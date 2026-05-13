import json
from pathlib import Path


ROOT_DIR = Path.home() / "GLI" / "tapeitout.com" / "gli-flow"

DIAGNOSTIC_FILE = (
    ROOT_DIR
    / "intelligence"
    / "latest_diagnostics.json"
)

RECOMMENDATION_DB = (
    ROOT_DIR
    / "intelligence"
    / "recommendation_db.json"
)

OUTPUT_FILE = (
    ROOT_DIR
    / "intelligence"
    / "execution_recommendations.json"
)


def load_json(path):

    with open(path, "r") as f:
        return json.load(f)


def generate_recommendations(
    diagnostics,
    recommendation_db
):

    recommendations = []

    for diagnostic in diagnostics:

        category = diagnostic["category"]

        for item in recommendation_db:

            if item["category"] == category:

                recommendations.append({
                    "category": category,
                    "recommendation": (
                        item["recommendation"]
                    )
                })

    return recommendations


def save_output(data):

    with open(OUTPUT_FILE, "w") as f:
        json.dump(data, f, indent=4)


def print_results(recommendations):

    print("=" * 60)
    print("GLI-FLOW Recommendation Intelligence")
    print("=" * 60)

    if not recommendations:

        print(
            "[SUCCESS] No remediation guidance required"
        )

    else:

        for item in recommendations:

            print("\n----------------------------------------")
            print(
                f"CATEGORY       : "
                f"{item['category']}"
            )

            print(
                f"RECOMMENDATION : "
                f"{item['recommendation']}"
            )

    print("\n========================================")


def main():

    diagnostics = load_json(
        DIAGNOSTIC_FILE
    )

    recommendation_db = load_json(
        RECOMMENDATION_DB
    )

    recommendations = generate_recommendations(
        diagnostics,
        recommendation_db
    )

    save_output(recommendations)

    print_results(recommendations)


if __name__ == "__main__":
    main()
