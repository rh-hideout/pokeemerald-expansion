"""Minimal indexed-colour PNG reader/writer (stdlib only).

Supports what the GBA asset pipeline uses: colour type 3 (palette) at bit
depths 1/2/4/8, plus 8-bit greyscale for reading, non-interlaced.
"""

import struct
import zlib
from dataclasses import dataclass

SIGNATURE = b"\x89PNG\r\n\x1a\n"


@dataclass
class IndexedImage:
    width: int
    height: int
    bit_depth: int
    palette: list                  # [(r, g, b), ...]
    pixels: list                   # rows of palette indices
    trns: bytes = None
    color_type: int = 3

    def copy(self):
        return IndexedImage(self.width, self.height, self.bit_depth, list(self.palette),
                            [list(r) for r in self.pixels], self.trns, self.color_type)


class PngError(Exception):
    pass


def _chunks(data):
    pos = len(SIGNATURE)
    while pos < len(data):
        length, ctype = struct.unpack(">I4s", data[pos:pos + 8])
        body = data[pos + 8:pos + 8 + length]
        yield ctype.decode("latin-1"), body
        pos += 12 + length


def _paeth(a, b, c):
    p = a + b - c
    pa, pb, pc = abs(p - a), abs(p - b), abs(p - c)
    if pa <= pb and pa <= pc:
        return a
    return b if pb <= pc else c


def read_png(path):
    with open(path, "rb") as f:
        data = f.read()
    if not data.startswith(SIGNATURE):
        raise PngError(f"{path}: not a PNG file")
    ihdr = None
    palette = []
    trns = None
    idat = bytearray()
    for ctype, body in _chunks(data):
        if ctype == "IHDR":
            ihdr = struct.unpack(">IIBBBBB", body)
        elif ctype == "PLTE":
            palette = [tuple(body[i:i + 3]) for i in range(0, len(body), 3)]
        elif ctype == "tRNS":
            trns = body
        elif ctype == "IDAT":
            idat += body
        elif ctype == "IEND":
            break
    if ihdr is None:
        raise PngError(f"{path}: missing IHDR")
    width, height, depth, ctype, _, _, interlace = ihdr
    if interlace:
        raise PngError(f"{path}: interlaced PNGs are not supported")
    if ctype not in (0, 3):
        raise PngError(f"{path}: only indexed (or greyscale) PNGs are supported, got colour type {ctype}")
    raw = zlib.decompress(bytes(idat))
    stride = (width * depth + 7) // 8
    bpp = max(1, depth // 8)
    rows = []
    prev = bytearray(stride)
    pos = 0
    for _ in range(height):
        ftype = raw[pos]
        line = bytearray(raw[pos + 1:pos + 1 + stride])
        pos += 1 + stride
        for i in range(stride):
            a = line[i - bpp] if i >= bpp else 0
            b = prev[i]
            c = prev[i - bpp] if i >= bpp else 0
            if ftype == 1:
                line[i] = (line[i] + a) & 0xFF
            elif ftype == 2:
                line[i] = (line[i] + b) & 0xFF
            elif ftype == 3:
                line[i] = (line[i] + ((a + b) >> 1)) & 0xFF
            elif ftype == 4:
                line[i] = (line[i] + _paeth(a, b, c)) & 0xFF
        prev = line
        rows.append(_unpack_row(line, width, depth))
    if ctype == 0 and not palette:
        levels = 1 << depth
        palette = [(v * 255 // (levels - 1),) * 3 for v in range(levels)]
    return IndexedImage(width, height, depth, palette, rows, trns, ctype)


def _unpack_row(line, width, depth):
    if depth == 8:
        return list(line[:width])
    per = 8 // depth
    mask = (1 << depth) - 1
    out = []
    for x in range(width):
        byte = line[x // per]
        shift = 8 - depth * (x % per + 1)
        out.append((byte >> shift) & mask)
    return out


def _pack_row(row, depth):
    if depth == 8:
        return bytes(row)
    per = 8 // depth
    out = bytearray((len(row) + per - 1) // per)
    for x, v in enumerate(row):
        out[x // per] |= (v & ((1 << depth) - 1)) << (8 - depth * (x % per + 1))
    return bytes(out)


def _chunk(ctype, body):
    c = ctype.encode("latin-1")
    return struct.pack(">I", len(body)) + c + body + struct.pack(">I", zlib.crc32(c + body) & 0xFFFFFFFF)


def write_png(path, img):
    raw = bytearray()
    for row in img.pixels:
        raw.append(0)
        raw += _pack_row(row, img.bit_depth)
    out = bytearray(SIGNATURE)
    out += _chunk("IHDR", struct.pack(">IIBBBBB", img.width, img.height, img.bit_depth, img.color_type, 0, 0, 0))
    if img.color_type == 3:
        out += _chunk("PLTE", b"".join(bytes(c) for c in img.palette))
        if img.trns:
            out += _chunk("tRNS", img.trns)
    out += _chunk("IDAT", zlib.compress(bytes(raw), 9))
    out += _chunk("IEND", b"")
    with open(path, "wb") as f:
        f.write(out)
