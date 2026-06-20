# Getting Started

Welcome to GLI-FLOW. This guide walks you from clone to dashboard in 9 steps.

**Time to first run:** under 10 minutes (mock mode).  
**Prerequisites:** Python 3.9+, Linux, git, 8GB+ RAM, 10GB+ disk.

---

## Step 1: Clone

```bash
git clone https://github.com/green-lantern-industries/gli-flow.git
cd gli-flow
```

## Step 2: Install

```bash
python3 -m venv venv        # Create a virtual environment (required on modern Linux)
source venv/bin/activate     # Activate it — you need to do this every new terminal session
pip install -e .             # Install GLI-FLOW in editable mode
```

If `gli-flow` is not found after install: run `source venv/bin/activate` to activate your virtual environment. If you installed without a venv, add `export PATH="$HOME/.local/bin:$PATH"` to `~/.bashrc`.

## Step 3: Smoke Test

Verify your installation with a single command:

```bash
gli-flow smoke-test
```

Expected output:

```
Smoke Test Summary

  ✓ Environment
  ✓ Database
  ✓ Telemetry
  ✓ Dashboard
  ✓ Example Design

Result: GLI-FLOW is ready for use.
```

If any check fails, `smoke-test` shows what is missing and how to fix it.

## Step 4: Doctor (optional)

```bash
gli-flow doctor
```

Detailed environment report: Python version, EDA tools, PDK, environment variables.  
Safe to run at any time — never modifies files.

## Step 5: Run Counter (Mock)

Mock mode runs the full pipeline without requiring EDA tools:

```bash
gli-flow run examples/counter --mock
```

Expected output: a progress bar showing each stage, followed by:

```
QoR Score     0.6
WNS           0.05   (Worst Negative Slack — positive means timing passes)
✓ Tapeout Ready
```

**What to look for:** The final banner says "Run completed successfully" and "Tapeout Ready ✓".  
**QoR** (Quality of Results) is a 0–1 score combining timing, area, and power.  
**WNS** (Worst Negative Slack) measures timing — positive means the design meets timing.

## Step 6: Run Counter (Real)

If EDA tools are installed (Yosys, OpenROAD, Magic, Netgen, KLayout) and a PDK is configured:

```bash
gli-flow run examples/counter
```

This runs the complete RTL-to-GDS flow through real EDA tooling.

## Step 7: Open Dashboard

```bash
gli-flow dashboard
```

Opens the web dashboard at [http://127.0.0.1:5173](http://127.0.0.1:5173). Browse your run results: timing, area, DRC/LVS violations, and telemetry.

If the dashboard doesn't open, try:
```bash
gli-flow dashboard --backend-only   # API server only
```
Then open [http://127.0.0.1:8000/docs](http://127.0.0.1:8000/docs) in your browser.

**Where to find your counter results:** Dashboard → click the most recent run card → Summary tab → see WNS, TNS, utilization, and cell count.

## Step 8: View Telemetry Status

```bash
gli-flow telemetry status
```

Shows your current telemetry mode. Default is `local` — no data leaves your machine.

## Step 9: Generate Support Bundle

```bash
gli-flow support-bundle
```

Creates `support-bundle.zip` with diagnostics. Attach this file when reporting issues.

---

## What's Next?

- [User Manual](user_manual.md) — detailed usage for all features
- [Dashboard Guide](dashboard.md) — dashboard pages and features
- [CLI Reference](../reference/cli_reference.md) — every command
- [Troubleshooting](../reference/troubleshooting.md) — common issues
- [Telemetry & Privacy](../privacy/telemetry_and_privacy.md) — data handling
- [Known Limitations](KNOWN_LIMITATIONS.md) — what v1.0 does not do
