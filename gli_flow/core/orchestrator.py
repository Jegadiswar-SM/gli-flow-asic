import json
import logging
import os
import sys
import time
import traceback

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

from gli_flow.provenance.manifest import generate_reproducibility_manifest
from gli_flow.regression.detector import detect_regression


logger = logging.getLogger(__name__)


STAGES = [
    "INITIALIZING",
    "SYNTHESIS",
    "FLOORPLANNING",
    "PLACEMENT",
    "CTS",
    "ROUTING",
    "TIMING_ANALYSIS",
    "QOR_EXTRACTION",
    "PACKAGING",
]


class FlowOrchestrator:

    def __init__(self, design_path, threads: int = None, memory_mb: int = None, orfs_root: str = None):
        discover_pdks()

        self.design_path = Path(design_path)
        self.design_name = self.design_path.name

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

        if self.backend_type == "openroad":
            self.adapter = OpenRoadAdapter(pdk_root=self.pdk_root, pdk=self.pdk, orfs_root=self.orfs_root)
            toolchain_name = f"OpenROAD/{pdk_name}"
        else:
            self.adapter = LibreLaneAdapter(pdk_root=self.pdk_root)
            toolchain_name = "LibreLane"

        self.database = DatabaseManager()

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
            return yaml.safe_load(f)

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

        print(f"Run ID: {self.run_id}")
        print(f"Design: {self.design_name}")
        print(f"PDK: {self.pdk.name if self.pdk else 'unknown'}")
        print(f"Corners: {[c.name for c in self.corners]}")
        if self.threads:
            print(f"Threads: {self.threads}")
        if self.memory_mb:
            print(f"Memory: {self.memory_mb}MB")
        print(f"Run Dir: {self.run_dir}")
        print()

        env_issues = self.adapter.validate_environment()
        if env_issues:
            for issue in env_issues:
                print(f"  [WARN] {issue}")
            print()

        config_path = None
        corner_results = []

        for index, stage in enumerate(STAGES):
            progress = int(((index + 1) / len(STAGES)) * 100)
            self._update_stage(stage, progress)
            print(f"  [{stage:<18}] {progress}%")

            if stage == "SYNTHESIS":
                config_result = self.adapter.generate_config(
                    self.manifest, str(self.run_dir)
                )
                if not config_result.get("success"):
                    self._handle_failure(f"Config generation failed: {config_result.get('error')}")
                    self._write_telemetry(self._compute_qor())
                    return self.record
                print(f"  Config: {config_result['config_path']}")

            elif stage == "TIMING_ANALYSIS":
                if len(self.corners) > 1:
                    print(f"  Running {len(self.corners)} PVT corners...")
                    for corner in self.corners:
                        print(f"    Corner: {corner.name} ({corner.process}, {corner.voltage}V, {corner.temperature}C)")
                        cr = self.adapter.run_corner(
                            str(self.run_dir / "config.json"),
                            str(self.design_path),
                            str(self.run_dir),
                            corner,
                        )
                        corner_results.append({
                            "corner": corner.to_dict(),
                            "success": cr.get("success"),
                            "wns": cr.get("wns"),
                            "tns": cr.get("tns"),
                            "duration": cr.get("duration"),
                        })

            elif stage == "PACKAGING":
                self._backend_result = self.adapter.run(
                    config_path=str(self.run_dir / "config.json"),
                    design_dir=str(self.design_path),
                    run_dir=str(self.run_dir),
                )

                backend_ok = self._backend_result.get("success", False)

                if not backend_ok:
                    err_msg = self._backend_result.get("error", "Backend execution failed")
                    print(f"  [ERROR] {err_msg}")
                else:
                    print(f"  Duration: {self._backend_result.get('duration', 0)}s")

                if self._backend_result.get("duration"):
                    self.record.runtime_sec = self._backend_result["duration"]

                self._extract_metrics()
                qor_result = self._compute_qor()
                self._write_telemetry(qor_result, corner_results)
                self._write_manifest(qor_result)
                self._collect_artifacts()

                if not backend_ok:
                    self._handle_failure(
                        f"Backend returned code {self._backend_result.get('returncode')}: "
                        f"{self._backend_result.get('stderr', '')[:200]}"
                    )
                    return self.record

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

        if corner_results:
            print()
            print("  Corner Results:")
            for cr in corner_results:
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

        return self.record
