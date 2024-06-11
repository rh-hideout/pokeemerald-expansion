//Credits: TheXaman
#include "global.h"
#include "constants/songs.h"
#include "bg.h"
#include "decoration.h"
#include "event_scripts.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "constants/items.h"
#include "list_menu.h"
#include "mail.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "player_pc.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "window.h"
#include "menu_specialized.h"
#include "tx_registered_items_menu.h"
#include "graphics.h"

#define SWAP_LINE_LENGTH 7
struct TxRegItemsMenu_Struct
{
    struct ListMenuItem listItems[PC_ITEMS_COUNT + 1];
    u8 itemNames[PC_ITEMS_COUNT + 1][ITEM_NAME_LENGTH + 10];
    u8 windowIds[1];
    u8 toSwapPos;
    u8 spriteId;
    u8 spriteId2;
    u8 swapLineSpriteIds[SWAP_LINE_LENGTH];
    u8 swapLineSpriteIds2[SWAP_LINE_LENGTH];
};

// Message IDs for Item Storage
enum {
    MSG_SWITCH_WHICH_ITEM = 0xFFF7,
    MSG_OKAY_TO_THROW_AWAY,
    MSG_TOO_IMPORTANT,
    MSG_NO_MORE_ROOM,
    MSG_THREW_AWAY_ITEM,
    MSG_HOW_MANY_TO_TOSS,
    MSG_WITHDREW_ITEM,
    MSG_HOW_MANY_TO_WITHDRAW,
    MSG_GO_BACK_TO_PREV
};

static void TxRegItemsMenu_InitMenuFunctions(u8 taskId);
static void TxRegItemsMenu_ClearAndInitData(u8 taskId);
static void TxRegItemsMenu_InitDataAndCreateListMenu(u8 taskId);
static void TxRegItemsMenu_ProcessInput(u8 taskId);
static void TxRegItemsMenu_DoItemAction(u8 taskId);
static void TxRegItemsMenu_CloseMenu(u8 taskId);
static void TxRegItemsMenu_ItemSwapChoosePrompt(u8 taskId);
static void TxRegItemsMenu_HandleSwapInput(u8 taskId);
//helper
static void TxRegItemsMenu_CalcCursorPos(void);
static void TxRegItemsMenu_CalculateUsedSlots(void);
static void TxRegItemsMenu_AllocateStruct(void);
static u8 TxRegItemsMenu_InitWindow(void);
static void TxRegItemsMenu_RefreshListMenu(void);
static void TxRegItemsMenu_MoveCursor(s32 id, bool8 b, struct ListMenu *thisMenu);
static void TxRegItemsMenu_PrintFunc(u8 windowId, u32 id, u8 yOffset);
static void TxRegItemsMenu_PrintItemIcon(u16 itemId);
static void TxRegItemsMenu_DoItemSwap(u8 taskId, bool8 a);
static void TxRegItemsMenu_StartScrollIndicator(void);
static void TxRegItemsMenu_UpdateSwapLinePos(u8 y);
static void TxRegItemsMenu_CopyItemName(u8 *string, u16 itemId);
static void TxRegItemsMenu_PrintSwappingCursor(u8 y, u8 b, u8 speed);
static void TxRegItemsMenu_GetSwappingCursorPositionAndPrint(u8 a, u8 b, u8 speed);
static void TxRegItemsMenu_MoveItemSlotInList(struct RegisteredItemSlot* registeredItemSlots_, u32 from, u32 to_);
static void TxRegItemsMenu_CalcAndSetUsedSlotsCount(struct RegisteredItemSlot *slots, u8 count, u8 *arg2, u8 *usedSlotsCount, u8 maxUsedSlotsCount);
static void TxRegItemsMenu_RemoveRegisteredItemIndex(u8 index);
static s32 TxRegItemsMenu_FindFreeRegisteredItemSlot(void);
//helper cleanup
static void TxRegItemsMenu_RemoveItemIcon(void);
static void TxRegItemsMenu_RemoveWindow(void);
static void TxRegItemsMenu_RemoveScrollIndicator(void);
static void TxRegItemsMenu_FreeStructs(void);

#define TAG_ITEM_ICON       5110
#define TAG_INDICATOR_ARROWS       TAG_ITEM_ICON//109
#define TILE_TAG_INDICATOR_ARROWS  0x13f8
#define TAG_SCROLL_ARROW    TAG_ITEM_ICON//5112

static const struct WindowTemplate TxRegItemsMenu_WindowTemplates[1] =
{
    {//item list window
        .bg = 0,
        .tilemapLeft = 1, //0
        .tilemapTop = 13,
        .width = 28, //30
        .height = 6, //7
        .paletteNum = 15,
        .baseBlock = 0x0001
    },
};

static const struct ListMenuTemplate gTxRegItemsMenu_List = //item storage list
{
    .items = NULL,
    .moveCursorFunc = TxRegItemsMenu_MoveCursor,
    .itemPrintFunc = TxRegItemsMenu_PrintFunc,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 0,
    .header_X = 0,
    .item_X = 48,
    .cursor_X = 40,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = FALSE,
    .itemVerticalPadding = 0,
    .scrollMultiple = FALSE,
    .fontId = 7
};

// EWRAM
static EWRAM_DATA struct TxRegItemsMenu_Struct *gTxRegItemsMenu = NULL;
static EWRAM_DATA struct TxRegItemsMenu_ItemPageStruct TxRegItemsMenuItemPageInfo = {0, 0, 0, 0, {0, 0, 0}, 0};


// functions
void TxRegItemsMenu_OpenMenu(void)
{
    u8 taskId = CreateTask(TaskDummy, 0);
    FreezeObjects_WaitForPlayer();
    gTasks[taskId].func = TxRegItemsMenu_InitMenuFunctions;
}

static void TxRegItemsMenu_InitMenuFunctions(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u8 count = TxRegItemsMenu_CountUsedRegisteredItemSlots();
    TxRegItemsMenu_ClearAndInitData(taskId);
}

static void TxRegItemsMenu_ClearAndInitData(u8 taskId)
{
    u16 *data = gTasks[taskId].data;
    u8 offset = 0;
    u8 cursorStart = gSaveBlock1Ptr->registeredItemLastSelected;
    u8 count = TxRegItemsMenu_CountUsedRegisteredItemSlots();

    //calculate offset from list top
    if (cursorStart > 1 && count > 3)
    {
        if (cursorStart == count - 1)
        {
            offset = cursorStart - 2;
            cursorStart = 2;
        }
        else
        {
            offset = cursorStart - 1;
            cursorStart = 1;
        }
    }

    TxRegItemsMenuItemPageInfo.cursorPos = cursorStart;
    TxRegItemsMenuItemPageInfo.itemsAbove = offset;
    TxRegItemsMenuItemPageInfo.scrollIndicatorTaskId = TASK_NONE;
    TxRegItemsMenuItemPageInfo.pageItems = 3; //ItemStorage_SetItemAndMailCount(taskId);
    TxRegItemsMenu_AllocateStruct(); //sub_816BC14(); //allocate struct
    //FreeAndReserveObjectSpritePalettes();
    //AllocSpritePalette(TAG_INDICATOR_ARROWS);
    //LoadPalette(&gBagSwapLineGfx, 432, 16);
    LoadListMenuSwapLineGfx_RegisteredItemsMenu();
    CreateSwapLineSprites_RegisteredItemsMenu(gTxRegItemsMenu->swapLineSpriteIds, 7);
    if (GetFlashLevel() > 0)
    {
        u8 i;
        CreateSwapLineSprites_RegisteredItemsMenu(gTxRegItemsMenu->swapLineSpriteIds2, 7);
        for (i=0; i<SWAP_LINE_LENGTH; i++)
            gSprites[gTxRegItemsMenu->swapLineSpriteIds2[i]].oam.objMode = ST_OAM_OBJ_WINDOW;
    }
    gTasks[taskId].func = TxRegItemsMenu_InitDataAndCreateListMenu;
}

static void TxRegItemsMenu_InitDataAndCreateListMenu(u8 taskId)
{
    s16 *data;
    u32 i, x;
    const u8* text;

    data = gTasks[taskId].data;
    TxRegItemsMenu_CalculateUsedSlots(); //calculate used slots
    TxRegItemsMenu_CalcCursorPos(); //calc cursor pos
    TxRegItemsMenu_RefreshListMenu();
    data[5] = ListMenuInit(&gMultiuseListMenuTemplate, TxRegItemsMenuItemPageInfo.itemsAbove, TxRegItemsMenuItemPageInfo.cursorPos);
    TxRegItemsMenu_StartScrollIndicator();
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = TxRegItemsMenu_ProcessInput;
}

static void TxRegItemsMenu_ProcessInput(u8 taskId)
{
    s16 *data;
    s32 id;

    data = gTasks[taskId].data;
    if (JOY_NEW(SELECT_BUTTON))
    {
        ListMenuGetScrollAndRow(data[5], &(TxRegItemsMenuItemPageInfo.itemsAbove), &(TxRegItemsMenuItemPageInfo.cursorPos)); //fine
        if ((TxRegItemsMenuItemPageInfo.itemsAbove + TxRegItemsMenuItemPageInfo.cursorPos) != (TxRegItemsMenuItemPageInfo.count - 1))
        {
            PlaySE(SE_SELECT);
            TxRegItemsMenu_ItemSwapChoosePrompt(taskId);
        }
    }
    else
    {
        id = ListMenu_ProcessInput(data[5]); //fine
        ListMenuGetScrollAndRow(data[5], &(TxRegItemsMenuItemPageInfo.itemsAbove), &(TxRegItemsMenuItemPageInfo.cursorPos)); //fine
        switch(id)
        {
        case LIST_NOTHING_CHOSEN:
            break;
        case LIST_CANCEL:
            PlaySE(SE_SELECT);
            ScriptContext_Enable();
            TxRegItemsMenu_CloseMenu(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            TxRegItemsMenu_DoItemAction(taskId);
            break;
        }
    }
}

static void TxRegItemsMenu_DoItemAction(u8 taskId)
{
    s16 *data;
    u16 pos;

    data = gTasks[taskId].data;
    pos = (TxRegItemsMenuItemPageInfo.cursorPos + TxRegItemsMenuItemPageInfo.itemsAbove);
    TxRegItemsMenu_RemoveScrollIndicator();

    gSaveBlock1Ptr->registeredItemLastSelected = pos;
    TxRegItemsMenu_CloseMenu(taskId);
    UseRegisteredKeyItemOnField(pos+2);
}

static void TxRegItemsMenu_CloseMenu(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    TxRegItemsMenu_RemoveItemIcon();
    TxRegItemsMenu_RemoveScrollIndicator();
    DestroyListMenuTask(data[5], NULL, NULL);
    DestroySwapLineSprites(gTxRegItemsMenu->swapLineSpriteIds, 7);
    if (GetFlashLevel() > 0)
        DestroySwapLineSprites(gTxRegItemsMenu->swapLineSpriteIds2, 7);
    TxRegItemsMenu_RemoveWindow();
    TxRegItemsMenu_FreeStructs();
    ScriptUnfreezeObjectEvents();
    DestroyTask(taskId);
}

static void TxRegItemsMenu_ItemSwapChoosePrompt(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    ListMenuSetUnkIndicatorsStructField(data[5], 16, 1);
    gTxRegItemsMenu->toSwapPos = (TxRegItemsMenuItemPageInfo.itemsAbove + TxRegItemsMenuItemPageInfo.cursorPos);
    TxRegItemsMenu_GetSwappingCursorPositionAndPrint(data[5], 0, 0);
    TxRegItemsMenu_UpdateSwapLinePos(gTxRegItemsMenu->toSwapPos);
    gTasks[taskId].func = TxRegItemsMenu_HandleSwapInput;
}

static void TxRegItemsMenu_HandleSwapInput(u8 taskId)
{
    s16 *data;
    s32 id;

    data = gTasks[taskId].data;
    if (JOY_NEW(SELECT_BUTTON))
    {
        ListMenuGetScrollAndRow(data[5], &(TxRegItemsMenuItemPageInfo.itemsAbove), &(TxRegItemsMenuItemPageInfo.cursorPos));
        TxRegItemsMenu_DoItemSwap(taskId, FALSE);
        return;
    }
    id = ListMenu_ProcessInput(data[5]);
    ListMenuGetScrollAndRow(data[5], &(TxRegItemsMenuItemPageInfo.itemsAbove), &(TxRegItemsMenuItemPageInfo.cursorPos));
    SetSwapLineSpritesInvisibility(gTxRegItemsMenu->swapLineSpriteIds, 7, FALSE);
    if (GetFlashLevel() > 0)
        SetSwapLineSpritesInvisibility(gTxRegItemsMenu->swapLineSpriteIds2, 7, FALSE);
    TxRegItemsMenu_UpdateSwapLinePos(TxRegItemsMenuItemPageInfo.cursorPos);
    switch(id)
    {
    case LIST_NOTHING_CHOSEN:
        break;
    case LIST_CANCEL:
        if (JOY_NEW(A_BUTTON))
        {
            TxRegItemsMenu_DoItemSwap(taskId, FALSE);
        }
        else
        {
            TxRegItemsMenu_DoItemSwap(taskId, TRUE);
        }
        break;
    default:
        TxRegItemsMenu_DoItemSwap(taskId, FALSE);
        break;
    }
}



//helper functions
static void TxRegItemsMenu_AllocateStruct(void)
{
    gTxRegItemsMenu = AllocZeroed(sizeof(struct TxRegItemsMenu_Struct));
    memset(gTxRegItemsMenu->windowIds, 0xFF, 0x1);
    gTxRegItemsMenu->toSwapPos = 0xFF;
    gTxRegItemsMenu->spriteId = SPRITE_NONE;
    gTxRegItemsMenu->spriteId2 = SPRITE_NONE;
}

static u8 TxRegItemsMenu_InitWindow(void)
{
    u8 *windowIdLoc = &(gTxRegItemsMenu->windowIds[0]);
    if (*windowIdLoc == WINDOW_NONE)
    {
        *windowIdLoc = AddWindow(&TxRegItemsMenu_WindowTemplates[0]);
        DrawStdFrameWithCustomTileAndPalette(*windowIdLoc, FALSE, 0x214, 0xE);
        ScheduleBgCopyTilemapToVram(0);
    }
    return *windowIdLoc;
}

static void TxRegItemsMenu_CalculateUsedSlots(void) //calculate used slots
{
    TxRegItemsMenu_CompactRegisteredItems();
    TxRegItemsMenu_CalcAndSetUsedSlotsCount(gSaveBlock1Ptr->registeredItems, REGISTERED_ITEMS_MAX, &(TxRegItemsMenuItemPageInfo.pageItems), &(TxRegItemsMenuItemPageInfo.count), 3);
}

static void TxRegItemsMenu_CalcCursorPos(void) //calc cursor pos
{
    SetCursorWithinListBounds(&(TxRegItemsMenuItemPageInfo.itemsAbove), &(TxRegItemsMenuItemPageInfo.cursorPos), TxRegItemsMenuItemPageInfo.pageItems, TxRegItemsMenuItemPageInfo.count); //fine
}

static void TxRegItemsMenu_RefreshListMenu(void)
{
    u16 i;
    u8 windowId = TxRegItemsMenu_InitWindow();
    LoadMessageBoxAndBorderGfx();
    SetStandardWindowBorderStyle(windowId , 0);

    for(i = 0; i < TxRegItemsMenuItemPageInfo.count - 1; i++)
    {
        TxRegItemsMenu_CopyItemName(&(gTxRegItemsMenu->itemNames[i][0]), gSaveBlock1Ptr->registeredItems[i].itemId);
        gTxRegItemsMenu->listItems[i].name = &(gTxRegItemsMenu->itemNames[i][0]);
        gTxRegItemsMenu->listItems[i].id = i;
    }
    StringCopy(&(gTxRegItemsMenu->itemNames[i][0]) ,gText_Cancel2);
    gTxRegItemsMenu->listItems[i].name = &(gTxRegItemsMenu->itemNames[i][0]);
    gTxRegItemsMenu->listItems[i].id = -2;
    gMultiuseListMenuTemplate = gTxRegItemsMenu_List;
    gMultiuseListMenuTemplate.windowId = windowId;
    gMultiuseListMenuTemplate.totalItems = TxRegItemsMenuItemPageInfo.count;
    gMultiuseListMenuTemplate.items = gTxRegItemsMenu->listItems;
    gMultiuseListMenuTemplate.maxShowed = 3;//TxRegItemsMenuItemPageInfo.pageItems;
}

static void TxRegItemsMenu_MoveCursor(s32 id, bool8 b, struct ListMenu *thisMenu)
{
    if (b != TRUE)
        PlaySE(SE_SELECT);
    if (gTxRegItemsMenu->toSwapPos == 0xFF)
    {
        TxRegItemsMenu_RemoveItemIcon();
        if (id != -2)
            TxRegItemsMenu_PrintItemIcon(gSaveBlock1Ptr->registeredItems[id].itemId);
        else
            TxRegItemsMenu_PrintItemIcon(MSG_GO_BACK_TO_PREV);
    }
}

static void TxRegItemsMenu_PrintFunc(u8 windowId, u32 id, u8 yOffset)
{
    if (id != -2)
    {
        if (gTxRegItemsMenu->toSwapPos != 0xFF)
        {
            if (gTxRegItemsMenu->toSwapPos == (u8)id)
                TxRegItemsMenu_PrintSwappingCursor(yOffset, 0, 0xFF);
            else
                TxRegItemsMenu_PrintSwappingCursor(yOffset, 0xFF, 0xFF);
        }
    }
}

static void TxRegItemsMenu_PrintItemIcon(u16 itemId)
{
    u8 spriteId = MAX_SPRITES;
    u8 spriteId2 = MAX_SPRITES;
    u8* spriteIdLoc = &gTxRegItemsMenu->spriteId;
    u8* spriteId2Loc = &gTxRegItemsMenu->spriteId2;
    bool8 handleFlash = FALSE;

    if (GetFlashLevel() > 0)
    {
        handleFlash = TRUE;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
        SetGpuRegBits(REG_OFFSET_WINOUT, WINOUT_WINOBJ_OBJ);
    }

    if (*spriteIdLoc == SPRITE_NONE)
    {
        FreeSpriteTilesByTag(TAG_ITEM_ICON);
        FreeSpritePaletteByTag(TAG_ITEM_ICON);
        spriteId = AddItemIconSprite(TAG_ITEM_ICON, TAG_ITEM_ICON, itemId);
        
        if (spriteId != MAX_SPRITES)
        {
            *spriteIdLoc = spriteId;
            gSprites[spriteId].oam.priority = 0;
            gSprites[spriteId].x2 = 32;
            gSprites[spriteId].y2 = 132;
        }
    }

    if (handleFlash && *spriteId2Loc == SPRITE_NONE)
    {
        spriteId2 = AddItemIconSprite(TAG_ITEM_ICON, TAG_ITEM_ICON, itemId);
        if (spriteId2 != MAX_SPRITES)
        {
            *spriteId2Loc = spriteId2;
            gSprites[spriteId2].oam.priority = 0;
            gSprites[spriteId2].x2 = 32;
            gSprites[spriteId2].y2 = 132;
            gSprites[spriteId2].oam.objMode = ST_OAM_OBJ_WINDOW;
        }
    }
}

static void TxRegItemsMenu_DoItemSwap(u8 taskId, bool8 a)
{
    s16 *data;
    u16 b;
    u8 lastSelected = gSaveBlock1Ptr->registeredItemLastSelected;
    u16 lastSelectedItemId = gSaveBlock1Ptr->registeredItems[lastSelected].itemId;

    data = gTasks[taskId].data;
    b = (TxRegItemsMenuItemPageInfo.itemsAbove + TxRegItemsMenuItemPageInfo.cursorPos);
    PlaySE(SE_SELECT);
    DestroyListMenuTask(data[5], &(TxRegItemsMenuItemPageInfo.itemsAbove), &(TxRegItemsMenuItemPageInfo.cursorPos));
    if (!a)
    {
        if (gTxRegItemsMenu->toSwapPos != b)
        {
            if (gTxRegItemsMenu->toSwapPos != b - 1)
            {
                TxRegItemsMenu_MoveItemSlotInList(gSaveBlock1Ptr->registeredItems, gTxRegItemsMenu->toSwapPos, b);
                gSaveBlock1Ptr->registeredItemLastSelected = TxRegItemsMenu_GetRegisteredItemIndex(lastSelectedItemId);
                TxRegItemsMenu_RefreshListMenu();
            }
        }
    }
    if (gTxRegItemsMenu->toSwapPos < b)
        TxRegItemsMenuItemPageInfo.cursorPos--;
    SetSwapLineSpritesInvisibility(gTxRegItemsMenu->swapLineSpriteIds, 7, TRUE);
    if (GetFlashLevel() > 0)
        SetSwapLineSpritesInvisibility(gTxRegItemsMenu->swapLineSpriteIds2, 7, TRUE);
    gTxRegItemsMenu->toSwapPos = 0xFF;
    data[5] = ListMenuInit(&gMultiuseListMenuTemplate, TxRegItemsMenuItemPageInfo.itemsAbove, TxRegItemsMenuItemPageInfo.cursorPos);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = TxRegItemsMenu_ProcessInput;
}

static void TxRegItemsMenu_StartScrollIndicator(void)
{
    if (TxRegItemsMenuItemPageInfo.scrollIndicatorTaskId == TASK_NONE)
        TxRegItemsMenuItemPageInfo.scrollIndicatorTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 28, 110, 148, TxRegItemsMenuItemPageInfo.count - TxRegItemsMenuItemPageInfo.pageItems, TILE_TAG_INDICATOR_ARROWS, TAG_INDICATOR_ARROWS, &(TxRegItemsMenuItemPageInfo.itemsAbove)); //176, 12, 148 x, y1, y2
}

static void TxRegItemsMenu_UpdateSwapLinePos(u8 y)
{
    UpdateSwapLineSpritesPos(gTxRegItemsMenu->swapLineSpriteIds, 7, 48, ((y+1) * 16 + 90));
    if (GetFlashLevel() > 0)
        UpdateSwapLineSpritesPos(gTxRegItemsMenu->swapLineSpriteIds2, 7, 48, ((y+1) * 16 + 90));
}

static void TxRegItemsMenu_CopyItemName(u8 *string, u16 itemId)
{
    CopyItemName(itemId, string);
}

static const u8 gColor_gray[] = {0x01, 0x03, 0x02, 0x00};
static void TxRegItemsMenu_PrintSwappingCursor(u8 y, u8 b, u8 speed)
{
    u8 x = 40;
    u8 windowId = gTxRegItemsMenu->windowIds[0];
    if (b == 0xFF)
        FillWindowPixelRect(windowId, PIXEL_FILL(1), x, y, GetMenuCursorDimensionByFont(1, 0), GetMenuCursorDimensionByFont(1, 1));
    else
        AddTextPrinterParameterized4(windowId, 1, x, y, 0, 0, gColor_gray, speed, gText_SelectorArrow2);
}

static void TxRegItemsMenu_GetSwappingCursorPositionAndPrint(u8 a, u8 b, u8 speed)
{
    TxRegItemsMenu_PrintSwappingCursor(ListMenuGetYCoordForPrintingArrowCursor(a), b, speed);
}


//registeredItems struct helper functions
static void TxRegItemsMenu_MoveItemSlotInList(struct RegisteredItemSlot* registeredItemSlots_, u32 from, u32 to_)
{
    // dumb assignments needed to match
    struct RegisteredItemSlot *registeredItemSlots = registeredItemSlots_;
    u32 to = to_;

    if (from != to)
    {
        s16 i, count;
        struct RegisteredItemSlot firstSlot = registeredItemSlots[from];

        if (to > from)
        {
            to--;
            for (i = from, count = to; i < count; i++)
                registeredItemSlots[i] = registeredItemSlots[i + 1];
        }
        else
        {
            for (i = from, count = to; i > count; i--)
                registeredItemSlots[i] = registeredItemSlots[i - 1];
        }
        registeredItemSlots[to] = firstSlot;
    }
}

u8 TxRegItemsMenu_CountUsedRegisteredItemSlots(void)
{
    u8 usedSlots = 0;
    u8 i;

    for (i = 0; i < PC_ITEMS_COUNT; i++)
    {
        if (gSaveBlock1Ptr->registeredItems[i].itemId != ITEM_NONE)
            usedSlots++;
    }
    return usedSlots;
}

static void TxRegItemsMenu_ChangeLastSelectedItemIndex(u8 index)
{
    if (gSaveBlock1Ptr->registeredItemLastSelected == index)
        gSaveBlock1Ptr->registeredItemLastSelected = 0;
    else if (index < gSaveBlock1Ptr->registeredItemLastSelected && index != 0)
        gSaveBlock1Ptr->registeredItemLastSelected--;
}


static void TxRegItemsMenu_RemoveRegisteredItemIndex(u8 index)
{
    TxRegItemsMenu_ChangeLastSelectedItemIndex(index);
    gSaveBlock1Ptr->registeredItems[index].itemId = ITEM_NONE;
    gSaveBlock1Ptr->registeredItemListCount--;
    TxRegItemsMenu_CompactRegisteredItems();
}

void TxRegItemsMenu_RemoveRegisteredItem(u16 itemId)
{
    u8 i;
    for (i = i ; i < REGISTERED_ITEMS_MAX; i++)
        {
            if (gSaveBlock1Ptr->registeredItems[i].itemId == itemId)
            {
                gSaveBlock1Ptr->registeredItems[i].itemId = ITEM_NONE;
                gSaveBlock1Ptr->registeredItemListCount--;
                TxRegItemsMenu_ChangeLastSelectedItemIndex(i);
                TxRegItemsMenu_CompactRegisteredItems();
            }
        }
}
void TxRegItemsMenu_CompactRegisteredItems(void)
{
    u16 i;
    u16 j;

    for (i = 0; i < REGISTERED_ITEMS_MAX - 1; i++)
    {
        for (j = i + 1; j < REGISTERED_ITEMS_MAX; j++)
        {
            if (gSaveBlock1Ptr->registeredItems[i].itemId == ITEM_NONE)
            {
                struct RegisteredItemSlot temp = gSaveBlock1Ptr->registeredItems[i];
                gSaveBlock1Ptr->registeredItems[i] = gSaveBlock1Ptr->registeredItems[j];
                gSaveBlock1Ptr->registeredItems[j] = temp;
            }
        }
    }
    gSaveBlock1Ptr->registeredItemListCount = TxRegItemsMenu_CountUsedRegisteredItemSlots();
}

static void TxRegItemsMenu_CalcAndSetUsedSlotsCount(struct RegisteredItemSlot *slots, u8 count, u8 *arg2, u8 *usedSlotsCount, u8 maxUsedSlotsCount)
{
    u16 i;
    struct RegisteredItemSlot *slots_ = slots;

    (*usedSlotsCount) = 0;
    for (i = 0; i < count; i++)
    {
        if (slots_[i].itemId != ITEM_NONE)
            (*usedSlotsCount)++;
    }

    (*usedSlotsCount)++;
    if ((*usedSlotsCount) > maxUsedSlotsCount)
        *arg2 = maxUsedSlotsCount;
    else
        *arg2 = (*usedSlotsCount);
}

bool8 TxRegItemsMenu_CheckRegisteredHasItem(u16 itemId)
{
    u8 i;

    for (i = 0; i < REGISTERED_ITEMS_MAX; i++)
    {
        if (gSaveBlock1Ptr->registeredItems[i].itemId == itemId)
            return TRUE;
    }
    return FALSE;
}

u8 TxRegItemsMenu_GetRegisteredItemIndex(u16 itemId)
{
    u8 i;

    for (i = 0; i < REGISTERED_ITEMS_MAX; i++)
    {
        if (gSaveBlock1Ptr->registeredItems[i].itemId == itemId)
            return i;
    }
    return 0xFF;
}

static s32 TxRegItemsMenu_FindFreeRegisteredItemSlot(void)
{
    s8 i;

    for (i = 0; i < REGISTERED_ITEMS_MAX; i++)
    {
        if (gSaveBlock1Ptr->registeredItems[i].itemId == ITEM_NONE)
            return i;
    }
    return -1;
}

bool8 TxRegItemsMenu_AddRegisteredItem(u16 itemId)
{
    u8 i;
    s8 freeSlot;
    struct RegisteredItemSlot *newItems;

    // Copy PC items
    newItems = AllocZeroed(sizeof(gSaveBlock1Ptr->registeredItems));
    memcpy(newItems, gSaveBlock1Ptr->registeredItems, sizeof(gSaveBlock1Ptr->registeredItems));

    //check for a free slot
    freeSlot = TxRegItemsMenu_FindFreeRegisteredItemSlot();
    if (freeSlot == -1) //no slot left, return (triggers error messsage)
    {
        Free(newItems);
        return FALSE;
    }
    else
    {
        newItems[freeSlot].itemId = itemId;
        gSaveBlock1Ptr->registeredItemListCount++;
    }

    // Copy items back to the PC
    memcpy(gSaveBlock1Ptr->registeredItems, newItems, sizeof(gSaveBlock1Ptr->registeredItems));
    Free(newItems);
    return TRUE;
}

void TxRegItemsMenu_RegisteredItemsMenuNewGame(void)
{
    u8 i;
    struct RegisteredItemSlot *newItems;
    for (i = i ; i < REGISTERED_ITEMS_MAX; i++)
    {
        gSaveBlock1Ptr->registeredItems[i].itemId = ITEM_NONE;
    }
    gSaveBlock1Ptr->registeredItemLastSelected = 0;
    gSaveBlock1Ptr->registeredItemListCount = 0;
}


//helper cleanup
static void TxRegItemsMenu_RemoveItemIcon(void) //remove item storage selected item icon
{
    u8* spriteIdLoc = &(gTxRegItemsMenu->spriteId);
    u8* spriteId2Loc = &(gTxRegItemsMenu->spriteId2);
    
    if (*spriteIdLoc != SPRITE_NONE)
    {
        FreeSpriteTilesByTag(TAG_ITEM_ICON);
        FreeSpritePaletteByTag(TAG_ITEM_ICON);
        DestroySprite(&(gSprites[*spriteIdLoc]));
        *spriteIdLoc = SPRITE_NONE;
    }

    if (GetFlashLevel() > 0 && *spriteId2Loc != SPRITE_NONE)
    {
        FreeSpriteTilesByTag(TAG_ITEM_ICON);
        FreeSpritePaletteByTag(TAG_ITEM_ICON);
        DestroySprite(&(gSprites[*spriteId2Loc]));
        *spriteId2Loc = SPRITE_NONE;
    }
}

static void TxRegItemsMenu_RemoveWindow(void) //remove window
{
    u8 *windowIdLoc = &(gTxRegItemsMenu->windowIds[0]);
    if (*windowIdLoc != WINDOW_NONE)
    {
        ClearStdWindowAndFrameToTransparent(*windowIdLoc, FALSE);
        ClearWindowTilemap(*windowIdLoc);
        ScheduleBgCopyTilemapToVram(0);
        RemoveWindow(*windowIdLoc);
        *windowIdLoc = WINDOW_NONE;
    }
}

static void TxRegItemsMenu_RemoveScrollIndicator(void)
{
    if (TxRegItemsMenuItemPageInfo.scrollIndicatorTaskId != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(TxRegItemsMenuItemPageInfo.scrollIndicatorTaskId);
        TxRegItemsMenuItemPageInfo.scrollIndicatorTaskId = TASK_NONE;
    }
}

static void TxRegItemsMenu_FreeStructs(void)
{
    Free(gTxRegItemsMenu);
}



