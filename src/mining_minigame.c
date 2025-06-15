#include "mining_minigame.h"
#include "gba/types.h"
#include "gba/defines.h"
#include "global.h"
#include "main.h"
#include "bg.h"
#include "text_window.h"
#include "window.h"
#include "palette.h"
#include "task.h"
#include "overworld.h"
#include "malloc.h"
#include "gba/macro.h"
#include "gba/m4a_internal.h"
#include "m4a.h"
#include "menu_helpers.h"
#include "menu.h"
#include "malloc.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "constants/rgb.h"
#include "decompress.h"
#include "constants/songs.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "pokemon_icon.h"
#include "graphics.h"
#include "data.h"
#include "pokedex.h"
#include "gpu_regs.h"
#include "random.h"
#include "field_message_box.h"
#include "constants/items.h"
#include "item.h"
#include "data/mining_minigame.h"

/* >> Specials << */
void StartMining(void);

/* >> Callbacks << */
static void Mining_Init(MainCallback callback);
static void Mining_SetupCB(void);
static bool8 Mining_InitBgs(void);
static void Mining_MainCB(void);
static void Mining_VBlankCB(void);

/* >> Tasks << */
static void Task_Mining_WaitFadeAndBail(u8 taskId);
static void Task_MiningWaitFadeIn(u8 taskId);
static void Task_WaitButtonPressOpening(u8 taskId);
static void Task_MiningMainInput(u8 taskId);
static void Task_MiningFadeAndExitMenu(u8 taskId);
static void Task_MiningPrintResult(u8 taskId);

/* >> Others << */
static void Mining_FadeAndBail(void);
static bool8 Mining_LoadBgGraphics(void);
static void Mining_LoadSpriteGraphics(void);
static void Mining_FreeResources(void);
static void Mining_UpdateStressLevel(void);
static void Mining_UpdateTerrain(void);
static void Mining_DrawRandomTerrain(void);
static void DoDrawRandomItem(u8 itemStateId, u8 itemId);
static void DoDrawRandomStone(u8 itemId);
static bool32 DoesStoneFitInItemMap(u8 itemId);
static bool32 CanStoneBePlacedAtXY(u32 x, u32 y, u32 itemId);
static void Mining_CheckItemFound(void);
static void PrintMessage(const u8 *string);
static void InitMiningWindows(void);
static bool32 IsStressLevelMax(void);
static void EndMining(u8 taskId);
static u32 ConvertLoadGameStateToItemIndex(void);
static void GetItemOrPrintError(u8 taskId, u32 itemIndex, u32 itemId);
static void CheckItemAndPrint(u8 taskId, u32 itemIndex, u32 itemId);
static void MakeCursorInvisible(void);
static void HandleGameFinish(u8 taskId);
static void PrintItemSuccess(u32 buriedItemsIndex);
static u32 GetTotalNumberOfBuriedItems(void);
static void InitBuriedItems(void);
static bool32 AreAllItemsFound(void);
static void SetBuriedItemsId(u32 index, u32 itemId);
static void SetBuriedItemStatus(u32 index, bool32 status);
static u32 GetBuriedBagItemId(u32 index);
static u32 GetBuriedMiningItemId(u32 index);
static u32 GetNumberOfFoundItems(void);
static bool32 GetBuriedItemStatus(u32 index);
static void ExitMiningUI(u8 taskId);
static void WallCollapseAnimation();

/* >> Debug << */
static u32 Debug_SetNumberOfBuriedItems(u32 rnd);
static u32 Debug_DetermineStoneSize(u32 stone, u32 stoneIndex);
static void Debug_DetermineLocation(u32* x, u32* y, u32 item);
static void Debug_RaiseSpritePriority(u32 spriteId);
#if DEBUG_ENABLE_ITEM_GENERATION_OPTIONS == TRUE
static u32 Debug_CreateRandomItem(u32 random, u32 itemId);

#define DEBUG_DESIRED_NUMBER_OF_ITEMS   4
#define DEBUG_MININGID_ITEM1            MININGID_THUNDER_STONE
#define DEBUG_MININGID_ITEM2            MININGID_THUNDER_STONE
#define DEBUG_MININGID_ITEM3            MININGID_THUNDER_STONE
#define DEBUG_MININGID_ITEM4            MININGID_THUNDER_STONE
#define DEBUG_MININGID_STONE1           MININGID_STONE_MUSHROOM1
#define DEBUG_MININGID_STONE2           MININGID_STONE_MUSHROOM2

#endif


struct BuriedItem
{
    u32 bagItemId;
    u32 miningItemId;
    bool32 isDugUp;
    bool32 isSelected;
    u32 buriedState;
    u32 spriteId;
};

struct MiningState
{
    MainCallback leavingCallback; // Callback to leave the Ui
    u32 loadGameState;
    u32 layerMap[96];             // Array representing the screen. Determines virtual layers
    u32 itemMap[96];              // Determines where items are on the screen
    u32 cursorX;
    u32 cursorY;

    u8 *sBg1TilemapBuffer;
    u8 *sBg2TilemapBuffer;
    u8 *sBg3TilemapBuffer;

    // Items and Stones
    struct BuriedItem buriedItems[MINING_MAX_NUM_BURIED_ITEMS];
    struct BuriedItem buriedStones[MINING_COUNT_MAX_NUMBER_STONES];

    // Tools
    bool32 tool;    // Hammer or Pickaxe
    u32 cursorSpriteIndex;
    u32 bRedSpriteIndex;
    u32 bBlueSpriteIndex;

    // Shake
    bool32 shouldShake; // If set to true, shake gets executed every VBlank
    u32 shakeState;     // State of shaking steps
    u32 shakeDuration;  // How many times should the shaking loop?
    u32 ShakeHitTool;
    u32 ShakeHitEffect;
    bool32 toggleShakeDuringAnimation;

    // Stress Level
    u32 stressLevelCount;   // How many cracks in one 32x32 portion
    u32 stressLevelPos;     // Which crack portion

    // Collapse Animation
    u32 delayCounter;
    bool32 isCollapseAnimActive;
};

// Win IDs
#define WIN_MSG         0

// Other Sprite Tags
#define TAG_DUMMY               0
#define TAG_CURSOR              1
#define TAG_BUTTONS             2

#define TAG_PAL_ITEM1           3
#define TAG_PAL_ITEM2           4
#define TAG_PAL_ITEM3           5
#define TAG_PAL_ITEM4           6

#define TAG_PAL_HIT_EFFECTS     7
#define TAG_HIT_EFFECT_HAMMER   8
#define TAG_HIT_EFFECT_PICKAXE  9
#define TAG_HIT_HAMMER          10
#define TAG_HIT_PICKAXE         11

enum
{
    STATE_CLEAR_SCREEN = 0,
    STATE_RESET_DATA,
    STATE_INIT_BGS,
    STATE_LOAD_BGS,
    STATE_LOAD_SPRITES,
    STATE_WAIT_FADE,
    STATE_FADE,
    STATE_SET_CALLBACKS,
};

enum
{
    STATE_GRAPHICS_VRAM,
    STATE_GRAPHICS_DECOMPRESS,
    STATE_GRAPHICS_PALETTES,
    STATE_GRAPHICS_TERRAIN,
    STATE_GAME_START,
    STATE_GAME_FINISH,
    STATE_ITEM_NAME_1,
    STATE_ITEM_BAG_1,
    STATE_ITEM_NAME_2,
    STATE_ITEM_BAG_2,
    STATE_ITEM_NAME_3,
    STATE_ITEM_BAG_3,
    STATE_ITEM_NAME_4,
    STATE_ITEM_BAG_4,
    STATE_QUIT,
};

enum
{
    STRESS_LEVEL_POS_0,
    STRESS_LEVEL_POS_1,
    STRESS_LEVEL_POS_2,
    STRESS_LEVEL_POS_3,
    STRESS_LEVEL_POS_4,
    STRESS_LEVEL_POS_5,
    STRESS_LEVEL_POS_6,
    STRESS_LEVEL_POS_7,
    STRESS_LEVEL_POS_MAX,
};

enum
{
    BG_TEXT_BOX = 0,
    BG_COLLAPSE_SCREEN,
    BG_STRESS_LEVEL,
    BG_UI_GFX,
};

static EWRAM_DATA struct MiningState *sMiningUiState = NULL;

#if DEBUG_ENABLE_ITEM_GENERATION_OPTIONS == TRUE
static EWRAM_DATA u8 debugVariable = 0; // Debug
#endif

static const struct WindowTemplate sWindowTemplates[] =
{
    [WIN_MSG] =
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 14,
        .baseBlock = 256,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sMiningBgTemplates[] =
{
    {
        .bg = BG_TEXT_BOX,
        .charBaseIndex = 0,
        .mapBaseIndex = 13,
        .priority = 0,
    },
    {
        .bg = BG_COLLAPSE_SCREEN,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .priority = 1,
    },
    {
        .bg = BG_STRESS_LEVEL,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .priority = 2
    },
    {
        .bg = BG_UI_GFX,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .priority = 3
    },
};

// UI
static const u32 sUiTiles[] = INCBIN_U32("graphics/mining_minigame/ui.4bpp.smol");
static const u32 sUiTilemap[] = INCBIN_U32("graphics/mining_minigame/ui.bin.smolTM");
static const u16 sUiPalette[] = INCBIN_U16("graphics/mining_minigame/ui.gbapal");

// Collapse screen
static const u32 sCollapseScreenTiles[] = INCBIN_U32("graphics/mining_minigame/collapse.4bpp.smol");
static const u16 sCollapseScreenPalette[] = INCBIN_U16("graphics/mining_minigame/collapse.gbapal");

static const u32 gStressLevelAndTerrainTiles[] = INCBIN_U32("graphics/mining_minigame/stress_level_terrain.4bpp.smol");
static const u32 gStressLevelAndTerrainTilemap[] = INCBIN_U32("graphics/mining_minigame/stress_level_terrain.bin.smolTM");
static const u16 gStressLevelAndTerrainPalette[] = INCBIN_U16("graphics/mining_minigame/stress_level_terrain.gbapal");

static const u8 gMiningMessageBoxGfx[] = INCBIN_U8("graphics/mining_minigame/message_box.4bpp");
static const u16 gMiningMessageBoxPal[] = INCBIN_U16("graphics/mining_minigame/message_box.gbapal");

// Sprite data
const u32 gCursorGfx[] = INCBIN_U32("graphics/mining_minigame/cursor.4bpp.smol");
const u16 gCursorPal[] = INCBIN_U16("graphics/pokenav/region_map/cursor.gbapal");

const u32 gButtonGfx[] = INCBIN_U32("graphics/mining_minigame/buttons.4bpp.smol");
const u16 gButtonPal[] = INCBIN_U16("graphics/mining_minigame/buttons.gbapal");

const u32 gHitEffectHammerGfx[] = INCBIN_U32("graphics/mining_minigame/hit_effect_hammer.4bpp.smol");
const u32 gHitEffectPickaxeGfx[] = INCBIN_U32("graphics/mining_minigame/hit_effect_pickaxe.4bpp.smol");
const u32 gHitHammerGfx[] = INCBIN_U32("graphics/mining_minigame/hit_hammer.4bpp.smol");
const u32 gHitPickaxeGfx[] = INCBIN_U32("graphics/mining_minigame/hit_pickaxe.4bpp.smol");
const u16 gHitEffectPal[] = INCBIN_U16("graphics/mining_minigame/hit_effects.gbapal");

static const struct CompressedSpriteSheet sSpriteSheet_Cursor[] =
{
    {gCursorGfx, 384, TAG_CURSOR},
    {NULL},
};

static const struct SpritePalette sSpritePal_Cursor[] =
{
    {gCursorPal, TAG_CURSOR},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_Buttons[] =
{
    {gButtonGfx, 8192 / 2 , TAG_BUTTONS},
    {NULL},
};

static const struct SpritePalette sSpritePal_Buttons[] =
{
    {gButtonPal, TAG_BUTTONS},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_HitEffectHammer[] =
{
    {gHitEffectHammerGfx, 64 * 64 / 2 , TAG_HIT_EFFECT_HAMMER},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_HitEffectPickaxe[] =
{
    {gHitEffectPickaxeGfx, 64 * 64 / 2 , TAG_HIT_EFFECT_PICKAXE},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_HitHammer[] =
{
    {gHitHammerGfx, 32 * 64 / 2 , TAG_HIT_HAMMER},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_HitPickaxe[] =
{
    {gHitPickaxeGfx, 32 * 64 / 2 , TAG_HIT_PICKAXE},
    {NULL},
};

static const struct SpritePalette sSpritePal_HitEffect[] =
{
    {gHitEffectPal, TAG_PAL_HIT_EFFECTS},
    {NULL},
};

static const struct OamData gOamCursor =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

static const struct OamData gOamButton =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .bpp = 0,
    .shape = 2,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

static const struct OamData gOamHitEffect =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

static const struct OamData gOamHitTools =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

static const struct OamData gOamItem64x64 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
};

static const union AnimCmd gAnimCmdCursor[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const gCursorAnim[] =
{
    gAnimCmdCursor,
};

static const union AnimCmd gAnimCmdButton_RedNotPressed[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gAnimCmdButton_RedPressed[] =
{
    ANIMCMD_FRAME(32, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gAnimCmdButton_BlueNotPressed[] =
{
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gAnimCmdButton_BluePressed[] =
{
    ANIMCMD_FRAME(96, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const gButtonRedAnim[] =
{
    gAnimCmdButton_RedNotPressed,
    gAnimCmdButton_RedPressed,
};

static const union AnimCmd *const gButtonBlueAnim[] =
{
    gAnimCmdButton_BluePressed,
    gAnimCmdButton_BlueNotPressed,
};

static const union AnimCmd gAnimCmd_EffectHammerHit[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gAnimCmd_EffectHammerNotHit[] =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gAnimCmd_EffectPickaxeHit[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd gAnimCmd_EffectPickaxeNotHit[] =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const gHitHammerAnim[] =
{
    gAnimCmd_EffectHammerHit,
    gAnimCmd_EffectHammerNotHit,
};

static const union AnimCmd *const gHitPickaxeAnim[] =
{
    gAnimCmd_EffectPickaxeHit,
    gAnimCmd_EffectPickaxeNotHit,
};

static const struct SpriteTemplate gSpriteCursor =
{
    .tileTag = TAG_CURSOR,
    .paletteTag = TAG_CURSOR,
    .oam = &gOamCursor,
    .anims = gCursorAnim,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteButtonRed =
{
    .tileTag = TAG_BUTTONS,
    .paletteTag = TAG_BUTTONS,
    .oam = &gOamButton,
    .anims = gButtonRedAnim,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteButtonBlue =
{
    .tileTag = TAG_BUTTONS,
    .paletteTag = TAG_BUTTONS,
    .oam = &gOamButton,
    .anims = gButtonBlueAnim,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteHitEffectHammer =
{
    .tileTag = TAG_HIT_EFFECT_HAMMER,
    .paletteTag = TAG_PAL_HIT_EFFECTS,
    .oam = &gOamHitEffect,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteHitEffectPickaxe =
{
    .tileTag = TAG_HIT_EFFECT_PICKAXE,
    .paletteTag = TAG_PAL_HIT_EFFECTS,
    .oam = &gOamHitEffect,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteHitHammer =
{
    .tileTag = TAG_HIT_HAMMER,
    .paletteTag = TAG_PAL_HIT_EFFECTS,
    .oam = &gOamHitTools,
    .anims = gHitHammerAnim,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteHitPickaxe =
{
    .tileTag = TAG_HIT_PICKAXE,
    .paletteTag = TAG_PAL_HIT_EFFECTS,
    .oam = &gOamHitTools,
    .anims = gHitPickaxeAnim,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const u16 gStonePal[] = INCBIN_U16("graphics/mining_minigame/stones/stones.gbapal");
static const u32 gStone1x4Gfx[] = INCBIN_U32("graphics/mining_minigame/stones/stone_1x4.4bpp.smol");
static const u32 gStone4x1Gfx[] = INCBIN_U32("graphics/mining_minigame/stones/stone_4x1.4bpp.smol");
static const u32 gStone2x4Gfx[] = INCBIN_U32("graphics/mining_minigame/stones/stone_2x4.4bpp.smol");
static const u32 gStone4x2Gfx[] = INCBIN_U32("graphics/mining_minigame/stones/stone_4x2.4bpp.smol");
static const u32 gStone2x2Gfx[] = INCBIN_U32("graphics/mining_minigame/stones/stone_2x2.4bpp.smol");
static const u32 gStone3x3Gfx[] = INCBIN_U32("graphics/mining_minigame/stones/stone_3x3.4bpp.smol");
static const u32 gStoneSnake1Gfx[] = INCBIN_U32("graphics/mining_minigame/stones/stone_snake1.4bpp.smol");
static const u32 gStoneSnake2Gfx[] = INCBIN_U32("graphics/mining_minigame/stones/stone_snake2.4bpp.smol");
static const u32 gStoneMushroom1Gfx[] = INCBIN_U32("graphics/mining_minigame/stones/stone_mushroom1.4bpp.smol");
static const u32 gStoneMushroom2Gfx[] = INCBIN_U32("graphics/mining_minigame/stones/stone_mushroom2.4bpp.smol");

static const u32 gItemHeartScaleGfx[] = INCBIN_U32("graphics/mining_minigame/items/heart_scale.4bpp.smol");
static const u16 gItemHeartScalePal[] = INCBIN_U16("graphics/mining_minigame/items/heart_scale.gbapal");

static const u32 gItemHardStoneGfx[] = INCBIN_U32("graphics/mining_minigame/items/hard_stone.4bpp.smol");
static const u16 gItemHardStonePal[] = INCBIN_U16("graphics/mining_minigame/items/hard_stone.gbapal");

static const u32 gItemReviveGfx[] = INCBIN_U32("graphics/mining_minigame/items/revive.4bpp.smol");
static const u16 gItemRevivePal[] = INCBIN_U16("graphics/mining_minigame/items/revive.gbapal");

static const u32 gItemStarPieceGfx[] = INCBIN_U32("graphics/mining_minigame/items/star_piece.4bpp.smol");
static const u16 gItemStarPiecePal[] = INCBIN_U16("graphics/mining_minigame/items/star_piece.gbapal");

static const u32 gItemDampRockGfx[] = INCBIN_U32("graphics/mining_minigame/items/damp_rock.4bpp.smol");
static const u16 gItemDampRockPal[] = INCBIN_U16("graphics/mining_minigame/items/damp_rock.gbapal");

static const u32 gItemRedShardGfx[] = INCBIN_U32("graphics/mining_minigame/items/red_shard.4bpp.smol");
static const u16 gItemRedShardPal[] = INCBIN_U16("graphics/mining_minigame/items/red_shard.gbapal");

static const u32 gItemBlueShardGfx[] = INCBIN_U32("graphics/mining_minigame/items/blue_shard.4bpp.smol");
static const u16 gItemBlueShardPal[] = INCBIN_U16("graphics/mining_minigame/items/blue_shard.gbapal");

static const u32 gItemYellowShardGfx[] = INCBIN_U32("graphics/mining_minigame/items/yellow_shard.4bpp.smol");
static const u16 gItemYellowShardPal[] = INCBIN_U16("graphics/mining_minigame/items/yellow_shard.gbapal");

static const u32 gItemGreenShardGfx[] = INCBIN_U32("graphics/mining_minigame/items/green_shard.4bpp.smol");
static const u16 gItemGreenShardPal[] = INCBIN_U16("graphics/mining_minigame/items/green_shard.gbapal");

static const u32 gItemIronBallGfx[] = INCBIN_U32("graphics/mining_minigame/items/iron_ball.4bpp.smol");
static const u16 gItemIronBallPal[] = INCBIN_U16("graphics/mining_minigame/items/iron_ball.gbapal");

static const u32 gItemReviveMaxGfx[] = INCBIN_U32("graphics/mining_minigame/items/revive_max.4bpp.smol");
static const u16 gItemReviveMaxPal[] = INCBIN_U16("graphics/mining_minigame/items/revive_max.gbapal");

static const u32 gItemEverStoneGfx[] = INCBIN_U32("graphics/mining_minigame/items/ever_stone.4bpp.smol");
static const u16 gItemEverStonePal[] = INCBIN_U16("graphics/mining_minigame/items/ever_stone.gbapal");

static const u32 gItemOvalStoneGfx[] = INCBIN_U32("graphics/mining_minigame/items/oval_stone.4bpp.smol");
static const u16 gItemOvalStonePal[] = INCBIN_U16("graphics/mining_minigame/items/oval_stone.gbapal");

static const u32 gItemLightClayGfx[] = INCBIN_U32("graphics/mining_minigame/items/light_clay.4bpp.smol");
static const u16 gItemLightClayPal[] = INCBIN_U16("graphics/mining_minigame/items/light_clay.gbapal");

static const u32 gItemHeatRockGfx[] = INCBIN_U32("graphics/mining_minigame/items/heat_rock.4bpp.smol");
static const u16 gItemHeatRockPal[] = INCBIN_U16("graphics/mining_minigame/items/heat_rock.gbapal");

static const u32 gItemIcyRockGfx[] = INCBIN_U32("graphics/mining_minigame/items/icy_rock.4bpp.smol");
static const u16 gItemIcyRockPal[] = INCBIN_U16("graphics/mining_minigame/items/icy_rock.gbapal");

static const u32 gItemSmoothRockGfx[] = INCBIN_U32("graphics/mining_minigame/items/smooth_rock.4bpp.smol");
static const u16 gItemSmoothRockPal[] = INCBIN_U16("graphics/mining_minigame/items/smooth_rock.gbapal");

static const u32 gItemLeafStoneGfx[] = INCBIN_U32("graphics/mining_minigame/items/leaf_stone.4bpp.smol");
static const u16 gItemLeafStonePal[] = INCBIN_U16("graphics/mining_minigame/items/leaf_stone.gbapal");

static const u32 gItemFireStoneGfx[] = INCBIN_U32("graphics/mining_minigame/items/fire_stone.4bpp.smol");
static const u16 gItemFireStonePal[] = INCBIN_U16("graphics/mining_minigame/items/fire_stone.gbapal");

static const u32 gItemWaterStoneGfx[] = INCBIN_U32("graphics/mining_minigame/items/water_stone.4bpp.smol");
static const u16 gItemWaterStonePal[] = INCBIN_U16("graphics/mining_minigame/items/water_stone.gbapal");

static const u32 gItemThunderStoneGfx[] = INCBIN_U32("graphics/mining_minigame/items/thunder_stone.4bpp.smol");
static const u16 gItemThunderStonePal[] = INCBIN_U16("graphics/mining_minigame/items/thunder_stone.gbapal");

static const u32 gItemMoonStoneGfx[] = INCBIN_U32("graphics/mining_minigame/items/moon_stone.4bpp.smol");
static const u16 gItemMoonStonePal[] = INCBIN_U16("graphics/mining_minigame/items/moon_stone.gbapal");

static const u32 gItemSunStoneGfx[] = INCBIN_U32("graphics/mining_minigame/items/sun_stone.4bpp.smol");
static const u16 gItemSunStonePal[] = INCBIN_U16("graphics/mining_minigame/items/sun_stone.gbapal");

static const u32 gItemOddKeyStoneGfx[] = INCBIN_U32("graphics/mining_minigame/items/odd_key_stone.4bpp.smol");
static const u16 gItemOddKeyStonePal[] = INCBIN_U16("graphics/mining_minigame/items/odd_key_stone.gbapal");

static const u32 gItemSkullFossilGfx[] = INCBIN_U32("graphics/mining_minigame/items/skull_fossil.4bpp.smol");
static const u32 gItemArmorFossilGfx[] = INCBIN_U32("graphics/mining_minigame/items/armor_fossil.4bpp.smol");
static const u16 gItemFossilPal[] = INCBIN_U16("graphics/mining_minigame/items/fossil.gbapal");

// Stone SpriteSheets and SpritePalettes
static const struct CompressedSpriteSheet sSpriteSheet_Stone1x4[] =
{
    {gStone1x4Gfx, 64 * 64 / 2, MINING_TAG_STONE_1X4},
    {NULL},
};

static const struct SpritePalette sSpritePal_Stone1x4[] =
{
    {gStonePal, MINING_TAG_STONE_1X4},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_Stone4x1[] =
{
    {gStone4x1Gfx, 64 * 64 / 2, MINING_TAG_STONE_4X1},
    {NULL},
};

static const struct SpritePalette sSpritePal_Stone4x1[] =
{
    {gStonePal, MINING_TAG_STONE_4X1},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_Stone2x4[] =
{
    {gStone2x4Gfx, 64 * 64 / 2, MINING_TAG_STONE_2X4},
    {NULL},
};

static const struct SpritePalette sSpritePal_Stone2x4[] =
{
    {gStonePal, MINING_TAG_STONE_2X4},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_Stone4x2[] =
{
    {gStone4x2Gfx, 64 * 64 / 2, MINING_TAG_STONE_4X2},
    {NULL},
};

static const struct SpritePalette sSpritePal_Stone4x2[] =
{
    {gStonePal, MINING_TAG_STONE_4X2},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_Stone2x2[] =
{
    {gStone2x2Gfx, 64 * 64 / 2, MINING_TAG_STONE_2X2},
    {NULL},
};

static const struct SpritePalette sSpritePal_Stone2x2[] =
{
    {gStonePal, MINING_TAG_STONE_2X2},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_Stone3x3[] =
{
    {gStone3x3Gfx, 64 * 64 / 2, MINING_TAG_STONE_3X3},
    {NULL},
};

static const struct SpritePalette sSpritePal_Stone3x3[] =
{
    {gStonePal, MINING_TAG_STONE_3X3},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_StoneSnake1[] =
{
    {gStoneSnake1Gfx, 64 * 64 / 2, MINING_TAG_STONE_SNAKE1},
    {NULL},
};

static const struct SpritePalette sSpritePal_StoneSnake1[] =
{
    {gStonePal, MINING_TAG_STONE_SNAKE1},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_StoneSnake2[] =
{
    {gStoneSnake2Gfx, 64 * 64 / 2, MINING_TAG_STONE_SNAKE2},
    {NULL},
};

static const struct SpritePalette sSpritePal_StoneSnake2[] =
{
    {gStonePal, MINING_TAG_STONE_SNAKE2},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_StoneMushroom1[] =
{
    {gStoneMushroom1Gfx, 64 * 64 / 2, MINING_TAG_STONE_MUSHROOM1},
    {NULL},
};

static const struct SpritePalette sSpritePal_StoneMushroom1[] =
{
    {gStonePal, MINING_TAG_STONE_MUSHROOM1},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_StoneMushroom2[] =
{
    {gStoneMushroom2Gfx, 64 * 64 / 2, MINING_TAG_STONE_MUSHROOM2},
    {NULL},
};

static const struct SpritePalette sSpritePal_StoneMushroom2[] =
{
    {gStonePal, MINING_TAG_STONE_MUSHROOM2},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemHeartScale =
{
    gItemHeartScaleGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_HEARTSCALE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemHardStone =
{
    gItemHardStoneGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_HARDSTONE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemRevive =
{
    gItemReviveGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_REVIVE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemStarPiece =
{
    gItemStarPieceGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_STAR_PIECE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemDampRock =
{
    gItemDampRockGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_DAMP_ROCK,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemRedShard =
{
    gItemRedShardGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_RED_SHARD
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemBlueShard =
{
    gItemBlueShardGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_BLUE_SHARD
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemYellowShard =
{
    gItemYellowShardGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_YELLOW_SHARD
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemGreenShard =
{
    gItemGreenShardGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_GREEN_SHARD
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemIronBall =
{
    gItemIronBallGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_IRON_BALL
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemReviveMax =
{
    gItemReviveMaxGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_REVIVE_MAX
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemEverStone =
{
    gItemEverStoneGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_EVER_STONE
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemOvalStone =
{
    gItemOvalStoneGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_OVAL_STONE
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemLightClay =
{
    gItemLightClayGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_LIGHT_CLAY
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemHeatRock =
{
    gItemHeatRockGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_HEAT_ROCK,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemIcyRock =
{
    gItemIcyRockGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_ICY_ROCK,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemSmoothRock =
{
    gItemSmoothRockGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_SMOOTH_ROCK,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemLeafStone =
{
    gItemLeafStoneGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_LEAF_STONE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemFireStone =
{
    gItemFireStoneGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_FIRE_STONE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemWaterStone =
{
    gItemWaterStoneGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_WATER_STONE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemThunderStone =
{
    gItemThunderStoneGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_THUNDER_STONE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemMoonStone =
{
    gItemMoonStoneGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_MOON_STONE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemSunStone =
{
    gItemSunStoneGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_SUN_STONE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemOddKeyStone =
{
    gItemOddKeyStoneGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_ODD_KEY_STONE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemSkullFossil =
{
    gItemSkullFossilGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_SKULL_FOSSIL,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemArmorFossil =
{
    gItemArmorFossilGfx,
    64 * 64 / 2,
    MINING_TAG_ITEM_ARMOR_FOSSIL,
};

static const struct SpriteTemplate gSpriteStone1x4 =
{
    .tileTag = MINING_TAG_STONE_1X4,
    .paletteTag = MINING_TAG_STONE_1X4,
    .oam = &gOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteStone4x1 =
{
    .tileTag = MINING_TAG_STONE_4X1,
    .paletteTag = MINING_TAG_STONE_4X1,
    .oam = &gOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteStone2x4 =
{
    .tileTag = MINING_TAG_STONE_2X4,
    .paletteTag = MINING_TAG_STONE_2X4,
    .oam = &gOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteStone4x2 =
{
    .tileTag = MINING_TAG_STONE_4X2,
    .paletteTag = MINING_TAG_STONE_4X2,
    .oam = &gOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteStone2x2 =
{
    .tileTag = MINING_TAG_STONE_2X2,
    .paletteTag = MINING_TAG_STONE_2X2,
    .oam = &gOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteStone3x3 =
{
    .tileTag = MINING_TAG_STONE_3X3,
    .paletteTag = MINING_TAG_STONE_3X3,
    .oam = &gOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteStoneSnake1 =
{
    .tileTag = MINING_TAG_STONE_SNAKE1,
    .paletteTag = MINING_TAG_STONE_SNAKE1,
    .oam = &gOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteStoneSnake2 =
{
    .tileTag = MINING_TAG_STONE_SNAKE2,
    .paletteTag = MINING_TAG_STONE_SNAKE2,
    .oam = &gOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteStoneMushroom1 =
{
    .tileTag = MINING_TAG_STONE_MUSHROOM1,
    .paletteTag = MINING_TAG_STONE_MUSHROOM1,
    .oam = &gOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate gSpriteStoneMushroom2 =
{
    .tileTag = MINING_TAG_STONE_MUSHROOM2,
    .paletteTag = MINING_TAG_STONE_MUSHROOM2,
    .oam = &gOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};


struct MiningItem
{
    u32 miningItemId;
    u32 bagItemId;
    u32 top;        // starts with 0
    u32 left;       // starts with 0
    u32 totalTiles; // starts with 0
    u32 tag;
    const struct CompressedSpriteSheet* sheet;
    const u16* paldata;
};

struct MiningStone
{
    u32 top;        // starts with 0
    u32 left;       // starts with 0
    u32 height;
    u32 width;
};

static const struct MiningItem MiningItemList[] =
{
    [MININGID_NONE] =
    {
        .miningItemId = MININGID_NONE,
        .bagItemId = 0,
        .top = 0,
        .left = 0,
        .totalTiles = 0,
        .tag = 0,
        .sheet = NULL,
        .paldata = NULL,
    },
    [MININGID_HARD_STONE] =
    {
        .miningItemId = MININGID_HARD_STONE,
        .bagItemId = ITEM_HARD_STONE,
        .top = 1,
        .left = 1,
        .totalTiles = 3,
        .tag = MINING_TAG_ITEM_HARDSTONE,
        .sheet = &sSpriteSheet_ItemHardStone,
        .paldata = gItemHardStonePal,
    },
    [MININGID_REVIVE] =
    {
        .miningItemId = MININGID_REVIVE,
        .bagItemId = ITEM_REVIVE,
        .top = 2,
        .left = 2,
        .totalTiles = 4,
        .tag = MINING_TAG_ITEM_REVIVE,
        .sheet = &sSpriteSheet_ItemRevive,
        .paldata = gItemRevivePal,
    },
    [MININGID_STAR_PIECE] =
    {
        .miningItemId = MININGID_STAR_PIECE,
        .bagItemId = ITEM_STAR_PIECE,
        .top = 2,
        .left = 2,
        .totalTiles = 4,
        .tag = MINING_TAG_ITEM_STAR_PIECE,
        .sheet = &sSpriteSheet_ItemStarPiece,
        .paldata = gItemStarPiecePal,
    },
    [MININGID_DAMP_ROCK] =
    {
        .miningItemId = MININGID_DAMP_ROCK,
        .bagItemId = ITEM_DAMP_ROCK,
        .top = 2,
        .left = 2,
        .totalTiles = 7,
        .tag = MINING_TAG_ITEM_DAMP_ROCK,
        .sheet = &sSpriteSheet_ItemDampRock,
        .paldata = gItemDampRockPal,
    },
    [MININGID_RED_SHARD] =
    {
        .miningItemId = MININGID_RED_SHARD,
        .bagItemId = ITEM_RED_SHARD,
        .top = 2,
        .left = 2,
        .totalTiles = 7,
        .tag = MINING_TAG_ITEM_RED_SHARD,
        .sheet = &sSpriteSheet_ItemRedShard,
        .paldata = gItemRedShardPal,
    },
    [MININGID_BLUE_SHARD] =
    {
        .miningItemId = MININGID_BLUE_SHARD,
        .bagItemId = ITEM_BLUE_SHARD,
        .top = 2,
        .left = 2,
        .totalTiles = 7,
        .tag = MINING_TAG_ITEM_BLUE_SHARD,
        .sheet = &sSpriteSheet_ItemBlueShard,
        .paldata = gItemBlueShardPal,
    },
    [MININGID_YELLOW_SHARD] =
    {
        .miningItemId = MININGID_YELLOW_SHARD,
        .bagItemId = ITEM_YELLOW_SHARD,
        .top = 2,
        .left = 3,
        .totalTiles = 8,
        .tag = MINING_TAG_ITEM_YELLOW_SHARD,
        .sheet = &sSpriteSheet_ItemYellowShard,
        .paldata = gItemYellowShardPal,
    },
    [MININGID_GREEN_SHARD] =
    {
        .miningItemId = MININGID_GREEN_SHARD,
        .bagItemId = ITEM_GREEN_SHARD,
        .top = 2,
        .left = 3,
        .totalTiles = 10,
        .tag = MINING_TAG_ITEM_GREEN_SHARD,
        .sheet = &sSpriteSheet_ItemGreenShard,
        .paldata = gItemGreenShardPal,
    },
    [MININGID_IRON_BALL] =
    {
        .miningItemId = MININGID_IRON_BALL,
        .bagItemId = ITEM_IRON_BALL,
        .top = 2,
        .left = 2,
        .totalTiles = 8,
        .tag = MINING_TAG_ITEM_IRON_BALL,
        .sheet = &sSpriteSheet_ItemIronBall,
        .paldata = gItemIronBallPal,
    },
    [MININGID_REVIVE_MAX] =
    {
        .miningItemId = MININGID_REVIVE_MAX,
        .bagItemId = ITEM_MAX_REVIVE,
        .top = 2,
        .left = 2,
        .totalTiles = 8,
        .tag = MINING_TAG_ITEM_REVIVE_MAX,
        .sheet = &sSpriteSheet_ItemReviveMax,
        .paldata = gItemReviveMaxPal,
    },
    [MININGID_EVER_STONE] =
    {
        .miningItemId = MININGID_EVER_STONE,
        .bagItemId = ITEM_EVERSTONE,
        .top = 1,
        .left = 3,
        .totalTiles = 7,
        .tag = MINING_TAG_ITEM_EVER_STONE,
        .sheet = &sSpriteSheet_ItemEverStone,
        .paldata = gItemEverStonePal,
    },
    [MININGID_HEART_SCALE] =
    {
        .miningItemId = MININGID_HEART_SCALE,
        .bagItemId = ITEM_HEART_SCALE,
        .top = 1,
        .left = 1,
        .totalTiles = 2,
        .tag = MINING_TAG_ITEM_HEARTSCALE,
        .sheet = &sSpriteSheet_ItemHeartScale,
        .paldata = gItemHeartScalePal,
    },
    [MININGID_OVAL_STONE] =
    {
        .miningItemId = MININGID_OVAL_STONE,
        .bagItemId = ITEM_OVAL_STONE,
        .top = 2,
        .left = 2,
        .totalTiles = 8,
        .tag = MINING_TAG_ITEM_OVAL_STONE,
        .sheet = &sSpriteSheet_ItemOvalStone,
        .paldata = gItemOvalStonePal,
    },
    [MININGID_LIGHT_CLAY] =
    {
        .miningItemId = MININGID_LIGHT_CLAY,
        .bagItemId = ITEM_LIGHT_CLAY,
        .top = 3,
        .left = 3,
        .totalTiles = 10,
        .tag = MINING_TAG_ITEM_LIGHT_CLAY,
        .sheet = &sSpriteSheet_ItemLightClay,
        .paldata = gItemLightClayPal,
    },
    [MININGID_HEAT_ROCK] =
    {
        .miningItemId = MININGID_HEAT_ROCK,
        .bagItemId = ITEM_HEAT_ROCK,
        .top = 2,
        .left = 3,
        .totalTiles = 9,
        .tag = MINING_TAG_ITEM_HEAT_ROCK,
        .sheet = &sSpriteSheet_ItemHeatRock,
        .paldata = gItemHeatRockPal,
    },
    [MININGID_ICY_ROCK] =
    {
        .miningItemId = MININGID_ICY_ROCK,
        .bagItemId = ITEM_ICY_ROCK,
        .top = 3,
        .left = 3,
        .totalTiles = 11,
        .tag = MINING_TAG_ITEM_ICY_ROCK,
        .sheet = &sSpriteSheet_ItemIcyRock,
        .paldata = gItemIcyRockPal,
    },
    [MININGID_SMOOTH_ROCK] =
    {
        .miningItemId = MININGID_SMOOTH_ROCK,
        .bagItemId = ITEM_SMOOTH_ROCK,
        .top = 3,
        .left = 3,
        .totalTiles = 7,
        .tag = MINING_TAG_ITEM_SMOOTH_ROCK,
        .sheet = &sSpriteSheet_ItemSmoothRock,
        .paldata = gItemSmoothRockPal,
    },
    [MININGID_LEAF_STONE] =
    {
        .miningItemId = MININGID_LEAF_STONE,
        .bagItemId = ITEM_LEAF_STONE,
        .top = 3,
        .left = 2,
        .totalTiles = 7,
        .tag = MINING_TAG_ITEM_LEAF_STONE,
        .sheet = &sSpriteSheet_ItemLeafStone,
        .paldata = gItemLeafStonePal,
    },
    [MININGID_FIRE_STONE] =
    {
        .miningItemId = MININGID_FIRE_STONE,
        .bagItemId = ITEM_FIRE_STONE,
        .top = 2,
        .left = 2,
        .totalTiles = 8,
        .tag = MINING_TAG_ITEM_FIRE_STONE,
        .sheet = &sSpriteSheet_ItemFireStone,
        .paldata = gItemFireStonePal,
    },
    [MININGID_WATER_STONE] =
    {
        .miningItemId = MININGID_WATER_STONE,
        .bagItemId = ITEM_WATER_STONE,
        .top = 2,
        .left = 2,
        .totalTiles = 7,
        .tag = MINING_TAG_ITEM_WATER_STONE,
        .sheet = &sSpriteSheet_ItemWaterStone,
        .paldata = gItemWaterStonePal,
    },
    [MININGID_THUNDER_STONE] =
    {
        .miningItemId = MININGID_THUNDER_STONE,
        .bagItemId = ITEM_THUNDER_STONE,
        .top = 2,
        .left = 2,
        .totalTiles = 6,
        .tag = MINING_TAG_ITEM_THUNDER_STONE,
        .sheet = &sSpriteSheet_ItemThunderStone,
        .paldata = gItemThunderStonePal,
    },
    [MININGID_MOON_STONE] =
    {
        .miningItemId = MININGID_MOON_STONE,
        .bagItemId = ITEM_MOON_STONE,
        .top = 1,
        .left = 3,
        .totalTiles = 5,
        .tag = MINING_TAG_ITEM_MOON_STONE,
        .sheet = &sSpriteSheet_ItemMoonStone,
        .paldata = gItemMoonStonePal,
    },
    [MININGID_SUN_STONE] =
    {
        .miningItemId = MININGID_SUN_STONE,
        .bagItemId = ITEM_SUN_STONE,
        .top = 2,
        .left = 2,
        .totalTiles = 6,
        .tag = MINING_TAG_ITEM_SUN_STONE,
        .sheet = &sSpriteSheet_ItemSunStone,
        .paldata = gItemSunStonePal,
    },
    [MININGID_ODD_KEY_STONE] =
    {
        .miningItemId = MININGID_ODD_KEY_STONE,
        .bagItemId = ITEM_ODD_KEYSTONE,
        .top = 3,
        .left = 3,
        .totalTiles = 15,
        .tag = MINING_TAG_ITEM_ODD_KEY_STONE,
        .sheet = &sSpriteSheet_ItemOddKeyStone,
        .paldata = gItemOddKeyStonePal,
    },
    [MININGID_SKULL_FOSSIL] =
    {
        .miningItemId = MININGID_SKULL_FOSSIL,
        .bagItemId = ITEM_SKULL_FOSSIL,
        .top = 3,
        .left = 3,
        .totalTiles = 13,
        .tag = MINING_TAG_ITEM_SKULL_FOSSIL,
        .sheet = &sSpriteSheet_ItemSkullFossil,
        .paldata = gItemFossilPal,
    },
    [MININGID_ARMOR_FOSSIL] =
    {
        .miningItemId = MININGID_ARMOR_FOSSIL,
        .bagItemId = ITEM_ARMOR_FOSSIL,
        .top = 3,
        .left = 3,
        .totalTiles = 15,
        .tag = MINING_TAG_ITEM_ARMOR_FOSSIL,
        .sheet = &sSpriteSheet_ItemArmorFossil,
        .paldata = gItemFossilPal,
    },
};

static const struct MiningStone MiningStoneList[] =
{
    [MININGID_STONE_1x4] =
    {
        .top = 3,
        .left = 0,
        .width = 1,
        .height = 4,
    },
    [MININGID_STONE_4x1] =
    {
        .top = 0,
        .left = 3,
        .width = 4,
        .height = 1,
    },
    [MININGID_STONE_2x4] =
    {
        .top = 3,
        .left = 1,
        .width = 2,
        .height = 4,
    },
    [MININGID_STONE_4x2] =
    {
        .top = 1,
        .left = 3,
        .width = 4,
        .height = 2,
    },
    [MININGID_STONE_2x2] =
    {
        .top = 1,
        .left = 1,
        .width = 2,
        .height = 2,
    },
    [MININGID_STONE_3x3] =
    {
        .top = 2,
        .left = 2,
        .width = 3,
        .height = 3,
    },
    [MININGID_STONE_SNAKE1] =
    {
        .top = 1,
        .left = 2,
        .width = 3,
        .height = 2,
    },
    [MININGID_STONE_SNAKE2] =
    {
        .top = 1,
        .left = 2,
        .width = 3,
        .height = 2,
    },
    [MININGID_STONE_MUSHROOM1] =
    {
        .top = 1,
        .left = 2,
        .width = 3,
        .height = 2,
    },
    [MININGID_STONE_MUSHROOM2] =
    {
        .top = 1,
        .left = 2,
        .width = 3,
        .height = 2,
    },
};

static const u8 sText_SomethingPinged[] = _("Something pinged in the wall!\n{STR_VAR_1} confirmed!");
static const u8 sText_EverythingWas[] = _("Everything was dug up!");
static const u8 sText_WasObtained[] = _("{STR_VAR_1}\nwas obtained!");
static const u8 sText_TooBad[] = _("Too bad!\nYour Bag is full!");
static const u8 sText_TheWall[] = _("The wall collapsed!");

static u32 MiningUtil_GetTotalTileAmount(u8 itemId)
{
    return MiningItemList[itemId].totalTiles + 1;
}

// Creates a random number between 0 and amount-1
static u32 random(u32 amount)
{
    return (Random() % amount);
}

void StartMining(void)
{
    Mining_Init(CB2_ReturnToField);
}

static void Mining_Init(MainCallback callback)
{
    sMiningUiState = AllocZeroed(sizeof(struct MiningState));

    if (sMiningUiState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    sMiningUiState->leavingCallback = callback;
    sMiningUiState->shakeState = 0;
    sMiningUiState->shouldShake = FALSE;
    sMiningUiState->isCollapseAnimActive = FALSE;
    sMiningUiState->shakeDuration = 0;
    sMiningUiState->loadGameState = 0;
    sMiningUiState->stressLevelCount = 0;
    sMiningUiState->stressLevelPos = 0;

    // Default the values for each item
    sMiningUiState->buriedItems[0].buriedState = 0;
    sMiningUiState->buriedItems[1].buriedState = 0;
    sMiningUiState->buriedItems[2].buriedState = 0;
    sMiningUiState->buriedItems[3].buriedState = 0;

    // Always two stones
    sMiningUiState->buriedStones[0].isSelected = TRUE;
    sMiningUiState->buriedStones[1].isSelected = TRUE;

    // Generate Items
    u32 amountItemsToSelect = Debug_SetNumberOfBuriedItems(random(3) + 2); // The `+ 2` says that the min. amount of items to be generated are 2.

    u32 itemStateIdsStep1[4] = {0,1,2,3};
    u32 itemStateIdsStep2[3];
    u32 itemStateIdsStep3[2];

    u32 firstBuriedItemId = itemStateIdsStep1[random(4)];
    sMiningUiState->buriedItems[firstBuriedItemId].isSelected = TRUE;

    for (u32 i = 0; i < 4; i++)
    {
        if (itemStateIdsStep1[i] == firstBuriedItemId)
            continue;

        if (itemStateIdsStep1[i] > firstBuriedItemId)
            itemStateIdsStep2[i-1] = itemStateIdsStep1[i];
        else
            itemStateIdsStep2[i] = itemStateIdsStep1[i];
    }

    u32 secondBuriedItemId = itemStateIdsStep2[random(3)];
    sMiningUiState->buriedItems[secondBuriedItemId].isSelected = TRUE;

    if (amountItemsToSelect > 2)
    {
        for (u32 i = 0; i < 3; i++)
        {
            if (itemStateIdsStep2[i] == secondBuriedItemId)
                continue;

            if (itemStateIdsStep2[i] > secondBuriedItemId)
                itemStateIdsStep3[i-1] = itemStateIdsStep2[i];
            else
                itemStateIdsStep3[i] = itemStateIdsStep2[i];
        }

        u32 thirdBuriedItemId = itemStateIdsStep3[random(2)];
        sMiningUiState->buriedItems[thirdBuriedItemId].isSelected = TRUE;

        if (amountItemsToSelect == 4)
        {
            u32 fourthBuriedItemId;
            if (itemStateIdsStep3[0] == thirdBuriedItemId)
                fourthBuriedItemId = itemStateIdsStep3[1];
            else
                fourthBuriedItemId = itemStateIdsStep3[0];

            sMiningUiState->buriedItems[fourthBuriedItemId].isSelected = TRUE;
        }
    }

    SetMainCallback2(Mining_SetupCB);
}

static void Mining_SetupCB(void)
{
    switch(gMain.state)
    {
        case STATE_CLEAR_SCREEN:
            SetVBlankHBlankCallbacksToNull();
            ClearScheduledBgCopiesToVram();
            ScanlineEffect_Stop();
            CpuFill16(0, (void *)VRAM, VRAM_SIZE);
            CpuFill32(0, (void *)OAM, OAM_SIZE);
            gMain.state++;
            break;

        case STATE_RESET_DATA:
            FreeAllSpritePalettes();
            ResetPaletteFade();
            ResetSpriteData();
            ResetTasks();
            BuildOamBuffer();
            LoadOam();
            gMain.state++;
            break;

        case STATE_INIT_BGS:
            if (Mining_InitBgs() == TRUE)
            {
                sMiningUiState->loadGameState = 0;
            } else
            {
                Mining_FadeAndBail();
                return;
            }
            gMain.state++;
            break;

        case STATE_LOAD_BGS:
            if (Mining_LoadBgGraphics() == TRUE)
            {
                InitMiningWindows();
                gMain.state++;
            }
            break;

        case STATE_LOAD_SPRITES:
            if (!gPaletteFade.active)
            {
                InitBuriedItems();
                Mining_LoadSpriteGraphics();
                gMain.state++;
            }
            break;

        case STATE_WAIT_FADE:
            CreateTask(Task_MiningWaitFadeIn, 0);
            gMain.state++;
            break;

        case STATE_FADE:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            gMain.state++;
            break;

        case STATE_SET_CALLBACKS:
            SetVBlankCallback(Mining_VBlankCB);
            SetMainCallback2(Mining_MainCB);
            break;
    }
}

static bool8 Mining_InitBgs(void)
{
    const u32 TILEMAP_BUFFER_SIZE = (1024 * 2);

    ResetAllBgsCoordinates();

    sMiningUiState->sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    sMiningUiState->sBg2TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    sMiningUiState->sBg3TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);

    if (sMiningUiState->sBg3TilemapBuffer == NULL)
        return FALSE;
    else if (sMiningUiState->sBg2TilemapBuffer == NULL)
        return FALSE;
    else if (sMiningUiState->sBg1TilemapBuffer == NULL)
        return FALSE;

    ResetBgsAndClearDma3BusyFlags(0);

    InitBgsFromTemplates(0, sMiningBgTemplates, NELEMS(sMiningBgTemplates));

    SetBgTilemapBuffer(1, sMiningUiState->sBg1TilemapBuffer);
    SetBgTilemapBuffer(2, sMiningUiState->sBg2TilemapBuffer);
    SetBgTilemapBuffer(3, sMiningUiState->sBg3TilemapBuffer);

    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);

    ShowBg(0);
    ShowBg(2);
    ShowBg(3);

    return TRUE;
}

static void Task_Mining_WaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMiningUiState->leavingCallback);
        Mining_FreeResources();
        DestroyTask(taskId);
    }
}

static void Mining_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
}

static void MoveItemSprites(s16 dx, s16 dy)
{
    u32 i;

    if (sMiningUiState->toggleShakeDuringAnimation == FALSE)
    {
        for (i=0;i<MAX_SPRITES;i++)
        {
            gSprites[i].x += dx;
            gSprites[i].y += dy;
        }
    }
}

static void MiningUi_Shake(u8 taskId)
{
    switch(sMiningUiState->shakeState)
    {
        case 0: // Left 1 - Down 1
            MakeCursorInvisible();
            if (!IsStressLevelMax() && Random() % 100 < 20) // 20 % chance of not shaking the screen
                sMiningUiState->toggleShakeDuringAnimation = TRUE;
            MoveItemSprites(-1, 1);
            sMiningUiState->shakeState++;
            break;
        case 1:
            if (sMiningUiState->toggleShakeDuringAnimation == FALSE)
            {
                SetGpuReg(REG_OFFSET_BG3HOFS, 1);
                SetGpuReg(REG_OFFSET_BG2HOFS, 1);
                SetGpuReg(REG_OFFSET_BG3VOFS, -1);
                SetGpuReg(REG_OFFSET_BG2VOFS, -1);
            }
            sMiningUiState->shakeState++;
            break;
        case 3: // Right 2 - Up 2
            MoveItemSprites(3, -3);
            gSprites[sMiningUiState->ShakeHitEffect].invisible = 1;
            gSprites[sMiningUiState->ShakeHitTool].invisible = 1;
            sMiningUiState->shakeState++;
            break;
        case 4:
            if (sMiningUiState->toggleShakeDuringAnimation == FALSE)
            {
                SetGpuReg(REG_OFFSET_BG3HOFS, -2);
                SetGpuReg(REG_OFFSET_BG2HOFS, -2);
                SetGpuReg(REG_OFFSET_BG3VOFS, 2);
                SetGpuReg(REG_OFFSET_BG2VOFS, 2);
            }
            sMiningUiState->shakeState++;
            break;
        case 6: // Down 2
            MoveItemSprites(-2, 4);
            if (!IsStressLevelMax())
            {
                gSprites[sMiningUiState->ShakeHitEffect].invisible = 0;
                gSprites[sMiningUiState->ShakeHitTool].invisible = 0;
            }
            sMiningUiState->shakeState++;
            break;
        case 7:
            if (sMiningUiState->toggleShakeDuringAnimation == FALSE)
            {
                SetGpuReg(REG_OFFSET_BG3VOFS, -2);
                SetGpuReg(REG_OFFSET_BG2VOFS, -2);
                SetGpuReg(REG_OFFSET_BG3HOFS, 0);
                SetGpuReg(REG_OFFSET_BG2HOFS, 0);
            }
            sMiningUiState->shakeState++;
            break;
        case 9: // Left 2 - Up 2
            MoveItemSprites(-2, -4);
            gSprites[sMiningUiState->ShakeHitEffect].invisible = 1;
            sMiningUiState->shakeState++;
            break;
        case 10:
            if (sMiningUiState->toggleShakeDuringAnimation == FALSE)
            {
                SetGpuReg(REG_OFFSET_BG2HOFS, 2);
                SetGpuReg(REG_OFFSET_BG3HOFS, 2);
                SetGpuReg(REG_OFFSET_BG3VOFS, 2);
                SetGpuReg(REG_OFFSET_BG2VOFS, 2);
            }
            sMiningUiState->shakeState++;
            break;
        case 12: // Right 1 - Down 1
            MoveItemSprites(3, 3);
            if (!IsStressLevelMax())
                gSprites[sMiningUiState->ShakeHitEffect].invisible = 0;
            gSprites[sMiningUiState->ShakeHitTool].x += 7;
            StartSpriteAnim(&gSprites[sMiningUiState->ShakeHitTool], 1);
            sMiningUiState->shakeState++;
            break;
        case 13:
            if (sMiningUiState->toggleShakeDuringAnimation == FALSE)
            {
                SetGpuReg(REG_OFFSET_BG3HOFS, -1);
                SetGpuReg(REG_OFFSET_BG2HOFS, -1);
                SetGpuReg(REG_OFFSET_BG3VOFS, -1);
                SetGpuReg(REG_OFFSET_BG2VOFS, -1);
            }
            sMiningUiState->shakeState++;
            break;
        case 15:
            MoveItemSprites(-1, -1);
            //if (!IsStressLevelMax())
            //  gSprites[sMiningUiState->cursorSpriteIndex].invisible = 0;
            sMiningUiState->shakeState++;
            break;
        case 16:
            SetGpuReg(REG_OFFSET_BG3VOFS, 0);
            SetGpuReg(REG_OFFSET_BG3HOFS, 0);
            SetGpuReg(REG_OFFSET_BG2HOFS, 0);
            SetGpuReg(REG_OFFSET_BG2VOFS, 0);
            DestroySprite(&gSprites[sMiningUiState->ShakeHitTool]);
            DestroySprite(&gSprites[sMiningUiState->ShakeHitEffect]);
            if (sMiningUiState->shakeDuration > 0)
            {
                sMiningUiState->shakeDuration--;
                sMiningUiState->shakeState = 0;
                sMiningUiState->toggleShakeDuringAnimation = FALSE;
                break;
            }
            if (IsStressLevelMax())
                WallCollapseAnimation();
            if (!IsStressLevelMax())
                gSprites[sMiningUiState->cursorSpriteIndex].invisible = 0;
            sMiningUiState->shakeState = 0;
            sMiningUiState->shouldShake = FALSE;
            sMiningUiState->toggleShakeDuringAnimation = FALSE;
            DestroyTask(taskId);
            break;
        default:
            sMiningUiState->shakeState++;
            break;
    }
    BuildOamBuffer();
}

static void Mining_VBlankCB(void)
{
    Mining_CheckItemFound();
    UpdatePaletteFade();
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Mining_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_Mining_WaitFadeAndBail, 0);
    SetVBlankCallback(Mining_VBlankCB);
    SetMainCallback2(Mining_MainCB);
}

#define TILE_POS(x, y) (32 * (y) + (x))

static void OverwriteTileDataInTilemapBuffer(u8 tile, u8 x, u8 y, u16* tilemapBuf, u8 pal)
{
    tilemapBuf[TILE_POS(x, y)] = tile | (pal << 12);
}

static bool8 Mining_LoadBgGraphics(void)
{
    u32 i, j;
    u16 *tilemapBuf = GetBgTilemapBuffer(1);
    switch (sMiningUiState->loadGameState)
    {
        case 0:
            ResetTempTileDataBuffers();
            DecompressAndCopyTileDataToVram(1, sCollapseScreenTiles, 0, 0, 0);
            DecompressAndCopyTileDataToVram(2, gStressLevelAndTerrainTiles, 0, 0, 0);
            DecompressAndCopyTileDataToVram(3, sUiTiles, 0, 0, 0);
            sMiningUiState->loadGameState++;
            break;
        case 1:
            if (FreeTempTileDataBuffersIfPossible() != TRUE)
            {
                for (i = 0; i<32; i++)
                {
                    for (j = 0; j<32; j++)
                        OverwriteTileDataInTilemapBuffer(0, i, j, tilemapBuf, 2);
                }
                DecompressDataWithHeaderWram(gStressLevelAndTerrainTilemap, sMiningUiState->sBg2TilemapBuffer);
                DecompressDataWithHeaderWram(sUiTilemap, sMiningUiState->sBg3TilemapBuffer);
                sMiningUiState->loadGameState++;
            }
            break;
        case 2:
            LoadPalette(sCollapseScreenPalette, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
            LoadPalette(gStressLevelAndTerrainPalette, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
            LoadPalette(sUiPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
            sMiningUiState->loadGameState++;
        case 3:
            Mining_DrawRandomTerrain();
            sMiningUiState->loadGameState++;
        default:
            sMiningUiState->loadGameState = STATE_GAME_START;
            return TRUE;
    }
    return FALSE;
}

static void ClearItemMap(void)
{
    u8 i;

    for (i=0; i < 96; i++)
        sMiningUiState->itemMap[i] = MINING_ITEM_TILE_NONE;
}

#define RARITY_COMMON   0
#define RARITY_UNCOMMON 1
#define RARITY_RARE     2

static const u32 ItemRarityTable_Common[] =
{
    MININGID_HEART_SCALE,
    MININGID_RED_SHARD,
    MININGID_BLUE_SHARD,
    MININGID_YELLOW_SHARD,
    MININGID_GREEN_SHARD,
};

static const u32 ItemRarityTable_Uncommon[] =
{
    MININGID_IRON_BALL,
    MININGID_HARD_STONE,
    MININGID_REVIVE,
    MININGID_EVER_STONE,
};

static const u32 ItemRarityTable_Rare[] =
{
    MININGID_STAR_PIECE,
    MININGID_DAMP_ROCK,
    MININGID_HEAT_ROCK,
    MININGID_REVIVE_MAX,
    MININGID_OVAL_STONE,
    MININGID_LIGHT_CLAY,
    MININGID_ICY_ROCK,
    MININGID_SMOOTH_ROCK,
    MININGID_LEAF_STONE,
    MININGID_FIRE_STONE,
    MININGID_WATER_STONE,
    MININGID_THUNDER_STONE,
    MININGID_MOON_STONE,
    MININGID_SUN_STONE,
    MININGID_ODD_KEY_STONE,
    MININGID_SKULL_FOSSIL,
    MININGID_ARMOR_FOSSIL,
};

static u8 GetRandomItemId()
{
    u32 rarity;
    u32 index;
    u32 itemId;
    u32 rnd = random(7);

    if (rnd < 4)
        rarity = RARITY_COMMON;
    else if (rnd < 6)
        rarity = RARITY_UNCOMMON;
    else
        rarity = RARITY_RARE;

    switch (rarity)
    {
        case RARITY_COMMON:
            index = random(ARRAY_COUNT(ItemRarityTable_Common));
            itemId =  ItemRarityTable_Common[index];
            break;
        case RARITY_UNCOMMON:
            index = random(ARRAY_COUNT(ItemRarityTable_Uncommon));
            itemId =  ItemRarityTable_Uncommon[index];
            break;
        case RARITY_RARE:
            index = random(ARRAY_COUNT(ItemRarityTable_Rare));
            itemId =  ItemRarityTable_Rare[index];
            break;
    }

#if DEBUG_ENABLE_ITEM_GENERATION_OPTIONS == TRUE
    return Debug_CreateRandomItem(rarity,itemId);
#else
    return itemId;
#endif

    return 0;
}

static void InitItemsIfSelected(u32 item, u32 itemId) {
    if (sMiningUiState->buriedItems[item].isSelected)
    {
        itemId = GetRandomItemId();
        SetBuriedItemsId(item, itemId);
        DoDrawRandomItem(item+1, itemId);
    }
}

static void Mining_LoadSpriteGraphics(void)
{
    u32 i;
    u32 itemId1 = 0;
    u32 itemId2 = 0;
    u32 itemId3 = 0;
    u32 itemId4 = 0;
    u32 stone = MININGID_NONE;

    LoadSpritePalette(sSpritePal_Cursor);
    LoadCompressedSpriteSheet(sSpriteSheet_Cursor);

    LoadSpritePalette(sSpritePal_Buttons);
    LoadCompressedSpriteSheet(sSpriteSheet_Buttons);

    ClearItemMap();

    // Items
    InitItemsIfSelected(0, itemId1);
    InitItemsIfSelected(1, itemId2);
    InitItemsIfSelected(2, itemId3);
    InitItemsIfSelected(3, itemId4);

    // Stones
    for (i=0; i<MINING_COUNT_MAX_NUMBER_STONES; i++)
    {
        stone = MININGID_NONE;
        while (!DoesStoneFitInItemMap(stone))
            stone = ((Random() % MINING_COUNT_ID_STONE) + MININGID_STONE_1x4);

        stone = Debug_DetermineStoneSize(stone,i);
        DoDrawRandomStone(stone);
    }

    sMiningUiState->cursorSpriteIndex = CreateSprite(&gSpriteCursor, 8, 40, 0);
    sMiningUiState->cursorX = 0;
    sMiningUiState->cursorY = 2;
    sMiningUiState->bRedSpriteIndex = CreateSprite(&gSpriteButtonRed, 217, 78, 0);
    sMiningUiState->bBlueSpriteIndex = CreateSprite(&gSpriteButtonBlue, 217, 138, 1);
    sMiningUiState->tool = 0;
    LoadSpritePalette(sSpritePal_HitEffect);
    LoadCompressedSpriteSheet(sSpriteSheet_HitEffectHammer);
    LoadCompressedSpriteSheet(sSpriteSheet_HitEffectPickaxe);
    LoadCompressedSpriteSheet(sSpriteSheet_HitHammer);
    LoadCompressedSpriteSheet(sSpriteSheet_HitPickaxe);
}

static void Task_MiningWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        ConvertIntToDecimalStringN(gStringVar1, GetTotalNumberOfBuriedItems(), STR_CONV_MODE_LEFT_ALIGN, 2);
        StringExpandPlaceholders(gStringVar2, sText_SomethingPinged);
        PrintMessage(gStringVar2);
        gTasks[taskId].func = Task_WaitButtonPressOpening;
    }
}

#define BLUE_BUTTON 0
#define RED_BUTTON  1

static void Task_MiningMainInput(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON && !sMiningUiState->shouldShake)
    {
        u32 cursorPos = sMiningUiState->cursorX + (sMiningUiState->cursorY-2) * 12;
        Mining_UpdateTerrain();
        Mining_UpdateStressLevel();
        ScheduleBgCopyTilemapToVram(2);
        DoScheduledBgTilemapCopiesToVram();
        BuildOamBuffer();

        if (sMiningUiState->tool == 1)
        {
            sMiningUiState->ShakeHitEffect = CreateSprite(&gSpriteHitEffectHammer, (sMiningUiState->cursorX * 16) + 8, (sMiningUiState->cursorY * 16) + 8, 0);
            sMiningUiState->ShakeHitTool = CreateSprite(&gSpriteHitHammer, (sMiningUiState->cursorX * 16) + 24, sMiningUiState->cursorY * 16, 0);

            if (sMiningUiState->layerMap[cursorPos] == 6 && sMiningUiState->itemMap[cursorPos] > 4)
            {
                m4aMPlayStop(&gMPlayInfo_SE1);
                m4aMPlayStop(&gMPlayInfo_SE2);
                PlayBGM(MINING_SE_HIT_DUG_UP);
            }
            else
            {
                m4aMPlayStop(&gMPlayInfo_SE1);
                m4aMPlayStop(&gMPlayInfo_SE2);
                PlaySE(MINING_SE_HIT_HAMMER);
            }
        } else
        {
            sMiningUiState->ShakeHitEffect = CreateSprite(&gSpriteHitEffectPickaxe, (sMiningUiState->cursorX * 16) + 8, (sMiningUiState->cursorY * 16) + 8, 0);
            sMiningUiState->ShakeHitTool = CreateSprite(&gSpriteHitPickaxe, (sMiningUiState->cursorX * 16) + 24, sMiningUiState->cursorY * 16, 0);
            if (sMiningUiState->layerMap[cursorPos] == 6 && sMiningUiState->itemMap[cursorPos] > 4)
            {
                m4aMPlayStop(&gMPlayInfo_SE1);
                m4aMPlayStop(&gMPlayInfo_SE2);
                PlayBGM(MINING_SE_HIT_DUG_UP);
            }
            else
            {
                m4aMPlayStop(&gMPlayInfo_SE1);
                m4aMPlayStop(&gMPlayInfo_SE2);
                PlaySE(MINING_SE_HIT_PICKAXE);
            }
        }
        sMiningUiState->shouldShake = TRUE;
        CreateTask(MiningUi_Shake, 0);
    }
    else if (gMain.newAndRepeatedKeys & DPAD_LEFT && sMiningUiState->cursorX > 0)
    {
        gSprites[sMiningUiState->cursorSpriteIndex].x -= 16;
        sMiningUiState->cursorX -= 1;
    } else if (gMain.newAndRepeatedKeys & DPAD_RIGHT && sMiningUiState->cursorX < 11)
    {
        gSprites[sMiningUiState->cursorSpriteIndex].x += 16;
        sMiningUiState->cursorX += 1;
    } else if (gMain.newAndRepeatedKeys & DPAD_UP && sMiningUiState->cursorY > 2)
    {
        gSprites[sMiningUiState->cursorSpriteIndex].y -= 16;
        sMiningUiState->cursorY -= 1;
    } else if (gMain.newAndRepeatedKeys & DPAD_DOWN && sMiningUiState->cursorY < 9)
    {
        gSprites[sMiningUiState->cursorSpriteIndex].y += 16;
        sMiningUiState->cursorY += 1;
    }
    else if (gMain.newAndRepeatedKeys & R_BUTTON)
    {
        StartSpriteAnim(&gSprites[sMiningUiState->bRedSpriteIndex], 1);
        StartSpriteAnim(&gSprites[sMiningUiState->bBlueSpriteIndex],1);
        sMiningUiState->tool = RED_BUTTON;
        PlaySE(MINING_SE_TOOL_SWITCH);
    } else if (gMain.newAndRepeatedKeys & L_BUTTON)
    {
        StartSpriteAnim(&gSprites[sMiningUiState->bRedSpriteIndex], 0);
        StartSpriteAnim(&gSprites[sMiningUiState->bBlueSpriteIndex], 0);
        sMiningUiState->tool = BLUE_BUTTON;
        PlaySE(MINING_SE_TOOL_SWITCH);
    }

    if (AreAllItemsFound())
        EndMining(taskId);

    if (IsStressLevelMax())
    {
        EndMining(taskId);
        PlaySE(SE_M_EARTHQUAKE);
    }
}

static void StressLevel_Draw_0(u8 ofs, u8 ofs2, u16* ptr)
{
    OverwriteTileDataInTilemapBuffer(0x07, 21 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x08, 22 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x09, 23 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x0E, 22 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x0F, 23 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x14, 23 - ofs * 4 + ofs2, 3, ptr, 0x01);
}

static void StressLevel_Draw_1(u8 ofs, u8 ofs2, u16* ptr)
{
    OverwriteTileDataInTilemapBuffer(0x17, 21 - ofs * 4 + ofs2, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x18, 22 - ofs * 4 + ofs2, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x1B, 21 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x1C, 22 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x1D, 23 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x22, 22 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x23, 23 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x26, 23 - ofs * 4 + ofs2, 3, ptr, 0x01);
}

static void StressLevel_Draw_2(u8 ofs, u8 ofs2, u16* ptr)
{
    OverwriteTileDataInTilemapBuffer(0x27, 20 - ofs * 4 + ofs2, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x28, 21 - ofs * 4 + ofs2, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x29, 22 - ofs * 4 + ofs2, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2A, 20 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2B, 21 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2C, 22 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2D, 23 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2E, 21 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2F, 22 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x30, 23 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x26, 23 - ofs * 4 + ofs2, 3, ptr, 0x01);
}

static void StressLevel_Draw_3(u8 ofs, u8 ofs2, u16* ptr)
{
    // Clean up 0x27, 0x28 and 0x29 from StressLevel_Draw_2
    OverwriteTileDataInTilemapBuffer(0x00, 20 - ofs * 4 + ofs2, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x00, 21 - ofs * 4 + ofs2, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x00, 22 - ofs * 4 + ofs2, 0, ptr, 0x01);

    OverwriteTileDataInTilemapBuffer(0x31, 22 - ofs * 4 + ofs2, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x32, 20 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x33, 21 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x34, 22 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2D, 23 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x35, 20 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x36, 21 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x37, 22 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x30, 23 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x26, 23 - ofs * 4 + ofs2, 3, ptr, 0x01);
}

static void StressLevel_Draw_4(u8 ofs, u8 ofs2, u16* ptr)
{
    // The same clean up as StressLevel_Draw_3 but only used when the hammer is used
    OverwriteTileDataInTilemapBuffer(0x00, 20 - ofs * 4 + ofs2, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x00, 21 - ofs * 4 + ofs2, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x00, 22 - ofs * 4 + ofs2, 0, ptr, 0x01);

    OverwriteTileDataInTilemapBuffer(0x38, 22 - ofs * 4 + ofs2, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x39, 20 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3A, 21 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3B, 22 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2D, 23 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3C, 19 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3D, 20 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3E, 21 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3F, 22 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x30, 23 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x40, 19 - ofs * 4 + ofs2, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x41, 20 - ofs * 4 + ofs2, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x42, 21 - ofs * 4 + ofs2, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x26, 23 - ofs * 4 + ofs2, 3, ptr, 0x01);
}

static void StressLevel_Draw_5(u8 ofs, u8 ofs2, u16* ptr)
{
    OverwriteTileDataInTilemapBuffer(0x43, 20 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x44, 21 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3B, 22 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2D, 23 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x45, 19 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x46, 20 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x47, 21 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3F, 22 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x30, 23 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x48, 19 - ofs * 4 + ofs2, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x49, 20 - ofs * 4 + ofs2, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x4A, 21 - ofs * 4 + ofs2, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x26, 23 - ofs * 4 + ofs2, 3, ptr, 0x01);
}

static void StressLevel_Draw_6(u8 ofs, u8 ofs2, u16* ptr)
{
    // Clean up 0x48 and 0x49 from StressLevel_Draw_5
    OverwriteTileDataInTilemapBuffer(0x00, 19 - ofs * 4 + ofs2, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x00, 20 - ofs * 4 + ofs2, 3, ptr, 0x01);

    OverwriteTileDataInTilemapBuffer(0x07, 18 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x08, 19 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x09, 20 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x44, 21 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3B, 22 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2D, 23 - ofs * 4 + ofs2, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x0E, 19 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x0F, 20 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x4B, 21 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3F, 22 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x30, 23 - ofs * 4 + ofs2, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x14, 20 - ofs * 4 + ofs2, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x4A, 21 - ofs * 4 + ofs2, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x26, 23 - ofs * 4 + ofs2, 3, ptr, 0x01);
}

// This function draws the individual frames of the stress level indicator
static void StressLevel_UpdateRelativeToFramePos(u8 offsetIn8, u8 ofs2, u16* ptr)
{
    switch (sMiningUiState->stressLevelCount)
    {
        case 0:
            StressLevel_Draw_0(offsetIn8, ofs2, ptr);
            if (sMiningUiState->tool == 1)
                sMiningUiState->stressLevelCount++;
            sMiningUiState->stressLevelCount++;
            break;
        case 1:
            StressLevel_Draw_1(offsetIn8, ofs2, ptr);
            if (sMiningUiState->tool == 1)
                sMiningUiState->stressLevelCount++;
            sMiningUiState->stressLevelCount++;
            break;
        case 2:
            StressLevel_Draw_2(offsetIn8, ofs2, ptr);
            if (sMiningUiState->tool == 1)
                sMiningUiState->stressLevelCount++;
            sMiningUiState->stressLevelCount++;
            break;
        case 3:
            StressLevel_Draw_3(offsetIn8, ofs2, ptr);
            if (sMiningUiState->tool == 1)
                sMiningUiState->stressLevelCount++;
            sMiningUiState->stressLevelCount++;
            break;
        case 4:
            StressLevel_Draw_4(offsetIn8, ofs2, ptr);
            if (sMiningUiState->tool == 1)
                sMiningUiState->stressLevelCount++;
            sMiningUiState->stressLevelCount++;
            break;
        case 5:
            StressLevel_Draw_5(offsetIn8, ofs2, ptr);
            sMiningUiState->stressLevelCount++;
            break;
        case 6:
            StressLevel_Draw_6(offsetIn8, ofs2, ptr);
            if (sMiningUiState->stressLevelPos == 7)
            {
                OverwriteTileDataInTilemapBuffer(0x00, 18 - offsetIn8 * 4 + ofs2, 1, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x00, 19 - offsetIn8 * 4 + ofs2, 1, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x00, 20 - offsetIn8 * 4 + ofs2, 1, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x00, 19 - offsetIn8 * 4 + ofs2, 2, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x00, 20 - offsetIn8 * 4 + ofs2, 2, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x00, 20 - offsetIn8 * 4 + ofs2, 3, ptr, 0x01);
            }
            sMiningUiState->stressLevelCount = 1;
            sMiningUiState->stressLevelPos++;
            break;
    }
}

// This is the function that is called to easily update the stress level indicator on the top of the screen.
static void Mining_UpdateStressLevel(void)
{
    u16 *ptr = GetBgTilemapBuffer(2);
    switch (sMiningUiState->stressLevelPos)
    {
        case 0:
            StressLevel_UpdateRelativeToFramePos(0, 0, ptr);
            break;
        case 1:
            StressLevel_UpdateRelativeToFramePos(1, 1, ptr);
            break;
        case 2:
            StressLevel_UpdateRelativeToFramePos(2, 2, ptr);
            break;
        case 3:
            StressLevel_UpdateRelativeToFramePos(3, 3, ptr);
            break;
        case 4:
            StressLevel_UpdateRelativeToFramePos(4, 4, ptr);
            break;
        case 5:
            StressLevel_UpdateRelativeToFramePos(5, 5, ptr);
            break;
        case 6:
            StressLevel_UpdateRelativeToFramePos(6, 6, ptr);
            break;
        case 7:
            StressLevel_UpdateRelativeToFramePos(7, 7, ptr);
            break;
    }
}

// Draws a tile layer to the screen.
static void Terrain_DrawLayerTileToScreen(u8 x, u8 y, u8 layer, u16* ptr)
{
    u8 tileX = x * 2;
    u8 tileY = y * 2;

    switch(layer)
    {
        // layer 0 and 1 - tile: 0
        case 0:
            OverwriteTileDataInTilemapBuffer(0x20, tileX, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x21, tileX + 1, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x24, tileX, tileY + 1, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x25, tileX + 1, tileY + 1, ptr, 0x01);
            break;
        case 1:
            OverwriteTileDataInTilemapBuffer(0x19, tileX, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x1A, tileX + 1, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x1E, tileX, tileY + 1, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x1F, tileX + 1, tileY + 1, ptr, 0x01);
            break;
        case 2:
            OverwriteTileDataInTilemapBuffer(0x10, tileX, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x11, tileX + 1, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x15, tileX, tileY + 1, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x16, tileX + 1, tileY + 1, ptr, 0x01);
            break;
        case 3:
            OverwriteTileDataInTilemapBuffer(0x0C, tileX, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x0D, tileX + 1, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x12, tileX, tileY + 1, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x13, tileX + 1, tileY + 1, ptr, 0x01);
            break;
        case 4:
            OverwriteTileDataInTilemapBuffer(0x05, tileX, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x06, tileX + 1, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x0A, tileX, tileY + 1, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x0B, tileX + 1, tileY + 1, ptr, 0x01);
            break;
        case 5:
            OverwriteTileDataInTilemapBuffer(0x01, tileX, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x02, tileX + 1, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x03, tileX, tileY + 1, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x04, tileX + 1, tileY + 1, ptr, 0x01);
            break;
    }
}

static struct SpriteTemplate CreatePaletteAndReturnTemplate(u32 TileTag, u32 PalTag, u32 itemId)
{
    struct SpritePalette TempPalette;
    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempPalette.tag = PalTag;
    TempPalette.data = (u16 *)MiningItemList[itemId].paldata;
    LoadSpritePalette(&TempPalette);

    TempSpriteTemplate.tileTag = TileTag;
    TempSpriteTemplate.paletteTag = PalTag;
    TempSpriteTemplate.oam = &gOamItem64x64;
    return TempSpriteTemplate;
}

#define POS_OFFS_32X32 16
#define POS_OFFS_64X64 32

static void DrawItemSprite(u8 x, u8 y, u8 itemId, u32 itemNumPalTag, u32 itemStateId)
{
    struct SpriteTemplate gSpriteTemplate;
    u8 posX = x * 16;
    u8 posY = y * 16 + 32;
    u32 spriteId;

    switch(itemId)
    {
        case MININGID_STONE_1x4:
            LoadSpritePalette(sSpritePal_Stone1x4);
            LoadCompressedSpriteSheet(sSpriteSheet_Stone1x4);
            spriteId = CreateSprite(&gSpriteStone1x4, posX + POS_OFFS_64X64, posY + POS_OFFS_64X64, 3);
            break;
        case MININGID_STONE_4x1:
            LoadSpritePalette(sSpritePal_Stone4x1);
            LoadCompressedSpriteSheet(sSpriteSheet_Stone4x1);
            spriteId = CreateSprite(&gSpriteStone4x1, posX + POS_OFFS_64X64, posY + POS_OFFS_64X64, 3);
            break;
        case MININGID_STONE_2x4:
            LoadSpritePalette(sSpritePal_Stone2x4);
            LoadCompressedSpriteSheet(sSpriteSheet_Stone2x4);
            spriteId = CreateSprite(&gSpriteStone2x4, posX + POS_OFFS_64X64, posY + POS_OFFS_64X64, 3);
            break;
        case MININGID_STONE_4x2:
            LoadSpritePalette(sSpritePal_Stone4x2);
            LoadCompressedSpriteSheet(sSpriteSheet_Stone4x2);
            spriteId = CreateSprite(&gSpriteStone4x2, posX + POS_OFFS_64X64, posY + POS_OFFS_64X64, 3);
            break;
        case MININGID_STONE_2x2:
            LoadSpritePalette(sSpritePal_Stone2x2);
            LoadCompressedSpriteSheet(sSpriteSheet_Stone2x2);
            spriteId = CreateSprite(&gSpriteStone2x2, posX + POS_OFFS_64X64, posY + POS_OFFS_64X64, 3);
            break;
        case MININGID_STONE_3x3:
            LoadSpritePalette(sSpritePal_Stone3x3);
            LoadCompressedSpriteSheet(sSpriteSheet_Stone3x3);
            spriteId = CreateSprite(&gSpriteStone3x3, posX + POS_OFFS_64X64, posY + POS_OFFS_64X64, 3);
            break;
        case MININGID_STONE_SNAKE1:
            LoadSpritePalette(sSpritePal_StoneSnake1);
            LoadCompressedSpriteSheet(sSpriteSheet_StoneSnake1);
            spriteId = CreateSprite(&gSpriteStoneSnake1, posX + POS_OFFS_64X64, posY + POS_OFFS_64X64, 3);
            break;
        case MININGID_STONE_SNAKE2:
            LoadSpritePalette(sSpritePal_StoneSnake2);
            LoadCompressedSpriteSheet(sSpriteSheet_StoneSnake2);
            spriteId = CreateSprite(&gSpriteStoneSnake2, posX + POS_OFFS_64X64, posY + POS_OFFS_64X64, 3);
            break;
        case MININGID_STONE_MUSHROOM1:
            LoadSpritePalette(sSpritePal_StoneMushroom1);
            LoadCompressedSpriteSheet(sSpriteSheet_StoneMushroom1);
            spriteId = CreateSprite(&gSpriteStoneMushroom1, posX + POS_OFFS_64X64, posY + POS_OFFS_64X64, 3);
            break;
        case MININGID_STONE_MUSHROOM2:
            LoadSpritePalette(sSpritePal_StoneMushroom2);
            LoadCompressedSpriteSheet(sSpriteSheet_StoneMushroom2);
            spriteId = CreateSprite(&gSpriteStoneMushroom2, posX + POS_OFFS_64X64, posY + POS_OFFS_64X64, 3);
            break;
        default: // If Item and not Stone
            gSpriteTemplate = CreatePaletteAndReturnTemplate(MiningItemList[itemId].tag, itemNumPalTag, itemId);
            LoadCompressedSpriteSheet(MiningItemList[itemId].sheet);
            sMiningUiState->buriedItems[itemStateId].spriteId = CreateSprite(&gSpriteTemplate, posX+POS_OFFS_64X64, posY+POS_OFFS_64X64, 3);
            Debug_RaiseSpritePriority(sMiningUiState->buriedItems[itemStateId].spriteId);
            return;
            break;
    }

    Debug_RaiseSpritePriority(spriteId);
}

// Defines && Macros
static void SetItemState(u32 posX, u32 posY, u32 x, u32 y, u32 itemStateId)
{
    sMiningUiState->itemMap[posX + x + (posY + y) * 12] = itemStateId;
}

static void OverwriteItemMapData(u8 posX, u8 posY, u8 itemStateId, u8 itemId)
{
    u32 x, y;

    for (x=0; x<4; x++)
    {
        for (y=0; y<4; y++)
        {
            if (sSpriteTileTable[itemId][x+y*4] == 1)
                SetItemState(posX, posY, x, y, itemStateId);
        }
    }
}

// Defines && Macros
#define BORDERCHECK_COND(itemId) posX + MiningItemList[(itemId)].left > xBorder || \
    posY + MiningItemList[(itemId)].top > yBorder
#define IGNORE_COORDS 255

static u8 CheckIfItemCanBePlaced(u8 itemId, u8 posX, u8 posY, u8 xBorder, u8 yBorder)
{
    u32 i;

    for(i=1;i<=4;i++)
    {
        if (BORDERCHECK_COND(itemId)) {
            return 0;
        } // If it cannot be placed, return false, that means that item placement should regenerate
    }
    return TRUE; // If it can be placed, return true
}

static void DoDrawRandomItem(u8 itemStateId, u8 itemId)
{
    u32 y;
    u32 x;
    bool32 isItemPlaced = FALSE;
    u32 xMax, yMax, xMin, yMin;
    u32 paletteTag;

    switch(itemStateId)
    {
        default:
        case 1:
            xMin = MINING_ZONE_1_X_LEFT_BOUNDARY;
            xMax = MINING_ZONE_1_X_RIGHT_BOUNDARY;
            yMin = MINING_ZONE_1_Y_UP_BOUNDARY;
            yMax = MINING_ZONE_1_Y_DOWN_BOUNDARY;
            paletteTag = TAG_PAL_ITEM1;
            break;
        case 2:
            xMin = MINING_ZONE_2_X_LEFT_BOUNDARY;
            xMax = MINING_ZONE_2_X_RIGHT_BOUNDARY;
            yMin = MINING_ZONE_2_Y_UP_BOUNDARY;
            yMax = MINING_ZONE_2_Y_DOWN_BOUNDARY;
            paletteTag = TAG_PAL_ITEM2;
            break;
        case 3:
            xMin = MINING_ZONE_3_X_LEFT_BOUNDARY;
            xMax = MINING_ZONE_3_X_RIGHT_BOUNDARY;
            yMin = MINING_ZONE_3_Y_UP_BOUNDARY;
            yMax = MINING_ZONE_3_Y_DOWN_BOUNDARY;
            paletteTag = TAG_PAL_ITEM3;
            break;
        case 4:
            xMin = MINING_ZONE_4_X_LEFT_BOUNDARY;
            xMax = MINING_ZONE_4_X_RIGHT_BOUNDARY;
            yMin = MINING_ZONE_4_Y_UP_BOUNDARY;
            yMax = MINING_ZONE_4_Y_DOWN_BOUNDARY;
            paletteTag = TAG_PAL_ITEM4;
            break;
    }

    for(y=yMin; y<=yMax; y++)
    {
        for(x=xMin; x<=xMax; x++)
        {
            if (isItemPlaced)
                continue;

            if (Random() <= 49151)
                continue;

            Debug_DetermineLocation(&x,&y,itemStateId); // Debug

            if (MiningItemList[(itemId)].top == 3)
                y = yMin;

            if (!CheckIfItemCanBePlaced(itemId, x, y, xMax, yMax))
                continue;

            DrawItemSprite(x,y,itemId, paletteTag, itemStateId - 1);
            OverwriteItemMapData(x, y, itemStateId, itemId); // For the collection logic, overwrite the item map data
            isItemPlaced = TRUE;
            break;
        }
        // If it hasn't placed an Item (we dont really need this, why am I not deleting this??? lol, we lowkey dont need this huh), just retry
        if (y == yMax && !isItemPlaced)
            y = yMin;
    }
}

static bool32 CanStoneBePlacedAtXY(u32 x, u32 y, u32 itemId) // PSF magic
{
    u32 dx, dy;
    u32 height = MiningStoneList[itemId].height;
    u32 width = MiningStoneList[itemId].width;

    if ((x + width) > MINING_ZONE_WIDTH)
        return FALSE;

    if ((y + height) > MINING_ZONE_HEIGHT)
        return FALSE;

    for (dx = 0; dx < width; dx++)
    {
        for (dy = 0; dy < height; dy++)
        {
            if (sMiningUiState->itemMap[x + dx + (y + dy) * MINING_ZONE_WIDTH] != 0)
                return FALSE;
        }
    }
    return TRUE;
}

static bool32 DoesStoneFitInItemMap(u8 itemId)
{
    u32 coordX, coordY;

    if (itemId == MININGID_NONE)
        return FALSE;

    for (coordX = 0; coordX < MINING_ZONE_WIDTH; coordX++)
    {
        for (coordY = 0; coordY < MINING_ZONE_HEIGHT; coordY++)
        {
            if (CanStoneBePlacedAtXY(coordX, coordY, itemId))
                return TRUE;
        }
    }
    return FALSE;
}

static void DoDrawRandomStone(u8 itemId)
{
    u32 x = Random() % MINING_ZONE_WIDTH;
    u32 y = Random() % MINING_ZONE_HEIGHT;

    while(!CanStoneBePlacedAtXY(x, y, itemId))
    {
        x = Random() % MINING_ZONE_WIDTH;
        y = Random() % MINING_ZONE_HEIGHT;
    }

    DrawItemSprite(x, y, itemId, TAG_DUMMY, 0);
    OverwriteItemMapData(x, y, 6, itemId);
}

static void HandleItemState(u32 itemId) {
    u32 i;
    u32 full = MiningUtil_GetTotalTileAmount(GetBuriedMiningItemId(itemId));
    u32 stop = full + 1;

    if (sMiningUiState->buriedItems[itemId].buriedState < full && sMiningUiState->buriedItems[itemId].isSelected)
    {
        for(i=0;i<96;i++)
        {
            if(sMiningUiState->itemMap[i] == itemId+1 && sMiningUiState->layerMap[i] == 6)
            {
                sMiningUiState->itemMap[i] = MINING_ITEM_TILE_DUG_UP;
                sMiningUiState->buriedItems[itemId].buriedState++;
            }
        }
    } else if (sMiningUiState->buriedItems[itemId].buriedState == full)
    {
        BeginNormalPaletteFade(1 << (16 + gSprites[sMiningUiState->buriedItems[itemId].spriteId].oam.paletteNum), 2, 16, 0, RGB_WHITE);
        sMiningUiState->buriedItems[itemId].buriedState = stop;
        SetBuriedItemStatus(itemId,TRUE);
        PlaySE(SE_RG_CARD_OPEN);
    }
}

static void Mining_CheckItemFound(void)
{
    HandleItemState(0);
    HandleItemState(1);
    HandleItemState(2);
    HandleItemState(3);

    for (u32 i=0;i<96;i++)
    {
        if(sMiningUiState->itemMap[i] == 6 && sMiningUiState->layerMap[i] == 6)
            sMiningUiState->itemMap[i] = MINING_ITEM_TILE_DUG_UP;
    }
}

static s16 RandRangeSigned(s16 min, s16 max)
{
    if (min == max)
        return min;

    return (Random() % (max - min)) + min;
}

static bool8 AtCornerOfRectangle(u8 row, u8 col, u8 baseRow, u8 baseCol, u8 finalRow, u8 finalCol)
{
    return (col == baseCol && row == baseRow)
        || (col == baseCol && row == finalRow)
        || (col == finalCol && row == baseRow)
        || (col == finalCol && row == finalRow);
}

// Randomly generates a terrain, stores the layering in an array and draw the right tiles, with the help of the layer map, to the screen.
// Use the above function just to draw a tile once
// Credits - Skeli
static void Mining_DrawRandomTerrain(void)
{
    u8 row1, row2, col1, col2, x, y;
    u8 i, j, totalTimes;
    s8 baseRow; // Rocks can go up to one row over on either top or bottom
    s8 baseCol; // Rocks can go up to one col over on either left or right
    s8 finalRow;
    s8 finalCol, k, m;
    u16 *ptr = GetBgTilemapBuffer(2);

    // Start by placing blank layer 3 rocks
    for (i = 0; i < 96; ++i)
        sMiningUiState->layerMap[i] = 2;

    // Create patches of lighter dirt areas
    totalTimes = 3 + random(5);
    for (i = 0; i < totalTimes; ++i)
    {
        do
        {
            row1 = random(9);
            row2 = random(9);
        } while (row1 >= row2);

        do
        {
            col1 = random(13);
            col2 = random(13);
        } while (col1 >= col2);

        for (; row1 < row2; ++row1)
        {
            for (j = col1; j < col2; ++j)
                sMiningUiState->layerMap[j + row1 * 12] = 4;
        }
    }

    // Create smaller patches of big rocks on top
    /* Always in the shape:
        0 0 0
      0 0 0 0 0
      0 0 0 0 0
      0 0 0 0 0
        0 0 0
    */
    totalTimes = random(5) + 2;
    for (i = 0; i < totalTimes; ++i)
    {
        baseRow = RandRangeSigned(-4, 8);  // Rocks can go up to one row over on either top or bottom
        baseCol = RandRangeSigned(-4, 12); // Rocks can go up to one col over on either left or right
        finalRow = baseRow + 5;
        finalCol = baseCol + 5;

        for (k = baseRow; k < finalRow; ++k)
        {
            if (k < 0 || k >= 8)
                continue; // Not legal row

            for (m = baseCol; m < finalCol; ++m)
            {
                if (m < 0 || m >= 12)
                    continue; // Not legal column

                if (AtCornerOfRectangle(k, m, baseRow, baseCol, baseRow + 4, baseCol + 4))
                    continue; // Leave corner out

                sMiningUiState->layerMap[m + k * 12] = 0;
            }
        }
    }

    i = 0; // Using 'i' again to get the layer of the layer map

    // Using 'x', 'y' and 'i' to draw the right layer_tiles from layerMap to the screen.
    // Why 'y = 2'? Because we need to have a distance from the top of the screen, which is 32px -> 2 * 16
    for (y = 2; y < 8 +2; y++)
    {
        for (x = 0; x < 12 && i < 96; x++, i++)
            Terrain_DrawLayerTileToScreen(x, y, sMiningUiState->layerMap[i], ptr);
    }
}

static void Terrain_UpdateLayerTileOnScreen(u16* ptr, s8 ofsX, s8 ofsY)
{
    u8 i;
    u8 tileX;
    u8 tileY;

    i = (sMiningUiState->cursorY - 2 + ofsY) * 12 + sMiningUiState->cursorX + ofsX; // It needs the `-2` because the cursorY value started at `2`
    tileX = (sMiningUiState->cursorX + ofsX) * 2;
    tileY = (sMiningUiState->cursorY + ofsY) * 2;
    if (sMiningUiState->layerMap[i] < 6)
    {
        sMiningUiState->layerMap[i]++;

        switch (sMiningUiState->layerMap[i]) // Each case represents one layer on the wall
        {
            case 1:
                OverwriteTileDataInTilemapBuffer(0x19, tileX, tileY, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x1A, tileX + 1, tileY, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x1E, tileX, tileY + 1, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x1F, tileX + 1, tileY + 1, ptr, 0x01);
                break;
            case 2:
                OverwriteTileDataInTilemapBuffer(0x10, tileX, tileY, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x11, tileX + 1, tileY, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x15, tileX, tileY + 1, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x16, tileX + 1, tileY + 1, ptr, 0x01);
                break;
            case 3:
                OverwriteTileDataInTilemapBuffer(0x0C, tileX, tileY, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x0D, tileX + 1, tileY, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x12, tileX, tileY + 1, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x13, tileX + 1, tileY + 1, ptr, 0x01);
                break;
            case 4:
                OverwriteTileDataInTilemapBuffer(0x05, tileX, tileY, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x06, tileX + 1, tileY, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x0A, tileX, tileY + 1, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x0B, tileX + 1, tileY + 1, ptr, 0x01);
                break;
            case 5:
                OverwriteTileDataInTilemapBuffer(0x01, tileX, tileY, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x02, tileX + 1, tileY, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x03, tileX, tileY + 1, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x04, tileX + 1, tileY + 1, ptr, 0x01);
                break;
            case 6:
                OverwriteTileDataInTilemapBuffer(0x00, tileX, tileY, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x00, tileX + 1, tileY, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x00, tileX, tileY + 1, ptr, 0x01);
                OverwriteTileDataInTilemapBuffer(0x00, tileX + 1, tileY + 1, ptr, 0x01);
                break;
        }
    }
}

static u8 Terrain_Pickaxe_OverwriteTiles(u16* ptr)
{
    u8 pos = sMiningUiState->cursorX + (sMiningUiState->cursorY-2)*12;

    if (sMiningUiState->itemMap[pos] != MINING_ITEM_TILE_DUG_UP)
    {
        if (sMiningUiState->cursorX != 0)
            Terrain_UpdateLayerTileOnScreen(ptr, -1, 0);

        if (sMiningUiState->cursorX != 11)
            Terrain_UpdateLayerTileOnScreen(ptr, 1, 0);

        // We have to add '2' to '7' and '0', because the cursor spawns at Y position 2
        if (sMiningUiState->cursorY != 9)
            Terrain_UpdateLayerTileOnScreen(ptr, 0, 1);

        if (sMiningUiState->cursorY != 2)
            Terrain_UpdateLayerTileOnScreen(ptr, 0, -1);

        // Center hit
        Terrain_UpdateLayerTileOnScreen(ptr,0,0);
        if (sMiningUiState->tool == BLUE_BUTTON)
        {
            Terrain_UpdateLayerTileOnScreen(ptr,0,0);
        }
        return 0;
    } else
    {
        return 1;
    }
}

static void Terrain_Hammer_OverwriteTiles(u16* ptr)
{
    bool32 isItemDugUp = Terrain_Pickaxe_OverwriteTiles(ptr);
    u32 pos = sMiningUiState->cursorX + (sMiningUiState->cursorY - 2) * 12;

    if (!isItemDugUp)
    {
        // Corners
        // We have to add '2' to '7' and '0', because the cursor spawns at Y position 2
        if (sMiningUiState->cursorX != 11 && sMiningUiState->cursorY != 9)
            Terrain_UpdateLayerTileOnScreen(ptr, 1, 1);

        if (sMiningUiState->cursorX != 0 && sMiningUiState->cursorY != 9)
            Terrain_UpdateLayerTileOnScreen(ptr, -1, 1);

        if (sMiningUiState->cursorX != 11 && sMiningUiState->cursorY != 2)
            Terrain_UpdateLayerTileOnScreen(ptr, 1, -1);

        if (sMiningUiState->cursorX != 0 && sMiningUiState->cursorY != 2)
            Terrain_UpdateLayerTileOnScreen(ptr, -1, -1);

        if (sMiningUiState->layerMap[pos] != 6)
            Terrain_Pickaxe_OverwriteTiles(ptr);
    }
}

static void Mining_UpdateTerrain(void)
{
    u16 *ptr = GetBgTilemapBuffer(2);

    switch (sMiningUiState->tool)
    {
        case RED_BUTTON:
            Terrain_Hammer_OverwriteTiles(ptr);
            break;
        case BLUE_BUTTON:
            Terrain_Pickaxe_OverwriteTiles(ptr);
            break;
    }
}

static void Task_MiningFadeAndExitMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMiningUiState->leavingCallback);
        Mining_FreeResources();
        DestroyTask(taskId);
    }
}

static void Mining_FreeResources(void)
{
    if (sMiningUiState != NULL)
        Free(sMiningUiState);

    FreeAllWindowBuffers();
    ResetSpriteData();
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WIN1H, 0);
    SetGpuReg(REG_OFFSET_WIN1V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
}

static void InitMiningWindows(void)
{
    if (InitWindows(sWindowTemplates))
    {
        DeactivateAllTextPrinters();
        ScheduleBgCopyTilemapToVram(0);
#if FLAG_USE_DEFAULT_MESSAGE_BOX == FALSE
        LoadBgTiles(GetWindowAttribute(WIN_MSG, WINDOW_BG), gMiningMessageBoxGfx, 0x1C0, 20);
        LoadPalette(gMiningMessageBoxPal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        LoadPalette(gMiningMessageBoxPal, BG_PLTT_ID(14), PLTT_SIZE_4BPP);
#elif FLAG_USE_DEFAULT_MESSAGE_BOX == TRUE
        LoadBgTiles(GetWindowAttribute(WIN_MSG, WINDOW_BG), gMessageBox_Gfx, 0x1C0, 20);
        LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        Menu_LoadStdPalAt(BG_PLTT_ID(14));
#endif
        PutWindowTilemap(WIN_MSG);
        CopyWindowToVram(WIN_MSG, COPYWIN_FULL);
    }
}

static void PrintMessage(const u8 *string)
{
    u32 letterSpacing = 0;
    u32 x = 0;
    u32 y = 1;

    u8 txtColor[]= {TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};

    DrawDialogFrameWithCustomTileAndPalette(WIN_MSG, FALSE, 20, 15);
    FillWindowPixelBuffer(WIN_MSG, PIXEL_FILL(TEXT_COLOR_WHITE));
    CopyWindowToVram(WIN_MSG, 3);
    PutWindowTilemap(WIN_MSG);
    AddTextPrinterParameterized4(WIN_MSG, FONT_NORMAL, x, y, letterSpacing, 1, txtColor, GetPlayerTextSpeedDelay(),string);
    RunTextPrinters();
}

static bool32 IsStressLevelMax(void)
{
    return sMiningUiState->stressLevelPos == STRESS_LEVEL_POS_MAX;
}

static void EndMining(u8 taskId)
{
    sMiningUiState->loadGameState = STATE_GAME_FINISH;
    gTasks[taskId].func = Task_MiningPrintResult;
}

static bool32 ClearWindowPlaySelectButtonPress(void)
{
    if (JOY_NEW(A_BUTTON) && !sMiningUiState->isCollapseAnimActive && !sMiningUiState->shouldShake)
    {
        PlaySE(SE_SELECT);
        switch (sMiningUiState->loadGameState)
        {
            case STATE_GAME_FINISH:
            case STATE_ITEM_NAME_1:
            case STATE_ITEM_BAG_1:
            case STATE_ITEM_NAME_2:
            case STATE_ITEM_BAG_2:
            case STATE_ITEM_NAME_3:
            case STATE_ITEM_BAG_3:
            case STATE_ITEM_NAME_4:
            case STATE_ITEM_BAG_4:
                break;
            default:
                ClearDialogWindowAndFrame(WIN_MSG, TRUE);
                break;
        }
        return TRUE;
    }
    return FALSE;
}

static void Task_WaitButtonPressOpening(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        if (!ClearWindowPlaySelectButtonPress())
            return;

        switch (sMiningUiState->loadGameState)
        {
            case STATE_GAME_FINISH:
            case STATE_ITEM_NAME_1:
            case STATE_ITEM_BAG_1:
            case STATE_ITEM_NAME_2:
            case STATE_ITEM_BAG_2:
            case STATE_ITEM_NAME_3:
            case STATE_ITEM_BAG_3:
            case STATE_ITEM_NAME_4:
            case STATE_ITEM_BAG_4:
                gTasks[taskId].func = Task_MiningPrintResult;
                break;
            case STATE_QUIT:
                ExitMiningUI(taskId);
                break;
            default:
                gTasks[taskId].func = Task_MiningMainInput;
                break;
        }
    }
    else if (JOY_NEW(A_BUTTON))
    {
        while(1)
        {
            if (!RunTextPrintersAndIsPrinter0Active())
                break;
        }
    }
}

static void Task_MiningPrintResult(u8 taskId)
{
    u32 itemIndex = ConvertLoadGameStateToItemIndex();
    u32 itemId = GetBuriedBagItemId(itemIndex);

    if (gPaletteFade.active)
        return;

    switch (sMiningUiState->loadGameState)
    {
        case STATE_GAME_START:
            gTasks[taskId].func = Task_MiningMainInput;
            break;
        case STATE_GAME_FINISH:
            HandleGameFinish(taskId);
            break;
        case STATE_ITEM_NAME_1:
        case STATE_ITEM_NAME_2:
        case STATE_ITEM_NAME_3:
        case STATE_ITEM_NAME_4:
            CheckItemAndPrint(taskId,itemIndex,itemId);
            break;
        case STATE_ITEM_BAG_1:
        case STATE_ITEM_BAG_2:
        case STATE_ITEM_BAG_3:
        case STATE_ITEM_BAG_4:
            GetItemOrPrintError(taskId,itemIndex,itemId);
            break;
        default:
            ExitMiningUI(taskId);
            break;
    }
}

static u32 ConvertLoadGameStateToItemIndex(void)
{
    switch (sMiningUiState->loadGameState)
    {
        default:
        case STATE_ITEM_NAME_1:
        case STATE_ITEM_BAG_1:
            return 0;
        case STATE_ITEM_NAME_2:
        case STATE_ITEM_BAG_2:
            return 1;
        case STATE_ITEM_NAME_3:
        case STATE_ITEM_BAG_3:
            return 2;
        case STATE_ITEM_NAME_4:
        case STATE_ITEM_BAG_4:
            return 3;
    }
}

static void GetItemOrPrintError(u8 taskId, u32 itemIndex, u32 itemId)
{
    sMiningUiState->loadGameState++;

    if (itemId == ITEM_NONE)
        return;

    if (AddBagItem(itemId,1))
        return;

    PrintMessage(sText_TooBad);
    gTasks[taskId].func = Task_WaitButtonPressOpening;
}

static void CheckItemAndPrint(u8 taskId, u32 itemIndex, u32 itemId)
{
    sMiningUiState->loadGameState++;

    if (itemId == ITEM_NONE)
        return;

    if (!GetBuriedItemStatus(itemIndex))
        return;

    PrintItemSuccess(itemId);
    gTasks[taskId].func = Task_WaitButtonPressOpening;
}

static void MakeCursorInvisible(void)
{
    gSprites[sMiningUiState->cursorSpriteIndex].invisible = 1;
}

static void Task_WallCollapseDelay(u8 taskId)
{
    u16* tilemapBuf = GetBgTilemapBuffer(1);

    switch(sMiningUiState->delayCounter)
    {
        default:
            sMiningUiState->delayCounter++;
            break;
        case 0:
        case 2:
        case 4:
        case 6:
        case 8:
        case 10:
        case 12:
        case 14:
        case 16:
        case 18:
        case 20:
        case 22:
        case 24:
        case 26:
        case 28:
        case 30:
        case 32:
        case 34:
        case 36:
        case 38:
            for (u32 j = 0; j < 30; j++)
            {
                OverwriteTileDataInTilemapBuffer(1, j, (sMiningUiState->delayCounter/2), tilemapBuf, 2);
                ScheduleBgCopyTilemapToVram(1);
                DoScheduledBgTilemapCopiesToVram();
            }
            sMiningUiState->delayCounter++;
            break;
        case 40:
            DestroyTask(taskId);
            sMiningUiState->isCollapseAnimActive = FALSE;
            PrintMessage(sText_TheWall);
            break;
    }
}

static void WallCollapseAnimation()
{
    sMiningUiState->delayCounter = 0;
    sMiningUiState->isCollapseAnimActive = TRUE;
    ShowBg(1);
    CreateTask(Task_WallCollapseDelay, 0);
}

static void HandleGameFinish(u8 taskId)
{
    MakeCursorInvisible();

    if (IsStressLevelMax())
        // Here, we only set the Shake Duration. The Task, which handles the shake effect, is created by the input handler.
        sMiningUiState->shakeDuration = 6;
    else
        PrintMessage(sText_EverythingWas);

    sMiningUiState->loadGameState++;
    gTasks[taskId].func = Task_WaitButtonPressOpening;
}

static void PrintItemSuccess(u32 itemId)
{
    CopyItemName(itemId,gStringVar1);
    StringExpandPlaceholders(gStringVar2,sText_WasObtained);
    PrintMessage(gStringVar2);
}

static u32 GetTotalNumberOfBuriedItems(void)
{
    u32 itemIndex = 0;
    u32 count = 0;

    for (itemIndex = 0; itemIndex < MINING_MAX_NUM_BURIED_ITEMS; itemIndex++)
        if (GetBuriedBagItemId(itemIndex))
            count++;

    return count;
}

static u32 GetNumberOfFoundItems(void)
{
    u32 itemIndex = 0;
    u32 count = 0;

    for (itemIndex = 0; itemIndex < MINING_MAX_NUM_BURIED_ITEMS; itemIndex++)
        if (GetBuriedItemStatus(itemIndex))
            count++;

    return count;
}

static bool32 AreAllItemsFound(void)
{
    return (GetTotalNumberOfBuriedItems() == GetNumberOfFoundItems());
}

static void InitBuriedItems(void)
{
    u32 index = 0;
    for (index = 0; index < MINING_MAX_NUM_BURIED_ITEMS; index++)
    {
        SetBuriedItemsId(index, MININGID_NONE);
        SetBuriedItemStatus(index, FALSE);
    }
}

static void SetBuriedItemsId(u32 index, u32 itemId)
{
    sMiningUiState->buriedItems[index].bagItemId = MiningItemList[itemId].bagItemId;
    sMiningUiState->buriedItems[index].miningItemId = MiningItemList[itemId].miningItemId;
}

static void SetBuriedItemStatus(u32 index, bool32 status)
{
    sMiningUiState->buriedItems[index].isDugUp = status;
}

static u32 GetBuriedBagItemId(u32 index)
{
    return sMiningUiState->buriedItems[index].bagItemId;
}

static u32 GetBuriedMiningItemId(u32 index)
{
    return sMiningUiState->buriedItems[index].miningItemId;
}

static bool32 GetBuriedItemStatus(u32 index)
{
    return sMiningUiState->buriedItems[index].isDugUp;
}

static void ExitMiningUI(u8 taskId)
{
    PlaySE(SE_PC_OFF);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_MiningFadeAndExitMenu;
}

static u32 Debug_SetNumberOfBuriedItems(u32 rnd)
{
#if DEBUG_ENABLE_ITEM_GENERATION_OPTIONS == TRUE
    return DEBUG_DESIRED_NUMBER_OF_ITEMS;
#else
    return rnd;
#endif
}

#if DEBUG_ENABLE_ITEM_GENERATION_OPTIONS == TRUE
static u32 Debug_CreateRandomItem(u32 random, u32 itemId)
{
    switch (debugVariable++)
    {
        case 0: return DEBUG_MININGID_ITEM1;
        case 1: return DEBUG_MININGID_ITEM2;
        case 2: return DEBUG_MININGID_ITEM3;
        case 3: return DEBUG_MININGID_ITEM4;
        default: return itemId;
    }
}
#endif

static u32 Debug_DetermineStoneSize(u32 stone, u32 stoneIndex)
{
#if DEBUG_ENABLE_ITEM_GENERATION_OPTIONS == TRUE
    u32 desiredStones[2] = {DEBUG_MININGID_STONE1, DEBUG_MININGID_STONE2};
    stoneIndex = (stoneIndex > 1) ? 1 : stoneIndex;
    return (desiredStones[stoneIndex] == MININGID_NONE) ? stone : desiredStones[stoneIndex];
#else
    return stone;
#endif
}

static void Debug_DetermineLocation(u32* x, u32* y, u32 item)
{
#if DEBUG_ENABLE_ITEM_GENERATION_OPTIONS == TRUE
    {
        switch (item)
        {
            default:
            case 1:
                *x = 1;
                *y = 1;
                break;
            case 2:
                *x = 1;
                *y = 5;
                break;
            case 3:
                *x = 7;
                *y = 1;
                break;
            case 4:
                *x = 7;
                *y = 5;
                break;
        }
    }
#endif
    return;
}

static void Debug_RaiseSpritePriority(u32 spriteId)
{
#if DEBUG_ENABLE_ITEM_GENERATION_OPTIONS == TRUE
    gSprites[spriteId].oam.priority = 0;
#endif
}
