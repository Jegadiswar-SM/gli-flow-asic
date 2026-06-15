from typing import Dict, Any, List
from intelligence.warehouse import TelemetryWarehouse
from intelligence.recommendation_record import RecommendationRecord

class RecommendationEngine:
    def __init__(self, warehouse: TelemetryWarehouse):
        self.warehouse = warehouse

    def get_recommendation(self, failure_type: str) -> RecommendationRecord:
        # Fetch successful historical recommendations
        successes = self.warehouse.get_successful_recommendations(failure_type)
        if not successes:
            return RecommendationRecord(failure_type, "UNKNOWN", "Manual Review", 0.0, 0.0, "PENDING")
        
        # Simple recommendation: return the most frequent successful fix
        from collections import Counter
        fixes = Counter([r.recommendation for r in successes])
        best_fix = fixes.most_common(1)[0][0]
        
        return RecommendationRecord(failure_type, "Known", best_fix, 1.0, 1.0, "SUCCESS")

    def explain(self, rec: RecommendationRecord) -> str:
        return f"Fix '{rec.recommended_fix}' is recommended because it successfully resolved {rec.failure} in previous runs."
