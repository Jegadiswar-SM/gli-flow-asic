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
)
from gli_flow.installer import Installer
from gli_flow.scheduler import JobQueue, ResourceSpec
from gli_flow.ci import CIConfig, CIRunner
from gli_flow.scheduler.remote import RemoteWorker, RemoteWorkerConfig
from gli_flow.cloud import CloudStorageConfig, CloudStorageManager, CloudProvider
from gli_flow.config_validator import validate_manifest
from gli_flow.parser.rtl_parser import detect_from_directory, parse_file, scan_directory
from gli_flow.infrastructure.environment_validator import EnvironmentValidator
from gli_flow.infrastructure.repair_actions import run_repairs


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


def _show_first_run_notice():
    """Show telemetry notice on first run."""
    from rich.panel import Panel

    config = _load_config()
    if config.get("first_run_notice_shown"):
        return

    console.print(Panel(
        "[bold]Telemetry Notice[/bold]\n\n"
        "GLI-FLOW collects anonymized execution metrics (WNS, TNS, runtime, cell count).\n"
        "Your RTL, GDS, and design data are [bold]never[/bold] transmitted.\n\n"
        "To opt out: [bold green]gli-flow config --telemetry off[/bold green]\n"
        "To inspect: [bold green]gli-flow show-telemetry --run <id>[/bold green]\n\n"
        "Full details: tapeitout.com/privacy",
        title="Telemetry",
        border_style="blue"
    ))

    config["first_run_notice_shown"] = True
    _save_config(config)


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
    _show_first_run_notice()
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

        if record.status == "FAILED":
            print_error(f"Execution failed for {design_path}")
            sys.exit(1)

        console.print(f"[bold green]SUCCESS[/bold green] — {orchestrator.run_dir}")
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


def doctor_command(args):
    from gli_flow.infrastructure.environment_validator import EnvironmentValidator

    db_path = getattr(args, 'db_path', None)
    validator = EnvironmentValidator(db_path=db_path, backend="local")

    if getattr(args, 'fix', False):
        console.print("[bold]Running auto-repair...[/bold]\n")
        repair_results = run_repairs(db_path=db_path)
        for result in repair_results:
            status = "[green]OK[/green]" if result.success else "[red]FAIL[/red]"
            console.print(f"  {status} {result.action}: {result.detail}")
            if result.requires_restart:
                console.print(f"    [yellow]Restart required:[/yellow] {result.detail}")
        console.print()
        console.print("[bold]Re-checking after repairs...[/bold]\n")

    report = _doctor_output(validator)

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

    c.print(f"\n[bold]Diagnosing run: {run_id}[/bold]")

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

    if not findings:
        c.print("[yellow]No specific failure pattern detected. Check logs manually:[/yellow]\n"
                f"  {run_dir / 'logs'}")
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
    from datetime import datetime

    cfg_dir = _ensure_config_dir()
    bundle_name = args.output or f"gli-flow-support-bundle-{datetime.now().strftime('%Y%m%d_%H%M%S')}.zip"
    bundle_path = Path(bundle_name)
    if not bundle_path.suffix:
        bundle_path = bundle_path.with_suffix(".zip")

    console.print(f"[cyan]Generating support bundle: {bundle_path}[/cyan]")

    files_to_include = []

    # Config
    for cfg_file in ["config.yaml", "config.json"]:
        p = cfg_dir / cfg_file
        if p.exists():
            files_to_include.append((str(p), f"config/{cfg_file}"))

    # Environment fingerprint
    for p in [Path("run_environment.json"), cfg_dir / "environment.json"]:
        if p.exists():
            files_to_include.append((str(p), f"environment/{p.name}"))

    # Doctor output
    try:
        from gli_flow.doctor import run_doctor
        report = run_doctor(db_path=getattr(args, 'db_path', None))
        doctor_path = cfg_dir / "doctor_output.json"
        with open(doctor_path, "w") as f:
            json.dump(report.to_dict() if hasattr(report, 'to_dict') else str(report), f, indent=2)
        files_to_include.append((str(doctor_path), "diagnostics/doctor_output.json"))
    except Exception:
        pass

    # Logs
    logs_dir = Path("logs")
    if logs_dir.exists():
        for log_file in sorted(logs_dir.rglob("*.log"))[:20]:
            files_to_include.append((str(log_file), f"logs/{log_file.relative_to(logs_dir)}"))

    # Recent run summaries
    if args.run_id:
        try:
            db = DatabaseManager(db_path=getattr(args, 'db_path', None))
            run = db.get_run(args.run_id)
            if run:
                run_dir = Path(run.get("run_dir", ""))
                if run_dir.exists():
                    for f in run_dir.rglob("*"):
                        if f.is_file() and f.suffix in (".log", ".json", ".rpt", ".md"):
                            files_to_include.append((str(f), f"run/{f.relative_to(run_dir)}"))
        except Exception:
            pass

    # Version info
    from gli_flow.version import VERSION
    version_info = {"gli_flow_version": VERSION}
    version_path = cfg_dir / "version_info.json"
    with open(version_path, "w") as f:
        json.dump(version_info, f, indent=2)
    files_to_include.append((str(version_path), "diagnostics/version_info.json"))

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


def build_parser():
    parser = argparse.ArgumentParser(
        prog="gli-flow",
        description="GLI-FLOW — RTL-to-GDS Silicon Pipeline",
    )

    subparsers = parser.add_subparsers(dest="command")

    run_parser = subparsers.add_parser("run", help="Run a design through the flow")
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

    history_parser = subparsers.add_parser("history", help="Show execution history")
    history_parser.add_argument("--limit", type=int, default=20, help="Number of runs to show")
    history_parser.add_argument("--db-path", type=str, default=None,
                                help="Path to SQLite database (default: gli_flow.db or $GLI_FLOW_DB_PATH)")

    status_parser = subparsers.add_parser("status", help="Show recent run status")
    status_parser.add_argument("--db-path", type=str, default=None,
                               help="Path to SQLite database (default: gli_flow.db or $GLI_FLOW_DB_PATH)")

    batch_parser = subparsers.add_parser("batch", help="Run multiple designs in parallel")
    batch_parser.add_argument("designs", nargs="+", help="Design directories with gli_manifest.yaml")
    batch_parser.add_argument("--parallel", "-j", type=int, default=1,
                              help="Number of parallel workers (default: 1)")
    batch_parser.add_argument("--threads", type=int, default=None,
                              help="Threads per worker")
    batch_parser.add_argument("--memory", type=int, default=None,
                              help="Memory limit in MB per worker")

    init_parser = subparsers.add_parser("init", help="Create a new design manifest")
    init_parser.add_argument("design_name", help="Name of the design (creates a directory and manifest)")
    init_parser.add_argument("--rtl-dir", type=str, default=None,
                              help="Path to RTL directory to auto-detect top module, ports, and files")
    init_parser.add_argument("--rtl", type=str, default=None,
                              help="Path to a single RTL file to auto-detect top module and ports")

    quickstart_parser = subparsers.add_parser("quickstart", help="Interactive setup wizard for new designs")

    report_parser = subparsers.add_parser("report", help="Show QoR report for a completed ORFS run")
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

    install_parser = subparsers.add_parser("install", help="Install gli-flow and all EDA toolchain dependencies")
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

    ci_parser = subparsers.add_parser("ci", help="Run a design in CI mode with JUnit/Markdown output")
    ci_parser.add_argument("design", help="Path to design directory with gli_manifest.yaml")
    ci_parser.add_argument("--junit", type=str, default=None, help="Path to write JUnit XML report")
    ci_parser.add_argument("--markdown", type=str, default=None, help="Path to write Markdown report")
    ci_parser.add_argument("--baseline", type=str, default=None, help="Baseline run ID for comparison")
    ci_parser.add_argument("--qor-min", type=float, default=None, help="Minimum acceptable QoR score")
    ci_parser.add_argument("--wns-max", type=float, default=None, help="Maximum acceptable WNS (ns)")
    ci_parser.add_argument("--verbose", "-v", action="store_true", help="Show verbose output")

    remote_parser = subparsers.add_parser("remote", help="Run a design on a remote machine via SSH")
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

    cloud_parser = subparsers.add_parser("cloud", help="Upload/download run artifacts to/from cloud storage")
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

    doctor_parser = subparsers.add_parser("doctor", help="Validate installed EDA toolchain and produce health report")
    doctor_parser.add_argument("--fix", action="store_true", help="Attempt to auto-repair detected issues")
    doctor_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    db_parser = subparsers.add_parser("db", help="Database schema management")
    db_subparsers = db_parser.add_subparsers(dest="db_action")
    db_status_parser = db_subparsers.add_parser("status", help="Show database schema migration status")
    db_status_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")
    db_migrate_parser = db_subparsers.add_parser("migrate", help="Apply pending database migrations")
    db_migrate_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")
    db_repair_parser = db_subparsers.add_parser("repair", help="Repair database schema version tracking")
    db_repair_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")
    db_path_parser = db_subparsers.add_parser("path", help="Show database file path")
    db_path_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    diagnose_parser = subparsers.add_parser("diagnose", help="Diagnose a failed run by scanning stage logs")
    diagnose_parser.add_argument("run_id", help="Run ID to diagnose")
    diagnose_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    show_telemetry_parser = subparsers.add_parser("show-telemetry", help="Show exact telemetry payload that would be uploaded (no data sent)")
    show_telemetry_parser.add_argument("run_id", help="Run ID to inspect")
    show_telemetry_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    config_parser = subparsers.add_parser("config", help="View or change GLI-FLOW configuration")
    config_parser.add_argument("--telemetry", choices=["on", "off"], default=None, help="Enable or disable telemetry")

    dashboard_parser = subparsers.add_parser("dashboard", help="Start the GLI-FLOW dashboard")
    dashboard_parser.add_argument("--backend-only", action="store_true", help="Start backend only, skip frontend dev server")

    setup_parser = subparsers.add_parser("setup", help="Interactive first-time setup — configure PDK, tools, workspace")
    setup_parser.add_argument("--pdk-root", type=str, default=None, help="PDK install root directory")
    setup_parser.add_argument("--workspace", type=str, default=None, help="Workspace directory for designs and runs")
    setup_parser.add_argument("--telemetry", choices=["on", "off"], default=None, help="Telemetry consent")
    setup_parser.add_argument("--non-interactive", action="store_true", help="Skip interactive prompts, use defaults or flags")

    support_bundle_parser = subparsers.add_parser("support-bundle", help="Generate a support bundle archive for debugging")
    support_bundle_parser.add_argument("--output", "-o", type=str, default=None, help="Output path for support bundle zip")
    support_bundle_parser.add_argument("--run-id", type=str, default=None, help="Include specific run ID's artifacts")
    support_bundle_parser.add_argument("--db-path", type=str, default=None, help="Path to SQLite database")

    upgrade_check_parser = subparsers.add_parser("upgrade-check", help="Check for newer versions of GLI-FLOW")

    return parser


def main():
    setup_logging()
    parser = build_parser()
    args = parser.parse_args()

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
    elif args.command == "show-telemetry":
        show_telemetry_command(args)
    elif args.command == "config":
        config_command(args)
    elif args.command == "dashboard":
        dashboard_command(args)
    elif args.command == "setup":
        setup_command(args)
    elif args.command == "support-bundle":
        support_bundle_command(args)
    elif args.command == "upgrade-check":
        upgrade_check_command(args)
    else:
        parser.print_help()


if __name__ == "__main__":
    main()
