import json
import os
import sqlite3
import uuid
from datetime import datetime, timezone
from pathlib import Path
from typing import Optional, List, Dict, Any


REQUIRED_FIELDS = [
    "id", "run_id", "failure_id", "failure_type", "severity",
    "title", "description", "recommended_fix", "confidence",
    "signature", "detected_at", "domain", "category",
]

RESOLUTION_FIELDS = [
    "fix_applied", "fix_type", "fix_description", "fix_run_id",
    "before_metrics", "after_metrics", "resolution_confidence",
]


SCHEMA_SQL = """
CREATE TABLE IF NOT EXISTS failure_atlas_entries (
    id TEXT PRIMARY KEY,
    run_id TEXT NOT NULL,
    failure_id TEXT,
    failure_type TEXT NOT NULL,
    severity TEXT NOT NULL,
    title TEXT,
    description TEXT,
    recommended_fix TEXT,
    confidence REAL DEFAULT 0.8,
    signature TEXT,
    domain TEXT,
    category TEXT,
    evidence TEXT,
    detected_at TEXT DEFAULT (datetime('now')),
    created_at TEXT DEFAULT (datetime('now')),
    parent_run_id TEXT,
    fix_applied INTEGER DEFAULT 0,
    fix_type TEXT,
    fix_description TEXT,
    fix_run_id TEXT,
    before_metrics TEXT,
    after_metrics TEXT,
    resolution_confidence TEXT,
    FOREIGN KEY (run_id) REFERENCES runs(run_id)
)
"""

MIGRATIONS = [
    "ALTER TABLE failure_atlas_entries ADD COLUMN parent_run_id TEXT DEFAULT NULL",
    "ALTER TABLE failure_atlas_entries ADD COLUMN before_metrics TEXT DEFAULT NULL",
    "ALTER TABLE failure_atlas_entries ADD COLUMN after_metrics TEXT DEFAULT NULL",
    "ALTER TABLE failure_atlas_entries ADD COLUMN resolution_confidence TEXT DEFAULT NULL",
]


class FailureAtlasRepository:

    def __init__(self, db_path: Optional[str] = None):
        if db_path:
            self.db_path = db_path
        else:
            self.db_path = os.environ.get("GLI_FLOW_DB")
            if not self.db_path:
                self.db_path = os.environ.get("GLI_FLOW_DB_PATH")
            if not self.db_path:
                db_dir = Path.home() / ".gli_flow"
                db_dir.mkdir(parents=True, exist_ok=True)
                self.db_path = str(db_dir / "gli_flow.db")

        self.connection = sqlite3.connect(self.db_path)
        self.connection.row_factory = sqlite3.Row
        self._init_schema()

    def _init_schema(self):
        self.connection.execute(SCHEMA_SQL)
        self.connection.commit()
        self._run_migrations()

    def _run_migrations(self):
        cursor = self.connection.cursor()
        for migration in MIGRATIONS:
            try:
                cursor.execute(migration)
                self.connection.commit()
            except sqlite3.OperationalError:
                pass

    def insert_entry(self, entry: Dict[str, Any]) -> str:
        entry_id = entry.get("id") or str(uuid.uuid4())
        entry.setdefault("detected_at", datetime.now(timezone.utc).isoformat())
        entry.setdefault("created_at", datetime.now(timezone.utc).isoformat())
        entry.setdefault("confidence", 0.8)
        entry.setdefault("fix_applied", 0)

        evidence = entry.get("evidence")
        if isinstance(evidence, dict):
            evidence = json.dumps(evidence)
        recommended_fix = entry.get("recommended_fix")
        if isinstance(recommended_fix, list):
            recommended_fix = json.dumps(recommended_fix)
        before_metrics = entry.get("before_metrics")
        if isinstance(before_metrics, dict):
            before_metrics = json.dumps(before_metrics)
        after_metrics = entry.get("after_metrics")
        if isinstance(after_metrics, dict):
            after_metrics = json.dumps(after_metrics)

        self.connection.execute(
            """
            INSERT OR REPLACE INTO failure_atlas_entries (
                id, run_id, failure_id, failure_type, severity,
                title, description, recommended_fix, confidence,
                signature, domain, category, evidence,
                detected_at, created_at, parent_run_id,
                fix_applied, fix_type, fix_description, fix_run_id,
                before_metrics, after_metrics, resolution_confidence
            ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
            """,
            (
                entry_id,
                entry.get("run_id"),
                entry.get("failure_id"),
                entry.get("failure_type"),
                entry.get("severity"),
                entry.get("title"),
                entry.get("description"),
                recommended_fix,
                entry.get("confidence", 0.8),
                entry.get("signature"),
                entry.get("domain"),
                entry.get("category"),
                evidence,
                entry.get("detected_at"),
                entry.get("created_at"),
                entry.get("parent_run_id"),
                int(entry.get("fix_applied", 0)),
                entry.get("fix_type"),
                entry.get("fix_description"),
                entry.get("fix_run_id"),
                before_metrics,
                after_metrics,
                entry.get("resolution_confidence"),
            ),
        )
        self.connection.commit()
        return entry_id

    def get_failures_for_run(self, run_id: str) -> List[Dict[str, Any]]:
        cursor = self.connection.cursor()
        cursor.execute(
            "SELECT * FROM failure_atlas_entries WHERE run_id = ? ORDER BY detected_at DESC",
            (run_id,),
        )
        return [self._row_to_dict(row) for row in cursor.fetchall()]

    def get_all_failures(self, limit: int = 50, offset: int = 0,
                         severity: Optional[str] = None,
                         failure_type: Optional[str] = None,
                         search: Optional[str] = None) -> List[Dict[str, Any]]:
        query = "SELECT * FROM failure_atlas_entries WHERE 1=1"
        params = []

        if severity:
            query += " AND severity = ?"
            params.append(severity)
        if failure_type:
            query += " AND failure_type = ?"
            params.append(failure_type)
        if search:
            query += " AND (title LIKE ? OR description LIKE ? OR failure_type LIKE ?)"
            params.extend([f"%{search}%", f"%{search}%", f"%{search}%"])

        query += " ORDER BY detected_at DESC LIMIT ? OFFSET ?"
        params.extend([limit, offset])

        cursor = self.connection.cursor()
        cursor.execute(query, params)
        return [self._row_to_dict(row) for row in cursor.fetchall()]

    def get_failure_by_id(self, failure_id: str) -> Optional[Dict[str, Any]]:
        cursor = self.connection.cursor()
        cursor.execute(
            "SELECT * FROM failure_atlas_entries WHERE id = ?",
            (failure_id,),
        )
        row = cursor.fetchone()
        return self._row_to_dict(row) if row else None

    def get_failure_count(self, severity: Optional[str] = None,
                          failure_type: Optional[str] = None,
                          search: Optional[str] = None) -> int:
        query = "SELECT COUNT(*) FROM failure_atlas_entries WHERE 1=1"
        params = []

        if severity:
            query += " AND severity = ?"
            params.append(severity)
        if failure_type:
            query += " AND failure_type = ?"
            params.append(failure_type)
        if search:
            query += " AND (title LIKE ? OR description LIKE ? OR failure_type LIKE ?)"
            params.extend([f"%{search}%", f"%{search}%", f"%{search}%"])

        cursor = self.connection.cursor()
        cursor.execute(query, params)
        return cursor.fetchone()[0]

    def update_resolution(self, failure_id: str, fix_type: str,
                          fix_description: str, fix_run_id: str,
                          before_metrics: Optional[Dict] = None,
                          after_metrics: Optional[Dict] = None) -> bool:
        cursor = self.connection.cursor()

        before_json = json.dumps(before_metrics) if before_metrics else None
        after_json = json.dumps(after_metrics) if after_metrics else None

        resolution_confidence = self._compute_resolution_confidence(
            before_metrics, after_metrics
        )

        cursor.execute(
            """
            UPDATE failure_atlas_entries SET
                fix_applied = 1,
                fix_type = ?,
                fix_description = ?,
                fix_run_id = ?,
                before_metrics = ?,
                after_metrics = ?,
                resolution_confidence = ?
            WHERE id = ?
            """,
            (fix_type, fix_description, fix_run_id,
             before_json, after_json, resolution_confidence,
             failure_id),
        )
        self.connection.commit()
        return cursor.rowcount > 0

    def _compute_resolution_confidence(self, before: Optional[Dict],
                                       after: Optional[Dict]) -> str:
        if not before or not after:
            return "MEDIUM"

        wns_before = before.get("wns") or 0
        wns_after = after.get("wns") or 0
        tns_before = before.get("tns") or 0
        tns_after = after.get("tns") or 0

        wns_improved = wns_after > wns_before
        tns_improved = tns_after > tns_before

        if wns_improved and tns_improved:
            return "HIGH"
        elif wns_improved or tns_improved:
            return "MEDIUM"
        else:
            return "LOW"

    def get_analytics_summary(self) -> Dict[str, Any]:
        cursor = self.connection.cursor()

        cursor.execute("SELECT COUNT(*) FROM failure_atlas_entries")
        total_count = cursor.fetchone()[0]

        cursor.execute("SELECT COUNT(*) FROM failure_atlas_entries WHERE fix_applied = 1")
        fixed_count = cursor.fetchone()[0]

        unfixed_count = total_count - fixed_count
        success_rate = (fixed_count / total_count * 100) if total_count > 0 else 0

        return {
            "total_failures": total_count,
            "fixed_count": fixed_count,
            "unfixed_count": unfixed_count,
            "success_rate": round(success_rate, 1),
        }

    def get_common_failures(self, limit: int = 10) -> List[Dict[str, Any]]:
        cursor = self.connection.cursor()
        cursor.execute(
            """
            SELECT failure_type, COUNT(*) as count,
                   ROUND(CAST(COUNT(*) AS FLOAT) / (SELECT COUNT(*) FROM failure_atlas_entries) * 100, 1) as percentage
            FROM failure_atlas_entries
            GROUP BY failure_type
            ORDER BY count DESC
            LIMIT ?
            """,
            (limit,),
        )
        return [dict(row) for row in cursor.fetchall()]

    def get_fix_effectiveness(self, min_samples: int = 3) -> List[Dict[str, Any]]:
        cursor = self.connection.cursor()
        cursor.execute(
            """
            SELECT failure_type, fix_type,
                   COUNT(*) as sample_size,
                   ROUND(CAST(SUM(fix_applied) AS FLOAT) / COUNT(*) * 100, 1) as success_rate
            FROM failure_atlas_entries
            WHERE fix_type IS NOT NULL AND fix_type != ''
            GROUP BY failure_type, fix_type
            HAVING sample_size >= ?
            ORDER BY success_rate DESC
            """,
            (min_samples,),
        )
        return [dict(row) for row in cursor.fetchall()]

    def get_qor_improvements(self) -> List[Dict[str, Any]]:
        cursor = self.connection.cursor()
        cursor.execute(
            """
            SELECT fix_type,
                   COUNT(*) as sample_size,
                   AVG(
                       CASE
                           WHEN before_metrics IS NOT NULL AND after_metrics IS NOT NULL
                           THEN json_extract(after_metrics, '$.wns') - json_extract(before_metrics, '$.wns')
                           ELSE 0
                       END
                   ) as avg_wns_improvement,
                   AVG(
                       CASE
                           WHEN before_metrics IS NOT NULL AND after_metrics IS NOT NULL
                           THEN json_extract(after_metrics, '$.tns') - json_extract(before_metrics, '$.tns')
                           ELSE 0
                       END
                   ) as avg_tns_improvement
            FROM failure_atlas_entries
            WHERE fix_type IS NOT NULL AND fix_type != ''
            GROUP BY fix_type
            ORDER BY avg_wns_improvement DESC
            """
        )
        return [dict(row) for row in cursor.fetchall()]

    def get_failure_trends(self) -> Dict[str, Any]:
        cursor = self.connection.cursor()
        cursor.execute(
            """
            SELECT failure_type, COUNT(*) as count,
                   ROUND(CAST(COUNT(*) AS FLOAT) / (SELECT COUNT(*) FROM failure_atlas_entries) * 100, 1) as percentage
            FROM failure_atlas_entries
            GROUP BY failure_type
            ORDER BY count DESC
            """
        )
        failure_dist = [dict(row) for row in cursor.fetchall()]

        cursor.execute(
            """
            SELECT DATE(detected_at) as date, COUNT(*) as count
            FROM failure_atlas_entries
            GROUP BY DATE(detected_at)
            ORDER BY date DESC
            LIMIT 30
            """
        )
        daily_counts = [dict(row) for row in cursor.fetchall()]

        return {
            "failure_distribution": failure_dist,
            "daily_counts": daily_counts,
        }

    def get_mttr_by_type(self) -> List[Dict[str, Any]]:
        cursor = self.connection.cursor()
        cursor.execute(
            """
            SELECT failure_type,
                   COUNT(*) as sample_size,
                   ROUND(AVG(
                       CASE
                           WHEN fix_run_id IS NOT NULL AND fix_run_id != ''
                           THEN 1.0
                           ELSE NULL
                       END
                   ), 2) as avg_resolution_steps
            FROM failure_atlas_entries
            GROUP BY failure_type
            ORDER BY sample_size DESC
            """
        )
        return [dict(row) for row in cursor.fetchall()]

    def get_regression_events(self) -> List[Dict[str, Any]]:
        cursor = self.connection.cursor()
        cursor.execute(
            """
            SELECT f1.*
            FROM failure_atlas_entries f1
            WHERE f1.detected_at = (
                SELECT MIN(f2.detected_at)
                FROM failure_atlas_entries f2
                WHERE f2.failure_type = f1.failure_type
            )
            ORDER BY f1.detected_at DESC
            LIMIT 20
            """
        )
        return [self._row_to_dict(row) for row in cursor.fetchall()]

    def similar_failures(self, failure_type: str, limit: int = 10) -> List[Dict[str, Any]]:
        cursor = self.connection.cursor()
        cursor.execute(
            """
            SELECT failure_type, fix_type,
                   COUNT(*) as sample_size,
                   ROUND(CAST(SUM(fix_applied) AS FLOAT) / COUNT(*) * 100, 1) as success_rate
            FROM failure_atlas_entries
            WHERE failure_type = ?
            GROUP BY failure_type, fix_type
            ORDER BY sample_size DESC
            LIMIT ?
            """,
            (failure_type, limit),
        )
        return [dict(row) for row in cursor.fetchall()]

    def _row_to_dict(self, row) -> Optional[Dict[str, Any]]:
        if row is None:
            return None
        d = dict(row)
        for field in ("evidence", "recommended_fix", "before_metrics", "after_metrics"):
            if d.get(field) and isinstance(d[field], str):
                try:
                    d[field] = json.loads(d[field])
                except (json.JSONDecodeError, TypeError):
                    pass
        if isinstance(d.get("fix_applied"), int):
            d["fix_applied"] = bool(d["fix_applied"])
        return d

    def close(self):
        if self.connection:
            self.connection.close()

    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.close()
