### Note: This guide was written for version 1.15.0. And the processes described here will likely become obsolete at some point

# Deleting vanilla maps

If you want to delete a map, you will need to remove 4 things:
- the map folder in `data/maps/`
- the map folder in `data/layouts`
- the include of the mapscript in `data/event_scripts.s`
- the name of the map in `data/maps/map_groups.json`

Because vanilla maps are referenced all over the C code, deleting references to them can prevent the project to compile. To avoid this, mapjson will check if vanilla maps are missing and create dummy values for them.

**NOTE**:
- mapjson will _not_ function correctly unless all four of the aforementioned are edited.
- mapjson will also modify heal_locations.json if one of the deleted map contained a heal_location.
- when creating connections between maps, mapjson will check if the connected map exist and will not add a connection for a missing map

## Exceptions

Some maps may still be referenced in ways that cause compilation issues. Usually, it will be scripts that directly reference the old map names. For example the following script: `data/scripts/safari_zone.inc` references the entrance to the safari zone where the player needs to be warped to when the safari is over.
You can simply remove the lines referencing the maps to fix the issue, remove the entire script (assuming you deleted the safari entrance map because you remove the safari zone from your game).

## Deleting all FRLG maps

A command was added to delete all FRLG maps at once. This doesn't save space in the ROM because the maps are not compiled in the ROM if you are compiling in "emerald mode". This solely exists for users that want to clean up their repo.

Running `make delete-frlg` will delete all FRLG maps from the repo.

Users will still need to fix the safari zone script issue mentioned in the previous paragraph.
