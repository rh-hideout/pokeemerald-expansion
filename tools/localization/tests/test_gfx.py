import json
import os
import struct
import unittest

from tests.fixture import Fixture

import gfx
import pngio
from charmap import Charmap
from fonts import FontSet
from generate import generate
from project import Project

PALETTE = [(0, 0, 0), (255, 255, 255), (80, 80, 80), (0, 0, 255)] + [(i, i, i) for i in range(12)]


def make_image(path, width, height, fill=3, bit_depth=4):
    img = pngio.IndexedImage(width, height, bit_depth, list(PALETTE), [[fill] * width for _ in range(height)])
    os.makedirs(os.path.dirname(path), exist_ok=True)
    pngio.write_png(path, img)
    return img


def make_tilemap(path, cells, width=32, height=4):
    entries = [0x3FF] * (width * height)  # tile 0x3FF: out of range, never reserved
    for (x, y), v in cells.items():
        entries[y * width + x] = v
    with open(path, "wb") as f:
        f.write(struct.pack(f"<{len(entries)}H", *entries))


class GfxTest(unittest.TestCase):
    def setUp(self):
        self.fx = Fixture()
        self.project = Project(self.fx.root)
        self.charmap = Charmap(self.project.path("charmap.txt"))
        self.fonts = FontSet(self.fx.root, self.charmap)
        self.out = os.path.join(self.fx.root, "build", "loc", "es")
        make_image(self.project.path("graphics/menu/title.png"), 64, 16)
        # Tiles 0-3 hold the title; tile 4 is a shared border.
        make_tilemap(self.project.path("graphics/menu/title.bin"),
                     {(2, 1): 0, (3, 1): 1, (4, 1): 2, (5, 1): 3, (1, 1): 4, (6, 1): 4})
        self.fx.write("localization/assets.csv",
                      "key,context,max_width,en,es,status\nMENU_TITLE,,,TITLE,TÍTULO,\n")

    def tearDown(self):
        self.fx.cleanup()

    def set_regions(self, regions):
        self.fx.write("localization/graphics.json", json.dumps({"regions": regions}))

    def region(self, **kw):
        r = {"key": "MENU_TITLE", "image": "graphics/menu/title.png", "tilemap": "graphics/menu/title.bin",
             "rect": {"x": 2, "y": 1, "w": 4, "h": 1}, "font": "FONT_SMALL",
             "colors": {"fg": 1, "shadow": 2, "bg": 3}, "y_offset": -4}
        r.update(kw)
        return r

    def run_generate(self):
        return generate(self.project, self.charmap, self.fonts, "es", self.out)

    def test_render_text_width(self):
        rows, width = gfx.render_text(self.fonts, self.charmap, "AB", "FONT_NORMAL")
        a = self.charmap.chars["A"][0]
        b = self.charmap.chars["B"][0]
        self.assertEqual(width, self.fonts.glyph_width("FONT_NORMAL", a) + self.fonts.glyph_width("FONT_NORMAL", b))
        self.assertEqual(len(rows), 16)
        self.assertTrue(all(len(r) == width for r in rows))

    def test_region_renders_into_reserved_tiles(self):
        self.set_regions([self.region()])
        result, validator = self.run_generate()
        self.assertEqual(validator.errors, [], [d.format() for d in validator.errors])
        self.assertEqual(result.graphics, ["graphics/menu/title.png"])
        img = pngio.read_png(os.path.join(self.out, "gfx", "graphics/menu/title.png"))
        tiles = img.pixels[0:8]
        self.assertTrue(any(v == 1 for row in tiles for v in row[0:32]))   # text drawn in tiles 0-3
        self.assertTrue(all(v == 3 for row in tiles for v in row[32:40]))  # border tile untouched

    def test_source_language_not_rendered(self):
        self.set_regions([self.region()])
        result, validator = generate(self.project, self.charmap, self.fonts, "en", self.out)
        self.assertEqual(result.graphics, [])

    def test_text_too_wide_for_region(self):
        self.fx.write("localization/assets.csv",
                      "key,context,max_width,en,es,status\nMENU_TITLE,,,TITLE,TÍTULO MUY LARGO,\n")
        self.set_regions([self.region()])
        _, validator = self.run_generate()
        self.assertTrue(any("reserved area" in d.message for d in validator.errors))

    def test_shared_tile_rejected(self):
        self.set_regions([self.region(rect={"x": 1, "y": 1, "w": 2, "h": 1})])
        _, validator = self.run_generate()
        self.assertTrue(any("also used" in d.message for d in validator.errors), validator.errors)

    def test_flipped_tile_rejected(self):
        make_tilemap(self.project.path("graphics/menu/title.bin"), {(2, 1): 0x400, (3, 1): 1, (4, 1): 2, (5, 1): 3})
        self.set_regions([self.region()])
        _, validator = self.run_generate()
        self.assertTrue(any("flipped" in d.message for d in validator.errors))

    def test_pixel_rect_region(self):
        self.set_regions([self.region(tilemap=None, rect={"x": 0, "y": 8, "w": 8, "h": 1})])
        regions = gfx.load_regions(self.project)
        del regions[0]["tilemap"]
        self.set_regions(regions)
        _, validator = self.run_generate()
        self.assertEqual(validator.errors, [])

    def test_override_must_match_original(self):
        make_image(self.project.path("localization/locales/es/graphics/menu/title.png"), 32, 16)
        _, validator = self.run_generate()
        self.assertTrue(any("original is 64x16" in d.message for d in validator.errors))

    def test_override_copied_to_overlay(self):
        make_image(self.project.path("localization/locales/es/graphics/menu/title.png"), 64, 16, fill=0)
        result, validator = self.run_generate()
        self.assertEqual(validator.errors, [])
        self.assertTrue(os.path.exists(os.path.join(self.out, "gfx", "graphics/menu/title.png")))

    def test_override_of_missing_file(self):
        make_image(self.project.path("localization/locales/es/graphics/menu/nope.png"), 8, 8)
        _, validator = self.run_generate()
        self.assertTrue(any("does not exist" in d.message for d in validator.errors))

    def test_png_roundtrip(self):
        for depth in (4, 8):
            path = self.project.path(f"graphics/rt{depth}.png")
            img = make_image(path, 24, 8, fill=2, bit_depth=depth)
            img.pixels[3][5] = 1
            pngio.write_png(path, img)
            back = pngio.read_png(path)
            self.assertEqual(back.pixels, img.pixels)
            self.assertEqual(back.palette, img.palette)


if __name__ == "__main__":
    unittest.main()
