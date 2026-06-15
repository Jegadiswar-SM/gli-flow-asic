from typing import List
from failure_atlas.repository import FailureAtlasRepository
from failure_atlas.prediction.models import PredictionTrainingRecord

class PredictionDatasetBuilder:
    """Builds prediction training datasets from historical intelligence records."""
    
    def __init__(self, db_path: str):
        self.repo = FailureAtlasRepository(db_path=db_path)
        
    def build(self) -> List[PredictionTrainingRecord]:
        failures = self.repo.get_all_failures(limit=1000)
        records = []
        for f in failures:
            # Construct a record from a failure atlas entry
            records.append(PredictionTrainingRecord(
                run_id=f["run_id"],
                design_name="", # Needs resolution via Run DB
                tool=f.get("tool_name", "UNKNOWN"),
                stage=f.get("tool_stage", "UNKNOWN"),
                telemetry_summary=f.get("before_metrics", {}),
                failure_fingerprint=f.get("signature", "NONE"),
                root_cause=f.get("description", "UNKNOWN"),
                resolution=f.get("fix_description", "NONE"),
                trust_score=0.8, # Placeholder for trust mechanism
                outcome="SUCCESS" if f.get("fix_applied") else "FAILURE"
            ))
        return records
