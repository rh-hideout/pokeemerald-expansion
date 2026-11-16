#!/usr/bin/env python3
"""Composes the Kralamoure Géant artworks. In Dofus the boss has no sprite of its own: its look
({838}) is the brown shell of its lair, identical in all 4 directions, and the fight is carried by
four tentacle summons. This script builds the creature the illustrations show instead:

  body       the Kralamoure's mantle and brim (see kralamoure.py), widened, enlarged and darkened
  face       DRAWN here after the official illustrations: heavy brow, pale green eyes with yellow
             irises, a siphon for a mouth
  tentacles  the real renders of the boss's summons, look {835} (Tentacule Primaire / Tertiaire,
             curled) and look {1083} (Secondaire / Quaternaire, straight), recoloured from brown to
             the Kralamoure's pink
  colours    the finished picture is then pulled part of the way back to the boss's reddish
             brown (toward_dofus), so that the Géant is less fuchsia than the Kralamoure
  back       IMAGINED: the heartless mantle of the Kralamoure's back and the back renders of the
             same tentacles, mirrored so that it looks right, towards the opponent

Reads <src>/brut/kralamoure_icone.png and <src>/brut/tentacule_{enroule,droit}_{face,dos}.png
(downloaded from Ankama if missing) and writes <src>/kralamoure_geant_pose.png and
<src>/kralamoure_geant_pose_back.png, which overrides.json points kralamoure_geant at ("source"),
then: ../run.sh --src <src> kralamoure_geant && ../run.sh --apply kralamoure_geant

Usage: python3 kralamoure_geant.py [--src ../sources] [--force]
"""
import argparse
import colorsys
import sys
from pathlib import Path

import numpy as np
from PIL import Image, ImageChops, ImageDraw, ImageEnhance, ImageFilter, ImageOps

sys.path.insert(0, str(Path(__file__).resolve().parent))
import kralamoure as base  # noqa: E402

RENDERER = "https://static.ankama.com/dofus/renderer/look/{look}/full/{dir}/600_600-10.png"
TENTACLES = {  # file stem -> (look, direction)
    "tentacule_enroule_face": ("{835}", 1), "tentacule_enroule_dos": ("{835}", 7),
    "tentacule_droit_face": ("{1083}", 1), "tentacule_droit_dos": ("{1083}", 7),
}
DARK = 0.84  # the Géant is a little darker than the Kralamoure
PINK_HUE = 328 / 360
DOFUS_HUE_SHIFT = 15 / 360  # fuchsia (328°) towards a brick rose (343°)
DOFUS_SATURATION = 0.84
W, H, GROUND = 1700, 1500, 1400

SKIN = (150, 38, 98)
SKIN_DARK = (112, 26, 70)
SKIN_LIGHT = (196, 62, 134)
EYE_WHITE = (226, 232, 168)
IRIS = (240, 196, 40)
INK = (22, 10, 16)


def shade(p, factor):
    a = p.getchannel("A")
    p = ImageEnhance.Brightness(p.convert("RGB")).enhance(factor).convert("RGBA")
    p.putalpha(a)
    return p


def tentacle(src, stem):
    """A boss tentacle without its water ripple and shadow, brown turned to pink (suckers and
    underside stay pale)."""
    path = src / "brut" / f"{stem}.png"
    look, direction = TENTACLES[stem]
    base.fetch(RENDERER.format(look=look.encode().hex(), dir=direction), path)
    a = np.asarray(Image.open(path).convert("RGBA")).astype(float) / 255
    r, g, b, al = a[..., 0], a[..., 1], a[..., 2], a[..., 3]
    ripple = (g > r + 0.02) | (al < 0.75)
    hsv = np.vectorize(colorsys.rgb_to_hsv)(r, g, b)
    s, v = hsv[1], hsv[2]
    skin = s > 0.5  # brown skin and mud; the rest is the beige underside
    s2 = np.where(skin, np.clip(s * 1.05, 0, 1), s * 0.55)
    v2 = np.where(skin, np.clip(v * 1.5, 0, 1), np.clip(v * 1.3, 0, 1))
    rgb = np.vectorize(colorsys.hsv_to_rgb)(np.full_like(s, PINK_HUE), s2, v2)
    out = np.dstack([*rgb, np.where(ripple, 0, 1.0)])
    im = Image.fromarray((out * 255).astype(np.uint8), "RGBA")
    # the suckers are under 2 px once in the sprite and turn into noise: soften the underside
    soft = im.filter(ImageFilter.GaussianBlur(7))
    soft.putalpha(im.getchannel("A"))
    under = Image.fromarray(((~skin & ~ripple) * 255).astype(np.uint8)).filter(ImageFilter.MinFilter(3))
    im = Image.composite(soft, im, under)
    return shade(im.crop(im.getbbox()), DARK)


def toward_dofus(im):
    """Pulls the pinks part of the way to the reddish brown of the Dofus boss: hue turned towards
    red and saturation lowered. Yellows (the eyes) and greys are left alone."""
    a = np.asarray(im).astype(float) / 255
    h, s, v = np.vectorize(colorsys.rgb_to_hsv)(a[..., 0], a[..., 1], a[..., 2])
    pink = ((h > 280 / 360) | (h < 20 / 360)) & (s > 0.08)
    h = np.where(pink, (h + DOFUS_HUE_SHIFT) % 1.0, h)
    s = np.where(pink & (s < 0.8), s * DOFUS_SATURATION, s)  # the heart keeps its hot red
    rgb = np.vectorize(colorsys.hsv_to_rgb)(h, s, v)
    return Image.fromarray((np.dstack([*rgb, a[..., 3]]) * 255).round().astype(np.uint8), "RGBA")


def xf(p, scale=1.0, flip=False, rot=0, dark=1.0, sx=1.0):
    p = p.resize((max(1, round(p.width * scale * sx)), max(1, round(p.height * scale))), Image.LANCZOS)
    if flip:
        p = ImageOps.mirror(p)
    if rot:
        p = p.rotate(rot, Image.BICUBIC, expand=True)
    return shade(p, dark) if dark != 1.0 else p


class Canvas:
    def __init__(self):
        self.im = Image.new("RGBA", (W, H), (0, 0, 0, 0))
        self.d = ImageDraw.Draw(self.im)

    def put(self, p, x, bottom=GROUND):
        self.im.alpha_composite(p, (round(x), round(bottom - p.height)))

    def ellipse(self, cx, cy, rx, ry, fill, outline=None, width=0):
        self.d.ellipse([cx - rx, cy - ry, cx + rx, cy + ry], fill=fill + (255,),
                       outline=outline + (255,) if outline else None, width=width)

    def poly(self, pts, fill):
        self.d.polygon(pts, fill=fill + (255,))

    def cropped(self, mirror=False):
        im = ImageOps.mirror(self.im) if mirror else self.im
        return toward_dofus(im.crop(im.getbbox()))


def mantle(icon, hearts):
    """The Kralamoure's mantle, squat and massive."""
    m = base.mantle_piece(icon, hearts)
    m = m.crop(m.getbbox())
    m = m.resize((round(m.width * 2.45), round(m.height * 1.75)), Image.LANCZOS)
    # darkened with a pink tint, so that the glassy white top does not turn grey
    tint = Image.new("RGBA", m.size, (round(255 * DARK), round(232 * DARK), round(243 * DARK), 255))
    out = ImageChops.multiply(m, tint)
    out.putalpha(m.getchannel("A"))
    return out


def head(c, cx, cy):
    """The bulk under the brim: a wide skin mass, darker towards the ground."""
    c.ellipse(cx, cy + 40, 520, 290, SKIN_DARK)
    c.ellipse(cx - 10, cy, 510, 270, SKIN)


def eye(c, cx, cy, r, look=-0.35):
    c.ellipse(cx, cy, r, r * 0.92, EYE_WHITE, outline=SKIN_DARK, width=14)
    px = cx + look * r
    c.ellipse(px, cy + r * 0.12, r * 0.5, r * 0.5, IRIS)
    c.ellipse(px, cy + r * 0.12, r * 0.26, r * 0.26, INK)


def compose_front(icon, t):
    """Faces left. Far tentacles first, then head, eyes, mantle (its brim is the brow), near ones."""
    c = Canvas()
    m = mantle(icon, hearts=True)
    mx, brim_y = 330, 1010  # mantle's left edge, bottom of the brim
    cx = mx + m.width * 0.47
    c.put(xf(t["droit_face"], 1.7, dark=0.72), 20, GROUND - 60)
    c.put(xf(t["droit_face"], 1.8, flip=True, dark=0.72), 1290, GROUND - 60)
    head(c, cx, brim_y + 70)
    eye(c, cx - 225, brim_y + 25, 135)
    eye(c, cx + 100, brim_y + 65, 165)
    c.put(m, mx, brim_y)
    # angry brows: wedges of dark skin sloping down to the middle, over the top of each eye
    c.poly([(cx - 380, brim_y - 170), (cx - 80, brim_y - 20), (cx - 90, brim_y + 45), (cx - 370, brim_y - 80)], SKIN_DARK)
    c.poly([(cx - 70, brim_y + 20), (cx + 300, brim_y - 60), (cx + 300, brim_y + 20), (cx - 60, brim_y + 85)], SKIN_DARK)
    # siphon: a short tube pointing at the viewer's left
    sx, sy = cx - 150, brim_y + 235
    c.ellipse(sx + 40, sy, 150, 115, SKIN_LIGHT, outline=SKIN_DARK, width=14)
    c.ellipse(sx - 20, sy + 5, 100, 95, SKIN, outline=SKIN_DARK, width=14)
    c.ellipse(sx - 30, sy + 8, 58, 60, INK)
    c.put(xf(t["enroule_face"], 1.3, flip=True), 60)
    c.put(xf(t["enroule_face"], 1.38), 1190)
    return c


def compose_back(icon, t):
    """Built facing left, mirrored when saved: mantle in front, tentacles rising around it."""
    c = Canvas()
    m = mantle(icon, hearts=False)
    mx, brim_y = 380, 1180
    cx = mx + m.width * 0.47
    c.put(xf(t["droit_dos"], 1.55, dark=0.72), 90, GROUND - 120)
    c.put(xf(t["enroule_dos"], 1.25, flip=True, dark=0.78), 1210, GROUND - 100)
    head(c, cx, brim_y - 40)
    c.put(m, mx, brim_y)
    c.put(xf(t["enroule_dos"], 1.5), 100)
    c.put(xf(t["droit_dos"], 1.7, flip=True), 1290)
    return c


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--src", type=Path, default=base.DEFAULT_SRC)
    p.add_argument("--force", action="store_true", help="écrase kralamoure_geant_pose*.png")
    args = p.parse_args()
    src = args.src.expanduser()
    names = ["kralamoure_geant_pose.png", "kralamoure_geant_pose_back.png"]
    existing = [n for n in names if (src / n).exists()]
    if existing and not args.force:
        sys.exit(f"{', '.join(existing)} existe déjà dans {src} : rien n'est écrasé (--force pour remplacer).")
    icon = base.load_icon(src)
    t = {stem.removeprefix("tentacule_"): tentacle(src, stem) for stem in TENTACLES}
    compose_front(icon, t).cropped().save(src / names[0])
    compose_back(icon, t).cropped(mirror=True).save(src / names[1])
    print(f"écrit {src}/{names[0]} (face) et {names[1]} (dos imaginé)")


if __name__ == "__main__":
    main()
