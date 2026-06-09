## License Architecture

All GPL and GPL-3.0 tool invocations use subprocess exclusively to maintain license isolation.

Tools invoked via subprocess ONLY:
- OpenSTA (GPL-3.0) — via OpenROAD subprocess
- OpenROAD (BSD-3-Clause) — subprocess
- Magic (GPL-2.0) — subprocess
- Netgen (GPL-2.0) — subprocess
- KLayout (GPL-2.0) — subprocess
- Yosys (ISC) — subprocess

No GLI-FLOW Python code links against any GPL library at runtime.

## Tool Discovery Architecture

GLI-FLOW uses a three-layer tool discovery system designed to prevent PATH shadowing failures:

```
Layer 1: Multi-Candidate Discovery (gli_flow/core/tool_discovery.py)
  discover_<tool>_binaries() → list[ToolCandidate]
  ├── Config override (manifest / env var)
  ├── PATH search (shutil.which)
  ├── Well-known paths (/usr/bin, /usr/local/bin, ~/.local/bin, ...)
  └── Extra install dirs (ORFS, PDK, OpenROAD build)

Layer 2: Functional Validation (gli_flow/core/tool_discovery.py)
  validate_<tool>_candidate() → ValidationReport
  ├── File exists + executable
  ├── Process launches
  ├── Version detectable
  └── Tool-specific functional tests (TCL execution, DRC smoke, etc.)

Layer 3: Evidence-Based Ranking (gli_flow/core/tool_discovery.py)
  rank_tool_candidates() → sorted list
  ├── 1. Functional validation PASSED
  ├── 2. Version parseable
  └── 3. Source priority (config > user-local > venv > system)
```

Key principle: **Never trust PATH order alone. Never trust version strings alone. Always prefer functional validation + evidence.**

### Self-Healing Repair

The repair framework (`gli_flow/infrastructure/repair_actions.py`) follows a detect → repair → verify lifecycle:

- `PathShadowingRepair` — Detects broken local binary + valid system binary, renames broken binary
- `BrokenBinaryRepair` — Generic binary rename repair
- `repair_path_shadowing("magic")` — CLI entry point via `--repair-magic`

### Failure Atlas Integration

Environment failures are tracked in `failure_atlas/taxonomy.py` under the `ENVIRONMENT` domain:

| Category | Description |
| -------- | ----------- |
| `PATH_SHADOWING` | Broken local binary shadows valid system binary |
| `WRAPPER_MISSING` | Tcl wrapper references non-existent file |
| `BROKEN_SYMLINK` | Symlink points to non-existent target |
| `TOOL_BROKEN` | Binary exists but fails functional validation |
| `TOOL_WRONG_VERSION` | Binary exists but version is incompatible |
