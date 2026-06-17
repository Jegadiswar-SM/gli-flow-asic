# GLI-FLOW Quickstart

## Goal

Get your first design running within 15 minutes.

---

## Step 1 — Install

```bash
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
pip install -e .
```

Verify installation:

```bash
gli-flow doctor
```

---

## Step 2 — Run a Mock Design

No EDA tools required. Test the pipeline with a built-in example:

```bash
gli-flow run examples/counter --mock
```

Expected output: successful run with QoR metrics, timing summary, and achievement banner.

---

## Step 3 — Create Your Own Design

### Option A: Interactive wizard

```bash
gli-flow quickstart
```

Prompts for a design name, creates a manifest, and generates skeleton RTL.

### Option B: From existing RTL

```bash
gli-flow init my_design --rtl path/to/top.v
```

Auto-detects `top_module`, `clock_port`, and RTL files.

### Option C: Manual

```bash
gli-flow init my_design
# Edit my_design/gli_manifest.yaml
```

---

## Step 4 — Run Your Design

```bash
# Mock mode (no EDA tools needed)
gli-flow run my_design --mock

# Real mode (requires installed EDA tools)
export PDK_ROOT=/pdk
export ORFS_ROOT=/path/to/orfs/flow
gli-flow run my_design
```

---

## Step 5 — View Results

```bash
gli-flow history        # Last 20 runs
gli-flow status         # Current run status
gli-flow doctor         # System health
```

Start the dashboard:

```bash
gli-flow dashboard
```

---

## Examples

```bash
# Run the included counter example in mock mode
gli-flow run examples/counter --mock

# Run GCD example
gli-flow run examples/gcd --mock

# Run UART example
gli-flow run examples/uart_top --mock
```

---

## Next Steps

- `docs/user_guide/USER_MANUAL.md` — Full command reference, manifest format, pipeline stages
- `docs/guides/troubleshooting_guide.md` — Common issues and resolutions
- `docs/developer/telemetry_pipeline_audit.md` — Telemetry transparency
