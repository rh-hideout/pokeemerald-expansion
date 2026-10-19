import textwrap
import unittest

import tests.helpers  # noqa: F401  (sets up sys.path)
from asmparse import parse_asm
from cparse import parse_c


class CParseTest(unittest.TestCase):
    def keys(self, src, macros=()):
        strings, skipped = parse_c(textwrap.dedent(src), macros)
        return {s.key: s for s in strings}, skipped

    def test_named_string(self):
        keys, _ = self.keys('static const u8 sText_Hello[] = _("Hello!");\n')
        self.assertEqual(keys["sText_Hello"].text, "Hello!")
        self.assertEqual(keys["sText_Hello"].line, 1)

    def test_concatenated_literals(self):
        keys, _ = self.keys('const u8 gText_A[] = _("One\\n"\n    "Two");\n')
        self.assertEqual(keys["gText_A"].text, "One\\nTwo")

    def test_designated_initializers(self):
        keys, _ = self.keys('''
            const struct ItemInfo gItemsInfo[] =
            {
                [ITEM_POTION] =
                {
                    .name = ITEM_NAME("Potion"),
                    .description = COMPOUND_STRING("Heals 20 HP."),
                    .price = 300,
                },
            };
        ''', ["ITEM_NAME"])
        self.assertIn("gItemsInfo[ITEM_POTION].name", keys)
        self.assertEqual(keys["gItemsInfo[ITEM_POTION].name"].kind, "ITEM_NAME")
        self.assertEqual(keys["gItemsInfo[ITEM_POTION].description"].text, "Heals 20 HP.")

    def test_positional_array(self):
        keys, _ = self.keys('static const u8 *const sTexts[] = { COMPOUND_STRING("A"), COMPOUND_STRING("B") };\n')
        self.assertEqual(keys["sTexts[0]"].text, "A")
        self.assertEqual(keys["sTexts[1]"].text, "B")

    def test_fixed_size_array(self):
        keys, _ = self.keys('static const u8 sNames[][POKEMON_NAME_LENGTH + 1] = { _("Abc"), _("Def") };\n')
        self.assertEqual(keys["sNames[0]"].max_bytes, "POKEMON_NAME_LENGTH + 1")

    def test_function_strings_use_text_hash(self):
        keys, _ = self.keys('''
            void Foo(void)
            {
                Print(COMPOUND_STRING("Hi"));
                Print(COMPOUND_STRING("Bye"));
            }
        ''')
        self.assertEqual(len(keys), 2)
        self.assertTrue(all(k.startswith("Foo@") for k in keys))

    def test_define_strings_are_skipped(self):
        keys, skipped = self.keys('#define TEXT _("Hello")\nconst u8 x[] = TEXT;\n')
        self.assertEqual(keys, {})
        self.assertEqual(len(skipped), 1)

    def test_non_literal_is_skipped(self):
        keys, skipped = self.keys('const u8 x[] = COMPOUND_STRING("For "TURNS" turns");\n')
        self.assertEqual(keys, {})
        self.assertIn("non-literal", skipped[0].reason)

    def test_conditional_inside_string_gives_variants(self):
        keys, _ = self.keys('const u8 x[] = _("A"\n#if B\n"B"\n#else\n"C"\n#endif\n);\n')
        self.assertEqual(keys["x"].text, "AB")
        self.assertEqual(keys["x/alt2"].text, "AC")
        self.assertEqual(keys["x/alt2"].line, keys["x"].line)

    def test_conditional_closing_paren_in_each_branch(self):
        keys, _ = self.keys('const struct M m[] = {\n  [1] = {\n    .d = COMPOUND_STRING(\n      "A "\n    #if X\n      "B"),\n    #else\n      "C"),\n    #endif\n    .p = 1,\n  },\n};\n')
        self.assertEqual(keys["m[1].d"].text, "A B")
        self.assertEqual(keys["m[1].d/alt2"].text, "A C")

    def test_if_without_else_inside_string(self):
        keys, _ = self.keys('const u8 x[] = _("A"\n#ifdef B\n"B"\n#endif\n);\n')
        self.assertEqual(sorted(k.text for k in keys.values()), ["A", "AB"])

    def test_nested_conditional_inside_string_is_skipped(self):
        keys, skipped = self.keys('const u8 x[] = _("A"\n#if B\n#if C\n"C"\n#endif\n#endif\n);\n')
        self.assertEqual(keys, {})
        self.assertIn("conditional", skipped[0].reason)

    def test_duplicate_keys_in_if_branches(self):
        keys, _ = self.keys('#if A\nconst u8 x[] = _("A");\n#else\nconst u8 x[] = _("B");\n#endif\n')
        self.assertEqual(keys["x"].text, "A")
        self.assertEqual(keys["x~2"].text, "B")

    def test_comments_ignored(self):
        keys, _ = self.keys('// _("no")\n/* _("no") */\nconst u8 y[] = _("yes");\n')
        self.assertEqual(list(keys), ["y"])


class AsmParseTest(unittest.TestCase):
    def test_unit(self):
        units, _ = parse_asm('Foo_Text_Hi:\n\t.string "Hello\\n"\n\t.string "there.$"\n\nBar:\n')
        self.assertEqual(len(units), 1)
        u = units[0]
        self.assertEqual(u.key, "Foo_Text_Hi")
        self.assertEqual(u.text, "Hello\\nthere.")
        self.assertTrue(u.terminated)
        self.assertEqual(u.lines, [2, 3])

    def test_padded(self):
        units, _ = parse_asm('Name::\n\t.string "BOB$", 8\n')
        self.assertEqual(units[0].pad, "8")

    def test_comment(self):
        units, _ = parse_asm('L:\n\t.string "A@B$" @ comment\n')
        self.assertEqual(units[0].text, "A@B")

    def test_second_unit_after_same_label(self):
        units, _ = parse_asm('L:\n\t.string "A$"\n\t.byte 1\n\t.string "B$"\n')
        self.assertEqual([u.key for u in units], ["L", "L#2"])


if __name__ == "__main__":
    unittest.main()
