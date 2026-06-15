from typing import Dict, Any, List
from failure_atlas.prediction.similarity import ExecutionSimilarityEngine
from failure_atlas.repository import FailureAtlasRepository

class FailureRiskEngine:
    """Predicts risk of various failure types based on historical similarities and trust-weighted Failure Atlas data."""
    
    def __init__(self, db_path: str):
        self.similarity_engine = ExecutionSimilarityEngine(db_path)
        self.repo = FailureAtlasRepository(db_path)
        
    def predict_risk(self, current_metrics: Dict[str, Any]) -> Dict[str, Any]:
        similar_runs = self.similarity_engine.find_similar(current_metrics)
        
        # Aggregate risk with trust weighting and Failure Atlas signatures
        risk_data = {
            "Timing": {"risk": 0.0, "reason": []},
            "Routing": {"risk": 0.0, "reason": []},
            "DRC": {"risk": 0.0, "reason": []},
            "LVS": {"risk": 0.0, "reason": []},
            "Power": {"risk": 0.0, "reason": []}
        }
        
        if not similar_runs:
            return risk_data
            
        total_trust = 0.0
        
        for run in similar_runs:
            # Trust score weighting (Placeholder: use actual trust score from repository if available)
            trust_weight = run.get("similarity", 0.5) 
            total_trust += trust_weight
            
            failures = self.repo.get_failures_for_run(run["run_id"])
            for f in failures:
                f_type = f.get("failure_type", "UNKNOWN")
                if f_type in risk_data:
                    # Risk increases with Failure Atlas occurrences, weighted by similarity
                    risk_data[f_type]["risk"] += (100.0 * trust_weight)
                    
                    # Add reason if it matches Failure Atlas signature
                    signature = f.get("signature")
                    if signature and signature not in risk_data[f_type]["reason"]:
                        risk_data[f_type]["reason"].append(signature)
        
        # Calculate weighted average risk
        for f_type in risk_data:
            if total_trust > 0:
                risk_data[f_type]["risk"] = (risk_data[f_type]["risk"] / total_trust)
            
        return risk_data
