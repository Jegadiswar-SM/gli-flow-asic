
PILLAR 1: Dynamic Top-Module & File Dependency Discovery
The Problem
Users provide a directory. They do not know the correct top module. They do not know compilation order. Tools crash silently on wrong order.
Architecture: Hierarchical Dependency Resolver
INPUT: directory path or file list
           │
           ▼
┌─────────────────────────────────┐
│   FILE SCANNER                  │
│   Walk directory tree           │
│   Collect: .v .sv .vh .svh .vhd │
│   Ignore:  sim/ tb/ testbench/  │
│            *_tb.v *_sim.v       │
└────────────┬────────────────────┘
             │
             ▼
┌─────────────────────────────────┐
│   MODULE PARSER (per file)      │
│   Regex extract:                │
│     module <name> (             │
│     endmodule                   │
│   Build map:                    │
│     file → [modules_defined]    │
│     module → file               │
└────────────┬────────────────────┘
             │
             ▼
┌─────────────────────────────────┐
│   INSTANTIATION MAPPER          │
│   For each file, regex scan:    │
│     <identifier> <inst_name> (  │
│   Exclude keywords:             │
│     module/input/output/wire/   │
│     reg/always/assign/if/case   │
│   Build graph:                  │
│     module → [instantiates...]  │
└────────────┬────────────────────┘
             │
             ▼
┌─────────────────────────────────┐
│   TOP MODULE DETECTOR           │
│   For each module M:            │
│     if M not instantiated       │
│     by any other module:        │
│       candidate_tops.add(M)     │
│                                 │
│   Score candidates:             │
│     +3 if filename == module    │
│     +2 if most instantiations   │
│     +1 if has clock port        │
│     -5 if name contains _tb     │
│     -5 if name contains _sim    │
│     -5 if name contains _test   │
│   Return highest scored         │
└────────────┬────────────────────┘
             │
             ▼
┌─────────────────────────────────┐
│   DEPENDENCY ORDERER            │
│   Topological sort of DAG:      │
│     leaf modules first          │
│     (no outgoing instantiation) │
│   Kahn's algorithm:             │
│     queue = nodes with in=0     │
│     while queue:                │
│       emit node                 │
│       reduce in-degree          │
│       enqueue new zeros         │
│   Cycle detection:              │
│     if nodes_emitted <          │
│     total_nodes:                │
│       CIRCULAR_DEP_ERROR        │
└────────────┬────────────────────┘
             │
             ▼
OUTPUT: ordered_flist, top_module, dependency_graph
Pseudo-Code
pythonclass HierarchyResolver:

    TESTBENCH_PATTERNS = re.compile(
        r'(_tb|_sim|_test|testbench|tb_)',
        re.IGNORECASE
    )
    MODULE_DEF = re.compile(
        r'^\s*module\s+(\w+)\s*[#(]', re.MULTILINE
    )
    INST_PATTERN = re.compile(
        r'^\s*(\w+)\s+(?:#\([^)]*\)\s*)?(\w+)\s*\(',
        re.MULTILINE
    )
    VERILOG_KEYWORDS = frozenset([
        'module','endmodule','input','output','inout',
        'wire','reg','logic','always','assign','if',
        'else','case','begin','end','for','while',
        'parameter','localparam','integer','genvar',
        'generate','endgenerate','initial','fork',
        'posedge','negedge','and','or','not','xor',
        'buf','nand','nor','xnor','supply0','supply1'
    ])

    def resolve(self, source_dir: Path) -> ResolutionResult:
        files = self._collect_rtl_files(source_dir)
        module_map = self._parse_all_modules(files)
        inst_graph = self._build_instantiation_graph(
            files, module_map
        )
        top = self._detect_top_module(
            module_map, inst_graph
        )
        ordered = self._topological_sort(
            module_map, inst_graph, top
        )
        return ResolutionResult(
            top_module=top,
            ordered_files=ordered,
            graph=inst_graph
        )

    def _detect_top_module(self, module_map, graph):
        all_instantiated = set()
        for deps in graph.values():
            all_instantiated.update(deps)

        candidates = {
            m for m in module_map
            if m not in all_instantiated
            and not self.TESTBENCH_PATTERNS.search(m)
        }

        if len(candidates) == 1:
            return candidates.pop()

        # Score tiebreak
        scores = {}
        for m in candidates:
            s = 0
            f = module_map[m]
            if Path(f).stem == m: s += 3
            if m in graph: s += len(graph[m])
            # check for clock port
            content = Path(f).read_text()
            if re.search(r'\bclk\b|\bclock\b', content): s += 1
            scores[m] = s

        return max(scores, key=scores.get)

PILLAR 2: Strict Input Sanitization & Automated Fix-Ups
Architecture: Pre-Flight Sanitization Pipeline
RAW INPUT FILES
      │
      ▼
┌──────────────────────────────────────┐
│  ENCODING NORMALIZER                 │
│  1. Detect encoding (chardet)        │
│  2. Convert to UTF-8                 │
│  3. Strip BOM if present             │
│  4. Replace \r\n → \n (CRLF fix)    │
│  5. Replace \t → 2 spaces            │
│  6. Strip null bytes                 │
│  Output: encoding-clean files        │
└──────────────────┬───────────────────┘
                   │
                   ▼
┌──────────────────────────────────────┐
│  LANGUAGE CLASSIFIER                 │
│  For each file:                      │
│    if .sv or .svh → SYSTEMVERILOG    │
│    if .vhd → VHDL                    │
│    if .v or .vh:                     │
│      scan for SV keywords:          │
│        always_ff always_comb logic  │
│        interface package typedef    │
│        enum struct :: import        │
│      if found → SYSTEMVERILOG       │
│      else → VERILOG                 │
│  Group by language                   │
└──────────────────┬───────────────────┘
                   │
                   ▼
┌──────────────────────────────────────┐
│  SYSTEMVERILOG CONVERTER             │
│  If any SV files:                    │
│    Check sv2v installed              │
│    If yes:                           │
│      sv2v -I<inc_paths> <sv_files>   │
│      → single converted.v           │
│      Validate output has modules     │
│    If no sv2v:                       │
│      WARN + attempt Yosys -sv flag  │
│      Log known risk to report        │
└──────────────────┬───────────────────┘
                   │
                   ▼
┌──────────────────────────────────────┐
│  TIMESCALE INJECTOR                  │
│  Scan first 20 lines of each file   │
│  If no `timescale directive:         │
│    Check if other files define it   │
│    If missing globally:              │
│      Prepend `timescale 1ns/1ps     │
│      to first file in flist         │
│      Log injection to report        │
└──────────────────┬───────────────────┘
                   │
                   ▼
┌──────────────────────────────────────┐
│  INCLUDE PATH RESOLVER               │
│  Scan all files for `include "..."  │
│  For each include:                   │
│    Check if file exists at:          │
│      - relative to source file       │
│      - in inc/ include/ headers/    │
│      - in every source directory    │
│    Build -I flag list                │
│    If include not found:             │
│      Create empty stub file         │
│      WARN in report                  │
└──────────────────┬───────────────────┘
                   │
                   ▼
┌──────────────────────────────────────┐
│  YOSYS DFF NAME NORMALIZER           │
│  (Specific to post-synthesis LVS)   │
│  Regex replace in netlist:           │
│    \name[N]$_DFF_PP0_               │
│    → name_N_DFF_PP0_                │
│  Also fix escaped identifiers:      │
│    \signal[N] → signal_N_           │
│  Add power connections:              │
│    wire VSUBS;                       │
│    Add .VGND(VSUBS) .VPWR(VSUBS)   │
│    .VPB(VSUBS) .VNB(VSUBS)         │
│    to each standard cell instance   │
└──────────────────┬───────────────────┘
                   │
                   ▼
OUTPUT: sanitized_files[], include_flags[], warnings[]
The SPICE Post-Processing Wrapper
This was one of the 7 confirmed-universal bugs. The fix is architecturally embedded:
pythonclass SPICEPostProcessor:

    def wrap_top_cell(
        self,
        spice_path: Path,
        top_module: str,
        pdk: str
    ) -> Path:
        """
        Magic always emits top-level circuit outside
        .subckt/.ends. Netgen requires .subckt wrapping.
        This is a universal bug for all Magic + sky130
        combinations — not design-specific.
        """
        content = spice_path.read_text()
        lines = content.splitlines()

        # Find the top-level circuit block
        # It appears as bare .circuit / .end
        # without .subckt wrapper
        wrapped = []
        in_top = False
        subckt_depth = 0

        for line in lines:
            stripped = line.strip().upper()

            if stripped.startswith('.SUBCKT'):
                subckt_depth += 1
                wrapped.append(line)

            elif stripped.startswith('.ENDS'):
                subckt_depth -= 1
                wrapped.append(line)

            elif (stripped.startswith('.GLOBAL')
                  or stripped.startswith('*')):
                wrapped.append(line)

            elif subckt_depth == 0 and (
                stripped.startswith('X')
                or stripped.startswith('C')
                or stripped.startswith('R')
            ):
                # Top-level element outside subckt
                if not in_top:
                    wrapped.append(
                        f'.SUBCKT {top_module.upper()}'
                    )
                    wrapped.append('.GLOBAL VSUBS')
                    in_top = True
                wrapped.append(line)

            else:
                if in_top and stripped.startswith('.END'):
                    wrapped.append(
                        f'.ENDS {top_module.upper()}'
                    )
                    in_top = False
                wrapped.append(line)

        output_path = spice_path.with_suffix('.wrapped.spice')
        output_path.write_text('\n'.join(wrapped))
        return output_path

    def suppress_parasitics(self, magic_tcl: str) -> str:
        """
        Inject cthresh/rthresh to suppress parasitic
        R/C that cause device count mismatch in LVS.
        Universal fix — Magic extracts parasitics by
        default for all designs.
        """
        injection = (
            "ext2spice cthresh 999999\n"
            "ext2spice rthresh 999999\n"
            "ext2spice hierarchy on\n"
        )
        return injection + magic_tcl

PILLAR 3: Dynamic Environment & Tool Abstraction Layer
Architecture: Tool Capability Matrix
BOOT TIME DISCOVERY
         │
         ▼
┌─────────────────────────────────────────┐
│  TOOL DETECTOR (runs once at startup)  │
│                                         │
│  For each required tool:               │
│    [yosys, openroad, magic, netgen,     │
│     klayout, sv2v, iverilog]            │
│                                         │
│  Search order:                          │
│    1. PATH (shutil.which)               │
│    2. BINARY_SEARCH_PATHS list:         │
│       /usr/lib/x86_64-linux-gnu/magic/ │
│         tcl/magicdnull (Magic fix)      │
│       /usr/local/bin/netgen-lvs        │
│         (Netgen fix)                    │
│       ~/.gli-flow/bin/                  │
│       /opt/eda/bin/                     │
│    3. Docker image fallback             │
│                                         │
│  For each found binary:                 │
│    Run version extraction command       │
│    Parse version string → semver tuple  │
│    Check against MIN_VERSIONS dict      │
│    Record: path, version, capabilities  │
└──────────────────┬──────────────────────┘
                   │
                   ▼
┌─────────────────────────────────────────┐
│  CAPABILITY REGISTRY                    │
│                                         │
│  yosys:                                 │
│    path: /usr/bin/yosys                 │
│    version: (0, 40, 0)                  │
│    has_sv_support: True                 │
│    has_abc9: True                       │
│    synth_cmd: "synth_sky130 -flatten"   │
│                                         │
│  magic:                                 │
│    path: /usr/lib/.../magicdnull        │
│    invocation: NOWRAPPER_MODE           │
│    version: (8, 3, 105)                 │
│    needs_rcfile: True                   │
│    tech_version_patched: True           │
│                                         │
│  netgen:                                │
│    path: /usr/local/bin/netgen-lvs      │
│    mode: BATCH_LVS (not TCL)            │
│    version: (1, 5, 270)                 │
└──────────────────┬──────────────────────┘
                   │
                   ▼
┌─────────────────────────────────────────┐
│  RESOURCE ALLOCATOR                     │
│                                         │
│  Estimate design complexity:            │
│    file_count, total_lines,             │
│    module_count, inst_depth             │
│                                         │
│  Complexity score → resource tier:      │
│    TINY   (<500 lines):                 │
│      threads=2, mem_gb=4               │
│    SMALL  (<5K lines):                  │
│      threads=4, mem_gb=8               │
│    MEDIUM (<50K lines):                 │
│      threads=8, mem_gb=16              │
│    LARGE  (<500K lines):                │
│      threads=16, mem_gb=32             │
│    XLARGE (>500K lines):                │
│      threads=max, mem_gb=64            │
│      WARN: may require cloud            │
│                                         │
│  Check available system resources:      │
│    available_mem = psutil.virtual_      │
│      memory().available                 │
│    available_cpu = os.cpu_count()       │
│                                         │
│  Clamp to available:                    │
│    threads = min(requested, avail_cpu) │
│    mem = min(requested, avail_mem*0.8) │
│                                         │
│  Emit resource_spec for subprocess     │
└──────────────────┬──────────────────────┘
                   │
                   ▼
┌─────────────────────────────────────────┐
│  ENVIRONMENT BUILDER                    │
│                                         │
│  Always set:                            │
│    LC_ALL=C                             │
│    LANG=C                               │
│    OMP_NUM_THREADS={threads}            │
│                                         │
│  Never set (proven to break tools):     │
│    CAD_ROOT (breaks Magic 8.3.x)        │
│                                         │
│  Conditionally set:                     │
│    PDK_ROOT (if Magic needs it)         │
│    MAGIC_EXT_USE_GDS=1 (for extraction) │
│                                         │
│  Apply resource limits via preexec_fn:  │
│    RLIMIT_AS = mem_bytes                │
│    RLIMIT_NOFILE = 65536                │
└─────────────────────────────────────────┘
Tool Invocation Abstraction
pythonclass ToolInvoker:
    """
    Single point of entry for all EDA tool subprocess
    calls. Handles version-specific command construction,
    environment safety, and binary path selection.
    """

    INVOCATION_MODES = {
        'magic': {
            'NOWRAPPER': (
                '{magicdnull} -nowrapper -d NULL '
                '-rcfile {rcfile} {script}'
            ),
            'LEGACY': (
                '{magic} -dnull -noconsole '
                '-T {techfile} {script}'
            ),
        },
        'netgen': {
            'BATCH_LVS': (
                '{netgen} -batch lvs '
                '"{spice1} {cell1}" '
                '"{spice2} {cell2}" '
                '{setup} {report}'
            ),
        },
    }

    def invoke_magic(
        self,
        script_path: Path,
        run_dir: Path,
        pdk: str,
        mode: str = 'NOWRAPPER'
    ) -> SubprocessResult:

        caps = self.registry.get('magic')
        template = self.INVOCATION_MODES['magic'][mode]

        cmd_str = template.format(
            magicdnull=caps.path,
            rcfile=self._get_rcfile(pdk),
            script=str(script_path)
        )

        return self._run_safe(
            cmd=cmd_str.split(),
            stage='magic',
            run_dir=run_dir,
            env=safe_env(
                extra={'PDK_ROOT': self._get_pdk_root(pdk)}
            )
        )

    def invoke_netgen_lvs(
        self,
        spice1: Path, cell1: str,
        spice2: Path, cell2: str,
        setup: Path, report: Path,
        run_dir: Path, pdk: str
    ) -> SubprocessResult:

        caps = self.registry.get('netgen')
        template = self.INVOCATION_MODES['netgen']['BATCH_LVS']

        cmd_str = template.format(
            netgen=caps.path,
            spice1=str(spice1), cell1=cell1,
            spice2=str(spice2), cell2=cell2,
            setup=str(setup),
            report=str(report)
        )

        # CRITICAL: Must use shell=True for batch LVS
        # because the argument quoting is complex
        return self._run_safe(
            cmd=cmd_str,
            stage='netgen_lvs',
            run_dir=run_dir,
            shell=True,
            env=safe_env()
        )

PILLAR 4: Intelligent Error Trapping & Graceful Recovery
Architecture: Real-Time Error Interceptor
SUBPROCESS SPAWNS
      │
      ├──────────────────────────────────┐
      │                                  │
      ▼                                  ▼
 STDOUT STREAM                    STDERR STREAM
      │                                  │
      ▼                                  ▼
┌─────────────────┐         ┌──────────────────────┐
│ LINE BUFFER      │         │ ERROR PATTERN MATCHER │
│ Write to logfile │         │                       │
│ Emit progress    │         │ Pattern registry:     │
│ signals          │         │   LATCH_INFERRED      │
│                  │         │   MULTI_DRIVER_NET    │
│ Watch for:       │         │   MODULE_NOT_FOUND    │
│   CRITICAL:      │         │   OOM_KILL            │
│   "ERROR"        │         │   TOOL_VERSION_MISMATCH│
│   "FATAL"        │         │   TECH_VERSION_FAIL   │
│   "abort"        │         │   NETGEN_0_CIRCUITS   │
└────────┬─────────┘         └──────────┬────────────┘
         │                              │
         └──────────┬───────────────────┘
                    │
                    ▼
┌───────────────────────────────────────────┐
│  ERROR CLASSIFIER                         │
│                                           │
│  Match against ErrorPattern registry:     │
│                                           │
│  ErrorPattern(                            │
│    pattern=r"requires magic-(\d+\.\d+)",  │
│    domain=TOOL_VERSION,                   │
│    severity=RECOVERABLE,                  │
│    recovery=PATCH_TECH_VERSION            │
│  )                                        │
│                                           │
│  ErrorPattern(                            │
│    pattern=r"Latch inferred",             │
│    domain=SYNTHESIS_SAFETY,               │
│    severity=TAPEOUT_BLOCKING,             │
│    recovery=NONE                          │
│  )                                        │
│                                           │
│  ErrorPattern(                            │
│    pattern=r"readnet spice.*0 circuits",  │
│    domain=LVS_PIPELINE,                   │
│    severity=RECOVERABLE,                  │
│    recovery=SWITCH_TO_BATCH_LVS           │
│  )                                        │
│                                           │
│  ErrorPattern(                            │
│    pattern=r"Killed|Out of memory",       │
│    domain=RESOURCE,                       │
│    severity=RECOVERABLE,                  │
│    recovery=INCREASE_MEMORY_AND_RETRY     │
│  )                                        │
└───────────────────┬───────────────────────┘
                    │
                    ▼
┌───────────────────────────────────────────┐
│  RECOVERY EXECUTOR                        │
│                                           │
│  if severity == RECOVERABLE:              │
│    execute recovery_strategy()            │
│    retry the stage (max 2 retries)        │
│    if retry fails → UNRECOVERABLE         │
│                                           │
│  if severity == TAPEOUT_BLOCKING:         │
│    halt immediately                       │
│    add to PreFlightReport                 │
│    DO NOT continue to next stage          │
│                                           │
│  if severity == UNRECOVERABLE:            │
│    collect all error context              │
│    generate PreFlightDiagnosticsReport    │
│    halt with structured exit              │
└───────────────────────────────────────────┘
The Relaxation Pivot Engine
pythonclass SynthesisRelaxationPivot:
    """
    When Yosys fails, systematically retry with
    relaxed flags before declaring failure.
    The audit found this universal: any design
    with flip-flops hits DFF naming issues.
    """

    SYNTHESIS_STRATEGIES = [
        SynthStrategy(
            name="STRICT_SV2012",
            yosys_flags=["-sv", "-formal"],
            abc_flags="-dff",
            description="Full SystemVerilog 2012"
        ),
        SynthStrategy(
            name="VERILOG_2005_COMPAT",
            yosys_flags=[],
            abc_flags="",
            preprocessor="sv2v",
            description="Convert SV to V-2005 first"
        ),
        SynthStrategy(
            name="RELAXED_NO_HIER",
            yosys_flags=["-sv"],
            abc_flags="-dff -share",
            flatten=True,
            description="Flat synthesis, no hierarchy"
        ),
        SynthStrategy(
            name="MINIMAL_INFERENCE",
            yosys_flags=[],
            abc_flags="",
            flatten=True,
            no_dff_extraction=True,
            description="Minimal — last resort"
        ),
    ]

    def synthesize_with_retry(
        self,
        design: DesignContext,
        pdk: str
    ) -> SynthesisResult:

        for strategy in self.SYNTHESIS_STRATEGIES:
            log.info(
                f"Trying synthesis strategy: "
                f"{strategy.name}"
            )

            # Apply preprocessor if needed
            rtl_files = design.rtl_files
            if strategy.preprocessor == "sv2v":
                rtl_files = self.sv2v_convert(rtl_files)

            result = self._run_yosys(
                rtl_files=rtl_files,
                top_module=design.top_module,
                strategy=strategy,
                pdk=pdk
            )

            if result.success:
                log.info(
                    f"Synthesis succeeded with "
                    f"strategy: {strategy.name}"
                )
                result.strategy_used = strategy.name
                return result

            # Classify failure for next iteration
            failure = self.classifier.classify(
                result.stderr
            )

            if failure.severity == TAPEOUT_BLOCKING:
                # No point retrying — design has
                # a fundamental flaw
                raise SynthesisSafetyError(
                    failure.check,
                    failure.detail,
                    failure.fix
                )

            log.warning(
                f"Strategy {strategy.name} failed: "
                f"{failure.domain}. Trying next."
            )

        # All strategies exhausted
        raise UnrecoverableSynthesisError(
            strategies_tried=self.SYNTHESIS_STRATEGIES,
            last_error=result.stderr
        )
Pre-Flight Diagnostics Report Generator
pythonclass PreFlightReport:
    """
    When all recovery strategies are exhausted,
    generate a human-readable report that tells
    the user EXACTLY what is wrong and how to fix it.
    """

    KNOWN_FIXES = {
        'MAGIC_VERSION_MISMATCH': {
            'summary': "Magic version too old for PDK",
            'detail': (
                "sky130A.tech requires Magic ≥8.3.411. "
                "Installed: {installed_version}."
            ),
            'fix': (
                "Option 1 (recommended): Patch the "
                "version requirement in sky130A.tech:\n"
                "  sed -i 's/requires magic-8.3.411/"
                "requires magic-8.3.0/' "
                "~/.gli-flow/pdk/sky130A/libs.tech/"
                "magic/sky130A.tech\n\n"
                "Option 2: Install Magic from source "
                "at the required version."
            ),
        },
        'NETGEN_BROKEN_WRAPPER': {
            'summary': "System netgen is a broken wrapper",
            'detail': (
                "/usr/local/bin/netgen is a shell "
                "wrapper that does not support the "
                "-batch lvs mode required for LVS."
            ),
            'fix': (
                "GLI-FLOW automatically uses "
                "netgen-lvs if available. "
                "Install with:\n"
                "  sudo apt install netgen"
                "\nThis installs both netgen "
                "and netgen-lvs."
            ),
        },
        'MAGIC_CAD_ROOT_CONFLICT': {
            'summary': "CAD_ROOT environment variable "
                       "conflicts with Magic",
            'detail': (
                "CAD_ROOT={cad_root} is set in your "
                "environment. Magic 8.3.x uses this "
                "to locate technology files, "
                "overriding the -T flag and "
                "producing no extraction output."
            ),
            'fix': (
                "Unset CAD_ROOT before running "
                "GLI-FLOW:\n"
                "  unset CAD_ROOT\n"
                "Or add to ~/.bashrc:\n"
                "  unset CAD_ROOT"
            ),
        },
        'SPICE_TOP_CELL_UNWRAPPED': {
            'summary': "Magic SPICE output missing "
                       ".subckt wrapper",
            'detail': (
                "Magic emits the top-level circuit "
                "outside a .subckt block. Netgen "
                "requires .subckt wrapping for "
                "comparison."
            ),
            'fix': (
                "This is handled automatically by "
                "GLI-FLOW's SPICE post-processor. "
                "If you are running Magic manually:\n"
                "  Wrap the top-level .circuit block "
                "with .subckt {top} / .ends {top}"
            ),
        },
    }

    def generate(
        self,
        errors: list[ClassifiedError],
        design: DesignContext,
        environment: EnvironmentSnapshot
    ) -> str:

        lines = [
            "=" * 60,
            "GLI-FLOW PRE-FLIGHT DIAGNOSTICS REPORT",
            "=" * 60,
            f"Design:      {design.name}",
            f"Top module:  {design.top_module}",
            f"PDK:         {design.pdk}",
            f"Timestamp:   {datetime.utcnow().isoformat()}",
            "",
            "ENVIRONMENT:",
            f"  Magic:     {environment.magic_version} "
            f"at {environment.magic_path}",
            f"  Netgen:    {environment.netgen_version} "
            f"at {environment.netgen_path}",
            f"  Yosys:     {environment.yosys_version}",
            f"  OpenROAD:  {environment.openroad_version}",
            f"  CAD_ROOT:  {environment.cad_root or '(not set)'}",
            "",
            f"FAILURES FOUND: {len(errors)}",
            "",
        ]

        for i, error in enumerate(errors, 1):
            fix_info = self.KNOWN_FIXES.get(error.code, {})
            lines.extend([
                f"{'─' * 60}",
                f"FAILURE {i}: {error.code}",
                f"Stage:    {error.stage}",
                f"Severity: {error.severity}",
                "",
                f"What happened:",
                f"  {fix_info.get('summary', error.message)}",
                "",
                f"Detail:",
                f"  {fix_info.get('detail', error.detail).format(**error.context)}",
                "",
                f"How to fix:",
                f"  {fix_info.get('fix', 'See log for details')}",
                "",
            ])

        lines.extend([
            "=" * 60,
            "NEXT STEPS",
            "=" * 60,
        ])

        blocking = [e for e in errors
                    if e.severity == 'TAPEOUT_BLOCKING']
        recoverable = [e for e in errors
                       if e.severity == 'RECOVERABLE']

        if blocking:
            lines.append(
                f"⛔ {len(blocking)} TAPEOUT-BLOCKING issue(s) "
                f"must be fixed in your RTL before proceeding."
            )
        if recoverable:
            lines.append(
                f"⚠  {len(recoverable)} environment issue(s). "
                f"Follow the fix instructions above, "
                f"then re-run gli-flow."
            )

        lines.append(
            "\nReport saved to: "
            f"{design.run_dir}/preflight_report.txt"
        )

        report = '\n'.join(lines)
        (design.run_dir / 'preflight_report.txt').write_text(report)
        return report

Complete Integration Flow
gli-flow run <design_path>
         │
         ▼
┌────────────────────────────────────┐
│  1. TOOL DETECTOR                  │
│     Discover all binaries          │
│     Build capability registry      │
│     Detect broken wrappers         │
│     Remove dangerous env vars      │
└────────────┬───────────────────────┘
             │
             ▼
┌────────────────────────────────────┐
│  2. HIERARCHY RESOLVER             │
│     Scan RTL files                 │
│     Build module graph             │
│     Detect top module              │
│     Generate ordered flist         │
└────────────┬───────────────────────┘
             │
             ▼
┌────────────────────────────────────┐
│  3. SANITIZATION PIPELINE          │
│     Encoding normalization         │
│     Language classification        │
│     SV→V conversion (sv2v)         │
│     Timescale injection            │
│     Include path resolution        │
└────────────┬───────────────────────┘
             │
             ▼
┌────────────────────────────────────┐
│  4. RESOURCE ALLOCATOR             │
│     Estimate complexity            │
│     Clamp to available resources   │
│     Build safe_env()               │
│     Set RLIMIT_AS, RLIMIT_NOFILE   │
└────────────┬───────────────────────┘
             │
             ▼
┌────────────────────────────────────┐
│  5. SYNTHESIS (with retry pivot)   │
│     Try STRICT_SV2012              │
│     → fail → VERILOG_2005_COMPAT   │
│     → fail → RELAXED_NO_HIER       │
│     → fail → UNRECOVERABLE         │
│     Post-synth: DFF name normalize │
│     Post-synth: Power pin inject   │
└────────────┬───────────────────────┘
             │
             ▼
┌────────────────────────────────────┐
│  6. P&R (OpenROAD)                 │
│     Overflow fail-fast at >5%      │
│     Multi-corner STA               │
│     Hold timing = blocking         │
└────────────┬───────────────────────┘
             │
             ▼
┌────────────────────────────────────┐
│  7. DRC/LVS (dual tool)            │
│     Magic: magicdnull -nowrapper   │
│            cthresh 999999          │
│     SPICE post-process:            │
│            wrap top cell           │
│     Netgen: -batch lvs mode        │
│             netgen-lvs binary      │
│     KLayout: DRC cross-check       │
└────────────┬───────────────────────┘
             │
             ▼
┌────────────────────────────────────┐
│  8. REPORT GENERATION              │
│     If success: telemetry.json     │
│                 reproducibility    │
│                 failure atlas      │
│     If failure: preflight_report   │
│                 exact fix steps    │
└────────────────────────────────────┘

The 7 Universal Bugs — Now Architecturally Handled
BugWhere Fixed in ArchitectureMagic broken binary (apt)Tool Detector → _BINARY_SEARCH_PATHS → magicdnullsky130A.tech version checkTool Detector → auto-patch on version mismatchNetgen broken wrapperTool Detector → netgen-lvs before netgenTCL readnet returns 0Tool Invoker → BATCH_LVS mode, not TCLSPICE top-cell unwrappedSPICE Post-Processor → wrap_top_cell()Parasitic cap injectionSPICE Post-Processor → suppress_parasitics()Yosys DFF namingSanitization Pipeline → _preprocess_netlist_for_lvs()CAD_ROOT conflictEnvironment Builder → explicit removal from safe_env()
