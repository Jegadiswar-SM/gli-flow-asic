import tempfile
from pathlib import Path

from gli_flow.telemetry.parser import TelemetryParser


def test_parser_init():
    p = TelemetryParser("/tmp")
    assert p.reports_dir == Path("/tmp")


def test_parse_empty_dir():
    with tempfile.TemporaryDirectory() as tmp:
        p = TelemetryParser(tmp)
        metrics = p.parse_all()
        assert metrics == {}


def test_parse_timing_rpt():
    with tempfile.TemporaryDirectory() as tmp:
        rpt = Path(tmp) / "timing.rpt"
        rpt.write_text("wns: -0.12\n")
        p = TelemetryParser(tmp)
        metrics = p.parse_timing()
        assert "wns" in metrics
        assert metrics["wns"] == -0.12


def test_parse_utilization():
    with tempfile.TemporaryDirectory() as tmp:
        rpt = Path(tmp) / "utilization.rpt"
        rpt.write_text("Core Utilization: 45.2%\nTotal Cells: 4231\n")
        p = TelemetryParser(tmp)
        metrics = p.parse_utilization()
        assert metrics["utilization"] == 45.2
        assert metrics["cell_count"] == 4231


def test_parse_runtime():
    with tempfile.TemporaryDirectory() as tmp:
        rpt = Path(tmp) / "runtime.rpt"
        rpt.write_text("Total Runtime: 89.4 sec\n")
        p = TelemetryParser(tmp)
        metrics = p.parse_runtime()
        assert metrics["runtime_sec"] == 89.4
