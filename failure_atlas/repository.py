import json
import os
import sqlite3
import uuid
from datetime import datetime, timezone
from pathlib import Path
from typing import Optional, List, Dict, Any

from gli_flow.database.migrations import migrate_if_needed, MigrationEngine, FAILURE_ATLAS_MIGRATIONS


REQUIRED_FIELDS = [
    "id", "run_id", "failure_id", "failure_type", "severity",
    "title", "description", "recommended_fix", "confidence",
    "signature", "detected_at", "domain", "category",
]

RESOLUTION_FIELDS = [
    "fix_applied", "fix_type", "fix_description", "fix_run_id",
    "before_metrics", "after_metrics", "resolution_confidence",
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

        migrate_if_needed(self.db_path)
        self.connection = sqlite3.connect(self.db_path)
        self.connection.row_factory = sqlite3.Row
        self.connection.execute("PRAGMA journal_mode=WAL")

    def _raw_execute(self, sql: str, params=None):
        cursor = self.connection.cursor()
        if params:
            cursor.execute(sql, params)
        else:
            cursor.execute(sql)
        return cursor

    def _fetchone(self, sql: str, params=None) -> Optional[Dict[str, Any]]:
        cursor = self._raw_execute(sql, params)
        row = cursor.fetchone()
        if row is None:
            return None
        return dict(row)

    def _fetchall(self, sql: str, params=None) -> List[Dict[str, Any]]:
        cursor = self._raw_execute(sql, params)
        return [dict(row) for row in cursor.fetchall()]

    def _execute(self, sql: str, params=None):
        self._raw_execute(sql, params)
        self.connection.commit()

    def insert_entry(self, entry: Dict[str, Any]) -> str:
        entry.setdefault("id", str(uuid.uuid4()))
        entry.setdefault("failure_id", entry["id"])
        entry.setdefault("detected_at", datetime.now(timezone.utc).isoformat())
        entry.setdefault("created_at", datetime.now(timezone.utc).isoformat())
        entry.setdefault("confidence", 0.8)

        self._execute(
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
                entry["id"],
                entry.get("run_id", ""),
                entry.get("failure_id", entry["id"]),
                entry.get("failure_type", "UNKNOWN"),
                entry.get("severity", "MEDIUM"),
                entry.get("title", ""),
                entry.get("description", ""),
                json.dumps(rf) if not isinstance(rf := entry.get("recommended_fix", ""), str) else rf,
                entry.get("confidence", 0.8),
                entry.get("signature", ""),
                entry.get("domain", ""),
                entry.get("category", ""),
                json.dumps(entry.get("evidence", {})),
                entry.get("detected_at"),
                entry.get("created_at"),
                entry.get("parent_run_id"),
                1 if entry.get("fix_applied") else 0,
                entry.get("fix_type", ""),
                entry.get("fix_description", ""),
                entry.get("fix_run_id", ""),
                json.dumps(entry.get("before_metrics", {})),
                json.dumps(entry.get("after_metrics", {})),
                entry.get("resolution_confidence", ""),
            ),
        )
        return entry["id"]

    def get_entries_for_run(self, run_id: str) -> List[Dict[str, Any]]:
        return self._fetchall(
            "SELECT * FROM failure_atlas_entries WHERE run_id = ? ORDER BY detected_at DESC",
            (run_id,),
        )

    def search_entries(self, failure_type: Optional[str] = None, severity: Optional[str] = None,
                       domain: Optional[str] = None, limit: int = 50) -> List[Dict[str, Any]]:
        query = "SELECT * FROM failure_atlas_entries WHERE 1=1"
        params = []
        if failure_type:
            query += " AND failure_type = ?"
            params.append(failure_type)
        if severity:
            query += " AND severity = ?"
            params.append(severity)
        if domain:
            query += " AND domain = ?"
            params.append(domain)
        query += " ORDER BY detected_at DESC LIMIT ?"
        params.append(limit)
        return self._fetchall(query, params)

    def get_entry(self, entry_id: str) -> Optional[Dict[str, Any]]:
        return self._fetchone(
            "SELECT * FROM failure_atlas_entries WHERE id = ?",
            (entry_id,),
        )

    def count_entries(self, failure_type: Optional[str] = None) -> int:
        query = "SELECT COUNT(*) FROM failure_atlas_entries WHERE 1=1"
        params = []
        if failure_type:
            query += " AND failure_type = ?"
            params.append(failure_type)
        cursor = self._raw_execute(query, params)
        return cursor.fetchone()[0]

    def update_resolution(self, entry_id: str, resolution: Dict[str, Any]):
        self._execute(
            """
            UPDATE failure_atlas_entries SET
                fix_applied = ?,
                fix_type = ?,
                fix_description = ?,
                fix_run_id = ?,
                before_metrics = ?,
                after_metrics = ?,
                resolution_confidence = ?
            WHERE id = ?
            """,
            (
                1 if resolution.get("fix_applied") else 0,
                resolution.get("fix_type", ""),
                resolution.get("fix_description", ""),
                resolution.get("fix_run_id", ""),
                json.dumps(resolution.get("before_metrics", {})),
                json.dumps(resolution.get("after_metrics", {})),
                resolution.get("resolution_confidence", ""),
                entry_id,
            ),
        )

    def get_statistics(self) -> Dict[str, Any]:
        try:
            total = self._fetchone("SELECT COUNT(*) as cnt FROM failure_atlas_entries")["cnt"]
        except Exception:
            total = 0
        try:
            fixed = self._fetchone("SELECT COUNT(*) as cnt FROM failure_atlas_entries WHERE fix_applied = 1")["cnt"]
        except Exception:
            fixed = 0
        return {"total_entries": total, "fixed_entries": fixed, "fix_rate": round(fixed / total * 100, 1) if total else 0.0}

    def get_top_failures(self, limit: int = 20) -> List[Dict[str, Any]]:
        try:
            return self._fetchall(
                """
                SELECT failure_type, severity, COUNT(*) as occurrences,
                       ROUND(CAST(COUNT(*) AS FLOAT) / (SELECT COUNT(*) FROM failure_atlas_entries) * 100, 1) as percentage
                FROM failure_atlas_entries
                GROUP BY failure_type, severity
                ORDER BY occurrences DESC LIMIT ?
                """,
                (limit,),
            )
        except Exception:
            return []

    def get_domain_summary(self) -> List[Dict[str, Any]]:
        try:
            return self._fetchall(
                """
                SELECT domain, COUNT(*) as occurrences,
                       ROUND(CAST(COUNT(*) AS FLOAT) / (SELECT COUNT(*) FROM failure_atlas_entries) * 100, 1) as percentage
                FROM failure_atlas_entries
                GROUP BY domain ORDER BY occurrences DESC
                """,
            )
        except Exception:
            return []

    def get_resolution_rate_by_type(self) -> List[Dict[str, Any]]:
        try:
            return self._fetchall(
                """
                SELECT failure_type,
                       COUNT(*) as total,
                       SUM(CASE WHEN fix_applied = 1 THEN 1 ELSE 0 END) as fixed,
                       ROUND(CAST(SUM(CASE WHEN fix_applied = 1 THEN 1 ELSE 0 END) AS FLOAT) / COUNT(*) * 100, 1) as fix_rate
                FROM failure_atlas_entries
                GROUP BY failure_type ORDER BY total DESC
                """,
            )
        except Exception:
            return []

    def get_severity_distribution(self) -> List[Dict[str, Any]]:
        try:
            return self._fetchall(
                """
                SELECT severity, COUNT(*) as occurrences,
                       ROUND(CAST(COUNT(*) AS FLOAT) / (SELECT COUNT(*) FROM failure_atlas_entries) * 100, 1) as percentage
                FROM failure_atlas_entries
                GROUP BY severity ORDER BY occurrences DESC
                """,
            )
        except Exception:
            return []

    def get_related_entries(self, entry_id: str) -> List[Dict[str, Any]]:
        entry = self.get_entry(entry_id)
        if not entry:
            return []
        try:
            return self._fetchall(
                """
                SELECT * FROM failure_atlas_entries
                WHERE (failure_type = ? OR domain = ?) AND id != ?
                ORDER BY detected_at DESC LIMIT 5
                """,
                (entry.get("failure_type", ""), entry.get("domain", ""), entry_id),
            )
        except Exception:
            return []

    def resolve_entries_for_run(self, run_id: str, resolution: Dict[str, Any]):
        entries = self.get_entries_for_run(run_id)
        for entry in entries:
            self.update_resolution(entry["id"], resolution)

    def close(self):
        if self.connection:
            self.connection.close()
