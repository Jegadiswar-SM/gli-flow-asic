# Magic Root Cause Analysis

## Issue: Magic Fails to Execute in Batch Mode

### Symptoms
- `magic -dnull -noconsole -T <techfile> <script>` produces no output or crashes
- `crashbackups disable` error during DRCI runs
- LVS extraction produces no SPICE file

### Root Cause 1: Wrong Magic Binary (Wrapper Script)
The system package `magic` (apt) installs `/usr/bin/magic` as a **wrapper script**, not the actual binary. This wrapper:
- Invokes Tcl/Tk Wish for GUI mode
- Does not properly handle `-dnull` (no display) in batch mode
- Tries to open the display even with `-dnull` flag

**Fix**: Use `magicdnull` directly, located at:
```
/usr/lib/x86_64-linux-gnu/magic/tcl/magicdnull
```
Invoke with:
```
magicdnull -nowrapper -d NULL -rcfile <magicrc> script.tcl
```

### Root Cause 2: Wrong Tech File Version Check
`sky130A.tech` (line 19) requires `magic-8.3.411`, but the installed version is `magic-8.3.105` (Ubuntu apt). Magic refuses to load the tech file on version mismatch.

**Fix**: Patch the version requirement in `sky130A.tech`:
```
requires magic-8.3.0
```

### Root Cause 3: CAD_ROOT Environment Variable Breaks Magic
The `safe_env()` function in `subprocess_env.py` sets `CAD_ROOT=/home/bolter/.local/lib`, which interferes with Magic's internal resource lookup. When set, Magic subprocess runs but produces no output — no `.ext` file, no `.spice` file. No error is raised.

**Fix**: Remove `CAD_ROOT` from `safe_env()` entirely.

## Detection
- In the run logs, look for `crashbackups disable` errors (Magic not starting)
- In the run logs, look for "Magic extraction did not produce SPICE file"
- The DRC summary shows 0 checks run (Magic DRC didn't execute)

## Affected Versions
- Magic 8.3.105 (Ubuntu apt package)
- GLI-FLOW versions prior to this fix
