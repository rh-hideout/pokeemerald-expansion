"""Game font metrics and glyphs, read from src/fonts.c and graphics/fonts.

Widths mirror GetStringWidth() in src/text.c, measured on source-syntax text
so placeholders can be given worst-case widths by name.
"""

import os
import re

import pngio
from charmap import tokenize

# Font constant -> (glyph width table in src/fonts.c, glyph sheet)
FONTS = {
    "FONT_SMALL": ("gFontSmallLatinGlyphWidths", "latin_small.png"),
    "FONT_NORMAL": ("gFontNormalLatinGlyphWidths", "latin_normal.png"),
    "FONT_SHORT": ("gFontShortLatinGlyphWidths", "latin_short.png"),
    "FONT_SHORT_COPY_1": ("gFontShortLatinGlyphWidths", "latin_short.png"),
    "FONT_SHORT_COPY_2": ("gFontShortLatinGlyphWidths", "latin_short.png"),
    "FONT_SHORT_COPY_3": ("gFontShortLatinGlyphWidths", "latin_short.png"),
    "FONT_NARROW": ("gFontNarrowLatinGlyphWidths", "latin_narrow.png"),
    "FONT_SMALL_NARROW": ("gFontSmallNarrowLatinGlyphWidths", "latin_small_narrow.png"),
    "FONT_NARROWER": ("gFontNarrowerLatinGlyphWidths", "latin_narrower.png"),
    "FONT_SMALL_NARROWER": ("gFontSmallNarrowerLatinGlyphWidths", "latin_small_narrower.png"),
    "FONT_SHORT_NARROW": ("gFontShortNarrowLatinGlyphWidths", "latin_short_narrow.png"),
    "FONT_SHORT_NARROWER": ("gFontShortNarrowerLatinGlyphWidths", "latin_short_narrower.png"),
}

# Font ids as used by {FONT n} / FC 06 n (include/text.h enum order).
FONT_IDS = [
    "FONT_SMALL", "FONT_NORMAL", "FONT_SHORT", "FONT_SHORT_COPY_1", "FONT_SHORT_COPY_2",
    "FONT_SHORT_COPY_3", "FONT_BRAILLE", "FONT_NARROW", "FONT_SMALL_NARROW", "FONT_BOLD",
    "FONT_NARROWER", "FONT_SMALL_NARROWER", "FONT_SHORT_NARROW", "FONT_SHORT_NARROWER",
]

EXT_CTRL = 0xFC
PLACEHOLDER = 0xFD
DYNAMIC = 0xF7
KEYPAD_ICON = 0xF8
EXTRA_SYMBOL = 0xF9
LINE_BREAKS = ("\\n", "\\l", "\\p")
GLYPH_CELL = 16


def parse_width_tables(fonts_c_path):
    with open(fonts_c_path, encoding="utf-8") as f:
        src = f.read()
    tables = {}
    for m in re.finditer(r"(\w+GlyphWidths)\[\]\s*=\s*\{(.*?)\};", src, re.S):
        body = re.sub(r"//[^\n]*|/\*.*?\*/", "", m.group(2), flags=re.S)
        tables[m.group(1)] = [int(x, 0) for x in re.findall(r"0x[0-9A-Fa-f]+|\d+", body)]
    return tables


class FontSet:
    def __init__(self, root, charmap, placeholder_chars=None):
        self.root = root
        self.charmap = charmap
        self.tables = parse_width_tables(os.path.join(root, "src", "fonts.c"))
        self.placeholder_chars = placeholder_chars or {}
        self._sheets = {}

    def widths(self, font):
        table_name = FONTS[font][0]
        return self.tables[table_name]

    def glyph_width(self, font, code):
        table = self.widths(font)
        return table[code] if code < len(table) else 0

    def max_letter_width(self, font):
        letters = [self.glyph_width(font, self.charmap.chars[c][0])
                   for c in "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
                   if c in self.charmap.chars]
        return max(letters) if letters else 8

    def placeholder_width(self, font, name):
        chars = self.placeholder_chars.get(name, self.placeholder_chars.get("default", 10))
        return chars * self.max_letter_width(font)

    # ------------------------------------------------------------------
    def line_widths(self, text, font):
        """Returns [(line_text, width_px)] for each line of 'text'.

        Lines are split on \\n, \\l and \\p. Unknown characters are ignored
        (character set validation reports them separately)."""
        lines = []
        cur_font = font
        width = 0
        toks = tokenize(text)
        pieces = []
        for tok in toks:
            if tok in LINE_BREAKS:
                lines.append(("".join(pieces), width))
                pieces = []
                width = 0
                continue
            pieces.append(tok)
            if tok.startswith("{") and tok.endswith("}"):
                width, cur_font = self._brace_width(tok, width, cur_font)
            elif tok.startswith("\\"):
                continue
            else:
                seq = self.charmap.chars.get(tok)
                if not seq:
                    continue
                for b in seq:
                    width += self.glyph_width(cur_font, b)
        lines.append(("".join(pieces), width))
        return lines

    def _brace_width(self, tok, width, font):
        parts = tok[1:-1].split()
        if not parts:
            return width, font
        name = parts[0]
        seq = self.charmap.constants.get(name)
        if name in FONTS:
            return width, name
        if seq is None:
            return width, font
        if seq[0] == EXT_CTRL and len(seq) >= 2:
            code = seq[1]
            arg = _int_arg(parts[1]) if len(parts) > 1 else (seq[2] if len(seq) > 2 else None)
            if code == 0x06 and arg is not None and arg < len(FONT_IDS) and FONT_IDS[arg] in FONTS:
                return width, FONT_IDS[arg]
            if code == 0x11 and arg is not None:      # CLEAR
                return width + arg, font
            if code == 0x12 and arg is not None:      # SKIP
                return arg, font
            if code == 0x13 and arg is not None:      # CLEAR_TO
                return max(width, arg), font
            return width, font
        if seq[0] in (PLACEHOLDER, DYNAMIC):
            return width + self.placeholder_width(font, name), font
        if seq[0] in (KEYPAD_ICON, EXTRA_SYMBOL):
            return width + 8, font
        for b in seq:
            width += self.glyph_width(font, b)
        return width, font

    # ------------------------------------------------------------------
    def sheet(self, font):
        name = FONTS[font][1]
        if name not in self._sheets:
            self._sheets[name] = pngio.read_png(os.path.join(self.root, "graphics", "fonts", name))
        return self._sheets[name]

    def glyph_pixels(self, font, code):
        """Returns the 16x16 cell of glyph 'code' as rows of palette indices."""
        img = self.sheet(font)
        cols = img.width // GLYPH_CELL
        cx = (code % cols) * GLYPH_CELL
        cy = (code // cols) * GLYPH_CELL
        return [img.pixels[cy + y][cx:cx + GLYPH_CELL] for y in range(GLYPH_CELL)]


def _int_arg(text):
    try:
        return int(text, 0)
    except ValueError:
        return None
