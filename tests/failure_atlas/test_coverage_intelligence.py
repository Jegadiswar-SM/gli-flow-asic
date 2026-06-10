import pytest
import sqlite3
import os
from failure_atlas.coverage_engine import get_coverage_data

DB_PATH = "test_failure_atlas.db"
os.environ["GLI_FLOW_DB"] = DB_PATH

def setup_module():
    conn = sqlite3.connect(DB_PATH)
    conn.execute("CREATE TABLE failure_atlas_entries (failure_type TEXT, fix_applied INTEGER, detected_at TEXT)")
    conn.execute("INSERT INTO failure_atlas_entries VALUES ('licon.8a', 1, '2026-06-01')")
    conn.execute("INSERT INTO failure_atlas_entries VALUES ('licon.8a', 0, '2026-06-02')")
    conn.commit()
    conn.close()

def test_coverage_data_aggregation():
    data = get_coverage_data()
    # Check if aggregation works
    common = next(f for f in data['common_failures'] if f['failure_type'] == 'licon.8a')
    assert common['count'] == 2
    
    # Check resolved/unresolved counts
    resolved = next(f for f in data['most_resolved'] if f['failure_type'] == 'licon.8a')
    assert resolved['count'] == 1
    
    unresolved = next(f for f in data['most_unresolved'] if f['failure_type'] == 'licon.8a')
    assert unresolved['count'] == 1
