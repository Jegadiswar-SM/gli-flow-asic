import hashlib
import json
import sqlite3
from datetime import datetime, timezone
from typing import Optional


AUDIT_TABLE_SQL = """
CREATE TABLE IF NOT EXISTS telemetry_audit_log (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    event_type TEXT NOT NULL,
    event_name TEXT DEFAULT '',
    status TEXT NOT NULL,
    reason TEXT DEFAULT '',
    payload_hash TEXT DEFAULT '',
    recorded_at TEXT NOT NULL
);
CREATE INDEX IF NOT EXISTS idx_tal_event_type ON telemetry_audit_log(event_type);
CREATE INDEX IF NOT EXISTS idx_tal_status ON telemetry_audit_log(status);
CREATE INDEX IF NOT EXISTS idx_tal_recorded ON telemetry_audit_log(recorded_at);
"""


class TelemetryAuditLog:
    EVENT_CREATED = "event_created"
    EVENT_SANITIZED = "event_sanitized"
    EVENT_UPLOADED = "event_uploaded"
    EVENT_REJECTED = "event_rejected"
    EVENT_EXPORTED = "event_exported"
    EVENT_REPLAYED = "event_replayed"

    def __init__(self, db_path: Optional[str] = None):
        if db_path:
            self.db_path = db_path
        else:
            from gli_flow.database.migrations import _get_db_path
            self.db_path = _get_db_path()
        self._ensure_table()

    def _ensure_table(self):
        conn = sqlite3.connect(self.db_path)
        try:
            conn.executescript(AUDIT_TABLE_SQL)
        finally:
            conn.close()

    def _get_connection(self):
        conn = sqlite3.connect(self.db_path)
        conn.row_factory = sqlite3.Row
        return conn

    def record(self, event_type: str, event_name: str = "",
               status: str = "success", reason: str = "",
               payload: Optional[dict] = None):
        payload_hash = ""
        if payload:
            payload_hash = hashlib.sha256(
                json.dumps(payload, sort_keys=True, default=str).encode()
            ).hexdigest()[:16]
        conn = self._get_connection()
        try:
            conn.execute(
                """INSERT INTO telemetry_audit_log
                   (event_type, event_name, status, reason, payload_hash, recorded_at)
                   VALUES (?, ?, ?, ?, ?, ?)""",
                (event_type, event_name, status, reason, payload_hash,
                 datetime.now(timezone.utc).isoformat()),
            )
            conn.commit()
        finally:
            conn.close()

    def get_logs(self, limit: int = 100, offset: int = 0,
                 event_type: Optional[str] = None) -> list[dict]:
        conn = self._get_connection()
        try:
            if event_type:
                rows = conn.execute(
                    """SELECT * FROM telemetry_audit_log
                       WHERE event_type = ? ORDER BY recorded_at DESC LIMIT ? OFFSET ?""",
                    (event_type, limit, offset),
                ).fetchall()
            else:
                rows = conn.execute(
                    """SELECT * FROM telemetry_audit_log
                       ORDER BY recorded_at DESC LIMIT ? OFFSET ?""",
                    (limit, offset),
                ).fetchall()
            return [dict(r) for r in rows]
        finally:
            conn.close()

    def get_stats(self) -> dict:
        conn = self._get_connection()
        try:
            total = conn.execute("SELECT COUNT(*) FROM telemetry_audit_log").fetchone()[0]
            by_type = dict(
                conn.execute(
                    "SELECT event_type, COUNT(*) FROM telemetry_audit_log GROUP BY event_type"
                ).fetchall()
            )
            rejected = conn.execute(
                "SELECT COUNT(*) FROM telemetry_audit_log WHERE status = 'rejected'"
            ).fetchone()[0]
            return {
                "total_entries": total,
                "by_event_type": by_type,
                "total_rejected": rejected,
            }
        finally:
            conn.close()
