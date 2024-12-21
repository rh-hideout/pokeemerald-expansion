const u32 gBattleTerrainTiles_TallGrass[] = INCBIN_U32("graphics/battle_terrain/tall_grass/tiles.4bpp.lz");
const u32 gBattleTerrainPalette_TallGrass[] = INCBIN_U32("graphics/battle_terrain/tall_grass/palette.gbapal.lz");
const u32 gBattleTerrainTilemap_TallGrass[] = INCBIN_U32("graphics/battle_terrain/tall_grass/map.bin.lz");

const u32 gBattleTerrainTiles_LongGrass[] = INCBIN_U32("graphics/battle_terrain/long_grass/tiles.4bpp.lz");
const u32 gBattleTerrainPalette_LongGrass[] = INCBIN_U32("graphics/battle_terrain/long_grass/palette.gbapal.lz");
const u32 gBattleTerrainTilemap_LongGrass[] = INCBIN_U32("graphics/battle_terrain/long_grass/map.bin.lz");

const u32 gBattleTerrainTiles_Sand[] = INCBIN_U32("graphics/battle_terrain/sand/tiles.4bpp.lz");
const u32 gBattleTerrainPalette_Sand[] = INCBIN_U32("graphics/battle_terrain/sand/palette.gbapal.lz");
const u32 gBattleTerrainTilemap_Sand[] = INCBIN_U32("graphics/battle_terrain/sand/map.bin.lz");

const u32 gBattleTerrainTiles_Underwater[] = INCBIN_U32("graphics/battle_terrain/underwater/tiles.4bpp.lz");
const u32 gBattleTerrainPalette_Underwater[] = INCBIN_U32("graphics/battle_terrain/underwater/palette.gbapal.lz");
const u32 gBattleTerrainTilemap_Underwater[] = INCBIN_U32("graphics/battle_terrain/underwater/map.bin.lz");

const u32 gBattleTerrainTiles_Water[] = INCBIN_U32("graphics/battle_terrain/water/tiles.4bpp.lz");
const u32 gBattleTerrainPalette_Water[] = INCBIN_U32("graphics/battle_terrain/water/palette.gbapal.lz");
const u32 gBattleTerrainTilemap_Water[] = INCBIN_U32("graphics/battle_terrain/water/map.bin.lz");

const u32 gBattleTerrainTiles_PondWater[] = INCBIN_U32("graphics/battle_terrain/pond_water/tiles.4bpp.lz");
const u32 gBattleTerrainPalette_PondWater[] = INCBIN_U32("graphics/battle_terrain/pond_water/palette.gbapal.lz");
const u32 gBattleTerrainTilemap_PondWater[] = INCBIN_U32("graphics/battle_terrain/pond_water/map.bin.lz");

const u32 gBattleTerrainTiles_Rock[] = INCBIN_U32("graphics/battle_terrain/rock/tiles.4bpp.lz");
const u32 gBattleTerrainPalette_Rock[] = INCBIN_U32("graphics/battle_terrain/rock/palette.gbapal.lz");
const u32 gBattleTerrainTilemap_Rock[] = INCBIN_U32("graphics/battle_terrain/rock/map.bin.lz");

const u32 gBattleTerrainTiles_Cave[] = INCBIN_U32("graphics/battle_terrain/cave/tiles.4bpp.lz");
const u32 gBattleTerrainPalette_Cave[] = INCBIN_U32("graphics/battle_terrain/cave/palette.gbapal.lz");
const u32 gBattleTerrainTilemap_Cave[] = INCBIN_U32("graphics/battle_terrain/cave/map.bin.lz");

const u32 gBattleTerrainPalette_Plain[] = INCBIN_U32("graphics/battle_terrain/plain/palette.gbapal.lz");

const u32 gBattleTerrainTiles_Building[] = INCBIN_U32("graphics/battle_terrain/building/tiles.4bpp.lz");
const u32 gBattleTerrainPalette_Frontier[] = INCBIN_U32("graphics/battle_terrain/stadium/battle_frontier.gbapal.lz"); // this is also used for link battles
const u32 gBattleTerrainTilemap_Building[] = INCBIN_U32("graphics/battle_terrain/building/map.bin.lz");

#define TERRAIN_BACKGROUND(background)                       \
{                                                           \
    .tileset = gBattleTerrainTiles_##background,            \
    .tilemap = gBattleTerrainTilemap_##background,          \
    .entryTileset = gBattleTerrainAnimTiles_##background,   \
    .entryTilemap = gBattleTerrainAnimTilemap_##background, \
    .palette = gBattleTerrainPalette_##background,          \
}

const struct BattleTerrain gBattleTerrainInfo[BATTLE_TERRAIN_COUNT] =
{
    [BATTLE_TERRAIN_GRASS] =
    {
    #if B_NATURE_POWER_MOVES >= GEN_6
        .naturePower = MOVE_ENERGY_BALL,
    #elif B_NATURE_POWER_MOVES >= GEN_4
        .naturePower = MOVE_SEED_BOMB,
    #else
        .naturePower = MOVE_STUN_SPORE,
    #endif
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_4 ? MOVE_EFFECT_SLEEP : MOVE_EFFECT_POISON,
        .camouflageType = TYPE_GRASS,
        .background = TERRAIN_BACKGROUND(TallGrass),
    },

    [BATTLE_TERRAIN_LONG_GRASS] =
    {
    #if B_NATURE_POWER_MOVES >= GEN_6
        .naturePower = MOVE_ENERGY_BALL,
    #elif B_NATURE_POWER_MOVES >= GEN_4
        .naturePower = MOVE_SEED_BOMB,
    #else
        .naturePower = MOVE_RAZOR_LEAF,
    #endif
        .secretPowerEffect = MOVE_EFFECT_SLEEP,
        .camouflageType = TYPE_GRASS,
        .background = TERRAIN_BACKGROUND(LongGrass),
    },

    [BATTLE_TERRAIN_SAND] =
    {
        .naturePower = B_NATURE_POWER_MOVES >= GEN_6 ? MOVE_EARTH_POWER : MOVE_EARTHQUAKE,
        .secretPowerEffect = MOVE_EFFECT_ACC_MINUS_1,
        .camouflageType = TYPE_GROUND,
        .background = TERRAIN_BACKGROUND(Sand),
    },

    [BATTLE_TERRAIN_UNDERWATER] =
    {
        .naturePower = MOVE_HYDRO_PUMP,
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_6 ? MOVE_EFFECT_ATK_MINUS_1 : MOVE_EFFECT_DEF_MINUS_1,
        .camouflageType = TYPE_WATER,
        .background = TERRAIN_BACKGROUND(Underwater),
    },

    [BATTLE_TERRAIN_WATER] =
    {
        .naturePower = B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_HYDRO_PUMP : MOVE_SURF,
        .secretPowerEffect = MOVE_EFFECT_ATK_MINUS_1,
        .camouflageType = TYPE_WATER,
        .background = TERRAIN_BACKGROUND(Water),
    },

    [BATTLE_TERRAIN_POND] =
    {
        .naturePower = B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_HYDRO_PUMP : MOVE_BUBBLE_BEAM,
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_4 ? MOVE_EFFECT_ATK_MINUS_1 : MOVE_EFFECT_SPD_MINUS_1,
        .camouflageType = TYPE_WATER,
        .background = TERRAIN_BACKGROUND(PondWater),
    },

    [BATTLE_TERRAIN_MOUNTAIN] =
    {
    #if B_NATURE_POWER_MOVES >= GEN_6
        .naturePower = MOVE_EARTH_POWER,
    #elif B_NATURE_POWER_MOVES >= GEN_5
        .naturePower = MOVE_EARTHQUAKE,
    #else
        .naturePower = MOVE_ROCK_SLIDE,
    #endif
    #if B_SECRET_POWER_EFFECT >= GEN_5
        .secretPowerEffect = MOVE_EFFECT_ACC_MINUS_1,
    #elif B_SECRET_POWER_EFFECT >= GEN_4
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
    #else
        .secretPowerEffect = MOVE_EFFECT_CONFUSION,
    #endif
        .camouflageType = B_CAMOUFLAGE_TYPES >= GEN_5 ? TYPE_GROUND : TYPE_ROCK,
        .background = TERRAIN_BACKGROUND(Rock),
    },

    [BATTLE_TERRAIN_CAVE] =
    {
    #if B_NATURE_POWER_MOVES >= GEN_6
        .naturePower = MOVE_EARTH_POWER,
    #elif B_NATURE_POWER_MOVES >= GEN_5
        .naturePower = MOVE_EARTHQUAKE,
    #elif B_NATURE_POWER_MOVES >= GEN_4
        .naturePower = MOVE_ROCK_SLIDE,
    #else
        .naturePower = MOVE_SHADOW_BALL,
    #endif
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_ROCK,
        .background = TERRAIN_BACKGROUND(Cave),
    },

    [BATTLE_TERRAIN_BUILDING] =
    {
        .naturePower = B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_TRI_ATTACK : MOVE_SWIFT,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_NORMAL,
        .background = TERRAIN_BACKGROUND(Building),
    },

    [BATTLE_TERRAIN_PLAIN] =
    {
    #if B_NATURE_POWER_MOVES >= GEN_6
        .naturePower = MOVE_TRI_ATTACK,
    #elif B_NATURE_POWER_MOVES >= GEN_4
        .naturePower = MOVE_EARTHQUAKE,
    #else
        .naturePower = MOVE_SWIFT,
    #endif
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = B_CAMOUFLAGE_TYPES >= GEN_4 ? TYPE_GROUND : TYPE_NORMAL,
        .background =
        {
            .tileset = gBattleTerrainTiles_Building,
            .tilemap = gBattleTerrainTilemap_Building,
            .entryTileset = gBattleTerrainAnimTiles_Building,
            .entryTilemap = gBattleTerrainAnimTilemap_Building,
            .palette = gBattleTerrainPalette_Plain,
        },
    },

    [BATTLE_TERRAIN_FRONTIER] =
    {
        .background =
        {
            .tileset = gBattleTerrainTiles_Building,
            .tilemap = gBattleTerrainTilemap_Building,
            .entryTileset = gBattleTerrainAnimTiles_Building,
            .entryTilemap = gBattleTerrainAnimTilemap_Building,
            .palette = gBattleTerrainPalette_Frontier,
        },
    },

    [BATTLE_TERRAIN_GYM] =
    {
        .background =
        {
            .tileset = gBattleTerrainTiles_Building,
            .tilemap = gBattleTerrainTilemap_Building,
            .entryTileset = gBattleTerrainAnimTiles_Building,
            .entryTilemap = gBattleTerrainAnimTilemap_Building,
            .palette = gBattleTerrainPalette_BuildingGym,
        },
    },

    [BATTLE_TERRAIN_LEADER] =
    {
        .background =
        {
            .tileset = gBattleTerrainTiles_Building,
            .tilemap = gBattleTerrainTilemap_Building,
            .entryTileset = gBattleTerrainAnimTiles_Building,
            .entryTilemap = gBattleTerrainAnimTilemap_Building,
            .palette = gBattleTerrainPalette_BuildingLeader,
        },
    },

    [BATTLE_TERRAIN_MAGMA] =
    {
        .background =
        {
            .tileset = gBattleTerrainTiles_Stadium,
            .tilemap = gBattleTerrainTilemap_Stadium,
            .entryTileset = gBattleTerrainAnimTiles_Building,
            .entryTilemap = gBattleTerrainAnimTilemap_Building,
            .palette = gBattleTerrainPalette_StadiumMagma,
        },
    },

    [BATTLE_TERRAIN_AQUA] =
    {
        .background =
        {
            .tileset = gBattleTerrainTiles_Stadium,
            .tilemap = gBattleTerrainTilemap_Stadium,
            .entryTileset = gBattleTerrainAnimTiles_Building,
            .entryTilemap = gBattleTerrainAnimTilemap_Building,
            .palette = gBattleTerrainPalette_StadiumAqua,
        },
    },

    [BATTLE_TERRAIN_SIDNEY] =
    {
        .background =
        {
            .tileset = gBattleTerrainTiles_Stadium,
            .tilemap = gBattleTerrainTilemap_Stadium,
            .entryTileset = gBattleTerrainAnimTiles_Building,
            .entryTilemap = gBattleTerrainAnimTilemap_Building,
            .palette = gBattleTerrainPalette_StadiumSidney,
        },
    },

    [BATTLE_TERRAIN_PHOEBE] =
    {
        .background =
        {
            .tileset = gBattleTerrainTiles_Stadium,
            .tilemap = gBattleTerrainTilemap_Stadium,
            .entryTileset = gBattleTerrainAnimTiles_Building,
            .entryTilemap = gBattleTerrainAnimTilemap_Building,
            .palette = gBattleTerrainPalette_StadiumPhoebe,
        },
    },

    [BATTLE_TERRAIN_GLACIA] =
    {
        .background =
        {
            .tileset = gBattleTerrainTiles_Stadium,
            .tilemap = gBattleTerrainTilemap_Stadium,
            .entryTileset = gBattleTerrainAnimTiles_Building,
            .entryTilemap = gBattleTerrainAnimTilemap_Building,
            .palette = gBattleTerrainPalette_StadiumGlacia,
        },
    },

    [BATTLE_TERRAIN_DRAKE] =
    {
        .background =
        {
            .tileset = gBattleTerrainTiles_Stadium,
            .tilemap = gBattleTerrainTilemap_Stadium,
            .entryTileset = gBattleTerrainAnimTiles_Building,
            .entryTilemap = gBattleTerrainAnimTilemap_Building,
            .palette = gBattleTerrainPalette_StadiumDrake,
        },
    },

    [BATTLE_TERRAIN_CHAMPION] =
    {
        .background =
        {
            .tileset = gBattleTerrainTiles_Stadium,
            .tilemap = gBattleTerrainTilemap_Stadium,
            .entryTileset = gBattleTerrainAnimTiles_Building,
            .entryTilemap = gBattleTerrainAnimTilemap_Building,
            .palette = gBattleTerrainPalette_StadiumWallace,
        },
    },

    [BATTLE_TERRAIN_GROUDON] =
    {
        .background =
        {
            .tileset = gBattleTerrainTiles_Cave,
            .tilemap = gBattleTerrainTilemap_Cave,
            .entryTileset = gBattleTerrainAnimTiles_Cave,
            .entryTilemap = gBattleTerrainAnimTilemap_Cave,
            .palette = gBattleTerrainPalette_Groudon,
        },
    },

    [BATTLE_TERRAIN_KYOGRE] =
    {
        .background =
        {
            .tileset = gBattleTerrainTiles_Water,
            .tilemap = gBattleTerrainTilemap_Water,
            .entryTileset = gBattleTerrainAnimTiles_Underwater,
            .entryTilemap = gBattleTerrainAnimTilemap_Underwater,
            .palette = gBattleTerrainPalette_Kyogre,
        },
    },

    [BATTLE_TERRAIN_RAYQUAZA] =
    {
        .background =
        {
            .tileset = gBattleTerrainTiles_Rayquaza,
            .tilemap = gBattleTerrainTilemap_Rayquaza,
            .entryTileset = gBattleTerrainAnimTiles_Rayquaza,
            .entryTilemap = gBattleTerrainAnimTilemap_Rayquaza,
            .palette = gBattleTerrainPalette_Rayquaza,
        },
    },

    [BATTLE_TERRAIN_SOARING] =
    {
        .naturePower = MOVE_AIR_SLASH,
        .secretPowerEffect = MOVE_EFFECT_SPD_MINUS_1,
        .camouflageType = TYPE_FLYING,
    },

    [BATTLE_TERRAIN_SKY_PILLAR] =
    {
        .naturePower = MOVE_AIR_SLASH,
        .secretPowerEffect = MOVE_EFFECT_SPD_MINUS_1,
        .camouflageType = TYPE_FLYING,
    },

    [BATTLE_TERRAIN_BURIAL_GROUND] =
    {
        .naturePower = MOVE_SHADOW_BALL,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_GHOST,
    },

    [BATTLE_TERRAIN_PUDDLE] =
    {
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_5 ? MOVE_EFFECT_SPD_MINUS_1 : MOVE_EFFECT_ACC_MINUS_1,
        .camouflageType = TYPE_GROUND,
    },

    [BATTLE_TERRAIN_MARSH] =
    {
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerEffect = MOVE_EFFECT_SPD_MINUS_1,
        .camouflageType = TYPE_GROUND,
    },

    [BATTLE_TERRAIN_SWAMP] =
    {
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerEffect = MOVE_EFFECT_SPD_MINUS_1,
        .camouflageType = TYPE_GROUND,
    },

    [BATTLE_TERRAIN_SNOW] =
    {
    #if B_NATURE_POWER_MOVES >= GEN_7
        .naturePower = MOVE_ICE_BEAM,
    #elif B_NATURE_POWER_MOVES >= GEN_6
        .naturePower = MOVE_FROST_BREATH,
    #else
        .naturePower = MOVE_BLIZZARD,
    #endif
        .secretPowerEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
        .camouflageType = TYPE_ICE,
    },

    [BATTLE_TERRAIN_ICE] =
    {
        .naturePower = MOVE_ICE_BEAM,
        .secretPowerEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
        .camouflageType = TYPE_ICE,
    },

    [BATTLE_TERRAIN_VOLCANO] =
    {
        .naturePower = MOVE_LAVA_PLUME,
        .secretPowerEffect = MOVE_EFFECT_BURN,
        .camouflageType = TYPE_FIRE,
    },

    [BATTLE_TERRAIN_DISTORTION_WORLD] =
    {
        .naturePower = MOVE_TRI_ATTACK,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_NORMAL,
    },

    [BATTLE_TERRAIN_SPACE] =
    {
        .naturePower = MOVE_DRACO_METEOR,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_DRAGON,
    },

    [BATTLE_TERRAIN_ULTRA_SPACE] =
    {
        .naturePower = MOVE_PSYSHOCK,
        .secretPowerEffect = MOVE_EFFECT_DEF_MINUS_1,
        .camouflageType = TYPE_PSYCHIC,
    },
};

static const struct {
    u8 mapScene;
    u8 battleTerrain;
} sMapBattleSceneMapping[] = {
    {MAP_BATTLE_SCENE_GYM,      BATTLE_TERRAIN_GYM},
    {MAP_BATTLE_SCENE_MAGMA,    BATTLE_TERRAIN_MAGMA},
    {MAP_BATTLE_SCENE_AQUA,     BATTLE_TERRAIN_AQUA},
    {MAP_BATTLE_SCENE_SIDNEY,   BATTLE_TERRAIN_SIDNEY},
    {MAP_BATTLE_SCENE_PHOEBE,   BATTLE_TERRAIN_PHOEBE},
    {MAP_BATTLE_SCENE_GLACIA,   BATTLE_TERRAIN_GLACIA},
    {MAP_BATTLE_SCENE_DRAKE,    BATTLE_TERRAIN_DRAKE},
    {MAP_BATTLE_SCENE_FRONTIER, BATTLE_TERRAIN_FRONTIER}
};
