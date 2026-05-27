import json
from datetime import datetime, timezone
from pathlib import Path


ROOT_DIR = Path(__file__).resolve().parent.parent

DIAGNOSTIC_FILE = (
    ROOT_DIR
    / "intelligence"
    / "latest_diagnostics.json"
)

RECOMMENDATION_FILE = (
    ROOT_DIR
    / "intelligence"
    / "execution_recommendations.json"
)

CONFIDENCE_FILE = (
    ROOT_DIR
    / "intelligence"
    / "execution_confidence.json"
)

MEMORY_FILE = (
    ROOT_DIR
    / "intelligence"
    / "learning_memory.json"
)


def load_json(path):

    with open(path, "r") as f:
        return json.load(f)


def save_json(path, data):

    with open(path, "w") as f:
        json.dump(data, f, indent=4)


def build_execution_pattern(
    diagnostics,
    recommendations,
    confidence
):

    pattern = {
        "timestamp": datetime.now(timezone.utc).isoformat(),

        "diagnostic_categories": [
            item["category"]
            for item in diagnostics
        ],

        "recommendations": [
            item["recommendation"]
            for item in recommendations
        ],

        "execution_score": confidence["score"],

        "classification": (
            confidence["classification"]
        )
    }

    return pattern


def append_memory(memory, pattern):

    memory["execution_patterns"].append(
        pattern
    )

    return memory


def analyze_memory(memory):

    patterns = memory["execution_patterns"]

    recurring = {}

    for pattern in patterns:

        for category in pattern[
            "diagnostic_categories"
        ]:

            recurring[category] = (
                recurring.get(category, 0) + 1
            )

    return recurring


def print_results(memory, recurring):

    print("=" * 60)
    print("GLI-FLOW Historical Learning Engine")
    print("=" * 60)

    print(
        f"TOTAL PATTERNS LEARNED : "
        f"{len(memory['execution_patterns'])}"
    )

    print("\nRECURRING PATTERNS:")

    if not recurring:

        print("  No recurring patterns detected")

    else:

        for key, value in recurring.items():

            print(f"  {key:<30} {value}")

    print("\n========================================")
    print("[SUCCESS] Learning memory updated")
    print("========================================")


def main():

    diagnostics = load_json(
        DIAGNOSTIC_FILE
    )

    recommendations = load_json(
        RECOMMENDATION_FILE
    )

    confidence = load_json(
        CONFIDENCE_FILE
    )

    memory = load_json(
        MEMORY_FILE
    )

    pattern = build_execution_pattern(
        diagnostics,
        recommendations,
        confidence
    )

    memory = append_memory(
        memory,
        pattern
    )

    save_json(
        MEMORY_FILE,
        memory
    )

    recurring = analyze_memory(
        memory
    )

    print_results(
        memory,
        recurring
    )


if __name__ == "__main__":
    main()
