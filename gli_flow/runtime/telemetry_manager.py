import json
import os


class TelemetryManager:

    def __init__(self, run_dir):
        self.run_dir = run_dir
        self.telemetry_dir = os.path.join(run_dir, "telemetry")
        os.makedirs(self.telemetry_dir, exist_ok=True)

    def _export_json(self, filename, data):
        output_file = os.path.join(self.telemetry_dir, filename)
        try:
            with open(output_file, "w") as f:
                json.dump(data, f, indent=2)
        except OSError as e:
            print(f"[WARN] Failed to write telemetry {filename}: {e}")

    def export_metrics(self, metrics):
        self._export_json("metrics.json", metrics)

    def export_stage_data(self, stage_name, data):
        safe_name = stage_name.lower().replace(" ", "_")
        self._export_json(f"{safe_name}.json", data)
