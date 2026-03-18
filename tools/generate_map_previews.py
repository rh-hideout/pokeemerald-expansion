#!/usr/bin/env python3
"""Generate tile-accurate map preview PNGs for the web editor.

Reads map layouts, tilesets, metatiles and palettes from the repo data files
and composites full-colour preview images. Only regenerates previews whose
source data has changed (based on file modification times).

Usage:
    python3 tools/generate_map_previews.py [--force] [--output DIR]
"""

import argparse
import hashlib
import json
import os
import re
import struct
import sys
from pathlib import Path

try:
    from PIL import Image
except ImportError:
    sys.exit("Pillow is required: pip install Pillow")

ROOT = Path(__file__).resolve().parent.parent
DEFAULT_OUTPUT = ROOT / "editor" / "previews"

NUM_METATILES_IN_PRIMARY = 512
NUM_METATILES_IN_PRIMARY_FRLG = 640
NUM_TILES_IN_PRIMARY = 512
NUM_TILES_IN_PRIMARY_FRLG = 640
NUM_PALS_IN_PRIMARY = 6
NUM_PALS_IN_PRIMARY_FRLG = 7
NUM_PALS_TOTAL = 13
TILE_SIZE = 8       # 8x8 pixels per tile
METATILE_SIZE = 16   # 16x16 pixels per metatile
TILES_PER_ROW = 16   # tiles.png is 128px wide = 16 tiles

# ─── Tileset name → directory mapping ────────────────────────────────────────

def build_tileset_mapping():
    """Parse graphics.h and headers.h to map gTileset_Name → directory paths."""
    mapping = {}

    # 1. Parse graphics.h for tile image paths
    tiles_to_dir = {}
    gfx_path = ROOT / "src" / "data" / "tilesets" / "graphics.h"
    if gfx_path.exists():
        gfx = gfx_path.read_text()
        for name, path in re.findall(
            r'gTilesetTiles_(\w+)\[\]\s*=\s*INCBIN_U32\("([^"]+)/tiles', gfx
        ):
            tiles_to_dir[f"gTilesetTiles_{name}"] = path

    # 2. Parse metatiles.h for metatile bin paths
    meta_to_dir = {}
    meta_path = ROOT / "src" / "data" / "tilesets" / "metatiles.h"
    if meta_path.exists():
        meta = meta_path.read_text()
        for name, path in re.findall(
            r'gMetatiles_(\w+)\[\]\s*=\s*INCBIN_U16\("([^"]+)/metatiles\.bin', meta
        ):
            meta_to_dir[f"gMetatiles_{name}"] = path

    # 3. Parse headers.h to get per-tileset .tiles / .metatiles references
    headers_path = ROOT / "src" / "data" / "tilesets" / "headers.h"
    if headers_path.exists():
        headers = headers_path.read_text()
        for m in re.finditer(
            r'const struct Tileset (gTileset_\w+)\s*=\s*\{([^}]+)\}',
            headers, re.DOTALL,
        ):
            ts_name = m.group(1)
            body = m.group(2)
            fields = dict(re.findall(r'\.(\w+)\s*=\s*(\w+)', body))
            tiles_ref = fields.get("tiles", "")
            meta_ref = fields.get("metatiles", "")
            tiles_dir = tiles_to_dir.get(tiles_ref)
            meta_dir = meta_to_dir.get(meta_ref)
            if tiles_dir and meta_dir:
                mapping[ts_name] = {"tiles_dir": tiles_dir, "meta_dir": meta_dir}
            elif tiles_dir:
                mapping[ts_name] = {"tiles_dir": tiles_dir, "meta_dir": tiles_dir}

    # 4. Fallback: scan filesystem for any tilesets not yet mapped
    for kind in ("primary", "secondary"):
        base = ROOT / "data" / "tilesets" / kind
        if not base.exists():
            continue
        for d in sorted(base.iterdir()):
            if not d.is_dir():
                continue
            tiles_png = d / "tiles.png"
            metatiles_bin = d / "metatiles.bin"
            if tiles_png.exists() and metatiles_bin.exists():
                # Build the expected gTileset name
                parts = d.name.split("_")
                ts_suffix = "".join(w.capitalize() for w in parts)
                ts_name = f"gTileset_{ts_suffix}"
                if ts_name not in mapping:
                    rel = str(d.relative_to(ROOT))
                    mapping[ts_name] = {"tiles_dir": rel, "meta_dir": rel}

    return mapping


# ─── Palette loading ─────────────────────────────────────────────────────────

def load_palettes(tileset_dir):
    """Load 16 palettes from JASC-PAL .pal files. Returns list of 16 palettes,
    each palette is a list of 16 (R, G, B) tuples."""
    palettes = []
    pal_dir = ROOT / tileset_dir / "palettes"
    for i in range(16):
        pal_file = pal_dir / f"{i:02d}.pal"
        if not pal_file.exists():
            palettes.append([(0, 0, 0)] * 16)
            continue
        colors = []
        lines = pal_file.read_text().strip().splitlines()
        # JASC-PAL format: header, version, count, then R G B lines
        for line in lines[3:19]:
            parts = line.strip().split()
            if len(parts) >= 3:
                colors.append((int(parts[0]), int(parts[1]), int(parts[2])))
        while len(colors) < 16:
            colors.append((0, 0, 0))
        palettes.append(colors)
    return palettes


# ─── Tile pixel extraction ───────────────────────────────────────────────────

def load_tile_pixels(tiles_png_path):
    """Load tiles.png and return the raw indexed pixel data + image dimensions.
    Returns (width_in_tiles, height_in_tiles, pixel_indices) where
    pixel_indices[tile_id] is an 8x8 list of palette indices."""
    img = Image.open(tiles_png_path)
    # Ensure we have the indexed (palette) mode
    if img.mode != "P":
        img = img.convert("P")
    pixels = img.load()
    w, h = img.size
    tiles_per_row = w // TILE_SIZE
    num_rows = h // TILE_SIZE
    total_tiles = tiles_per_row * num_rows

    tile_data = []
    for tid in range(total_tiles):
        col = tid % tiles_per_row
        row = tid // tiles_per_row
        px0 = col * TILE_SIZE
        py0 = row * TILE_SIZE
        tile_pixels = []
        for y in range(TILE_SIZE):
            row_pixels = []
            for x in range(TILE_SIZE):
                row_pixels.append(pixels[px0 + x, py0 + y])
            tile_pixels.append(row_pixels)
        tile_data.append(tile_pixels)

    return tile_data


# ─── Metatile loading ────────────────────────────────────────────────────────

def load_metatiles(metatiles_bin_path):
    """Load metatiles from a .bin file. Each metatile is 8 u16 tile entries.
    Returns list of metatiles, each is a list of 8 (tile_id, hflip, vflip, pal) tuples."""
    data = Path(metatiles_bin_path).read_bytes()
    num_metatiles = len(data) // 16  # 8 entries * 2 bytes
    metatiles = []
    for i in range(num_metatiles):
        entries = struct.unpack_from("<8H", data, i * 16)
        parsed = []
        for e in entries:
            tile_id = e & 0x3FF
            hflip = (e >> 10) & 1
            vflip = (e >> 11) & 1
            pal = (e >> 12) & 0xF
            parsed.append((tile_id, hflip, vflip, pal))
        metatiles.append(parsed)
    return metatiles


# ─── Render a single metatile to RGBA pixels ────────────────────────────────

def render_metatile(metatile_entries, tile_data, palettes):
    """Render a 16x16 metatile to an RGBA pixel buffer."""
    result = Image.new("RGBA", (METATILE_SIZE, METATILE_SIZE), (0, 0, 0, 0))

    # Bottom layer = entries 0-3, Top layer = entries 4-7
    # Each layer: TL(0), TR(1), BL(2), BR(3)
    positions = [(0, 0), (8, 0), (0, 8), (8, 8)]

    for layer in range(2):
        for slot in range(4):
            tile_id, hflip, vflip, pal_idx = metatile_entries[layer * 4 + slot]
            px, py = positions[slot]

            if tile_id >= len(tile_data):
                continue

            palette = palettes[pal_idx] if pal_idx < len(palettes) else [(0, 0, 0)] * 16
            tile_pixels = tile_data[tile_id]

            for ty in range(TILE_SIZE):
                for tx in range(TILE_SIZE):
                    src_y = (TILE_SIZE - 1 - ty) if vflip else ty
                    src_x = (TILE_SIZE - 1 - tx) if hflip else tx
                    pal_index = tile_pixels[src_y][src_x]

                    # Palette index 0 is transparent
                    if pal_index == 0 and layer == 1:
                        continue

                    color = palette[pal_index] if pal_index < len(palette) else (0, 0, 0)
                    result.putpixel((px + tx, py + ty), (*color, 255))

    return result


# ─── Map rendering ───────────────────────────────────────────────────────────

def render_map(layout, tileset_mapping):
    """Render a complete map layout to a PIL Image."""
    width = layout["width"]
    height = layout["height"]
    primary_name = layout["primary_tileset"]
    secondary_name = layout["secondary_tileset"]
    is_frlg = layout.get("layout_version") == "firered"

    if primary_name not in tileset_mapping or secondary_name not in tileset_mapping:
        return None

    primary_info = tileset_mapping[primary_name]
    secondary_info = tileset_mapping[secondary_name]

    num_primary_metatiles = NUM_METATILES_IN_PRIMARY_FRLG if is_frlg else NUM_METATILES_IN_PRIMARY
    num_primary_tiles = NUM_TILES_IN_PRIMARY_FRLG if is_frlg else NUM_TILES_IN_PRIMARY
    num_primary_pals = NUM_PALS_IN_PRIMARY_FRLG if is_frlg else NUM_PALS_IN_PRIMARY

    # Load tilesets
    primary_tiles = load_tile_pixels(ROOT / primary_info["tiles_dir"] / "tiles.png")
    secondary_tiles = load_tile_pixels(ROOT / secondary_info["tiles_dir"] / "tiles.png")
    primary_palettes = load_palettes(primary_info["tiles_dir"])
    secondary_palettes = load_palettes(secondary_info["tiles_dir"])

    # Merge tiles: the GBA loads primary tiles at offset 0 and secondary tiles
    # at offset NUM_TILES_IN_PRIMARY.  Metatile entries in both tilesets reference
    # absolute tile IDs in this combined space.
    merged_tiles = list(primary_tiles)
    # Pad primary tiles to the expected count
    while len(merged_tiles) < num_primary_tiles:
        merged_tiles.append([[0] * TILE_SIZE for _ in range(TILE_SIZE)])
    merged_tiles.extend(secondary_tiles)

    # Merge palettes: primary tileset provides palette slots 0..(num_primary_pals-1),
    # secondary provides slots num_primary_pals..(NUM_PALS_TOTAL-1).
    # Metatile entries reference absolute palette slot indices.
    merged_palettes = []
    for i in range(NUM_PALS_TOTAL):
        if i < num_primary_pals:
            merged_palettes.append(primary_palettes[i] if i < len(primary_palettes) else [(0, 0, 0)] * 16)
        else:
            sec_idx = i - num_primary_pals
            merged_palettes.append(secondary_palettes[sec_idx] if sec_idx < len(secondary_palettes) else [(0, 0, 0)] * 16)
    # Pad to 16 slots for safety
    while len(merged_palettes) < 16:
        merged_palettes.append([(0, 0, 0)] * 16)

    primary_metatiles = load_metatiles(ROOT / primary_info["meta_dir"] / "metatiles.bin")
    secondary_metatiles = load_metatiles(ROOT / secondary_info["meta_dir"] / "metatiles.bin")

    # Load map blockdata
    map_bin = ROOT / layout["blockdata_filepath"]
    if not map_bin.exists():
        return None
    blockdata = map_bin.read_bytes()
    blocks = struct.unpack("<" + "H" * (len(blockdata) // 2), blockdata)

    if len(blocks) < width * height:
        return None

    # Pre-render all metatiles
    metatile_cache = {}

    img = Image.new("RGB", (width * METATILE_SIZE, height * METATILE_SIZE), (0, 0, 0))

    for y in range(height):
        for x in range(width):
            idx = y * width + x
            block = blocks[idx]
            metatile_id = block & 0x3FF

            if metatile_id in metatile_cache:
                mt_img = metatile_cache[metatile_id]
            elif metatile_id < num_primary_metatiles:
                # Primary tileset metatile
                if metatile_id >= len(primary_metatiles):
                    continue
                mt_img = render_metatile(
                    primary_metatiles[metatile_id],
                    merged_tiles, merged_palettes,
                )
                metatile_cache[metatile_id] = mt_img
            else:
                # Secondary tileset metatile
                sec_id = metatile_id - num_primary_metatiles
                if sec_id >= len(secondary_metatiles):
                    continue
                mt_img = render_metatile(
                    secondary_metatiles[sec_id],
                    merged_tiles, merged_palettes,
                )
                metatile_cache[metatile_id] = mt_img

            img.paste(mt_img, (x * METATILE_SIZE, y * METATILE_SIZE))

    return img


# ─── Change detection ────────────────────────────────────────────────────────

def source_hash(layout, tileset_mapping):
    """Compute a hash of all source files that contribute to a map preview."""
    h = hashlib.sha256()
    paths = [ROOT / layout["blockdata_filepath"]]

    for ts_name in (layout["primary_tileset"], layout["secondary_tileset"]):
        info = tileset_mapping.get(ts_name)
        if not info:
            continue
        for d in set([info["tiles_dir"], info["meta_dir"]]):
            paths.append(ROOT / d / "tiles.png")
            paths.append(ROOT / d / "metatiles.bin")
            pal_dir = ROOT / d / "palettes"
            if pal_dir.exists():
                for p in sorted(pal_dir.glob("*.pal")):
                    paths.append(p)

    for p in paths:
        if p.exists():
            h.update(str(p).encode())
            h.update(str(p.stat().st_mtime_ns).encode())
    return h.hexdigest()[:16]


# ─── Map name derivation ────────────────────────────────────────────────────

def get_map_dir_for_layout(layout_id, maps_dir):
    """Find which map directory uses a given layout ID."""
    for d in sorted(maps_dir.iterdir()):
        map_json = d / "map.json"
        if not map_json.exists():
            continue
        try:
            m = json.loads(map_json.read_text())
            if m.get("layout") == layout_id:
                return d.name
        except (json.JSONDecodeError, KeyError):
            continue
    return None


# ─── Main ────────────────────────────────────────────────────────────────────

def main():
    parser = argparse.ArgumentParser(description="Generate map preview images")
    parser.add_argument("--force", action="store_true", help="Regenerate all previews")
    parser.add_argument("--output", type=Path, default=DEFAULT_OUTPUT, help="Output directory")
    parser.add_argument("--max-size", type=int, default=256, help="Max dimension in pixels (thumbnails)")
    parser.add_argument("--full-size", action="store_true", help="Also save full-size images (no downscaling)")
    parser.add_argument("maps", nargs="*", help="Only generate for specific map directories")
    args = parser.parse_args()

    args.output.mkdir(parents=True, exist_ok=True)

    # Load data
    layouts_json = ROOT / "data" / "layouts" / "layouts.json"
    layouts = json.loads(layouts_json.read_text())["layouts"]
    tileset_mapping = build_tileset_mapping()
    maps_dir = ROOT / "data" / "maps"

    # Build layout_id -> map_dir_name mapping
    layout_to_maps = {}
    for d in sorted(maps_dir.iterdir()):
        map_json = d / "map.json"
        if not map_json.exists():
            continue
        try:
            m = json.loads(map_json.read_text())
            lid = m.get("layout")
            if lid:
                layout_to_maps.setdefault(lid, []).append(d.name)
        except (json.JSONDecodeError, KeyError):
            continue

    # Hash cache file
    hash_cache_path = args.output / ".hashes.json"
    cached_hashes = {}
    if hash_cache_path.exists() and not args.force:
        try:
            cached_hashes = json.loads(hash_cache_path.read_text())
        except (json.JSONDecodeError, KeyError):
            pass

    generated = 0
    skipped = 0
    failed = 0
    new_hashes = {}

    for layout in layouts:
        lid = layout["id"]
        map_dirs = layout_to_maps.get(lid, [])

        if not map_dirs:
            continue

        # If specific maps requested, filter
        if args.maps and not any(d in args.maps for d in map_dirs):
            continue

        # Skip layouts with invalid tilesets
        if layout["primary_tileset"] not in tileset_mapping:
            continue
        if layout["secondary_tileset"] not in tileset_mapping:
            continue

        # Use first map directory name as the output filename
        out_name = map_dirs[0]
        out_path = args.output / f"{out_name}.png"

        # Check if regeneration needed
        h = source_hash(layout, tileset_mapping)
        if not args.force and cached_hashes.get(out_name) == h and out_path.exists():
            new_hashes[out_name] = h
            skipped += 1
            continue

        try:
            img = render_map(layout, tileset_mapping)
            if img is None:
                failed += 1
                continue

            # Save full-size version if requested
            if args.full_size:
                full_dir = args.output / "full"
                full_dir.mkdir(parents=True, exist_ok=True)
                img.save(full_dir / f"{out_name}.png", optimize=True)
                for extra_dir in map_dirs[1:]:
                    img.save(full_dir / f"{extra_dir}.png", optimize=True)

            # Resize to thumbnail
            w, h_px = img.size
            if w > args.max_size or h_px > args.max_size:
                scale = min(args.max_size / w, args.max_size / h_px)
                new_w = max(1, int(w * scale))
                new_h = max(1, int(h_px * scale))
                img = img.resize((new_w, new_h), Image.NEAREST)

            img.save(out_path, optimize=True)

            # Also save for any other maps sharing this layout
            for extra_dir in map_dirs[1:]:
                extra_path = args.output / f"{extra_dir}.png"
                img.save(extra_path, optimize=True)

            new_hashes[out_name] = h
            generated += 1
            print(f"  Generated: {out_name} ({img.size[0]}x{img.size[1]})")

        except Exception as e:
            print(f"  FAILED: {out_name}: {e}", file=sys.stderr)
            failed += 1

    # Save hash cache
    new_hashes.update({k: v for k, v in cached_hashes.items() if k not in new_hashes})
    hash_cache_path.write_text(json.dumps(new_hashes, indent=2))

    print(f"\nDone: {generated} generated, {skipped} unchanged, {failed} failed")


if __name__ == "__main__":
    main()
