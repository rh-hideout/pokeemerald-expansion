#include "global.h"
#include "main.h"
#include "menu.h"
#include "bg.h"
#include "malloc.h"
#include "palette.h"
#include "pokedex_area_region_map.h"
#include "regions.h"

static EWRAM_DATA u8 *sPokedexAreaMapBgNum = NULL;

static const u16 ALIGNED(4) sPokedexAreaMap_Pal[] = INCBIN_U16("graphics/pokedex/region_map.gbapal");
static const u32 sPokedexAreaMap_Gfx[] = INCBIN_U32("graphics/pokedex/region_map.8bpp.smol");
static const u32 sPokedexAreaMap_Tilemap[] = INCBIN_U32("graphics/pokedex/region_map.bin.smolTM");
static const u32 sPokedexAreaMapAffine_Gfx[] = INCBIN_U32("graphics/pokedex/region_map_affine.8bpp.smol");
static const u32 sPokedexAreaMapAffine_Tilemap[] = INCBIN_U32("graphics/pokedex/region_map_affine.bin.smolTM");
static const u16 ALIGNED(4) sPokedexAreaMapKanto_Pal[] = INCBIN_U16("graphics/pokedex/region_map_kanto.gbapal");
static const u32 sPokedexAreaMapKanto_Gfx[] = INCBIN_U32("graphics/pokedex/region_map_kanto.8bpp.smol");
static const u32 sPokedexAreaMapKanto_Tilemap[] = INCBIN_U32("graphics/pokedex/region_map_kanto.bin.smolTM");
static const u16 ALIGNED(4) sPokedexAreaMapSevii123_Pal[] = INCBIN_U16("graphics/pokedex/region_map_sevii123.gbapal");
static const u32 sPokedexAreaMapSevii123_Gfx[] = INCBIN_U32("graphics/pokedex/region_map_sevii123.8bpp.smol");
static const u32 sPokedexAreaMapSevii123_Tilemap[] = INCBIN_U32("graphics/pokedex/region_map_sevii123.bin.smolTM");
static const u16 ALIGNED(4) sPokedexAreaMapSevii45_Pal[] = INCBIN_U16("graphics/pokedex/region_map_sevii45.gbapal");
static const u32 sPokedexAreaMapSevii45_Gfx[] = INCBIN_U32("graphics/pokedex/region_map_sevii45.8bpp.smol");
static const u32 sPokedexAreaMapSevii45_Tilemap[] = INCBIN_U32("graphics/pokedex/region_map_sevii45.bin.smolTM");
static const u16 ALIGNED(4) sPokedexAreaMapSevii67_Pal[] = INCBIN_U16("graphics/pokedex/region_map_sevii67.gbapal");
static const u32 sPokedexAreaMapSevii67_Gfx[] = INCBIN_U32("graphics/pokedex/region_map_sevii67.8bpp.smol");
static const u32 sPokedexAreaMapSevii67_Tilemap[] = INCBIN_U32("graphics/pokedex/region_map_sevii67.bin.smolTM");

static const u32 *GetDexAreaMapTilemap()
{
    switch (GetCurrentRegion())
    {
        case REGION_KANTO:
            switch (GetKantoSubmap(gMapHeader.regionMapSectionId))
            {
            case KANTO_SUB_SEVII123:
                return sPokedexAreaMapSevii123_Tilemap;
            case KANTO_SUB_SEVII45:
                return sPokedexAreaMapSevii45_Tilemap;
            case KANTO_SUB_SEVII67:
                return sPokedexAreaMapSevii67_Tilemap;
            case KANTO_SUB_KANTO:
            default:
                return sPokedexAreaMapKanto_Tilemap;
            }
        case REGION_HOENN:
        default:
            return sPokedexAreaMap_Tilemap;
    }
}

static const u32 *GetDexAreaMapGfx()
{
    switch (GetCurrentRegion())
    {
        case REGION_KANTO:
            switch (GetKantoSubmap(gMapHeader.regionMapSectionId))
            {
            case KANTO_SUB_SEVII123:
                return sPokedexAreaMapSevii123_Gfx;
            case KANTO_SUB_SEVII45:
                return sPokedexAreaMapSevii45_Gfx;
            case KANTO_SUB_SEVII67:
                return sPokedexAreaMapSevii67_Gfx;
            case KANTO_SUB_KANTO:
            default:
                return sPokedexAreaMapKanto_Gfx;
            }
        case REGION_HOENN:
        default:
            return sPokedexAreaMap_Gfx;
    }
}

static const u16 *GetDexAreaMapPalette()
{
    switch (GetCurrentRegion())
    {
        case REGION_KANTO:
            switch (GetKantoSubmap(gMapHeader.regionMapSectionId))
            {
            case KANTO_SUB_SEVII123:
                return sPokedexAreaMapSevii123_Pal;
            case KANTO_SUB_SEVII45:
                return sPokedexAreaMapSevii45_Pal;
            case KANTO_SUB_SEVII67:
                return sPokedexAreaMapSevii67_Pal;
            case KANTO_SUB_KANTO:
            default:
                return sPokedexAreaMapKanto_Pal;
            }
        case REGION_HOENN:
        default:
            return sPokedexAreaMap_Pal;
    }
}

static u32 GetDexAreaMapPaletteSize()
{
    switch (GetCurrentRegion())
    {
        case REGION_KANTO:
            switch (GetKantoSubmap(gMapHeader.regionMapSectionId))
            {
            case KANTO_SUB_SEVII123:
                return sizeof(sPokedexAreaMapSevii123_Pal);
            case KANTO_SUB_SEVII45:
                return sizeof(sPokedexAreaMapSevii45_Pal);
            case KANTO_SUB_SEVII67:
                return sizeof(sPokedexAreaMapSevii67_Pal);
            case KANTO_SUB_KANTO:
            default:
                return sizeof(sPokedexAreaMapKanto_Pal);
            }
        case REGION_HOENN:
        default:
            return sizeof(sPokedexAreaMap_Pal);
    }
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
        DecompressAndCopyTileDataToVram(template->bg, GetDexAreaMapGfx(), 0, template->offset, 0);
        tilemap = DecompressAndCopyTileDataToVram(template->bg, GetDexAreaMapTilemap(), 0, 0, 1);
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
    CpuCopy32(GetDexAreaMapPalette(), &gPlttBufferUnfaded[BG_PLTT_ID(7)], GetDexAreaMapPaletteSize());
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
