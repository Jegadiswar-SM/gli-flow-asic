from dataclasses import dataclass, field
from datetime import datetime


@dataclass
class ExecutionRecord:

    run_id: str
    design_name: str
    toolchain: str
    status: str
    current_stage: str
    progress: int = 0
    wns: float = None
    tns: float = None
    utilization: float = None
    runtime_sec: float = None
    cell_count: int = None
    qor_score: float = None
    timestamp: str = field(default_factory=lambda: datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
