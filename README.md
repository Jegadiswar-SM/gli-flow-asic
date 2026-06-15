# GLI-FLOW

RTL-to-GDS execution orchestration and observability for OpenROAD / ORFS.

> **IP Ownership:** You own all your RTL and generated artifacts. See [Terms of Service](docs/TERMS_OF_SERVICE.md).

## Telemetry

GLI-FLOW collects **anonymized execution telemetry** to improve the platform.

**What is collected:**
- WNS, TNS, cell count, utilization, runtime
- Flow stage completion status
- Error type classifications

**What is NEVER collected:**
- RTL source code
- Module names or signal names
- GDS geometry
- Any design-identifying information

**To opt out permanently:**
```bash
  gli-flow config --telemetry off
```

**To inspect what would be uploaded:**
```bash
  gli-flow show-telemetry --run <run_id>
```

See [Privacy Policy](docs/PRIVACY_POLICY.md) for exact field enumeration.

## What It Does

`gli-flow run <design_dir>` reads a manifest, invokes Yosys + OpenROAD via the ORFS
Makefile, collects timing/power/area metrics from the tool output, computes a QoR
score, detects regressions against previous runs, and persists everything to SQLite.
A FastAPI backend serves dashboards, run details, images, and reports. DRC/LVS
verification, multi-corner STA, and Failure Atlas pattern matching are wired in.

## Quick Start

```bash
# 1. Clone and install
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
pip install -e .

# 2. Verify installation
gli-flow doctor

# 3. Run a design in mock mode (no EDA tools required)
gli-flow run examples/counter --mock

# 4. Interactive design setup wizard
gli-flow quickstart
```

> **Need your PATH updated?** After `pip install -e .`, if `gli-flow` is not found:
> - **Linux:** add `export PATH="$HOME/.local/bin:$PATH"` to `~/.bashrc`
> - **Using a venv:** activate it first: `source venv/bin/activate`
> - Run `which gli-flow` to confirm it's on your PATH

### One-command install script

```bash
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
bash scripts/install.sh
```

## Commands

| Command | Description |
|---------|-------------|
| `gli-flow quickstart` | Interactive wizard — creates manifest + skeleton RTL, auto-detects existing RTL |
| `gli-flow init <name>` | Creates a design manifest; use `--rtl` or `--rtl-dir` to auto-detect from RTL |
| `gli-flow run <dir>` | Run a design through the full RTL-to-GDS pipeline |
| `gli-flow run <dir> --mock` | Run using a mock adapter (no real EDA tools needed) |
| `gli-flow history` | Show execution history |
| `gli-flow status` | Show recent run status |
| `gli-flow report <design>` | Show QoR report from ORFS output files |
| `gli-flow batch <dir1> <dir2> ...` | Run multiple designs in parallel |
| `gli-flow install` | Install EDA toolchain (Yosys, OpenROAD, KLayout, PDK) |
| `gli-flow ci <dir>` | Run a design in CI mode with JUnit/Markdown output |
| `gli-flow doctor` | Validate installed EDA toolchain and produce health report |
| `gli-flow doctor --fix` | Auto-repair detected issues (schema, paths, caches) |
| `gli-flow doctor --repair-magic` | Repair broken magic binary shadowing system install |
| `gli-flow diagnose <run_id>` | Diagnose a failed run by scanning stage logs |
| `gli-flow show-telemetry <run_id>` | Show exact telemetry payload that would be uploaded |
| `gli-flow config --telemetry off/on` | View or change GLI-FLOW configuration |

## Manifest Format

Create a `gli_manifest.yaml` in your design directory:

```yaml
design_name: my_chip
rtl_files:
  - rtl/my_chip.sv
top_module: my_chip
backend: openroad
pdk: sky130
pdk_variant: sky130A
clock_port: clk
clock_period_ns: 10.0
threads: 4
corners:
  - name: typical
    type: typical
    process: typical
    voltage: 1.80
    temperature: 25
```

Generate one with: `gli-flow init my_design`

### RTL Auto-Detection

`gli-flow init` can auto-detect `top_module`, `clock_port`, `design_name`, and `rtl_files` from existing RTL:

```bash
# From a single file
gli-flow init my_design --rtl src/top.v

# From a directory (scans all .v/.sv files recursively)
gli-flow init my_design --rtl-dir src/

# quickstart also auto-detects if rtl/ already has files
gli-flow quickstart
```

When `rtl_files` is missing from a manifest, `gli-flow run` automatically discovers `.v`/`.sv` files in the design directory and infers the top module. The manifest is validated before every run, catching missing fields or broken file paths early.

## Outputs

After a run, results are in `outputs/runs/<run_id>/`:

| Path | Contents |
|------|----------|
| `reports/` | Timing reports, metrics CSV, DRC/LVS results, finish report, images |
| `artifacts/` | GDS, DEF, synthesized Verilog, artifact manifest |
| `telemetry/` | Per-stage telemetry and metrics JSON |
| `logs/` | OpenROAD execution log |
| `config.json` | Full design configuration |
| `reproducibility.json` | SHA256 hashes, tool versions, system fingerprint |
| `drc_lvs_summary.json` | DRC and LVS verification results |
| `sta_corners.json` | Multi-corner STA results |

## Architecture

```
CLI -> FlowOrchestrator -> OpenRoadAdapter -> subprocess(make) -> ORFS
                                                         |
                                               Reports (GDS, DEF, .rpt)
                                                         |
                                               TelemetryParser -> metrics.csv
                                                         |
                                               QoR scoring -> SQLite -> FastAPI -> React Dashboard
```

## Dashboard

Start the backend and frontend:

```bash
# Terminal 1: Start API server
python -m uvicorn backend.server:app --reload --port 8000

# Terminal 2: Start dashboard dev server
cd dashboard && npm run dev
```

The dashboard polls the API every 2 seconds and shows:
- 5 metric cards (total runs, success rate, avg QoR, regressions, unique designs)
- QoR trend chart with 0.70 threshold line
- QoR score breakdown (timing, utilization, cell count, runtime)
- Execution health gauge
- Recent runs table (click a run for detail view with 8 tabs)
- Top releases (from `/releases` API)
- Pipeline capability indicators (from `/health` API)

## System Requirements

- Linux, macOS, or WSL2
- Python >= 3.9
- OpenROAD-flow-scripts (ORFS) installed locally
- PDK pointing to a sky130 or gf180mcu PDK
- 8 GB RAM minimum (16+ recommended for non-trivial designs)

## Supported PDKs

| PDK | Variant | Status |
|-----|---------|--------|
| sky130 | sky130A (sky130hd) | Tested (4x4 systolic, UART, counter, GCD) |
| gf180mcu | — | Defined but not verified |

## Known Limitations

See [docs/KNOWN_LIMITATIONS.md](docs/KNOWN_LIMITATIONS.md) for the complete list.

Key limitations:
- No CDC analysis — mandatory disclaimer for multi-clock designs
- No Monte Carlo timing — deterministic corner analysis only
- SystemVerilog requires sv2v preprocessing
- No hierarchical or analog/mixed-signal flows
- Maximum tested complexity: ~50,000 cells (ibex RISC-V)

## Environment Resilience

GLI-FLOW includes a multi-candidate tool discovery system that prevents PATH shadowing failures:

- **Multi-candidate discovery** — Finds all tool candidates, not just the first on PATH
- **Functional validation** — Each candidate is tested for actual execution, not just existence
- **Evidence-based ranking** — Never selects a broken candidate solely due to PATH order
- **Self-healing repair** — `gli-flow doctor --repair-magic` disables broken binaries that shadow valid system installs
- **Doctor discovery report** — Shows all candidates with path, version, status, and selection rationale
- **Telemetry** — Tracks tool shadowing events, broken wrapper detections, and repair outcomes

```bash
# Full candidate discovery and validation
gli-flow doctor

# Repair broken magic binary shadowing system /usr/bin/magic
gli-flow doctor --repair-magic
```

See [MAGIC_ROOT_CAUSE.md](MAGIC_ROOT_CAUSE.md) for the incident that drove this architecture.

## Testing

```bash
# Run all tests
pytest tests/ -v

# Run with coverage
pytest tests/ --cov=gli_flow --cov-report=term-missing

# Run environment resilience tests specifically
pytest tests/adversarial/environment/ tests/regressions/test_path_shadowing_prefers_functional_binary.py -v
```

## License

Apache 2.0
