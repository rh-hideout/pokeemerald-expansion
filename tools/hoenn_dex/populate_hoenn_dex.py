hoenn_dex_order = "enum HoennDexOrder\n{\n"
hoenn_to_national_order = ""
lastSpecies = ""

with open("tools/hoenn_dex/hoenn_dex.txt", "r+") as file:
    lines = file.readlines()
    for line in lines:
        if line.startswith("    SPECIES"):
            hoenn_dex_order += line.replace("SPECIES", "HOENN_DEX")
            lastSpecies = line.split("_")[1].replace(",\n", "")
            if "SPECIES_NONE" not in line:
                hoenn_to_national_order += line.replace("SPECIES_", "HOENN_TO_NATIONAL(").replace(",", "),")
        else:
            hoenn_dex_order += line
            hoenn_to_national_order += line

with open("include/constants/hoenn_dex.h", "w") as file:
    file.write(f"{hoenn_dex_order}}};\n\n#define HOENN_DEX_COUNT (HOENN_DEX_{lastSpecies} + 1)\n")

with open("src/data/hoenn_dex.h", "w") as file:
    file.write(hoenn_to_national_order)
