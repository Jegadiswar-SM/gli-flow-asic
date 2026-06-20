# User Manual

GLI-FLOW takes your Verilog design and runs it through the complete open-source ASIC
toolchain — synthesis, placement, routing, DRC/LVS, timing analysis, and GDSII export —
with a single command.

**If you haven't run anything yet, start with [Getting Started](getting_started.md)** — it
walks you through your first run in 8 steps. This manual covers everything else.

---

## Installation

```bash
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
python3 -m venv venv
source venv/bin/activate
pip install -e .
```

Requirements: Python 3.9+, Linux (Ubuntu 22.04+ / Debian 12+ / WSL2), 8GB+ RAM, 10GB+ disk.

### EDA Tools (optional for mock mode)

Real ASIC runs require the OpenROAD-flow-scripts toolchain. Install via:

- [ORFS Installation Guide](https://github.com/The-OpenROAD-Project/OpenROAD-Flow-Scripts)
- Or use the bundled installer: `gli-flow install`

The `doctor` command validates all tool dependencies.

### Smoke Test

```bash
gli-flow smoke-test
```

Validates five areas in one command: environment (Python + tools), database schema, telemetry configuration, dashboard dependencies, and example design validity.

See [Getting Started](getting_started.md) for the full onboarding flow.

---

## Environment Validation

```bash
gli-flow doctor
```

Checks:
- Python version (3.9+)
- EDA tools: yosys, openroad, magic, netgen, klayout
- PDK presence and configuration (`PDK_ROOT`)
- Environment variables (`ORFS_ROOT`)

Multi-candidate discovery: doctor finds all copies of each tool and selects the best one based on functional validation. If a broken wrapper shadows a valid system binary (e.g., `magic` version 0), doctor detects and reports it:

```bash
gli-flow doctor --repair-magic   # Auto-repair magic PATH shadowing
```

---

## Running Designs

### Design Directory Structure

Every design needs a directory with:
- RTL files (`.v` or `.sv`)
- `gli_manifest.yaml` — design configuration (clock period, pin constraints, PDK)

Example minimal manifest (`examples/counter/gli_manifest.yaml`):
```yaml
name: counter
rtl_files:
  - counter.v
top_module: counter
clock_port: clk
clock_period_ns: 10.0
pdk: sky130A
```

### Run a Design

```bash
gli-flow run <design_directory> [options]
```

Options:
- `--mock` — run without EDA tools
- `--verbose, -v` — full traceback on error
- `--threads, -j N` — parallel thread count
- `--memory, -m N` — memory limit in MB

Example:
```bash
gli-flow run examples/counter
```

### Mock Runs

Mock mode simulates the full pipeline without requiring any EDA tools:

```bash
gli-flow run examples/counter --mock
```

Use mock mode to:
- Validate design configuration
- Test the flow pipeline
- Onboard without installing the toolchain
- Develop and iterate on manifests

### Real ASIC Runs

Real runs require installed EDA tools and a configured PDK:

```bash
gli-flow run examples/counter
```

The full pipeline executes ~29 stages (major groups listed; some stages like fill, decap,
antenna check, ATPG run in parallel). The major stages are:

1. **Synthesis** (Yosys) — Verilog → gate-level netlist
2. **Floorplanning** — die area, I/O pin placement
3. **Placement** — standard cell placement
4. **CTS** (Clock Tree Synthesis) — build the clock distribution network
5. **Routing** — connect all cells with metal wires
6. **DRC** (Design Rule Check) — verify the layout against foundry rules (Magic + KLayout)
7. **LVS** (Layout vs. Schematic) — verify the layout matches the original design
8. **STA** (Static Timing Analysis) — verify all paths meet timing constraints (OpenSTA)
9. **GDS Export** — final layout file for tapeout

Each stage runs through OpenROAD Flow Scripts (ORFS) and reports results to the database.

### Run History

```bash
gli-flow history              # Show recent runs
gli-flow history --limit 50   # Show more runs
```

---

## Dashboard

```bash
gli-flow dashboard                # Full dashboard (backend + frontend)
gli-flow dashboard --backend-only # API server at http://127.0.0.1:8000
```

Pages:
- **Dashboard** — metric cards, QoR trend, recent runs
- **Run Detail** — timing, area, power, DRC/LVS, layout images, artifacts (10 tabs)
- **Run Matrix** — design × stage progress
- **Failure Atlas** — detected failures with resolution tracking
- **Telemetry** — transparency center showing what data is collected
- **Settings** — app configuration

See [Dashboard Guide](dashboard.md) for complete page documentation.

---

## Failure Detection

GLI-FLOW automatically detects failures from run logs and artifacts:

```bash
gli-flow diagnose <run_id>      # Analyze a failed run
gli-flow investigate <run_id>   # Deep AI-assisted investigation (if configured)
```

Failures are categorized by type (DRC, LVS, timing, tool crash) and severity (TAPEOUT_BLOCKING, WARNING, INFO). The Failure Atlas stores detection patterns and resolutions for future reference.

---

## Telemetry

GLI-FLOW collects anonymized runtime metrics to improve the tool. This is opt-in only.

```bash
gli-flow telemetry status       # View current settings
gli-flow telemetry enable       # Enable telemetry
gli-flow telemetry disable      # Disable telemetry
gli-flow telemetry mode full    # Share full telemetry
gli-flow telemetry mode atlas   # Share Failure Atlas data only
gli-flow telemetry mode local   # Keep everything local (default)
gli-flow telemetry preview      # View what would be uploaded
```

### Privacy Guarantees

- **Default: local-only.** No data leaves your machine without explicit consent.
- **Never uploaded:** RTL source, netlists, DEF/LEF/GDS files, bitstreams, liberty files, SDC constraints.
- **Sanitization:** All telemetry passes through a privacy validator before upload.
- **Transparency:** Preview payload before any upload.

---

## Support Bundle

Generate a diagnostic archive for issue reports:

```bash
gli-flow support-bundle                    # All recent runs
gli-flow support-bundle --run-id run_123   # Specific run
gli-flow support-bundle -o bundle.zip      # Custom output path
```

The archive contains: GLI-FLOW version, last 20 runs, system info, config, tool versions. Attach to GitHub issues.

---

## Common Workflows

### First-Time Setup
```bash
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
python3 -m venv venv
source venv/bin/activate
pip install -e .
gli-flow doctor
gli-flow run examples/counter --mock
```

### Run a Custom Design
```bash
mkdir my_design
# Add RTL files and gli_manifest.yaml
gli-flow run my_design --mock      # Validate first
gli-flow run my_design              # Real run
```

### Investigate a Failure
```bash
gli-flow history                    # Find the run ID
gli-flow diagnose <run_id>          # Automated analysis
gli-flow dashboard                  # Visual investigation
```

### Reset Database
```bash
gli-flow reset-runs                 # Clear all run data
```

---

## Troubleshooting

| Symptom | Likely Cause | Solution |
|---------|--------------|----------|
| `gli-flow: command not found` | pip bin not in PATH | Activate venv or add `~/.local/bin` to PATH |
| `magic version 0` in doctor | Broken wrapper shadows system binary | `gli-flow doctor --repair-magic` |
| PDK not found | `PDK_ROOT` not set | `export PDK_ROOT=/path/to/pdk` |
| Dashboard won't start | Port in use | Kill existing process or change port |
| Run fails with "Killed" or "MemoryError" | Out of memory | Reduce threads, increase swap |
| Database locked | Concurrent access | Remove `gli_flow.db-journal` |

For complete troubleshooting, see the [Troubleshooting Guide](../reference/troubleshooting.md).

---

## Glossary

Common terms you will see in GLI-FLOW output and documentation:

| Term | Meaning |
|------|---------|
| **ASIC** | Application-Specific Integrated Circuit — a custom chip designed for a specific purpose |
| **CTS** | Clock Tree Synthesis — building the network that distributes the clock signal to all flip-flops |
| **DRC** | Design Rule Check — verifying the layout follows manufacturing rules |
| **GDS / GDSII** | The standard file format for chip layout data (what you send to a fab) |
| **LVS** | Layout vs. Schematic — verifying the physical layout matches the original circuit |
| **ORFS** | OpenROAD Flow Scripts — the underlying RTL-to-GDS flow engine |
| **PDK** | Process Design Kit — the files that describe a chip manufacturing process (transistor models, design rules, standard cells) |
| **QoR** | Quality of Results — a 0–1 score combining timing, area, and power |
| **RTL** | Register Transfer Level — a hardware description (Verilog) that defines circuit behavior |
| **STA** | Static Timing Analysis — verifying all signal paths meet timing constraints |
| **TNS** | Total Negative Slack — sum of all timing violations (0 means no violations) |
| **WNS** | Worst Negative Slack — the worst timing violation (positive means timing passes) |

---

## Frequently Asked Questions

**Do I need EDA tools to try GLI-FLOW?**  
No. Mock mode runs the full pipeline without tools.

**What PDKs are supported?**  
sky130A (tested), gf180mcuD (partial), IHP SG13G2 (planned).

**What designs have been tested?**  
counter (~500 cells), uart (~2,000 cells), gcd (~500 cells), systolic array (~15,000 cells), PicoRV32 (~50,000 cells).

**Does GLI-FLOW upload my designs?**  
No. RTL, netlists, GDS, and constraints are never uploaded regardless of telemetry mode.

**Can I use GLI-FLOW offline?**  
Yes. Default telemetry mode is local-only.

**How do I report a bug?**  
Run `gli-flow support-bundle` and attach the `.zip` to https://github.com/green-lantern-industries/gli-flow/issues.

---

## See Also

- [Getting Started](getting_started.md)
- [Dashboard Guide](dashboard.md)
- [CLI Reference](../reference/cli_reference.md)
- [Troubleshooting](../reference/troubleshooting.md)
- [Telemetry & Privacy](../privacy/telemetry_and_privacy.md)
- [Known Limitations](KNOWN_LIMITATIONS.md)
