# GLI-FLOW User Manual

> **RTL-to-GDS Silicon Compiler Pipeline** — v1.0.0

GLI-FLOW is an open-source RTL-to-GDS ASIC implementation flow built on OpenROAD, Yosys, Magic, and Netgen. It provides a unified CLI, 29-stage pipeline, telemetry, regression detection, PDK management, CI/CD integration, and a web dashboard.

---

## Table of Contents

1. [Installation](#installation)
2. [Quick Start](#quick-start)
3. [CLI Reference](#cli-reference)
4. [Pipeline Stages](#pipeline-stages)
5. [Manifest Configuration](#manifest-configuration)
6. [PDK Support](#pdk-support)
7. [Examples](#examples)
8. [Output & Telemetry](#output--telemetry)
9. [Architecture](#architecture)
10. [CI/CD Integration](#cicd-integration)
11. [Remote & Cloud](#remote--cloud)
12. [Troubleshooting](#troubleshooting)

---

## Installation

### Prerequisites

| Tool   | Minimum Version |
| ------ | --------------- |
| Python | ≥ 3.9           |
| git    | ≥ 2.0           |
| cmake  | ≥ 3.10          |
| Yosys  | 0.33+           |
| OpenROAD | 2.0+          |
| KLayout | any            |
| Magic  | 8.3+            |
| Netgen | 1.5+            |

### From Source

```bash
git clone https://github.com/Jegadiswar-SM/gli-flow.git
cd gli-flow
pip install -e .
```

### Full Install (PDK + Tools)

```bash
gli-flow install                          # sky130 default
gli-flow install --pdk gf180mcu          # GlobalFoundries 180nm
gli-flow install --pdk sky130 --force    # Reinstall
gli-flow install --dry-run               # Preview only
```

The installer automates:

1. System dependencies (apt/brew)
2. Toolchain: Yosys, KLayout, OpenROAD
3. OpenROAD Flow Scripts (ORFS)
4. PDK via [Volare](https://github.com/efabless/volare)
5. Workspace config at `~/.gli-flow/config.json`
6. Validation of all tools

### Docker

```bash
docker build -t gli-flow .
docker run --rm gli-flow --help
```

The Docker image ships with Ubuntu 22.04, OpenROAD 2.0, Yosys 0.33, Magic 8.3, Netgen 1.5, and sky130A PDK pre-installed.

---

## Quick Start

### 1. Create a design

```bash
# Auto-detect from existing RTL (single file or directory)
gli-flow init my_design --rtl src/top.v
gli-flow init my_design --rtl-dir rtl/

# Or create a boilerplate manifest (edit manually)
gli-flow init my_design
```

With `--rtl` or `--rtl-dir`, `init` parses the Verilog/SystemVerilog and auto-populates:

| Manifest Field | Source |
| -------------- | ------ |
| `top_module` | Top-level module name (not instantiated by others) |
| `design_name` | Same as top module |
| `rtl_files` | All discovered `.v`/`.sv` files (from directory) or the single file |
| `clock_port` | First port matching `clk`/`clock` naming convention |

Example generated manifest from `gli-flow init my_design --rtl-dir rtl/`:

```yaml
design_name: uart_top
rtl_files:
  - rtl/uart_rx.sv
  - rtl/uart_top.sv
  - rtl/uart_tx.sv
top_module: uart_top
backend: openroad
pdk: sky130
pdk_variant: sky130A
clock_port: clk
clock_period_ns: 10.0
threads: 4
```

### 2. Run the flow

```bash
gli-flow run .
# or with mock adapter (no EDA tools needed):
gli-flow run . --mock
```

### 4. View results

```bash
gli-flow history        # Last 20 runs
gli-flow status         # Current run status
gli-flow report my_design --platform sky130hd
```

---

## CLI Reference

| Command | Description | Key Flags |
| ------- | ----------- | --------- |
| `gli-flow run <dir>` | Run full pipeline | `--mock`, `-j N` (threads), `-m N` (MB), `--orfs-root`, `--db-path`, `--verbose` |
| `gli-flow history` | List recent runs | `--limit N` (default 20), `--db-path` |
| `gli-flow status` | Current run status | `--db-path` |
| `gli-flow batch <dir1> [dir2...]` | Run multiple designs | `--parallel/-j N` (default 1) |
| `gli-flow init <name>` | Create manifest | `--rtl <file>` (single file), `--rtl-dir <dir>` (scan directory) — auto-detect top module, ports, RTL files |
| `gli-flow install` | Install PDK + tools | `--pdk`, `--force`, `--dry-run`, `--skip-orfs`, `--skip-system`, `--skip-pdk` |
| `gli-flow ci <dir>` | CI mode | `--junit`, `--markdown`, `--baseline`, `--qor-min`, `--wns-max` |
| `gli-flow remote <dir>` | Remote SSH execution | `--host` (required), `--port`, `--user`, `--key`, `--check` |
| `gli-flow cloud upload <run_id>` | Upload to S3/GCS | `--provider`, `--bucket`, `--prefix` |
| `gli-flow cloud download <run_id>` | Download from S3/GCS | `--provider`, `--bucket`, `--prefix` |
| `gli-flow cloud list` | List cloud runs | `--provider`, `--bucket`, `--prefix` |

> **Tip:** Use `gli-flow run . --mock` to test your manifest and pipeline without EDA tools — the mock adapter generates synthetic results for all 29 stages.

---

## Pipeline Stages

GLI-FLOW implements **29 pipeline stages**. Stages marked **Essential** will abort the flow on failure; others are gracefully skipped.

| # | Stage | Essential | Description |
| - | ----- | --------- | ----------- |
| 1 | **INITIALIZING** | ✅ | Read manifest, resolve PDK, create run directory |
| 2 | HIERARCHICAL_PARTITIONING | | Partition flat RTL into hierarchical blocks |
| 3 | BLOCK_SYNTHESIS | | Synthesize individual blocks |
| 4 | **SYNTHESIS** | ✅ | Top-level Yosys synthesis (RTL → gate-level netlist) |
| 5 | CLOCK_GATING | | Insert clock-gating cells for power savings |
| 6 | SCAN_INSERTION | | Insert DFT scan chains (Yosys dft_sweep + dft_stitch) |
| 7 | FORMAL_VERIFICATION | | Equivalence checking (RTL vs gate-level) |
| 8 | FLOORPLANNING | | IO pin placement, die area definition |
| 9 | TOP_FLOORPLANNING | | Top-level floorplan assembly for hierarchical flows |
| 10 | PLACEMENT | | Standard cell placement |
| 11 | CTS | | Clock tree synthesis |
| 12 | ROUTING | | Detailed routing |
| 13 | PRO | | Post-route optimization (buffer insertion, sizing) |
| 14 | ANTENNA_CHECK | | Antenna rule violation check |
| 15 | FILL | | Density fill cell insertion |
| 16 | DECAP | | Decoupling capacitor insertion |
| 17 | POWER | | Power analysis & IR drop |
| 18 | EM_CHECK | | Electromigration check |
| 19 | DENSITY_CHECK | | Physical density verification |
| 20 | YIELD | | Yield enhancement (redundant vias, repair) |
| 21 | DRC | | Design rule checking (Magic) |
| 22 | LVS | | Layout vs. schematic verification (Netgen) |
| 23 | ATPG | | Automatic test pattern generation |
| 24 | TIMING_ANALYSIS | | Multi-corner STA signoff |
| 25 | SI_ANALYSIS | | Signal integrity / crosstalk analysis |
| 26 | SIGN_OFF | | OCV-aware timing signoff |
| 27 | D2D_INTERFACE_CHECK | | Die-to-die interface validation |
| 28 | QOR_EXTRACTION | ✅ | Extract QoR metrics & telemetry |
| 29 | PACKAGING | ✅ | GDS packaging & artifact collection |

```
RTL → Hierarchical Partitioning → Block Synthesis → Synthesis →
Clock Gating → Scan Insertion → Formal Verification → Floorplanning →
Top Floorplanning → Placement → CTS → Routing → PRO → Antenna Check →
Fill → Decap → Power Analysis → EM Check → Density Check → Yield →
DRC → LVS → ATPG → Timing Analysis → SI Analysis → OCV Sign-Off →
D2D Interface Check → QoR Extraction → GDS
```

---

## Manifest Configuration

The `gli_manifest.yaml` file describes your design. Place it in your design directory.

If `rtl_files` is omitted or empty, `gli-flow run` will auto-discover all `.v` and `.sv` files in the design directory (recursively) and attempt to infer the top module. The manifest is validated before each run — missing required fields or broken file paths produce a clear error immediately.

### Fields

| Field | Required | Type | Default | Description |
| ----- | -------- | ---- | ------- | ----------- |
| `design_name` | ✅ | string | — | Design name |
| `rtl_files` | ✅ | list | — | Paths to RTL files (`.v`, `.sv`) |
| `top_module` | ✅ | string | — | Top-level Verilog module |
| `backend` | | string | `openroad` | `openroad` or `librelane` |
| `pdk` | | string | `sky130` | PDK name |
| `pdk_variant` | | string | `sky130A` | PDK variant |
| `clock_port` | | string | `clk` | Clock port name |
| `clock_period_ns` | | float | `10.0` | Clock period in ns |
| `constraints` | | list | — | SDC constraint file paths |
| `threads` | | int | `4` | CPU threads |
| `corners` | | list | PDK defaults | PVT corners |

### Corner Definition

```yaml
corners:
  - name: worst
    type: worst
    process: slow
    voltage: 1.62
    temperature: 125
  - name: typical
    type: typical
    process: typical
    voltage: 1.80
    temperature: 25
  - name: best
    type: best
    process: fast
    voltage: 1.95
    temperature: -40
```

### Complete Example

```yaml
design_name: mac_top
rtl_files:
  - rtl/accel/mac_top.v
  - rtl/accel/systolic_array.v
  - rtl/accel/pe.v
  - rtl/accel/mac_regs.v
top_module: mac_top
backend: openroad
pdk: sky130
pdk_variant: sky130A
clock_port: clk
clock_period_ns: 10.0
constraints:
  - constraints/mac.sdc
threads: 4
corners:
  - { name: worst, type: worst,  process: slow,    voltage: 1.62, temperature: 125 }
  - { name: typical, type: typical, process: typical, voltage: 1.80, temperature: 25  }
  - { name: best,   type: best,   process: fast,    voltage: 1.95, temperature: -40 }
```

---

## PDK Support

| PDK | Name | Variant | Platform | Voltage | Track Height | Metal Layers |
| --- | ---- | ------- | -------- | ------- | ------------ | ------------ |
| SkyWater 130nm | `sky130` | sky130A | sky130hd | 1.8V | 14 | li1, met1–met5 |
| GlobalFoundries 180nm | `gf180mcu` | gf180mcuC | gf180mcuC | 1.8V | 12 | met1–met4 |
| IHP SG13G2 | `ihp-sg13g2` | sg13g2 | sg13g2 | 1.2V | 12 | met1–met5 |

```bash
gli-flow install --pdk sky130      # SkyWater 130nm
gli-flow install --pdk gf180mcu    # GlobalFoundries 180nm
```

Each PDK defines three default corners:

| Corner | sky130 (V/T) | gf180mcu (V/T) | ihp-sg13g2 (V/T) |
| ------ | ------------ | -------------- | ----------------- |
| Worst  | 1.62V / 125°C | 1.62V / 125°C | 1.08V / 125°C |
| Typical | 1.80V / 25°C | 1.80V / 25°C | 1.20V / 25°C |
| Best  | 1.95V / -40°C | 1.95V / -40°C | 1.32V / -40°C |

---

## Examples

Six example designs are included:

| Design | Backend | PDK | RTL Files | Description |
| ------ | ------- | --- | --------- | ----------- |
| **counter** | openroad | sky130 | 1 | 8-bit counter |
| **gcd** | **librelane** | sky130A | 1 | GCD calculator |
| **mini_mac** | openroad | sky130 | 4 + Ibex CPU | MAC accelerator with APB control, memory arbiter, firmware |
| **systolic_array** | openroad | sky130 | 2 | 4×4 systolic PE array |
| **tiny_or** | openroad | sky130 | 1 | Minimal OR gate (testing) |
| **uart** | openroad | sky130 | 3 | UART TX/RX |

```bash
cd examples/counter && gli-flow run .                  # Run counter
cd examples/counter && gli-flow run . --mock           # Mock mode (no tools)
cd examples/gcd     && gli-flow run .                  # Uses LibreLane backend
cd examples/mini_mac && gli-flow run .                 # MAC accelerator
```

### Mini-MaC

The Mini-MaC example is a complete SoC with:

- Ibex RISC-V CPU core
- 4×4 systolic array MAC accelerator
- APB bus and memory subsystem
- Verilator testbench (`dv/Makefile`)
- Firmware driver (`sw/main.c`)
- SDR constraints

```bash
cd examples/mini_mac/dv && make    # Run Verilator simulation
```

---

## Output & Telemetry

### Directory Structure

After a run, results are organized under `outputs/runs/run_{timestamp}_{design}/`:

```
outputs/runs/
└── run_1748714400_counter/
    ├── logs/              # Tool execution logs
    ├── reports/           # Parseable stage reports (RPT, CSV, TXT)
    ├── artifacts/         # Output files (GDS, netlist, DEF, SDC)
    │   ├── 1_synth.v      # Synthesized netlist
    │   └── 6_final.gds    # Final GDS layout
    ├── results/           # Same as artifacts
    ├── telemetry/         # Metrics JSON files
    │   ├── metrics.json
    │   └── *.json         # Per-stage data
    └── snapshots/
```

### Key Output Files

| File | Description |
| ---- | ----------- |
| `results/6_final.gds` | Final GDS layout |
| `artifacts/1_synth.v` | Synthesized gate-level Verilog |
| `telemetry/metrics.json` | Structured metrics (149 fields) |
| `drc_lvs_summary.json` | DRC/LVS results |
| `sta_corners.json` | Multi-corner STA results |
| `openroad_metrics.json` | Full pipeline metrics |
| `reproducibility.json` | Provenance manifest (SHA256 RTL hashes, tool versions) |

### Telemetry Fields

The `TelemetryParser` extracts ~149 metrics across these domains:

| Domain | Parse Method | Source Files |
| ------ | ------------ | ------------ |
| Timing | `parse_timing()` | `metrics.csv`, `timing.rpt` |
| Utilization | `parse_utilization()` | `metrics.csv`, `utilization.rpt` |
| DRC | `parse_drc_report()` | `drc_raw.txt` |
| LVS | `parse_lvs_report()` | `lvs_comp.out` |
| Power | `parse_power_report()` | `power_report.txt` |
| EM | `parse_em_report()` | `em_report.txt` |
| Decap | `parse_decap_report()` | `decap_log.txt` |
| Scan | `parse_scan_report()` | `scan_log.txt` |
| ATPG | `parse_atpg_report()` | `atpg_report.txt` |
| Formal | `parse_formal_report()` | `formal_log.txt` |
| Clock Gating | `parse_clock_gating_report()` | `clock_gating_log.txt` |
| PRO | `parse_pro_report()` | `pro_log.txt` |
| SI | `parse_si_report()` | `si_report.txt` |
| Yield | `parse_yield_report()` | `yield_report.txt` |
| Antenna | `parse_antenna_report()` | `antenna_report.txt` |
| Density | `parse_density_report()` | `density_report.txt` |
| Signoff | `parse_signoff_report()` | `signoff_setup.rpt` |

### QoR Score

The QoR scoring engine (`calculate_qor_score`) evaluates three dimensions:

| Dimension | Weight | Metrics |
| --------- | ------ | ------- |
| Timing | 50% | WNS, TNS |
| Area | 30% | Cell count, utilization |
| Density | 20% | Utilization vs. threshold |

Scores range 0–100. Penalties apply for WNS degradation, high utilization, and excessive runtime.

---

## Architecture

```
┌─────────────────────────────────────────────────────────┐
│                        CLI                              │
│   gli-flow run, install, history, batch, ci, remote     │
└──────────────────┬──────────────────────────────────────┘
                   │
┌──────────────────▼──────────────────────────────────────┐
│                 FlowOrchestrator                         │
│  Reads manifest → resolves PDK → iterates 29 stages    │
│  Dispatches each stage to adapter → collects telemetry  │
│  → computes QoR → writes artifacts → checks regression │
└──────────────────┬──────────────────────────────────────┘
                   │
        ┌──────────┼──────────┐
        ▼          ▼          ▼
┌────────────┐ ┌────────┐ ┌──────────┐
│ OpenROAD   │ │LibreLa-│ │  Mock    │
│ Adapter    │ │ne Adap │ │  EDA     │
│ (primary)  │ │ (alt)  │ │ (test)   │
└────────────┘ └────────┘ └──────────┘
        │
        ▼
┌─────────────────────────────────────────────────────────┐
│  OpenROAD Flow Scripts (ORFS)                           │
│  Yosys → Floorplan → Place → CTS → Route → GDS         │
└─────────────────────────────────────────────────────────┘
        │
        ▼
┌─────────────────────────────────────────────────────────┐
│  PDK Layer                                              │
│  sky130 / gf180mcu / ihp-sg13g2                         │
│  (magic_tech, netgen_setup, fill_rules, liberty)        │
└─────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────┐
│  Supporting Subsystems                                   │
│                                                          │
│  TelemetryParser  ─── parse_all() → 149 fields          │
│  DatabaseManager  ─── SQLite (runs, trends, history)    │
│  RegressionDetector ── QoR/WNS/utilization delta        │
│  FailureAtlas    ─── rule-based failure detection       │
│  Scheduler       ─── JobQueue, LocalWorker, RemoteWorker│
│  Installer       ─── system deps, PDK, ORFS, validation │
│  Backend Server  ─── FastAPI (runs, trends, releases)   │
│  Dashboard       ─── Frontend (Vite served by FastAPI)  │
│  Provenance      ─── SHA256 hashes + reproducibility    │
└─────────────────────────────────────────────────────────┘
```

### Key Modules

| Module | Location | Responsibility |
| ------ | -------- | -------------- |
| `FlowOrchestrator` | `gli_flow/core/orchestrator.py` | Pipeline orchestration |
| `ExecutionStage` | `gli_flow/core/stages.py` | Stage enum (29 stages) |
| `OpenRoadAdapter` | `gli_flow/backends/openroad_adapter.py` | EDA tool integration (~1,900 lines) |
| `PDKRegistry` | `gli_flow/pdk/registry.py` | PDK discovery & resolution |
| `TelemetryParser` | `gli_flow/telemetry/parser.py` | Report parsing (~700 lines) |
| `DatabaseManager` | `gli_flow/database/sqlite.py` | Run history & persistence |
| `RegressionDetector` | `gli_flow/regression/detector.py` | QoR regression checks |
| `detect_failures` | `failure_atlas/detector.py` | Failure detection engine |
| `Installer` | `gli_flow/installer/installer.py` | Environment setup |
| `CIRunner` | `gli_flow/ci/runner.py` | CI pipeline runner |
| `JobQueue` | `gli_flow/scheduler/queue.py` | Batch execution queue |

---

## CI/CD Integration

```bash
# Run in CI mode with JUnit output
gli-flow ci designs/counter \
  --junit results.xml \
  --markdown report.md \
  --baseline run_1748714400_counter \
  --qor-min 80 \
  --wns-max 0.0

# Compare against baseline
# Fails if: QoR < 80, WNS > 0.0, utilization > 70%, QoR drop > 10%
```

The CI runner produces:

- **JUnit XML** — integrates with Jenkins, GitLab CI, GitHub Actions
- **Markdown report** — human-readable summary
- **Regression alerts** — detected via `RegressionDetector`

### GitHub Actions

```yaml
# .github/workflows/ci.yml
jobs:
  gli-flow-ci:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
      - name: Run GLI-FLOW CI
        run: |
          pip install -e .
          gli-flow ci designs/counter --junit results.xml
      - name: Upload results
        uses: actions/upload-artifact@v4
        with:
          path: outputs/runs/*/telemetry/
```

---

## Remote & Cloud

### Remote SSH Execution

```bash
# Check connection
gli-flow remote . --host build-server --check

# Run remotely
gli-flow remote . --host build-server --user jenkins \
  --key ~/.ssh/id_rsa --gli-flow-path /opt/gli-flow
```

The remote worker uses `rsync` to transfer the design directory, runs the flow via SSH, and reports results back.

### Cloud Storage

```bash
# Upload a run to S3
gli-flow cloud upload run_1748714400_counter \
  --provider s3 --bucket my-bucket --prefix gli-flow/

# Download from GCS
gli-flow cloud download run_1748714400_counter \
  --provider gcs --bucket my-bucket

# List remote runs
gli-flow cloud list --provider s3 --bucket my-bucket
```

Supports AWS S3 (`boto3`) and Google Cloud Storage (`google-cloud-storage`).

---

## Troubleshooting

### Common Issues

| Symptom | Cause | Solution |
| ------- | ----- | -------- |
| `gli-flow: command not found` | Package not installed | `pip install -e .` |
| `PDK_ROOT not set` | PDK not installed | `gli-flow install --pdk sky130` |
| Stage shows `[SKIP]` | Method not on adapter | Use `--mock` to test without tools |
| `openroad: command not found` | OpenROAD missing | Install via `gli-flow install` or manual |
| Integration tests skipped | EDA tools not present | `pytest -k "not integration"` |
| `Unknown mark integration` | Missing `pytest.ini` | Cosmetic only; tests still run |
| Large GDS warnings on push | Binary blobs in repo | Use `.gitignore` or Git LFS |

### Logging

```bash
gli-flow run . --verbose       # Detailed output
cat outputs/runs/*/logs/*.log  # Raw tool logs
```

### Data & Reports

```bash
# Dashboard server
cd backend && python server.py
# → http://localhost:8000

# API endpoints
curl http://localhost:8000/runs
curl http://localhost:8000/health
curl http://localhost:8000/trends
```

### Tests

```bash
pytest                              # All unit tests (175+ tests)
pytest -k "drc or lvs"             # DRC/LVS telemetry tests
pytest tests/e2e/                   # Mock E2E pipeline tests
pytest tests/integration/           # Integration tests
pytest -v --tb=short               # Verbose, short traceback
```

---

## License

Apache 2.0 — Green Lantern Industries
