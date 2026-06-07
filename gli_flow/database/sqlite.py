import os
import sqlite3
from pathlib import Path

from gli_flow.database.migrations import migrate_if_needed, MigrationEngine, RUNS_MIGRATIONS


class DatabaseManager:

    def __init__(self, db_path=None):
        if db_path:
            self.db_path = db_path
        else:
            self.db_path = os.environ.get("GLI_FLOW_DB")
            if not self.db_path:
                db_dir = Path.home() / ".gli_flow"
                db_dir.mkdir(parents=True, exist_ok=True)
                self.db_path = str(db_dir / "gli_flow.db")
        migrate_if_needed(self.db_path)
        self.connection = sqlite3.connect(self.db_path)
        self.connection.execute("PRAGMA journal_mode=WAL")

    def update_run_signoff(self, run_id, signoff_gate=None, timing_result=None, drc_result=None, lvs_result=None):
        import dataclasses
        import json as json_mod
        self.execute("""
            UPDATE runs SET
                drc_magic_violations = ?,
                drc_klayout_violations = ?,
                drc_is_clean = ?,
                lvs_result = ?,
                lvs_is_clean = ?,
                setup_wns_ns = ?,
                hold_whs_ns = ?,
                signoff_setup_pass = ?,
                signoff_hold_pass = ?,
                signoff_gate_json = ?,
                tapeout_ready = ?
            WHERE run_id = ?
        """, (
            drc_result.magic_violations if drc_result else None,
            drc_result.klayout_violations if drc_result else None,
            drc_result.is_clean if drc_result else False,
            lvs_result.result if lvs_result else "NOT_RUN",
            lvs_result.is_clean if lvs_result else False,
            timing_result.setup_wns_ns if timing_result else None,
            timing_result.hold_whs_ns if timing_result else None,
            signoff_gate.setup_pass if signoff_gate else False,
            signoff_gate.hold_pass if signoff_gate else False,
            json_mod.dumps(dataclasses.asdict(signoff_gate)) if signoff_gate else "{}",
            signoff_gate.tapeout_ready if signoff_gate else False,
            run_id,
        ))

    def execute(self, sql, params=None):
        cursor = self.connection.cursor()
        if params:
            cursor.execute(sql, params)
        else:
            cursor.execute(sql)
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
                cell_count, qor_score, run_dir
            )
            VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
            """,
            (
                record.run_id, record.design_name, record.status,
                record.current_stage, record.progress,
                record.wns, record.tns, record.utilization,
                record.runtime_sec, record.cell_count, record.qor_score,
                str(getattr(record, 'run_dir', '')),
            ),
        )
        self.connection.commit()

    def update_run(self, run_id, status=None, current_stage=None, progress=None,
                   wns=None, tns=None, utilization=None, runtime_sec=None,
                   cell_count=None, qor_score=None, run_dir=None,
                   hold_wns=None, hold_tns=None):
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
        if hold_wns is not None:
            fields.append("hold_wns = ?")
            values.append(hold_wns)
        if hold_tns is not None:
            fields.append("hold_tns = ?")
            values.append(hold_tns)
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
        if run_dir is not None:
            fields.append("run_dir = ?")
            values.append(run_dir)

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

    def get_run(self, run_id):
        cursor = self.connection.cursor()
        cursor.execute(
            """
            SELECT run_id, design_name, qor_score,
                   wns, tns, utilization, runtime_sec, cell_count,
                   status, current_stage, progress, timestamp,
                   run_dir, regression, drc_violations, lvs_result
            FROM runs
            WHERE run_id = ?
            """,
            (run_id,),
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
            "run_dir": row[12],
            "regression": row[13],
            "drc_violations": row[14],
            "lvs_result": row[15],
        }

    def get_qor_trend(self, limit=20):
        cursor = self.connection.cursor()
        cursor.execute(
            """
            SELECT qor_score, wns, tns, utilization, timestamp
            FROM runs
            WHERE qor_score IS NOT NULL
            ORDER BY timestamp DESC
            LIMIT ?
            """,
            (limit,),
        )
        return [
            {
                "qor_score": row[0],
                "wns": row[1],
                "tns": row[2],
                "utilization": row[3],
                "timestamp": row[4],
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
