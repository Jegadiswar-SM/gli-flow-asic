import { useEffect, useState } from "react"

function App() {

  const [runsData, setRunsData] = useState([])

  const [liveData, setLiveData] = useState([])

  const [trendsData, setTrendsData] = useState({
    trend: "NO_DATA",
    avg_qor: 0,
    avg_runtime: 0,
    regressions: 0
  })

  useEffect(() => {

    const fetchData = async () => {

      try {

        const runsResponse = await fetch(
          "http://127.0.0.1:8000/runs"
        )

        const runsJson = await runsResponse.json()

        setRunsData(runsJson)

        const liveResponse = await fetch(
          "http://127.0.0.1:8000/live_runs"
        )

        const liveJson = await liveResponse.json()

        setLiveData(liveJson)

        const trendsResponse = await fetch(
          "http://127.0.0.1:8000/trends"
        )

        const trendsJson = await trendsResponse.json()

        setTrendsData(trendsJson)

      } catch (error) {

        console.log(error)
      }
    }

    fetchData()

    const interval = setInterval(
      fetchData,
      2000
    )

    return () => clearInterval(interval)

  }, [])

  return (

    <div
      style={{
        background: "#020817",
        minHeight: "100vh",
        padding: 32,
        color: "white",
        fontFamily: "Inter, sans-serif",
      }}
    >

      <div
        style={{
          marginBottom: 30,
        }}
      >

        <h1
          style={{
            fontSize: 40,
            marginBottom: 10,
          }}
        >
          GLI-FLOW v1.0.0 MVP
        </h1>

        <div
          style={{
            color: "#94a3b8",
          }}
        >
          Execution Intelligence Infrastructure
        </div>

      </div>

      <div
        style={{
          display: "grid",
          gridTemplateColumns:
            "repeat(auto-fit, minmax(220px, 1fr))",
          gap: 20,
          marginBottom: 30,
        }}
      >

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
            Total Runs
          </div>

          <div
            style={{
              fontSize: 36,
              fontWeight: "bold",
            }}
          >
            {runsData.length}
          </div>

        </div>

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
            Average QoR
          </div>

          <div
            style={{
              fontSize: 36,
              fontWeight: "bold",
              color: "#22c55e",
            }}
          >
            {trendsData.avg_qor}
          </div>

        </div>

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
            Average Runtime
          </div>

          <div
            style={{
              fontSize: 36,
              fontWeight: "bold",
              color: "#38bdf8",
            }}
          >
            {trendsData.avg_runtime}s
          </div>

        </div>

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
            Regressions
          </div>

          <div
            style={{
              fontSize: 36,
              fontWeight: "bold",
              color: "#ef4444",
            }}
          >
            {trendsData.regressions}
          </div>

        </div>

      </div>

      <div
        style={{
          background: "#071122",
          border: "1px solid #1e293b",
          borderRadius: 16,
          padding: 20,
          marginBottom: 30,
        }}
      >

        <h2
          style={{
            marginBottom: 20,
          }}
        >
          QoR Trend
        </h2>

        <div
          style={{
            display: "flex",
            alignItems: "flex-end",
            gap: 12,
            height: 220,
            marginTop: 20,
          }}
        >

          {runsData
            .slice()
            .reverse()
            .map((run) => (

              <div
                key={run.run_id}
                style={{
                  flex: 1,
                  display: "flex",
                  flexDirection: "column",
                  alignItems: "center",
                }}
              >

                <div
                  style={{
                    height: `${run.qor_score * 180}px`,
                    width: "100%",
                    background:
                      run.qor_score < 0.7
                        ? "#ef4444"
                        : "#22c55e",
                    borderRadius: 8,
                    transition: "0.4s",
                  }}
                />

                <div
                  style={{
                    marginTop: 8,
                    fontSize: 12,
                    color: "#94a3b8",
                  }}
                >
                  {run.qor_score}
                </div>

              </div>

            ))}

        </div>

      </div>

      <div
        style={{
          background: "#071122",
          border: "1px solid #1e293b",
          borderRadius: 16,
          padding: 20,
          marginBottom: 30,
        }}
      >

        <h2>Live Execution Monitor</h2>

        {liveData.length === 0 && (

          <div
            style={{
              marginTop: 20,
              color: "#94a3b8",
            }}
          >
            No active executions
          </div>

        )}

        {liveData.map((run) => (

          <div
            key={run.run_id}
            style={{
              border: "1px solid #1e293b",
              borderRadius: 12,
              padding: 16,
              marginTop: 16,
            }}
          >

            <div
              style={{
                fontWeight: "bold",
                marginBottom: 12,
              }}
            >
              {run.run_id}
            </div>

            <div
              style={{
                marginBottom: 8,
              }}
            >
              Status: {run.status}
            </div>

            <div
              style={{
                marginBottom: 8,
              }}
            >
              Stage: {run.current_stage}
            </div>

            <div
              style={{
                marginBottom: 8,
              }}
            >
              Progress: {run.progress}%
            </div>

            <div
              style={{
                width: "100%",
                height: 12,
                background: "#0f172a",
                borderRadius: 20,
                overflow: "hidden",
              }}
            >

              <div
                style={{
                  width: `${run.progress}%`,
                  height: "100%",
                  background: "#22c55e",
                  transition: "0.5s",
                }}
              />

            </div>

          </div>

        ))}

      </div>

      <div
        style={{
          background: "#071122",
          border: "1px solid #1e293b",
          borderRadius: 16,
          padding: 20,
        }}
      >

        <h2>Execution History</h2>

        <table
          style={{
            width: "100%",
            marginTop: 20,
            borderCollapse: "collapse",
          }}
        >

          <thead>

            <tr
              style={{
                textAlign: "left",
                color: "#94a3b8",
              }}
            >

              <th>Run ID</th>
              <th>Status</th>
              <th>Stage</th>
              <th>QoR</th>
              <th>WNS</th>
              <th>Runtime</th>

            </tr>

          </thead>

          <tbody>

            {runsData.map((run) => (

              <tr key={run.run_id}>

                <td style={{ paddingTop: 16 }}>
                  {run.run_id}
                </td>

                <td>{run.status}</td>

                <td>{run.current_stage}</td>

                <td>{run.qor_score}</td>

                <td>{run.wns}</td>

                <td>{run.runtime_sec}</td>

              </tr>

            ))}

          </tbody>

        </table>

      </div>

    </div>
  )
}

export default App
