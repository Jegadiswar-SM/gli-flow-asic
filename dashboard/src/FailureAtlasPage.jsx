import { useState, useEffect } from "react"
import { Search, Filter, AlertTriangle, CheckCircle, ChevronDown, ChevronRight, ExternalLink, ArrowUp, ArrowDown, Minus } from "lucide-react"

const API_BASE = import.meta.env.VITE_API_URL || ""

function SeverityBadge({ severity }) {
  const colors = {
    TAPEOUT_BLOCKING: "bg-red-100 text-red-700 border-red-200",
    HIGH: "bg-red-100 text-red-700 border-red-200",
    FUNCTIONAL_RISK: "bg-orange-100 text-orange-700 border-orange-200",
    PERFORMANCE_DEGRADATION: "bg-yellow-100 text-yellow-700 border-yellow-200",
    MEDIUM: "bg-yellow-100 text-yellow-700 border-yellow-200",
    LOW: "bg-blue-100 text-blue-700 border-blue-200",
    WARNING: "bg-gray-100 text-gray-700 border-gray-200",
  }
  const cls = colors[severity] || "bg-gray-100 text-gray-700 border-gray-200"
  return <span className={`text-[10px] px-1.5 py-0.5 rounded font-medium border ${cls}`}>{severity}</span>
}

function OverviewCards({ analytics }) {
  if (!analytics) return null
  const cards = [
    { label: "Total Failures", value: analytics.total_failures, color: "text-red-600" },
    { label: "Resolved", value: analytics.fixed_count, color: "text-green-600" },
    { label: "Success Rate", value: `${analytics.success_rate ?? 0}%`, color: analytics.success_rate > 50 ? "text-green-600" : "text-orange-600" },
    { label: "High Confidence", value: analytics.high_confidence_resolutions || 0, color: "text-blue-600" },
  ]
  return (
    <div className="grid grid-cols-4 gap-4 mb-6">
      {cards.map(c => (
        <div key={c.label} className="bg-white border border-stone-ridge rounded-lg p-4">
          <p className="text-[10px] font-[Work_Sans] text-[#6B7280] uppercase tracking-wider">{c.label}</p>
          <p className={`text-xl font-semibold mt-1 ${c.color}`}>{c.value}</p>
        </div>
      ))}
    </div>
  )
}

function CommonFailures({ data }) {
  if (!data || data.length === 0) return null
  return (
    <div className="bg-white border border-stone-ridge rounded-lg p-5">
      <h3 className="font-[Playfair_Display] text-[14px] text-abyss-ink mb-3">Most Common Failures</h3>
      <table className="w-full text-xs">
        <thead><tr className="text-[10px] text-[#6B7280] border-b border-stone-ridge">
          <th className="text-left pb-2 font-medium">Failure Type</th>
          <th className="text-right pb-2 font-medium">Count</th>
          <th className="text-right pb-2 font-medium">%</th>
        </tr></thead>
        <tbody>
          {data.map((f, i) => (
            <tr key={i} className="border-b border-stone-ridge/50">
              <td className="py-2 text-abyss-ink">{f.failure_type}</td>
              <td className="py-2 text-right">{f.count}</td>
              <td className="py-2 text-right text-[#6B7280]">{f.percentage}%</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  )
}

function FixEffectiveness({ data }) {
  if (!data || data.message === "Insufficient Data") {
    return (
      <div className="bg-white border border-stone-ridge rounded-lg p-5">
        <h3 className="font-[Playfair_Display] text-[14px] text-abyss-ink mb-3">Most Effective Fixes</h3>
        <p className="text-xs text-[#6B7280]">Insufficient Data — need at least {data?.min_samples_required || 3} samples per fix type.</p>
      </div>
    )
  }
  const results = data?.results || []
  if (results.length === 0) return null
  return (
    <div className="bg-white border border-stone-ridge rounded-lg p-5">
      <h3 className="font-[Playfair_Display] text-[14px] text-abyss-ink mb-3">Most Effective Fixes</h3>
      <table className="w-full text-xs">
        <thead><tr className="text-[10px] text-[#6B7280] border-b border-stone-ridge">
          <th className="text-left pb-2 font-medium">Failure Type</th>
          <th className="text-left pb-2 font-medium">Fix Type</th>
          <th className="text-right pb-2 font-medium">Success Rate</th>
          <th className="text-right pb-2 font-medium">Sample Size</th>
        </tr></thead>
        <tbody>
          {results.map((r, i) => (
            <tr key={i} className="border-b border-stone-ridge/50">
              <td className="py-2 text-abyss-ink">{r.failure_type}</td>
              <td className="py-2 text-[#6B7280]">{r.fix_type}</td>
              <td className="py-2 text-right font-medium">{r.success_rate}%</td>
              <td className="py-2 text-right text-[#6B7280]">{r.sample_size}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  )
}

function QoRImprovements({ data }) {
  if (!data || data.length === 0) return null
  return (
    <div className="bg-white border border-stone-ridge rounded-lg p-5">
      <h3 className="font-[Playfair_Display] text-[14px] text-abyss-ink mb-3">QoR Impact by Fix Type</h3>
      <table className="w-full text-xs">
        <thead><tr className="text-[10px] text-[#6B7280] border-b border-stone-ridge">
          <th className="text-left pb-2 font-medium">Fix Type</th>
          <th className="text-right pb-2 font-medium">Avg WNS Improvement</th>
          <th className="text-right pb-2 font-medium">Avg TNS Improvement</th>
          <th className="text-right pb-2 font-medium">Sample Size</th>
        </tr></thead>
        <tbody>
          {data.map((r, i) => (
            <tr key={i} className="border-b border-stone-ridge/50">
              <td className="py-2 text-abyss-ink">{r.fix_type}</td>
              <td className={`py-2 text-right ${r.avg_wns_improvement > 0 ? "text-green-600" : "text-red-600"}`}>{r.avg_wns_improvement?.toFixed(3)} ns</td>
              <td className={`py-2 text-right ${r.avg_tns_improvement > 0 ? "text-green-600" : "text-red-600"}`}>{r.avg_tns_improvement?.toFixed(2)} ns</td>
              <td className="py-2 text-right text-[#6B7280]">{r.sample_size}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  )
}

function ResolutionConfidence({ data }) {
  if (!data) return null
  const { distribution, unresolved } = data
  return (
    <div className="bg-white border border-stone-ridge rounded-lg p-5">
      <h3 className="font-[Playfair_Display] text-[14px] text-abyss-ink mb-3">Resolution Confidence</h3>
      <div className="space-y-2">
        {(distribution || []).map((d, i) => {
          const color = d.resolution_confidence === "HIGH" ? "bg-green-500" : d.resolution_confidence === "MEDIUM" ? "bg-yellow-500" : "bg-red-500"
          return (
            <div key={i} className="flex items-center gap-2 text-xs">
              <span className={`w-2 h-2 rounded-full ${color}`} />
              <span className="w-16">{d.resolution_confidence || "UNKNOWN"}</span>
              <span className="font-medium">{d.count}</span>
            </div>
          )
        })}
        {unresolved > 0 && (
          <div className="flex items-center gap-2 text-xs">
            <span className="w-2 h-2 rounded-full bg-gray-300" />
            <span className="w-16">UNRESOLVED</span>
            <span className="font-medium">{unresolved}</span>
          </div>
        )}
      </div>
    </div>
  )
}

function FailureTrends({ data }) {
  if (!data) return null
  const { failure_distribution, daily_counts } = data
  return (
    <div className="bg-white border border-stone-ridge rounded-lg p-5">
      <h3 className="font-[Playfair_Display] text-[14px] text-abyss-ink mb-3">Failure Trends</h3>
      <div className="grid grid-cols-2 gap-4">
        <div>
          <p className="text-[10px] font-semibold text-[#6B7280] mb-2">Distribution</p>
          <div className="space-y-1">
            {(failure_distribution || []).slice(0, 5).map((f, i) => (
              <div key={i} className="flex items-center justify-between text-xs">
                <span>{f.failure_type}</span>
                <span className="text-[#6B7280]">{f.percentage}%</span>
              </div>
            ))}
          </div>
        </div>
        <div>
          <p className="text-[10px] font-semibold text-[#6B7280] mb-2">Recent Activity</p>
          <div className="space-y-1">
            {(daily_counts || []).slice(0, 7).map((d, i) => (
              <div key={i} className="flex items-center justify-between text-xs">
                <span>{d.date}</span>
                <span className="text-[#6B7280]">{d.count} failure(s)</span>
              </div>
            ))}
          </div>
        </div>
      </div>
    </div>
  )
}

function CoverageIntelligence({ data }) {
  if (!data) return null
  return (
    <div className="bg-white border border-stone-ridge rounded-lg p-5">
      <h3 className="font-[Playfair_Display] text-[14px] text-abyss-ink mb-3">Coverage Intelligence</h3>
      <div className="grid grid-cols-2 gap-4">
        <div>
          <p className="text-[10px] font-semibold text-[#6B7280] mb-2">Most Viewed Rules</p>
          <div className="space-y-1">
            {data.most_viewed.map((f, i) => (
              <div key={i} className="flex items-center justify-between text-xs">
                <span>{f.rule_id}</span>
                <span className="text-[#6B7280]">{f.views} views</span>
              </div>
            ))}
          </div>
        </div>
        <div>
          <p className="text-[10px] font-semibold text-[#6B7280] mb-2">Most Requested Missing</p>
          <div className="space-y-1">
            {data.most_requested_missing.map((f, i) => (
              <div key={i} className="flex items-center justify-between text-xs">
                <span className="text-red-600">{f.rule_id}</span>
                <span className="text-[#6B7280]">{f.requests} reqs</span>
              </div>
            ))}
          </div>
        </div>
      </div>
    </div>
  )
}

function FailureList({ failures, onSelect }) {
  if (!failures || failures.length === 0) return <p className="text-xs text-[#6B7280] py-8 text-center">No failures found matching filters.</p>
  
  return (
    <div className="space-y-2">
      {failures.map((fa) => {
        let ev = {}
        try { if (typeof fa.evidence === "string") { ev = JSON.parse(fa.evidence) } else if (fa.evidence) { ev = fa.evidence } } catch {}
        const stage = fa.detection_stage || ev.stage || fa.domain || "—"
        const errorText = fa.description || fa.title || ""
        const isGeneric = !fa.title || fa.title === `Pipeline failed at stage ${stage}` || fa.title.startsWith("Run")
        
        return (
          <div key={fa.id || fa.failure_id} className="bg-white border border-stone-ridge rounded-lg p-4 hover:border-red-300 cursor-pointer transition-colors" onClick={() => onSelect?.(fa)}>
            <div className="flex items-start justify-between gap-3">
              <div className="flex-1 min-w-0">
                <div className="flex items-center gap-2 mb-1">
                  <SeverityBadge severity={fa.severity} />
                  <span className="text-[10px] font-medium text-[#6B7280] uppercase tracking-wider">{fa.domain || "PIPELINE"}</span>
                  {stage && <span className="text-[10px] text-[#6B7280]">· {stage}</span>}
                  {fa.fix_applied && <CheckCircle size={12} className="text-green-500 ml-1" />}
                  {fa.is_important === 1 && <span className="text-[10px] font-medium text-amber-600 bg-amber-50 px-1.5 py-0.5 rounded border border-amber-200">Important Run</span>}
                </div>
                {isGeneric ? (
                  <p className="text-xs text-[#6B7280] italic">{errorText || "Pipeline execution failed"}</p>
                ) : (
                  <p className="text-xs font-medium text-[#991B1B] leading-relaxed">{fa.title}</p>
                )}
                {!isGeneric && fa.description && fa.description !== fa.title && (
                  <p className="text-[10px] text-[#6B7280] mt-1 line-clamp-2">{fa.description}</p>
                )}
              </div>
              <div className="text-right flex-shrink-0">
                <p className="text-[10px] text-[#6B7280]">{fa.run_id?.slice(0, 16)}</p>
                <p className="text-[9px] text-[#6B7280] mt-0.5">{fa.detected_at ? new Date(fa.detected_at).toLocaleDateString() : ""}</p>
              </div>
            </div>
          </div>
        )
      })}
    </div>
  )
}

function FailureDetail({ failure, onBack }) {
  const [knowledge, setKnowledge] = useState(null)
  const [correlation, setCorrelation] = useState(null)

  useEffect(() => {
    if (failure) {
      const identifier = failure.signature || failure.failure_type;
      if (identifier) {
        let ev = {}
        try { if (typeof failure.evidence === "string") { ev = JSON.parse(failure.evidence) } else if (failure.evidence) { ev = failure.evidence } } catch {}
        const citation = ev.citation || ""
        const params = citation ? `?citation=${encodeURIComponent(citation)}` : ""
        fetch(`${API_BASE}/knowledge/failures/${identifier}${params}`)
          .then(r => r.ok ? r.json() : null)
          .then(setKnowledge)
          .catch(() => setKnowledge(null))
        
        fetch(`${API_BASE}/failures/correlation/${failure.failure_type}`)
          .then(r => r.ok ? r.json() : null)
          .then(setCorrelation)
          .catch(() => setCorrelation(null))
      }
    }
  }, [failure])

  if (!failure) return null

  let ev = {}
  try { if (typeof failure.evidence === "string") { ev = JSON.parse(failure.evidence) } else if (failure.evidence) { ev = failure.evidence } } catch {}

  const stage = ev.stage || failure.detection_stage || failure.domain || "—"
  const errorText = failure.description || failure.title || ""
  const isGeneric = !failure.title || failure.title === `Pipeline failed at stage ${stage}` || failure.title.startsWith("Run run_")

  return (
    <div className="space-y-4">
      <button onClick={onBack} className="text-xs text-meridian-gold hover:underline mb-2">← Back to all failures</button>
      
      {correlation && correlation.statistics && (
        <div className="mt-5 p-4 bg-white border border-stone-ridge rounded">
          <h4 className="text-xs font-semibold text-abyss-ink mb-3">Historical Intelligence</h4>
          <div className="grid grid-cols-3 gap-4 text-xs mb-4">
            <div><p className="text-[#6B7280]">Seen</p><p className="font-medium">{correlation.statistics.total_occurrences}</p></div>
            <div><p className="text-[#6B7280]">Resolved</p><p className="font-medium text-green-600">{correlation.statistics.resolved_count}</p></div>
            <div><p className="text-[#6B7280]">Unresolved</p><p className="font-medium text-red-600">{correlation.statistics.unresolved_count}</p></div>
          </div>
          <div className="text-xs mb-4">
            <p><span className="text-[#6B7280]">First Seen:</span> {correlation.statistics.first_seen?.slice(0, 10) || "—"}</p>
            <p><span className="text-[#6B7280]">Last Seen:</span> {correlation.statistics.last_seen?.slice(0, 10) || "—"}</p>
          </div>

          {correlation.affected_designs && correlation.affected_designs.length > 0 && (
              <>
                  <p className="text-[10px] font-semibold text-abyss-ink mb-1">Affected Designs</p>
                  <div className="flex flex-wrap gap-1 mb-4">
                    {correlation.affected_designs.map((d, i) => (
                      <span key={i} className="text-[10px] bg-stone-ridge/20 px-1.5 py-0.5 rounded">{d.design_name} ({d.occurrences})</span>
                    ))}
                  </div>
              </>
          )}

          {correlation.resolution_effectiveness && correlation.resolution_effectiveness.length > 0 && (
              <div className="mt-4">
                  <p className="text-[10px] font-semibold text-abyss-ink mb-1">Most Successful Historical Fixes</p>
                  <table className="w-full text-[10px] text-left">
                      <thead><tr className="text-[#6B7280]"><th>Fix Type</th><th>Attempts</th><th>Success %</th><th>Imp. Runs</th></tr></thead>
                      <tbody>
                          {correlation.resolution_effectiveness.map((e, i) => (
                              <tr key={i} className="border-t border-stone-ridge/50">
                                  <td>{e.fix_type}</td>
                                  <td>{e.attempts}</td>
                                  <td className="text-green-600 font-medium">{e.success_rate}%</td>
                                  <td>{e.important_runs}</td>
                              </tr>
                          ))}
                      </tbody>
                  </table>
              </div>
          )}
        </div>
      )}

      {knowledge && (
        <div className="bg-white border border-stone-ridge rounded-lg p-5">
          <div className="flex items-center gap-2 mb-4">
            <AlertTriangle size={16} className="text-topography-rust" />
            <h3 className="text-sm font-semibold text-abyss-ink">Knowledge Base — {knowledge.failure_type}</h3>
            {knowledge.source && (
              <span className="ml-auto text-[10px] text-[#6B7280]">{knowledge.source}{knowledge.version ? ` v${knowledge.version}` : ""}</span>
            )}
          </div>

          {knowledge.description && (
            <p className="text-xs text-[#6B7280] mb-4 leading-relaxed">{knowledge.description}</p>
          )}

          {knowledge.common_causes && knowledge.common_causes.length > 0 && (
            <div className="mb-4">
              <p className="text-[10px] font-semibold text-abyss-ink mb-1">Common Causes</p>
              <ul className="list-disc list-inside text-[10px] text-[#6B7280] space-y-0.5">
                {knowledge.common_causes.map((c, i) => <li key={i}>{c}</li>)}
              </ul>
            </div>
          )}

          {knowledge.remediation_strategies && knowledge.remediation_strategies.length > 0 && (
            <div className="mb-4">
              <p className="text-[10px] font-semibold text-abyss-ink mb-1">Remediation Strategies</p>
              <div className="space-y-2">
                {knowledge.remediation_strategies.map((s, i) => (
                  <div key={i} className="text-[10px] p-2 bg-[#FAFAF8] rounded border border-stone-ridge">
                    <p className="font-medium text-abyss-ink">{s.technique || s}</p>
                    {s.description && <p className="text-[#6B7280] mt-0.5">{s.description}</p>}
                  </div>
                ))}
              </div>
            </div>
          )}

          {knowledge.verification_steps && knowledge.verification_steps.length > 0 && (
            <div className="mb-4">
              <p className="text-[10px] font-semibold text-abyss-ink mb-1">Verification Steps</p>
              <ul className="list-disc list-inside text-[10px] text-[#6B7280] space-y-0.5">
                {knowledge.verification_steps.map((v, i) => <li key={i}>{typeof v === "string" ? v : JSON.stringify(v)}</li>)}
              </ul>
            </div>
          )}

          {knowledge.references && knowledge.references.length > 0 && (
            <div>
              <p className="text-[10px] font-semibold text-abyss-ink mb-1">References</p>
              <ul className="list-disc list-inside text-[10px] text-[#6B7280] space-y-0.5">
                {knowledge.references.map((r, i) => <li key={i}>{r}</li>)}
              </ul>
            </div>
          )}
        </div>
      )}

      <div className="bg-white border border-stone-ridge rounded-lg p-5">
        <div className="flex items-center gap-2 mb-4">
          <AlertTriangle size={16} className="text-topography-rust" />
          <h3 className="text-sm font-semibold text-abyss-ink">Root Cause Analysis</h3>
        </div>

        <div className="bg-[#FEF2F2] border border-[#FECACA] rounded-lg p-4 mb-5">
          <p className="text-[10px] font-semibold text-[#991B1B] uppercase tracking-wider mb-2">Error</p>
          {isGeneric ? (
            <p className="text-xs italic text-[#6B7280]">{errorText || "Pipeline execution failed"}</p>
          ) : (
            <>
              <p className="text-sm font-medium text-[#991B1B] leading-relaxed">{failure.title}</p>
              {failure.description && failure.description !== failure.title && (
                <p className="text-xs text-[#6B7280] mt-2 leading-relaxed">{failure.description}</p>
              )}
            </>
          )}
        </div>
        
        <div className="grid grid-cols-4 gap-4 text-xs mb-5">
          <div className="p-3 bg-[#FAFAF8] rounded border border-stone-ridge">
            <p className="text-[9px] font-medium text-[#6B7280] uppercase tracking-wider mb-0.5">Stage</p>
            <p className="font-medium text-abyss-ink">{stage}</p>
          </div>
          <div className="p-3 bg-[#FAFAF8] rounded border border-stone-ridge">
            <p className="text-[9px] font-medium text-[#6B7280] uppercase tracking-wider mb-0.5">Severity</p>
            <SeverityBadge severity={failure.severity} />
          </div>
          <div className="p-3 bg-[#FAFAF8] rounded border border-stone-ridge">
            <p className="text-[9px] font-medium text-[#6B7280] uppercase tracking-wider mb-0.5">Confidence</p>
            <p className="font-medium text-abyss-ink">{failure.confidence != null ? `${(failure.confidence * 100).toFixed(0)}%` : "—"}</p>
          </div>
          <div className="p-3 bg-[#FAFAF8] rounded border border-stone-ridge">
            <p className="text-[9px] font-medium text-[#6B7280] uppercase tracking-wider mb-0.5">Run</p>
            <p className="font-medium text-abyss-ink text-[10px] truncate">{failure.run_id}</p>
          </div>
        </div>
      </div>
    </div>
  )
}

export default function FailureAtlasPage({ designFilter }) {
  const [failures, setFailures] = useState({ results: [], total: 0 })
  const [analytics, setAnalytics] = useState(null)
  const [commonFailures, setCommonFailures] = useState(null)
  const [fixEffectiveness, setFixEffectiveness] = useState(null)
  const [qorImprovements, setQorImprovements] = useState(null)
  const [failureTrends, setFailureTrends] = useState(null)
  const [resolutionConfidence, setResolutionConfidence] = useState(null)
  const [coverage, setCoverage] = useState(null)
  const [selectedFailure, setSelectedFailure] = useState(null)
  const [search, setSearch] = useState("")
  const [severityFilter, setSeverityFilter] = useState("")
  const [typeFilter, setTypeFilter] = useState("")
  const [loading, setLoading] = useState(true)

  const fetchAll = () => {
    setLoading(true)
    const params = new URLSearchParams()
    if (search) params.set("search", search)
    if (severityFilter) params.set("severity", severityFilter)
    if (typeFilter) params.set("failure_type", typeFilter)
    if (designFilter) params.set("design", designFilter)
    params.set("limit", "50")

    Promise.all([
      fetch(`${API_BASE}/failures?${params}`).then(r => r.json()),
      fetch(`${API_BASE}/analytics/summary${designFilter ? `?design=${designFilter}` : ""}`).then(r => r.ok ? r.json() : null),
      fetch(`${API_BASE}/analytics/common-failures${designFilter ? `?design=${designFilter}` : ""}`).then(r => r.ok ? r.json() : null),
      fetch(`${API_BASE}/analytics/fix-effectiveness${designFilter ? `?design=${designFilter}` : ""}`).then(r => r.ok ? r.json() : null),
      fetch(`${API_BASE}/analytics/qor-improvements${designFilter ? `?design=${designFilter}` : ""}`).then(r => r.ok ? r.json() : null),
      fetch(`${API_BASE}/analytics/failure-trends${designFilter ? `?design=${designFilter}` : ""}`).then(r => r.ok ? r.json() : null),
      fetch(`${API_BASE}/analytics/resolution-confidence${designFilter ? `?design=${designFilter}` : ""}`).then(r => r.ok ? r.json() : null),
      fetch(`${API_BASE}/analytics/coverage${designFilter ? `?design=${designFilter}` : ""}`).then(r => r.ok ? r.json() : null),
    ])
      .then(([f, a, cf, fe, qi, ft, rc, cov]) => {
        setFailures(f)
        setAnalytics(a)
        setCommonFailures(cf)
        setFixEffectiveness(fe)
        setQorImprovements(qi)
        setFailureTrends(ft)
        setResolutionConfidence(rc)
        setCoverage(cov)
        setLoading(false)
      })
      .catch(() => setLoading(false))
  }

  useEffect(() => {
    fetchAll()
    const id = setInterval(fetchAll, 30000)
    return () => clearInterval(id)
  }, [designFilter])

  const handleSearch = (e) => {
    e.preventDefault()
    fetchAll()
  }

  const uniqueTypes = [...new Set((failures.results || []).map(f => f.failure_type || f.category).filter(Boolean))]

  if (selectedFailure) {
    return <FailureDetail failure={selectedFailure} onBack={() => setSelectedFailure(null)} />
  }

  return (
    <div className="space-y-6">
      <div className="flex items-center justify-between">
        <h2 className="font-[Playfair_Display] text-lg text-abyss-ink">Failure Atlas</h2>
        <div className="text-[10px] text-[#6B7280]">{failures.total || 0} total failures recorded</div>
      </div>

      <OverviewCards analytics={analytics} />

      <div className="grid grid-cols-2 gap-4">
        <CommonFailures data={commonFailures} />
        <FixEffectiveness data={fixEffectiveness} />
      </div>

      <div className="grid grid-cols-2 gap-4">
        <QoRImprovements data={qorImprovements} />
        <ResolutionConfidence data={resolutionConfidence} />
      </div>

      <FailureTrends data={failureTrends} />
      <CoverageIntelligence data={coverage} />

      <div className="bg-white border border-stone-ridge rounded-lg p-5">
        <div className="flex items-center justify-between mb-4">
          <h3 className="font-[Playfair_Display] text-[14px] text-abyss-ink">All Failures</h3>
          <form onSubmit={handleSearch} className="flex items-center gap-2">
            <div className="relative">
              <Search size={12} className="absolute left-2 top-1/2 -translate-y-1/2 text-[#6B7280]" />
              <input
                type="text"
                value={search}
                onChange={(e) => setSearch(e.target.value)}
                placeholder="Search failures..."
                className="pl-6 pr-2 py-1 text-[10px] border border-stone-ridge rounded w-40"
              />
            </div>
            <select value={severityFilter} onChange={(e) => setSeverityFilter(e.target.value)} className="text-[10px] border border-stone-ridge rounded px-2 py-1">
              <option value="">All Severity</option>
              <option value="TAPEOUT_BLOCKING">Tapeout Blocking</option>
              <option value="HIGH">HIGH</option>
              <option value="FUNCTIONAL_RISK">Functional Risk</option>
              <option value="PERFORMANCE_DEGRADATION">Performance Degradation</option>
              <option value="MEDIUM">Medium</option>
              <option value="LOW">Low</option>
            </select>
            <select value={typeFilter} onChange={(e) => setTypeFilter(e.target.value)} className="text-[10px] border border-stone-ridge rounded px-2 py-1">
              <option value="">All Types</option>
              {uniqueTypes.map(t => <option key={t} value={t}>{t}</option>)}
            </select>
            <button type="submit" className="text-[10px] bg-meridian-gold text-abyss-ink px-3 py-1 rounded font-medium hover:bg-yellow-500">Filter</button>
          </form>
        </div>
        {loading ? (
          <p className="text-xs text-[#6B7280] py-4">Loading failures...</p>
        ) : (
          <FailureList failures={failures.results} onSelect={setSelectedFailure} />
        )}
      </div>
    </div>
  )
}
