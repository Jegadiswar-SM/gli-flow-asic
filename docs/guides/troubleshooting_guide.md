# Troubleshooting Guide

Common issues encountered when using GLI-FLOW and how to resolve them.

## Installation Issues

**Error:** `gli-flow: command not found`

**Solutions:**
1. Activate your virtual environment: `source venv/bin/activate`
2. Ensure pip's bin directory is on PATH:
   ```bash
   export PATH="$HOME/.local/bin:$PATH"   # Linux
   ```
3. Verify installation: `pip list | grep gli-flow`
4. Reinstall: `cd gli-flow && pip install -e .`

## PATH Shadowing (Magic Version 0)

**Symptom:** `gli-flow doctor` reports `magic version 0` or `magic version unknown`.
A broken wrapper in `~/.local/bin/magic` shadows the valid system `/usr/bin/magic`.

**Root cause:** A local Tcl wrapper script in `~/.local/bin/` references a missing file. Because `~/.local/bin` appears earlier in PATH, the broken wrapper is found before the valid system binary.

**Detection:** `gli-flow doctor` uses multi-candidate discovery:

```
Magic Discovery — 2 candidate(s) found

Candidate #1                Candidate #2
Path:  ~/.local/bin/magic   Path:  /usr/bin/magic
Version: unknown             Version: 8.3.105
Status: BROKEN               Status: VALID
Reason: wrapper.tcl missing  Selected: YES
```

**Resolution:**
```bash
# Auto-repair: rename broken wrapper
gli-flow doctor --repair-magic

# Manual repair:
mv ~/.local/bin/magic ~/.local/bin/magic.broken

# Verify
gli-flow doctor
```

## PDK Issues

**Symptom:** `gli-flow doctor` reports PDK errors or flows fail with PDK-related messages.

**Common causes and fixes:**

| Problem | Solution |
|---|---|
| PDK not installed | Run `gli-flow install` to download and configure sky130 PDK |
| `PDK_ROOT` not set | Add `export PDK_ROOT=/path/to/pdk` to your shell rc file |
| PDK path contains spaces | Move the PDK to a path without spaces or create a symlink |
| Permission errors on PDK files | Run `chmod -R +r $PDK_ROOT` to fix read permissions |

## DRC Failures

**Symptom:** Design Rule Check violations reported after routing.

**Steps to resolve:**
1. View the DRC report in the dashboard or check `outputs/runs/<run_id>/reports/`
2. Identify the failing rules and their coordinates
3. Adjust routing constraints in `gli_manifest.yaml`:
   - Increase spacing or via margins
   - Add routing blockage over known-problematic areas
4. Re-run the flow

## LVS Mismatches

**Symptom:** Layout vs. Schematic comparison reports mismatches.

**Debugging workflow:**
1. Check for shorted or open nets in the layout
2. Verify power/ground connectivity
3. Ensure all standard cells are properly placed and connected

## Timing Failures

**Symptom:** Setup or hold time violations in static timing analysis.

**Resolution steps:**
1. View the timing report in the dashboard
2. Identify the failing paths and their slack values
3. Adjust clock frequency or add pipeline stages if violations are large
4. For small setup violations, change the flow strategy

## Out of Memory Errors

**Symptom:** Flow crashes with `Killed` or `MemoryError`.

**Mitigations:**
- Reduce parallel jobs in `gli_manifest.yaml`
- Increase swap space:
  ```bash
  sudo fallocate -l 8G /swapfile && sudo mkswap /swapfile && sudo swapon /swapfile
  ```
- Process smaller design blocks instead of the full chip
- Use the Docker image which may have higher memory limits
- On WSL, increase memory allocation in `.wslconfig`:
  ```ini
  [wsl2]
  memory=16GB
  ```

## Database Errors

**Symptom:** Corrupted or locked database.

**Recovery:**
1. Remove lock files: `rm -f ~/.gli-flow/gli_flow.db-journal`
2. Run database repair: `python -c "import sqlite3; conn=sqlite3.connect('~/.gli-flow/gli_flow.db'); conn.execute('PRAGMA integrity_check').fetchall()"`
3. If corrupted, delete and re-run: `rm ~/.gli-flow/gli_flow.db`

## How to Generate a Support Bundle

When you need to report an issue, generate a support bundle:

```bash
gli-flow support-bundle --output support-bundle.zip
```

This creates a ZIP archive containing:
- GLI-FLOW version and installation info
- Last 20 run summaries
- System information (OS, Python version, available memory)
- Configuration files
- Tool versions (redacted for secrets)

Attach `support-bundle.zip` to your GitHub issue.
