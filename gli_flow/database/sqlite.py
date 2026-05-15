import sqlite3


DATABASE_FILE = "gli_flow.db"


class DatabaseManager:

    def __init__(self):

        self.connection = sqlite3.connect(
            DATABASE_FILE
        )

        self.cursor = self.connection.cursor()

    def initialize(self):

        self.cursor.execute("""
        CREATE TABLE IF NOT EXISTS runs (

            run_id TEXT PRIMARY KEY,
            design_name TEXT,
            toolchain TEXT,
            status TEXT,
            current_stage TEXT,

            runtime_sec REAL,
            wns REAL,
            tns REAL,
            utilization REAL,
            cell_count INTEGER,
            qor_score REAL,

            timestamp TEXT
        )
        """)

        self.connection.commit()

    def insert_run(self, record):

        self.cursor.execute("""
        INSERT INTO runs (

            run_id,
            design_name,
            toolchain,
            status,
            current_stage,

            runtime_sec,
            wns,
            tns,
            utilization,
            cell_count,
            qor_score,

            timestamp

        ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
        """, (

            record.run_id,
            record.design_name,
            record.toolchain,
            record.status,
            record.current_stage,

            record.runtime_sec,
            record.wns,
            record.tns,
            record.utilization,
            record.cell_count,
            record.qor_score,

            record.timestamp
        ))

        self.connection.commit()

    def update_stage(
        self,
        run_id,
        stage,
        status="RUNNING"
    ):

        self.cursor.execute("""
        UPDATE runs
        SET current_stage = ?,
            status = ?
        WHERE run_id = ?
        """, (
            stage,
            status,
            run_id
        ))

        self.connection.commit()

    def update_run(self, record):

        self.cursor.execute("""
        UPDATE runs
        SET

            status = ?,
            current_stage = ?,

            runtime_sec = ?,
            wns = ?,
            tns = ?,
            utilization = ?,
            cell_count = ?,
            qor_score = ?

        WHERE run_id = ?
        """, (

            record.status,
            record.current_stage,

            record.runtime_sec,
            record.wns,
            record.tns,
            record.utilization,
            record.cell_count,
            record.qor_score,

            record.run_id
        ))

        self.connection.commit()
