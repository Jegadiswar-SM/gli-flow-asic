from dataclasses import dataclass
from typing import Dict, Any, List
from intelligence.intelligence_records import ExecutionIntelligenceRecord

@dataclass
class PredictionTrainingRecord:
    features: Dict[str, Any]
    target: Dict[str, Any]

class PredictionDatasetBuilder:
    def build(self, record: ExecutionIntelligenceRecord) -> PredictionTrainingRecord:
        # Transform ExecutionIntelligenceRecord into PredictionTrainingRecord
        return PredictionTrainingRecord(
            features=record.telemetry_summary,
            target={"outcome": record.outcome}
        )
