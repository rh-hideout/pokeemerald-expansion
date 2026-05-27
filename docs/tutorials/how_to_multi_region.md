# How to add multiple regions
*Written by OpticalMagician*

## Steps to implement multiple regions
In order to enable multiple regions we need a couple of things for each region first:

* The correct region map files. See [How to create a Region Map](how_to_region_map.md) if you do not already have these.

Then we have a couple steps to take to implement our region:

* Add our region to the list of available regions
* Set the new region to the map sections that belong to it


## Adding our region to the list of available regions
Next we will need to do is add our region to the list of available regions. This can be done by adding our region to [src/data/region_map/region_maps.json](../../src/data/region_map/region_maps.json).

```diff
{
    "region_maps": [
    {
      "label": "hoenn",
      "region_name": "HOENN",
      "layoutFile": "src/data/region_map/layout_hoenn.h",
      "layout_width": 28,
      "layout_height": 15,
      "layout_offset_left": 1,
      "layout_offset_top": 2,
      "palette": ["graphics/pokenav/region_map/map_hoenn.pal", ".gbapal"],
      "gfx": ["graphics/pokenav/region_map/map_hoenn.png", ".8bpp.smol"],
      "tilemap": ["graphics/pokenav/region_map/map_hoenn.bin", ".smolTM"],
      "pokedexPalette": ["graphics/pokedex/region_map_hoenn.pal", ".gbapal"],
      "pokedexGfx": ["graphics/pokedex/region_map_hoenn.png", ".8bpp.smol", "-num_tiles 232 -Wnum_tiles"],
      "pokedexTilemap": ["graphics/pokedex/region_map_hoenn.bin", ".smolTM"]
    },
+   {
+      "label": "johto",
+      "region_name": "JOHTO",
+      "layoutFile": "src/data/region_map/layout_johto.h",
+      "layout_width": 28,
+      "layout_height": 15,
+      "layout_offset_left": 1,
+      "layout_offset_top": 2,
+      "palette": ["graphics/pokenav/region_map/map_johto.pal", ".gbapal"],
+      "gfx": ["graphics/pokenav/region_map/map_johto.png", ".8bpp.smol"],
+      "tilemap": ["graphics/pokenav/region_map/map_johto.bin", ".smolTM"],
+      "pokedexPalette": ["graphics/pokedex/region_map_johto.pal", ".gbapal"],
+      "pokedexGfx": ["graphics/pokedex/region_map_johto.png", ".8bpp.smol"],
+      "pokedexTilemap": ["graphics/pokedex/region_map_johto.bin", ".smolTM"]
    },
    ...
}
```

Let's go over what each field means:

- `label` is used for internal variable names refererencing the region, it should only be made of aplhanumeric characters
- `region_name` is the actual string the player can see in the game, it can contain whitespace or punctuation
- `layoutFile` contains the path to the file listing the map section assiocated with each map tile. If the file doesn't exist, it will be created automatically but filled with no map scetions (like if the map had no point of interest). Once the file is created, we recommend editing it with Porymap's Region map Editor
- `layout_width`, `layout_height`, `layout_offset_left`, `layout_offset_top` refers to the selectable area you can move your pointer over on the map, `layout_width` and `layout_height` are the size of that selectable area while `layout_offset_left` and `layout_offset_top` refers to the coordiantes of the first selectable tile. You would set both values to 0 if you wanted the selected area to start on the top left corner of the map
- `palette`, `gfx` and `tilemap` refers to the graphics file of the map. they are arrays because they correspond to incgfx entries instead of simple path to the files
- `pokedexPalette`, `pokedexGfx` and `pokedexTilemap` are the same for the pokedex versions of the region images
- `unlockCondition` refers to the condition that needs to be fulfilled for the map to be accesible from the pokedex or when trying to fly


## Region map unlock conditions

When adding a new region map to your game, you may not want it to be accesible to the player at all times. The `unlockCondition` field let you add restriction so that a player can't see the Sevii Islands at the start of the game for exampe. The possible values for `unlockCondition` are:
- `ALWAYS_LOCKED`  means the map is never accesible from the pokedex or fly map. However you can still see the map with an item or event set to that specific map
- `ALWAYS_UNLOCKED` means the map is always accesible. From the start of the game, you will be able to select that map.
- `UNLOCKED_ON_FLY` means the map will be available if you have at least one fly location from that map unlocked.
- `FLAG_UNLOCK(flag)` means the map will be available only if `flag` is set

If no `unlockCondition` is present, the game will use `UNLOCKED_ON_FLY` as default

