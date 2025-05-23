#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "task.h"
#include "text_window.h"
#include "menu.h"
#include "menu_helpers.h"
#include "list_menu.h"
#include "item.h"
#include "item_menu.h"
#include "link.h"
#include "money.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "pokemon_storage_system.h"
#include "party_menu.h"
#include "data.h"
#include "scanline_effect.h"
#include "shop.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/rgb.h"

#define TM_CASE_TM_TAG 400

struct UnkStruct_203B10C
{
    void (* savedCallback)(void);
    u8 tmCaseMenuType;
    u8 unk_05;
    u8 unk_06;
    u16 selectedRow;
    u16 scrollOffset;
};

struct UnkStruct_203B118
{
    void (* savedCallback)(void);
    u8 tmSpriteId;
    u8 maxTMsShown;
    u8 numTMs;
    u8 contextMenuWindowId;
    u8 scrollIndicatorArrowPairId;
    u16 currItem;
    const u8 * menuActionIndices;
    u8 numMenuActions;
    s16 seqId;
    u8 filler_14[8];
};

struct UnkStruct_203B11C
{
    struct ItemSlot bagPocket_TMHM[BAG_TMHM_COUNT];
    struct ItemSlot bagPocket_KeyItems[BAG_KEYITEMS_COUNT];
    u16 unk_160;
    u16 unk_162;
};

static EWRAM_DATA struct UnkStruct_203B10C sTMCaseStaticResources = {};
static EWRAM_DATA struct UnkStruct_203B118 * sTMCaseDynamicResources = NULL;
static EWRAM_DATA void * sTilemapBuffer = NULL; // tilemap buffer
static EWRAM_DATA struct ListMenuItem * sListMenuItemsBuffer = NULL;
static EWRAM_DATA u8 (* sListMenuStringsBuffer)[29] = NULL;
static EWRAM_DATA u16 * sTMSpritePaletteBuffer = NULL;
static EWRAM_DATA u8    spriteIdData[PARTY_SIZE] = {};
static EWRAM_DATA u16   spriteIdPalette[PARTY_SIZE] = {};

static void CB2_SetUpTMCaseUI_Blocking(void);
static bool8 DoSetUpTMCaseUI(void);
static void ResetBufferPointers_NoFree(void);
static void LoadBGTemplates(void);
static bool8 HandleLoadTMCaseGraphicsAndPalettes(void);
static void CreateTMCaseListMenuBuffers(void);
static void InitTMCaseListMenuItems(void);
static void GetTMNumberAndMoveString(u8 * dest, u16 itemId);
static void TMCase_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list);
static void TMCase_ItemPrintFunc(u8 windowId, u32 itemId, u8 y);
static void TMCase_MoveCursor_UpdatePrintedDescription(s32 itemIndex);
static void PrintListMenuCursorAt_WithColorIdx(u8 a0, u8 a1);
static void CreateTMCaseScrollIndicatorArrowPair_Main(void);
static void TMCaseSetup_GetTMCount(void);
static void TMCaseSetup_InitListMenuPositions(void);
static void TMCaseSetup_UpdateVisualMenuOffset(void);
static void Task_FadeOutAndCloseTMCase(u8 taskId);
static void Task_TMCaseMain(u8 taskId);
static void Task_SelectTMAction_FromFieldBag(u8 taskId);
static void Task_TMContextMenu_HandleInput(u8 taskId);
static void TMHMContextMenuAction_Use(u8 taskId);
static void TMHMContextMenuAction_Give(u8 taskId);
static void PrintError_ThereIsNoPokemon(u8 taskId);
static void PrintError_ItemCantBeHeld(u8 taskId);
static void Task_WaitButtonAfterErrorPrint(u8 taskId);
static void Subtask_CloseContextMenuAndReturnToMain(u8 taskId);
static void TMHMContextMenuAction_Exit(u8 taskId);
static void Task_SelectTMAction_Type1(u8 taskId);
static void Task_SelectTMAction_Type3(u8 taskId);
static void InitWindowTemplatesAndPals(void);
static void AddTextPrinterParameterized_ColorByIndex(u8 windowId, u8 fontId, const u8 * str, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorIdx);
static void TMCase_SetWindowBorder1(u8 windowId);
static void TMCase_SetWindowBorder2(u8 windowId);
static void TMCase_SetWindowBorder3(u8 windowId);
static void TMCase_PrintMessageWithFollowupTask(u8 taskId, u8 windowId, const u8 * str, TaskFunc func);
static void PrintStringTMCaseOnWindow3(void);
static void DrawMoveInfoUIMarkers(void);
static void TMCase_MoveCursor_UpdatePrintedTMInfo(u16 itemId);
static void PlaceHMTileInWindow(u8 windowId, u8 x, u8 y);
static void HandlePrintMoneyOnHand(void);
static void HandleCreateYesNoMenu(u8 taskId, const struct YesNoFuncTable * ptrs);
static u8 AddTMContextMenu(u8 * a0, u8 a1);
static void RemoveTMContextMenu(u8 * a0);
static u8 CreateTMSprite(u16 itemId);
static void SetTMSpriteAnim(struct Sprite * sprite, u8 var);
static void TintTMSpriteByType(u8 type);
static void UpdateTMSpritePosition(struct Sprite * sprite, u8 var);
static void InitSelectedTMSpriteData(u8 a0, u16 itemId);
static void SpriteCB_MoveTMSpriteInCase(struct Sprite * sprite);
static void LoadTMTypePalettes(void);
static void DrawPartyMonIcons(void);
static void TintPartyMonIcons(u8 tm);
static void DestroyPartyMonIcons(void);

static const struct BgTemplate sBGTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0x000
    }, {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0x000
    }, {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0x000
    }
};

static void (*const sSelectTMActionTasks[])(u8 taskId) = {
    Task_SelectTMAction_FromFieldBag,
    Task_SelectTMAction_Type1,
    //Task_SelectTMAction_FromSellMenu,
    Task_SelectTMAction_Type3
};

static const struct MenuAction sMenuActions_UseGiveExit[] = {
    {gMenuText_Use,  TMHMContextMenuAction_Use },
    {gText_Cancel, TMHMContextMenuAction_Exit},
};

static const u8 sMenuActionIndices_Field[] = {0, 1};
static const u8 sMenuActionIndices_UnionRoom[] = {0, 1};
// static const struct YesNoFuncTable sYesNoFuncTable = {Task_PrintSaleConfirmedText, Task_SaleOfTMsCanceled};

static const u8 sText_ClearTo18[] = _("{CLEAR_TO 18}");
static const u8 sText_SingleSpace[] = _(" ");

const u8 gItemDescription_ITEM_TM_CASE[] = _("A case that holds TMs and HMs.\nIt is attached to the BAG's\ncompartment for important items.");
//const u16 gTMCaseMainWindowPalette[] = INCBIN_U16("graphics/tm_case/unk_841F408.gbapal");

static ALIGNED(4) const u16 sPal3Override[] = {RGB(8, 8, 8), RGB(30, 16, 6)};

static const u8 sTMCaseTextColors[][3] = {
    {0, 1, 2},
    {0, 2, 3},
    {0, 3, 6},
    {0, 14, 10},
    {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY},
};

static const struct WindowTemplate sWindowTemplates[] = {
    {0x00, 0x0e, 0x01, 0x0f, 0x0a, 0x0f, 0x0081},
    {0x00, 0x0c, 0x0c, 0x12, 0x08, 0x0a, 0x013f},
    {0x01, 0x05, 0x0f, 0x0f, 0x04, 0x0f, 0x01f9},
    {0x00, 0x00, 0x01, 0x0a, 0x02, 0x0f, 0x0235},
    {0x00, 0x01, 0x0d, 0x05, 0x06, 0x0c, 0x0249},
    {0x00, 0x07, 0x0d, 0x05, 0x06, 0x0c, 0x0267},
    {0x01, 0x02, 0x0f, 0x1a, 0x04, 0x0b, 0x0285},
    {0x01, 0x11, 0x09, 0x0c, 0x04, 0x0f, 0x02ed},
    {0x01, 0x01, 0x01, 0x08, 0x03, 0x0d, 0x031d},
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sYesNoWindowTemplate = {0x01, 0x15, 0x09, 0x06, 0x04, 0x0f, 0x0335};

static const struct WindowTemplate sTMContextWindowTemplates[] = {
    {0x01, 0x16, 0x0d, 0x07, 0x06, 0x0f, 0x01cf},
    {0x01, 0x16, 0x0f, 0x07, 0x04, 0x0f, 0x01cf}
};

static const struct OamData sTMSpriteOamData = {
    .size = 2,
    .priority = 2
};

static const union AnimCmd sTMSpriteAnim0[] = {
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sTMSpriteAnim1[] = {
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sTMSpriteAnims[] = {
    sTMSpriteAnim0,
    sTMSpriteAnim1
};

static const struct CompressedSpriteSheet sTMSpriteSheet = {
    (const void *)gTMCase_TMSpriteGfx,
    0x400,
    TM_CASE_TM_TAG
};

static const struct SpriteTemplate sTMSpriteTemplate = {
    TM_CASE_TM_TAG,
    TM_CASE_TM_TAG,
    &sTMSpriteOamData,
    sTMSpriteAnims,
    NULL,
    gDummySpriteAffineAnimTable,
    SpriteCallbackDummy
};

static const u16 sTMSpritePaletteOffsetByType[] = {
    [TYPE_NORMAL]   = 0x000,
    [TYPE_FIRE]     = 0x010,
    [TYPE_WATER]    = 0x020,
    [TYPE_GRASS]    = 0x030,
    [TYPE_ELECTRIC] = 0x040,
    [TYPE_ROCK]     = 0x050,
    [TYPE_GROUND]   = 0x060,
    [TYPE_ICE]      = 0x070,
    [TYPE_FLYING]   = 0x080,
    [TYPE_FIGHTING] = 0x090,
    [TYPE_GHOST]    = 0x0a0,
    [TYPE_BUG]      = 0x0b0,
    [TYPE_POISON]   = 0x0c0,
    [TYPE_PSYCHIC]  = 0x0d0,
    [TYPE_STEEL]    = 0x0e0,
    [TYPE_DARK]     = 0x0f0,
    [TYPE_DRAGON]   = 0x100
};

void InitTMCase(u8 type, void (* callback)(void), u8 a2)
{
    ResetBufferPointers_NoFree();
    sTMCaseDynamicResources = Alloc(sizeof(struct UnkStruct_203B118));
    sTMCaseDynamicResources->savedCallback = 0;
    sTMCaseDynamicResources->scrollIndicatorArrowPairId = 0xFF;
    sTMCaseDynamicResources->contextMenuWindowId = 0xFF;
    if (type != 5)
        sTMCaseStaticResources.tmCaseMenuType = type;
    if (callback != NULL)
        sTMCaseStaticResources.savedCallback = callback;
    if (a2 != 0xFF)
        sTMCaseStaticResources.unk_05 = a2;
    gTextFlags.autoScroll = FALSE;
    SetMainCallback2(CB2_SetUpTMCaseUI_Blocking);
}

static void CB2_Idle(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB_Idle(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_SetUpTMCaseUI_Blocking(void)
{
    while (1)
    {
        if (MenuHelpers_ShouldWaitForLinkRecv() == TRUE)
            break;
        if (DoSetUpTMCaseUI() == TRUE)
            break;
        if (MenuHelpers_IsLinkActive() == TRUE)
            break;
    }
}

static bool8 DoSetUpTMCaseUI(void)
{
    u8 taskId;

    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 3:
        ResetPaletteFade();
        gMain.state++;
        break;
    case 4:
        ResetSpriteData();
        gMain.state++;
        break;
    case 5:
        ResetTasks();
        gMain.state++;
        break;
    case 6:
        LoadBGTemplates();
        sTMCaseDynamicResources->seqId = 0;
        gMain.state++;
        break;
    case 7:
        InitWindowTemplatesAndPals();
        gMain.state++;
        break;
    case 8:
        if (HandleLoadTMCaseGraphicsAndPalettes())
            gMain.state++;
        break;
    case 9:
        UpdatePocketItemList(TMHM_POCKET);
        gMain.state++;
        break;
    case 10:
        TMCaseSetup_GetTMCount();
        TMCaseSetup_InitListMenuPositions();
        TMCaseSetup_UpdateVisualMenuOffset();
        gMain.state++;
        break;
    case 11:
        DrawMoveInfoUIMarkers();
        DrawPartyMonIcons();
        gMain.state++;
        break;
    case 12:
        CreateTMCaseListMenuBuffers();
        InitTMCaseListMenuItems();
        gMain.state++;
        break;
    case 13:
        PrintStringTMCaseOnWindow3();
        gMain.state++;
        break;
    case 14:
        taskId = CreateTask(Task_TMCaseMain, 0);
        gTasks[taskId].data[0] = ListMenuInit(&gMultiuseListMenuTemplate, sTMCaseStaticResources.scrollOffset, sTMCaseStaticResources.selectedRow);
        gMain.state++;
        break;
    case 15:
        CreateTMCaseScrollIndicatorArrowPair_Main();
        gMain.state++;
        break;
    case 16:
        // sTMCaseDynamicResources->tmSpriteId = CreateTMSprite(BagGetItemIdByPocketPosition(POCKET_TM_HM, sTMCaseStaticResources.scrollOffset + sTMCaseStaticResources.selectedRow));
        gMain.state++;
        break;
    case 17:
        BlendPalettes(0xFFFFFFFF, 16, 0);
        gMain.state++;
        break;
    case 18:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(VBlankCB_Idle);
        SetMainCallback2(CB2_Idle);
        return TRUE;
    }

    return FALSE;
}

static void ResetBufferPointers_NoFree(void)
{
    sTMCaseDynamicResources = NULL;
    sTilemapBuffer = NULL;
    sListMenuItemsBuffer = NULL;
    sListMenuStringsBuffer = NULL;
    sTMSpritePaletteBuffer = NULL;
}

static void LoadBGTemplates(void)
{
    void ** ptr;
    ResetVramOamAndBgCntRegs();
    ResetAllBgsCoordinates();
    ptr = &sTilemapBuffer;
    *ptr = AllocZeroed(0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBGTemplates, NELEMS(sBGTemplates));
    SetBgTilemapBuffer(2, *ptr);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
}

static bool8 HandleLoadTMCaseGraphicsAndPalettes(void)
{
    switch (sTMCaseDynamicResources->seqId)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, gUnknown_8E845D8, 0, 0, 0);
        sTMCaseDynamicResources->seqId++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(gUnknown_8E84A24, sTilemapBuffer);
            sTMCaseDynamicResources->seqId++;
        }
        break;
    case 2:
        // LZDecompressWram(gUnknown_8E84B70, GetBgTilemapBuffer(1)); //TM case bg graphic
        sTMCaseDynamicResources->seqId++;
        break;
    case 3:
        if (gSaveBlock2Ptr->playerGender == MALE)
            LoadCompressedPalette(gUnknown_8E84CB0, 0, 0x80);
        else
            LoadCompressedPalette(gUnknown_8E84D20, 0, 0x80);
        sTMCaseDynamicResources->seqId++;
        break;
    case 4:
        LoadCompressedSpriteSheet(&sTMSpriteSheet);
        sTMCaseDynamicResources->seqId++;
        break;
    default:
        //LoadTMTypePalettes();
        sTMCaseDynamicResources->seqId = 0;
        return TRUE;
    }

    return FALSE;
}

static void CreateTMCaseListMenuBuffers(void)
{
    struct BagPocket * pocket = &gBagPockets[POCKET_TM_HM - 1];
    sListMenuItemsBuffer = Alloc((pocket->capacity) * sizeof(struct ListMenuItem));
    sListMenuStringsBuffer = Alloc(sTMCaseDynamicResources->numTMs * 29);
}

static void InitTMCaseListMenuItems(void)
{
    struct BagPocket * pocket = &gBagPockets[POCKET_TM_HM - 1];
    u16 i;

    for (i = 0; i < sTMCaseDynamicResources->numTMs; i++)
    {
        GetTMNumberAndMoveString(sListMenuStringsBuffer[i], pocket->itemSlots[i].itemId);
        sListMenuItemsBuffer[i].name = sListMenuStringsBuffer[i];
        sListMenuItemsBuffer[i].id = i;
    }
    // sListMenuItemsBuffer[i].name = gText_Close;
    // sListMenuItemsBuffer[i].id = -2;
    gMultiuseListMenuTemplate.items = sListMenuItemsBuffer;
    gMultiuseListMenuTemplate.totalItems = sTMCaseDynamicResources->numTMs;
    gMultiuseListMenuTemplate.windowId = 0;
    gMultiuseListMenuTemplate.header_X = 0;
    gMultiuseListMenuTemplate.item_X = 8;
    gMultiuseListMenuTemplate.cursor_X = 0;
    gMultiuseListMenuTemplate.lettersSpacing = 0;
    gMultiuseListMenuTemplate.itemVerticalPadding = 2;
    gMultiuseListMenuTemplate.upText_Y = 2;
    gMultiuseListMenuTemplate.maxShowed = sTMCaseDynamicResources->maxTMsShown;
    gMultiuseListMenuTemplate.fontId = 2;
    gMultiuseListMenuTemplate.cursorPal = 2;
    gMultiuseListMenuTemplate.fillValue = 0;
    gMultiuseListMenuTemplate.cursorShadowPal = 3;
    gMultiuseListMenuTemplate.moveCursorFunc = TMCase_MoveCursorFunc;
    gMultiuseListMenuTemplate.itemPrintFunc = TMCase_ItemPrintFunc;
    gMultiuseListMenuTemplate.cursorKind = 0;
    gMultiuseListMenuTemplate.scrollMultiple = 0;
}

static void GetTMNumberAndMoveString(u8 * dest, u16 itemId)
{
    StringCopy(gStringVar4, gText_FontSmall);
    if (itemId >= ITEM_HM01)
    {
        StringAppend(gStringVar4, sText_ClearTo18);
        StringAppend(gStringVar4, gText_NumberClear01);
        ConvertIntToDecimalStringN(gStringVar1, itemId - ITEM_HM01 + 1, STR_CONV_MODE_LEADING_ZEROS, 1);
        StringAppend(gStringVar4, gStringVar1);
    }
    else
    {
        StringAppend(gStringVar4, gText_NumberClear01);
        ConvertIntToDecimalStringN(gStringVar1, itemId - ITEM_TM01 + 1, STR_CONV_MODE_LEADING_ZEROS, 2);
        StringAppend(gStringVar4, gStringVar1);
    }
    StringAppend(gStringVar4, sText_SingleSpace);
    StringAppend(gStringVar4, gText_FontShort);
    StringAppend(gStringVar4, gMoveNames[ItemIdToBattleMoveId(itemId)]);
    StringCopy(dest, gStringVar4);
}

static void TMCase_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    u16 itemId;

    if (itemIndex == -2)
        itemId = 0;
    else
        itemId = BagGetItemIdByPocketPosition(POCKET_TM_HM, itemIndex);

    if (onInit != TRUE)
    {
        PlaySE(SE_SELECT);
        // InitSelectedTMSpriteData(sTMCaseDynamicResources->tmSpriteId, itemId);
    }
    TMCase_MoveCursor_UpdatePrintedDescription(itemIndex);
    TMCase_MoveCursor_UpdatePrintedTMInfo(itemId);
}

static void TMCase_ItemPrintFunc(u8 windowId, u32 itemId, u8 y)
{
    if (itemId != -2)
    {
        if (!ItemId_GetImportance(BagGetItemIdByPocketPosition(POCKET_TM_HM, itemId)))
        {
            // ConvertIntToDecimalStringN(gStringVar1, BagGetQuantityByPocketPosition(POCKET_TM_HM, itemId), STR_CONV_MODE_RIGHT_ALIGN, 3);
            // StringExpandPlaceholders(gStringVar4, gText_xVar1);
            // AddTextPrinterParameterized_ColorByIndex(windowId, 0, gStringVar4, 0x7E, y, 0, 0, 0xFF, 1);
        }
        else
        {
            PlaceHMTileInWindow(windowId, 8, y);
        }
    }
}

static void TMCase_MoveCursor_UpdatePrintedDescription(s32 itemIndex)
{
    const u8 * str;
    u16 itemId = BagGetItemIdByPocketPosition(POCKET_TM_HM, itemIndex);
    if (itemIndex != -2)
    {
        str = ItemId_GetDescription(itemId);
    }
    else
    {
        str = gText_TMCaseWillBePutAway;
    }
    FillWindowPixelBuffer(1, 0);
    AddTextPrinterParameterized_ColorByIndex(1, 2, str, 2, 3, 1, 0, 0, 0);

    // update icons
    TintPartyMonIcons(itemId - ITEM_TM01);
}

static void FillBG2RowWithPalette_2timesNplus1(s32 a0)
{
    SetBgTilemapPalette(2, 0, 12, 30, 8, 2 * a0 + 1);
    ScheduleBgCopyTilemapToVram(2);
}

static void PrintListMenuCursorByID_WithColorIdx(u8 a0, u8 a1)
{
    PrintListMenuCursorAt_WithColorIdx(ListMenuGetYCoordForPrintingArrowCursor(a0), a1);
}

static void PrintListMenuCursorAt_WithColorIdx(u8 a0, u8 a1)
{
    if (a1 == 0xFF)
    {
        FillWindowPixelRect(0, 0, 0, a0, GetFontAttribute(2, 0), GetFontAttribute(2, 1));
        CopyWindowToVram(0, 2);
    }
    else
    {
        AddTextPrinterParameterized_ColorByIndex(0, 2, gText_SelectorArrow2, 0, a0, 0, 0, 0, a1);
    }
}

static void CreateTMCaseScrollIndicatorArrowPair_Main(void)
{
    sTMCaseDynamicResources->scrollIndicatorArrowPairId = AddScrollIndicatorArrowPairParameterized(2, 0xA0, 0x08, 0x58, sTMCaseDynamicResources->numTMs - sTMCaseDynamicResources->maxTMsShown, 0x6E, 0x6E, &sTMCaseStaticResources.scrollOffset);
}

static void CreateTMCaseScrollIndicatorArrowPair_SellQuantitySelect(void)
{
    sTMCaseDynamicResources->currItem = 1;
    sTMCaseDynamicResources->scrollIndicatorArrowPairId = AddScrollIndicatorArrowPairParameterized(2, 0x98, 0x48, 0x68, 2, 0x6E, 0x6E, &sTMCaseDynamicResources->currItem);
}

static void RemoveTMCaseScrollIndicatorArrowPair(void)
{
    if (sTMCaseDynamicResources->scrollIndicatorArrowPairId != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(sTMCaseDynamicResources->scrollIndicatorArrowPairId);
        sTMCaseDynamicResources->scrollIndicatorArrowPairId = 0xFF;
    }
}

void ResetTMCaseCursorPos(void)
{
    sTMCaseStaticResources.selectedRow = 0;
    sTMCaseStaticResources.scrollOffset = 0;
}

static void TMCaseSetup_GetTMCount(void)
{
    struct BagPocket * pocket = &gBagPockets[POCKET_TM_HM - 1];
    u16 i;

    // BagPocketCompaction(pocket->itemSlots, pocket->capacity);
    UpdatePocketItemList(TMHM_POCKET);
    sTMCaseDynamicResources->numTMs = 0;
    for (i = 0; i < pocket->capacity; i++)
    {
        if (pocket->itemSlots[i].itemId == ITEM_NONE)
            break;
        sTMCaseDynamicResources->numTMs++;
    }
    sTMCaseDynamicResources->maxTMsShown = min(sTMCaseDynamicResources->numTMs, 5);
}

static void TMCaseSetup_InitListMenuPositions(void)
{
    if (sTMCaseStaticResources.scrollOffset != 0)
    {
        if (sTMCaseStaticResources.scrollOffset + sTMCaseDynamicResources->maxTMsShown > sTMCaseDynamicResources->numTMs)
            sTMCaseStaticResources.scrollOffset = sTMCaseDynamicResources->numTMs - sTMCaseDynamicResources->maxTMsShown;
    }
    if (sTMCaseStaticResources.scrollOffset + sTMCaseStaticResources.selectedRow >= sTMCaseDynamicResources->numTMs)
    {
        if (sTMCaseDynamicResources->numTMs < 2)
            sTMCaseStaticResources.selectedRow = 0;
        else
            sTMCaseStaticResources.selectedRow = sTMCaseDynamicResources->numTMs;
    }
}

static void TMCaseSetup_UpdateVisualMenuOffset(void)
{
    u8 i;
    if (sTMCaseStaticResources.selectedRow > 3)
    {
        for (i = 0; i <= sTMCaseStaticResources.selectedRow - 3 && sTMCaseStaticResources.scrollOffset + sTMCaseDynamicResources->maxTMsShown != sTMCaseDynamicResources->numTMs; i++)
        {
            do {} while (0);
            sTMCaseStaticResources.selectedRow--;
            sTMCaseStaticResources.scrollOffset++;
        }
    }
}

static void DestroyTMCaseBuffers(void)
{
    if (sTMCaseDynamicResources != NULL)
        Free(sTMCaseDynamicResources);
    if (sTilemapBuffer != NULL)
        Free(sTilemapBuffer);
    if (sListMenuItemsBuffer != NULL)
        Free(sListMenuItemsBuffer);
    if (sListMenuStringsBuffer != NULL)
        Free(sListMenuStringsBuffer);
    if (sTMSpritePaletteBuffer != NULL)
        Free(sTMSpritePaletteBuffer);
    FreeAllWindowBuffers();
}

static void Task_BeginFadeOutFromTMCase(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, -2, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_FadeOutAndCloseTMCase;
}

static void Task_FadeOutAndCloseTMCase(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        DestroyListMenuTask(data[0], &sTMCaseStaticResources.scrollOffset, &sTMCaseStaticResources.selectedRow);
        if (sTMCaseDynamicResources->savedCallback != NULL)
            SetMainCallback2(sTMCaseDynamicResources->savedCallback);
        else
            SetMainCallback2(sTMCaseStaticResources.savedCallback);
        RemoveTMCaseScrollIndicatorArrowPair();
        DestroyTMCaseBuffers();
        DestroyTask(taskId);
    }
}

static void Task_TMCaseMain(u8 taskId)
{
    s16 * data = gTasks[taskId].data;
    s32 input;

    if (!gPaletteFade.active)
    {
        if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
        {
            input = ListMenu_ProcessInput(data[0]);
            ListMenuGetScrollAndRow(data[0], &sTMCaseStaticResources.scrollOffset, &sTMCaseStaticResources.selectedRow);
            if (JOY_NEW(SELECT_BUTTON) && sTMCaseStaticResources.unk_05 == 1)
            {
                PlaySE(SE_SELECT);
                gSpecialVar_ItemId = ITEM_NONE;
                Task_BeginFadeOutFromTMCase(taskId);
            }
            else
            {
                switch (input)
                {
                case -1:
                    break;
                case -2:
                    PlaySE(SE_SELECT);
                    gSpecialVar_ItemId = 0;
                    Task_BeginFadeOutFromTMCase(taskId);
                    break;
                default:
                    PlaySE(SE_SELECT);
                    FillBG2RowWithPalette_2timesNplus1(1);
                    RemoveTMCaseScrollIndicatorArrowPair();
                    PrintListMenuCursorByID_WithColorIdx(data[0], 2);
                    data[1] = input;
                    data[2] = BagGetQuantityByPocketPosition(POCKET_TM_HM, input);
                    gSpecialVar_ItemId = BagGetItemIdByPocketPosition(POCKET_TM_HM, input);
                    gTasks[taskId].func = sSelectTMActionTasks[sTMCaseStaticResources.tmCaseMenuType];
                    break;
                }
            }
        }
    }
}

static void Subtask_ReturnToTMCaseMain(u8 taskId)
{
    FillBG2RowWithPalette_2timesNplus1(0);
    CreateTMCaseScrollIndicatorArrowPair_Main();
    gTasks[taskId].func = Task_TMCaseMain;
}

static void Task_SelectTMAction_FromFieldBag(u8 taskId)
{
    u8 * strbuf;
    // contex menu
    if (!MenuHelpers_IsLinkActive() && InUnionRoom() != TRUE) // menu code
    {
        AddTMContextMenu(&sTMCaseDynamicResources->contextMenuWindowId, 1);
        sTMCaseDynamicResources->menuActionIndices = sMenuActionIndices_Field;
        sTMCaseDynamicResources->numMenuActions = NELEMS(sMenuActionIndices_Field);
    }
    else
    {
        AddTMContextMenu(&sTMCaseDynamicResources->contextMenuWindowId, 1);
        sTMCaseDynamicResources->menuActionIndices = sMenuActionIndices_UnionRoom;
        sTMCaseDynamicResources->numMenuActions = NELEMS(sMenuActionIndices_UnionRoom);
    }
    // context menu text
    PrintMenuActionTexts(sTMCaseDynamicResources->contextMenuWindowId, 2, GetMenuCursorDimensionByFont(2, 0), 2, 0, GetFontAttribute(2, 1) + 2, sTMCaseDynamicResources->numMenuActions, sMenuActions_UseGiveExit, sTMCaseDynamicResources->menuActionIndices);
    // context menu cursor
    InitMenuInUpperLeftCornerNormal(sTMCaseDynamicResources->contextMenuWindowId, sTMCaseDynamicResources->numMenuActions, 0);
    
    //"Move xyz is selected" text and window (no shoing the right palette)
    TMCase_SetWindowBorder3(2); // context window border style
    strbuf = Alloc(256);
    GetTMNumberAndMoveString(strbuf, gSpecialVar_ItemId);
    StringAppend(strbuf, gText_Var1IsSelected + 2); // +2 skips over the stringvar
    AddTextPrinterParameterized_ColorByIndex(2, 2, strbuf, 0, 2, 1, 0, 0, 4);
    Free(strbuf);

    //show HM icon
    if (ItemId_GetImportance(gSpecialVar_ItemId))
    {
        PlaceHMTileInWindow(2, 0, 2);
        CopyWindowToVram(2, 2);
    }

    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    gTasks[taskId].func = Task_TMContextMenu_HandleInput;
}

static void Task_TMContextMenu_HandleInput(u8 taskId)
{
    s8 input;

    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        input = Menu_ProcessInputNoWrap();
        switch (input)
        {
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            sMenuActions_UseGiveExit[sTMCaseDynamicResources->menuActionIndices[sTMCaseDynamicResources->numMenuActions - 1]].func.void_u8(taskId);
            break;
        case MENU_NOTHING_CHOSEN:
            break;
        default:
            PlaySE(SE_SELECT);
            sMenuActions_UseGiveExit[sTMCaseDynamicResources->menuActionIndices[input]].func.void_u8(taskId);
            break;
        }
    }
}

static void TMHMContextMenuAction_Use(u8 taskId)
{
    RemoveTMContextMenu(&sTMCaseDynamicResources->contextMenuWindowId);
    ClearStdWindowAndFrameToTransparent(2, 0);
    ClearWindowTilemap(2);
    PutWindowTilemap(0);
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    if (CalculatePlayerPartyCount() == 0)
    {
        PrintError_ThereIsNoPokemon(taskId);
    }
    else
    {
        gItemUseCB = ItemUseCB_TMHM;
        sTMCaseDynamicResources->savedCallback = CB2_ShowPartyMenuForItemUseTMCase;
        Task_BeginFadeOutFromTMCase(taskId);
    }
}

static void PrintError_ThereIsNoPokemon(u8 taskId)
{
    TMCase_PrintMessageWithFollowupTask(taskId, 2, gText_NoPokemon, Task_WaitButtonAfterErrorPrint);
}

static void PrintError_ItemCantBeHeld(u8 taskId)
{
    CopyItemName(gSpecialVar_ItemId, gStringVar1);
    StringExpandPlaceholders(gStringVar4, gText_Var1CantBeHeld);
    TMCase_PrintMessageWithFollowupTask(taskId, 2, gStringVar4, Task_WaitButtonAfterErrorPrint);
}

static void Task_WaitButtonAfterErrorPrint(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        Subtask_CloseContextMenuAndReturnToMain(taskId);
    }
}

static void Subtask_CloseContextMenuAndReturnToMain(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    DestroyListMenuTask(data[0], &sTMCaseStaticResources.scrollOffset, &sTMCaseStaticResources.selectedRow);
    data[0] = ListMenuInit(&gMultiuseListMenuTemplate, sTMCaseStaticResources.scrollOffset, sTMCaseStaticResources.selectedRow);
    PrintListMenuCursorByID_WithColorIdx(data[0], 1);
    ClearDialogWindowAndFrameToTransparent(6, 0);
    ClearWindowTilemap(6);
    PutWindowTilemap(1);
    PutWindowTilemap(4);
    PutWindowTilemap(5);
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    Subtask_ReturnToTMCaseMain(taskId);
}

static void TMHMContextMenuAction_Exit(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    RemoveTMContextMenu(&sTMCaseDynamicResources->contextMenuWindowId);
    ClearStdWindowAndFrameToTransparent(2, 0);
    ClearWindowTilemap(2);
    PutWindowTilemap(0);
    PrintListMenuCursorByID_WithColorIdx(data[0], 1);
    PutWindowTilemap(1);
    PutWindowTilemap(4);
    PutWindowTilemap(5);
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    Subtask_ReturnToTMCaseMain(taskId);
}

static void Task_SelectTMAction_Type1(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    PrintError_ItemCantBeHeld(taskId);
}

static void Task_SelectTMAction_Type3(u8 taskId)
{
    s16 * data = gTasks[taskId].data;

    if (!ItemId_GetImportance(BagGetItemIdByPocketPosition(POCKET_TM_HM, data[1])))
    {
        sTMCaseDynamicResources->savedCallback = CB2_ReturnToPokeStorage;
        Task_BeginFadeOutFromTMCase(taskId);
    }
    else
    {
        PrintError_ItemCantBeHeld(taskId);
    }
}

static void InitWindowTemplatesAndPals(void)
{
    u8 i;

    InitWindows(sWindowTemplates);
    DeactivateAllTextPrinters();
    LoadMessageBoxGfx(0, 0x64, 0xB0);
    LoadUserWindowBorderGfx(0, 0x78, 0xD0);
    LoadPalette(gTMCaseMainWindowPalette, 0xF0, 0x20);
    LoadPalette(gTMCaseMainWindowPalette, 0xA0, 0x20);
    LoadPalette(sPal3Override, 0xF6, 0x04);
    LoadPalette(sPal3Override, 0xD6, 0x04);
    ListMenuLoadStdPalAt(0xc0, 0x01);
    for (i = 0; i < 9; i++)
        FillWindowPixelBuffer(i, 0x00);
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    PutWindowTilemap(3);
    PutWindowTilemap(4);
    PutWindowTilemap(5);
    ScheduleBgCopyTilemapToVram(0);
}

static void AddTextPrinterParameterized_ColorByIndex(u8 windowId, u8 fontId, const u8 * str, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorIdx)
{
    AddTextPrinterParameterized4(windowId, fontId, x, y, letterSpacing, lineSpacing, sTMCaseTextColors[colorIdx], speed, str);
}

static void TMCase_SetWindowBorder1(u8 windowId)
{
    DrawStdFrameWithCustomTileAndPalette(windowId, FALSE, 0x5B, 0x0E);
}

static void TMCase_SetWindowBorder2(u8 windowId)
{
    DrawStdFrameWithCustomTileAndPalette(windowId, FALSE, 0x78, 0x0D);
}

static void TMCase_SetWindowBorder3(u8 windowId)
{
    DrawStdFrameWithCustomTileAndPalette(windowId, FALSE, 0x78, 0x0D);
}

static void TMCase_PrintMessageWithFollowupTask(u8 taskId, u8 windowId, const u8 * str, TaskFunc func)
{
    DisplayMessageAndContinueTask(taskId, 6, 0x64, 0x0B, windowId, GetPlayerTextSpeedDelay(), str, func);
    ScheduleBgCopyTilemapToVram(1);
}

static void PrintStringTMCaseOnWindow3(void)
{
    u32 distance = 72 - GetStringWidth(1, gText_TMCase, 0);
    AddTextPrinterParameterized3(3, 1, distance / 2, 1, sTMCaseTextColors[0], 0, gText_TMCase);
}

static void DrawMoveInfoUIMarkers(void)
{
    #ifndef POKEMON_EXPANSION
        BlitMenuInfoIcon(4, 19, 0, 0); // "Type" sprite
        BlitMenuInfoIcon(4, 20, 0, 12); // "Power" sprite
        BlitMenuInfoIcon(4, 21, 0, 24); // "Accuracy" sprite
        BlitMenuInfoIcon(4, 22, 0, 36); // "PP" sprite
    #else
        BlitMenuInfoIcon(4, 20, 0, 0); // "Type" sprite
        BlitMenuInfoIcon(4, 21, 0, 12); // "Power" sprite
        BlitMenuInfoIcon(4, 22, 0, 24); // "Accuracy" sprite
        BlitMenuInfoIcon(4, 23, 0, 36); // "PP" sprite
    #endif
    CopyWindowToVram(4, 2);
}

static void TMCase_MoveCursor_UpdatePrintedTMInfo(u16 itemId)
{
    u8 i;
    u16 move;
    const u8 * str;

    FillWindowPixelRect(5, 0, 0, 0, 40, 48);
    if (itemId == ITEM_NONE)
    {
        for (i = 0; i < 4; i++)
        {
            AddTextPrinterParameterized_ColorByIndex(5, 3, gText_ThreeDashes, 7, 12 * i, 0, 0, 0xFF, 3);
        }
        CopyWindowToVram(5, 2);
    }
    else
    {
        move = ItemIdToBattleMoveId(itemId);
        BlitMenuInfoIcon(5, gBattleMoves[move].type + 1, 0, 0);
        if (gBattleMoves[move].power < 2)
            str = gText_ThreeDashes;
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move].power, STR_CONV_MODE_RIGHT_ALIGN, 3);
            str = gStringVar1;
        }
        AddTextPrinterParameterized_ColorByIndex(5, 3, str, 7, 12, 0, 0, 0xFF, 3);
        if (gBattleMoves[move].accuracy == 0)
            str = gText_ThreeDashes;
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move].accuracy, STR_CONV_MODE_RIGHT_ALIGN, 3);
            str = gStringVar1;
        }
        AddTextPrinterParameterized_ColorByIndex(5, 3, str, 7, 24, 0, 0, 0xFF, 3);
        ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move].pp, STR_CONV_MODE_RIGHT_ALIGN, 3);
        AddTextPrinterParameterized_ColorByIndex(5, 3, gStringVar1, 7, 36, 0, 0, 0xFF, 3);
        CopyWindowToVram(5, 2);
    }
}

static void PlaceHMTileInWindow(u8 windowId, u8 x, u8 y)
{
    BlitBitmapToWindow(windowId, gUnknown_8E99118, x, y, 16, 12);
}

static void HandlePrintMoneyOnHand(void)
{
    PrintMoneyAmountInMoneyBoxWithBorder(8, 0x78, 0xD, GetMoney(&gSaveBlock1Ptr->money));
}

static void HandleCreateYesNoMenu(u8 taskId, const struct YesNoFuncTable *ptrs)
{
    CreateYesNoMenuWithCallbacks(taskId, &sYesNoWindowTemplate, 2, 0, 2, 0x5B, 0x0E, ptrs);
}

static u8 AddTMContextMenu(u8 * a0, u8 a1)
{
    if (*a0 == 0xFF)
    {
        *a0 = AddWindow(&sTMContextWindowTemplates[a1]);
        TMCase_SetWindowBorder2(*a0);
        ScheduleBgCopyTilemapToVram(0);
    }
    return *a0;
}

static void RemoveTMContextMenu(u8 * a0)
{
    ClearStdWindowAndFrameToTransparent(*a0, FALSE);
    ClearWindowTilemap(*a0);
    RemoveWindow(*a0);
    ScheduleBgCopyTilemapToVram(0);
    *a0 = 0xFF;
}

#define sMonIconStill data[3]
static void SpriteCb_MonIcon(struct Sprite *sprite)
{
    if (!sprite->sMonIconStill)
        UpdateMonIconFrame(sprite);
}
#undef sMonIconStill

#define MON_ICON_START_X  0x10
#define MON_ICON_START_Y  0x2a
#define MON_ICON_PADDING  0x20


void LoadMonIconPalettesTinted(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(gMonIconPaletteTable); i++)
    {
        LoadSpritePalette(&gMonIconPaletteTable[i]);
        TintPalette_GrayScale2(&gPlttBufferUnfaded[0x170 + i*16], 16);
    }
}
        

static void DrawPartyMonIcons(void)
{
    u8 i;
    u16 species;
    u8 icon_x = 0;
    u8 icon_y = 0;

    LoadMonIconPalettesTinted();

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        //calc icon position (centered)
        if (gPlayerPartyCount == 1)
        {
            icon_x = MON_ICON_START_X + MON_ICON_PADDING;
            icon_y = MON_ICON_START_Y + MON_ICON_PADDING*0.5;
        }
        else if (gPlayerPartyCount == 2)
        {
            icon_x = i < 2 ? MON_ICON_START_X + MON_ICON_PADDING*0.5 + MON_ICON_PADDING * i : MON_ICON_START_X + MON_ICON_PADDING*0.5 + MON_ICON_PADDING * (i - 2);
            icon_y = MON_ICON_START_Y + MON_ICON_PADDING*0.5;
        }else if (gPlayerPartyCount == 3)
        {
            icon_x = i < 3 ? MON_ICON_START_X + MON_ICON_PADDING * i : MON_ICON_START_X + MON_ICON_PADDING * (i - 3);
            icon_y = MON_ICON_START_Y + MON_ICON_PADDING*0.5;
        }
        else if (gPlayerPartyCount == 4)
        {
            icon_x = i < 2 ? MON_ICON_START_X + MON_ICON_PADDING*0.5 + MON_ICON_PADDING * i : MON_ICON_START_X + MON_ICON_PADDING*0.5 + MON_ICON_PADDING * (i - 2);
            icon_y = i < 2 ? MON_ICON_START_Y : MON_ICON_START_Y + MON_ICON_PADDING;
        }
        else
        {
            icon_x = i < 3 ? MON_ICON_START_X + MON_ICON_PADDING * i : MON_ICON_START_X + MON_ICON_PADDING * (i - 3);
            icon_y = i < 3 ? MON_ICON_START_Y : MON_ICON_START_Y + MON_ICON_PADDING;
        }
        //get species
        species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);

        //create icon sprite
        #ifndef POKEMON_EXPANSION
            spriteIdData[i] = CreateMonIcon(species, SpriteCb_MonIcon, icon_x, icon_y, 1, GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY), TRUE);
        #else
            spriteIdData[i] = CreateMonIcon(species, SpriteCb_MonIcon, icon_x, icon_y, 1, GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY));
        #endif

        //Set priority, stop movement and save original palette position
        gSprites[spriteIdData[i]].oam.priority = 0;
        StartSpriteAnim(&gSprites[spriteIdData[i]], 4); //full stop
        spriteIdPalette[i] = gSprites[spriteIdData[i]].oam.paletteNum; //save correct palette number to array
    }
}

static void TintPartyMonIcons(u8 tm)
{
    u8 i;
    u16 species;

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
        if (!CanSpeciesLearnTMHM(species, tm))
        {
            gSprites[spriteIdData[i]].oam.paletteNum = 7 + spriteIdPalette[i];
        }
        else
        {
            gSprites[spriteIdData[i]].oam.paletteNum = spriteIdPalette[i];//gMonIconPaletteIndices[species];
        }
    }
    
}

static void DestroyPartyMonIcons(void)
{
    u8 i;
    for (i = 0; i < gPlayerPartyCount; i++)
    {
        FreeAndDestroyMonIconSprite(&gSprites[spriteIdData[i]]);
        FreeMonIconPalettes();
    }
}
