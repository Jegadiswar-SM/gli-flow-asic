import json
from pathlib import Path


ROOT_DIR = Path.home() / "GLI" / "tapeitout.com" / "gli-flow"

SIGNATURE_FILE = ROOT_DIR / "failure_atlas" / "signatures.json"

RUNS_DIR = ROOT_DIR / "runs"


def load_signatures():
    with open(SIGNATURE_FILE, "r") as f:
        return json.load(f)


def scan_file(log_file, signatures):
    findings = []

    try:
        content = log_file.read_text(errors="ignore")

        for sig in signatures:
            if sig["match"] in content:
                findings.append(sig)

    except Exception:
        pass

    return findings


def scan_runs():
    signatures = load_signatures()

    all_findings = []

    for run_dir in RUNS_DIR.iterdir():

        if not run_dir.is_dir():
            continue

        for log_file in run_dir.rglob("*.log"):

            findings = scan_file(log_file, signatures)

            for finding in findings:
                result = {
                    "run": run_dir.name,
                    "log": str(log_file),
                    "signature": finding
                }

                all_findings.append(result)

    return all_findings


def main():
    print("=" * 60)
    print("GLI-FLOW Failure Signature Engine")
    print("=" * 60)

    findings = scan_runs()

    if not findings:
        print("[INFO] No known signatures detected")
        return

    for item in findings:

        sig = item["signature"]

        print("\n----------------------------------------")
        print(f"RUN        : {item['run']}")
        print(f"SIGNATURE  : {sig['id']}")
        print(f"NAME       : {sig['name']}")
        print(f"SEVERITY   : {sig['severity']}")
        print(f"CATEGORY   : {sig['category']}")
        print(f"LOG FILE   : {item['log']}")

    print("\n========================================")
    print("[COMPLETE] Signature scan finished")
    print("========================================")


if __name__ == "__main__":
    main()
