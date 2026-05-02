#include "global.h"
#include "battle_pyramid.h"
#include "bg.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "map_name_popup.h"
#include "palette.h"
#include "region_map.h"
#include "rtc.h"
#include "start_menu.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "constants/battle_frontier.h"
#include "constants/layouts.h"
#include "constants/region_map_sections.h"
#include "constants/weather.h"
#include "config/general.h"
#include "config/overworld.h"

// enums
enum MapPopUp_Themes
{
    MAPPOPUP_THEME_WOOD,
    MAPPOPUP_THEME_MARBLE,
    MAPPOPUP_THEME_STONE,
    MAPPOPUP_THEME_BRICK,
    MAPPOPUP_THEME_UNDERWATER,
    MAPPOPUP_THEME_STONE2,
#if IS_HNS
    MAPPOPUP_THEME_CAVE_BROWN_HNS,
    MAPPOPUP_THEME_CAVE_GREY_HNS,
    MAPPOPUP_THEME_FALL_HNS,
    MAPPOPUP_THEME_WOODS_HNS,
    MAPPOPUP_THEME_CHERRY_HNS,
    MAPPOPUP_THEME_CITY_HNS,
    MAPPOPUP_THEME_CLIFF_HNS,
    MAPPOPUP_THEME_JOHTO_ROUTE_HNS,
    MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    MAPPOPUP_THEME_HISTORIC_HNS,
    MAPPOPUP_THEME_TOWN_HNS,
    MAPPOPUP_THEME_OCEAN_HNS,
#endif
};

enum MapPopUp_Themes_BW
{
    MAPPOPUP_THEME_BW_DEFAULT,
};

// static functions
static void Task_MapNamePopUpWindow(u8 taskId);
static void UpdateSecondaryPopUpWindow(u8 secondaryPopUpWindowId);
static void ShowMapNamePopUpWindow(void);
static void LoadMapNamePopUpWindowBg(void);

// EWRAM
EWRAM_DATA u8 gPopupTaskId = 0;

// .rodata
static const u8 sMapPopUp_Table[][960] =
{
    [MAPPOPUP_THEME_WOOD]       = INCBIN_U8("graphics/map_popup/wood.4bpp"),
    [MAPPOPUP_THEME_MARBLE]     = INCBIN_U8("graphics/map_popup/marble.4bpp"),
    [MAPPOPUP_THEME_STONE]      = INCBIN_U8("graphics/map_popup/stone.4bpp"),
    [MAPPOPUP_THEME_BRICK]      = INCBIN_U8("graphics/map_popup/brick.4bpp"),
    [MAPPOPUP_THEME_UNDERWATER] = INCBIN_U8("graphics/map_popup/underwater.4bpp"),
    [MAPPOPUP_THEME_STONE2]     = INCBIN_U8("graphics/map_popup/stone2.4bpp"),
#if IS_HNS
    [MAPPOPUP_THEME_CAVE_BROWN_HNS]  = INCBIN_U8("graphics/map_popup/cave_brown_hns.4bpp"),
    [MAPPOPUP_THEME_CAVE_GREY_HNS]   = INCBIN_U8("graphics/map_popup/cave_grey_hns.4bpp"),
    [MAPPOPUP_THEME_FALL_HNS]        = INCBIN_U8("graphics/map_popup/fall_hns.4bpp"),
    [MAPPOPUP_THEME_WOODS_HNS]       = INCBIN_U8("graphics/map_popup/woods_hns.4bpp"),
    [MAPPOPUP_THEME_CHERRY_HNS]      = INCBIN_U8("graphics/map_popup/cherry_hns.4bpp"),
    [MAPPOPUP_THEME_CITY_HNS]        = INCBIN_U8("graphics/map_popup/city_hns.4bpp"),
    [MAPPOPUP_THEME_CLIFF_HNS]       = INCBIN_U8("graphics/map_popup/cliff_hns.4bpp"),
    [MAPPOPUP_THEME_JOHTO_ROUTE_HNS] = INCBIN_U8("graphics/map_popup/johto_hns.4bpp"),
    [MAPPOPUP_THEME_KANTO_ROUTE_HNS] = INCBIN_U8("graphics/map_popup/kanto_hns.4bpp"),
    [MAPPOPUP_THEME_HISTORIC_HNS]    = INCBIN_U8("graphics/map_popup/historic_hns.4bpp"),
    [MAPPOPUP_THEME_TOWN_HNS]        = INCBIN_U8("graphics/map_popup/town_hns.4bpp"),
    [MAPPOPUP_THEME_OCEAN_HNS]       = INCBIN_U8("graphics/map_popup/ocean_hns.4bpp"),
#endif
};

static const u8 sMapPopUp_OutlineTable[][960] =
{
    [MAPPOPUP_THEME_WOOD]       = INCBIN_U8("graphics/map_popup/wood_outline.4bpp"),
    [MAPPOPUP_THEME_MARBLE]     = INCBIN_U8("graphics/map_popup/marble_outline.4bpp"),
    [MAPPOPUP_THEME_STONE]      = INCBIN_U8("graphics/map_popup/stone_outline.4bpp"),
    [MAPPOPUP_THEME_BRICK]      = INCBIN_U8("graphics/map_popup/brick_outline.4bpp"),
    [MAPPOPUP_THEME_UNDERWATER] = INCBIN_U8("graphics/map_popup/underwater_outline.4bpp"),
    [MAPPOPUP_THEME_STONE2]     = INCBIN_U8("graphics/map_popup/stone2_outline.4bpp"),
#if IS_HNS
    [MAPPOPUP_THEME_CAVE_BROWN_HNS]  = INCBIN_U8("graphics/map_popup/cave_brown_outline_hns.4bpp"),
    [MAPPOPUP_THEME_CAVE_GREY_HNS]   = INCBIN_U8("graphics/map_popup/cave_grey_outline_hns.4bpp"),
    [MAPPOPUP_THEME_FALL_HNS]        = INCBIN_U8("graphics/map_popup/fall_outline_hns.4bpp"),
    [MAPPOPUP_THEME_WOODS_HNS]       = INCBIN_U8("graphics/map_popup/woods_outline_hns.4bpp"),
    [MAPPOPUP_THEME_CHERRY_HNS]      = INCBIN_U8("graphics/map_popup/cherry_outline_hns.4bpp"),
    [MAPPOPUP_THEME_CITY_HNS]        = INCBIN_U8("graphics/map_popup/city_outline_hns.4bpp"),
    [MAPPOPUP_THEME_CLIFF_HNS]       = INCBIN_U8("graphics/map_popup/cliff_outline_hns.4bpp"),
    [MAPPOPUP_THEME_JOHTO_ROUTE_HNS] = INCBIN_U8("graphics/map_popup/johto_outline_hns.4bpp"),
    [MAPPOPUP_THEME_KANTO_ROUTE_HNS] = INCBIN_U8("graphics/map_popup/kanto_outline_hns.4bpp"),
    [MAPPOPUP_THEME_HISTORIC_HNS]    = INCBIN_U8("graphics/map_popup/historic_outline_hns.4bpp"),
    [MAPPOPUP_THEME_TOWN_HNS]        = INCBIN_U8("graphics/map_popup/town_outline_hns.4bpp"),
    [MAPPOPUP_THEME_OCEAN_HNS]       = INCBIN_U8("graphics/map_popup/ocean_outline_hns.4bpp"),
#endif
};

static const u16 sMapPopUp_PaletteTable[][16] =
{
    [MAPPOPUP_THEME_WOOD]       = INCBIN_U16("graphics/map_popup/wood.gbapal"),
    [MAPPOPUP_THEME_MARBLE]     = INCBIN_U16("graphics/map_popup/marble_outline.gbapal"),
    [MAPPOPUP_THEME_STONE]      = INCBIN_U16("graphics/map_popup/stone_outline.gbapal"),
    [MAPPOPUP_THEME_BRICK]      = INCBIN_U16("graphics/map_popup/brick_outline.gbapal"),
    [MAPPOPUP_THEME_UNDERWATER] = INCBIN_U16("graphics/map_popup/underwater_outline.gbapal"),
    [MAPPOPUP_THEME_STONE2]     = INCBIN_U16("graphics/map_popup/stone2_outline.gbapal"),
#if IS_HNS
    [MAPPOPUP_THEME_CAVE_BROWN_HNS]  = INCBIN_U16("graphics/map_popup/cave_brown_outline_hns.gbapal"),
    [MAPPOPUP_THEME_CAVE_GREY_HNS]   = INCBIN_U16("graphics/map_popup/cave_grey_outline_hns.gbapal"),
    [MAPPOPUP_THEME_FALL_HNS]        = INCBIN_U16("graphics/map_popup/fall_outline_hns.gbapal"),
    [MAPPOPUP_THEME_WOODS_HNS]       = INCBIN_U16("graphics/map_popup/woods_hns.gbapal"),
    [MAPPOPUP_THEME_CHERRY_HNS]      = INCBIN_U16("graphics/map_popup/cherry_outline_hns.gbapal"),
    [MAPPOPUP_THEME_CITY_HNS]        = INCBIN_U16("graphics/map_popup/city_outline_hns.gbapal"),
    [MAPPOPUP_THEME_CLIFF_HNS]       = INCBIN_U16("graphics/map_popup/cliff_outline_hns.gbapal"),
    [MAPPOPUP_THEME_JOHTO_ROUTE_HNS] = INCBIN_U16("graphics/map_popup/johto_outline_hns.gbapal"),
    [MAPPOPUP_THEME_KANTO_ROUTE_HNS] = INCBIN_U16("graphics/map_popup/kanto_outline_hns.gbapal"),
    [MAPPOPUP_THEME_HISTORIC_HNS]    = INCBIN_U16("graphics/map_popup/historic_outline_hns.gbapal"),
    [MAPPOPUP_THEME_TOWN_HNS]        = INCBIN_U16("graphics/map_popup/town_outline_hns.gbapal"),
    [MAPPOPUP_THEME_OCEAN_HNS]       = INCBIN_U16("graphics/map_popup/ocean_outline_hns.gbapal"),
#endif
};

static const u16 sMapPopUp_Palette_Underwater[16] = INCBIN_U16("graphics/map_popup/underwater.gbapal");

// -1 in the size excludes MAPSEC_NONE.
// The MAPSEC values for Kanto (between MAPSEC_DYNAMIC and MAPSEC_AQUA_HIDEOUT) are also excluded,
// and this is then handled by subtracting KANTO_MAPSEC_COUNT here and in LoadMapNamePopUpWindowBg.
#if IS_HNS
static const u8 sMapSectionToThemeId[MAPSEC_COUNT - 1] =
{
    // Shared / non-regional
    [MAPSEC_ABANDONED_SHIP] = MAPPOPUP_THEME_WOODS_HNS,
    [MAPSEC_BATTLE_FRONTIER] = MAPPOPUP_THEME_CITY_HNS,
    [MAPSEC_BIRTH_ISLAND] = MAPPOPUP_THEME_OCEAN_HNS,
    [MAPSEC_FARAWAY_ISLAND] = MAPPOPUP_THEME_OCEAN_HNS,
    [MAPSEC_LILYCOVE_CITY] = MAPPOPUP_THEME_CHERRY_HNS,
    [MAPSEC_SAFARI_ZONE] = MAPPOPUP_THEME_JOHTO_ROUTE_HNS,
    [MAPSEC_SOUTHERN_ISLAND] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_TRAINER_HILL] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_VICTORY_ROAD] = MAPPOPUP_THEME_CAVE_BROWN_HNS,
    // Kanto
    [MAPSEC_PALLET_TOWN] = MAPPOPUP_THEME_TOWN_HNS,
    [MAPSEC_VIRIDIAN_CITY] = MAPPOPUP_THEME_CITY_HNS,
    [MAPSEC_PEWTER_CITY] = MAPPOPUP_THEME_CITY_HNS,
    [MAPSEC_CERULEAN_CITY] = MAPPOPUP_THEME_CITY_HNS,
    [MAPSEC_LAVENDER_TOWN] = MAPPOPUP_THEME_HISTORIC_HNS,
    [MAPSEC_VERMILION_CITY] = MAPPOPUP_THEME_CITY_HNS,
    [MAPSEC_CELADON_CITY] = MAPPOPUP_THEME_CITY_HNS,
    [MAPSEC_FUCHSIA_CITY] = MAPPOPUP_THEME_CITY_HNS,
    [MAPSEC_CINNABAR_ISLAND] = MAPPOPUP_THEME_OCEAN_HNS,
    [MAPSEC_INDIGO_PLATEAU] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_SAFFRON_CITY] = MAPPOPUP_THEME_CITY_HNS,
    [MAPSEC_ROUTE_1] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_2] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_3] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_4] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_5] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_6] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_7] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_8] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_9] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_10] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_11] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_12] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_13] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_14] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_15] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_16] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_17] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_18] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_19] = MAPPOPUP_THEME_OCEAN_HNS,
    [MAPSEC_ROUTE_20] = MAPPOPUP_THEME_OCEAN_HNS,
    [MAPSEC_ROUTE_21] = MAPPOPUP_THEME_OCEAN_HNS,
    [MAPSEC_ROUTE_22] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_24] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_25] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_VIRIDIAN_FOREST] = MAPPOPUP_THEME_WOODS_HNS,
    [MAPSEC_MT_MOON] = MAPPOPUP_THEME_CAVE_BROWN_HNS,
    [MAPSEC_DIGLETTS_CAVE] = MAPPOPUP_THEME_CAVE_BROWN_HNS,
    [MAPSEC_ROCKET_HIDEOUT] = MAPPOPUP_THEME_CAVE_BROWN_HNS,
    [MAPSEC_ROCK_TUNNEL] = MAPPOPUP_THEME_CAVE_BROWN_HNS,
    [MAPSEC_SEAFOAM_ISLANDS] = MAPPOPUP_THEME_OCEAN_HNS,
    [MAPSEC_CERULEAN_CAVE] = MAPPOPUP_THEME_CAVE_BROWN_HNS,
    [MAPSEC_POWER_PLANT] = MAPPOPUP_THEME_CITY_HNS,
    // Johto
    [MAPSEC_NEW_BARK_TOWN] = MAPPOPUP_THEME_TOWN_HNS,
    [MAPSEC_CHERRYGROVE_CITY] = MAPPOPUP_THEME_CHERRY_HNS,
    [MAPSEC_VIOLET_CITY] = MAPPOPUP_THEME_HISTORIC_HNS,
    [MAPSEC_AZALEA_TOWN] = MAPPOPUP_THEME_TOWN_HNS,
    [MAPSEC_GOLDENROD_CITY] = MAPPOPUP_THEME_CITY_HNS,
    [MAPSEC_ECRUTEAK_CITY] = MAPPOPUP_THEME_HISTORIC_HNS,
    [MAPSEC_OLIVINE_CITY] = MAPPOPUP_THEME_CITY_HNS,
    [MAPSEC_CIANWOOD_CITY] = MAPPOPUP_THEME_TOWN_HNS,
    [MAPSEC_MAHOGANY_TOWN] = MAPPOPUP_THEME_TOWN_HNS,
    [MAPSEC_BLACKTHORN_CITY] = MAPPOPUP_THEME_HISTORIC_HNS,
    [MAPSEC_ROUTE_26] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_27] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_28] = MAPPOPUP_THEME_KANTO_ROUTE_HNS,
    [MAPSEC_ROUTE_29] = MAPPOPUP_THEME_JOHTO_ROUTE_HNS,
    [MAPSEC_ROUTE_30] = MAPPOPUP_THEME_CHERRY_HNS,
    [MAPSEC_ROUTE_31] = MAPPOPUP_THEME_CHERRY_HNS,
    [MAPSEC_ROUTE_32] = MAPPOPUP_THEME_CLIFF_HNS,
    [MAPSEC_ROUTE_33] = MAPPOPUP_THEME_CLIFF_HNS,
    [MAPSEC_ROUTE_34] = MAPPOPUP_THEME_JOHTO_ROUTE_HNS,
    [MAPSEC_ROUTE_35] = MAPPOPUP_THEME_JOHTO_ROUTE_HNS,
    [MAPSEC_ROUTE_36] = MAPPOPUP_THEME_JOHTO_ROUTE_HNS,
    [MAPSEC_ROUTE_37] = MAPPOPUP_THEME_FALL_HNS,
    [MAPSEC_ROUTE_38] = MAPPOPUP_THEME_FALL_HNS,
    [MAPSEC_ROUTE_39] = MAPPOPUP_THEME_FALL_HNS,
    [MAPSEC_ROUTE_40] = MAPPOPUP_THEME_OCEAN_HNS,
    [MAPSEC_ROUTE_41] = MAPPOPUP_THEME_OCEAN_HNS,
    [MAPSEC_ROUTE_42] = MAPPOPUP_THEME_JOHTO_ROUTE_HNS,
    [MAPSEC_ROUTE_43] = MAPPOPUP_THEME_CLIFF_HNS,
    [MAPSEC_ROUTE_44] = MAPPOPUP_THEME_JOHTO_ROUTE_HNS,
    [MAPSEC_ROUTE_45] = MAPPOPUP_THEME_CLIFF_HNS,
    [MAPSEC_ROUTE_46] = MAPPOPUP_THEME_JOHTO_ROUTE_HNS,
    [MAPSEC_ROUTE_47] = MAPPOPUP_THEME_CLIFF_HNS,
    [MAPSEC_ROUTE_48] = MAPPOPUP_THEME_CLIFF_HNS,
    [MAPSEC_BURNED_TOWER] = MAPPOPUP_THEME_HISTORIC_HNS,
    [MAPSEC_CLIFF_CAVE] = MAPPOPUP_THEME_CAVE_BROWN_HNS,
    [MAPSEC_DARK_CAVE] = MAPPOPUP_THEME_CAVE_GREY_HNS,
    [MAPSEC_DRAGONS_DEN] = MAPPOPUP_THEME_HISTORIC_HNS,
    [MAPSEC_EMBEDDED_TOWER] = MAPPOPUP_THEME_HISTORIC_HNS,
    [MAPSEC_ICE_PATH] = MAPPOPUP_THEME_CAVE_GREY_HNS,
    [MAPSEC_ILEX_FOREST] = MAPPOPUP_THEME_WOODS_HNS,
    [MAPSEC_LAKE_OF_RAGE] = MAPPOPUP_THEME_CLIFF_HNS,
    [MAPSEC_MT_MORTAR] = MAPPOPUP_THEME_CAVE_GREY_HNS,
    [MAPSEC_MT_SILVER] = MAPPOPUP_THEME_CAVE_BROWN_HNS,
    [MAPSEC_NATIONAL_PARK] = MAPPOPUP_THEME_JOHTO_ROUTE_HNS,
    [MAPSEC_OLIVINE_LIGHTHOUSE] = MAPPOPUP_THEME_CITY_HNS,
    [MAPSEC_RUINS_OF_ALPH] = MAPPOPUP_THEME_CLIFF_HNS,
    [MAPSEC_SAFARI_ZONE_GATE] = MAPPOPUP_THEME_CLIFF_HNS,
    [MAPSEC_SLOWPOKE_WELL] = MAPPOPUP_THEME_CAVE_GREY_HNS,
    [MAPSEC_SPROUT_TOWER] = MAPPOPUP_THEME_HISTORIC_HNS,
    [MAPSEC_SS_AQUA] = MAPPOPUP_THEME_OCEAN_HNS,
    [MAPSEC_TIN_TOWER] = MAPPOPUP_THEME_HISTORIC_HNS,
    [MAPSEC_TOHJO_FALLS] = MAPPOPUP_THEME_CAVE_BROWN_HNS,
    [MAPSEC_UNION_CAVE] = MAPPOPUP_THEME_CAVE_GREY_HNS,
    [MAPSEC_WHIRL_ISLANDS] = MAPPOPUP_THEME_CAVE_GREY_HNS,
};
#else
static const u8 sMapSectionToThemeId[MAPSEC_COUNT - KANTO_MAPSEC_COUNT - 1] =
{
    [MAPSEC_LITTLEROOT_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_OLDALE_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_DEWFORD_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_LAVARIDGE_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_FALLARBOR_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_VERDANTURF_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_PACIFIDLOG_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_PETALBURG_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_SLATEPORT_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_MAUVILLE_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_RUSTBORO_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_FORTREE_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_LILYCOVE_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_MOSSDEEP_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_SOOTOPOLIS_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_EVER_GRANDE_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_ROUTE_101] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_102] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_103] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_104] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_105] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_106] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_107] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_108] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_109] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_110] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_111] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_112] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_113] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_114] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_115] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_116] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_117] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_118] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_119] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_120] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_121] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_122] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_123] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_124] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_125] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_126] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_127] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_128] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_129] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_130] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_131] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_132] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_133] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_134] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_UNDERWATER_124] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_126] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_127] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_128] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_SOOTOPOLIS] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_GRANITE_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MT_CHIMNEY] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SAFARI_ZONE] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_BATTLE_FRONTIER] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_PETALBURG_WOODS] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_RUSTURF_TUNNEL] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ABANDONED_SHIP] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_NEW_MAUVILLE] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_METEOR_FALLS] = MAPPOPUP_THEME_STONE,
    [MAPSEC_METEOR_FALLS2] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MT_PYRE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_AQUA_HIDEOUT_OLD] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SHOAL_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SEAFLOOR_CAVERN] = MAPPOPUP_THEME_STONE,
    [MAPSEC_UNDERWATER_SEAFLOOR_CAVERN] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_VICTORY_ROAD] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MIRAGE_ISLAND] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_CAVE_OF_ORIGIN] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SOUTHERN_ISLAND] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_FIERY_PATH] = MAPPOPUP_THEME_STONE,
    [MAPSEC_FIERY_PATH2] = MAPPOPUP_THEME_STONE,
    [MAPSEC_JAGGED_PASS] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_JAGGED_PASS2] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_SEALED_CHAMBER] = MAPPOPUP_THEME_STONE,
    [MAPSEC_UNDERWATER_SEALED_CHAMBER] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_SCORCHED_SLAB] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ISLAND_CAVE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_DESERT_RUINS] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ANCIENT_TOMB] = MAPPOPUP_THEME_STONE,
    [MAPSEC_INSIDE_OF_TRUCK] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_SKY_PILLAR] = MAPPOPUP_THEME_STONE,
    [MAPSEC_SECRET_BASE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_DYNAMIC] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_AQUA_HIDEOUT - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MAGMA_HIDEOUT - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MIRAGE_TOWER - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_BIRTH_ISLAND - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_FARAWAY_ISLAND - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ARTISAN_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MARINE_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_UNDERWATER_MARINE_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_TERRA_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_UNDERWATER_105 - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_125 - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_UNDERWATER_129 - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_DESERT_UNDERPASS - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ALTERING_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_NAVEL_ROCK - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,
    [MAPSEC_TRAINER_HILL - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_MARBLE,
};
#endif // !IS_HNS

#if OW_POPUP_GENERATION == GEN_5
// Gen5 assets
static const u8 sMapPopUpTilesPrimary_BW[] = INCBIN_U8("graphics/map_popup/bw/bw_primary.4bpp");
static const u8 sMapPopUpTilesSecondary_BW[] = INCBIN_U8("graphics/map_popup/bw/bw_secondary.4bpp");
static const u16 sMapPopUpTilesPalette_BW_Black[16] = INCBIN_U16("graphics/map_popup/bw/black.gbapal");
static const u16 sMapPopUpTilesPalette_BW_White[16] = INCBIN_U16("graphics/map_popup/bw/white.gbapal");
#else
static const u8 sMapPopUpTilesPrimary_BW[] = {0};
static const u8 sMapPopUpTilesSecondary_BW[] = {0};
static const u16 sMapPopUpTilesPalette_BW_Black[] = {0};
static const u16 sMapPopUpTilesPalette_BW_White[] = {0};
#endif

static const u8 sRegionMapSectionId_To_PopUpThemeIdMapping_BW[] =
{
#if IS_HNS
    [0] = MAPPOPUP_THEME_BW_DEFAULT,
#else
    [MAPSEC_LITTLEROOT_TOWN] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_OLDALE_TOWN] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_DEWFORD_TOWN] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_LAVARIDGE_TOWN] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_FALLARBOR_TOWN] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_VERDANTURF_TOWN] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_PACIFIDLOG_TOWN] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_PETALBURG_CITY] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SLATEPORT_CITY] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_MAUVILLE_CITY] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_RUSTBORO_CITY] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_FORTREE_CITY] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_LILYCOVE_CITY] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_MOSSDEEP_CITY] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SOOTOPOLIS_CITY] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_EVER_GRANDE_CITY] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_101] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_102] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_103] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_104] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_105] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_106] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_107] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_108] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_109] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_110] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_111] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_112] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_113] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_114] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_115] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_116] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_117] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_118] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_119] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_120] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_121] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_122] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_123] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_124] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_125] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_126] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_127] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_128] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_129] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_130] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_131] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_132] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_133] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ROUTE_134] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_UNDERWATER_124] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_UNDERWATER_126] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_UNDERWATER_127] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_UNDERWATER_128] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_UNDERWATER_SOOTOPOLIS] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_GRANITE_CAVE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_MT_CHIMNEY] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SAFARI_ZONE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_BATTLE_FRONTIER] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_PETALBURG_WOODS] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_RUSTURF_TUNNEL] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ABANDONED_SHIP] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_NEW_MAUVILLE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_METEOR_FALLS] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_METEOR_FALLS2] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_MT_PYRE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_AQUA_HIDEOUT_OLD] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SHOAL_CAVE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SEAFLOOR_CAVERN] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_UNDERWATER_SEAFLOOR_CAVERN] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_VICTORY_ROAD] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_MIRAGE_ISLAND] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_CAVE_OF_ORIGIN] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SOUTHERN_ISLAND] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_FIERY_PATH] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_FIERY_PATH2] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_JAGGED_PASS] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_JAGGED_PASS2] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SEALED_CHAMBER] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_UNDERWATER_SEALED_CHAMBER] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SCORCHED_SLAB] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ISLAND_CAVE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_DESERT_RUINS] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ANCIENT_TOMB] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_INSIDE_OF_TRUCK] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SKY_PILLAR] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SECRET_BASE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_DYNAMIC] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_AQUA_HIDEOUT - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_MAGMA_HIDEOUT - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_MIRAGE_TOWER - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_BIRTH_ISLAND - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_FARAWAY_ISLAND - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ARTISAN_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_MARINE_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_UNDERWATER_MARINE_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_TERRA_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_UNDERWATER_105 - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_UNDERWATER_125 - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_UNDERWATER_129 - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_DESERT_UNDERPASS - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ALTERING_CAVE - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_NAVEL_ROCK - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_TRAINER_HILL - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,
#endif
};

static const u8 sText_PyramidFloor1[] = _("PYRAMID FLOOR 1");
static const u8 sText_PyramidFloor2[] = _("PYRAMID FLOOR 2");
static const u8 sText_PyramidFloor3[] = _("PYRAMID FLOOR 3");
static const u8 sText_PyramidFloor4[] = _("PYRAMID FLOOR 4");
static const u8 sText_PyramidFloor5[] = _("PYRAMID FLOOR 5");
static const u8 sText_PyramidFloor6[] = _("PYRAMID FLOOR 6");
static const u8 sText_PyramidFloor7[] = _("PYRAMID FLOOR 7");
static const u8 sText_Pyramid[] = _("PYRAMID");

static const u8 *const sBattlePyramid_MapHeaderStrings[FRONTIER_STAGES_PER_CHALLENGE + 1] =
{
    sText_PyramidFloor1,
    sText_PyramidFloor2,
    sText_PyramidFloor3,
    sText_PyramidFloor4,
    sText_PyramidFloor5,
    sText_PyramidFloor6,
    sText_PyramidFloor7,
    sText_Pyramid,
};

static bool8 UNUSED StartMenu_ShowMapNamePopup(void)
{
    HideStartMenu();
    ShowMapNamePopup();
    return TRUE;
}

// States and data defines for Task_MapNamePopUpWindow
enum {
    STATE_SLIDE_IN,
    STATE_WAIT,
    STATE_SLIDE_OUT,
    STATE_UNUSED,
    STATE_ERASE,
    STATE_END,
    STATE_PRINT, // For some reason the first state is numerically last.
};

#define POPUP_OFFSCREEN_Y  ((OW_POPUP_GENERATION == GEN_5) ? 24 : 40)
#define POPUP_SLIDE_SPEED  2

#define tState         data[0]
#define tOnscreenTimer data[1]
#define tYOffset       data[2]
#define tIncomingPopUp data[3]
#define tPrintTimer    data[4]

void ShowMapNamePopup(void)
{
    if (FlagGet(FLAG_HIDE_MAP_NAME_POPUP) != TRUE)
    {
        if (!FuncIsActiveTask(Task_MapNamePopUpWindow))
        {
            // New pop up window
            if (OW_POPUP_GENERATION == GEN_5)
            {
                gPopupTaskId = CreateTask(Task_MapNamePopUpWindow, 100);

                if (OW_POPUP_BW_ALPHA_BLEND && !IsWeatherAlphaBlend())
                    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
            }
            else
            {
                gPopupTaskId = CreateTask(Task_MapNamePopUpWindow, 90);
                SetGpuReg(REG_OFFSET_BG0VOFS, POPUP_OFFSCREEN_Y);
            }

            gTasks[gPopupTaskId].tState = STATE_PRINT;
            gTasks[gPopupTaskId].tYOffset = POPUP_OFFSCREEN_Y;
        }
        else
        {
            // There's already a pop up window running.
            // Hurry the old pop up offscreen so the new one can appear.
            if (gTasks[gPopupTaskId].tState != STATE_SLIDE_OUT)
                gTasks[gPopupTaskId].tState = STATE_SLIDE_OUT;
            gTasks[gPopupTaskId].tIncomingPopUp = TRUE;
        }
    }
}

static void Task_MapNamePopUpWindow(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case STATE_PRINT:
        // Wait, then create and print the pop up window
        if (++task->tPrintTimer > 30)
        {
            task->tState = STATE_SLIDE_IN;
            task->tPrintTimer = 0;
            ShowMapNamePopUpWindow();
            if (OW_POPUP_GENERATION == GEN_5)
            {
                EnableInterrupts(INTR_FLAG_HBLANK);
                SetHBlankCallback(HBlankCB_DoublePopupWindow);
            }
        }
        break;
    case STATE_SLIDE_IN:
        // Slide the window onscreen.
        task->tYOffset -= POPUP_SLIDE_SPEED;
        if (task->tYOffset <= 0 )
        {
            task->tYOffset = 0;
            task->tState = STATE_WAIT;
            gTasks[gPopupTaskId].tOnscreenTimer = 0;
        }
        break;
    case STATE_WAIT:
        // Wait while the window is fully onscreen.
        if (++task->tOnscreenTimer > 120)
        {
            task->tOnscreenTimer = 0;
            task->tState = STATE_SLIDE_OUT;
        }
        break;
    case STATE_SLIDE_OUT:
        // Slide the window offscreen.
        task->tYOffset += POPUP_SLIDE_SPEED;
        if (task->tYOffset >= POPUP_OFFSCREEN_Y)
        {
            task->tYOffset = POPUP_OFFSCREEN_Y;
            if (task->tIncomingPopUp)
            {
                // A new pop up window is incoming,
                // return to the first state to show it.
                task->tState = STATE_PRINT;
                task->tPrintTimer = 0;
                task->tIncomingPopUp = FALSE;
            }
            else
            {
                task->tState = STATE_ERASE;
                return;
            }
        }
        break;
    case STATE_ERASE:
        ClearStdWindowAndFrame(GetMapNamePopUpWindowId(), TRUE);
        if (OW_POPUP_GENERATION == GEN_5)
            ClearStdWindowAndFrame(GetSecondaryPopUpWindowId(), TRUE);
        task->tState = STATE_END;
        break;
    case STATE_END:
        HideMapNamePopUpWindow();
        return;
    }
    if (OW_POPUP_GENERATION != GEN_5)
        SetGpuReg(REG_OFFSET_BG0VOFS, task->tYOffset);
}

void HideMapNamePopUpWindow(void)
{
    if (FuncIsActiveTask(Task_MapNamePopUpWindow))
    {
    #ifdef UBFIX
        if (GetMapNamePopUpWindowId() != WINDOW_NONE)
    #endif // UBFIX
        {
            ClearStdWindowAndFrame(GetMapNamePopUpWindowId(), TRUE);
            RemoveMapNamePopUpWindow();
        }

        if (OW_POPUP_GENERATION == GEN_5)
        {
            if (GetSecondaryPopUpWindowId() != WINDOW_NONE)
            {
                ClearStdWindowAndFrame(GetSecondaryPopUpWindowId(), TRUE);
                RemoveSecondaryPopUpWindow();
            }

            DisableInterrupts(INTR_FLAG_HBLANK);
            SetHBlankCallback(NULL);

            if (OW_POPUP_BW_ALPHA_BLEND && !IsWeatherAlphaBlend())
            {
                SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ);
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_EFFECT_BLEND);
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 10));
            }
        }

        SetGpuReg_ForcedBlank(REG_OFFSET_BG0VOFS, 0);
        DestroyTask(gPopupTaskId);
    }
}

static void UpdateSecondaryPopUpWindow(u8 secondaryPopUpWindowId)
{
    u8 mapDisplayHeader[24];
    u8 *withoutPrefixPtr = &(mapDisplayHeader[0]);

    if (OW_POPUP_BW_TIME_MODE != OW_POPUP_BW_TIME_NONE)
    {
        RtcCalcLocalTime();
        FormatDecimalTimeWithoutSeconds(withoutPrefixPtr, gLocalTime.hours, gLocalTime.minutes, OW_POPUP_BW_TIME_MODE == OW_POPUP_BW_TIME_24_HR);
        AddTextPrinterParameterized(secondaryPopUpWindowId, FONT_SMALL, mapDisplayHeader, GetStringRightAlignXOffset(FONT_SMALL, mapDisplayHeader, DISPLAY_WIDTH) - 5, 8, TEXT_SKIP_DRAW, NULL);
    }
    CopyWindowToVram(secondaryPopUpWindowId, COPYWIN_FULL);
}

static void ShowMapNamePopUpWindow(void)
{
    u8 mapDisplayHeader[27];
    u8 *withoutPrefixPtr;
    u8 x;
    const u8 *mapDisplayHeaderSource;
    u8 mapNamePopUpWindowId, secondaryPopUpWindowId;

    if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP)
        {
            withoutPrefixPtr = &(mapDisplayHeader[6]);
            mapDisplayHeaderSource = sBattlePyramid_MapHeaderStrings[FRONTIER_STAGES_PER_CHALLENGE];
        }
        else
        {
            withoutPrefixPtr = &(mapDisplayHeader[6]);
            mapDisplayHeaderSource = sBattlePyramid_MapHeaderStrings[gSaveBlock2Ptr->frontier.curChallengeBattleNum];
        }
        StringCopy(withoutPrefixPtr, mapDisplayHeaderSource);
    }
    else
    {
        withoutPrefixPtr = &(mapDisplayHeader[6]);
        GetMapName(withoutPrefixPtr, gMapHeader.regionMapSectionId, 0);
    }

    if (OW_POPUP_GENERATION == GEN_5)
    {
        if (OW_POPUP_BW_ALPHA_BLEND && !IsWeatherAlphaBlend())
            SetGpuRegBits(REG_OFFSET_WININ, WININ_WIN0_CLR);

        mapNamePopUpWindowId = AddMapNamePopUpWindow();
        secondaryPopUpWindowId = AddSecondaryPopUpWindow();
    }
    else
    {
        AddMapNamePopUpWindow();
    }

    LoadMapNamePopUpWindowBg();

    mapDisplayHeader[0] = EXT_CTRL_CODE_BEGIN;
    mapDisplayHeader[1] = EXT_CTRL_CODE_BACKGROUND;
    mapDisplayHeader[2] = TEXT_COLOR_TRANSPARENT;
    mapDisplayHeader[3] = EXT_CTRL_CODE_BEGIN;
    mapDisplayHeader[4] = EXT_CTRL_CODE_ACCENT;
    mapDisplayHeader[5] = TEXT_COLOR_TRANSPARENT;

    if (OW_POPUP_GENERATION == GEN_5)
    {
        AddTextPrinterParameterized(mapNamePopUpWindowId, FONT_SHORT, mapDisplayHeader, 8, 2, TEXT_SKIP_DRAW, NULL);
        CopyWindowToVram(mapNamePopUpWindowId, COPYWIN_FULL);
        UpdateSecondaryPopUpWindow(secondaryPopUpWindowId);
    }
    else
    {
        x = GetStringCenterAlignXOffset(FONT_NARROW, withoutPrefixPtr, 80);
        AddTextPrinterParameterized(GetMapNamePopUpWindowId(), FONT_NARROW, mapDisplayHeader, x, 3, TEXT_SKIP_DRAW, NULL);
        CopyWindowToVram(GetMapNamePopUpWindowId(), COPYWIN_FULL);
    }
}

#define TILE_TOP_EDGE_START 0x21D
#define TILE_TOP_EDGE_END   0x228
#define TILE_LEFT_EDGE_TOP  0x229
#define TILE_RIGHT_EDGE_TOP 0x22A
#define TILE_LEFT_EDGE_MID  0x22B
#define TILE_RIGHT_EDGE_MID 0x22C
#define TILE_LEFT_EDGE_BOT  0x22D
#define TILE_RIGHT_EDGE_BOT 0x22E
#define TILE_BOT_EDGE_START 0x22F
#define TILE_BOT_EDGE_END   0x23A

static void DrawMapNamePopUpFrame(u8 bg, u8 x, u8 y, u8 deltaX, u8 deltaY, u8 unused)
{
    s32 i;

    // Draw top edge
    for (i = 0; i < 1 + TILE_TOP_EDGE_END - TILE_TOP_EDGE_START; i++)
        FillBgTilemapBufferRect(bg, TILE_TOP_EDGE_START + i, i - 1 + x, y - 1, 1, 1, 14);

    // Draw sides
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_TOP,       x - 1,     y, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_TOP, deltaX + x,     y, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_MID,       x - 1, y + 1, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_MID, deltaX + x, y + 1, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_BOT,       x - 1, y + 2, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_BOT, deltaX + x, y + 2, 1, 1, 14);

    // Draw bottom edge
    for (i = 0; i < 1 + TILE_BOT_EDGE_END - TILE_BOT_EDGE_START; i++)
        FillBgTilemapBufferRect(bg, TILE_BOT_EDGE_START + i, i - 1 + x, y + deltaY, 1, 1, 14);
}

static void LoadMapNamePopUpWindowBg(void)
{
    u8 popUpThemeId;
    u8 popupWindowId = GetMapNamePopUpWindowId();
    mapsec_u16_t regionMapSectionId = gMapHeader.regionMapSectionId;
    u8 secondaryPopUpWindowId;

    if (OW_POPUP_GENERATION == GEN_5)
        secondaryPopUpWindowId = GetSecondaryPopUpWindowId();

#if !IS_HNS
    if (regionMapSectionId >= KANTO_MAPSEC_START)
    {
        if (regionMapSectionId > KANTO_MAPSEC_END)
            regionMapSectionId -= KANTO_MAPSEC_COUNT;
        else
            regionMapSectionId = 0; // Discard kanto region sections;
    }
#endif

    if (OW_POPUP_GENERATION == GEN_5)
    {
        popUpThemeId = sRegionMapSectionId_To_PopUpThemeIdMapping_BW[regionMapSectionId];
        switch (popUpThemeId)
        {
        // add additional gen 5-style pop-up themes as cases here
        default: // MAPPOPUP_THEME_BW_DEFAULT
            if (OW_POPUP_BW_COLOR == OW_POPUP_BW_COLOR_WHITE)
                LoadPalette(sMapPopUpTilesPalette_BW_White, BG_PLTT_ID(14), sizeof(sMapPopUpTilesPalette_BW_White));
            else
                LoadPalette(sMapPopUpTilesPalette_BW_Black, BG_PLTT_ID(14), sizeof(sMapPopUpTilesPalette_BW_Black));

            CopyToWindowPixelBuffer(popupWindowId, sMapPopUpTilesPrimary_BW, sizeof(sMapPopUpTilesPrimary_BW), 0);
            CopyToWindowPixelBuffer(secondaryPopUpWindowId, sMapPopUpTilesSecondary_BW, sizeof(sMapPopUpTilesSecondary_BW), 0);
            break;
        }

        PutWindowTilemap(popupWindowId);
        PutWindowTilemap(secondaryPopUpWindowId);
    }
    else
    {
        popUpThemeId = sMapSectionToThemeId[regionMapSectionId];
        LoadBgTiles(GetWindowAttribute(popupWindowId, WINDOW_BG), sMapPopUp_OutlineTable[popUpThemeId], 0x400, 0x21D);
        CallWindowFunction(popupWindowId, DrawMapNamePopUpFrame);
        PutWindowTilemap(popupWindowId);
        if (gMapHeader.weather == WEATHER_UNDERWATER_BUBBLES)
            LoadPalette(&sMapPopUp_Palette_Underwater, BG_PLTT_ID(14), sizeof(sMapPopUp_Palette_Underwater));
        else
            LoadPalette(sMapPopUp_PaletteTable[popUpThemeId], BG_PLTT_ID(14), sizeof(sMapPopUp_PaletteTable[0]));
        BlitBitmapToWindow(popupWindowId, sMapPopUp_Table[popUpThemeId], 0, 0, 80, 24);
    }
}
