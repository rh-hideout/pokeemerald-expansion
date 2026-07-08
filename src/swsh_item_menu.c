#include "global.h"
#include "item_menu.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_message.h"
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
#include "field_weather.h"
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
#include "dma3.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#if SWSH_ITEM_MENU_TMHM_CONTEST_INFO
#include "contest.h"
#include "contest_effect.h"
#endif
#if SWSH_ITEM_MENU_ACTION_IN_BAG
#include "battle_interface.h"
#include "caps.h"
#include "easy_chat.h"
#include "item_icon.h"
#include "pokemon_icon.h"
#include "evolution_scene.h"
#include "menu_specialized.h"
#include "pokemon_storage_system.h"
#include "constants/party_menu.h"
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
#define TAG_PARTY_HELD_ITEM      121
#define TAG_STATUS_ICON          122
#define TAG_SWAP_PROMPT          123

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
#if SWSH_ITEM_MENU_ACTION_IN_BAG
    WIN_PARTY_HP_BAR,
#endif
};

enum {
    INFO_PROMPT_BATTLE_INFO,
    INFO_PROMPT_BATTLE_STAT,
    INFO_PROMPT_CONTEST_INFO,
    INFO_PROMPT_CONTEST_STAT,
    INFO_PROMPT_BERRY_INFO,
    INFO_PROMPT_BERRY_STAT,
    INFO_PROMPT_BERRY_TAG,
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
struct BagItemUseState {
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
    TaskFunc moveLearnContinue;
};
struct BagMailGiveState {
    u8 slot;
    u16 mailItem;
};
struct BagFusionState {
    u8 firstFusionSlot;
    u8 secondFusionSlot;
    u8 storageIndex;
    u8 fusionType;
    u16 fusionResult;
    u16 moveToLearn;
    u8 extraMoveHandling;
};
#endif // SWSH_ITEM_MENU_ACTION_IN_BAG

static void CB2_Bag(void);
static bool8 SetupBagMenu(void);
static void BagMenu_AllocObjPalettes(void);
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
static void ShowInfoPrompt(u8);
#if SWSH_ITEM_MENU_TMHM_CONTEST_INFO
static void UpdateMoveContestInfo(s32);
static void PrintContestDescription(s32);
#endif
static bool8 IsWallysBag(void);
static void Task_WallyTutorialBagMenu(u8);
static void Task_BagMenu_HandleInput(u8);
static enum Item BagList_GetItemId(u8 pocketId, u32 pos);
static struct ItemSlot BagList_GetSlot(u8 pocketId, u32 pos);
static void GetItemNameFromPocket(u8 *dest, enum Item itemId);
static void PrintItemDescription(int);
static void UpdateEmptyPocket(void);
static u8 FormatDescriptionByWidth(u8 *, s32, u8, const u8 *, s16);
static void BagMenu_PrintCursorAtPos(u8, u8);
static void BagMenu_Print(u8, u8, const u8 *, u8, u8, u8, u8, u8, u8);
static void Task_CloseBagMenu(u8);
static u8 AddItemMessageWindow(u8);
static void RemoveItemMessageWindow(u8);
static void ReturnToItemList(u8);
static u8 BagMenu_AddWindow(u8);
static u8 GetSwitchBagPocketDirection(void);
static void SwitchBagPocket(u8, s16, bool16);
static bool8 CanSwapItems(void);
static void StartItemSwap(u8 taskId);
static void Task_SwitchBagPocket(u8);
static void Task_HandleSwappingItemsInput(u8);
static void BagMenu_SetSwapListSelection(u8, u16, u16 *, u16 *);
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
static void CreateQuantityFrameSprites(u8 y);
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
#if SWSH_ITEM_MENU_CHECK_BERRY_TAG
static void ItemMenu_CheckTag(u8);
#endif
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
#if SWSH_ITEM_MENU_ACTION_IN_BAG
static void BagMenu_DrawPartySlots(void);
static void BagMenu_SetPartySlotPalette(u8 slot, u8 pal);
static void BagMenu_CreatePartyIcons(void);
static void BagMenu_FreePartyIcons(void);
static void BagMenu_UpdateTMHMPartyBlend(s32 itemIndex);
static void BagMenu_DisableTMHMPartyBlend(void);
static void BagMenu_UseSacredAsh(u8);
static void BagMenu_GetEVStatName(enum ItemEffectType effectType, u8 *dest);
static void BagMenu_UsePPOnMove(u8, u8);
static void BagMenu_UseItem(u8);
static void BagMenu_UseMedicine(u8);
static void BagMenu_UseResetEVs(u8);
static void BagMenu_UseDynamaxCandy(u8);
static void BagMenu_UseReduceEV(u8);
static void BagMenu_UseAbilityCapsule(u8);
static void BagMenu_UseAbilityPatch(u8);
static void BagMenu_UseMint(u8);
static void BagMenu_UseRareCandy(u8);
static void BagMenu_UseEvolutionStone(u8);
static void BagMenu_UseFormChange(u8);
static void Task_BagMenu_FormChangeAnim(u8);
static void BagMenu_SpriteCB_FormChangeIconMosaic(struct Sprite *);
static void Task_BagMenu_PartyInput(u8);
static s16  BagMenu_ComputeMultiUseMax(u8);
static void BagMenu_TryMultiUse(u8);
static void BagMenu_InitMultiUseInput(u8);
static void Task_BagMenu_MultiUseInput(u8);
static void BagMenu_ClosePartySelect(u8);
static void Task_BagMenu_PartyStayAfterMessage(u8);
static void Task_BagMenu_PartyAfterItemUse(u8);
static void Task_BagMenu_SacredAshMessages(u8);
static void BagMenu_ShowPPMoveSelectWindow(u8);
static void Task_BagMenu_PPMoveSelectInput(u8);
static void Task_BagMenu_AbilityChangeYesNo(u8);
static void BagMenu_AbilityChangeYes(u8);
static void BagMenu_AbilityChangeNo(u8);
static void Task_BagMenu_MintYesNo(u8);
static void BagMenu_MintYes(u8);
static void BagMenu_MintNo(u8);
static void Task_BagMenu_RareCandyWaitLvUpMsg(u8);
static void Task_BagMenu_RareCandyStatsPg1(u8);
static void Task_BagMenu_RareCandyStatsPg2(u8);
static void BagMenu_RareCandyDoLearnMoveStep(u8);
static void Task_BagMenu_MoveLearnFanfare(u8);
static void Task_BagMenu_MoveLearnFanfareWait(u8);
static void Task_BagMenu_RareCandyReplaceYesNo(u8);
static void BagMenu_RareCandyReplaceYes(u8);
static void BagMenu_RareCandyReplaceNo(u8);
static void Task_BagMenu_MoveLearnGoToSummary(u8);
static void Task_BagMenu_MoveLearnNotLearned(u8);
static void BagMenu_CB2_SummaryForMoveForget(void);
static void BagMenu_CB2_ReturnFromMoveForget(void);
static void Task_BagMenu_RareCandyReentry(u8);
static void Task_BagMenu_MoveLearnAfterForget(u8);
static void Task_BagMenu_MoveLearnAfterForgotMove(u8);
static void Task_BagMenu_MoveLearnDone(u8);
static void BagMenu_RareCandyTryEvolution(u8);
static void BagMenu_CB2_DoBeginEvolution(void);
static void BagMenu_CB2_AfterRareCandyEvolution(void);
static void BagMenu_RareCandyCleanupAndReturn(u8);
static void BagMenu_CB2_AfterEvoStoneEvolution(void);
static void BagMenu_DoGiveMail(u8, struct Pokemon *, u16);
static void BagMenu_GiveItem(u8);
static void Task_BagMenu_GiveSwapYesNo(u8);
static void BagMenu_GiveSwapYes(u8);
static void BagMenu_GiveSwapNo(u8);
static void Task_BagMenu_AfterGiveFormChange(u8);
static void BagMenu_CB2_GiveMail(void);
static void BagMenu_CB2_AfterMailWrite(void);
static bool32 BagMenu_HasMultichoiceFormChange(struct Pokemon *);
static void BagMenu_UseRotomCatalog(u8);
static void Task_BagMenu_RotomCatalogInput(u8);
static void BagMenu_UseZygardeCube(u8);
static void Task_BagMenu_ZygardeCubeInput(u8);
static void BagMenu_UseMultichoiceFormChange(u8);
static void Task_BagMenu_RotomAfterTransform(u8);
static void Task_BagMenu_RotomMoveReplaceYesNo(u8);
static void BagMenu_RotomMoveReplaceYes(u8);
static void BagMenu_RotomMoveReplaceNo(u8);
static void BagMenu_UseFusion(u8);
static void Task_BagMenu_FusionStayAfterMessage(u8);
static void Task_BagMenu_FusionAwaitSecond(u8);
static void BagMenu_UseFusionSecond(u8);
static void Task_BagMenu_FusionAnim(u8);
static void Task_BagMenu_FusionAfterAnim(u8);
static void Task_BagMenu_FusionMoveLearnDone(u8);
static void BagMenu_UseTMHM(u8);
static void Task_BagMenu_TMHMLearnDone(u8);
static void SpriteCB_HeldItemIcon_WaitDisappear(struct Sprite *);
static void BagMenu_LoadHeldItemIconGfx(enum Item);
static void BagMenu_UpdateHeldItemIcon(u8);
static void BagMenu_ApplyGiveBlend(void);
static void BagMenu_UpdateStatusIcons(void);
static void BagMenu_UpdateStatusIconPos(u8 hoveredSlot);
static void BagMenu_DrawPartyHPBar(s8 slot);
static void BagMenu_DrawPartyHPBarPixels(u8 slot, u8 filledWidth);
static void Task_BagMenu_HPBarAnim(u8 taskId);
static bool8 BagMenu_ShouldShowHPBar(void);
static bool8 BagMenu_ShouldLoadPartyPanel(void);
static bool8 BagMenu_InBattleSelect(void);
static u8 BagMenu_PartyIdFromSlot(u8);
static struct Pokemon *BagMenu_GetPanelMon(u8);
static bool8 BagMenu_SlotIsPartner(u8);
static u8 BagMenu_PanelSlotLimit(void);
static bool8 BagMenu_PanelSlotOccupied(u8);
static u8 BagMenu_StepSlot(u8, s8, u8);
static void BagMenu_CreatePanelMonIcon(u8, s16);
#if SWSH_ITEM_MENU_ACTION_IN_BATTLE
static void ShowMultiBattleSwapPrompt(bool8);
static void BagMenu_UseBattleItem(u8);
static void BagMenu_BattleApplyItem(u8, u8, bool8);
static void BagMenu_BattleUsePPOnMove(u8, u8);
static bool8 BagMenu_IsMultiFull(void);
static u8 BagMenu_FullMultiPartyId(u8);
static void BagMenu_StartMultiFullSwap(u8);
static void Task_BagMenu_MultiFullSwap(u8);
#endif
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
static const u8 sText_PartyBasePointsReset[] = _("{STR_VAR_1}'s base points\nwere all reset to zero!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PartyDynamaxLevelUp[]  = _("{STR_VAR_1}'s Dynamax Level\nincreased by 1!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PartyAbilityAsk[]      = _("Would you like to change {STR_VAR_1}'s\nability to {STR_VAR_2}?{PAUSE_UNTIL_PRESS}");
static const u8 sText_PartyAbilityDone[]     = _("{STR_VAR_1}'s ability became\n{STR_VAR_2}!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PartyMintAsk[]         = _("It might affect {STR_VAR_1}'s stats.\nAre you sure you want to use it?{PAUSE_UNTIL_PRESS}");
static const u8 sText_PartyMintDone[]        = _("{STR_VAR_1}'s stats may have changed due\nto the effects of the {STR_VAR_2}!{PAUSE_UNTIL_PRESS}");

static const struct YesNoFuncTable sPartyAbilityChangeYesNo    = {BagMenu_AbilityChangeYes, BagMenu_AbilityChangeNo};
static const struct YesNoFuncTable sPartyMintYesNo             = {BagMenu_MintYes, BagMenu_MintNo};
static const struct YesNoFuncTable sPartyRareCandyReplaceYesNo = {BagMenu_RareCandyReplaceYes, BagMenu_RareCandyReplaceNo};
static const struct YesNoFuncTable sPartyGiveSwapYesNo         = {BagMenu_GiveSwapYes, BagMenu_GiveSwapNo};
static const struct YesNoFuncTable sPartyRotomMoveReplaceYesNo = {BagMenu_RotomMoveReplaceYes, BagMenu_RotomMoveReplaceNo};
#endif // SWSH_ITEM_MENU_ACTION_IN_BAG

static const u8 sText_NumberItem_HM[]           = _("{CLEAR_TO 15}{STR_VAR_1}{CLEAR 3}{STR_VAR_2}");
static const u8 sText_Var1CantBeHeldHere[]      = _("The {STR_VAR_1} can't be held\nhere.");
static const u8 sText_DepositHowManyVar1[]      = _("Deposit how many\n{STR_VAR_1}?");
static const u8 sText_UseHowMany[]              = _("How many do you want to use?");
static const u8 sText_DepositedVar2Var1s[]      = _("Deposited {STR_VAR_2}\n{STR_VAR_1}.");
static const u8 sText_NoRoomForItems[]          = _("There's no room to\nstore items.");
static const u8 sText_CantStoreImportantItems[] = _("Important items can't be\nstored in the PC!");
static const u8 sText_Price[]                   = _("Price");
static const u8 sText_ConfirmTossItems[]        = _("Throw away {STR_VAR_2}\n{STR_VAR_1}?");

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
#if SWSH_ITEM_MENU_CHECK_BERRY_TAG
    [ACTION_CHECK_TAG]         = {COMPOUND_STRING("CHECK TAG"), {ItemMenu_CheckTag}},
#endif
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

#if SWSH_ITEM_MENU_PYRAMID_BAG
static const u8 sContextMenuItems_PyramidToss[] = {
    ACTION_TOSS,        ACTION_CANCEL
};
#endif

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
static const u8 sBagMenuHMIcon_Gfx[]            = INCGFX_U8("graphics/bag/swsh/hm.png", ".4bpp");
static const u16 sCursor_Pal[]                  = INCGFX_U16("graphics/bag/swsh/cursor.png", ".gbapal");
static const u32 sMoveTypeIcons_Gfx[]           = INCGFX_U32("graphics/bag/swsh/move_types.png", ".4bpp.smol");
static const u16 sMoveTypeIcons_Pal[]           = INCGFX_U16("graphics/bag/swsh/move_types.png", ".gbapal");
static const u8 sInfoPrompt_Tilemap[]           = INCBIN_U8("graphics/bag/swsh/info_prompt.bin");

#if SWSH_ITEM_MENU_BERRY_INFO
static const u32 sBerryFlavorMark_Gfx[]         = INCGFX_U32("graphics/bag/swsh/berry_flavor_mark.png", ".4bpp.smol");
#endif

#if SWSH_ITEM_MENU_ACTION_IN_BAG
static const u8 sPartySlots_Tilemap[]           = INCBIN_U8("graphics/bag/swsh/party_slots.bin");
static const u32 sStatusIcons_Gfx[]             = INCGFX_U32("graphics/bag/swsh/status_icons.png", ".4bpp.smol");
#if SWSH_ITEM_MENU_ACTION_IN_BATTLE
static const u32 sMultiBattleSwapPrompt_Gfx[]   = INCGFX_U32("graphics/bag/swsh/prompt_swap.png", ".4bpp.smol");
#endif
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

#if SWSH_ITEM_MENU_ACTION_IN_BAG && SWSH_ITEM_MENU_ACTION_IN_BATTLE
static const struct OamData sOamData_MultiSwapPrompt =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 2,
};

static const union AnimCmd sAnim_MultiSwapPrompt_0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};
static const union AnimCmd sAnim_MultiSwapPrompt_1[] =
{
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_MultiSwapPrompt[] =
{
    sAnim_MultiSwapPrompt_0,
    sAnim_MultiSwapPrompt_1,
};

static const struct CompressedSpriteSheet sSpriteSheet_MultiSwapPrompt =
{
    .data = sMultiBattleSwapPrompt_Gfx,
    .size = (32 * 16 * 2) / 2,
    .tag = TAG_SWAP_PROMPT,
};

static const struct SpriteTemplate sSpriteTemplate_MultiSwapPrompt =
{
    .tileTag = TAG_SWAP_PROMPT,
    .paletteTag = TAG_ITEM_CURSOR,
    .oam = &sOamData_MultiSwapPrompt,
    .anims = sAnims_MultiSwapPrompt,
};
#endif

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

#if SWSH_ITEM_MENU_ACTION_IN_BAG
static const struct OamData sOamData_HeldItemIcon =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 2,
};

static const union AffineAnimCmd sAffineAnim_HeldItemIcon_Appear[] =
{
    AFFINEANIMCMD_FRAME(176, 176, 0, 0),
    AFFINEANIMCMD_FRAME(5, 5, 0, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_HeldItemIcon_Disappear[] =
{
    AFFINEANIMCMD_FRAME(128, 128, 0, 0),
    AFFINEANIMCMD_FRAME(-5, -5, 0, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnims_HeldItemIcon[] =
{
    [0] = sAffineAnim_HeldItemIcon_Appear,
    [1] = sAffineAnim_HeldItemIcon_Disappear,
};

static const struct SpriteTemplate sSpriteTemplate_HeldItemIcon =
{
    .tileTag = TAG_PARTY_HELD_ITEM,
    .paletteTag = TAG_PARTY_HELD_ITEM,
    .oam = &sOamData_HeldItemIcon,
    .affineAnims = sAffineAnims_HeldItemIcon,
};

static const struct OamData sOamData_StatusIcon =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .size = SPRITE_SIZE(32x8),
    .priority = 2,
};

static const union AnimCmd sSpriteAnim_StatusPoison[]    = { ANIMCMD_FRAME(0,  0), ANIMCMD_END };
static const union AnimCmd sSpriteAnim_StatusParalyzed[] = { ANIMCMD_FRAME(4,  0), ANIMCMD_END };
static const union AnimCmd sSpriteAnim_StatusSleep[]     = { ANIMCMD_FRAME(8,  0), ANIMCMD_END };
static const union AnimCmd sSpriteAnim_StatusFrozen[]    = { ANIMCMD_FRAME(12, 0), ANIMCMD_END };
static const union AnimCmd sSpriteAnim_StatusBurn[]      = { ANIMCMD_FRAME(16, 0), ANIMCMD_END };
static const union AnimCmd sSpriteAnim_StatusPokerus[]   = { ANIMCMD_FRAME(20, 0), ANIMCMD_END };
static const union AnimCmd sSpriteAnim_StatusFaint[]     = { ANIMCMD_FRAME(24, 0), ANIMCMD_END };
static const union AnimCmd sSpriteAnim_StatusFrostbite[] = { ANIMCMD_FRAME(28, 0), ANIMCMD_END };

static const union AnimCmd *const sSpriteAnims_StatusIcon[] =
{
    sSpriteAnim_StatusPoison,
    sSpriteAnim_StatusParalyzed,
    sSpriteAnim_StatusSleep,
    sSpriteAnim_StatusFrozen,
    sSpriteAnim_StatusBurn,
    sSpriteAnim_StatusPokerus,
    sSpriteAnim_StatusFaint,
    sSpriteAnim_StatusFrostbite,
};

static const struct CompressedSpriteSheet sSpriteSheet_StatusIcon =
{
    .data = sStatusIcons_Gfx,
    .size = 0x400,
    .tag = TAG_STATUS_ICON,
};

static const struct SpriteTemplate sSpriteTemplate_StatusIcon =
{
    .tileTag = TAG_STATUS_ICON,
    .paletteTag = TAG_ITEM_CURSOR,
    .oam = &sOamData_StatusIcon,
    .anims = sSpriteAnims_StatusIcon,
};
#endif // SWSH_ITEM_MENU_ACTION_IN_BAG

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
static u32 sPartyItemIconAnimId;
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
#if SWSH_ITEM_MENU_ACTION_IN_BAG
static bool8 sPartyGiveMode;
static bool8 sPartyBlendActive;
static u16 sPartyGiveSwapItem;
static u8  sHeldItemIconSpriteId;
static u16 sHeldItemPalIndex;
static s8  sHeldItemCurSlot;
static u8  sStatusIconSpriteIds[PARTY_SIZE];
static s8  sPrevHPBarSlot;
static bool8 sHPBarWindowMapped;
static u8  sMultiFullPage; // 0 = player team, 1 = partner team (12v12 multi battle)
#if SWSH_ITEM_MENU_ACTION_IN_BATTLE
static u8  sMultiSwapPromptSpriteIds[2];
#endif
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
        .width = 7,
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
#if SWSH_ITEM_MENU_ACTION_IN_BAG
    [WIN_PARTY_HP_BAR] = {
        .bg          = 1,
        .tilemapLeft = 2,
        .tilemapTop  = 3,
        .width       = 4,
        .height      = 16,
        .paletteNum  = 2,
        .baseBlock   = 619,
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
        .width = 4,
        .height = 2,
        .paletteNum = 1,
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
        .tilemapLeft = 15,
        .tilemapTop = 11,
        .width = 14,
        .height = 8,
        .paletteNum = 5,
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
    [ITEMWIN_ROTOM_CATALOG] = {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 3,
        .width = 12,
        .height = 12,
        .paletteNum = 15,
        .baseBlock = 475,
    },
    [ITEMWIN_ZYGARDE_CUBE] = {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 11,
        .width = 12,
        .height = 4,
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
static EWRAM_DATA struct BagItemUseState *sBagItemUseState = NULL;
static EWRAM_DATA struct BagMailGiveState *sBagMailGiveState = NULL;
static EWRAM_DATA struct BagFusionState *sBagFusionState = NULL;
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
#if SWSH_ITEM_MENU_PYRAMID_BAG
        gBagPosition.isPyramid = FALSE;
#endif
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
#if SWSH_ITEM_MENU_ACTION_IN_BAG && SWSH_ITEM_MENU_ACTION_IN_BATTLE
        memset(sMultiSwapPromptSpriteIds, SPRITE_NONE, sizeof(sMultiSwapPromptSpriteIds));
#endif
        sScrollThumbSpriteId = SPRITE_NONE;
        memset(sPocketScrollArrowSpriteIds, SPRITE_NONE, sizeof(sPocketScrollArrowSpriteIds));
        memset(sFrameQuantityIds, SPRITE_NONE, sizeof(sFrameQuantityIds));
        sPocketScrollArrowAnimIds[0] = INVALID_COMFY_ANIM;
        sPocketScrollArrowAnimIds[1] = INVALID_COMFY_ANIM;
        sCursorAnimId = INVALID_COMFY_ANIM;
        sScrollThumbAnimId = INVALID_COMFY_ANIM;
        sPartyItemIconAnimId = INVALID_COMFY_ANIM;
        sHoveredItemIndex = LIST_CANCEL;
        memset(gBagMenu->windowIds, WINDOW_NONE, sizeof(gBagMenu->windowIds));
#if SWSH_ITEM_MENU_ACTION_IN_BAG
        sHeldItemIconSpriteId = SPRITE_NONE;
        sHeldItemCurSlot = -1;
        memset(sStatusIconSpriteIds, SPRITE_NONE, sizeof(sStatusIconSpriteIds));
        sPrevHPBarSlot = -1;
        sHPBarWindowMapped = FALSE;
        sMultiFullPage = 0;
#endif
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
    if(SWSH_ITEM_MENU_SCROLLING_BG)
    {
        ChangeBgX(3, 64, BG_COORD_ADD);
        ChangeBgY(3, 64, BG_COORD_ADD);
    }
}

#define tListTaskId             data[0]
#define tListPosition           data[1]
#define tQuantity               data[2]
#define tNeverRead              data[3]
#define tPartySlot              data[4]
#define tPartySavedIconY        data[5]
#define tPartyTemp              data[6]
#define tItemCount              data[8]
#define tMsgWindowId            data[10]
#define tPocketSwitchDir        data[11]
#define tPocketSwitchTimer      data[12]
#define tPocketSwitchState      data[13]
#define tMultiUseMax            data[14]

static void CB2_Bag(void)
{
    while (MenuHelpers_ShouldWaitForLinkRecv() != TRUE && SetupBagMenu() != TRUE && MenuHelpers_IsLinkActive() != TRUE)
        {};
}

#if SWSH_ITEM_MENU_ACTION_IN_BAG
#define PARTY_ITEM_ICON_X       16
#define PARTY_ITEM_ICON_Y(i)    (24 * (i) + 16)
enum {
    BAG_REENTRY_NONE,
    BAG_REENTRY_MOVE_FORGET,
    BAG_REENTRY_ITEM_USE,
};

enum {
    BAG_NOT_FUSION_MON,
    BAG_FUSE_MON,
    BAG_UNFUSE_MON,
    BAG_SECOND_FUSE_MON,
};

#define ROTOM_BASE_MOVE  MOVE_THUNDER_SHOCK
#define ROTOM_HEAT_MOVE  MOVE_OVERHEAT
#define ROTOM_WASH_MOVE  MOVE_HYDRO_PUMP
#define ROTOM_FROST_MOVE MOVE_BLIZZARD
#define ROTOM_FAN_MOVE   MOVE_AIR_SLASH
#define ROTOM_MOW_MOVE   MOVE_LEAF_STORM

static const u16 sBagRotomFormChangeMoves[] = {
    ROTOM_HEAT_MOVE,
    ROTOM_WASH_MOVE,
    ROTOM_FROST_MOVE,
    ROTOM_FAN_MOVE,
    ROTOM_MOW_MOVE,
};

extern void DeleteMove(struct Pokemon *mon, enum Move move);
extern bool32 DoesMonHaveAnyMoves(struct Pokemon *mon);
extern u8 IsFusionMon(enum Species species);
#endif // SWSH_ITEM_MENU_ACTION_IN_BAG

// Matching the enum in item_menu_icons.c to reserve palette slots.
#define TAG_BAG_ITEM_ICON_0  102
#define TAG_BAG_ITEM_ICON_1  103

static void BagMenu_AllocObjPalettes(void)
{
    AllocSpritePalette(TAG_ITEM_CURSOR);        // Pal 0
    AllocSpritePalette(TAG_BAG_ITEM_ICON_0);    // Pal 1
    AllocSpritePalette(TAG_BAG_ITEM_ICON_1);    // Pal 2
}

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
        BagMenu_AllocObjPalettes();
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
#if SWSH_ITEM_MENU_PYRAMID_BAG
        if (gBagPosition.isPyramid)
            PrintPocketName(COMPOUND_STRING("Pyramid"));
        else
#endif
            PrintPocketName(sPocketNamesStringsTable[gBagPosition.pocket]);
        gMain.state++;
        break;
    case 14:
        taskId = CreateBagInputHandlerTask(gBagPosition.location);
        gTasks[taskId].tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, gBagPosition.scrollPosition[gBagPosition.pocket], gBagPosition.cursorPosition[gBagPosition.pocket]);
        gTasks[taskId].tNeverRead = 0;
        gTasks[taskId].tItemCount = 0;
#if SWSH_ITEM_MENU_ACTION_IN_BAG
        if (sBagItemUseState != NULL && sBagItemUseState->reentryPhase != BAG_REENTRY_NONE)
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
        if (sBagItemUseState != NULL && sBagItemUseState->reentryPhase != BAG_REENTRY_NONE)
        {
            u8 iconSpriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + (gBagMenu->itemIconSlot ^ 1)];
            if (iconSpriteId != SPRITE_NONE)
            {
                gSprites[iconSpriteId].x2 = PARTY_ITEM_ICON_X;
                gSprites[iconSpriteId].y2 = PARTY_ITEM_ICON_Y(sBagItemUseState->slot);
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
#if SWSH_ITEM_MENU_ACTION_IN_BAG
        sPartyBlendActive = FALSE;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        if (gBagPosition.pocket == POCKET_TM_HM
         && gBagMenu->numItemStacks[gBagPosition.pocket] != (u8)(!gBagMenu->hideCloseBagText))
            BagMenu_UpdateTMHMPartyBlend(gBagPosition.cursorPosition[gBagPosition.pocket]);
#endif
#if SWSH_ITEM_MENU_BERRY_INFO
        sBerryInfoMode = 0;
        memset(sBerryFlavorMarkSpriteIds, SPRITE_NONE, sizeof(sBerryFlavorMarkSpriteIds));
#endif
        if (gBagMenu->numItemStacks[gBagPosition.pocket] != (u8)(!gBagMenu->hideCloseBagText))
        {
            if (gBagPosition.pocket == POCKET_TM_HM)
            {
                ShowInfoPrompt(INFO_PROMPT_BATTLE_STAT);
            }
#if SWSH_ITEM_MENU_BERRY_INFO
            else if (gBagPosition.pocket == POCKET_BERRIES)
            {
                ShowInfoPrompt(INFO_PROMPT_BERRY_STAT);
            }
#endif
        }
        if (gBagPosition.location == ITEMMENULOCATION_SHOP)
        {
            SetupSellWindows();
            UpdateSellPrice(BagList_GetItemId(gBagPosition.pocket,
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
#if SWSH_ITEM_MENU_ACTION_IN_BAG
        if (BagMenu_ShouldLoadPartyPanel())
        {
            BagMenu_DrawPartySlots();
#if SWSH_ITEM_MENU_ACTION_IN_BATTLE
            if (BagMenu_IsMultiFull())
            {
                LoadCompressedSpriteSheet(&sSpriteSheet_MultiSwapPrompt);
                ShowMultiBattleSwapPrompt(TRUE);
            }
#endif
        }
#endif
        gBagMenu->graphicsLoadState++;
        break;
    case 3:
#if SWSH_ITEM_MENU_ACTION_IN_BAG
        if (BagMenu_ShouldLoadPartyPanel())
            BagMenu_CreatePartyIcons();
#endif
        gBagMenu->graphicsLoadState++;
        break;
    case 4:
        LoadPalette(sBagScreen_Pal, BG_PLTT_ID(0), 6 * PLTT_SIZE_4BPP);
        gBagMenu->graphicsLoadState++;
        break;
    case 5:
        LoadCompressedSpriteSheet(&sSpriteSheet_Cursor);
        gBagMenu->graphicsLoadState++;
        break;
    case 6:
        LoadPalette(sCursor_Pal, OBJ_PLTT_ID(0), PLTT_SIZE_4BPP);
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

#if SWSH_ITEM_MENU_PYRAMID_BAG

static enum Item BagList_GetItemId(u8 pocketId, u32 pos)
{
    if (gBagPosition.isPyramid)
        return gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode][pos];
    return GetBagItemId(pocketId, pos);
}

static struct ItemSlot BagList_GetSlot(u8 pocketId, u32 pos)
{
    if (gBagPosition.isPyramid)
    {
        return (struct ItemSlot){
            .itemId = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode][pos],
            .quantity = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode][pos],
        };
    }
    return GetBagItemIdAndQuantity(pocketId, pos);
}

static void BagList_CompactPyramid(void)
{
    u16 *itemIds = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];
#if MAX_PYRAMID_BAG_ITEM_CAPACITY > 255
    u16 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];
#else
    u8 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];
#endif
    u8 i, j;

    for (i = 0; i < PYRAMID_BAG_ITEMS_COUNT; i++)
    {
        if (itemIds[i] == ITEM_NONE || quantities[i] == 0)
        {
            itemIds[i] = ITEM_NONE;
            quantities[i] = 0;
        }
    }
    for (i = 0; i < PYRAMID_BAG_ITEMS_COUNT - 1; i++)
    {
        for (j = i + 1; j < PYRAMID_BAG_ITEMS_COUNT; j++)
        {
            if (itemIds[i] == ITEM_NONE || quantities[i] == 0)
            {
                u16 tmpId = itemIds[i];
                itemIds[i] = itemIds[j];
                itemIds[j] = tmpId;
                {
                    u16 tmpQ = quantities[i];
                    quantities[i] = quantities[j];
                    quantities[j] = tmpQ;
                }
            }
        }
    }
}

static struct ItemSlot sPyramidScratch[PYRAMID_BAG_ITEMS_COUNT];
static struct BagPocket sPyramidScratchPocket;

static struct BagPocket *BagList_PyramidScratchPocket(void)
{
    u16 *ids = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];
#if MAX_PYRAMID_BAG_ITEM_CAPACITY > 255
    u16 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];
#else
    u8 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];
#endif
    u32 i;

    for (i = 0; i < PYRAMID_BAG_ITEMS_COUNT; i++)
    {
        sPyramidScratch[i].itemId = ids[i];
        sPyramidScratch[i].quantity = quantities[i];
    }
    sPyramidScratchPocket.itemSlots = sPyramidScratch;
    sPyramidScratchPocket.capacity = PYRAMID_BAG_ITEMS_COUNT;
    sPyramidScratchPocket.id = POCKET_DUMMY;
    return &sPyramidScratchPocket;
}

static void BagList_PyramidScratchWriteBack(void)
{
    u16 *ids = gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode];
#if MAX_PYRAMID_BAG_ITEM_CAPACITY > 255
    u16 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];
#else
    u8 *quantities = gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode];
#endif
    u32 i;

    for (i = 0; i < PYRAMID_BAG_ITEMS_COUNT; i++)
    {
        ids[i] = sPyramidScratch[i].itemId;
        quantities[i] = sPyramidScratch[i].quantity;
    }
}

static void BagList_SortPyramid(enum BagSortOptions type)
{
    SortItemsInBag(BagList_PyramidScratchPocket(), type);
    BagList_PyramidScratchWriteBack();
}

static void BagList_MovePyramidSlot(u32 from, u32 to)
{
    struct BagPocket *pocket = BagList_PyramidScratchPocket();

    if (from != to)
    {
        s8 shift = (to > from) ? 1 : -1;
        struct ItemSlot fromSlot;
        u32 i;

        if (to > from)
            to--;
        fromSlot = BagPocket_GetSlotData(pocket, from);
        for (i = from; i != to; i += shift)
            BagPocket_SetSlotData(pocket, i, BagPocket_GetSlotData(pocket, i + shift));
        BagPocket_SetSlotData(pocket, to, fromSlot);
    }
    BagList_PyramidScratchWriteBack();
}

static void BagList_MoveSlot(u8 pocketId, u32 from, u32 to)
{
    if (gBagPosition.isPyramid)
        BagList_MovePyramidSlot(from, to);
    else
        MoveItemSlotInPocket(pocketId, from, to);
}
#else
static enum Item BagList_GetItemId(u8 pocketId, u32 pos)
{
    return GetBagItemId(pocketId, pos);
}

static struct ItemSlot BagList_GetSlot(u8 pocketId, u32 pos)
{
    return GetBagItemIdAndQuantity(pocketId, pos);
}

static void BagList_MoveSlot(u8 pocketId, u32 from, u32 to)
{
    MoveItemSlotInPocket(pocketId, from, to);
}
#endif

static void LoadBagItemListBuffers(u8 pocketId)
{
    u16 i;
    struct ListMenuItem *subBuffer;

    if (!gBagMenu->hideCloseBagText)
    {
        for (i = 0; i < gBagMenu->numItemStacks[pocketId] - 1; i++)
        {
            GetItemNameFromPocket(sListBuffer2->name[i], BagList_GetItemId(pocketId, i));
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
            GetItemNameFromPocket(sListBuffer2->name[i], BagList_GetItemId(pocketId, i));
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
            StringExpandPlaceholders(dest, sText_NumberItem_HM);
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

static void RefreshItemListRow(struct ListMenu *list, u8 row)
{
    u8 rowHeight = GetFontAttribute(FONT_NARROW, FONTATTR_MAX_LETTER_HEIGHT) + list->template.itemVerticalPadding;
    u8 windowWidth = sDefaultBagWindows[WIN_ITEM_LIST].width * 8;
    s32 absIndex = (s32)(list->scrollOffset + row);
    u8 rowY;

    if (absIndex >= (s32)gBagMenu->numItemStacks[gBagPosition.pocket])
        return;

    rowY = list->template.upText_Y + row * rowHeight;
    FillWindowPixelRect(WIN_ITEM_LIST, PIXEL_FILL(0), 0, rowY, windowWidth, rowHeight);
    BagMenu_ItemPrintCallback(WIN_ITEM_LIST, (u32)absIndex, rowY);
    BagMenu_Print(WIN_ITEM_LIST, FONT_NARROW, gMultiuseListMenuTemplate.items[absIndex].name,
                  sItemListMenu.item_X, rowY, 0, 0, TEXT_SKIP_DRAW,
                  absIndex == sHoveredItemIndex ? COLORID_HOVER_NAME : COLORID_NORMAL);
}

static void RefreshItemListColors(struct ListMenu *list)
{
    u8 row;
    for (row = 0; row < list->template.maxShowed; row++)
    {
        if ((s32)(list->scrollOffset + row) >= (s32)gBagMenu->numItemStacks[gBagPosition.pocket])
            break;
        RefreshItemListRow(list, row);
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

#if SWSH_ITEM_MENU_PYRAMID_BAG
    if (gBagPosition.isPyramid && itemIndex != LIST_CANCEL)
    {
        gPyramidBagMenuState.scrollPosition = 0;
        gPyramidBagMenuState.cursorPosition = itemIndex;
    }
#endif

    {
        s32 oldHovered = sHoveredItemIndex;
        sHoveredItemIndex = itemIndex;
        if (!onInit
         && oldHovered >= 0 && itemIndex >= 0
         && (oldHovered - itemIndex == 1 || itemIndex - oldHovered == 1)
         && gBagMenu->toSwapPos == NOT_SWAPPING)
        {
            s32 oldRow = oldHovered - (s32)list->scrollOffset;
            if (oldRow >= 0 && oldRow < list->template.maxShowed)
                RefreshItemListRow(list, oldRow);
            RefreshItemListRow(list, list->selectedRow);
        }
        else
        {
            RefreshItemListColors(list);
        }
    }
#if SWSH_ITEM_MENU_ACTION_IN_BAG
    if (gBagPosition.pocket == POCKET_TM_HM)
        BagMenu_UpdateTMHMPartyBlend(itemIndex);
#endif

    if (onInit != TRUE)
        PlaySE(SE_SELECT);

    if (!onInit || gBagMenu->numItemStacks[gBagPosition.pocket] != (u8)(!gBagMenu->hideCloseBagText))
    {
        u8 iconSlot = gBagMenu->itemIconSlot;
        u8 iconSpriteId;
        RemoveBagItemIconSprite(iconSlot ^ 1);
        if (itemIndex != LIST_CANCEL)
            AddBagItemIconSprite(BagList_GetItemId(gBagPosition.pocket, itemIndex), iconSlot);
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
            ? BagList_GetItemId(gBagPosition.pocket, itemIndex) : ITEM_NONE;
        UpdateSellPrice(itemId);
    }
}

static void BagMenu_ItemPrintCallback(u8 windowId, u32 itemIndex, u8 y)
{
    if (itemIndex != LIST_CANCEL)
    {
        s32 offset;

        struct ItemSlot itemSlot = BagList_GetSlot(gBagPosition.pocket, itemIndex);

        // Draw HM icon
        if (gBagPosition.pocket == POCKET_TM_HM && GetItemTMHMIndex(itemSlot.itemId) > NUM_TECHNICAL_MACHINES)
            BlitBitmapToWindow(windowId, sBagMenuHMIcon_Gfx, 8, y, 16, 16);

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
        str = GetItemDescription(BagList_GetItemId(gBagPosition.pocket, itemIndex));
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

static void UpdateEmptyPocket(void)
{
    bool8 pocketEmpty = gBagMenu->numItemStacks[gBagPosition.pocket] == (u8)(!gBagMenu->hideCloseBagText);
    u8 i;

    if (sCursorSpriteId != SPRITE_NONE)
        gSprites[sCursorSpriteId].invisible = pocketEmpty;
    for (i = 0; i < HOVER_SLOT_SPRITES_COUNT; i++)
    {
        if (sHoverSlotSpriteIds[i] != SPRITE_NONE)
            gSprites[sHoverSlotSpriteIds[i]].invisible = pocketEmpty;
    }

    if (pocketEmpty)
    {
        for (i = 0; i < 2; i++)
        {
            u8 iconSpriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + i];
            if (iconSpriteId != SPRITE_NONE)
                gSprites[iconSpriteId].invisible = TRUE;
        }
        FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
        CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_GFX);

        if (gBagPosition.pocket == POCKET_TM_HM
#if SWSH_ITEM_MENU_BERRY_INFO
         || gBagPosition.pocket == POCKET_BERRIES
#endif
            )
        {
            FillBgTilemapBufferRect_Palette0(2, 4, 27, 16, 3, 4);
            ScheduleBgCopyTilemapToVram(2);
        }
    }
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

#if SWSH_ITEM_MENU_PYRAMID_BAG
    if (gBagPosition.isPyramid)
        return; // no pocket-switch arrows in pyramid bag
#endif

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
#if SWSH_ITEM_MENU_ACTION_IN_BAG
    if (gBagPosition.location == ITEMMENULOCATION_FIELD
        || gBagPosition.location == ITEMMENULOCATION_BATTLE
        || gBagPosition.location == ITEMMENULOCATION_PARTY
        || gBagPosition.location == ITEMMENULOCATION_WALLY)
        BagMenu_FreePartyIcons();
#endif
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
        if (sPartyItemIconAnimId != INVALID_COMFY_ANIM)
        {
            ReleaseComfyAnim(sPartyItemIconAnimId);
            sPartyItemIconAnimId = INVALID_COMFY_ANIM;
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

#if SWSH_ITEM_MENU_PYRAMID_BAG
    if (gBagPosition.isPyramid)
    {
        BagList_CompactPyramid();
        gBagMenu->numItemStacks[pocketId] = 0;
        for (u32 i = 0; i < PYRAMID_BAG_ITEMS_COUNT && BagList_GetItemId(pocketId, i); i++)
            gBagMenu->numItemStacks[pocketId]++;

        if (!gBagMenu->hideCloseBagText)
            gBagMenu->numItemStacks[pocketId]++;

        if (gBagMenu->numItemStacks[pocketId] > MAX_ITEMS_SHOWN)
            gBagMenu->numShownItems[pocketId] = MAX_ITEMS_SHOWN;
        else
            gBagMenu->numShownItems[pocketId] = gBagMenu->numItemStacks[pocketId];
        return;
    }
#endif

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
    UpdateEmptyPocket();
    ScheduleBgCopyTilemapToVram(1);
    ReturnToItemList(taskId);
}

static void AddItemQuantityWindow(void)
{
    CreateQuantityFrameSprites(144);
    PrintQuantity(BagMenu_AddWindowNoFrame(ITEMWIN_QUANTITY), 1);
}

static bool8 BagMenu_TryWraparoundScroll(u8 listTaskId, u16 *scrollPos, u16 *cursorPos)
{
    struct ListMenu *list = (void *) gTasks[listTaskId].data;
    u16 total = list->template.totalItems;

    if (total < 2)
        return FALSE;

    if (JOY_NEW(DPAD_UP) && list->scrollOffset == 0 && list->selectedRow == 0)
    {
        u16 maxShowed = list->template.maxShowed;

        if (total > maxShowed)
        {
            list->scrollOffset = total - maxShowed;
            list->selectedRow = maxShowed - 1;
        }
        else
        {
            list->scrollOffset = 0;
            list->selectedRow = total - 1;
        }
    }
    else if (JOY_NEW(DPAD_DOWN) && list->scrollOffset + list->selectedRow == total - 1)
    {
        list->scrollOffset = 0;
        list->selectedRow = 0;
    }
    else
    {
        return FALSE;
    }

    *scrollPos = list->scrollOffset;
    *cursorPos = list->selectedRow;
    PlaySE(SE_SELECT);
    RedrawListMenu(listTaskId);
    return TRUE;
}

static void Task_BagMenu_HandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *scrollPos = &gBagPosition.scrollPosition[gBagPosition.pocket];
    u16 *cursorPos = &gBagPosition.cursorPosition[gBagPosition.pocket];
    s32 listPosition;

    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE && !gPaletteFade.active)
    {
#if SWSH_ITEM_MENU_ACTION_IN_BATTLE
        if (BagMenu_IsMultiFull() && GetLRKeysPressed())
        {
            BagMenu_StartMultiFullSwap(taskId);
            return;
        }
#endif
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
                if ((gBagMenu->numItemStacks[gBagPosition.pocket] - (gBagMenu->hideCloseBagText ? 0 : 1)) <= 1)
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
                    tempItem = BagList_GetSlot(gBagPosition.pocket, data[1]);
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

        if (BagMenu_TryWraparoundScroll(tListTaskId, scrollPos, cursorPos))
            return;
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
                if (gBagMenu->numItemStacks[gBagPosition.pocket] == (u8)(!gBagMenu->hideCloseBagText))
                {
                    PlaySE(SE_FAILURE);
                    break;
                }
                struct ItemSlot itemSlot = BagList_GetSlot(gBagPosition.pocket, listPosition);
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
#if SWSH_ITEM_MENU_ACTION_IN_BAG
        if (gBagPosition.pocket == POCKET_TM_HM)
            BagMenu_DisableTMHMPartyBlend();
#endif
        ChangeBagPocketId(&gBagPosition.pocket, tPocketSwitchDir);
        LoadBagItemListBuffers(gBagPosition.pocket);
        tListTaskId = ListMenuInit(&gMultiuseListMenuTemplate, gBagPosition.scrollPosition[gBagPosition.pocket], gBagPosition.cursorPosition[gBagPosition.pocket]);
        UpdateEmptyPocket();
        PutWindowTilemap(WIN_DESCRIPTION);
        PutWindowTilemap(WIN_POCKET_NAME);
        ScheduleBgCopyTilemapToVram(1);
        if (gBagMenu->numItemStacks[gBagPosition.pocket] != (u8)(!gBagMenu->hideCloseBagText))
        {
            if (gBagPosition.pocket == POCKET_TM_HM)
            {
                ShowInfoPrompt(INFO_PROMPT_BATTLE_STAT);
            }
#if SWSH_ITEM_MENU_BERRY_INFO
            else if (gBagPosition.pocket == POCKET_BERRIES)
            {
                ShowInfoPrompt(INFO_PROMPT_BERRY_STAT);
            }
#endif
        }
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

static void BagMenu_SetSwapListSelection(u8 listTaskId, u16 absPos, u16 *scrollPos, u16 *cursorPos)
{
    struct ListMenu *list = (void *) gTasks[listTaskId].data;
    u16 total = gBagMenu->numItemStacks[gBagPosition.pocket];
    u16 maxShowed = gBagMenu->numShownItems[gBagPosition.pocket];

    if (total > maxShowed && absPos > total - maxShowed)
        list->scrollOffset = total - maxShowed;
    else
        list->scrollOffset = 0;

    list->selectedRow = absPos - list->scrollOffset;
    *scrollPos = list->scrollOffset;
    *cursorPos = list->selectedRow;
    RedrawListMenu(listTaskId);
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
            BagList_MoveSlot(pocket, tListPosition, tListPosition + 2);
            tListPosition++;
            gBagMenu->toSwapPos = tListPosition;
            LoadBagItemListBuffers(pocket);
            ListMenu_ProcessInput(tListTaskId);
            ListMenuGetScrollAndRow(tListTaskId, scrollPos, cursorPos);
        }
        else if (JOY_NEW(DPAD_DOWN) && tListPosition == lastRealPos && lastRealPos > 0)
        {
            BagList_MoveSlot(pocket, tListPosition, 0);
            tListPosition = 0;
            gBagMenu->toSwapPos = tListPosition;
            LoadBagItemListBuffers(pocket);
            BagMenu_SetSwapListSelection(tListTaskId, 0, scrollPos, cursorPos);
        }
        else if (JOY_REPEAT(DPAD_UP) && tListPosition > 0)
        {
            BagList_MoveSlot(pocket, tListPosition, tListPosition - 1);
            tListPosition--;
            gBagMenu->toSwapPos = tListPosition;
            LoadBagItemListBuffers(pocket);
            ListMenu_ProcessInput(tListTaskId);
            ListMenuGetScrollAndRow(tListTaskId, scrollPos, cursorPos);
        }
        else if (JOY_NEW(DPAD_UP) && tListPosition == 0 && lastRealPos > 0)
        {
            BagList_MoveSlot(pocket, tListPosition, lastRealPos + 1);
            tListPosition = lastRealPos;
            gBagMenu->toSwapPos = tListPosition;
            LoadBagItemListBuffers(pocket);
            BagMenu_SetSwapListSelection(tListTaskId, lastRealPos, scrollPos, cursorPos);
        }
    }
}

static void OpenContextMenu(u8 taskId)
{
#if SWSH_ITEM_MENU_PYRAMID_BAG
    if (gBagPosition.isPyramid && gPyramidBagMenuState.location == PYRAMIDBAG_LOC_CHOOSE_TOSS)
    {
        gBagMenu->contextMenuItemsPtr = sContextMenuItems_PyramidToss;
        gBagMenu->contextMenuNumItems = ARRAY_COUNT(sContextMenuItems_PyramidToss);
    }
    else
#endif
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
        WrapFontIdToFit(gStringVar1, end, FONT_SHORT_NARROW, WindowWidthPx(WIN_DESCRIPTION) - 10 - 6);
        StringExpandPlaceholders(gStringVar4, gText_TossHowManyVar1s);
        FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
        BagMenu_Print(WIN_DESCRIPTION, FONT_SHORT_NARROW, gStringVar4, 3, 1, 0, 1, 0, COLORID_NORMAL);
        AddItemQuantityWindow();
        gTasks[taskId].func = Task_ChooseHowManyToToss;
    }
}

static void AskTossItems(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u8 *end = CopyItemNameHandlePlural(gSpecialVar_ItemId, gStringVar1, tItemCount);
    WrapFontIdToFit(gStringVar1, end, FONT_SHORT_NARROW, WindowWidthPx(WIN_DESCRIPTION) - 10 - 6);
    ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS);
    StringExpandPlaceholders(gStringVar4, sText_ConfirmTossItems);
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    BagMenu_Print(WIN_DESCRIPTION, FONT_SHORT_NARROW, gStringVar4, 3, 1, 0, 1, 0, COLORID_NORMAL);
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
        PrintQuantity(gBagMenu->windowIds[ITEMWIN_QUANTITY], tItemCount);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        DestroyQuantityFrameSprites();
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY);
        AskTossItems(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        DestroyQuantityFrameSprites();
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY);
        CancelToss(taskId);
    }
}

static void ConfirmToss(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u8 *end = CopyItemNameHandlePlural(gSpecialVar_ItemId, gStringVar1, tItemCount);
    WrapFontIdToFit(gStringVar1, end, FONT_SHORT_NARROW, WindowWidthPx(WIN_DESCRIPTION) - 10 - 6);
    ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_ThrewAwayVar2Var1s);
    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
    BagMenu_Print(WIN_DESCRIPTION, FONT_SHORT_NARROW, gStringVar4, 3, 1, 0, 1, 0, COLORID_NORMAL);
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
        UpdateEmptyPocket();
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
        UpdateEmptyPocket();
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
#if SWSH_ITEM_MENU_PYRAMID_BAG && !SWSH_ITEM_MENU_PYRAMID_ACTION
            if (gBagPosition.isPyramid)
            {
                gBagMenu->newScreenCallback = CB2_ChooseMonToGiveItem;
                Task_FadeAndCloseBagMenu(taskId);
            }
            else
#endif
            {
                sPartyGiveMode = TRUE;
                BagMenu_OpenPartySelect(taskId);
            }
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

#if SWSH_ITEM_MENU_CHECK_BERRY_TAG
static void ItemMenu_CheckTag(u8 taskId)
{
    gBagMenu->newScreenCallback = DoBerryTagScreen;
    Task_FadeAndCloseBagMenu(taskId);
}
#endif

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

    CreateQuantityFrameSprites(96);
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
        WrapFontIdToFit(gStringVar1, end, FONT_SHORT_NARROW, WindowWidthPx(WIN_DESCRIPTION) - 10 - 6);
        StringExpandPlaceholders(gStringVar4, sText_DepositHowManyVar1);
        FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(0));
        BagMenu_Print(WIN_DESCRIPTION, FONT_SHORT_NARROW, gStringVar4, 3, 1, 0, 1, 0, COLORID_NORMAL);
        AddItemQuantityWindow();
        gTasks[taskId].func = Task_ChooseHowManyToDeposit;
    }
}

static void Task_ChooseHowManyToDeposit(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, tQuantity) == TRUE)
    {
        PrintQuantity(gBagMenu->windowIds[ITEMWIN_QUANTITY], tItemCount);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        DestroyQuantityFrameSprites();
        BagMenu_RemoveWindow(ITEMWIN_QUANTITY);
        TryDepositItem(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        PrintItemDescription(tListPosition);
        BagMenu_PrintCursor(tListTaskId, COLORID_NONE);
        DestroyQuantityFrameSprites();
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
        BagMenu_Print(WIN_DESCRIPTION, FONT_SHORT_NARROW, sText_CantStoreImportantItems, 3, 1, 0, 1, 0, COLORID_NORMAL);
        gTasks[taskId].func = WaitDepositErrorMessage;
    }
    else if (AddPCItem(gSpecialVar_ItemId, tItemCount) == TRUE)
    {
        // Successfully deposited
        u8 *end = CopyItemNameHandlePlural(gSpecialVar_ItemId, gStringVar1, tItemCount);
        WrapFontIdToFit(gStringVar1, end, FONT_SHORT_NARROW, WindowWidthPx(WIN_DESCRIPTION) - 10 - 6);
        ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS);
        StringExpandPlaceholders(gStringVar4, sText_DepositedVar2Var1s);
        BagMenu_Print(WIN_DESCRIPTION, FONT_SHORT_NARROW, gStringVar4, 3, 1, 0, 1, 0, COLORID_NORMAL);
        gTasks[taskId].func = Task_RemoveItemFromBag;
    }
    else
    {
        // No room to deposit
        BagMenu_Print(WIN_DESCRIPTION, FONT_SHORT_NARROW, sText_NoRoomForItems, 3, 1, 0, 1, 0, COLORID_NORMAL);
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
#if SWSH_ITEM_MENU_ACTION_IN_BAG
    FillWindowPixelBuffer(WIN_PARTY_HP_BAR, PIXEL_FILL(0));
#endif
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

static void CreateQuantityFrameSprites(u8 y)
{
    u8 i;
    for (i = 0; i < FRAME_QUANTITY_SPRITES_COUNT; i++)
    {
        sFrameQuantityIds[i] = CreateSprite(&sSpriteTemplate_FramePriceQuantity, 192 + i * 32, y, 3);
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

static void ShowInfoPrompt(u8 index)
{
    u8 i;
    u16 *buf = (u16 *)gBagMenu->mainTilemapBuffer;
    const u8 *tilemap = sInfoPrompt_Tilemap + index * 12;
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

    move = ItemIdToBattleMoveId(BagList_GetItemId(gBagPosition.pocket, itemIndex));

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
        enum Move move = ItemIdToBattleMoveId(BagList_GetItemId(gBagPosition.pocket, itemIndex));
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
        ShowInfoPrompt(INFO_PROMPT_CONTEST_INFO);
#else
        ShowInfoPrompt(INFO_PROMPT_BATTLE_INFO);
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
        ShowInfoPrompt(INFO_PROMPT_CONTEST_STAT);
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
        ShowInfoPrompt(INFO_PROMPT_BATTLE_INFO);
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
        ShowInfoPrompt(INFO_PROMPT_BATTLE_STAT);
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

    move = ItemIdToBattleMoveId(BagList_GetItemId(gBagPosition.pocket, itemIndex));

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

#if SWSH_ITEM_MENU_PYRAMID_BAG
    if (gBagPosition.isPyramid)
        BagList_SortPyramid(tSortType);
    else
#endif
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
        const struct BerryInfo *berryInfo = GetBerryInfo(ItemIdToBerryType(BagList_GetItemId(gBagPosition.pocket, itemIndex)));

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
            BagMenu_Print(WIN_BERRY_INFO, FONT_SHORT_NARROW, gStringVar4, GetStringCenterAlignXOffset(FONT_SHORT_NARROW, gStringVar4, 56), 2, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);
        }

        if (berryInfo->firmness != BERRY_FIRMNESS_UNKNOWN)
            BagMenu_Print(WIN_BERRY_INFO, FONT_SHORT_NARROW, sBerryFirmnessStrings[berryInfo->firmness], GetStringCenterAlignXOffset(FONT_SHORT_NARROW, sBerryFirmnessStrings[berryInfo->firmness], 56), 16, 0, 0, TEXT_SKIP_DRAW, COLORID_NORMAL);

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
        const struct BerryInfo *berryInfo = GetBerryInfo(ItemIdToBerryType(BagList_GetItemId(gBagPosition.pocket, itemIndex)));
        AddTextPrinterParameterized4(WIN_DESCRIPTION, FONT_SMALL_NARROWER, 3,  2, 0, 1, sFontColorTable[COLORID_NORMAL], 0, berryInfo->description1);
        AddTextPrinterParameterized4(WIN_DESCRIPTION, FONT_SMALL_NARROWER, 3, 15, 0, 1, sFontColorTable[COLORID_NORMAL], 0, berryInfo->description2);
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
        ShowInfoPrompt(INFO_PROMPT_BERRY_TAG);
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
        ShowInfoPrompt(INFO_PROMPT_BERRY_INFO);
        ScheduleBgCopyTilemapToVram(1);
    }
    else
    {
        sBerryInfoMode = 0;

        ClearWindowTilemap(WIN_DESCRIPTION);
        PrintItemDescription(itemIndex);
        PutWindowTilemap(WIN_DESCRIPTION);
        ShowInfoPrompt(INFO_PROMPT_BERRY_STAT);
        ScheduleBgCopyTilemapToVram(1);
    }
}

#endif // SWSH_ITEM_MENU_BERRY_INFO

#if SWSH_ITEM_MENU_ACTION_IN_BAG

// ============================================================
// Party Panel
// ============================================================

#define PARTY_PANEL_START_COL   1
#define PARTY_PANEL_START_ROW   1
#define PARTY_PANEL_SLOT_WIDTH  6
#define PARTY_PANEL_SLOT_HEIGHT 3
#define PARTY_HP_BAR_Y_OFFSET   4   // pixel offset of the HP bar

static bool8 BagMenu_ShouldLoadPartyPanel(void)
{
    switch (gBagPosition.location)
    {
    case ITEMMENULOCATION_FIELD:
    case ITEMMENULOCATION_PARTY:
        return TRUE;
#if SWSH_ITEM_MENU_ACTION_IN_BATTLE
    case ITEMMENULOCATION_BATTLE:
    case ITEMMENULOCATION_WALLY:
        return TRUE;
#endif
    default:
        return FALSE;
    }
}

static void BagMenu_DrawPartySlots(void)
{
    u16 *buf = (u16 *)gBagMenu->mainTilemapBuffer;
    u8 limit = IsWallysBag() ? 1 : BagMenu_PanelSlotLimit();
    u8 slot, row, col;

    for (slot = 0; slot < limit; slot++)
    {
        if (!BagMenu_PanelSlotOccupied(slot))
            continue;
        u16 palBits = BagMenu_SlotIsPartner(slot) ? (3 << 12) : 0;
        for (row = 0; row < PARTY_PANEL_SLOT_HEIGHT; row++)
        {
            u8 panelRow = PARTY_PANEL_START_ROW + slot * PARTY_PANEL_SLOT_HEIGHT + row;
            u8 binRow = slot * PARTY_PANEL_SLOT_HEIGHT + row;
            for (col = 0; col < PARTY_PANEL_SLOT_WIDTH; col++)
                buf[panelRow * 32 + (PARTY_PANEL_START_COL + col)]
                    = (sPartySlots_Tilemap[binRow * PARTY_PANEL_SLOT_WIDTH + col] & 0x0FFF) | palBits;
        }
    }
}

static void BagMenu_SetPartySlotPalette(u8 slot, u8 pal)
{
    u16 *buf = (u16 *)gBagMenu->mainTilemapBuffer;
    u8 baseRow = PARTY_PANEL_START_ROW + slot * PARTY_PANEL_SLOT_HEIGHT;
    u8 row, col;

    if (BagMenu_SlotIsPartner(slot))
        pal = (pal == 0) ? 3 : 4;

    for (row = 0; row < PARTY_PANEL_SLOT_HEIGHT; row++)
        for (col = 0; col < PARTY_PANEL_SLOT_WIDTH; col++)
        {
            u16 *entry = &buf[(baseRow + row) * 32 + (PARTY_PANEL_START_COL + col)];
            *entry = (*entry & 0x0FFF) | ((u16)pal << 12);
        }
    ScheduleBgCopyTilemapToVram(2);
}

static void BagMenu_CreatePanelMonIcon(u8 slot, s16 x2)
{
    struct Pokemon *mon = BagMenu_GetPanelMon(slot);
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    bool32 isEgg;
    u8 spriteId;
    u8 animNum;

    gBagMenu->partyMonIconSpriteIds[slot] = SPRITE_NONE;
    if (species == SPECIES_NONE)
        return;

    isEgg = GetMonData(mon, MON_DATA_IS_EGG);
    spriteId = CreateMonIconIsEgg(species, SpriteCB_MonIcon, 30, 24 * slot + 16, 6, GetMonData(mon, MON_DATA_PERSONALITY), isEgg);

    if (spriteId == MAX_SPRITES)
        return;

    gBagMenu->partyMonIconSpriteIds[slot] = spriteId;
    gSprites[spriteId].oam.priority = 2;
    gSprites[spriteId].invisible = FALSE;
    gSprites[spriteId].x2 = x2;

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

static void BagMenu_CreatePartyIcons(void)
{
    u8 i;
    u8 count = IsWallysBag() ? 1 : PARTY_SIZE;

    memset(gBagMenu->partyMonIconSpriteIds, SPRITE_NONE, sizeof(gBagMenu->partyMonIconSpriteIds));
    LoadMonIconPalettes();
    LoadCompressedSpriteSheet(&sSpriteSheet_StatusIcon);

    if (AllocItemIconTemporaryBuffers())
    {
        struct SpriteSheet sheet = { .data = gItemIcon4x4Buffer, .size = 0x200, .tag = TAG_PARTY_HELD_ITEM };
        u8 palSlot = IndexOfSpritePaletteTag(TAG_PARTY_HELD_ITEM);
        memset(gItemIcon4x4Buffer, 0, 0x200);
        LoadSpriteSheet(&sheet);
        FreeItemIconTemporaryBuffers();
        if (palSlot == 0xFF)
            palSlot = AllocSpritePalette(TAG_PARTY_HELD_ITEM);
        sHeldItemPalIndex = OBJ_PLTT_ID(palSlot);
        sHeldItemIconSpriteId = CreateSprite(&sSpriteTemplate_HeldItemIcon, 0, 0, 5);
        gSprites[sHeldItemIconSpriteId].invisible = TRUE;
    }

    for (i = 0; i < count; i++)
        BagMenu_CreatePanelMonIcon(i, 0);

    for (i = 0; i < count; i++)
    {
        u8 sid = CreateSprite(&sSpriteTemplate_StatusIcon, 44, 23 + i * 24, 2);
        sStatusIconSpriteIds[i] = (sid == MAX_SPRITES) ? SPRITE_NONE : sid;
    }
    BagMenu_UpdateStatusIcons();
    BagMenu_UpdateStatusIconPos(PARTY_SIZE);
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

    if (sHeldItemIconSpriteId != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sHeldItemIconSpriteId]);
        FreeSpriteTilesByTag(TAG_PARTY_HELD_ITEM);
        sHeldItemIconSpriteId = SPRITE_NONE;
    }

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sStatusIconSpriteIds[i] != SPRITE_NONE)
        {
            DestroySprite(&gSprites[sStatusIconSpriteIds[i]]);
            sStatusIconSpriteIds[i] = SPRITE_NONE;
        }
    }
    FreeSpriteTilesByTag(TAG_STATUS_ICON);
}

static u8 BagMenu_GetMonAilment(u8 slot)
{
    struct Pokemon *mon = BagMenu_GetPanelMon(slot);
    if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE)
        return AILMENT_NONE;
    if (GetMonData(mon, MON_DATA_IS_EGG))
        return AILMENT_NONE;
    if (GetMonData(mon, MON_DATA_HP) == 0)
        return AILMENT_FNT;
    return GetAilmentFromStatus(GetMonData(mon, MON_DATA_STATUS));
}

static void BagMenu_UpdateStatusIcons(void)
{
    u8 i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        u8 ailment;
        if (sStatusIconSpriteIds[i] == SPRITE_NONE)
            continue;
        ailment = BagMenu_GetMonAilment(i);
        if (ailment == AILMENT_NONE)
        {
            gSprites[sStatusIconSpriteIds[i]].invisible = TRUE;
        }
        else
        {
            StartSpriteAnim(&gSprites[sStatusIconSpriteIds[i]], ailment - 1);
            gSprites[sStatusIconSpriteIds[i]].invisible = FALSE;
        }
    }
}

static void BagMenu_UpdateStatusIconPos(u8 hoveredSlot)
{
    u8 i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sStatusIconSpriteIds[i] == SPRITE_NONE)
            continue;
        gSprites[sStatusIconSpriteIds[i]].y = 23 + i * 24
            + (BagMenu_ShouldShowHPBar() && i == hoveredSlot ? 0 : 4);
    }
}

static void BagMenu_DrawPartyHPBarPixels(u8 slot, u8 filledWidth)
{
    u16 y = (u16)slot * 3 * 8 + PARTY_HP_BAR_Y_OFFSET;
    u8 colorIdx;

    if (filledWidth > 16)     colorIdx = 12;    // green
    else if (filledWidth > 6) colorIdx = 13;    // yellow
    else                      colorIdx = 14;    // red

    if (sPrevHPBarSlot >= 0 && sPrevHPBarSlot != (s8)slot)
    {
        u16 prevY = (u16)sPrevHPBarSlot * 3 * 8 + PARTY_HP_BAR_Y_OFFSET;
        FillWindowPixelRect(WIN_PARTY_HP_BAR, PIXEL_FILL(0), 0, prevY, 32, 2);
    }
    FillWindowPixelRect(WIN_PARTY_HP_BAR, PIXEL_FILL(0), 0, y, 32, 2);
    if (filledWidth > 0)
        FillWindowPixelRect(WIN_PARTY_HP_BAR, PIXEL_FILL(colorIdx), 0, y, filledWidth, 2);
    if (filledWidth < 32)
        FillWindowPixelRect(WIN_PARTY_HP_BAR, PIXEL_FILL(15), filledWidth, y, 32 - filledWidth, 2);
    CopyWindowToVram(WIN_PARTY_HP_BAR, COPYWIN_GFX);
    ScheduleBgCopyTilemapToVram(1);
    sPrevHPBarSlot = (s8)slot;
}

static void Task_BagMenu_HPBarAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 curWidth    = (u8)data[7];
    u8 targetWidth = (u8)data[9];

    if (curWidth < targetWidth)
        curWidth++;
    data[7] = curWidth;
    BagMenu_DrawPartyHPBarPixels((u8)tPartySlot, curWidth);

    if (curWidth == targetWidth)
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyAfterItemUse);
}

static bool8 BagMenu_ShouldShowHPBar(void)
{
    return SWSH_ITEM_MENU_PARTY_HP_BAR
        && !sPartyGiveMode
        && gItemUseCB != ItemUseCB_EvolutionStone
        && gItemUseCB != ItemUseCB_FormChange
        && gItemUseCB != ItemUseCB_FormChange_ConsumedOnUse
        && gItemUseCB != ItemUseCB_RotomCatalog
        && gItemUseCB != ItemUseCB_ZygardeCube
        && gItemUseCB != ItemUseCB_Fusion
        && gItemUseCB != ItemUseCB_AbilityCapsule
        && gItemUseCB != ItemUseCB_AbilityPatch
        && gItemUseCB != ItemUseCB_Mint
        && gItemUseCB != ItemUseCB_DynamaxCandy
        && gItemUseCB != ItemUseCB_TMHM;
}

static void BagMenu_DrawPartyHPBar(s8 slot)
{
    if (slot < 0)
    {
        if (sHPBarWindowMapped)
        {
            FillWindowPixelBuffer(WIN_PARTY_HP_BAR, PIXEL_FILL(0));
            CopyWindowToVram(WIN_PARTY_HP_BAR, COPYWIN_GFX);
            ClearWindowTilemap(WIN_PARTY_HP_BAR);
            ScheduleBgCopyTilemapToVram(1);
            sHPBarWindowMapped = FALSE;
        }
        sPrevHPBarSlot = -1;
        return;
    }

    if (!sHPBarWindowMapped)
    {
        PutWindowTilemap(WIN_PARTY_HP_BAR);
        sHPBarWindowMapped = TRUE;
    }

    if (sPrevHPBarSlot >= 0 && sPrevHPBarSlot != slot)
    {
        u16 prevY = sPrevHPBarSlot * 3 * 8 + PARTY_HP_BAR_Y_OFFSET;
        FillWindowPixelRect(WIN_PARTY_HP_BAR, PIXEL_FILL(0), 0, prevY, 32, 2);
    }

    {
        struct Pokemon *mon = BagMenu_GetPanelMon(slot);
        u16 y = slot * 3 * 8 + PARTY_HP_BAR_Y_OFFSET;

        if (GetMonData(mon, MON_DATA_IS_EGG))
        {
            FillWindowPixelRect(WIN_PARTY_HP_BAR, PIXEL_FILL(0), 0, y, 32, 2);
        }
        else
        {
            u16 hp    = GetMonData(mon, MON_DATA_HP);
            u16 maxHp = GetMonData(mon, MON_DATA_MAX_HP);
            u8 fillColorIdx;
            u8 hpFraction;

            switch (GetHPBarLevel(hp, maxHp))
            {
            case HP_BAR_FULL:
            case HP_BAR_GREEN:  fillColorIdx = 12; break;
            case HP_BAR_YELLOW: fillColorIdx = 13; break;
            default:            fillColorIdx = 14; break;
            }

            hpFraction = GetScaledHPFraction(hp, maxHp, 32);
            if (hpFraction > 0)
                FillWindowPixelRect(WIN_PARTY_HP_BAR, PIXEL_FILL(fillColorIdx), 0, y, hpFraction, 2);
            if (hpFraction < 32)
                FillWindowPixelRect(WIN_PARTY_HP_BAR, PIXEL_FILL(15), hpFraction, y, 32 - hpFraction, 2);
        }
    }

    CopyWindowToVram(WIN_PARTY_HP_BAR, COPYWIN_GFX);
    ScheduleBgCopyTilemapToVram(1);
    sPrevHPBarSlot = slot;
}

static void SpriteCB_HeldItemIcon_WaitDisappear(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        sprite->invisible = TRUE;
        sprite->callback = SpriteCallbackDummy;
    }
}

static void BagMenu_LoadHeldItemIconGfx(enum Item itemId)
{
    void *vramTiles = (u8 *)OBJ_VRAM0 + 32 * GetSpriteTileStartByTag(TAG_PARTY_HELD_ITEM);
    if (!AllocItemIconTemporaryBuffers())
        return;
    DecompressDataWithHeaderWram(GetItemIconPic(itemId), gItemIconDecompressionBuffer);
    CopyItemIconPicTo4x4Buffer(gItemIconDecompressionBuffer, gItemIcon4x4Buffer);
    CpuFastCopy(gItemIcon4x4Buffer, vramTiles, 0x200);
    FreeItemIconTemporaryBuffers();
    LoadPalette(GetItemIconPalette(itemId), sHeldItemPalIndex, PLTT_SIZE_4BPP);
}

static void BagMenu_UpdateHeldItemIcon(u8 slot)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][slot];
    struct Sprite *spr;
    u16 heldItem;

    if (sHeldItemIconSpriteId == SPRITE_NONE)
        return;

    spr = &gSprites[sHeldItemIconSpriteId];
    heldItem = GetMonData(mon, MON_DATA_HELD_ITEM);

    if (heldItem != ITEM_NONE && !GetMonData(mon, MON_DATA_IS_EGG))
    {
        BagMenu_LoadHeldItemIconGfx(heldItem);
        spr->x = 46;
        spr->y = 24 * slot + 28;
        spr->invisible = FALSE;
        spr->callback = SpriteCallbackDummy;
        StartSpriteAffineAnim(spr, 0);
        sHeldItemCurSlot = slot;
    }
    else
    {
        if (!spr->invisible)
        {
            StartSpriteAffineAnim(spr, 1);
            spr->callback = SpriteCB_HeldItemIcon_WaitDisappear;
        }
        sHeldItemCurSlot = -1;
    }
}

// party mon icon alpha blending (item use eligibility)
static void BagMenu_SetPartyIconBlend(bool8 enable)
{
    if (enable)
    {
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 8));
        sPartyBlendActive = TRUE;
    }
    else
    {
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        sPartyBlendActive = FALSE;
    }
}

static void BagMenu_UpdateTMHMPartyBlend(s32 itemIndex)
{
    u8 i;

    BagMenu_SetPartyIconBlend(TRUE);
    for (i = 0; i < PARTY_SIZE; i++)
    {
        u8 spriteId = gBagMenu->partyMonIconSpriteIds[i];
        bool8 eligible;

        if (spriteId == SPRITE_NONE)
            continue;

        if (itemIndex == LIST_CANCEL)
        {
            eligible = FALSE;
        }
        else
        {
            struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];
            enum Item itemId = BagList_GetItemId(gBagPosition.pocket, itemIndex);
            enum Move move = ItemIdToBattleMoveId(itemId);
            enum Species species = GetMonData(mon, MON_DATA_SPECIES);

            eligible = !GetMonData(mon, MON_DATA_IS_EGG)
                    && (CanLearnTeachableMove(species, move) || MonKnowsMove(mon, move));
        }
        gSprites[spriteId].oam.objMode = eligible ? ST_OAM_OBJ_NORMAL : ST_OAM_OBJ_BLEND;
    }
}

static void BagMenu_DisableTMHMPartyBlend(void)
{
    u8 i;

    if (!sPartyBlendActive)
        return;
    BagMenu_SetPartyIconBlend(FALSE);
    for (i = 0; i < PARTY_SIZE; i++)
    {
        u8 spriteId = gBagMenu->partyMonIconSpriteIds[i];
        if (spriteId != SPRITE_NONE)
            gSprites[spriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
    }
}

static bool8 BagMenu_IsMonEligibleForItem(u8 partySlot)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][partySlot];
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    u32 i;

    if (species == SPECIES_NONE)
        return FALSE;

    if (gItemUseCB == ItemUseCB_EvolutionStone)
    {
        bool32 canStopEvo = TRUE;
        return GetEvolutionTargetSpecies(mon, EVO_MODE_ITEM_USE, gSpecialVar_ItemId, NULL, &canStopEvo, CHECK_EVO) != SPECIES_NONE;
    }
    if (gItemUseCB == ItemUseCB_FormChange || gItemUseCB == ItemUseCB_FormChange_ConsumedOnUse)
    {
        struct FormChangeContext ctx = {
            .method = FORM_CHANGE_ITEM_USE,
            .currentSpecies = species,
            .partyItemUsed = gSpecialVar_ItemId,
            .status = GetMonData(mon, MON_DATA_STATUS),
        };
        return GetFormChangeTargetSpecies_Internal(ctx) != species;
    }
    if (gItemUseCB == ItemUseCB_RotomCatalog || gItemUseCB == ItemUseCB_ZygardeCube)
    {
        const struct FormChange *changes = GetSpeciesFormChanges(species);
        if (changes == NULL || GetMonData(mon, MON_DATA_IS_EGG))
            return FALSE;
        for (i = 0; changes[i].method != FORM_CHANGE_TERMINATOR; i++)
        {
            if (changes[i].method == FORM_CHANGE_ITEM_USE_MULTICHOICE
             && changes[i].param1 == gSpecialVar_ItemId)
                return TRUE;
        }
        return FALSE;
    }
    return FALSE;
}

static void BagMenu_ApplyEvoBlend(void)
{
    u8 i;

    BagMenu_SetPartyIconBlend(TRUE);
    for (i = 0; i < PARTY_SIZE; i++)
    {
        u8 spriteId = gBagMenu->partyMonIconSpriteIds[i];
        if (spriteId == SPRITE_NONE)
            continue;
        gSprites[spriteId].oam.objMode = BagMenu_IsMonEligibleForItem(i) ? ST_OAM_OBJ_NORMAL : ST_OAM_OBJ_BLEND;
    }
}

static void BagMenu_DisableEvoBlend(void)
{
    u8 i;

    if (!sPartyBlendActive)
        return;
    BagMenu_SetPartyIconBlend(FALSE);
    for (i = 0; i < PARTY_SIZE; i++)
    {
        u8 spriteId = gBagMenu->partyMonIconSpriteIds[i];
        if (spriteId != SPRITE_NONE)
            gSprites[spriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
    }
}

static void BagMenu_ApplyGiveBlend(void)
{
    u8 i;

    BagMenu_SetPartyIconBlend(TRUE);
    for (i = 0; i < PARTY_SIZE; i++)
    {
        u8 spriteId = gBagMenu->partyMonIconSpriteIds[i];
        bool8 holdsItem;

        if (spriteId == SPRITE_NONE)
            continue;

        holdsItem = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_HELD_ITEM) != ITEM_NONE;
        gSprites[spriteId].oam.objMode = holdsItem ? ST_OAM_OBJ_NORMAL : ST_OAM_OBJ_BLEND;
    }
}

static bool8 BagMenu_IsMonEligibleFusion1(u8 partySlot)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][partySlot];
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    u8 fusionKind;
    const struct Fusion *tbl;
    u16 i;

    if (species == SPECIES_NONE)
        return FALSE;
    fusionKind = IsFusionMon(species);
    if (fusionKind != BAG_FUSE_MON && fusionKind != BAG_UNFUSE_MON)
        return FALSE;
    tbl = gFusionTablePointers[species];
    if (tbl == NULL)
        return FALSE;
    for (i = 0; tbl[i].fusionStorageIndex != FUSION_TERMINATOR; i++)
    {
        if (tbl[i].itemId == gSpecialVar_ItemId)
            return TRUE;
    }
    return FALSE;
}

static void BagMenu_ApplyFusionStage1Blend(void)
{
    u8 i;

    BagMenu_SetPartyIconBlend(TRUE);
    for (i = 0; i < PARTY_SIZE; i++)
    {
        u8 spriteId = gBagMenu->partyMonIconSpriteIds[i];
        if (spriteId == SPRITE_NONE)
            continue;
        gSprites[spriteId].oam.objMode = BagMenu_IsMonEligibleFusion1(i) ? ST_OAM_OBJ_NORMAL : ST_OAM_OBJ_BLEND;
    }
}

static void BagMenu_ApplyFusionStage2Blend(u8 firstSlot)
{
    u8 i;
    enum Species firstSpecies = GetMonData(&gParties[B_TRAINER_PLAYER][firstSlot], MON_DATA_SPECIES);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u8 spriteId = gBagMenu->partyMonIconSpriteIds[i];
        bool8 eligible;

        if (spriteId == SPRITE_NONE)
            continue;

        if (i == firstSlot)
        {
            eligible = FALSE;
        }
        else
        {
            enum Species species2 = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES);
            const struct Fusion *tbl = gFusionTablePointers[species2];
            u16 j;

            eligible = FALSE;
            if (IsFusionMon(species2) == BAG_SECOND_FUSE_MON && tbl != NULL)
            {
                for (j = 0; tbl[j].fusionStorageIndex != FUSION_TERMINATOR; j++)
                {
                    if (tbl[j].itemId == gSpecialVar_ItemId
                     && tbl[j].targetSpecies1 == firstSpecies
                     && tbl[j].targetSpecies2 == species2
                     && gPokemonStoragePtr->fusions[tbl[j].fusionStorageIndex].level == 0)
                    {
                        eligible = TRUE;
                        break;
                    }
                }
            }
        }
        gSprites[spriteId].oam.objMode = eligible ? ST_OAM_OBJ_NORMAL : ST_OAM_OBJ_BLEND;
    }
}

static void BagMenu_PartyStartItemIconYAnim(struct Sprite *spr, s16 toY)
{
    struct ComfyAnimEasingConfig config;
    InitComfyAnimConfig_Easing(&config);
    config.from = Q_24_8(spr->y2);
    config.to = Q_24_8(toY);
    config.durationFrames = 8;
    config.easingFunc = ComfyAnimEasing_EaseOutCubic;
    if (sPartyItemIconAnimId == INVALID_COMFY_ANIM)
        sPartyItemIconAnimId = CreateComfyAnim_Easing(&config);
    else
        InitComfyAnim_Easing(&config, &gComfyAnims[sPartyItemIconAnimId]);
}

void BagMenu_OpenPartySelect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 iconSpriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + (gBagMenu->itemIconSlot ^ 1)];

    if (gItemUseCB == ItemUseCB_SacredAsh)
    {
        BagMenu_UseSacredAsh(taskId);
        return;
    }

    tPartySlot = 0;
    tPartySavedIconY = ReadComfyAnimValueSmooth(&gComfyAnims[sCursorAnimId]);

    if (sPartyGiveMode)
    {
        u8 si;
        BagMenu_ApplyGiveBlend();
        BagMenu_UpdateHeldItemIcon(0);
        for (si = 0; si < PARTY_SIZE; si++)
            if (sStatusIconSpriteIds[si] != SPRITE_NONE)
                gSprites[sStatusIconSpriteIds[si]].invisible = TRUE;
    }

    if (!sPartyGiveMode)
    {
        if (gItemUseCB == ItemUseCB_Fusion)
            BagMenu_ApplyFusionStage1Blend();
        else if (gItemUseCB == ItemUseCB_EvolutionStone
                || gItemUseCB == ItemUseCB_FormChange
                || gItemUseCB == ItemUseCB_FormChange_ConsumedOnUse
                || gItemUseCB == ItemUseCB_RotomCatalog
                || gItemUseCB == ItemUseCB_ZygardeCube)
            BagMenu_ApplyEvoBlend();
    }

    gSprites[sCursorSpriteId].invisible = TRUE;
    BagMenu_SetPartySlotPalette(0, 2);
    BagMenu_UpdateStatusIconPos(0);

    if (BagMenu_ShouldShowHPBar())
        BagMenu_DrawPartyHPBar(0);

    if (iconSpriteId != SPRITE_NONE)
    {
        struct Sprite *spr = &gSprites[iconSpriteId];
        spr->x2 = PARTY_ITEM_ICON_X;
        BagMenu_PartyStartItemIconYAnim(spr, PARTY_ITEM_ICON_Y(0));
    }

    gTasks[taskId].func = Task_BagMenu_PartyInput;
}

#if SWSH_ITEM_MENU_ACTION_IN_BATTLE
void BagMenu_OpenPartySelectBattle(u8 taskId)
{
    BagMenu_OpenPartySelect(taskId);
}
#endif

static void Task_BagMenu_PartyInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 slotLimit = BagMenu_PanelSlotLimit();
    u8 iconSpriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + (gBagMenu->itemIconSlot ^ 1)];

    if (iconSpriteId != SPRITE_NONE && sPartyItemIconAnimId != INVALID_COMFY_ANIM)
        gSprites[iconSpriteId].y2 = ReadComfyAnimValueSmooth(&gComfyAnims[sPartyItemIconAnimId]);

    if (sPartyItemIconAnimId != INVALID_COMFY_ANIM && !gComfyAnims[sPartyItemIconAnimId].completed)
        return;

#if SWSH_ITEM_MENU_ACTION_IN_BATTLE
    if (BagMenu_IsMultiFull() && GetLRKeysPressed())
    {
        BagMenu_ClosePartySelect(taskId);
        BagMenu_StartMultiFullSwap(taskId);
        return;
    }
#endif

    if (JOY_NEW(DPAD_DOWN))
    {
        BagMenu_SetPartySlotPalette(tPartySlot, 0);
        tPartySlot = BagMenu_StepSlot(tPartySlot, +1, slotLimit);
        BagMenu_SetPartySlotPalette(tPartySlot, 2);
        BagMenu_UpdateStatusIconPos(tPartySlot);
        PlaySE(SE_SELECT);
        if (iconSpriteId != SPRITE_NONE)
            BagMenu_PartyStartItemIconYAnim(&gSprites[iconSpriteId], PARTY_ITEM_ICON_Y(tPartySlot));
        if (sPartyGiveMode)
            BagMenu_UpdateHeldItemIcon(tPartySlot);
        if (BagMenu_ShouldShowHPBar())
            BagMenu_DrawPartyHPBar(tPartySlot);
    }
    else if (JOY_NEW(DPAD_UP))
    {
        BagMenu_SetPartySlotPalette(tPartySlot, 0);
        tPartySlot = BagMenu_StepSlot(tPartySlot, -1, slotLimit);
        BagMenu_SetPartySlotPalette(tPartySlot, 2);
        BagMenu_UpdateStatusIconPos(tPartySlot);
        PlaySE(SE_SELECT);
        if (iconSpriteId != SPRITE_NONE)
            BagMenu_PartyStartItemIconYAnim(&gSprites[iconSpriteId], PARTY_ITEM_ICON_Y(tPartySlot));
        if (sPartyGiveMode)
            BagMenu_UpdateHeldItemIcon(tPartySlot);
        if (BagMenu_ShouldShowHPBar())
            BagMenu_DrawPartyHPBar(tPartySlot);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BagMenu_ClosePartySelect(taskId);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if (GetMonData(BagMenu_GetPanelMon(tPartySlot), MON_DATA_IS_EGG))
        {
            PlaySE(SE_FAILURE);
            return;
        }
        if (sPartyGiveMode)
            BagMenu_GiveItem(taskId);
#if SWSH_ITEM_MENU_ACTION_IN_BATTLE
        else if (BagMenu_InBattleSelect())
            BagMenu_UseBattleItem(taskId);
#endif
        else
            BagMenu_TryMultiUse(taskId);
    }
}

static void BagMenu_ClosePartySelect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 iconSpriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + (gBagMenu->itemIconSlot ^ 1)];
    sPartyGiveMode = FALSE;
    BagMenu_DisableEvoBlend();
    BagMenu_UpdateStatusIcons();
    BagMenu_UpdateStatusIconPos(PARTY_SIZE);
    BagMenu_DrawPartyHPBar(-1);

    if (sHeldItemIconSpriteId != SPRITE_NONE)
    {
        gSprites[sHeldItemIconSpriteId].invisible = TRUE;
        gSprites[sHeldItemIconSpriteId].callback = SpriteCallbackDummy;
        sHeldItemCurSlot = -1;
    }
    if (gBagPosition.pocket == POCKET_TM_HM)
        BagMenu_UpdateTMHMPartyBlend(sHoveredItemIndex);

    if (sPartyItemIconAnimId != INVALID_COMFY_ANIM)
    {
        ReleaseComfyAnim(sPartyItemIconAnimId);
        sPartyItemIconAnimId = INVALID_COMFY_ANIM;
    }

    gSprites[sCursorSpriteId].invisible = FALSE;

    if (iconSpriteId != SPRITE_NONE)
    {
        struct Sprite *spr = &gSprites[iconSpriteId];
        spr->x2 = 102;
        spr->y2 = tPartySavedIconY + 4;
        spr->invisible = FALSE;
    }

    BagMenu_SetPartySlotPalette(tPartySlot, 0);
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

static void Task_BagMenu_PartyStayAfterMessage(u8 taskId)
{
    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    gTasks[taskId].func = Task_BagMenu_PartyInput;
}

static void Task_BagMenu_PartyAfterItemUse(u8 taskId)
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
        BagMenu_ClosePartySelect(taskId);
        return;
    }

    if (newSpriteId != SPRITE_NONE)
    {
        DestroySpriteAndFreeResources(&gSprites[newSpriteId]);
        gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + newSlot] = SPRITE_NONE;
    }
    gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + newSlot] = keepSpriteId;
    if (keepSpriteId != SPRITE_NONE)
        gSprites[keepSpriteId].invisible = FALSE;

    if (sPartyGiveMode)
    {
        BagMenu_ApplyGiveBlend();
        BagMenu_SetPartySlotPalette(gTasks[taskId].data[4], 2);
        BagMenu_UpdateHeldItemIcon(gTasks[taskId].data[4]);
    }
    else
    {
        BagMenu_SetPartySlotPalette(gTasks[taskId].data[4], 2);
        BagMenu_UpdateStatusIcons();
        BagMenu_UpdateStatusIconPos(gTasks[taskId].data[4]);
    }
    if (BagMenu_ShouldShowHPBar())
        BagMenu_DrawPartyHPBar(gTasks[taskId].data[4]);
    gTasks[taskId].func = Task_BagMenu_PartyInput;
}

static void BagMenu_DisplayCannotUseMessage(u8 taskId)
{
    DisplayItemMessage(taskId, FONT_NORMAL, gText_WontHaveEffect, Task_BagMenu_PartyStayAfterMessage);
}

static void BagMenu_FreeItemUseState(void)
{
    Free(sBagItemUseState);
    sBagItemUseState = NULL;
}

static void BagMenu_GetMedicineEffectMessage(enum Item item, u32 statusCured)
{
    enum ItemEffectType effectType = GetItemEffectType(item);

    switch (effectType)
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
    case ITEM_EFFECT_ATK_EV:
    case ITEM_EFFECT_DEF_EV:
    case ITEM_EFFECT_SPEED_EV:
    case ITEM_EFFECT_SPATK_EV:
    case ITEM_EFFECT_SPDEF_EV:
        BagMenu_GetEVStatName(effectType, gStringVar2);
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

static void BagMenu_UseSacredAsh(u8 taskId)
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
    tPartyTemp = 0;
    data[7] = revivedMask;
    Task_BagMenu_SacredAshMessages(taskId);
}

static void Task_BagMenu_SacredAshMessages(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 slot = (u8)tPartyTemp;
    u8 revivedMask = (u8)data[7];

    while (slot < PARTY_SIZE && !(revivedMask & (1 << slot)))
        slot++;

    if (slot >= PARTY_SIZE)
    {
        BagMenu_UpdateStatusIcons();
        CloseItemMessage(taskId);
        return;
    }

    tPartyTemp = slot + 1;

    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][slot];
    GetMonNickname(mon, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar2, GetMonData(mon, MON_DATA_HP), STR_CONV_MODE_LEFT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_PkmnHPRestoredByVar2);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_SacredAshMessages);
}

static void BagMenu_UseMedicine(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    enum Item item = gSpecialVar_ItemId;
    u16 hp = 0, maxHp = 0;
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
            maxHp = GetMonData(mon, MON_DATA_MAX_HP);
            if (hp == maxHp)
                canHeal = FALSE;
        }
        cannotUse = ExecuteTableBasedItemEffect(mon, item, tPartySlot, 0);
    }

    if (cannotUse)
    {
        PlaySE(SE_SELECT);
        BagMenu_DisplayCannotUseMessage(taskId);
        return;
    }

    PlaySE(SE_USE_ITEM);
    for (s16 i = 1; i < tItemCount; i++)
        ExecuteTableBasedItemEffect(mon, item, tPartySlot, 0);
    RemoveBagItem(item, tItemCount);

    if (GetMonData(mon, MON_DATA_STATUS) != oldStatus)
        BagMenu_UpdateStatusIcons();

    GetMonNickname(mon, gStringVar1);
    if (canHeal)
    {
        u16 newHp = GetMonData(mon, MON_DATA_HP);
        ConvertIntToDecimalStringN(gStringVar2, newHp - hp, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringExpandPlaceholders(gStringVar4, gText_PkmnHPRestoredByVar2);

        if (BagMenu_ShouldShowHPBar())
        {
            u8 oldFraction = GetScaledHPFraction(hp, maxHp, 32);
            u8 newFraction = GetScaledHPFraction(newHp, maxHp, 32);
            if (newFraction > oldFraction)
            {
                BagMenu_DrawPartyHPBarPixels(tPartySlot, oldFraction);
                data[7] = oldFraction;
                data[9] = newFraction;
                gTasks[taskId].func = Task_BagMenu_HPBarAnim;
                return;
            }
        }
    }
    else
    {
        BagMenu_GetMedicineEffectMessage(item, oldStatus);
    }

    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyAfterItemUse);
}

static void BagMenu_UseResetEVs(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    enum Item item = gSpecialVar_ItemId;
    bool8 cannotUse = ExecuteTableBasedItemEffect(mon, item, tPartySlot, 0);

    if (cannotUse)
    {
        PlaySE(SE_SELECT);
        BagMenu_DisplayCannotUseMessage(taskId);
        return;
    }

    PlaySE(SE_USE_ITEM);
    RemoveBagItem(item, 1);
    GetMonNickname(mon, gStringVar1);
    StringExpandPlaceholders(gStringVar4, sText_PartyBasePointsReset);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyAfterItemUse);
}

static void BagMenu_UseDynamaxCandy(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    enum Item item = gSpecialVar_ItemId;
    u8 dynamaxLevel = GetMonData(mon, MON_DATA_DYNAMAX_LEVEL);

    if (dynamaxLevel >= MAX_DYNAMAX_LEVEL)
    {
        PlaySE(SE_SELECT);
        BagMenu_DisplayCannotUseMessage(taskId);
        return;
    }

    PlaySE(SE_USE_ITEM);
    dynamaxLevel++;
    SetMonData(mon, MON_DATA_DYNAMAX_LEVEL, &dynamaxLevel);
    RemoveBagItem(item, 1);
    GetMonNickname(mon, gStringVar1);
    StringExpandPlaceholders(gStringVar4, sText_PartyDynamaxLevelUp);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyAfterItemUse);
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

static void BagMenu_UseReduceEV(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    enum Item item = gSpecialVar_ItemId;
    enum ItemEffectType effectType = GetItemEffectType(item);
    u16 friendship = GetMonData(mon, MON_DATA_FRIENDSHIP);
    u16 ev = BagMenu_GetMonEV(mon, effectType);
    bool8 cannotUse = ExecuteTableBasedItemEffect(mon, item, tPartySlot, 0);
    u16 newFriendship;
    u16 newEv;

    if (!cannotUse)
    {
        for (s16 i = 1; i < tItemCount; i++)
            ExecuteTableBasedItemEffect(mon, item, tPartySlot, 0);
    }
    newFriendship = GetMonData(mon, MON_DATA_FRIENDSHIP);
    newEv = BagMenu_GetMonEV(mon, effectType);

    if (cannotUse || (friendship == newFriendship && ev == newEv))
    {
        PlaySE(SE_SELECT);
        BagMenu_DisplayCannotUseMessage(taskId);
        return;
    }

    PlaySE(SE_USE_ITEM);
    RemoveBagItem(item, tItemCount);
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
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyAfterItemUse);
}

static void Task_BagMenu_AbilityChangeYesNo(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tPartyTemp)
    {
    case 0:
        BagMenu_YesNo(taskId, ITEMWIN_YESNO_HIGH, &sPartyAbilityChangeYesNo);
        tPartyTemp++;
        break;
    case 1:
        break;
    }
}

static void BagMenu_AbilityChangeYes(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
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
    StringExpandPlaceholders(gStringVar4, sText_PartyAbilityDone);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyAfterItemUse);
}

static void BagMenu_AbilityChangeNo(u8 taskId)
{
    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    gTasks[taskId].func = Task_BagMenu_PartyInput;
}

static void BagMenu_UseAbilityCapsule(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    u32 species = GetMonData(mon, MON_DATA_SPECIES);
    u8 abilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM) ^ 1;

    if (!species
        || GetSpeciesAbility(species, 0) == GetSpeciesAbility(species, 1)
        || GetSpeciesAbility(species, 1) == 0
        || GetMonData(mon, MON_DATA_ABILITY_NUM) > 1)
    {
        PlaySE(SE_SELECT);
        BagMenu_DisplayCannotUseMessage(taskId);
        return;
    }

    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, gAbilitiesInfo[GetAbilityBySpecies(species, abilityNum)].name);
    StringExpandPlaceholders(gStringVar4, sText_PartyAbilityAsk);
    tPartyTemp = 0;
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_AbilityChangeYesNo);
}

static void BagMenu_UseAbilityPatch(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    u32 species = GetMonData(mon, MON_DATA_SPECIES);
    u8 currentAbilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM);
    u8 abilityNum = (currentAbilityNum == 2) ? 0 : 2;

    if (!species || GetSpeciesAbility(species, abilityNum) == 0)
    {
        PlaySE(SE_SELECT);
        BagMenu_DisplayCannotUseMessage(taskId);
        return;
    }

    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, gAbilitiesInfo[GetAbilityBySpecies(species, abilityNum)].name);
    StringExpandPlaceholders(gStringVar4, sText_PartyAbilityAsk);
    tPartyTemp = 0;
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_AbilityChangeYesNo);
}

static void Task_BagMenu_MintYesNo(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tPartyTemp)
    {
    case 0:
        BagMenu_YesNo(taskId, ITEMWIN_YESNO_HIGH, &sPartyMintYesNo);
        tPartyTemp++;
        break;
    case 1:
        break;
    }
}

static void BagMenu_MintYes(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    enum Item item = gSpecialVar_ItemId;
    u8 newNature = GetItemSecondaryId(item);

    PlaySE(SE_USE_ITEM);
    SetMonData(mon, MON_DATA_HIDDEN_NATURE, &newNature);
    CalculateMonStats(mon);
    RemoveBagItem(item, 1);
    GetMonNickname(mon, gStringVar1);
    CopyItemName(item, gStringVar2);
    StringExpandPlaceholders(gStringVar4, sText_PartyMintDone);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyAfterItemUse);
}

static void BagMenu_MintNo(u8 taskId)
{
    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    gTasks[taskId].func = Task_BagMenu_PartyInput;
}

static void BagMenu_UseMint(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    enum Item item = gSpecialVar_ItemId;
    u8 currentNature = GetMonData(mon, MON_DATA_HIDDEN_NATURE);
    u8 newNature = GetItemSecondaryId(item);

    if (currentNature == newNature)
    {
        PlaySE(SE_SELECT);
        BagMenu_DisplayCannotUseMessage(taskId);
        return;
    }

    GetMonNickname(mon, gStringVar1);
    CopyItemName(item, gStringVar2);
    StringExpandPlaceholders(gStringVar4, sText_PartyMintAsk);
    tPartyTemp = 0;
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_MintYesNo);
}

static void BagMenu_UsePPOnMove(u8 taskId, u8 moveSlot)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    enum Item item = gSpecialVar_ItemId;

    if (ExecuteTableBasedItemEffect(mon, item, tPartySlot, moveSlot))
    {
        PlaySE(SE_SELECT);
        BagMenu_DisplayCannotUseMessage(taskId);
        return;
    }

    PlaySE(SE_USE_ITEM);
    RemoveBagItem(item, 1);
    StringCopy(gStringVar1, GetMoveName(GetMonData(mon, MON_DATA_MOVE1 + moveSlot)));
    BagMenu_GetMedicineEffectMessage(item, 0);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyAfterItemUse);
}

static const u8 sPPMoveSelectColors[][3] = {
    [0] = {0, 4, 5},
    [1] = {0, 6, 7},
    [2] = {0, 8, 9},
};

static void BagMenu_ShowPPMoveSelectWindow(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = BagMenu_GetPanelMon(tPartySlot);
    u8 windowId = BagMenu_AddWindow(ITEMWIN_PP_MOVE_SELECT);
    u8 moveCount = 0;
    u8 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        enum Move move = GetMonData(mon, MON_DATA_MOVE1 + i);
        u8 fontId = GetFontIdToFit(GetMoveName(move), FONT_NORMAL, 0, 72);
        AddTextPrinterParameterized(windowId, fontId, GetMoveName(move), 8, (i * 16) + 1, TEXT_SKIP_DRAW, NULL);
        if (move != MOVE_NONE)
        {
            u8 currentPp = GetMonData(mon, MON_DATA_PP1 + i);
            u8 maxPp = CalculatePPWithBonus(move, GetMonData(mon, MON_DATA_PP_BONUSES), i);
            u8 ppState = GetCurrentPpToMaxPpState(currentPp, maxPp);
            s32 x;

            ConvertIntToDecimalStringN(gStringVar1, currentPp, STR_CONV_MODE_RIGHT_ALIGN, 2);
            ConvertIntToDecimalStringN(gStringVar2, maxPp, STR_CONV_MODE_RIGHT_ALIGN, 2);
            StringCopy(gStringVar3, gStringVar1);
            StringAppend(gStringVar3, gText_Slash);
            StringAppend(gStringVar3, gStringVar2);
            x = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar3, WindowWidthPx(windowId));
            if (ppState == 3)
                AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar3, x, (i * 16) + 1, TEXT_SKIP_DRAW, NULL);
            else
                AddTextPrinterParameterized4(windowId, FONT_NORMAL, x, (i * 16) + 1, 0, 0, sPPMoveSelectColors[ppState], TEXT_SKIP_DRAW, gStringVar3);
            moveCount++;
        }
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
        gTasks[taskId].func = Task_BagMenu_PartyInput;
#if SWSH_ITEM_MENU_ACTION_IN_BATTLE
    else if (BagMenu_InBattleSelect())
        BagMenu_BattleUsePPOnMove(taskId, (u8)input);
#endif
    else
        BagMenu_UsePPOnMove(taskId, (u8)input);
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

static void BagMenu_UseRareCandy(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    enum Item item = gSpecialVar_ItemId;
    u8 holdEffectParam = GetItemHoldEffectParam(item);
    bool8 cannotUse;
    u8 initialLevel = GetMonData(mon, MON_DATA_LEVEL);
    s16 appliedCount = 0;

    if (sBagItemUseState == NULL)
        sBagItemUseState = AllocZeroed(sizeof(*sBagItemUseState));

    sBagItemUseState->slot = tPartySlot;
    sBagItemUseState->savedExitCallback = gBagPosition.exitCallback;
    sBagItemUseState->moveLearnContinue = BagMenu_RareCandyDoLearnMoveStep;

    if (B_RARE_CANDY_CAP && initialLevel >= GetCurrentLevelCap())
    {
        cannotUse = TRUE;
    }
    else
    {
        BagMenu_RareCandyBufferStats(mon, sBagItemUseState->statsBefore);
        for (s16 i = 0; i < tItemCount; i++)
        {
            if (!ExecuteTableBasedItemEffect(mon, item, tPartySlot, 0))
                appliedCount++;
            else
                break;
        }
        BagMenu_RareCandyBufferStats(mon, sBagItemUseState->statsAfter);
        cannotUse = (appliedCount == 0);
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
                sBagItemUseState->evolutionTarget = target;
                sBagItemUseState->canStopEvolution = canStopEvo;
                gCB2_AfterEvolution = BagMenu_CB2_AfterRareCandyEvolution;
                gBagMenu->newScreenCallback = BagMenu_CB2_DoBeginEvolution;
                Task_FadeAndCloseBagMenu(taskId);
                return;
            }
        }
        BagMenu_FreeItemUseState();
        BagMenu_DisplayCannotUseMessage(taskId);
        return;
    }

    sBagItemUseState->initialLevel = initialLevel;
    sBagItemUseState->finalLevel = GetMonData(mon, MON_DATA_LEVEL);
    RemoveBagItem(item, appliedCount);
    GetMonNickname(mon, gStringVar1);

    if (sBagItemUseState->finalLevel > sBagItemUseState->initialLevel)
    {
        PlayFanfareByFanfareNum(FANFARE_LEVEL_UP);
        if (holdEffectParam == 0)
        {
            ConvertIntToDecimalStringN(gStringVar2, sBagItemUseState->finalLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
            StringExpandPlaceholders(gStringVar4, gText_PkmnElevatedToLvVar2);
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar2, sExpCandyExperienceTable[holdEffectParam - 1] * appliedCount, STR_CONV_MODE_LEFT_ALIGN, 7);
            ConvertIntToDecimalStringN(gStringVar3, sBagItemUseState->finalLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
            StringExpandPlaceholders(gStringVar4, gText_PkmnGainedExpAndElevatedToLvVar3);
        }
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_RareCandyWaitLvUpMsg);
    }
    else
    {
        PlaySE(SE_USE_ITEM);
        ConvertIntToDecimalStringN(gStringVar2, sExpCandyExperienceTable[holdEffectParam - 1] * appliedCount, STR_CONV_MODE_LEFT_ALIGN, 7);
        StringExpandPlaceholders(gStringVar4, gText_PkmnGainedExp);
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyAfterItemUse);
        BagMenu_FreeItemUseState();
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
        DrawLevelUpWindowPg1(windowId, (u16 *)sBagItemUseState->statsBefore,
                             (u16 *)sBagItemUseState->statsAfter,
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
                             (u16 *)sBagItemUseState->statsAfter,
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
        sBagItemUseState->learnMoveLevel = sBagItemUseState->initialLevel + 1;
        sBagItemUseState->firstMoveAtLevel = TRUE;
        BagMenu_RareCandyDoLearnMoveStep(taskId);
    }
}

static void BagMenu_RareCandyDoLearnMoveStep(u8 taskId)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][sBagItemUseState->slot];

    for (; sBagItemUseState->learnMoveLevel <= sBagItemUseState->finalLevel;)
    {
        bool8 first = sBagItemUseState->firstMoveAtLevel;
        u16 result;

        sBagItemUseState->firstMoveAtLevel = FALSE;
        SetMonData(mon, MON_DATA_LEVEL, &sBagItemUseState->learnMoveLevel);
        result = MonTryLearningNewMove(mon, first);
        switch (result)
        {
        case 0:
            if (sBagItemUseState->learnMoveLevel >= sBagItemUseState->finalLevel)
            {
                BagMenu_RareCandyTryEvolution(taskId);
                return;
            }
            sBagItemUseState->learnMoveLevel++;
            sBagItemUseState->firstMoveAtLevel = TRUE;
            continue;
        case MON_ALREADY_KNOWS_MOVE:
            continue;
        case MON_HAS_MAX_MOVES:
            sBagItemUseState->moveToLearn = gMoveToLearn;
            GetMonNickname(mon, gStringVar1);
            StringCopy(gStringVar2, GetMoveName(gMoveToLearn));
            StringExpandPlaceholders(gStringVar4, gText_PkmnNeedsToReplaceMove);
            gTasks[taskId].tPartyTemp = 0;
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_RareCandyReplaceYesNo);
            return;
        default:
            GetMonNickname(mon, gStringVar1);
            StringCopy(gStringVar2, GetMoveName(result));
            StringExpandPlaceholders(gStringVar4, gText_PkmnLearnedMove3);
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_MoveLearnFanfare);
            sBagItemUseState->learnMoveLevel++;
            sBagItemUseState->firstMoveAtLevel = TRUE;
            return;
        }
    }
    BagMenu_RareCandyTryEvolution(taskId);
}

static void Task_BagMenu_MoveLearnFanfare(u8 taskId)
{
    PlayFanfare(MUS_LEVEL_UP);
    gTasks[taskId].func = Task_BagMenu_MoveLearnFanfareWait;
}

static void Task_BagMenu_MoveLearnFanfareWait(u8 taskId)
{
    if (IsFanfareTaskInactive() && (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON)))
    {
        RemoveItemMessageWindow(ITEMWIN_MESSAGE);
        gTasks[taskId].func = sBagItemUseState->moveLearnContinue;
    }
}

static void Task_BagMenu_RareCandyReplaceYesNo(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tPartyTemp)
    {
    case 0:
        BagMenu_YesNo(taskId, ITEMWIN_YESNO_HIGH, &sPartyRareCandyReplaceYesNo);
        tPartyTemp++;
        break;
    case 1:
        break;
    }
}

static void BagMenu_RareCandyReplaceYes(u8 taskId)
{
    GetMonNickname(&gParties[B_TRAINER_PLAYER][sBagItemUseState->slot], gStringVar1);
    StringCopy(gStringVar2, GetMoveName(sBagItemUseState->moveToLearn));
    StringExpandPlaceholders(gStringVar4, gText_WhichMoveToForget);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_MoveLearnGoToSummary);
}

static void BagMenu_RareCandyReplaceNo(u8 taskId)
{
    GetMonNickname(&gParties[B_TRAINER_PLAYER][sBagItemUseState->slot], gStringVar1);
    StringCopy(gStringVar2, GetMoveName(sBagItemUseState->moveToLearn));
    StringExpandPlaceholders(gStringVar4, gText_MoveNotLearned);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_MoveLearnNotLearned);
}

static void Task_BagMenu_MoveLearnNotLearned(u8 taskId)
{
    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    gTasks[taskId].func = sBagItemUseState->moveLearnContinue;
}

static void Task_BagMenu_MoveLearnGoToSummary(u8 taskId)
{
    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    sBagItemUseState->reentryPhase = BAG_REENTRY_MOVE_FORGET;
    gBagMenu->newScreenCallback = BagMenu_CB2_SummaryForMoveForget;
    Task_FadeAndCloseBagMenu(taskId);
}

static void BagMenu_CB2_SummaryForMoveForget(void)
{
    ShowSelectMovePokemonSummaryScreen(gParties[B_TRAINER_PLAYER],
                                      sBagItemUseState->slot,
                                      BagMenu_CB2_ReturnFromMoveForget,
                                      sBagItemUseState->moveToLearn);
}

static void BagMenu_CB2_ReturnFromMoveForget(void)
{
    GoToBagMenu(ITEMMENULOCATION_LAST, POCKETS_COUNT, sBagItemUseState->savedExitCallback);
}

static void Task_BagMenu_RareCandyReentry(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (gPaletteFade.active)
        return;

    switch (sBagItemUseState->reentryPhase)
    {
    case BAG_REENTRY_MOVE_FORGET:
    {
        tPartySlot = sBagItemUseState->slot;
        tPartySavedIconY = ReadComfyAnimValueSmooth(&gComfyAnims[sCursorAnimId]);
        gSprites[sCursorSpriteId].invisible = TRUE;
        sBagItemUseState->reentryPhase = BAG_REENTRY_NONE;
        gTasks[taskId].func = Task_BagMenu_MoveLearnAfterForget;
        break;
    }
    case BAG_REENTRY_ITEM_USE:
    {
        u8 slot = sBagItemUseState->slot;
        tPartySlot = slot;
        tPartySavedIconY = ReadComfyAnimValueSmooth(&gComfyAnims[sCursorAnimId]);
        gSprites[sCursorSpriteId].invisible = TRUE;
        BagMenu_SetPartySlotPalette(slot, 2);
        BagMenu_UpdateStatusIconPos(slot);
        if (BagMenu_ShouldShowHPBar())
            BagMenu_DrawPartyHPBar(slot);
        BagMenu_FreeItemUseState();
        gTasks[taskId].func = Task_BagMenu_PartyInput;
        break;
    }
    }
}

static void Task_BagMenu_MoveLearnAfterForget(u8 taskId)
{
    u8 moveSlot;

    if (sPartyItemIconAnimId != INVALID_COMFY_ANIM && !gComfyAnims[sPartyItemIconAnimId].completed)
        return;

    moveSlot = GetMoveSlotToReplace();
    if (moveSlot != MAX_MON_MOVES)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][sBagItemUseState->slot];
        enum Move oldMove = GetMonData(mon, MON_DATA_MOVE1 + moveSlot);

        RemoveMonPPBonus(mon, moveSlot);
        SetMonMoveSlot(mon, sBagItemUseState->moveToLearn, moveSlot);

        GetMonNickname(mon, gStringVar1);
        StringCopy(gStringVar2, GetMoveName(oldMove));
        StringExpandPlaceholders(gStringVar4, gText_12PoofForgotMove);
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_MoveLearnAfterForgotMove);
    }
    else
    {
        GetMonNickname(&gParties[B_TRAINER_PLAYER][sBagItemUseState->slot], gStringVar1);
        StringCopy(gStringVar2, GetMoveName(sBagItemUseState->moveToLearn));
        StringExpandPlaceholders(gStringVar4, gText_MoveNotLearned);
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_MoveLearnNotLearned);
    }
}

static void Task_BagMenu_MoveLearnAfterForgotMove(u8 taskId)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][sBagItemUseState->slot];

    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, GetMoveName(sBagItemUseState->moveToLearn));
    StringExpandPlaceholders(gStringVar4, gText_PkmnLearnedMove3);
    sBagItemUseState->learnMoveLevel++;
    sBagItemUseState->firstMoveAtLevel = TRUE;
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_MoveLearnFanfare);
}

static void Task_BagMenu_MoveLearnDone(u8 taskId)
{
    BagMenu_FreeItemUseState();
    Task_BagMenu_PartyAfterItemUse(taskId);
}

static void BagMenu_RareCandyTryEvolution(u8 taskId)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][sBagItemUseState->slot];
    bool32 canStopEvo = TRUE;
    enum Species target = GetEvolutionTargetSpecies(mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, &canStopEvo, CHECK_EVO);

    if (target != SPECIES_NONE)
    {
        GetEvolutionTargetSpecies(mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, &canStopEvo, DO_EVO);
        sBagItemUseState->evolutionTarget = target;
        sBagItemUseState->canStopEvolution = canStopEvo;
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
    EvolutionScene(&gParties[B_TRAINER_PLAYER][sBagItemUseState->slot],
                   sBagItemUseState->evolutionTarget,
                   sBagItemUseState->canStopEvolution,
                   sBagItemUseState->slot);
}

static void BagMenu_CB2_AfterRareCandyEvolution(void)
{
    if (GetItemFieldFunc(gSpecialVar_ItemId) == ItemUseOutOfBattle_RareCandy
        && CheckBagHasItem(gSpecialVar_ItemId, 1))
    {
        sBagItemUseState->reentryPhase = BAG_REENTRY_ITEM_USE;
        GoToBagMenu(ITEMMENULOCATION_LAST, POCKETS_COUNT, sBagItemUseState->savedExitCallback);
    }
    else
    {
        MainCallback exitCb = sBagItemUseState->savedExitCallback;
        BagMenu_FreeItemUseState();
        GoToBagMenu(ITEMMENULOCATION_LAST, POCKETS_COUNT, exitCb);
    }
}

static void BagMenu_RareCandyCleanupAndReturn(u8 taskId)
{
    BagMenu_FreeItemUseState();
    Task_BagMenu_PartyAfterItemUse(taskId);
}

static void BagMenu_UseEvolutionStone(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 item = gSpecialVar_ItemId;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    bool32 canStopEvo = TRUE;
    enum Species target = GetEvolutionTargetSpecies(mon, EVO_MODE_ITEM_USE, item, NULL, &canStopEvo, CHECK_EVO);

    PlaySE(SE_SELECT);

    if (target == SPECIES_NONE)
    {
        BagMenu_DisplayCannotUseMessage(taskId);
        return;
    }

    GetEvolutionTargetSpecies(mon, EVO_MODE_ITEM_USE, item, NULL, &canStopEvo, DO_EVO);
    RemoveBagItem(item, 1);

    if (sBagItemUseState == NULL)
        sBagItemUseState = AllocZeroed(sizeof(*sBagItemUseState));

    sBagItemUseState->slot = tPartySlot;
    sBagItemUseState->savedExitCallback = gBagPosition.exitCallback;
    sBagItemUseState->evolutionTarget = target;
    sBagItemUseState->canStopEvolution = canStopEvo;
    gCB2_AfterEvolution = BagMenu_CB2_AfterEvoStoneEvolution;
    gBagMenu->newScreenCallback = BagMenu_CB2_DoBeginEvolution;
    Task_FadeAndCloseBagMenu(taskId);
}

static void BagMenu_CB2_AfterEvoStoneEvolution(void)
{
    if (CheckBagHasItem(gSpecialVar_ItemId, 1))
    {
        sBagItemUseState->reentryPhase = BAG_REENTRY_ITEM_USE;
        GoToBagMenu(ITEMMENULOCATION_LAST, POCKETS_COUNT, sBagItemUseState->savedExitCallback);
    }
    else
    {
        MainCallback exitCb = sBagItemUseState->savedExitCallback;
        BagMenu_FreeItemUseState();
        GoToBagMenu(ITEMMENULOCATION_LAST, POCKETS_COUNT, exitCb);
    }
}

static void BagMenu_DoGiveMail(u8 taskId, struct Pokemon *mon, u16 item)
{
    s16 *data = gTasks[taskId].data;

    if (GiveMailToMonByItemId(mon, item) == MAIL_NONE)
    {
        BagMenu_DisplayCannotUseMessage(taskId);
        return;
    }
    u8 itemBytes[2];
    itemBytes[0] = item;
    itemBytes[1] = item >> 8;
    SetMonData(mon, MON_DATA_HELD_ITEM, itemBytes);
    RemoveBagItem(item, 1);
    sBagMailGiveState = AllocZeroed(sizeof(*sBagMailGiveState));
    sBagMailGiveState->slot = tPartySlot;
    sBagMailGiveState->mailItem = item;
    gBagMenu->newScreenCallback = BagMenu_CB2_GiveMail;
    Task_FadeAndCloseBagMenu(taskId);
}

static void BagMenu_GiveItem(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    u16 item = gSpecialVar_ItemId;
    u16 heldItem = GetMonData(mon, MON_DATA_HELD_ITEM);
    u8 itemBytes[2];

    PlaySE(SE_SELECT);
    GetMonNickname(mon, gStringVar1);

    if (ItemIsMail(item))
    {
        if (heldItem != ITEM_NONE)
            DisplayItemMessage(taskId, FONT_NORMAL, gText_PkmnHoldingItemCantHoldMail, Task_BagMenu_PartyStayAfterMessage);
        else
            BagMenu_DoGiveMail(taskId, mon, item);
    }
    else if (heldItem == ITEM_NONE)
    {
        enum Species speciesBefore = GetMonData(mon, MON_DATA_SPECIES);
        CopyItemName(item, gStringVar2);
        itemBytes[0] = item;
        itemBytes[1] = item >> 8;
        SetMonData(mon, MON_DATA_HELD_ITEM, itemBytes);
        TryFormChange(mon, FORM_CHANGE_ITEM_HOLD, B_TRAINER_PLAYER);
        BagMenu_UpdateHeldItemIcon(tPartySlot);
        RemoveBagItem(item, 1);
        StringExpandPlaceholders(gStringVar4, gText_PkmnWasGivenItem);
        if (GetMonData(mon, MON_DATA_SPECIES) != speciesBefore)
        {
            data[9] = (s16)GetMonData(mon, MON_DATA_SPECIES);
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_AfterGiveFormChange);
        }
        else
        {
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyAfterItemUse);
        }
    }
    else
    {
        sPartyGiveSwapItem = heldItem;
        CopyItemName(heldItem, gStringVar2);
        StringExpandPlaceholders(gStringVar4, gText_PkmnAlreadyHoldingItemSwitch);
        tPartyTemp = 0;
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_GiveSwapYesNo);
    }
}

static void Task_BagMenu_GiveSwapYesNo(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tPartyTemp)
    {
    case 0:
        BagMenu_YesNo(taskId, ITEMWIN_YESNO_HIGH, &sPartyGiveSwapYesNo);
        tPartyTemp++;
        break;
    case 1:
        break;
    }
}

static void BagMenu_GiveSwapYes(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    u16 item = gSpecialVar_ItemId;
    u8 itemBytes[2];

    RemoveBagItem(item, 1);
    if (!AddBagItem(sPartyGiveSwapItem, 1))
    {
        AddBagItem(item, 1);
        StringExpandPlaceholders(gStringVar4, gText_BagFullCouldNotRemoveItem);
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyStayAfterMessage);
        return;
    }
    itemBytes[0] = item;
    itemBytes[1] = item >> 8;
    {
        enum Species speciesBefore = GetMonData(mon, MON_DATA_SPECIES);
        SetMonData(mon, MON_DATA_HELD_ITEM, itemBytes);
        TryFormChange(mon, FORM_CHANGE_ITEM_HOLD, B_TRAINER_PLAYER);
        BagMenu_UpdateHeldItemIcon(tPartySlot);
        CopyItemName(item, gStringVar1);
        CopyItemName(sPartyGiveSwapItem, gStringVar2);
        StringExpandPlaceholders(gStringVar4, gText_SwitchedPkmnItem);
        if (GetMonData(mon, MON_DATA_SPECIES) != speciesBefore)
        {
            data[9] = (s16)GetMonData(mon, MON_DATA_SPECIES);
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_AfterGiveFormChange);
        }
        else
        {
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyAfterItemUse);
        }
    }
}

static void BagMenu_GiveSwapNo(u8 taskId)
{
    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    gTasks[taskId].func = Task_BagMenu_PartyInput;
}

static void Task_BagMenu_AfterGiveFormChange(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    data[6] = 0;
    data[7] = 0;
    data[8] = MOVE_NONE;
    gTasks[taskId].func = Task_BagMenu_FormChangeAnim;
}

static void BagMenu_CB2_GiveMail(void)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][sBagMailGiveState->slot];
    u8 mail = GetMonData(mon, MON_DATA_MAIL);

    DoEasyChatScreen(
        EASY_CHAT_TYPE_MAIL,
        gSaveBlock1Ptr->mail[mail].words,
        BagMenu_CB2_AfterMailWrite,
        EASY_CHAT_PERSON_DISPLAY_NONE);
}

static void BagMenu_CB2_AfterMailWrite(void)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][sBagMailGiveState->slot];
    MainCallback exitCb = gBagPosition.exitCallback;

    if (!gSpecialVar_Result)
    {
        TakeMailFromMon(mon);
        AddBagItem(sBagMailGiveState->mailItem, 1);
    }

    Free(sBagMailGiveState);
    sBagMailGiveState = NULL;
    GoToBagMenu(ITEMMENULOCATION_LAST, POCKETS_COUNT, exitCb);
}

static void BagMenu_SpriteCB_FormChangeIconMosaic(struct Sprite *sprite)
{
    u8 taskId = sprite->data[2];

    sprite->data[0] -= sprite->data[1];

    if (sprite->data[0] <= 0)
    {
        if (gTasks[taskId].data[7] == 20)
            sprite->data[0] = 0;
        else
            sprite->data[0] = 10;
    }

    SetGpuReg(REG_OFFSET_MOSAIC, (sprite->data[0] << 12) | (sprite->data[1] << 8));

    if (sprite->data[0] == 0)
    {
        sprite->oam.mosaic = FALSE;
        sprite->callback = SpriteCB_MonIcon;
    }
}

static void Task_BagMenu_FormChangeAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 slot = tPartySlot;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][slot];

    switch (data[6])
    {
    case 0:
        PlaySE(SE_M_TELEPORT);
        data[6]++;
        break;
    case 1:
        if (data[7] == 0)
        {
            enum Species newSpecies = (u16)data[9];
            u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);
            u8 animNum;
            u8 spriteId;
            struct Sprite *icon;

            FreeAndDestroyMonIconSprite(&gSprites[gBagMenu->partyMonIconSpriteIds[slot]]);
            spriteId = CreateMonIconIsEgg(newSpecies, SpriteCB_MonIcon, 32, 24 * slot + 16, 6, personality, FALSE);
            gBagMenu->partyMonIconSpriteIds[slot] = spriteId;
            icon = &gSprites[spriteId];
            icon->oam.priority = 2;

            switch (GetHPBarLevel(GetMonData(mon, MON_DATA_HP), GetMonData(mon, MON_DATA_MAX_HP)))
            {
            case HP_BAR_FULL:   animNum = 0; break;
            case HP_BAR_GREEN:  animNum = 1; break;
            case HP_BAR_YELLOW: animNum = 2; break;
            case HP_BAR_RED:    animNum = 3; break;
            default:            animNum = 4; break;
            }
            SetPartyHPBarSprite(icon, animNum);

            icon->oam.mosaic = TRUE;
            icon->data[0] = 10;
            icon->data[1] = 1;
            icon->data[2] = taskId;
            icon->callback = BagMenu_SpriteCB_FormChangeIconMosaic;
            SetGpuReg(REG_OFFSET_MOSAIC, (icon->data[0] << 12) | (icon->data[1] << 8));
            gSprites[gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + (gBagMenu->itemIconSlot ^ 1)]].invisible = TRUE;
        }
        if (++data[7] == 60)
            data[6]++;
        break;
    case 2:
        PlayCry_Normal((u16)data[9], 0);
        data[6]++;
        break;
    case 3:
        if (IsCryFinished())
        {
            TaskFunc afterTransform = data[8] != MOVE_NONE
                ? Task_BagMenu_RotomAfterTransform
                : Task_BagMenu_PartyAfterItemUse;
            GetMonNickname(mon, gStringVar1);
            StringExpandPlaceholders(gStringVar4, gText_PkmnTransformed);
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, afterTransform);
            data[6]++;
        }
        break;
    }
}

static void BagMenu_UseFormChange(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    bool8 consumed = (gItemUseCB == ItemUseCB_FormChange_ConsumedOnUse);

    PlaySE(SE_SELECT);

    if (!TryFormChange(mon, FORM_CHANGE_ITEM_USE, B_TRAINER_PLAYER))
    {
        BagMenu_DisplayCannotUseMessage(taskId);
        return;
    }

    if (consumed)
        RemoveBagItem(gSpecialVar_ItemId, 1);

    data[6] = 0;
    data[7] = 0;
    data[8] = MOVE_NONE;
    data[9] = (s16)GetMonData(mon, MON_DATA_SPECIES);
    gTasks[taskId].func = Task_BagMenu_FormChangeAnim;
}

static bool32 BagMenu_HasMultichoiceFormChange(struct Pokemon *mon)
{
    const struct FormChange *formChanges = GetSpeciesFormChanges(GetMonData(mon, MON_DATA_SPECIES));
    u32 i;

    if (formChanges == NULL)
        return FALSE;
    for (i = 0; formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        if (formChanges[i].method == FORM_CHANGE_ITEM_USE_MULTICHOICE
            && formChanges[i].param1 == gSpecialVar_ItemId)
            return TRUE;
    }
    return FALSE;
}

static void BagMenu_UseMultichoiceFormChange(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 slot = tPartySlot;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][slot];
    enum Move moveToTeach = MOVE_NONE;

    if (!TryFormChange(mon, FORM_CHANGE_ITEM_USE_MULTICHOICE, B_TRAINER_PLAYER))
    {
        BagMenu_DisplayCannotUseMessage(taskId);
        return;
    }

    if (gSpecialVar_ItemId == ITEM_ZYGARDE_CUBE && gSpecialVar_Result == 1)
    {
        u32 newSpecies = GetMonData(mon, MON_DATA_SPECIES);
        u8 abilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM);

        PlaySE(SE_USE_ITEM);
        GetMonNickname(mon, gStringVar1);
        StringCopy(gStringVar2, gAbilitiesInfo[GetAbilityBySpecies(newSpecies, abilityNum)].name);
        StringExpandPlaceholders(gStringVar4, sText_PartyAbilityDone);
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyAfterItemUse);
        return;
    }

    if (gSpecialVar_ItemId == ITEM_ROTOM_CATALOG)
    {
        if (I_ROTOM_CATALOG_THUNDER_SHOCK < GEN_9 && gSpecialVar_0x8000 == ROTOM_BASE_MOVE)
        {
            if (!DoesMonHaveAnyMoves(mon))
                moveToTeach = ROTOM_BASE_MOVE;
        }
        else
        {
            moveToTeach = gSpecialVar_0x8000;
        }
    }

    data[6] = 0;
    data[7] = 0;
    data[8] = (s16)moveToTeach;
    data[9] = (s16)GetMonData(mon, MON_DATA_SPECIES);
    gTasks[taskId].func = Task_BagMenu_FormChangeAnim;
}

static void Task_BagMenu_RotomCatalogInput(u8 taskId)
{
    s8 input = Menu_ProcessInput();

    if (input == MENU_NOTHING_CHOSEN)
        return;

    BagMenu_RemoveWindow(ITEMWIN_ROTOM_CATALOG);

    if (input == MENU_B_PRESSED)
    {
        gTasks[taskId].func = Task_BagMenu_PartyInput;
        return;
    }

    switch (input)
    {
    case 0: gSpecialVar_Result = 0; gSpecialVar_0x8000 = ROTOM_BASE_MOVE;  break;
    case 1: gSpecialVar_Result = 1; gSpecialVar_0x8000 = ROTOM_HEAT_MOVE;  break;
    case 2: gSpecialVar_Result = 2; gSpecialVar_0x8000 = ROTOM_WASH_MOVE;  break;
    case 3: gSpecialVar_Result = 3; gSpecialVar_0x8000 = ROTOM_FROST_MOVE; break;
    case 4: gSpecialVar_Result = 4; gSpecialVar_0x8000 = ROTOM_FAN_MOVE;   break;
    case 5: gSpecialVar_Result = 5; gSpecialVar_0x8000 = ROTOM_MOW_MOVE;   break;
    }

    BagMenu_UseMultichoiceFormChange(taskId);
}

static void BagMenu_UseRotomCatalog(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    u8 windowId;
    u8 cursorDim;
    u32 i;

    if (!BagMenu_HasMultichoiceFormChange(mon))
    {
        BagMenu_DisplayCannotUseMessage(taskId);
        return;
    }

    static const u8 *const sCatalogOptionText[] = {
        COMPOUND_STRING("Light bulb"),
        COMPOUND_STRING("Microwave oven"),
        COMPOUND_STRING("Washing machine"),
        COMPOUND_STRING("Refrigerator"),
        COMPOUND_STRING("Electric fan"),
        COMPOUND_STRING("Lawn mower"),
    };

    windowId = BagMenu_AddWindow(ITEMWIN_ROTOM_CATALOG);
    cursorDim = GetMenuCursorDimensionByFont(FONT_NORMAL, 0);
    for (i = 0; i < ARRAY_COUNT(sCatalogOptionText); i++)
        AddTextPrinterParameterized(windowId, FONT_NORMAL, sCatalogOptionText[i],
            cursorDim, (i * 16) + 1, TEXT_SKIP_DRAW, NULL);
    InitMenuInUpperLeftCornerNormal(windowId, ARRAY_COUNT(sCatalogOptionText), 0);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_BagMenu_RotomCatalogInput;
}

static void Task_BagMenu_ZygardeCubeInput(u8 taskId)
{
    s8 input = Menu_ProcessInput();

    if (input == MENU_NOTHING_CHOSEN)
        return;

    BagMenu_RemoveWindow(ITEMWIN_ZYGARDE_CUBE);

    if (input == MENU_B_PRESSED)
    {
        gTasks[taskId].func = Task_BagMenu_PartyInput;
        return;
    }

    gSpecialVar_Result = (u8)input;
    BagMenu_UseMultichoiceFormChange(taskId);
}

static void BagMenu_UseZygardeCube(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    u8 windowId;
    u8 cursorDim;
    u32 i;
    static const u8 *const sZygardeOptionText[] = {
        COMPOUND_STRING("Change form"),
        COMPOUND_STRING("Change Ability"),
    };

    if (!BagMenu_HasMultichoiceFormChange(mon))
    {
        BagMenu_DisplayCannotUseMessage(taskId);
        return;
    }

    windowId = BagMenu_AddWindow(ITEMWIN_ZYGARDE_CUBE);
    cursorDim = GetMenuCursorDimensionByFont(FONT_NORMAL, 0);
    for (i = 0; i < ARRAY_COUNT(sZygardeOptionText); i++)
        AddTextPrinterParameterized(windowId, FONT_NORMAL, sZygardeOptionText[i],
            cursorDim, (i * 16) + 1, TEXT_SKIP_DRAW, NULL);
    InitMenuInUpperLeftCornerNormal(windowId, ARRAY_COUNT(sZygardeOptionText), 0);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_BagMenu_ZygardeCubeInput;
}

static void Task_BagMenu_RotomAfterTransform(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 slot = tPartySlot;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][slot];
    enum Move moveToTeach = (u16)data[8];
    u32 i;

    RemoveItemMessageWindow(ITEMWIN_MESSAGE);

    for (i = 0; i < ARRAY_COUNT(sBagRotomFormChangeMoves); i++)
        DeleteMove(mon, sBagRotomFormChangeMoves[i]);

    if (moveToTeach == MOVE_NONE)
    {
        Task_BagMenu_PartyAfterItemUse(taskId);
        return;
    }

    if (sBagItemUseState == NULL)
        sBagItemUseState = AllocZeroed(sizeof(*sBagItemUseState));

    sBagItemUseState->slot = slot;
    sBagItemUseState->moveToLearn = moveToTeach;
    sBagItemUseState->savedExitCallback = gBagPosition.exitCallback;
    sBagItemUseState->moveLearnContinue = Task_BagMenu_MoveLearnDone;

    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, GetMoveName(moveToTeach));

    if (GiveMoveToMon(mon, moveToTeach) == MON_HAS_MAX_MOVES)
    {
        StringExpandPlaceholders(gStringVar4, gText_PkmnNeedsToReplaceMove);
        tPartyTemp = 0;
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_RotomMoveReplaceYesNo);
    }
    else
    {
        StringExpandPlaceholders(gStringVar4, gText_PkmnLearnedMove3);
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_MoveLearnFanfare);
    }
}

static void Task_BagMenu_RotomMoveReplaceYesNo(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tPartyTemp)
    {
    case 0:
        BagMenu_YesNo(taskId, ITEMWIN_YESNO_HIGH, &sPartyRotomMoveReplaceYesNo);
        tPartyTemp++;
        break;
    case 1:
        break;
    }
}

static void BagMenu_RotomMoveReplaceYes(u8 taskId)
{
    GetMonNickname(&gParties[B_TRAINER_PLAYER][sBagItemUseState->slot], gStringVar1);
    StringCopy(gStringVar2, GetMoveName(sBagItemUseState->moveToLearn));
    StringExpandPlaceholders(gStringVar4, gText_WhichMoveToForget);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_MoveLearnGoToSummary);
}

static void BagMenu_RotomMoveReplaceNo(u8 taskId)
{
    GetMonNickname(&gParties[B_TRAINER_PLAYER][sBagItemUseState->slot], gStringVar1);
    StringCopy(gStringVar2, GetMoveName(sBagItemUseState->moveToLearn));
    StringExpandPlaceholders(gStringVar4, gText_MoveNotLearned);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_MoveLearnNotLearned);
}

static void BagMenu_RestoreFusionMon(struct Pokemon *mon)
{
    s32 i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES) == SPECIES_NONE)
            break;
    }
    if (i >= PARTY_SIZE)
        CopyMonToPC(mon);
    else
    {
        CopyMon(&gParties[B_TRAINER_PLAYER][i], mon, sizeof(*mon));
        gPartiesCount[B_TRAINER_PLAYER] = i + 1;
    }
}

static void BagMenu_DeleteInvalidFusionMoves(struct Pokemon *mon, u16 species)
{
    u32 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u32 j;
        enum Move move = GetMonData(mon, MON_DATA_MOVE1 + i);
        bool32 toDelete = TRUE;
        const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);
        for (j = 0; learnset[j].move != LEVEL_UP_MOVE_END; j++)
        {
            if (learnset[j].move == move)
            {
                toDelete = FALSE;
                break;
            }
        }
        if (!toDelete)
            continue;
        {
            const u16 *learnset2 = GetSpeciesTeachableLearnset(species);
            for (j = 0; learnset2[j] != MOVE_UNAVAILABLE; j++)
            {
                if (learnset2[j] == move)
                {
                    toDelete = FALSE;
                    break;
                }
            }
        }
        if (!toDelete)
            continue;
        {
            const u16 *learnset3 = GetSpeciesEggMoves(species);
            for (j = 0; learnset3[j] != MOVE_UNAVAILABLE; j++)
            {
                if (learnset3[j] == move)
                {
                    toDelete = FALSE;
                    break;
                }
            }
        }
        if (toDelete)
            DeleteMove(mon, move);
    }
}

#if P_FUSION_FORMS
static void BagMenu_SwapFusionMonMoves(struct Pokemon *mon, const u16 moveTable[][2], u32 mode)
{
    u32 i;
    u32 oldMoveIndex = (mode == BAG_FUSE_MON) ? 0 : 1;
    u32 newMoveIndex = (mode == BAG_FUSE_MON) ? 1 : 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u32 j;
        enum Move move = GetMonData(mon, MON_DATA_MOVE1 + i);
        for (j = 0; j < 2; j++)
        {
            if (move == moveTable[j][oldMoveIndex])
            {
                u32 pp = GetMovePP(moveTable[j][newMoveIndex]);
                SetMonData(mon, MON_DATA_MOVE1 + i, &moveTable[j][newMoveIndex]);
                SetMonData(mon, MON_DATA_PP1 + i, &pp);
            }
        }
    }
}
#endif // P_FUSION_FORMS

static void Task_BagMenu_FusionAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 slot = sBagFusionState->firstFusionSlot;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][slot];

    switch (data[6])
    {
    case 0:
    {
        u16 fusionResult = sBagFusionState->fusionResult;
        if (sBagFusionState->fusionType == BAG_FUSE_MON)
        {
            u8 slot2 = sBagFusionState->secondFusionSlot;
            struct Pokemon *mon2 = &gParties[B_TRAINER_PLAYER][slot2];
            CopyMon(&gPokemonStoragePtr->fusions[sBagFusionState->storageIndex], mon2, sizeof(*mon2));
            ZeroMonData(&gParties[B_TRAINER_PLAYER][slot2]);
            SetMonData(mon, MON_DATA_SPECIES, &fusionResult);
        }
        else
        {
            struct Pokemon *stored = &gPokemonStoragePtr->fusions[sBagFusionState->storageIndex];
            BagMenu_RestoreFusionMon(stored);
            ZeroMonData(&gPokemonStoragePtr->fusions[sBagFusionState->storageIndex]);
            SetMonData(mon, MON_DATA_SPECIES, &fusionResult);
        }
        CalculateMonStats(mon);
        CompactPartySlots();
        CalculatePlayerPartyCount();
        PlaySE(SE_M_TELEPORT);
        data[7] = 0;
        data[6]++;
        break;
    }
    case 1:
        if (data[7] == 0)
        {
            u8 iconSpriteId = gBagMenu->partyMonIconSpriteIds[slot];
            struct Sprite *icon = &gSprites[iconSpriteId];
            icon->oam.mosaic = TRUE;
            icon->data[0] = 10;
            icon->data[1] = 1;
            icon->data[2] = taskId;
            icon->callback = BagMenu_SpriteCB_FormChangeIconMosaic;
            SetGpuReg(REG_OFFSET_MOSAIC, (icon->data[0] << 12) | (icon->data[1] << 8));
            if (sBagFusionState->fusionType == BAG_FUSE_MON)
            {
                u8 icon2SpriteId = gBagMenu->partyMonIconSpriteIds[sBagFusionState->secondFusionSlot];
                struct Sprite *icon2 = &gSprites[icon2SpriteId];
                icon2->oam.mosaic = TRUE;
                icon2->data[0] = 10;
                icon2->data[1] = 1;
                icon2->data[2] = taskId;
                icon2->callback = BagMenu_SpriteCB_FormChangeIconMosaic;
            }
            gSprites[gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + (gBagMenu->itemIconSlot ^ 1)]].invisible = TRUE;
        }
        if (++data[7] == 60)
        {
            if (sBagFusionState->fusionType == BAG_FUSE_MON
                && sBagFusionState->firstFusionSlot > sBagFusionState->secondFusionSlot)
            {
                sBagFusionState->firstFusionSlot--;
            }
            BagMenu_FreePartyIcons();
            DecompressDataWithHeaderWram(sBagScreen_BG2TileMap, gBagMenu->mainTilemapBuffer);
            BagMenu_DrawPartySlots();
            if (BagMenu_IsMultiFull())
                ShowMultiBattleSwapPrompt(TRUE);
            BagMenu_CreatePartyIcons();
            ScheduleBgCopyTilemapToVram(2);
            data[6]++;
        }
        break;
    case 2:
        PlayCry_Normal(sBagFusionState->fusionResult, 0);
        data[6]++;
        break;
    case 3:
        if (IsCryFinished())
        {
            GetMonNickname(&gParties[B_TRAINER_PLAYER][sBagFusionState->firstFusionSlot], gStringVar1);
            StringExpandPlaceholders(gStringVar4, gText_PkmnTransformed);
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_FusionAfterAnim);
            data[6]++;
        }
        break;
    }
}

static void Task_BagMenu_FusionAfterAnim(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 slot = sBagFusionState->firstFusionSlot;
    u8 fusionType = sBagFusionState->fusionType;
    u8 extraMoveHandling = sBagFusionState->extraMoveHandling;
    u16 moveToLearn = sBagFusionState->moveToLearn;
    u16 fusionResult = sBagFusionState->fusionResult;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][slot];

    tPartySlot = slot;
    Free(sBagFusionState);
    sBagFusionState = NULL;

    RemoveItemMessageWindow(ITEMWIN_MESSAGE);

#if P_FUSION_FORMS
#if P_FAMILY_KYUREM
#if P_FAMILY_RESHIRAM
    if (extraMoveHandling == SWAP_EXTRA_MOVES_KYUREM_WHITE)
        BagMenu_SwapFusionMonMoves(mon, gKyuremWhiteSwapMoveTable, fusionType);
#endif
#if P_FAMILY_ZEKROM
    if (extraMoveHandling == SWAP_EXTRA_MOVES_KYUREM_BLACK)
        BagMenu_SwapFusionMonMoves(mon, gKyuremBlackSwapMoveTable, fusionType);
#endif
#endif
#endif

    if (fusionType == BAG_UNFUSE_MON && extraMoveHandling == FORGET_EXTRA_MOVES)
    {
        BagMenu_DeleteInvalidFusionMoves(mon, fusionResult);
        if (!DoesMonHaveAnyMoves(mon))
            moveToLearn = MOVE_CONFUSION;
    }

    if (moveToLearn != MOVE_NONE)
    {
        if (sBagItemUseState == NULL)
            sBagItemUseState = AllocZeroed(sizeof(*sBagItemUseState));
        sBagItemUseState->slot = slot;
        sBagItemUseState->moveToLearn = moveToLearn;
        sBagItemUseState->savedExitCallback = gBagPosition.exitCallback;
        sBagItemUseState->moveLearnContinue = Task_BagMenu_FusionMoveLearnDone;

        GetMonNickname(mon, gStringVar1);
        StringCopy(gStringVar2, GetMoveName(moveToLearn));

        if (GiveMoveToMon(mon, moveToLearn) == MON_HAS_MAX_MOVES)
        {
            StringExpandPlaceholders(gStringVar4, gText_PkmnNeedsToReplaceMove);
            tPartyTemp = 0;
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_RotomMoveReplaceYesNo);
        }
        else
        {
            StringExpandPlaceholders(gStringVar4, gText_PkmnLearnedMove3);
            DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_MoveLearnFanfare);
        }
    }
    else
    {
        BagMenu_ClosePartySelect(taskId);
    }
}

static void Task_BagMenu_FusionMoveLearnDone(u8 taskId)
{
    BagMenu_FreeItemUseState();
    BagMenu_ClosePartySelect(taskId);
}

static void BagMenu_UseFusion(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 slot = tPartySlot;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][slot];
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    const struct Fusion *itemFusion = gFusionTablePointers[species];
    u16 i;

    PlaySE(SE_SELECT);

    switch (IsFusionMon(species))
    {
    case BAG_FUSE_MON:
        for (i = 0; itemFusion[i].fusionStorageIndex != FUSION_TERMINATOR; i++)
        {
            if (itemFusion[i].itemId != gSpecialVar_ItemId)
                continue;
            sBagFusionState = AllocZeroed(sizeof(*sBagFusionState));
            sBagFusionState->firstFusionSlot = slot;
            sBagFusionState->storageIndex = itemFusion[i].fusionStorageIndex;
            sBagFusionState->fusionType = BAG_FUSE_MON;
            BagMenu_ApplyFusionStage2Blend(slot);
            gTasks[taskId].func = Task_BagMenu_FusionAwaitSecond;
            return;
        }
        break;
    case BAG_UNFUSE_MON:
        if (gPartiesCount[B_TRAINER_PLAYER] >= PARTY_SIZE)
        {
            DisplayItemMessage(taskId, FONT_NORMAL, gText_YourPartysFull, Task_BagMenu_PartyStayAfterMessage);
            return;
        }
        for (i = 0; itemFusion[i].fusionStorageIndex != FUSION_TERMINATOR; i++)
        {
            if (gPokemonStoragePtr->fusions[itemFusion[i].fusionStorageIndex].level == 0)
                continue;
            if (itemFusion[i].itemId != gSpecialVar_ItemId)
                continue;
            if (GetMonData(&gPokemonStoragePtr->fusions[itemFusion[i].fusionStorageIndex], MON_DATA_SPECIES) != itemFusion[i].targetSpecies2)
                continue;
            sBagFusionState = AllocZeroed(sizeof(*sBagFusionState));
            sBagFusionState->firstFusionSlot = slot;
            sBagFusionState->storageIndex = itemFusion[i].fusionStorageIndex;
            sBagFusionState->fusionType = BAG_UNFUSE_MON;
            sBagFusionState->fusionResult = itemFusion[i].targetSpecies1;
            sBagFusionState->extraMoveHandling = itemFusion[i].extraMoveHandling;
            sBagFusionState->moveToLearn = MOVE_NONE;
            data[6] = 0;
            data[7] = 0;
            gTasks[taskId].func = Task_BagMenu_FusionAnim;
            return;
        }
        break;
    }
    BagMenu_DisplayCannotUseMessage(taskId);
}

static void Task_BagMenu_FusionStayAfterMessage(u8 taskId)
{
    RemoveItemMessageWindow(ITEMWIN_MESSAGE);
    gTasks[taskId].func = Task_BagMenu_FusionAwaitSecond;
}

static void Task_BagMenu_FusionAwaitSecond(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 partyCount = CalculatePlayerPartyCount();
    u8 iconSpriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM + (gBagMenu->itemIconSlot ^ 1)];

    if (iconSpriteId != SPRITE_NONE && sPartyItemIconAnimId != INVALID_COMFY_ANIM)
        gSprites[iconSpriteId].y2 = ReadComfyAnimValueSmooth(&gComfyAnims[sPartyItemIconAnimId]);

    if (sPartyItemIconAnimId != INVALID_COMFY_ANIM && !gComfyAnims[sPartyItemIconAnimId].completed)
        return;

    if (JOY_NEW(DPAD_DOWN))
    {
        BagMenu_SetPartySlotPalette(tPartySlot, 0);
        tPartySlot = (tPartySlot == partyCount - 1) ? 0 : tPartySlot + 1;
        BagMenu_SetPartySlotPalette(tPartySlot, 2);
        PlaySE(SE_SELECT);
        if (iconSpriteId != SPRITE_NONE)
            BagMenu_PartyStartItemIconYAnim(&gSprites[iconSpriteId], PARTY_ITEM_ICON_Y(tPartySlot));
    }
    else if (JOY_NEW(DPAD_UP))
    {
        BagMenu_SetPartySlotPalette(tPartySlot, 0);
        tPartySlot = (tPartySlot == 0) ? partyCount - 1 : tPartySlot - 1;
        BagMenu_SetPartySlotPalette(tPartySlot, 2);
        PlaySE(SE_SELECT);
        if (iconSpriteId != SPRITE_NONE)
            BagMenu_PartyStartItemIconYAnim(&gSprites[iconSpriteId], PARTY_ITEM_ICON_Y(tPartySlot));
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        Free(sBagFusionState);
        sBagFusionState = NULL;
        BagMenu_ClosePartySelect(taskId);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if (GetMonData(BagMenu_GetPanelMon(tPartySlot), MON_DATA_IS_EGG))
        {
            PlaySE(SE_FAILURE);
            return;
        }
        BagMenu_UseFusionSecond(taskId);
    }
}

static void BagMenu_UseFusionSecond(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 slot2 = tPartySlot;
    struct Pokemon *mon1 = &gParties[B_TRAINER_PLAYER][sBagFusionState->firstFusionSlot];
    struct Pokemon *mon2 = &gParties[B_TRAINER_PLAYER][slot2];
    enum Species species1 = GetMonData(mon1, MON_DATA_SPECIES);
    enum Species species2 = GetMonData(mon2, MON_DATA_SPECIES);
    const struct Fusion *itemFusion = gFusionTablePointers[species2];
    u16 i;

    if (itemFusion == NULL || IsFusionMon(species2) != BAG_SECOND_FUSE_MON)
    {
        DisplayItemMessage(taskId, FONT_NORMAL, gText_WontHaveEffect, Task_BagMenu_FusionStayAfterMessage);
        return;
    }

    for (i = 0; itemFusion[i].fusionStorageIndex != FUSION_TERMINATOR; i++)
    {
        if (gPokemonStoragePtr->fusions[itemFusion[i].fusionStorageIndex].level != 0)
            continue;
        if (itemFusion[i].itemId != gSpecialVar_ItemId)
            continue;
        if (itemFusion[i].targetSpecies1 != species1)
            continue;
        if (itemFusion[i].targetSpecies2 != species2)
            continue;
        sBagFusionState->secondFusionSlot = slot2;
        sBagFusionState->storageIndex = itemFusion[i].fusionStorageIndex;
        sBagFusionState->fusionResult = itemFusion[i].fusingIntoMon;
        sBagFusionState->moveToLearn = itemFusion[i].fusionMove;
        sBagFusionState->extraMoveHandling = itemFusion[i].extraMoveHandling;
        data[6] = 0;
        data[7] = 0;
        gTasks[taskId].func = Task_BagMenu_FusionAnim;
        return;
    }
    DisplayItemMessage(taskId, FONT_NORMAL, gText_WontHaveEffect, Task_BagMenu_FusionStayAfterMessage);
}

static void Task_BagMenu_TMHMLearnDone(u8 taskId)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][sBagItemUseState->slot];
    bool32 learned = MonKnowsMove(mon, sBagItemUseState->moveToLearn);

    if (learned)
    {
        AdjustFriendship(mon, FRIENDSHIP_EVENT_LEARN_TMHM);
        if (!GetItemImportance(gSpecialVar_ItemId))
            RemoveBagItem(gSpecialVar_ItemId, 1);
    }
    BagMenu_FreeItemUseState();
    Task_BagMenu_PartyAfterItemUse(taskId);
}

static void BagMenu_UseTMHM(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 item = gSpecialVar_ItemId;
    enum Move move = ItemIdToBattleMoveId(item);
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    enum Species species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG);

    GetMonNickname(mon, gStringVar1);
    StringCopy(gStringVar2, GetMoveName(move));

    if (GetMonData(mon, MON_DATA_IS_EGG) || !CanLearnTeachableMove(species, move))
    {
        DisplayItemMessage(taskId, FONT_NORMAL, gText_PkmnCantLearnMove, Task_BagMenu_PartyStayAfterMessage);
        return;
    }

    if (MonKnowsMove(mon, move))
    {
        DisplayItemMessage(taskId, FONT_NORMAL, gText_PkmnAlreadyKnows, Task_BagMenu_PartyStayAfterMessage);
        return;
    }

    if (sBagItemUseState == NULL)
        sBagItemUseState = AllocZeroed(sizeof(*sBagItemUseState));

    sBagItemUseState->slot = tPartySlot;
    sBagItemUseState->moveToLearn = move;
    sBagItemUseState->savedExitCallback = gBagPosition.exitCallback;
    sBagItemUseState->moveLearnContinue = Task_BagMenu_TMHMLearnDone;

    if (GiveMoveToMon(mon, move) != MON_HAS_MAX_MOVES)
    {
        StringExpandPlaceholders(gStringVar4, gText_PkmnLearnedMove3);
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_MoveLearnFanfare);
    }
    else
    {
        StringExpandPlaceholders(gStringVar4, gText_PkmnNeedsToReplaceMove);
        tPartyTemp = 0;
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_RotomMoveReplaceYesNo);
    }
}

static s16 BagMenu_ComputeMultiUseMax(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][tPartySlot];
    enum Item item = gSpecialVar_ItemId;
    s16 bagQty = CountTotalItemQuantityInBag(item);

    if (gItemUseCB == ItemUseCB_Medicine)
    {
        enum ItemEffectType effectType = GetItemEffectType(item);
        u32 evIncrease;
        u32 ev;
        u32 evCount;
        u32 maxAllowedEVs;
        u32 remainingStatEVs;
        u32 remainingTotalEVs;

        switch (effectType)
        {
        case ITEM_EFFECT_HP_EV:
            if (HasShedinjaHPHandling(GetMonData(mon, MON_DATA_SPECIES)))
                return 0;
            break;
        case ITEM_EFFECT_ATK_EV:
        case ITEM_EFFECT_DEF_EV:
        case ITEM_EFFECT_SPEED_EV:
        case ITEM_EFFECT_SPATK_EV:
        case ITEM_EFFECT_SPDEF_EV:
            break;
        default:
            return 0;
        }

        evIncrease = GetItemEffect(item)[6];
        ev = BagMenu_GetMonEV(mon, effectType);
        evCount = GetMonEVCount(mon);
        maxAllowedEVs = B_EV_ITEMS_CAP ? GetCurrentEVCap() : MAX_TOTAL_EVS;
        remainingStatEVs  = MAX_PER_STAT_EVS - ev;
        remainingTotalEVs = maxAllowedEVs - evCount;

        if (remainingStatEVs == 0 || remainingTotalEVs == 0)
            return 0;

        return (s16)min(bagQty, min(
            (remainingStatEVs  + evIncrease - 1) / evIncrease,
            (remainingTotalEVs + evIncrease - 1) / evIncrease));
    }

    if (gItemUseCB == ItemUseCB_ReduceEV)
    {
        enum ItemEffectType effectType = GetItemEffectType(item);
        u32 ev = BagMenu_GetMonEV(mon, effectType);
        s16 max;

        if (ev <= 10)
            return 0;

        max = (I_BERRY_EV_JUMP == GEN_4 && ev > 100) ? 11 : (s16)((ev + 9) / 10);
        return min(bagQty, max);
    }

    if (gItemUseCB == ItemUseCB_RareCandy)
    {
        u8 level = GetMonData(mon, MON_DATA_LEVEL);
        u8 holdEffectParam = GetItemHoldEffectParam(item);

        if (holdEffectParam == 0)
        {
            if (B_RARE_CANDY_CAP && level >= GetCurrentLevelCap())
                return 0;
            if (level >= MAX_LEVEL)
                return 0;
            return B_RARE_CANDY_CAP ? (s16)min(bagQty, GetCurrentLevelCap() - level) : bagQty;
        }
        else
        {
            if (level >= MAX_LEVEL)
                return 0;
            return bagQty;
        }
    }

    return 0;
}

static void BagMenu_TryMultiUse(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s16 bagQty = CountTotalItemQuantityInBag(gSpecialVar_ItemId);
    s16 max = BagMenu_ComputeMultiUseMax(taskId);

    tItemCount = 1;

    if (max <= 1 || bagQty <= 1)
    {
        BagMenu_UseItem(taskId);
        return;
    }

    tMultiUseMax = max;
    StringExpandPlaceholders(gStringVar4, sText_UseHowMany);
    DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, BagMenu_InitMultiUseInput);
}

static void BagMenu_InitMultiUseInput(u8 taskId)
{
    CreateQuantityFrameSprites(96);
    PrintQuantity(BagMenu_AddWindowNoFrame(ITEMWIN_SELL_QUANTITY), 1);
    gTasks[taskId].func = Task_BagMenu_MultiUseInput;
}

static void Task_BagMenu_MultiUseInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, tMultiUseMax) == TRUE)
    {
        PrintQuantity(gBagMenu->windowIds[ITEMWIN_SELL_QUANTITY], tItemCount);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        DestroyQuantityFrameSprites();
        BagMenu_RemoveWindow(ITEMWIN_SELL_QUANTITY);
        RemoveItemMessageWindow(ITEMWIN_MESSAGE);
        BagMenu_UseItem(taskId);
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        DestroyQuantityFrameSprites();
        BagMenu_RemoveWindow(ITEMWIN_SELL_QUANTITY);
        RemoveItemMessageWindow(ITEMWIN_MESSAGE);
        tItemCount = 1;
        gTasks[taskId].func = Task_BagMenu_PartyInput;
    }
}

#if SWSH_ITEM_MENU_ACTION_IN_BATTLE
static bool8 BagMenu_IsItemFlute(enum Item item)
{
    return item == ITEM_BLUE_FLUTE || item == ITEM_RED_FLUTE || item == ITEM_YELLOW_FLUTE;
}
#endif

static bool8 BagMenu_InBattleSelect(void)
{
#if SWSH_ITEM_MENU_ACTION_IN_BATTLE
    return gBagPosition.location == ITEMMENULOCATION_BATTLE
        || gBagPosition.location == ITEMMENULOCATION_WALLY;
#else
    return FALSE;
#endif
}

#if SWSH_ITEM_MENU_ACTION_IN_BATTLE
static bool8 BagMenu_IsMultiFull(void)
{
    return BagMenu_InBattleSelect() && IsMultiBattle() && AreMultiPartiesFullTeams();
}

static u8 BagMenu_FullMultiPartyId(u8 slot)
{
    enum BattlerId battler = (sMultiFullPage != 0) ? B_BATTLER_2 : gBattlerInMenuId;
    const u8 *order = gBattleStruct->battlerPartyOrders[battler];
    u8 packed = order[slot / 2];
    return (slot & 1) ? (packed & 0xF) : (packed >> 4);
}
#endif // SWSH_ITEM_MENU_ACTION_IN_BATTLE

static bool8 BagMenu_SlotIsPartner(u8 slot)
{
    if (!BagMenu_InBattleSelect() || !IsMultiBattle())
        return FALSE;
    if (AreMultiPartiesFullTeams())
        return sMultiFullPage != 0;
    return slot >= MULTI_PARTY_SIZE;
}

static u8 BagMenu_MultiGroupIndex(bool8 partner, u8 pos)
{
    const u8 *order = gBattleStruct->battlerPartyOrders[gBattlerInMenuId];
    u8 lo = partner ? MULTI_PARTY_SIZE : 0;
    u8 found = 0, i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u8 id = (i & 1) ? (order[i / 2] & 0xF) : (order[i / 2] >> 4);
        if (id >= lo && id < lo + MULTI_PARTY_SIZE)
        {
            if (found == pos)
                return id - lo;
            found++;
        }
    }
    return pos;
}

static u8 BagMenu_PartyIdFromSlot(u8 slot)
{
    u8 packed;

    if (!BagMenu_InBattleSelect())
        return slot;

    if (IsMultiBattle())
    {
#if SWSH_ITEM_MENU_ACTION_IN_BATTLE
        if (AreMultiPartiesFullTeams())
            return BagMenu_FullMultiPartyId(slot);
#endif
        if (slot >= MULTI_PARTY_SIZE)
            return BagMenu_MultiGroupIndex(TRUE, slot - MULTI_PARTY_SIZE);
        return BagMenu_MultiGroupIndex(FALSE, slot);
    }

    packed = gBattlePartyCurrentOrder[slot / 2];
    return (slot & 1) ? (packed & 0xF) : (packed >> 4);
}

static struct Pokemon *BagMenu_GetPanelMon(u8 slot)
{
    if (BagMenu_SlotIsPartner(slot))
        return &gParties[B_TRAINER_PARTNER][BagMenu_PartyIdFromSlot(slot)];
    return &gParties[B_TRAINER_PLAYER][BagMenu_PartyIdFromSlot(slot)];
}

static u8 BagMenu_PanelSlotLimit(void)
{
    if (BagMenu_InBattleSelect() && IsMultiBattle())
    {
        if (AreMultiPartiesFullTeams())
            return (sMultiFullPage != 0) ? CalculatePartnerPartyCount() : CalculatePartyCount(B_TRAINER_PLAYER);
        return PARTY_SIZE;
    }
    return CalculatePlayerPartyCount();
}

static bool8 BagMenu_PanelSlotOccupied(u8 slot)
{
    return GetMonData(BagMenu_GetPanelMon(slot), MON_DATA_SPECIES) != SPECIES_NONE;
}

static u8 BagMenu_StepSlot(u8 cur, s8 dir, u8 limit)
{
    s32 next = cur;
    u8 i;

    if (limit == 0)
        return cur;
    for (i = 0; i < limit; i++)
    {
        next = (next + dir + limit) % limit;
        if (BagMenu_PanelSlotOccupied((u8)next))
            return (u8)next;
    }
    return cur;
}

#if SWSH_ITEM_MENU_ACTION_IN_BATTLE
#define MULTI_FULL_SWAP_TILES 12
#define tSwapPhase  tPartyTemp  // data[6]: 0 = sliding out, 1 = sliding in
#define tSwapFrame  data[7]

static void ShowMultiBattleSwapPrompt(bool8 show)
{
    u8 i;

    if (sMultiSwapPromptSpriteIds[0] == SPRITE_NONE)
    {
        for (i = 0; i < 2; i++)
        {
            sMultiSwapPromptSpriteIds[i] = CreateSprite(&sSpriteTemplate_MultiSwapPrompt, 56 + i * 32, 8, 0);
            StartSpriteAnim(&gSprites[sMultiSwapPromptSpriteIds[i]], i);
        }
    }
    for (i = 0; i < 2; i++)
        gSprites[sMultiSwapPromptSpriteIds[i]].invisible = !show;
}

static void BagMenu_MoveMultiFullSlotSprites(u8 slot, s16 x2)
{
    u8 iconId = gBagMenu->partyMonIconSpriteIds[slot];
    u8 statusId = sStatusIconSpriteIds[slot];

    if (iconId != SPRITE_NONE)
        gSprites[iconId].x2 = x2;
    if (statusId != SPRITE_NONE)
        gSprites[statusId].x2 = x2;
}

static s16 BagMenu_MultiFullSlideOffset(u8 slot, s16 frame)
{
    s16 elapsed = frame - slot;

    if (elapsed < 0)
        elapsed = 0;
    if (elapsed > MULTI_FULL_SWAP_TILES)
        elapsed = MULTI_FULL_SWAP_TILES;
    return elapsed;
}

static void BagMenu_MultiFullFlipPage(void)
{
    u8 i;

    sMultiFullPage ^= 1;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (gBagMenu->partyMonIconSpriteIds[i] != SPRITE_NONE)
        {
            FreeAndDestroyMonIconSprite(&gSprites[gBagMenu->partyMonIconSpriteIds[i]]);
            gBagMenu->partyMonIconSpriteIds[i] = SPRITE_NONE;
        }
    }

    DecompressDataWithHeaderWram(sBagScreen_BG2TileMap, gBagMenu->mainTilemapBuffer);
    BagMenu_DrawPartySlots();
    ShowMultiBattleSwapPrompt(TRUE);
    ScheduleBgCopyTilemapToVram(2);

    for (i = 0; i < PARTY_SIZE; i++)
        BagMenu_CreatePanelMonIcon(i, -8 * MULTI_FULL_SWAP_TILES);

    BagMenu_UpdateStatusIcons();
    BagMenu_UpdateStatusIconPos(PARTY_SIZE);
    for (i = 0; i < PARTY_SIZE; i++)
        BagMenu_MoveMultiFullSlotSprites(i, -8 * MULTI_FULL_SWAP_TILES);
}

static void BagMenu_StartMultiFullSwap(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    PlaySE(SE_M_HARDEN);
    tSwapPhase = 0;
    tSwapFrame = 0;
    gTasks[taskId].func = Task_BagMenu_MultiFullSwap;
}

static void Task_BagMenu_MultiFullSwap(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s16 frame = tSwapFrame;
    bool8 done = frame >= (PARTY_SIZE - 1) + MULTI_FULL_SWAP_TILES;
    u8 i;

    if (tSwapPhase == 0) // slide out
    {
        for (i = 0; i < PARTY_SIZE; i++)
            BagMenu_MoveMultiFullSlotSprites(i, -8 * BagMenu_MultiFullSlideOffset(i, frame));

        if (done)
        {
            BagMenu_MultiFullFlipPage();
            tSwapPhase = 1;
            tSwapFrame = 0;
            return;
        }
    }
    else // slide in
    {
        for (i = 0; i < PARTY_SIZE; i++)
            BagMenu_MoveMultiFullSlotSprites(i, -8 * (MULTI_FULL_SWAP_TILES - BagMenu_MultiFullSlideOffset(i, frame)));

        if (done)
        {
            for (i = 0; i < PARTY_SIZE; i++)
                BagMenu_MoveMultiFullSlotSprites(i, 0);
            tPartySlot = 0;
            gTasks[taskId].func = Task_BagMenu_HandleInput;
            return;
        }
    }
    tSwapFrame++;
}

#undef tSwapPhase
#undef tSwapFrame
#endif // SWSH_ITEM_MENU_ACTION_IN_BATTLE

#if SWSH_ITEM_MENU_ACTION_IN_BATTLE
static u8 BagMenu_BattleTargetSlotId(bool8 partner, u8 partyIndex)
{
    if (IsMultiBattle())
    {
        u8 battler = partner ? BATTLE_PARTNER(gBattlerInMenuId) : gBattlerInMenuId;
        if (gBattlerPartyIndexes[battler] != partyIndex)
            return PARTY_SIZE;
        return (GetBattlerPosition(battler) == B_POSITION_PLAYER_RIGHT) ? 1 : 0;
    }
    if (gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)] == partyIndex)
        return 0;
    if (IsDoubleBattle() && gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT)] == partyIndex)
        return 1;
    return PARTY_SIZE;
}

static void BagMenu_UseBattleItem(u8 taskId)
{
    if (gItemUseCB == ItemUseCB_BattleChooseMove)
        BagMenu_ShowPPMoveSelectWindow(taskId);
    else
        BagMenu_BattleApplyItem(taskId, MAX_MON_MOVES, FALSE);
}

static void BagMenu_BattleUsePPOnMove(u8 taskId, u8 moveSlot)
{
    BagMenu_BattleApplyItem(taskId, moveSlot, TRUE);
}

static void BagMenu_BattleApplyItem(u8 taskId, u8 moveSlot, bool8 chooseMove)
{
    s16 *data = gTasks[taskId].data;
    bool8 partner = BagMenu_SlotIsPartner(tPartySlot);
    u8 partyId = BagMenu_PartyIdFromSlot(tPartySlot);
    struct Pokemon *mon = BagMenu_GetPanelMon(tPartySlot);
    enum Item item = gSpecialVar_ItemId;

    gPartyMenu.slotId = BagMenu_BattleTargetSlotId(partner, partyId);
    gPartyMenu.menuType = PARTY_MENU_TYPE_IN_BATTLE;
    if (chooseMove)
        gPartyMenu.data1 = moveSlot;

    if (CannotUseItemsInBattle(item, mon))
    {
        PlaySE(SE_SELECT);
        DisplayItemMessage(taskId, FONT_NORMAL, gStringVar4, Task_BagMenu_PartyStayAfterMessage);
        return;
    }

    gBattleStruct->itemPartyIndex[gBattlerInMenuId] = partyId;
    gBattleStruct->itemTargetPartner[gBattlerInMenuId] = partner;
    if (chooseMove)
        gBattleStruct->itemMoveIndex[gBattlerInMenuId] = moveSlot;
    gPartyMenuUseExitCallback = TRUE;
    PlaySE(SE_SELECT);
    if (!BagMenu_IsItemFlute(item))
        RemoveBagItem(item, 1);

    Task_FadeAndCloseBagMenu(taskId);
}
#endif // SWSH_ITEM_MENU_ACTION_IN_BATTLE

static void BagMenu_UseItem(u8 taskId)
{
    if (gItemUseCB == ItemUseCB_Medicine)
        BagMenu_UseMedicine(taskId);
    else if (gItemUseCB == ItemUseCB_AbilityCapsule)
        BagMenu_UseAbilityCapsule(taskId);
    else if (gItemUseCB == ItemUseCB_AbilityPatch)
        BagMenu_UseAbilityPatch(taskId);
    else if (gItemUseCB == ItemUseCB_Mint)
        BagMenu_UseMint(taskId);
    else if (gItemUseCB == ItemUseCB_ResetEVs)
        BagMenu_UseResetEVs(taskId);
    else if (gItemUseCB == ItemUseCB_ReduceEV)
        BagMenu_UseReduceEV(taskId);
    else if (gItemUseCB == ItemUseCB_PPUp)
        BagMenu_ShowPPMoveSelectWindow(taskId);
    else if (gItemUseCB == ItemUseCB_PPRecovery)
    {
        const u8 *effect = GetItemEffect(gSpecialVar_ItemId);
        if (effect != NULL && (effect[4] & ITEM4_HEAL_PP_ONE))
            BagMenu_ShowPPMoveSelectWindow(taskId);
        else
            BagMenu_UsePPOnMove(taskId, 0);
    }
    else if (gItemUseCB == ItemUseCB_RareCandy)
        BagMenu_UseRareCandy(taskId);
    else if (gItemUseCB == ItemUseCB_DynamaxCandy)
        BagMenu_UseDynamaxCandy(taskId);
    else if (gItemUseCB == ItemUseCB_EvolutionStone)
        BagMenu_UseEvolutionStone(taskId);
    else if (gItemUseCB == ItemUseCB_FormChange || gItemUseCB == ItemUseCB_FormChange_ConsumedOnUse)
        BagMenu_UseFormChange(taskId);
    else if (gItemUseCB == ItemUseCB_RotomCatalog)
        BagMenu_UseRotomCatalog(taskId);
    else if (gItemUseCB == ItemUseCB_ZygardeCube)
        BagMenu_UseZygardeCube(taskId);
    else if (gItemUseCB == ItemUseCB_Fusion)
        BagMenu_UseFusion(taskId);
    else if (gItemUseCB == ItemUseCB_TMHM)
        BagMenu_UseTMHM(taskId);
    else
        BagMenu_ClosePartySelect(taskId);
}

#endif // SWSH_ITEM_MENU_ACTION_IN_BAG

#if SWSH_ITEM_MENU_PYRAMID_BAG

EWRAM_DATA struct PyramidBagMenu *gPyramidBagMenu = NULL;
EWRAM_DATA struct PyramidBagMenuState gPyramidBagMenuState = {0};

static void BagMenu_SyncPyramidSelection(void)
{
    gPyramidBagMenuState.scrollPosition = gBagPosition.scrollPosition[gBagPosition.pocket];
    gPyramidBagMenuState.cursorPosition = gBagPosition.cursorPosition[gBagPosition.pocket];
}

void GoToBattlePyramidBagMenu(u8 location, MainCallback exitCallback)
{
    u8 itemMenuLocation;

    switch (location)
    {
    case PYRAMIDBAG_LOC_FIELD:
    case PYRAMIDBAG_LOC_CHOOSE_TOSS:
        itemMenuLocation = ITEMMENULOCATION_FIELD;
        break;
    case PYRAMIDBAG_LOC_BATTLE:
        itemMenuLocation = ITEMMENULOCATION_BATTLE;
        break;
    case PYRAMIDBAG_LOC_PARTY:
        itemMenuLocation = ITEMMENULOCATION_PARTY;
        break;
    case PYRAMIDBAG_LOC_PREV:
    default:
        itemMenuLocation = ITEMMENULOCATION_LAST;
        break;
    }

    if (location != PYRAMIDBAG_LOC_PREV)
        gPyramidBagMenuState.location = location;
    if (exitCallback != NULL)
        gPyramidBagMenuState.exitCallback = exitCallback;

    GoToBagMenu(itemMenuLocation, POCKET_ITEMS, exitCallback);
    if (gBagMenu != NULL)
    {
        gBagPosition.isPyramid = TRUE;
        gBagMenu->pocketSwitchDisabled = TRUE;
        gPyramidBagMenu = (struct PyramidBagMenu *)gBagMenu;
    }
}

void CB2_PyramidBagMenuFromStartMenu(void)
{
    GoToBattlePyramidBagMenu(PYRAMIDBAG_LOC_FIELD, CB2_ReturnToFieldWithOpenMenu);
}

void CB2_ReturnToPyramidBagMenu(void)
{
    GoToBattlePyramidBagMenu(PYRAMIDBAG_LOC_PREV, gPyramidBagMenuState.exitCallback);
}

void InitBattlePyramidBagCursorPosition(void)
{
    gPyramidBagMenuState.cursorPosition = 0;
    gPyramidBagMenuState.scrollPosition = 0;
    gBagPosition.cursorPosition[POCKET_ITEMS] = 0;
    gBagPosition.scrollPosition[POCKET_ITEMS] = 0;
}

void UpdatePyramidBagList(void)
{
    UpdatePocketItemList(gBagPosition.pocket);
    BagMenu_SyncPyramidSelection();
}

void UpdatePyramidBagCursorPos(void)
{
    UpdatePocketListPosition(gBagPosition.pocket);
    BagMenu_SyncPyramidSelection();
}

void CloseBattlePyramidBag(u8 taskId)
{
    Task_FadeAndCloseBagMenu(taskId);
}

void Task_CloseBattlePyramidBagMessage(u8 taskId)
{
    CloseItemMessage(taskId);
}

void DisplayItemMessageInBattlePyramid(u8 taskId, const u8 *str, TaskFunc callback)
{
    DisplayItemMessage(taskId, FONT_NORMAL, str, callback);
}

void TryStoreHeldItemsInPyramidBag(void)
{
    u8 i;
    struct Pokemon *party = gParties[B_TRAINER_PLAYER];
    u16 *newItems = Alloc(PYRAMID_BAG_ITEMS_COUNT * sizeof(*newItems));
#if MAX_PYRAMID_BAG_ITEM_CAPACITY > 255
    u16 *newQuantities = Alloc(PYRAMID_BAG_ITEMS_COUNT * sizeof(*newQuantities));
#else
    u8 *newQuantities = Alloc(PYRAMID_BAG_ITEMS_COUNT * sizeof(*newQuantities));
#endif
    u16 heldItem;

    memcpy(newItems, gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode], PYRAMID_BAG_ITEMS_COUNT * sizeof(*newItems));
    memcpy(newQuantities, gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode], PYRAMID_BAG_ITEMS_COUNT * sizeof(*newQuantities));
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        heldItem = GetMonData(&party[i], MON_DATA_HELD_ITEM);
        if (heldItem != ITEM_NONE && !AddBagItem(heldItem, 1))
        {
            memcpy(gSaveBlock2Ptr->frontier.pyramidBag.itemId[gSaveBlock2Ptr->frontier.lvlMode], newItems, PYRAMID_BAG_ITEMS_COUNT * sizeof(*newItems));
            memcpy(gSaveBlock2Ptr->frontier.pyramidBag.quantity[gSaveBlock2Ptr->frontier.lvlMode], newQuantities, PYRAMID_BAG_ITEMS_COUNT * sizeof(*newQuantities));
            Free(newItems);
            Free(newQuantities);
            gSpecialVar_Result = 1;
            return;
        }
    }

    heldItem = ITEM_NONE;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        SetMonData(&party[i], MON_DATA_HELD_ITEM, &heldItem);
    gSpecialVar_Result = 0;
    Free(newItems);
    Free(newQuantities);
}

static void Task_ChooseItemsToTossFromPyramidBag(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        gFieldCallback2 = CB2_FadeFromPartyMenu;
        GoToBattlePyramidBagMenu(PYRAMIDBAG_LOC_CHOOSE_TOSS, CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

void ChooseItemsToTossFromPyramidBag(void)
{
    LockPlayerFieldControls();
    FadeScreen(FADE_TO_BLACK, 0);
    CreateTask(Task_ChooseItemsToTossFromPyramidBag, 10);
}

#endif // SWSH_ITEM_MENU_PYRAMID_BAG

#endif // SWSH_ITEM_MENU
