#include "fieldmap.h"

// Whether a palette has a night version, located at ((x + 9) % 16).pal
#define SWAP_PAL(x) ((x) < NUM_PALS_IN_PRIMARY ? 1 << (x) : 1 << ((x) - NUM_PALS_IN_PRIMARY))

const struct Tileset gTileset_SecretBase =
{
    .isCompressed = FALSE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_SecretBase,
    .palettes = gTilesetPalettes_SecretBase,
    .metatiles = gMetatiles_SecretBasePrimary,
    .metatileAttributes = gMetatileAttributes_SecretBasePrimary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseRedCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseRedCave,
    .palettes = gTilesetPalettes_SecretBaseRedCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset *const gTilesetPointer_SecretBase = &gTileset_SecretBase;
const struct Tileset *const gTilesetPointer_SecretBaseRedCave = &gTileset_SecretBaseRedCave;

const struct Tileset gTileset_General =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_General,
    .palettes = gTilesetPalettes_General,
    .metatiles = gMetatiles_General,
    .metatileAttributes = gMetatileAttributes_General,
    .callback = InitTilesetAnim_General,
};

const struct Tileset gTileset_Building =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_InsideBuilding,
    .palettes = gTilesetPalettes_InsideBuilding,
    .metatiles = gMetatiles_InsideBuilding,
    .metatileAttributes = gMetatileAttributes_InsideBuilding,
    .callback = InitTilesetAnim_Building,
};

const struct Tileset gTileset_TrainerHill =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TrainerHill,
    .palettes = gTilesetPalettes_TrainerHill,
    .metatiles = gMetatiles_TrainerHill,
    .metatileAttributes = gMetatileAttributes_TrainerHill,
    .callback = NULL,
};

const struct Tileset gTileset_BattleTent =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleTent,
    .palettes = gTilesetPalettes_BattleTent,
    .metatiles = gMetatiles_BattleTent,
    .metatileAttributes = gMetatileAttributes_BattleTent,
    .callback = NULL,
};

const struct Tileset gTileset_Rustboro =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Rustboro,
    .palettes = gTilesetPalettes_Rustboro,
    .metatiles = gMetatiles_Rustboro,
    .metatileAttributes = gMetatileAttributes_Rustboro,
    .callback = InitTilesetAnim_Rustboro,
};

const struct Tileset gTileset_Dewford =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Dewford,
    .palettes = gTilesetPalettes_Dewford,
    .metatiles = gMetatiles_Dewford,
    .metatileAttributes = gMetatileAttributes_Dewford,
    .callback = InitTilesetAnim_Dewford,
};

const struct Tileset gTileset_Fortree =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Fortree,
    .palettes = gTilesetPalettes_Fortree,
    .metatiles = gMetatiles_Fortree,
    .metatileAttributes = gMetatileAttributes_Fortree,
    .callback = InitTilesetAnim_Fortree,
};

const struct Tileset gTileset_IslandHarbor =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_IslandHarbor,
    .palettes = gTilesetPalettes_IslandHarbor,
    .metatiles = gMetatiles_IslandHarbor,
    .metatileAttributes = gMetatileAttributes_IslandHarbor,
    .callback = NULL,
};

const struct Tileset gTileset_BattleFrontierOutsideWest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontierOutsideWest,
    .palettes = gTilesetPalettes_BattleFrontierOutsideWest,
    .metatiles = gMetatiles_BattleFrontierOutsideWest,
    .metatileAttributes = gMetatileAttributes_BattleFrontierOutsideWest,
    .callback = InitTilesetAnim_BattleFrontierOutsideWest,
};

const struct Tileset gTileset_BattleFrontierOutsideEast =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontierOutsideEast,
    .palettes = gTilesetPalettes_BattleFrontierOutsideEast,
    .metatiles = gMetatiles_BattleFrontierOutsideEast,
    .metatileAttributes = gMetatileAttributes_BattleFrontierOutsideEast,
    .callback = InitTilesetAnim_BattleFrontierOutsideEast,
};

const struct Tileset gTileset_PokemonCenter =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonCenter,
    .palettes = gTilesetPalettes_PokemonCenter,
    .metatiles = gMetatiles_PokemonCenter,
    .metatileAttributes = gMetatileAttributes_PokemonCenter,
    .callback = NULL,
};

const struct Tileset gTileset_Shop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Shop,
    .palettes = gTilesetPalettes_Shop,
    .metatiles = gMetatiles_Shop,
    .metatileAttributes = gMetatileAttributes_Shop,
    .callback = NULL,
};

const struct Tileset gTileset_BattleFrontier =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontier,
    .palettes = gTilesetPalettes_BattleFrontier,
    .metatiles = gMetatiles_BattleFrontier,
    .metatileAttributes = gMetatileAttributes_BattleFrontier,
    .callback = NULL,
};

const struct Tileset gTileset_BattlePalace =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattlePalace,
    .palettes = gTilesetPalettes_BattlePalace,
    .metatiles = gMetatiles_BattlePalace,
    .metatileAttributes = gMetatileAttributes_BattlePalace,
    .callback = NULL,
};

const struct Tileset gTileset_BattleDome =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleDome,
    .palettes = gTilesetPalettes_BattleDome,
    .metatiles = gMetatiles_BattleDome,
    .metatileAttributes = gMetatileAttributes_BattleDome,
    .callback = InitTilesetAnim_BattleDome,
};

const struct Tileset gTileset_BattleFactory =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFactory,
    .palettes = gTilesetPalettes_BattleFactory,
    .metatiles = gMetatiles_BattleFactory,
    .metatileAttributes = gMetatileAttributes_BattleFactory,
    .callback = NULL,
};

const struct Tileset gTileset_BattlePike =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattlePike,
    .palettes = gTilesetPalettes_BattlePike,
    .metatiles = gMetatiles_BattlePike,
    .metatileAttributes = gMetatileAttributes_BattlePike,
    .callback = NULL,
};

const struct Tileset gTileset_BattleArena =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleArena,
    .palettes = gTilesetPalettes_BattleArena,
    .metatiles = gMetatiles_BattleArena,
    .metatileAttributes = gMetatileAttributes_BattleArena,
    .callback = NULL,
};

const struct Tileset gTileset_BattlePyramid =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattlePyramid,
    .palettes = gTilesetPalettes_BattlePyramid,
    .metatiles = gMetatiles_BattlePyramid,
    .metatileAttributes = gMetatileAttributes_BattlePyramid,
    .callback = InitTilesetAnim_BattlePyramid,
};

const struct Tileset gTileset_BattleFrontierRankingHall =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontierRankingHall,
    .palettes = gTilesetPalettes_BattleFrontierRankingHall,
    .metatiles = gMetatiles_BattleFrontierRankingHall,
    .metatileAttributes = gMetatileAttributes_BattleFrontierRankingHall,
    .callback = NULL,
};

#if !IS_FRLG && !IS_HNS

const struct Tileset gTileset_Petalburg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Petalburg,
    .palettes = gTilesetPalettes_Petalburg,
    .metatiles = gMetatiles_Petalburg,
    .metatileAttributes = gMetatileAttributes_Petalburg,
    .callback = InitTilesetAnim_Petalburg,
};

const struct Tileset gTileset_Slateport =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Slateport,
    .palettes = gTilesetPalettes_Slateport,
    .metatiles = gMetatiles_Slateport,
    .metatileAttributes = gMetatileAttributes_Slateport,
    .callback = InitTilesetAnim_Slateport,
};

const struct Tileset gTileset_Mauville =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Mauville,
    .palettes = gTilesetPalettes_Mauville,
    .metatiles = gMetatiles_Mauville,
    .metatileAttributes = gMetatileAttributes_Mauville,
    .callback = InitTilesetAnim_Mauville,
};

const struct Tileset gTileset_Lavaridge =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lavaridge,
    .palettes = gTilesetPalettes_Lavaridge,
    .metatiles = gMetatiles_Lavaridge,
    .metatileAttributes = gMetatileAttributes_Lavaridge,
    .callback = InitTilesetAnim_Lavaridge,
};

const struct Tileset gTileset_Fallarbor =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Fallarbor,
    .palettes = gTilesetPalettes_Fallarbor,
    .metatiles = gMetatiles_Fallarbor,
    .metatileAttributes = gMetatileAttributes_Fallarbor,
    .callback = InitTilesetAnim_Fallarbor,
};

const struct Tileset gTileset_Lilycove =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lilycove,
    .palettes = gTilesetPalettes_Lilycove,
    .metatiles = gMetatiles_Lilycove,
    .metatileAttributes = gMetatileAttributes_Lilycove,
    .callback = InitTilesetAnim_Lilycove,
};

const struct Tileset gTileset_Mossdeep =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Mossdeep,
    .palettes = gTilesetPalettes_Mossdeep,
    .metatiles = gMetatiles_Mossdeep,
    .metatileAttributes = gMetatileAttributes_Mossdeep,
    .callback = InitTilesetAnim_Mossdeep,
};

const struct Tileset gTileset_EverGrande =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EverGrande,
    .palettes = gTilesetPalettes_EverGrande,
    .metatiles = gMetatiles_EverGrande,
    .metatileAttributes = gMetatileAttributes_EverGrande,
    .callback = InitTilesetAnim_EverGrande,
};

const struct Tileset gTileset_Pacifidlog =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Pacifidlog,
    .palettes = gTilesetPalettes_Pacifidlog,
    .metatiles = gMetatiles_Pacifidlog,
    .metatileAttributes = gMetatileAttributes_Pacifidlog,
    .callback = InitTilesetAnim_Pacifidlog,
};

const struct Tileset gTileset_Sootopolis =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Sootopolis,
    .palettes = gTilesetPalettes_Sootopolis,
    .metatiles = gMetatiles_Sootopolis,
    .metatileAttributes = gMetatileAttributes_Sootopolis,
    .callback = InitTilesetAnim_Sootopolis,
};

const struct Tileset gTileset_Cave =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave,
    .palettes = gTilesetPalettes_Cave,
    .metatiles = gMetatiles_Cave,
    .metatileAttributes = gMetatileAttributes_Cave,
    .callback = InitTilesetAnim_Cave,
};

const struct Tileset gTileset_PokemonSchool =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonSchool,
    .palettes = gTilesetPalettes_PokemonSchool,
    .metatiles = gMetatiles_PokemonSchool,
    .metatileAttributes = gMetatileAttributes_PokemonSchool,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonFanClub =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonFanClub,
    .palettes = gTilesetPalettes_PokemonFanClub,
    .metatiles = gMetatiles_PokemonFanClub,
    .metatileAttributes = gMetatileAttributes_PokemonFanClub,
    .callback = NULL,
};

const struct Tileset gTileset_Unused1 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Unused1,
    .palettes = gTilesetPalettes_Unused1,
    .metatiles = gMetatiles_Unused1,
    .metatileAttributes = gMetatileAttributes_Unused1,
    .callback = NULL,
};

const struct Tileset gTileset_MeteorFalls =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MeteorFalls,
    .palettes = gTilesetPalettes_MeteorFalls,
    .metatiles = gMetatiles_MeteorFalls,
    .metatileAttributes = gMetatileAttributes_MeteorFalls,
    .callback = NULL,
};

const struct Tileset gTileset_OceanicMuseum =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_OceanicMuseum,
    .palettes = gTilesetPalettes_OceanicMuseum,
    .metatiles = gMetatiles_OceanicMuseum,
    .metatileAttributes = gMetatileAttributes_OceanicMuseum,
    .callback = NULL,
};

const struct Tileset gTileset_CableClub =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CableClub,
    .palettes = gTilesetPalettes_CableClub,
    .metatiles = gMetatiles_CableClub,
    .metatileAttributes = gMetatileAttributes_CableClub,
    .callback = NULL,
};

const struct Tileset gTileset_SeashoreHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeashoreHouse,
    .palettes = gTilesetPalettes_SeashoreHouse,
    .metatiles = gMetatiles_SeashoreHouse,
    .metatileAttributes = gMetatileAttributes_SeashoreHouse,
    .callback = NULL,
};

const struct Tileset gTileset_PrettyPetalFlowerShop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PrettyPetalFlowerShop,
    .palettes = gTilesetPalettes_PrettyPetalFlowerShop,
    .metatiles = gMetatiles_PrettyPetalFlowerShop,
    .metatileAttributes = gMetatileAttributes_PrettyPetalFlowerShop,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonDayCare =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonDayCare,
    .palettes = gTilesetPalettes_PokemonDayCare,
    .metatiles = gMetatiles_PokemonDayCare,
    .metatileAttributes = gMetatileAttributes_PokemonDayCare,
    .callback = NULL,
};

const struct Tileset gTileset_Facility =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Facility,
    .palettes = gTilesetPalettes_Facility,
    .metatiles = gMetatiles_Facility,
    .metatileAttributes = gMetatileAttributes_Facility,
    .callback = NULL,
};

const struct Tileset gTileset_BikeShop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BikeShop,
    .palettes = gTilesetPalettes_BikeShop,
    .metatiles = gMetatiles_BikeShop,
    .metatileAttributes = gMetatileAttributes_BikeShop,
    .callback = InitTilesetAnim_BikeShop,
};

const struct Tileset gTileset_RusturfTunnel =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RusturfTunnel,
    .palettes = gTilesetPalettes_RusturfTunnel,
    .metatiles = gMetatiles_RusturfTunnel,
    .metatileAttributes = gMetatileAttributes_RusturfTunnel,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseBrownCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseBrownCave,
    .palettes = gTilesetPalettes_SecretBaseBrownCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseTree =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseTree,
    .palettes = gTilesetPalettes_SecretBaseTree,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseShrub =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseShrub,
    .palettes = gTilesetPalettes_SecretBaseShrub,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseBlueCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseBlueCave,
    .palettes = gTilesetPalettes_SecretBaseBlueCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseYellowCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseYellowCave,
    .palettes = gTilesetPalettes_SecretBaseYellowCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_InsideOfTruck =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_InsideOfTruck,
    .palettes = gTilesetPalettes_InsideOfTruck,
    .metatiles = gMetatiles_InsideOfTruck,
    .metatileAttributes = gMetatileAttributes_InsideOfTruck,
    .callback = NULL,
};

const struct Tileset gTileset_Unused2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Unused2,
    .palettes = gTilesetPalettes_Unused2,
    .metatiles = gMetatiles_Unused2,
    .metatileAttributes = gMetatileAttributes_Unused2,
    .callback = NULL,
};

const struct Tileset gTileset_Contest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Contest,
    .palettes = gTilesetPalettes_Contest,
    .metatiles = gMetatiles_Contest,
    .metatileAttributes = gMetatileAttributes_Contest,
    .callback = NULL,
};

const struct Tileset gTileset_LilycoveMuseum =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LilycoveMuseum,
    .palettes = gTilesetPalettes_LilycoveMuseum,
    .metatiles = gMetatiles_LilycoveMuseum,
    .metatileAttributes = gMetatileAttributes_LilycoveMuseum,
    .callback = NULL,
};

const struct Tileset gTileset_BrendansMaysHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BrendansMaysHouse,
    .palettes = gTilesetPalettes_BrendansMaysHouse,
    .metatiles = gMetatiles_BrendansMaysHouse,
    .metatileAttributes = gMetatileAttributes_BrendansMaysHouse,
    .callback = NULL,
};

const struct Tileset gTileset_Lab =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lab,
    .palettes = gTilesetPalettes_Lab,
    .metatiles = gMetatiles_Lab,
    .metatileAttributes = gMetatileAttributes_Lab,
    .callback = NULL,
};

const struct Tileset gTileset_Underwater =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Underwater,
    .palettes = gTilesetPalettes_Underwater,
    .metatiles = gMetatiles_Underwater,
    .metatileAttributes = gMetatileAttributes_Underwater,
    .callback = InitTilesetAnim_Underwater,
};

const struct Tileset gTileset_PetalburgGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PetalburgGym,
    .palettes = gTilesetPalettes_PetalburgGym,
    .metatiles = gMetatiles_PetalburgGym,
    .metatileAttributes = gMetatileAttributes_PetalburgGym,
    .callback = NULL,
};

const struct Tileset gTileset_SootopolisGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SootopolisGym,
    .palettes = gTilesetPalettes_SootopolisGym,
    .metatiles = gMetatiles_SootopolisGym,
    .metatileAttributes = gMetatileAttributes_SootopolisGym,
    .callback = InitTilesetAnim_SootopolisGym,
};

const struct Tileset gTileset_GenericBuilding =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GenericBuilding,
    .palettes = gTilesetPalettes_GenericBuilding,
    .metatiles = gMetatiles_GenericBuilding,
    .metatileAttributes = gMetatileAttributes_GenericBuilding,
    .callback = NULL,
};

const struct Tileset gTileset_MauvilleGameCorner =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MauvilleGameCorner,
    .palettes = gTilesetPalettes_MauvilleGameCorner,
    .metatiles = gMetatiles_MauvilleGameCorner,
    .metatileAttributes = gMetatileAttributes_MauvilleGameCorner,
    .callback = NULL,
};

const struct Tileset gTileset_RustboroGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RustboroGym,
    .palettes = gTilesetPalettes_RustboroGym,
    .metatiles = gMetatiles_RustboroGym,
    .metatileAttributes = gMetatileAttributes_RustboroGym,
    .callback = NULL,
};

const struct Tileset gTileset_DewfordGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DewfordGym,
    .palettes = gTilesetPalettes_DewfordGym,
    .metatiles = gMetatiles_DewfordGym,
    .metatileAttributes = gMetatileAttributes_DewfordGym,
    .callback = NULL,
};

const struct Tileset gTileset_MauvilleGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MauvilleGym,
    .palettes = gTilesetPalettes_MauvilleGym,
    .metatiles = gMetatiles_MauvilleGym,
    .metatileAttributes = gMetatileAttributes_MauvilleGym,
    .callback = InitTilesetAnim_MauvilleGym,
};

const struct Tileset gTileset_LavaridgeGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LavaridgeGym,
    .palettes = gTilesetPalettes_LavaridgeGym,
    .metatiles = gMetatiles_LavaridgeGym,
    .metatileAttributes = gMetatileAttributes_LavaridgeGym,
    .callback = NULL,
};

const struct Tileset gTileset_TrickHousePuzzle =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TrickHousePuzzle,
    .palettes = gTilesetPalettes_TrickHousePuzzle,
    .metatiles = gMetatiles_TrickHousePuzzle,
    .metatileAttributes = gMetatileAttributes_TrickHousePuzzle,
    .callback = NULL,
};

const struct Tileset gTileset_FortreeGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FortreeGym,
    .palettes = gTilesetPalettes_FortreeGym,
    .metatiles = gMetatiles_FortreeGym,
    .metatileAttributes = gMetatileAttributes_FortreeGym,
    .callback = NULL,
};

const struct Tileset gTileset_MossdeepGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MossdeepGym,
    .palettes = gTilesetPalettes_MossdeepGym,
    .metatiles = gMetatiles_MossdeepGym,
    .metatileAttributes = gMetatileAttributes_MossdeepGym,
    .callback = NULL,
};

const struct Tileset gTileset_InsideShip =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_InsideShip,
    .palettes = gTilesetPalettes_InsideShip,
    .metatiles = gMetatiles_InsideShip,
    .metatileAttributes = gMetatileAttributes_InsideShip,
    .callback = NULL,
};

const struct Tileset gTileset_EliteFour =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EliteFour,
    .palettes = gTilesetPalettes_EliteFour,
    .metatiles = gMetatiles_EliteFour,
    .metatileAttributes = gMetatileAttributes_EliteFour,
    .callback = InitTilesetAnim_EliteFour,
};

const struct Tileset gTileset_MirageTower =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MirageTower,
    .palettes = gTilesetPalettes_MirageTower,
    .metatiles = gMetatiles_MirageTower,
    .metatileAttributes = gMetatileAttributes_MirageTower,
    .callback = NULL,
};

const struct Tileset gTileset_MossdeepGameCorner =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MossdeepGameCorner,
    .palettes = gTilesetPalettes_MossdeepGameCorner,
    .metatiles = gMetatiles_MossdeepGameCorner,
    .metatileAttributes = gMetatileAttributes_MossdeepGameCorner,
    .callback = NULL,
};

const struct Tileset gTileset_NavelRock =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_NavelRock,
    .palettes = gTilesetPalettes_NavelRock,
    .metatiles = gMetatiles_NavelRock,
    .metatileAttributes = gMetatileAttributes_NavelRock,
    .callback = NULL,
};

const struct Tileset gTileset_MysteryEventsHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MysteryEventsHouse,
    .palettes = gTilesetPalettes_MysteryEventsHouse,
    .metatiles = gMetatiles_MysteryEventsHouse,
    .metatileAttributes = gMetatileAttributes_MysteryEventsHouse,
    .callback = NULL,
};

const struct Tileset gTileset_UnionRoom =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_UnionRoom,
    .palettes = gTilesetPalettes_UnionRoom,
    .metatiles = gMetatiles_UnionRoom,
    .metatileAttributes = gMetatileAttributes_UnionRoom,
    .callback = NULL,
};

#elif IS_FRLG

// FRLG tilesets
const struct Tileset gTileset_BuildingFrlg =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Building_Frlg,
    .palettes = gTilesetPalettes_Building_Frlg,
    .metatiles = gMetatiles_Building_Frlg,
    .metatileAttributes = gMetatileAttributes_Building_Frlg,
    .callback = NULL,
};

const struct Tileset gTileset_General_Frlg =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_General_Frlg,
    .palettes = gTilesetPalettes_General_Frlg,
    .metatiles = gMetatiles_General_Frlg,
    .metatileAttributes = gMetatileAttributes_General_Frlg,
    .callback = InitTilesetAnim_General_Frlg,
};

const struct Tileset gTileset_PalletTown =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PalletTown,
    .palettes = gTilesetPalettes_PalletTown,
    .metatiles = gMetatiles_PalletTown,
    .metatileAttributes = gMetatileAttributes_PalletTown,
    .callback = NULL,
};

const struct Tileset gTileset_ViridianCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianCity,
    .palettes = gTilesetPalettes_ViridianCity,
    .metatiles = gMetatiles_ViridianCity,
    .metatileAttributes = gMetatileAttributes_ViridianCity,
    .callback = NULL,
};

const struct Tileset gTileset_PewterCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PewterCity,
    .palettes = gTilesetPalettes_PewterCity,
    .metatiles = gMetatiles_PewterCity,
    .metatileAttributes = gMetatileAttributes_PewterCity,
    .callback = NULL,
};

const struct Tileset gTileset_CeruleanCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanCity,
    .palettes = gTilesetPalettes_CeruleanCity,
    .metatiles = gMetatiles_CeruleanCity,
    .metatileAttributes = gMetatileAttributes_CeruleanCity,
    .callback = NULL,
};

const struct Tileset gTileset_LavenderTown =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LavenderTown,
    .palettes = gTilesetPalettes_LavenderTown,
    .metatiles = gMetatiles_LavenderTown,
    .metatileAttributes = gMetatileAttributes_LavenderTown,
    .callback = NULL,
};

const struct Tileset gTileset_VermilionCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_VermilionCity,
    .palettes = gTilesetPalettes_VermilionCity,
    .metatiles = gMetatiles_VermilionCity,
    .metatileAttributes = gMetatileAttributes_VermilionCity,
    .callback = NULL,
};

const struct Tileset gTileset_CeladonCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeladonCity,
    .palettes = gTilesetPalettes_CeladonCity,
    .metatiles = gMetatiles_CeladonCity,
    .metatileAttributes = gMetatileAttributes_CeladonCity,
    .callback = InitTilesetAnim_CeladonCity,
};

const struct Tileset gTileset_FuchsiaCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FuchsiaCity,
    .palettes = gTilesetPalettes_FuchsiaCity,
    .metatiles = gMetatiles_FuchsiaCity,
    .metatileAttributes = gMetatileAttributes_FuchsiaCity,
    .callback = NULL,
};

const struct Tileset gTileset_CinnabarIsland =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CinnabarIsland,
    .palettes = gTilesetPalettes_CinnabarIsland,
    .metatiles = gMetatiles_CinnabarIsland,
    .metatileAttributes = gMetatileAttributes_CinnabarIsland,
    .callback = NULL,
};

const struct Tileset gTileset_IndigoPlateau =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_IndigoPlateau,
    .palettes = gTilesetPalettes_IndigoPlateau,
    .metatiles = gMetatiles_IndigoPlateau,
    .metatileAttributes = gMetatileAttributes_IndigoPlateau,
    .callback = NULL,
};

const struct Tileset gTileset_SaffronCity =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SaffronCity,
    .palettes = gTilesetPalettes_SaffronCity,
    .metatiles = gMetatiles_SaffronCity,
    .metatileAttributes = gMetatileAttributes_SaffronCity,
    .callback = NULL,
};

const struct Tileset gTileset_Mart =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Mart,
    .palettes = gTilesetPalettes_Mart,
    .metatiles = gMetatiles_Mart,
    .metatileAttributes = gMetatileAttributes_Mart,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonCenterFrlg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonCenter_Frlg,
    .palettes = gTilesetPalettes_PokemonCenter_Frlg,
    .metatiles = gMetatiles_PokemonCenter_Frlg,
    .metatileAttributes = gMetatileAttributes_PokemonCenter_Frlg,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_Frlg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_Frlg,
    .palettes = gTilesetPalettes_Cave_Frlg,
    .metatiles = gMetatiles_Cave_Frlg,
    .metatileAttributes = gMetatileAttributes_Cave_Frlg,
    .callback = NULL,
};

const struct Tileset gTileset_Museum =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Museum,
    .palettes = gTilesetPalettes_Museum,
    .metatiles = gMetatiles_Museum,
    .metatileAttributes = gMetatileAttributes_Museum,
    .callback = NULL,
};

const struct Tileset gTileset_CableClub_Frlg =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CableClub_Frlg,
    .palettes = gTilesetPalettes_CableClub_Frlg,
    .metatiles = gMetatiles_CableClub_Frlg,
    .metatileAttributes = gMetatileAttributes_CableClub_Frlg,
    .callback = NULL,
};

const struct Tileset gTileset_BikeShop_Frlg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BikeShop_Frlg,
    .palettes = gTilesetPalettes_BikeShop_Frlg,
    .metatiles = gMetatiles_BikeShop_Frlg,
    .metatileAttributes = gMetatileAttributes_BikeShop_Frlg,
    .callback = NULL,
};

const struct Tileset gTileset_GenericBuilding1 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GenericBuilding1,
    .palettes = gTilesetPalettes_GenericBuilding1,
    .metatiles = gMetatiles_GenericBuilding1,
    .metatileAttributes = gMetatileAttributes_GenericBuilding1,
    .callback = NULL,
};

const struct Tileset gTileset_Lab_Frlg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lab_Frlg,
    .palettes = gTilesetPalettes_Lab_Frlg,
    .metatiles = gMetatiles_Lab_Frlg,
    .metatileAttributes = gMetatileAttributes_Lab_Frlg,
    .callback = NULL,
};

const struct Tileset gTileset_FuchsiaGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FuchsiaGym,
    .palettes = gTilesetPalettes_FuchsiaGym,
    .metatiles = gMetatiles_FuchsiaGym,
    .metatileAttributes = gMetatileAttributes_FuchsiaGym,
    .callback = NULL,
};

const struct Tileset gTileset_ViridianGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianGym,
    .palettes = gTilesetPalettes_ViridianGym,
    .metatiles = gMetatiles_ViridianGym,
    .metatileAttributes = gMetatileAttributes_ViridianGym,
    .callback = NULL,
};

const struct Tileset gTileset_HoennBuilding =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_HoennBuilding,
    .palettes = gTilesetPalettes_HoennBuilding,
    .metatiles = gMetatiles_HoennBuilding,
    .metatileAttributes = gMetatileAttributes_HoennBuilding,
    .callback = NULL,
};

const struct Tileset gTileset_GameCorner =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GameCorner,
    .palettes = gTilesetPalettes_GameCorner,
    .metatiles = gMetatiles_GameCorner,
    .metatileAttributes = gMetatileAttributes_GameCorner,
    .callback = NULL,
};

const struct Tileset gTileset_PewterGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PewterGym,
    .palettes = gTilesetPalettes_PewterGym,
    .metatiles = gMetatiles_PewterGym,
    .metatileAttributes = gMetatileAttributes_PewterGym,
    .callback = NULL,
};

const struct Tileset gTileset_CeruleanGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanGym,
    .palettes = gTilesetPalettes_CeruleanGym,
    .metatiles = gMetatiles_CeruleanGym,
    .metatileAttributes = gMetatileAttributes_CeruleanGym,
    .callback = NULL,
};

const struct Tileset gTileset_VermilionGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_VermilionGym,
    .palettes = gTilesetPalettes_VermilionGym,
    .metatiles = gMetatiles_VermilionGym,
    .metatileAttributes = gMetatileAttributes_VermilionGym,
    .callback = InitTilesetAnim_VermilionGym,
};

const struct Tileset gTileset_CeladonGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeladonGym,
    .palettes = gTilesetPalettes_CeladonGym,
    .metatiles = gMetatiles_CeladonGym,
    .metatileAttributes = gMetatileAttributes_CeladonGym,
    .callback = InitTilesetAnim_CeladonGym,
};

const struct Tileset gTileset_SaffronGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SaffronGym,
    .palettes = gTilesetPalettes_SaffronGym,
    .metatiles = gMetatiles_SaffronGym,
    .metatileAttributes = gMetatileAttributes_SaffronGym,
    .callback = NULL,
};

const struct Tileset gTileset_CinnabarGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CinnabarGym,
    .palettes = gTilesetPalettes_CinnabarGym,
    .metatiles = gMetatiles_CinnabarGym,
    .metatileAttributes = gMetatileAttributes_CinnabarGym,
    .callback = NULL,
};

const struct Tileset gTileset_SSAnne =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SSAnne,
    .palettes = gTilesetPalettes_SSAnne,
    .metatiles = gMetatiles_SSAnne,
    .metatileAttributes = gMetatileAttributes_SSAnne,
    .callback = NULL,
};

const struct Tileset gTileset_ViridianForest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianForest,
    .palettes = gTilesetPalettes_ViridianForest,
    .metatiles = gMetatiles_ViridianForest,
    .metatileAttributes = gMetatileAttributes_ViridianForest,
    .callback = NULL,
};

const struct Tileset gTileset_UnusedGatehouse1 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_UnusedGatehouse1,
    .palettes = gTilesetPalettes_UnusedGatehouse1,
    .metatiles = gMetatiles_UnusedGatehouse1,
    .metatileAttributes = gMetatileAttributes_UnusedGatehouse1,
    .callback = NULL,
};

const struct Tileset gTileset_RockTunnel =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RockTunnel,
    .palettes = gTilesetPalettes_RockTunnel,
    .metatiles = gMetatiles_RockTunnel,
    .metatileAttributes = gMetatileAttributes_RockTunnel,
    .callback = NULL,
};

const struct Tileset gTileset_DiglettsCave =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DiglettsCave,
    .palettes = gTilesetPalettes_DiglettsCave,
    .metatiles = gMetatiles_DiglettsCave,
    .metatileAttributes = gMetatileAttributes_DiglettsCave,
    .callback = NULL,
};

const struct Tileset gTileset_SeafoamIslands =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeafoamIslands,
    .palettes = gTilesetPalettes_SeafoamIslands,
    .metatiles = gMetatiles_SeafoamIslands,
    .metatileAttributes = gMetatileAttributes_SeafoamIslands,
    .callback = NULL,
};

const struct Tileset gTileset_UnusedGatehouse2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_UnusedGatehouse2,
    .palettes = gTilesetPalettes_UnusedGatehouse2,
    .metatiles = gMetatiles_UnusedGatehouse2,
    .metatileAttributes = gMetatileAttributes_UnusedGatehouse2,
    .callback = NULL,
};

const struct Tileset gTileset_CeruleanCave =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanCave,
    .palettes = gTilesetPalettes_CeruleanCave,
    .metatiles = gMetatiles_CeruleanCave,
    .metatileAttributes = gMetatileAttributes_CeruleanCave,
    .callback = NULL,
};

const struct Tileset gTileset_DepartmentStore =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DepartmentStore,
    .palettes = gTilesetPalettes_DepartmentStore,
    .metatiles = gMetatiles_DepartmentStore,
    .metatileAttributes = gMetatileAttributes_DepartmentStore,
    .callback = NULL,
};

const struct Tileset gTileset_GenericBuilding2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GenericBuilding2,
    .palettes = gTilesetPalettes_GenericBuilding2,
    .metatiles = gMetatiles_GenericBuilding2,
    .metatileAttributes = gMetatileAttributes_GenericBuilding2,
    .callback = NULL,
};

const struct Tileset gTileset_PowerPlant =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PowerPlant,
    .palettes = gTilesetPalettes_PowerPlant,
    .metatiles = gMetatiles_PowerPlant,
    .metatileAttributes = gMetatileAttributes_PowerPlant,
    .callback = NULL,
};

const struct Tileset gTileset_SeaCottage =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeaCottage,
    .palettes = gTilesetPalettes_SeaCottage,
    .metatiles = gMetatiles_SeaCottage,
    .metatileAttributes = gMetatileAttributes_SeaCottage,
    .callback = NULL,
};

const struct Tileset gTileset_SilphCo =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Condominiums,
    .palettes = gTilesetPalettes_Condominiums,
    .metatiles = gMetatiles_SilphCo,
    .metatileAttributes = gMetatileAttributes_SilphCo,
    .callback = InitTilesetAnim_SilphCo,
};

const struct Tileset gTileset_UndergroundPath =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_UndergroundPath,
    .palettes = gTilesetPalettes_UndergroundPath,
    .metatiles = gMetatiles_UndergroundPath,
    .metatileAttributes = gMetatileAttributes_UndergroundPath,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonTower =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonTower,
    .palettes = gTilesetPalettes_PokemonTower,
    .metatiles = gMetatiles_PokemonTower,
    .metatileAttributes = gMetatileAttributes_PokemonTower,
    .callback = NULL,
};

const struct Tileset gTileset_SafariZoneBuilding =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SafariZoneBuilding,
    .palettes = gTilesetPalettes_SafariZoneBuilding,
    .metatiles = gMetatiles_SafariZoneBuilding,
    .metatileAttributes = gMetatileAttributes_SafariZoneBuilding,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonMansion =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonMansion,
    .palettes = gTilesetPalettes_PokemonMansion,
    .metatiles = gMetatiles_PokemonMansion,
    .metatileAttributes = gMetatileAttributes_PokemonMansion,
    .callback = NULL,
};

const struct Tileset gTileset_RestaurantHotel =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RestaurantHotel,
    .palettes = gTilesetPalettes_RestaurantHotel,
    .metatiles = gMetatiles_RestaurantHotel,
    .metatileAttributes = gMetatileAttributes_RestaurantHotel,
    .callback = NULL,
};

const struct Tileset gTileset_School =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_School,
    .palettes = gTilesetPalettes_School,
    .metatiles = gMetatiles_School,
    .metatileAttributes = gMetatileAttributes_School,
    .callback = NULL,
};

const struct Tileset gTileset_FanClubDaycare =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FanClubDaycare,
    .palettes = gTilesetPalettes_FanClubDaycare,
    .metatiles = gMetatiles_FanClubDaycare,
    .metatileAttributes = gMetatileAttributes_FanClubDaycare,
    .callback = NULL,
};

const struct Tileset gTileset_Condominiums =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Condominiums,
    .palettes = gTilesetPalettes_Condominiums,
    .metatiles = gMetatiles_Condominiums,
    .metatileAttributes = gMetatileAttributes_Condominiums,
    .callback = NULL,
};

const struct Tileset gTileset_BurgledHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BurgledHouse,
    .palettes = gTilesetPalettes_BurgledHouse,
    .metatiles = gMetatiles_BurgledHouse,
    .metatileAttributes = gMetatileAttributes_BurgledHouse,
    .callback = NULL,
};

const struct Tileset gTileset_MtEmber =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MtEmber,
    .palettes = gTilesetPalettes_MtEmber,
    .metatiles = gMetatiles_MtEmber,
    .metatileAttributes = gMetatileAttributes_MtEmber,
    .callback = InitTilesetAnim_MtEmber,
};

const struct Tileset gTileset_BerryForest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BerryForest,
    .palettes = gTilesetPalettes_BerryForest,
    .metatiles = gMetatiles_BerryForest,
    .metatileAttributes = gMetatileAttributes_BerryForest,
    .callback = NULL,
};

const struct Tileset gTileset_NavelRock_Frlg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_NavelRock_Frlg,
    .palettes = gTilesetPalettes_NavelRock_Frlg,
    .metatiles = gMetatiles_NavelRock_Frlg,
    .metatileAttributes = gMetatileAttributes_NavelRock_Frlg,
    .callback = NULL,
};

const struct Tileset gTileset_TanobyRuins =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TanobyRuins,
    .palettes = gTilesetPalettes_TanobyRuins,
    .metatiles = gMetatiles_TanobyRuins,
    .metatileAttributes = gMetatileAttributes_TanobyRuins,
    .callback = NULL,
};

const struct Tileset gTileset_SeviiIslands123 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeviiIslands123,
    .palettes = gTilesetPalettes_SeviiIslands123,
    .metatiles = gMetatiles_SeviiIslands123,
    .metatileAttributes = gMetatileAttributes_SeviiIslands123,
    .callback = NULL,
};

const struct Tileset gTileset_SeviiIslands45 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeviiIslands45,
    .palettes = gTilesetPalettes_SeviiIslands45,
    .metatiles = gMetatiles_SeviiIslands45,
    .metatileAttributes = gMetatileAttributes_SeviiIslands45,
    .callback = NULL,
};

const struct Tileset gTileset_SeviiIslands67 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeviiIslands67,
    .palettes = gTilesetPalettes_SeviiIslands67,
    .metatiles = gMetatiles_SeviiIslands67,
    .metatileAttributes = gMetatileAttributes_SeviiIslands67,
    .callback = NULL,
};

const struct Tileset gTileset_TrainerTower =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TrainerTower,
    .palettes = gTilesetPalettes_TrainerTower,
    .metatiles = gMetatiles_TrainerTower,
    .metatileAttributes = gMetatileAttributes_TrainerTower,
    .callback = NULL,
};

const struct Tileset gTileset_IslandHarbor_Frlg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_IslandHarbor_Frlg,
    .palettes = gTilesetPalettes_IslandHarbor_Frlg,
    .metatiles = gMetatiles_IslandHarbor_Frlg,
    .metatileAttributes = gMetatileAttributes_IslandHarbor_Frlg,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonLeague =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonLeague,
    .palettes = gTilesetPalettes_PokemonLeague,
    .metatiles = gMetatiles_PokemonLeague,
    .metatileAttributes = gMetatileAttributes_PokemonLeague,
    .callback = NULL,
};

const struct Tileset gTileset_HallOfFame =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_HallOfFame,
    .palettes = gTilesetPalettes_HallOfFame,
    .metatiles = gMetatiles_HallOfFame,
    .metatileAttributes = gMetatileAttributes_HallOfFame,
    .callback = NULL,
};

#elif IS_HNS


// HnS tilesets
const struct Tileset gTileset_General_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_General_Hns,
    .palettes = gTilesetPalettes_General_Hns,
    .metatiles = gMetatiles_General_Hns,
    .metatileAttributes = gMetatileAttributes_General_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Johto_Building_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Johto_Building_Hns,
    .palettes = gTilesetPalettes_Johto_Building_Hns,
    .metatiles = gMetatiles_Johto_Building_Hns,
    .metatileAttributes = gMetatileAttributes_Johto_Building_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Johto_General_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Johto_General_Hns,
    .palettes = gTilesetPalettes_Johto_General_Hns,
    .metatiles = gMetatiles_Johto_General_Hns,
    .metatileAttributes = gMetatileAttributes_Johto_General_Hns,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_Johto_NorthEast_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Johto_NorthEast_Hns,
    .palettes = gTilesetPalettes_Johto_NorthEast_Hns,
    .metatiles = gMetatiles_Johto_NorthEast_Hns,
    .metatileAttributes = gMetatileAttributes_Johto_NorthEast_Hns,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_Johto_NorthWest_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Johto_NorthWest_Hns,
    .palettes = gTilesetPalettes_Johto_NorthWest_Hns,
    .metatiles = gMetatiles_Johto_NorthWest_Hns,
    .metatileAttributes = gMetatileAttributes_Johto_NorthWest_Hns,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_Johto_South_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Johto_South_Hns,
    .palettes = gTilesetPalettes_Johto_South_Hns,
    .metatiles = gMetatiles_Johto_South_Hns,
    .metatileAttributes = gMetatileAttributes_Johto_South_Hns,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_Kanto_Building_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Kanto_Building_Hns,
    .palettes = gTilesetPalettes_Kanto_Building_Hns,
    .metatiles = gMetatiles_Kanto_Building_Hns,
    .metatileAttributes = gMetatileAttributes_Kanto_Building_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Kanto_General_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_Kanto_General_Hns,
    .palettes = gTilesetPalettes_Kanto_General_Hns,
    .metatiles = gMetatiles_Kanto_General_Hns,
    .metatileAttributes = gMetatileAttributes_Kanto_General_Hns,
    .callback = InitTilesetAnim_JohtoGeneral,
};

const struct Tileset gTileset_AzaleaTown_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_AzaleaTown_Hns,
    .palettes = gTilesetPalettes_AzaleaTown_Hns,
    .metatiles = gMetatiles_AzaleaTown_Hns,
    .metatileAttributes = gMetatileAttributes_AzaleaTown_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_AzaleaTown_Gym_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_AzaleaTown_Gym_Hns,
    .palettes = gTilesetPalettes_AzaleaTown_Gym_Hns,
    .metatiles = gMetatiles_AzaleaTown_Gym_Hns,
    .metatileAttributes = gMetatileAttributes_AzaleaTown_Gym_Hns,
    .callback = InitTilesetAnim_AzaleaTownGym,
};

const struct Tileset gTileset_Barn_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Barn_Hns,
    .palettes = gTilesetPalettes_Barn_Hns,
    .metatiles = gMetatiles_Barn_Hns,
    .metatileAttributes = gMetatileAttributes_Barn_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_BellchimeTrail_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BellchimeTrail_Hns,
    .palettes = gTilesetPalettes_BellchimeTrail_Hns,
    .metatiles = gMetatiles_BellchimeTrail_Hns,
    .metatileAttributes = gMetatileAttributes_BellchimeTrail_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_BikeShop_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BikeShop_Hns,
    .palettes = gTilesetPalettes_BikeShop_Hns,
    .metatiles = gMetatiles_BikeShop_Hns,
    .metatileAttributes = gMetatileAttributes_BikeShop_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Blackthorn_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Blackthorn_Hns,
    .palettes = gTilesetPalettes_Blackthorn_Hns,
    .metatiles = gMetatiles_Blackthorn_Hns,
    .metatileAttributes = gMetatileAttributes_Blackthorn_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_BlackthornGym_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BlackthornGym_Hns,
    .palettes = gTilesetPalettes_BlackthornGym_Hns,
    .metatiles = gMetatiles_BlackthornGym_Hns,
    .metatileAttributes = gMetatileAttributes_BlackthornGym_Hns,
    .callback = InitTilesetAnim_BlackthornGym,
};

const struct Tileset gTileset_BurnedTower_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BurnedTower_Hns,
    .palettes = gTilesetPalettes_BurnedTower_Hns,
    .metatiles = gMetatiles_BurnedTower_Hns,
    .metatileAttributes = gMetatileAttributes_BurnedTower_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Cafe_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cafe_Hns,
    .palettes = gTilesetPalettes_Cafe_Hns,
    .metatiles = gMetatiles_Cafe_Hns,
    .metatileAttributes = gMetatileAttributes_Cafe_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_Default_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_Default_Hns,
    .palettes = gTilesetPalettes_Cave_Default_Hns,
    .metatiles = gMetatiles_Cave_Default_Hns,
    .metatileAttributes = gMetatileAttributes_Cave_Default_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_DragonsDen_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_DragonsDen_Hns,
    .palettes = gTilesetPalettes_Cave_DragonsDen_Hns,
    .metatiles = gMetatiles_Cave_DragonsDen_Hns,
    .metatileAttributes = gMetatileAttributes_Cave_DragonsDen_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_Gray_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_Gray_Hns,
    .palettes = gTilesetPalettes_Cave_Gray_Hns,
    .metatiles = gMetatiles_Cave_Gray_Hns,
    .metatileAttributes = gMetatileAttributes_Cave_Gray_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_Green_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_Green_Hns,
    .palettes = gTilesetPalettes_Cave_Green_Hns,
    .metatiles = gMetatiles_Cave_Green_Hns,
    .metatileAttributes = gMetatileAttributes_Cave_Green_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_Ice_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_Ice_Hns,
    .palettes = gTilesetPalettes_Cave_Ice_Hns,
    .metatiles = gMetatiles_Cave_Ice_Hns,
    .metatileAttributes = gMetatileAttributes_Cave_Ice_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_MtMoon_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_MtMoon_Hns,
    .palettes = gTilesetPalettes_Cave_MtMoon_Hns,
    .metatiles = gMetatiles_Cave_MtMoon_Hns,
    .metatileAttributes = gMetatileAttributes_Cave_MtMoon_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Cave_Sandy_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave_Sandy_Hns,
    .palettes = gTilesetPalettes_Cave_Sandy_Hns,
    .metatiles = gMetatiles_Cave_Sandy_Hns,
    .metatileAttributes = gMetatileAttributes_Cave_Sandy_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_CeladonApartments_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeladonApartments_Hns,
    .palettes = gTilesetPalettes_CeladonApartments_Hns,
    .metatiles = gMetatiles_CeladonApartments_Hns,
    .metatileAttributes = gMetatileAttributes_CeladonApartments_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_CeladonCity_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeladonCity_Hns,
    .palettes = gTilesetPalettes_CeladonCity_Hns,
    .metatiles = gMetatiles_CeladonCity_Hns,
    .metatileAttributes = gMetatileAttributes_CeladonCity_Hns,
    .callback = InitTilesetAnim_CeladonCity_Hns,
};

const struct Tileset gTileset_CeruleanCity_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanCity_Hns,
    .palettes = gTilesetPalettes_CeruleanCity_Hns,
    .metatiles = gMetatiles_CeruleanCity_Hns,
    .metatileAttributes = gMetatileAttributes_CeruleanCity_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_CeruleanCity_Gym_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanCity_Gym_Hns,
    .palettes = gTilesetPalettes_CeruleanCity_Gym_Hns,
    .metatiles = gMetatiles_CeruleanCity_Gym_Hns,
    .metatileAttributes = gMetatileAttributes_CeruleanCity_Gym_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_CherrygroveCity_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CherrygroveCity_Hns,
    .palettes = gTilesetPalettes_CherrygroveCity_Hns,
    .metatiles = gMetatiles_CherrygroveCity_Hns,
    .metatileAttributes = gMetatileAttributes_CherrygroveCity_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_CianwoodCity_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CianwoodCity_Hns,
    .palettes = gTilesetPalettes_CianwoodCity_Hns,
    .metatiles = gMetatiles_CianwoodCity_Hns,
    .metatileAttributes = gMetatileAttributes_CianwoodCity_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_CianwoodCity_Gym_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CianwoodCity_Gym_Hns,
    .palettes = gTilesetPalettes_CianwoodCity_Gym_Hns,
    .metatiles = gMetatiles_CianwoodCity_Gym_Hns,
    .metatileAttributes = gMetatileAttributes_CianwoodCity_Gym_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_CyclingRoad_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CyclingRoad_Hns,
    .palettes = gTilesetPalettes_CyclingRoad_Hns,
    .metatiles = gMetatiles_CyclingRoad_Hns,
    .metatileAttributes = gMetatileAttributes_CyclingRoad_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_DepartmentStore_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DepartmentStore_Hns,
    .palettes = gTilesetPalettes_DepartmentStore_Hns,
    .metatiles = gMetatiles_DepartmentStore_Hns,
    .metatileAttributes = gMetatileAttributes_DepartmentStore_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_DragonsDen_Shrine_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DragonsDen_Shrine_Hns,
    .palettes = gTilesetPalettes_DragonsDen_Shrine_Hns,
    .metatiles = gMetatiles_DragonsDen_Shrine_Hns,
    .metatileAttributes = gMetatileAttributes_DragonsDen_Shrine_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_EcruteakCity_Gym_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EcruteakCity_Gym_Hns,
    .palettes = gTilesetPalettes_EcruteakCity_Gym_Hns,
    .metatiles = gMetatiles_EcruteakCity_Gym_Hns,
    .metatileAttributes = gMetatileAttributes_EcruteakCity_Gym_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_EcruteakTheater_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EcruteakTheater_Hns,
    .palettes = gTilesetPalettes_EcruteakTheater_Hns,
    .metatiles = gMetatiles_EcruteakTheater_Hns,
    .metatileAttributes = gMetatileAttributes_EcruteakTheater_Hns,
    .callback = InitTilesetAnim_EcruteakTheater,
};

const struct Tileset gTileset_Ecruteak_City_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Ecruteak_City_Hns,
    .palettes = gTilesetPalettes_Ecruteak_City_Hns,
    .metatiles = gMetatiles_Ecruteak_City_Hns,
    .metatileAttributes = gMetatileAttributes_Ecruteak_City_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Fuchsia_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Fuchsia_Hns,
    .palettes = gTilesetPalettes_Fuchsia_Hns,
    .metatiles = gMetatiles_Fuchsia_Hns,
    .metatileAttributes = gMetatileAttributes_Fuchsia_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_FuchsiaCity_Gym_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FuchsiaCity_Gym_Hns,
    .palettes = gTilesetPalettes_FuchsiaCity_Gym_Hns,
    .metatiles = gMetatiles_FuchsiaCity_Gym_Hns,
    .metatileAttributes = gMetatileAttributes_FuchsiaCity_Gym_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_GameCorner_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GameCorner_Hns,
    .palettes = gTilesetPalettes_GameCorner_Hns,
    .metatiles = gMetatiles_GameCorner_Hns,
    .metatileAttributes = gMetatileAttributes_GameCorner_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Gate_Standard_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Gate_Standard_Hns,
    .palettes = gTilesetPalettes_Gate_Standard_Hns,
    .metatiles = gMetatiles_Gate_Standard_Hns,
    .metatileAttributes = gMetatileAttributes_Gate_Standard_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Goldenrod_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Goldenrod_Hns,
    .palettes = gTilesetPalettes_Goldenrod_Hns,
    .metatiles = gMetatiles_Goldenrod_Hns,
    .metatileAttributes = gMetatileAttributes_Goldenrod_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_GoldenrodCity_TrainStation_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GoldenrodCity_TrainStation_Hns,
    .palettes = gTilesetPalettes_GoldenrodCity_TrainStation_Hns,
    .metatiles = gMetatiles_GoldenrodCity_TrainStation_Hns,
    .metatileAttributes = gMetatileAttributes_GoldenrodCity_TrainStation_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_GoldenrodUndergroundRocket_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GoldenrodUndergroundRocket_Hns,
    .palettes = gTilesetPalettes_GoldenrodUndergroundRocket_Hns,
    .metatiles = gMetatiles_GoldenrodUndergroundRocket_Hns,
    .metatileAttributes = gMetatileAttributes_GoldenrodUndergroundRocket_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_GoldenrodUndergroundTunnel_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GoldenrodUndergroundTunnel_Hns,
    .palettes = gTilesetPalettes_GoldenrodUndergroundTunnel_Hns,
    .metatiles = gMetatiles_GoldenrodUndergroundTunnel_Hns,
    .metatileAttributes = gMetatileAttributes_GoldenrodUndergroundTunnel_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Goldenrod_Underground_Storage_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Goldenrod_Underground_Storage_Hns,
    .palettes = gTilesetPalettes_Goldenrod_Underground_Storage_Hns,
    .metatiles = gMetatiles_Goldenrod_Underground_Storage_Hns,
    .metatileAttributes = gMetatileAttributes_Goldenrod_Underground_Storage_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_HallOfFame_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_HallOfFame_Hns,
    .palettes = gTilesetPalettes_HallOfFame_Hns,
    .metatiles = gMetatiles_HallOfFame_Hns,
    .metatileAttributes = gMetatileAttributes_HallOfFame_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_House_2_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_House_2_Hns,
    .palettes = gTilesetPalettes_House_2_Hns,
    .metatiles = gMetatiles_House_2_Hns,
    .metatileAttributes = gMetatileAttributes_House_2_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_House_Lab_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_House_Lab_Hns,
    .palettes = gTilesetPalettes_House_Lab_Hns,
    .metatiles = gMetatiles_House_Lab_Hns,
    .metatileAttributes = gMetatileAttributes_House_Lab_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_IlexForest_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_IlexForest_Hns,
    .palettes = gTilesetPalettes_IlexForest_Hns,
    .metatiles = gMetatiles_IlexForest_Hns,
    .metatileAttributes = gMetatileAttributes_IlexForest_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_IndigoPlateau_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_IndigoPlateau_Hns,
    .palettes = gTilesetPalettes_IndigoPlateau_Hns,
    .metatiles = gMetatiles_IndigoPlateau_Hns,
    .metatileAttributes = gMetatileAttributes_IndigoPlateau_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoBikeShop_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoBikeShop_Hns,
    .palettes = gTilesetPalettes_JohtoBikeShop_Hns,
    .metatiles = gMetatiles_JohtoBikeShop_Hns,
    .metatileAttributes = gMetatileAttributes_JohtoBikeShop_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoMart_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoMart_Hns,
    .palettes = gTilesetPalettes_JohtoMart_Hns,
    .metatiles = gMetatiles_JohtoMart_Hns,
    .metatileAttributes = gMetatileAttributes_JohtoMart_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_KantoMart_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KantoMart_Hns,
    .palettes = gTilesetPalettes_KantoMart_Hns,
    .metatiles = gMetatiles_KantoMart_Hns,
    .metatileAttributes = gMetatileAttributes_KantoMart_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Kanto_PokemonCenter_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Kanto_PokemonCenter_Hns,
    .palettes = gTilesetPalettes_Kanto_PokemonCenter_Hns,
    .metatiles = gMetatiles_Kanto_PokemonCenter_Hns,
    .metatileAttributes = gMetatileAttributes_Kanto_PokemonCenter_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_KurtsHouse_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KurtsHouse_Hns,
    .palettes = gTilesetPalettes_KurtsHouse_Hns,
    .metatiles = gMetatiles_KurtsHouse_Hns,
    .metatileAttributes = gMetatileAttributes_KurtsHouse_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Lavaridge_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lavaridge_Hns,
    .palettes = gTilesetPalettes_Lavaridge_Hns,
    .metatiles = gMetatiles_Lavaridge_Hns,
    .metatileAttributes = gMetatileAttributes_Lavaridge_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_LavenderTown_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LavenderTown_Hns,
    .palettes = gTilesetPalettes_LavenderTown_Hns,
    .metatiles = gMetatiles_LavenderTown_Hns,
    .metatileAttributes = gMetatileAttributes_LavenderTown_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Lighthouse_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lighthouse_Hns,
    .palettes = gTilesetPalettes_Lighthouse_Hns,
    .metatiles = gMetatiles_Lighthouse_Hns,
    .metatileAttributes = gMetatileAttributes_Lighthouse_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_MahoganyTown_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MahoganyTown_Hns,
    .palettes = gTilesetPalettes_MahoganyTown_Hns,
    .metatiles = gMetatiles_MahoganyTown_Hns,
    .metatileAttributes = gMetatileAttributes_MahoganyTown_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_MtSilverSnow_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MtSilverSnow_Hns,
    .palettes = gTilesetPalettes_MtSilverSnow_Hns,
    .metatiles = gMetatiles_MtSilverSnow_Hns,
    .metatileAttributes = gMetatileAttributes_MtSilverSnow_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Museum_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Museum_Hns,
    .palettes = gTilesetPalettes_Museum_Hns,
    .metatiles = gMetatiles_Museum_Hns,
    .metatileAttributes = gMetatileAttributes_Museum_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_NationalPark_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_NationalPark_Hns,
    .palettes = gTilesetPalettes_NationalPark_Hns,
    .metatiles = gMetatiles_NationalPark_Hns,
    .metatileAttributes = gMetatileAttributes_NationalPark_Hns,
    .callback = InitTilesetAnim_NationalPark,
};

const struct Tileset gTileset_NewBarkTown_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_NewBarkTown_Hns,
    .palettes = gTilesetPalettes_NewBarkTown_Hns,
    .metatiles = gMetatiles_NewBarkTown_Hns,
    .metatileAttributes = gMetatileAttributes_NewBarkTown_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_OlivineCity_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_OlivineCity_Hns,
    .palettes = gTilesetPalettes_OlivineCity_Hns,
    .metatiles = gMetatiles_OlivineCity_Hns,
    .metatileAttributes = gMetatileAttributes_OlivineCity_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_PalletTown_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PalletTown_Hns,
    .palettes = gTilesetPalettes_PalletTown_Hns,
    .metatiles = gMetatiles_PalletTown_Hns,
    .metatileAttributes = gMetatileAttributes_PalletTown_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_PewterCity_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PewterCity_Hns,
    .palettes = gTilesetPalettes_PewterCity_Hns,
    .metatiles = gMetatiles_PewterCity_Hns,
    .metatileAttributes = gMetatileAttributes_PewterCity_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_PlayersHouse_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PlayersHouse_Hns,
    .palettes = gTilesetPalettes_PlayersHouse_Hns,
    .metatiles = gMetatiles_PlayersHouse_Hns,
    .metatileAttributes = gMetatileAttributes_PlayersHouse_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonCenter_White_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonCenter_White_Hns,
    .palettes = gTilesetPalettes_PokemonCenter_White_Hns,
    .metatiles = gMetatiles_PokemonCenter_White_Hns,
    .metatileAttributes = gMetatileAttributes_PokemonCenter_White_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonDayCare_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonDayCare_Hns,
    .palettes = gTilesetPalettes_PokemonDayCare_Hns,
    .metatiles = gMetatiles_PokemonDayCare_Hns,
    .metatileAttributes = gMetatileAttributes_PokemonDayCare_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonLeague_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonLeague_Hns,
    .palettes = gTilesetPalettes_PokemonLeague_Hns,
    .metatiles = gMetatiles_PokemonLeague_Hns,
    .metatileAttributes = gMetatileAttributes_PokemonLeague_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_PortIndoor_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PortIndoor_Hns,
    .palettes = gTilesetPalettes_PortIndoor_Hns,
    .metatiles = gMetatiles_PortIndoor_Hns,
    .metatileAttributes = gMetatileAttributes_PortIndoor_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_PowerPlant_GeneratorRoom_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PowerPlant_GeneratorRoom_Hns,
    .palettes = gTilesetPalettes_PowerPlant_GeneratorRoom_Hns,
    .metatiles = gMetatiles_PowerPlant_GeneratorRoom_Hns,
    .metatileAttributes = gMetatileAttributes_PowerPlant_GeneratorRoom_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Route32_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Route32_Hns,
    .palettes = gTilesetPalettes_Route32_Hns,
    .metatiles = gMetatiles_Route32_Hns,
    .metatileAttributes = gMetatileAttributes_Route32_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Route38_Farmland_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Route38_Farmland_Hns,
    .palettes = gTilesetPalettes_Route38_Farmland_Hns,
    .metatiles = gMetatiles_Route38_Farmland_Hns,
    .metatileAttributes = gMetatileAttributes_Route38_Farmland_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_RuinsOfAlphWriting_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RuinsOfAlphWriting_Hns,
    .palettes = gTilesetPalettes_RuinsOfAlphWriting_Hns,
    .metatiles = gMetatiles_RuinsOfAlphWriting_Hns,
    .metatileAttributes = gMetatileAttributes_RuinsOfAlphWriting_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_RuinsOfAlph_B1F_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RuinsOfAlph_B1F_Hns,
    .palettes = gTilesetPalettes_RuinsOfAlph_B1F_Hns,
    .metatiles = gMetatiles_RuinsOfAlph_B1F_Hns,
    .metatileAttributes = gMetatileAttributes_RuinsOfAlph_B1F_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_RuinsOfAlph_Outside_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RuinsOfAlph_Outside_Hns,
    .palettes = gTilesetPalettes_RuinsOfAlph_Outside_Hns,
    .metatiles = gMetatiles_RuinsOfAlph_Outside_Hns,
    .metatileAttributes = gMetatileAttributes_RuinsOfAlph_Outside_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_SafariZoneJohto_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SafariZoneJohto_Hns,
    .palettes = gTilesetPalettes_SafariZoneJohto_Hns,
    .metatiles = gMetatiles_SafariZoneJohto_Hns,
    .metatileAttributes = gMetatileAttributes_SafariZoneJohto_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_SafariZone_Entrance_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SafariZone_Entrance_Hns,
    .palettes = gTilesetPalettes_SafariZone_Entrance_Hns,
    .metatiles = gMetatiles_SafariZone_Entrance_Hns,
    .metatileAttributes = gMetatileAttributes_SafariZone_Entrance_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_SaffronCity_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SaffronCity_Hns,
    .palettes = gTilesetPalettes_SaffronCity_Hns,
    .metatiles = gMetatiles_SaffronCity_Hns,
    .metatileAttributes = gMetatileAttributes_SaffronCity_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_SaffronCity_FightingDojoVIP_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SaffronCity_FightingDojoVIP_Hns,
    .palettes = gTilesetPalettes_SaffronCity_FightingDojoVIP_Hns,
    .metatiles = gMetatiles_SaffronCity_FightingDojoVIP_Hns,
    .metatileAttributes = gMetatileAttributes_SaffronCity_FightingDojoVIP_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_SaffronCity_Gym_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SaffronCity_Gym_Hns,
    .palettes = gTilesetPalettes_SaffronCity_Gym_Hns,
    .metatiles = gMetatiles_SaffronCity_Gym_Hns,
    .metatileAttributes = gMetatileAttributes_SaffronCity_Gym_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_SeaCottage_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeaCottage_Hns,
    .palettes = gTilesetPalettes_SeaCottage_Hns,
    .metatiles = gMetatiles_SeaCottage_Hns,
    .metatileAttributes = gMetatileAttributes_SeaCottage_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_ShopRooftop_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ShopRooftop_Hns,
    .palettes = gTilesetPalettes_ShopRooftop_Hns,
    .metatiles = gMetatiles_ShopRooftop_Hns,
    .metatileAttributes = gMetatileAttributes_ShopRooftop_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_SilphCo_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SilphCo_Hns,
    .palettes = gTilesetPalettes_SilphCo_Hns,
    .metatiles = gMetatiles_SilphCo_Hns,
    .metatileAttributes = gMetatileAttributes_SilphCo_Hns,
    .callback = InitTilesetAnim_SilphCo_Hns,
};

const struct Tileset gTileset_SootopolisGym_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SootopolisGym_Hns,
    .palettes = gTilesetPalettes_SootopolisGym_Hns,
    .metatiles = gMetatiles_SootopolisGym_Hns,
    .metatileAttributes = gMetatileAttributes_SootopolisGym_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_SoulHouse_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SoulHouse_Hns,
    .palettes = gTilesetPalettes_SoulHouse_Hns,
    .metatiles = gMetatiles_SoulHouse_Hns,
    .metatileAttributes = gMetatileAttributes_SoulHouse_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_TrainerHill_Courtyard_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TrainerHill_Courtyard_Hns,
    .palettes = gTilesetPalettes_TrainerHill_Courtyard_Hns,
    .metatiles = gMetatiles_TrainerHill_Courtyard_Hns,
    .metatileAttributes = gMetatileAttributes_TrainerHill_Courtyard_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_TrainerSchool_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TrainerSchool_Hns,
    .palettes = gTilesetPalettes_TrainerSchool_Hns,
    .metatiles = gMetatiles_TrainerSchool_Hns,
    .metatileAttributes = gMetatileAttributes_TrainerSchool_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_Vermilion_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Vermilion_Hns,
    .palettes = gTilesetPalettes_Vermilion_Hns,
    .metatiles = gMetatiles_Vermilion_Hns,
    .metatileAttributes = gMetatileAttributes_Vermilion_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_VermilionCity_Gym_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_VermilionCity_Gym_Hns,
    .palettes = gTilesetPalettes_VermilionCity_Gym_Hns,
    .metatiles = gMetatiles_VermilionCity_Gym_Hns,
    .metatileAttributes = gMetatileAttributes_VermilionCity_Gym_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_VioletCity_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_VioletCity_Hns,
    .palettes = gTilesetPalettes_VioletCity_Hns,
    .metatiles = gMetatiles_VioletCity_Hns,
    .metatileAttributes = gMetatileAttributes_VioletCity_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_ViridianCity_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianCity_Hns,
    .palettes = gTilesetPalettes_ViridianCity_Hns,
    .metatiles = gMetatiles_ViridianCity_Hns,
    .metatileAttributes = gMetatileAttributes_ViridianCity_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_ViridianCity_Gym_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianCity_Gym_Hns,
    .palettes = gTilesetPalettes_ViridianCity_Gym_Hns,
    .metatiles = gMetatiles_ViridianCity_Gym_Hns,
    .metatileAttributes = gMetatileAttributes_ViridianCity_Gym_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_ViridianForest_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianForest_Hns,
    .palettes = gTilesetPalettes_ViridianForest_Hns,
    .metatiles = gMetatiles_ViridianForest_Hns,
    .metatileAttributes = gMetatileAttributes_ViridianForest_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_WhirlIslands_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_WhirlIslands_Hns,
    .palettes = gTilesetPalettes_WhirlIslands_Hns,
    .metatiles = gMetatiles_WhirlIslands_Hns,
    .metatileAttributes = gMetatileAttributes_WhirlIslands_Hns,
    .callback = NULL,
};

const struct Tileset gTileset_ssaqua_Hns =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ssaqua_Hns,
    .palettes = gTilesetPalettes_ssaqua_Hns,
    .metatiles = gMetatiles_ssaqua_Hns,
    .metatileAttributes = gMetatileAttributes_ssaqua_Hns,
    .callback = NULL,
};

#endif // IS_FRLG || IS_HNS
