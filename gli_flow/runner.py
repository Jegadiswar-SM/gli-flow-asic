import os
import subprocess
from datetime import datetime

RUNS_DIR = "runs"

def create_run():
    if not os.path.exists(RUNS_DIR):
        os.makedirs(RUNS_DIR)

    run_id = f"run_{len(os.listdir(RUNS_DIR)) + 1:03d}"
    run_path = os.path.join(RUNS_DIR, run_id)

    os.makedirs(run_path)
    os.makedirs(f"{run_path}/logs")
    os.makedirs(f"{run_path}/reports")
    os.makedirs(f"{run_path}/outputs")

    return run_id, run_path


def run_flow(design):

    if not os.path.exists(design):
        print(f"[GLI-FLOW] ERROR: Design file not found: {design}")
        return

    script_path = os.path.join(os.getcwd(), "scripts", "run_flow.sh")

    if not os.path.exists(script_path):
        print(f"[GLI-FLOW] ERROR: Script not found: {script_path}")
        return


    print(f"[GLI-FLOW] Running {design}")

    run_id, run_path = create_run()

    log_file = f"{run_path}/logs/run.log"

    cmd = ["bash", script_path, design]

    with open(log_file, "w") as log:
        process = subprocess.Popen(cmd, stdout=log, stderr=log)
        process.wait()

    if process.returncode == 0:
        print("[GLI-FLOW] SUCCESS")
    else:
        print("[GLI-FLOW] FAILED")

    print(f"[GLI-FLOW] Logs: {log_file}")
