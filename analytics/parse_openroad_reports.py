from pathlib import Path
import json
import re

BASE_DIR = Path(__file__).resolve().parent.parent

RUNS_DIR = BASE_DIR / "openroad_runs"

metrics = []

for run in RUNS_DIR.iterdir():

    if not run.is_dir():
        continue

    log_file = run / "openroad.log"

    if not log_file.exists():
        continue

    content = log_file.read_text(errors="ignore")

    data = {
        "run": run.name,
        "flow_status": "SUCCESS"
        if "Flow complete" in content
        else "FAILED",
        "cell_count": None,
        "runtime_seconds": None,
        "wns": None,
        "tns": None,
        "power": None
    }

    cell_match = re.search(
        r"Number of cells:\s+(\d+)",
        content
    )

    if cell_match:
        data["cell_count"] = int(
            cell_match.group(1)
        )

    runtime_match = re.search(
        r"Elapsed time:\s+([\d\.]+)",
        content
    )

    if runtime_match:
        data["runtime_seconds"] = float(
            runtime_match.group(1)
        )

    wns_match = re.search(
        r"WNS.*?(-?\d+\.\d+)",
        content
    )

    if wns_match:
        data["wns"] = float(
            wns_match.group(1)
        )

    tns_match = re.search(
        r"TNS.*?(-?\d+\.\d+)",
        content
    )

    if tns_match:
        data["tns"] = float(
            tns_match.group(1)
        )

    power_match = re.search(
        r"Total Power.*?([\d\.]+)",
        content
    )

    if power_match:
        data["power"] = float(
            power_match.group(1)
        )

    metrics.append(data)

output = BASE_DIR / "openroad_metrics.json"

with open(output, "w") as f:
    json.dump(metrics, f, indent=4)

print("=" * 60)
print("GLI-FLOW OpenROAD Metrics Parser")
print("=" * 60)
print()

for item in metrics:
    print(item)

print()
print(f"[OUTPUT] {output.resolve()}")
