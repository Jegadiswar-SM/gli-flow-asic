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


def run_command(args):
    design_path = args.design

    try:
        print_banner()

        orchestrator = FlowOrchestrator(
            design_path=design_path,
            threads=args.threads,
            memory_mb=args.memory,
            orfs_root=args.orfs_root,
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

    db = DatabaseManager()
    runs = db.get_recent_runs(limit=args.limit or 20)
    print_run_history(runs)


def status_command(args):
    print_banner()
    console.print("[bold]Recent Runs[/bold]")
    console.print()

    db = DatabaseManager()
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

    history_parser = subparsers.add_parser("history", help="Show execution history")
    history_parser.add_argument("--limit", type=int, default=20, help="Number of runs to show")

    subparsers.add_parser("status", help="Show recent run status")

    batch_parser = subparsers.add_parser("batch", help="Run multiple designs in parallel")
    batch_parser.add_argument("designs", nargs="+", help="Design directories with gli_manifest.yaml")
    batch_parser.add_argument("--parallel", "-j", type=int, default=1,
                              help="Number of parallel workers (default: 1)")
    batch_parser.add_argument("--threads", type=int, default=None,
                              help="Threads per worker")
    batch_parser.add_argument("--memory", type=int, default=None,
                              help="Memory limit in MB per worker")

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
    else:
        parser.print_help()


if __name__ == "__main__":
    main()
