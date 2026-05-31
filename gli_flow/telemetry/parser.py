import csv
import os
import re

from pathlib import Path


class TelemetryParser:

    def __init__(self, reports_dir):
        self.reports_dir = Path(reports_dir)

    def _safe_read_lines(self, path):
        try:
            with open(path, "r") as f:
                return f.readlines()
        except (FileNotFoundError, OSError):
            return []

    def _parse_key_value_lines(self, lines, separators=(":",)):
        metrics = {}
        for line in lines:
            for sep in separators:
                if sep in line:
                    parts = line.split(sep, 1)
                    key = parts[0].strip()
                    raw = parts[1].strip()
                    try:
                        value = float(raw.replace("%", "").replace("sec", "").strip())
                        metrics[key.lower().replace(" ", "_")] = value
                    except ValueError:
                        try:
                            value = int(raw)
                            metrics[key.lower().replace(" ", "_")] = value
                        except ValueError:
                            pass
                    break
        return metrics

    def _parse_csv(self, path):
        metrics = {}
        try:
            with open(path, newline="") as f:
                reader = csv.reader(f)
                for row in reader:
                    if len(row) >= 2:
                        key = row[0].strip().lower().replace(" ", "_")
                        raw = row[1].strip()
                        try:
                            metrics[key] = float(raw)
                        except ValueError:
                            try:
                                metrics[key] = int(raw)
                            except ValueError:
                                pass
        except (FileNotFoundError, OSError):
            pass
        return metrics

    def parse_timing(self):
        metrics = {}

        csv_path = self.reports_dir / "metrics.csv"
        if csv_path.exists():
            parsed = self._parse_csv(csv_path)
            if "wns" in parsed:
                metrics["wns"] = parsed["wns"]
            if "tns" in parsed:
                metrics["tns"] = parsed["tns"]

        timing_file = self.reports_dir / "timing.rpt"
        if timing_file.exists():
            lines = self._safe_read_lines(timing_file)
            parsed = self._parse_key_value_lines(lines)
            key_map = {"wns": "wns", "tns": "tns"}
            for k, v in parsed.items():
                if k in key_map:
                    metrics[key_map[k]] = v

        metrics_file = self.reports_dir / "metrics.rpt"
        if metrics_file.exists():
            lines = self._safe_read_lines(metrics_file)
            parsed = self._parse_key_value_lines(lines)
            if "wns" not in metrics and "wns" in parsed:
                metrics["wns"] = parsed["wns"]
            if "tns" not in metrics and "tns" in parsed:
                metrics["tns"] = parsed["tns"]

        return metrics

    def parse_utilization(self):
        metrics = {}

        csv_path = self.reports_dir / "metrics.csv"
        if csv_path.exists():
            parsed = self._parse_csv(csv_path)
            if "utilization" in parsed:
                metrics["utilization"] = parsed["utilization"]
            if "cell_count" in parsed:
                metrics["cell_count"] = int(parsed["cell_count"])

        util_file = self.reports_dir / "utilization.rpt"
        if util_file.exists():
            lines = self._safe_read_lines(util_file)
            for line in lines:
                if "Core Utilization:" in line:
                    try:
                        value = float(line.split(":")[1].replace("%", "").strip())
                        metrics["utilization"] = value
                    except (ValueError, IndexError):
                        pass
                if "Total Cells:" in line:
                    try:
                        metrics["cell_count"] = int(line.split(":")[1].strip())
                    except (ValueError, IndexError):
                        pass

        metrics_file = self.reports_dir / "metrics.rpt"
        if metrics_file.exists():
            lines = self._safe_read_lines(metrics_file)
            for line in lines:
                if "utilization" not in metrics and "Utilization:" in line:
                    try:
                        value = float(line.split(":")[1].replace("%", "").strip())
                        metrics["utilization"] = value
                    except (ValueError, IndexError):
                        pass
                if "cell_count" not in metrics and "Total Cells:" in line:
                    try:
                        metrics["cell_count"] = int(line.split(":")[1].strip())
                    except (ValueError, IndexError):
                        pass

        return metrics

    def parse_runtime(self):
        metrics = {}

        csv_path = self.reports_dir / "metrics.csv"
        if csv_path.exists():
            parsed = self._parse_csv(csv_path)
            if "runtime_sec" in parsed:
                metrics["runtime_sec"] = parsed["runtime_sec"]

        runtime_file = self.reports_dir / "runtime.rpt"
        if runtime_file.exists():
            lines = self._safe_read_lines(runtime_file)
            for line in lines:
                if "Total Runtime:" in line:
                    try:
                        value = float(line.split(":")[1].replace("sec", "").strip())
                        metrics["runtime_sec"] = value
                    except (ValueError, IndexError):
                        pass

        return metrics

    def parse_drc_report(self, drc_log_path: str) -> dict:
        drc_path = Path(drc_log_path)
        if not drc_path.exists():
            return {"drc_total_violations": 0, "drc_by_category": {}, "drc_locations": [], "drc_is_clean": True}
        try:
            text = drc_path.read_text()
        except OSError:
            return {"drc_total_violations": 0, "drc_by_category": {}, "drc_locations": [], "drc_is_clean": True}
        total = 0
        by_rule = {}
        locations = []
        for line in text.splitlines():
            if line.startswith("DRC_TOTAL:"):
                try:
                    total = int(line.split(":")[1].strip())
                except (ValueError, IndexError):
                    pass
            elif line.startswith("VIOLATION:"):
                parts = line[len("VIOLATION:"):].strip().split()
                if len(parts) >= 2:
                    rule = parts[0]
                    layer = parts[1]
                    by_rule[rule] = by_rule.get(rule, 0) + 1
                    coords = {}
                    if len(parts) > 2:
                        coord_text = " ".join(parts[2:])
                        cm = re.search(r'\(([-\d.]+)\s+([-\d.]+)\)\s*\(([-\d.]+)\s+([-\d.]+)\)', coord_text)
                        if cm:
                            coords = {"x1": float(cm.group(1)), "y1": float(cm.group(2)),
                                      "x2": float(cm.group(3)), "y2": float(cm.group(4))}
                    locations.append({"rule": rule, "layer": layer, **coords})
        return {
            "drc_total_violations": total,
            "drc_by_category": by_rule,
            "drc_locations": locations,
            "drc_is_clean": total == 0,
        }

    def parse_lvs_report(self, lvs_comp_path: str) -> dict:
        lvs_path = Path(lvs_comp_path)
        if not lvs_path.exists():
            return {"lvs_result": "ERROR", "lvs_unmatched_devices": 0, "lvs_unmatched_nets": 0,
                    "lvs_short_count": 0, "lvs_open_count": 0, "lvs_is_clean": False}
        try:
            text = lvs_path.read_text()
        except OSError:
            return {"lvs_result": "ERROR", "lvs_unmatched_devices": 0, "lvs_unmatched_nets": 0,
                    "lvs_short_count": 0, "lvs_open_count": 0, "lvs_is_clean": False}
        result = "FAIL"
        unmatched_devices = 0
        unmatched_nets = 0
        short_count = 0
        open_count = 0
        for line in text.splitlines():
            if "Circuits match uniquely" in line:
                result = "CLEAN"
            m = re.search(r"Unmatched Devices:\s+(\d+)", line)
            if m:
                unmatched_devices = int(m.group(1))
            m = re.search(r"Unmatched Nets:\s+(\d+)", line)
            if m:
                unmatched_nets = int(m.group(1))
            m = re.search(r"Shorts:\s+(\d+)", line)
            if m:
                short_count = int(m.group(1))
            m = re.search(r"Opens?\s*:\s*(\d+)", line)
            if m:
                open_count = int(m.group(1))
        is_clean = result == "CLEAN" and unmatched_devices == 0 and unmatched_nets == 0
        return {
            "lvs_result": result,
            "lvs_unmatched_devices": unmatched_devices,
            "lvs_unmatched_nets": unmatched_nets,
            "lvs_short_count": short_count,
            "lvs_open_count": open_count,
            "lvs_is_clean": is_clean,
        }

    def parse_power_report(self, power_report_path: str) -> dict:
        power_path = Path(power_report_path)
        if not power_path.exists():
            return {"total_power_mw": 0.0, "leakage_mw": 0.0, "internal_mw": 0.0, "switching_mw": 0.0,
                    "max_ir_drop_mv": None, "mean_ir_drop_mv": None, "ir_violation_count": 0}
        try:
            text = power_path.read_text()
        except OSError:
            return {"total_power_mw": 0.0, "leakage_mw": 0.0, "internal_mw": 0.0, "switching_mw": 0.0,
                    "max_ir_drop_mv": None, "mean_ir_drop_mv": None, "ir_violation_count": 0}
        total = 0.0
        leakage = 0.0
        internal = 0.0
        switching = 0.0
        for line in text.splitlines():
            m = re.search(r"Total\s+([\d.]+)\s+([\d.]+)\s+([\d.]+)\s+([\d.]+)", line)
            if m:
                internal = float(m.group(1))
                switching = float(m.group(2))
                leakage = float(m.group(3))
                total = float(m.group(4))
        return {
            "total_power_mw": total, "leakage_mw": leakage,
            "internal_mw": internal, "switching_mw": switching,
            "max_ir_drop_mv": None, "mean_ir_drop_mv": None, "ir_violation_count": 0,
        }

    def parse_em_report(self, em_report_path: str) -> dict:
        em_path = Path(em_report_path)
        if not em_path.exists():
            return {"em_total_violations": 0, "em_max_current_density_ma_um": 0.0, "em_is_clean": True}
        try:
            text = em_path.read_text()
        except OSError:
            return {"em_total_violations": 0, "em_max_current_density_ma_um": 0.0, "em_is_clean": True}
        violations = 0
        max_cd = 0.0
        for line in text.splitlines():
            if "EM Violation" in line or "EM violation" in line:
                violations += 1
                m = re.search(r"([\d.]+)\s*\(limit\s+([\d.]+)\)", line)
                if m:
                    max_cd = max(max_cd, float(m.group(1)))
            m = re.search(r"Max\s+current\s+density\s*:\s*([\d.]+)", line, re.IGNORECASE)
            if m:
                max_cd = max(max_cd, float(m.group(1)))
        return {
            "em_total_violations": violations,
            "em_max_current_density_ma_um": max_cd,
            "em_is_clean": violations == 0,
        }

    def parse_decap_report(self, decap_log_path: str) -> dict:
        decap_path = Path(decap_log_path)
        if not decap_path.exists():
            return {"decap_total_cells": 0, "decap_capacitance_pf": 0.0, "decap_coverage_pct": 0.0}
        try:
            text = decap_path.read_text()
        except OSError:
            return {"decap_total_cells": 0, "decap_capacitance_pf": 0.0, "decap_coverage_pct": 0.0}
        total = 0
        cap = 0.0
        for line in text.splitlines():
            m = re.search(r"Inserted\s+(\d+)\s+decap\s+cells", line, re.IGNORECASE)
            if m:
                total = int(m.group(1))
            m = re.search(r"Decap\s+capacitance\s*:\s*([\d.]+)", line, re.IGNORECASE)
            if m:
                cap = float(m.group(1))
        return {
            "decap_total_cells": total,
            "decap_capacitance_pf": cap,
            "decap_coverage_pct": min(100.0, total * 0.5),
        }

    def parse_scan_report(self, scan_log_path: str) -> dict:
        scan_path = Path(scan_log_path)
        if not scan_path.exists():
            return {"scan_total_flops": 0, "scan_scanned_flops": 0, "scan_coverage_pct": 0.0}
        try:
            text = scan_path.read_text()
        except OSError:
            return {"scan_total_flops": 0, "scan_scanned_flops": 0, "scan_coverage_pct": 0.0}
        total = 0
        scanned = 0
        for line in text.splitlines():
            m = re.search(r"Total\s+flip.flops\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                total = int(m.group(1))
            m = re.search(r"Scanned\s+flip.flops\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                scanned = int(m.group(1))
        coverage = (scanned / total * 100.0) if total else 0.0
        return {
            "scan_total_flops": total,
            "scan_scanned_flops": scanned,
            "scan_coverage_pct": coverage,
        }

    def parse_atpg_report(self, atpg_report_path: str) -> dict:
        atpg_path = Path(atpg_report_path)
        if not atpg_path.exists():
            return {"atpg_total_patterns": 0, "atpg_fault_coverage_pct": 0.0, "atpg_detected_faults": 0}
        try:
            text = atpg_path.read_text()
        except OSError:
            return {"atpg_total_patterns": 0, "atpg_fault_coverage_pct": 0.0, "atpg_detected_faults": 0}
        total_patterns = 0
        detected = 0
        total_faults = 0
        for line in text.splitlines():
            m = re.search(r"Total\s+patterns\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                total_patterns = int(m.group(1))
            m = re.search(r"Detected\s+faults\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                detected = int(m.group(1))
            m = re.search(r"Total\s+faults\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                total_faults = int(m.group(1))
        coverage = (detected / total_faults * 100.0) if total_faults else 0.0
        return {
            "atpg_total_patterns": total_patterns,
            "atpg_detected_faults": detected,
            "atpg_total_faults": total_faults,
            "atpg_fault_coverage_pct": coverage,
        }

    def parse_formal_report(self, formal_log_path: str) -> dict:
        formal_path = Path(formal_log_path)
        if not formal_path.exists():
            return {"formal_compare_points": 0, "formal_is_equivalent": True, "formal_failures": 0}
        try:
            text = formal_path.read_text()
        except OSError:
            return {"formal_compare_points": 0, "formal_is_equivalent": True, "formal_failures": 0}
        points = 0
        is_equiv = True
        for line in text.splitlines():
            m = re.search(r"Compare\s+points\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                points = int(m.group(1))
            if "not equivalent" in line.lower():
                is_equiv = False
        return {"formal_compare_points": points, "formal_is_equivalent": is_equiv, "formal_failures": 0 if is_equiv else points}

    def parse_antenna_report(self, antenna_report_path: str) -> dict:
        ant_path = Path(antenna_report_path)
        if not ant_path.exists():
            return {"antenna_total_violations": 0, "antenna_max_ratio": 0.0, "antenna_is_clean": True}
        try:
            text = ant_path.read_text()
        except OSError:
            return {"antenna_total_violations": 0, "antenna_max_ratio": 0.0, "antenna_is_clean": True}
        violations = 0
        max_ratio = 0.0
        for line in text.splitlines():
            m = re.search(r"Antenna\s+violation\s+on\s+net\s+(\S+)\s+ratio\s+([\d.]+)", line, re.IGNORECASE)
            if m:
                violations += 1
                max_ratio = max(max_ratio, float(m.group(2)))
            m = re.search(r"Total\s+violations\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                violations = max(violations, int(m.group(1)))
        return {"antenna_total_violations": violations, "antenna_max_ratio": max_ratio, "antenna_is_clean": violations == 0}

    def parse_density_report(self, density_report_path: str) -> dict:
        den_path = Path(density_report_path)
        if not den_path.exists():
            return {"density_pct": 0.0, "density_min_pct": 0.0, "density_max_pct": 0.0, "density_violations": 0}
        try:
            text = den_path.read_text()
        except OSError:
            return {"density_pct": 0.0, "density_min_pct": 0.0, "density_max_pct": 0.0, "density_violations": 0}
        density = 0.0
        min_d = 0.0
        max_d = 0.0
        violations = 0
        for line in text.splitlines():
            m = re.search(r"^Density\s*:\s*([\d.]+)", line, re.IGNORECASE)
            if m:
                density = float(m.group(1))
            m = re.search(r"Min\s+density\s*:\s*([\d.]+)", line, re.IGNORECASE)
            if m:
                min_d = float(m.group(1))
            m = re.search(r"Max\s+density\s*:\s*([\d.]+)", line, re.IGNORECASE)
            if m:
                max_d = float(m.group(1))
            m = re.search(r"Violations\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                violations = int(m.group(1))
        return {"density_pct": density, "density_min_pct": min_d, "density_max_pct": max_d, "density_violations": violations}

    def parse_signoff_report(self, setup_rpt_path: str) -> dict:
        setup_path = Path(setup_rpt_path)
        if not setup_path.exists():
            return {"signoff_setup_wns_ns": 0.0, "signoff_setup_tns_ns": 0.0, "signoff_endpoints": 0, "signoff_setup_satisfied": True}
        try:
            text = setup_path.read_text()
        except OSError:
            return {"signoff_setup_wns_ns": 0.0, "signoff_setup_tns_ns": 0.0, "signoff_endpoints": 0, "signoff_setup_satisfied": True}
        endpoints = 0
        setup_wns = 0.0
        setup_tns = 0.0
        for line in text.splitlines():
            m = re.search(r"wns\s+(-?[\d.]+)", line, re.IGNORECASE)
            if m:
                setup_wns = float(m.group(1))
            m = re.search(r"tns\s+(-?[\d.]+)", line, re.IGNORECASE)
            if m:
                setup_tns = float(m.group(1))
            m = re.search(r"Endpoints\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                endpoints = int(m.group(1))
        return {"signoff_setup_wns_ns": setup_wns, "signoff_setup_tns_ns": setup_tns,
                "signoff_endpoints": endpoints, "signoff_setup_satisfied": setup_wns >= 0}

    def parse_clock_gating_report(self, cg_log_path: str) -> dict:
        cg_path = Path(cg_log_path)
        if not cg_path.exists():
            return {"cg_total_registers": 0, "cg_gated_registers": 0, "cg_power_savings_pct": 0.0}
        try:
            text = cg_path.read_text()
        except OSError:
            return {"cg_total_registers": 0, "cg_gated_registers": 0, "cg_power_savings_pct": 0.0}
        total = 0
        gated = 0
        for line in text.splitlines():
            m = re.search(r"Total\s+registers\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                total = int(m.group(1))
            m = re.search(r"Gated\s+registers\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                gated = int(m.group(1))
        savings = (gated / total * 100.0) if total else 0.0
        return {"cg_total_registers": total, "cg_gated_registers": gated, "cg_power_savings_pct": savings}

    def parse_pro_report(self, pro_log_path: str) -> dict:
        pro_path = Path(pro_log_path)
        if not pro_path.exists():
            return {"pro_buffer_count": 0, "pro_slack_improvement_ns": 0.0, "pro_setup_fixed": 0, "pro_hold_fixed": 0}
        try:
            text = pro_path.read_text()
        except OSError:
            return {"pro_buffer_count": 0, "pro_slack_improvement_ns": 0.0, "pro_setup_fixed": 0, "pro_hold_fixed": 0}
        buffers = 0
        slack_imp = 0.0
        setup_fixed = 0
        hold_fixed = 0
        for line in text.splitlines():
            m = re.search(r"Inserted\s+(\d+)\s+buffer", line, re.IGNORECASE)
            if m:
                buffers = int(m.group(1))
            m = re.search(r"Slack\s+improvement\s*:\s*([-\d.]+)", line, re.IGNORECASE)
            if m:
                slack_imp = float(m.group(1))
            m = re.search(r"Setup\s+violations\s+fixed\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                setup_fixed = int(m.group(1))
            m = re.search(r"Hold\s+violations\s+fixed\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                hold_fixed = int(m.group(1))
        return {"pro_buffer_count": buffers, "pro_slack_improvement_ns": slack_imp,
                "pro_setup_fixed": setup_fixed, "pro_hold_fixed": hold_fixed}

    def parse_si_report(self, si_report_path: str) -> dict:
        si_path = Path(si_report_path)
        if not si_path.exists():
            return {"si_crosstalk_violations": 0, "si_max_delta_delay_ns": 0.0, "si_is_clean": True}
        try:
            text = si_path.read_text()
        except OSError:
            return {"si_crosstalk_violations": 0, "si_max_delta_delay_ns": 0.0, "si_is_clean": True}
        violations = 0
        max_delay = 0.0
        for line in text.splitlines():
            m = re.search(r"Crosstalk\s+violations?\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                violations = int(m.group(1))
            m = re.search(r"Max\s+delta\s+delay\s*:\s*([\d.]+)", line, re.IGNORECASE)
            if m:
                max_delay = max(max_delay, float(m.group(1)))
            m = re.search(r"Crosstalk\s+violation\s+on\s+(\S+)\s+delta\s+([\d.]+)", line, re.IGNORECASE)
            if m:
                violations += 1
                max_delay = max(max_delay, float(m.group(2)))
        return {"si_crosstalk_violations": violations, "si_max_delta_delay_ns": max_delay, "si_is_clean": violations == 0}

    def parse_hierarchical_partition_report(self, partition_log_path: str) -> dict:
        metrics: dict = {
            "hp_total_blocks": 0,
            "hp_runtime_sec": 0.0,
        }
        log_path = Path(partition_log_path)
        if not log_path.exists():
            return metrics
        text = log_path.read_text()
        for line in text.splitlines():
            m = re.search(r"Partition:\s+(\S+)\s+instances\s+(\d+)", line, re.IGNORECASE)
            if m:
                metrics["hp_total_blocks"] = metrics.get("hp_total_blocks", 0) + 1
        return metrics

    def parse_block_synthesis_report(self, block_synth_log_path: str) -> dict:
        metrics: dict = {
            "bs_total_blocks": 0,
            "bs_total_cells": 0,
            "bs_total_area_um2": 0.0,
            "bs_estimated_power_mw": 0.0,
        }
        log_path = Path(block_synth_log_path)
        if not log_path.exists():
            return metrics
        text = log_path.read_text()
        for line in text.splitlines():
            m = re.search(r"Number\s+of\s+blocks?\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                metrics["bs_total_blocks"] = int(m.group(1))
            m = re.search(r"Number\s+of\s+cells\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                metrics["bs_total_cells"] = int(m.group(1))
            m = re.search(r"Chip\s+area\s+for\s+top\s+module\s*:\s*([\d.]+)", line, re.IGNORECASE)
            if m:
                metrics["bs_total_area_um2"] = float(m.group(1))
        return metrics

    def parse_top_floorplan_report(self, top_fp_log_path: str) -> dict:
        metrics: dict = {
            "tf_total_blocks": 0,
            "tf_die_width_um": 0.0,
            "tf_die_height_um": 0.0,
        }
        log_path = Path(top_fp_log_path)
        if not log_path.exists():
            return metrics
        text = log_path.read_text()
        for line in text.splitlines():
            m = re.search(r"Die\s+area\s*:\s*([\d.]+)\s*x\s*([\d.]+)", line, re.IGNORECASE)
            if m:
                metrics["tf_die_width_um"] = float(m.group(1))
                metrics["tf_die_height_um"] = float(m.group(2))
            m = re.search(r"Block\s+(\S+)\s+placed", line, re.IGNORECASE)
            if m:
                metrics["tf_total_blocks"] = metrics.get("tf_total_blocks", 0) + 1
        return metrics

    def parse_d2d_interface_report(self, d2d_report_path: str) -> dict:
        metrics: dict = {
            "d2d_cross_boundary_paths": 0,
            "d2d_total_violations": 0,
            "d2d_max_cross_delay_ns": 0.0,
            "d2d_is_clean": True,
        }
        report_path = Path(d2d_report_path)
        if not report_path.exists():
            return metrics
        text = report_path.read_text()
        violations = 0
        for line in text.splitlines():
            m = re.search(r"Cross-boundary\s+paths?\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                metrics["d2d_cross_boundary_paths"] = int(m.group(1))
            m = re.search(r"Interface\s+violations?\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                violations = int(m.group(1))
            m = re.search(r"Interface\s+violation\s+on\s+(\S+)\s+delay\s+([\d.]+)", line, re.IGNORECASE)
            if m:
                metrics["d2d_max_cross_delay_ns"] = max(
                    metrics["d2d_max_cross_delay_ns"], float(m.group(2))
                )
        metrics["d2d_total_violations"] = violations
        metrics["d2d_is_clean"] = violations == 0
        return metrics

    def parse_yield_report(self, yield_report_path: str) -> dict:
        yield_path = Path(yield_report_path)
        if not yield_path.exists():
            return {"yield_redundant_vias": 0, "yield_repair_coverage_pct": 0.0, "yield_critical_spots": 0}
        try:
            text = yield_path.read_text()
        except OSError:
            return {"yield_redundant_vias": 0, "yield_repair_coverage_pct": 0.0, "yield_critical_spots": 0}
        vias = 0
        coverage = 0.0
        critical = 0
        for line in text.splitlines():
            m = re.search(r"Redundant\s+vias?\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                vias = int(m.group(1))
            m = re.search(r"Repair\s+coverage\s*:\s*([\d.]+)", line, re.IGNORECASE)
            if m:
                coverage = float(m.group(1))
            m = re.search(r"Critical\s+spots?\s*:\s*(\d+)", line, re.IGNORECASE)
            if m:
                critical = int(m.group(1))
        return {"yield_redundant_vias": vias, "yield_repair_coverage_pct": coverage, "yield_critical_spots": critical}

    def parse_all(self):
        metrics = {}
        metrics.update(self.parse_timing())
        metrics.update(self.parse_utilization())
        metrics.update(self.parse_runtime())
        drc_path = self.reports_dir / "drc_raw.txt"
        if drc_path.exists():
            metrics.update(self.parse_drc_report(str(drc_path)))
        lvs_path = self.reports_dir / "lvs_comp.out"
        if lvs_path.exists():
            metrics.update(self.parse_lvs_report(str(lvs_path)))
        power_path = self.reports_dir / "power_report.txt"
        if power_path.exists():
            metrics.update(self.parse_power_report(str(power_path)))
        em_path = self.reports_dir / "em_report.txt"
        if em_path.exists():
            metrics.update(self.parse_em_report(str(em_path)))
        decap_path = self.reports_dir / "decap_log.txt"
        if decap_path.exists():
            metrics.update(self.parse_decap_report(str(decap_path)))
        scan_path = self.reports_dir / "scan_log.txt"
        if scan_path.exists():
            metrics.update(self.parse_scan_report(str(scan_path)))
        atpg_path = self.reports_dir / "atpg_report.txt"
        if atpg_path.exists():
            metrics.update(self.parse_atpg_report(str(atpg_path)))
        formal_path = self.reports_dir / "formal_log.txt"
        if formal_path.exists():
            metrics.update(self.parse_formal_report(str(formal_path)))
        antenna_path = self.reports_dir / "antenna_report.txt"
        if antenna_path.exists():
            metrics.update(self.parse_antenna_report(str(antenna_path)))
        density_path = self.reports_dir / "density_report.txt"
        if density_path.exists():
            metrics.update(self.parse_density_report(str(density_path)))
        signoff_path = self.reports_dir / "signoff_setup.rpt"
        if signoff_path.exists():
            metrics.update(self.parse_signoff_report(str(signoff_path)))
        cg_path = self.reports_dir / "clock_gating_log.txt"
        if cg_path.exists():
            metrics.update(self.parse_clock_gating_report(str(cg_path)))
        pro_path = self.reports_dir / "pro_log.txt"
        if pro_path.exists():
            metrics.update(self.parse_pro_report(str(pro_path)))
        si_path = self.reports_dir / "si_report.txt"
        if si_path.exists():
            metrics.update(self.parse_si_report(str(si_path)))
        yield_path = self.reports_dir / "yield_report.txt"
        if yield_path.exists():
            metrics.update(self.parse_yield_report(str(yield_path)))
        partition_path = self.reports_dir / "partition_log.txt"
        if partition_path.exists():
            metrics.update(self.parse_hierarchical_partition_report(str(partition_path)))
        block_synth_path = self.reports_dir / "block_synth_log.txt"
        if block_synth_path.exists():
            metrics.update(self.parse_block_synthesis_report(str(block_synth_path)))
        top_fp_path = self.reports_dir / "top_floorplan_log.txt"
        if top_fp_path.exists():
            metrics.update(self.parse_top_floorplan_report(str(top_fp_path)))
        d2d_path = self.reports_dir / "d2d_report.txt"
        if d2d_path.exists():
            metrics.update(self.parse_d2d_interface_report(str(d2d_path)))
        return metrics
