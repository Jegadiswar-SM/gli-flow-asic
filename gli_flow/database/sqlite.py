import os
import sqlite3
from pathlib import Path

from gli_flow.database.migrations import migrate_if_needed, MigrationEngine, RUNS_MIGRATIONS, _get_db_path


class DatabaseManager:

    def __init__(self, db_path=None):
        if db_path:
            self.db_path = db_path
        else:
            self.db_path = _get_db_path()
        migrate_if_needed(self.db_path)
        self.connection = sqlite3.connect(self.db_path)
        try:
            self.connection.execute("PRAGMA journal_mode=WAL")
        except sqlite3.OperationalError:
            self.connection.close()
            self.connection = sqlite3.connect(self.db_path)

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
                   hold_wns=None, hold_tns=None,
                   implementation_status=None, signoff_status=None,
                   implementation_score=None, signoff_score=None,
                   tapeout_ready=None, root_cause_summary=None,
                   drc_violations=None, drc_is_clean=None, lvs_result=None, lvs_is_clean=None,
                   signoff_setup_pass=None, signoff_hold_pass=None):
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
        if implementation_status is not None:
            fields.append("implementation_status = ?")
            values.append(implementation_status)
        if signoff_status is not None:
            fields.append("signoff_status = ?")
            values.append(signoff_status)
        if implementation_score is not None:
            fields.append("implementation_score = ?")
            values.append(implementation_score)
        if signoff_score is not None:
            fields.append("signoff_score = ?")
            values.append(signoff_score)
        if tapeout_ready is not None:
            fields.append("tapeout_ready = ?")
            values.append(1 if tapeout_ready else 0)
        if root_cause_summary is not None:
            fields.append("root_cause_summary = ?")
            values.append(root_cause_summary)
        if drc_violations is not None:
            fields.append("drc_violations = ?")
            values.append(drc_violations)
        if drc_is_clean is not None:
            fields.append("drc_is_clean = ?")
            values.append(1 if drc_is_clean else 0)
        if lvs_result is not None:
            fields.append("lvs_result = ?")
            values.append(lvs_result)
        if lvs_is_clean is not None:
            fields.append("lvs_is_clean = ?")
            values.append(1 if lvs_is_clean else 0)
        if signoff_setup_pass is not None:
            fields.append("signoff_setup_pass = ?")
            values.append(1 if signoff_setup_pass else 0)
        if signoff_hold_pass is not None:
            fields.append("signoff_hold_pass = ?")
            values.append(1 if signoff_hold_pass else 0)

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

    def update_run_investigation(self, run_id, available=None, status=None, summary=None, timestamp=None, failed_attempts=None):
        fields = []
        values = []
        if available is not None:
            fields.append("llm_investigation_available = ?")
            values.append(1 if available else 0)
        if status is not None:
            fields.append("llm_investigation_status = ?")
            values.append(status)
        if summary is not None:
            fields.append("llm_investigation_summary = ?")
            values.append(summary)
        if timestamp is not None:
            fields.append("llm_investigation_timestamp = ?")
            values.append(timestamp)
        if failed_attempts is not None:
            fields.append("llm_investigation_failed_attempts = ?")
            values.append(failed_attempts)
        if not fields:
            return
        values.append(run_id)
        self.connection.execute(
            f"UPDATE runs SET {', '.join(fields)} WHERE run_id = ?",
            values,
        )
        self.connection.commit()

    def get_run_investigation_row(self, run_id):
        cursor = self.connection.cursor()
        cursor.execute(
            """SELECT llm_investigation_available, llm_investigation_status,
               llm_investigation_summary, llm_investigation_timestamp,
               llm_investigation_failed_attempts
               FROM runs WHERE run_id = ?""",
            (run_id,),
        )
        return cursor.fetchone()

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
