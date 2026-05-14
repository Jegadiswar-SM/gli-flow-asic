import json
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent.parent

RUNS_DIR = (
    BASE_DIR
    / "openroad_runs"
)

SIGNATURES = (
    BASE_DIR
    / "failure_atlas"
    / "signatures.json"
)

with open(SIGNATURES) as f:
    signatures = json.load(f)

detections = []

print("=" * 60)
print("GLI-FLOW Failure Detection Engine")
print("=" * 60)
print()

for run in RUNS_DIR.iterdir():

    if not run.is_dir():
        continue

    log_file = run / "openroad.log"

    if not log_file.exists():
        continue

    log_text = log_file.read_text()

    for signature in signatures:

        pattern = signature["signature"]

        if pattern in log_text:

            detection = {

                "run": run.name,
                "failure_id": signature["failure_id"],
                "failure_type": signature["failure_type"],
                "severity": signature["severity"],
                "matched_signature": pattern,
                "description": signature["description"]
            }

            detections.append(detection)

            print(f"[DETECTED] {run.name}")
            print(f"  Failure ID : {signature['failure_id']}")
            print(f"  Severity   : {signature['severity']}")
            print()

output = (
    BASE_DIR
    / "outputs"
    / "reports"
    / "failure_detections.json"
)

with open(output, "w") as f:
    json.dump(
        detections,
        f,
        indent=4
    )

print("=" * 60)
print(f"[OUTPUT] {output}")
