#include "global.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "money.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "script.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "text_window.h"
#include "tv.h"
#include "grid_menu.h"
#include "event_data.h"
#include "constants/decorations.h"
#include "constants/items.h"
#include "constants/metatile_behaviors.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/event_objects.h"

#ifdef MUDSKIP_SHOP_UI
// #include "outfit_menu.h" // uncomment this out if you have my outfit system
#include "new_shop.h"

#define GFXTAG_CURSOR 0x1300
#define PALTAG_CURSOR 0x1300

#define GFXTAG_ITEM 0x1000
#define PALTAG_ITEM 0x2000

#define CURSOR_START_X 100 + 32
#define CURSOR_START_Y 4 + 32

#define MAX_ITEMS_SHOWN sShopData->gridItems->numItems

enum {
    WIN_BUY_SELL_QUIT,
    WIN_BUY_QUIT,
};

enum {
    WIN_MONEY,
    WIN_MULTI,
    WIN_ITEM_DESCRIPTION,
    WIN_QUANTITY_PRICE,
    WIN_MUGSHOT,
};

enum {
    COLORID_NORMAL,      // Money amount
    COLORID_BLACK,       // Item descriptions, quantity in bag, and quantity/price
};

enum {
    MART_TYPE_NORMAL,
    MART_TYPE_DECOR,
    MART_TYPE_DECOR2,
    #ifdef MUDSKIP_OUTFIT_SYSTEM
    MART_TYPE_OUTFIT,
    #endif // MUDSKIP_OUTFIT_SYSTEM
    MART_TYPE_VARIABLE,
};

// seller id
enum
{
    SELLER_NONE,
    SELLER_JERRY, // OBJ_EVENT_GFX_MART_EMPLOYEE
    SELLER_JENNIE, // OBJ_EVENT_GFX_WOMAN_3
    SELLER_COUNT,
};

struct MartInfo
{
    void (*callback)(void);
    const struct MenuAction *menuActions;
    const u16 *itemSource;
    u16 *itemList;
    u16 *itemPriceList;
    u16 itemCount;
    u8 windowId;
    u8 martType;
};

struct ShopData
{
    u16 tilemapBuffers[2][0x400];
    u32 totalCost;
    u16 maxQuantity;
    u8 gfxLoadState;
    u8 cursorSpriteId;
    u16 currentItemId;
    struct GridMenu *gridItems;
    u16 sellerId;
};

struct Seller
{
    // Add more id "param" on the union here
    union {
        u16 gfxId;
    } id;
    const u8 *mugshotGfx;
    const u16 *mugshotPal;
    const u32 *menuGfx;
    const u32 *menuPal;
    const u32 *menuMap;
    const u32 *scrollGfx;
    const u32 *scrollPal;
    const u32 *scrollMap;
    const u16 *cursorGfx;
    const u32 *cursorPal;
    // use seperate palette for scrolling bg,
    // this can be used if your scrolling bg
    // colors cant fit to the menu's graphics
    // palette. uses bg pal slot 1, after the
    // menu pal slot (0)
    bool8 useScrollPal;
};

static EWRAM_DATA struct MartInfo sMartInfo = {0};
static EWRAM_DATA struct ShopData *sShopData = NULL;
static EWRAM_DATA u8 sPurchaseHistoryId = 0;

const u32 sNewShopMenu_DefaultMenuGfx[] = INCBIN_U32("graphics/new_shop/menu.4bpp.lz");
const u32 sNewShopMenu_DefaultMenuPal[] = INCBIN_U32("graphics/new_shop/menu.gbapal.lz");
const u32 sNewShopMenu_DefaultMenuTilemap[] = INCBIN_U32("graphics/new_shop/menu.bin.lz");
const u32 sNewShopMenu_DefaultScrollGfx[] = INCBIN_U32("graphics/new_shop/scroll.4bpp.lz");
const u32 sNewShopMenu_DefaultScrollTilemap[] = INCBIN_U32("graphics/new_shop/scroll.bin.lz");
const u16 sNewShopMenu_DefaultCursorGfx[] = INCBIN_U16("graphics/new_shop/cursor.4bpp"); // uses the menu palette

const u8 sNewShopMenu_SellerMugshotGfx_Jerry[] = INCBIN_U8("graphics/new_shop/sellers/jerry/mugshot.4bpp");
const u16 sNewShopMenu_SellerMugshotPal_Jerry[] = INCBIN_U16("graphics/new_shop/sellers/jerry/mugshot.gbapal");
const u32 sNewShopMenu_SellerMenuGfx_Jerry[] = INCBIN_U32("graphics/new_shop/sellers/jerry/menu.4bpp.lz");
const u32 sNewShopMenu_SellerMenuPal_Jerry[] = INCBIN_U32("graphics/new_shop/sellers/jerry/menu.gbapal.lz");
const u32 sNewShopMenu_SellerMenuMap_Jerry[] = INCBIN_U32("graphics/new_shop/sellers/jerry/menu.bin.lz");
const u32 sNewShopMenu_SellerScrollGfx_Jerry[] = INCBIN_U32("graphics/new_shop/sellers/jerry/scroll.4bpp.lz");
const u32 sNewShopMenu_SellerScrollPal_Jerry[] = INCBIN_U32("graphics/new_shop/sellers/jerry/scroll.gbapal.lz");
const u32 sNewShopMenu_SellerScrollMap_Jerry[] = INCBIN_U32("graphics/new_shop/sellers/jerry/scroll.bin.lz");
const u16 sNewShopMenu_SellerCursorGfx_Jerry[] = INCBIN_U16("graphics/new_shop/sellers/jerry/cursor.4bpp");
const u32 sNewShopMenu_SellerCursorPal_Jerry[] = INCBIN_U32("graphics/new_shop/sellers/jerry/cursor.gbapal.lz");

const u8 sNewShopMenu_SellerMugshotGfx_Jennie[] = INCBIN_U8("graphics/new_shop/sellers/jennie/mugshot.4bpp");
const u16 sNewShopMenu_SellerMugshotPal_Jennie[] = INCBIN_U16("graphics/new_shop/sellers/jennie/mugshot.gbapal");
const u32 sNewShopMenu_SellerMenuGfx_Jennie[] = INCBIN_U32("graphics/new_shop/sellers/jennie/menu.4bpp.lz");
const u32 sNewShopMenu_SellerMenuPal_Jennie[] = INCBIN_U32("graphics/new_shop/sellers/jennie/menu.gbapal.lz");
const u32 sNewShopMenu_SellerMenuMap_Jennie[] = INCBIN_U32("graphics/new_shop/sellers/jennie/menu.bin.lz");
const u32 sNewShopMenu_SellerScrollGfx_Jennie[] = INCBIN_U32("graphics/new_shop/sellers/jennie/scroll.4bpp.lz");
const u32 sNewShopMenu_SellerScrollPal_Jennie[] = INCBIN_U32("graphics/new_shop/sellers/jennie/scroll.gbapal.lz");
const u32 sNewShopMenu_SellerScrollMap_Jennie[] = INCBIN_U32("graphics/new_shop/sellers/jennie/scroll.bin.lz");
const u16 sNewShopMenu_SellerCursorGfx_Jennie[] = INCBIN_U16("graphics/new_shop/sellers/jennie/cursor.4bpp");
const u32 sNewShopMenu_SellerCursorPal_Jennie[] = INCBIN_U32("graphics/new_shop/sellers/jennie/cursor.gbapal.lz");

static void Task_ShopMenu(u8 taskId);
static void Task_HandleShopMenuQuit(u8 taskId);
static void CB2_InitBuyMenu(void);
static void Task_GoToBuyOrSellMenu(u8 taskId);
static void MapPostLoadHook_ReturnToShopMenu(void);
static void Task_ReturnToShopMenu(u8 taskId);
static void ShowShopMenuAfterExitingBuyOrSellMenu(u8 taskId);
static void BuyMenuDrawGraphics(void);
static void Task_BuyMenu(u8 taskId);
static void BuyMenuInitBgs(void);
static void BuyMenuInitWindows(void);
static void BuyMenuInitGrid(void);
static bool8 BuyMenuInitSprites(void);
static void BuyMenuDecompressBgGraphics(void);
static void BuyMenuPrint(u8 windowId, const u8 *text, u8 x, u8 y, s8 speed, u8 colorSet, bool32 copy);
static void Task_ExitBuyMenu(u8 taskId);
static void BuyMenuTryMakePurchase(u8 taskId);
static void BuyMenuReturnToItemList(u8 taskId);
static void Task_BuyHowManyDialogueInit(u8 taskId);
static void BuyMenuConfirmPurchase(u8 taskId);
static void BuyMenuPrintItemQuantityAndPrice(u8 taskId);
static void Task_BuyHowManyDialogueHandleInput(u8 taskId);
static void BuyMenuSubtractMoney(u8 taskId);
static void RecordItemPurchase(u8 taskId);
static void Task_ReturnToItemListAfterItemPurchase(u8 taskId);
#ifdef MUDSKIP_OUTFIT_SYSTEM
static void Task_ReturnToItemListAfterOutfitPurchase(u8 taskId);
#endif // MUDSKIP_OUTFIT_SYSTEM
static void Task_ReturnToItemListAfterDecorationPurchase(u8 taskId);
static void Task_HandleShopMenuBuy(u8 taskId);
static void Task_HandleShopMenuSell(u8 taskId);
static void PrintMoneyLocal(u8 windowId, u8 y, u32 amount, u8 width, u8 colorIdx, bool32 copy);
static void UpdateItemData(void);
static void Task_ReturnToItemListWaitMsg(u8 taskId);

static const u8 sGridPosX[] = { (120 + 16), (160 + 16), (200 + 16) };
static const u8 sGridPosY[] = { (24 + 16), (64 + 16) };

static const struct YesNoFuncTable sShopPurchaseYesNoFuncs =
{
    BuyMenuTryMakePurchase,
    BuyMenuReturnToItemList
};

static const struct MenuAction sShopMenuActions_BuySellQuit[] =
{
    { gText_ShopBuy, {.void_u8=Task_HandleShopMenuBuy} },
    { gText_ShopSell, {.void_u8=Task_HandleShopMenuSell} },
    { gText_ShopQuit, {.void_u8=Task_HandleShopMenuQuit} }
};

static const struct MenuAction sShopMenuActions_BuyQuit[] =
{
    { gText_ShopBuy, {.void_u8=Task_HandleShopMenuBuy} },
    { gText_ShopQuit, {.void_u8=Task_HandleShopMenuQuit} }
};

static const struct WindowTemplate sShopMenuWindowTemplates[] =
{
    [WIN_BUY_SELL_QUIT] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 9,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x0008,
    },
    // Separate shop menu window for decorations, which can't be sold
    [WIN_BUY_QUIT] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 9,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x0008,
    }
};

static const struct BgTemplate sShopBuyMenuBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate sShopBuyMenuWindowTemplates[] =
{
    [WIN_MONEY] = {
        .bg = 0,
        .tilemapLeft = 19,
        .tilemapTop = 0,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x001E,
    },
    [WIN_MULTI] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 13,
        .width = 10,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x0032,
    },
    [WIN_ITEM_DESCRIPTION] = {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 13,
        .width = 14,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x0122,
    },
    [WIN_QUANTITY_PRICE] = {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 14,
        .width = 8,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x018E,
    },
    [WIN_MUGSHOT] = {
        .bg = 1,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 13,
        .height = 12,
        .paletteNum = 1,
        .baseBlock = 1,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sShopBuyMenuYesNoWindowTemplates =
{
    .bg = 0,
    .tilemapLeft = 24,
    .tilemapTop = 14,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x020E,
};

static const u8 sShopBuyMenuTextColors[][3] =
{
    [COLORID_NORMAL]      = {0, 1, 2},
    [COLORID_BLACK]       = {0, 2, 3},
};

static const struct SpriteSheet sDefaultCursor_SpriteSheet = {
    .data = sNewShopMenu_DefaultCursorGfx,
    .size = 64*64*2,
    .tag = GFXTAG_CURSOR,
};

static const struct CompressedSpritePalette sDefaultCursor_SpritePalette = {
    .data = sNewShopMenu_DefaultMenuPal,
    .tag = PALTAG_CURSOR,
};

static const union AnimCmd sCursorAnim[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sCursorAnims[] = { sCursorAnim };

static const struct OamData sCursor_SpriteOamData = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 1,
};

static const struct SpriteTemplate sCursor_SpriteTemplate = {
    .tileTag = GFXTAG_CURSOR,
    .paletteTag = PALTAG_CURSOR,
    .callback = SpriteCallbackDummy,
    .anims = sCursorAnims,
    .affineAnims = gDummySpriteAffineAnimTable,
    .images = NULL,
    .oam = &sCursor_SpriteOamData,
};

static const struct Seller sSellers[] = {
    [SELLER_JERRY] = {
        { .gfxId = OBJ_EVENT_GFX_MART_EMPLOYEE },
        .mugshotGfx = sNewShopMenu_SellerMugshotGfx_Jerry,
        .mugshotPal = sNewShopMenu_SellerMugshotPal_Jerry,
        .menuGfx = sNewShopMenu_SellerMenuGfx_Jerry,
        .menuPal = sNewShopMenu_SellerMenuPal_Jerry,
        .menuMap = sNewShopMenu_SellerMenuMap_Jerry,
        .scrollGfx = sNewShopMenu_SellerScrollGfx_Jerry,
        .scrollPal = sNewShopMenu_SellerScrollPal_Jerry,
        .scrollMap = sNewShopMenu_SellerScrollMap_Jerry,
        .cursorGfx = sNewShopMenu_SellerCursorGfx_Jerry,
        .cursorPal = sNewShopMenu_SellerCursorPal_Jerry,
    },
    [SELLER_JENNIE] = {
        { .gfxId = OBJ_EVENT_GFX_WOMAN_3 },
        .mugshotGfx = sNewShopMenu_SellerMugshotGfx_Jennie,
        .mugshotPal = sNewShopMenu_SellerMugshotPal_Jennie,
        .menuGfx = sNewShopMenu_SellerMenuGfx_Jennie,
        .menuPal = sNewShopMenu_SellerMenuPal_Jennie,
        .menuMap = sNewShopMenu_SellerMenuMap_Jennie,
        .scrollGfx = sNewShopMenu_SellerScrollGfx_Jennie,
        .scrollPal = sNewShopMenu_SellerScrollPal_Jennie,
        .scrollMap = sNewShopMenu_SellerScrollMap_Jennie,
        .cursorGfx = sNewShopMenu_SellerCursorGfx_Jennie,
        .cursorPal = sNewShopMenu_SellerCursorPal_Jennie,
    },
};

const u8 sText_ThatItemIsSoldOut[] = _("I'm sorry, but\nthat item is\nsold out.{PAUSE_UNTIL_PRESS}");
const u8 sText_Var1CertainlyHowMany[] = _("{STR_VAR_1}?\nCertainly. How\nmany?");
const u8 sText_Var1CertainlyHowMany2[] = _("{STR_VAR_1}?\nCertainly. How\nmany?");
const u8 sText_Var1AndYouWantedVar2[] = _("So you wanted\n{STR_VAR_2} {STR_VAR_1}?\nThat'll be ¥{STR_VAR_3}.");
const u8 sText_Var1IsItThatllBeVar2[] = _("{STR_VAR_1}, is it?\nThat'll be ¥{STR_VAR_2}.\nDo you want it?");
const u8 sText_YouWantedVar1ThatllBeVar2[] = _("You wanted the\n{STR_VAR_1}?\nThat'll be ¥{STR_VAR_2}.");
const u8 sText_ThankYouIllSendItHome[] = _("Thank you!\nI'll send it to\nyour home PC.");
const u8 sText_ThanksIllSendItHome[] = _("Thanks!\nI'll send it to your\nPC at home.");
const u8 sText_YouDontHaveMoney[] = _("You don't have\nenough money.{PAUSE_UNTIL_PRESS}");
const u8 sText_NoMoreRoomForThis[] = _("You have no more\nroom for this\nitem.{PAUSE_UNTIL_PRESS}");
const u8 sText_SpaceForVar1Full[] = _("The space for\n{STR_VAR_1}\nis full.{PAUSE_UNTIL_PRESS}");
const u8 sText_ThrowInPremierBall[] = _("I'll throw in\na PREMIER BALL,\ntoo.{PAUSE_UNTIL_PRESS}");
const u8 sText_ThrowInPremierBalls[] = _("I'll throw in\n{STR_VAR_1} PREMIER BALLS,\ntoo.{PAUSE_UNTIL_PRESS}");

static u8 CreateShopMenu(u8 martType)
{
    int numMenuItems;

    LockPlayerFieldControls();
    DebugPrintf("lastTalked: %d", gSpecialVar_LastTalked);
    sMartInfo.martType = martType;

    if (martType == MART_TYPE_NORMAL || martType == MART_TYPE_VARIABLE)
    {
        struct WindowTemplate winTemplate = sShopMenuWindowTemplates[WIN_BUY_SELL_QUIT];
        winTemplate.width = GetMaxWidthInMenuTable(sShopMenuActions_BuySellQuit, ARRAY_COUNT(sShopMenuActions_BuySellQuit));
        sMartInfo.windowId = AddWindow(&winTemplate);
        sMartInfo.menuActions = sShopMenuActions_BuySellQuit;
        numMenuItems = ARRAY_COUNT(sShopMenuActions_BuySellQuit);
    }
    else
    {
        struct WindowTemplate winTemplate = sShopMenuWindowTemplates[WIN_BUY_QUIT];
        winTemplate.width = GetMaxWidthInMenuTable(sShopMenuActions_BuyQuit, ARRAY_COUNT(sShopMenuActions_BuyQuit));
        sMartInfo.windowId = AddWindow(&winTemplate);
        sMartInfo.menuActions = sShopMenuActions_BuyQuit;
        numMenuItems = ARRAY_COUNT(sShopMenuActions_BuyQuit);
    }

    SetStandardWindowBorderStyle(sMartInfo.windowId, FALSE);
    PrintMenuTable(sMartInfo.windowId, numMenuItems, sMartInfo.menuActions);
    InitMenuInUpperLeftCornerNormal(sMartInfo.windowId, numMenuItems, 0);
    PutWindowTilemap(sMartInfo.windowId);
    CopyWindowToVram(sMartInfo.windowId, COPYWIN_MAP);

    return CreateTask(Task_ShopMenu, 8);
}

static void SetShopMenuCallback(void (* callback)(void))
{
    sMartInfo.callback = callback;
}

static void SetShopItemsForSale(const u16 *items)
{
    u32 i = 0;

    sMartInfo.itemSource = items;
    sMartInfo.itemCount = 0;

    // Read items until ITEM_NONE / DECOR_NONE is reached
    while (items[i])
    {
        DebugPrintf("SetShopItemsForSale \n"
                                    "       loop item: %d    loop idx: %d", items[i], i);
        sMartInfo.itemCount++;
        i++;

        if (sMartInfo.martType == MART_TYPE_VARIABLE)
            i++;
    }
    sMartInfo.itemCount++; // for ITEM_NONE / DECOR_NONE
    DebugPrintf("SetShopItemsForSale \n"
                                "       end item: %d    end idx: %d", items[i], i);
}

static void InitShopItemsForSale(void)
{
    u32 i = 0, j = 0;
    u16 *itemList;
    u16 *itemPriceList;

    sMartInfo.itemList = AllocZeroed(sMartInfo.itemCount * sizeof(u16));
    sMartInfo.itemPriceList = AllocZeroed(sMartInfo.itemCount * sizeof(u16));

    itemList = (sMartInfo.itemList);
    itemPriceList = (sMartInfo.itemPriceList);

    while (sMartInfo.itemSource[i])
    {
        *itemList = sMartInfo.itemSource[i];
        DebugPrintf("InitShopItemsForSale \n"
                                    "       loop item source: %d    loop item list: %d",
                                    sMartInfo.itemSource[i], sMartInfo.itemList[j]);
        i++;
        itemList++;
        j++;

        if (sMartInfo.martType == MART_TYPE_VARIABLE)
        {
            *itemPriceList = sMartInfo.itemSource[i];
            DebugPrintf("InitShopItemsForSale \n"
                                        "       loop price source: %d    loop price list: %d",
                                        sMartInfo.itemSource[i], sMartInfo.itemPriceList[j]);
            i++;
            itemPriceList++;
        }
    }

    *itemList = ITEM_NONE;
    *itemPriceList = ITEM_NONE;
    DebugPrintf("InitShopItemsForSale \n"
                                "       end item source: %d    end item list: %d    end price list: %d",
                                sMartInfo.itemSource[i], sMartInfo.itemList[j], sMartInfo.itemPriceList[j]);
}

static u32 SearchItemListForPrice(u32 itemId)
{
    u32 i;
    u16 *itemList = sMartInfo.itemList;
    u16 *itemPriceList = sMartInfo.itemPriceList;

    for (i = 0; i < sMartInfo.itemCount; i++)
    {
        DebugPrintf("SearchItemListForPrice \n"
                                    "       loop item list: %d    loop cost list: %d",
                                    sMartInfo.itemList[i], sMartInfo.itemPriceList[i]);
        if (*itemList == itemId)
        {
            return *itemPriceList;
        }

        itemList++;
        itemPriceList++;
    }

    return 0;
}

static void Task_ShopMenu(u8 taskId)
{
    s8 inputCode = Menu_ProcessInputNoWrap();
    switch (inputCode)
    {
    case MENU_NOTHING_CHOSEN:
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        Task_HandleShopMenuQuit(taskId);
        break;
    default:
        sMartInfo.menuActions[inputCode].func.void_u8(taskId);
        break;
    }
}

#define tItemCount  data[1]
#define tCallbackHi data[8]
#define tCallbackLo data[9]

static void Task_HandleShopMenuBuy(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    tCallbackHi = (u32)CB2_InitBuyMenu >> 16;
    tCallbackLo = (u32)CB2_InitBuyMenu;
    gTasks[taskId].func = Task_GoToBuyOrSellMenu;
    FadeScreen(FADE_TO_BLACK, 0);
}

static void Task_HandleShopMenuSell(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    tCallbackHi = (u32)CB2_GoToSellMenu >> 16;
    tCallbackLo = (u32)CB2_GoToSellMenu;
    gTasks[taskId].func = Task_GoToBuyOrSellMenu;
    FadeScreen(FADE_TO_BLACK, 0);
}

void CB2_ExitSellNewShopMenu(void)
{
    gFieldCallback = MapPostLoadHook_ReturnToShopMenu;
    SetMainCallback2(CB2_ReturnToField);
}

static void Task_HandleShopMenuQuit(u8 taskId)
{
    ClearStdWindowAndFrameToTransparent(sMartInfo.windowId, COPYWIN_FULL);
    RemoveWindow(sMartInfo.windowId);
    TryPutSmartShopperOnAir();
    UnlockPlayerFieldControls();
    DestroyTask(taskId);

    if (sMartInfo.callback)
        sMartInfo.callback();

    DebugPrintf("Task_HandleShopMenuQuit");
}

static void Task_GoToBuyOrSellMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        SetMainCallback2((void *)((u16)tCallbackHi << 16 | (u16)tCallbackLo));
    }
}

static void MapPostLoadHook_ReturnToShopMenu(void)
{
    FadeInFromBlack();
    CreateTask(Task_ReturnToShopMenu, 8);
}

static void Task_ReturnToShopMenu(u8 taskId)
{
    if (IsWeatherNotFadingIn() == TRUE)
    {
        if (sMartInfo.martType == MART_TYPE_DECOR2)
            DisplayItemMessageOnField(taskId, gText_CanIHelpWithAnythingElse, ShowShopMenuAfterExitingBuyOrSellMenu);
        else
            DisplayItemMessageOnField(taskId, gText_AnythingElseICanHelp, ShowShopMenuAfterExitingBuyOrSellMenu);
    }
}

static void ShowShopMenuAfterExitingBuyOrSellMenu(u8 taskId)
{
    CreateShopMenu(sMartInfo.martType);
    DestroyTask(taskId);
}

static void CB2_BuyMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB_BuyMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ChangeBgX(3, 96, BG_COORD_SUB);
}

static void Task_BuyMenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_BuyMenu;
}

static void CB2_InitBuyMenu(void)
{
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
        ResetVramOamAndBgCntRegs();
        SetVBlankHBlankCallbacksToNull();
        CpuFastFill(0, (void *)OAM, OAM_SIZE);
        ScanlineEffect_Stop();
        ResetTempTileDataBuffers();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        ClearScheduledBgCopiesToVram();
        sShopData = AllocZeroed(sizeof(struct ShopData));
        InitShopItemsForSale();
        BuyMenuInitBgs();
        BuyMenuInitGrid();
        BuyMenuInitWindows();
        BuyMenuDecompressBgGraphics();
        gMain.state++;
        break;
    case 1:
        if (BuyMenuInitSprites())
            gMain.state++;
        break;
    case 2:
        if (!FreeTempTileDataBuffersIfPossible())
            gMain.state++;
        break;
    default:
        BuyMenuDrawGraphics();
        CreateTask(Task_BuyMenuWaitFadeIn, 8);
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB_BuyMenu);
        SetMainCallback2(CB2_BuyMenu);
        break;
    }
}

static void BuyMenuFreeMemory(void)
{
    GridMenu_Destroy(sShopData->gridItems);
    Free(sShopData);
    // they're better freed here since
    // this is only used in the buy menu
    Free(sMartInfo.itemPriceList);
    Free(sMartInfo.itemList);
    FreeAllWindowBuffers();
}

static void ForEachCB_PopulateItemIcons(u32 idx, u32 col, u32 row)
{
    u32 i = sShopData->gridItems->topLeftItemIndex + idx;
    if (i >= sMartInfo.itemCount)
        return;

    if (sMartInfo.martType == MART_TYPE_NORMAL || sMartInfo.martType == MART_TYPE_VARIABLE)
    {
        if (sMartInfo.itemList[i] == ITEM_NONE)
            sShopData->gridItems->iconSpriteIds[idx] = AddItemIconSprite(GFXTAG_ITEM + idx, PALTAG_ITEM + idx, ITEM_LIST_END);
        else
            sShopData->gridItems->iconSpriteIds[idx] = AddItemIconSprite(GFXTAG_ITEM + idx, PALTAG_ITEM + idx, sMartInfo.itemList[i]);

        gSprites[sShopData->gridItems->iconSpriteIds[idx]].x = ((col % 3) < ARRAY_COUNT(sGridPosX)) ? sGridPosX[col] : sGridPosX[0];
        gSprites[sShopData->gridItems->iconSpriteIds[idx]].y = ((row % 2) < ARRAY_COUNT(sGridPosY)) ? sGridPosY[row] : sGridPosY[0];
    }
    #ifdef MUDSKIP_OUTFIT_SYSTEM
    else if (sMartInfo.martType == MART_TYPE_OUTFIT)
    {
        //! TODO: Fix coord of this
        u32 x, y;
        u16 gfxId = GetPlayerAvatarGraphicsIdByOutfitStateIdAndGender(sMartInfo.itemList[i], PLAYER_AVATAR_STATE_NORMAL, gSaveBlock2Ptr->playerGender);

        x = (((col % 3) < ARRAY_COUNT(sGridPosX)) ? sGridPosX[col] : sGridPosX[0]) - 40;
        y = (((row % 2) < ARRAY_COUNT(sGridPosY)) ? sGridPosY[row] : sGridPosY[0]) - 36;
        if (sMartInfo.itemList[i] == OUTFIT_NONE) // is 0 as DECOR/ITEM_NONE
            sShopData->gridItems->iconSpriteIds[idx] = AddItemIconSprite(GFXTAG_ITEM + idx, PALTAG_ITEM + idx, ITEM_LIST_END);
        else
            sShopData->gridItems->iconSpriteIds[idx] = CreateObjectGraphicsSprite(gfxId, SpriteCallbackDummy, x, y, 0);

        gSprites[sShopData->gridItems->iconSpriteIds[idx]].x = ((col % 3) < ARRAY_COUNT(sGridPosX)) ? sGridPosX[col] : sGridPosX[0];
        gSprites[sShopData->gridItems->iconSpriteIds[idx]].y = ((row % 2) < ARRAY_COUNT(sGridPosY)) ? sGridPosY[row] : sGridPosY[0];
    }
    #endif // MUDSKIP_OUTFIT_SYSTEM
    else
    {
        u32 x, y;

        x = (((col % 3) < ARRAY_COUNT(sGridPosX)) ? sGridPosX[col] : sGridPosX[0]) - 4;
        y = (((row % 2) < ARRAY_COUNT(sGridPosY)) ? sGridPosY[row] : sGridPosY[0]) - 4;

        if (sMartInfo.itemList[i] == DECOR_NONE) // DECOR_NONE has the same value as ITEM_NONE but this is for clarity
        {
            sShopData->gridItems->iconSpriteIds[idx] = AddItemIconSprite(GFXTAG_ITEM + idx, PALTAG_ITEM + idx, ITEM_LIST_END);
            gSprites[sShopData->gridItems->iconSpriteIds[idx]].x = ((col % 3) < ARRAY_COUNT(sGridPosX)) ? sGridPosX[col] : sGridPosX[0];
            gSprites[sShopData->gridItems->iconSpriteIds[idx]].y = ((row % 2) < ARRAY_COUNT(sGridPosY)) ? sGridPosY[row] : sGridPosY[0];
        }
        else
            sShopData->gridItems->iconSpriteIds[idx] = AddDecorationIconObject(sMartInfo.itemList[i], x, y, 2, GFXTAG_ITEM + idx, PALTAG_ITEM + idx);
    }
}

static void ForAllCB_FreeItemIcons(u32 idx, u32 col, u32 row)
{
    if (sShopData->gridItems->iconSpriteIds[idx] == SPRITE_NONE)
        return;

    if (gSprites[sShopData->gridItems->iconSpriteIds[idx]].inUse)
    {
        FreeSpriteTilesByTag(idx + GFXTAG_ITEM);
        FreeSpritePaletteByTag(idx + PALTAG_ITEM);
        DestroySprite(&gSprites[sShopData->gridItems->iconSpriteIds[idx]]);
    }

    sShopData->gridItems->iconSpriteIds[idx] = SPRITE_NONE;
}

static void InputCB_UpDownScroll(void)
{
    GridMenu_ForAll(sShopData->gridItems, ForAllCB_FreeItemIcons);
    GridMenu_ForEach(sShopData->gridItems, ForEachCB_PopulateItemIcons);
    UpdateItemData();
    if (!IsSEPlaying())
        PlaySE(SE_RG_BAG_CURSOR);
}

static void InputCB_Move(void)
{
    UpdateItemData();
    if (!IsSEPlaying())
        PlaySE(SE_RG_BAG_CURSOR);
}

static void InputCB_Fail(void)
{
    if (!IsSEPlaying())
        PlaySE(SE_BOO);
}

static void BuyMenuInitGrid(void)
{
    sShopData->gridItems = GridMenu_Init(3, 2, sMartInfo.itemCount);
    GridMenu_ForEach(sShopData->gridItems, ForEachCB_PopulateItemIcons);
    // we're doing this so that when the grid menu input function "fails", the item data wont flickers
    // it'll flicker when we call UpdateItemData on the main input task func
    // UPDATE: Not exactly true, it flickers when the printing func always immediately copy to vram
    // for good measure though, i'll keep it.
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_Move, DIRECTION_UP, TYPE_MOVE);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_Move, DIRECTION_DOWN, TYPE_MOVE);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_Move, DIRECTION_LEFT, TYPE_MOVE);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_Move, DIRECTION_RIGHT, TYPE_MOVE);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_Fail, DIRECTION_UP, TYPE_FAIL);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_Fail, DIRECTION_DOWN, TYPE_FAIL);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_Fail, DIRECTION_LEFT, TYPE_FAIL);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_Fail, DIRECTION_RIGHT, TYPE_FAIL);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_UpDownScroll, DIRECTION_UP, TYPE_SCROLL);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_UpDownScroll, DIRECTION_DOWN, TYPE_SCROLL);
}

static void BuyMenuInitBgs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sShopBuyMenuBgTemplates, ARRAY_COUNT(sShopBuyMenuBgTemplates));
    SetBgTilemapBuffer(2, sShopData->tilemapBuffers[0]);
    SetBgTilemapBuffer(3, sShopData->tilemapBuffers[1]);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

static void BuyMenuDecompressBgGraphics(void)
{
    u32 i = sShopData->sellerId;
    if (gSpecialVar_LastTalked == 0 || i == SELLER_NONE)
    {
        DecompressAndCopyTileDataToVram(2, sNewShopMenu_DefaultMenuGfx, 0, 9, 0);
        DecompressAndCopyTileDataToVram(2, sNewShopMenu_DefaultScrollGfx, 0, 0, 0);
        LZDecompressWram(sNewShopMenu_DefaultMenuTilemap, sShopData->tilemapBuffers[0]);
        LZDecompressWram(sNewShopMenu_DefaultScrollTilemap, sShopData->tilemapBuffers[1]);
        LoadCompressedPalette(sNewShopMenu_DefaultMenuPal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        return;
    }
    DecompressAndCopyTileDataToVram(2, sSellers[i].menuGfx ?
                                        sSellers[i].menuGfx :
                                        sNewShopMenu_DefaultMenuGfx, 0, 9, 0);

    DecompressAndCopyTileDataToVram(2, sSellers[i].scrollGfx ?
                                        sSellers[i].scrollGfx :
                                        sNewShopMenu_DefaultScrollGfx, 0, 0, 0);

    LZDecompressWram(sSellers[i].menuMap ?
                        sSellers[i].menuMap :
                        sNewShopMenu_DefaultMenuTilemap, sShopData->tilemapBuffers[0]);

    LZDecompressWram(sSellers[i].scrollMap ?
                        sSellers[i].scrollMap :
                        sNewShopMenu_DefaultScrollTilemap, sShopData->tilemapBuffers[1]);

    LoadCompressedPalette(sSellers[i].menuPal ?
                        sSellers[i].menuPal :
                        sNewShopMenu_DefaultMenuPal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);

    if (sSellers[i].useScrollPal == TRUE)
    {
        LoadCompressedPalette(sSellers[i].scrollPal ?
                                sSellers[i].scrollPal :
                                sNewShopMenu_DefaultMenuPal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
    }
}

static inline void SpawnWindow(u8 winId)
{
    FillWindowPixelBuffer(winId, 0);
    PutWindowTilemap(winId);
    CopyWindowToVram(winId, COPYWIN_FULL);
}

static inline const u8 *BuyMenuGetItemName(u32 id)
{
    if (sMartInfo.martType == MART_TYPE_NORMAL || sMartInfo.martType == MART_TYPE_VARIABLE)
        return ItemId_GetName(sMartInfo.itemList[id]);
    #ifdef MUDSKIP_OUTFIT_SYSTEM
    else if (sMartInfo.martType == MART_TYPE_OUTFIT)
        return gOutfits[sMartInfo.itemList[id]].name;
    #endif // MUDSKIP_OUTFIT_SYSTEM
    else
        return gDecorations[sMartInfo.itemList[id]].name;
}

static inline const u8 *BuyMenuGetItemDesc(u32 id)
{
    if (sMartInfo.martType == MART_TYPE_NORMAL || sMartInfo.martType == MART_TYPE_VARIABLE)
        return ItemId_GetDescription(sMartInfo.itemList[id]);
    #ifdef MUDSKIP_OUTFIT_SYSTEM
    else if (sMartInfo.martType == MART_TYPE_OUTFIT)
        return gOutfits[sMartInfo.itemList[id]].desc;
    #endif // MUDSKIP_OUTFIT_SYSTEM
    else
        return gDecorations[sMartInfo.itemList[id]].description;
}

static inline u32 BuyMenuGetItemPrice(u32 id)
{
    if (sMartInfo.martType == MART_TYPE_NORMAL)
        return ItemId_GetPrice(sMartInfo.itemList[id]);
    else if (sMartInfo.martType == MART_TYPE_VARIABLE)
        return SearchItemListForPrice(sMartInfo.itemList[id]);
    #ifdef MUDSKIP_OUTFIT_SYSTEM
    else if (sMartInfo.martType == MART_TYPE_OUTFIT)
        return GetOutfitPrice(sMartInfo.itemList[id]);
    #endif // MUDSKIP_OUTFIT_SYSTEM
    else
        return gDecorations[sMartInfo.itemList[id]].price;
}

static void LoadSellerMugshot(const u8 *gfx, const u16 *pal)
{
    CopyToWindowPixelBuffer(WIN_MUGSHOT, gfx, 4992, 0);
    LoadPalette(pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
    PutWindowTilemap(WIN_MUGSHOT);
    CopyWindowToVram(WIN_MUGSHOT, COPYWIN_FULL);
}

static void SetupSellerMugshot(void)
{
    u32 i;
    u32 objId = GetObjectEventIdByLocalIdAndMap(gSpecialVar_LastTalked,
                                                    gSaveBlock1Ptr->location.mapNum,
                                                    gSaveBlock1Ptr->location.mapGroup);
    u32 gfxId = gObjectEvents[objId].graphicsId;

    if (gfxId >= OBJ_EVENT_GFX_VAR_0 && gfxId <= OBJ_EVENT_GFX_VAR_F)
    {
        gfxId = VarGetObjectEventGraphicsId(gfxId);
    }

    if (gSpecialVar_LastTalked == 0) // failsafe
    {
        LoadSellerMugshot(sNewShopMenu_SellerMugshotGfx_Jerry, sNewShopMenu_SellerMugshotPal_Jerry);
        sShopData->sellerId = SELLER_NONE;
        return;
    }

    // loop over all of the sellers
    for (i = SELLER_NONE; i < SELLER_COUNT; i++)
    {
        if (gfxId == sSellers[i].id.gfxId)
        {
            if (sSellers[i].mugshotGfx != NULL || sSellers[i].mugshotPal != NULL)
            {
                LoadSellerMugshot(sSellers[i].mugshotGfx, sSellers[i].mugshotPal);
            }
            else
            {
                LoadSellerMugshot(sNewShopMenu_SellerMugshotGfx_Jerry, sNewShopMenu_SellerMugshotPal_Jerry);
            }
            sShopData->sellerId = i;
            return;
        }
    }
}

// credit to Vexx on PRET Discord
static void FormatTextByWidth(u8 *result, s32 maxWidth, u8 fontId, const u8 *str, s16 letterSpacing)
{
    u8 *end, *ptr, *curLine, *lastSpace;

    end = result;
    // copy string, replacing all space and line breaks with EOS
    while (*str != EOS) 
    {
        if (*str == CHAR_SPACE || *str == CHAR_NEWLINE) 
            *end = EOS;
        else 
            *end = *str;

        end++;
        str++;
    }
    *end = EOS; // now end points to the true end of the string

    ptr = result;
    curLine = ptr;

    while (*ptr != EOS)
        ptr++;
    // now ptr is the first EOS char

    while (ptr != end) 
    {
        // all the EOS chars (except *end) must be replaced by either ' ' or '\n'
        lastSpace = ptr++; // this points at the EOS

        // check that adding the next word this line still fits
        *lastSpace = CHAR_SPACE;
        if (GetStringWidth(fontId, curLine, letterSpacing) > maxWidth) 
        {
            *lastSpace = CHAR_NEWLINE;

            curLine = ptr;
        }

        while (*ptr != EOS) 
            ptr++;
        // now ptr is the next EOS char
    }
}

static void BuyMenuInitWindows(void)
{
    const u8 *name = BuyMenuGetItemName(0), *desc = BuyMenuGetItemDesc(0);
    u32 price = BuyMenuGetItemPrice(0);

    InitWindows(sShopBuyMenuWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(WIN_MONEY, 1, BG_PLTT_ID(13));
    LoadMessageBoxGfx(WIN_MONEY, 0xA, BG_PLTT_ID(14));

    SpawnWindow(WIN_MONEY);
    SpawnWindow(WIN_MUGSHOT);
    SpawnWindow(WIN_ITEM_DESCRIPTION);

    BuyMenuPrint(WIN_MULTI, name, 0, 0, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
    BuyMenuPrint(WIN_MULTI, COMPOUND_STRING("PRICE"), 0, 2*8, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
    BuyMenuPrint(WIN_MULTI, COMPOUND_STRING("IN BAG"), 0, 4*8, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);

    if (sMartInfo.martType == MART_TYPE_NORMAL || sMartInfo.martType == MART_TYPE_VARIABLE)
    {
        u32 item = sMartInfo.itemList[0];
        u16 quantity = CountTotalItemQuantityInBag(item);
        if (ItemId_GetPocket(item) == POCKET_TM_HM)
        {
            const u8 *move = GetMoveName(ItemIdToBattleMoveId(item));
            FormatTextByWidth(gStringVar2, 80, FONT_SMALL, ItemId_GetDescription(sMartInfo.itemList[0]), 0);
            desc = gStringVar2;
            BuyMenuPrint(WIN_MULTI, move, GetStringRightAlignXOffset(FONT_SMALL, move, 80), 0, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
        }

        if (ItemId_GetImportance(item) && (CheckBagHasItem(item, 1) || CheckPCHasItem(item, 1)))
            BuyMenuPrint(WIN_MULTI, gText_SoldOut, GetStringRightAlignXOffset(FONT_SMALL, gText_SoldOut, 80), 2*8, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
        else
            PrintMoneyLocal(WIN_MULTI, 2*8, price, 84, COLORID_BLACK, FALSE);

        ConvertIntToDecimalStringN(gStringVar3, quantity, STR_CONV_MODE_RIGHT_ALIGN, 4);
        BuyMenuPrint(WIN_MULTI, gStringVar3, GetStringRightAlignXOffset(FONT_SMALL, gStringVar3, 80), 4*8, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
    }
    else
    {
        PrintMoneyLocal(WIN_MULTI, 2*8, price, 84, COLORID_BLACK, FALSE);
    }
    CopyWindowToVram(WIN_MULTI, COPYWIN_FULL);
    FillWindowPixelBuffer(WIN_ITEM_DESCRIPTION, PIXEL_FILL(0));
    FormatTextByWidth(gStringVar2, 80, FONT_SMALL, desc, 0);
    BuyMenuPrint(WIN_ITEM_DESCRIPTION, gStringVar2, 4, 0, TEXT_SKIP_DRAW, COLORID_BLACK, TRUE);
    SetupSellerMugshot();
}

static bool32 LoadSellerCursor(void)
{
    u32 i = sShopData->sellerId;
    struct SpriteSheet gfx = {
        .data = sSellers[i].cursorGfx ? sSellers[i].cursorGfx : sNewShopMenu_DefaultCursorGfx,
        .size = 64*64*2,
        .tag = GFXTAG_CURSOR,
    };
    struct CompressedSpritePalette pal = {
        .data = sSellers[i].cursorPal ? sSellers[i].cursorPal : sNewShopMenu_DefaultMenuPal,
        .tag = PALTAG_CURSOR
    };

    if (gSpecialVar_LastTalked == 0 || i == 0)
    {
        LoadSpriteSheet(&sDefaultCursor_SpriteSheet);
        LoadCompressedSpritePalette(&sDefaultCursor_SpritePalette);
        return FALSE;
    }

    LoadSpriteSheet(&gfx);
    LoadCompressedSpritePalette(&pal);
    return TRUE;
}

static bool8 BuyMenuInitSprites(void)
{
    switch (sShopData->gfxLoadState)
    {
    case 0:
        LoadSellerCursor();
        sShopData->gfxLoadState++;
        break;
    case 1:
        sShopData->cursorSpriteId = CreateSprite(&sCursor_SpriteTemplate, CURSOR_START_X, CURSOR_START_Y, 0);
        StartSpriteAnim(&gSprites[sShopData->cursorSpriteId], 0);
        sShopData->gfxLoadState++;
        break;
    case 2:
        sShopData->gfxLoadState = 0;
        return TRUE;
        break;
    }
    return FALSE;
}

static void BuyMenuPrint(u8 windowId, const u8 *text, u8 x, u8 y, s8 speed, u8 colorSet, bool32 copy)
{
    AddTextPrinterParameterized4(windowId, FONT_SMALL, x, y, 0, 0, sShopBuyMenuTextColors[colorSet], speed, text);
    PutWindowTilemap(windowId);
    if (copy)
        CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void PrintMoneyLocal(u8 windowId, u8 y, u32 amount, u8 width, u8 colorIdx, bool32 copy)
{
    u8 *txtPtr;
    s32 strLength;
    s32 x;

    ConvertIntToDecimalStringN(gStringVar1, amount, STR_CONV_MODE_RIGHT_ALIGN, 6);

    strLength = 6 - StringLength(gStringVar1);
    txtPtr = gStringVar4;

    while (strLength-- > 0)
        *(txtPtr++) = CHAR_SPACER;

    StringExpandPlaceholders(txtPtr, gText_PokedollarVar1);
    x = GetStringRightAlignXOffset(FONT_NORMAL, txtPtr, width);
    AddTextPrinterParameterized4(windowId, FONT_SMALL, x, y, 0, 0, sShopBuyMenuTextColors[colorIdx], TEXT_SKIP_DRAW, gStringVar4);
    PutWindowTilemap(windowId);
    if (copy)
        CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void BuyMenuDrawGraphics(void)
{
    PrintMoneyLocal(WIN_MONEY, 0, GetMoney(&gSaveBlock1Ptr->money), 84, COLORID_NORMAL, TRUE);
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);
}

static void UpdateItemData(void)
{
    const u8 strip[] = _("-");
    if (GridMenu_SelectedIndex(sShopData->gridItems) >= sMartInfo.itemCount)
        return;

    FillWindowPixelRect(WIN_MULTI, PIXEL_FILL(0), 0, 0, 84, 16);
    FillWindowPixelRect(WIN_MULTI, PIXEL_FILL(0), 34, 1*8, 84, 40);
    if (sMartInfo.itemList[GridMenu_SelectedIndex(sShopData->gridItems)] == ITEM_NONE)
    {
        FillWindowPixelRect(WIN_MULTI, PIXEL_FILL(0), 0, 0, 84, 16);
        BuyMenuPrint(WIN_MULTI, COMPOUND_STRING("Return to Field"), 0, 0, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
        BuyMenuPrint(WIN_MULTI, strip, GetStringRightAlignXOffset(FONT_SMALL, strip, 80), 2*8, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);

        if (sMartInfo.martType == MART_TYPE_NORMAL || sMartInfo.martType == MART_TYPE_VARIABLE)
            BuyMenuPrint(WIN_MULTI, strip, GetStringRightAlignXOffset(FONT_SMALL, strip, 80), 4*8, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);

        FillWindowPixelBuffer(WIN_ITEM_DESCRIPTION, PIXEL_FILL(0));
        BuyMenuPrint(WIN_ITEM_DESCRIPTION, gText_QuitShopping, 4, 0, TEXT_SKIP_DRAW, COLORID_BLACK, TRUE);
    }
    else
    {
        u32 i = GridMenu_SelectedIndex(sShopData->gridItems);
        u32 item = sMartInfo.itemList[i];
        const u8 *desc = BuyMenuGetItemDesc(i);
        BuyMenuPrint(WIN_MULTI, BuyMenuGetItemName(i), 0, 0, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);

        if (sMartInfo.martType == MART_TYPE_NORMAL || sMartInfo.martType == MART_TYPE_VARIABLE)
        {
            u16 quantity = CountTotalItemQuantityInBag(item);
            if (ItemId_GetPocket(item) == POCKET_TM_HM && item != ITEM_NONE)
            {
                const u8 *move = GetMoveName(ItemIdToBattleMoveId(item));
                FormatTextByWidth(gStringVar2, 80, FONT_SMALL, ItemId_GetDescription(sMartInfo.itemList[i]), 0);
                desc = gStringVar2;
                BuyMenuPrint(WIN_MULTI, move, GetStringRightAlignXOffset(FONT_SMALL, move, 80), 0, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
            }

            if (ItemId_GetImportance(item) && (CheckBagHasItem(item, 1) || CheckPCHasItem(item, 1)))
                BuyMenuPrint(WIN_MULTI, gText_SoldOut, GetStringRightAlignXOffset(FONT_SMALL, gText_SoldOut, 80), 2*8, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
            else
                PrintMoneyLocal(WIN_MULTI, 2*8, BuyMenuGetItemPrice(i), 84, COLORID_BLACK, FALSE);

            ConvertIntToDecimalStringN(gStringVar3, quantity, STR_CONV_MODE_RIGHT_ALIGN, 4);
            BuyMenuPrint(WIN_MULTI, gStringVar3, GetStringRightAlignXOffset(FONT_SMALL, gStringVar3, 80), 4*8, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
        }
        else
        {
            PrintMoneyLocal(WIN_MULTI, 2*8, BuyMenuGetItemPrice(i), 84, COLORID_BLACK, FALSE);
        }
        FillWindowPixelBuffer(WIN_ITEM_DESCRIPTION, PIXEL_FILL(0));
        FormatTextByWidth(gStringVar2, 80, FONT_SMALL, desc, 0);
        BuyMenuPrint(WIN_ITEM_DESCRIPTION, gStringVar2, 4, 0, TEXT_SKIP_DRAW, COLORID_BLACK, TRUE);
    }
    CopyWindowToVram(WIN_MULTI, COPYWIN_FULL);
}

static void UpdateCursorPosition(void)
{
    u32 row = sShopData->gridItems->selectedItem / sShopData->gridItems->maxCols;
    u32 col = sShopData->gridItems->selectedItem % sShopData->gridItems->maxCols;
    // 8 because tile is 8px wide/tall, 5 because gridbox is 4 tiles plus 1 empty space
    u32 x = CURSOR_START_X + (col * (8 * 5));
    u32 y = CURSOR_START_Y + (row * (8 * 5));
    gSprites[sShopData->cursorSpriteId].x = x;
    gSprites[sShopData->cursorSpriteId].y = y;
}

static void Task_WaitMessage(u8 taskId)
{
    if (--gTasks[taskId].data[0] == 0)
    {
        UpdateItemData();
        gTasks[taskId].func = Task_BuyMenu;
    }
}

static void BuyMenuDisplayMessage(u8 taskId, const u8 *str, TaskFunc nextFunc)
{
    StringExpandPlaceholders(gStringVar4, str);
    BuyMenuPrint(WIN_ITEM_DESCRIPTION, gStringVar4, 4, 0, TEXT_SKIP_DRAW, COLORID_BLACK, TRUE);
    gTasks[taskId].func = nextFunc;
}

static void Task_BuyMenuTryBuyingItem(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u32 cost = BuyMenuGetItemPrice(GridMenu_SelectedIndex(sShopData->gridItems));
    if (sMartInfo.martType == MART_TYPE_NORMAL || sMartInfo.martType == MART_TYPE_VARIABLE)
        sShopData->totalCost = (cost >> IsPokeNewsActive(POKENEWS_SLATEPORT));
    else
        sShopData->totalCost = cost;

    FillWindowPixelBuffer(WIN_ITEM_DESCRIPTION, PIXEL_FILL(0));

    if (sMartInfo.martType != MART_TYPE_DECOR || sMartInfo.martType != MART_TYPE_DECOR2)
    {
        if (ItemId_GetImportance(sShopData->currentItemId) && (CheckBagHasItem(sShopData->currentItemId, 1) || CheckPCHasItem(sShopData->currentItemId, 1)))
        {
            PlaySE(SE_BOO);
            gTasks[taskId].data[0] = 70;
            BuyMenuDisplayMessage(taskId, sText_ThatItemIsSoldOut, Task_WaitMessage);
            return;
        }
    }

    if (!IsEnoughMoney(&gSaveBlock1Ptr->money, sShopData->totalCost))
    {
        PlaySE(SE_BOO);
        gTasks[taskId].data[0] = 70;
        BuyMenuDisplayMessage(taskId, sText_YouDontHaveMoney, Task_WaitMessage);
    }
    else
    {
        PlaySE(SE_SELECT);
        if (sMartInfo.martType == MART_TYPE_NORMAL || sMartInfo.martType == MART_TYPE_VARIABLE)
        {
            CopyItemName(sShopData->currentItemId, gStringVar1);
            if (ItemId_GetImportance(sShopData->currentItemId))
            {
                u32 price = BuyMenuGetItemPrice(GridMenu_SelectedIndex(sShopData->gridItems));
                ConvertIntToDecimalStringN(gStringVar2, sShopData->totalCost, STR_CONV_MODE_LEFT_ALIGN, 6);
                tItemCount = 1;
                sShopData->totalCost = (price >> IsPokeNewsActive(POKENEWS_SLATEPORT)) * tItemCount;
                BuyMenuDisplayMessage(taskId, sText_YouWantedVar1ThatllBeVar2, BuyMenuConfirmPurchase);
            }
            else if (ItemId_GetPocket(sShopData->currentItemId) == POCKET_TM_HM)
            {
                BuyMenuDisplayMessage(taskId, sText_Var1CertainlyHowMany2, Task_BuyHowManyDialogueInit);
            }
            else
            {
                BuyMenuDisplayMessage(taskId, sText_Var1CertainlyHowMany, Task_BuyHowManyDialogueInit);
            }
        }
        #ifdef MUDSKIP_OUTFIT_SYSTEM
        else if (sMartInfo.martType == MART_TYPE_OUTFIT)
        {
            BufferOutfitStrings(gStringVar1, sShopData->currentItemId, OUTFIT_BUFFER_NAME);
            ConvertIntToDecimalStringN(gStringVar2, sShopData->totalCost, STR_CONV_MODE_LEFT_ALIGN, 6);
            StringExpandPlaceholders(gStringVar4, gText_YouWantedVar1OutfitThatllBeVar2);
            BuyMenuDisplayMessage(taskId, gStringVar4, BuyMenuConfirmPurchase);
        }
        #endif // MUDSKIP_OUTFIT_SYSTEM
        else
        {
            const u8 *str;
            StringCopy(gStringVar1, gDecorations[sShopData->currentItemId].name);
            ConvertIntToDecimalStringN(gStringVar2, sShopData->totalCost, STR_CONV_MODE_LEFT_ALIGN, 6);
            if (sMartInfo.martType == MART_TYPE_DECOR)
                str = sText_Var1IsItThatllBeVar2;
            else // MART_TYPE_DECOR2
                str = sText_YouWantedVar1ThatllBeVar2;

            BuyMenuDisplayMessage(taskId, str, BuyMenuConfirmPurchase);
        }
    }
}

static inline void ExitBuyMenu(u8 taskId)
{
    gFieldCallback = MapPostLoadHook_ReturnToShopMenu;
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_ExitBuyMenu;
}

static void Task_BuyMenu(u8 taskId)
{
    GridMenu_HandleInput(sShopData->gridItems);
    if (JOY_REPEAT(DPAD_ANY))
    {
        DebugPrintf("Chosen item: %d", sMartInfo.itemList[GridMenu_SelectedIndex(sShopData->gridItems)]);
        DebugPrintf("idx: %d", GridMenu_SelectedIndex(sShopData->gridItems));
    }
    else if (JOY_NEW(B_BUTTON))
    {
        ExitBuyMenu(taskId);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        sShopData->currentItemId = sMartInfo.itemList[GridMenu_SelectedIndex(sShopData->gridItems)];
        if (sShopData->currentItemId == ITEM_NONE)
        {
            ExitBuyMenu(taskId);
        }
        else
        {
            gTasks[taskId].func = Task_BuyMenuTryBuyingItem;
        }

    }
    UpdateCursorPosition();
}

static void Task_BuyHowManyDialogueInit(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u16 maxQuantity;

    tItemCount = 1;
    BuyMenuPrintItemQuantityAndPrice(taskId);
    ScheduleBgCopyTilemapToVram(0);

    maxQuantity = GetMoney(&gSaveBlock1Ptr->money) / sShopData->totalCost;

    if (maxQuantity > MAX_BAG_ITEM_CAPACITY)
        sShopData->maxQuantity = MAX_BAG_ITEM_CAPACITY;
    else
        sShopData->maxQuantity = maxQuantity;

    gTasks[taskId].func = Task_BuyHowManyDialogueHandleInput;
}

static void Task_BuyHowManyDialogueHandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, sShopData->maxQuantity) == TRUE)
    {
        u32 price = BuyMenuGetItemPrice(GridMenu_SelectedIndex(sShopData->gridItems));
        sShopData->totalCost = (price >> IsPokeNewsActive(POKENEWS_SLATEPORT)) * tItemCount;
        BuyMenuPrintItemQuantityAndPrice(taskId);
    }
    else
    {
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            ClearWindowTilemap(WIN_QUANTITY_PRICE);
            CopyItemName(sShopData->currentItemId, gStringVar1);
            ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS);
            ConvertIntToDecimalStringN(gStringVar3, sShopData->totalCost, STR_CONV_MODE_LEFT_ALIGN, 6);
            FillWindowPixelBuffer(WIN_ITEM_DESCRIPTION, PIXEL_FILL(0));
            if (tItemCount >= 2)
                CopyItemNameHandlePlural(sShopData->currentItemId, gStringVar1, tItemCount);
            else
                CopyItemName(sShopData->currentItemId, gStringVar1);

            BuyMenuDisplayMessage(taskId, sText_Var1AndYouWantedVar2, BuyMenuConfirmPurchase);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            ClearWindowTilemap(WIN_QUANTITY_PRICE);
            BuyMenuReturnToItemList(taskId);
        }
    }
}

static void BuyMenuConfirmPurchase(u8 taskId)
{
    CreateYesNoMenuWithCallbacks(taskId, &sShopBuyMenuYesNoWindowTemplates, 1, 0, 0, 1, 13, &sShopPurchaseYesNoFuncs);
}

static void BuyMenuTryMakePurchase(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    FillWindowPixelBuffer(WIN_ITEM_DESCRIPTION, PIXEL_FILL(0));
    if (sMartInfo.martType == MART_TYPE_NORMAL || sMartInfo.martType == MART_TYPE_VARIABLE)
    {
        if (AddBagItem(sShopData->currentItemId, tItemCount) == TRUE)
        {
            RecordItemPurchase(taskId);
            BuyMenuDisplayMessage(taskId, gText_HereYouGoThankYou, BuyMenuSubtractMoney);
        }
        else
        {
            gTasks[taskId].data[0] = 20;
            BuyMenuDisplayMessage(taskId, sText_NoMoreRoomForThis, Task_ReturnToItemListWaitMsg);
        }
    }
    #ifdef MUDSKIP_OUTFIT_SYSTEM
    else if (sMartInfo.martType == MART_TYPE_OUTFIT)
    {
        UnlockOutfit(sShopData->currentItemId);
        BuyMenuDisplayMessage(taskId, gText_HereIsTheOutfitThankYou, BuyMenuSubtractMoney);
    }
    #endif // MUDSKIP_OUTFIT_SYSTEM
    else
    {
        if (DecorationAdd(sShopData->currentItemId))
        {
            if (sMartInfo.martType == MART_TYPE_DECOR)
                BuyMenuDisplayMessage(taskId, sText_ThankYouIllSendItHome, BuyMenuSubtractMoney);
            else // MART_TYPE_DECOR2
                BuyMenuDisplayMessage(taskId, sText_ThanksIllSendItHome, BuyMenuSubtractMoney);
        }
        else
        {
            gTasks[taskId].data[0] = 20;
            BuyMenuDisplayMessage(taskId, sText_SpaceForVar1Full, Task_ReturnToItemListWaitMsg);
        }
    }
}

static void BuyMenuSubtractMoney(u8 taskId)
{
    IncrementGameStat(GAME_STAT_SHOPPED);
    RemoveMoney(&gSaveBlock1Ptr->money, sShopData->totalCost);
    PlaySE(SE_SHOP);
    FillWindowPixelBuffer(WIN_MONEY, PIXEL_FILL(0));
    PrintMoneyLocal(WIN_MONEY, 0, GetMoney(&gSaveBlock1Ptr->money), 84, COLORID_NORMAL, TRUE);

    if (sMartInfo.martType == MART_TYPE_NORMAL || sMartInfo.martType == MART_TYPE_VARIABLE)
        gTasks[taskId].func = Task_ReturnToItemListAfterItemPurchase;
    #ifdef MUDSKIP_OUTFIT_SYSTEM
    else if (sMartInfo.martType == MART_TYPE_OUTFIT)
        gTasks[taskId].func = Task_ReturnToItemListAfterOutfitPurchase;
    #endif // MUDSKIP_OUTFIT_SYSTEM
    else
        gTasks[taskId].func = Task_ReturnToItemListAfterDecorationPurchase;
}

// This is hacky but this'd do it
static void Task_ReturnToItemListWaitMsg(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        if (JOY_NEW(A_BUTTON | B_BUTTON))
            BuyMenuReturnToItemList(taskId);
    }
    else
        gTasks[taskId].data[0]--;
}

static void Task_ReturnToItemListAfterItemPurchase(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        u16 premierBallsToAdd = tItemCount / 10;

        if (premierBallsToAdd >= 1
         && ((I_PREMIER_BALL_BONUS <= GEN_7 && sShopData->currentItemId == ITEM_POKE_BALL)
          || (I_PREMIER_BALL_BONUS >= GEN_8 && (ItemId_GetPocket(sShopData->currentItemId) == POCKET_POKE_BALLS))))
        {
            u32 spaceAvailable = GetFreeSpaceForItemInBag(ITEM_PREMIER_BALL);
            if (spaceAvailable < premierBallsToAdd)
                premierBallsToAdd = spaceAvailable;
        }
        else
        {
            premierBallsToAdd = 0;
        }

        if (gTasks[taskId].data[0] != 20)
            PlaySE(SE_SELECT);

        AddBagItem(ITEM_PREMIER_BALL, premierBallsToAdd);
        if (premierBallsToAdd > 0)
        {
            FillWindowPixelBuffer(WIN_ITEM_DESCRIPTION, PIXEL_FILL(0));
            ConvertIntToDecimalStringN(gStringVar1, premierBallsToAdd, STR_CONV_MODE_LEFT_ALIGN, MAX_ITEM_DIGITS);
            StringExpandPlaceholders(gStringVar2, (premierBallsToAdd >= 2 ? sText_ThrowInPremierBalls : sText_ThrowInPremierBall));
            BuyMenuPrint(WIN_ITEM_DESCRIPTION, gStringVar2, 4, 0, TEXT_SKIP_DRAW, COLORID_BLACK, TRUE);
        }
        gTasks[taskId].data[0] = 20;
        gTasks[taskId].func = Task_ReturnToItemListWaitMsg;
    }
}

#ifdef MUDSKIP_OUTFIT_SYSTEM
static void Task_ReturnToItemListAfterOutfitPurchase(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BuyMenuReturnToItemList(taskId);
    }
}
#endif // MUDSKIP_OUTFIT_SYSTEM

static void Task_ReturnToItemListAfterDecorationPurchase(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BuyMenuReturnToItemList(taskId);
    }
}

static void BuyMenuReturnToItemList(u8 taskId)
{
    UpdateItemData();
    gTasks[taskId].func = Task_BuyMenu;
}

static void BuyMenuPrintItemQuantityAndPrice(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    FillWindowPixelBuffer(WIN_QUANTITY_PRICE, PIXEL_FILL(0));
    PrintMoneyLocal(WIN_QUANTITY_PRICE, 13, sShopData->totalCost, 56, COLORID_BLACK, FALSE);
    ConvertIntToDecimalStringN(gStringVar1, tItemCount, STR_CONV_MODE_LEADING_ZEROS, MAX_ITEM_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    BuyMenuPrint(WIN_QUANTITY_PRICE, gStringVar4, 29, 3, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
    CopyWindowToVram(WIN_QUANTITY_PRICE, COPYWIN_FULL);
}

static void Task_ExitBuyMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        BuyMenuFreeMemory();
        SetMainCallback2(CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

static void ClearItemPurchases(void)
{
    sPurchaseHistoryId = 0;
    memset(gMartPurchaseHistory, 0, sizeof(gMartPurchaseHistory));
}

static void RecordItemPurchase(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u16 i;

    for (i = 0; i < ARRAY_COUNT(gMartPurchaseHistory); i++)
    {
        if (gMartPurchaseHistory[i].itemId == sShopData->currentItemId && gMartPurchaseHistory[i].quantity != 0)
        {
            if (gMartPurchaseHistory[i].quantity + tItemCount > 255)
                gMartPurchaseHistory[i].quantity = 255;
            else
                gMartPurchaseHistory[i].quantity += tItemCount;
            return;
        }
    }

    if (sPurchaseHistoryId < ARRAY_COUNT(gMartPurchaseHistory))
    {
        gMartPurchaseHistory[sPurchaseHistoryId].itemId = sShopData->currentItemId;
        gMartPurchaseHistory[sPurchaseHistoryId].quantity = tItemCount;
        sPurchaseHistoryId++;
    }
}

#undef tItemCount
#undef tCallbackHi
#undef tCallbackLo

void NewShop_CreatePokemartMenu(const u16 *itemsForSale)
{
    CreateShopMenu(MART_TYPE_NORMAL);
    SetShopItemsForSale(itemsForSale);
    ClearItemPurchases();
    SetShopMenuCallback(ScriptContext_Enable);
}

void NewShop_CreateDecorationShop1Menu(const u16 *itemsForSale)
{
    CreateShopMenu(MART_TYPE_DECOR);
    SetShopItemsForSale(itemsForSale);
    SetShopMenuCallback(ScriptContext_Enable);
}

void NewShop_CreateDecorationShop2Menu(const u16 *itemsForSale)
{
    CreateShopMenu(MART_TYPE_DECOR2);
    SetShopItemsForSale(itemsForSale);
    SetShopMenuCallback(ScriptContext_Enable);
}

#ifdef MUDSKIP_OUTFIT_SYSTEM
void NewShop_CreateOutfitShopMenu(const u16 *itemsForSale)
{
    CreateNewShopMenu(MART_TYPE_OUTFIT);
    SetShopItemsForSale(itemsForSale);
    SetShopMenuCallback(ScriptContext_Enable);
}
#endif // MUDSKIP_OUTFIT_SYSTEM

void NewShop_CreateVariablePokemartMenu(const u16 *itemsForSale)
{
    CreateShopMenu(MART_TYPE_VARIABLE);
    SetShopItemsForSale(itemsForSale);
    ClearItemPurchases();
    SetShopMenuCallback(ScriptContext_Enable);
}

#endif // MUDSKIP_SHOP_UI
