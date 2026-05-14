# GLI-FLOW Quickstart

## Goal

This quickstart validates that:
- your environment is configured correctly
- onboarding validation works
- GLI-FLOW infrastructure is operational

Estimated time:
- 5–10 minutes

---

# Step 1 — Clone Repository

```bash
git clone <repository-url>
cd gli-flow
```

---

# Step 2 — Create Python Environment

```bash
python3 -m venv venv
source venv/bin/activate
```

---

# Step 3 — Install Dependencies

```bash
pip install -r requirements.txt
```

---

# Step 4 — Validate Environment

Run:

```bash
python3 environment/validation/run_full_validation.py
```

Expected capabilities:
- environment validation
- remediation guidance
- environment fingerprinting
- consistency analysis
- validation report indexing

---

# Step 5 — Verify Reports

Generated reports will appear under:

```text
outputs/reports/
```

Expected examples:
- environment_validation_report.json
- environment_fingerprint.json
- environment_consistency_report.json
- validation_report_index.json

---

# Step 6 — Verify Repository Health

Run:

```bash
git status
```

Expected:
- clean repository
- deterministic structure
- no runtime pollution

---

# Current MVP Scope

Current MVP supports:
- onboarding validation
- environment diagnostics
- telemetry foundations
- QoR analytics foundations
- execution intelligence foundations

---

# Current Limitations

Current MVP does NOT yet provide:
- production tapeout flows
- cloud orchestration
- distributed execution
- advanced dashboard systems
- enterprise orchestration

These belong to future industrialization phases.

---

# Next Steps

See:
- docs/architecture/
- docs/setup/
- docs/execution/
- docs/troubleshooting/

for deeper documentation.
