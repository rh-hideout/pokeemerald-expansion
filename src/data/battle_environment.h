const u32 gBattleEnvironmentTiles_TallGrass[] = INCBIN_U32("graphics/battle_environment/tall_grass/tiles.4bpp.smol");
const u16 gBattleEnvironmentPalette_TallGrass[] = INCBIN_U16("graphics/battle_environment/tall_grass/palette.gbapal");
const u32 gBattleEnvironmentTilemap_TallGrass[] = INCBIN_U32("graphics/battle_environment/tall_grass/map.bin.smolTM");

const u32 gBattleEnvironmentTiles_LongGrass[] = INCBIN_U32("graphics/battle_environment/long_grass/tiles.4bpp.smol");
const u16 gBattleEnvironmentPalette_LongGrass[] = INCBIN_U16("graphics/battle_environment/long_grass/palette.gbapal");
const u32 gBattleEnvironmentTilemap_LongGrass[] = INCBIN_U32("graphics/battle_environment/long_grass/map.bin.smolTM");

const u32 gBattleEnvironmentTiles_Sand[] = INCBIN_U32("graphics/battle_environment/sand/tiles.4bpp.smol");
const u16 gBattleEnvironmentPalette_Sand[] = INCBIN_U16("graphics/battle_environment/sand/palette.gbapal");
const u32 gBattleEnvironmentTilemap_Sand[] = INCBIN_U32("graphics/battle_environment/sand/map.bin.smolTM");

const u32 gBattleEnvironmentTiles_Underwater[] = INCBIN_U32("graphics/battle_environment/underwater/tiles.4bpp.smol");
const u16 gBattleEnvironmentPalette_Underwater[] = INCBIN_U16("graphics/battle_environment/underwater/palette.gbapal");
const u32 gBattleEnvironmentTilemap_Underwater[] = INCBIN_U32("graphics/battle_environment/underwater/map.bin.smolTM");

const u32 gBattleEnvironmentTiles_Water[] = INCBIN_U32("graphics/battle_environment/water/tiles.4bpp.smol");
const u16 gBattleEnvironmentPalette_Water[] = INCBIN_U16("graphics/battle_environment/water/palette.gbapal");
const u32 gBattleEnvironmentTilemap_Water[] = INCBIN_U32("graphics/battle_environment/water/map.bin.smolTM");

const u32 gBattleEnvironmentTiles_PondWater[] = INCBIN_U32("graphics/battle_environment/pond_water/tiles.4bpp.smol");
const u16 gBattleEnvironmentPalette_PondWater[] = INCBIN_U16("graphics/battle_environment/pond_water/palette.gbapal");
const u32 gBattleEnvironmentTilemap_PondWater[] = INCBIN_U32("graphics/battle_environment/pond_water/map.bin.smolTM");

const u32 gBattleEnvironmentTiles_Rock[] = INCBIN_U32("graphics/battle_environment/rock/tiles.4bpp.smol");
const u16 gBattleEnvironmentPalette_Rock[] = INCBIN_U16("graphics/battle_environment/rock/palette.gbapal");
const u32 gBattleEnvironmentTilemap_Rock[] = INCBIN_U32("graphics/battle_environment/rock/map.bin.smolTM");

const u32 gBattleEnvironmentTiles_Cave[] = INCBIN_U32("graphics/battle_environment/cave/tiles.4bpp.smol");
const u16 gBattleEnvironmentPalette_Cave[] = INCBIN_U16("graphics/battle_environment/cave/palette.gbapal");
const u32 gBattleEnvironmentTilemap_Cave[] = INCBIN_U32("graphics/battle_environment/cave/map.bin.smolTM");

const u16 gBattleEnvironmentPalette_Plain[] = INCBIN_U16("graphics/battle_environment/plain/palette.gbapal");

const u32 gBattleEnvironmentTiles_Building[] = INCBIN_U32("graphics/battle_environment/building/tiles.4bpp.smol");
const u16 gBattleEnvironmentPalette_Frontier[] = INCBIN_U16("graphics/battle_environment/stadium/battle_frontier.gbapal"); // this is also used for link battles
const u32 gBattleEnvironmentTilemap_Building[] = INCBIN_U32("graphics/battle_environment/building/map.bin.smolTM");

#define ENVIRONMENT_BACKGROUND(background)                      \
{                                                               \
    .tileset = gBattleEnvironmentTiles_##background,            \
    .tilemap = gBattleEnvironmentTilemap_##background,          \
    .entryTileset = gBattleEnvironmentAnimTiles_##background,   \
    .entryTilemap = gBattleEnvironmentAnimTilemap_##background, \
    .palette = gBattleEnvironmentPalette_##background,          \
}

const struct BattleEnvironment gBattleEnvironmentInfo[BATTLE_ENVIRONMENT_COUNT] =
{
    [BATTLE_ENVIRONMENT_GRASS] =
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
        .background = ENVIRONMENT_BACKGROUND(TallGrass),
    },

    [BATTLE_ENVIRONMENT_LONG_GRASS] =
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
        .background = ENVIRONMENT_BACKGROUND(LongGrass),
    },

    [BATTLE_ENVIRONMENT_SAND] =
    {
        .naturePower = B_NATURE_POWER_MOVES >= GEN_6 ? MOVE_EARTH_POWER : MOVE_EARTHQUAKE,
        .secretPowerEffect = MOVE_EFFECT_ACC_MINUS_1,
        .camouflageType = TYPE_GROUND,
        .background = ENVIRONMENT_BACKGROUND(Sand),
    },

    [BATTLE_ENVIRONMENT_UNDERWATER] =
    {
        .naturePower = MOVE_HYDRO_PUMP,
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_6 ? MOVE_EFFECT_ATK_MINUS_1 : MOVE_EFFECT_DEF_MINUS_1,
        .camouflageType = TYPE_WATER,
        .background = ENVIRONMENT_BACKGROUND(Underwater),
    },

    [BATTLE_ENVIRONMENT_WATER] =
    {
        .naturePower = B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_HYDRO_PUMP : MOVE_SURF,
        .secretPowerEffect = MOVE_EFFECT_ATK_MINUS_1,
        .camouflageType = TYPE_WATER,
        .background = ENVIRONMENT_BACKGROUND(Water),
    },

    [BATTLE_ENVIRONMENT_POND] =
    {
        .naturePower = B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_HYDRO_PUMP : MOVE_BUBBLE_BEAM,
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_4 ? MOVE_EFFECT_ATK_MINUS_1 : MOVE_EFFECT_SPD_MINUS_1,
        .camouflageType = TYPE_WATER,
        .background = ENVIRONMENT_BACKGROUND(PondWater),
    },

    [BATTLE_ENVIRONMENT_MOUNTAIN] =
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
        .background = ENVIRONMENT_BACKGROUND(Rock),
    },

    [BATTLE_ENVIRONMENT_CAVE] =
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
        .background = ENVIRONMENT_BACKGROUND(Cave),
    },

    [BATTLE_ENVIRONMENT_BUILDING] =
    {
        .naturePower = B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_TRI_ATTACK : MOVE_SWIFT,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_NORMAL,
        .background = ENVIRONMENT_BACKGROUND(Building),
    },

    [BATTLE_ENVIRONMENT_PLAIN] =
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

    [BATTLE_ENVIRONMENT_FRONTIER] =
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

    [BATTLE_ENVIRONMENT_GYM] =
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

    [BATTLE_ENVIRONMENT_LEADER] =
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

    [BATTLE_ENVIRONMENT_MAGMA] =
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

    [BATTLE_ENVIRONMENT_AQUA] =
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

    [BATTLE_ENVIRONMENT_SIDNEY] =
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

    [BATTLE_ENVIRONMENT_PHOEBE] =
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

    [BATTLE_ENVIRONMENT_GLACIA] =
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

    [BATTLE_ENVIRONMENT_DRAKE] =
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

    [BATTLE_ENVIRONMENT_CHAMPION] =
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

    [BATTLE_ENVIRONMENT_GROUDON] =
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

    [BATTLE_ENVIRONMENT_KYOGRE] =
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

    [BATTLE_ENVIRONMENT_RAYQUAZA] =
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

    [BATTLE_ENVIRONMENT_SOARING] =
    {
        .naturePower = MOVE_AIR_SLASH,
        .secretPowerEffect = MOVE_EFFECT_SPD_MINUS_1,
        .camouflageType = TYPE_FLYING,
    },

    [BATTLE_ENVIRONMENT_SKY_PILLAR] =
    {
        .naturePower = MOVE_AIR_SLASH,
        .secretPowerEffect = MOVE_EFFECT_SPD_MINUS_1,
        .camouflageType = TYPE_FLYING,
    },

    [BATTLE_ENVIRONMENT_BURIAL_GROUND] =
    {
        .naturePower = MOVE_SHADOW_BALL,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_GHOST,
    },

    [BATTLE_ENVIRONMENT_PUDDLE] =
    {
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_5 ? MOVE_EFFECT_SPD_MINUS_1 : MOVE_EFFECT_ACC_MINUS_1,
        .camouflageType = TYPE_GROUND,
    },

    [BATTLE_ENVIRONMENT_MARSH] =
    {
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerEffect = MOVE_EFFECT_SPD_MINUS_1,
        .camouflageType = TYPE_GROUND,
    },

    [BATTLE_ENVIRONMENT_SWAMP] =
    {
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerEffect = MOVE_EFFECT_SPD_MINUS_1,
        .camouflageType = TYPE_GROUND,
    },

    [BATTLE_ENVIRONMENT_SNOW] =
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

    [BATTLE_ENVIRONMENT_ICE] =
    {
        .naturePower = MOVE_ICE_BEAM,
        .secretPowerEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
        .camouflageType = TYPE_ICE,
    },

    [BATTLE_ENVIRONMENT_VOLCANO] =
    {
        .naturePower = MOVE_LAVA_PLUME,
        .secretPowerEffect = MOVE_EFFECT_BURN,
        .camouflageType = TYPE_FIRE,
    },

    [BATTLE_ENVIRONMENT_DISTORTION_WORLD] =
    {
        .naturePower = MOVE_TRI_ATTACK,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_NORMAL,
    },

    [BATTLE_ENVIRONMENT_SPACE] =
    {
        .naturePower = MOVE_DRACO_METEOR,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_DRAGON,
    },

    [BATTLE_ENVIRONMENT_ULTRA_SPACE] =
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
    {MAP_BATTLE_SCENE_GYM,      BATTLE_ENVIRONMENT_GYM},
    {MAP_BATTLE_SCENE_MAGMA,    BATTLE_ENVIRONMENT_MAGMA},
    {MAP_BATTLE_SCENE_AQUA,     BATTLE_ENVIRONMENT_AQUA},
    {MAP_BATTLE_SCENE_SIDNEY,   BATTLE_ENVIRONMENT_SIDNEY},
    {MAP_BATTLE_SCENE_PHOEBE,   BATTLE_ENVIRONMENT_PHOEBE},
    {MAP_BATTLE_SCENE_GLACIA,   BATTLE_ENVIRONMENT_GLACIA},
    {MAP_BATTLE_SCENE_DRAKE,    BATTLE_ENVIRONMENT_DRAKE},
    {MAP_BATTLE_SCENE_FRONTIER, BATTLE_ENVIRONMENT_FRONTIER}
};
