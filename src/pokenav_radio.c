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
#include "text.h"
#include "string_util.h"
#include "text_window.h"
#include "constants/songs.h"

#define RADIO_FRAME_BASE_TILE 150
#define RADIO_FRAME_PALETTE 4
#define RADIO_TEXT_PALETTE 5
#include "data/text/radio_strings.h"

#define GFXTAG_RADIO_DIAL 11
#define PALTAG_RADIO_DIAL 21

#define RADIO_TUNING_MIN 0
#define RADIO_TUNING_MAX 63
#define RADIO_TUNING_STEP 1
#define RADIO_DIAL_BASE_X 144
#define RADIO_DIAL_Y 28

enum RadioStation
{
    RADIO_STATION_NONE,
    RADIO_STATION_POKEMON_TALK,
    RADIO_STATION_POKEMON_MUSIC,
    RADIO_STATION_LUCKY_CHANNEL,
    RADIO_STATION_BUENAS_PASSWORD,
    RADIO_STATION_UNOWN,
    RADIO_STATION_PLACES_AND_PEOPLE,
    RADIO_STATION_LETS_ALL_SING,
    RADIO_STATION_POKE_FLUTE,
    RADIO_STATION_EVOLUTION,
    NUM_RADIO_STATIONS,
};

struct RadioChannelEntry
{
    s32 tuningPos;
    u8 station;
    const u8 *name;
};

struct Pokenav_Radio
{
    u32 (*callback)(void);
    s32 tuningPos;
    u8 tuneDelay;
    u8 currentStation;
};

struct Pokenav_RadioGfx
{
    bool32 (*isTaskActiveCB)(void);
    u32 loopedTaskId;
    struct Sprite *dialSprite;
    u16 stationNameWindowId;
    u16 radioTextWindowId;
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
static u8 FindStation(s32 tuningPos);
static void PrintStationName(struct Pokenav_RadioGfx *gfx, u8 station);
static void PrintRadioText(struct Pokenav_RadioGfx *gfx, const u8 *text);
static void ClearRadioText(struct Pokenav_RadioGfx *gfx);

static const u16 sRadioUI_Pal[] = INCBIN_U16("graphics/pokenav/hns/radio/ui.gbapal");
static const u32 sRadioUI_Gfx[] = INCBIN_U32("graphics/pokenav/hns/radio/ui_tiles.4bpp.smol");
static const u32 sRadioUI_Tilemap[] = INCBIN_U32("graphics/pokenav/hns/radio/ui_map.bin.smolTM");
static const u32 sRadioDial_Gfx[] = INCBIN_U32("graphics/pokenav/hns/radio/dial.4bpp.smol");

// Crystal frequencies (0-80) scaled to our range (0-63):
//   new = old * 63 / 80
static const struct RadioChannelEntry sRadioChannels[] =
{
    { .tuningPos = 13, .station = RADIO_STATION_POKEMON_TALK,     .name = sRadioStationName_OaksPkmnTalk },
    { .tuningPos = 22, .station = RADIO_STATION_POKEMON_MUSIC,    .name = sRadioStationName_PokemonMusic },
    { .tuningPos = 25, .station = RADIO_STATION_LUCKY_CHANNEL,    .name = sRadioStationName_LuckyChannel },
    { .tuningPos = 32, .station = RADIO_STATION_BUENAS_PASSWORD,  .name = sRadioStationName_BuenasPassword },
    { .tuningPos = 41, .station = RADIO_STATION_UNOWN,            .name = sRadioStationName_Unown },
    { .tuningPos = 50, .station = RADIO_STATION_PLACES_AND_PEOPLE,.name = sRadioStationName_PlacesAndPeople },
    { .tuningPos = 57, .station = RADIO_STATION_LETS_ALL_SING,    .name = sRadioStationName_LetsAllSing },
    { .tuningPos = 61, .station = RADIO_STATION_POKE_FLUTE,       .name = sRadioStationName_PokeFlute },
    { .tuningPos = 63, .station = RADIO_STATION_EVOLUTION,        .name = sRadioStationName_Unown },
};

static const u8 sRadioText_NoStation[] = _("- - - -");

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

// Station name window: inside the text box area (cols 7-25, row 9)
static const struct WindowTemplate sStationNameWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 6,
    .tilemapTop = 8,
    .width = 19,
    .height = 4,
    .paletteNum = 2,
    .baseBlock = 200,
};

static const u8 sStationNameTextColors[] = {TEXT_COLOR_TRANSPARENT, 7, 5};

// Radio text window: bottom of screen for scrolling dialogue
static const struct WindowTemplate sRadioTextWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 13,
    .width = 28,
    .height = 4,
    .paletteNum = RADIO_TEXT_PALETTE,
    .baseBlock = 1,
};

static const u8 sRadioTextColors[] = {TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};

static const struct BgTemplate sRadioBgTemplates[] =
{
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 0x1F,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
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
    radio->currentStation = RADIO_STATION_NONE;
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

static u8 FindStation(s32 tuningPos)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sRadioChannels); i++)
    {
        if (sRadioChannels[i].tuningPos == tuningPos)
            return sRadioChannels[i].station;
    }
    return RADIO_STATION_NONE;
}

static const u8 *GetStationName(u8 station)
{
    u32 i;
    if (station == RADIO_STATION_NONE)
        return sRadioText_NoStation;
    for (i = 0; i < ARRAY_COUNT(sRadioChannels); i++)
    {
        if (sRadioChannels[i].station == station)
            return sRadioChannels[i].name;
    }
    return sRadioText_NoStation;
}

static void PrintStationName(struct Pokenav_RadioGfx *gfx, u8 station)
{
    const u8 *name = GetStationName(station);
    u32 width = GetStringWidth(FONT_NORMAL, name, -1);
    u32 windowWidth = 19 * 8;

    FillWindowPixelBuffer(gfx->stationNameWindowId, PIXEL_FILL(0));
    AddTextPrinterParameterized3(gfx->stationNameWindowId, FONT_NORMAL,
        (windowWidth - width) / 2, 1, sStationNameTextColors, TEXT_SKIP_DRAW, name);
    CopyWindowToVram(gfx->stationNameWindowId, COPYWIN_FULL);
}

static void PrintRadioText(struct Pokenav_RadioGfx *gfx, const u8 *text)
{
    FillWindowPixelBuffer(gfx->radioTextWindowId, PIXEL_FILL(1));
    AddTextPrinterParameterized3(gfx->radioTextWindowId, FONT_NORMAL,
        2, 1, sRadioTextColors, TEXT_SKIP_DRAW, text);
    CopyWindowToVram(gfx->radioTextWindowId, COPYWIN_GFX);
}

static void ClearRadioText(struct Pokenav_RadioGfx *gfx)
{
    FillWindowPixelBuffer(gfx->radioTextWindowId, PIXEL_FILL(1));
    CopyWindowToVram(gfx->radioTextWindowId, COPYWIN_GFX);
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
            radio->currentStation = FindStation(radio->tuningPos);
            return POKENAV_RADIO_FUNC_TUNE;
        }
        else if (JOY_HELD(DPAD_LEFT) && radio->tuningPos > RADIO_TUNING_MIN)
        {
            radio->tuningPos -= RADIO_TUNING_STEP;
            radio->currentStation = FindStation(radio->tuningPos);
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
    RemoveWindow(gfx->stationNameWindowId);
    RemoveWindow(gfx->radioTextWindowId);
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
        ChangeBgX(2, 0x800, BG_COORD_SET);
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
        gfx->stationNameWindowId = AddWindow(&sStationNameWindowTemplate);
        PutWindowTilemap(gfx->stationNameWindowId);
        PrintStationName(gfx, RADIO_STATION_NONE);
        gfx->radioTextWindowId = AddWindow(&sRadioTextWindowTemplate);
        LoadPalette(gStandardMenuPalette, BG_PLTT_ID(RADIO_TEXT_PALETTE), PLTT_SIZE_4BPP);
        LoadUserWindowBorderGfx(gfx->radioTextWindowId, RADIO_FRAME_BASE_TILE, BG_PLTT_ID(RADIO_FRAME_PALETTE));
        DrawStdFrameWithCustomTileAndPalette(gfx->radioTextWindowId, FALSE, RADIO_FRAME_BASE_TILE, RADIO_FRAME_PALETTE);
        FillWindowPixelBuffer(gfx->radioTextWindowId, PIXEL_FILL(1));
        PutWindowTilemap(gfx->radioTextWindowId);
        CopyWindowToVram(gfx->radioTextWindowId, COPYWIN_FULL);
        CopyBgTilemapBufferToVram(1);
        ShowBg(0);
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

static const u8 *GetStationIntroText(u8 station)
{
    switch (station)
    {
    case RADIO_STATION_POKEMON_TALK:
        return sRadioText_OPT_Intro1;
    case RADIO_STATION_POKEMON_MUSIC:
        return sRadioText_BenIntro1;
    case RADIO_STATION_LUCKY_CHANNEL:
        return sRadioText_LC1;
    case RADIO_STATION_BUENAS_PASSWORD:
        return sRadioText_Buena1;
    case RADIO_STATION_PLACES_AND_PEOPLE:
        return sRadioText_PnP1;
    case RADIO_STATION_UNOWN:
    case RADIO_STATION_EVOLUTION:
    case RADIO_STATION_LETS_ALL_SING:
    case RADIO_STATION_POKE_FLUTE:
    default:
        return NULL;
    }
}

static u32 LoopedTask_TuneRadio(s32 state)
{
    struct Pokenav_RadioGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO_GFX);
    struct Pokenav_Radio *radio = GetSubstructPtr(POKENAV_SUBSTRUCT_RADIO);
    const u8 *introText;

    gfx->dialSprite->x = RADIO_DIAL_BASE_X + radio->tuningPos;
    PrintStationName(gfx, radio->currentStation);

    introText = GetStationIntroText(radio->currentStation);
    if (introText != NULL)
        PrintRadioText(gfx, introText);
    else
        ClearRadioText(gfx);

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
        ShowBg(0);
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
