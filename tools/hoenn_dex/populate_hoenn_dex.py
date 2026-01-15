hoenn_dex_order = "enum HoennDexOrder\n{\n"
hoenn_to_national_order = ""

with open("tools/hoenn_dex/hoenn_dex.txt", "r+") as file:
    lines = file.readlines()
    for line in lines:
        if line.startswith("    SPECIES"):
            hoenn_dex_order += line.replace("SPECIES", "HOENN_DEX")
            if "SPECIES_NONE" not in line:
                hoenn_to_national_order += line.replace("SPECIES_", "HOENN_TO_NATIONAL(").replace(",", "),")
        else:
            hoenn_dex_order += line
            hoenn_to_national_order += line

#include/constants/hoenn_dex.h src/data/hoenn_dex.h
with open("include/constants/hoenn_dex.h", "w") as file:
    file.write(hoenn_dex_order + "};\n")

with open("src/data/hoenn_dex.h", "w") as file:
    file.write(hoenn_to_national_order)