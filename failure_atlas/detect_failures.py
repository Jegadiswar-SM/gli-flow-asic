import os


KNOWN_FAILURES = {
    "bad interpreter": {
        "failure_id": "TOOLCHAIN-0004",
        "title": "Stale Virtual Environment Interpreter"
    },

    "command not found": {
        "failure_id": "TOOLCHAIN-0002",
        "title": "Missing Executable in PATH"
    },

    "invalid option -- 'y'": {
        "failure_id": "TOOLCHAIN-0003",
        "title": "Unsupported Yosys Flag"
    },

    "No module named 'pyosys'": {
        "failure_id": "TOOLCHAIN-0005",
        "title": "Pyosys Missing"
    }
}


def scan_file(filepath):
    findings = []

    try:
        with open(filepath, "r", errors="ignore") as f:
            content = f.read()

            for signature, metadata in KNOWN_FAILURES.items():
                if signature in content:
                    findings.append(metadata)

    except Exception as e:
        print(f"[ERROR] Failed to scan {filepath}")
        print(str(e))

    return findings


def scan_directory(directory):
    all_findings = []

    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(".log"):
                path = os.path.join(root, file)

                findings = scan_file(path)

                if findings:
                    all_findings.append({
                        "log": path,
                        "findings": findings
                    })

    return all_findings


def main():
    target_dir = "../runs"

    print("=" * 60)
    print("GLI-FLOW Failure Detector")
    print("=" * 60)

    results = scan_directory(target_dir)

    if not results:
        print("[INFO] No known failures detected")
        return

    for result in results:
        print(f"\n[LOG] {result['log']}")

        for finding in result["findings"]:
            print(f"  [DETECTED] {finding['failure_id']}")
            print(f"  {finding['title']}")


if __name__ == "__main__":
    main()
