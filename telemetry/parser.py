from pathlib import Path


class TelemetryParser:

    def __init__(self, reports_dir):

        self.reports_dir = Path(reports_dir)

    def parse_timing(self):

        timing_file = (
            self.reports_dir / "timing.rpt"
        )

        metrics = {}

        with open(timing_file, "r") as f:

            lines = f.readlines()

        for line in lines:

            if "WNS:" in line:

                metrics["wns"] = float(
                    line.split(":")[1].strip()
                )

            if "TNS:" in line:

                metrics["tns"] = float(
                    line.split(":")[1].strip()
                )

        return metrics

    def parse_utilization(self):

        util_file = (
            self.reports_dir /
            "utilization.rpt"
        )

        metrics = {}

        with open(util_file, "r") as f:

            lines = f.readlines()

        for line in lines:

            if "Core Utilization:" in line:

                value = (
                    line.split(":")[1]
                    .replace("%", "")
                    .strip()
                )

                metrics["utilization"] = (
                    float(value)
                )

            if "Total Cells:" in line:

                metrics["cell_count"] = int(
                    line.split(":")[1].strip()
                )

        return metrics

    def parse_runtime(self):

        runtime_file = (
            self.reports_dir /
            "runtime.rpt"
        )

        metrics = {}

        with open(runtime_file, "r") as f:

            lines = f.readlines()

        for line in lines:

            if "Total Runtime:" in line:

                value = (
                    line.split(":")[1]
                    .replace("sec", "")
                    .strip()
                )

                metrics["runtime_sec"] = (
                    float(value)
                )

        return metrics

    def parse_all(self):

        metrics = {}

        metrics.update(
            self.parse_timing()
        )

        metrics.update(
            self.parse_utilization()
        )

        metrics.update(
            self.parse_runtime()
        )

        return metrics
