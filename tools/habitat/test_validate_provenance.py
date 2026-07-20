#!/usr/bin/env python3
"""Regression checks for the Habitat provenance gate's current red state."""

from __future__ import annotations

import subprocess
import sys
import json
import hashlib
import re
import shutil
import tempfile
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
VALIDATOR = ROOT / "tools/habitat/validate_provenance.py"


def run(mode: str, root: Path = ROOT) -> str:
    result = subprocess.run(
        [sys.executable, str(VALIDATOR), "--root", str(root), mode],
        cwd=ROOT,
        check=False,
        capture_output=True,
        text=True,
    )
    assert result.returncode == 1, result.stdout + result.stderr
    return result.stdout + result.stderr


def fixture_root() -> Path:
    fixture = Path(tempfile.mkdtemp(prefix="hh-provenance-"))
    for relative in (
        "src/habitat/spot_data.c",
        "src/habitat/spot_interaction.c",
        "data/scripts/habitat_spot.inc",
        "src/data/items.h",
        "docs/assets/placeholder-assets.json",
        "graphics/items/icons/question_mark.png",
    ):
        source = ROOT / relative
        target = fixture / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(source, target)
    return fixture


def test_replacing_question_marks_without_six_release_records_stays_red() -> None:
    fixture = fixture_root()
    try:
        items = fixture / "src/data/items.h"
        items.write_text(
            items.read_text(encoding="utf-8").replace(
                "gItemIcon_QuestionMark", "gItemIcon_HH_Unapproved"
            ),
            encoding="utf-8",
        )
        manifest = fixture / "docs/assets/placeholder-assets.json"
        data = json.loads(manifest.read_text(encoding="utf-8"))
        data["temporary_assets"] = []
        data["release_assets"] = []
        manifest.write_text(json.dumps(data), encoding="utf-8")
        result = subprocess.run(
            [sys.executable, str(VALIDATOR), "--root", str(fixture), "--release"],
            check=False,
            capture_output=True,
            text=True,
        )
        output = result.stdout + result.stderr
        assert result.returncode == 1, output
        assert "missing required furnishing release record" in output, output
    finally:
        shutil.rmtree(fixture)


def test_development_rejects_an_unmanifested_furnishing_icon() -> None:
    fixture = fixture_root()
    try:
        items = fixture / "src/data/items.h"
        items.write_text(
            items.read_text(encoding="utf-8").replace(
                "gItemIcon_QuestionMark", "gItemIcon_HH_Unapproved"
            ),
            encoding="utf-8",
        )
        result = subprocess.run(
            [sys.executable, str(VALIDATOR), "--root", str(fixture), "--development"],
            check=False,
            capture_output=True,
            text=True,
        )
        output = result.stdout + result.stderr
        assert result.returncode == 1, output
        assert "furnishing item lacks manifested temporary or approved release record" in output, output
    finally:
        shutil.rmtree(fixture)


def test_replacing_pending_copy_without_approval_stays_red() -> None:
    fixture = fixture_root()
    try:
        script = fixture / "data/scripts/habitat_spot.inc"
        script.write_text(
            script.read_text(encoding="utf-8").replace("PLACEHOLDER", "UNAPPROVED COPY"),
            encoding="utf-8",
        )
        result = subprocess.run(
            [sys.executable, str(VALIDATOR), "--root", str(fixture), "--development"],
            check=False,
            capture_output=True,
            text=True,
        )
        output = result.stdout + result.stderr
        assert result.returncode == 1, output
        assert "pending copy record has non-temporary source text" in output, output
    finally:
        shutil.rmtree(fixture)


def test_approved_neutral_fallback_clears_its_own_copy_blocker() -> None:
    fixture = fixture_root()
    try:
        interaction = fixture / "src/habitat/spot_interaction.c"
        interaction.write_text(
            interaction.read_text(encoding="utf-8").replace(
                "PLACEHOLDER: nothing here.$", "Nothing here.$"
            ),
            encoding="utf-8",
        )
        manifest = fixture / "docs/assets/placeholder-assets.json"
        data = json.loads(manifest.read_text(encoding="utf-8"))
        approval = fixture / "docs/assets/approvals/neutral-not-a-spot.md"
        approval.parent.mkdir(parents=True)
        approval.write_text("Approved neutral fallback copy.\n", encoding="utf-8")
        source = interaction.read_text(encoding="utf-8")
        match = re.search(r"static const u8 sText_NotASpot\[\] = _\((.*?);\n", source, re.DOTALL)
        assert match is not None
        record = data["copy_records"]["src/habitat/spot_interaction.c:sText_NotASpot"]
        record["approval_status"] = "approved"
        record["approval_reference"] = "docs/assets/approvals/neutral-not-a-spot.md"
        record["approved_text_sha256"] = hashlib.sha256(match.group(0).encode("utf-8")).hexdigest()
        manifest.write_text(json.dumps(data), encoding="utf-8")
        result = subprocess.run(
            [sys.executable, str(VALIDATOR), "--root", str(fixture), "--development"],
            check=False,
            capture_output=True,
            text=True,
        )
        output = result.stdout + result.stderr
        assert result.returncode == 1, output
        assert "copy record src/habitat/spot_interaction.c:sText_NotASpot:" not in output, output
        assert "copy record awaits narrative approval: src/habitat/spot_interaction.c:sText_NotASpot" not in output, output
        assert "approved copy record" not in output, output
    finally:
        shutil.rmtree(fixture)


def main() -> int:
    development = run("--development")
    assert "player-facing temporary text" in development, development
    assert "temporary furnishing icon" in development, development

    release = run("--release")
    assert "player-facing temporary text" in release, release
    assert "temporary furnishing icon" in release, release
    assert "temporary asset manifest is not empty" in release, release

    test_replacing_question_marks_without_six_release_records_stays_red()
    test_development_rejects_an_unmanifested_furnishing_icon()
    test_replacing_pending_copy_without_approval_stays_red()
    test_approved_neutral_fallback_clears_its_own_copy_blocker()

    print("test_validate_provenance: expected development and release blockers are reported")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
