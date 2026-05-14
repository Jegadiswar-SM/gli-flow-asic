import json
import shutil
import subprocess

from pathlib import Path
from datetime import datetime


def validate_librelane():

    executable = shutil.which(
        "librelane"
    )

    if executable is None:

        return (

            False,

            "LibreLane executable not found.\n"
            "Please ensure LibreLane is installed "
            "and available in PATH."
        )

    return (

        True,

        f"LibreLane detected: {executable}"
    )


def write_metadata(
    metadata_file,
    metadata
):

    with open(metadata_file, "w") as f:

        json.dump(
            metadata,
            f,
            indent=4
        )


def run_librelane(design_path):

    timestamp = datetime.now().strftime(
        "%Y%m%d_%H%M%S"
    )

    run_dir = (
        Path("outputs/runs")
        / f"run_{timestamp}"
    )

    run_dir.mkdir(
        parents=True,
        exist_ok=True
    )

    log_file = (
        run_dir
        / "librelane.log"
    )

    metadata_file = (
        run_dir
        / "execution_metadata.json"
    )

    command = [

        "librelane",
        "--version"
    ]

    metadata = {

        "design_path":
            str(design_path),

        "timestamp":
            timestamp,

        "command":
            command,

        "status":
            "RUNNING",

        "success":
            False,

        "start_time":
            str(datetime.now()),

        "end_time":
            None,

        "returncode":
            None,

        "log_file":
            str(log_file)
    }

    write_metadata(
        metadata_file,
        metadata
    )

    try:

        result = subprocess.run(

            command,

            capture_output=True,
            text=True,
            timeout=30
        )

        with open(log_file, "w") as f:

            f.write(result.stdout)
            f.write("\n")
            f.write(result.stderr)

        success = (
            result.returncode == 0
        )

        metadata["end_time"] = str(
            datetime.now()
        )

        metadata["returncode"] = (
            result.returncode
        )

        metadata["success"] = success

        metadata["status"] = (

            "SUCCESS"
            if success
            else "FAILED"
        )

        write_metadata(
            metadata_file,
            metadata
        )

        return {

            "success": success,

            "status":
                metadata["status"],

            "returncode":
                result.returncode,

            "log_file":
                str(log_file),

            "metadata_file":
                str(metadata_file),

            "stdout":
                result.stdout,

            "stderr":
                result.stderr
        }

    except subprocess.TimeoutExpired:

        metadata["end_time"] = str(
            datetime.now()
        )

        metadata["status"] = "TIMEOUT"

        metadata["error"] = (
            "Execution timed out."
        )

        write_metadata(
            metadata_file,
            metadata
        )

        return {

            "success": False,

            "status":
                "TIMEOUT",

            "error":
                "LibreLane execution timed out.",

            "log_file":
                str(log_file),

            "metadata_file":
                str(metadata_file)
        }

    except Exception as e:

        metadata["end_time"] = str(
            datetime.now()
        )

        metadata["status"] = "FAILED"

        metadata["error"] = str(e)

        write_metadata(
            metadata_file,
            metadata
        )

        return {

            "success": False,

            "status":
                "FAILED",

            "error":
                str(e),

            "log_file":
                str(log_file),

            "metadata_file":
                str(metadata_file)
        }
