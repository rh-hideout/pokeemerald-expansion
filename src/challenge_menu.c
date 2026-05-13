#include "global.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "battle_main.h"
#include "random.h"
#include "overworld.h"
#include "script.h"
#include "challenge_menu.h"

// Pokemon HeartGold/SoulSilver uses this file name pattern from HnS.
// However, this is a clean rewrite using expansion's ListMenu infrastructure.

// =============================================================================
// Submenu (tab) definitions
// =============================================================================

enum {
    TAB_MODE,
    TAB_FEATURES,
    TAB_RANDOMIZER,
    TAB_NUZLOCKE,
    TAB_DIFFICULTY,
    TAB_CHALLENGES,
    TAB_COUNT,
};

// =============================================================================
// Per-tab item enums — placeholder items for skeleton testing
// =============================================================================

enum {
    ITEM_MODE_GAMEMODE,
    ITEM_MODE_MODERN_MOVES,
    ITEM_MODE_SYNCHRONIZE,
    ITEM_MODE_STURDY,
    ITEM_MODE_NEW_CITRUS,
    ITEM_MODE_FAIRY_TYPES,
    ITEM_MODE_LEGENDARY_ABILITIES,
    ITEM_MODE_INFINITE_TMS,
    ITEM_MODE_MINTS,
    ITEM_MODE_SURVIVE_POISON,
    ITEM_MODE_NEXT,
    ITEM_MODE_COUNT,
};

enum {
    ITEM_FEATURES_RTC_TYPE,
    ITEM_FEATURES_SHINY_CHANCE,
    ITEM_FEATURES_SHINY_COLOR,
    ITEM_FEATURES_ITEM_DROP,
    ITEM_FEATURES_FRONTIER_BANS,
    ITEM_FEATURES_NEXT,
    ITEM_FEATURES_COUNT,
};

enum {
    ITEM_RANDOM_OFF_ON,
    ITEM_RANDOM_STARTER,
    ITEM_RANDOM_WILD_PKMN,
    ITEM_RANDOM_MAP_BASED,
    ITEM_RANDOM_TRAINER,
    ITEM_RANDOM_STATIC,
    ITEM_RANDOM_SIMILAR,
    ITEM_RANDOM_LEGENDARIES,
    ITEM_RANDOM_TYPE,
    ITEM_RANDOM_MOVES,
    ITEM_RANDOM_ABILITIES,
    ITEM_RANDOM_EVOLUTIONS,
    ITEM_RANDOM_EVO_METHODS,
    ITEM_RANDOM_TYPE_EFFEC,
    ITEM_RANDOM_ITEMS,
    ITEM_RANDOM_CHAOS,
    ITEM_RANDOM_NEXT,
    ITEM_RANDOM_COUNT,
};

enum {
    ITEM_NUZLOCKE_NUZLOCKE,
    ITEM_NUZLOCKE_SPECIES_CLAUSE,
    ITEM_NUZLOCKE_SHINY_CLAUSE,
    ITEM_NUZLOCKE_NICKNAMING,
    ITEM_NUZLOCKE_DELETION,
    ITEM_NUZLOCKE_RARE_CANDY,
    ITEM_NUZLOCKE_NEXT,
    ITEM_NUZLOCKE_COUNT,
};

enum {
    ITEM_DIFFICULTY_PARTY_LIMIT,
    ITEM_DIFFICULTY_LEVEL_CAP,
    ITEM_DIFFICULTY_EXP_MULTIPLIER,
    ITEM_DIFFICULTY_ITEM_PLAYER,
    ITEM_DIFFICULTY_ITEM_TRAINER,
    ITEM_DIFFICULTY_MAX_PARTY_IVS,
    ITEM_DIFFICULTY_SCALING_IVS,
    ITEM_DIFFICULTY_NO_EVS,
    ITEM_DIFFICULTY_SCALING_EVS,
    ITEM_DIFFICULTY_LESS_ESCAPES,
    ITEM_DIFFICULTY_ESCAPE_ROPE_DIG,
    ITEM_DIFFICULTY_NEXT,
    ITEM_DIFFICULTY_COUNT,
};

enum {
    ITEM_CHALLENGES_POKECENTER,
    ITEM_CHALLENGES_PCHEAL,
    ITEM_CHALLENGES_EXPENSIVE,
    ITEM_CHALLENGES_EVO_LIMIT,
    ITEM_CHALLENGES_ONE_TYPE,
    ITEM_CHALLENGES_BST_EQUALIZER,
    ITEM_CHALLENGES_MIRROR,
    ITEM_CHALLENGES_MIRROR_THIEF,
    ITEM_CHALLENGES_SAVE,
    ITEM_CHALLENGES_COUNT,
};

// Maximum items in any single tab
#define MAX_ITEMS_PER_TAB 16
#define ITEMS_VISIBLE 5
#define Y_DIFF 16

// =============================================================================
// Menu item descriptor — one per option row
// =============================================================================

struct ChallengeMenuItem
{
    const u8 *name;
    const u8 *const *descriptions;
    u8 numChoices;
    const u8 *const *choiceNames;
};

// =============================================================================
// EWRAM state
// =============================================================================

struct ChallengeMenuState
{
    u8 currentTab;
    u8 listTaskId;
    u8 arrowTaskId;
    u16 scrollOffset[TAB_COUNT];
    u16 selectedRow[TAB_COUNT];
    u8 selections[TAB_COUNT * MAX_ITEMS_PER_TAB];
};

static EWRAM_DATA struct ChallengeMenuState *sMenu = NULL;

// =============================================================================
// Window / BG templates
// =============================================================================

enum {
    WIN_TOPBAR,
    WIN_OPTIONS,
    WIN_DESCRIPTION,
};

static const struct WindowTemplate sWinTemplates[] = {
    [WIN_TOPBAR] = {
        .bg = 1,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2,
    },
    [WIN_OPTIONS] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 26,
        .height = 10,
        .paletteNum = 1,
        .baseBlock = 62,
    },
    [WIN_DESCRIPTION] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 500,
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct BgTemplate sBgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
};

static const u16 sBgPal[] = {RGB(14, 20, 24)};
static const u16 sTextPal[] = INCBIN_U16("graphics/interface/option_menu_text_custom.gbapal");

// Frame tile IDs — loaded from window frame tileset at base 0x1A2
#define TILE_TOP_CORNER_L 0x1A2
#define TILE_TOP_EDGE     0x1A3
#define TILE_TOP_CORNER_R 0x1A4
#define TILE_LEFT_EDGE    0x1A5
#define TILE_RIGHT_EDGE   0x1A7
#define TILE_BOT_CORNER_L 0x1A8
#define TILE_BOT_EDGE     0x1A9
#define TILE_BOT_CORNER_R 0x1AA

// Text color arrays for AddTextPrinterParameterized3/4
#define TEXT_COLOR_OPTIONS_WHITE              1
#define TEXT_COLOR_OPTIONS_GRAY_FG            2
#define TEXT_COLOR_OPTIONS_GRAY_SHADOW        3
#define TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG      4
#define TEXT_COLOR_OPTIONS_ORANGE_FG          5
#define TEXT_COLOR_OPTIONS_ORANGE_SHADOW      6
#define TEXT_COLOR_OPTIONS_RED_FG             7
#define TEXT_COLOR_OPTIONS_RED_SHADOW         8
#define TEXT_COLOR_OPTIONS_GREEN_FG           9
#define TEXT_COLOR_OPTIONS_GREEN_SHADOW      10
#define TEXT_COLOR_OPTIONS_GREEN_DARK_FG     11
#define TEXT_COLOR_OPTIONS_GREEN_DARK_SHADOW 12
#define TEXT_COLOR_OPTIONS_RED_DARK_FG       13
#define TEXT_COLOR_OPTIONS_RED_DARK_SHADOW   14

// =============================================================================
// Placeholder choice strings
// =============================================================================

static const u8 *const sChoices_OffOn[] = {
    COMPOUND_STRING("OFF"),
    COMPOUND_STRING("ON"),
};

static const u8 *const sChoices_OnOff[] = {
    COMPOUND_STRING("ON"),
    COMPOUND_STRING("OFF"),
};

static const u8 *const sChoices_Gamemode[] = {
    COMPOUND_STRING("RECOMMENDED"),
    COMPOUND_STRING("CUSTOM"),
};

static const u8 *const sChoices_OriginalModern[] = {
    COMPOUND_STRING("ORIGINAL"),
    COMPOUND_STRING("MODERN"),
};

static const u8 sText_TopBar_Left[]  = _("{L_BUTTON}PREVIOUS");
static const u8 sText_TopBar_Right[] = _("{R_BUTTON}NEXT");

// =============================================================================
// Tab item tables — skeleton placeholders
// =============================================================================

static const u8 *const sDesc_Gamemode[] = {
    COMPOUND_STRING("Recommended settings.\nNOTE: All selections are PERMANENT."),
    COMPOUND_STRING("Choose your own rules.\nNOTE: All selections are PERMANENT."),
};
static const u8 *const sDesc_ModernMoves[] = {
    COMPOUND_STRING("No new MOVES, and original MOVEPOOL\nfor all {PKMN} + new EGG MOVES."),
    COMPOUND_STRING("13 new MOVES, and improved MOVEPOOL\nfor all {PKMN} + new EGG MOVES."),
};
static const u8 *const sDesc_Synchronize[] = {
    COMPOUND_STRING("SYNCHRONIZE works as in GEN III.\n50% chance to copy nature."),
    COMPOUND_STRING("SYNCHRONIZE works as in GEN VIII+.\n100% chance to copy nature."),
};
static const u8 *const sDesc_Sturdy[] = {
    COMPOUND_STRING("STURDY works as in GEN III. Only\nnegates OHKO moves (GUILLOTINE, etc.)"),
    COMPOUND_STRING("STURDY works as in GEN V+.\n{PKMN} survive lethal hits with 1HP."),
};
static const u8 *const sDesc_NewCitrus[] = {
    COMPOUND_STRING("SITRUS BERRY restores 30HP.\nSame as GEN III."),
    COMPOUND_STRING("SITRUS BERRY restores 25% of\ntotal HP. Same as GEN IV and up."),
};
static const u8 *const sDesc_FairyTypes[] = {
    COMPOUND_STRING("FAIRY TYPE isn't added to {PKMN}\nthat got it in GEN VI."),
    COMPOUND_STRING("FAIRY TYPE is added / changed to\ncertain {PKMN}, as in GEN VI."),
};
static const u8 *const sDesc_LegAbilities[] = {
    COMPOUND_STRING("PRESSURE stays as the main\nability of some legendaries."),
    COMPOUND_STRING("Legendaries have PRESSURE changed\nfor a better ability."),
};
static const u8 *const sDesc_InfiniteTMs[] = {
    COMPOUND_STRING("TMs are not reusable.\nLike in the original."),
    COMPOUND_STRING("TMs are reusable.\nModern Emerald recommended."),
};
static const u8 *const sDesc_Mints[] = {
    COMPOUND_STRING("Mints are not available ingame until\nfinishing the game."),
    COMPOUND_STRING("Mints can be bought at PRETTY PETAL\nFLOWER SHOP after the 4th medal."),
};
static const u8 *const sDesc_SurvivePoison[] = {
    COMPOUND_STRING("Your {PKMN} will faint if they are\nPOISONED."),
    COMPOUND_STRING("Your {PKMN} will survive the POISON\nstatus with 1HP."),
};
static const u8 *const sDesc_Next[] = {
    COMPOUND_STRING("Continue to the next page."),
};

static const struct ChallengeMenuItem sTabItems_Mode[] = {
    [ITEM_MODE_GAMEMODE] = {
        .name         = COMPOUND_STRING("GAMEMODE"),
        .descriptions = sDesc_Gamemode,
        .numChoices   = 2,
        .choiceNames  = sChoices_Gamemode,
    },
    [ITEM_MODE_MODERN_MOVES] = {
        .name         = COMPOUND_STRING("{PKMN} MOVEPOOL"),
        .descriptions = sDesc_ModernMoves,
        .numChoices   = 2,
        .choiceNames  = sChoices_OriginalModern,
    },
    [ITEM_MODE_SYNCHRONIZE] = {
        .name         = COMPOUND_STRING("SYNCHRONIZE"),
        .descriptions = sDesc_Synchronize,
        .numChoices   = 2,
        .choiceNames  = sChoices_OriginalModern,
    },
    [ITEM_MODE_STURDY] = {
        .name         = COMPOUND_STRING("STURDY"),
        .descriptions = sDesc_Sturdy,
        .numChoices   = 2,
        .choiceNames  = sChoices_OriginalModern,
    },
    [ITEM_MODE_NEW_CITRUS] = {
        .name         = COMPOUND_STRING("SITRUS BERRY"),
        .descriptions = sDesc_NewCitrus,
        .numChoices   = 2,
        .choiceNames  = sChoices_OriginalModern,
    },
    [ITEM_MODE_FAIRY_TYPES] = {
        .name         = COMPOUND_STRING("ADD FAIRY TYPE"),
        .descriptions = sDesc_FairyTypes,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_MODE_LEGENDARY_ABILITIES] = {
        .name         = COMPOUND_STRING("LEGEN. ABILITIES"),
        .descriptions = sDesc_LegAbilities,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_MODE_INFINITE_TMS] = {
        .name         = COMPOUND_STRING("REUSABLE TMS"),
        .descriptions = sDesc_InfiniteTMs,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_MODE_MINTS] = {
        .name         = COMPOUND_STRING("NATURE MINTS"),
        .descriptions = sDesc_Mints,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_MODE_SURVIVE_POISON] = {
        .name         = COMPOUND_STRING("SURVIVE POISON"),
        .descriptions = sDesc_SurvivePoison,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_MODE_NEXT] = {
        .name         = COMPOUND_STRING("NEXT"),
        .descriptions = sDesc_Next,
        .numChoices   = 0,
        .choiceNames  = NULL,
    },
};

static const u8 *const sDesc_SaveExit[] = { COMPOUND_STRING("Save choices and continue...") };

// =============================================================================
// Choice strings — shared across tabs
// =============================================================================

static const u8 *const sChoices_OffRandom[] = {
    COMPOUND_STRING("OFF"),
    COMPOUND_STRING("RANDOM"),
};

static const u8 *const sChoices_OffChaos[] = {
    COMPOUND_STRING("OFF"),
    COMPOUND_STRING("CHAOS"),
};

static const u8 *const sChoices_YesNo[] = {
    COMPOUND_STRING("YES"),
    COMPOUND_STRING("NO"),
};

static const u8 *const sChoices_BanUnban[] = {
    COMPOUND_STRING("BAN"),
    COMPOUND_STRING("UNBAN"),
};

static const u8 *const sChoices_RtcFake[] = {
    COMPOUND_STRING("RTC"),
    COMPOUND_STRING("FAKE RTC"),
};

static const u8 *const sChoices_ShinyChance[] = {
    COMPOUND_STRING("8192"),
    COMPOUND_STRING("4096"),
    COMPOUND_STRING("2048"),
    COMPOUND_STRING("1024"),
    COMPOUND_STRING("512"),
};

static const u8 *const sChoices_Nuzlocke[] = {
    COMPOUND_STRING("OFF"),
    COMPOUND_STRING("EASY"),
    COMPOUND_STRING("NORMAL"),
    COMPOUND_STRING("HARD"),
};

static const u8 *const sChoices_CemeteryRelease[] = {
    COMPOUND_STRING("CEMETERY"),
    COMPOUND_STRING("RELEASE"),
};

static const u8 *const sChoices_PartyLimit[] = {
    COMPOUND_STRING("OFF"),
    COMPOUND_STRING("5"),
    COMPOUND_STRING("4"),
    COMPOUND_STRING("3"),
    COMPOUND_STRING("2"),
    COMPOUND_STRING("1"),
};

static const u8 *const sChoices_LevelCap[] = {
    COMPOUND_STRING("OFF"),
    COMPOUND_STRING("NORMAL"),
    COMPOUND_STRING("HARD"),
};

static const u8 *const sChoices_ExpMult[] = {
    COMPOUND_STRING("x1.0"),
    COMPOUND_STRING("x1.5"),
    COMPOUND_STRING("x2.0"),
    COMPOUND_STRING("x0.0"),
};

static const u8 *const sChoices_TrainerIVs[] = {
    COMPOUND_STRING("OFF"),
    COMPOUND_STRING("SCALE"),
    COMPOUND_STRING("HARD"),
};

static const u8 *const sChoices_TrainerEVs[] = {
    COMPOUND_STRING("OFF"),
    COMPOUND_STRING("SCALE"),
    COMPOUND_STRING("HARD"),
    COMPOUND_STRING("EXTREM"),
};

static const u8 *const sChoices_PlayerIVs[] = {
    COMPOUND_STRING("YES"),
    COMPOUND_STRING("NO"),
    COMPOUND_STRING("NO (HP)"),
};

static const u8 *const sChoices_PkmnCenter[] = {
    COMPOUND_STRING("YES"),
    COMPOUND_STRING("NO"),
};

static const u8 *const sChoices_Expensive[] = {
    COMPOUND_STRING("OFF"),
    COMPOUND_STRING("x5"),
    COMPOUND_STRING("x10"),
    COMPOUND_STRING("x50!"),
};

static const u8 *const sChoices_EvoLimit[] = {
    COMPOUND_STRING("OFF"),
    COMPOUND_STRING("FIRST"),
    COMPOUND_STRING("ALL"),
};

static const u8 *const sChoices_BstEqual[] = {
    COMPOUND_STRING("OFF"),
    COMPOUND_STRING("100"),
    COMPOUND_STRING("255"),
    COMPOUND_STRING("500"),
};

// =============================================================================
// FEATURES descriptions + table
// =============================================================================

static const u8 *const sDesc_RtcType[] = {
    COMPOUND_STRING("Use vanilla Real Time Clock."),
    COMPOUND_STRING("Use a fake Real Time Clock.\n1h in real life = 1 day in-game."),
};
static const u8 *const sDesc_ShinyChance[] = {
    COMPOUND_STRING("Very low chance of SHINY encounter.\nDefault chance from Generation III."),
    COMPOUND_STRING("Low chance of SHINY encounter.\nDefault chance from Generation VI+."),
    COMPOUND_STRING("Decent chance of SHINY encounter."),
    COMPOUND_STRING("High chance of SHINY encounter."),
    COMPOUND_STRING("Very high chance of SHINY encounter."),
};
static const u8 *const sDesc_ItemDrop[] = {
    COMPOUND_STRING("Wild {PKMN} items will be only\nobtainable via capture or THIEF."),
    COMPOUND_STRING("Wild {PKMN} will drop their hold\nitem after defeating them."),
};
static const u8 *const sDesc_FrontierBans[] = {
    COMPOUND_STRING("Powerful legendary {PKMN} are banned\nin the BATTLE FRONTIER. Default."),
    COMPOUND_STRING("All legendaries are allowed to\nparticipate in the BATTLE FRONTIER."),
};
static const u8 *const sDesc_ShinyColor[] = {
    COMPOUND_STRING("Original shiny color palette for\nall {PKMN}. Default."),
    COMPOUND_STRING("Some shiny {PKMN} have brand new\ncolor palettes."),
};
static const u8 *const sDesc_FeaturesNext[] = {
    COMPOUND_STRING("Continue to Randomizer options."),
};

static const struct ChallengeMenuItem sTabItems_Features[] = {
    [ITEM_FEATURES_RTC_TYPE] = {
        .name         = COMPOUND_STRING("CLOCK TYPE"),
        .descriptions = sDesc_RtcType,
        .numChoices   = 2,
        .choiceNames  = sChoices_RtcFake,
    },
    [ITEM_FEATURES_SHINY_CHANCE] = {
        .name         = COMPOUND_STRING("SHINY CHANCE"),
        .descriptions = sDesc_ShinyChance,
        .numChoices   = 5,
        .choiceNames  = sChoices_ShinyChance,
    },
    [ITEM_FEATURES_SHINY_COLOR] = {
        .name         = COMPOUND_STRING("ALT SHINY"),
        .descriptions = sDesc_ShinyColor,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_FEATURES_ITEM_DROP] = {
        .name         = COMPOUND_STRING("ITEM DROP"),
        .descriptions = sDesc_ItemDrop,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_FEATURES_FRONTIER_BANS] = {
        .name         = COMPOUND_STRING("FRONTIER BANS"),
        .descriptions = sDesc_FrontierBans,
        .numChoices   = 2,
        .choiceNames  = sChoices_BanUnban,
    },
    [ITEM_FEATURES_NEXT] = {
        .name         = COMPOUND_STRING("NEXT"),
        .descriptions = sDesc_FeaturesNext,
        .numChoices   = 0,
        .choiceNames  = NULL,
    },
};

// =============================================================================
// RANDOMIZER descriptions + table
// =============================================================================

static const u8 *const sDesc_RandomOffOn[] = {
    COMPOUND_STRING("Game will not be randomized."),
    COMPOUND_STRING("Play the game randomized.\nSettings below!"),
};
static const u8 *const sDesc_RandomStarter[] = {
    COMPOUND_STRING("Standard starter {PKMN}."),
    COMPOUND_STRING("Randomize starter {PKMN}."),
};
static const u8 *const sDesc_RandomWild[] = {
    COMPOUND_STRING("Same wild encounter as in the\nbase game."),
    COMPOUND_STRING("Randomize wild {PKMN}."),
};
static const u8 *const sDesc_RandomMapBased[] = {
    COMPOUND_STRING("Wild encounters are fully random\nevery time."),
    COMPOUND_STRING("Wild encounters are seeded per map.\nSame area always has the same {PKMN}."),
};
static const u8 *const sDesc_RandomTrainer[] = {
    COMPOUND_STRING("Trainer will have their expected\nparty."),
    COMPOUND_STRING("Randomize enemy trainer parties."),
};
static const u8 *const sDesc_RandomStatic[] = {
    COMPOUND_STRING("Static encounters will be the same\nas in the base game."),
    COMPOUND_STRING("Named {PKMN}, casino {PKMN}, roamers,\nand some other special {PKMN} won't change."),
};
static const u8 *const sDesc_RandomSimilar[] = {
    COMPOUND_STRING("{PKMN} replaced with similar tiered\nones. Currently based on evo stages."),
    COMPOUND_STRING("Distribution of {PKMN} not balanced\naround their strength!"),
};
static const u8 *const sDesc_RandomLegendaries[] = {
    COMPOUND_STRING("Legendary {PKMN} will not be\nincluded and randomized."),
    COMPOUND_STRING("Include legendary {PKMN} in\nrandomization!"),
};
static const u8 *const sDesc_RandomType[] = {
    COMPOUND_STRING("{PKMN} types stay the same as in\nthe base game."),
    COMPOUND_STRING("Randomize all {PKMN} types."),
};
static const u8 *const sDesc_RandomMoves[] = {
    COMPOUND_STRING("{PKMN} moves stay the same as in\nthe base game."),
    COMPOUND_STRING("Randomize all {PKMN} moves."),
};
static const u8 *const sDesc_RandomAbilities[] = {
    COMPOUND_STRING("{PKMN} abilities stay the same as\nin the base game."),
    COMPOUND_STRING("Randomize all {PKMN} abilities."),
};
static const u8 *const sDesc_RandomEvolutions[] = {
    COMPOUND_STRING("{PKMN} evolutions stay the same as\nin the base game."),
    COMPOUND_STRING("Randomize all {PKMN} evolutions."),
};
static const u8 *const sDesc_RandomEvoMethods[] = {
    COMPOUND_STRING("The {PKMN} that can potentially\nevolve are unchanged."),
    COMPOUND_STRING("Randomize evolution lines. Allows\nnew evolution lines to occur!"),
};
static const u8 *const sDesc_RandomTypeEffec[] = {
    COMPOUND_STRING("Type effectiveness chart will remain\nthe same as in the base game."),
    COMPOUND_STRING("Randomize type effectiveness.\nWARNING: CAN BE BUGGY!"),
};
static const u8 *const sDesc_RandomItems[] = {
    COMPOUND_STRING("All found or received items are the\nsame as in the base game."),
    COMPOUND_STRING("Randomize found, hidden and received\nitems. KEY items are excluded!"),
};
static const u8 *const sDesc_RandomChaos[] = {
    COMPOUND_STRING("Chaos mode disabled."),
    COMPOUND_STRING("Every above chosen option will be\nvery chaotic. NOT recommended!"),
};
static const u8 *const sDesc_RandomNext[] = {
    COMPOUND_STRING("Continue to Nuzlocke options."),
};

static const struct ChallengeMenuItem sTabItems_Randomizer[] = {
    [ITEM_RANDOM_OFF_ON] = {
        .name         = COMPOUND_STRING("RANDOMIZER"),
        .descriptions = sDesc_RandomOffOn,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_STARTER] = {
        .name         = COMPOUND_STRING("STARTER {PKMN}"),
        .descriptions = sDesc_RandomStarter,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_WILD_PKMN] = {
        .name         = COMPOUND_STRING("WILD {PKMN}"),
        .descriptions = sDesc_RandomWild,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_MAP_BASED] = {
        .name         = COMPOUND_STRING("MAP SEEDED"),
        .descriptions = sDesc_RandomMapBased,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_RANDOM_TRAINER] = {
        .name         = COMPOUND_STRING("TRAINER"),
        .descriptions = sDesc_RandomTrainer,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_STATIC] = {
        .name         = COMPOUND_STRING("STATIC {PKMN}"),
        .descriptions = sDesc_RandomStatic,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_SIMILAR] = {
        .name         = COMPOUND_STRING("BALANCING"),
        .descriptions = sDesc_RandomSimilar,
        .numChoices   = 2,
        .choiceNames  = sChoices_OnOff,
    },
    [ITEM_RANDOM_LEGENDARIES] = {
        .name         = COMPOUND_STRING("LEGENDARIES"),
        .descriptions = sDesc_RandomLegendaries,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_RANDOM_TYPE] = {
        .name         = COMPOUND_STRING("TYPE"),
        .descriptions = sDesc_RandomType,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_MOVES] = {
        .name         = COMPOUND_STRING("MOVES"),
        .descriptions = sDesc_RandomMoves,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_ABILITIES] = {
        .name         = COMPOUND_STRING("ABILITIES"),
        .descriptions = sDesc_RandomAbilities,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_EVOLUTIONS] = {
        .name         = COMPOUND_STRING("EVOLUTIONS"),
        .descriptions = sDesc_RandomEvolutions,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_EVO_METHODS] = {
        .name         = COMPOUND_STRING("EVO LINES"),
        .descriptions = sDesc_RandomEvoMethods,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_TYPE_EFFEC] = {
        .name         = COMPOUND_STRING("EFFECTIVENESS"),
        .descriptions = sDesc_RandomTypeEffec,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_ITEMS] = {
        .name         = COMPOUND_STRING("ITEMS"),
        .descriptions = sDesc_RandomItems,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffRandom,
    },
    [ITEM_RANDOM_CHAOS] = {
        .name         = COMPOUND_STRING("CHAOS MODE"),
        .descriptions = sDesc_RandomChaos,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffChaos,
    },
    [ITEM_RANDOM_NEXT] = {
        .name         = COMPOUND_STRING("NEXT"),
        .descriptions = sDesc_RandomNext,
        .numChoices   = 0,
        .choiceNames  = NULL,
    },
};

// =============================================================================
// NUZLOCKE descriptions + table
// =============================================================================

static const u8 *const sDesc_Nuzlocke[] = {
    COMPOUND_STRING("Nuzlocke mode is disabled."),
    COMPOUND_STRING("Fainted {PKMN} can't be used anymore!\nNo more rules are enforced."),
    COMPOUND_STRING("One catch per route! Fainted {PKMN}\ncan't be used anymore."),
    COMPOUND_STRING("Same rules as NORMAL but also\ndeletes SAVE on battle loss!"),
};
static const u8 *const sDesc_SpeciesClause[] = {
    COMPOUND_STRING("Only not prior caught {PKMN} count\nas first encounter. RECOMMENDED!"),
    COMPOUND_STRING("The player always has to catch the\nfirst {PKMN} per route."),
};
static const u8 *const sDesc_ShinyClause[] = {
    COMPOUND_STRING("The player can always catch shiny\n{PKMN}. RECOMMENDED!"),
    COMPOUND_STRING("The player can only catch a shiny\n{PKMN} if it's the first encounter."),
};
static const u8 *const sDesc_Nicknaming[] = {
    COMPOUND_STRING("Forces the player to nickname every\n{PKMN}. RECOMMENDED!"),
    COMPOUND_STRING("Nicknames are optional."),
};
static const u8 *const sDesc_Deletion[] = {
    COMPOUND_STRING("Fainted {PKMN} are sent to the PC\nafter battle and can't be retrieved."),
    COMPOUND_STRING("Fainted {PKMN} are released after\nbattle!"),
};
static const u8 *const sDesc_RareCandy[] = {
    COMPOUND_STRING("Infinite Rare Candy will be in the\nplayer's PC at game start."),
    COMPOUND_STRING("Player will not have access to\nInfinite Rare Candy."),
};
static const u8 *const sDesc_NuzlockeNext[] = {
    COMPOUND_STRING("Continue to difficulty options."),
};

static const struct ChallengeMenuItem sTabItems_Nuzlocke[] = {
    [ITEM_NUZLOCKE_NUZLOCKE] = {
        .name         = COMPOUND_STRING("NUZLOCKE"),
        .descriptions = sDesc_Nuzlocke,
        .numChoices   = 4,
        .choiceNames  = sChoices_Nuzlocke,
    },
    [ITEM_NUZLOCKE_SPECIES_CLAUSE] = {
        .name         = COMPOUND_STRING("DUPES CLAUSE"),
        .descriptions = sDesc_SpeciesClause,
        .numChoices   = 2,
        .choiceNames  = sChoices_OnOff,
    },
    [ITEM_NUZLOCKE_SHINY_CLAUSE] = {
        .name         = COMPOUND_STRING("SHINY CLAUSE"),
        .descriptions = sDesc_ShinyClause,
        .numChoices   = 2,
        .choiceNames  = sChoices_OnOff,
    },
    [ITEM_NUZLOCKE_NICKNAMING] = {
        .name         = COMPOUND_STRING("NICKNAMES"),
        .descriptions = sDesc_Nicknaming,
        .numChoices   = 2,
        .choiceNames  = sChoices_OnOff,
    },
    [ITEM_NUZLOCKE_DELETION] = {
        .name         = COMPOUND_STRING("FAINTING"),
        .descriptions = sDesc_Deletion,
        .numChoices   = 2,
        .choiceNames  = sChoices_CemeteryRelease,
    },
    [ITEM_NUZLOCKE_RARE_CANDY] = {
        .name         = COMPOUND_STRING("INF. RARE CANDY"),
        .descriptions = sDesc_RareCandy,
        .numChoices   = 2,
        .choiceNames  = sChoices_OnOff,
    },
    [ITEM_NUZLOCKE_NEXT] = {
        .name         = COMPOUND_STRING("NEXT"),
        .descriptions = sDesc_NuzlockeNext,
        .numChoices   = 0,
        .choiceNames  = NULL,
    },
};

// =============================================================================
// DIFFICULTY descriptions + table
// =============================================================================

static const u8 sText_Desc_PartyLimit[] = _("Limits the amount of {PKMN} in the\nparty. 1 has visual bugs in DOUBLES.");
static const u8 *const sDesc_PartyLimit[] = {
    sText_Desc_PartyLimit, sText_Desc_PartyLimit, sText_Desc_PartyLimit,
    sText_Desc_PartyLimit, sText_Desc_PartyLimit, sText_Desc_PartyLimit,
};
static const u8 *const sDesc_LevelCap[] = {
    COMPOUND_STRING("No level cap. Overleveling possible."),
    COMPOUND_STRING("Maximum level is based on the next\ngym's highest {PKMN} level."),
    COMPOUND_STRING("Maximum level is based on the next\ngym's lowest {PKMN} level."),
};
static const u8 *const sDesc_ExpMult[] = {
    COMPOUND_STRING("{PKMN} gain normal EXP. Points.\nStacks with HARD MODE EXP."),
    COMPOUND_STRING("{PKMN} gain 50 percent more EXP.\nPoints! Stacks with HARD MODE EXP."),
    COMPOUND_STRING("{PKMN} gain double EXP. Points!\nStacks with HARD MODE EXP."),
    COMPOUND_STRING("{PKMN} gain ZERO EXP. Points!!!\nApplies to HARD MODE EXP. as well."),
};
static const u8 *const sDesc_ItemPlayer[] = {
    COMPOUND_STRING("The player can use battle items."),
    COMPOUND_STRING("The player can NOT use battle items.\nHold items are allowed!"),
};
static const u8 *const sDesc_ItemTrainer[] = {
    COMPOUND_STRING("Enemy trainers can use battle items."),
    COMPOUND_STRING("Enemy trainers can NOT use battle\nitems."),
};
static const u8 *const sDesc_NoEVs[] = {
    COMPOUND_STRING("The player's {PKMN} gain effort\nvalues as expected."),
    COMPOUND_STRING("The player's {PKMN} do NOT gain any\neffort values!"),
};
static const u8 *const sDesc_ScalingIVs[] = {
    COMPOUND_STRING("The {PKMN} of enemy Trainer have\nthe expected IVs."),
    COMPOUND_STRING("The IVs of Trainer {PKMN} increase\nwith gym badges!"),
    COMPOUND_STRING("All Trainer {PKMN} have perfect IVs!"),
};
static const u8 *const sDesc_ScalingEVs[] = {
    COMPOUND_STRING("The {PKMN} of enemy Trainer have\nno EVs."),
    COMPOUND_STRING("The EVs of Trainer {PKMN} increase\nwith gym badges!"),
    COMPOUND_STRING("All Trainer {PKMN} have high EVs!"),
    COMPOUND_STRING("All Trainer {PKMN} have 252 EVs!\nVery Hard!"),
};
static const u8 *const sDesc_MaxPartyIVs[] = {
    COMPOUND_STRING("Your {PKMN} have the expected IVs\n(between 0 and 31)."),
    COMPOUND_STRING("The IVs of your {PKMN} are set\nalways to the maximum (31)."),
    COMPOUND_STRING("IVs are set between 30 and 31 to\nallow different Hidden Powers."),
};
static const u8 *const sDesc_LessEscapes[] = {
    COMPOUND_STRING("The player can easily run away from\nbattles, as usual."),
    COMPOUND_STRING("The player can't easily run away\nfrom battles. Use repels!"),
};
static const u8 *const sDesc_EscapeRopeDig[] = {
    COMPOUND_STRING("ESCAPE ROPE and DIG can be used to\nexit dungeons."),
    COMPOUND_STRING("ESCAPE ROPE and DIG can't be used\nto exit dungeons."),
};
static const u8 *const sDesc_DifficultyNext[] = {
    COMPOUND_STRING("Continue to challenge options."),
};

static const struct ChallengeMenuItem sTabItems_Difficulty[] = {
    [ITEM_DIFFICULTY_PARTY_LIMIT] = {
        .name         = COMPOUND_STRING("PARTY LIMIT"),
        .descriptions = sDesc_PartyLimit,
        .numChoices   = 6,
        .choiceNames  = sChoices_PartyLimit,
    },
    [ITEM_DIFFICULTY_LEVEL_CAP] = {
        .name         = COMPOUND_STRING("LEVEL CAP"),
        .descriptions = sDesc_LevelCap,
        .numChoices   = 3,
        .choiceNames  = sChoices_LevelCap,
    },
    [ITEM_DIFFICULTY_EXP_MULTIPLIER] = {
        .name         = COMPOUND_STRING("EXP. MULTIPLIER"),
        .descriptions = sDesc_ExpMult,
        .numChoices   = 4,
        .choiceNames  = sChoices_ExpMult,
    },
    [ITEM_DIFFICULTY_ITEM_PLAYER] = {
        .name         = COMPOUND_STRING("PLAYER ITEMS"),
        .descriptions = sDesc_ItemPlayer,
        .numChoices   = 2,
        .choiceNames  = sChoices_YesNo,
    },
    [ITEM_DIFFICULTY_ITEM_TRAINER] = {
        .name         = COMPOUND_STRING("TRAINER ITEMS"),
        .descriptions = sDesc_ItemTrainer,
        .numChoices   = 2,
        .choiceNames  = sChoices_YesNo,
    },
    [ITEM_DIFFICULTY_MAX_PARTY_IVS] = {
        .name         = COMPOUND_STRING("PLAYER IVs"),
        .descriptions = sDesc_MaxPartyIVs,
        .numChoices   = 3,
        .choiceNames  = sChoices_PlayerIVs,
    },
    [ITEM_DIFFICULTY_SCALING_IVS] = {
        .name         = COMPOUND_STRING("TRAINER IVs"),
        .descriptions = sDesc_ScalingIVs,
        .numChoices   = 3,
        .choiceNames  = sChoices_TrainerIVs,
    },
    [ITEM_DIFFICULTY_NO_EVS] = {
        .name         = COMPOUND_STRING("PLAYER EVs"),
        .descriptions = sDesc_NoEVs,
        .numChoices   = 2,
        .choiceNames  = sChoices_YesNo,
    },
    [ITEM_DIFFICULTY_SCALING_EVS] = {
        .name         = COMPOUND_STRING("TRAINER EVs"),
        .descriptions = sDesc_ScalingEVs,
        .numChoices   = 4,
        .choiceNames  = sChoices_TrainerEVs,
    },
    [ITEM_DIFFICULTY_LESS_ESCAPES] = {
        .name         = COMPOUND_STRING("LESS ESCAPES"),
        .descriptions = sDesc_LessEscapes,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_DIFFICULTY_ESCAPE_ROPE_DIG] = {
        .name         = COMPOUND_STRING("ESC. ROPE / DIG"),
        .descriptions = sDesc_EscapeRopeDig,
        .numChoices   = 2,
        .choiceNames  = sChoices_YesNo,
    },
    [ITEM_DIFFICULTY_NEXT] = {
        .name         = COMPOUND_STRING("NEXT"),
        .descriptions = sDesc_DifficultyNext,
        .numChoices   = 0,
        .choiceNames  = NULL,
    },
};

// =============================================================================
// CHALLENGES descriptions + table
// =============================================================================

static const u8 *const sDesc_Pokecenter[] = {
    COMPOUND_STRING("The player can visit {PKMN}centers\nand other locations to heal."),
    COMPOUND_STRING("The player CAN'T visit {PKMN}centers\nor other locations to heal."),
};
static const u8 *const sDesc_PCHeal[] = {
    COMPOUND_STRING("{PKMN} deposited to the PC will be\nhealed as usual."),
    COMPOUND_STRING("{PKMN} deposited to the PC will not\nbe healed."),
};
static const u8 *const sDesc_Expensive[] = {
    COMPOUND_STRING("Everything has the usual cost."),
    COMPOUND_STRING("Everything is 5 times more\nexpensive!"),
    COMPOUND_STRING("Everything is 10 times more\nexpensive! Good ol' capitalism."),
    COMPOUND_STRING("Everything is 50 times more\nexpensive! Ultra capitalism!"),
};
static const u8 *const sDesc_EvoLimit[] = {
    COMPOUND_STRING("{PKMN} evolve as expected."),
    COMPOUND_STRING("{PKMN} can only evolve into their\nfirst evolution."),
    COMPOUND_STRING("{PKMN} can NOT evolve at all!"),
};
#define NUM_ONE_TYPE_CHOICES 20
#define ONE_TYPE_OFF 31

static const u8 sText_Desc_OneType[] = _("Allow only one {PKMN} type the\nplayer can capture and use.");
static const u8 *const sDesc_OneType[] = {
    sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType,
    sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType,
    sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType,
    sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType,
    sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType, sText_Desc_OneType,
};
static const u8 *const sDesc_BstEqualizer[] = {
    COMPOUND_STRING("All {PKMN} have their original\nbase stats."),
    COMPOUND_STRING("{PKMN} stats are calculated with\n100 of each base stat."),
    COMPOUND_STRING("{PKMN} stats are calculated with\n255 of each base stat."),
    COMPOUND_STRING("{PKMN} stats are calculated with\n500 of each base stat."),
};
static const u8 *const sDesc_Mirror[] = {
    COMPOUND_STRING("The player uses their own party."),
    COMPOUND_STRING("In Trainer battles, the player gets\na copy of the enemy's party!"),
};
static const u8 *const sDesc_MirrorThief[] = {
    COMPOUND_STRING("The player gets their own party\nback after battles."),
    COMPOUND_STRING("The player keeps the enemies party\nafter battle!"),
};

static const struct ChallengeMenuItem sTabItems_Challenges[] = {
    [ITEM_CHALLENGES_POKECENTER] = {
        .name         = COMPOUND_STRING("{PKMN}CENTER"),
        .descriptions = sDesc_Pokecenter,
        .numChoices   = 2,
        .choiceNames  = sChoices_PkmnCenter,
    },
    [ITEM_CHALLENGES_PCHEAL] = {
        .name         = COMPOUND_STRING("PC HEALS {PKMN}"),
        .descriptions = sDesc_PCHeal,
        .numChoices   = 2,
        .choiceNames  = sChoices_YesNo,
    },
    [ITEM_CHALLENGES_EXPENSIVE] = {
        .name         = COMPOUND_STRING("ULTRA EXPENSIVE!"),
        .descriptions = sDesc_Expensive,
        .numChoices   = 4,
        .choiceNames  = sChoices_Expensive,
    },
    [ITEM_CHALLENGES_EVO_LIMIT] = {
        .name         = COMPOUND_STRING("EVO LIMIT"),
        .descriptions = sDesc_EvoLimit,
        .numChoices   = 3,
        .choiceNames  = sChoices_EvoLimit,
    },
    [ITEM_CHALLENGES_ONE_TYPE] = {
        .name         = COMPOUND_STRING("ONE TYPE ONLY"),
        .descriptions = sDesc_OneType,
        .numChoices   = NUM_ONE_TYPE_CHOICES,
        .choiceNames  = NULL,
    },
    [ITEM_CHALLENGES_BST_EQUALIZER] = {
        .name         = COMPOUND_STRING("BST EQUALIZER"),
        .descriptions = sDesc_BstEqualizer,
        .numChoices   = 4,
        .choiceNames  = sChoices_BstEqual,
    },
    [ITEM_CHALLENGES_MIRROR] = {
        .name         = COMPOUND_STRING("MIRROR MODE"),
        .descriptions = sDesc_Mirror,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_CHALLENGES_MIRROR_THIEF] = {
        .name         = COMPOUND_STRING("MIRROR THIEF"),
        .descriptions = sDesc_MirrorThief,
        .numChoices   = 2,
        .choiceNames  = sChoices_OffOn,
    },
    [ITEM_CHALLENGES_SAVE] = {
        .name         = COMPOUND_STRING("SAVE"),
        .descriptions = sDesc_SaveExit,
        .numChoices   = 0,
        .choiceNames  = NULL,
    },
};

// =============================================================================
// Per-tab metadata
// =============================================================================

struct TabDef
{
    const u8 *tabName;
    const struct ChallengeMenuItem *items;
    u8 count;
};

static const struct TabDef sTabs[TAB_COUNT] = {
    [TAB_MODE]       = { COMPOUND_STRING("MODE"),       sTabItems_Mode,       ITEM_MODE_COUNT },
    [TAB_FEATURES]   = { COMPOUND_STRING("FEATURES"),   sTabItems_Features,   ITEM_FEATURES_COUNT },
    [TAB_RANDOMIZER] = { COMPOUND_STRING("RANDOMIZER"), sTabItems_Randomizer, ITEM_RANDOM_COUNT },
    [TAB_NUZLOCKE]   = { COMPOUND_STRING("NUZLOCKE"),   sTabItems_Nuzlocke,   ITEM_NUZLOCKE_COUNT },
    [TAB_DIFFICULTY] = { COMPOUND_STRING("DIFFICULTY"),  sTabItems_Difficulty, ITEM_DIFFICULTY_COUNT },
    [TAB_CHALLENGES] = { COMPOUND_STRING("CHALLENGES"), sTabItems_Challenges, ITEM_CHALLENGES_COUNT },
};

// =============================================================================
// Forward declarations
// =============================================================================

static void MainCB2(void);
static void VBlankCB(void);
static void Task_FadeIn(u8 taskId);
static void Task_ProcessInput(u8 taskId);
static void Task_Save(u8 taskId);
static void Task_FadeOut(u8 taskId);
static void InitListMenu(void);
static void DestroyCurrentListMenu(void);
static void DrawTopBar(void);
static void DrawDescription(void);
static void DrawBgFrames(void);
static void ChallengeMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static void ChallengeMenu_ItemPrintFunc(u8 windowId, u32 itemId, u8 y);

static u8 *GetSelectionPtr(u8 tab, u8 itemIndex);

// Temporary ListMenuItem storage for building the list each tab switch
static EWRAM_DATA struct ListMenuItem sListItems[MAX_ITEMS_PER_TAB] = {0};

// =============================================================================
// Helpers
// =============================================================================

static u8 *GetSelectionPtr(u8 tab, u8 itemIndex)
{
    return &sMenu->selections[tab * MAX_ITEMS_PER_TAB + itemIndex];
}

static u8 GetCurrentTabItemCount(void)
{
    return sTabs[sMenu->currentTab].count;
}

static const struct ChallengeMenuItem *GetCurrentTabItems(void)
{
    return sTabs[sMenu->currentTab].items;
}

// =============================================================================
// Conditions / presets
// =============================================================================

static bool8 CheckConditions(u8 tab, u8 itemIndex)
{
    switch (tab)
    {
    case TAB_MODE:
        switch (itemIndex)
        {
        case ITEM_MODE_GAMEMODE:
        case ITEM_MODE_NEXT:
            return TRUE;
        default:
            return *GetSelectionPtr(TAB_MODE, ITEM_MODE_GAMEMODE) == 1; // CUSTOM
        }
    case TAB_RANDOMIZER:
    {
        u8 masterOn = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_OFF_ON);
        bool8 anyPkmn = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_WILD_PKMN)
                      || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_STARTER)
                      || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TRAINER)
                      || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_STATIC);
        switch (itemIndex)
        {
        case ITEM_RANDOM_OFF_ON:
        case ITEM_RANDOM_NEXT:
            return TRUE;
        case ITEM_RANDOM_MAP_BASED:
            return masterOn && *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_WILD_PKMN);
        case ITEM_RANDOM_SIMILAR:
            return masterOn && anyPkmn && !(*GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_CHAOS));
        case ITEM_RANDOM_LEGENDARIES:
            return masterOn && anyPkmn;
        case ITEM_RANDOM_CHAOS:
            return masterOn && (anyPkmn
                || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TYPE)
                || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_MOVES)
                || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_ABILITIES)
                || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_EVOLUTIONS)
                || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_EVO_METHODS)
                || *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TYPE_EFFEC));
        default:
            return masterOn;
        }
    }
    case TAB_NUZLOCKE:
    {
        u8 nuzSel = *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NUZLOCKE);
        switch (itemIndex)
        {
        case ITEM_NUZLOCKE_NUZLOCKE:
        case ITEM_NUZLOCKE_NEXT:
            return TRUE;
        case ITEM_NUZLOCKE_RARE_CANDY:
            return nuzSel > 0;
        default:
            if (nuzSel == 1) // EASY — lock all sub-options except RARE_CANDY
                return FALSE;
            return nuzSel > 0;
        }
    }
    case TAB_CHALLENGES:
        switch (itemIndex)
        {
        case ITEM_CHALLENGES_PCHEAL:
            return !(*GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_POKECENTER));
        case ITEM_CHALLENGES_MIRROR_THIEF:
            return *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_MIRROR) == 1;
        default:
            return TRUE;
        }
    default:
        return TRUE;
    }
}

static void ApplyRecommendedPresets(void)
{
    // When RECOMMENDED is selected, force all mode options to their "on/new" values
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_MODERN_MOVES)       = 1; // ON
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_SYNCHRONIZE)        = 1; // NEW
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_STURDY)             = 1; // NEW
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_NEW_CITRUS)         = 1; // NEW
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_FAIRY_TYPES)        = 1; // ON
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_LEGENDARY_ABILITIES)= 1; // ON
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_INFINITE_TMS)       = 1; // ON
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_MINTS)              = 1; // ON
    *GetSelectionPtr(TAB_MODE, ITEM_MODE_SURVIVE_POISON)     = 1; // ON
}

// =============================================================================
// Callbacks
// =============================================================================

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

// =============================================================================
// Row highlight (hardware window darkening band)
// =============================================================================

static void HighlightRow(void)
{
    u16 scrollOffset, selectedRow;
    ListMenuGetScrollAndRow(sMenu->listTaskId, &scrollOffset, &selectedRow);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(Y_DIFF, 224));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(selectedRow * Y_DIFF + 24, selectedRow * Y_DIFF + 40));
}

// =============================================================================
// Right-side choice drawing
// =============================================================================

static void DrawRightSideChoiceText(const u8 *text, int x, int y, bool8 chosen, bool8 active)
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    if (active)
    {
        color[1] = chosen ? TEXT_COLOR_OPTIONS_RED_FG : TEXT_COLOR_OPTIONS_GRAY_FG;
        color[2] = chosen ? TEXT_COLOR_OPTIONS_RED_SHADOW : TEXT_COLOR_OPTIONS_GRAY_SHADOW;
    }
    else
    {
        color[1] = chosen ? TEXT_COLOR_OPTIONS_RED_DARK_FG : TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG;
        color[2] = chosen ? TEXT_COLOR_OPTIONS_RED_DARK_SHADOW : TEXT_COLOR_OPTIONS_GRAY_SHADOW;
    }
    AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, x, y, 0, 0, color, TEXT_SKIP_DRAW, text);
}

static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3)
{
    int widthLeft = GetStringWidth(FONT_NORMAL, txt1, 0);
    int widthMid = GetStringWidth(FONT_NORMAL, txt2, 0);
    int widthRight = GetStringWidth(FONT_NORMAL, txt3, 0);
    widthMid -= (198 - 104);
    return (widthLeft - widthMid - widthRight) / 2 + 104;
}

static void DrawChoices_Two(const u8 *const *strings, int selection, int y, bool8 active, int leftX)
{
    DrawRightSideChoiceText(strings[0], leftX, y + 1, selection == 0, active);
    DrawRightSideChoiceText(strings[1], GetStringRightAlignXOffset(FONT_NORMAL, strings[1], 198), y + 1, selection == 1, active);
}

static void DrawChoices_Three(const u8 *const *strings, int selection, int y, bool8 active)
{
    static const u8 orders[][2] = { {0, 1}, {1, 2}, {1, 2} };
    const u8 *order = orders[selection];
    DrawRightSideChoiceText(strings[order[0]], 104, y + 1, selection == order[0], active);
    DrawRightSideChoiceText(strings[order[1]], GetStringRightAlignXOffset(FONT_NORMAL, strings[order[1]], 198), y + 1, selection == order[1], active);
}

static void DrawChoices_Four(const u8 *const *strings, int selection, int y, bool8 active)
{
    static const u8 orders[][3] = { {0, 1, 2}, {0, 1, 2}, {1, 2, 3}, {1, 2, 3} };
    const u8 *order = orders[selection];
    int xMid = GetMiddleX(strings[order[0]], strings[order[1]], strings[order[2]]);
    DrawRightSideChoiceText(strings[order[0]], 104, y + 1, selection == order[0], active);
    DrawRightSideChoiceText(strings[order[1]], xMid, y + 1, selection == order[1], active);
    DrawRightSideChoiceText(strings[order[2]], GetStringRightAlignXOffset(FONT_NORMAL, strings[order[2]], 198), y + 1, selection == order[2], active);
}

static void DrawChoices_Five(const u8 *const *strings, int selection, int y, bool8 active)
{
    static const u8 orders[][3] = { {0, 1, 2}, {0, 1, 2}, {1, 2, 3}, {2, 3, 4}, {2, 3, 4} };
    const u8 *order = orders[selection];
    int xMid = GetMiddleX(strings[order[0]], strings[order[1]], strings[order[2]]);
    DrawRightSideChoiceText(strings[order[0]], 104, y + 1, selection == order[0], active);
    DrawRightSideChoiceText(strings[order[1]], xMid, y + 1, selection == order[1], active);
    DrawRightSideChoiceText(strings[order[2]], GetStringRightAlignXOffset(FONT_NORMAL, strings[order[2]], 198), y + 1, selection == order[2], active);
}

static void DrawChoices_Six(const u8 *const *strings, int selection, int y, bool8 active)
{
    static const u8 orders[][3] = { {0, 1, 2}, {0, 1, 2}, {1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {3, 4, 5} };
    const u8 *order = orders[selection];
    int xMid = GetMiddleX(strings[order[0]], strings[order[1]], strings[order[2]]);
    DrawRightSideChoiceText(strings[order[0]], 104, y + 1, selection == order[0], active);
    DrawRightSideChoiceText(strings[order[1]], xMid, y + 1, selection == order[1], active);
    DrawRightSideChoiceText(strings[order[2]], GetStringRightAlignXOffset(FONT_NORMAL, strings[order[2]], 198), y + 1, selection == order[2], active);
}

// =============================================================================
// ListMenu callbacks
// =============================================================================

static void ChallengeMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (!onInit)
        PlaySE(SE_SELECT);

    ListMenuGetScrollAndRow(sMenu->listTaskId, &sMenu->scrollOffset[sMenu->currentTab], &sMenu->selectedRow[sMenu->currentTab]);
    HighlightRow();
    DrawDescription();
}

static void ChallengeMenu_ItemPrintFunc(u8 windowId, u32 itemId, u8 y)
{
    const struct ChallengeMenuItem *items = GetCurrentTabItems();

    if (itemId >= GetCurrentTabItemCount())
        return;

    bool8 active = CheckConditions(sMenu->currentTab, itemId);

    // Gray out locked item names by overriding the ListMenu text colors
    if (!active)
    {
        u8 color[3] = { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG, TEXT_COLOR_OPTIONS_GRAY_SHADOW };
        AddTextPrinterParameterized4(windowId, FONT_NORMAL, 8, y + 1, 0, 0, color, TEXT_SKIP_DRAW, items[itemId].name);
    }

    u8 sel = *GetSelectionPtr(sMenu->currentTab, itemId);

    // ONE_TYPE draws type names dynamically instead of using choiceNames
    if (sMenu->currentTab == TAB_CHALLENGES && itemId == ITEM_CHALLENGES_ONE_TYPE)
    {
        u8 n = sel;
        const u8 *text;
        static const u8 sText_Random[] = _("RANDOM");
        static const u8 sText_Off[] = _("OFF");
        if (n > 18)
            text = sText_Off;
        else if (n == 18)
            text = sText_Random;
        else if (n >= 9)
            text = gTypesInfo[n + 2].name;
        else
            text = gTypesInfo[n + 1].name;
        DrawRightSideChoiceText(text, GetStringRightAlignXOffset(FONT_NORMAL, text, 198), y + 1, TRUE, active);
        return;
    }

    if (items[itemId].numChoices == 0 || items[itemId].choiceNames == NULL)
        return;

    if (sel >= items[itemId].numChoices)
        sel = 0;

    switch (items[itemId].numChoices)
    {
    case 2:
    {
        int leftX = (sMenu->currentTab == TAB_MODE && itemId == ITEM_MODE_GAMEMODE) ? 74 : 104;
        DrawChoices_Two(items[itemId].choiceNames, sel, y, active, leftX);
        break;
    }
    case 3:
        DrawChoices_Three(items[itemId].choiceNames, sel, y, active);
        break;
    case 4:
        DrawChoices_Four(items[itemId].choiceNames, sel, y, active);
        break;
    case 5:
        DrawChoices_Five(items[itemId].choiceNames, sel, y, active);
        break;
    case 6:
        DrawChoices_Six(items[itemId].choiceNames, sel, y, active);
        break;
    default:
    {
        const u8 *choiceStr = items[itemId].choiceNames[sel];
        u8 x = GetStringRightAlignXOffset(FONT_NORMAL, choiceStr, 198);
        DrawRightSideChoiceText(choiceStr, x, y + 1, TRUE, active);
        break;
    }
    }
}

// =============================================================================
// List menu init / teardown
// =============================================================================

static void InitListMenu(void)
{
    struct ListMenuTemplate template;
    const struct ChallengeMenuItem *items = GetCurrentTabItems();
    u8 count = GetCurrentTabItemCount();

    for (u8 i = 0; i < count; i++)
    {
        sListItems[i].name = items[i].name;
        sListItems[i].id = i;
    }

    memset(&template, 0, sizeof(template));
    template.items = sListItems;
    template.moveCursorFunc = ChallengeMenu_MoveCursorFunc;
    template.itemPrintFunc = ChallengeMenu_ItemPrintFunc;
    template.totalItems = count;
    template.maxShowed = (count < ITEMS_VISIBLE) ? count : ITEMS_VISIBLE;
    template.windowId = WIN_OPTIONS;
    template.header_X = 0;
    template.item_X = 8;
    template.cursor_X = 0;
    template.upText_Y = 1;
    template.cursorPal = TEXT_COLOR_OPTIONS_ORANGE_FG;
    template.fillValue = 1;
    template.cursorShadowPal = TEXT_COLOR_OPTIONS_ORANGE_SHADOW;
    template.lettersSpacing = 0;
    template.itemVerticalPadding = 0;
    template.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    template.fontId = FONT_NORMAL;
    template.cursorKind = CURSOR_INVISIBLE;

    sMenu->listTaskId = ListMenuInit(&template,
        sMenu->scrollOffset[sMenu->currentTab],
        sMenu->selectedRow[sMenu->currentTab]);

    HighlightRow();

    if (count > ITEMS_VISIBLE)
    {
        sMenu->arrowTaskId = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP, 240 / 2, 20, 110,
            count - ITEMS_VISIBLE,
            110, 110,
            &sMenu->scrollOffset[sMenu->currentTab]);
    }
    else
    {
        sMenu->arrowTaskId = TASK_NONE;
    }
}

static void DestroyCurrentListMenu(void)
{
    DestroyListMenuTask(sMenu->listTaskId,
        &sMenu->scrollOffset[sMenu->currentTab],
        &sMenu->selectedRow[sMenu->currentTab]);

    if (sMenu->arrowTaskId != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(sMenu->arrowTaskId);
        sMenu->arrowTaskId = TASK_NONE;
    }
}

// =============================================================================
// Drawing
// =============================================================================

static void DrawTopBar(void)
{
    const u8 color[3] = { TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_OPTIONS_WHITE, TEXT_COLOR_OPTIONS_GRAY_FG };
    const u8 *tabName = sTabs[sMenu->currentTab].tabName;
    int width = GetStringWidth(FONT_SMALL, tabName, 0) / 2;
    int right = 240 - GetStringWidth(FONT_SMALL, sText_TopBar_Right, 0) - 5;

    FillWindowPixelBuffer(WIN_TOPBAR, PIXEL_FILL(15));

    AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 120 - width, 1, color, 0, tabName);

    if (sMenu->currentTab > 0)
        AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 5, 1, color, 0, sText_TopBar_Left);
    if (sMenu->currentTab < TAB_COUNT - 1)
        AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, right, 1, color, 0, sText_TopBar_Right);

    PutWindowTilemap(WIN_TOPBAR);
    CopyWindowToVram(WIN_TOPBAR, COPYWIN_FULL);
}

static void DrawDescription(void)
{
    const u8 color[3] = { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_OPTIONS_GRAY_FG, TEXT_COLOR_OPTIONS_GRAY_SHADOW };
    u16 scrollOffset, selectedRow;
    ListMenuGetScrollAndRow(sMenu->listTaskId, &scrollOffset, &selectedRow);
    u8 itemIndex = scrollOffset + selectedRow;

    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(1));

    const struct ChallengeMenuItem *items = GetCurrentTabItems();
    if (itemIndex < GetCurrentTabItemCount() && items[itemIndex].descriptions != NULL)
    {
        u8 sel = *GetSelectionPtr(sMenu->currentTab, itemIndex);
        if (sel >= items[itemIndex].numChoices)
            sel = 0;
        const u8 *desc = items[itemIndex].descriptions[sel];
        if (desc != NULL)
        {
            AddTextPrinterParameterized4(WIN_DESCRIPTION, FONT_NORMAL,
                8, 1, 0, 0, color, TEXT_SKIP_DRAW, desc);
        }
    }

    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_FULL);
}

static void DrawBgFrames(void)
{
    // Outer frame — top edge at row 2, shared side edges rows 3-18
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  2,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  2, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  2,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  3,  1, 16,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  3,  1, 16,  7);

    // Horizontal divider between options and description (row 13 bottom / row 14 top)
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 13,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 13, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 13,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1, 14,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2, 14, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28, 14,  1,  1,  7);

    // Bottom edge at row 19
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 19,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 19, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 19,  1,  1,  7);

    CopyBgTilemapBufferToVram(1);
}

// =============================================================================
// Tab switching
// =============================================================================

static void SwitchTab(s8 direction)
{
    s8 newTab = sMenu->currentTab + direction;

    if (newTab < 0 || newTab >= TAB_COUNT)
        return;

    DestroyCurrentListMenu();
    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));

    sMenu->currentTab = newTab;

    InitListMenu();
    DrawTopBar();
    DrawDescription();
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);

    PlaySE(SE_SELECT);
}

// =============================================================================
// Input: cycle selection left/right
// =============================================================================

static void ProcessLeftRight(void)
{
    u16 scrollOffset, selectedRow;
    ListMenuGetScrollAndRow(sMenu->listTaskId, &scrollOffset, &selectedRow);
    u8 itemIndex = scrollOffset + selectedRow;

    const struct ChallengeMenuItem *items = GetCurrentTabItems();
    if (itemIndex >= GetCurrentTabItemCount())
        return;
    if (items[itemIndex].numChoices == 0)
        return;
    if (!CheckConditions(sMenu->currentTab, itemIndex))
        return;

    u8 *sel = GetSelectionPtr(sMenu->currentTab, itemIndex);
    u8 prev = *sel;

    if (JOY_NEW(DPAD_RIGHT))
    {
        if (*sel < items[itemIndex].numChoices - 1)
            (*sel)++;
        else
            *sel = 0;
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (*sel > 0)
            (*sel)--;
        else
            *sel = items[itemIndex].numChoices - 1;
    }

    if (*sel != prev)
    {
        // When GAMEMODE changes to RECOMMENDED, apply presets
        if (sMenu->currentTab == TAB_MODE && itemIndex == ITEM_MODE_GAMEMODE && *sel == 0)
            ApplyRecommendedPresets();

        // Nuzlocke OFF or EASY — reset sub-options to defaults
        if (sMenu->currentTab == TAB_NUZLOCKE && itemIndex == ITEM_NUZLOCKE_NUZLOCKE
            && (*sel == 0 || *sel == 1))
        {
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_SPECIES_CLAUSE) = 0; // ON
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_SHINY_CLAUSE)   = 0; // ON
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NICKNAMING)     = 0; // ON
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_DELETION)       = 0; // CEMETERY
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_RARE_CANDY)     = 1; // OFF
        }

        // Chaos ON — force Similar/Balancing to OFF (sel=1 in inverted ON/OFF display)
        if (sMenu->currentTab == TAB_RANDOMIZER && itemIndex == ITEM_RANDOM_CHAOS && *sel == 1)
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_SIMILAR) = 1;

        // Mirror OFF — force-clear Mirror Thief
        if (sMenu->currentTab == TAB_CHALLENGES && itemIndex == ITEM_CHALLENGES_MIRROR && *sel == 0)
            *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_MIRROR_THIEF) = 0;

        PlaySE(SE_SELECT);
        RedrawListMenu(sMenu->listTaskId);
        HighlightRow();
        CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
        DrawDescription();
    }
}

// =============================================================================
// Tasks
// =============================================================================

static void Task_FadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_ProcessInput;
}

static void Task_ProcessInput(u8 taskId)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        ProcessLeftRight();
        return;
    }

    if (JOY_NEW(L_BUTTON))
    {
        SwitchTab(-1);
        return;
    }

    if (JOY_NEW(R_BUTTON))
    {
        SwitchTab(+1);
        return;
    }

    s32 input = ListMenu_ProcessInput(sMenu->listTaskId);

    if (input == LIST_NOTHING_CHOSEN || input == LIST_CANCEL)
        return;

    if (sMenu->currentTab == TAB_CHALLENGES && (u32)input == ITEM_CHALLENGES_SAVE)
    {
        gTasks[taskId].func = Task_Save;
        return;
    }

    const struct ChallengeMenuItem *items = GetCurrentTabItems();
    if ((u32)input < GetCurrentTabItemCount()
        && items[input].numChoices == 0
        && sMenu->currentTab < TAB_COUNT - 1)
    {
        SwitchTab(+1);
    }
}

static void Task_Save(u8 taskId)
{
    struct ChallengeSettings *cs = &gSaveBlock3Ptr->challengeSettings;

    // Mode tab
    cs->tx_Mode_Modern_Moves       = *GetSelectionPtr(TAB_MODE, ITEM_MODE_MODERN_MOVES);
    cs->tx_Mode_Synchronize        = *GetSelectionPtr(TAB_MODE, ITEM_MODE_SYNCHRONIZE);
    cs->tx_Mode_Sturdy             = *GetSelectionPtr(TAB_MODE, ITEM_MODE_STURDY);
    cs->tx_Mode_New_Citrus         = *GetSelectionPtr(TAB_MODE, ITEM_MODE_NEW_CITRUS);
    cs->tx_Mode_Fairy_Types        = *GetSelectionPtr(TAB_MODE, ITEM_MODE_FAIRY_TYPES);
    cs->tx_Mode_Legendary_Abilities= *GetSelectionPtr(TAB_MODE, ITEM_MODE_LEGENDARY_ABILITIES);
    cs->tx_Mode_InfiniteTMs        = *GetSelectionPtr(TAB_MODE, ITEM_MODE_INFINITE_TMS);
    cs->tx_Mode_Mints              = *GetSelectionPtr(TAB_MODE, ITEM_MODE_MINTS);
    if (cs->tx_Mode_Mints)
        FlagClear(FLAG_MINTS_DISABLED);
    else
        FlagSet(FLAG_MINTS_DISABLED);
    cs->tx_Mode_PoisonSurvive      = *GetSelectionPtr(TAB_MODE, ITEM_MODE_SURVIVE_POISON);

    // Features tab
    cs->tx_Features_RTCType        = *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_RTC_TYPE);
    cs->tx_Features_ShinyChance    = *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_SHINY_CHANCE);
    cs->tx_Features_WildMonDropItems = *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_ITEM_DROP);
    cs->tx_Features_FrontierBans   = *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_FRONTIER_BANS);
    cs->tx_Features_ShinyColors    = *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_SHINY_COLOR);

    // Randomizer tab — if master toggle is OFF, clear all sub-fields
    if (*GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_OFF_ON) == 0)
    {
        cs->tx_Random_Starter          = 0;
        cs->tx_Random_WildPokemon      = 0;
        cs->tx_Random_MapBased         = 0;
        cs->tx_Random_Trainer          = 0;
        cs->tx_Random_Static           = 0;
        cs->tx_Random_Similar          = 0;
        cs->tx_Random_IncludeLegendaries = 0;
        cs->tx_Random_Type             = 0;
        cs->tx_Random_Moves            = 0;
        cs->tx_Random_Abilities        = 0;
        cs->tx_Random_Evolutions       = 0;
        cs->tx_Random_EvolutionMethods = 0;
        cs->tx_Random_TypeEffectiveness= 0;
        cs->tx_Random_Items            = 0;
        cs->tx_Random_Chaos            = 0;
    }
    else
    {
        cs->tx_Random_Starter          = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_STARTER);
        cs->tx_Random_WildPokemon      = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_WILD_PKMN);
        cs->tx_Random_MapBased         = cs->tx_Random_WildPokemon ? *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_MAP_BASED) : 0;
        cs->tx_Random_Trainer          = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TRAINER);
        cs->tx_Random_Static           = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_STATIC);
        cs->tx_Random_Similar          = !(*GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_SIMILAR));
        cs->tx_Random_IncludeLegendaries = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_LEGENDARIES);
        cs->tx_Random_Type             = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TYPE);
        cs->tx_Random_Moves            = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_MOVES);
        cs->tx_Random_Abilities        = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_ABILITIES);
        cs->tx_Random_Evolutions       = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_EVOLUTIONS);
        cs->tx_Random_EvolutionMethods = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_EVO_METHODS);
        cs->tx_Random_TypeEffectiveness= *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TYPE_EFFEC);
        cs->tx_Random_Items            = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_ITEMS);
        cs->tx_Random_Chaos            = *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_CHAOS);
    }

    // Nuzlocke tab — decompose selection back to 3 bits (matches HnS encoding)
    {
        u8 nuzSel = *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NUZLOCKE);
        cs->tx_Challenges_Nuzlocke         = (nuzSel >= 2) ? 1 : 0;
        cs->tx_Nuzlocke_EasyMode           = (nuzSel == 1) ? 1 : 0;
        cs->tx_Challenges_NuzlockeHardcore = (nuzSel == 3) ? 1 : 0;

        if (nuzSel == 0) // OFF — clear sub-options
        {
            cs->tx_Nuzlocke_SpeciesClause = 0;
            cs->tx_Nuzlocke_ShinyClause   = 0;
            cs->tx_Nuzlocke_Nicknaming    = 0;
        }
        else if (nuzSel == 1) // EASY — only RareCandy is saved
        {
            cs->tx_Nuzlocke_RareCandy = !(*GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_RARE_CANDY));
        }
        else // NORMAL or HARD — save all sub-options with polarity inversion
        {
            cs->tx_Nuzlocke_SpeciesClause = !(*GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_SPECIES_CLAUSE));
            cs->tx_Nuzlocke_ShinyClause   = !(*GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_SHINY_CLAUSE));
            cs->tx_Nuzlocke_Nicknaming    = !(*GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NICKNAMING));
            cs->tx_Nuzlocke_Deletion      = *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_DELETION);
            cs->tx_Nuzlocke_RareCandy     = !(*GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_RARE_CANDY));
        }
    }

    // Difficulty tab
    cs->tx_Challenges_PartyLimit      = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_PARTY_LIMIT);
    cs->tx_Challenges_LevelCap        = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_LEVEL_CAP);
    cs->tx_Challenges_ExpMultiplier   = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_EXP_MULTIPLIER);
    cs->tx_Challenges_NoItemPlayer    = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_ITEM_PLAYER);
    cs->tx_Challenges_NoItemTrainer   = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_ITEM_TRAINER);
    cs->tx_Challenges_NoEVs           = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_NO_EVS);
    cs->tx_Challenges_TrainerScalingIVs = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_SCALING_IVS);
    cs->tx_Challenges_TrainerScalingEVs = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_SCALING_EVS);
    cs->tx_Challenges_MaxPartyIVs     = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_MAX_PARTY_IVS);
    cs->tx_Challenges_LessEscapes     = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_LESS_ESCAPES);
    cs->tx_Difficulty_EscapeRopeDig   = *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_ESCAPE_ROPE_DIG);

    // Challenges tab
    cs->tx_Challenges_PkmnCenter      = *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_POKECENTER);
    cs->tx_Challenges_PCHeal          = *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_PCHEAL);
    cs->tx_Challenges_Expensive       = *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_EXPENSIVE);
    cs->tx_Challenges_EvoLimit        = *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_EVO_LIMIT);
    // ONE_TYPE: map selection position back to type index
    {
        u8 otSel = *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_ONE_TYPE);
        static const u8 sValidTypes[] = {
            TYPE_NORMAL, TYPE_FIGHTING, TYPE_FLYING, TYPE_POISON, TYPE_GROUND,
            TYPE_ROCK, TYPE_BUG, TYPE_GHOST, TYPE_STEEL, TYPE_FIRE, TYPE_WATER,
            TYPE_GRASS, TYPE_ELECTRIC, TYPE_PSYCHIC, TYPE_ICE, TYPE_DRAGON,
            TYPE_DARK, TYPE_FAIRY,
        };
        if (otSel > 18)
            cs->tx_Challenges_OneTypeChallenge = ONE_TYPE_OFF;
        else if (otSel == 18)
            cs->tx_Challenges_OneTypeChallenge = sValidTypes[Random() % ARRAY_COUNT(sValidTypes)];
        else if (otSel >= 9)
            cs->tx_Challenges_OneTypeChallenge = otSel + 2;
        else
            cs->tx_Challenges_OneTypeChallenge = otSel + 1;
    }
    cs->tx_Challenges_BaseStatEqualizer = *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_BST_EQUALIZER);
    cs->tx_Challenges_Mirror          = *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_MIRROR);
    cs->tx_Challenges_Mirror_Thief    = *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_MIRROR_THIEF);

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_FadeOut;
}

static void Task_FadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyCurrentListMenu();
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        FREE_AND_SET_NULL(sMenu);
        SetMainCallback2(gMain.savedCallback);
    }
}

// =============================================================================
// Init
// =============================================================================

void CB2_InitChallengeMenu(void)
{
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        ResetBgPositions();
        InitWindows(sWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(16, 224));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(24, 104));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN1_BG0 | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
        gMain.state++;
        break;
    case 4:
        LoadPalette(sBgPal, 0, sizeof(sBgPal));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 0x70, 0x20);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sTextPal, 16, sizeof(sTextPal));
        gMain.state++;
        break;
    case 6:
        sMenu = AllocZeroed(sizeof(struct ChallengeMenuState));
        sMenu->currentTab = TAB_MODE;
        sMenu->arrowTaskId = TASK_NONE;

        {
            struct ChallengeSettings *cs = &gSaveBlock3Ptr->challengeSettings;

            // Mode tab — GAMEMODE always starts as RECOMMENDED (matches HnS)
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_GAMEMODE) = 0;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_MODERN_MOVES)       = cs->tx_Mode_Modern_Moves;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_SYNCHRONIZE)        = cs->tx_Mode_Synchronize;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_STURDY)             = cs->tx_Mode_Sturdy;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_NEW_CITRUS)         = cs->tx_Mode_New_Citrus;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_FAIRY_TYPES)        = cs->tx_Mode_Fairy_Types;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_LEGENDARY_ABILITIES)= cs->tx_Mode_Legendary_Abilities;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_INFINITE_TMS)       = cs->tx_Mode_InfiniteTMs;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_MINTS)              = cs->tx_Mode_Mints;
            *GetSelectionPtr(TAB_MODE, ITEM_MODE_SURVIVE_POISON)     = cs->tx_Mode_PoisonSurvive;

            // Features tab
            *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_RTC_TYPE)     = cs->tx_Features_RTCType;
            *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_SHINY_CHANCE) = cs->tx_Features_ShinyChance;
            *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_ITEM_DROP)    = cs->tx_Features_WildMonDropItems;
            *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_FRONTIER_BANS)= cs->tx_Features_FrontierBans;
            *GetSelectionPtr(TAB_FEATURES, ITEM_FEATURES_SHINY_COLOR)  = cs->tx_Features_ShinyColors;

            // Randomizer tab — derive master toggle from individual fields
            bool8 anyRandom = cs->tx_Random_WildPokemon || cs->tx_Random_Starter
                || cs->tx_Random_MapBased || cs->tx_Random_Trainer || cs->tx_Random_Static
                || cs->tx_Random_Similar || cs->tx_Random_IncludeLegendaries || cs->tx_Random_Type
                || cs->tx_Random_Moves || cs->tx_Random_Abilities || cs->tx_Random_Evolutions
                || cs->tx_Random_EvolutionMethods || cs->tx_Random_TypeEffectiveness
                || cs->tx_Random_Items || cs->tx_Random_Chaos;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_OFF_ON)      = anyRandom ? 1 : 0;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_STARTER)     = cs->tx_Random_Starter;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_WILD_PKMN)   = cs->tx_Random_WildPokemon;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_MAP_BASED)  = cs->tx_Random_MapBased;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TRAINER)     = cs->tx_Random_Trainer;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_STATIC)      = cs->tx_Random_Static;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_SIMILAR)     = !cs->tx_Random_Similar;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_LEGENDARIES) = cs->tx_Random_IncludeLegendaries;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TYPE)        = cs->tx_Random_Type;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_MOVES)       = cs->tx_Random_Moves;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_ABILITIES)   = cs->tx_Random_Abilities;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_EVOLUTIONS)  = cs->tx_Random_Evolutions;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_EVO_METHODS) = cs->tx_Random_EvolutionMethods;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_TYPE_EFFEC)  = cs->tx_Random_TypeEffectiveness;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_ITEMS)       = cs->tx_Random_Items;
            *GetSelectionPtr(TAB_RANDOMIZER, ITEM_RANDOM_CHAOS)       = cs->tx_Random_Chaos;

            // Nuzlocke tab — 3 bits → 4 selection states (matches HnS encoding)
            if (cs->tx_Challenges_Nuzlocke && cs->tx_Challenges_NuzlockeHardcore)
                *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NUZLOCKE) = 3; // HARD
            else if (cs->tx_Challenges_Nuzlocke)
                *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NUZLOCKE) = 2; // NORMAL
            else if (cs->tx_Nuzlocke_EasyMode)
                *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NUZLOCKE) = 1; // EASY
            else
                *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NUZLOCKE) = 0; // OFF
            // Polarity inversion: SaveBlock 1 = active, UI 0 = ON
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_SPECIES_CLAUSE) = !cs->tx_Nuzlocke_SpeciesClause;
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_SHINY_CLAUSE)   = !cs->tx_Nuzlocke_ShinyClause;
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_NICKNAMING)     = !cs->tx_Nuzlocke_Nicknaming;
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_DELETION)       = cs->tx_Nuzlocke_Deletion;
            *GetSelectionPtr(TAB_NUZLOCKE, ITEM_NUZLOCKE_RARE_CANDY)     = !cs->tx_Nuzlocke_RareCandy;

            // Difficulty tab
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_PARTY_LIMIT)    = cs->tx_Challenges_PartyLimit;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_LEVEL_CAP)      = cs->tx_Challenges_LevelCap;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_EXP_MULTIPLIER) = cs->tx_Challenges_ExpMultiplier;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_ITEM_PLAYER)    = cs->tx_Challenges_NoItemPlayer;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_ITEM_TRAINER)   = cs->tx_Challenges_NoItemTrainer;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_NO_EVS)         = cs->tx_Challenges_NoEVs;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_SCALING_IVS)    = cs->tx_Challenges_TrainerScalingIVs;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_SCALING_EVS)    = cs->tx_Challenges_TrainerScalingEVs;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_MAX_PARTY_IVS)  = cs->tx_Challenges_MaxPartyIVs;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_LESS_ESCAPES)   = cs->tx_Challenges_LessEscapes;
            *GetSelectionPtr(TAB_DIFFICULTY, ITEM_DIFFICULTY_ESCAPE_ROPE_DIG)= cs->tx_Difficulty_EscapeRopeDig;

            // Challenges tab
            *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_POKECENTER)    = cs->tx_Challenges_PkmnCenter;
            *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_PCHEAL)        = cs->tx_Challenges_PCHeal;
            *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_EXPENSIVE)     = cs->tx_Challenges_Expensive;
            *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_EVO_LIMIT)     = cs->tx_Challenges_EvoLimit;
            // ONE_TYPE: map SaveBlock type index to selection position
            {
                u8 typeVal = cs->tx_Challenges_OneTypeChallenge;
                u8 oneTypeSel;
                if (typeVal >= ONE_TYPE_OFF || typeVal == TYPE_NONE || typeVal == TYPE_MYSTERY || typeVal == TYPE_STELLAR)
                    oneTypeSel = 19; // OFF
                else if (typeVal <= TYPE_STEEL)
                    oneTypeSel = typeVal - 1; // types 1-9 → sel 0-8
                else
                    oneTypeSel = typeVal - 2; // types 11-19 → sel 9-17
                *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_ONE_TYPE) = oneTypeSel;
            }
            *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_BST_EQUALIZER) = cs->tx_Challenges_BaseStatEqualizer;
            *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_MIRROR)        = cs->tx_Challenges_Mirror;
            *GetSelectionPtr(TAB_CHALLENGES, ITEM_CHALLENGES_MIRROR_THIEF)  = cs->tx_Challenges_Mirror_Thief;
        }

        gMain.state++;
        break;
    case 7:
        PutWindowTilemap(WIN_TOPBAR);
        PutWindowTilemap(WIN_OPTIONS);
        PutWindowTilemap(WIN_DESCRIPTION);
        DrawTopBar();
        DrawBgFrames();
        InitListMenu();
        DrawDescription();
        CopyWindowToVram(WIN_TOPBAR, COPYWIN_FULL);
        CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
        CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_FULL);
        gMain.state++;
        break;
    case 8:
        CreateTask(Task_FadeIn, 0);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        break;
    }
}

// =============================================================================
// Script entry point (for callnative)
// =============================================================================

void Script_OpenChallengeMenu(struct ScriptContext *ctx)
{
    gMain.savedCallback = CB2_ReturnToFieldWithOpenMenu;
    SetMainCallback2(CB2_InitChallengeMenu);
}

bool32 HMsOverwriteOptionActive(void)
{
    struct ChallengeSettings *cs = &gSaveBlock3Ptr->challengeSettings;
    return (cs->tx_Challenges_Nuzlocke
            || cs->tx_Challenges_Mirror
            || cs->tx_Random_Moves
            || cs->tx_Challenges_OneTypeChallenge != ONE_TYPE_OFF);
}
