from rich.console import Console
from rich.table import Table
from rich.panel import Panel
from rich.layout import Layout
from rich.columns import Columns
from rich import box

console = Console()

LVS_DISCLAIMER = (
    "LVS PASS verifies that the physical layout matches the schematic netlist.\n"
    "It does NOT verify functional correctness, timing, or that the RTL behaves as intended.\n"
    "Functional verification (simulation/formal) must be completed separately before tapeout."
)


def print_banner():
    console.print()
    console.print(
        "[bold green]  GLI-FLOW  [/bold green]"
        " [dim]Execution Intelligence Infrastructure[/dim]"
    )
    console.print("[dim]RTL-to-GDS Silicon Pipeline[/dim]")
    console.print()


def print_run_header(run_id, design_name, run_dir):
    layout = Layout()
    layout.split_row(
        Layout(Panel(f"[bold]Run ID[/bold]\n{run_id}", box=box.ROUNDED)),
        Layout(Panel(f"[bold]Design[/bold]\n{design_name}", box=box.ROUNDED)),
        Layout(Panel(f"[bold]Output[/bold]\n{run_dir}", box=box.ROUNDED)),
    )
    console.print(layout)
    console.print()


def print_stage_progress(stage, progress, status="RUNNING"):
    color = {"RUNNING": "yellow", "SUCCESS": "green", "FAILED": "red"}.get(status, "white")
    bar_len = 20
    filled = int(progress / 100 * bar_len)
    bar = "█" * filled + "░" * (bar_len - filled)
    console.print(f"  [{color}]{stage:<18}[/{color}] {bar} {progress:>3}%")


def print_results(record):
    table = Table(box=box.SIMPLE)
    table.add_column("Metric", style="cyan")
    table.add_column("Value", style="white")

    qor_color = "green" if record.qor_score and record.qor_score >= 0.7 else "red"
    table.add_row("QoR Score", f"[{qor_color}]{record.qor_score}[/{qor_color}]")
    table.add_row("WNS", str(record.wns) if record.wns is not None else "N/A")
    table.add_row("TNS", str(record.tns) if record.tns is not None else "N/A")
    hold_wns = getattr(record, "hold_wns", None)
    if hold_wns is not None:
        hold_color = "green" if hold_wns >= 0 else "red"
        hold_label = "✓" if hold_wns >= 0 else "✗ TAPEOUT BLOCKER"
        table.add_row("Hold WNS", f"[{hold_color}]{hold_wns:.3f} ns {hold_label}[/{hold_color}]")
    table.add_row("Utilization", f"{record.utilization}%" if record.utilization is not None else "N/A")
    table.add_row("Cell Count", str(record.cell_count) if record.cell_count is not None else "N/A")
    table.add_row("Runtime", f"{record.runtime_sec}s" if record.runtime_sec is not None else "N/A")

    console.print(table)

    lvs_is_clean = getattr(record, "lvs_is_clean", None)
    if lvs_is_clean is True:
        console.print(f"  [green]✓ LVS PASS[/green]")
        console.print(f"\n  [dim]ℹ {LVS_DISCLAIMER}[/dim]")
    elif lvs_is_clean is False:
        console.print(f"  [red]✗ LVS FAIL[/red]")

    console.print()


def print_regression(regression):
    if not regression["regression_detected"]:
        return

    console.print("[bold yellow]REGRESSION ALERTS[/bold yellow]")
    for alert in regression["alerts"]:
        console.print(f"  [yellow]![/yellow] {alert}")
    console.print()


def print_error(message):
    console.print(f"[bold red]ERROR:[/bold red] {message}")


def print_warning(message):
    console.print(f"[bold yellow]WARN:[/bold yellow] {message}")


def print_run_history(runs):
    if not runs:
        console.print("[dim]No runs found.[/dim]")
        return

    table = Table(box=box.SIMPLE)
    table.add_column("Run ID", style="cyan", no_wrap=True)
    table.add_column("Design", style="green")
    table.add_column("Status", style="white")
    table.add_column("QoR", style="white")
    table.add_column("Timestamp")

    for run in runs:
        qor = f"{run['qor_score']:.2f}" if run.get("qor_score") is not None else "N/A"
        status_color = {
            "SUCCESS": "green",
            "FAILED": "red",
            "TIMEOUT": "yellow",
            "RUNNING": "cyan",
        }.get(run.get("status", ""), "white")

        table.add_row(
            run.get("run_id", "")[:20],
            run.get("design_name", ""),
            f"[{status_color}]{run.get('status', '')}[/{status_color}]",
            qor,
            run.get("timestamp", ""),
        )

    console.print(table)


def print_report(metrics):
    console.print("[bold]QoR Report[/bold]")
    console.print()

    grid = Table.grid(padding=(0, 2))
    grid.add_column()
    grid.add_column()

    left = Table(box=box.SIMPLE)
    left.add_column("Metric", style="cyan")
    left.add_column("Value", style="white")

    right = Table(box=box.SIMPLE)
    right.add_column("Metric", style="cyan")
    right.add_column("Value", style="white")

    def v(val, fmt=None):
        if val is None:
            return "N/A"
        if fmt:
            return fmt(val)
        return str(val)

    def color_slack(s):
        if s is None or s == "N/A":
            return "N/A"
        s = float(s)
        c = "green" if s >= 0 else "red"
        return f"[{c}]{s:.3f}[/{c}]"

    left.add_row("Design", metrics.get("design", "N/A"))
    left.add_row("Platform", metrics.get("platform", "N/A"))
    left.add_row("Die Area", v(metrics.get("die_area_um2"), lambda x: f"{x:,.0f} µm²"))
    left.add_row("Cell Area", v(metrics.get("cell_area_um2"), lambda x: f"{x:,.0f} µm²"))
    left.add_row("Utilization", v(metrics.get("utilization_pct"), lambda x: f"{x:.1f}%"))
    left.add_row("Cell Count", v(metrics.get("cell_count"), lambda x: f"{x:,}"))
    left.add_row("Port Bits (Pins)", v(metrics.get("pin_count")))
    left.add_row("---", "---")
    left.add_row("Worst Slack", v(metrics.get("worst_slack"), color_slack))
    left.add_row("WNS", v(metrics.get("wns"), color_slack))
    left.add_row("TNS", v(metrics.get("tns"), color_slack))
    left.add_row("Critical Path", v(metrics.get("critical_path_ns"), lambda x: f"{x:.2f} ns"))
    left.add_row("Fmax", v(metrics.get("fmax_mhz"), lambda x: f"{x:.0f} MHz"))

    right.add_row("Total Power", v(metrics.get("total_power_w"), lambda x: f"{x*1000:.1f} mW"))
    right.add_row("  Sequential", v(metrics.get("seq_power_w"), lambda x: f"{x*1000:.1f} mW"))
    right.add_row("  Combinational", v(metrics.get("comb_power_w"), lambda x: f"{x*1000:.1f} mW"))
    right.add_row("  Clock", v(metrics.get("clock_power_w"), lambda x: f"{x*1000:.1f} mW"))
    right.add_row("---", "---")
    right.add_row("Setup Violations", v(metrics.get("setup_violations")))
    right.add_row("Hold Violations", v(metrics.get("hold_violations")))
    right.add_row("Max Fanout Violations", v(metrics.get("fanout_violations")))
    right.add_row("Max Cap Violations", v(metrics.get("cap_violations")))
    right.add_row("Max Slew Violations", v(metrics.get("slew_violations")))
    right.add_row("---", "---")
    right.add_row("Clock Skew", v(metrics.get("clock_skew_ns"), lambda x: f"{x:.3f} ns"))
    right.add_row("Runtime", v(metrics.get("runtime_sec"), lambda x: f"{x:.0f}s"))

    grid.add_row(left, right)
    console.print(grid)
    console.print()

    if metrics.get("setup_violations") and int(metrics["setup_violations"]) > 0:
        console.print("[red]✗[/red] Setup violations present — design may not meet timing")
    if metrics.get("hold_violations") and int(metrics["hold_violations"]) > 0:
        console.print("[yellow]⚠[/yellow] Hold violations present — may require ECO fixes")
    if metrics.get("fanout_violations") and int(metrics["fanout_violations"]) > 0:
        console.print("[yellow]⚠[/yellow] Fanout violations present — clock tree may need tuning")


def print_install_report(report):
    console.print("[bold]Installation Summary[/bold]")
    console.print()

    for name in report.completed:
        console.print(f"  [green]✓[/green] {name}")
    for name in report.skipped:
        console.print(f"  [dim]─[/dim] {name} [dim](already installed)[/dim]")
    for name in report.failed:
        console.print(f"  [red]✗[/red] {name}")

    console.print()
    console.print("[bold]Validation Results[/bold]")

    table = Table(box=box.SIMPLE)
    table.add_column("Tool", style="cyan")
    table.add_column("Status", style="white")
    table.add_column("Version", style="white")

    for v in report.validations:
        status = "[green]OK[/green]" if v.ok else "[red]MISSING[/red]"
        table.add_row(v.tool, status, v.version or "—")

    console.print(table)
    console.print()

    if report.success:
        console.print("[bold green]All components installed successfully[/bold green]")
    else:
        console.print(f"[bold red]{len(report.failed)} component(s) failed[/bold red]")
