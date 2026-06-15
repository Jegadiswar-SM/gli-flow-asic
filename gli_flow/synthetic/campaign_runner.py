from dataclasses import dataclass, field
from typing import Any, Dict, List, Optional
import random
import multiprocessing # Import for parallel processing
import time # For simulating runtime

from gli_flow.synthetic.golden_designs import GoldenDesign
from gli_flow.synthetic.failure_injector import FailureInjector, InjectionConfig, InjectionType

@dataclass
class SyntheticRunResult:
    """
    Represents the outcome of a single synthetic design execution.
    """
    design_name: str
    injection_config: Optional[InjectionConfig] = None
    runtime_sec: float = 0.0
    memory_mb: float = 0.0 # New field for memory
    status: str = "SUCCESS"
    root_cause: Optional[str] = None
    telemetry_summary: Dict[str, Any] = field(default_factory=dict)
    resolution_candidate: Optional[str] = None
    # Ensure reproducibility of the run if it involves randomized elements
    run_seed: Optional[int] = None
    # Additional fields to capture from the prompt
    qor: Optional[float] = None
    fingerprint: Optional[str] = None

@dataclass
class CampaignResult:
    """
    Aggregates results from an entire execution campaign.
    """
    campaign_id: str
    design_name: str
    total_runs: int
    successful_runs: int
    failed_runs: int
    results: List[SyntheticRunResult] = field(default_factory=list)
    average_runtime: float = 0.0
    average_memory: float = 0.0
    success_rate: float = 0.0
    dataset_yield: int = 0 # Number of records generated, e.g., failure records

class CampaignRunner:
    """
    Manages and executes campaigns of synthetic design runs with failure injections.
    """
    def __init__(self, failure_injector: FailureInjector):
        self.failure_injector = failure_injector

    def _run_single_variation(
        self,
        design: GoldenDesign,
        injection_types: Optional[List[InjectionType]],
        base_seed: Optional[int],
        variation_index: int,
        # Pass failure_injector as a target, not part of self, for multiprocessing
        # In actual multiprocessing, objects with non-picklable attributes cannot be directly passed
        # This is a simplification for a synthetic environment.
        # In a real scenario, FailureInjector might be re-instantiated in each worker process,
        # or its state passed explicitly.
    ) -> SyntheticRunResult:
        """
        Executes a single variation of a campaign run.
        """
        run_seed = base_seed + variation_index if base_seed is not None else random.randint(0, 100000)
        random.seed(run_seed) # Ensure run-level reproducibility for this process

        injection_config: Optional[InjectionConfig] = None
        if injection_types:
            chosen_injection_type = random.choice(injection_types)
            injection_params = {"variation_id": variation_index, "random_val": random.random()}
            injection_config = InjectionConfig(
                injection_type=chosen_injection_type,
                parameters=injection_params,
                seed=run_seed,
                description=f"Campaign variation {variation_index} of {chosen_injection_type.name}"
            )
            # Simulating injection - in a real scenario, this would apply actual changes
            # We don't call self.failure_injector.inject here directly because it's in a separate process
            # Instead, we just simulate the outcome.
            # If the FailureInjector had picklable state that needed to be shared, that would be more complex.
            # For this synthetic environment, the "injection" is implicit in the run result.
            print(f"  - Run {variation_index+1} (PID: {multiprocessing.current_process().pid}): Simulating injection {chosen_injection_type.name}")


        # Simulate execution and capture outcomes
        simulated_status = "SUCCESS" if random.random() > 0.1 else "FAILURE" # 10% failure rate
        simulated_runtime = design.base_metrics["runtime_sec"] * (1 + random.uniform(-0.1, 0.2))
        simulated_qor = design.expected_qor * (1 + random.uniform(-0.05, 0.05))
        simulated_memory = random.uniform(100.0, 500.0) # Placeholder for memory in MB

        run_result = SyntheticRunResult(
            design_name=design.name,
            injection_config=injection_config,
            runtime_sec=simulated_runtime,
            memory_mb=simulated_memory,
            status=simulated_status,
            root_cause="Timing violation" if simulated_status == "FAILURE" else None,
            telemetry_summary={"area": 1000 + random.randint(-100,100), "power": 50 + random.randint(-5,5)},
            resolution_candidate="Adjust clock period" if simulated_status == "FAILURE" else None,
            run_seed=run_seed,
            qor=simulated_qor,
            fingerprint=design.fingerprint # This would ideally be a run-specific fingerprint
        )
        return run_result

    def run_campaign(
        self,
        design: GoldenDesign,
        num_variations: int,
        injection_types: Optional[List[InjectionType]] = None,
        base_seed: Optional[int] = None,
        num_workers: int = 1, # New parameter for parallel workers
    ) -> CampaignResult:
        """
        Executes a campaign for a given design with specified parameter variations and injections.
        Supports parallel execution using multiprocessing.

        Args:
            design: The golden design to run the campaign on.
            num_variations: The number of parameter variations/executions to perform.
            injection_types: A list of InjectionTypes to randomly apply. If None, no injection.
            base_seed: Optional base seed for reproducibility of the entire campaign.
            num_workers: The number of parallel workers to use. Defaults to 1 (sequential).

        Returns:
            A CampaignResult object summarizing the campaign.
        """
        campaign_id = f"{design.name}_campaign_{random.randint(1000, 9999)}"
        print(f"Starting campaign '{campaign_id}' for design '{design.name}' with {num_variations} variations using {num_workers} workers.")

        campaign_results = CampaignResult(
            campaign_id=campaign_id,
            design_name=design.name,
            total_runs=num_variations,
            successful_runs=0,
            failed_runs=0,
            results=[],
            average_runtime=0.0, # Initialize new fields
            average_memory=0.0,
            success_rate=0.0,
            dataset_yield=0,
        )

        all_run_results: List[SyntheticRunResult] = []

        if num_workers > 1:
            # Prepare arguments for multiprocessing map
            # We need to create a list of tuples, one for each call to _run_single_variation
            # Since _run_single_variation doesn't directly use self.failure_injector,
            # we don't need to worry about pickling the entire CampaignRunner.
            args = [
                (design, injection_types, base_seed, i)
                for i in range(num_variations)
            ]
            
            # Using Pool to run in parallel
            with multiprocessing.Pool(num_workers) as pool:
                # The _run_single_variation needs to be a static method or a top-level function
                # to be picklable for multiprocessing. For simplicity here, we assume it's callable.
                # In a real project, this might require refactoring _run_single_variation
                # out of the class or making it a staticmethod.
                all_run_results = pool.starmap(self._run_single_variation, args)
        else:
            # Sequential execution
            for i in range(num_variations):
                run_result = self._run_single_variation(design, injection_types, base_seed, i)
                all_run_results.append(run_result)

        total_runtime = 0.0
        total_memory = 0.0
        generated_records_count = 0 # Placeholder for dataset yield

        for run_result in all_run_results:
            campaign_results.results.append(run_result)
            total_runtime += run_result.runtime_sec
            total_memory += run_result.memory_mb

            if run_result.status == "SUCCESS":
                campaign_results.successful_runs += 1
            else:
                campaign_results.failed_runs += 1
            
            # Simple placeholder for dataset yield: count failed runs as generated records
            if run_result.status == "FAILURE":
                generated_records_count += 1
        
        campaign_results.average_runtime = total_runtime / num_variations if num_variations > 0 else 0.0
        campaign_results.average_memory = total_memory / num_variations if num_variations > 0 else 0.0
        campaign_results.success_rate = campaign_results.successful_runs / num_variations if num_variations > 0 else 0.0
        campaign_results.dataset_yield = generated_records_count

        print(f"Campaign '{campaign_id}' completed. Successful runs: {campaign_results.successful_runs}/{campaign_results.total_runs}")
        print(f"  Avg Runtime: {campaign_results.average_runtime:.2f}s, Avg Memory: {campaign_results.average_memory:.2f}MB")
        print(f"  Success Rate: {campaign_results.success_rate:.2f}, Dataset Yield: {campaign_results.dataset_yield}")
        return campaign_results
