"""Python port of tools/preproc's charmap reader and string encoder.

The encoder must produce exactly the bytes preproc produces for the same
string literal contents, because translation tables match source strings by
the hash of their encoded bytes.  tests/test_charmap.py checks this parity.
"""

import re

EOS = 0xFF


class EncodeError(Exception):
    def __init__(self, message, pos=None):
        super().__init__(message)
        self.pos = pos


class Charmap:
    def __init__(self, path):
        self.path = path
        self.chars = {}       # code point -> bytes
        self.escapes = {}     # ascii char -> bytes
        self.constants = {}   # NAME -> bytes
        self._load(path)

    def _load(self, path):
        with open(path, encoding="utf-8") as f:
            for lineno, raw in enumerate(f, 1):
                line = self._strip_comment(raw.rstrip("\n"))
                if not line.strip():
                    continue
                lhs, sep, rhs = self._split(line)
                if not sep:
                    raise ValueError(f"{path}:{lineno}: expected '='")
                seq = bytes(int(b, 16) for b in rhs.split())
                lhs = lhs.strip()
                if lhs.startswith("'"):
                    body = lhs[1:-1]
                    if body.startswith("\\") and len(body) == 2 and body[1] != "'":
                        self.escapes[body[1]] = seq
                    else:
                        ch = body[1:] if body.startswith("\\") else body
                        self.chars[ch] = seq
                else:
                    self.constants[lhs] = seq

    @staticmethod
    def _strip_comment(line):
        in_char = False
        i = 0
        while i < len(line):
            c = line[i]
            if in_char:
                if c == "\\" and i + 1 < len(line) and line[i + 1] == "'":
                    i += 2
                    continue
                if c == "'":
                    in_char = False
            elif c == "@":
                return line[:i]
            elif c == "'":
                in_char = True
            i += 1
        return line

    @staticmethod
    def _split(line):
        # The left-hand side may itself be '=' (a quoted char literal).
        if line.lstrip().startswith("'"):
            start = line.index("'")
            end = line.index("'", start + 2) if line[start + 1] != "\\" else line.index("'", start + 3)
            rest = line[end + 1:]
            lhs = line[:end + 1]
            pre, sep, rhs = rest.partition("=")
            return lhs, sep, rhs
        return line.partition("=")

    # ------------------------------------------------------------------
    # Encoding (mirrors StringParser::ParseString)

    def encode(self, text):
        """Encodes the contents of a string literal (without quotes)."""
        out = bytearray()
        i = 0
        n = len(text)
        while i < n:
            c = text[i]
            if c == "{":
                end = text.find("}", i)
                if end < 0:
                    raise EncodeError("unterminated '{'", i)
                out += self._encode_braces(text[i + 1:end], i)
                i = end + 1
            elif c == "\\":
                if i + 1 >= n:
                    raise EncodeError("dangling backslash", i)
                e = text[i + 1]
                if e in ('"', "\\"):
                    seq = self.chars.get(e)
                else:
                    seq = self.escapes.get(e)
                if not seq:
                    raise EncodeError(f"unknown escape '\\{e}'", i)
                out += seq
                i += 2
            else:
                if ord(c) < 0x20 or ord(c) == 0x7F:
                    raise EncodeError(f"unexpected control character U+{ord(c):04X}", i)
                seq = self.chars.get(c)
                if not seq:
                    raise EncodeError(f"character '{c}' (U+{ord(c):04X}) is not in charmap.txt", i)
                out += seq
                i += 1
        return bytes(out)

    def _encode_braces(self, body, pos):
        out = bytearray()
        for tok in body.split():
            if re.match(r"^[A-Za-z_]\w*$", tok):
                seq = self.constants.get(tok)
                if seq is None:
                    raise EncodeError(f"unknown constant '{{{tok}}}'", pos)
                out += seq
            elif re.match(r"^\d", tok):
                out += _encode_int(tok, pos)
            else:
                raise EncodeError(f"unexpected '{tok}' within curly brackets", pos)
        return bytes(out)


def _encode_int(tok, pos):
    if tok.startswith("0x"):
        digits = tok[2:]
        if len(digits) not in (2, 4, 8) or not re.match(r"^[0-9A-Fa-f]+$", digits):
            raise EncodeError(f"hex integer literal '{tok}' must have 2, 4 or 8 digits", pos)
        return int(digits, 16).to_bytes(len(digits) // 2, "little")
    m = re.match(r"^(\d+)([HW]?)$", tok)
    if not m:
        raise EncodeError(f"bad integer literal '{tok}'", pos)
    value = int(m.group(1))
    if m.group(2) == "H":
        size = 2
    elif m.group(2) == "W":
        size = 4
    else:
        size = 4 if value >= 0x10000 else 2 if value >= 0x100 else 1
    return value.to_bytes(size, "little")


def fnv1a64(data):
    h = 0xcbf29ce484222325
    for b in data:
        h = ((h ^ b) * 0x00000100000001b3) & 0xFFFFFFFFFFFFFFFF
    return h


# ----------------------------------------------------------------------
# Text tokenization (used by validation; works on source syntax, not bytes)

TOKEN_RE = re.compile(r"\{[^}]*\}|\\.|.", re.S)


def tokenize(text):
    """Splits source-syntax text into chars, escapes ('\\n') and brace groups."""
    return TOKEN_RE.findall(text)
