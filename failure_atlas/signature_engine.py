import json
import re
from pathlib import Path


ROOT_DIR = Path(__file__).resolve().parent.parent

SIGNATURE_FILE = ROOT_DIR / "failure_atlas" / "signatures.json"

RUNS_DIR = ROOT_DIR / "runs"


def load_signatures():
    try:
        with open(SIGNATURE_FILE, "r") as f:
            return json.load(f)
    except (FileNotFoundError, json.JSONDecodeError):
        return []


def scan_file(log_file, signatures):
    findings = []

    try:
        content = log_file.read_text(errors="ignore")

        for sig in signatures:
            pattern = sig.get("observed_signature", "")
            if pattern:
                regex = re.compile(re.escape(pattern), re.IGNORECASE)
                if regex.search(content):
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
        print(f"RUN        : {item.get('run', '?')}")
        print(f"SIGNATURE  : {sig.get('atlas_id', '?')}")
        print(f"CATEGORY   : {sig.get('category', '?')}")
        print(f"SEVERITY   : {sig.get('severity', '?')}")
        print(f"SIGNATURE  : {sig.get('observed_signature', '?')}")
        print(f"LOG FILE   : {item.get('log', '?')}")

    print("\n========================================")
    print("[COMPLETE] Signature scan finished")
    print("========================================")


if __name__ == "__main__":
    main()
