#include "global.h"
#include "battle_info.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_gimmick.h"
#include "battle_setup.h"
#include "battle_util.h"
#include "event_data.h"
#include "bg.h"
#include "data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "line_break.h"
#include "palette.h"
#include "party_menu.h"
#include "item.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "scanline_effect.h"
#include "decompress.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "window.h"
#include "constants/battle_info.h"
#include "constants/battle.h"
#include "constants/party_menu.h"
#include "constants/abilities.h"
#include "constants/characters.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/pokemon.h"

struct PrintText
{
    u8 windowId;
    u8 font;
    u8 left;
    u8 top;
    u8 letterSpacing;
    u8 lineSpacing;
    const u8 *color;
    s8 speed;
    const u8 *string;
};

struct MonPic
{
    enum Species species;
    u32 isShiny:1;
    u32 personality:30;
    u32 isFrontPic:1;
    s16 left;
    s16 top;
    u8 paletteSlot;
    u16 paletteTag;
};

static void PrintTextOnWindow(struct PrintText *text)
{
    AddTextPrinterParameterized4(
        text->windowId,
        text->font,
        text->left,
        text->top,
        text->letterSpacing,
        text->lineSpacing,
        text->color,
        text->speed,
        text->string
    );
}

#include "trainer_pokemon_sprites.h"
static u32 CreateMonSprite(struct MonPic *pic)
{
    return CreateMonPicSprite(
                pic->species,
                pic->isShiny,
                pic->personality,
                pic->isFrontPic,
                pic->left,
                pic->top,
                pic->paletteSlot,
                pic->paletteTag
            );
}

struct BattleInfo
{
    u8 label;
    u8 durationRemaining;
    u8 baseTotalDuration;
    u8 stackCount:4;
    u8 setterSide:2;
    u8 durationKnown:1;
    u8 padding:1;
};

struct BattleInfoCard
{
    enum BattlerId battler;
    s16 x;
    s16 y;
    u8 hpBarSpriteId;
    u8 monIconSpriteId;
    u8 gimmickSpriteId;
    u8 statusSpriteId;
    u8 updateSpriteId;
    u8 hpBarLeftEndcapSpriteId;
    u8 hpBarRightEndcapSpriteId;
};

struct BattleInfoMenuData
{
    u8 menuState;
    u8 page;
    u8 selectedCard;
    u8 cursorSpriteId;
    u8 iconSpriteId;
    u8 hpBarSpriteId;
    u8 hpBarLeftEndcapSpriteId;
    u8 hpBarRightEndcapSpriteId;
    u8 statusSpriteId;
    u8 teraTypeSpriteId;
    u8 gimmickSpriteId;
    u8 typeIconSpriteIds[2];
    u8 statPipSpriteIds[B_INFO_DETAIL_STAT_ROW_COUNT][B_INFO_DETAIL_STAT_PIPS_PER_ROW];
    struct BattleInfoCard cards[MAX_BATTLERS_COUNT];
    struct BattleInfo activeEffects[B_INFO_DETAIL_MAX_ACTIVE_EFFECTS];
    u8 activeEffectsCount;
    u8 effectsCursor;
    u8 effectsScrollbarSpriteId;
    u16 effectsScroll;
    u32 windowIds[WIN_DETAIL_COUNT];
    u16 bg0Tilemap[BG_SCREEN_SIZE];
    u16 bg1Tilemap[BG_SCREEN_SIZE];
    u8 detailTextBuffer[B_INFO_DETAIL_TEXT_BUFFER_SIZE];
};

static EWRAM_DATA struct BattleInfoMenuData *sData = NULL;

static void CB2_BattleInfoMenu(void);
static void Task_BattleInfoLoadPage(u8 taskId);
static void BattleInfoVBlankCB(void);
static void BattleInfoMainCB(void);
static void BattleInfoResetSpriteIds(void);
static void BattleInfoInitBgs(void);
static void BattleInfoInit(void);
static void Overview_Enter(void);
static void Overview_Exit(void);
static void Overview_ComputeRowLayout(s16 *outXs);
static void Overview_CreateCards(void);
static void Overview_DrawCards(void);
static void Overview_DrawCard(struct BattleInfoCard *card);
static void Overview_PrintMonAndGender(struct BattleInfoCard *card, struct Pokemon *mon, enum Species species, u32 contentYOffset);
static void CreateGimmickIndicator(struct BattleInfoCard *card, u32 iconCenterY);
static void CreateMonAndStatusInon(struct BattleInfoCard *card, enum Species species, u32 personality, u32 contentYOffset);
static void CreateHpBar(struct BattleInfoCard *card, u32 contentYOffset);
static void Overview_SetBgTile(s16 x, s16 y, u16 tileNum, u16 attrs);
static void Overview_FillBgRect(s16 x, s16 y, s16 width, s16 height, u16 tileNum, u16 attrs);
static void BackdropLoadBaseTilemap(void);
static void LoadBackdropAssets(void);
static void Overview_ComputeHeaderLayout(s16 labelWidth, u8 *outTextLenTiles, s16 *outHeaderX, s16 *outHeaderWidth);
static void Overview_DrawStatusCard(s16 x, s16 y, bool8 isActive, bool8 isBottomRow);
static void Overview_DrawHeaderBox(u16 *tilemap, s16 x, s16 y, u8 textLenTiles);
static void Overview_DrawBackground(void);
static void Overview_DrawCardBackground(const struct BattleInfoCard *card, bool8 isActive);
static void Overview_UpdateCardSelectionHighlight(u8 oldSelectedIndex);
static void Overview_DrawLabels(void);
static void Overview_CreateWindows(void);
static void Overview_ClearWindows(void);
static void Overview_InitCursor(void);
static void Overview_UpdateCursorPos(void);
static void Overview_GetCursorPos(const struct BattleInfoCard *card, s16 *outX, s16 *outY);
static void Task_BattleMenuStatus_HandleInput(u8 taskId);
static void Overview_HandleInput(u8 taskId);

static void Overview_TryMoveCursor(u32 direction);
static void Detail_Enter(void);
static void Detail_Exit(void);
static void Detail_HandleInput(u8 taskId);
static void Detail_CreateWindows(void);
static void Detail_DestroyWindows(void);
static void Detail_DrawStaticWindows(void);
static const u8 *GetGimmickIndicatorData(enum BattlerId battler, u32 *palTag);
static void Detail_DestroyHpBar(void);
static void Detail_RefreshHpBar(void);
static void Detail_DestroyStatusIcon(void);
static void Detail_RefreshStatusIcon(void);
static void Detail_DrawLRButtonGlyphs(void);
static void Detail_DestroyGimmickIndicator(void);
static void Detail_RefreshGimmickIndicator(void);
static void Detail_DestroyTeraTypeIndicator(void);
static void Detail_RefreshTeraTypeIndicator(void);
static void Detail_RefreshItemAbilityWindow(void);
static void PrintHeldItemText(struct PrintText text, enum BattlerId battler);
static void PrintAbilityText(struct PrintText text, enum BattlerId battler);
static void Detail_RefreshHeader(void);
static void Detail_PrintMonName(struct PrintText text, struct Pokemon *mon, s32 levelX);
static void Detail_DisplayMonGender(struct PrintText text, struct Pokemon *mon, s32 genderX);
static void Detail_DisplayMonLevel(struct PrintText text, struct Pokemon *mon, s32 levelX);
static void Detail_DisplayGimmickIndicator(struct PrintText text);
static void Detail_RefreshIcon(void);
static void Detail_RefreshTypeIcons(void);
static void Detail_DestroyTypeIcons(void);
static void Detail_CreateStatPips(void);
static void Detail_DestroyStatPips(void);
static void Detail_RefreshStatPips(void);
static s32 Detail_GetStatRowTextY(u32 row);
static void Detail_SetStatPipSpriteGraphic(u32 spriteId, u16 tileTag);
static void Detail_CycleBattler(s8 direction);
static void Detail_InitEffectsList(void);
static void Detail_BuildActiveEffectsForBattler(void);
static void TryAddActiveWeather(enum BattleInfoLabels label, enum BattleSide side);
static void TryAddActiveTerrain(enum BattleInfoLabels label, enum BattleSide side);
static void TryAddActiveScreen(enum BattleInfoLabels label, u32 sideStatus, u32 remaining, u32 extendedTotal, enum BattleSide side);
static bool32 ShouldShowIncreasedDuration(enum BattleSide side);

struct DisplayTimer
{
    s8 baseTotal;
    s8 extendedTotal;
    s8 remaining;
};
static void SetRemainingDuration(struct DisplayTimer *timer);
static void TryAddActiveFieldStatus(enum BattleInfoLabels label, u32 fieldStatus, u32 timer, u32 totalTimer, enum BattleSide side);
static void TryAddActiveSideStatus(enum BattleInfoLabels label, u32 sideStatus, u32 timer, u32 totalTimer, enum BattleSide side);
static void TryAddActiveStatus(enum BattleInfoLabels label, u32 timerOrFlag, enum BattleSide side);
static void TryAddActiveStatusTimer(enum BattleInfoLabels label, u32 remaining, u32 baseTotal, enum BattleSide side);
static void TryAddActiveStatusInternal(enum BattleInfoLabels label, u32 timerOrFlag, u32 baseTotal, enum BattleSide side, bool32 isTimer);
static enum BattleInfoLabels GetStatusEffectFromWeather(void);
static enum BattleInfoLabels GetStatusEffectFromTerrain(void);
static enum BattleInfoLabels GetStatusEffectFromNonVolatile(enum BattlerId battler);
static void TryAddeActiveDamageNonTypes(enum BattleSide side);

struct Durations
{
    u16 total;
    u16 remaining;
};
static bool32 Detail_GetDisplayedDuration(const struct BattleInfo *entry, enum BattleSide viewerSide, struct Durations *duration);

static void Detail_BuildTurnFractionText(u8 *dst, u16 remaining, u16 total);
static bool32 Detail_TryMoveEffectCursor(s8 direction);
static void Detail_RefreshEffectsWindow(void);
static void Detail_RefreshDescriptionWindow(void);
static void Detail_RefreshEffectsSection(void);
static void Detail_RefreshEffectsScrollbar(void);
static void Detail_DestroyEffectsCursor(void);
static void Detail_DestroyEffectsScrollbar(void);
static void Detail_UpdateEffectsCursor(void);
static void Detail_UpdateScrollbarLane(bool8 hasScrollbar);
static void Detail_SetDescriptionPlaceholder(enum BattleInfoLabels  label);
static void Detail_FormatDescriptionText(enum BattleInfoLabels  label, u8 *dst);
static void Detail_ClampTextLines(u8 *text, u8 maxLines);
static void Detail_DrawWindowFrame(u32 windowId);
static const u8 *GetPrimaryOpponentTrainerName(void);
static const u8 *GetPlayerSideTrainerName(void);
static const u8 *GetPrimaryOpponentTrainerName(void);
static u32 GetOpponentTrainerCount(void);
static void BattleInfoDestroy(void);
static void DestroyOverviewCardSprites(struct BattleInfoCard *card, bool8 freeHpBarTile);

static u32 CreateHpBarSprite(u16 tileTag, s16 x, s16 y);
static void DestroyHpBarEndcaps(u8 *leftEndcapSpriteId, u8 *rightEndcapSpriteId);
static void CreateHpBarEndcaps(u8 *leftEndcapSpriteId, u8 *rightEndcapSpriteId);
static void UpdateHpBarEndcaps(u8 leftEndcapSpriteId, u8 rightEndcapSpriteId, s16 barCenterX, s16 barY, u8 segmentCount);
static void UpdateHpBarTilesWithWidth(u32 spriteId, s16 hp, s16 maxHp, u8 totalPixels, u8 segmentCount);
static void UpdateHpBarTiles(u32 spriteId, s16 hp, s16 maxHp);
static void DrawHpBarSprite(struct BattleInfoCard *card);
static u32 GetBarGfxId(s16 hp, s16 maxHp);
static u32 GetAilmentFromBattler(enum BattlerId battler);
static bool32 CanViewCard(enum BattlerId battler);
static u32 GetCardCount(void);
static enum BattlerId GetSelectedBattler(void);
static enum BattlerId GetBattlerFromSlot(u32 slot);
static enum BattlerId GetBattlerFromEnemySlot(u32 slot);
static enum BattlerId GetBattlerFromPlayerSlot(u32 slot);

static const u8 sTextColor_BattleInfo_Default[] =
{
    B_INFO_TEXT_COLOR_TRANSPARENT,
    B_INFO_TEXT_COLOR_WHITE,
    B_INFO_TEXT_COLOR_DARK_GRAY
};

static const u8 sTextColor_BattleInfo_OverviewDefault[] =
{
    B_INFO_TEXT_COLOR_TRANSPARENT,
    B_INFO_TEXT_COLOR_BLACK,
    B_INFO_TEXT_COLOR_WHITE
};

static const u8 sTextColor_BattleInfo_Male[] =
{
    B_INFO_TEXT_COLOR_TRANSPARENT,
    B_INFO_TEXT_COLOR_BLUE,
    B_INFO_TEXT_COLOR_LIGHT_BLUE
};

static const u8 sTextColor_BattleInfo_Female[] =
{
    B_INFO_TEXT_COLOR_TRANSPARENT,
    B_INFO_TEXT_COLOR_PINK,
    B_INFO_TEXT_COLOR_DARK_PINK
};

static const u8 sText_BattleInfo_DetailLButtonGlyph[] = _("{L_BUTTON}");
static const u8 sText_BattleInfo_DetailRButtonGlyph[] = _("{R_BUTTON}");

static const u8 *const sBattleInfoDetailStatLabels[B_INFO_DETAIL_STAT_ROW_COUNT] =
{
    COMPOUND_STRING("Attack"),
    COMPOUND_STRING("Defense"),
    COMPOUND_STRING("Sp. Atk"),
    COMPOUND_STRING("Sp. Def"),
    COMPOUND_STRING("Speed"),
    COMPOUND_STRING("Accuracy"),
    COMPOUND_STRING("Evasion"),
};

static const enum Stat sBattleInfoDetailStatIds[B_INFO_DETAIL_STAT_ROW_COUNT] =
{
    STAT_ATK,
    STAT_DEF,
    STAT_SPATK,
    STAT_SPDEF,
    STAT_SPEED,
    STAT_ACC,
    STAT_EVASION,
};

struct BattleInfoEffectData
{
    const u8 *name;
    const u8 *description;
};

static const struct BattleInfoEffectData sBattleInfoEffects[INFO_COUNT] =
{
    [INFO_HARSH_SUNLIGHT] =
    {
        COMPOUND_STRING("Harsh Sunlight"),
        COMPOUND_STRING("Boosts the damage dealt by Fire-type moves by 50% and halves the damage dealt by Water-type moves.")
    },
    [INFO_RAIN] =
    {
        COMPOUND_STRING("Rain"),
        COMPOUND_STRING("Boosts the damage dealt by Water-type moves by 50% and halves the damage dealt by Fire-type moves.")
    },
    [INFO_SANDSTORM] =
    {
        COMPOUND_STRING("Sandstorm"),
        COMPOUND_STRING("Pokémon that are not Rock, Ground, or Steel types take damage equal to 1/16 of their max HP at the end of every turn. Boosts the Sp. Def stats of Rock-type Pokémon by 50%.")
    },
    [INFO_SNOW] =
    {
        COMPOUND_STRING("Snow"),
        COMPOUND_STRING("Boosts the Defense stats of Ice-type Pokémon by 50%.")
    },
    [INFO_ELECTRIC_TERRAIN] =
    {
        COMPOUND_STRING("Electric Terrain"),
        COMPOUND_STRING("Pokémon on the ground have the power of their Electric-type moves boosted by 30% and they cannot fall asleep.")
    },
    [INFO_GRASSY_TERRAIN] =
    {
        COMPOUND_STRING("Grassy Terrain"),
        COMPOUND_STRING("Pokémon on the ground have the power of their Grass-type moves boosted by 30% and they have 1/16 of their max HP restored at the end of every turn.")
    },
    [INFO_MISTY_TERRAIN] =
    {
        COMPOUND_STRING("Misty Terrain"),
        COMPOUND_STRING("Halves the damage dealt by Dragon-type moves used against Pokémon on the ground. Pokémon on the ground are also immune to status conditions and cannot become confused.")
    },
    [INFO_TRICK_ROOM] =
    {
        COMPOUND_STRING("Trick Room"),
        COMPOUND_STRING("Pokémon with lower Speed stats move first.")
    },
    [INFO_MAGIC_ROOM] =
    {
        COMPOUND_STRING("Magic Room"),
        COMPOUND_STRING("Most held items do not work.")
    },
    [INFO_WONDER_ROOM] =
    {
        COMPOUND_STRING("Wonder Room"),
        COMPOUND_STRING("Pokémon's Defense and Sp. Def stats are swapped.")
    },
    [INFO_CRITICAL_HIT_BOOST] =
    {
        COMPOUND_STRING("Critical Hit Boost"),
        COMPOUND_STRING("The Pokémon's attacks are more likely to be critical hits.")
    },
    [INFO_CONFUSION] =
    {
        COMPOUND_STRING("Confused"),
        COMPOUND_STRING("For 1-4 turns, the Pokémon has a 1-in-3 chance of hurting itself.")
    },
    [INFO_INFATUATION] =
    {
        COMPOUND_STRING("Infatuation"),
        COMPOUND_STRING("The Pokémon has a 50% chance of being unable to use its moves while the Pokémon that gave it the Infatuated status is on the field.")
    },
    [INFO_NIGHTMARE] =
    {
        COMPOUND_STRING("Nightmare"),
        COMPOUND_STRING("The Pokémon will lose HP each turn as long as it is sleeping.")
    },
    [INFO_DROWSY] =
    {
        COMPOUND_STRING("Drowsy"),
        COMPOUND_STRING("The Pokémon will fall asleep at the end of the next turn after becoming drowsy.")
    },
    [INFO_ENCORE] =
    {
        COMPOUND_STRING("Encore"),
        COMPOUND_STRING("The Pokémon can only use {STR_VAR_1}.")
    },
    [INFO_NO_ABILITY] =
    {
        COMPOUND_STRING("No Ability"),
        COMPOUND_STRING("The Pokémon's Ability loses its effect.")
    },
    [INFO_TORMENT] =
    {
        COMPOUND_STRING("Unable to Repeat"),
        COMPOUND_STRING("The Pokémon cannot use the same move twice in a row.")
    },
    [INFO_TAILWIND] =
    {
        COMPOUND_STRING("Tailwind"),
        COMPOUND_STRING("Doubles the Pokémon's Speed stat.")
    },
    [INFO_LUCKY_CHANT] =
    {
        COMPOUND_STRING("Lucky Chant"),
        COMPOUND_STRING("The opponent's moves won't result in a critical hit.")
    },
    [INFO_GRUDGE] =
    {
        COMPOUND_STRING("Grudge"),
        COMPOUND_STRING("If the Pokémon faints as a result of a move, the PP of that move will be reduced to 0.")
    },
    [INFO_HEALING_PREVENTED] =
    {
        COMPOUND_STRING("Healing Prevented"),
        COMPOUND_STRING("The Pokémon is unable to restore HP through moves, Abilities, or held items.")
    },
    [INFO_IDENTIFIED] =
    {
        COMPOUND_STRING("-"),
        COMPOUND_STRING("The Pokémon will be hit by certain moves that usually wouldn't affect it. If the Pokémon's evasiveness has been boosted, the benefits will be ignored when it is attacked.")
    },
    [INFO_MOVE_DISABLED] =
    {
        COMPOUND_STRING("Move Disabled"),
        COMPOUND_STRING("{STR_VAR_1} cannot be used.")
    },
    [INFO_CANT_ESCAPE] =
    {
        COMPOUND_STRING("Can't Escape"),
        COMPOUND_STRING("The Pokémon cannot be switched out of battle.")
    },
    [INFO_LOCK_ON] =
    {
        COMPOUND_STRING("Lock-On"),
        COMPOUND_STRING("On the next turn after gaining the Locked On status, the Pokémon's move will not miss if targeting the Pokémon that was locked onto.")
    },
    [INFO_EMBARGO] =
    {
        COMPOUND_STRING("Embargo"),
        COMPOUND_STRING("The Pokémon cannot use its held item and no items can be used on it.")
    },
    [INFO_CHARGE] =
    {
        COMPOUND_STRING("Electric Boost"),
        COMPOUND_STRING("The power of the next Electric-type move used by the Pokémon will be doubled.")
    },
    [INFO_GRAVITY] =
    {
        COMPOUND_STRING("Gravity"),
        COMPOUND_STRING("Boosts the accuracy of moves by 67%. Pokémon such as Flying types or ones with the Levitate Ability become grounded. Moves that involve flying or leaping cannot be used.")
    },
    [INFO_MIST] =
    {
        COMPOUND_STRING("Mist"),
        COMPOUND_STRING("The Pokémon's stats won't be lowered.")
    },
    [INFO_SAFEGUARD] =
    {
        COMPOUND_STRING("Safeguard"),
        COMPOUND_STRING("The Pokémon is immune to status conditions and cannot become confused.")
    },
    [INFO_STEALTH_ROCK] =
    {
        COMPOUND_STRING("Stealth Rock"),
        COMPOUND_STRING("Pokémon that switch into battle will take damage equal to 1/8 of their max HP. This damage differs depending on the Pokémon's type matchup with the Rock type.")
    },
    [INFO_STOCKPILING] =
    {
        COMPOUND_STRING("Stockpiling"),
        COMPOUND_STRING("The Pokémon's Defense and Sp. Def stats are boosted by 1 stage for each time it has used Stockpile.")
    },
    [INFO_TAUNT] =
    {
        COMPOUND_STRING("Taunted"),
        COMPOUND_STRING("The Pokémon can use only attacks.")
    },
    [INFO_TELEKINESIS] =
    {
        COMPOUND_STRING("Telekinesis"),
        COMPOUND_STRING("Moves used against the Pokémon will hit without fail, except for one-hit KO moves. Also, Ground-type moves won't hit the Pokémon.")
    },
    [INFO_MAGNET_RISE] =
    {
        COMPOUND_STRING("Magnet Rise"),
        COMPOUND_STRING("The Pokémon floats off the ground, making it immune to Ground-type moves, as well as the Spikes, Toxic Spikes, and Sticky Web statuses.")
    },
    [INFO_TOXIC_SPIKES] =
    {
        COMPOUND_STRING("Toxic Spikes"),
        COMPOUND_STRING("Pokémon that switch into battle will be poisoned or, if 2 layers of Toxic Spikes are set, badly poisoned. Pokémon such as Flying types or ones with the Levitate Ability are unaffected.")
    },
    [INFO_MUD_SPORT] =
    {
        COMPOUND_STRING("Mud Sport"),
        COMPOUND_STRING("The power of Electric-type moves will be halved.")
    },
    [INFO_WISH] =
    {
        COMPOUND_STRING("Wish"),
        COMPOUND_STRING("At the end of the next turn after the Wish status is activated, the HP of the Pokémon in the affected spot will be restored by 1/2 of the max HP of the Pokémon that caused the status.")
    },
    [INFO_STICKY_WEB] =
    {
        COMPOUND_STRING("Sticky Web"),
        COMPOUND_STRING("Pokémon that switch into battle will have their Speed stats lowered by 1 stage. Pokémon such as Flying types or ones with the Levitate Ability are unaffected.")
    },
    [INFO_INGRAIN] =
    {
        COMPOUND_STRING("Ingrained"),
        COMPOUND_STRING("The Pokémon loses 1/4 of its max HP at the end of every turn.")
    },
    [INFO_CURSE] =
    {
        COMPOUND_STRING("Cursed"),
        COMPOUND_STRING("The Pokémon loses 1/4 of its max HP at the end of every turn.")
    },
    [INFO_TRICK_OR_TREAT] =
    {
        COMPOUND_STRING("Trick-or-Treating"),
        COMPOUND_STRING("The Pokémon gains the Ghost type.")
    },
    [INFO_LIGHT_SCREEN] =
    {
        COMPOUND_STRING("Light Screen"),
        COMPOUND_STRING("Halves the damage taken from special moves. In Double Battles, this damage is reduced by 1/3 instead.")
    },
    [INFO_REFLECT] =
    {
        COMPOUND_STRING("Reflect"),
        COMPOUND_STRING("Halves the damage taken from physical moves. In Double Battles, this damage is reduced by 1/3 instead.")
    },
    [INFO_IMPRISON] =
    {
        COMPOUND_STRING("Sealing Off"),
        COMPOUND_STRING("Any moves known by the Pokémon that caused this status cannot be used by its opponents.")
    },
    [INFO_PERISHING] =
    {
        COMPOUND_STRING("Perishing"),
        COMPOUND_STRING("The Pokémon will faint 3 turns after gaining the Perishing status.")
    },
    [INFO_SPIKES] =
    {
        COMPOUND_STRING("Spikes"),
        COMPOUND_STRING("Pokémon that switch into battle will take damage equal to 1/8 of their max HP. This damage will increase if 2 layers of Spikes are set, and again if 3 layers are set. Pokémon such as Flying types or ones with the Levitate Ability are unaffected.")
    },
    [INFO_WATER_SPORT] =
    {
        COMPOUND_STRING("Water Sport"),
        COMPOUND_STRING("The power of Fire-type moves will be halved.")
    },
    [INFO_DESTINY_BOND] =
    {
        COMPOUND_STRING("Destiny Bound"),
        COMPOUND_STRING("If the Pokémon is knocked out by an opponent, that opponent will also be knocked out.")
    },
    [INFO_FORESTS_CURSE] =
    {
        COMPOUND_STRING("Forest's Curse"),
        COMPOUND_STRING("The Pokemon gains the Grass type.")
    },
    [INFO_LEECH_SEED] =
    {
        COMPOUND_STRING("Leech Seeded"),
        COMPOUND_STRING("The Pokémon takes damage equal to 1/8 of its max HP at the end of every turn. Whichever Pokémon is in the spot of the Pokémon that caused the Leech Seeded status has its HP restored by the same amount.")
    },
    [INFO_BOUND] =
    {
        COMPOUND_STRING("Bound"),
        COMPOUND_STRING("For 4-5 turns, the Pokémon takes damage equal to 1/8 of its max HP at the end of every turn. It cannot be switched out of battle.")
    },
    [INFO_BIDE] =
    {
        COMPOUND_STRING("Bide"),
        COMPOUND_STRING("The Pokemon endures attacks for two turns, then strikes back to inflict double the damage it has taken.")
    },
    [INFO_RAMPAGING] =
    {
        COMPOUND_STRING("Rampaging"),
        COMPOUND_STRING("For 2-3 turns, the Pokémon continues its attack and is unable to take any other actions. After that, it becomes confused.")
    },
    [INFO_BADLY_POISONED] =
    {
        COMPOUND_STRING("Badly Poisoned"),
        COMPOUND_STRING("The Pokémon takes increasing poison damage at the end of every turn, starting at 1/16 of the Pokémon's max HP, then 2/16, then 3/16, and so on. If the Pokémon switches out and reenters battle, the damage restarts at 1/16 of its max HP.")
    },
    [INFO_FUTURE_ATTACK] =
    {
        COMPOUND_STRING("Future Attack"),
        COMPOUND_STRING("The Pokémon in the targeted spot will take damage 2 turns after the Future Attack status is activated.")
    },
    [INFO_UPROAR] =
    {
        COMPOUND_STRING("Uproar"),
        COMPOUND_STRING("For 3 turns, the Pokémon continues its attack and is unable to take any other actions. During this time, no Pokémon on the field can fall asleep.")
    },
    [INFO_AQUA_RING] =
    {
        COMPOUND_STRING("Aqua Ring"),
        COMPOUND_STRING("The Pokémon has 1/16 of its max HP restored at the end of every turn.")
    },
    [INFO_AUTOTOMIZE] =
    {
        COMPOUND_STRING("Autotomize"),
        COMPOUND_STRING("The Pokémon's weight is reduced, and its Speed is sharply increased.")
    },
    [INFO_SMACK_DOWN] =
    {
        COMPOUND_STRING("Landed"),
        COMPOUND_STRING("The Pokémon is now grounded and can be affected by Ground-type moves.")
    },
    [INFO_FAIRY_LOCK] =
    {
        COMPOUND_STRING("Fairy Locked"),
        COMPOUND_STRING("No Pokémon on the field can be switched out of battle until the end of the next turn after the Fairy Locked status is activated.")
    },
    [INFO_RAINBOW] =
    {
        COMPOUND_STRING("Rainbow"),
        COMPOUND_STRING("The additional effects of moves are more likely to occur.")
    },
    [INFO_SWAMP] =
    {
        COMPOUND_STRING("Swamp"),
        COMPOUND_STRING("Speed is reduced by 75% in swampy conditions.")
    },
    [INFO_SEA_OF_FIRE] =
    {
        COMPOUND_STRING("Sea of Fire"),
        COMPOUND_STRING("Pokémon that are not Fire types will take damage every turn.")
    },
    [INFO_EXTREMELY_HARSH_SUNLIGHT] =
    {
        COMPOUND_STRING("Extremely Harsh Sunlight"),
        COMPOUND_STRING("Boosts the power of Fire-type moves and protects Pokémon from Water-type moves.")
    },
    [INFO_HEAVY_RAIN] =
    {
        COMPOUND_STRING("Heavy Rain"),
        COMPOUND_STRING("Boosts the power of Water-type moves and protects Pokemon from Fire-type moves.")
    },
    [INFO_STRONG_WINDS] =
    {
        COMPOUND_STRING("Strong Winds"),
        COMPOUND_STRING("The power of moves that are super effective against Flying-type Pokemon is decreased.")
    },
    [INFO_PSYCHIC_TERRAIN] =
    {
        COMPOUND_STRING("Psychic Terrain"),
        COMPOUND_STRING("Pokémon on the ground have the power of their Psychic-type moves boosted by 30% and they are immune to priority moves.")
    },
    [INFO_THROAT_CHOP] =
    {
        COMPOUND_STRING("Throat Chopped"),
        COMPOUND_STRING("The Pokémon cannot use any sound-based moves for 2 turns.")
    },
    [INFO_AURORA_VEIL] =
    {
        COMPOUND_STRING("Aurora Veil"),
        COMPOUND_STRING("Halves the damage taken from physical and special moves. In Double Battles, this damage is reduced by 1/3 instead.")
    },
    [INFO_LASER_FOCUS] =
    {
        COMPOUND_STRING("Laser Focus"),
        COMPOUND_STRING("The next move used will always result in a critical hit.")
    },
    [INFO_TAR_SHOT] =
    {
        COMPOUND_STRING("Tar Shot"),
        COMPOUND_STRING("The Pokémon has been made weaker to Fire-type moves.")
    },
    [INFO_OCTOLOCK] =
    {
        COMPOUND_STRING("Octolock"),
        COMPOUND_STRING("The Pokémon's Defense and Sp. Def are both lowered with each passing turn.")
    },
    // G-Max effects
    [INFO_G_MAX_WILDFIRE] =
    {
        COMPOUND_STRING("G-Max Wildfire"),
        COMPOUND_STRING("Pokémon that are not Fire types will take damage every turn for four turns.")
    },
    [INFO_G_MAX_VOLCALITH] =
    {
        COMPOUND_STRING("G-Max Volcalith"),
        COMPOUND_STRING("Pokémon that are not Rock types will take damage every turn for four turns.")
    },
    [INFO_G_MAX_STEELSURGE] =
    {
        COMPOUND_STRING("G-Max Volcalith"),
        COMPOUND_STRING("Pokémon that switch into battle will take damage.")
    },
    [INFO_G_MAX_VINE_LASH] =
    {
        COMPOUND_STRING("G-Max Vine Lash"),
        COMPOUND_STRING("Pokémon that are not Grass types will take damage every turn for four turns.")
    },
    [INFO_G_MAX_CANNONADE] =
    {
        COMPOUND_STRING("G-Max Cannonade"),
        COMPOUND_STRING("Pokémon that are not Water types will take damage every turn for four turns.")
    },
    [INFO_FOG] =
    {
        COMPOUND_STRING("Fog"),
        COMPOUND_STRING("All moves are less accurate, apart from moves that are always sure to hit.")
    },
    [INFO_SALT_CURE] =
    {
        COMPOUND_STRING("Salt Cured"),
        COMPOUND_STRING("The Pokémon takes damage equal to 1/16 of its max HP at the end of every turn. If the Pokémon is a Steel type or Water type, it takes damage equal to 1/8 of its max HP instead.")
    },
    [INFO_SYRUPY] =
    {
        COMPOUND_STRING("Syrupy"),
        COMPOUND_STRING("The Pokémon's Speed stat is lowered by 1 stage at the end of every turn.")
    },
    [INFO_GOING_ALL_OUT] =
    {
        COMPOUND_STRING("Going All Out"),
        COMPOUND_STRING("The Pokémon's Attack and Sp. Atk are both boosted thanks to a Trainer's cheer.")
    },
    [INFO_HANGING_TOUGH] =
    {
        COMPOUND_STRING("Hanging Tough"),
        COMPOUND_STRING("The Pokémon's Defense and Sp. Def are both boosted thanks to a Trainer's cheer.")
    },
    [INFO_BATTLE_STATE_112] =
    {
        COMPOUND_STRING("-"),
        COMPOUND_STRING("No description.")
    },
    [INFO_RECHARGING] =
    {
        COMPOUND_STRING("Recharging"),
        COMPOUND_STRING("The Pokémon cannot take any actions for 1 turn.")
    },
    [INFO_CHARGING] =
    {
        COMPOUND_STRING("Charging"),
        COMPOUND_STRING("The Pokémon spends 1 turn charging before using a move.")
    },
    [INFO_SKY_HIGH] =
    {
        COMPOUND_STRING("Sky-High"), // Fly, Bounce, Sky Drop
        COMPOUND_STRING("The Pokémon cannot be hit by most moves, excluding moves such as Thunder, Hurricane, and Smack Down. The Pokémon is also unaffected by the terrain.")
    },
    [INFO_SUBMERGED] =
    {
        COMPOUND_STRING("Submerged"), // Dive
        COMPOUND_STRING("The Pokémon cannot be hit by most moves, but Surf and Whirlpool will hit and will deal double damage. The Pokémon is also unaffected by the terrain.")
    },
    [INFO_UNDERGROUND] =
    {
        COMPOUND_STRING("Underground"), // Dig
        COMPOUND_STRING("The Pokémon cannot be hit by most moves, but Earthquake will hit and will deal double damage. The Pokémon is also unaffected by the terrain.")
    },
    [INFO_CONCEALED] =
    {
        COMPOUND_STRING("Concealed"), // Shadow Force, Phantom Force
        COMPOUND_STRING("The Pokémon cannot be hit by moves and is unaffected by the terrain.")
    },
    [INFO_MINIMIZED] =
    {
        COMPOUND_STRING("Minimized"),
        COMPOUND_STRING("Moves such as Supercell Slam, Body Slam, Dragon Rush, Flying Press, Heat Crash, and Heavy Slam will not miss the Pokémon and will deal double damage.")
    },
    [INFO_ATK_DEF_SWAPPED] =
    {
        COMPOUND_STRING("Atk/Def Swapped"), // Power Trick
        COMPOUND_STRING("The Pokémon's Attack and Defense stats are swapped.")
    },
    [INFO_FLASH_FIRE] =
    {
        COMPOUND_STRING("Flash Fire"),
        COMPOUND_STRING("Boosts the power of the Pokémon's Fire-type moves by 50%.")
    },
    [INFO_MICLE_BERRY] =
    {
        COMPOUND_STRING("Micle Berry"),
        COMPOUND_STRING("Boosts the accuracy of the Pokémon's next move by 20%.")
    },
};

static const u8 sBattleInfoHpBarTiles[8 * TILE_SIZE_4BPP] = {0};
static const u8 sBattleInfoHpBarLeftEndcapGfx[] = INCBIN_U8("graphics/battle_interface/hpbar_left_endcap.4bpp");
static const u8 sBattleInfoHpBarRightEndcapGfx[] = INCBIN_U8("graphics/battle_interface/hpbar_right_endcap.4bpp");
static const u16 sBattleInfoMenuBgPalette[] = INCBIN_U16("graphics/battle_interface/battle_status_menu.gbapal");
static const u32 sBattleInfoMenuBgTiles[] = INCBIN_U32("graphics/battle_interface/battle_status_menu.4bpp");
static const u16 sBattleInfoMenuOverviewBaseTilemap[] = INCBIN_U16("graphics/battle_interface/active_battlers_overview.bin");
static const u16 sBattleInfoMenuDetailsBaseTilemap[] = INCBIN_U16("graphics/battle_interface/active_battlers_details.bin");

static const struct OamData sOamData_BattleInfoHpBar =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct Subsprite sBattleInfoHpBarSubsprites[] =
{
    {
        .x = -16,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 0,
        .priority = 1
    },
    {
        .x = 16,
        .y = 0,
        .shape = SPRITE_SHAPE(32x8),
        .size = SPRITE_SIZE(32x8),
        .tileOffset = 4,
        .priority = 1
    }
};

static const struct SubspriteTable sBattleInfoHpBarSubspriteTable[] =
{
    {ARRAY_COUNT(sBattleInfoHpBarSubsprites), sBattleInfoHpBarSubsprites}
};

static const struct SpriteSheet sSpriteSheet_BattleInfoHpBar =
{
    sBattleInfoHpBarTiles, sizeof(sBattleInfoHpBarTiles), B_INFO_HP_BAR_TILE_TAG_BASE
};

static const struct SpritePalette sSpritePalette_BattleInfoHpBar =
{
    gBattleInterface_BallDisplayPal, B_INFO_HP_BAR_PAL_TAG
};

static const struct SpriteTemplate sSpriteTemplate_BattleInfoHpBar =
{
    .tileTag = B_INFO_HP_BAR_TILE_TAG_BASE,
    .paletteTag = B_INFO_HP_BAR_PAL_TAG,
    .oam = &sOamData_BattleInfoHpBar,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_BattleInfoHpBarEndcap =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteSheet sSpriteSheet_BattleInfoHpBarLeftEndcap =
{
    sBattleInfoHpBarLeftEndcapGfx, sizeof(sBattleInfoHpBarLeftEndcapGfx), B_INFO_HP_BAR_ENDCAP_LEFT_TILE_TAG
};

static const struct SpriteSheet sSpriteSheet_BattleInfoHpBarRightEndcap =
{
    sBattleInfoHpBarRightEndcapGfx, sizeof(sBattleInfoHpBarRightEndcapGfx), B_INFO_HP_BAR_ENDCAP_RIGHT_TILE_TAG
};

static const struct SpritePalette sSpritePalette_BattleInfoHpBarEndcap =
{
    gBattleInterface_BallDisplayPal, B_INFO_HP_BAR_ENDCAP_PAL_TAG
};

static const struct SpriteTemplate sSpriteTemplate_BattleInfoHpBarLeftEndcap =
{
    .tileTag = B_INFO_HP_BAR_ENDCAP_LEFT_TILE_TAG,
    .paletteTag = B_INFO_HP_BAR_ENDCAP_PAL_TAG,
    .oam = &sOamData_BattleInfoHpBarEndcap,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_BattleInfoHpBarRightEndcap =
{
    .tileTag = B_INFO_HP_BAR_ENDCAP_RIGHT_TILE_TAG,
    .paletteTag = B_INFO_HP_BAR_ENDCAP_PAL_TAG,
    .oam = &sOamData_BattleInfoHpBarEndcap,
    .callback = SpriteCallbackDummy
};

static const u8 sBattleInfoUpdateIconGfx[] = INCBIN_U8("graphics/battle_interface/update_indicator.4bpp");

static const struct OamData sOamData_BattleInfoUpdateIcon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteSheet sSpriteSheet_BattleInfoUpdateIcon =
{
    sBattleInfoUpdateIconGfx, sizeof(sBattleInfoUpdateIconGfx), B_INFO_UPDATE_ICON_TILE_TAG
};

static const struct SpriteTemplate sSpriteTemplate_BattleInfoUpdateIcon =
{
    .tileTag = B_INFO_UPDATE_ICON_TILE_TAG,
    .paletteTag = TAG_MISC_INDICATOR_PAL,
    .oam = &sOamData_BattleInfoUpdateIcon,
    .callback = SpriteCallbackDummy
};

static const u8 sBattleInfoDetailStatPipDotGfx[] = INCBIN_U8("graphics/battle_interface/battle_status_stat_slot_indicator.4bpp");
static const u8 sBattleInfoDetailStatPipUpGfx[] = INCBIN_U8("graphics/battle_interface/battle_status_stat_raise_indicator.4bpp");
static const u8 sBattleInfoDetailStatPipDownGfx[] = INCBIN_U8("graphics/battle_interface/battle_status_stat_drop_indicator.4bpp");

static const struct OamData sOamData_BattleInfoDetailStatPip =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteSheet sSpriteSheet_BattleInfoDetailStatPipDot =
{
    sBattleInfoDetailStatPipDotGfx, sizeof(sBattleInfoDetailStatPipDotGfx), B_INFO_DETAIL_STAT_PIP_DOT_TILE_TAG
};

static const struct SpriteSheet sSpriteSheet_BattleInfoDetailStatPipUp =
{
    sBattleInfoDetailStatPipUpGfx, sizeof(sBattleInfoDetailStatPipUpGfx), B_INFO_DETAIL_STAT_PIP_UP_TILE_TAG
};

static const struct SpriteSheet sSpriteSheet_BattleInfoDetailStatPipDown =
{
    sBattleInfoDetailStatPipDownGfx, sizeof(sBattleInfoDetailStatPipDownGfx), B_INFO_DETAIL_STAT_PIP_DOWN_TILE_TAG
};

static const struct SpriteTemplate sSpriteTemplate_BattleInfoDetailStatPip =
{
    .tileTag = B_INFO_DETAIL_STAT_PIP_DOT_TILE_TAG,
    .paletteTag = B_INFO_DETAIL_STAT_PIP_PAL_TAG,
    .oam = &sOamData_BattleInfoDetailStatPip,
    .callback = SpriteCallbackDummy,
};

static const u8 sBattleInfoDetailEffectsScrollbarGfx[] = INCBIN_U8("graphics/battle_interface/scrollbar.4bpp");

static const struct OamData sOamData_BattleInfoDetailEffectsScrollbar =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteSheet sSpriteSheet_BattleInfoDetailEffectsScrollbar =
{
    sBattleInfoDetailEffectsScrollbarGfx, sizeof(sBattleInfoDetailEffectsScrollbarGfx), B_INFO_DETAIL_EFFECTS_SCROLLBAR_TILE_TAG
};

static const struct SpriteTemplate sSpriteTemplate_BattleInfoDetailEffectsScrollbar =
{
    .tileTag = B_INFO_DETAIL_EFFECTS_SCROLLBAR_TILE_TAG,
    .paletteTag = TAG_MISC_INDICATOR_PAL,
    .oam = &sOamData_BattleInfoDetailEffectsScrollbar,
    .callback = SpriteCallbackDummy,
};

static const u8 sBattleInfoCursorGfx[] = INCBIN_U8("graphics/battle_interface/arrow_indicator.4bpp");

static const struct OamData sOamData_BattleInfoCursor =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sSpriteTemplate_BattleInfoCursor =
{
    .tileTag = B_INFO_CURSOR_TILE_TAG,
    .paletteTag = TAG_MISC_INDICATOR_PAL,
    .oam = &sOamData_BattleInfoCursor,
    .callback = SpriteCallbackDummy
};

static const struct SpriteSheet sSpriteSheet_BattleInfoCursor =
{
    sBattleInfoCursorGfx, sizeof(sBattleInfoCursorGfx), B_INFO_CURSOR_TILE_TAG
};

static const struct OamData sOamData_BattleInfoDetailGimmick =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sSpriteTemplate_BattleInfoDetailGimmick =
{
    .tileTag = B_INFO_DETAIL_GIMMICK_TILE_TAG,
    .paletteTag = TAG_MISC_INDICATOR_PAL,
    .oam = &sOamData_BattleInfoDetailGimmick,
    .callback = SpriteCallbackDummy,
};

static const struct BgTemplate sBattleInfoMenuBgTemplates[] =
{
    [B_INFO_TEXT_BG] = {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    [B_INFO_BACKDROP_BG] = {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
};

static const struct WindowTemplate sBattleInfoMenuWindowTemplates[] =
{
    [WIN_LABEL_TOP] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 32,
        .height = B_INFO_LABEL_TILE_H,
        .paletteNum = B_INFO_TEXT_PAL,
        .baseBlock = B_INFO_WIN_LABEL_TOP_BASE,
    },
    [WIN_LABEL_BOTTOM] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = B_INFO_LABEL_BOTTOM_TILE_TOP,
        .width = 32,
        .height = B_INFO_LABEL_TILE_H,
        .paletteNum = B_INFO_TEXT_PAL,
        .baseBlock = B_INFO_WIN_LABEL_BOTTOM_BASE,
    },
    [WIN_ROW_ENEMY] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = B_INFO_ROW_Y_ENEMY / 8,
        .width = 32,
        .height = B_INFO_CARD_TILE_H,
        .paletteNum = B_INFO_TEXT_PAL,
        .baseBlock = B_INFO_WIN_ROW_ENEMY_BASE,
    },
    [WIN_ROW_PLAYER] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = B_INFO_ROW_Y_PLAYER / 8,
        .width = 32,
        .height = B_INFO_CARD_TILE_H,
        .paletteNum = B_INFO_TEXT_PAL,
        .baseBlock = B_INFO_WIN_ROW_PLAYER_BASE,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sBattleInfoDetailWindowTemplates[WIN_DETAIL_COUNT] =
{
    [WIN_DETAIL_HEADER] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 0,
        .width = B_INFO_DETAIL_HEADER_WIN_W,
        .height = B_INFO_DETAIL_HEADER_WIN_H,
        .paletteNum = B_INFO_TEXT_PAL,
        .baseBlock = B_INFO_WIN_DETAIL_HEADER_BASE,
    },
    [WIN_DETAIL_ITEM_ABILITY] = {
        .bg = 0,
        .tilemapLeft = 7,
        .tilemapTop = 4,
        .width = B_INFO_DETAIL_ITEM_WIN_W,
        .height = B_INFO_DETAIL_ITEM_WIN_H,
        .paletteNum = B_INFO_TEXT_PAL,
        .baseBlock = B_INFO_WIN_DETAIL_ITEM_BASE,
    },
    [WIN_DETAIL_STATS] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 9,
        .width = B_INFO_DETAIL_STATS_WIN_W,
        .height = B_INFO_DETAIL_STATS_WIN_H,
        .paletteNum = B_INFO_TEXT_PAL,
        .baseBlock = B_INFO_WIN_DETAIL_STATS_BASE,
    },
    [WIN_DETAIL_EFFECTS] = {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 0,
        .width = B_INFO_DETAIL_EFFECTS_WIN_W,
        .height = B_INFO_DETAIL_EFFECTS_WIN_H,
        .paletteNum = B_INFO_TEXT_PAL,
        .baseBlock = B_INFO_WIN_DETAIL_EFFECTS_BASE,
    },
    [WIN_DETAIL_DESCRIPTION] = {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 12,
        .width = B_INFO_DETAIL_DESC_WIN_W,
        .height = B_INFO_DETAIL_DESC_WIN_H,
        .paletteNum = B_INFO_TEXT_PAL,
        .baseBlock = B_INFO_WIN_DETAIL_DESC_BASE,
    },
};

void CB2_BattleInfoFromBattle(void)
{
    sData = AllocZeroed(sizeof(struct BattleInfoMenuData));

    if (sData == NULL)
    {
        SetMainCallback2(CB2_SetUpReshowBattleScreenAfterMenu);
        return;
    }

    SetMainCallback2(CB2_BattleInfoMenu);
}

static void CB2_BattleInfoMenu(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        if (!MenuHelpers_IsLinkActive())
            ResetTasks();
        BattleInfoResetSpriteIds();
        gPaletteFade.bufferTransferDisabled = TRUE;
        gMain.state++;
        break;
    case 2:
        BattleInfoInitBgs();
        gMain.state++;
        break;
    case 3:
        gMain.state++;
        break;
    case 4:
        InitWindows((const struct WindowTemplate[]){DUMMY_WIN_TEMPLATE});
        DeactivateAllTextPrinters();
        BattleInfoInit();
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gPaletteFade.bufferTransferDisabled = FALSE;
        gMain.state++;
        break;
    case 5:
        sData->menuState = B_INFO_STATE_HANDLE_INPUT;
        CreateTask(Task_BattleInfoLoadPage, 0);
        SetVBlankCallback(BattleInfoVBlankCB);
        SetMainCallback2(BattleInfoMainCB);
        gMain.state++;
        break;
    }
}

static void Task_BattleInfoLoadPage(u8 taskId)
{
    if (gPaletteFade.active)
        return;

    switch (sData->menuState)
    {
    case B_INFO_STATE_CLEAR_PAGE:
        if (sData->page == B_INFO_PAGE_DETAIL)
            Overview_Exit();
        else if (sData->page == B_INFO_PAGE_OVERVIEW)
            Detail_Exit();
        sData->menuState++;
        break;
    case B_INFO_STATE_ENTER_PAGE:
        if (sData->page == B_INFO_PAGE_DETAIL)
            Detail_Enter();
        else if (sData->page == B_INFO_PAGE_OVERVIEW)
            Overview_Enter();
        sData->menuState = B_INFO_STATE_HANDLE_INPUT;
        break;
    case B_INFO_STATE_EXIT:
        BattleInfoDestroy();
        FreeAllWindowBuffers();
        DestroyTask(taskId);
        SetMainCallback2(CB2_SetUpReshowBattleScreenAfterMenu);
        break;
    case B_INFO_STATE_HANDLE_INPUT:
        gTasks[taskId].func = Task_BattleMenuStatus_HandleInput;
        sData->menuState++;
        break;
    case B_INFO_STATE_DONE:
        break;
    }
}

static void BattleInfoVBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void BattleInfoMainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void BattleInfoResetSpriteIds(void)
{
    sData->cursorSpriteId = SPRITE_NONE;
    sData->iconSpriteId = SPRITE_NONE;
    sData->hpBarSpriteId = SPRITE_NONE;
    sData->hpBarLeftEndcapSpriteId = SPRITE_NONE;
    sData->hpBarRightEndcapSpriteId = SPRITE_NONE;
    sData->statusSpriteId = SPRITE_NONE;
    sData->teraTypeSpriteId = SPRITE_NONE;
    sData->gimmickSpriteId = SPRITE_NONE;
    sData->effectsScrollbarSpriteId = SPRITE_NONE;
    sData->typeIconSpriteIds[0] = SPRITE_NONE;
    sData->typeIconSpriteIds[1] = SPRITE_NONE;

    for (u32 i = 0; i < B_INFO_DETAIL_STAT_ROW_COUNT; i++)
    {
        for (u32 j = 0; j < B_INFO_DETAIL_STAT_PIPS_PER_ROW; j++)
            sData->statPipSpriteIds[i][j] = SPRITE_NONE;
    }

    for (u32 i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        sData->cards[i].hpBarSpriteId = SPRITE_NONE;
        sData->cards[i].monIconSpriteId = SPRITE_NONE;
        sData->cards[i].gimmickSpriteId = SPRITE_NONE;
        sData->cards[i].statusSpriteId = SPRITE_NONE;
        sData->cards[i].updateSpriteId = SPRITE_NONE;
        sData->cards[i].hpBarLeftEndcapSpriteId = SPRITE_NONE;
        sData->cards[i].hpBarRightEndcapSpriteId = SPRITE_NONE;
    }
}

static void BattleInfoInitBgs(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    CpuFill16(0, (void *)BG_CHAR_ADDR(0), BG_CHAR_SIZE);
    CpuFill16(0, (void *)BG_CHAR_ADDR(2), BG_CHAR_SIZE);
    CpuFill16(0, (void *)BG_CHAR_ADDR(3), BG_CHAR_SIZE);

    InitBgsFromTemplates(0, sBattleInfoMenuBgTemplates, ARRAY_COUNT(sBattleInfoMenuBgTemplates));
    SetBgTilemapBuffer(B_INFO_TEXT_BG, sData->bg0Tilemap); // This doesn't seems to be used?
    SetBgTilemapBuffer(B_INFO_BACKDROP_BG, sData->bg1Tilemap);
    FillBgTilemapBufferRect(B_INFO_TEXT_BG, 0, 0, 0, B_INFO_TILEMAP_WIDTH, B_INFO_TILEMAP_HEIGHT, 0);
    FillBgTilemapBufferRect(B_INFO_BACKDROP_BG, 0, 0, 0, B_INFO_TILEMAP_WIDTH, B_INFO_TILEMAP_HEIGHT, 0);
    CopyBgTilemapBufferToVram(B_INFO_TEXT_BG);
    CopyBgTilemapBufferToVram(B_INFO_BACKDROP_BG);

    ResetAllBgsCoordinates();
    LoadBgTiles(B_INFO_BACKDROP_BG, sBattleInfoMenuBgTiles, sizeof(sBattleInfoMenuBgTiles), 0);
    LoadPalette(sBattleInfoMenuBgPalette, BG_PLTT_ID(0), sizeof(sBattleInfoMenuBgPalette));
    LoadPalette(gBattleInfoTextPalette, BG_PLTT_ID(B_INFO_TEXT_PAL), PLTT_SIZE_4BPP);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(B_INFO_BACKDROP_BG);
    ShowBg(B_INFO_TEXT_BG);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static void BattleInfoInit(void)
{
    LoadMonIconPalettes();
    LoadPartyMenuAilmentGfx();
    LoadSpriteSheet(&sSpriteSheet_BattleInfoHpBar);
    LoadSpriteSheet(&sSpriteSheet_BattleInfoHpBarLeftEndcap);
    LoadSpriteSheet(&sSpriteSheet_BattleInfoHpBarRightEndcap);
    LoadSpritePalette(&sSpritePalette_BattleInfoHpBar);
    LoadSpritePalette(&sSpritePalette_BattleInfoHpBarEndcap);
    LoadSpriteSheet(&sSpriteSheet_BattleInfoUpdateIcon);
    LoadCompressedSpriteSheet(&gSpriteSheet_MoveTypes);
    LoadSpritePaletteInSlot(&(struct SpritePalette){ .data = gMoveTypes_Pal,      .tag = gSpriteTemplate_MoveTypes.paletteTag }, 13);
    LoadSpritePaletteInSlot(&(struct SpritePalette){ .data = gMoveTypes_Pal + 16, .tag = B_INFO_MOVE_TYPES_PAL_TAG_1 }, 14);
    LoadSpritePaletteInSlot(&(struct SpritePalette){ .data = gMoveTypes_Pal + 32, .tag = B_INFO_MOVE_TYPES_PAL_TAG_2 }, 15);
    LoadSpriteSheet(&sSpriteSheet_BattleInfoDetailEffectsScrollbar);
    LoadSpriteSheet(&sSpriteSheet_BattleInfoCursor);
    LoadIndicatorSpritesGfx();
    Overview_CreateWindows();
    Overview_Enter();
}

static void Overview_Enter(void)
{
    sData->page = B_INFO_PAGE_OVERVIEW;
    LoadBackdropAssets();
    Overview_ClearWindows();
    Overview_CreateCards();
    Overview_DrawBackground();
    Overview_DrawCards();
    Overview_DrawLabels();
    Overview_InitCursor();
    ShowBg(B_INFO_BACKDROP_BG);
    ShowBg(B_INFO_TEXT_BG);
}

static void Overview_Exit(void)
{
    if (sData->cursorSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sData->cursorSpriteId]);
    sData->cursorSpriteId = SPRITE_NONE;

    for (u32 i = 0; i < GetCardCount(); i++)
        DestroyOverviewCardSprites(&sData->cards[i], FALSE);

    Overview_ClearWindows();
}

static void Overview_CreateWindows(void)
{
    InitWindows(sBattleInfoMenuWindowTemplates);
    Overview_ClearWindows();
}

static void Overview_ClearWindows(void)
{
    for (u32 i = 0; i < GetCardCount(); i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(B_INFO_TEXT_COLOR_TRANSPARENT));
        ClearWindowTilemap(i);
        CopyWindowToVram(i, COPYWIN_GFX);
    }

    CopyBgTilemapBufferToVram(B_INFO_TEXT_BG);
}

static void Detail_Enter(void)
{
    Detail_DestroyEffectsCursor();

    sData->page = B_INFO_PAGE_DETAIL;
    sData->iconSpriteId = SPRITE_NONE;
    sData->hpBarSpriteId = SPRITE_NONE;
    sData->statusSpriteId = SPRITE_NONE;
    sData->teraTypeSpriteId = SPRITE_NONE;
    sData->gimmickSpriteId = SPRITE_NONE;
    LoadBackdropAssets();
    BackdropLoadBaseTilemap();
    FillBgTilemapBufferRect(B_INFO_TEXT_BG, 0, 0, 0, B_INFO_TILEMAP_WIDTH, B_INFO_TILEMAP_HEIGHT, 0);
    CopyBgTilemapBufferToVram(B_INFO_TEXT_BG);
    Detail_CreateWindows();
    Detail_DrawStaticWindows();
    Detail_InitEffectsList();
    Detail_CreateStatPips();
    Detail_RefreshStatPips();
    Detail_RefreshHeader();
    Detail_RefreshItemAbilityWindow();
    Detail_RefreshIcon();
    Detail_RefreshHpBar();
    Detail_RefreshStatusIcon();
    Detail_RefreshTypeIcons();
    ShowBg(B_INFO_BACKDROP_BG);
    ShowBg(B_INFO_TEXT_BG);
}

static void Detail_Exit(void)
{
    Detail_DestroyWindows();

    Detail_DestroyHpBar();
    Detail_DestroyStatusIcon();
    Detail_DestroyTeraTypeIndicator();
    Detail_DestroyGimmickIndicator();
    Detail_DestroyTypeIcons();
    Detail_DestroyStatPips();
    Detail_DestroyEffectsScrollbar();
    Detail_DestroyEffectsCursor();
    sData->activeEffectsCount = 0;
    sData->effectsCursor = 0;
    sData->effectsScroll = 0;

    if (sData->iconSpriteId != SPRITE_NONE)
    {
        FreeAndDestroyMonIconSprite(&gSprites[sData->iconSpriteId]);
        sData->iconSpriteId = SPRITE_NONE;
    }

    FillBgTilemapBufferRect(B_INFO_TEXT_BG, 0, 0, 0, B_INFO_TILEMAP_WIDTH, B_INFO_TILEMAP_HEIGHT, 0);
    CopyBgTilemapBufferToVram(B_INFO_TEXT_BG);
}

static void Detail_CreateWindows(void)
{
    for (u32 i = 0; i < WIN_DETAIL_COUNT; i++)
        sData->windowIds[i] = WINDOW_NONE;

    for (u32 i = 0; i < WIN_DETAIL_COUNT; i++)
    {
        if (i == WIN_DETAIL_ITEM_ABILITY)
            continue;

        sData->windowIds[i] = AddWindow(&sBattleInfoDetailWindowTemplates[i]);
        if (sData->windowIds[i] != WINDOW_NONE)
            Detail_DrawWindowFrame(sData->windowIds[i]);
    }

    sData->windowIds[WIN_DETAIL_ITEM_ABILITY] = sData->windowIds[WIN_DETAIL_HEADER];
}

static void Detail_DestroyWindows(void)
{
    u32 mergedInfoWindowId = sData->windowIds[WIN_DETAIL_HEADER];

    for (u32 i = 0; i < WIN_DETAIL_COUNT; i++)
    {
        u32 windowId = sData->windowIds[i];

        if (windowId == WINDOW_NONE)
            continue;

        if (i == WIN_DETAIL_ITEM_ABILITY
         && windowId == mergedInfoWindowId)
        {
            sData->windowIds[i] = WINDOW_NONE;
            continue;
        }

        FillWindowPixelBuffer(windowId, PIXEL_FILL(B_INFO_TEXT_COLOR_TRANSPARENT));
        ClearWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_GFX);
        RemoveWindow(windowId);
        sData->windowIds[i] = WINDOW_NONE;
    }

    CopyBgTilemapBufferToVram(B_INFO_TEXT_BG);
}

static void Detail_DrawStaticWindows(void)
{
    u32 windowId;

    windowId = sData->windowIds[WIN_DETAIL_ITEM_ABILITY];
    if (windowId != WINDOW_NONE)
    {
        Detail_DrawWindowFrame(windowId);
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }

    windowId = sData->windowIds[WIN_DETAIL_STATS];
    if (windowId != WINDOW_NONE)
    {
        Detail_DrawWindowFrame(windowId);
        for (u32 i = 0; i < B_INFO_DETAIL_STAT_ROW_COUNT; i++)
        {
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, 2,
                                         Detail_GetStatRowTextY(i), 0, 0,
                                         sTextColor_BattleInfo_Default, TEXT_SKIP_DRAW,
                                         sBattleInfoDetailStatLabels[i]);
        }
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }

    Detail_DrawLRButtonGlyphs();
    windowId = sData->windowIds[WIN_DETAIL_ITEM_ABILITY];
    if (windowId != WINDOW_NONE)
    {
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }
    windowId = sData->windowIds[WIN_DETAIL_STATS];
    if (windowId != WINDOW_NONE)
    {
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }

    windowId = sData->windowIds[WIN_DETAIL_EFFECTS];
    if (windowId != WINDOW_NONE)
    {
        Detail_DrawWindowFrame(windowId);
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }

    windowId = sData->windowIds[WIN_DETAIL_DESCRIPTION];
    if (windowId != WINDOW_NONE)
    {
        Detail_DrawWindowFrame(windowId);
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }
}

static void Detail_DestroyHpBar(void)
{
    if (sData->hpBarSpriteId != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sData->hpBarSpriteId]);
        sData->hpBarSpriteId = SPRITE_NONE;
    }

    DestroyHpBarEndcaps(&sData->hpBarLeftEndcapSpriteId, &sData->hpBarRightEndcapSpriteId);
    FreeSpriteTilesByTag(B_INFO_DETAIL_HP_BAR_TILE_TAG);
}

static void Detail_RefreshHpBar(void)
{
    enum BattlerId battler = GetSelectedBattler();
    s16 hp = gBattleMons[battler].hp;
    s16 maxHp = gBattleMons[battler].maxHP;
    struct Sprite *sprite;

    if (sData->hpBarSpriteId == SPRITE_NONE)
    {
        sData->hpBarSpriteId = CreateHpBarSprite(B_INFO_DETAIL_HP_BAR_TILE_TAG, 21, 70);
        CreateHpBarEndcaps(&sData->hpBarLeftEndcapSpriteId, &sData->hpBarRightEndcapSpriteId);
    }

    sprite = &gSprites[sData->hpBarSpriteId];
    sprite->x = 21;
    sprite->y = 70;
    if (maxHp <= 0)
    {
        sprite->invisible = TRUE;
        if (sData->hpBarLeftEndcapSpriteId != SPRITE_NONE)
            gSprites[sData->hpBarLeftEndcapSpriteId].invisible = TRUE;
        if (sData->hpBarRightEndcapSpriteId != SPRITE_NONE)
            gSprites[sData->hpBarRightEndcapSpriteId].invisible = TRUE;
        return;
    }

    UpdateHpBarTilesWithWidth(sData->hpBarSpriteId, hp, maxHp,
                              B_INFO_DETAIL_HEALTHBAR_PIXELS, B_INFO_DETAIL_HP_BAR_SEGMENTS);

    sprite->invisible = FALSE;
    UpdateHpBarEndcaps(sData->hpBarLeftEndcapSpriteId,
                       sData->hpBarRightEndcapSpriteId,
                       21, 70,
                       B_INFO_DETAIL_HP_BAR_SEGMENTS);
}

static void Detail_DestroyStatusIcon(void)
{
    if (sData->statusSpriteId != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sData->statusSpriteId]);
        sData->statusSpriteId = SPRITE_NONE;
    }
}

static void Detail_RefreshStatusIcon(void)
{
    u32 ailment = GetAilmentFromBattler(GetSelectedBattler());

    Detail_DestroyStatusIcon();

    if (ailment == AILMENT_NONE || ailment == AILMENT_PKRS)
        return;

    sData->statusSpriteId = CreateSprite(&gSpriteTemplate_StatusIcons, 46, 66, 0);
    StartSpriteAnim(&gSprites[sData->statusSpriteId], ailment - 1);
    gSprites[sData->statusSpriteId].oam.priority = 0;
}

static void Detail_DrawLRButtonGlyphs(void)
{
    u32 itemWindowId = sData->windowIds[WIN_DETAIL_ITEM_ABILITY];
    u32 statsWindowId = sData->windowIds[WIN_DETAIL_STATS];

    u32 itemWindowWidth = WindowWidthPx(itemWindowId);
    u32 itemWindowHeight = GetWindowAttribute(itemWindowId, WINDOW_HEIGHT) * 8;
    s32 rGlyphWidth = GetKeypadIconWidth(CHAR_R_BUTTON);

    if (rGlyphWidth == 0)
        rGlyphWidth = GetStringWidth(FONT_SHORT_NARROW, sText_BattleInfo_DetailRButtonGlyph, 0);

    s32 itemAbsTop = GetWindowAttribute(itemWindowId, WINDOW_TILEMAP_TOP) * 8;
    s32 statsAbsTop = GetWindowAttribute(statsWindowId, WINDOW_TILEMAP_TOP) * 8;

    s32 itemY = itemWindowHeight - KEYPAD_ICON_HEIGHT - 1;
    itemY -= 5;
    itemY = max(itemY, 1);

    s32 alignedAbsY = itemAbsTop + itemY;
    s32 statsY = alignedAbsY - statsAbsTop;
    statsY -= 1;
    statsY = max(statsY, 0);

    s32 statsX = 1;
    s32 itemX = itemWindowWidth - rGlyphWidth - 2;
    itemX = max(itemX, 1);
    itemY -= 1;
    itemY = max(itemY, 0);

    struct PrintText text = {
        .windowId = statsWindowId,
        .font = FONT_SHORT_NARROW,
        .color = sTextColor_BattleInfo_Default,
        .speed = TEXT_SKIP_DRAW,
        .string = sText_BattleInfo_DetailLButtonGlyph,
    };

    text.left = statsX;
    text.top = statsY;
    PrintTextOnWindow(&text);

    text.left = itemX;
    text.top = itemY;
    PrintTextOnWindow(&text);
}

static void Detail_DestroyTeraTypeIndicator(void)
{
    if (sData->teraTypeSpriteId != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sData->teraTypeSpriteId]);
        sData->teraTypeSpriteId = SPRITE_NONE;
    }

    FreeSpriteTilesByTag(B_INFO_DETAIL_TERA_TYPE_TILE_TAG);
}

static void Detail_RefreshTeraTypeIndicator(void)
{
    u32 windowId = sData->windowIds[WIN_DETAIL_HEADER];
    struct SpriteSheet sheet;
    struct SpriteTemplate template = sSpriteTemplate_BattleInfoDetailGimmick;

    Detail_DestroyTeraTypeIndicator();

    if (!FlagGet(B_FLAG_TERA_ORB_CHARGED))
        return;

    enum Type teraType = GetBattlerTeraType(GetSelectedBattler());
    const u32 *indicatorData = GetTeraIndicatorSpriteSrc(teraType);
    if (indicatorData == NULL)
        return;

    sheet.data = (const u8 *)indicatorData;
    sheet.size = B_INFO_DETAIL_GIMMICK_GFX_SIZE;
    sheet.tag = B_INFO_DETAIL_TERA_TYPE_TILE_TAG;
    LoadSpriteSheet(&sheet);

    template.tileTag = B_INFO_DETAIL_TERA_TYPE_TILE_TAG;
    template.paletteTag = TAG_TERA_INDICATOR_PAL;

    u32 windowLeftPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT) * 8;
    u32 windowTopPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP) * 8;
    sData->teraTypeSpriteId = CreateSprite(&template, windowLeftPx + 24 + (B_INFO_DETAIL_GIMMICK_W / 2), windowTopPx + 23, 0);

    if (sData->teraTypeSpriteId != SPRITE_NONE)
        gSprites[sData->teraTypeSpriteId].oam.priority = 0;
}

static const u8 *GetGimmickIndicatorData(enum BattlerId battler, u32 *palTag)
{
    const u32 *indicatorData = GetIndicatorSpriteSrc(battler);

    *palTag = GetIndicatorPalTag(battler);
    if (indicatorData == NULL || *palTag == TAG_NONE)
        return NULL;

    return (const u8 *)indicatorData;
}

static void Detail_DestroyGimmickIndicator(void)
{
    if (sData->gimmickSpriteId != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sData->gimmickSpriteId]);
        sData->gimmickSpriteId = SPRITE_NONE;
    }

    FreeSpriteTilesByTag(B_INFO_DETAIL_GIMMICK_TILE_TAG);
}

static void Detail_RefreshGimmickIndicator(void)
{
    u32 windowId = sData->windowIds[WIN_DETAIL_HEADER];
    const u8 *indicatorData;
    u32 palTag;
    struct SpriteTemplate template = sSpriteTemplate_BattleInfoDetailGimmick;
    struct SpriteSheet sheet;
    s16 windowLeftPx;
    s16 windowTopPx;
    s16 indicatorLeftPx;
    s16 indicatorTopPx;

    Detail_DestroyGimmickIndicator();

    indicatorData = GetGimmickIndicatorData(GetSelectedBattler(), &palTag);
    if (indicatorData == NULL || palTag == 0)
        return;

    sheet.data = indicatorData;
    sheet.size = B_INFO_DETAIL_GIMMICK_GFX_SIZE;
    sheet.tag = B_INFO_DETAIL_GIMMICK_TILE_TAG;
    LoadSpriteSheet(&sheet);

    template.paletteTag = palTag;
    windowLeftPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT) * 8;
    windowTopPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP) * 8;
    indicatorLeftPx = windowLeftPx + 2;
    indicatorTopPx = windowTopPx + 33;

    sData->gimmickSpriteId = CreateSprite(&template, indicatorLeftPx + (B_INFO_DETAIL_GIMMICK_W / 2), indicatorTopPx + (B_INFO_DETAIL_GIMMICK_H / 2), 0);

    if (sData->gimmickSpriteId != SPRITE_NONE)
        gSprites[sData->gimmickSpriteId].oam.priority = 0;
}

static void Detail_RefreshItemAbilityWindow(void)
{
    enum BattlerId battler = GetSelectedBattler();
    u32 windowId = sData->windowIds[WIN_DETAIL_HEADER];
    u32 statsWindowId = sData->windowIds[WIN_DETAIL_STATS];

    if (IsOnPlayerSide(battler) || B_INFO_OPPOSING_INFORMATION)
    {
        struct PrintText text = {
            .windowId = windowId,
            .font = FONT_SHORT_NARROW,
            .color = sTextColor_BattleInfo_Default,
            .speed = TEXT_SKIP_DRAW,
            .left = 50,
        };

        PrintHeldItemText(text, battler);
        PrintAbilityText(text, battler);
    }

    Detail_DrawLRButtonGlyphs();
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
    PutWindowTilemap(statsWindowId);
    CopyWindowToVram(statsWindowId, COPYWIN_FULL);
}

#define MAX_VALUE_WIDTH (B_INFO_DETAIL_ITEM_WIN_W * 8) - 6
static void PrintHeldItemText(struct PrintText text, enum BattlerId battler)
{
    text.top = 33;
    text.string = COMPOUND_STRING("Held Item");
    PrintTextOnWindow(&text);

    enum Item heldItem = gBattleMons[battler].item;
    const u8 *string = (heldItem != ITEM_NONE) ? GetItemName(heldItem) : COMPOUND_STRING("None");

    text.font = GetFontIdToFit(string, FONT_SMALL, 0, MAX_VALUE_WIDTH);
    text.top = 43;
    text.string = string;
    PrintTextOnWindow(&text);
}

static void PrintAbilityText(struct PrintText text, enum BattlerId battler)
{
    text.top = 56;
    text.string = COMPOUND_STRING("Ability");
    PrintTextOnWindow(&text);

    enum Ability ability = gBattleMons[battler].ability;
    const u8 *string = (ability != ABILITY_NONE) ? gAbilitiesInfo[ability].name : COMPOUND_STRING("None");

    text.font = GetFontIdToFit(string, FONT_SMALL, 0, MAX_VALUE_WIDTH);
    text.top = 66;
    text.string = string;
    PrintTextOnWindow(&text);
}
#undef MAX_VALUE_WIDTH

static void Detail_RefreshHeader(void)
{
    u32 windowId = sData->windowIds[WIN_DETAIL_HEADER];
    struct Pokemon *mon = GetBattlerMon(GetSelectedBattler());

    Detail_DrawWindowFrame(windowId);
    s32 genderX = WindowWidthPx(windowId) - 2 - B_INFO_GENDER_W;
    u8 maxLevelText[2] = { CHAR_EXTRA_SYMBOL, CHAR_LV_2 };

    ConvertIntToDecimalStringN(maxLevelText + 2, 999, STR_CONV_MODE_LEFT_ALIGN, 3);

    s32 levelMaxWidth = GetStringWidth(FONT_SMALL, maxLevelText, 0);
    s32 levelX = genderX - 2 - levelMaxWidth;
    levelX = max(levelX, 2);

    struct PrintText text = {
        .windowId = windowId,
        .color = sTextColor_BattleInfo_Default,
        .speed = TEXT_SKIP_DRAW,
    };

    Detail_PrintMonName(text, mon, levelX);
    Detail_DisplayMonGender(text, mon, genderX);
    Detail_DisplayMonLevel(text, mon, levelX);
    Detail_DisplayGimmickIndicator(text);

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void Detail_PrintMonName(struct PrintText text, struct Pokemon *mon, s32 levelX)
{
    u8 monName[POKEMON_NAME_LENGTH + 1];
    GetMonData(mon, MON_DATA_NICKNAME, monName);
    u32 maxNameWidth = max(levelX - 4, 16);
    text.font = GetFontIdToFit(monName, FONT_NORMAL, 0, maxNameWidth);
    text.left = 2;
    text.top = 2;
    text.string = monName;
    PrintTextOnWindow(&text);
}

static void Detail_DisplayMonGender(struct PrintText text, struct Pokemon *mon, s32 genderX)
{
    enum Gender gender = GetMonGender(mon);

    if (gender == MON_MALE || gender == MON_FEMALE)
    {
        text.color = (gender == MON_MALE) ? sTextColor_BattleInfo_Male : sTextColor_BattleInfo_Female;

        u8 genderSymbol[2];
        genderSymbol[0] = (gender == MON_MALE) ? CHAR_MALE : CHAR_FEMALE;
        genderSymbol[1] = EOS;
        text.font = FONT_SMALL;
        text.left = genderX;
        text.top = 2;
        text.string = genderSymbol;
        PrintTextOnWindow(&text);
    }
}

static void Detail_DisplayMonLevel(struct PrintText text, struct Pokemon *mon, s32 levelX)
{
    u32 level = GetMonData(mon, MON_DATA_LEVEL);
    u8 levelText[2] = { CHAR_EXTRA_SYMBOL, CHAR_LV_2 };
    ConvertIntToDecimalStringN(levelText + 2, level, STR_CONV_MODE_LEFT_ALIGN, 3);

    text.font = FONT_SMALL;
    text.left = levelX;
    text.top = 2;
    text.string = levelText;
    PrintTextOnWindow(&text);
}

static void Detail_DisplayGimmickIndicator(struct PrintText text)
{
    Detail_DestroyGimmickIndicator();

    if (FlagGet(B_FLAG_TERA_ORB_CHARGED) && IsOnPlayerSide(GetSelectedBattler()))
    {
        text.font = FONT_SMALL_NARROWER;
        text.left = 2;
        text.top = 14;
        text.string = COMPOUND_STRING("Tera\nType:");
        PrintTextOnWindow(&text);
        Detail_RefreshTeraTypeIndicator();
    }
    else
    {
        Detail_DestroyTeraTypeIndicator();
    }

    Detail_RefreshGimmickIndicator();
}

static void Detail_RefreshIcon(void)
{
    struct Pokemon *mon;
    enum Species species;
    u32 personality;

    if (sData->iconSpriteId != SPRITE_NONE)
    {
        FreeAndDestroyMonIconSprite(&gSprites[sData->iconSpriteId]);
        sData->iconSpriteId = SPRITE_NONE;
    }

    mon = GetBattlerMon(GetSelectedBattler());
    species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG);
    personality = GetMonData(mon, MON_DATA_PERSONALITY);

    sData->iconSpriteId = CreateMonIcon(species, SpriteCallbackDummy, 33, 52, 0, personality);
    if (sData->iconSpriteId != SPRITE_NONE)
        gSprites[sData->iconSpriteId].oam.priority = 0;
}

static void Detail_DestroyTypeIcons(void)
{
    for (u32 i = 0; i < ARRAY_COUNT(sData->typeIconSpriteIds); i++)
    {
        if (sData->typeIconSpriteIds[i] != SPRITE_NONE)
        {
            DestroySprite(&gSprites[sData->typeIconSpriteIds[i]]);
            sData->typeIconSpriteIds[i] = SPRITE_NONE;
        }
    }
}

static void Detail_RefreshTypeIcons(void)
{
    enum BattlerId battler = GetSelectedBattler();
    enum Type type1 = gBattleMons[battler].types[0];
    enum Type type2 = gBattleMons[battler].types[1];
    u32 windowId = sData->windowIds[WIN_DETAIL_HEADER];

    Detail_DestroyTypeIcons();

    if (GetActiveGimmick(battler) == GIMMICK_TERA)
    {
        type1 = GetBattlerTeraType(battler);
        type2 = type1;
    }

    s32 windowLeftPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT) * 8;
    s32 windowTopPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP) * 8;

    s32 rightAlignedTypeRightPx = windowLeftPx + WindowWidthPx(windowId) - 2;
    s32 type2LeftPx = rightAlignedTypeRightPx - 32;
    s32 type1LeftPx = type2LeftPx - 33;

    u32 spriteId = CreateSprite(&gSpriteTemplate_MoveTypes, type1LeftPx + 16, windowTopPx + 25, 0);

    StartSpriteAnim(&gSprites[spriteId], type1);
    gSprites[spriteId].oam.paletteNum = gTypesInfo[type1].palette;
    gSprites[spriteId].oam.priority = 0;
    sData->typeIconSpriteIds[0] = spriteId;

    if (type2 == type1)
        return;

    spriteId = CreateSprite(&gSpriteTemplate_MoveTypes, type2LeftPx + 16, windowTopPx + 25, 0);

    StartSpriteAnim(&gSprites[spriteId], type2);
    gSprites[spriteId].oam.paletteNum = gTypesInfo[type2].palette;
    gSprites[spriteId].oam.priority = 0;
    sData->typeIconSpriteIds[1] = spriteId;
}

static s32 Detail_GetStatRowTextY(u32 row)
{
    u32 y = 15 + row * 9;

    if (row >= 5)
        y += 3;

    return y;
}

static void Detail_SetStatPipSpriteGraphic(u32 spriteId, u16 tileTag)
{
    u32 tileStart;

    if (spriteId == SPRITE_NONE)
        return;

    tileStart = GetSpriteTileStartByTag(tileTag);

    if (tileStart == 0xFFFF)
        return;

    gSprites[spriteId].oam.tileNum = tileStart;
}

static void Detail_CreateStatPips(void)
{
    u32 windowId = sData->windowIds[WIN_DETAIL_STATS];

    Detail_DestroyStatPips();

    LoadSpritePaletteInSlot(&(struct SpritePalette){
        .data = gBattleInfoTextPalette,
        .tag = B_INFO_DETAIL_STAT_PIP_PAL_TAG,
    }, B_INFO_DETAIL_STAT_PIP_PAL_NUM);
    LoadSpriteSheet(&sSpriteSheet_BattleInfoDetailStatPipDot);
    LoadSpriteSheet(&sSpriteSheet_BattleInfoDetailStatPipUp);
    LoadSpriteSheet(&sSpriteSheet_BattleInfoDetailStatPipDown);

    s32 windowLeftPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT) * 8;
    s32 windowTopPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP) * 8;

    for (u32 row = 0; row < B_INFO_DETAIL_STAT_ROW_COUNT; row++)
    {
        s32 rowY = windowTopPx + Detail_GetStatRowTextY(row) + 8;

        for (u32 col = 0; col < B_INFO_DETAIL_STAT_PIPS_PER_ROW; col++)
        {
            u32 spriteId = CreateSprite(&sSpriteTemplate_BattleInfoDetailStatPip,
                                       windowLeftPx + 56 + col * 8,
                                       rowY, 0);
            sData->statPipSpriteIds[row][col] = spriteId;

            if (spriteId == SPRITE_NONE)
                continue;

            gSprites[spriteId].invisible = FALSE;
            gSprites[spriteId].oam.priority = 0;
        }
    }
}

static void Detail_DestroyStatPips(void)
{
    for (u32 row = 0; row < B_INFO_DETAIL_STAT_ROW_COUNT; row++)
    {
        for (u32 col = 0; col < B_INFO_DETAIL_STAT_PIPS_PER_ROW; col++)
        {
            u32 spriteId = sData->statPipSpriteIds[row][col];

            if (spriteId != SPRITE_NONE)
                DestroySprite(&gSprites[spriteId]);
            sData->statPipSpriteIds[row][col] = SPRITE_NONE;
        }
    }

    FreeSpriteTilesByTag(B_INFO_DETAIL_STAT_PIP_DOT_TILE_TAG);
    FreeSpriteTilesByTag(B_INFO_DETAIL_STAT_PIP_UP_TILE_TAG);
    FreeSpriteTilesByTag(B_INFO_DETAIL_STAT_PIP_DOWN_TILE_TAG);
    FreeSpritePaletteByTag(B_INFO_DETAIL_STAT_PIP_PAL_TAG);
}

static void Detail_RefreshStatPips(void)
{
    enum BattlerId battler = GetSelectedBattler();

    for (u32 row = 0; row < B_INFO_DETAIL_STAT_ROW_COUNT; row++)
    {
        s32 delta = gBattleMons[battler].statStages[sBattleInfoDetailStatIds[row]] - DEFAULT_STAT_STAGE;
        u32 absDelta = (delta >= 0) ? delta : -delta;
        u32 tileTag = B_INFO_DETAIL_STAT_PIP_DOT_TILE_TAG;

        if (absDelta > B_INFO_DETAIL_STAT_PIPS_PER_ROW)
            absDelta = B_INFO_DETAIL_STAT_PIPS_PER_ROW;

        if (delta > 0)
            tileTag = B_INFO_DETAIL_STAT_PIP_UP_TILE_TAG;
        else if (delta < 0)
            tileTag = B_INFO_DETAIL_STAT_PIP_DOWN_TILE_TAG;

        for (u32 col = 0; col < B_INFO_DETAIL_STAT_PIPS_PER_ROW; col++)
        {
            u32 spriteId = sData->statPipSpriteIds[row][col];
            u32 currentTag = (col < absDelta) ? tileTag : B_INFO_DETAIL_STAT_PIP_DOT_TILE_TAG;

            Detail_SetStatPipSpriteGraphic(spriteId, currentTag);
        }
    }
}

static void Detail_CycleBattler(s8 direction)
{
    Detail_DestroyGimmickIndicator();
    Detail_DestroyTeraTypeIndicator();

    u32 cardCount = GetCardCount();

    if (direction < 0)
    {
        do {
            if (sData->selectedCard == 0)
                sData->selectedCard = cardCount - 1;
            else
                sData->selectedCard--;
        } while (!CanViewCard(GetSelectedBattler()));
    }
    else
    {
        do {
            sData->selectedCard++;
            if (sData->selectedCard >= cardCount)
                sData->selectedCard = 0;
        } while (!CanViewCard(GetSelectedBattler()));
    }

    Detail_RefreshIcon();
    Detail_RefreshHpBar();
    Detail_RefreshStatusIcon();
    Detail_RefreshTypeIcons();
    Detail_RefreshHeader();
    Detail_RefreshItemAbilityWindow();
    Detail_RefreshStatPips();
    Detail_InitEffectsList();
}

static void Detail_InitEffectsList(void)
{
    Detail_DestroyEffectsScrollbar();
    sData->activeEffectsCount = 0;
    sData->effectsCursor = 0;
    sData->effectsScroll = 0;
    Detail_BuildActiveEffectsForBattler();
    Detail_RefreshEffectsSection();
}

static void Detail_BuildActiveEffectsForBattler(void)
{
    enum BattlerId battler = GetSelectedBattler();
    enum BattleSide side = GetBattlerSide(battler);

    struct FieldTimer *fieldStatus = &gFieldTimers;
    struct SideTimer *sideStatus = &gSideTimers[side];
    struct Volatiles *vol = &gBattleMons[battler].volatiles;

    bool32 critBoost = (vol->focusEnergy || vol->dragonCheer);
    bool32 foresight = (vol->foresight || vol->miracleEye);


    TryAddActiveWeather(GetStatusEffectFromWeather(), side);
    TryAddActiveTerrain(GetStatusEffectFromTerrain(), side);
    TryAddActiveScreen(INFO_LIGHT_SCREEN, SIDE_STATUS_LIGHTSCREEN, sideStatus->lightscreenTimer, sideStatus->lightscreenTimerTotal, side);
    TryAddActiveScreen(INFO_REFLECT, SIDE_STATUS_REFLECT, sideStatus->reflectTimer, sideStatus->reflectTimerTotal, side);
    TryAddActiveScreen(INFO_AURORA_VEIL, SIDE_STATUS_AURORA_VEIL, sideStatus->auroraVeilTimer, sideStatus->auroraVeilTimerTotal, side);

    TryAddActiveFieldStatus(INFO_TRICK_ROOM, STATUS_FIELD_TRICK_ROOM, fieldStatus->trickRoomTimer, 5, side);
    TryAddActiveFieldStatus(INFO_MAGIC_ROOM, STATUS_FIELD_MAGIC_ROOM, fieldStatus->magicRoomTimer, 5, side);
    TryAddActiveFieldStatus(INFO_WONDER_ROOM, STATUS_FIELD_WONDER_ROOM, fieldStatus->wonderRoomTimer, 5, side);
    TryAddActiveFieldStatus(INFO_GRAVITY, STATUS_FIELD_GRAVITY, fieldStatus->gravityTimer, 5, side);
    TryAddActiveFieldStatus(INFO_MUD_SPORT, STATUS_FIELD_MUDSPORT, fieldStatus->mudSportTimer, 5, side);
    TryAddActiveFieldStatus(INFO_WATER_SPORT, STATUS_FIELD_WATERSPORT, fieldStatus->waterSportTimer, 5, side);
    TryAddActiveFieldStatus(INFO_FAIRY_LOCK, STATUS_FIELD_FAIRY_LOCK, fieldStatus->fairyLockTimer, 2, side);

    TryAddActiveSideStatus(INFO_MIST, SIDE_STATUS_MIST, sideStatus->mistTimer, 5, side);
    TryAddActiveSideStatus(INFO_SAFEGUARD, SIDE_STATUS_SAFEGUARD, sideStatus->safeguardTimer, 5, side);
    TryAddActiveSideStatus(INFO_LUCKY_CHANT, SIDE_STATUS_LUCKY_CHANT, sideStatus->luckyChantTimer, 5, side);
    TryAddActiveSideStatus(INFO_TAILWIND, SIDE_STATUS_TAILWIND, sideStatus->tailwindTimer, (GetConfig(B_TAILWIND_TURNS) >= GEN_5 ? 4 : 3), side);
    TryAddActiveSideStatus(INFO_RAINBOW, SIDE_STATUS_RAINBOW, sideStatus->rainbowTimer, 4, side);
    TryAddActiveSideStatus(INFO_SWAMP, SIDE_STATUS_SWAMP, sideStatus->swampTimer, 4, side);
    TryAddActiveSideStatus(INFO_SEA_OF_FIRE, SIDE_STATUS_SEA_OF_FIRE, sideStatus->seaOfFireTimer, 4, side);
    TryAddActiveSideStatus(INFO_STEALTH_ROCK, IsHazardOnSide(side, HAZARDS_STEALTH_ROCK), 0, 0, side);
    TryAddActiveSideStatus(INFO_SPIKES, IsHazardOnSide(side, HAZARDS_SPIKES), 0, 0, side);
    TryAddActiveSideStatus(INFO_TOXIC_SPIKES, IsHazardOnSide(side, HAZARDS_TOXIC_SPIKES), 0, 0, side);
    TryAddActiveSideStatus(INFO_STICKY_WEB, IsHazardOnSide(side, HAZARDS_STICKY_WEB), 0, 0, side);
    TryAddeActiveDamageNonTypes(side);

    TryAddActiveStatus(GetStatusEffectFromNonVolatile(battler), PERMANENT_STATUS, side);
    TryAddActiveStatus(INFO_INFATUATION, vol->infatuation, side);
    TryAddActiveStatus(INFO_NIGHTMARE, vol->nightmare, side);
    TryAddActiveStatus(INFO_TORMENT, vol->torment, side);
    TryAddActiveStatus(INFO_GRUDGE, vol->grudge, side);
    TryAddActiveStatus(INFO_LOCK_ON, vol->lockOn, side);
    TryAddActiveStatus(INFO_INGRAIN, vol->root, side);
    TryAddActiveStatus(INFO_AQUA_RING, vol->aquaRing, side);
    TryAddActiveStatus(INFO_CURSE, vol->cursed, side);
    TryAddActiveStatus(INFO_DESTINY_BOND, vol->destinyBond, side);
    TryAddActiveStatus(INFO_AUTOTOMIZE, vol->autotomizeCount, side);
    TryAddActiveStatus(INFO_TAR_SHOT, vol->tarShot, side);
    TryAddActiveStatus(INFO_OCTOLOCK, vol->octolock, side);
    TryAddActiveStatus(INFO_FIXATED, vol->glaiveRush, side);
    TryAddActiveStatus(INFO_STANCE_SWAP, vol->powerTrick, side);
    TryAddActiveStatus(INFO_SMACK_DOWN, vol->smackDown, side);
    TryAddActiveStatus(INFO_SALT_CURE, vol->saltCure, side);
    TryAddActiveStatus(INFO_TAUNT, vol->tauntTimer, side);
    TryAddActiveStatus(INFO_CHARGE, vol->chargeTimer, side);
    TryAddActiveStatus(INFO_BOUND, vol->wrapTurns, side);
    TryAddActiveStatus(INFO_RAMPAGING, vol->rampageTurns, side);
    TryAddActiveStatus(INFO_CONFUSION, vol->confusionTimer, side);
    TryAddActiveStatus(INFO_CANT_ESCAPE, vol->escapePrevention, side);
    TryAddActiveStatus(INFO_CRITICAL_HIT_BOOST, critBoost, side);
    TryAddActiveStatus(INFO_IDENTIFIED, foresight, side);
    TryAddActiveStatusTimer(INFO_DROWSY, vol->yawn, 2, side);
    TryAddActiveStatusTimer(INFO_HEALING_PREVENTED, vol->healBlockTimer, B_HEAL_BLOCK_TIMER, side);
    TryAddActiveStatusTimer(INFO_EMBARGO, vol->embargoTimer, B_EMBARGO_TIMER, side);
    TryAddActiveStatusTimer(INFO_TELEKINESIS, vol->telekinesisTimer, B_TELEKINESIS_TIMER, side);
    TryAddActiveStatusTimer(INFO_MAGNET_RISE, vol->magnetRiseTimer, B_MAGNET_RISE_TIMER, side);
    TryAddActiveStatusTimer(INFO_BIDE, vol->bideTurns, 2, side);
    TryAddActiveStatusTimer(INFO_FUTURE_ATTACK, gBattleStruct->futureSight[battler].counter, 3, side);
    TryAddActiveStatusTimer(INFO_THROAT_CHOP, vol->throatChopTimer, B_THROAT_CHOP_TIMER, side);
    TryAddActiveStatusTimer(INFO_LASER_FOCUS, vol->laserFocusTimer, B_LASER_FOCUS_TIMER, side);
    TryAddActiveStatusTimer(INFO_SLOW_START, vol->slowStartTimer, B_SLOW_START_TIMER, side);
    TryAddActiveStatusTimer(INFO_SYRUPY, vol->syrupBombTimer, B_SYRUP_BOMB_TIMER, side);
    TryAddActiveStatusTimer(INFO_WISH, gBattleStruct->wish[battler].counter, 2, side);

    if (B_DISABLE_TURNS >= GEN_5)
        TryAddActiveStatusTimer(INFO_MOVE_DISABLED, vol->disableTimer, B_DISABLE_TIMER, side);
    else
        TryAddActiveStatus(INFO_MOVE_DISABLED, vol->disableTimer, side);

    if (B_UPROAR_TURNS >= GEN_5)
        TryAddActiveStatusTimer(INFO_UPROAR, vol->uproarTurns, B_UPROAR_TURN_COUNT - 2, side);
    else
        TryAddActiveStatus(INFO_UPROAR, vol->uproarTurns, side);

    if (B_ENCORE_TURNS >= GEN_5)
        TryAddActiveStatusTimer(INFO_ENCORE, vol->encoreTimer, B_ENCORE_TIMER, side);
    else
        TryAddActiveStatus(INFO_ENCORE, vol->encoreTimer, side);
}

static void TryAddActiveWeather(enum BattleInfoLabels label, enum BattleSide side)
{
    if (gBattleStruct->weatherDuration > 0)
    {
        struct DisplayTimer timer = {
            .baseTotal = 5,
            .extendedTotal = gBattleStruct->weatherDurationTotal,
            .remaining = gBattleStruct->weatherDuration,
        };

        if (ShouldShowIncreasedDuration(gBattleStruct->weatherSide))
        {
            TryAddActiveStatusTimer(label, timer.remaining, timer.extendedTotal, side);
        }
        else
        {
            SetRemainingDuration(&timer);
            TryAddActiveStatusTimer(label, timer.remaining, timer.baseTotal, side);
        }
    }
    else
    {
        TryAddActiveStatus(label, PERMANENT_STATUS, side);
    }
}

static void TryAddActiveTerrain(enum BattleInfoLabels status, enum BattleSide side)
{
    if (gFieldTimers.terrainTimer > 0)
    {
        struct DisplayTimer timer = {
            .baseTotal = 5,
            .extendedTotal = gFieldTimers.terrainTimerTotal,
            .remaining = gFieldTimers.terrainTimer,
        };

        if (ShouldShowIncreasedDuration(gFieldTimers.terrainSide))
        {
            TryAddActiveStatusTimer(status, timer.remaining, timer.extendedTotal, side);
        }
        else
        {
            SetRemainingDuration(&timer);
            TryAddActiveStatusTimer(status, timer.remaining, timer.baseTotal, side);
        }
    }
    else
    {
        TryAddActiveStatus(status, PERMANENT_STATUS, side);
    }
}

static void TryAddActiveScreen(enum BattleInfoLabels label, u32 sideStatus, u32 remaining, u32 extendedTotal, enum BattleSide side)
{
    if (remaining > 0)
    {
        struct DisplayTimer timer = {
            .baseTotal = 5,
            .extendedTotal = extendedTotal,
            .remaining = remaining,
        };

        if (ShouldShowIncreasedDuration(side))
        {
            TryAddActiveStatusTimer(label, timer.remaining, timer.extendedTotal, side);
        }
        else
        {
            SetRemainingDuration(&timer);
            TryAddActiveSideStatus(label, sideStatus, timer.remaining, timer.baseTotal, side);
        }
    }
    else
    {
        TryAddActiveSideStatus(label, sideStatus, PERMANENT_STATUS, 0, side);
    }
}

static bool32 ShouldShowIncreasedDuration(enum BattleSide side)
{
    if (side == B_SIDE_PLAYER)
        return TRUE;

    if (B_INFO_ALWAYS_SHOW_ACCURATE_DURATION)
        return TRUE;

    return FALSE;
}

static void SetRemainingDuration(struct DisplayTimer *timer)
{
    if (timer->extendedTotal == timer->baseTotal)
        return;

    s32 durationDifference = timer->extendedTotal - timer->baseTotal;

    if (timer->remaining == durationDifference)
        timer->baseTotal = timer->extendedTotal;
    else
        timer->remaining = timer->remaining - durationDifference;
}

static void TryAddActiveFieldStatus(enum BattleInfoLabels label, u32 fieldStatus, u32 timer, u32 totalTimer, enum BattleSide side)
{
    if (!(gFieldStatuses & fieldStatus))
        return;

    if (timer > 0)
        TryAddActiveStatusTimer(label, timer, totalTimer, side);
    else
        TryAddActiveStatus(label, PERMANENT_STATUS, side);
}

static void TryAddActiveSideStatus(enum BattleInfoLabels label, u32 sideStatus, u32 timer, u32 totalTimer, enum BattleSide side)
{
    if (!(gSideStatuses[side] & sideStatus))
        return;

    if (timer > 0)
        TryAddActiveStatusTimer(label, timer, totalTimer, side);
    else
        TryAddActiveStatus(label, PERMANENT_STATUS, side);
}

static void TryAddActiveStatus(enum BattleInfoLabels label, u32 timerOrFlag, enum BattleSide side)
{
    bool32 isNotTimer = FALSE;
    TryAddActiveStatusInternal(label, timerOrFlag, 0, side, isNotTimer);
}

static void TryAddActiveStatusTimer(enum BattleInfoLabels label, u32 remaining, u32 baseTotal, enum BattleSide side)
{
    bool32 isTimer = TRUE;
    TryAddActiveStatusInternal(label, remaining, baseTotal, side, isTimer);
}

static void TryAddActiveStatusInternal(enum BattleInfoLabels label, u32 timerOrFlag, u32 baseTotal, enum BattleSide side, bool32 isTimer)
{
    if (label == INFO_NONE)
        return;

    if (timerOrFlag == 0)
        return;

    if (baseTotal == 0)
        baseTotal = timerOrFlag;

    struct BattleInfo entry = {0};

    if (isTimer)
    {
        entry.durationRemaining = timerOrFlag;
        entry.baseTotalDuration = baseTotal;
        entry.durationKnown = TRUE;
    }

    entry.label = label;
    entry.setterSide = side;

    sData->activeEffects[sData->activeEffectsCount++] = entry;
}

static bool32 Detail_GetDisplayedDuration(const struct BattleInfo *entry, enum BattleSide viewerSide, struct Durations *duration)
{
    if (!entry->durationKnown)
        return FALSE;

    if (entry->baseTotalDuration == 0)
        return FALSE;

    u32 actualTotal = entry->baseTotalDuration;
    if (actualTotal == 0)
        return FALSE;

    u32 remaining = entry->durationRemaining;
    u32 displayedTotal = actualTotal;

    duration->remaining = remaining;
    duration->total = displayedTotal;
    return TRUE;
}

static enum BattleInfoLabels GetStatusEffectFromWeather(void)
{
    switch (GetBattleWeather(gBattleWeather))
    {
    case BATTLE_WEATHER_NONE:          return INFO_NONE;
    case BATTLE_WEATHER_RAIN:          return INFO_RAIN;
    case BATTLE_WEATHER_RAIN_DOWNPOUR: return INFO_RAIN;
    case BATTLE_WEATHER_RAIN_PRIMAL:   return INFO_HEAVY_RAIN;
    case BATTLE_WEATHER_SUN:           return INFO_HARSH_SUNLIGHT;
    case BATTLE_WEATHER_SUN_PRIMAL:    return INFO_EXTREMELY_HARSH_SUNLIGHT;
    case BATTLE_WEATHER_SANDSTORM:     return INFO_SANDSTORM;
    case BATTLE_WEATHER_HAIL:          return INFO_SNOW;
    case BATTLE_WEATHER_SNOW:          return INFO_SNOW;
    case BATTLE_WEATHER_FOG:           return INFO_FOG;
    case BATTLE_WEATHER_STRONG_WINDS:  return INFO_STRONG_WINDS;
    case BATTLE_WEATHER_COUNT:         return INFO_NONE;
    }

    return INFO_NONE;
}

static enum BattleInfoLabels GetStatusEffectFromTerrain(void)
{
    switch (gFieldTimers.terrain)
    {
    case B_TERRAIN_ELECTRIC: return INFO_ELECTRIC_TERRAIN;
    case B_TERRAIN_GRASSY:   return INFO_GRASSY_TERRAIN;
    case B_TERRAIN_MISTY:    return INFO_MISTY_TERRAIN;
    case B_TERRAIN_PSYCHIC:  return INFO_PSYCHIC_TERRAIN;
    case B_TERRAIN_NONE:     return INFO_NONE;
    case B_TERRAIN_COUNT:    return INFO_NONE;
    }

    return INFO_NONE;
}

static enum BattleInfoLabels GetStatusEffectFromNonVolatile(enum BattlerId battler)
{
    switch (gBattleMons[battler].status1)
    {
    case STATUS1_TOXIC_POISON: return INFO_BADLY_POISONED;
    case STATUS1_POISON:       return INFO_POISONED;
    case STATUS1_PARALYSIS:    return INFO_PARALYZED;
    case STATUS1_BURN:         return INFO_BURNED;
    case STATUS1_FROSTBITE:    return INFO_FROSTBITE;
    }

    return INFO_NONE;
}

static void TryAddeActiveDamageNonTypes(enum BattleSide side)
{
    if (!(gSideStatuses[side] & SIDE_STATUS_DAMAGE_NON_TYPES))
        return;

    switch (gSideTimers[side].damageNonTypesType)
    {
    case TYPE_FIRE:
        TryAddActiveStatus(INFO_G_MAX_WILDFIRE, PERMANENT_STATUS, side);
        break;
    case TYPE_ROCK:
        TryAddActiveStatus(INFO_G_MAX_VOLCALITH, PERMANENT_STATUS, side);
        break;
    case TYPE_GRASS:
        TryAddActiveStatus(INFO_G_MAX_VINE_LASH, PERMANENT_STATUS, side);
        break;
    case TYPE_WATER:
        TryAddActiveStatus(INFO_G_MAX_CANNONADE, PERMANENT_STATUS, side);
        break;
    default:
        break;
    }
}

static void Detail_BuildTurnFractionText(u8 *dst, u16 remaining, u16 total)
{
    u8 *str = dst;

    str = ConvertIntToDecimalStringN(str, remaining, STR_CONV_MODE_LEFT_ALIGN, 2);
    *(str++) = CHAR_SLASH;
    str = ConvertIntToDecimalStringN(str, total, STR_CONV_MODE_LEFT_ALIGN, 2);
    *str = EOS;
}

static bool32 Detail_TryMoveEffectCursor(s8 direction)
{
    if (sData->activeEffectsCount == 0)
        return FALSE;

    if (direction < 0)
    {
        if (sData->effectsCursor == 0)
            return FALSE;
        sData->effectsCursor--;
    }
    else if (direction > 0)
    {
        if (sData->effectsCursor + 1 >= sData->activeEffectsCount)
            return FALSE;
        sData->effectsCursor++;
    }
    else
    {
        return FALSE;
    }

    if (sData->effectsCursor < sData->effectsScroll)
        sData->effectsScroll = sData->effectsCursor;
    else if (sData->effectsCursor >= sData->effectsScroll + B_INFO_DETAIL_EFFECTS_VISIBLE_ROWS)
        sData->effectsScroll = sData->effectsCursor - B_INFO_DETAIL_EFFECTS_VISIBLE_ROWS + 1;

    return TRUE;
}

static void Detail_CopyTextToFit(u8 *dst, const u8 *src, u8 fontId, s16 maxWidth)
{
    const u8 *in = src;
    u8 *out = dst;

    if (maxWidth <= 0)
    {
        dst[0] = EOS;
        return;
    }

    while (*in != EOS)
    {
        *out = *in;
        out[1] = EOS;
        if (GetStringWidth(fontId, dst, 0) > maxWidth)
        {
            *out = EOS;
            break;
        }
        out++;
        in++;
    }
    *out = EOS;
}

static void DisplayRow(u32 windowId, u32 row, u32 index, u32 fractionYOffset)
{
    u32 y = 16 + row * 12;
    const struct BattleInfo *entry = &sData->activeEffects[index];
    const struct BattleInfoEffectData *effectData = &sBattleInfoEffects[entry->label];

    if (index == sData->effectsCursor)
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROWER, 2, y, 0, 0, sTextColor_BattleInfo_Default, TEXT_SKIP_DRAW, gText_SelectorArrow2);

    struct Durations duration = {0};
    bool32 hasFraction = Detail_GetDisplayedDuration(entry, B_SIDE_PLAYER, &duration);

    if (hasFraction || entry->stackCount > 0)
    {
        u32 textLength = hasFraction ? 24 : 8;
        u8 text[textLength];
        u8 nameBuffer[64];

        u8 *stackPtr = text;

        if (hasFraction)
        {
            Detail_BuildTurnFractionText(text, duration.remaining, duration.total);
        }
        else if (entry->stackCount > 0)
        {
            *(stackPtr++) = CHAR_PLUS;
            stackPtr = ConvertIntToDecimalStringN(stackPtr, entry->stackCount, STR_CONV_MODE_LEFT_ALIGN, 1);
            *stackPtr = EOS;
        }

        s32 windowWidth = WindowWidthPx(windowId);
        s32 fractionWidth = GetStringWidth(FONT_SMALL_NARROWER, text, 0);

        s32 fractionX = windowWidth - 6 - 2 - fractionWidth;
        fractionX = max(fractionX, 10);

        s32 maxNameWidth = fractionX - 10 - 2;
        maxNameWidth = max(maxNameWidth, 0);

        Detail_CopyTextToFit(nameBuffer, effectData->name, FONT_SHORT_NARROWER, maxNameWidth);

        AddTextPrinterParameterized4(windowId, FONT_SHORT_NARROWER, 10, y, 0, 0,
                                     sTextColor_BattleInfo_Default, TEXT_SKIP_DRAW, nameBuffer);

        s32 fractionY = y + fractionYOffset;
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROWER, fractionX, fractionY, 0, 0,
                                     sTextColor_BattleInfo_Default, TEXT_SKIP_DRAW, text);
    }
    else
    {
        AddTextPrinterParameterized4(windowId, FONT_SHORT_NARROWER, 10, y, 0, 0,
                                     sTextColor_BattleInfo_Default, TEXT_SKIP_DRAW, effectData->name);
    }
}

static void Detail_RefreshEffectsWindow(void)
{
    u32 windowId = sData->windowIds[WIN_DETAIL_EFFECTS];
    u8 fractionYOffset = 0;

    if (GetFontAttribute(FONT_SMALL_NARROWER, FONTATTR_MAX_LETTER_HEIGHT) < 12)
    {
        fractionYOffset = (12 - GetFontAttribute(FONT_SMALL_NARROWER, FONTATTR_MAX_LETTER_HEIGHT)) / 2;
    }

    Detail_DrawWindowFrame(windowId);
    AddTextPrinterParameterized4(windowId, FONT_NARROWER, 2, 2, 0, 0, sTextColor_BattleInfo_Default,
                                 TEXT_SKIP_DRAW, COMPOUND_STRING("Active States and Effects"));

    if (sData->activeEffectsCount != 0)
    {
        for (u32 row = 0; row < B_INFO_DETAIL_EFFECTS_VISIBLE_ROWS; row++)
        {
            u32 rowIndex = sData->effectsScroll + row;

            if (rowIndex >= sData->activeEffectsCount)
                break;

            DisplayRow(windowId, row, rowIndex, fractionYOffset);
        }
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
    Detail_RefreshEffectsScrollbar();
    Detail_UpdateEffectsCursor();
}

static void Detail_RefreshEffectsScrollbar(void)
{
    if (sData->activeEffectsCount <= B_INFO_DETAIL_EFFECTS_VISIBLE_ROWS)
    {
        Detail_UpdateScrollbarLane(FALSE);
        Detail_DestroyEffectsScrollbar();
        return;
    }

    Detail_UpdateScrollbarLane(TRUE);

    u32 windowId = sData->windowIds[WIN_DETAIL_EFFECTS];
    u32 windowLeftPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT) * 8;
    u32 windowTopPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP) * 8;
    u32 scrollbarX = windowLeftPx + WindowWidthPx(windowId) - 6;
    u32 scrollbarMinY = windowTopPx + 16 + 7;
    u32 scrollbarMaxY = scrollbarMinY + 3 + (B_INFO_DETAIL_EFFECTS_VISIBLE_ROWS - 1) * 12;
    u32 maxScroll = sData->activeEffectsCount - B_INFO_DETAIL_EFFECTS_VISIBLE_ROWS;

    if (sData->effectsScroll > maxScroll)
        sData->effectsScroll = maxScroll;

    u32 spriteId;
    if (sData->effectsScrollbarSpriteId == SPRITE_NONE)
    {
        spriteId = CreateSprite(&sSpriteTemplate_BattleInfoDetailEffectsScrollbar, scrollbarX, scrollbarMinY, 0);
        if (spriteId == SPRITE_NONE)
            return;
        sData->effectsScrollbarSpriteId = spriteId;
        gSprites[spriteId].oam.priority = 0;
    }

    spriteId = sData->effectsScrollbarSpriteId;
    gSprites[spriteId].x = scrollbarX;
    gSprites[spriteId].y = scrollbarMinY + (sData->effectsScroll * (scrollbarMaxY - scrollbarMinY) + (maxScroll / 2)) / maxScroll;
    gSprites[spriteId].invisible = FALSE;
}

static void SetBg1Tilemap(u32 bottomTileY, u32 laneX, u32 scrollbarTile, bool32 hasScrollbar)
{
    u32 index = bottomTileY * B_INFO_TILEMAP_WIDTH + laneX;

    if (hasScrollbar)
        sData->bg1Tilemap[index] = (sData->bg1Tilemap[index] & 0xFC00) | scrollbarTile;
    else
        sData->bg1Tilemap[index] = sBattleInfoMenuDetailsBaseTilemap[index];
}

static void Detail_UpdateScrollbarLane(bool8 hasScrollbar)
{
    u32 windowId = sData->windowIds[WIN_DETAIL_EFFECTS];
    s32 laneX = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT) + (WindowWidthPx(windowId) - 6) / 8;

    if (laneX < 0 || laneX >= B_INFO_TILEMAP_WIDTH)
        return;

    s32 laneYStart = (GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP) + (16 / 8)) + 1;
    s32 laneTileCount = (((B_INFO_DETAIL_EFFECTS_VISIBLE_ROWS * 12) + 7) / 8) + 1;

    if (laneTileCount <= 0)
        return;

    for (u32 i = 0; i < laneTileCount; i++)
    {
        s32 tileY = laneYStart + i;

        if (tileY < 0 || tileY >= B_INFO_TILEMAP_HEIGHT)
            continue;

        SetBg1Tilemap(tileY, laneX, B_INFO_BG_TILE_SCROLLBAR_BOTTOM, hasScrollbar);
    }

    if (laneTileCount > 0)
    {
        s32 topTileY = laneYStart - 1;
        s32 bottomTileY = laneYStart + laneTileCount;

        if (topTileY >= 0 && topTileY < B_INFO_TILEMAP_HEIGHT)
            SetBg1Tilemap(topTileY, laneX, B_INFO_BG_TILE_SCROLLBAR_BOTTOM, hasScrollbar);

        if (bottomTileY >= 0 && bottomTileY < B_INFO_TILEMAP_HEIGHT)
            SetBg1Tilemap(bottomTileY, laneX, B_INFO_BG_TILE_SCROLLBAR_BOTTOM, hasScrollbar);
    }

    CopyBgTilemapBufferToVram(B_INFO_BACKDROP_BG);
}

static void Detail_SetDescriptionPlaceholder(enum BattleInfoLabels  label)
{
    gStringVar1[0] = EOS;
    switch (label)
    {
    case INFO_ENCORE:
        StringCopy(gStringVar1, COMPOUND_STRING("its last move"));
        break;
    case INFO_MOVE_DISABLED:
        StringCopy(gStringVar1, COMPOUND_STRING("A move"));
        break;
    case INFO_G_MAX_WILDFIRE:
        StringCopy(gStringVar1, COMPOUND_STRING("Fire"));
        break;
    case INFO_G_MAX_VOLCALITH:
        StringCopy(gStringVar1, COMPOUND_STRING("Rock"));
        break;
    case INFO_G_MAX_VINE_LASH:
        StringCopy(gStringVar1, COMPOUND_STRING("Grass"));
        break;
    case INFO_G_MAX_CANNONADE:
        StringCopy(gStringVar1, COMPOUND_STRING("Water"));
        break;
    default:
        StringCopy(gStringVar1, COMPOUND_STRING(""));
        break;
    }
}

static void Detail_FormatDescriptionText(enum BattleInfoLabels  label, u8 *dst)
{
    Detail_SetDescriptionPlaceholder(label);
    StringExpandPlaceholders(dst, sBattleInfoEffects[label].description);
}

static void Detail_ClampTextLines(u8 *text, u8 maxLines)
{
    u32 line = 1;

    while (*text != EOS)
    {
        if (*text == CHAR_NEWLINE)
        {
            line++;
            if (line > maxLines)
            {
                *text = EOS;
                return;
            }
        }
        text++;
    }
}

static void Detail_RefreshDescriptionWindow(void)
{
    u32 windowId = sData->windowIds[WIN_DETAIL_DESCRIPTION];
    u32 descFont = FONT_SMALL_NARROWER;

    Detail_DrawWindowFrame(windowId);

    if (sData->activeEffectsCount == 0 || sData->effectsCursor >= sData->activeEffectsCount)
    {
        sData->detailTextBuffer[0] = EOS;
    }
    else
    {
        enum BattleInfoLabels  label = sData->activeEffects[sData->effectsCursor].label;
        Detail_FormatDescriptionText(label, sData->detailTextBuffer);
    }

    u32 wrapWidth = WindowWidthPx(windowId) - (2 * 2) - 2;
    wrapWidth = max(wrapWidth, 8);

    u32 windowHeightPx = GetWindowAttribute(windowId, WINDOW_HEIGHT) * 8;
    u32 availableHeight = (windowHeightPx > 2 + 1) ? windowHeightPx - 2 - 1 : 1;

    u32 lineHeight = GetFontAttribute(descFont, FONTATTR_MAX_LETTER_HEIGHT) + GetFontAttribute(descFont, FONTATTR_LINE_SPACING);
    lineHeight = max(lineHeight, 1);

    u32 maxLines = availableHeight / lineHeight;
    maxLines = max(maxLines, 1);

    BreakStringAutomatic(sData->detailTextBuffer, wrapWidth, maxLines, descFont, HIDE_SCROLL_PROMPT);

    u8 *end = sData->detailTextBuffer + StringLength(sData->detailTextBuffer);
    WrapFontIdToFit(sData->detailTextBuffer, end, descFont, wrapWidth);
    Detail_ClampTextLines(sData->detailTextBuffer, maxLines);

    if (sData->detailTextBuffer[0] != EOS)
    {
        AddTextPrinterParameterized4(windowId, descFont, 2, 2, 0, 0,
                                     sTextColor_BattleInfo_Default, TEXT_SKIP_DRAW, sData->detailTextBuffer);
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void Detail_RefreshEffectsSection(void)
{
    Detail_RefreshEffectsWindow();
    Detail_RefreshDescriptionWindow();
}

static void Detail_DestroyEffectsCursor(void)
{
    if (sData->cursorSpriteId == SPRITE_NONE)
        return;
    DestroySprite(&gSprites[sData->cursorSpriteId]);
    sData->cursorSpriteId = SPRITE_NONE;
}

static void Detail_DestroyEffectsScrollbar(void)
{
    if (sData->effectsScrollbarSpriteId == SPRITE_NONE)
        return;
    DestroySprite(&gSprites[sData->effectsScrollbarSpriteId]);
    sData->effectsScrollbarSpriteId = SPRITE_NONE;
}

static void Detail_UpdateEffectsCursor(void)
{
    Detail_DestroyEffectsCursor();
}

static void Detail_DrawWindowFrame(u32 windowId)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(B_INFO_TEXT_COLOR_TRANSPARENT));
}

static void Overview_ComputeRowLayout(s16 *outXs)
{
    s32 gapTiles = 0;
    s32 safeLeft = B_INFO_SAFE_LEFT_TILE;
    s32 safeRight = B_INFO_SAFE_RIGHT_TILE;
    s32 safeWidthTiles = safeRight - safeLeft + 1;
    s32 screenWidthTiles = DISPLAY_WIDTH / 8;
    u32 count = GetCardCount() / 2;

    s32 totalWidthTiles = count * B_INFO_CARD_TILE_W + (count - 1) * gapTiles;

    if (totalWidthTiles > safeWidthTiles)
    {
        gapTiles = 0;
        totalWidthTiles = count * B_INFO_CARD_TILE_W + (count - 1) * gapTiles;
    }

    s32 startXTile = (screenWidthTiles - totalWidthTiles) / 2;
    if (startXTile < safeLeft)
        startXTile = safeLeft;
    if (startXTile + totalWidthTiles - 1 > safeRight)
        startXTile = safeRight - totalWidthTiles + 1;
    if (startXTile < safeLeft)
        startXTile = safeLeft;

    for (u32 i = 0; i < count; i++)
        outXs[i] = (startXTile + i * (B_INFO_CARD_TILE_W + gapTiles)) * 8;
}

static void Overview_CreateCards(void)
{
    u32 enemySlots = 0;
    u32 playerSlots = 0;

    for (enum BattlerId battler = 0; battler < GetCardCount(); battler++)
    {
        if (IsOnPlayerSide(battler))
            playerSlots++;
        else
            enemySlots++;
    }

    s16 rowXs[MAX_BATTLERS_COUNT];

    u32 cardCount = 0;
    Overview_ComputeRowLayout(rowXs);

    for (u32 i = 0; i < enemySlots; i++)
    {
        struct BattleInfoCard *card = &sData->cards[cardCount++];
        card->x = rowXs[i];
        card->battler = GetBattlerFromEnemySlot(i);
        card->y = B_INFO_ROW_Y_ENEMY;
    }

    for (u32 i = 0; i < playerSlots; i++)
    {
        struct BattleInfoCard *card = &sData->cards[cardCount++];
        card->x = rowXs[i];
        card->battler = GetBattlerFromPlayerSlot(i);
        card->y = B_INFO_ROW_Y_PLAYER;
    }
}

static void Overview_DrawCards(void)
{
    for (u32 i = 0; i < GetCardCount(); i++)
    {
        if (!CanViewCard(GetBattlerFromSlot(i)))
            continue;

        Overview_DrawCard(&sData->cards[i]);
    }
}

static void Overview_DrawCard(struct BattleInfoCard *card)
{
    s32 contentYOffset = (card->y == B_INFO_ROW_Y_ENEMY) ? -2 : 0;
    struct Pokemon *mon = GetBattlerMon(card->battler);
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);

    Overview_PrintMonAndGender(card, mon, species, contentYOffset);
    CreateGimmickIndicator(card, card->y + 28 + contentYOffset);
    CreateMonAndStatusInon(card, species, GetMonData(mon, MON_DATA_PERSONALITY), contentYOffset);
    CreateHpBar(card, contentYOffset);
}

static void Overview_PrintMonAndGender(struct BattleInfoCard *card, struct Pokemon *mon, enum Species species, u32 contentYOffset)
{
    u32 windowId = (card->y == B_INFO_ROW_Y_ENEMY) ? WIN_ROW_ENEMY : WIN_ROW_PLAYER;
    u32 gender = GetMonGender(mon);
    bool32 hasGender = gender == MON_MALE || gender == MON_FEMALE;
    u32 localX = card->x;
    u32 localY = card->y;

    u32 row = (windowId == WIN_ROW_ENEMY) ? B_INFO_ROW_Y_ENEMY : B_INFO_ROW_Y_PLAYER;
    localY -= (row / 8) * 8;

    u32 maxNameWidth = B_INFO_CARD_W - 6;
    maxNameWidth -= hasGender ? B_INFO_GENDER_W + 4 : 0;

    u8 name[POKEMON_NAME_LENGTH + 1];
    GetMonData(mon, MON_DATA_NICKNAME, name);

    FillWindowPixelRect(windowId, PIXEL_FILL(B_INFO_TEXT_COLOR_TRANSPARENT), localX, localY, B_INFO_CARD_W, B_INFO_CARD_H);

    struct PrintText text = {
        .windowId = windowId,
        .speed = TEXT_SKIP_DRAW,
    };

    text.font = GetFontIdToFit(name, FONT_NORMAL, 0, maxNameWidth);
    text.top = localY + 2 + contentYOffset;
    text.left = localX + 6;
    text.color = sTextColor_BattleInfo_OverviewDefault;
    text.string = name;
    PrintTextOnWindow(&text);

    if (hasGender)
    {
        u8 genderSymbol[2];
        genderSymbol[0] = (gender == MON_MALE) ? CHAR_MALE : CHAR_FEMALE;
        genderSymbol[1] = EOS;

        text.font = FONT_SMALL,
        text.top = localY + 2 + contentYOffset,
        text.left = localX + B_INFO_CARD_W - B_INFO_GENDER_W - 2,
        text.color = (gender == MON_MALE) ? sTextColor_BattleInfo_Male : sTextColor_BattleInfo_Female,
        text.string = genderSymbol,
        PrintTextOnWindow(&text);
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void CreateGimmickIndicator(struct BattleInfoCard *card, u32 iconCenterY)
{
    u32 gimmickIndicatorPalTag;
    const u8 *gimmickIndicatorData = GetGimmickIndicatorData(card->battler, &gimmickIndicatorPalTag);

    if (gimmickIndicatorData == NULL || gimmickIndicatorPalTag == TAG_NONE)
        return;

    card->gimmickSpriteId = SPRITE_NONE;
    u32 gimmickTileTag = B_INFO_OVERVIEW_GIMMICK_TILE_TAG_BASE + card->battler;

    struct SpriteTemplate gimmickTemplate;
    gimmickTemplate = sSpriteTemplate_BattleInfoDetailGimmick;
    gimmickTemplate.tileTag = gimmickTileTag;
    gimmickTemplate.paletteTag = gimmickIndicatorPalTag;

    struct SpriteSheet gimmickSheet;
    gimmickSheet.data = gimmickIndicatorData;
    gimmickSheet.size = B_INFO_DETAIL_GIMMICK_GFX_SIZE;
    gimmickSheet.tag = gimmickTileTag;
    LoadSpriteSheet(&gimmickSheet);

    s32 x = card->x + (B_INFO_DETAIL_GIMMICK_W / 2) + 5;
    s32 y = iconCenterY - (B_INFO_DETAIL_GIMMICK_H / 2) - 3;
    card->gimmickSpriteId = CreateSprite(&gimmickTemplate, x, y, 0);

    if (card->gimmickSpriteId != SPRITE_NONE)
        gSprites[card->gimmickSpriteId].oam.priority = 0;
}

static void CreateMonAndStatusInon(struct BattleInfoCard *card, enum Species species, u32 personality, u32 contentYOffset)
{
    s32 iconCenterX = card->x + (B_INFO_CARD_W / 2);
    s32 iconCenterY = card->y + 28 + contentYOffset;

    card->monIconSpriteId = CreateMonIcon(species, SpriteCallbackDummy, iconCenterX, iconCenterY, 0, personality);
    gSprites[card->monIconSpriteId].oam.priority = 0;

    u32 ailment = GetAilmentFromBattler(card->battler);
    if (ailment != AILMENT_NONE && ailment != AILMENT_PKRS)
    {
        s16 statusX = iconCenterX + 13;
        s16 statusY = iconCenterY + 14;

        card->statusSpriteId = CreateSprite(&gSpriteTemplate_StatusIcons, statusX, statusY, 0);
        StartSpriteAnim(&gSprites[card->statusSpriteId], ailment - 1);
        gSprites[card->statusSpriteId].oam.priority = 0;
    }
}

static void CreateHpBar(struct BattleInfoCard *card, u32 contentYOffset)
{
    card->hpBarSpriteId = CreateHpBarSprite(B_INFO_HP_BAR_TILE_TAG_BASE + card->battler, card->x - 16, card->y + 46 + contentYOffset);
    CreateHpBarEndcaps(&card->hpBarLeftEndcapSpriteId, &card->hpBarRightEndcapSpriteId);
    DrawHpBarSprite(card);
}

static void Overview_SetBgTile(s16 x, s16 y, u16 tileNum, u16 attrs)
{
    sData->bg1Tilemap[y * B_INFO_TILEMAP_WIDTH + x] = tileNum | attrs;
}

static void LoadBackdropAssets(void)
{
    LoadBgTiles(B_INFO_BACKDROP_BG, sBattleInfoMenuBgTiles, sizeof(sBattleInfoMenuBgTiles), 0);
    LoadPalette(sBattleInfoMenuBgPalette, BG_PLTT_ID(0), sizeof(sBattleInfoMenuBgPalette));
}

static void BackdropLoadBaseTilemap(void)
{
    u32 mode = B_INFO_TILEMAP_WIDTH * B_INFO_TILEMAP_HEIGHT * sizeof(u16);
    CpuCopy16(sBattleInfoMenuDetailsBaseTilemap, sData->bg1Tilemap, mode);
    CopyBgTilemapBufferToVram(B_INFO_BACKDROP_BG);
}

static void Overview_FillBgRect(s16 x, s16 y, s16 width, s16 height, u16 tileNum, u16 attrs)
{
    for (u32 yi = y; yi < y + height; yi++)
    {
        for (u32 xi = x; xi < x + width; xi++)
            Overview_SetBgTile(xi, yi, tileNum, attrs);
    }
}

static u32 GetCenterRow(void)
{
    s32 gapTiles = 0;
    s32 safeLeft = B_INFO_SAFE_LEFT_TILE;
    s32 safeRight = B_INFO_SAFE_RIGHT_TILE;
    s32 safeWidthTiles = safeRight - safeLeft + 1;
    s32 screenWidthTiles = DISPLAY_WIDTH / 8;
    u32 count = GetCardCount() / 2;

    s32 totalWidthTiles = count * B_INFO_CARD_TILE_W + (count - 1) * gapTiles;

    if (totalWidthTiles > safeWidthTiles)
    {
        gapTiles = 0;
        totalWidthTiles = count * B_INFO_CARD_TILE_W + (count - 1) * gapTiles;
    }

    s32 startXTile = (screenWidthTiles - totalWidthTiles) / 2;

    if (startXTile < safeLeft)
        startXTile = safeLeft;
    if (startXTile + totalWidthTiles - 1 > safeRight)
        startXTile = safeRight - totalWidthTiles + 1;
    if (startXTile < safeLeft)
        startXTile = safeLeft;

    s16 outXs[count];
    for (u32 i = 0; i < count; i++)
        outXs[i] = (startXTile + i * (B_INFO_CARD_TILE_W + gapTiles)) * 8;

    u32 outRowLeft = outXs[0];
    u32 outRowRight = outXs[count - 1] + B_INFO_CARD_W;

    return (outRowLeft + outRowRight) / 2;
}

static void Overview_ComputeHeaderLayout(s16 labelWidth, u8 *outTextLenTiles, s16 *outHeaderX, s16 *outHeaderWidth)
{
    u32 textLenTiles = (labelWidth + 7) / 8;
    textLenTiles = max(textLenTiles, 1);

    if (textLenTiles & 1)
        textLenTiles++;

    s32 headerWidth = textLenTiles + 2;
    s32 headerX = (GetCenterRow() - ((headerWidth * 8) / 2)) / 8;
    if (headerX < B_INFO_SAFE_LEFT_TILE)
        headerX = B_INFO_SAFE_LEFT_TILE;
    if (headerX + headerWidth - 1 > B_INFO_SAFE_RIGHT_TILE)
        headerX = B_INFO_SAFE_RIGHT_TILE - headerWidth + 1;

    if (outTextLenTiles != NULL)
        *outTextLenTiles = textLenTiles;
    *outHeaderX = headerX;
    *outHeaderWidth = headerWidth;
}

static void Overview_DrawStatusCard(s16 x, s16 y, bool8 isActive, bool8 isBottomRow)
{
    u32 topLeftTile;
    u32 topEdgeTile;
    u32 sideEdgeTile;
    u32 fillTile;
    u32 bottomLeftTile;
    u32 bottomEdgeTile;
    u32 topAttrs = 0;
    u32 bottomAttrs = 0;

    u32 width = B_INFO_CARD_TILE_W;
    u32 height = B_INFO_CARD_TILE_H;

    if (isActive)
    {
        topLeftTile = B_INFO_BG_TILE_CARD_ACTIVE_TL;
        topEdgeTile = B_INFO_BG_TILE_CARD_ACTIVE_TE;
        sideEdgeTile = B_INFO_BG_TILE_CARD_ACTIVE_SE;
        fillTile = B_INFO_BG_TILE_CARD_ACTIVE_IN;
        bottomLeftTile = B_INFO_BG_TILE_CARD_ACTIVE_BL;
        bottomEdgeTile = B_INFO_BG_TILE_CARD_ACTIVE_BE;
    }
    else
    {
        topLeftTile = B_INFO_BG_TILE_CARD_INACTIVE_TL;
        topEdgeTile = B_INFO_BG_TILE_CARD_INACTIVE_TE;
        sideEdgeTile = B_INFO_BG_TILE_CARD_INACTIVE_SE;
        fillTile = B_INFO_BG_TILE_CARD_INACTIVE_IN;
        bottomLeftTile = B_INFO_BG_TILE_CARD_INACTIVE_BL;
        bottomEdgeTile = B_INFO_BG_TILE_CARD_INACTIVE_BE;
    }

    if (isBottomRow)
    {
        u32 swappedTopLeft = bottomLeftTile;
        u32 swappedTopEdge = bottomEdgeTile;
        u32 swappedBottomLeft = topLeftTile;
        u32 swappedBottomEdge = topEdgeTile;

        topLeftTile = swappedTopLeft;
        topEdgeTile = swappedTopEdge;
        bottomLeftTile = swappedBottomLeft;
        bottomEdgeTile = swappedBottomEdge;
        topAttrs = B_INFO_BG_ATTR_VFLIP;
        bottomAttrs = B_INFO_BG_ATTR_VFLIP;
    }

    Overview_SetBgTile(x, y, topLeftTile, topAttrs);
    Overview_SetBgTile(x + width - 1, y, topLeftTile, topAttrs | B_INFO_BG_ATTR_HFLIP);
    Overview_SetBgTile(x, y + height - 1, bottomLeftTile, bottomAttrs);
    Overview_SetBgTile(x + width - 1, y + height - 1, bottomLeftTile, bottomAttrs | B_INFO_BG_ATTR_HFLIP);

    for (u32 xi = x + 1; xi < x + width - 1; xi++)
    {
        Overview_SetBgTile(xi, y, topEdgeTile, topAttrs);
        Overview_SetBgTile(xi, y + height - 1, bottomEdgeTile, bottomAttrs);
    }

    for (u32 yi = y + 1; yi < y + height - 1; yi++)
    {
        Overview_SetBgTile(x, yi, sideEdgeTile, 0);
        Overview_SetBgTile(x + width - 1, yi, sideEdgeTile, B_INFO_BG_ATTR_HFLIP);
        for (u32 xi = x + 1; xi < x + width - 1; xi++)
            Overview_SetBgTile(xi, yi, fillTile, 0);
    }
}

static void Overview_DrawHeaderBox(u16 *tilemap, s16 x, s16 y, u8 textLenTiles)
{
    if (textLenTiles == 0)
        textLenTiles = 1;

    if (y < 0 || y + 2 >= B_INFO_TILEMAP_HEIGHT)
        return;

    u32 interior = textLenTiles;
    if (interior & 1)
        interior++;

    u32 width = min(B_INFO_TILEMAP_WIDTH, interior + 2);

    if (x < 0)
        x = 0;
    if (x + width > B_INFO_TILEMAP_WIDTH)
        x = B_INFO_TILEMAP_WIDTH - width;

    Overview_SetBgTile(x, y, B_INFO_BG_TILE_HEADER_CORNER, 0);
    Overview_SetBgTile(x + width - 1, y, B_INFO_BG_TILE_HEADER_CORNER, B_INFO_BG_ATTR_HFLIP);
    for (interior = x + 1; interior < x + width - 1; interior++)
        Overview_SetBgTile(interior, y, B_INFO_BG_TILE_HEADER_TOP, 0);

    Overview_SetBgTile(x, y + 1, B_INFO_BG_TILE_HEADER_SIDE, 0);
    Overview_SetBgTile(x + width - 1, y + 1, B_INFO_BG_TILE_HEADER_SIDE, B_INFO_BG_ATTR_HFLIP);
    for (interior = x + 1; interior < x + width - 1; interior++)
        Overview_SetBgTile(interior, y + 1, B_INFO_BG_TILE_HEADER_FILL, 0);

    Overview_SetBgTile(x, y + 2, B_INFO_BG_TILE_HEADER_CORNER, B_INFO_BG_ATTR_VFLIP);
    Overview_SetBgTile(x + width - 1, y + 2, B_INFO_BG_TILE_HEADER_CORNER, B_INFO_BG_ATTR_HFLIP | B_INFO_BG_ATTR_VFLIP);
    for (interior = x + 1; interior < x + width - 1; interior++)
        Overview_SetBgTile(interior, y + 2, B_INFO_BG_TILE_HEADER_TOP, B_INFO_BG_ATTR_VFLIP);
}

static void Overview_DrawCardBackground(const struct BattleInfoCard *card, bool8 isActive)
{
    s32 cardTileX = card->x / 8;
    s32 cardTileY = card->y / 8;
    Overview_FillBgRect(cardTileX, cardTileY,
                       B_INFO_CARD_TILE_W, B_INFO_CARD_TILE_H, B_INFO_BG_TILE_FILL, 0);
    Overview_DrawStatusCard(cardTileX, cardTileY, isActive, card->y == B_INFO_ROW_Y_PLAYER);
}

static void Overview_DrawBackground(void)
{
    s16 enemyLabelWidth;
    s16 playerLabelWidth;
    u8 enemyTextLenTiles;
    u8 playerTextLenTiles;
    s16 enemyHeaderX;
    s16 playerHeaderX;
    s16 enemyHeaderWidth;
    s16 playerHeaderWidth;

    CpuCopy16(sBattleInfoMenuOverviewBaseTilemap, sData->bg1Tilemap,
              B_INFO_TILEMAP_WIDTH * B_INFO_TILEMAP_HEIGHT * sizeof(u16));

    struct TileCoords {
        s16 top;
        s16 height;
    }tileCoords[] = {
        { B_INFO_ROW_Y_ENEMY / 8, B_INFO_CARD_TILE_H },
        { B_INFO_ROW_Y_PLAYER / 8, B_INFO_CARD_TILE_H },
        { 0, B_INFO_LABEL_TILE_H },
        { B_INFO_LABEL_BOTTOM_TILE_TOP, B_INFO_LABEL_TILE_H },
    };

    for (u32 i = 0; i < ARRAY_COUNT(tileCoords); i++)
    {
        Overview_FillBgRect(
            B_INFO_SAFE_LEFT_TILE,
            tileCoords[i].top,
            B_INFO_SAFE_RIGHT_TILE - B_INFO_SAFE_LEFT_TILE + 1,
            tileCoords[i].height,
            B_INFO_BG_TILE_FILL, 0
        );
    }

    for (u32 i = 0; i < GetCardCount(); i++)
        Overview_DrawCardBackground(&sData->cards[i], i == sData->selectedCard);

    enemyLabelWidth = GetStringWidth(FONT_SMALL, GetPrimaryOpponentTrainerName(), 0);
    playerLabelWidth = GetStringWidth(FONT_SMALL, GetPlayerSideTrainerName(), 0);
    Overview_ComputeHeaderLayout(enemyLabelWidth, &enemyTextLenTiles, &enemyHeaderX, &enemyHeaderWidth);
    Overview_ComputeHeaderLayout(playerLabelWidth, &playerTextLenTiles, &playerHeaderX, &playerHeaderWidth);

    Overview_DrawHeaderBox(sData->bg1Tilemap, enemyHeaderX, 0, enemyTextLenTiles);
    Overview_DrawHeaderBox(sData->bg1Tilemap, playerHeaderX, B_INFO_LABEL_BOTTOM_TILE_TOP, playerTextLenTiles);

    CopyBgTilemapBufferToVram(B_INFO_BACKDROP_BG);
}

static void Overview_UpdateCardSelectionHighlight(u8 oldSelectedIndex)
{
    u32 cardCount = GetCardCount();

    if (oldSelectedIndex < cardCount)
        Overview_DrawCardBackground(&sData->cards[oldSelectedIndex], FALSE);
    if (sData->selectedCard < cardCount)
        Overview_DrawCardBackground(&sData->cards[sData->selectedCard], TRUE);

    CopyBgTilemapBufferToVram(B_INFO_BACKDROP_BG);
}

static void Overview_DrawLabels(void)
{
    s16 enemyHeaderX;
    s16 playerHeaderX;
    s16 enemyHeaderWidth;
    s16 playerHeaderWidth;
    s32 labelHeight = GetFontAttribute(FONT_SMALL, FONTATTR_MAX_LETTER_HEIGHT);

    const u8 *enemyLabel = GetPrimaryOpponentTrainerName();
    const u8 *playerLabel = GetPlayerSideTrainerName();

    s32 enemyLabelWidth = GetStringWidth(FONT_SMALL, enemyLabel, 0);
    s32 playerLabelWidth = GetStringWidth(FONT_SMALL, playerLabel, 0);
    Overview_ComputeHeaderLayout(enemyLabelWidth, NULL, &enemyHeaderX, &enemyHeaderWidth);
    Overview_ComputeHeaderLayout(playerLabelWidth, NULL, &playerHeaderX, &playerHeaderWidth);

    s32 enemyLabelX = enemyHeaderX * 8 + ((enemyHeaderWidth * 8) - enemyLabelWidth) / 2;
    s32 playerLabelX = playerHeaderX * 8 + ((playerHeaderWidth * 8) - playerLabelWidth) / 2;

    if (labelHeight <= 0 || labelHeight > B_INFO_LABEL_H)
        labelHeight = 8;

    s32 labelY = (B_INFO_LABEL_H - labelHeight) / 2;
    labelY -= 2;
    labelY = max(labelY, 0);

    struct PrintText text = {
        .font = FONT_SMALL,
        .color = sTextColor_BattleInfo_Default,
        .speed = TEXT_SKIP_DRAW,
        .top = labelY,
    };

    FillWindowPixelBuffer(WIN_LABEL_TOP, PIXEL_FILL(B_INFO_TEXT_COLOR_TRANSPARENT));
    text.windowId = WIN_LABEL_TOP;
    text.left = enemyLabelX;
    text.string = enemyLabel;
    PrintTextOnWindow(&text);
    PutWindowTilemap(WIN_LABEL_TOP);
    CopyWindowToVram(WIN_LABEL_TOP, COPYWIN_FULL);

    FillWindowPixelBuffer(WIN_LABEL_BOTTOM, PIXEL_FILL(B_INFO_TEXT_COLOR_TRANSPARENT));
    text.windowId = WIN_LABEL_BOTTOM;
    text.left = playerLabelX;
    text.string = playerLabel;
    PrintTextOnWindow(&text);
    PutWindowTilemap(WIN_LABEL_BOTTOM);
    CopyWindowToVram(WIN_LABEL_BOTTOM, COPYWIN_FULL);
}

static const u8 *GetPlayerSideTrainerName(void)
{
    if (HasPartnerTrainer(B_BATTLER_0))
        return COMPOUND_STRING("Ally");
    return gSaveBlock2Ptr->playerName;
}

static const u8 *GetPrimaryOpponentTrainerName(void)
{
    if (GetOpponentTrainerCount() == 1 && gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        return GetTrainerNameFromId(TRAINER_BATTLE_PARAM.opponentA);
    return COMPOUND_STRING("Opponent");
}

static u32 GetOpponentTrainerCount(void)
{
    if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
        return 0;

    if ((gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_MULTI)) && !BATTLE_TWO_VS_ONE_OPPONENT)
        return 2;

    return 1;
}

static void DestroyOverviewCardSprites(struct BattleInfoCard *card, bool8 freeHpBarTile)
{
    DestroyHpBarEndcaps(&card->hpBarLeftEndcapSpriteId, &card->hpBarRightEndcapSpriteId);

    if (card->statusSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[card->statusSpriteId]);

    if (card->updateSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[card->updateSpriteId]);

    if (card->monIconSpriteId != SPRITE_NONE)
        FreeAndDestroyMonIconSprite(&gSprites[card->monIconSpriteId]);

    if (card->gimmickSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[card->gimmickSpriteId]);

    if (card->gimmickSpriteId != SPRITE_NONE)
        DestroySpriteAndFreeResources(&gSprites[card->gimmickSpriteId]);

    if (card->hpBarSpriteId != SPRITE_NONE)
        DestroySpriteAndFreeResources(&gSprites[card->hpBarSpriteId]);

    card->hpBarSpriteId = SPRITE_NONE;
    card->statusSpriteId = SPRITE_NONE;
    card->updateSpriteId = SPRITE_NONE;
    card->monIconSpriteId = SPRITE_NONE;
    card->gimmickSpriteId = SPRITE_NONE;
}

static void BattleInfoDestroy(void)
{
    if (sData->cursorSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sData->cursorSpriteId]);
    sData->cursorSpriteId = SPRITE_NONE;

    Detail_DestroyWindows();
    Detail_DestroyHpBar();
    Detail_DestroyStatusIcon();
    Detail_DestroyTeraTypeIndicator();
    Detail_DestroyGimmickIndicator();
    Detail_DestroyTypeIcons();
    Detail_DestroyStatPips();
    Detail_DestroyEffectsScrollbar();

    if (sData->iconSpriteId != SPRITE_NONE)
    {
        FreeAndDestroyMonIconSprite(&gSprites[sData->iconSpriteId]);
        sData->iconSpriteId = SPRITE_NONE;
    }

    for (u32 i = 0; i < GetCardCount(); i++)
    {
        DestroyOverviewCardSprites(&sData->cards[i], TRUE);
    }

    RemoveWindow(WIN_LABEL_TOP);
    RemoveWindow(WIN_LABEL_BOTTOM);
    RemoveWindow(WIN_ROW_ENEMY);
    RemoveWindow(WIN_ROW_PLAYER);

    FreeSpritePaletteByTag(B_INFO_HP_BAR_PAL_TAG);
    FreeSpritePaletteByTag(B_INFO_HP_BAR_ENDCAP_PAL_TAG);
    FreeSpriteTilesByTag(B_INFO_HP_BAR_ENDCAP_LEFT_TILE_TAG);
    FreeSpriteTilesByTag(B_INFO_HP_BAR_ENDCAP_RIGHT_TILE_TAG);
    FreeSpriteTilesByTag(B_INFO_UPDATE_ICON_TILE_TAG);
    FreeSpriteTilesByTag(B_INFO_CURSOR_TILE_TAG);
    FreeSpriteTilesByTag(B_INFO_DETAIL_EFFECTS_SCROLLBAR_TILE_TAG);
    FreeSpritePaletteByTag(gSpriteTemplate_MoveTypes.paletteTag);
    FreeSpritePaletteByTag(B_INFO_MOVE_TYPES_PAL_TAG_1);
    FreeSpritePaletteByTag(B_INFO_MOVE_TYPES_PAL_TAG_2);
    FreeSpriteTilesByTag(TAG_STATUS_ICONS);
    FreeSpritePaletteByTag(TAG_STATUS_ICONS);
    FreeMonIconPalettes();

    FREE_AND_SET_NULL(sData);
}

static u32 CreateHpBarSprite(u16 tileTag, s16 x, s16 y)
{
    struct SpriteSheet sheet = {
        sBattleInfoHpBarTiles, sizeof(sBattleInfoHpBarTiles), tileTag
    };

    struct SpriteTemplate template = sSpriteTemplate_BattleInfoHpBar;
    u32 spriteId;

    LoadSpriteSheet(&sheet);
    template.tileTag = tileTag;
    spriteId = CreateSprite(&template, x, y, 0);

    if (spriteId != SPRITE_NONE)
    {
        SetSubspriteTables(&gSprites[spriteId], sBattleInfoHpBarSubspriteTable);
        gSprites[spriteId].subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        gSprites[spriteId].invisible = TRUE;
        gSprites[spriteId].oam.priority = 0;
    }

    return spriteId;
}

static void DestroyHpBarEndcaps(u8 *leftEndcapSpriteId, u8 *rightEndcapSpriteId)
{
    if (*leftEndcapSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[*leftEndcapSpriteId]);
    if (*rightEndcapSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[*rightEndcapSpriteId]);
    *leftEndcapSpriteId = SPRITE_NONE;
    *rightEndcapSpriteId = SPRITE_NONE;
}

static void CreateHpBarEndcaps(u8 *leftEndcapSpriteId, u8 *rightEndcapSpriteId)
{
    DestroyHpBarEndcaps(leftEndcapSpriteId, rightEndcapSpriteId);

    *leftEndcapSpriteId = CreateSprite(&sSpriteTemplate_BattleInfoHpBarLeftEndcap, 0, 0, 0);
    if (*leftEndcapSpriteId != SPRITE_NONE)
    {
        gSprites[*leftEndcapSpriteId].oam.priority = 0;
        gSprites[*leftEndcapSpriteId].invisible = TRUE;
    }

    *rightEndcapSpriteId = CreateSprite(&sSpriteTemplate_BattleInfoHpBarRightEndcap, 0, 0, 0);
    if (*rightEndcapSpriteId != SPRITE_NONE)
    {
        gSprites[*rightEndcapSpriteId].oam.priority = 0;
        gSprites[*rightEndcapSpriteId].invisible = TRUE;
    }
}

static void UpdateHpBarEndcaps(u8 leftEndcapSpriteId, u8 rightEndcapSpriteId, s16 barCenterX, s16 barY, u8 segmentCount)
{
    s16 leftEdge;
    s16 rightEndcapStart;

    if (segmentCount > B_INFO_HP_BAR_SEGMENTS)
        segmentCount = B_INFO_HP_BAR_SEGMENTS;

    leftEdge = barCenterX - 32;
    rightEndcapStart = leftEdge + 8 + (segmentCount * 8);

    if (leftEndcapSpriteId != SPRITE_NONE)
    {
        gSprites[leftEndcapSpriteId].x = leftEdge + 20;
        gSprites[leftEndcapSpriteId].y = barY + 4;
        gSprites[leftEndcapSpriteId].invisible = FALSE;
    }
    if (rightEndcapSpriteId != SPRITE_NONE)
    {
        gSprites[rightEndcapSpriteId].x = rightEndcapStart + 20;
        gSprites[rightEndcapSpriteId].y = barY + 4;
        gSprites[rightEndcapSpriteId].invisible = FALSE;
    }
}

static void UpdateHpBarTilesWithWidth(u32 spriteId, s16 hp, s16 maxHp, u8 totalPixels, u8 segmentCount)
{
    u32 array[B_INFO_HP_BAR_SEGMENTS];
    void *dst;

    u32 filledPixels = GetScaledHPFraction(hp, maxHp, totalPixels);
    u32 barElementId = GetBarGfxId(hp, maxHp);

    for (u32 i = 0; i < B_INFO_HP_BAR_SEGMENTS; i++)
        array[i] = 0;

    if (filledPixels == 0 && hp > 0)
        filledPixels = 1;

    for (u32 i = 0; i < segmentCount; i++)
    {
        if (filledPixels >= 8)
        {
            array[i] = 8;
            filledPixels -= 8;
        }
        else
        {
            array[i] = filledPixels;
            filledPixels = 0;
        }
    }

    u32 tileNum = gSprites[spriteId].oam.tileNum;
    for (u32 i = 0; i < B_INFO_HP_BAR_SEGMENTS; i++)
    {
        if (i < 3)
            dst = (void *)(OBJ_VRAM0 + (tileNum + 1 + i) * TILE_SIZE_4BPP);
        else
            dst = (void *)(OBJ_VRAM0 + 64 + (tileNum + i - 1) * TILE_SIZE_4BPP);

        if (i >= segmentCount)
        {
            CpuFill16(0, dst, 32);
            continue;
        }

        CpuCopy32(&gHealthboxElementsGfxTable[barElementId][array[i] * 32],
                  dst, 32);
    }
}

static void UpdateHpBarTiles(u32 spriteId, s16 hp, s16 maxHp)
{
    UpdateHpBarTilesWithWidth(spriteId, hp, maxHp, B_INFO_HEALTHBAR_PIXELS, B_INFO_HP_BAR_SEGMENTS);
}

static void DrawHpBarSprite(struct BattleInfoCard *card)
{
    struct Sprite *sprite;
    s16 hp = gBattleMons[card->battler].hp;
    s16 maxHp = gBattleMons[card->battler].maxHP;
    s16 contentYOffset = (card->y == B_INFO_ROW_Y_ENEMY) ? -2 : 0;

    sprite = &gSprites[card->hpBarSpriteId];
    sprite->x = card->x + (B_INFO_CARD_W / 2) - 16;
    sprite->y = card->y + 46 + contentYOffset;

    UpdateHpBarTiles(card->hpBarSpriteId, hp, maxHp);
    UpdateHpBarEndcaps(card->hpBarLeftEndcapSpriteId, card->hpBarRightEndcapSpriteId,
                       sprite->x, sprite->y, B_INFO_HP_BAR_SEGMENTS);
    sprite->invisible = FALSE;
}

static u32 GetBarGfxId(s16 hp, s16 maxHp)
{
    switch (GetHPBarLevel(hp, maxHp))
    {
    case HP_BAR_GREEN:
    case HP_BAR_FULL:
        return HEALTHBOX_GFX_HP_BAR_GREEN;
    case HP_BAR_YELLOW:
        return HEALTHBOX_GFX_HP_BAR_YELLOW;
    case HP_BAR_RED:
    default:
        return HEALTHBOX_GFX_HP_BAR_RED;
    }

    return HEALTHBOX_GFX_HP_BAR_RED;
}

static u32 GetAilmentFromBattler(enum BattlerId battler)
{
    if (!IsBattlerAlive(battler))
        return AILMENT_FNT;

    return GetAilmentFromStatus(gBattleMons[battler].status1);
}

static void Overview_GetCursorPos(const struct BattleInfoCard *card, s16 *outX, s16 *outY)
{
    *outX = card->x + 2;
    *outY = card->y + (B_INFO_CARD_H / 2) + 2;
}

static void Overview_InitCursor(void)
{
    s16 cursorX;
    s16 cursorY;

    if (sData->cursorSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sData->cursorSpriteId]);

    Overview_GetCursorPos(&sData->cards[sData->selectedCard], &cursorX, &cursorY);
    sData->cursorSpriteId = CreateSprite(&sSpriteTemplate_BattleInfoCursor, cursorX, cursorY, 0);
    if (sData->cursorSpriteId != SPRITE_NONE)
        gSprites[sData->cursorSpriteId].oam.priority = 0;
}

static void Overview_UpdateCursorPos(void)
{
    struct BattleInfoCard *card;
    card = &sData->cards[sData->selectedCard];
    Overview_GetCursorPos(card, &gSprites[sData->cursorSpriteId].x, &gSprites[sData->cursorSpriteId].y);
}

static void Task_BattleMenuStatus_HandleInput(u8 taskId)
{
    if (sData->page == B_INFO_PAGE_OVERVIEW)
        Overview_HandleInput(taskId);
    else
        Detail_HandleInput(taskId);
}

static void Overview_HandleInput(u8 taskId)
{
    if (JOY_NEW(DPAD_LEFT))
    {
        Overview_TryMoveCursor(B_INFO_CURSOR_LEFT);
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        Overview_TryMoveCursor(B_INFO_CURSOR_RIGHT);
    }
    else if (JOY_NEW(DPAD_UP))
    {
        Overview_TryMoveCursor(B_INFO_CURSOR_UP);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        Overview_TryMoveCursor(B_INFO_CURSOR_DOWN);
    }
    else if (JOY_NEW(A_BUTTON) && CanViewCard(GetSelectedBattler()))
    {
        PlaySE(SE_SELECT);
        sData->menuState = B_INFO_STATE_CLEAR_PAGE;
        sData->page = B_INFO_PAGE_DETAIL;
        gTasks[taskId].func = Task_BattleInfoLoadPage;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sData->menuState = B_INFO_STATE_EXIT;
        gTasks[taskId].func = Task_BattleInfoLoadPage;
    }
}

static void Detail_HandleInput(u8 taskId)
{
    s8 scrollDir = 0;

    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        sData->menuState = B_INFO_STATE_CLEAR_PAGE;
        sData->page = B_INFO_PAGE_OVERVIEW;
        gTasks[taskId].func = Task_BattleInfoLoadPage;
    }
    else if (JOY_NEW(L_BUTTON))
    {
        PlaySE(SE_SELECT);
        Detail_CycleBattler(-1);
    }
    else if (JOY_NEW(R_BUTTON))
    {
        PlaySE(SE_SELECT);
        Detail_CycleBattler(1);
    }
    else
    {
        if (JOY_REPEAT(DPAD_UP))
            scrollDir = -1;
        else if (JOY_REPEAT(DPAD_DOWN))
            scrollDir = 1;

        if (scrollDir != 0 && Detail_TryMoveEffectCursor(scrollDir))
        {
            PlaySE(SE_SELECT);
            Detail_RefreshEffectsSection();
        }
    }
}

static void Overview_TryMoveCursor(u32 direction)
{
    u32 currSelectedCard = sData->selectedCard;

    switch (direction)
    {
    case B_INFO_CURSOR_LEFT:
    case B_INFO_CURSOR_RIGHT:
        if (IsDoubleBattle())
            sData->selectedCard ^= 1;
        break;
    case B_INFO_CURSOR_UP:
    case B_INFO_CURSOR_DOWN:
        if (IsDoubleBattle())
            sData->selectedCard ^= 2;
        else
            sData->selectedCard ^= 1;
        break;
    }

    Overview_UpdateCardSelectionHighlight(currSelectedCard);
    Overview_UpdateCursorPos();
}

static u32 GetCardCount(void)
{
    return gBattlersCount;
}

static bool32 CanViewCard(enum BattlerId battler)
{
    return IsBattlerAlive(battler);
}

static enum BattlerId GetSelectedBattler(void)
{
    return sData->cards[sData->selectedCard].battler;
}

static enum BattlerId GetBattlerFromSlot(u32 slot)
{
    if (IsDoubleBattle())
    {
        switch (slot)
        {
        case 0: return B_BATTLER_1;
        case 1: return B_BATTLER_3;
        case 2: return B_BATTLER_0;
        case 3: return B_BATTLER_2;
        }
    }
    else
    {
        switch (slot)
        {
        case 0: return B_BATTLER_1;
        case 1: return B_BATTLER_0;
        }
    }

    return B_BATTLER_1;
}

static enum BattlerId GetBattlerFromEnemySlot(u32 slot)
{
    switch (slot)
    {
    case 0: return B_BATTLER_1;
    case 1: return B_BATTLER_3;
    }

    return B_BATTLER_1;
}

static enum BattlerId GetBattlerFromPlayerSlot(u32 slot)
{
    switch (slot)
    {
    case 0: return B_BATTLER_0;
    case 1: return B_BATTLER_2;
    }

    return B_BATTLER_1;
}
