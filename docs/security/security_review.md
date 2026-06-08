# GLI-FLOW Security Review

## Audit Scope

**Target:** GLI-FLOW v0.1.0 (RTL-to-GDS silicon pipeline)
**Date:** 2026-06-08
**Scope:** Core library (`gli_flow/`), backend API (`backend/`), execution infrastructure, PDK handling, cloud integration, test suite.
**Out of scope:** Third-party vendor code under `examples/`, Docker base images, CI/CD runner environment.

---

## Findings

| ID | Severity | Category | Location | Finding |
|----|----------|----------|----------|---------|
| SEC-001 | **CRITICAL** | Subprocess Injection | `gli_flow/signoff.py:30-32` | `subprocess.run(cmd, shell=True)` — user-influenced path components (GDS, CDL, rule deck) are interpolated into a shell string without escaping, enabling arbitrary command injection. |
| SEC-002 | **HIGH** | Filesystem Access | `backend/server.py` (legacy) | Path traversal via `/runs/{run_id}/report/{path}` and `/runs/{run_id}/image/{path}`. Fixed with `_safe_run_path()`. Verify fix covers all endpoints. |
| SEC-003 | **HIGH** | No Privilege Separation | `gli_flow/backends/openroad_adapter.py` | Subprocesses run with full user permissions. EDA tool exploits could read/write any file the user can access. |
| SEC-004 | **MEDIUM** | Path Traversal | CLI `run` command | User-supplied design argument is not validated for `../` components. Malicious paths could reference files outside the project root. |
| SEC-005 | **MEDIUM** | Config Loading | YAML manifest loading | `gli_manifest.yaml` is loaded with `yaml.load()` (not `safe_load`). Arbitrary YAML tags could execute code. |
| SEC-006 | **MEDIUM** | Secret Handling | `gli_flow/security/file_protection.py:83` | `GLI_ENCRYPTION_SECRET` defaults to `"default-change-in-production"` when unset; no production guardrail forces the user to set it. |
| SEC-007 | **MEDIUM** | Config Loading | `gli_flow/core/subprocess_env.py` | `safe_env()` inherits all parent environment variables. Malicious `PATH`, `LD_PRELOAD`, or `PYTHONPATH` from the calling environment propagate to subprocesses. |
| SEC-008 | **LOW** | Temp Files | `gli_flow/signoff.py:84-92` | Netgen Tcl setup script written to a predictable path in `run_dir` with no cleanup. Another process on the same host could race-condition the file. |
| SEC-009 | **LOW** | Dependency Supply Chain | `setup.py` | No dependency pinning beyond major/minor ranges (`>=x.y.z`). Transitive updates could introduce untested or vulnerable packages. |
| SEC-010 | **LOW** | No Security Scanning | CI pipeline | No SAST (Bandit, CodeQL), SCA (`pip-audit`), or secret scanning integrated into CI. |

---

## Fixed: shell=True in signoff.py

**File:** `gli_flow/signoff.py`
**Change:** `_run_command()` now splits `cmd` with `shlex.split()` and passes the resulting list to `subprocess.run()` with `shell=False` (default).

```python
# Before (vulnerable):
result = subprocess.run(cmd, shell=True, capture_output=True, text=True, timeout=600)

# After (fixed):
import shlex
result = subprocess.run(shlex.split(cmd), capture_output=True, text=True, timeout=600)
```

This prevents shell metacharacter injection via crafted GDS paths, CDL paths, or design names. `shlex.split()` preserves POSIX shell quoting semantics so spaces in paths are still handled correctly.

---

## Recommendations

| Priority | ID | Recommendation | Effort |
|----------|----|----------------|--------|
| P0 | SEC-001 | ✅ **Done** — shell=True replaced with shlex + list form in `signoff.py`. | Done |
| P1 | SEC-006 | Require `GLI_ENCRYPTION_SECRET` in production: fail with `RuntimeError` if unset and not using KMS. | 1-2 days |
| P1 | SEC-005 | Replace all `yaml.load()` with `yaml.safe_load()`. Audit YAML loading across the codebase. | 1 day |
| P2 | SEC-002 | Audit backend for remaining path traversal vectors; add integration tests. | 2-3 days |
| P2 | SEC-004 | Add path containment validation to CLI `run` command design argument. | 1 day |
| P2 | SEC-003 | Document privilege separation boundary; add user-namespace sandboxing for EDA tools in multi-tenant deployments. | 2 weeks |
| P3 | SEC-007 | Strip dangerous env variables (`LD_PRELOAD`, `LD_LIBRARY_PATH`, `PYTHONPATH`, `PYTHONSTARTUP`) from `safe_env()`. | 1 day |
| P3 | SEC-008 | Write temp files to a `tempfile.mkstemp()` directory; clean up after execution. | 1 day |
| P3 | SEC-009 | Pin dependencies with lock files and add `pip-audit` to CI. | 1-2 days |
| P3 | SEC-010 | Integrate Bandit, CodeQL, and Gitleaks into CI pipeline. | 2-3 days |

---

## Overall Security Score

| Category | Score | Notes |
|----------|-------|-------|
| Subprocess Safety | **7/10** | `shell=True` fixed. Remaining: no sandboxing, env inheritance. |
| Input Validation | **5/10** | Path traversal partially fixed. No systematic input validation framework. |
| Secrets Management | **5/10** | KMS integration exists. Weak default secret, no production guardrail. |
| Dependency Security | **3/10** | No pinning, no SCA scanning. |
| CI/CD Security | **2/10** | No SAST, SCA, or secret scanning in CI. |
| Configuration Safety | **6/10** | YAML safe loading not enforced. |
| **Overall** | **5/10** | High-priority shell injection fixed. Systematic hardening (SAST, SCA, input validation, sandboxing) needed before production deployment. |
