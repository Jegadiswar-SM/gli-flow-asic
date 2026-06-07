You are acting as:

* Principal Backend Engineer
* Principal Data Platform Architect
* Principal ASIC CAD Infrastructure Engineer
* Product Architect for Failure Atlas

Project:
GLI-FLOW-ASIC

Mission:
Failure Atlas already contains the core components:

* detector.py
* signature_engine.py
* signatures.json
* remediation_db.json
* FailureAtlasEntry schema

The problem is NOT missing detection logic.

The problem is that Failure Atlas is disconnected from the actual execution pipeline.

Your job is to make Failure Atlas fully operational end-to-end.

Do NOT add new failure signatures.

Do NOT invent new AI features.

Do NOT redesign the architecture.

Wire the existing components together.

==================================================
CURRENT AUDIT FINDINGS
======================

Existing:

* failure_atlas/detector.py
* failure_atlas/signature_engine.py
* signatures.json
* remediation_db.json
* FailureAtlasEntry schema

Missing:

* Pipeline invocation
* Persistence layer
* API layer
* Dashboard integration
* Failure Atlas page

Current UI:

FailureAtlasTab:

<div>
Failure Atlas data available in output reports directory.
</div>

Current state:

Failure Atlas effectively does not exist from a user perspective.

==================================================
PHASE 1
PIPELINE INTEGRATION
====================

Locate:

TelemetryParser.parse_all()

Locate:

FlowOrchestrator execution path.

Requirements:

After telemetry extraction is complete:

metrics
↓
detect_failures(metrics)
↓
FailureAtlasEntry[]

must execute automatically.

Failure detection must occur for every completed run.

Do not require CLI invocation.

Verification:

Every run produces Failure Atlas entries.

==================================================
PHASE 2
DATABASE PERSISTENCE
====================

Create:

failure_atlas_entries

SQLite table.

Required fields:

id
run_id
failure_id
failure_type
severity
title
description
recommended_fix
confidence
signature
detected_at

Support:

fix_applied
fix_type
fix_description
fix_run_id

Create migrations.

Create repository layer.

Verification:

Failures survive process restart.

==================================================
PHASE 3
SIGNATURE ENGINE INTEGRATION
============================

Currently:

signature_engine.py

is CLI-only.

Requirements:

Integrate into pipeline.

For every run:

1. Metrics detection
2. Log signature detection

Merge results.

Deduplicate entries.

Verification:

Failure Atlas includes:

Metric-based failures
+
Log-based failures

==================================================
PHASE 4
API LAYER
=========

Create:

GET /runs/{run_id}/failures

Returns:

All failures associated with run.

Create:

GET /failures

Returns:

Paginated failure catalog.

Create:

GET /failures/{failure_id}

Returns:

Failure details
Remediation
Associated runs

Verification:

Swagger/OpenAPI updated.

==================================================
PHASE 5
FAILURE ATLAS TAB
=================

Replace placeholder.

Current:

<div>
Failure Atlas data available in output reports directory.
</div>

Build real component.

Display:

Failure Type
Severity
Description
Confidence
Recommended Fix

Support:

Expand/collapse details.

Support:

Multiple failures per run.

==================================================
PHASE 6
FAILURE ATLAS PAGE
==================

Sidebar currently contains:

Failure Atlas

but page does not exist.

Build:

FailureAtlasPage

Features:

Search
Filter
Severity filter
Failure type filter

Display:

Most common failures
Recent failures
Failure trends

==================================================
PHASE 7
RUN DETAIL INTEGRATION
======================

Run Details page must show:

Detected Failures

Example:

Routing Overflow
Severity: HIGH
Confidence: 0.92

Recommended Fix:
Reduce utilization
Increase die area
Adjust placement density

Display remediation directly.

==================================================
PHASE 8
FIX CHAIN SUPPORT
=================

FailureAtlasEntry already contains:

fix_applied
fix_type
fix_description
fix_run_id

Implement support.

Example:

Run 100:
Hold violation

Run 101:
User fixes issue

Atlas should show:

Original Failure
↓
Fix Applied
↓
Resulting Run

Build foundation now.

==================================================
PHASE 9
TELEMETRY LINKAGE
=================

Store:

run_id
parent_run_id

Allow future:

Failure evolution
Regression tracking
Fix effectiveness analysis

Required for:

GLI-SDI
Future LCM training

==================================================
PHASE 10
TESTING
=======

Create tests:

1. Failure persistence
2. API responses
3. Dashboard rendering
4. Signature detection
5. Metrics detection
6. Deduplication
7. Fix chain linkage

Coverage target:

90%+

==================================================
DELIVERABLES
============

Produce:

1. Architecture diagram
2. Database schema
3. API documentation
4. UI screenshots
5. Test results
6. Example failure records

Final assessment:

Can a user:

* Run GLI-FLOW
* Open dashboard
* View detected failures
* Read remediation guidance
* Track fixes

without touching CLI tools?

If not:

FAIL

If yes:

PASS


Yes, but **not the way a normal bug tracker would implement it.**

The current Fix Chain schema is actually one of the foundations for the future GLI-SDI and Failure Atlas intelligence layer.

So don't implement:

```text
Mark As Fixed
```

buttons.

Implement:

```text
Engineer Action Tracking
```

---

# What I Would Build

When a failure exists:

```text
Run 100

Failure:
Hold Violation
```

The engineer creates:

```text
Run 101
```

and records:

```text
Primary Action:
Pipeline Insertion

Secondary Action:
Retiming

Notes:
Added register stage between MAC and SRAM
```

Store:

```text
fix_type
fix_description
fix_run_id
```

---

Then Failure Atlas can build:

```text
Failure
↓
Fix Applied
↓
Result
```

chains.

---

# Why This Matters

Future dataset:

```text
Failure:
Negative Setup Slack

Context:
Logic depth = 14

Engineer Action:
Added Pipeline Stage

Result:
WNS improved by 1.2ns
```

This is dramatically more valuable than:

```text
Status:
Fixed
```

---

# What To Add

## Backend

Add endpoint:

```text
POST /failures/{failure_id}/resolution
```

Payload:

{
"fix_type": "...",
"fix_description": "...",
"fix_run_id": 123
}

---

## Resolution Types

Create controlled taxonomy:

```text
pipeline_insertion
retiming
floorplan_change
macro_relocation
clock_restructuring
buffer_insertion
constraint_update
utilization_reduction
pdn_adjustment
placement_density_change
routing_strategy_change
cdc_fix
reset_fix
rtl_bug_fix
latch_removal
multi_driver_fix
module_integration_fix
sram_integration_fix
other
```

Do NOT use free-form only.

---

## Dashboard

On failure details:

```text
Link Resolution
```

User selects:

* Resolution Type
* Resolution Description
* Fixed Run

---

Display:

```text
Run 100
Failure:
Hold Violation

↓ Fixed By

Run 101
Action:
Pipeline Insertion

Result:
WHS improved from -0.32ns to +0.08ns
```

---

# Even More Important

Store:

```text
before_metrics
after_metrics
```

at time of linking.

Example:

```json
{
  "wns_before": -1.20,
  "wns_after": 0.35,
  "tns_before": -45.3,
  "tns_after": 0.0
}
```

---

# This Is The Real Goal

Not:

```text
Failure Atlas
```

The real goal is:

```text
Failure
→ Human Fix
→ QoR Change
→ Outcome
```

Because eventually GLI-SDI learns:

```text
For this failure pattern,
80% of engineers used
pipeline insertion.

Average improvement:
1.4ns WNS.
```

That is where the intelligence comes from.

---

So my recommendation is:

```text
YES
Implement Phase 8.

BUT

Implement Resolution Tracking,
not a simple "mark fixed" feature.
```

That will create a much more valuable telemetry and Failure Atlas dataset for tapeitout.com's long-term roadmap.

You are acting as:

* Principal Data Platform Architect
* Failure Atlas Architect
* Semiconductor Reliability Engineer
* Product Analytics Architect

Project:
GLI-FLOW-ASIC

Mission:

Failure Atlas now has:

✓ Failure Detection
✓ Persistence
✓ API
✓ Dashboard
✓ Resolution Tracking
✓ Fix Chains
✓ Before/After Metrics

The next step is NOT AI.

The next step is:

Failure Atlas Analytics.

Build a data-driven analytics layer that helps engineers understand:

* Which failures happen most often
* Which fixes work best
* Which fixes actually improve QoR
* Which fixes are ineffective
* How failure patterns evolve over time

Do NOT build LLMs.

Do NOT build AI recommendations.

Do NOT build GLI-SDI.

Use actual recorded Failure Atlas data.

==================================================
PHASE 1
ANALYTICS DATABASE LAYER
========================

Create analytics aggregation layer.

Support:

1. Failure frequency
2. Fix effectiveness
3. Resolution success rate
4. QoR improvement tracking
5. Trend analysis

Required metrics:

failure_count
fixed_count
unfixed_count

success_rate

avg_wns_improvement
avg_tns_improvement
avg_qor_improvement

avg_resolution_time

last_seen

==================================================
PHASE 2
RESOLUTION CONFIDENCE
=====================

Add:

resolution_confidence

Enum:

HIGH
MEDIUM
LOW

Computation:

HIGH:

* Failure resolved
* WNS improved
* TNS improved
* QoR improved
* No similar failure in linked run

MEDIUM:

* Partial improvement
* Failure reduced but still exists

LOW:

* Failure still exists
* QoR unchanged
* Metrics worsened

Store in DB.

Expose via API.

Display in dashboard.

==================================================
PHASE 3
FIX EFFECTIVENESS ENGINE
========================

Create analytics:

Failure Type
↓
Fix Type
↓
Outcome

Example:

Hold Violation

Pipeline Insertion
Success Rate: 78%

Retiming
Success Rate: 64%

Constraint Update
Success Rate: 22%

Calculate automatically from historical data.

Requirements:

Minimum sample count visible.

Display:

sample_size

to avoid misleading percentages.

==================================================
PHASE 4
QOR IMPROVEMENT ANALYTICS
=========================

For every fix type calculate:

Average WNS Improvement

Average TNS Improvement

Average QoR Improvement

Example:

Pipeline Insertion

Average WNS:
+1.42ns

Average TNS:
+45.3ns

Average QoR:
+0.23

Display top-performing fixes.

==================================================
PHASE 5
FAILURE TREND ENGINE
====================

Create:

Failure Trends

Support:

7 days
30 days
90 days
All Time

Examples:

Routing Overflow
32%

Hold Violations
21%

Macro Placement
18%

Show:

Count
Percentage
Trend Direction

Trend:

UP
DOWN
STABLE

==================================================
PHASE 6
NEW API ENDPOINTS
=================

Create:

GET /analytics/failure-trends

GET /analytics/fix-effectiveness

GET /analytics/qor-improvements

GET /analytics/common-failures

GET /analytics/resolution-confidence

Support:

date ranges
pagination
filtering

==================================================
PHASE 7
FAILURE ATLAS DASHBOARD
=======================

Upgrade FailureAtlasPage.

Add sections:

---

SECTION A
Overview Cards
--------------

Total Failures

Resolved Failures

Success Rate

Average QoR Improvement

---

SECTION B
Most Common Failures
--------------------

Table:

Failure
Count
%
Trend

---

SECTION C
Most Effective Fixes
--------------------

Table:

Fix Type
Success Rate
Sample Size

---

SECTION D
QoR Impact
----------

Table:

Fix Type
Avg WNS
Avg TNS
Avg QoR

---

SECTION E
Resolution Confidence
---------------------

HIGH
MEDIUM
LOW

distribution chart

==================================================
PHASE 8
RUN DETAIL IMPROVEMENTS
=======================

For each resolved failure display:

Resolution Confidence

Example:

✓ Resolved via Retiming

Confidence:
HIGH

Before:
WNS = -1.20

After:
WNS = +0.35

QoR:
+0.47

==================================================
PHASE 9
ANTI-MISLEADING SAFEGUARDS
==========================

Do NOT display effectiveness rankings unless:

sample_size >= configurable threshold

Default:

5

Display:

"Insufficient Data"

instead of fake statistics.

This is critical.

Failure Atlas must not create misleading engineering guidance.

==================================================
PHASE 10
TESTING
=======

Create tests for:

* effectiveness calculations
* trend calculations
* confidence calculations
* QoR delta calculations
* insufficient data handling

Coverage target:

90%+

==================================================
DELIVERABLES
============

Produce:

1. Analytics schema
2. API documentation
3. Dashboard screenshots
4. Sample analytics output
5. Test results

Final question:

Can an engineer now answer:

* What failures occur most often?
* Which fixes work best?
* Which fixes improve timing most?
* Which fixes are unreliable?

using Failure Atlas alone?

If not:

FAIL

If yes:

PASS

Important:

Build statistical analytics only.

Do NOT build AI recommendations yet.

Do NOT generate automatic fix suggestions from tiny datasets.

Failure Atlas must earn intelligence through data first.

You are acting as:

* Principal ASIC Physical Design Engineer
* Principal Timing Closure Engineer
* Failure Atlas Architect
* Semiconductor Knowledge Systems Architect

Project:
GLI-FLOW-ASIC

Mission:

Failure Atlas currently has:

* Failure Detection
* Failure Persistence
* Resolution Tracking
* Fix Chains
* Analytics Foundation

However, the historical dataset is still small.

We need a temporary Industry Knowledge Base that provides engineers with genuine, widely accepted remediation strategies from established ASIC/FPGA engineering practice.

IMPORTANT:

Do NOT present these as AI recommendations.

Do NOT present these as Failure Atlas learned recommendations.

Present them as:

"Industry Knowledge Base"

with clear attribution that they are standard engineering remediation techniques.

==================================================
PHASE 1
KNOWLEDGE BASE SCHEMA
=====================

Create:

knowledge_base.json

Structure:

failure_type

description

common_causes

remediation_strategies

references

verification_steps

confidence

==================================================
PHASE 2
INITIAL FAILURE COVERAGE
========================

Create entries for:

Timing:

* Setup Violation
* Hold Violation
* Excessive TNS
* Clock Skew Issues

Routing:

* Routing Overflow
* Congestion
* DRC Routing Violations

Physical Design:

* Macro Placement Failure
* Placement Density Issues
* Utilization Too High
* Antenna Violations
* Metal Density Violations

Verification:

* LVS Mismatch
* Missing Module
* Multi Driver Nets
* Latch Inference

Memory:

* SRAM Integration Errors
* SRAM Power Connectivity Issues

Flow:

* OOM
* Tool Crashes
* Missing Artifacts

==================================================
PHASE 3
REMEDIATION STRATEGIES
======================

For each failure provide:

Example:

Setup Violation

Common Industry Strategies:

* Pipeline insertion
* Retiming
* Logic restructuring
* Buffer insertion
* Floorplan optimization
* Clock tree optimization

Expected Effect:

WNS improvement

Verification:

Re-run STA
Check WNS/TNS

---

Hold Violation

Common Industry Strategies:

* Delay buffers
* Hold fixing
* Clock path balancing
* Cell resizing

Expected Effect:

WHS improvement

Verification:

Re-run hold STA

---

Routing Overflow

Common Industry Strategies:

* Reduce utilization
* Increase die area
* Macro relocation
* Placement density reduction

Expected Effect:

Reduced congestion

Verification:

Global route overflow percentage

==================================================
PHASE 4
QOR IMPROVEMENT KNOWLEDGE
=========================

Create:

qor_playbook.json

Categories:

Timing Improvement

Area Optimization

Power Optimization

Congestion Reduction

For each:

* technique
* tradeoffs
* expected impact
* validation method

==================================================
PHASE 5
API
===

Create:

GET /knowledge/failures

GET /knowledge/failures/{failure_type}

GET /knowledge/qor

GET /knowledge/search?q=

==================================================
PHASE 6
DASHBOARD
=========

When a failure is detected:

Show:

---

Failure Detected

## Setup Violation

Industry Knowledge Base

Common Strategies:

✓ Pipeline insertion
✓ Retiming
✓ Buffer insertion
✓ Logic restructuring

Verification Steps:

1. Re-run STA
2. Verify WNS > 0
3. Verify TNS = 0

---

Do NOT label this:

Recommended Fix

Label it:

Industry Knowledge Base

==================================================
PHASE 7
FUTURE SEPARATION
=================

Maintain strict separation:

Section A:

Industry Knowledge Base

(static engineering knowledge)

Section B:

Failure Atlas Analytics

(real GLI-FLOW observed outcomes)

Section C:

Future SDI Recommendations

(not implemented)

==================================================
PHASE 8
ANTI-HALLUCINATION REQUIREMENT
==============================

Do not invent fixes.

Only include:

* well-established ASIC practices
* well-established FPGA practices
* industry-standard timing closure methods
* industry-standard physical design techniques

No speculative remediation.

==================================================
OUTPUT
======

Produce:

1. Knowledge base schema
2. Initial database
3. APIs
4. Dashboard integration
5. Example screenshots

Success Criteria:

A user with a detected failure can immediately see:

* What the failure means
* Common causes
* Industry-standard remediation approaches
* How to verify the fix

without confusing this information with Failure Atlas learned intelligence.
You are acting as:

* Principal Physical Design Engineer
* Principal Timing Closure Engineer
* Failure Atlas Architect
* Semiconductor Reliability Engineer
* Engineering Productivity Architect

Project:
GLI-FLOW-ASIC

Mission:

Failure Atlas currently provides:

✓ Failure Detection
✓ Knowledge Base
✓ Resolution Tracking
✓ Analytics
✓ QoR Deltas
✓ Fix Chains

However Failure Atlas is still mostly a Failure Viewer.

The goal of this project is to transform Failure Atlas into a true engineering painkiller.

Do NOT build AI.

Do NOT build LLMs.

Do NOT build chatbots.

Do NOT build speculative recommendations.

Build engineering intelligence features based on actual telemetry, run history, and failure records.

==================================================
PHASE 1
FAILURE DIFF ENGINE
===================

Problem:

Run 100 passes.

Run 101 fails.

Engineer does not know what changed.

Build:

Failure Diff Engine.

Compare:

* WNS
* TNS
* WHS
* THS
* QoR
* Utilization
* Congestion
* DRC Count
* LVS Status
* Runtime
* Tool Versions
* Flow Config

Output:

What Changed?

Example:

Utilization:
72% → 84%

Congestion:
18% → 47%

WNS:
+0.22ns → -1.81ns

Likely Regression:
Placement Density Increase

Store:

run_diff_record

Create:

GET /runs/{run_id}/diff/{previous_run_id}

==================================================
PHASE 2
REGRESSION DETECTION ENGINE
===========================

Problem:

Engineers know current run failed.

They do not know when failure first appeared.

Build:

Regression Timeline Engine.

Detect:

First Run
Last Healthy Run
First Failing Run

Example:

Routing Overflow

First Seen:
Run 337

Last Clean:
Run 336

Regression Window:
1 Run

Store:

regression_events

Create:

GET /regressions

==================================================
PHASE 3
SIMILAR FAILURE SEARCH
======================

Problem:

Engineers solve same problem repeatedly.

Build:

Failure Similarity Engine.

Compare:

Failure Type
Metrics
Severity
Domain
Signature
QoR Pattern

Return:

Most Similar Historical Failures

Example:

Current Failure:
Routing Overflow

Found:

42 Similar Cases

Successful Fixes:

Macro Relocation
Success Rate 81%

Die Area Increase
Success Rate 72%

Placement Density Reduction
Success Rate 69%

Requirements:

Use actual historical Failure Atlas data.

No AI.

No embeddings.

Start rule-based.

==================================================
PHASE 4
ROOT CAUSE LOCALIZATION
=======================

Problem:

Atlas says failure exists.

Engineer still hunts through reports.

Build:

Root Cause Extraction Layer.

For Timing:

Extract:

Worst Paths
Worst Slack
Logic Depth

Example:

DSP
→ LUT
→ LUT
→ SRAM

Logic Levels:
14

Likely Cause:
Combinational Depth

---

For Routing:

Extract:

Congested Regions
Overflow Hotspots

---

For DRC:

Extract:

Top Violation Types

---

For LVS:

Extract:

Mismatch Categories

Display:

Likely Investigation Starting Point

==================================================
PHASE 5
FAILURE TIMELINE
================

Build:

Failure Evolution Timeline

Example:

Run 100

Hold Violation

WHS:
-0.40ns

↓

Run 101

Retiming

WHS:
-0.15ns

↓

Run 102

Buffer Insertion

WHS:
+0.03ns

Show:

Failure
Fix
Outcome

As chronological chain.

==================================================
PHASE 6
TEAM KNOWLEDGE RETENTION
========================

Add:

Engineer Notes

For each failure resolution.

Fields:

author
note
timestamp

Example:

"Inserted pipeline register after MAC stage."

Store permanently.

Display with resolution chain.

==================================================
PHASE 7
MEAN TIME TO RESOLUTION
=======================

Compute:

MTTR

Per:

Failure Type

Example:

Hold Violations

Average Resolution Time:
4.2 Hours

Routing Overflow

Average Resolution Time:
1.8 Days

Create:

GET /analytics/mttr

==================================================
PHASE 8
FAILURE ATLAS DASHBOARD
=======================

Add New Sections:

---

## Failure Trends

Most Common Failures

---

## Regression Events

Newly Introduced Failures

---

## Most Effective Fixes

Historical Outcomes

---

## MTTR

Resolution Speed

---

## Similar Failures

Historical Cases

==================================================
PHASE 9
ENGINEERING SAFETY
==================

Do NOT show:

Success Rates

unless:

sample_size >= 5

Do NOT show:

Root Cause

without:

confidence score

Do NOT show:

Fix Effectiveness

without:

sample size

==================================================
PHASE 10
DELIVERABLE
===========

Failure Atlas should answer:

1. What failed?
2. Why did it fail?
3. What changed?
4. When did the failure first appear?
5. Has anyone solved this before?
6. What fixes historically worked?
7. How long does this failure usually take to resolve?
8. What should I investigate first?

without requiring engineers to manually inspect dozens of reports.

Final Assessment:

If Atlas merely displays failures:

FAIL

If Atlas actively reduces debugging time:

PASS

