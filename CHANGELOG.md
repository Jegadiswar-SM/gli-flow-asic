# Changelog

All notable changes to GLI-FLOW-ASIC are documented here. Format follows [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

## [1.0.0] - 2026-06-03

### Added
- RTL-to-GDSII pipeline via LibreLane/OpenROAD
- Dual DRC (Magic + KLayout) for full coverage
- Multi-corner STA (TT, SS, FF process corners)
- Hold timing detection as TAPEOUT_BLOCKING
- SystemVerilog preprocessing via sv2v
- Latch inference detection — blocks synthesis
- Multi-driver net detection — blocks synthesis
- Missing module detection — blocks synthesis
- Global routing overflow fail-fast (>5% threshold)
- Antenna violation check with automatic diode insertion
- LC_ALL=C on all EDA subprocess calls (locale fix)
- OOM detection with human-readable error messages
- CDC multi-clock disclaimer (mandatory)
- LVS clean disclaimer (mandatory)
- RTL encryption at rest (AES-256)
- Run directory access control (per-user)
- Telemetry opt-out (gli-flow config --telemetry off)
- gli-flow show-telemetry command
- gli-flow doctor command with version checks
- gli-flow diagnose command for failed runs
- gli-flow quickstart interactive wizard
- gli-flow init manifest generator
- Rich terminal output with progress and ETA
- Log rotation (100MB, 5 rotations)
- Path length validation at manifest load
- Temp directory cleanup on failure
- KNOWN_LIMITATIONS.md
- Failure Atlas knowledge base

### Known Issues
- IHP SG13G2 PDK support planned for v1.1
- Hierarchical flows not yet supported
- OpenRAM SRAM integration partial
- No CDC analysis (documented limitation)
