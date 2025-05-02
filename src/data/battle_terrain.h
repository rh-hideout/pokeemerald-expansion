const u32 gBattleEnvironmentTiles_TallGrass[] = INCBIN_U32("graphics/battle_environment/tall_grass/tiles.4bpp.lz");
const u32 gBattleEnvironmentPalette_TallGrass[] = INCBIN_U32("graphics/battle_environment/tall_grass/palette.gbapal.lz");
const u32 gBattleEnvironmentTilemap_TallGrass[] = INCBIN_U32("graphics/battle_environment/tall_grass/map.bin.lz");

const u32 gBattleEnvironmentTiles_LongGrass[] = INCBIN_U32("graphics/battle_environment/long_grass/tiles.4bpp.lz");
const u32 gBattleEnvironmentPalette_LongGrass[] = INCBIN_U32("graphics/battle_environment/long_grass/palette.gbapal.lz");
const u32 gBattleEnvironmentTilemap_LongGrass[] = INCBIN_U32("graphics/battle_environment/long_grass/map.bin.lz");

const u32 gBattleEnvironmentTiles_Sand[] = INCBIN_U32("graphics/battle_environment/sand/tiles.4bpp.lz");
const u32 gBattleEnvironmentPalette_Sand[] = INCBIN_U32("graphics/battle_environment/sand/palette.gbapal.lz");
const u32 gBattleEnvironmentTilemap_Sand[] = INCBIN_U32("graphics/battle_environment/sand/map.bin.lz");

const u32 gBattleEnvironmentTiles_Underwater[] = INCBIN_U32("graphics/battle_environment/underwater/tiles.4bpp.lz");
const u32 gBattleEnvironmentPalette_Underwater[] = INCBIN_U32("graphics/battle_environment/underwater/palette.gbapal.lz");
const u32 gBattleEnvironmentTilemap_Underwater[] = INCBIN_U32("graphics/battle_environment/underwater/map.bin.lz");

const u32 gBattleEnvironmentTiles_Water[] = INCBIN_U32("graphics/battle_environment/water/tiles.4bpp.lz");
const u32 gBattleEnvironmentPalette_Water[] = INCBIN_U32("graphics/battle_environment/water/palette.gbapal.lz");
const u32 gBattleEnvironmentTilemap_Water[] = INCBIN_U32("graphics/battle_environment/water/map.bin.lz");

const u32 gBattleEnvironmentTiles_PondWater[] = INCBIN_U32("graphics/battle_environment/pond_water/tiles.4bpp.lz");
const u32 gBattleEnvironmentPalette_PondWater[] = INCBIN_U32("graphics/battle_environment/pond_water/palette.gbapal.lz");
const u32 gBattleEnvironmentTilemap_PondWater[] = INCBIN_U32("graphics/battle_environment/pond_water/map.bin.lz");

const u32 gBattleEnvironmentTiles_Rock[] = INCBIN_U32("graphics/battle_environment/rock/tiles.4bpp.lz");
const u32 gBattleEnvironmentPalette_Rock[] = INCBIN_U32("graphics/battle_environment/rock/palette.gbapal.lz");
const u32 gBattleEnvironmentTilemap_Rock[] = INCBIN_U32("graphics/battle_environment/rock/map.bin.lz");

const u32 gBattleEnvironmentTiles_Cave[] = INCBIN_U32("graphics/battle_environment/cave/tiles.4bpp.lz");
const u32 gBattleEnvironmentPalette_Cave[] = INCBIN_U32("graphics/battle_environment/cave/palette.gbapal.lz");
const u32 gBattleEnvironmentTilemap_Cave[] = INCBIN_U32("graphics/battle_environment/cave/map.bin.lz");

const u32 gBattleEnvironmentPalette_Plain[] = INCBIN_U32("graphics/battle_environment/plain/palette.gbapal.lz");

const u32 gBattleEnvironmentTiles_Building[] = INCBIN_U32("graphics/battle_environment/building/tiles.4bpp.lz");
const u32 gBattleEnvironmentPalette_Frontier[] = INCBIN_U32("graphics/battle_environment/stadium/battle_frontier.gbapal.lz"); // this is also used for link battles
const u32 gBattleEnvironmentTilemap_Building[] = INCBIN_U32("graphics/battle_environment/building/map.bin.lz");

#define TERRAIN_BACKGROUND(background)                          \
{                                                               \
    .tileset = gBattleEnvironmentTiles_##background,            \
    .tilemap = gBattleEnvironmentTilemap_##background,          \
    .entryTileset = gBattleEnvironmentAnimTiles_##background,   \
    .entryTilemap = gBattleEnvironmentAnimTilemap_##background, \
    .palette = gBattleEnvironmentPalette_##background,          \
}

const struct BattleEnvironment gBattleEnvironmentInfo[BATTLE_TERRAIN_COUNT] =
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
            .tileset = gBattleEnvironmentTiles_Building,
            .tilemap = gBattleEnvironmentTilemap_Building,
            .entryTileset = gBattleEnvironmentAnimTiles_Building,
            .entryTilemap = gBattleEnvironmentAnimTilemap_Building,
            .palette = gBattleEnvironmentPalette_Plain,
        },
    },

    [BATTLE_TERRAIN_FRONTIER] =
    {
        .background =
        {
            .tileset = gBattleEnvironmentTiles_Building,
            .tilemap = gBattleEnvironmentTilemap_Building,
            .entryTileset = gBattleEnvironmentAnimTiles_Building,
            .entryTilemap = gBattleEnvironmentAnimTilemap_Building,
            .palette = gBattleEnvironmentPalette_Frontier,
        },
    },

    [BATTLE_TERRAIN_GYM] =
    {
        .background =
        {
            .tileset = gBattleEnvironmentTiles_Building,
            .tilemap = gBattleEnvironmentTilemap_Building,
            .entryTileset = gBattleEnvironmentAnimTiles_Building,
            .entryTilemap = gBattleEnvironmentAnimTilemap_Building,
            .palette = gBattleEnvironmentPalette_BuildingGym,
        },
    },

    [BATTLE_TERRAIN_LEADER] =
    {
        .background =
        {
            .tileset = gBattleEnvironmentTiles_Building,
            .tilemap = gBattleEnvironmentTilemap_Building,
            .entryTileset = gBattleEnvironmentAnimTiles_Building,
            .entryTilemap = gBattleEnvironmentAnimTilemap_Building,
            .palette = gBattleEnvironmentPalette_BuildingLeader,
        },
    },

    [BATTLE_TERRAIN_MAGMA] =
    {
        .background =
        {
            .tileset = gBattleEnvironmentTiles_Stadium,
            .tilemap = gBattleEnvironmentTilemap_Stadium,
            .entryTileset = gBattleEnvironmentAnimTiles_Building,
            .entryTilemap = gBattleEnvironmentAnimTilemap_Building,
            .palette = gBattleEnvironmentPalette_StadiumMagma,
        },
    },

    [BATTLE_TERRAIN_AQUA] =
    {
        .background =
        {
            .tileset = gBattleEnvironmentTiles_Stadium,
            .tilemap = gBattleEnvironmentTilemap_Stadium,
            .entryTileset = gBattleEnvironmentAnimTiles_Building,
            .entryTilemap = gBattleEnvironmentAnimTilemap_Building,
            .palette = gBattleEnvironmentPalette_StadiumAqua,
        },
    },

    [BATTLE_TERRAIN_SIDNEY] =
    {
        .background =
        {
            .tileset = gBattleEnvironmentTiles_Stadium,
            .tilemap = gBattleEnvironmentTilemap_Stadium,
            .entryTileset = gBattleEnvironmentAnimTiles_Building,
            .entryTilemap = gBattleEnvironmentAnimTilemap_Building,
            .palette = gBattleEnvironmentPalette_StadiumSidney,
        },
    },

    [BATTLE_TERRAIN_PHOEBE] =
    {
        .background =
        {
            .tileset = gBattleEnvironmentTiles_Stadium,
            .tilemap = gBattleEnvironmentTilemap_Stadium,
            .entryTileset = gBattleEnvironmentAnimTiles_Building,
            .entryTilemap = gBattleEnvironmentAnimTilemap_Building,
            .palette = gBattleEnvironmentPalette_StadiumPhoebe,
        },
    },

    [BATTLE_TERRAIN_GLACIA] =
    {
        .background =
        {
            .tileset = gBattleEnvironmentTiles_Stadium,
            .tilemap = gBattleEnvironmentTilemap_Stadium,
            .entryTileset = gBattleEnvironmentAnimTiles_Building,
            .entryTilemap = gBattleEnvironmentAnimTilemap_Building,
            .palette = gBattleEnvironmentPalette_StadiumGlacia,
        },
    },

    [BATTLE_TERRAIN_DRAKE] =
    {
        .background =
        {
            .tileset = gBattleEnvironmentTiles_Stadium,
            .tilemap = gBattleEnvironmentTilemap_Stadium,
            .entryTileset = gBattleEnvironmentAnimTiles_Building,
            .entryTilemap = gBattleEnvironmentAnimTilemap_Building,
            .palette = gBattleEnvironmentPalette_StadiumDrake,
        },
    },

    [BATTLE_TERRAIN_CHAMPION] =
    {
        .background =
        {
            .tileset = gBattleEnvironmentTiles_Stadium,
            .tilemap = gBattleEnvironmentTilemap_Stadium,
            .entryTileset = gBattleEnvironmentAnimTiles_Building,
            .entryTilemap = gBattleEnvironmentAnimTilemap_Building,
            .palette = gBattleEnvironmentPalette_StadiumWallace,
        },
    },

    [BATTLE_TERRAIN_GROUDON] =
    {
        .background =
        {
            .tileset = gBattleEnvironmentTiles_Cave,
            .tilemap = gBattleEnvironmentTilemap_Cave,
            .entryTileset = gBattleEnvironmentAnimTiles_Cave,
            .entryTilemap = gBattleEnvironmentAnimTilemap_Cave,
            .palette = gBattleEnvironmentPalette_Groudon,
        },
    },

    [BATTLE_TERRAIN_KYOGRE] =
    {
        .background =
        {
            .tileset = gBattleEnvironmentTiles_Water,
            .tilemap = gBattleEnvironmentTilemap_Water,
            .entryTileset = gBattleEnvironmentAnimTiles_Underwater,
            .entryTilemap = gBattleEnvironmentAnimTilemap_Underwater,
            .palette = gBattleEnvironmentPalette_Kyogre,
        },
    },

    [BATTLE_TERRAIN_RAYQUAZA] =
    {
        .background =
        {
            .tileset = gBattleEnvironmentTiles_Rayquaza,
            .tilemap = gBattleEnvironmentTilemap_Rayquaza,
            .entryTileset = gBattleEnvironmentAnimTiles_Rayquaza,
            .entryTilemap = gBattleEnvironmentAnimTilemap_Rayquaza,
            .palette = gBattleEnvironmentPalette_Rayquaza,
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
    u8 battleEnvironment;
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
