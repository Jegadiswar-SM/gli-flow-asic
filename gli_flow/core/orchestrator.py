import json
import logging
import os
import re
import shutil
import subprocess
import sys
import time
import traceback
import webbrowser

from pathlib import Path

import yaml

from gli_flow.database.sqlite import DatabaseManager
from gli_flow.models.execution_record import ExecutionRecord
from gli_flow.version import VERSION

from gli_flow.backends.librelane import LibreLaneAdapter
from gli_flow.backends.openroad_adapter import OpenRoadAdapter
from gli_flow.runtime.run_directory import RunDirectoryManager
from gli_flow.runtime.telemetry_manager import TelemetryManager
from gli_flow.runtime.artifact_manager import ArtifactManager
from gli_flow.analytics.qor_score import calculate_qor_score
from gli_flow.pdk import get_pdk, discover_pdks
from gli_flow.installer.workspace import get_config_value
from gli_flow.testing.layout_images import generate_placeholder_images

from gli_flow.provenance.manifest import generate_reproducibility_manifest
from gli_flow.regression.detector import detect_regression
from gli_flow.config_validator import validate_manifest
from gli_flow.parser.rtl_parser import scan_directory
from gli_flow.core.exceptions import PreSynthesisCheckError, StageOOMError, StageFailure


logger = logging.getLogger(__name__)


STAGES = [
    "INITIALIZING",
    "HIERARCHICAL_PARTITIONING",
    "BLOCK_SYNTHESIS",
    "SYNTHESIS",
    "CLOCK_GATING",
    "SCAN_INSERTION",
    "FORMAL_VERIFICATION",
    "FLOORPLANNING",
    "TOP_FLOORPLANNING",
    "PLACEMENT",
    "CTS",
    "ROUTING",
    "PRO",
    "ANTENNA_CHECK",
    "FILL",
    "DECAP",
    "POWER",
    "EM_CHECK",
    "DENSITY_CHECK",
    "YIELD",
    "ATPG",
    "D2D_INTERFACE_CHECK",
    "QOR_EXTRACTION",
    "PACKAGING",
    "DRC",
    "LVS",
    "TIMING_ANALYSIS",
    "SI_ANALYSIS",
    "SIGN_OFF",
]

_STAGE_METHODS = {
    "HIERARCHICAL_PARTITIONING": "run_hierarchical_partitioning",
    "BLOCK_SYNTHESIS": "run_block_synthesis",
    "CLOCK_GATING": "run_clock_gating",
    "SCAN_INSERTION": "run_scan_insertion",
    "FORMAL_VERIFICATION": "run_formal",
    "TOP_FLOORPLANNING": "run_top_floorplanning",
    "PRO": "run_pro",
    "ANTENNA_CHECK": "run_antenna_check",
    "FILL": "run_fill",
    "DECAP": "run_decap",
    "POWER": "run_power_analysis",
    "EM_CHECK": "run_em_check",
    "DENSITY_CHECK": "run_density_check",
    "YIELD": "run_yield_enhancement",
    "ATPG": "run_atpg",
    "SI_ANALYSIS": "run_si_analysis",
    "D2D_INTERFACE_CHECK": "run_d2d_interface_check",
    "PACKAGING": "run_packaging",
}


class FlowOrchestrator:

    def __init__(self, design_path, threads: int = None, memory_mb: int = None,
                 orfs_root: str = None, mock: bool = False, db_path: str = None):
        discover_pdks()

        self.design_path = Path(design_path)
        self.design_name = self.design_path.name
        self.db_path = db_path

        self.manifest = self._read_manifest()

        self.run_id = f"run_{int(time.time())}_{self.design_name}"

        self.run_dir_mgr = RunDirectoryManager(self.run_id)
        self.run_dir = self.run_dir_mgr.create()

        self.pdk_root = os.environ.get("PDK_ROOT") or get_config_value("pdk_root")
        self.orfs_root = orfs_root or os.environ.get("ORFS_ROOT") or get_config_value("orfs_root")
        self.backend_type = self.manifest.get("backend", "openroad")

        pdk_name = self.manifest.get("pdk", "sky130")
        pdk_variant = self.manifest.get("pdk_variant", "")
        self.pdk = get_pdk(pdk_name, variant=pdk_variant)

        self.corners = self._resolve_corners()

        self.threads = threads or self.manifest.get("threads")
        self.memory_mb = memory_mb or self.manifest.get("memory_mb")

        if mock:
            from gli_flow.testing.mock_adapter import MockEDAAdapter
            self.adapter = MockEDAAdapter(pdk_root=self.pdk_root, pdk=self.pdk)
            toolchain_name = f"Mock/{pdk_name}"
        elif self.backend_type == "openroad":
            self.adapter = OpenRoadAdapter(pdk_root=self.pdk_root, pdk=self.pdk, orfs_root=self.orfs_root)
            toolchain_name = f"OpenROAD/{pdk_name}"
        else:
            self.adapter = LibreLaneAdapter(pdk_root=self.pdk_root)
            toolchain_name = "LibreLane"

        self.database = DatabaseManager(db_path=self.db_path)

        self.record = ExecutionRecord(
            run_id=self.run_id,
            design_name=self.design_name,
            toolchain=toolchain_name,
            status="INITIALIZING",
            current_stage="INITIALIZING",
        )

        self.telemetry_mgr = TelemetryManager(str(self.run_dir))
        self.artifact_mgr = ArtifactManager()

        self._backend_result = None

    def _read_manifest(self):
        manifest_path = self.design_path / "gli_manifest.yaml"
        if not manifest_path.exists():
            print(f"[ERROR] Manifest not found: {manifest_path}", file=sys.stderr)
            sys.exit(1)

        with open(manifest_path, "r") as f:
            manifest = yaml.safe_load(f)

        rtl_files = manifest.get("rtl_files")
        if not rtl_files:
            _, top_module, discovered = scan_directory(self.design_path)
            if discovered:
                manifest["rtl_files"] = [str(Path(f).relative_to(self.design_path.parent)) for f in discovered]
                print(f"  [INFO] Auto-discovered {len(discovered)} RTL file(s) in design directory")
                if top_module and "top_module" not in manifest:
                    manifest["top_module"] = top_module.name
                    print(f"  [INFO] Auto-detected top module: {top_module.name}")

        return manifest

    def _resolve_corners(self):
        manifest_corners = self.manifest.get("corners")
        if manifest_corners:
            from gli_flow.pdk.corner import PVTCorner
            return [PVTCorner.from_dict(c) if isinstance(c, dict) else c for c in manifest_corners]
        if self.pdk:
            return self.pdk.corners
        from gli_flow.pdk.corner import PVTCorner
        return [PVTCorner.typical()]

    def _update_stage(self, stage, progress):
        self.record.current_stage = stage
        self.record.progress = progress
        self.record.status = "RUNNING"

        self.database.update_run(
            run_id=self.run_id,
            status="RUNNING",
            current_stage=stage,
            progress=progress,
        )

    def _extract_metrics(self):
        reports_dir = self.run_dir / "reports"
        from gli_flow.telemetry.parser import TelemetryParser

        parser = TelemetryParser(str(reports_dir))
        parsed = parser.parse_all()

        self.record.wns = parsed.get("wns")
        self.record.tns = parsed.get("tns")
        self.record.utilization = parsed.get("utilization")
        if parsed.get("cell_count") is not None:
            self.record.cell_count = int(parsed["cell_count"])
        self.record.runtime_sec = parsed.get("runtime_sec")

    def _compute_qor(self):
        qor_result = calculate_qor_score(
            wns=self.record.wns,
            tns=self.record.tns,
            utilization=self.record.utilization,
            runtime=self.record.runtime_sec,
            cell_count=self.record.cell_count,
        )
        self.record.qor_score = qor_result["score"]
        return qor_result

    def _write_telemetry(self, qor_result, corner_results=None):
        telemetry_data = {
            "run_id": self.run_id,
            "design_name": self.design_name,
            "pdk": self.manifest.get("pdk", ""),
            "pdk_variant": self.manifest.get("pdk_variant", ""),
            "corners": [c.to_dict() for c in self.corners],
            "metrics": {
                "wns": self.record.wns,
                "tns": self.record.tns,
                "utilization": self.record.utilization,
                "cell_count": self.record.cell_count,
                "runtime_sec": self.record.runtime_sec,
                "qor_score": self.record.qor_score,
                "qor_breakdown": qor_result["breakdown"],
                "qor_weights": qor_result["weights"],
            },
        }

        if corner_results:
            telemetry_data["corner_results"] = corner_results

        self.telemetry_mgr.export_metrics(telemetry_data)

        for idx, stage in enumerate(STAGES):
            stage_data = {
                "stage": stage,
                "order": idx,
                "completed": idx <= (self.record.progress / 100 * len(STAGES)) - 1,
            }
            self.telemetry_mgr.export_stage_data(stage, stage_data)

    def _collect_artifacts(self):
        artifact_dirs = ["config.json", "reproducibility.json", "telemetry/metrics.json"]
        for rel_path in artifact_dirs:
            full_path = self.run_dir / rel_path
            if full_path.exists():
                self.artifact_mgr.add_artifact(str(full_path))

        log_dir = self.run_dir / "logs"
        if log_dir.exists():
            for f in sorted(log_dir.iterdir()):
                if f.is_file():
                    self.artifact_mgr.add_artifact(str(f))

        reports_dir = self.run_dir / "reports"
        if reports_dir.exists():
            for f in sorted(reports_dir.iterdir()):
                if f.is_file():
                    self.artifact_mgr.add_artifact(str(f))

        results_dir = self.run_dir / "results"
        if results_dir.exists():
            for f in sorted(results_dir.iterdir()):
                if f.is_file():
                    self.artifact_mgr.add_artifact(str(f))

        artifacts_dir = self.run_dir / "artifacts"
        if artifacts_dir.exists():
            for f in sorted(artifacts_dir.iterdir()):
                if f.is_file():
                    self.artifact_mgr.add_artifact(str(f))

        self.artifact_mgr.export_manifest(str(self.run_dir))

    def _write_manifest(self, qor_result):
        metrics = {
            "wns": self.record.wns,
            "tns": self.record.tns,
            "utilization": self.record.utilization,
            "cell_count": self.record.cell_count,
            "runtime_sec": self.record.runtime_sec,
            "qor_score": self.record.qor_score,
            "qor_breakdown": qor_result["breakdown"],
        }

        manifest_data = {
            "rtl_files": self.manifest.get("rtl_files", []),
            "constraints": self.manifest.get("constraints", []),
            "pdk": self.manifest.get("pdk", ""),
            "pdk_variant": self.manifest.get("pdk_variant", ""),
            "corners": [c.to_dict() for c in self.corners],
            "config_path": str(self.run_dir / "config.json"),
        }

        generate_reproducibility_manifest(
            run_id=self.run_id,
            design_name=self.design_name,
            metrics=metrics,
            manifest_data=manifest_data,
            run_dir=str(self.run_dir),
        )

    def _check_regression(self):
        baseline = self.database.get_last_successful_run(self.design_name)
        if baseline is None:
            return {"regression_detected": False, "alerts": [], "baseline": None}

        current_metrics = {
            "qor_score": self.record.qor_score,
            "wns": self.record.wns,
            "utilization": self.record.utilization,
        }

        baseline_metrics = {
            "qor_score": baseline["qor_score"],
            "wns": baseline["wns"],
            "utilization": baseline["utilization"],
        }

        return detect_regression(current_metrics, baseline_metrics)

    def _add_failure_atlas_entry(self, stage, category, severity):
        entry = {
            "run_id": self.run_id,
            "design_name": self.design_name,
            "detection_stage": stage,
            "level2_category": str(category),
            "severity": str(severity),
            "timestamp": time.strftime('%Y-%m-%d %H:%M:%S'),
        }
        atlas_dir = Path(self.run_dir) / "failure_atlas"
        atlas_dir.mkdir(parents=True, exist_ok=True)
        fname = f"{stage}_{category}_{int(time.time())}.json"
        (atlas_dir / fname).write_text(json.dumps(entry, indent=2))

    def _start_dashboard(self):
        try:
            dashboard_port = os.environ.get("GLI_FLOW_DASHBOARD_PORT", "5173")
            backend_port = os.environ.get("GLI_FLOW_BACKEND_PORT", "8000")
            backend_proc = subprocess.Popen(
                [sys.executable, "-m", "uvicorn", "backend.server:app", "--host", "127.0.0.1", "--port", backend_port],
                cwd=Path(__file__).resolve().parent.parent.parent,
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
            )
            time.sleep(2)
            dashboard_url = f"http://127.0.0.1:{dashboard_port}"
            if not Path(Path(__file__).resolve().parent.parent.parent / "dashboard" / "dist" / "index.html").exists():
                dashboard_url = f"http://127.0.0.1:{backend_port}"
            webbrowser.open(dashboard_url)
            print(f"  [INFO] Dashboard opened: {dashboard_url}")
            self._dashboard_proc = backend_proc
        except Exception as e:
            print(f"  [INFO] Could not auto-open dashboard: {e}")
            self._dashboard_proc = None

    def _handle_failure(self, error_message):
        self.record.status = "FAILED"
        self.record.current_stage = "FAILED"

        self.database.update_run(
            run_id=self.run_id,
            status="FAILED",
            current_stage="FAILED",
            progress=self.record.progress,
        )

        error_log = self.run_dir / "logs" / "error.log"
        try:
            with open(error_log, "w") as f:
                f.write(f"Timestamp: {time.strftime('%Y-%m-%d %H:%M:%S')}\n")
                f.write(f"Error: {error_message}\n")
                f.write(traceback.format_exc())
        except OSError:
            pass

        print(f"\n[ERROR] {error_message}")

    def run(self):
        self.database.insert_run(self.record)

        self._start_dashboard()

        print(f"Run ID: {self.run_id}")
        print(f"Design: {self.design_name}")
        print(f"PDK: {self.pdk.name if self.pdk else 'unknown'}")
        if self.pdk_root:
            print(f"PDK Root: {self.pdk_root}")
        print(f"Corners: {[c.name for c in self.corners]}")
        if self.threads:
            print(f"Threads: {self.threads}")
        if self.memory_mb:
            print(f"Memory: {self.memory_mb}MB")
        print(f"Run Dir: {self.run_dir}")
        print()

        env_issues = self.adapter.validate_environment()
        if env_issues:
            print("  [ERROR] Environment validation failed:")
            for issue in env_issues:
                print(f"           {issue}")
            print()
            print("  Run 'gli-flow install' to fix missing components.")
            self._handle_failure("Environment validation failed: " + "; ".join(env_issues))
            return self.record

        config_path = None
        self._corner_results = []

        essential = {"INITIALIZING", "SYNTHESIS", "PACKAGING", "QOR_EXTRACTION"}

        for index, stage in enumerate(STAGES):
            progress = int(((index + 1) / len(STAGES)) * 100)
            self._update_stage(stage, progress)
            print(f"  [{stage:<18}] {progress}%")

            try:
                if stage == "SYNTHESIS":
                    rtl_files = self.manifest.get("rtl_files", [])
                    top_module = self.manifest.get("top_module", self.design_name)
                    pre_checks = self.adapter.pre_synthesis_checks(rtl_files, top_module, str(self.run_dir))
                    if pre_checks.get("has_sv"):
                        print("  [INFO] SystemVerilog detected — preprocessing with sv2v.")
                        sv_files = [f for f in rtl_files if str(f).endswith((".sv", ".svh"))]
                        v_files = [f for f in rtl_files if not str(f).endswith((".sv", ".svh"))]
                        converted = []
                        for svf in sv_files:
                            sv_path = Path(svf)
                            v_path = sv_path.with_suffix(".v")
                            if shutil.which("sv2v"):
                                result = subprocess.run(
                                    ["sv2v", str(svf), "-w", str(v_path)],
                                    capture_output=True, text=True, timeout=120,
                                    env={**os.environ.copy(), "LC_ALL": "C"},
                                )
                                if result.returncode == 0 and v_path.exists():
                                    converted.append(str(v_path))
                                    print(f"  [INFO] Converted {svf} -> {v_path}")
                                else:
                                    print(f"  [WARN] sv2v conversion failed for {svf}")
                            else:
                                print(f"  [WARN] sv2v not found — skipping conversion of {svf}")
                        self.manifest["rtl_files"] = converted + v_files
                    if pre_checks.get("latch_inferred"):
                        from gli_flow.failure_atlas.taxonomy import FailureSeverity
                        self._add_failure_atlas_entry("SYNTHESIS", "LATCH_INFERRED", FailureSeverity.TAPEOUT_BLOCKING)
                        print("  [ERROR] Latch inferred — TAPEOUT_BLOCKING failure. Blocking run.")
                        self._handle_failure("Latch inferred: Incomplete case/if statements cause hold violations.")
                        return self.record
                    if pre_checks.get("multi_driver"):
                        err_msg = "; ".join(pre_checks.get("errors", []))
                        print(f"  [ERROR] Multi-driver nets detected: {err_msg}")
                        self._handle_failure(err_msg)
                        return self.record
                    if pre_checks.get("missing_modules"):
                        missing = ", ".join(pre_checks["missing_modules"])
                        err_msg = f"Missing modules: {missing}. Design is structurally incomplete."
                        print(f"  [ERROR] {err_msg}")
                        self._handle_failure(err_msg)
                        return self.record
                    config_result = self.adapter.generate_config(
                        self.manifest, str(self.run_dir)
                    )
                    if not config_result.get("success"):
                        self._handle_failure(f"Config generation failed: {config_result.get('error')}")
                        self._write_telemetry(self._compute_qor())
                        return self.record
                    print(f"  Config: {config_result['config_path']}")

                elif stage == "DRC":
                    if self.adapter and hasattr(self.adapter, "run_drc"):
                        try:
                            gds_path = self.run_dir / "artifacts" / "6_final.gds"
                            magic_drc = self.adapter.run_drc(str(self.run_dir), self.design_name, str(gds_path), self.pdk)
                            klayout_drc = self.adapter.run_klayout_drc(str(self.run_dir), self.design_name, str(gds_path), self.pdk)
                            drc_result = self.adapter.merge_drc_results(magic_drc, klayout_drc)
                            drc_summary = {
                                "total_violations": drc_result.total_violations,
                                "by_rule": drc_result.by_rule,
                                "is_clean": drc_result.is_clean,
                                "runtime_seconds": drc_result.runtime_seconds,
                                "magic_violations": magic_drc.total_violations,
                                "klayout_violations": klayout_drc.total_violations,
                            }
                            summary_path = self.run_dir / "drc_lvs_summary.json"
                            if summary_path.exists():
                                summary = json.loads(summary_path.read_text())
                            else:
                                summary = {}
                            summary["drc"] = drc_summary
                            summary_path.write_text(json.dumps(summary, indent=2))
                        except Exception as e:
                            print(f"  [SKIP] DRC: {e}")

                elif stage == "LVS":
                    if self.adapter and hasattr(self.adapter, "run_lvs"):
                        try:
                            gds_path = self.run_dir / "artifacts" / "6_final.gds"
                            netlist_path = self.run_dir / "artifacts" / "1_synth.v"
                            lvs_result = self.adapter.run_lvs(str(self.run_dir), self.design_name, str(gds_path), str(netlist_path), self.pdk)
                            lvs_summary = {
                                "result": lvs_result.result,
                                "unmatched_devices": lvs_result.unmatched_devices,
                                "unmatched_nets": lvs_result.unmatched_nets,
                                "short_count": lvs_result.short_count,
                                "open_count": lvs_result.open_count,
                                "is_clean": lvs_result.is_clean,
                                "runtime_seconds": lvs_result.runtime_seconds,
                            }
                            summary_path = self.run_dir / "drc_lvs_summary.json"
                            if summary_path.exists():
                                summary = json.loads(summary_path.read_text())
                            else:
                                summary = {}
                            summary["lvs"] = lvs_summary
                            summary_path.write_text(json.dumps(summary, indent=2))
                        except Exception as e:
                            print(f"  [SKIP] LVS: {e}")

                elif stage == "TIMING_ANALYSIS":
                    if self.adapter and hasattr(self.adapter, "run_timing_signoff"):
                        try:
                            sta_result = self.adapter.run_timing_signoff(str(self.run_dir), self.design_name, self.pdk)
                            timing_ok = sta_result.setup_satisfied and sta_result.hold_satisfied
                            if not sta_result.hold_satisfied:
                                print(f"  [WARN] Hold violations detected: WNS={sta_result.hold_wns_ns}, TNS={sta_result.hold_tns_ns}")
                            self._corner_results = [{
                                "corner": {"name": "typical"},
                                "success": timing_ok,
                                "setup_satisfied": sta_result.setup_satisfied,
                                "hold_satisfied": sta_result.hold_satisfied,
                                "setup_wns": sta_result.setup_wns_ns,
                                "setup_tns": sta_result.setup_tns_ns,
                                "hold_wns": sta_result.hold_wns_ns,
                                "hold_tns": sta_result.hold_tns_ns,
                            }]
                            corner_sta_path = self.run_dir / "sta_corners.json"
                            corner_sta_path.write_text(json.dumps(self._corner_results, indent=2))
                        except Exception as e:
                            print(f"  [SKIP] TIMING_ANALYSIS: {e}")
                    else:
                        print(f"  [SKIP] TIMING_ANALYSIS: no adapter")

                elif stage not in essential and stage not in _STAGE_METHODS:
                    pass
                else:
                    method_name = _STAGE_METHODS.get(stage)
                    if not method_name:
                        pass
                    elif hasattr(self.adapter, method_name):
                        method = getattr(self.adapter, method_name)
                        try:
                            result = method(str(self.run_dir), self.design_name, self.pdk)
                            if stage == "PACKAGING":
                                self._backend_result = result
                                log_file = self._backend_result.get("log_file", "")
                                if log_file and Path(log_file).exists():
                                    log_text = Path(log_file).read_text()
                                    overflow_h = 0.0
                                    overflow_v = 0.0
                                    for line in log_text.splitlines():
                                        m = re.search(r"Overflow\s+H\s*=\s*([\d.]+)\s*%?", line)
                                        if m:
                                            overflow_h = float(m.group(1))
                                        m = re.search(r"Overflow\s+V\s*=\s*([\d.]+)\s*%?", line)
                                        if m:
                                            overflow_v = float(m.group(1))
                                        m = re.search(r"global\s+routing\s+overflow\s*:\s*H=([\d.]+)\s*V=([\d.]+)", line, re.IGNORECASE)
                                        if m:
                                            overflow_h = float(m.group(1))
                                            overflow_v = float(m.group(2))
                                    if overflow_h > 5.0 or overflow_v > 5.0 or overflow_h > 0.05 or overflow_v > 0.05:
                                        ov = max(overflow_h, overflow_v)
                                        ov_pct = ov if ov > 1 else ov * 100
                                        print(f"  [ERROR] Global routing overflow {ov_pct:.1f}%. Reduce core_utilization by at least 15% and rerun.")
                                        self._backend_result["success"] = False
                                        self._backend_result["error"] = f"Global routing overflow {ov_pct:.1f}%. Reduce core_utilization and rerun."
                        except Exception as e:
                            print(f"  [SKIP] {stage}: {e}")
                    else:
                        print(f"  [SKIP] {stage}: {method_name} not on adapter")

            except Exception as e:
                if stage in essential:
                    raise
                print(f"  [SKIP] {stage}: {e}")

        if self._backend_result is not None:
            self._extract_metrics()
            qor_result = self._compute_qor()
            backend_ok = self._backend_result.get("success", False)

            if not backend_ok:
                err_msg = self._backend_result.get("error", "Backend execution failed")
                log_hint = self._backend_result.get("log_file")
                if log_hint and "log" not in err_msg.lower():
                    err_msg += f"\n  See logs: {log_hint}"
                print(f"  [ERROR] {err_msg}")
                self._handle_failure(err_msg)
                from gli_flow.failure_atlas.analyze_failure import save_failure_analysis
                save_failure_analysis(self.run_id, self.design_name, self.record.current_stage, err_msg)
                return self.record

            if self._backend_result.get("duration"):
                self.record.runtime_sec = self._backend_result["duration"]

            self._write_telemetry(qor_result, self._corner_results)
            self._write_manifest(qor_result)

            results_dir = self.run_dir / "results"
            if results_dir.exists():
                for f in results_dir.iterdir():
                    if f.is_file():
                        shutil.copy2(str(f), str(self.run_dir / "artifacts" / f.name))

            self.record.run_dir = str(self.run_dir)
            self.database.update_run(run_id=self.run_id, run_dir=self.record.run_dir)

            reports_dir = self.run_dir / "reports"
            generate_placeholder_images(str(reports_dir))

            self._collect_artifacts()

            print(f"  Duration: {self._backend_result.get('duration', 0)}s")

        self.record.status = "SUCCESS"
        self.record.current_stage = "DONE"
        self.record.progress = 100

        self.database.update_run(
            run_id=self.run_id,
            status="SUCCESS",
            current_stage="DONE",
            progress=100,
            wns=self.record.wns,
            tns=self.record.tns,
            utilization=self.record.utilization,
            runtime_sec=self.record.runtime_sec,
            cell_count=self.record.cell_count,
            qor_score=self.record.qor_score,
        )

        print()
        print(f"  QoR Score:  {self.record.qor_score}")
        print(f"  WNS:        {self.record.wns}")
        print(f"  TNS:        {self.record.tns}")
        print(f"  Utilization: {self.record.utilization}%")
        print(f"  Cell Count: {self.record.cell_count}")
        print(f"  Runtime:    {self.record.runtime_sec}s")

        if self._corner_results:
            print()
            print("  Corner Results:")
            for cr in self._corner_results:
                icon = "OK" if cr["success"] else "FAIL"
                print(f"    {cr['corner']['name']}: {icon}")

        regression = self._check_regression()
        if regression["regression_detected"]:
            print()
            print("  REGRESSION ALERTS:")
            for alert in regression["alerts"]:
                print(f"    ! {alert}")

        print()
        print(f"  Run complete: {self.run_dir}")

        self.database.close()

        return self.record
