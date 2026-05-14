import json
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent.parent

DETECTIONS = (
    BASE_DIR
    / "outputs"
    / "reports"
    / "failure_detections.json"
)

SIGNATURES = (
    BASE_DIR
    / "failure_atlas"
    / "signatures.json"
)

with open(DETECTIONS) as f:
    detections = json.load(f)

with open(SIGNATURES) as f:
    signatures = json.load(f)

remediation_report = []

print("=" * 60)
print("GLI-FLOW Remediation Engine")
print("=" * 60)
print()

for detection in detections:

    failure_id = detection["failure_id"]

    for signature in signatures:

        if signature["failure_id"] == failure_id:

            remediation = {

                "run": detection["run"],
                "failure_id": failure_id,
                "severity": signature["severity"],
                "description": signature["description"],
                "recommended_actions":
                    signature["recommended_actions"]
            }

            remediation_report.append(remediation)

            print(f"[REMEDIATION] {failure_id}")
            print(f"  Run : {detection['run']}")
            print()

output = (
    BASE_DIR
    / "outputs"
    / "reports"
    / "remediation_report.json"
)

with open(output, "w") as f:
    json.dump(
        remediation_report,
        f,
        indent=4
    )

print("=" * 60)
print(f"[OUTPUT] {output}")
