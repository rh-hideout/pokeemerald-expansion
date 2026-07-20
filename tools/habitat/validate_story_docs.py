#!/usr/bin/env python3
"""Fail closed on the canonical Story documentation contract."""

from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
STORY = ROOT / "Story"
EXPECTED_FILES = (
    "00 - Story Overview.md",
    "01 - Timeline.md",
    "02 - Locked Canon.md",
    "03 - Main Story.md",
    "04 - Characters.md",
    "05 - Tone Guide.md",
    "06 - Open Questions.md",
    "07 - Changelog.md",
)
REQUIRED_HEADINGS = ("Purpose", "Current Canon", "Notes", "Future Expansion")
LOCKED_TIMELINE = (
    "Deoxys falls toward Hoenn.",
    "Rayquaza rises to meet it.",
    "Deoxys defeats Rayquaza but does not kill it.",
    "Rayquaza is driven from Hoenn.",
    "Deoxys crashes on Birth Island and becomes dormant.",
    "Team Magma awakens Groudon.",
    "Team Aqua awakens Kyogre.",
    "Groudon and Kyogre clash.",
    "Sky Pillar is climbed.",
    "Rayquaza is absent.",
    "A lone Zoroark casts the Great Illusion.",
    "Hoenn's humans evacuate.",
    "Zoroark fades permanently into the illusion.",
    "The Pokémon remain.",
    "Ten years pass.",
    "Zorua's journey begins.",
)
SUPERSEDED_PATTERNS = {
    "living or fading elder Zoroark": re.compile(
        r"\b(?:living|fading)\s+elder\s+zoroark\b|\belder\s+zoroark\s+(?:raises|instructs)",
        re.IGNORECASE,
    ),
    "evolution lifting the veil": re.compile(
        r"\bevol(?:ution|ves?|ving)\b.{0,48}\b(?:lift(?:s|ed|ing)?|lifting)\b.{0,24}\bveil\b|"
        r"\bveil\b.{0,48}\b(?:when|after|because)\b.{0,48}\bevol",
        re.IGNORECASE,
    ),
    "all trainers returning": re.compile(
        r"\b(?:all|every)\s+trainers?\s+(?:return|returns|returning|came home|come home)",
        re.IGNORECASE,
    ),
    "mandatory Machop battle": re.compile(
        r"\bmachop\b.{0,48}\bmandatory\s+battle\b|\bmandatory\s+battle\b.{0,48}\bmachop\b",
        re.IGNORECASE,
    ),
    "ordinary capture availability": re.compile(
        r"\b(?:ordinary\s+)?captur(?:e|ing)\s+(?:is\s+)?(?:available|allowed|part of the game loop)",
        re.IGNORECASE,
    ),
}


def validate_structure() -> list[str]:
    errors = []
    if not STORY.is_dir():
        return ["missing Story/ directory"]
    actual = {entry.name for entry in STORY.iterdir()}
    expected = set(EXPECTED_FILES)
    if actual != expected:
        missing = sorted(expected - actual)
        unexpected = sorted(actual - expected)
        if missing:
            errors.append(f"Story/: missing files: {', '.join(missing)}")
        if unexpected:
            errors.append(f"Story/: unexpected entries: {', '.join(unexpected)}")
    for name in EXPECTED_FILES:
        path = STORY / name
        if not path.is_file():
            if path.exists():
                errors.append(f"Story/{name}: must be a regular file")
            continue
        text = path.read_text(encoding="utf-8")
        positions = []
        for heading in REQUIRED_HEADINGS:
            match = re.search(rf"^## {re.escape(heading)}\s*$", text, re.MULTILINE)
            if match is None:
                errors.append(f"Story/{name}: missing heading {heading!r}")
                break
            positions.append(match.start())
        else:
            if positions != sorted(positions):
                errors.append(f"Story/{name}: headings are not in required order")
            future = text[text.index("## Future Expansion") + len("## Future Expansion"):]
            if not re.search(r"\b(?:Open Question|Proposal)\b", future, re.IGNORECASE):
                errors.append(f"Story/{name}: Future Expansion must label a Proposal or Open Question")
    return errors


def validate_timeline() -> list[str]:
    path = STORY / "01 - Timeline.md"
    if not path.is_file():
        return []
    events = []
    for line in path.read_text(encoding="utf-8").splitlines():
        match = re.fullmatch(r"(\d+)\. (.+)", line)
        if match:
            events.append((int(match.group(1)), match.group(2)))
    if events != list(enumerate(LOCKED_TIMELINE, start=1)):
        return ["Story/01 - Timeline.md: events must exactly match the 16 locked canonical events"]
    return []


def validate_locked_canon() -> list[str]:
    path = STORY / "02 - Locked Canon.md"
    if not path.is_file():
        return []
    text = path.read_text(encoding="utf-8")
    required = (
        "Authority source order is: (1) the approved Story Handoff; (2) the relevant",
        "canonical Spec v0.2 sections when they do not conflict with that Handoff; (3)",
        "the repository implementation state for what is currently built; and (4)",
        "Proposals and Open Questions, which are non-canon.",
        "There is no villain.",
        "only mandatory battle is Zorua versus Deoxys",
        "restored bonds are sufficient for the veil to lift",
        "Evolution is neither an epilogue prerequisite nor the cause",
        "some trainers come home",
        "Capturing Pokémon is not part of the game loop",
    )
    return [
        f"Story/02 - Locked Canon.md: missing canonical statement {fragment!r}"
        for fragment in required
        if fragment not in text
    ]


def validate_changelog() -> list[str]:
    path = STORY / "07 - Changelog.md"
    if not path.is_file():
        return []
    text = path.read_text(encoding="utf-8")
    rulings = re.findall(
        r"^\*\*2026-07-19 — Ruling [1-7]: .*$",
        text,
        re.MULTILINE,
    )
    if len(rulings) != 7:
        return ["Story/07 - Changelog.md: expected seven dated rulings"]
    return [
        "Story/07 - Changelog.md: every dated ruling must identify superseded material"
        for ruling in rulings
        if "**Supersedes:**" not in ruling
    ]


def validate_open_questions() -> list[str]:
    path = STORY / "06 - Open Questions.md"
    if not path.is_file():
        return []
    required = "**Open Question — Lab context:** who used the lab, and how is history presented there?"
    if required not in path.read_text(encoding="utf-8"):
        return ["Story/06 - Open Questions.md: missing labeled unresolved Lab context"]
    return []


def validate_superseded_claims() -> list[str]:
    errors = []
    for name in EXPECTED_FILES:
        path = STORY / name
        if not path.is_file():
            continue
        text = path.read_text(encoding="utf-8")
        for claim, pattern in SUPERSEDED_PATTERNS.items():
            match = pattern.search(text)
            if match:
                errors.append(f"Story/{name}: superseded claim ({claim}): {match.group(0)!r}")
    return errors


def main() -> int:
    errors = (
        validate_structure()
        + validate_timeline()
        + validate_locked_canon()
        + validate_changelog()
        + validate_open_questions()
        + validate_superseded_claims()
    )
    if errors:
        for message in errors:
            print(f"validate_story_docs: {message}", file=sys.stderr)
        return 1
    print("validate_story_docs: canonical Story structure, timeline, and canon scan pass")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
