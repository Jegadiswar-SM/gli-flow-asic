import json


class ArtifactManager:

    def __init__(self):

        self.artifacts = []

    def add_artifact(

        self,

        artifact_path
    ):

        self.artifacts.append(
            artifact_path
        )

    def export_manifest(

        self,

        run_dir
    ):

        manifest_path = (
            f"{run_dir}/artifacts/"
            f"artifact_manifest.json"
        )

        manifest = {

            "artifacts": self.artifacts
        }

        with open(
            manifest_path,
            "w"
        ) as file:

            json.dump(

                manifest,

                file,

                indent=4
            )
