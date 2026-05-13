import json
from pathlib import Path


ROOT_DIR = Path.home() / "GLI" / "tapeitout.com" / "gli-flow"

SIGNATURE_DB = ROOT_DIR / "failure_atlas" / "signatures.json"

REMEDIATION_DB = ROOT_DIR / "failure_atlas" / "remediation_db.json"

RUNS_DIR = ROOT_DIR / "runs"


def load_json(path):
    with open(path, "r") as f:
        return json.load(f)


def detect_signatures(content, signatures):
    detected = []

    for sig in signatures:
        if sig["match"] in content:
            detected.append(sig)

    return detected


def remediation_lookup(signature_id, remediation_db):

    for item in remediation_db:
        if item["signature_id"] == signature_id:
            return item["recommended_fix"]

    return ["No remediation available"]


def scan_logs():

    signatures = load_json(SIGNATURE_DB)

    remediation_db = load_json(REMEDIATION_DB)

    findings = []

    for run_dir in RUNS_DIR.iterdir():

        if not run_dir.is_dir():
            continue

        for log_file in run_dir.rglob("*.log"):

            try:
                content = log_file.read_text(errors="ignore")

            except Exception:
                continue

            detected = detect_signatures(content, signatures)

            for sig in detected:

                fixes = remediation_lookup(
                    sig["id"],
                    remediation_db
                )

                findings.append({
                    "run": run_dir.name,
                    "log": str(log_file),
                    "signature": sig,
                    "fixes": fixes
                })

    return findings


def main():

    print("=" * 60)
    print("GLI-FLOW Remediation Recommendation Engine")
    print("=" * 60)

    findings = scan_logs()

    if not findings:
        print("[INFO] No remediation cases detected")
        return

    for item in findings:

        sig = item["signature"]

        print("\n----------------------------------------")
        print(f"RUN         : {item['run']}")
        print(f"SIGNATURE   : {sig['id']}")
        print(f"NAME        : {sig['name']}")
        print(f"CATEGORY    : {sig['category']}")
        print("\nRECOMMENDED FIXES:")

        for fix in item["fixes"]:
            print(f"  - {fix}")

    print("\n========================================")
    print("[COMPLETE] Remediation analysis complete")
    print("========================================")


if __name__ == "__main__":
    main()
