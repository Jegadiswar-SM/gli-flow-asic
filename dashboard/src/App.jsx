import { useEffect, useState } from "react"

import {
  LineChart,
  Line,
  XAxis,
  YAxis,
  Tooltip,
  ResponsiveContainer,
  PieChart,
  Pie,
  Cell,
} from "recharts"

export default function App() {

  const [runs, setRuns] = useState([])

  const [wnsData, setWnsData] = useState([])

  useEffect(() => {

    fetch("http://127.0.0.1:8000/runs")
      .then((res) => res.json())
      .then((data) => {

        setRuns(data)

      })

    fetch("http://127.0.0.1:8000/metrics/wns")
      .then((res) => res.json())
      .then((data) => {

        const formatted = data.map((x, i) => ({
          index: i,
          value: x[1]
        }))

        setWnsData(formatted)

      })

  }, [])

  const latestRun = runs.length > 0 ? runs[0] : null

  const successfulRuns = runs.filter(
    (r) => r.status === "COMPLETED"
  ).length

  const avgQor =
    runs.length > 0
      ? (
          runs.reduce(
            (acc, r) => acc + (r.qor_score || 0),
            0
          ) / runs.length
        ).toFixed(2)
      : 0

  const pieData = [

    { name: "Timing", value: 88 },

    { name: "Area", value: 75 },

    { name: "Power", value: 79 },

    { name: "DRC", value: 92 },

    { name: "Congestion", value: 68 },
  ]

  const COLORS = [

    "#22c55e",

    "#3b82f6",

    "#8b5cf6",

    "#f59e0b",

    "#ef4444",
  ]

  return (

    <div className="min-h-screen bg-slate-950 text-white flex">

      {/* Sidebar */}

      <div className="w-72 bg-slate-900 border-r border-slate-800 p-6">

        <h1 className="text-3xl font-bold text-green-400">
          GLI-FLOW
        </h1>

        <p className="text-slate-400 mt-2 text-sm">
          Execution Intelligence Infrastructure
        </p>

        <div className="mt-10 space-y-4">

          <div className="bg-green-500/20 border border-green-500 rounded-lg px-4 py-3">
            Dashboard
          </div>

          <div className="text-slate-400 px-4 py-3">
            Run Monitor
          </div>

          <div className="text-slate-400 px-4 py-3">
            QoR Analytics
          </div>

          <div className="text-slate-400 px-4 py-3">
            Regression Detector
          </div>

          <div className="text-slate-400 px-4 py-3">
            Failure Atlas
          </div>

          <div className="text-slate-400 px-4 py-3">
            Artifacts
          </div>

        </div>

      </div>

      {/* Main */}

      <div className="flex-1 p-8">

        <h1 className="text-4xl font-bold">
          GLI-FLOW Dashboard
        </h1>

        <p className="text-slate-400 mt-2">
          Execution Intelligence for ASIC Infrastructure
        </p>

        {/* Top Cards */}

        <div className="grid grid-cols-5 gap-6 mt-8">

          <Card
            title="Total Runs"
            value={runs.length}
            sub="+3 this week"
          />

          <Card
            title="Successful Runs"
            value={successfulRuns}
            sub="Stable execution"
          />

          <Card
            title="Average QoR"
            value={avgQor}
            sub="Improving"
          />

          <Card
            title="Regressions"
            value="0"
            sub="Needs investigation"
          />

          <Card
            title="Validated Releases"
            value="3"
            sub="Ready for deployment"
          />

        </div>

        {/* Charts */}

        <div className="grid grid-cols-3 gap-6 mt-8">

          {/* QoR Trend */}

          <div className="col-span-2 bg-slate-900 rounded-2xl p-6 border border-slate-800">

            <div className="flex justify-between items-center">

              <h2 className="text-2xl font-semibold">
                QoR Trend
              </h2>

              <span className="text-slate-400 text-sm">
                Last Runs
              </span>

            </div>

            <div className="h-80 mt-6">

              <ResponsiveContainer width="100%" height="100%">

                <LineChart data={wnsData}>

                  <XAxis dataKey="index" />

                  <YAxis />

                  <Tooltip />

                  <Line
                    type="monotone"
                    dataKey="value"
                    stroke="#22c55e"
                    strokeWidth={3}
                  />

                </LineChart>

              </ResponsiveContainer>

            </div>

          </div>

          {/* Pie */}

          <div className="bg-slate-900 rounded-2xl p-6 border border-slate-800">

            <h2 className="text-2xl font-semibold">
              QoR Breakdown
            </h2>

            <div className="h-80 mt-6">

              <ResponsiveContainer width="100%" height="100%">

                <PieChart>

                  <Pie
                    data={pieData}
                    cx="50%"
                    cy="50%"
                    outerRadius={100}
                    dataKey="value"
                  >

                    {pieData.map((entry, index) => (

                      <Cell
                        key={index}
                        fill={COLORS[index % COLORS.length]}
                      />

                    ))}

                  </Pie>

                  <Tooltip />

                </PieChart>

              </ResponsiveContainer>

            </div>

          </div>

        </div>

        {/* Execution Table */}

        <div className="bg-slate-900 rounded-2xl p-6 border border-slate-800 mt-8">

          <div className="flex justify-between items-center">

            <h2 className="text-2xl font-semibold">
              Recent Runs
            </h2>

            <span className="text-green-400 text-sm">
              Live Database
            </span>

          </div>

          <table className="w-full mt-6">

            <thead>

              <tr className="text-left text-slate-400 border-b border-slate-700">

                <th className="pb-4">Run ID</th>

                <th className="pb-4">Status</th>

                <th className="pb-4">WNS</th>

                <th className="pb-4">QoR</th>

                <th className="pb-4">Runtime</th>

              </tr>

            </thead>

            <tbody>

              {runs.map((run, index) => (

                <tr
                  key={index}
                  className="border-b border-slate-800"
                >

                  <td className="py-4">
                    {run.run_id}
                  </td>

                  <td className="py-4 text-green-400">
                    {run.status}
                  </td>

                  <td className="py-4">
                    {run.wns}
                  </td>

                  <td className="py-4">
                    {run.qor_score}
                  </td>

                  <td className="py-4">
                    {run.runtime_sec}s
                  </td>

                </tr>

              ))}

            </tbody>

          </table>

        </div>

      </div>

    </div>

  )
}

function Card({ title, value, sub }) {

  return (

    <div className="bg-slate-900 border border-slate-800 rounded-2xl p-6">

      <p className="text-slate-400 text-sm">
        {title}
      </p>

      <h2 className="text-4xl font-bold mt-4">
        {value}
      </h2>

      <p className="text-green-400 mt-2 text-sm">
        {sub}
      </p>

    </div>

  )
}
