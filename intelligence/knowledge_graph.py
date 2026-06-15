from typing import Dict, Any, List
from intelligence.warehouse import TelemetryWarehouse

class KnowledgeGraphBuilder:
    def __init__(self, warehouse: TelemetryWarehouse):
        self.warehouse = warehouse
        self.graph = {"entities": [], "relationships": []}

    def build_from_warehouse(self):
        # Build graph based on real warehouse records
        for record in self.warehouse.execution_records:
            self.graph["entities"].append({"type": "Failure", "id": record.failure})
            self.graph["relationships"].append({"from": record.failure, "to": record.root_cause, "type": "causes"})
