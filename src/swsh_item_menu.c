#include "global.h"
#include "item_menu.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_pyramid.h"
#include "frontier_util.h"
#include "battle_pyramid_bag.h"
#include "berry.h"
#include "berry_tag_screen.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "item_menu_icons.h"
#include "item_use.h"
#include "lilycove_lady.h"
#include "list_menu.h"
#include "link.h"
#include "mail.h"
#include "malloc.h"
#include "map_name_popup.h"
#include "menu.h"
#include "money.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "player_pc.h"
#include "pokemon.h"
#include "pokemon_summary_screen.h"
#include "scanline_effect.h"
#include "script.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "menu_helpers.h"
#include "window.h"
#include "apprentice.h"
#include "battle_pike.h"
#include "comfy_anim.h"
#if SWSH_ITEM_MENU_TMHM_CONTEST_INFO
#include "contest.h"
#include "contest_effect.h"
#endif
#include "dma3.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#if SWSH_ITEM_MENU
#include "battle_interface.h"
#include "pokemon_icon.h"
#endif
#if SWSH_ITEM_MENU_ACTION_IN_BAG
#include "caps.h"
#include "evolution_scene.h"
#include "menu_specialized.h"
#endif

#if SWSH_ITEM_MENU

#define TAG_POCKET_SCROLL_ARROW  110
#define TAG_BAG_SCROLL_ARROW     111
#define TAG_ITEM_CURSOR          112
#define TAG_HOVER_SLOT           113
#define TAG_BAG_SCROLL_THUMB     114
#define TAG_MOVE_TYPE_ICON       115
#define TAG_CATEGORY_ICON        116
#define TAG_BERRY_FLAVOR_MARK    117
#define TAG_SWAP_CURSOR          118
#define TAG_FRAME_MONEY          119
#define TAG_FRAME_PRICE_QUANTITY 120

#define HOVER_SLOT_SPRITES_COUNT     5
#define FRAME_MONEY_SPRITES_COUNT    3
#define FRAME_PRICE_SPRITES_COUNT    3
#define FRAME_QUANTITY_SPRITES_COUNT 2

// The buffer for the bag item list needs to be large enough to hold the maximum
// number of item slots that could fit in a single pocket, + 1 for Cancel.
// This constant picks the max of the existing pocket sizes.
// By default, the largest pocket is BAG_TMHM_COUNT at 64.
#define MAX_POCKET_ITEMS  ((max(BAG_TMHM_COUNT,              \
                            max(BAG_BERRIES_COUNT,           \
                            max(BAG_ITEMS_COUNT,             \
                            max(BAG_KEYITEMS_COUNT,          \
                                BAG_POKEBALLS_COUNT))))) + 1)

// Up to 8 item slots can be visible at a time
#define MAX_ITEMS_SHOWN 6

enum {
    SWITCH_POCKET_NONE,
    SWITCH_POCKET_LEFT,
    SWITCH_POCKET_RIGHT
};

enum {
    ACTION_USE,
    ACTION_TOSS,
    ACTION_REGISTER,
    ACTION_GIVE,
    ACTION_CANCEL,
    ACTION_BATTLE_USE,
    ACTION_CHECK,
    ACTION_WALK,
    ACTION_DESELECT,
    ACTION_CHECK_TAG,
    ACTION_CONFIRM,
    ACTION_SHOW,
    ACTION_GIVE_FAVOR_LADY,
    ACTION_CONFIRM_QUIZ_LADY,
    ACTION_BY_NAME,
    ACTION_BY_TYPE,
    ACTION_BY_AMOUNT,
    ACTION_BY_INDEX,
    ACTION_DUMMY,
};

enum {
    WIN_ITEM_LIST,
    WIN_DESCRIPTION,
    WIN_POCKET_NAME,
    WIN_PP_LABEL,
    WIN_POW_ACC_LABEL,
    WIN_PP_INFO,
    WIN_POW_ACC_INFO,
    WIN_SELECT_PROMPT,
#if SWSH_ITEM_MENU_TMHM_CONTEST_INFO
    WIN_APP_JAM_LABEL,
#endif
    WIN_MESSAGE, // Identical to ITEMWIN_MESSAGE. Unused?
#if SWSH_ITEM_MENU_BERRY_INFO
    WIN_BERRY_INFO,
    WIN_BERRY_FLAVORS,
#endif
};

// Item list ID for toSwapPos to indicate an item is not currently being swapped
#define NOT_SWAPPING 0xFF

struct ListBuffer1 {
    struct ListMenuItem subBuffers[MAX_POCKET_ITEMS];
};

struct ListBuffer2 {
    u8 name[MAX_POCKET_ITEMS][max(ITEM_NAME_LENGTH, MOVE_NAME_LENGTH) + 15];
};

struct TempWallyBag {
    struct ItemSlot bagPocket_Items[BAG_ITEMS_COUNT];
    struct ItemSlot bagPocket_PokeBalls[BAG_POKEBALLS_COUNT];
    u16 cursorPosition[POCKETS_COUNT];
    u16 scrollPosition[POCKETS_COUNT];
    u16 unused;
    u16 pocket;
};
#if SWSH_ITEM_MENU_ACTION_IN_BAG
struct BagRareCandyState {
    u8 slot;
    u8 initialLevel;
    u8 finalLevel;
    u8 learnMoveLevel;
    bool8 firstMoveAtLevel;
    s16 statsBefore[NUM_STATS];
    s16 statsAfter[NUM_STATS];
    u8 reentryPhase;
    enum Move moveToLearn;
    enum Species evolutionTarget;
    bool8 canStopEvolution;
    MainCallback savedExitCallback;
};
#endif // SWSH_ITEM_MENU_ACTION_IN_BAG

static void CB2_Bag(void);
static bool8 SetupBagMenu(void);
static void BagMenu_InitBGs(void);
static bool8 LoadBagMenu_Graphics(void);
static void LoadBagMenuTextWindows(void);
static void AllocateBagItemListBuffers(void);
static void LoadBagItemListBuffers(u8);
static void PrintPocketName(const u8 *);
static void DrawItemListBgRow(u8);
static void SpriteCB_SlideCursorY(struct Sprite *);
static void SpriteCB_BagScrollThumb(struct Sprite *);
static void SpriteCB_PocketScrollArrow(struct Sprite *);
static void CreateCursorSprite(void);
static void CreateHoverSlotSprites(void);
static void CreateScrollThumbSprite(void);
static void CreatePocketScrollArrowPair(void);
static void SpriteCB_MoveTypeIcon(struct Sprite *);
static void SwitchMoveInfoMode(s32);
#if SWSH_ITEM_MENU_BERRY_INFO
static void SwitchBerryInfoMode(s32);
static void UpdateBerryInfo(s32);
static void PrintBerryDescriptionInfo(s32);
#endif
static void UpdateMoveBattleInfo(s32);
static void ShowInfoPrompt(const u8 *);
#if SWSH_ITEM_MENU_TMHM_CONTEST_INFO
static void UpdateMoveContestInfo(s32);
static void PrintContestDescription(s32);
#endif
static bool8 IsWallysBag(void);
static void Task_WallyTutorialBagMenu(u8);
static void Task_BagMenu_HandleInput(u8);
static void GetItemNameFromPocket(u8 *dest, enum Item itemId);
static void PrintItemDescription(int);
static u8 FormatDescriptionByWidth(u8 *, s32, u8, const u8 *, s16);
static void BagMenu_PrintCursorAtPos(u8, u8);
static void BagMenu_Print(u8, u8, const u8 *, u8, u8, u8, u8, u8, u8);
static void Task_CloseBagMenu(u8);
static u8 AddItemMessageWindow(u8);
static void RemoveItemMessageWindow(u8);
static void ReturnToItemList(u8);
static void PrintItemQuantity(u8, s16);
static u8 BagMenu_AddWindow(u8);
static u8 GetSwitchBagPocketDirection(void);
static void SwitchBagPocket(u8, s16, bool16);
static bool8 CanSwapItems(void);
static void StartItemSwap(u8 taskId);
static void Task_SwitchBagPocket(u8);
static void Task_HandleSwappingItemsInput(u8);
static void PrintContextMenuItems(u8);
static void PrintContextMenuItemGrid(u8, u8, u8);
static void Task_ItemContext_SingleRow(u8);
static void Task_ItemContext_MultipleRows(u8);
static bool8 IsValidContextMenuPos(s8);
static void BagMenu_RemoveWindow(u8);
static void PrintThereIsNoPokemon(u8);
static void Task_ChooseHowManyToToss(u8);
static void AskTossItems(u8);
static void Task_RemoveItemFromBag(u8);
static void Task_TossItemFromBag(u8 taskId);
static void ItemMenu_Cancel(u8);
static void HandleErrorMessage(u8);
static void PrintItemCantBeHeld(u8);
static u8 BagMenu_AddWindowNoFrame(u8 windowType);
static void CreateQuantityFrameSprites(void);
static void DestroyQuantityFrameSprites(void);
static void SetupSellWindows(void);
static void PrintSellPrice(u16 itemId, int qty);
static void PrintQuantity(u8 windowId, s16 quantity);
static void PrintMoney(u8 windowId);
static void UpdateSellPrice(u16 itemId);
static void DisplaySellItemPriceAndConfirm(u8);
static void InitSellHowManyInput(u8);
static void AskSellItems(u8);
static void Task_ChooseHowManyToSell(u8);
static void SellItem(u8);
static void WaitAfterItemSell(u8);
static void TryDepositItem(u8);
static void Task_ChooseHowManyToDeposit(u8 taskId);
static void WaitDepositErrorMessage(u8);
static void CB2_ApprenticeExitBagMenu(void);
static void CB2_FavorLadyExitBagMenu(void);
static void CB2_QuizLadyExitBagMenu(void);
static void UpdatePocketItemLists(void);
static void InitPocketListPositions(void);
static void InitPocketScrollPositions(void);
static u8 CreateBagInputHandlerTask(u8);
static void BagMenu_MoveCursorCallback(s32, bool8, struct ListMenu *);
static void BagMenu_ItemPrintCallback(u8, u32, u8);
static void ItemMenu_UseOutOfBattle(u8);
static void ItemMenu_Toss(u8);
static void ItemMenu_Register(u8);
static void ItemMenu_Give(u8);
static void ItemMenu_Cancel(u8);
static void ItemMenu_UseInBattle(u8);
static void ItemMenu_CheckTag(u8);
static void ItemMenu_Show(u8);
static void ItemMenu_GiveFavorLady(u8);
static void ItemMenu_ConfirmQuizLady(u8);
static void Task_ItemContext_Normal(u8);
static void Task_ItemContext_GiveToParty(u8);
static void Task_ItemContext_Sell(u8);
static void Task_ItemContext_Deposit(u8);
static void Task_ItemContext_GiveToPC(u8);
static void ConfirmToss(u8);
static void CancelToss(u8);
static void ConfirmSell(u8);
static void CancelSell(u8);
static void Task_FadeAndCloseBagMenuIfMulch(u8 taskId);
static void BagMenu_DrawPartySlots(void);
static void BagMenu_CreatePartyIcons(void);
static void BagMenu_FreePartyIcons(void);
#if SWSH_ITEM_MENU_ACTION_IN_BAG
static void Task_BagMenu_PartyPanelInput(u8);
static void BagMenu_ClosePartyPanelSelect(u8);
static void Task_BagMenu_PartyPanelStayAfterMessage(u8);
static void Task_BagMenu_PartyPanelAfterItemUse(u8);
static void BagMenu_ApplySacredAsh(u8);
static void Task_BagMenu_SacredAshMessages(u8);
static void BagMenu_ShowPPMoveSelectWindow(u8);
static void Task_BagMenu_PPMoveSelectInput(u8);
static void BagMenu_ApplyPPToMove(u8, u8);
static void BagMenu_DispatchApplyItem(u8);
static void BagMenu_ApplyMedicine(u8);
static void BagMenu_ApplyResetEVs(u8);
static void BagMenu_ApplyDynamaxCandy(u8);
static void BagMenu_ApplyReduceEV(u8);
static void BagMenu_ApplyAbilityCapsule(u8);
static void BagMenu_ApplyAbilityPatch(u8);
static void BagMenu_ApplyMint(u8);
static void Task_BagMenu_AbilityChangeYesNo(u8);
static void BagMenu_AbilityChangeYes(u8);
static void BagMenu_AbilityChangeNo(u8);
static void Task_BagMenu_MintYesNo(u8);
static void BagMenu_MintYes(u8);
static void BagMenu_MintNo(u8);
static void BagMenu_ApplyRareCandy(u8);
static void Task_BagMenu_RareCandyWaitLvUpMsg(u8);
static void Task_BagMenu_RareCandyStatsPg1(u8);
static void Task_BagMenu_RareCandyStatsPg2(u8);
static void BagMenu_RareCandyDoLearnMoveStep(u8);
static void Task_BagMenu_RareCandyMoveLearned(u8);
static void Task_BagMenu_RareCandyMoveLearned2(u8);
static void Task_BagMenu_RareCandyReplaceYesNo(u8);
static void BagMenu_RareCandyReplaceYes(u8);
static void BagMenu_RareCandyReplaceNo(u8);
static void Task_BagMenu_RareCandyGoToSummary(u8);
static void Task_BagMenu_RareCandyAfterNotLearned(u8);
static void BagMenu_CB2_SummaryForMoveForget(void);
static void BagMenu_CB2_ReturnFromMoveForget(void);
static void Task_BagMenu_RareCandyReentry(u8);
static void Task_BagMenu_RareCandyAfterMoveForget(u8);
static void Task_BagMenu_RareCandyAfterForgotMove(u8);
static void BagMenu_RareCandyTryEvolution(u8);
static void BagMenu_CB2_DoBeginEvolution(void);
static void BagMenu_CB2_AfterRareCandyEvolution(void);
static void BagMenu_RareCandyCleanupAndReturn(u8);
#endif // SWSH_ITEM_MENU_ACTION_IN_BAG

static const u8 *const sPocketNamesStringsTable[] =
{
    [POCKET_ITEMS]      = COMPOUND_STRING("Items"),
    [POCKET_POKE_BALLS] = COMPOUND_STRING("Poké Balls"),
    [POCKET_TM_HM]      = COMPOUND_STRING("TMs & HMs"),
    [POCKET_BERRIES]    = COMPOUND_STRING("Berries"),
    [POCKET_KEY_ITEMS]  = COMPOUND_STRING("Key Items")
};

static const u8 sText_MoveInfoPower[]          = _("Power");
static const u8 sText_MoveInfoAccuracy[]       = _("Accuracy");
static const u8 sText_MoveInfoPP[]             = _("PP");
#if SWSH_ITEM_MENU_BERRY_INFO
static const u8 sText_BerryFlavorSpicy[]       = _("Spicy");
static const u8 sText_BerryFlavorDry[]         = _("Dry");
static const u8 sText_BerryFlavorSweet[]       = _("Sweet");
static const u8 sText_BerryFlavorBitter[]      = _("Bitter");
static const u8 sText_BerryFlavorSour[]        = _("Sour");
static const u8 *const sBerryFirmnessStrings[] =
{
    [BERRY_FIRMNESS_UNKNOWN]    = COMPOUND_STRING("???"),
    [BERRY_FIRMNESS_VERY_SOFT]  = COMPOUND_STRING("Very soft"),
    [BERRY_FIRMNESS_SOFT]       = COMPOUND_STRING("Soft"),
    [BERRY_FIRMNESS_HARD]       = COMPOUND_STRING("Hard"),
    [BERRY_FIRMNESS_VERY_HARD]  = COMPOUND_STRING("Very hard"),
    [BERRY_FIRMNESS_SUPER_HARD] = COMPOUND_STRING("Super hard"),
};
#endif
#if SWSH_ITEM_MENU_TMHM_CONTEST_INFO
static const u8 sText_MoveInfoAppeal[]   = _("Appeal");
static const u8 sText_MoveInfoJam[]      = _("Jam");
#endif

#if SWSH_ITEM_MENU_ACTION_IN_BAG
static const u8 sText_PartyPanelBasePointsReset[] = _("{STR_VAR_1}'s base points\nwere all reset to zero!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PartyPanelDynamaxLevelUp[]  = _("{STR_VAR_1}'s Dynamax Level\nincreased by 1!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PartyPanelAbilityAsk[]      = _("Would you like to change {STR_VAR_1}'s\nability to {STR_VAR_2}?{PAUSE_UNTIL_PRESS}");
static const u8 sText_PartyPanelAbilityDone[]     = _("{STR_VAR_1}'s ability became\n{STR_VAR_2}!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PartyPanelMintAsk[]         = _("It might affect {STR_VAR_1}'s stats.\nAre you sure you want to use it?{PAUSE_UNTIL_PRESS}");
static const u8 sText_PartyPanelMintDone[]        = _("{STR_VAR_1}'s stats may have changed due\nto the effects of the {STR_VAR_2}!{PAUSE_UNTIL_PRESS}");

static const struct YesNoFuncTable sPartyPanelAbilityChangeYesNo    = {BagMenu_AbilityChangeYes, BagMenu_AbilityChangeNo};
static const struct YesNoFuncTable sPartyPanelMintYesNo             = {BagMenu_MintYes, BagMenu_MintNo};
static const struct YesNoFuncTable sPartyPanelRareCandyReplaceYesNo = {BagMenu_RareCandyReplaceYes, BagMenu_RareCandyReplaceNo};
#endif // SWSH_ITEM_MENU_ACTION_IN_BAG

static const u8 sText_Var1CantBeHeldHere[]      = _("The {STR_VAR_1} can't be held\nhere.");
static const u8 sText_DepositHowManyVar1[]      = _("Deposit how many\n{STR_VAR_1}?");
static const u8 sText_DepositedVar2Var1s[]      = _("Deposited {STR_VAR_2}\n{STR_VAR_1}.");
static const u8 sText_NoRoomForItems[]          = _("There's no room to\nstore items.");
static const u8 sText_CantStoreImportantItems[] = _("Important items\ncan't be stored in\nthe PC!");
static const u8 sText_Price[]                   = _("Price");

static void Task_LoadBagSortOptions(u8 taskId);
static void ItemMenu_SortByName(u8 taskId);
static void ItemMenu_SortByType(u8 taskId);
static void ItemMenu_SortByAmount(u8 taskId);
static void ItemMenu_SortByIndex(u8 taskId);
static void SortBagItems(u8 taskId);
static void Task_SortFinish(u8 taskId);
static void MergeSort(struct BagPocket *pocket, s32 (*comparator)(enum Pocket, struct ItemSlot, struct ItemSlot));
static s32 CompareItemsAlphabetically(enum Pocket pocketId, struct ItemSlot item1, struct ItemSlot item2);
static s32 CompareItemsByMost(enum Pocket pocketId, struct ItemSlot item1, struct ItemSlot item2);
static s32 CompareItemsByType(enum Pocket pocketId, struct ItemSlot item1, struct ItemSlot item2);
static s32 CompareItemsByIndex(enum Pocket pocketId, struct ItemSlot item1, struct ItemSlot item2);

static const struct BgTemplate sBgTemplates_ItemMenu[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

static const struct ListMenuTemplate sItemListMenu =
{
    .items = NULL,
    .moveCursorFunc = BagMenu_MoveCursorCallback,
    .itemPrintFunc = BagMenu_ItemPrintCallback,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = WIN_ITEM_LIST,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 1,
    .fillValue = 0,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NARROW,
    .cursorKind = CURSOR_INVISIBLE
};

static const u8 sText_NothingToSort[] = _("There's nothing to sort!");
static const struct MenuAction sItemMenuActions[] = {
    [ACTION_USE]               = {gMenuText_Use,                {ItemMenu_UseOutOfBattle}},
    [ACTION_TOSS]              = {gMenuText_Toss,               {ItemMenu_Toss}},
    [ACTION_REGISTER]          = {gMenuText_Register,           {ItemMenu_Register}},
    [ACTION_GIVE]              = {gMenuText_Give,               {ItemMenu_Give}},
    [ACTION_CANCEL]            = {gText_Cancel2,                {ItemMenu_Cancel}},
    [ACTION_BATTLE_USE]        = {gMenuText_Use,                {ItemMenu_UseInBattle}},
    [ACTION_CHECK]             = {COMPOUND_STRING("CHECK"),     {ItemMenu_UseOutOfBattle}},
    [ACTION_WALK]              = {COMPOUND_STRING("WALK"),      {ItemMenu_UseOutOfBattle}},
    [ACTION_DESELECT]          = {COMPOUND_STRING("DESELECT"),  {ItemMenu_Register}},
    [ACTION_CHECK_TAG]         = {COMPOUND_STRING("CHECK TAG"), {ItemMenu_CheckTag}},
    [ACTION_CONFIRM]           = {gMenuText_Confirm,            {Task_FadeAndCloseBagMenu}},
    [ACTION_SHOW]              = {COMPOUND_STRING("SHOW"),      {ItemMenu_Show}},
    [ACTION_GIVE_FAVOR_LADY]   = {gMenuText_Give2,              {ItemMenu_GiveFavorLady}},
    [ACTION_CONFIRM_QUIZ_LADY] = {gMenuText_Confirm,            {ItemMenu_ConfirmQuizLady}},
    [ACTION_BY_NAME]           = {COMPOUND_STRING("Name"),      {ItemMenu_SortByName}},
    [ACTION_BY_TYPE]           = {COMPOUND_STRING("Type"),      {ItemMenu_SortByType}},
    [ACTION_BY_AMOUNT]         = {COMPOUND_STRING("Amount"),    {ItemMenu_SortByAmount}},
    [ACTION_BY_INDEX]          = {COMPOUND_STRING("Index"),     {ItemMenu_SortByIndex}},
    [ACTION_DUMMY]             = {gText_EmptyString2,           {NULL}}
};

// these are all 2D arrays with a width of 2 but are represented as 1D arrays
// ACTION_DUMMY is used to represent blank spaces
static const u8 sContextMenuItems_ItemsPocket[] = {
    ACTION_USE,         ACTION_GIVE,
    ACTION_TOSS,        ACTION_CANCEL
};

static const u8 sContextMenuItems_KeyItemsPocket[] = {
    ACTION_USE,         ACTION_REGISTER,
    ACTION_DUMMY,       ACTION_CANCEL
};

static const u8 sContextMenuItems_BallsPocket[] = {
    ACTION_GIVE,        ACTION_DUMMY,
    ACTION_TOSS,        ACTION_CANCEL
};

static const u8 sContextMenuItems_TmHmPocket[] = {
    ACTION_USE,         ACTION_GIVE,
    ACTION_DUMMY,       ACTION_CANCEL
};

#if SWSH_ITEM_MENU_CHECK_BERRY_TAG
static const u8 sContextMenuItems_BerriesPocket[] = {
    ACTION_CHECK_TAG,   ACTION_DUMMY,
    ACTION_USE,         ACTION_GIVE,
    ACTION_TOSS,        ACTION_CANCEL
};
#else
static const u8 sContextMenuItems_BerriesPocket[] = {
    ACTION_USE,         ACTION_GIVE,
    ACTION_TOSS,        ACTION_CANCEL
};
#endif

static const u8 sContextMenuItems_BattleUse[] = {
    ACTION_BATTLE_USE,  ACTION_CANCEL
};

static const u8 sContextMenuItems_Give[] = {
    ACTION_GIVE,        ACTION_CANCEL
};

static const u8 sContextMenuItems_Cancel[] = {
    ACTION_CANCEL
};

#if SWSH_ITEM_MENU_CHECK_BERRY_TAG
static const u8 sContextMenuItems_BerryBlenderCrush[] = {
    ACTION_CONFIRM,     ACTION_CHECK_TAG,
    ACTION_DUMMY,       ACTION_CANCEL
};
#else
static const u8 sContextMenuItems_BerryBlenderCrush[] = {
    ACTION_CONFIRM,     ACTION_CANCEL
};
#endif

static const u8 sContextMenuItems_Apprentice[] = {
    ACTION_SHOW,        ACTION_CANCEL
};

static const u8 sContextMenuItems_FavorLady[] = {
    ACTION_GIVE_FAVOR_LADY, ACTION_CANCEL
};

static const u8 sContextMenuItems_QuizLady[] = {
    ACTION_CONFIRM_QUIZ_LADY, ACTION_CANCEL
};

static const TaskFunc sContextMenuFuncs[] = {
    [ITEMMENULOCATION_FIELD] =                  Task_ItemContext_Normal,
    [ITEMMENULOCATION_BATTLE] =                 Task_ItemContext_Normal,
    [ITEMMENULOCATION_PARTY] =                  Task_ItemContext_GiveToParty,
    [ITEMMENULOCATION_SHOP] =                   Task_ItemContext_Sell,
    [ITEMMENULOCATION_BERRY_TREE] =             Task_FadeAndCloseBagMenu,
    [ITEMMENULOCATION_BERRY_BLENDER_CRUSH] =    Task_ItemContext_Normal,
    [ITEMMENULOCATION_ITEMPC] =                 Task_ItemContext_Deposit,
    [ITEMMENULOCATION_FAVOR_LADY] =             Task_ItemContext_Normal,
    [ITEMMENULOCATION_QUIZ_LADY] =              Task_ItemContext_Normal,
    [ITEMMENULOCATION_APPRENTICE] =             Task_ItemContext_Normal,
    [ITEMMENULOCATION_WALLY] =                  NULL,
    [ITEMMENULOCATION_PCBOX] =                  Task_ItemContext_GiveToPC,
    [ITEMMENULOCATION_BERRY_TREE_MULCH] =       Task_FadeAndCloseBagMenuIfMulch,
};

static const struct YesNoFuncTable sYesNoTossFunctions = {ConfirmToss, CancelToss};

static const struct YesNoFuncTable sYesNoSellItemFunctions = {ConfirmSell, CancelSell};

static const struct ScrollArrowsTemplate sBagScrollArrowsTemplate = {
    .firstArrowType = SCROLL_ARROW_LEFT,
    .firstX = 28,
    .firstY = 16,
    .secondArrowType = SCROLL_ARROW_RIGHT,
    .secondX = 100,
    .secondY = 16,
    .fullyUpThreshold = -1,
    .fullyDownThreshold = -1,
    .tileTag = TAG_BAG_SCROLL_ARROW,
    .palTag = TAG_BAG_SCROLL_ARROW,
    .palNum = 0,
};

static const u8 sRegisteredSelect_Gfx[]         = INCGFX_U8("graphics/bag/swsh/select_button.png", ".4bpp");
static const u32 sBagScreen_Gfx[]               = INCGFX_U32("graphics/bag/swsh/tiles.png", ".4bpp.smol");
static const u16 sBagScreen_Pal[]               = INCGFX_U16("graphics/bag/swsh/tiles.png", ".gbapal");
static const u32 sBagScreen_BG2TileMap[]        = INCGFX_U32("graphics/bag/swsh/bg2.bin", ".smolTM");
static const u32 sBagScreen_BG3TileMap[]        = INCGFX_U32("graphics/bag/swsh/bg3.bin", ".smolTM");
static const u32 sCursor_Gfx[]                  = INCGFX_U32("graphics/bag/swsh/cursor.png", ".4bpp.smol");
static const u32 sHoverSlot_Gfx[]               = INCGFX_U32("graphics/bag/swsh/hover_slot.png", ".4bpp.smol");
static const u32 sScrollThumb_Gfx[]             = INCGFX_U32("graphics/bag/swsh/scroll_thumb.png", ".4bpp.smol");
static const u32 sCategoryIcons_Gfx[]           = INCGFX_U32("graphics/bag/swsh/category_icons.png", ".4bpp.smol");
static const u32 sPocketScrollArrows_Gfx[]      = INCGFX_U32("graphics/bag/swsh/pocket_scroll_arrows.png", ".4bpp.smol");
static const u32 sSwapCursor_Gfx[]              = INCGFX_U32("graphics/bag/swsh/swap_cursor.png", ".4bpp.smol");
static const u32 sFrameMoney_Gfx[]              = INCGFX_U32("graphics/bag/swsh/frame_money.png", ".4bpp.smol");
static const u32 sFramePriceQuantity_Gfx[]      = INCGFX_U32("graphics/bag/swsh/frame_price_quantity.png", ".4bpp.smol");
static const u16 sCursor_Pal[]                  = INCGFX_U16("graphics/bag/swsh/cursor.png", ".gbapal");
static const u32 sMoveTypeIcons_Gfx[]           = INCGFX_U32("graphics/bag/swsh/move_types.png", ".4bpp.smol");
static const u16 sMoveTypeIcons_Pal[]           = INCGFX_U16("graphics/bag/swsh/move_types.png", ".gbapal");
static const u8 sBattleInfoPrompt_Tilemap[]     = INCBIN_U8("graphics/bag/swsh/battle_info_prompt.bin");
static const u8 sBattleStatPrompt_Tilemap[]     = INCBIN_U8("graphics/bag/swsh/battle_stat_prompt.bin");
#if SWSH_ITEM_MENU_TMHM_CONTEST_INFO
static const u8 sContestInfoPrompt_Tilemap[]    = INCBIN_U8("graphics/bag/swsh/contest_info_prompt.bin");
static const u8 sContestStatPrompt_Tilemap[]    = INCBIN_U8("graphics/bag/swsh/contest_stat_prompt.bin");
#endif

static const u8 sPartySlots_Tilemap[]           = INCBIN_U8("graphics/bag/swsh/party_slots.bin");

#if SWSH_ITEM_MENU_BERRY_INFO
static const u32 sBerryFlavorMark_Gfx[]         = INCGFX_U32("graphics/bag/swsh/berry_flavor_mark.png", ".4bpp.smol");
static const u8 sBerryInfoPrompt_Tilemap[]      = INCBIN_U8("graphics/bag/swsh/berry_info_prompt.bin");
static const u8 sBerryStatPrompt_Tilemap[]      = INCBIN_U8("graphics/bag/swsh/berry_stat_prompt.bin");
static const u8 sBerryTagPrompt_Tilemap[]       = INCBIN_U8("graphics/bag/swsh/berry_tag_prompt.bin");
#endif

static const struct OamData sOamData_Cursor =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1,
};

static const struct CompressedSpriteSheet sSpriteSheet_Cursor =
{
    .data = sCursor_Gfx,
    .size = (16 * 16 * 3) / 2,
    .tag = TAG_ITEM_CURSOR
};

static const union AnimCmd sAnim_Cursor[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_Cursor[] =
{
    sAnim_Cursor,
};

static const struct SpriteTemplate sSpriteTemplate_Cursor =
{
    .tileTag = TAG_ITEM_CURSOR,
    .paletteTag = TAG_ITEM_CURSOR,
    .oam = &sOamData_Cursor,
    .anims = sAnims_Cursor,
};

static const struct SpritePalette sSpritePalette_Cursor = {
    .data = sCursor_Pal,
    .tag = TAG_ITEM_CURSOR
};

static const struct CompressedSpriteSheet sSpriteSheet_SwapCursor =
{
    .data = sSwapCursor_Gfx,
    .size = (16 * 32 * 3) / 2,
    .tag = TAG_SWAP_CURSOR,
};

static const struct OamData sOamData_SwapCursor =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .size = SPRITE_SIZE(16x32),
    .priority = 1,
};

static const union AnimCmd sAnim_SwapCursor[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_SwapCursor[] =
{
    sAnim_SwapCursor,
};

static const struct SpriteTemplate sSpriteTemplate_SwapCursor =
{
    .tileTag = TAG_SWAP_CURSOR,
    .paletteTag = TAG_ITEM_CURSOR,
    .oam = &sOamData_SwapCursor,
    .anims = sAnims_SwapCursor,
};

static const struct OamData sOamData_HoverSlot =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_HoverSlot_0[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_HoverSlot_1[] = {
    ANIMCMD_FRAME(7, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_HoverSlot_2[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_HoverSlot_3[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_HoverSlot[] = {
    sSpriteAnim_HoverSlot_0,
    sSpriteAnim_HoverSlot_1,
    sSpriteAnim_HoverSlot_2,
    sSpriteAnim_HoverSlot_3,
};

static const u8 sHoverSlotAnims[HOVER_SLOT_SPRITES_COUNT] = {0, 1, 1, 2, 3};

static const struct CompressedSpriteSheet sSpriteSheet_HoverSlot =
{
    .data = sHoverSlot_Gfx,
    .size = (32 * 16 * 3) / 2,
    .tag = TAG_HOVER_SLOT
};

static const struct SpriteTemplate sHoverSlotSpriteTemplate =
{
    .tileTag = TAG_HOVER_SLOT,
    .paletteTag = TAG_ITEM_CURSOR,
    .oam = &sOamData_HoverSlot,
    .anims = sSpriteAnimTable_HoverSlot,
};

static const struct OamData sOamData_ScrollThumb =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .size = SPRITE_SIZE(8x8),
    .priority = 2,
};

static const struct CompressedSpriteSheet sSpriteSheet_ScrollThumb =
{
    .data = sScrollThumb_Gfx,
    .size = (8 * 8) / 2,
    .tag = TAG_BAG_SCROLL_THUMB
};

static const struct SpriteTemplate sSpriteTemplate_ScrollThumb =
{
    .tileTag = TAG_BAG_SCROLL_THUMB,
    .paletteTag = TAG_ITEM_CURSOR,
    .oam = &sOamData_ScrollThumb,
    .callback = SpriteCB_BagScrollThumb,
};

static const struct OamData sOamData_PocketScrollArrows =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .size = SPRITE_SIZE(8x16),
    .x = 0,
    .matrixNum = 0,
    .shape = SPRITE_SHAPE(8x16),
    .tileNum = 0,
    .priority = 2,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_PocketScrollArrow_Left[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_PocketScrollArrow_Right[] = {
    ANIMCMD_FRAME(2, 0, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_PocketScrollArrows[] = {
    sSpriteAnim_PocketScrollArrow_Left,
    sSpriteAnim_PocketScrollArrow_Right,
};

static const struct CompressedSpriteSheet sSpriteSheet_PocketScrollArrows =
{
    .data = sPocketScrollArrows_Gfx,
    .size = (8 * 16 * 2) / 2,
    .tag = TAG_POCKET_SCROLL_ARROW,
};

static const struct SpriteTemplate sSpriteTemplate_PocketScrollArrows =
{
    .tileTag = TAG_POCKET_SCROLL_ARROW,
    .paletteTag = TAG_ITEM_CURSOR,
    .oam = &sOamData_PocketScrollArrows,
    .anims = sSpriteAnimTable_PocketScrollArrows,
    .callback = SpriteCB_PocketScrollArrow,
};

static const union AffineAnimCmd sAffineAnim_BagItemIcon_Appear[] =
{
    AFFINEANIMCMD_FRAME(192, 192, 0, 0),
    AFFINEANIMCMD_FRAME(8, 8, 0, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnims_BagItemIcon[] =
{
    sAffineAnim_BagItemIcon_Appear,
};

static const struct OamData sOamData_MoveTypeIcon =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 0,
};

static const struct SpriteTemplate sSpriteTemplate_MoveTypeIcon =
{
    .tileTag = TAG_MOVE_TYPE_ICON,
    .paletteTag = TAG_MOVE_TYPE_ICON,
    .oam = &sOamData_MoveTypeIcon,
    .callback = SpriteCB_MoveTypeIcon,
};

static const struct OamData sOamData_CategoryIcon =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 0,
};

static const union AnimCmd sSpriteAnim_CategoryPhysical[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_CategorySpecial[] =
{
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_CategoryStatus[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_CategoryIcons[] =
{
    [DAMAGE_CATEGORY_PHYSICAL] = sSpriteAnim_CategoryPhysical,
    [DAMAGE_CATEGORY_SPECIAL]  = sSpriteAnim_CategorySpecial,
    [DAMAGE_CATEGORY_STATUS]   = sSpriteAnim_CategoryStatus,
};

static const struct CompressedSpriteSheet sSpriteSheet_CategoryIcon =
{
    .data = sCategoryIcons_Gfx,
    .size = 32 * 16 * 3 / 2,
    .tag = TAG_CATEGORY_ICON,
};

static const struct SpriteTemplate sSpriteTemplate_CategoryIcon =
{
    .tileTag = TAG_CATEGORY_ICON,
    .paletteTag = TAG_ITEM_CURSOR,
    .oam = &sOamData_CategoryIcon,
    .anims = sSpriteAnimTable_CategoryIcons,
};

#if SWSH_ITEM_MENU_BERRY_INFO
static const struct OamData sOamData_BerryFlavorMark =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .size = SPRITE_SIZE(8x8),
    .priority = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_BerryFlavorMark =
{
    .data = sBerryFlavorMark_Gfx,
    .size = 8 * 8 / 2,
    .tag = TAG_BERRY_FLAVOR_MARK,
};

static const struct SpriteTemplate sSpriteTemplate_BerryFlavorMark =
{
    .tileTag = TAG_BERRY_FLAVOR_MARK,
    .paletteTag = TAG_ITEM_CURSOR,
    .oam = &sOamData_BerryFlavorMark,
};
#endif

static const struct OamData sOamData_FrameMoney =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 2,
};

static const union AnimCmd sSpriteAnim_FrameMoney_0[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_FrameMoney_1[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd *const sSpriteAnimTable_FrameMoney[] = {
    sSpriteAnim_FrameMoney_0,
    sSpriteAnim_FrameMoney_1,
};
static const u8 sFrameMoneyAnims[FRAME_MONEY_SPRITES_COUNT] = {0, 0, 1};

static const struct CompressedSpriteSheet sSpriteSheet_FrameMoney = {
    .data = sFrameMoney_Gfx,
    .size = (32 * 32) / 2,
    .tag = TAG_FRAME_MONEY,
};

static const struct SpriteTemplate sSpriteTemplate_FrameMoney = {
    .tileTag = TAG_FRAME_MONEY,
    .paletteTag = TAG_ITEM_CURSOR,
    .oam = &sOamData_FrameMoney,
    .anims = sSpriteAnimTable_FrameMoney,
};

static const struct OamData sOamData_FramePriceQuantity =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1,
};

static const union AnimCmd sSpriteAnim_FramePriceQuantity_0[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_FramePriceQuantity_1[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_FramePriceQuantity_2[] = {
    ANIMCMD_FRAME(16, 0, TRUE, TRUE),
    ANIMCMD_END
};
static const union AnimCmd *const sSpriteAnimTable_FramePriceQuantity[] = {
    sSpriteAnim_FramePriceQuantity_0,
    sSpriteAnim_FramePriceQuantity_1,
    sSpriteAnim_FramePriceQuantity_2,
};
static const u8 sFramePriceAnims[FRAME_PRICE_SPRITES_COUNT]       = {0, 0, 1};
static const u8 sFrameQuantityAnims[FRAME_QUANTITY_SPRITES_COUNT] = {2, 0};

static const struct CompressedSpriteSheet sSpriteSheet_FramePriceQuantity = {
    .data = sFramePriceQuantity_Gfx,
    .size = (32 * 64) / 2,
    .tag = TAG_FRAME_PRICE_QUANTITY,
};

static const struct SpriteTemplate sSpriteTemplate_FramePriceQuantity = {
    .tileTag = TAG_FRAME_PRICE_QUANTITY,
    .paletteTag = TAG_ITEM_CURSOR,
    .oam = &sOamData_FramePriceQuantity,
    .anims = sSpriteAnimTable_FramePriceQuantity,
};

static u8 sCursorSpriteId;
static u8 sSwapCursorSpriteId;
static u8 sHoverSlotSpriteIds[HOVER_SLOT_SPRITES_COUNT];
static u8 sScrollThumbSpriteId;
static u8 sPocketScrollArrowSpriteIds[2];
static u32 sCursorAnimId;
static s32 sHoveredItemIndex;
static u32 sScrollThumbAnimId;
static u32 sPocketScrollArrowAnimIds[2];
static u32 sPartyPanelItemIconAnimId;
static u8 sMoveInfoMode;
static u8 sMoveTypeIconSpriteId;
static u8 sCategoryIconSpriteId;
static u8 sFrameMoneyIds[FRAME_MONEY_SPRITES_COUNT];
static u8 sFramePriceIds[FRAME_PRICE_SPRITES_COUNT];
static u8 sFrameQuantityIds[FRAME_QUANTITY_SPRITES_COUNT];
static u16 *sMoveTypeIconTilesPtr;
#if SWSH_ITEM_MENU_BERRY_INFO
static u8 sBerryInfoMode;
static u8 sBerryFlavorMarkSpriteIds[FLAVOR_COUNT];
#endif

enum {
    COLORID_NORMAL,
    COLORID_HOVER_NAME,
    COLORID_HOVER_QTY,
    COLORID_POCKET_NAME,
    COLORID_GRAY_CURSOR,
    COLORID_TMHM_INFO,
    COLORID_NONE = 0xFF
};
static const u8 sFontColorTable[][3] = {
                            // bgColor, textColor, shadowColor
    [COLORID_NORMAL]      = {0,  1,  3},
    [COLORID_HOVER_NAME]  = {0,  2,  4},
    [COLORID_HOVER_QTY]   = {0,  2,  5},
    [COLORID_POCKET_NAME] = {0,  2,  6},
    [COLORID_GRAY_CURSOR] = {0,  3,  6},
    [COLORID_TMHM_INFO]   = {0, 14, 10}
};

static const struct WindowTemplate sDefaultBagWindows[] =
{
    [WIN_ITEM_LIST] = {
        .bg = 1,
        .tilemapLeft = 13,
        .tilemapTop = 3,
        .width = 15,
        .height = 12,
        .paletteNum = 1,
        .baseBlock = 39,
    },
    [WIN_DESCRIPTION] = {
        .bg = 1,
        .tilemapLeft = 8,
        .tilemapTop = 16,
        .width = 18,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 219,
    },
    [WIN_POCKET_NAME] = {
        .bg = 1,
        .tilemapLeft = 15,
        .tilemapTop = 1,
        .width = 11,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 291,
    },
    [WIN_PP_LABEL] = {
        .bg = 1,
        .tilemapLeft = 10,
        .tilemapTop = 18,
        .width = 2,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 313,
    },
    [WIN_POW_ACC_LABEL] = {
        .bg = 1,
        .tilemapLeft = 17,
        .tilemapTop = 16,
        .width = 5,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 317,
    },
    [WIN_PP_INFO] = {
        .bg = 1,
        .tilemapLeft = 12,
        .tilemapTop = 18,
        .width = 2,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 337,
    },
    [WIN_POW_ACC_INFO] = {
        .bg = 1,
        .tilemapLeft = 23,
        .tilemapTop = 16,
        .width = 2,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 341,
    },
    [WIN_SELECT_PROMPT] = {
        .bg = 1,
        .tilemapLeft = 27,
        .tilemapTop = 16,
        .width = 3,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 499,
    },
#if SWSH_ITEM_MENU_TMHM_CONTEST_INFO
    [WIN_APP_JAM_LABEL] = {
        .bg = 1,
        .tilemapLeft = 17,
        .tilemapTop = 16,
        .width = 4,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 349,
    },
#endif
    [WIN_MESSAGE] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 367,
    },
#if SWSH_ITEM_MENU_BERRY_INFO
    [WIN_BERRY_INFO] = {
        .bg = 1,
        .tilemapLeft = 7,
        .tilemapTop = 16,
        .width = 6,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 475,
    },
    [WIN_BERRY_FLAVORS] = {
        .bg = 1,
        .tilemapLeft = 14,
        .tilemapTop = 16,
        .width = 12,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 349,
    },
#endif
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate sContextMenuWindowTemplates[] =
{
    [ITEMWIN_1x1] = {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 17,
        .width = 7,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 475,
    },
    [ITEMWIN_1x2] = {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 15,
        .width = 7,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 475,
    },
    [ITEMWIN_2x2] = {
        .bg = 0,
        .tilemapLeft = 15,
        .tilemapTop = 15,
        .width = 14,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 475,
    },
    [ITEMWIN_2x3] = {
        .bg = 0,
        .tilemapLeft = 15,
        .tilemapTop = 13,
        .width = 14,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 475,
    },
    [ITEMWIN_MESSAGE] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 367,
    },
    [ITEMWIN_YESNO_LOW] = { // Yes/No tucked in corner, for toss confirm
        .bg = 0,
        .tilemapLeft = 24,
        .tilemapTop = 15,
        .width = 5,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 475,
    },
    [ITEMWIN_YESNO_HIGH] = { // Yes/No higher up, positioned above a lower message box
        .bg = 0,
        .tilemapLeft = 21,
        .tilemapTop = 9,
        .width = 5,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 475,
    },
    [ITEMWIN_QUANTITY] = { // Used for quantity of items to Toss/Deposit
        .bg = 0,
        .tilemapLeft = 24,
        .tilemapTop = 17,
        .width = 5,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 475,
    },
    [ITEMWIN_SELL_PRICE] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 4,
        .width = 6,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 559,
    },
    [ITEMWIN_MONEY] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 0,
        .width = 8,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 583,
    },
    [ITEMWIN_SELL_QUANTITY] = {
        .bg = 0,
        .tilemapLeft = 24,
        .tilemapTop = 11,
        .width = 4,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 599,
    },
#if SWSH_ITEM_MENU_ACTION_IN_BAG
    [ITEMWIN_PP_MOVE_SELECT] = {
        .bg = 0,
        .tilemapLeft = 19,
        .tilemapTop = 11,
        .width = 10,
        .height = 8,
        .paletteNum = 15,
        .baseBlock = 475,
    },
    [ITEMWIN_LEVEL_UP_STATS] = {
        .bg = 0,
        .tilemapLeft = 19,
        .tilemapTop = 2,
        .width = 10,
        .height = 11,
        .paletteNum = 15,
        .baseBlock = 475,
    },
#endif
};

EWRAM_DATA struct BagMenu *gBagMenu = 0;
EWRAM_DATA struct BagPosition gBagPosition = {0};
static EWRAM_DATA struct ListBuffer1 *sListBuffer1 = 0;
static EWRAM_DATA struct ListBuffer2 *sListBuffer2 = 0;
EWRAM_DATA u16 gSpecialVar_ItemId = 0;
static EWRAM_DATA struct TempWallyBag *sTempWallyBag = 0;
static EWRAM_DATA u8 *sMoveTypeIconsCache = NULL;
#if SWSH_ITEM_MENU_ACTION_IN_BAG
static EWRAM_DATA struct BagRareCandyState *sBagRareCandyState = NULL;
#endif 

void ResetBagScrollPositions(void)
{
    gBagPosition.pocket = POCKET_ITEMS;
    memset(gBagPosition.cursorPosition, 0, sizeof(gBagPosition.cursorPosition));
    memset(gBagPosition.scrollPosition, 0, sizeof(gBagPosition.scrollPosition));
}

void CB2_BagMenuFromStartMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_FIELD, POCKETS_COUNT, CB2_ReturnToFieldWithOpenMenu);
}

void CB2_BagMenuFromBattle(void)
{
    if (CurrentBattlePyramidLocation() == PYRAMID_LOCATION_NONE)
        GoToBagMenu(ITEMMENULOCATION_BATTLE, POCKETS_COUNT, CB2_SetUpReshowBattleScreenAfterMenu2);
    else
        GoToBattlePyramidBagMenu(PYRAMIDBAG_LOC_BATTLE, CB2_SetUpReshowBattleScreenAfterMenu2);
}

// Choosing berry to plant
void CB2_ChooseBerry(void)
{
    GoToBagMenu(ITEMMENULOCATION_BERRY_TREE, POCKET_BERRIES, CB2_ReturnToFieldContinueScript);
}

// Choosing mulch to use
void CB2_ChooseMulch(void)
{
    GoToBagMenu(ITEMMENULOCATION_BERRY_TREE_MULCH, POCKET_ITEMS, CB2_ReturnToFieldContinueScript);
}

// Choosing berry for Berry Blender or Berry Crush
void ChooseBerryForMachine(MainCallback exitCallback)
{
    GoToBagMenu(ITEMMENULOCATION_BERRY_BLENDER_CRUSH, POCKET_BERRIES, exitCallback);
}

void CB2_GoToSellMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_SHOP, POCKETS_COUNT, CB2_ExitSellMenu);
}

void CB2_GoToItemDepositMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_ITEMPC, POCKETS_COUNT, CB2_PlayerPCExitBagMenu);
}

void ApprenticeOpenBagMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_APPRENTICE, POCKETS_COUNT, CB2_ApprenticeExitBagMenu);
    gSpecialVar_0x8005 = ITEM_NONE;
    gSpecialVar_Result = FALSE;
}

void FavorLadyOpenBagMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_FAVOR_LADY, POCKETS_COUNT, CB2_FavorLadyExitBagMenu);
    gSpecialVar_Result = FALSE;
}

void QuizLadyOpenBagMenu(void)
{
    GoToBagMenu(ITEMMENULOCATION_QUIZ_LADY, POCKETS_COUNT, CB2_QuizLadyExitBagMenu);
    gSpecialVar_Result = FALSE;
}

void GoToBagMenu(u8 location, u8 pocket, MainCallback exitCallback)
{
    gBagMenu = AllocZeroed(sizeof(*gBagMenu));
    if (gBagMenu == NULL)
    {
        // Alloc failed, exit
        SetMainCallback2(exitCallback);
    }
    else
    {
        gBagMenu->hideCloseBagText = TRUE;
        if (location != ITEMMENULOCATION_LAST)
            gBagPosition.location = location;
        if (exitCallback)
            gBagPosition.exitCallback = exitCallback;
        if (pocket < POCKETS_COUNT)
            gBagPosition.pocket = pocket;
        if (gBagPosition.location == ITEMMENULOCATION_BERRY_TREE ||
            gBagPosition.location == ITEMMENULOCATION_BERRY_BLENDER_CRUSH ||
            gBagPosition.location == ITEMMENULOCATION_BERRY_TREE_MULCH)
            gBagMenu->pocketSwitchDisabled = TRUE;
        gBagMenu->newScreenCallback = NULL;
        gBagMenu->toSwapPos = NOT_SWAPPING;
        gBagMenu->pocketScrollArrowsTask = TASK_NONE;
        gBagMenu->pocketSwitchArrowsTask = TASK_NONE;
        memset(gBagMenu->spriteIds, SPRITE_NONE, sizeof(gBagMenu->spriteIds));
        sCursorSpriteId = SPRITE_NONE;
        sSwapCursorSpriteId = SPRITE_NONE;
        memset(sHoverSlotSpriteIds, SPRITE_NONE, sizeof(sHoverSlotSpriteIds));
        sScrollThumbSpriteId = SPRITE_NONE;
        memset(sPocketScrollArrowSpriteIds, SPRITE_NONE, sizeof(sPocketScrollArrowSpriteIds));
        memset(sFrameQuantityIds, SPRITE_NONE, sizeof(sFrameQuantityIds));
        sPocketScrollArrowAnimIds[0] = INVALID_COMFY_ANIM;
        sPocketScrollArrowAnimIds[1] = INVALID_COMFY_ANIM;
        sCursorAnimId = INVALID_COMFY_ANIM;
        sScrollThumbAnimId = INVALID_COMFY_ANIM;
        sPartyPanelItemIconAnimId = INVALID_COMFY_ANIM;
        sHoveredItemIndex = LIST_CANCEL;
        memset(gBagMenu->windowIds, WINDOW_NONE, sizeof(gBagMenu->windowIds));
        SetMainCallback2(CB2_Bag);
    }
}

void CB2_BagMenuRun(void)
{
    RunTasks();
    AdvanceComfyAnimations();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

void VBlankCB_BagMenuRun(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
#if SWSH_ITEM_MENU_SCROLLING_BG
    ChangeBgX(3, 64, BG_COORD_ADD);
    ChangeBgY(3, 64, BG_COORD_ADD);
#endif
}

#define tListTaskId             data[0]
#define tListPosition           data[1]
#define tQuantity               data[2]
#define tNeverRead              data[3]
#define tPartyPanelSlot         data[4]
#define tPartyPanelSavedIconY   data[5]
#define tPartyPanelTemp         data[6]
#define tItemCount              data[8]
#define tMsgWindowId            data[10]
#define tPocketSwitchDir        data[11]
#define tPocketSwitchTimer      data[12]
#define tPocketSwitchState      data[13]

static void CB2_Bag(void)
{
    while (MenuHelpers_ShouldWaitForLinkRecv() != TRUE && SetupBagMenu() != TRUE && MenuHelpers_IsLinkActive() != TRUE)
        {};
}

#if SWSH_ITEM_MENU_ACTION_IN_BAG
#define PARTY_PANEL_ITEM_ICON_X      20
#define PARTY_PANEL_ITEM_ICON_Y(i)   (24 * (i) + 16)
#define RARE_CANDY_REENTRY_NONE         0
#define RARE_CANDY_REENTRY_MOVE_FORGET  1
#define RARE_CANDY_REENTRY_CANDY_USE    2
#endif // SWSH_ITEM_MENU_ACTION_IN_BAG

static bool8 SetupBagMenu(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 3:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = TRUE;
        gMain.state++;
        break;
    case 4:
        ResetSpriteData();
        gMain.state++;
        break;
    case 5:
        gMain.state++;
        break;
    case 6:
        if (!MenuHelpers_IsLinkActive())
            ResetTasks();
        gMain.state++;
        break;
    case 7:
        BagMenu_InitBGs();
        gBagMenu->graphicsLoadState = 0;
        gMain.state++;
        break;
    case 8:
        if (!LoadBagMenu_Graphics())
            break;
        gMain.state++;
        break;
    case 9:
        LoadBagMenuTextWindows();
        gMain.state++;
        break;
    case 10:
        UpdatePocketItemLists();
        InitPocketListPositions();
        InitPocketScrollPositions();
        gMain.state++;
        break;
    case 11:
        AllocateBagItemListBuffers();
        gMain.state++;
        break;
    case 12:
        LoadBagItemListBuffers(gBagPosition.pocket);
        gMain.state++;
        break;
    case 13:
        PrintPocketName(sPocketNamesStringsTable[gBagPosition.pocket]);
        gMain.state++;
        break;
    case 14:
        taskId = CreateBagInputHandlerTask(gBagPosition.location);
        gTasks[taskId].tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, gBagPosition.scrollPosition[gBagPosition.pocket], gBagPosition.cursorPosition[gBagPosition.pocket]);
        gTasks[taskId].tNeverRead = 0;
        gTasks[taskId].tItemCount = 0;
#if SWSH_ITEM_MENU_ACTION_IN_BAG
        if (sBagRareCandyState != NULL && sBagRareCandyState->reentryPhase != RARE_CANDY_REENTRY_NONE)
            gTasks[taskId].func = Task_BagMenu_RareCandyReentry;
#endif
        gMain.state++;
        break;
    case 15:
        CreateCursorSprite();
        gMain.state++;
        break;
    case 16:
#if SWSH_ITEM_MENU_ACTION_IN_BAG
        if (sBagRareCandyState != NULL && sBagRareCandyState->reentryPhase != RARE_CANDY_REENTRY_NONE)
        {
            u8 iconSpriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + (gBagMenu->itemIconSlot ^ 1)];
            if (iconSpriteId != SPRITE_NONE)
            {
                gSprites[iconSpriteId].x2 = PARTY_PANEL_ITEM_ICON_X;
                gSprites[iconSpriteId].y2 = PARTY_PANEL_ITEM_ICON_Y(sBagRareCandyState->slot);
            }
            gSprites[sCursorSpriteId].invisible = TRUE;
        }
        else
#endif
        if (gBagMenu->numItemStacks[gBagPosition.pocket] == (u8)(!gBagMenu->hideCloseBagText))
            gSprites[sCursorSpriteId].invisible = TRUE;
        gMain.state++;
        break;
    case 17:
        CreateHoverSlotSprites();
        if (gBagMenu->numItemStacks[gBagPosition.pocket] == (u8)(!gBagMenu->hideCloseBagText))
        {
            u8 i;
            for (i = 0; i < HOVER_SLOT_SPRITES_COUNT; i++)
                gSprites[sHoverSlotSpriteIds[i]].invisible = TRUE;
        }
        gMain.state++;
        break;
    case 18:
        CreateScrollThumbSprite();
        gMain.state++;
        break;
    case 19:
        CreatePocketScrollArrowPair();
        gMain.state++;
        break;
    case 20:
        sMoveInfoMode = FALSE;
        sMoveTypeIconSpriteId = SPRITE_NONE;
        sCategoryIconSpriteId = SPRITE_NONE;
#if SWSH_ITEM_MENU_BERRY_INFO
        sBerryInfoMode = 0;
        memset(sBerryFlavorMarkSpriteIds, SPRITE_NONE, sizeof(sBerryFlavorMarkSpriteIds));
#endif
        if (gBagMenu->numItemStacks[gBagPosition.pocket] != (u8)(!gBagMenu->hideCloseBagText))
        {
            if (gBagPosition.pocket == POCKET_TM_HM)
            {
                ShowInfoPrompt(sBattleStatPrompt_Tilemap);
            }
#if SWSH_ITEM_MENU_BERRY_INFO
            else if (gBagPosition.pocket == POCKET_BERRIES)
            {
                ShowInfoPrompt(sBerryStatPrompt_Tilemap);
            }
#endif
        }
        if (gBagPosition.location == ITEMMENULOCATION_SHOP)
        {
            SetupSellWindows();
            UpdateSellPrice(GetBagItemId(gBagPosition.pocket,
                gBagPosition.cursorPosition[gBagPosition.pocket]));
        }
        gMain.state++;
        break;
    case 21:
        BlendPalettes(PALETTES_ALL, 16, 0);
        gMain.state++;
        break;
    case 22:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gPaletteFade.bufferTransferDisabled = FALSE;
        gMain.state++;
        break;
    default:
        SetVBlankCallback(VBlankCB_BagMenuRun);
        SetMainCallback2(CB2_BagMenuRun);
        return TRUE;
    }
    return FALSE;
}

static void BagMenu_InitBGs(void)
{
    ResetVramOamAndBgCntRegs();
    memset(gBagMenu->mainTilemapBuffer, 0, sizeof(gBagMenu->mainTilemapBuffer));
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates_ItemMenu, ARRAY_COUNT(sBgTemplates_ItemMenu));
    SetBgTilemapBuffer(2, gBagMenu->mainTilemapBuffer);
    SetBgTilemapBuffer(3, gBagMenu->scrollingBgTilemapBuffer);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static bool8 LoadBagMenu_Graphics(void)
{
    switch (gBagMenu->graphicsLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(2, sBagScreen_Gfx, 0, 0, 0);
        gBagMenu->graphicsLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            DecompressDataWithHeaderWram(sBagScreen_BG2TileMap, gBagMenu->mainTilemapBuffer);
            DecompressDataWithHeaderWram(sBagScreen_BG3TileMap, gBagMenu->scrollingBgTilemapBuffer);
            gBagMenu->graphicsLoadState++;
        }
        break;
    case 2:
        if (gBagPosition.location == ITEMMENULOCATION_FIELD
            || gBagPosition.location == ITEMMENULOCATION_BATTLE
            || gBagPosition.location == ITEMMENULOCATION_PARTY
            || gBagPosition.location == ITEMMENULOCATION_WALLY)
            BagMenu_DrawPartySlots();
        gBagMenu->graphicsLoadState++;
        break;
    case 3:
        if (gBagPosition.location == ITEMMENULOCATION_FIELD
            || gBagPosition.location == ITEMMENULOCATION_BATTLE
            || gBagPosition.location == ITEMMENULOCATION_PARTY
            || gBagPosition.location == ITEMMENULOCATION_WALLY)
            BagMenu_CreatePartyIcons();
        gBagMenu->graphicsLoadState++;
        break;
    case 4:
        LoadPalette(sBagScreen_Pal, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
        gBagMenu->graphicsLoadState++;
        break;
    case 5:
        LoadCompressedSpriteSheet(&sSpriteSheet_Cursor);
        gBagMenu->graphicsLoadState++;
        break;
    case 6:
        LoadSpritePalette(&sSpritePalette_Cursor);
        gBagMenu->graphicsLoadState++;
        break;
    case 7:
        LoadCompressedSpriteSheet(&sSpriteSheet_HoverSlot);
        gBagMenu->graphicsLoadState++;
        break;
    case 8:
        LoadCompressedSpriteSheet(&sSpriteSheet_ScrollThumb);
        gBagMenu->graphicsLoadState++;
        break;
    case 9:
        LoadCompressedSpriteSheet(&sSpriteSheet_PocketScrollArrows);
        gBagMenu->graphicsLoadState++;
        break;
    case 10:
        sMoveTypeIconsCache = Alloc(32 * 416 / 2);
        DecompressDataWithHeaderWram(sMoveTypeIcons_Gfx, sMoveTypeIconsCache);
        gBagMenu->graphicsLoadState++;
        break;
    case 11:
        LoadCompressedSpriteSheet(&sSpriteSheet_SwapCursor);
        gBagMenu->graphicsLoadState++;
        break;
    case 12:
        LoadCompressedSpriteSheet(&sSpriteSheet_FrameMoney);
        gBagMenu->graphicsLoadState++;
        break;
    case 13:
        LoadCompressedSpriteSheet(&sSpriteSheet_FramePriceQuantity);
        gBagMenu->graphicsLoadState++;
        break;
    default:
        gBagMenu->graphicsLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static u8 CreateBagInputHandlerTask(u8 location)
{
    u8 taskId;
    if (location == ITEMMENULOCATION_WALLY)
        taskId = CreateTask(Task_WallyTutorialBagMenu, 0);
    else
        taskId = CreateTask(Task_BagMenu_HandleInput, 0);
    return taskId;
}

static void AllocateBagItemListBuffers(void)
{
    sListBuffer1 = Alloc(sizeof(*sListBuffer1));
    sListBuffer2 = Alloc(sizeof(*sListBuffer2));
}

static void LoadBagItemListBuffers(u8 pocketId)
{
    u16 i;
    struct ListMenuItem *subBuffer;

    if (!gBagMenu->hideCloseBagText)
    {
        for (i = 0; i < gBagMenu->numItemStacks[pocketId] - 1; i++)
        {
            GetItemNameFromPocket(sListBuffer2->name[i], GetBagItemId(pocketId, i));
            subBuffer = sListBuffer1->subBuffers;
            subBuffer[i].name = sListBuffer2->name[i];
            subBuffer[i].id = i;
        }
        StringCopy(sListBuffer2->name[i], gText_CloseBag);
        subBuffer = sListBuffer1->subBuffers;
        subBuffer[i].name = sListBuffer2->name[i];
        subBuffer[i].id = LIST_CANCEL;
    }
    else
    {
        for (i = 0; i < gBagMenu->numItemStacks[pocketId]; i++)
        {
            GetItemNameFromPocket(sListBuffer2->name[i], GetBagItemId(pocketId, i));
            subBuffer = sListBuffer1->subBuffers;
            subBuffer[i].name = sListBuffer2->name[i];
            subBuffer[i].id = i;
        }
    }
    gMultiuseListMenuTemplate = sItemListMenu;
    gMultiuseListMenuTemplate.totalItems = gBagMenu->numItemStacks[pocketId];
    gMultiuseListMenuTemplate.items = sListBuffer1->subBuffers;
    gMultiuseListMenuTemplate.maxShowed = gBagMenu->numShownItems[pocketId];
}

static void GetItemNameFromPocket(u8 *dest, enum Item itemId)
{
    u8 *end;
    switch (gBagPosition.pocket)
    {
    case POCKET_TM_HM:
        end = StringCopy(gStringVar2, GetMoveName(ItemIdToBattleMoveId(itemId)));
        PrependFontIdToFit(gStringVar2, end, FONT_NARROW, NUM_TECHNICAL_MACHINES >= 100 ? 60 : 65);
        if (GetItemTMHMIndex(itemId) > NUM_TECHNICAL_MACHINES)
        {
            // Get HM number
            ConvertIntToDecimalStringN(gStringVar1, GetItemTMHMIndex(itemId) - NUM_TECHNICAL_MACHINES, STR_CONV_MODE_LEADING_ZEROS, 1);
            StringExpandPlaceholders(dest, gText_NumberItem_HM);
        }
        else
        {
            // Get TM number
            ConvertIntToDecimalStringN(gStringVar1, GetItemTMHMIndex(itemId), STR_CONV_MODE_LEADING_ZEROS, NUM_TECHNICAL_MACHINES >= 100 ? 3 : 2);
            StringExpandPlaceholders(dest, gText_NumberItem_TMBerry);
        }
        break;
    case POCKET_BERRIES:
        ConvertIntToDecimalStringN(gStringVar1, ItemIdToBerryType(itemId), STR_CONV_MODE_LEADING_ZEROS, 2);
        end = CopyItemName(itemId, gStringVar2);
        PrependFontIdToFit(gStringVar2, end, FONT_NARROW, 61);
        StringExpandPlaceholders(dest, gText_NumberItem_TMBerry);
        break;
    default:
        end = CopyItemName(itemId, dest);
        PrependFontIdToFit(dest, end, FONT_NARROW, 88);
        break;
    }
}

static void CreateCursorSprite(void)
{
    u8 rowHeight = GetFontAttribute(FONT_NARROW, FONTATTR_MAX_LETTER_HEIGHT) + sItemListMenu.itemVerticalPadding;
    u8 windowTop = sDefaultBagWindows[WIN_ITEM_LIST].tilemapTop * 8;
    u8 initialY = windowTop + sItemListMenu.upText_Y + gBagPosition.cursorPosition[gBagPosition.pocket] * rowHeight + 8;
    struct ComfyAnimEasingConfig animConfig;

    InitComfyAnimConfig_Easing(&animConfig);
    animConfig.from = Q_24_8(initialY);
    animConfig.to = Q_24_8(initialY);
    animConfig.durationFrames = 1;
    animConfig.easingFunc = ComfyAnimEasing_EaseOutCubic;
    sCursorAnimId = CreateComfyAnim_Easing(&animConfig);

    sCursorSpriteId = CreateSprite(&sSpriteTemplate_Cursor, 80, initialY, 0);
    gSprites[sCursorSpriteId].callback = SpriteCB_SlideCursorY;
}

static void CreateScrollThumbSprite(void)
{
    u8 pocket = gBagPosition.pocket;
    u8 total = gBagMenu->numItemStacks[pocket];
    u16 absIdx = gBagPosition.scrollPosition[pocket] + gBagPosition.cursorPosition[pocket];
    s16 initialY2 = (total > MAX_ITEMS_SHOWN) ? absIdx * 88 / (total - 1) : 0;
    struct ComfyAnimEasingConfig animConfig;

    InitComfyAnimConfig_Easing(&animConfig);
    animConfig.from = Q_24_8(initialY2);
    animConfig.to = Q_24_8(initialY2);
    animConfig.durationFrames = 1;
    animConfig.easingFunc = ComfyAnimEasing_EaseOutCubic;
    sScrollThumbAnimId = CreateComfyAnim_Easing(&animConfig);

    sScrollThumbSpriteId = CreateSprite(&sSpriteTemplate_ScrollThumb, 236, 28, 1);
}

static void CreateHoverSlotSprites(void)
{
    u8 rowHeight = GetFontAttribute(FONT_NARROW, FONTATTR_MAX_LETTER_HEIGHT) + sItemListMenu.itemVerticalPadding;
    u8 windowTop = sDefaultBagWindows[WIN_ITEM_LIST].tilemapTop * 8;
    u8 initialY = windowTop + sItemListMenu.upText_Y + gBagPosition.cursorPosition[gBagPosition.pocket] * rowHeight + 8;
    u8 i;

    for (i = 0; i < HOVER_SLOT_SPRITES_COUNT; i++)
    {
        sHoverSlotSpriteIds[i] = CreateSprite(&sHoverSlotSpriteTemplate, 86 + i * 32, initialY, 1);
        StartSpriteAnim(&gSprites[sHoverSlotSpriteIds[i]], sHoverSlotAnims[i]);
    }
}

static void SpriteCB_SlideCursorY(struct Sprite *sprite)
{
    s16 y;
    u8 i;
    y = ReadComfyAnimValueSmooth(&gComfyAnims[sCursorAnimId]);
    sprite->y = y;
    for (i = 0; i < HOVER_SLOT_SPRITES_COUNT; i++)
    {
        if (sHoverSlotSpriteIds[i] != SPRITE_NONE)
            gSprites[sHoverSlotSpriteIds[i]].y = y;
    }
    if (gBagMenu->toSwapPos != NOT_SWAPPING)
    {
        u8 iconSpriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + (gBagMenu->itemIconSlot ^ 1)];
        if (iconSpriteId != SPRITE_NONE)
            gSprites[iconSpriteId].y2 = y + 4;
        if (sSwapCursorSpriteId != SPRITE_NONE)
            gSprites[sSwapCursorSpriteId].y = y;
    }
}

static void SpriteCB_BagScrollThumb(struct Sprite *sprite)
{
    u8 pocket = gBagPosition.pocket;
    u8 total = gBagMenu->numItemStacks[pocket];

    if (total <= MAX_ITEMS_SHOWN)
    {
        sprite->invisible = TRUE;
        return;
    }
    sprite->invisible = FALSE;
    sprite->y2 = ReadComfyAnimValueSmooth(&gComfyAnims[sScrollThumbAnimId]);
}

static void RefreshItemListColors(struct ListMenu *list)
{
    u8 rowHeight = GetFontAttribute(FONT_NARROW, FONTATTR_MAX_LETTER_HEIGHT) + list->template.itemVerticalPadding;
    u8 windowWidth = sDefaultBagWindows[WIN_ITEM_LIST].width * 8;
    u8 row;
    for (row = 0; row < list->template.maxShowed; row++)
    {
        s32 absIndex = (s32)(list->scrollOffset + row);
        if (absIndex >= (s32)gBagMenu->numItemStacks[gBagPosition.pocket])
            break;
        u8 rowY = list->template.upText_Y + row * rowHeight;
        FillWindowPixelRect(WIN_ITEM_LIST, PIXEL_FILL(0), 0, rowY, windowWidth, rowHeight);
        BagMenu_ItemPrintCallback(WIN_ITEM_LIST, (u32)absIndex, rowY);
        BagMenu_Print(WIN_ITEM_LIST, FONT_NARROW, gMultiuseListMenuTemplate.items[absIndex].name,
                      sItemListMenu.item_X, rowY, 0, 0, TEXT_SKIP_DRAW,
                      absIndex == sHoveredItemIndex ? COLORID_HOVER_NAME : COLORID_NORMAL);
    }
    CopyWindowToVram(WIN_ITEM_LIST, COPYWIN_GFX);
}

static void BagMenu_MoveCursorCallback(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    u8 rowHeight = GetFontAttribute(FONT_NARROW, FONTATTR_MAX_LETTER_HEIGHT) + list->template.itemVerticalPadding;
    u8 windowTop = sDefaultBagWindows[WIN_ITEM_LIST].tilemapTop * 8;
    s16 spriteY = windowTop + list->template.upText_Y + list->selectedRow * rowHeight + 8;
    u32 durationFrames = 8;

    if (!onInit && !gComfyAnims[sCursorAnimId].completed)
    {
        if (gMain.heldKeys & (DPAD_UP | DPAD_DOWN))
            durationFrames = 1;
        else
            durationFrames = 2;
    }

    {
        struct ComfyAnimEasingConfig animConfig;
        InitComfyAnimConfig_Easing(&animConfig);
        animConfig.from = gComfyAnims[sCursorAnimId].position;
        animConfig.to = Q_24_8(spriteY);
        animConfig.durationFrames = durationFrames;
        animConfig.easingFunc = ComfyAnimEasing_EaseOutCubic;
        InitComfyAnim_Easing(&animConfig, &gComfyAnims[sCursorAnimId]);
    }

    {
        u8 total = gBagMenu->numItemStacks[gBagPosition.pocket];
        if (total > MAX_ITEMS_SHOWN)
        {
            struct ComfyAnimEasingConfig animConfig;
            InitComfyAnimConfig_Easing(&animConfig);
            animConfig.from = gComfyAnims[sScrollThumbAnimId].position;
            animConfig.to = Q_24_8(itemIndex * 88 / (total - 1));
            animConfig.durationFrames = durationFrames;
            animConfig.easingFunc = ComfyAnimEasing_EaseOutCubic;
            InitComfyAnim_Easing(&animConfig, &gComfyAnims[sScrollThumbAnimId]);
        }
    }

    sHoveredItemIndex = itemIndex;
    RefreshItemListColors(list);

    if (onInit != TRUE)
        PlaySE(SE_SELECT);

    if (!onInit || gBagMenu->numItemStacks[gBagPosition.pocket] != (u8)(!gBagMenu->hideCloseBagText))
    {
        u8 iconSlot = gBagMenu->itemIconSlot;
        u8 iconSpriteId;
        RemoveBagItemIconSprite(iconSlot ^ 1);
        if (itemIndex != LIST_CANCEL)
            AddBagItemIconSprite(GetBagItemId(gBagPosition.pocket, itemIndex), iconSlot);
        else
            AddBagItemIconSprite(ITEM_LIST_END, iconSlot);
        gBagMenu->itemIconSlot ^= 1;
        iconSpriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + iconSlot];
        if (iconSpriteId != SPRITE_NONE)
        {
            struct Sprite *spr = &gSprites[iconSpriteId];
            spr->x2 = 102;
            spr->y2 = spriteY + 4;
            if (gBagMenu->toSwapPos == NOT_SWAPPING)
            {
                spr->oam.affineMode = ST_OAM_AFFINE_NORMAL;
                spr->affineAnims = sAffineAnims_BagItemIcon;
                InitSpriteAffineAnim(spr);
                StartSpriteAffineAnim(spr, 0);
            }
        }
    }
    if (gBagMenu->toSwapPos == NOT_SWAPPING && !gBagMenu->inhibitItemDescriptionPrint
     && (!onInit || gBagMenu->numItemStacks[gBagPosition.pocket] != (u8)(!gBagMenu->hideCloseBagText)))
    {
        if (gBagPosition.pocket == POCKET_TM_HM && sMoveInfoMode == 1)
            UpdateMoveBattleInfo(itemIndex);
#if SWSH_ITEM_MENU_TMHM_CONTEST_INFO
        else if (gBagPosition.pocket == POCKET_TM_HM && sMoveInfoMode == 2)
            PrintContestDescription(itemIndex);
        else if (gBagPosition.pocket == POCKET_TM_HM && sMoveInfoMode == 3)
            UpdateMoveContestInfo(itemIndex);
#endif
#if SWSH_ITEM_MENU_BERRY_INFO
        else if (gBagPosition.pocket == POCKET_BERRIES && sBerryInfoMode == 1)
            UpdateBerryInfo(itemIndex);
        else if (gBagPosition.pocket == POCKET_BERRIES && sBerryInfoMode == 2)
            PrintBerryDescriptionInfo(itemIndex);
#endif
        else
            PrintItemDescription(itemIndex);
    }
    if (gBagPosition.location == ITEMMENULOCATION_SHOP
     && gBagMenu->windowIds[ITEMWIN_SELL_PRICE] != WINDOW_NONE)
    {
        u16 itemId = (itemIndex != LIST_CANCEL)
            ? GetBagItemId(gBagPosition.pocket, itemIndex) : ITEM_NONE;
        UpdateSellPrice(itemId);
    }
}

static void BagMenu_ItemPrintCallback(u8 windowId, u32 itemIndex, u8 y)
{
    if (itemIndex != LIST_CANCEL)
    {
        s32 offset;

        struct ItemSlot itemSlot = GetBagItemIdAndQuantity(gBagPosition.pocket, itemIndex);

        // Draw HM icon
        if (gBagPosition.pocket == POCKET_TM_HM && GetItemTMHMIndex(itemSlot.itemId) > NUM_TECHNICAL_MACHINES)
            BlitBitmapToWindow(windowId, gBagMenuHMIcon_Gfx, 8, y - 1, 16, 16);

        bool8 isHovered = ((s32)itemIndex == sHoveredItemIndex);

        if (gBagPosition.pocket != POCKET_KEY_ITEMS && GetItemImportance(itemSlot.itemId) == FALSE)
        {
            // Print item quantity
            ConvertIntToDecimalStringN(gStringVar1, itemSlot.quantity, STR_CONV_MODE_RIGHT_ALIGN, MAX_ITEM_DIGITS);
            StringExpandPlaceholders(gStringVar4, gText_xVar1);
            offset = GetStringRightAlignXOffset(FONT_NARROW, gStringVar4, 119);
            BagMenu_Print(windowId, FONT_NARROW, gStringVar4, offset, y, 0, 0, TEXT_SKIP_DRAW,
                          isHovered ? COLORID_HOVER_QTY : COLORID_NORMAL);
        }
        else
        {
            // Print registered icon
            if (gSaveBlock1Ptr->registeredItem != ITEM_NONE && gSaveBlock1Ptr->registeredItem == itemSlot.itemId)
                BlitBitmapToWindow(windowId, sRegisteredSelect_Gfx, 102, y + 4, 16, 16);
        }

        if (isHovered)
            BagMenu_Print(windowId, FONT_NARROW, gMultiuseListMenuTemplate.items[itemIndex].name,
                          sItemListMenu.item_X, y, 0, 0, TEXT_SKIP_DRAW, COLORID_HOVER_NAME);
    }
}

static void PrintItemDescription(int itemIndex)
{
    const u8 *str;
    u8 desc[200];
    u8 fontId;
    s32 maxWidth = sDefaultBagWindows[WIN_DESCRIPTION].width * 8 - 3;

    if (itemIndex != LIST_CANCEL)
    {
        str = GetItemDescription(GetBagItemId(gBagPosition.pocket, itemIndex));
    }
    else
    {
        // Print 'Cancel' description
        StringCopy(gStringVar1, gBagMenu_ReturnToStrings[gBagPosition.location]);
        StringExpandPlaceholders(gStringVar4, gText_ReturnToVar1);
        str = gStringVar4;
    }
    fontId = FormatDescriptionByWidth(desc, maxWidth, FONT_SHORT_NARROW, str, GetFontAttribute(FONT_SHORT_NARROW, FONTATTR_LETTER_SPACING));
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    AddTextPrinterParameterized4(WIN_DESCRIPTION, fontId, 3, 1, 0, 1, sFontColorTable[COLORID_NORMAL], 0, desc);
}

static void BagMenu_PrintCursor(u8 listTaskId, u8 colorIndex)
{
    BagMenu_PrintCursorAtPos(ListMenuGetYCoordForPrintingArrowCursor(listTaskId), colorIndex);
}

static void BagMenu_PrintCursorAtPos(u8 y, u8 colorIndex)
{
    if (colorIndex == COLORID_NONE)
        FillWindowPixelRect(WIN_ITEM_LIST, PIXEL_FILL(0), 0, y, GetMenuCursorDimensionByFont(FONT_NORMAL, 0), GetMenuCursorDimensionByFont(FONT_NORMAL, 1));
    else
        BagMenu_Print(WIN_ITEM_LIST, FONT_NORMAL, gText_SelectorArrow2, 0, y, 0, 0, 0, colorIndex);

}

static void CreatePocketScrollArrowPair(void)
{
    static const u8 sArrowX[2] = {104, 223};
    struct ComfyAnimEasingConfig animConfig;
    u8 i;

    if (sPocketScrollArrowSpriteIds[0] != SPRITE_NONE)
        return;

    for (i = 0; i < 2; i++)
    {
        u8 spriteId;
        u32 animId;

        InitComfyAnimConfig_Easing(&animConfig);
        animConfig.from = Q_24_8(0);
        animConfig.to = Q_24_8(0);
        animConfig.durationFrames = 1;
        animId = CreateComfyAnim_Easing(&animConfig);
        sPocketScrollArrowAnimIds[i] = animId;

        spriteId = CreateSprite(&sSpriteTemplate_PocketScrollArrows, sArrowX[i], 16, 0);
        if (spriteId != MAX_SPRITES)
        {
            StartSpriteAnim(&gSprites[spriteId], i);
            gSprites[spriteId].data[0] = animId;
            sPocketScrollArrowSpriteIds[i] = spriteId;
        }
    }
}

void BagDestroyPocketScrollArrowPair(void)
{
    u8 i;

    for (i = 0; i < 2; i++)
    {
        if (sPocketScrollArrowSpriteIds[i] != SPRITE_NONE)
        {
            DestroySprite(&gSprites[sPocketScrollArrowSpriteIds[i]]);
            sPocketScrollArrowSpriteIds[i] = SPRITE_NONE;
        }
        if (sPocketScrollArrowAnimIds[i] != INVALID_COMFY_ANIM)
        {
            ReleaseComfyAnim(sPocketScrollArrowAnimIds[i]);
            sPocketScrollArrowAnimIds[i] = INVALID_COMFY_ANIM;
        }
    }
}

static void SpriteCB_PocketScrollArrow(struct Sprite *sprite)
{
    u8 animId = (u8)sprite->data[0];
    if (animId != INVALID_COMFY_ANIM)
        sprite->x2 = ReadComfyAnimValueSmooth(&gComfyAnims[animId]);
}

static void AnimatePocketScrollArrow(s8 direction)
{
    u8 arrowIdx = (direction < 0) ? 0 : 1;
    struct ComfyAnimEasingConfig config;

    if (sPocketScrollArrowAnimIds[arrowIdx] == INVALID_COMFY_ANIM)
        return;

    InitComfyAnimConfig_Easing(&config);
    config.from = Q_24_8(direction < 0 ? -4 : 4);
    config.to = Q_24_8(0);
    config.durationFrames = 12;
    config.easingFunc = ComfyAnimEasing_EaseOutCubic;
    InitComfyAnim_Easing(&config, &gComfyAnims[sPocketScrollArrowAnimIds[arrowIdx]]);
}

static void FreeBagMenu(void)
{
    if (gBagPosition.location == ITEMMENULOCATION_FIELD
        || gBagPosition.location == ITEMMENULOCATION_BATTLE
        || gBagPosition.location == ITEMMENULOCATION_PARTY
        || gBagPosition.location == ITEMMENULOCATION_WALLY)
        BagMenu_FreePartyIcons();
    Free(sMoveTypeIconsCache);
    sMoveTypeIconsCache = NULL;
    Free(sListBuffer2);
    Free(sListBuffer1);
    FreeAllWindowBuffers();
    Free(gBagMenu);
}

void Task_FadeAndCloseBagMenu(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_CloseBagMenu;
}

static void Task_FadeAndCloseBagMenuIfMulch(u8 taskId)
{
    if (gSpecialVar_ItemId == ITEM_GROWTH_MULCH ||
        gSpecialVar_ItemId == ITEM_DAMP_MULCH ||
        gSpecialVar_ItemId == ITEM_STABLE_MULCH ||
        gSpecialVar_ItemId == ITEM_GOOEY_MULCH ||
        gSpecialVar_ItemId == ITEM_RICH_MULCH ||
        gSpecialVar_ItemId == ITEM_SURPRISE_MULCH ||
        gSpecialVar_ItemId == ITEM_BOOST_MULCH ||
        gSpecialVar_ItemId == ITEM_AMAZE_MULCH)
    {
        Task_FadeAndCloseBagMenu(taskId);
        return;
    }
    DisplayDadsAdviceCannotUseItemMessage(taskId, FALSE);
}

static void Task_CloseBagMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        DestroyListMenuTask(tListTaskId, &gBagPosition.scrollPosition[gBagPosition.pocket], &gBagPosition.cursorPosition[gBagPosition.pocket]);

        // If ready for a new screen (e.g. party menu for giving an item) go to that screen
        // Otherwise exit the bag and use callback set up when the bag was first opened
        if (gBagMenu->newScreenCallback != NULL)
            SetMainCallback2(gBagMenu->newScreenCallback);
        else
            SetMainCallback2(gBagPosition.exitCallback);

        BagDestroyPocketScrollArrowPair();
        ReleaseComfyAnim(sCursorAnimId);
        ReleaseComfyAnim(sScrollThumbAnimId);
        if (sPartyPanelItemIconAnimId != INVALID_COMFY_ANIM)
        {
            ReleaseComfyAnim(sPartyPanelItemIconAnimId);
            sPartyPanelItemIconAnimId = INVALID_COMFY_ANIM;
        }
        ResetSpriteData();
        FreeAllSpritePalettes();
        FreeBagMenu();
        DestroyTask(taskId);
    }
}

void UpdatePocketItemList(enum Pocket pocketId)
{
    if (pocketId >= POCKETS_COUNT)
        return; // shouldn't even get here

    struct BagPocket *pocket = &gBagPockets[pocketId];
    switch (pocketId)
    {
    case POCKET_TM_HM:
    case POCKET_BERRIES:
        SortItemsInBag(pocket, SORT_BY_INDEX);
        break;
    default:
        CompactItemsInBagPocket(pocketId);
        break;
    }

    gBagMenu->numItemStacks[pocketId] = 0;

    for (u32 i = 0; i < pocket->capacity && BagPocket_GetSlotData(pocket, i).itemId; i++)
        gBagMenu->numItemStacks[pocketId]++;

    if (!gBagMenu->hideCloseBagText)
        gBagMenu->numItemStacks[pocketId]++;

    if (gBagMenu->numItemStacks[pocketId] > MAX_ITEMS_SHOWN)
        gBagMenu->numShownItems[pocketId] = MAX_ITEMS_SHOWN;
    else
        gBagMenu->numShownItems[pocketId] = gBagMenu->numItemStacks[pocketId];
}

static void UpdatePocketItemLists(void)
{
    u8 i;
    for (i = 0; i < POCKETS_COUNT; i++)
        UpdatePocketItemList(i);
}

void UpdatePocketListPosition(u8 pocketId)
{
    SetCursorWithinListBounds(&gBagPosition.scrollPosition[pocketId], &gBagPosition.cursorPosition[pocketId], gBagMenu->numShownItems[pocketId], gBagMenu->numItemStacks[pocketId]);
}

static void InitPocketListPositions(void)
{
    u8 i;
    for (i = 0; i < POCKETS_COUNT; i++)
        UpdatePocketListPosition(i);
}

static void InitPocketScrollPositions(void)
{
    u8 i;
    for (i = 0; i < POCKETS_COUNT; i++)
        SetCursorScrollWithinListBounds(&gBagPosition.scrollPosition[i], &gBagPosition.cursorPosition[i], gBagMenu->numShownItems[i], gBagMenu->numItemStacks[i], MAX_ITEMS_SHOWN);
}

u8 GetItemListPosition(u8 pocketId)
{
    return gBagPosition.scrollPosition[pocketId] + gBagPosition.cursorPosition[pocketId];
}

void DisplayItemMessage(u8 taskId, u8 fontId, const u8 *str, TaskFunc callback)
{
    s16 *data = gTasks[taskId].data;

    tMsgWindowId = AddItemMessageWindow(ITEMWIN_MESSAGE);
    FillWindowPixelBuffer(tMsgWindowId, PIXEL_FILL(1));
    DisplayMessageAndContinueTask(taskId, tMsgWindowId, 10, 13, fontId, GetPlayerTextSpeedDelay(), str, callback);
    ScheduleBgCopyTilemapToVram(0);
}

void CloseItemMessage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];
    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    DestroyListMenuTask(tListTaskId, scrollPos, cursorPos);
    UpdatePocketItemList(gBagPosition.pocket);
    UpdatePocketListPosition(gBagPosition.pocket);
    LoadBagItemListBuffers(gBagPosition.pocket);
    tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    ScheduleBgCopyTilemapToVram(1);
    ReturnToItemList(taskId);
}

static void AddItemQuantityWindow(u8 windowType)
{
    PrintItemQuantity(BagMenu_AddWindow(windowType), 1);
}

static void PrintItemQuantity(u8 windowId, s16 quantity)
{
    ConvertIntToDecimalStringN(gStringVar1, quantity, STR_CONV_MODE_LEADING_ZEROS, MAX_ITEM_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar4, GetStringCenterAlignXOffset(FONT_NORMAL, gStringVar4, 0x28), 2, 0, 0);
}

static void Task_BagMenu_HandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];
    s32 listPosition;

    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE && !gPaletteFade.active)
    {
        switch (GetSwitchBagPocketDirection())
        {
        case SWITCH_POCKET_LEFT:
            SwitchBagPocket(taskId, MENU_CURSOR_DELTA_LEFT, FALSE);
            return;
        case SWITCH_POCKET_RIGHT:
            SwitchBagPocket(taskId, MENU_CURSOR_DELTA_RIGHT, FALSE);
            return;
        default:
            if (JOY_NEW(SELECT_BUTTON))
            {
                bool8 pocketEmpty = gBagMenu->numItemStacks[gBagPosition.pocket] == (u8)(!gBagMenu->hideCloseBagText);
                if (!pocketEmpty && gBagPosition.pocket == POCKET_TM_HM)
                {
                    PlaySE(SE_SELECT);
                    SwitchMoveInfoMode(sHoveredItemIndex);
                }
#if SWSH_ITEM_MENU_BERRY_INFO
                else if (!pocketEmpty && gBagPosition.pocket == POCKET_BERRIES)
                {
                    PlaySE(SE_SELECT);
                    SwitchBerryInfoMode(sHoveredItemIndex);
                }
#endif
                else if (!pocketEmpty && CanSwapItems() == TRUE)
                {
                    ListMenuGetScrollAndRow(tListTaskId, scrollPos, cursorPos);
                    if (gBagMenu->hideCloseBagText || (*scrollPos + *cursorPos) != gBagMenu->numItemStacks[gBagPosition.pocket] - 1)
                    {
                        PlaySE(SE_SELECT);
                        StartItemSwap(taskId);
                    }
                }
                return;
            }
            else if (JOY_NEW(START_BUTTON))
            {
                if ((gBagMenu->numItemStacks[gBagPosition.pocket] - 1) <= 1) //can't sort with 0 or 1 item in bag
                {
                    static const u8 sText_NothingToSort[] = _("There's nothing to sort!");
                    PlaySE(SE_FAILURE);
                    DisplayItemMessage(taskId, 1, sText_NothingToSort, HandleErrorMessage);
                    break;
                }
                else
                {
                    struct ItemSlot tempItem;
                    data[1] = GetItemListPosition(gBagPosition.pocket);
                    tempItem = GetBagItemIdAndQuantity(gBagPosition.pocket, data[1]);
                    data[2] = tempItem.quantity;
                    if (gBagPosition.cursorPosition[gBagPosition.pocket] == gBagMenu->numItemStacks[gBagPosition.pocket])
                        break;
                    else
                        gSpecialVar_ItemId = tempItem.itemId;

                    PlaySE(SE_SELECT);
                    BagDestroyPocketScrollArrowPair();
                    BagMenu_PrintCursor(tListTaskId, COLORID_NONE);
                    ListMenuGetScrollAndRow(data[0], scrollPos, cursorPos);
                    gTasks[taskId].func = Task_LoadBagSortOptions;
                    return;
                }
            }
            break;
        }

        listPosition = ListMenu_ProcessInput(tListTaskId);
        ListMenuGetScrollAndRow(tListTaskId, scrollPos, cursorPos);
        switch (listPosition)
        {
        case LIST_NOTHING_CHOSEN:
            break;
        case LIST_CANCEL:
            if (gBagPosition.location == ITEMMENULOCATION_BERRY_BLENDER_CRUSH)
            {
                PlaySE(SE_FAILURE);
                break;
            }
            PlaySE(SE_SELECT);
            gSpecialVar_ItemId = ITEM_NONE;
            gTasks[taskId].func = Task_FadeAndCloseBagMenu;
            break;
        default: // A_BUTTON
            {
                struct ItemSlot itemSlot = GetBagItemIdAndQuantity(gBagPosition.pocket, listPosition);
                PlaySE(SE_SELECT);
                BagMenu_PrintCursor(tListTaskId, COLORID_NONE);
                tListPosition = listPosition;
                gSpecialVar_ItemId = itemSlot.itemId;
                tQuantity = itemSlot.quantity;
                sContextMenuFuncs[gBagPosition.location](taskId);
            }
            break;
        }
    }
}

static void ReturnToItemList(u8 taskId)
{
    CreatePocketScrollArrowPair();
    if (gBagPosition.pocket == POCKET_TM_HM && sMoveInfoMode == 1)
    {
        PutWindowTilemap(WIN_PP_LABEL);
        PutWindowTilemap(WIN_PP_INFO);
        PutWindowTilemap(WIN_POW_ACC_LABEL);
        PutWindowTilemap(WIN_POW_ACC_INFO);
    }
#if SWSH_ITEM_MENU_TMHM_CONTEST_INFO
    else if (gBagPosition.pocket == POCKET_TM_HM && sMoveInfoMode == 3)
    {
        PutWindowTilemap(WIN_PP_LABEL);
        PutWindowTilemap(WIN_PP_INFO);
        PutWindowTilemap(WIN_APP_JAM_LABEL);
    }
#endif
    else
    {
        PutWindowTilemap(WIN_DESCRIPTION);
    }
    ScheduleBgCopyTilemapToVram(1);
    gTasks[taskId].func = Task_BagMenu_HandleInput;
}

static u8 GetSwitchBagPocketDirection(void)
{
    u8 LRKeys;
    if (gBagMenu->pocketSwitchDisabled)
        return SWITCH_POCKET_NONE;
    LRKeys = GetLRKeysPressed();
    if (JOY_NEW(DPAD_LEFT) || LRKeys == MENU_L_PRESSED)
    {
        PlaySE(SE_SELECT);
        return SWITCH_POCKET_LEFT;
    }
    if (JOY_NEW(DPAD_RIGHT) || LRKeys == MENU_R_PRESSED)
    {
        PlaySE(SE_SELECT);
        return SWITCH_POCKET_RIGHT;
    }
    return SWITCH_POCKET_NONE;
}

static void ChangeBagPocketId(u8 *bagPocketId, s8 deltaBagPocketId)
{
    if (deltaBagPocketId == MENU_CURSOR_DELTA_RIGHT && *bagPocketId == POCKETS_COUNT - 1)
        *bagPocketId = 0;
    else if (deltaBagPocketId == MENU_CURSOR_DELTA_LEFT && *bagPocketId == 0)
        *bagPocketId = POCKETS_COUNT - 1;
    else
        *bagPocketId += deltaBagPocketId;
}

static void SwitchBagPocket(u8 taskId, s16 deltaBagPocketId, bool16 skipEraseList)
{
    s16 *data = gTasks[taskId].data;
    u8 newPocket;

    tPocketSwitchState = 0;
    tPocketSwitchTimer = 0;
    tPocketSwitchDir = deltaBagPocketId;
    AnimatePocketScrollArrow(deltaBagPocketId);
    newPocket = gBagPosition.pocket;
    ChangeBagPocketId(&newPocket, deltaBagPocketId);
    if (!skipEraseList)
    {
        if (gBagPosition.pocket == POCKET_TM_HM && sMoveInfoMode)
        {
            if (sMoveTypeIconSpriteId != SPRITE_NONE)
            {
                DestroySprite(&gSprites[sMoveTypeIconSpriteId]);
                FreeSpriteTilesByTag(TAG_MOVE_TYPE_ICON);
                sMoveTypeIconSpriteId = SPRITE_NONE;
            }
            if (sCategoryIconSpriteId != SPRITE_NONE)
            {
                DestroySprite(&gSprites[sCategoryIconSpriteId]);
                FreeSpriteTilesByTag(TAG_CATEGORY_ICON);
                sCategoryIconSpriteId = SPRITE_NONE;
            }
            ClearWindowTilemap(WIN_PP_LABEL);
            ClearWindowTilemap(WIN_POW_ACC_LABEL);
            ClearWindowTilemap(WIN_PP_INFO);
            ClearWindowTilemap(WIN_POW_ACC_INFO);
#if SWSH_ITEM_MENU_TMHM_CONTEST_INFO
            ClearWindowTilemap(WIN_APP_JAM_LABEL);
            FillBgTilemapBufferRect_Palette0(2, 4, 21, 16, 4, 4);
#endif
            sMoveInfoMode = 0;
        }
#if SWSH_ITEM_MENU_BERRY_INFO
        if (gBagPosition.pocket == POCKET_BERRIES && sBerryInfoMode)
        {
            if (sBerryInfoMode == 1)
            {
                u8 i;
                for (i = 0; i < FLAVOR_COUNT; i++)
                {
                    if (sBerryFlavorMarkSpriteIds[i] != SPRITE_NONE)
                    {
                        DestroySprite(&gSprites[sBerryFlavorMarkSpriteIds[i]]);
                        sBerryFlavorMarkSpriteIds[i] = SPRITE_NONE;
                    }
                }
                FreeSpriteTilesByTag(TAG_BERRY_FLAVOR_MARK);
                ClearWindowTilemap(WIN_BERRY_INFO);
                ClearWindowTilemap(WIN_BERRY_FLAVORS);
            }
            sBerryInfoMode = 0;
        }
#endif
        {
            bool8 srcHasInfoPrompt = (gBagPosition.pocket == POCKET_TM_HM);
            bool8 destHasInfoPrompt = (newPocket == POCKET_TM_HM);
#if SWSH_ITEM_MENU_BERRY_INFO
            srcHasInfoPrompt |= (gBagPosition.pocket == POCKET_BERRIES);
            destHasInfoPrompt |= (newPocket == POCKET_BERRIES);
#endif
            if (srcHasInfoPrompt && !destHasInfoPrompt)
                FillBgTilemapBufferRect_Palette0(2, 4, 27, 16, 3, 4);
        }
        ClearWindowTilemap(WIN_ITEM_LIST);
        ClearWindowTilemap(WIN_DESCRIPTION);
        DestroyListMenuTask(tListTaskId, &gBagPosition.scrollPosition[gBagPosition.pocket], &gBagPosition.cursorPosition[gBagPosition.pocket]);
        ScheduleBgCopyTilemapToVram(1);
        gSprites[gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + (gBagMenu->itemIconSlot ^ 1)]].invisible = TRUE;
    }
    PrintPocketName(sPocketNamesStringsTable[newPocket]);
    FillBgTilemapBufferRect_Palette0(2, 4, 14, sDefaultBagWindows[WIN_ITEM_LIST].tilemapTop, sDefaultBagWindows[WIN_ITEM_LIST].width, sDefaultBagWindows[WIN_ITEM_LIST].height);
    ScheduleBgCopyTilemapToVram(2);
    SetTaskFuncWithFollowupFunc(taskId, Task_SwitchBagPocket, gTasks[taskId].func);
}

static void Task_SwitchBagPocket(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!MenuHelpers_IsLinkActive() && !IsWallysBag())
    {
        switch (GetSwitchBagPocketDirection())
        {
        case SWITCH_POCKET_LEFT:
            ChangeBagPocketId(&gBagPosition.pocket, tPocketSwitchDir);
            SwitchTaskToFollowupFunc(taskId);
            SwitchBagPocket(taskId, MENU_CURSOR_DELTA_LEFT, TRUE);
            return;
        case SWITCH_POCKET_RIGHT:
            ChangeBagPocketId(&gBagPosition.pocket, tPocketSwitchDir);
            SwitchTaskToFollowupFunc(taskId);
            SwitchBagPocket(taskId, MENU_CURSOR_DELTA_RIGHT, TRUE);
            return;
        }
    }
    switch (tPocketSwitchState)
    {
    case 0:
        DrawItemListBgRow(tPocketSwitchTimer);
        if (++tPocketSwitchTimer == 6)
            tPocketSwitchState++;
        break;
    case 1:
        ChangeBagPocketId(&gBagPosition.pocket, tPocketSwitchDir);
        LoadBagItemListBuffers(gBagPosition.pocket);
        tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, gBagPosition.scrollPosition[gBagPosition.pocket], gBagPosition.cursorPosition[gBagPosition.pocket]);
        PutWindowTilemap(WIN_DESCRIPTION);
        PutWindowTilemap(WIN_POCKET_NAME);
        ScheduleBgCopyTilemapToVram(1);
        if (gBagPosition.pocket == POCKET_TM_HM)
        {
            ShowInfoPrompt(sBattleStatPrompt_Tilemap);
        }
#if SWSH_ITEM_MENU_BERRY_INFO
        else if (gBagPosition.pocket == POCKET_BERRIES)
        {
            ShowInfoPrompt(sBerryStatPrompt_Tilemap);
        }
#endif
        CreatePocketScrollArrowPair();
        SwitchTaskToFollowupFunc(taskId);
    }
}

static void DrawItemListBgRow(u8 y)
{
    FillBgTilemapBufferRect_Palette0(2, 4, 14, y + sDefaultBagWindows[WIN_ITEM_LIST].tilemapTop, sDefaultBagWindows[WIN_ITEM_LIST].width, 1);
    ScheduleBgCopyTilemapToVram(2);
}

static bool8 CanSwapItems(void)
{
    // Swaps can only be done from the field or in battle (as opposed to while selling items, for example)
    if (gBagPosition.location == ITEMMENULOCATION_FIELD
     || gBagPosition.location == ITEMMENULOCATION_BATTLE)
    {
        // TMHMs and berries are numbered, and so may not be swapped
        if (gBagPosition.pocket != POCKET_TM_HM
         && gBagPosition.pocket != POCKET_BERRIES)
            return TRUE;
    }
    return FALSE;
}

static void StartItemSwap(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s16 cursorY = ReadComfyAnimValueSmooth(&gComfyAnims[sCursorAnimId]);

    tListPosition = gBagPosition.scrollPosition[gBagPosition.pocket] + gBagPosition.cursorPosition[gBagPosition.pocket];
    gBagMenu->toSwapPos = tListPosition;
    gSprites[sCursorSpriteId].invisible = TRUE;
    sSwapCursorSpriteId = CreateSprite(&sSpriteTemplate_SwapCursor, 84, cursorY, 1);
    gTasks[taskId].func = Task_HandleSwappingItemsInput;
}

static void Task_HandleSwappingItemsInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 pocket = gBagPosition.pocket;
    u16 *scrollPos = &gBagPosition.scrollPosition[pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[pocket];
    u8 lastRealPos = gBagMenu->numItemStacks[pocket] - (gBagMenu->hideCloseBagText ? 1 : 2);

    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        if (JOY_NEW(SELECT_BUTTON | A_BUTTON | B_BUTTON))
        {
            PlaySE(SE_SELECT);
            gBagMenu->toSwapPos = NOT_SWAPPING;
            DestroySprite(&gSprites[sSwapCursorSpriteId]);
            sSwapCursorSpriteId = SPRITE_NONE;
            gSprites[sCursorSpriteId].invisible = FALSE;
            gTasks[taskId].func = Task_BagMenu_HandleInput;
        }
        else if (JOY_REPEAT(DPAD_DOWN) && tListPosition < lastRealPos)
        {
            MoveItemSlotInPocket(pocket, tListPosition, tListPosition + 2);
            tListPosition++;
            gBagMenu->toSwapPos = tListPosition;
            LoadBagItemListBuffers(pocket);
            ListMenu_ProcessInput(tListTaskId);
            ListMenuGetScrollAndRow(tListTaskId, scrollPos, cursorPos);
        }
        else if (JOY_REPEAT(DPAD_UP) && tListPosition > 0)
        {
            MoveItemSlotInPocket(pocket, tListPosition, tListPosition - 1);
            tListPosition--;
            gBagMenu->toSwapPos = tListPosition;
            LoadBagItemListBuffers(pocket);
            ListMenu_ProcessInput(tListTaskId);
            ListMenuGetScrollAndRow(tListTaskId, scrollPos, cursorPos);
        }
    }
}

static void OpenContextMenu(u8 taskId)
{
    switch (gBagPosition.location)
    {
    case ITEMMENULOCATION_BATTLE:
    case ITEMMENULOCATION_WALLY:
        if (GetItemBattleUsage(gSpecialVar_ItemId))
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_BattleUse;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_BattleUse);
        }
        else
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
        }
        break;
    case ITEMMENULOCATION_BERRY_BLENDER_CRUSH:
        gBagMenu->contextMenuItemsPtr = sContextMenuItems_BerryBlenderCrush;
        gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_BerryBlenderCrush);
        break;
    case ITEMMENULOCATION_APPRENTICE:
        if (!GetItemImportance(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY_E_READER)
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_Apprentice;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Apprentice);
        }
        else
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
        }
        break;
    case ITEMMENULOCATION_FAVOR_LADY:
        if (!GetItemImportance(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY_E_READER)
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_FavorLady;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_FavorLady);
        }
        else
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
        }
        break;
    case ITEMMENULOCATION_QUIZ_LADY:
        if (!GetItemImportance(gSpecialVar_ItemId) && gSpecialVar_ItemId != ITEM_ENIGMA_BERRY_E_READER)
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_QuizLady;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_QuizLady);
        }
        else
        {
            gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
            gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
        }
        break;
    case ITEMMENULOCATION_PARTY:
    case ITEMMENULOCATION_SHOP:
    case ITEMMENULOCATION_BERRY_TREE:
    case ITEMMENULOCATION_ITEMPC:
    case ITEMMENULOCATION_BERRY_TREE_MULCH:
    default:
        if (MenuHelpers_IsLinkActive() == TRUE || InUnionRoom() == TRUE)
        {
            if (gBagPosition.pocket == POCKET_KEY_ITEMS || !IsHoldingItemAllowed(gSpecialVar_ItemId))
            {
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_Cancel;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Cancel);
            }
            else
            {
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_Give;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_Give);
            }
        }
        else
        {
            switch (gBagPosition.pocket)
            {
            case POCKET_ITEMS:
                gBagMenu->contextMenuItemsPtr = gBagMenu->contextMenuItemsBuffer;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_ItemsPocket);
                memcpy(&gBagMenu->contextMenuItemsBuffer, &sContextMenuItems_ItemsPocket, sizeof(sContextMenuItems_ItemsPocket));
                if (ItemIsMail(gSpecialVar_ItemId) == TRUE)
                    gBagMenu->contextMenuItemsBuffer[0] = ACTION_CHECK;
                break;
            case POCKET_KEY_ITEMS:
                gBagMenu->contextMenuItemsPtr = gBagMenu->contextMenuItemsBuffer;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_KeyItemsPocket);
                memcpy(&gBagMenu->contextMenuItemsBuffer, &sContextMenuItems_KeyItemsPocket, sizeof(sContextMenuItems_KeyItemsPocket));
                if (gSaveBlock1Ptr->registeredItem == gSpecialVar_ItemId)
                    gBagMenu->contextMenuItemsBuffer[1] = ACTION_DESELECT;
                if (gSpecialVar_ItemId == ITEM_MACH_BIKE || gSpecialVar_ItemId == ITEM_ACRO_BIKE || gSpecialVar_ItemId == ITEM_BICYCLE)
                {
                    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
                        gBagMenu->contextMenuItemsBuffer[0] = ACTION_WALK;
                }
                break;
            case POCKET_POKE_BALLS:
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_BallsPocket;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_BallsPocket);
                break;
            case POCKET_TM_HM:
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_TmHmPocket;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_TmHmPocket);
                break;
            case POCKET_BERRIES:
                gBagMenu->contextMenuItemsPtr = sContextMenuItems_BerriesPocket;
                gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_BerriesPocket);
                break;
            }
        }
    }
    if (gBagMenu->contextMenuNumItems == 1)
        PrintContextMenuItems(BagMenu_AddWindow(ITEMWIN_1x1));
    else if (gBagMenu->contextMenuNumItems == 2)
        PrintContextMenuItems(BagMenu_AddWindow(ITEMWIN_1x2));
    else if (gBagMenu->contextMenuNumItems == 4)
        PrintContextMenuItemGrid(BagMenu_AddWindow(ITEMWIN_2x2), 2, 2);
    else
        PrintContextMenuItemGrid(BagMenu_AddWindow(ITEMWIN_2x3), 2, 3);
}

static void PrintContextMenuItems(u8 windowId)
{
    PrintMenuActionTexts(windowId, FONT_NARROW, 8, 1, 0, 16, gBagMenu->contextMenuNumItems, sItemMenuActions, gBagMenu->contextMenuItemsPtr);
    InitMenuInUpperLeftCornerNormal(windowId, gBagMenu->contextMenuNumItems, 0);
}

static void PrintContextMenuItemGrid(u8 windowId, u8 columns, u8 rows)
{
    PrintMenuActionGrid(windowId, FONT_NARROW, 8, 1, 56, columns, rows, sItemMenuActions, gBagMenu->contextMenuItemsPtr);
    InitMenuActionGrid(windowId, 56, columns, rows, 0);
}

static void Task_ItemContext_Normal(u8 taskId)
{
    OpenContextMenu(taskId);

    // Context menu width is never greater than 2 columns, so if
    // there are more than 2 items then there are multiple rows
    if (gBagMenu->contextMenuNumItems <= 2)
        gTasks[taskId].func = Task_ItemContext_SingleRow;
    else
        gTasks[taskId].func = Task_ItemContext_MultipleRows;
}

static void Task_ItemContext_SingleRow(u8 taskId)
{
    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        s8 selection = Menu_ProcessInputNoWrap();
        switch (selection)
        {
        case MENU_NOTHING_CHOSEN:
            break;
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            sItemMenuActions[ACTION_CANCEL].func.void_u8(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            sItemMenuActions[gBagMenu->contextMenuItemsPtr[selection]].func.void_u8(taskId);
            break;
        }
    }
}

static void Task_ItemContext_MultipleRows(u8 taskId)
{
    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        s8 cursorPos = Menu_GetCursorPos();
        if (JOY_NEW(DPAD_UP))
        {
            if (cursorPos > 0 && IsValidContextMenuPos(cursorPos - 2))
            {
                PlaySE(SE_SELECT);
                ChangeMenuGridCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_UP);
            }
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (cursorPos < (gBagMenu->contextMenuNumItems - 2) && IsValidContextMenuPos(cursorPos + 2))
            {
                PlaySE(SE_SELECT);
                ChangeMenuGridCursorPosition(MENU_CURSOR_DELTA_NONE, MENU_CURSOR_DELTA_DOWN);
            }
        }
        else if (JOY_NEW(DPAD_LEFT) || GetLRKeysPressed() == MENU_L_PRESSED)
        {
            if ((cursorPos & 1) && IsValidContextMenuPos(cursorPos - 1))
            {
                PlaySE(SE_SELECT);
                ChangeMenuGridCursorPosition(MENU_CURSOR_DELTA_LEFT, MENU_CURSOR_DELTA_NONE);
            }
        }
        else if (JOY_NEW(DPAD_RIGHT) || GetLRKeysPressed() == MENU_R_PRESSED)
        {
            if (!(cursorPos & 1) && IsValidContextMenuPos(cursorPos + 1))
            {
                PlaySE(SE_SELECT);
                ChangeMenuGridCursorPosition(MENU_CURSOR_DELTA_RIGHT, MENU_CURSOR_DELTA_NONE);
            }
        }
        else if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            sItemMenuActions[gBagMenu->contextMenuItemsPtr[cursorPos]].func.void_u8(taskId);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            sItemMenuActions[ACTION_CANCEL].func.void_u8(taskId);
        }
    }
}

static bool8 IsValidContextMenuPos(s8 cursorPos)
{
    if (cursorPos < 0)
        return FALSE;
    if (cursorPos > gBagMenu->contextMenuNumItems)
        return FALSE;
    if (gBagMenu->contextMenuItemsPtr[cursorPos] == ACTION_DUMMY)
        return FALSE;
    return TRUE;
}

static void RemoveContextWindow(void)
{
    if (gBagMenu->contextMenuNumItems == 1)
        BagMenu_RemoveWindow(ITEMWIN_1x1);
    else if (gBagMenu->contextMenuNumItems == 2)
        BagMenu_RemoveWindow(ITEMWIN_1x2);
    else if (gBagMenu->contextMenuNumItems == 4)
        BagMenu_RemoveWindow(ITEMWIN_2x2);
    else
        BagMenu_RemoveWindow(ITEMWIN_2x3);
}

static void ItemMenu_UseOutOfBattle(u8 taskId)
{
    if (GetItemFieldFunc(gSpecialVar_ItemId))
    {
        RemoveContextWindow();
        if (CalculatePlayerPartyCount() == 0 && GetItemType(gSpecialVar_ItemId) == ITEM_USE_PARTY_MENU)
        {
            PrintThereIsNoPokemon(taskId);
        }
        else
        {
            FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
            ScheduleBgCopyTilemapToVram(1);
            if (gBagPosition.pocket != POCKET_BERRIES)
                GetItemFieldFunc(gSpecialVar_ItemId)(taskId);
            else
                ItemUseOutOfBattle_Berry(taskId);
        }
    }
}

static void ItemMenu_Toss(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    RemoveContextWindow();
    tItemCount = 1;
    if (tQuantity == 1)
    {
        AskTossItems(taskId);
    }
    else
    {
        u8 *end = CopyItemNameHandlePlural(gSpecialVar_ItemId, gStringVar1, 2);
        WrapFontIdToFit(gStringVar1, end, FONT_NORMAL, WindowWidthPx(WIN_DESCRIPTION) - 10 - 6);
        StringExpandPlaceholders(gStringVar4, gText_TossHowManyVar1s);
        FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
        BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, gStringVar4, 3, 1, 0, 0, 0, COLORID_NORMAL);
        AddItemQuantityWindow(ITEMWIN_QUANTITY);
        gTasks[taskId].func = Task_ChooseHowManyToToss;
    }
}

static void AskTossItems(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u8 *end = CopyItemNameHandlePlural(gSpecialVar_ItemId, gStringVar1, tItemCount);
    WrapFontIdToFit(gStringVar1, end, FONT_NORMAL, WindowWidthPx(WIN_DESCRIPTION) - 10 - 6);
    ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_ConfirmTossItems);
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, gStringVar4, 3, 1, 0, 0, 0, COLORID_NORMAL);
    BagMenu_YesNo(taskId, ITEMWIN_YESNO_LOW, &sYesNoTossFunctions);
}

static void CancelToss(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    PrintItemDescription(tListPosition);
    BagMenu_PrintCursor(tListTaskId, COLORID_NONE);
    ReturnToItemList(taskId);
}

static void Task_ChooseHowManyToToss(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, tQuantity) == TRUE)
    {
        PrintItemQuantity(gBagMenu->windowIds[ITEMWIN_QUANTITY], tItemCount);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY);
        AskTossItems(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY);
        CancelToss(taskId);
    }
}

static void ConfirmToss(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u8 *end = CopyItemNameHandlePlural(gSpecialVar_ItemId, gStringVar1, tItemCount);
    WrapFontIdToFit(gStringVar1, end, FONT_NORMAL, WindowWidthPx(WIN_DESCRIPTION) - 10 - 6);
    ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_ThrewAwayVar2Var1s);
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, gStringVar4, 3, 1, 0, 0, 0, COLORID_NORMAL);
    if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE || FlagGet(FLAG_STORING_ITEMS_IN_PYRAMID_BAG) == TRUE)
        gTasks[taskId].func = Task_RemoveItemFromBag;
    else
        gTasks[taskId].func = Task_TossItemFromBag;
}

static void Task_TossItemFromBag(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];

    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        RemoveBagItemFromSlot(&gBagPockets[gBagPosition.pocket], *scrollPos + *cursorPos, tItemCount);
        DestroyListMenuTask(tListTaskId, scrollPos, cursorPos);
        UpdatePocketItemList(gBagPosition.pocket);
        UpdatePocketListPosition(gBagPosition.pocket);
        LoadBagItemListBuffers(gBagPosition.pocket);
        tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
        ScheduleBgCopyTilemapToVram(1);
        ReturnToItemList(taskId);
    }
}

// Remove selected item(s) from the bag and update list
// For when items are deposited
static void Task_RemoveItemFromBag(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];

    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        RemoveBagItem(gSpecialVar_ItemId, tItemCount);
        DestroyListMenuTask(tListTaskId, scrollPos, cursorPos);
        UpdatePocketItemList(gBagPosition.pocket);
        UpdatePocketListPosition(gBagPosition.pocket);
        LoadBagItemListBuffers(gBagPosition.pocket);
        tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
        ScheduleBgCopyTilemapToVram(1);
        ReturnToItemList(taskId);
    }
}

static void ItemMenu_Register(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];

    if (gSaveBlock1Ptr->registeredItem == gSpecialVar_ItemId)
        gSaveBlock1Ptr->registeredItem = ITEM_NONE;
    else
        gSaveBlock1Ptr->registeredItem = gSpecialVar_ItemId;
    DestroyListMenuTask(tListTaskId, scrollPos, cursorPos);
    LoadBagItemListBuffers(gBagPosition.pocket);
    tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    ScheduleBgCopyTilemapToVram(1);
    ItemMenu_Cancel(taskId);
}

static void ItemMenu_Give(u8 taskId)
{
    RemoveContextWindow();
    if (!IsWritingMailAllowed(gSpecialVar_ItemId))
    {
        DisplayItemMessage(taskId, FONT_NORMAL, gText_CantWriteMail, HandleErrorMessage);
    }
    else if (!GetItemImportance(gSpecialVar_ItemId))
    {
        if (CalculatePlayerPartyCount() == 0)
        {
            PrintThereIsNoPokemon(taskId);
        }
        else
        {
#if SWSH_ITEM_MENU_ACTION_IN_BAG
            BagMenu_OpenPartyPanelSelect(taskId);
#else
            gBagMenu->newScreenCallback = CB2_ChooseMonToGiveItem;
            Task_FadeAndCloseBagMenu(taskId);
#endif
        }
    }
    else
    {
        PrintItemCantBeHeld(taskId);
    }
}

static void PrintThereIsNoPokemon(u8 taskId)
{
    DisplayItemMessage(taskId, FONT_NORMAL, gText_NoPokemon, HandleErrorMessage);
}

static void PrintItemCantBeHeld(u8 taskId)
{
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_Var1CantBeHeld);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, HandleErrorMessage);
}

static void HandleErrorMessage(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        CloseItemMessage(taskId);
    }
}

static void ItemMenu_CheckTag(u8 taskId)
{
    gBagMenu->newScreenCallback = DoBerryTagScreen;
    Task_FadeAndCloseBagMenu(taskId);
}

static void ItemMenu_Cancel(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    RemoveContextWindow();
    PrintItemDescription(tListPosition);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(0);
    BagMenu_PrintCursor(tListTaskId, COLORID_NONE);
    ReturnToItemList(taskId);
}

static void ItemMenu_UseInBattle(u8 taskId)
{
    // Safety check
    enum ItemType type = GetItemType(gSpecialVar_ItemId);
    if (!GetItemBattleUsage(gSpecialVar_ItemId))
        return;

    RemoveContextWindow();
    if (type == ITEM_USE_BAG_MENU || (type == ITEM_USE_BATTLER && !IsDoubleBattle()))
        ItemUseInBattle_BagMenu(taskId);
    else if (type == ITEM_USE_PARTY_MENU || (type == ITEM_USE_BATTLER && IsDoubleBattle()))
        ItemUseInBattle_PartyMenu(taskId);
    else if (type == ITEM_USE_PARTY_MENU_MOVES)
        ItemUseInBattle_PartyMenuChooseMove(taskId);
}

void CB2_ReturnToBagMenuPocket(void)
{
    GoToBagMenu(ITEMMENULOCATION_LAST, POCKETS_COUNT, NULL);
}

static void Task_ItemContext_GiveToParty(u8 taskId)
{
    if (!IsWritingMailAllowed(gSpecialVar_ItemId))
    {
        DisplayItemMessage(taskId, FONT_NORMAL, gText_CantWriteMail, HandleErrorMessage);
    }
    else if (!IsHoldingItemAllowed(gSpecialVar_ItemId))
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar1);
        StringExpandPlaceholders(gStringVar4, sText_Var1CantBeHeldHere);
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, HandleErrorMessage);
    }
    else if (gBagPosition.pocket != POCKET_KEY_ITEMS && !GetItemImportance(gSpecialVar_ItemId))
    {
        Task_FadeAndCloseBagMenu(taskId);
    }
    else
    {
        PrintItemCantBeHeld(taskId);
    }
}

// Selected item to give to a Pokémon in PC storage
static void Task_ItemContext_GiveToPC(u8 taskId)
{
    if (ItemIsMail(gSpecialVar_ItemId) == TRUE)
        DisplayItemMessage(taskId, FONT_NORMAL, gText_CantWriteMail, HandleErrorMessage);
    else if (gBagPosition.pocket != POCKET_KEY_ITEMS && !GetItemImportance(gSpecialVar_ItemId))
        gTasks[taskId].func = Task_FadeAndCloseBagMenu;
    else
        PrintItemCantBeHeld(taskId);
}

#define tUsingRegisteredKeyItem data[3] // See usage in item_use.c

bool8 UseRegisteredKeyItemOnField(void)
{
    u8 taskId;

    if (InUnionRoom() == TRUE || CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE || InBattlePike() || InMultiPartnerRoom() == TRUE)
        return FALSE;
    HideMapNamePopUpWindow();
    ChangeBgY_ScreenOff(0, 0, BG_COORD_SET);
    if (gSaveBlock1Ptr->registeredItem != ITEM_NONE)
    {
        if (CheckBagHasItem(gSaveBlock1Ptr->registeredItem, 1) == TRUE)
        {
            LockPlayerFieldControls();
            FreezeObjectEvents();
            PlayerFreeze();
            StopPlayerAvatar();
            gSpecialVar_ItemId = gSaveBlock1Ptr->registeredItem;
            taskId = CreateTask(GetItemFieldFunc(gSaveBlock1Ptr->registeredItem), 8);
            gTasks[taskId].tUsingRegisteredKeyItem = TRUE;
            return TRUE;
        }
        else
        {
            gSaveBlock1Ptr->registeredItem = ITEM_NONE;
        }
    }
    ScriptContext_SetupScript(EventScript_SelectWithoutRegisteredItem);
    return TRUE;
}

#undef tUsingRegisteredKeyItem

static void Task_ItemContext_Sell(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (GetItemPrice(gSpecialVar_ItemId) == 0 || GetItemImportance(gSpecialVar_ItemId))
    {
        CopyItemName(gSpecialVar_ItemId, gStringVar2);
        StringExpandPlaceholders(gStringVar4, gText_CantBuyKeyItem);
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, CloseItemMessage);
    }
    else
    {
        tItemCount = 1;
        if (tQuantity == 1)
        {
            DisplaySellItemPriceAndConfirm(taskId);
        }
        else
        {
            u32 maxQuantity = MAX_MONEY / GetItemSellPrice(gSpecialVar_ItemId);

            if (tQuantity > maxQuantity)
                tQuantity = maxQuantity;

            CopyItemName(gSpecialVar_ItemId, gStringVar2);
            StringExpandPlaceholders(gStringVar4, gText_HowManyToSell);
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, InitSellHowManyInput);
        }
    }
}

static void DisplaySellItemPriceAndConfirm(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    ConvertIntToDecimalStringN(gStringVar1, GetItemSellPrice(gSpecialVar_ItemId) * tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_MONEY_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_ICanPayVar1);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, AskSellItems);
}

static void AskSellItems(u8 taskId)
{
    if (gBagMenu->windowIds[ITEMWIN_SELL_QUANTITY] != WINDOW_NONE)
    {
        DestroyQuantityFrameSprites();
        BagMenu_RemoveWindow(ITEMWIN_SELL_QUANTITY);
    }
    BagMenu_YesNo(taskId, ITEMWIN_YESNO_HIGH, &sYesNoSellItemFunctions);
}

static void CancelSell(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    BagMenu_PrintCursor(tListTaskId, COLORID_NONE);
    ReturnToItemList(taskId);
}

static void InitSellHowManyInput(u8 taskId)
{
    u8 windowId;

    CreateQuantityFrameSprites();
    windowId = BagMenu_AddWindowNoFrame(ITEMWIN_SELL_QUANTITY);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    PrintQuantity(windowId, 1);
    PrintSellPrice(gSpecialVar_ItemId, 1);
    gTasks[taskId].func = Task_ChooseHowManyToSell;
}

static void Task_ChooseHowManyToSell(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, tQuantity) == TRUE)
    {
        PrintQuantity(gBagMenu->windowIds[ITEMWIN_SELL_QUANTITY], tItemCount);
        PrintSellPrice(gSpecialVar_ItemId, tItemCount);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        DisplaySellItemPriceAndConfirm(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_PrintCursor(tListTaskId, COLORID_NONE);
        DestroyQuantityFrameSprites();
        BagMenu_RemoveWindow(ITEMWIN_SELL_QUANTITY);
        PrintSellPrice(gSpecialVar_ItemId, 1);
        RemoveItemMessageWindow(ITEMWIN_MESSAGE);
        ReturnToItemList(taskId);
    }
}

static void ConfirmSell(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    CopyItemName(gSpecialVar_ItemId, gStringVar2);
    ConvertIntToDecimalStringN(gStringVar1, GetItemSellPrice(gSpecialVar_ItemId) * tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_MONEY_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_TurnedOverVar1ForVar2);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, SellItem);
}

static void SellItem(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];

    PlaySE(SE_SHOP);
    RemoveBagItem(gSpecialVar_ItemId, tItemCount);
    AddMoney(&gSaveBlock1Ptr->money, GetItemSellPrice(gSpecialVar_ItemId) * tItemCount);
    DestroyListMenuTask(tListTaskId, scrollPos, cursorPos);
    UpdatePocketItemList(gBagPosition.pocket);
    UpdatePocketListPosition(gBagPosition.pocket);
    LoadBagItemListBuffers(gBagPosition.pocket);
    tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    BagMenu_PrintCursor(tListTaskId, COLORID_NONE);
    PrintMoney(gBagMenu->windowIds[ITEMWIN_MONEY]);
    gTasks[taskId].func = WaitAfterItemSell;
}

static void WaitAfterItemSell(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        CloseItemMessage(taskId);
    }
}

static void Task_ItemContext_Deposit(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    tItemCount = 1;
    if (tQuantity == 1)
    {
        TryDepositItem(taskId);
    }
    else
    {
        u8 *end = CopyItemNameHandlePlural(gSpecialVar_ItemId, gStringVar1, 2);
        WrapFontIdToFit(gStringVar1, end, FONT_NORMAL, WindowWidthPx(WIN_DESCRIPTION) - 10 - 6);
        StringExpandPlaceholders(gStringVar4, sText_DepositHowManyVar1);
        FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
        BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, gStringVar4, 3, 1, 0, 0, 0, COLORID_NORMAL);
        AddItemQuantityWindow(ITEMWIN_QUANTITY);
        gTasks[taskId].func = Task_ChooseHowManyToDeposit;
    }
}

static void Task_ChooseHowManyToDeposit(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, tQuantity) == TRUE)
    {
        PrintItemQuantity(gBagMenu->windowIds[ITEMWIN_QUANTITY], tItemCount);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY);
        TryDepositItem(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        PrintItemDescription(tListPosition);
        BagMenu_PrintCursor(tListTaskId, COLORID_NONE);
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY);
        ReturnToItemList(taskId);
    }
}

static void TryDepositItem(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    if (GetItemImportance(gSpecialVar_ItemId))
    {
        // Can't deposit important items
        BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, sText_CantStoreImportantItems, 3, 1, 0, 0, 0, COLORID_NORMAL);
        gTasks[taskId].func = WaitDepositErrorMessage;
    }
    else if (AddPCItem(gSpecialVar_ItemId, tItemCount) == TRUE)
    {
        // Successfully deposited
        u8 *end = CopyItemNameHandlePlural(gSpecialVar_ItemId, gStringVar1, tItemCount);
        WrapFontIdToFit(gStringVar1, end, FONT_NORMAL, WindowWidthPx(WIN_DESCRIPTION) - 10 - 6);
        ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS);
        StringExpandPlaceholders(gStringVar4, sText_DepositedVar2Var1s);
        BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, gStringVar4, 3, 1, 0, 0, 0, COLORID_NORMAL);
        gTasks[taskId].func = Task_RemoveItemFromBag;
    }
    else
    {
        // No room to deposit
        BagMenu_Print(WIN_DESCRIPTION, FONT_NORMAL, sText_NoRoomForItems, 3, 1, 0, 0, 0, COLORID_NORMAL);
        gTasks[taskId].func = WaitDepositErrorMessage;
    }
}

static void WaitDepositErrorMessage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        PrintItemDescription(tListPosition);
        BagMenu_PrintCursor(tListTaskId, COLORID_NONE);
        ReturnToItemList(taskId);
    }
}

static bool8 IsWallysBag(void)
{
    if (gBagPosition.location == ITEMMENULOCATION_WALLY)
        return TRUE;
    return FALSE;
}

static void PrepareBagForWallyTutorial(void)
{
    u32 i;

    sTempWallyBag = AllocZeroed(sizeof(*sTempWallyBag));
    memcpy(sTempWallyBag->bagPocket_Items, gSaveBlock1Ptr->bag.items, sizeof(gSaveBlock1Ptr->bag.items));
    memcpy(sTempWallyBag->bagPocket_PokeBalls, gSaveBlock1Ptr->bag.pokeBalls, sizeof(gSaveBlock1Ptr->bag.pokeBalls));
    sTempWallyBag->pocket = gBagPosition.pocket;
    for (i = 0; i < POCKETS_COUNT; i++)
    {
        sTempWallyBag->cursorPosition[i] = gBagPosition.cursorPosition[i];
        sTempWallyBag->scrollPosition[i] = gBagPosition.scrollPosition[i];
    }
    memset(gSaveBlock1Ptr->bag.items, 0, sizeof(gSaveBlock1Ptr->bag.items));
    memset(gSaveBlock1Ptr->bag.pokeBalls, 0, sizeof(gSaveBlock1Ptr->bag.pokeBalls));
    ResetBagScrollPositions();
}

static void RestoreBagAfterWallyTutorial(void)
{
    u32 i;

    memcpy(gSaveBlock1Ptr->bag.items, sTempWallyBag->bagPocket_Items, sizeof(sTempWallyBag->bagPocket_Items));
    memcpy(gSaveBlock1Ptr->bag.pokeBalls, sTempWallyBag->bagPocket_PokeBalls, sizeof(sTempWallyBag->bagPocket_PokeBalls));
    gBagPosition.pocket = sTempWallyBag->pocket;
    for (i = 0; i < POCKETS_COUNT; i++)
    {
        gBagPosition.cursorPosition[i] = sTempWallyBag->cursorPosition[i];
        gBagPosition.scrollPosition[i] = sTempWallyBag->scrollPosition[i];
    }
    Free(sTempWallyBag);
}

void DoWallyTutorialBagMenu(void)
{
    PrepareBagForWallyTutorial();
    AddBagItem(ITEM_POTION, 1);
    AddBagItem(ITEM_POKE_BALL, 1);
    GoToBagMenu(ITEMMENULOCATION_WALLY, POCKET_ITEMS, CB2_SetUpReshowBattleScreenAfterMenu2);
}

void InitOldManBag(void)
{
    PrepareBagForWallyTutorial();
    AddBagItem(ITEM_POTION, 1);
    AddBagItem(ITEM_POKE_BALL, 1);
    GoToBagMenu(ITEMMENULOCATION_WALLY, POCKET_ITEMS, CB2_SetUpReshowBattleScreenAfterMenu2);
}

#define tTimer data[8]
#define WALLY_BAG_DELAY 102 // The number of frames between each action Wally takes in the bag

static void Task_WallyTutorialBagMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        switch (tTimer)
        {
        case WALLY_BAG_DELAY * 1:
            PlaySE(SE_SELECT);
            SwitchBagPocket(taskId, MENU_CURSOR_DELTA_RIGHT, FALSE);
            tTimer++;
            break;
        case WALLY_BAG_DELAY * 2:
            PlaySE(SE_SELECT);
            BagMenu_PrintCursor(tListTaskId, COLORID_NONE);
            gSpecialVar_ItemId = ITEM_POKE_BALL;
            OpenContextMenu(taskId);
            tTimer++;
            break;
        case WALLY_BAG_DELAY * 3:
            PlaySE(SE_SELECT);
            RemoveContextWindow();
            DestroyListMenuTask(tListTaskId, 0, 0);
            RestoreBagAfterWallyTutorial();
            Task_FadeAndCloseBagMenu(taskId);
            break;
        default:
            tTimer++;
            break;
        }
    }
}

#undef tTimer

// This action is used to show the Apprentice an item when
// they ask what item they should make their Pokémon hold
static void ItemMenu_Show(u8 taskId)
{
    gSpecialVar_0x8005 = gSpecialVar_ItemId;
    gSpecialVar_Result = TRUE;
    RemoveContextWindow();
    Task_FadeAndCloseBagMenu(taskId);
}

static void CB2_ApprenticeExitBagMenu(void)
{
    gFieldCallback = Apprentice_ScriptContext_Enable;
    SetMainCallback2(CB2_ReturnToField);
}

static void ItemMenu_GiveFavorLady(u8 taskId)
{
    RemoveBagItem(gSpecialVar_ItemId, 1);
    gSpecialVar_Result = TRUE;
    RemoveContextWindow();
    Task_FadeAndCloseBagMenu(taskId);
}

static void CB2_FavorLadyExitBagMenu(void)
{
    gFieldCallback = FieldCallback_FavorLadyEnableScriptContexts;
    SetMainCallback2(CB2_ReturnToField);
}

// This action is used to confirm which item to use as
// a prize for a custom quiz with the Lilycove Quiz Lady
static void ItemMenu_ConfirmQuizLady(u8 taskId)
{
    gSpecialVar_Result = TRUE;
    RemoveContextWindow();
    Task_FadeAndCloseBagMenu(taskId);
}

static void CB2_QuizLadyExitBagMenu(void)
{
    gFieldCallback = FieldCallback_QuizLadyEnableScriptContexts;
    SetMainCallback2(CB2_ReturnToField);
}

static void PrintPocketName(const u8 *name)
{
    u8 offset = GetStringCenterAlignXOffset(FONT_SHORT, name, 88);
    FillWindowPixelBuffer(WIN_POCKET_NAME, PIXEL_FILL(0));
    BagMenu_Print(WIN_POCKET_NAME, FONT_SHORT, name, offset, 1, 0, 0, TEXT_SKIP_DRAW, COLORID_POCKET_NAME);
    PutWindowTilemap(WIN_POCKET_NAME);
    CopyWindowToVram(WIN_POCKET_NAME, COPYWIN_GFX);
}

static void LoadBagMenuTextWindows(void)
{
    u8 i;

    InitWindows(sDefaultBagWindows);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 1, BG_PLTT_ID(14));
    LoadMessageBoxGfx(0, 10, BG_PLTT_ID(13));
    ListMenuLoadStdPalAt(BG_PLTT_ID(12), 1);
    LoadPalette(&gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    for (i = 0; i <= WIN_POCKET_NAME; i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
        PutWindowTilemap(i);
    }
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(0);
}

static void BagMenu_Print(u8 windowId, u8 fontId, const u8 *str, u8 left, u8 top, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorIndex)
{
    AddTextPrinterParameterized4(windowId, fontId, left, top, letterSpacing, lineSpacing, sFontColorTable[colorIndex], speed, str);
}

static u8 UNUSED BagMenu_GetWindowId(u8 windowType)
{
    return gBagMenu->windowIds[windowType];
}

static u8 BagMenu_AddWindow(u8 windowType)
{
    u8 *windowId = &gBagMenu->windowIds[windowType];
    if (*windowId == WINDOW_NONE)
    {
        *windowId = AddWindow(&sContextMenuWindowTemplates[windowType]);
        DrawStdFrameWithCustomTileAndPalette(*windowId, FALSE, 1, 14);
        ScheduleBgCopyTilemapToVram(0);
    }
    return *windowId;
}

static void BagMenu_RemoveWindow(u8 windowType)
{
    u8 *windowId = &gBagMenu->windowIds[windowType];
    if (*windowId != WINDOW_NONE)
    {
        ClearStdWindowAndFrameToTransparent(*windowId, FALSE);
        ClearWindowTilemap(*windowId);
        RemoveWindow(*windowId);
        ScheduleBgCopyTilemapToVram(0);
        *windowId = WINDOW_NONE;
    }
}

static u8 AddItemMessageWindow(u8 windowType)
{
    u8 *windowId = &gBagMenu->windowIds[windowType];
    if (*windowId == WINDOW_NONE)
        *windowId = AddWindow(&sContextMenuWindowTemplates[windowType]);
    return *windowId;
}

static void RemoveItemMessageWindow(u8 windowType)
{
    u8 *windowId = &gBagMenu->windowIds[windowType];
    if (*windowId != WINDOW_NONE)
    {
        ClearDialogWindowAndFrameToTransparent(*windowId, FALSE);
        // This ClearWindowTilemap call is redundant, since ClearDialogWindowAndFrameToTransparent already calls it.
        ClearWindowTilemap(*windowId);
        RemoveWindow(*windowId);
        ScheduleBgCopyTilemapToVram(0);
        *windowId = WINDOW_NONE;
    }
}

void BagMenu_YesNo(u8 taskId, u8 windowType, const struct YesNoFuncTable *funcTable)
{
    CreateYesNoMenuWithCallbacks(taskId, &sContextMenuWindowTemplates[windowType], 1, 0, 2, 1, 14, funcTable);
}

static void CreateMoneyFrameSprites(void)
{
    u8 i;
    for (i = 0; i < FRAME_MONEY_SPRITES_COUNT; i++)
    {
        sFrameMoneyIds[i] = CreateSprite(&sSpriteTemplate_FrameMoney, i * 32, 8, 3);
        StartSpriteAnim(&gSprites[sFrameMoneyIds[i]], sFrameMoneyAnims[i]);
    }
}

static void CreatePriceFrameSprites(void)
{
    u8 i;
    for (i = 0; i < FRAME_PRICE_SPRITES_COUNT; i++)
    {
        sFramePriceIds[i] = CreateSprite(&sSpriteTemplate_FramePriceQuantity, i * 32, 48, 3);
        StartSpriteAnim(&gSprites[sFramePriceIds[i]], sFramePriceAnims[i]);
    }
}

static void CreateQuantityFrameSprites(void)
{
    u8 i;
    for (i = 0; i < FRAME_QUANTITY_SPRITES_COUNT; i++)
    {
        sFrameQuantityIds[i] = CreateSprite(&sSpriteTemplate_FramePriceQuantity, 192 + i * 32, 96, 3);
        StartSpriteAnim(&gSprites[sFrameQuantityIds[i]], sFrameQuantityAnims[i]);
    }
}

static void DestroyQuantityFrameSprites(void)
{
    u8 i;
    for (i = 0; i < FRAME_QUANTITY_SPRITES_COUNT; i++)
    {
        if (sFrameQuantityIds[i] != SPRITE_NONE)
        {
            DestroySprite(&gSprites[sFrameQuantityIds[i]]);
            sFrameQuantityIds[i] = SPRITE_NONE;
        }
    }
}

static u8 BagMenu_AddWindowNoFrame(u8 windowType)
{
    u8 *windowId = &gBagMenu->windowIds[windowType];
    if (*windowId == WINDOW_NONE)
        *windowId = AddWindow(&sContextMenuWindowTemplates[windowType]);
    PutWindowTilemap(*windowId);
    ScheduleBgCopyTilemapToVram(0);
    return *windowId;
}

static void PrintSellPrice(u16 itemId, int qty)
{
    u8 windowId = gBagMenu->windowIds[ITEMWIN_SELL_PRICE];
    u8 windowWidthPx = sContextMenuWindowTemplates[ITEMWIN_SELL_PRICE].width * 8;

    FillWindowPixelRect(windowId, PIXEL_FILL(0), 0, 16, windowWidthPx, 16);

    if (itemId == ITEM_NONE || GetItemPrice(itemId) == 0 || GetItemImportance(itemId))
    {
        StringCopy(gStringVar1, gText_ThreeDashes);
    }
    else
    {
        u32 total = GetItemSellPrice(itemId) * qty;
        ConvertIntToDecimalStringN(gStringVar1, total, STR_CONV_MODE_LEFT_ALIGN, MAX_MONEY_DIGITS);
    }
    StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
    BagMenu_Print(windowId, FONT_NORMAL, gStringVar4,
        GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, windowWidthPx), 16, 0, 0, TEXT_SKIP_DRAW, COLORID_POCKET_NAME);
    CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void SetupSellWindows(void)
{
    u8 windowId;
    CreatePriceFrameSprites();
    CreateMoneyFrameSprites();

    windowId = BagMenu_AddWindowNoFrame(ITEMWIN_SELL_PRICE);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    BagMenu_Print(windowId, FONT_NORMAL, sText_Price, 0, 0, 0, 0, TEXT_SKIP_DRAW, COLORID_POCKET_NAME);
    CopyWindowToVram(windowId, COPYWIN_GFX);

    windowId = BagMenu_AddWindowNoFrame(ITEMWIN_MONEY);
    PrintMoney(windowId);
}

static void UpdateSellPrice(u16 itemId)
{
    PrintSellPrice(itemId, 1);
}

static void PrintQuantity(u8 windowId, s16 quantity)
{
    u8 windowWidthPx = sContextMenuWindowTemplates[ITEMWIN_SELL_QUANTITY].width * 8;

    ConvertIntToDecimalStringN(gStringVar1, quantity, STR_CONV_MODE_LEADING_ZEROS, MAX_ITEM_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    BagMenu_Print(windowId, FONT_NORMAL, gStringVar4,
        GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, windowWidthPx), 0, 0, 0, TEXT_SKIP_DRAW, COLORID_POCKET_NAME);
    CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void PrintMoney(u8 windowId)
{
    ConvertIntToDecimalStringN(gStringVar1, GetMoney(&gSaveBlock1Ptr->money), STR_CONV_MODE_LEFT_ALIGN, MAX_MONEY_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    BagMenu_Print(windowId, FONT_NORMAL, gStringVar4, 0, 0, 0, 0, TEXT_SKIP_DRAW, COLORID_HOVER_NAME);
    CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void ShowInfoPrompt(const u8 *tilemap)
{
    u8 i;
    u16 *buf = (u16 *)gBagMenu->mainTilemapBuffer;
    for (i = 0; i < 12; i++)
        buf[(16 + i / 3) * 32 + (27 + i % 3)] = tilemap[i];
    ScheduleBgCopyTilemapToVram(2);
}

static void SpriteCB_MoveTypeIcon(struct Sprite *sprite)
{
    if (sprite->data[0] != 0xFF)
    {
        u32 offset = sprite->data[0] * 0x100;
        RequestDma3Copy(&sMoveTypeIconsCache[offset], sMoveTypeIconTilesPtr, 0x100, 0x10);
        sprite->data[0] = 0xFF;
    }
}

static void UpdateMoveBattleInfo(s32 itemIndex)
{
    enum Move move;
    const u8 *text;
    u32 power;
    u32 accuracy;
    int ppInfoWidth = WindowWidthPx(WIN_PP_INFO);
    int valInfoWidth = WindowWidthPx(WIN_POW_ACC_INFO);

    FillWindowPixelBuffer(WIN_PP_INFO, PIXEL_FILL(0));
    FillWindowPixelBuffer(WIN_POW_ACC_INFO, PIXEL_FILL(0));

    if (itemIndex == LIST_CANCEL)
    {
        BagMenu_Print(WIN_PP_INFO, FONT_SHORT_NARROW, gText_ThreeDashes,
            GetStringRightAlignXOffset(FONT_SHORT_NARROW, gText_ThreeDashes, ppInfoWidth), 0, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
        BagMenu_Print(WIN_POW_ACC_INFO, FONT_SHORT_NARROW, gText_ThreeDashes,
            GetStringRightAlignXOffset(FONT_SHORT_NARROW, gText_ThreeDashes, valInfoWidth), 0, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
        BagMenu_Print(WIN_POW_ACC_INFO, FONT_SHORT_NARROW, gText_ThreeDashes,
            GetStringRightAlignXOffset(FONT_SHORT_NARROW, gText_ThreeDashes, valInfoWidth), 16, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
        CopyWindowToVram(WIN_PP_INFO, COPYWIN_GFX);
        CopyWindowToVram(WIN_POW_ACC_INFO, COPYWIN_GFX);
        gSprites[sMoveTypeIconSpriteId].invisible = TRUE;
        gSprites[sCategoryIconSpriteId].invisible = TRUE;
        return;
    }

    move = ItemIdToBattleMoveId(GetBagItemId(gBagPosition.pocket, itemIndex));

    // PP
    ConvertIntToDecimalStringN(gStringVar1, GetMovePP(move), STR_CONV_MODE_LEFT_ALIGN, 3);
    BagMenu_Print(WIN_PP_INFO, FONT_SHORT_NARROW, gStringVar1,
        GetStringRightAlignXOffset(FONT_SHORT_NARROW, gStringVar1, ppInfoWidth), 0, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
    CopyWindowToVram(WIN_PP_INFO, COPYWIN_GFX);

    // Power
    power = GetMovePower(move);
    if (power <= 1)
        text = gText_ThreeDashes;
    else
    {
        ConvertIntToDecimalStringN(gStringVar1, power, STR_CONV_MODE_LEFT_ALIGN, 3);
        text = gStringVar1;
    }
    BagMenu_Print(WIN_POW_ACC_INFO, FONT_SHORT_NARROW, text,
        GetStringRightAlignXOffset(FONT_SHORT_NARROW, text, valInfoWidth), 1, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);

    // Accuracy
    accuracy = GetMoveAccuracy(move);
    if (accuracy == 0)
        text = gText_ThreeDashes;
    else
    {
        ConvertIntToDecimalStringN(gStringVar1, accuracy, STR_CONV_MODE_LEFT_ALIGN, 3);
        text = gStringVar1;
    }
    BagMenu_Print(WIN_POW_ACC_INFO, FONT_SHORT_NARROW, text,
        GetStringRightAlignXOffset(FONT_SHORT_NARROW, text, valInfoWidth), 16, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
    CopyWindowToVram(WIN_POW_ACC_INFO, COPYWIN_GFX);

    gSprites[sMoveTypeIconSpriteId].x = 112;
    gSprites[sMoveTypeIconSpriteId].oam.paletteNum = gTypesInfo[GetMoveType(move)].palette;
    gSprites[sMoveTypeIconSpriteId].data[0] = GetMoveType(move);
    gSprites[sMoveTypeIconSpriteId].invisible = FALSE;

    StartSpriteAnim(&gSprites[sCategoryIconSpriteId], GetBattleMoveCategory(move));
    gSprites[sCategoryIconSpriteId].invisible = FALSE;
}

#if SWSH_ITEM_MENU_TMHM_CONTEST_INFO
static void PrintContestDescription(s32 itemIndex)
{
    const u8 *str;
    u8 desc[200];
    u8 fontId;
    s32 maxWidth = sDefaultBagWindows[WIN_DESCRIPTION].width * 8 - 3;

    if (itemIndex != LIST_CANCEL)
    {
        enum Move move = ItemIdToBattleMoveId(GetBagItemId(gBagPosition.pocket, itemIndex));
        str = gContestEffects[GetMoveContestEffect(move)].description;
    }
    else
    {
        StringCopy(gStringVar1, gBagMenu_ReturnToStrings[gBagPosition.location]);
        StringExpandPlaceholders(gStringVar4, gText_ReturnToVar1);
        str = gStringVar4;
    }
    fontId = FormatDescriptionByWidth(desc, maxWidth, FONT_SHORT_NARROW, str, GetFontAttribute(FONT_SHORT_NARROW, FONTATTR_LETTER_SPACING));
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    AddTextPrinterParameterized4(WIN_DESCRIPTION, fontId, 3, 1, 0, 1, sFontColorTable[COLORID_NORMAL], 0, desc);
}
#endif

static void SwitchMoveInfoMode(s32 itemIndex)
{
    if (sMoveInfoMode == 0)
    {
        sMoveInfoMode = 1;

        LoadPalette(sMoveTypeIcons_Pal, OBJ_PLTT_ID(13), 3 * PLTT_SIZE_4BPP);
        {
            struct SpriteSheet sheet = { .data = sMoveTypeIconsCache, .size = 0x100, .tag = TAG_MOVE_TYPE_ICON };
            LoadSpriteSheet(&sheet);
        }
        LoadCompressedSpriteSheet(&sSpriteSheet_CategoryIcon);

        sMoveTypeIconSpriteId = CreateSprite(&sSpriteTemplate_MoveTypeIcon, 112, 136, 0);
        sMoveTypeIconTilesPtr = (u16 *)((u8 *)OBJ_VRAM0 + 32 * GetSpriteTileStartByTag(TAG_MOVE_TYPE_ICON));
        sCategoryIconSpriteId = CreateSprite(&sSpriteTemplate_CategoryIcon, 80, 136, 0);

        FillWindowPixelBuffer(WIN_PP_LABEL, PIXEL_FILL(0));
        BagMenu_Print(WIN_PP_LABEL, FONT_SHORT_NARROW, sText_MoveInfoPP, 0, 0, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
        CopyWindowToVram(WIN_PP_LABEL, COPYWIN_GFX);

        {
            int winWidth = WindowWidthPx(WIN_POW_ACC_LABEL);
            FillWindowPixelBuffer(WIN_POW_ACC_LABEL, PIXEL_FILL(0));
            BagMenu_Print(WIN_POW_ACC_LABEL, FONT_SHORT_NARROW, sText_MoveInfoPower,
                GetStringRightAlignXOffset(FONT_SHORT_NARROW, sText_MoveInfoPower, winWidth), 1, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
            BagMenu_Print(WIN_POW_ACC_LABEL, FONT_SHORT_NARROW, sText_MoveInfoAccuracy,
                GetStringRightAlignXOffset(FONT_SHORT_NARROW, sText_MoveInfoAccuracy, winWidth), 16, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
            CopyWindowToVram(WIN_POW_ACC_LABEL, COPYWIN_GFX);
        }

        ClearWindowTilemap(WIN_DESCRIPTION);
        UpdateMoveBattleInfo(itemIndex);

        PutWindowTilemap(WIN_PP_LABEL);
        PutWindowTilemap(WIN_POW_ACC_LABEL);
        PutWindowTilemap(WIN_PP_INFO);
        PutWindowTilemap(WIN_POW_ACC_INFO);
#if SWSH_ITEM_MENU_TMHM_CONTEST_INFO
        ShowInfoPrompt(sContestInfoPrompt_Tilemap);
#else
        ShowInfoPrompt(sBattleInfoPrompt_Tilemap);
#endif
        ScheduleBgCopyTilemapToVram(1);
    }
#if SWSH_ITEM_MENU_TMHM_CONTEST_INFO
    else if (sMoveInfoMode == 1)
    {
        sMoveInfoMode = 2;

        gSprites[sMoveTypeIconSpriteId].invisible = TRUE;
        gSprites[sCategoryIconSpriteId].invisible = TRUE;

        FillWindowPixelBuffer(WIN_PP_LABEL, PIXEL_FILL(0));
        ClearWindowTilemap(WIN_PP_LABEL);
        FillWindowPixelBuffer(WIN_PP_INFO, PIXEL_FILL(0));
        ClearWindowTilemap(WIN_PP_INFO);
        FillWindowPixelBuffer(WIN_POW_ACC_LABEL, PIXEL_FILL(0));
        ClearWindowTilemap(WIN_POW_ACC_LABEL);
        FillWindowPixelBuffer(WIN_POW_ACC_INFO, PIXEL_FILL(0));
        ClearWindowTilemap(WIN_POW_ACC_INFO);

        PrintContestDescription(itemIndex);
        PutWindowTilemap(WIN_DESCRIPTION);
        ShowInfoPrompt(sContestStatPrompt_Tilemap);
        ScheduleBgCopyTilemapToVram(1);
    }
    else if (sMoveInfoMode == 2)
    {
        int winWidth;
        sMoveInfoMode = 3;

        ClearWindowTilemap(WIN_DESCRIPTION);

        FillWindowPixelBuffer(WIN_PP_LABEL, PIXEL_FILL(0));
        BagMenu_Print(WIN_PP_LABEL, FONT_SHORT_NARROW, sText_MoveInfoPP, 0, 0, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
        CopyWindowToVram(WIN_PP_LABEL, COPYWIN_GFX);

        winWidth = WindowWidthPx(WIN_APP_JAM_LABEL);
        FillWindowPixelBuffer(WIN_APP_JAM_LABEL, PIXEL_FILL(0));
        BagMenu_Print(WIN_APP_JAM_LABEL, FONT_SHORT_NARROW, sText_MoveInfoAppeal,
            GetStringRightAlignXOffset(FONT_SHORT_NARROW, sText_MoveInfoAppeal, winWidth), 1, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
        BagMenu_Print(WIN_APP_JAM_LABEL, FONT_SHORT_NARROW, sText_MoveInfoJam,
            GetStringRightAlignXOffset(FONT_SHORT_NARROW, sText_MoveInfoJam, winWidth), 16, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
        CopyWindowToVram(WIN_APP_JAM_LABEL, COPYWIN_GFX);

        UpdateMoveContestInfo(itemIndex);
        PutWindowTilemap(WIN_PP_LABEL);
        PutWindowTilemap(WIN_PP_INFO);
        PutWindowTilemap(WIN_APP_JAM_LABEL);
        ShowInfoPrompt(sBattleInfoPrompt_Tilemap);
        ScheduleBgCopyTilemapToVram(1);
    }
#endif
    else
    {
        sMoveInfoMode = 0;

        if (sMoveTypeIconSpriteId != SPRITE_NONE)
        {
            DestroySprite(&gSprites[sMoveTypeIconSpriteId]);
            FreeSpriteTilesByTag(TAG_MOVE_TYPE_ICON);
            sMoveTypeIconSpriteId = SPRITE_NONE;
        }
        if (sCategoryIconSpriteId != SPRITE_NONE)
        {
            DestroySprite(&gSprites[sCategoryIconSpriteId]);
            FreeSpriteTilesByTag(TAG_CATEGORY_ICON);
            sCategoryIconSpriteId = SPRITE_NONE;
        }

        ClearWindowTilemap(WIN_PP_LABEL);
        ClearWindowTilemap(WIN_POW_ACC_LABEL);
        ClearWindowTilemap(WIN_PP_INFO);
        ClearWindowTilemap(WIN_POW_ACC_INFO);
#if SWSH_ITEM_MENU_TMHM_CONTEST_INFO
        ClearWindowTilemap(WIN_APP_JAM_LABEL);
        FillBgTilemapBufferRect_Palette0(2, 4, 21, 16, 4, 4);
#endif

        PrintItemDescription(itemIndex);
        PutWindowTilemap(WIN_DESCRIPTION);
        ShowInfoPrompt(sBattleStatPrompt_Tilemap);
        ScheduleBgCopyTilemapToVram(1);
    }
}

#if SWSH_ITEM_MENU_TMHM_CONTEST_INFO
static void UpdateMoveContestInfo(s32 itemIndex)
{
    enum Move move;
    u8 appeal, jam, i;
    u16 *buf = (u16 *)gBagMenu->mainTilemapBuffer;
    int ppInfoWidth = WindowWidthPx(WIN_PP_INFO);

    FillWindowPixelBuffer(WIN_PP_INFO, PIXEL_FILL(0));

    if (itemIndex == LIST_CANCEL)
    {
        FillBgTilemapBufferRect_Palette0(2, 13, 21, 16, 4, 4);
        gSprites[sMoveTypeIconSpriteId].invisible = TRUE;
        ScheduleBgCopyTilemapToVram(2);
        CopyWindowToVram(WIN_PP_INFO, COPYWIN_GFX);
        return;
    }

    move = ItemIdToBattleMoveId(GetBagItemId(gBagPosition.pocket, itemIndex));

    // PP
    ConvertIntToDecimalStringN(gStringVar1, GetMovePP(move), STR_CONV_MODE_LEFT_ALIGN, 3);
    BagMenu_Print(WIN_PP_INFO, FONT_SHORT_NARROW, gStringVar1,
        GetStringRightAlignXOffset(FONT_SHORT_NARROW, gStringVar1, ppInfoWidth), 0, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
    CopyWindowToVram(WIN_PP_INFO, COPYWIN_GFX);

    // Contest type icon
    {
        u32 category = GetMoveContestCategory(move);
        gSprites[sMoveTypeIconSpriteId].x = 96;
        gSprites[sMoveTypeIconSpriteId].oam.paletteNum = gContestCategoryInfo[category].palette;
        gSprites[sMoveTypeIconSpriteId].data[0] = NUMBER_OF_MON_TYPES + category;
        gSprites[sMoveTypeIconSpriteId].invisible = FALSE;
    }

    // Appeal/Jam tile grid
    {
        u32 effect = GetMoveContestEffect(move);
        appeal = gContestEffects[effect].appeal;
        if (appeal != 0xFF)
            appeal /= 10;
        jam = gContestEffects[effect].jam;
        if (jam != 0xFF)
            jam /= 10;
    }

    for (i = 0; i < 8; i++)
        buf[(16 + i / 4) * 32 + (21 + i % 4)] = (appeal == 0xFF || i < appeal) ? 14 : 13;
    for (i = 0; i < 8; i++)
        buf[(18 + i / 4) * 32 + (21 + i % 4)] = (jam == 0xFF || i < jam) ? 15 : 13;
    ScheduleBgCopyTilemapToVram(2);
}
#endif // SWSH_ITEM_MENU_TMHM_CONTEST_INFO

static const u8 sText_SortItemsHow[] = _("Sort items how?");
static const u8 sText_ItemsSorted[] = _("Items sorted by {STR_VAR_1}!");
static const u8 *const sSortTypeStrings[] =
{
    [SORT_ALPHABETICALLY] = COMPOUND_STRING("name"),
    [SORT_BY_TYPE] = COMPOUND_STRING("type"),
    [SORT_BY_AMOUNT] = COMPOUND_STRING("amount"),
    [SORT_BY_INDEX] = COMPOUND_STRING("index")
};

static const u8 sBagMenuSortItems[] =
{
    ACTION_BY_NAME,
    ACTION_BY_TYPE,
    ACTION_BY_AMOUNT,
    ACTION_CANCEL,
};

static const u8 sBagMenuSortKeyItems[] =
{
    ACTION_BY_NAME,
    ACTION_CANCEL,
};

static const u8 sBagMenuSortPokeBalls[] =
{
    ACTION_BY_NAME,
    ACTION_BY_AMOUNT,
    ACTION_DUMMY,
    ACTION_CANCEL,
};

static const u8 sBagMenuSortBerriesTMsHMs[] =
{
    ACTION_BY_NAME,
    ACTION_BY_AMOUNT,
    ACTION_BY_INDEX,
    ACTION_CANCEL,
};

static void AddBagSortSubMenu(void)
{
    switch (gBagPosition.pocket)
    {
    case POCKET_KEY_ITEMS:
        gBagMenu->contextMenuItemsPtr = sBagMenuSortKeyItems;
        memcpy(&gBagMenu->contextMenuItemsBuffer, &sBagMenuSortKeyItems, NELEMS(sBagMenuSortKeyItems));
        gBagMenu->contextMenuNumItems = NELEMS(sBagMenuSortKeyItems);
        break;
    case POCKET_POKE_BALLS:
        gBagMenu->contextMenuItemsPtr = sBagMenuSortPokeBalls;
        memcpy(&gBagMenu->contextMenuItemsBuffer, &sBagMenuSortPokeBalls, NELEMS(sBagMenuSortPokeBalls));
        gBagMenu->contextMenuNumItems = NELEMS(sBagMenuSortPokeBalls);
        break;
    case POCKET_BERRIES:
    case POCKET_TM_HM:
        gBagMenu->contextMenuItemsPtr = sBagMenuSortBerriesTMsHMs;
        memcpy(&gBagMenu->contextMenuItemsBuffer, &sBagMenuSortBerriesTMsHMs, NELEMS(sBagMenuSortBerriesTMsHMs));
        gBagMenu->contextMenuNumItems = NELEMS(sBagMenuSortBerriesTMsHMs);
        break;
    default:
        gBagMenu->contextMenuItemsPtr = sBagMenuSortItems;
        memcpy(&gBagMenu->contextMenuItemsBuffer, &sBagMenuSortItems, NELEMS(sBagMenuSortItems));
        gBagMenu->contextMenuNumItems = NELEMS(sBagMenuSortItems);
        break;
    }

    StringExpandPlaceholders(gStringVar4, sText_SortItemsHow);
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    BagMenu_Print(1, 1, gStringVar4, 3, 1, 0, 0, 0, 0);

    if (gBagMenu->contextMenuNumItems == 2)
        PrintContextMenuItems(BagMenu_AddWindow(ITEMWIN_1x2));
    else if (gBagMenu->contextMenuNumItems == 4)
        PrintContextMenuItemGrid(BagMenu_AddWindow(ITEMWIN_2x2), 2, 2);
    else
        PrintContextMenuItemGrid(BagMenu_AddWindow(ITEMWIN_2x3), 2, 3);
}

static void Task_LoadBagSortOptions(u8 taskId)
{
    AddBagSortSubMenu();
    if (gBagMenu->contextMenuNumItems <= 2)
        gTasks[taskId].func = Task_ItemContext_SingleRow;
    else
        gTasks[taskId].func = Task_ItemContext_MultipleRows;
}

#define tSortType data[2]
static void ItemMenu_SortByName(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_ALPHABETICALLY;
    StringCopy(gStringVar1, sSortTypeStrings[SORT_ALPHABETICALLY]);
    gTasks[taskId].func = SortBagItems;
}

static void ItemMenu_SortByType(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_TYPE;
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_TYPE]);
    gTasks[taskId].func = SortBagItems;
}

static void ItemMenu_SortByAmount(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_AMOUNT; //greatest->least
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_AMOUNT]);
    gTasks[taskId].func = SortBagItems;
}

static void ItemMenu_SortByIndex(u8 taskId)
{
    gTasks[taskId].tSortType = SORT_BY_INDEX;
    StringCopy(gStringVar1, sSortTypeStrings[SORT_BY_INDEX]);
    gTasks[taskId].func = SortBagItems;
}

static void SortBagItems(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];

    RemoveContextWindow();

    SortItemsInBag(&gBagPockets[gBagPosition.pocket], tSortType);
    DestroyListMenuTask(data[0], scrollPos, cursorPos);
    UpdatePocketListPosition(gBagPosition.pocket);
    LoadBagItemListBuffers(gBagPosition.pocket);
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    ScheduleBgCopyTilemapToVram(1);

    StringCopy(gStringVar1, sSortTypeStrings[tSortType]);
    StringExpandPlaceholders(gStringVar4, sText_ItemsSorted);
    DisplayItemMessage(taskId, 1, gStringVar4, Task_SortFinish);
}

#undef tSortType

static void Task_SortFinish(u8 taskId)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        RemoveItemMessageWindow(4);
        ReturnToItemList(taskId);
    }
}

void SortItemsInBag(struct BagPocket *pocket, enum BagSortOptions type)
{
    switch (type)
    {
    case SORT_ALPHABETICALLY:
        MergeSort(pocket, CompareItemsAlphabetically);
        break;
    case SORT_BY_AMOUNT:
        MergeSort(pocket, CompareItemsByMost);
        break;
    case SORT_BY_INDEX:
        MergeSort(pocket, CompareItemsByIndex);
        break;
    default:
        MergeSort(pocket, CompareItemsByType);
        break;
    }
}

static inline __attribute__((always_inline)) void Merge(struct BagPocket *pocket, u32 iLeft, u32 iRight, u32 iEnd, struct ItemSlot *dummySlots, s32 (*comparator)(enum Pocket, struct ItemSlot, struct ItemSlot))
{
    struct ItemSlot item_i, item_j;
    u32 i = iLeft, j = iRight;
    for (u32 k = iLeft; k < iEnd; k++)
    {
        item_i = BagPocket_GetSlotData(pocket, i);
        item_j = BagPocket_GetSlotData(pocket, j);
        if (i < iRight && (j >= iEnd || comparator(pocket->id, item_i, item_j) < 0))
        {
            dummySlots[k] = item_i;
            i++;
        }
        else
        {
            dummySlots[k] = item_j;
            j++;
        }
    }
}

// Source: https://en.wikipedia.org/wiki/Merge_sort#Bottom-up_implementation
static void MergeSort(struct BagPocket *pocket, s32 (*comparator)(enum Pocket, struct ItemSlot, struct ItemSlot))
{
    struct ItemSlot *dummySlots = AllocZeroed(sizeof(struct ItemSlot) * pocket->capacity);

    u32 usedCapacity;
    for (usedCapacity = 0; usedCapacity < pocket->capacity; usedCapacity++)
    {
        if (BagPocket_GetSlotData(pocket, usedCapacity).itemId == ITEM_NONE)
            break;
    }

    for (u32 width = 1; width < usedCapacity; width *= 2)
    {
        for (u32 i = 0; i < usedCapacity; i += 2 * width)
            Merge(pocket, i, min(i + width, usedCapacity), min(i + 2 * width, usedCapacity), dummySlots, comparator);

        for (u32 j = 0; j < usedCapacity; j++)
            BagPocket_SetSlotData(pocket, j, dummySlots[j]);
    }

    Free(dummySlots);
}

static s32 CompareItemsAlphabetically(enum Pocket pocketId, struct ItemSlot item1, struct ItemSlot item2)
{
    const u8 *name1, *name2;

    if (item1.itemId == ITEM_NONE)
        return 1;
    else if (item2.itemId == ITEM_NONE)
        return -1;

    if (pocketId == POCKET_TM_HM)
    {
        name1 = GetMoveName(GetTMHMMoveId(GetItemTMHMIndex(item1.itemId)));
        name2 = GetMoveName(GetTMHMMoveId(GetItemTMHMIndex(item2.itemId)));
    }
    else
    {
        name1 = GetItemName(item1.itemId);
        name2 = GetItemName(item2.itemId);
    }

    return StringCompare(name1, name2);
}

static s32 CompareItemsByMost(enum Pocket pocketId, struct ItemSlot item1, struct ItemSlot item2)
{
    if (item1.itemId == ITEM_NONE)
        return 1;
    else if (item2.itemId == ITEM_NONE)
        return -1;

    if (item1.quantity < item2.quantity)
        return 1;
    else if (item1.quantity > item2.quantity)
        return -1;

    return CompareItemsAlphabetically(pocketId, item1, item2); // Items have same quantity so sort alphabetically
}

static s32 CompareItemsByType(enum Pocket pocketId, struct ItemSlot item1, struct ItemSlot item2)
{
    if (item1.itemId == ITEM_NONE)
        return 1;
    else if (item2.itemId == ITEM_NONE)
        return -1;

    enum ItemSortType type1 = gItemsInfo[item1.itemId].sortType;
    enum ItemSortType type2 = gItemsInfo[item2.itemId].sortType;

    // Uncategorized items go last.
    if (type1 != ITEM_TYPE_UNCATEGORIZED && type2 == ITEM_TYPE_UNCATEGORIZED)
        return -1;
    else if (type2 != ITEM_TYPE_UNCATEGORIZED && type1 == ITEM_TYPE_UNCATEGORIZED)
        return 1;
    else if (type1 < type2)
        return -1;
    else if (type1 > type2)
        return 1;

    return CompareItemsAlphabetically(pocketId, item1, item2); // Items are of same type so sort alphabetically
}

static s32 CompareItemsByIndex(enum Pocket pocketId, struct ItemSlot item1, struct ItemSlot item2)
{
    u16 index1 = 0, index2 = 0;

    if (item1.itemId == ITEM_NONE)
        return 1;
    else if (item2.itemId == ITEM_NONE)
        return -1;

    switch (pocketId)
    {
    case POCKET_TM_HM:
        index1 = GetItemTMHMIndex(item1.itemId);
        index2 = GetItemTMHMIndex(item2.itemId);
        break;
    case POCKET_BERRIES: // To do - requires #7305
        index1 = item1.itemId;
        index2 = item2.itemId;
        break;
    default:
        return 0;
    }

    if (index1 < index2)
        return -1;
    else if (index1 > index2)
        return 1;

    return 0; // Cannot have multiple stacks of indexed items
}

// Lookup table for hyphen-removal — specific compound words that are split with a hyphen
// in vanilla item descriptions get rejoined so they don't look odd when reflowed.
static const struct {
    const char *before;
    const char *after;
} sHyphenRemovalPatterns[] = {
    {"Incine", "roar"},
    {"La",     "riat"},
    {"Marsha", "dow"},
    {"Thi",    "ef"},
    {"Elec",   "tric"},
    {"Fight",  "ing"},
    {"pro",    "motes"},
    {"Decidu", "eye"},
    {"Sha",    "ckle"},
    {"invigor","ating"},
    {"Thunder","bolt"},
    {"inde",   "scribable"},
};

static u8 AsciiToGbaChar(char c)
{
    if (c >= 'A' && c <= 'Z') return CHAR_A + (c - 'A');
    if (c >= 'a' && c <= 'z') return CHAR_a + (c - 'a');
    if (c >= '0' && c <= '9') return CHAR_0 + (c - '0');
    return c;
}

static bool32 ShouldRemoveHyphen(const u8 *p, const u8 *start, const u8 *end)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sHyphenRemovalPatterns); i++)
    {
        const char *before = sHyphenRemovalPatterns[i].before;
        const char *after  = sHyphenRemovalPatterns[i].after;
        u32 beforeLen = 0, afterLen = 0;
        u32 j;
        bool32 matches;

        while (before[beforeLen]) beforeLen++;
        while (after[afterLen])  afterLen++;

        if (p < start + beforeLen)
            continue;

        matches = TRUE;
        for (j = 0; j < beforeLen; j++)
        {
            if (p[-(s32)beforeLen + j] != AsciiToGbaChar(before[j]))
            {
                matches = FALSE;
                break;
            }
        }
        if (!matches)
            continue;

        for (j = 0; j < afterLen; j++)
        {
            if (p[1 + j] != AsciiToGbaChar(after[j]))
            {
                matches = FALSE;
                break;
            }
        }
        if (matches)
            return TRUE;
    }

    // Special case: Poké-mon
    if (p >= start + 4 &&
        p[-4] == CHAR_P && p[-3] == CHAR_o && p[-2] == CHAR_k && p[-1] == CHAR_e_ACUTE &&
        p[1]  == CHAR_m && p[2]  == CHAR_o && p[3]  == CHAR_n)
        return TRUE;

    return FALSE;
}

static bool32 PerformTextFormatting(u8 *result, s32 maxWidth, u8 fontId, const u8 *str, s16 letterSpacing, u32 *outLineCount)
{
    u8 *end, *ptr, *curLine, *lastSpace;

    end = result;
    while (*str != EOS)
    {
        if (*str == CHAR_SPACE || *str == CHAR_NEWLINE)
        {
            if (!(*str == CHAR_NEWLINE && end > result && *(end - 1) == CHAR_HYPHEN))
            {
                *end = EOS;
                end++;
            }
        }
        else
        {
            *end = *str;
            end++;
        }
        str++;
    }
    *end = EOS;

    {
        u8 *p = result;
        while (p < end)
        {
            if (*p == CHAR_HYPHEN && ShouldRemoveHyphen(p, result, end))
            {
                u8 *dst = p;
                u8 *src = p + 1;
                while (src <= end)
                    *dst++ = *src++;
                end--;
            }
            else
            {
                p++;
            }
        }
    }

    ptr = result;
    curLine = ptr;
    *outLineCount = 1;

    while (*ptr != EOS) ptr++;

    while (ptr != end)
    {
        lastSpace = ptr++;
        *lastSpace = CHAR_SPACE;
        if (GetStringWidth(fontId, curLine, letterSpacing) > maxWidth)
        {
            *lastSpace = CHAR_NEWLINE;
            (*outLineCount)++;
            curLine = ptr;
        }
        while (*ptr != EOS) ptr++;
    }

    return (GetStringWidth(fontId, curLine, letterSpacing) <= maxWidth);
}

static u8 FormatDescriptionByWidth(u8 *result, s32 maxWidth, u8 fontId, const u8 *str, s16 letterSpacing)
{
    u32 lineCount;
    bool32 lastLineFits;

    while (TRUE)
    {
        lastLineFits = PerformTextFormatting(result, maxWidth, fontId, str, letterSpacing, &lineCount);

        if (lineCount < 3 && lastLineFits)
            break;

        if (fontId == FONT_SHORT_NARROW)
        {
            fontId = FONT_SHORT_NARROWER;
            letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
        }
        else
        {
            break;
        }
    }

    return fontId;
}

#if SWSH_ITEM_MENU_BERRY_INFO
static void UpdateBerryInfo(s32 itemIndex)
{
    FillWindowPixelBuffer(WIN_BERRY_INFO, PIXEL_FILL(0));
    FillWindowPixelBuffer(WIN_BERRY_FLAVORS, PIXEL_FILL(0));

    if (itemIndex == LIST_CANCEL)
    {
        u8 i;
        for (i = 0; i < FLAVOR_COUNT; i++)
            gSprites[sBerryFlavorMarkSpriteIds[i]].invisible = TRUE;
        CopyWindowToVram(WIN_BERRY_INFO, COPYWIN_GFX);
        CopyWindowToVram(WIN_BERRY_FLAVORS, COPYWIN_GFX);
        return;
    }

    {
        const struct BerryInfo *berryInfo = GetBerryInfo(ItemIdToBerryType(GetBagItemId(gBagPosition.pocket, itemIndex)));

        if (berryInfo->size != 0)
        {
            u32 inches = 1000 * berryInfo->size / 254;
            u32 fraction;
            u8 *ptr;
            if (inches % 10 > 4)
                inches += 10;
            fraction = (inches % 100) / 10;
            inches /= 100;
            ptr = ConvertIntToDecimalStringN(gStringVar4, inches, STR_CONV_MODE_LEFT_ALIGN, 2);
            *ptr++ = CHAR_PERIOD;
            ptr = ConvertIntToDecimalStringN(ptr, fraction, STR_CONV_MODE_LEFT_ALIGN, 1);
            *ptr++ = CHAR_DBL_QUOTE_RIGHT;
            *ptr = EOS;
            BagMenu_Print(WIN_BERRY_INFO, FONT_SHORT_NARROW, gStringVar4, 8, 2, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
        }

        if (berryInfo->firmness != BERRY_FIRMNESS_UNKNOWN)
            BagMenu_Print(WIN_BERRY_INFO, FONT_SHORT_NARROW, sBerryFirmnessStrings[berryInfo->firmness], 0, 16, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);

        BagMenu_Print(WIN_BERRY_FLAVORS, FONT_SHORT_NARROW, sText_BerryFlavorSpicy,   0,  0, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
        BagMenu_Print(WIN_BERRY_FLAVORS, FONT_SHORT_NARROW, sText_BerryFlavorDry,    40,  0, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
        BagMenu_Print(WIN_BERRY_FLAVORS, FONT_SHORT_NARROW, sText_BerryFlavorSweet,  71,  0, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
        BagMenu_Print(WIN_BERRY_FLAVORS, FONT_SHORT_NARROW, sText_BerryFlavorBitter, 14, 16, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
        BagMenu_Print(WIN_BERRY_FLAVORS, FONT_SHORT_NARROW, sText_BerryFlavorSour,   60, 16, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);

        CopyWindowToVram(WIN_BERRY_INFO, COPYWIN_GFX);
        CopyWindowToVram(WIN_BERRY_FLAVORS, COPYWIN_GFX);

        gSprites[sBerryFlavorMarkSpriteIds[FLAVOR_SPICY]].invisible  = (berryInfo->spicy  == 0);
        gSprites[sBerryFlavorMarkSpriteIds[FLAVOR_DRY]].invisible    = (berryInfo->dry    == 0);
        gSprites[sBerryFlavorMarkSpriteIds[FLAVOR_SWEET]].invisible  = (berryInfo->sweet  == 0);
        gSprites[sBerryFlavorMarkSpriteIds[FLAVOR_BITTER]].invisible = (berryInfo->bitter == 0);
        gSprites[sBerryFlavorMarkSpriteIds[FLAVOR_SOUR]].invisible   = (berryInfo->sour   == 0);
    }
}

static void PrintBerryDescriptionInfo(s32 itemIndex)
{
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    if (itemIndex != LIST_CANCEL)
    {
        const struct BerryInfo *berryInfo = GetBerryInfo(ItemIdToBerryType(GetBagItemId(gBagPosition.pocket, itemIndex)));
        AddTextPrinterParameterized4(WIN_DESCRIPTION, FONT_SMALL_NARROWER, 3,  2, 0, 1, sFontColorTable[COLORID_NORMAL], 0, berryInfo->description1);
        AddTextPrinterParameterized4(WIN_DESCRIPTION, FONT_SMALL_NARROWER, 3, 12, 0, 1, sFontColorTable[COLORID_NORMAL], 0, berryInfo->description2);
    }
}

static void SwitchBerryInfoMode(s32 itemIndex)
{
    if (sBerryInfoMode == 0)
    {
        sBerryInfoMode = 1;

        LoadCompressedSpriteSheet(&sSpriteSheet_BerryFlavorMark);
        sBerryFlavorMarkSpriteIds[FLAVOR_SPICY]  = CreateSprite(&sSpriteTemplate_BerryFlavorMark, 106, 136, 0);
        sBerryFlavorMarkSpriteIds[FLAVOR_DRY]    = CreateSprite(&sSpriteTemplate_BerryFlavorMark, 146, 136, 0);
        sBerryFlavorMarkSpriteIds[FLAVOR_SWEET]  = CreateSprite(&sSpriteTemplate_BerryFlavorMark, 177, 136, 0);
        sBerryFlavorMarkSpriteIds[FLAVOR_BITTER] = CreateSprite(&sSpriteTemplate_BerryFlavorMark, 120, 152, 0);
        sBerryFlavorMarkSpriteIds[FLAVOR_SOUR]   = CreateSprite(&sSpriteTemplate_BerryFlavorMark, 166, 152, 0);

        ClearWindowTilemap(WIN_DESCRIPTION);
        UpdateBerryInfo(itemIndex);
        PutWindowTilemap(WIN_BERRY_INFO);
        PutWindowTilemap(WIN_BERRY_FLAVORS);
        ShowInfoPrompt(sBerryTagPrompt_Tilemap);
        ScheduleBgCopyTilemapToVram(1);
    }
    else if (sBerryInfoMode == 1)
    {
        u8 i;
        sBerryInfoMode = 2;

        for (i = 0; i < FLAVOR_COUNT; i++)
        {
            if (sBerryFlavorMarkSpriteIds[i] != SPRITE_NONE)
            {
                DestroySprite(&gSprites[sBerryFlavorMarkSpriteIds[i]]);
                sBerryFlavorMarkSpriteIds[i] = SPRITE_NONE;
            }
        }
        FreeSpriteTilesByTag(TAG_BERRY_FLAVOR_MARK);

        ClearWindowTilemap(WIN_BERRY_INFO);
        ClearWindowTilemap(WIN_BERRY_FLAVORS);
        FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
        CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);

        PrintBerryDescriptionInfo(itemIndex);
        PutWindowTilemap(WIN_DESCRIPTION);
        ShowInfoPrompt(sBerryInfoPrompt_Tilemap);
        ScheduleBgCopyTilemapToVram(1);
    }
    else
    {
        sBerryInfoMode = 0;

        ClearWindowTilemap(WIN_DESCRIPTION);
        PrintItemDescription(itemIndex);
        PutWindowTilemap(WIN_DESCRIPTION);
        ShowInfoPrompt(sBerryStatPrompt_Tilemap);
        ScheduleBgCopyTilemapToVram(1);
    }
}

#endif // SWSH_ITEM_MENU_BERRY_INFO

// ============================================================
// Party Panel
// ============================================================

#define PARTY_PANEL_START_COL   1
#define PARTY_PANEL_START_ROW   1
#define PARTY_PANEL_SLOT_WIDTH  6
#define PARTY_PANEL_SLOT_HEIGHT 3

static void BagMenu_DrawPartySlots(void)
{
    u8 partyCount = CalculatePlayerPartyCount();
    u16 *buf = (u16 *)gBagMenu->mainTilemapBuffer;
    u8 row, col;

    for (row = 0; row < partyCount * PARTY_PANEL_SLOT_HEIGHT; row++)
        for (col = 0; col < PARTY_PANEL_SLOT_WIDTH; col++)
            buf[(PARTY_PANEL_START_ROW + row) * 32 + (PARTY_PANEL_START_COL + col)]
                = sPartySlots_Tilemap[row * PARTY_PANEL_SLOT_WIDTH + col];
}

static void BagMenu_CreatePartyIcons(void)
{
    u8 i;

    memset(gBagMenu->partyMonIconSpriteIds, SPRITE_NONE, sizeof(gBagMenu->partyMonIconSpriteIds));
    LoadMonIconPalettes();

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];
        enum Species species = GetMonData(mon, MON_DATA_SPECIES);
        bool32 isEgg;
        u8 spriteId;
        u8 animNum;

        if (species == SPECIES_NONE)
            continue;

        isEgg = GetMonData(mon, MON_DATA_IS_EGG);
        spriteId = CreateMonIconIsEgg(species, SpriteCB_MonIcon, 32, 24 * i + 16, 6, GetMonData(mon, MON_DATA_PERSONALITY), isEgg);

        if (spriteId == MAX_SPRITES)
            continue;

        gBagMenu->partyMonIconSpriteIds[i] = spriteId;
        gSprites[spriteId].oam.priority = 1;
        gSprites[spriteId].invisible = FALSE;

        if (!isEgg)
        {
            switch (GetHPBarLevel(GetMonData(mon, MON_DATA_HP), GetMonData(mon, MON_DATA_MAX_HP)))
            {
            case HP_BAR_FULL:   animNum = 0; break;
            case HP_BAR_GREEN:  animNum = 1; break;
            case HP_BAR_YELLOW: animNum = 2; break;
            case HP_BAR_RED:    animNum = 3; break;
            default:            animNum = 4; break;
            }
            SetPartyHPBarSprite(&gSprites[spriteId], animNum);
        }
    }
}

static void BagMenu_FreePartyIcons(void)
{
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (gBagMenu->partyMonIconSpriteIds[i] != SPRITE_NONE)
        {
            FreeAndDestroyMonIconSprite(&gSprites[gBagMenu->partyMonIconSpriteIds[i]]);
            gBagMenu->partyMonIconSpriteIds[i] = SPRITE_NONE;
        }
    }
    FreeMonIconPalettes();
}

// ============================================================
// Inline Party Select
// ============================================================

#if SWSH_ITEM_MENU_ACTION_IN_BAG

static void BagMenu_PartyPanelStartItemIconYAnim(struct Sprite *spr, s16 toY)
{
    struct ComfyAnimEasingConfig config;
    InitComfyAnimConfig_Easing(&config);
    config.from = Q_24_8(spr->y2);
    config.to = Q_24_8(toY);
    config.durationFrames = 8;
    config.easingFunc = ComfyAnimEasing_EaseOutCubic;
    if (sPartyPanelItemIconAnimId == INVALID_COMFY_ANIM)
        sPartyPanelItemIconAnimId = CreateComfyAnim_Easing(&config);
    else
        InitComfyAnim_Easing(&config, &gComfyAnims[sPartyPanelItemIconAnimId]);
}

void BagMenu_OpenPartyPanelSelect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 iconSpriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + (gBagMenu->itemIconSlot ^ 1)];

    if (gItemUseCB == ItemUseCB_SacredAsh)
    {
        BagMenu_ApplySacredAsh(taskId);
        return;
    }

    tPartyPanelSlot = 0;
    tPartyPanelSavedIconY = ReadComfyAnimValueSmooth(&gComfyAnims[sCursorAnimId]);

    gSprites[sCursorSpriteId].invisible = TRUE;

    if (iconSpriteId != SPRITE_NONE)
    {
        struct Sprite *spr = &gSprites[iconSpriteId];
        spr->x2 = PARTY_PANEL_ITEM_ICON_X;
        BagMenu_PartyPanelStartItemIconYAnim(spr, PARTY_PANEL_ITEM_ICON_Y(0));
    }

    gTasks[taskId].func = Task_BagMenu_PartyPanelInput;
}

void BagMenu_OpenPartyPanelSelectBattle(u8 taskId)
{
    // TODO: Phase 4 — battle-specific slot filtering
    BagMenu_OpenPartyPanelSelect(taskId);
}

static void Task_BagMenu_PartyPanelInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 partyCount = CalculatePlayerPartyCount();
    u8 iconSpriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + (gBagMenu->itemIconSlot ^ 1)];

    if (iconSpriteId != SPRITE_NONE && sPartyPanelItemIconAnimId != INVALID_COMFY_ANIM)
        gSprites[iconSpriteId].y2 = ReadComfyAnimValueSmooth(&gComfyAnims[sPartyPanelItemIconAnimId]);

    if (sPartyPanelItemIconAnimId != INVALID_COMFY_ANIM && !gComfyAnims[sPartyPanelItemIconAnimId].completed)
        return;

    if (JOY_NEW(DPAD_DOWN))
    {
        tPartyPanelSlot = (tPartyPanelSlot == partyCount - 1) ? 0 : tPartyPanelSlot + 1;
        PlaySE(SE_SELECT);
        if (iconSpriteId != SPRITE_NONE)
            BagMenu_PartyPanelStartItemIconYAnim(&gSprites[iconSpriteId], PARTY_PANEL_ITEM_ICON_Y(tPartyPanelSlot));
    }
    else if (JOY_NEW(DPAD_UP))
    {
        tPartyPanelSlot = (tPartyPanelSlot == 0) ? partyCount - 1 : tPartyPanelSlot - 1;
        PlaySE(SE_SELECT);
        if (iconSpriteId != SPRITE_NONE)
            BagMenu_PartyPanelStartItemIconYAnim(&gSprites[iconSpriteId], PARTY_PANEL_ITEM_ICON_Y(tPartyPanelSlot));
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_ClosePartyPanelSelect(taskId);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        BagMenu_DispatchApplyItem(taskId);
    }
}

static void BagMenu_ClosePartyPanelSelect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 iconSpriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + (gBagMenu->itemIconSlot ^ 1)];

    if (sPartyPanelItemIconAnimId != INVALID_COMFY_ANIM)
    {
        ReleaseComfyAnim(sPartyPanelItemIconAnimId);
        sPartyPanelItemIconAnimId = INVALID_COMFY_ANIM;
    }

    gSprites[sCursorSpriteId].invisible = FALSE;

    if (iconSpriteId != SPRITE_NONE)
    {
        struct Sprite *spr = &gSprites[iconSpriteId];
        spr->x2 = 102;
        spr->y2 = tPartyPanelSavedIconY + 4;
    }

    ReturnToItemList(taskId);
}

static void BagMenu_RefreshItemList(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];

    DestroyListMenuTask(tListTaskId, scrollPos, cursorPos);
    UpdatePocketItemList(gBagPosition.pocket);
    UpdatePocketListPosition(gBagPosition.pocket);
    LoadBagItemListBuffers(gBagPosition.pocket);
    tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, *scrollPos, *cursorPos);
    ScheduleBgCopyTilemapToVram(1);
}

static void Task_BagMenu_PartyPanelStayAfterMessage(u8 taskId)
{
    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    gTasks[taskId].func = Task_BagMenu_PartyPanelInput;
}

static void Task_BagMenu_PartyPanelAfterItemUse(u8 taskId)
{
    u8 keepSlot = gBagMenu->itemIconSlot ^ 1;
    u8 keepSpriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + keepSlot];
    u8 newSlot, newSpriteId;

    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + keepSlot] = SPRITE_NONE;

    BagMenu_RefreshItemList(taskId);
    newSlot = gBagMenu->itemIconSlot ^ 1;
    newSpriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + newSlot];

    if (!CheckBagHasItem(gSpecialVar_ItemId, 1))
    {
        if (keepSpriteId != SPRITE_NONE)
            DestroySpriteAndFreeResources(&gSprites[keepSpriteId]);
        BagMenu_ClosePartyPanelSelect(taskId);
        return;
    }

    if (newSpriteId != SPRITE_NONE)
    {
        DestroySpriteAndFreeResources(&gSprites[newSpriteId]);
        gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + newSlot] = SPRITE_NONE;
    }
    gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + newSlot] = keepSpriteId;

    gTasks[taskId].func = Task_BagMenu_PartyPanelInput;
}

static void BagMenu_GetMedicineEffectMessage(enum Item item, u32 statusCured)
{
    switch (GetItemEffectType(item))
    {
    case ITEM_EFFECT_CURE_POISON:
        StringExpandPlaceholders(gStringVar4, gText_PkmnCuredOfPoison);
        break;
    case ITEM_EFFECT_CURE_SLEEP:
        StringExpandPlaceholders(gStringVar4, gText_PkmnWokeUp2);
        break;
    case ITEM_EFFECT_CURE_BURN:
        StringExpandPlaceholders(gStringVar4, gText_PkmnBurnHealed);
        break;
    case ITEM_EFFECT_CURE_FREEZE_FROSTBITE:
        if (statusCured & STATUS1_FREEZE)
            StringExpandPlaceholders(gStringVar4, gText_PkmnThawedOut);
        if (statusCured & STATUS1_FROSTBITE)
            StringExpandPlaceholders(gStringVar4, gText_PkmnFrostbiteHealed);
        break;
    case ITEM_EFFECT_CURE_PARALYSIS:
        StringExpandPlaceholders(gStringVar4, gText_PkmnCuredOfParalysis);
        break;
    case ITEM_EFFECT_CURE_CONFUSION:
        StringExpandPlaceholders(gStringVar4, gText_PkmnSnappedOutOfConfusion);
        break;
    case ITEM_EFFECT_CURE_INFATUATION:
        StringExpandPlaceholders(gStringVar4, gText_PkmnGotOverInfatuation);
        break;
    case ITEM_EFFECT_CURE_ALL_STATUS:
        StringExpandPlaceholders(gStringVar4, gText_PkmnBecameHealthy);
        break;
    case ITEM_EFFECT_HP_EV:
        StringCopy(gStringVar2, gText_HP3);
        StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
        break;
    case ITEM_EFFECT_ATK_EV:
        StringCopy(gStringVar2, gText_Attack3);
        StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
        break;
    case ITEM_EFFECT_DEF_EV:
        StringCopy(gStringVar2, gText_Defense3);
        StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
        break;
    case ITEM_EFFECT_SPEED_EV:
        StringCopy(gStringVar2, gText_Speed2);
        StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
        break;
    case ITEM_EFFECT_SPATK_EV:
        StringCopy(gStringVar2, gText_SpAtk3);
        StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
        break;
    case ITEM_EFFECT_SPDEF_EV:
        StringCopy(gStringVar2, gText_SpDef3);
        StringExpandPlaceholders(gStringVar4, gText_PkmnBaseVar2StatIncreased);
        break;
    case ITEM_EFFECT_PP_UP:
    case ITEM_EFFECT_PP_MAX:
        StringExpandPlaceholders(gStringVar4, gText_MovesPPIncreased);
        break;
    case ITEM_EFFECT_HEAL_PP:
        StringExpandPlaceholders(gStringVar4, gText_PPWasRestored);
        break;
    default:
        StringExpandPlaceholders(gStringVar4, gText_WontHaveEffect);
        break;
    }
}

static void BagMenu_ApplySacredAsh(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    enum Item item = gSpecialVar_ItemId;
    u8 revivedMask = 0;
    u8 slot;

    for (slot = 0; slot < PARTY_SIZE; slot++)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][slot];
        if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE
            && GetMonData(mon, MON_DATA_HP) == 0
            && !ExecuteTableBasedItemEffect(mon, item, slot, 0))
        {
            revivedMask |= (1 << slot);
        }
    }

    if (!revivedMask)
    {
        PlaySE(SE_SELECT);
        DisplayItemMessage(taskId, FONT_NORMAL, gText_WontHaveEffect, CloseItemMessage);
        return;
    }

    PlaySE(SE_USE_ITEM);
    RemoveBagItem(item, 1);
    tPartyPanelTemp = 0;
    data[7] = revivedMask;
    Task_BagMenu_SacredAshMessages(taskId);
}

static void Task_BagMenu_SacredAshMessages(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 slot = (u8)tPartyPanelTemp;
    u8 revivedMask = (u8)data[7];

    while (slot < PARTY_SIZE && !(revivedMask & (1 << slot)))
        slot++;

    if (slot >= PARTY_SIZE)
    {
        CloseItemMessage(taskId);
        return;
    }

    tPartyPanelTemp = slot + 1;

    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][slot];
    GetMonNickname(mon, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, GetMonData(mon, MON_DATA_HP), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_PkmnHPRestoredByVar2);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_SacredAshMessages);
}

static void BagMenu_ApplyMedicine(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartyPanelSlot];
    enum Item item = gSpecialVar_ItemId;
    u16 hp = 0;
    u32 oldStatus = GetMonData(mon, MON_DATA_STATUS);
    bool8 canHeal = FALSE;
    bool8 cannotUse;

    if (GetItemEffectType(item) == ITEM_EFFECT_HP_EV && HasShedinjaHPHandling(GetMonData(mon, MON_DATA_SPECIES)))
    {
        cannotUse = TRUE;
    }
    else
    {
        const u8 *effect = GetItemEffect(item);
        canHeal = (effect != NULL && (effect[4] & ITEM4_HEAL_HP));
        if (canHeal)
        {
            hp = GetMonData(mon, MON_DATA_HP);
            if (hp == GetMonData(mon, MON_DATA_MAX_HP))
                canHeal = FALSE;
        }
        cannotUse = ExecuteTableBasedItemEffect(mon, item, tPartyPanelSlot, 0);
    }

    if (cannotUse)
    {
        PlaySE(SE_SELECT);
        DisplayItemMessage(taskId, FONT_NORMAL, gText_WontHaveEffect, Task_BagMenu_PartyPanelStayAfterMessage);
        return;
    }

    PlaySE(SE_USE_ITEM);
    RemoveBagItem(item, 1);

    GetMonNickname(mon, gStringVar1);
    if (canHeal)
    {
        u16 newHp = GetMonData(mon, MON_DATA_HP);
        ConvertIntToDecimalStringN(gStringVar2, newHp - hp, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringExpandPlaceholders(gStringVar4, gText_PkmnHPRestoredByVar2);
    }
    else
    {
        BagMenu_GetMedicineEffectMessage(item, oldStatus);
    }

    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyPanelAfterItemUse);
}

static void BagMenu_ApplyResetEVs(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartyPanelSlot];
    enum Item item = gSpecialVar_ItemId;
    bool8 cannotUse = ExecuteTableBasedItemEffect(mon, item, tPartyPanelSlot, 0);

    if (cannotUse)
    {
        PlaySE(SE_SELECT);
        DisplayItemMessage(taskId, FONT_NORMAL, gText_WontHaveEffect, Task_BagMenu_PartyPanelStayAfterMessage);
        return;
    }

    PlaySE(SE_USE_ITEM);
    RemoveBagItem(item, 1);
    GetMonNickname(mon, gStringVar1);
    StringExpandPlaceholders(gStringVar4, sText_PartyPanelBasePointsReset);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyPanelAfterItemUse);
}

static void BagMenu_ApplyDynamaxCandy(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartyPanelSlot];
    enum Item item = gSpecialVar_ItemId;
    u8 dynamaxLevel = GetMonData(mon, MON_DATA_DYNAMAX_LEVEL);

    if (dynamaxLevel >= MAX_DYNAMAX_LEVEL)
    {
        PlaySE(SE_SELECT);
        DisplayItemMessage(taskId, FONT_NORMAL, gText_WontHaveEffect, Task_BagMenu_PartyPanelStayAfterMessage);
        return;
    }

    PlaySE(SE_USE_ITEM);
    dynamaxLevel++;
    SetMonData(mon, MON_DATA_DYNAMAX_LEVEL, &dynamaxLevel);
    RemoveBagItem(item, 1);
    GetMonNickname(mon, gStringVar1);
    StringExpandPlaceholders(gStringVar4, sText_PartyPanelDynamaxLevelUp);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyPanelAfterItemUse);
}

static u16 BagMenu_GetMonEV(struct Pokemon *mon, enum ItemEffectType effectType)
{
    switch (effectType)
    {
    case ITEM_EFFECT_HP_EV:
        if (!HasShedinjaHPHandling(GetMonData(mon, MON_DATA_SPECIES)))
            return GetMonData(mon, MON_DATA_HP_EV);
        break;
    case ITEM_EFFECT_ATK_EV:
        return GetMonData(mon, MON_DATA_ATK_EV);
    case ITEM_EFFECT_DEF_EV:
        return GetMonData(mon, MON_DATA_DEF_EV);
    case ITEM_EFFECT_SPEED_EV:
        return GetMonData(mon, MON_DATA_SPEED_EV);
    case ITEM_EFFECT_SPATK_EV:
        return GetMonData(mon, MON_DATA_SPATK_EV);
    case ITEM_EFFECT_SPDEF_EV:
        return GetMonData(mon, MON_DATA_SPDEF_EV);
    default:
        break;
    }
    return 0;
}

static void BagMenu_GetEVStatName(enum ItemEffectType effectType, u8 *dest)
{
    switch (effectType)
    {
    case ITEM_EFFECT_HP_EV:
        StringCopy(dest, gText_HP3);
        break;
    case ITEM_EFFECT_ATK_EV:
        StringCopy(dest, gText_Attack3);
        break;
    case ITEM_EFFECT_DEF_EV:
        StringCopy(dest, gText_Defense3);
        break;
    case ITEM_EFFECT_SPEED_EV:
        StringCopy(dest, gText_Speed2);
        break;
    case ITEM_EFFECT_SPATK_EV:
        StringCopy(dest, gText_SpAtk3);
        break;
    case ITEM_EFFECT_SPDEF_EV:
        StringCopy(dest, gText_SpDef3);
        break;
    default:
        break;
    }
}

static void BagMenu_ApplyReduceEV(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartyPanelSlot];
    enum Item item = gSpecialVar_ItemId;
    enum ItemEffectType effectType = GetItemEffectType(item);
    u16 friendship = GetMonData(mon, MON_DATA_FRIENDSHIP);
    u16 ev = BagMenu_GetMonEV(mon, effectType);
    bool8 cannotUse = ExecuteTableBasedItemEffect(mon, item, tPartyPanelSlot, 0);
    u16 newFriendship = GetMonData(mon, MON_DATA_FRIENDSHIP);
    u16 newEv = BagMenu_GetMonEV(mon, effectType);

    if (cannotUse || (friendship == newFriendship && ev == newEv))
    {
        PlaySE(SE_SELECT);
        DisplayItemMessage(taskId, FONT_NORMAL, gText_WontHaveEffect, Task_BagMenu_PartyPanelStayAfterMessage);
        return;
    }

    PlaySE(SE_USE_ITEM);
    RemoveBagItem(item, 1);
    GetMonNickname(mon, gStringVar1);
    BagMenu_GetEVStatName(effectType, gStringVar2);
    if (friendship != newFriendship)
    {
        if (ev != newEv)
            StringExpandPlaceholders(gStringVar4, gText_PkmnFriendlyBaseVar2Fell);
        else
            StringExpandPlaceholders(gStringVar4, gText_PkmnFriendlyBaseVar2CantFall);
    }
    else
    {
        StringExpandPlaceholders(gStringVar4, gText_PkmnAdoresBaseVar2Fell);
    }
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyPanelAfterItemUse);
}

static void Task_BagMenu_AbilityChangeYesNo(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tPartyPanelTemp)
    {
    case 0:
        BagMenu_YesNo(taskId, ITEMWIN_YESNO_HIGH, &sPartyPanelAbilityChangeYesNo);
        tPartyPanelTemp++;
        break;
    case 1:
        break;
    }
}

static void BagMenu_AbilityChangeYes(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartyPanelSlot];
    enum Item item = gSpecialVar_ItemId;
    u8 currentAbilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM);
    u8 abilityNum;

    if (item == ITEM_ABILITY_PATCH)
        abilityNum = (currentAbilityNum == 2) ? 0 : 2;
    else
        abilityNum = currentAbilityNum ^ 1;

    PlaySE(SE_USE_ITEM);
    SetMonData(mon, MON_DATA_ABILITY_NUM, &abilityNum);
    RemoveBagItem(item, 1);
    GetMonNickname(mon, gStringVar1);
    u32 species = GetMonData(mon, MON_DATA_SPECIES);
    StringCopy(gStringVar2, gAbilitiesInfo[GetAbilityBySpecies(species, abilityNum)].name);
    StringExpandPlaceholders(gStringVar4, sText_PartyPanelAbilityDone);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyPanelAfterItemUse);
}

static void BagMenu_AbilityChangeNo(u8 taskId)
{
    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    gTasks[taskId].func = Task_BagMenu_PartyPanelInput;
}

static void BagMenu_ApplyAbilityCapsule(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartyPanelSlot];
    u32 species = GetMonData(mon, MON_DATA_SPECIES);
    u8 abilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM) ^ 1;

    if (!species
        || GetSpeciesAbility(species, 0) == GetSpeciesAbility(species, 1)
        || GetSpeciesAbility(species, 1) == 0
        || GetMonData(mon, MON_DATA_ABILITY_NUM) > 1)
    {
        PlaySE(SE_SELECT);
        DisplayItemMessage(taskId, FONT_NORMAL, gText_WontHaveEffect, Task_BagMenu_PartyPanelStayAfterMessage);
        return;
    }

    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, gAbilitiesInfo[GetAbilityBySpecies(species, abilityNum)].name);
    StringExpandPlaceholders(gStringVar4, sText_PartyPanelAbilityAsk);
    tPartyPanelTemp = 0;
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_AbilityChangeYesNo);
}

static void BagMenu_ApplyAbilityPatch(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartyPanelSlot];
    u32 species = GetMonData(mon, MON_DATA_SPECIES);
    u8 currentAbilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM);
    u8 abilityNum = (currentAbilityNum == 2) ? 0 : 2;

    if (!species || GetSpeciesAbility(species, abilityNum) == 0)
    {
        PlaySE(SE_SELECT);
        DisplayItemMessage(taskId, FONT_NORMAL, gText_WontHaveEffect, Task_BagMenu_PartyPanelStayAfterMessage);
        return;
    }

    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, gAbilitiesInfo[GetAbilityBySpecies(species, abilityNum)].name);
    StringExpandPlaceholders(gStringVar4, sText_PartyPanelAbilityAsk);
    tPartyPanelTemp = 0;
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_AbilityChangeYesNo);
}

static void Task_BagMenu_MintYesNo(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tPartyPanelTemp)
    {
    case 0:
        BagMenu_YesNo(taskId, ITEMWIN_YESNO_HIGH, &sPartyPanelMintYesNo);
        tPartyPanelTemp++;
        break;
    case 1:
        break;
    }
}

static void BagMenu_MintYes(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartyPanelSlot];
    enum Item item = gSpecialVar_ItemId;
    u8 newNature = GetItemSecondaryId(item);

    PlaySE(SE_USE_ITEM);
    SetMonData(mon, MON_DATA_HIDDEN_NATURE, &newNature);
    CalculateMonStats(mon);
    RemoveBagItem(item, 1);
    GetMonNickname(mon, gStringVar1);
    CopyItemName(item, gStringVar2);
    StringExpandPlaceholders(gStringVar4, sText_PartyPanelMintDone);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyPanelAfterItemUse);
}

static void BagMenu_MintNo(u8 taskId)
{
    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    gTasks[taskId].func = Task_BagMenu_PartyPanelInput;
}

static void BagMenu_ApplyMint(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartyPanelSlot];
    enum Item item = gSpecialVar_ItemId;
    u8 currentNature = GetMonData(mon, MON_DATA_HIDDEN_NATURE);
    u8 newNature = GetItemSecondaryId(item);

    if (currentNature == newNature)
    {
        PlaySE(SE_SELECT);
        DisplayItemMessage(taskId, FONT_NORMAL, gText_WontHaveEffect, Task_BagMenu_PartyPanelStayAfterMessage);
        return;
    }

    GetMonNickname(mon, gStringVar1);
    CopyItemName(item, gStringVar2);
    StringExpandPlaceholders(gStringVar4, sText_PartyPanelMintAsk);
    tPartyPanelTemp = 0;
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_MintYesNo);
}

static void BagMenu_ApplyPPToMove(u8 taskId, u8 moveSlot)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartyPanelSlot];
    enum Item item = gSpecialVar_ItemId;

    if (ExecuteTableBasedItemEffect(mon, item, tPartyPanelSlot, moveSlot))
    {
        PlaySE(SE_SELECT);
        DisplayItemMessage(taskId, FONT_NORMAL, gText_WontHaveEffect, Task_BagMenu_PartyPanelStayAfterMessage);
        return;
    }

    PlaySE(SE_USE_ITEM);
    RemoveBagItem(item, 1);
    StringCopy(gStringVar1, GetMoveName(GetMonData(mon, MON_DATA_MOVE1 + moveSlot)));
    BagMenu_GetMedicineEffectMessage(item, 0);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyPanelAfterItemUse);
}

static void BagMenu_ShowPPMoveSelectWindow(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartyPanelSlot];
    u8 windowId = BagMenu_AddWindow(ITEMWIN_PP_MOVE_SELECT);
    u8 moveCount = 0;
    u8 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        enum Move move = GetMonData(mon, MON_DATA_MOVE1 + i);
        u8 fontId = GetFontIdToFit(GetMoveName(move), FONT_NORMAL, 0, 72);
        AddTextPrinterParameterized(windowId, fontId, GetMoveName(move), 8, (i * 16) + 1, TEXT_SKIP_DRAW, NULL);
        if (move != MOVE_NONE)
            moveCount++;
    }
    InitMenuInUpperLeftCornerNormal(windowId, moveCount, 0);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_BagMenu_PPMoveSelectInput;
}

static void Task_BagMenu_PPMoveSelectInput(u8 taskId)
{
    s8 input = Menu_ProcessInput();

    if (input == MENU_NOTHING_CHOSEN)
        return;

    BagMenu_RemoveWindow(ITEMWIN_PP_MOVE_SELECT);

    if (input == MENU_B_PRESSED)
        gTasks[taskId].func = Task_BagMenu_PartyPanelInput;
    else
        BagMenu_ApplyPPToMove(taskId, (u8)input);
}

static void BagMenu_RareCandyBufferStats(struct Pokemon *mon, s16 *data)
{
    data[0] = GetMonData(mon, MON_DATA_MAX_HP);
    data[1] = GetMonData(mon, MON_DATA_ATK);
    data[2] = GetMonData(mon, MON_DATA_DEF);
    data[3] = GetMonData(mon, MON_DATA_SPEED);
    data[4] = GetMonData(mon, MON_DATA_SPATK);
    data[5] = GetMonData(mon, MON_DATA_SPDEF);
}

static void BagMenu_ApplyRareCandy(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartyPanelSlot];
    enum Item item = gSpecialVar_ItemId;
    u8 holdEffectParam = GetItemHoldEffectParam(item);
    bool8 cannotUse;
    u8 initialLevel = GetMonData(mon, MON_DATA_LEVEL);

    if (sBagRareCandyState == NULL)
        sBagRareCandyState = AllocZeroed(sizeof(*sBagRareCandyState));

    sBagRareCandyState->slot = tPartyPanelSlot;
    sBagRareCandyState->savedExitCallback = gBagPosition.exitCallback;

    if (B_RARE_CANDY_CAP && initialLevel >= GetCurrentLevelCap())
    {
        cannotUse = TRUE;
    }
    else
    {
        BagMenu_RareCandyBufferStats(mon, sBagRareCandyState->statsBefore);
        cannotUse = ExecuteTableBasedItemEffect(mon, item, tPartyPanelSlot, 0);
        BagMenu_RareCandyBufferStats(mon, sBagRareCandyState->statsAfter);
    }

    PlaySE(SE_SELECT);

    if (cannotUse)
    {
        if (holdEffectParam == 0)
        {
            bool32 canStopEvo = TRUE;
            enum Species target = GetEvolutionTargetSpecies(mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, &canStopEvo, CHECK_EVO);
            if (target != SPECIES_NONE)
            {
                GetEvolutionTargetSpecies(mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, &canStopEvo, DO_EVO);
                RemoveBagItem(item, 1);
                sBagRareCandyState->evolutionTarget = target;
                sBagRareCandyState->canStopEvolution = canStopEvo;
                gCB2_AfterEvolution = BagMenu_CB2_AfterRareCandyEvolution;
                gBagMenu->newScreenCallback = BagMenu_CB2_DoBeginEvolution;
                Task_FadeAndCloseBagMenu(taskId);
                return;
            }
        }
        Free(sBagRareCandyState);
        sBagRareCandyState = NULL;
        DisplayItemMessage(taskId, FONT_NORMAL, gText_WontHaveEffect, Task_BagMenu_PartyPanelStayAfterMessage);
        return;
    }

    sBagRareCandyState->initialLevel = initialLevel;
    sBagRareCandyState->finalLevel = GetMonData(mon, MON_DATA_LEVEL);
    RemoveBagItem(item, 1);
    GetMonNickname(mon, gStringVar1);

    if (sBagRareCandyState->finalLevel > sBagRareCandyState->initialLevel)
    {
        PlayFanfareByFanfareNum(FANFARE_LEVEL_UP);
        if (holdEffectParam == 0)
        {
            ConvertIntToDecimalStringN(gStringVar2, sBagRareCandyState->finalLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
            StringExpandPlaceholders(gStringVar4, gText_PkmnElevatedToLvVar2);
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar2, sExpCandyExperienceTable[holdEffectParam - 1], STR_CONV_MODE_LEFT_ALIGN, 6);
            ConvertIntToDecimalStringN(gStringVar3, sBagRareCandyState->finalLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
            StringExpandPlaceholders(gStringVar4, gText_PkmnGainedExpAndElevatedToLvVar3);
        }
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_RareCandyWaitLvUpMsg);
    }
    else
    {
        PlaySE(SE_USE_ITEM);
        ConvertIntToDecimalStringN(gStringVar2, sExpCandyExperienceTable[holdEffectParam - 1], STR_CONV_MODE_LEFT_ALIGN, 6);
        StringExpandPlaceholders(gStringVar4, gText_PkmnGainedExp);
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyPanelAfterItemUse);
        Free(sBagRareCandyState);
        sBagRareCandyState = NULL;
    }
}

static void Task_BagMenu_RareCandyWaitLvUpMsg(u8 taskId)
{
    if (IsPartyMenuTextPrinterActive() != TRUE && WaitFanfare(FALSE)
        && (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON)))
    {
        u8 windowId;
        RemoveItemMessageWindow(ITEMWIN_MESSAGE);
        windowId = BagMenu_AddWindow(ITEMWIN_LEVEL_UP_STATS);
        DrawLevelUpWindowPg1(windowId, (u16 *)sBagRareCandyState->statsBefore,
                             (u16 *)sBagRareCandyState->statsAfter,
                             TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY);
        CopyWindowToVram(windowId, COPYWIN_GFX);
        ScheduleBgCopyTilemapToVram(0);
        gTasks[taskId].func = Task_BagMenu_RareCandyStatsPg1;
    }
}

static void Task_BagMenu_RareCandyStatsPg1(u8 taskId)
{
    if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
    {
        DrawLevelUpWindowPg2(gBagMenu->windowIds[ITEMWIN_LEVEL_UP_STATS],
                             (u16 *)sBagRareCandyState->statsAfter,
                             TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY);
        CopyWindowToVram(gBagMenu->windowIds[ITEMWIN_LEVEL_UP_STATS], COPYWIN_GFX);
        ScheduleBgCopyTilemapToVram(0);
        gTasks[taskId].func = Task_BagMenu_RareCandyStatsPg2;
    }
}

static void Task_BagMenu_RareCandyStatsPg2(u8 taskId)
{
    if (WaitFanfare(FALSE) && (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON)))
    {
        BagMenu_RemoveWindow(ITEMWIN_LEVEL_UP_STATS);
        sBagRareCandyState->learnMoveLevel = sBagRareCandyState->initialLevel + 1;
        sBagRareCandyState->firstMoveAtLevel = TRUE;
        BagMenu_RareCandyDoLearnMoveStep(taskId);
    }
}

static void BagMenu_RareCandyDoLearnMoveStep(u8 taskId)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][sBagRareCandyState->slot];

    for (; sBagRareCandyState->learnMoveLevel <= sBagRareCandyState->finalLevel;)
    {
        bool8 first = sBagRareCandyState->firstMoveAtLevel;
        u16 result;

        sBagRareCandyState->firstMoveAtLevel = FALSE;
        SetMonData(mon, MON_DATA_LEVEL, &sBagRareCandyState->learnMoveLevel);
        result = MonTryLearningNewMove(mon, first);
        switch (result)
        {
        case 0:
            if (sBagRareCandyState->learnMoveLevel >= sBagRareCandyState->finalLevel)
            {
                BagMenu_RareCandyTryEvolution(taskId);
                return;
            }
            sBagRareCandyState->learnMoveLevel++;
            sBagRareCandyState->firstMoveAtLevel = TRUE;
            continue;
        case MON_ALREADY_KNOWS_MOVE:
            continue;
        case MON_HAS_MAX_MOVES:
            sBagRareCandyState->moveToLearn = gMoveToLearn;
            GetMonNickname(mon, gStringVar1);
            StringCopy(gStringVar2, GetMoveName(gMoveToLearn));
            StringExpandPlaceholders(gStringVar4, gText_PkmnNeedsToReplaceMove);
            gTasks[taskId].tPartyPanelTemp = 0;
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_RareCandyReplaceYesNo);
            return;
        default:
            GetMonNickname(mon, gStringVar1);
            StringCopy(gStringVar2, GetMoveName(result));
            StringExpandPlaceholders(gStringVar4, gText_PkmnLearnedMove3);
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_RareCandyMoveLearned);
            sBagRareCandyState->learnMoveLevel++;
            sBagRareCandyState->firstMoveAtLevel = TRUE;
            return;
        }
    }
    BagMenu_RareCandyTryEvolution(taskId);
}

static void Task_BagMenu_RareCandyMoveLearned(u8 taskId)
{
    PlayFanfare(MUS_LEVEL_UP);
    gTasks[taskId].func = Task_BagMenu_RareCandyMoveLearned2;
}

static void Task_BagMenu_RareCandyMoveLearned2(u8 taskId)
{
    if (IsFanfareTaskInactive() && (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON)))
    {
        RemoveItemMessageWindow(ITEMWIN_MESSAGE);
        BagMenu_RareCandyDoLearnMoveStep(taskId);
    }
}

static void Task_BagMenu_RareCandyReplaceYesNo(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tPartyPanelTemp)
    {
    case 0:
        BagMenu_YesNo(taskId, ITEMWIN_YESNO_HIGH, &sPartyPanelRareCandyReplaceYesNo);
        tPartyPanelTemp++;
        break;
    case 1:
        break;
    }
}

static void BagMenu_RareCandyReplaceYes(u8 taskId)
{
    GetMonNickname(&gParties[B_TRAINER_PLAYER][sBagRareCandyState->slot], gStringVar1);
    StringCopy(gStringVar2, GetMoveName(sBagRareCandyState->moveToLearn));
    StringExpandPlaceholders(gStringVar4, gText_WhichMoveToForget);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_RareCandyGoToSummary);
}

static void BagMenu_RareCandyReplaceNo(u8 taskId)
{
    GetMonNickname(&gParties[B_TRAINER_PLAYER][sBagRareCandyState->slot], gStringVar1);
    StringCopy(gStringVar2, GetMoveName(sBagRareCandyState->moveToLearn));
    StringExpandPlaceholders(gStringVar4, gText_MoveNotLearned);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_RareCandyAfterNotLearned);
}

static void Task_BagMenu_RareCandyAfterNotLearned(u8 taskId)
{
    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    BagMenu_RareCandyDoLearnMoveStep(taskId);
}

static void Task_BagMenu_RareCandyGoToSummary(u8 taskId)
{
    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    sBagRareCandyState->reentryPhase = RARE_CANDY_REENTRY_MOVE_FORGET;
    gBagMenu->newScreenCallback = BagMenu_CB2_SummaryForMoveForget;
    Task_FadeAndCloseBagMenu(taskId);
}

static void BagMenu_CB2_SummaryForMoveForget(void)
{
    ShowSelectMovePokemonSummaryScreen(gParties[B_TRAINER_PLAYER],
                                      sBagRareCandyState->slot,
                                      BagMenu_CB2_ReturnFromMoveForget,
                                      sBagRareCandyState->moveToLearn);
}

static void BagMenu_CB2_ReturnFromMoveForget(void)
{
    GoToBagMenu(ITEMMENULOCATION_LAST, POCKETS_COUNT, sBagRareCandyState->savedExitCallback);
}

static void Task_BagMenu_RareCandyReentry(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (gPaletteFade.active)
        return;

    switch (sBagRareCandyState->reentryPhase)
    {
    case RARE_CANDY_REENTRY_MOVE_FORGET:
    {
        tPartyPanelSlot = sBagRareCandyState->slot;
        tPartyPanelSavedIconY = ReadComfyAnimValueSmooth(&gComfyAnims[sCursorAnimId]);
        gSprites[sCursorSpriteId].invisible = TRUE;
        sBagRareCandyState->reentryPhase = RARE_CANDY_REENTRY_NONE;
        gTasks[taskId].func = Task_BagMenu_RareCandyAfterMoveForget;
        break;
    }
    case RARE_CANDY_REENTRY_CANDY_USE:
    {
        u8 slot = sBagRareCandyState->slot;
        tPartyPanelSlot = slot;
        tPartyPanelSavedIconY = ReadComfyAnimValueSmooth(&gComfyAnims[sCursorAnimId]);
        gSprites[sCursorSpriteId].invisible = TRUE;
        Free(sBagRareCandyState);
        sBagRareCandyState = NULL;
        gTasks[taskId].func = Task_BagMenu_PartyPanelInput;
        break;
    }
    }
}

static void Task_BagMenu_RareCandyAfterMoveForget(u8 taskId)
{
    u8 moveSlot;

    if (sPartyPanelItemIconAnimId != INVALID_COMFY_ANIM && !gComfyAnims[sPartyPanelItemIconAnimId].completed)
        return;

    moveSlot = GetMoveSlotToReplace();
    if (moveSlot != MAX_MON_MOVES)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][sBagRareCandyState->slot];
        enum Move oldMove = GetMonData(mon, MON_DATA_MOVE1 + moveSlot);

        RemoveMonPPBonus(mon, moveSlot);
        SetMonMoveSlot(mon, sBagRareCandyState->moveToLearn, moveSlot);

        GetMonNickname(mon, gStringVar1);
        StringCopy(gStringVar2, GetMoveName(oldMove));
        StringExpandPlaceholders(gStringVar4, gText_12PoofForgotMove);
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_RareCandyAfterForgotMove);
    }
    else
    {
        GetMonNickname(&gParties[B_TRAINER_PLAYER][sBagRareCandyState->slot], gStringVar1);
        StringCopy(gStringVar2, GetMoveName(sBagRareCandyState->moveToLearn));
        StringExpandPlaceholders(gStringVar4, gText_MoveNotLearned);
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_RareCandyAfterNotLearned);
    }
}

static void Task_BagMenu_RareCandyAfterForgotMove(u8 taskId)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][sBagRareCandyState->slot];

    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, GetMoveName(sBagRareCandyState->moveToLearn));
    StringExpandPlaceholders(gStringVar4, gText_PkmnLearnedMove3);
    sBagRareCandyState->learnMoveLevel++;
    sBagRareCandyState->firstMoveAtLevel = TRUE;
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_RareCandyMoveLearned);
}

static void BagMenu_RareCandyTryEvolution(u8 taskId)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][sBagRareCandyState->slot];
    bool32 canStopEvo = TRUE;
    enum Species target = GetEvolutionTargetSpecies(mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, &canStopEvo, CHECK_EVO);

    if (target != SPECIES_NONE)
    {
        GetEvolutionTargetSpecies(mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, &canStopEvo, DO_EVO);
        sBagRareCandyState->evolutionTarget = target;
        sBagRareCandyState->canStopEvolution = canStopEvo;
        gCB2_AfterEvolution = BagMenu_CB2_AfterRareCandyEvolution;
        gBagMenu->newScreenCallback = BagMenu_CB2_DoBeginEvolution;
        Task_FadeAndCloseBagMenu(taskId);
    }
    else
    {
        BagMenu_RareCandyCleanupAndReturn(taskId);
    }
}

static void BagMenu_CB2_DoBeginEvolution(void)
{
    EvolutionScene(&gParties[B_TRAINER_PLAYER][sBagRareCandyState->slot],
                   sBagRareCandyState->evolutionTarget,
                   sBagRareCandyState->canStopEvolution,
                   sBagRareCandyState->slot);
}

static void BagMenu_CB2_AfterRareCandyEvolution(void)
{
    if (GetItemFieldFunc(gSpecialVar_ItemId) == ItemUseOutOfBattle_RareCandy
        && CheckBagHasItem(gSpecialVar_ItemId, 1))
    {
        sBagRareCandyState->reentryPhase = RARE_CANDY_REENTRY_CANDY_USE;
        GoToBagMenu(ITEMMENULOCATION_LAST, POCKETS_COUNT, sBagRareCandyState->savedExitCallback);
    }
    else
    {
        MainCallback exitCb = sBagRareCandyState->savedExitCallback;
        Free(sBagRareCandyState);
        sBagRareCandyState = NULL;
        GoToBagMenu(ITEMMENULOCATION_LAST, POCKETS_COUNT, exitCb);
    }
}

static void BagMenu_RareCandyCleanupAndReturn(u8 taskId)
{
    Free(sBagRareCandyState);
    sBagRareCandyState = NULL;
    Task_BagMenu_PartyPanelAfterItemUse(taskId);
}

static void BagMenu_DispatchApplyItem(u8 taskId)
{
    if (gItemUseCB == ItemUseCB_Medicine)
        BagMenu_ApplyMedicine(taskId);
    else if (gItemUseCB == ItemUseCB_AbilityCapsule)
        BagMenu_ApplyAbilityCapsule(taskId);
    else if (gItemUseCB == ItemUseCB_AbilityPatch)
        BagMenu_ApplyAbilityPatch(taskId);
    else if (gItemUseCB == ItemUseCB_Mint)
        BagMenu_ApplyMint(taskId);
    else if (gItemUseCB == ItemUseCB_ResetEVs)
        BagMenu_ApplyResetEVs(taskId);
    else if (gItemUseCB == ItemUseCB_ReduceEV)
        BagMenu_ApplyReduceEV(taskId);
    else if (gItemUseCB == ItemUseCB_PPUp)
        BagMenu_ShowPPMoveSelectWindow(taskId);
    else if (gItemUseCB == ItemUseCB_PPRecovery)
    {
        const u8 *effect = GetItemEffect(gSpecialVar_ItemId);
        if (effect != NULL && (effect[4] & ITEM4_HEAL_PP_ONE))
            BagMenu_ShowPPMoveSelectWindow(taskId);
        else
            BagMenu_ApplyPPToMove(taskId, 0);
    }
    else if (gItemUseCB == ItemUseCB_RareCandy)
        BagMenu_ApplyRareCandy(taskId);
    else if (gItemUseCB == ItemUseCB_DynamaxCandy)
        BagMenu_ApplyDynamaxCandy(taskId);
    else
        BagMenu_ClosePartyPanelSelect(taskId);
}

#endif // SWSH_ITEM_MENU_ACTION_IN_BAG

#endif // SWSH_ITEM_MENU
