from pathlib import Path
from datetime import datetime


class RunDirectoryManager:

    def __init__(self):

        self.timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")

        self.run_id = f"run_{self.timestamp}"

        self.run_dir = Path("outputs/runs") / self.run_id

    def create(self):

        directories = [
            "logs",
            "reports",
            "artifacts",
            "metrics",
            "snapshots",
            "packaged"
        ]

        for directory in directories:

            (self.run_dir / directory).mkdir(
                parents=True,
                exist_ok=True
            )

        return self.run_dir
