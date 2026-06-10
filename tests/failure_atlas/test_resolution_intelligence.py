import pytest
import sqlite3
from failure_atlas.correlation_engine import get_correlation_data
import os

# Set up a test database in-memory or a temporary file
DB_PATH = "test_failure_atlas.db"
os.environ["GLI_FLOW_DB"] = DB_PATH

def setup_module():
    conn = sqlite3.connect(DB_PATH)
    conn.execute("""
        CREATE TABLE failure_atlas_entries (
            id TEXT PRIMARY KEY,
            failure_type TEXT,
            severity TEXT,
            fix_applied INTEGER,
            fix_type TEXT,
            detected_at TEXT,
            after_metrics TEXT
        )
    """)
    # Insert mock data
    conn.execute("INSERT INTO failure_atlas_entries VALUES ('1', 'licon.8a', 'HIGH', 1, 'Die Padding', '2026-06-01', '{\"drc_total\": 0}')")
    conn.execute("INSERT INTO failure_atlas_entries VALUES ('2', 'licon.8a', 'HIGH', 1, 'Die Padding', '2026-06-02', '{\"drc_total\": 0}')")
    conn.execute("INSERT INTO failure_atlas_entries VALUES ('3', 'licon.8a', 'TAPEOUT_BLOCKING', 1, 'Util Reduction', '2026-06-03', '{\"drc_total\": 5}')")
    conn.commit()
    conn.close()

def test_resolution_intelligence_stats():
    data = get_correlation_data('licon.8a')
    eff = data['resolution_effectiveness']
    
    # Check "Die Padding" stats (2 attempts, 2 success = 100%)
    padding_fix = next(f for f in eff if f['fix_type'] == 'Die Padding')
    assert padding_fix['attempts'] == 2
    assert padding_fix['success_rate'] == 100.0
    
    # Check "Util Reduction" stats (1 attempt, 0 success = 0%)
    util_fix = next(f for f in eff if f['fix_type'] == 'Util Reduction')
    assert util_fix['attempts'] == 1
    assert util_fix['success_rate'] == 0.0

def test_important_run_correlation():
    data = get_correlation_data('licon.8a')
    padding_fix = next(f for f in data['resolution_effectiveness'] if f['fix_type'] == 'Die Padding')
    util_fix = next(f for f in data['resolution_effectiveness'] if f['fix_type'] == 'Util Reduction')
    
    # No important runs in the mock data for padding, 1 for util reduction
    assert padding_fix['important_runs'] == 0
    assert util_fix['important_runs'] == 1
