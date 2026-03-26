#include "global.h"
#include "assertf.h"
#include "banking_system.h"
#include "battle_message.h"
#include "config/banking.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "international_string_util.h"
#include "item.h"
#include "main.h"
#include "menu.h"
#include "money.h"
#include "overworld.h"
#include "random.h"
#include "script.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "util.h"
#include "window.h"

// Macros
#define EnsureBankingEnabled()                                              \
    {                                                                       \
        assertf(IsBankingEnabled(),"Banking functionality is not enabled")  \
            {                                                               \
                UnlockPlayerFieldControls();                                \
                return;                                                     \
            }                                                               \
    }

// Config
#define MAX_STEP       1000
#define STEP_SPEED     360
#define MAX_BANK_MONEY 9999999
#define MAX_PENDING    5

// Enums
enum BankingMode
{
    MODE_DEPOSIT,
    MODE_WITHDRAW
};

// Structs
struct UniquePurchaseItem
{
    enum Item itemId;
    u32 thresholdMoney;
    u16 quantity;
    s32 price;
};

struct RepeatPurchaseItem
{
    enum Item itemId;
    s32 quantity;
    s32 price;
};

static const struct UniquePurchaseItem sUniquePurchaseTable[] = {
    {ITEM_NONE},
    {ITEM_SUPER_POTION,  900,   1,  600},
    {ITEM_REPEL,         4000,  1,  270},
    {ITEM_SUPER_POTION,  7000,  1,  600},
    {ITEM_SILK_SCARF,    10000, 1,  100},
    {ITEM_MOON_STONE,    15000, 1, 3000},
    {ITEM_HYPER_POTION,  19000, 1,  900},
    {ITEM_CHOICE_SCARF,  30000, 1,  200},
    {ITEM_MUSCLE_BAND,   40000, 1,  200},
    {ITEM_FOCUS_SASH,    50000, 1,  200},
    {ITEM_NONE}
};

static const struct RepeatPurchaseItem sRepeatPurchaseTable[] = {
    {ITEM_OCCA_BERRY,   5, 100},
    {ITEM_PASSHO_BERRY, 5, 100},
    {ITEM_WACAN_BERRY,  5, 100},
    {ITEM_RINDO_BERRY,  5, 100},
    {ITEM_YACHE_BERRY,  5, 100},
    {ITEM_CHOPLE_BERRY, 5, 100},
    {ITEM_KEBIA_BERRY,  5, 100},
    {ITEM_SHUCA_BERRY,  5, 100},
    {ITEM_COBA_BERRY,   5, 100},
    {ITEM_PAYAPA_BERRY, 5, 100},
    {ITEM_TANGA_BERRY,  5, 100},
    {ITEM_CHARTI_BERRY, 5, 100},
    {ITEM_KASIB_BERRY,  5, 100},
    {ITEM_HABAN_BERRY,  5, 100},
    {ITEM_COLBUR_BERRY, 5, 100},
    {ITEM_BABIRI_BERRY, 5, 100},
    {ITEM_CHILAN_BERRY, 5, 100},
};

// Strings
static const u8 sText_Deposit[] = _("Deposit");
static const u8 sText_Withdraw[] = _("Withdraw");

// Variables
u32 sTransactionAmount = 0;
u8 sTransactionWindowId = 0;
u8 sBankingModeWindowId = 0;

// Static Functions
static u32 GetStepSize(s16 heldFrames);
static bool32 HandleAmountInput(u32 *amount, u32 max, u32 min, s16 *heldFrames);
static u32 GetTransactionMaxAmount(enum BankingMode mode);
static void UpdateBankBalanceAfterTransaction(enum BankingMode mode);

// Tasks
static void Task_ShowBankingInput(u8 taskId);
static void Task_HandleMoneyInput(u8 taskId);

// Windows
static const struct WindowTemplate sSavingsWithdrawalWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 15,
    .tilemapTop = 2,
    .width = 13,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 1};

static const struct WindowTemplate sBankingModeWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 2,
    .width = 7,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 1 + 13 * 2};

bool32 IsBankingEnabled(void)
{
    return SAVINGS_ENABLED;
}

bool32 IsSavingMoney(void)
{
    return IsBankingEnabled() && FlagGet(SAVINGS_FLAG);
}

struct Banking* GetBankingPtr(void)
{
    #if SAVINGS_ENABLED
        return &gSaveBlock3Ptr->banking;
    #else
        return NULL;
    #endif /* if SAVINGS_ENABLED */
    
}

u32 GetMoneyInBank(void)
{
    assertf(IsBankingEnabled(), "Banking functionality is not enabled")
    {
        return 0;
    }

    struct Banking *banking = GetBankingPtr();
    return banking->savings;
}

void SetMoneyInBank(u32 amount)
{

    assertf(IsBankingEnabled(), "Banking functionality is not enabled")
    {
        return;
    }

    struct Banking *banking = GetBankingPtr();
    banking->savings = amount;
}

void NewGameInitBanking(void)
{
    struct Banking *banking = GetBankingPtr();
    SetMoneyInBank(0);
    banking->lastBought = 0;
    banking->deposited = 0;
    banking->isPending = FALSE;
}

void Script_CompareBankBalance(struct ScriptContext *ctx)
{
    EnsureBankingEnabled();

    u32 value = ScriptReadWord(ctx);
    u32 balance = GetMoneyInBank();

    if (value > balance)
        gSpecialVar_Result = FALSE;
    else if (value <= balance)
        gSpecialVar_Result = TRUE;
}

void Script_RemoveFromBank(struct ScriptContext *ctx)
{
    EnsureBankingEnabled();

    u32 amount = ScriptReadWord(ctx);
    u32 balance = GetMoneyInBank();

    if (amount > balance)
    {
        gSpecialVar_Result = FALSE;
        amount = balance;
    }
    else
    {
        gSpecialVar_Result = TRUE;
    }

    SetMoneyInBank(balance - amount);
}

void Script_AddToBank(struct ScriptContext *ctx)
{
    EnsureBankingEnabled();

    u32 amount = ScriptReadWord(ctx);
    u32 balance = GetMoneyInBank();

    gSpecialVar_Result = TRUE;

    u32 newBalance = balance + amount;

    if (newBalance > MAX_BANK_MONEY)
    {
        amount = MAX_BANK_MONEY - balance;
        gSpecialVar_Result = FALSE;
    }

    SetMoneyInBank(balance + amount);
}

void Script_ShowBankBalanceBox(struct ScriptContext *ctx)
{
    EnsureBankingEnabled();

    u8 x = ScriptReadByte(ctx);
    u8 y = ScriptReadByte(ctx);

    Script_RequestEffects(SCREFF_V1 | SCREFF_HARDWARE);

    DrawMoneyBox(GetMoneyInBank(), x, y);
}

void Script_HideBankBalanceBox(struct ScriptContext *ctx)
{
    EnsureBankingEnabled();

    Script_RequestEffects(SCREFF_V1 | SCREFF_HARDWARE);

    HideMoneyBox();
}

void Script_UpdateBankBalanceBox(struct ScriptContext *ctx)
{
    EnsureBankingEnabled();

    Script_RequestEffects(SCREFF_V1 | SCREFF_HARDWARE);
    ChangeAmountInMoneyBox(GetMoneyInBank());
}

void Script_GetBankBalanceString(void)
{
    u32 savings = GetMoneyInBank();
    u32 digits = Util_CountDigits(savings);
    ConvertIntToDecimalStringN(gStringVar2, savings, STR_CONV_MODE_LEFT_ALIGN, digits);
}

u32 CalcAmountToDeposit(u32 money)
{
    return (money / 100) * SAVINGS_PERCENT
         + ((money % 100) * SAVINGS_PERCENT) / 100;
}

u32 GetTransactionAmount(void)
{
    return sTransactionAmount;
}

void CreateBankingWindow(void)
{
    // print window
    sTransactionWindowId = AddWindow(&sSavingsWithdrawalWindowTemplate);
    DrawStdWindowFrame(sTransactionWindowId, FALSE);
    CopyWindowToVram(sTransactionWindowId, COPYWIN_FULL);
}

void CreateBankingModeWindow(enum BankingMode mode)
{
    const u8 *text = NULL;

    if (mode == MODE_DEPOSIT)
        text = sText_Deposit;
    else if (mode == MODE_WITHDRAW)
        text = sText_Withdraw;

    sBankingModeWindowId = AddWindow(&sBankingModeWindowTemplate);
    DrawStdWindowFrame(sBankingModeWindowId, FALSE);
    CopyWindowToVram(sBankingModeWindowId, COPYWIN_FULL);
    AddTextPrinterParameterized(
        sBankingModeWindowId, FONT_NARROW, text,
        GetStringCenterAlignXOffset(FONT_NARROW, text, 0x28), 2, 0, 0);
}

static bool32 HandleAmountInput(u32 *amount, u32 max, u32 min, s16 *heldFrames)
{
    u32 original = *amount;

    u16 input = JOY_REPEAT(DPAD_ANY);
    u16 held = JOY_HELD(DPAD_ANY);

    u32 step = GetStepSize(*heldFrames);

    if (held)
        (*heldFrames)++;
    else
        *heldFrames = 0;

    if (input & DPAD_UP || input & DPAD_RIGHT)
    {
        if (*amount + step > max)
            *amount = max;
        else
            *amount += step;
    }
    else if (input & DPAD_DOWN || input & DPAD_LEFT)
    {
        if (*amount < step)
            *amount = min;
        else
            *amount -= step;
    }

    return *amount != original;
}

static void PrintTransactionAmount(u8 windowId, u32 amount)
{

    u8 *txtPtr = gStringVar4;
    u32 numDigits = Util_CountDigits(amount);
    u32 maxDigits = (numDigits > 6) ? MAX_MONEY_DIGITS : 6;

    ConvertIntToDecimalStringN(gStringVar1, amount, STR_CONV_MODE_LEFT_ALIGN,
                               maxDigits);

    StringExpandPlaceholders(txtPtr, gText_PokedollarVar1);

    u8 x = 1;
    u8 y = 2;

    if (numDigits > 8)
        PrependFontIdToFit(gStringVar4, txtPtr + 1 + numDigits, FONT_NORMAL,
                           54);

    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar4, x, y, 0,
                                NULL);
}

static u32 GetTransactionMaxAmount(enum BankingMode mode)
{
    u32 money = GetMoney(&gSaveBlock1Ptr->money);
    u32 savings = GetMoneyInBank();
    u32 max = 0;

    if (mode == MODE_DEPOSIT)
    {
        u32 bankCapacity = MAX_BANK_MONEY - savings;
        max = Clamp(money, 0, bankCapacity);
    }
    else if (mode == MODE_WITHDRAW)
    {
        u32 walletCapacity = MAX_MONEY - money;
        max = Clamp(savings, 0, walletCapacity);
    }

    return max;
}

static void UpdateBankBalanceAfterTransaction(enum BankingMode mode)
{
    if (mode == MODE_WITHDRAW)
    {
        SetMoneyInBank(GetMoneyInBank() - sTransactionAmount);
        AddMoney(&gSaveBlock1Ptr->money, sTransactionAmount);
    }
    else if (mode == MODE_DEPOSIT)
    {
        SetMoneyInBank(GetMoneyInBank() + sTransactionAmount);
        RemoveMoney(&gSaveBlock1Ptr->money, sTransactionAmount);
    }

    if (sTransactionAmount)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;

    sTransactionAmount = 0;
}

#define tState       data[0]
#define tBankingMode data[1]
static void Task_ShowBankingInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        if (!IsOverworldLinkActive())
        {
            FreezeObjectEvents();
            PlayerFreeze();
            StopPlayerAvatar();
            LockPlayerFieldControls();
        }
        tState++;
        break;
    case 1:
        CreateBankingWindow();
        CreateBankingModeWindow(tBankingMode);
        tState++;
        break;
    case 2:
        sTransactionAmount = GetTransactionMaxAmount(tBankingMode);
        PrintTransactionAmount(sTransactionWindowId, sTransactionAmount);
        tState++;
        break;
    case 3:
        gTasks[taskId].func = Task_HandleMoneyInput;
        break;
    }
}
#undef tState
#undef tBankingMode

static u32 GetStepSize(s16 heldFrames)
{
    u32 t = heldFrames;
    if (t > STEP_SPEED)
        t = STEP_SPEED;

    u32 eased = (t * t * t) / (STEP_SPEED * STEP_SPEED);

    return 1 + (eased * (MAX_STEP - 1)) / STEP_SPEED;
}

#define tHeldFrames  data[0]
#define tBankingMode data[1]
static void Task_HandleMoneyInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (HandleAmountInput(&sTransactionAmount,
                          GetTransactionMaxAmount(tBankingMode), 0,
                          &tHeldFrames))
    {
        PrintTransactionAmount(sTransactionWindowId, sTransactionAmount);
    }
    else if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        if (JOY_NEW(B_BUTTON))
            sTransactionAmount = 0;
        gSpecialVar_Result = sTransactionAmount;
        ClearStdWindowAndFrame(sTransactionWindowId, TRUE);
        ClearStdWindowAndFrame(sBankingModeWindowId, TRUE);
        UnfreezeObjectEvents();
        ScriptContext_Enable();
        UnlockPlayerFieldControls();
        UpdateBankBalanceAfterTransaction(tBankingMode);
        DestroyTask(taskId);
    }
}
#undef tHeldFrames
#undef tBankingMode

#define tBankingMode data[1]
void Script_StartTransactionTask(struct ScriptContext *ctx)
{
    EnsureBankingEnabled();
    u8 bankingMode = ScriptReadByte(ctx);
    u8 taskId = CreateTask(Task_ShowBankingInput, 2);
    gTasks[taskId].tBankingMode = bankingMode;
}
#undef tBankingMode

void Script_CheckPurchaseFromSavings()
{
    
    EnsureBankingEnabled();
    struct Banking* banking = GetBankingPtr();
    u32 purchaseIdx = banking->lastBought;

    if (!banking->isPending)
    {
        gSpecialVar_Result = ITEM_NONE;
        return;
    }

    struct UniquePurchaseItem purchase = sUniquePurchaseTable[purchaseIdx];
    gSpecialVar_Result = purchase.itemId;
    return;
}

void Script_CheckSavingsPurchaseQuantity()
{
    EnsureBankingEnabled();
    struct Banking *banking = GetBankingPtr();
    u32 purchaseIdx = banking->isPending;

    struct UniquePurchaseItem currentPurchase =
        sUniquePurchaseTable[purchaseIdx];

    gSpecialVar_Result = currentPurchase.quantity;
}

void Script_GetPurchaseFromSavings()
{
    EnsureBankingEnabled();
    struct Banking* banking = GetBankingPtr();
    u32 idx = banking->lastBought;

    assertf(banking->isPending, "No pending purchases to get")
    {
        return;
    }

    struct UniquePurchaseItem currentPurchase =
        sUniquePurchaseTable[idx];

    banking->isPending = FALSE;

    gSpecialVar_Result = currentPurchase.itemId;
    gSpecialVar_0x8001 = currentPurchase.quantity;
}

void PurchaseFromSavings()
{
    struct Banking* banking = GetBankingPtr();
    u32 idx = banking->lastBought;
    u32 savings = GetMoneyInBank();
    struct UniquePurchaseItem next = sUniquePurchaseTable[idx + 1];

    if (savings < next.thresholdMoney)
        return;
    if (banking->isPending)
        return;

    idx++;
    banking->lastBought = idx;
    banking->isPending = TRUE;
}
