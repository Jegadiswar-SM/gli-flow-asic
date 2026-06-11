import os
import sqlite3
from dataclasses import dataclass, field
from pathlib import Path
from typing import Optional


SCHEMA_VERSION_TABLE = """
CREATE TABLE IF NOT EXISTS schema_version (
    source TEXT NOT NULL,
    version INTEGER NOT NULL,
    applied_at TEXT DEFAULT (datetime('now')),
    description TEXT,
    PRIMARY KEY (source, version)
)
"""


@dataclass
class Migration:
    version: int
    description: str
    sql: str


@dataclass
class MigrationState:
    current_version: int = 0
    pending: list[Migration] = field(default_factory=list)
    applied: list[Migration] = field(default_factory=list)
    error: Optional[str] = None
    ok: bool = True


RUNS_MIGRATIONS = [
    Migration(1, "initial runs table", """
        CREATE TABLE IF NOT EXISTS runs (
            run_id TEXT PRIMARY KEY,
            design_name TEXT NOT NULL,
            status TEXT DEFAULT 'PENDING',
            current_stage TEXT DEFAULT 'INITIALIZING',
            progress INTEGER DEFAULT 0,
            wns REAL DEFAULT NULL,
            tns REAL DEFAULT NULL,
            hold_wns REAL DEFAULT NULL,
            hold_tns REAL DEFAULT NULL,
            utilization REAL DEFAULT NULL,
            runtime_sec REAL DEFAULT NULL,
            cell_count INTEGER DEFAULT NULL,
            qor_score REAL DEFAULT NULL,
            timestamp TEXT DEFAULT (datetime('now')),
            run_dir TEXT DEFAULT NULL,
            regression INTEGER DEFAULT 0,
            drc_violations INTEGER DEFAULT NULL,
            drc_magic_violations INTEGER DEFAULT NULL,
            drc_klayout_violations INTEGER DEFAULT NULL,
            drc_is_clean INTEGER DEFAULT 0,
            lvs_result TEXT DEFAULT NULL,
            lvs_is_clean INTEGER DEFAULT 0,
            setup_wns_ns REAL DEFAULT NULL,
            hold_whs_ns REAL DEFAULT NULL,
            signoff_setup_pass INTEGER DEFAULT 0,
            signoff_hold_pass INTEGER DEFAULT 0,
            signoff_gate_json TEXT DEFAULT NULL,
            tapeout_ready INTEGER DEFAULT 0
        )
    """),
    Migration(2, "add created_at to runs", """
        ALTER TABLE runs ADD COLUMN created_at TEXT DEFAULT NULL
    """),
    Migration(3, "add updated_at to runs", """
        ALTER TABLE runs ADD COLUMN updated_at TEXT DEFAULT NULL
    """),
    Migration(4, "add tags to runs", """
        ALTER TABLE runs ADD COLUMN tags TEXT DEFAULT NULL
    """),
    Migration(5, "add important columns to runs", """
        ALTER TABLE runs ADD COLUMN is_important INTEGER DEFAULT 0;
        ALTER TABLE runs ADD COLUMN important_marked_at TEXT DEFAULT NULL;
        ALTER TABLE runs ADD COLUMN important_source TEXT DEFAULT NULL
    """),
]

FAILURE_ATLAS_MIGRATIONS = [
    Migration(1, "initial failure_atlas_entries table", """
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
            resolution_confidence TEXT
        )
    """),
    Migration(2, "add parent_run_id to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN parent_run_id TEXT DEFAULT NULL
    """),
    Migration(3, "add before_metrics to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN before_metrics TEXT DEFAULT NULL
    """),
    Migration(4, "add after_metrics to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN after_metrics TEXT DEFAULT NULL
    """),
    Migration(5, "add resolution_confidence to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN resolution_confidence TEXT DEFAULT NULL
    """),
    Migration(6, "add created_at to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN created_at TEXT DEFAULT (datetime('now'))
    """),
    Migration(7, "add entry_level to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN entry_level TEXT DEFAULT 'FAILURE'
    """),
    Migration(8, "add failure_hash to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN failure_hash TEXT DEFAULT NULL
    """),
    Migration(9, "add tool_name to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN tool_name TEXT DEFAULT NULL
    """),
    Migration(10, "add tool_version to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN tool_version TEXT DEFAULT NULL
    """),
    Migration(11, "add tool_stage to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN tool_stage TEXT DEFAULT NULL
    """),
    Migration(12, "add first_seen to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN first_seen TEXT DEFAULT NULL
    """),
    Migration(13, "add last_seen to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN last_seen TEXT DEFAULT NULL
    """),
    Migration(14, "add occurrence_count to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN occurrence_count INTEGER DEFAULT 1
    """),
    Migration(15, "add environment_fingerprint to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN environment_fingerprint TEXT DEFAULT NULL
    """),
    Migration(16, "add resolution_attempts to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN resolution_attempts INTEGER DEFAULT 0
    """),
    Migration(17, "add resolution_success_rate to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN resolution_success_rate REAL DEFAULT 0.0
    """),
    Migration(18, "add regression_detected to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN regression_detected INTEGER DEFAULT 0
    """),
    Migration(19, "add artifact_snapshot to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN artifact_snapshot TEXT DEFAULT NULL
    """),
    Migration(20, "add execution_snapshot to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN execution_snapshot TEXT DEFAULT NULL
    """),
    Migration(21, "add timing_snapshot to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN timing_snapshot TEXT DEFAULT NULL
    """),
    Migration(22, "add utilization_snapshot to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN utilization_snapshot TEXT DEFAULT NULL
    """),
    Migration(23, "add congestion_snapshot to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN congestion_snapshot TEXT DEFAULT NULL
    """),
    Migration(24, "add runtime_snapshot to failure_atlas_entries", """
        ALTER TABLE failure_atlas_entries ADD COLUMN runtime_snapshot TEXT DEFAULT NULL
    """),
    Migration(25, "deduplicate cross-tool DRC disagreements and add uniqueness constraint", """
        DELETE FROM failure_atlas_entries
        WHERE rowid NOT IN (
            SELECT MIN(rowid) FROM failure_atlas_entries
            WHERE failure_type = 'CROSS_TOOL_DRC_DISAGREEMENT'
            GROUP BY run_id, failure_type, signature
        );
        CREATE UNIQUE INDEX IF NOT EXISTS idx_fa_unique_run_type_sig
        ON failure_atlas_entries(run_id, failure_type, signature);
    """),
]


EXPECTED_COLUMNS = {
    "runs": {
        "run_id", "design_name", "status", "current_stage", "progress",
        "wns", "tns", "hold_wns", "hold_tns", "utilization",
        "runtime_sec", "cell_count", "qor_score", "timestamp", "run_dir",
        "regression", "drc_violations", "drc_magic_violations",
        "drc_klayout_violations", "drc_is_clean", "lvs_result",
        "lvs_is_clean", "setup_wns_ns", "hold_whs_ns",
        "signoff_setup_pass", "signoff_hold_pass", "signoff_gate_json",
        "tapeout_ready", "created_at", "updated_at", "tags",
        "is_important", "important_marked_at", "important_source"
    },
    "failure_atlas_entries": {
        "id", "run_id", "failure_id", "failure_type", "severity", "title",
        "description", "recommended_fix", "confidence", "signature",
        "domain", "category", "evidence", "detected_at", "created_at",
        "parent_run_id", "fix_applied", "fix_type", "fix_description",
        "fix_run_id", "before_metrics", "after_metrics",
        "resolution_confidence", "entry_level",
    },
}


def _get_db_path() -> str:
    db_path = os.environ.get("GLI_FLOW_DB")
    if db_path:
        return db_path
    db_path = os.environ.get("GLI_FLOW_DB_PATH")
    if db_path:
        return db_path
    db_dir = Path.home() / ".gli_flow"
    try:
        db_dir.mkdir(parents=True, exist_ok=True)
        probe = db_dir / ".write_test"
        probe.write_text("")
        probe.unlink(missing_ok=True)
        return str(db_dir / "gli_flow.db")
    except OSError:
        return str(Path.cwd() / "gli_flow.db")


_SOURCES = {"runs", "failure_atlas"}


def _ensure_schema_version_table(conn: sqlite3.Connection):
    old_exists = conn.execute(
        "SELECT name FROM sqlite_master WHERE type='table' AND name='schema_version'"
    ).fetchone()
    has_source = False
    if old_exists:
        try:
            conn.execute("SELECT source FROM schema_version LIMIT 1")
            has_source = True
        except sqlite3.OperationalError:
            pass

    if not has_source and old_exists:
        conn.execute("CREATE TABLE IF NOT EXISTS schema_version_old (version INTEGER PRIMARY KEY, applied_at TEXT, description TEXT)")
        conn.execute("INSERT OR IGNORE INTO schema_version_old SELECT version, applied_at, description FROM schema_version")
        conn.execute("DROP TABLE IF EXISTS schema_version")
        conn.execute(SCHEMA_VERSION_TABLE)
        try:
            rows = conn.execute("SELECT description, version FROM schema_version_old").fetchall()
            for desc, ver in rows:
                if "failure_atlas" in (desc or "").lower():
                    src = "failure_atlas"
                elif "runs" in (desc or "").lower():
                    src = "runs"
                else:
                    src = "migrated"
                conn.execute(
                    "INSERT OR IGNORE INTO schema_version (source, version, description) VALUES (?, ?, ?)",
                    (src, ver, desc),
                )
        except sqlite3.OperationalError:
            pass
        conn.commit()
    elif not old_exists:
        conn.execute(SCHEMA_VERSION_TABLE)
        conn.commit()


def _current_version(conn: sqlite3.Connection, source: str) -> int:
    cursor = conn.execute(
        "SELECT COALESCE(MAX(version), 0) FROM schema_version WHERE source = ?",
        (source,),
    )
    return cursor.fetchone()[0]


class MigrationEngine:
    def __init__(self, db_path: Optional[str] = None):
        self.db_path = db_path or _get_db_path()
        self.conn = sqlite3.connect(self.db_path)
        try:
            self.conn.execute("PRAGMA journal_mode=WAL")
        except sqlite3.OperationalError:
            self.conn.close()
            self.conn = sqlite3.connect(self.db_path)
        _ensure_schema_version_table(self.conn)

    def close(self):
        self.conn.close()

    def state(self, source: str, migrations: list[Migration]) -> MigrationState:
        current = _current_version(self.conn, source)
        state = MigrationState(current_version=current)
        for m in migrations:
            if m.version <= current:
                state.applied.append(m)
            else:
                state.pending.append(m)
        return state

    def migrate(self, source: str, migrations: list[Migration], target: Optional[int] = None) -> MigrationState:
        state = self.state(source, migrations)
        if state.error:
            return state
        for m in state.pending:
            if target is not None and m.version > target:
                break
            try:
                # Handle semicolon-separated statements by splitting them
                for statement in m.sql.split(';'):
                    if statement.strip():
                        self.conn.execute(statement)
                self.conn.execute(
                    "INSERT INTO schema_version (source, version, description) VALUES (?, ?, ?)",
                    (source, m.version, m.description),
                )
                self.conn.commit()
                state.applied.append(m)
            except sqlite3.OperationalError as e:
                if "duplicate column" in str(e).lower() or "already exists" in str(e).lower():
                    self.conn.execute(
                        "INSERT OR IGNORE INTO schema_version (source, version, description) VALUES (?, ?, ?)",
                        (source, m.version, m.description),
                    )
                    self.conn.commit()
                    state.applied.append(m)
                    continue
                state.error = f"Migration {m.version} ({m.description}) failed: {e}"
                state.ok = False
                return state
        state.pending = [m for m in migrations if m.version > _current_version(self.conn, source)]
        state.current_version = _current_version(self.conn, source)
        return state

    def repair(self, source: str, migrations: list[Migration]) -> MigrationState:
        for m in migrations:
            try:
                self.conn.execute(
                    "INSERT OR IGNORE INTO schema_version (source, version, description) VALUES (?, ?, ?)",
                    (source, m.version, m.description),
                )
            except sqlite3.OperationalError:
                pass
        self.conn.commit()
        return self.state(source, migrations)

    def validate_schema(self, source: str, migrations: list[Migration]) -> bool:
        state = self.state(source, migrations)
        if state.error:
            return False
        return len(state.pending) == 0

    def validate_runtime_schema(self) -> tuple[bool, list[str]]:
        errors = []
        for table, expected in EXPECTED_COLUMNS.items():
            try:
                rows = self.conn.execute(f"PRAGMA table_info({table})").fetchall()
            except sqlite3.OperationalError as e:
                errors.append(f"{table}: {e}")
                continue
            actual = {row[1] for row in rows}
            missing = sorted(expected - actual)
            if missing:
                errors.append(f"{table}: missing columns {', '.join(missing)}")
        return (len(errors) == 0, errors)


MIGRATION_SOURCES = {
    "runs": RUNS_MIGRATIONS,
    "failure_atlas": FAILURE_ATLAS_MIGRATIONS,
}


def migrate_if_needed(db_path: Optional[str] = None) -> None:
    engine = MigrationEngine(db_path)
    try:
        for source, migrations in MIGRATION_SOURCES.items():
            state = engine.migrate(source, migrations)
            if not state.ok:
                raise RuntimeError(f"Schema migration failed for {source}: {state.error}")
        ok, errors = engine.validate_runtime_schema()
        if not ok:
            raise RuntimeError("Schema validation failed: " + "; ".join(errors))
    finally:
        engine.close()
