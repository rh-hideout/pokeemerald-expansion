#!/usr/bin/python3
""" Extract a GBA-compatible palette from a PNG. """
import sys
import os.path
import png

PAL_PRELUDE = 'JASC-PAL\n0100\n'


def extract_palette(path):
    r = png.Reader(path)
    r.read()
    root, _ = os.path.splitext(path)
    out_path = root + '.pal'
    with open(out_path, 'w', newline='\r\n') as f:
        f.write(PAL_PRELUDE)
        colours = r.palette()
        if len(colours) < 16:
            colours += [(0, 0, 0) for _ in range(16-len(colours))]
        f.write(f'{len(colours)}\n')
        for r, g, b in colours:
            f.write(f'{r} {g} {b}\n')


if __name__ == '__main__':
    extract_palette(*sys.argv[1:])
