import os
import subprocess
import unittest

from tests.fixture import Fixture
from tests.helpers import ROOT

import csvstore
import extract
from charmap import Charmap, fnv1a64
from fonts import FontSet
from generate import generate
from project import Project

PREPROC = os.path.join(ROOT, "tools", "preproc", "preproc")


class GenerateTest(unittest.TestCase):
    def setUp(self):
        self.fx = Fixture()
        self.project = Project(self.fx.root)
        self.charmap = Charmap(self.project.path("charmap.txt"))
        self.fonts = FontSet(self.fx.root, self.charmap, self.project.rules["placeholder_chars"])
        self.extract()

    def tearDown(self):
        self.fx.cleanup()

    def extract(self):
        scans = extract.scan_all(self.project)
        for rel, scan in scans.items():
            extract.update_csv(self.project, rel, scan.units)
        return scans

    def run_generate(self, strict=False):
        out = os.path.join(self.fx.root, "build", "loc", "es")
        result, validator = generate(self.project, self.charmap, self.fonts, "es", out, strict=strict)
        return result, validator, out

    def table(self, out, rel):
        path = os.path.join(out, "strings", rel + ".tbl")
        if not os.path.exists(path):
            return []
        with open(path) as f:
            return [line.split() for line in f]

    def messages(self, validator, level="error"):
        return [d.message for d in validator.diagnostics if d.level == level]

    # -- extraction -------------------------------------------------------
    def test_extract_creates_csvs(self):
        header, rows = csvstore.read_csv(self.project.path("localization/text/src/test.c.csv"))
        keys = [r["key"] for r in rows]
        self.assertEqual(header, ["key", "context", "max_width", "en", "es", "status"])
        self.assertIn("gText_Hello", keys)
        self.assertIn("gItemsInfo[ITEM_POTION].name", keys)
        self.assertTrue(any(k.startswith("Foo@") for k in keys))

    def edit_source(self, *pairs, extract=True):
        src = self.project.path("src/test.c")
        with open(src, encoding="utf-8") as f:
            text = f.read()
        for old, new in pairs:
            self.assertIn(old, text)
            text = text.replace(old, new)
        with open(src, "w", encoding="utf-8") as f:
            f.write(text)
        if extract:
            self.extract()
        _, rows = csvstore.read_csv(self.project.path("localization/text/src/test.c.csv"))
        return {r["key"]: r for r in rows}

    def function_key(self, by_key=None):
        if by_key is None:
            _, rows = csvstore.read_csv(self.project.path("localization/text/src/test.c.csv"))
            by_key = {r["key"]: r for r in rows}
        return next(k for k in by_key if k.startswith("Foo@"))

    def test_extract_marks_changed_text_stale(self):
        self.fx.set_translation("src/test.c", "gText_Hello", "es", "¡Hola, {PLAYER}!")
        by_key = self.edit_source(("Hello, {PLAYER}!", "Hello again, {PLAYER}!"))
        self.assertEqual(by_key["gText_Hello"]["status"], "stale:es")
        self.assertEqual(by_key["gText_Hello"]["es"], "¡Hola, {PLAYER}!")

    def test_renamed_key_keeps_translation(self):
        self.fx.set_translation("src/test.c", "gText_Twin1", "es", "Igual")
        by_key = self.edit_source(("gText_Twin1", "gText_Renamed"))
        self.assertNotIn("gText_Twin1", by_key)
        self.assertEqual(by_key["gText_Renamed"]["es"], "Igual")
        self.assertEqual(by_key["gText_Renamed"]["status"], "")

    def test_edited_function_string_carries_translation(self):
        old_key = self.function_key()
        self.fx.set_translation("src/test.c", old_key, "es", "Dentro de una función")
        by_key = self.edit_source(("Inside a function", "Inside the function"))
        new_key = self.function_key(by_key)
        self.assertNotEqual(new_key, old_key)
        self.assertNotIn(old_key, by_key)
        self.assertEqual(by_key[new_key]["es"], "Dentro de una función")
        self.assertEqual(by_key[new_key]["status"], "stale:es")

    def test_unrelated_string_does_not_take_translation(self):
        old_key = self.function_key()
        self.fx.set_translation("src/test.c", old_key, "es", "Dentro de una función")
        by_key = self.edit_source(("Inside a function", "Completely different words"))
        new_key = self.function_key(by_key)
        self.assertEqual(by_key[new_key]["es"], "")
        self.assertEqual(by_key[old_key]["status"], "obsolete")
        self.assertEqual(by_key[old_key]["es"], "Dentro de una función")

    def test_prune_removes_unpaired_obsolete_rows(self):
        old_key = self.function_key()
        self.fx.set_translation("src/test.c", old_key, "es", "Dentro de una función")
        self.edit_source(("Inside a function", "Completely different words"), extract=False)
        for rel, scan in extract.scan_all(self.project).items():
            extract.update_csv(self.project, rel, scan.units, prune=True)
        _, rows = csvstore.read_csv(self.project.path("localization/text/src/test.c.csv"))
        self.assertNotIn(old_key, {r["key"] for r in rows})

    # -- generation -------------------------------------------------------
    def test_missing_translations_fall_back(self):
        result, validator, out = self.run_generate()
        self.assertEqual(result.translated, 0)
        self.assertEqual(len(result.missing), result.total)
        self.assertEqual(validator.errors, [])

    def test_strict_missing_is_error(self):
        _, validator, _ = self.run_generate(strict=True)
        self.assertIn("missing translation", self.messages(validator))

    def test_c_table(self):
        self.fx.set_translation("src/test.c", "gText_Hello", "es", "¡Hola, {PLAYER}!")
        result, validator, out = self.run_generate()
        self.assertEqual(validator.errors, [])
        entries = self.table(out, "src/test.c")
        self.assertEqual(len(entries), 1)
        kind, line, h, data = entries[0]
        self.assertEqual((kind, line), ("C", "1"))
        self.assertEqual(int(h, 16), fnv1a64(self.charmap.encode("Hello, {PLAYER}!")))
        self.assertEqual(bytes.fromhex(data), self.charmap.encode("¡Hola, {PLAYER}!"))

    def test_identical_strings_get_identity_entries(self):
        self.fx.set_translation("src/test.c", "gText_Twin2", "es", "Igual")
        _, validator, out = self.run_generate()
        entries = self.table(out, "src/test.c")
        self.assertEqual(sorted(e[1] for e in entries), ["2", "3"])
        by_line = {e[1]: bytes.fromhex(e[3]) for e in entries}
        self.assertEqual(by_line["2"], self.charmap.encode("Same"))
        self.assertEqual(by_line["3"], self.charmap.encode("Igual"))

    def test_asm_table(self):
        self.fx.set_translation("data/test.inc", "Test_Text_Greeting", "es", "¡Hola!\\pBienvenido a la prueba.")
        _, validator, out = self.run_generate()
        self.assertEqual(validator.errors, [])
        entries = self.table(out, "data/test.inc")
        self.assertEqual([e[1] for e in entries], ["2", "3"])
        self.assertEqual(bytes.fromhex(entries[0][3]), self.charmap.encode("¡Hola!\\pBienvenido a la prueba.$"))
        self.assertEqual(entries[1][3], "-")

    def test_padded_asm(self):
        self.fx.set_translation("data/test.inc", "Test_Text_Name", "es", "BETO")
        _, validator, out = self.run_generate()
        entries = self.table(out, "data/test.inc")
        self.assertEqual(bytes.fromhex(entries[0][3]), self.charmap.encode("BETO$") + b"\x00" * 3)

    # -- validation -------------------------------------------------------
    def assert_error(self, rel, key, text, fragment):
        self.fx.set_translation(rel, key, "es", text)
        _, validator, out = self.run_generate()
        msgs = self.messages(validator)
        self.assertTrue(any(fragment in m for m in msgs), msgs)
        return out

    def test_unknown_character(self):
        out = self.assert_error("src/test.c", "gText_Hello", "Привет, {PLAYER}!", "not in charmap.txt")
        self.assertEqual(self.table(out, "src/test.c"), [])

    def test_missing_placeholder(self):
        self.assert_error("src/test.c", "gText_Hello", "¡Hola!", "missing {PLAYER}")

    def test_unknown_placeholder(self):
        self.assert_error("src/test.c", "gText_Hello", "¡Hola, {JUGADOR}!", "unknown constant")

    def test_buffer_overflow(self):
        self.assert_error("src/test.c", "gItemsInfo[ITEM_POTION].name", "Poción extraordinariamente buena",
                          "buffer holds 20")

    def test_padded_overflow(self):
        self.assert_error("data/test.inc", "Test_Text_Name", "ROBERTO MARIO", "padded to 8")

    def test_line_too_wide(self):
        self.assert_error("data/test.inc", "Test_Text_Greeting",
                          "¡Hola!\\pBienvenido a esta prueba larguísima que no cabe en la caja",
                          "limit is 208px")

    def test_too_many_lines(self):
        self.assert_error("data/test.inc", "Test_Text_Greeting", "¡Hola!\\nUno\\nDos", "text box shows 2")

    def test_terminator_not_allowed(self):
        self.assert_error("data/test.inc", "Test_Text_Greeting", "¡Hola!$", "must not end with '$'")

    def test_literal_newline(self):
        self.assert_error("data/test.inc", "Test_Text_Greeting", "¡Hola!\nBienvenido", "literal line break")

    def test_csv_max_width_column(self):
        path = self.project.path("localization/text/src/test.c.csv")
        header, rows = csvstore.read_csv(path)
        for row in rows:
            if row["key"] == "gText_Hello":
                row["max_width"] = "40"
        csvstore.write_if_changed(path, csvstore.render_csv(header, rows))
        self.assert_error("src/test.c", "gText_Hello", "¡Hola de nuevo, {PLAYER}!", "limit is")

    # -- preproc parity ---------------------------------------------------
    @unittest.skipUnless(os.path.exists(PREPROC), "tools/preproc not built")
    def test_preproc_applies_tables(self):
        self.fx.set_translation("src/test.c", "gText_Hello", "es", "¡Hola, {PLAYER}!")
        self.fx.set_translation("src/test.c", "gItemsInfo[ITEM_POTION].name", "es", "Poción")
        self.fx.set_translation("src/test.c", "gText_Twin2", "es", "Igual")
        self.fx.set_translation("data/test.inc", "Test_Text_Greeting", "es", "¡Hola!\\pBienvenido.")
        _, validator, out = self.run_generate()
        self.assertEqual(validator.errors, [])
        # ITEM_NAME expands to the string several times on one line.
        c_src = self.project.path("src/test.c")
        with open(c_src, encoding="utf-8") as f:
            text = f.read().replace('ITEM_NAME("Potion")', '(_("Potion"), COMPOUND_STRING("Potion"))')
        with open(c_src, "w", encoding="utf-8") as f:
            f.write(text)
        tables = os.path.join(out, "strings")
        c_out = subprocess.run([PREPROC, "-t", tables, "src/test.c", "charmap.txt"], cwd=self.fx.root,
                               capture_output=True, check=True).stdout.decode()
        self.fx.write("data/test.s", '.include "data/test.inc"\n')
        a_out = subprocess.run([PREPROC, "-t", tables, "data/test.s", "charmap.txt"], cwd=self.fx.root,
                               capture_output=True, check=True)
        def c_bytes(s):
            return ", ".join(f"0x{b:02X}" for b in self.charmap.encode(s))
        self.assertIn(c_bytes("¡Hola, {PLAYER}!"), c_out)
        self.assertNotIn(c_bytes("Hello, {PLAYER}!"), c_out)
        self.assertEqual(c_out.count(c_bytes("Poción")), 2)
        self.assertIn(c_bytes("Same"), c_out)       # gText_Twin1 keeps its text
        self.assertIn(c_bytes("Igual"), c_out)      # gText_Twin2 is translated
        asm = a_out.stdout.decode()
        expected = ", ".join(f"0x{b:02X}" for b in self.charmap.encode("¡Hola!\\pBienvenido.$"))
        self.assertIn(expected, asm)
        self.assertEqual(asm.count(".byte"), 2)    # merged unit + untouched name

    @unittest.skipUnless(os.path.exists(PREPROC), "tools/preproc not built")
    def test_preproc_rejects_stale_asm_table(self):
        self.fx.set_translation("data/test.inc", "Test_Text_Greeting", "es", "¡Hola!")
        _, _, out = self.run_generate()
        self.fx.write("data/test.inc", ASM_CHANGED)
        self.fx.write("data/test.s", '.include "data/test.inc"\n')
        proc = subprocess.run([PREPROC, "-t", os.path.join(out, "strings"), "data/test.s", "charmap.txt"],
                              cwd=self.fx.root, capture_output=True)
        self.assertNotEqual(proc.returncode, 0)
        self.assertIn(b"out of date", proc.stderr)


ASM_CHANGED = 'Test_Text_Greeting::\n\t.string "Changed!\\p"\n\t.string "Welcome to the test.$"\n'


if __name__ == "__main__":
    unittest.main()
