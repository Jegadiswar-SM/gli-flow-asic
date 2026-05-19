import json
import os
import time


def generate_manifest(
    run_id,
    design_name,
    metrics
):

    manifest = {
        "run_id": run_id,
        "design_name": design_name,
        "timestamp": time.time(),
        "toolchain": "LibreLane",
        "gli_flow_version": "v1.0.0 MVP",
        "metrics": metrics
    }

    output_dir = os.path.join(
        "outputs",
        "runs",
        run_id
    )

    os.makedirs(
        output_dir,
        exist_ok=True
    )

    output_path = os.path.join(
        output_dir,
        "manifest.json"
    )

    try:

        with open(output_path, "w") as f:

            json.dump(
                manifest,
                f,
                indent=4
            )

    except Exception:
        pass

    return output_path
