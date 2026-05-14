# GLI-FLOW

## Open ASIC Execution Intelligence Infrastructure

GLI-FLOW is an execution intelligence and orchestration infrastructure layer for open-source ASIC design workflows built around LibreLane/OpenROAD ecosystems.

The project focuses on:
- reproducible execution
- telemetry collection
- QoR-aware analytics
- regression tracking
- provenance systems
- release governance
- packaging infrastructure
- execution observability

GLI-FLOW is NOT a replacement for OpenROAD or LibreLane.

Instead, it acts as an infrastructure intelligence layer around them.

---

# Why GLI-FLOW Exists

Open-source ASIC flows currently provide:
- synthesis
- placement
- routing
- physical implementation

But large-scale execution infrastructure problems remain difficult:

- execution reproducibility
- telemetry visibility
- regression correlation
- execution observability
- artifact governance
- release validation
- infrastructure diagnostics
- execution intelligence

GLI-FLOW aims to address these workflow-level infrastructure gaps.

---

# Current MVP Capabilities

## Execution Infrastructure
- OpenROAD/LibreLane orchestration
- execution tracking
- runtime telemetry collection
- execution replay foundations

## Analytics
- QoR scoring
- execution metrics extraction
- reliability scoring
- trend analysis
- regression detection

## Governance
- release validation
- artifact manifests
- packaging systems
- provenance tracking

## Infrastructure Intelligence
- execution health analysis
- predictive diagnostics foundations
- Failure Atlas foundations
- execution correlation systems

---

# Repository Structure

| Directory | Responsibility |
|---|---|
| analytics/ | QoR analytics and metrics intelligence |
| configs/ | Runtime and toolchain configuration |
| docs/ | Documentation system |
| examples/ | Golden onboarding designs |
| execution/ | OpenROAD/LibreLane orchestration |
| failure_atlas/ | Failure intelligence systems |
| governance/ | Release governance |
| intelligence/ | Execution intelligence systems |
| outputs/ | Generated runtime artifacts |
| packaging/ | Packaging logic |
| provenance/ | Provenance tracking |
| regression/ | Regression analysis |
| replay/ | Execution replay |
| scheduler/ | Scheduling infrastructure |
| telemetry/ | Runtime telemetry |
| trends/ | Historical analysis |

---

# Current Development Status

Current state:

```text
GLI-FLOW v0.1-alpha
Foundational execution intelligence infrastructure
```

Current focus:
- MVP stabilization
- repository cleanup
- documentation
- onboarding
- usability
- release preparation

---

# Planned Future Direction (v2)

Planned industrialization areas include:
- advanced OpenROAD report parsing
- DEF/GDS analysis
- congestion analytics
- DRC intelligence
- IR drop analytics
- dashboard systems
- CI/CD integration
- distributed execution
- cloud orchestration
- ML-assisted optimization

---

# Current Limitations

GLI-FLOW is currently:
- early-stage infrastructure software
- Linux/WSL focused
- under active architectural stabilization
- not production-certified
- not yet tapeout-certified

---

# MVP Objectives

The current MVP aims to provide:
- deterministic execution foundations
- observable execution flows
- reproducible runtime environments
- QoR-aware infrastructure analytics
- infrastructure governance systems
- contributor-friendly repository structure

---

# Documentation

Additional documentation is being organized under:

- docs/architecture/
- docs/setup/
- docs/execution/
- docs/troubleshooting/
- docs/failure_atlas/

---

# License

Currently under active development.

Licensing strategy will be finalized during release preparation.

---

# Project Status

Active development in progress.
