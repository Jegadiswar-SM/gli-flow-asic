import { useState, useEffect } from "react"
import { ArrowLeft, Clock, AlertTriangle, CheckCircle, XCircle, Download, ChevronDown, ChevronRight, ExternalLink } from "lucide-react"

const API_BASE = import.meta.env.VITE_API_URL || ""

function TabButton({ label, active, onClick }) {
  return (
    <button
      onClick={onClick}
      className={`px-3 py-1.5 text-xs font-[Work_Sans] rounded-t border-b-2 transition-colors ${
        active ? "border-meridian-gold text-abyss-ink font-semibold" : "border-transparent text-[#6B7280] hover:text-abyss-ink"
      }`}
    >
      {label}
    </button>
  )
}

function SummaryTab({ run }) {
  return (
    <div className="grid grid-cols-3 gap-4">
      <div className="bg-white border border-stone-ridge rounded-lg p-4">
        <p className="text-[10px] font-[Work_Sans] text-[#6B7280] uppercase tracking-wider">Status</p>
        <p className="text-sm font-semibold mt-1">{run.status || "—"}</p>
      </div>
      <div className="bg-white border border-stone-ridge rounded-lg p-4">
        <p className="text-[10px] font-[Work_Sans] text-[#6B7280] uppercase tracking-wider">QoR Score</p>
        <p className="text-sm font-semibold mt-1">{run.qor_score?.toFixed(2) ?? "—"}</p>
      </div>
      <div className="bg-white border border-stone-ridge rounded-lg p-4">
        <p className="text-[10px] font-[Work_Sans] text-[#6B7280] uppercase tracking-wider">Current Stage</p>
        <p className="text-sm font-semibold mt-1">{run.current_stage || "—"}</p>
      </div>
      <div className="bg-white border border-stone-ridge rounded-lg p-4">
        <p className="text-[10px] font-[Work_Sans] text-[#6B7280] uppercase tracking-wider">WNS</p>
        <p className={`text-sm font-semibold mt-1 ${(run.wns ?? 0) < 0 ? "text-red-600" : "text-green-600"}`}>{run.wns?.toFixed(3) ?? "—"}</p>
      </div>
      <div className="bg-white border border-stone-ridge rounded-lg p-4">
        <p className="text-[10px] font-[Work_Sans] text-[#6B7280] uppercase tracking-wider">TNS</p>
        <p className={`text-sm font-semibold mt-1 ${(run.tns ?? 0) < 0 ? "text-red-600" : "text-green-600"}`}>{run.tns?.toFixed(3) ?? "—"}</p>
      </div>
      <div className="bg-white border border-stone-ridge rounded-lg p-4">
        <p className="text-[10px] font-[Work_Sans] text-[#6B7280] uppercase tracking-wider">Runtime</p>
        <p className="text-sm font-semibold mt-1">{run.runtime_sec ? `${run.runtime_sec}s` : "—"}</p>
      </div>
    </div>
  )
}

function TimingTab({ run }) {
  const telemetry = run.telemetry || {}
  const metrics = telemetry.metrics || {}
  return (
    <div className="space-y-3">
      <div className="bg-white border border-stone-ridge rounded-lg p-4">
        <h4 className="text-xs font-semibold mb-3">Setup Timing</h4>
        <div className="grid grid-cols-3 gap-4">
          <div><p className="text-[10px] text-[#6B7280]">WNS</p><p className="text-sm font-semibold">{(run.wns ?? metrics.wns)?.toFixed(3) ?? "—"}</p></div>
          <div><p className="text-[10px] text-[#6B7280]">TNS</p><p className="text-sm font-semibold">{(run.tns ?? metrics.tns)?.toFixed(3) ?? "—"}</p></div>
          <div><p className="text-[10px] text-[#6B7280]">Fmax</p><p className="text-sm font-semibold">{metrics.fmax_mhz ? `${metrics.fmax_mhz} MHz` : "—"}</p></div>
        </div>
      </div>
      {run.sta_corners && run.sta_corners.length > 0 && (
        <div className="bg-white border border-stone-ridge rounded-lg p-4">
          <h4 className="text-xs font-semibold mb-3">Multi-Corner STA</h4>
          <div className="space-y-2">
            {run.sta_corners.map((c, i) => (
              <div key={i} className="flex items-center gap-4 text-xs">
                <span className="font-medium w-20">{c.corner?.name || "corner"}</span>
                <span className={c.success ? "text-green-600" : "text-red-600"}>{c.success ? "PASS" : "FAIL"}</span>
                <span>Setup WNS: {c.setup_wns?.toFixed(3)}</span>
                <span>Setup TNS: {c.setup_tns?.toFixed(3)}</span>
              </div>
            ))}
          </div>
        </div>
      )}
    </div>
  )
}

function AreaPowerTab({ run }) {
  const telemetry = run.telemetry || {}
  const metrics = telemetry.metrics || {}
  return (
    <div className="grid grid-cols-2 gap-4">
      <div className="bg-white border border-stone-ridge rounded-lg p-4">
        <h4 className="text-xs font-semibold mb-3">Area</h4>
        <div className="space-y-2 text-xs">
          <div className="flex justify-between"><span className="text-[#6B7280]">Utilization</span><span>{run.utilization ?? metrics.utilization ?? "—"}%</span></div>
          <div className="flex justify-between"><span className="text-[#6B7280]">Cell Count</span><span>{run.cell_count ?? metrics.cell_count ?? "—"}</span></div>
          <div className="flex justify-between"><span className="text-[#6B7280]">Die Area</span><span>{metrics.die_area_um2 ? `${metrics.die_area_um2.toFixed(2)} µm²` : "—"}</span></div>
        </div>
      </div>
      <div className="bg-white border border-stone-ridge rounded-lg p-4">
        <h4 className="text-xs font-semibold mb-3">Power</h4>
        <div className="space-y-2 text-xs">
          <div className="flex justify-between"><span className="text-[#6B7280]">Total Power</span><span>{metrics.total_power_mw ? `${metrics.total_power_mw.toFixed(2)} mW` : "—"}</span></div>
          <div className="flex justify-between"><span className="text-[#6B7280]">Internal</span><span>{metrics.internal_power_mw ? `${metrics.internal_power_mw.toFixed(2)} mW` : "—"}</span></div>
          <div className="flex justify-between"><span className="text-[#6B7280]">Switching</span><span>{metrics.switching_power_mw ? `${metrics.switching_power_mw.toFixed(2)} mW` : "—"}</span></div>
          <div className="flex justify-between"><span className="text-[#6B7280]">Leakage</span><span>{metrics.leakage_power_mw ? `${metrics.leakage_power_mw.toFixed(4)} mW` : "—"}</span></div>
        </div>
      </div>
    </div>
  )
}

function DrcLvsTab({ run }) {
  const drcLvs = run.drc_lvs || {}
  const drc = drcLvs.drc || {}
  const lvs = drcLvs.lvs || {}
  return (
    <div className="grid grid-cols-2 gap-4">
      <div className="bg-white border border-stone-ridge rounded-lg p-4">
        <h4 className="text-xs font-semibold mb-3 flex items-center gap-2">
          DRC {drc.is_clean ? <CheckCircle size={14} className="text-green-600" /> : <XCircle size={14} className="text-red-600" />}
        </h4>
        <div className="space-y-2 text-xs">
          <div className="flex justify-between"><span className="text-[#6B7280]">Total Violations</span><span>{drc.total_violations ?? "—"}</span></div>
          <div className="flex justify-between"><span className="text-[#6B7280]">Clean</span><span>{drc.is_clean ? "Yes" : "No"}</span></div>
          <div className="flex justify-between"><span className="text-[#6B7280]">Runtime</span><span>{drc.runtime_seconds ? `${drc.runtime_seconds.toFixed(1)}s` : "—"}</span></div>
        </div>
        {drc.by_rule && Object.keys(drc.by_rule).length > 0 && (
          <div className="mt-3">
            <p className="text-[10px] text-[#6B7280] mb-1">By Rule:</p>
            {Object.entries(drc.by_rule).map(([rule, count]) => (
              <div key={rule} className="flex justify-between text-xs"><span>{rule}</span><span>{count}</span></div>
            ))}
          </div>
        )}
      </div>
      <div className="bg-white border border-stone-ridge rounded-lg p-4">
        <h4 className="text-xs font-semibold mb-3 flex items-center gap-2">
          LVS {lvs.is_clean ? <CheckCircle size={14} className="text-green-600" /> : <XCircle size={14} className="text-red-600" />}
        </h4>
        <div className="space-y-2 text-xs">
          <div className="flex justify-between"><span className="text-[#6B7280]">Result</span><span>{lvs.result || "—"}</span></div>
          <div className="flex justify-between"><span className="text-[#6B7280]">Unmatched Devices</span><span>{lvs.unmatched_devices ?? "—"}</span></div>
          <div className="flex justify-between"><span className="text-[#6B7280]">Unmatched Nets</span><span>{lvs.unmatched_nets ?? "—"}</span></div>
          <div className="flex justify-between"><span className="text-[#6B7280]">Shorts</span><span>{lvs.short_count ?? "—"}</span></div>
          <div className="flex justify-between"><span className="text-[#6B7280]">Opens</span><span>{lvs.open_count ?? "—"}</span></div>
          <div className="flex justify-between"><span className="text-[#6B7280]">Runtime</span><span>{lvs.runtime_seconds ? `${lvs.runtime_seconds.toFixed(1)}s` : "—"}</span></div>
        </div>
      </div>
    </div>
  )
}

function LayoutImagesTab({ run }) {
  const images = ["final_all", "final_placement", "final_routing", "final_clocks", "final_ir_drop"]
  return (
    <div className="grid grid-cols-2 gap-4">
      {images.map((name) => (
        <div key={name} className="bg-white border border-stone-ridge rounded-lg p-3">
          <p className="text-[10px] font-[Work_Sans] text-[#6B7280] mb-2">{name}</p>
          <img
            src={`${API_BASE}/runs/${run.run_id}/image/${name}`}
            alt={name}
            className="w-full rounded border border-stone-ridge"
            onError={(e) => { e.target.style.display = "none" }}
          />
        </div>
      ))}
    </div>
  )
}

function ReportsTab({ run }) {
  const reportTypes = ["6_finish", "metrics", "synth_stat"]
  return (
    <div className="space-y-3">
      {reportTypes.map((name) => (
        <div key={name} className="bg-white border border-stone-ridge rounded-lg p-4">
          <div className="flex items-center justify-between mb-2">
            <h4 className="text-xs font-semibold">{name}</h4>
            <a
              href={`${API_BASE}/runs/${run.run_id}/report/${name}`}
              target="_blank"
              rel="noreferrer"
              className="text-[10px] text-meridian-gold flex items-center gap-1"
            >
              <Download size={12} /> View
            </a>
          </div>
        </div>
      ))}
    </div>
  )
}

function FailureAtlasTab({ run }) {
  const [failures, setFailures] = useState(null)
  const [expanded, setExpanded] = useState({})
  const [resolutionForm, setResolutionForm] = useState(null)

  useEffect(() => {
    if (!run?.run_id) return
    const doFetch = () => {
      fetch(`${API_BASE}/runs/${run.run_id}/failures`)
        .then(r => r.ok ? r.json() : [])
        .then(setFailures)
        .catch(() => setFailures([]))
    }
    doFetch()
    const id = setInterval(doFetch, 15000)
    return () => clearInterval(id)
  }, [run?.run_id])

  const toggleExpand = (id) => setExpanded(p => ({ ...p, [id]: !p[id] }))

  const severityColor = (sev) => {
    if (sev === "TAPEOUT_BLOCKING") return "text-red-600 bg-red-50"
    if (sev === "HIGH") return "text-red-600 bg-red-50"
    if (sev === "FUNCTIONAL_RISK") return "text-orange-600 bg-orange-50"
    if (sev === "PERFORMANCE_DEGRADATION") return "text-yellow-600 bg-yellow-50"
    if (sev === "MEDIUM") return "text-yellow-600 bg-yellow-50"
    if (sev === "LOW") return "text-blue-600 bg-blue-50"
    return "text-gray-600 bg-gray-50"
  }

  const handleResolve = async (failureId) => {
    const payload = resolutionForm[failureId]
    if (!payload?.fix_type) return
    try {
      const resp = await fetch(`${API_BASE}/failures/${failureId}/resolution`, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(payload),
      })
      if (resp.ok) {
        setFailures(f => f.map(fa => fa.id === failureId || fa.failure_id === failureId ? { ...fa, fix_applied: true, fix_type: payload.fix_type, fix_description: payload.fix_description } : fa))
        setResolutionForm(p => ({ ...p, [failureId]: null }))
      }
    } catch (e) {
      console.error("Resolution failed", e)
    }
  }

  if (failures === null) {
    return <div className="text-xs text-[#6B7280]">Loading failure detections...</div>
  }

  if (failures.length === 0) {
    return (
      <div className="bg-white border border-stone-ridge rounded-lg p-4">
        <h4 className="text-xs font-semibold mb-3 text-green-700 flex items-center gap-2"><CheckCircle size={14} /> No Failures Detected</h4>
        <p className="text-xs text-[#6B7280]">This run completed without any Failure Atlas detections.</p>
      </div>
    )
  }

  const backfilled = failures.every(f => f.domain === "PIPELINE" && f.category === "PIPELINE_FAILURE")

  return (
    <div className="space-y-3">
      {backfilled && (
        <div className="bg-amber-50 border border-amber-200 rounded-lg p-3 text-[10px] text-amber-800">
          This run failed before Failure Atlas was fully active. Failures shown below were backfilled from run metadata.
        </div>
      )}
      <div className="flex items-center justify-between">
        <h4 className="text-xs font-semibold flex items-center gap-2">
          <AlertTriangle size={14} className="text-orange-500" />
          Failure Atlas Detections ({failures.length})
        </h4>
      </div>
      {failures.map((fa) => {
        let ev = {}
        try { if (typeof fa.evidence === "string") { ev = JSON.parse(fa.evidence) } else if (fa.evidence) { ev = fa.evidence } } catch {}
        const stage = ev.stage || fa.detection_stage || "—"
        const isGeneric = !fa.title || fa.title === `Pipeline failed at stage ${stage}` || fa.title.startsWith("Run run_")
        const fid = fa.id || fa.failure_id
        return (
        <div key={fid} className={`bg-white border rounded-lg overflow-hidden ${fa.fix_applied ? "border-green-300" : "border-stone-ridge"}`}>
          <div className="flex items-start justify-between p-4 cursor-pointer hover:bg-[#FAFAF8]" onClick={() => toggleExpand(fid)}>
            <div className="flex items-center gap-2 min-w-0 flex-1">
              {expanded[fid] ? <ChevronDown size={14} className="text-[#6B7280] flex-shrink-0" /> : <ChevronRight size={14} className="text-[#6B7280] flex-shrink-0" />}
              <div className="min-w-0 flex-1">
                <div className="flex items-center gap-2">
                  <span className={`text-[10px] px-1.5 py-0.5 rounded font-medium ${severityColor(fa.severity)}`}>{fa.severity}</span>
                  {stage !== "—" && <span className="text-[10px] text-[#6B7280]">· {stage}</span>}
                  {fa.fix_applied && <span className="text-[10px] text-green-600 font-medium flex items-center gap-1"><CheckCircle size={10} /> Fixed</span>}
                </div>
                {isGeneric ? (
                  <p className="text-xs text-[#6B7280] italic mt-0.5">{fa.title || "Pipeline execution failed"}</p>
                ) : (
                  <p className="text-xs font-medium text-[#991B1B] mt-0.5 leading-relaxed">{fa.title}</p>
                )}
              </div>
            </div>
            {fa.confidence != null && (
              <span className="text-[10px] text-[#6B7280] flex-shrink-0 ml-2">{(fa.confidence * 100).toFixed(0)}% confidence</span>
            )}
          </div>
          {!isGeneric && fa.description && fa.description !== fa.title && (
            <div className="px-4 pb-2 ml-5">
              <p className="text-[10px] text-[#6B7280] leading-relaxed">{fa.description}</p>
            </div>
          )}
          {expanded[fid] && (
            <div className="ml-5 mr-4 mb-4 space-y-3 border-t border-stone-ridge pt-3">
              {ev.error && !isGeneric && (
                <div className="p-2 bg-[#FFF7ED] border border-[#FED7AA] rounded">
                  <p className="text-[10px] font-semibold text-[#C2410C] mb-1">Diagnostic Details</p>
                  {ev.exit_code != null && <p className="text-[10px]"><span className="text-[#6B7280]">Exit Code:</span> <span className={`font-medium ${ev.exit_code === 0 ? "text-[#16A34A]" : "text-[#C2410C]"}`}>{ev.exit_code}</span></p>}
                  {ev.log_file && <p className="text-[10px]"><span className="text-[#6B7280]">Log:</span> <span className="font-mono">{ev.log_file}</span></p>}
                  {ev.command && <p className="text-[10px]"><span className="text-[#6B7280]">Command:</span> <span className="font-mono">{ev.command}</span></p>}
                  {ev.stderr && (
                    <details className="mt-1">
                      <summary className="text-[10px] text-[#C2410C] cursor-pointer font-medium">stderr</summary>
                      <pre className="text-[9px] text-[#6B7280] bg-[#FAFAF8] p-2 rounded mt-1 max-h-20 overflow-auto">{ev.stderr}</pre>
                    </details>
                  )}
                </div>
              )}
              {fa.recommended_fix && Array.isArray(fa.recommended_fix) && fa.recommended_fix.length > 0 && (
                <div>
                  <p className="text-[10px] font-semibold text-abyss-ink mb-1">Industry Knowledge Base:</p>
                  <ul className="list-disc list-inside text-[10px] text-[#6B7280] space-y-0.5">
                    {fa.recommended_fix.map((fix, i) => <li key={i}>{fix}</li>)}
                  </ul>
                </div>
              )}
              {ev && typeof ev === "object" && Object.keys(ev).length > 0 && (
                <div>
                  <p className="text-[10px] font-semibold text-abyss-ink mb-1">Evidence <span className="font-normal text-[#6B7280]">({Object.keys(ev).length} fields)</span></p>
                  <pre className="text-[9px] text-[#6B7280] bg-[#FAFAF8] p-2 rounded mt-1 overflow-auto max-h-24 border border-stone-ridge">
                    {JSON.stringify(ev, null, 2)}
                  </pre>
                </div>
              )}
              {fa.fix_type && (
                <div className="p-2 bg-green-50 rounded">
                  <p className="text-[10px] font-semibold text-green-700">Fix Applied:</p>
                  <p className="text-[10px] text-green-600">{fa.fix_type}{fa.fix_description ? ` - ${fa.fix_description}` : ""}</p>
                  {fa.fix_run_id && <p className="text-[10px] text-green-600">Run: {fa.fix_run_id}</p>}
                </div>
              )}
              {!fa.fix_applied && (
                <div>
                  <button
                    onClick={(e) => { e.stopPropagation(); setResolutionForm(p => ({ ...p, [fid]: p?.[fid] || { fix_type: "", fix_description: "", fix_run_id: "" } })) }}
                    className="text-[10px] text-meridian-gold hover:underline flex items-center gap-1"
                  >
                    <ExternalLink size={10} /> Link Resolution
                  </button>
                  {resolutionForm?.[fid] && (
                    <div className="mt-2 p-2 bg-[#FAFAF8] rounded space-y-2" onClick={(e) => e.stopPropagation()}>
                      <select
                        value={resolutionForm[fid].fix_type}
                        onChange={(e) => setResolutionForm(p => ({ ...p, [fid]: { ...p[fid], fix_type: e.target.value } }))}
                        className="w-full text-[10px] border border-stone-ridge rounded px-2 py-1"
                      >
                        <option value="">Select Resolution Type...</option>
                        <option value="pipeline_insertion">Pipeline Insertion</option>
                        <option value="retiming">Retiming</option>
                        <option value="floorplan_change">Floorplan Change</option>
                        <option value="macro_relocation">Macro Relocation</option>
                        <option value="clock_restructuring">Clock Restructuring</option>
                        <option value="buffer_insertion">Buffer Insertion</option>
                        <option value="constraint_update">Constraint Update</option>
                        <option value="utilization_reduction">Utilization Reduction</option>
                        <option value="placement_density_change">Placement Density Change</option>
                        <option value="routing_strategy_change">Routing Strategy Change</option>
                        <option value="cdc_fix">CDC Fix</option>
                        <option value="rtl_bug_fix">RTL Bug Fix</option>
                        <option value="sram_integration_fix">SRAM Integration Fix</option>
                        <option value="other">Other</option>
                      </select>
                      <input
                        type="text"
                        placeholder="Fix description"
                        value={resolutionForm[fid].fix_description}
                        onChange={(e) => setResolutionForm(p => ({ ...p, [fid]: { ...p[fid], fix_description: e.target.value } }))}
                        className="w-full text-[10px] border border-stone-ridge rounded px-2 py-1"
                      />
                      <input
                        type="text"
                        placeholder="Fix run ID"
                        value={resolutionForm[fid].fix_run_id}
                        onChange={(e) => setResolutionForm(p => ({ ...p, [fid]: { ...p[fid], fix_run_id: e.target.value } }))}
                        className="w-full text-[10px] border border-stone-ridge rounded px-2 py-1"
                      />
                      <button
                        onClick={(e) => { e.stopPropagation(); handleResolve(fid) }}
                        className="text-[10px] bg-meridian-gold text-abyss-ink px-3 py-1 rounded font-medium hover:bg-yellow-500"
                      >
                        Record Resolution
                      </button>
                    </div>
                  )}
                </div>
              )}
            </div>
          )}
        </div>
      )})}
    </div>
  )
}

function ReproducibilityTab({ run }) {
  const [manifest, setManifest] = useState(null)
  useEffect(() => {
    fetch(`${API_BASE}/runs/${run.run_id}/report/reproducibility.json`)
      .then(r => r.ok ? r.json() : null)
      .then(setManifest)
      .catch(() => setManifest(null))
  }, [run.run_id])

  if (!manifest) {
    return <div className="text-xs text-[#6B7280]">Reproducibility manifest not available.</div>
  }
  return (
    <div className="bg-white border border-stone-ridge rounded-lg p-4">
      <h4 className="text-xs font-semibold mb-3">Reproducibility Manifest</h4>
      <pre className="text-[10px] text-[#6B7280] overflow-auto max-h-80 whitespace-pre-wrap">{JSON.stringify(manifest, null, 2)}</pre>
    </div>
  )
}

const TABS = [
  { key: "summary", label: "Summary", component: SummaryTab },
  { key: "timing", label: "Timing", component: TimingTab },
  { key: "area_power", label: "Area & Power", component: AreaPowerTab },
  { key: "drc_lvs", label: "DRC/LVS", component: DrcLvsTab },
  { key: "images", label: "Layout Images", component: LayoutImagesTab },
  { key: "reports", label: "Reports", component: ReportsTab },
  { key: "failure_atlas", label: "Failure Atlas", component: FailureAtlasTab },
  { key: "reproducibility", label: "Reproducibility", component: ReproducibilityTab },
]

export default function RunDetail({ runId, onBack }) {
  const [run, setRun] = useState(null)
  const [activeTab, setActiveTab] = useState("summary")
  const [error, setError] = useState(null)

  useEffect(() => {
    if (!runId) return
    fetch(`${API_BASE}/runs/${runId}`)
      .then(r => { if (!r.ok) throw new Error(`/${runId} ${r.status}`); return r.json() })
      .then(setRun)
      .catch(e => { console.error(e); setError(e.message) })
  }, [runId])

  if (error) {
    return (
      <div className="bg-white border border-stone-ridge rounded-lg p-6">
        <button onClick={onBack} className="flex items-center gap-1 text-xs text-meridian-gold mb-4"><ArrowLeft size={14} /> Back</button>
        <p className="text-sm text-red-600">Error loading run: {error}</p>
      </div>
    )
  }

  if (!run) {
    return (
      <div className="bg-white border border-stone-ridge rounded-lg p-6">
        <button onClick={onBack} className="flex items-center gap-1 text-xs text-meridian-gold mb-4"><ArrowLeft size={14} /> Back</button>
        <p className="text-xs text-[#6B7280]">Loading run details...</p>
      </div>
    )
  }

  const ActiveComponent = TABS.find(t => t.key === activeTab)?.component || SummaryTab

  return (
    <div className="bg-white border border-stone-ridge rounded-lg p-5">
      <div className="flex items-center justify-between mb-4">
        <div className="flex items-center gap-3">
          <button onClick={onBack} className="flex items-center gap-1 text-xs text-meridian-gold hover:underline"><ArrowLeft size={14} /> Back</button>
          <h2 className="font-[Playfair_Display] text-lg text-abyss-ink">{run.run_id}</h2>
          <span className={`text-[10px] px-2 py-0.5 rounded-full font-semibold ${run.status === "SUCCESS" ? "bg-green-100 text-green-700" : "bg-red-100 text-red-700"}`}>{run.status}</span>
        </div>
        <span className="text-[10px] text-[#6B7280]">{run.design_name}</span>
      </div>

      <div className="flex border-b border-stone-ridge mb-4">
        {TABS.map(tab => (
          <TabButton key={tab.key} label={tab.label} active={activeTab === tab.key} onClick={() => setActiveTab(tab.key)} />
        ))}
      </div>

      <ActiveComponent run={run} />
    </div>
  )
}
