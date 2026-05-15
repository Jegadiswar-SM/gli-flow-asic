from fastapi import FastAPI

from analytics.regression import detect_regression

from fastapi.middleware.cors import CORSMiddleware

from metrics.qor_api import (
    get_all_runs,
    get_latest_run,
    get_live_runs,
    get_wns_trend
)

app = FastAPI()

app.add_middleware(

    CORSMiddleware,

    allow_origins=["*"],

    allow_credentials=True,

    allow_methods=["*"],

    allow_headers=["*"],
)

@app.get("/runs")
def runs():

    return get_all_runs()


@app.get("/runs/latest")
def latest_run():

    return get_latest_run()


@app.get("/runs/live")
def live_runs():

    return get_live_runs()


@app.get("/metrics/wns")
def wns():

    return get_wns_trend()

@app.get("/regressions")
def regressions():

    return detect_regression()
