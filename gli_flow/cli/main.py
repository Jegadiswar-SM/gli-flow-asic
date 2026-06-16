import argparse
import os
import re
import shutil
import subprocess
import sys
import time
import traceback
import webbrowser
from pathlib import Path

from gli_flow.core.logging import setup_logging, get_logger
from gli_flow.core.orchestrator import FlowOrchestrator
from gli_flow.core.subprocess_env import safe_env
from gli_flow.database.sqlite import DatabaseManager
from gli_flow.database.migrations import MigrationEngine, RUNS_MIGRATIONS, FAILURE_ATLAS_MIGRATIONS, _get_db_path
from gli_flow.cli.output import (
    console,
    print_banner,
    print_run_header,
    print_stage_progress,
    print_results,
    print_regression,
    print_error,
    print_warning,
    print_run_history,
    print_report,
    print_install_report,
    print_achievement_summary,
    print_first_run_guide,
    print_ai_assistant_header,
    print_ai_response,
    print_ai_diagnose_display,
    print_escalation_header,
    print_escalation_result,
)
from gli_flow.installer import Installer
from gli_flow.scheduler import JobQueue, ResourceSpec
from gli_flow.ci import CIConfig, CIRunner
from gli_flow.scheduler.remote import RemoteWorker, RemoteWorkerConfig
from gli_flow.cloud import CloudStorageConfig, CloudStorageManager, CloudProvider
from gli_flow.config_validator import validate_manifest
from gli_flow.parser.rtl_parser import detect_from_directory, parse_file, scan_directory
from gli_flow.infrastructure.environment_validator import EnvironmentValidator
from gli_flow.infrastructure.repair_actions import run_repairs, repair_path_shadowing
from gli_flow.doctor import DiscoveryReport, run_magic_discovery


EXPERIMENTAL_COMMANDS = {"remote", "cloud", "dashboard", "upgrade-check"}
BROKEN_COMMANDS = set()


class CategorizedHelpFormatter(argparse.HelpFormatter):
    """HelpFormatter that groups subcommands by stability category."""

    def _format_action(self, action):
        if not isinstance(action, argparse._SubParsersAction):
            return super()._format_action(action)

        # Use the same layout as the parent for the header
        help_position = min(self._action_max_length + 2, self._max_help_position)
        help_width = max(self._width - help_position, 11)
        action_width = help_position - self._current_indent - 2
        header = self._format_action_invocation(action)

        parts = [f"  {header}\n"]

        if action.help:
            help_text = self._expand_help(action)
            if help_text:
                help_lines = self._split_lines(help_text, help_width)
                parts.append(f"{' ' * help_position}{help_lines[0]}\n")
                for line in help_lines[1:]:
                    parts.append(f"{' ' * help_position}{line}\n")

        # Group subactions by category
        name_map = {}
        for sa in action._get_subactions():
            name_map[getattr(sa, "dest", "")] = sa

        category_help = {}
        for name, parser in action.choices.items():
            cat = getattr(parser, "_category", "production")
            sa = name_map.get(name)
            if sa:
                category_help.setdefault(cat, []).append(sa)

        for category, title in [
            ("production", "Production Commands (stable, fully tested):"),
            ("experimental", "Experimental Commands (functional, may need setup):"),
        ]:
            subactions = category_help.get(category, [])
            if not subactions:
                continue
            parts.append(f"\n  {title}\n")
            for sa in subactions:
                invocation = self._format_action_invocation(sa)
                help_text = self._expand_help(sa) if sa.help else ""
                padded = f"{' ' * 2}{invocation:<{action_width - 2}}"
                if help_text:
                    help_lines = self._split_lines(help_text, help_width)
                    parts.append(f"{padded}  {help_lines[0]}\n")
                    for line in help_lines[1:]:
                        parts.append(f"{' ' * help_position}{line}\n")
                else:
                    parts.append(f"{padded}\n")

        return self._join_parts(parts)


def _load_config():
    config_path = Path.home() / ".gli-flow" / "config.json"
    if config_path.exists():
        import json
        return json.loads(config_path.read_text())
    return {}


def _save_config(config):
    config_path = Path.home() / ".gli-flow" / "config.json"
    config_path.parent.mkdir(parents=True, exist_ok=True)
    import json
    config_path.write_text(json.dumps(config, indent=2))


def _get_telemetry_setting():
    config = _load_config()
    telemetry = config.get("telemetry", "on")
    return telemetry == "on"


def _ensure_telemetry_consent(non_interactive: bool = False):
    """Ensure user has seen the telemetry wizard."""
    from gli_flow.telemetry.settings import get_telemetry_settings, TelemetryMode
    from gli_flow.telemetry.wizard import run_telemetry_wizard

    settings = get_telemetry_settings()
    if settings.is_wizard_required():
        if non_interactive:
            # Default to LOCAL if non-interactive and consent is required
            settings.mode = TelemetryMode.LOCAL
            settings.consent_given = False
            settings.save()
            return
        run_telemetry_wizard()

def _open_browser(url):
    is_wsl = "microsoft" in os.uname().release.lower() if hasattr(os, "uname") else False
    if is_wsl:
        subprocess.Popen(
            ["cmd.exe", "/c", "start", url],
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
        )
        return
    if os.name == "posix" and not os.environ.get("DISPLAY"):
        return
    webbrowser.open(url)


def _start_dashboard():
    try:
        backend_port = os.environ.get("GLI_FLOW_BACKEND_PORT", "8000")
        dashboard_port = os.environ.get("GLI_FLOW_DASHBOARD_PORT", "5173")
        backend_proc = subprocess.Popen(
            [sys.executable, "-m", "uvicorn", "backend.server:app", "--host", "127.0.0.1", "--port", backend_port],
            cwd=Path(__file__).resolve().parent.parent.parent,
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
            env=safe_env(),
        )
        time.sleep(2)
        dashboard_url = f"http://127.0.0.1:{dashboard_port}"
        if not Path(Path(__file__).resolve().parent.parent.parent / "dashboard" / "dist" / "index.html").exists():
            dashboard_url = f"http://127.0.0.1:{backend_port}"
        _open_browser(dashboard_url)
        console.print(f"[dim]Dashboard: {dashboard_url}[/dim]")
    except Exception:
        pass


def db_command(args):
    from gli_flow.database.migrations import MigrationEngine, RUNS_MIGRATIONS, FAILURE_ATLAS_MIGRATIONS, _get_db_path

    db_path = args.db_path or _get_db_path()
    action = args.db_action

    if action == "status":
        engine = MigrationEngine(db_path)
        try:
            for source, migrations in [("runs", RUNS_MIGRATIONS), ("failure_atlas", FAILURE_ATLAS_MIGRATIONS)]:
                state = engine.state(source, migrations)
                lines = []
                lines.append(f"[bold]{source}[/bold]")
                lines.append(f"  Current version: {state.current_version}")
                if state.applied:
                    lines.append(f"  Applied: {len(state.applied)} migration(s)")
                    for m in state.applied:
                        lines.append(f"    [green]v{m.version}[/green] {m.description}")
                if state.pending:
                    lines.append(f"  [yellow]Pending: {len(state.pending)} migration(s)[/yellow]")
                    for m in state.pending:
                        lines.append(f"    [yellow]v{m.version}[/yellow] {m.description}")
                if not state.pending:
                    lines.append(f"  [green]Schema is up to date[/green]")
                console.print("\n".join(lines))
                console.print()
        finally:
            engine.close()

    elif action == "migrate":
        engine = MigrationEngine(db_path)
        try:
            for source, migrations in [("runs", RUNS_MIGRATIONS), ("failure_atlas", FAILURE_ATLAS_MIGRATIONS)]:
                state = engine.migrate(source, migrations)
                if state.ok:
                    console.print(f"[bold green]{source}:[/bold green] Migrated to v{state.current_version}")
                else:
                    console.print(f"[bold red]{source}:[/bold red] Migration failed: {state.error}")
                    sys.exit(1)
        finally:
            engine.close()

    elif action == "repair":
        engine = MigrationEngine(db_path)
        try:
            for source, migrations in [("runs", RUNS_MIGRATIONS), ("failure_atlas", FAILURE_ATLAS_MIGRATIONS)]:
                state = engine.repair(source, migrations)
                if state.ok:
                    console.print(f"[bold green]{source}:[/bold green] Repaired. Current version: {state.current_version}")
                else:
                    console.print(f"[bold yellow]{source}:[/bold yellow] Warning: {state.error}")
        finally:
            engine.close()

    elif action == "path":
        console.print(f"[bold]Database path:[/bold] {db_path}")
        from pathlib import Path
        p = Path(db_path)
        if p.exists():
            console.print(f"[bold]Size:[/bold] {p.stat().st_size / 1024:.1f} KB")
        else:
            console.print("[yellow]Database file does not exist yet[/yellow]")


def reset_runs_command(args):
    """Permanently delete all run history, telemetry, and execution data."""
    from pathlib import Path
    import json
    import shutil
    from datetime import datetime
    from gli_flow.database.migrations import _get_db_path

    db_path = args.db_path or _get_db_path()
    project_root = Path(__file__).resolve().parent.parent.parent

    stats = {
        "db_records_removed": {"runs": 0, "failure_atlas_entries": 0},
        "run_directories_removed": 0,
        "files_removed": 0,
        "reports_reset": [],
    }

    console.print()
    console.print("[bold red]WARNING[/bold red]")
    console.print()
    console.print("This will permanently delete:")
    console.print("  • Run history")
    console.print("  • Telemetry history")
    console.print("  • Failure Atlas execution records")
    console.print("  • Dashboard history")
    console.print()
    console.print("The following will be [bold green]PRESERVED[/bold green]:")
    console.print("  • Database schema & migrations")
    console.print("  • Failure Atlas signatures & knowledge base")
    console.print("  • PDK & ORFS installations")
    console.print("  • Configuration & settings")
    console.print("  • Design examples")
    console.print("  • Dashboard & backend source code")
    console.print()

    try:
        response = input("Type [bold red]DELETE[/bold red] to continue: ")
    except (EOFError, KeyboardInterrupt):
        console.print("\n[yellow]Reset cancelled.[/yellow]")
        return

    if response.strip() != "DELETE":
        console.print("[yellow]Reset cancelled — you did not type DELETE.[/yellow]")
        return

    console.print()
    console.print("[bold]Proceeding with reset...[/bold]\n")

    # ── Phase 1: Database cleanup ──
    import sqlite3
    try:
        conn = sqlite3.connect(db_path)
        cursor = conn.cursor()
        cursor.execute("SELECT name FROM sqlite_master WHERE type='table'")
        tables = [row[0] for row in cursor.fetchall()]
        for table in ["runs", "failure_atlas_entries"]:
            if table in tables:
                cursor.execute(f"SELECT COUNT(*) FROM \"{table}\"")
                count = cursor.fetchone()[0]
                cursor.execute(f"DELETE FROM \"{table}\"")
                conn.commit()
                stats["db_records_removed"][table] = count
                console.print(f"  [dim]Cleared {count} record(s) from {table}[/dim]")
        conn.close()
    except sqlite3.Error as e:
        console.print(f"  [yellow]Database note: {e}[/yellow]")

    # ── Phase 2: Filesystem cleanup ──

    # 2a: Remove run output directories
    runs_dir = project_root / "outputs" / "runs"
    if runs_dir.exists():
        run_dirs = [d for d in runs_dir.iterdir() if d.is_dir()]
        stats["run_directories_removed"] = len(run_dirs)
        for d in run_dirs:
            shutil.rmtree(d, ignore_errors=True)
            console.print(f"  [dim]Removed run: {d.name}[/dim]", highlight=False)
        # Also remove any files at the top level of outputs/runs/
        for f in runs_dir.iterdir():
            if f.is_file():
                f.unlink()
                stats["files_removed"] += 1

    # 2b: Remove output reports
    reports_dir = project_root / "outputs" / "reports"
    if reports_dir.exists():
        for f in reports_dir.iterdir():
            if f.is_file():
                f.unlink()
                stats["files_removed"] += 1
        console.print("  [dim]Cleared outputs/reports/[/dim]")

    # 2c: Remove root-level generated images
    root_images = [
        "final_all.png", "final_clocks.png", "final_ir_drop.png",
        "final_placement.png", "final_routing.png", "uart_gds.png",
    ]
    for img in root_images:
        p = project_root / img
        if p.exists():
            p.unlink()
            stats["files_removed"] += 1
            console.print(f"  [dim]Removed root image: {img}[/dim]")

    # 2d: Remove execution history manifests
    exec_hist_dir = project_root / "execution_history"
    for f in exec_hist_dir.glob("manifest_*.json"):
        f.unlink()
        stats["files_removed"] += 1
        console.print(f"  [dim]Removed manifest: {f.name}[/dim]")

    # ── Phase 3: Reset aggregated report files ──

    reset_files = {
        "trends/historical_trends.json": [],
        "trends/predictive_report.json": {"prediction_warnings": [], "risk_detected": False},
        "analytics/execution_report.json": {
            "total_runs": 0, "total_detected_failures": 0, "failure_statistics": {}
        },
        "analytics/reliability_report.json": {
            "execution_score": 100, "classification": "STABLE", "detected_failures": 0
        },
        "regression/regression_report.json": {
            "regression_detected": False, "flags": []
        },
        "ppa/metrics_history.json": {"runs": []},
        "execution_history/run_index.json": [],
        "dashboard/health_report.json": {
            "execution_health": {"score": 100, "classification": "STABLE"},
            "telemetry_summary": {"total_runs": 0, "total_detected_failures": 0},
            "governance_state": {"contracts_enforced": True, "reproducibility_enabled": True},
            "regression_state": {"regression_detected": False, "flags": []}
        },
        "provenance/provenance_graph.json": {"nodes": [], "edges": []},
    }

    for rel_path, content in reset_files.items():
        abs_path = project_root / rel_path
        if abs_path.exists():
            abs_path.write_text(json.dumps(content, indent=4))
            stats["reports_reset"].append(rel_path)
            console.print(f"  [dim]Reset: {rel_path}[/dim]")

    # ── Phase 4: Preserve Failure Atlas — remove only run-linked analysis records ──
    atlas_analysis_files = list((project_root / "failure_atlas" / "records").glob("analysis_run_*.json"))
    for f in atlas_analysis_files:
        f.unlink()
        stats["files_removed"] += 1
        console.print(f"  [dim]Removed run-linked analysis: {f.name}[/dim]")

    # ── Summary ──
    total_records = sum(stats["db_records_removed"].values())
    console.print()
    console.print("[bold green]Reset complete.[/bold green]")
    console.print(f"  Database records removed: {total_records}")
    console.print(f"  Run directories removed: {stats['run_directories_removed']}")
    console.print(f"  Files removed: {stats['files_removed']}")
    console.print(f"  Reports/data files reset: {len(stats['reports_reset'])}")
    console.print()

    # ── Generate RESET_EXECUTION_REPORT.md ──
    report_path = project_root / "RESET_EXECUTION_REPORT.md"
    now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    report_content = (
        f"# RESET EXECUTION REPORT\n\n"
        f"**Date:** {now}\n"
        f"**Command:** gli-flow reset-runs\n\n"
        f"## Records Removed\n\n"
        f"| Table | Records |\n"
        f"|-------|--------|\n"
        f"| `runs` | {stats['db_records_removed']['runs']} |\n"
        f"| `failure_atlas_entries` | {stats['db_records_removed']['failure_atlas_entries']} |\n\n"
        f"## Files/Directories Removed\n\n"
        f"| Category | Count |\n"
        f"|----------|-------|\n"
        f"| Run directories | {stats['run_directories_removed']} |\n"
        f"| Individual files | {stats['files_removed']} |\n\n"
        f"## Reports/Data Files Reset to Clean State\n\n"
    )
    for r in stats["reports_reset"]:
        report_content += f"- {r}\n"
    report_content += (
        f"\n## Tables Preserved\n\n"
        f"- `schema_version` (migration tracking)\n"
        f"- `failure_atlas_entries` (table structure preserved, execution records cleared)\n"
        f"- `runs` (table structure preserved, execution records cleared)\n\n"
        f"## Directories Preserved\n\n"
        f"- `failure_atlas/signatures/` — Failure Atlas intelligence\n"
        f"- `failure_atlas/records/` — Knowledge base & resolution data (non-execution records preserved)\n"
        f"- `failure_atlas/knowledge_base.json` — Resolution knowledge\n"
        f"- `failure_atlas/qor_playbook.json` — QoR improvement strategies\n"
        f"- `examples/` — Design examples\n"
        f"- `outputs/examples/` — Example output references\n"
        f"- `~/.gli-flow/pdk/` — PDK installation\n"
        f"- `~/.gli-flow/orfs/` — ORFS installation\n"
        f"- `~/.gli-flow/config.json` — User settings\n"
        f"- `gli_flow/`, `backend/`, `dashboard/` — Source code\n\n"
        f"## Infrastructure Intact\n\n"
        f"- Database schema & migrations\n"
        f"- Failure Atlas signatures & knowledge base\n"
        f"- PDK & ORFS installations\n"
        f"- Configuration & settings\n"
        f"- Design examples\n"
        f"- Dashboard & backend source code\n"
    )
    report_path.write_text(report_content)
    console.print(f"[dim]Report written: {report_path.name}[/dim]")
    console.print()


def dashboard_command(args):
    print_banner()
    backend_port = os.environ.get("GLI_FLOW_BACKEND_PORT", "8000")
    dashboard_port = os.environ.get("GLI_FLOW_DASHBOARD_PORT", "5173")
    dist = Path(__file__).resolve().parent.parent.parent / "dashboard" / "dist"

    backend_proc = subprocess.Popen(
        [sys.executable, "-m", "uvicorn", "backend.server:app", "--host", "127.0.0.1", "--port", backend_port],
        cwd=Path(__file__).resolve().parent.parent.parent,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
        env=safe_env(),
    )

    time.sleep(1.5)

    frontend_proc = None
    if not args.backend_only:
        dashboard_url = f"http://127.0.0.1:{dashboard_port}"
        try:
            frontend_proc = subprocess.Popen(
                ["npm", "run", "dev", "--", "--port", dashboard_port, "--host", "127.0.0.1"],
                cwd=dist.parent,
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
                env=safe_env(),
            )
        except FileNotFoundError:
            dashboard_url = f"http://127.0.0.1:{backend_port}"
            console.print("[yellow]npm not found, starting backend only[/yellow]")
    else:
        dashboard_url = f"http://127.0.0.1:{backend_port}"

    _open_browser(dashboard_url)
    console.print(f"[bold green]Dashboard starting at {dashboard_url}[/bold green]")
    console.print("[dim]Press Ctrl+C to stop[/dim]")

    try:
        backend_proc.wait()
    except KeyboardInterrupt:
        backend_proc.terminate()
        if frontend_proc:
            frontend_proc.terminate()
        console.print("\n[dim]Dashboard stopped[/dim]")


def run_command(args):
    design_path = args.design

    if not Path(design_path).exists():
        friendly_error("manifest", f"Directory not found: {design_path}")
        sys.exit(1)

    manifest_file = Path(design_path) / "gli_manifest.yaml"
    if not manifest_file.exists():
        friendly_error("manifest", f"Not found: {manifest_file}")
        sys.exit(1)

    ok, msg = validate_manifest(manifest_file)
    if not ok:
        print_error(f"Manifest validation failed: {msg}")
        sys.exit(1)

    if not getattr(args, 'mock', False):
        config = _load_yaml_config()
        pdk_root = config.get("pdk_root", str(Path.home() / ".gli-flow" / "pdk"))
        if "PDK_ROOT" not in os.environ:
            os.environ["PDK_ROOT"] = pdk_root

    try:
        print_banner()

        db_path = getattr(args, 'db_path', None)
        backend = "mock" if getattr(args, 'mock', False) else "local"

        if not getattr(args, 'mock', False):
            validator = EnvironmentValidator(db_path=db_path, backend=backend)
            env_report = validator.validate_all()
            env_fails = []
            for section, items in env_report.sections.items():
                for item in items:
                    if item.failed:
                        env_fails.append(f"{section}/{item.name}: {item.detail}")
            if env_fails:
                print_error("Environment validation failed:")
                for f in env_fails:
                    print_error(f"  {f}")
                console.print("\n[bold yellow]Run 'gli-flow doctor' for full report or 'gli-flow doctor --fix' to auto-repair[/bold yellow]")
                sys.exit(1)
        orchestrator = FlowOrchestrator(
            design_path=design_path,
            threads=args.threads,
            memory_mb=args.memory,
            orfs_root=args.orfs_root,
            mock=getattr(args, 'mock', False),
            db_path=db_path,
        )
        print_run_header(
            orchestrator.run_id,
            orchestrator.design_name,
            str(orchestrator.run_dir),
        )

        record = orchestrator.run()

        elapsed = getattr(record, "runtime_sec", None)
        print_achievement_summary(record, elapsed)

        if record.status == "FAILED":
            sys.exit(1)

        sys.exit(0)

    except FileNotFoundError as e:
        print_error(f"File not found: {e}")
        sys.exit(1)
    except Exception as e:
        print_error(f"Unexpected error: {e}")
        if args.verbose:
            traceback.print_exc()
        sys.exit(1)


def history_command(args):
    print_banner()
    console.print("[bold]Run History[/bold]")
    console.print()

    db = DatabaseManager(db_path=getattr(args, 'db_path', None))
    runs = db.get_recent_runs(limit=args.limit or 20)
    print_run_history(runs)


def status_command(args):
    print_banner()
    console.print("[bold]Recent Runs[/bold]")
    console.print()

    db = DatabaseManager(db_path=getattr(args, 'db_path', None))
    runs = db.get_recent_runs(limit=10)
    print_run_history(runs)


def batch_command(args):
    print_banner()
    console.print("[bold]Batch Run[/bold]")
    console.print()

    designs = args.designs
    if not designs:
        console.print("[red]No design directories specified[/red]")
        sys.exit(1)

    resource = ResourceSpec(threads=args.threads or 0, memory_mb=args.memory or 0)
    queue = JobQueue(max_parallel=args.parallel or 1, default_resource=resource)

    for d in designs:
        run = queue.add(d)
        console.print(f"  [dim]Queued:[/dim] {run.name} ({d})")

    console.print()
    console.print(f"[bold]Running {len(designs)} design(s) with {args.parallel or 1} worker(s)...[/bold]")
    console.print()

    def on_progress(run):
        status = "[green]OK[/green]" if run.status.name == "SUCCESS" else "[red]FAIL[/red]"
        dur = f"{run.result.duration:.1f}s" if run.result else "—"
        console.print(f"  {status} {run.name:<20} {dur}")

    queue.set_progress_callback(on_progress)
    results = queue.run_all()

    console.print()
    summary = queue.summary()
    console.print(f"[bold]Batch Complete:[/bold] "
                  f"{summary['success']} succeeded, "
                  f"{summary['failed']} failed, "
                  f"{summary['total']} total")

    if summary["failed"] > 0:
        sys.exit(1)


def _write_install_report(report):
    report_dir = Path.home() / ".gli-flow"
    report_dir.mkdir(parents=True, exist_ok=True)
    report_path = report_dir / "install_report.json"
    report_path.write_text(report.to_json())
    return report_path


def install_command(args):
    print_banner()

    installer = Installer(
        pdk_name=args.pdk,
        pdk_root=args.pdk_root,
        orfs_root=args.orfs_root,
        force=args.force,
        dry_run=args.dry_run,
        skip_system=args.skip_system,
        skip_pdk=args.skip_pdk,
        skip_orfs=args.skip_orfs,
    )

    console.print(f"[bold]Platform:[/bold] {installer.info.distro} {installer.info.version}")
    console.print(f"[bold]PDK:[/bold] {args.pdk}")
    console.print(f"[bold]ORFS:[/bold] {installer.orfs_root}")
    if args.dry_run:
        console.print("[yellow]DRY RUN[/yellow] — no changes will be made")
    console.print()

    report = installer.run()

    # Write install report
    report_path = _write_install_report(report)
    console.print(f"[dim]Install report: {report_path}[/dim]")

    for item in report.completed:
        console.print(f"  [green]PASS[/green]  {item}")
    for item in report.skipped:
        console.print(f"  [dim]SKIP[/dim]  {item}")
    for item in report.failed:
        console.print(f"  [red]FAIL[/red]  {item}")
    for tool, reason, remediation in report.action_required:
        console.print(f"  [yellow]ACTION REQUIRED[/yellow]  {tool}: {reason}")

    console.print()
    console.print(report.summary_text())

    if not report.success:
        failed = [item for item in report.validations if not item.ok]
        for item in failed:
            console.print(f"  [red][FAIL] {item.tool}: {item.error or 'not installed'}[/red]")
        sys.exit(1)


def _parse_synth_stat(path):
    m = {"pin_count": None, "cell_count": None, "cell_area_um2": None}
    if not path.exists():
        return m
    text = path.read_text()
    rp = re.search(r"Number of port bits:\s+(\d+)", text)
    if rp:
        m["pin_count"] = int(rp.group(1))
    rc = re.search(r"Number of cells:\s+(\d+)", text)
    if rc:
        m["cell_count"] = int(rc.group(1))
    ra = re.search(r"Chip area for module.*?:\s+([\d.]+)", text)
    if ra:
        m["cell_area_um2"] = float(ra.group(1))
    return m


def _parse_finish_rpt(path):
    m = {
        "wns": None, "tns": None, "worst_slack": None,
        "setup_violations": None, "hold_violations": None,
        "fanout_violations": None, "cap_violations": None, "slew_violations": None,
        "critical_path_ns": None, "critical_path_slack": None,
        "total_power_w": None, "seq_power_w": None, "comb_power_w": None, "clock_power_w": None,
        "clock_skew_ns": None,
    }
    if not path.exists():
        return m
    text = path.read_text()

    for key, pat in [
        ("tns", r"^tns\s+(-?[\d.]+)"),
        ("wns", r"^wns\s+(-?[\d.]+)"),
        ("worst_slack", r"worst slack\s+(-?[\d.]+)"),
        ("setup_violations", r"setup violation count\s+(\d+)"),
        ("hold_violations", r"hold violation count\s+(\d+)"),
        ("fanout_violations", r"max fanout violation count\s+(\d+)"),
        ("cap_violations", r"max cap violation count\s+(\d+)"),
        ("slew_violations", r"max slew violation count\s+(\d+)"),
        ("clock_skew_ns", r"([\d.]+)\s+setup skew"),
    ]:
        match = re.search(pat, text, re.MULTILINE)
        if match:
            v = match.group(1)
            m[key] = float(v) if "." in v else int(v)

    for key, pat in [
        ("critical_path_ns", r"critical path delay\n[-=]+\n([\d.]+)"),
        ("critical_path_slack", r"critical path slack\n[-=]+\n([\d.]+)"),
    ]:
        match = re.search(pat, text)
        if match:
            m[key] = float(match.group(1))

    power_block = re.search(
        r"report_power\s*-+\s*Group.*?" + re.escape("Total") +
        r"\s+([\de.+-]+)\s+([\de.+-]+)\s+([\de.+-]+)\s+([\de.+-]+)",
        text, re.DOTALL,
    )
    if power_block:
        m["total_power_w"] = float(power_block.group(4))

    for label, key in [
        ("Sequential", "seq_power_w"),
        ("Combinational", "comb_power_w"),
        ("Clock", "clock_power_w"),
    ]:
        pat = rf"^{re.escape(label)}\s+([\de.+-]+)\s+([\de.+-]+)\s+([\de.+-]+)\s+([\de.+-]+)"
        pr = re.search(pat, text, re.MULTILINE)
        if pr:
            m[key] = float(pr.group(4))

    return m


def _parse_def_for_die_area(path):
    if not path.exists():
        return None
    text = path.read_text()
    m = re.search(r"DIEAREA\s*\(\s*(\d+)\s+(\d+)\s*\)\s*\(\s*(\d+)\s+(\d+)\s*\)", text)
    if not m:
        return None
    units_m = re.search(r"UNITS DISTANCE MICRONS\s+(\d+)", text)
    scale = int(units_m.group(1)) if units_m else 1000
    w = (int(m.group(3)) - int(m.group(1))) / scale
    h = (int(m.group(4)) - int(m.group(2))) / scale
    return w * h


def _read_clock_period(path):
    if not path.exists():
        return None
    text = path.read_text().strip()
    if text:
        try:
            return float(text)
        except ValueError:
            pass
    return None


def report_command(args):
    platform = args.platform_flag or args.platform or "sky130hd"
    orfs_root_s = args.orfs_root_flag or args.orfs_root or "~/.gli-flow/orfs/flow"
    orfs_root = Path(orfs_root_s).expanduser().resolve()
    results_dir = orfs_root / "results" / platform / args.design / "base"
    reports_dir = orfs_root / "reports" / platform / args.design / "base"

    if not results_dir.exists():
        print_error(f"Results directory not found: {results_dir}")
        sys.exit(1)

    metrics = {
        "design": args.design,
        "platform": platform,
    }

    synth_stat = _parse_synth_stat(reports_dir / "synth_stat.txt")
    metrics.update(synth_stat)

    finish = _parse_finish_rpt(reports_dir / "6_finish.rpt")
    metrics.update(finish)

    die_area = _parse_def_for_die_area(results_dir / "6_final.def")
    metrics["die_area_um2"] = die_area

    if metrics.get("cell_area_um2") and die_area:
        metrics["utilization_pct"] = (metrics["cell_area_um2"] / die_area) * 100

    clk_period = _read_clock_period(results_dir / "clock_period.txt")
    if clk_period:
        metrics["fmax_mhz"] = 1000 / clk_period
    elif finish.get("critical_path_ns"):
        slack = finish.get("critical_path_slack") or 0
        metrics["fmax_mhz"] = 1000 / (finish["critical_path_ns"] + slack)

    print_banner()
    print_report(metrics)


def ci_command(args):
    from gli_flow.cli.output import console, print_banner

    config = CIConfig(
        design_path=args.design,
        junit_output=args.junit,
        markdown_output=args.markdown,
        baseline_run_id=args.baseline,
        qor_score_min=args.qor_min,
        wns_max=args.wns_max,
        verbose=args.verbose,
        db_path=getattr(args, 'db_path', None),
    )
    runner = CIRunner(config)
    print_banner()
    console.print(f"[bold]CI Run:[/bold] {args.design}")
    console.print()

    report = runner.run()

    if report.success:
        console.print(f"[bold green]CI PASS[/bold green] — {report.run_id} ({report.duration:.1f}s)")
    else:
        console.print(f"[bold red]CI FAIL[/bold red] — {report.run_id}")
        if report.regressions:
            for r in report.regressions:
                console.print(f"  [red]![/red] {r}")
        if report.error:
            console.print(f"  [red]ERROR:[/red] {report.error}")
        sys.exit(1)


def _print_doctor_section(section_name: str, items):
    from rich.table import Table
    from rich import box
    status_colors = {"PASS": "green", "FAIL": "red", "WARN": "yellow", "INFO": "blue"}
    table = Table(title=f"[bold]{section_name}[/bold]", box=box.SIMPLE, show_header=True)
    table.add_column("Check", style="bold")
    table.add_column("Status", width=10)
    table.add_column("Detail")
    for item in items:
        color = status_colors.get(item.status, "white")
        status_str = f"[{color}]{item.status}[/{color}]"
        table.add_row(item.name, status_str, item.detail)
    console.print(table)
    console.print()


def _print_magic_doctor_section(items):
    """Print dedicated Magic section with path, version, and status."""
    from rich.table import Table
    from rich import box
    magic_items = [i for i in items if i.name == "magic"]
    if not magic_items:
        return
    mi = magic_items[0]
    table = Table(title="[bold]Magic[/bold]", box=box.SIMPLE, show_header=False)
    table.add_column("Field", style="bold")
    table.add_column("Value")
    table.add_row("Path", mi.detail.split(" at ")[-1].split(" [")[0] if " at " in mi.detail else mi.detail)
    table.add_row("Version", mi.detail.split(" ")[0] if " " in mi.detail else "?")
    status_color = "green" if mi.passed else "red"
    table.add_row("Status", f"[{status_color}]{mi.status}[/{status_color}]")
    if mi.failed:
        table.add_row("Issue", f"[red]{mi.detail}[/red]")
    console.print(table)
    console.print()


def _doctor_output(validator: EnvironmentValidator):
    print_banner()
    console.print("[bold]GLI-FLOW Doctor — Environment Health Report[/bold]\n")
    report = validator.validate_all()
    order = ["SYSTEM", "TOOLS", "DATABASE", "PDK", "DOCKER", "ORFS", "NETWORK", "PERMISSIONS"]
    for section in order:
        items = report.sections.get(section, [])
        if items:
            _print_doctor_section(section, items)
    # Print dedicated Magic section
    all_items = [i for items in report.sections.values() for i in items]
    _print_magic_doctor_section(all_items)
    overall = report.readiness
    color = "bold green" if report.all_pass else "bold yellow" if any(
        i.warned for items in report.sections.values() for i in items
    ) else "bold red"
    console.print(f"[{color}]{overall}[/{color}]")
    telemetry_enabled = _get_telemetry_setting()
    console.print(
        f"\n[dim]Telemetry: {'enabled' if telemetry_enabled else 'disabled'}"
        f" | To change: gli-flow config --telemetry {'off' if telemetry_enabled else 'on'}"
        f"[/dim]"
    )
    if not report.all_pass:
        console.print("\n[bold]To attempt auto-repair:[/bold] gli-flow doctor --fix")
    return report


def _print_magic_discovery(discovery: DiscoveryReport):
    """Print detailed Magic discovery report showing all candidates."""
    from rich.table import Table
    from rich import box
    console.print()
    console.print(f"[bold]Magic Discovery — {len(discovery.candidates)} candidate(s) found[/bold]")
    console.print()
    for i, c in enumerate(discovery.candidates, 1):
        table = Table(title=f"Candidate #{i}", box=box.SIMPLE, show_header=False)
        table.add_column("Field", style="bold")
        table.add_column("Value")
        selected_mark = "YES" if discovery.selected and c.path == discovery.selected.path else "NO"
        status_color = {
            "valid": "green", "broken": "red", "unknown": "yellow",
        }.get(c.status.value, "white")
        table.add_row("Path", c.path)
        table.add_row("Version", c.version_str if c.version_str != "unknown" else "[yellow]unknown[/yellow]")
        table.add_row("Status", f"[{status_color}]{c.status.value.upper()}[/{status_color}]")
        if c.failure_reason:
            table.add_row("Reason", f"[red]{c.failure_reason}[/red]")
        if c.validation_evidence:
            table.add_row("Evidence", c.validation_evidence[0][:80])
        table.add_row("Selected", "[green]YES[/green]" if selected_mark == "YES" else "[dim]NO[/dim]")
        console.print(table)
        console.print()
    if discovery.issues:
        console.print("[bold yellow]Issues:[/bold yellow]")
        for issue in discovery.issues:
            console.print(f"  [yellow]- {issue}[/yellow]")
        console.print()
    if discovery.repair_available:
        console.print(f"[bold]Resolution:[/bold] Run [green]{discovery.repair_command}[/green]")
        console.print()


def doctor_command(args):
    from gli_flow.infrastructure.environment_validator import EnvironmentValidator

    db_path = getattr(args, 'db_path', None)

    if getattr(args, 'repair_magic', False):
        info("Magic Path Shadowing Repair")
        result = repair_path_shadowing("magic")
        if result.success:
            success(f"{result.action}: {result.detail}")
            info("Re-running doctor check...")
        else:
            error_and_exit(f"{result.action}: {result.detail}", fix="Manually check your PATH or reinstall Magic.", verbose=getattr(args, 'verbose', False))
        console.print()

    validator = EnvironmentValidator(db_path=db_path, backend="local")

    if getattr(args, 'fix', False):
        info("Running auto-repair...")
        repair_results = run_repairs(db_path=db_path)
        for result in repair_results:
            if result.success:
                success(f"{result.action}: {result.detail}")
            else:
                warn(f"{result.action}: {result.detail}")
            if result.requires_restart:
                warn(f"Restart required: {result.detail}")
        console.print()
        info("Re-checking after repairs...")

    report = _doctor_output(validator)

    if not getattr(args, 'repair_magic', False):
        discovery = run_magic_discovery()
        _print_magic_discovery(discovery)

    if not report.all_pass:
        sys.exit(1)


def remote_command(args):
    from gli_flow.cli.output import console, print_banner

    config = RemoteWorkerConfig(
        host=args.host,
        port=args.port or 22,
        user=args.user or "",
        key_path=args.key or "",
        max_concurrent=1,
        gli_flow_path=args.gli_flow_path or "gli-flow",
        work_dir=args.work_dir or "",
    )
    worker = RemoteWorker(name=args.host, config=config)

    if args.check:
        ok = worker.check_connection()
        if ok:
            console.print(f"[bold green]Connection OK[/bold green] — {config.ssh_host}")
        else:
            console.print(f"[bold red]Connection FAILED[/bold red] — {config.ssh_host}")
            sys.exit(1)
        return

    print_banner()
    console.print(f"[bold]Remote Run:[/bold] {args.design} -> {config.ssh_host}")
    console.print()

    result = worker.run(args.design)
    if result.success:
        console.print(f"[bold green]SUCCESS[/bold green] — {result.run_id} ({result.duration:.1f}s)")
    else:
        console.print(f"[bold red]FAILED[/bold red] — {result.error or 'Unknown error'}")
        sys.exit(1)


def cloud_command(args):
    from gli_flow.cli.output import console, print_banner

    provider = CloudProvider(args.provider) if args.provider else CloudProvider.S3
    config = CloudStorageConfig(
        provider=provider,
        bucket=args.bucket or "gli-flow-runs",
        prefix=args.prefix or "runs",
    )
    mgr = CloudStorageManager(config)

    if args.action == "upload":
        print_banner()
        console.print(f"[bold]Uploading run:[/bold] {args.run_id}")
        url = mgr.upload_run(args.dir, args.run_id)
        if url:
            console.print(f"[bold green]Uploaded:[/bold green] {url}")
        else:
            console.print("[bold red]Upload failed[/bold red]")
            sys.exit(1)

    elif args.action == "download":
        print_banner()
        console.print(f"[bold]Downloading run:[/bold] {args.run_id}")
        dest = mgr.download_run(args.run_id, args.dir or ".")
        if dest:
            console.print(f"[bold green]Downloaded to:[/bold green] {dest}")
        else:
            console.print("[bold red]Download failed[/bold red]")
            sys.exit(1)

    elif args.action == "list":
        runs = mgr.list_runs()
        console.print("[bold]Cloud Runs[/bold]")
        console.print()
        for r in runs:
            console.print(f"  {r}")



FRIENDLY_ERRORS = {
    "PDK_ROOT": (
        "PDK_ROOT is not set. The PDK (Process Design Kit) tells the tools how to build "
        "your chip for a specific foundry process.\n\n"
        "  Quick fix:\n"
        "    export PDK_ROOT=$HOME/.gli-flow/pdk\n"
        "    gli-flow install\n"
    ),
    "ORFS_ROOT": (
        "ORFS_ROOT is not set. OpenROAD Flow Scripts (ORFS) is the build system that "
        "runs the actual synthesis, place & route steps.\n\n"
        "  Quick fix:\n"
        "    export ORFS_ROOT=/path/to/orfs/flow\n"
        "    gli-flow install\n"
    ),
    "openroad": (
        "OpenROAD binary not found. It is the main engine for synthesis, placement, "
        "routing, and timing analysis.\n\n"
        "  Quick fix:\n"
        "    gli-flow install\n"
    ),
    "yosys": (
        "Yosys not found. Yosys performs RTL synthesis (converting Verilog to gates).\n\n"
        "  Quick fix:\n"
        "    gli-flow install\n"
    ),
    "klayout": (
        "KLayout not found. It is used for GDS viewing and DRC verification.\n\n"
        "  Quick fix:\n"
        "    gli-flow install\n"
    ),
    "manifest": (
        "No gli_manifest.yaml found in the design directory.\n\n"
        "  A manifest tells GLI-FLOW what to build. Create one with:\n"
        "    gli-flow init <design_name>\n"
        "  or copy from an example:\n"
        "    cp -r examples/counter my_design\n"
        "    gli-flow run my_design --mock\n"
    ),
}

STAGE_EXPLANATIONS = {
    "INITIALIZING": "Setting up directories, loading PDK, and validating the environment",
    "SYNTHESIS": "Converting Verilog RTL to a gate-level netlist using Yosys+OpenROAD",
    "FLOORPLANNING": "Placing the chip I/O pads and defining the die area",
    "PLACEMENT": "Arranging standard cells within the floorplan",
    "CTS": "Building the clock tree to distribute the clock signal with minimal skew",
    "ROUTING": "Connecting all cells with metal wires (global + detailed)",
    "DRC": "Design Rule Check — verifying the layout against foundry manufacturing rules",
    "LVS": "Layout vs. Schematic — checking that the layout matches the original netlist",
    "TIMING_ANALYSIS": "Static Timing Analysis — verifying the design meets timing constraints",
    "POWER": "Analyzing power consumption and IR drop across the chip",
    "SIGN_OFF": "Final sign-off checks: timing, power, DRC, LVS, antenna rules",
    "QOR_EXTRACTION": "Collecting final metrics and computing the QoR (Quality of Results) score",
    "PACKAGING": "Running the full ORFS flow: synthesis → floorplan → place → route → finish",
}


def friendly_error(error_key, extra=None):
    msg = FRIENDLY_ERRORS.get(error_key, f"Unknown issue: {error_key}")
    print(f"\n  [!] {msg}", file=sys.stderr)
    if extra:
        print(f"\n  Details: {extra}", file=sys.stderr)
    print(file=sys.stderr)


def init_command(args):
    design_name = args.design_name

    manifest = {
        "design_name": design_name,
        "rtl_files": [f"rtl/{design_name}.sv"],
        "top_module": design_name,
        "backend": "openroad",
        "pdk": "sky130",
        "pdk_variant": "sky130A",
        "clock_port": "clk",
        "clock_period_ns": 10.0,
        "threads": 4,
    }

    rtl_source = args.rtl_dir or args.rtl
    if rtl_source:
        rtl_path = Path(rtl_source)
        if rtl_path.is_file():
            mods = parse_file(rtl_path)
            if mods:
                manifest["top_module"] = mods[0].name
                manifest["design_name"] = mods[0].name
                manifest["rtl_files"] = [str(rtl_path)]
                if mods[0].clock_ports:
                    manifest["clock_port"] = mods[0].clock_ports[0].name
                if mods[0].reset_ports:
                    manifest["clock_port"] = manifest.get("clock_port", "clk")
        elif rtl_path.is_dir():
            detected = detect_from_directory(rtl_path)
            if detected.get("rtl_files"):
                manifest["rtl_files"] = detected["rtl_files"]
            if detected.get("top_module"):
                manifest["top_module"] = detected["top_module"]
                manifest["design_name"] = detected["top_module"]
            if detected.get("clock_port"):
                manifest["clock_port"] = detected["clock_port"]
        else:
            print_error(f"RTL path not found: {rtl_source}")
            sys.exit(1)
        console.print(f"[green]Auto-detected from RTL:[/green] top_module={manifest['top_module']}, "
                       f"rtl_files={len(manifest['rtl_files'])} file(s)")

    manifest_path = Path(design_name) / "gli_manifest.yaml"
    manifest_path.parent.mkdir(parents=True, exist_ok=True)
    import yaml
    with open(manifest_path, "w") as f:
        yaml.dump(manifest, f, default_flow_style=False)
    print(f"\n  [OK] Created {manifest_path}")
    print(f"\n  Next steps:")
    print(f"    1. Place your Verilog files in {design_name}/rtl/")
    print(f"    2. Run: gli-flow run {design_name} --mock")


def quickstart_command(args):
    print_banner()
    print("  Welcome to GLI-FLOW! Let's get you set up quickly.\n")

    try:
        design_name = input("  Design name (e.g., my_chip): ").strip() or "my_design"
    except (EOFError, KeyboardInterrupt):
        print("\n  Aborted.")
        return

    print(f"\n  Creating manifest for '{design_name}'...")
    manifest = {
        "design_name": design_name,
        "rtl_files": [f"rtl/{design_name}.sv"],
        "top_module": design_name,
        "backend": "openroad",
        "pdk": "sky130",
        "pdk_variant": "sky130A",
        "clock_port": "clk",
        "clock_period_ns": 10.0,
        "threads": 4,
    }

    design_dir = Path(design_name)
    rtl_dir = design_dir / "rtl"

    existing_rtl = list(rtl_dir.glob("*.v")) + list(rtl_dir.glob("*.sv"))
    if existing_rtl:
        detected = detect_from_directory(rtl_dir)
        if detected.get("rtl_files"):
            manifest["rtl_files"] = detected["rtl_files"]
            console.print(f"[green]Discovered {len(detected['rtl_files'])} RTL file(s) in rtl/[/green]")
        if detected.get("top_module"):
            manifest["top_module"] = detected["top_module"]
            manifest["design_name"] = detected["top_module"]
            console.print(f"[green]Detected top module:[/green] {detected['top_module']}")
        if detected.get("clock_port"):
            manifest["clock_port"] = detected["clock_port"]
            console.print(f"[green]Detected clock port:[/green] {detected['clock_port']}")
    else:
        rtl_dir.mkdir(parents=True, exist_ok=True)
        sv_path = rtl_dir / f"{design_name}.sv"
        sv_path.write_text(f"""// {design_name} — generated by gli-flow quickstart
module {design_name} (
    input  wire       clk,
    input  wire       rst_n,
    input  wire [7:0] data_in,
    output reg  [7:0] data_out
);
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            data_out <= 8'd0;
        else
            data_out <= data_in;
    end
endmodule
""")
        console.print(f"[green]Created boilerplate RTL:[/green] {sv_path}")

    manifest_path = design_dir / "gli_manifest.yaml"
    import yaml
    with open(manifest_path, "w") as f:
        yaml.dump(manifest, f, default_flow_style=False)

    print(f"\n  [OK] Created {manifest_path}")
    print(f"\n  Try it now:")
    print(f"       gli-flow run {design_name} --mock")
    print()


def diagnose_command(args):
    """Diagnose a failed run by scanning stage logs."""
    from rich.console import Console
    from rich.panel import Panel
    from pathlib import Path
    import json
    import re as re_mod

    c = Console()
    run_id = args.run_id

    db = DatabaseManager(db_path=getattr(args, 'db_path', None))
    run = db.get_run(run_id)
    if not run:
        c.print(f"[red]Run '{run_id}' not found.[/red]")
        return

    run_dir = Path(run.get("run_dir", ""))
    if not run_dir.exists():
        c.print(f"[red]Run directory not found: {run_dir}[/red]")
        return

    from failure_atlas.run_trust_engine import RunTrustEngine
    from gli_flow.database.migrations import _get_db_path
    
    # ... inside diagnose_command ...
    c.print(f"\n[bold]Diagnosing run: {run_id}[/bold]")

    trust_engine = RunTrustEngine(getattr(args, 'db_path', None) or _get_db_path())
    trust_score = trust_engine.compute_run_trust_score(run_id)
    
    c.print(f"[bold]Run Trust Score:[/bold] {(trust_score['trust_ratio'] * 100):.1f}%")
    c.print(f"[dim]Breakdown:[/dim] Verified: {trust_score['verified_count']} / Heuristic: {trust_score['heuristic_count']} / Unverified: {trust_score['unverified_count']}")
    
    findings = []

    t_path = run_dir / "telemetry.json"
    if t_path.exists():
        with open(t_path) as f:
            telemetry = json.load(f)
        status = telemetry.get("flow", {}).get("status")
        failure_stage = telemetry.get("flow", {}).get("failure_stage")
        if failure_stage:
            findings.append({
                "type": "STAGE_FAILURE", "stage": failure_stage,
                "message": f"Flow failed at stage: {failure_stage}",
            })

    log_patterns = [
        {"pattern": r"Latch inferred", "stage": "Synthesis",
         "cause": "Latch inferred in synthesis",
         "fix": "Add default assignments to all incomplete if/case branches",
         "atlas": "FA-0019"},
        {"pattern": r"overflow.*[5-9]\d%|overflow.*100%", "stage": "Routing",
         "cause": "High routing overflow",
         "fix": "Reduce FP_CORE_UTIL by 15% in gli_manifest.yaml",
         "atlas": "FA-0002"},
        {"pattern": r"[Kk]illed|[Oo]ut of [Mm]emory", "stage": "Any",
         "cause": "Process killed by OOM",
         "fix": "Run with more memory: gli-flow run <design> --memory 32000",
         "atlas": None},
        {"pattern": r"Module.*not found", "stage": "Synthesis",
         "cause": "Missing Verilog module",
         "fix": "Add missing module source files to rtl_files in gli_manifest.yaml",
         "atlas": None},
        {"pattern": r"hold.*violation|whs.*-", "stage": "STA",
         "cause": "Hold timing violations",
         "fix": "Add set_fix_hold to SDC. Hold violations are TAPEOUT BLOCKING.",
         "atlas": "FA-0006"},
        {"pattern": r"DRC.*violation|violation.*DRC", "stage": "DRC",
         "cause": "DRC violations in final GDS",
         "fix": "Review DRC report: gli-flow report <run_id> --drc",
         "atlas": None},
        {"pattern": r"LVS.*FAIL|FAIL.*LVS", "stage": "LVS",
         "cause": "LVS mismatch — layout does not match schematic",
         "fix": "Check for missing connections or extra connections in routing",
         "atlas": None},
    ]

    for log_file in run_dir.rglob("*.log"):
        try:
            content = log_file.read_text(errors='ignore')
            for p in log_patterns:
                if re_mod.search(p["pattern"], content, re_mod.IGNORECASE):
                    finding = {
                        "type": "LOG_MATCH", "log_file": log_file.name,
                        "stage": p["stage"], "cause": p["cause"], "fix": p["fix"],
                    }
                    if p.get("atlas"):
                        finding["atlas"] = p["atlas"]
                    if finding not in findings:
                        findings.append(finding)
        except Exception:
            pass

    ai_explanation_path = run_dir / "ai_explanation.json"
    if ai_explanation_path.exists():
        try:
            explanation = json.loads(ai_explanation_path.read_text())
            c.print(f"\n[bold]AI GENERATED — EXPERIMENTAL — NOT VERIFIED[/bold]")
            c.print(f"  [bold]Summary:[/bold] {explanation.get('summary', 'N/A')}")
            if explanation.get("likely_cause"):
                c.print(f"  [bold]Likely Cause:[/bold] {explanation['likely_cause']}")
            if explanation.get("recommended_actions"):
                c.print(f"  [bold]Recommended:[/bold]")
                for a in explanation["recommended_actions"]:
                    c.print(f"    - {a}")
            if explanation.get("knowledge_base_citations"):
                c.print(f"  [bold]References:[/bold] {', '.join(explanation['knowledge_base_citations'])}")
            c.print(f"  [dim]Confidence: {explanation.get('confidence', 'LOW')}[/dim]")
            c.print()
            if findings:
                c.print("[bold]Additional Log Findings:[/bold]")
            else:
                return
        except (json.JSONDecodeError, KeyError):
            pass

    if not findings:
        c.print("[yellow]No specific failure pattern detected in signature library.[/yellow]")
        c.print()
        from failure_atlas.ai_assistant.explanation_engine import ExplanationEngine
        try:
            engine = ExplanationEngine(str(run_dir), run.get("design_name", ""), run_id)
            explanation = engine.generate()
            c.print(f"\n[bold]AI GENERATED — EXPERIMENTAL — NOT VERIFIED[/bold]")
            c.print(f"  [bold]Summary:[/bold] {explanation.summary}")
            if explanation.likely_cause:
                c.print(f"  [bold]Likely Cause:[/bold] {explanation.likely_cause}")
            if explanation.recommended_actions:
                c.print(f"  [bold]Recommended:[/bold]")
                for a in explanation.recommended_actions:
                    c.print(f"    - {a}")
            if explanation.knowledge_base_citations:
                c.print(f"  [bold]References:[/bold] {', '.join(explanation.knowledge_base_citations)}")
            c.print(f"  [dim]Confidence: {explanation.confidence}[/dim]")
        except Exception as e:
            c.print(f"[yellow]AI explanation unavailable: {e}[/yellow]")
        return

    for f in findings:
        c.print(Panel(
            f"[bold]Stage:[/bold] {f.get('stage')}\n"
            f"[bold]Cause:[/bold] {f.get('cause')}\n"
            f"[bold]Fix:[/bold] {f.get('fix')}"
            + (f"\n[bold]Atlas:[/bold] {f.get('atlas')}" if f.get('atlas') else ""),
            title=f"[bold red]Finding: {f.get('type')}[/bold red]",
            border_style="red"
        ))


def investigate_command(args):
    """Run LLM investigation on a failed run (Tier 2 — Experimental).

    Hardened: preserves existing successful investigations on failure,
    maintains history, creates backups, validates API key before attempting.
    """
    from rich.console import Console
    from rich.panel import Panel
    from pathlib import Path
    from gli_flow.investigation import InvestigationLayer
    from gli_flow.investigation.availability import InvestigationAvailabilityService
    from gli_flow.database.sqlite import DatabaseManager

    c = Console()
    run_id = args.run_id

    availability = InvestigationAvailabilityService().check_availability()
    if not availability.is_ready:
        c.print(f"[red]Investigation unavailable: {availability.reason}[/red]")
        c.print(f"[dim]Fix: {availability.fix}[/dim]")
        return

    db = DatabaseManager(db_path=getattr(args, 'db_path', None))
    run = db.get_run(run_id)
    if not run:
        c.print(f"[red]Run '{run_id}' not found.[/red]")
        return

    run_dir = Path(run.get("run_dir", ""))
    if not run_dir.exists():
        c.print(f"[red]Run directory not found: {run_dir}[/red]")
        return

    c.print(f"\n[bold yellow]AI Investigation — {run_id}[/bold yellow]")
    c.print("[dim]Tier 2 (Experimental) — Does not override deterministic results[/dim]\n")

    layer = InvestigationLayer(run_dir=str(run_dir), run_id=run_id)

    if layer.has_successful_investigation():
        c.print("[dim]Existing successful investigation found. New attempt will not overwrite it on failure.[/dim]\n")

    with c.status("[yellow]Running AI investigation..."):
        result = layer.investigate()
    saved_path = layer.save_investigation(result)

    summary = ""
    if result.payload and result.payload.get("summary"):
        summary = result.payload["summary"]

    failed_attempts_json = None
    if not result.is_success():
        import json
        failed_attempts = layer.get_failed_attempts()
        failed_attempts_json = json.dumps({"attempts": failed_attempts})

    db.update_run_investigation(
        run_id=run_id,
        available=result.is_success(),
        status=result.status,
        summary=summary,
        timestamp=__import__('datetime').datetime.now().isoformat(),
        failed_attempts=failed_attempts_json,
    )

    if result.status == "FAILED":
        c.print(f"\n[red]Investigation failed: {result.error}[/red]")
        if layer.has_successful_investigation():
            c.print("[green]Previous successful investigation preserved.[/green]")
        return
    if result.status == "UNAVAILABLE":
        c.print(f"\n[red]Investigation unavailable: {result.error}[/red]")
        return

    payload = result.payload or {}
    c.print(f"[green]✓ Investigation complete[/green] ({result.latency_sec:.1f}s)")
    c.print(f"[dim]Provider: {result.provider} / Model: {result.model}[/dim]\n")

    c.print(Panel(
        f"[bold]Status:[/bold] {payload.get('investigation_status', 'N/A')}\n"
        f"[bold]Summary:[/bold] {payload.get('summary', 'N/A')}",
        title="[bold yellow]AI Investigation[/bold yellow]",
        border_style="yellow",
    ))

    facts = payload.get('facts', [])
    if facts:
        c.print(f"\n[bold]Facts ({len(facts)}):[/bold]")
        for f in facts:
            c.print(f"  • {f.get('observation', 'N/A')} [dim]({f.get('source', '?')})[/dim]")

    causes = payload.get('possible_causes', [])
    if causes:
        c.print(f"\n[bold]Possible Causes ({len(causes)}):[/bold]")
        for c_ in causes:
            conf = c_.get('confidence', 'LOW')
            conf_color = {"HIGH": "red", "MEDIUM": "yellow", "LOW": "dim"}.get(conf, "dim")
            c.print(f"  [{conf_color}][{conf}][/] {c_.get('cause', 'N/A')}")

    steps = payload.get('recommended_next_steps', [])
    if steps:
        c.print(f"\n[bold]Recommended Next Steps:[/bold]")
        for s in steps:
            c.print(f"  → {s}")

    missing = payload.get('missing_information', [])
    if missing:
        c.print(f"\n[dim]Missing Information:[/dim]")
        for m in missing:
            c.print(f"  [dim]- {m}[/dim]")

    if payload.get('disclaimer'):
        c.print(f"\n[dim]{payload['disclaimer']}[/dim]")

    c.print(f"\n[dim]Full result saved to: {saved_path}[/dim]")
    history = layer.get_investigation_history()
    if len(history) > 1:
        c.print(f"[dim]Investigation history: {len(history)} entries in {run_dir / 'investigations/'}[/dim]")
    failed = layer.get_failed_attempts()
    if failed:
        c.print(f"[dim]Failed attempts on record: {len(failed)}[/dim]")


def investigate_migrate_command(args):
    """Restore failed investigations from backup or history."""
    from rich.console import Console
    from rich.table import Table
    from pathlib import Path
    from gli_flow.investigation import InvestigationLayer
    from gli_flow.database.sqlite import DatabaseManager

    c = Console()
    db = DatabaseManager(db_path=getattr(args, 'db_path', None))

    run_ids = []
    if args.run_id:
        run_ids = [args.run_id]
    else:
        cursor = db.connection.cursor()
        cursor.execute(
            "SELECT run_id FROM runs WHERE llm_investigation_status IN ('FAILED', 'SKIPPED', 'UNAVAILABLE')"
            " AND llm_investigation_available = 0"
        )
        run_ids = [r[0] for r in cursor.fetchall()]

    if not run_ids:
        c.print("[green]No failed investigations found to migrate.[/green]")
        return

    restored = 0
    table = Table(title="Investigation Migration Results")
    table.add_column("Run ID")
    table.add_column("Result")

    for rid in run_ids:
        run = db.get_run(rid)
        if not run:
            table.add_row(rid, "[red]Run not found[/red]")
            continue
        run_dir = Path(run.get("run_dir", ""))
        if not run_dir.exists():
            table.add_row(rid, "[red]Directory not found[/red]")
            continue
        layer = InvestigationLayer(run_dir=str(run_dir), run_id=rid)
        if layer.migrate_failed_investigations():
            restored += 1
            table.add_row(rid, "[green]Restored from backup/history[/green]")
        else:
            table.add_row(rid, "[yellow]No backup available[/yellow]")

    c.print(table)
    if restored:
        c.print(f"\n[green]✓ {restored} investigation(s) restored.[/green]")
    else:
        c.print("\n[yellow]No investigations could be restored.[/yellow]")


def show_telemetry_command(args):
    """Show exact JSON payload that would be uploaded."""
    from rich.console import Console
    from rich.syntax import Syntax
    import json
    from pathlib import Path

    c = Console()
    run_id = args.run_id

    db = DatabaseManager(db_path=getattr(args, 'db_path', None))
    run = db.get_run(run_id)
    if not run:
        c.print(f"[red]Run not found: {run_id}[/red]")
        return

    run_dir = Path(run.get("run_dir", ""))
    t_path = run_dir / "telemetry.json"

    if not t_path.exists():
        c.print("[red]No telemetry file for this run.[/red]")
        return

    with open(t_path) as f:
        telemetry = json.load(f)

    upload_payload = {
        "schema_version": telemetry.get("schema_version"),
        "execution_id": telemetry.get("execution_id"),
        "gli_version": telemetry.get("gli_version"),
        "backend": telemetry.get("backend"),
        "pdk": telemetry.get("pdk"),
        "timing": telemetry.get("timing", {}),
        "area": telemetry.get("area", {}),
        "power": telemetry.get("power", {}),
        "routing": {k: v for k, v in telemetry.get("routing", {}).items()
                     if k not in ["drc_report_path", "lvs_report_path"]},
        "runtime": telemetry.get("runtime", {}),
        "qor_score": telemetry.get("qor_score"),
        "flow_status": telemetry.get("flow", {}).get("status"),
    }

    c.print("\n[bold]Telemetry payload that would be uploaded:[/bold]\n"
            "[dim](This exact JSON — nothing more)[/dim]")
    c.print(Syntax(json.dumps(upload_payload, indent=2), "json", theme="monokai"))

    c.print("\n[bold green]✓ No RTL, module names, or design-identifying data above.[/bold green]\n"
            "[dim]To opt out permanently: gli-flow config --telemetry off[/dim]")


def _ensure_config_dir():
    cfg_dir = Path.home() / ".gli-flow"
    cfg_dir.mkdir(parents=True, exist_ok=True)
    return cfg_dir


def _load_yaml_config():
    cfg_dir = _ensure_config_dir()
    yaml_path = cfg_dir / "config.yaml"
    if yaml_path.exists():
        import yaml
        with open(yaml_path) as f:
            return yaml.safe_load(f) or {}
    json_path = cfg_dir / "config.json"
    if json_path.exists():
        import json
        with open(json_path) as f:
            return json.load(f)
    return {}


def _save_yaml_config(config):
    cfg_dir = _ensure_config_dir()
    import yaml
    yaml_path = cfg_dir / "config.yaml"
    with open(yaml_path, "w") as f:
        yaml.dump(config, f, default_flow_style=False)
    json_path = cfg_dir / "config.json"
    if json_path.exists():
        json_path.unlink()


def setup_command(args):
    """Interactive first-time setup — configure PDK, tools, workspace."""
    from rich.panel import Panel
    from rich.prompt import Prompt, Confirm
    from rich.table import Table

    console.print()
    console.print(Panel(
        "[bold cyan]GLI-FLOW Setup[/bold cyan]\n\n"
        "This will help you configure:\n"
        "  • PDK location\n"
        "  • EDA tool paths\n"
        "  • Workspace directory\n"
        "  • Telemetry preference",
        border_style="cyan",
    ))
    console.print()

    config = _load_yaml_config()

    if not args.non_interactive:
        pdk_root = args.pdk_root or Prompt.ask(
            "[bold]PDK root directory[/bold]",
            default=config.get("pdk_root", str(Path.home() / ".gli-flow" / "pdk")),
        )
        workspace = args.workspace or Prompt.ask(
            "[bold]Workspace directory[/bold]",
            default=config.get("workspace", str(Path.home() / "gli-flow-workspace")),
        )
        telemetry = args.telemetry
        if telemetry is None:
            telemetry = "on" if Confirm.ask(
                "[bold]Enable telemetry?[/bold]\n"
                "  (Anonymized metrics only — no RTL or design data)",
                default=True,
            ) else "off"
    else:
        pdk_root = args.pdk_root or config.get("pdk_root", str(Path.home() / ".gli-flow" / "pdk"))
        workspace = args.workspace or config.get("workspace", str(Path.home() / "gli-flow-workspace"))
        telemetry = args.telemetry or config.get("telemetry", "on")

    config.update({
        "pdk_root": pdk_root,
        "workspace": workspace,
        "telemetry": telemetry,
    })

    _save_yaml_config(config)
    console.print(f"[green]✓[/green] Configuration saved to ~/.gli-flow/config.yaml")

    _validate_config(config)

    console.print()
    console.print(Panel(
        "[bold green]Setup complete![/bold green]\n\n"
        "Next steps:\n"
        f"  [bold cyan]gli-flow doctor[/bold cyan]     — validate EDA tools\n"
        f"  [bold cyan]gli-flow quickstart[/bold cyan] — run your first design\n"
        f"  [bold cyan]gli-flow run examples/counter[/bold cyan] — run the counter example",
        border_style="green",
    ))
    console.print()


def _validate_config(config):
    """Validate setup configuration immediately."""
    from rich.console import Console
    c = Console()

    issues = []

    pdk_root = Path(config.get("pdk_root", ""))
    if not pdk_root.exists():
        issues.append(f"PDK root does not exist: {pdk_root}")
        c.print(f"  [yellow]⚠ PDK root does not exist: {pdk_root}[/yellow]")
        c.print(f"  [dim]  Run 'gli-flow install --pdk sky130' to install the PDK.[/dim]")
    else:
        c.print(f"  [green]✓[/green] PDK root: {pdk_root}")

    workspace = Path(config.get("workspace", ""))
    if not workspace.exists():
        workspace.mkdir(parents=True, exist_ok=True)
        c.print(f"  [green]✓[/green] Created workspace: {workspace}")
    else:
        c.print(f"  [green]✓[/green] Workspace: {workspace}")

    telemetry = config.get("telemetry", "on")
    status = "enabled" if telemetry == "on" else "disabled"
    c.print(f"  [green]✓[/green] Telemetry: {status}")

    return issues


def support_bundle_command(args):
    """Generate a support bundle archive for debugging."""
    import json
    import zipfile
    import platform
    import subprocess
    from datetime import datetime

    cfg_dir = _ensure_config_dir()
    bundle_name = args.output or f"gli-flow-support-bundle-{datetime.now().strftime('%Y%m%d_%H%M%S')}.zip"
    bundle_path = Path(bundle_name)
    if not bundle_path.suffix:
        bundle_path = bundle_path.with_suffix(".zip")

    console.print(f"[cyan]Generating support bundle: {bundle_path}[/cyan]")

    bundle_data = {}
    files_to_include = []

    # Config
    for cfg_file in ["config.yaml", "config.json"]:
        p = cfg_dir / cfg_file
        if p.exists():
            files_to_include.append((str(p), f"config/{cfg_file}"))

    # === Enhanced: Version information ===
    from gli_flow.version import VERSION
    bundle_data["version"] = {
        "gli_flow_version": VERSION,
        "python_version": platform.python_version(),
        "platform": platform.platform(),
        "system": platform.system(),
        "release": platform.release(),
    }

    # === Enhanced: Tool versions ===
    tools = {}
    for tool in ("yosys", "openroad", "magic", "netgen", "klayout", "python3"):
        try:
            r = subprocess.run([tool, "--version"], capture_output=True, text=True, timeout=5)
            tools[tool] = r.stdout.strip()[:200] if r.returncode == 0 else None
        except Exception:
            tools[tool] = None
    bundle_data["tool_versions"] = tools

    # === Enhanced: Telemetry health ===
    try:
        from failure_atlas.community_intelligence.health import TelemetryHealth
        health_checker = TelemetryHealth(getattr(args, 'db_path', None))
        bundle_data["telemetry_health"] = health_checker.check()
    except Exception as e:
        bundle_data["telemetry_health"] = {"error": str(e)}

    # === Enhanced: Run metadata (top 20 recent runs) ===
    try:
        db = DatabaseManager(db_path=getattr(args, 'db_path', None))
        bundle_data["recent_runs"] = db.get_runs(limit=20)
    except Exception:
        bundle_data["recent_runs"] = []

    # === Enhanced: Failure fingerprints ===
    try:
        db_path = getattr(args, 'db_path', None) or os.environ.get("GLI_FLOW_DB") or os.environ.get("GLI_FLOW_DB_PATH")
        if db_path:
            import sqlite3
            conn = sqlite3.connect(db_path)
            rows = conn.execute(
                "SELECT signature, failure_type, severity, occurrence_count, first_seen, last_seen "
                "FROM failure_atlas_entries ORDER BY occurrence_count DESC LIMIT 20"
            ).fetchall()
            bundle_data["failure_fingerprints"] = [
                {"signature": r[0], "failure_type": r[1], "severity": r[2],
                 "occurrence_count": r[3], "first_seen": r[4], "last_seen": r[5]}
                for r in rows
            ]
            conn.close()
        else:
            bundle_data["failure_fingerprints"] = []
    except Exception:
        bundle_data["failure_fingerprints"] = []

    # === Enhanced: Audit summaries ===
    try:
        db_path = getattr(args, 'db_path', None) or os.environ.get("GLI_FLOW_DB") or os.environ.get("GLI_FLOW_DB_PATH")
        if db_path:
            import sqlite3
            conn = sqlite3.connect(db_path)
            rows = conn.execute(
                "SELECT event_type, status, COUNT(*) as cnt FROM telemetry_audit_log "
                "GROUP BY event_type, status ORDER BY cnt DESC LIMIT 20"
            ).fetchall()
            bundle_data["audit_summary"] = [{"event_type": r[0], "status": r[1], "count": r[2]} for r in rows]
            conn.close()
        else:
            bundle_data["audit_summary"] = []
    except Exception:
        bundle_data["audit_summary"] = []

    # Doctor output
    try:
        from gli_flow.doctor import run_doctor
        report = run_doctor(db_path=getattr(args, 'db_path', None))
        bundle_data["doctor"] = report.to_dict() if hasattr(report, 'to_dict') else str(report)
    except Exception:
        pass

    # Logs
    logs_dir = Path("logs")
    if logs_dir.exists():
        for log_file in sorted(logs_dir.rglob("*.log"))[:20]:
            files_to_include.append((str(log_file), f"logs/{log_file.relative_to(logs_dir)}"))

    # Recent run artifacts (if run_id specified, exclude RTL/netlists/GDS/etc.)
    EXCLUDED_SUFFIXES = {".v", ".sv", ".vhdl", ".vhd", ".gds", ".gdsii", ".def", ".lef",
                         ".lib", ".lib.gz", ".db", ".sdc", ".spi", ".cdl", ".mag", ".ext"}
    if args.run_id:
        try:
            db = DatabaseManager(db_path=getattr(args, 'db_path', None))
            run = db.get_run(args.run_id)
            if run:
                run_dir = Path(run.get("run_dir", ""))
                if run_dir.exists():
                    for f in run_dir.rglob("*"):
                        if f.is_file() and f.suffix in (".log", ".json", ".rpt", ".md"):
                            if f.suffix not in EXCLUDED_SUFFIXES:
                                files_to_include.append((str(f), f"run/{f.relative_to(run_dir)}"))
        except Exception:
            pass

    # Write bundle_data.json
    bundle_data_path = cfg_dir / "bundle_data.json"
    with open(bundle_data_path, "w") as f:
        json.dump(bundle_data, f, indent=2, default=str)
    files_to_include.append((str(bundle_data_path), "bundle_data.json"))

    # Write zip
    with zipfile.ZipFile(bundle_path, "w", zipfile.ZIP_DEFLATED) as zf:
        for src, arcname in files_to_include:
            if Path(src).exists():
                zf.write(src, arcname)

    console.print(f"[green]✓[/green] Support bundle written to: {bundle_path.resolve()}")
    console.print(f"[dim]  Contains {len(files_to_include)} files[/dim]")


def upgrade_check_command(args):
    """Check for newer versions of GLI-FLOW."""
    import json
    from urllib.request import urlopen, Request
    from urllib.error import URLError

    from gli_flow.version import VERSION
    current = VERSION.lstrip("v")
    console.print(f"[dim]Current version: {VERSION}[/dim]")

    pypi_url = "https://pypi.org/pypi/gli-flow/json"
    github_url = "https://api.github.com/repos/green-lantern-industries/gli-flow/releases/latest"

    for url, source in [(pypi_url, "PyPI"), (github_url, "GitHub")]:
        try:
            req = Request(url, headers={"User-Agent": "gli-flow/upgrade-check"})
            with urlopen(req, timeout=5) as resp:
                data = json.loads(resp.read().decode())
            if source == "PyPI":
                latest = data.get("info", {}).get("version", "")
            else:
                latest = data.get("tag_name", "").lstrip("v")
            if latest:
                console.print(f"[dim]  Latest on {source}: v{latest}[/dim]")
                if latest > current:
                    console.print(f"[yellow]⚠ A newer version is available: v{latest}[/yellow]")
                    console.print(f"  Upgrade: pip install --upgrade gli-flow")
                    return
                elif latest == current:
                    console.print(f"[green]✓ v{current} is the latest version on {source}[/green]")
                    return
        except URLError:
            console.print(f"[dim]  Could not check {source} (offline)[/dim]")
        except Exception:
            continue

    console.print("[yellow]Could not determine latest version (offline or not published yet).[/yellow]")
    console.print(f"  Current: {VERSION}")
    console.print(f"  Check: https://github.com/green-lantern-industries/gli-flow/releases")


def config_command(args):
    """Set or view configuration."""
    config = _load_config()
    if args.telemetry is not None:
        config["telemetry"] = args.telemetry
        _save_config(config)
        console.print(f"[green]Telemetry set to: {args.telemetry}[/green]")
        return
    console.print(f"Telemetry: {config.get('telemetry', 'on')}")


def ai_assist_command(args):
    """AI Investigation Assistant — analyze unknown failures."""
    from failure_atlas.ai_assistant import (
        should_use_ai, build_context, AIResponse, validate_response,
        FeedbackStore,
    )

    if args.feedback:
        store = FeedbackStore(db_path=getattr(args, 'db_path', None))
        if args.helpful:
            store.record_feedback(
                investigation_id=args.feedback,
                feedback_type="helpful",
                run_id=args.run_id or "",
                failure_type=args.failure_type or "",
            )
            console.print("[green]✓ Feedback recorded: Helpful[/green]")
            return
        if args.not_helpful:
            store.record_feedback(
                investigation_id=args.feedback,
                feedback_type="not_helpful",
                run_id=args.run_id or "",
                failure_type=args.failure_type or "",
            )
            console.print("[green]✓ Feedback recorded: Not Helpful[/green]")
            return
        if args.resolved:
            store.record_feedback(
                investigation_id=args.feedback,
                feedback_type="resolved",
                resolved=True,
                run_id=args.run_id or "",
                failure_type=args.failure_type or "",
            )
            console.print("[green]✓ Feedback recorded: Resolved[/green]")
            return
        if args.did_not_resolve:
            store.record_feedback(
                investigation_id=args.feedback,
                feedback_type="did_not_resolve",
                run_id=args.run_id or "",
                failure_type=args.failure_type or "",
            )
            console.print("[green]✓ Feedback recorded: Did Not Resolve[/green]")
            return

        feedback_list = store.get_feedback_for_investigation(args.feedback)
        if not feedback_list:
            console.print("[yellow]No feedback found for this investigation.[/yellow]")
            return
        console.print(f"[bold]Feedback for investigation: {args.feedback}[/bold]")
        for f in feedback_list:
            console.print(f"  [{f['feedback_type']}] {f['created_at']}")
            if f.get("comment"):
                console.print(f"    Comment: {f['comment']}")
        return

    failure_type = args.failure_type or "UNKNOWN"
    signature = args.signature or ""
    severity = args.severity or "MEDIUM"
    confidence = args.confidence or 0.0
    tool = args.tool or ""
    stage = args.stage or ""
    error_text = args.error_text or ""
    log_snippet = args.log_snippet or ""

    print_banner()
    print_ai_assistant_header()

    trigger = should_use_ai(
        failure_type=failure_type,
        signature=signature,
        severity=severity,
        confidence=confidence,
    )

    if not trigger.use_ai:
        console.print("[green]✓ Failure is recognized — AI Investigation not required.[/green]")
        console.print("Reasons:")
        for r in trigger.reasons:
            console.print(f"  • {r}")
        return

    context = build_context(
        tool=tool,
        stage=stage,
        error_text=error_text,
        log_snippet=log_snippet,
        failure_type=failure_type,
    )

    response = AIResponse.heuristic_fallback(context.to_dict())
    errors = validate_response(response.to_dict())

    result = {
        "trigger": {
            "use_ai": trigger.use_ai,
            "reasons": trigger.reasons,
            "signature_match": trigger.signature_match,
            "historical_count": trigger.historical_count,
            "confidence": trigger.confidence,
        },
        "context": context.to_dict(),
        "response": response.to_dict(),
        "validation_errors": errors,
    }

    print_ai_response(result)

    if errors:
        console.print(f"\n[yellow]Validation warnings: {errors}[/yellow]")


def escalate_command(args):
    """Community Intelligence escalation — submit unknown failures to GLI engineers."""
    from failure_atlas.community_intelligence import (
        EscalationManager, EscalationRecord, should_escalate,
        FailurePackageBuilder, FailurePackage,
    )

    if args.submit and not args.consent:
        console.print("[red]ERROR: --consent is required to submit an escalation.[/red]")
        sys.exit(1)

    print_banner()
    print_escalation_header()

    failure_type = args.failure_type or "UNKNOWN"
    signature = args.signature or ""
    severity = args.severity or "MEDIUM"
    confidence = args.confidence or 0.0
    tool = args.tool or ""
    stage = args.stage or ""
    error_text = args.error_text or ""

    # Check if escalation is warranted
    esc_trigger = should_escalate(
        failure_type=failure_type,
        signature=signature,
        severity=severity,
        confidence=confidence,
    )

    if not esc_trigger.should_escalate:
        console.print("[green]✓ Failure is recognized — Community Intelligence escalation not required.[/green]")
        for r in esc_trigger.reasons:
            console.print(f"  • {r}")
        return

    if args.feedback:
        store = EscalationManager(db_path=getattr(args, 'db_path', None))
        try:
            record = store.get_escalation(args.feedback)
            if not record:
                console.print(f"[yellow]No escalation found: {args.feedback}[/yellow]")
                return
            from gli_flow.database.migrations import _get_db_path
            console.print(f"[bold]Escalation: {record.id}[/bold]")
            console.print(f"  Status: {record.status}")
            console.print(f"  Failure: {record.failure_type} ({record.tool}/{record.stage})")
            console.print(f"  Consent: {'Yes' if record.consent_given else 'No'}")
            if record.bharatcode_submission_id:
                console.print(f"  BharatCode ID: {record.bharatcode_submission_id}")
            if record.engineer_response and record.engineer_response != "{}":
                import json
                resp = json.loads(record.engineer_response) if isinstance(record.engineer_response, str) else record.engineer_response
                console.print(f"  Engineer Response:")
                for k, v in resp.items():
                    console.print(f"    {k}: {v}")
            console.print(f"  Created: {record.created_at}")
        finally:
            store.close()
        return

    if args.submit:
        from gli_flow.database.migrations import _get_db_path
        store = EscalationManager(db_path=getattr(args, 'db_path', None))
        try:
            escalation = store.create_escalation(
                run_id=args.run_id or "",
                failure_type=failure_type,
                tool=tool,
                stage=stage,
                user_notes=args.notes or "",
                consent_given=args.consent,
            )

            store.submit_escalation(escalation.id)
            console.print(f"[bold green]✓[/bold green] Escalation submitted: [bold]{escalation.id}[/bold]")
            console.print(f"  Failure: {failure_type}")
            if args.notes:
                console.print(f"  Notes: {args.notes}")
            console.print()
            console.print("[dim]The escalation has been sent to GLI engineers for analysis.[/dim]")
        finally:
            store.close()
        return

    # Dry run: show what would be escalated
    console.print(f"[bold]Escalation Assessment:[/bold]")
    console.print(f"  Failure Type: {failure_type}")
    console.print(f"  Signature: {signature or '(none)'}")
    console.print(f"  Tool/Stage: {tool}/{stage}")
    console.print(f"  Error: {error_text[:200] if error_text else '(none)'}")
    console.print()
    console.print("[bold]Trigger Reasons:[/bold]")
    for r in esc_trigger.reasons:
        console.print(f"  • {r}")
    console.print()
    console.print("[yellow]This is a dry run. Use --submit --consent to send the escalation.[/yellow]")


EXAMPLES = {
    "run": "Examples:\n  gli-flow run examples/counter\n  gli-flow run designs/my_chip --threads 4\n  gli-flow run . --mock    # dry run without real tools",
    "history": "Examples:\n  gli-flow history\n  gli-flow history --limit 50",
    "status": "Examples:\n  gli-flow status",
    "init": "Examples:\n  gli-flow init my_chip\n  gli-flow init my_chip --rtl-dir src/rtl\n  gli-flow init my_chip --rtl src/top.v",
    "quickstart": "Examples:\n  gli-flow quickstart",
    "install": "Examples:\n  gli-flow install\n  gli-flow install --pdk gf180mcu\n  gli-flow install --pdk-root /opt/pdk --skip-orfs\n  gli-flow install --dry-run  # preview without changes",
    "ci": "Examples:\n  gli-flow ci examples/counter\n  gli-flow ci . --junit results.xml --markdown report.md\n  gli-flow ci . --baseline run_abc123 --wns-max -0.1",
    "doctor": "Examples:\n  gli-flow doctor\n  gli-flow doctor --fix",
    "diagnose": "Examples:\n  gli-flow diagnose run_abc123",
    "investigate": "Examples:\n  gli-flow investigate run_abc123",
    "cloud": "Examples:\n  gli-flow cloud upload run_abc123 --provider s3 --bucket my-bucket\n  gli-flow cloud download run_abc123 --dir ./restored",
    "db": "Examples:\n  gli-flow db status\n  gli-flow db migrate",
    "config": "Examples:\n  gli-flow config\n  gli-flow config --telemetry off",
    "dashboard": "Examples:\n  gli-flow dashboard\n  gli-flow dashboard --backend-only",
    "setup": "Examples:\n  gli-flow setup\n  gli-flow setup --non-interactive --pdk-root /opt/pdk --workspace ~/designs\n  gli-flow setup --telemetry off",
    "remote": "Examples:\n  gli-flow remote . --host 192.168.1.100 --user root\n  gli-flow remote . --host server.local --check",
    "batch": "Examples:\n  gli-flow batch designs/counter designs/uart designs/gpio\n  gli-flow batch *. --parallel 4",
    "report": "Examples:\n  gli-flow report\n  gli-flow report counter sky130hd",
    "show-telemetry": "Examples:\n  gli-flow show-telemetry run_abc123",
    "reset-runs": "Examples:\n  gli-flow reset-runs",
    "upgrade-check": "Examples:\n  gli-flow upgrade-check",
    "ai-assist": "Examples:\n  gli-flow ai-assist --failure-type TIMING_VIOLATION --tool openroad\n  gli-flow ai-assist --feedback inv_abc123",
    "escalate": "Examples:\n  gli-flow escalate --failure-type UNKNOWN --tool yosys --submit --consent\n  gli-flow escalate --feedback esc_abc123",
    "telemetry": "Examples:\n  gli-flow telemetry export\n  gli-flow telemetry export --format csv\n  gli-flow telemetry replay export.json\n  gli-flow telemetry snapshot",
    "support-bundle": "Examples:\n  gli-flow support-bundle\n  gli-flow support-bundle --run-id run_abc123 -o bundle.zip",
}


def warehouse_command(args):
    """Handle warehouse subcommands."""
    from gli_flow.database.migrations import _get_db_path
    from failure_atlas.repository import FailureAtlasRepository
    db_path = args.db_path or _get_db_path()
    repo = FailureAtlasRepository(db_path)

    if args.warehouse_command == "status":
        stats = repo.get_statistics()
        print(f"Warehouse Status: {stats['total_entries']} entries, {stats['fix_rate']}% fix rate")

    elif args.warehouse_command == "coverage":
        summary = repo.get_domain_summary()
        print("Atlas Coverage:")
        for row in summary:
            print(f"  {row['domain']}: {row['occurrences']} ({row['percentage']}%)")

    elif args.warehouse_command == "quality":
        # Placeholder for IntelligenceQualityEngine
        print("Intelligence Quality Score: 0.85 (Needs implementation)")

    elif args.warehouse_command == "correlations":
        # Placeholder for CorrelationEngine
        print("Correlation Chains: (Needs implementation)")

    elif args.warehouse_command == "snapshot":
        from failure_atlas.knowledge_graph import KnowledgeGraphBuilder
        builder = KnowledgeGraphBuilder(db_path)
        snapshot = builder.build_snapshot()
        print(f"Created knowledge graph snapshot: {len(snapshot['nodes'])} nodes, {len(snapshot['edges'])} edges")

    else:
        print("Unknown warehouse command. Use: gli-flow warehouse status|coverage|quality|correlations|snapshot")


def telemetry_command(args):
    """Handle telemetry subcommands."""
    from gli_flow.database.migrations import _get_db_path
    from gli_flow.telemetry.settings import get_telemetry_settings
    from gli_flow.telemetry.wizard import TelemetryMode
    db_path = getattr(args, 'db_path', None) or _get_db_path()
    settings = get_telemetry_settings()

    if args.telemetry_command == "status":
        from failure_atlas.community_intelligence.health import TelemetryHealth
        health = TelemetryHealth(db_path)
        status = health.get_health()
        console.print(f"  Telemetry Mode: [bold]{settings.mode.upper()}[/bold]")
        console.print(f"  Mode:              [bold]{settings.mode.upper()}[/bold]")
        console.print(f"  Consent Status:    {'[green]Given[/green]' if settings.consent_given else '[yellow]Not Given[/yellow]'}")
        console.print(f"  Events Collected:  {status['collected_events']}")
        console.print(f"  Events Uploaded:   {status.get('uploaded_events', 0)}")
        console.print(f"  Events Blocked:    {status['blocked_fields']}")
        console.print(f"  Upload Success:    {status['upload_success_rate']:.1%}")
        console.print(f"  Last Upload:       {status['last_upload_time'] or 'never'}")

    elif args.telemetry_command == "enable":
        settings.mode = TelemetryMode.FULL
        settings.consent_given = True
        settings.save()
        console.print("[bold green]Telemetry enabled (Full mode).[/bold green]")

    elif args.telemetry_command == "disable":
        settings.mode = TelemetryMode.LOCAL
        settings.consent_given = False
        settings.save()
        console.print("[bold yellow]Telemetry disabled (Local mode).[/bold yellow]")

    elif args.telemetry_command == "mode":
        if not args.mode_value:
            console.print(f"Current Telemetry Mode: [bold]{settings.mode.upper()}[/bold]")
            return
        
        mode_map = {
            "full": TelemetryMode.FULL,
            "atlas": TelemetryMode.ATLAS,
            "local": TelemetryMode.LOCAL,
            "disabled": TelemetryMode.DISABLED
        }
        val = args.mode_value.lower()
        if val in mode_map:
            settings.mode = mode_map[val]
            settings.consent_given = (val != "local" and val != "disabled")
            settings.save()
            console.print(f"Telemetry mode set to: [bold]{val.upper()}[/bold]")
        else:
            console.print(f"[red]Invalid mode: {args.mode_value}. Valid modes: full, atlas, local, disabled[/red]")

    elif args.telemetry_command == "preview":
        from rich.syntax import Syntax
        from failure_atlas.community_intelligence.export import TelemetryExporter
        exporter = TelemetryExporter(db_path)
        data = exporter.export_to_json()
        if not data or data == "{}":
            console.print("[yellow]No telemetry events to preview.[/yellow]")
            return
        
        console.print("\n[bold]Telemetry Upload Preview (Most recent event):[/bold]")
        console.print(Syntax(data, "json", theme="monokai"))

    elif args.telemetry_command == "export":
        from failure_atlas.community_intelligence.export import TelemetryExporter
        exporter = TelemetryExporter(db_path)
        fmt = args.format or "json"
        if fmt == "csv":
            outputs = exporter.export_to_csv(
                run_id=args.run_id or None,
                from_date=args.from_date or None,
                to_date=args.to_date or None,
            )
            output_path = args.output or "telemetry_export.csv"
            combined = []
            for section, content in outputs.items():
                if content:
                    path = output_path.replace(".csv", f"_{section}.csv")
                    with open(path, "w") as f:
                        f.write(content)
                    combined.append(path)
            print(f"Exported {len(combined)} CSV files:")
            for p in combined:
                print(f"  {p}")
        else:
            data = exporter.export_to_json(
                run_id=args.run_id or None,
                from_date=args.from_date or None,
                to_date=args.to_date or None,
            )
            output_path = args.output or "telemetry_export.json"
            with open(output_path, "w") as f:
                f.write(data)
            import json
            parsed = json.loads(data)
            meta = parsed.get("export_metadata", {})
            counts = meta.get("record_count", {})
            print(f"Exported to {output_path}")
            for k, v in counts.items():
                print(f"  {k}: {v}")
            if meta.get("privacy_validated"):
                print("  Privacy: VALIDATED")
            else:
                report = meta.get("privacy_report", {})
                print(f"  Privacy: {report.get('issue_count', '?')} issues found")

    elif args.telemetry_command == "replay":
        from failure_atlas.community_intelligence.replay import TelemetryReplayEngine
        engine = TelemetryReplayEngine(db_path)
        dry_run = getattr(args, "dry_run", True)
        results = engine.replay(args.filepath, dry_run=dry_run)
        print(engine.summary_text())

    elif args.telemetry_command == "health":
        from failure_atlas.community_intelligence.health import TelemetryHealth
        health = TelemetryHealth(db_path)
        status = health.get_health()
        print("Telemetry Health")
        print(f"  Overall Status:    {status['overall_status']}")
        print(f"  Collected Events:  {status['collected_events']}")
        print(f"  Upload Success:    {status['upload_success_rate']:.1%}")
        print(f"  Upload Failures:   {status['upload_failures']}")
        print(f"  Queued Events:     {status['queued_events']}")
        print(f"  Avg Latency:       {status['average_upload_latency_ms']:.0f}ms")
        print(f"  Last Upload:       {status['last_upload_time'] or 'never'}")
        print(f"  Last Sanitization: {status['last_sanitization_time'] or 'never'}")

    elif args.telemetry_command == "snapshot":
        from failure_atlas.community_intelligence.snapshot import DatasetSnapshot
        snap = DatasetSnapshot(db_path)
        output = args.output or "dataset_snapshot.json"
        result = snap.create(output_path=output)
        print(f"Created dataset snapshot: {output}")
        meta = result.get("snapshot_metadata", {})
        for k, v in meta.get("record_count", {}).items():
            print(f"  {k}: {v}")

    elif args.telemetry_command == "audit-log":
        from failure_atlas.community_intelligence.audit import TelemetryAuditLog
        audit = TelemetryAuditLog(db_path)
        logs = audit.get_logs(
            limit=args.limit,
            event_type=args.event_type or None,
        )
        stats = audit.get_stats()
        print(f"Audit Log — {stats['total_entries']} total entries, {stats['total_rejected']} rejected")
        for log in logs:
            print(f"  [{log['recorded_at'][:19]}] {log['event_type']:20s} {log['status']:10s} {log['event_name'][:30]}")

    elif args.telemetry_command == "upload-internal":
        from gli_flow.telemetry.uploader import TelemetryUploader
        uploader = TelemetryUploader(db_path)
        uploader.upload_run_telemetry(args.run_id)

    else:
        print("Unknown telemetry command. Use: gli-flow telemetry status|enable|disable|mode|preview|export|replay|health|snapshot|audit-log")


def build_parser():
    parser = argparse.ArgumentParser(
        prog="gli-flow",
        description="GLI-FLOW — RTL-to-GDS Digital Design Flow",
        epilog="See 'gli-flow <command> --help' for detailed command help.\n"
               "Report issues: https://github.com/green-lantern-industries/gli-flow/issues",
        formatter_class=CategorizedHelpFormatter,
    )
    parser.add_argument("--non-interactive", action="store_true", help="Run in non-interactive mode (default to local telemetry)")

    subparsers = parser.add_subparsers(dest="command")

    run_parser = subparsers.add_parser("run", help="Run a design through the flow", epilog=EXAMPLES["run"])
    run_parser._category = "Execution"
    run_parser.add_argument("design", help="Path to design directory with gli_manifest.yaml")
    run_parser.add_argument("--verbose", "-v", action="store_true", help="Show full traceback on error")
    run_parser.add_argument("--threads", "-j", type=int, default=None,
                            help="Number of parallel threads for the flow")
    run_parser.add_argument("--memory", "-m", type=int, default=None,
                            help="Memory limit in MB")
    run_parser.add_argument("--orfs-root", type=str, default=None,
                            help="Path to OpenROAD-flow-scripts installation")
    run_parser.add_argument("--mock", action="store_true",
                            help="Run with mock EDA adapter (no real tools required)")
    run_parser.add_argument("--db-path", type=str, default=None,
                            help="Path to SQLite database (default: gli_flow.db or $GLI_FLOW_DB_PATH)")

    history_parser = subparsers.add_parser("history", help="Show execution history", epilog=EXAMPLES["history"])
    history_parser._category = "Execution"
    history_parser.add_argument("--limit", type=int, default=20, help="Number of runs to show")
    history_parser.add_argument("--db-path", type=str, default=None,
                                help="Path to SQLite database (default: gli_flow.db or $GLI_FLOW_DB_PATH)")

    status_parser = subparsers.add_parser("status", help="Show recent run status", epilog=EXAMPLES["status"])
    status_parser._category = "Execution"
    status_parser.add_argument("--db-path", type=str, default=None,
                               help="Path to SQLite database (default: gli_flow.db or $GLI_FLOW_DB_PATH)")

    batch_parser = subparsers.add_parser("batch", help="Run multiple designs in parallel", epilog=EXAMPLES["batch"])
    batch_parser._category = "Execution"
    batch_parser.add_argument("designs", nargs="+", help="Design directories with gli_manifest.yaml")
    batch_parser.add_argument("--parallel", "-j", type=int, default=1,
                              help="Number of parallel workers (default: 1)")
    batch_parser.add_argument("--threads", type=int, default=None,
                              help="Threads per worker")
    batch_parser.add_argument("--memory", type=int, default=None,
                              help="Memory limit in MB per worker")

    init_parser = subparsers.add_parser("init", help="Create a new design manifest", epilog=EXAMPLES["init"])
    init_parser._category = "Setup"
    init_parser.add_argument("design_name", help="Name of the design (creates a directory and manifest)")
    init_parser.add_argument("--rtl-dir", type=str, default=None,
                              help="Path to RTL directory to auto-detect top module, ports, and files")
    init_parser.add_argument("--rtl", type=str, default=None,
                              help="Path to a single RTL file to auto-detect top module and ports")

    quickstart_parser = subparsers.add_parser("quickstart", help="Interactive setup wizard for new designs", epilog=EXAMPLES["quickstart"])
    quickstart_parser._category = "Setup"

    report_parser = subparsers.add_parser("report", help="Show QoR report for a completed ORFS run", epilog=EXAMPLES["report"])
    report_parser._category = "Analysis"
    report_parser.add_argument("design", nargs="?", default="systolic_array_4x4",
                               help="Design name (default: systolic_array_4x4)")
    report_parser.add_argument("platform", nargs="?", default=None,
                               help="Platform name (default: sky130hd)")
    report_parser.add_argument("orfs_root", nargs="?", default=None,
                               help="ORFS flow root (default: ~/.gli-flow/orfs/flow)")
    report_parser.add_argument("--platform", "-p", dest="platform_flag", default=None,
                               help="Platform name")
    report_parser.add_argument("--orfs-root", dest="orfs_root_flag", default=None,
                               help="ORFS flow root path")

    install_parser = subparsers.add_parser("install", help="Install gli-flow and all EDA toolchain dependencies", epilog=EXAMPLES["install"])
    install_parser._category = "Infrastructure"
    install_parser.add_argument("--pdk", default="sky130", choices=["sky130", "gf180mcu"],
                                help="PDK to install (default: sky130)")
    install_parser.add_argument("--pdk-root", default=None,
                                help="PDK install root directory (default: ~/.gli-flow/pdk)")
    install_parser.add_argument("--orfs-root", type=str, default=None,
                                help="OpenROAD-flow-scripts install path (default: ~/.gli-flow/orfs)")
    install_parser.add_argument("--skip-orfs", action="store_true",
                                help="Skip ORFS installation")
    install_parser.add_argument("--force", "-f", action="store_true",
                                help="Reinstall even if already present")
    install_parser.add_argument("--dry-run", "-n", action="store_true",
                                help="Show what would be installed without making changes")
    install_parser.add_argument("--skip-system", action="store_true",
                                help="Skip system package installation")
    install_parser.add_argument("--skip-pdk", action="store_true",
                                help="Skip PDK installation")

    ci_parser = subparsers.add_parser("ci", help="Run a design in CI mode with JUnit/Markdown output", epilog=EXAMPLES["ci"])
    ci_parser._category = "Analysis"
    ci_parser.add_argument("design", help="Path to design directory with gli_manifest.yaml")
    ci_parser.add_argument("--junit", type=str, default=None, help="Path to write JUnit XML report")
    ci_parser.add_argument("--markdown", type=str, default=None, help="Path to write Markdown report")
    ci_parser.add_argument("--baseline", type=str, default=None, help="Baseline run ID for comparison")
    ci_parser.add_argument("--qor-min", type=float, default=None, help="Minimum acceptable QoR score")
    ci_parser.add_argument("--wns-max", type=float, default=None, help="Maximum acceptable WNS (ns)")
    ci_parser.add_argument("--verbose", "-v", action="store_true", help="Show verbose output")
    ci_parser.add_argument("--db-path", type=str, default=None,
                            help="Path to SQLite database (default: gli_flow.db or $GLI_FLOW_DB_PATH)")

    remote_parser = subparsers.add_parser("remote", help="Run a design on a remote machine via SSH", epilog=EXAMPLES["remote"])
    remote_parser._category = "Experimental"
    remote_parser.add_argument("design", nargs="?", help="Path to design directory")
    remote_parser.add_argument("--host", required=True, help="Remote hostname or IP")
    remote_parser.add_argument("--port", type=int, default=22, help="SSH port (default: 22)")
    remote_parser.add_argument("--user", type=str, default=None, help="SSH user")
    remote_parser.add_argument("--key", type=str, default=None, help="SSH private key path")
    remote_parser.add_argument("--gli-flow-path", type=str, default="gli-flow",
                               help="Path to gli-flow on remote (default: gli-flow)")
    remote_parser.add_argument("--work-dir", type=str, default=None,
                               help="Working directory on remote (default: ~/gli-flow-runs/<run_id>)")
    remote_parser.add_argument("--check", action="store_true", help="Check SSH connection only")

    cloud_parser = subparsers.add_parser("cloud", help="Upload/download run artifacts to/from cloud storage", epilog=EXAMPLES["cloud"])
    cloud_parser._category = "Experimental"
    cloud_subparsers = cloud_parser.add_subparsers(dest="action")
    upload_parser = cloud_subparsers.add_parser("upload", help="Upload a run directory")
    upload_parser.add_argument("run_id", help="Run ID")
    upload_parser.add_argument("--dir", type=str, default=".", help="Run directory to upload")
    upload_parser.add_argument("--provider", choices=["s3", "gcs"], default="s3", help="Cloud provider")
    upload_parser.add_argument("--bucket", type=str, default=None, help="Bucket name")
    upload_parser.add_argument("--prefix", type=str, default="runs", help="Key prefix")
    download_parser = cloud_subparsers.add_parser("download", help="Download a run")
    download_parser.add_argument("run_id", help="Run ID to download")
    download_parser.add_argument("--dir", type=str, default=".", help="Destination directory")
    download_parser.add_argument("--provider", choices=["s3", "gcs"], default="s3", help="Cloud provider")
    download_parser.add_argument("--bucket", type=str, default=None, help="Bucket name")
    download_parser.add_argument("--prefix", type=str, default="runs", help="Key prefix")
    list_parser = cloud_subparsers.add_parser("list", help="List runs in cloud storage")
    list_parser.add_argument("--provider", choices=["s3", "gcs"], default="s3", help="Cloud provider")
    list_parser.add_argument("--bucket", type=str, default=None, help="Bucket name")
    list_parser.add_argument("--prefix", type=str, default="runs", help="Key prefix")

    doctor_parser = subparsers.add_parser("doctor", help="Validate installed EDA toolchain and produce health report", epilog=EXAMPLES["doctor"])
    doctor_parser._category = "Setup"
    doctor_parser.add_argument("--fix", action="store_true", help="Attempt to auto-repair detected issues")
    doctor_parser.add_argument("--repair-magic", action="store_true", help="Repair broken magic binary shadowing valid system binary")
    doctor_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    reset_parser = subparsers.add_parser("reset-runs", help="Permanently delete all run history, telemetry, and dashboard data", epilog=EXAMPLES["reset-runs"])
    reset_parser._category = "Infrastructure"
    reset_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    db_parser = subparsers.add_parser("db", help="Database schema management", epilog=EXAMPLES["db"])
    db_parser._category = "Infrastructure"
    db_subparsers = db_parser.add_subparsers(dest="db_action")
    db_status_parser = db_subparsers.add_parser("status", help="Show database schema migration status")
    db_status_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")
    db_migrate_parser = db_subparsers.add_parser("migrate", help="Apply pending database migrations")
    db_migrate_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")
    db_repair_parser = db_subparsers.add_parser("repair", help="Repair database schema version tracking")
    db_repair_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")
    db_path_parser = db_subparsers.add_parser("path", help="Show database file path")
    db_path_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    diagnose_parser = subparsers.add_parser("diagnose", help="Diagnose a failed run by scanning stage logs", epilog=EXAMPLES["diagnose"])
    diagnose_parser._category = "Analysis"
    diagnose_parser.add_argument("run_id", help="Run ID to diagnose")
    diagnose_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    investigate_parser = subparsers.add_parser("investigate", help="Run LLM investigation on a failed run (Tier 2 — Experimental)", epilog=EXAMPLES["investigate"])
    investigate_parser._category = "Experimental"
    investigate_parser.add_argument("run_id", help="Run ID to investigate")
    investigate_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    investigate_migrate_parser = subparsers.add_parser("investigate-migrate", help="Restore failed investigations from backup (Tier 2 — Experimental)")
    investigate_migrate_parser._category = "Experimental"
    investigate_migrate_parser.add_argument("run_id", nargs="?", help="Run ID to restore (omit for all)")
    investigate_migrate_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    show_telemetry_parser = subparsers.add_parser("show-telemetry", help="Show exact telemetry payload that would be uploaded (no data sent)", epilog=EXAMPLES["show-telemetry"])
    show_telemetry_parser._category = "Analysis"
    show_telemetry_parser.add_argument("run_id", help="Run ID to inspect")
    show_telemetry_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    config_parser = subparsers.add_parser("config", help="View or change GLI-FLOW configuration", epilog=EXAMPLES["config"])
    config_parser._category = "Setup"
    config_parser.add_argument("--telemetry", choices=["on", "off"], default=None, help="Enable or disable telemetry")

    dashboard_parser = subparsers.add_parser("dashboard", help="Start the GLI-FLOW dashboard", epilog=EXAMPLES["dashboard"])
    dashboard_parser._category = "Experimental"
    dashboard_parser.add_argument("--backend-only", action="store_true", help="Start backend only, skip frontend dev server")

    setup_parser = subparsers.add_parser("setup", help="Interactive first-time setup — configure PDK, tools, workspace", epilog=EXAMPLES["setup"])
    setup_parser._category = "Setup"
    setup_parser.add_argument("--pdk-root", type=str, default=None, help="PDK install root directory")
    setup_parser.add_argument("--workspace", type=str, default=None, help="Workspace directory for designs and runs")
    setup_parser.add_argument("--telemetry", choices=["on", "off"], default=None, help="Telemetry consent")
    setup_parser.add_argument("--non-interactive", action="store_true", help="Skip interactive prompts, use defaults or flags")

    support_bundle_parser = subparsers.add_parser("support-bundle", help="Generate a support bundle archive for debugging", epilog=EXAMPLES["support-bundle"])
    support_bundle_parser._category = "Infrastructure"
    support_bundle_parser.add_argument("--output", "-o", type=str, default=None, help="Output path for support bundle zip")
    support_bundle_parser.add_argument("--run-id", type=str, default=None, help="Include specific run ID's artifacts")
    support_bundle_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    upgrade_check_parser = subparsers.add_parser("upgrade-check", help="Check for newer versions of GLI-FLOW", epilog=EXAMPLES["upgrade-check"])
    upgrade_check_parser._category = "Experimental"

    ai_parser = subparsers.add_parser("ai-assist", help="AI Investigation Assistant — analyze unknown failures", epilog=EXAMPLES["ai-assist"])
    ai_parser._category = "Experimental"
    ai_parser.add_argument("--failure-type", type=str, default="", help="Failure type classification")
    ai_parser.add_argument("--signature", type=str, default="", help="Failure signature string")
    ai_parser.add_argument("--severity", type=str, default="MEDIUM", help="Failure severity")
    ai_parser.add_argument("--confidence", type=float, default=0.0, help="Classification confidence (0.0-1.0)")
    ai_parser.add_argument("--tool", type=str, default="", help="EDA tool that failed")
    ai_parser.add_argument("--stage", type=str, default="", help="Pipeline stage at failure")
    ai_parser.add_argument("--error-text", type=str, default="", help="Error text from the run")
    ai_parser.add_argument("--log-snippet", type=str, default="", help="Log snippet (last N lines)")
    ai_parser.add_argument("--run-id", type=str, default="", help="Run ID for context")
    ai_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")
    ai_parser.add_argument("--feedback", type=str, default="", help="Record or view feedback for an investigation ID")
    ai_parser.add_argument("--helpful", action="store_true", help="Mark feedback as helpful")
    ai_parser.add_argument("--not-helpful", action="store_true", help="Mark feedback as not helpful")
    ai_parser.add_argument("--resolved", action="store_true", help="Mark issue as resolved")
    ai_parser.add_argument("--did-not-resolve", action="store_true", help="Mark issue as not resolved")

    escalate_parser = subparsers.add_parser("escalate", help="Community Intelligence — escalate unknown failure to GLI engineers", epilog=EXAMPLES["escalate"])
    escalate_parser._category = "Experimental"
    escalate_parser.add_argument("--failure-type", type=str, default="", help="Failure type classification")
    escalate_parser.add_argument("--signature", type=str, default="", help="Failure signature string")
    escalate_parser.add_argument("--severity", type=str, default="MEDIUM", help="Failure severity")
    escalate_parser.add_argument("--confidence", type=float, default=0.0, help="Classification confidence (0.0-1.0)")
    escalate_parser.add_argument("--tool", type=str, default="", help="EDA tool that failed")
    escalate_parser.add_argument("--stage", type=str, default="", help="Pipeline stage at failure")
    escalate_parser.add_argument("--error-text", type=str, default="", help="Error text from the run")
    escalate_parser.add_argument("--run-id", type=str, default="", help="Run ID for context")
    escalate_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")
    escalate_parser.add_argument("--consent", action="store_true", help="Confirm consent to share sanitized failure data")
    escalate_parser.add_argument("--submit", action="store_true", help="Submit the escalation (requires --consent)")
    escalate_parser.add_argument("--notes", type=str, default="", help="Additional notes for engineers")
    escalate_parser.add_argument("--feedback", type=str, default="", help="View an escalation by ID")

    telemetry_parser = subparsers.add_parser("telemetry", help="Telemetry Operations Center — export, replay, snapshot", epilog=EXAMPLES["telemetry"])
    telemetry_parser._category = "Experimental"
    telemetry_sub = telemetry_parser.add_subparsers(dest="telemetry_command")

    telemetry_sub.add_parser("status", help="Show telemetry status and mode")
    telemetry_sub.add_parser("enable", help="Enable full telemetry collection and upload")
    telemetry_sub.add_parser("disable", help="Disable all telemetry uploads")
    
    mode_parser = telemetry_sub.add_parser("mode", help="Set or view telemetry mode")
    mode_parser.add_argument("mode_value", nargs="?", choices=["full", "atlas", "local", "disabled"], help="Telemetry mode")

    telemetry_sub.add_parser("preview", help="Preview the next telemetry upload payload")

    export_parser = telemetry_sub.add_parser("export", help="Export sanitized telemetry data")
    export_parser.add_argument("--run-id", type=str, default="", help="Filter by run ID")
    export_parser.add_argument("--from-date", type=str, default="", help="Filter from date (ISO format)")
    export_parser.add_argument("--to-date", type=str, default="", help="Filter to date (ISO format)")
    export_parser.add_argument("--format", choices=["json", "csv"], default="json", help="Export format (default: json)")
    export_parser.add_argument("--output", "-o", type=str, default="", help="Output file path")
    export_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    replay_parser = telemetry_sub.add_parser("replay", help="Replay a telemetry export file")
    replay_parser.add_argument("filepath", help="Path to telemetry_export.json")
    replay_parser.add_argument("--dry-run", action="store_true", default=False, help="Simulate without recording (default: true)")
    replay_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    health_parser = telemetry_sub.add_parser("health", help="Show telemetry pipeline health")
    health_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    snapshot_parser = telemetry_sub.add_parser("snapshot", help="Create a dataset snapshot for AI training")
    snapshot_parser.add_argument("--output", "-o", type=str, default="", help="Output file path")
    snapshot_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    audit_parser = telemetry_sub.add_parser("audit-log", help="Show telemetry audit log")
    audit_parser.add_argument("--limit", type=int, default=50, help="Number of entries")
    audit_parser.add_argument("--event-type", type=str, default="", help="Filter by event type")
    audit_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    upload_internal_parser = telemetry_sub.add_parser("upload-internal", help=argparse.SUPPRESS)
    upload_internal_parser.add_argument("run_id", help="Run ID to upload")
    upload_internal_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    
    warehouse_parser = subparsers.add_parser("warehouse", help="Telemetry Intelligence Warehouse — status, coverage, quality, correlations, snapshot")
    warehouse_parser._category = "Experimental"
    warehouse_sub = warehouse_parser.add_subparsers(dest="warehouse_command")

    warehouse_sub.add_parser("status", help="Show warehouse capacity, yield, and coverage")
    warehouse_sub.add_parser("coverage", help="Show failure atlas coverage analysis")
    warehouse_sub.add_parser("quality", help="Show intelligence quality score")
    warehouse_sub.add_parser("correlations", help="List discovered Failure -> Root Cause -> Resolution chains")
    warehouse_sub.add_parser("snapshot", help="Create a knowledge graph snapshot")

    predict_parser = subparsers.add_parser("predict", help="Predict execution risk and tapeout readiness")
    predict_parser._category = "Experimental"
    predict_parser.add_argument("run_id", help="Run ID or 'latest'")
    predict_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    return parser


def main():
    setup_logging()
    parser = build_parser()
    args = parser.parse_args()

    # Skip wizard for basic help/config commands if they are being used to disable it
    if args.command not in [None, "help"] and not (args.command == "telemetry" and args.telemetry_command in ["disable", "mode"]):
        # Pass non-interactive status to telemetry consent
        try:
            _ensure_telemetry_consent(non_interactive=getattr(args, 'non_interactive', False))
        except Exception as e:
            error_and_exit(f"Telemetry initialization failed: {e}", fix="Check your telemetry configuration.", verbose=getattr(args, 'verbose', False))

    if args.command == "run":
        run_command(args)
    elif args.command == "history":
        history_command(args)
    elif args.command == "status":
        status_command(args)
    elif args.command == "install":
        install_command(args)
    elif args.command == "batch":
        batch_command(args)
    elif args.command == "report":
        report_command(args)
    elif args.command == "ci":
        ci_command(args)
    elif args.command == "remote":
        remote_command(args)
    elif args.command == "init":
        init_command(args)
    elif args.command == "quickstart":
        quickstart_command(args)
    elif args.command == "cloud":
        cloud_command(args)
    elif args.command == "doctor":
        doctor_command(args)
    elif args.command == "db":
        db_command(args)
    elif args.command == "diagnose":
        diagnose_command(args)
    elif args.command == "investigate":
        investigate_command(args)
    elif args.command == "investigate-migrate":
        investigate_migrate_command(args)
    elif args.command == "show-telemetry":
        show_telemetry_command(args)
    elif args.command == "config":
        config_command(args)
    elif args.command == "reset-runs":
        reset_runs_command(args)
    elif args.command == "dashboard":
        dashboard_command(args)
    elif args.command == "setup":
        setup_command(args)
    elif args.command == "support-bundle":
        support_bundle_command(args)
    elif args.command == "upgrade-check":
        upgrade_check_command(args)
    elif args.command == "ai-assist":
        ai_assist_command(args)
    elif args.command == "escalate":
        escalate_command(args)
    elif args.command == "telemetry":
        telemetry_command(args)
    else:
        print_banner()
        show_first_run_guide = _load_config().get("first_run_notice_shown", False) is False
        if show_first_run_guide:
            print_first_run_guide()
        parser.print_help()


if __name__ == "__main__":
    main()
