#!/usr/bin/env python3
"""Builds the Kralamoure artworks from the only official picture there is: the icon of the fishing
resource (Dofus item 600, icon 41309). Kralamoure is not a monster in Dofus, so there is no render
and no back view.

  front  the icon, cleaned (halo and soft shadow removed) and enlarged. It already sits in a 3/4
         pose with the face on the left.
  back   IMAGINED, not an Ankama artwork: rebuilt from the front. Eyes and mouth are removed, the
         mantle is lengthened over the head, the heart is taken off, the tentacles are spread and
         darkened, and the whole is mirrored so that it looks right, towards the opponent.

Reads <src>/brut/kralamoure_icone.png (downloaded from Ankama if missing) and writes
<src>/kralamoure.png and <src>/kralamoure_back.png, then:
  ../run.sh --src <src> kralamoure && ../run.sh --apply kralamoure

The pipeline only carries an existing shiny over, so the shiny palette of both Kralamoure and
Kralamoure Géant is written here, after each generation of previews that has no shiny to carry:
  python3 kralamoure.py --shiny ../preview/kralamoure ../preview/kralamoure_geant

Usage: python3 kralamoure.py [--src ../sources] [--force] | --shiny DIR...
"""
import argparse
import colorsys
import subprocess
import sys
from pathlib import Path

import numpy as np
from PIL import Image, ImageChops, ImageDraw, ImageEnhance, ImageFilter, ImageOps

HERE = Path(__file__).resolve().parent
DEFAULT_SRC = HERE.parent / "sources"
ICON_URL = "https://static.ankama.com/dofus/www/game/items/200/41309.png"
K = 4  # working scale: the icon is 200x200, the artworks 800x800

# Colours sampled on the icon
BRIM = (166, 40, 102)
HEAD = (188, 50, 125)
# Redrawn eyes, in icon pixels: (centre x, centre y, radius), (pupil x, pupil y, pupil radius)
EYES = [((71, 130, 10), (66, 131, 3)), ((98, 135, 14), (90, 136, 4))]
HEART_SCALE = 1.25


def pts(*xy):
    """Polygon given in icon pixels."""
    return [(x * K, y * K) for x, y in xy]


def fetch(url, path):
    if path.exists():
        return
    path.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run(["curl", "-sS", "-f", "-m", "30", "-A", "osatopia-sprite-import", "-o", str(path), url],
                   check=True)


def load_icon(src):
    """The icon at working scale, without its halo: faint pixels go, the glassy top stays."""
    path = src / "brut" / "kralamoure_icone.png"
    fetch(ICON_URL, path)
    im = Image.open(path).convert("RGBA")
    im = im.resize((im.width * K, im.height * K), Image.LANCZOS)
    a = np.asarray(im).astype(float)
    al = a[..., 3]
    a[..., 3] = np.where(al < 70, 0, np.clip((al - 70) * 3, 0, 255))
    return Image.fromarray(a.astype(np.uint8), "RGBA")


def mask_of(size, poly):
    m = Image.new("L", size, 0)
    ImageDraw.Draw(m).polygon(poly, fill=255)
    return m


def piece(src, poly):
    p = src.copy()
    p.putalpha(ImageChops.multiply(src.getchannel("A"), mask_of(src.size, poly)))
    return p


def shade(p, factor):
    a = p.getchannel("A")
    p = ImageEnhance.Brightness(p.convert("RGB")).enhance(factor).convert("RGBA")
    p.putalpha(a)
    return p


def paint(im, mask, colour):
    """Flat colour over a mask, keeping the picture's own alpha."""
    a = im.getchannel("A")
    out = Image.composite(Image.new("RGBA", im.size, colour + (255,)), im, mask)
    out.putalpha(a)
    return out


def eye_mask(im):
    """Whites, pupils and the reddish rim of both eyes."""
    a = np.asarray(im).astype(int)
    rgb = a[..., :3]
    eye = ((rgb.min(2) > 150) | (rgb.max(2) < 80)) & (a[..., 3] > 0)
    box = np.zeros_like(eye)
    box[112 * K:152 * K, 60 * K:118 * K] = True
    m = Image.fromarray(((eye & box) * 255).astype(np.uint8))
    return m.filter(ImageFilter.MaxFilter(4 * K + 1))


def heart_mask(im):
    """The red hearts on the mantle (not the highlight streak on its right side)."""
    a = np.asarray(im).astype(int)
    r, g, b = a[..., 0], a[..., 1], a[..., 2]
    red = (r > 215) & (g < 95) & (b < 135) & (r - b > 105)
    box = np.zeros_like(red)
    for x0, y0, x1, y1 in ((86, 38, 132, 86), (78, 60, 96, 74), (82, 84, 96, 98), (132, 78, 150, 96)):
        box[y0 * K:y1 * K, x0 * K:x1 * K] = True
    m = Image.fromarray(((red & box) * 255).astype(np.uint8))
    return m.filter(ImageFilter.MaxFilter(2 * K + 1))


def fill_rows(im, mask):
    """Replaces masked pixels by a blend of the colours on either side of the mask, row by row:
    enough to continue the mantle's vertical gradient under the heart."""
    a = np.asarray(im).astype(float).copy()
    m = np.asarray(mask) > 0
    for y in np.nonzero(m.any(1))[0]:
        xs = np.nonzero(m[y])[0]
        start = xs[0]
        for x0, x1 in zip(xs, list(xs[1:]) + [None]):
            if x1 is None or x1 != x0 + 1:
                lo, hi = max(start - 1, 0), min(x0 + 1, a.shape[1] - 1)
                t = np.linspace(0, 1, x0 - start + 3)[1:-1, None]
                a[y, start:x0 + 1, :3] = a[y, lo, :3] * (1 - t) + a[y, hi, :3] * t
                start = x1
    out = Image.fromarray(a.astype(np.uint8), "RGBA")
    soft = out.filter(ImageFilter.GaussianBlur(2 * K))
    soft.putalpha(out.getchannel("A"))
    return Image.composite(soft, out, mask.filter(ImageFilter.MaxFilter(2 * K + 1)))


def enlarge(im, mask, factor):
    """Scales the masked feature about its centre and pastes it back over the original."""
    box = mask.getbbox()
    cut = im.crop(box)
    cut.putalpha(ImageChops.multiply(cut.getchannel("A"), mask.crop(box)))
    w, h = round(cut.width * factor), round(cut.height * factor)
    cut = cut.resize((w, h), Image.LANCZOS)
    out = im.copy()
    out.alpha_composite(cut, ((box[0] + box[2] - w) // 2, (box[1] + box[3] - h) // 2))
    return out


def front(icon):
    """The sprite is about 36 px tall: at that size the icon's squinting eyes merge into one bar and
    the heart into a dot. The heart is enlarged and the eyes are redrawn bigger, pupils to the left."""
    heart = ImageChops.multiply(heart_mask(icon), mask_of(icon.size, pts((86, 38), (132, 38), (132, 86), (86, 86))))
    out = enlarge(icon, heart, HEART_SCALE)
    d = ImageDraw.Draw(out)
    for (cx, cy, r), (px, py, pr) in EYES:
        d.ellipse([(cx - r) * K, (cy - r) * K, (cx + r) * K, (cy + r) * K], fill=(255, 255, 255, 255),
                  outline=(214, 150, 176, 255), width=K)
        d.ellipse([(px - pr) * K, (py - pr) * K, (px + pr) * K, (py + pr) * K], fill=(16, 10, 14, 255))
    return out.crop(out.getbbox())


# Under this line: head and tentacles; above: mantle and its brim (the eyes straddle it)
BRIM_EDGE = [(56, 126), (66, 131), (80, 137), (96, 143), (112, 147), (128, 148), (146, 142)]


def mantle_piece(icon, hearts=True):
    """Mantle and brim alone, the eyes that overlap the brim painted over."""
    im = paint(icon, eye_mask(icon), BRIM)
    if not hearts:
        im = fill_rows(im, heart_mask(icon))
    return piece(im, pts((40, 0), (200, 0), (200, 120), *reversed(BRIM_EDGE), (50, 110)))


def back(icon):
    """Built facing left like the front, mirrored at the very end."""
    size = icon.size
    eyes = eye_mask(icon)
    mantle = mantle_piece(icon, hearts=False)
    body = paint(icon, eyes, HEAD)
    # the frown on the middle tentacle is its mouth: keep the tentacle, drop the mark
    mouth = mask_of(size, pts((84, 160), (112, 160), (112, 178), (84, 178)))
    body = paint(body, mouth, (176, 46, 116))
    left = piece(body, pts((30, 112), (56, 112), (58, 129), (72, 137), (80, 150), (74, 165), (30, 165)))
    mid = piece(body, pts((74, 140), (114, 144), (116, 190), (74, 190)))
    right = piece(body, pts((112, 140), (165, 140), (165, 190), (112, 190)))
    head = piece(body, pts((72, 126), (138, 132), (138, 158), (72, 158)))

    c = Image.new("RGBA", (size[0] + 40 * K, size[1] + 40 * K), (0, 0, 0, 0))
    o = 20 * K

    def put(p, dx=0, dy=0):
        c.alpha_composite(p, (o + round(dx * K), o + round(dy * K)))

    # seen from behind the tentacles fan out further and the far ones sit in the mantle's shadow
    put(shade(mid, 0.72), 4, -6)
    put(shade(head, 0.85), 0, 0)
    put(shade(left, 0.9), -7, 2)
    put(shade(right, 0.9), 8, 3)
    # the mantle hangs lower, over where the face was
    bb = mantle.getbbox()
    m = mantle.crop(bb)
    m = m.resize((round(m.width * 1.06), round(m.height * 1.13)), Image.LANCZOS)
    c.alpha_composite(m, (o + bb[0] - round(m.width * 0.03), o + bb[1]))
    c = ImageOps.mirror(c)
    return c.crop(c.getbbox())


def shiny_palette(colours):
    """Shiny after the Kralamoure Unique (item 1799), the turquoise variant of the same icon: pinks
    turn turquoise, the hot red of the heart and stripes turns salmon. Greys, whites, blacks and
    yellows (the Géant's eyes) are kept. Index 0 is the transparency and stays as it is."""
    out = [tuple(colours[0])]
    for r, g, b in colours[1:]:
        h, s, v = colorsys.rgb_to_hsv(r / 255, g / 255, b / 255)
        if s >= 0.08 and v >= 0.12 and not 30 / 360 < h < 290 / 360:
            if s > 0.72 and v > 0.8:
                h, s = 6 / 360, 0.52
            else:
                h, s, v = 176 / 360, s * 0.78, min(1.0, v * 1.08)
        out.append(tuple(round(c * 255) for c in colorsys.hsv_to_rgb(h, s, v)))
    return out


def write_shiny(folder):
    lines = (folder / "normal.pal").read_text().split()
    colours = [tuple(map(int, lines[i:i + 3])) for i in range(3, 51, 3)]
    rows = ["JASC-PAL", "0100", "16"] + ["%d %d %d" % c for c in shiny_palette(colours)]
    (folder / "shiny.pal").write_bytes(("\r\n".join(rows) + "\r\n").encode())
    print(f"écrit {folder}/shiny.pal")


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--src", type=Path, default=DEFAULT_SRC)
    p.add_argument("--force", action="store_true", help="écrase kralamoure.png et kralamoure_back.png")
    p.add_argument("--shiny", type=Path, nargs="+", metavar="DIR",
                   help="écrit DIR/shiny.pal à partir de DIR/normal.pal (aperçu ou graphics/pokemon), puis s'arrête")
    args = p.parse_args()
    if args.shiny:
        for folder in args.shiny:
            write_shiny(folder)
        return
    src = args.src.expanduser()
    out = {"kralamoure.png": front, "kralamoure_back.png": back}
    existing = [n for n in out if (src / n).exists()]
    if existing and not args.force:
        sys.exit(f"{', '.join(existing)} existe déjà dans {src} : rien n'est écrasé (--force pour remplacer).")
    icon = load_icon(src)
    for name, build in out.items():
        build(icon).save(src / name)
    print(f"écrit {src}/kralamoure.png (face) et kralamoure_back.png (dos imaginé)")


if __name__ == "__main__":
    main()
