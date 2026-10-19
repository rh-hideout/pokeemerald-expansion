"""Project-wide configuration: paths, rules.json, C constants and struct fields."""

import fnmatch
import glob
import json
import os
import re
import subprocess

TOOL_DIR = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(TOOL_DIR, "..", ".."))

LOC_DIR = "localization"
TEXT_DIR = os.path.join(LOC_DIR, "text")
LOCALES_DIR = os.path.join(LOC_DIR, "locales")
RULES_PATH = os.path.join(LOC_DIR, "rules.json")
GRAPHICS_PATH = os.path.join(LOC_DIR, "graphics.json")
ASSETS_CSV = os.path.join(LOC_DIR, "assets.csv")
CHARMAP_PATH = "charmap.txt"


def glob_match(path, patterns):
    """fnmatch where '**/' may also match nothing (so 'a/**/b' matches 'a/b')."""
    for p in patterns:
        # Keys contain brackets (gItemsInfo[ITEM_POTION].name): match them literally.
        p = p.replace("[", "[[]")
        if fnmatch.fnmatchcase(path, p) or fnmatch.fnmatchcase(path, p.replace("**/", "")):
            return True
    return False


class Project:
    def __init__(self, root=ROOT):
        self.root = root
        with open(self.path(RULES_PATH), encoding="utf-8") as f:
            self.rules = json.load(f)
        self.languages = self.rules["languages"]
        self.source_language = self.rules.get("source_language", "en")
        self._defines = None
        self._fields = None

    def path(self, *parts):
        return os.path.join(self.root, *parts)

    def rel(self, path):
        return os.path.relpath(path, self.root).replace(os.sep, "/")

    @property
    def target_languages(self):
        return [l for l in self.languages if l != self.source_language]

    # -- sources -----------------------------------------------------------
    def _git_visible_files(self):
        """Tracked plus untracked-but-not-ignored files, or None without git.

        Generated sources (gitignored) are skipped so extraction doesn't
        depend on whether a build has run."""
        try:
            out = subprocess.run(["git", "ls-files", "--cached", "--others", "--exclude-standard", "-z"],
                                 cwd=self.root, capture_output=True, check=True)
        except (OSError, subprocess.CalledProcessError):
            return None
        return set(p for p in out.stdout.decode("utf-8").split("\0") if p)

    def source_files(self):
        src = self.rules["sources"]
        exclude = src.get("exclude", [])
        visible = self._git_visible_files()
        out = []
        self.missing_generated = []
        # Generated sources holding game text (made by 'make generated').
        for rel in src.get("generated", []):
            if os.path.isfile(self.path(rel)):
                out.append(("c", rel))
            else:
                self.missing_generated.append(rel)
        generated = set(src.get("generated", []))
        for kind in ("c", "asm"):
            seen = set()
            for pattern in src[kind]:
                for p in sorted(glob.glob(self.path(pattern), recursive=True)):
                    rel = self.rel(p)
                    if rel in seen or rel in generated or glob_match(rel, exclude) or not os.path.isfile(p):
                        continue
                    if visible is not None and rel not in visible:
                        continue
                    seen.add(rel)
                    out.append((kind, rel))
        return out

    def csv_path(self, source_rel):
        return os.path.join(TEXT_DIR, source_rel + ".csv").replace(os.sep, "/")

    # -- text rules ----------------------------------------------------------
    def text_rule(self, source_rel, key):
        """Returns the merged rule for a unit: later rules override earlier
        ones, except 'checks' lists, which accumulate."""
        merged = {"checks": []}
        for rule in self.rules.get("text_rules", []):
            files = rule.get("files")
            keys = rule.get("keys")
            if files and not glob_match(source_rel, files):
                continue
            if keys and not glob_match(key, keys):
                continue
            merged["checks"] += rule.get("checks", [])
            merged.update({k: v for k, v in rule.items() if k not in ("files", "keys", "comment", "checks")})
        return merged

    def buffer_rule(self, source_rel, key):
        for rule in self.rules.get("buffers", []):
            files = rule.get("files")
            if files and not glob_match(source_rel, files):
                continue
            if glob_match(key, rule.get("keys", ["*"])):
                return rule["max_bytes"]
        return None

    def skip_unit(self, source_rel, key):
        skip = self.rules.get("skip", {})
        return glob_match(key, skip.get("keys", []))

    # -- C constants ---------------------------------------------------------
    @property
    def defines(self):
        if self._defines is None:
            self._defines = {}
            for p in glob.glob(self.path("include", "**", "*.h"), recursive=True):
                with open(p, encoding="utf-8", errors="replace") as f:
                    for m in re.finditer(r"^[ \t]*#[ \t]*define[ \t]+(\w+)[ \t]+([^\n]*?)\s*(?://.*)?$", f.read(), re.M):
                        self._defines.setdefault(m.group(1), []).append(m.group(2))
        return self._defines

    def eval_expr(self, expr, depth=0):
        """Evaluates a constant integer expression, or returns None."""
        if expr is None:
            return None
        expr = expr.strip()
        if not expr or depth > 16:
            return None

        def repl(m):
            name = m.group(0)
            values = [self.eval_expr(v, depth + 1) for v in self.defines.get(name, [])]
            values = [v for v in values if v is not None]
            if not values:
                raise ValueError(name)
            # Config-dependent constants: be lenient and take the largest.
            return str(max(values))

        try:
            text = re.sub(r"\b[A-Za-z_]\w*\b", repl, expr)
        except ValueError:
            return None
        text = re.sub(r"\b(0x[0-9A-Fa-f]+|\d+)[uUlL]*\b", r"\1", text)
        if not re.fullmatch(r"[\d\sxXa-fA-F+\-*/()<>]*", text):
            return None
        try:
            value = eval(text.replace("/", "//"), {"__builtins__": {}}, {})
        except Exception:
            return None
        return int(value) if isinstance(value, int) else None

    @property
    def struct_fields(self):
        """Maps u8 struct member names to their array size expressions.

        A name that is a pointer anywhere, or has different sizes in
        different structs, maps to None (ambiguous)."""
        if self._fields is None:
            seen = {}
            pattern = re.compile(r"^\s*(?:const\s+)?u8\s+(\*\s*(?:const\s+)?)?(\w+)\s*(\[([^\]\n]+)\])?\s*(?::\s*\d+\s*)?;", re.M)
            for p in glob.glob(self.path("include", "**", "*.h"), recursive=True):
                with open(p, encoding="utf-8", errors="replace") as f:
                    for m in pattern.finditer(f.read()):
                        size = "ptr" if m.group(1) else (m.group(4) or "scalar")
                        seen.setdefault(m.group(2), set()).add(size.strip())
            self._fields = {name: (next(iter(s)) if len(s) == 1 and next(iter(s)) not in ("ptr", "scalar") else None)
                            for name, s in seen.items()}
        return self._fields
