# GLI-FLOW User Manual

This manual provides instructions for using GLI-FLOW to orchestrate RTL-to-GDS pipelines and analyze results.

## 1. Installation

See [Installation Guide](../setup/installation.md) for detailed steps.

## 2. First Run

```bash
# Interactive wizard to setup a new design
gli-flow quickstart

# Run a design in mock mode (no EDA tools needed)
gli-flow run examples/counter --mock
```

## 3. Environment Validation

```bash
# Validate environment and toolchain
gli-flow doctor

# Auto-repair detected issues
gli-flow doctor --fix

# Detailed discovery
gli-flow doctor --verbose -v
```

## 4. Design Management

```bash
# Create a new design manifest
gli-flow init my_chip

# Auto-detect from RTL files
gli-flow init my_chip --rtl-dir src/rtl
gli-flow init my_chip --rtl src/top.v

# Quick interactive setup
gli-flow quickstart
```

## 5. Running Designs

```bash
# Run a design (requires EDA tools)
gli-flow run examples/counter

# Mock mode (no tools needed)
gli-flow run . --mock

# Multi-threaded
gli-flow run designs/my_chip --threads 4

# Batch multiple designs
gli-flow batch designs/counter designs/uart --parallel 2
```

## 6. Execution History

```bash
# Show recent runs
gli-flow history

# Show last 10 run statuses
gli-flow status

# Reset all run data (irreversible)
gli-flow reset-runs
```

## 7. Dashboard

```bash
# Launch dashboard
gli-flow dashboard

# Backend only
gli-flow dashboard --backend-only
```

The dashboard provides 24 pages for managing designs, monitoring runs, and analyzing failures.

## 8. Failure Analysis

```bash
# Diagnose a failed run
gli-flow diagnose <run_id>

# AI-powered investigation (experimental)
gli-flow investigate <run_id>

# AI Investigation Assistant
gli-flow ai-assist --failure-type TIMING_VIOLATION --tool openroad
```

## 9. Failure Atlas

The Failure Atlas tracks failures across runs and enables resolution tracking.

```bash
# Diagnose a failed run to populate the atlas
gli-flow diagnose <run_id>
```

Access via dashboard **Failure Atlas** page or the analytics endpoints.

## 10. Resolution Intelligence

Resolutions are automatically tracked when a failed run recovers. View patterns and trust scores in the dashboard.

## 11. CI Mode

```bash
# Run with CI output
gli-flow ci examples/counter --junit results.xml --markdown report.md

# Compare against baseline
gli-flow ci examples/counter --baseline run_abc123 --wns-max -0.1
```

## 12. Telemetry

```bash
# View telemetry status
gli-flow telemetry status

# Enable/disable telemetry
gli-flow telemetry enable
gli-flow telemetry disable

# Set telemetry mode
gli-flow telemetry mode local
gli-flow telemetry mode full

# Show what would be uploaded
gli-flow show-telemetry <run_id>

# Export telemetry
gli-flow telemetry export --format csv

# View telemetry health
gli-flow telemetry health
```

## 13. Community Escalation

```bash
# Dry-run assessment
gli-flow escalate --failure-type UNKNOWN --tool yosys

# Submit with consent
gli-flow escalate --failure-type UNKNOWN --tool yosys --submit --consent
```

## 14. Support Bundles

```bash
# Generate support bundle
gli-flow support-bundle

# Include specific run
gli-flow support-bundle --run-id run_abc123 -o bundle.zip
```

## 15. Database Management

```bash
# Check migration status
gli-flow db status

# Apply pending migrations
gli-flow db migrate

# Show database location
gli-flow db path
```

## 16. Configuration

```bash
# View current configuration
gli-flow config

# Set telemetry preference
gli-flow config --telemetry off

# Interactive first-time setup
gli-flow setup
```

## 17. Upgrade Checks

```bash
# Check for newer versions
gli-flow upgrade-check
```

## 18. Report

```bash
# Show QoR report for a completed run
gli-flow report counter sky130hd
```

## 19. Troubleshooting

```bash
# Validate environment
gli-flow doctor

# Generate support bundle for debugging
gli-flow support-bundle

# Check telemetry health
gli-flow telemetry health

# Check database status
gli-flow db status
```
