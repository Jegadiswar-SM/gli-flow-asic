from dataclasses import dataclass, field
from typing import Dict, List, Any
from intelligence.intelligence_records import ExecutionIntelligenceRecord
from intelligence.recommendation_outcome_record import RecommendationOutcomeRecord

@dataclass
class TelemetryWarehouse:
    execution_records: List[ExecutionIntelligenceRecord] = field(default_factory=list)
    recommendation_records: List[RecommendationOutcomeRecord] = field(default_factory=list)

    def store_execution(self, record: ExecutionIntelligenceRecord):
        self.execution_records.append(record)

    def store_recommendation(self, record: RecommendationOutcomeRecord):
        self.recommendation_records.append(record)

    def get_execution_records_by_failure(self, failure_type: str) -> List[ExecutionIntelligenceRecord]:
        return [r for r in self.execution_records if r.failure == failure_type]

    def get_successful_recommendations(self, failure_type: str) -> List[RecommendationOutcomeRecord]:
        return [r for r in self.recommendation_records if r.failure_type == failure_type and r.outcome == "SUCCESS"]
