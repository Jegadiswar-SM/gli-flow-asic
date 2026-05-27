from setuptools import setup, find_packages

from gli_flow.version import VERSION

setup(
    name="gli-flow",
    version=VERSION.lstrip("v"),
    description="Reproducible RTL-to-GDS silicon pipeline - Green Lantern Industries",
    long_description="Execution intelligence and orchestration infrastructure for open-source ASIC design workflows.",
    long_description_content_type="text/plain",
    author="Green Lantern Industries",
    author_email="team@gatelevel.io",
    url="https://github.com/green-lantern-industries/gli-flow",
    license="Apache-2.0",
    license_files=("LICENSE",),
    packages=find_packages() + ["provenance", "failure_atlas",
                                 "gli_flow.provenance", "gli_flow.regression",
                                 "gli_flow.telemetry"],
    package_data={
        "failure_atlas": ["*.json"],
        "provenance": ["*.py"],
    },
    include_package_data=True,
    extras_require={
        "install": [
            "distro>=1.8.0",
            "volare>=0.18.0",
        ],
    },
    install_requires=[
        "click>=8.1.0",
        "rich>=13.7.0",
        "pyyaml>=6.0.0",
        "jinja2>=3.1.0",
        "tabulate>=0.9.0",
    ],
    entry_points={
        "console_scripts": [
            "gli-flow=gli_flow.cli.main:main",
        ],
    },
    python_requires=">=3.9",
    classifiers=[
        "Development Status :: 3 - Alpha",
        "Intended Audience :: Science/Research",
        "License :: OSI Approved :: Apache Software License",
        "Programming Language :: Python :: 3",
        "Programming Language :: Python :: 3.9",
        "Programming Language :: Python :: 3.10",
        "Programming Language :: Python :: 3.11",
        "Topic :: Scientific/Engineering :: Electronic Design Automation (EDA)",
    ],
)
