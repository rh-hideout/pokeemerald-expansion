#ifndef GUARD_POKEDEX_H
#define GUARD_POKEDEX_H

#include "bg.h"
#include "window.h"

extern u8 gUnusedPokedexU8;
extern void (*gPokedexVBlankCB)(void);

void ResetPokedex(void);
u16 GetNationalPokedexCount(u8 caseID);
u32 GetRegionalPokedexCount(u8 caseID);
u16 GetHoennPokedexCount(u8 caseID);
u16 GetKantoPokedexCount(u8 caseID);
u8 DisplayCaughtMonDexPage(enum Species species, bool32 isShiny, u32 personality);
u32 Pokedex_CreateCaughtMonSprite(enum Species species, s32 x, s32 y);
s8 GetSetPokedexFlag(enum NationalDexOrder nationalDexNo, u8 caseID);
void DrawFootprint(u8 windowId, enum Species species);
u16 CreateMonSpriteFromNationalDexNumber(enum NationalDexOrder nationalNum, s16 x, s16 y, u16 paletteSlot);
bool16 HasAllRegionalMons(void);
bool16 HasAllHoennMons(void);
bool16 HasAllKantoMons(void);
void ResetPokedexScrollPositions(void);
bool16 HasAllMons(void);
void CB2_OpenPokedex(void);
void PrintMonMeasurements(enum Species species, u32 owned);
u8* ConvertMonHeightToString(u32 height);
u8* ConvertMonWeightToString(u32 weight);

// Common Pokédex Definitions and Functions
enum
{
    PAGE_MAIN,
    PAGE_INFO,
    PAGE_SEARCH,
    PAGE_SEARCH_RESULTS,
    PAGE_UNK,
    PAGE_AREA,
    PAGE_CRY,
    PAGE_SIZE
};

enum
{
    AREA_SCREEN,
    CRY_SCREEN,
    SIZE_SCREEN,
    CANCEL_SCREEN,
    SCREEN_COUNT,
    INFO_SCREEN = SCREEN_COUNT,
    STATS_SCREEN,
    EVO_SCREEN,
    FORMS_SCREEN,
};

enum
{
    SEARCH_NAME,
    SEARCH_COLOR,
    SEARCH_TYPE_LEFT,
    SEARCH_TYPE_RIGHT,
    SEARCH_ORDER,
    SEARCH_MODE,
    SEARCH_OK,
    SEARCH_COUNT
};

enum
{
    SEARCH_TOPBAR_SEARCH,
    SEARCH_TOPBAR_SHIFT,
    SEARCH_TOPBAR_CANCEL,
    SEARCH_TOPBAR_COUNT
};

enum
{
   ORDER_NUMERICAL,
   ORDER_ALPHABETICAL,
   ORDER_HEAVIEST,
   ORDER_LIGHTEST,
   ORDER_TALLEST,
   ORDER_SMALLEST
};

enum
{
    NAME_ABC = 1,
    NAME_DEF,
    NAME_GHI,
    NAME_JKL,
    NAME_MNO,
    NAME_PQR,
    NAME_STU,
    NAME_VWX,
    NAME_YZ,
};

enum
{
    WIN_INFO,
    WIN_FOOTPRINT,
    WIN_CRY_WAVE,
    WIN_VU_METER,
    WIN_NAVIGATION_BUTTONS,
};

// For scrolling search parameter
#define MAX_SEARCH_PARAM_ON_SCREEN      6
#define MAX_SEARCH_PARAM_CURSOR_POS     (MAX_SEARCH_PARAM_ON_SCREEN - 1)

#define LIST_SCROLL_STEP                16

#define POKEBALL_ROTATION_TOP           64
#define POKEBALL_ROTATION_BOTTOM        (POKEBALL_ROTATION_TOP - 16)

#define MAX_MONS_ON_SCREEN              4

// Coordinates of the Pokémon sprite on its page (info/cry screens)
#define MON_PAGE_X                      48
#define MON_PAGE_Y                      56

// Number of background templates in different screens.
#define NUM_POKEDEX_BG_TEMPLATES        4
#define NUM_INFO_SCREEN_BG_TEMPLATES    4
#define NUM_NEW_ENTRY_INFO_BG_TEMPLATES 2
#define NUM_SEARCH_MENU_BG_TEMPLATES    4

// Tile and pal tag used for all interface sprites.
#define TAG_DEX_INTERFACE               4096

struct PokedexListItem
{
    u16 dexNum;
    u16 seen:1;
    u16 owned:1;
};

struct PokemonStats
{
    enum Species species;
    u8 genderRatio;
    u8 baseHP;
    u8 baseSpeed;
    u8 baseAttack;
    u8 baseSpAttack;
    u8 baseDefense;
    u8 baseSpDefense;
    u8 differentEVs;
    u8 evYield_HP;
    u8 evYield_Speed;
    u8 evYield_Attack;
    u8 evYield_SpAttack;
    u8 evYield_Defense;
    u8 evYield_SpDefense;
    u8 catchRate;
    enum GrowthRate growthRate:8;
    u8 eggGroup1;
    u8 eggGroup2;
    u8 eggCycles;
    u16 expYield;
    u8 friendship;
    enum Ability ability0;
    enum Ability ability1;
    enum Ability abilityHidden;
};

struct EvoScreenData
{
    bool8 fromEvoPage;
    u8 numAllEvolutions;
    enum Species targetSpecies[10];
    u8 numSeen;
    bool8 seen[10];
    u8 menuPos;
    u8 arrowSpriteId;
    bool8 isMega;
    u32 arrowSpriteDist[10];
};

struct FromScreenData
{
    u8 numForms;
    u16 formIds[30];
    bool8 inSubmenu;
    u8 menuPos;
    u8 arrowSpriteId;
};

struct PokedexView
{
    struct PokedexListItem pokedexList[NATIONAL_DEX_COUNT + 1];
    u16 pokemonListCount;
    u16 selectedPokemon;
    u16 selectedPokemonBackup;
    u16 dexMode;
    u16 dexModeBackup;
    u16 dexOrder;
    u16 dexOrderBackup;
    u16 seenCount;
    u16 ownCount;
    u16 monSpriteIds[MAX_MONS_ON_SCREEN];
    u16 selectedMonSpriteId;
    u16 pokeBallRotationStep;
    u16 pokeBallRotationBackup;
    u8 pokeBallRotation;
    u8 initialVOffset;
    u8 scrollTimer;
    u8 scrollDirection;
    s16 listVOffset;
    s16 listMovingVOffset;
    u16 scrollMonIncrement;
    u16 maxScrollTimer;
    u16 scrollSpeed;
    u16 unkArr1[4]; // Cleared, never read
    u8 filler[8];
    u8 currentPage;
    u8 currentPageBackup;
    bool8 isSearchResults:1;
    u8 selectedScreen;
    u8 screenSwitchState;
    u8 menuIsOpen;
    u16 menuCursorPos;
    s16 menuY;     //Menu Y position (inverted because we use REG_BG0VOFS for this)
    u8 unkArr2[8]; // Cleared, never read
    u8 unkArr3[8]; // Cleared, never read

    // HGSS
    u16 originalSearchSelectionNum;
    u8 typeIconSpriteIds[2];
    u16 moveSelected;
    u16 movesTotal;
    u8 statBarsSpriteId;
    u8 statBarsBgSpriteId;
    bool8 justScrolled;
    u8 categoryIconSpriteId; //Physical/Special/Status category
    u8 numEggMoves;
    u8 numLevelUpMoves;
    u16 numTeachableMoves;
    u8 numPreEvolutions;
    struct PokemonStats sPokemonStats;
    struct EvoScreenData sEvoScreenData;
    struct FromScreenData sFormScreenData;
    enum Species formSpecies;
};

extern const struct SpriteTemplate sScrollBarSpriteTemplate;
extern const struct SpriteTemplate sScrollArrowSpriteTemplate;
extern const struct SpriteTemplate sSeenOwnTextSpriteTemplate;
extern const struct SpriteTemplate sHoennNationalTextSpriteTemplate;
extern const struct SpriteTemplate sHoennDexSeenOwnNumberSpriteTemplate;
extern const struct SpriteTemplate sNationalDexSeenOwnNumberSpriteTemplate;
extern const struct SpriteTemplate sDexListStartMenuCursorSpriteTemplate;

extern const struct BgTemplate sSearchMenu_BgTemplate[NUM_SEARCH_MENU_BG_TEMPLATES];
extern const struct WindowTemplate sSearchMenu_WindowTemplate[];
extern const u8 sScrollMonIncrements[];
extern const u8 sScrollTimers[];
extern const struct BgTemplate sPokedex_BgTemplate[NUM_POKEDEX_BG_TEMPLATES];
extern const struct WindowTemplate sPokemonList_WindowTemplate[];
extern const struct BgTemplate sInfoScreen_BgTemplate[NUM_INFO_SCREEN_BG_TEMPLATES];
extern const struct BgTemplate sNewEntryInfoScreen_BgTemplate[NUM_NEW_ENTRY_INFO_BG_TEMPLATES];

void VBlankCB_Pokedex(void);
void CB2_Pokedex(void);

void Task_OpenPokedexMainPage(u8);
void Task_HandlePokedexInput(u8);
void Task_OpenInfoScreenAfterMonMovement(u8);
u8 LoadInfoScreen(struct PokedexListItem *, u8 monSpriteId);
void Task_LoadInfoScreen(u8 taskId);

void ResetPokedexView(struct PokedexView *pokedexView);
void HighlightSelectedSearchMenuItem(u8 topBarItem, u8 menuItem);
void DrawSearchMenuItemBgHighlight(u8 searchBg, bool8 unselected, bool8 disabled);
void Task_SelectSearchMenuItem(u8 taskId);
void Task_HandleSearchParameterInput(u8);
void PrintSearchParameterText(u8 taskId);
u8 GetSearchModeSelection(u8 taskId, u8 option);
bool8 SearchParamCantScrollUp(u8 taskId);
bool8 SearchParamCantScrollDown(u8 taskId);
void SetInitialSearchMenuBgHighlights(u8 topBarItem);
void HighlightSelectedSearchTopBarItem(u8 topBarItem);
void PrintSelectedSearchParameters(u8 taskId);
void Task_HandleSearchMenuInput(u8 taskId);
void Task_StartPokedexSearch(u8 taskId);
void CreatePokedexList(u8, u8);

void Task_ClosePokedex(u8);
void CreateMonSpritesAtPos(u16, u16);
void UpdateSelectedMonSpriteId(void);
void SpriteCB_MoveMonForInfoScreen(struct Sprite *sprite);
void Task_SwitchToSearchMenuTopBar(u8);

void Task_LoadCryScreen(u8);
void Task_LoadSizeScreen(u8);
void Task_LoadAreaScreen(u8 taskId);

void Task_SwitchScreensFromInfoScreen(u8);
void Task_HandleSizeScreenInput(u8);

void CreateCaughtBall(u16, u8, u8, u16);
void ClearMonListEntry(u8 x, u8 y, u16 unused);

void Task_LoadInfoScreenWaitForFade(u8);
void FreeInfoScreenWindowAndBgBuffers(void);
void Task_ExitInfoScreen(u8 taskId);
void PrintInfoScreenText(const u8 *str, u8 left, u8 top);
void Task_HandleInfoScreenInput(u8 taskId);
void Task_HandleCryScreenInput(u8);

void Task_ReloadAreaScreen(u8 taskId);
void Task_WaitForAreaScreenInput(u8 taskId);

void Task_HandleCaughtMonPageInput(u8 taskId);

void CreateMonDexNum(u16 entryNum, u8 left, u8 top, u16 unused);
u8 CreateMonName(u16 num, u8 left, u8 top);

void ResetOtherVideoRegisters(u16);
u8 PrintCryScreenSpeciesName(u8, u16, u8, u8);

enum Species NationalPokedexNumToSpeciesForm(enum NationalDexOrder nationalNum);

void SetDefaultSearchModeAndOrder(u8);

#endif // GUARD_POKEDEX_H
