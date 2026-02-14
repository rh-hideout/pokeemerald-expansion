import json
import re
import sys

auto = len(sys.argv) > 1 and (sys.argv[1] == "--auto" or sys.argv[1] == "-a")

# no need to be fully accurate, we just want a sensible ordering
# sorts alternate forms after every base form pokemon, but this is good enough
SPECIES_DEFINE_PAT = re.compile(r"#define (?P<species_name>SPECIES_[A-Z_]+)")
species_indices = {}
with open("include/constants/species.h", 'r') as species_consts_file:
    i = 0
    for line in species_consts_file.readlines():
        if (m := re.match(SPECIES_DEFINE_PAT, line)):
            species_indices[m["species_name"]] = i
            i += 1

with open("src/data/wild_encounters.json", 'r') as wild_enc_in:
    wild_encounters = json.load(wild_enc_in)

def split_groups(encounter_groups, map_encounters):
    for encounter_type, groups in encounter_groups.items():
        if encounter_type in map_encounters:
            for group_name, group in groups.items():
                map_encounters[group["new_name"]] = {
                    key: (value if key != "mons" else
                         [map_encounters[encounter_type]["mons"][i] for i in group["slots"]])
                    for key, value in map_encounters[encounter_type].items()
                }
            del map_encounters[encounter_type]

def add_weights(encounter_rates, map_encounters):
    for (encounter_type, rates) in encounter_rates.items():
        if encounter_type in map_encounters:
            for i, mon in enumerate(map_encounters[encounter_type]["mons"]):
                mon["weight"] = rates[i]

def make_encounters_object(encounter_rates, map_encounters):
    map_encounters["encounter_sets"] = dict((key, map_encounters[key]) for key in encounter_rates if key in map_encounters)
    for key in encounter_rates:
        if key in map_encounters:
            del map_encounters[key]

def optimize_encounter_slots(map_encounters):
    for encounter_set in map_encounters["encounter_sets"].values():
        slots = {}
        for slot in encounter_set["mons"]:
            key = (slot["min_level"], slot["max_level"], slot["species"])
            if key not in slots:
                slots[key] = slot
            else:
                slots[key]["weight"] += slot["weight"]
        encounter_set["mons"] = list(slots.values())

def sort_encounter_slots(map_encounters):
    for encounter_set in map_encounters["encounter_sets"].values():
        encounter_set["mons"] = sorted(encounter_set["mons"], key=(lambda slot: (species_indices[slot["species"]], slot["min_level"], slot["max_level"])))

encounter_rates = {}
encounter_groups = {}
new_fields = []
for group in wild_encounters["wild_encounter_groups"]:
    if "fields" in group:
        for field in group["fields"]:
            encounter_rates[field["type"]] = field["encounter_rates"]
            if "groups" in field:
                encounter_groups[field["type"]] = {}
                for group_name, group_slots in field["groups"].items():
                    if auto:
                        new_name = f"{field['type']}_{group_name}"
                        print(f"Split group {group_name} from field {field['type']} into new field {new_name}")
                    else:
                        new_name = input(f"Name for new field from field {field['type']}'s group {group_name} (default: {field['type']}_{group_name}):")
                        if not new_name:
                            new_name = f"{field['type']}_{group_name}"
                    encounter_groups[field["type"]][group_name] = {
                        "new_name": new_name,
                        "slots": group_slots
                    }
                    new_fields.append({"type": new_name, "encounter_rates": [field["encounter_rates"][i] for i in group_slots]})
            else:
                new_fields.append(field)
        group["fields"] = new_fields

for encounter_type, groups in encounter_groups.items():
    for _, group in groups.items():
        encounter_rates[group["new_name"]] = [encounter_rates[encounter_type][i] for i in group["slots"]]

optimize = False
sort = True
if (not auto):
    inp = input("Optimize encounter slots for space (affects encounter rates with Lure active, saves 2KB on vanilla Emerald)? [y(es)/N(o)] (default: no) ")
    optimize = bool(inp and inp.lower() in ['y', 'yes'])
    inp = input("Sort encounter slots by species ID and level? [Y(es)/n(o)] (default: yes) ")
    sort = bool(not inp or inp.lower() in ['y', 'yes'])

for group in wild_encounters["wild_encounter_groups"]:
    for map_encounters in group["encounters"]:
        split_groups(encounter_groups, map_encounters)
        add_weights(encounter_rates, map_encounters)
        make_encounters_object(encounter_rates, map_encounters)

        if (optimize):
            optimize_encounter_slots(map_encounters)
        if (sort):
            sort_encounter_slots(map_encounters)

with open("src/data/wild_encounters.json", 'w') as wild_enc_out:
    json.dump(wild_encounters, wild_enc_out, indent=2)
