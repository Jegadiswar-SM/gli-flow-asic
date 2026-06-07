import os
import shutil
import sqlite3
from abc import ABC, abstractmethod
from dataclasses import dataclass, field
from pathlib import Path
from typing import Optional

from gli_flow.database.migrations import MigrationEngine, RUNS_MIGRATIONS, FAILURE_ATLAS_MIGRATIONS, _get_db_path
from gli_flow.installer.tool_detector import detect_netgen_lib_dir, detect_netgenexec


@dataclass
class RepairActionResult:
    action: str
    success: bool
    detail: str = ""
    requires_restart: bool = False


class RepairAction(ABC):
    @abstractmethod
    def detect(self) -> bool:
        pass

    @abstractmethod
    def repair(self) -> RepairActionResult:
        pass

    @abstractmethod
    def verify(self) -> bool:
        pass


class SchemaMigrationRepair(RepairAction):
    def __init__(self, db_path: Optional[str] = None):
        self.db_path = db_path or _get_db_path()
        self._needs_repair = False

    def detect(self) -> bool:
        engine = MigrationEngine(self.db_path)
        try:
            runs_ok = engine.validate_schema("runs", RUNS_MIGRATIONS)
            fa_ok = engine.validate_schema("failure_atlas", FAILURE_ATLAS_MIGRATIONS)
            self._needs_repair = not (runs_ok and fa_ok)
            return self._needs_repair
        finally:
            engine.close()

    def repair(self) -> RepairActionResult:
        engine = MigrationEngine(self.db_path)
        try:
            for source, migrations in [("runs", RUNS_MIGRATIONS), ("failure_atlas", FAILURE_ATLAS_MIGRATIONS)]:
                state = engine.repair(source, migrations)
                if not state.ok:
                    state = engine.migrate(source, migrations)
                if not state.ok:
                    return RepairActionResult("schema-migration", False,
                        f"Failed for {source}: {state.error}")
            return RepairActionResult("schema-migration", True,
                "All schema migrations applied successfully")
        finally:
            engine.close()

    def verify(self) -> bool:
        engine = MigrationEngine(self.db_path)
        try:
            return engine.validate_schema("runs", RUNS_MIGRATIONS) and engine.validate_schema("failure_atlas", FAILURE_ATLAS_MIGRATIONS)
        finally:
            engine.close()


class NetgenLibPathRepair(RepairAction):
    def __init__(self):
        self._needs_repair = False

    def detect(self) -> bool:
        self._needs_repair = detect_netgen_lib_dir() is None
        return self._needs_repair

    def repair(self) -> RepairActionResult:
        candidates = [
            "/usr/lib/netgen",
            "/usr/local/lib/netgen",
        ]
        for d in candidates:
            p = Path(d)
            if p.is_dir():
                for f in p.iterdir():
                    if "tclnetgen" in f.name and f.suffix in (".so", ".dylib"):
                        if d not in (os.environ.get("LD_LIBRARY_PATH", "")):
                            return RepairActionResult("netgen-lib-path", False,
                                f"Found at {d} but not in LD_LIBRARY_PATH. "
                                f"Add: export LD_LIBRARY_PATH={d}:$LD_LIBRARY_PATH",
                                requires_restart=True)
        return RepairActionResult("netgen-lib-path", False,
            "tclnetgen.so not found. Reinstall netgen: gli-flow install --force")

    def verify(self) -> bool:
        return detect_netgen_lib_dir() is not None


class PathRepair(RepairAction):
    def __init__(self, tool_name: str, expected_paths: Optional[list[str]] = None):
        self.tool_name = tool_name
        self.expected_paths = expected_paths or [
            str(Path.home() / ".local" / "bin"),
            str(Path.home() / ".gli-flow" / "tools" / "bin"),
        ]

    def detect(self) -> bool:
        return shutil.which(self.tool_name) is None

    def repair(self) -> RepairActionResult:
        found = False
        for p in self.expected_paths:
            candidate = Path(p) / self.tool_name
            if candidate.exists() and os.access(str(candidate), os.X_OK):
                found = True
                break
        if found:
            return RepairActionResult(f"path-{self.tool_name}", True,
                f"Found at {candidate}. Ensure {candidate.parent} is in your PATH",
                requires_restart=True)
        return RepairActionResult(f"path-{self.tool_name}", False,
            f"Not found. Install with: gli-flow install")

    def verify(self) -> bool:
        return shutil.which(self.tool_name) is not None


class CacheRepair(RepairAction):
    def __init__(self, cache_dirs: Optional[list[str]] = None):
        self.cache_dirs = cache_dirs or [
            str(Path.home() / ".cache" / "gli-flow"),
            str(Path.home() / ".gli-flow"),
        ]

    def detect(self) -> bool:
        return True

    def repair(self) -> RepairActionResult:
        cleaned = []
        failed = []
        for d in self.cache_dirs:
            p = Path(d)
            if p.is_dir():
                try:
                    for f in p.rglob("__pycache__"):
                        shutil.rmtree(str(f), ignore_errors=True)
                    cleaned.append(d)
                except Exception as e:
                    failed.append(f"{d}: {e}")
        if cleaned and not failed:
            return RepairActionResult("cache-clean", True,
                f"Cleaned caches in: {', '.join(cleaned)}")
        elif cleaned:
            return RepairActionResult("cache-clean", True,
                f"Partial: cleaned {', '.join(cleaned)}; failed: {', '.join(failed)}")
        return RepairActionResult("cache-clean", True,
            "No caches found to clean")

    def verify(self) -> bool:
        return True


REPAIR_REGISTRY: list[type[RepairAction]] = [
    SchemaMigrationRepair,
    NetgenLibPathRepair,
    CacheRepair,
]


def get_repair_actions(db_path: Optional[str] = None) -> list[RepairAction]:
    actions: list[RepairAction] = []
    for cls in REPAIR_REGISTRY:
        try:
            if cls == SchemaMigrationRepair:
                actions.append(cls(db_path=db_path))
            else:
                actions.append(cls())
        except Exception:
            pass
    for tool in ["magic", "netgen", "yosys", "openroad", "klayout"]:
        actions.append(PathRepair(tool))
    return actions


def run_repairs(db_path: Optional[str] = None) -> list[RepairActionResult]:
    results: list[RepairActionResult] = []
    for action in get_repair_actions(db_path):
        try:
            if action.detect():
                result = action.repair()
                if result.success:
                    verified = action.verify()
                    if not verified:
                        result = RepairActionResult(result.action, False,
                            f"Repair applied but verification failed: {result.detail}")
                results.append(result)
            else:
                results.append(RepairActionResult(
                    type(action).__name__, True, "No repair needed"))
        except Exception as e:
            results.append(RepairActionResult(
                type(action).__name__, False, str(e)))
    return results
