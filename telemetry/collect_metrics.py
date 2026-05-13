import json
import os
from datetime import datetime


RUNS_DIR = "../runs"
OUTPUT_FILE = "telemetry_snapshot.json"


def collect_metrics():
    metrics = {
        "generated_at": datetime.utcnow().isoformat(),
        "total_runs": 0,
        "runs": []
    }

    if not os.path.exists(RUNS_DIR):
        return metrics

    run_dirs = sorted(os.listdir(RUNS_DIR))

    for run_name in run_dirs:
        run_path = os.path.join(RUNS_DIR, run_name)

        if os.path.isdir(run_path):
            run_data = {
                "run_id": run_name,
                "path": os.path.abspath(run_path),
                "log_files": 0,
                "json_files": 0
            }

            for root, dirs, files in os.walk(run_path):
                for file in files:
                    if file.endswith(".log"):
                        run_data["log_files"] += 1

                    if file.endswith(".json"):
                        run_data["json_files"] += 1

            metrics["runs"].append(run_data)

    metrics["total_runs"] = len(metrics["runs"])

    return metrics


def main():
    metrics = collect_metrics()

    with open(OUTPUT_FILE, "w") as f:
        json.dump(metrics, f, indent=4)

    print("=" * 60)
    print("GLI-FLOW Telemetry Collector")
    print("=" * 60)

    print(f"[SUCCESS] Telemetry snapshot generated")
    print(f"[OUTPUT] {OUTPUT_FILE}")
    print(f"[RUNS] {metrics['total_runs']}")


if __name__ == "__main__":
    main()
