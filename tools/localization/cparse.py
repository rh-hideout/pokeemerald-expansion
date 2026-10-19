"""Extracts localizable strings from raw (un-preprocessed) C sources.

Every `_("...")`, `__("...")`, `COMPOUND_STRING("...")` and configured string
macro (e.g. `ITEM_NAME("...")`) becomes a unit with a key derived from the
code around it:

    static const u8 gText_Foo[] = _("...");      -> gText_Foo
    gItemsInfo[] = { [ITEM_POTION] = { .name = ITEM_NAME("Potion") } }
                                                  -> gItemsInfo[ITEM_POTION].name
    sTexts[] = { COMPOUND_STRING("A"), ... }      -> sTexts[0]
    void Foo(void) { Print(COMPOUND_STRING("A")); }
                                                  -> Foo@<hash of text>

Strings in #define bodies, or whose argument is not purely string literals,
are reported as skipped instead of extracted.
"""

import re
from dataclasses import dataclass

from charmap import fnv1a64


@dataclass
class CString:
    key: str
    text: str            # concatenated literal contents, source syntax
    line: int            # line of the `_` / macro token
    kind: str            # "_", "__", "COMPOUND_STRING" or a macro name
    max_bytes: object = None   # array size expression (incl. terminator) or None
    decl: str = ""       # declaration name the string belongs to
    field_name: str = "" # last designator field, e.g. "name"
    file: str = None     # source file named by a #line directive, if any


@dataclass
class Skipped:
    line: int
    reason: str


TOKEN_RE = re.compile(r"""
    (?P<ws>[ \t\r\f\v]+)
  | (?P<nl>\n)
  | (?P<lcomment>//[^\n]*)
  | (?P<bcomment>/\*.*?\*/)
  | (?P<string>"(?:[^"\\\n]|\\.)*")
  | (?P<char>'(?:[^'\\\n]|\\.)*')
  | (?P<ident>[A-Za-z_]\w*)
  | (?P<number>\.?\d(?:[\w.]|[eEpP][+-])*)
  | (?P<punct>\#\#|->|\.\.\.|<<=|>>=|[<>=!+\-*/%&|^]=|&&|\|\||<<|>>|\+\+|--|[{}\[\]();,.<>=!+\-*/%&|^~?:\#])
""", re.S | re.X)


@dataclass
class Tok:
    kind: str
    value: str
    line: int
    file: str = None   # logical file from #line, None for the scanned file
    pline: int = 0     # physical line in the scanned file


def tokenize(src):
    """Tokenizes C source, dropping comments and preprocessor directives.

    Returns (tokens, define_lines) where define_lines holds the line numbers
    of #define bodies (strings there can't be localized by key)."""
    toks = []
    define_lines = set()
    directive_lines = {}
    line = 1
    # #line remapping: logical line = physical line + line_delta
    line_delta = 0
    line_file = None
    pos = 0
    at_line_start = True
    in_directive = False
    directive_is_define = False
    toks_in_directive = []
    n = len(src)
    while pos < n:
        m = TOKEN_RE.match(src, pos)
        if not m:
            # Unknown character (e.g. backslash-newline); skip it.
            if src[pos] == "\\" and src.startswith("\\\n", pos):
                pos += 2
                line += 1
                continue
            pos += 1
            continue
        kind = m.lastgroup
        text = m.group()
        pos = m.end()
        if kind == "nl":
            line += 1
            at_line_start = True
            in_directive = False
            continue
        if kind in ("ws",):
            continue
        if kind in ("lcomment", "bcomment"):
            line += text.count("\n")
            continue
        if at_line_start and kind == "punct" and text == "#":
            in_directive = True
            m_kind = re.compile(r"[ \t]*(\w+)").match(src, pos)
            directive_lines[line] = m_kind.group(1) if m_kind else ""
            m_line = re.compile(r'[ \t]*(?:line[ \t]+)?(\d+)(?:[ \t]+"([^"]*)")?[ \t]*$', re.M).match(src, pos)
            if m_line:
                # The line after the directive has the given number.
                line_delta = int(m_line.group(1)) - (line + 1)
                if m_line.group(2) is not None:
                    line_file = m_line.group(2)
            # look ahead for 'define'
            m2 = re.compile(r"[ \t]*(\w+)").match(src, pos)
            directive_is_define = bool(m2 and m2.group(1) == "define")
            toks_in_directive = []
        at_line_start = False
        if in_directive:
            if directive_is_define and kind == "string" and toks_in_directive[-2:] and \
                    toks_in_directive[-1] == "(" and toks_in_directive[-2] in ("_", "__", "COMPOUND_STRING"):
                define_lines.add(line)
            toks_in_directive.append(text)
            # Handle line continuations inside directives.
            continue
        toks.append(Tok(kind, text, line + line_delta, line_file, line))
    return toks, define_lines, directive_lines


class CParser:
    def __init__(self, src, string_macros):
        # Preserve line numbers but neutralise backslash-newlines in
        # directives: replace them by a space and record the newline using
        # a block comment that the tokenizer counts.
        src = src.replace("\\\r\n", "/*\n*/").replace("\\\n", "/*\n*/")
        self.toks, self.define_lines, self.directive_lines = tokenize(src)
        self.string_macros = set(string_macros)
        self.strings = []
        self.skipped = [Skipped(l, "string inside #define") for l in sorted(self.define_lines)]
        self.i = 0
        self.conditional_strings = set()

    # -- helpers --------------------------------------------------------
    def peek(self, k=0):
        j = self.i + k
        return self.toks[j] if j < len(self.toks) else None

    def is_string_start(self, j):
        t = self.toks[j] if j < len(self.toks) else None
        if t is None or t.kind != "ident":
            return False
        nxt = self.toks[j + 1] if j + 1 < len(self.toks) else None
        if nxt is None or nxt.value != "(":
            return False
        return t.value in ("_", "__", "COMPOUND_STRING") or t.value in self.string_macros

    def read_string_call(self, j):
        """Reads `NAME ( "a" "b" )` starting at token j.

        Returns (end_index, [texts] or None). There is more than one text
        when #if/#else lines select between pieces; each combination is a
        separate variant (preproc matches whichever one gets compiled)."""
        name_tok = self.toks[j]
        k = j + 2
        pieces = []
        piece_lines = []
        ok = True
        depth = 1
        while k < len(self.toks):
            t = self.toks[k]
            if t.value == "(":
                depth += 1
                ok = False
            elif t.value == ")":
                depth -= 1
                if depth == 0:
                    break
            elif t.kind == "string" and depth == 1:
                pieces.append(t.value[1:-1])
                piece_lines.append(t.pline)
            else:
                ok = False
            k += 1
        if not pieces:
            ok = False
        end_line = self.toks[k].pline if k < len(self.toks) else name_tok.pline
        # The closing ')' may sit inside an #if branch, with each branch
        # repeating it:  "a" #if X "b"), #else "c"), #endif
        opened = sum(1 if kind.startswith("if") else -1 if kind == "endif" else 0
                     for l, kind in self.directive_lines.items() if name_tok.pline < l < end_line)
        if ok and opened > 0:
            endif_line = None
            for l, kind in sorted(self.directive_lines.items()):
                if l <= end_line:
                    continue
                if kind.startswith("if"):
                    opened += 1
                elif kind == "endif":
                    opened -= 1
                    if opened == 0:
                        endif_line = l
                        break
            if endif_line is None:
                ok = False
            else:
                m = k + 1
                while m < len(self.toks) and self.toks[m].pline < endif_line:
                    t = self.toks[m]
                    if t.kind == "string":
                        pieces.append(t.value[1:-1])
                        piece_lines.append(t.pline)
                    elif t.value not in (")", ","):
                        ok = False
                    m += 1
                k = m - 1
                end_line = endif_line + 1
        if not ok:
            return k + 1, None
        directives = sorted((l, kind) for l, kind in self.directive_lines.items() if name_tok.pline < l < end_line)
        if not directives:
            return k + 1, ["".join(pieces)]
        variants = self.string_variants(pieces, piece_lines, directives)
        if variants is None:
            self.conditional_strings.add(j)
        return k + 1, variants

    MAX_VARIANTS = 8

    def string_variants(self, pieces, piece_lines, directives):
        """Expands non-nested #if/#elif/#else groups inside a string call."""
        segments = []        # str, or list of branch strings
        group = None         # branches of the open group
        events = sorted([(l, 1, kind) for l, kind in directives] +
                        [(l, 0, i) for i, l in enumerate(piece_lines)])
        for line, is_directive, value in events:
            if is_directive:
                kind = value
                if kind in ("if", "ifdef", "ifndef"):
                    if group is not None:
                        return None   # nested conditionals
                    group = [""]
                elif kind in ("elif", "else"):
                    if group is None:
                        return None
                    group.append("")
                elif kind == "endif":
                    if group is None:
                        return None
                    if len(group) == 1:
                        group.append("")   # #if without #else
                    segments.append(group)
                    group = None
                else:
                    return None
            else:
                if group is not None:
                    group[-1] += pieces[value]
                else:
                    segments.append(pieces[value])
        if group is not None:
            return None
        variants = [""]
        for seg in segments:
            if isinstance(seg, str):
                variants = [v + seg for v in variants]
            else:
                variants = [v + b for v in variants for b in seg]
            if len(variants) > self.MAX_VARIANTS:
                return None
        # Keep order, drop duplicates.
        return list(dict.fromkeys(variants))

    def matching(self, j, open_, close):
        depth = 0
        k = j
        while k < len(self.toks):
            v = self.toks[k].value
            if v == open_:
                depth += 1
            elif v == close:
                depth -= 1
                if depth == 0:
                    return k
            k += 1
        return len(self.toks) - 1

    def add(self, key, j, texts, ctx):
        tok = self.toks[j]
        if texts is None:
            reason = ("preprocessor conditional inside the string" if j in self.conditional_strings
                      else f"non-literal argument to {tok.value}()")
            self.skipped.append(Skipped(tok.line, reason))
            return
        for n, text in enumerate(texts, 1):
            self.strings.append(CString(key=key if n == 1 else f"{key}/alt{n}", text=text, line=tok.line,
                                        kind=tok.value, max_bytes=ctx.get("max_bytes"),
                                        decl=ctx.get("decl", ""), field_name=ctx.get("field", ""),
                                        file=tok.file))

    # -- top level ------------------------------------------------------
    def parse(self):
        toks = self.toks
        while self.i < len(toks):
            t = toks[self.i]
            if t.value in (";",):
                self.i += 1
                continue
            if t.value in ("[", ".") or t.value == "{":
                # Bare initializer fragment (header included inside an
                # initializer, e.g. species_info/gen_1_families.h).
                self.i = self.parse_init_list(self.i, "", {}, bare=True)
                continue
            self.parse_declaration()
        return self.strings, self.skipped

    def parse_declaration(self):
        toks = self.toks
        header = []
        depth = 0
        k = self.i
        while k < len(toks):
            v = toks[k].value
            if v == "(":
                depth += 1
            elif v == ")":
                depth -= 1
            elif depth == 0 and v in ("=", "{", ";"):
                break
            elif depth == 0 and self.is_string_start(k):
                break
            header.append(toks[k])
            k += 1
        if k >= len(toks):
            self.i = k
            return
        v = toks[k].value
        if v == ";":
            self.i = k + 1
            return
        if v == "{":
            # Function definition, struct/enum definition, or aggregate
            # declared without '=' (not valid C, ignore).
            close = self.matching(k, "{", "}")
            func = self.function_name(header)
            if func:
                self.scan_function_body(k, close, func)
            self.i = close + 1
            return
        if v != "=":
            # e.g. a string macro used at top level without declaration
            self.i = k + 1
            return
        name, dims, is_ptr = self.declarator(header)
        ctx = {"decl": name}
        k += 1
        if k < len(toks) and toks[k].value == "{":
            sub = dict(ctx)
            sub["dims"] = dims
            sub["is_ptr"] = is_ptr
            self.i = self.parse_init_list(k, name, sub)
            return
        # Scalar initializer: scan expression until ';' at depth 0.
        sub = dict(ctx)
        if dims and not is_ptr:
            sub["max_bytes"] = dims[-1]
        self.i = self.scan_expression(k, name, sub, stop=(";",))

    def function_name(self, header):
        # Last identifier directly before a '(' at depth 0.
        depth = 0
        for idx, t in enumerate(header):
            if t.value == "(":
                if depth == 0 and idx > 0 and header[idx - 1].kind == "ident":
                    name = header[idx - 1].value
                    if name not in ("__attribute__", "ALIGNED", "UNUSED", "NAKED", "asm", "__asm__"):
                        return name
                depth += 1
            elif t.value == ")":
                depth -= 1
        return None

    def declarator(self, header):
        """Returns (name, [dim exprs], is_pointer) for a declaration header."""
        name = ""
        dims = []
        is_ptr = False
        depth = 0
        idx = 0
        while idx < len(header):
            t = header[idx]
            if t.value == "(":
                depth += 1
            elif t.value == ")":
                depth -= 1
            elif depth == 0:
                if t.kind == "ident":
                    nxt = header[idx + 1] if idx + 1 < len(header) else None
                    if nxt is None or nxt.value != "(":
                        name = t.value
                        dims = []
                elif t.value == "*":
                    is_ptr = True
                elif t.value == "[":
                    close = idx
                    d = 0
                    while close < len(header):
                        if header[close].value == "[":
                            d += 1
                        elif header[close].value == "]":
                            d -= 1
                            if d == 0:
                                break
                        close += 1
                    dims.append(" ".join(x.value for x in header[idx + 1:close]))
                    idx = close
            idx += 1
        return name, dims, is_ptr

    # -- initializers ---------------------------------------------------
    def parse_init_list(self, k, path, ctx, bare=False):
        """Parses `{ ... }` (or a bare element sequence) at token k."""
        toks = self.toks
        if not bare:
            assert toks[k].value == "{"
            k += 1
        index = 0
        while k < len(toks):
            t = toks[k]
            if t.value == "}":
                return k + 1
            if t.value == ",":
                k += 1
                continue
            # Designators
            des = ""
            field_name = None
            while k < len(toks) and toks[k].value in ("[", "."):
                if toks[k].value == "[":
                    close = self.matching(k, "[", "]")
                    des += "[" + " ".join(x.value for x in toks[k + 1:close]) + "]"
                    k = close + 1
                else:
                    if k + 1 < len(toks) and toks[k + 1].kind == "ident":
                        field_name = toks[k + 1].value
                        des += "." + field_name
                    k += 2
            if des and k < len(toks) and toks[k].value == "=":
                k += 1
            elif des:
                # Not actually a designator (shouldn't happen); bail out.
                pass
            elem_path = path + (des if des else f"[{index}]")
            sub = dict(ctx)
            if field_name is not None:
                sub["field"] = field_name
            # The char-array dimension only applies to string elements of
            # the innermost level.
            dims = ctx.get("dims") or []
            if dims and not ctx.get("is_ptr") and len(dims) >= 1:
                rest = dims[1:]
                sub["dims"] = rest
                sub["max_bytes"] = dims[-1] if len(dims) == 2 else None
            else:
                sub["dims"] = []
                sub["max_bytes"] = None
            if field_name is not None:
                sub["max_bytes"] = None  # resolved from struct fields later
            before = k
            if k < len(toks) and toks[k].value == "{":
                k = self.parse_init_list(k, elem_path, sub)
            else:
                k = self.scan_expression(k, elem_path, sub, stop=(",", "}"))
            if k == before:
                k += 1  # stray token (e.g. unbalanced ')'); never stall
            index += 1
            if bare and k < len(toks) and toks[k].value == ";":
                return k + 1
        return k

    def scan_expression(self, k, path, ctx, stop):
        """Scans an expression for strings until a stop token at depth 0."""
        toks = self.toks
        depth = 0
        count = 0
        while k < len(toks):
            t = toks[k]
            if depth == 0 and t.value in stop:
                return k if t.value != ";" else k + 1
            if self.is_string_start(k):
                end, texts = self.read_string_call(k)
                key = path if count == 0 else f"{path}#{count + 1}"
                self.add(key, k, texts, ctx)
                count += 1
                k = end
                continue
            if t.value == "{":
                k = self.parse_init_list(k, path, ctx)
                continue
            if t.value in ("(", "["):
                depth += 1
            elif t.value in (")", "]"):
                depth -= 1
                if depth < 0:
                    return k
            elif t.value == "}":
                return k
            k += 1
        return k

    # -- functions ------------------------------------------------------
    def scan_function_body(self, start, end, func):
        k = start + 1
        while k < end:
            if self.is_string_start(k):
                stop, texts = self.read_string_call(k)
                h = fnv1a64((texts[0] if texts else "").encode("utf-8")) & 0xFFFFFF
                self.add(f"{func}@{h:06x}", k, texts, {"decl": func})
                k = stop
                continue
            k += 1


def parse_c(src, string_macros=()):
    parser = CParser(src, string_macros)
    strings, skipped = parser.parse()
    # Make keys unique within the file (e.g. #if/#else alternatives).
    seen = {}
    for s in strings:
        n = seen.get(s.key, 0) + 1
        seen[s.key] = n
        if n > 1:
            s.key = f"{s.key}~{n}"
    return strings, skipped
