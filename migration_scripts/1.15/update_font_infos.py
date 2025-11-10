from enum import Enum, auto
import re
import tempfile

font_infos_re = re.compile(
    r"struct\s+FontInfo\s+sFontInfos\[\]\s+=[^{]*\{" # array opening bracket
    r"(?P<elems>([^{}]*\{[^{}]*})+)" # array elements
    r"[^{}]*};", # array closing bracket
    re.MULTILINE
)

array_elem_re = re.compile(r"[^{}]*(\{[^{}]*})")

bg_color_re = re.compile(r"(?P<indent>\s*)\.bgColor\s*=\s*(?P<bg_color>[a-zA-Z0-9_]+)(?P<comma>,?)")
        
def repl_fi_elem(m):
    s = m[0]
    if ".accentColor" in s:
        return s
    return bg_color_re.sub(lambda m: f"{m["indent"]}.bgColor = {m["bg_color"]},{m["indent"]}.accentColor = {m["bg_color"]}{m["comma"]}", s)

if __name__ == "__main__":
    with tempfile.TemporaryFile(mode="w+") as tmp:
        with open("src/text.c", 'r') as f:
            text_c = f.read()
            m = font_infos_re.search(text_c)
        if m is None:
            print("Couldn't find sFontInfos!")
            exit(1)
        font_infos_elems = m.group("elems")
        fi_start, fi_end = m.span("elems")
        
        tmp.write(text_c[:fi_start])
        edited = array_elem_re.sub(repl_fi_elem, font_infos_elems)
        tmp.write(edited)
        tmp.write(text_c[fi_end:])
        
        tmp.seek(0)
        
        with open("src/text.c", "w") as f:
            f.write(tmp.read())
