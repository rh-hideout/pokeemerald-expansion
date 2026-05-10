#include "global.h"
#include "bg.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "overworld.h"
#include "script.h"
#include "challenge_menu.h"

// Pokemon HeartGold/SoulSilver uses this file name pattern from HnS.
// However, this is a clean rewrite using expansion's ListMenu infrastructure.

// =============================================================================
// Submenu (tab) definitions
// =============================================================================

enum {
    TAB_MODE,
    TAB_FEATURES,
    TAB_RANDOMIZER,
    TAB_NUZLOCKE,
    TAB_DIFFICULTY,
    TAB_CHALLENGES,
    TAB_COUNT,
};

// =============================================================================
// Per-tab item enums — placeholder items for skeleton testing
// =============================================================================

enum {
    ITEM_MODE_PLACEHOLDER_1,
    ITEM_MODE_PLACEHOLDER_2,
    ITEM_MODE_PLACEHOLDER_3,
    ITEM_MODE_COUNT,
};

enum {
    ITEM_FEATURES_PLACEHOLDER_1,
    ITEM_FEATURES_PLACEHOLDER_2,
    ITEM_FEATURES_COUNT,
};

enum {
    ITEM_RANDOM_PLACEHOLDER_1,
    ITEM_RANDOM_PLACEHOLDER_2,
    ITEM_RANDOM_COUNT,
};

enum {
    ITEM_NUZLOCKE_PLACEHOLDER_1,
    ITEM_NUZLOCKE_PLACEHOLDER_2,
    ITEM_NUZLOCKE_COUNT,
};

enum {
    ITEM_DIFFICULTY_PLACEHOLDER_1,
    ITEM_DIFFICULTY_PLACEHOLDER_2,
    ITEM_DIFFICULTY_COUNT,
};

enum {
    ITEM_CHALLENGES_PLACEHOLDER_1,
    ITEM_CHALLENGES_PLACEHOLDER_2,
    ITEM_CHALLENGES_SAVE,
    ITEM_CHALLENGES_COUNT,
};

// Maximum items in any single tab
#define MAX_ITEMS_PER_TAB 16
#define ITEMS_VISIBLE 5
#define Y_DIFF 16

// =============================================================================
// Menu item descriptor — one per option row
// =============================================================================

struct ChallengeMenuItem
{
    const u8 *name;
    const u8 *description;
    u8 numChoices;
    const u8 *const *choiceNames;
};

// =============================================================================
// EWRAM state
// =============================================================================

struct ChallengeMenuState
{
    u8 currentTab;
    u8 listTaskId;
    u8 arrowTaskId;
    u16 scrollOffset[TAB_COUNT];
    u16 selectedRow[TAB_COUNT];
    u8 selections[TAB_COUNT * MAX_ITEMS_PER_TAB];
};

static EWRAM_DATA struct ChallengeMenuState *sMenu = NULL;

// =============================================================================
// Window / BG templates
// =============================================================================

enum {
    WIN_TOPBAR,
    WIN_OPTIONS,
    WIN_DESCRIPTION,
};

static const struct WindowTemplate sWinTemplates[] = {
    [WIN_TOPBAR] = {
        .bg = 1,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2,
    },
    [WIN_OPTIONS] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 26,
        .height = 10,
        .paletteNum = 1,
        .baseBlock = 62,
    },
    [WIN_DESCRIPTION] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 1,
        .baseBlock = 500,
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct BgTemplate sBgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
};

static const u16 sBgPal[] = {RGB(17, 18, 31)};
static const u16 sTextPal[] = INCBIN_U16("graphics/interface/option_menu_text_custom.gbapal");

// Frame tile IDs — loaded from window frame tileset at base 0x1A2
#define TILE_TOP_CORNER_L 0x1A2
#define TILE_TOP_EDGE     0x1A3
#define TILE_TOP_CORNER_R 0x1A4
#define TILE_LEFT_EDGE    0x1A5
#define TILE_RIGHT_EDGE   0x1A7
#define TILE_BOT_CORNER_L 0x1A8
#define TILE_BOT_EDGE     0x1A9
#define TILE_BOT_CORNER_R 0x1AA

// Text color arrays for AddTextPrinterParameterized3/4
#define TEXT_COLOR_OPTIONS_WHITE              1
#define TEXT_COLOR_OPTIONS_GRAY_FG            2
#define TEXT_COLOR_OPTIONS_GRAY_SHADOW        3
#define TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG      4
#define TEXT_COLOR_OPTIONS_ORANGE_FG          5
#define TEXT_COLOR_OPTIONS_ORANGE_SHADOW      6
#define TEXT_COLOR_OPTIONS_RED_FG             7
#define TEXT_COLOR_OPTIONS_RED_SHADOW         8
#define TEXT_COLOR_OPTIONS_GREEN_FG           9
#define TEXT_COLOR_OPTIONS_GREEN_SHADOW      10
#define TEXT_COLOR_OPTIONS_GREEN_DARK_FG     11
#define TEXT_COLOR_OPTIONS_GREEN_DARK_SHADOW 12
#define TEXT_COLOR_OPTIONS_RED_DARK_FG       13
#define TEXT_COLOR_OPTIONS_RED_DARK_SHADOW   14

// =============================================================================
// Placeholder choice strings
// =============================================================================

static const u8 *const sChoices_OffOn[] = {
    COMPOUND_STRING("OFF"),
    COMPOUND_STRING("ON"),
};

static const u8 *const sChoices_Three[] = {
    COMPOUND_STRING("OFF"),
    COMPOUND_STRING("NORMAL"),
    COMPOUND_STRING("HARD"),
};

static const u8 *const sChoices_Four[] = {
    COMPOUND_STRING("OFF"),
    COMPOUND_STRING("EASY"),
    COMPOUND_STRING("NORMAL"),
    COMPOUND_STRING("HARD"),
};

static const u8 sText_TopBar_Left[]  = _("{L_BUTTON}PREVIOUS");
static const u8 sText_TopBar_Right[] = _("{R_BUTTON}NEXT");

// =============================================================================
// Tab item tables — skeleton placeholders
// =============================================================================

static const struct ChallengeMenuItem sTabItems_Mode[] = {
    [ITEM_MODE_PLACEHOLDER_1] = {
        .name        = COMPOUND_STRING("MODE OPTION 1"),
        .description = COMPOUND_STRING("First mode option."),
        .numChoices  = 2,
        .choiceNames = sChoices_OffOn,
    },
    [ITEM_MODE_PLACEHOLDER_2] = {
        .name        = COMPOUND_STRING("MODE OPTION 2"),
        .description = COMPOUND_STRING("Three choices test."),
        .numChoices  = 3,
        .choiceNames = sChoices_Three,
    },
    [ITEM_MODE_PLACEHOLDER_3] = {
        .name        = COMPOUND_STRING("MODE OPTION 3"),
        .description = COMPOUND_STRING("Four choices test."),
        .numChoices  = 4,
        .choiceNames = sChoices_Four,
    },
};

static const struct ChallengeMenuItem sTabItems_Features[] = {
    [ITEM_FEATURES_PLACEHOLDER_1] = {
        .name        = COMPOUND_STRING("FEATURE 1"),
        .description = COMPOUND_STRING("First feature."),
        .numChoices  = 2,
        .choiceNames = sChoices_OffOn,
    },
    [ITEM_FEATURES_PLACEHOLDER_2] = {
        .name        = COMPOUND_STRING("FEATURE 2"),
        .description = COMPOUND_STRING("Second feature."),
        .numChoices  = 2,
        .choiceNames = sChoices_OffOn,
    },
};

static const struct ChallengeMenuItem sTabItems_Randomizer[] = {
    [ITEM_RANDOM_PLACEHOLDER_1] = {
        .name        = COMPOUND_STRING("RANDOM OPT 1"),
        .description = COMPOUND_STRING("First randomizer option."),
        .numChoices  = 2,
        .choiceNames = sChoices_OffOn,
    },
    [ITEM_RANDOM_PLACEHOLDER_2] = {
        .name        = COMPOUND_STRING("RANDOM OPT 2"),
        .description = COMPOUND_STRING("Second randomizer option."),
        .numChoices  = 2,
        .choiceNames = sChoices_OffOn,
    },
};

static const struct ChallengeMenuItem sTabItems_Nuzlocke[] = {
    [ITEM_NUZLOCKE_PLACEHOLDER_1] = {
        .name        = COMPOUND_STRING("NUZLOCKE OPT 1"),
        .description = COMPOUND_STRING("First nuzlocke option."),
        .numChoices  = 2,
        .choiceNames = sChoices_OffOn,
    },
    [ITEM_NUZLOCKE_PLACEHOLDER_2] = {
        .name        = COMPOUND_STRING("NUZLOCKE OPT 2"),
        .description = COMPOUND_STRING("Second nuzlocke option."),
        .numChoices  = 2,
        .choiceNames = sChoices_OffOn,
    },
};

static const struct ChallengeMenuItem sTabItems_Difficulty[] = {
    [ITEM_DIFFICULTY_PLACEHOLDER_1] = {
        .name        = COMPOUND_STRING("DIFFICULTY 1"),
        .description = COMPOUND_STRING("First difficulty option."),
        .numChoices  = 2,
        .choiceNames = sChoices_OffOn,
    },
    [ITEM_DIFFICULTY_PLACEHOLDER_2] = {
        .name        = COMPOUND_STRING("DIFFICULTY 2"),
        .description = COMPOUND_STRING("Second difficulty option."),
        .numChoices  = 2,
        .choiceNames = sChoices_OffOn,
    },
};

static const struct ChallengeMenuItem sTabItems_Challenges[] = {
    [ITEM_CHALLENGES_PLACEHOLDER_1] = {
        .name        = COMPOUND_STRING("CHALLENGE 1"),
        .description = COMPOUND_STRING("First challenge option."),
        .numChoices  = 2,
        .choiceNames = sChoices_OffOn,
    },
    [ITEM_CHALLENGES_PLACEHOLDER_2] = {
        .name        = COMPOUND_STRING("CHALLENGE 2"),
        .description = COMPOUND_STRING("Second challenge option."),
        .numChoices  = 2,
        .choiceNames = sChoices_OffOn,
    },
    [ITEM_CHALLENGES_SAVE] = {
        .name        = COMPOUND_STRING("SAVE & EXIT"),
        .description = COMPOUND_STRING("Save settings and exit."),
        .numChoices  = 0,
        .choiceNames = NULL,
    },
};

// =============================================================================
// Per-tab metadata
// =============================================================================

struct TabDef
{
    const u8 *tabName;
    const struct ChallengeMenuItem *items;
    u8 count;
};

static const struct TabDef sTabs[TAB_COUNT] = {
    [TAB_MODE]       = { COMPOUND_STRING("MODE"),       sTabItems_Mode,       ITEM_MODE_COUNT },
    [TAB_FEATURES]   = { COMPOUND_STRING("FEATURES"),   sTabItems_Features,   ITEM_FEATURES_COUNT },
    [TAB_RANDOMIZER] = { COMPOUND_STRING("RANDOMIZER"), sTabItems_Randomizer, ITEM_RANDOM_COUNT },
    [TAB_NUZLOCKE]   = { COMPOUND_STRING("NUZLOCKE"),   sTabItems_Nuzlocke,   ITEM_NUZLOCKE_COUNT },
    [TAB_DIFFICULTY] = { COMPOUND_STRING("DIFFICULTY"),  sTabItems_Difficulty, ITEM_DIFFICULTY_COUNT },
    [TAB_CHALLENGES] = { COMPOUND_STRING("CHALLENGES"), sTabItems_Challenges, ITEM_CHALLENGES_COUNT },
};

// =============================================================================
// Forward declarations
// =============================================================================

static void MainCB2(void);
static void VBlankCB(void);
static void Task_FadeIn(u8 taskId);
static void Task_ProcessInput(u8 taskId);
static void Task_Save(u8 taskId);
static void Task_FadeOut(u8 taskId);
static void InitListMenu(void);
static void DestroyCurrentListMenu(void);
static void DrawTopBar(void);
static void DrawDescription(void);
static void DrawBgFrames(void);
static void ChallengeMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static void ChallengeMenu_ItemPrintFunc(u8 windowId, u32 itemId, u8 y);

static u8 *GetSelectionPtr(u8 tab, u8 itemIndex);

// Temporary ListMenuItem storage for building the list each tab switch
static EWRAM_DATA struct ListMenuItem sListItems[MAX_ITEMS_PER_TAB] = {0};

// =============================================================================
// Helpers
// =============================================================================

static u8 *GetSelectionPtr(u8 tab, u8 itemIndex)
{
    return &sMenu->selections[tab * MAX_ITEMS_PER_TAB + itemIndex];
}

static u8 GetCurrentTabItemCount(void)
{
    return sTabs[sMenu->currentTab].count;
}

static const struct ChallengeMenuItem *GetCurrentTabItems(void)
{
    return sTabs[sMenu->currentTab].items;
}

// =============================================================================
// Callbacks
// =============================================================================

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

// =============================================================================
// Row highlight (hardware window darkening band)
// =============================================================================

static void HighlightRow(void)
{
    u16 scrollOffset, selectedRow;
    ListMenuGetScrollAndRow(sMenu->listTaskId, &scrollOffset, &selectedRow);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(Y_DIFF, 224));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(selectedRow * Y_DIFF + 24, selectedRow * Y_DIFF + 40));
}

// =============================================================================
// Right-side choice drawing
// =============================================================================

static void DrawRightSideChoiceText(const u8 *text, int x, int y, bool8 chosen, bool8 active)
{
    u8 color[3];
    color[0] = TEXT_COLOR_TRANSPARENT;
    if (active)
    {
        color[1] = chosen ? TEXT_COLOR_OPTIONS_RED_FG : TEXT_COLOR_OPTIONS_GRAY_FG;
        color[2] = chosen ? TEXT_COLOR_OPTIONS_RED_SHADOW : TEXT_COLOR_OPTIONS_GRAY_SHADOW;
    }
    else
    {
        color[1] = chosen ? TEXT_COLOR_OPTIONS_RED_DARK_FG : TEXT_COLOR_OPTIONS_GRAY_LIGHT_FG;
        color[2] = chosen ? TEXT_COLOR_OPTIONS_RED_DARK_SHADOW : TEXT_COLOR_OPTIONS_GRAY_SHADOW;
    }
    AddTextPrinterParameterized4(WIN_OPTIONS, FONT_NORMAL, x, y, 0, 0, color, TEXT_SKIP_DRAW, text);
}

static int GetMiddleX(const u8 *txt1, const u8 *txt2, const u8 *txt3)
{
    int widthLeft = GetStringWidth(FONT_NORMAL, txt1, 0);
    int widthMid = GetStringWidth(FONT_NORMAL, txt2, 0);
    int widthRight = GetStringWidth(FONT_NORMAL, txt3, 0);
    widthMid -= (198 - 104);
    return (widthLeft - widthMid - widthRight) / 2 + 104;
}

static void DrawChoices_Two(const u8 *const *strings, int selection, int y, bool8 active)
{
    DrawRightSideChoiceText(strings[0], 104, y + 1, selection == 0, active);
    DrawRightSideChoiceText(strings[1], GetStringRightAlignXOffset(FONT_NORMAL, strings[1], 198), y + 1, selection == 1, active);
}

static void DrawChoices_Three(const u8 *const *strings, int selection, int y, bool8 active)
{
    static const u8 orders[][2] = { {0, 1}, {1, 2}, {1, 2} };
    const u8 *order = orders[selection];
    DrawRightSideChoiceText(strings[order[0]], 104, y + 1, selection == order[0], active);
    DrawRightSideChoiceText(strings[order[1]], GetStringRightAlignXOffset(FONT_NORMAL, strings[order[1]], 198), y + 1, selection == order[1], active);
}

static void DrawChoices_Four(const u8 *const *strings, int selection, int y, bool8 active)
{
    static const u8 orders[][3] = { {0, 1, 2}, {0, 1, 2}, {1, 2, 3}, {1, 2, 3} };
    const u8 *order = orders[selection];
    int xMid = GetMiddleX(strings[order[0]], strings[order[1]], strings[order[2]]);
    DrawRightSideChoiceText(strings[order[0]], 104, y + 1, selection == order[0], active);
    DrawRightSideChoiceText(strings[order[1]], xMid, y + 1, selection == order[1], active);
    DrawRightSideChoiceText(strings[order[2]], GetStringRightAlignXOffset(FONT_NORMAL, strings[order[2]], 198), y + 1, selection == order[2], active);
}

static void DrawChoices_Five(const u8 *const *strings, int selection, int y, bool8 active)
{
    static const u8 orders[][3] = { {0, 1, 2}, {0, 1, 2}, {1, 2, 3}, {2, 3, 4}, {2, 3, 4} };
    const u8 *order = orders[selection];
    int xMid = GetMiddleX(strings[order[0]], strings[order[1]], strings[order[2]]);
    DrawRightSideChoiceText(strings[order[0]], 104, y + 1, selection == order[0], active);
    DrawRightSideChoiceText(strings[order[1]], xMid, y + 1, selection == order[1], active);
    DrawRightSideChoiceText(strings[order[2]], GetStringRightAlignXOffset(FONT_NORMAL, strings[order[2]], 198), y + 1, selection == order[2], active);
}

// =============================================================================
// ListMenu callbacks
// =============================================================================

static void ChallengeMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (!onInit)
        PlaySE(SE_SELECT);

    HighlightRow();
    DrawDescription();
}

static void ChallengeMenu_ItemPrintFunc(u8 windowId, u32 itemId, u8 y)
{
    const struct ChallengeMenuItem *items = GetCurrentTabItems();

    if (itemId >= GetCurrentTabItemCount())
        return;

    if (items[itemId].numChoices == 0 || items[itemId].choiceNames == NULL)
        return;

    u8 sel = *GetSelectionPtr(sMenu->currentTab, itemId);
    if (sel >= items[itemId].numChoices)
        sel = 0;

    switch (items[itemId].numChoices)
    {
    case 2:
        DrawChoices_Two(items[itemId].choiceNames, sel, y, TRUE);
        break;
    case 3:
        DrawChoices_Three(items[itemId].choiceNames, sel, y, TRUE);
        break;
    case 4:
        DrawChoices_Four(items[itemId].choiceNames, sel, y, TRUE);
        break;
    case 5:
        DrawChoices_Five(items[itemId].choiceNames, sel, y, TRUE);
        break;
    default:
    {
        const u8 *choiceStr = items[itemId].choiceNames[sel];
        u8 x = GetStringRightAlignXOffset(FONT_NORMAL, choiceStr, 198);
        DrawRightSideChoiceText(choiceStr, x, y + 1, TRUE, TRUE);
        break;
    }
    }
}

// =============================================================================
// List menu init / teardown
// =============================================================================

static void InitListMenu(void)
{
    struct ListMenuTemplate template;
    const struct ChallengeMenuItem *items = GetCurrentTabItems();
    u8 count = GetCurrentTabItemCount();

    for (u8 i = 0; i < count; i++)
    {
        sListItems[i].name = items[i].name;
        sListItems[i].id = i;
    }

    template.items = sListItems;
    template.moveCursorFunc = ChallengeMenu_MoveCursorFunc;
    template.itemPrintFunc = ChallengeMenu_ItemPrintFunc;
    template.totalItems = count;
    template.maxShowed = (count < ITEMS_VISIBLE) ? count : ITEMS_VISIBLE;
    template.windowId = WIN_OPTIONS;
    template.header_X = 0;
    template.item_X = 8;
    template.cursor_X = 0;
    template.upText_Y = 1;
    template.cursorPal = TEXT_COLOR_OPTIONS_ORANGE_FG;
    template.fillValue = 1;
    template.cursorShadowPal = TEXT_COLOR_OPTIONS_ORANGE_SHADOW;
    template.lettersSpacing = 0;
    template.itemVerticalPadding = 0;
    template.scrollMultiple = LIST_NO_MULTIPLE_SCROLL;
    template.fontId = FONT_NORMAL;
    template.cursorKind = CURSOR_INVISIBLE;

    sMenu->listTaskId = ListMenuInit(&template,
        sMenu->scrollOffset[sMenu->currentTab],
        sMenu->selectedRow[sMenu->currentTab]);

    HighlightRow();

    if (count > ITEMS_VISIBLE)
    {
        sMenu->arrowTaskId = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP, 240 / 2, 20, 110,
            count - ITEMS_VISIBLE,
            110, 110,
            &sMenu->scrollOffset[sMenu->currentTab]);
    }
    else
    {
        sMenu->arrowTaskId = TASK_NONE;
    }
}

static void DestroyCurrentListMenu(void)
{
    DestroyListMenuTask(sMenu->listTaskId,
        &sMenu->scrollOffset[sMenu->currentTab],
        &sMenu->selectedRow[sMenu->currentTab]);

    if (sMenu->arrowTaskId != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(sMenu->arrowTaskId);
        sMenu->arrowTaskId = TASK_NONE;
    }
}

// =============================================================================
// Drawing
// =============================================================================

static void DrawTopBar(void)
{
    const u8 color[3] = { TEXT_DYNAMIC_COLOR_6, TEXT_COLOR_OPTIONS_WHITE, TEXT_COLOR_OPTIONS_GRAY_FG };
    const u8 *tabName = sTabs[sMenu->currentTab].tabName;
    int width = GetStringWidth(FONT_SMALL, tabName, 0) / 2;
    int right = 240 - GetStringWidth(FONT_SMALL, sText_TopBar_Right, 0) - 5;

    FillWindowPixelBuffer(WIN_TOPBAR, PIXEL_FILL(15));

    AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 120 - width, 1, color, 0, tabName);

    if (sMenu->currentTab > 0)
        AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, 5, 1, color, 0, sText_TopBar_Left);
    if (sMenu->currentTab < TAB_COUNT - 1)
        AddTextPrinterParameterized3(WIN_TOPBAR, FONT_SMALL, right, 1, color, 0, sText_TopBar_Right);

    PutWindowTilemap(WIN_TOPBAR);
    CopyWindowToVram(WIN_TOPBAR, COPYWIN_FULL);
}

static void DrawDescription(void)
{
    const u8 color[3] = { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_OPTIONS_GRAY_FG, TEXT_COLOR_OPTIONS_GRAY_SHADOW };
    u16 scrollOffset, selectedRow;
    ListMenuGetScrollAndRow(sMenu->listTaskId, &scrollOffset, &selectedRow);
    u8 itemIndex = scrollOffset + selectedRow;

    FillWindowPixelBuffer(WIN_DESCRIPTION, PIXEL_FILL(1));

    const struct ChallengeMenuItem *items = GetCurrentTabItems();
    if (itemIndex < GetCurrentTabItemCount() && items[itemIndex].description != NULL)
    {
        AddTextPrinterParameterized4(WIN_DESCRIPTION, FONT_NORMAL,
            8, 1, 0, 0, color, TEXT_SKIP_DRAW, items[itemIndex].description);
    }

    CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_FULL);
}

static void DrawBgFrames(void)
{
    // Outer frame — top edge at row 2, shared side edges rows 3-18
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  2,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  2, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  2,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  3,  1, 16,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  3,  1, 16,  7);

    // Horizontal divider between options and description (row 13 bottom / row 14 top)
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 13,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 13, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 13,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1, 14,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2, 14, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28, 14,  1,  1,  7);

    // Bottom edge at row 19
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 19,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 19, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 19,  1,  1,  7);

    CopyBgTilemapBufferToVram(1);
}

// =============================================================================
// Tab switching
// =============================================================================

static void SwitchTab(s8 direction)
{
    s8 newTab = sMenu->currentTab + direction;

    if (newTab < 0 || newTab >= TAB_COUNT)
        return;

    DestroyCurrentListMenu();
    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));

    sMenu->currentTab = newTab;

    InitListMenu();
    DrawTopBar();
    DrawDescription();
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);

    PlaySE(SE_SELECT);
}

// =============================================================================
// Input: cycle selection left/right
// =============================================================================

static void ProcessLeftRight(void)
{
    u16 scrollOffset, selectedRow;
    ListMenuGetScrollAndRow(sMenu->listTaskId, &scrollOffset, &selectedRow);
    u8 itemIndex = scrollOffset + selectedRow;

    const struct ChallengeMenuItem *items = GetCurrentTabItems();
    if (itemIndex >= GetCurrentTabItemCount())
        return;
    if (items[itemIndex].numChoices == 0)
        return;

    u8 *sel = GetSelectionPtr(sMenu->currentTab, itemIndex);
    u8 prev = *sel;

    if (JOY_NEW(DPAD_RIGHT))
    {
        if (*sel < items[itemIndex].numChoices - 1)
            (*sel)++;
        else
            *sel = 0;
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (*sel > 0)
            (*sel)--;
        else
            *sel = items[itemIndex].numChoices - 1;
    }

    if (*sel != prev)
    {
        PlaySE(SE_SELECT);
        RedrawListMenu(sMenu->listTaskId);
        HighlightRow();
        CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
        DrawDescription();
    }
}

// =============================================================================
// Tasks
// =============================================================================

static void Task_FadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_ProcessInput;
}

static void Task_ProcessInput(u8 taskId)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        ProcessLeftRight();
        return;
    }

    if (JOY_NEW(L_BUTTON))
    {
        SwitchTab(-1);
        return;
    }

    if (JOY_NEW(R_BUTTON))
    {
        SwitchTab(+1);
        return;
    }

    s32 input = ListMenu_ProcessInput(sMenu->listTaskId);

    if (input == LIST_NOTHING_CHOSEN || input == LIST_CANCEL)
        return;

    if (sMenu->currentTab == TAB_CHALLENGES && (u32)input == ITEM_CHALLENGES_SAVE)
    {
        gTasks[taskId].func = Task_Save;
        return;
    }
}

static void Task_Save(u8 taskId)
{
    // TODO: write selections back to saveblock fields here

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_FadeOut;
}

static void Task_FadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyCurrentListMenu();
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        FREE_AND_SET_NULL(sMenu);
        SetMainCallback2(gMain.savedCallback);
    }
}

// =============================================================================
// Init
// =============================================================================

void CB2_InitChallengeMenu(void)
{
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        ResetBgPositions();
        InitWindows(sWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(16, 224));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(24, 104));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN1_BG0 | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_DARKEN | BLDCNT_TGT1_BG0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
        gMain.state++;
        break;
    case 4:
        LoadPalette(sBgPal, 0, sizeof(sBgPal));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, 0x70, 0x20);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sTextPal, 16, sizeof(sTextPal));
        gMain.state++;
        break;
    case 6:
        sMenu = AllocZeroed(sizeof(struct ChallengeMenuState));
        sMenu->currentTab = TAB_MODE;
        sMenu->arrowTaskId = TASK_NONE;

        // TODO: load current selections from saveblock here

        gMain.state++;
        break;
    case 7:
        PutWindowTilemap(WIN_TOPBAR);
        PutWindowTilemap(WIN_OPTIONS);
        PutWindowTilemap(WIN_DESCRIPTION);
        DrawTopBar();
        DrawBgFrames();
        InitListMenu();
        DrawDescription();
        CopyWindowToVram(WIN_TOPBAR, COPYWIN_FULL);
        CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
        CopyWindowToVram(WIN_DESCRIPTION, COPYWIN_FULL);
        gMain.state++;
        break;
    case 8:
        CreateTask(Task_FadeIn, 0);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        break;
    }
}

// =============================================================================
// Script entry point (for callnative)
// =============================================================================

void Script_OpenChallengeMenu(struct ScriptContext *ctx)
{
    gMain.savedCallback = CB2_ReturnToFieldWithOpenMenu;
    SetMainCallback2(CB2_InitChallengeMenu);
}
