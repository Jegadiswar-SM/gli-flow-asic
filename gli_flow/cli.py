import sys
from gli_flow.runner import run_flow

def main():
    if len(sys.argv) < 3:
        print("Usage: gli-flow run <design.v>")
        sys.exit(1)

    command = sys.argv[1]

    if command == "run":
        design = sys.argv[2]
        run_flow(design)
    else:
        print("Unknown command")

if __name__ == "__main__":
    main()
