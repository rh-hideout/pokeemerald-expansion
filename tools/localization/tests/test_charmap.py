import unittest

from tests.helpers import charmap
from charmap import EncodeError, fnv1a64, tokenize


class CharmapTest(unittest.TestCase):
    def test_plain_text(self):
        cm = charmap()
        self.assertEqual(cm.encode("AB"), bytes([0xBB, 0xBC]))

    def test_escapes_and_terminator(self):
        cm = charmap()
        self.assertEqual(cm.encode("A\\nB\\pC\\l$"), bytes([0xBB, 0xFE, 0xBC, 0xFB, 0xBD, 0xFA, 0xFF]))

    def test_quote_and_apostrophe(self):
        cm = charmap()
        self.assertEqual(cm.encode("'"), cm.chars["'"])
        # Like preproc, a double quote must be mapped in charmap.txt to be used.
        if '"' not in cm.chars:
            with self.assertRaises(EncodeError):
                cm.encode('\\"')

    def test_placeholders(self):
        cm = charmap()
        self.assertEqual(cm.encode("{PLAYER}"), bytes([0xFD, 0x01]))
        self.assertEqual(cm.encode("{COLOR RED}"), bytes([0xFC, 0x01, 0x04]))
        self.assertEqual(cm.encode("{PAUSE 15}"), bytes([0xFC, 0x08, 15]))
        self.assertEqual(cm.encode("{0x12}"), bytes([0x12]))
        self.assertEqual(cm.encode("{300}"), (300).to_bytes(2, "little"))

    def test_accented_letters(self):
        cm = charmap()
        for ch in "áéíóúñÑçÇàèêôâ¿¡":
            cm.encode(ch)

    def test_unknown_character(self):
        with self.assertRaises(EncodeError) as ctx:
            charmap().encode("A\u0416")
        self.assertEqual(ctx.exception.pos, 1)

    def test_unknown_constant(self):
        with self.assertRaises(EncodeError):
            charmap().encode("{NOT_A_PLACEHOLDER}")

    def test_fnv_matches_preproc(self):
        # Value computed by preproc's fnv1a over the same bytes.
        self.assertEqual(fnv1a64(b""), 0xcbf29ce484222325)
        self.assertEqual(fnv1a64(b"a"), 0xaf63dc4c8601ec8c)

    def test_tokenize(self):
        self.assertEqual(tokenize("A{PLAYER}\\nb"), ["A", "{PLAYER}", "\\n", "b"])


if __name__ == "__main__":
    unittest.main()
