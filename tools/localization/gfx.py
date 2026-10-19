"""Localized graphics.

1. Whole-image overrides: localization/locales/<lang>/<path>.png (or .pal)
   replaces <path>.png for that language.
2. Reserved text regions: localization/graphics.json describes rectangles,
   in tilemap cells or image pixels, that are redrawn with the text of a key
   from localization/assets.csv using the game's fonts.

Both produce files in the overlay directory build/loc/<lang>/gfx/, which
preproc and scaninc substitute for the originals (-L).
"""

import glob
import json
import os
import re
import shutil
import struct

import csvstore
import pngio
from fonts import FONTS, GLYPH_CELL
from charmap import EncodeError, tokenize
from project import ASSETS_CSV, GRAPHICS_PATH, LOCALES_DIR

TILE = 8

# Font sheet palette indices (graphics/fonts/latin_*.png).
FONT_PIXEL_FG = 1
FONT_PIXEL_SHADOW = 2
FONT_PIXEL_BG = 3


class GfxError(Exception):
    pass


def load_regions(project):
    path = project.path(GRAPHICS_PATH)
    if not os.path.exists(path):
        return []
    with open(path, encoding="utf-8") as f:
        data = json.load(f)
    return data.get("regions", [])


def load_assets(project):
    header, rows = csvstore.read_csv(project.path(ASSETS_CSV))
    return {r["key"]: r for r in rows}


# ---------------------------------------------------------------------------
# Tilemaps

def read_tilemap(path):
    with open(path, "rb") as f:
        data = f.read()
    n = len(data) // 2
    return list(struct.unpack(f"<{n}H", data[:n * 2]))


def tilemap_cell(entries, width_cells, x, y):
    v = entries[y * width_cells + x]
    return {"tile": v & 0x3FF, "hflip": bool(v & 0x400), "vflip": bool(v & 0x800), "pal": v >> 12}


# ---------------------------------------------------------------------------
# Text rendering

def render_text(fonts, charmap, text, font):
    """Renders a single line of text to rows of font-pixel values
    (0 = transparent, FONT_PIXEL_*) and returns (rows, width)."""
    glyph_rows = [[] for _ in range(GLYPH_CELL)]
    width = 0
    cur_font = font
    for tok in tokenize(text):
        if tok.startswith("{"):
            name = tok[1:-1].split()[0] if tok[1:-1].split() else ""
            if name in FONTS:
                cur_font = name
                continue
            seq = charmap.constants.get(name)
            if seq is None or seq[0] in (0xFC, 0xFD, 0xF7, 0xF8, 0xF9):
                continue
            codes = list(seq)
        elif tok.startswith("\\"):
            continue
        else:
            seq = charmap.chars.get(tok)
            if not seq:
                raise EncodeError(f"character '{tok}' is not in charmap.txt")
            codes = list(seq)
        for code in codes:
            w = fonts.glyph_width(cur_font, code)
            cell = fonts.glyph_pixels(cur_font, code)
            for y in range(GLYPH_CELL):
                glyph_rows[y].extend(cell[y][:w])
            width += w
    return glyph_rows, width


def draw_region(img, region, rows, text_width, cells):
    """Draws rendered text into 'cells' [(tile_index, cx, cy)] of 'img'.

    'cx', 'cy' are the cell's position inside the region (in tiles)."""
    colors = region["colors"]
    bg = colors["bg"]
    cmap = {FONT_PIXEL_FG: colors["fg"], FONT_PIXEL_SHADOW: colors.get("shadow", colors["fg"])}
    cols = region["rect"]["w"] * TILE
    lines = region["rect"]["h"] * TILE
    align = region.get("align", "left")
    x0 = region.get("x_offset", 0)
    if align == "center":
        x0 += (cols - text_width) // 2
    elif align == "right":
        x0 += cols - text_width
    y0 = region.get("y_offset", 0)
    canvas = [[bg] * cols for _ in range(lines)]
    for gy, row in enumerate(rows):
        y = gy + y0
        if not (0 <= y < lines):
            continue
        for gx, v in enumerate(row):
            x = gx + x0
            if 0 <= x < cols and v in cmap:
                canvas[y][x] = cmap[v]
    tiles_per_row = img.width // TILE
    for tile, cx, cy in cells:
        tx = (tile % tiles_per_row) * TILE
        ty = (tile // tiles_per_row) * TILE
        for y in range(TILE):
            for x in range(TILE):
                img.pixels[ty + y][tx + x] = canvas[cy * TILE + y][cx * TILE + x]


def region_cells(project, region, img):
    """Resolves the region to [(tile index, cx, cy)] and validates it."""
    rect = region["rect"]
    w, h = rect["w"], rect["h"]
    tiles_per_row = img.width // TILE
    num_tiles = tiles_per_row * (img.height // TILE)
    if "tilemap" not in region:
        if rect["x"] % TILE or rect["y"] % TILE:
            raise GfxError("pixel rect must be tile aligned (multiples of 8)")
        cells = []
        for cy in range(h):
            for cx in range(w):
                tx = rect["x"] // TILE + cx
                ty = rect["y"] // TILE + cy
                if tx >= tiles_per_row or ty >= img.height // TILE:
                    raise GfxError(f"rect exceeds the image ({img.width}x{img.height})")
                cells.append((ty * tiles_per_row + tx, cx, cy))
        return cells

    tilemap_path = project.path(region["tilemap"])
    entries = read_tilemap(tilemap_path)
    map_w = region.get("tilemap_width", 32)
    base = region.get("tile_base", 0)
    cells = []
    used = {}
    inside = set()
    for cy in range(h):
        for cx in range(w):
            x, y = rect["x"] + cx, rect["y"] + cy
            if y * map_w + x >= len(entries):
                raise GfxError(f"rect exceeds the tilemap ({len(entries)} cells)")
            cell = tilemap_cell(entries, map_w, x, y)
            if cell["hflip"] or cell["vflip"]:
                raise GfxError(f"tilemap cell ({x},{y}) is flipped; reserved tiles must not be flipped")
            tile = cell["tile"] - base
            if not (0 <= tile < num_tiles):
                raise GfxError(f"tilemap cell ({x},{y}) references tile {cell['tile']:#x}, outside {region['image']}")
            if tile in used:
                raise GfxError(f"tilemap cells {used[tile]} and ({x},{y}) share tile {cell['tile']:#x}; "
                               "reserve unique tiles for localized text")
            used[tile] = (x, y)
            inside.add(y * map_w + x)
            cells.append((tile, cx, cy))
    # Every tilemap that uses this image must only show the reserved tiles
    # inside the reserved rect.
    shared = region.get("check_tilemaps", [region["tilemap"]])
    for tm in shared:
        for idx, v in enumerate(read_tilemap(project.path(tm))):
            if tm == region["tilemap"] and idx in inside:
                continue
            t = (v & 0x3FF) - base
            if t in used:
                raise GfxError(f"reserved tile {t + base:#x} is also used at cell ({idx % map_w},{idx // map_w}) of {tm}")
    return cells


_MK_RULE_TARGETS = None


def custom_make_rule(project, rel):
    """Returns the *.mk file with a dedicated rule for rel's converted file."""
    global _MK_RULE_TARGETS
    if _MK_RULE_TARGETS is None:
        _MK_RULE_TARGETS = {}
        for mk in sorted(glob.glob(project.path("*.mk"))):
            with open(mk, encoding="utf-8") as f:
                text = f.read()
            variables = dict(re.findall(r"^(\w+)\s*:?=\s*(\S+)\s*$", text, re.M))
            text = re.sub(r"\$\((\w+)\)", lambda m: variables.get(m.group(1), m.group(0)), text)
            for m in re.finditer(r"^([^\s:#=$][^:=\n]*?)\s*:(?!=)", text, re.M):
                for target in m.group(1).split():
                    _MK_RULE_TARGETS.setdefault(target.split(".")[0], os.path.basename(mk))
    return _MK_RULE_TARGETS.get(rel.rsplit(".", 1)[0])


def build_overlay(project, lang, fonts, charmap, validator, out_dir):
    """Writes the language's graphics overlay; returns the files written."""
    written = []
    source_lang = project.source_language

    # 1. Whole-image overrides.
    locale_dir = project.path(LOCALES_DIR, lang)
    overrides = {}
    for path in sorted(glob.glob(os.path.join(locale_dir, "**", "*"), recursive=True)):
        if not os.path.isfile(path) or not path.endswith((".png", ".pal")):
            continue
        rel = os.path.relpath(path, locale_dir).replace(os.sep, "/")
        where = project.rel(path)
        orig = project.path(rel)
        if not os.path.exists(orig):
            validator.error(where, rel, lang, f"overrides '{rel}', which does not exist")
            continue
        if rel.endswith(".png"):
            try:
                a = pngio.read_png(orig)
                b = pngio.read_png(path)
            except pngio.PngError as e:
                validator.error(where, rel, lang, str(e))
                continue
            if (a.width, a.height) != (b.width, b.height):
                validator.error(where, rel, lang, f"is {b.width}x{b.height}, original is {a.width}x{a.height}")
                continue
            if a.bit_depth != b.bit_depth:
                validator.error(where, rel, lang, f"has bit depth {b.bit_depth}, original has {a.bit_depth}")
                continue
            if len(b.palette) > len(a.palette):
                validator.error(where, rel, lang, f"has {len(b.palette)} palette colors, original has {len(a.palette)}")
                continue
            if a.palette != b.palette[:len(a.palette)]:
                validator.warn(where, rel, lang, "palette differs from the original (shared palettes may break)")
        rule_file = custom_make_rule(project, rel)
        if rule_file:
            validator.warn(where, rel, lang, f"has a custom conversion rule in {rule_file}; "
                           "the localized copy is converted with the generic rule")
        overrides[rel] = path

    # 2. Reserved text regions (drawn on top of an override when present).
    assets = load_assets(project)
    rendered = {}
    for region in load_regions(project):
        key = region["key"]
        where = project.rel(project.path(GRAPHICS_PATH))
        row = assets.get(key)
        if row is None:
            validator.error(where, key, lang, f"region key not found in {ASSETS_CSV}")
            continue
        if lang == source_lang and not region.get("render_source_language", False):
            continue
        text = row.get(lang, "")
        if not text:
            validator.warn(project.rel(project.path(ASSETS_CSV)), key, lang, "missing translation (graphic keeps its original text)")
            continue
        image_rel = region["image"]
        try:
            img = rendered.get(image_rel)
            if img is None:
                img = pngio.read_png(overrides.get(image_rel, project.path(image_rel)))
            font = region.get("font", "FONT_NORMAL")
            src_text = row.get(source_lang, "")
            max_width = region["rect"]["w"] * TILE - region.get("x_offset", 0)
            if row.get("max_width"):
                max_width = min(max_width, int(row["max_width"]))
            if validator.check_text(project.rel(project.path(ASSETS_CSV)), key, lang, text, src_text) is None:
                continue
            cells = region_cells(project, region, img)
            rows, width = render_text(fonts, charmap, text, font)
            if width > max_width:
                validator.error(project.rel(project.path(ASSETS_CSV)), key, lang,
                                f"text is {width}px wide in {font}, the reserved area is {max_width}px")
                continue
            draw_region(img, region, rows, width, cells)
            rendered[image_rel] = img
        except (GfxError, EncodeError, pngio.PngError, OSError) as e:
            validator.error(where, key, lang, str(e))

    # Write the overlay.
    for rel, src in overrides.items():
        if rel in rendered:
            continue
        _copy_if_changed(src, os.path.join(out_dir, rel))
        written.append(rel)
    for rel, img in rendered.items():
        dst = os.path.join(out_dir, rel)
        tmp = dst + ".tmp.png"
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        pngio.write_png(tmp, img)
        _replace_if_changed(tmp, dst)
        written.append(rel)

    # Remove stale overlay files.
    keep = {os.path.normpath(os.path.join(out_dir, r)) for r in written}
    if os.path.isdir(out_dir):
        for dirpath, _, files in os.walk(out_dir):
            for name in files:
                full = os.path.normpath(os.path.join(dirpath, name))
                if full not in keep and name.endswith((".png", ".pal")):
                    os.remove(full)
    return sorted(written)


def _copy_if_changed(src, dst):
    if os.path.exists(dst):
        with open(src, "rb") as a, open(dst, "rb") as b:
            if a.read() == b.read():
                return False
    os.makedirs(os.path.dirname(dst), exist_ok=True)
    shutil.copyfile(src, dst)
    return True


def _replace_if_changed(tmp, dst):
    if os.path.exists(dst):
        with open(tmp, "rb") as a, open(dst, "rb") as b:
            if a.read() == b.read():
                os.remove(tmp)
                return False
    os.replace(tmp, dst)
    return True
