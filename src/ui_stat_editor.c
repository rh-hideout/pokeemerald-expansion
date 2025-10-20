#include "global.h"
#include "ui_stat_editor.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_icon.h"
#include "item_use.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "pokemon_icon.h"
#include "pokedex.h"
#include "trainer_pokemon_sprites.h"
#include "field_effect.h"
#include "field_screen_effect.h"

/*
 * 
 */
 
//==========DEFINES==========//
struct StatEditorResources
{
    MainCallback savedCallback;     // determines callback to run when we exit. e.g. where do we want to go after closing the menu
    u8 gfxLoadState;
    u8 mode;
    u8 monIconSpriteId;
    u16 speciesID;
    u16 selectedStat;
    u16 selectorSpriteId;
    u16 selector_x;
    u16 selector_y;
    u32 editingStat;
    u16 normalTotal;
    u16 evTotal;
    u16 ivTotal;
    u16 partyid;
    u16 inputMode;
};

#define INPUT_SELECT_STAT 0
#define INPUT_EDIT_STAT 1

#define CAN_EDIT_IVS 0 // set to 1 to allow editing IVs, 0 to disable

enum WindowIds
{
    WINDOW_1,
    WINDOW_2,
    WINDOW_3,
    WINDOW_4,
};

//==========EWRAM==========//
static EWRAM_DATA struct StatEditorResources *sStatEditorDataPtr = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

//==========STATIC=DEFINES==========//
static void StatEditor_RunSetup(void);
static bool8 StatEditor_DoGfxSetup(void);
static bool8 StatEditor_InitBgs(void);
static void StatEditor_FadeAndBail(void);
static bool8 StatEditor_LoadGraphics(void);
static void StatEditor_InitWindows(void);
static void PrintTitleToWindowMainState();
static void Task_StatEditorWaitFadeIn(u8 taskId);
static void Task_StatEditorMain(u8 taskId);
static void Task_MenuEditingStat(u8 taskId);
static void SampleUi_DrawMonIcon(u16 dexNum);
static void PrintMonStats(void);
static void SelectorCallback(struct Sprite *sprite);
static struct Pokemon *ReturnPartyMon();
static u8 CreateSelector();
static void DestroySelector();

//==========CONST=DATA==========//
static const struct BgTemplate sStatEditorBgTemplates[] =
{
    {
        .bg = 0,    // windows, etc
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .priority = 1
    }, 
    {
        .bg = 1,    // this bg loads the UI tilemap
        .charBaseIndex = 3,
        .mapBaseIndex = 28,
        .priority = 2
    },
    {
        .bg = 2,    // this bg loads the UI tilemap
        .charBaseIndex = 0,
        .mapBaseIndex = 26,
        .priority = 0
    }
};

static const struct WindowTemplate sMenuWindowTemplates[] = 
{
    [WINDOW_1] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 1,   // position from left (per 8 pixels)
        .tilemapTop = 0,    // position from top (per 8 pixels)
        .width = 30,        // width (per 8 pixels)
        .height = 2,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 1,     // tile start in VRAM
    },
    [WINDOW_2] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 11,   // position from left (per 8 pixels)
        .tilemapTop = 2,    // position from top (per 8 pixels)
        .width = 18,        // width (per 8 pixels)
        .height = 17,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 1 + 70,     // tile start in VRAM
    },
    [WINDOW_3] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 1,   // position from left (per 8 pixels)
        .tilemapTop = 11,    // position from top (per 8 pixels)
        .width = 8,        // width (per 8 pixels)
        .height = 9,        // height (per 8 pixels)
        .paletteNum = 15,   // palette index to use for text
        .baseBlock = 1 + 70 + 306,     // tile start in VRAM
    },
    DUMMY_WIN_TEMPLATE
};

static const u32 sStatEditorBgTiles[] = INCBIN_U32("graphics/ui_menu/background_tileset.4bpp.lz");
static const u32 sStatEditorBgTilemap[] = INCBIN_U32("graphics/ui_menu/background_tileset.bin.lz");
static const u16 sStatEditorBgPalette[] = INCBIN_U16("graphics/ui_menu/background_pal.gbapal");

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};
static const u8 sMenuWindowFontColors[][3] = 
{
    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_DARK_GRAY,  TEXT_COLOR_LIGHT_GRAY},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_WHITE,  TEXT_COLOR_DARK_GRAY},
    [FONT_RED]   = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_GRAY},
    [FONT_BLUE]  = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_BLUE,       TEXT_COLOR_LIGHT_GRAY},
};

#define TAG_SELECTOR 30004

static const u16 sSelector_Pal[] = INCBIN_U16("graphics/ui_menu/selector.gbapal");
static const u32 sSelector_Gfx[] = INCBIN_U32("graphics/ui_menu/selector.4bpp.lz");
static const u8 sA_ButtonGfx[]         = INCBIN_U8("graphics/ui_menu/a_button.4bpp");
static const u8 sB_ButtonGfx[]         = INCBIN_U8("graphics/ui_menu/b_button.4bpp");
static const u8 sR_ButtonGfx[]         = INCBIN_U8("graphics/ui_menu/r_button.4bpp");
static const u8 sDPad_ButtonGfx[]         = INCBIN_U8("graphics/ui_menu/dpad_button.4bpp");

static const struct OamData sOamData_Selector =
{
    .size = SPRITE_SIZE(32x32),
    .shape = SPRITE_SHAPE(32x32),
    .priority = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_Selector =
{
    .data = sSelector_Gfx,
    .size = 32*32*4/2,
    .tag = TAG_SELECTOR,
};

static const struct SpritePalette sSpritePal_Selector =
{
    .data = sSelector_Pal,
    .tag = TAG_SELECTOR
};

static const union AnimCmd sSpriteAnim_Selector0[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(0, 32),
    //ANIMCMD_FRAME(48, 10),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_Selector1[] =
{
    ANIMCMD_FRAME(32, 32),
    ANIMCMD_FRAME(32, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_Selector2[] =
{
    ANIMCMD_FRAME(16, 32),
    ANIMCMD_FRAME(16, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_Selector3[] =
{
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_FRAME(0, 32),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sSpriteAnimTable_Selector[] =
{
    sSpriteAnim_Selector0,
    sSpriteAnim_Selector1,
    sSpriteAnim_Selector2,
    sSpriteAnim_Selector3,
};

static const struct SpriteTemplate sSpriteTemplate_Selector =
{
    .tileTag = TAG_SELECTOR,
    .paletteTag = TAG_SELECTOR,
    .oam = &sOamData_Selector,
    .anims = sSpriteAnimTable_Selector,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SelectorCallback
};

// Begin Generic UI Initialization Code
void Task_OpenStatEditorFromStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        StatEditor_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

// This is our main initialization function if you want to call the menu from elsewhere
void StatEditor_Init(MainCallback callback)
{
    if ((sStatEditorDataPtr = AllocZeroed(sizeof(struct StatEditorResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }
    
    // initialize stuff
    sStatEditorDataPtr->gfxLoadState = 0;
    sStatEditorDataPtr->savedCallback = callback;
    sStatEditorDataPtr->selectorSpriteId = 0xFF;
    sStatEditorDataPtr->partyid = gSpecialVar_0x8004;
    
    SetMainCallback2(StatEditor_RunSetup);
}

static void StatEditor_RunSetup(void)
{
    while (1)
    {
        if (StatEditor_DoGfxSetup() == TRUE)
            break;
    }
}

static void StatEditor_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void StatEditor_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static bool8 StatEditor_DoGfxSetup(void)
{
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
        SetVBlankHBlankCallbacksToNull();
        ResetVramOamAndBgCntRegs();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (StatEditor_InitBgs())
        {
            sStatEditorDataPtr->gfxLoadState = 0;
            gMain.state++;
        }
        else
        {
            StatEditor_FadeAndBail();
            return TRUE;
        }
        break;
    case 3:
        if (StatEditor_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 4:
        sStatEditorDataPtr->speciesID = GetMonData(ReturnPartyMon(), MON_DATA_SPECIES);
        FreeMonIconPalettes();
        LoadMonIconPalettes();
        LoadCompressedSpriteSheet(&sSpriteSheet_Selector);
        LoadSpritePalette(&sSpritePal_Selector);
        SampleUi_DrawMonIcon(sStatEditorDataPtr->speciesID);
        gMain.state++;
        break;
    case 5:
        StatEditor_InitWindows();
        PrintTitleToWindowMainState();
        sStatEditorDataPtr->inputMode = INPUT_SELECT_STAT;
        PrintMonStats();
        CreateSelector();
        gMain.state++;
        break;
    case 6:
        CreateTask(Task_StatEditorWaitFadeIn, 0);
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(StatEditor_VBlankCB);
        SetMainCallback2(StatEditor_MainCB);
        return TRUE;
    }
    return FALSE;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void StatEditor_FreeResources(void)
{
    DestroySelector();
    FreeResourcesAndDestroySprite(&gSprites[sStatEditorDataPtr->monIconSpriteId], sStatEditorDataPtr->monIconSpriteId);
    try_free(sStatEditorDataPtr);
    try_free(sBg1TilemapBuffer);
    FreeAllWindowBuffers();
}


static void Task_StatEditorWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sStatEditorDataPtr->savedCallback);
        StatEditor_FreeResources();
        DestroyTask(taskId);
    }
}

static void StatEditor_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_StatEditorWaitFadeAndBail, 0);
    SetVBlankCallback(StatEditor_VBlankCB);
    SetMainCallback2(StatEditor_MainCB);
}

static bool8 StatEditor_InitBgs(void)
{
    ResetAllBgsCoordinates();
    sBg1TilemapBuffer = Alloc(0x800);
    if (sBg1TilemapBuffer == NULL)
        return FALSE;
    
    memset(sBg1TilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sStatEditorBgTemplates, NELEMS(sStatEditorBgTemplates));
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    return TRUE;
}

static bool8 StatEditor_LoadGraphics(void)
{
    switch (sStatEditorDataPtr->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sStatEditorBgTiles, 0, 0, 0);
        sStatEditorDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            DecompressDataWithHeaderWram(sStatEditorBgTilemap, sBg1TilemapBuffer);
            sStatEditorDataPtr->gfxLoadState++;
        }
        break;
    case 2:
        LoadPalette(sStatEditorBgPalette, 0, 32);
        sStatEditorDataPtr->gfxLoadState++;
        break;
    default:
        sStatEditorDataPtr->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void StatEditor_InitWindows(void)
{
    InitWindows(sMenuWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    
    FillWindowPixelBuffer(WINDOW_1, 0);
    PutWindowTilemap(WINDOW_1);
    CopyWindowToVram(WINDOW_1, 3);
    
    ScheduleBgCopyTilemapToVram(2);
}

static void Task_StatEditorWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_StatEditorMain;
}

static void Task_StatEditorTurnOff(u8 taskId)
{
    // s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        SetMainCallback2(sStatEditorDataPtr->savedCallback);
        StatEditor_FreeResources();
        DestroyTask(taskId);
    }
}

//
//       Stat Editor Code
//  End of UI setup code, beginning of stat editor specific code
//
static struct Pokemon *ReturnPartyMon()
{
    return &gPlayerParty[sStatEditorDataPtr->partyid];
}

#define MON_ICON_X     32 + 8
#define MON_ICON_Y     32 + 24
static void SampleUi_DrawMonIcon(u16 dexNum)
{
    u16 speciesId = dexNum;
    sStatEditorDataPtr->monIconSpriteId = CreateMonPicSprite_Affine(speciesId, 0, 0x8000, TRUE, MON_ICON_X, MON_ICON_Y, 0, TAG_NONE);

    gSprites[sStatEditorDataPtr->monIconSpriteId].oam.priority = 0;
}

static u8 CreateSelector()
{
    if (sStatEditorDataPtr->selectorSpriteId == 0xFF)
        sStatEditorDataPtr->selectorSpriteId = CreateSprite(&sSpriteTemplate_Selector, 188, 30, 0);

    gSprites[sStatEditorDataPtr->selectorSpriteId].invisible = FALSE;
    StartSpriteAnim(&gSprites[sStatEditorDataPtr->selectorSpriteId], 0);
    DebugPrintf("Sprite ID: %d", sStatEditorDataPtr->selectorSpriteId);
    return sStatEditorDataPtr->selectorSpriteId;
}

static void DestroySelector()
{
    if (sStatEditorDataPtr->selectorSpriteId != 0xFF)
        DestroySprite(&gSprites[sStatEditorDataPtr->selectorSpriteId]);
    sStatEditorDataPtr->selectorSpriteId = 0xFF;
}

#define DISTANCE_BETWEEN_STATS_Y 16
#define SECOND_COLUMN ((8 * 4))
#define THIRD_COLUMN ((8 * 8))
#define STARTING_X 60
#define STARTING_Y 26

struct MonPrintData {
    u16 x;
    u16 y;
};

static const struct MonPrintData StatPrintData[] =
{
    [MON_DATA_MAX_HP] = {STARTING_X, STARTING_Y},
    [MON_DATA_HP_EV] = {STARTING_X + SECOND_COLUMN, STARTING_Y},
    [MON_DATA_HP_IV] = {STARTING_X + THIRD_COLUMN, STARTING_Y},

    [MON_DATA_ATK] = {STARTING_X, STARTING_Y + DISTANCE_BETWEEN_STATS_Y},
    [MON_DATA_ATK_EV] = {STARTING_X + SECOND_COLUMN, STARTING_Y + DISTANCE_BETWEEN_STATS_Y},
    [MON_DATA_ATK_IV] = {STARTING_X + THIRD_COLUMN, STARTING_Y + DISTANCE_BETWEEN_STATS_Y},

    [MON_DATA_DEF] = {STARTING_X, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 2)},
    [MON_DATA_DEF_EV] = {STARTING_X + SECOND_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 2)},
    [MON_DATA_DEF_IV] = {STARTING_X + THIRD_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 2)},

    [MON_DATA_SPATK] = {STARTING_X, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 3)},
    [MON_DATA_SPATK_EV] = {STARTING_X + SECOND_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 3)},
    [MON_DATA_SPATK_IV] = {STARTING_X + THIRD_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 3)},

    [MON_DATA_SPDEF] = {STARTING_X, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 4)},
    [MON_DATA_SPDEF_EV] = {STARTING_X + SECOND_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 4)},
    [MON_DATA_SPDEF_IV] = {STARTING_X + THIRD_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 4)},

    [MON_DATA_SPEED] = {STARTING_X, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 5)},
    [MON_DATA_SPEED_EV] = {STARTING_X + SECOND_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 5)},
    [MON_DATA_SPEED_IV] = {STARTING_X + THIRD_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 5)},
};

static const u16 statsToPrintActual[] = {
        MON_DATA_MAX_HP, MON_DATA_ATK, MON_DATA_DEF, MON_DATA_SPEED, MON_DATA_SPATK, MON_DATA_SPDEF,
};

static const u16 statsToPrintEVs[] = {
        MON_DATA_HP_EV, MON_DATA_ATK_EV, MON_DATA_DEF_EV, MON_DATA_SPEED_EV, MON_DATA_SPATK_EV, MON_DATA_SPDEF_EV,
};

static const u16 statsToPrintIVs[] = {
        MON_DATA_HP_IV, MON_DATA_ATK_IV, MON_DATA_DEF_IV, MON_DATA_SPEED_IV, MON_DATA_SPATK_IV, MON_DATA_SPDEF_IV,
};


static const u8 sGenderColors[2][3] =
{
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_BLUE, TEXT_COLOR_BLUE},
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED, TEXT_COLOR_RED}
};

static const u8 sText_MenuTitle[] = _("Stat Editor");
static const u8 sText_MenuHP[] = _("HP");
static const u8 sText_MenuAttack[] = _("Attack");
static const u8 sText_MenuSpAttack[] = _("Sp. Atk");
static const u8 sText_MenuDefense[] = _("Defense");
static const u8 sText_MenuSpDefense[] = _("Sp. Def");
static const u8 sText_MenuSpeed[] = _("Speed");
static const u8 sText_MenuTotal[] = _("Total");
static const u8 sText_MenuStat[] = _("Stat");
static const u8 sText_MenuActual[] = _("Actual");
static const u8 sText_MenuEV[] = _("EV");
static const u8 sText_MenuIV[] = _("IV");
static const u8 sText_MonLevel[]         = _("Lv.{CLEAR 1}{STR_VAR_1}");

static const u8 sText_MenuLRButtonTextMain[]   = _("Cycle Party");
static const u8 sText_MenuAButtonTextMain[]    = _("Edit Stats");
static const u8 sText_MenuBButtonTextMain[]    = _("Back");
static const u8 sText_MenuDPadButtonTextMain[] = _("Change Stat");

#define BUTTON_Y 4
static void PrintTitleToWindowMainState()
{
    FillWindowPixelBuffer(WINDOW_1, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    
    AddTextPrinterParameterized4(WINDOW_1, FONT_NORMAL, 1, 0, 0, 0, sMenuWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, sText_MenuTitle);

    BlitBitmapToWindow(WINDOW_1, sR_ButtonGfx, 75, (BUTTON_Y), 24, 8);
    AddTextPrinterParameterized4(WINDOW_1, FONT_NARROW, 102, 0, 0, 0, sMenuWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, sText_MenuLRButtonTextMain);

    BlitBitmapToWindow(WINDOW_1, sA_ButtonGfx, 160, (BUTTON_Y), 8, 8);
    AddTextPrinterParameterized4(WINDOW_1, FONT_NARROW, 172, 0, 0, 0, sMenuWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, sText_MenuAButtonTextMain);

    PutWindowTilemap(WINDOW_1);
    CopyWindowToVram(WINDOW_1, 3);
}

static void PrintTitleToWindowEditState()
{
    FillWindowPixelBuffer(WINDOW_1, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    
    AddTextPrinterParameterized4(WINDOW_1, FONT_NORMAL, 1, 0, 0, 0, sMenuWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, sText_MenuTitle);

    BlitBitmapToWindow(WINDOW_1, sDPad_ButtonGfx, 75, (BUTTON_Y), 24, 8);
    AddTextPrinterParameterized4(WINDOW_1, FONT_NARROW, 102, 0, 0, 0, sMenuWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, sText_MenuDPadButtonTextMain);

    BlitBitmapToWindow(WINDOW_1, sB_ButtonGfx, 160, (BUTTON_Y), 8, 8);
    AddTextPrinterParameterized4(WINDOW_1, FONT_NARROW, 172, 0, 0, 0, sMenuWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, sText_MenuBButtonTextMain);

    PutWindowTilemap(WINDOW_1);
    CopyWindowToVram(WINDOW_1, 3);
}

static void PrintMonStats()
{
    u8 i;
    u16 currentStat;
    u16 nature;
    u16 ability;
    u8 text[2];
    u16 level = GetMonData(ReturnPartyMon(), MON_DATA_LEVEL);
    u16 personality = GetMonData(ReturnPartyMon(), MON_DATA_PERSONALITY);
    u16 gender = GetGenderFromSpeciesAndPersonality(sStatEditorDataPtr->speciesID, personality);

    FillWindowPixelBuffer(WINDOW_2, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(WINDOW_3, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    sStatEditorDataPtr->normalTotal = 0;
    sStatEditorDataPtr->evTotal = 0;
    sStatEditorDataPtr->ivTotal = 0;

    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, 18, 7, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuStat);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, STARTING_X - 6, 7, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuActual);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, STARTING_X + SECOND_COLUMN + 4, 7, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuEV);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, STARTING_X + THIRD_COLUMN + 5, 7, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuIV);

    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, 24, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 0), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuHP);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, 12, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 1), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuAttack);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, 12, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 2), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuDefense);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, 10, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 3), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuSpAttack);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, 12, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 4), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuSpDefense);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, 16, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 5), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuSpeed);
    AddTextPrinterParameterized4(WINDOW_2, FONT_NARROW, 16, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 6), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_MenuTotal);

    // Print Mon Stats
    for(i = 0; i < 6; i++)
    {
        currentStat = GetMonData(ReturnPartyMon(), statsToPrintActual[i]);
        sStatEditorDataPtr->normalTotal += currentStat;
        DebugPrintf("Stat: %d", currentStat);
        ConvertIntToDecimalStringN(gStringVar2, currentStat, STR_CONV_MODE_RIGHT_ALIGN, 3);
        AddTextPrinterParameterized4(WINDOW_2, 1, StatPrintData[statsToPrintActual[i]].x, StatPrintData[statsToPrintActual[i]].y, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);
    }

    for(i = 0; i < 6; i++)
    {
        currentStat = GetMonData(ReturnPartyMon(), statsToPrintEVs[i]);
        sStatEditorDataPtr->evTotal += currentStat;
        DebugPrintf("Stat: %d", currentStat);
        ConvertIntToDecimalStringN(gStringVar2, currentStat, STR_CONV_MODE_RIGHT_ALIGN, 3);
        AddTextPrinterParameterized4(WINDOW_2, 1, StatPrintData[statsToPrintEVs[i]].x, StatPrintData[statsToPrintEVs[i]].y, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);
    }

    for(i = 0; i < 6; i++)
    {
        currentStat = GetMonData(ReturnPartyMon(), statsToPrintIVs[i]);
        sStatEditorDataPtr->ivTotal += currentStat;
        DebugPrintf("Stat: %d", currentStat);
        ConvertIntToDecimalStringN(gStringVar2, currentStat, STR_CONV_MODE_RIGHT_ALIGN, 3);
        AddTextPrinterParameterized4(WINDOW_2, 1, StatPrintData[statsToPrintIVs[i]].x, StatPrintData[statsToPrintIVs[i]].y, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);
    }

    // Calc Totals
    ConvertIntToDecimalStringN(gStringVar2, sStatEditorDataPtr->normalTotal, STR_CONV_MODE_RIGHT_ALIGN, 4);
    AddTextPrinterParameterized4(WINDOW_2, 1, STARTING_X - 6, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 6), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);

    ConvertIntToDecimalStringN(gStringVar2, sStatEditorDataPtr->evTotal, STR_CONV_MODE_RIGHT_ALIGN, 3);
    AddTextPrinterParameterized4(WINDOW_2, 1, STARTING_X + SECOND_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 6), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);

    ConvertIntToDecimalStringN(gStringVar2, sStatEditorDataPtr->ivTotal, STR_CONV_MODE_RIGHT_ALIGN, 3);
    AddTextPrinterParameterized4(WINDOW_2, 1, STARTING_X + THIRD_COLUMN, STARTING_Y + (DISTANCE_BETWEEN_STATS_Y * 6), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);


    // Print ability / nature / name / level / gender

#ifdef POKEMON_EXPANSION
    StringCopy(gStringVar2, GetSpeciesName(sStatEditorDataPtr->speciesID));
#else
    StringCopy(gStringVar2, gSpeciesNames[sStatEditorDataPtr->speciesID]);
#endif

    AddTextPrinterParameterized4(WINDOW_3, FONT_NARROW, 4, 2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);

    ConvertIntToDecimalStringN(gStringVar1, level, STR_CONV_MODE_RIGHT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar2, sText_MonLevel);
    AddTextPrinterParameterized4(WINDOW_3, FONT_SMALL_NARROW, 4, 18, 0, 0, sMenuWindowFontColors[FONT_WHITE], TEXT_SKIP_DRAW, gStringVar2);

    StringCopy(text, gText_MaleSymbol);
    if (gender != MON_GENDERLESS)
    {
        if (gender == MON_FEMALE)
            StringCopy(text, gText_FemaleSymbol);
        else
            StringCopy(text, gText_MaleSymbol);
        AddTextPrinterParameterized4(WINDOW_3, FONT_NORMAL, 41 + 8, 19, 0, 0, sGenderColors[(gender == MON_FEMALE)], TEXT_SKIP_DRAW, text);
    }

    nature  = GetNature(ReturnPartyMon());
    ability = GetMonAbility(ReturnPartyMon());
    StringCopy(gStringVar2, gNaturesInfo[nature].name);
    AddTextPrinterParameterized4(WINDOW_3, FONT_SMALL_NARROW, 4, 50, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);

    StringCopy(gStringVar2, gAbilitiesInfo[ability].name);
    AddTextPrinterParameterized4(WINDOW_3, FONT_SMALL_NARROW, 4, 34, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar2);

    PutWindowTilemap(WINDOW_3);
    CopyWindowToVram(WINDOW_3, 3);

    PutWindowTilemap(WINDOW_2);
    CopyWindowToVram(WINDOW_2, 3);
}

struct SpriteCordsStruct {
    u8 x;
    u8 y;
};

static void SelectorCallback(struct Sprite *sprite)
{
    struct SpriteCordsStruct spriteCords[6][2] = {
        {{188, 30 + 20}, {220, 30 + 20}},
        {{188, 46 + 20}, {220, 46 + 20}},
        {{188, 62 + 20}, {220, 62 + 20}},
        {{188, 78 + 20}, {220, 78 + 20}},
        {{188, 94 + 20}, {220, 94 + 20}},
        {{188, 110 + 20}, {220, 110 + 20}}, // Thanks Jaizu
    };

    if(sStatEditorDataPtr->inputMode == INPUT_EDIT_STAT)
    {
        if(sprite->data[0] == 32)
        {
            sprite->invisible = TRUE;
        }
        if(sprite->data[0] >= 48)
        {
            sprite->invisible = FALSE;
            sprite->data[0] = 0;
        }
        sprite->data[0]++;
    }
    else
    {
        sprite->invisible = FALSE;
        sprite->data[0] = 0;
    }

    sStatEditorDataPtr->selectedStat = sStatEditorDataPtr->selector_x + (sStatEditorDataPtr->selector_y * 2);

    sprite->x = spriteCords[sStatEditorDataPtr->selector_y][sStatEditorDataPtr->selector_x].x;
    sprite->y = spriteCords[sStatEditorDataPtr->selector_y][sStatEditorDataPtr->selector_x].y;

    DebugPrintf("%d", sStatEditorDataPtr->selectedStat);
}

static const u16 selectedStatToStatEnum[] = {
        MON_DATA_HP_EV, MON_DATA_HP_IV, MON_DATA_ATK_EV, MON_DATA_ATK_IV, MON_DATA_DEF_EV, MON_DATA_DEF_IV,
        MON_DATA_SPATK_EV, MON_DATA_SPATK_IV, MON_DATA_SPDEF_EV, MON_DATA_SPDEF_IV, MON_DATA_SPEED_EV, MON_DATA_SPEED_IV,
};

static void Task_DelayedSpriteLoad(u8 taskId) // wait 4 frames after changing the mon you're editing so there are no palette problems
{   
    if (gTasks[taskId].data[11] >= 4)
    {
        SampleUi_DrawMonIcon(sStatEditorDataPtr->speciesID);
        PrintMonStats();
        gTasks[taskId].func = Task_StatEditorMain;
        return;
    }
    else
    {
        gTasks[taskId].data[11]++;
    }
}

static void ReloadNewPokemon(u8 taskId)
{
    gSprites[sStatEditorDataPtr->monIconSpriteId].invisible = TRUE;
    FreeResourcesAndDestroySprite(&gSprites[sStatEditorDataPtr->monIconSpriteId], sStatEditorDataPtr->monIconSpriteId);
    sStatEditorDataPtr->speciesID = GetMonData(ReturnPartyMon(), MON_DATA_SPECIES);
    gTasks[taskId].func = Task_DelayedSpriteLoad;
    gTasks[taskId].data[11] = 0;
}

static void Task_StatEditorMain(u8 taskId) // input control when first loaded into menu
{
    if (JOY_NEW(A_BUTTON))
    {
        sStatEditorDataPtr->editingStat = GetMonData(ReturnPartyMon(), selectedStatToStatEnum[sStatEditorDataPtr->selectedStat]);
        StartSpriteAnim(&gSprites[sStatEditorDataPtr->selectorSpriteId], 3);
        PlaySE(SE_SELECT);
        PrintTitleToWindowEditState();
        sStatEditorDataPtr->inputMode = INPUT_EDIT_STAT;
        gTasks[taskId].func = Task_MenuEditingStat;
        if(sStatEditorDataPtr->editingStat == 0)
            StartSpriteAnim(&gSprites[sStatEditorDataPtr->selectorSpriteId], 1);
        if((sStatEditorDataPtr->editingStat == 255 || (sStatEditorDataPtr->evTotal == 510)) && (sStatEditorDataPtr->selector_x == 0))
            StartSpriteAnim(&gSprites[sStatEditorDataPtr->selectorSpriteId], 2);
        if((sStatEditorDataPtr->editingStat == 31) && (sStatEditorDataPtr->selector_x == 1))
            StartSpriteAnim(&gSprites[sStatEditorDataPtr->selectorSpriteId], 2);
        return;
    }
    if (JOY_NEW(L_BUTTON))
    {
        u16 partyid = sStatEditorDataPtr->partyid;
        if (partyid == 0)
            partyid = gPlayerPartyCount - 1;
        else
            partyid -= 1;
        sStatEditorDataPtr->partyid = partyid;
        PlaySE(SE_SELECT);
        ReloadNewPokemon(taskId);
    }
    if (JOY_NEW(R_BUTTON))
    {
        u16 partyid = sStatEditorDataPtr->partyid;
        if (partyid == gPlayerPartyCount - 1)
            partyid = 0;
        else
            partyid += 1;
        sStatEditorDataPtr->partyid = partyid;
        PlaySE(SE_SELECT);
        ReloadNewPokemon(taskId);
    }
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StatEditorTurnOff;
    }
    if (CAN_EDIT_IVS)
    {
        if (JOY_NEW(DPAD_LEFT) || JOY_NEW(DPAD_RIGHT))
        {
            if(sStatEditorDataPtr->selector_x == 0)
                sStatEditorDataPtr->selector_x = 1;
            else
                sStatEditorDataPtr->selector_x = 0; 
        }
    }
    if (JOY_NEW(DPAD_UP))
    {
        if (sStatEditorDataPtr->selector_y == 0)
            sStatEditorDataPtr->selector_y = 5;
        else
            sStatEditorDataPtr->selector_y--;
    }
    if (JOY_NEW(DPAD_DOWN))
    {
        if (sStatEditorDataPtr->selector_y == 5)
            sStatEditorDataPtr->selector_y = 0;
        else
            sStatEditorDataPtr->selector_y++;
    }

}

static void ChangeAndUpdateStat()
{
    u16 currentStatEnum = selectedStatToStatEnum[sStatEditorDataPtr->selectedStat];
    u32 currentHP = 0;
    u32 oldMaxHP = 0;
    u32 amountHPLost = 0;
    s32 tempDifference = 0;
    u32 newDifference = 0;

    if (currentStatEnum == MON_DATA_HP_EV || currentStatEnum == MON_DATA_HP_IV)
    {
        currentHP = GetMonData(ReturnPartyMon(), MON_DATA_HP);
        oldMaxHP = GetMonData(ReturnPartyMon(), MON_DATA_MAX_HP);
        amountHPLost = oldMaxHP - currentHP;
    }

    SetMonData(ReturnPartyMon(), currentStatEnum, &(sStatEditorDataPtr->editingStat));
    CalculateMonStats(ReturnPartyMon());

    if ((amountHPLost > 0) && (currentHP != 0))
    {
        tempDifference = GetMonData(ReturnPartyMon(), MON_DATA_MAX_HP) - amountHPLost;
        if (tempDifference < 0)
            tempDifference = 0;
        newDifference = (u32) tempDifference;
        if (newDifference <= 0)
            newDifference = 1;
        SetMonData(ReturnPartyMon(), MON_DATA_HP, &newDifference);
    }

    PrintMonStats();
}

#define EDIT_INPUT_INCREASE_STATE           0
#define EDIT_INPUT_MAX_INCREASE_STATE       1
#define EDIT_INPUT_DECREASE_STATE           2
#define EDIT_INPUT_MAX_DECREASE_STATE       3

#define STAT_MINIMUM          0  
#define IV_MAX_SINGLE_STAT    MAX_PER_STAT_IVS
#define EV_MAX_SINGLE_STAT    MAX_PER_STAT_EVS
#define EV_MAX_TOTAL          MAX_TOTAL_EVS
                
#define EDITING_EVS     0
#define EDITING_IVS     1

#define CHECK_IF_STAT_CANT_INCREASE (((sStatEditorDataPtr->editingStat == ((sStatEditorDataPtr->selector_x == EDITING_EVS) ? (EV_MAX_SINGLE_STAT) : (IV_MAX_SINGLE_STAT))) \
                                     || ((sStatEditorDataPtr->selector_x == EDITING_EVS) && (sStatEditorDataPtr->evTotal == EV_MAX_TOTAL))))
/*
Breakdown of CHECK_IF_STAT_CANT_INCREASE
TLDR: Stat can't increase if you're either: at the maximum amount a stat can have (for both EVs and IVs), or for EVs, if you already hit the max total of EVs

 | (sStatEditorDataPtr->editingStat == ((sStatEditorDataPtr->selector_x == EDITING_EVS) ? (EV_MAX_SINGLE_STAT) : (IV_MAX_SINGLE_STAT))
  \> This part checks if the current stat being raised is already at max, whether it's an EV or IV

 | (sStatEditorDataPtr->selector_x == EDITING_EVS)
  \> This part checks if you're currently editing an EV

 | (sStatEditorDataPtr->evTotal == EV_MAX_TOTAL)
  \> This part checks if the Pokémon already has the max amount of evs

 | ((sStatEditorDataPtr->selector_x == EDITING_EVS) && (sStatEditorDataPtr->evTotal == EV_MAX_TOTAL))
  \> Together, these two check if you're editing an EV and already at the maximum amount of EVs
*/
static void HandleEditingStatInput(u32 input)
{
    u16 iterator = 0;
    if((input <= EDIT_INPUT_MAX_INCREASE_STATE) && CHECK_IF_STAT_CANT_INCREASE)
    {
        StartSpriteAnim(&gSprites[sStatEditorDataPtr->selectorSpriteId], 2);
        return;
    }

    if((input >= EDIT_INPUT_DECREASE_STATE) && (sStatEditorDataPtr->editingStat == STAT_MINIMUM))
    {
        StartSpriteAnim(&gSprites[sStatEditorDataPtr->selectorSpriteId], 1);
        return;
    }

    #define INCREASE_DECREASE_AMOUNT 1

    switch(input)
    {
        case EDIT_INPUT_DECREASE_STATE:
            for (iterator = 0; iterator < INCREASE_DECREASE_AMOUNT; iterator++)
            {
                if(!(sStatEditorDataPtr->editingStat == STAT_MINIMUM))
                    sStatEditorDataPtr->editingStat--;
                else
                    break;
            }
            break;
       case EDIT_INPUT_MAX_DECREASE_STATE:
            sStatEditorDataPtr->editingStat = STAT_MINIMUM;
            break;
        case EDIT_INPUT_INCREASE_STATE:
            for (iterator = 0; iterator < INCREASE_DECREASE_AMOUNT; iterator++)
            {
                if(!CHECK_IF_STAT_CANT_INCREASE)
                    sStatEditorDataPtr->editingStat++;
                else
                    break;
            }
            break;
        case EDIT_INPUT_MAX_INCREASE_STATE:
            if((sStatEditorDataPtr->selector_x == EDITING_EVS))
            {
                if (EV_MAX_TOTAL - sStatEditorDataPtr->evTotal < EV_MAX_SINGLE_STAT)
                    sStatEditorDataPtr->editingStat += EV_MAX_TOTAL - sStatEditorDataPtr->evTotal;
                else
                    sStatEditorDataPtr->editingStat = EV_MAX_SINGLE_STAT;
                if(sStatEditorDataPtr->editingStat > EV_MAX_SINGLE_STAT)
                    sStatEditorDataPtr->editingStat = EV_MAX_SINGLE_STAT;
            }
            else
            {
                sStatEditorDataPtr->editingStat = IV_MAX_SINGLE_STAT;
            }
    }

    ChangeAndUpdateStat();

    if(CHECK_IF_STAT_CANT_INCREASE)
        StartSpriteAnim(&gSprites[sStatEditorDataPtr->selectorSpriteId], 2);
    else if(sStatEditorDataPtr->editingStat == STAT_MINIMUM)
        StartSpriteAnim(&gSprites[sStatEditorDataPtr->selectorSpriteId], 1); 
    else
        StartSpriteAnim(&gSprites[sStatEditorDataPtr->selectorSpriteId], 3);       
}

static void Task_MenuEditingStat(u8 taskId) // This function should be refactored to not be a hot mess
{
    if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_StatEditorMain;
        StartSpriteAnim(&gSprites[sStatEditorDataPtr->selectorSpriteId], 0);
        PlaySE(SE_SELECT);
        sStatEditorDataPtr->inputMode = INPUT_SELECT_STAT;
        PrintTitleToWindowMainState();
        return;
    }
    if (JOY_NEW(DPAD_LEFT))
        HandleEditingStatInput(EDIT_INPUT_DECREASE_STATE);
    else if (JOY_NEW(DPAD_RIGHT))
        HandleEditingStatInput(EDIT_INPUT_INCREASE_STATE);
    else if (JOY_NEW(DPAD_UP) || JOY_NEW(R_BUTTON))
        HandleEditingStatInput(EDIT_INPUT_MAX_INCREASE_STATE);
    else if (JOY_NEW(DPAD_DOWN) || JOY_NEW(L_BUTTON))
        HandleEditingStatInput(EDIT_INPUT_MAX_DECREASE_STATE);

}
