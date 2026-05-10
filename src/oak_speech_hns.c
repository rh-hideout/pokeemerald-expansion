#include "global.h"
#include "trainer_pokemon_sprites.h"
#include "bg.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "field_effect.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "main.h"
#include "main_menu.h"
#include "menu.h"
#include "list_menu.h"
#include "naming_screen.h"
#include "oak_speech_hns.h"
#include "challenge_menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokeball.h"
#include "pokemon.h"
#include "random.h"
#include "save.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"

#if IS_HNS

extern const u8 gText_Oak_Welcome[];
extern const u8 gText_Oak_MainSpeech[];
extern const u8 gText_Oak_AndYouAre[];
extern const u8 gText_Oak_BoyOrGirl[];
extern const u8 gText_Oak_WhatChallenge[];
extern const u8 gText_Oak_WhatsYourName[];
extern const u8 gText_Oak_SoItsPlayer[];
extern const u8 gText_Oak_YourePlayer[];
extern const u8 gText_Oak_AreYouReady[];

static EWRAM_DATA bool8 sStartedPokeBallTask = 0;

static u8 sHnsSpeechMainTaskId;

// Static function declarations
static void Task_NewGameHnsSpeech_Init(u8);
static void AddHnsSpeechObjects(u8);
static void Task_NewGameHnsSpeech_WaitToShowProfessor(u8);
static void NewGameHnsSpeech_StartFadeInTarget1OutTarget2(u8, u8);
static void NewGameHnsSpeech_StartFadePlatformOut(u8, u8);
static void Task_NewGameHnsSpeech_WaitForSpriteFadeInWelcome(u8);
static void NewGameHnsSpeech_ClearWindow(u8);
static void Task_NewGameHnsSpeech_ThisIsAPokemon(u8);
static void Task_NewGameHnsSpeech_MainSpeech(u8);
static void NewGameHnsSpeech_WaitForThisIsPokemonText(struct TextPrinterTemplate *, u16);
static void Task_NewGameHnsSpeech_AndYouAre(u8);
static void Task_NewGameHnsSpeechSub_WaitForMon(u8);
static void Task_NewGameHnsSpeech_StartProfessorMonPlatformFade(u8);
static void NewGameHnsSpeech_StartFadeOutTarget1InTarget2(u8, u8);
static void NewGameHnsSpeech_StartFadePlatformIn(u8, u8);
static void Task_NewGameHnsSpeech_SlidePlatformAway(u8);
static void Task_NewGameHnsSpeech_StartPlayerFadeIn(u8);
static void Task_NewGameHnsSpeech_WaitForPlayerFadeIn(u8);
static void Task_NewGameHnsSpeech_BoyOrGirl(u8);
static void Task_NewGameHnsSpeech_WaitToShowGenderMenu(u8);
static void Task_NewGameHnsSpeech_ChooseGender(u8);
static void NewGameHnsSpeech_ShowGenderMenu(void);
static void NewGameHnsSpeech_ClearGenderWindow(u8, u8);
static void Task_NewGameHnsSpeech_ChallengePrompt(u8);
static void Task_NewGameHnsSpeech_WaitForChallengePrompt(u8);
static void Task_NewGameHnsSpeech_WaitPressBeforeChallengeMenu(u8);
static void Task_NewGameHnsSpeech_ChallengeMenu(u8);
static void Task_NewGameHnsSpeech_WhatsYourName(u8);
static void Task_NewGameHnsSpeech_SlideOutOldGenderSprite(u8);
static void Task_NewGameHnsSpeech_SlideInNewGenderSprite(u8);
static void Task_NewGameHnsSpeech_WaitForWhatsYourNameToPrint(u8);
static void Task_NewGameHnsSpeech_WaitPressBeforeNameChoice(u8);
static void Task_NewGameHnsSpeech_StartNamingScreen(u8);
static void CB2_NewGameHnsSpeech_ReturnFromNamingScreen(void);
static void CB2_NewGameHnsSpeech_ReturnFromChallengeMenu(void);
static void Task_NewGameHnsSpeech_FadeOutToChallengeMenu(u8);
static void Task_NewGameHnsSpeech_ReturnFromChallengeMenuShowTextbox(u8);
static void Task_NewGameHnsSpeech_ReturnFromNamingScreenShowTextbox(u8);
static void Task_NewGameHnsSpeech_SoItsPlayerName(u8);
static void Task_NewGameHnsSpeech_CreateNameYesNo(u8);
static void Task_NewGameHnsSpeech_ProcessNameYesNoMenu(u8);
static void Task_NewGameHnsSpeech_SlidePlatformAway2(u8);
static void Task_NewGameHnsSpeech_ReshowProfessorMon(u8);
static void Task_NewGameHnsSpeech_WaitForSpriteFadeInAndTextPrinter(u8);
static void Task_NewGameHnsSpeech_AreYouReady(u8);
static void Task_NewGameHnsSpeech_ShrinkPlayer(u8);
static void Task_NewGameHnsSpeech_WaitForPlayerShrink(u8);
static void Task_NewGameHnsSpeech_FadePlayerToWhite(u8);
static void Task_NewGameHnsSpeech_Cleanup(u8);
static void Task_NewGameHnsSpeechSub_InitPokeBall(u8);
static void Task_NewGameHnsSpeech_FadeOutTarget1InTarget2(u8);
static void Task_NewGameHnsSpeech_FadeInTarget1OutTarget2(u8);
static void Task_NewGameHnsSpeech_FadePlatformIn(u8);
static void Task_NewGameHnsSpeech_FadePlatformOut(u8);
static void SpriteCB_Null(struct Sprite *);
static void SpriteCB_MovePlayerDownWhileShrinking(struct Sprite *);
static u8 NewGameHnsSpeech_CreateMonSprite(u8, u8);
static s8 NewGameHnsSpeech_ProcessGenderMenuInput(void);
static void NewGameHnsSpeech_ClearGenderWindowTilemap(u8, u8, u8, u8, u8, u8);
static void LoadMainMenuWindowFrameTiles(u8, u16);
static void DrawMainMenuWindowBorder(const struct WindowTemplate *, u16);

// .rodata

static const u16 sHnsSpeechBgPals[][16] = {
    INCBIN_U16("graphics/oak_speech_hns/bg0_hns.gbapal"),
    INCBIN_U16("graphics/oak_speech_hns/bg1_hns.gbapal")
};

static const u32 sHnsSpeechShadowGfx[] = INCBIN_U32("graphics/oak_speech_hns/shadow_hns.4bpp.smol");
static const u32 sHnsSpeechBgMap[] = INCBIN_U32("graphics/oak_speech_hns/map_hns.bin.smolTM");
static const u16 sHnsSpeechBgGradientPal[] = INCBIN_U16("graphics/oak_speech_hns/bg2_hns.gbapal");

static const struct WindowTemplate sNewGameHnsSpeechTextWindows[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1
    },
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 5,
        .width = 6,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x6D
    },
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 2,
        .width = 9,
        .height = 10,
        .paletteNum = 15,
        .baseBlock = 0x85
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sHnsBgTemplate = {
    .bg = 0,
    .charBaseIndex = 3,
    .mapBaseIndex = 30,
    .screenSize = 0,
    .paletteMode = 0,
    .priority = 0,
    .baseTile = 0
};

static const struct BgTemplate sMainMenuBgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const union AffineAnimCmd sSpriteAffineAnim_PlayerShrink[] = {
    AFFINEANIMCMD_FRAME(-2, -2, 0, 0x30),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_PlayerShrink[] =
{
    sSpriteAffineAnim_PlayerShrink
};

static const struct MenuAction sMenuActions_Gender[] = {
    {gText_Boy, {NULL}},
    {gText_Girl, {NULL}}
};

static const u8 *const sMalePresetNames[] = {
    COMPOUND_STRING("GOLD"),
};

static const u8 *const sFemalePresetNames[] = {
    COMPOUND_STRING("KRIS"),
};

#define NUM_PRESET_NAMES min(ARRAY_COUNT(sMalePresetNames), ARRAY_COUNT(sFemalePresetNames))

#define MAIN_MENU_BORDER_TILE   0x1D5
#define HNS_DLG_BASE_TILE_NUM 0xFC

// Task data defines
#define tTimer            data[0]
#define tBG1HOFS          data[1]
#define tPlayerSpriteId   data[2]
#define tPlayerGender     data[3]
#define tProfessorSpriteId data[4]
#define tMonSpriteId      data[5]
#define tGoldSpriteId     data[6]
#define tKrisSpriteId     data[7]
#define tIsDoneFadingSprites data[15]

static void CB2_HnsMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_HnsMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void StartNewGameSceneHns(void)
{
    u8 taskId;

    SetVBlankCallback(NULL);
    ResetTasks();
    taskId = CreateTask(Task_NewGameHnsSpeech_Init, 0);
    gTasks[taskId].tBG1HOFS = 0;
    gTasks[taskId].tPlayerSpriteId = SPRITE_NONE;
    gTasks[taskId].data[3] = 0xFF;
    gTasks[taskId].tTimer = 0xD8;

    SetVBlankCallback(VBlankCB_HnsMenu);
    SetMainCallback2(CB2_HnsMenu);
}

static void Task_NewGameHnsSpeech_Init(u8 taskId)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ResetPaletteFade();
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    InitBgFromTemplate(&sHnsBgTemplate);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);

    DecompressDataWithHeaderVram(sHnsSpeechShadowGfx, (void *)VRAM);
    DecompressDataWithHeaderVram(sHnsSpeechBgMap, (void *)(BG_SCREEN_ADDR(7)));
    LoadPalette(sHnsSpeechBgPals, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
    LoadPalette(&sHnsSpeechBgGradientPal[8], BG_PLTT_ID(0) + 1, PLTT_SIZEOF(8));
    ScanlineEffect_Stop();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    AddHnsSpeechObjects(taskId);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    gTasks[taskId].func = Task_NewGameHnsSpeech_WaitToShowProfessor;
    PlayBGM(MUS_HG_NEW_GAME);
    ShowBg(0);
    ShowBg(1);
}

static void Task_NewGameHnsSpeech_WaitToShowProfessor(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].tTimer)
    {
        gTasks[taskId].tTimer--;
    }
    else
    {
        spriteId = gTasks[taskId].tProfessorSpriteId;
        gSprites[spriteId].x = 136;
        gSprites[spriteId].y = 60;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        NewGameHnsSpeech_StartFadeInTarget1OutTarget2(taskId, 10);
        NewGameHnsSpeech_StartFadePlatformOut(taskId, 20);
        gTasks[taskId].tTimer = 80;
        gTasks[taskId].func = Task_NewGameHnsSpeech_WaitForSpriteFadeInWelcome;
    }
}

static void Task_NewGameHnsSpeech_WaitForSpriteFadeInWelcome(u8 taskId)
{
    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tProfessorSpriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
        if (gTasks[taskId].tTimer)
        {
            gTasks[taskId].tTimer--;
        }
        else
        {
            InitWindows(sNewGameHnsSpeechTextWindows);
            LoadMainMenuWindowFrameTiles(0, 0xF3);
            LoadMessageBoxGfx(0, HNS_DLG_BASE_TILE_NUM, BG_PLTT_ID(15));
            DrawDialogFrameWithCustomTile(0, TRUE, HNS_DLG_BASE_TILE_NUM);
            PutWindowTilemap(0);
            CopyWindowToVram(0, COPYWIN_GFX);
            NewGameHnsSpeech_ClearWindow(0);
            StringExpandPlaceholders(gStringVar4, gText_Oak_Welcome);
            AddTextPrinterForMessage(TRUE);
            gTasks[taskId].func = Task_NewGameHnsSpeech_ThisIsAPokemon;
        }
    }
}

static void Task_NewGameHnsSpeech_ThisIsAPokemon(u8 taskId)
{
    if (!gPaletteFade.active && !RunTextPrintersAndIsPrinter0Active())
    {
        gTasks[taskId].func = Task_NewGameHnsSpeech_MainSpeech;
        StringExpandPlaceholders(gStringVar4, gText_ThisIsAPokemon);
        AddTextPrinterWithCallbackForMessage(TRUE, NewGameHnsSpeech_WaitForThisIsPokemonText);
        sHnsSpeechMainTaskId = taskId;
    }
}

static void Task_NewGameHnsSpeech_MainSpeech(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        StringExpandPlaceholders(gStringVar4, gText_Oak_MainSpeech);
        AddTextPrinterForMessage(TRUE);
        gTasks[taskId].func = Task_NewGameHnsSpeech_AndYouAre;
    }
}

#define tState data[0]

static void Task_NewGameHnsSpeechSub_InitPokeBall(u8 taskId)
{
    u8 spriteId = gTasks[sHnsSpeechMainTaskId].tMonSpriteId;

    gSprites[spriteId].x = 100;
    gSprites[spriteId].y = 75;
    gSprites[spriteId].invisible = FALSE;
    gSprites[spriteId].data[0] = 0;

    CreatePokeballSpriteToReleaseMon(spriteId, gSprites[spriteId].oam.paletteNum, 112, 58, 0, 0, 32, PALETTES_BG, SPECIES_WOOPER);
    gTasks[taskId].func = Task_NewGameHnsSpeechSub_WaitForMon;
    gTasks[sHnsSpeechMainTaskId].tTimer = 0;
}

static void Task_NewGameHnsSpeechSub_WaitForMon(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct Sprite *sprite = &gSprites[gTasks[sHnsSpeechMainTaskId].tMonSpriteId];

    switch (tState)
    {
    case 0:
        if (sprite->callback != SpriteCallbackDummy)
            return;
        sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
        break;
    case 1:
        if (gTasks[sHnsSpeechMainTaskId].tTimer >= 96)
        {
            DestroyTask(taskId);
            if (gTasks[sHnsSpeechMainTaskId].tTimer < 0x4000)
                gTasks[sHnsSpeechMainTaskId].tTimer++;
        }
        return;
    }
    tState++;
    if (gTasks[sHnsSpeechMainTaskId].tTimer < 0x4000)
        gTasks[sHnsSpeechMainTaskId].tTimer++;
}

#undef tState

static void Task_NewGameHnsSpeech_AndYouAre(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        sStartedPokeBallTask = FALSE;
        StringExpandPlaceholders(gStringVar4, gText_Oak_AndYouAre);
        AddTextPrinterForMessage(TRUE);
        gTasks[taskId].func = Task_NewGameHnsSpeech_StartProfessorMonPlatformFade;
    }
}

static void Task_NewGameHnsSpeech_StartProfessorMonPlatformFade(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        gSprites[gTasks[taskId].tProfessorSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        gSprites[gTasks[taskId].tMonSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        NewGameHnsSpeech_StartFadeOutTarget1InTarget2(taskId, 2);
        NewGameHnsSpeech_StartFadePlatformIn(taskId, 1);
        gTasks[taskId].tTimer = 64;
        gTasks[taskId].func = Task_NewGameHnsSpeech_SlidePlatformAway;
    }
}

static void Task_NewGameHnsSpeech_SlidePlatformAway(u8 taskId)
{
    if (gTasks[taskId].tBG1HOFS != -60)
    {
        gTasks[taskId].tBG1HOFS -= 2;
        SetGpuReg(REG_OFFSET_BG1HOFS, gTasks[taskId].tBG1HOFS);
    }
    else
    {
        gTasks[taskId].tBG1HOFS = -60;
        gTasks[taskId].func = Task_NewGameHnsSpeech_StartPlayerFadeIn;
    }
}

static void Task_NewGameHnsSpeech_StartPlayerFadeIn(u8 taskId)
{
    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tProfessorSpriteId].invisible = TRUE;
        gSprites[gTasks[taskId].tMonSpriteId].invisible = TRUE;
        if (gTasks[taskId].tTimer)
        {
            gTasks[taskId].tTimer--;
        }
        else
        {
            u8 spriteId = gTasks[taskId].tGoldSpriteId;

            gSprites[spriteId].x = 180;
            gSprites[spriteId].y = 60;
            gSprites[spriteId].invisible = FALSE;
            gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
            gTasks[taskId].tPlayerSpriteId = spriteId;
            gTasks[taskId].tPlayerGender = MALE;
            NewGameHnsSpeech_StartFadeInTarget1OutTarget2(taskId, 2);
            NewGameHnsSpeech_StartFadePlatformOut(taskId, 1);
            gTasks[taskId].func = Task_NewGameHnsSpeech_WaitForPlayerFadeIn;
        }
    }
}

static void Task_NewGameHnsSpeech_WaitForPlayerFadeIn(u8 taskId)
{
    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tPlayerSpriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
        gTasks[taskId].func = Task_NewGameHnsSpeech_BoyOrGirl;
    }
}

static void Task_NewGameHnsSpeech_BoyOrGirl(u8 taskId)
{
    NewGameHnsSpeech_ClearWindow(0);
    StringExpandPlaceholders(gStringVar4, gText_Oak_BoyOrGirl);
    AddTextPrinterForMessage(TRUE);
    gTasks[taskId].func = Task_NewGameHnsSpeech_WaitToShowGenderMenu;
}

static void Task_NewGameHnsSpeech_WaitToShowGenderMenu(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        NewGameHnsSpeech_ShowGenderMenu();
        gTasks[taskId].func = Task_NewGameHnsSpeech_ChooseGender;
    }
}

static void Task_NewGameHnsSpeech_ChooseGender(u8 taskId)
{
    enum Gender gender = NewGameHnsSpeech_ProcessGenderMenuInput();
    enum Gender gender2;

    switch (gender)
    {
    case MALE:
        PlaySE(SE_SELECT);
        gSaveBlock2Ptr->playerGender = gender;
        NewGameHnsSpeech_ClearGenderWindow(1, 1);
        gTasks[taskId].func = Task_NewGameHnsSpeech_ChallengePrompt;
        break;
    case FEMALE:
        PlaySE(SE_SELECT);
        gSaveBlock2Ptr->playerGender = gender;
        NewGameHnsSpeech_ClearGenderWindow(1, 1);
        gTasks[taskId].func = Task_NewGameHnsSpeech_ChallengePrompt;
        break;
    default:
        break;
    }
    gender2 = Menu_GetCursorPos();
    if (gender2 != gTasks[taskId].tPlayerGender)
    {
        gTasks[taskId].tPlayerGender = gender2;
        gSprites[gTasks[taskId].tPlayerSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        NewGameHnsSpeech_StartFadeOutTarget1InTarget2(taskId, 0);
        gTasks[taskId].func = Task_NewGameHnsSpeech_SlideOutOldGenderSprite;
    }
}

static void Task_NewGameHnsSpeech_SlideOutOldGenderSprite(u8 taskId)
{
    u8 spriteId = gTasks[taskId].tPlayerSpriteId;
    if (gTasks[taskId].tIsDoneFadingSprites == 0)
    {
        gSprites[spriteId].x += 4;
    }
    else
    {
        gSprites[spriteId].invisible = TRUE;
        if (gTasks[taskId].tPlayerGender != MALE)
            spriteId = gTasks[taskId].tKrisSpriteId;
        else
            spriteId = gTasks[taskId].tGoldSpriteId;
        gSprites[spriteId].x = DISPLAY_WIDTH;
        gSprites[spriteId].y = 60;
        gSprites[spriteId].invisible = FALSE;
        gTasks[taskId].tPlayerSpriteId = spriteId;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        NewGameHnsSpeech_StartFadeInTarget1OutTarget2(taskId, 0);
        gTasks[taskId].func = Task_NewGameHnsSpeech_SlideInNewGenderSprite;
    }
}

static void Task_NewGameHnsSpeech_SlideInNewGenderSprite(u8 taskId)
{
    u8 spriteId = gTasks[taskId].tPlayerSpriteId;

    if (gSprites[spriteId].x > 180)
    {
        gSprites[spriteId].x -= 4;
    }
    else
    {
        gSprites[spriteId].x = 180;
        if (gTasks[taskId].tIsDoneFadingSprites)
        {
            gSprites[spriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
            gTasks[taskId].func = Task_NewGameHnsSpeech_ChooseGender;
        }
    }
}

static void Task_NewGameHnsSpeech_ChallengePrompt(u8 taskId)
{
    NewGameHnsSpeech_ClearWindow(0);
    StringExpandPlaceholders(gStringVar4, gText_Oak_WhatChallenge);
    AddTextPrinterForMessage(TRUE);
    gTasks[taskId].func = Task_NewGameHnsSpeech_WaitForChallengePrompt;
}

static void Task_NewGameHnsSpeech_WaitForChallengePrompt(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
        gTasks[taskId].func = Task_NewGameHnsSpeech_WaitPressBeforeChallengeMenu;
}

static void Task_NewGameHnsSpeech_WaitPressBeforeChallengeMenu(u8 taskId)
{
    if ((JOY_NEW(A_BUTTON)) || (JOY_NEW(B_BUTTON)))
        gTasks[taskId].func = Task_NewGameHnsSpeech_ChallengeMenu;
}

static void Task_NewGameHnsSpeech_ChallengeMenu(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_NewGameHnsSpeech_FadeOutToChallengeMenu;
}

static void Task_NewGameHnsSpeech_FadeOutToChallengeMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        DestroyTask(taskId);
        gMain.savedCallback = CB2_NewGameHnsSpeech_ReturnFromChallengeMenu;
        SetMainCallback2(CB2_InitChallengeMenu);
    }
}

static void Task_NewGameHnsSpeech_WhatsYourName(u8 taskId)
{
    NewGameHnsSpeech_ClearWindow(0);
    StringExpandPlaceholders(gStringVar4, gText_Oak_WhatsYourName);
    AddTextPrinterForMessage(TRUE);
    gTasks[taskId].func = Task_NewGameHnsSpeech_WaitForWhatsYourNameToPrint;
}

static void Task_NewGameHnsSpeech_WaitForWhatsYourNameToPrint(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
        gTasks[taskId].func = Task_NewGameHnsSpeech_WaitPressBeforeNameChoice;
}

static void Task_NewGameHnsSpeech_WaitPressBeforeNameChoice(u8 taskId)
{
    if ((JOY_NEW(A_BUTTON)) || (JOY_NEW(B_BUTTON)))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_NewGameHnsSpeech_StartNamingScreen;
    }
}

static void NewGameHnsSpeech_SetDefaultPlayerName(u8 nameId)
{
    const u8 *name;
    u8 i;

    if (gSaveBlock2Ptr->playerGender == MALE)
        name = sMalePresetNames[nameId];
    else
        name = sFemalePresetNames[nameId];
    for (i = 0; i < PLAYER_NAME_LENGTH; i++)
        gSaveBlock2Ptr->playerName[i] = name[i];
    gSaveBlock2Ptr->playerName[PLAYER_NAME_LENGTH] = EOS;
}

static void Task_NewGameHnsSpeech_StartNamingScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        NewGameHnsSpeech_SetDefaultPlayerName(Random() % NUM_PRESET_NAMES);
        DestroyTask(taskId);
        DoNamingScreen(NAMING_SCREEN_PLAYER, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_NewGameHnsSpeech_ReturnFromNamingScreen);
    }
}

static void Task_NewGameHnsSpeech_SoItsPlayerName(u8 taskId)
{
    NewGameHnsSpeech_ClearWindow(0);
    StringExpandPlaceholders(gStringVar4, gText_Oak_SoItsPlayer);
    AddTextPrinterForMessage(TRUE);
    gTasks[taskId].func = Task_NewGameHnsSpeech_CreateNameYesNo;
}

static void Task_NewGameHnsSpeech_CreateNameYesNo(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        CreateYesNoMenuParameterized(2, 1, 0xF3, 0xDF, 2, 15);
        gTasks[taskId].func = Task_NewGameHnsSpeech_ProcessNameYesNoMenu;
    }
}

static void Task_NewGameHnsSpeech_ProcessNameYesNoMenu(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        PlaySE(SE_SELECT);
        gSprites[gTasks[taskId].tPlayerSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        NewGameHnsSpeech_StartFadeOutTarget1InTarget2(taskId, 2);
        NewGameHnsSpeech_StartFadePlatformIn(taskId, 1);
        gTasks[taskId].func = Task_NewGameHnsSpeech_SlidePlatformAway2;
        break;
    case MENU_B_PRESSED:
    case 1:
        PlaySE(SE_SELECT);
        gTasks[taskId].func = Task_NewGameHnsSpeech_BoyOrGirl;
    }
}

static void Task_NewGameHnsSpeech_SlidePlatformAway2(u8 taskId)
{
    if (gTasks[taskId].tBG1HOFS)
    {
        gTasks[taskId].tBG1HOFS += 2;
        SetGpuReg(REG_OFFSET_BG1HOFS, gTasks[taskId].tBG1HOFS);
    }
    else
    {
        gTasks[taskId].func = Task_NewGameHnsSpeech_ReshowProfessorMon;
    }
}

static void Task_NewGameHnsSpeech_ReshowProfessorMon(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tGoldSpriteId].invisible = TRUE;
        gSprites[gTasks[taskId].tKrisSpriteId].invisible = TRUE;
        spriteId = gTasks[taskId].tProfessorSpriteId;
        gSprites[spriteId].x = 136;
        gSprites[spriteId].y = 60;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        spriteId = gTasks[taskId].tMonSpriteId;
        gSprites[spriteId].x = 100;
        gSprites[spriteId].y = 75;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        NewGameHnsSpeech_StartFadeInTarget1OutTarget2(taskId, 2);
        NewGameHnsSpeech_StartFadePlatformOut(taskId, 1);
        NewGameHnsSpeech_ClearWindow(0);
        StringExpandPlaceholders(gStringVar4, gText_Oak_YourePlayer);
        AddTextPrinterForMessage(TRUE);
        gTasks[taskId].func = Task_NewGameHnsSpeech_WaitForSpriteFadeInAndTextPrinter;
    }
}

static void Task_NewGameHnsSpeech_WaitForSpriteFadeInAndTextPrinter(u8 taskId)
{
    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tProfessorSpriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
        gSprites[gTasks[taskId].tMonSpriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
        if (!RunTextPrintersAndIsPrinter0Active())
        {
            gSprites[gTasks[taskId].tProfessorSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
            gSprites[gTasks[taskId].tMonSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
            NewGameHnsSpeech_StartFadeOutTarget1InTarget2(taskId, 2);
            NewGameHnsSpeech_StartFadePlatformIn(taskId, 1);
            gTasks[taskId].tTimer = 64;
            gTasks[taskId].func = Task_NewGameHnsSpeech_AreYouReady;
        }
    }
}

static void Task_NewGameHnsSpeech_AreYouReady(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tProfessorSpriteId].invisible = TRUE;
        gSprites[gTasks[taskId].tMonSpriteId].invisible = TRUE;
        if (gTasks[taskId].tTimer)
        {
            gTasks[taskId].tTimer--;
            return;
        }
        if (gSaveBlock2Ptr->playerGender != MALE)
            spriteId = gTasks[taskId].tKrisSpriteId;
        else
            spriteId = gTasks[taskId].tGoldSpriteId;
        gSprites[spriteId].x = 120;
        gSprites[spriteId].y = 60;
        gSprites[spriteId].invisible = FALSE;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        gTasks[taskId].tPlayerSpriteId = spriteId;
        NewGameHnsSpeech_StartFadeInTarget1OutTarget2(taskId, 2);
        NewGameHnsSpeech_StartFadePlatformOut(taskId, 1);
        StringExpandPlaceholders(gStringVar4, gText_Oak_AreYouReady);
        AddTextPrinterForMessage(TRUE);
        gTasks[taskId].func = Task_NewGameHnsSpeech_ShrinkPlayer;
    }
}

static void Task_NewGameHnsSpeech_ShrinkPlayer(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].tIsDoneFadingSprites)
    {
        gSprites[gTasks[taskId].tPlayerSpriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
        if (!RunTextPrintersAndIsPrinter0Active())
        {
            spriteId = gTasks[taskId].tPlayerSpriteId;
            gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
            gSprites[spriteId].affineAnims = sSpriteAffineAnimTable_PlayerShrink;
            InitSpriteAffineAnim(&gSprites[spriteId]);
            StartSpriteAffineAnim(&gSprites[spriteId], 0);
            gSprites[spriteId].callback = SpriteCB_MovePlayerDownWhileShrinking;
            BeginNormalPaletteFade(PALETTES_BG, 0, 0, 16, RGB_BLACK);
            FadeOutBGM(4);
            gTasks[taskId].func = Task_NewGameHnsSpeech_WaitForPlayerShrink;
        }
    }
}

static void Task_NewGameHnsSpeech_WaitForPlayerShrink(u8 taskId)
{
    u8 spriteId = gTasks[taskId].tPlayerSpriteId;

    if (gSprites[spriteId].affineAnimEnded)
        gTasks[taskId].func = Task_NewGameHnsSpeech_FadePlayerToWhite;
}

static void Task_NewGameHnsSpeech_FadePlayerToWhite(u8 taskId)
{
    u8 spriteId;

    if (!gPaletteFade.active)
    {
        spriteId = gTasks[taskId].tPlayerSpriteId;
        gSprites[spriteId].callback = SpriteCB_Null;
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        BeginNormalPaletteFade(PALETTES_OBJECTS, 0, 0, 16, RGB_WHITEALPHA);
        gTasks[taskId].func = Task_NewGameHnsSpeech_Cleanup;
    }
}

static void Task_NewGameHnsSpeech_Cleanup(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        ResetAllPicSprites();
        SetMainCallback2(CB2_NewGame);
        DestroyTask(taskId);
    }
}

static void CB2_NewGameHnsSpeech_ReturnFromNamingScreen(void)
{
    u8 taskId;
    u8 spriteId;
    u16 savedIme;

    ResetBgsAndClearDma3BusyFlags(0);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    InitBgsFromTemplates(0, sMainMenuBgTemplates, ARRAY_COUNT(sMainMenuBgTemplates));
    InitBgFromTemplate(&sHnsBgTemplate);
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ResetPaletteFade();
    DecompressDataWithHeaderVram(sHnsSpeechShadowGfx, (u8 *)VRAM);
    DecompressDataWithHeaderVram(sHnsSpeechBgMap, (u8 *)(BG_SCREEN_ADDR(7)));
    LoadPalette(sHnsSpeechBgPals, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
    LoadPalette(&sHnsSpeechBgGradientPal[1], BG_PLTT_ID(0) + 1, PLTT_SIZEOF(8));
    ResetTasks();
    taskId = CreateTask(Task_NewGameHnsSpeech_ReturnFromNamingScreenShowTextbox, 0);
    gTasks[taskId].tTimer = 5;
    gTasks[taskId].tBG1HOFS = -60;
    ScanlineEffect_Stop();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    AddHnsSpeechObjects(taskId);
    if (gSaveBlock2Ptr->playerGender != MALE)
    {
        gTasks[taskId].tPlayerGender = FEMALE;
        spriteId = gTasks[taskId].tKrisSpriteId;
    }
    else
    {
        gTasks[taskId].tPlayerGender = MALE;
        spriteId = gTasks[taskId].tGoldSpriteId;
    }
    gSprites[spriteId].x = 180;
    gSprites[spriteId].y = 60;
    gSprites[spriteId].invisible = FALSE;
    gTasks[taskId].tPlayerSpriteId = spriteId;
    SetGpuReg(REG_OFFSET_BG1HOFS, -60);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    ShowBg(0);
    ShowBg(1);
    savedIme = REG_IME;
    REG_IME = 0;
    REG_IE |= 1;
    REG_IME = savedIme;
    SetVBlankCallback(VBlankCB_HnsMenu);
    SetMainCallback2(CB2_HnsMenu);
    InitWindows(sNewGameHnsSpeechTextWindows);
    LoadMainMenuWindowFrameTiles(0, 0xF3);
    LoadMessageBoxGfx(0, HNS_DLG_BASE_TILE_NUM, BG_PLTT_ID(15));
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
}

static void CB2_NewGameHnsSpeech_ReturnFromChallengeMenu(void)
{
    u8 taskId;
    u8 spriteId;
    u16 savedIme;

    ResetBgsAndClearDma3BusyFlags(0);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    InitBgsFromTemplates(0, sMainMenuBgTemplates, ARRAY_COUNT(sMainMenuBgTemplates));
    InitBgFromTemplate(&sHnsBgTemplate);
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ResetPaletteFade();
    DecompressDataWithHeaderVram(sHnsSpeechShadowGfx, (u8 *)VRAM);
    DecompressDataWithHeaderVram(sHnsSpeechBgMap, (u8 *)(BG_SCREEN_ADDR(7)));
    LoadPalette(sHnsSpeechBgPals, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
    LoadPalette(&sHnsSpeechBgGradientPal[1], BG_PLTT_ID(0) + 1, PLTT_SIZEOF(8));
    ResetTasks();
    taskId = CreateTask(Task_NewGameHnsSpeech_ReturnFromChallengeMenuShowTextbox, 0);
    gTasks[taskId].tTimer = 5;
    gTasks[taskId].tBG1HOFS = -60;
    ScanlineEffect_Stop();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    AddHnsSpeechObjects(taskId);
    if (gSaveBlock2Ptr->playerGender != MALE)
    {
        gTasks[taskId].tPlayerGender = FEMALE;
        spriteId = gTasks[taskId].tKrisSpriteId;
    }
    else
    {
        gTasks[taskId].tPlayerGender = MALE;
        spriteId = gTasks[taskId].tGoldSpriteId;
    }
    gSprites[spriteId].x = 180;
    gSprites[spriteId].y = 60;
    gSprites[spriteId].invisible = FALSE;
    gTasks[taskId].tPlayerSpriteId = spriteId;
    SetGpuReg(REG_OFFSET_BG1HOFS, -60);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    ShowBg(0);
    ShowBg(1);
    savedIme = REG_IME;
    REG_IME = 0;
    REG_IE |= 1;
    REG_IME = savedIme;
    SetVBlankCallback(VBlankCB_HnsMenu);
    SetMainCallback2(CB2_HnsMenu);
    InitWindows(sNewGameHnsSpeechTextWindows);
    LoadMainMenuWindowFrameTiles(0, 0xF3);
    LoadMessageBoxGfx(0, HNS_DLG_BASE_TILE_NUM, BG_PLTT_ID(15));
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
}

static void Task_NewGameHnsSpeech_ReturnFromChallengeMenuShowTextbox(u8 taskId)
{
    if (gTasks[taskId].tTimer-- <= 0)
    {
        DrawDialogFrameWithCustomTile(0, TRUE, HNS_DLG_BASE_TILE_NUM);
        gTasks[taskId].func = Task_NewGameHnsSpeech_WhatsYourName;
    }
}

static void SpriteCB_Null(struct Sprite *sprite)
{
}

static void SpriteCB_MovePlayerDownWhileShrinking(struct Sprite *sprite)
{
    u32 y;

    y = (sprite->y << 16) + sprite->data[0] + 0xC000;
    sprite->y = y >> 16;
    sprite->data[0] = y;
}

static u8 NewGameHnsSpeech_CreateMonSprite(u8 x, u8 y)
{
    return CreateMonPicSprite_Affine(SPECIES_WOOPER, FALSE, 0, MON_PIC_AFFINE_FRONT, x, y, 14, TAG_NONE);
}

static void AddHnsSpeechObjects(u8 taskId)
{
    u8 professorSpriteId;
    u8 monSpriteId;
    u8 goldSpriteId;
    u8 krisSpriteId;

    professorSpriteId = AddNewGameOakObject(0x88, 0x3C, 1);
    gSprites[professorSpriteId].callback = SpriteCB_Null;
    gSprites[professorSpriteId].oam.priority = 0;
    gSprites[professorSpriteId].invisible = TRUE;
    gTasks[taskId].tProfessorSpriteId = professorSpriteId;
    monSpriteId = NewGameHnsSpeech_CreateMonSprite(100, 0x4B);
    gSprites[monSpriteId].callback = SpriteCB_Null;
    gSprites[monSpriteId].oam.priority = 0;
    gSprites[monSpriteId].invisible = TRUE;
    gTasks[taskId].tMonSpriteId = monSpriteId;
    goldSpriteId = CreateTrainerSprite(FacilityClassToPicIndex(FACILITY_CLASS_GOLD_HNS), 120, 60, 0, NULL);
    gSprites[goldSpriteId].callback = SpriteCB_Null;
    gSprites[goldSpriteId].invisible = TRUE;
    gSprites[goldSpriteId].oam.priority = 0;
    gTasks[taskId].tGoldSpriteId = goldSpriteId;
    krisSpriteId = CreateTrainerSprite(FacilityClassToPicIndex(FACILITY_CLASS_KRIS_HNS), 120, 60, 0, NULL);
    gSprites[krisSpriteId].callback = SpriteCB_Null;
    gSprites[krisSpriteId].invisible = TRUE;
    gSprites[krisSpriteId].oam.priority = 0;
    gTasks[taskId].tKrisSpriteId = krisSpriteId;
}

#undef tPlayerSpriteId
#undef tBG1HOFS
#undef tPlayerGender
#undef tProfessorSpriteId
#undef tMonSpriteId
#undef tGoldSpriteId
#undef tKrisSpriteId

#define tMainTask data[0]
#define tAlphaCoeff1 data[1]
#define tAlphaCoeff2 data[2]
#define tDelay data[3]
#define tDelayTimer data[4]

static void Task_NewGameHnsSpeech_FadeOutTarget1InTarget2(u8 taskId)
{
    int alphaCoeff2;

    if (gTasks[taskId].tAlphaCoeff1 == 0)
    {
        gTasks[gTasks[taskId].tMainTask].tIsDoneFadingSprites = TRUE;
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tAlphaCoeff1--;
        gTasks[taskId].tAlphaCoeff2++;
        alphaCoeff2 = gTasks[taskId].tAlphaCoeff2 << 8;
        SetGpuReg(REG_OFFSET_BLDALPHA, gTasks[taskId].tAlphaCoeff1 + alphaCoeff2);
    }
}

static void NewGameHnsSpeech_StartFadeOutTarget1InTarget2(u8 taskId, u8 delay)
{
    u8 taskId2;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_OBJ);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].tIsDoneFadingSprites = 0;
    taskId2 = CreateTask(Task_NewGameHnsSpeech_FadeOutTarget1InTarget2, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tAlphaCoeff1 = 16;
    gTasks[taskId2].tAlphaCoeff2 = 0;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

static void Task_NewGameHnsSpeech_FadeInTarget1OutTarget2(u8 taskId)
{
    int alphaCoeff2;

    if (gTasks[taskId].tAlphaCoeff1 == 16)
    {
        gTasks[gTasks[taskId].tMainTask].tIsDoneFadingSprites = TRUE;
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tAlphaCoeff1++;
        gTasks[taskId].tAlphaCoeff2--;
        alphaCoeff2 = gTasks[taskId].tAlphaCoeff2 << 8;
        SetGpuReg(REG_OFFSET_BLDALPHA, gTasks[taskId].tAlphaCoeff1 + alphaCoeff2);
    }
}

static void NewGameHnsSpeech_StartFadeInTarget1OutTarget2(u8 taskId, u8 delay)
{
    u8 taskId2;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_OBJ);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].tIsDoneFadingSprites = 0;
    taskId2 = CreateTask(Task_NewGameHnsSpeech_FadeInTarget1OutTarget2, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tAlphaCoeff1 = 0;
    gTasks[taskId2].tAlphaCoeff2 = 16;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

#undef tMainTask
#undef tAlphaCoeff1
#undef tAlphaCoeff2
#undef tDelay
#undef tDelayTimer

#undef tIsDoneFadingSprites

#define tMainTask data[0]
#define tPalIndex data[1]
#define tDelayBefore data[2]
#define tDelay data[3]
#define tDelayTimer data[4]

static void Task_NewGameHnsSpeech_FadePlatformIn(u8 taskId)
{
    if (gTasks[taskId].tDelayBefore)
    {
        gTasks[taskId].tDelayBefore--;
    }
    else if (gTasks[taskId].tPalIndex == 8)
    {
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tPalIndex++;
        LoadPalette(&sHnsSpeechBgGradientPal[gTasks[taskId].tPalIndex], BG_PLTT_ID(0) + 1, PLTT_SIZEOF(8));
    }
}

static void NewGameHnsSpeech_StartFadePlatformIn(u8 taskId, u8 delay)
{
    u8 taskId2;

    taskId2 = CreateTask(Task_NewGameHnsSpeech_FadePlatformIn, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tPalIndex = 0;
    gTasks[taskId2].tDelayBefore = 8;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

static void Task_NewGameHnsSpeech_FadePlatformOut(u8 taskId)
{
    if (gTasks[taskId].tDelayBefore)
    {
        gTasks[taskId].tDelayBefore--;
    }
    else if (gTasks[taskId].tPalIndex == 0)
    {
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tPalIndex--;
        LoadPalette(&sHnsSpeechBgGradientPal[gTasks[taskId].tPalIndex], BG_PLTT_ID(0) + 1, PLTT_SIZEOF(8));
    }
}

static void NewGameHnsSpeech_StartFadePlatformOut(u8 taskId, u8 delay)
{
    u8 taskId2;

    taskId2 = CreateTask(Task_NewGameHnsSpeech_FadePlatformOut, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tPalIndex = 8;
    gTasks[taskId2].tDelayBefore = 8;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

#undef tMainTask
#undef tPalIndex
#undef tDelayBefore
#undef tDelay
#undef tDelayTimer

static void NewGameHnsSpeech_ShowGenderMenu(void)
{
    DrawMainMenuWindowBorder(&sNewGameHnsSpeechTextWindows[1], 0xF3);
    FillWindowPixelBuffer(1, PIXEL_FILL(1));
    PrintMenuTable(1, ARRAY_COUNT(sMenuActions_Gender), sMenuActions_Gender);
    InitMenuInUpperLeftCornerNormal(1, ARRAY_COUNT(sMenuActions_Gender), 0);
    PutWindowTilemap(1);
    CopyWindowToVram(1, COPYWIN_FULL);
}

static s8 NewGameHnsSpeech_ProcessGenderMenuInput(void)
{
    return Menu_ProcessInputNoWrap();
}

static void NewGameHnsSpeech_ClearGenderWindowTilemap(u8 bg, u8 x, u8 y, u8 width, u8 height, u8 unused)
{
    FillBgTilemapBufferRect(bg, 0, x + 255, y + 255, width + 2, height + 2, 2);
}

static void NewGameHnsSpeech_ClearGenderWindow(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, NewGameHnsSpeech_ClearGenderWindowTilemap);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void NewGameHnsSpeech_ClearWindow(u8 windowId)
{
    u8 bgColor = GetFontAttribute(FONT_NORMAL, FONTATTR_COLOR_BACKGROUND);
    u8 maxCharWidth = GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_WIDTH);
    u8 maxCharHeight = GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_HEIGHT);
    u8 winWidth = GetWindowAttribute(windowId, WINDOW_WIDTH);
    u8 winHeight = GetWindowAttribute(windowId, WINDOW_HEIGHT);

    FillWindowPixelRect(windowId, bgColor, 0, 0, maxCharWidth * winWidth, maxCharHeight * winHeight);
    CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void NewGameHnsSpeech_WaitForThisIsPokemonText(struct TextPrinterTemplate *printer, u16 renderCmd)
{
    if (*(printer->currentChar - 2) == EXT_CTRL_CODE_PAUSE && !sStartedPokeBallTask)
    {
        sStartedPokeBallTask = TRUE;
        CreateTask(Task_NewGameHnsSpeechSub_InitPokeBall, 0);
    }
}

static void Task_NewGameHnsSpeech_ReturnFromNamingScreenShowTextbox(u8 taskId)
{
    if (gTasks[taskId].tTimer-- <= 0)
    {
        DrawDialogFrameWithCustomTile(0, TRUE, HNS_DLG_BASE_TILE_NUM);
        gTasks[taskId].func = Task_NewGameHnsSpeech_SoItsPlayerName;
    }
}

static void LoadMainMenuWindowFrameTiles(u8 bgId, u16 tileOffset)
{
    LoadBgTiles(bgId, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, tileOffset);
    LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
}

static void DrawMainMenuWindowBorder(const struct WindowTemplate *template, u16 baseTileNum)
{
    u16 r9 = 1 + baseTileNum;
    u16 r10 = 2 + baseTileNum;
    u16 sp18 = 3 + baseTileNum;
    u16 spC = 5 + baseTileNum;
    u16 sp10 = 6 + baseTileNum;
    u16 sp14 = 7 + baseTileNum;
    u16 r6 = 8 + baseTileNum;

    FillBgTilemapBufferRect(template->bg, baseTileNum, template->tilemapLeft - 1, template->tilemapTop - 1, 1, 1, 2);
    FillBgTilemapBufferRect(template->bg, r9, template->tilemapLeft, template->tilemapTop - 1, template->width, 1, 2);
    FillBgTilemapBufferRect(template->bg, r10, template->tilemapLeft + template->width, template->tilemapTop - 1, 1, 1, 2);
    FillBgTilemapBufferRect(template->bg, sp18, template->tilemapLeft - 1, template->tilemapTop, 1, template->height, 2);
    FillBgTilemapBufferRect(template->bg, spC, template->tilemapLeft + template->width, template->tilemapTop, 1, template->height, 2);
    FillBgTilemapBufferRect(template->bg, sp10, template->tilemapLeft - 1, template->tilemapTop + template->height, 1, 1, 2);
    FillBgTilemapBufferRect(template->bg, sp14, template->tilemapLeft, template->tilemapTop + template->height, template->width, 1, 2);
    FillBgTilemapBufferRect(template->bg, r6, template->tilemapLeft + template->width, template->tilemapTop + template->height, 1, 1, 2);
    CopyBgTilemapBufferToVram(template->bg);
}

#undef tTimer

#endif // IS_HNS
