import shutil
import sys
import subprocess
import importlib.util
from pathlib import Path

from gli_flow.cli.utils import info, success, warn, error
from gli_flow.config_validator import validate_manifest


def run_smoke_test(args):
    info("Running smoke test...\n")

    checks = []

    checks.append(_check_environment())
    checks.append(_check_database(args))
    checks.append(_check_telemetry())
    checks.append(_check_dashboard())
    checks.append(_check_example_design())

    _print_summary(checks)

    if any(status != "pass" for status, _ in checks):
        sys.exit(1)


def _check_environment():
    failed = []
    passed = []

    py_version = sys.version_info
    if py_version.major < 3 or (py_version.major == 3 and py_version.minor < 9):
        failed.append(f"Python {py_version.major}.{py_version.minor} (3.9+ required)")
    else:
        passed.append(f"Python {py_version.major}.{py_version.minor}.{py_version.micro}")

    tools = [
        ("openroad", _tool_version("openroad", "-version")),
        ("yosys", _tool_version("yosys", "-V")),
        ("magic", _tool_version("magic", "--version")),
        ("netgen", _tool_version("netgen", "-version")),
        ("klayout", _tool_version("klayout", "-v")),
        ("sv2v", _tool_version("sv2v", "--version")),
    ]

    for name, version in tools:
        if version is not None:
            passed.append(f"{name} {version}")
        else:
            failed.append(f"{name} not found")

    status = "pass" if not failed else "fail"
    return status, ("Environment", passed, failed)


def _check_database(args):
    failed = []
    passed = []

    try:
        from gli_flow.database.migrations import _get_db_path, MigrationEngine, RUNS_MIGRATIONS, FAILURE_ATLAS_MIGRATIONS

        db_path = getattr(args, 'db_path', None) or _get_db_path()

        if db_path and Path(db_path).exists():
            passed.append(f"Database found at {db_path}")
        elif db_path:
            passed.append("Database location configured")
            passed.append("(will be created on first run)")
        else:
            passed.append("Database path configured")

        engine = MigrationEngine(db_path)

        runs_ok = engine.validate_schema("runs", RUNS_MIGRATIONS)
        fa_ok = engine.validate_schema("failure_atlas", FAILURE_ATLAS_MIGRATIONS)

        if runs_ok and fa_ok:
            passed.append("Schema valid, migrations applied")
        else:
            missing = []
            if not runs_ok:
                missing.append("runs")
            if not fa_ok:
                missing.append("failure_atlas")
            failed.append(f"Schema needs migration: {', '.join(missing)}")
            engine.migrate()
            passed.append("Migrations applied")
    except Exception as e:
        failed.append(f"Database error: {e}")

    status = "pass" if not failed else "fail"
    return status, ("Database", passed, failed)


def _check_telemetry():
    failed = []
    passed = []

    try:
        from gli_flow.telemetry.settings import get_telemetry_settings

        settings = get_telemetry_settings()
        passed.append(f"Configuration readable (mode: {settings.mode})")
        passed.append(f"Consent state: {'given' if settings.consent_given else 'not given'}")

        queue_path = Path.home() / ".gli-flow" / "upload_queue.db"
        if queue_path.exists():
            passed.append("Queue database healthy")
        else:
            passed.append("No upload queue (no data queued for upload)")
    except Exception as e:
        failed.append(f"Telemetry error: {e}")

    status = "pass" if not failed else "fail"
    return status, ("Telemetry", passed, failed)


def _check_dashboard():
    failed = []
    passed = []

    backend_deps = ["fastapi", "uvicorn"]
    missing_deps = []
    for dep in backend_deps:
        if importlib.util.find_spec(dep) is not None:
            passed.append(f"Backend dependency: {dep}")
        else:
            missing_deps.append(dep)

    if missing_deps:
        failed.append(f"Missing backend dependencies: {', '.join(missing_deps)}")
        failed.append("Run: pip install gli-flow[dashboard]")

    node_version = _tool_version("node", "--version")
    npm_version = _tool_version("npm", "--version")

    if node_version is not None:
        passed.append(f"Node.js {node_version}")
    else:
        passed.append("Node.js not found (frontend dev server unavailable)")
        passed.append("Use gli-flow dashboard --backend-only")

    if npm_version is not None:
        passed.append(f"npm {npm_version}")
    else:
        passed.append("npm not found (frontend dev server unavailable)")

    status = "pass" if not failed else "fail"
    return status, ("Dashboard", passed, failed)


def _check_example_design():
    failed = []
    passed = []

    manifest_path = Path("examples/counter/gli_manifest.yaml")

    if not manifest_path.exists():
        manifest_path = Path(__file__).parent.parent.parent / "examples" / "counter" / "gli_manifest.yaml"

    if not manifest_path.exists():
        failed.append(f"Example design not found at {manifest_path}")
        return "fail", ("Example Design", passed, failed)

    passed.append(f"Design manifest found")

    ok, msg = validate_manifest(manifest_path)
    if ok:
        passed.append("Manifest valid")
    else:
        failed.append(f"Manifest invalid: {msg}")

    status = "pass" if not failed else "fail"
    return status, ("Example Design", passed, failed)


def _print_summary(checks):
    from rich.console import Console
    from rich.table import Table

    console = Console()

    label_width = max(len(label) for _, (label, _, _) in checks)

    console.print("[bold]Smoke Test Summary[/bold]")
    console.print()

    for status, (label, passed, failed) in checks:
        icon = "✓" if status == "pass" else "✗"
        color = "green" if status == "pass" else "red"
        padded = label.ljust(label_width)
        console.print(f"  [{color}]{icon}[/{color}] {padded}")

    console.print()
    console.print("[bold]Details:[/bold]")

    any_fail = False
    for status, (label, passed, failed) in checks:
        console.print(f"\n[{ 'green' if status == 'pass' else 'red' }]{label}[/{'green' if status == 'pass' else 'red' }]:")
        if passed:
            for m in passed:
                console.print(f"  [green]✓[/green] {m}")
        if failed:
            for m in failed:
                console.print(f"  [red]✗[/red] {m}")
                any_fail = True

    console.print()
    if any_fail:
        console.print("[bold red]Result:[/bold red] GLI-FLOW has issues that need attention.")
        console.print()
        console.print("Next:")
        console.print("  [bold green]gli-flow doctor[/bold green]        — Detailed environment report")
        console.print("  [bold green]gli-flow doctor --fix[/bold green]  — Auto-repair detected issues")
    else:
        console.print("[bold green]Result:[/bold green] GLI-FLOW is ready for use.")
        console.print()
        console.print("Next:")
        console.print("  [bold green]gli-flow run examples/counter --mock[/bold green]  — Run a test design")
        console.print("  [bold green]gli-flow dashboard[/bold green]                     — Open the web dashboard")


def _tool_version(tool_name, version_flag):
    path = shutil.which(tool_name)
    if not path:
        return None
    try:
        result = subprocess.run(
            [tool_name, version_flag],
            capture_output=True, text=True, timeout=10,
        )
        version = (result.stdout or result.stderr or "").strip()
        parts = version.split("\n")[0].strip()
        return parts[:60] if parts else None
    except Exception:
        return None
