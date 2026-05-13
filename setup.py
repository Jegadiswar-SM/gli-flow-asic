from setuptools import setup, find_packages

setup(
    name="gli-flow",
    version="0.1.0",
    description="Reproducible RTL-to-GDS silicon pipeline — Green Lantern Industries",
    author="Green Lantern Industries",
    license="Apache-2.0",
    packages=find_packages(),
    install_requires=[
        "click>=8.0",
        "rich>=13.0",
        "pyyaml>=6.0",
        "jinja2>=3.0",
        "tabulate>=0.9",
    ],
    entry_points={
        "console_scripts": [
            "gli-flow=gli_flow.cli:main",
        ],
    },
    python_requires=">=3.9",
)
