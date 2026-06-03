## License Architecture

All GPL and GPL-3.0 tool invocations use subprocess exclusively to maintain license isolation.

Tools invoked via subprocess ONLY:
- OpenSTA (GPL-3.0) — via OpenROAD subprocess
- OpenROAD (BSD-3-Clause) — subprocess
- Magic (GPL-2.0) — subprocess
- Netgen (GPL-2.0) — subprocess
- KLayout (GPL-2.0) — subprocess
- Yosys (ISC) — subprocess

No GLI-FLOW Python code links against any GPL library at runtime.
