#include "global.h"
#include "main.h"
#include "menu.h"
#include "bg.h"
#include "malloc.h"
#include "palette.h"
#include "regions.h"
#include "pokedex_area_region_map.h"
#include "regions.h"
#include "region_map.h"

#define POKEDEX_AREA_MAP_BG 3

void LoadPokedexAreaMapGfx(enum RegionMapId regionMap, bool32 faded)
{
    DecompressAndCopyTileDataToVram(POKEDEX_AREA_MAP_BG, gRegionMapInfos[regionMap].dexMapGfx, 0, 0, 0);
    DecompressAndCopyTileDataToVram(POKEDEX_AREA_MAP_BG, gRegionMapInfos[regionMap].dexMapTilemap, 0, 0, 1);
    CpuCopy32(gRegionMapInfos[regionMap].dexMapPalette, &gPlttBufferUnfaded[BG_PLTT_ID(7)], gRegionMapInfos[regionMap].dexMapPaletteSize);
    if (!faded)
        CpuCopy32(gRegionMapInfos[regionMap].dexMapPalette, &gPlttBufferFaded[BG_PLTT_ID(7)], gRegionMapInfos[regionMap].dexMapPaletteSize);
}

bool32 TryShowPokedexAreaMap(void)
{
    if (!FreeTempTileDataBuffersIfPossible())
    {
        ShowBg(POKEDEX_AREA_MAP_BG);
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void PokedexAreaMapChangeBgY(u32 move)
{
    ChangeBgY(POKEDEX_AREA_MAP_BG, move * 0x100, BG_COORD_SET);
}
