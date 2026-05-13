import subprocess
from datetime import datetime
from pathlib import Path


ROOT_DIR = Path.home() / "GLI" / "tapeitout.com" / "gli-flow"

DESIGN_DIR = (
    ROOT_DIR
    / "designs"
    / "counter_design"
)

RUN_DIR = (
    ROOT_DIR
    / "openroad_runs"
    / f"openroad_run_{datetime.now().strftime('%Y%m%d_%H%M%S')}"
)

RUN_DIR.mkdir(
    parents=True,
    exist_ok=True
)


def run_flow():

    log_file = RUN_DIR / "openroad.log"

    command = [
    "sudo",
    str(
        Path.home()
        / "GLI"
        / "third_party"
        / "librelane"
        / "venv"
        / "bin"
        / "librelane"
    ),
    "--containerized",
    "-f",
    "classic",
    str(
        DESIGN_DIR / "config.json"
    ),
    "--design-dir",
    str(DESIGN_DIR)
    ]

    with open(log_file, "w") as log:

        result = subprocess.run(
            command,
            stdout=log,
            stderr=log
        )

    return result.returncode, log_file


def print_results(code, log_file):

    print("=" * 60)
    print("GLI-FLOW OpenROAD Integration")
    print("=" * 60)

    print(f"LOG FILE : {log_file}")

    if code == 0:

        print(
            "\n[SUCCESS] OpenROAD flow completed"
        )

    else:

        print(
            "\n[FAILED] OpenROAD flow failed"
        )

    print("\n========================================")


def main():

    code, log_file = run_flow()

    print_results(
        code,
        log_file
    )


if __name__ == "__main__":
    main()
