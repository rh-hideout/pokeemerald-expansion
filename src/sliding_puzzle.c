#include "global.h"
#include "sliding_puzzle.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"

static void CB2_LoadSlidingPuzzle(void);
static void CB2_SlidingPuzzle(void);
static void VBlankCB_SlidingPuzzle(void);
static void Task_SlidingPuzzle_WaitFadeIn(u8);
static void Task_SlidingPuzzle_HandleInput(u8);
static void Task_SlidingPuzzle_Glow(u8);
static void Task_SlidingPuzzle_Solved(u8);
static void Task_SlidingPuzzle_Exit(u8);
static void DrawInstructionsBar(u8);
static void CreateCursorSprite(void);
static void CreateTileSprites(void);
static void MoveCursor(s8, s8);
static void MoveCursorSprite(s8, s8, u8);
static bool32 CursorIsOnTile(void);
static bool32 CursorIsOnImmovableTile(void);
static void SelectTile(void);
static void PlaceTile(void);
static void RotateTile(u8);
static void CheckForSolution(void);
static void ExitSlidingPuzzle(u8);
static void SpriteCB_Cursor(struct Sprite *);

static EWRAM_DATA struct SlidingPuzzle *sSlidingPuzzle = NULL;

// Keep the player's original Button Mode (e.g., Normal / L=R / L=A)
static u8 sSavedButtonMode = 0;
static bool8 sSavedButtonModeValid = FALSE;


static const u32 sSlidingPuzzle_Gfx[]     = INCBIN_U32("graphics/sliding_puzzle/bg.4bpp.lz");
static const u32 sSlidingPuzzle_Tilemap[] = INCBIN_U32("graphics/sliding_puzzle/map.bin.lz");
static const u16 sSlidingPuzzle_Pal[]     = INCBIN_U16("graphics/sliding_puzzle/bg.gbapal");

enum
{
    WIN_INSTRUCTIONS_BAR,
    WIN_DUMMY,
};

static const struct WindowTemplate sWindowTemplates[] =
{
    [WIN_INSTRUCTIONS_BAR] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 13,
        .baseBlock = 1,
    },
    [WIN_DUMMY] = DUMMY_WIN_TEMPLATE,
};

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 1,
        .mapBaseIndex = 29,
        .priority = 3,
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .priority = 3,
    },
};

static const u16 sColumnXCoords[NUM_SLIDING_PUZZLE_COLS] =
{
    32, 72, 104, 136, 168, 208,
};

static const u16 sRowYCoords[NUM_SLIDING_PUZZLE_ROWS] =
{
    40,
    72,
    104,
    136,
};

static const u32 sCursor_Gfx[]      = INCBIN_U32("graphics/sliding_puzzle/cursor.4bpp.lz");
static const u16 sCursorTiles_Pal[] = INCBIN_U16("graphics/sliding_puzzle/cursor_tiles.gbapal");

#define TAG_CURSOR    244
#define GFXTAG_TILES  245

static const struct SpritePalette sSpritePalettes_CursorTiles[] =
{
    {
        .data = sCursorTiles_Pal,
        .tag = TAG_CURSOR
    },
    {},
};

static const struct CompressedSpriteSheet sSpriteSheet_Cursor =
{
    .data = sCursor_Gfx,
    .size = 0x400,
    .tag = TAG_CURSOR,
};

static const struct OamData sOamData_Cursor =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sSpriteTemplate_Cursor =
{
    .tileTag = TAG_CURSOR,
    .paletteTag = TAG_CURSOR,
    .oam = &sOamData_Cursor,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Cursor,
};

static const struct OamData sOamData_Tiles =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_Tile0[] =
{
    ANIMCMD_FRAME(0 * 16, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tile1[] =
{
    ANIMCMD_FRAME(1 * 16, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tile2[] =
{
    ANIMCMD_FRAME(2 * 16, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tile3[] =
{
    ANIMCMD_FRAME(3 * 16, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tile4[] =
{
    ANIMCMD_FRAME(4 * 16, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tile5[] =
{
    ANIMCMD_FRAME(5 * 16, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tile6[] =
{
    ANIMCMD_FRAME(6 * 16, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tile7[] =
{
    ANIMCMD_FRAME(7 * 16, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tile8[] =
{
    ANIMCMD_FRAME(8 * 16, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tile9[] =
{
    ANIMCMD_FRAME(9 * 16, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tile10[] =
{
    ANIMCMD_FRAME(10 * 16, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tile11[] =
{
    ANIMCMD_FRAME(11 * 16, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tile12[] =
{
    ANIMCMD_FRAME(12 * 16, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tile13[] =
{
    ANIMCMD_FRAME(13 * 16, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tile14[] =
{
    ANIMCMD_FRAME(14 * 16, 30),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Tile15[] =
{
    ANIMCMD_FRAME(15 * 16, 30),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_Tiles[] =
{
    sAnim_Tile0,
    sAnim_Tile1,
    sAnim_Tile2,
    sAnim_Tile3,
    sAnim_Tile4,
    sAnim_Tile5,
    sAnim_Tile6,
    sAnim_Tile7,
    sAnim_Tile8,
    sAnim_Tile9,
    sAnim_Tile10,
    sAnim_Tile11,
    sAnim_Tile12,
    sAnim_Tile13,
    sAnim_Tile14,
    sAnim_Tile15,
};

static const union AffineAnimCmd sSpriteAffineAnim_Rotated0[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sSpriteAffineAnim_Rotated90[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -64, 0),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sSpriteAffineAnim_Rotated180[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -128, 0),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sSpriteAffineAnim_Rotated270[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 64, 0),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingClockwise0to90[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingClockwise90to180[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -64, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingClockwise180to270[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -128, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingClockwise270to360[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 64, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingAnticlockwise360to270[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingAnticlockwise270to180[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 64, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingAnticlockwise180to90[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -128, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingAnticlockwise90to0[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -64, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_RotateTile[] =
{
    sSpriteAffineAnim_Rotated0,
    sSpriteAffineAnim_Rotated90,
    sSpriteAffineAnim_Rotated180,
    sSpriteAffineAnim_Rotated270,
    sSpriteAffineAnim_RotatingAnticlockwise360to270,
    sSpriteAffineAnim_RotatingAnticlockwise90to0,
    sSpriteAffineAnim_RotatingAnticlockwise180to90,
    sSpriteAffineAnim_RotatingAnticlockwise270to180,
    sSpriteAffineAnim_RotatingClockwise0to90,
    sSpriteAffineAnim_RotatingClockwise90to180,
    sSpriteAffineAnim_RotatingClockwise180to270,
    sSpriteAffineAnim_RotatingClockwise270to360,
};

static const struct SpriteTemplate sSpriteTemplate_Tiles =
{
    .tileTag = GFXTAG_TILES,
    .paletteTag = TAG_CURSOR,
    .oam = &sOamData_Tiles,
    .anims = sAnims_Tiles,
    .images = NULL,
    .affineAnims = sSpriteAffineAnimTable_RotateTile,
    .callback = SpriteCallbackDummy,
};

#define __ 0

#include "data/sliding_puzzles.h"

enum
{
    INSTRUCTION_NO_SELECTION,
    INSTRUCTION_PICK_UP,
    INSTRUCTION_PLACE,
    INSTRUCTION_SWAP,
    INSTRUCTION_ROTATE,
    INSTRUCTION_CONTINUE,
};

static const u8 sText_MoveQuit[]            = _("{DPAD_NONE} Move {B_BUTTON} Quit");
static const u8 sText_MovePickUpQuit[]      = _("{DPAD_NONE} Move {A_BUTTON} Pick Up {B_BUTTON} Quit");
static const u8 sText_MovePlaceRotateQuit[] = _("{DPAD_NONE} Move {A_BUTTON} Place {L_BUTTON}{R_BUTTON} Rotate {B_BUTTON} Quit");
static const u8 sText_MoveSwapRotateQuit[]  = _("{DPAD_NONE} Move {A_BUTTON} Swap {L_BUTTON}{R_BUTTON} Rotate {B_BUTTON} Quit");
static const u8 sText_MoveRotateQuit[]      = _("{DPAD_NONE} Move {L_BUTTON}{R_BUTTON} Rotate {B_BUTTON} Quit");
static const u8 sText_Continue[]            = _("{A_BUTTON}{B_BUTTON} Continue");

static const u8 *const sInstructions[] =
{
    [INSTRUCTION_NO_SELECTION] = sText_MoveQuit,
    [INSTRUCTION_PICK_UP]      = sText_MovePickUpQuit,
    [INSTRUCTION_PLACE]        = sText_MovePlaceRotateQuit,
    [INSTRUCTION_SWAP]         = sText_MoveSwapRotateQuit,
    [INSTRUCTION_ROTATE]       = sText_MoveRotateQuit,
    [INSTRUCTION_CONTINUE]     = sText_Continue,
};

void DoSlidingPuzzle(void)
{
    SetMainCallback2(CB2_LoadSlidingPuzzle);
    gMain.savedCallback = CB2_ReturnToFieldContinueScriptPlayMapMusic;
}

static void CB2_LoadSlidingPuzzle(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_BG3CNT, 0);
        SetGpuReg(REG_OFFSET_BG2CNT, 0);
        SetGpuReg(REG_OFFSET_BG1CNT, 0);
        SetGpuReg(REG_OFFSET_BG0CNT, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        break;
    case 1:
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        ResetBgsAndClearDma3BusyFlags(0);
        break;
    case 2:
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        InitWindows(sWindowTemplates);
        break;
    case 3:
        sSlidingPuzzle = AllocZeroed(sizeof(*sSlidingPuzzle));
        sSlidingPuzzle->heldTile = __;
        sSlidingPuzzle->puzzleId = gSpecialVar_0x8004;
        sSlidingPuzzle->solved   = gSpecialVar_0x8005;

        // Disable L=A during the sliding puzzle
        sSavedButtonMode = gSaveBlock2Ptr->optionsButtonMode;    // current setting from options menu
        sSavedButtonModeValid = TRUE;
        gSaveBlock2Ptr->optionsButtonMode = 0;                   // force "Normal" button mode
        break;
    case 4:
        LoadPalette(GetTextWindowPalette(2), 0xD0, 32);
        if (sSlidingPuzzle->solved)
            DrawInstructionsBar(INSTRUCTION_CONTINUE);
        else
            DrawInstructionsBar(INSTRUCTION_NO_SELECTION);
        ShowBg(0);
        break;
    case 5:
        LoadPalette(sSlidingPuzzle_Pal, 0, 32);
        LZ77UnCompVram(sSlidingPuzzle_Gfx, (void *)(BG_CHAR_ADDR(0)));
        LZ77UnCompVram(sSlidingPuzzle_Tilemap, (void *)(BG_SCREEN_ADDR(7)));
        ShowBg(1);
        break;
    case 6:
        LoadSpritePalettes(sSpritePalettes_CursorTiles);
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        break;
    case 7:
        LoadCompressedSpriteSheet(&sSpriteSheet_Cursor);
        CreateCursorSprite();
        break;
    case 8:
        LoadCompressedSpriteSheet(&sSpriteSheet_Tiles[sSlidingPuzzle->puzzleId]);
        CreateTileSprites();
        break;
    default:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        CreateTask(Task_SlidingPuzzle_WaitFadeIn, 0);
        SetVBlankCallback(VBlankCB_SlidingPuzzle);
        SetMainCallback2(CB2_SlidingPuzzle);
        return;
    }
    gMain.state++;
}

static void CB2_SlidingPuzzle(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB_SlidingPuzzle(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_SlidingPuzzle_WaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (!sSlidingPuzzle->solved)
            gTasks[taskId].func = Task_SlidingPuzzle_HandleInput;
        else
            gTasks[taskId].func = Task_SlidingPuzzle_Solved;
    }
}

#define sTimer        data[0]
#define sAnimating    data[1]
#define sRow          data[2]
#define sCol          data[3]
#define sTileId       data[4]
#define sOrientation  data[5]

static void Task_SlidingPuzzle_HandleInput(u8 taskId)
{
    // Prevent input if the puzzle has been solved
    if (sSlidingPuzzle->solved)
    {
        gTasks[taskId].func = Task_SlidingPuzzle_Glow;
        return;
    }

    // Prevent input while the tile is rotating
    if (sSlidingPuzzle->heldTile != __)
    {
        struct Sprite *sprite = &gSprites[sSlidingPuzzle->heldTile];

        if (sprite->sAnimating && !sprite->affineAnimEnded)
            return;
    }

    if (JOY_NEW(B_BUTTON))
        ExitSlidingPuzzle(taskId);
    else if (JOY_NEW(DPAD_LEFT))
        MoveCursor(-1,  0);
    else if (JOY_NEW(DPAD_RIGHT))
        MoveCursor( 1,  0);
    else if (JOY_NEW(DPAD_UP))
        MoveCursor( 0, -1);
    else if (JOY_NEW(DPAD_DOWN))
        MoveCursor( 0,  1);

    if (sSlidingPuzzle->heldTile == __)
    {
        // Not holding a tile
        if (CursorIsOnTile() && !CursorIsOnImmovableTile())
        {
            DrawInstructionsBar(INSTRUCTION_PICK_UP);
            if (JOY_NEW(A_BUTTON))
                SelectTile();
        }
        else
        {
            DrawInstructionsBar(INSTRUCTION_NO_SELECTION);
        }
    }
    else
    {
        // Currently holding a tile
        if (CursorIsOnTile() && !CursorIsOnImmovableTile())
        {
            DrawInstructionsBar(INSTRUCTION_SWAP);
            if (JOY_NEW(A_BUTTON))
                SelectTile();
        }
        else if (CursorIsOnImmovableTile())
        {
            DrawInstructionsBar(INSTRUCTION_ROTATE);
        }
        else
        {
            DrawInstructionsBar(INSTRUCTION_PLACE);
            if (JOY_NEW(A_BUTTON))
                PlaceTile();
        }

        if (JOY_NEW(L_BUTTON))
            RotateTile(ROTATE_ANTICLOCKWISE);
        else if (JOY_NEW(R_BUTTON))
            RotateTile(ROTATE_CLOCKWISE);
    }
}

#define tState  data[0]
#define tTimer  data[1]
#define tGlow   data[2]

static void Task_SlidingPuzzle_Glow(u8 taskId)
{
    u16 color;
    s16* data = gTasks[taskId].data;
    switch (tState)
    {
    case 0:
        DrawInstructionsBar(INSTRUCTION_CONTINUE);
        tState++;
        break;
    case 1:
        DestroySprite(&gSprites[sSlidingPuzzle->cursorSpriteId]);
        PlayFanfare(MUS_LEVEL_UP);
        tGlow = 22;
        tState++;
        break;
    case 2:
        tTimer++;
        if ((tTimer % 4) == 0)
        {
            if (++tGlow == 31)
                tState++;
            color = RGB(tGlow, tGlow, tGlow);
            LoadPalette(&color, 0x103, sizeof(color));
        }
        break;
    case 3:
        tTimer++;
        if ((tTimer % 4) == 0)
        {
            tGlow--;
            if (tGlow > 22)
            {
                color = RGB(tGlow, tGlow, tGlow);
            }
            else
            {
                color = RGB(28, 22, 13);
                tState++;
            }
            LoadPalette(&color, 0x103, sizeof(color));
        }
        break;
    default:
        if (IsFanfareTaskInactive())
            gTasks[taskId].func = Task_SlidingPuzzle_Solved;
        break;
    }
}

#undef tState
#undef tTimer
#undef tGlow

static void Task_SlidingPuzzle_Solved(u8 taskId)
{
    if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
        ExitSlidingPuzzle(taskId);
}

static void Task_SlidingPuzzle_Exit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        // Restore original Button Mode
        if (sSavedButtonModeValid)
        {
            gSaveBlock2Ptr->optionsButtonMode = sSavedButtonMode;
            sSavedButtonModeValid = FALSE;
        }

        gSpecialVar_Result = sSlidingPuzzle->solved;
        Free(sSlidingPuzzle);
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

static void DrawInstructionsBar(u8 stringId)
{
    const u8 color[3] = { TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY };

    FillWindowPixelBuffer(WIN_INSTRUCTIONS_BAR, PIXEL_FILL(15));
    AddTextPrinterParameterized3(WIN_INSTRUCTIONS_BAR, FONT_SMALL, 2, 1, color, 0, sInstructions[stringId]);
    PutWindowTilemap(WIN_INSTRUCTIONS_BAR);
    CopyWindowToVram(WIN_INSTRUCTIONS_BAR, COPYWIN_FULL);
    ScheduleBgCopyTilemapToVram(0);
}

static void CreateCursorSprite(void)
{
    u8 spriteId = SPRITE_NONE;

    if (!sSlidingPuzzle->solved)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Cursor,
                                sColumnXCoords[0],
                                sRowYCoords[0],
                                1);
        gSprites[spriteId].sTimer = 0;
        gSprites[spriteId].sAnimating = TRUE;
        gSprites[spriteId].sRow = 0;
        gSprites[spriteId].sCol = 0;
    }

    sSlidingPuzzle->cursorSpriteId = spriteId;
}

static void CreateTileSprites(void)
{
    u8 row, col, puzzleId, tile;
    for (row = 0; row < NUM_SLIDING_PUZZLE_ROWS; ++row)
    {
        for (col = 0; col < NUM_SLIDING_PUZZLE_COLS; ++col)
        {
            if (sSlidingPuzzle->solved)
                puzzleId = SLIDING_PUZZLE_SOLVED;
            else
                puzzleId = sSlidingPuzzle->puzzleId;

            tile = sPuzzleLayouts[puzzleId][row][col];
            if (tile != __)
            {
                u8 spriteId = CreateSprite(&sSpriteTemplate_Tiles,
                                           sColumnXCoords[col],
                                           sRowYCoords[row],
                                           2);
                struct Sprite *sprite = &gSprites[spriteId];
                sprite->sAnimating = FALSE;
                sprite->sRow = row;
                sprite->sCol = col;
                sprite->sTileId = tile;
                sprite->sOrientation = sTileOrientations[puzzleId][row][col];
                if (sprite->sOrientation >= ORIENTATION_MAX)
                    sprite->sOrientation = ORIENTATION_0;
                StartSpriteAnim(sprite, tile - 1);
                StartSpriteAffineAnim(sprite, sprite->sOrientation);
                tile = spriteId;
            }

            sSlidingPuzzle->tiles[row][col] = tile;
        }
    }
}

static void MoveCursor(s8 deltaX, s8 deltaY)
{
    MoveCursorSprite(deltaX, deltaY, sSlidingPuzzle->cursorSpriteId);

    if (sSlidingPuzzle->heldTile != __)
    {
        MoveCursorSprite(deltaX, deltaY, sSlidingPuzzle->heldTile);
        PlaySE(SE_BALL_TRAY_ENTER);
    }
}

static void MoveCursorSprite(s8 deltaX, s8 deltaY, u8 spriteId)
{
    struct Sprite *sprite = &gSprites[spriteId];
    s8 row = sprite->sRow + deltaY;
    s8 col = sprite->sCol + deltaX;

    if (row < FIRST_SLIDING_PUZZLE_ROW)
        row = FINAL_SLIDING_PUZZLE_ROW;
    else if (row > FINAL_SLIDING_PUZZLE_ROW)
        row = FIRST_SLIDING_PUZZLE_ROW;

    if (col < FIRST_SLIDING_PUZZLE_COL)
        col = FINAL_SLIDING_PUZZLE_COL;
    else if (col > FINAL_SLIDING_PUZZLE_COL)
        col = FIRST_SLIDING_PUZZLE_COL;

    sprite->sCol = col;
    sprite->sRow = row;
    sprite->x = sColumnXCoords[sprite->sCol];
    sprite->y = sRowYCoords[sprite->sRow];

    sprite->invisible = FALSE;
    sprite->sTimer = 0;
}

static bool32 CursorIsOnTile(void)
{
    struct Sprite *cursor = &gSprites[sSlidingPuzzle->cursorSpriteId];

    if (sSlidingPuzzle->tiles[cursor->sRow][cursor->sCol] != __)
        return TRUE;

    return FALSE;
}

static bool32 CursorIsOnImmovableTile(void)
{
    struct Sprite *cursor = &gSprites[sSlidingPuzzle->cursorSpriteId];

    if (sTileOrientations[sSlidingPuzzle->puzzleId][cursor->sRow][cursor->sCol] == IMMOVABLE_TILE)
        return TRUE;

    return FALSE;
}

static void SelectTile(void)
{
    struct Sprite *cursor = &gSprites[sSlidingPuzzle->cursorSpriteId];

    u8 tile = sSlidingPuzzle->heldTile;
    if (tile != __)
        gSprites[tile].subpriority = 2;

    sSlidingPuzzle->heldTile = sSlidingPuzzle->tiles[cursor->sRow][cursor->sCol];
    gSprites[sSlidingPuzzle->heldTile].subpriority = 0;

    sSlidingPuzzle->tiles[cursor->sRow][cursor->sCol] = tile;

    cursor->sAnimating = FALSE;
    PlaySE(SE_SELECT);
    CheckForSolution();
}

static void PlaceTile(void)
{
    struct Sprite *cursor = &gSprites[sSlidingPuzzle->cursorSpriteId];

    sSlidingPuzzle->tiles[cursor->sRow][cursor->sCol] = sSlidingPuzzle->heldTile;
    gSprites[sSlidingPuzzle->heldTile].subpriority = 2;

    sSlidingPuzzle->heldTile = __;

    cursor->sAnimating = TRUE;
    PlaySE(SE_SELECT);
    CheckForSolution();
}

static void RotateTile(u8 rotDir)
{
    struct Sprite *sprite = &gSprites[sSlidingPuzzle->heldTile];
    u8 affineAnimation;

    if (rotDir == ROTATE_ANTICLOCKWISE)
    {
        affineAnimation = sprite->sOrientation + 4;
        if (sprite->sOrientation)
            sprite->sOrientation--;
        else
            sprite->sOrientation = ORIENTATION_270;
    }
    else if (rotDir == ROTATE_CLOCKWISE)
    {
        affineAnimation = sprite->sOrientation + 8;
        sprite->sOrientation++;
        sprite->sOrientation = sprite->sOrientation % ORIENTATION_MAX;
    }

    StartSpriteAffineAnim(sprite, affineAnimation);
    sprite->sAnimating = TRUE;
}

static void CheckForSolution(void)
{
    u8 row, col, tile;
    for (row = 0; row < NUM_SLIDING_PUZZLE_ROWS; row++)
    {
        for (col = 0; col < NUM_SLIDING_PUZZLE_COLS; col++)
        {
            struct Sprite *tile = &gSprites[sSlidingPuzzle->tiles[row][col]];
            u8 tileId = sPuzzleLayouts[SLIDING_PUZZLE_SOLVED][row][col];

            if (tile->sTileId != tileId || tile->sOrientation != ORIENTATION_0)
            {
                sSlidingPuzzle->solved = FALSE;
                return;
            }
        }
    }

    sSlidingPuzzle->solved = TRUE;
}

static void ExitSlidingPuzzle(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_SlidingPuzzle_Exit;
}

static void SpriteCB_Cursor(struct Sprite *sprite)
{
    if (++sprite->sTimer % 16 == 0)
    {
        sprite->sTimer = 0;
        if (sprite->sAnimating)
            sprite->invisible ^= TRUE;
        else
            sprite->invisible = FALSE;
    }
}

#undef sTimer
#undef sAnimating
#undef sRow
#undef sCol
#undef sTileId
#undef sOrientation

#undef __
