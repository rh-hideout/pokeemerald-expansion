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
static bool32 Mining_InitBgs(void);
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
static bool32 Mining_LoadBgGraphics(void);
static void Mining_LoadSpriteGraphics(void);
static void Mining_FreeResources(void);
static void Mining_UpdateStressLevel(void);
static void Mining_UpdateTerrain(void);
static void Mining_DrawRandomTerrain(void);
static void DoDrawRandomItem(u32 itemStateId, enum MiningId itemId);
static void DoDrawRandomStone(enum MiningId itemId);
#if MINING_DEBUG_ENABLE == FALSE || MINING_DEBUG_ENABLE_STONE_GENERATION_OPTIONS == FALSE
static bool32 DoesStoneFitInItemMap(enum MiningId itemId);
#endif
static bool32 CanStoneBePlacedAtXY(u32 x, u32 y, enum MiningId itemId);
static void Mining_CheckItemFound(void);
static void PrintMessage(const u8 *string);
static void InitMiningWindows(void);
static bool32 IsStressLevelMax(void);
#if MINING_DEBUG_ENABLE == FALSE || MINING_DEBUG_INFINITE_HITS == FALSE
static void EndMining(u8 taskId);
static bool32 AreAllItemsFound(void);
static u32 GetNumberOfFoundItems(void);
static void WallCollapseAnimation();
#endif
static u32 ConvertLoadGameStateToItemIndex(void);
static void GetItemOrPrintError(u8 taskId, u32 itemIndex, enum Item itemId);
static void CheckItemAndPrint(u8 taskId, u32 itemIndex, enum Item itemId);
static void MakeCursorInvisible(void);
static void HandleGameFinish(u8 taskId);
static void PrintItemSuccess(enum Item itemId);
static u32 GetTotalNumberOfBuriedItems(void);
static void InitBuriedItems(void);
static void SetBuriedItemsId(u32 index, enum MiningId itemId);
static void SetBuriedItemStatus(u32 index, bool32 status);
static enum Item GetBuriedBagItemId(u32 index);
static enum MiningId GetBuriedMiningItemId(u32 index);
static bool32 GetBuriedItemStatus(u32 index);
static void ExitMiningUI(u8 taskId);

struct BuriedItem
{
    enum Item bagItemId;
    enum MiningId miningItemId;
    bool32 isDugUp;
    bool32 isSelected;
    u32 buriedState;
    u32 spriteId;
};

struct MiningState
{
    MainCallback leavingCallback;   // Callback to leave the Ui
    u32 loadGameState;
    u32 layerMap[MINING_WALL_SIZE];             // Array representing the screen. Determines virtual layers
    u32 itemMap[MINING_WALL_SIZE];              // Determines where items are on the screen
    u32 cursorX;
    u32 cursorY;

    u8 *sBg1TilemapBuffer;
    u8 *sBg2TilemapBuffer;
    u8 *sBg3TilemapBuffer;

    // Items and Stones
    struct BuriedItem buriedItems[MINING_MAX_NUM_BURIED_ITEMS];
    struct BuriedItem buriedStones[MINING_MAX_NUM_BURIED_STONES];

    // Tools
    bool32 tool;    // Hammer or Pickaxe
    u32 cursorSpriteIndex;
    u32 bRedSpriteIndex;
    u32 bBlueSpriteIndex;

    // Shake
    bool32 shouldShake;     // If set to true, shake gets executed every VBlank
    u32 shakeState;         // State of shaking steps
    u32 shakeDuration;      // How many times should the shaking loop?
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
#define WIN_MSG             0

// Other Sprite Tags
enum
{
    TAG_DUMMY,
    TAG_CURSOR,
    TAG_BUTTONS,
    TAG_PAL_ITEM1,
    TAG_PAL_ITEM2,
    TAG_PAL_ITEM3,
    TAG_PAL_ITEM4,
    TAG_PAL_HIT_EFFECTS,
    TAG_HIT_EFFECT_HAMMER,
    TAG_HIT_EFFECT_PICKAXE,
    TAG_HIT_HAMMER,
    TAG_HIT_PICKAXE,
};

enum
{
    RARITY_COMMON,
    RARITY_UNCOMMON,
    RARITY_RARE,
};

#define BLUE_BUTTON     0
#define RED_BUTTON      1

#if MINING_DEBUG_ENABLE == TRUE && MINING_DEBUG_ALL_SPRITES_VISIBLE == TRUE
#define ITEM_STONE_SPRITE_PRIORITY  0
#else
#define ITEM_STONE_SPRITE_PRIORITY  3
#endif

enum
{
    STATE_CLEAR_SCREEN,
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
    ITEM_STATE_ID_NONE,     // Placeholder ID
    ITEM_STATE_ID_1,        // ID for item 1 in zone 1
    ITEM_STATE_ID_2,        // ID for item 2 in zone 2
    ITEM_STATE_ID_3,        // ID for item 3 in zone 3
    ITEM_STATE_ID_4,        // ID for item 4 in zone 4
    ITEM_STATE_ID_5,        // probably leftover from refactoring ?
    ITEM_STATE_ID_6,        // Stone
};

enum
{
    BG_TEXT_BOX,
    BG_COLLAPSE_SCREEN,
    BG_STRESS_LEVEL,
    BG_UI_GFX,
};

static EWRAM_DATA struct MiningState *sMiningUiState = NULL;

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
static const u32 sUiTiles[] = INCGFX_U32("graphics/mining_minigame/ui.png", ".4bpp.smol");
static const u32 sUiTilemap[] = INCGFX_U32("graphics/mining_minigame/ui.bin", ".smolTM");
static const u16 sUiPalette[] = INCGFX_U16("graphics/mining_minigame/ui.png", ".gbapal");

// Collapse screen
static const u32 sCollapseScreenTiles[] = INCGFX_U32("graphics/mining_minigame/collapse.png", ".4bpp.smol");
static const u16 sCollapseScreenPalette[] = INCGFX_U16("graphics/mining_minigame/collapse.png", ".gbapal");

static const u32 sStressLevelAndTerrainTiles[] = INCGFX_U32("graphics/mining_minigame/stress_level_terrain.png", ".4bpp.smol");
static const u32 sStressLevelAndTerrainTilemap[] = INCGFX_U32("graphics/mining_minigame/stress_level_terrain.bin", ".smolTM");
static const u16 sStressLevelAndTerrainPalette[] = INCGFX_U16("graphics/mining_minigame/stress_level_terrain.png", ".gbapal");

static const u8 sMiningMessageBoxGfx[] = INCGFX_U8("graphics/mining_minigame/message_box.png", ".4bpp");
static const u16 sMiningMessageBoxPal[] = INCGFX_U16("graphics/mining_minigame/message_box.pal", ".gbapal");

// Sprite data
const u32 gCursorGfx[] = INCGFX_U32("graphics/mining_minigame/cursor.png", ".4bpp.smol");
const u16 gCursorPal[] = INCGFX_U16("graphics/mining_minigame/cursor.png", ".gbapal");

const u32 gButtonGfx[] = INCGFX_U32("graphics/mining_minigame/buttons.png", ".4bpp.smol");
const u16 gButtonPal[] = INCGFX_U16("graphics/mining_minigame/buttons.png", ".gbapal");

const u32 gHitEffectHammerGfx[] = INCGFX_U32("graphics/mining_minigame/hit_effect_hammer.png", ".4bpp.smol");
const u32 gHitEffectPickaxeGfx[] = INCGFX_U32("graphics/mining_minigame/hit_effect_pickaxe.png", ".4bpp.smol");
const u32 gHitHammerGfx[] = INCGFX_U32("graphics/mining_minigame/hit_hammer.png", ".4bpp.smol");
const u32 gHitPickaxeGfx[] = INCGFX_U32("graphics/mining_minigame/hit_pickaxe.png", ".4bpp.smol");
const u16 gHitEffectPal[] = INCGFX_U16("graphics/mining_minigame/hit_effects.pal", ".gbapal");

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
    {gButtonGfx, 4096, TAG_BUTTONS},
    {NULL},
};

static const struct SpritePalette sSpritePal_Buttons[] =
{
    {gButtonPal, TAG_BUTTONS},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_HitEffectHammer[] =
{
    {gHitEffectHammerGfx, 2048, TAG_HIT_EFFECT_HAMMER},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_HitEffectPickaxe[] =
{
    {gHitEffectPickaxeGfx, 2048, TAG_HIT_EFFECT_PICKAXE},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_HitHammer[] =
{
    {gHitHammerGfx, 1024, TAG_HIT_HAMMER},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_HitPickaxe[] =
{
    {gHitPickaxeGfx, 1024, TAG_HIT_PICKAXE},
    {NULL},
};

static const struct SpritePalette sSpritePal_HitEffect[] =
{
    {gHitEffectPal, TAG_PAL_HIT_EFFECTS},
    {NULL},
};

static const struct OamData sOamCursor =
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

static const struct OamData sOamButton =
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

static const struct OamData sOamHitEffect =
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

static const struct OamData sOamHitTools =
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

static const struct OamData sOamItem64x64 =
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
    .priority = ITEM_STONE_SPRITE_PRIORITY,
    .paletteNum = 0,
};

static const union AnimCmd sAnimCmdCursor[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sCursorAnim[] =
{
    sAnimCmdCursor,
};

static const union AnimCmd sAnimCmdButton_RedNotPressed[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmdButton_RedPressed[] =
{
    ANIMCMD_FRAME(32, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmdButton_BlueNotPressed[] =
{
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmdButton_BluePressed[] =
{
    ANIMCMD_FRAME(MINING_WALL_SIZE, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sButtonRedAnim[] =
{
    sAnimCmdButton_RedNotPressed,
    sAnimCmdButton_RedPressed,
};

static const union AnimCmd *const sButtonBlueAnim[] =
{
    sAnimCmdButton_BluePressed,
    sAnimCmdButton_BlueNotPressed,
};

static const union AnimCmd sAnimCmd_EffectHammerHit[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_EffectHammerNotHit[] =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_EffectPickaxeHit[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnimCmd_EffectPickaxeNotHit[] =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sHitHammerAnim[] =
{
    sAnimCmd_EffectHammerHit,
    sAnimCmd_EffectHammerNotHit,
};

static const union AnimCmd *const sHitPickaxeAnim[] =
{
    sAnimCmd_EffectPickaxeHit,
    sAnimCmd_EffectPickaxeNotHit,
};

static const struct SpriteTemplate sSpriteCursor =
{
    .tileTag = TAG_CURSOR,
    .paletteTag = TAG_CURSOR,
    .oam = &sOamCursor,
    .anims = sCursorAnim,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteButtonRed =
{
    .tileTag = TAG_BUTTONS,
    .paletteTag = TAG_BUTTONS,
    .oam = &sOamButton,
    .anims = sButtonRedAnim,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteButtonBlue =
{
    .tileTag = TAG_BUTTONS,
    .paletteTag = TAG_BUTTONS,
    .oam = &sOamButton,
    .anims = sButtonBlueAnim,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteHitEffectHammer =
{
    .tileTag = TAG_HIT_EFFECT_HAMMER,
    .paletteTag = TAG_PAL_HIT_EFFECTS,
    .oam = &sOamHitEffect,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteHitEffectPickaxe =
{
    .tileTag = TAG_HIT_EFFECT_PICKAXE,
    .paletteTag = TAG_PAL_HIT_EFFECTS,
    .oam = &sOamHitEffect,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteHitHammer =
{
    .tileTag = TAG_HIT_HAMMER,
    .paletteTag = TAG_PAL_HIT_EFFECTS,
    .oam = &sOamHitTools ,
    .anims = sHitHammerAnim,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteHitPickaxe =
{
    .tileTag = TAG_HIT_PICKAXE,
    .paletteTag = TAG_PAL_HIT_EFFECTS,
    .oam = &sOamHitTools ,
    .anims = sHitPickaxeAnim,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const u16 sStonePal[] = INCGFX_U16("graphics/mining_minigame/stones/stones.pal", ".gbapal");
static const u32 sStone1x4Gfx[] = INCGFX_U32("graphics/mining_minigame/stones/stone_1x4.png", ".4bpp.smol");
static const u32 sStone4x1Gfx[] = INCGFX_U32("graphics/mining_minigame/stones/stone_4x1.png", ".4bpp.smol");
static const u32 sStone2x4Gfx[] = INCGFX_U32("graphics/mining_minigame/stones/stone_2x4.png", ".4bpp.smol");
static const u32 sStone4x2Gfx[] = INCGFX_U32("graphics/mining_minigame/stones/stone_4x2.png", ".4bpp.smol");
static const u32 sStone2x2Gfx[] = INCGFX_U32("graphics/mining_minigame/stones/stone_2x2.png", ".4bpp.smol");
static const u32 sStone3x3Gfx[] = INCGFX_U32("graphics/mining_minigame/stones/stone_3x3.png", ".4bpp.smol");
static const u32 sStoneSnake1Gfx[] = INCGFX_U32("graphics/mining_minigame/stones/stone_snake1.png", ".4bpp.smol");
static const u32 sStoneSnake2Gfx[] = INCGFX_U32("graphics/mining_minigame/stones/stone_snake2.png", ".4bpp.smol");
static const u32 sStoneMushroom1Gfx[] = INCGFX_U32("graphics/mining_minigame/stones/stone_mushroom1.png", ".4bpp.smol");
static const u32 sStoneMushroom2Gfx[] = INCGFX_U32("graphics/mining_minigame/stones/stone_mushroom2.png", ".4bpp.smol");

static const u32 sItemHeartScaleGfx[] = INCGFX_U32("graphics/mining_minigame/items/heart_scale.png", ".4bpp.smol");
static const u16 sItemHeartScalePal[] = INCGFX_U16("graphics/mining_minigame/items/heart_scale.png", ".gbapal");

static const u32 sItemHardStoneGfx[] = INCGFX_U32("graphics/mining_minigame/items/hard_stone.png", ".4bpp.smol");
static const u16 sItemHardStonePal[] = INCGFX_U16("graphics/mining_minigame/items/hard_stone.png", ".gbapal");

static const u32 sItemReviveGfx[] = INCGFX_U32("graphics/mining_minigame/items/revive.png", ".4bpp.smol");
static const u16 sItemRevivePal[] = INCGFX_U16("graphics/mining_minigame/items/revive.png", ".gbapal");

static const u32 sItemStarPieceGfx[] = INCGFX_U32("graphics/mining_minigame/items/star_piece.png", ".4bpp.smol");
static const u16 sItemStarPiecePal[] = INCGFX_U16("graphics/mining_minigame/items/star_piece.png", ".gbapal");

static const u32 sItemDampRockGfx[] = INCGFX_U32("graphics/mining_minigame/items/damp_rock.png", ".4bpp.smol");
static const u16 sItemDampRockPal[] = INCGFX_U16("graphics/mining_minigame/items/damp_rock.png", ".gbapal");

static const u32 sItemRedShardGfx[] = INCGFX_U32("graphics/mining_minigame/items/red_shard.png", ".4bpp.smol");
static const u16 sItemRedShardPal[] = INCGFX_U16("graphics/mining_minigame/items/red_shard.png", ".gbapal");

static const u32 sItemBlueShardGfx[] = INCGFX_U32("graphics/mining_minigame/items/blue_shard.png", ".4bpp.smol");
static const u16 sItemBlueShardPal[] = INCGFX_U16("graphics/mining_minigame/items/blue_shard.png", ".gbapal");

static const u32 sItemYellowShardGfx[] = INCGFX_U32("graphics/mining_minigame/items/yellow_shard.png", ".4bpp.smol");
static const u16 sItemYellowShardPal[] = INCGFX_U16("graphics/mining_minigame/items/yellow_shard.png", ".gbapal");

static const u32 sItemGreenShardGfx[] = INCGFX_U32("graphics/mining_minigame/items/green_shard.png", ".4bpp.smol");
static const u16 sItemGreenShardPal[] = INCGFX_U16("graphics/mining_minigame/items/green_shard.png", ".gbapal");

static const u32 sItemIronBallGfx[] = INCGFX_U32("graphics/mining_minigame/items/iron_ball.png", ".4bpp.smol");
static const u16 sItemIronBallPal[] = INCGFX_U16("graphics/mining_minigame/items/iron_ball.png", ".gbapal");

static const u32 sItemReviveMaxGfx[] = INCGFX_U32("graphics/mining_minigame/items/revive_max.png", ".4bpp.smol");
static const u16 sItemReviveMaxPal[] = INCGFX_U16("graphics/mining_minigame/items/revive_max.png", ".gbapal");

static const u32 sItemEverStoneGfx[] = INCGFX_U32("graphics/mining_minigame/items/ever_stone.png", ".4bpp.smol");
static const u16 sItemEverStonePal[] = INCGFX_U16("graphics/mining_minigame/items/ever_stone.png", ".gbapal");

static const u32 sItemOvalStoneGfx[] = INCGFX_U32("graphics/mining_minigame/items/oval_stone.png", ".4bpp.smol");
static const u16 sItemOvalStonePal[] = INCGFX_U16("graphics/mining_minigame/items/oval_stone.png", ".gbapal");

static const u32 sItemLightClayGfx[] = INCGFX_U32("graphics/mining_minigame/items/light_clay.png", ".4bpp.smol");
static const u16 sItemLightClayPal[] = INCGFX_U16("graphics/mining_minigame/items/light_clay.png", ".gbapal");

static const u32 sItemHeatRockGfx[] = INCGFX_U32("graphics/mining_minigame/items/heat_rock.png", ".4bpp.smol");
static const u16 sItemHeatRockPal[] = INCGFX_U16("graphics/mining_minigame/items/heat_rock.png", ".gbapal");

static const u32 sItemIcyRockGfx[] = INCGFX_U32("graphics/mining_minigame/items/icy_rock.png", ".4bpp.smol");
static const u16 sItemIcyRockPal[] = INCGFX_U16("graphics/mining_minigame/items/icy_rock.png", ".gbapal");

static const u32 sItemSmoothRockGfx[] = INCGFX_U32("graphics/mining_minigame/items/smooth_rock.png", ".4bpp.smol");
static const u16 sItemSmoothRockPal[] = INCGFX_U16("graphics/mining_minigame/items/smooth_rock.png", ".gbapal");

static const u32 sItemLeafStoneGfx[] = INCGFX_U32("graphics/mining_minigame/items/leaf_stone.png", ".4bpp.smol");
static const u16 sItemLeafStonePal[] = INCGFX_U16("graphics/mining_minigame/items/leaf_stone.png", ".gbapal");

static const u32 sItemFireStoneGfx[] = INCGFX_U32("graphics/mining_minigame/items/fire_stone.png", ".4bpp.smol");
static const u16 sItemFireStonePal[] = INCGFX_U16("graphics/mining_minigame/items/fire_stone.png", ".gbapal");

static const u32 sItemWaterStoneGfx[] = INCGFX_U32("graphics/mining_minigame/items/water_stone.png", ".4bpp.smol");
static const u16 sItemWaterStonePal[] = INCGFX_U16("graphics/mining_minigame/items/water_stone.png", ".gbapal");

static const u32 sItemThunderStoneGfx[] = INCGFX_U32("graphics/mining_minigame/items/thunder_stone.png", ".4bpp.smol");
static const u16 sItemThunderStonePal[] = INCGFX_U16("graphics/mining_minigame/items/thunder_stone.png", ".gbapal");

static const u32 sItemMoonStoneGfx[] = INCGFX_U32("graphics/mining_minigame/items/moon_stone.png", ".4bpp.smol");
static const u16 sItemMoonStonePal[] = INCGFX_U16("graphics/mining_minigame/items/moon_stone.png", ".gbapal");

static const u32 sItemSunStoneGfx[] = INCGFX_U32("graphics/mining_minigame/items/sun_stone.png", ".4bpp.smol");
static const u16 sItemSunStonePal[] = INCGFX_U16("graphics/mining_minigame/items/sun_stone.png", ".gbapal");

static const u32 sItemOddKeyStoneGfx[] = INCGFX_U32("graphics/mining_minigame/items/odd_key_stone.png", ".4bpp.smol");
static const u16 sItemOddKeyStonePal[] = INCGFX_U16("graphics/mining_minigame/items/odd_key_stone.png", ".gbapal");

static const u32 sItemSkullFossilGfx[] = INCGFX_U32("graphics/mining_minigame/items/skull_fossil.png", ".4bpp.smol");
static const u32 sItemArmorFossilGfx[] = INCGFX_U32("graphics/mining_minigame/items/armor_fossil.png", ".4bpp.smol");
static const u16 sItemFossilPal[] = INCGFX_U16("graphics/mining_minigame/items/fossil.pal", ".gbapal");

// Stone SpriteSheets and SpritePalettes
static const struct CompressedSpriteSheet sSpriteSheet_Stone1x4[] =
{
    {sStone1x4Gfx, 2048, MINING_TAG_STONE_1X4},
    {NULL},
};

static const struct SpritePalette sSpritePal_Stone1x4[] =
{
    {sStonePal, MINING_TAG_STONE_1X4},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_Stone4x1[] =
{
    {sStone4x1Gfx, 2048, MINING_TAG_STONE_4X1},
    {NULL},
};

static const struct SpritePalette sSpritePal_Stone4x1[] =
{
    {sStonePal, MINING_TAG_STONE_4X1},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_Stone2x4[] =
{
    {sStone2x4Gfx, 2048, MINING_TAG_STONE_2X4},
    {NULL},
};

static const struct SpritePalette sSpritePal_Stone2x4[] =
{
    {sStonePal, MINING_TAG_STONE_2X4},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_Stone4x2[] =
{
    {sStone4x2Gfx, 2048, MINING_TAG_STONE_4X2},
    {NULL},
};

static const struct SpritePalette sSpritePal_Stone4x2[] =
{
    {sStonePal, MINING_TAG_STONE_4X2},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_Stone2x2[] =
{
    {sStone2x2Gfx, 2048, MINING_TAG_STONE_2X2},
    {NULL},
};

static const struct SpritePalette sSpritePal_Stone2x2[] =
{
    {sStonePal, MINING_TAG_STONE_2X2},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_Stone3x3[] =
{
    {sStone3x3Gfx, 2048, MINING_TAG_STONE_3X3},
    {NULL},
};

static const struct SpritePalette sSpritePal_Stone3x3[] =
{
    {sStonePal, MINING_TAG_STONE_3X3},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_StoneSnake1[] =
{
    {sStoneSnake1Gfx, 2048, MINING_TAG_STONE_SNAKE1},
    {NULL},
};

static const struct SpritePalette sSpritePal_StoneSnake1[] =
{
    {sStonePal, MINING_TAG_STONE_SNAKE1},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_StoneSnake2[] =
{
    {sStoneSnake2Gfx, 2048, MINING_TAG_STONE_SNAKE2},
    {NULL},
};

static const struct SpritePalette sSpritePal_StoneSnake2[] =
{
    {sStonePal, MINING_TAG_STONE_SNAKE2},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_StoneMushroom1[] =
{
    {sStoneMushroom1Gfx, 2048, MINING_TAG_STONE_MUSHROOM1},
    {NULL},
};

static const struct SpritePalette sSpritePal_StoneMushroom1[] =
{
    {sStonePal, MINING_TAG_STONE_MUSHROOM1},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_StoneMushroom2[] =
{
    {sStoneMushroom2Gfx, 2048, MINING_TAG_STONE_MUSHROOM2},
    {NULL},
};

static const struct SpritePalette sSpritePal_StoneMushroom2[] =
{
    {sStonePal, MINING_TAG_STONE_MUSHROOM2},
    {NULL},
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemHeartScale =
{
    sItemHeartScaleGfx,
    2048,
    MINING_TAG_ITEM_HEARTSCALE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemHardStone =
{
    sItemHardStoneGfx,
    2048,
    MINING_TAG_ITEM_HARDSTONE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemRevive =
{
    sItemReviveGfx,
    2048,
    MINING_TAG_ITEM_REVIVE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemStarPiece =
{
    sItemStarPieceGfx,
    2048,
    MINING_TAG_ITEM_STAR_PIECE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemDampRock =
{
    sItemDampRockGfx,
    2048,
    MINING_TAG_ITEM_DAMP_ROCK,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemRedShard =
{
    sItemRedShardGfx,
    2048,
    MINING_TAG_ITEM_RED_SHARD
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemBlueShard =
{
    sItemBlueShardGfx,
    2048,
    MINING_TAG_ITEM_BLUE_SHARD
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemYellowShard =
{
    sItemYellowShardGfx,
    2048,
    MINING_TAG_ITEM_YELLOW_SHARD
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemGreenShard =
{
    sItemGreenShardGfx,
    2048,
    MINING_TAG_ITEM_GREEN_SHARD
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemIronBall =
{
    sItemIronBallGfx,
    2048,
    MINING_TAG_ITEM_IRON_BALL
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemReviveMax =
{
    sItemReviveMaxGfx,
    2048,
    MINING_TAG_ITEM_REVIVE_MAX
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemEverStone =
{
    sItemEverStoneGfx,
    2048,
    MINING_TAG_ITEM_EVER_STONE
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemOvalStone =
{
    sItemOvalStoneGfx,
    2048,
    MINING_TAG_ITEM_OVAL_STONE
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemLightClay =
{
    sItemLightClayGfx,
    2048,
    MINING_TAG_ITEM_LIGHT_CLAY
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemHeatRock =
{
    sItemHeatRockGfx,
    2048,
    MINING_TAG_ITEM_HEAT_ROCK,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemIcyRock =
{
    sItemIcyRockGfx,
    2048,
    MINING_TAG_ITEM_ICY_ROCK,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemSmoothRock =
{
    sItemSmoothRockGfx,
    2048,
    MINING_TAG_ITEM_SMOOTH_ROCK,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemLeafStone =
{
    sItemLeafStoneGfx,
    2048,
    MINING_TAG_ITEM_LEAF_STONE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemFireStone =
{
    sItemFireStoneGfx,
    2048,
    MINING_TAG_ITEM_FIRE_STONE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemWaterStone =
{
    sItemWaterStoneGfx,
    2048,
    MINING_TAG_ITEM_WATER_STONE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemThunderStone =
{
    sItemThunderStoneGfx,
    2048,
    MINING_TAG_ITEM_THUNDER_STONE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemMoonStone =
{
    sItemMoonStoneGfx,
    2048,
    MINING_TAG_ITEM_MOON_STONE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemSunStone =
{
    sItemSunStoneGfx,
    2048,
    MINING_TAG_ITEM_SUN_STONE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemOddKeyStone =
{
    sItemOddKeyStoneGfx,
    2048,
    MINING_TAG_ITEM_ODD_KEY_STONE,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemSkullFossil =
{
    sItemSkullFossilGfx,
    2048,
    MINING_TAG_ITEM_SKULL_FOSSIL,
};

static const struct CompressedSpriteSheet sSpriteSheet_ItemArmorFossil =
{
    sItemArmorFossilGfx,
    2048,
    MINING_TAG_ITEM_ARMOR_FOSSIL,
};

static const struct SpriteTemplate sSpriteStone1x4 =
{
    .tileTag = MINING_TAG_STONE_1X4,
    .paletteTag = MINING_TAG_STONE_1X4,
    .oam = &sOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteStone4x1 =
{
    .tileTag = MINING_TAG_STONE_4X1,
    .paletteTag = MINING_TAG_STONE_4X1,
    .oam = &sOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteStone2x4 =
{
    .tileTag = MINING_TAG_STONE_2X4,
    .paletteTag = MINING_TAG_STONE_2X4,
    .oam = &sOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteStone4x2 =
{
    .tileTag = MINING_TAG_STONE_4X2,
    .paletteTag = MINING_TAG_STONE_4X2,
    .oam = &sOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteStone2x2 =
{
    .tileTag = MINING_TAG_STONE_2X2,
    .paletteTag = MINING_TAG_STONE_2X2,
    .oam = &sOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteStone3x3 =
{
    .tileTag = MINING_TAG_STONE_3X3,
    .paletteTag = MINING_TAG_STONE_3X3,
    .oam = &sOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteStoneSnake1 =
{
    .tileTag = MINING_TAG_STONE_SNAKE1,
    .paletteTag = MINING_TAG_STONE_SNAKE1,
    .oam = &sOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteStoneSnake2 =
{
    .tileTag = MINING_TAG_STONE_SNAKE2,
    .paletteTag = MINING_TAG_STONE_SNAKE2,
    .oam = &sOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteStoneMushroom1 =
{
    .tileTag = MINING_TAG_STONE_MUSHROOM1,
    .paletteTag = MINING_TAG_STONE_MUSHROOM1,
    .oam = &sOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteStoneMushroom2 =
{
    .tileTag = MINING_TAG_STONE_MUSHROOM2,
    .paletteTag = MINING_TAG_STONE_MUSHROOM2,
    .oam = &sOamItem64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};


struct MiningItem
{
    enum Item bagItemId;
    u32 tag;
    const struct CompressedSpriteSheet *sheet;
    const u16 *paldata;
};

static const struct MiningItem sMiningItemList[] =
{
    [MININGID_NONE] =
    {
        .bagItemId = ITEM_NONE,
        .tag = 0,
        .sheet = NULL,
        .paldata = NULL,
    },
    [MININGID_HARD_STONE] =
    {
        .bagItemId = ITEM_HARD_STONE,
        .tag = MINING_TAG_ITEM_HARDSTONE,
        .sheet = &sSpriteSheet_ItemHardStone,
        .paldata = sItemHardStonePal,
    },
    [MININGID_REVIVE] =
    {
        .bagItemId = ITEM_REVIVE,
        .tag = MINING_TAG_ITEM_REVIVE,
        .sheet = &sSpriteSheet_ItemRevive,
        .paldata = sItemRevivePal,
    },
    [MININGID_STAR_PIECE] =
    {
        .bagItemId = ITEM_STAR_PIECE,
        .tag = MINING_TAG_ITEM_STAR_PIECE,
        .sheet = &sSpriteSheet_ItemStarPiece,
        .paldata = sItemStarPiecePal,
    },
    [MININGID_DAMP_ROCK] =
    {
        .bagItemId = ITEM_DAMP_ROCK,
        .tag = MINING_TAG_ITEM_DAMP_ROCK,
        .sheet = &sSpriteSheet_ItemDampRock,
        .paldata = sItemDampRockPal,
    },
    [MININGID_RED_SHARD] =
    {
        .bagItemId = ITEM_RED_SHARD,
        .tag = MINING_TAG_ITEM_RED_SHARD,
        .sheet = &sSpriteSheet_ItemRedShard,
        .paldata = sItemRedShardPal,
    },
    [MININGID_BLUE_SHARD] =
    {
        .bagItemId = ITEM_BLUE_SHARD,
        .tag = MINING_TAG_ITEM_BLUE_SHARD,
        .sheet = &sSpriteSheet_ItemBlueShard,
        .paldata = sItemBlueShardPal,
    },
    [MININGID_YELLOW_SHARD] =
    {
        .bagItemId = ITEM_YELLOW_SHARD,
        .tag = MINING_TAG_ITEM_YELLOW_SHARD,
        .sheet = &sSpriteSheet_ItemYellowShard,
        .paldata = sItemYellowShardPal,
    },
    [MININGID_GREEN_SHARD] =
    {
        .bagItemId = ITEM_GREEN_SHARD,
        .tag = MINING_TAG_ITEM_GREEN_SHARD,
        .sheet = &sSpriteSheet_ItemGreenShard,
        .paldata = sItemGreenShardPal,
    },
    [MININGID_IRON_BALL] =
    {
        .bagItemId = ITEM_IRON_BALL,
        .tag = MINING_TAG_ITEM_IRON_BALL,
        .sheet = &sSpriteSheet_ItemIronBall,
        .paldata = sItemIronBallPal,
    },
    [MININGID_REVIVE_MAX] =
    {
        .bagItemId = ITEM_MAX_REVIVE,
        .tag = MINING_TAG_ITEM_REVIVE_MAX,
        .sheet = &sSpriteSheet_ItemReviveMax,
        .paldata = sItemReviveMaxPal,
    },
    [MININGID_EVER_STONE] =
    {
        .bagItemId = ITEM_EVERSTONE,
        .tag = MINING_TAG_ITEM_EVER_STONE,
        .sheet = &sSpriteSheet_ItemEverStone,
        .paldata = sItemEverStonePal,
    },
    [MININGID_HEART_SCALE] =
    {
        .bagItemId = ITEM_HEART_SCALE,
        .tag = MINING_TAG_ITEM_HEARTSCALE,
        .sheet = &sSpriteSheet_ItemHeartScale,
        .paldata = sItemHeartScalePal,
    },
    [MININGID_OVAL_STONE] =
    {
        .bagItemId = ITEM_OVAL_STONE,
        .tag = MINING_TAG_ITEM_OVAL_STONE,
        .sheet = &sSpriteSheet_ItemOvalStone,
        .paldata = sItemOvalStonePal,
    },
    [MININGID_LIGHT_CLAY] =
    {
        .bagItemId = ITEM_LIGHT_CLAY,
        .tag = MINING_TAG_ITEM_LIGHT_CLAY,
        .sheet = &sSpriteSheet_ItemLightClay,
        .paldata = sItemLightClayPal,
    },
    [MININGID_HEAT_ROCK] =
    {
        .bagItemId = ITEM_HEAT_ROCK,
        .tag = MINING_TAG_ITEM_HEAT_ROCK,
        .sheet = &sSpriteSheet_ItemHeatRock,
        .paldata = sItemHeatRockPal,
    },
    [MININGID_ICY_ROCK] =
    {
        .bagItemId = ITEM_ICY_ROCK,
        .tag = MINING_TAG_ITEM_ICY_ROCK,
        .sheet = &sSpriteSheet_ItemIcyRock,
        .paldata = sItemIcyRockPal,
    },
    [MININGID_SMOOTH_ROCK] =
    {
        .bagItemId = ITEM_SMOOTH_ROCK,
        .tag = MINING_TAG_ITEM_SMOOTH_ROCK,
        .sheet = &sSpriteSheet_ItemSmoothRock,
        .paldata = sItemSmoothRockPal,
    },
    [MININGID_LEAF_STONE] =
    {
        .bagItemId = ITEM_LEAF_STONE,
        .tag = MINING_TAG_ITEM_LEAF_STONE,
        .sheet = &sSpriteSheet_ItemLeafStone,
        .paldata = sItemLeafStonePal,
    },
    [MININGID_FIRE_STONE] =
    {
        .bagItemId = ITEM_FIRE_STONE,
        .tag = MINING_TAG_ITEM_FIRE_STONE,
        .sheet = &sSpriteSheet_ItemFireStone,
        .paldata = sItemFireStonePal,
    },
    [MININGID_WATER_STONE] =
    {
        .bagItemId = ITEM_WATER_STONE,
        .tag = MINING_TAG_ITEM_WATER_STONE,
        .sheet = &sSpriteSheet_ItemWaterStone,
        .paldata = sItemWaterStonePal,
    },
    [MININGID_THUNDER_STONE] =
    {
        .bagItemId = ITEM_THUNDER_STONE,
        .tag = MINING_TAG_ITEM_THUNDER_STONE,
        .sheet = &sSpriteSheet_ItemThunderStone,
        .paldata = sItemThunderStonePal,
    },
    [MININGID_MOON_STONE] =
    {
        .bagItemId = ITEM_MOON_STONE,
        .tag = MINING_TAG_ITEM_MOON_STONE,
        .sheet = &sSpriteSheet_ItemMoonStone,
        .paldata = sItemMoonStonePal,
    },
    [MININGID_SUN_STONE] =
    {
        .bagItemId = ITEM_SUN_STONE,
        .tag = MINING_TAG_ITEM_SUN_STONE,
        .sheet = &sSpriteSheet_ItemSunStone,
        .paldata = sItemSunStonePal,
    },
    [MININGID_ODD_KEY_STONE] =
    {
        .bagItemId = ITEM_ODD_KEYSTONE,
        .tag = MINING_TAG_ITEM_ODD_KEY_STONE,
        .sheet = &sSpriteSheet_ItemOddKeyStone,
        .paldata = sItemOddKeyStonePal,
    },
    [MININGID_SKULL_FOSSIL] =
    {
        .bagItemId = ITEM_SKULL_FOSSIL,
        .tag = MINING_TAG_ITEM_SKULL_FOSSIL,
        .sheet = &sSpriteSheet_ItemSkullFossil,
        .paldata = sItemFossilPal,
    },
    [MININGID_ARMOR_FOSSIL] =
    {
        .bagItemId = ITEM_ARMOR_FOSSIL,
        .tag = MINING_TAG_ITEM_ARMOR_FOSSIL,
        .sheet = &sSpriteSheet_ItemArmorFossil,
        .paldata = sItemFossilPal,
    },
};

static const enum MiningId sItemRarityTable_Common[] =
{
    MININGID_HEART_SCALE,
    MININGID_RED_SHARD,
    MININGID_BLUE_SHARD,
    MININGID_YELLOW_SHARD,
    MININGID_GREEN_SHARD,
};

static const enum MiningId sItemRarityTable_Uncommon[] =
{
    MININGID_IRON_BALL,
    MININGID_HARD_STONE,
    MININGID_REVIVE,
    MININGID_EVER_STONE,
};

static const enum MiningId sItemRarityTable_Rare[] =
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

static u32 MiningUtil_GetTotalTileAmount(enum MiningId itemId)
{
    u32 result = 0;

    for (u32 i = 0; i < 16; i++)
    {
        if (sSpriteTileTable[itemId][i] == 1)
            result++;
    }
    if (result == 0)
        return result+1;

    return result;
}

static u32 MiningUtil_GetLeftValue(enum MiningId itemId)
{
    u32 left = 0;

    for (u32 x = 0; x < 4; x++)
    {
        for (u32 y = 0; y < 4; y++)
        {
            if (sSpriteTileTable[itemId][x + y * 4] == 1)
            {
                left++;
                break;
            }
        }
    }

    return left - 1;
}

static u32 MiningUtil_GetTopValue(enum MiningId itemId)
{
    u32 top = 0;

    for (u32 y = 0; y < 4; y++)
    {
        for (u32 x = 0; x < 4; x++)
        {
            if (sSpriteTileTable[itemId][x + y * 4] == 1)
            {
                top++;
                break;
            }
        }
    }

    return top - 1;
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
#if MINING_DEBUG_ENABLE == TRUE && MINING_DEBUG_ENABLE_ITEM_GENERATION_OPTIONS == TRUE
    u32 amountItemsToSelect;

    if (MINING_DEBUG_DESIRED_NUMBER_OF_ITEMS == 0)
        amountItemsToSelect = 2;
    else if (MINING_DEBUG_DESIRED_NUMBER_OF_ITEMS > 4)
        amountItemsToSelect = 4;
    else
        amountItemsToSelect = MINING_DEBUG_DESIRED_NUMBER_OF_ITEMS;

    for (u32 i = 0; i < amountItemsToSelect; i++)
        sMiningUiState->buriedItems[i].isSelected = TRUE;

#else
    u32 amountItemsToSelect = Random() % 3 + 2; // The `+ 2` says that the min. amount of items to be generated are 2.

    // Fisher-Yates shuffle implementation
    u32 n = 4;
    u32 zones[4] = {0, 1, 2, 3};

    // Do the shuffle
    for (u32 i = n - 1; i > 0; i--)
    {
        // Pick a random index from 0 to i (inclusive)
        u32 j = Random() % (i + 1);
        // Swap the current element with the element at random index
        u32 temp = zones[i];
        zones[i] = zones[j];
        zones[j] = temp;
    }

    // Select the zones from the shuffled array
    for (u32 i = 0; i < amountItemsToSelect; i++)
    {
        sMiningUiState->buriedItems[zones[i]].isSelected = TRUE;
    }
#endif

    SetMainCallback2(Mining_SetupCB);
}

static void Mining_SetupCB(void)
{
    switch (gMain.state)
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
        }
        else
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

#define TILEMAP_BUFFER_SIZE 2048

static bool32 Mining_InitBgs(void)
{
    ResetAllBgsCoordinates();

    sMiningUiState->sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    sMiningUiState->sBg2TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    sMiningUiState->sBg3TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);

    if (sMiningUiState->sBg1TilemapBuffer == NULL || sMiningUiState->sBg2TilemapBuffer == NULL || sMiningUiState->sBg3TilemapBuffer == NULL)
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
    if (gPaletteFade.active)
        return;

    SetMainCallback2(sMiningUiState->leavingCallback);
    Mining_FreeResources();
    DestroyTask(taskId);
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
    if (!sMiningUiState->toggleShakeDuringAnimation)
    {
        for (u32 i = 0; i < MAX_SPRITES; i++)
        {
            gSprites[i].x += dx;
            gSprites[i].y += dy;
        }
    }
}

static void MiningUi_Shake(u8 taskId)
{
    switch (sMiningUiState->shakeState)
    {
    case 0: // Left 1 - Down 1
        MakeCursorInvisible();
        if (!IsStressLevelMax() && Random() % 100 < 20) // 20 % chance of not shaking the screen
            sMiningUiState->toggleShakeDuringAnimation = TRUE;
        MoveItemSprites(-1, 1);
        sMiningUiState->shakeState++;
        break;
    case 1:
        if (!sMiningUiState->toggleShakeDuringAnimation)
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
        if (!sMiningUiState->toggleShakeDuringAnimation)
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
        if (!sMiningUiState->toggleShakeDuringAnimation)
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
        if (!sMiningUiState->toggleShakeDuringAnimation)
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
        if (!sMiningUiState->toggleShakeDuringAnimation)
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
        #if MINING_DEBUG_ENABLE == TRUE && MINING_DEBUG_INFINITE_HITS == TRUE
        gSprites[sMiningUiState->cursorSpriteIndex].invisible = 0;
        #else
        if (IsStressLevelMax())
            WallCollapseAnimation();
        if (!IsStressLevelMax())
            gSprites[sMiningUiState->cursorSpriteIndex].invisible = 0;
        #endif
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

static void OverwriteTileDataInTilemapBuffer(u8 tile, u8 x, u8 y, u16 *tilemapBuf, u8 pal)
{
    tilemapBuf[32 * y + x] = tile | (pal << 12);
}

static bool32 Mining_LoadBgGraphics(void)
{
    u16 *tilemapBuf = GetBgTilemapBuffer(1);

    switch (sMiningUiState->loadGameState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sCollapseScreenTiles, 0, 0, 0);
        DecompressAndCopyTileDataToVram(2, sStressLevelAndTerrainTiles, 0, 0, 0);
        DecompressAndCopyTileDataToVram(3, sUiTiles, 0, 0, 0);
        sMiningUiState->loadGameState++;
        break;
    case 1:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            for (u32 i = 0; i < 32; i++)
            {
                for (u32 j = 0; j < 32; j++)
                    OverwriteTileDataInTilemapBuffer(0, i, j, tilemapBuf, 2);
            }
            DecompressDataWithHeaderWram(sStressLevelAndTerrainTilemap, sMiningUiState->sBg2TilemapBuffer);
            DecompressDataWithHeaderWram(sUiTilemap, sMiningUiState->sBg3TilemapBuffer);
            sMiningUiState->loadGameState++;
        }
        break;
    case 2:
        LoadPalette(sCollapseScreenPalette, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
        LoadPalette(sStressLevelAndTerrainPalette, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
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
    for (u32 i = 0; i < MINING_WALL_SIZE; i++)
        sMiningUiState->itemMap[i] = MINING_ITEM_TILE_NONE;
}

#if MINING_DEBUG_ENABLE == FALSE || MINING_DEBUG_ENABLE_ITEM_GENERATION_OPTIONS == FALSE
static enum MiningId GetRandomItemId()
{
    u32 rarity, index;
    enum MiningId itemId = MININGID_NONE;
    u32 rnd = Random() % 7;

    if (rnd < 4)
        rarity = RARITY_COMMON;
    else if (rnd < 6)
        rarity = RARITY_UNCOMMON;
    else
        rarity = RARITY_RARE;

    switch (rarity)
    {
    case RARITY_COMMON:
        index = Random() % ARRAY_COUNT(sItemRarityTable_Common);
        itemId = sItemRarityTable_Common[index];
        break;
    case RARITY_UNCOMMON:
        index = Random() % ARRAY_COUNT(sItemRarityTable_Uncommon);
        itemId = sItemRarityTable_Uncommon[index];
        break;
    case RARITY_RARE:
        index = Random() % ARRAY_COUNT(sItemRarityTable_Rare);
        itemId = sItemRarityTable_Rare[index];
        break;
    }

    return itemId;
}
#endif

static void InitItemsIfSelected(u32 item)
{
    enum MiningId itemId = MININGID_NONE;
    if (sMiningUiState->buriedItems[item].isSelected)
    {
        #if MINING_DEBUG_ENABLE == TRUE && MINING_DEBUG_ENABLE_ITEM_GENERATION_OPTIONS == TRUE
        switch(item)
        {
        case 0:
            itemId = MINING_DEBUG_MININGID_ITEM1;
            break;
        case 1:
            itemId = MINING_DEBUG_MININGID_ITEM2;
            break;
        case 2:
            itemId = MINING_DEBUG_MININGID_ITEM3;
            break;
        case 3:
            itemId = MINING_DEBUG_MININGID_ITEM4;
            break;
        }
        #else
        itemId = GetRandomItemId();
        #endif
        SetBuriedItemsId(item, itemId);
        DoDrawRandomItem(item+1, itemId);
    }
}

static void Mining_LoadSpriteGraphics(void)
{
    LoadSpritePalette(sSpritePal_Cursor);
    LoadCompressedSpriteSheet(sSpriteSheet_Cursor);

    LoadSpritePalette(sSpritePal_Buttons);
    LoadCompressedSpriteSheet(sSpriteSheet_Buttons);

    ClearItemMap();

    // Items
    InitItemsIfSelected(0);
    InitItemsIfSelected(1);
    InitItemsIfSelected(2);
    InitItemsIfSelected(3);

    // Stones
    #if MINING_DEBUG_ENABLE == TRUE && MINING_DEBUG_ENABLE_STONE_GENERATION_OPTIONS == TRUE
    DoDrawRandomStone(MINING_DEBUG_MININGID_STONE1);
    DoDrawRandomStone(MINING_DEBUG_MININGID_STONE2);
    #else
    enum MiningId stone = MININGID_NONE;
    for (u32 i = 0; i < MINING_MAX_NUM_BURIED_STONES; i++)
    {
        stone = MININGID_NONE;
        while (!DoesStoneFitInItemMap(stone))
            stone = ((Random() % MINING_COUNT_ID_STONE) + MININGID_STONE_1x4);

        DoDrawRandomStone(stone);
    }
    #endif

    sMiningUiState->cursorSpriteIndex = CreateSprite(&sSpriteCursor, 8, 40, 0);
    sMiningUiState->cursorX = 0;
    sMiningUiState->cursorY = 2;
    sMiningUiState->bRedSpriteIndex = CreateSprite(&sSpriteButtonRed, 217, 78, 0);
    sMiningUiState->bBlueSpriteIndex = CreateSprite(&sSpriteButtonBlue, 217, 138, 1);
    sMiningUiState->tool = BLUE_BUTTON;
    LoadSpritePalette(sSpritePal_HitEffect);
    LoadCompressedSpriteSheet(sSpriteSheet_HitEffectHammer);
    LoadCompressedSpriteSheet(sSpriteSheet_HitEffectPickaxe);
    LoadCompressedSpriteSheet(sSpriteSheet_HitHammer);
    LoadCompressedSpriteSheet(sSpriteSheet_HitPickaxe);
}

static void Task_MiningWaitFadeIn(u8 taskId)
{
    if (gPaletteFade.active)
        return;

    ConvertIntToDecimalStringN(gStringVar1, GetTotalNumberOfBuriedItems(), STR_CONV_MODE_LEFT_ALIGN, 2);
    StringExpandPlaceholders(gStringVar2, COMPOUND_STRING("Something pinged in the wall!\n{STR_VAR_1} confirmed!"));
    PrintMessage(gStringVar2);
    gTasks[taskId].func = Task_WaitButtonPressOpening;
}

static void Task_MiningMainInput(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON && !sMiningUiState->shouldShake)
    {
        u32 cursorPos = sMiningUiState->cursorX + (sMiningUiState->cursorY - 2) * MINING_WALL_WIDTH;
        Mining_UpdateTerrain();
        Mining_UpdateStressLevel();
        ScheduleBgCopyTilemapToVram(2);
        DoScheduledBgTilemapCopiesToVram();
        BuildOamBuffer();

        if (sMiningUiState->tool == RED_BUTTON)
        {
            sMiningUiState->ShakeHitEffect = CreateSprite(&sSpriteHitEffectHammer, (sMiningUiState->cursorX * 16) + 8, (sMiningUiState->cursorY * 16) + 8, 0);
            sMiningUiState->ShakeHitTool = CreateSprite(&sSpriteHitHammer, (sMiningUiState->cursorX * 16) + 24, sMiningUiState->cursorY * 16, 0);

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
        }
        else
        {
            sMiningUiState->ShakeHitEffect = CreateSprite(&sSpriteHitEffectPickaxe, (sMiningUiState->cursorX * 16) + 8, (sMiningUiState->cursorY * 16) + 8, 0);
            sMiningUiState->ShakeHitTool = CreateSprite(&sSpriteHitPickaxe, (sMiningUiState->cursorX * 16) + 24, sMiningUiState->cursorY * 16, 0);
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
    else if (gMain.newAndRepeatedKeys & DPAD_LEFT && sMiningUiState->cursorX > MINING_WALL_BORDER_X_LEFT)
    {
        gSprites[sMiningUiState->cursorSpriteIndex].x -= 16;
        sMiningUiState->cursorX -= 1;
    }
    else if (gMain.newAndRepeatedKeys & DPAD_RIGHT && sMiningUiState->cursorX < MINING_WALL_BORDER_X_RIGHT)
    {
        gSprites[sMiningUiState->cursorSpriteIndex].x += 16;
        sMiningUiState->cursorX += 1;
    }
    else if (gMain.newAndRepeatedKeys & DPAD_UP && sMiningUiState->cursorY > MINING_WALL_BORDER_Y_UP)
    {
        gSprites[sMiningUiState->cursorSpriteIndex].y -= 16;
        sMiningUiState->cursorY -= 1;
    }
    else if (gMain.newAndRepeatedKeys & DPAD_DOWN && sMiningUiState->cursorY < MINING_WALL_BORDER_Y_DOWN)
    {
        gSprites[sMiningUiState->cursorSpriteIndex].y += 16;
        sMiningUiState->cursorY += 1;
    }
    else if (gMain.newAndRepeatedKeys & R_BUTTON)
    {
        StartSpriteAnim(&gSprites[sMiningUiState->bRedSpriteIndex], 1);
        StartSpriteAnim(&gSprites[sMiningUiState->bBlueSpriteIndex], 1);
        sMiningUiState->tool = RED_BUTTON;
        PlaySE(MINING_SE_TOOL_SWITCH);
    }
    else if (gMain.newAndRepeatedKeys & L_BUTTON)
    {
        StartSpriteAnim(&gSprites[sMiningUiState->bRedSpriteIndex], 0);
        StartSpriteAnim(&gSprites[sMiningUiState->bBlueSpriteIndex], 0);
        sMiningUiState->tool = BLUE_BUTTON;
        PlaySE(MINING_SE_TOOL_SWITCH);
    }

    #if MINING_DEBUG_ENABLE == FALSE || MINING_DEBUG_INFINITE_HITS == FALSE
    if (AreAllItemsFound())
        EndMining(taskId);

    if (IsStressLevelMax())
    {
        EndMining(taskId);
        PlaySE(SE_M_EARTHQUAKE);
    }
    #endif
}

static void StressLevel_Draw_0(u32 stressPosOffset, u16 *ptr)
{
    OverwriteTileDataInTilemapBuffer(0x07, 21 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x08, 22 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x09, 23 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x0E, 22 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x0F, 23 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x14, 23 - stressPosOffset * 3, 3, ptr, 0x01);
}

static void StressLevel_Draw_1(u32 stressPosOffset, u16 *ptr)
{
    OverwriteTileDataInTilemapBuffer(0x17, 21 - stressPosOffset * 3, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x18, 22 - stressPosOffset * 3, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x1B, 21 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x1C, 22 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x1D, 23 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x22, 22 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x23, 23 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x26, 23 - stressPosOffset * 3, 3, ptr, 0x01);
}

static void StressLevel_Draw_2(u32 stressPosOffset, u16 *ptr)
{
    OverwriteTileDataInTilemapBuffer(0x27, 20 - stressPosOffset * 3, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x28, 21 - stressPosOffset * 3, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x29, 22 - stressPosOffset * 3, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2A, 20 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2B, 21 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2C, 22 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2D, 23 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2E, 21 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2F, 22 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x30, 23 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x26, 23 - stressPosOffset * 3, 3, ptr, 0x01);
}

static void StressLevel_Draw_3(u32 stressPosOffset, u16 *ptr)
{
    // Clean up 0x27, 0x28 and 0x29 from StressLevel_Draw_2
    OverwriteTileDataInTilemapBuffer(0x00, 20 - stressPosOffset * 3, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x00, 21 - stressPosOffset * 3, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x00, 22 - stressPosOffset * 3, 0, ptr, 0x01);

    OverwriteTileDataInTilemapBuffer(0x31, 22 - stressPosOffset * 3, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x32, 20 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x33, 21 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x34, 22 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2D, 23 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x35, 20 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x36, 21 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x37, 22 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x30, 23 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x26, 23 - stressPosOffset * 3, 3, ptr, 0x01);
}

static void StressLevel_Draw_4(u32 stressPosOffset, u16 *ptr)
{
    // The same clean up as StressLevel_Draw_3 but only used when the hammer is used
    OverwriteTileDataInTilemapBuffer(0x00, 20 - stressPosOffset * 3, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x00, 21 - stressPosOffset * 3, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x00, 22 - stressPosOffset * 3, 0, ptr, 0x01);

    OverwriteTileDataInTilemapBuffer(0x38, 22 - stressPosOffset * 3, 0, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x39, 20 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3A, 21 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3B, 22 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2D, 23 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3C, 19 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3D, 20 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3E, 21 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3F, 22 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x30, 23 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x40, 19 - stressPosOffset * 3, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x41, 20 - stressPosOffset * 3, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x42, 21 - stressPosOffset * 3, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x26, 23 - stressPosOffset * 3, 3, ptr, 0x01);
}

static void StressLevel_Draw_5(u32 stressPosOffset, u16 *ptr)
{
    OverwriteTileDataInTilemapBuffer(0x43, 20 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x44, 21 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3B, 22 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2D, 23 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x45, 19 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x46, 20 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x47, 21 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3F, 22 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x30, 23 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x48, 19 - stressPosOffset * 3, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x49, 20 - stressPosOffset * 3, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x4A, 21 - stressPosOffset * 3, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x26, 23 - stressPosOffset * 3, 3, ptr, 0x01);
}

static void StressLevel_Draw_6(u32 stressPosOffset, u16 *ptr)
{
    // Clean up 0x48 and 0x49 from StressLevel_Draw_5
    OverwriteTileDataInTilemapBuffer(0x00, 19 - stressPosOffset * 3, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x00, 20 - stressPosOffset * 3, 3, ptr, 0x01);

    OverwriteTileDataInTilemapBuffer(0x07, 18 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x08, 19 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x09, 20 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x44, 21 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3B, 22 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x2D, 23 - stressPosOffset * 3, 1, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x0E, 19 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x0F, 20 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x4B, 21 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x3F, 22 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x30, 23 - stressPosOffset * 3, 2, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x14, 20 - stressPosOffset * 3, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x4A, 21 - stressPosOffset * 3, 3, ptr, 0x01);
    OverwriteTileDataInTilemapBuffer(0x26, 23 - stressPosOffset * 3, 3, ptr, 0x01);
}

// This function draws the individual frames of the stress level indicator
static void StressLevel_UpdateRelativeToFramePos(u32 stressPosOffset, u16 *ptr)
{
    switch (sMiningUiState->stressLevelCount)
    {
    case 0:
        StressLevel_Draw_0(stressPosOffset, ptr);
        if (sMiningUiState->tool == RED_BUTTON)
            sMiningUiState->stressLevelCount++;
        sMiningUiState->stressLevelCount++;
        break;
    case 1:
        StressLevel_Draw_1(stressPosOffset, ptr);
        if (sMiningUiState->tool == RED_BUTTON)
            sMiningUiState->stressLevelCount++;
        sMiningUiState->stressLevelCount++;
        break;
    case 2:
        StressLevel_Draw_2(stressPosOffset, ptr);
        if (sMiningUiState->tool == RED_BUTTON)
            sMiningUiState->stressLevelCount++;
        sMiningUiState->stressLevelCount++;
        break;
    case 3:
        StressLevel_Draw_3(stressPosOffset, ptr);
        if (sMiningUiState->tool == RED_BUTTON)
            sMiningUiState->stressLevelCount++;
        sMiningUiState->stressLevelCount++;
        break;
    case 4:
        StressLevel_Draw_4(stressPosOffset, ptr);
        if (sMiningUiState->tool == RED_BUTTON)
            sMiningUiState->stressLevelCount++;
        sMiningUiState->stressLevelCount++;
        break;
    case 5:
        StressLevel_Draw_5(stressPosOffset, ptr);
        sMiningUiState->stressLevelCount++;
        break;
    case 6:
        StressLevel_Draw_6(stressPosOffset, ptr);
        if (sMiningUiState->stressLevelPos == 7)
        {
            OverwriteTileDataInTilemapBuffer(0x00, 18 - stressPosOffset * 3, 1, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x00, 19 - stressPosOffset * 3, 1, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x00, 20 - stressPosOffset * 3, 1, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x00, 19 - stressPosOffset * 3, 2, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x00, 20 - stressPosOffset * 3, 2, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x00, 20 - stressPosOffset * 3, 3, ptr, 0x01);
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
    StressLevel_UpdateRelativeToFramePos(sMiningUiState->stressLevelPos, ptr);
}

// Draws a tile layer to the screen.
static void Terrain_DrawLayerTileToScreen(u32 x, u32 y, u32 layer, u16 *ptr)
{
    u32 tileX = x * 2;
    u32 tileY = y * 2;

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

static struct SpriteTemplate CreatePaletteAndReturnTemplate(u32 TileTag, u32 PalTag, enum MiningId itemId)
{
    struct SpritePalette TempPalette;
    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempPalette.tag = PalTag;
    TempPalette.data = (u16 *)sMiningItemList[itemId].paldata;
    LoadSpritePalette(&TempPalette);

    TempSpriteTemplate.tileTag = TileTag;
    TempSpriteTemplate.paletteTag = PalTag;
    TempSpriteTemplate.oam = &sOamItem64x64;

    return TempSpriteTemplate;
}

static void DrawItemSprite(u32 x, u32 y, enum MiningId itemId, u32 itemNumPalTag, u32 itemStateId)
{
    struct SpriteTemplate gSpriteTemplate;
    u32 posX = x * 16;
    u32 posY = y * 16 + 32;

    switch(itemId)
    {
    case MININGID_STONE_1x4:
        LoadSpritePalette(sSpritePal_Stone1x4);
        LoadCompressedSpriteSheet(sSpriteSheet_Stone1x4);
        CreateSprite(&sSpriteStone1x4, posX + MINING_POS_OFFS_64X64, posY + MINING_POS_OFFS_64X64, 3);
        break;
    case MININGID_STONE_4x1:
        LoadSpritePalette(sSpritePal_Stone4x1);
        LoadCompressedSpriteSheet(sSpriteSheet_Stone4x1);
        CreateSprite(&sSpriteStone4x1, posX + MINING_POS_OFFS_64X64, posY + MINING_POS_OFFS_64X64, 3);
        break;
    case MININGID_STONE_2x4:
        LoadSpritePalette(sSpritePal_Stone2x4);
        LoadCompressedSpriteSheet(sSpriteSheet_Stone2x4);
        CreateSprite(&sSpriteStone2x4, posX + MINING_POS_OFFS_64X64, posY + MINING_POS_OFFS_64X64, 3);
        break;
    case MININGID_STONE_4x2:
        LoadSpritePalette(sSpritePal_Stone4x2);
        LoadCompressedSpriteSheet(sSpriteSheet_Stone4x2);
        CreateSprite(&sSpriteStone4x2, posX + MINING_POS_OFFS_64X64, posY + MINING_POS_OFFS_64X64, 3);
        break;
    case MININGID_STONE_2x2:
        LoadSpritePalette(sSpritePal_Stone2x2);
        LoadCompressedSpriteSheet(sSpriteSheet_Stone2x2);
        CreateSprite(&sSpriteStone2x2, posX + MINING_POS_OFFS_64X64, posY + MINING_POS_OFFS_64X64, 3);
        break;
    case MININGID_STONE_3x3:
        LoadSpritePalette(sSpritePal_Stone3x3);
        LoadCompressedSpriteSheet(sSpriteSheet_Stone3x3);
        CreateSprite(&sSpriteStone3x3, posX + MINING_POS_OFFS_64X64, posY + MINING_POS_OFFS_64X64, 3);
        break;
    case MININGID_STONE_SNAKE1:
        LoadSpritePalette(sSpritePal_StoneSnake1);
        LoadCompressedSpriteSheet(sSpriteSheet_StoneSnake1);
        CreateSprite(&sSpriteStoneSnake1, posX + MINING_POS_OFFS_64X64, posY + MINING_POS_OFFS_64X64, 3);
        break;
    case MININGID_STONE_SNAKE2:
        LoadSpritePalette(sSpritePal_StoneSnake2);
        LoadCompressedSpriteSheet(sSpriteSheet_StoneSnake2);
        CreateSprite(&sSpriteStoneSnake2, posX + MINING_POS_OFFS_64X64, posY + MINING_POS_OFFS_64X64, 3);
        break;
    case MININGID_STONE_MUSHROOM1:
        LoadSpritePalette(sSpritePal_StoneMushroom1);
        LoadCompressedSpriteSheet(sSpriteSheet_StoneMushroom1);
        CreateSprite(&sSpriteStoneMushroom1, posX + MINING_POS_OFFS_64X64, posY + MINING_POS_OFFS_64X64, 3);
        break;
    case MININGID_STONE_MUSHROOM2:
        LoadSpritePalette(sSpritePal_StoneMushroom2);
        LoadCompressedSpriteSheet(sSpriteSheet_StoneMushroom2);
        CreateSprite(&sSpriteStoneMushroom2, posX + MINING_POS_OFFS_64X64, posY + MINING_POS_OFFS_64X64, 3);
        break;
    default: // If Item and not Stone
        gSpriteTemplate = CreatePaletteAndReturnTemplate(sMiningItemList[itemId].tag, itemNumPalTag, itemId);
        LoadCompressedSpriteSheet(sMiningItemList[itemId].sheet);
        sMiningUiState->buriedItems[itemStateId].spriteId = CreateSprite(&gSpriteTemplate, posX + MINING_POS_OFFS_64X64, posY + MINING_POS_OFFS_64X64, 3);
        return;
    }
}

// Defines && Macros
static void SetItemState(u32 posX, u32 posY, u32 x, u32 y, u32 itemStateId)
{
    sMiningUiState->itemMap[posX + x + (posY + y) * 12] = itemStateId;
}

static void OverwriteItemMapData(u32 posX, u32 posY, u32 itemStateId, enum MiningId itemId)
{
    for (u32 x = 0; x < 4; x++)
    {
        for (u32 y = 0; y < 4; y++)
        {
            if (sSpriteTileTable[itemId][x + y * 4] == 1)
                SetItemState(posX, posY, x, y, itemStateId);
        }
    }
}

// Defines && Macros
#define BORDERCHECK_COND(itemId) posX + MiningUtil_GetLeftValue(itemId) > xBorder \
    || posY + MiningUtil_GetTopValue(itemId) > yBorder
#define IGNORE_COORDS 255

static bool32 CheckIfItemCanBePlaced(enum MiningId itemId, u32 posX, u32 posY, u32 xBorder, u32 yBorder)
{
    for (u32 i = 1; i <= 4; i++)
    {
        if (BORDERCHECK_COND(itemId))
            return FALSE; // If it cannot be placed, return false, that means that item placement should regenerate
    }

    return TRUE; // If it can be placed, return true
}

static void DoDrawRandomItem(u32 itemStateId, enum MiningId itemId)
{
    u32 x, y, xMax, yMax, xMin, yMin, paletteTag;
    u32 validX[24] = {0};
    u32 validY[24] = {0};
    u32 numValid = 0;

    switch(itemStateId)
    {
    default:
    case ITEM_STATE_ID_1:
        xMin = MINING_ZONE_1_X_LEFT_BOUNDARY;
        xMax = MINING_ZONE_1_X_RIGHT_BOUNDARY;
        yMin = MINING_ZONE_1_Y_UP_BOUNDARY;
        yMax = MINING_ZONE_1_Y_DOWN_BOUNDARY;
        paletteTag = TAG_PAL_ITEM1;
        break;
    case ITEM_STATE_ID_2:
        xMin = MINING_ZONE_2_X_LEFT_BOUNDARY;
        xMax = MINING_ZONE_2_X_RIGHT_BOUNDARY;
        yMin = MINING_ZONE_2_Y_UP_BOUNDARY;
        yMax = MINING_ZONE_2_Y_DOWN_BOUNDARY;
        paletteTag = TAG_PAL_ITEM2;
        break;
    case ITEM_STATE_ID_3:
        xMin = MINING_ZONE_3_X_LEFT_BOUNDARY;
        xMax = MINING_ZONE_3_X_RIGHT_BOUNDARY;
        yMin = MINING_ZONE_3_Y_UP_BOUNDARY;
        yMax = MINING_ZONE_3_Y_DOWN_BOUNDARY;
        paletteTag = TAG_PAL_ITEM3;
        break;
    case ITEM_STATE_ID_4:
        xMin = MINING_ZONE_4_X_LEFT_BOUNDARY;
        xMax = MINING_ZONE_4_X_RIGHT_BOUNDARY;
        yMin = MINING_ZONE_4_Y_UP_BOUNDARY;
        yMax = MINING_ZONE_4_Y_DOWN_BOUNDARY;
        paletteTag = TAG_PAL_ITEM4;
        break;
    }

    for (y = yMin; y <= yMax; y++)
    {
        for (x = xMin; x <= xMax; x++)
        {
            if (CheckIfItemCanBePlaced(itemId, x, y, xMax, yMax))
            {
                validX[numValid] = x;
                validY[numValid] = y;
                numValid++;
            }

            if (numValid == 0)
                return; // safety, shouldnt happen anyway

            u32 pick = Random() % numValid;

            DrawItemSprite(validX[pick], validY[pick], itemId, paletteTag, itemStateId - 1);
            OverwriteItemMapData(validX[pick], validY[pick], itemStateId, itemId); // For the collection logic, overwrite the item map data
            return;
        }
    }
}

static bool32 CanStoneBePlacedAtXY(u32 x, u32 y, enum MiningId itemId) // PSF magic
{
    u32 height = MiningUtil_GetTopValue(itemId) + 1;
    u32 width =  MiningUtil_GetLeftValue(itemId) + 1;

    if ((x + width) > MINING_WALL_WIDTH)
        return FALSE;

    if ((y + height) > MINING_WALL_HEIGHT)
        return FALSE;

    for (u32 dx = 0; dx < width; dx++)
    {
        for (u32 dy = 0; dy < height; dy++)
        {
            if (sMiningUiState->itemMap[x + dx + (y + dy) * MINING_WALL_WIDTH] != 0)
                return FALSE;
        }
    }

    return TRUE;
}


#if MINING_DEBUG_ENABLE == FALSE || MINING_DEBUG_ENABLE_STONE_GENERATION_OPTIONS == FALSE
static bool32 DoesStoneFitInItemMap(enum MiningId itemId)
{
    if (itemId == MININGID_NONE)
        return FALSE;

    for (u32 coordX = 0; coordX < MINING_WALL_WIDTH; coordX++)
    {
        for (u32 coordY = 0; coordY < MINING_WALL_HEIGHT; coordY++)
        {
            if (CanStoneBePlacedAtXY(coordX, coordY, itemId))
                return TRUE;
        }
    }

    return FALSE;
}
#endif

static void DoDrawRandomStone(enum MiningId itemId)
{
    u32 x = Random() % MINING_WALL_WIDTH;
    u32 y = Random() % MINING_WALL_HEIGHT;

    while(!CanStoneBePlacedAtXY(x, y, itemId))
    {
        x = Random() % MINING_WALL_WIDTH;
        y = Random() % MINING_WALL_HEIGHT;
    }

    DrawItemSprite(x, y, itemId, TAG_DUMMY, ITEM_STATE_ID_NONE); // We use ITEM_STATE_ID_NONE becasue here, a stone is guaranteed
    OverwriteItemMapData(x, y, ITEM_STATE_ID_6, itemId);
}

static void HandleItemState(u32 itemId)
{
    u32 full = MiningUtil_GetTotalTileAmount(GetBuriedMiningItemId(itemId));
    u32 stop = full + 1;

    if (sMiningUiState->buriedItems[itemId].buriedState < full && sMiningUiState->buriedItems[itemId].isSelected)
    {
        for (u32 i = 0; i < MINING_WALL_SIZE; i++)
        {
            if (sMiningUiState->itemMap[i] == itemId + 1 && sMiningUiState->layerMap[i] == 6)
            {
                sMiningUiState->itemMap[i] = MINING_ITEM_TILE_DUG_UP;
                sMiningUiState->buriedItems[itemId].buriedState++;
            }
        }
    }
    else if (sMiningUiState->buriedItems[itemId].buriedState == full)
    {
        BeginNormalPaletteFade(1 << (16 + gSprites[sMiningUiState->buriedItems[itemId].spriteId].oam.paletteNum), 2, 16, 0, RGB_WHITE);
        sMiningUiState->buriedItems[itemId].buriedState = stop;
        SetBuriedItemStatus(itemId, TRUE);
        PlaySE(SE_RG_CARD_OPEN);
    }
}

static void Mining_CheckItemFound(void)
{
    HandleItemState(0);
    HandleItemState(1);
    HandleItemState(2);
    HandleItemState(3);

    for (u32 i = 0; i < MINING_WALL_SIZE; i++)
    {
        if (sMiningUiState->itemMap[i] == 6 && sMiningUiState->layerMap[i] == 6)
            sMiningUiState->itemMap[i] = MINING_ITEM_TILE_DUG_UP;
    }
}

static s32 RandRangeSigned(s32 min, s32 max)
{
    if (min == max)
        return min;

    return (Random() % (max - min)) + min;
}

static bool32 AtCornerOfRectangle(u32 row, u32 col, u32 baseRow, u32 baseCol, u32 finalRow, u32 finalCol)
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
    u32 row1, row2, col1, col2, x, y;
    u32 i, j, totalTimes;
    s32 baseRow; // Rocks can go up to one row over on either top or bottom
    s32 baseCol; // Rocks can go up to one col over on either left or right
    s32 finalRow;
    s32 finalCol, k, m;
    u16 *ptr = GetBgTilemapBuffer(2);

    // Start by placing blank layer 3 rocks
    for (i = 0; i < MINING_WALL_SIZE; ++i)
        sMiningUiState->layerMap[i] = 2;

    // Create patches of lighter dirt areas
    totalTimes = 3 + Random() % 5;
    for (i = 0; i < totalTimes; ++i)
    {
        do
        {
            row1 = Random() % (MINING_WALL_HEIGHT + 1);
            row2 = Random() % (MINING_WALL_HEIGHT + 1);
        } while (row1 >= row2);

        do
        {
            col1 = Random() % (MINING_WALL_WIDTH + 1);
            col2 = Random() % (MINING_WALL_WIDTH + 1);
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
    totalTimes = Random() % 5 + 2;
    for (i = 0; i < totalTimes; ++i)
    {
        baseRow = RandRangeSigned(-4,  MINING_WALL_HEIGHT);  // Rocks can go up to one row over on either top or bottom
        baseCol = RandRangeSigned(-4, MINING_WALL_WIDTH); // Rocks can go up to one col over on either left or right
        finalRow = baseRow + 5;
        finalCol = baseCol + 5;

        for (k = baseRow; k < finalRow; ++k)
        {
            if (k < 0 || k >= MINING_WALL_HEIGHT)
                continue; // Not legal row

            for (m = baseCol; m < finalCol; ++m)
            {
                if (m < 0 || m >= MINING_WALL_WIDTH)
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
    for (y = 2; y < MINING_WALL_HEIGHT + 2; y++)
    {
        for (x = 0; x < MINING_WALL_WIDTH && i < MINING_WALL_SIZE; x++, i++)
            Terrain_DrawLayerTileToScreen(x, y, sMiningUiState->layerMap[i], ptr);
    }
}

static void Terrain_UpdateLayerTileOnScreen(u16 *ptr, s32 ofsX, s32 ofsY)
{
    u32 i = (sMiningUiState->cursorY - 2 + ofsY) * 12 + sMiningUiState->cursorX + ofsX; // It needs the `-2` because the cursorY value started at `2`
    u32 tileX = (sMiningUiState->cursorX + ofsX) * 2;
    u32 tileY = (sMiningUiState->cursorY + ofsY) * 2;
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

static bool32 Terrain_Pickaxe_OverwriteTiles(u16 *ptr)
{
    u32 pos = sMiningUiState->cursorX + (sMiningUiState->cursorY - 2) * 12;

    if (sMiningUiState->itemMap[pos] != MINING_ITEM_TILE_DUG_UP)
    {
        if (sMiningUiState->cursorX != MINING_WALL_BORDER_X_LEFT)
            Terrain_UpdateLayerTileOnScreen(ptr, -1, 0);

        if (sMiningUiState->cursorX != MINING_WALL_BORDER_X_RIGHT)
            Terrain_UpdateLayerTileOnScreen(ptr, 1, 0);

        // We have to add '2' to '7' and '0', because the cursor spawns at Y position 2
        if (sMiningUiState->cursorY != MINING_WALL_BORDER_Y_DOWN)
            Terrain_UpdateLayerTileOnScreen(ptr, 0, 1);

        if (sMiningUiState->cursorY != MINING_WALL_BORDER_Y_UP)
            Terrain_UpdateLayerTileOnScreen(ptr, 0, -1);

        // Center hit
        Terrain_UpdateLayerTileOnScreen(ptr, 0, 0);
        if (sMiningUiState->tool == BLUE_BUTTON)
        {
            Terrain_UpdateLayerTileOnScreen(ptr, 0, 0);
        }
        return FALSE;
    }

    return TRUE;
}

static void Terrain_Hammer_OverwriteTiles(u16 *ptr)
{
    bool32 isItemDugUp = Terrain_Pickaxe_OverwriteTiles(ptr);
    u32 pos = sMiningUiState->cursorX + (sMiningUiState->cursorY - 2) * 12;

    if (!isItemDugUp)
    {
        // Corners
        // We have to add '2' to '7' and '0', because the cursor spawns at Y position 2
        if (sMiningUiState->cursorX != MINING_WALL_BORDER_X_RIGHT && sMiningUiState->cursorY != MINING_WALL_BORDER_Y_DOWN)
            Terrain_UpdateLayerTileOnScreen(ptr, 1, 1);

        if (sMiningUiState->cursorX != MINING_WALL_BORDER_X_LEFT && sMiningUiState->cursorY != MINING_WALL_BORDER_Y_DOWN)
            Terrain_UpdateLayerTileOnScreen(ptr, -1, 1);

        if (sMiningUiState->cursorX != MINING_WALL_BORDER_X_RIGHT && sMiningUiState->cursorY != MINING_WALL_BORDER_Y_UP)
            Terrain_UpdateLayerTileOnScreen(ptr, 1, -1);

        if (sMiningUiState->cursorX != MINING_WALL_BORDER_X_LEFT && sMiningUiState->cursorY != MINING_WALL_BORDER_Y_UP)
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
#if MINING_FLAG_USE_DEFAULT_MESSAGE_BOX == FALSE
        LoadBgTiles(GetWindowAttribute(WIN_MSG, WINDOW_BG), sMiningMessageBoxGfx, 0x1C0, 20);
        LoadPalette(sMiningMessageBoxPal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        LoadPalette(sMiningMessageBoxPal, BG_PLTT_ID(14), PLTT_SIZE_4BPP);
#elif MINING_FLAG_USE_DEFAULT_MESSAGE_BOX == TRUE
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

    u8 txtColor[] = {TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};

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

#if MINING_DEBUG_ENABLE == FALSE || MINING_DEBUG_INFINITE_HITS == FALSE
static void EndMining(u8 taskId)
{
    sMiningUiState->loadGameState = STATE_GAME_FINISH;
    gTasks[taskId].func = Task_MiningPrintResult;
}
#endif

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
        while(TRUE)
        {
            if (!RunTextPrintersAndIsPrinter0Active())
                break;
        }
    }
}

static void Task_MiningPrintResult(u8 taskId)
{
    u32 itemIndex = ConvertLoadGameStateToItemIndex();
    enum Item itemId = GetBuriedBagItemId(itemIndex);

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
        CheckItemAndPrint(taskId, itemIndex, itemId);
        break;
    case STATE_ITEM_BAG_1:
    case STATE_ITEM_BAG_2:
    case STATE_ITEM_BAG_3:
    case STATE_ITEM_BAG_4:
        GetItemOrPrintError(taskId, itemIndex, itemId);
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

static void GetItemOrPrintError(u8 taskId, u32 itemIndex, enum Item itemId)
{
    sMiningUiState->loadGameState++;

    if (itemId == ITEM_NONE)
        return;

    if (AddBagItem(itemId, 1))
        return;

    PrintMessage(COMPOUND_STRING("Too bad!\nYour Bag is full!"));
    gTasks[taskId].func = Task_WaitButtonPressOpening;
}

static void CheckItemAndPrint(u8 taskId, u32 itemIndex, enum Item itemId)
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
    gSprites[sMiningUiState->cursorSpriteIndex].invisible = TRUE;
}

#if MINING_DEBUG_ENABLE == FALSE || MINING_DEBUG_INFINITE_HITS == FALSE
static void Task_WallCollapseDelay(u8 taskId)
{
    u16 *tilemapBuf = GetBgTilemapBuffer(1);

    if (sMiningUiState->delayCounter >= 40)
    {
        DestroyTask(taskId);
        sMiningUiState->isCollapseAnimActive = FALSE;
        PrintMessage(COMPOUND_STRING("The wall collapsed!"));
    }
    else
    {
        if (sMiningUiState->delayCounter % 2 == 0)
        {
            for (u32 j = 0; j < 30; j++)
            {
                OverwriteTileDataInTilemapBuffer(1, j, sMiningUiState->delayCounter / 2, tilemapBuf, 2);
                ScheduleBgCopyTilemapToVram(1);
                DoScheduledBgTilemapCopiesToVram();
            }
        }
        sMiningUiState->delayCounter++;
    }
}
#endif


#if MINING_DEBUG_ENABLE == FALSE || MINING_DEBUG_INFINITE_HITS == FALSE
static void WallCollapseAnimation()
{
    sMiningUiState->delayCounter = 0;
    sMiningUiState->isCollapseAnimActive = TRUE;
    ShowBg(1);
    CreateTask(Task_WallCollapseDelay, 0);
}
#endif

static void HandleGameFinish(u8 taskId)
{
    MakeCursorInvisible();

    if (IsStressLevelMax())
        // Here, we only set the Shake Duration. The Task, which handles the shake effect, is created by the input handler.
        sMiningUiState->shakeDuration = 6;
    else
        PrintMessage(COMPOUND_STRING("Everything was dug up!"));

    sMiningUiState->loadGameState++;
    gTasks[taskId].func = Task_WaitButtonPressOpening;
}

static void PrintItemSuccess(enum Item itemId)
{
    CopyItemName(itemId,gStringVar1);
    StringExpandPlaceholders(gStringVar2, COMPOUND_STRING("{STR_VAR_1}\nwas obtained!"));
    PrintMessage(gStringVar2);
}

static u32 GetTotalNumberOfBuriedItems(void)
{
    u32 count = 0;

    for (u32 itemIndex = 0; itemIndex < MINING_MAX_NUM_BURIED_ITEMS; itemIndex++)
        if (GetBuriedBagItemId(itemIndex) != ITEM_NONE)
            count++;

    return count;
}


#if MINING_DEBUG_ENABLE == FALSE || MINING_DEBUG_INFINITE_HITS == FALSE
static u32 GetNumberOfFoundItems(void)
{
    u32 count = 0;

    for (u32 itemIndex = 0; itemIndex < MINING_MAX_NUM_BURIED_ITEMS; itemIndex++)
        if (GetBuriedItemStatus(itemIndex))
            count++;

    return count;
}
#endif


#if MINING_DEBUG_ENABLE == FALSE || MINING_DEBUG_INFINITE_HITS == FALSE
static bool32 AreAllItemsFound(void)
{
    return (GetTotalNumberOfBuriedItems() == GetNumberOfFoundItems());
}
#endif

static void InitBuriedItems(void)
{
    for (u32 index = 0; index < MINING_MAX_NUM_BURIED_ITEMS; index++)
    {
        SetBuriedItemsId(index, MININGID_NONE);
        SetBuriedItemStatus(index, FALSE);
    }
}

static void SetBuriedItemsId(u32 index, enum MiningId itemId)
{
    sMiningUiState->buriedItems[index].bagItemId = sMiningItemList[itemId].bagItemId;
    sMiningUiState->buriedItems[index].miningItemId = itemId;
}

static void SetBuriedItemStatus(u32 index, bool32 status)
{
    sMiningUiState->buriedItems[index].isDugUp = status;
}

static enum Item GetBuriedBagItemId(u32 index)
{
    return sMiningUiState->buriedItems[index].bagItemId;
}

static enum MiningId GetBuriedMiningItemId(u32 index)
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
