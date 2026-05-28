import json
import os
import re
import shutil
import subprocess
import time

from pathlib import Path

from gli_flow.pdk import get_pdk, PDK
from gli_flow.pdk.corner import PVTCorner
from gli_flow.installer.workspace import get_config_value


def resolve_orfs_root(orfs_root: str = None) -> str:
    if orfs_root:
        return orfs_root
    env = os.environ.get("ORFS_ROOT")
    if env:
        return env
    config = get_config_value("orfs_root")
    if config:
        return config
    from gli_flow.installer.orfs import default_orfs_root
    return default_orfs_root()


class OpenRoadAdapter:

    def __init__(self, pdk_root=None, pdk: PDK = None, orfs_root: str = None):
        self.pdk_root = pdk_root or os.environ.get("PDK_ROOT")
        self._orfs_root = resolve_orfs_root(orfs_root)
        self._flow_dir = f"{self._orfs_root}/flow"
        self.pdk = pdk

    def set_pdk(self, pdk: PDK) -> None:
        self.pdk = pdk

    @property
    def platform(self) -> str:
        return self.pdk.orfs_platform if self.pdk else "sky130hd"

    def validate_environment(self):
        issues = []
        if not Path(self._orfs_root).is_dir():
            issues.append(f"ORFS root not found: {self._orfs_root}")
        if not Path(self._flow_dir).is_dir():
            issues.append(f"ORFS flow dir not found: {self._flow_dir}")
        if not self.pdk_root:
            issues.append("PDK_ROOT not set")
        elif not Path(self.pdk_root).is_dir():
            issues.append(f"PDK_ROOT directory not found: {self.pdk_root}")
        openroad = shutil.which("openroad")
        if not openroad:
            install_path = Path(f"{self._orfs_root}/tools/install/OpenROAD/bin/openroad")
            build_path = Path(f"{self._orfs_root}/tools/OpenROAD/build/bin/openroad")
            if not install_path.exists() and not build_path.exists():
                issues.append("OpenROAD binary not found")
        return issues

    def generate_config(self, manifest, run_dir, corner: PVTCorner = None):
        design_name = manifest.get("design_name", "unnamed")
        pdk_name = manifest.get("pdk", "sky130")
        pdk_variant = manifest.get("pdk_variant", "")
        pdk = self.pdk or get_pdk(pdk_name, variant=pdk_variant)
        if pdk is None:
            return {"success": False, "error": f"Unknown PDK: {pdk_name}"}

        self.pdk = pdk
        platform = pdk.orfs_platform

        design_dir = Path(f"{self._flow_dir}/designs/{platform}/{design_name}")
        src_dir = Path(f"{self._flow_dir}/designs/src/{design_name}")
        design_dir.mkdir(parents=True, exist_ok=True)
        src_dir.mkdir(parents=True, exist_ok=True)

        rtl_files = manifest.get("rtl_files", [])
        for rtl in rtl_files:
            src_path = Path(os.path.join(os.getcwd(), rtl))
            if src_path.exists():
                dst_name = src_path.stem + ".sv"
                shutil.copy2(str(src_path), str(src_dir / dst_name))

        config_mk = pdk.generate_config_mk(design_name, corner)
        # Replace hard-coded VERILOG_FILES with actual RTL file list
        verilog_files = " ".join(
            f"$(CURDIR)/designs/src/{design_name}/{Path(f).stem}.sv"
            for f in rtl_files
        )
        config_mk = re.sub(
            r'^export VERILOG_FILES = .*',
            f'export VERILOG_FILES = {verilog_files}',
            config_mk,
            flags=re.MULTILINE,
        )
        config_path = design_dir / "config.mk"
        try:
            with open(config_path, "w") as f:
                f.write(config_mk)
        except OSError as e:
            return {"success": False, "error": f"Failed to write config.mk: {e}"}

        sdc_files = manifest.get("constraints", [])
        if sdc_files:
            sdc_src = Path(os.path.join(os.getcwd(), sdc_files[0]))
            if sdc_src.exists():
                shutil.copy2(str(sdc_src), str(design_dir / "constraint.sdc"))
        else:
            clock_period = manifest.get("clock_period_ns", 10.0)
            clock_port = manifest.get("clock_port", "clk")
            sdc_content = f"""create_clock -name clk -period {clock_period} [get_ports {clock_port}]
set_input_delay -clock clk 2.0 [all_inputs]
set_output_delay -clock clk 2.0 [all_outputs]
"""
            with open(design_dir / "constraint.sdc", "w") as f:
                f.write(sdc_content)

        design_info = {
            "design_name": design_name,
            "pdk": pdk_name,
            "pdk_variant": pdk_variant,
            "platform": platform,
            "config_mk": str(config_path),
            "design_dir": str(design_dir),
            "src_dir": str(src_dir),
            "orfs_results_dir": f"{self._flow_dir}/results/{platform}/{design_name}/base",
            "orfs_reports_dir": f"{self._flow_dir}/reports/{platform}/{design_name}/base",
        }

        run_config_path = Path(run_dir) / "config.json"
        try:
            with open(run_config_path, "w") as f:
                json.dump({**manifest, "orfs": design_info}, f, indent=2)
        except OSError as e:
            return {"success": False, "error": f"Failed to write config: {e}"}

        return {"success": True, "config_path": str(run_config_path), "orfs_info": design_info}

    def run(self, config_path, design_dir, run_dir, timeout=3600):
        reports_dir = Path(run_dir) / "reports"
        reports_dir.mkdir(parents=True, exist_ok=True)
        logs_dir = Path(run_dir) / "logs"
        logs_dir.mkdir(parents=True, exist_ok=True)
        artifacts_dir = Path(run_dir) / "artifacts"
        artifacts_dir.mkdir(parents=True, exist_ok=True)

        log_file = logs_dir / "openroad.log"

        try:
            with open(config_path) as f:
                config = json.load(f)
        except (FileNotFoundError, json.JSONDecodeError) as e:
            return {
                "success": False,
                "returncode": -1,
                "stdout": "",
                "stderr": f"Failed to read config: {e}",
                "duration": 0,
                "log_file": str(log_file),
                "reports_dir": str(reports_dir),
                "output_dir": str(run_dir),
                "error": f"Config load failed: {e}",
            }

        orfs_info = config.get("orfs", {})
        design_name = orfs_info.get("design_name", "unknown")
        platform = orfs_info.get("platform", self.platform)
        orfs_results_dir = orfs_info.get("orfs_results_dir")
        orfs_reports_dir = orfs_info.get("orfs_reports_dir")

        config_mk = orfs_info.get("config_mk")
        if not config_mk or not Path(config_mk).exists():
            return {
                "success": False,
                "returncode": -1,
                "stdout": "",
                "stderr": "ORFS config.mk not found",
                "duration": 0,
                "log_file": str(log_file),
                "reports_dir": str(reports_dir),
                "output_dir": str(run_dir),
                "error": "ORFS config.mk not found — run generate_config first",
            }

        clean_cmd = ["make", f"DESIGN_CONFIG=./designs/{platform}/{design_name}/config.mk", "clean_all"]
        subprocess.run(clean_cmd, cwd=self._flow_dir, capture_output=True, text=True, timeout=120)

        env = os.environ.copy()
        env["PDK_ROOT"] = self.pdk_root or ""

        command = ["make", f"DESIGN_CONFIG=./designs/{platform}/{design_name}/config.mk"]

        if config.get("threads"):
            env["NUM_CORES"] = str(config["threads"])

        start_time = time.time()

        try:
            result = subprocess.run(
                command,
                cwd=self._flow_dir,
                capture_output=True,
                text=True,
                timeout=timeout,
                env=env,
            )

            with open(log_file, "w") as f:
                f.write(result.stdout)
                if result.stderr:
                    f.write("\n--- STDERR ---\n")
                    f.write(result.stderr)

            duration = round(time.time() - start_time, 2)

            success = result.returncode == 0

            if orfs_reports_dir and Path(orfs_reports_dir).exists():
                for f in Path(orfs_reports_dir).iterdir():
                    if f.is_file():
                        shutil.copy2(str(f), str(reports_dir / f.name))

            self._write_metrics_csv(str(reports_dir), str(log_file))

            if orfs_results_dir and Path(orfs_results_dir).exists():
                artifacts = [
                    ("6_final.gds", "6_final.gds"),
                    ("6_final.def", "6_final.def"),
                    ("1_synth.v", "1_synth.v"),
                ]
                for src_name, dst_name in artifacts:
                    src_file = Path(orfs_results_dir) / src_name
                    if src_file.exists():
                        shutil.copy2(str(src_file), str(artifacts_dir / dst_name))

            return {
                "success": success,
                "returncode": result.returncode,
                "stdout": result.stdout,
                "stderr": result.stderr,
                "duration": duration,
                "log_file": str(log_file),
                "reports_dir": str(reports_dir),
                "output_dir": str(run_dir),
            }

        except FileNotFoundError:
            duration = round(time.time() - start_time, 2)
            return {
                "success": False,
                "returncode": -1,
                "stdout": "",
                "stderr": "make not found in PATH",
                "duration": duration,
                "log_file": str(log_file),
                "reports_dir": str(reports_dir),
                "output_dir": str(run_dir),
                "error": "make not found in PATH",
            }

        except subprocess.TimeoutExpired:
            duration = round(time.time() - start_time, 2)
            return {
                "success": False,
                "returncode": -1,
                "stdout": "",
                "stderr": f"ORFS execution timed out after {timeout}s",
                "duration": duration,
                "log_file": str(log_file),
                "reports_dir": str(reports_dir),
                "output_dir": str(run_dir),
                "error": f"Timed out after {timeout}s",
            }

    def run_corner(self, config_path, design_dir, run_dir, corner: PVTCorner, timeout=3600):
        corner_dir = Path(run_dir) / f"corner_{corner.name}"
        corner_dir.mkdir(parents=True, exist_ok=True)

        with open(config_path) as f:
            config = json.load(f)

        config["corner"] = corner.to_dict()
        corner_config = Path(str(config_path).replace(".json", f"_{corner.name}.json"))
        with open(corner_config, "w") as f:
            json.dump(config, f, indent=2)

        return self.run(str(corner_config), design_dir, str(corner_dir), timeout)

    def _write_metrics_csv(self, reports_dir, log_file):
        metrics = {}

        finish_rpt = Path(reports_dir) / "6_finish.rpt"
        if finish_rpt.exists():
            try:
                text = finish_rpt.read_text()

                m = re.search(r"wns\s+(max|min)\s+([-\d.]+)", text)
                if m:
                    metrics["wns"] = float(m.group(2))

                m = re.search(r"tns\s+(max|min)\s+([-\d.]+)", text)
                if m:
                    metrics["tns"] = float(m.group(2))

                m = re.search(r"clk period_min\s*=\s*([\d.]+)", text)
                if m:
                    metrics["fmax_mhz"] = round(1000.0 / float(m.group(1)), 2)

                m = re.search(r"Total\s+(?:Power|power)\s+([\d.e+-]+)", text)
                if m:
                    metrics["total_power_w"] = float(m.group(1))

                m = re.search(r"setup violation count\s+(\d+)", text)
                if m:
                    metrics["setup_violations"] = int(m.group(1))

                m = re.search(r"hold violation count\s+(\d+)", text)
                if m:
                    metrics["hold_violations"] = int(m.group(1))

            except (OSError, ValueError):
                pass

        if log_file and Path(log_file).exists():
            try:
                log_text = Path(log_file).read_text()

                for line in log_text.split("\n"):
                    m = re.match(r"Design area\s+([\d.]+)\s+um\^2\s+([\d.]+)%\s+utilization", line)
                    if m:
                        metrics["die_area_um2"] = float(m.group(1))
                        metrics["utilization"] = float(m.group(2))

                    m = re.match(r"Total cells:\s+(\d+)", line)
                    if m:
                        metrics["cell_count"] = int(m.group(1))

                    m = re.match(r"Total\s+(\d+)\s+(\d+)\s*$", line)
                    if m:
                        metrics["runtime_sec"] = float(m.group(1))

            except (OSError, ValueError):
                pass

        if metrics:
            csv_path = Path(reports_dir) / "metrics.csv"
            try:
                with open(csv_path, "w") as f:
                    for key, value in metrics.items():
                        f.write(f"{key},{value}\n")
            except OSError:
                pass
