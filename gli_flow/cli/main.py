import argparse
import sys

from gli_flow.core.orchestrator import FlowOrchestrator

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

    design_name = args.design

    orchestrator = FlowOrchestrator(
        design_name
    )

    orchestrator.run()

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
