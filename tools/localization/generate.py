"""Generates the per-language build inputs from the CSV files.

Output layout (build/loc/<lang>/):
    strings/<source path>.tbl   replacement tables read by preproc (-t)
    gfx/<path>.png              graphics overlay read by preproc/scaninc (-L)
    overlay.stamp               lists the files above; rewritten only when the
                                set changes so make re-scans dependencies
    report.txt                  diagnostics and coverage of the last run
"""

import os
from collections import defaultdict

import csvstore
import gfx
from charmap import fnv1a64
from extract import scan_all
from validate import Validator


class Result:
    def __init__(self):
        self.total = 0
        self.translated = 0
        self.missing = []
        self.tables = []
        self.graphics = []


def unit_limits(project, unit, row):
    """Returns ([(font, max_width)], max_lines, max_bytes) for a unit."""
    rule = project.text_rule(unit.file, unit.key)
    checks = [(c["font"], c.get("max_width")) for c in rule["checks"]]
    if rule.get("font"):
        checks.insert(0, (rule["font"], rule.get("max_width")))
    if row.get("max_width"):
        try:
            checks = [(checks[0][0] if checks else "FONT_NORMAL", int(row["max_width"]))]
        except ValueError:
            pass
    max_bytes = project.eval_expr(unit.max_bytes_expr) if unit.max_bytes_expr else None
    return checks, rule.get("max_lines"), max_bytes


def build_entries(project, charmap, unit, translated):
    """Returns table lines for one translated unit."""
    if unit.kind == "c":
        orig = charmap.encode(unit.text)
        return [("C", unit.line, fnv1a64(orig), translated)]
    entries = []
    full = translated + (b"\xff" if unit.terminated else b"")
    if unit.pad is not None:
        full = full + b"\x00" * max(0, unit.pad - len(full))
    for i, (line, piece) in enumerate(zip(unit.lines, unit.pieces)):
        orig = charmap.encode(piece)
        if unit.pad is not None:
            orig = orig + b"\x00" * max(0, unit.pad - len(orig))
        entries.append(("S", line, fnv1a64(orig), full if i == 0 else None))
    return entries


def format_entry(kind, line, h, data):
    hexdata = "-" if not data else data.hex().upper()
    return f"{kind} {line} {h:016x} {hexdata}\n"


def generate(project, charmap, fonts, lang, out_dir, strict=False, scans=None):
    validator = Validator(project, charmap, fonts)
    result = Result()
    src_lang = project.source_language
    if scans is None:
        scans = scan_all(project, cache_path=os.path.join(out_dir, "..", "scan_cache.pickle"))
    tables = {}

    for rel, scan in sorted(scans.items()):
        if not scan.units:
            continue
        csv_rel = project.csv_path(rel)
        try:
            header, rows = csvstore.read_csv(project.path(csv_rel))
        except csvstore.CsvError as e:
            validator.error(csv_rel, "-", lang, str(e))
            continue
        result.total += len(scan.units)
        if header is None:
            result.missing.extend((rel, u.key) for u in scan.units)
            continue
        if lang not in header:
            validator.warn(csv_rel, "-", lang, f"no '{lang}' column (run: make loc-seed LANG={lang})")
            result.missing.extend((rel, u.key) for u in scan.units)
            continue
        by_key = {}
        for row in rows:
            if row["key"] in by_key:
                validator.error(f"{csv_rel}:{row['_line']}", row["key"], "", "duplicate key")
            by_key[row["key"]] = row
        units_by_key = {u.key: u for u in scan.units}
        for row in rows:
            status = csvstore.parse_status(row.get("status"))
            if row["key"] not in units_by_key and "obsolete" not in status and row.get(lang):
                validator.warn(f"{csv_rel}:{row['_line']}", row["key"], lang,
                               "key no longer exists in the source (run: make loc-extract)")

        entries = []
        translated_hashes = set()
        c_units_by_hash = defaultdict(list)
        for u in scan.units:
            if u.kind == "c":
                c_units_by_hash[fnv1a64(charmap.encode(u.text))].append(u)
            row = by_key.get(u.key)
            text = row.get(lang, "") if row else ""
            if not text or lang == src_lang:
                if lang != src_lang:
                    result.missing.append((rel, u.key))
                continue
            where = f"{csv_rel}:{row['_line']}"
            status = csvstore.parse_status(row.get("status"))
            if row.get(src_lang, "") != u.text:
                (validator.error if strict else validator.warn)(
                    where, u.key, lang,
                    "source text changed since the CSV was updated (run: make loc-extract, then review)")
            if lang in status.get("stale", set()):
                (validator.error if strict else validator.warn)(
                    where, u.key, lang, "translation is marked stale; review it and clear the status column")
            checks, max_lines, max_bytes = unit_limits(project, u, row)
            encoded = validator.check_text(where, u.key, lang, text, u.text, unit=u, checks=checks,
                                           max_lines=max_lines, max_bytes=max_bytes, pad=u.pad)
            if encoded is None:
                continue
            result.translated += 1
            entries.extend(build_entries(project, charmap, u, encoded))
            if u.kind == "c":
                translated_hashes.add(fnv1a64(charmap.encode(u.text)))

        # Identical source strings in the same file are told apart by line;
        # give untranslated twins an identity entry so they keep their text.
        translated_lines = {(e[0], e[1]) for e in entries}
        for h in translated_hashes:
            for u in c_units_by_hash[h]:
                if ("C", u.line) not in translated_lines:
                    entries.append(("C", u.line, h, charmap.encode(u.text)))
        if entries:
            entries.sort(key=lambda e: (e[1], e[0]))
            tables[rel] = "".join(format_entry(*e) for e in entries)
            # preproc looks tables up by the #line file, scaninc by the file
            # it scans: give generated headers a copy so edits still rebuild.
            for origin in {u.origin for u in scan.units if u.origin and u.origin != rel}:
                tables[origin] = f"# Copy of {rel}.tbl (generated from it via #line)\n" + tables[rel]

    # Write tables, removing stale ones.
    strings_dir = os.path.join(out_dir, "strings")
    keep = set()
    for rel, content in tables.items():
        path = os.path.join(strings_dir, rel + ".tbl")
        csvstore.write_if_changed(path, content)
        keep.add(os.path.normpath(path))
        result.tables.append(rel)
    if os.path.isdir(strings_dir):
        for dirpath, _, files in os.walk(strings_dir):
            for name in files:
                full = os.path.normpath(os.path.join(dirpath, name))
                if full not in keep:
                    os.remove(full)

    # Graphics overlay.
    result.graphics = gfx.build_overlay(project, lang, fonts, charmap, validator, os.path.join(out_dir, "gfx"))

    if result.missing and lang != src_lang:
        if strict:
            for rel, key in result.missing:
                validator.error(project.csv_path(rel), key, lang, "missing translation")

    # Stamp: changes when the set of tables/overlay files changes.
    stamp = "".join(f"strings/{t}.tbl\n" for t in sorted(result.tables))
    stamp += "".join(f"gfx/{g}\n" for g in result.graphics)
    csvstore.write_if_changed(os.path.join(out_dir, "overlay.stamp"), stamp)
    return result, validator
