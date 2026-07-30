#include "global.h"
#include "option_menu.h"
#include "bg.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "gba/m4a_internal.h"
#include "constants/rgb.h"
#include "event_data.h"
#include "string_util.h"

/* Forward declarations */
static void ReadAllCurrentSettings(u8 taskId);
static void DrawOptionsPg1(u8 taskId);
static void DrawOptionsPg2(u8 taskId);
static void DrawOptionsPg3(u8 taskId);

#define tMenuSelection    data[0]
#define tButtonMode       data[1]
#define tWindowFrameType  data[2]
#define tAIBattles        data[3]  // bit0 = trainer AI, bit1 = wild AI
#define tDifficulty       data[4]
#define tTextSpeed        data[5]

// Packed flags for all boolean options (data[6], bits 0-15)
#define BATTLE_SCENE_SHIFT     0
#define BATTLE_STYLE_SHIFT     1
#define SOUND_SHIFT            2
#define AUTO_SCROLL_SHIFT      3
#define RANDOMIZER_SHIFT       4
#define RANDOMIZER_TYPE_SHIFT  5
#define RANDOMIZER_MOVES_SHIFT 6
#define NUZLOCKE_SHIFT         7
#define AUTOSAVE_SHIFT         8
#define LEVEL_CAP_OFF_SHIFT    9
#define STAT_EDITOR_SHIFT     10
#define DEBUG_SHIFT           11

#define tPackedFlags          data[6]  // 12 booleans packed into 16 bits

// Helper macros for packed flag access
#define GET_FLAG(name) ((gTasks[taskId].tPackedFlags >> name##_SHIFT) & 1)
#define SET_FLAG(name, val) do { \
    if (val) gTasks[taskId].tPackedFlags |= (1 << name##_SHIFT); \
    else     gTasks[taskId].tPackedFlags &= ~(1 << name##_SHIFT); \
} while(0)

enum
{
    MENUITEM_TEXTSPEED,
    MENUITEM_BATTLESCENE,
    MENUITEM_BATTLESTYLE,
    MENUITEM_SOUND,
    MENUITEM_BUTTONMODE,
    MENUITEM_FRAMETYPE,
    MENUITEM_CANCEL,
    MENUITEM_COUNT,
};

// Menu items Pg2
enum
{
    MENUITEM_AIBATTLES_TRAINER,
    MENUITEM_AIBATTLES_WILD,
    MENUITEM_AUTOSCROLL,
    MENUITEM_NUZLOCKE,
    MENUITEM_AUTOSAVE,
    MENUITEM_DIFFICULTY,
    MENUITEM_CANCEL_PG2,
    MENUITEM_COUNT_PG2,
};

// Menu items Pg3
enum
{
    MENUITEM_RANDOMIZER,
    MENUITEM_RANDOMIZER_TYPE,
    MENUITEM_RANDOMIZER_MOVES,
    MENUITEM_LEVEL_CAP_OFF,
    MENUITEM_ALLOW_STAT_EDITOR,
    MENUITEM_DEBUG,
    MENUITEM_CANCEL_PG3,
    MENUITEM_COUNT_PG3,
};

enum
{
    WIN_HEADER,
    WIN_OPTIONS
};

//Pg 1
#define YPOS_TEXTSPEED    (MENUITEM_TEXTSPEED * 16)
#define YPOS_BATTLESCENE  (MENUITEM_BATTLESCENE * 16)
#define YPOS_BATTLESTYLE  (MENUITEM_BATTLESTYLE * 16)
#define YPOS_SOUND        (MENUITEM_SOUND * 16)
#define YPOS_BUTTONMODE   (MENUITEM_BUTTONMODE * 16)
#define YPOS_FRAMETYPE    (MENUITEM_FRAMETYPE * 16)

//Pg2
#define YPOS_AIBATTLES_TRAINER    (MENUITEM_AIBATTLES_TRAINER * 16)
#define YPOS_AIBATTLES_WILD       (MENUITEM_AIBATTLES_WILD * 16)
#define YPOS_AUTOSCROLL           (MENUITEM_AUTOSCROLL * 16)
#define YPOS_NUZLOCKE             (MENUITEM_NUZLOCKE * 16)
#define YPOS_AUTOSAVE             (MENUITEM_AUTOSAVE * 16)
#define YPOS_DIFFICULTY           (MENUITEM_DIFFICULTY * 16)

//Pg3
#define YPOS_RANDOMIZER   (MENUITEM_RANDOMIZER * 16)
#define YPOS_RANDOMIZER_TYPE (MENUITEM_RANDOMIZER_TYPE * 16)
#define YPOS_RANDOMIZER_MOVES (MENUITEM_RANDOMIZER_MOVES * 16)
#define YPOS_LEVEL_CAP_OFF (MENUITEM_LEVEL_CAP_OFF * 16)
#define YPOS_STAT_EDITOR (MENUITEM_ALLOW_STAT_EDITOR * 16)
#define YPOS_DEBUG (MENUITEM_DEBUG * 16)

#define PAGE_COUNT 3

static void Task_OptionMenuFadeIn(u8 taskId);
static void Task_OptionMenuProcessInput(u8 taskId);
static void Task_OptionMenuFadeIn_Pg2(u8 taskId);
static void Task_OptionMenuProcessInput_Pg2(u8 taskId);
static void Task_OptionMenuFadeIn_Pg3(u8 taskId);
static void Task_OptionMenuProcessInput_Pg3(u8 taskId);
static void Task_OptionMenuSave(u8 taskId);
static void Task_OptionMenuFadeOut(u8 taskId);
static void HighlightOptionMenuItem(u8 selection);
static u8 TextSpeed_ProcessInput(u8 selection);
static void TextSpeed_DrawChoices(u8 selection);
static u8 BattleScene_ProcessInput(u8 selection);
static void BattleScene_DrawChoices(u8 selection);
static u8 BattleStyle_ProcessInput(u8 selection);
static void BattleStyle_DrawChoices(u8 selection);
static u8 AIBattles_ProcessInput(u8 selection);
static void AIBattles_DrawChoices(u8 selection);
static void WildAIBattles_DrawChoices(u8 selection);
static u8   AutoScroll_ProcessInput(u8 selection);
static void AutoScroll_DrawChoices(u8 selection);
static u8   Randomizer_ProcessInput(u8 selection);
static void Randomizer_DrawChoices(u8 selection);
static u8   RandomizerType_ProcessInput(u8 selection);
static void RandomizerType_DrawChoices(u8 selection);
static u8   RandomizerMoves_ProcessInput(u8 selection);
static void RandomizerMoves_DrawChoices(u8 selection);
static u16  LevelCapOff_ProcessInput(u8 selection);
static void LevelCapOff_DrawChoices(u8 selection);
static u8   StatEditor_ProcessInput(u8 selection);
static void StatEditor_DrawChoices(u8 selection);
static u8   Debug_ProcessInput(u8 selection);
static void Debug_DrawChoices(u8 selection);
static u8   Nuzlocke_ProcessInput(u8 selection);
static void Nuzlocke_DrawChoices(u8 selection);
static u8   Autosave_ProcessInput(u8 selection);
static void Autosave_DrawChoices(u8 selection);
static u8   Difficulty_ProcessInput(u8 selection);
static void Difficulty_DrawChoices(u8 selection);
static u8 Sound_ProcessInput(u8 selection);
static void Sound_DrawChoices(u8 selection);
static u8 FrameType_ProcessInput(u8 selection);
static void FrameType_DrawChoices(u8 selection);
static u8 ButtonMode_ProcessInput(u8 selection);
static void ButtonMode_DrawChoices(u8 selection);
static void DrawHeaderText(void);
static void DrawOptionMenuTexts(void);
static void DrawBgWindowFrames(void);
static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style);

EWRAM_DATA static bool8 sArrowPressed = FALSE;
EWRAM_DATA static u8 sCurrPage = 0;

static const u8 gText_Option[]             = _("OPTION");
static const u8 gText_PageNav[]            = _("PAGE");
static const u8 gText_SmallDot[]           = _("·");
static const u8 gText_LargeDot[]           = _("{EMOJI_CIRCLE}");

static const u8 gText_TextSpeedSlow[]      = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}SLOW");
static const u8 gText_TextSpeedMid[]       = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}MID");
static const u8 gText_TextSpeedFast[]      = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}FAST");
static const u8 gText_BattleSceneOn[]      = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON");
static const u8 gText_BattleSceneOff[]     = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF");
static const u8 gText_BattleStyleShift[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}SHIFT");
static const u8 gText_BattleStyleSet[]     = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}SET");
static const u8 gText_SoundMono[]          = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}MONO");
static const u8 gText_SoundStereo[]        = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}STEREO");
static const u8 gText_FrameType[]          = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}TYPE");
static const u8 gText_FrameTypeNumber[]    = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}");
static const u8 gText_ButtonTypeNormal[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}NORMAL");
static const u8 gText_ButtonTypeLR[]       = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}LR");
static const u8 gText_ButtonTypeLEqualsA[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}L=A");

// Page 2 strings
static const u8 gText_AIBattlesTrainer[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}TRAINER");
static const u8 gText_AIBattlesWild[]      = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}WILD");
static const u8 gText_AIBattlesOff[]       = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF");
static const u8 gText_AIBattlesOn[]        = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON");
static const u8 gText_AutoScroll[]         = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}AUTO-SCROLL");
static const u8 gText_AutoScrollOff[]      = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF");
static const u8 gText_AutoScrollOn[]       = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON");
static const u8 gText_Nuzlocke[]           = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}NUZLOCKE");
static const u8 gText_NuzlockeOff[]        = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF");
static const u8 gText_NuzlockeOn[]         = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON");
static const u8 gText_Autosave[]           = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}AUTOSAVE");
static const u8 gText_AutosaveOff[]        = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF");
static const u8 gText_AutosaveOn[]         = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON");
static const u8 gText_Difficulty[]         = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}DIFFICULTY");
static const u8 gText_DifficultyEasy[]     = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}EASY");
static const u8 gText_DifficultyNormal[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}NORMAL");
static const u8 gText_DifficultyHard[]     = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}HARD");

// Page 3 strings
static const u8 gText_SpeciesRandomizer[]  = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}SPECIES");
static const u8 gText_RandomizerOff[]      = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF");
static const u8 gText_RandomizerOn[]       = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON");
static const u8 gText_TypeRandomizer[]     = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}TYPE");
static const u8 gText_TypeRandomizerOff[]  = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF");
static const u8 gText_TypeRandomizerOn[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON");
static const u8 gText_MovesRandomizer[]    = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}MOVES");
static const u8 gText_MovesRandomizerOff[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF");
static const u8 gText_MovesRandomizerOn[]  = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON");
static const u8 gText_LevelCap[]           = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}LEVEL CAP");
static const u8 gText_LevelCapOn[]         = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON");
static const u8 gText_LevelCapOff[]        = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF");
static const u8 gText_AllowStatEditorOff[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF");
static const u8 gText_AllowStatEditorOn[]  = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON");
static const u8 gText_Debug[]              = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}DEBUG");
static const u8 gText_DebugOff[]           = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}OFF");
static const u8 gText_DebugOn[]            = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}ON");

static const u16 sOptionMenuText_Pal[] = INCGFX_U16("graphics/interface/option_menu_text.pal", ".gbapal");
// note: this is only used in the Japanese release
static const u8 sEqualSignGfx[] = INCGFX_U8("graphics/interface/option_menu_equals_sign.png", ".4bpp");

static const u8 *const sOptionMenuItemsNames[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED]   = COMPOUND_STRING("TEXT SPEED"),
    [MENUITEM_BATTLESCENE] = COMPOUND_STRING("BATTLE SCENE"),
    [MENUITEM_BATTLESTYLE] = COMPOUND_STRING("BATTLE STYLE"),
    [MENUITEM_SOUND]       = COMPOUND_STRING("SOUND"),
    [MENUITEM_BUTTONMODE]  = COMPOUND_STRING("BUTTON MODE"),
    [MENUITEM_FRAMETYPE]   = COMPOUND_STRING("FRAME"),
    [MENUITEM_CANCEL]      = COMPOUND_STRING("CANCEL"),
};

static const u8 *const sOptionMenuItemsNames_Pg2[MENUITEM_COUNT_PG2] =
{
    [MENUITEM_AIBATTLES_TRAINER] = COMPOUND_STRING("AI BATTLES - TRNR"),
    [MENUITEM_AIBATTLES_WILD]    = COMPOUND_STRING("AI BATTLES - WILD"),
    [MENUITEM_AUTOSCROLL]        = COMPOUND_STRING("AUTO SCROLL"),
    [MENUITEM_NUZLOCKE]          = COMPOUND_STRING("NUZLOCKE"),
    [MENUITEM_AUTOSAVE]          = COMPOUND_STRING("AUTOSAVE"),
    [MENUITEM_DIFFICULTY]        = COMPOUND_STRING("DIFFICULTY"),
    [MENUITEM_CANCEL_PG2]        = COMPOUND_STRING("CANCEL"),
};

static const u8 *const sOptionMenuItemsNames_Pg3[MENUITEM_COUNT_PG3] =
{
    [MENUITEM_RANDOMIZER]        = COMPOUND_STRING("RANDOMIZE MONS"),
    [MENUITEM_RANDOMIZER_TYPE]   = COMPOUND_STRING("RANDOMIZE TYPES"),
    [MENUITEM_RANDOMIZER_MOVES]  = COMPOUND_STRING("RANDOMIZE MOVES"),
    [MENUITEM_LEVEL_CAP_OFF]     = COMPOUND_STRING("LEVEL CAP"),
    [MENUITEM_ALLOW_STAT_EDITOR] = COMPOUND_STRING("STAT EDITOR"),
    [MENUITEM_DEBUG]             = COMPOUND_STRING("DEBUG"),
    [MENUITEM_CANCEL_PG3]        = COMPOUND_STRING("CANCEL"),
};

static const struct WindowTemplate sOptionMenuWinTemplates[] =
{
    [WIN_HEADER] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 26,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2
    },
    [WIN_OPTIONS] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 5,
        .width = 26,
        .height = 14,
        .paletteNum = 1,
        .baseBlock = 0x36
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sOptionMenuBgTemplates[] =
{
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
        .bg = 0,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    }
};

static const u16 sOptionMenuBg_Pal[] = {RGB(17, 18, 31)};

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void ReadAllCurrentSettings(u8 taskId)
{
    gTasks[taskId].tMenuSelection = 0;
    gTasks[taskId].tTextSpeed = gSaveBlock2Ptr->optionsTextSpeed;
    gTasks[taskId].tButtonMode = gSaveBlock2Ptr->optionsButtonMode;
    gTasks[taskId].tWindowFrameType = gSaveBlock2Ptr->optionsWindowFrameType;
    gTasks[taskId].tAIBattles = (FlagGet(FLAG_AI_BATTLES) ? 1 : 0) | (FlagGet(FLAG_AI_WILD_BATTLES) ? 2 : 0);
    gTasks[taskId].tDifficulty = gSaveBlock1Ptr->difficulty;
    gTasks[taskId].tPackedFlags = 0;
    if (gSaveBlock2Ptr->optionsBattleSceneOff)     SET_FLAG(BATTLE_SCENE, 1); else SET_FLAG(BATTLE_SCENE, 0);
    if (gSaveBlock2Ptr->optionsBattleStyle)        SET_FLAG(BATTLE_STYLE, 1); else SET_FLAG(BATTLE_STYLE, 0);
    if (gSaveBlock2Ptr->optionsSound)              SET_FLAG(SOUND, 1); else SET_FLAG(SOUND, 0);
    if (FlagGet(FLAG_AUTO_SCROLL_TEXT))            SET_FLAG(AUTO_SCROLL, 1); else SET_FLAG(AUTO_SCROLL, 0);
    if (FlagGet(FLAG_RANDOMIZE_MON))               SET_FLAG(RANDOMIZER, 1); else SET_FLAG(RANDOMIZER, 0);
    if (FlagGet(FLAG_RANDOMIZE_TYPE))              SET_FLAG(RANDOMIZER_TYPE, 1); else SET_FLAG(RANDOMIZER_TYPE, 0);
    if (FlagGet(FLAG_RANDOMIZE_MOVES))             SET_FLAG(RANDOMIZER_MOVES, 1); else SET_FLAG(RANDOMIZER_MOVES, 0);
    if (gSaveBlock1Ptr->nuzlockeModeEnabled)       SET_FLAG(NUZLOCKE, 1); else SET_FLAG(NUZLOCKE, 0);
    if (gSaveBlock1Ptr->autosaveModeEnabled)       SET_FLAG(AUTOSAVE, 1); else SET_FLAG(AUTOSAVE, 0);
    if (FlagGet(FLAG_LEVEL_CAP_OFF))               SET_FLAG(LEVEL_CAP_OFF, 1); else SET_FLAG(LEVEL_CAP_OFF, 0);
    if (FlagGet(FLAG_ALLOW_STAT_EDITOR))           SET_FLAG(STAT_EDITOR, 1); else SET_FLAG(STAT_EDITOR, 0);
    if (FlagGet(FLAG_DEBUG))                       SET_FLAG(DEBUG, 1); else SET_FLAG(DEBUG, 0);
}

static void DrawOptionsPg1(u8 taskId)
{  
    TextSpeed_DrawChoices(gTasks[taskId].tTextSpeed);
    BattleScene_DrawChoices(GET_FLAG(BATTLE_SCENE));
    BattleStyle_DrawChoices(GET_FLAG(BATTLE_STYLE));
    Sound_DrawChoices(GET_FLAG(SOUND));
    ButtonMode_DrawChoices(gTasks[taskId].tButtonMode);
    FrameType_DrawChoices(gTasks[taskId].tWindowFrameType);
    HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

static void DrawOptionsPg2(u8 taskId)
{
    AIBattles_DrawChoices(gTasks[taskId].tAIBattles & 1);
    WildAIBattles_DrawChoices((gTasks[taskId].tAIBattles & 2) ? 1 : 0);
    AutoScroll_DrawChoices(GET_FLAG(AUTO_SCROLL));
    Nuzlocke_DrawChoices(GET_FLAG(NUZLOCKE));
    Autosave_DrawChoices(GET_FLAG(AUTOSAVE));
    Difficulty_DrawChoices(gTasks[taskId].tDifficulty);
    HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

static void DrawOptionsPg3(u8 taskId)
{
    Randomizer_DrawChoices(GET_FLAG(RANDOMIZER));
    RandomizerType_DrawChoices(GET_FLAG(RANDOMIZER_TYPE));
    RandomizerMoves_DrawChoices(GET_FLAG(RANDOMIZER_MOVES));
    LevelCapOff_DrawChoices(GET_FLAG(LEVEL_CAP_OFF));
    StatEditor_DrawChoices(GET_FLAG(STAT_EDITOR));
    Debug_DrawChoices(GET_FLAG(DEBUG));
    HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

void CB2_InitOptionMenu(void)
{
    u8 taskId;
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sOptionMenuBgTemplates, ARRAY_COUNT(sOptionMenuBgTemplates));
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);
        InitWindows(sOptionMenuWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_DARKEN);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(1, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0x1A2);
        gMain.state++;
        break;
    case 4:
        LoadPalette(sOptionMenuBg_Pal, BG_PLTT_ID(0), sizeof(sOptionMenuBg_Pal));
        LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sOptionMenuText_Pal, BG_PLTT_ID(1), sizeof(sOptionMenuText_Pal));
        gMain.state++;
        break;
    case 6:
        PutWindowTilemap(WIN_HEADER);
        DrawHeaderText();
        gMain.state++;
        break;
    case 7:
        gMain.state++;
        break;
    case 8:
        PutWindowTilemap(WIN_OPTIONS);
        DrawOptionMenuTexts();
        gMain.state++;
        break;
    case 9:
        DrawBgWindowFrames();
        gMain.state++;
        break;
    case 10:
    {
        taskId = CreateTask(Task_OptionMenuFadeIn, 0);
        ReadAllCurrentSettings(taskId);
        switch(sCurrPage)
        {
        case 0:
            DrawOptionsPg1(taskId);
            gTasks[taskId].func = Task_OptionMenuFadeIn;
            break;
        case 1:
            DrawOptionsPg2(taskId);
            gTasks[taskId].func = Task_OptionMenuFadeIn_Pg2;
            break;
        case 2:
            DrawOptionsPg3(taskId);
            gTasks[taskId].func = Task_OptionMenuFadeIn_Pg3;
            break;
        }
        gMain.state++;
        break;
    }
    case 11:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

static void Task_OptionMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OptionMenuProcessInput;
}

static u8 Process_ChangePage(u8 CurrentPage)
{
    if (JOY_NEW(R_BUTTON))
    {
        if (CurrentPage < PAGE_COUNT - 1)
            CurrentPage++;
        else
            CurrentPage = 0;
    }
    if (JOY_NEW(L_BUTTON))
    {
        if (CurrentPage != 0)
            CurrentPage--;
        else
            CurrentPage = PAGE_COUNT - 1;
    }
    return CurrentPage;
}

static void Task_ChangePage(u8 taskId)
{
    DrawHeaderText();
    PutWindowTilemap(1);
    DrawOptionMenuTexts();
    switch(sCurrPage)
    {
    case 0:
        DrawOptionsPg1(taskId);
        gTasks[taskId].func = Task_OptionMenuFadeIn;
        break;
    case 1:
        DrawOptionsPg2(taskId);
        gTasks[taskId].func = Task_OptionMenuFadeIn_Pg2;
        break;
    case 2:
        DrawOptionsPg3(taskId);
        gTasks[taskId].func = Task_OptionMenuFadeIn_Pg3;
        break;
    }
}

static void Task_OptionMenuProcessInput(u8 taskId)
{
    if (JOY_NEW(L_BUTTON) || JOY_NEW(R_BUTTON))
    {
        FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
        ClearStdWindowAndFrame(WIN_OPTIONS, FALSE);
        sCurrPage = Process_ChangePage(sCurrPage);
        gTasks[taskId].func = Task_ChangePage;
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if (gTasks[taskId].tMenuSelection == MENUITEM_CANCEL)
            gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gTasks[taskId].tMenuSelection > 0)
            gTasks[taskId].tMenuSelection--;
        else
            gTasks[taskId].tMenuSelection = MENUITEM_CANCEL;
        HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (gTasks[taskId].tMenuSelection < MENUITEM_CANCEL)
            gTasks[taskId].tMenuSelection++;
        else
            gTasks[taskId].tMenuSelection = 0;
        HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
    }
    else
    {
        u8 previousOption;

        switch (gTasks[taskId].tMenuSelection)
        {
        case MENUITEM_TEXTSPEED:
            previousOption = gTasks[taskId].tTextSpeed;
            gTasks[taskId].tTextSpeed = TextSpeed_ProcessInput(gTasks[taskId].tTextSpeed);

            if (previousOption != gTasks[taskId].tTextSpeed)
                TextSpeed_DrawChoices(gTasks[taskId].tTextSpeed);
            break;
        case MENUITEM_BATTLESCENE:
            previousOption = GET_FLAG(BATTLE_SCENE);
            gTasks[taskId].tPackedFlags = (gTasks[taskId].tPackedFlags & ~(1 << BATTLE_SCENE_SHIFT)) | (BattleScene_ProcessInput(previousOption) << BATTLE_SCENE_SHIFT);

            if (previousOption != GET_FLAG(BATTLE_SCENE))
                BattleScene_DrawChoices(GET_FLAG(BATTLE_SCENE));
            break;
        case MENUITEM_BATTLESTYLE:
            previousOption = GET_FLAG(BATTLE_STYLE);
            gTasks[taskId].tPackedFlags = (gTasks[taskId].tPackedFlags & ~(1 << BATTLE_STYLE_SHIFT)) | (BattleStyle_ProcessInput(previousOption) << BATTLE_STYLE_SHIFT);

            if (previousOption != GET_FLAG(BATTLE_STYLE))
                BattleStyle_DrawChoices(GET_FLAG(BATTLE_STYLE));
            break;
        case MENUITEM_SOUND:
            previousOption = GET_FLAG(SOUND);
            gTasks[taskId].tPackedFlags = (gTasks[taskId].tPackedFlags & ~(1 << SOUND_SHIFT)) | (Sound_ProcessInput(previousOption) << SOUND_SHIFT);

            if (previousOption != GET_FLAG(SOUND))
                Sound_DrawChoices(GET_FLAG(SOUND));
            break;
        case MENUITEM_BUTTONMODE:
            previousOption = gTasks[taskId].tButtonMode;
            gTasks[taskId].tButtonMode = ButtonMode_ProcessInput(gTasks[taskId].tButtonMode);

            if (previousOption != gTasks[taskId].tButtonMode)
                ButtonMode_DrawChoices(gTasks[taskId].tButtonMode);
            break;
        case MENUITEM_FRAMETYPE:
            previousOption = gTasks[taskId].tWindowFrameType;
            gTasks[taskId].tWindowFrameType = FrameType_ProcessInput(gTasks[taskId].tWindowFrameType);

            if (previousOption != gTasks[taskId].tWindowFrameType)
                FrameType_DrawChoices(gTasks[taskId].tWindowFrameType);
            break;
        default:
            return;
        }

        if (sArrowPressed)
        {
            sArrowPressed = FALSE;
            CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
        }
    }
}

static void Task_OptionMenuFadeIn_Pg2(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OptionMenuProcessInput_Pg2;
}

static void Task_OptionMenuProcessInput_Pg2(u8 taskId)
{
    if (JOY_NEW(L_BUTTON) || JOY_NEW(R_BUTTON))
    {
        FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
        ClearStdWindowAndFrame(WIN_OPTIONS, FALSE);
        sCurrPage = Process_ChangePage(sCurrPage);
        gTasks[taskId].func = Task_ChangePage;
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if (gTasks[taskId].tMenuSelection == MENUITEM_CANCEL_PG2)
            gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gTasks[taskId].tMenuSelection > 0)
            gTasks[taskId].tMenuSelection--;
        else
            gTasks[taskId].tMenuSelection = MENUITEM_CANCEL_PG2;
        HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (gTasks[taskId].tMenuSelection < MENUITEM_CANCEL_PG2)
            gTasks[taskId].tMenuSelection++;
        else
            gTasks[taskId].tMenuSelection = 0;
        HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
    }
    else
    {
        u8 previousOption;

        switch (gTasks[taskId].tMenuSelection)
        {
        case MENUITEM_AIBATTLES_TRAINER:
        {
            u8 prev = gTasks[taskId].tAIBattles & 1;
            u8 sel = AIBattles_ProcessInput(prev);
            if (prev != sel)
            {
                if (sel)
                    gTasks[taskId].tAIBattles |= 1;
                else
                    gTasks[taskId].tAIBattles &= ~1;
                AIBattles_DrawChoices(sel);
            }
            break;
        }
        case MENUITEM_AIBATTLES_WILD:
        {
            u8 prev = (gTasks[taskId].tAIBattles & 2) ? 1 : 0;
            u8 sel = AIBattles_ProcessInput(prev);
            if (prev != sel)
            {
                if (sel)
                    gTasks[taskId].tAIBattles |= 2;
                else
                    gTasks[taskId].tAIBattles &= ~2;
                WildAIBattles_DrawChoices(sel);
            }
            break;
        }
        case MENUITEM_AUTOSCROLL:
            previousOption = GET_FLAG(AUTO_SCROLL);
            gTasks[taskId].tPackedFlags = (gTasks[taskId].tPackedFlags & ~(1 << AUTO_SCROLL_SHIFT)) | (AutoScroll_ProcessInput(previousOption) << AUTO_SCROLL_SHIFT);

            if (previousOption != GET_FLAG(AUTO_SCROLL))
                AutoScroll_DrawChoices(GET_FLAG(AUTO_SCROLL));
            break;
        case MENUITEM_NUZLOCKE:
            previousOption = GET_FLAG(NUZLOCKE);
            gTasks[taskId].tPackedFlags = (gTasks[taskId].tPackedFlags & ~(1 << NUZLOCKE_SHIFT)) | (Nuzlocke_ProcessInput(previousOption) << NUZLOCKE_SHIFT);

            if (previousOption != GET_FLAG(NUZLOCKE))
                Nuzlocke_DrawChoices(GET_FLAG(NUZLOCKE));
            break;
        case MENUITEM_AUTOSAVE:
            previousOption = GET_FLAG(AUTOSAVE);
            gTasks[taskId].tPackedFlags = (gTasks[taskId].tPackedFlags & ~(1 << AUTOSAVE_SHIFT)) | (Autosave_ProcessInput(previousOption) << AUTOSAVE_SHIFT);

            if (previousOption != GET_FLAG(AUTOSAVE))
                Autosave_DrawChoices(GET_FLAG(AUTOSAVE));
            break;
        case MENUITEM_DIFFICULTY:
            previousOption = gTasks[taskId].tDifficulty;
            gTasks[taskId].tDifficulty = Difficulty_ProcessInput(gTasks[taskId].tDifficulty);

            if (previousOption != gTasks[taskId].tDifficulty)
                Difficulty_DrawChoices(gTasks[taskId].tDifficulty);
            break;
        default:
            return;
        }

        if (sArrowPressed)
        {
            sArrowPressed = FALSE;
            CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
        }
    }
}

static void Task_OptionMenuFadeIn_Pg3(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OptionMenuProcessInput_Pg3;
}

static void Task_OptionMenuProcessInput_Pg3(u8 taskId)
{
    if (JOY_NEW(L_BUTTON) || JOY_NEW(R_BUTTON))
    {
        FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
        ClearStdWindowAndFrame(WIN_OPTIONS, FALSE);
        sCurrPage = Process_ChangePage(sCurrPage);
        gTasks[taskId].func = Task_ChangePage;
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if (gTasks[taskId].tMenuSelection == MENUITEM_CANCEL_PG3)
            gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gTasks[taskId].tMenuSelection > 0)
            gTasks[taskId].tMenuSelection--;
        else
            gTasks[taskId].tMenuSelection = MENUITEM_CANCEL_PG3;
        HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (gTasks[taskId].tMenuSelection < MENUITEM_CANCEL_PG3)
            gTasks[taskId].tMenuSelection++;
        else
            gTasks[taskId].tMenuSelection = 0;
        HighlightOptionMenuItem(gTasks[taskId].tMenuSelection);
    }
    else
    {
        u8 previousOption;

        switch (gTasks[taskId].tMenuSelection)
        {
        case MENUITEM_RANDOMIZER:
            previousOption = GET_FLAG(RANDOMIZER);
            gTasks[taskId].tPackedFlags = (gTasks[taskId].tPackedFlags & ~(1 << RANDOMIZER_SHIFT)) | (Randomizer_ProcessInput(previousOption) << RANDOMIZER_SHIFT);

            if (previousOption != GET_FLAG(RANDOMIZER))
                Randomizer_DrawChoices(GET_FLAG(RANDOMIZER));
            break;
        case MENUITEM_RANDOMIZER_TYPE:
            previousOption = GET_FLAG(RANDOMIZER_TYPE);
            gTasks[taskId].tPackedFlags = (gTasks[taskId].tPackedFlags & ~(1 << RANDOMIZER_TYPE_SHIFT)) | (RandomizerType_ProcessInput(previousOption) << RANDOMIZER_TYPE_SHIFT);

            if (previousOption != GET_FLAG(RANDOMIZER_TYPE))
                RandomizerType_DrawChoices(GET_FLAG(RANDOMIZER_TYPE));
            break;
        case MENUITEM_RANDOMIZER_MOVES:
            previousOption = GET_FLAG(RANDOMIZER_MOVES);
            gTasks[taskId].tPackedFlags = (gTasks[taskId].tPackedFlags & ~(1 << RANDOMIZER_MOVES_SHIFT)) | (RandomizerMoves_ProcessInput(previousOption) << RANDOMIZER_MOVES_SHIFT);

            if (previousOption != GET_FLAG(RANDOMIZER_MOVES))
                RandomizerMoves_DrawChoices(GET_FLAG(RANDOMIZER_MOVES));
            break;
        case MENUITEM_LEVEL_CAP_OFF:
            previousOption = GET_FLAG(LEVEL_CAP_OFF);
            gTasks[taskId].tPackedFlags = (gTasks[taskId].tPackedFlags & ~(1 << LEVEL_CAP_OFF_SHIFT)) | (LevelCapOff_ProcessInput(previousOption) << LEVEL_CAP_OFF_SHIFT);

            if (previousOption != GET_FLAG(LEVEL_CAP_OFF))
                LevelCapOff_DrawChoices(GET_FLAG(LEVEL_CAP_OFF));
            break;
        case MENUITEM_ALLOW_STAT_EDITOR:
            previousOption = GET_FLAG(STAT_EDITOR);
            gTasks[taskId].tPackedFlags = (gTasks[taskId].tPackedFlags & ~(1 << STAT_EDITOR_SHIFT)) | (StatEditor_ProcessInput(previousOption) << STAT_EDITOR_SHIFT);

            if (previousOption != GET_FLAG(STAT_EDITOR))
                StatEditor_DrawChoices(GET_FLAG(STAT_EDITOR));
            break;
        case MENUITEM_DEBUG:
            previousOption = GET_FLAG(DEBUG);
            gTasks[taskId].tPackedFlags = (gTasks[taskId].tPackedFlags & ~(1 << DEBUG_SHIFT)) | (Debug_ProcessInput(previousOption) << DEBUG_SHIFT);

            if (previousOption != GET_FLAG(DEBUG))
                Debug_DrawChoices(GET_FLAG(DEBUG));
            break;
        default:
            return;
        }

        if (sArrowPressed)
        {
            sArrowPressed = FALSE;
            CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
        }
    }
}

static void Task_OptionMenuSave(u8 taskId)
{
    gSaveBlock2Ptr->optionsTextSpeed = gTasks[taskId].tTextSpeed;
    gSaveBlock2Ptr->optionsBattleSceneOff = GET_FLAG(BATTLE_SCENE);
    gSaveBlock2Ptr->optionsBattleStyle = GET_FLAG(BATTLE_STYLE);
    gSaveBlock2Ptr->optionsSound = GET_FLAG(SOUND);
    gSaveBlock2Ptr->optionsButtonMode = gTasks[taskId].tButtonMode;
    gSaveBlock2Ptr->optionsWindowFrameType = gTasks[taskId].tWindowFrameType;
    /* Save trainer and wild AI flags from the bitmask */
    (gTasks[taskId].tAIBattles & 1) == 0 ? FlagClear(FLAG_AI_BATTLES) : FlagSet(FLAG_AI_BATTLES);
    (gTasks[taskId].tAIBattles & 2) == 0 ? FlagClear(FLAG_AI_WILD_BATTLES) : FlagSet(FLAG_AI_WILD_BATTLES);
    GET_FLAG(AUTO_SCROLL) == 0 ? FlagClear(FLAG_AUTO_SCROLL_TEXT) : FlagSet(FLAG_AUTO_SCROLL_TEXT);
    GET_FLAG(RANDOMIZER) == 0 ? FlagClear(FLAG_RANDOMIZE_MON) : FlagSet(FLAG_RANDOMIZE_MON);
    GET_FLAG(RANDOMIZER_TYPE) == 0 ? FlagClear(FLAG_RANDOMIZE_TYPE) : FlagSet(FLAG_RANDOMIZE_TYPE);
    GET_FLAG(RANDOMIZER_MOVES) == 0 ? FlagClear(FLAG_RANDOMIZE_MOVES) : FlagSet(FLAG_RANDOMIZE_MOVES);
    GET_FLAG(LEVEL_CAP_OFF) == 0 ? FlagClear(FLAG_LEVEL_CAP_OFF) : FlagSet(FLAG_LEVEL_CAP_OFF);
    GET_FLAG(STAT_EDITOR) == 0 ? FlagClear(FLAG_ALLOW_STAT_EDITOR) : FlagSet(FLAG_ALLOW_STAT_EDITOR);
    GET_FLAG(DEBUG) == 0 ? FlagClear(FLAG_DEBUG) : FlagSet(FLAG_DEBUG);
    GET_FLAG(NUZLOCKE) == 0 ? (gSaveBlock1Ptr->nuzlockeModeEnabled = 0) : (gSaveBlock1Ptr->nuzlockeModeEnabled = 1);
    GET_FLAG(AUTOSAVE) == 0 ? (gSaveBlock1Ptr->autosaveModeEnabled = 0) : (gSaveBlock1Ptr->autosaveModeEnabled = 1);
    gSaveBlock1Ptr->difficulty = gTasks[taskId].tDifficulty;

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_OptionMenuFadeOut;
}

static void Task_OptionMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

static void HighlightOptionMenuItem(u8 index)
{
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(16, DISPLAY_WIDTH - 16));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(index * 16 + 40, index * 16 + 56));
}

static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style)
{
    u8 dst[16];
    u16 i;

    for (i = 0; *text != EOS && i < ARRAY_COUNT(dst) - 1; i++)
        dst[i] = *(text++);

    if (style != 0)
    {
        dst[2] = TEXT_COLOR_RED;
        dst[5] = TEXT_COLOR_LIGHT_RED;
    }

    dst[i] = EOS;
    AddTextPrinterParameterized(WIN_OPTIONS, FONT_NORMAL, dst, x, y + 1, TEXT_SKIP_DRAW, NULL);
}

static u8 TextSpeed_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection <= 1)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = 2;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void TextSpeed_DrawChoices(u8 selection)
{
    u8 styles[3];
    s32 widthSlow, widthMid, widthFast, xMid;

    styles[0] = 0;
    styles[1] = 0;
    styles[2] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_TextSpeedSlow, 104, YPOS_TEXTSPEED, styles[0]);

    widthSlow = GetStringWidth(FONT_NORMAL, gText_TextSpeedSlow, 0);
    widthMid = GetStringWidth(FONT_NORMAL, gText_TextSpeedMid, 0);
    widthFast = GetStringWidth(FONT_NORMAL, gText_TextSpeedFast, 0);

    widthMid -= 94;
    xMid = (widthSlow - widthMid - widthFast) / 2 + 104;
    DrawOptionMenuChoice(gText_TextSpeedMid, xMid, YPOS_TEXTSPEED, styles[1]);

    DrawOptionMenuChoice(gText_TextSpeedFast, GetStringRightAlignXOffset(FONT_NORMAL, gText_TextSpeedFast, 198), YPOS_TEXTSPEED, styles[2]);
}

static u8 BattleScene_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void BattleScene_DrawChoices(u8 selection)
{
    u8 styles[2];

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_BattleSceneOn, 104, YPOS_BATTLESCENE, styles[0]);
    DrawOptionMenuChoice(gText_BattleSceneOff, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleSceneOff, 198), YPOS_BATTLESCENE, styles[1]);
}

static u8 BattleStyle_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void BattleStyle_DrawChoices(u8 selection)
{
    u8 styles[2];

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_BattleStyleShift, 104, YPOS_BATTLESTYLE, styles[0]);
    DrawOptionMenuChoice(gText_BattleStyleSet, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleStyleSet, 198), YPOS_BATTLESTYLE, styles[1]);
}

static u8 Sound_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        SetPokemonCryStereo(selection);
        sArrowPressed = TRUE;
    }

    return selection;
}

static void Sound_DrawChoices(u8 selection)
{
    u8 styles[2];

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_SoundMono, 104, YPOS_SOUND, styles[0]);
    DrawOptionMenuChoice(gText_SoundStereo, GetStringRightAlignXOffset(FONT_NORMAL, gText_SoundStereo, 198), YPOS_SOUND, styles[1]);
}

static u8 FrameType_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection < WINDOW_FRAMES_COUNT - 1)
            selection++;
        else
            selection = 0;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = WINDOW_FRAMES_COUNT - 1;

        LoadBgTiles(1, GetWindowFrameTilesPal(selection)->tiles, 0x120, 0x1A2);
        LoadPalette(GetWindowFrameTilesPal(selection)->pal, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        sArrowPressed = TRUE;
    }
    return selection;
}

static void FrameType_DrawChoices(u8 selection)
{
    u8 text[16] = {EOS};
    u8 n = selection + 1;
    u16 i;

    for (i = 0; gText_FrameTypeNumber[i] != EOS && i <= 5; i++)
        text[i] = gText_FrameTypeNumber[i];

    // Convert a number to decimal string
    if (n / 10 != 0)
    {
        text[i] = n / 10 + CHAR_0;
        i++;
        text[i] = n % 10 + CHAR_0;
        i++;
    }
    else
    {
        text[i] = n % 10 + CHAR_0;
        i++;
        text[i] = CHAR_SPACER;
        i++;
    }

    text[i] = EOS;

    DrawOptionMenuChoice(gText_FrameType, 104, YPOS_FRAMETYPE, 0);
    DrawOptionMenuChoice(text, 128, YPOS_FRAMETYPE, 1);
}

static u8 ButtonMode_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection <= 1)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = 2;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void ButtonMode_DrawChoices(u8 selection)
{
    s32 widthNormal, widthLR, widthLA, xLR;
    u8 styles[3];

    styles[0] = 0;
    styles[1] = 0;
    styles[2] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_ButtonTypeNormal, 104, YPOS_BUTTONMODE, styles[0]);

    widthNormal = GetStringWidth(FONT_NORMAL, gText_ButtonTypeNormal, 0);
    widthLR = GetStringWidth(FONT_NORMAL, gText_ButtonTypeLR, 0);
    widthLA = GetStringWidth(FONT_NORMAL, gText_ButtonTypeLEqualsA, 0);

    widthLR -= 94;
    xLR = (widthNormal - widthLR - widthLA) / 2 + 104;
    DrawOptionMenuChoice(gText_ButtonTypeLR, xLR, YPOS_BUTTONMODE, styles[1]);

    DrawOptionMenuChoice(gText_ButtonTypeLEqualsA, GetStringRightAlignXOffset(FONT_NORMAL, gText_ButtonTypeLEqualsA, 198), YPOS_BUTTONMODE, styles[2]);
}
static u8 AIBattles_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void AIBattles_DrawChoices(u8 selection)
{
    u8 styles[2];
    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;
    DrawOptionMenuChoice(gText_AIBattlesOff, 104, YPOS_AIBATTLES_TRAINER, styles[0]);
    DrawOptionMenuChoice(gText_AIBattlesOn, GetStringRightAlignXOffset(FONT_NORMAL, gText_AIBattlesOn, 198), YPOS_AIBATTLES_TRAINER, styles[1]);
}

static void WildAIBattles_DrawChoices(u8 selection)
{
    u8 styles[2];
    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;
    DrawOptionMenuChoice(gText_AIBattlesOff, 104, YPOS_AIBATTLES_WILD, styles[0]);
    DrawOptionMenuChoice(gText_AIBattlesOn, GetStringRightAlignXOffset(FONT_NORMAL, gText_AIBattlesOn, 198), YPOS_AIBATTLES_WILD, styles[1]);
}

static u8 AutoScroll_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void AutoScroll_DrawChoices(u8 selection)
{
    u8 styles[2];
    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;
    DrawOptionMenuChoice(gText_AutoScrollOff, 104, YPOS_AUTOSCROLL, styles[0]);
    DrawOptionMenuChoice(gText_AutoScrollOn, GetStringRightAlignXOffset(FONT_NORMAL, gText_AutoScrollOn, 198), YPOS_AUTOSCROLL, styles[1]);
}


static u8 Randomizer_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void Randomizer_DrawChoices(u8 selection)
{
    u8 styles[2];
    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;
    DrawOptionMenuChoice(gText_RandomizerOff, 104, YPOS_RANDOMIZER, styles[0]);
    DrawOptionMenuChoice(gText_RandomizerOn, GetStringRightAlignXOffset(FONT_NORMAL, gText_RandomizerOn, 198), YPOS_RANDOMIZER, styles[1]);
}

static u8 RandomizerType_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void RandomizerType_DrawChoices(u8 selection)
{
    u8 styles[2];
    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;
    DrawOptionMenuChoice(gText_TypeRandomizerOff, 104, YPOS_RANDOMIZER_TYPE, styles[0]);
    DrawOptionMenuChoice(gText_TypeRandomizerOn, GetStringRightAlignXOffset(FONT_NORMAL, gText_TypeRandomizerOn, 198), YPOS_RANDOMIZER_TYPE, styles[1]);
}

static u8 RandomizerMoves_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void RandomizerMoves_DrawChoices(u8 selection)
{
    u8 styles[2];
    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;
    DrawOptionMenuChoice(gText_MovesRandomizerOff, 104, YPOS_RANDOMIZER_MOVES, styles[0]);
    DrawOptionMenuChoice(gText_MovesRandomizerOn, GetStringRightAlignXOffset(FONT_NORMAL, gText_MovesRandomizerOn, 198), YPOS_RANDOMIZER_MOVES, styles[1]);
}

static u16 LevelCapOff_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void LevelCapOff_DrawChoices(u8 selection)
{
    u8 styles[2];
    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;
    DrawOptionMenuChoice(gText_LevelCapOn, 104, YPOS_LEVEL_CAP_OFF, styles[0]);
    DrawOptionMenuChoice(gText_LevelCapOff, GetStringRightAlignXOffset(FONT_NORMAL, gText_LevelCapOff, 198), YPOS_LEVEL_CAP_OFF, styles[1]);
}

static u8 StatEditor_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void StatEditor_DrawChoices(u8 selection)
{
    u8 styles[2];
    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;
    DrawOptionMenuChoice(gText_AllowStatEditorOff, 104, YPOS_STAT_EDITOR, styles[0]);
    DrawOptionMenuChoice(gText_AllowStatEditorOn, GetStringRightAlignXOffset(FONT_NORMAL, gText_AllowStatEditorOn, 198), YPOS_STAT_EDITOR, styles[1]);
}

static u8 Debug_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void Debug_DrawChoices(u8 selection)
{
    u8 styles[2];
    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;
    DrawOptionMenuChoice(gText_DebugOff, 104, YPOS_DEBUG, styles[0]);
    DrawOptionMenuChoice(gText_DebugOn, GetStringRightAlignXOffset(FONT_NORMAL, gText_DebugOn, 198), YPOS_DEBUG, styles[1]);
}

static u8 Nuzlocke_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void Nuzlocke_DrawChoices(u8 selection)
{
    u8 styles[2];
    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;
    DrawOptionMenuChoice(gText_NuzlockeOff, 104, YPOS_NUZLOCKE, styles[0]);
    DrawOptionMenuChoice(gText_NuzlockeOn, GetStringRightAlignXOffset(FONT_NORMAL, gText_NuzlockeOn, 198), YPOS_NUZLOCKE, styles[1]);
}

static u8 Autosave_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void Autosave_DrawChoices(u8 selection)
{
    u8 styles[2];
    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;
    DrawOptionMenuChoice(gText_AutosaveOff, 104, YPOS_AUTOSAVE, styles[0]);
    DrawOptionMenuChoice(gText_AutosaveOn, GetStringRightAlignXOffset(FONT_NORMAL, gText_AutosaveOn, 198), YPOS_AUTOSAVE, styles[1]);
}

static u8 Difficulty_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection <= 1)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = 2;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void Difficulty_DrawChoices(u8 selection)
{
    u8 styles[3];
    bool8 centerMid = TRUE;
    s32 widthEasy, widthNormal, widthHard, xMid;

    styles[0] = 0;
    styles[1] = 0;
    styles[2] = 0;
    styles[selection] = 1;
    DrawOptionMenuChoice(gText_DifficultyEasy, 104, YPOS_DIFFICULTY, styles[0]);

    widthNormal = GetStringWidth(FONT_NORMAL, gText_DifficultyNormal, 0);
    if (centerMid){
        xMid = (94 - widthNormal) / 2 + 104;
    }
    else
    {
        widthEasy = GetStringWidth(FONT_NORMAL, gText_DifficultyEasy, 0);
        widthHard = GetStringWidth(FONT_NORMAL, gText_DifficultyHard, 0);
        widthNormal -= 94;
        xMid = (widthEasy - widthNormal - widthHard) / 2 + 104;
    }

    DrawOptionMenuChoice(gText_DifficultyNormal, xMid, YPOS_DIFFICULTY, styles[1]);

    DrawOptionMenuChoice(gText_DifficultyHard, GetStringRightAlignXOffset(FONT_NORMAL, gText_DifficultyHard, 198), YPOS_DIFFICULTY, styles[2]);
}

static void DrawHeaderText(void)
{
    u32 i, widthOptions, xMid;
    u8 pageDots[9] = _("");  // Array size should be at least (2 * PAGE_COUNT) -1
    widthOptions = GetStringWidth(FONT_NORMAL, gText_Option, 0);

    for (i = 0; i < PAGE_COUNT; i++)
    {
        if (i == sCurrPage)
            StringAppend(pageDots, gText_LargeDot);
        else
            StringAppend(pageDots, gText_SmallDot);
        if (i < PAGE_COUNT - 1)
            StringAppend(pageDots, gText_Space);            
    }
    xMid = (8 + widthOptions + 5);
    FillWindowPixelBuffer(WIN_HEADER, PIXEL_FILL(1));
    AddTextPrinterParameterized(WIN_HEADER, FONT_NORMAL, gText_Option, 8, 1, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_HEADER, FONT_NORMAL, pageDots, xMid, 1, TEXT_SKIP_DRAW, NULL);
    AddTextPrinterParameterized(WIN_HEADER, FONT_NORMAL, gText_PageNav, GetStringRightAlignXOffset(FONT_NORMAL, gText_PageNav, 198), 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(WIN_HEADER, COPYWIN_FULL);
}

static void DrawOptionMenuTexts(void)
{
    u8 i, items;
    const u8* const* menu = NULL;

    switch (sCurrPage){
    default:
    case 0:
        items = MENUITEM_COUNT;
        menu = sOptionMenuItemsNames;
        break;
    case 1:
        items = MENUITEM_COUNT_PG2;
        menu = sOptionMenuItemsNames_Pg2;
        break;
    case 2:
        items = MENUITEM_COUNT_PG3;
        menu = sOptionMenuItemsNames_Pg3;
        break;    
    }

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
    for (i = 0; i < items; i++)
        AddTextPrinterParameterized(WIN_OPTIONS, FONT_NORMAL, menu[i], 8, (i * 16) + 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

#define TILE_TOP_CORNER_L 0x1A2
#define TILE_TOP_EDGE     0x1A3
#define TILE_TOP_CORNER_R 0x1A4
#define TILE_LEFT_EDGE    0x1A5
#define TILE_RIGHT_EDGE   0x1A7
#define TILE_BOT_CORNER_L 0x1A8
#define TILE_BOT_EDGE     0x1A9
#define TILE_BOT_CORNER_R 0x1AA

static void DrawBgWindowFrames(void)
{
    //                     bg, tile,              x, y, width, height, palNum
    // Draw title window frame
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  0,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  0, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  0,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  1,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  1,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1,  3,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2,  3, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28,  3,  1,  1,  7);

    // Draw options list window frame
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  4,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  4, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  4,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  5,  1, 18,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  5,  1, 18,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 19,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 19, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 19,  1,  1,  7);

    CopyBgTilemapBufferToVram(1);
}
