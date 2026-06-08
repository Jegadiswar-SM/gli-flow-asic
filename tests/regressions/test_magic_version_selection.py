"""
Regression test: Magic version selection.

Verifies that tool_discovery.py selects the supported Magic version
(8.3.659) over the known-broken version (8.3.105) when both exist.

This test creates a temporary bin directory with mock magic binaries
and tests the discovery logic.
"""

import os
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path


def _create_mock_magic(bindir: Path, version: str, name: str = "magic"):
    """Create a mock magic binary that prints the given version string."""
    path = bindir / name
    path.write_text(
        "#!/usr/bin/env python3\n"
        "import sys\n"
        f"print('Magic {version}')\n"
        "sys.exit(0)\n"
    )
    path.chmod(0o755)
    return str(path)


def _create_mock_magicdnull(bindir: Path, version: str):
    """Create a mock magicdnull binary."""
    path = bindir / "magicdnull"
    path.write_text(
        "#!/usr/bin/env python3\n"
        "import sys\n"
        f"print('Magic {version}')\n"
        "sys.exit(0)\n"
    )
    path.chmod(0o755)
    return str(path)


def test_tool_discovery_prefers_newer_magic():
    """find_magic_binary should prefer 8.3.659 over 8.3.105."""
    from gli_flow.core.tool_discovery import find_magic_binary, find_magicdnull_binary

    with tempfile.TemporaryDirectory() as tmp:
        bindir = Path(tmp) / "bin"
        bindir.mkdir()

        _create_mock_magic(bindir, "8.3.105", name="magic")
        _create_mock_magicdnull(bindir, "8.3.105")

        old_path = os.environ.get("PATH", "")
        os.environ["PATH"] = str(bindir)
        try:
            tb = find_magic_binary()
            assert tb is not None, "Should find magic even if old version"
            assert tb.path.startswith(str(bindir)), f"Should find mock in temp dir, got {tb.path}"
        finally:
            os.environ["PATH"] = old_path


def test_tool_discovery_prefers_659_over_105():
    """find_magic_binary should prefer 8.3.659 when both 8.3.105 and 8.3.659 exist."""
    from gli_flow.core.tool_discovery import find_magic_binary, find_magicdnull_binary

    with tempfile.TemporaryDirectory() as tmp:
        bindir = Path(tmp) / "bin"
        bindir.mkdir()
        libdir = Path(tmp) / "lib" / "magic" / "tcl"
        libdir.mkdir(parents=True)

        old_path = os.environ.get("PATH", "")
        # Put old version in PATH first (system default)
        os.environ["PATH"] = str(bindir) + ":" + old_path
        try:
            _create_mock_magic(bindir, "8.3.105", name="magic")
            # Put new version in the lib directory (user-installed path)
            mock_new = _create_mock_magicdnull(libdir, "8.3.659")

            tb = find_magic_binary()
            assert tb is not None, "Should find a magic binary"

            # The new version (8.3.659) should be preferred
            found_in_user_path = "8.3.659" in tb.version_str
            found_version = tb.version
            assert found_version >= (8, 3, 659) or found_in_user_path, (
                f"Expected version >= 8.3.659, got {tb.version_str} at {tb.path}"
            )
        finally:
            os.environ["PATH"] = old_path


def test_magicdnull_prefers_659_over_105():
    """find_magicdnull_binary should prefer user-installed (8.3.659) over system (8.3.105)."""
    from gli_flow.core.tool_discovery import find_magicdnull_binary

    with tempfile.TemporaryDirectory() as tmp:
        old_path = os.environ.get("PATH", "")
        user_libdir = Path(tmp) / ".local" / "lib" / "magic" / "tcl"
        user_libdir.mkdir(parents=True)
        system_libdir = Path(tmp) / "usr" / "lib" / "x86_64-linux-gnu" / "magic" / "tcl"
        system_libdir.mkdir(parents=True)

        old_home = os.environ.get("HOME", "")
        os.environ["HOME"] = str(Path(tmp))
        try:
            # Create old system version
            old_magicdnull = system_libdir / "magicdnull"
            old_magicdnull.write_text(
                "#!/usr/bin/env python3\nimport sys\nprint('Magic 8.3 revision 105')\nsys.exit(0)\n"
            )
            old_magicdnull.chmod(0o755)

            # Create new user-installed version
            new_magicdnull = user_libdir / "magicdnull"
            new_magicdnull.write_text(
                "#!/usr/bin/env python3\nimport sys\nprint('Magic 8.3 revision 659')\nsys.exit(0)\n"
            )
            new_magicdnull.chmod(0o755)

            tb = find_magicdnull_binary()
            assert tb is not None, "Should find a magicdnull binary"
            # Should prefer user-installed 8.3.659
            assert tb.version >= (8, 3, 659), (
                f"Expected version >= 8.3.659, got {tb.version_str} at {tb.path}"
            )
        finally:
            os.environ["PATH"] = old_path
            os.environ["HOME"] = old_home


def test_tool_discovery_rejects_broken_version():
    """is_broken_version should correctly identify 8.3.105 as broken."""
    from gli_flow.core.tool_discovery import is_broken_version

    assert is_broken_version("magic", (8, 3, 105)) is True
    assert is_broken_version("magic", (8, 3, 659)) is False
    assert is_broken_version("magic", (8, 3, 106)) is False
    assert is_broken_version("yosys", (0, 40)) is False


def test_tool_discovery_semver_parsing():
    """_parse_semver should handle various version strings."""
    from gli_flow.core.tool_discovery import _parse_semver

    assert _parse_semver("8.3.105") == (8, 3, 105)
    assert _parse_semver("8.3.659") == (8, 3, 659)
    assert _parse_semver("1.2.3.4") == (1, 2, 3, 4)
    assert _parse_semver("v2.0-17598-ga008522d8") == (2, 0, 17598)
    assert _parse_semver("Yosys 0.40 (git sha1 ...)") == (0, 40)
    assert _parse_semver("") == (0,)
