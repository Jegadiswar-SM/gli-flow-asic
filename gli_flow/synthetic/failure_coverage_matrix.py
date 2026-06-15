from dataclasses import dataclass, field
from typing import Dict, List, Set, Any
import json
from pathlib import Path

@dataclass
class FailureCoverageMatrix:
    """
    Tracks the coverage of various failure dimensions to identify gaps.
    """
    failure_types: Dict[str, Set[str]] = field(default_factory=lambda: {
        "Timing Violation": set(),
        "DRC": set(),
        "LVS": set(),
        # Add other initial failure types as needed, potentially from InjectionType
    })
    tools: Set[str] = field(default_factory=set)
    stages: Set[str] = field(default_factory=set)
    pdks: Set[str] = field(default_factory=set)
    designs: Set[str] = field(default_factory=set)

    def track_failure(
        self,
        failure_type: str,
        root_cause: str,
        tool: str,
        stage: str,
        pdk: str,
        design: str
    ):
        """
        Records an observed failure's attributes to build the coverage matrix.
        """
        if failure_type not in self.failure_types:
            self.failure_types[failure_type] = set()
        self.failure_types[failure_type].add(root_cause)
        self.tools.add(tool)
        self.stages.add(stage)
        self.pdks.add(pdk)
        self.designs.add(design)

    def get_coverage_gaps(self) -> Dict[str, Any]:
        """
        Identifies and returns areas with no observed failures.
        This is a placeholder for more sophisticated gap analysis.
        """
        gaps = {}
        # Example: if a known root cause for a failure type is missing
        # This would be expanded with defined 'expected' values for each dimension
        # For now, it just reports what has been seen.
        
        # Example of how to structure the output for missing coverage if we had "expected" sets
        # For instance, if we had a predefined set of all possible tools:
        # all_possible_tools = {"openroad", "magic", "innovus", "icc2", "prime-time"}
        # missing_tools = all_possible_tools - self.tools
        # if missing_tools:
        #     gaps["missing_tools"] = list(missing_tools)
        
        # Simple report of current tracked items
        gaps["tracked_failure_types"] = {ft: list(rc) for ft, rc in self.failure_types.items()}
        gaps["tracked_tools"] = list(self.tools)
        gaps["tracked_stages"] = list(self.stages)
        gaps["tracked_pdks"] = list(self.pdks)
        gaps["tracked_designs"] = list(self.designs)

        return gaps

    def generate_json(self, output_path: Path):
        """
        Generates the failure_coverage_matrix.json file.
        """
        matrix_data = {
            "failure_types": {ft: sorted(list(rc)) for ft, rc in self.failure_types.items()},
            "tools": sorted(list(self.tools)),
            "stages": sorted(list(self.stages)),
            "pdks": sorted(list(self.pdks)),
            "designs": sorted(list(self.designs)),
            "coverage_gaps": self.get_coverage_gaps() # Report current status as gaps
        }
        with open(output_path, "w") as f:
            json.dump(matrix_data, f, indent=4)
        print(f"Generated failure_coverage_matrix.json at {output_path}")

# Example usage (for testing purposes, not part of the class itself)
if __name__ == "__main__":
    matrix = FailureCoverageMatrix()
    matrix.track_failure("Timing Violation", "CTS", "openroad", "placement", "sky130A", "picorv32")
    matrix.track_failure("Timing Violation", "Routing", "openroad", "routing", "sky130A", "picorv32")
    matrix.track_failure("DRC", "Placement", "magic", "placement", "sky130A", "counter")
    matrix.track_failure("DRC", "Routing", "innovus", "routing", "sky130A", "counter")
    matrix.track_failure("LVS", "Net Mismatch", "netgen", "lvs", "sky130A", "gcd")

    # Adding a new failure type not initialized in the constructor
    matrix.track_failure("Power", "IR Drop", "innovus", "signoff", "sky130A", "ibex")

    output_file = Path("failure_coverage_matrix.json")
    matrix.generate_json(output_file)
