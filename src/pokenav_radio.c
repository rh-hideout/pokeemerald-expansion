#include "global.h"
#include "pokenav.h"
#include "window.h"
#include "bg.h"
#include "menu.h"
#include "sound.h"
#include "constants/songs.h"

struct Pokenav_Radio
{
    u32 (*callback)(void);
};

struct Pokenav_RadioGfx
{
    bool32 (*isTaskActiveCB)(void);
    u32 loopedTaskId;
};

enum
{
    POKENAV_RADIO_FUNC_NONE,
    POKENAV_RADIO_FUNC_EXIT,
};

static u32 HandleRadioInput(void);
static u32 GetExitRadioMenuId(void);
static u32 LoopedTask_OpenRadio(s32 state);
static u32 LoopedTask_ExitRadio(s32 state);
static bool32 GetCurrentRadioLoopedTaskActive(void);

static const LoopedTask sRadioLoopTaskFuncs[] =
{
    [POKENAV_RADIO_FUNC_NONE] = NULL,
    [POKENAV_RADIO_FUNC_EXIT] = LoopedTask_ExitRadio,
};

bool32 PokenavCallback_Init_Radio(void)
{
    struct Pokenav_Radio *radio = AllocSubstruct(POKENAV_SUBSTRUCT_RADIO, sizeof(struct Pokenav_Radio));
    if (!radio)
        return FALSE;

    radio->callback = HandleRadioInput;
    return TRUE;
}

u32 GetRadioCallback(void)
{
    struct Pokenav_Radio *radio = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO);
    return radio->callback();
}

void FreeRadioSubstruct1(void)
{
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_RADIO);
}

static u32 HandleRadioInput(void)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        struct Pokenav_Radio *radio = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO);
        radio->callback = GetExitRadioMenuId;
        return POKENAV_RADIO_FUNC_EXIT;
    }

    return POKENAV_RADIO_FUNC_NONE;
}

static u32 GetExitRadioMenuId(void)
{
    return POKENAV_MAIN_MENU_CURSOR_ON_MAP;
}

bool32 OpenPokenavRadio(void)
{
    struct Pokenav_RadioGfx *gfx = AllocSubstruct(POKENAV_SUBSTRUCT_RADIO_GFX, sizeof(struct Pokenav_RadioGfx));
    if (!gfx)
        return FALSE;

    gfx->loopedTaskId = CreateLoopedTask(LoopedTask_OpenRadio, 1);
    gfx->isTaskActiveCB = GetCurrentRadioLoopedTaskActive;
    return TRUE;
}

void CreateRadioLoopedTask(s32 index)
{
    struct Pokenav_RadioGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO_GFX);
    gfx->loopedTaskId = CreateLoopedTask(sRadioLoopTaskFuncs[index], 1);
    gfx->isTaskActiveCB = GetCurrentRadioLoopedTaskActive;
}

bool32 IsRadioLoopedTaskActive(void)
{
    struct Pokenav_RadioGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO_GFX);
    return gfx->isTaskActiveCB();
}

void FreeRadioSubstruct2(void)
{
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_RADIO_GFX);
}

static bool32 GetCurrentRadioLoopedTaskActive(void)
{
    struct Pokenav_RadioGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO_GFX);
    return IsLoopedTaskActive(gfx->loopedTaskId);
}

static u32 LoopedTask_OpenRadio(s32 state)
{
    switch (state)
    {
    case 0:
        PokenavFadeScreen(POKENAV_FADE_FROM_BLACK);
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_ExitRadio(s32 state)
{
    switch (state)
    {
    case 0:
        PokenavFadeScreen(POKENAV_FADE_TO_BLACK);
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        SetLeftHeaderSpritesInvisibility();
        SlideMenuHeaderDown();
        return LT_INC_AND_PAUSE;
    case 2:
        if (MainMenuLoopedTaskIsBusy())
            return LT_PAUSE;
        HideBg(1);
        HideBg(2);
        HideBg(3);
        return LT_INC_AND_PAUSE;
    }
    return LT_FINISH;
}
