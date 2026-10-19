"""Build-time validation of translations.

Checks: character set, placeholders and control codes, line commands,
pixel width per line, lines per page, and fixed-length buffers.
"""

from collections import Counter
from dataclasses import dataclass

from charmap import EncodeError, tokenize

LINE_BREAKS = ("\\n", "\\l", "\\p")


@dataclass
class Diagnostic:
    level: str      # "error" or "warning"
    where: str      # "path/to/file.csv:LINE"
    key: str
    lang: str
    message: str

    def format(self):
        lang = f" [{self.lang}]" if self.lang else ""
        return f"{self.where}: {self.level}: {self.key}{lang}: {self.message}"


class Validator:
    def __init__(self, project, charmap, fonts):
        self.project = project
        self.charmap = charmap
        self.fonts = fonts
        self.diagnostics = []

    def error(self, where, key, lang, message):
        self.diagnostics.append(Diagnostic("error", where, key, lang, message))

    def warn(self, where, key, lang, message):
        self.diagnostics.append(Diagnostic("warning", where, key, lang, message))

    @property
    def errors(self):
        return [d for d in self.diagnostics if d.level == "error"]

    @property
    def warnings(self):
        return [d for d in self.diagnostics if d.level == "warning"]

    # ------------------------------------------------------------------
    def classify_braces(self, text):
        """Returns (placeholders Counter, control codes Counter)."""
        placeholders = Counter()
        controls = Counter()
        for tok in tokenize(text):
            if not (tok.startswith("{") and tok.endswith("}")):
                continue
            parts = tok[1:-1].split()
            seq = self.charmap.constants.get(parts[0]) if parts else None
            norm = "{" + " ".join(parts) + "}"
            if seq and seq[0] in (0xFD, 0xF7):
                placeholders[norm] += 1
            else:
                controls[norm] += 1
        return placeholders, controls

    def check_text(self, where, key, lang, text, source_text, unit=None, checks=(),
                   max_lines=None, max_bytes=None, pad=None):
        """'checks' is a list of (font, max_width) pairs."""
        """Validates one translation. Returns the encoded bytes or None."""
        ok = True
        if "\n" in text or "\r" in text:
            self.error(where, key, lang, "contains a literal line break; use \\n (new line), \\l (scroll) or \\p (new page)")
            return None
        if text != text.strip(" ") and source_text == source_text.strip(" "):
            self.warn(where, key, lang, "has leading/trailing spaces")

        # Character set
        try:
            encoded = self.charmap.encode(text)
        except EncodeError as e:
            self.error(where, key, lang, f"{e} (at column {e.pos + 1 if e.pos is not None else '?'})")
            return None

        # Placeholders / control codes
        src_ph, src_ctrl = self.classify_braces(source_text)
        tr_ph, tr_ctrl = self.classify_braces(text)
        if src_ph != tr_ph:
            missing = src_ph - tr_ph
            extra = tr_ph - src_ph
            parts = []
            if missing:
                parts.append("missing " + ", ".join(sorted(missing.elements())))
            if extra:
                parts.append("unexpected " + ", ".join(sorted(extra.elements())))
            self.error(where, key, lang, "placeholders differ from the source text: " + "; ".join(parts))
            ok = False
        if src_ctrl != tr_ctrl:
            missing = src_ctrl - tr_ctrl
            extra = tr_ctrl - src_ctrl
            parts = []
            if missing:
                parts.append("missing " + ", ".join(sorted(missing.elements())))
            if extra:
                parts.append("extra " + ", ".join(sorted(extra.elements())))
            self.warn(where, key, lang, "control codes differ from the source text: " + "; ".join(parts))

        # Line commands
        toks = tokenize(text)
        if toks and toks[-1] in LINE_BREAKS and not (tokenize(source_text) or [""])[-1] in LINE_BREAKS:
            self.error(where, key, lang, f"ends with a line command '{toks[-1]}'")
            ok = False
        for a, b in zip(toks, toks[1:]):
            if a in LINE_BREAKS and b in LINE_BREAKS and (a + b) not in source_text:
                self.warn(where, key, lang, f"consecutive line commands '{a}{b}'")
                break
        if unit is not None and unit.kind == "asm" and text.endswith("$") and not text.endswith("\\$"):
            self.error(where, key, lang, "must not end with '$'; the terminator is added automatically")
            ok = False
        if unit is not None and unit.kind == "c" and 0xFF in encoded and "$" not in source_text:
            self.warn(where, key, lang, "contains '$' (end of string) which truncates the text")

        # Pixel width
        for font, limit in checks:
            if limit is None:
                continue
            src_max = max((w for _, w in self.fonts.line_widths(source_text, font)), default=0)
            limit = max(limit, src_max)   # never stricter than the shipped source text
            for line, width in self.fonts.line_widths(text, font):
                if width > limit:
                    self.error(where, key, lang,
                               f"line is {width}px wide in {font}, limit is {limit}px: \"{line}\"")
                    ok = False
                    break

        # Lines per page
        if max_lines:
            src_pages = _lines_per_page(source_text)
            limit = max(max_lines, max(src_pages, default=0))
            pages = _lines_per_page(text)
            if pages and max(pages) > limit:
                self.error(where, key, lang,
                           f"a page has {max(pages)} lines, the text box shows {limit}; split it with \\p")
                ok = False

        # Fixed-length buffers
        if max_bytes is not None:
            terminator = 1 if unit is None or unit.adds_terminator else 0
            size = len(encoded) + terminator
            # Rule-based limits can be stricter than what already ships.
            max_bytes = max(max_bytes, len(self.charmap.encode(source_text)) + terminator)
            if size > max_bytes:
                self.error(where, key, lang, f"needs {size} bytes, buffer holds {max_bytes}")
                ok = False
        if pad is not None:
            if len(encoded) > pad:
                self.error(where, key, lang, f"is {len(encoded)} bytes, the field is padded to {pad}")
                ok = False

        return encoded if ok else None


def _lines_per_page(text):
    pages = []
    lines = 1
    for tok in tokenize(text):
        if tok == "\\n":
            lines += 1
        elif tok == "\\l":
            # \l scrolls: the box still shows the same number of lines.
            pass
        elif tok == "\\p":
            pages.append(lines)
            lines = 1
    pages.append(lines)
    return pages
