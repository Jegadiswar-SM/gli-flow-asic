import sqlite3


class DatabaseManager:

    def __init__(self):

        self.db_path = "gli_flow.db"

        self.connection = sqlite3.connect(
            self.db_path
        )

    def insert_run(self, record):

        cursor = self.connection.cursor()

        cursor.execute(
            """
            INSERT INTO runs (
                run_id,
                design_name,
                status,
                current_stage,
                progress,
                wns,
                tns,
                utilization,
                runtime_sec,
                cell_count,
                qor_score
            )
            VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
            """,
            (
                record.run_id,
                record.design_name,
                record.status,
                record.current_stage,
                record.progress,
                record.wns,
                record.tns,
                record.utilization,
                record.runtime_sec,
                record.cell_count,
                record.qor_score
            )
        )

        self.connection.commit()

    def update_run(
        self,
        run_id,
        status,
        current_stage,
        progress,
        wns,
        tns,
        utilization,
        runtime_sec,
        cell_count,
        qor_score
    ):

        cursor = self.connection.cursor()

        cursor.execute(
            """
            UPDATE runs

            SET
                status = ?,
                current_stage = ?,
                progress = ?,
                wns = ?,
                tns = ?,
                utilization = ?,
                runtime_sec = ?,
                cell_count = ?,
                qor_score = ?

            WHERE run_id = ?
            """,
            (
                status,
                current_stage,
                progress,
                wns,
                tns,
                utilization,
                runtime_sec,
                cell_count,
                qor_score,
                run_id
            )
        )

        self.connection.commit()

    def get_recent_runs(self):

        cursor = self.connection.cursor()

        cursor.execute(
            """
            SELECT
                run_id,
                design_name,
                qor_score,
                wns,
                tns,
                utilization,
                runtime_sec,
                cell_count

            FROM runs

            ORDER BY rowid DESC
            LIMIT 20
            """
        )

        rows = cursor.fetchall()

        results = []

        for row in rows:

            results.append({

                "run_id": row[0],
                "design_name": row[1],

                "qor_score": row[2],
                "wns": row[3],
                "tns": row[4],

                "utilization": row[5],
                "runtime_sec": row[6],

                "cell_count": row[7]
            })

        return results
