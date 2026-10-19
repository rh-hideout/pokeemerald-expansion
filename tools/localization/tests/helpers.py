import os
import sys

TOOL_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
ROOT = os.path.abspath(os.path.join(TOOL_DIR, "..", ".."))
if TOOL_DIR not in sys.path:
    sys.path.insert(0, TOOL_DIR)

from charmap import Charmap  # noqa: E402

_charmap = None


def charmap():
    global _charmap
    if _charmap is None:
        _charmap = Charmap(os.path.join(ROOT, "charmap.txt"))
    return _charmap
