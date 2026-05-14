import argparse
import sys

from pathlib import Path

from gli_flow.history import (
    get_run_history
)

from gli_flow.config_validator import (
    validate_manifest
)

from gli_flow.backends.librelane import (
    validate_librelane,
    run_librelane
)


def run_command(args):

    design = args.design

    print("=" * 60)
    print("GLI-FLOW Execution")
    print("=" * 60)
    print()

    print(f"Design : {design}")
    print()

    design_path = Path(design)

    if not design_path.exists():

        print("[ERROR]")
        print("Design path does not exist.")
        print()

        sys.exit(1)

    manifest_path = (
        design_path
        / "gli_manifest.yaml"
    )

    print("Validating manifest...")
    print()

    valid, message = validate_manifest(
        manifest_path
    )

    if not valid:

        print("[ERROR]")
        print(message)
        print()

        sys.exit(1)

    print("[SUCCESS]")
    print(message)
    print()

    print("Validating LibreLane...")
    print()

    valid, message = validate_librelane()

    if not valid:

        print("[ERROR]")
        print(message)
        print()

        sys.exit(1)

    print("[SUCCESS]")
    print(message)
    print()

    print("Launching LibreLane...")
    print()

    result = run_librelane(
        design_path
    )

    if not result["success"]:

        print("[ERROR]")

        if "error" in result:

            print(result["error"])

        else:

            print(
                "LibreLane execution failed."
            )

        print()

        print(
            f"Log file: "
            f"{result['log_file']}"
        )

        sys.exit(1)

    print("[SUCCESS]")
    print("LibreLane execution completed.")
    print()

    print(
    f"Log file: "
    f"{result['log_file']}"
    )

    print()

    print(
    f"Metadata file: "
    f"{result['metadata_file']}"
    )

def history_command():

    print("=" * 60)
    print("GLI-FLOW Run History")
    print("=" * 60)
    print()

    runs = get_run_history()

    if not runs:

        print("No runs found.")
        return

    for run in runs:

        print(
            f"Timestamp : "
            f"{run.get('timestamp')}"
        )

        print(
            f"Design    : "
            f"{run.get('design_path')}"
        )
        
        print(
            f"Status    : "
            f"{run.get('status')}"
        )
        print(
            f"Success   : "
            f"{run.get('success')}"
        )

        print(
            f"Returncode: "
            f"{run.get('returncode')}"
        )

        print(
            f"Log file  : "
            f"{run.get('log_file')}"
        )

        print("-" * 60)

def build_parser():

    parser = argparse.ArgumentParser(

        prog="gli_flow",

        description=(
            "GLI-FLOW Execution Intelligence Infrastructure"
        )
    )

    subparsers = parser.add_subparsers(

        dest="command"
    )

    run_parser = subparsers.add_parser(

        "run",

        help="Run a GLI-FLOW execution"
    )

    subparsers.add_parser(

        "history",

        help="Show execution history"
    )

    run_parser.add_argument(

        "design",

        help="Path to design directory"
    )

    return parser


def main():

    parser = build_parser()

    args = parser.parse_args()

    if args.command == "run":

        run_command(args)

    elif args.command == "history":

        history_command()

    else:

        parser.print_help()

if __name__ == "__main__":

    main()
