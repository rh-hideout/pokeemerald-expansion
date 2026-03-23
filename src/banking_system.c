#include "global.h"
#include "assertf.h"
#include "banking_system.h"
#include "battle_message.h"
#include "config/banking.h"
#include "constants/flags.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "money.h"
#include "overworld.h"
#include "script.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "util.h"
#include "window.h"

// Config
#define MAX_STEP       1000
#define STEP_SPEED     360
#define MAX_BANK_MONEY 9999999

enum BankingMode
{
    MODE_DEPOSIT,
    MODE_WITHDRAW
};

static const u8 sText_Deposit[] = _("Deposit");
static const u8 sText_Withdraw[] = _("Withdraw");

// Variables
u32 sTransactionAmount = 0;
u8 sTransactionWindowId = 0;
u8 sBankingModeWindowId = 0;

// Static Functions
static u32 GetStepSize(s16 heldFrames);
static bool32 HandleAmountInput(u32 *amount, s32 max, s32 min, s16 *heldFrames);
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

bool32 IsSavingMoney(void)
{
    return FlagGet(SAVINGS_FLAG);
}

u32 GetMoneyInBank(void)
{
    return gSaveBlock3Ptr->savedMoney;
}

void SetMoneyInBank(u32 amount)
{
    assertf(amount <= MAX_BANK_MONEY, "Amount greater than MAX_BANK_MONEY");
    gSaveBlock3Ptr->savedMoney = amount;
}

void Script_CompareBankBalance(struct ScriptContext *ctx)
{
    u32 value = ScriptReadWord(ctx);
    u32 balance = GetMoneyInBank();

    if (value > balance)
        gSpecialVar_Result = FALSE;
    else if (value <= balance)
        gSpecialVar_Result = TRUE;
}

void Script_RemoveFromBank(struct ScriptContext *ctx)
{
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
    u32 amount = ScriptReadWord(ctx);
    u32 balance = GetMoneyInBank();
    u32 wallet = GetMoney(&gSaveBlock1Ptr->money);

    gSpecialVar_Result = TRUE;

    if (amount > wallet)
    {
        amount = wallet;
        gSpecialVar_Result = FALSE;
    }

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
    u8 x = ScriptReadByte(ctx);
    u8 y = ScriptReadByte(ctx);

    Script_RequestEffects(SCREFF_V1 | SCREFF_HARDWARE);

    DrawMoneyBox(GetMoneyInBank(), x, y);
}

void Script_HideBankBalanceBox(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1 | SCREFF_HARDWARE);

    HideMoneyBox();
}

void Script_UpdateBankBalanceBox(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1 | SCREFF_HARDWARE);
    ChangeAmountInMoneyBox(GetMoneyInBank());
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

static bool32 HandleAmountInput(u32 *amount, s32 max, s32 min, s16 *heldFrames)
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

static void PrintTransactionAmount(u8 windowId, s16 amount)
{
    ConvertIntToDecimalStringN(gStringVar4, amount, STR_CONV_MODE_LEADING_ZEROS,
                               Util_CountDigits(GetMoneyInBank()));
    AddTextPrinterParameterized(
        windowId, FONT_NORMAL, gStringVar4,
        GetStringCenterAlignXOffset(FONT_NORMAL, gStringVar4, 0x28), 2, 0, 0);
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
void StartTransactionTask(struct ScriptContext *ctx)
{
    u8 bankingMode = ScriptReadByte(ctx);
    u8 taskId = CreateTask(Task_ShowBankingInput, 2);
    gTasks[taskId].tBankingMode = bankingMode;
}
#undef tBankingMode

