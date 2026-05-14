import json
from pathlib import Path
from datetime import datetime

BASE_DIR = Path(__file__).resolve().parent.parent

required_components = [

    "environment",
    "execution",
    "failure_atlas",
    "reliability",
    "regression",
    "release",
    "docs",
    "outputs"
]

validation = {

    "generated_at":
        str(datetime.now()),

    "validation_status":
        "VALID",

    "checks": []
}

print("=" * 60)
print("GLI-FLOW Release Validation")
print("=" * 60)
print()

for component in required_components:

    path = BASE_DIR / component

    exists = path.exists()

    result = {

        "component": component,
        "exists": exists
    }

    validation["checks"].append(result)

    print(f"{component}")
    print(f"  Exists : {exists}")
    print()

    if not exists:
        validation["validation_status"] = "INVALID"

output = (
    BASE_DIR
    / "outputs"
    / "reports"
    / "release_validation_report_v2.json"
)

with open(output, "w") as f:
    json.dump(
        validation,
        f,
        indent=4
    )

print("=" * 60)
print(f"[OUTPUT] {output}")
