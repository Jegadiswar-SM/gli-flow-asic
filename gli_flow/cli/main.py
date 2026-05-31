import argparse
import re
import sys
import traceback
from pathlib import Path

from gli_flow.core.orchestrator import FlowOrchestrator
from gli_flow.database.sqlite import DatabaseManager
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
from gli_flow.scheduler import JobQueue, ResourceSpec, BatchRun
from gli_flow.ci import CIConfig, CIRunner
from gli_flow.scheduler.remote import RemoteWorker, RemoteWorkerConfig
from gli_flow.cloud import CloudStorageConfig, CloudStorageManager, CloudProvider


def run_command(args):
    design_path = args.design

    if not Path(design_path).exists():
        friendly_error("manifest", f"Directory not found: {design_path}")
        sys.exit(1)

    manifest_file = Path(design_path) / "gli_manifest.yaml"
    if not manifest_file.exists():
        friendly_error("manifest", f"Not found: {manifest_file}")
        sys.exit(1)

    try:
        print_banner()

        db_path = getattr(args, 'db_path', None)
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
    print_install_report(report)

    if not report.success:
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
        "    export PDK_ROOT=/pdk\n"
        "    gli-flow quickstart\n"
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
    manifest_path = Path(design_name) / "gli_manifest.yaml"
    manifest_path.parent.mkdir(parents=True, exist_ok=True)
    import yaml
    with open(manifest_path, "w") as f:
        yaml.dump(manifest, f, default_flow_style=False)
    print(f"\n  [OK] Created {manifest_path}")
    print(f"\n  Next steps:")
    print(f"    1. Place your Verilog files in {design_name}/rtl/")
    print(f"    2. Edit {manifest_path} to match your design")
    print(f"    3. Run: gli-flow run {design_name} --mock")


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
    rtl_dir.mkdir(parents=True, exist_ok=True)

    manifest_path = design_dir / "gli_manifest.yaml"
    import yaml
    with open(manifest_path, "w") as f:
        yaml.dump(manifest, f, default_flow_style=False)

    sv_path = rtl_dir / f"{design_name}.sv"
    if not sv_path.exists():
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

    print(f"\n  [OK] Created:")
    print(f"       {manifest_path}")
    print(f"       {sv_path}")
    print(f"\n  Try it now:")
    print(f"       gli-flow run {design_name} --mock")
    print()


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
                                help="PDK install root directory (default: /pdk)")
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

    return parser


def main():
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
    else:
        parser.print_help()


if __name__ == "__main__":
    main()
