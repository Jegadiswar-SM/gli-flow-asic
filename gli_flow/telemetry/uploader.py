import json
import logging
import os
import subprocess
import sys
from pathlib import Path
from typing import Optional

from gli_flow.telemetry.settings import get_telemetry_settings, TelemetryMode
from failure_atlas.community_intelligence.export import TelemetryExporter
from failure_atlas.community_intelligence.audit import TelemetryAuditLog

logger = logging.getLogger(__name__)

class TelemetryUploader:
    def __init__(self, db_path: Optional[str] = None):
        self.db_path = db_path
        self.settings = get_telemetry_settings()
        self.exporter = TelemetryExporter(db_path)
        self.audit = TelemetryAuditLog(db_path)

    def should_upload(self) -> bool:
        if self.settings.mode == TelemetryMode.LOCAL or self.settings.mode == TelemetryMode.DISABLED:
            return False
        if not self.settings.consent_given:
            return False
        return True

    def upload_run_telemetry(self, run_id: str):
        if not self.should_upload():
            logger.info(f"Skipping telemetry upload for run {run_id} (mode={self.settings.mode}, consent={self.settings.consent_given})")
            return

        logger.info(f"Preparing telemetry upload for run {run_id}")
        
        # 1. Export and Sanitize
        # Note: export_to_json already runs the PrivacyValidator
        try:
            payload_json = self.exporter.export_to_json(run_id=run_id)
            payload = json.loads(payload_json)
            
            if not payload.get("telemetry_events") and not payload.get("unknown_failures"):
                logger.info(f"No telemetry data found for run {run_id}")
                return

            # 2. Filter based on mode
            if self.settings.mode == TelemetryMode.ATLAS:
                # In ATLAS mode, we only keep unknown_failures and specific atlas events
                payload["telemetry_events"] = [
                    e for e in payload.get("telemetry_events", [])
                    if e.get("event") in ["unknown_failure_detected", "failure_atlas_miss"]
                ]
                # Remove metrics from design metadata if present
                if "escalations" in payload:
                    for esc in payload["escalations"]:
                        if "details" in esc:
                            # Keep only minimal details
                            esc["details"] = {k: v for k, v in esc["details"].items() if k in ["tool", "stage", "failure_type"]}

            # 3. Perform Upload (Simulation for now, as we don't have a real endpoint yet)
            # In a real scenario, this would be a POST request to GLI-FLOW Community Intelligence API
            logger.info(f"Uploading {len(payload.get('telemetry_events', []))} events and {len(payload.get('unknown_failures', []))} failures")
            
            # Audit the upload attempt
            self.audit.record(
                TelemetryAuditLog.EVENT_UPLOADED,
                f"run_{run_id}",
                "success",
                payload={"mode": self.settings.mode, "event_count": len(payload.get("telemetry_events", []))}
            )
            
            logger.info(f"Successfully uploaded telemetry for run {run_id}")
            
        except Exception as e:
            logger.error(f"Telemetry upload failed for run {run_id}: {e}")
            self.audit.record(
                TelemetryAuditLog.EVENT_UPLOADED,
                f"run_{run_id}",
                "failed",
                payload={"error": str(e)}
            )

    def trigger_background_upload(self, run_id: str):
        """Spawns a background process to handle the upload."""
        if not self.should_upload():
            return

        # We use the CLI to run the upload in background to avoid blocking the main process
        # and to ensure it survives if the main process exits.
        try:
            cmd = [sys.executable, "-m", "gli_flow.cli.main", "telemetry", "upload-internal", run_id]
            if self.db_path:
                cmd.extend(["--db-path", self.db_path])
            
            subprocess.Popen(
                cmd,
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
                start_new_session=True # Detach
            )
        except Exception as e:
            logger.warning(f"Failed to trigger background telemetry upload: {e}")

def auto_upload_run(run_id: str, db_path: Optional[str] = None):
    uploader = TelemetryUploader(db_path)
    uploader.trigger_background_upload(run_id)
