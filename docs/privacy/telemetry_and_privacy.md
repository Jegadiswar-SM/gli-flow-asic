# Telemetry and Privacy Guide

GLI-FLOW collects anonymized execution telemetry.

## Collected Data
- QoR metrics (WNS, TNS, cell count, utilization, runtime)
- Stage completion status
- Failure classifications

## Data Not Collected
- RTL source code
- Design-identifying information
- GDS geometry

## Opt-out
```bash
gli-flow config --telemetry off
```
