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

const pieData = [
  { name: "Timing", value: 25 },
  { name: "Power", value: 20 },
  { name: "Area", value: 18 },
  { name: "Routing", value: 22 },
  { name: "DRC", value: 15 },
]

const COLORS = [
  "#22c55e",
  "#3b82f6",
  "#8b5cf6",
  "#f59e0b",
  "#ef4444",
]

function MetricCard({
  title,
  value,
  subtitle,
}) {

  return (

    <div
      style={{
        background: "#071122",
        border: "1px solid #1e293b",
        borderRadius: 16,
        padding: 20,
      }}
    >

      <div
        style={{
          color: "#94a3b8",
          marginBottom: 10,
        }}
      >
        {title}
      </div>

      <div
        style={{
          fontSize: 36,
          fontWeight: "bold",
          marginBottom: 8,
        }}
      >
        {value}
      </div>

      <div
        style={{
          color: "#22c55e",
          fontSize: 14,
        }}
      >
        {subtitle}
      </div>

    </div>

  )
}

export default function App() {

  const [runs, setRuns] = useState([])
  const [liveRuns, setLiveRuns] = useState([])
  const [trendData, setTrendData] = useState(null)

  const fetchRuns = async () => {

    try {

      const response = await fetch(
        "http://localhost:8000/runs"
      )

      const data = await response.json()

      setRuns(data)

    } catch (error) {

      console.error(error)

    }

  }

  const fetchLiveRuns = async () => {

    try {

      const response = await fetch(
        "http://localhost:8000/live_runs"
      )

      const data = await response.json()

      setLiveRuns(data)

    } catch (error) {

      console.error(error)

    }

  }

  const fetchTrendData = async () => {

    try {

      const response = await fetch(
        "http://localhost:8000/trends"
      )

      const data = await response.json()

      setTrendData(data)

    } catch (error) {

      console.error(error)

    }

  }

  useEffect(() => {

    fetchRuns()
    fetchLiveRuns()
    fetchTrendData()

    const interval = setInterval(() => {

      fetchRuns()
      fetchLiveRuns()
      fetchTrendData()

    }, 3000)

    return () => clearInterval(interval)

  }, [])

  const totalRuns = runs.length

  const latestRun =
    runs.length > 0
      ? runs[0]
      : null

  const regressions = runs.filter(
    (run) =>
      run.status === "FAILED"
  ).length

  const chartData = runs
    .slice()
    .reverse()
    .map((run, index) => ({
      run: index,
      qor: run.qor_score,
    }))

  return (

    <div
      style={{
        minHeight: "100vh",
        background: "#020617",
        color: "white",
        padding: 24,
        fontFamily: "Arial",
      }}
    >

      <div
        style={{
          marginBottom: 30,
        }}
      >

        <h1
          style={{
            fontSize: 42,
            marginBottom: 6,
          }}
        >
          GLI-FLOW
        </h1>

        <p
          style={{
            color: "#94a3b8",
          }}
        >
          Execution Intelligence Infrastructure
        </p>

      </div>

      <div
        style={{
          display: "grid",
          gridTemplateColumns:
            "repeat(auto-fit, minmax(220px, 1fr))",
          gap: 20,
          marginBottom: 24,
        }}
      >

        <MetricCard
          title="Total Runs"
          value={totalRuns}
          subtitle="Execution history"
        />

        <MetricCard
          title="Latest QoR"
          value={
            latestRun
              ? latestRun.qor_score
              : 0
          }
          subtitle="Quality score"
        />

        <MetricCard
          title="Regressions"
          value={regressions}
          subtitle="Detected anomalies"
        />

        <MetricCard
          title="Latest WNS"
          value={
            latestRun
              ? latestRun.wns
              : 0
          }
          subtitle="Timing closure"
        />

      </div>

      {
        trendData && (

          <div
            style={{
              background: "#071122",
              border: "1px solid #1e293b",
              borderRadius: 16,
              padding: 20,
              marginBottom: 24,
            }}
          >

            <h2
              style={{
                marginBottom: 20,
              }}
            >
              Trend Intelligence
            </h2>

            <div
              style={{
                display: "grid",
                gridTemplateColumns:
                  "repeat(auto-fit, minmax(180px, 1fr))",
                gap: 20,
              }}
            >

              <MetricCard
                title="Trend"
                value={trendData.trend}
                subtitle="QoR direction"
              />

              <MetricCard
                title="QoR Delta"
                value={trendData.qor_delta}
                subtitle="Historical movement"
              />

              <MetricCard
                title="Average QoR"
                value={trendData.average_qor}
                subtitle="Execution stability"
              />

              <MetricCard
                title="Average Runtime"
                value={`${trendData.average_runtime}s`}
                subtitle="Runtime intelligence"
              />

            </div>

          </div>

        )
      }

      <div
        style={{
          display: "grid",
          gridTemplateColumns:
            "2fr 1fr",
          gap: 24,
          marginBottom: 24,
        }}
      >

        <div
          style={{
            background: "#071122",
            border: "1px solid #1e293b",
            borderRadius: 16,
            padding: 20,
            height: 420,
          }}
        >

          <h2
            style={{
              marginBottom: 20,
            }}
          >
            QoR Trend
          </h2>

          <ResponsiveContainer
            width="100%"
            height="90%"
          >

            <LineChart data={chartData}>

              <XAxis dataKey="run" />

              <YAxis />

              <Tooltip />

              <Line
                type="monotone"
                dataKey="qor"
                stroke="#22c55e"
                strokeWidth={3}
              />

            </LineChart>

          </ResponsiveContainer>

        </div>

        <div
          style={{
            background: "#071122",
            border: "1px solid #1e293b",
            borderRadius: 16,
            padding: 20,
            height: 420,
          }}
        >

          <h2
            style={{
              marginBottom: 20,
            }}
          >
            QoR Breakdown
          </h2>

          <ResponsiveContainer
            width="100%"
            height="90%"
          >

            <PieChart>

              <Pie
                data={pieData}
                dataKey="value"
                outerRadius={120}
              >

                {
                  pieData.map(
                    (entry, index) => (

                      <Cell
                        key={index}
                        fill={
                          COLORS[index % COLORS.length]
                        }
                      />

                    )
                  )
                }

              </Pie>

            </PieChart>

          </ResponsiveContainer>

        </div>

      </div>

      <div
        style={{
          background: "#071122",
          border: "1px solid #1e293b",
          borderRadius: 16,
          padding: 20,
          marginBottom: 24,
        }}
      >

        <h2
          style={{
            marginBottom: 20,
          }}
        >
          Live Execution Monitor
        </h2>

        {
          liveRuns.length === 0 ? (

            <p
              style={{
                color: "#94a3b8",
              }}
            >
              No active executions
            </p>

          ) : (

            <div
              style={{
                display: "grid",
                gap: 16,
              }}
            >

              {
                liveRuns.map((run) => (

                  <div
                    key={run.run_id}
                    style={{
                      border:
                        "1px solid #1e293b",
                      borderRadius: 12,
                      padding: 16,
                    }}
                  >

                    <h3>{run.run_id}</h3>

                    <p
                      style={{
                        color: "#22c55e",
                      }}
                    >
                      {run.current_stage}
                    </p>

                    <p
                      style={{
                        color: "#94a3b8",
                      }}
                    >
                      {run.status}
                    </p>

                  </div>

                ))
              }

            </div>

          )
        }

      </div>

      <div
        style={{
          background: "#071122",
          border: "1px solid #1e293b",
          borderRadius: 16,
          padding: 20,
        }}
      >

        <h2
          style={{
            marginBottom: 20,
          }}
        >
          Recent Runs
        </h2>

        <table
          style={{
            width: "100%",
            borderCollapse: "collapse",
          }}
        >

          <thead>

            <tr
              style={{
                color: "#94a3b8",
                textAlign: "left",
              }}
            >

              <th
                style={{
                  paddingBottom: 12,
                }}
              >
                Run ID
              </th>

              <th>Status</th>

              <th>Stage</th>

              <th>QoR</th>

              <th>WNS</th>

              <th>Runtime</th>

            </tr>

          </thead>

          <tbody>

            {
              runs.map((run) => (

                <tr
                  key={run.run_id}
                  style={{
                    borderTop:
                      "1px solid #1e293b",
                  }}
                >

                  <td
                    style={{
                      padding: "14px 0",
                    }}
                  >
                    {run.run_id}
                  </td>

                  <td
                    style={{
                      color:
                        run.status === "COMPLETED"
                          ? "#22c55e"
                          : run.status === "RUNNING"
                          ? "#f59e0b"
                          : "#ef4444",
                    }}
                  >
                    {run.status}
                  </td>

                  <td>
                    {run.current_stage}
                  </td>

                  <td>
                    {run.qor_score}
                  </td>

                  <td>
                    {run.wns}
                  </td>

                  <td>
                    {run.runtime_sec}s
                  </td>

                </tr>

              ))
            }

          </tbody>

        </table>

      </div>

    </div>

  )

}
