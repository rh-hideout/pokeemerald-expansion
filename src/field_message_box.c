#include "global.h"
#include "menu.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "match_call.h"
#include "field_message_box.h"
#include "text_window.h"
#include "script.h"
#include "field_name_box.h"
#include "constants/dialogue_styles.h"

#define DIALOGUE_STYLE_SLOW_TEXT_DELAY 12
#define DIALOGUE_STYLE_FAST_TEXT_DELAY 1
#define DIALOGUE_STYLE_SLOW_TEXT_MODIFIER 1
#define DIALOGUE_STYLE_FAST_TEXT_MODIFIER 3
#define DIALOGUE_STYLE_SLOW_SCROLL_SPEED 1
#define DIALOGUE_STYLE_FAST_SCROLL_SPEED 6
#define DIALOGUE_STYLE_SCROLL_DELAY_NONE 0

static EWRAM_DATA u8 sFieldMessageBoxMode = 0;
static EWRAM_DATA u8 sFieldMessageDialogueStyle = DIALOGUE_STYLE_DEFAULT;
EWRAM_DATA u8 gWalkAwayFromSignpostTimer = 0;

static void ExpandStringAndStartDrawFieldMessage(const u8 *, bool32);
static void StartDrawFieldMessage(void);

void InitFieldMessageBox(void)
{
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
    ClearFieldMessageDialogueStyle();
    gTextFlags.canABSpeedUpPrint = FALSE;
    gTextFlags.useAlternateDownArrow = FALSE;
    gTextFlags.autoScroll = FALSE;
    gTextFlags.forceMidTextSpeed = FALSE;
}

void SetFieldMessageDialogueStyle(u8 style)
{
    if (style >= DIALOGUE_STYLE_COUNT)
        style = DIALOGUE_STYLE_DEFAULT;
    sFieldMessageDialogueStyle = style;
}

void ClearFieldMessageDialogueStyle(void)
{
    sFieldMessageDialogueStyle = DIALOGUE_STYLE_DEFAULT;
}

u8 GetFieldMessageDialogueStyle(void)
{
    return sFieldMessageDialogueStyle;
}

u32 GetFieldMessageTextSpeedDelay(void)
{
    switch (sFieldMessageDialogueStyle)
    {
    case DIALOGUE_STYLE_SLOW:
    case DIALOGUE_STYLE_SLOW_TEXT:
        return DIALOGUE_STYLE_SLOW_TEXT_DELAY;
    case DIALOGUE_STYLE_FAST:
    case DIALOGUE_STYLE_FAST_TEXT:
        return DIALOGUE_STYLE_FAST_TEXT_DELAY;
    default:
        return GetPlayerTextSpeedDelay();
    }
}

u32 GetFieldMessageTextSpeedModifier(void)
{
    switch (sFieldMessageDialogueStyle)
    {
    case DIALOGUE_STYLE_FAST:
    case DIALOGUE_STYLE_FAST_TEXT:
        return DIALOGUE_STYLE_FAST_TEXT_MODIFIER;
    case DIALOGUE_STYLE_SLOW:
    case DIALOGUE_STYLE_SLOW_TEXT:
        return DIALOGUE_STYLE_SLOW_TEXT_MODIFIER;
    default:
        return GetPlayerTextSpeedModifier();
    }
}

u32 GetFieldMessageTextScrollSpeed(void)
{
    switch (sFieldMessageDialogueStyle)
    {
    case DIALOGUE_STYLE_SLOW:
        return DIALOGUE_STYLE_SLOW_SCROLL_SPEED;
    case DIALOGUE_STYLE_FAST:
        return DIALOGUE_STYLE_FAST_SCROLL_SPEED;
    default:
        return GetPlayerTextScrollSpeed();
    }
}

u32 GetFieldMessageTextScrollDelay(void)
{
    switch (sFieldMessageDialogueStyle)
    {
    case DIALOGUE_STYLE_SLOW:
    case DIALOGUE_STYLE_FAST:
        return DIALOGUE_STYLE_SCROLL_DELAY_NONE;
    default:
        return GetPlayerTextSpeedModifier();
    }
}

bool32 IsFieldMessageTextSpeedInstant(void)
{
    if (sFieldMessageDialogueStyle == DIALOGUE_STYLE_DEFAULT)
        return IsPlayerTextSpeedInstant();
    return FALSE;
}

void ApplyFieldMessageTextPrinterProfile(void)
{
    SetTextPrinterSpeedProfile(
        GetFieldMessageTextSpeedModifier(),
        IsFieldMessageTextSpeedInstant(),
        GetFieldMessageTextScrollSpeed(),
        GetFieldMessageTextScrollDelay());
}

#define tState data[0]

static void Task_DrawFieldMessage(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        if (gMsgIsSignPost)
            LoadSignPostWindowFrameGfx();
        else
            LoadMessageBoxAndBorderGfx();
        task->tState++;
        break;
    case 1:
    {
        u32 nameboxWinId = GetNameboxWindowId();
        DrawDialogueFrame(0, TRUE);
        if (nameboxWinId != WINDOW_NONE)
            DrawNamebox(nameboxWinId, NAME_BOX_BASE_TILE_NUM - NAME_BOX_BASE_TILES_TOTAL, TRUE);
        task->tState++;
        break;
    }
    case 2:
        if (RunTextPrintersAndIsPrinter0Active() != TRUE)
        {
            sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
            DestroyTask(taskId);
        }
    }
}

#undef tState

static void CreateTask_DrawFieldMessage(void)
{
    CreateTask(Task_DrawFieldMessage, 0x50);
}

static void DestroyTask_DrawFieldMessage(void)
{
    u8 taskId = FindTaskIdByFunc(Task_DrawFieldMessage);
    if (taskId != TASK_NONE)
        DestroyTask(taskId);
}

bool8 ShowFieldMessage(const u8 *str)
{
    if (sFieldMessageBoxMode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    ExpandStringAndStartDrawFieldMessage(str, TRUE);
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_NORMAL;
    return TRUE;
}

static void Task_HidePokenavMessageWhenDone(u8 taskId)
{
    if (!IsMatchCallTaskActive())
    {
        sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
        DestroyTask(taskId);
    }
}

bool8 ShowPokenavFieldMessage(const u8 *str)
{
    if (sFieldMessageBoxMode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    StringExpandPlaceholders(gStringVar4, str);
    CreateTask(Task_HidePokenavMessageWhenDone, 0);
    StartMatchCallFromScript(str);
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_NORMAL;
    return TRUE;
}

bool8 ShowFieldAutoScrollMessage(const u8 *str)
{
    if (sFieldMessageBoxMode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_AUTO_SCROLL;
    ExpandStringAndStartDrawFieldMessage(str, FALSE);
    return TRUE;
}

static bool8 UNUSED ForceShowFieldAutoScrollMessage(const u8 *str)
{
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_AUTO_SCROLL;
    ExpandStringAndStartDrawFieldMessage(str, TRUE);
    return TRUE;
}

// Same as ShowFieldMessage, but instead of accepting a
// string arg it just prints whats already in gStringVar4
bool8 ShowFieldMessageFromBuffer(void)
{
    if (sFieldMessageBoxMode != FIELD_MESSAGE_BOX_HIDDEN)
        return FALSE;
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_NORMAL;
    StartDrawFieldMessage();
    return TRUE;
}

static void ExpandStringAndStartDrawFieldMessage(const u8 *str, bool32 allowSkippingDelayWithButtonPress)
{
    StringExpandPlaceholders(gStringVar4, str);
    TrySpawnNamebox(gStringVar4, NAME_BOX_BASE_TILE_NUM);
    AddTextPrinterForMessage(allowSkippingDelayWithButtonPress);
    CreateTask_DrawFieldMessage();
}

static void StartDrawFieldMessage(void)
{
    AddTextPrinterForMessage(TRUE);
    CreateTask_DrawFieldMessage();
}

void HideFieldMessageBox(void)
{
    DestroyTask_DrawFieldMessage();
    ClearDialogWindowAndFrame(0, TRUE);
    DestroyNamebox();
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
}

u8 GetFieldMessageBoxMode(void)
{
    return sFieldMessageBoxMode;
}

bool8 IsFieldMessageBoxHidden(void)
{
    if (sFieldMessageBoxMode == FIELD_MESSAGE_BOX_HIDDEN)
        return TRUE;
    return FALSE;
}

static void UNUSED ReplaceFieldMessageWithFrame(void)
{
    DestroyTask_DrawFieldMessage();
    DrawStdWindowFrame(0, TRUE);
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
}

void StopFieldMessage(void)
{
    DestroyTask_DrawFieldMessage();
    sFieldMessageBoxMode = FIELD_MESSAGE_BOX_HIDDEN;
}
