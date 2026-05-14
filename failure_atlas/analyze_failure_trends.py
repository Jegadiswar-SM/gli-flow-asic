import json
from pathlib import Path
from collections import Counter

BASE_DIR = Path(__file__).resolve().parent.parent

FAILURE_INDEX = (
    BASE_DIR
    / "outputs"
    / "reports"
    / "failure_index.json"
)

with open(FAILURE_INDEX) as f:
    failure_index = json.load(f)

failures = failure_index["failures"]

failure_ids = [
    f["failure_id"]
    for f in failures
]

severity_levels = [
    f["severity"]
    for f in failures
]

failure_counter = Counter(
    failure_ids
)

severity_counter = Counter(
    severity_levels
)

trend_report = {

    "total_failures": len(failures),

    "failure_frequency":
        dict(failure_counter),

    "severity_distribution":
        dict(severity_counter)
}

print("=" * 60)
print("GLI-FLOW Failure Trend Intelligence")
print("=" * 60)
print()

print(f"Total Failures : {len(failures)}")
print()

print("Failure Frequency")
print("------------------------------")

for key, value in failure_counter.items():

    print(f"{key} : {value}")

print()

print("Severity Distribution")
print("------------------------------")

for key, value in severity_counter.items():

    print(f"{key} : {value}")

output = (
    BASE_DIR
    / "outputs"
    / "reports"
    / "failure_trend_report.json"
)

with open(output, "w") as f:
    json.dump(
        trend_report,
        f,
        indent=4
    )

print()
print("=" * 60)
print(f"[OUTPUT] {output}")
