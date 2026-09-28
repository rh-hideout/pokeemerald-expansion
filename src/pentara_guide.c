#include "global.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "international_string_util.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon_icon.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "pentara_guide.h"

// Pentara Guide: a handbook of every location in the current region. For each
// place it shows the wild Pokemon (icons, levels, habitat), items and TMs, and
// the legendary Pokemon with the criteria to meet them.

struct PentaraGuideEntry
{
    u8 region;
    u16 mapsec;
    const u8 *name;
    const u16 *species;
    u8 minLevel;
    u8 maxLevel;
    const u8 *habitat;
    const u8 *items;
    const u8 *legends;
};

#include "data/pentara_guide.h"

enum
{
    WIN_HEADER,
    WIN_TABS,
    WIN_LIST,
    WIN_BODY,
    WIN_FOOTER,
};

enum
{
    TAB_POKEMON,
    TAB_ITEMS,
    TAB_LEGENDS,
    TAB_COUNT
};

#define LIST_ROWS       7
#define MAX_ENTRIES     96
#define MAX_ICONS       12
#define BODY_LINES      9
#define BG1_TILE_BG     0
#define BG1_TILE_HEADER 1
#define BG1_TILE_BODY   2
#define BG1_TILE_TAB    3
#define BG1_TILE_LIST   4
#define BG1_TILE_SELECT 5

struct GuideState
{
    MainCallback exitCallback;
    u16 entries[MAX_ENTRIES];
    u8 count;
    u8 cursor;
    u8 scroll;
    u8 tab;
    u8 page;
    u8 pageCount;
    u8 iconSpriteIds[MAX_ICONS];
    u16 *bg1Tilemap;
};

static EWRAM_DATA struct GuideState *sGuide = NULL;

static void Guide_VBlankCB(void);
static void Guide_MainCB(void);
static void Guide_RunSetup(void);
static void Task_GuideWaitFadeIn(u8 taskId);
static void Task_GuideMain(u8 taskId);
static void Task_GuideFadeAndExit(u8 taskId);
static void Guide_DrawAll(void);
static void Guide_PrintPaged(const u8 *str);

static const struct BgTemplate sGuideBgTemplates[] =
{
    {.bg = 0, .charBaseIndex = 0, .mapBaseIndex = 31, .priority = 0},
    {.bg = 1, .charBaseIndex = 3, .mapBaseIndex = 30, .priority = 1},
};

static const struct WindowTemplate sGuideWindowTemplates[] =
{
    [WIN_HEADER] = {.bg = 0, .tilemapLeft = 1, .tilemapTop = 0, .width = 28, .height = 2, .paletteNum = 15, .baseBlock = 1},
    [WIN_TABS]   = {.bg = 0, .tilemapLeft = 0, .tilemapTop = 2, .width = 30, .height = 2, .paletteNum = 15, .baseBlock = 57},
    [WIN_LIST]   = {.bg = 0, .tilemapLeft = 0, .tilemapTop = 4, .width = 12, .height = 14, .paletteNum = 15, .baseBlock = 117},
    [WIN_BODY]   = {.bg = 0, .tilemapLeft = 12, .tilemapTop = 4, .width = 18, .height = 14, .paletteNum = 15, .baseBlock = 285},
    [WIN_FOOTER] = {.bg = 0, .tilemapLeft = 0, .tilemapTop = 18, .width = 30, .height = 2, .paletteNum = 15, .baseBlock = 537},
    DUMMY_WIN_TEMPLATE
};

// BG1 panel colours (palette 0) and text colours (palette 15).
static const u16 sPanelPalette[16] =
{
    RGB(3, 4, 9),     // 0 backdrop
    RGB(4, 5, 11),    // 1 page background (deep navy)
    RGB(2, 15, 17),   // 2 header / footer (teal)
    RGB(29, 30, 31),  // 3 body panel (paper white)
    RGB(31, 19, 5),   // 4 active tab (amber)
    RGB(22, 26, 30),  // 5 list panel (mist blue)
    RGB(31, 26, 12),  // 6 selected row (gold)
};

static const u16 sTextPalette[16] =
{
    RGB(0, 0, 0),     // 0 transparent
    RGB(31, 31, 31),  // 1 white
    RGB(3, 5, 10),    // 2 ink (dark navy)
    RGB(18, 20, 24),  // 3 soft shadow
    RGB(6, 9, 18),    // 4 dark shadow for white text
    RGB(31, 19, 5),   // 5 amber
    RGB(2, 15, 17),   // 6 teal
};

static const u8 sColor_White[] = {TEXT_COLOR_TRANSPARENT, 1, 4};
static const u8 sColor_Ink[] = {TEXT_COLOR_TRANSPARENT, 2, 3};
static const u8 sColor_Teal[] = {TEXT_COLOR_TRANSPARENT, 6, 3};

static const u8 sText_Title[] = _("PENTARA GUIDE");
static const u8 sText_TabPokemon[] = _("Pokémon");
static const u8 sText_TabItems[] = _("Items & TMs");
static const u8 sText_TabLegends[] = _("Legends");
static const u8 sText_Footer[] = _("{DPAD_UPDOWN} Place {L_BUTTON}{R_BUTTON} Tab {A_BUTTON} More {B_BUTTON} Close");
static const u8 sText_Page[] = _("{STR_VAR_1}/{STR_VAR_2} {A_BUTTON}");
static const u8 sText_NoWild[] = _("No wild Pokémon live here.");
static const u8 sText_Levels[] = _("Lv. {STR_VAR_1}-{STR_VAR_2}");
static const u8 sText_Caught[] = _("Caught {STR_VAR_1}/{STR_VAR_2}");
static const u8 sText_Cursor[] = _("{RIGHT_ARROW}");
static const u8 sText_Nothing[] = _("Nothing noted here yet.");

static const u8 *const sRegionNames[] =
{
    [0] = COMPOUND_STRING("PENTARA"),
    [1] = COMPOUND_STRING("ALDERMOOR"),
    [2] = COMPOUND_STRING("CORALIS"),
    [3] = COMPOUND_STRING("IRONVALE"),
    [4] = COMPOUND_STRING("SOLUNE ISLES"),
    [5] = COMPOUND_STRING("VASTARA"),
};

// ---------------------------------------------------------------- entry

void OpenPentaraGuide(void)
{
    u32 i, region = VarGet(VAR_P_REGION);

    if (region == 0 || region > 5)
        region = 1;
    sGuide = AllocZeroed(sizeof(*sGuide));
    if (sGuide == NULL)
    {
        SetMainCallback2(CB2_ReturnToField);
        return;
    }
    sGuide->exitCallback = CB2_ReturnToField;
    for (i = 0; i < ARRAY_COUNT(sPentaraGuide) && sGuide->count < MAX_ENTRIES; i++)
    {
        if (sPentaraGuide[i].region == region)
        {
            if (sPentaraGuide[i].mapsec == gMapHeader.regionMapSectionId)
                sGuide->cursor = sGuide->count;
            sGuide->entries[sGuide->count++] = i;
        }
    }
    if (sGuide->cursor >= LIST_ROWS)
        sGuide->scroll = sGuide->cursor - LIST_ROWS + 1;
    for (i = 0; i < MAX_ICONS; i++)
        sGuide->iconSpriteIds[i] = MAX_SPRITES;
    gMain.state = 0;
    SetMainCallback2(Guide_RunSetup);
}

// ---------------------------------------------------------------- setup

static void Guide_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Guide_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Guide_LoadPanelTiles(void)
{
    // Six solid-colour tiles: the whole layout is drawn from these.
    static u32 tiles[6][8];
    u32 t, r;

    for (t = 0; t < 6; t++)
        for (r = 0; r < 8; r++)
            tiles[t][r] = 0x11111111 * (t + 1);
    LoadBgTiles(1, tiles, sizeof(tiles), 0);
}

static void Guide_FillBg1(u32 left, u32 top, u32 width, u32 height, u32 tile)
{
    u32 x, y;

    for (y = top; y < top + height; y++)
        for (x = left; x < left + width; x++)
            sGuide->bg1Tilemap[y * 32 + x] = tile;
}

static void Guide_DrawPanels(void)
{
    u32 i, row;

    Guide_FillBg1(0, 0, 30, 20, BG1_TILE_BG);
    Guide_FillBg1(0, 0, 30, 2, BG1_TILE_HEADER);
    Guide_FillBg1(0, 18, 30, 2, BG1_TILE_HEADER);
    Guide_FillBg1(0, 4, 12, 14, BG1_TILE_LIST);
    Guide_FillBg1(12, 4, 18, 14, BG1_TILE_BODY);
    Guide_FillBg1(sGuide->tab * 10, 2, 10, 2, BG1_TILE_TAB);
    for (i = 0; i < LIST_ROWS; i++)
    {
        if (sGuide->scroll + i == sGuide->cursor)
        {
            row = 4 + i * 2;
            Guide_FillBg1(0, row, 12, 2, BG1_TILE_SELECT);
        }
    }
    ScheduleBgCopyTilemapToVram(1);
}

static bool8 Guide_DoSetup(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 1:
        ResetVramOamAndBgCntRegs();
        ResetAllBgsCoordinates();
        sGuide->bg1Tilemap = AllocZeroed(BG_SCREEN_SIZE);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sGuideBgTemplates, ARRAY_COUNT(sGuideBgTemplates));
        SetBgTilemapBuffer(1, sGuide->bg1Tilemap);
        InitWindows(sGuideWindowTemplates);
        DeactivateAllTextPrinters();
        gMain.state++;
        break;
    case 2:
        Guide_LoadPanelTiles();
        LoadPalette(sPanelPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        LoadPalette(sTextPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        LoadMonIconPalettes();
        gMain.state++;
        break;
    case 3:
        Guide_DrawAll();
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 4:
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        taskId = CreateTask(Task_GuideWaitFadeIn, 0);
        (void)taskId;
        SetVBlankCallback(Guide_VBlankCB);
        SetMainCallback2(Guide_MainCB);
        return TRUE;
    }
    return FALSE;
}

static void Guide_RunSetup(void)
{
    while (!Guide_DoSetup()) {}
}

// ---------------------------------------------------------------- drawing

static const struct PentaraGuideEntry *Guide_Current(void)
{
    if (sGuide->count == 0)
        return NULL;
    return &sPentaraGuide[sGuide->entries[sGuide->cursor]];
}

static void Guide_DestroyIcons(void)
{
    u32 i;

    for (i = 0; i < MAX_ICONS; i++)
    {
        if (sGuide->iconSpriteIds[i] != MAX_SPRITES)
        {
            FreeAndDestroyMonIconSprite(&gSprites[sGuide->iconSpriteIds[i]]);
            sGuide->iconSpriteIds[i] = MAX_SPRITES;
        }
    }
}

static void Guide_DrawHeader(void)
{
    u32 region = VarGet(VAR_P_REGION);

    if (region > 5)
        region = 0;
    FillWindowPixelBuffer(WIN_HEADER, PIXEL_FILL(0));
    AddTextPrinterParameterized3(WIN_HEADER, FONT_NORMAL, 2, 1, sColor_White, TEXT_SKIP_DRAW, sText_Title);
    AddTextPrinterParameterized3(WIN_HEADER, FONT_NORMAL,
                                 GetStringRightAlignXOffset(FONT_NORMAL, sRegionNames[region], 28 * 8) - 4, 1,
                                 sColor_White, TEXT_SKIP_DRAW, sRegionNames[region]);
    PutWindowTilemap(WIN_HEADER);
    CopyWindowToVram(WIN_HEADER, COPYWIN_FULL);

    FillWindowPixelBuffer(WIN_TABS, PIXEL_FILL(0));
    AddTextPrinterParameterized3(WIN_TABS, FONT_NORMAL, 12, 1, sColor_White, TEXT_SKIP_DRAW, sText_TabPokemon);
    AddTextPrinterParameterized3(WIN_TABS, FONT_NORMAL, 84, 1, sColor_White, TEXT_SKIP_DRAW, sText_TabItems);
    AddTextPrinterParameterized3(WIN_TABS, FONT_NORMAL, 172, 1, sColor_White, TEXT_SKIP_DRAW, sText_TabLegends);
    PutWindowTilemap(WIN_TABS);
    CopyWindowToVram(WIN_TABS, COPYWIN_FULL);

    FillWindowPixelBuffer(WIN_FOOTER, PIXEL_FILL(0));
    AddTextPrinterParameterized3(WIN_FOOTER, FONT_SMALL, 4, 2, sColor_White, TEXT_SKIP_DRAW, sText_Footer);
    PutWindowTilemap(WIN_FOOTER);
    CopyWindowToVram(WIN_FOOTER, COPYWIN_FULL);
}

static void Guide_DrawList(void)
{
    u32 i;

    FillWindowPixelBuffer(WIN_LIST, PIXEL_FILL(0));
    for (i = 0; i < LIST_ROWS && sGuide->scroll + i < sGuide->count; i++)
    {
        const struct PentaraGuideEntry *e = &sPentaraGuide[sGuide->entries[sGuide->scroll + i]];
        if (sGuide->scroll + i == sGuide->cursor)
            AddTextPrinterParameterized3(WIN_LIST, FONT_NARROW, 1, i * 16 + 1, sColor_Ink, TEXT_SKIP_DRAW, sText_Cursor);
        AddTextPrinterParameterized3(WIN_LIST, FONT_NARROW, 9, i * 16 + 1, sColor_Ink, TEXT_SKIP_DRAW, e->name);
    }
    PutWindowTilemap(WIN_LIST);
    CopyWindowToVram(WIN_LIST, COPYWIN_FULL);
}

static void Guide_DrawBody(void)
{
    const struct PentaraGuideEntry *e = Guide_Current();
    u32 i, n = 0, caught = 0;

    Guide_DestroyIcons();
    sGuide->pageCount = 1;
    FillWindowPixelBuffer(WIN_BODY, PIXEL_FILL(0));
    if (e == NULL)
    {
        PutWindowTilemap(WIN_BODY);
        CopyWindowToVram(WIN_BODY, COPYWIN_FULL);
        return;
    }
    switch (sGuide->tab)
    {
    case TAB_POKEMON:
        for (i = 0; e->species[i] != SPECIES_NONE; i++)
        {
            if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(e->species[i]), FLAG_GET_CAUGHT))
                caught++;
            n++;
        }
        sGuide->pageCount = (n + MAX_ICONS - 1) / MAX_ICONS;
        if (sGuide->page >= sGuide->pageCount)
            sGuide->page = 0;
        for (i = 0; i < MAX_ICONS && sGuide->page * MAX_ICONS + i < n; i++)
        {
            sGuide->iconSpriteIds[i] = CreateMonIcon(e->species[sGuide->page * MAX_ICONS + i], SpriteCallbackDummy,
                                                     96 + 22 + (i % 4) * 34, 32 + 18 + (i / 4) * 28, 0, 0);
        }
        if (n == 0)
        {
            AddTextPrinterParameterized3(WIN_BODY, FONT_SMALL, 4, 4, sColor_Ink, TEXT_SKIP_DRAW, sText_NoWild);
            break;
        }
        ConvertIntToDecimalStringN(gStringVar1, e->minLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar2, e->maxLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringExpandPlaceholders(gStringVar4, sText_Levels);
        AddTextPrinterParameterized3(WIN_BODY, FONT_SMALL, 4, 88, sColor_Teal, TEXT_SKIP_DRAW, gStringVar4);
        AddTextPrinterParameterized3(WIN_BODY, FONT_SMALL, 60, 88, sColor_Ink, TEXT_SKIP_DRAW, e->habitat);
        ConvertIntToDecimalStringN(gStringVar1, caught, STR_CONV_MODE_LEFT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar2, n, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringExpandPlaceholders(gStringVar4, sText_Caught);
        AddTextPrinterParameterized3(WIN_BODY, FONT_SMALL, 4, 100, sColor_Ink, TEXT_SKIP_DRAW, gStringVar4);
        break;
    case TAB_ITEMS:
        Guide_PrintPaged(e->items != NULL ? e->items : sText_Nothing);
        break;
    case TAB_LEGENDS:
        Guide_PrintPaged(e->legends != NULL ? e->legends : sText_Nothing);
        break;
    }
    if (sGuide->pageCount > 1)
    {
        ConvertIntToDecimalStringN(gStringVar1, sGuide->page + 1, STR_CONV_MODE_LEFT_ALIGN, 2);
        ConvertIntToDecimalStringN(gStringVar2, sGuide->pageCount, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringExpandPlaceholders(gStringVar4, sText_Page);
        AddTextPrinterParameterized3(WIN_BODY, FONT_SMALL, 18 * 8 - 44, 100, sColor_Teal, TEXT_SKIP_DRAW, gStringVar4);
    }
    PutWindowTilemap(WIN_BODY);
    CopyWindowToVram(WIN_BODY, COPYWIN_FULL);
}

// Prints BODY_LINES lines of a multi-line string, starting at the current page.
static void Guide_PrintPaged(const u8 *str)
{
    u32 line = 0, lines = 1, start = sGuide->page * BODY_LINES, j = 0;
    const u8 *p;

    for (p = str; *p != EOS; p++)
        if (*p == CHAR_NEWLINE)
            lines++;
    sGuide->pageCount = (lines + BODY_LINES - 1) / BODY_LINES;
    if (sGuide->page >= sGuide->pageCount)
    {
        sGuide->page = 0;
        start = 0;
    }
    for (p = str; *p != EOS && line < start + BODY_LINES; p++)
    {
        if (*p == CHAR_NEWLINE)
        {
            line++;
            if (line == start || line >= start + BODY_LINES)
                continue;
        }
        if (line >= start)
            gStringVar4[j++] = *p;
    }
    gStringVar4[j] = EOS;
    AddTextPrinterParameterized3(WIN_BODY, FONT_SMALL, 4, 2, sColor_Ink, TEXT_SKIP_DRAW, gStringVar4);
}

static void Guide_DrawAll(void)
{
    Guide_DrawPanels();
    Guide_DrawHeader();
    Guide_DrawList();
    Guide_DrawBody();
}

// ---------------------------------------------------------------- input

static void Task_GuideWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_GuideMain;
}

static void Guide_MoveCursor(s32 delta)
{
    if (sGuide->count == 0)
        return;
    sGuide->cursor = (sGuide->cursor + sGuide->count + delta) % sGuide->count;
    sGuide->page = 0;
    if (sGuide->cursor < sGuide->scroll)
        sGuide->scroll = sGuide->cursor;
    else if (sGuide->cursor >= sGuide->scroll + LIST_ROWS)
        sGuide->scroll = sGuide->cursor - LIST_ROWS + 1;
    PlaySE(SE_SELECT);
    Guide_DrawPanels();
    Guide_DrawList();
    Guide_DrawBody();
}

static void Guide_SwitchTab(s32 delta)
{
    sGuide->tab = (sGuide->tab + TAB_COUNT + delta) % TAB_COUNT;
    sGuide->page = 0;
    PlaySE(SE_SELECT);
    Guide_DrawPanels();
    Guide_DrawBody();
}

static void Task_GuideMain(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_GuideFadeAndExit;
    }
    else if (JOY_NEW(A_BUTTON) && sGuide->pageCount > 1)
    {
        sGuide->page = (sGuide->page + 1) % sGuide->pageCount;
        PlaySE(SE_SELECT);
        Guide_DrawBody();
    }
    else if (JOY_REPEAT(DPAD_UP))
        Guide_MoveCursor(-1);
    else if (JOY_REPEAT(DPAD_DOWN))
        Guide_MoveCursor(1);
    else if (JOY_NEW(L_BUTTON) || JOY_NEW(DPAD_LEFT))
        Guide_SwitchTab(-1);
    else if (JOY_NEW(R_BUTTON) || JOY_NEW(DPAD_RIGHT))
        Guide_SwitchTab(1);
}

static void Task_GuideFadeAndExit(u8 taskId)
{
    if (gPaletteFade.active)
        return;
    SetMainCallback2(sGuide->exitCallback);
    Guide_DestroyIcons();
    FreeMonIconPalettes();
    Free(sGuide->bg1Tilemap);
    FreeAllWindowBuffers();
    FREE_AND_SET_NULL(sGuide);
    DestroyTask(taskId);
}
