#include "global.h"
#include "main.h"
#include "menu.h"
#include "bg.h"
#include "malloc.h"
#include "palette.h"
#include "regions.h"
#include "pokedex_area_region_map.h"

static EWRAM_DATA u8 *sPokedexAreaMapBgNum = NULL;

// Hoenn region map
static const u16 ALIGNED(4) sPokedexAreaMap_Pal_Hoenn[] = INCBIN_U16("graphics/pokedex/region_map_hoenn.gbapal");
static const u32 sPokedexAreaMap_Gfx_Hoenn[] = INCBIN_U32("graphics/pokedex/region_map_hoenn.8bpp.smol");
static const u32 sPokedexAreaMap_Tilemap_Hoenn[] = INCBIN_U32("graphics/pokedex/region_map_hoenn.bin.smolTM");
// Affine versions (not used)
static const u32 sPokedexAreaMapAffine_Gfx[] = INCBIN_U32("graphics/pokedex/region_map_affine.8bpp.smol");
static const u32 sPokedexAreaMapAffine_Tilemap[] = INCBIN_U32("graphics/pokedex/region_map_affine.bin.smolTM");

const u16 *GetPokedexAreaMapPal(void)
{
    switch (GetCurrentRegion())
    {
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
    DebugPrintf("GetCurrentRegionMapBgPal[Default]: Returning Hoenn Palette");
    return sPokedexAreaMap_Pal_Hoenn;
}

const u32 *GetPokedexAreaMapGfx(void)
{
    switch (GetCurrentRegion())
    {
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
    DebugPrintf("GetCurrentRegionMapBgPal[Default]: Returning Hoenn Graphics");
    return sPokedexAreaMap_Gfx_Hoenn;
}

const u32 *GetPokedexAreaMapTilemap(void)
{
    switch (GetCurrentRegion())
    {
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
    DebugPrintf("GetCurrentRegionMapBgPal[Default]: Returning Hoenn Tilemap");
    return sPokedexAreaMap_Tilemap_Hoenn;
}

void LoadPokedexAreaMapGfx(const struct PokedexAreaMapTemplate *template)
{
    u8 mode;
    void *tilemap;
    sPokedexAreaMapBgNum = Alloc(sizeof(sPokedexAreaMapBgNum));
    mode = template->mode;

    if (mode == 0)
    {
        SetBgAttribute(template->bg, BG_ATTR_METRIC, 0);
        DecompressAndCopyTileDataToVram(template->bg, GetPokedexAreaMapGfx(), 0, template->offset, 0);
        tilemap = DecompressAndCopyTileDataToVram(template->bg, GetPokedexAreaMapTilemap(), 0, 0, 1);
        AddValToTilemapBuffer(tilemap, template->offset, 32, 32, FALSE); // template->offset is always 0, so this does nothing.
    }
    else
    {
        // This is never reached, only a mode of 0 is given
        SetBgAttribute(template->bg, BG_ATTR_METRIC, 2);
        SetBgAttribute(template->bg, BG_ATTR_TYPE, BG_TYPE_AFFINE); // This does nothing. BG_ATTR_TYPE can't be set with this function
        DecompressAndCopyTileDataToVram(template->bg, sPokedexAreaMapAffine_Gfx, 0, template->offset, 0);
        tilemap = DecompressAndCopyTileDataToVram(template->bg, sPokedexAreaMapAffine_Tilemap, 0, 0, 1);
        AddValToTilemapBuffer(tilemap, template->offset, 64, 64, TRUE); // template->offset is always 0, so this does nothing.
    }

    ChangeBgX(template->bg, 0, BG_COORD_SET);
    ChangeBgY(template->bg, 0, BG_COORD_SET);
    SetBgAttribute(template->bg, BG_ATTR_PALETTEMODE, 1);
    CpuCopy32(GetPokedexAreaMapPal(), &gPlttBufferUnfaded[BG_PLTT_ID(7)], sizeof(GetPokedexAreaMapPal()));
    *sPokedexAreaMapBgNum = template->bg;
}

bool32 TryShowPokedexAreaMap(void)
{
    if (!FreeTempTileDataBuffersIfPossible())
    {
        ShowBg(*sPokedexAreaMapBgNum);
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void FreePokedexAreaMapBgNum(void)
{
    TRY_FREE_AND_SET_NULL(sPokedexAreaMapBgNum);
}

void PokedexAreaMapChangeBgY(u32 move)
{
    ChangeBgY(*sPokedexAreaMapBgNum, move * 0x100, BG_COORD_SET);
}
