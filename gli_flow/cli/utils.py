from rich.console import Console
import traceback

console = Console()

def success(message: str):
    console.print(f"[bold green]✓[/bold green] {message}")

def warn(message: str):
    console.print(f"[bold yellow]⚠[/bold yellow] {message}")

def info(message: str):
    console.print(f"[bold cyan]→[/bold cyan] {message}")

def error_and_exit(message: str, fix: str = None, verbose: bool = False):
    console.print(f"[bold red]✗ Error:[/bold red] {message}")
    if fix:
        console.print(f"[bold]Fix:[/bold] {fix}")
    if verbose:
        console.print_exception()
    exit(1)
