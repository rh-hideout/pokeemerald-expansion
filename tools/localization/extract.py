"""Scans the game's sources for text units and keeps the CSV files in sync."""

import difflib
import os
import pickle
import re
from dataclasses import dataclass, field

import asmparse
import cparse
import csvstore
from project import TEXT_DIR

CACHE_VERSION = 3


@dataclass
class Unit:
    file: str
    key: str
    text: str                  # source-language text (source syntax)
    kind: str                  # "c" or "asm"
    line: int
    macro: str = ""            # C: _, __, COMPOUND_STRING or string macro
    lines: list = field(default_factory=list)   # asm: line of each piece
    pieces: list = field(default_factory=list)  # asm: raw piece contents
    pad: object = None         # asm: pad length of a single padded piece
    terminated: bool = False   # asm: text ended with '$'
    max_bytes_expr: object = None
    origin: str = ""           # file that was scanned (differs from 'file' after #line)

    @property
    def adds_terminator(self):
        return self.kind == "c" and self.macro != "__"


@dataclass
class FileScan:
    units: list
    skipped: list   # [(line, reason)]


_CJK_RE = re.compile(r"[぀-ヿ一-鿿＀-￯]")
_BRACES_RE = re.compile(r"\{[^}]*\}|\\.")


def is_translatable(text):
    """Skips strings with no letters (numbers, symbols, pure placeholders)
    and Japanese-only data."""
    if _CJK_RE.search(text):
        return False
    bare = _BRACES_RE.sub("", text)
    return any(c.isalpha() for c in bare)


def scan_file(project, kind, rel):
    with open(project.path(rel), encoding="utf-8", errors="strict") as f:
        src = f.read()
    units = []
    skipped = []
    if kind == "c":
        macros = project.rules.get("string_macros", {})
        strings, skips = cparse.parse_c(src, list(macros))
        skipped += [(s.line, s.reason) for s in skips]
        for s in strings:
            expr = None
            if s.kind in macros:
                expr = macros[s.kind].get("max_bytes")
            elif s.max_bytes:
                expr = s.max_bytes
            elif s.field_name:
                expr = project.struct_fields.get(s.field_name)
            units.append(Unit(file=s.file or rel, key=s.key, text=s.text, kind="c", line=s.line,
                              macro=s.kind, max_bytes_expr=expr, origin=rel))
    else:
        asm_units, skips = asmparse.parse_asm(src)
        skipped += [(s.line, s.reason) for s in skips]
        for u in asm_units:
            pad = u.pad
            if pad is not None:
                try:
                    pad = int(pad, 0)
                except ValueError:
                    skipped.append((u.line, f"symbolic .string padding '{pad}'"))
                    continue
            units.append(Unit(file=rel, key=u.key, text=u.text, kind="asm", line=u.line,
                              lines=u.lines, pieces=u.pieces, pad=pad, terminated=u.terminated, origin=rel))
    kept = []
    for u in units:
        override = project.buffer_rule(u.file, u.key)
        if override is not None:
            u.max_bytes_expr = override
        if not is_translatable(u.text):
            continue
        if project.skip_unit(u.file, u.key):
            continue
        kept.append(u)
    return FileScan(kept, skipped)


def scan_all(project, cache_path=None, quiet=True):
    """Returns {source_rel: FileScan}, using an mtime cache when possible."""
    cache = {}
    # Invalidate on rules or parser changes too.
    tool_dir = os.path.dirname(os.path.abspath(__file__))
    rules_mtime = (os.stat(project.path("localization", "rules.json")).st_mtime_ns,
                   max(os.stat(os.path.join(tool_dir, f)).st_mtime_ns
                       for f in os.listdir(tool_dir) if f.endswith(".py")))
    if cache_path and os.path.exists(cache_path):
        try:
            with open(cache_path, "rb") as f:
                data = pickle.load(f)
            if data.get("version") == CACHE_VERSION and data.get("rules") == rules_mtime:
                cache = data["files"]
        except Exception:
            cache = {}
    result = {}
    new_cache = {}
    for kind, rel in project.source_files():
        st = os.stat(project.path(rel))
        stamp = (st.st_mtime_ns, st.st_size)
        hit = cache.get(rel)
        if hit and hit[0] == stamp:
            scan = hit[1]
        else:
            scan = scan_file(project, kind, rel)
        new_cache[rel] = (stamp, scan)
        # Units are grouped by the file they belong to, which #line can
        # make different from the scanned file (e.g. trainers.party).
        if scan.skipped:
            result.setdefault(rel, FileScan([], [])).skipped.extend(scan.skipped)
        for u in scan.units:
            result.setdefault(u.file, FileScan([], [])).units.append(u)
    if cache_path:
        os.makedirs(os.path.dirname(cache_path), exist_ok=True)
        tmp = cache_path + ".tmp"
        with open(tmp, "wb") as f:
            pickle.dump({"version": CACHE_VERSION, "rules": rules_mtime, "files": new_cache}, f)
        os.replace(tmp, cache_path)
    return result


# ----------------------------------------------------------------------------
# CSV synchronisation

def update_csv(project, rel, units, prune=False):
    """Brings the CSV for 'rel' in line with the current source units.

    Returns a dict of counters describing what changed."""
    path = project.path(project.csv_path(rel))
    header, rows = csvstore.read_csv(path)
    langs = list(project.languages)
    header = csvstore.ensure_languages(header or csvstore.default_header(langs), langs)
    src = project.source_language
    old = {r["key"]: r for r in rows}
    stats = {"added": 0, "changed": 0, "carried": 0, "obsolete": 0, "removed": 0}
    out = []
    seen = set()
    added = []
    for u in units:
        seen.add(u.key)
        row = old.get(u.key)
        if row is None:
            row = {h: "" for h in header}
            row["key"] = u.key
            row[src] = u.text
            stats["added"] += 1
            added.append(row)
        else:
            row = dict(row)
            status = csvstore.parse_status(row.get("status"))
            status.pop("obsolete", None)
            if row.get(src, "") != u.text:
                stale = {l for l in project.target_languages if row.get(l)}
                if stale:
                    status.setdefault("stale", set()).update(stale)
                row[src] = u.text
                stats["changed"] += 1
            row["status"] = csvstore.format_status(status)
        out.append(row)
    leftovers = [r for r in rows if r["key"] not in seen
                 and any(r.get(l) for l in project.target_languages)]
    carried = carry_translations(project, added, leftovers)
    stats["carried"] = len(carried)
    for row in rows:
        if row["key"] in seen or row["key"] in carried:
            continue
        has_translation = any(row.get(l) for l in project.target_languages)
        if prune or not has_translation:
            stats["removed"] += 1
            continue
        row = dict(row)
        status = csvstore.parse_status(row.get("status"))
        if "obsolete" not in status:
            stats["obsolete"] += 1
        status["obsolete"] = set()
        row["status"] = csvstore.format_status(status)
        out.append(row)
    if not out:
        if os.path.exists(path):
            os.remove(path)
            return stats, True
        return stats, False
    changed = csvstore.write_if_changed(path, csvstore.render_csv(header, out))
    return stats, changed


_KEY_STEM_RE = re.compile(r"(@|/alt|~|#).*$")


def carry_translations(project, added, leftovers):
    """Moves translations from rows whose key disappeared onto new rows that
    are evidently the same string (renamed key, or edited text in the same
    function/field). Edited text is marked stale. Returns the keys of the
    leftover rows that were used."""
    src = project.source_language
    langs = project.target_languages
    candidates = []
    for new in added:
        for old in leftovers:
            new_text, old_text = new.get(src, ""), old.get(src, "")
            if new_text == old_text:
                score = 3.0
            else:
                ratio = difflib.SequenceMatcher(None, old_text, new_text).ratio()
                same_stem = _KEY_STEM_RE.sub("", new["key"]) == _KEY_STEM_RE.sub("", old["key"])
                if same_stem and ratio >= 0.5:
                    score = 2.0 + ratio
                elif ratio >= 0.8:
                    score = 1.0 + ratio
                else:
                    continue
            candidates.append((score, new["key"], old["key"], new, old))
    candidates.sort(key=lambda c: (-c[0], c[1], c[2]))
    used_new, used_old = set(), set()
    for score, new_key, old_key, new, old in candidates:
        if new_key in used_new or old_key in used_old:
            continue
        used_new.add(new_key)
        used_old.add(old_key)
        for col in ["context", "max_width"] + langs:
            if old.get(col):
                new[col] = old[col]
        if new.get(src, "") != old.get(src, ""):
            status = csvstore.parse_status(new.get("status"))
            status.setdefault("stale", set()).update(l for l in langs if old.get(l))
            new["status"] = csvstore.format_status(status)
        else:
            status = csvstore.parse_status(old.get("status"))
            status.pop("obsolete", None)
            new["status"] = csvstore.format_status(status)
    return used_old


def remove_orphan_csvs(project, scans):
    """Deletes CSVs whose source file vanished and that hold no translations."""
    removed = []
    base = project.path(TEXT_DIR)
    for dirpath, _, files in os.walk(base):
        for name in files:
            if not name.endswith(".csv"):
                continue
            full = os.path.join(dirpath, name)
            rel_src = os.path.relpath(full, base).replace(os.sep, "/")[:-4]
            if rel_src in scans:
                continue
            _, rows = csvstore.read_csv(full)
            if any(r.get(l) for r in rows for l in project.target_languages):
                continue
            os.remove(full)
            removed.append(rel_src)
    return removed
