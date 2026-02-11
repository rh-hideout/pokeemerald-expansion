#include "global.h"
#include "bg.h"
#include "event_object_movement.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "script.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"

static s16 sSavedBg0XOffset;
static s16 sSavedBg0YOffset;

static const u8 sTrainerCodeHintText[] = {
    CHAR_d,
    CHAR_e,
    CHAR_f,
    CHAR_SPACE,
    CHAR_t,
    CHAR_r,
    CHAR_a,
    CHAR_i,
    CHAR_n,
    CHAR_e,
    CHAR_r,
    CHAR_UNDERSCORE,
    CHAR_c,
    CHAR_o,
    CHAR_d,
    CHAR_e,
    CHAR_LEFT_PAREN,
    CHAR_t,
    CHAR_r,
    CHAR_a,
    CHAR_i,
    CHAR_n,
    CHAR_e,
    CHAR_r,
    CHAR_UNDERSCORE,
    CHAR_i,
    CHAR_d,
    CHAR_COLON,
    CHAR_SPACE,
    CHAR_i,
    CHAR_n,
    CHAR_t,
    CHAR_COMMA,
    CHAR_SPACE,
    CHAR_n,
    CHAR_a,
    CHAR_m,
    CHAR_e,
    CHAR_COLON,
    CHAR_SPACE,
    CHAR_s,
    CHAR_t,
    CHAR_r,
    CHAR_RIGHT_PAREN,
    CHAR_SPACE,
    CHAR_HYPHEN,
    CHAR_GREATER_THAN,
    CHAR_SPACE,
    CHAR_i,
    CHAR_n,
    CHAR_t,
    CHAR_COLON,
    CHAR_NEWLINE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_s,
    CHAR_SPACE,
    CHAR_EQUALS,
    CHAR_SPACE,
    CHAR_f,
    CHAR_DBL_QUOTE,
    CHAR_L_BRACE,
    CHAR_t,
    CHAR_r,
    CHAR_a,
    CHAR_i,
    CHAR_n,
    CHAR_e,
    CHAR_r,
    CHAR_UNDERSCORE,
    CHAR_i,
    CHAR_d,
    CHAR_R_BRACE,
    CHAR_L_BRACE,
    CHAR_n,
    CHAR_a,
    CHAR_m,
    CHAR_e,
    CHAR_R_BRACE,
    CHAR_DBL_QUOTE,
    CHAR_PERIOD,
    CHAR_e,
    CHAR_n,
    CHAR_c,
    CHAR_o,
    CHAR_d,
    CHAR_e,
    CHAR_LEFT_PAREN,
    CHAR_DBL_QUOTE,
    CHAR_u,
    CHAR_t,
    CHAR_f,
    CHAR_HYPHEN,
    CHAR_8,
    CHAR_DBL_QUOTE,
    CHAR_RIGHT_PAREN,
    CHAR_NEWLINE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_x,
    CHAR_SPACE,
    CHAR_EQUALS,
    CHAR_SPACE,
    CHAR_0,
    CHAR_NEWLINE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_f,
    CHAR_o,
    CHAR_r,
    CHAR_SPACE,
    CHAR_b,
    CHAR_SPACE,
    CHAR_i,
    CHAR_n,
    CHAR_SPACE,
    CHAR_s,
    CHAR_COLON,
    CHAR_NEWLINE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_x,
    CHAR_SPACE,
    CHAR_CARET,
    CHAR_EQUALS,
    CHAR_SPACE,
    CHAR_b,
    CHAR_NEWLINE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_x,
    CHAR_SPACE,
    CHAR_CARET,
    CHAR_EQUALS,
    CHAR_SPACE,
    CHAR_LEFT_PAREN,
    CHAR_x,
    CHAR_SPACE,
    CHAR_LESS_THAN,
    CHAR_LESS_THAN,
    CHAR_SPACE,
    CHAR_QUESTION_MARK,
    CHAR_RIGHT_PAREN,
    CHAR_SPACE,
    CHAR_AMPERSAND,
    CHAR_SPACE,
    CHAR_0,
    CHAR_x,
    CHAR_F,
    CHAR_F,
    CHAR_F,
    CHAR_F,
    CHAR_F,
    CHAR_F,
    CHAR_F,
    CHAR_F,
    CHAR_NEWLINE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_x,
    CHAR_SPACE,
    CHAR_CARET,
    CHAR_EQUALS,
    CHAR_SPACE,
    CHAR_LEFT_PAREN,
    CHAR_x,
    CHAR_SPACE,
    CHAR_GREATER_THAN,
    CHAR_GREATER_THAN,
    CHAR_SPACE,
    CHAR_QUESTION_MARK,
    CHAR_RIGHT_PAREN,
    CHAR_NEWLINE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_x,
    CHAR_SPACE,
    CHAR_AMPERSAND,
    CHAR_EQUALS,
    CHAR_SPACE,
    CHAR_0,
    CHAR_x,
    CHAR_F,
    CHAR_F,
    CHAR_F,
    CHAR_F,
    CHAR_F,
    CHAR_F,
    CHAR_F,
    CHAR_F,
    CHAR_NEWLINE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_SPACE,
    CHAR_r,
    CHAR_e,
    CHAR_t,
    CHAR_u,
    CHAR_r,
    CHAR_n,
    CHAR_SPACE,
    CHAR_1,
    CHAR_UNDERSCORE,
    CHAR_0,
    CHAR_0,
    CHAR_0,
    CHAR_UNDERSCORE,
    CHAR_0,
    CHAR_0,
    CHAR_0,
    CHAR_SPACE,
    CHAR_PLUS,
    CHAR_SPACE,
    CHAR_LEFT_PAREN,
    CHAR_x,
    CHAR_SPACE,
    CHAR_PERCENT,
    CHAR_SPACE,
    CHAR_9,
    CHAR_UNDERSCORE,
    CHAR_0,
    CHAR_0,
    CHAR_0,
    CHAR_UNDERSCORE,
    CHAR_0,
    CHAR_0,
    CHAR_0,
    CHAR_RIGHT_PAREN,
    EOS
};

static const struct WindowTemplate sTrainerCodeHintWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 30,
    .height = 20,
    .paletteNum = 15,
    .baseBlock = 1,
};

static const u8 sTrainerCodeHintTextColor[] = {
    TEXT_COLOR_LIGHT_GRAY,
    TEXT_COLOR_TRANSPARENT,
    TEXT_COLOR_DARK_GRAY,
};

static void Task_TrainerCodeHint(u8 taskId);

bool8 ShowTrainerCodeHint(void)
{
    sSavedBg0XOffset = GetBgX(0);
    sSavedBg0YOffset = GetBgY(0);
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    LockPlayerFieldControls();
    FreezeObjectEvents();
    ScriptContext_Stop();
    CreateTask(Task_TrainerCodeHint, 80);
    return TRUE;
}

static void Task_TrainerCodeHint(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
    {
        u8 windowId = AddWindow(&sTrainerCodeHintWindowTemplate);
        data[1] = windowId;
        PutWindowTilemap(windowId);
        FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
        DrawStdFrameWithCustomTileAndPalette(windowId, FALSE, 1, 14);
        gTextFlags.canABSpeedUpPrint = FALSE;
        AddTextPrinterParameterized4(windowId, FONT_NARROWER, 2, 2, 0, 1, sTrainerCodeHintTextColor, TEXT_SKIP_DRAW, sTrainerCodeHintText);
        CopyWindowToVram(windowId, COPYWIN_FULL);
        data[0] = 1;
        break;
    }
    case 1:
        if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            u8 windowId = data[1];
            ClearWindowTilemap(windowId);
            RemoveWindow(windowId);
            CopyBgTilemapBufferToVram(0);
            ChangeBgX(0, sSavedBg0XOffset, BG_COORD_SET);
            ChangeBgY(0, sSavedBg0YOffset, BG_COORD_SET);
            ScriptContext_Enable();
            UnfreezeObjectEvents();
            UnlockPlayerFieldControls();
            DestroyTask(taskId);
        }
        break;
    }
}
