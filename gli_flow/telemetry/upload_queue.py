import json
import os
import sqlite3
from datetime import datetime, timezone
from pathlib import Path
from typing import Optional


QUEUE_DB_DIR = Path.home() / ".gli-flow"
QUEUE_DB_PATH = QUEUE_DB_DIR / "upload_queue.db"

QUEUE_TABLE_SQL = """
CREATE TABLE IF NOT EXISTS upload_queue (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    destination TEXT NOT NULL,
    payload TEXT NOT NULL,
    status TEXT NOT NULL DEFAULT 'pending',
    created_at TEXT NOT NULL,
    next_retry_at TEXT,
    retry_count INTEGER DEFAULT 0,
    error_message TEXT,
    run_id TEXT
);
CREATE INDEX IF NOT EXISTS idx_uq_status ON upload_queue(status);
CREATE INDEX IF NOT EXISTS idx_uq_next_retry ON upload_queue(next_retry_at);
CREATE INDEX IF NOT EXISTS idx_uq_run_id ON upload_queue(run_id);
"""


class UploadQueue:
    def __init__(self, db_path: Optional[str] = None):
        self.db_path = db_path or str(QUEUE_DB_PATH)
        os.makedirs(str(QUEUE_DB_DIR), exist_ok=True)
        self._ensure_table()

    def _ensure_table(self):
        conn = sqlite3.connect(self.db_path)
        try:
            conn.executescript(QUEUE_TABLE_SQL)
        finally:
            conn.close()

    def _get_connection(self) -> sqlite3.Connection:
        conn = sqlite3.connect(self.db_path)
        conn.row_factory = sqlite3.Row
        return conn

    def enqueue(self, destination: str, payload: dict,
                run_id: str = "", status: str = "pending") -> int:
        conn = self._get_connection()
        try:
            now = datetime.now(timezone.utc).isoformat()
            cur = conn.execute(
                """INSERT INTO upload_queue
                   (destination, payload, status, created_at, run_id)
                   VALUES (?, ?, ?, ?, ?)""",
                (destination, json.dumps(payload, default=str), status, now, run_id),
            )
            conn.commit()
            return cur.lastrowid or 0
        finally:
            conn.close()

    def dequeue(self, limit: int = 10) -> list[dict]:
        conn = self._get_connection()
        try:
            now = datetime.now(timezone.utc).isoformat()
            rows = conn.execute(
                """SELECT * FROM upload_queue
                   WHERE status = 'pending'
                      OR (status = 'failed' AND next_retry_at IS NOT NULL AND next_retry_at <= ?)
                   ORDER BY created_at ASC
                   LIMIT ?""",
                (now, limit),
            ).fetchall()
            ids = [r["id"] for r in rows]
            if ids:
                placeholders = ",".join("?" for _ in ids)
                conn.execute(
                    f"UPDATE upload_queue SET status = 'in_progress' WHERE id IN ({placeholders})",
                    ids,
                )
                conn.commit()
            return [dict(r) for r in rows]
        finally:
            conn.close()

    def mark_completed(self, item_id: int):
        conn = self._get_connection()
        try:
            conn.execute(
                "UPDATE upload_queue SET status = 'completed' WHERE id = ?",
                (item_id,),
            )
            conn.commit()
        finally:
            conn.close()

    def mark_failed(self, item_id: int, error_message: str = "",
                    next_retry_at: Optional[str] = None):
        conn = self._get_connection()
        try:
            item = conn.execute(
                "SELECT retry_count FROM upload_queue WHERE id = ?", (item_id,)
            ).fetchone()
            retry_count = (item["retry_count"] if item else 0) + 1
            conn.execute(
                """UPDATE upload_queue
                   SET status = 'failed', retry_count = ?, error_message = ?, next_retry_at = ?
                   WHERE id = ?""",
                (retry_count, error_message[:500], next_retry_at, item_id),
            )
            conn.commit()
        finally:
            conn.close()

    def flush_completed(self, older_than_hours: int = 24):
        conn = self._get_connection()
        try:
            from datetime import timedelta
            cutoff = (datetime.now(timezone.utc) - timedelta(hours=older_than_hours)).isoformat()
            conn.execute(
                "DELETE FROM upload_queue WHERE status = 'completed' AND created_at < ?",
                (cutoff,),
            )
            conn.commit()
        finally:
            conn.close()

    def get_pending_count(self) -> int:
        conn = self._get_connection()
        try:
            row = conn.execute(
                "SELECT COUNT(*) FROM upload_queue WHERE status IN ('pending', 'failed', 'in_progress')"
            ).fetchone()
            return row[0] if row else 0
        finally:
            conn.close()

    def get_queue_stats(self) -> dict:
        conn = self._get_connection()
        try:
            total = conn.execute("SELECT COUNT(*) FROM upload_queue").fetchone()[0]
            by_status = dict(
                conn.execute(
                    "SELECT status, COUNT(*) FROM upload_queue GROUP BY status"
                ).fetchall()
            )
            by_destination = dict(
                conn.execute(
                    "SELECT destination, COUNT(*) FROM upload_queue GROUP BY destination"
                ).fetchall()
            )
            return {
                "total": total,
                "by_status": by_status,
                "by_destination": by_destination,
            }
        finally:
            conn.close()
