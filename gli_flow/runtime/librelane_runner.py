import subprocess
import os


class LibreLaneRunner:

    def __init__(self, design_name, run_dir):

        self.design_name = design_name
        self.run_dir = run_dir

        self.librelane_python = os.path.expanduser(
            "~/GLI/third_party/librelane/venv/bin/python3"
        )

    def run(self):

        print()
        print("=" * 70)
        print("[GLI-FLOW] STARTING LIBRELANE")
        print("=" * 70)
        print()

        os.makedirs(self.run_dir, exist_ok=True)

        command = [
            self.librelane_python,
            "-m",
            "librelane",
            "--version"
        ]

        process = subprocess.Popen(
            command,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            cwd=self.run_dir
        )

        stdout, stderr = process.communicate()

        print(stdout)

        if stderr:
            print(stderr)

        print()
        print("[GLI-FLOW] LIBRELANE EXECUTION FINISHED")
        print()

        return {
            "status": "SUCCESS",
            "stdout": stdout,
            "stderr": stderr
        }
