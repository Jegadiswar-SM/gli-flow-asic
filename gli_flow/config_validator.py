import yaml

from pathlib import Path


REQUIRED_FIELDS = [

    "design_name",
    "rtl_files",
    "top_module",
    "backend"
]

SUPPORTED_BACKENDS = [

    "librelane"
]


def validate_manifest(manifest_path):

    manifest_path = Path(manifest_path)

    if not manifest_path.exists():

        return (
            False,
            f"Manifest not found: {manifest_path}"
        )

    try:

        with open(manifest_path) as f:

            manifest = yaml.safe_load(f)

    except Exception as e:

        return (
            False,
            f"Failed to parse YAML: {e}"
        )

    if not isinstance(manifest, dict):

        return (
            False,
            "Manifest must be a YAML dictionary."
        )

    missing_fields = []

    for field in REQUIRED_FIELDS:

        if field not in manifest:

            missing_fields.append(field)

    if missing_fields:

        return (

            False,

            "Missing required fields: "
            + ", ".join(missing_fields)
        )

    backend = manifest["backend"]

    if backend not in SUPPORTED_BACKENDS:

        return (

            False,

            "Unsupported backend: "
            f"{backend}. "
            "Supported backends: "
            + ", ".join(SUPPORTED_BACKENDS)
        )

    rtl_files = manifest["rtl_files"]

    if not isinstance(rtl_files, list):

        return (

            False,

            "rtl_files must be a list."
        )

    for rtl in rtl_files:

        rtl_path = Path(rtl)

        if not rtl_path.exists():

            return (

                False,

                f"RTL file not found: {rtl}"
            )

    return (

        True,

        "Manifest validation successful."
    )
