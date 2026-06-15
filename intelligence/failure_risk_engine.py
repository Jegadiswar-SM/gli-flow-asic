from typing import Dict, Any
from intelligence.warehouse import TelemetryWarehouse

class FailureRiskEngine:
    def __init__(self, warehouse: TelemetryWarehouse):
        self.warehouse = warehouse

    def predict_risk(self, failure_type: str) -> float:
        # Calculate risk based on historical failure frequency
        all_records = self.warehouse.execution_records
        if not all_records:
            return 0.0
        
        failures = self.warehouse.get_execution_records_by_failure(failure_type)
        return len(failures) / len(all_records)
