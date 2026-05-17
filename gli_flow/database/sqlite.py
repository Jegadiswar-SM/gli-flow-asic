import sqlite3


class DatabaseManager:

    def __init__(self, db_path="gli_flow.db"):

        self.db_path = db_path

        self.initialize()


    def connect(self):

        return sqlite3.connect(self.db_path)


    def initialize(self):

        connection = self.connect()

        cursor = connection.cursor()

        cursor.execute("""
        CREATE TABLE IF NOT EXISTS runs (
            run_id TEXT PRIMARY KEY,
            design_name TEXT,
            toolchain TEXT,
            status TEXT,
            current_stage TEXT,
            wns REAL,
            tns REAL,
            utilization REAL,
            runtime_sec REAL,
            cell_count INTEGER,
            qor_score REAL,
            timestamp TEXT
        )
        """)

        connection.commit()

        connection.close()


    def insert_run(self, record):

        connection = self.connect()

        cursor = connection.cursor()

        cursor.execute("""
        INSERT OR REPLACE INTO runs (
            run_id,
            design_name,
            toolchain,
            status,
            current_stage,
            wns,
            tns,
            utilization,
            runtime_sec,
            cell_count,
            qor_score,
            timestamp
        )
        VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
        """, (
            record.run_id,
            record.design_name,
            record.toolchain,
            record.status,
            record.current_stage,
            record.wns,
            record.tns,
            record.utilization,
            record.runtime_sec,
            record.cell_count,
            record.qor_score,
            record.timestamp
        ))

        connection.commit()

        connection.close()


    def update_run(
        self,
        run_id,
        status=None,
        current_stage=None,
        wns=None,
        tns=None,
        utilization=None,
        runtime_sec=None,
        cell_count=None,
        qor_score=None
    ):

        connection = self.connect()

        cursor = connection.cursor()

        cursor.execute("""
        UPDATE runs
        SET
            status = ?,
            current_stage = ?,
            wns = ?,
            tns = ?,
            utilization = ?,
            runtime_sec = ?,
            cell_count = ?,
            qor_score = ?
        WHERE run_id = ?
        """, (
            status,
            current_stage,
            wns,
            tns,
            utilization,
            runtime_sec,
            cell_count,
            qor_score,
            run_id
        ))

        connection.commit()

        connection.close()


    def get_runs(self):

        connection = self.connect()

        cursor = connection.cursor()

        cursor.execute("""
        SELECT
            run_id,
            design_name,
            toolchain,
            status,
            current_stage,
            wns,
            tns,
            utilization,
            runtime_sec,
            cell_count,
            qor_score,
            timestamp
        FROM runs
        ORDER BY timestamp DESC
        """)

        rows = cursor.fetchall()

        connection.close()

        return rows
