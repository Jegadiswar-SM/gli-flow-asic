import sqlite3


SCHEMA_SQL = """
CREATE TABLE IF NOT EXISTS runs (
    run_id TEXT PRIMARY KEY,
    design_name TEXT NOT NULL,
    status TEXT DEFAULT 'PENDING',
    current_stage TEXT DEFAULT 'INITIALIZING',
    progress INTEGER DEFAULT 0,
    wns REAL DEFAULT NULL,
    tns REAL DEFAULT NULL,
    utilization REAL DEFAULT NULL,
    runtime_sec REAL DEFAULT NULL,
    cell_count INTEGER DEFAULT NULL,
    qor_score REAL DEFAULT NULL,
    timestamp TEXT DEFAULT (datetime('now'))
)
"""


class DatabaseManager:

    def __init__(self, db_path=None):
        self.db_path = db_path or "gli_flow.db"
        self.connection = sqlite3.connect(self.db_path)
        self.connection.execute(SCHEMA_SQL)
        self.connection.commit()

    def close(self):
        if self.connection:
            self.connection.close()

    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.close()

    def insert_run(self, record):
        cursor = self.connection.cursor()
        cursor.execute(
            """
            INSERT INTO runs (
                run_id, design_name, status, current_stage,
                progress, wns, tns, utilization, runtime_sec,
                cell_count, qor_score
            )
            VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
            """,
            (
                record.run_id, record.design_name, record.status,
                record.current_stage, record.progress,
                record.wns, record.tns, record.utilization,
                record.runtime_sec, record.cell_count, record.qor_score,
            ),
        )
        self.connection.commit()

    def update_run(self, run_id, status=None, current_stage=None, progress=None,
                   wns=None, tns=None, utilization=None, runtime_sec=None,
                   cell_count=None, qor_score=None):
        fields = []
        values = []

        if status is not None:
            fields.append("status = ?")
            values.append(status)
        if current_stage is not None:
            fields.append("current_stage = ?")
            values.append(current_stage)
        if progress is not None:
            fields.append("progress = ?")
            values.append(progress)
        if wns is not None:
            fields.append("wns = ?")
            values.append(wns)
        if tns is not None:
            fields.append("tns = ?")
            values.append(tns)
        if utilization is not None:
            fields.append("utilization = ?")
            values.append(utilization)
        if runtime_sec is not None:
            fields.append("runtime_sec = ?")
            values.append(runtime_sec)
        if cell_count is not None:
            fields.append("cell_count = ?")
            values.append(cell_count)
        if qor_score is not None:
            fields.append("qor_score = ?")
            values.append(qor_score)

        if not fields:
            return

        values.append(run_id)

        cursor = self.connection.cursor()
        cursor.execute(
            f"UPDATE runs SET {', '.join(fields)} WHERE run_id = ?",
            values,
        )
        self.connection.commit()

    def get_recent_runs(self, limit=20):
        cursor = self.connection.cursor()
        cursor.execute(
            """
            SELECT run_id, design_name, qor_score,
                   wns, tns, utilization, runtime_sec, cell_count,
                   status, current_stage, progress, timestamp
            FROM runs
            ORDER BY timestamp DESC
            LIMIT ?
            """,
            (limit,),
        )

        return [
            {
                "run_id": row[0],
                "design_name": row[1],
                "qor_score": row[2],
                "wns": row[3],
                "tns": row[4],
                "utilization": row[5],
                "runtime_sec": row[6],
                "cell_count": row[7],
                "status": row[8],
                "current_stage": row[9],
                "progress": row[10],
                "timestamp": row[11],
            }
            for row in cursor.fetchall()
        ]

    def get_runs_for_design(self, design_name, limit=10):
        cursor = self.connection.cursor()
        cursor.execute(
            """
            SELECT run_id, design_name, qor_score,
                   wns, tns, utilization, runtime_sec, cell_count,
                   status, current_stage, progress, timestamp
            FROM runs
            WHERE design_name = ?
            ORDER BY timestamp DESC
            LIMIT ?
            """,
            (design_name, limit),
        )

        return [
            {
                "run_id": row[0],
                "design_name": row[1],
                "qor_score": row[2],
                "wns": row[3],
                "tns": row[4],
                "utilization": row[5],
                "runtime_sec": row[6],
                "cell_count": row[7],
                "status": row[8],
                "current_stage": row[9],
                "progress": row[10],
                "timestamp": row[11],
            }
            for row in cursor.fetchall()
        ]

    def get_last_successful_run(self, design_name):
        cursor = self.connection.cursor()
        cursor.execute(
            """
            SELECT run_id, design_name, qor_score,
                   wns, tns, utilization, runtime_sec, cell_count,
                   status, current_stage, progress, timestamp
            FROM runs
            WHERE design_name = ? AND status = 'SUCCESS'
            ORDER BY timestamp DESC
            LIMIT 1
            """,
            (design_name,),
        )

        row = cursor.fetchone()
        if row is None:
            return None

        return {
            "run_id": row[0],
            "design_name": row[1],
            "qor_score": row[2],
            "wns": row[3],
            "tns": row[4],
            "utilization": row[5],
            "runtime_sec": row[6],
            "cell_count": row[7],
            "status": row[8],
            "current_stage": row[9],
            "progress": row[10],
            "timestamp": row[11],
        }
