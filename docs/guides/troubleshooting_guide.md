# Troubleshooting Guide

Common issues encountered when using GLI-FLOW and how to resolve them.

## Tool Not Found Errors

**Error message:** `gli-flow: command not found` or `Error: tool 'xyz' not found in PATH`

**Checklist:**
1. Verify GLI-FLOW is installed: `pip list | grep gli-flow`
2. Check your PATH includes the pip user bin directory:
   ```bash
   export PATH="$HOME/.local/bin:$PATH"   # Linux
   export PATH="$HOME/Library/Python/3.9/bin:$PATH"   # macOS
   ```
3. Confirm PDK tooling is installed: `gli-flow doctor --tools`

If the tool is still missing, reinstall with:

```bash
pip install --force-reinstall gli-flow
```

## PDK Issues

**Symptom:** `gli-flow doctor` reports PDK errors or flows fail with PDK-related messages.

**Common causes and fixes:**

| Problem | Solution |
|---|---|
| PDK not installed | Run `gli-flow pdk setup` to download and configure the standard PDK |
| Wrong PDK version | Run `gli-flow pdk update` to update to the recommended version |
| `PDK_ROOT` not set | Add `export PDK_ROOT=/path/to/pdk` to your shell rc file |
| PDK path contains spaces | Move the PDK to a path without spaces or create a symlink |
| Permission errors on PDK files | Run `chmod -R +r $PDK_ROOT` to fix read permissions |

## DRC Failures

**Symptom:** Design Rule Check violations reported after routing.

**Steps to resolve:**
1. Review the DRC report: `gli-flow log drc --last`
2. Identify the failing rules and their coordinates
3. Adjust routing constraints in your configuration:
   - Increase spacing or via margins
   - Add routing blockage over known-problematic areas
4. Re-run the flow with: `gli-flow run --continue`

If DRC failures persist, the design may need floorplan or placement changes.

## LVS Mismatches

**Symptom:** Layout vs. Schematic comparison reports mismatches.

**Debugging workflow:**
1. Run the LVS debugger: `gli-flow debug lvs --last`
2. Check for shorted or open nets in the layout
3. Verify power/ground connectivity
4. Ensure all standard cells are properly placed and connected

Common fixes:
- Re-run synthesis with `--retime` to clean up netlist issues
- Verify the extracted netlist matches the schematic: `gli-flow debug extract --last`
- Check for missing `connect` directives in your configuration

## Timing Failures

**Symptom:** Setup or hold time violations in static timing analysis.

**Resolution steps:**
1. View the timing report: `gli-flow log timing --last`
2. Identify the failing paths and their slack values
3. Adjust clock frequency or add pipeline stages if violations are large
4. For small setup violations, try: `gli-flow run --strategy area`
5. For hold violations, insert delay buffers: `gli-flow run --fix-hold`

## Out of Memory Errors

**Symptom:** Flow crashes with `Killed` or `MemoryError`.

**Mitigations:**
- Reduce parallel jobs: `gli-flow run --jobs 2`
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

**Symptom:** Corrupted or locked database when running `gli-flow db` commands.

**Recovery:**
1. Check database integrity: `gli-flow db check`
2. If corrupted, restore from backup: `gli-flow db restore --latest`
3. Manually remove lock files: `rm -f .gli-flow/db/*.lock`
4. Reset the database: `gli-flow db reset`
5. Re-run the previous flow step: `gli-flow run --from last`

Periodic backups are stored in `.gli-flow/backups/` by default.

## How to Generate a Support Bundle

When you need to report an issue, generate a support bundle to provide diagnostic information:

```bash
gli-flow support bundle --output support-bundle.tar.gz
```

This creates a compressed archive containing:
- GLI-FLOW version and installation info
- Last 3 flow logs
- System information (OS, Python version, available memory)
- Current configuration files
- Environment variables (redacted for secrets)

To upload the bundle when filing an issue:

```bash
gli-flow support upload support-bundle.tar.gz
```

Or attach `support-bundle.tar.gz` manually to your GitHub issue at https://github.com/gli-flow/gli-flow/issues.
