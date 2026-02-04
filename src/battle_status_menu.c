#include "global.h"
#include "battle_status_menu.h"
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
#include "constants/battle.h"
#include "constants/party_menu.h"
#include "constants/abilities.h"
#include "constants/characters.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/pokemon.h"

enum
{
    BATTLE_STATUS_MENU_STATE_FADE_IN,
    BATTLE_STATUS_MENU_STATE_WAIT_INPUT,
    BATTLE_STATUS_MENU_STATE_FADE_OUT,
};

enum
{
    BATTLE_STATUS_PAGE_OVERVIEW,
    BATTLE_STATUS_PAGE_DETAIL,
};

enum
{
    BSTATUS_TEXT_COLOR_TRANSPARENT,
    BSTATUS_TEXT_COLOR_BLACK,
    BSTATUS_TEXT_COLOR_DARK_GRAY,
    BSTATUS_TEXT_COLOR_LIGHT_GRAY,
    BSTATUS_TEXT_COLOR_WHITE,
    BSTATUS_TEXT_COLOR_LIGHT_BLUE,
    BSTATUS_TEXT_COLOR_BLUE,
    BSTATUS_TEXT_COLOR_PINK,
    BSTATUS_TEXT_COLOR_DARK_PINK,
    BSTATUS_TEXT_COLOR_GREEN,
    BSTATUS_TEXT_COLOR_LIGHT_GREEN,
    BSTATUS_TEXT_COLOR_RED,
    BSTATUS_TEXT_COLOR_LIGHT_RED,
};

#define BSTATUS_TEXT_PAL                15

#define BSTATUS_CARD_TILE_W             9
#define BSTATUS_CARD_TILE_H             7
#define BSTATUS_CARD_W                  (BSTATUS_CARD_TILE_W * 8)
#define BSTATUS_CARD_H                  (BSTATUS_CARD_TILE_H * 8)

#define BSTATUS_ROW_Y_ENEMY             16
#define BSTATUS_ROW_Y_PLAYER            80

#define BSTATUS_DETAIL_ICON_X           32
#define BSTATUS_DETAIL_ICON_Y           52
#define BSTATUS_DETAIL_TYPE_Y           16
#define BSTATUS_DETAIL_TYPE_W           32
#define BSTATUS_DETAIL_TYPE_H           16
#define BSTATUS_DETAIL_TYPE_GAP_X       33

#define BSTATUS_CARD_GAP_TILES          1
#define BSTATUS_MIN_GAP_TILES           0

#define BSTATUS_SAFE_LEFT_TILE          1
#define BSTATUS_SAFE_RIGHT_TILE         29

#define BSTATUS_LABEL_PAD_Y             16
#define BSTATUS_LABEL_TILE_H            2
#define BSTATUS_LABEL_H                 (BSTATUS_LABEL_TILE_H * 8)

#define BSTATUS_WIN_LABEL_TOP_BASE      1
#define BSTATUS_WIN_LABEL_BOTTOM_BASE   (BSTATUS_WIN_LABEL_TOP_BASE + (32 * BSTATUS_LABEL_TILE_H))
#define BSTATUS_WIN_ROW_ENEMY_BASE      (BSTATUS_WIN_LABEL_BOTTOM_BASE + (32 * BSTATUS_LABEL_TILE_H))
#define BSTATUS_WIN_ROW_PLAYER_BASE     (BSTATUS_WIN_ROW_ENEMY_BASE + (32 * BSTATUS_CARD_TILE_H))
#define BSTATUS_DETAIL_HEADER_WIN_W     15
#define BSTATUS_DETAIL_HEADER_WIN_H     4
#define BSTATUS_DETAIL_ITEM_WIN_W       9
#define BSTATUS_DETAIL_ITEM_WIN_H       7
#define BSTATUS_DETAIL_STATS_WIN_W      6
#define BSTATUS_DETAIL_STATS_WIN_H      9
#define BSTATUS_DETAIL_EFFECTS_WIN_W    13
#define BSTATUS_DETAIL_EFFECTS_WIN_H    12
#define BSTATUS_DETAIL_DESC_WIN_W       13
#define BSTATUS_DETAIL_DESC_WIN_H       8
#define BSTATUS_WIN_DETAIL_HEADER_BASE  (BSTATUS_WIN_ROW_PLAYER_BASE + (32 * BSTATUS_CARD_TILE_H))
#define BSTATUS_WIN_DETAIL_ITEM_BASE    (BSTATUS_WIN_DETAIL_HEADER_BASE + (BSTATUS_DETAIL_HEADER_WIN_W * BSTATUS_DETAIL_HEADER_WIN_H))
#define BSTATUS_WIN_DETAIL_STATS_BASE   (BSTATUS_WIN_DETAIL_ITEM_BASE + (BSTATUS_DETAIL_ITEM_WIN_W * BSTATUS_DETAIL_ITEM_WIN_H))
#define BSTATUS_WIN_DETAIL_EFFECTS_BASE (BSTATUS_WIN_DETAIL_STATS_BASE + (BSTATUS_DETAIL_STATS_WIN_W * BSTATUS_DETAIL_STATS_WIN_H))
#define BSTATUS_WIN_DETAIL_DESC_BASE    (BSTATUS_WIN_DETAIL_EFFECTS_BASE + (BSTATUS_DETAIL_EFFECTS_WIN_W * BSTATUS_DETAIL_EFFECTS_WIN_H))

#define BSTATUS_NAME_X                  4
#define BSTATUS_NAME_Y                  2
#define BSTATUS_STATUS_PAD_X            8
#define BSTATUS_STATUS_PAD_Y            2

#define BSTATUS_GENDER_PAD_X            2
#define BSTATUS_GENDER_PAD_Y            2
#define BSTATUS_GENDER_W                8
#define BSTATUS_DETAIL_HEADER_NAME_Y    1
#define BSTATUS_DETAIL_HEADER_LV_X      2
#define BSTATUS_DETAIL_HEADER_LV_Y      14
#define BSTATUS_DETAIL_HEADER_RIGHT_INFO_Y BSTATUS_DETAIL_HEADER_NAME_Y
#define BSTATUS_DETAIL_HEADER_RIGHT_PAD_X 2
#define BSTATUS_DETAIL_HEADER_LEVEL_GENDER_GAP_X 2
#define BSTATUS_DETAIL_HEADER_GIMMICK_X 2
#define BSTATUS_DETAIL_HEADER_GIMMICK_Y 30
#define BSTATUS_DETAIL_HEADER_TERA_LABEL_X 2
#define BSTATUS_DETAIL_HEADER_TERA_LABEL_Y 11
#define BSTATUS_DETAIL_HEADER_TERA_ICON_X 24
#define BSTATUS_DETAIL_HEADER_TERA_ICON_Y 20

#define BSTATUS_HP_BAR_X                -18
#define BSTATUS_HP_BAR_Y                (BSTATUS_CARD_H - 10)

#define BSTATUS_UPDATE_ICON_W           8
#define BSTATUS_UPDATE_ICON_H           8
#define BSTATUS_UPDATE_ICON_PAD_X       2
#define BSTATUS_UPDATE_ICON_PAD_Y       2

#define BSTATUS_HP_BAR_TILE_TAG_BASE    0xD7C0
#define BSTATUS_HP_BAR_PAL_TAG          0xD7C4
#define BSTATUS_HEALTHBAR_PIXELS        48
#define BSTATUS_DETAIL_HEALTHBAR_PIXELS 40
#define BSTATUS_HP_BAR_SEGMENTS         6
#define BSTATUS_DETAIL_HP_BAR_SEGMENTS  5

#define BSTATUS_UPDATE_ICON_TILE_TAG    0xD7D0
#define BSTATUS_UPDATE_ICON_PAL_TAG     0xD7D1

#define BSTATUS_CURSOR_TILE_TAG         0xD7E0
#define BSTATUS_CURSOR_PAL_TAG          0xD7E1
#define BSTATUS_DETAIL_GIMMICK_TILE_TAG 0xD7E2
#define BSTATUS_DETAIL_HP_BAR_TILE_TAG  0xD7E3
#define BSTATUS_DETAIL_TERA_TYPE_TILE_TAG 0xD7F0
#define BSTATUS_OVERVIEW_GIMMICK_TILE_TAG_BASE 0xD7E4
#define BSTATUS_DETAIL_STAT_PIP_DOT_TILE_TAG 0xD7E8
#define BSTATUS_DETAIL_STAT_PIP_UP_TILE_TAG  0xD7E9
#define BSTATUS_DETAIL_STAT_PIP_DOWN_TILE_TAG 0xD7EA
#define BSTATUS_DETAIL_STAT_PIP_PAL_TAG      0xD7EF
#define BSTATUS_DETAIL_STAT_PIP_PAL_NUM      12
#define BSTATUS_DETAIL_EFFECTS_SCROLLBAR_TILE_TAG 0xD7EB
#define BSTATUS_DETAIL_EFFECTS_SCROLLBAR_PAL_TAG  0xD7F1
#define BSTATUS_DETAIL_EFFECTS_SCROLLBAR_PAL_NUM  9
#define BSTATUS_MOVE_TYPES_PAL_TAG_1       0xD7ED
#define BSTATUS_MOVE_TYPES_PAL_TAG_2       0xD7EE

#define BSTATUS_DETAIL_WINDOW_COUNT     5
#define BSTATUS_DETAIL_GIMMICK_W        8
#define BSTATUS_DETAIL_GIMMICK_H        16
#define BSTATUS_DETAIL_GIMMICK_GFX_SIZE ((BSTATUS_DETAIL_GIMMICK_W * BSTATUS_DETAIL_GIMMICK_H) / 2)
#define BSTATUS_DETAIL_HP_BAR_X         (BSTATUS_DETAIL_ICON_X - 20)
#define BSTATUS_DETAIL_HP_BAR_Y         (BSTATUS_DETAIL_ICON_Y + 18)
#define BSTATUS_DETAIL_STATUS_X         (BSTATUS_DETAIL_ICON_X + 13)
#define BSTATUS_DETAIL_STATUS_Y         (BSTATUS_DETAIL_HP_BAR_Y - 4)
#define BSTATUS_DETAIL_STAT_ROW_COUNT   7
#define BSTATUS_DETAIL_STAT_PIPS_PER_ROW 6
#define BSTATUS_DETAIL_STAT_LABEL_X     2
#define BSTATUS_DETAIL_STAT_ROW_START_Y 0
#define BSTATUS_DETAIL_STAT_ROW_SPACING_Y 9
#define BSTATUS_DETAIL_STAT_EXTRA_GAP_BEFORE_ACC 3
#define BSTATUS_DETAIL_STAT_PIP_START_X 56
#define BSTATUS_DETAIL_STAT_PIP_SPACING_X 8
#define BSTATUS_DETAIL_STAT_PIP_Y_OFFSET 8
#define BSTATUS_DETAIL_MAX_ACTIVE_EFFECTS 64
#define BSTATUS_DETAIL_EFFECTS_HEADER_Y 2
#define BSTATUS_DETAIL_EFFECTS_CURSOR_X 2
#define BSTATUS_DETAIL_EFFECTS_TEXT_X 10
#define BSTATUS_DETAIL_EFFECTS_LIST_START_Y 16
#define BSTATUS_DETAIL_EFFECTS_ROW_HEIGHT 12
#define BSTATUS_DETAIL_EFFECTS_VISIBLE_ROWS 6
#define BSTATUS_DETAIL_EFFECTS_SCROLLBAR_X_INSET 6
#define BSTATUS_DETAIL_DESC_TEXT_X 2
#define BSTATUS_DETAIL_DESC_TEXT_Y 2
#define BSTATUS_DETAIL_TEXT_BUFFER_SIZE 512

#define TAG_STATUS_ICONS                1202

#define HEALTHBOX_GFX_HP_LABEL          1
#define HEALTHBOX_GFX_HP_BAR_GREEN      3
#define HEALTHBOX_GFX_HP_BAR_YELLOW     50
#define HEALTHBOX_GFX_HP_BAR_RED        59

struct BattleStatusCard
{
    enum BattlerId battlerId;
    s16 x;
    s16 y;
    u16 hpBarTileTag;
    u16 gimmickTileTag;
    u8 hpBarSpriteId;
    u8 monIconSpriteId;
    u8 gimmickSpriteId;
    u8 statusSpriteId;
    u8 updateSpriteId;
};

struct BattleStatusMenuState
{
    u8 page;
    u8 selectedCardIndex;
    u8 cursorSpriteId;
    u8 detailIconSpriteId;
    u8 detailHpBarSpriteId;
    u8 detailStatusSpriteId;
    u8 detailTeraTypeSpriteId;
    u8 detailGimmickSpriteId;
    u8 detailTypeIconSpriteIds[2];
    u8 detailStatPipSpriteIds[BSTATUS_DETAIL_STAT_ROW_COUNT][BSTATUS_DETAIL_STAT_PIPS_PER_ROW];
    u8 playerCount;
    u8 enemyCount;
    enum BattlerId selectedBattlerId;
    enum BattlerId playerBattlers[MAX_BATTLERS_COUNT];
    enum BattlerId enemyBattlers[MAX_BATTLERS_COUNT];
    u8 battlerNames[MAX_BATTLERS_COUNT][POKEMON_NAME_LENGTH + 1];
    u8 enemyLabelText[TRAINER_NAME_LENGTH + 1];
    u8 playerLabelText[TRAINER_NAME_LENGTH + 1];
    struct BattleStatusCard cards[MAX_BATTLERS_COUNT];
    u8 cardCount;
    s16 enemyRowLeft;
    s16 enemyRowRight;
    s16 enemyRowCenter;
    s16 playerRowLeft;
    s16 playerRowRight;
    s16 playerRowCenter;
    u8 detailActiveEffects[BSTATUS_DETAIL_MAX_ACTIVE_EFFECTS];
    u8 detailActiveEffectsCount;
    u8 detailEffectsCursor;
    u8 detailEffectsScrollbarSpriteId;
    u16 detailEffectsScroll;
    u8 detailWindowIds[BSTATUS_DETAIL_WINDOW_COUNT];
};

enum BattleStatusEffectId
{
    BSTATUS_EFFECT_HARSH_SUNLIGHT,
    BSTATUS_EFFECT_RAIN,
    BSTATUS_EFFECT_SANDSTORM,
    BSTATUS_EFFECT_SNOW,
    BSTATUS_EFFECT_ELECTRIC_TERRAIN,
    BSTATUS_EFFECT_GRASSY_TERRAIN,
    BSTATUS_EFFECT_MISTY_TERRAIN,
    BSTATUS_EFFECT_PSYCHIC_TERRAIN,
    BSTATUS_EFFECT_TRICK_ROOM,
    BSTATUS_EFFECT_MAGIC_ROOM,
    BSTATUS_EFFECT_WONDER_ROOM,
    BSTATUS_EFFECT_GRAVITY,
    BSTATUS_EFFECT_MIST,
    BSTATUS_EFFECT_SAFEGUARD,
    BSTATUS_EFFECT_LUCKY_CHANT,
    BSTATUS_EFFECT_TAILWIND,
    BSTATUS_EFFECT_CRITICAL_HIT_BOOST,
    BSTATUS_EFFECT_CONFUSION,
    BSTATUS_EFFECT_INFATUATION,
    BSTATUS_EFFECT_NIGHTMARE,
    BSTATUS_EFFECT_DROWSY,
    BSTATUS_EFFECT_ENCORE,
    BSTATUS_EFFECT_TORMENT,
    BSTATUS_EFFECT_GRUDGE,
    BSTATUS_EFFECT_HEALING_PREVENTED,
    BSTATUS_EFFECT_IDENTIFIED,
    BSTATUS_EFFECT_MOVE_DISABLED,
    BSTATUS_EFFECT_CANT_ESCAPE,
    BSTATUS_EFFECT_LOCK_ON,
    BSTATUS_EFFECT_EMBARGO,
    BSTATUS_EFFECT_CHARGE,
    BSTATUS_EFFECT_TAUNT,
    BSTATUS_EFFECT_TELEKINESIS,
    BSTATUS_EFFECT_MAGNET_RISE,
    BSTATUS_EFFECT_WISH,
    BSTATUS_EFFECT_INGRAIN,
    BSTATUS_EFFECT_CURSE,
    BSTATUS_EFFECT_DESTINY_BOND,
    BSTATUS_EFFECT_BOUND,
    BSTATUS_EFFECT_BIDE,
    BSTATUS_EFFECT_FUTURE_ATTACK,
    BSTATUS_EFFECT_UPROAR,
    BSTATUS_EFFECT_AQUA_RING,
    BSTATUS_EFFECT_AUTOTOMIZE,
    BSTATUS_EFFECT_SMACK_DOWN,
    BSTATUS_EFFECT_FAIRY_LOCK,
    BSTATUS_EFFECT_RAINBOW,
    BSTATUS_EFFECT_SWAMP,
    BSTATUS_EFFECT_SEA_OF_FIRE,
    BSTATUS_EFFECT_THROAT_CHOP,
    BSTATUS_EFFECT_LASER_FOCUS,
    BSTATUS_EFFECT_TAR_SHOT,
    BSTATUS_EFFECT_OCTOLOCK,
    BSTATUS_EFFECT_FIXATED,
    BSTATUS_EFFECT_SPLINTERS,
    BSTATUS_EFFECT_OBSCURED,
    BSTATUS_EFFECT_PRIMED,
    BSTATUS_EFFECT_STANCE_SWAP,
    BSTATUS_EFFECT_SLOW_START,
    BSTATUS_EFFECT_SALT_CURE,
    BSTATUS_EFFECT_SYRUPY,
    BSTATUS_EFFECT_GOING_ALL_OUT,
    BSTATUS_EFFECT_HANGING_TOUGH,
    BSTATUS_EFFECT_POISONED,
    BSTATUS_EFFECT_BADLY_POISONED,
    BSTATUS_EFFECT_PARALYZED,
    BSTATUS_EFFECT_BURNED,
    BSTATUS_EFFECT_FROSTBITE,
    BSTATUS_EFFECT_STEALTH_ROCK,
    BSTATUS_EFFECT_SPIKES,
    BSTATUS_EFFECT_TOXIC_SPIKES,
    BSTATUS_EFFECT_STICKY_WEB,
    BSTATUS_EFFECT_LIGHT_SCREEN,
    BSTATUS_EFFECT_REFLECT,
    BSTATUS_EFFECT_AURORA_VEIL,
    BSTATUS_EFFECT_MUD_SPORT,
    BSTATUS_EFFECT_WATER_SPORT,
    BSTATUS_EFFECT_FORESTS_CURSE,
    BSTATUS_EFFECT_TRICK_OR_TREAT,
    BSTATUS_EFFECT_POWER_BOOST,
    BSTATUS_EFFECT_POWER_DROP,
    BSTATUS_EFFECT_GUARD_BOOST,
    BSTATUS_EFFECT_GUARD_DROP,
    BSTATUS_EFFECT_FOG,
    BSTATUS_EFFECT_EXTREMELY_HARSH_SUNLIGHT,
    BSTATUS_EFFECT_HEAVY_RAIN,
    BSTATUS_EFFECT_STRONG_WINDS,
    BSTATUS_EFFECT_OUTRAGE,
    BSTATUS_EFFECT_RAMPAGING,
    BSTATUS_EFFECT_PETAL_DANCE,
    BSTATUS_EFFECT_RAGING_FURY,
    BSTATUS_EFFECT_G_MAX_WILDFIRE,
    BSTATUS_EFFECT_G_MAX_VOLCALITH,
    BSTATUS_EFFECT_G_MAX_VINE_LASH,
    BSTATUS_EFFECT_G_MAX_CANNONADE,
    BSTATUS_EFFECT_WILD_MIGHT,
    BSTATUS_EFFECT_TERRIBLE_MIGHT,
    BSTATUS_EFFECT_TERRIFIC_MIGHT,
    BSTATUS_EFFECT_FRENZIED_MIGHT,
    BSTATUS_EFFECT_COUNT
};

struct BattleStatusEffectData
{
    const u8 *name;
    const u8 *description;
};

static void BattleStatusMenu_VBlankCB(void);
static void BattleStatusMenu_MainCB(void);
static void BattleStatusMenu_Init(void);
static void BattleStatus_OverviewEnter(void);
static void BattleStatus_OverviewExit(void);
static void BattleStatus_OverviewBuildBattlerLists(void);
static void BattleStatus_OverviewBufferLabelText(void);
static void BattleStatus_OverviewSortBattlersByScreenOrder(enum BattlerId *battlers, u8 count);
static u8 BattleStatus_OverviewGetBattlerSortOrder(enum BattlerId battler);
static void BattleStatus_OverviewComputeRowLayout(const enum BattlerId *battlers, u8 count, s16 *outXs,
                                                  s16 *outRowLeft, s16 *outRowRight, s16 *outRowCenter);
static void BattleStatus_OverviewCreateCards(void);
static void BattleStatus_OverviewDrawCard(struct BattleStatusCard *card);
static u8 BattleStatus_GetBestFitNameFont(const u8 *name, s16 maxWidth);
static void BattleStatus_OverviewDrawLabels(void);
static void BattleStatus_OverviewCreateWindows(void);
static void BattleStatus_OverviewClearWindows(void);
static void BattleStatus_OverviewInitCursor(void);
static void BattleStatus_OverviewUpdateCursorPos(void);
static void BattleStatus_OverviewHandleInput(void);
static bool8 BattleStatus_OverviewTryMoveCursor(s8 dx, s8 dy);
static u8 BattleStatus_OverviewGetDefaultIndex(void);
static void BattleStatus_OverviewRestoreSelection(void);
static void BattleStatus_OverviewSyncSelectedBattler(void);
static void BattleStatus_DetailEnter(void);
static void BattleStatus_DetailExit(void);
static void BattleStatus_DetailHandleInput(void);
static void BattleStatus_DetailCreateWindows(void);
static void BattleStatus_DetailDestroyWindows(void);
static void BattleStatus_DetailDrawStaticWindows(void);
static u8 BattleStatus_DetailGetBestFitSmallFont(const u8 *text, s16 maxWidth);
static const u8 *BattleStatus_GetGimmickIndicatorData(enum BattlerId battler, u32 *palTag);
static void BattleStatus_DetailDestroyHpBar(void);
static void BattleStatus_ClearHpBarLabelTiles(u8 spriteId);
static void BattleStatus_DetailRefreshHpBar(void);
static void BattleStatus_DetailDestroyStatusIcon(void);
static void BattleStatus_DetailRefreshStatusIcon(void);
static void BattleStatus_DetailDestroyGimmickIndicator(void);
static void BattleStatus_DetailRefreshGimmickIndicator(void);
static void BattleStatus_DetailDestroyTeraTypeIndicator(void);
static void BattleStatus_DetailRefreshTeraTypeIndicator(void);
static void BattleStatus_DetailRefreshItemAbilityWindow(void);
static void BattleStatus_DetailRefreshHeader(void);
static void BattleStatus_DetailRefreshIcon(void);
static void BattleStatus_DetailRefreshTypeIcons(void);
static void BattleStatus_DetailDestroyTypeIcons(void);
static void BattleStatus_DetailCreateStatPips(void);
static void BattleStatus_DetailDestroyStatPips(void);
static void BattleStatus_DetailRefreshStatPips(void);
static s16 BattleStatus_DetailGetStatRowTextY(u8 row);
static void BattleStatus_DetailSetStatPipSpriteGraphic(u8 spriteId, u16 tileTag);
static void BattleStatus_DetailCycleBattler(s8 direction);
static void BattleStatus_DetailInitEffectsList(void);
static void BattleStatus_DetailBuildActiveEffects(void);
static void BattleStatus_DetailTryAddActiveEffect(enum BattleStatusEffectId effectId);
static const struct BattleStatusEffectData *BattleStatus_GetEffectData(enum BattleStatusEffectId effectId);
static bool8 BattleStatus_DetailTryMoveEffectCursor(s8 direction);
static void BattleStatus_DetailRefreshEffectsWindow(void);
static void BattleStatus_DetailRefreshDescriptionWindow(void);
static void BattleStatus_DetailRefreshEffectsSection(void);
static void BattleStatus_DetailRefreshEffectsScrollbar(void);
static void BattleStatus_DetailDestroyEffectsCursor(void);
static void BattleStatus_DetailDestroyEffectsScrollbar(void);
static void BattleStatus_DetailUpdateEffectsCursor(void);
static void BattleStatus_DetailFormatDescriptionText(enum BattleStatusEffectId effectId, u8 *dst);
static void BattleStatus_DetailClampTextLines(u8 *text, u8 maxLines);
static void BattleStatus_DetailDrawWindowFrame(u8 windowId);
static const u8 *BattleStatus_GetPlayerTrainerName(void);
static const u8 *BattleStatus_GetPrimaryOpponentTrainerName(void);
static u8 BattleStatus_GetOpponentTrainerCount(void);
static bool8 BattleStatus_HasPlayerPartnerTrainer(void);
static void BattleStatus_OverviewUpdateHpBars(void);
static void BattleStatusMenu_Destroy(void);

static u8 BattleStatus_CreateHpBarSprite(u16 tileTag, s16 x, s16 y);
static void BattleStatus_UpdateHpBarTilesWithWidth(u8 spriteId, s16 hp, s16 maxHp, u8 totalPixels, u8 segmentCount);
static void BattleStatus_UpdateHpBarTiles(u8 spriteId, s16 hp, s16 maxHp);
static void BattleStatus_DrawHpBarSprite(struct BattleStatusCard *card);
static u8 BattleStatus_GetBarGfxId(s16 hp, s16 maxHp);
static void BattleStatus_GetNickname(enum BattlerId battler, u8 *dst);
static u8 BattleStatus_GetAilmentFromBattler(enum BattlerId battler);
static void BattleStatus_RefreshUnreadUpdates(void);
static u32 BattleStatus_CalcBattlerUpdateHash(enum BattlerId battler);
static u32 BattleStatus_HashBytes(u32 hash, const void *data, u32 size);
static void BattleStatus_GetActiveEffectsMask(enum BattlerId battler, u64 *mask);
static bool8 BattleStatus_BattlerHasUnreadUpdates(enum BattlerId battler);

EWRAM_DATA static u8 sBattleStatusMenuState = 0;
EWRAM_DATA static struct BattleStatusMenuState sBattleStatusMenu = {0};
EWRAM_DATA static u16 sBattleStatusMenuBg0Tilemap[BG_SCREEN_SIZE] = {0};
EWRAM_DATA static u8 sBattleStatusDetailTextBuffer[BSTATUS_DETAIL_TEXT_BUFFER_SIZE] = {0};
EWRAM_DATA static u16 sBattleStatusSnapshotTurn = 0;
EWRAM_DATA static bool8 sBattleStatusSnapshotInitialized = FALSE;
EWRAM_DATA static u32 sBattleStatusLastTurnSnapshotHash[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA static bool8 sBattleStatusLastTurnSnapshotValid[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA static bool8 sBattleStatusUnreadUpdates[MAX_BATTLERS_COUNT] = {0};

static const u8 sTextColor_BattleStatus_Default[] =
{
    BSTATUS_TEXT_COLOR_TRANSPARENT,
    BSTATUS_TEXT_COLOR_BLACK,
    BSTATUS_TEXT_COLOR_LIGHT_GRAY
};

static const u8 sTextColor_BattleStatus_Male[] =
{
    BSTATUS_TEXT_COLOR_TRANSPARENT,
    BSTATUS_TEXT_COLOR_LIGHT_BLUE,
    BSTATUS_TEXT_COLOR_BLUE
};

static const u8 sTextColor_BattleStatus_Female[] =
{
    BSTATUS_TEXT_COLOR_TRANSPARENT,
    BSTATUS_TEXT_COLOR_PINK,
    BSTATUS_TEXT_COLOR_DARK_PINK
};

static const u8 sText_BattleStatus_Opponent[] = _("Opponent");
static const u8 sText_BattleStatus_Ally[] = _("Ally");
static const u8 sText_BattleStatus_DetailHeldItemLabel[] = _("Held Item");
static const u8 sText_BattleStatus_DetailHeldItemValue[] = _("None");
static const u8 sText_BattleStatus_DetailAbilityLabel[] = _("Ability");
static const u8 sText_BattleStatus_DetailAbilityValue[] = _("None");
static const u8 sText_BattleStatus_DetailEffectsHeader[] = _("Active States and Effects");
static const u8 sText_BattleStatus_DetailTeraTypeLabel[] = _("Tera\nType:");
static const u8 sText_BattleStatus_DetailStatAttack[] = _("Attack");
static const u8 sText_BattleStatus_DetailStatDefense[] = _("Defense");
static const u8 sText_BattleStatus_DetailStatSpAtk[] = _("Sp. Atk");
static const u8 sText_BattleStatus_DetailStatSpDef[] = _("Sp. Def");
static const u8 sText_BattleStatus_DetailStatSpeed[] = _("Speed");
static const u8 sText_BattleStatus_DetailStatAccuracy[] = _("Accuracy");
static const u8 sText_BattleStatus_DetailStatEvasion[] = _("Evasion");

static const u8 *const sBattleStatusDetailStatLabels[BSTATUS_DETAIL_STAT_ROW_COUNT] =
{
    sText_BattleStatus_DetailStatAttack,
    sText_BattleStatus_DetailStatDefense,
    sText_BattleStatus_DetailStatSpAtk,
    sText_BattleStatus_DetailStatSpDef,
    sText_BattleStatus_DetailStatSpeed,
    sText_BattleStatus_DetailStatAccuracy,
    sText_BattleStatus_DetailStatEvasion,
};

static const u8 sBattleStatusDetailStatIds[BSTATUS_DETAIL_STAT_ROW_COUNT] =
{
    STAT_ATK,
    STAT_DEF,
    STAT_SPATK,
    STAT_SPDEF,
    STAT_SPEED,
    STAT_ACC,
    STAT_EVASION,
};

static const u8 sText_BattleStatus_EffectName_HARSH_SUNLIGHT[] = _("Harsh Sunlight");
static const u8 sText_BattleStatus_EffectName_RAIN[] = _("Rain");
static const u8 sText_BattleStatus_EffectName_SANDSTORM[] = _("Sandstorm");
static const u8 sText_BattleStatus_EffectName_SNOW[] = _("Snow");
static const u8 sText_BattleStatus_EffectName_ELECTRIC_TERRAIN[] = _("Electric Terrain");
static const u8 sText_BattleStatus_EffectName_GRASSY_TERRAIN[] = _("Grassy Terrain");
static const u8 sText_BattleStatus_EffectName_MISTY_TERRAIN[] = _("Misty Terrain");
static const u8 sText_BattleStatus_EffectName_PSYCHIC_TERRAIN[] = _("Psychic Terrain");
static const u8 sText_BattleStatus_EffectName_TRICK_ROOM[] = _("Trick Room");
static const u8 sText_BattleStatus_EffectName_MAGIC_ROOM[] = _("Magic Room");
static const u8 sText_BattleStatus_EffectName_WONDER_ROOM[] = _("Wonder Room");
static const u8 sText_BattleStatus_EffectName_GRAVITY[] = _("Gravity");
static const u8 sText_BattleStatus_EffectName_MIST[] = _("Mist");
static const u8 sText_BattleStatus_EffectName_SAFEGUARD[] = _("Safeguard");
static const u8 sText_BattleStatus_EffectName_LUCKY_CHANT[] = _("Lucky Chant");
static const u8 sText_BattleStatus_EffectName_TAILWIND[] = _("Tailwind");
static const u8 sText_BattleStatus_EffectName_CRITICAL_HIT_BOOST[] = _("Critical Hit Boost");
static const u8 sText_BattleStatus_EffectName_CONFUSION[] = _("Confusion");
static const u8 sText_BattleStatus_EffectName_INFATUATION[] = _("Infatuation");
static const u8 sText_BattleStatus_EffectName_NIGHTMARE[] = _("Nightmare");
static const u8 sText_BattleStatus_EffectName_DROWSY[] = _("Drowsy");
static const u8 sText_BattleStatus_EffectName_ENCORE[] = _("Encore");
static const u8 sText_BattleStatus_EffectName_TORMENT[] = _("Torment");
static const u8 sText_BattleStatus_EffectName_GRUDGE[] = _("Grudge");
static const u8 sText_BattleStatus_EffectName_HEALING_PREVENTED[] = _("Healing Prevented");
static const u8 sText_BattleStatus_EffectName_IDENTIFIED[] = _("Identified");
static const u8 sText_BattleStatus_EffectName_MOVE_DISABLED[] = _("Move Disabled");
static const u8 sText_BattleStatus_EffectName_CANT_ESCAPE[] = _("Can't Escape");
static const u8 sText_BattleStatus_EffectName_LOCK_ON[] = _("Lock-On");
static const u8 sText_BattleStatus_EffectName_EMBARGO[] = _("Embargo");
static const u8 sText_BattleStatus_EffectName_CHARGE[] = _("Charge");
static const u8 sText_BattleStatus_EffectName_TAUNT[] = _("Taunt");
static const u8 sText_BattleStatus_EffectName_TELEKINESIS[] = _("Telekinesis");
static const u8 sText_BattleStatus_EffectName_MAGNET_RISE[] = _("Magnet Rise");
static const u8 sText_BattleStatus_EffectName_WISH[] = _("Wish");
static const u8 sText_BattleStatus_EffectName_INGRAIN[] = _("Ingrain");
static const u8 sText_BattleStatus_EffectName_CURSE[] = _("Curse");
static const u8 sText_BattleStatus_EffectName_DESTINY_BOND[] = _("Destiny Bond");
static const u8 sText_BattleStatus_EffectName_BOUND[] = _("Bound");
static const u8 sText_BattleStatus_EffectName_BIDE[] = _("Bide");
static const u8 sText_BattleStatus_EffectName_FUTURE_ATTACK[] = _("Future Attack");
static const u8 sText_BattleStatus_EffectName_UPROAR[] = _("Uproar");
static const u8 sText_BattleStatus_EffectName_AQUA_RING[] = _("Aqua Ring");
static const u8 sText_BattleStatus_EffectName_AUTOTOMIZE[] = _("Autotomize");
static const u8 sText_BattleStatus_EffectName_SMACK_DOWN[] = _("Smack Down");
static const u8 sText_BattleStatus_EffectName_FAIRY_LOCK[] = _("Fairy Lock");
static const u8 sText_BattleStatus_EffectName_RAINBOW[] = _("Rainbow");
static const u8 sText_BattleStatus_EffectName_SWAMP[] = _("Swamp");
static const u8 sText_BattleStatus_EffectName_SEA_OF_FIRE[] = _("Sea of Fire");
static const u8 sText_BattleStatus_EffectName_THROAT_CHOP[] = _("Throat Chop");
static const u8 sText_BattleStatus_EffectName_LASER_FOCUS[] = _("Laser Focus");
static const u8 sText_BattleStatus_EffectName_TAR_SHOT[] = _("Tar Shot");
static const u8 sText_BattleStatus_EffectName_OCTOLOCK[] = _("Octolock");
static const u8 sText_BattleStatus_EffectName_FIXATED[] = _("Fixated");
static const u8 sText_BattleStatus_EffectName_SPLINTERS[] = _("Splinters");
static const u8 sText_BattleStatus_EffectName_OBSCURED[] = _("Obscured");
static const u8 sText_BattleStatus_EffectName_PRIMED[] = _("Primed");
static const u8 sText_BattleStatus_EffectName_STANCE_SWAP[] = _("Stance Swap");
static const u8 sText_BattleStatus_EffectName_SLOW_START[] = _("Slow Start");
static const u8 sText_BattleStatus_EffectName_SALT_CURE[] = _("Salt Cure");
static const u8 sText_BattleStatus_EffectName_SYRUPY[] = _("Syrupy");
static const u8 sText_BattleStatus_EffectName_GOING_ALL_OUT[] = _("Going All Out");
static const u8 sText_BattleStatus_EffectName_HANGING_TOUGH[] = _("Hanging Tough");
static const u8 sText_BattleStatus_EffectName_POISONED[] = _("Poisoned");
static const u8 sText_BattleStatus_EffectName_BADLY_POISONED[] = _("Badly Poisoned");
static const u8 sText_BattleStatus_EffectName_PARALYZED[] = _("Paralyzed");
static const u8 sText_BattleStatus_EffectName_BURNED[] = _("Burned");
static const u8 sText_BattleStatus_EffectName_FROSTBITE[] = _("Frostbite");
static const u8 sText_BattleStatus_EffectName_STEALTH_ROCK[] = _("Stealth Rock");
static const u8 sText_BattleStatus_EffectName_SPIKES[] = _("Spikes");
static const u8 sText_BattleStatus_EffectName_TOXIC_SPIKES[] = _("Toxic Spikes");
static const u8 sText_BattleStatus_EffectName_STICKY_WEB[] = _("Sticky Web");
static const u8 sText_BattleStatus_EffectName_LIGHT_SCREEN[] = _("Light Screen");
static const u8 sText_BattleStatus_EffectName_REFLECT[] = _("Reflect");
static const u8 sText_BattleStatus_EffectName_AURORA_VEIL[] = _("Aurora Veil");
static const u8 sText_BattleStatus_EffectName_MUD_SPORT[] = _("Mud Sport");
static const u8 sText_BattleStatus_EffectName_WATER_SPORT[] = _("Water Sport");
static const u8 sText_BattleStatus_EffectName_FORESTS_CURSE[] = _("Forest's Curse");
static const u8 sText_BattleStatus_EffectName_TRICK_OR_TREAT[] = _("Trick-or-Treat");
static const u8 sText_BattleStatus_EffectName_POWER_BOOST[] = _("Power Boost");
static const u8 sText_BattleStatus_EffectName_POWER_DROP[] = _("Power Drop");
static const u8 sText_BattleStatus_EffectName_GUARD_BOOST[] = _("Guard Boost");
static const u8 sText_BattleStatus_EffectName_GUARD_DROP[] = _("Guard Drop");
static const u8 sText_BattleStatus_EffectName_FOG[] = _("Fog");
static const u8 sText_BattleStatus_EffectName_EXTREMELY_HARSH_SUNLIGHT[] = _("Extremely Harsh Sunlight");
static const u8 sText_BattleStatus_EffectName_HEAVY_RAIN[] = _("Heavy Rain");
static const u8 sText_BattleStatus_EffectName_STRONG_WINDS[] = _("Strong Winds");
static const u8 sText_BattleStatus_EffectName_OUTRAGE[] = _("Outrage");
static const u8 sText_BattleStatus_EffectName_RAMPAGING[] = _("Rampaging");
static const u8 sText_BattleStatus_EffectName_PETAL_DANCE[] = _("Petal Dance");
static const u8 sText_BattleStatus_EffectName_RAGING_FURY[] = _("Raging Fury");
static const u8 sText_BattleStatus_EffectName_G_MAX_WILDFIRE[] = _("G-Max Wildfire");
static const u8 sText_BattleStatus_EffectName_G_MAX_VOLCALITH[] = _("G-Max Volcalith");
static const u8 sText_BattleStatus_EffectName_G_MAX_VINE_LASH[] = _("G-Max Vine Lash");
static const u8 sText_BattleStatus_EffectName_G_MAX_CANNONADE[] = _("G-Max Cannonade");
static const u8 sText_BattleStatus_EffectName_WILD_MIGHT[] = _("Wild Might");
static const u8 sText_BattleStatus_EffectName_TERRIBLE_MIGHT[] = _("Terrible Might");
static const u8 sText_BattleStatus_EffectName_TERRIFIC_MIGHT[] = _("Terrific Might");
static const u8 sText_BattleStatus_EffectName_FRENZIED_MIGHT[] = _("Frenzied Might");

static const struct BattleStatusEffectData sBattleStatusEffects[BSTATUS_EFFECT_COUNT] =
{
    [BSTATUS_EFFECT_HARSH_SUNLIGHT] = {sText_BattleStatus_EffectName_HARSH_SUNLIGHT, COMPOUND_STRING("The harsh sunlight weather condition. It boosts the power of Fire-type moves and lowers the power of Water-type moves.")},
    [BSTATUS_EFFECT_RAIN] = {sText_BattleStatus_EffectName_RAIN, COMPOUND_STRING("The rain weather condition. It boosts the power of Water-type moves and lowers the power of Fire-type moves.")},
    [BSTATUS_EFFECT_SANDSTORM] = {sText_BattleStatus_EffectName_SANDSTORM, COMPOUND_STRING("The sandstorm weather condition. At the end of each turn, it damages all Pokemon that are not Rock, Ground, or Steel types. It boosts the Sp. Def of Rock-type Pokemon.")},
    [BSTATUS_EFFECT_SNOW] = {sText_BattleStatus_EffectName_SNOW, COMPOUND_STRING("The snow weather condition. It makes Blizzard more likely to hit and boosts the Defense of Ice-type Pokemon.")},
    [BSTATUS_EFFECT_ELECTRIC_TERRAIN] = {sText_BattleStatus_EffectName_ELECTRIC_TERRAIN, COMPOUND_STRING("For five turns, Pokemon on the ground won't fall asleep. The power of Electric-type moves is boosted.")},
    [BSTATUS_EFFECT_GRASSY_TERRAIN] = {sText_BattleStatus_EffectName_GRASSY_TERRAIN, COMPOUND_STRING("For five turns, Pokemon on the ground will have a little HP restored at the end of each turn. The power of Grass-type moves is boosted.")},
    [BSTATUS_EFFECT_MISTY_TERRAIN] = {sText_BattleStatus_EffectName_MISTY_TERRAIN, COMPOUND_STRING("For five turns, Pokemon on the ground won't get any status conditions. Damage from Dragon-type moves is halved.")},
    [BSTATUS_EFFECT_PSYCHIC_TERRAIN] = {sText_BattleStatus_EffectName_PSYCHIC_TERRAIN, COMPOUND_STRING("For five turns, Pokemon on the ground won't be hit by priority moves. The power of Psychic-type moves is boosted.")},
    [BSTATUS_EFFECT_TRICK_ROOM] = {sText_BattleStatus_EffectName_TRICK_ROOM, COMPOUND_STRING("Slower Pokemon get to move first for five turns.")},
    [BSTATUS_EFFECT_MAGIC_ROOM] = {sText_BattleStatus_EffectName_MAGIC_ROOM, COMPOUND_STRING("Pokemon can't use their held items for five turns.")},
    [BSTATUS_EFFECT_WONDER_ROOM] = {sText_BattleStatus_EffectName_WONDER_ROOM, COMPOUND_STRING("Pokemon's Defense and Sp. Def are swapped for five turns.")},
    [BSTATUS_EFFECT_GRAVITY] = {sText_BattleStatus_EffectName_GRAVITY, COMPOUND_STRING("Moves are more likely to hit for five turns. Ground-type moves will hit Flying-type Pokemon and Pokemon with the Levitate Ability. Moves that require action midair can't be used.")},
    [BSTATUS_EFFECT_MIST] = {sText_BattleStatus_EffectName_MIST, COMPOUND_STRING("The Pokemon's stats won't be lowered for five turns.")},
    [BSTATUS_EFFECT_SAFEGUARD] = {sText_BattleStatus_EffectName_SAFEGUARD, COMPOUND_STRING("The Pokemon is protected from status conditions for five turns.")},
    [BSTATUS_EFFECT_LUCKY_CHANT] = {sText_BattleStatus_EffectName_LUCKY_CHANT, COMPOUND_STRING("The opponent's moves won't result in a critical hit.")},
    [BSTATUS_EFFECT_TAILWIND] = {sText_BattleStatus_EffectName_TAILWIND, COMPOUND_STRING("The Speed stats of a Pokemon and its allies are doubled for four turns.")},
    [BSTATUS_EFFECT_CRITICAL_HIT_BOOST] = {sText_BattleStatus_EffectName_CRITICAL_HIT_BOOST, COMPOUND_STRING("The Pokemon is more likely to land critical hits.")},
    [BSTATUS_EFFECT_CONFUSION] = {sText_BattleStatus_EffectName_CONFUSION, COMPOUND_STRING("The Pokemon may hurt itself in its confusion. The effect lasts for one to four turns.")},
    [BSTATUS_EFFECT_INFATUATION] = {sText_BattleStatus_EffectName_INFATUATION, COMPOUND_STRING("The Pokemon is less likely to unleash an attack on Pokemon of the opposite gender.")},
    [BSTATUS_EFFECT_NIGHTMARE] = {sText_BattleStatus_EffectName_NIGHTMARE, COMPOUND_STRING("The Pokemon will lose HP each turn as long as it is sleeping.")},
    [BSTATUS_EFFECT_DROWSY] = {sText_BattleStatus_EffectName_DROWSY, COMPOUND_STRING("The Pokemon will fall asleep at the end of the turn if it remains on the battlefield.")},
    [BSTATUS_EFFECT_ENCORE] = {sText_BattleStatus_EffectName_ENCORE, COMPOUND_STRING("Due to Encore, the Pokemon can use only {STR_VAR_1} for three turns.")},
    [BSTATUS_EFFECT_TORMENT] = {sText_BattleStatus_EffectName_TORMENT, COMPOUND_STRING("The Pokemon can't use the same move twice in a row.")},
    [BSTATUS_EFFECT_GRUDGE] = {sText_BattleStatus_EffectName_GRUDGE, COMPOUND_STRING("If the Pokemon faints as a result of a move, the PP of that move will be reduced to 0.")},
    [BSTATUS_EFFECT_HEALING_PREVENTED] = {sText_BattleStatus_EffectName_HEALING_PREVENTED, COMPOUND_STRING("For five turns, the Pokemon is unable to recover HP through its moves, Ability, or held item.")},
    [BSTATUS_EFFECT_IDENTIFIED] = {sText_BattleStatus_EffectName_IDENTIFIED, COMPOUND_STRING("The Pokemon will be hit by certain moves that usually wouldn't affect it. If the Pokemon's evasiveness has been boosted, the benefits will be ignored when it is attacked.")},
    [BSTATUS_EFFECT_MOVE_DISABLED] = {sText_BattleStatus_EffectName_MOVE_DISABLED, COMPOUND_STRING("{STR_VAR_1} has been disabled and cannot be used for four turns.")},
    [BSTATUS_EFFECT_CANT_ESCAPE] = {sText_BattleStatus_EffectName_CANT_ESCAPE, COMPOUND_STRING("The Pokemon can't flee or be switched out.")},
    [BSTATUS_EFFECT_LOCK_ON] = {sText_BattleStatus_EffectName_LOCK_ON, COMPOUND_STRING("The next move used by the Pokemon will be sure to hit the target that was locked on to.")},
    [BSTATUS_EFFECT_EMBARGO] = {sText_BattleStatus_EffectName_EMBARGO, COMPOUND_STRING("For five turns, the Pokemon cannot use its held item and no items can be used on it.")},
    [BSTATUS_EFFECT_CHARGE] = {sText_BattleStatus_EffectName_CHARGE, COMPOUND_STRING("The power of the next Electric-type move used by the Pokemon will be doubled.")},
    [BSTATUS_EFFECT_TAUNT] = {sText_BattleStatus_EffectName_TAUNT, COMPOUND_STRING("The Pokemon can only use moves that deal damage.")},
    [BSTATUS_EFFECT_TELEKINESIS] = {sText_BattleStatus_EffectName_TELEKINESIS, COMPOUND_STRING("For three turns, moves used against the Pokemon will hit without fail, except for one-hit KO moves. Also, Ground-type moves won't hit the Pokemon.")},
    [BSTATUS_EFFECT_MAGNET_RISE] = {sText_BattleStatus_EffectName_MAGNET_RISE, COMPOUND_STRING("Ground-type moves won't hit the Pokemon for five turns.")},
    [BSTATUS_EFFECT_WISH] = {sText_BattleStatus_EffectName_WISH, COMPOUND_STRING("The Pokemon in this spot will have its HP restored on the turn after Wish was used.")},
    [BSTATUS_EFFECT_INGRAIN] = {sText_BattleStatus_EffectName_INGRAIN, COMPOUND_STRING("The Pokemon regains some HP at the end of each turn. Ingrained Pokemon can't be switched out.")},
    [BSTATUS_EFFECT_CURSE] = {sText_BattleStatus_EffectName_CURSE, COMPOUND_STRING("The Pokemon takes damage at the end of each turn.")},
    [BSTATUS_EFFECT_DESTINY_BOND] = {sText_BattleStatus_EffectName_DESTINY_BOND, COMPOUND_STRING("If the Pokemon is knocked out by an opponent, that opponent will also faint.")},
    [BSTATUS_EFFECT_BOUND] = {sText_BattleStatus_EffectName_BOUND, COMPOUND_STRING("The Pokemon is bound and takes damage every turn.")},
    [BSTATUS_EFFECT_BIDE] = {sText_BattleStatus_EffectName_BIDE, COMPOUND_STRING("The Pokemon endures attacks for two turns, then strikes back to inflict double the damage it has taken.")},
    [BSTATUS_EFFECT_FUTURE_ATTACK] = {sText_BattleStatus_EffectName_FUTURE_ATTACK, COMPOUND_STRING("The Pokemon will take damage two turns after an attack was foreseen.")},
    [BSTATUS_EFFECT_UPROAR] = {sText_BattleStatus_EffectName_UPROAR, COMPOUND_STRING("The Pokemon attacks and causes an uproar for three turns. During this time, no Pokemon can fall asleep.")},
    [BSTATUS_EFFECT_AQUA_RING] = {sText_BattleStatus_EffectName_AQUA_RING, COMPOUND_STRING("The Pokemon is enveloped in a veil made of water. It regains some HP every turn.")},
    [BSTATUS_EFFECT_AUTOTOMIZE] = {sText_BattleStatus_EffectName_AUTOTOMIZE, COMPOUND_STRING("The Pokemon's weight is reduced, and its Speed is sharply increased.")},
    [BSTATUS_EFFECT_SMACK_DOWN] = {sText_BattleStatus_EffectName_SMACK_DOWN, COMPOUND_STRING("The Pokemon has been knocked out of the sky and has fallen to the ground.")},
    [BSTATUS_EFFECT_FAIRY_LOCK] = {sText_BattleStatus_EffectName_FAIRY_LOCK, COMPOUND_STRING("No Pokemon can flee the turn after Fairy Lock is used.")},
    [BSTATUS_EFFECT_RAINBOW] = {sText_BattleStatus_EffectName_RAINBOW, COMPOUND_STRING("The additional effects of moves are more likely to occur.")},
    [BSTATUS_EFFECT_SWAMP] = {sText_BattleStatus_EffectName_SWAMP, COMPOUND_STRING("Speed is reduced by 75% in swampy conditions.")},
    [BSTATUS_EFFECT_SEA_OF_FIRE] = {sText_BattleStatus_EffectName_SEA_OF_FIRE, COMPOUND_STRING("Pokemon that are not Fire types will take damage every turn.")},
    [BSTATUS_EFFECT_THROAT_CHOP] = {sText_BattleStatus_EffectName_THROAT_CHOP, COMPOUND_STRING("The Pokemon can't use any sound-based moves for two turns.")},
    [BSTATUS_EFFECT_LASER_FOCUS] = {sText_BattleStatus_EffectName_LASER_FOCUS, COMPOUND_STRING("The next move used will always result in a critical hit.")},
    [BSTATUS_EFFECT_TAR_SHOT] = {sText_BattleStatus_EffectName_TAR_SHOT, COMPOUND_STRING("The Pokemon has been made weaker to Fire-type moves.")},
    [BSTATUS_EFFECT_OCTOLOCK] = {sText_BattleStatus_EffectName_OCTOLOCK, COMPOUND_STRING("The Pokemon's Defense and Sp. Def are both lowered with each passing turn.")},
    [BSTATUS_EFFECT_FIXATED] = {sText_BattleStatus_EffectName_FIXATED, COMPOUND_STRING("The Pokemon is fixated on the last move it used. This move will deal increased damage while the fixation lasts, but any damage dealt to the fixated Pokemon is also increased.")},
    [BSTATUS_EFFECT_SPLINTERS] = {sText_BattleStatus_EffectName_SPLINTERS, COMPOUND_STRING("At the end of each turn, the Pokemon is hurt by the jagged splinters digging into it.")},
    [BSTATUS_EFFECT_OBSCURED] = {sText_BattleStatus_EffectName_OBSCURED, COMPOUND_STRING("The Pokemon is concealed in mud or the like, raising the chance that the Pokemon will evade opponents' moves.")},
    [BSTATUS_EFFECT_PRIMED] = {sText_BattleStatus_EffectName_PRIMED, COMPOUND_STRING("The Pokemon has adopted a hard-hitting stance, increasing the damage it deals with its moves.")},
    [BSTATUS_EFFECT_STANCE_SWAP] = {sText_BattleStatus_EffectName_STANCE_SWAP, COMPOUND_STRING("The Pokemon has swapped its offensive stats with its defensive stats.")},
    [BSTATUS_EFFECT_SLOW_START] = {sText_BattleStatus_EffectName_SLOW_START, COMPOUND_STRING("The Pokemon's Attack and Speed stats are halved until it gets going.")},
    [BSTATUS_EFFECT_SALT_CURE] = {sText_BattleStatus_EffectName_SALT_CURE, COMPOUND_STRING("The Pokemon is being salt cured, which deals damage to it each turn. This damage is doubled for Steel-type and Water-type Pokemon.")},
    [BSTATUS_EFFECT_SYRUPY] = {sText_BattleStatus_EffectName_SYRUPY, COMPOUND_STRING("The Pokemon's Speed will drop at the end of each turn for three turns.")},
    [BSTATUS_EFFECT_GOING_ALL_OUT] = {sText_BattleStatus_EffectName_GOING_ALL_OUT, COMPOUND_STRING("The Pokemon's Attack and Sp. Atk are both boosted thanks to a Trainer's cheer.")},
    [BSTATUS_EFFECT_HANGING_TOUGH] = {sText_BattleStatus_EffectName_HANGING_TOUGH, COMPOUND_STRING("The Pokemon's Defense and Sp. Def are both boosted thanks to a Trainer's cheer.")},
    [BSTATUS_EFFECT_POISONED] = {sText_BattleStatus_EffectName_POISONED, COMPOUND_STRING("At the end of each turn, the Pokemon is hurt by poison.")},
    [BSTATUS_EFFECT_BADLY_POISONED] = {sText_BattleStatus_EffectName_BADLY_POISONED, COMPOUND_STRING("The Pokemon is badly poisoned. The damage the Pokemon takes from the poison worsens every turn.")},
    [BSTATUS_EFFECT_PARALYZED] = {sText_BattleStatus_EffectName_PARALYZED, COMPOUND_STRING("The Pokemon is paralyzed and may fail to act. Its Speed stat is also lowered.")},
    [BSTATUS_EFFECT_BURNED] = {sText_BattleStatus_EffectName_BURNED, COMPOUND_STRING("At the end of each turn, the Pokemon is hurt by its burn. Any damage it deals with physical moves will also be reduced.")},
    [BSTATUS_EFFECT_FROSTBITE] = {sText_BattleStatus_EffectName_FROSTBITE, COMPOUND_STRING("At the end of each turn, the Pokemon is hurt by its frostbite. Any damage it deals with special moves will also be reduced.")},
    [BSTATUS_EFFECT_STEALTH_ROCK] = {sText_BattleStatus_EffectName_STEALTH_ROCK, COMPOUND_STRING("Pokemon that switch into battle will take damage.")},
    [BSTATUS_EFFECT_SPIKES] = {sText_BattleStatus_EffectName_SPIKES, COMPOUND_STRING("Pokemon that switch into battle will take damage. Flying-type Pokemon or Pokemon with the Levitate Ability will not be affected.")},
    [BSTATUS_EFFECT_TOXIC_SPIKES] = {sText_BattleStatus_EffectName_TOXIC_SPIKES, COMPOUND_STRING("Pokemon that switch into battle will be poisoned. Flying-type Pokemon or Pokemon with the Levitate Ability will not be affected.")},
    [BSTATUS_EFFECT_STICKY_WEB] = {sText_BattleStatus_EffectName_STICKY_WEB, COMPOUND_STRING("Pokemon that switch into battle will have their Speed lowered.")},
    [BSTATUS_EFFECT_LIGHT_SCREEN] = {sText_BattleStatus_EffectName_LIGHT_SCREEN, COMPOUND_STRING("Damage from special moves is halved for five turns.")},
    [BSTATUS_EFFECT_REFLECT] = {sText_BattleStatus_EffectName_REFLECT, COMPOUND_STRING("Damage from physical moves is halved for five turns.")},
    [BSTATUS_EFFECT_AURORA_VEIL] = {sText_BattleStatus_EffectName_AURORA_VEIL, COMPOUND_STRING("For five turns, the power of special and physical moves will be halved.")},
    [BSTATUS_EFFECT_MUD_SPORT] = {sText_BattleStatus_EffectName_MUD_SPORT, COMPOUND_STRING("The power of Electric-type moves will be halved for five turns.")},
    [BSTATUS_EFFECT_WATER_SPORT] = {sText_BattleStatus_EffectName_WATER_SPORT, COMPOUND_STRING("The power of Fire-type moves will be halved for five turns.")},
    [BSTATUS_EFFECT_FORESTS_CURSE] = {sText_BattleStatus_EffectName_FORESTS_CURSE, COMPOUND_STRING("The Pokemon gains the Grass type.")},
    [BSTATUS_EFFECT_TRICK_OR_TREAT] = {sText_BattleStatus_EffectName_TRICK_OR_TREAT, COMPOUND_STRING("The Pokemon gains the Ghost type.")},
    [BSTATUS_EFFECT_POWER_BOOST] = {sText_BattleStatus_EffectName_POWER_BOOST, COMPOUND_STRING("The Pokemon's offensive stats are raised, boosting its Attack and Sp. Atk stats.")},
    [BSTATUS_EFFECT_POWER_DROP] = {sText_BattleStatus_EffectName_POWER_DROP, COMPOUND_STRING("The Pokemon's offensive stats are lowered, reducing its Attack and Sp. Atk stats.")},
    [BSTATUS_EFFECT_GUARD_BOOST] = {sText_BattleStatus_EffectName_GUARD_BOOST, COMPOUND_STRING("The Pokemon's defensive stats are raised, boosting its Defense and Sp. Def stats.")},
    [BSTATUS_EFFECT_GUARD_DROP] = {sText_BattleStatus_EffectName_GUARD_DROP, COMPOUND_STRING("The Pokemon's defensive stats are lowered, reducing its Defense and Sp. Def stats.")},
    [BSTATUS_EFFECT_FOG] = {sText_BattleStatus_EffectName_FOG, COMPOUND_STRING("All moves are less accurate, apart from moves that are always sure to hit.")},
    [BSTATUS_EFFECT_EXTREMELY_HARSH_SUNLIGHT] = {sText_BattleStatus_EffectName_EXTREMELY_HARSH_SUNLIGHT, COMPOUND_STRING("The extremely harsh sunlight weather condition. It boosts the power of Fire-type moves and protects Pokemon from Water-type moves.")},
    [BSTATUS_EFFECT_HEAVY_RAIN] = {sText_BattleStatus_EffectName_HEAVY_RAIN, COMPOUND_STRING("The heavy rain weather condition. It boosts the power of Water-type moves and protects Pokemon from Fire-type moves.")},
    [BSTATUS_EFFECT_STRONG_WINDS] = {sText_BattleStatus_EffectName_STRONG_WINDS, COMPOUND_STRING("The strong winds weather condition. The power of moves that are super effective against Flying-type Pokemon is decreased.")},
    [BSTATUS_EFFECT_OUTRAGE] = {sText_BattleStatus_EffectName_OUTRAGE, COMPOUND_STRING("The Pokemon rampages and attacks for two to three turns. It then becomes confused.")},
    [BSTATUS_EFFECT_RAMPAGING] = {sText_BattleStatus_EffectName_RAMPAGING, COMPOUND_STRING("The Pokemon rampages and attacks for two to three turns. It then becomes confused.")},
    [BSTATUS_EFFECT_PETAL_DANCE] = {sText_BattleStatus_EffectName_PETAL_DANCE, COMPOUND_STRING("The Pokemon rampages and attacks for two to three turns. It then becomes confused.")},
    [BSTATUS_EFFECT_RAGING_FURY] = {sText_BattleStatus_EffectName_RAGING_FURY, COMPOUND_STRING("The Pokemon rampages and attacks for two to three turns. It then becomes confused.")},
    [BSTATUS_EFFECT_G_MAX_WILDFIRE] = {sText_BattleStatus_EffectName_G_MAX_WILDFIRE, COMPOUND_STRING("Pokemon that are not {STR_VAR_1} types will take damage every turn for four turns.")},
    [BSTATUS_EFFECT_G_MAX_VOLCALITH] = {sText_BattleStatus_EffectName_G_MAX_VOLCALITH, COMPOUND_STRING("Pokemon that are not {STR_VAR_1} types will take damage every turn for four turns.")},
    [BSTATUS_EFFECT_G_MAX_VINE_LASH] = {sText_BattleStatus_EffectName_G_MAX_VINE_LASH, COMPOUND_STRING("Pokemon that are not {STR_VAR_1} types will take damage every turn for four turns.")},
    [BSTATUS_EFFECT_G_MAX_CANNONADE] = {sText_BattleStatus_EffectName_G_MAX_CANNONADE, COMPOUND_STRING("Pokemon that are not {STR_VAR_1} types will take damage every turn for four turns.")},
    [BSTATUS_EFFECT_WILD_MIGHT] = {sText_BattleStatus_EffectName_WILD_MIGHT, COMPOUND_STRING("All the Pokemon's stats are boosted. The Pokemon also takes reduced damage from status conditions and move effects such as poisoning and splinters.")},
    [BSTATUS_EFFECT_TERRIBLE_MIGHT] = {sText_BattleStatus_EffectName_TERRIBLE_MIGHT, COMPOUND_STRING("All the Pokemon's stats are boosted. The Pokemon also takes reduced damage from status conditions and move effects such as poisoning and splinters.")},
    [BSTATUS_EFFECT_TERRIFIC_MIGHT] = {sText_BattleStatus_EffectName_TERRIFIC_MIGHT, COMPOUND_STRING("The Pokemon takes reduced damage from status conditions and move effects such as poisoning and splinters.")},
    [BSTATUS_EFFECT_FRENZIED_MIGHT] = {sText_BattleStatus_EffectName_FRENZIED_MIGHT, COMPOUND_STRING("The Pokemon takes reduced damage from status conditions and move effects such as poisoning and splinters.")},
};
STATIC_ASSERT(ARRAY_COUNT(sBattleStatusEffects) == BSTATUS_EFFECT_COUNT, BattleStatusEffectTableSizeMismatch);

static const u8 sBattleStatusHpBarTiles[8 * TILE_SIZE_4BPP] = {0};

static const struct OamData sOamData_BattleStatusHpBar =
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

static const struct Subsprite sBattleStatusHpBarSubsprites[] =
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

static const struct SubspriteTable sBattleStatusHpBarSubspriteTable[] =
{
    {ARRAY_COUNT(sBattleStatusHpBarSubsprites), sBattleStatusHpBarSubsprites}
};

static const struct SpriteSheet sSpriteSheet_BattleStatusHpBar =
{
    sBattleStatusHpBarTiles, sizeof(sBattleStatusHpBarTiles), BSTATUS_HP_BAR_TILE_TAG_BASE
};

static const struct SpritePalette sSpritePalette_BattleStatusHpBar =
{
    gBattleInterface_BallDisplayPal, BSTATUS_HP_BAR_PAL_TAG
};

static const struct SpriteTemplate sSpriteTemplate_BattleStatusHpBar =
{
    .tileTag = BSTATUS_HP_BAR_TILE_TAG_BASE,
    .paletteTag = BSTATUS_HP_BAR_PAL_TAG,
    .oam = &sOamData_BattleStatusHpBar,
    .callback = SpriteCallbackDummy
};

static const u8 sBattleStatusUpdateIconGfx[] = INCBIN_U8("graphics/battle_interface/update_indicator.4bpp");

static const struct OamData sOamData_BattleStatusUpdateIcon =
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

static const struct SpriteSheet sSpriteSheet_BattleStatusUpdateIcon =
{
    sBattleStatusUpdateIconGfx, sizeof(sBattleStatusUpdateIconGfx), BSTATUS_UPDATE_ICON_TILE_TAG
};

static const struct SpriteTemplate sSpriteTemplate_BattleStatusUpdateIcon =
{
    .tileTag = BSTATUS_UPDATE_ICON_TILE_TAG,
    .paletteTag = TAG_MISC_INDICATOR_PAL,
    .oam = &sOamData_BattleStatusUpdateIcon,
    .callback = SpriteCallbackDummy
};

static const u8 sBattleStatusDetailStatPipDotGfx[] = INCBIN_U8("graphics/battle_interface/battle_status_stat_slot_indicator.4bpp");
static const u8 sBattleStatusDetailStatPipUpGfx[] = INCBIN_U8("graphics/battle_interface/battle_status_stat_raise_indicator.4bpp");
static const u8 sBattleStatusDetailStatPipDownGfx[] = INCBIN_U8("graphics/battle_interface/battle_status_stat_drop_indicator.4bpp");

static const struct OamData sOamData_BattleStatusDetailStatPip =
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

static const struct SpriteSheet sSpriteSheet_BattleStatusDetailStatPipDot =
{
    sBattleStatusDetailStatPipDotGfx, sizeof(sBattleStatusDetailStatPipDotGfx), BSTATUS_DETAIL_STAT_PIP_DOT_TILE_TAG
};

static const struct SpriteSheet sSpriteSheet_BattleStatusDetailStatPipUp =
{
    sBattleStatusDetailStatPipUpGfx, sizeof(sBattleStatusDetailStatPipUpGfx), BSTATUS_DETAIL_STAT_PIP_UP_TILE_TAG
};

static const struct SpriteSheet sSpriteSheet_BattleStatusDetailStatPipDown =
{
    sBattleStatusDetailStatPipDownGfx, sizeof(sBattleStatusDetailStatPipDownGfx), BSTATUS_DETAIL_STAT_PIP_DOWN_TILE_TAG
};

static const struct SpriteTemplate sSpriteTemplate_BattleStatusDetailStatPip =
{
    .tileTag = BSTATUS_DETAIL_STAT_PIP_DOT_TILE_TAG,
    .paletteTag = BSTATUS_DETAIL_STAT_PIP_PAL_TAG,
    .oam = &sOamData_BattleStatusDetailStatPip,
    .callback = SpriteCallbackDummy,
};

static const u8 sBattleStatusDetailEffectsScrollbarGfx[] = INCBIN_U8("graphics/battle_interface/scrollbar.4bpp");

static const struct OamData sOamData_BattleStatusDetailEffectsScrollbar =
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

static const struct SpriteSheet sSpriteSheet_BattleStatusDetailEffectsScrollbar =
{
    sBattleStatusDetailEffectsScrollbarGfx, sizeof(sBattleStatusDetailEffectsScrollbarGfx), BSTATUS_DETAIL_EFFECTS_SCROLLBAR_TILE_TAG
};

static const struct SpriteTemplate sSpriteTemplate_BattleStatusDetailEffectsScrollbar =
{
    .tileTag = BSTATUS_DETAIL_EFFECTS_SCROLLBAR_TILE_TAG,
    .paletteTag = TAG_MISC_INDICATOR_PAL,
    .oam = &sOamData_BattleStatusDetailEffectsScrollbar,
    .callback = SpriteCallbackDummy,
};

static const u32 sBattleStatusCursorGfx[] = INCBIN_U32("graphics/interface/arrow_cursor.4bpp.smol");

static const struct OamData sOamData_BattleStatusCursor =
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

static const struct SpriteTemplate sSpriteTemplate_BattleStatusCursor =
{
    .tileTag = BSTATUS_CURSOR_TILE_TAG,
    .paletteTag = TAG_MISC_INDICATOR_PAL,
    .oam = &sOamData_BattleStatusCursor,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_BattleStatusDetailGimmick =
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

static const struct SpriteTemplate sSpriteTemplate_BattleStatusDetailGimmick =
{
    .tileTag = BSTATUS_DETAIL_GIMMICK_TILE_TAG,
    .paletteTag = TAG_MISC_INDICATOR_PAL,
    .oam = &sOamData_BattleStatusDetailGimmick,
    .callback = SpriteCallbackDummy,
};

static const struct BgTemplate sBattleStatusMenuBgTemplates[] =
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
};

// Window templates
enum
{
    WIN_LABEL_TOP,
    WIN_LABEL_BOTTOM,
    WIN_ROW_ENEMY,
    WIN_ROW_PLAYER,
};

static const struct WindowTemplate sBattleStatusMenuWindowTemplates[] =
{
    [WIN_LABEL_TOP] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 32,
        .height = BSTATUS_LABEL_TILE_H,
        .paletteNum = BSTATUS_TEXT_PAL,
        .baseBlock = BSTATUS_WIN_LABEL_TOP_BASE,
    },
    [WIN_LABEL_BOTTOM] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = (DISPLAY_HEIGHT / 8) - BSTATUS_LABEL_TILE_H,
        .width = 32,
        .height = BSTATUS_LABEL_TILE_H,
        .paletteNum = BSTATUS_TEXT_PAL,
        .baseBlock = BSTATUS_WIN_LABEL_BOTTOM_BASE,
    },
    [WIN_ROW_ENEMY] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = BSTATUS_ROW_Y_ENEMY / 8,
        .width = 32,
        .height = BSTATUS_CARD_TILE_H,
        .paletteNum = BSTATUS_TEXT_PAL,
        .baseBlock = BSTATUS_WIN_ROW_ENEMY_BASE,
    },
    [WIN_ROW_PLAYER] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = BSTATUS_ROW_Y_PLAYER / 8,
        .width = 32,
        .height = BSTATUS_CARD_TILE_H,
        .paletteNum = BSTATUS_TEXT_PAL,
        .baseBlock = BSTATUS_WIN_ROW_PLAYER_BASE,
    },
    DUMMY_WIN_TEMPLATE
};

enum
{
    WIN_DETAIL_HEADER,
    WIN_DETAIL_ITEM_ABILITY,
    WIN_DETAIL_STATS,
    WIN_DETAIL_EFFECTS,
    WIN_DETAIL_DESCRIPTION,
    WIN_DETAIL_COUNT = BSTATUS_DETAIL_WINDOW_COUNT,
};

static const struct WindowTemplate sBattleStatusDetailWindowTemplates[WIN_DETAIL_COUNT] =
{
    [WIN_DETAIL_HEADER] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 0,
        .width = BSTATUS_DETAIL_HEADER_WIN_W,
        .height = BSTATUS_DETAIL_HEADER_WIN_H,
        .paletteNum = BSTATUS_TEXT_PAL,
        .baseBlock = BSTATUS_WIN_DETAIL_HEADER_BASE,
    },
    [WIN_DETAIL_ITEM_ABILITY] = {
        .bg = 0,
        .tilemapLeft = 7,
        .tilemapTop = 4,
        .width = BSTATUS_DETAIL_ITEM_WIN_W,
        .height = BSTATUS_DETAIL_ITEM_WIN_H,
        .paletteNum = BSTATUS_TEXT_PAL,
        .baseBlock = BSTATUS_WIN_DETAIL_ITEM_BASE,
    },
    [WIN_DETAIL_STATS] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 11,
        .width = BSTATUS_DETAIL_STATS_WIN_W,
        .height = BSTATUS_DETAIL_STATS_WIN_H,
        .paletteNum = BSTATUS_TEXT_PAL,
        .baseBlock = BSTATUS_WIN_DETAIL_STATS_BASE,
    },
    [WIN_DETAIL_EFFECTS] = {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 0,
        .width = BSTATUS_DETAIL_EFFECTS_WIN_W,
        .height = BSTATUS_DETAIL_EFFECTS_WIN_H,
        .paletteNum = BSTATUS_TEXT_PAL,
        .baseBlock = BSTATUS_WIN_DETAIL_EFFECTS_BASE,
    },
    [WIN_DETAIL_DESCRIPTION] = {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 12,
        .width = BSTATUS_DETAIL_DESC_WIN_W,
        .height = BSTATUS_DETAIL_DESC_WIN_H,
        .paletteNum = BSTATUS_TEXT_PAL,
        .baseBlock = BSTATUS_WIN_DETAIL_DESC_BASE,
    },
};

void CB2_BattleStatusMenuFromBattle(void)
{
    SetVBlankHBlankCallbacksToNull();
    ClearScheduledBgCopiesToVram();
    ScanlineEffect_Stop();
    FreeAllSpritePalettes();
    ResetPaletteFade();
    gPaletteFade.bufferTransferDisabled = TRUE;
    ResetSpriteData();
    if (!MenuHelpers_IsLinkActive())
        ResetTasks();
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    CpuFill16(0, (void *)BG_CHAR_ADDR(0), BG_CHAR_SIZE);
    InitBgsFromTemplates(0, sBattleStatusMenuBgTemplates, ARRAY_COUNT(sBattleStatusMenuBgTemplates));
    SetBgTilemapBuffer(0, sBattleStatusMenuBg0Tilemap);
    FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 0);
    CopyBgTilemapBufferToVram(0);
    ResetAllBgsCoordinates();
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
    LoadPalette(gBattleStatusTextPalette, BG_PLTT_ID(BSTATUS_TEXT_PAL), PLTT_SIZE_4BPP);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
    InitWindows((const struct WindowTemplate[]){DUMMY_WIN_TEMPLATE});
    DeactivateAllTextPrinters();
    BattleStatusMenu_Init();
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    gPaletteFade.bufferTransferDisabled = FALSE;
    sBattleStatusMenuState = BATTLE_STATUS_MENU_STATE_FADE_IN;
    SetVBlankCallback(BattleStatusMenu_VBlankCB);
    SetMainCallback2(BattleStatusMenu_MainCB);
}

static void BattleStatusMenu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void BattleStatusMenu_MainCB(void)
{
    if (sBattleStatusMenuState != BATTLE_STATUS_MENU_STATE_FADE_OUT)
    {
        if (sBattleStatusMenu.page == BATTLE_STATUS_PAGE_OVERVIEW)
            BattleStatus_OverviewUpdateHpBars();
        else
            BattleStatus_DetailRefreshHpBar();
    }

    switch (sBattleStatusMenuState)
    {
    case BATTLE_STATUS_MENU_STATE_FADE_IN:
        if (!gPaletteFade.active)
            sBattleStatusMenuState = BATTLE_STATUS_MENU_STATE_WAIT_INPUT;
        break;
    case BATTLE_STATUS_MENU_STATE_WAIT_INPUT:
        if (sBattleStatusMenu.page == BATTLE_STATUS_PAGE_OVERVIEW)
        {
            BattleStatus_OverviewHandleInput();
            if (JOY_NEW(B_BUTTON))
            {
                PlaySE(SE_SELECT);
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                sBattleStatusMenuState = BATTLE_STATUS_MENU_STATE_FADE_OUT;
            }
        }
        else
            BattleStatus_DetailHandleInput();
        break;
    case BATTLE_STATUS_MENU_STATE_FADE_OUT:
        if (!gPaletteFade.active)
        {
            BattleStatusMenu_Destroy();
            FreeAllWindowBuffers();
            SetMainCallback2(CB2_SetUpReshowBattleScreenAfterMenu);
        }
        break;
    }

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void BattleStatusMenu_Init(void)
{
    u8 i, j;

    memset(&sBattleStatusMenu, 0, sizeof(sBattleStatusMenu));
    sBattleStatusMenu.page = BATTLE_STATUS_PAGE_OVERVIEW;
    sBattleStatusMenu.selectedCardIndex = 0;
    sBattleStatusMenu.selectedBattlerId = B_BATTLER_0;
    sBattleStatusMenu.cursorSpriteId = SPRITE_NONE;
    sBattleStatusMenu.detailIconSpriteId = SPRITE_NONE;
    sBattleStatusMenu.detailHpBarSpriteId = SPRITE_NONE;
    sBattleStatusMenu.detailStatusSpriteId = SPRITE_NONE;
    sBattleStatusMenu.detailTeraTypeSpriteId = SPRITE_NONE;
    sBattleStatusMenu.detailGimmickSpriteId = SPRITE_NONE;
    sBattleStatusMenu.detailEffectsScrollbarSpriteId = SPRITE_NONE;
    sBattleStatusMenu.detailTypeIconSpriteIds[0] = SPRITE_NONE;
    sBattleStatusMenu.detailTypeIconSpriteIds[1] = SPRITE_NONE;
    for (i = 0; i < BSTATUS_DETAIL_STAT_ROW_COUNT; i++)
    {
        for (j = 0; j < BSTATUS_DETAIL_STAT_PIPS_PER_ROW; j++)
            sBattleStatusMenu.detailStatPipSpriteIds[i][j] = SPRITE_NONE;
    }
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        sBattleStatusMenu.cards[i].gimmickTileTag = 0;
        sBattleStatusMenu.cards[i].hpBarSpriteId = SPRITE_NONE;
        sBattleStatusMenu.cards[i].monIconSpriteId = SPRITE_NONE;
        sBattleStatusMenu.cards[i].gimmickSpriteId = SPRITE_NONE;
        sBattleStatusMenu.cards[i].statusSpriteId = SPRITE_NONE;
        sBattleStatusMenu.cards[i].updateSpriteId = SPRITE_NONE;
    }
    for (i = 0; i < ARRAY_COUNT(sBattleStatusMenu.detailWindowIds); i++)
        sBattleStatusMenu.detailWindowIds[i] = WINDOW_NONE;

    LoadMonIconPalettes();
    LoadPartyMenuAilmentGfx();
    LoadSpriteSheet(&sSpriteSheet_BattleStatusHpBar);
    LoadSpritePalette(&sSpritePalette_BattleStatusHpBar);
    LoadSpriteSheet(&sSpriteSheet_BattleStatusUpdateIcon);
    LoadCompressedSpriteSheet(&gSpriteSheet_MoveTypes);
    LoadSpritePaletteInSlot(&(struct SpritePalette){ .data = gMoveTypes_Pal,      .tag = gSpriteTemplate_MoveTypes.paletteTag }, 13);
    LoadSpritePaletteInSlot(&(struct SpritePalette){ .data = gMoveTypes_Pal + 16, .tag = BSTATUS_MOVE_TYPES_PAL_TAG_1 }, 14);
    LoadSpritePaletteInSlot(&(struct SpritePalette){ .data = gMoveTypes_Pal + 32, .tag = BSTATUS_MOVE_TYPES_PAL_TAG_2 }, 15);
    LoadSpriteSheet(&sSpriteSheet_BattleStatusDetailEffectsScrollbar);
    LoadCompressedSpriteSheet(&(struct CompressedSpriteSheet){
        sBattleStatusCursorGfx, 0x80, BSTATUS_CURSOR_TILE_TAG
    });
    LoadIndicatorSpritesGfx();

    BattleStatus_OverviewCreateWindows();
    BattleStatus_OverviewEnter();
}

static void BattleStatus_OverviewEnter(void)
{
    sBattleStatusMenu.page = BATTLE_STATUS_PAGE_OVERVIEW;
    BattleStatus_OverviewClearWindows();
    BattleStatus_OverviewBuildBattlerLists();
    BattleStatus_RefreshUnreadUpdates();
    BattleStatus_OverviewBufferLabelText();
    BattleStatus_OverviewCreateCards();
    BattleStatus_OverviewDrawLabels();
    BattleStatus_OverviewRestoreSelection();
    BattleStatus_OverviewInitCursor();
}

static void BattleStatus_OverviewExit(void)
{
    u8 i;

    if (sBattleStatusMenu.cursorSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sBattleStatusMenu.cursorSpriteId]);
    sBattleStatusMenu.cursorSpriteId = SPRITE_NONE;

    for (i = 0; i < sBattleStatusMenu.cardCount; i++)
    {
        struct BattleStatusCard *card = &sBattleStatusMenu.cards[i];

        if (card->hpBarSpriteId != SPRITE_NONE)
            DestroySprite(&gSprites[card->hpBarSpriteId]);
        if (card->statusSpriteId != SPRITE_NONE)
            DestroySprite(&gSprites[card->statusSpriteId]);
        if (card->updateSpriteId != SPRITE_NONE)
            DestroySprite(&gSprites[card->updateSpriteId]);
        if (card->monIconSpriteId != SPRITE_NONE)
            FreeAndDestroyMonIconSprite(&gSprites[card->monIconSpriteId]);
        if (card->gimmickSpriteId != SPRITE_NONE)
            DestroySprite(&gSprites[card->gimmickSpriteId]);
        if (card->gimmickTileTag != 0)
            FreeSpriteTilesByTag(card->gimmickTileTag);

        card->hpBarSpriteId = SPRITE_NONE;
        card->statusSpriteId = SPRITE_NONE;
        card->updateSpriteId = SPRITE_NONE;
        card->monIconSpriteId = SPRITE_NONE;
        card->gimmickSpriteId = SPRITE_NONE;
        card->gimmickTileTag = 0;
    }

    BattleStatus_OverviewClearWindows();
}

static void BattleStatus_OverviewClearWindows(void)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(BSTATUS_TEXT_COLOR_TRANSPARENT));
        ClearWindowTilemap(i);
        CopyWindowToVram(i, COPYWIN_GFX);
    }

    CopyBgTilemapBufferToVram(0);
}

static void BattleStatus_OverviewRestoreSelection(void)
{
    u8 i;

    if (sBattleStatusMenu.cardCount == 0)
        return;

    for (i = 0; i < sBattleStatusMenu.cardCount; i++)
    {
        if (sBattleStatusMenu.cards[i].battlerId == sBattleStatusMenu.selectedBattlerId)
        {
            sBattleStatusMenu.selectedCardIndex = i;
            BattleStatus_OverviewSyncSelectedBattler();
            return;
        }
    }

    sBattleStatusMenu.selectedCardIndex = BattleStatus_OverviewGetDefaultIndex();
    BattleStatus_OverviewSyncSelectedBattler();
}

static u8 BattleStatus_OverviewGetDefaultIndex(void)
{
    u8 i;

    if (sBattleStatusMenu.cardCount == 0)
        return 0;

    for (i = 0; i < sBattleStatusMenu.cardCount; i++)
    {
        if (sBattleStatusMenu.cards[i].y == BSTATUS_ROW_Y_PLAYER)
            return i;
    }

    return 0;
}

static void BattleStatus_OverviewSyncSelectedBattler(void)
{
    if (sBattleStatusMenu.selectedCardIndex < sBattleStatusMenu.cardCount)
        sBattleStatusMenu.selectedBattlerId = sBattleStatusMenu.cards[sBattleStatusMenu.selectedCardIndex].battlerId;
}

static void BattleStatus_DetailEnter(void)
{
    if (sBattleStatusMenu.cardCount == 0)
        return;

    if (sBattleStatusMenu.selectedCardIndex >= sBattleStatusMenu.cardCount)
        sBattleStatusMenu.selectedCardIndex = 0;
    BattleStatus_OverviewSyncSelectedBattler();
    BattleStatus_DetailDestroyEffectsCursor();

    sBattleStatusMenu.page = BATTLE_STATUS_PAGE_DETAIL;
    sBattleStatusMenu.detailIconSpriteId = SPRITE_NONE;
    sBattleStatusMenu.detailHpBarSpriteId = SPRITE_NONE;
    sBattleStatusMenu.detailStatusSpriteId = SPRITE_NONE;
    sBattleStatusMenu.detailTeraTypeSpriteId = SPRITE_NONE;
    sBattleStatusMenu.detailGimmickSpriteId = SPRITE_NONE;
    FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 0);
    CopyBgTilemapBufferToVram(0);
    BattleStatus_DetailCreateWindows();
    BattleStatus_DetailDrawStaticWindows();
    BattleStatus_DetailInitEffectsList();
    BattleStatus_DetailCreateStatPips();
    BattleStatus_DetailRefreshStatPips();
    BattleStatus_DetailRefreshHeader();
    BattleStatus_DetailRefreshItemAbilityWindow();
    BattleStatus_DetailRefreshIcon();
    BattleStatus_DetailRefreshHpBar();
    BattleStatus_DetailRefreshStatusIcon();
    BattleStatus_DetailRefreshTypeIcons();
}

static void BattleStatus_DetailExit(void)
{
    BattleStatus_DetailDestroyWindows();

    BattleStatus_DetailDestroyHpBar();
    BattleStatus_DetailDestroyStatusIcon();
    BattleStatus_DetailDestroyTeraTypeIndicator();
    BattleStatus_DetailDestroyGimmickIndicator();
    BattleStatus_DetailDestroyTypeIcons();
    BattleStatus_DetailDestroyStatPips();
    BattleStatus_DetailDestroyEffectsScrollbar();
    BattleStatus_DetailDestroyEffectsCursor();
    sBattleStatusMenu.detailActiveEffectsCount = 0;
    sBattleStatusMenu.detailEffectsCursor = 0;
    sBattleStatusMenu.detailEffectsScroll = 0;

    if (sBattleStatusMenu.detailIconSpriteId != SPRITE_NONE)
        FreeAndDestroyMonIconSprite(&gSprites[sBattleStatusMenu.detailIconSpriteId]);
    sBattleStatusMenu.detailIconSpriteId = SPRITE_NONE;

    FillBgTilemapBufferRect(0, 0, 0, 0, 32, 32, 0);
    CopyBgTilemapBufferToVram(0);
}

static void BattleStatus_DetailHandleInput(void)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BattleStatus_DetailExit();
        BattleStatus_OverviewEnter();
        return;
    }

    if (JOY_NEW(L_BUTTON))
    {
        PlaySE(SE_SELECT);
        BattleStatus_DetailCycleBattler(-1);
    }
    else if (JOY_NEW(R_BUTTON))
    {
        PlaySE(SE_SELECT);
        BattleStatus_DetailCycleBattler(1);
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (BattleStatus_DetailTryMoveEffectCursor(-1))
        {
            PlaySE(SE_SELECT);
            BattleStatus_DetailRefreshEffectsSection();
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (BattleStatus_DetailTryMoveEffectCursor(1))
        {
            PlaySE(SE_SELECT);
            BattleStatus_DetailRefreshEffectsSection();
        }
    }
}

static void BattleStatus_DetailCreateWindows(void)
{
    u8 i;

    for (i = 0; i < WIN_DETAIL_COUNT; i++)
    {
        sBattleStatusMenu.detailWindowIds[i] = AddWindow(&sBattleStatusDetailWindowTemplates[i]);
        if (sBattleStatusMenu.detailWindowIds[i] != WINDOW_NONE)
            BattleStatus_DetailDrawWindowFrame(sBattleStatusMenu.detailWindowIds[i]);
    }
}

static void BattleStatus_DetailDestroyWindows(void)
{
    u8 i;

    for (i = 0; i < WIN_DETAIL_COUNT; i++)
    {
        u8 windowId = sBattleStatusMenu.detailWindowIds[i];

        if (windowId == WINDOW_NONE)
            continue;

        FillWindowPixelBuffer(windowId, PIXEL_FILL(BSTATUS_TEXT_COLOR_TRANSPARENT));
        ClearWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_GFX);
        RemoveWindow(windowId);
        sBattleStatusMenu.detailWindowIds[i] = WINDOW_NONE;
    }

    CopyBgTilemapBufferToVram(0);
}

static void BattleStatus_DetailDrawStaticWindows(void)
{
    u8 windowId;

    windowId = sBattleStatusMenu.detailWindowIds[WIN_DETAIL_ITEM_ABILITY];
    if (windowId != WINDOW_NONE)
    {
        BattleStatus_DetailDrawWindowFrame(windowId);
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }

    windowId = sBattleStatusMenu.detailWindowIds[WIN_DETAIL_STATS];
    if (windowId != WINDOW_NONE)
    {
        u8 i;

        BattleStatus_DetailDrawWindowFrame(windowId);
        for (i = 0; i < BSTATUS_DETAIL_STAT_ROW_COUNT; i++)
        {
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, BSTATUS_DETAIL_STAT_LABEL_X,
                                         BattleStatus_DetailGetStatRowTextY(i), 0, 0,
                                         sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW,
                                         sBattleStatusDetailStatLabels[i]);
        }
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }

    windowId = sBattleStatusMenu.detailWindowIds[WIN_DETAIL_EFFECTS];
    if (windowId != WINDOW_NONE)
    {
        BattleStatus_DetailDrawWindowFrame(windowId);
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }

    windowId = sBattleStatusMenu.detailWindowIds[WIN_DETAIL_DESCRIPTION];
    if (windowId != WINDOW_NONE)
    {
        BattleStatus_DetailDrawWindowFrame(windowId);
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }
}

static u8 BattleStatus_DetailGetBestFitSmallFont(const u8 *text, s16 maxWidth)
{
    if (GetStringWidth(FONT_SMALL, text, 0) <= maxWidth)
        return FONT_SMALL;
    if (GetStringWidth(FONT_SMALL_NARROW, text, 0) <= maxWidth)
        return FONT_SMALL_NARROW;
    return FONT_SMALL_NARROWER;
}

static void BattleStatus_DetailDestroyHpBar(void)
{
    if (sBattleStatusMenu.detailHpBarSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sBattleStatusMenu.detailHpBarSpriteId]);
    sBattleStatusMenu.detailHpBarSpriteId = SPRITE_NONE;

    FreeSpriteTilesByTag(BSTATUS_DETAIL_HP_BAR_TILE_TAG);
}

static void BattleStatus_ClearHpBarLabelTiles(u8 spriteId)
{
    u16 tileNum = gSprites[spriteId].oam.tileNum;

    CpuFill16(0, (void *)(OBJ_VRAM0 + tileNum * TILE_SIZE_4BPP), 64);
}

static void BattleStatus_DetailRefreshHpBar(void)
{
    enum BattlerId battler = sBattleStatusMenu.selectedBattlerId;
    s16 hp = gBattleMons[battler].hp;
    s16 maxHp = gBattleMons[battler].maxHP;
    struct Sprite *sprite;

    if (sBattleStatusMenu.detailHpBarSpriteId == SPRITE_NONE)
    {
        sBattleStatusMenu.detailHpBarSpriteId = BattleStatus_CreateHpBarSprite(BSTATUS_DETAIL_HP_BAR_TILE_TAG,
                                                                                BSTATUS_DETAIL_HP_BAR_X,
                                                                                BSTATUS_DETAIL_HP_BAR_Y);
        if (sBattleStatusMenu.detailHpBarSpriteId == SPRITE_NONE)
            return;

        // Detail page bar omits the HP logo block and shows only the fill bar.
        BattleStatus_ClearHpBarLabelTiles(sBattleStatusMenu.detailHpBarSpriteId);
    }

    sprite = &gSprites[sBattleStatusMenu.detailHpBarSpriteId];
    sprite->x = BSTATUS_DETAIL_HP_BAR_X;
    sprite->y = BSTATUS_DETAIL_HP_BAR_Y;
    if (maxHp <= 0)
    {
        sprite->invisible = TRUE;
        return;
    }

    BattleStatus_UpdateHpBarTilesWithWidth(sBattleStatusMenu.detailHpBarSpriteId, hp, maxHp,
                                           BSTATUS_DETAIL_HEALTHBAR_PIXELS, BSTATUS_DETAIL_HP_BAR_SEGMENTS);
    sprite->invisible = FALSE;
}

static void BattleStatus_DetailDestroyStatusIcon(void)
{
    if (sBattleStatusMenu.detailStatusSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sBattleStatusMenu.detailStatusSpriteId]);
    sBattleStatusMenu.detailStatusSpriteId = SPRITE_NONE;
}

static void BattleStatus_DetailRefreshStatusIcon(void)
{
    u8 ailment = BattleStatus_GetAilmentFromBattler(sBattleStatusMenu.selectedBattlerId);

    BattleStatus_DetailDestroyStatusIcon();
    if (ailment == AILMENT_NONE || ailment == AILMENT_PKRS)
        return;

    sBattleStatusMenu.detailStatusSpriteId = CreateSprite(&gSpriteTemplate_StatusIcons,
                                                          BSTATUS_DETAIL_STATUS_X,
                                                          BSTATUS_DETAIL_STATUS_Y, 0);
    if (sBattleStatusMenu.detailStatusSpriteId != SPRITE_NONE)
    {
        StartSpriteAnim(&gSprites[sBattleStatusMenu.detailStatusSpriteId], ailment - 1);
        gSprites[sBattleStatusMenu.detailStatusSpriteId].oam.priority = 0;
    }
}

static void BattleStatus_DetailDestroyTeraTypeIndicator(void)
{
    if (sBattleStatusMenu.detailTeraTypeSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sBattleStatusMenu.detailTeraTypeSpriteId]);
    sBattleStatusMenu.detailTeraTypeSpriteId = SPRITE_NONE;

    FreeSpriteTilesByTag(BSTATUS_DETAIL_TERA_TYPE_TILE_TAG);
}

static void BattleStatus_DetailRefreshTeraTypeIndicator(void)
{
    u8 windowId = sBattleStatusMenu.detailWindowIds[WIN_DETAIL_HEADER];
    struct SpriteSheet sheet;
    struct SpriteTemplate template = sSpriteTemplate_BattleStatusDetailGimmick;
    enum Type teraType;
    const u32 *indicatorData;
    s16 windowLeftPx;
    s16 windowTopPx;

    BattleStatus_DetailDestroyTeraTypeIndicator();
    if (windowId == WINDOW_NONE || B_FLAG_TERA_ORB_CHARGED == 0 || !FlagGet(B_FLAG_TERA_ORB_CHARGED))
        return;

    teraType = GetBattlerTeraType(sBattleStatusMenu.selectedBattlerId);
    indicatorData = GetTeraIndicatorSpriteSrc(teraType);
    if (indicatorData == NULL)
        return;

    sheet.data = (const u8 *)indicatorData;
    sheet.size = BSTATUS_DETAIL_GIMMICK_GFX_SIZE;
    sheet.tag = BSTATUS_DETAIL_TERA_TYPE_TILE_TAG;
    LoadSpriteSheet(&sheet);

    template.tileTag = BSTATUS_DETAIL_TERA_TYPE_TILE_TAG;
    template.paletteTag = TAG_TERA_INDICATOR_PAL;

    windowLeftPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT) * 8;
    windowTopPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP) * 8;
    sBattleStatusMenu.detailTeraTypeSpriteId = CreateSprite(&template,
                                                            windowLeftPx + BSTATUS_DETAIL_HEADER_TERA_ICON_X + (BSTATUS_DETAIL_GIMMICK_W / 2),
                                                            windowTopPx + BSTATUS_DETAIL_HEADER_TERA_ICON_Y, 0);
    if (sBattleStatusMenu.detailTeraTypeSpriteId != SPRITE_NONE)
        gSprites[sBattleStatusMenu.detailTeraTypeSpriteId].oam.priority = 0;
}

static const u8 *BattleStatus_GetGimmickIndicatorData(enum BattlerId battler, u32 *palTag)
{
    const u32 *indicatorData = GetIndicatorSpriteSrc(battler);

    *palTag = GetIndicatorPalTag(battler);
    if (indicatorData == NULL || *palTag == TAG_NONE)
        return NULL;

    return (const u8 *)indicatorData;
}

static void BattleStatus_DetailDestroyGimmickIndicator(void)
{
    if (sBattleStatusMenu.detailGimmickSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sBattleStatusMenu.detailGimmickSpriteId]);
    sBattleStatusMenu.detailGimmickSpriteId = SPRITE_NONE;

    FreeSpriteTilesByTag(BSTATUS_DETAIL_GIMMICK_TILE_TAG);
}

static void BattleStatus_DetailRefreshGimmickIndicator(void)
{
    u8 windowId = sBattleStatusMenu.detailWindowIds[WIN_DETAIL_HEADER];
    const u8 *indicatorData;
    u32 palTag;
    struct SpriteTemplate template = sSpriteTemplate_BattleStatusDetailGimmick;
    struct SpriteSheet sheet;
    s16 windowLeftPx;
    s16 windowTopPx;
    s16 indicatorLeftPx;
    s16 indicatorTopPx;

    BattleStatus_DetailDestroyGimmickIndicator();
    if (windowId == WINDOW_NONE)
        return;

    indicatorData = BattleStatus_GetGimmickIndicatorData(sBattleStatusMenu.selectedBattlerId, &palTag);
    if (indicatorData == NULL || palTag == 0)
        return;

    sheet.data = indicatorData;
    sheet.size = BSTATUS_DETAIL_GIMMICK_GFX_SIZE;
    sheet.tag = BSTATUS_DETAIL_GIMMICK_TILE_TAG;
    LoadSpriteSheet(&sheet);

    template.paletteTag = palTag;
    windowLeftPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT) * 8;
    windowTopPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP) * 8;
    indicatorLeftPx = windowLeftPx + BSTATUS_DETAIL_HEADER_GIMMICK_X;
    indicatorTopPx = windowTopPx + BSTATUS_DETAIL_HEADER_GIMMICK_Y - 4;

    sBattleStatusMenu.detailGimmickSpriteId = CreateSprite(&template,
                                                           indicatorLeftPx + (BSTATUS_DETAIL_GIMMICK_W / 2),
                                                           indicatorTopPx + (BSTATUS_DETAIL_GIMMICK_H / 2), 0);
    if (sBattleStatusMenu.detailGimmickSpriteId != SPRITE_NONE)
        gSprites[sBattleStatusMenu.detailGimmickSpriteId].oam.priority = 0;
}

static void BattleStatus_DetailRefreshItemAbilityWindow(void)
{
    enum BattlerId battler = sBattleStatusMenu.selectedBattlerId;
    u8 windowId = sBattleStatusMenu.detailWindowIds[WIN_DETAIL_ITEM_ABILITY];
    const u8 *itemText = sText_BattleStatus_DetailHeldItemValue;
    const u8 *abilityText = sText_BattleStatus_DetailAbilityValue;
    u8 itemFont;
    u8 abilityFont;
    s16 maxValueWidth;

    if (windowId == WINDOW_NONE)
        return;

    BattleStatus_DetailDrawWindowFrame(windowId);
    if (IsOnPlayerSide(battler))
    {
        enum Item heldItem = gBattleMons[battler].item;
        enum Ability ability = gBattleMons[battler].ability;

        if (heldItem != ITEM_NONE)
            itemText = GetItemName(heldItem);
        if (ability != ABILITY_NONE && ability < ABILITIES_COUNT)
            abilityText = gAbilitiesInfo[ability].name;

        maxValueWidth = WindowWidthPx(windowId) - 6;
        itemFont = BattleStatus_DetailGetBestFitSmallFont(itemText, maxValueWidth);
        abilityFont = BattleStatus_DetailGetBestFitSmallFont(abilityText, maxValueWidth);

        AddTextPrinterParameterized4(windowId, FONT_SHORT_NARROW, 2, 2, 0, 0, sTextColor_BattleStatus_Default,
                                     TEXT_SKIP_DRAW, sText_BattleStatus_DetailHeldItemLabel);
        AddTextPrinterParameterized4(windowId, itemFont, 2, 12, 0, 0, sTextColor_BattleStatus_Default,
                                     TEXT_SKIP_DRAW, itemText);
        AddTextPrinterParameterized4(windowId, FONT_SHORT_NARROW, 2, 25, 0, 0, sTextColor_BattleStatus_Default,
                                     TEXT_SKIP_DRAW, sText_BattleStatus_DetailAbilityLabel);
        AddTextPrinterParameterized4(windowId, abilityFont, 2, 35, 0, 0, sTextColor_BattleStatus_Default,
                                     TEXT_SKIP_DRAW, abilityText);
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void BattleStatus_DetailRefreshHeader(void)
{
    u8 windowId = sBattleStatusMenu.detailWindowIds[WIN_DETAIL_HEADER];
    u8 monName[POKEMON_NAME_LENGTH + 1];
    u8 genderSymbol[2];
    u8 levelText[10];
    u8 maxLevelText[10];
    u8 nameFont;
    u8 gender;
    u8 level;
    s16 maxNameWidth;
    s16 levelMaxWidth;
    s16 levelX;
    s16 genderX;
    struct Pokemon *mon;

    if (windowId == WINDOW_NONE)
        return;

    mon = GetBattlerMon(sBattleStatusMenu.selectedBattlerId);
    gender = GetMonGender(mon);
    level = GetMonData(mon, MON_DATA_LEVEL);

    BattleStatus_DetailDrawWindowFrame(windowId);
    genderX = WindowWidthPx(windowId) - BSTATUS_DETAIL_HEADER_RIGHT_PAD_X - BSTATUS_GENDER_W;

    maxLevelText[0] = CHAR_EXTRA_SYMBOL;
    maxLevelText[1] = CHAR_LV_2;
    ConvertIntToDecimalStringN(maxLevelText + 2, 999, STR_CONV_MODE_LEFT_ALIGN, 3);
    levelMaxWidth = GetStringWidth(FONT_SMALL, maxLevelText, 0);
    levelX = genderX - BSTATUS_DETAIL_HEADER_LEVEL_GENDER_GAP_X - levelMaxWidth;
    if (levelX < 2)
        levelX = 2;

    BattleStatus_GetNickname(sBattleStatusMenu.selectedBattlerId, monName);
    maxNameWidth = levelX - 4;
    if (maxNameWidth < 16)
        maxNameWidth = 16;
    nameFont = BattleStatus_GetBestFitNameFont(monName, maxNameWidth);
    AddTextPrinterParameterized4(windowId, nameFont, 2, BSTATUS_DETAIL_HEADER_NAME_Y, 0, 0, sTextColor_BattleStatus_Default,
                                 TEXT_SKIP_DRAW, monName);
    BattleStatus_DetailRefreshGimmickIndicator();
    if (B_FLAG_TERA_ORB_CHARGED != 0
     && FlagGet(B_FLAG_TERA_ORB_CHARGED)
     && IsOnPlayerSide(sBattleStatusMenu.selectedBattlerId))
    {
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROWER,
                                     BSTATUS_DETAIL_HEADER_TERA_LABEL_X,
                                     BSTATUS_DETAIL_HEADER_TERA_LABEL_Y,
                                     0, 0, sTextColor_BattleStatus_Default,
                                     TEXT_SKIP_DRAW, sText_BattleStatus_DetailTeraTypeLabel);
        BattleStatus_DetailRefreshTeraTypeIndicator();
    }
    else
    {
        BattleStatus_DetailDestroyTeraTypeIndicator();
    }

    levelText[0] = CHAR_EXTRA_SYMBOL;
    levelText[1] = CHAR_LV_2;
    ConvertIntToDecimalStringN(levelText + 2, level, STR_CONV_MODE_LEFT_ALIGN, 3);

    AddTextPrinterParameterized4(windowId, FONT_SMALL, levelX, BSTATUS_DETAIL_HEADER_RIGHT_INFO_Y, 0, 0, sTextColor_BattleStatus_Default,
                                 TEXT_SKIP_DRAW, levelText);

    if (gender == MON_MALE || gender == MON_FEMALE)
    {
        const u8 *colors = (gender == MON_MALE) ? sTextColor_BattleStatus_Male : sTextColor_BattleStatus_Female;

        genderSymbol[0] = (gender == MON_MALE) ? CHAR_MALE : CHAR_FEMALE;
        genderSymbol[1] = EOS;
        AddTextPrinterParameterized4(windowId, FONT_SMALL, genderX, BSTATUS_DETAIL_HEADER_RIGHT_INFO_Y, 0, 0,
                                     colors, TEXT_SKIP_DRAW, genderSymbol);
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void BattleStatus_DetailRefreshIcon(void)
{
    struct Pokemon *mon;
    u16 species;
    u32 personality;

    if (sBattleStatusMenu.detailIconSpriteId != SPRITE_NONE)
        FreeAndDestroyMonIconSprite(&gSprites[sBattleStatusMenu.detailIconSpriteId]);
    sBattleStatusMenu.detailIconSpriteId = SPRITE_NONE;

    mon = GetBattlerMon(sBattleStatusMenu.selectedBattlerId);
    species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG);
    personality = GetMonData(mon, MON_DATA_PERSONALITY);

    if (species == SPECIES_NONE)
        return;

    sBattleStatusMenu.detailIconSpriteId = CreateMonIcon(species, SpriteCallbackDummy,
                                                         BSTATUS_DETAIL_ICON_X, BSTATUS_DETAIL_ICON_Y, 0, personality);
    if (sBattleStatusMenu.detailIconSpriteId != SPRITE_NONE)
        gSprites[sBattleStatusMenu.detailIconSpriteId].oam.priority = 0;
}

static void BattleStatus_DetailDestroyTypeIcons(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sBattleStatusMenu.detailTypeIconSpriteIds); i++)
    {
        if (sBattleStatusMenu.detailTypeIconSpriteIds[i] != SPRITE_NONE)
            DestroySprite(&gSprites[sBattleStatusMenu.detailTypeIconSpriteIds[i]]);
        sBattleStatusMenu.detailTypeIconSpriteIds[i] = SPRITE_NONE;
    }
}

static void BattleStatus_DetailRefreshTypeIcons(void)
{
    enum BattlerId battler = sBattleStatusMenu.selectedBattlerId;
    enum Type type1 = gBattleMons[battler].types[0];
    enum Type type2 = gBattleMons[battler].types[1];
    u8 windowId = sBattleStatusMenu.detailWindowIds[WIN_DETAIL_HEADER];
    s16 windowLeftPx;
    s16 windowTopPx;
    s16 rightAlignedTypeRightPx;
    s16 type1LeftPx;
    s16 type2LeftPx;
    u8 spriteId;

    BattleStatus_DetailDestroyTypeIcons();
    if (windowId == WINDOW_NONE)
        return;

    // Terastallized battlers should display their single defensive Tera type.
    if (GetActiveGimmick(battler) == GIMMICK_TERA)
    {
        type1 = GetBattlerTeraType(battler);
        type2 = type1;
    }

    if (type1 >= NUMBER_OF_MON_TYPES)
        type1 = TYPE_MYSTERY;
    if (type2 >= NUMBER_OF_MON_TYPES)
        type2 = TYPE_MYSTERY;

    windowLeftPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT) * 8;
    windowTopPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP) * 8;

    // Right edge of the rightmost type icon matches the gimmick indicator's right edge.
    rightAlignedTypeRightPx = windowLeftPx + WindowWidthPx(windowId) - 2;
    type2LeftPx = rightAlignedTypeRightPx - BSTATUS_DETAIL_TYPE_W;
    type1LeftPx = type2LeftPx - BSTATUS_DETAIL_TYPE_GAP_X;

    spriteId = CreateSprite(&gSpriteTemplate_MoveTypes,
                            type1LeftPx + (BSTATUS_DETAIL_TYPE_W / 2),
                            windowTopPx + BSTATUS_DETAIL_TYPE_Y + (BSTATUS_DETAIL_TYPE_H / 2), 0);
    if (spriteId != SPRITE_NONE)
    {
        StartSpriteAnim(&gSprites[spriteId], type1);
        gSprites[spriteId].oam.paletteNum = gTypesInfo[type1].palette;
        gSprites[spriteId].oam.priority = 0;
        sBattleStatusMenu.detailTypeIconSpriteIds[0] = spriteId;
    }

    if (type2 == TYPE_MYSTERY || type2 == type1)
        return;

    spriteId = CreateSprite(&gSpriteTemplate_MoveTypes,
                            type2LeftPx + (BSTATUS_DETAIL_TYPE_W / 2),
                            windowTopPx + BSTATUS_DETAIL_TYPE_Y + (BSTATUS_DETAIL_TYPE_H / 2), 0);
    if (spriteId != SPRITE_NONE)
    {
        StartSpriteAnim(&gSprites[spriteId], type2);
        gSprites[spriteId].oam.paletteNum = gTypesInfo[type2].palette;
        gSprites[spriteId].oam.priority = 0;
        sBattleStatusMenu.detailTypeIconSpriteIds[1] = spriteId;
    }
}

static s16 BattleStatus_DetailGetStatRowTextY(u8 row)
{
    s16 y = BSTATUS_DETAIL_STAT_ROW_START_Y + row * BSTATUS_DETAIL_STAT_ROW_SPACING_Y;

    // Add extra room between Speed (row 4) and Accuracy (row 5).
    if (row >= 5)
        y += BSTATUS_DETAIL_STAT_EXTRA_GAP_BEFORE_ACC;

    return y;
}

static void BattleStatus_DetailSetStatPipSpriteGraphic(u8 spriteId, u16 tileTag)
{
    u16 tileStart;

    if (spriteId == SPRITE_NONE)
        return;

    tileStart = GetSpriteTileStartByTag(tileTag);
    if (tileStart == 0xFFFF)
        return;

    gSprites[spriteId].oam.tileNum = tileStart;
}

static void BattleStatus_DetailCreateStatPips(void)
{
    u8 windowId = sBattleStatusMenu.detailWindowIds[WIN_DETAIL_STATS];
    s16 windowLeftPx;
    s16 windowTopPx;
    u8 row, col;

    BattleStatus_DetailDestroyStatPips();
    if (windowId == WINDOW_NONE)
        return;

    LoadSpritePaletteInSlot(&(struct SpritePalette){
        .data = gBattleStatusTextPalette,
        .tag = BSTATUS_DETAIL_STAT_PIP_PAL_TAG,
    }, BSTATUS_DETAIL_STAT_PIP_PAL_NUM);
    LoadSpriteSheet(&sSpriteSheet_BattleStatusDetailStatPipDot);
    LoadSpriteSheet(&sSpriteSheet_BattleStatusDetailStatPipUp);
    LoadSpriteSheet(&sSpriteSheet_BattleStatusDetailStatPipDown);

    windowLeftPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT) * 8;
    windowTopPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP) * 8;

    for (row = 0; row < BSTATUS_DETAIL_STAT_ROW_COUNT; row++)
    {
        s16 rowY = windowTopPx + BattleStatus_DetailGetStatRowTextY(row) + BSTATUS_DETAIL_STAT_PIP_Y_OFFSET;

        for (col = 0; col < BSTATUS_DETAIL_STAT_PIPS_PER_ROW; col++)
        {
            u8 spriteId = CreateSprite(&sSpriteTemplate_BattleStatusDetailStatPip,
                                       windowLeftPx + BSTATUS_DETAIL_STAT_PIP_START_X + col * BSTATUS_DETAIL_STAT_PIP_SPACING_X,
                                       rowY, 0);
            sBattleStatusMenu.detailStatPipSpriteIds[row][col] = spriteId;
            if (spriteId != SPRITE_NONE)
            {
                gSprites[spriteId].invisible = FALSE;
                gSprites[spriteId].oam.priority = 0;
            }
        }
    }
}

static void BattleStatus_DetailDestroyStatPips(void)
{
    u8 row, col;

    for (row = 0; row < BSTATUS_DETAIL_STAT_ROW_COUNT; row++)
    {
        for (col = 0; col < BSTATUS_DETAIL_STAT_PIPS_PER_ROW; col++)
        {
            u8 spriteId = sBattleStatusMenu.detailStatPipSpriteIds[row][col];

            if (spriteId != SPRITE_NONE)
                DestroySprite(&gSprites[spriteId]);
            sBattleStatusMenu.detailStatPipSpriteIds[row][col] = SPRITE_NONE;
        }
    }

    FreeSpriteTilesByTag(BSTATUS_DETAIL_STAT_PIP_DOT_TILE_TAG);
    FreeSpriteTilesByTag(BSTATUS_DETAIL_STAT_PIP_UP_TILE_TAG);
    FreeSpriteTilesByTag(BSTATUS_DETAIL_STAT_PIP_DOWN_TILE_TAG);
    FreeSpritePaletteByTag(BSTATUS_DETAIL_STAT_PIP_PAL_TAG);
}

static void BattleStatus_DetailRefreshStatPips(void)
{
    enum BattlerId battler = sBattleStatusMenu.selectedBattlerId;
    u8 row, col;

    for (row = 0; row < BSTATUS_DETAIL_STAT_ROW_COUNT; row++)
    {
        s8 delta = gBattleMons[battler].statStages[sBattleStatusDetailStatIds[row]] - DEFAULT_STAT_STAGE;
        u8 absDelta = (delta >= 0) ? delta : -delta;
        u16 tileTag = BSTATUS_DETAIL_STAT_PIP_DOT_TILE_TAG;

        if (absDelta > BSTATUS_DETAIL_STAT_PIPS_PER_ROW)
            absDelta = BSTATUS_DETAIL_STAT_PIPS_PER_ROW;

        if (delta > 0)
            tileTag = BSTATUS_DETAIL_STAT_PIP_UP_TILE_TAG;
        else if (delta < 0)
            tileTag = BSTATUS_DETAIL_STAT_PIP_DOWN_TILE_TAG;

        for (col = 0; col < BSTATUS_DETAIL_STAT_PIPS_PER_ROW; col++)
        {
            u8 spriteId = sBattleStatusMenu.detailStatPipSpriteIds[row][col];
            u16 currentTag = (col < absDelta) ? tileTag : BSTATUS_DETAIL_STAT_PIP_DOT_TILE_TAG;

            BattleStatus_DetailSetStatPipSpriteGraphic(spriteId, currentTag);
        }
    }
}

static void BattleStatus_DetailCycleBattler(s8 direction)
{
    if (sBattleStatusMenu.cardCount == 0)
        return;

    if (sBattleStatusMenu.selectedCardIndex >= sBattleStatusMenu.cardCount)
        sBattleStatusMenu.selectedCardIndex = 0;

    if (direction < 0)
    {
        if (sBattleStatusMenu.selectedCardIndex == 0)
            sBattleStatusMenu.selectedCardIndex = sBattleStatusMenu.cardCount - 1;
        else
            sBattleStatusMenu.selectedCardIndex--;
    }
    else
    {
        sBattleStatusMenu.selectedCardIndex++;
        if (sBattleStatusMenu.selectedCardIndex >= sBattleStatusMenu.cardCount)
            sBattleStatusMenu.selectedCardIndex = 0;
    }

    BattleStatus_OverviewSyncSelectedBattler();
    BattleStatus_DetailRefreshIcon();
    BattleStatus_DetailRefreshHpBar();
    BattleStatus_DetailRefreshStatusIcon();
    BattleStatus_DetailRefreshTypeIcons();
    BattleStatus_DetailRefreshHeader();
    BattleStatus_DetailRefreshItemAbilityWindow();
    BattleStatus_DetailRefreshStatPips();
    BattleStatus_DetailInitEffectsList();
}

static void BattleStatus_DetailInitEffectsList(void)
{
    BattleStatus_DetailDestroyEffectsScrollbar();
    sBattleStatusMenu.detailActiveEffectsCount = 0;
    sBattleStatusMenu.detailEffectsCursor = 0;
    sBattleStatusMenu.detailEffectsScroll = 0;
    BattleStatus_DetailBuildActiveEffects();
    BattleStatus_DetailRefreshEffectsSection();
}

static void BattleStatus_DetailBuildActiveEffects(void)
{
    enum BattlerId battler = sBattleStatusMenu.selectedBattlerId;
    enum BattleSide side = GetBattlerSide(battler);
    u32 status1 = gBattleMons[battler].status1;
    u32 sideStatuses = gSideStatuses[side];

    if (gBattleWeather & B_WEATHER_SUN_PRIMAL)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_EXTREMELY_HARSH_SUNLIGHT);
    else if (gBattleWeather & B_WEATHER_SUN)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_HARSH_SUNLIGHT);

    if (gBattleWeather & B_WEATHER_RAIN_PRIMAL)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_HEAVY_RAIN);
    else if (gBattleWeather & B_WEATHER_RAIN)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_RAIN);

    if (gBattleWeather & B_WEATHER_SANDSTORM)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_SANDSTORM);
    if (gBattleWeather & B_WEATHER_SNOW)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_SNOW);
    if (gBattleWeather & B_WEATHER_STRONG_WINDS)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_STRONG_WINDS);
    if (gBattleWeather & B_WEATHER_FOG)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_FOG);

    if (gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_ELECTRIC_TERRAIN);
    if (gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_GRASSY_TERRAIN);
    if (gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_MISTY_TERRAIN);
    if (gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_PSYCHIC_TERRAIN);
    if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_TRICK_ROOM);
    if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_MAGIC_ROOM);
    if (gFieldStatuses & STATUS_FIELD_WONDER_ROOM)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_WONDER_ROOM);
    if (gFieldStatuses & STATUS_FIELD_GRAVITY)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_GRAVITY);
    if (gFieldStatuses & STATUS_FIELD_MUDSPORT)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_MUD_SPORT);
    if (gFieldStatuses & STATUS_FIELD_WATERSPORT)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_WATER_SPORT);
    if (gFieldStatuses & STATUS_FIELD_FAIRY_LOCK)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_FAIRY_LOCK);

    if (sideStatuses & SIDE_STATUS_MIST)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_MIST);
    if (sideStatuses & SIDE_STATUS_SAFEGUARD)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_SAFEGUARD);
    if (sideStatuses & SIDE_STATUS_LUCKY_CHANT)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_LUCKY_CHANT);
    if (sideStatuses & SIDE_STATUS_TAILWIND)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_TAILWIND);
    if (sideStatuses & SIDE_STATUS_LIGHTSCREEN)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_LIGHT_SCREEN);
    if (sideStatuses & SIDE_STATUS_REFLECT)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_REFLECT);
    if (sideStatuses & SIDE_STATUS_AURORA_VEIL)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_AURORA_VEIL);
    if (sideStatuses & SIDE_STATUS_RAINBOW)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_RAINBOW);
    if (sideStatuses & SIDE_STATUS_SWAMP)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_SWAMP);
    if (sideStatuses & SIDE_STATUS_SEA_OF_FIRE)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_SEA_OF_FIRE);
    if (sideStatuses & SIDE_STATUS_DAMAGE_NON_TYPES)
    {
        switch (gSideTimers[side].damageNonTypesType)
        {
        case TYPE_FIRE:
            BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_G_MAX_WILDFIRE);
            break;
        case TYPE_ROCK:
            BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_G_MAX_VOLCALITH);
            break;
        case TYPE_GRASS:
            BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_G_MAX_VINE_LASH);
            break;
        case TYPE_WATER:
            BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_G_MAX_CANNONADE);
            break;
        default:
            break;
        }
    }

    if (IsHazardOnSide(side, HAZARDS_STEALTH_ROCK))
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_STEALTH_ROCK);
    if (IsHazardOnSide(side, HAZARDS_SPIKES))
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_SPIKES);
    if (IsHazardOnSide(side, HAZARDS_TOXIC_SPIKES))
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_TOXIC_SPIKES);
    if (IsHazardOnSide(side, HAZARDS_STICKY_WEB))
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_STICKY_WEB);

    if (status1 & STATUS1_TOXIC_POISON)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_BADLY_POISONED);
    else if (status1 & STATUS1_POISON)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_POISONED);

    if (status1 & STATUS1_PARALYSIS)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_PARALYZED);
    if (status1 & STATUS1_BURN)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_BURNED);
    if (status1 & STATUS1_FROSTBITE)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_FROSTBITE);

    if (gBattleMons[battler].volatiles.focusEnergy
     || gBattleMons[battler].volatiles.dragonCheer
     || gBattleMons[battler].volatiles.bonusCritStages > 0)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_CRITICAL_HIT_BOOST);
    if (gBattleMons[battler].volatiles.confusionTurns > 0
     || gBattleMons[battler].volatiles.infiniteConfusion)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_CONFUSION);
    if (gBattleMons[battler].volatiles.infatuation)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_INFATUATION);
    if (gBattleMons[battler].volatiles.nightmare)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_NIGHTMARE);
    if (gBattleMons[battler].volatiles.yawn)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_DROWSY);
    if (gBattleMons[battler].volatiles.encoreTimer > 0)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_ENCORE);
    if (gBattleMons[battler].volatiles.torment)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_TORMENT);
    if (gBattleMons[battler].volatiles.grudge)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_GRUDGE);
    if (gBattleMons[battler].volatiles.healBlock)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_HEALING_PREVENTED);
    if (gBattleMons[battler].volatiles.foresight || gBattleMons[battler].volatiles.miracleEye)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_IDENTIFIED);
    if (gBattleMons[battler].volatiles.disableTimer > 0)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_MOVE_DISABLED);
    if (gBattleMons[battler].volatiles.escapePrevention || gBattleMons[battler].volatiles.noRetreat)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_CANT_ESCAPE);
    if (gBattleMons[battler].volatiles.lockOn)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_LOCK_ON);
    if (gBattleMons[battler].volatiles.embargo)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_EMBARGO);
    if (gBattleMons[battler].volatiles.chargeTimer > 0)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_CHARGE);
    if (gBattleMons[battler].volatiles.tauntTimer > 0)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_TAUNT);
    if (gBattleMons[battler].volatiles.telekinesis)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_TELEKINESIS);
    if (gBattleMons[battler].volatiles.magnetRise)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_MAGNET_RISE);
    if (gBattleStruct->wish[battler].counter > 0)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_WISH);
    if (gBattleMons[battler].volatiles.root)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_INGRAIN);
    if (gBattleMons[battler].volatiles.cursed)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_CURSE);
    if (gBattleMons[battler].volatiles.destinyBond)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_DESTINY_BOND);
    if (gBattleMons[battler].volatiles.wrapped)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_BOUND);
    if (gBattleMons[battler].volatiles.bideTurns > 0)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_BIDE);
    if (gBattleStruct->futureSight[battler].counter > 0)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_FUTURE_ATTACK);
    if (gBattleMons[battler].volatiles.uproarTurns > 0)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_UPROAR);
    if (gBattleMons[battler].volatiles.aquaRing)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_AQUA_RING);
    if (gBattleMons[battler].volatiles.autotomizeCount > 0)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_AUTOTOMIZE);
    if (gBattleMons[battler].volatiles.smackDown)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_SMACK_DOWN);
    if (gBattleMons[battler].volatiles.throatChopTimer > 0)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_THROAT_CHOP);
    if (gBattleMons[battler].volatiles.laserFocus || gBattleMons[battler].volatiles.laserFocusTimer > 0)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_LASER_FOCUS);
    if (gBattleMons[battler].volatiles.tarShot)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_TAR_SHOT);
    if (gBattleMons[battler].volatiles.octolock)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_OCTOLOCK);
    if (gBattleMons[battler].volatiles.glaiveRush)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_FIXATED);
    if (gBattleMons[battler].volatiles.powerTrick)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_STANCE_SWAP);
    if (gBattleMons[battler].volatiles.slowStartTimer > 0)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_SLOW_START);
    if (gBattleMons[battler].volatiles.saltCure)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_SALT_CURE);
    if (gBattleMons[battler].volatiles.syrupBomb || gBattleMons[battler].volatiles.syrupBombTimer > 0)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_SYRUPY);
    if (gBattleMons[battler].volatiles.rampageTurns > 0)
        BattleStatus_DetailTryAddActiveEffect(BSTATUS_EFFECT_RAMPAGING);
}

static void BattleStatus_DetailTryAddActiveEffect(enum BattleStatusEffectId effectId)
{
    u8 i;

    if (effectId >= BSTATUS_EFFECT_COUNT)
        return;

    for (i = 0; i < sBattleStatusMenu.detailActiveEffectsCount; i++)
    {
        if (sBattleStatusMenu.detailActiveEffects[i] == effectId)
            return;
    }

    if (sBattleStatusMenu.detailActiveEffectsCount < BSTATUS_DETAIL_MAX_ACTIVE_EFFECTS)
        sBattleStatusMenu.detailActiveEffects[sBattleStatusMenu.detailActiveEffectsCount++] = effectId;
}

static const struct BattleStatusEffectData *BattleStatus_GetEffectData(enum BattleStatusEffectId effectId)
{
    if (effectId >= BSTATUS_EFFECT_COUNT)
        return NULL;

    return &sBattleStatusEffects[effectId];
}

static bool8 BattleStatus_DetailTryMoveEffectCursor(s8 direction)
{
    if (sBattleStatusMenu.detailActiveEffectsCount == 0)
        return FALSE;

    if (direction < 0)
    {
        if (sBattleStatusMenu.detailEffectsCursor == 0)
            return FALSE;
        sBattleStatusMenu.detailEffectsCursor--;
    }
    else if (direction > 0)
    {
        if (sBattleStatusMenu.detailEffectsCursor + 1 >= sBattleStatusMenu.detailActiveEffectsCount)
            return FALSE;
        sBattleStatusMenu.detailEffectsCursor++;
    }
    else
    {
        return FALSE;
    }

    if (sBattleStatusMenu.detailEffectsCursor < sBattleStatusMenu.detailEffectsScroll)
        sBattleStatusMenu.detailEffectsScroll = sBattleStatusMenu.detailEffectsCursor;
    else if (sBattleStatusMenu.detailEffectsCursor >= sBattleStatusMenu.detailEffectsScroll + BSTATUS_DETAIL_EFFECTS_VISIBLE_ROWS)
        sBattleStatusMenu.detailEffectsScroll = sBattleStatusMenu.detailEffectsCursor - BSTATUS_DETAIL_EFFECTS_VISIBLE_ROWS + 1;

    return TRUE;
}

static void BattleStatus_DetailRefreshEffectsWindow(void)
{
    u8 windowId = sBattleStatusMenu.detailWindowIds[WIN_DETAIL_EFFECTS];
    u8 row;

    if (windowId == WINDOW_NONE)
        return;

    BattleStatus_DetailDrawWindowFrame(windowId);
    AddTextPrinterParameterized4(windowId, FONT_NARROWER, 2, BSTATUS_DETAIL_EFFECTS_HEADER_Y, 0, 0, sTextColor_BattleStatus_Default,
                                 TEXT_SKIP_DRAW, sText_BattleStatus_DetailEffectsHeader);

    if (sBattleStatusMenu.detailActiveEffectsCount != 0)
    {
        for (row = 0; row < BSTATUS_DETAIL_EFFECTS_VISIBLE_ROWS; row++)
        {
            u16 index = sBattleStatusMenu.detailEffectsScroll + row;
            enum BattleStatusEffectId effectId;
            const struct BattleStatusEffectData *effectData;
            u8 y;

            if (index >= sBattleStatusMenu.detailActiveEffectsCount)
                break;

            effectId = sBattleStatusMenu.detailActiveEffects[index];
            effectData = BattleStatus_GetEffectData(effectId);
            if (effectData == NULL || effectData->name == NULL)
                continue;

            y = BSTATUS_DETAIL_EFFECTS_LIST_START_Y + row * BSTATUS_DETAIL_EFFECTS_ROW_HEIGHT;
            if (index == sBattleStatusMenu.detailEffectsCursor)
            {
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROWER, BSTATUS_DETAIL_EFFECTS_CURSOR_X, y, 0, 0,
                                             sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW, gText_SelectorArrow2);
            }
            AddTextPrinterParameterized4(windowId, FONT_SHORT_NARROWER, BSTATUS_DETAIL_EFFECTS_TEXT_X, y, 0, 0,
                                         sTextColor_BattleStatus_Default,
                                         TEXT_SKIP_DRAW, effectData->name);
        }
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
    BattleStatus_DetailRefreshEffectsScrollbar();
    BattleStatus_DetailUpdateEffectsCursor();
}

static void BattleStatus_DetailRefreshEffectsScrollbar(void)
{
    u8 windowId = sBattleStatusMenu.detailWindowIds[WIN_DETAIL_EFFECTS];
    s16 windowLeftPx;
    s16 windowTopPx;
    s16 scrollbarMinY;
    s16 scrollbarMaxY;
    s16 scrollbarX;
    u16 maxScroll;
    u8 spriteId;

    if (windowId == WINDOW_NONE || sBattleStatusMenu.detailActiveEffectsCount <= BSTATUS_DETAIL_EFFECTS_VISIBLE_ROWS)
    {
        BattleStatus_DetailDestroyEffectsScrollbar();
        return;
    }

    windowLeftPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT) * 8;
    windowTopPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP) * 8;
    scrollbarX = windowLeftPx + WindowWidthPx(windowId) - BSTATUS_DETAIL_EFFECTS_SCROLLBAR_X_INSET;
    scrollbarMinY = windowTopPx + BSTATUS_DETAIL_EFFECTS_LIST_START_Y + 7;
    scrollbarMaxY = scrollbarMinY + 3 + (BSTATUS_DETAIL_EFFECTS_VISIBLE_ROWS - 1) * BSTATUS_DETAIL_EFFECTS_ROW_HEIGHT;
    maxScroll = sBattleStatusMenu.detailActiveEffectsCount - BSTATUS_DETAIL_EFFECTS_VISIBLE_ROWS;
    if (sBattleStatusMenu.detailEffectsScroll > maxScroll)
        sBattleStatusMenu.detailEffectsScroll = maxScroll;

    if (sBattleStatusMenu.detailEffectsScrollbarSpriteId == SPRITE_NONE)
    {
        spriteId = CreateSprite(&sSpriteTemplate_BattleStatusDetailEffectsScrollbar, scrollbarX, scrollbarMinY, 0);
        if (spriteId == SPRITE_NONE)
            return;
        sBattleStatusMenu.detailEffectsScrollbarSpriteId = spriteId;
        gSprites[spriteId].oam.priority = 0;
    }

    spriteId = sBattleStatusMenu.detailEffectsScrollbarSpriteId;
    gSprites[spriteId].x = scrollbarX;
    gSprites[spriteId].y = scrollbarMinY + (sBattleStatusMenu.detailEffectsScroll * (scrollbarMaxY - scrollbarMinY) + (maxScroll / 2)) / maxScroll;
    gSprites[spriteId].invisible = FALSE;
}

static void BattleStatus_DetailFormatDescriptionText(enum BattleStatusEffectId effectId, u8 *dst)
{
    const struct BattleStatusEffectData *effectData = BattleStatus_GetEffectData(effectId);

    if (effectData == NULL || effectData->description == NULL)
    {
        dst[0] = EOS;
        return;
    }

    // Keep placeholder expansion centralized so dynamic words can be filled in per effect.
    gStringVar1[0] = EOS;
    switch (effectId)
    {
    case BSTATUS_EFFECT_ENCORE:
        StringCopy(gStringVar1, COMPOUND_STRING("its last move"));
        break;
    case BSTATUS_EFFECT_MOVE_DISABLED:
        StringCopy(gStringVar1, COMPOUND_STRING("A move"));
        break;
    case BSTATUS_EFFECT_G_MAX_WILDFIRE:
        StringCopy(gStringVar1, COMPOUND_STRING("Fire"));
        break;
    case BSTATUS_EFFECT_G_MAX_VOLCALITH:
        StringCopy(gStringVar1, COMPOUND_STRING("Rock"));
        break;
    case BSTATUS_EFFECT_G_MAX_VINE_LASH:
        StringCopy(gStringVar1, COMPOUND_STRING("Grass"));
        break;
    case BSTATUS_EFFECT_G_MAX_CANNONADE:
        StringCopy(gStringVar1, COMPOUND_STRING("Water"));
        break;
    default:
        break;
    }

    StringExpandPlaceholders(dst, effectData->description);
}

static void BattleStatus_DetailClampTextLines(u8 *text, u8 maxLines)
{
    u8 line = 1;

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

static void BattleStatus_DetailRefreshDescriptionWindow(void)
{
    u8 windowId = sBattleStatusMenu.detailWindowIds[WIN_DETAIL_DESCRIPTION];
    u8 descFont = FONT_SMALL_NARROWER;
    u8 maxLines;
    u8 lineHeight;
    u16 windowHeightPx;
    u16 availableHeight;
    u32 wrapWidth;
    u8 *end;

    if (windowId == WINDOW_NONE)
        return;

    BattleStatus_DetailDrawWindowFrame(windowId);

    if (sBattleStatusMenu.detailActiveEffectsCount == 0
     || sBattleStatusMenu.detailEffectsCursor >= sBattleStatusMenu.detailActiveEffectsCount)
    {
        sBattleStatusDetailTextBuffer[0] = EOS;
    }
    else
    {
        enum BattleStatusEffectId effectId = sBattleStatusMenu.detailActiveEffects[sBattleStatusMenu.detailEffectsCursor];
        BattleStatus_DetailFormatDescriptionText(effectId, sBattleStatusDetailTextBuffer);
    }

    wrapWidth = WindowWidthPx(windowId) - (BSTATUS_DETAIL_DESC_TEXT_X * 2) - 2;
    if (wrapWidth < 8)
        wrapWidth = 8;

    windowHeightPx = GetWindowAttribute(windowId, WINDOW_HEIGHT) * 8;
    availableHeight = (windowHeightPx > BSTATUS_DETAIL_DESC_TEXT_Y + 1) ? windowHeightPx - BSTATUS_DETAIL_DESC_TEXT_Y - 1 : 1;
    lineHeight = GetFontAttribute(descFont, FONTATTR_MAX_LETTER_HEIGHT) + GetFontAttribute(descFont, FONTATTR_LINE_SPACING);
    if (lineHeight == 0)
        lineHeight = 1;
    maxLines = availableHeight / lineHeight;
    if (maxLines == 0)
        maxLines = 1;

    // Wrap words into new lines to keep long strings from wrapping over themselves in-window.
    BreakStringAutomatic(sBattleStatusDetailTextBuffer, wrapWidth, maxLines, descFont, HIDE_SCROLL_PROMPT);

    end = sBattleStatusDetailTextBuffer + StringLength(sBattleStatusDetailTextBuffer);
    WrapFontIdToFit(sBattleStatusDetailTextBuffer, end, descFont, wrapWidth);
    BattleStatus_DetailClampTextLines(sBattleStatusDetailTextBuffer, maxLines);

    if (sBattleStatusDetailTextBuffer[0] != EOS)
    {
        AddTextPrinterParameterized4(windowId, descFont, BSTATUS_DETAIL_DESC_TEXT_X, BSTATUS_DETAIL_DESC_TEXT_Y, 0, 0,
                                     sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW, sBattleStatusDetailTextBuffer);
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void BattleStatus_DetailRefreshEffectsSection(void)
{
    BattleStatus_DetailRefreshEffectsWindow();
    BattleStatus_DetailRefreshDescriptionWindow();
}

static void BattleStatus_DetailDestroyEffectsCursor(void)
{
    if (sBattleStatusMenu.cursorSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sBattleStatusMenu.cursorSpriteId]);
    sBattleStatusMenu.cursorSpriteId = SPRITE_NONE;
}

static void BattleStatus_DetailDestroyEffectsScrollbar(void)
{
    if (sBattleStatusMenu.detailEffectsScrollbarSpriteId != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sBattleStatusMenu.detailEffectsScrollbarSpriteId]);
        sBattleStatusMenu.detailEffectsScrollbarSpriteId = SPRITE_NONE;
    }
}

static void BattleStatus_DetailUpdateEffectsCursor(void)
{
    // Detail effects list uses a text cursor glyph instead of an OAM sprite.
    BattleStatus_DetailDestroyEffectsCursor();
}

static void BattleStatus_DetailDrawWindowFrame(u8 windowId)
{
    u16 width = WindowWidthPx(windowId);
    u16 height = GetWindowAttribute(windowId, WINDOW_HEIGHT) * 8;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(BSTATUS_TEXT_COLOR_WHITE));
    FillWindowPixelRect(windowId, PIXEL_FILL(BSTATUS_TEXT_COLOR_DARK_GRAY), 0, 0, width, 1);
    FillWindowPixelRect(windowId, PIXEL_FILL(BSTATUS_TEXT_COLOR_DARK_GRAY), 0, 0, 1, height);
    FillWindowPixelRect(windowId, PIXEL_FILL(BSTATUS_TEXT_COLOR_DARK_GRAY), 0, height - 1, width, 1);
    FillWindowPixelRect(windowId, PIXEL_FILL(BSTATUS_TEXT_COLOR_DARK_GRAY), width - 1, 0, 1, height);
}

static void BattleStatus_OverviewBuildBattlerLists(void)
{
    enum BattlerId battler;

    sBattleStatusMenu.playerCount = 0;
    sBattleStatusMenu.enemyCount = 0;

    for (battler = 0; battler < gBattlersCount; battler++)
    {
        if (!IsBattlerAlive(battler))
            continue;

        BattleStatus_GetNickname(battler, sBattleStatusMenu.battlerNames[battler]);
        if (IsOnPlayerSide(battler))
            sBattleStatusMenu.playerBattlers[sBattleStatusMenu.playerCount++] = battler;
        else
            sBattleStatusMenu.enemyBattlers[sBattleStatusMenu.enemyCount++] = battler;
    }

    BattleStatus_OverviewSortBattlersByScreenOrder(sBattleStatusMenu.playerBattlers, sBattleStatusMenu.playerCount);
    BattleStatus_OverviewSortBattlersByScreenOrder(sBattleStatusMenu.enemyBattlers, sBattleStatusMenu.enemyCount);
}

static void BattleStatus_OverviewBufferLabelText(void)
{
    if (BattleStatus_GetOpponentTrainerCount() == 1)
        StringCopy(sBattleStatusMenu.enemyLabelText, BattleStatus_GetPrimaryOpponentTrainerName());
    else
        StringCopy(sBattleStatusMenu.enemyLabelText, sText_BattleStatus_Opponent);

    if (BattleStatus_HasPlayerPartnerTrainer())
        StringCopy(sBattleStatusMenu.playerLabelText, sText_BattleStatus_Ally);
    else
        StringCopy(sBattleStatusMenu.playerLabelText, BattleStatus_GetPlayerTrainerName());
}

static void BattleStatus_OverviewSortBattlersByScreenOrder(enum BattlerId *battlers, u8 count)
{
    u8 i;
    u8 j;

    for (i = 0; i < count; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (BattleStatus_OverviewGetBattlerSortOrder(battlers[j]) < BattleStatus_OverviewGetBattlerSortOrder(battlers[i]))
            {
                enum BattlerId temp = battlers[i];
                battlers[i] = battlers[j];
                battlers[j] = temp;
            }
        }
    }
}

static u8 BattleStatus_OverviewGetBattlerSortOrder(enum BattlerId battler)
{
    u8 pos = GetBattlerPosition(battler);

    if (IsOnPlayerSide(battler))
        return pos;

    return pos ^ BIT_FLANK;
}

static void BattleStatus_OverviewComputeRowLayout(const enum BattlerId *battlers, u8 count, s16 *outXs,
                                                  s16 *outRowLeft, s16 *outRowRight, s16 *outRowCenter)
{
    s16 gapTiles = BSTATUS_CARD_GAP_TILES;
    s16 totalWidthTiles;
    s16 startXTile;
    s16 i;
    s16 safeLeft = BSTATUS_SAFE_LEFT_TILE;
    s16 safeRight = BSTATUS_SAFE_RIGHT_TILE;
    s16 safeWidthTiles = safeRight - safeLeft + 1;
    s16 screenWidthTiles = DISPLAY_WIDTH / 8;

    if (count == 0)
    {
        *outRowLeft = BSTATUS_SAFE_LEFT_TILE * 8;
        *outRowRight = BSTATUS_SAFE_LEFT_TILE * 8;
        *outRowCenter = (DISPLAY_WIDTH / 2);
        return;
    }

    totalWidthTiles = count * BSTATUS_CARD_TILE_W + (count - 1) * gapTiles;
    if (totalWidthTiles > safeWidthTiles)
    {
        gapTiles = BSTATUS_MIN_GAP_TILES;
        totalWidthTiles = count * BSTATUS_CARD_TILE_W + (count - 1) * gapTiles;
    }

    startXTile = (screenWidthTiles - totalWidthTiles) / 2;
    if (startXTile < safeLeft)
        startXTile = safeLeft;
    if (startXTile + totalWidthTiles - 1 > safeRight)
        startXTile = safeRight - totalWidthTiles + 1;
    if (startXTile < safeLeft)
        startXTile = safeLeft;

    for (i = 0; i < count; i++)
        outXs[i] = (startXTile + i * (BSTATUS_CARD_TILE_W + gapTiles)) * 8;

    *outRowLeft = outXs[0];
    *outRowRight = outXs[count - 1] + BSTATUS_CARD_W;
    *outRowCenter = (*outRowLeft + *outRowRight) / 2;
}

static void BattleStatus_OverviewCreateCards(void)
{
    u8 i;
    s16 rowXs[MAX_BATTLERS_COUNT];

    sBattleStatusMenu.cardCount = 0;

    BattleStatus_OverviewComputeRowLayout(sBattleStatusMenu.enemyBattlers, sBattleStatusMenu.enemyCount,
                                      rowXs, &sBattleStatusMenu.enemyRowLeft, &sBattleStatusMenu.enemyRowRight,
                                      &sBattleStatusMenu.enemyRowCenter);

    for (i = 0; i < sBattleStatusMenu.enemyCount; i++)
    {
        struct BattleStatusCard *card = &sBattleStatusMenu.cards[sBattleStatusMenu.cardCount++];
        card->battlerId = sBattleStatusMenu.enemyBattlers[i];
        card->x = rowXs[i];
        card->y = BSTATUS_ROW_Y_ENEMY;
        BattleStatus_OverviewDrawCard(card);
    }

    BattleStatus_OverviewComputeRowLayout(sBattleStatusMenu.playerBattlers, sBattleStatusMenu.playerCount,
                                      rowXs, &sBattleStatusMenu.playerRowLeft, &sBattleStatusMenu.playerRowRight,
                                      &sBattleStatusMenu.playerRowCenter);

    for (i = 0; i < sBattleStatusMenu.playerCount; i++)
    {
        struct BattleStatusCard *card = &sBattleStatusMenu.cards[sBattleStatusMenu.cardCount++];
        card->battlerId = sBattleStatusMenu.playerBattlers[i];
        card->x = rowXs[i];
        card->y = BSTATUS_ROW_Y_PLAYER;
        BattleStatus_OverviewDrawCard(card);
    }
}

static void BattleStatus_OverviewDrawCard(struct BattleStatusCard *card)
{
    u8 windowId = (card->y == BSTATUS_ROW_Y_ENEMY) ? WIN_ROW_ENEMY : WIN_ROW_PLAYER;
    u8 nameFont;
    const u8 *gimmickIndicatorData;
    u32 gimmickIndicatorPalTag;
    struct SpriteTemplate gimmickTemplate;
    struct SpriteSheet gimmickSheet;
    s16 localX = card->x;
    s16 localY = card->y;
    s16 maxNameWidth;
    s16 iconCenterX;
    s16 iconCenterY;
    u16 species = GetMonData(GetBattlerMon(card->battlerId), MON_DATA_SPECIES);
    u8 gender = GetMonGender(GetBattlerMon(card->battlerId));
    u32 personality = GetMonData(GetBattlerMon(card->battlerId), MON_DATA_PERSONALITY);
    u8 ailment = BattleStatus_GetAilmentFromBattler(card->battlerId);
    const u8 *name = sBattleStatusMenu.battlerNames[card->battlerId];

    if (windowId == WINDOW_NONE)
        return;

    if (windowId == WIN_ROW_ENEMY)
        localY -= (BSTATUS_ROW_Y_ENEMY / 8) * 8;
    else
        localY -= (BSTATUS_ROW_Y_PLAYER / 8) * 8;

    maxNameWidth = BSTATUS_CARD_W - BSTATUS_NAME_X - 2;
    if (gender == MON_MALE || gender == MON_FEMALE)
        maxNameWidth -= BSTATUS_GENDER_W + BSTATUS_GENDER_PAD_X + 2;
    nameFont = BattleStatus_GetBestFitNameFont(name, maxNameWidth);

    FillWindowPixelRect(windowId, PIXEL_FILL(BSTATUS_TEXT_COLOR_WHITE), localX, localY, BSTATUS_CARD_W, BSTATUS_CARD_H);
    FillWindowPixelRect(windowId, PIXEL_FILL(BSTATUS_TEXT_COLOR_DARK_GRAY), localX, localY, BSTATUS_CARD_W, 1);
    FillWindowPixelRect(windowId, PIXEL_FILL(BSTATUS_TEXT_COLOR_DARK_GRAY), localX, localY + BSTATUS_CARD_H - 1, BSTATUS_CARD_W, 1);
    FillWindowPixelRect(windowId, PIXEL_FILL(BSTATUS_TEXT_COLOR_DARK_GRAY), localX, localY, 1, BSTATUS_CARD_H);
    FillWindowPixelRect(windowId, PIXEL_FILL(BSTATUS_TEXT_COLOR_DARK_GRAY), localX + BSTATUS_CARD_W - 1, localY, 1, BSTATUS_CARD_H);

    AddTextPrinterParameterized4(windowId, nameFont, localX + BSTATUS_NAME_X, localY + BSTATUS_NAME_Y, 0, 0,
                                 sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW, name);

    if (gender == MON_MALE || gender == MON_FEMALE)
    {
        u8 genderSymbol[2];
        const u8 *colors = (gender == MON_MALE) ? sTextColor_BattleStatus_Male : sTextColor_BattleStatus_Female;
        u8 genderX = localX + BSTATUS_CARD_W - BSTATUS_GENDER_W - BSTATUS_GENDER_PAD_X;
        u8 genderY = localY + BSTATUS_GENDER_PAD_Y;

        genderSymbol[0] = (gender == MON_MALE) ? CHAR_MALE : CHAR_FEMALE;
        genderSymbol[1] = EOS;

        AddTextPrinterParameterized4(windowId, FONT_SMALL, genderX, genderY, 0, 0, colors, TEXT_SKIP_DRAW, genderSymbol);
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);

    iconCenterX = card->x + (BSTATUS_CARD_W / 2);
    iconCenterY = card->y + ((BSTATUS_NAME_Y + 8 + BSTATUS_HP_BAR_Y) / 2);

    if (species != SPECIES_NONE)
    {
        card->monIconSpriteId = CreateMonIcon(species, SpriteCallbackDummy,
                                              iconCenterX,
                                              iconCenterY,
                                              0, personality);
        if (card->monIconSpriteId != SPRITE_NONE)
            gSprites[card->monIconSpriteId].oam.priority = 0;
    }

    card->gimmickSpriteId = SPRITE_NONE;
    card->gimmickTileTag = 0;
    gimmickIndicatorData = BattleStatus_GetGimmickIndicatorData(card->battlerId, &gimmickIndicatorPalTag);
    if (gimmickIndicatorData != NULL && gimmickIndicatorPalTag != 0)
    {
        card->gimmickTileTag = BSTATUS_OVERVIEW_GIMMICK_TILE_TAG_BASE + card->battlerId;
        gimmickTemplate = sSpriteTemplate_BattleStatusDetailGimmick;
        gimmickTemplate.tileTag = card->gimmickTileTag;
        gimmickTemplate.paletteTag = gimmickIndicatorPalTag;

        gimmickSheet.data = gimmickIndicatorData;
        gimmickSheet.size = BSTATUS_DETAIL_GIMMICK_GFX_SIZE;
        gimmickSheet.tag = card->gimmickTileTag;
        LoadSpriteSheet(&gimmickSheet);

        card->gimmickSpriteId = CreateSprite(&gimmickTemplate,
                                             card->x + (BSTATUS_DETAIL_GIMMICK_W / 2) + 2,
                                             iconCenterY - (BSTATUS_DETAIL_GIMMICK_H / 2), 0);
        if (card->gimmickSpriteId != SPRITE_NONE)
            gSprites[card->gimmickSpriteId].oam.priority = 0;
    }

    if (ailment != AILMENT_NONE && ailment != AILMENT_PKRS)
    {
        s16 statusX = iconCenterX + 16 + BSTATUS_STATUS_PAD_X;
        s16 statusY = iconCenterY + 16 - BSTATUS_STATUS_PAD_Y;

        card->statusSpriteId = CreateSprite(&gSpriteTemplate_StatusIcons, statusX, statusY, 0);
        if (card->statusSpriteId != SPRITE_NONE)
        {
            StartSpriteAnim(&gSprites[card->statusSpriteId], ailment - 1);
            gSprites[card->statusSpriteId].oam.priority = 0;
        }
    }

    card->hpBarTileTag = BSTATUS_HP_BAR_TILE_TAG_BASE + card->battlerId;
    card->hpBarSpriteId = BattleStatus_CreateHpBarSprite(card->hpBarTileTag, card->x + BSTATUS_HP_BAR_X,
                                                         card->y + BSTATUS_HP_BAR_Y);
    BattleStatus_DrawHpBarSprite(card);

    if (BattleStatus_BattlerHasUnreadUpdates(card->battlerId))
    {
        s16 updateX = card->x + BSTATUS_CARD_W - BSTATUS_UPDATE_ICON_W;
        s16 updateY = iconCenterY - 8;

        card->updateSpriteId = CreateSprite(&sSpriteTemplate_BattleStatusUpdateIcon, updateX, updateY, 0);
        if (card->updateSpriteId != SPRITE_NONE)
            gSprites[card->updateSpriteId].oam.priority = 0;
    }
}

static u8 BattleStatus_GetBestFitNameFont(const u8 *name, s16 maxWidth)
{
    if (GetStringWidth(FONT_NORMAL, name, 0) <= maxWidth)
        return FONT_NORMAL;
    if (GetStringWidth(FONT_NARROW, name, 0) <= maxWidth)
        return FONT_NARROW;
    return FONT_NARROWER;
}

static void BattleStatus_OverviewDrawLabels(void)
{
    const u8 *enemyLabel;
    const u8 *playerLabel;
    s16 enemyLabelX;
    s16 playerLabelX;
    s16 enemyLabelWidth;
    s16 playerLabelWidth;

    enemyLabel = sBattleStatusMenu.enemyLabelText;
    playerLabel = sBattleStatusMenu.playerLabelText;

    enemyLabelWidth = GetStringWidth(FONT_SMALL, enemyLabel, 0);
    playerLabelWidth = GetStringWidth(FONT_SMALL, playerLabel, 0);

    enemyLabelX = sBattleStatusMenu.enemyRowCenter - (enemyLabelWidth / 2);
    playerLabelX = sBattleStatusMenu.playerRowCenter - (playerLabelWidth / 2);

    if (enemyLabelX < BSTATUS_SAFE_LEFT_TILE * 8)
        enemyLabelX = BSTATUS_SAFE_LEFT_TILE * 8;
    if (enemyLabelX + enemyLabelWidth > (BSTATUS_SAFE_RIGHT_TILE + 1) * 8)
        enemyLabelX = (BSTATUS_SAFE_RIGHT_TILE + 1) * 8 - enemyLabelWidth;

    if (playerLabelX < BSTATUS_SAFE_LEFT_TILE * 8)
        playerLabelX = BSTATUS_SAFE_LEFT_TILE * 8;
    if (playerLabelX + playerLabelWidth > (BSTATUS_SAFE_RIGHT_TILE + 1) * 8)
        playerLabelX = (BSTATUS_SAFE_RIGHT_TILE + 1) * 8 - playerLabelWidth;

    FillWindowPixelBuffer(WIN_LABEL_TOP, PIXEL_FILL(BSTATUS_TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WIN_LABEL_TOP, FONT_SMALL, enemyLabelX, 0, 0, 0,
                                 sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW, enemyLabel);
    PutWindowTilemap(WIN_LABEL_TOP);
    CopyWindowToVram(WIN_LABEL_TOP, COPYWIN_FULL);

    FillWindowPixelBuffer(WIN_LABEL_BOTTOM, PIXEL_FILL(BSTATUS_TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WIN_LABEL_BOTTOM, FONT_SMALL, playerLabelX, 0, 0, 0,
                                 sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW, playerLabel);
    PutWindowTilemap(WIN_LABEL_BOTTOM);
    CopyWindowToVram(WIN_LABEL_BOTTOM, COPYWIN_FULL);
}

static const u8 *BattleStatus_GetPlayerTrainerName(void)
{
    return gSaveBlock2Ptr->playerName;
}

static const u8 *BattleStatus_GetPrimaryOpponentTrainerName(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        return GetTrainerNameFromId(TRAINER_BATTLE_PARAM.opponentA);

    return sText_BattleStatus_Opponent;
}

static u8 BattleStatus_GetOpponentTrainerCount(void)
{
    if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
        return 0;

    if ((gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_MULTI)) && !BATTLE_TWO_VS_ONE_OPPONENT)
        return 2;

    return 1;
}

static bool8 BattleStatus_HasPlayerPartnerTrainer(void)
{
    return HasPartnerTrainer(B_BATTLER_0);
}

static void BattleStatus_OverviewUpdateHpBars(void)
{
    u8 i;

    for (i = 0; i < sBattleStatusMenu.cardCount; i++)
        BattleStatus_DrawHpBarSprite(&sBattleStatusMenu.cards[i]);
}

static void BattleStatusMenu_Destroy(void)
{
    u8 i;

    if (sBattleStatusMenu.cursorSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sBattleStatusMenu.cursorSpriteId]);
    sBattleStatusMenu.cursorSpriteId = SPRITE_NONE;

    BattleStatus_DetailDestroyWindows();
    BattleStatus_DetailDestroyHpBar();
    BattleStatus_DetailDestroyStatusIcon();
    BattleStatus_DetailDestroyTeraTypeIndicator();
    BattleStatus_DetailDestroyGimmickIndicator();
    BattleStatus_DetailDestroyTypeIcons();
    BattleStatus_DetailDestroyStatPips();
    BattleStatus_DetailDestroyEffectsScrollbar();

    if (sBattleStatusMenu.detailIconSpriteId != SPRITE_NONE)
        FreeAndDestroyMonIconSprite(&gSprites[sBattleStatusMenu.detailIconSpriteId]);
    sBattleStatusMenu.detailIconSpriteId = SPRITE_NONE;

    for (i = 0; i < sBattleStatusMenu.cardCount; i++)
    {
        struct BattleStatusCard *card = &sBattleStatusMenu.cards[i];

        if (card->hpBarSpriteId != SPRITE_NONE)
            DestroySprite(&gSprites[card->hpBarSpriteId]);
        if (card->statusSpriteId != SPRITE_NONE)
            DestroySprite(&gSprites[card->statusSpriteId]);
        if (card->updateSpriteId != SPRITE_NONE)
            DestroySprite(&gSprites[card->updateSpriteId]);
        if (card->monIconSpriteId != SPRITE_NONE)
            FreeAndDestroyMonIconSprite(&gSprites[card->monIconSpriteId]);
        if (card->gimmickSpriteId != SPRITE_NONE)
            DestroySprite(&gSprites[card->gimmickSpriteId]);

        if (card->hpBarTileTag != 0)
            FreeSpriteTilesByTag(card->hpBarTileTag);
        if (card->gimmickTileTag != 0)
            FreeSpriteTilesByTag(card->gimmickTileTag);

        card->hpBarSpriteId = SPRITE_NONE;
        card->statusSpriteId = SPRITE_NONE;
        card->updateSpriteId = SPRITE_NONE;
        card->monIconSpriteId = SPRITE_NONE;
        card->gimmickSpriteId = SPRITE_NONE;
        card->gimmickTileTag = 0;
    }

    RemoveWindow(WIN_LABEL_TOP);
    RemoveWindow(WIN_LABEL_BOTTOM);
    RemoveWindow(WIN_ROW_ENEMY);
    RemoveWindow(WIN_ROW_PLAYER);

    FreeSpritePaletteByTag(BSTATUS_HP_BAR_PAL_TAG);
    FreeSpriteTilesByTag(BSTATUS_UPDATE_ICON_TILE_TAG);
    FreeSpriteTilesByTag(BSTATUS_CURSOR_TILE_TAG);
    FreeSpriteTilesByTag(BSTATUS_DETAIL_EFFECTS_SCROLLBAR_TILE_TAG);
    FreeSpritePaletteByTag(gSpriteTemplate_MoveTypes.paletteTag);
    FreeSpritePaletteByTag(BSTATUS_MOVE_TYPES_PAL_TAG_1);
    FreeSpritePaletteByTag(BSTATUS_MOVE_TYPES_PAL_TAG_2);
    FreeSpriteTilesByTag(TAG_STATUS_ICONS);
    FreeSpritePaletteByTag(TAG_STATUS_ICONS);
    FreeMonIconPalettes();
}

static u8 BattleStatus_CreateHpBarSprite(u16 tileTag, s16 x, s16 y)
{
    struct SpriteSheet sheet =
    {
        sBattleStatusHpBarTiles, sizeof(sBattleStatusHpBarTiles), tileTag
    };
    struct SpriteTemplate template = sSpriteTemplate_BattleStatusHpBar;
    u16 tileNum;
    u8 spriteId;

    LoadSpriteSheet(&sheet);
    template.tileTag = tileTag;
    spriteId = CreateSprite(&template, x, y, 0);

    if (spriteId != SPRITE_NONE)
    {
        SetSubspriteTables(&gSprites[spriteId], sBattleStatusHpBarSubspriteTable);
        gSprites[spriteId].subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        gSprites[spriteId].invisible = TRUE;
        gSprites[spriteId].oam.priority = 0;
        tileNum = gSprites[spriteId].oam.tileNum;
        CpuCopy32(&gHealthboxElementsGfxTable[HEALTHBOX_GFX_HP_LABEL][0],
                  (void *)(OBJ_VRAM0 + tileNum * TILE_SIZE_4BPP), 64);
    }

    return spriteId;
}

static void BattleStatus_UpdateHpBarTilesWithWidth(u8 spriteId, s16 hp, s16 maxHp, u8 totalPixels, u8 segmentCount)
{
    u8 array[BSTATUS_HP_BAR_SEGMENTS];
    u8 i;
    u8 filledPixels;
    u8 barElementId;
    u16 tileNum;
    void *dst;

    if (segmentCount > BSTATUS_HP_BAR_SEGMENTS)
        segmentCount = BSTATUS_HP_BAR_SEGMENTS;

    if (maxHp <= 0)
        maxHp = 1;

    filledPixels = GetScaledHPFraction(hp, maxHp, totalPixels);
    barElementId = BattleStatus_GetBarGfxId(hp, maxHp);

    for (i = 0; i < BSTATUS_HP_BAR_SEGMENTS; i++)
        array[i] = 0;

    if (filledPixels == 0 && hp > 0)
        filledPixels = 1;

    for (i = 0; i < segmentCount; i++)
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

    tileNum = gSprites[spriteId].oam.tileNum;
    for (i = 0; i < BSTATUS_HP_BAR_SEGMENTS; i++)
    {
        if (i < 2)
            dst = (void *)(OBJ_VRAM0 + (tileNum + 2 + i) * TILE_SIZE_4BPP);
        else
            dst = (void *)(OBJ_VRAM0 + 64 + (tileNum + i) * TILE_SIZE_4BPP);

        if (i >= segmentCount)
        {
            CpuFill16(0, dst, 32);
            continue;
        }

        CpuCopy32(&gHealthboxElementsGfxTable[barElementId][array[i] * 32],
                  dst, 32);
    }
}

static void BattleStatus_UpdateHpBarTiles(u8 spriteId, s16 hp, s16 maxHp)
{
    BattleStatus_UpdateHpBarTilesWithWidth(spriteId, hp, maxHp, BSTATUS_HEALTHBAR_PIXELS, BSTATUS_HP_BAR_SEGMENTS);
}

static void BattleStatus_DrawHpBarSprite(struct BattleStatusCard *card)
{
    struct Sprite *sprite;
    s16 hp = gBattleMons[card->battlerId].hp;
    s16 maxHp = gBattleMons[card->battlerId].maxHP;

    if (card->hpBarSpriteId == SPRITE_NONE)
        return;

    sprite = &gSprites[card->hpBarSpriteId];
    sprite->x = card->x + (BSTATUS_CARD_W / 2) + BSTATUS_HP_BAR_X;
    sprite->y = card->y + BSTATUS_HP_BAR_Y;

    BattleStatus_UpdateHpBarTiles(card->hpBarSpriteId, hp, maxHp);
    sprite->invisible = FALSE;
}

static u8 BattleStatus_GetBarGfxId(s16 hp, s16 maxHp)
{
    u8 barLevel = GetHPBarLevel(hp, maxHp);

    switch (barLevel)
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

static void BattleStatus_GetNickname(enum BattlerId battler, u8 *dst)
{
    GetMonData(GetBattlerMon(battler), MON_DATA_NICKNAME, dst);
    StringGet_Nickname(dst);
}

static u8 BattleStatus_GetAilmentFromBattler(enum BattlerId battler)
{
    u32 status = gBattleMons[battler].status1;

    return GetAilmentFromStatus(status);
}

static void BattleStatus_RefreshUnreadUpdates(void)
{
    u8 battler;
    u16 turn = gBattleTurnCounter;

    // New battle/session guard: turn counter wrapped or reset.
    if (sBattleStatusSnapshotInitialized && turn < sBattleStatusSnapshotTurn)
        sBattleStatusSnapshotInitialized = FALSE;

    if (!sBattleStatusSnapshotInitialized)
    {
        for (battler = 0; battler < MAX_BATTLERS_COUNT; battler++)
        {
            if (battler < gBattlersCount)
            {
                sBattleStatusLastTurnSnapshotHash[battler] = BattleStatus_CalcBattlerUpdateHash(battler);
                sBattleStatusLastTurnSnapshotValid[battler] = TRUE;
            }
            else
            {
                sBattleStatusLastTurnSnapshotHash[battler] = 0;
                sBattleStatusLastTurnSnapshotValid[battler] = FALSE;
            }
            sBattleStatusUnreadUpdates[battler] = FALSE;
        }
        sBattleStatusSnapshotTurn = turn;
        sBattleStatusSnapshotInitialized = TRUE;
        return;
    }

    // New turn: compare against previous turn's baseline, then set new baseline.
    if (sBattleStatusSnapshotTurn != turn)
    {
        for (battler = 0; battler < MAX_BATTLERS_COUNT; battler++)
        {
            if (battler < gBattlersCount)
            {
                u32 hash = BattleStatus_CalcBattlerUpdateHash(battler);

                if (sBattleStatusLastTurnSnapshotValid[battler])
                    sBattleStatusUnreadUpdates[battler] = (hash != sBattleStatusLastTurnSnapshotHash[battler]);
                else
                    sBattleStatusUnreadUpdates[battler] = FALSE;

                sBattleStatusLastTurnSnapshotHash[battler] = hash;
                sBattleStatusLastTurnSnapshotValid[battler] = TRUE;
            }
            else
            {
                sBattleStatusUnreadUpdates[battler] = FALSE;
                sBattleStatusLastTurnSnapshotHash[battler] = 0;
                sBattleStatusLastTurnSnapshotValid[battler] = FALSE;
            }
        }

        sBattleStatusSnapshotTurn = turn;
        return;
    }

    // Same turn: detect live changes (e.g. battle debug edits) against current turn baseline.
    for (battler = 0; battler < gBattlersCount; battler++)
    {
        u32 hash = BattleStatus_CalcBattlerUpdateHash(battler);

        if (sBattleStatusLastTurnSnapshotValid[battler] && hash != sBattleStatusLastTurnSnapshotHash[battler])
            sBattleStatusUnreadUpdates[battler] = TRUE;
    }
}

static u32 BattleStatus_CalcBattlerUpdateHash(enum BattlerId battler)
{
    const struct BattlePokemon *mon = &gBattleMons[battler];
    const enum Gimmick activeGimmick = GetActiveGimmick(battler);
    const bool8 isPlayerSide = IsOnPlayerSide(battler);
    const bool8 isPrimal = IsBattlerPrimalReverted(battler);
    u64 effectsMask[(BSTATUS_EFFECT_COUNT + 63) / 64];
    u32 hash = 2166136261u;
    u8 i;

    // Opponent ability/item are hidden, so only track these on player side.
    if (isPlayerSide)
    {
        hash = BattleStatus_HashBytes(hash, &mon->ability, sizeof(mon->ability));
        hash = BattleStatus_HashBytes(hash, &mon->item, sizeof(mon->item));
    }

    // Species/form tracks gimmick changes like Mega/Primal form swaps.
    hash = BattleStatus_HashBytes(hash, &mon->species, sizeof(mon->species));
    hash = BattleStatus_HashBytes(hash, &mon->types, sizeof(mon->types));
    hash = BattleStatus_HashBytes(hash, &mon->statStages, sizeof(mon->statStages));
    hash = BattleStatus_HashBytes(hash, &activeGimmick, sizeof(activeGimmick));
    hash = BattleStatus_HashBytes(hash, &isPrimal, sizeof(isPrimal));

    if (B_FLAG_TERA_ORB_CHARGED != 0)
    {
        enum Type teraType = GetBattlerTeraType(battler);
        hash = BattleStatus_HashBytes(hash, &teraType, sizeof(teraType));
    }

    BattleStatus_GetActiveEffectsMask(battler, effectsMask);
    for (i = 0; i < ARRAY_COUNT(effectsMask); i++)
        hash = BattleStatus_HashBytes(hash, &effectsMask[i], sizeof(effectsMask[i]));

    return hash;
}

static u32 BattleStatus_HashBytes(u32 hash, const void *data, u32 size)
{
    const u8 *bytes = data;
    u32 i;

    for (i = 0; i < size; i++)
        hash = (hash * 16777619u) ^ bytes[i];

    return hash;
}

static void BattleStatus_GetActiveEffectsMask(enum BattlerId battler, u64 *mask)
{
    u8 maskWords = (BSTATUS_EFFECT_COUNT + 63) / 64;
    enum BattlerId savedBattler = sBattleStatusMenu.selectedBattlerId;
    u8 savedCount = sBattleStatusMenu.detailActiveEffectsCount;
    u8 savedEffects[BSTATUS_DETAIL_MAX_ACTIVE_EFFECTS];
    u8 i;

    for (i = 0; i < maskWords; i++)
        mask[i] = 0;

    memcpy(savedEffects, sBattleStatusMenu.detailActiveEffects, sizeof(savedEffects));

    sBattleStatusMenu.selectedBattlerId = battler;
    sBattleStatusMenu.detailActiveEffectsCount = 0;
    BattleStatus_DetailBuildActiveEffects();

    for (i = 0; i < sBattleStatusMenu.detailActiveEffectsCount; i++)
    {
        u8 effectId = sBattleStatusMenu.detailActiveEffects[i];
        if (effectId < BSTATUS_EFFECT_COUNT)
            mask[effectId / 64] |= (u64)1 << (effectId % 64);
    }

    sBattleStatusMenu.selectedBattlerId = savedBattler;
    sBattleStatusMenu.detailActiveEffectsCount = savedCount;
    memcpy(sBattleStatusMenu.detailActiveEffects, savedEffects, sizeof(savedEffects));
}

static bool8 BattleStatus_BattlerHasUnreadUpdates(enum BattlerId battler)
{
    if (battler >= MAX_BATTLERS_COUNT)
        return FALSE;

    return sBattleStatusUnreadUpdates[battler];
}

static void BattleStatus_OverviewInitCursor(void)
{
    s16 cursorX;
    s16 cursorY;

    if (sBattleStatusMenu.cardCount == 0)
        return;

    if (sBattleStatusMenu.cursorSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sBattleStatusMenu.cursorSpriteId]);
    if (sBattleStatusMenu.selectedCardIndex >= sBattleStatusMenu.cardCount)
        sBattleStatusMenu.selectedCardIndex = BattleStatus_OverviewGetDefaultIndex();

    BattleStatus_OverviewSyncSelectedBattler();

    cursorX = sBattleStatusMenu.cards[sBattleStatusMenu.selectedCardIndex].x - 8;
    cursorY = sBattleStatusMenu.cards[sBattleStatusMenu.selectedCardIndex].y + (BSTATUS_CARD_H / 2);
    sBattleStatusMenu.cursorSpriteId = CreateSprite(&sSpriteTemplate_BattleStatusCursor, cursorX, cursorY, 0);
    if (sBattleStatusMenu.cursorSpriteId != SPRITE_NONE)
        gSprites[sBattleStatusMenu.cursorSpriteId].oam.priority = 0;
}

static void BattleStatus_OverviewUpdateCursorPos(void)
{
    struct BattleStatusCard *card;

    if (sBattleStatusMenu.cursorSpriteId == SPRITE_NONE)
        return;
    if (sBattleStatusMenu.selectedCardIndex >= sBattleStatusMenu.cardCount)
        return;

    card = &sBattleStatusMenu.cards[sBattleStatusMenu.selectedCardIndex];
    gSprites[sBattleStatusMenu.cursorSpriteId].x = card->x - 8;
    gSprites[sBattleStatusMenu.cursorSpriteId].y = card->y + (BSTATUS_CARD_H / 2);
}

static void BattleStatus_OverviewHandleInput(void)
{
    bool8 moved = FALSE;

    if (JOY_NEW(DPAD_LEFT))
        moved = BattleStatus_OverviewTryMoveCursor(-1, 0);
    else if (JOY_NEW(DPAD_RIGHT))
        moved = BattleStatus_OverviewTryMoveCursor(1, 0);
    else if (JOY_NEW(DPAD_UP))
        moved = BattleStatus_OverviewTryMoveCursor(0, -1);
    else if (JOY_NEW(DPAD_DOWN))
        moved = BattleStatus_OverviewTryMoveCursor(0, 1);

    if (moved)
    {
        BattleStatus_OverviewUpdateCursorPos();
        BattleStatus_OverviewSyncSelectedBattler();
    }

    if (JOY_NEW(A_BUTTON) && sBattleStatusMenu.cardCount != 0)
    {
        PlaySE(SE_SELECT);
        BattleStatus_OverviewSyncSelectedBattler();
        BattleStatus_OverviewExit();
        BattleStatus_DetailEnter();
    }
}

static bool8 BattleStatus_OverviewTryMoveCursor(s8 dx, s8 dy)
{
    u8 i;
    u8 bestIndex = sBattleStatusMenu.selectedCardIndex;
    s16 bestMetric = 0x7FFF;
    s16 currX;
    s16 currY;
    s16 targetRowY;

    if (sBattleStatusMenu.cardCount == 0)
        return FALSE;

    currX = sBattleStatusMenu.cards[sBattleStatusMenu.selectedCardIndex].x;
    currY = sBattleStatusMenu.cards[sBattleStatusMenu.selectedCardIndex].y;

    if (dx != 0)
    {
        for (i = 0; i < sBattleStatusMenu.cardCount; i++)
        {
            const struct BattleStatusCard *card = &sBattleStatusMenu.cards[i];
            s16 diff = card->x - currX;

            if (card->y != currY)
                continue;
            if ((dx < 0 && diff >= 0) || (dx > 0 && diff <= 0))
                continue;

            diff = abs(diff);
            if (diff < bestMetric)
            {
                bestMetric = diff;
                bestIndex = i;
            }
        }
    }
    else if (dy != 0)
    {
        targetRowY = (currY == BSTATUS_ROW_Y_ENEMY) ? BSTATUS_ROW_Y_PLAYER : BSTATUS_ROW_Y_ENEMY;

        for (i = 0; i < sBattleStatusMenu.cardCount; i++)
        {
            const struct BattleStatusCard *card = &sBattleStatusMenu.cards[i];
            s16 diff;

            if (card->y != targetRowY)
                continue;

            diff = abs(card->x - currX);
            if (diff < bestMetric)
            {
                bestMetric = diff;
                bestIndex = i;
            }
        }
    }

    if (bestIndex != sBattleStatusMenu.selectedCardIndex)
    {
        sBattleStatusMenu.selectedCardIndex = bestIndex;
        return TRUE;
    }

    return FALSE;
}

static void BattleStatus_OverviewCreateWindows(void)
{
    InitWindows(sBattleStatusMenuWindowTemplates);
    BattleStatus_OverviewClearWindows();
}
