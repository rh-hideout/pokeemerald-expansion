#include "global.h"
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
#include "banking_system.h"
#include "script.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "util.h"
#include "window.h"

// Config
#define MAX_STEP 1000

// Variables
u32 sWithdrawalAmount = 0;
u8 sWithdrawalWindowId = 0;

// Static Functions
static u32 GetStepSize(s16 heldFrames);
static bool32 HandleAmountInput(u32 *amount, s32 max, s32 min, s16 *heldFrames);

// Tasks
static void Task_ShowWithdrawalMenu(u8 taskId);
static void Task_HandleWithdrawalInput(u8 taskId);

// Windows
static const struct WindowTemplate sSavingsWithdrawalWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 15,
    .tilemapTop = 2,
    .width = 13,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x30};

bool32 IsSavingMoney(void)
{
    return FlagGet(SAVINGS_FLAG);
}

u32 GetMoneyInBank(void)
{
    return gSaveBlock3Ptr->savedMoney;
}

void GetMoneyInBankFromScript(struct ScriptContext ctx)
{
    gSpecialVar_Result = GetMoneyInBank();
}

void SetMoneyInBank(u32 amount)
{
    gSaveBlock3Ptr->savedMoney = amount;
}

void SetMoneyInBankFromScript(struct ScriptContext *ctx)
{
    u32 amount = ScriptReadWord(ctx);
    SetMoneyInBank(amount);
}

u32 CalcAmountToDeposit(u32 money)
{
    return (money / 100) * SAVINGS_PERCENT
         + ((money % 100) * SAVINGS_PERCENT) / 100;
}

u32 GetWithdrawalAmount(void)
{
    return sWithdrawalAmount;
}

void CreateWithdrawalWindow(void)
{
    // print window
    sWithdrawalWindowId = AddWindow(&sSavingsWithdrawalWindowTemplate);
    DrawStdWindowFrame(sWithdrawalWindowId, FALSE);
    CopyWindowToVram(sWithdrawalWindowId, COPYWIN_FULL);
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

static void PrintWithdrawalAmount(u8 windowId, s16 amount)
{
    ConvertIntToDecimalStringN(gStringVar4, amount, STR_CONV_MODE_LEADING_ZEROS,
                               Util_CountDigits(GetMoneyInBank()));
    AddTextPrinterParameterized(
        windowId, FONT_NORMAL, gStringVar4,
        GetStringCenterAlignXOffset(FONT_NORMAL, gStringVar4, 0x28), 2, 0, 0);
}

#define tState data[0]
static void Task_ShowWithdrawalMenu(u8 taskId)
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
        CreateWithdrawalWindow();
        tState++;
        break;
    case 2:
        sWithdrawalAmount = GetMoneyInBank();
        PrintWithdrawalAmount(sWithdrawalWindowId, sWithdrawalAmount);
        tState++;
        break;
    case 3:
        gTasks[taskId].func = Task_HandleWithdrawalInput;
        break;
    }
}
#undef tState

static u32 GetStepSize(s16 heldFrames)
{
    if (heldFrames < 60)
        return 1 + heldFrames / 20;

    u32 step = 5 + (heldFrames - 60) / 5;
    step = step > MAX_STEP ? MAX_STEP : step;

    return step;
}

#define tHeldFrames data[0]
static void Task_HandleWithdrawalInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (HandleAmountInput(&sWithdrawalAmount, GetMoneyInBank(), 0,
                          &tHeldFrames))
    {
        PrintWithdrawalAmount(sWithdrawalWindowId, sWithdrawalAmount);
    }
    else if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        if (JOY_NEW(B_BUTTON))
            sWithdrawalAmount = 0;
        gSpecialVar_Result = sWithdrawalAmount;
        ClearStdWindowAndFrame(sWithdrawalWindowId, TRUE);
        UnfreezeObjectEvents();
        ScriptContext_Enable();
        UnlockPlayerFieldControls();
        DestroyTask(taskId);
    }
}
#undef tHeldFrames

void StartWithdrawMoneyTask(void)
{
    CreateTask(Task_ShowWithdrawalMenu, 2);
}

void UpdateBankAccountAfterWithdrawal(void)
{
    SetMoneyInBank(GetMoneyInBank() - sWithdrawalAmount);
    AddMoney(&gSaveBlock1Ptr->money, sWithdrawalAmount);
}
