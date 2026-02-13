### Note: This guide was written for version 1.15.0. And the processes described here will likely become obsolete at some point

# Deleting vanilla maps

If you want to delte a map, you will need to remove 4 things:
- the map folder in `data/maps/`
- the map folder in `data/layouts`
- the include of the mapscript in `data/event_scripts.s`
- the name of the map in `data/maps/map_groups.json`

Because vanilla maps are referenced all over the C code, deleting references to them can prevent the project to compile. To avoid this, mapjson will check if vanilla maps are missing and create dummy values for them.
mapjson will also modify heal_locations.json if one of the deleted map contained a heal_location

## Exceptions

Some maps may still be referenced in ways that cause compilation issues. For example the following script: `data/scripts/safari_zone.inc` references the entrance to the saafri zone where the player needs to be warped to when the safari is over.
You can simply remove the lines referencing the maps to fix the issue or even remove the entire script (assuming you deleted the safari entrance map because you remove the safri zone from your game)

## Deleting all FRLG maps

A command was added to delete all FRLG maps at once. This doesn;t really save space in the ROM because the maps are not compiled in the ROM if you are compiling in "emerald mode" but this can be used to clean up your repo.

Just run `make delete-frlg` to delete all FRLG maps from your repo.
You will still need to fix the safari zone script issue mentionned in the previous paragraph.
