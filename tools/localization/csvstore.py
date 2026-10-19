"""Reading and writing translation CSV files.

Columns are addressed by header name, so their order is free. New files use
key,context,max_width,<languages...>,status.
"""

import csv
import io
import os

BASE_COLUMNS = ["key", "context", "max_width"]
TRAILING_COLUMNS = ["status"]


def default_header(languages):
    return BASE_COLUMNS + list(languages) + TRAILING_COLUMNS


class CsvError(Exception):
    pass


def read_csv(path):
    """Returns (header, rows) where rows are dicts. Missing file -> (None, [])."""
    if not os.path.exists(path):
        return None, []
    with open(path, encoding="utf-8", newline="") as f:
        reader = csv.reader(f)
        try:
            header = next(reader)
        except StopIteration:
            return None, []
        if header and header[0].startswith("﻿"):
            header[0] = header[0][1:]
        if "key" not in header:
            raise CsvError(f"{path}: missing 'key' column")
        rows = []
        for lineno, rec in enumerate(reader, 2):
            if not any(rec):
                continue
            if len(rec) > len(header):
                raise CsvError(f"{path}:{lineno}: row has more cells than the header (unquoted comma?)")
            row = {h: (rec[i] if i < len(rec) else "") for i, h in enumerate(header)}
            row["_line"] = lineno
            rows.append(row)
    return header, rows


def render_csv(header, rows):
    buf = io.StringIO()
    writer = csv.writer(buf, lineterminator="\n")
    writer.writerow(header)
    for row in rows:
        writer.writerow([row.get(h, "") for h in header])
    return buf.getvalue()


def write_if_changed(path, content):
    """Writes text content, keeping the mtime when nothing changed."""
    if os.path.exists(path):
        with open(path, encoding="utf-8", newline="") as f:
            if f.read() == content:
                return False
    os.makedirs(os.path.dirname(path) or ".", exist_ok=True)
    with open(path, "w", encoding="utf-8", newline="") as f:
        f.write(content)
    return True


def ensure_languages(header, languages):
    """Adds missing language columns before 'status'."""
    header = list(header)
    for lang in languages:
        if lang not in header:
            idx = header.index("status") if "status" in header else len(header)
            header.insert(idx, lang)
    for col in BASE_COLUMNS + TRAILING_COLUMNS:
        if col not in header:
            header.append(col) if col == "status" else header.insert(BASE_COLUMNS.index(col), col)
    return header


def parse_status(status):
    """'stale:es,pt;obsolete' -> {'stale': {'es','pt'}, 'obsolete': set()}"""
    out = {}
    for part in filter(None, (p.strip() for p in (status or "").split(";"))):
        name, _, langs = part.partition(":")
        out[name] = set(filter(None, langs.split(",")))
    return out


def format_status(status):
    parts = []
    for name in sorted(status):
        langs = status[name]
        parts.append(f"{name}:{','.join(sorted(langs))}" if langs else name)
    return ";".join(parts)
