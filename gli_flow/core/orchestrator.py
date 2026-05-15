import os
import time
import random
from datetime import datetime

from gli_flow.models.execution_record import ExecutionRecord
from gli_flow.database.sqlite import DatabaseManager
from gli_flow.runtime.telemetry_manager import TelemetryManager


class FlowOrchestrator:

    def __init__(self, design_name):

        self.design_name = design_name

        self.toolchain = "LibreLane"

        self.run_id = datetime.now().strftime(
            "run_%Y%m%d_%H%M%S"
        )

        self.base_run_dir = "runs"

        os.makedirs(
            self.base_run_dir,
            exist_ok=True
        )

        self.run_dir = os.path.join(
            self.base_run_dir,
            self.run_id
        )

        os.makedirs(
            self.run_dir,
            exist_ok=True
        )

        self.stages = [

            "INITIALIZING",

            "SYNTHESIS",

            "FLOORPLAN",

            "PLACEMENT",

            "CTS",

            "ROUTING",

            "TIMING_ANALYSIS",

            "QOR_EXTRACTION",

            "PACKAGING"
        ]

        self.record = ExecutionRecord(

            run_id=self.run_id,

            design_name=self.design_name,

            toolchain=self.toolchain,

            status="RUNNING",

            current_stage="INITIALIZING",

            wns=0.0,

            tns=0.0,

            utilization=0.0,

            runtime_sec=0.0,

            cell_count=0,

            qor_score=0.0
        )

        self.database = DatabaseManager()

        self.telemetry = TelemetryManager(
            self.run_dir
        )

        self.database.insert_run(
            self.record
        )

    def simulate_metrics(self):

        self.record.wns = round(
            random.uniform(-0.20, 0.05),
            2
        )

        self.record.tns = round(
            random.uniform(-8.0, 0.0),
            2
        )

        self.record.utilization = round(
            random.uniform(55.0, 75.0),
            1
        )

        self.record.cell_count = random.randint(
            12000,
            18000
        )

        self.record.qor_score = round(
            random.uniform(0.65, 0.95),
            2
        )

    def execute_stage(self, stage):

        print()

        print("=" * 60)

        print("[GLI-FLOW] EXECUTING STAGE:")

        print(stage)

        print("=" * 60)

        print()

        self.record.current_stage = stage

        self.database.update_run(
            self.record
        )

        stage_data = {

            "stage": stage,

            "timestamp": datetime.now().isoformat(),

            "status": "COMPLETED"
        }

        self.telemetry.export_stage_data(
            stage,
            stage_data
        )

        time.sleep(1.5)

    def run(self):

        start_time = time.time()

        print()

        print("=" * 70)

        print("GLI-FLOW EXECUTION ORCHESTRATOR")

        print("=" * 70)

        print(f"RUN ID: {self.run_id}")

        print(f"DESIGN: {self.design_name}")

        print(f"TOOLCHAIN: {self.toolchain}")

        print("=" * 70)

        for stage in self.stages:

            self.execute_stage(stage)

        runtime = round(
            time.time() - start_time,
            2
        )

        self.simulate_metrics()

        self.record.runtime_sec = runtime

        self.record.status = "COMPLETED"

        self.record.current_stage = "COMPLETED"

        self.database.update_run(
            self.record
        )

        metrics = {

            "run_id": self.record.run_id,

            "design_name": self.record.design_name,

            "toolchain": self.record.toolchain,

            "status": self.record.status,

            "current_stage": self.record.current_stage,

            "wns": self.record.wns,

            "tns": self.record.tns,

            "utilization": self.record.utilization,

            "runtime_sec": self.record.runtime_sec,

            "cell_count": self.record.cell_count,

            "qor_score": self.record.qor_score,

            "timestamp": self.record.timestamp
        }

        self.telemetry.export_metrics(
            metrics
        )

        print()

        print("=" * 70)

        print("[GLI-FLOW] EXECUTION COMPLETED")

        print("=" * 70)

        print(f"Final WNS: {self.record.wns}")

        print(f"Final TNS: {self.record.tns}")

        print(f"Utilization: {self.record.utilization}%")

        print(f"Cell Count: {self.record.cell_count}")

        print(f"QoR Score: {self.record.qor_score}")

        print(f"Runtime: {self.record.runtime_sec} sec")

        print("=" * 70)

        print()
