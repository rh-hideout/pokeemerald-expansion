#include "global.h"
#include "event_data.h"
#include "field_door.h"
#include "field_camera.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "task.h"
#include "tilesets.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"

#define DOOR_SOUND_NORMAL  0
#define DOOR_SOUND_SLIDING 1
#define DOOR_SOUND_ARENA   2

struct DoorGraphics
{
    u16 metatileNum;
    const struct Tileset *tileset;
    u8 sound;
    u8 size;
    const void *tiles;
    const void *palettes;
};

struct DoorAnimFrame
{
    u8 time;
    u16 offset;
};

static bool8 ShouldUseMultiCorridorDoor(void);

static const u8 sDoorAnimTiles_Littleroot[] = INCBIN_U8("graphics/door_anims/littleroot.4bpp");
static const u16 sDoorNullPalette1[16] = {};
static const u8 sDoorAnimTiles_BirchsLab[] = INCBIN_U8("graphics/door_anims/birchs_lab.4bpp");
static const u16 sDoorNullPalette2[16] = {};
static const u8 sDoorAnimTiles_FallarborLightRoof[] = INCBIN_U8("graphics/door_anims/fallarbor_light_roof.4bpp");
static const u16 sDoorNullPalette3[16] = {};
static const u8 sDoorAnimTiles_Lilycove[] = INCBIN_U8("graphics/door_anims/lilycove.4bpp");
static const u16 sDoorNullPalette4[16] = {};
static const u8 sDoorAnimTiles_LilycoveWooden[] = INCBIN_U8("graphics/door_anims/lilycove_wooden.4bpp");
static const u16 sDoorNullPalette5[16] = {};
static const u8 sDoorAnimTiles_General[] = INCBIN_U8("graphics/door_anims/general.4bpp");
static const u16 sDoorNullPalette6[16] = {};
static const u8 sDoorAnimTiles_PokeCenter[] = INCBIN_U8("graphics/door_anims/poke_center.4bpp");
static const u8 sDoorAnimTiles_Gym[] = INCBIN_U8("graphics/door_anims/gym.4bpp");
static const u8 sDoorAnimTiles_PokeMart[] = INCBIN_U8("graphics/door_anims/poke_mart.4bpp");
static const u8 sDoorAnimTiles_RustboroTan[] = INCBIN_U8("graphics/door_anims/rustboro_tan.4bpp");
static const u16 sDoorNullPalette7[16] = {};
static const u8 sDoorAnimTiles_RustboroGray[] = INCBIN_U8("graphics/door_anims/rustboro_gray.4bpp");
static const u16 sDoorNullPalette8[16] = {};
static const u8 sDoorAnimTiles_Oldale[] = INCBIN_U8("graphics/door_anims/oldale.4bpp");
static const u8 sFiller1[0x5900] = {};
static const u8 sDoorAnimTiles_UnusedTops[] = INCBIN_U8("graphics/door_anims/unused_top.4bpp");
static const u8 sFiller2[0x140] = {};
static const u8 sDoorAnimTiles_UnusedBottoms[] = INCBIN_U8("graphics/door_anims/unused_bottom.4bpp");
static const u16 sDoorNullPalette11[16] = {};
static const u8 sDoorAnimTiles_Mauville[] = INCBIN_U8("graphics/door_anims/mauville.4bpp");
static const u16 sDoorNullPalette12[16] = {};
static const u8 sDoorAnimTiles_Verdanturf[] = INCBIN_U8("graphics/door_anims/verdanturf.4bpp");
static const u16 sDoorNullPalette13[16] = {};
static const u8 sDoorAnimTiles_Slateport[] = INCBIN_U8("graphics/door_anims/slateport.4bpp");
static const u16 sDoorNullPalette14[16] = {};
static const u8 sDoorAnimTiles_Dewford[] = INCBIN_U8("graphics/door_anims/dewford.4bpp");
static const u16 sDoorNullPalette15[16] = {};
static const u8 sDoorAnimTiles_Contest[] = INCBIN_U8("graphics/door_anims/contest.4bpp");
static const u16 sDoorNullPalette16[16] = {};
static const u8 sDoorAnimTiles_Mossdeep[] = INCBIN_U8("graphics/door_anims/mossdeep.4bpp");
static const u16 sDoorNullPalette17[16] = {};
static const u8 sDoorAnimTiles_SootopolisPeakedRoof[] = INCBIN_U8("graphics/door_anims/sootopolis_peaked_roof.4bpp");
static const u16 sDoorNullPalette18[16] = {};
static const u8 sDoorAnimTiles_Sootopolis[] = INCBIN_U8("graphics/door_anims/sootopolis.4bpp");
static const u16 sDoorNullPalette19[16] = {};
static const u8 sDoorAnimTiles_PokemonLeague[] = INCBIN_U8("graphics/door_anims/pokemon_league.4bpp");
static const u16 sDoorNullPalette20[16] = {};
static const u8 sDoorAnimTiles_Pacifidlog[] = INCBIN_U8("graphics/door_anims/pacifidlog.4bpp");
static const u16 sDoorNullPalette21[16] = {};
static const u8 sDoorAnimTiles_PetalburgGym[] = INCBIN_U8("graphics/door_anims/petalburg_gym.4bpp");
static const u16 sDoorNullPalette22[16] = {};
static const u8 sDoorAnimTiles_CyclingRoad[] = INCBIN_U8("graphics/door_anims/cycling_road.4bpp");
static const u16 sDoorNullPalette23[16] = {};
static const u8 sDoorAnimTiles_LilycoveDeptStore[] = INCBIN_U8("graphics/door_anims/lilycove_dept_store.4bpp");
static const u16 sDoorNullPalette24[16] = {};
static const u8 sDoorAnimTiles_SafariZone[] = INCBIN_U8("graphics/door_anims/safari_zone.4bpp");
static const u16 sDoorNullPalette25[16] = {};
static const u8 sDoorAnimTiles_MossdeepSpaceCenter[] = INCBIN_U8("graphics/door_anims/mossdeep_space_center.4bpp");
static const u16 sDoorNullPalette26[16] = {};
static const u8 sDoorAnimTiles_CableClub[] = INCBIN_U8("graphics/door_anims/cable_club.4bpp");
static const u16 sDoorNullPalette27[16] = {};
static const u8 sDoorAnimTiles_AbandonedShip[] = INCBIN_U8("graphics/door_anims/abandoned_ship.4bpp");
static const u16 sDoorNullPalette28[16] = {};
static const u8 sDoorAnimTiles_FallarborDarkRoof[] = INCBIN_U8("graphics/door_anims/fallarbor_dark_roof.4bpp");
static const u16 sDoorNullPalette29[16] = {};
static const u8 sDoorAnimTiles_AbandonedShipRoom[] = INCBIN_U8("graphics/door_anims/abandoned_ship_room.4bpp");
static const u16 sDoorNullPalette30[16] = {};
static const u8 sDoorAnimTiles_LilycoveDeptStoreElevator[] = INCBIN_U8("graphics/door_anims/lilycove_dept_store_elevator.4bpp");
static const u16 sDoorNullPalette31[16] = {};
static const u8 sDoorAnimTiles_BattleTowerOld[] = INCBIN_U8("graphics/door_anims/battle_tower_old.4bpp");
static const u16 sDoorNullPalette32[16] = {};
static const u8 sDoorAnimTiles_BattleTowerElevator[] = INCBIN_U8("graphics/door_anims/battle_tower_elevator.4bpp");
static const u16 sDoorNullPalette33[16] = {};
static const u8 sDoorAnimTiles_UnusedBattleFrontier[] = INCBIN_U8("graphics/door_anims/unused_battle_frontier.4bpp");
static const u16 sDoorNullPalette34[16] = {};
static const u8 sDoorAnimTiles_BattleDome[] = INCBIN_U8("graphics/door_anims/battle_dome.4bpp");
static const u16 sDoorNullPalette35[16] = {};
static const u8 sDoorAnimTiles_BattleFactory[] = INCBIN_U8("graphics/door_anims/battle_factory.4bpp");
static const u16 sDoorNullPalette36[16] = {};
static const u8 sDoorAnimTiles_BattleTower[] = INCBIN_U8("graphics/door_anims/battle_tower.4bpp");
static const u16 sDoorNullPalette37[16] = {};
static const u8 sDoorAnimTiles_BattleArena[] = INCBIN_U8("graphics/door_anims/battle_arena.4bpp");
static const u16 sDoorNullPalette38[16] = {};
static const u8 sDoorAnimTiles_BattleArenaLobby[] = INCBIN_U8("graphics/door_anims/battle_arena_lobby.4bpp");
static const u16 sDoorNullPalette39[16] = {};
static const u8 sDoorAnimTiles_BattleDomeLobby[] = INCBIN_U8("graphics/door_anims/battle_dome_lobby.4bpp");
static const u16 sDoorNullPalette40[16] = {};
static const u8 sDoorAnimTiles_BattlePalaceLobby[] = INCBIN_U8("graphics/door_anims/battle_palace_lobby.4bpp");
static const u8 sDoorAnimTiles_BattleTent[] = INCBIN_U8("graphics/door_anims/battle_tent.4bpp");
static const u16 sDoorNullPalette41[16] = {};
static const u8 sDoorAnimTiles_BattleDomeCorridor[] = INCBIN_U8("graphics/door_anims/battle_dome_corridor.4bpp");
static const u16 sDoorNullPalette42[16] = {};
static const u8 sDoorAnimTiles_BattleTowerMultiCorridor[] = INCBIN_U8("graphics/door_anims/battle_tower_multi_corridor.4bpp");
static const u16 sDoorNullPalette43[16] = {};
static const u8 sDoorAnimTiles_BattleFrontier[] = INCBIN_U8("graphics/door_anims/battle_frontier.4bpp");
static const u16 sDoorNullPalette44[16] = {};
static const u8 sDoorAnimTiles_BattleFrontierSliding[] = INCBIN_U8("graphics/door_anims/battle_frontier_sliding.4bpp");
static const u16 sDoorNullPalette45[16] = {};
static const u8 sDoorAnimTiles_BattleDomePreBattleRoom[] = INCBIN_U8("graphics/door_anims/battle_dome_pre_battle_room.4bpp");
static const u16 sDoorNullPalette46[16] = {};
static const u8 sDoorAnimTiles_BattleTentInterior[] = INCBIN_U8("graphics/door_anims/battle_tent_interior.4bpp");
static const u16 sDoorNullPalette47[16] = {};
static const u8 sDoorAnimTiles_TrainerHillLobbyElevator[] = INCBIN_U8("graphics/door_anims/trainer_hill_lobby_elevator.4bpp");
static const u16 sDoorNullPalette48[16] = {};
static const u8 sDoorAnimTiles_TrainerHillRoofElevator[] = INCBIN_U8("graphics/door_anims/trainer_hill_roof_elevator.4bpp");
static const u16 sDoorNullPalette49[16] = {};

#if IS_FRLG

static const u8 sDoorAnimTiles_GeneralFrlg[] = INCBIN_U8("graphics/door_anims/general_frlg.4bpp");
static const u8 sDoorAnimTiles_SlidingSingle[] = INCBIN_U8("graphics/door_anims/sliding_single.4bpp");
static const u8 sDoorAnimTiles_SlidingDouble[] = INCBIN_U8("graphics/door_anims/sliding_double.4bpp");
static const u8 sDoorAnimTiles_Pallet[] = INCBIN_U8("graphics/door_anims/pallet.4bpp");
static const u8 sDoorAnimTiles_OaksLab[] = INCBIN_U8("graphics/door_anims/oaks_lab.4bpp");
static const u8 sDoorAnimTiles_Viridian[] = INCBIN_U8("graphics/door_anims/viridian.4bpp");
static const u8 sDoorAnimTiles_Pewter[] = INCBIN_U8("graphics/door_anims/pewter.4bpp");
static const u8 sDoorAnimTiles_Saffron[] = INCBIN_U8("graphics/door_anims/saffron.4bpp");
static const u8 sDoorAnimTiles_SilphCo[] = INCBIN_U8("graphics/door_anims/silph_co.4bpp");
static const u8 sDoorAnimTiles_Cerulean[] = INCBIN_U8("graphics/door_anims/cerulean.4bpp");
static const u8 sDoorAnimTiles_Lavender[] = INCBIN_U8("graphics/door_anims/lavender.4bpp");
static const u8 sDoorAnimTiles_Vermilion[] = INCBIN_U8("graphics/door_anims/vermilion.4bpp");
static const u8 sDoorAnimTiles_PokemonFanClub[] = INCBIN_U8("graphics/door_anims/pokemon_fan_club.4bpp");
static const u8 sDoorAnimTiles_DeptStore[] = INCBIN_U8("graphics/door_anims/dept_store.4bpp");
static const u8 sDoorAnimTiles_Fuchsia[] = INCBIN_U8("graphics/door_anims/fuchsia.4bpp");
static const u8 sDoorAnimTiles_SafariZoneFrlg[] = INCBIN_U8("graphics/door_anims/safari_zone_frlg.4bpp");
static const u8 sDoorAnimTiles_CinnabarLab[] = INCBIN_U8("graphics/door_anims/cinnabar_lab.4bpp");
static const u8 sDoorAnimTiles_DeptStoreElevator[] = INCBIN_U8("graphics/door_anims/dept_store_elevator.4bpp");
static const u8 sDoorAnimTiles_CableClubFrlg[] = INCBIN_U8("graphics/door_anims/cable_club_frlg.4bpp");
static const u8 sDoorAnimTiles_HideoutElevator[] = INCBIN_U8("graphics/door_anims/hideout_elevator.4bpp");
static const u8 sDoorAnimTiles_SSAnne[] = INCBIN_U8("graphics/door_anims/ss_anne.4bpp");
static const u8 sDoorAnimTiles_SilphCoElevator[] = INCBIN_U8("graphics/door_anims/silph_co_elevator.4bpp");
static const u8 sDoorAnimTiles_Sevii123[] = INCBIN_U8("graphics/door_anims/sevii_123.4bpp");
static const u8 sDoorAnimTiles_JoyfulGameCorner[] = INCBIN_U8("graphics/door_anims/joyful_game_corner.4bpp");
static const u8 sDoorAnimTiles_OneIslandPokeCenter[] = INCBIN_U8("graphics/door_anims/one_island_poke_center.4bpp");
static const u8 sDoorAnimTiles_Sevii45[] = INCBIN_U8("graphics/door_anims/sevii_45.4bpp");
static const u8 sDoorAnimTiles_FourIslandDayCare[] = INCBIN_U8("graphics/door_anims/four_island_day_care.4bpp");
static const u8 sDoorAnimTiles_RocketWarehouse[] = INCBIN_U8("graphics/door_anims/rocket_warehouse.4bpp");
static const u8 sDoorAnimTiles_Sevii67[] = INCBIN_U8("graphics/door_anims/sevii_67.4bpp");
static const u8 sDoorAnimTiles_Teleporter[] = INCBIN_U8("graphics/door_anims/teleporter.4bpp");
static const u8 sDoorAnimTiles_TrainerTowerLobbyElevator[] = INCBIN_U8("graphics/door_anims/trainer_tower_lobby_elevator.4bpp");
static const u8 sDoorAnimTiles_TrainerTowerRoofElevator[] = INCBIN_U8("graphics/door_anims/trainer_tower_roof_elevator.4bpp");

#endif // IS_FRLG

static const struct DoorAnimFrame sDoorOpenAnimFrames[] =
{
    {4, -1},
    {4, 0},
    {4, 0x100},
    {4, 0x200},
    {0, 0},
};

static const struct DoorAnimFrame sDoorCloseAnimFrames[] =
{
    {4, 0x200},
    {4, 0x100},
    {4, 0},
    {4, -1},
    {0, 0},
};

static const struct DoorAnimFrame sBigDoorOpenAnimFrames[] =
{
    {4, -1},
    {4, 0},
    {4, 0x200},
    {4, 0x400},
    {0, 0},
};

static const struct DoorAnimFrame sBigDoorCloseAnimFrames[] =
{
    {4, 0x400},
    {4, 0x200},
    {4, 0},
    {4, -1},
    {0, 0},
};

static const struct DoorAnimFrame sDoorAnimFrames_OpenSmallFrlg[] = {
    {4, -1},
    {4, 0 * TILE_SIZE_4BPP},
    {4, 4 * TILE_SIZE_4BPP},
    {4, 8 * TILE_SIZE_4BPP},
    {}
};

static const struct DoorAnimFrame sDoorAnimFrames_CloseSmallFrlg[] = {
    {4, 8 * TILE_SIZE_4BPP},
    {4, 4 * TILE_SIZE_4BPP},
    {4, 0 * TILE_SIZE_4BPP},
    {4, -1},
    {}
};

static const struct DoorAnimFrame sDoorAnimFrames_OpenLargeFrlg[] = {
    {4, -1},
    {4, 0 * TILE_SIZE_4BPP},
    {4, 8 * TILE_SIZE_4BPP},
    {4, 16 * TILE_SIZE_4BPP},
    {}
};

static const struct DoorAnimFrame sDoorAnimFrames_CloseLargeFrlg[] = {
    {4, 16 * TILE_SIZE_4BPP},
    {4, 8 * TILE_SIZE_4BPP},
    {4, 0 * TILE_SIZE_4BPP},
    {4, -1},
    {}
};

static const u8 sDoorAnimPalettes_General[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_PokeCenter[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_Gym[] = {5, 5, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_PokeMart[] = {0, 0, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_Littleroot[] = {10, 10, 6, 6, 6, 6, 6, 6};
static const u8 sDoorAnimPalettes_BirchsLab[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_RustboroTan[] = {11, 11, 11, 11, 11, 11, 11, 11};
static const u8 sDoorAnimPalettes_RustboroGray[] = {10, 10, 10, 10, 10, 10, 10, 10};
static const u8 sDoorAnimPalettes_FallarborLightRoof[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_Lilycove[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_Oldale[] = {10, 10, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_Mossdeep[] = {9, 9, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_PokemonLeague[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_Pacifidlog[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_SootopolisPeakedRoof[] = {6, 6, 6, 6, 6, 6, 6, 6};
static const u8 sDoorAnimPalettes_Sootopolis[] = {6, 6, 6, 6, 6, 6, 6, 6};
static const u8 sDoorAnimPalettes_Dewford[] = {0, 0, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_Slateport[] = {6, 6, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_Mauville[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_Verdanturf[] = {6, 6, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_LilycoveWooden[] = {5, 5, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_Contest[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_PetalburgGym[] = {6, 6, 6, 6, 6, 6, 6, 6};
static const u8 sDoorAnimPalettes_CyclingRoad[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_LilycoveDeptStore[] = {5, 5, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_SafariZone[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_MossdeepSpaceCenter[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_CableClub[] = {6, 6, 6, 6, 6, 6, 6, 6};
static const u8 sDoorAnimPalettes_AbandonedShip[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_FallarborDarkRoof[] = {11, 11, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_AbandonedShipRoom[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_LilycoveDeptStoreElevator[] = {6, 6, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattleTowerOld[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_BattleTowerElevator[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_UnusedBattleFrontier[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_BattleDome[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_BattleFactory[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_BattleTower[] = {0, 0, 0, 0, 0, 0, 0, 0};
static const u8 sDoorAnimPalettes_BattleArena[] = {5, 5, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_BattleArenaLobby[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattleDomeLobby[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattlePalaceLobby[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattleTent[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_BattleDomeCorridor[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattleTowerMultiCorridor[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_Unused[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_BattleFrontier[] = {1, 1, 1, 1, 1, 1, 1, 1};
static const u8 sDoorAnimPalettes_BattleDomePreBattleRoom[] = {9, 9, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_BattleTentInterior[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_TrainerHillLobbyElevator[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_TrainerHillRoofElevator[] = {9, 9, 7, 7, 7, 7, 7, 7};

#if IS_FRLG

static const u8 sDoorAnimPalettes_GeneralFrlg[] = {2, 2, 2, 2, 2, 2, 2, 2};
static const u8 sDoorAnimPalettes_SlidingSingle[] = {3, 3, 3, 3, 3, 3, 3, 3};
static const u8 sDoorAnimPalettes_SlidingDouble[] = {3, 3, 3, 3, 3, 3, 3, 3};
static const u8 sDoorAnimPalettes_Pallet[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_OaksLab[] = {10, 10, 10, 10, 10, 10, 10, 10};
static const u8 sDoorAnimPalettes_Viridian[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_Pewter[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_Saffron[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_SilphCo[] = {3, 3, 3, 3, 3, 3, 3, 3};
static const u8 sDoorAnimPalettes_Cerulean[] = {12, 12, 12, 12, 12, 12, 12, 12};
static const u8 sDoorAnimPalettes_Lavender[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_Vermilion[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_PokemonFanClub[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_DeptStore[] = {3, 3, 3, 3, 3, 3, 3, 3};
static const u8 sDoorAnimPalettes_Fuchsia[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_SafariZoneFrlg[] = {9, 9, 9, 9, 9, 9, 9, 9};
static const u8 sDoorAnimPalettes_CinnabarLab[] = {3, 3, 3, 3, 3, 3, 3, 3};
static const u8 sDoorAnimPalettes_DeptStoreElevator[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_CableClubFrlg[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_HideoutElevator[] = {12, 12, 2, 2, 2, 2, 2, 2};
static const u8 sDoorAnimPalettes_SSAnne[] = {7, 7, 7, 7, 7, 7, 7, 7};
static const u8 sDoorAnimPalettes_SilphCoElevator[] = {8, 8, 2, 2, 2, 2, 2, 2};
static const u8 sDoorAnimPalettes_Sevii123[] = {5, 5, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_JoyfulGameCorner[] = {3, 3, 3, 3, 3, 3, 3, 3};
static const u8 sDoorAnimPalettes_OneIslandPokeCenter[] = {3, 3, 3, 3, 3, 3, 3, 3};
static const u8 sDoorAnimPalettes_Sevii45[] = {5, 5, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_FourIslandDayCare[] = {3, 3, 3, 3, 3, 3, 3, 3};
static const u8 sDoorAnimPalettes_RocketWarehouse[] = {10, 10, 10, 10, 10, 10, 10, 10};
static const u8 sDoorAnimPalettes_Sevii67[] = {5, 5, 5, 5, 5, 5, 5, 5};
static const u8 sDoorAnimPalettes_Teleporter[] = {8, 8, 8, 8, 8, 8, 8, 8};
static const u8 sDoorAnimPalettes_TrainerTowerLobbyElevator[] = {8, 8, 2, 2, 2, 2, 2, 2};
static const u8 sDoorAnimPalettes_TrainerTowerRoofElevator[] = {11, 11, 2, 2, 2, 2, 2, 2};

#endif // IS_FRLG

static const struct DoorGraphics sDoorAnimGraphicsTable[] =
{
#if !IS_FRLG
    {METATILE_General_Door,                                 &gTileset_General, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_General, sDoorAnimPalettes_General},
    {METATILE_General_Door_PokeCenter,                      &gTileset_General, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_PokeCenter, sDoorAnimPalettes_PokeCenter},
    {METATILE_General_Door_Gym,                             &gTileset_General, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_Gym, sDoorAnimPalettes_Gym},
    {METATILE_General_Door_PokeMart,                        &gTileset_General, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_PokeMart, sDoorAnimPalettes_PokeMart},
    {METATILE_Petalburg_Door_Littleroot,                    &gTileset_Petalburg, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Littleroot, sDoorAnimPalettes_Littleroot},
    {METATILE_Petalburg_Door_BirchsLab,                     &gTileset_Petalburg, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_BirchsLab, sDoorAnimPalettes_BirchsLab},
    {METATILE_Rustboro_Door_Tan,                            &gTileset_Rustboro, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_RustboroTan, sDoorAnimPalettes_RustboroTan},
    {METATILE_Rustboro_Door_Gray,                           &gTileset_Rustboro, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_RustboroGray, sDoorAnimPalettes_RustboroGray},
    {METATILE_Fallarbor_Door_LightRoof,                     &gTileset_Fallarbor, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_FallarborLightRoof, sDoorAnimPalettes_FallarborLightRoof},
    {METATILE_Petalburg_Door_Oldale,                        &gTileset_Petalburg, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Oldale, sDoorAnimPalettes_Oldale},
    {METATILE_Mauville_Door,                                &gTileset_Mauville, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Mauville, sDoorAnimPalettes_Mauville},
    {METATILE_Mauville_Door_Verdanturf,                     &gTileset_Mauville, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Verdanturf, sDoorAnimPalettes_Verdanturf},
    {METATILE_Slateport_Door,                               &gTileset_Slateport, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Slateport, sDoorAnimPalettes_Slateport},
    {METATILE_Dewford_Door,                                 &gTileset_Dewford, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Dewford, sDoorAnimPalettes_Dewford},
    {METATILE_General_Door_Contest,                         &gTileset_General, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_Contest, sDoorAnimPalettes_Contest},
    {METATILE_Lilycove_Door,                                &gTileset_Lilycove, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Lilycove, sDoorAnimPalettes_Lilycove},
    {METATILE_Lilycove_Door_Wooden,                         &gTileset_Lilycove, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_LilycoveWooden, sDoorAnimPalettes_LilycoveWooden},
    {METATILE_Mossdeep_Door,                                &gTileset_Mossdeep, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Mossdeep, sDoorAnimPalettes_Mossdeep},
    {METATILE_Sootopolis_Door_PeakedRoof,                   &gTileset_Sootopolis, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_SootopolisPeakedRoof, sDoorAnimPalettes_SootopolisPeakedRoof},
    {METATILE_Sootopolis_Door,                              &gTileset_Sootopolis, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Sootopolis, sDoorAnimPalettes_Sootopolis},
    {METATILE_EverGrande_Door_PokemonLeague,                &gTileset_EverGrande, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_PokemonLeague, sDoorAnimPalettes_PokemonLeague},
    {METATILE_Pacifidlog_Door,                              &gTileset_Pacifidlog, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Pacifidlog, sDoorAnimPalettes_Pacifidlog},
    {METATILE_PetalburgGym_Door,                            &gTileset_PetalburgGym, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_PetalburgGym, sDoorAnimPalettes_PetalburgGym},
    {METATILE_Mauville_Door_CyclingRoad,                    &gTileset_Mauville, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_CyclingRoad, sDoorAnimPalettes_CyclingRoad},
    {METATILE_Lilycove_Door_DeptStore,                      &gTileset_Lilycove, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_LilycoveDeptStore, sDoorAnimPalettes_LilycoveDeptStore},
    {METATILE_Lilycove_Door_SafariZone,                     &gTileset_Lilycove, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_SafariZone, sDoorAnimPalettes_SafariZone},
    {METATILE_Mossdeep_Door_SpaceCenter,                    &gTileset_Mossdeep, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_MossdeepSpaceCenter, sDoorAnimPalettes_MossdeepSpaceCenter},
    {METATILE_PokemonCenter_Door_CableClub,                 &gTileset_PokemonCenter, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_CableClub, sDoorAnimPalettes_CableClub},
    {METATILE_InsideShip_IntactDoor_Bottom_Unlocked,        &gTileset_InsideShip, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_AbandonedShip, sDoorAnimPalettes_AbandonedShip},
    {METATILE_Fallarbor_Door_DarkRoof,                      &gTileset_Fallarbor, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_FallarborDarkRoof, sDoorAnimPalettes_FallarborDarkRoof},
    {METATILE_InsideShip_IntactDoor_Bottom_Interior,        &gTileset_InsideShip, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_AbandonedShipRoom, sDoorAnimPalettes_AbandonedShipRoom},
    {METATILE_Shop_Door_Elevator,                           &gTileset_Shop, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_LilycoveDeptStoreElevator, sDoorAnimPalettes_LilycoveDeptStoreElevator},
    {METATILE_Dewford_Door_BattleTower,                     &gTileset_Dewford, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTowerOld, sDoorAnimPalettes_BattleTowerOld},
    {METATILE_BattleFrontier_Door_Elevator,                 &gTileset_BattleFrontier, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTowerElevator, sDoorAnimPalettes_BattleTowerElevator},
    // The metatile for this door doesn't seem to correspond to a door in any Emerald tileset. Given the surrounding door animations, it was likely cut from the Battle Frontier.
    // From the palettes array we know it uses palette 9, and the door's shadow looks correct using either the Battle Tent or Battle Frontier Outside's 9th palette.
    {0x3B0,                                                 NULL, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_UnusedBattleFrontier, sDoorAnimPalettes_UnusedBattleFrontier},
    {METATILE_BattleFrontierOutsideWest_Door_BattleDome,    &gTileset_BattleFrontierOutsideWest, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleDome, sDoorAnimPalettes_BattleDome},
    {METATILE_BattleFrontierOutsideWest_Door_BattleFactory, &gTileset_BattleFrontierOutsideWest, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleFactory, sDoorAnimPalettes_BattleFactory},
    {METATILE_BattleFrontierOutsideEast_Door_BattleTower,   &gTileset_BattleFrontierOutsideEast, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTower, sDoorAnimPalettes_BattleTower},
    {METATILE_BattleFrontierOutsideEast_Door_BattleArena,   &gTileset_BattleFrontierOutsideEast, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_BattleArena, sDoorAnimPalettes_BattleArena},
    {METATILE_BattleArena_Door,                             &gTileset_BattleArena, DOOR_SOUND_ARENA,   1, sDoorAnimTiles_BattleArenaLobby, sDoorAnimPalettes_BattleArenaLobby},
    {METATILE_BattleDome_Door_Lobby,                        &gTileset_BattleDome, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleDomeLobby, sDoorAnimPalettes_BattleDomeLobby},
    {METATILE_BattlePalace_Door,                            &gTileset_BattlePalace, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_BattlePalaceLobby, sDoorAnimPalettes_BattlePalaceLobby},
    {METATILE_Slateport_Door_BattleTent,                    &gTileset_Slateport, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTent, sDoorAnimPalettes_BattleTent},
    {METATILE_Mauville_Door_BattleTent,                     &gTileset_Mauville, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTent, sDoorAnimPalettes_BattleTent},
    {METATILE_Fallarbor_Door_BattleTent,                    &gTileset_Fallarbor, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTent, sDoorAnimPalettes_BattleTent},
    {METATILE_BattleDome_Door_Corridor,                     &gTileset_BattleDome, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleDomeCorridor, sDoorAnimPalettes_BattleDomeCorridor},
    {METATILE_BattleFrontier_Door_MultiCorridor,            &gTileset_BattleFrontier, DOOR_SOUND_SLIDING, 2, sDoorAnimTiles_BattleTowerMultiCorridor, sDoorAnimPalettes_BattleTowerMultiCorridor},
    {METATILE_BattleFrontierOutsideWest_Door,               &gTileset_BattleFrontierOutsideWest, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_BattleFrontier, sDoorAnimPalettes_BattleFrontier},
    {METATILE_BattleFrontierOutsideWest_Door_Sliding,       &gTileset_BattleFrontierOutsideWest, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleFrontierSliding, sDoorAnimPalettes_BattleFrontier},
    {METATILE_BattleDome_Door_PreBattleRoom,                &gTileset_BattleDome, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleDomePreBattleRoom, sDoorAnimPalettes_BattleDomePreBattleRoom},
    {METATILE_BattleTent_Door,                              &gTileset_BattleTent, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_BattleTentInterior, sDoorAnimPalettes_BattleTentInterior},
    {METATILE_TrainerHill_Door_Elevator_Lobby,              &gTileset_TrainerHill, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_TrainerHillLobbyElevator, sDoorAnimPalettes_TrainerHillLobbyElevator},
    {METATILE_TrainerHill_Door_Elevator_Roof,               &gTileset_TrainerHill, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_TrainerHillRoofElevator, sDoorAnimPalettes_TrainerHillRoofElevator},
#else
    {METATILE_GeneralFrlg_Door,                             &gTileset_General_Frlg, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_GeneralFrlg, sDoorAnimPalettes_GeneralFrlg},
    {METATILE_GeneralFrlg_SlidingSingleDoor,                &gTileset_General_Frlg, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_SlidingSingle, sDoorAnimPalettes_SlidingSingle},
    {METATILE_GeneralFrlg_SlidingDoubleDoor,                &gTileset_General_Frlg, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_SlidingDouble, sDoorAnimPalettes_SlidingDouble},
    {METATILE_PalletTown_Door,                              &gTileset_PalletTown, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Pallet, sDoorAnimPalettes_Pallet},
    {METATILE_PalletTown_OaksLabDoor,                       &gTileset_PalletTown, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_OaksLab, sDoorAnimPalettes_OaksLab},
    {METATILE_ViridianCity_Door,                            &gTileset_ViridianCity, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Viridian, sDoorAnimPalettes_Viridian},
    {METATILE_PewterCity_Door,                              &gTileset_PewterCity, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Pewter, sDoorAnimPalettes_Pewter},
    {METATILE_SaffronCity_Door,                             &gTileset_SaffronCity, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Saffron, sDoorAnimPalettes_Saffron},
    {METATILE_SaffronCity_SilphCoDoor,                      &gTileset_SaffronCity, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_SilphCo, sDoorAnimPalettes_SilphCo},
    {METATILE_CeruleanCity_Door,                            &gTileset_CeruleanCity, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Cerulean, sDoorAnimPalettes_Cerulean},
    {METATILE_LavenderTown_Door,                            &gTileset_LavenderTown, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Lavender, sDoorAnimPalettes_Lavender},
    {METATILE_VermilionCity_Door,                           &gTileset_VermilionCity, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Vermilion, sDoorAnimPalettes_Vermilion},
/*  Below was presumably intended for the door to the Pokemon Fan Club. The metatile is surrounded by metatiles for the fan club building.
    Its animation tiles are similar to the Vermilion door above, and the building on the map uses that metatile instead. The unused tiles
    have the pokeball above the door in view, but on the map the pokeball above the door is too high to be in view.
    The metatile below was subsequently re-used for the warp to enter the SS Anne from the harbor, which has no door. */
    {METATILE_VermilionCity_SSAnneWarp,                     &gTileset_VermilionCity, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_PokemonFanClub, sDoorAnimPalettes_PokemonFanClub},
    {METATILE_CeladonCity_DeptStoreDoor,                    &gTileset_CeladonCity, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_DeptStore, sDoorAnimPalettes_DeptStore},
    {METATILE_FuchsiaCity_Door,                             &gTileset_FuchsiaCity, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Fuchsia, sDoorAnimPalettes_Fuchsia},
    {METATILE_FuchsiaCity_SafariZoneDoor,                   &gTileset_FuchsiaCity, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_SafariZoneFrlg, sDoorAnimPalettes_SafariZoneFrlg},
    {METATILE_CinnabarIsland_LabDoor,                       &gTileset_CinnabarIsland, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_CinnabarLab, sDoorAnimPalettes_CinnabarLab},
    {METATILE_SeviiIslands123_Door,                         &gTileset_SeviiIslands123, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Sevii123, sDoorAnimPalettes_Sevii123},
    {METATILE_SeviiIslands123_GameCornerDoor,               &gTileset_SeviiIslands123, DOOR_SOUND_SLIDING, 1, sDoorAnimTiles_JoyfulGameCorner, sDoorAnimPalettes_JoyfulGameCorner},
    {METATILE_SeviiIslands123_PokeCenterDoor,               &gTileset_SeviiIslands123, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_OneIslandPokeCenter, sDoorAnimPalettes_OneIslandPokeCenter},
    {METATILE_SeviiIslands45_Door,                          &gTileset_SeviiIslands45, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Sevii45, sDoorAnimPalettes_Sevii45},
    {METATILE_SeviiIslands45_DayCareDoor,                   &gTileset_SeviiIslands45, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_FourIslandDayCare, sDoorAnimPalettes_FourIslandDayCare},
    {METATILE_SeviiIslands45_RocketWarehouseDoor_Unlocked,  &gTileset_SeviiIslands45, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_RocketWarehouse, sDoorAnimPalettes_RocketWarehouse},
    {METATILE_SeviiIslands67_Door,                          &gTileset_SeviiIslands67, DOOR_SOUND_NORMAL,  1, sDoorAnimTiles_Sevii67, sDoorAnimPalettes_Sevii67},
    {METATILE_DepartmentStore_ElevatorDoor,                 &gTileset_DepartmentStore, DOOR_SOUND_SLIDING, 2, sDoorAnimTiles_DeptStoreElevator, sDoorAnimPalettes_DeptStoreElevator},
    {METATILE_PokemonCenterFrlg_CableClubDoor,              &gTileset_PokemonCenterFrlg, DOOR_SOUND_SLIDING, 2, sDoorAnimTiles_CableClubFrlg, sDoorAnimPalettes_CableClubFrlg},
    {METATILE_SilphCo_HideoutElevatorDoor,                  &gTileset_SilphCo, DOOR_SOUND_SLIDING, 2, sDoorAnimTiles_HideoutElevator, sDoorAnimPalettes_HideoutElevator},
    {METATILE_SSAnne_Door,                                  &gTileset_SSAnne, DOOR_SOUND_NORMAL,  2, sDoorAnimTiles_SSAnne, sDoorAnimPalettes_SSAnne},
    {METATILE_SilphCo_ElevatorDoor,                         &gTileset_SilphCo, DOOR_SOUND_SLIDING, 2, sDoorAnimTiles_SilphCoElevator, sDoorAnimPalettes_SilphCoElevator},
    {METATILE_SeaCottage_Teleporter_Door,                   &gTileset_SeaCottage, DOOR_SOUND_SLIDING, 2, sDoorAnimTiles_Teleporter, sDoorAnimPalettes_Teleporter},
    {METATILE_TrainerTower_LobbyElevatorDoor,               &gTileset_TrainerTower, DOOR_SOUND_SLIDING, 2, sDoorAnimTiles_TrainerTowerLobbyElevator, sDoorAnimPalettes_TrainerTowerLobbyElevator},
    {METATILE_TrainerTower_RoofElevatorDoor,                &gTileset_TrainerTower, DOOR_SOUND_SLIDING, 2, sDoorAnimTiles_TrainerTowerRoofElevator, sDoorAnimPalettes_TrainerTowerRoofElevator},
#endif // !IS_FRLG
    {},
};

// NOTE: The tiles of a door's animation must be copied to VRAM because they are not already part of any given tileset.
//       This means that if there are any pre-existing tiles in this copied region that are visible when the door
//       animation is played they will be overwritten.
#define DOOR_TILE_START_SIZE1 (NUM_TILES_TOTAL - 8)
#define DOOR_TILE_START_SIZE2 (NUM_TILES_TOTAL - 16)

static void CopyDoorTilesToVram(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frame)
{
    if (gfx->size == 2 && !gMapHeader.mapLayout->isFrlg)
        CpuFastCopy(gfx->tiles + frame->offset, (void *)(VRAM + TILE_OFFSET_4BPP(DOOR_TILE_START_SIZE2)), 16 * TILE_SIZE_4BPP);
    else
        CpuFastCopy(gfx->tiles + frame->offset, (void *)(VRAM + TILE_OFFSET_4BPP(DOOR_TILE_START_SIZE1)), 8 * TILE_SIZE_4BPP);
}

static void BuildDoorTiles(u16 *tiles, u16 tileNum, const u8 *paletteNums)
{
    int i;
    u16 tile;

    // Only the first 4 tiles of each metatile (bottom layer) actually use the door tiles
    for (i = 0; i < 4; i++)
    {
        tile = *(paletteNums++) << 12;
        tiles[i] = tile | (tileNum + i);
    }

    // The remaining layers are left as tile 0 (with the same palette)
    for (; i < 8; i++)
    {
        tile = *(paletteNums++) << 12;
        tiles[i] = tile;
    }
}

static void DrawCurrentDoorAnimFrameFrlg(const struct DoorGraphics *gfx, int x, int y, const u8 *paletteNums)
{
    u16 tiles[8];
    if (gfx->size == 1)
        BuildDoorTiles(tiles, DOOR_TILE_START_SIZE1, paletteNums);

    else
    {
        BuildDoorTiles(tiles, DOOR_TILE_START_SIZE1, paletteNums);
        DrawDoorMetatileAt(x, y - 1, tiles);
        BuildDoorTiles(tiles, DOOR_TILE_START_SIZE1 + 4, &paletteNums[4]);
    }

    DrawDoorMetatileAt(x, y, tiles);
}

static void DrawCurrentDoorAnimFrame(const struct DoorGraphics *gfx, u32 x, u32 y, const u8 *paletteNums)
{
    if (gMapHeader.mapLayout->isFrlg)
    {
        DrawCurrentDoorAnimFrameFrlg(gfx, x, y, paletteNums);
        return;
    }

    u16 tiles[24];

    if (gfx->size == 2)
    {
        // Top left metatile
        BuildDoorTiles(&tiles[8], DOOR_TILE_START_SIZE2 + 0, &paletteNums[0]);
        DrawDoorMetatileAt(x, y - 1, &tiles[8]);

        // Bottom left metatile
        BuildDoorTiles(&tiles[8], DOOR_TILE_START_SIZE2 + 4, &paletteNums[4]);
        DrawDoorMetatileAt(x, y, &tiles[8]);

        // Top right metatile
        BuildDoorTiles(&tiles[8], DOOR_TILE_START_SIZE2 + 8, &paletteNums[0]);
        DrawDoorMetatileAt(x + 1, y - 1, &tiles[8]);

        // Bottom right metatile
        BuildDoorTiles(&tiles[8], DOOR_TILE_START_SIZE2 + 12, &paletteNums[4]);
        DrawDoorMetatileAt(x + 1, y, &tiles[8]);
    }
    else
    {
        // Top metatile
        BuildDoorTiles(&tiles[0], DOOR_TILE_START_SIZE1 + 0, &paletteNums[0]);
        DrawDoorMetatileAt(x, y - 1, &tiles[0]);

        // Bottom metatile
        BuildDoorTiles(&tiles[0], DOOR_TILE_START_SIZE1 + 4, &paletteNums[4]);
        DrawDoorMetatileAt(x, y, &tiles[0]);
    }
}

static void DrawClosedDoorTilesFrlg(const struct DoorGraphics *gfx, int x, int y)
{
    if (gfx->size == 1)
        CurrentMapDrawMetatileAt(x, y);
    else
    {
        CurrentMapDrawMetatileAt(x, y);
        CurrentMapDrawMetatileAt(x, y - 1);
    }
}

static void DrawClosedDoorTiles(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    if (gMapHeader.mapLayout->isFrlg)
    {
        DrawClosedDoorTilesFrlg(gfx, x, y);
        return;
    }

    CurrentMapDrawMetatileAt(x, y - 1);
    CurrentMapDrawMetatileAt(x, y);

    if (gfx->size == 2)
    {
        CurrentMapDrawMetatileAt(x + 1, y - 1);
        CurrentMapDrawMetatileAt(x + 1, y);
    }
}

static void DrawDoor(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frame, u32 x, u32 y)
{
    if (frame->offset == 0xFFFF)
    {
        DrawClosedDoorTiles(gfx, x, y);
        if (ShouldUseMultiCorridorDoor())
            DrawClosedDoorTiles(gfx, gSpecialVar_0x8004 + MAP_OFFSET, gSpecialVar_0x8005 + MAP_OFFSET);
    }
    else
    {
        CopyDoorTilesToVram(gfx, frame);
        DrawCurrentDoorAnimFrame(gfx, x, y, gfx->palettes);
        if (ShouldUseMultiCorridorDoor())
            DrawCurrentDoorAnimFrame(gfx, gSpecialVar_0x8004 + MAP_OFFSET, gSpecialVar_0x8005 + MAP_OFFSET, gfx->palettes);
    }
}

#define tFramesHi data[0]
#define tFramesLo data[1]
#define tGfxHi data[2]
#define tGfxLo data[3]
#define tFrameId data[4]
#define tCounter data[5]
#define tX data[6]
#define tY data[7]

// Draws a single frame of the door animation, or skips drawing to wait between frames.
// Returns FALSE when the final frame has been reached
static bool32 AnimateDoorFrame(struct DoorGraphics *gfx, struct DoorAnimFrame *frames, s16 *data)
{
    if (tCounter == 0)
        DrawDoor(gfx, &frames[tFrameId], tX, tY);

    if (tCounter == frames[tFrameId].time)
    {
        tCounter = 0;
        tFrameId++;
        if (frames[tFrameId].time == 0)
            return FALSE;
        else
            return TRUE;
    }
    tCounter++;
    return TRUE;
}

static void Task_AnimateDoor(u8 taskId)
{
    u16 *data = (u16*) gTasks[taskId].data;
    struct DoorAnimFrame *frames = (struct DoorAnimFrame *)(tFramesHi << 16 | tFramesLo);
    struct DoorGraphics *gfx = (struct DoorGraphics *)(tGfxHi << 16 | tGfxLo);

    if (AnimateDoorFrame(gfx, frames, gTasks[taskId].data) == FALSE)
        DestroyTask(taskId);
}

static const struct DoorAnimFrame *GetLastDoorFrame(const struct DoorAnimFrame *frame, const void *unused)
{
    while (frame->time != 0)
        frame++;
    return frame - 1;
}

static const struct DoorGraphics *GetDoorGraphics(const struct DoorGraphics *gfx, u16 metatileNum)
{
    while (gfx->tiles != NULL)
    {
        if (gfx->metatileNum == metatileNum && (gfx->tileset == gMapHeader.mapLayout->primaryTileset || gfx->tileset == gMapHeader.mapLayout->secondaryTileset))
            return gfx;
        gfx++;
    }
    return NULL;
}

static s8 StartDoorAnimationTask(const struct DoorGraphics *gfx, const struct DoorAnimFrame *frames, u32 x, u32 y)
{
    if (FuncIsActiveTask(Task_AnimateDoor) == TRUE)
    {
        return -1;
    }
    else
    {
        u8 taskId = CreateTask(Task_AnimateDoor, 0x50);
        s16 *data = gTasks[taskId].data;

        tX = x;
        tY = y;

        tFramesLo = (u32)frames;
        tFramesHi = (u32)frames >> 16;

        tGfxLo = (u32)gfx;
        tGfxHi = (u32)gfx >> 16;

        return taskId;
    }
}

static void DrawClosedDoor(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    DrawClosedDoorTiles(gfx, x, y);
}

static void DrawOpenedDoor(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    const struct DoorAnimFrame *doorAnimFrames = gMapHeader.mapLayout->isFrlg ? sDoorAnimFrames_OpenSmallFrlg : sDoorOpenAnimFrames;
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx != NULL)
        DrawDoor(gfx, GetLastDoorFrame(doorAnimFrames, doorAnimFrames), x, y);
}

static s8 StartDoorOpenAnimation(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
    {
        return -1;
    }
    else
    {
        if (gfx->size == 2)
            return StartDoorAnimationTask(gfx, gMapHeader.mapLayout->isFrlg ? sDoorAnimFrames_OpenLargeFrlg : sBigDoorOpenAnimFrames, x, y);
        else
            return StartDoorAnimationTask(gfx, gMapHeader.mapLayout->isFrlg ? sDoorAnimFrames_OpenSmallFrlg : sDoorOpenAnimFrames, x, y);
    }
}

static s8 StartDoorCloseAnimation(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
        return -1;
    else if (gfx->size != 1 && gMapHeader.mapLayout->isFrlg)
        return StartDoorAnimationTask(gfx, sDoorAnimFrames_CloseLargeFrlg, x, y);
    else
        return StartDoorAnimationTask(gfx, gMapHeader.mapLayout->isFrlg ? sDoorAnimFrames_CloseSmallFrlg : sDoorCloseAnimFrames, x, y);
}

static s8 GetDoorSoundType(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    gfx = GetDoorGraphics(gfx, MapGridGetMetatileIdAt(x, y));
    if (gfx == NULL)
        return -1;
    else
        return gfx->sound;
}

// Debug? Same as FieldAnimateDoorOpen but doesnt return or check if metatile is actually a door
static void UNUSED Debug_FieldAnimateDoorOpen(u32 x, u32 y)
{
    StartDoorOpenAnimation(sDoorAnimGraphicsTable, x, y);
}

void FieldSetDoorOpened(u32 x, u32 y)
{
    if (MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        DrawOpenedDoor(sDoorAnimGraphicsTable, x, y);
}

void FieldSetDoorClosed(u32 x, u32 y)
{
    if (MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        DrawClosedDoor(sDoorAnimGraphicsTable, x, y);
}

s8 FieldAnimateDoorClose(u32 x, u32 y)
{
    if (!MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        return -1;
    else
        return StartDoorCloseAnimation(sDoorAnimGraphicsTable, x, y);
}

s8 FieldAnimateDoorOpen(u32 x, u32 y)
{
    if (!MetatileBehavior_IsDoor(MapGridGetMetatileBehaviorAt(x, y)))
        return -1;
    else
        return StartDoorOpenAnimation(sDoorAnimGraphicsTable, x, y);
}

bool8 FieldIsDoorAnimationRunning(void)
{
    return FuncIsActiveTask(Task_AnimateDoor);
}

u32 GetDoorSoundEffect(u32 x, u32 y)
{
    int sound = GetDoorSoundType(sDoorAnimGraphicsTable, x, y);

    if (sound == DOOR_SOUND_NORMAL)
        return SE_DOOR;
    else if (sound == DOOR_SOUND_SLIDING)
        return SE_SLIDING_DOOR;
    else if (sound == DOOR_SOUND_ARENA)
        return SE_REPEL;
    else
        return SE_DOOR;
}

// Opens the Battle Tower multi partner's door in sync with the player's door
static bool8 ShouldUseMultiCorridorDoor(void)
{
    if (FlagGet(FLAG_ENABLE_MULTI_CORRIDOR_DOOR))
    {
        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR)
            && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_CORRIDOR))
        {
            return TRUE;
        }
    }
    return FALSE;
}
