"""Builds a small throwaway project for generator/validator tests."""

import json
import os
import shutil
import tempfile
import textwrap

from tests.helpers import ROOT

import csvstore

C_SOURCE = textwrap.dedent('''\
    const u8 gText_Hello[] = _("Hello, {PLAYER}!");
    const u8 gText_Twin1[] = _("Same");
    const u8 gText_Twin2[] = _("Same");

    const struct ItemInfo gItemsInfo[] =
    {
        [ITEM_POTION] =
        {
            .name = ITEM_NAME("Potion"),
            .description = COMPOUND_STRING("Heals."),
        },
    };

    void Foo(void)
    {
        Print(COMPOUND_STRING("Inside a function"));
    }
''')

ASM_SOURCE = textwrap.dedent('''\
    Test_Text_Greeting::
    \t.string "Hi there!\\p"
    \t.string "Welcome to the test.$"

    Test_Text_Name::
    \t.string "BOB$", 8
''')

RULES = {
    "source_language": "en",
    "languages": {
        "en": {"name": "English", "game_language": "LANGUAGE_ENGLISH"},
        "es": {"name": "Español", "game_language": "LANGUAGE_SPANISH"},
    },
    "sources": {"c": ["src/**/*.c"], "asm": ["data/**/*.inc"], "exclude": []},
    "string_macros": {"ITEM_NAME": {"max_bytes": "ITEM_NAME_LENGTH"}},
    "buffers": [],
    "placeholder_chars": {"default": 10, "PLAYER": 7},
    "text_rules": [{"files": ["data/**"], "font": "FONT_NORMAL", "max_width": 208, "max_lines": 2}],
    "skip": {"keys": []},
}


class Fixture:
    def __init__(self):
        self.root = tempfile.mkdtemp(prefix="loc_test_")
        for rel in ["charmap.txt", "src/fonts.c"]:
            self.copy(rel)
        shutil.copytree(os.path.join(ROOT, "graphics", "fonts"), os.path.join(self.root, "graphics", "fonts"))
        self.write("include/constants/global.h", "#define ITEM_NAME_LENGTH 20\n")
        self.write("src/test.c", C_SOURCE)
        self.write("data/test.inc", ASM_SOURCE)
        self.write("localization/rules.json", json.dumps(RULES, indent=4))
        self.write("localization/assets.csv", "key,context,max_width,en,es,status\n")

    def copy(self, rel):
        dst = os.path.join(self.root, rel)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        shutil.copyfile(os.path.join(ROOT, rel), dst)

    def write(self, rel, content, mode="w"):
        path = os.path.join(self.root, rel)
        os.makedirs(os.path.dirname(path), exist_ok=True)
        with open(path, mode, **({} if "b" in mode else {"encoding": "utf-8"})) as f:
            f.write(content)
        return path

    def set_translation(self, source_rel, key, lang, text):
        path = os.path.join(self.root, "localization", "text", source_rel + ".csv")
        header, rows = csvstore.read_csv(path)
        for row in rows:
            if row["key"] == key:
                row[lang] = text
                break
        else:
            raise KeyError(key)
        csvstore.write_if_changed(path, csvstore.render_csv(header, rows))

    def cleanup(self):
        shutil.rmtree(self.root, ignore_errors=True)
