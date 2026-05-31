import { useState, useEffect } from "react"
import { ArrowLeft, Clock, AlertTriangle, CheckCircle, XCircle, Download } from "lucide-react"

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
          <div className="flex justify-between"><span className="text-[#6B7280]">Die Area</span><span>{metrics.die_area_um2 ? `${metrics.die_area_um2} µm²` : "—"}</span></div>
        </div>
      </div>
      <div className="bg-white border border-stone-ridge rounded-lg p-4">
        <h4 className="text-xs font-semibold mb-3">Power</h4>
        <div className="space-y-2 text-xs">
          <div className="flex justify-between"><span className="text-[#6B7280]">Total Power</span><span>{metrics.total_power_w ? `${(metrics.total_power_w * 1000).toFixed(2)} mW` : "—"}</span></div>
          <div className="flex justify-between"><span className="text-[#6B7280]">Internal</span><span>{metrics.internal_mw ? `${metrics.internal_mw.toFixed(2)} mW` : "—"}</span></div>
          <div className="flex justify-between"><span className="text-[#6B7280]">Switching</span><span>{metrics.switching_mw ? `${metrics.switching_mw.toFixed(2)} mW` : "—"}</span></div>
          <div className="flex justify-between"><span className="text-[#6B7280]">Leakage</span><span>{metrics.leakage_mw ? `${metrics.leakage_mw.toFixed(2)} mW` : "—"}</span></div>
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
  const telemetry = run.telemetry || {}
  return (
    <div className="bg-white border border-stone-ridge rounded-lg p-4">
      <h4 className="text-xs font-semibold mb-3">Failure Atlas Detections</h4>
      <p className="text-xs text-[#6B7280]">Failure Atlas data available in output reports directory.</p>
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
