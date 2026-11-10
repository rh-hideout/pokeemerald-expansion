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

#include "config/mining_minigame.h"

#include "data/mining_minigame/enums.h"

#define MINING_POS_OFFS_32X32           16
#define MINING_POS_OFFS_64X64           32

#define MINING_WALL_WIDTH               12
#define MINING_WALL_HEIGHT              8
#define MINING_WALL_SIZE                (MINING_WALL_WIDTH * MINING_WALL_HEIGHT)

#define STRESS_LEVEL_OFFSET             2

#define MINING_WALL_BORDER_X_LEFT       0
#define MINING_WALL_BORDER_X_RIGHT      (MINING_WALL_BORDER_X_LEFT + MINING_WALL_WIDTH - 1)

#define MINING_WALL_BORDER_Y_UP         STRESS_LEVEL_OFFSET
#define MINING_WALL_BORDER_Y_DOWN       (MINING_WALL_BORDER_Y_UP + MINING_WALL_HEIGHT - 1)

#define MINING_ZONE_1_X_LEFT_BOUNDARY   0
#define MINING_ZONE_1_X_RIGHT_BOUNDARY  5
#define MINING_ZONE_1_Y_UP_BOUNDARY     0
#define MINING_ZONE_1_Y_DOWN_BOUNDARY   3

#define MINING_ZONE_2_X_LEFT_BOUNDARY   0
#define MINING_ZONE_2_X_RIGHT_BOUNDARY  5
#define MINING_ZONE_2_Y_UP_BOUNDARY     4
#define MINING_ZONE_2_Y_DOWN_BOUNDARY   (MINING_WALL_HEIGHT - 1)

#define MINING_ZONE_3_X_LEFT_BOUNDARY   6
#define MINING_ZONE_3_X_RIGHT_BOUNDARY  (MINING_WALL_WIDTH - 1)
#define MINING_ZONE_3_Y_UP_BOUNDARY     0
#define MINING_ZONE_3_Y_DOWN_BOUNDARY   3

#define MINING_ZONE_4_X_LEFT_BOUNDARY   6
#define MINING_ZONE_4_X_RIGHT_BOUNDARY  (MINING_WALL_WIDTH - 1)
#define MINING_ZONE_4_Y_UP_BOUNDARY     4
#define MINING_ZONE_4_Y_DOWN_BOUNDARY   (MINING_WALL_HEIGHT - 1)

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
static void DoDrawRandomItem(u32 itemStateId, enum MiningId miningId);
static void DoDrawRandomStone(enum MiningId miningId);
static bool32 DoesStoneFitInItemMap(enum MiningId miningId);
static bool32 CanStoneBePlacedAtXY(u32 x, u32 y, enum MiningId miningId);
static void Mining_CheckItemFound(void);
static void PrintMessage(const u8 *string);
static void InitMiningWindows(void);
static bool32 IsStressLevelMax(void);
static void EndMining(u8 taskId);
static bool32 AreAllItemsFound(void);
static u32 GetNumberOfFoundItems(void);
static void WallCollapseAnimation();
static u32 ConvertLoadGameStateToItemIndex(void);
static void GetItemOrPrintError(u8 taskId, u32 itemIndex, enum Item miningId);
static void CheckItemAndPrint(u8 taskId, u32 itemIndex, enum Item miningId);
static void MakeCursorInvisible(void);
static void HandleGameFinish(u8 taskId);
static void PrintItemSuccess(enum Item itemId);
static u32 GetTotalNumberOfBuriedItems(void);
static void InitBuriedItems(void);
static void SetBuriedItemsId(u32 index, enum MiningId miningId);
static void SetBuriedItemStatus(u32 index, bool32 status);
static enum Item GetBuriedBagItemId(u32 index);
static bool32 GetBuriedItemStatus(u32 index);
static void ExitMiningUI(u8 taskId);

struct MiningObject
{
    enum Item itemId:16;
    u16 tag;
    const struct CompressedSpriteSheet *sheet;
    const struct SpritePalette *palette;
    const struct SpriteTemplate *template;
};

struct BuriedItem
{
    enum Item itemId;
    enum MiningId miningId;
    bool32 isDugUp;
    bool32 isSelected;
    u32 buriedItemTileCount;
    u32 spriteId;
};

struct MiningState
{
    MainCallback leavingCallback;   // Callback to leave the Ui
    u32 loadGameState;
    u32 layerMap[MINING_WALL_SIZE];             // Array representing the screen. Determines virtual layers
    u32 itemMap[MINING_WALL_SIZE];    // Determines where items are on the screen
    u32 cursorX;
    u32 cursorY;

    u8 *sBg1TilemapBuffer;
    u8 *sBg2TilemapBuffer;
    u8 *sBg3TilemapBuffer;

    // Items and Stones
    struct BuriedItem buriedItems[MINING_MAX_NUM_BURIED_ITEMS];
    struct BuriedItem buriedStones[MINING_NUM_BURIED_STONES];

    // Tools
    bool32 tool;    // Hammer or Pickaxe
    u32 cursorSpriteIndex;
    u32 bRedSpriteIndex;
    u32 bBlueSpriteIndex;

    // Shake
    bool32 shouldShake;     // If set to true, shake gets executed every VBlank
    u32 shakeStepCounter;   // Shake steps
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
enum SpriteAndPaletteTag
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

enum ItemRarity
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

enum UiLoadState
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

enum MinigameState
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

enum StressLevelPos
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

enum ItemState
{
    ITEM_STATE_ID_NONE,     // Placeholder ID
    ITEM_STATE_ID_1,        // ID for item 1 in zone 1
    ITEM_STATE_ID_2,        // ID for item 2 in zone 2
    ITEM_STATE_ID_3,        // ID for item 3 in zone 3
    ITEM_STATE_ID_4,        // ID for item 4 in zone 4
    ITEM_STATE_TILE_DUG_UP,
    ITEM_STATE_ID_STONE,    // Stones dont need seperate IDs in the itemMap array. We just need to know that there is a stone, so we use this ID for both stones.
};

enum TerrainLayer
{
    TERRAIN_LAYER_0,
    TERRAIN_LAYER_1,
    TERRAIN_LAYER_2,
    TERRAIN_LAYER_3,
    TERRAIN_LAYER_4,
    TERRAIN_LAYER_5,
    TERRAIN_LAYER_CLEARED,
};

enum BgLayers
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

#include "data/mining_minigame/objects.h"
#include "data/mining_minigame/tile_data.h"

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

static u32 MiningUtil_GetTotalTileAmount(enum MiningId miningId)
{
    u32 result = 0;

    for (u32 i = 0; i < 16; i++)
    {
        if (sSpriteTileTable[miningId][i] == TRUE)
            result++;
    }
    if (result == 0)
        return result + 1;

    return result;
}

static u32 MiningUtil_GetLeftValue(enum MiningId miningId)
{
    u32 left = 0;

    for (u32 x = 0; x < 4; x++)
    {
        for (u32 y = 0; y < 4; y++)
        {
            if (sSpriteTileTable[miningId][x + y * 4] == TRUE)
            {
                left++;
                break;
            }
        }
    }

    return left - 1;
}

static u32 MiningUtil_GetTopValue(enum MiningId miningId)
{
    u32 top = 0;

    for (u32 y = 0; y < 4; y++)
    {
        for (u32 x = 0; x < 4; x++)
        {
            if (sSpriteTileTable[miningId][x + y * 4] == TRUE)
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
    sMiningUiState->shakeStepCounter = 0;
    sMiningUiState->shouldShake = FALSE;
    sMiningUiState->isCollapseAnimActive = FALSE;
    sMiningUiState->shakeDuration = 0;
    sMiningUiState->loadGameState = STATE_GRAPHICS_VRAM;
    sMiningUiState->stressLevelCount = 0;
    sMiningUiState->stressLevelPos = 0;

    // Default the values for each item
    sMiningUiState->buriedItems[0].buriedItemTileCount = 0;
    sMiningUiState->buriedItems[1].buriedItemTileCount = 0;
    sMiningUiState->buriedItems[2].buriedItemTileCount = 0;
    sMiningUiState->buriedItems[3].buriedItemTileCount = 0;

    // Always two stones
    sMiningUiState->buriedStones[0].isSelected = TRUE;
    sMiningUiState->buriedStones[1].isSelected = TRUE;

    u32 amountItemsToSelect;
    // Generate Items
    if (MINING_DEBUG_ENABLE && MINING_DEBUG_ENABLE_ITEM_GENERATION_OPTIONS)
    {
        if (MINING_DEBUG_DESIRED_NUMBER_OF_ITEMS == 0)
            amountItemsToSelect = 2;
        else if (MINING_DEBUG_DESIRED_NUMBER_OF_ITEMS > 4)
            amountItemsToSelect = 4;
        else
            amountItemsToSelect = MINING_DEBUG_DESIRED_NUMBER_OF_ITEMS;

        for (u32 i = 0; i < amountItemsToSelect; i++)
            sMiningUiState->buriedItems[i].isSelected = TRUE;
    }
    else {
        amountItemsToSelect = RandomUniform(RNG_NONE, MINING_MIN_NUM_BURIED_ITEMS, MINING_MAX_NUM_BURIED_ITEMS);
        u32 zones[4] = {0, 1, 2, 3};
        Shuffle(zones, 4, sizeof(u32));

        // Select the zones from the shuffled array
        for (u32 i = 0; i < amountItemsToSelect; i++)
            sMiningUiState->buriedItems[zones[i]].isSelected = TRUE;
    }

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
    switch (sMiningUiState->shakeStepCounter)
    {
    case 0: // Left 1 - Down 1
        MakeCursorInvisible();
        if (!IsStressLevelMax() && RandomPercentage(RNG_NONE, 20))
            sMiningUiState->toggleShakeDuringAnimation = TRUE;
        MoveItemSprites(-1, 1);
        sMiningUiState->shakeStepCounter++;
        break;
    case 1:
        if (!sMiningUiState->toggleShakeDuringAnimation)
        {
            SetGpuReg(REG_OFFSET_BG3HOFS, 1);
            SetGpuReg(REG_OFFSET_BG2HOFS, 1);
            SetGpuReg(REG_OFFSET_BG3VOFS, -1);
            SetGpuReg(REG_OFFSET_BG2VOFS, -1);
        }
        sMiningUiState->shakeStepCounter++;
        break;
    case 3: // Right 2 - Up 2
        MoveItemSprites(3, -3);
        gSprites[sMiningUiState->ShakeHitEffect].invisible = TRUE;
        gSprites[sMiningUiState->ShakeHitTool].invisible = TRUE;
        sMiningUiState->shakeStepCounter++;
        break;
    case 4:
        if (!sMiningUiState->toggleShakeDuringAnimation)
        {
            SetGpuReg(REG_OFFSET_BG3HOFS, -2);
            SetGpuReg(REG_OFFSET_BG2HOFS, -2);
            SetGpuReg(REG_OFFSET_BG3VOFS, 2);
            SetGpuReg(REG_OFFSET_BG2VOFS, 2);
        }
        sMiningUiState->shakeStepCounter++;
        break;
    case 6: // Down 2
        MoveItemSprites(-2, 4);
        if (!IsStressLevelMax())
        {
            gSprites[sMiningUiState->ShakeHitEffect].invisible = FALSE;
            gSprites[sMiningUiState->ShakeHitTool].invisible = FALSE;
        }
        sMiningUiState->shakeStepCounter++;
        break;
    case 7:
        if (!sMiningUiState->toggleShakeDuringAnimation)
        {
            SetGpuReg(REG_OFFSET_BG3VOFS, -2);
            SetGpuReg(REG_OFFSET_BG2VOFS, -2);
            SetGpuReg(REG_OFFSET_BG3HOFS, 0);
            SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        }
        sMiningUiState->shakeStepCounter++;
        break;
    case 9: // Left 2 - Up 2
        MoveItemSprites(-2, -4);
        gSprites[sMiningUiState->ShakeHitEffect].invisible = TRUE;
        sMiningUiState->shakeStepCounter++;
        break;
    case 10:
        if (!sMiningUiState->toggleShakeDuringAnimation)
        {
            SetGpuReg(REG_OFFSET_BG2HOFS, 2);
            SetGpuReg(REG_OFFSET_BG3HOFS, 2);
            SetGpuReg(REG_OFFSET_BG3VOFS, 2);
            SetGpuReg(REG_OFFSET_BG2VOFS, 2);
        }
        sMiningUiState->shakeStepCounter++;
        break;
    case 12: // Right 1 - Down 1
        MoveItemSprites(3, 3);
        if (!IsStressLevelMax())
            gSprites[sMiningUiState->ShakeHitEffect].invisible = FALSE;
        gSprites[sMiningUiState->ShakeHitTool].x += 7;
        StartSpriteAnim(&gSprites[sMiningUiState->ShakeHitTool], 1);
        sMiningUiState->shakeStepCounter++;
        break;
    case 13:
        if (!sMiningUiState->toggleShakeDuringAnimation)
        {
            SetGpuReg(REG_OFFSET_BG3HOFS, -1);
            SetGpuReg(REG_OFFSET_BG2HOFS, -1);
            SetGpuReg(REG_OFFSET_BG3VOFS, -1);
            SetGpuReg(REG_OFFSET_BG2VOFS, -1);
        }
        sMiningUiState->shakeStepCounter++;
        break;
    case 15:
        MoveItemSprites(-1, -1);
        sMiningUiState->shakeStepCounter++;
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
            sMiningUiState->shakeStepCounter = 0;
            sMiningUiState->toggleShakeDuringAnimation = FALSE;
            break;
        }

        if (MINING_DEBUG_ENABLE && MINING_DEBUG_INFINITE_HITS)
        {
            gSprites[sMiningUiState->cursorSpriteIndex].invisible = FALSE;
        }
        else
        {
            if (IsStressLevelMax())
                WallCollapseAnimation();
            else
                gSprites[sMiningUiState->cursorSpriteIndex].invisible = FALSE;
        }

        sMiningUiState->shakeStepCounter = 0;
        sMiningUiState->shouldShake = FALSE;
        sMiningUiState->toggleShakeDuringAnimation = FALSE;
        DestroyTask(taskId);
        break;
    default:
        sMiningUiState->shakeStepCounter++;
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
    case STATE_GRAPHICS_VRAM:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sCollapseScreenTiles, 0, 0, 0);
        DecompressAndCopyTileDataToVram(2, sStressLevelAndTerrainTiles, 0, 0, 0);
        DecompressAndCopyTileDataToVram(3, sUiTiles, 0, 0, 0);
        sMiningUiState->loadGameState++;
        break;
    case STATE_GRAPHICS_DECOMPRESS:
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
    case STATE_GRAPHICS_PALETTES:
        LoadPalette(sCollapseScreenPalette, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
        LoadPalette(sStressLevelAndTerrainPalette, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        LoadPalette(sUiPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        sMiningUiState->loadGameState++;
        break;
    case STATE_GRAPHICS_TERRAIN:
        Mining_DrawRandomTerrain();
        sMiningUiState->loadGameState++;
        break;
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

static enum MiningId GetRandomMiningItem(void)
{
    u32 index;
    u32 rnd = Random() % 7;
    enum ItemRarity rarity;
    enum MiningId itemId = MININGID_NONE;

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

static void InitItemsIfSelected(u32 buriedItemIndex)
{
    enum MiningId miningId = MININGID_NONE;
    if (sMiningUiState->buriedItems[buriedItemIndex].isSelected)
    {
        if (MINING_DEBUG_ENABLE && MINING_DEBUG_ENABLE_ITEM_GENERATION_OPTIONS)
        {
            switch (buriedItemIndex)
            {
            case 0:
                miningId = MINING_DEBUG_MININGID_ITEM1;
                break;
            case 1:
                miningId = MINING_DEBUG_MININGID_ITEM2;
                break;
            case 2:
                miningId = MINING_DEBUG_MININGID_ITEM3;
                break;
            case 3:
                miningId = MINING_DEBUG_MININGID_ITEM4;
                break;
            }
        }
        else
        {
            miningId = GetRandomMiningItem();
        }
        SetBuriedItemsId(buriedItemIndex, miningId);
        DoDrawRandomItem(buriedItemIndex + 1, miningId);
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
    if (MINING_DEBUG_ENABLE && MINING_DEBUG_ENABLE_STONE_GENERATION_OPTIONS)
    {
        DoDrawRandomStone(MINING_DEBUG_MININGID_STONE1);
        DoDrawRandomStone(MINING_DEBUG_MININGID_STONE2);
    }
    else
    {
        enum MiningId stone;
        for (u32 i = 0; i < MINING_NUM_BURIED_STONES; i++)
        {
            stone = MININGID_NONE;
            while (!DoesStoneFitInItemMap(stone))
                stone = ((Random() % MINING_COUNT_ID_STONE) + MININGID_STONE_1x4);

            DoDrawRandomStone(stone);
        }
    }

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

            if (sMiningUiState->layerMap[cursorPos] == TERRAIN_LAYER_CLEARED && sMiningUiState->itemMap[cursorPos] > 4)
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
            if (sMiningUiState->layerMap[cursorPos] == TERRAIN_LAYER_CLEARED && sMiningUiState->itemMap[cursorPos] > 4)
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

    if (AreAllItemsFound())
        EndMining(taskId);

    if (IsStressLevelMax())
    {
        EndMining(taskId);
        PlaySE(SE_M_EARTHQUAKE);
    }
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

    switch (layer)
    {
    // layer 0 and 1 - tile: 0
    case TERRAIN_LAYER_0:
        OverwriteTileDataInTilemapBuffer(0x20, tileX, tileY, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x21, tileX + 1, tileY, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x24, tileX, tileY + 1, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x25, tileX + 1, tileY + 1, ptr, 0x01);
        break;
    case TERRAIN_LAYER_1:
        OverwriteTileDataInTilemapBuffer(0x19, tileX, tileY, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x1A, tileX + 1, tileY, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x1E, tileX, tileY + 1, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x1F, tileX + 1, tileY + 1, ptr, 0x01);
        break;
    case TERRAIN_LAYER_2:
        OverwriteTileDataInTilemapBuffer(0x10, tileX, tileY, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x11, tileX + 1, tileY, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x15, tileX, tileY + 1, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x16, tileX + 1, tileY + 1, ptr, 0x01);
        break;
    case TERRAIN_LAYER_3:
        OverwriteTileDataInTilemapBuffer(0x0C, tileX, tileY, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x0D, tileX + 1, tileY, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x12, tileX, tileY + 1, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x13, tileX + 1, tileY + 1, ptr, 0x01);
        break;
    case TERRAIN_LAYER_4:
        OverwriteTileDataInTilemapBuffer(0x05, tileX, tileY, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x06, tileX + 1, tileY, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x0A, tileX, tileY + 1, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x0B, tileX + 1, tileY + 1, ptr, 0x01);
        break;
    case TERRAIN_LAYER_5:
        OverwriteTileDataInTilemapBuffer(0x01, tileX, tileY, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x02, tileX + 1, tileY, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x03, tileX, tileY + 1, ptr, 0x01);
        OverwriteTileDataInTilemapBuffer(0x04, tileX + 1, tileY + 1, ptr, 0x01);
        break;
    }
}

static void DrawItemSprite(u32 x, u32 y, enum MiningId miningId, u32 itemNumPalTag, u32 itemStateId)
{
    struct SpriteTemplate gSpriteTemplate;
    u32 posX = 16 * x;
    u32 posY = 16 * (y + STRESS_LEVEL_OFFSET);

    LoadSpritePalette(sMiningObjectList[miningId].palette);
    LoadCompressedSpriteSheet(sMiningObjectList[miningId].sheet);
    u32 spriteId = CreateSprite(sMiningObjectList[miningId].template, posX + MINING_POS_OFFS_64X64, posY + MINING_POS_OFFS_64X64, 3);
    if (miningId > MINING_COUNT_ID_STONE)
        sMiningUiState->buriedItems[itemStateId].spriteId = spriteId;
}

// Defines && Macros
static void SetItemState(u32 posX, u32 posY, u32 x, u32 y, u32 itemStateId)
{
    sMiningUiState->itemMap[posX + x + (posY + y) * 12] = itemStateId;
}

static void OverwriteItemMapData(u32 posX, u32 posY, u32 itemStateId, enum MiningId miningId)
{
    for (u32 x = 0; x < 4; x++)
    {
        for (u32 y = 0; y < 4; y++)
        {
            if (sSpriteTileTable[miningId][x + y * 4] == 1)
                SetItemState(posX, posY, x, y, itemStateId);
        }
    }
}

// Defines && Macros
#define BORDERCHECK_COND(miningId) posX + MiningUtil_GetLeftValue(miningId) > xBorder \
                              || posY + MiningUtil_GetTopValue(miningId) > yBorder
#define IGNORE_COORDS 255

static bool32 CheckIfItemCanBePlaced(enum MiningId miningId, u32 posX, u32 posY, u32 xBorder, u32 yBorder)
{
    for (u32 i = 1; i <= 4; i++)
    {
        if (BORDERCHECK_COND(miningId))
            return FALSE; // If it cannot be placed, return false, that means that item placement should regenerate
    }

    return TRUE; // If it can be placed, return true
}

static void DoDrawRandomItem(u32 itemStateId, enum MiningId miningId)
{
    u32 x, y, xMax, yMax, xMin, yMin;
    enum SpriteAndPaletteTag paletteTag;
    u32 validX[24] = {0};
    u32 validY[24] = {0};
    u32 numValid = 0;

    switch (itemStateId)
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
            if (CheckIfItemCanBePlaced(miningId, x, y, xMax, yMax))
            {
                validX[numValid] = x;
                validY[numValid] = y;
                numValid++;
            }

            if (numValid == 0)
                return; // safety, shouldnt happen anyway

            u32 pick = RandomUniform(RNG_NONE, 0, numValid - 1);

            DrawItemSprite(validX[pick], validY[pick], miningId, paletteTag, itemStateId - 1);
            OverwriteItemMapData(validX[pick], validY[pick], itemStateId, miningId); // For the collection logic, overwrite the item map data
            return;
        }
    }
}

static bool32 CanStoneBePlacedAtXY(u32 x, u32 y, enum MiningId miningId) // PSF magic
{
    u32 height = MiningUtil_GetTopValue(miningId) + 1;
    u32 width =  MiningUtil_GetLeftValue(miningId) + 1;

    if (x + width > MINING_WALL_WIDTH)
        return FALSE;

    if (y + height > MINING_WALL_HEIGHT)
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

static bool32 DoesStoneFitInItemMap(enum MiningId miningId)
{
    if (miningId == MININGID_NONE)
        return FALSE;

    for (u32 coordX = 0; coordX < MINING_WALL_WIDTH; coordX++)
    {
        for (u32 coordY = 0; coordY < MINING_WALL_HEIGHT; coordY++)
        {
            if (CanStoneBePlacedAtXY(coordX, coordY, miningId))
                return TRUE;
        }
    }

    return FALSE;
}

static void GetRandomTile(u32 *x, u32 *y)
{
    u32 rand = RandomUniform(RNG_NONE, 0, MINING_WALL_HEIGHT * MINING_WALL_WIDTH - 1);
    *x = rand % MINING_WALL_WIDTH;
    *y = rand % MINING_WALL_HEIGHT;
}

static void DoDrawRandomStone(enum MiningId miningId)
{
    u32 x, y;

    do {
        GetRandomTile(&x, &y);
    } while(!CanStoneBePlacedAtXY(x, y, miningId));

    DrawItemSprite(x, y, miningId, TAG_DUMMY, ITEM_STATE_ID_NONE); // We use ITEM_STATE_ID_NONE because here, a stone is guaranteed
    OverwriteItemMapData(x, y, ITEM_STATE_ID_STONE, miningId);
}

static void HandleItemState(u32 buriedItemIndex)
{
    struct BuriedItem *item = &sMiningUiState->buriedItems[buriedItemIndex];
    u32 tileCount = MiningUtil_GetTotalTileAmount(item->miningId);

    if (item->isSelected && item->buriedItemTileCount < tileCount)
    {
        for (u32 i = 0; i < MINING_WALL_SIZE; i++)
        {
            if (sMiningUiState->itemMap[i] != buriedItemIndex + 1 || sMiningUiState->layerMap[i] != TERRAIN_LAYER_CLEARED)
                continue;

            sMiningUiState->itemMap[i] = ITEM_STATE_TILE_DUG_UP;
            item->buriedItemTileCount++;
        }
    }
    else if (item->buriedItemTileCount == tileCount)
    {
        BeginNormalPaletteFade(1 << (16 + gSprites[item->spriteId].oam.paletteNum), 2, 16, 0, RGB_WHITE);
        item->buriedItemTileCount = tileCount + 1;
        SetBuriedItemStatus(buriedItemIndex, TRUE);
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
        if (sMiningUiState->itemMap[i] == ITEM_STATE_ID_STONE && sMiningUiState->layerMap[i] == TERRAIN_LAYER_CLEARED)
            sMiningUiState->itemMap[i] = ITEM_STATE_TILE_DUG_UP;
    }
}

static bool32 AtCornerOfRectangle(u32 row, u32 col, u32 baseRow, u32 baseCol, u32 finalRow, u32 finalCol)
{
    return (col == baseCol && row == baseRow)
        || (col == baseCol && row == finalRow)
        || (col == finalCol && row == baseRow)
        || (col == finalCol && row == finalRow);
}

#define ROCK_PATCH_SIZE 5

// Randomly generates a terrain, stores the layering in an array and draw the right tiles, with the help of the layer map, to the screen.
// Use the above function just to draw a tile once
// Credits - Skeli
static void Mining_DrawRandomTerrain(void)
{
    u32 row1, row2, col1, col2, x, y, i, totalTimes;
    s32 baseRow; // Rocks can go up to one row over on either top or bottom
    s32 baseCol; // Rocks can go up to one col over on either left or right
    s32 finalRow;
    s32 finalCol;
    u16 *ptr = GetBgTilemapBuffer(2);

    // Start by placing blank layer 3 rocks
    for (i = 0; i < MINING_WALL_SIZE; ++i)
        sMiningUiState->layerMap[i] = TERRAIN_LAYER_2;

    // Create patches of lighter dirt areas
    totalTimes = RandomUniform(RNG_NONE, 3, 7);
    for (i = 0; i < totalTimes; ++i)
    {
        GetRandomTile(&col1, &row1);
        do
        {
            GetRandomTile(&col2, &row2);
        } while (col1 == col2 || row1 == row2);

        u32 temp;
        if (row2 < row1)
            SWAP(row1, row2, temp);
        if (col2 < col1)
            SWAP(col1, col2, temp);

        for (; row1 < row2; ++row1)
        {
            for (u32 j = col1; j < col2; ++j)
                sMiningUiState->layerMap[j + row1 * 12] = TERRAIN_LAYER_4;
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
    totalTimes = RandomUniform(RNG_NONE, 2, 6);
    for (i = 0; i < totalTimes; ++i)
    {
        // Rocks can go up to tile over on any side of the board
        baseRow = RandomUniform(RNG_NONE, 0, MINING_WALL_HEIGHT - 1 + ROCK_PATCH_SIZE) - ROCK_PATCH_SIZE;
        baseCol = RandomUniform(RNG_NONE, 0, MINING_WALL_WIDTH - 1 + ROCK_PATCH_SIZE) - ROCK_PATCH_SIZE;
        finalRow = baseRow + ROCK_PATCH_SIZE;
        finalCol = baseCol + ROCK_PATCH_SIZE;

        for (s32 k = baseRow; k < finalRow; ++k)
        {
            if (k < 0 || k >= MINING_WALL_HEIGHT)
                continue; // Not legal row

            for (s32 m = baseCol; m < finalCol; ++m)
            {
                if (m < 0 || m >= MINING_WALL_WIDTH)
                    continue; // Not legal column

                if (AtCornerOfRectangle(k, m, baseRow, baseCol, finalRow - 1, finalCol - 1))
                    continue; // Leave corner out

                sMiningUiState->layerMap[m + k * MINING_WALL_WIDTH] = TERRAIN_LAYER_0;
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
    u32 i = (sMiningUiState->cursorY - 2 + ofsY) * MINING_WALL_WIDTH + sMiningUiState->cursorX + ofsX; // It needs the `-2` because the cursorY value started at `2`
    u32 tileX = (sMiningUiState->cursorX + ofsX) * 2;
    u32 tileY = (sMiningUiState->cursorY + ofsY) * 2;
    if (sMiningUiState->layerMap[i] < TERRAIN_LAYER_CLEARED)
    {
        sMiningUiState->layerMap[i]++;

        switch (sMiningUiState->layerMap[i]) // Each case represents one layer on the wall
        {
        case TERRAIN_LAYER_1:
            OverwriteTileDataInTilemapBuffer(0x19, tileX, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x1A, tileX + 1, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x1E, tileX, tileY + 1, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x1F, tileX + 1, tileY + 1, ptr, 0x01);
            break;
        case TERRAIN_LAYER_2:
            OverwriteTileDataInTilemapBuffer(0x10, tileX, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x11, tileX + 1, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x15, tileX, tileY + 1, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x16, tileX + 1, tileY + 1, ptr, 0x01);
            break;
        case TERRAIN_LAYER_3:
            OverwriteTileDataInTilemapBuffer(0x0C, tileX, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x0D, tileX + 1, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x12, tileX, tileY + 1, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x13, tileX + 1, tileY + 1, ptr, 0x01);
            break;
        case TERRAIN_LAYER_4:
            OverwriteTileDataInTilemapBuffer(0x05, tileX, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x06, tileX + 1, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x0A, tileX, tileY + 1, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x0B, tileX + 1, tileY + 1, ptr, 0x01);
            break;
        case TERRAIN_LAYER_5:
            OverwriteTileDataInTilemapBuffer(0x01, tileX, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x02, tileX + 1, tileY, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x03, tileX, tileY + 1, ptr, 0x01);
            OverwriteTileDataInTilemapBuffer(0x04, tileX + 1, tileY + 1, ptr, 0x01);
            break;
        case TERRAIN_LAYER_CLEARED:
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
    u32 pos = sMiningUiState->cursorX + (sMiningUiState->cursorY - 2) * MINING_WALL_WIDTH;

    if (sMiningUiState->itemMap[pos] != ITEM_STATE_TILE_DUG_UP)
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
    u32 pos = sMiningUiState->cursorX + (sMiningUiState->cursorY - 2) * MINING_WALL_WIDTH;

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

        if (sMiningUiState->layerMap[pos] != TERRAIN_LAYER_CLEARED)
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
        if (MINING_USE_DEFAULT_MESSAGE_BOX)
        {
            LoadBgTiles(GetWindowAttribute(WIN_MSG, WINDOW_BG), sMiningMessageBoxGfx, 0x1C0, 20);
            LoadPalette(sMiningMessageBoxPal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
            LoadPalette(sMiningMessageBoxPal, BG_PLTT_ID(14), PLTT_SIZE_4BPP);
        }
        else
        {
            LoadBgTiles(GetWindowAttribute(WIN_MSG, WINDOW_BG), gMessageBox_Gfx, 0x1C0, 20);
            LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(15), PLTT_SIZE_4BPP);
            Menu_LoadStdPalAt(BG_PLTT_ID(14));
        }
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

    if (itemId == ITEM_NONE || !GetBuriedItemStatus(itemIndex))
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

static u32 GetNumberOfFoundItems(void)
{
    u32 count = 0;

    for (u32 itemIndex = 0; itemIndex < MINING_MAX_NUM_BURIED_ITEMS; itemIndex++)
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
    for (u32 index = 0; index < MINING_MAX_NUM_BURIED_ITEMS; index++)
    {
        SetBuriedItemsId(index, MININGID_NONE);
        SetBuriedItemStatus(index, FALSE);
    }
}

static void SetBuriedItemsId(u32 index, enum MiningId miningId)
{
    sMiningUiState->buriedItems[index].itemId = sMiningObjectList[miningId].itemId;
    sMiningUiState->buriedItems[index].miningId = miningId;
}

static void SetBuriedItemStatus(u32 index, bool32 status)
{
    sMiningUiState->buriedItems[index].isDugUp = status;
}

static enum Item GetBuriedBagItemId(u32 index)
{
    return sMiningUiState->buriedItems[index].itemId;
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
