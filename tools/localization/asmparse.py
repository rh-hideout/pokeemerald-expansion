"""Extracts localizable text units from assembly sources (.s / .inc).

A unit is a label followed by consecutive `.string` lines:

    PetalburgCity_Text_AreYouATrainer:
        .string "Excuse me!\\p"
        .string "Let me guess...$"

The unit's key is the label and its text is the concatenation of the pieces
with the trailing `$` terminator removed (it is re-added on generation).
"""

import re
from dataclasses import dataclass

LABEL_RE = re.compile(r"^([A-Za-z_.][\w.]*)(::?)")
STRING_RE = re.compile(r'^[ \t]*\.string[ \t]+"((?:[^"\\]|\\.)*)"[ \t]*(?:,[ \t]*(\w+))?[ \t]*$')


@dataclass
class AsmUnit:
    key: str
    lines: list            # source line numbers of each .string piece
    pieces: list           # raw contents of each piece
    pad: object = None     # pad length if the unit is one padded piece
    terminated: bool = True

    @property
    def text(self):
        t = "".join(self.pieces)
        if self.terminated:
            t = t[:-1]
        return t

    @property
    def line(self):
        return self.lines[0]


@dataclass
class Skipped:
    line: int
    reason: str


def strip_comments(src):
    """Mirrors AsmFile::RemoveComments, keeping newlines."""
    out = []
    i = 0
    n = len(src)
    string_char = None
    while i < n:
        c = src[i]
        if string_char:
            if c == "\\" and i + 1 < n and src[i + 1] == string_char:
                out.append(src[i:i + 2])
                i += 2
                continue
            if c == string_char:
                string_char = None
            out.append(c)
            i += 1
        elif c == "@" and (i == 0 or src[i - 1] != "\\"):
            while i < n and src[i] != "\n":
                out.append(" ")
                i += 1
        elif src.startswith("/*", i):
            end = src.find("*/", i + 2)
            end = n if end < 0 else end + 2
            out.append("".join("\n" if ch == "\n" else " " for ch in src[i:end]))
            i = end
        else:
            if c in "\"'":
                string_char = c
            out.append(c)
            i += 1
    return "".join(out)


def parse_asm(src):
    lines = strip_comments(src).split("\n")
    units = []
    skipped = []
    label = None
    label_count = {}
    cur = None

    def finish():
        nonlocal cur
        if cur is None:
            return
        u = cur
        cur = None
        if any(p is not None for p in u["pads"]):
            if len(u["pieces"]) != 1:
                skipped.append(Skipped(u["lines"][0], "padded .string in a multi-line unit"))
                return
        pad = u["pads"][0]
        joined = "".join(u["pieces"])
        terminated = joined.endswith("$") and not joined.endswith("\\$")
        units.append(AsmUnit(key=u["key"], lines=u["lines"], pieces=u["pieces"],
                             pad=pad, terminated=terminated))

    for idx, line in enumerate(lines, 1):
        m = STRING_RE.match(line)
        if m:
            if cur is None:
                base = label or "_anon"
                n = label_count.get(base, 0) + 1
                label_count[base] = n
                key = base if n == 1 else f"{base}#{n}"
                cur = {"key": key, "lines": [], "pieces": [], "pads": []}
            cur["lines"].append(idx)
            cur["pieces"].append(m.group(1))
            cur["pads"].append(m.group(2))
            continue
        finish()
        stripped = line.strip()
        if not stripped:
            continue
        lm = LABEL_RE.match(line)
        if lm and not stripped.startswith("."):
            label = lm.group(1)
            continue
        if re.match(r"^\s*\.string\b", line):
            skipped.append(Skipped(idx, "unparsable .string line"))
    finish()
    return units, skipped
