#include "global.h"
#include "string_util.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "region_map.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "script.h"
#include "overworld.h"
#include "event_data.h"
#include "map_preview_screen.h"
#include "constants/region_map_sections.h"
#include "constants/rgb.h"

static EWRAM_DATA bool8 sAllocedBg0TilemapBuffer = FALSE;

static void Task_RunMapPreviewScreenForest(u8 taskId);
static void Task_RunMapPreview_Script(u8 taskId);
static void CB2_MapPreviewScript(void);
static void VblankCB_MapPreviewScript(void);

static const u8 sViridianForestMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/viridian_forest/tiles.gbapal");
static const u8 sViridianForestMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/viridian_forest/tiles.4bpp.lz");
static const u8 sViridianForestMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/viridian_forest/tilemap.bin.lz");
static const u8 sRockTunnelMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/rock_tunnel/tiles.gbapal");
static const u8 sRockTunnelMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/rock_tunnel/tiles.4bpp.lz");
static const u8 sRockTunnelMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/rock_tunnel/tilemap.bin.lz");
static const u8 sRocketHideoutMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/rocket_hideout/tiles.gbapal");
static const u8 sRocketHideoutMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/rocket_hideout/tiles.4bpp.lz");
static const u8 sRocketHideoutMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/rocket_hideout/tilemap.bin.lz");
static const u8 sPowerPlantMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/power_plant/tiles.gbapal");
static const u8 sPowerPlantMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/power_plant/tiles.4bpp.lz");
static const u8 sPowerPlantMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/power_plant/tilemap.bin.lz");
static const u8 sPokemonMansionMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/pokemon_mansion/tiles.gbapal");
static const u8 sPokemonMansionMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/pokemon_mansion/tiles.4bpp.lz");
static const u8 sPokemonMansionMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/pokemon_mansion/tilemap.bin.lz");
static const u8 sPokemonTowerMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/pokemon_tower/tiles.gbapal");
static const u8 sPokemonTowerMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/pokemon_tower/tiles.4bpp.lz");
static const u8 sPokemonTowerMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/pokemon_tower/tilemap.bin.lz");
static const u8 sSilphCoMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/silph_co/tiles.gbapal");
static const u8 sSilphCoMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/silph_co/tiles.4bpp.lz");
static const u8 sSilphCoMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/silph_co/tilemap.bin.lz");
static const u8 sMtMoonMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/mt_moon/tiles.gbapal");
static const u8 sMtMoonMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/mt_moon/tiles.4bpp.lz");
static const u8 sMtMoonMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/mt_moon/tilemap.bin.lz");
static const u8 sSeafoamIslandsMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/seafoam_islands/tiles.gbapal");
static const u8 sSeafoamIslandsMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/seafoam_islands/tiles.4bpp.lz");
static const u8 sSeafoamIslandsMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/seafoam_islands/tilemap.bin.lz");
static const u8 sRocketWarehouseMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/rocket_warehouse/tiles.gbapal");
static const u8 sRocketWarehouseMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/rocket_warehouse/tiles.4bpp.lz");
static const u8 sRocketWarehouseMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/rocket_warehouse/tilemap.bin.lz");
static const u8 sVictoryRoadMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/victory_road/tiles.gbapal");
static const u8 sVictoryRoadMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/victory_road/tiles.4bpp.lz");
static const u8 sVictoryRoadMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/victory_road/tilemap.bin.lz");
static const u8 sMtEmberMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/mt_ember/tiles.gbapal");
static const u8 sMtEmberMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/mt_ember/tiles.4bpp.lz");
static const u8 sMtEmberMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/mt_ember/tilemap.bin.lz");
static const u8 sSafariZoneMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/safari_zone/tiles.gbapal");
static const u8 sSafariZoneMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/safari_zone/tiles.4bpp.lz");
static const u8 sSafariZoneMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/safari_zone/tilemap.bin.lz");
static const u8 sMoneanChamberMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/monean_chamber/tiles.gbapal");
static const u8 sMoneanChamberMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/monean_chamber/tiles.4bpp.lz");
static const u8 sMoneanChamberMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/monean_chamber/tilemap.bin.lz");
static const u8 sDottedHoleMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/dotted_hole/tiles.gbapal");
static const u8 sDottedHoleMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/dotted_hole/tiles.4bpp.lz");
static const u8 sDottedHoleMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/dotted_hole/tilemap.bin.lz");
static const u8 sCeruleanCaveMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/cerulean_cave/tiles.gbapal");
static const u8 sCeruleanCaveMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/cerulean_cave/tiles.4bpp.lz");
static const u8 sCeruleanCaveMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/cerulean_cave/tilemap.bin.lz");
static const u8 sDiglettsCaveMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/digletts_cave/tiles.gbapal");
static const u8 sDiglettsCaveMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/digletts_cave/tiles.4bpp.lz");
static const u8 sDiglettsCaveMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/digletts_cave/tilemap.bin.lz");
static const u8 sLostCaveMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/lost_cave/tiles.gbapal");
static const u8 sLostCaveMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/lost_cave/tiles.4bpp.lz");
static const u8 sLostCaveMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/lost_cave/tilemap.bin.lz");
static const u8 sBerryForestMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/berry_forest/tiles.gbapal");
static const u8 sBerryForestMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/berry_forest/tiles.4bpp.lz");
static const u8 sBerryForestMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/berry_forest/tilemap.bin.lz");
static const u8 sIcefallCaveMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/icefall_cave/tiles.gbapal");
static const u8 sIcefallCaveMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/icefall_cave/tiles.4bpp.lz");
static const u8 sIcefallCaveMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/icefall_cave/tilemap.bin.lz");
static const u8 sAlteringCaveMapPreviewPalette[] = INCBIN_U8("graphics/map_preview/altering_cave/tiles.gbapal");
static const u8 sAlteringCaveMapPreviewTiles[] = INCBIN_U8("graphics/map_preview/altering_cave/tiles.4bpp.lz");
static const u8 sAlteringCaveMapPreviewTilemap[] = INCBIN_U8("graphics/map_preview/altering_cave/tilemap.bin.lz");

// If you set flagId to MPS_FLAG_NULL, it will not set a flag when visiting the map for the first time
// and the duration will default to MPS_DURATION_NO_FLAG.
static const struct MapPreviewScreen sMapPreviewScreenData[MPS_COUNT] = {
    [MPS_PETALBURG_WOODS] = {
        .mapsec = MAPSEC_PETALBURG_WOODS,
        .type = MPS_TYPE_FADE_IN,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_VIRIDIAN_FOREST
    },
    [MPS_MT_MOON] = {
        .mapsec = MAPSEC_MT_MOON,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MT_MOON
    },
    [MPS_DIGLETTS_CAVE] = {
        .mapsec = MAPSEC_DIGLETTS_CAVE,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_DIGLETTS_CAVE
    },
    [MPS_ROCK_TUNNEL] = {
        .mapsec = MAPSEC_ROCK_TUNNEL,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_ROCK_TUNNEL
    },
    [MPS_POKEMON_TOWER] = {
        .mapsec = MAPSEC_POKEMON_TOWER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_POKEMON_TOWER
    },
    [MPS_SAFARI_ZONE] = {
        .mapsec = MAPSEC_KANTO_SAFARI_ZONE,
        .type = MPS_TYPE_FADE_IN,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_SAFARI_ZONE
    },
    [MPS_SEAFOAM_ISLANDS] = {
        .mapsec = MAPSEC_SEAFOAM_ISLANDS,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_SEAFOAM_ISLANDS
    },
    [MPS_POKEMON_MANSION] = {
        .mapsec = MAPSEC_POKEMON_MANSION,
        .type = MPS_TYPE_FADE_IN,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_POKEMON_MANSION
    },
    [MPS_ROCKET_HIDEOUT] = {
        .mapsec = MAPSEC_ROCKET_HIDEOUT,
        .type = MPS_TYPE_FADE_IN,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_ROCKET_HIDEOUT
    },
    [MPS_SILPH_CO] = {
        .mapsec = MAPSEC_SILPH_CO,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_SILPH_CO
    },
    [MPS_VICTORY_ROAD] = {
        .mapsec = MAPSEC_KANTO_VICTORY_ROAD,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_VICTORY_ROAD
    },
    [MPS_CERULEAN_CAVE] = {
        .mapsec = MAPSEC_CERULEAN_CAVE,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_CERULEAN_CAVE
    },
    [MPS_POWER_PLANT] = {
        .mapsec = MAPSEC_POWER_PLANT,
        .type = MPS_TYPE_FADE_IN,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_POWER_PLANT
    },
    [MPS_MT_EMBER] = {
        .mapsec = MAPSEC_MT_EMBER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MT_EMBER
    },
    [MPS_ROCKET_WAREHOUSE] = {
        .mapsec = MAPSEC_ROCKET_WAREHOUSE,
        .type = MPS_TYPE_FADE_IN,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_ROCKET_WAREHOUSE
    },
    [MPS_MONEAN_CHAMBER] = {
        .mapsec = MAPSEC_MONEAN_CHAMBER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MONEAN_CHAMBER
    },
    [MPS_DOTTED_HOLE] = {
        .mapsec = MAPSEC_DOTTED_HOLE,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_DOTTED_HOLE
    },
    [MPS_BERRY_FOREST] = {
        .mapsec = MAPSEC_BERRY_FOREST,
        .type = MPS_TYPE_FADE_IN,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_BERRY_FOREST
    },
    [MPS_ICEFALL_CAVE] = {
        .mapsec = MAPSEC_ICEFALL_CAVE,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_ICEFALL_CAVE
    },
    [MPS_LOST_CAVE] = {
        .mapsec = MAPSEC_LOST_CAVE,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_LOST_CAVE
    },
    [MPS_ALTERING_CAVE] = {
        .mapsec = MAPSEC_ALTERING_CAVE,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_ALTERING_CAVE
    },
    [MPS_PATTERN_BUSH] = {
        .mapsec = MAPSEC_PATTERN_BUSH,
        .type = MPS_TYPE_FADE_IN,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_VIRIDIAN_FOREST
    },
    [MPS_LIPTOO_CHAMBER] = {
        .mapsec = MAPSEC_LIPTOO_CHAMBER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MONEAN_CHAMBER
    },
    [MPS_WEEPTH_CHAMBER] = {
        .mapsec = MAPSEC_WEEPTH_CHAMBER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MONEAN_CHAMBER
    },
    [MPS_TDILFORD_CHAMBER] = {
        .mapsec = MAPSEC_DILFORD_CHAMBER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MONEAN_CHAMBER
    },
    [MPS_SCUFIB_CHAMBER] = {
        .mapsec = MAPSEC_SCUFIB_CHAMBER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MONEAN_CHAMBER
    },
    [MPS_RIXY_CHAMBER] = {
        .mapsec = MAPSEC_RIXY_CHAMBER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MONEAN_CHAMBER
    },
    [MPS_VIAPOIS_CHAMBER] = {
        .mapsec = MAPSEC_VIAPOIS_CHAMBER,
        .type = MPS_TYPE_CAVE,
        .flagId = MPS_FLAG_NULL,
        .image = IMG_MONEAN_CHAMBER
    }
};

static const struct ImageData sMapPreviewImageData[IMG_COUNT] = {
    [IMG_VIRIDIAN_FOREST] = {
        .tilesptr = sViridianForestMapPreviewTiles,
        .tilemapptr = sViridianForestMapPreviewTilemap,
        .palptr = sViridianForestMapPreviewPalette
    },
    [IMG_MT_MOON] = {
        .tilesptr = sMtMoonMapPreviewTiles,
        .tilemapptr = sMtMoonMapPreviewTilemap,
        .palptr = sMtMoonMapPreviewPalette
    },
    [IMG_DIGLETTS_CAVE] = {
        .tilesptr = sDiglettsCaveMapPreviewTiles,
        .tilemapptr = sDiglettsCaveMapPreviewTilemap,
        .palptr = sDiglettsCaveMapPreviewPalette
    },
    [IMG_ROCK_TUNNEL] = {
        .tilesptr = sRockTunnelMapPreviewTiles,
        .tilemapptr = sRockTunnelMapPreviewTilemap,
        .palptr = sRockTunnelMapPreviewPalette
    },
    [IMG_POKEMON_TOWER] = {
        .tilesptr = sPokemonTowerMapPreviewTiles,
        .tilemapptr = sPokemonTowerMapPreviewTilemap,
        .palptr = sPokemonTowerMapPreviewPalette
    },
    [IMG_SAFARI_ZONE] = {
        .tilesptr = sSafariZoneMapPreviewTiles,
        .tilemapptr = sSafariZoneMapPreviewTilemap,
        .palptr = sSafariZoneMapPreviewPalette
    },
    [IMG_SEAFOAM_ISLANDS] = {
        .tilesptr = sSeafoamIslandsMapPreviewTiles,
        .tilemapptr = sSeafoamIslandsMapPreviewTilemap,
        .palptr = sSeafoamIslandsMapPreviewPalette
    },
    [IMG_POKEMON_MANSION] = {
        .tilesptr = sPokemonMansionMapPreviewTiles,
        .tilemapptr = sPokemonMansionMapPreviewTilemap,
        .palptr = sPokemonMansionMapPreviewPalette
    },
    [IMG_ROCKET_HIDEOUT] = {
        .tilesptr = sRocketHideoutMapPreviewTiles,
        .tilemapptr = sRocketHideoutMapPreviewTilemap,
        .palptr = sRocketHideoutMapPreviewPalette
    },
    [IMG_SILPH_CO] = {
        .tilesptr = sSilphCoMapPreviewTiles,
        .tilemapptr = sSilphCoMapPreviewTilemap,
        .palptr = sSilphCoMapPreviewPalette
    },
    [IMG_VICTORY_ROAD] = {
        .tilesptr = sVictoryRoadMapPreviewTiles,
        .tilemapptr = sVictoryRoadMapPreviewTilemap,
        .palptr = sVictoryRoadMapPreviewPalette
    },
    [IMG_CERULEAN_CAVE] = {
        .tilesptr = sCeruleanCaveMapPreviewTiles,
        .tilemapptr = sCeruleanCaveMapPreviewTilemap,
        .palptr = sCeruleanCaveMapPreviewPalette
    },
    [IMG_POWER_PLANT] = {
        .tilesptr = sPowerPlantMapPreviewTiles,
        .tilemapptr = sPowerPlantMapPreviewTilemap,
        .palptr = sPowerPlantMapPreviewPalette
    },
    [IMG_MT_EMBER] = {
        .tilesptr = sMtEmberMapPreviewTiles,
        .tilemapptr = sMtEmberMapPreviewTilemap,
        .palptr = sMtEmberMapPreviewPalette
    },
    [IMG_ROCKET_WAREHOUSE] = {
        .tilesptr = sRocketWarehouseMapPreviewTiles,
        .tilemapptr = sRocketWarehouseMapPreviewTilemap,
        .palptr = sRocketWarehouseMapPreviewPalette
    },
    [IMG_MONEAN_CHAMBER] = {
        .tilesptr = sMoneanChamberMapPreviewTiles,
        .tilemapptr = sMoneanChamberMapPreviewTilemap,
        .palptr = sMoneanChamberMapPreviewPalette
    },
    [IMG_DOTTED_HOLE] = {
        .tilesptr = sDottedHoleMapPreviewTiles,
        .tilemapptr = sDottedHoleMapPreviewTilemap,
        .palptr = sDottedHoleMapPreviewPalette
    },
    [IMG_BERRY_FOREST] = {
        .tilesptr = sBerryForestMapPreviewTiles,
        .tilemapptr = sBerryForestMapPreviewTilemap,
        .palptr = sBerryForestMapPreviewPalette
    },
    [IMG_ICEFALL_CAVE] = {
        .tilesptr = sIcefallCaveMapPreviewTiles,
        .tilemapptr = sIcefallCaveMapPreviewTilemap,
        .palptr = sIcefallCaveMapPreviewPalette
    },
    [IMG_LOST_CAVE] = {
        .tilesptr = sLostCaveMapPreviewTiles,
        .tilemapptr = sLostCaveMapPreviewTilemap,
        .palptr = sLostCaveMapPreviewPalette
    },
    [IMG_ALTERING_CAVE] = {
        .tilesptr = sAlteringCaveMapPreviewTiles,
        .tilemapptr = sAlteringCaveMapPreviewTilemap,
        .palptr = sAlteringCaveMapPreviewPalette
    }
};

static const struct WindowTemplate sMapNameWindow = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 13,
    .height = 2,
    .paletteNum = 14,
    .baseBlock = 0x1C2
};

static const struct WindowTemplate sMapNameWindowLarge = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 22,
    .height = 2,
    .paletteNum = 14,
    .baseBlock = 0x1C2
};

static const struct BgTemplate sMapPreviewBgTemplate[1] = {
    {
        .mapBaseIndex = 31
    }
};

static u8 GetMapPreviewScreenIdx(u8 mapsec)
{
    s32 i;

    for (i = 0; i < MPS_COUNT; i++)
    {
        if (sMapPreviewScreenData[i].mapsec == mapsec)
        {
            return i;
        }
    }
    return MPS_COUNT;
}

bool8 MapHasPreviewScreen(u8 mapsec, u8 type)
{
    u8 idx;

    idx = GetMapPreviewScreenIdx(mapsec);
    if (idx != MPS_COUNT)
    {
        if (type == MPS_TYPE_ANY)
        {
            return TRUE;
        }
        else
        {
            return sMapPreviewScreenData[idx].type == type ? TRUE : FALSE;
        }
    }
    else
    {
        return FALSE;
    }
}

bool32 MapHasPreviewScreen_HandleQLState2(u8 mapsec, u8 type)
{
    return MapHasPreviewScreen(mapsec, type);
}

void MapPreview_InitBgs(void)
{
    InitBgsFromTemplates(0, sMapPreviewBgTemplate, NELEMS(sMapPreviewBgTemplate));
    ShowBg(0);
}

void MapPreview_LoadGfx(u8 mapsec)
{
    u8 idx;

    idx = GetMapPreviewScreenIdx(mapsec);
    if (idx != MPS_COUNT)
    {
       ResetTempTileDataBuffers();
       if (MapHasPreviewScreen_HandleQLState2(gMapHeader.regionMapSectionId, MPS_TYPE_FADE_IN) == TRUE)
            LoadPalette(sMapPreviewImageData[sMapPreviewScreenData[idx].image].palptr, BG_PLTT_ID(13), 3 * PLTT_SIZE_4BPP);
        else
            LoadPalette(sMapPreviewImageData[sMapPreviewScreenData[idx].image].palptr, BG_PLTT_ID(0), 16 * PLTT_SIZE_4BPP);
            
       DecompressAndCopyTileDataToVram(0, sMapPreviewImageData[sMapPreviewScreenData[idx].image].tilesptr, 0, 0, 0);
       if (GetBgTilemapBuffer(0) == NULL)
       {
           SetBgTilemapBuffer(0, Alloc(BG_SCREEN_SIZE));
           sAllocedBg0TilemapBuffer = TRUE;
       }
       else
       {
           sAllocedBg0TilemapBuffer = FALSE;
       }
       CopyToBgTilemapBuffer(0, sMapPreviewImageData[sMapPreviewScreenData[idx].image].tilemapptr, 0, 0x000);
       CopyBgTilemapBufferToVram(0);
    }
}

void MapPreview_Unload(s32 windowId)
{
    RemoveWindow(windowId);
    if (sAllocedBg0TilemapBuffer)
    {
        Free(GetBgTilemapBuffer(0));
    }
}

bool32 MapPreview_IsGfxLoadFinished(void)
{
    return FreeTempTileDataBuffersIfPossible();
}

void MapPreview_StartForestTransition(u8 mapsec)
{
    u8 taskId;

    taskId = CreateTask(Task_RunMapPreviewScreenForest, 0);
    gTasks[taskId].data[2] = GetBgAttribute(0, BG_ATTR_PRIORITY);
    gTasks[taskId].data[4] = GetGpuReg(REG_OFFSET_BLDCNT);
    gTasks[taskId].data[5] = GetGpuReg(REG_OFFSET_BLDALPHA);
    gTasks[taskId].data[3] = GetGpuReg(REG_OFFSET_DISPCNT);
    gTasks[taskId].data[6] = GetGpuReg(REG_OFFSET_WININ);
    gTasks[taskId].data[7] = GetGpuReg(REG_OFFSET_WINOUT);
    gTasks[taskId].data[10] = MapPreview_GetDuration(mapsec);
    gTasks[taskId].data[8] = 16;
    gTasks[taskId].data[9] = 0;
    SetBgAttribute(0, BG_ATTR_PRIORITY, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
    SetGpuRegBits(REG_OFFSET_WININ, WININ_WIN0_CLR | WININ_WIN1_CLR);
    SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WIN01_CLR);
    gTasks[taskId].data[11] = MapPreview_CreateMapNameWindow(mapsec);
    LockPlayerFieldControls();
}

u16 MapPreview_CreateMapNameWindow(u8 mapsec)
{
    u16 windowId;
    u32 xctr;
    #ifdef BUGFIX
    // Fixes access violations indicated below.
    u8 color[3];
    #else
    u8 color[0];
    #endif

    GetMapName(gStringVar4, mapsec, 0);
    if (GetStringWidth(FONT_NORMAL, gStringVar4, 0) > 104)
    {
        windowId = AddWindow(&sMapNameWindowLarge);
        xctr = 177 - GetStringWidth(FONT_NORMAL, gStringVar4, 0);
    }
    else
    {
        xctr = 104 - GetStringWidth(FONT_NORMAL, gStringVar4, 0);
        windowId = AddWindow(&sMapNameWindow);
    }
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    color[0] = TEXT_COLOR_WHITE; // Access violation
    color[1] = TEXT_COLOR_RED; // Access violation
    color[2] = TEXT_COLOR_LIGHT_GRAY; // Access violation
    AddTextPrinterParameterized4(windowId, FONT_NORMAL, xctr / 2, 2, 0, 0, color/* Access violation */, -1, gStringVar4);
    return windowId;
}

bool32 ForestMapPreviewScreenIsRunning(void)
{
    if (FuncIsActiveTask(Task_RunMapPreviewScreenForest) == TRUE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void Task_RunMapPreviewScreenForest(u8 taskId)
{
    s16 * data;

    data = gTasks[taskId].data;
    switch (data[0])
    {
    case 0:
        if (!MapPreview_IsGfxLoadFinished() && !IsDma3ManagerBusyWithBgCopy())
        {
            CopyWindowToVram(data[11], COPYWIN_FULL);
            data[0]++;
        }
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            FadeInFromBlack();
            data[0]++;
        }
        break;
    case 2:
        if (IsWeatherNotFadingIn())
        {
            Overworld_PlaySpecialMapMusic();
            data[0]++;
        }
        break;
    case 3:
        data[1]++;
        if (data[1] > data[10] || JOY_HELD(B_BUTTON))
        {
            data[1] = 0;
            data[0]++;
        }
        break;
    case 4:
        switch (data[1])
        {
        case 0:
            data[9]++;
            if (data[9] > 16)
            {
                data[9] = 16;
            }
            break;
        case 1:
            data[8]--;
            if (data[8] < 0)
            {
                data[8] = 0;
            }
            break;
        }
        data[1] = (data[1] + 1) % 3;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(data[8], data[9]));
        if (data[8] == 0 && data[9] == 16)
        {
            FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
            CopyBgTilemapBufferToVram(0);
            data[0]++;
        }
        break;
    case 5:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            MapPreview_Unload(data[11]);
            SetBgAttribute(0, BG_ATTR_PRIORITY, data[2]);
            SetGpuReg(REG_OFFSET_DISPCNT, data[3]);
            SetGpuReg(REG_OFFSET_BLDCNT, data[4]);
            SetGpuReg(REG_OFFSET_BLDALPHA, data[5]);
            SetGpuReg(REG_OFFSET_WININ, data[6]);
            SetGpuReg(REG_OFFSET_WINOUT, data[7]);
            DestroyTask(taskId);
        }
        break;
    }
}

const struct MapPreviewScreen * GetDungeonMapPreviewScreenInfo(u8 mapsec)
{
    u8 idx;

    idx = GetMapPreviewScreenIdx(mapsec);
    if (idx == MPS_COUNT)
    {
        return NULL;
    }
    else
    {
        return &sMapPreviewScreenData[idx];
    }
}

u16 MapPreview_GetDuration(u8 mapsec)
{
    u8 idx;
    u16 flagId;

    idx = GetMapPreviewScreenIdx(mapsec);

    if (idx == MPS_COUNT)
    {
        return 0;
    }

    flagId = sMapPreviewScreenData[idx].flagId;

    if (flagId == MPS_FLAG_NULL) {
        if (MPS_DURATION_ALWAYS != 0) {
            return MPS_DURATION_ALWAYS;
        }
        else
        {
            return MPS_DURATION_NO_FLAG;
        }
    }
    else if (MPS_DURATION_ALWAYS != 0) {
        if (!FlagGet(flagId))
        {
            FlagSet(flagId);
        }
        return MPS_DURATION_ALWAYS;
    }
    else {
        if (!FlagGet(flagId))
        {
            FlagSet(flagId);
            return MPS_DURATION_LONG;
        }
        else
        {
            return MPS_DURATION_SHORT;
        }
    }
}

static void VblankCB_MapPreviewScript(void)
{
    TransferPlttBuffer();
}

#define taskStep        data[0]
#define frameCounter    data[1]
#define MPWindowId      data[2]

void Script_MapPreview(void)
{
    SetVBlankCallback(NULL);
    gMain.savedCallback = CB2_ReturnToFieldContinueScript;
    MapPreview_LoadGfx(gMapHeader.regionMapSectionId);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
    SetVBlankCallback(VblankCB_MapPreviewScript);
    SetMainCallback2(CB2_MapPreviewScript);
    CreateTask(Task_RunMapPreview_Script, 0);
}

static void CB2_MapPreviewScript(void)
{
    RunTasks();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Task_RunMapPreview_Script(u8 taskId)
{
    s16 * data;

    data = gTasks[taskId].data;
    switch (taskStep)
    {
    case 0:
        if (!MapPreview_IsGfxLoadFinished() && !IsDma3ManagerBusyWithBgCopy())
        {
            MPWindowId = MapPreview_CreateMapNameWindow(gMapHeader.regionMapSectionId);
            CopyWindowToVram(MPWindowId, COPYWIN_FULL);
            taskStep++;
        }
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            FadeInFromBlack();
            taskStep++;
        }
        break;
    case 2:
        frameCounter++;
        if (frameCounter > MPS_DURATION_SCRIPT || JOY_HELD(B_BUTTON))
        {
            BeginNormalPaletteFade(PALETTES_ALL, MPS_BASIC_FADE_SPEED, 0, 16, RGB_BLACK);
            frameCounter = 0;
            taskStep++;
        }
        break;
    case 3:
        if (!UpdatePaletteFade())
        {
            MapPreview_Unload(MPWindowId);
            DestroyTask(taskId);
            SetMainCallback2(gMain.savedCallback);
        }
        break;
    }
}

#undef taskStep
#undef frameCounter
#undef MPWindowId
