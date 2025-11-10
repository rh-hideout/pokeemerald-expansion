# How to add multiple regions
*Written by OpticalMagician*

## Steps to implement multiple regions
In order to enable multiple regions we need a couple of things for each region first:

* The corect region map files. See [How to create a Region Map](how_to_region_map.md) if you do not already have these.

Then we have a couple steps to take to implement our region:

* Enable multi-region support
* Add our region to the list of available regions
* Add our region map files to the correct locations
* Add a return for our region name
* Handle our region in the town map
* Handle our region in the pokedex

## Enabling Multi-Region Support
In order to enable multi-region support all we have to do is change the `OW_MULTI_REGION_SUPPORT` flag in [include/config/overworld.h](../../include/config/overworld.h) to `TRUE`.

```diff
#ifndef GUARD_CONFIG_OVERWORLD_H
#define GUARD_CONFIG_OVERWORLD_H

// Multi-Region Support
- #define OW_MULTI_REGION_SUPPORT     FALSE       // If enabled, allows maps to be assigned to different regions (Hoenn, Kanto, etc.) for use in region-based features.
+ #define OW_MULTI_REGION_SUPPORT     TRUE        // If enabled, allows maps to be assigned to different regions (Hoenn, Kanto, etc.) for use in region-based features.

// Movement config
#define OW_RUNNING_INDOORS          GEN_LATEST  // In Gen4+, players are allowed to run indoors.
```

## Adding our region to the list of available regions
Next we will need to do is add our region to the list of available regions. This can be done by adding our region to [src/data/region_map/regions.json](../../src/data/region_map/regions.json).

```diff
{
    "regions": [
        {
            "id": "REGION_KANTO",
            "name": "Kanto",
            "text": "KANTO"
        },
...
        {
            "id": "REGION_PALDEA",
            "name": "Paldea",
            "text": "PALDEA"
-        }
+        },
+        {
+            "id": "REGION_TUTORIAL",
+            "name": "Tutorial",
+            "text": "TUTORIAL"
+        }
    ]
}
```

## Adding our region map files to the correct locations
This part can be skipped if you simply wish to use the Hoenn region map. However, we assume that anyone adding a new region will want to add a new region map to accompany it. Once you have your region map files, follow the `Moving and renaming our files` section of the [How to create a Region Map](how_to_region_map.md) tutorial.

## Adding a return for our region name
Next we need to add a case for our region to the `GetCurrentRegionName` function in [include/regions.h](../../include/regions.h). The `gText_<region_name>` variable will be created by the build system in a generated file.

```diff
static inline const u8 *GetCurrentRegionName(void)
{
#if OW_MULTI_REGION_SUPPORT
    switch (GetCurrentRegion())
    {
    case REGION_HOENN:
        return gText_Hoenn;
...
    case REGION_PALDEA:
        return gText_Paldea;
+    case REGION_TUTORIAL:
+        return gText_Tutorial;
    case REGION_NONE:
        return gText_RegionDefault;
    }
#endif //OW_MULTI_REGION_SUPPORT
    return gText_Hoenn;
}
```

## Handling our region in the town map
Once our region map files are in the correct locations we will need to handle them in the town map graphics. For this we will need to add references to our files and a case for our region to 4 functions in the [src/region_map.c](../../src/region_map.c) file. For our `map.bin`, `tileset.pal`, and `tileset.png` files in [graphics/pokenav/region_map/](../../graphics/pokenav/region_map), we will need to add a new reference to each one.

```diff
static const u16 sRegionMapPlayerIcon_MayPal[] = INCBIN_U16("graphics/pokenav/region_map/may_icon.gbapal");
static const u8 sRegionMapPlayerIcon_MayGfx[] = INCBIN_U8("graphics/pokenav/region_map/may_icon.4bpp");
// Hoenn region map
static const u16 sRegionMapBg_Pal_Hoenn[] = INCBIN_U16("graphics/pokenav/region_map/map.gbapal");
static const u32 sRegionMapBg_Gfx_Hoenn[] = INCBIN_U32("graphics/pokenav/region_map/map.8bpp.smol");
static const u32 sRegionMapBg_Tilemap_Hoenn[] = INCBIN_U32("graphics/pokenav/region_map/map.bin.smolTM");
+ // Tutorial region map
+ static const u16 sRegionMapBg_Pal_Tutorial[] = INCBIN_U16("graphics/pokenav/region_map/tutorial_map.gbapal");
+ static const u32 sRegionMapBg_Gfx_Tutorial[] = INCBIN_U32("graphics/pokenav/region_map/tutorial_map.8bpp.smol");
+ static const u32 sRegionMapBg_Tilemap_Tutorial[] = INCBIN_U32("graphics/pokenav/region_map/tutorial_map.bin.smolTM");
```

Notice that the file extension is different from that of our files. This is correct as the build system will find our corresponding files by name and compress them to these formats for the game to use. Next we need to have a `region_map_layout.h` file for our region. For ease of implementation a blank one has been created, we will copy [src/data/region_map/region_map_layout_blank.h](../../src/data/region_map/region_map_layout_blank.h) and paste it back in [src/data/region_map](../../src/data/region_map) renaming it to `region_map_layout_tutorial.h`, and we will change the name of the array as well.

```diff
- static const mapsec_u8_t sRegionMap_MapSectionLayout_Blank[MAP_HEIGHT][MAP_WIDTH] = {
+ static const mapsec_u8_t sRegionMap_MapSectionLayout_Tutorial[MAP_HEIGHT][MAP_WIDTH] = {
```

Then we will need to reference it in [src/region_map.c](../../src/region_map.c).

```diff
#include "data/region_map/region_map_entries.h"
#include "data/region_map/region_map_layout_hoenn.h"
+ #include "data/region_map/region_map_layout_tutorial.h"
```

Finally we need to add a case for our region to the functions that serve these references to the graphics engine. We will need to add a case for our new region to:

`GetCurrentRegionMapBgPal`,

```diff
const u16 *GetCurrentRegionMapBgPal(void)
{
#if OW_MULTI_REGION_SUPPORT
    switch (GetCurrentRegion())
    {
+    case REGION_TUTORIAL:
+        return sRegionMapBg_Pal_Tutorial;
    case REGION_KANTO:
    case REGION_JOHTO:
    case REGION_SINNOH:
    case REGION_UNOVA:
    case REGION_KALOS:
    case REGION_ALOLA:
    case REGION_GALAR:
    case REGION_HISUI:
    case REGION_PALDEA:
    case REGION_HOENN:
    case REGION_NONE:
    case REGIONS_COUNT:
        return sRegionMapBg_Pal_Hoenn;
    }
#endif //OW_MULTI_REGION_SUPPORT
    return sRegionMapBg_Pal_Hoenn;
}
```

`GetCurrentRegionMapBgGfx`,

```diff
const u32 *GetCurrentRegionMapBgGfx(void)
{
#if OW_MULTI_REGION_SUPPORT
    switch (GetCurrentRegion())
    {
+    case REGION_TUTORIAL:
+        return sRegionMapBg_Gfx_Tutorial;
    case REGION_KANTO:
    case REGION_JOHTO:
    case REGION_SINNOH:
    case REGION_UNOVA:
    case REGION_KALOS:
    case REGION_ALOLA:
    case REGION_GALAR:
    case REGION_HISUI:
    case REGION_PALDEA:
    case REGION_HOENN:
    case REGION_NONE:
    case REGIONS_COUNT:
        return sRegionMapBg_Gfx_Hoenn;
    }
#endif //OW_MULTI_REGION_SUPPORT
    return sRegionMapBg_Gfx_Hoenn;
}
```

`GetCurrentRegionMapBgTilemap`,

```diff
const u32 *GetCurrentRegionMapBgTilemap(void)
{
#if OW_MULTI_REGION_SUPPORT
    switch (GetCurrentRegion())
    {
+    case REGION_TUTORIAL:
+        return sRegionMapBg_Tilemap_Tutorial;
    case REGION_KANTO:
    case REGION_JOHTO:
    case REGION_SINNOH:
    case REGION_UNOVA:
    case REGION_KALOS:
    case REGION_ALOLA:
    case REGION_GALAR:
    case REGION_HISUI:
    case REGION_PALDEA:
    case REGION_HOENN:
    case REGION_NONE:
    case REGIONS_COUNT:
        return sRegionMapBg_Tilemap_Hoenn;
    }
#endif //OW_MULTI_REGION_SUPPORT
    return sRegionMapBg_Tilemap_Hoenn;
}
```

and `GetCurrentRegionMapLayout`.

```diff
const mapsec_u8_t (*GetCurrentRegionMapLayout(void))[MAP_WIDTH]
{
#if OW_MULTI_REGION_SUPPORT
    switch (GetCurrentRegion())
    {
+    case REGION_TUTORIAL:
+        return sRegionMap_MapSectionLayout_Tutorial;
    case REGION_KANTO:
    case REGION_JOHTO:
    case REGION_SINNOH:
    case REGION_UNOVA:
    case REGION_KALOS:
    case REGION_ALOLA:
    case REGION_GALAR:
    case REGION_HISUI:
    case REGION_PALDEA:
    case REGION_HOENN:
    case REGION_NONE:
    case REGIONS_COUNT:
        return sRegionMap_MapSectionLayout_Hoenn;
    }
#endif //OW_MULTI_REGION_SUPPORT
    return sRegionMap_MapSectionLayout_Hoenn;
}
```

## Handling our region in the pokedex
Just like with the town map we need to add references and cases for our region to the [src/pokedex_area_region_map.c](../../src/pokedex_area_region_map.c) file. We will add our references to the region map files first.

```diff
// Hoenn region map
static const u16 ALIGNED(4) sPokedexAreaMap_Pal_Hoenn[] = INCBIN_U16("graphics/pokedex/region_map_hoenn.gbapal");
static const u32 sPokedexAreaMap_Gfx_Hoenn[] = INCBIN_U32("graphics/pokedex/region_map_hoenn.8bpp.smol");
static const u32 sPokedexAreaMap_Tilemap_Hoenn[] = INCBIN_U32("graphics/pokedex/region_map_hoenn.bin.smolTM");
+ // Tutorial region map
+ static const u16 ALIGNED(4) sPokedexAreaMap_Pal_Tutorial[] = INCBIN_U16("graphics/pokedex/region_map_tutorial.gbapal");
+ static const u32 sPokedexAreaMap_Gfx_Tutorial[] = INCBIN_U32("graphics/pokedex/region_map_tutorial.8bpp.smol");
+ static const u32 sPokedexAreaMap_Tilemap_Tutorial[] = INCBIN_U32("graphics/pokedex/region_map_tutorial.bin.smolTM");
// Affine versions (not used)
static const u32 sPokedexAreaMapAffine_Gfx[] = INCBIN_U32("graphics/pokedex/region_map_affine.8bpp.smol");
static const u32 sPokedexAreaMapAffine_Tilemap[] = INCBIN_U32("graphics/pokedex/region_map_affine.bin.smolTM");
```

Then we can add cases for our region to

`GetPokedexAreaMapPal`,

```diff
const u16 *GetPokedexAreaMapPal(void)
{
#if OW_MULTI_REGION_SUPPORT
    switch (GetCurrentRegion())
    {
+    case REGION_TUTORIAL:
+        return sPokedexAreaMap_Pal_Tutorial;
    case REGION_KANTO:
    case REGION_JOHTO:
    case REGION_SINNOH:
    case REGION_UNOVA:
    case REGION_KALOS:
    case REGION_ALOLA:
    case REGION_GALAR:
    case REGION_HISUI:
    case REGION_PALDEA:
    case REGION_HOENN:
    case REGION_NONE:
    case REGIONS_COUNT:
        DebugPrintf("GetCurrentRegionMapBgPal[Multi-Region]: Returning Hoenn Palette");
        return sPokedexAreaMap_Pal_Hoenn;
    }
#endif //OW_MULTI_REGION_SUPPORT
    DebugPrintf("GetCurrentRegionMapBgPal[Default]: Returning Hoenn Palette");
    return sPokedexAreaMap_Pal_Hoenn;
}
```

`GetPokedexAreaMapGfx`,

```diff
const u32 *GetPokedexAreaMapGfx(void)
{
#if OW_MULTI_REGION_SUPPORT
    switch (GetCurrentRegion())
    {
+    case REGION_TUTORIAL:
+        return sPokedexAreaMap_Gfx_Tutorial;
    case REGION_KANTO:
    case REGION_JOHTO:
    case REGION_SINNOH:
    case REGION_UNOVA:
    case REGION_KALOS:
    case REGION_ALOLA:
    case REGION_GALAR:
    case REGION_HISUI:
    case REGION_PALDEA:
    case REGION_HOENN:
    case REGION_NONE:
    case REGIONS_COUNT:
        DebugPrintf("GetCurrentRegionMapBgPal[Multi-Region]: Returning Hoenn Graphics");
        return sPokedexAreaMap_Gfx_Hoenn;
    }
#endif //OW_MULTI_REGION_SUPPORT
    DebugPrintf("GetCurrentRegionMapBgPal[Default]: Returning Hoenn Graphics");
    return sPokedexAreaMap_Gfx_Hoenn;
}
```

and `GetPokedexAreaMapTilemap`.

```diff
const u32 *GetPokedexAreaMapTilemap(void)
{
#if OW_MULTI_REGION_SUPPORT
    switch (GetCurrentRegion())
    {
+    case REGION_TUTORIAL:
+        return sPokedexAreaMap_Tilemap_Tutorial;
    case REGION_KANTO:
    case REGION_JOHTO:
    case REGION_SINNOH:
    case REGION_UNOVA:
    case REGION_KALOS:
    case REGION_ALOLA:
    case REGION_GALAR:
    case REGION_HISUI:
    case REGION_PALDEA:
    case REGION_HOENN:
    case REGION_NONE:
    case REGIONS_COUNT:
        DebugPrintf("GetCurrentRegionMapBgPal[Multi-Region]: Returning Hoenn Tilemap");
        return sPokedexAreaMap_Tilemap_Hoenn;
    }
#endif //OW_MULTI_REGION_SUPPORT
    DebugPrintf("GetCurrentRegionMapBgPal[Default]: Returning Hoenn Tilemap");
    return sPokedexAreaMap_Tilemap_Hoenn;
}
```

And finally we add our region to [src/pokedex_plus_hgss.c](../../src/pokedex_plus_hgss.c). In the `PrintEvolutionTargetSpeciesAndMethod` is a switch statement for regions where we must handle our new region.

```diff
                    switch ((enum Region)evolutions[i].params[j].arg1)
                    {
                    case REGION_NONE:
                    case REGIONS_COUNT:
                        StringAppend(gStringVar4, COMPOUND_STRING("???"));
                        break;
                    case REGION_KANTO: StringAppend(gStringVar4, COMPOUND_STRING("Kanto")); break;
                    case REGION_JOHTO: StringAppend(gStringVar4, COMPOUND_STRING("Johto")); break;
                    case REGION_HOENN: StringAppend(gStringVar4, COMPOUND_STRING("Hoenn")); break;
                    case REGION_SINNOH: StringAppend(gStringVar4, COMPOUND_STRING("Sinnoh")); break;
                    case REGION_UNOVA: StringAppend(gStringVar4, COMPOUND_STRING("Unova")); break;
                    case REGION_KALOS: StringAppend(gStringVar4, COMPOUND_STRING("Kalos")); break;
                    case REGION_ALOLA: StringAppend(gStringVar4, COMPOUND_STRING("Alola")); break;
                    case REGION_GALAR: StringAppend(gStringVar4, COMPOUND_STRING("Galar")); break;
                    case REGION_HISUI: StringAppend(gStringVar4, COMPOUND_STRING("Hisui")); break;
                    case REGION_PALDEA: StringAppend(gStringVar4, COMPOUND_STRING("Paldea")); break;
+                    case REGION_TUTORIAL: StringAppend(gStringVar4, COMPOUND_STRING("Tutorial")); break;
                    }
                    break;
                }
```

## Implementing core series regions
To implement any of the core series regions the steps for a new region will need to be followed but instead of adding new cases you simply implement handling for the core series regions.

## Adding map sections to a region
In order for multi-region to work, and not simply default to Hoenn for everything, you will need to specify which map sections belong to which regions. This is can be done by setting the region in the map header information through porymap or by adding an entry for the `region` field in the `map.json` file manually for the map section you wish to modify. As an example of adding the entry manually we have changed Littleroot to be in the Johto region.

```diff
{
  "id": "MAP_LITTLEROOT_TOWN",
  "name": "LittlerootTown",
  "layout": "LAYOUT_LITTLEROOT_TOWN",
  "music": "MUS_LITTLEROOT",
  "region_map_section": "MAPSEC_LITTLEROOT_TOWN",
+  "region": "REGION_JOHTO",
  "requires_flash": false,
  "weather": "WEATHER_SUNNY",
  "map_type": "MAP_TYPE_TOWN",
  "allow_cycling": true,
  "allow_escaping": false,
  "allow_running": true,
  "show_map_name": true,
  "battle_scene": "MAP_BATTLE_SCENE_NORMAL",
  "connections": [
    {
      "map": "MAP_ROUTE101",
      "offset": 0,
      "direction": "up"
    }
  ],
```

To use porymap to set the region for map sections you simply need to add and set a custom attribute. In the `Custom Attributes` section of the `Header` tab for your map section click `Add`. For the `Name` put `region`, leave the `Type` as `String`, and set the `Value` to the region id you wish, eg: `REGION_HOENN`.
