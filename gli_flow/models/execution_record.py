from dataclasses import dataclass, field
from datetime import datetime
from typing import Optional


@dataclass
class ExecutionRecord:

    run_id: str
    design_name: str
    toolchain: str
    status: str
    current_stage: str
    progress: int = 0
    wns: Optional[float] = None
    tns: Optional[float] = None
    utilization: Optional[float] = None
    runtime_sec: Optional[float] = None
    cell_count: Optional[int] = None
    qor_score: Optional[float] = None
    hold_wns: Optional[float] = None
    hold_tns: Optional[float] = None
    run_dir: str = ""
    timestamp: str = field(default_factory=lambda: datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
