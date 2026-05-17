#include "global.h"
#include "pokenav.h"
#include "window.h"
#include "bg.h"
#include "menu.h"
#include "sound.h"
#include "palette.h"
#include "decompress.h"
#include "dma3.h"
#include "gpu_regs.h"
#include "sprite.h"
#include "constants/songs.h"

#define GFXTAG_RADIO_DIAL 11
#define PALTAG_RADIO_DIAL 21

#define RADIO_TUNING_MIN 0
#define RADIO_TUNING_MAX 63
#define RADIO_TUNING_STEP 1
#define RADIO_DIAL_BASE_X 152
#define RADIO_DIAL_Y 36

struct Pokenav_Radio
{
    u32 (*callback)(void);
    s32 tuningPos;
    u8 tuneDelay;
};

struct Pokenav_RadioGfx
{
    bool32 (*isTaskActiveCB)(void);
    u32 loopedTaskId;
    struct Sprite *dialSprite;
    u16 bgTilemapBuffer1[BG_SCREEN_SIZE / 2];
    u16 bgTilemapBuffer2[BG_SCREEN_SIZE / 2];
};

enum
{
    POKENAV_RADIO_FUNC_NONE,
    POKENAV_RADIO_FUNC_TUNE,
    POKENAV_RADIO_FUNC_EXIT,
};

static u32 HandleRadioInput(void);
static u32 GetExitRadioMenuId(void);
static u32 LoopedTask_OpenRadio(s32 state);
static u32 LoopedTask_TuneRadio(s32 state);
static u32 LoopedTask_ExitRadio(s32 state);
static bool32 GetCurrentRadioLoopedTaskActive(void);

static const u16 sRadioUI_Pal[] = INCBIN_U16("graphics/pokenav/hns/radio/ui.gbapal");
static const u32 sRadioUI_Gfx[] = INCBIN_U32("graphics/pokenav/hns/radio/ui_tiles.4bpp.smol");
static const u32 sRadioUI_Tilemap[] = INCBIN_U32("graphics/pokenav/hns/radio/ui_map.bin.smolTM");
static const u32 sRadioDial_Gfx[] = INCBIN_U32("graphics/pokenav/hns/radio/dial.4bpp.smol");

static const struct CompressedSpriteSheet sRadioDialSpriteSheet =
{
    .data = sRadioDial_Gfx,
    .size = 16 * 16 / 2,
    .tag = GFXTAG_RADIO_DIAL,
};

static const struct SpritePalette sRadioDialSpritePalette =
{
    .data = sRadioUI_Pal,
    .tag = PALTAG_RADIO_DIAL,
};

static const struct OamData sRadioDialOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

static const struct SpriteTemplate sRadioDialSpriteTemplate =
{
    .tileTag = GFXTAG_RADIO_DIAL,
    .paletteTag = PALTAG_RADIO_DIAL,
    .oam = &sRadioDialOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct BgTemplate sRadioBgTemplates[] =
{
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x06,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
};

static const LoopedTask sRadioLoopTaskFuncs[] =
{
    [POKENAV_RADIO_FUNC_NONE] = NULL,
    [POKENAV_RADIO_FUNC_TUNE] = LoopedTask_TuneRadio,
    [POKENAV_RADIO_FUNC_EXIT] = LoopedTask_ExitRadio,
};

bool32 PokenavCallback_Init_Radio(void)
{
    struct Pokenav_Radio *radio = AllocSubstruct(POKENAV_SUBSTRUCT_RADIO, sizeof(struct Pokenav_Radio));
    if (!radio)
        return FALSE;

    radio->callback = HandleRadioInput;
    radio->tuningPos = RADIO_TUNING_MIN;
    return TRUE;
}

s32 GetRadioTuningPos(void)
{
    struct Pokenav_Radio *radio = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO);
    return radio->tuningPos;
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
    struct Pokenav_Radio *radio = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO);

    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        radio->callback = GetExitRadioMenuId;
        return POKENAV_RADIO_FUNC_EXIT;
    }

    if (JOY_HELD(DPAD_RIGHT) || JOY_HELD(DPAD_LEFT))
    {
        if (++radio->tuneDelay < 3)
            return POKENAV_RADIO_FUNC_NONE;
        radio->tuneDelay = 0;

        if (JOY_HELD(DPAD_RIGHT) && radio->tuningPos < RADIO_TUNING_MAX)
        {
            radio->tuningPos += RADIO_TUNING_STEP;
            return POKENAV_RADIO_FUNC_TUNE;
        }
        else if (JOY_HELD(DPAD_LEFT) && radio->tuningPos > RADIO_TUNING_MIN)
        {
            radio->tuningPos -= RADIO_TUNING_STEP;
            return POKENAV_RADIO_FUNC_TUNE;
        }
    }
    else
    {
        radio->tuneDelay = 0;
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
    struct Pokenav_RadioGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO_GFX);
    if (gfx->dialSprite)
        DestroySprite(gfx->dialSprite);
    FreeSpriteTilesByTag(GFXTAG_RADIO_DIAL);
    FreeSpritePaletteByTag(PALTAG_RADIO_DIAL);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_RADIO_GFX);
}

static bool32 GetCurrentRadioLoopedTaskActive(void)
{
    struct Pokenav_RadioGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO_GFX);
    return IsLoopedTaskActive(gfx->loopedTaskId);
}

static u32 LoopedTask_OpenRadio(s32 state)
{
    struct Pokenav_RadioGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO_GFX);
    switch (state)
    {
    case 0:
        InitBgTemplates(sRadioBgTemplates, ARRAY_COUNT(sRadioBgTemplates));
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        DecompressAndCopyTileDataToVram(2, sRadioUI_Gfx, 0, 0, 0);
        SetBgTilemapBuffer(2, gfx->bgTilemapBuffer2);
        CopyToBgTilemapBuffer(2, sRadioUI_Tilemap, 0, 0);
        CopyBgTilemapBufferToVram(2);
        CopyPaletteIntoBufferUnfaded(sRadioUI_Pal, BG_PLTT_ID(2), sizeof(sRadioUI_Pal));
        return LT_INC_AND_PAUSE;
    case 1:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        BgDmaFill(1, 0, 0, 1);
        SetBgTilemapBuffer(1, gfx->bgTilemapBuffer1);
        FillBgTilemapBufferRect_Palette0(1, 0x1000, 0, 0, 32, 20);
        CopyBgTilemapBufferToVram(1);
        return LT_INC_AND_PAUSE;
    case 2:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        LoadCompressedSpriteSheet(&sRadioDialSpriteSheet);
        LoadSpritePalette(&sRadioDialSpritePalette);
        {
            u8 spriteId = CreateSprite(&sRadioDialSpriteTemplate, RADIO_DIAL_BASE_X + GetRadioTuningPos(), RADIO_DIAL_Y, 1);
            gfx->dialSprite = &gSprites[spriteId];
        }
        ShowBg(1);
        ShowBg(2);
        PokenavFadeScreen(POKENAV_FADE_FROM_BLACK);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_TuneRadio(s32 state)
{
    struct Pokenav_RadioGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO_GFX);
    gfx->dialSprite->x = RADIO_DIAL_BASE_X + GetRadioTuningPos();
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
