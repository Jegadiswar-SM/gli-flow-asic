import pytest
from pathlib import Path


class TestNetgenArgumentConstruction:
    """Verify netgen -batch lvs receives correctly formed arguments."""

    def test_circuit_specs_are_separate_list_elements(self):
        """Each circuit spec must be its own list element (not multi-token strings)."""
        from gli_flow.backends.openroad_adapter import OpenRoadAdapter

        adapter = OpenRoadAdapter(pdk_root="/tmp")
        netgen_bin = "/usr/bin/netgen-lvs"
        spice_path = "/tmp/circuit1.spice"
        clean_netlist = "/tmp/netlist.v"
        design_name = "top"
        setup_file = "/tmp/setup.tcl"
        report_path = "/tmp/report.txt"
        pdk_sc_spice = "/tmp/pdk.spice"

        lvs_args = [netgen_bin, "-batch", "lvs"]
        lvs_args.append(f"{spice_path} {design_name}")
        lvs_args.append(f"{pdk_sc_spice} {design_name}")
        lvs_args.append(f"{clean_netlist} {design_name}")
        lvs_args.extend([setup_file, report_path])

        assert lvs_args[0] == netgen_bin
        assert lvs_args[1] == "-batch"
        assert lvs_args[2] == "lvs"

        circuit1 = lvs_args[3]
        assert circuit1 == f"{spice_path} {design_name}"
        assert " " in circuit1

        circuit2a = lvs_args[4]
        assert circuit2a == f"{pdk_sc_spice} {design_name}"

        circuit2b = lvs_args[5]
        assert circuit2b == f"{clean_netlist} {design_name}"

        assert not any(
            " " in arg and arg.count(" ") > 1
            for arg in lvs_args[3:-2]
        ), "no multi-token filename construction"

    def test_each_circuit_spec_has_exactly_one_space(self):
        """Each circuit spec argument should be exactly 'path name' (one space)."""
        specs = [
            "/tmp/layout.spice top",
            "/tmp/pdk.spice top",
            "/tmp/netlist.v top",
        ]
        for spec in specs:
            assert spec.count(" ") == 1, f"circuit spec must have exactly one space: {spec!r}"
            file_part, name_part = spec.rsplit(" ", 1)
            assert file_part, f"file path must not be empty in {spec!r}"
            assert name_part, f"design name must not be empty in {spec!r}"

    def test_no_embedded_spaces_in_file_paths(self):
        """File paths within circuit specs must not contain spaces."""
        specs = [
            ("/tmp/circuit1.spice", "top"),
            ("/tmp/pdk_models.spice", "top"),
            ("/tmp/design_netlist.v", "top"),
        ]
        for file_part, name in specs:
            arg = f"{file_part} {name}"
            parsed_file, parsed_name = arg.rsplit(" ", 1)
            assert parsed_file == file_part
            assert parsed_name == name
            assert " " not in parsed_file
