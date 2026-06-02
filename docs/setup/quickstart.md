# GLI-FLOW Quickstart

## Goal

This quickstart validates that:
- your environment is configured correctly
- onboarding validation works
- GLI-FLOW infrastructure is operational

Estimated time:
- 5–10 minutes

---

# Step 1 — Clone Repository

```bash
git clone <repository-url>
cd gli-flow
```

---

# Step 2 — Create Python Environment

```bash
python3 -m venv venv
source venv/bin/activate
```

---

# Step 3 — Install gli-flow

```bash
pip install -e .
```

---

# Step 4 — Quick Start with Auto-Detection

### Option A: Create a manifest from existing RTL

```bash
# Single RTL file
gli-flow init my_design --rtl path/to/top.v

# Directory of RTL files (scans .v/.sv recursively)
gli-flow init my_design --rtl-dir rtl/
```

This automatically detects `top_module`, `design_name`, `clock_port`, and lists all RTL files.

### Option B: Interactive wizard

```bash
gli-flow quickstart
```

If the `rtl/` directory already has `.v`/`.sv` files, `quickstart` auto-discovers them and populates the manifest from your actual design.

### Option C: Boilerplate (edit manually)

```bash
gli-flow init my_design
# Edit my_design/gli_manifest.yaml, then add RTL files
```

---

# Step 5 — Run the Pipeline

```bash
# With mock adapter (no EDA tools required)
gli-flow run my_design --mock

# With real EDA tools
export PDK_ROOT=/pdk
export ORFS_ROOT=/path/to/orfs/flow
gli-flow run my_design
```

The manifest is validated before the run starts — missing fields or broken file paths are caught immediately.

---

# Step 6 — View Results

```bash
gli-flow history        # Last 20 runs
gli-flow status         # Current run status
gli-flow report <name>  # QoR report
```

---

# Examples

```bash
# Run the included counter example in mock mode
gli-flow run examples/counter --mock

# Create your own design from a UART RTL directory
gli-flow init my_uart --rtl-dir examples/uart/rtl
gli-flow run my_uart --mock
```

---

# Next Steps

See:
- docs/USER_MANUAL.md — full command reference, manifest format, pipeline stages
- docs/architecture/ — system design
- docs/setup/installation.md — detailed installation
