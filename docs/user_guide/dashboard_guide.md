# Dashboard Guide

The GLI-FLOW dashboard provides a visual interface for managing designs, monitoring runs, and analyzing results.

## Launch

```bash
gli-flow dashboard                # Backend + frontend
gli-flow dashboard --backend-only  # Backend only at http://127.0.0.1:8000
```

## Pages

### Execution
| Page | Description |
|------|-------------|
| **Dashboard** | Home page: metric cards, QoR trend chart, recent runs, health status |
| **Run Design** | CLI command reference for running designs |
| **Run Matrix** | Design × Stage matrix showing execution progress |
| **Run Monitor** | Live run monitor and recent activity feed |
| **Important Runs** | Starred runs filtered view |
| **Artifacts** | Browse run artifacts with preview |

### Run Detail (10 tabs)
1. **Summary** — Run metadata, trust score, QoR, WNS, TNS
2. **Timing** — Multi-corner STA results
3. **Area & Power** — Utilization, cell count, die area, power breakdown
4. **DRC/LVS** — DRC violations, LVS results
5. **Layout Images** — 5 layout image views (floorplan, placement, routing, etc.)
6. **Artifacts** — Full artifact viewer with text/image/PDF/HTML preview
7. **Failure Atlas** — Per-run failure detections with resolution linking
8. **Reproducibility** — Reproducibility manifest viewer
9. **AI Investigation** — LLM-powered root cause analysis
10. **Compare** — Side-by-side run comparison with regression detection

### Intelligence
| Page | Description |
|------|-------------|
| **QoR Analytics** | QoR score analysis and trends over time |
| **Regression Detector** | Run-to-run regression comparison |
| **Trends & Reports** | Trends, timeline, top runs |
| **Failure Atlas** | Full failure atlas with search, filters, analytics, AI feedback, escalation |
| **Engineering Dashboard** | Community escalations, knowledge gaps, resolution statistics |

### Governance
| Page | Description |
|------|-------------|
| **Provenance** | Provenance graph and reproducibility manifests |
| **Release Validation** | Release candidate validation list |
| **Policy Suite** | Governance policy status |

### Beta
| Page | Description |
|------|-------------|
| **Beta Dashboard** | Beta ops dashboard with weekly report |
| **Feedback Center** | Submit and browse feedback |
| **Product Analytics** | Product usage analytics |
| **User Journey** | Funnel analysis (install → first run → failure → success) |

### System
| Page | Description |
|------|-------------|
| **Infrastructure** | API/tools health, system status |
| **Telemetry** | Telemetry transparency center (5 sub-tabs: Events, Unknown Failures, Escalations, Resolution Patterns, Upload Preview) |
| **Telemetry Health** | Telemetry pipeline health metrics |
| **Telemetry Replay** | Telemetry replay/dry-run tool |
| **Settings** | App settings with AI provider status |
| **Help** | Help links, quick commands reference |

## API Base URL

Configured via `VITE_API_URL` environment variable. Defaults to empty string (same origin).
Vite dev server proxies `/api/*` paths to `http://127.0.0.1:8000`.
