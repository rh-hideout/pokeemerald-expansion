#!/usr/bin/env python3
"""Adds composed accented glyphs to the latin fonts (one-time, idempotent).

Portuguese needs ã õ Ã Õ, which the Gen 3 character set lacks. For every
latin font this draws each new glyph as its base letter plus the tilde taken
from ñ / Ñ (the rows where ñ differs from n), writes it into a free glyph
cell, copies the base letter's width into src/fonts.c, and maps the
character in charmap.txt.

    python3 tools/localization/compose_glyphs.py
"""

import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

import pngio  # noqa: E402
from charmap import Charmap  # noqa: E402
from fonts import FONTS, GLYPH_CELL, parse_width_tables  # noqa: E402
from project import ROOT  # noqa: E402

# new char -> (code, base letter, letter carrying the same accent, its plain twin)
GLYPHS = {
    "Ã": (0x0A, "A", "Ñ", "N"),
    "ã": (0x18, "a", "ñ", "n"),
    "Õ": (0x1F, "O", "Ñ", "N"),
    "õ": (0x2F, "o", "ñ", "n"),
}

BLANK = (0, 3)   # outside the glyph / glyph background


def cell(img, code):
    cols = img.width // GLYPH_CELL
    x0 = (code % cols) * GLYPH_CELL
    y0 = (code // cols) * GLYPH_CELL
    return x0, y0


def get_glyph(img, code):
    x0, y0 = cell(img, code)
    return [img.pixels[y0 + y][x0:x0 + GLYPH_CELL] for y in range(GLYPH_CELL)]


def put_glyph(img, code, glyph):
    x0, y0 = cell(img, code)
    for y in range(GLYPH_CELL):
        img.pixels[y0 + y][x0:x0 + GLYPH_CELL] = glyph[y]


def accent_mask(accented, plain, width):
    """Pixels of 'accented' that 'plain' doesn't have (the accent), as
    (y, x, value), x relative to the accent's own left edge."""
    pixels = []
    for y in range(GLYPH_CELL):
        for x in range(width):
            a = accented[y][x]
            if a not in BLANK and plain[y][x] in BLANK:
                pixels.append((y, x, a))
    return pixels


def compose(img, widths, cm, base, accented_ch, plain_ch):
    b = cm.chars[base][0]
    a = cm.chars[accented_ch][0]
    p = cm.chars[plain_ch][0]
    base_w = widths[b]
    acc_w = widths[a]
    glyph = [list(r) for r in get_glyph(img, b)]
    accent = accent_mask(get_glyph(img, a), get_glyph(img, p), acc_w)
    if not accent:
        raise SystemExit(f"no accent found in '{accented_ch}'")
    # Center the accent over the base letter.
    acc_left = min(x for _, x, _ in accent)
    acc_right = max(x for _, x, _ in accent)
    base_cols = [x for y in range(GLYPH_CELL) for x in range(base_w) if glyph[y][x] not in BLANK]
    base_left, base_right = (min(base_cols), max(base_cols)) if base_cols else (0, base_w - 1)
    shift = (base_left + base_right - acc_left - acc_right) // 2
    for y, x, v in accent:
        nx = x + shift
        if 0 <= nx < base_w:
            glyph[y][nx] = v
    return glyph, base_w


def set_width(fonts_c, table, code, width):
    m = re.search(re.escape(table) + r"\[\]\s*=\s*\{", fonts_c)
    pos = m.end()
    for i, num in enumerate(re.finditer(r"\d+", fonts_c[pos:])):
        if i == code:
            start = pos + num.start()
            end = pos + num.end()
            return fonts_c[:start] + str(width).rjust(end - start) + fonts_c[end:]
    raise SystemExit(f"{table} is shorter than {code}")


def main():
    charmap_path = os.path.join(ROOT, "charmap.txt")
    fonts_c_path = os.path.join(ROOT, "src", "fonts.c")
    cm = Charmap(charmap_path)
    tables = parse_width_tables(fonts_c_path)
    with open(fonts_c_path, encoding="utf-8") as f:
        fonts_c = f.read()

    # Fonts with their own glyph sheet (the SHORT copies share one).
    sheets = {}
    for font, (table, sheet) in FONTS.items():
        sheets.setdefault(sheet, table)

    for sheet, table in sorted(sheets.items()):
        path = os.path.join(ROOT, "graphics", "fonts", sheet)
        img = pngio.read_png(path)
        widths = tables[table]
        for ch, (code, base, acc, plain) in GLYPHS.items():
            existing = cm.chars.get(ch)
            if existing and existing != bytes([code]):
                raise SystemExit(f"'{ch}' is already mapped to {existing.hex()} in charmap.txt")
            mapped = {k for k, v in cm.chars.items() if v == bytes([code])
                      and not re.match(r"[぀-ヿ]", k)}
            if mapped - {ch}:
                raise SystemExit(f"code {code:#04x} is already used by {mapped}")
            glyph, width = compose(img, widths, cm, base, acc, plain)
            put_glyph(img, code, glyph)
            fonts_c = set_width(fonts_c, table, code, width)
        pngio.write_png(path, img)
        print(f"updated {os.path.relpath(path, ROOT)}")

    with open(fonts_c_path, "w", encoding="utf-8") as f:
        f.write(fonts_c)

    with open(charmap_path, encoding="utf-8") as f:
        charmap_text = f.read()
    added = []
    for ch, (code, *_rest) in GLYPHS.items():
        if ch not in cm.chars:
            added.append(f"'{ch}'         = {code:02X}\n")
    if added:
        anchor = "'ª'         = 2B\n"
        if anchor not in charmap_text:
            raise SystemExit("could not find where to add the new characters in charmap.txt")
        charmap_text = charmap_text.replace(
            anchor, anchor + "@ Composed for Portuguese by tools/localization/compose_glyphs.py\n" + "".join(added))
        with open(charmap_path, "w", encoding="utf-8") as f:
            f.write(charmap_text)
        print(f"mapped {', '.join(a.split()[0] for a in added)} in charmap.txt")


if __name__ == "__main__":
    main()
