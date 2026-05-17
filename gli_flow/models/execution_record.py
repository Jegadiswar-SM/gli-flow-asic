from dataclasses import dataclass
from datetime import datetime


@dataclass
class ExecutionRecord:

    run_id: str

    design_name: str

    toolchain: str

    status: str

    current_stage: str

    wns: float = 0.0

    tns: float = 0.0

    utilization: float = 0.0

    runtime_sec: float = 0.0

    cell_count: int = 0

    qor_score: float = 0.0

    timestamp: str = ""

    def __post_init__(self):

        if self.timestamp == "":

            self.timestamp = datetime.now().strftime(
                "%Y-%m-%d %H:%M:%S"
            )
