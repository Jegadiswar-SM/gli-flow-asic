import json
from pathlib import Path
from datetime import datetime

BASE_DIR = Path(__file__).resolve().parent.parent

DETECTIONS = (
    BASE_DIR
    / "outputs"
    / "reports"
    / "failure_detections.json"
)

with open(DETECTIONS) as f:
    detections = json.load(f)

failure_index = {

    "generated_at": str(
        datetime.now()
    ),

    "failure_count": len(
        detections
    ),

    "failures": detections
}

print("=" * 60)
print("GLI-FLOW Failure Index")
print("=" * 60)
print()

print(f"Detected Failures : {len(detections)}")
print()

for failure in detections:

    print(f"{failure['failure_id']}")
    print(f"  Run      : {failure['run']}")
    print(f"  Severity : {failure['severity']}")
    print()

output = (
    BASE_DIR
    / "outputs"
    / "reports"
    / "failure_index.json"
)

with open(output, "w") as f:
    json.dump(
        failure_index,
        f,
        indent=4
    )

print("=" * 60)
print(f"[OUTPUT] {output}")
