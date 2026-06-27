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
    BATTLE_STATUS_PAGE_NONE = 0xFF,
};

enum
{
    B_STATUS_TEXT_COLOR_TRANSPARENT,
    B_STATUS_TEXT_COLOR_BLACK,
    B_STATUS_TEXT_COLOR_DARK_GRAY,
    B_STATUS_TEXT_COLOR_LIGHT_GRAY,
    B_STATUS_TEXT_COLOR_WHITE,
    B_STATUS_TEXT_COLOR_LIGHT_BLUE,
    B_STATUS_TEXT_COLOR_BLUE,
    B_STATUS_TEXT_COLOR_PINK,
    B_STATUS_TEXT_COLOR_DARK_PINK,
    B_STATUS_TEXT_COLOR_GREEN,
    B_STATUS_TEXT_COLOR_LIGHT_GREEN,
    B_STATUS_TEXT_COLOR_RED,
    B_STATUS_TEXT_COLOR_LIGHT_RED,
};

#define B_STATUS_TEXT_PAL                15
#define B_STATUS_TEXT_BG                 0
#define B_STATUS_BACKDROP_BG             1
#define B_STATUS_TILEMAP_WIDTH           32
#define B_STATUS_TILEMAP_HEIGHT          32

#define B_STATUS_BG_TILE_FILL            0x01
#define B_STATUS_BG_TILE_HEADER_CORNER   0x02
#define B_STATUS_BG_TILE_HEADER_SIDE     0x03
#define B_STATUS_BG_TILE_HEADER_TOP      0x04
#define B_STATUS_BG_TILE_HEADER_FILL     0x05
#define B_STATUS_BG_TILE_CARD_INACTIVE_TL 0x06
#define B_STATUS_BG_TILE_CARD_INACTIVE_TE 0x07
#define B_STATUS_BG_TILE_CARD_INACTIVE_SE 0x08
#define B_STATUS_BG_TILE_CARD_INACTIVE_IN 0x09
#define B_STATUS_BG_TILE_CARD_INACTIVE_BL 0x0A
#define B_STATUS_BG_TILE_CARD_INACTIVE_BE 0x0B
#define B_STATUS_BG_TILE_CARD_ACTIVE_TL  0x0C
#define B_STATUS_BG_TILE_CARD_ACTIVE_TE  0x0D
#define B_STATUS_BG_TILE_CARD_ACTIVE_SE  0x0E
#define B_STATUS_BG_TILE_CARD_ACTIVE_IN  0x0F
#define B_STATUS_BG_TILE_CARD_ACTIVE_BL  0x10
#define B_STATUS_BG_TILE_CARD_ACTIVE_BE  0x11
#define B_STATUS_BG_TILE_SCROLLBAR_LANE  0x18
#define B_STATUS_BG_TILE_SCROLLBAR_TOP   0x19
#define B_STATUS_BG_TILE_SCROLLBAR_BOTTOM 0x1A

#define B_STATUS_BG_ATTR_HFLIP           BG_TILE_H_FLIP(0)
#define B_STATUS_BG_ATTR_VFLIP           BG_TILE_V_FLIP(0)

#define B_STATUS_CARD_TILE_W             8
#define B_STATUS_CARD_TILE_H             7
#define B_STATUS_CARD_W                  (B_STATUS_CARD_TILE_W * 8)
#define B_STATUS_CARD_H                  (B_STATUS_CARD_TILE_H * 8)

#define B_STATUS_ROW_Y_ENEMY             24
#define B_STATUS_ROW_Y_PLAYER            80

#define B_STATUS_SAFE_LEFT_TILE          1
#define B_STATUS_SAFE_RIGHT_TILE         30

#define B_STATUS_LABEL_TILE_H            3
#define B_STATUS_LABEL_H                 (B_STATUS_LABEL_TILE_H * 8)
#define B_STATUS_LABEL_BOTTOM_TILE_TOP   ((DISPLAY_HEIGHT / 8) - B_STATUS_LABEL_TILE_H)

#define B_STATUS_WIN_LABEL_TOP_BASE      1
#define B_STATUS_WIN_LABEL_BOTTOM_BASE   (B_STATUS_WIN_LABEL_TOP_BASE + (32 * B_STATUS_LABEL_TILE_H))
#define B_STATUS_WIN_ROW_ENEMY_BASE      (B_STATUS_WIN_LABEL_BOTTOM_BASE + (32 * B_STATUS_LABEL_TILE_H))
#define B_STATUS_WIN_ROW_PLAYER_BASE     (B_STATUS_WIN_ROW_ENEMY_BASE + (32 * B_STATUS_CARD_TILE_H))
#define B_STATUS_DETAIL_HEADER_WIN_W     15
#define B_STATUS_DETAIL_HEADER_WIN_H     12
#define B_STATUS_DETAIL_ITEM_WIN_W       9
#define B_STATUS_DETAIL_ITEM_WIN_H       8
#define B_STATUS_DETAIL_STATS_WIN_W      6
#define B_STATUS_DETAIL_STATS_WIN_H      11
#define B_STATUS_DETAIL_EFFECTS_WIN_W    13
#define B_STATUS_DETAIL_EFFECTS_WIN_H    12
#define B_STATUS_DETAIL_DESC_WIN_W       13
#define B_STATUS_DETAIL_DESC_WIN_H       8
#define B_STATUS_WIN_DETAIL_HEADER_BASE  1
#define B_STATUS_WIN_DETAIL_ITEM_BASE    (B_STATUS_WIN_DETAIL_HEADER_BASE + (B_STATUS_DETAIL_HEADER_WIN_W * B_STATUS_DETAIL_HEADER_WIN_H))
#define B_STATUS_WIN_DETAIL_STATS_BASE   (B_STATUS_WIN_DETAIL_ITEM_BASE + (B_STATUS_DETAIL_ITEM_WIN_W * B_STATUS_DETAIL_ITEM_WIN_H))
#define B_STATUS_WIN_DETAIL_EFFECTS_BASE (B_STATUS_WIN_DETAIL_STATS_BASE + (B_STATUS_DETAIL_STATS_WIN_W * B_STATUS_DETAIL_STATS_WIN_H))
#define B_STATUS_WIN_DETAIL_DESC_BASE    (B_STATUS_WIN_DETAIL_EFFECTS_BASE + (B_STATUS_DETAIL_EFFECTS_WIN_W * B_STATUS_DETAIL_EFFECTS_WIN_H))

#define B_STATUS_GENDER_W                8

#define B_STATUS_HP_BAR_TILE_TAG_BASE    0xD7C0
#define B_STATUS_HP_BAR_PAL_TAG          0xD7C4
#define B_STATUS_HP_BAR_ENDCAP_LEFT_TILE_TAG 0xD7C5
#define B_STATUS_HP_BAR_ENDCAP_RIGHT_TILE_TAG 0xD7C6
#define B_STATUS_HP_BAR_ENDCAP_PAL_TAG        0xD7C7
#define B_STATUS_HEALTHBAR_PIXELS        48
#define B_STATUS_DETAIL_HEALTHBAR_PIXELS 40
#define B_STATUS_HP_BAR_SEGMENTS         6
#define B_STATUS_DETAIL_HP_BAR_SEGMENTS  5

#define B_STATUS_UPDATE_ICON_TILE_TAG    0xD7D0

#define B_STATUS_CURSOR_TILE_TAG         0xD7E0
#define B_STATUS_DETAIL_GIMMICK_TILE_TAG 0xD7E2
#define B_STATUS_DETAIL_HP_BAR_TILE_TAG  0xD7E3
#define B_STATUS_DETAIL_TERA_TYPE_TILE_TAG 0xD7F0
#define B_STATUS_OVERVIEW_GIMMICK_TILE_TAG_BASE 0xD7E4
#define B_STATUS_DETAIL_STAT_PIP_DOT_TILE_TAG 0xD7E8
#define B_STATUS_DETAIL_STAT_PIP_UP_TILE_TAG  0xD7E9
#define B_STATUS_DETAIL_STAT_PIP_DOWN_TILE_TAG 0xD7EA
#define B_STATUS_DETAIL_STAT_PIP_PAL_TAG      0xD7EF
#define B_STATUS_DETAIL_STAT_PIP_PAL_NUM      12
#define B_STATUS_DETAIL_EFFECTS_SCROLLBAR_TILE_TAG 0xD7EB
#define B_STATUS_MOVE_TYPES_PAL_TAG_1       0xD7ED
#define B_STATUS_MOVE_TYPES_PAL_TAG_2       0xD7EE

#define B_STATUS_DEBUG_UPDATE_REASON_LOG FALSE
#define B_STATUS_TRACKED_SIDE_STATUS_BITS (SIDE_STATUS_MIST          \
                                        | SIDE_STATUS_SAFEGUARD     \
                                        | SIDE_STATUS_LUCKY_CHANT   \
                                        | SIDE_STATUS_TAILWIND      \
                                        | SIDE_STATUS_LIGHTSCREEN   \
                                        | SIDE_STATUS_REFLECT       \
                                        | SIDE_STATUS_AURORA_VEIL   \
                                        | SIDE_STATUS_RAINBOW       \
                                        | SIDE_STATUS_SWAMP         \
                                        | SIDE_STATUS_SEA_OF_FIRE   \
                                        | SIDE_STATUS_DAMAGE_NON_TYPES)

#define B_STATUS_DETAIL_WINDOW_COUNT     5
#define B_STATUS_DETAIL_GIMMICK_W        8
#define B_STATUS_DETAIL_GIMMICK_H        16
#define B_STATUS_DETAIL_GIMMICK_GFX_SIZE ((B_STATUS_DETAIL_GIMMICK_W * B_STATUS_DETAIL_GIMMICK_H) / 2)
#define B_STATUS_DETAIL_STAT_ROW_COUNT   7
#define B_STATUS_DETAIL_STAT_PIPS_PER_ROW 6
#define B_STATUS_DETAIL_MAX_ACTIVE_EFFECTS 64
#define B_STATUS_DETAIL_EFFECTS_VISIBLE_ROWS 6

#define B_STATUS_EFFECT_FLAG_HAS_DURATION    (1 << 0)
#define B_STATUS_EFFECT_FLAG_EXTENDABLE      (1 << 1)
#define B_STATUS_EFFECT_FLAG_EXTENDER_KNOWN  (1 << 2)
#define B_STATUS_EFFECT_FLAG_TOTAL_KNOWN     (1 << 3)

struct BattleStatusEffectEntry
{
    u8 effectId;
    u16 durationRemaining;
    u16 baseTotalDuration;
    u16 extendedTotalDuration;
    u8 setterSide;
    u8 flags;
    u8 stackCount;
};

#define B_STATUS_DETAIL_TEXT_BUFFER_SIZE 512

#define TAG_STATUS_ICONS                1202

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
    u8 hpBarLeftEndcapSpriteId;
    u8 hpBarRightEndcapSpriteId;
};

struct BattleStatusMenuState
{
    u8 page;
    u8 selectedCardIndex;
    u8 cursorSpriteId;
    u8 detailIconSpriteId;
    u8 detailHpBarSpriteId;
    u8 detailHpBarLeftEndcapSpriteId;
    u8 detailHpBarRightEndcapSpriteId;
    u8 detailStatusSpriteId;
    u8 detailTeraTypeSpriteId;
    u8 detailGimmickSpriteId;
    u8 detailTypeIconSpriteIds[2];
    u8 detailStatPipSpriteIds[B_STATUS_DETAIL_STAT_ROW_COUNT][B_STATUS_DETAIL_STAT_PIPS_PER_ROW];
    u8 enemyLabelText[TRAINER_NAME_LENGTH + 1];
    u8 playerLabelText[TRAINER_NAME_LENGTH + 1];
    struct BattleStatusCard cards[MAX_BATTLERS_COUNT];
    s16 enemyRowLeft;
    s16 enemyRowRight;
    s16 enemyRowCenter;
    s16 playerRowLeft;
    s16 playerRowRight;
    s16 playerRowCenter;
    struct BattleStatusEffectEntry detailActiveEffects[B_STATUS_DETAIL_MAX_ACTIVE_EFFECTS];
    u8 detailActiveEffectsCount;
    u8 detailEffectsCursor;
    u8 detailEffectsScrollbarSpriteId;
    u16 detailEffectsScroll;
    u8 detailWindowIds[B_STATUS_DETAIL_WINDOW_COUNT];
};

enum BattleStatusUpdateReason
{
    B_STATUS_UPDATE_REASON_NONE                  = 0,
    B_STATUS_UPDATE_REASON_STATUS                = (1 << 0),
    B_STATUS_UPDATE_REASON_VOLATILE_GAIN         = (1 << 1),
    B_STATUS_UPDATE_REASON_VOLATILE_STACK_RAISE  = (1 << 2),
    B_STATUS_UPDATE_REASON_HAZARD_GAIN           = (1 << 3),
    B_STATUS_UPDATE_REASON_HAZARD_LAYER_RAISE    = (1 << 4),
    B_STATUS_UPDATE_REASON_SIDE_STATUS_GAIN      = (1 << 5),
    B_STATUS_UPDATE_REASON_FORM_CHANGE           = (1 << 6),
    B_STATUS_UPDATE_REASON_TYPE_CHANGE           = (1 << 7),
    B_STATUS_UPDATE_REASON_GIMMICK_ACTIVATED     = (1 << 8),
    B_STATUS_UPDATE_REASON_ALLY_ITEM             = (1 << 9),
    B_STATUS_UPDATE_REASON_ALLY_ABILITY          = (1 << 10),
    B_STATUS_UPDATE_REASON_STAT_STAGE            = (1 << 11),
    B_STATUS_UPDATE_REASON_GIMMICK_MEGA          = (1 << 12),
    B_STATUS_UPDATE_REASON_GIMMICK_DYNAMAX       = (1 << 13),
    B_STATUS_UPDATE_REASON_GIMMICK_TERA          = (1 << 14),
};

enum BattleStatusTrackedVolatile
{
    B_STATUS_TRACKED_VOLATILE_CRIT_BOOST,
    B_STATUS_TRACKED_VOLATILE_CONFUSION,
    B_STATUS_TRACKED_VOLATILE_INFATUATION,
    B_STATUS_TRACKED_VOLATILE_NIGHTMARE,
    B_STATUS_TRACKED_VOLATILE_DROWSY,
    B_STATUS_TRACKED_VOLATILE_ENCORE,
    B_STATUS_TRACKED_VOLATILE_TORMENT,
    B_STATUS_TRACKED_VOLATILE_GRUDGE,
    B_STATUS_TRACKED_VOLATILE_HEAL_BLOCK,
    B_STATUS_TRACKED_VOLATILE_IDENTIFIED,
    B_STATUS_TRACKED_VOLATILE_CANT_ESCAPE,
    B_STATUS_TRACKED_VOLATILE_LOCK_ON,
    B_STATUS_TRACKED_VOLATILE_EMBARGO,
    B_STATUS_TRACKED_VOLATILE_CHARGE,
    B_STATUS_TRACKED_VOLATILE_TAUNT,
    B_STATUS_TRACKED_VOLATILE_TELEKINESIS,
    B_STATUS_TRACKED_VOLATILE_MAGNET_RISE,
    B_STATUS_TRACKED_VOLATILE_WISH,
    B_STATUS_TRACKED_VOLATILE_INGRAIN,
    B_STATUS_TRACKED_VOLATILE_CURSE,
    B_STATUS_TRACKED_VOLATILE_DESTINY_BOND,
    B_STATUS_TRACKED_VOLATILE_BOUND,
    B_STATUS_TRACKED_VOLATILE_BIDE,
    B_STATUS_TRACKED_VOLATILE_FUTURE_ATTACK,
    B_STATUS_TRACKED_VOLATILE_UPROAR,
    B_STATUS_TRACKED_VOLATILE_AQUA_RING,
    B_STATUS_TRACKED_VOLATILE_AUTOTOMIZE,
    B_STATUS_TRACKED_VOLATILE_SMACK_DOWN,
    B_STATUS_TRACKED_VOLATILE_THROAT_CHOP,
    B_STATUS_TRACKED_VOLATILE_LASER_FOCUS,
    B_STATUS_TRACKED_VOLATILE_TAR_SHOT,
    B_STATUS_TRACKED_VOLATILE_OCTOLOCK,
    B_STATUS_TRACKED_VOLATILE_FIXATED,
    B_STATUS_TRACKED_VOLATILE_STANCE_SWAP,
    B_STATUS_TRACKED_VOLATILE_SLOW_START,
    B_STATUS_TRACKED_VOLATILE_SALT_CURE,
    B_STATUS_TRACKED_VOLATILE_SYRUPY,
    B_STATUS_TRACKED_VOLATILE_RAMPAGING,
    B_STATUS_TRACKED_VOLATILE_COUNT,
};

struct BattleStatusSnapshot
{
    u8 majorStatus;
    u64 volatileMask;
    u8 critBoostLevel;
    u8 autotomizeCount;
    u8 statStages[NUM_BATTLE_STATS];
    u16 species;
    u8 type1;
    u8 type2;
    u8 activeGimmick;
    bool8 isPrimal;
    bool8 isMega;
    bool8 isDynamaxed;
    u8 dynamaxTurns;
    bool8 isTera;
    u8 teraType;
    u32 sideStatusBits;
    u8 spikesLayers;
    u8 toxicSpikesLayers;
    bool8 stealthRock;
    bool8 stickyWeb;
    bool8 allyItemKnown;
    u16 allyItem;
    bool8 allyAbilityKnown;
    u16 allyAbility;
};

enum BattleStatusEffectId
{
    B_STATUS_EFFECT_HARSH_SUNLIGHT,
    B_STATUS_EFFECT_RAIN,
    B_STATUS_EFFECT_SANDSTORM,
    B_STATUS_EFFECT_SNOW,
    B_STATUS_EFFECT_ELECTRIC_TERRAIN,
    B_STATUS_EFFECT_GRASSY_TERRAIN,
    B_STATUS_EFFECT_MISTY_TERRAIN,
    B_STATUS_EFFECT_PSYCHIC_TERRAIN,
    B_STATUS_EFFECT_TRICK_ROOM,
    B_STATUS_EFFECT_MAGIC_ROOM,
    B_STATUS_EFFECT_WONDER_ROOM,
    B_STATUS_EFFECT_GRAVITY,
    B_STATUS_EFFECT_MIST,
    B_STATUS_EFFECT_SAFEGUARD,
    B_STATUS_EFFECT_LUCKY_CHANT,
    B_STATUS_EFFECT_TAILWIND,
    B_STATUS_EFFECT_CRITICAL_HIT_BOOST,
    B_STATUS_EFFECT_CONFUSION,
    B_STATUS_EFFECT_INFATUATION,
    B_STATUS_EFFECT_NIGHTMARE,
    B_STATUS_EFFECT_DROWSY,
    B_STATUS_EFFECT_ENCORE,
    B_STATUS_EFFECT_TORMENT,
    B_STATUS_EFFECT_GRUDGE,
    B_STATUS_EFFECT_HEALING_PREVENTED,
    B_STATUS_EFFECT_IDENTIFIED,
    B_STATUS_EFFECT_MOVE_DISABLED,
    B_STATUS_EFFECT_CANT_ESCAPE,
    B_STATUS_EFFECT_LOCK_ON,
    B_STATUS_EFFECT_EMBARGO,
    B_STATUS_EFFECT_CHARGE,
    B_STATUS_EFFECT_TAUNT,
    B_STATUS_EFFECT_TELEKINESIS,
    B_STATUS_EFFECT_MAGNET_RISE,
    B_STATUS_EFFECT_WISH,
    B_STATUS_EFFECT_INGRAIN,
    B_STATUS_EFFECT_CURSE,
    B_STATUS_EFFECT_DESTINY_BOND,
    B_STATUS_EFFECT_BOUND,
    B_STATUS_EFFECT_BIDE,
    B_STATUS_EFFECT_FUTURE_ATTACK,
    B_STATUS_EFFECT_UPROAR,
    B_STATUS_EFFECT_AQUA_RING,
    B_STATUS_EFFECT_AUTOTOMIZE,
    B_STATUS_EFFECT_SMACK_DOWN,
    B_STATUS_EFFECT_FAIRY_LOCK,
    B_STATUS_EFFECT_RAINBOW,
    B_STATUS_EFFECT_SWAMP,
    B_STATUS_EFFECT_SEA_OF_FIRE,
    B_STATUS_EFFECT_THROAT_CHOP,
    B_STATUS_EFFECT_LASER_FOCUS,
    B_STATUS_EFFECT_TAR_SHOT,
    B_STATUS_EFFECT_OCTOLOCK,
    B_STATUS_EFFECT_FIXATED,
    B_STATUS_EFFECT_SPLINTERS,
    B_STATUS_EFFECT_OBSCURED,
    B_STATUS_EFFECT_PRIMED,
    B_STATUS_EFFECT_STANCE_SWAP,
    B_STATUS_EFFECT_SLOW_START,
    B_STATUS_EFFECT_SALT_CURE,
    B_STATUS_EFFECT_SYRUPY,
    B_STATUS_EFFECT_GOING_ALL_OUT,
    B_STATUS_EFFECT_HANGING_TOUGH,
    B_STATUS_EFFECT_POISONED,
    B_STATUS_EFFECT_BADLY_POISONED,
    B_STATUS_EFFECT_PARALYZED,
    B_STATUS_EFFECT_BURNED,
    B_STATUS_EFFECT_FROSTBITE,
    B_STATUS_EFFECT_STEALTH_ROCK,
    B_STATUS_EFFECT_SPIKES,
    B_STATUS_EFFECT_TOXIC_SPIKES,
    B_STATUS_EFFECT_STICKY_WEB,
    B_STATUS_EFFECT_LIGHT_SCREEN,
    B_STATUS_EFFECT_REFLECT,
    B_STATUS_EFFECT_AURORA_VEIL,
    B_STATUS_EFFECT_MUD_SPORT,
    B_STATUS_EFFECT_WATER_SPORT,
    B_STATUS_EFFECT_FORESTS_CURSE,
    B_STATUS_EFFECT_TRICK_OR_TREAT,
    B_STATUS_EFFECT_POWER_BOOST,
    B_STATUS_EFFECT_POWER_DROP,
    B_STATUS_EFFECT_GUARD_BOOST,
    B_STATUS_EFFECT_GUARD_DROP,
    B_STATUS_EFFECT_FOG,
    B_STATUS_EFFECT_EXTREMELY_HARSH_SUNLIGHT,
    B_STATUS_EFFECT_HEAVY_RAIN,
    B_STATUS_EFFECT_STRONG_WINDS,
    B_STATUS_EFFECT_OUTRAGE,
    B_STATUS_EFFECT_RAMPAGING,
    B_STATUS_EFFECT_PETAL_DANCE,
    B_STATUS_EFFECT_RAGING_FURY,
    B_STATUS_EFFECT_G_MAX_WILDFIRE,
    B_STATUS_EFFECT_G_MAX_VOLCALITH,
    B_STATUS_EFFECT_G_MAX_VINE_LASH,
    B_STATUS_EFFECT_G_MAX_CANNONADE,
    B_STATUS_EFFECT_WILD_MIGHT,
    B_STATUS_EFFECT_TERRIBLE_MIGHT,
    B_STATUS_EFFECT_TERRIFIC_MIGHT,
    B_STATUS_EFFECT_FRENZIED_MIGHT,
    B_STATUS_EFFECT_COUNT
};

struct BattleStatusEffectData
{
    const u8 *name;
    const u8 *description;
};

static void GoToBattleStatusMenu(void);
static void BattleStatusMenu_VBlankCB(void);
static void BattleStatusMenu_MainCB(void);
static void BattleStatusMenu_Init(void);
static void OverviewEnter(void);
static void OverviewExit(void);
static void OverviewBufferLabelText(void);
static void OverviewComputeRowLayout(u8 count, s16 *outXs, s16 *outRowLeft, s16 *outRowRight, s16 *outRowCenter);
static void OverviewCreateCards(void);
static void OverviewDrawCards(void);
static void OverviewDrawCard(struct BattleStatusCard *card);
static u8 GetBestFitNameFont(const u8 *name, s16 maxWidth);
static void OverviewSetBgTile(u16 *tilemap, s16 x, s16 y, u16 tileNum, u16 attrs);
static void OverviewFillBgRect(u16 *tilemap, s16 x, s16 y, s16 width, s16 height, u16 tileNum, u16 attrs);
static void BackdropLoadBaseTilemap(const u16 *baseTilemap);
static void LoadBackdropAssets(void);
static void OverviewComputeHeaderLayout(s16 rowCenter, s16 labelWidth, u8 *outTextLenTiles, s16 *outHeaderX, s16 *outHeaderWidth);
static void OverviewDrawStatusCard(u16 *tilemap, s16 x, s16 y, u8 width, u8 height, bool8 isActive, bool8 isBottomRow);
static void OverviewDrawHeaderBox(u16 *tilemap, s16 x, s16 y, u8 textLenTiles);
static void DetailDrawEntryBoxes(void);
static void OverviewDrawBackground(void);
static void OverviewDrawCardBackground(const struct BattleStatusCard *card, bool8 isActive);
static void OverviewUpdateCardSelectionHighlight(u8 oldSelectedIndex);
static void OverviewDrawLabels(void);
static void OverviewCreateWindows(void);
static void OverviewClearWindows(void);
static void OverviewInitCursor(void);
static void OverviewUpdateCursorPos(void);
static void OverviewGetCursorPos(const struct BattleStatusCard *card, s16 *outX, s16 *outY);
static void OverviewHandleInput(void);
static void RequestPageTransition(u8 targetPage);
static void ProcessPageTransition(void);
static bool8 OverviewTryMoveCursor(s8 dx, s8 dy);
static void DetailEnter(void);
static void DetailExit(void);
static void DetailHandleInput(void);
static void DetailCreateWindows(void);
static void DetailDestroyWindows(void);
static void DetailDrawStaticWindows(void);
static u8 DetailGetBestFitSmallFont(const u8 *text, s16 maxWidth);
static const u8 *GetGimmickIndicatorData(enum BattlerId battler, u32 *palTag);
static void DetailDestroyHpBar(void);
static void DetailRefreshHpBar(void);
static void DetailDestroyStatusIcon(void);
static void DetailRefreshStatusIcon(void);
static void DetailDrawLRButtonGlyphs(void);
static void DetailDestroyGimmickIndicator(void);
static void DetailRefreshGimmickIndicator(void);
static void DetailDestroyTeraTypeIndicator(void);
static void DetailRefreshTeraTypeIndicator(void);
static void DetailRefreshItemAbilityWindow(void);
static void DetailRefreshHeader(void);
static void DetailRefreshIcon(void);
static void DetailRefreshTypeIcons(void);
static void DetailDestroyTypeIcons(void);
static void DetailCreateStatPips(void);
static void DetailDestroyStatPips(void);
static void DetailRefreshStatPips(void);
static s16 DetailGetStatRowTextY(u8 row);
static void DetailSetStatPipSpriteGraphic(u8 spriteId, u16 tileTag);
static void DetailCycleBattler(s8 direction);
static void DetailInitEffectsList(void);
static void DetailBuildActiveEffects(void);
static void DetailBuildActiveEffectsForBattler(enum BattlerId battler, struct BattleStatusEffectEntry *entries, u8 *count);
static void DetailTryAddActiveEffect(enum BattlerId battler, enum BattleSide side, enum BattleStatusEffectId effectId,
                                                  struct BattleStatusEffectEntry *entries, u8 *count);
static void DetailInitEffectEntry(struct BattleStatusEffectEntry *entry, enum BattleStatusEffectId effectId, enum BattleSide side);
static void DetailSetDuration(struct BattleStatusEffectEntry *entry, u16 remaining, u16 baseTotal, u16 extendedTotal,
                                           enum BattleSide setterSide, bool8 isExtendable);
static void DetailSetDurationUnknownTotal(struct BattleStatusEffectEntry *entry, u16 remaining, u16 baseTotal, u16 extendedTotal,
                                                       enum BattleSide setterSide, bool8 isExtendable);
static bool8 DetailGetDisplayedDuration(const struct BattleStatusEffectEntry *entry, enum BattleSide viewerSide,
                                                     u16 *outRemaining, u16 *outTotal);
static void DetailBuildTurnFractionText(u8 *dst, u16 remaining, u16 total);
static void DetailCopyTextToFit(u8 *dst, const u8 *src, u8 fontId, s16 maxWidth);
static const struct BattleStatusEffectData *GetEffectData(enum BattleStatusEffectId effectId);
static bool8 DetailTryMoveEffectCursor(s8 direction);
static void DetailRefreshEffectsWindow(void);
static void DetailRefreshDescriptionWindow(void);
static void DetailRefreshEffectsSection(void);
static void DetailRefreshEffectsScrollbar(void);
static void DetailDestroyEffectsCursor(void);
static void DetailDestroyEffectsScrollbar(void);
static void DetailUpdateEffectsCursor(void);
static void DetailUpdateScrollbarLane(bool8 hasScrollbar);
static void DetailSetDescriptionPlaceholder(enum BattleStatusEffectId effectId);
static void DetailFormatDescriptionText(enum BattleStatusEffectId effectId, u8 *dst);
static void DetailClampTextLines(u8 *text, u8 maxLines);
static void DetailDrawWindowFrame(u8 windowId);
static const u8 *GetPlayerTrainerName(void);
static const u8 *GetPrimaryOpponentTrainerName(void);
static u8 GetOpponentTrainerCount(void);
static bool8 HasPlayerPartnerTrainer(void);
static void OverviewUpdateHpBars(void);
static void BattleStatusMenu_Destroy(void);
static void DestroyOverviewCardSprites(struct BattleStatusCard *card, bool8 freeHpBarTile);

static u8 CreateHpBarSprite(u16 tileTag, s16 x, s16 y);
static void DestroyHpBarEndcaps(u8 *leftEndcapSpriteId, u8 *rightEndcapSpriteId);
static void CreateHpBarEndcaps(u8 *leftEndcapSpriteId, u8 *rightEndcapSpriteId);
static void UpdateHpBarEndcaps(u8 leftEndcapSpriteId, u8 rightEndcapSpriteId, s16 barCenterX, s16 barY, u8 segmentCount);
static void UpdateHpBarTilesWithWidth(u8 spriteId, s16 hp, s16 maxHp, u8 totalPixels, u8 segmentCount);
static void UpdateHpBarTiles(u8 spriteId, s16 hp, s16 maxHp);
static void DrawHpBarSprite(struct BattleStatusCard *card);
static u8 GetBarGfxId(s16 hp, s16 maxHp);
static u8 GetAilmentFromBattler(enum BattlerId battler);
static void RefreshUnreadUpdates(void);
static void PrimeSnapshotsFromCurrentState(void);
static u64 GetTrackedVolatileMask(enum BattlerId battler);
static void BuildSnapshotForBattler(enum BattlerId battler, struct BattleStatusSnapshot *snapshot);
static u16 GetUpdateReasons(enum BattlerId battler, const struct BattleStatusSnapshot *previous, const struct BattleStatusSnapshot *current);
static void LogUpdateReasons(enum BattlerId battler, u16 reasons);
static void ClearUnreadUpdatesForNewTurn(void);
static void SnapshotResetEntry(u8 battler);
static void SnapshotStoreEntry(u8 battler, u32 identity, const struct BattleStatusSnapshot *snapshot);
static enum BattlerId GetSelectedBattler(void);
static enum BattlerId GetBattlerFromEnemySlot(u32 slot);
static enum BattlerId GetBattlerFromPlayerSlot(u32 slot);

struct BattleStatusMenuData
{
    u8 menuState;
    struct BattleStatusMenuState menu;
    u16 bg0Tilemap[BG_SCREEN_SIZE];
    u16 bg1Tilemap[BG_SCREEN_SIZE];
    u8 detailTextBuffer[B_STATUS_DETAIL_TEXT_BUFFER_SIZE];
    u16 snapshotTurn;
    bool8 snapshotInitialized;
    struct BattleStatusSnapshot lastSnapshot[MAX_BATTLERS_COUNT];
    bool8 lastSnapshotValid[MAX_BATTLERS_COUNT];
    u32 lastMonIdentity[MAX_BATTLERS_COUNT];
    bool8 lastMonIdentityValid[MAX_BATTLERS_COUNT];
    bool8 unreadUpdates[MAX_BATTLERS_COUNT];
    u16 updateReasons[MAX_BATTLERS_COUNT];
    u16 updateLatchedTurn[MAX_BATTLERS_COUNT];
    bool8 justSwitchedIn[MAX_BATTLERS_COUNT];
    u8 pendingPage;
    bool8 transitionUnloaded;
};

static EWRAM_DATA struct BattleStatusMenuData *sData = NULL;

static const u8 sTextColor_BattleStatus_Default[] =
{
    B_STATUS_TEXT_COLOR_TRANSPARENT,
    B_STATUS_TEXT_COLOR_WHITE,
    B_STATUS_TEXT_COLOR_DARK_GRAY
};

static const u8 sTextColor_BattleStatus_OverviewDefault[] =
{
    B_STATUS_TEXT_COLOR_TRANSPARENT,
    B_STATUS_TEXT_COLOR_BLACK,
    B_STATUS_TEXT_COLOR_WHITE
};


static const u8 sTextColor_BattleStatus_Male[] =
{
    B_STATUS_TEXT_COLOR_TRANSPARENT,
    B_STATUS_TEXT_COLOR_BLUE,
    B_STATUS_TEXT_COLOR_LIGHT_BLUE
};

static const u8 sTextColor_BattleStatus_Female[] =
{
    B_STATUS_TEXT_COLOR_TRANSPARENT,
    B_STATUS_TEXT_COLOR_PINK,
    B_STATUS_TEXT_COLOR_DARK_PINK
};

static const u8 sText_BattleStatus_Opponent[] = _("Opponent");
static const u8 sText_BattleStatus_Ally[] = _("Ally");
static const u8 sText_BattleStatus_DetailHeldItemLabel[] = _("Held Item");
static const u8 sText_BattleStatus_DetailHeldItemValue[] = _("None");
static const u8 sText_BattleStatus_DetailAbilityLabel[] = _("Ability");
static const u8 sText_BattleStatus_DetailAbilityValue[] = _("None");
static const u8 sText_BattleStatus_DetailLButtonGlyph[] = _("{L_BUTTON}");
static const u8 sText_BattleStatus_DetailRButtonGlyph[] = _("{R_BUTTON}");
static const u8 sText_BattleStatus_DetailEffectsHeader[] = _("Active States and Effects");
static const u8 sText_BattleStatus_DetailTeraTypeLabel[] = _("Tera\nType:");
static const u8 sText_BattleStatus_DetailStatAttack[] = _("Attack");
static const u8 sText_BattleStatus_DetailStatDefense[] = _("Defense");
static const u8 sText_BattleStatus_DetailStatSpAtk[] = _("Sp. Atk");
static const u8 sText_BattleStatus_DetailStatSpDef[] = _("Sp. Def");
static const u8 sText_BattleStatus_DetailStatSpeed[] = _("Speed");
static const u8 sText_BattleStatus_DetailStatAccuracy[] = _("Accuracy");
static const u8 sText_BattleStatus_DetailStatEvasion[] = _("Evasion");

static const u8 *const sBattleStatusDetailStatLabels[B_STATUS_DETAIL_STAT_ROW_COUNT] =
{
    sText_BattleStatus_DetailStatAttack,
    sText_BattleStatus_DetailStatDefense,
    sText_BattleStatus_DetailStatSpAtk,
    sText_BattleStatus_DetailStatSpDef,
    sText_BattleStatus_DetailStatSpeed,
    sText_BattleStatus_DetailStatAccuracy,
    sText_BattleStatus_DetailStatEvasion,
};

static const u8 sBattleStatusDetailStatIds[B_STATUS_DETAIL_STAT_ROW_COUNT] =
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

static const struct BattleStatusEffectData sBattleStatusEffects[B_STATUS_EFFECT_COUNT] =
{
    [B_STATUS_EFFECT_HARSH_SUNLIGHT] = {sText_BattleStatus_EffectName_HARSH_SUNLIGHT, COMPOUND_STRING("The harsh sunlight weather condition. It boosts the power of Fire-type moves and lowers the power of Water-type moves.")},
    [B_STATUS_EFFECT_RAIN] = {sText_BattleStatus_EffectName_RAIN, COMPOUND_STRING("The rain weather condition. It boosts the power of Water-type moves and lowers the power of Fire-type moves.")},
    [B_STATUS_EFFECT_SANDSTORM] = {sText_BattleStatus_EffectName_SANDSTORM, COMPOUND_STRING("The sandstorm weather condition. At the end of each turn, it damages all Pokemon that are not Rock, Ground, or Steel types. It boosts the Sp. Def of Rock-type Pokemon.")},
    [B_STATUS_EFFECT_SNOW] = {sText_BattleStatus_EffectName_SNOW, COMPOUND_STRING("The snow weather condition. It makes Blizzard more likely to hit and boosts the Defense of Ice-type Pokemon.")},
    [B_STATUS_EFFECT_ELECTRIC_TERRAIN] = {sText_BattleStatus_EffectName_ELECTRIC_TERRAIN, COMPOUND_STRING("For five turns, Pokemon on the ground won't fall asleep. The power of Electric-type moves is boosted.")},
    [B_STATUS_EFFECT_GRASSY_TERRAIN] = {sText_BattleStatus_EffectName_GRASSY_TERRAIN, COMPOUND_STRING("For five turns, Pokemon on the ground will have a little HP restored at the end of each turn. The power of Grass-type moves is boosted.")},
    [B_STATUS_EFFECT_MISTY_TERRAIN] = {sText_BattleStatus_EffectName_MISTY_TERRAIN, COMPOUND_STRING("For five turns, Pokemon on the ground won't get any status conditions. Damage from Dragon-type moves is halved.")},
    [B_STATUS_EFFECT_PSYCHIC_TERRAIN] = {sText_BattleStatus_EffectName_PSYCHIC_TERRAIN, COMPOUND_STRING("For five turns, Pokemon on the ground won't be hit by priority moves. The power of Psychic-type moves is boosted.")},
    [B_STATUS_EFFECT_TRICK_ROOM] = {sText_BattleStatus_EffectName_TRICK_ROOM, COMPOUND_STRING("Slower Pokemon get to move first for five turns.")},
    [B_STATUS_EFFECT_MAGIC_ROOM] = {sText_BattleStatus_EffectName_MAGIC_ROOM, COMPOUND_STRING("Pokemon can't use their held items for five turns.")},
    [B_STATUS_EFFECT_WONDER_ROOM] = {sText_BattleStatus_EffectName_WONDER_ROOM, COMPOUND_STRING("Pokemon's Defense and Sp. Def are swapped for five turns.")},
    [B_STATUS_EFFECT_GRAVITY] = {sText_BattleStatus_EffectName_GRAVITY, COMPOUND_STRING("Moves are more likely to hit for five turns. Ground-type moves will hit Flying-type Pokemon and Pokemon with the Levitate Ability. Moves that require action midair can't be used.")},
    [B_STATUS_EFFECT_MIST] = {sText_BattleStatus_EffectName_MIST, COMPOUND_STRING("The Pokemon's stats won't be lowered for five turns.")},
    [B_STATUS_EFFECT_SAFEGUARD] = {sText_BattleStatus_EffectName_SAFEGUARD, COMPOUND_STRING("The Pokemon is protected from status conditions for five turns.")},
    [B_STATUS_EFFECT_LUCKY_CHANT] = {sText_BattleStatus_EffectName_LUCKY_CHANT, COMPOUND_STRING("The opponent's moves won't result in a critical hit.")},
    [B_STATUS_EFFECT_TAILWIND] = {sText_BattleStatus_EffectName_TAILWIND, COMPOUND_STRING("The Speed stats of a Pokemon and its allies are doubled for four turns.")},
    [B_STATUS_EFFECT_CRITICAL_HIT_BOOST] = {sText_BattleStatus_EffectName_CRITICAL_HIT_BOOST, COMPOUND_STRING("The Pokemon is more likely to land critical hits.")},
    [B_STATUS_EFFECT_CONFUSION] = {sText_BattleStatus_EffectName_CONFUSION, COMPOUND_STRING("The Pokemon may hurt itself in its confusion. The effect lasts for one to four turns.")},
    [B_STATUS_EFFECT_INFATUATION] = {sText_BattleStatus_EffectName_INFATUATION, COMPOUND_STRING("The Pokemon is less likely to unleash an attack on Pokemon of the opposite gender.")},
    [B_STATUS_EFFECT_NIGHTMARE] = {sText_BattleStatus_EffectName_NIGHTMARE, COMPOUND_STRING("The Pokemon will lose HP each turn as long as it is sleeping.")},
    [B_STATUS_EFFECT_DROWSY] = {sText_BattleStatus_EffectName_DROWSY, COMPOUND_STRING("The Pokemon will fall asleep at the end of the turn if it remains on the battlefield.")},
    [B_STATUS_EFFECT_ENCORE] = {sText_BattleStatus_EffectName_ENCORE, COMPOUND_STRING("Due to Encore, the Pokemon can use only {STR_VAR_1} for three turns.")},
    [B_STATUS_EFFECT_TORMENT] = {sText_BattleStatus_EffectName_TORMENT, COMPOUND_STRING("The Pokemon can't use the same move twice in a row.")},
    [B_STATUS_EFFECT_GRUDGE] = {sText_BattleStatus_EffectName_GRUDGE, COMPOUND_STRING("If the Pokemon faints as a result of a move, the PP of that move will be reduced to 0.")},
    [B_STATUS_EFFECT_HEALING_PREVENTED] = {sText_BattleStatus_EffectName_HEALING_PREVENTED, COMPOUND_STRING("For five turns, the Pokemon is unable to recover HP through its moves, Ability, or held item.")},
    [B_STATUS_EFFECT_IDENTIFIED] = {sText_BattleStatus_EffectName_IDENTIFIED, COMPOUND_STRING("The Pokemon will be hit by certain moves that usually wouldn't affect it. If the Pokemon's evasiveness has been boosted, the benefits will be ignored when it is attacked.")},
    [B_STATUS_EFFECT_MOVE_DISABLED] = {sText_BattleStatus_EffectName_MOVE_DISABLED, COMPOUND_STRING("{STR_VAR_1} has been disabled and cannot be used for four turns.")},
    [B_STATUS_EFFECT_CANT_ESCAPE] = {sText_BattleStatus_EffectName_CANT_ESCAPE, COMPOUND_STRING("The Pokemon can't flee or be switched out.")},
    [B_STATUS_EFFECT_LOCK_ON] = {sText_BattleStatus_EffectName_LOCK_ON, COMPOUND_STRING("The next move used by the Pokemon will be sure to hit the target that was locked on to.")},
    [B_STATUS_EFFECT_EMBARGO] = {sText_BattleStatus_EffectName_EMBARGO, COMPOUND_STRING("For five turns, the Pokemon cannot use its held item and no items can be used on it.")},
    [B_STATUS_EFFECT_CHARGE] = {sText_BattleStatus_EffectName_CHARGE, COMPOUND_STRING("The power of the next Electric-type move used by the Pokemon will be doubled.")},
    [B_STATUS_EFFECT_TAUNT] = {sText_BattleStatus_EffectName_TAUNT, COMPOUND_STRING("The Pokemon can only use moves that deal damage.")},
    [B_STATUS_EFFECT_TELEKINESIS] = {sText_BattleStatus_EffectName_TELEKINESIS, COMPOUND_STRING("For three turns, moves used against the Pokemon will hit without fail, except for one-hit KO moves. Also, Ground-type moves won't hit the Pokemon.")},
    [B_STATUS_EFFECT_MAGNET_RISE] = {sText_BattleStatus_EffectName_MAGNET_RISE, COMPOUND_STRING("Ground-type moves won't hit the Pokemon for five turns.")},
    [B_STATUS_EFFECT_WISH] = {sText_BattleStatus_EffectName_WISH, COMPOUND_STRING("The Pokemon in this spot will have its HP restored on the turn after Wish was used.")},
    [B_STATUS_EFFECT_INGRAIN] = {sText_BattleStatus_EffectName_INGRAIN, COMPOUND_STRING("The Pokemon regains some HP at the end of each turn. Ingrained Pokemon can't be switched out.")},
    [B_STATUS_EFFECT_CURSE] = {sText_BattleStatus_EffectName_CURSE, COMPOUND_STRING("The Pokemon takes damage at the end of each turn.")},
    [B_STATUS_EFFECT_DESTINY_BOND] = {sText_BattleStatus_EffectName_DESTINY_BOND, COMPOUND_STRING("If the Pokemon is knocked out by an opponent, that opponent will also faint.")},
    [B_STATUS_EFFECT_BOUND] = {sText_BattleStatus_EffectName_BOUND, COMPOUND_STRING("The Pokemon is bound and takes damage every turn.")},
    [B_STATUS_EFFECT_BIDE] = {sText_BattleStatus_EffectName_BIDE, COMPOUND_STRING("The Pokemon endures attacks for two turns, then strikes back to inflict double the damage it has taken.")},
    [B_STATUS_EFFECT_FUTURE_ATTACK] = {sText_BattleStatus_EffectName_FUTURE_ATTACK, COMPOUND_STRING("The Pokemon will take damage two turns after an attack was foreseen.")},
    [B_STATUS_EFFECT_UPROAR] = {sText_BattleStatus_EffectName_UPROAR, COMPOUND_STRING("The Pokemon attacks and causes an uproar for three turns. During this time, no Pokemon can fall asleep.")},
    [B_STATUS_EFFECT_AQUA_RING] = {sText_BattleStatus_EffectName_AQUA_RING, COMPOUND_STRING("The Pokemon is enveloped in a veil made of water. It regains some HP every turn.")},
    [B_STATUS_EFFECT_AUTOTOMIZE] = {sText_BattleStatus_EffectName_AUTOTOMIZE, COMPOUND_STRING("The Pokemon's weight is reduced, and its Speed is sharply increased.")},
    [B_STATUS_EFFECT_SMACK_DOWN] = {sText_BattleStatus_EffectName_SMACK_DOWN, COMPOUND_STRING("The Pokemon has been knocked out of the sky and has fallen to the ground.")},
    [B_STATUS_EFFECT_FAIRY_LOCK] = {sText_BattleStatus_EffectName_FAIRY_LOCK, COMPOUND_STRING("No Pokemon can flee the turn after Fairy Lock is used.")},
    [B_STATUS_EFFECT_RAINBOW] = {sText_BattleStatus_EffectName_RAINBOW, COMPOUND_STRING("The additional effects of moves are more likely to occur.")},
    [B_STATUS_EFFECT_SWAMP] = {sText_BattleStatus_EffectName_SWAMP, COMPOUND_STRING("Speed is reduced by 75% in swampy conditions.")},
    [B_STATUS_EFFECT_SEA_OF_FIRE] = {sText_BattleStatus_EffectName_SEA_OF_FIRE, COMPOUND_STRING("Pokemon that are not Fire types will take damage every turn.")},
    [B_STATUS_EFFECT_THROAT_CHOP] = {sText_BattleStatus_EffectName_THROAT_CHOP, COMPOUND_STRING("The Pokemon can't use any sound-based moves for two turns.")},
    [B_STATUS_EFFECT_LASER_FOCUS] = {sText_BattleStatus_EffectName_LASER_FOCUS, COMPOUND_STRING("The next move used will always result in a critical hit.")},
    [B_STATUS_EFFECT_TAR_SHOT] = {sText_BattleStatus_EffectName_TAR_SHOT, COMPOUND_STRING("The Pokemon has been made weaker to Fire-type moves.")},
    [B_STATUS_EFFECT_OCTOLOCK] = {sText_BattleStatus_EffectName_OCTOLOCK, COMPOUND_STRING("The Pokemon's Defense and Sp. Def are both lowered with each passing turn.")},
    [B_STATUS_EFFECT_FIXATED] = {sText_BattleStatus_EffectName_FIXATED, COMPOUND_STRING("The Pokemon is fixated on the last move it used. This move will deal increased damage while the fixation lasts, but any damage dealt to the fixated Pokemon is also increased.")},
    [B_STATUS_EFFECT_SPLINTERS] = {sText_BattleStatus_EffectName_SPLINTERS, COMPOUND_STRING("At the end of each turn, the Pokemon is hurt by the jagged splinters digging into it.")},
    [B_STATUS_EFFECT_OBSCURED] = {sText_BattleStatus_EffectName_OBSCURED, COMPOUND_STRING("The Pokemon is concealed in mud or the like, raising the chance that the Pokemon will evade opponents' moves.")},
    [B_STATUS_EFFECT_PRIMED] = {sText_BattleStatus_EffectName_PRIMED, COMPOUND_STRING("The Pokemon has adopted a hard-hitting stance, increasing the damage it deals with its moves.")},
    [B_STATUS_EFFECT_STANCE_SWAP] = {sText_BattleStatus_EffectName_STANCE_SWAP, COMPOUND_STRING("The Pokemon has swapped its offensive stats with its defensive stats.")},
    [B_STATUS_EFFECT_SLOW_START] = {sText_BattleStatus_EffectName_SLOW_START, COMPOUND_STRING("The Pokemon's Attack and Speed stats are halved until it gets going.")},
    [B_STATUS_EFFECT_SALT_CURE] = {sText_BattleStatus_EffectName_SALT_CURE, COMPOUND_STRING("The Pokemon is being salt cured, which deals damage to it each turn. This damage is doubled for Steel-type and Water-type Pokemon.")},
    [B_STATUS_EFFECT_SYRUPY] = {sText_BattleStatus_EffectName_SYRUPY, COMPOUND_STRING("The Pokemon's Speed will drop at the end of each turn for three turns.")},
    [B_STATUS_EFFECT_GOING_ALL_OUT] = {sText_BattleStatus_EffectName_GOING_ALL_OUT, COMPOUND_STRING("The Pokemon's Attack and Sp. Atk are both boosted thanks to a Trainer's cheer.")},
    [B_STATUS_EFFECT_HANGING_TOUGH] = {sText_BattleStatus_EffectName_HANGING_TOUGH, COMPOUND_STRING("The Pokemon's Defense and Sp. Def are both boosted thanks to a Trainer's cheer.")},
    [B_STATUS_EFFECT_POISONED] = {sText_BattleStatus_EffectName_POISONED, COMPOUND_STRING("At the end of each turn, the Pokemon is hurt by poison.")},
    [B_STATUS_EFFECT_BADLY_POISONED] = {sText_BattleStatus_EffectName_BADLY_POISONED, COMPOUND_STRING("The Pokemon is badly poisoned. The damage the Pokemon takes from the poison worsens every turn.")},
    [B_STATUS_EFFECT_PARALYZED] = {sText_BattleStatus_EffectName_PARALYZED, COMPOUND_STRING("The Pokemon is paralyzed and may fail to act. Its Speed stat is also lowered.")},
    [B_STATUS_EFFECT_BURNED] = {sText_BattleStatus_EffectName_BURNED, COMPOUND_STRING("At the end of each turn, the Pokemon is hurt by its burn. Any damage it deals with physical moves will also be reduced.")},
    [B_STATUS_EFFECT_FROSTBITE] = {sText_BattleStatus_EffectName_FROSTBITE, COMPOUND_STRING("At the end of each turn, the Pokemon is hurt by its frostbite. Any damage it deals with special moves will also be reduced.")},
    [B_STATUS_EFFECT_STEALTH_ROCK] = {sText_BattleStatus_EffectName_STEALTH_ROCK, COMPOUND_STRING("Pokemon that switch into battle will take damage.")},
    [B_STATUS_EFFECT_SPIKES] = {sText_BattleStatus_EffectName_SPIKES, COMPOUND_STRING("Pokemon that switch into battle will take damage. Flying-type Pokemon or Pokemon with the Levitate Ability will not be affected.")},
    [B_STATUS_EFFECT_TOXIC_SPIKES] = {sText_BattleStatus_EffectName_TOXIC_SPIKES, COMPOUND_STRING("Pokemon that switch into battle will be poisoned. Flying-type Pokemon or Pokemon with the Levitate Ability will not be affected.")},
    [B_STATUS_EFFECT_STICKY_WEB] = {sText_BattleStatus_EffectName_STICKY_WEB, COMPOUND_STRING("Pokemon that switch into battle will have their Speed lowered.")},
    [B_STATUS_EFFECT_LIGHT_SCREEN] = {sText_BattleStatus_EffectName_LIGHT_SCREEN, COMPOUND_STRING("Damage from special moves is halved for five turns.")},
    [B_STATUS_EFFECT_REFLECT] = {sText_BattleStatus_EffectName_REFLECT, COMPOUND_STRING("Damage from physical moves is halved for five turns.")},
    [B_STATUS_EFFECT_AURORA_VEIL] = {sText_BattleStatus_EffectName_AURORA_VEIL, COMPOUND_STRING("For five turns, the power of special and physical moves will be halved.")},
    [B_STATUS_EFFECT_MUD_SPORT] = {sText_BattleStatus_EffectName_MUD_SPORT, COMPOUND_STRING("The power of Electric-type moves will be halved for five turns.")},
    [B_STATUS_EFFECT_WATER_SPORT] = {sText_BattleStatus_EffectName_WATER_SPORT, COMPOUND_STRING("The power of Fire-type moves will be halved for five turns.")},
    [B_STATUS_EFFECT_FORESTS_CURSE] = {sText_BattleStatus_EffectName_FORESTS_CURSE, COMPOUND_STRING("The Pokemon gains the Grass type.")},
    [B_STATUS_EFFECT_TRICK_OR_TREAT] = {sText_BattleStatus_EffectName_TRICK_OR_TREAT, COMPOUND_STRING("The Pokemon gains the Ghost type.")},
    [B_STATUS_EFFECT_POWER_BOOST] = {sText_BattleStatus_EffectName_POWER_BOOST, COMPOUND_STRING("The Pokemon's offensive stats are raised, boosting its Attack and Sp. Atk stats.")},
    [B_STATUS_EFFECT_POWER_DROP] = {sText_BattleStatus_EffectName_POWER_DROP, COMPOUND_STRING("The Pokemon's offensive stats are lowered, reducing its Attack and Sp. Atk stats.")},
    [B_STATUS_EFFECT_GUARD_BOOST] = {sText_BattleStatus_EffectName_GUARD_BOOST, COMPOUND_STRING("The Pokemon's defensive stats are raised, boosting its Defense and Sp. Def stats.")},
    [B_STATUS_EFFECT_GUARD_DROP] = {sText_BattleStatus_EffectName_GUARD_DROP, COMPOUND_STRING("The Pokemon's defensive stats are lowered, reducing its Defense and Sp. Def stats.")},
    [B_STATUS_EFFECT_FOG] = {sText_BattleStatus_EffectName_FOG, COMPOUND_STRING("All moves are less accurate, apart from moves that are always sure to hit.")},
    [B_STATUS_EFFECT_EXTREMELY_HARSH_SUNLIGHT] = {sText_BattleStatus_EffectName_EXTREMELY_HARSH_SUNLIGHT, COMPOUND_STRING("The extremely harsh sunlight weather condition. It boosts the power of Fire-type moves and protects Pokemon from Water-type moves.")},
    [B_STATUS_EFFECT_HEAVY_RAIN] = {sText_BattleStatus_EffectName_HEAVY_RAIN, COMPOUND_STRING("The heavy rain weather condition. It boosts the power of Water-type moves and protects Pokemon from Fire-type moves.")},
    [B_STATUS_EFFECT_STRONG_WINDS] = {sText_BattleStatus_EffectName_STRONG_WINDS, COMPOUND_STRING("The strong winds weather condition. The power of moves that are super effective against Flying-type Pokemon is decreased.")},
    [B_STATUS_EFFECT_OUTRAGE] = {sText_BattleStatus_EffectName_OUTRAGE, COMPOUND_STRING("The Pokemon rampages and attacks for two to three turns. It then becomes confused.")},
    [B_STATUS_EFFECT_RAMPAGING] = {sText_BattleStatus_EffectName_RAMPAGING, COMPOUND_STRING("The Pokemon rampages and attacks for two to three turns. It then becomes confused.")},
    [B_STATUS_EFFECT_PETAL_DANCE] = {sText_BattleStatus_EffectName_PETAL_DANCE, COMPOUND_STRING("The Pokemon rampages and attacks for two to three turns. It then becomes confused.")},
    [B_STATUS_EFFECT_RAGING_FURY] = {sText_BattleStatus_EffectName_RAGING_FURY, COMPOUND_STRING("The Pokemon rampages and attacks for two to three turns. It then becomes confused.")},
    [B_STATUS_EFFECT_G_MAX_WILDFIRE] = {sText_BattleStatus_EffectName_G_MAX_WILDFIRE, COMPOUND_STRING("Pokemon that are not {STR_VAR_1} types will take damage every turn for four turns.")},
    [B_STATUS_EFFECT_G_MAX_VOLCALITH] = {sText_BattleStatus_EffectName_G_MAX_VOLCALITH, COMPOUND_STRING("Pokemon that are not {STR_VAR_1} types will take damage every turn for four turns.")},
    [B_STATUS_EFFECT_G_MAX_VINE_LASH] = {sText_BattleStatus_EffectName_G_MAX_VINE_LASH, COMPOUND_STRING("Pokemon that are not {STR_VAR_1} types will take damage every turn for four turns.")},
    [B_STATUS_EFFECT_G_MAX_CANNONADE] = {sText_BattleStatus_EffectName_G_MAX_CANNONADE, COMPOUND_STRING("Pokemon that are not {STR_VAR_1} types will take damage every turn for four turns.")},
    [B_STATUS_EFFECT_WILD_MIGHT] = {sText_BattleStatus_EffectName_WILD_MIGHT, COMPOUND_STRING("All the Pokemon's stats are boosted. The Pokemon also takes reduced damage from status conditions and move effects such as poisoning and splinters.")},
    [B_STATUS_EFFECT_TERRIBLE_MIGHT] = {sText_BattleStatus_EffectName_TERRIBLE_MIGHT, COMPOUND_STRING("All the Pokemon's stats are boosted. The Pokemon also takes reduced damage from status conditions and move effects such as poisoning and splinters.")},
    [B_STATUS_EFFECT_TERRIFIC_MIGHT] = {sText_BattleStatus_EffectName_TERRIFIC_MIGHT, COMPOUND_STRING("The Pokemon takes reduced damage from status conditions and move effects such as poisoning and splinters.")},
    [B_STATUS_EFFECT_FRENZIED_MIGHT] = {sText_BattleStatus_EffectName_FRENZIED_MIGHT, COMPOUND_STRING("The Pokemon takes reduced damage from status conditions and move effects such as poisoning and splinters.")},
};
STATIC_ASSERT(ARRAY_COUNT(sBattleStatusEffects) == B_STATUS_EFFECT_COUNT, BattleStatusEffectTableSizeMismatch);

static const u8 sBattleStatusHpBarTiles[8 * TILE_SIZE_4BPP] = {0};
static const u8 sBattleStatusHpBarLeftEndcapGfx[] = INCBIN_U8("graphics/battle_interface/hpbar_left_endcap.4bpp");
static const u8 sBattleStatusHpBarRightEndcapGfx[] = INCBIN_U8("graphics/battle_interface/hpbar_right_endcap.4bpp");
static const u16 sBattleStatusMenuBgPalette[] = INCBIN_U16("graphics/battle_interface/battle_status_menu.gbapal");
static const u32 sBattleStatusMenuBgTiles[] = INCBIN_U32("graphics/battle_interface/battle_status_menu.4bpp");
static const u16 sBattleStatusMenuOverviewBaseTilemap[] = INCBIN_U16("graphics/battle_interface/active_battlers_overview.bin");
static const u16 sBattleStatusMenuDetailsBaseTilemap[] = INCBIN_U16("graphics/battle_interface/active_battlers_details.bin");

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
    sBattleStatusHpBarTiles, sizeof(sBattleStatusHpBarTiles), B_STATUS_HP_BAR_TILE_TAG_BASE
};

static const struct SpritePalette sSpritePalette_BattleStatusHpBar =
{
    gBattleInterface_BallDisplayPal, B_STATUS_HP_BAR_PAL_TAG
};

static const struct SpriteTemplate sSpriteTemplate_BattleStatusHpBar =
{
    .tileTag = B_STATUS_HP_BAR_TILE_TAG_BASE,
    .paletteTag = B_STATUS_HP_BAR_PAL_TAG,
    .oam = &sOamData_BattleStatusHpBar,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_BattleStatusHpBarEndcap =
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

static const struct SpriteSheet sSpriteSheet_BattleStatusHpBarLeftEndcap =
{
    sBattleStatusHpBarLeftEndcapGfx, sizeof(sBattleStatusHpBarLeftEndcapGfx), B_STATUS_HP_BAR_ENDCAP_LEFT_TILE_TAG
};

static const struct SpriteSheet sSpriteSheet_BattleStatusHpBarRightEndcap =
{
    sBattleStatusHpBarRightEndcapGfx, sizeof(sBattleStatusHpBarRightEndcapGfx), B_STATUS_HP_BAR_ENDCAP_RIGHT_TILE_TAG
};

static const struct SpritePalette sSpritePalette_BattleStatusHpBarEndcap =
{
    gBattleInterface_BallDisplayPal, B_STATUS_HP_BAR_ENDCAP_PAL_TAG
};

static const struct SpriteTemplate sSpriteTemplate_BattleStatusHpBarLeftEndcap =
{
    .tileTag = B_STATUS_HP_BAR_ENDCAP_LEFT_TILE_TAG,
    .paletteTag = B_STATUS_HP_BAR_ENDCAP_PAL_TAG,
    .oam = &sOamData_BattleStatusHpBarEndcap,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_BattleStatusHpBarRightEndcap =
{
    .tileTag = B_STATUS_HP_BAR_ENDCAP_RIGHT_TILE_TAG,
    .paletteTag = B_STATUS_HP_BAR_ENDCAP_PAL_TAG,
    .oam = &sOamData_BattleStatusHpBarEndcap,
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
    sBattleStatusUpdateIconGfx, sizeof(sBattleStatusUpdateIconGfx), B_STATUS_UPDATE_ICON_TILE_TAG
};

static const struct SpriteTemplate sSpriteTemplate_BattleStatusUpdateIcon =
{
    .tileTag = B_STATUS_UPDATE_ICON_TILE_TAG,
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
    sBattleStatusDetailStatPipDotGfx, sizeof(sBattleStatusDetailStatPipDotGfx), B_STATUS_DETAIL_STAT_PIP_DOT_TILE_TAG
};

static const struct SpriteSheet sSpriteSheet_BattleStatusDetailStatPipUp =
{
    sBattleStatusDetailStatPipUpGfx, sizeof(sBattleStatusDetailStatPipUpGfx), B_STATUS_DETAIL_STAT_PIP_UP_TILE_TAG
};

static const struct SpriteSheet sSpriteSheet_BattleStatusDetailStatPipDown =
{
    sBattleStatusDetailStatPipDownGfx, sizeof(sBattleStatusDetailStatPipDownGfx), B_STATUS_DETAIL_STAT_PIP_DOWN_TILE_TAG
};

static const struct SpriteTemplate sSpriteTemplate_BattleStatusDetailStatPip =
{
    .tileTag = B_STATUS_DETAIL_STAT_PIP_DOT_TILE_TAG,
    .paletteTag = B_STATUS_DETAIL_STAT_PIP_PAL_TAG,
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
    sBattleStatusDetailEffectsScrollbarGfx, sizeof(sBattleStatusDetailEffectsScrollbarGfx), B_STATUS_DETAIL_EFFECTS_SCROLLBAR_TILE_TAG
};

static const struct SpriteTemplate sSpriteTemplate_BattleStatusDetailEffectsScrollbar =
{
    .tileTag = B_STATUS_DETAIL_EFFECTS_SCROLLBAR_TILE_TAG,
    .paletteTag = TAG_MISC_INDICATOR_PAL,
    .oam = &sOamData_BattleStatusDetailEffectsScrollbar,
    .callback = SpriteCallbackDummy,
};

static const u8 sBattleStatusCursorGfx[] = INCBIN_U8("graphics/battle_interface/arrow_indicator.4bpp");

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
    .tileTag = B_STATUS_CURSOR_TILE_TAG,
    .paletteTag = TAG_MISC_INDICATOR_PAL,
    .oam = &sOamData_BattleStatusCursor,
    .callback = SpriteCallbackDummy
};

static const struct SpriteSheet sSpriteSheet_BattleStatusCursor =
{
    sBattleStatusCursorGfx, sizeof(sBattleStatusCursorGfx), B_STATUS_CURSOR_TILE_TAG
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
    .tileTag = B_STATUS_DETAIL_GIMMICK_TILE_TAG,
    .paletteTag = TAG_MISC_INDICATOR_PAL,
    .oam = &sOamData_BattleStatusDetailGimmick,
    .callback = SpriteCallbackDummy,
};

static const struct BgTemplate sBattleStatusMenuBgTemplates[] =
{
    [B_STATUS_TEXT_BG] = {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    [B_STATUS_BACKDROP_BG] = {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
};

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
        .height = B_STATUS_LABEL_TILE_H,
        .paletteNum = B_STATUS_TEXT_PAL,
        .baseBlock = B_STATUS_WIN_LABEL_TOP_BASE,
    },
    [WIN_LABEL_BOTTOM] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = B_STATUS_LABEL_BOTTOM_TILE_TOP,
        .width = 32,
        .height = B_STATUS_LABEL_TILE_H,
        .paletteNum = B_STATUS_TEXT_PAL,
        .baseBlock = B_STATUS_WIN_LABEL_BOTTOM_BASE,
    },
    [WIN_ROW_ENEMY] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = B_STATUS_ROW_Y_ENEMY / 8,
        .width = 32,
        .height = B_STATUS_CARD_TILE_H,
        .paletteNum = B_STATUS_TEXT_PAL,
        .baseBlock = B_STATUS_WIN_ROW_ENEMY_BASE,
    },
    [WIN_ROW_PLAYER] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = B_STATUS_ROW_Y_PLAYER / 8,
        .width = 32,
        .height = B_STATUS_CARD_TILE_H,
        .paletteNum = B_STATUS_TEXT_PAL,
        .baseBlock = B_STATUS_WIN_ROW_PLAYER_BASE,
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
    WIN_DETAIL_COUNT = B_STATUS_DETAIL_WINDOW_COUNT,
};

static const struct WindowTemplate sBattleStatusDetailWindowTemplates[WIN_DETAIL_COUNT] =
{
    [WIN_DETAIL_HEADER] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 0,
        .width = B_STATUS_DETAIL_HEADER_WIN_W,
        .height = B_STATUS_DETAIL_HEADER_WIN_H,
        .paletteNum = B_STATUS_TEXT_PAL,
        .baseBlock = B_STATUS_WIN_DETAIL_HEADER_BASE,
    },
    [WIN_DETAIL_ITEM_ABILITY] = {
        .bg = 0,
        .tilemapLeft = 7,
        .tilemapTop = 4,
        .width = B_STATUS_DETAIL_ITEM_WIN_W,
        .height = B_STATUS_DETAIL_ITEM_WIN_H,
        .paletteNum = B_STATUS_TEXT_PAL,
        .baseBlock = B_STATUS_WIN_DETAIL_ITEM_BASE,
    },
    [WIN_DETAIL_STATS] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 9,
        .width = B_STATUS_DETAIL_STATS_WIN_W,
        .height = B_STATUS_DETAIL_STATS_WIN_H,
        .paletteNum = B_STATUS_TEXT_PAL,
        .baseBlock = B_STATUS_WIN_DETAIL_STATS_BASE,
    },
    [WIN_DETAIL_EFFECTS] = {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 0,
        .width = B_STATUS_DETAIL_EFFECTS_WIN_W,
        .height = B_STATUS_DETAIL_EFFECTS_WIN_H,
        .paletteNum = B_STATUS_TEXT_PAL,
        .baseBlock = B_STATUS_WIN_DETAIL_EFFECTS_BASE,
    },
    [WIN_DETAIL_DESCRIPTION] = {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 12,
        .width = B_STATUS_DETAIL_DESC_WIN_W,
        .height = B_STATUS_DETAIL_DESC_WIN_H,
        .paletteNum = B_STATUS_TEXT_PAL,
        .baseBlock = B_STATUS_WIN_DETAIL_DESC_BASE,
    },
};

void CB2_BattleStatusMenuFromBattle(void)
{
    sData = AllocZeroed(sizeof(struct BattleStatusMenuData));

    if (sData == NULL)
    {
        SetMainCallback2(CB2_SetUpReshowBattleScreenAfterMenu);
        return;
    }

    GoToBattleStatusMenu();
}

static void GoToBattleStatusMenu(void)
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
    CpuFill16(0, (void *)BG_CHAR_ADDR(2), BG_CHAR_SIZE);
    CpuFill16(0, (void *)BG_CHAR_ADDR(3), BG_CHAR_SIZE);

    InitBgsFromTemplates(0, sBattleStatusMenuBgTemplates, ARRAY_COUNT(sBattleStatusMenuBgTemplates));
    SetBgTilemapBuffer(B_STATUS_TEXT_BG, sData->bg0Tilemap);
    SetBgTilemapBuffer(B_STATUS_BACKDROP_BG, sData->bg1Tilemap);
    FillBgTilemapBufferRect(B_STATUS_TEXT_BG, 0, 0, 0, B_STATUS_TILEMAP_WIDTH, B_STATUS_TILEMAP_HEIGHT, 0);
    FillBgTilemapBufferRect(B_STATUS_BACKDROP_BG, 0, 0, 0, B_STATUS_TILEMAP_WIDTH, B_STATUS_TILEMAP_HEIGHT, 0);
    CopyBgTilemapBufferToVram(B_STATUS_TEXT_BG);
    CopyBgTilemapBufferToVram(B_STATUS_BACKDROP_BG);
    ResetAllBgsCoordinates();
    LoadBgTiles(B_STATUS_BACKDROP_BG, sBattleStatusMenuBgTiles, sizeof(sBattleStatusMenuBgTiles), 0);
    LoadPalette(sBattleStatusMenuBgPalette, BG_PLTT_ID(0), sizeof(sBattleStatusMenuBgPalette));
    LoadPalette(gBattleStatusTextPalette, BG_PLTT_ID(B_STATUS_TEXT_PAL), PLTT_SIZE_4BPP);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(B_STATUS_BACKDROP_BG);
    ShowBg(B_STATUS_TEXT_BG);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    InitWindows((const struct WindowTemplate[]){DUMMY_WIN_TEMPLATE});
    DeactivateAllTextPrinters();
    BattleStatusMenu_Init();
    BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    gPaletteFade.bufferTransferDisabled = FALSE;
    sData->menuState = BATTLE_STATUS_MENU_STATE_FADE_IN;
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
    if (sData->menuState != BATTLE_STATUS_MENU_STATE_FADE_OUT
     && sData->pendingPage == BATTLE_STATUS_PAGE_NONE)
    {
        if (sData->menu.page == BATTLE_STATUS_PAGE_OVERVIEW)
            OverviewUpdateHpBars();
        else
            DetailRefreshHpBar();
    }

    switch (sData->menuState)
    {
    case BATTLE_STATUS_MENU_STATE_FADE_IN:
        if (!gPaletteFade.active)
            sData->menuState = BATTLE_STATUS_MENU_STATE_WAIT_INPUT;
        break;
    case BATTLE_STATUS_MENU_STATE_WAIT_INPUT:
        if (sData->pendingPage != BATTLE_STATUS_PAGE_NONE)
        {
            ProcessPageTransition();
            break;
        }

        if (sData->menu.page == BATTLE_STATUS_PAGE_OVERVIEW)
        {
            OverviewHandleInput();
            if (JOY_NEW(B_BUTTON))
            {
                PlaySE(SE_SELECT);
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                sData->menuState = BATTLE_STATUS_MENU_STATE_FADE_OUT;
            }
        }
        else
            DetailHandleInput();
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
    memset(&sData->menu, 0, sizeof(sData->menu));
    sData->menu.page = BATTLE_STATUS_PAGE_OVERVIEW;
    sData->menu.selectedCardIndex = 0;
    sData->menu.cursorSpriteId = SPRITE_NONE;
    sData->menu.detailIconSpriteId = SPRITE_NONE;
    sData->menu.detailHpBarSpriteId = SPRITE_NONE;
    sData->menu.detailHpBarLeftEndcapSpriteId = SPRITE_NONE;
    sData->menu.detailHpBarRightEndcapSpriteId = SPRITE_NONE;
    sData->menu.detailStatusSpriteId = SPRITE_NONE;
    sData->menu.detailTeraTypeSpriteId = SPRITE_NONE;
    sData->menu.detailGimmickSpriteId = SPRITE_NONE;
    sData->menu.detailEffectsScrollbarSpriteId = SPRITE_NONE;
    sData->menu.detailTypeIconSpriteIds[0] = SPRITE_NONE;
    sData->menu.detailTypeIconSpriteIds[1] = SPRITE_NONE;
    for (u32 i = 0; i < B_STATUS_DETAIL_STAT_ROW_COUNT; i++)
    {
        for (u32 j = 0; j < B_STATUS_DETAIL_STAT_PIPS_PER_ROW; j++)
            sData->menu.detailStatPipSpriteIds[i][j] = SPRITE_NONE;
    }
    for (u32 i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        sData->menu.cards[i].gimmickTileTag = 0;
        sData->menu.cards[i].hpBarSpriteId = SPRITE_NONE;
        sData->menu.cards[i].monIconSpriteId = SPRITE_NONE;
        sData->menu.cards[i].gimmickSpriteId = SPRITE_NONE;
        sData->menu.cards[i].statusSpriteId = SPRITE_NONE;
        sData->menu.cards[i].updateSpriteId = SPRITE_NONE;
        sData->menu.cards[i].hpBarLeftEndcapSpriteId = SPRITE_NONE;
        sData->menu.cards[i].hpBarRightEndcapSpriteId = SPRITE_NONE;
    }
    for (u32 i = 0; i < ARRAY_COUNT(sData->menu.detailWindowIds); i++)
        sData->menu.detailWindowIds[i] = WINDOW_NONE;

    sData->pendingPage = BATTLE_STATUS_PAGE_NONE;
    sData->transitionUnloaded = FALSE;

    LoadMonIconPalettes();
    LoadPartyMenuAilmentGfx();
    LoadSpriteSheet(&sSpriteSheet_BattleStatusHpBar);
    LoadSpriteSheet(&sSpriteSheet_BattleStatusHpBarLeftEndcap);
    LoadSpriteSheet(&sSpriteSheet_BattleStatusHpBarRightEndcap);
    LoadSpritePalette(&sSpritePalette_BattleStatusHpBar);
    LoadSpritePalette(&sSpritePalette_BattleStatusHpBarEndcap);
    LoadSpriteSheet(&sSpriteSheet_BattleStatusUpdateIcon);
    LoadCompressedSpriteSheet(&gSpriteSheet_MoveTypes);
    LoadSpritePaletteInSlot(&(struct SpritePalette){ .data = gMoveTypes_Pal,      .tag = gSpriteTemplate_MoveTypes.paletteTag }, 13);
    LoadSpritePaletteInSlot(&(struct SpritePalette){ .data = gMoveTypes_Pal + 16, .tag = B_STATUS_MOVE_TYPES_PAL_TAG_1 }, 14);
    LoadSpritePaletteInSlot(&(struct SpritePalette){ .data = gMoveTypes_Pal + 32, .tag = B_STATUS_MOVE_TYPES_PAL_TAG_2 }, 15);
    LoadSpriteSheet(&sSpriteSheet_BattleStatusDetailEffectsScrollbar);
    LoadSpriteSheet(&sSpriteSheet_BattleStatusCursor);
    LoadIndicatorSpritesGfx();

    OverviewCreateWindows();
    OverviewEnter();
}

static void OverviewEnter(void)
{
    sData->menu.page = BATTLE_STATUS_PAGE_OVERVIEW;
    LoadBackdropAssets();
    OverviewClearWindows();
    RefreshUnreadUpdates();
    OverviewBufferLabelText();
    OverviewCreateCards();
    OverviewDrawBackground();
    OverviewDrawCards();
    OverviewDrawLabels();
    OverviewInitCursor();
    ShowBg(B_STATUS_BACKDROP_BG);
    ShowBg(B_STATUS_TEXT_BG);
}

static void OverviewExit(void)
{
    if (sData->menu.cursorSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sData->menu.cursorSpriteId]);
    sData->menu.cursorSpriteId = SPRITE_NONE;

    for (u32 i = 0; i < gBattlersCount; i++)
        DestroyOverviewCardSprites(&sData->menu.cards[i], FALSE);

    OverviewClearWindows();
}

static void OverviewClearWindows(void)
{
    for (u32 i = 0; i < 4; i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(B_STATUS_TEXT_COLOR_TRANSPARENT));
        ClearWindowTilemap(i);
        CopyWindowToVram(i, COPYWIN_GFX);
    }

    CopyBgTilemapBufferToVram(B_STATUS_TEXT_BG);
}

static void DetailEnter(void)
{
    DetailDestroyEffectsCursor();

    sData->menu.page = BATTLE_STATUS_PAGE_DETAIL;
    sData->menu.detailIconSpriteId = SPRITE_NONE;
    sData->menu.detailHpBarSpriteId = SPRITE_NONE;
    sData->menu.detailStatusSpriteId = SPRITE_NONE;
    sData->menu.detailTeraTypeSpriteId = SPRITE_NONE;
    sData->menu.detailGimmickSpriteId = SPRITE_NONE;
    LoadBackdropAssets();
    BackdropLoadBaseTilemap(sBattleStatusMenuDetailsBaseTilemap);
    FillBgTilemapBufferRect(B_STATUS_TEXT_BG, 0, 0, 0, B_STATUS_TILEMAP_WIDTH, B_STATUS_TILEMAP_HEIGHT, 0);
    CopyBgTilemapBufferToVram(B_STATUS_TEXT_BG);
    DetailCreateWindows();
    DetailDrawStaticWindows();
    DetailInitEffectsList();
    DetailCreateStatPips();
    DetailRefreshStatPips();
    DetailRefreshHeader();
    DetailRefreshItemAbilityWindow();
    DetailRefreshIcon();
    DetailRefreshHpBar();
    DetailRefreshStatusIcon();
    DetailRefreshTypeIcons();
    ShowBg(B_STATUS_BACKDROP_BG);
    ShowBg(B_STATUS_TEXT_BG);
}

static void DetailExit(void)
{
    DetailDestroyWindows();

    DetailDestroyHpBar();
    DetailDestroyStatusIcon();
    DetailDestroyTeraTypeIndicator();
    DetailDestroyGimmickIndicator();
    DetailDestroyTypeIcons();
    DetailDestroyStatPips();
    DetailDestroyEffectsScrollbar();
    DetailDestroyEffectsCursor();
    sData->menu.detailActiveEffectsCount = 0;
    sData->menu.detailEffectsCursor = 0;
    sData->menu.detailEffectsScroll = 0;

    if (sData->menu.detailIconSpriteId != SPRITE_NONE)
        FreeAndDestroyMonIconSprite(&gSprites[sData->menu.detailIconSpriteId]);
    sData->menu.detailIconSpriteId = SPRITE_NONE;

    FillBgTilemapBufferRect(B_STATUS_TEXT_BG, 0, 0, 0, B_STATUS_TILEMAP_WIDTH, B_STATUS_TILEMAP_HEIGHT, 0);
    CopyBgTilemapBufferToVram(B_STATUS_TEXT_BG);

}

static void DetailHandleInput(void)
{
    s8 scrollDir = 0;

    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        RequestPageTransition(BATTLE_STATUS_PAGE_OVERVIEW);
        return;
    }

    if (JOY_NEW(L_BUTTON))
    {
        PlaySE(SE_SELECT);
        DetailCycleBattler(-1);
    }
    else if (JOY_NEW(R_BUTTON))
    {
        PlaySE(SE_SELECT);
        DetailCycleBattler(1);
    }
    else
    {
        if (JOY_REPEAT(DPAD_UP))
            scrollDir = -1;
        else if (JOY_REPEAT(DPAD_DOWN))
            scrollDir = 1;

        if (scrollDir != 0 && DetailTryMoveEffectCursor(scrollDir))
        {
            PlaySE(SE_SELECT);
            DetailRefreshEffectsSection();
        }
    }
}

static void DetailCreateWindows(void)
{
    for (u32 i = 0; i < WIN_DETAIL_COUNT; i++)
        sData->menu.detailWindowIds[i] = WINDOW_NONE;

    for (u32 i = 0; i < WIN_DETAIL_COUNT; i++)
    {
        if (i == WIN_DETAIL_ITEM_ABILITY)
            continue;

        sData->menu.detailWindowIds[i] = AddWindow(&sBattleStatusDetailWindowTemplates[i]);
        if (sData->menu.detailWindowIds[i] != WINDOW_NONE)
            DetailDrawWindowFrame(sData->menu.detailWindowIds[i]);
    }

    sData->menu.detailWindowIds[WIN_DETAIL_ITEM_ABILITY] = sData->menu.detailWindowIds[WIN_DETAIL_HEADER];
}

static void DetailDestroyWindows(void)
{
    u32 mergedInfoWindowId = sData->menu.detailWindowIds[WIN_DETAIL_HEADER];

    for (u32 i = 0; i < WIN_DETAIL_COUNT; i++)
    {
        u8 windowId = sData->menu.detailWindowIds[i];

        if (windowId == WINDOW_NONE)
            continue;

        if (i == WIN_DETAIL_ITEM_ABILITY
         && windowId == mergedInfoWindowId)
        {
            sData->menu.detailWindowIds[i] = WINDOW_NONE;
            continue;
        }

        FillWindowPixelBuffer(windowId, PIXEL_FILL(B_STATUS_TEXT_COLOR_TRANSPARENT));
        ClearWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_GFX);
        RemoveWindow(windowId);
        sData->menu.detailWindowIds[i] = WINDOW_NONE;
    }

    CopyBgTilemapBufferToVram(B_STATUS_TEXT_BG);
}

static void DetailDrawStaticWindows(void)
{
    u8 windowId;

    windowId = sData->menu.detailWindowIds[WIN_DETAIL_ITEM_ABILITY];
    if (windowId != WINDOW_NONE)
    {
        DetailDrawWindowFrame(windowId);
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }

    windowId = sData->menu.detailWindowIds[WIN_DETAIL_STATS];
    if (windowId != WINDOW_NONE)
    {
        u8 i;

        DetailDrawWindowFrame(windowId);
        for (i = 0; i < B_STATUS_DETAIL_STAT_ROW_COUNT; i++)
        {
            AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROW, 2,
                                         DetailGetStatRowTextY(i), 0, 0,
                                         sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW,
                                         sBattleStatusDetailStatLabels[i]);
        }
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }

    DetailDrawLRButtonGlyphs();
    windowId = sData->menu.detailWindowIds[WIN_DETAIL_ITEM_ABILITY];
    if (windowId != WINDOW_NONE)
    {
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }
    windowId = sData->menu.detailWindowIds[WIN_DETAIL_STATS];
    if (windowId != WINDOW_NONE)
    {
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }

    windowId = sData->menu.detailWindowIds[WIN_DETAIL_EFFECTS];
    if (windowId != WINDOW_NONE)
    {
        DetailDrawWindowFrame(windowId);
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }

    windowId = sData->menu.detailWindowIds[WIN_DETAIL_DESCRIPTION];
    if (windowId != WINDOW_NONE)
    {
        DetailDrawWindowFrame(windowId);
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }
}

static u8 DetailGetBestFitSmallFont(const u8 *text, s16 maxWidth)
{
    if (GetStringWidth(FONT_SMALL, text, 0) <= maxWidth)
        return FONT_SMALL;
    if (GetStringWidth(FONT_SMALL_NARROW, text, 0) <= maxWidth)
        return FONT_SMALL_NARROW;
    return FONT_SMALL_NARROWER;
}

static void DetailDestroyHpBar(void)
{
    if (sData->menu.detailHpBarSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sData->menu.detailHpBarSpriteId]);
    sData->menu.detailHpBarSpriteId = SPRITE_NONE;
    DestroyHpBarEndcaps(&sData->menu.detailHpBarLeftEndcapSpriteId,
                                     &sData->menu.detailHpBarRightEndcapSpriteId);

    FreeSpriteTilesByTag(B_STATUS_DETAIL_HP_BAR_TILE_TAG);
}

static void DetailRefreshHpBar(void)
{
    enum BattlerId battler = GetSelectedBattler();
    s16 hp = gBattleMons[battler].hp;
    s16 maxHp = gBattleMons[battler].maxHP;
    struct Sprite *sprite;

    if (sData->menu.detailHpBarSpriteId == SPRITE_NONE)
    {
        sData->menu.detailHpBarSpriteId = CreateHpBarSprite(B_STATUS_DETAIL_HP_BAR_TILE_TAG,
                                                                                21,
                                                                                70);
        if (sData->menu.detailHpBarSpriteId == SPRITE_NONE)
            return;
        CreateHpBarEndcaps(&sData->menu.detailHpBarLeftEndcapSpriteId,
                                        &sData->menu.detailHpBarRightEndcapSpriteId);
    }

    sprite = &gSprites[sData->menu.detailHpBarSpriteId];
    sprite->x = 21;
    sprite->y = 70;
    if (maxHp <= 0)
    {
        sprite->invisible = TRUE;
        if (sData->menu.detailHpBarLeftEndcapSpriteId != SPRITE_NONE)
            gSprites[sData->menu.detailHpBarLeftEndcapSpriteId].invisible = TRUE;
        if (sData->menu.detailHpBarRightEndcapSpriteId != SPRITE_NONE)
            gSprites[sData->menu.detailHpBarRightEndcapSpriteId].invisible = TRUE;
        return;
    }

    UpdateHpBarTilesWithWidth(sData->menu.detailHpBarSpriteId, hp, maxHp,
                                           B_STATUS_DETAIL_HEALTHBAR_PIXELS, B_STATUS_DETAIL_HP_BAR_SEGMENTS);
    sprite->invisible = FALSE;
    UpdateHpBarEndcaps(sData->menu.detailHpBarLeftEndcapSpriteId,
                                    sData->menu.detailHpBarRightEndcapSpriteId,
                                    21, 70,
                                    B_STATUS_DETAIL_HP_BAR_SEGMENTS);
}

static void DetailDestroyStatusIcon(void)
{
    if (sData->menu.detailStatusSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sData->menu.detailStatusSpriteId]);
    sData->menu.detailStatusSpriteId = SPRITE_NONE;
}

static void DetailRefreshStatusIcon(void)
{
    u8 ailment = GetAilmentFromBattler(GetSelectedBattler());

    DetailDestroyStatusIcon();
    if (ailment == AILMENT_NONE || ailment == AILMENT_PKRS)
        return;

    sData->menu.detailStatusSpriteId = CreateSprite(&gSpriteTemplate_StatusIcons,
                                                          46,
                                                          66, 0);
    if (sData->menu.detailStatusSpriteId != SPRITE_NONE)
    {
        StartSpriteAnim(&gSprites[sData->menu.detailStatusSpriteId], ailment - 1);
        gSprites[sData->menu.detailStatusSpriteId].oam.priority = 0;
    }
}

static void DetailDrawLRButtonGlyphs(void)
{
    u8 itemWindowId = sData->menu.detailWindowIds[WIN_DETAIL_ITEM_ABILITY];
    u8 statsWindowId = sData->menu.detailWindowIds[WIN_DETAIL_STATS];
    u8 font = FONT_SHORT_NARROW;
    s16 glyphHeight;
    s16 statsAbsTop;
    s16 itemAbsTop;
    s16 itemY;
    s16 alignedAbsY;
    s16 statsY;
    s16 statsX;
    s16 itemX;
    s16 itemWindowWidth;
    s16 itemWindowHeight;
    s16 rGlyphWidth;

    if (itemWindowId == WINDOW_NONE || statsWindowId == WINDOW_NONE)
        return;

    glyphHeight = 12;//GetKeypadIconHeight(CHAR_L_BUTTON);
    if (glyphHeight == 0)
        glyphHeight = GetFontAttribute(font, FONTATTR_MAX_LETTER_HEIGHT);
    if (glyphHeight <= 0)
        glyphHeight = 8;

    itemWindowWidth = WindowWidthPx(itemWindowId);
    itemWindowHeight = GetWindowAttribute(itemWindowId, WINDOW_HEIGHT) * 8;
    rGlyphWidth = GetKeypadIconWidth(CHAR_R_BUTTON);
    if (rGlyphWidth == 0)
        rGlyphWidth = GetStringWidth(font, sText_BattleStatus_DetailRButtonGlyph, 0);

    itemAbsTop = GetWindowAttribute(itemWindowId, WINDOW_TILEMAP_TOP) * 8;
    statsAbsTop = GetWindowAttribute(statsWindowId, WINDOW_TILEMAP_TOP) * 8;

    itemY = itemWindowHeight - glyphHeight - 1;
    itemY -= 5;
    if (itemY < 1)
        itemY = 1;
    alignedAbsY = itemAbsTop + itemY;
    statsY = alignedAbsY - statsAbsTop;
    statsY -= 1;
    if (statsY < 0)
        statsY = 0;

    statsX = 1;
    itemX = itemWindowWidth - rGlyphWidth - 2;
    if (itemX < 1)
        itemX = 1;
    itemY -= 1;
    if (itemY < 0)
        itemY = 0;

    AddTextPrinterParameterized4(statsWindowId, font, statsX, statsY, 0, 0,
                                 sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW, sText_BattleStatus_DetailLButtonGlyph);
    AddTextPrinterParameterized4(itemWindowId, font, itemX, itemY, 0, 0,
                                 sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW, sText_BattleStatus_DetailRButtonGlyph);
}

static void DetailDestroyTeraTypeIndicator(void)
{
    if (sData->menu.detailTeraTypeSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sData->menu.detailTeraTypeSpriteId]);
    sData->menu.detailTeraTypeSpriteId = SPRITE_NONE;

    FreeSpriteTilesByTag(B_STATUS_DETAIL_TERA_TYPE_TILE_TAG);
}

static void DetailRefreshTeraTypeIndicator(void)
{
    u8 windowId = sData->menu.detailWindowIds[WIN_DETAIL_HEADER];
    struct SpriteSheet sheet;
    struct SpriteTemplate template = sSpriteTemplate_BattleStatusDetailGimmick;
    enum Type teraType;
    const u32 *indicatorData;
    s16 windowLeftPx;
    s16 windowTopPx;

    DetailDestroyTeraTypeIndicator();
    if (windowId == WINDOW_NONE || B_FLAG_TERA_ORB_CHARGED == 0 || !FlagGet(B_FLAG_TERA_ORB_CHARGED))
        return;

    teraType = GetBattlerTeraType(GetSelectedBattler());
    indicatorData = GetTeraIndicatorSpriteSrc(teraType);
    if (indicatorData == NULL)
        return;

    sheet.data = (const u8 *)indicatorData;
    sheet.size = B_STATUS_DETAIL_GIMMICK_GFX_SIZE;
    sheet.tag = B_STATUS_DETAIL_TERA_TYPE_TILE_TAG;
    LoadSpriteSheet(&sheet);

    template.tileTag = B_STATUS_DETAIL_TERA_TYPE_TILE_TAG;
    template.paletteTag = TAG_TERA_INDICATOR_PAL;

    windowLeftPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT) * 8;
    windowTopPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP) * 8;
    sData->menu.detailTeraTypeSpriteId = CreateSprite(&template,
                                                            windowLeftPx + 24 + (B_STATUS_DETAIL_GIMMICK_W / 2),
                                                            windowTopPx + 23, 0);
    if (sData->menu.detailTeraTypeSpriteId != SPRITE_NONE)
        gSprites[sData->menu.detailTeraTypeSpriteId].oam.priority = 0;
}

static const u8 *GetGimmickIndicatorData(enum BattlerId battler, u32 *palTag)
{
    const u32 *indicatorData = GetIndicatorSpriteSrc(battler);

    *palTag = GetIndicatorPalTag(battler);
    if (indicatorData == NULL || *palTag == TAG_NONE)
        return NULL;

    return (const u8 *)indicatorData;
}

static void DetailDestroyGimmickIndicator(void)
{
    if (sData->menu.detailGimmickSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sData->menu.detailGimmickSpriteId]);
    sData->menu.detailGimmickSpriteId = SPRITE_NONE;

    FreeSpriteTilesByTag(B_STATUS_DETAIL_GIMMICK_TILE_TAG);
}

static void DetailRefreshGimmickIndicator(void)
{
    u8 windowId = sData->menu.detailWindowIds[WIN_DETAIL_HEADER];
    const u8 *indicatorData;
    u32 palTag;
    struct SpriteTemplate template = sSpriteTemplate_BattleStatusDetailGimmick;
    struct SpriteSheet sheet;
    s16 windowLeftPx;
    s16 windowTopPx;
    s16 indicatorLeftPx;
    s16 indicatorTopPx;

    DetailDestroyGimmickIndicator();
    if (windowId == WINDOW_NONE)
        return;

    indicatorData = GetGimmickIndicatorData(GetSelectedBattler(), &palTag);
    if (indicatorData == NULL || palTag == 0)
        return;

    sheet.data = indicatorData;
    sheet.size = B_STATUS_DETAIL_GIMMICK_GFX_SIZE;
    sheet.tag = B_STATUS_DETAIL_GIMMICK_TILE_TAG;
    LoadSpriteSheet(&sheet);

    template.paletteTag = palTag;
    windowLeftPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT) * 8;
    windowTopPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP) * 8;
    indicatorLeftPx = windowLeftPx + 2;
    indicatorTopPx = windowTopPx + 33;

    sData->menu.detailGimmickSpriteId = CreateSprite(&template,
                                                           indicatorLeftPx + (B_STATUS_DETAIL_GIMMICK_W / 2),
                                                           indicatorTopPx + (B_STATUS_DETAIL_GIMMICK_H / 2), 0);
    if (sData->menu.detailGimmickSpriteId != SPRITE_NONE)
        gSprites[sData->menu.detailGimmickSpriteId].oam.priority = 0;
}

static void DetailRefreshItemAbilityWindow(void)
{
    enum BattlerId battler = GetSelectedBattler();
    u8 windowId = sData->menu.detailWindowIds[WIN_DETAIL_HEADER];
    u8 statsWindowId = sData->menu.detailWindowIds[WIN_DETAIL_STATS];
    const u8 *itemText = sText_BattleStatus_DetailHeldItemValue;
    const u8 *abilityText = sText_BattleStatus_DetailAbilityValue;
    u8 itemFont;
    u8 abilityFont;
    s16 maxValueWidth;

    if (windowId == WINDOW_NONE)
        return;

    if (IsOnPlayerSide(battler))
    {
        enum Item heldItem = gBattleMons[battler].item;
        enum Ability ability = gBattleMons[battler].ability;

        if (heldItem != ITEM_NONE)
            itemText = GetItemName(heldItem);
        if (ability != ABILITY_NONE && ability < ABILITIES_COUNT)
            abilityText = gAbilitiesInfo[ability].name;

        maxValueWidth = (B_STATUS_DETAIL_ITEM_WIN_W * 8) - 6;
        itemFont = DetailGetBestFitSmallFont(itemText, maxValueWidth);
        abilityFont = DetailGetBestFitSmallFont(abilityText, maxValueWidth);

        AddTextPrinterParameterized4(windowId, FONT_SHORT_NARROW, 50, 33, 0, 0, sTextColor_BattleStatus_Default,
                                     TEXT_SKIP_DRAW, sText_BattleStatus_DetailHeldItemLabel);
        AddTextPrinterParameterized4(windowId, itemFont, 50, 43, 0, 0, sTextColor_BattleStatus_Default,
                                     TEXT_SKIP_DRAW, itemText);
        AddTextPrinterParameterized4(windowId, FONT_SHORT_NARROW, 50, 56, 0, 0, sTextColor_BattleStatus_Default,
                                     TEXT_SKIP_DRAW, sText_BattleStatus_DetailAbilityLabel);
        AddTextPrinterParameterized4(windowId, abilityFont, 50, 66, 0, 0, sTextColor_BattleStatus_Default,
                                     TEXT_SKIP_DRAW, abilityText);
    }

    DetailDrawLRButtonGlyphs();
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
    if (statsWindowId != WINDOW_NONE)
    {
        PutWindowTilemap(statsWindowId);
        CopyWindowToVram(statsWindowId, COPYWIN_FULL);
    }
}

static void DetailRefreshHeader(void)
{
    u8 windowId = sData->menu.detailWindowIds[WIN_DETAIL_HEADER];
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

    mon = GetBattlerMon(GetSelectedBattler());
    gender = GetMonGender(mon);
    level = GetMonData(mon, MON_DATA_LEVEL);

    DetailDrawWindowFrame(windowId);
    genderX = WindowWidthPx(windowId) - 2 - B_STATUS_GENDER_W;

    maxLevelText[0] = CHAR_EXTRA_SYMBOL;
    maxLevelText[1] = CHAR_LV_2;
    ConvertIntToDecimalStringN(maxLevelText + 2, 999, STR_CONV_MODE_LEFT_ALIGN, 3);
    levelMaxWidth = GetStringWidth(FONT_SMALL, maxLevelText, 0);
    levelX = genderX - 2 - levelMaxWidth;
    if (levelX < 2)
        levelX = 2;

    GetMonData(GetBattlerMon(GetSelectedBattler()), MON_DATA_NICKNAME, monName);
    maxNameWidth = levelX - 4;
    if (maxNameWidth < 16)
        maxNameWidth = 16;
    nameFont = GetBestFitNameFont(monName, maxNameWidth);
    AddTextPrinterParameterized4(windowId, nameFont, 2, 2, 0, 0, sTextColor_BattleStatus_Default,
                                 TEXT_SKIP_DRAW, monName);
    DetailDestroyGimmickIndicator();
    if (B_FLAG_TERA_ORB_CHARGED != 0
     && FlagGet(B_FLAG_TERA_ORB_CHARGED)
     && IsOnPlayerSide(GetSelectedBattler()))
    {
        AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROWER,
                                     2,
                                     14,
                                     0, 0, sTextColor_BattleStatus_Default,
                                     TEXT_SKIP_DRAW, sText_BattleStatus_DetailTeraTypeLabel);
        DetailRefreshTeraTypeIndicator();
    }
    else
    {
        DetailDestroyTeraTypeIndicator();
    }
    DetailRefreshGimmickIndicator();

    levelText[0] = CHAR_EXTRA_SYMBOL;
    levelText[1] = CHAR_LV_2;
    ConvertIntToDecimalStringN(levelText + 2, level, STR_CONV_MODE_LEFT_ALIGN, 3);

    AddTextPrinterParameterized4(windowId, FONT_SMALL, levelX, 2, 0, 0, sTextColor_BattleStatus_Default,
                                 TEXT_SKIP_DRAW, levelText);

    if (gender == MON_MALE || gender == MON_FEMALE)
    {
        const u8 *colors = (gender == MON_MALE) ? sTextColor_BattleStatus_Male : sTextColor_BattleStatus_Female;

        genderSymbol[0] = (gender == MON_MALE) ? CHAR_MALE : CHAR_FEMALE;
        genderSymbol[1] = EOS;
        AddTextPrinterParameterized4(windowId, FONT_SMALL, genderX, 2, 0, 0,
                                     colors, TEXT_SKIP_DRAW, genderSymbol);
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void DetailRefreshIcon(void)
{
    struct Pokemon *mon;
    u16 species;
    u32 personality;

    if (sData->menu.detailIconSpriteId != SPRITE_NONE)
        FreeAndDestroyMonIconSprite(&gSprites[sData->menu.detailIconSpriteId]);
    sData->menu.detailIconSpriteId = SPRITE_NONE;

    mon = GetBattlerMon(GetSelectedBattler());
    species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG);
    personality = GetMonData(mon, MON_DATA_PERSONALITY);

    if (species == SPECIES_NONE)
        return;

    sData->menu.detailIconSpriteId = CreateMonIcon(species, SpriteCallbackDummy,
                                                         33, 52, 0, personality);
    if (sData->menu.detailIconSpriteId != SPRITE_NONE)
        gSprites[sData->menu.detailIconSpriteId].oam.priority = 0;
}

static void DetailDestroyTypeIcons(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sData->menu.detailTypeIconSpriteIds); i++)
    {
        if (sData->menu.detailTypeIconSpriteIds[i] != SPRITE_NONE)
            DestroySprite(&gSprites[sData->menu.detailTypeIconSpriteIds[i]]);
        sData->menu.detailTypeIconSpriteIds[i] = SPRITE_NONE;
    }
}

static void DetailRefreshTypeIcons(void)
{
    enum BattlerId battler = GetSelectedBattler();
    enum Type type1 = gBattleMons[battler].types[0];
    enum Type type2 = gBattleMons[battler].types[1];
    u8 windowId = sData->menu.detailWindowIds[WIN_DETAIL_HEADER];
    s16 windowLeftPx;
    s16 windowTopPx;
    s16 rightAlignedTypeRightPx;
    s16 type1LeftPx;
    s16 type2LeftPx;
    u8 spriteId;

    DetailDestroyTypeIcons();
    if (windowId == WINDOW_NONE)
        return;

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

    rightAlignedTypeRightPx = windowLeftPx + WindowWidthPx(windowId) - 2;
    type2LeftPx = rightAlignedTypeRightPx - 32;
    type1LeftPx = type2LeftPx - 33;

    spriteId = CreateSprite(&gSpriteTemplate_MoveTypes,
                            type1LeftPx + 16,
                            windowTopPx + 25, 0);
    if (spriteId != SPRITE_NONE)
    {
        StartSpriteAnim(&gSprites[spriteId], type1);
        gSprites[spriteId].oam.paletteNum = gTypesInfo[type1].palette;
        gSprites[spriteId].oam.priority = 0;
        sData->menu.detailTypeIconSpriteIds[0] = spriteId;
    }

    if (type2 == TYPE_MYSTERY || type2 == type1)
        return;

    spriteId = CreateSprite(&gSpriteTemplate_MoveTypes,
                            type2LeftPx + 16,
                            windowTopPx + 25, 0);
    if (spriteId != SPRITE_NONE)
    {
        StartSpriteAnim(&gSprites[spriteId], type2);
        gSprites[spriteId].oam.paletteNum = gTypesInfo[type2].palette;
        gSprites[spriteId].oam.priority = 0;
        sData->menu.detailTypeIconSpriteIds[1] = spriteId;
    }
}

static s16 DetailGetStatRowTextY(u8 row)
{
    s16 y = 15 + row * 9;

    if (row >= 5)
        y += 3;

    return y;
}

static void DetailSetStatPipSpriteGraphic(u8 spriteId, u16 tileTag)
{
    u16 tileStart;

    if (spriteId == SPRITE_NONE)
        return;

    tileStart = GetSpriteTileStartByTag(tileTag);
    if (tileStart == 0xFFFF)
        return;

    gSprites[spriteId].oam.tileNum = tileStart;
}

static void DetailCreateStatPips(void)
{
    u8 windowId = sData->menu.detailWindowIds[WIN_DETAIL_STATS];
    s16 windowLeftPx;
    s16 windowTopPx;
    u8 row, col;

    DetailDestroyStatPips();
    if (windowId == WINDOW_NONE)
        return;

    LoadSpritePaletteInSlot(&(struct SpritePalette){
        .data = gBattleStatusTextPalette,
        .tag = B_STATUS_DETAIL_STAT_PIP_PAL_TAG,
    }, B_STATUS_DETAIL_STAT_PIP_PAL_NUM);
    LoadSpriteSheet(&sSpriteSheet_BattleStatusDetailStatPipDot);
    LoadSpriteSheet(&sSpriteSheet_BattleStatusDetailStatPipUp);
    LoadSpriteSheet(&sSpriteSheet_BattleStatusDetailStatPipDown);

    windowLeftPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT) * 8;
    windowTopPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP) * 8;

    for (row = 0; row < B_STATUS_DETAIL_STAT_ROW_COUNT; row++)
    {
        s16 rowY = windowTopPx + DetailGetStatRowTextY(row) + 8;

        for (col = 0; col < B_STATUS_DETAIL_STAT_PIPS_PER_ROW; col++)
        {
            u8 spriteId = CreateSprite(&sSpriteTemplate_BattleStatusDetailStatPip,
                                       windowLeftPx + 56 + col * 8,
                                       rowY, 0);
            sData->menu.detailStatPipSpriteIds[row][col] = spriteId;
            if (spriteId != SPRITE_NONE)
            {
                gSprites[spriteId].invisible = FALSE;
                gSprites[spriteId].oam.priority = 0;
            }
        }
    }
}

static void DetailDestroyStatPips(void)
{
    u8 row, col;

    for (row = 0; row < B_STATUS_DETAIL_STAT_ROW_COUNT; row++)
    {
        for (col = 0; col < B_STATUS_DETAIL_STAT_PIPS_PER_ROW; col++)
        {
            u8 spriteId = sData->menu.detailStatPipSpriteIds[row][col];

            if (spriteId != SPRITE_NONE)
                DestroySprite(&gSprites[spriteId]);
            sData->menu.detailStatPipSpriteIds[row][col] = SPRITE_NONE;
        }
    }

    FreeSpriteTilesByTag(B_STATUS_DETAIL_STAT_PIP_DOT_TILE_TAG);
    FreeSpriteTilesByTag(B_STATUS_DETAIL_STAT_PIP_UP_TILE_TAG);
    FreeSpriteTilesByTag(B_STATUS_DETAIL_STAT_PIP_DOWN_TILE_TAG);
    FreeSpritePaletteByTag(B_STATUS_DETAIL_STAT_PIP_PAL_TAG);
}

static void DetailRefreshStatPips(void)
{
    enum BattlerId battler = GetSelectedBattler();
    u8 row, col;

    for (row = 0; row < B_STATUS_DETAIL_STAT_ROW_COUNT; row++)
    {
        s8 delta = gBattleMons[battler].statStages[sBattleStatusDetailStatIds[row]] - DEFAULT_STAT_STAGE;
        u8 absDelta = (delta >= 0) ? delta : -delta;
        u16 tileTag = B_STATUS_DETAIL_STAT_PIP_DOT_TILE_TAG;

        if (absDelta > B_STATUS_DETAIL_STAT_PIPS_PER_ROW)
            absDelta = B_STATUS_DETAIL_STAT_PIPS_PER_ROW;

        if (delta > 0)
            tileTag = B_STATUS_DETAIL_STAT_PIP_UP_TILE_TAG;
        else if (delta < 0)
            tileTag = B_STATUS_DETAIL_STAT_PIP_DOWN_TILE_TAG;

        for (col = 0; col < B_STATUS_DETAIL_STAT_PIPS_PER_ROW; col++)
        {
            u8 spriteId = sData->menu.detailStatPipSpriteIds[row][col];
            u16 currentTag = (col < absDelta) ? tileTag : B_STATUS_DETAIL_STAT_PIP_DOT_TILE_TAG;

            DetailSetStatPipSpriteGraphic(spriteId, currentTag);
        }
    }
}

static void DetailCycleBattler(s8 direction)
{
    DetailDestroyGimmickIndicator();
    DetailDestroyTeraTypeIndicator();

    u32 cardCount = gBattlersCount;

    if (direction < 0)
    {
        if (sData->menu.selectedCardIndex == 0)
            sData->menu.selectedCardIndex = cardCount - 1;
        else
            sData->menu.selectedCardIndex--;
    }
    else
    {
        sData->menu.selectedCardIndex++;
        if (sData->menu.selectedCardIndex >= cardCount)
            sData->menu.selectedCardIndex = 0;
    }

    DetailRefreshIcon();
    DetailRefreshHpBar();
    DetailRefreshStatusIcon();
    DetailRefreshTypeIcons();
    DetailRefreshHeader();
    DetailRefreshItemAbilityWindow();
    DetailRefreshStatPips();
    DetailInitEffectsList();
}

static void DetailInitEffectsList(void)
{
    DetailDestroyEffectsScrollbar();
    sData->menu.detailActiveEffectsCount = 0;
    sData->menu.detailEffectsCursor = 0;
    sData->menu.detailEffectsScroll = 0;
    DetailBuildActiveEffects();
    DetailRefreshEffectsSection();
}

static void DetailBuildActiveEffects(void)
{
    DetailBuildActiveEffectsForBattler(GetSelectedBattler(),
                                                    sData->menu.detailActiveEffects,
                                                    &sData->menu.detailActiveEffectsCount);
}

static void DetailBuildActiveEffectsForBattler(enum BattlerId battler, struct BattleStatusEffectEntry *entries, u8 *count)
{
    enum BattleSide side = GetBattlerSide(battler);
    u32 status1 = gBattleMons[battler].status1;
    u32 sideStatuses = gSideStatuses[side];

    if (gBattleWeather & B_WEATHER_SUN_PRIMAL)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_EXTREMELY_HARSH_SUNLIGHT, entries, count);
    else if (gBattleWeather & B_WEATHER_SUN)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_HARSH_SUNLIGHT, entries, count);

    if (gBattleWeather & B_WEATHER_RAIN_PRIMAL)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_HEAVY_RAIN, entries, count);
    else if (gBattleWeather & B_WEATHER_RAIN)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_RAIN, entries, count);

    if (gBattleWeather & B_WEATHER_SANDSTORM)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_SANDSTORM, entries, count);
    if (gBattleWeather & B_WEATHER_SNOW)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_SNOW, entries, count);
    if (gBattleWeather & B_WEATHER_STRONG_WINDS)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_STRONG_WINDS, entries, count);
    if (gBattleWeather & B_WEATHER_FOG)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_FOG, entries, count);

    if (gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_ELECTRIC_TERRAIN, entries, count);
    if (gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_GRASSY_TERRAIN, entries, count);
    if (gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_MISTY_TERRAIN, entries, count);
    if (gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_PSYCHIC_TERRAIN, entries, count);
    if (gFieldStatuses & STATUS_FIELD_TRICK_ROOM)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_TRICK_ROOM, entries, count);
    if (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_MAGIC_ROOM, entries, count);
    if (gFieldStatuses & STATUS_FIELD_WONDER_ROOM)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_WONDER_ROOM, entries, count);
    if (gFieldStatuses & STATUS_FIELD_GRAVITY)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_GRAVITY, entries, count);
    if (gFieldStatuses & STATUS_FIELD_MUDSPORT)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_MUD_SPORT, entries, count);
    if (gFieldStatuses & STATUS_FIELD_WATERSPORT)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_WATER_SPORT, entries, count);
    if (gFieldStatuses & STATUS_FIELD_FAIRY_LOCK)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_FAIRY_LOCK, entries, count);

    if (sideStatuses & SIDE_STATUS_MIST)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_MIST, entries, count);
    if (sideStatuses & SIDE_STATUS_SAFEGUARD)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_SAFEGUARD, entries, count);
    if (sideStatuses & SIDE_STATUS_LUCKY_CHANT)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_LUCKY_CHANT, entries, count);
    if (sideStatuses & SIDE_STATUS_TAILWIND)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_TAILWIND, entries, count);
    if (sideStatuses & SIDE_STATUS_LIGHTSCREEN)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_LIGHT_SCREEN, entries, count);
    if (sideStatuses & SIDE_STATUS_REFLECT)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_REFLECT, entries, count);
    if (sideStatuses & SIDE_STATUS_AURORA_VEIL)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_AURORA_VEIL, entries, count);
    if (sideStatuses & SIDE_STATUS_RAINBOW)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_RAINBOW, entries, count);
    if (sideStatuses & SIDE_STATUS_SWAMP)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_SWAMP, entries, count);
    if (sideStatuses & SIDE_STATUS_SEA_OF_FIRE)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_SEA_OF_FIRE, entries, count);
    if (sideStatuses & SIDE_STATUS_DAMAGE_NON_TYPES)
    {
        switch (gSideTimers[side].damageNonTypesType)
        {
        case TYPE_FIRE:
            DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_G_MAX_WILDFIRE, entries, count);
            break;
        case TYPE_ROCK:
            DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_G_MAX_VOLCALITH, entries, count);
            break;
        case TYPE_GRASS:
            DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_G_MAX_VINE_LASH, entries, count);
            break;
        case TYPE_WATER:
            DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_G_MAX_CANNONADE, entries, count);
            break;
        default:
            break;
        }
    }

    if (IsHazardOnSide(side, HAZARDS_STEALTH_ROCK))
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_STEALTH_ROCK, entries, count);
    if (IsHazardOnSide(side, HAZARDS_SPIKES))
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_SPIKES, entries, count);
    if (IsHazardOnSide(side, HAZARDS_TOXIC_SPIKES))
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_TOXIC_SPIKES, entries, count);
    if (IsHazardOnSide(side, HAZARDS_STICKY_WEB))
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_STICKY_WEB, entries, count);

    if (status1 & STATUS1_TOXIC_POISON)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_BADLY_POISONED, entries, count);
    else if (status1 & STATUS1_POISON)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_POISONED, entries, count);

    if (status1 & STATUS1_PARALYSIS)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_PARALYZED, entries, count);
    if (status1 & STATUS1_BURN)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_BURNED, entries, count);
    if (status1 & STATUS1_FROSTBITE)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_FROSTBITE, entries, count);

    if (gBattleMons[battler].volatiles.focusEnergy
     || gBattleMons[battler].volatiles.dragonCheer
     || gBattleMons[battler].volatiles.bonusCritStages > 0)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_CRITICAL_HIT_BOOST, entries, count);
    if (gBattleMons[battler].volatiles.confusionTurns > 0
     || gBattleMons[battler].volatiles.infiniteConfusion)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_CONFUSION, entries, count);
    if (gBattleMons[battler].volatiles.infatuation)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_INFATUATION, entries, count);
    if (gBattleMons[battler].volatiles.nightmare)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_NIGHTMARE, entries, count);
    if (gBattleMons[battler].volatiles.yawn)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_DROWSY, entries, count);
    if (gBattleMons[battler].volatiles.encoreTimer > 0)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_ENCORE, entries, count);
    if (gBattleMons[battler].volatiles.torment)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_TORMENT, entries, count);
    if (gBattleMons[battler].volatiles.grudge)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_GRUDGE, entries, count);
    if (gBattleMons[battler].volatiles.healBlock)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_HEALING_PREVENTED, entries, count);
    if (gBattleMons[battler].volatiles.foresight || gBattleMons[battler].volatiles.miracleEye)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_IDENTIFIED, entries, count);
    if (gBattleMons[battler].volatiles.disableTimer > 0)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_MOVE_DISABLED, entries, count);
    if (gBattleMons[battler].volatiles.escapePrevention || gBattleMons[battler].volatiles.noRetreat)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_CANT_ESCAPE, entries, count);
    if (gBattleMons[battler].volatiles.lockOn)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_LOCK_ON, entries, count);
    if (gBattleMons[battler].volatiles.embargo)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_EMBARGO, entries, count);
    if (gBattleMons[battler].volatiles.chargeTimer > 0)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_CHARGE, entries, count);
    if (gBattleMons[battler].volatiles.tauntTimer > 0)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_TAUNT, entries, count);
    if (gBattleMons[battler].volatiles.telekinesis)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_TELEKINESIS, entries, count);
    if (gBattleMons[battler].volatiles.magnetRiseTimer)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_MAGNET_RISE, entries, count);
    if (gBattleStruct->wish[battler].counter > 0)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_WISH, entries, count);
    if (gBattleMons[battler].volatiles.root)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_INGRAIN, entries, count);
    if (gBattleMons[battler].volatiles.cursed)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_CURSE, entries, count);
    if (gBattleMons[battler].volatiles.destinyBond)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_DESTINY_BOND, entries, count);
    if (gBattleMons[battler].volatiles.wrapped)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_BOUND, entries, count);
    if (gBattleMons[battler].volatiles.bideTurns > 0)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_BIDE, entries, count);
    if (gBattleStruct->futureSight[battler].counter > 0)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_FUTURE_ATTACK, entries, count);
    if (gBattleMons[battler].volatiles.uproarTurns > 0)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_UPROAR, entries, count);
    if (gBattleMons[battler].volatiles.aquaRing)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_AQUA_RING, entries, count);
    if (gBattleMons[battler].volatiles.autotomizeCount > 0)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_AUTOTOMIZE, entries, count);
    if (gBattleMons[battler].volatiles.smackDown)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_SMACK_DOWN, entries, count);
    if (gBattleMons[battler].volatiles.throatChopTimer > 0)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_THROAT_CHOP, entries, count);
    if (gBattleMons[battler].volatiles.laserFocusTimer > 0)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_LASER_FOCUS, entries, count);
    if (gBattleMons[battler].volatiles.tarShot)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_TAR_SHOT, entries, count);
    if (gBattleMons[battler].volatiles.octolock)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_OCTOLOCK, entries, count);
    if (gBattleMons[battler].volatiles.glaiveRush)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_FIXATED, entries, count);
    if (gBattleMons[battler].volatiles.powerTrick)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_STANCE_SWAP, entries, count);
    if (gBattleMons[battler].volatiles.slowStartTimer > 0)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_SLOW_START, entries, count);
    if (gBattleMons[battler].volatiles.saltCure)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_SALT_CURE, entries, count);
    if (gBattleMons[battler].volatiles.syrupBomb || gBattleMons[battler].volatiles.syrupBombTimer > 0)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_SYRUPY, entries, count);
    if (gBattleMons[battler].volatiles.rampageTurns > 0)
        DetailTryAddActiveEffect(battler, side, B_STATUS_EFFECT_RAMPAGING, entries, count);
}

static void DetailTryAddActiveEffect(enum BattlerId battler, enum BattleSide side, enum BattleStatusEffectId effectId,
                                                  struct BattleStatusEffectEntry *entries, u8 *count)
{
    u8 i;
    struct BattleStatusEffectEntry entry;

    if (effectId >= B_STATUS_EFFECT_COUNT)
        return;

    for (i = 0; i < *count; i++)
    {
        if (entries[i].effectId == effectId)
            return;
    }

    if (*count >= B_STATUS_DETAIL_MAX_ACTIVE_EFFECTS)
        return;

    DetailInitEffectEntry(&entry, effectId, side);

    switch (effectId)
    {
    case B_STATUS_EFFECT_HARSH_SUNLIGHT:
    case B_STATUS_EFFECT_RAIN:
    case B_STATUS_EFFECT_SANDSTORM:
    case B_STATUS_EFFECT_SNOW:
    case B_STATUS_EFFECT_FOG:
        if (gBattleStruct->weatherDuration > 0)
        {
            u16 baseTotal = 5;
            u16 actualTotal = gBattleStruct->weatherDurationTotal;
            u16 extendedTotal = (actualTotal > baseTotal) ? actualTotal : 0;
            DetailSetDuration(&entry, gBattleStruct->weatherDuration, baseTotal, extendedTotal, gBattleStruct->weatherSide, TRUE);
        }
        break;
    case B_STATUS_EFFECT_ELECTRIC_TERRAIN:
    case B_STATUS_EFFECT_GRASSY_TERRAIN:
    case B_STATUS_EFFECT_MISTY_TERRAIN:
    case B_STATUS_EFFECT_PSYCHIC_TERRAIN:
        if (gFieldTimers.terrainTimer > 0)
        {
            u16 baseTotal = 5;
            u16 actualTotal = gFieldTimers.terrainTimerTotal;
            u16 extendedTotal = (actualTotal > baseTotal) ? actualTotal : 0;
            DetailSetDuration(&entry, gFieldTimers.terrainTimer, baseTotal, extendedTotal, gFieldTimers.terrainSide, TRUE);
        }
        break;
    case B_STATUS_EFFECT_TRICK_ROOM:
        DetailSetDuration(&entry, gFieldTimers.trickRoomTimer, 5, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_MAGIC_ROOM:
        DetailSetDuration(&entry, gFieldTimers.magicRoomTimer, 5, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_WONDER_ROOM:
        DetailSetDuration(&entry, gFieldTimers.wonderRoomTimer, 5, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_GRAVITY:
        DetailSetDuration(&entry, gFieldTimers.gravityTimer, 5, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_MUD_SPORT:
        DetailSetDuration(&entry, gFieldTimers.mudSportTimer, 5, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_WATER_SPORT:
        DetailSetDuration(&entry, gFieldTimers.waterSportTimer, 5, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_FAIRY_LOCK:
        DetailSetDuration(&entry, gFieldTimers.fairyLockTimer, 2, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_MIST:
        DetailSetDuration(&entry, gSideTimers[side].mistTimer, 5, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_SAFEGUARD:
        DetailSetDuration(&entry, gSideTimers[side].safeguardTimer, 5, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_LUCKY_CHANT:
        DetailSetDuration(&entry, gSideTimers[side].luckyChantTimer, 5, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_TAILWIND:
        DetailSetDuration(&entry, gSideTimers[side].tailwindTimer,
                                       (GetConfig(B_TAILWIND_TURNS) >= GEN_5 ? 4 : 3), 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_LIGHT_SCREEN:
        if (gSideTimers[side].lightscreenTimer > 0)
        {
            u16 baseTotal = 5;
            u16 actualTotal = gSideTimers[side].lightscreenTimerTotal;
            u16 extendedTotal = (actualTotal > baseTotal) ? actualTotal : 0;
            DetailSetDuration(&entry, gSideTimers[side].lightscreenTimer, baseTotal, extendedTotal, side, TRUE);
        }
        break;
    case B_STATUS_EFFECT_REFLECT:
        if (gSideTimers[side].reflectTimer > 0)
        {
            u16 baseTotal = 5;
            u16 actualTotal = gSideTimers[side].reflectTimerTotal;
            u16 extendedTotal = (actualTotal > baseTotal) ? actualTotal : 0;
            DetailSetDuration(&entry, gSideTimers[side].reflectTimer, baseTotal, extendedTotal, side, TRUE);
        }
        break;
    case B_STATUS_EFFECT_AURORA_VEIL:
        if (gSideTimers[side].auroraVeilTimer > 0)
        {
            u16 baseTotal = 5;
            u16 actualTotal = gSideTimers[side].auroraVeilTimerTotal;
            u16 extendedTotal = (actualTotal > baseTotal) ? actualTotal : 0;
            DetailSetDuration(&entry, gSideTimers[side].auroraVeilTimer, baseTotal, extendedTotal, side, TRUE);
        }
        break;
    case B_STATUS_EFFECT_RAINBOW:
        DetailSetDuration(&entry, gSideTimers[side].rainbowTimer, 4, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_SWAMP:
        DetailSetDuration(&entry, gSideTimers[side].swampTimer, 4, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_SEA_OF_FIRE:
        DetailSetDuration(&entry, gSideTimers[side].seaOfFireTimer, 4, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_G_MAX_WILDFIRE:
    case B_STATUS_EFFECT_G_MAX_VOLCALITH:
    case B_STATUS_EFFECT_G_MAX_VINE_LASH:
    case B_STATUS_EFFECT_G_MAX_CANNONADE:
        DetailSetDuration(&entry, gSideTimers[side].damageNonTypesTimer, 5, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_SPIKES:
        entry.stackCount = gSideTimers[side].spikesAmount;
        break;
    case B_STATUS_EFFECT_TOXIC_SPIKES:
        entry.stackCount = gSideTimers[side].toxicSpikesAmount;
        break;
    case B_STATUS_EFFECT_CONFUSION:
        DetailSetDurationUnknownTotal(&entry, gBattleMons[battler].volatiles.confusionTurns,
                                                   gBattleMons[battler].volatiles.confusionTurns, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_DROWSY:
        DetailSetDuration(&entry, gBattleMons[battler].volatiles.yawn, 2, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_ENCORE:
        DetailSetDuration(&entry, gBattleMons[battler].volatiles.encoreTimer,
                                       (B_ENCORE_TIMER > 1 ? B_ENCORE_TIMER - 1 : 1), 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_HEALING_PREVENTED:
        DetailSetDuration(&entry, gBattleMons[battler].volatiles.healBlockTimer, B_HEAL_BLOCK_TIMER, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_MOVE_DISABLED:
        DetailSetDurationUnknownTotal(&entry, gBattleMons[battler].volatiles.disableTimer,
                                                   gBattleMons[battler].volatiles.disableTimer, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_EMBARGO:
        DetailSetDuration(&entry, gBattleMons[battler].volatiles.embargoTimer, B_EMBARGO_TIMER, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_CHARGE:
        DetailSetDurationUnknownTotal(&entry, gBattleMons[battler].volatiles.chargeTimer,
                                                   gBattleMons[battler].volatiles.chargeTimer, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_TAUNT:
        DetailSetDurationUnknownTotal(&entry, gBattleMons[battler].volatiles.tauntTimer,
                                                   gBattleMons[battler].volatiles.tauntTimer, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_TELEKINESIS:
        DetailSetDuration(&entry, gBattleMons[battler].volatiles.telekinesisTimer, B_TELEKINESIS_TIMER, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_MAGNET_RISE:
        DetailSetDuration(&entry, gBattleMons[battler].volatiles.magnetRiseTimer, B_MAGNET_RISE_TIMER, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_WISH:
        DetailSetDuration(&entry, gBattleStruct->wish[battler].counter, 2, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_BOUND:
        DetailSetDurationUnknownTotal(&entry, gBattleMons[battler].volatiles.wrapTurns,
                                                   gBattleMons[battler].volatiles.wrapTurns, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_BIDE:
        DetailSetDuration(&entry, gBattleMons[battler].volatiles.bideTurns, 2, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_FUTURE_ATTACK:
        DetailSetDuration(&entry, gBattleStruct->futureSight[battler].counter, 3, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_UPROAR:
        if (B_UPROAR_TURNS >= GEN_5)
            DetailSetDuration(&entry, gBattleMons[battler].volatiles.uproarTurns,
                                           (B_UPROAR_TURN_COUNT >= 2 ? B_UPROAR_TURN_COUNT - 2 : gBattleMons[battler].volatiles.uproarTurns),
                                           0, side, FALSE);
        else
            DetailSetDurationUnknownTotal(&entry, gBattleMons[battler].volatiles.uproarTurns,
                                                       gBattleMons[battler].volatiles.uproarTurns, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_THROAT_CHOP:
        DetailSetDuration(&entry, gBattleMons[battler].volatiles.throatChopTimer, B_THROAT_CHOP_TIMER, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_LASER_FOCUS:
        DetailSetDuration(&entry, gBattleMons[battler].volatiles.laserFocusTimer, B_LASER_FOCUS_TIMER, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_SLOW_START:
        DetailSetDuration(&entry, gBattleMons[battler].volatiles.slowStartTimer, B_SLOW_START_TIMER, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_SYRUPY:
        DetailSetDuration(&entry, gBattleMons[battler].volatiles.syrupBombTimer, B_SYRUP_BOMB_TIMER, 0, side, FALSE);
        break;
    case B_STATUS_EFFECT_RAMPAGING:
        DetailSetDurationUnknownTotal(&entry, gBattleMons[battler].volatiles.rampageTurns,
                                                   gBattleMons[battler].volatiles.rampageTurns, 0, side, FALSE);
        break;
    default:
        break;
    }

    entries[(*count)++] = entry;
}

static void DetailInitEffectEntry(struct BattleStatusEffectEntry *entry, enum BattleStatusEffectId effectId, enum BattleSide side)
{
    entry->effectId = effectId;
    entry->durationRemaining = 0;
    entry->baseTotalDuration = 0;
    entry->extendedTotalDuration = 0;
    entry->setterSide = side;
    entry->flags = 0;
    entry->stackCount = 0;
}

static void DetailSetDuration(struct BattleStatusEffectEntry *entry, u16 remaining, u16 baseTotal, u16 extendedTotal,
                                           enum BattleSide setterSide, bool8 isExtendable)
{
    if (remaining == 0)
        return;

    if (baseTotal == 0)
        baseTotal = remaining;

    entry->durationRemaining = remaining;
    entry->baseTotalDuration = baseTotal;
    entry->extendedTotalDuration = extendedTotal;
    entry->setterSide = setterSide;
    entry->flags |= B_STATUS_EFFECT_FLAG_HAS_DURATION;
    entry->flags |= B_STATUS_EFFECT_FLAG_TOTAL_KNOWN;
    if (isExtendable)
    {
        entry->flags |= B_STATUS_EFFECT_FLAG_EXTENDABLE;
        if (setterSide == B_SIDE_PLAYER)
            entry->flags |= B_STATUS_EFFECT_FLAG_EXTENDER_KNOWN;
    }
}

static void DetailSetDurationUnknownTotal(struct BattleStatusEffectEntry *entry, u16 remaining, u16 baseTotal, u16 extendedTotal,
                                                       enum BattleSide setterSide, bool8 isExtendable)
{
    DetailSetDuration(entry, remaining, baseTotal, extendedTotal, setterSide, isExtendable);
    entry->flags &= ~B_STATUS_EFFECT_FLAG_TOTAL_KNOWN;
}

static bool8 DetailGetDisplayedDuration(const struct BattleStatusEffectEntry *entry, enum BattleSide viewerSide,
                                                     u16 *outRemaining, u16 *outTotal)
{
    u16 actualTotal;
    u16 displayedTotal;
    u16 remaining;
    u16 elapsed;

    if (!(entry->flags & B_STATUS_EFFECT_FLAG_HAS_DURATION))
        return FALSE;

    if (!(entry->flags & B_STATUS_EFFECT_FLAG_TOTAL_KNOWN))
        return FALSE;

    if (entry->baseTotalDuration == 0)
        return FALSE;

    actualTotal = entry->extendedTotalDuration ? entry->extendedTotalDuration : entry->baseTotalDuration;
    if (actualTotal == 0)
        return FALSE;

    remaining = entry->durationRemaining;
    displayedTotal = actualTotal;

    if ((entry->flags & B_STATUS_EFFECT_FLAG_EXTENDABLE)
     && entry->setterSide != viewerSide
     && !(entry->flags & B_STATUS_EFFECT_FLAG_EXTENDER_KNOWN)
     && actualTotal > entry->baseTotalDuration)
    {
        elapsed = (actualTotal > remaining) ? actualTotal - remaining : 0;
        if (elapsed < entry->baseTotalDuration)
        {
            displayedTotal = entry->baseTotalDuration;
            remaining = (entry->baseTotalDuration > elapsed) ? entry->baseTotalDuration - elapsed : 0;
        }
    }

    *outRemaining = remaining;
    *outTotal = displayedTotal;
    return TRUE;
}

static void DetailBuildTurnFractionText(u8 *dst, u16 remaining, u16 total)
{
    u8 *str = dst;

    str = ConvertIntToDecimalStringN(str, remaining, STR_CONV_MODE_LEFT_ALIGN, 2);
    *(str++) = CHAR_SLASH;
    str = ConvertIntToDecimalStringN(str, total, STR_CONV_MODE_LEFT_ALIGN, 2);
    *str = EOS;
}

static void DetailCopyTextToFit(u8 *dst, const u8 *src, u8 fontId, s16 maxWidth)
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

static const struct BattleStatusEffectData *GetEffectData(enum BattleStatusEffectId effectId)
{
    if (effectId >= B_STATUS_EFFECT_COUNT)
        return NULL;

    return &sBattleStatusEffects[effectId];
}

static bool8 DetailTryMoveEffectCursor(s8 direction)
{
    if (sData->menu.detailActiveEffectsCount == 0)
        return FALSE;

    if (direction < 0)
    {
        if (sData->menu.detailEffectsCursor == 0)
            return FALSE;
        sData->menu.detailEffectsCursor--;
    }
    else if (direction > 0)
    {
        if (sData->menu.detailEffectsCursor + 1 >= sData->menu.detailActiveEffectsCount)
            return FALSE;
        sData->menu.detailEffectsCursor++;
    }
    else
    {
        return FALSE;
    }

    if (sData->menu.detailEffectsCursor < sData->menu.detailEffectsScroll)
        sData->menu.detailEffectsScroll = sData->menu.detailEffectsCursor;
    else if (sData->menu.detailEffectsCursor >= sData->menu.detailEffectsScroll + B_STATUS_DETAIL_EFFECTS_VISIBLE_ROWS)
        sData->menu.detailEffectsScroll = sData->menu.detailEffectsCursor - B_STATUS_DETAIL_EFFECTS_VISIBLE_ROWS + 1;

    return TRUE;
}

static void DetailRefreshEffectsWindow(void)
{
    u8 windowId = sData->menu.detailWindowIds[WIN_DETAIL_EFFECTS];
    u8 row;
    enum BattleSide viewerSide = B_SIDE_PLAYER;
    u8 fractionFont = FONT_SMALL_NARROWER;
    u8 fractionYOffset = 0;

    if (windowId == WINDOW_NONE)
        return;

    if (GetFontAttribute(fractionFont, FONTATTR_MAX_LETTER_HEIGHT) < 12)
    {
        fractionYOffset = (12 - GetFontAttribute(fractionFont, FONTATTR_MAX_LETTER_HEIGHT)) / 2;
    }

    DetailDrawWindowFrame(windowId);
    AddTextPrinterParameterized4(windowId, FONT_NARROWER, 2, 2, 0, 0, sTextColor_BattleStatus_Default,
                                 TEXT_SKIP_DRAW, sText_BattleStatus_DetailEffectsHeader);

    if (sData->menu.detailActiveEffectsCount != 0)
    {
        for (row = 0; row < B_STATUS_DETAIL_EFFECTS_VISIBLE_ROWS; row++)
        {
            u16 index = sData->menu.detailEffectsScroll + row;
            const struct BattleStatusEffectEntry *entry;
            enum BattleStatusEffectId effectId;
            const struct BattleStatusEffectData *effectData;
            u8 y;
            u16 remaining;
            u16 total;
            bool8 hasFraction;

            if (index >= sData->menu.detailActiveEffectsCount)
                break;

            entry = &sData->menu.detailActiveEffects[index];
            effectId = entry->effectId;
            effectData = GetEffectData(effectId);
            if (effectData == NULL || effectData->name == NULL)
                continue;

            y = 16 + row * 12;
            if (index == sData->menu.detailEffectsCursor)
            {
                AddTextPrinterParameterized4(windowId, FONT_SMALL_NARROWER, 2, y, 0, 0,
                                             sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW, gText_SelectorArrow2);
            }
            hasFraction = DetailGetDisplayedDuration(entry, viewerSide, &remaining, &total);
            if (hasFraction)
            {
                u8 fractionText[24];
                u8 nameBuffer[64];
                u16 fractionWidth;
                s16 fractionX;
                s16 maxNameWidth;
                u8 fractionY;
                u16 windowWidth = WindowWidthPx(windowId);

                DetailBuildTurnFractionText(fractionText, remaining, total);
                fractionWidth = GetStringWidth(fractionFont, fractionText, 0);
                fractionX = windowWidth - 6
                            - 2 - fractionWidth;
                if (fractionX < 10)
                    fractionX = 10;

                maxNameWidth = fractionX - 10 - 2;
                if (maxNameWidth < 0)
                    maxNameWidth = 0;
                DetailCopyTextToFit(nameBuffer, effectData->name, FONT_SHORT_NARROWER, maxNameWidth);

                AddTextPrinterParameterized4(windowId, FONT_SHORT_NARROWER, 10, y, 0, 0,
                                             sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW, nameBuffer);
                fractionY = y + fractionYOffset;
                AddTextPrinterParameterized4(windowId, fractionFont, fractionX, fractionY, 0, 0,
                                             sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW, fractionText);
            }
            else
            {
                if (entry->stackCount > 0)
                {
                    u8 stackText[8];
                    u8 nameBuffer[64];
                    u8 *stackPtr = stackText;
                    u16 stackWidth;
                    s16 stackX;
                    s16 maxNameWidth;
                    u8 stackY;
                    u16 windowWidth = WindowWidthPx(windowId);

                    *(stackPtr++) = CHAR_PLUS;
                    stackPtr = ConvertIntToDecimalStringN(stackPtr, entry->stackCount, STR_CONV_MODE_LEFT_ALIGN, 1);
                    *stackPtr = EOS;

                    stackWidth = GetStringWidth(fractionFont, stackText, 0);
                    stackX = windowWidth - 6
                           - 2 - stackWidth;
                    if (stackX < 10)
                        stackX = 10;

                    maxNameWidth = stackX - 10 - 2;
                    if (maxNameWidth < 0)
                        maxNameWidth = 0;
                    DetailCopyTextToFit(nameBuffer, effectData->name, FONT_SHORT_NARROWER, maxNameWidth);

                    AddTextPrinterParameterized4(windowId, FONT_SHORT_NARROWER, 10, y, 0, 0,
                                                 sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW, nameBuffer);
                    stackY = y + fractionYOffset;
                    AddTextPrinterParameterized4(windowId, fractionFont, stackX, stackY, 0, 0,
                                                 sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW, stackText);
                }
                else
                {
                    AddTextPrinterParameterized4(windowId, FONT_SHORT_NARROWER, 10, y, 0, 0,
                                                 sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW, effectData->name);
                }
            }
        }
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
    DetailRefreshEffectsScrollbar();
    DetailUpdateEffectsCursor();
}

static void DetailRefreshEffectsScrollbar(void)
{
    u8 windowId = sData->menu.detailWindowIds[WIN_DETAIL_EFFECTS];
    s16 windowLeftPx;
    s16 windowTopPx;
    s16 scrollbarMinY;
    s16 scrollbarMaxY;
    s16 scrollbarX;
    u16 maxScroll;
    u8 spriteId;

    if (windowId == WINDOW_NONE || sData->menu.detailActiveEffectsCount <= B_STATUS_DETAIL_EFFECTS_VISIBLE_ROWS)
    {
        DetailUpdateScrollbarLane(FALSE);
        DetailDestroyEffectsScrollbar();
        return;
    }

    DetailUpdateScrollbarLane(TRUE);

    windowLeftPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT) * 8;
    windowTopPx = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP) * 8;
    scrollbarX = windowLeftPx + WindowWidthPx(windowId) - 6;
    scrollbarMinY = windowTopPx + 16 + 7;
    scrollbarMaxY = scrollbarMinY + 3 + (B_STATUS_DETAIL_EFFECTS_VISIBLE_ROWS - 1) * 12;
    maxScroll = sData->menu.detailActiveEffectsCount - B_STATUS_DETAIL_EFFECTS_VISIBLE_ROWS;
    if (sData->menu.detailEffectsScroll > maxScroll)
        sData->menu.detailEffectsScroll = maxScroll;

    if (sData->menu.detailEffectsScrollbarSpriteId == SPRITE_NONE)
    {
        spriteId = CreateSprite(&sSpriteTemplate_BattleStatusDetailEffectsScrollbar, scrollbarX, scrollbarMinY, 0);
        if (spriteId == SPRITE_NONE)
            return;
        sData->menu.detailEffectsScrollbarSpriteId = spriteId;
        gSprites[spriteId].oam.priority = 0;
    }

    spriteId = sData->menu.detailEffectsScrollbarSpriteId;
    gSprites[spriteId].x = scrollbarX;
    gSprites[spriteId].y = scrollbarMinY + (sData->menu.detailEffectsScroll * (scrollbarMaxY - scrollbarMinY) + (maxScroll / 2)) / maxScroll;
    gSprites[spriteId].invisible = FALSE;
}

static void DetailUpdateScrollbarLane(bool8 hasScrollbar)
{
    u8 windowId = sData->menu.detailWindowIds[WIN_DETAIL_EFFECTS];
    s16 laneX;
    s16 laneYStart;
    s16 laneTileCount;
    s16 i;

    if (windowId == WINDOW_NONE)
        return;

    laneX = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT)
            + (WindowWidthPx(windowId) - 6) / 8;
    laneYStart = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP) + (16 / 8);
    laneTileCount = ((B_STATUS_DETAIL_EFFECTS_VISIBLE_ROWS * 12) + 7) / 8;
    laneTileCount++;
    laneYStart++;
    laneTileCount -= 2;
    if (laneTileCount <= 0)
        return;

    if (laneX < 0 || laneX >= B_STATUS_TILEMAP_WIDTH)
        return;

    for (i = 0; i < laneTileCount; i++)
    {
        s16 tileY = laneYStart + i;
        u16 index;

        if (tileY < 0 || tileY >= B_STATUS_TILEMAP_HEIGHT)
            continue;

        index = tileY * B_STATUS_TILEMAP_WIDTH + laneX;
        if (hasScrollbar)
            sData->bg1Tilemap[index] = (sData->bg1Tilemap[index] & 0xFC00) | B_STATUS_BG_TILE_SCROLLBAR_LANE;
        else
            sData->bg1Tilemap[index] = sBattleStatusMenuDetailsBaseTilemap[index];
    }

    if (laneTileCount > 0)
    {
        s16 topTileY = laneYStart - 1;
        s16 bottomTileY = laneYStart + laneTileCount;
        u16 index;

        if (topTileY >= 0 && topTileY < B_STATUS_TILEMAP_HEIGHT)
        {
            index = topTileY * B_STATUS_TILEMAP_WIDTH + laneX;
            if (hasScrollbar)
                sData->bg1Tilemap[index] = (sData->bg1Tilemap[index] & 0xFC00) | B_STATUS_BG_TILE_SCROLLBAR_TOP;
            else
                sData->bg1Tilemap[index] = sBattleStatusMenuDetailsBaseTilemap[index];
        }

        if (bottomTileY >= 0 && bottomTileY < B_STATUS_TILEMAP_HEIGHT)
        {
            index = bottomTileY * B_STATUS_TILEMAP_WIDTH + laneX;
            if (hasScrollbar)
                sData->bg1Tilemap[index] = (sData->bg1Tilemap[index] & 0xFC00) | B_STATUS_BG_TILE_SCROLLBAR_BOTTOM;
            else
                sData->bg1Tilemap[index] = sBattleStatusMenuDetailsBaseTilemap[index];
        }
    }

    CopyBgTilemapBufferToVram(B_STATUS_BACKDROP_BG);
}

static void DetailSetDescriptionPlaceholder(enum BattleStatusEffectId effectId)
{
    gStringVar1[0] = EOS;
    switch (effectId)
    {
    case B_STATUS_EFFECT_ENCORE:
        StringCopy(gStringVar1, COMPOUND_STRING("its last move"));
        break;
    case B_STATUS_EFFECT_MOVE_DISABLED:
        StringCopy(gStringVar1, COMPOUND_STRING("A move"));
        break;
    case B_STATUS_EFFECT_G_MAX_WILDFIRE:
        StringCopy(gStringVar1, COMPOUND_STRING("Fire"));
        break;
    case B_STATUS_EFFECT_G_MAX_VOLCALITH:
        StringCopy(gStringVar1, COMPOUND_STRING("Rock"));
        break;
    case B_STATUS_EFFECT_G_MAX_VINE_LASH:
        StringCopy(gStringVar1, COMPOUND_STRING("Grass"));
        break;
    case B_STATUS_EFFECT_G_MAX_CANNONADE:
        StringCopy(gStringVar1, COMPOUND_STRING("Water"));
        break;
    default:
        break;
    }
}

static void DetailFormatDescriptionText(enum BattleStatusEffectId effectId, u8 *dst)
{
    const struct BattleStatusEffectData *effectData = GetEffectData(effectId);

    if (effectData == NULL || effectData->description == NULL)
    {
        dst[0] = EOS;
        return;
    }

    DetailSetDescriptionPlaceholder(effectId);
    StringExpandPlaceholders(dst, effectData->description);
}

static void DetailClampTextLines(u8 *text, u8 maxLines)
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

static void DetailRefreshDescriptionWindow(void)
{
    u8 windowId = sData->menu.detailWindowIds[WIN_DETAIL_DESCRIPTION];
    u8 descFont = FONT_SMALL_NARROWER;
    u8 maxLines;
    u8 lineHeight;
    u16 windowHeightPx;
    u16 availableHeight;
    u32 wrapWidth;
    u8 *end;

    if (windowId == WINDOW_NONE)
        return;

    DetailDrawWindowFrame(windowId);

    if (sData->menu.detailActiveEffectsCount == 0
     || sData->menu.detailEffectsCursor >= sData->menu.detailActiveEffectsCount)
    {
        sData->detailTextBuffer[0] = EOS;
    }
    else
    {
        enum BattleStatusEffectId effectId = sData->menu.detailActiveEffects[sData->menu.detailEffectsCursor].effectId;
        DetailFormatDescriptionText(effectId, sData->detailTextBuffer);
    }

    wrapWidth = WindowWidthPx(windowId) - (2 * 2) - 2;
    if (wrapWidth < 8)
        wrapWidth = 8;

    windowHeightPx = GetWindowAttribute(windowId, WINDOW_HEIGHT) * 8;
    availableHeight = (windowHeightPx > 2 + 1) ? windowHeightPx - 2 - 1 : 1;
    lineHeight = GetFontAttribute(descFont, FONTATTR_MAX_LETTER_HEIGHT) + GetFontAttribute(descFont, FONTATTR_LINE_SPACING);
    if (lineHeight == 0)
        lineHeight = 1;
    maxLines = availableHeight / lineHeight;
    if (maxLines == 0)
        maxLines = 1;

    BreakStringAutomatic(sData->detailTextBuffer, wrapWidth, maxLines, descFont, HIDE_SCROLL_PROMPT);

    end = sData->detailTextBuffer + StringLength(sData->detailTextBuffer);
    WrapFontIdToFit(sData->detailTextBuffer, end, descFont, wrapWidth);
    DetailClampTextLines(sData->detailTextBuffer, maxLines);

    if (sData->detailTextBuffer[0] != EOS)
    {
        AddTextPrinterParameterized4(windowId, descFont, 2, 2, 0, 0,
                                     sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW, sData->detailTextBuffer);
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void DetailRefreshEffectsSection(void)
{
    DetailDrawEntryBoxes();
    DetailRefreshEffectsWindow();
    DetailRefreshDescriptionWindow();
}

static void DetailDestroyEffectsCursor(void)
{
    if (sData->menu.cursorSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sData->menu.cursorSpriteId]);
    sData->menu.cursorSpriteId = SPRITE_NONE;
}

static void DetailDestroyEffectsScrollbar(void)
{
    if (sData->menu.detailEffectsScrollbarSpriteId != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sData->menu.detailEffectsScrollbarSpriteId]);
        sData->menu.detailEffectsScrollbarSpriteId = SPRITE_NONE;
    }
}

static void DetailUpdateEffectsCursor(void)
{
    DetailDestroyEffectsCursor();
}

static void DetailDrawWindowFrame(u8 windowId)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(B_STATUS_TEXT_COLOR_TRANSPARENT));
}

static void OverviewBufferLabelText(void)
{
    if (GetOpponentTrainerCount() == 1)
        StringCopy(sData->menu.enemyLabelText, GetPrimaryOpponentTrainerName());
    else
        StringCopy(sData->menu.enemyLabelText, sText_BattleStatus_Opponent);

    if (HasPlayerPartnerTrainer())
        StringCopy(sData->menu.playerLabelText, sText_BattleStatus_Ally);
    else
        StringCopy(sData->menu.playerLabelText, GetPlayerTrainerName());
}

static void OverviewComputeRowLayout(u8 count, s16 *outXs, s16 *outRowLeft, s16 *outRowRight, s16 *outRowCenter)
{
    s16 gapTiles = 0;
    s16 totalWidthTiles;
    s16 startXTile;
    s16 i;
    s16 safeLeft = B_STATUS_SAFE_LEFT_TILE;
    s16 safeRight = B_STATUS_SAFE_RIGHT_TILE;
    s16 safeWidthTiles = safeRight - safeLeft + 1;
    s16 screenWidthTiles = DISPLAY_WIDTH / 8;

    if (count == 0)
    {
        *outRowLeft = B_STATUS_SAFE_LEFT_TILE * 8;
        *outRowRight = B_STATUS_SAFE_LEFT_TILE * 8;
        *outRowCenter = (DISPLAY_WIDTH / 2);
        return;
    }

    totalWidthTiles = count * B_STATUS_CARD_TILE_W + (count - 1) * gapTiles;
    if (totalWidthTiles > safeWidthTiles)
    {
        gapTiles = 0;
        totalWidthTiles = count * B_STATUS_CARD_TILE_W + (count - 1) * gapTiles;
    }

    startXTile = (screenWidthTiles - totalWidthTiles) / 2;
    if (startXTile < safeLeft)
        startXTile = safeLeft;
    if (startXTile + totalWidthTiles - 1 > safeRight)
        startXTile = safeRight - totalWidthTiles + 1;
    if (startXTile < safeLeft)
        startXTile = safeLeft;

    for (i = 0; i < count; i++)
        outXs[i] = (startXTile + i * (B_STATUS_CARD_TILE_W + gapTiles)) * 8;

    *outRowLeft = outXs[0];
    *outRowRight = outXs[count - 1] + B_STATUS_CARD_W;
    *outRowCenter = (*outRowLeft + *outRowRight) / 2;
}

static void OverviewCreateCards(void)
{
    u32 i;
    u32 enemySlots = 0;
    u32 playerSlots = 0;

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (IsOnPlayerSide(battler))
            playerSlots++;
        else
            enemySlots++;
    }

    s16 rowXs[MAX_BATTLERS_COUNT];

    u32 cardCount = 0;
    OverviewComputeRowLayout(enemySlots,
                             rowXs, &sData->menu.enemyRowLeft, &sData->menu.enemyRowRight,
                             &sData->menu.enemyRowCenter);

    for (i = 0; i < enemySlots; i++)
    {
        struct BattleStatusCard *card = &sData->menu.cards[cardCount++];
        card->x = rowXs[i];
        card->battlerId = GetBattlerFromEnemySlot(i);
        card->y = B_STATUS_ROW_Y_ENEMY;
    }

    OverviewComputeRowLayout(playerSlots,
                             rowXs, &sData->menu.playerRowLeft, &sData->menu.playerRowRight,
                             &sData->menu.playerRowCenter);

    for (i = 0; i < playerSlots; i++)
    {
        struct BattleStatusCard *card = &sData->menu.cards[cardCount++];
        card->x = rowXs[i];
        card->battlerId = GetBattlerFromPlayerSlot(i);
        card->y = B_STATUS_ROW_Y_PLAYER;
    }
}

static void OverviewDrawCards(void)
{
    for (u32 i = 0; i < gBattlersCount; i++)
        OverviewDrawCard(&sData->menu.cards[i]);
}

static void OverviewDrawCard(struct BattleStatusCard *card)
{
    u8 windowId = (card->y == B_STATUS_ROW_Y_ENEMY) ? WIN_ROW_ENEMY : WIN_ROW_PLAYER;
    u8 nameFont;
    const u8 *gimmickIndicatorData;
    u32 gimmickIndicatorPalTag;
    struct SpriteTemplate gimmickTemplate;
    struct SpriteSheet gimmickSheet;
    s16 localX = card->x;
    s16 localY = card->y;
    s16 contentYOffset = (card->y == B_STATUS_ROW_Y_ENEMY) ? -2 : 0;
    s16 maxNameWidth;
    s16 iconCenterX;
    s16 iconCenterY;

    struct Pokemon *mon = GetBattlerMon(card->battlerId);
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    u32 gender = GetMonGender(mon);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);
    u32 ailment = GetAilmentFromBattler(card->battlerId);
    u8 name[POKEMON_NAME_LENGTH + 1];
    GetMonData(mon, MON_DATA_NICKNAME, name);

    if (windowId == WIN_ROW_ENEMY)
        localY -= (B_STATUS_ROW_Y_ENEMY / 8) * 8;
    else
        localY -= (B_STATUS_ROW_Y_PLAYER / 8) * 8;

    maxNameWidth = B_STATUS_CARD_W - 6;
    if (gender == MON_MALE || gender == MON_FEMALE)
        maxNameWidth -= B_STATUS_GENDER_W + 4;
    nameFont = GetBestFitNameFont(name, maxNameWidth);

    FillWindowPixelRect(windowId, PIXEL_FILL(B_STATUS_TEXT_COLOR_TRANSPARENT), localX, localY, B_STATUS_CARD_W, B_STATUS_CARD_H);

    AddTextPrinterParameterized4(windowId, nameFont, localX + 6, localY + 2 + contentYOffset, 0, 0,
                                 sTextColor_BattleStatus_OverviewDefault, TEXT_SKIP_DRAW, name);

    if (gender == MON_MALE || gender == MON_FEMALE)
    {
        u8 genderSymbol[2];
        const u8 *colors = (gender == MON_MALE) ? sTextColor_BattleStatus_Male : sTextColor_BattleStatus_Female;
        u8 genderX = localX + B_STATUS_CARD_W - B_STATUS_GENDER_W - 2;
        u8 genderY = localY + 2 + contentYOffset;

        genderSymbol[0] = (gender == MON_MALE) ? CHAR_MALE : CHAR_FEMALE;
        genderSymbol[1] = EOS;

        AddTextPrinterParameterized4(windowId, FONT_SMALL, genderX, genderY, 0, 0, colors, TEXT_SKIP_DRAW, genderSymbol);
    }

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);

    iconCenterX = card->x + (B_STATUS_CARD_W / 2);
    iconCenterY = card->y + 28 + contentYOffset;

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
    gimmickIndicatorData = GetGimmickIndicatorData(card->battlerId, &gimmickIndicatorPalTag);
    if (gimmickIndicatorData != NULL && gimmickIndicatorPalTag != 0)
    {
        card->gimmickTileTag = B_STATUS_OVERVIEW_GIMMICK_TILE_TAG_BASE + card->battlerId;
        gimmickTemplate = sSpriteTemplate_BattleStatusDetailGimmick;
        gimmickTemplate.tileTag = card->gimmickTileTag;
        gimmickTemplate.paletteTag = gimmickIndicatorPalTag;

        gimmickSheet.data = gimmickIndicatorData;
        gimmickSheet.size = B_STATUS_DETAIL_GIMMICK_GFX_SIZE;
        gimmickSheet.tag = card->gimmickTileTag;
        LoadSpriteSheet(&gimmickSheet);

        card->gimmickSpriteId = CreateSprite(&gimmickTemplate,
                                             card->x + (B_STATUS_DETAIL_GIMMICK_W / 2) + 5,
                                             iconCenterY - (B_STATUS_DETAIL_GIMMICK_H / 2) - 3, 0);
        if (card->gimmickSpriteId != SPRITE_NONE)
            gSprites[card->gimmickSpriteId].oam.priority = 0;
    }

    if (ailment != AILMENT_NONE && ailment != AILMENT_PKRS)
    {
        s16 statusX = iconCenterX + 13;
        s16 statusY = iconCenterY + 14;

        card->statusSpriteId = CreateSprite(&gSpriteTemplate_StatusIcons, statusX, statusY, 0);
        if (card->statusSpriteId != SPRITE_NONE)
        {
            StartSpriteAnim(&gSprites[card->statusSpriteId], ailment - 1);
            gSprites[card->statusSpriteId].oam.priority = 0;
        }
    }

    card->hpBarTileTag = B_STATUS_HP_BAR_TILE_TAG_BASE + card->battlerId;
    card->hpBarSpriteId = CreateHpBarSprite(card->hpBarTileTag, card->x - 16,
                                                         card->y + 46 + contentYOffset);
    if (card->hpBarSpriteId != SPRITE_NONE)
        CreateHpBarEndcaps(&card->hpBarLeftEndcapSpriteId, &card->hpBarRightEndcapSpriteId);
    else
    {
        card->hpBarLeftEndcapSpriteId = SPRITE_NONE;
        card->hpBarRightEndcapSpriteId = SPRITE_NONE;
    }
    DrawHpBarSprite(card);

    if (sData->unreadUpdates[card->battlerId])
    {
        s16 updateX = card->x + B_STATUS_CARD_W - 9;
        s16 updateY = iconCenterY - 8;

        card->updateSpriteId = CreateSprite(&sSpriteTemplate_BattleStatusUpdateIcon, updateX, updateY, 0);
        if (card->updateSpriteId != SPRITE_NONE)
            gSprites[card->updateSpriteId].oam.priority = 0;
    }
}

static u8 GetBestFitNameFont(const u8 *name, s16 maxWidth)
{
    if (GetStringWidth(FONT_NORMAL, name, 0) <= maxWidth)
        return FONT_NORMAL;
    if (GetStringWidth(FONT_NARROW, name, 0) <= maxWidth)
        return FONT_NARROW;
    return FONT_NARROWER;
}

static void OverviewSetBgTile(u16 *tilemap, s16 x, s16 y, u16 tileNum, u16 attrs)
{
    if (x < 0 || x >= B_STATUS_TILEMAP_WIDTH || y < 0 || y >= B_STATUS_TILEMAP_HEIGHT)
        return;

    tilemap[y * B_STATUS_TILEMAP_WIDTH + x] = tileNum | attrs;
}

static void LoadBackdropAssets(void)
{
    LoadBgTiles(B_STATUS_BACKDROP_BG, sBattleStatusMenuBgTiles, sizeof(sBattleStatusMenuBgTiles), 0);
    LoadPalette(sBattleStatusMenuBgPalette, BG_PLTT_ID(0), sizeof(sBattleStatusMenuBgPalette));
}

static void BackdropLoadBaseTilemap(const u16 *baseTilemap)
{
    if (baseTilemap == NULL)
        return;

    CpuCopy16(baseTilemap, sData->bg1Tilemap,
              B_STATUS_TILEMAP_WIDTH * B_STATUS_TILEMAP_HEIGHT * sizeof(u16));
    CopyBgTilemapBufferToVram(B_STATUS_BACKDROP_BG);
}

static void DetailDrawEntryBoxes(void)
{
}

static void OverviewFillBgRect(u16 *tilemap, s16 x, s16 y, s16 width, s16 height, u16 tileNum, u16 attrs)
{
    s16 xi;
    s16 yi;

    for (yi = y; yi < y + height; yi++)
    {
        for (xi = x; xi < x + width; xi++)
            OverviewSetBgTile(tilemap, xi, yi, tileNum, attrs);
    }
}

static void OverviewComputeHeaderLayout(s16 rowCenter, s16 labelWidth, u8 *outTextLenTiles, s16 *outHeaderX, s16 *outHeaderWidth)
{
    u8 textLenTiles = (labelWidth + 7) / 8;
    s16 headerWidth;
    s16 headerX;

    if (textLenTiles == 0)
        textLenTiles = 1;
    if (textLenTiles & 1)
        textLenTiles++;

    headerWidth = textLenTiles + 2;
    headerX = (rowCenter - ((headerWidth * 8) / 2)) / 8;
    if (headerX < B_STATUS_SAFE_LEFT_TILE)
        headerX = B_STATUS_SAFE_LEFT_TILE;
    if (headerX + headerWidth - 1 > B_STATUS_SAFE_RIGHT_TILE)
        headerX = B_STATUS_SAFE_RIGHT_TILE - headerWidth + 1;

    if (outTextLenTiles != NULL)
        *outTextLenTiles = textLenTiles;
    *outHeaderX = headerX;
    *outHeaderWidth = headerWidth;
}

static void OverviewDrawStatusCard(u16 *tilemap, s16 x, s16 y, u8 width, u8 height, bool8 isActive, bool8 isBottomRow)
{
    u16 topLeftTile;
    u16 topEdgeTile;
    u16 sideEdgeTile;
    u16 fillTile;
    u16 bottomLeftTile;
    u16 bottomEdgeTile;
    u16 topAttrs = 0;
    u16 bottomAttrs = 0;
    s16 xi;
    s16 yi;

    if (width < 2 || height < 2)
        return;

    if (isActive)
    {
        topLeftTile = B_STATUS_BG_TILE_CARD_ACTIVE_TL;
        topEdgeTile = B_STATUS_BG_TILE_CARD_ACTIVE_TE;
        sideEdgeTile = B_STATUS_BG_TILE_CARD_ACTIVE_SE;
        fillTile = B_STATUS_BG_TILE_CARD_ACTIVE_IN;
        bottomLeftTile = B_STATUS_BG_TILE_CARD_ACTIVE_BL;
        bottomEdgeTile = B_STATUS_BG_TILE_CARD_ACTIVE_BE;
    }
    else
    {
        topLeftTile = B_STATUS_BG_TILE_CARD_INACTIVE_TL;
        topEdgeTile = B_STATUS_BG_TILE_CARD_INACTIVE_TE;
        sideEdgeTile = B_STATUS_BG_TILE_CARD_INACTIVE_SE;
        fillTile = B_STATUS_BG_TILE_CARD_INACTIVE_IN;
        bottomLeftTile = B_STATUS_BG_TILE_CARD_INACTIVE_BL;
        bottomEdgeTile = B_STATUS_BG_TILE_CARD_INACTIVE_BE;
    }

    if (isBottomRow)
    {
        u16 swappedTopLeft = bottomLeftTile;
        u16 swappedTopEdge = bottomEdgeTile;
        u16 swappedBottomLeft = topLeftTile;
        u16 swappedBottomEdge = topEdgeTile;

        topLeftTile = swappedTopLeft;
        topEdgeTile = swappedTopEdge;
        bottomLeftTile = swappedBottomLeft;
        bottomEdgeTile = swappedBottomEdge;
        topAttrs = B_STATUS_BG_ATTR_VFLIP;
        bottomAttrs = B_STATUS_BG_ATTR_VFLIP;
    }

    OverviewSetBgTile(tilemap, x, y, topLeftTile, topAttrs);
    OverviewSetBgTile(tilemap, x + width - 1, y, topLeftTile, topAttrs | B_STATUS_BG_ATTR_HFLIP);
    OverviewSetBgTile(tilemap, x, y + height - 1, bottomLeftTile, bottomAttrs);
    OverviewSetBgTile(tilemap, x + width - 1, y + height - 1, bottomLeftTile, bottomAttrs | B_STATUS_BG_ATTR_HFLIP);

    for (xi = x + 1; xi < x + width - 1; xi++)
    {
        OverviewSetBgTile(tilemap, xi, y, topEdgeTile, topAttrs);
        OverviewSetBgTile(tilemap, xi, y + height - 1, bottomEdgeTile, bottomAttrs);
    }

    for (yi = y + 1; yi < y + height - 1; yi++)
    {
        OverviewSetBgTile(tilemap, x, yi, sideEdgeTile, 0);
        OverviewSetBgTile(tilemap, x + width - 1, yi, sideEdgeTile, B_STATUS_BG_ATTR_HFLIP);
    }

    for (yi = y + 1; yi < y + height - 1; yi++)
    {
        for (xi = x + 1; xi < x + width - 1; xi++)
            OverviewSetBgTile(tilemap, xi, yi, fillTile, 0);
    }
}

static void OverviewDrawHeaderBox(u16 *tilemap, s16 x, s16 y, u8 textLenTiles)
{
    s16 width;
    s16 interior;

    if (textLenTiles == 0)
        textLenTiles = 1;

    interior = textLenTiles;
    if (interior & 1)
        interior++;
    width = interior + 2;
    if (width > B_STATUS_TILEMAP_WIDTH)
        width = B_STATUS_TILEMAP_WIDTH;
    if (x < 0)
        x = 0;
    if (x + width > B_STATUS_TILEMAP_WIDTH)
        x = B_STATUS_TILEMAP_WIDTH - width;
    if (y < 0 || y + 2 >= B_STATUS_TILEMAP_HEIGHT)
        return;

    OverviewSetBgTile(tilemap, x, y, B_STATUS_BG_TILE_HEADER_CORNER, 0);
    OverviewSetBgTile(tilemap, x + width - 1, y, B_STATUS_BG_TILE_HEADER_CORNER, B_STATUS_BG_ATTR_HFLIP);
    for (interior = x + 1; interior < x + width - 1; interior++)
        OverviewSetBgTile(tilemap, interior, y, B_STATUS_BG_TILE_HEADER_TOP, 0);

    OverviewSetBgTile(tilemap, x, y + 1, B_STATUS_BG_TILE_HEADER_SIDE, 0);
    OverviewSetBgTile(tilemap, x + width - 1, y + 1, B_STATUS_BG_TILE_HEADER_SIDE, B_STATUS_BG_ATTR_HFLIP);
    for (interior = x + 1; interior < x + width - 1; interior++)
        OverviewSetBgTile(tilemap, interior, y + 1, B_STATUS_BG_TILE_HEADER_FILL, 0);

    OverviewSetBgTile(tilemap, x, y + 2, B_STATUS_BG_TILE_HEADER_CORNER, B_STATUS_BG_ATTR_VFLIP);
    OverviewSetBgTile(tilemap, x + width - 1, y + 2, B_STATUS_BG_TILE_HEADER_CORNER, B_STATUS_BG_ATTR_HFLIP | B_STATUS_BG_ATTR_VFLIP);
    for (interior = x + 1; interior < x + width - 1; interior++)
        OverviewSetBgTile(tilemap, interior, y + 2, B_STATUS_BG_TILE_HEADER_TOP, B_STATUS_BG_ATTR_VFLIP);
}

static void OverviewDrawCardBackground(const struct BattleStatusCard *card, bool8 isActive)
{
    s16 cardTileX;
    s16 cardTileY;

    if (card == NULL)
        return;

    cardTileX = card->x / 8;
    cardTileY = card->y / 8;
    OverviewFillBgRect(sData->bg1Tilemap, cardTileX, cardTileY,
                                    B_STATUS_CARD_TILE_W, B_STATUS_CARD_TILE_H, B_STATUS_BG_TILE_FILL, 0);
    OverviewDrawStatusCard(sData->bg1Tilemap, cardTileX, cardTileY,
                                        B_STATUS_CARD_TILE_W, B_STATUS_CARD_TILE_H, isActive,
                                        card->y == B_STATUS_ROW_Y_PLAYER);
}

static void OverviewDrawBackground(void)
{
    u8 i;
    s16 enemyLabelWidth;
    s16 playerLabelWidth;
    u8 enemyTextLenTiles;
    u8 playerTextLenTiles;
    s16 enemyHeaderX;
    s16 playerHeaderX;
    s16 enemyHeaderWidth;
    s16 playerHeaderWidth;

    CpuCopy16(sBattleStatusMenuOverviewBaseTilemap, sData->bg1Tilemap,
              B_STATUS_TILEMAP_WIDTH * B_STATUS_TILEMAP_HEIGHT * sizeof(u16));

    OverviewFillBgRect(sData->bg1Tilemap, B_STATUS_SAFE_LEFT_TILE, B_STATUS_ROW_Y_ENEMY / 8,
                                    B_STATUS_SAFE_RIGHT_TILE - B_STATUS_SAFE_LEFT_TILE + 1, B_STATUS_CARD_TILE_H,
                                    B_STATUS_BG_TILE_FILL, 0);
    OverviewFillBgRect(sData->bg1Tilemap, B_STATUS_SAFE_LEFT_TILE, B_STATUS_ROW_Y_PLAYER / 8,
                                    B_STATUS_SAFE_RIGHT_TILE - B_STATUS_SAFE_LEFT_TILE + 1, B_STATUS_CARD_TILE_H,
                                    B_STATUS_BG_TILE_FILL, 0);
    OverviewFillBgRect(sData->bg1Tilemap, B_STATUS_SAFE_LEFT_TILE, 0,
                                    B_STATUS_SAFE_RIGHT_TILE - B_STATUS_SAFE_LEFT_TILE + 1, B_STATUS_LABEL_TILE_H,
                                    B_STATUS_BG_TILE_FILL, 0);
    OverviewFillBgRect(sData->bg1Tilemap, B_STATUS_SAFE_LEFT_TILE, B_STATUS_LABEL_BOTTOM_TILE_TOP,
                                    B_STATUS_SAFE_RIGHT_TILE - B_STATUS_SAFE_LEFT_TILE + 1, B_STATUS_LABEL_TILE_H,
                                    B_STATUS_BG_TILE_FILL, 0);

    for (i = 0; i < gBattlersCount; i++)
        OverviewDrawCardBackground(&sData->menu.cards[i], i == sData->menu.selectedCardIndex);

    enemyLabelWidth = GetStringWidth(FONT_SMALL, sData->menu.enemyLabelText, 0);
    playerLabelWidth = GetStringWidth(FONT_SMALL, sData->menu.playerLabelText, 0);
    OverviewComputeHeaderLayout(sData->menu.enemyRowCenter, enemyLabelWidth,
                                             &enemyTextLenTiles, &enemyHeaderX, &enemyHeaderWidth);
    OverviewComputeHeaderLayout(sData->menu.playerRowCenter, playerLabelWidth,
                                             &playerTextLenTiles, &playerHeaderX, &playerHeaderWidth);

    OverviewDrawHeaderBox(sData->bg1Tilemap, enemyHeaderX, 0, enemyTextLenTiles);
    OverviewDrawHeaderBox(sData->bg1Tilemap, playerHeaderX, B_STATUS_LABEL_BOTTOM_TILE_TOP, playerTextLenTiles);

    CopyBgTilemapBufferToVram(B_STATUS_BACKDROP_BG);
}

static void OverviewUpdateCardSelectionHighlight(u8 oldSelectedIndex)
{
    u32 cardCount = gBattlersCount;

    if (oldSelectedIndex < cardCount)
        OverviewDrawCardBackground(&sData->menu.cards[oldSelectedIndex], FALSE);
    if (sData->menu.selectedCardIndex < cardCount)
        OverviewDrawCardBackground(&sData->menu.cards[sData->menu.selectedCardIndex], TRUE);

    CopyBgTilemapBufferToVram(B_STATUS_BACKDROP_BG);
}

static void OverviewDrawLabels(void)
{
    const u8 *enemyLabel;
    const u8 *playerLabel;
    s16 enemyLabelX;
    s16 playerLabelX;
    s16 enemyLabelWidth;
    s16 playerLabelWidth;
    s16 enemyHeaderX;
    s16 playerHeaderX;
    s16 enemyHeaderWidth;
    s16 playerHeaderWidth;
    s16 labelY;
    s16 labelHeight = GetFontAttribute(FONT_SMALL, FONTATTR_MAX_LETTER_HEIGHT);

    enemyLabel = sData->menu.enemyLabelText;
    playerLabel = sData->menu.playerLabelText;

    enemyLabelWidth = GetStringWidth(FONT_SMALL, enemyLabel, 0);
    playerLabelWidth = GetStringWidth(FONT_SMALL, playerLabel, 0);
    OverviewComputeHeaderLayout(sData->menu.enemyRowCenter, enemyLabelWidth,
                                             NULL, &enemyHeaderX, &enemyHeaderWidth);
    OverviewComputeHeaderLayout(sData->menu.playerRowCenter, playerLabelWidth,
                                             NULL, &playerHeaderX, &playerHeaderWidth);

    enemyLabelX = enemyHeaderX * 8 + ((enemyHeaderWidth * 8) - enemyLabelWidth) / 2;
    playerLabelX = playerHeaderX * 8 + ((playerHeaderWidth * 8) - playerLabelWidth) / 2;
    if (labelHeight <= 0 || labelHeight > B_STATUS_LABEL_H)
        labelHeight = 8;
    labelY = (B_STATUS_LABEL_H - labelHeight) / 2;
    labelY -= 2;
    if (labelY < 0)
        labelY = 0;

    FillWindowPixelBuffer(WIN_LABEL_TOP, PIXEL_FILL(B_STATUS_TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WIN_LABEL_TOP, FONT_SMALL, enemyLabelX, labelY, 0, 0,
                                sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW, enemyLabel);
    PutWindowTilemap(WIN_LABEL_TOP);
    CopyWindowToVram(WIN_LABEL_TOP, COPYWIN_FULL);

    FillWindowPixelBuffer(WIN_LABEL_BOTTOM, PIXEL_FILL(B_STATUS_TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WIN_LABEL_BOTTOM, FONT_SMALL, playerLabelX, labelY, 0, 0,
                                sTextColor_BattleStatus_Default, TEXT_SKIP_DRAW, playerLabel);
    PutWindowTilemap(WIN_LABEL_BOTTOM);
    CopyWindowToVram(WIN_LABEL_BOTTOM, COPYWIN_FULL);
}

static const u8 *GetPlayerTrainerName(void)
{
    return gSaveBlock2Ptr->playerName;
}

static const u8 *GetPrimaryOpponentTrainerName(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        return GetTrainerNameFromId(TRAINER_BATTLE_PARAM.opponentA);

    return sText_BattleStatus_Opponent;
}

static u8 GetOpponentTrainerCount(void)
{
    if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
        return 0;

    if ((gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_MULTI)) && !BATTLE_TWO_VS_ONE_OPPONENT)
        return 2;

    return 1;
}

static bool8 HasPlayerPartnerTrainer(void)
{
    return HasPartnerTrainer(B_BATTLER_0);
}

static void OverviewUpdateHpBars(void)
{
    u8 i;

    for (i = 0; i < gBattlersCount; i++)
        DrawHpBarSprite(&sData->menu.cards[i]);
}

static void DestroyOverviewCardSprites(struct BattleStatusCard *card, bool8 freeHpBarTile)
{
    if (card->hpBarSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[card->hpBarSpriteId]);
    DestroyHpBarEndcaps(&card->hpBarLeftEndcapSpriteId, &card->hpBarRightEndcapSpriteId);
    if (card->statusSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[card->statusSpriteId]);
    if (card->updateSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[card->updateSpriteId]);
    if (card->monIconSpriteId != SPRITE_NONE)
        FreeAndDestroyMonIconSprite(&gSprites[card->monIconSpriteId]);
    if (card->gimmickSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[card->gimmickSpriteId]);

    if (freeHpBarTile && card->hpBarTileTag != 0)
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

static void BattleStatusMenu_Destroy(void)
{
    u32 i;

    if (sData->menu.cursorSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sData->menu.cursorSpriteId]);
    sData->menu.cursorSpriteId = SPRITE_NONE;

    DetailDestroyWindows();
    DetailDestroyHpBar();
    DetailDestroyStatusIcon();
    DetailDestroyTeraTypeIndicator();
    DetailDestroyGimmickIndicator();
    DetailDestroyTypeIcons();
    DetailDestroyStatPips();
    DetailDestroyEffectsScrollbar();

    if (sData->menu.detailIconSpriteId != SPRITE_NONE)
        FreeAndDestroyMonIconSprite(&gSprites[sData->menu.detailIconSpriteId]);
    sData->menu.detailIconSpriteId = SPRITE_NONE;

    for (i = 0; i < gBattlersCount; i++)
        DestroyOverviewCardSprites(&sData->menu.cards[i], TRUE);

    RemoveWindow(WIN_LABEL_TOP);
    RemoveWindow(WIN_LABEL_BOTTOM);
    RemoveWindow(WIN_ROW_ENEMY);
    RemoveWindow(WIN_ROW_PLAYER);

    FreeSpritePaletteByTag(B_STATUS_HP_BAR_PAL_TAG);
    FreeSpritePaletteByTag(B_STATUS_HP_BAR_ENDCAP_PAL_TAG);
    FreeSpriteTilesByTag(B_STATUS_HP_BAR_ENDCAP_LEFT_TILE_TAG);
    FreeSpriteTilesByTag(B_STATUS_HP_BAR_ENDCAP_RIGHT_TILE_TAG);
    FreeSpriteTilesByTag(B_STATUS_UPDATE_ICON_TILE_TAG);
    FreeSpriteTilesByTag(B_STATUS_CURSOR_TILE_TAG);
    FreeSpriteTilesByTag(B_STATUS_DETAIL_EFFECTS_SCROLLBAR_TILE_TAG);
    FreeSpritePaletteByTag(gSpriteTemplate_MoveTypes.paletteTag);
    FreeSpritePaletteByTag(B_STATUS_MOVE_TYPES_PAL_TAG_1);
    FreeSpritePaletteByTag(B_STATUS_MOVE_TYPES_PAL_TAG_2);
    FreeSpriteTilesByTag(TAG_STATUS_ICONS);
    FreeSpritePaletteByTag(TAG_STATUS_ICONS);
    FreeMonIconPalettes();

    FREE_AND_SET_NULL(sData);
}

static u8 CreateHpBarSprite(u16 tileTag, s16 x, s16 y)
{
    struct SpriteSheet sheet =
    {
        sBattleStatusHpBarTiles, sizeof(sBattleStatusHpBarTiles), tileTag
    };
    struct SpriteTemplate template = sSpriteTemplate_BattleStatusHpBar;
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

    *leftEndcapSpriteId = CreateSprite(&sSpriteTemplate_BattleStatusHpBarLeftEndcap, 0, 0, 0);
    if (*leftEndcapSpriteId != SPRITE_NONE)
    {
        gSprites[*leftEndcapSpriteId].oam.priority = 0;
        gSprites[*leftEndcapSpriteId].invisible = TRUE;
    }

    *rightEndcapSpriteId = CreateSprite(&sSpriteTemplate_BattleStatusHpBarRightEndcap, 0, 0, 0);
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

    if (segmentCount > B_STATUS_HP_BAR_SEGMENTS)
        segmentCount = B_STATUS_HP_BAR_SEGMENTS;

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

static void UpdateHpBarTilesWithWidth(u8 spriteId, s16 hp, s16 maxHp, u8 totalPixels, u8 segmentCount)
{
    u8 array[B_STATUS_HP_BAR_SEGMENTS];
    u8 i;
    u8 filledPixels;
    u8 barElementId;
    u16 tileNum;
    void *dst;

    if (segmentCount > B_STATUS_HP_BAR_SEGMENTS)
        segmentCount = B_STATUS_HP_BAR_SEGMENTS;

    if (maxHp <= 0)
        maxHp = 1;

    filledPixels = GetScaledHPFraction(hp, maxHp, totalPixels);
    barElementId = GetBarGfxId(hp, maxHp);

    for (i = 0; i < B_STATUS_HP_BAR_SEGMENTS; i++)
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
    for (i = 0; i < B_STATUS_HP_BAR_SEGMENTS; i++)
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

static void UpdateHpBarTiles(u8 spriteId, s16 hp, s16 maxHp)
{
    UpdateHpBarTilesWithWidth(spriteId, hp, maxHp, B_STATUS_HEALTHBAR_PIXELS, B_STATUS_HP_BAR_SEGMENTS);
}

static void DrawHpBarSprite(struct BattleStatusCard *card)
{
    struct Sprite *sprite;
    s16 hp = gBattleMons[card->battlerId].hp;
    s16 maxHp = gBattleMons[card->battlerId].maxHP;
    s16 contentYOffset = (card->y == B_STATUS_ROW_Y_ENEMY) ? -2 : 0;

    if (card->hpBarSpriteId == SPRITE_NONE)
        return;

    sprite = &gSprites[card->hpBarSpriteId];
    sprite->x = card->x + (B_STATUS_CARD_W / 2) - 16;
    sprite->y = card->y + 46 + contentYOffset;

    UpdateHpBarTiles(card->hpBarSpriteId, hp, maxHp);
    UpdateHpBarEndcaps(card->hpBarLeftEndcapSpriteId, card->hpBarRightEndcapSpriteId,
                                    sprite->x, sprite->y, B_STATUS_HP_BAR_SEGMENTS);
    sprite->invisible = FALSE;
}

static u8 GetBarGfxId(s16 hp, s16 maxHp)
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

static u8 GetAilmentFromBattler(enum BattlerId battler)
{
    u32 status;

    if (gBattleMons[battler].hp == 0)
        return AILMENT_FNT;

    status = gBattleMons[battler].status1;
    return GetAilmentFromStatus(status);
}

static void SnapshotResetEntry(u8 battler)
{
    memset(&sData->lastSnapshot[battler], 0, sizeof(sData->lastSnapshot[battler]));
    sData->lastSnapshotValid[battler] = FALSE;
    sData->lastMonIdentity[battler] = 0;
    sData->lastMonIdentityValid[battler] = FALSE;
    sData->unreadUpdates[battler] = FALSE;
    sData->updateReasons[battler] = B_STATUS_UPDATE_REASON_NONE;
    sData->updateLatchedTurn[battler] = 0;
    sData->justSwitchedIn[battler] = FALSE;
}

static void SnapshotStoreEntry(u8 battler, u32 identity, const struct BattleStatusSnapshot *snapshot)
{
    sData->lastSnapshot[battler] = *snapshot;
    sData->lastSnapshotValid[battler] = TRUE;
    sData->lastMonIdentity[battler] = identity;
    sData->lastMonIdentityValid[battler] = TRUE;
}

static u64 GetTrackedVolatileMask(enum BattlerId battler)
{
    const struct BattlePokemon *mon = &gBattleMons[battler];
    u64 mask = 0;

#define TRACK_VOLATILE(bit, condition)          \
    do                                          \
    {                                           \
        if (condition)                          \
            mask |= ((u64)1 << (bit));          \
    } while (0)

    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_CRIT_BOOST,
                   mon->volatiles.focusEnergy
                || mon->volatiles.dragonCheer
                || mon->volatiles.bonusCritStages > 0);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_CONFUSION,
                   mon->volatiles.confusionTurns > 0 || mon->volatiles.infiniteConfusion);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_INFATUATION, mon->volatiles.infatuation);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_NIGHTMARE, mon->volatiles.nightmare);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_DROWSY, mon->volatiles.yawn);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_ENCORE, mon->volatiles.encoreTimer > 0);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_TORMENT, mon->volatiles.torment);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_GRUDGE, mon->volatiles.grudge);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_HEAL_BLOCK, mon->volatiles.healBlock);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_IDENTIFIED, mon->volatiles.foresight || mon->volatiles.miracleEye);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_CANT_ESCAPE, mon->volatiles.escapePrevention || mon->volatiles.noRetreat);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_LOCK_ON, mon->volatiles.lockOn);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_EMBARGO, mon->volatiles.embargo);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_CHARGE, mon->volatiles.chargeTimer > 0);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_TAUNT, mon->volatiles.tauntTimer > 0);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_TELEKINESIS, mon->volatiles.telekinesis);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_WISH, gBattleStruct->wish[battler].counter > 0);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_INGRAIN, mon->volatiles.root);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_CURSE, mon->volatiles.cursed);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_DESTINY_BOND, mon->volatiles.destinyBond);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_BOUND, mon->volatiles.wrapped);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_BIDE, mon->volatiles.bideTurns > 0);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_FUTURE_ATTACK, gBattleStruct->futureSight[battler].counter > 0);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_UPROAR, mon->volatiles.uproarTurns > 0);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_AQUA_RING, mon->volatiles.aquaRing);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_AUTOTOMIZE, mon->volatiles.autotomizeCount > 0);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_SMACK_DOWN, mon->volatiles.smackDown);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_THROAT_CHOP, mon->volatiles.throatChopTimer > 0);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_LASER_FOCUS, mon->volatiles.laserFocusTimer > 0);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_TAR_SHOT, mon->volatiles.tarShot);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_OCTOLOCK, mon->volatiles.octolock);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_FIXATED, mon->volatiles.glaiveRush);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_STANCE_SWAP, mon->volatiles.powerTrick);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_SLOW_START, mon->volatiles.slowStartTimer > 0);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_SALT_CURE, mon->volatiles.saltCure);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_SYRUPY, mon->volatiles.syrupBomb || mon->volatiles.syrupBombTimer > 0);
    TRACK_VOLATILE(B_STATUS_TRACKED_VOLATILE_RAMPAGING, mon->volatiles.rampageTurns > 0);

#undef TRACK_VOLATILE

    return mask;
}

static void BuildSnapshotForBattler(enum BattlerId battler, struct BattleStatusSnapshot *snapshot)
{
    const struct BattlePokemon *mon = &gBattleMons[battler];
    enum BattleSide side = GetBattlerSide(battler);
    enum Gimmick activeGimmick = GetActiveGimmick(battler);
    u32 sideStatuses = gSideStatuses[side] & B_STATUS_TRACKED_SIDE_STATUS_BITS;

    memset(snapshot, 0, sizeof(*snapshot));
    snapshot->majorStatus = GetAilmentFromStatus(mon->status1);
    snapshot->volatileMask = GetTrackedVolatileMask(battler);
    snapshot->critBoostLevel = mon->volatiles.bonusCritStages;
    snapshot->autotomizeCount = mon->volatiles.autotomizeCount;
    memcpy(snapshot->statStages, mon->statStages, sizeof(snapshot->statStages));
    snapshot->species = mon->species;
    snapshot->type1 = mon->types[0];
    snapshot->type2 = mon->types[1];
    snapshot->activeGimmick = (u8)activeGimmick;
    snapshot->isPrimal = IsBattlerPrimalReverted(battler);
    snapshot->isMega = (activeGimmick == GIMMICK_MEGA);
    snapshot->isDynamaxed = (activeGimmick == GIMMICK_DYNAMAX);
    if (snapshot->isDynamaxed)
        snapshot->dynamaxTurns = gBattleStruct->dynamax.dynamaxTurns[battler];
    snapshot->isTera = (activeGimmick == GIMMICK_TERA);
    if (snapshot->isTera)
        snapshot->teraType = GetBattlerTeraType(battler);
    else
        snapshot->teraType = TYPE_NONE;
    snapshot->sideStatusBits = sideStatuses;
    snapshot->stealthRock = IsHazardOnSide(side, HAZARDS_STEALTH_ROCK);
    snapshot->stickyWeb = IsHazardOnSide(side, HAZARDS_STICKY_WEB);
    if (IsHazardOnSide(side, HAZARDS_SPIKES))
        snapshot->spikesLayers = gSideTimers[side].spikesAmount;
    if (IsHazardOnSide(side, HAZARDS_TOXIC_SPIKES))
        snapshot->toxicSpikesLayers = gSideTimers[side].toxicSpikesAmount;

    if (IsOnPlayerSide(battler))
    {
        snapshot->allyItemKnown = TRUE;
        snapshot->allyItem = mon->item;
        snapshot->allyAbilityKnown = TRUE;
        if (mon->ability != ABILITY_NONE && mon->ability < ABILITIES_COUNT)
            snapshot->allyAbility = mon->ability;
        else
            snapshot->allyAbility = ABILITY_NONE;
    }
}

static u16 GetUpdateReasons(enum BattlerId battler, const struct BattleStatusSnapshot *previous, const struct BattleStatusSnapshot *current)
{
    u16 reasons = B_STATUS_UPDATE_REASON_NONE;
    bool8 gimmickEnded = FALSE;
    bool8 megaActivated;
    bool8 dynamaxActivated;
    bool8 teraActivated;
    bool8 teraTypeChangedWhileActive;
    u64 gainedVolatiles = current->volatileMask & ~previous->volatileMask;
    u32 gainedSideStatuses = current->sideStatusBits & ~previous->sideStatusBits;

    if ((previous->activeGimmick != GIMMICK_NONE && current->activeGimmick == GIMMICK_NONE)
     || (previous->isPrimal && !current->isPrimal))
        gimmickEnded = TRUE;

    megaActivated = (!previous->isMega && current->isMega);
    dynamaxActivated = (!previous->isDynamaxed && current->isDynamaxed);
    teraActivated = (!previous->isTera && current->isTera);
    teraTypeChangedWhileActive = (previous->isTera && current->isTera && previous->teraType != current->teraType);

    if (current->majorStatus != previous->majorStatus && current->majorStatus != AILMENT_NONE)
        reasons |= B_STATUS_UPDATE_REASON_STATUS;

    if (gainedVolatiles != 0)
        reasons |= B_STATUS_UPDATE_REASON_VOLATILE_GAIN;
    if (current->critBoostLevel > previous->critBoostLevel
     || current->autotomizeCount > previous->autotomizeCount)
        reasons |= B_STATUS_UPDATE_REASON_VOLATILE_STACK_RAISE;

    if (!previous->stealthRock && current->stealthRock)
        reasons |= B_STATUS_UPDATE_REASON_HAZARD_GAIN;
    if (!previous->stickyWeb && current->stickyWeb)
        reasons |= B_STATUS_UPDATE_REASON_HAZARD_GAIN;
    if (current->spikesLayers > previous->spikesLayers
     || current->toxicSpikesLayers > previous->toxicSpikesLayers)
        reasons |= B_STATUS_UPDATE_REASON_HAZARD_LAYER_RAISE;

    if (gainedSideStatuses != 0)
        reasons |= B_STATUS_UPDATE_REASON_SIDE_STATUS_GAIN;

    if (memcmp(previous->statStages, current->statStages, sizeof(current->statStages)) != 0)
        reasons |= B_STATUS_UPDATE_REASON_STAT_STAGE;

    if (!gimmickEnded
     && (current->species != previous->species
      || (!previous->isPrimal && current->isPrimal)))
        reasons |= B_STATUS_UPDATE_REASON_FORM_CHANGE;
    if (!gimmickEnded
     && (current->type1 != previous->type1 || current->type2 != previous->type2))
        reasons |= B_STATUS_UPDATE_REASON_TYPE_CHANGE;
    if (!gimmickEnded
     && ((previous->activeGimmick != current->activeGimmick && current->activeGimmick != GIMMICK_NONE)
      || teraTypeChangedWhileActive))
        reasons |= B_STATUS_UPDATE_REASON_GIMMICK_ACTIVATED;
    if (megaActivated)
        reasons |= B_STATUS_UPDATE_REASON_GIMMICK_MEGA;
    if (dynamaxActivated)
        reasons |= B_STATUS_UPDATE_REASON_GIMMICK_DYNAMAX;
    if (teraActivated || teraTypeChangedWhileActive)
        reasons |= B_STATUS_UPDATE_REASON_GIMMICK_TERA;

    if (IsOnPlayerSide(battler))
    {
        if ((!previous->allyItemKnown && current->allyItemKnown)
         || (previous->allyItemKnown && current->allyItemKnown && previous->allyItem != current->allyItem))
            reasons |= B_STATUS_UPDATE_REASON_ALLY_ITEM;

        if ((!previous->allyAbilityKnown && current->allyAbilityKnown)
         || (previous->allyAbilityKnown && current->allyAbilityKnown && previous->allyAbility != current->allyAbility))
            reasons |= B_STATUS_UPDATE_REASON_ALLY_ABILITY;
    }

    return reasons;
}

static void LogUpdateReasons(enum BattlerId battler, u16 reasons)
{
#if B_STATUS_DEBUG_UPDATE_REASON_LOG
    if (reasons & B_STATUS_UPDATE_REASON_STATUS)
        DebugPrintf("BattleStatus upd battler=%d STATUS", battler);
    if (reasons & B_STATUS_UPDATE_REASON_VOLATILE_GAIN)
        DebugPrintf("BattleStatus upd battler=%d VOLATILE_GAIN", battler);
    if (reasons & B_STATUS_UPDATE_REASON_VOLATILE_STACK_RAISE)
        DebugPrintf("BattleStatus upd battler=%d VOLATILE_STACK", battler);
    if (reasons & B_STATUS_UPDATE_REASON_HAZARD_GAIN)
        DebugPrintf("BattleStatus upd battler=%d HAZARD_GAIN", battler);
    if (reasons & B_STATUS_UPDATE_REASON_HAZARD_LAYER_RAISE)
        DebugPrintf("BattleStatus upd battler=%d HAZARD_LAYER", battler);
    if (reasons & B_STATUS_UPDATE_REASON_SIDE_STATUS_GAIN)
        DebugPrintf("BattleStatus upd battler=%d SIDE_STATUS", battler);
    if (reasons & B_STATUS_UPDATE_REASON_FORM_CHANGE)
        DebugPrintf("BattleStatus upd battler=%d FORM", battler);
    if (reasons & B_STATUS_UPDATE_REASON_TYPE_CHANGE)
        DebugPrintf("BattleStatus upd battler=%d TYPE", battler);
    if (reasons & B_STATUS_UPDATE_REASON_STAT_STAGE)
        DebugPrintf("BattleStatus upd battler=%d STAT_STAGE", battler);
    if (reasons & B_STATUS_UPDATE_REASON_GIMMICK_ACTIVATED)
        DebugPrintf("BattleStatus upd battler=%d GIMMICK", battler);
    if (reasons & B_STATUS_UPDATE_REASON_GIMMICK_MEGA)
        DebugPrintf("BattleStatus upd battler=%d MEGA", battler);
    if (reasons & B_STATUS_UPDATE_REASON_GIMMICK_DYNAMAX)
        DebugPrintf("BattleStatus upd battler=%d DYNAMAX", battler);
    if (reasons & B_STATUS_UPDATE_REASON_GIMMICK_TERA)
        DebugPrintf("BattleStatus upd battler=%d TERA", battler);
    if (reasons & B_STATUS_UPDATE_REASON_ALLY_ITEM)
        DebugPrintf("BattleStatus upd battler=%d ALLY_ITEM", battler);
    if (reasons & B_STATUS_UPDATE_REASON_ALLY_ABILITY)
        DebugPrintf("BattleStatus upd battler=%d ALLY_ABILITY", battler);
#else
    (void)battler;
    (void)reasons;
#endif
}

static void PrimeSnapshotsFromCurrentState(void)
{
    u8 battler;

    for (battler = 0; battler < MAX_BATTLERS_COUNT; battler++)
    {
        if (battler < gBattlersCount && IsBattlerAlive(battler))
        {
            struct BattleStatusSnapshot snapshot;
            u32 identity = gBattleMons[battler].personality;

            BuildSnapshotForBattler(battler, &snapshot);
            SnapshotStoreEntry(battler, identity, &snapshot);
            sData->unreadUpdates[battler] = FALSE;
            sData->updateReasons[battler] = B_STATUS_UPDATE_REASON_NONE;
            sData->updateLatchedTurn[battler] = gBattleTurnCounter;
            sData->justSwitchedIn[battler] = FALSE;
        }
        else
        {
            SnapshotResetEntry(battler);
        }
    }

    sData->snapshotInitialized = TRUE;
    sData->snapshotTurn = gBattleTurnCounter;
#if B_STATUS_DEBUG_UPDATE_REASON_LOG
    DebugPrintf("BattleStatus snapshots initialized turn=%d battlers=%d", sData->snapshotTurn, gBattlersCount);
#endif
}

static void ClearUnreadUpdatesForNewTurn(void)
{
    u8 battler;
    u16 turn = gBattleTurnCounter;

    for (battler = 0; battler < MAX_BATTLERS_COUNT; battler++)
    {
        if (sData->unreadUpdates[battler]
         && (u16)(turn - sData->updateLatchedTurn[battler]) > 1)
        {
            sData->unreadUpdates[battler] = FALSE;
            sData->updateReasons[battler] = B_STATUS_UPDATE_REASON_NONE;
        }
        sData->justSwitchedIn[battler] = FALSE;
    }
#if B_STATUS_DEBUG_UPDATE_REASON_LOG
    DebugPrintf("BattleStatus unread updates clear pass for turn=%d", gBattleTurnCounter);
#endif
}

static void RefreshUnreadUpdates(void)
{
    u8 battler;
    u16 turn = gBattleTurnCounter;

    if (sData->snapshotInitialized && turn < sData->snapshotTurn)
        sData->snapshotInitialized = FALSE;

    if (!sData->snapshotInitialized)
        PrimeSnapshotsFromCurrentState();
    else if (turn != sData->snapshotTurn)
    {
        ClearUnreadUpdatesForNewTurn();
        sData->snapshotTurn = turn;
    }

    for (battler = 0; battler < MAX_BATTLERS_COUNT; battler++)
    {
        struct BattleStatusSnapshot currentSnapshot;
        u32 identity;
        u16 reasons;
        u16 newReasons;

        if (battler >= gBattlersCount || !IsBattlerAlive(battler))
        {
            SnapshotResetEntry(battler);
            continue;
        }

        identity = gBattleMons[battler].personality;
        BuildSnapshotForBattler(battler, &currentSnapshot);

        if (!sData->lastMonIdentityValid[battler] || !sData->lastSnapshotValid[battler])
        {
            SnapshotStoreEntry(battler, identity, &currentSnapshot);
            sData->unreadUpdates[battler] = FALSE;
            sData->updateReasons[battler] = B_STATUS_UPDATE_REASON_NONE;
            sData->updateLatchedTurn[battler] = turn;
            sData->justSwitchedIn[battler] = FALSE;
            continue;
        }

        if (identity != sData->lastMonIdentity[battler])
        {
            sData->unreadUpdates[battler] = FALSE;
            sData->updateReasons[battler] = B_STATUS_UPDATE_REASON_NONE;
            sData->updateLatchedTurn[battler] = turn;
            sData->justSwitchedIn[battler] = TRUE;
            SnapshotStoreEntry(battler, identity, &currentSnapshot);
#if B_STATUS_DEBUG_UPDATE_REASON_LOG
            DebugPrintf("BattleStatus battler=%d SWITCH BASELINE SET turn=%d", battler, turn);
#endif
            continue;
        }

        reasons = GetUpdateReasons(battler, &sData->lastSnapshot[battler], &currentSnapshot);
        if (reasons != B_STATUS_UPDATE_REASON_NONE)
            sData->updateLatchedTurn[battler] = turn;
        newReasons = reasons & ~sData->updateReasons[battler];
        if (newReasons != B_STATUS_UPDATE_REASON_NONE)
        {
            sData->unreadUpdates[battler] = TRUE;
            sData->updateReasons[battler] |= newReasons;
            if (sData->justSwitchedIn[battler])
            {
#if B_STATUS_DEBUG_UPDATE_REASON_LOG
                DebugPrintf("BattleStatus battler=%d POST_SWITCH_DIFF reasons=0x%X", battler, newReasons);
#endif
                sData->justSwitchedIn[battler] = FALSE;
            }
            LogUpdateReasons(battler, newReasons);
        }
        SnapshotStoreEntry(battler, identity, &currentSnapshot);
    }
}

static void OverviewGetCursorPos(const struct BattleStatusCard *card, s16 *outX, s16 *outY)
{
    *outX = card->x + 2;
    *outY = card->y + (B_STATUS_CARD_H / 2) + 2;
}

static void OverviewInitCursor(void)
{
    s16 cursorX;
    s16 cursorY;

    if (sData->menu.cursorSpriteId != SPRITE_NONE)
        DestroySprite(&gSprites[sData->menu.cursorSpriteId]);


    OverviewGetCursorPos(&sData->menu.cards[sData->menu.selectedCardIndex], &cursorX, &cursorY);
    sData->menu.cursorSpriteId = CreateSprite(&sSpriteTemplate_BattleStatusCursor, cursorX, cursorY, 0);
    if (sData->menu.cursorSpriteId != SPRITE_NONE)
        gSprites[sData->menu.cursorSpriteId].oam.priority = 0;
}

static void OverviewUpdateCursorPos(void)
{
    struct BattleStatusCard *card;

    if (sData->menu.cursorSpriteId == SPRITE_NONE)
        return;

    card = &sData->menu.cards[sData->menu.selectedCardIndex];
    OverviewGetCursorPos(card, &gSprites[sData->menu.cursorSpriteId].x, &gSprites[sData->menu.cursorSpriteId].y);
}

static void RequestPageTransition(u8 targetPage)
{
    if (targetPage == sData->menu.page || sData->pendingPage != BATTLE_STATUS_PAGE_NONE)
        return;

    if (targetPage == BATTLE_STATUS_PAGE_DETAIL)
        OverviewExit();
    else if (targetPage == BATTLE_STATUS_PAGE_OVERVIEW)
        DetailExit();
    else
        return;

    sData->pendingPage = targetPage;
    sData->transitionUnloaded = FALSE;
}

static void ProcessPageTransition(void)
{
    if (sData->pendingPage == BATTLE_STATUS_PAGE_NONE)
        return;

    if (!sData->transitionUnloaded)
    {
        sData->transitionUnloaded = TRUE;
        return;
    }

    if (sData->pendingPage == BATTLE_STATUS_PAGE_DETAIL)
        DetailEnter();
    else if (sData->pendingPage == BATTLE_STATUS_PAGE_OVERVIEW)
        OverviewEnter();

    sData->pendingPage = BATTLE_STATUS_PAGE_NONE;
    sData->transitionUnloaded = FALSE;
}

static void OverviewHandleInput(void)
{
    bool8 moved = FALSE;
    u8 oldSelectedIndex = sData->menu.selectedCardIndex;

    if (JOY_NEW(DPAD_LEFT))
        moved = OverviewTryMoveCursor(-1, 0);
    else if (JOY_NEW(DPAD_RIGHT))
        moved = OverviewTryMoveCursor(1, 0);
    else if (JOY_NEW(DPAD_UP))
        moved = OverviewTryMoveCursor(0, -1);
    else if (JOY_NEW(DPAD_DOWN))
        moved = OverviewTryMoveCursor(0, 1);

    if (moved)
    {
        OverviewUpdateCardSelectionHighlight(oldSelectedIndex);
        OverviewUpdateCursorPos();
    }

    if (JOY_NEW(A_BUTTON) && gBattlersCount != 0)
    {
        PlaySE(SE_SELECT);
        RequestPageTransition(BATTLE_STATUS_PAGE_DETAIL);
    }
}

static bool8 OverviewTryMoveCursor(s8 dx, s8 dy)
{
    u8 i;
    u8 bestIndex = sData->menu.selectedCardIndex;
    s16 bestMetric = 0x7FFF;
    s16 currX;
    s16 currY;
    s16 targetRowY;

    currX = sData->menu.cards[sData->menu.selectedCardIndex].x;
    currY = sData->menu.cards[sData->menu.selectedCardIndex].y;

    if (dx != 0)
    {
        for (i = 0; i < gBattlersCount; i++)
        {
            const struct BattleStatusCard *card = &sData->menu.cards[i];
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
        targetRowY = (currY == B_STATUS_ROW_Y_ENEMY) ? B_STATUS_ROW_Y_PLAYER : B_STATUS_ROW_Y_ENEMY;

        for (i = 0; i < gBattlersCount; i++)
        {
            const struct BattleStatusCard *card = &sData->menu.cards[i];
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

    if (bestIndex != sData->menu.selectedCardIndex)
    {
        sData->menu.selectedCardIndex = bestIndex;
        return TRUE;
    }

    return FALSE;
}

static void OverviewCreateWindows(void)
{
    InitWindows(sBattleStatusMenuWindowTemplates);
    OverviewClearWindows();
}

static enum BattlerId GetSelectedBattler(void)
{
    return sData->menu.cards[sData->menu.selectedCardIndex].battlerId;
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
