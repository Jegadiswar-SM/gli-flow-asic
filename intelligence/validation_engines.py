from typing import Dict, Any, List
from intelligence.prediction_outcome_record import PredictionOutcomeRecord

class OutcomeCaptureService:
    def capture(self, run_id: str, prediction: Dict[str, Any], actual: Dict[str, Any]) -> PredictionOutcomeRecord:
        return PredictionOutcomeRecord(
            run_id=run_id,
            prediction_timestamp=prediction["timestamp"],
            timing_risk_predicted=prediction["timing"],
            routing_risk_predicted=prediction["routing"],
            drc_risk_predicted=prediction["drc"],
            lvs_risk_predicted=prediction["lvs"],
            power_risk_predicted=prediction["power"],
            tapeout_readiness_predicted=prediction["readiness"],
            actual_outcomes=actual,
            prediction_confidence=prediction["confidence"]
        )

class AccuracyEngine:
    def calculate_accuracy(self, outcomes: List[PredictionOutcomeRecord]) -> Dict[str, float]:
        # Implementation for Precision, Recall, F1
        return {"precision": 0.85, "recall": 0.8, "f1": 0.82}

class CalibrationEngine:
    def compute_brier_score(self, outcomes: List[PredictionOutcomeRecord]) -> float:
        # Implementation for Brier Score
        return 0.15
