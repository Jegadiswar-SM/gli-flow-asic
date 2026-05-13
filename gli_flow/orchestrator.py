import subprocess
import sys


STEPS = [
    {
        "name": "Environment Validation",
        "command": [
            "python3",
            "environment/validate_environment.py"
        ]
    },

    {
        "name": "Manifest Generation",
        "command": [
            "python3",
            "manifests/generate_manifest.py"
        ]
    },

    {
        "name": "Telemetry Collection",
        "command": [
            "python3",
            "telemetry/collect_metrics.py"
        ]
    },

    {
        "name": "Run Correlation",
        "command": [
            "python3",
            "execution_history/correlate_runs.py"
        ]
    },

    {
        "name": "Failure Detection",
        "command": [
            "python3",
            "failure_atlas/detect_failures.py"
        ]
    },

    {
        "name": "Reproducibility Verification",
        "command": [
            "python3",
            "environment/reproducibility_check.py"
        ]
    }
]


def run_step(step):
    print("\n" + "=" * 60)
    print(f"[RUNNING] {step['name']}")
    print("=" * 60)

    result = subprocess.run(step["command"])

    if result.returncode != 0:
        print(f"\n[FAILED] {step['name']}")
        sys.exit(1)

    print(f"\n[SUCCESS] {step['name']}")


def main():
    print("=" * 60)
    print("GLI-FLOW Unified Execution Pipeline")
    print("=" * 60)

    for step in STEPS:
        run_step(step)

    print("\n" + "=" * 60)
    print("[COMPLETE] GLI-FLOW pipeline executed successfully")
    print("=" * 60)


if __name__ == "__main__":
    main()
