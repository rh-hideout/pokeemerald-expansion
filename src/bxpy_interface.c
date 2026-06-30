#include "global.h"
#include "bg.h"
#include "window.h"
#include "battle_setup.h"
#include "trig.h"
#include "tv.h"
#include "constants/rgb.h"
#include "battle_main.h"
#include "constants/songs.h"
#include "dma3.h"
#include "gpu_regs.h"
#include "sprite.h"
#include "palette.h"
#include "data.h"
#include "event_data.h"
#include "pokemon_icon.h"
#include "scanline_effect.h"
#include "sound.h"
#include "item.h"
#include "string_util.h"
#include "overworld.h"
#include "menu_helpers.h"
#include "malloc.h"
#include "task.h"
#include "international_string_util.h"
#include "text.h"
#include "text_window.h"
#include "menu.h"
#include "bxpy.h"
#include "bxpy_ai.h"

static void Task_BXPY_PartySelection(u8 taskId);
static void BXPY_AddRemoveSelectedMon(void);
static void BXPY_RemoveIndexFromSelected(u32 currentIndex);
static void BXPY_SetMusicFlag(bool32 isFirsTime);
static u8 BXPY_GetMusicFlag(void);
static void BXPY_ChangePosition(s32 delta);
static void BXPY_SetPosition(u32 position);
static u8 BXPY_GetPosition(void);
static u8 BXPY_GetBringSize(void);
static void BXPY_SetBringSize(u32 bringSize);
static u8 BXPY_GetPickSize(void);
static void BXPY_SetPickSize(u32 pickSize);
static void BXPY_SetBattleFlags(u32 battleFlags);
static u32 BXPY_GetBattleFlags(void);
static void BXPY_SetPage(enum BXPYPages page);
static u32 BXPY_GetPage(void);
static bool8 BXPY_IsOnPartnerPage(void);
static void BXPY_TogglePage(void);
static void BXPY_SetSpriteId(u32 spriteIndex, u32 spriteId);
static u8 BXPY_GetSpriteId(u32 spriteIndex);
static void BXPY_SetSelectedMons(u32 monIndex, u32 order);
static u8 BXPY_GetSelectedMons(u32 monIndex);
static void BXPY_VBlankCB(void);
static void BXPY_MainCB(void);
static bool8 BXPY_InitalizeBackgrounds(void);
static bool8 AllocZeroedTilemapBuffers(void);
static void HandleAndShowBgs(void);
static void SetScheduleBgs(enum BXPYBackgrounds backgroundId);
static bool8 AreTilesOrTilemapEmpty(enum BXPYBackgrounds backgroundId);
static void LoadGraphics(void);
static void LoadBXPYPalettes(void);
static void PlaySoundStartFadeQuitApp(u8 taskId);
static void Task_WaitFadeAndExitGracefully(u8 taskId);
static void FreeSpritePalettesResetSpriteData(void);
static void BXPY_FreeResources(void);
static void BXPY_FreeStructs(void);
static void BXPY_FreeBackgrounds(void);
static bool8 BXPY_AllocateStructs(void);
static void SpriteCB_BXPYCursor(struct Sprite *sprite);
static void BXPY_CreateCursorSprite(void);
static void ClearWindowCopyToVram(u32 windowId);
static void BXPY_InitWindows(void);
static void BXPY_DisplayParty(enum BattleSide side, bool32 cursorMove);
static void BXPY_CreateSelectionSprite(u32 partyMonIndex, enum BattleSide side);
static void BXPY_CreateSelectionSpriteTail(u32 partyMonIndex, enum BattleSide side);
static void SpriteCB_SelectionSprite(struct Sprite *sprite);
static void BXPY_DrawOrderOnSelectionSprite(u32 spriteId, u32 index);
static u8 BXPY_GetOrderForMon(u32 monIndex);
static bool8 BXPY_IsMonAlreadySelected(u32 partyMonIndex);
static void BXPY_DisplayPlayerParty(void);
static void BXPY_DisplayPlayerPartyCursorMove(void);
static void BXPY_DisplayPartyMonText(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex);
static void BXPY_DisplayPartyMonIcons(enum BXPYWindows windowId, struct Pokemon *mon, u32 partyMonIndex, enum BattleSide side, u32 species);
static void BXPY_PrintNickname(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex);
static void BXPY_PrintItemName(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex);
static void BXPY_PrintLevel(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex);
static void BXPY_PrintSex(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex);
static void BXPY_PrintMonIcon(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex, u32 species);
static void BXPY_PrintHP(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex);
static void BXPY_DisplayEnemyParty(void);
static void BXPY_DisplayEnemyName(void);
static void BXPY_PrintEnemyName(enum BXPYWindows windowId);
static void BXPY_DisplayHelpBar(enum BXPYWindows windowId);
static void BXPY_PrintHelpBarText(enum BXPYWindows windowId);
static bool8 BXPY_HasSelectedEnough(void);
static u32 BXPY_CalculateCursorMonValue(enum BattleSide side);
static enum Species BXPY_GetSpeciesFromPosition(enum BattleTrainer trainer, u32 cursorMon);
static bool8 BXPY_IsCursorOnEmpty(void);
static bool8 BXPY_IsCursorOnEnemy(void);
static bool8 BXPY_IsCursorOnPartner(void);
static void BXPY_ResetAllSpriteIds(void);
static void BXPY_InitializeBackgroundsAndLoadBackgroundGraphics(void);
static u32 BXPY_CountNumberSelected(void);
static void SpriteCB_HighlightSprite(struct Sprite *sprite);
static void BXPY_CreateHighlightSprite(void);
static void BXPY_GoToPokemonSummary(u8 taskId);
static void Task_LoadPokemonSummary(u8 taskId);
static void CB2_ReturnToBXPYInterface(void);
static bool8 BXPY_IsCursorOnSelectedMon(void);
static void BXPY_SelectMonAndShowMenu(u8 taskId);
static void BXPY_HandleMonClearMenu(u8 taskId);
static void BXPY_ClearMenuReturnToMainTask(u8 taskId);
static void Task_HandleMonMenu(u8 taskId);
static bool8 BXPY_ShouldHandleMonsWithFullMenu(void);
static void BXPY_CreateMonMenu(void);
static enum BattleTrainer BXPY_DetermineTrainer(enum BattleSide side, enum BXPYPages page);
static void BXPY_DrawPage(void);
static void BXPY_RemoveSprite(enum BXPYSpriteIds first, enum BXPYSpriteIds last);
static void BXPY_RemovePlayerMonSprites(void);
static void BXPY_RemovePlayerHPSprites(void);
static void BXPY_RemovePlayerSexSprites(void);
static void BXPY_RemoveEnemyMonSprites(void);
static void BXPY_RemoveEnemySexSprites(void);
static void BXPY_RemoveAllSprites(void);
static bool8 BXPY_IsSpriteIndexMon(enum BXPYSpriteIds spriteIndex);
static void SpriteCB_BXPYType(struct Sprite *sprite);
static void BXPY_PrintTypes(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex);
static void BXPY_RefreshSelectedSprites(void);

struct BXPYState *sBXPYState = NULL;
static u8 *sBgTilemapBuffer[BG_BXPY_COUNT] = {NULL};

static void Task_BXPY_PartySelection(u8 taskId)
{
    if (gPaletteFade.active)
        return;

    if (JOY_NEW(DPAD_LEFT) || JOY_REPEAT(DPAD_LEFT))
    {
        PlaySE(SE_BXPY_GENERIC);
        BXPY_ChangePosition(-6);
        BXPY_DisplayHelpBar(WIN_BXPY_HELP_BAR);
        BXPY_DisplayPlayerPartyCursorMove();
        return;
    }

    if (JOY_NEW(DPAD_RIGHT) || JOY_REPEAT(DPAD_RIGHT))
    {
        PlaySE(SE_BXPY_GENERIC);
        BXPY_ChangePosition(6);
        BXPY_DisplayHelpBar(WIN_BXPY_HELP_BAR);
        BXPY_DisplayPlayerPartyCursorMove();
        return;
    }

    if (JOY_NEW(DPAD_UP) || JOY_REPEAT(DPAD_UP))
    {
        PlaySE(SE_BXPY_GENERIC);
        BXPY_ChangePosition(-1);
        BXPY_DisplayHelpBar(WIN_BXPY_HELP_BAR);
        BXPY_DisplayPlayerPartyCursorMove();
        return;
    }

    if (JOY_NEW(DPAD_DOWN) || JOY_REPEAT(DPAD_DOWN))
    {
        PlaySE(SE_BXPY_GENERIC);
        BXPY_ChangePosition(1);
        BXPY_DisplayHelpBar(WIN_BXPY_HELP_BAR);
        BXPY_DisplayPlayerPartyCursorMove();
        return;
    }

    if (JOY_NEW(A_BUTTON) || JOY_REPEAT(A_BUTTON))
    {
        if (BXPY_IsCursorOnEmpty())
{
        PlaySE(SE_BXPY_ERROR);
            return;
}
        else if (BXPY_IsCursorOnEnemy() && BXPY_IsOpenTeamSheetOn() == TRUE)
            BXPY_GoToPokemonSummary(taskId);
        else if (BXPY_IsCursorOnPartner())
            BXPY_GoToPokemonSummary(taskId);
        else if (BXPY_IsCursorOnEnemy() && BXPY_IsOpenTeamSheetOn() == FALSE)
            return;
        else
            BXPY_SelectMonAndShowMenu(taskId);
        return;
    }

    if (JOY_NEW(START_BUTTON) || JOY_REPEAT(START_BUTTON))
    {
        if (BXPY_HasSelectedEnough() == FALSE)
            return;

        PlaySoundStartFadeQuitApp(taskId);
    }

    if (JOY_NEW(SELECT_BUTTON) || JOY_REPEAT(SELECT_BUTTON))
    {
        if (BXPY_IsMultiBattle() == FALSE)
{
        PlaySE(SE_BXPY_ERROR);
            return;
}
        PlaySE(SE_BXPY_SWITCH_PAGE);
        BXPY_TogglePage();
        BXPY_DrawPage();
    }
}

static void BXPY_AddRemoveSelectedMon(void)
{
    u32 currentIndex = BXPY_GetPosition();

    if (BXPY_IsCursorOnSelectedMon())
    {
        BXPY_RemoveIndexFromSelected(currentIndex);
    }
    else
    {
        if (BXPY_HasSelectedEnough() == FALSE)
        {
            BXPY_SetSelectedMons(BXPY_CountNumberSelected(),currentIndex);
        }
    }

    BXPY_RefreshSelectedSprites();
    BXPY_DisplayHelpBar(WIN_BXPY_HELP_BAR);
}

static void BXPY_RemoveIndexFromSelected(u32 currentIndex)
{
    PlaySE(SE_BXPY_REMOVE);
    u32 bringSize = min(BXPY_GetBringSize(),NUM_BXPY_MAX_MONS_SHOWED);
    u32 selectedIndex = 0;
    s32 retVal = -1;

    for (selectedIndex = 0; selectedIndex < bringSize; selectedIndex++)
        if (BXPY_GetSelectedMons(selectedIndex) == currentIndex)
            BXPY_SetSelectedMons(selectedIndex,BXPY_EMPTY_MON);

    u32 i, last;
    for (i = 0, last = 0; i < bringSize; i++)
    {
        u32 mon = (BXPY_GetSelectedMons(i));

        if (mon != BXPY_EMPTY_MON)
        {
            if (i != last)
                BXPY_SetSelectedMons(last,mon);
            last++;
        }
        else if (retVal == -1)
        {
            retVal = i;
        }
    }

    for (; last < bringSize; last++)
        BXPY_SetSelectedMons(last,BXPY_EMPTY_MON);
}

static void BXPY_ChangePosition(s32 delta)
{
    u32 current = BXPY_GetPosition();
    s32 new = delta + current;
    u32 max = (PARTY_SIZE * 2) - 1;

    if (delta == 6)
    {
        if (new > max)
            new = current - 6;
    }
    else if (delta == -6)
    {
        if (new < 0)
            new = current + 6;
    }

    if (new < 0)
        new = max;

    if (new > max)
        new = 0;

    BXPY_SetPosition(new);
}

static void BXPY_SetPosition(u32 position)
{
    sBXPYState->position = position;
}

static u8 BXPY_GetPosition(void)
{
    return sBXPYState->position;
}

static void BXPY_SetMusicFlag(bool32 isFirstTime)
{
    sBXPYState->musicFlag = isFirstTime;
}

static u8 BXPY_GetMusicFlag(void)
{
    return sBXPYState->musicFlag;
}

static u8 BXPY_GetBringSize(void)
{
    return sBXPYState->bringSize;
}

static void BXPY_SetBringSize(u32 bringSize)
{
    sBXPYState->bringSize = bringSize;
}

static u8 BXPY_GetPickSize(void)
{
    return sBXPYState->pickSize;
}

static void BXPY_SetPickSize(u32 pickSize)
{
    sBXPYState->pickSize = pickSize;
}

static void BXPY_SetBattleFlags(u32 battleFlags)
{
    sBXPYState->battleFlags = battleFlags;
}

static u32 BXPY_GetBattleFlags(void)
{
    return sBXPYState->battleFlags;
}

static void BXPY_SetPage(enum BXPYPages page)
{
    sBXPYState->page = page;
}

static u32 BXPY_GetPage(void)
{
    return sBXPYState->page;
}

static bool8 BXPY_IsOnPartnerPage(void)
{
    return (BXPY_GetPage() == BXPY_PAGE_OPPONENT_B);
}

static void BXPY_TogglePage(void)
{
    u32 newPage = (BXPY_GetPage() == BXPY_PAGE_OPPONENT_A) ? BXPY_PAGE_OPPONENT_B : BXPY_PAGE_OPPONENT_A;

    BXPY_SetPage(newPage);
}

static void BXPY_SetSpriteId(u32 spriteIndex, u32 spriteId)
{
    sBXPYState->spriteId[spriteIndex] = spriteId;
}

static u8 BXPY_GetSpriteId(u32 spriteIndex)
{
    return sBXPYState->spriteId[spriteIndex];
}

static void BXPY_SetSelectedMons(u32 monIndex, u32 order)
{
    sBXPYState->selectedMons[monIndex] = order;
}

static u8 BXPY_GetSelectedMons(u32 monIndex)
{
    return sBXPYState->selectedMons[monIndex];
}

u32 IsDoingBringXPickYSelection(void)
{
    return (FindTaskIdByFunc(Task_BXPY_PartySelection) != TASK_NONE);
}

static const struct BgTemplate sBXPYBgTemplates[] =
{
    [BG0_BXPY_TEXT] =
    {
        .bg = BG0_BXPY_TEXT,
        .charBaseIndex = 2,
        .mapBaseIndex = 17,
        .priority = 0,
    },
    [BG1_BXPY_INFO] =
    {
        .bg = BG1_BXPY_INFO,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .priority = 1,
    },
    [BG2_BXPY_PARTY_BG] =
    {
        .bg = BG2_BXPY_PARTY_BG,
        .charBaseIndex = 0,
        .mapBaseIndex = 5,
        .priority = 2,
    },
    [BG3_BXPY_WALLPAPER] =
    {
        .bg = BG3_BXPY_WALLPAPER,
        .charBaseIndex = 1,
        .mapBaseIndex = 9,
        .priority = 2,
    },
};
#if BXPY_SKIN == GEN_CHAMPIONS
#include "data/bxpy_graphics_champions.h"
#else
#include "data/bxpy_graphics_emerald.h"
#endif

static const struct WindowTemplate sBXPYWindows[] =
{
    [WIN_BXPY_PLAYER_INFO] =
    {
        .bg = BG1_BXPY_INFO,
        .tilemapLeft = 2,
        .tilemapTop = 0,
        .width = 12,
        .height = 18,
        .paletteNum = BXPY_PALETTE_TEXT_ID,
    },
    [WIN_BXPY_ENEMY_NAME] =
    {
        .bg = BG1_BXPY_INFO,
        .tilemapLeft = 19,
        .tilemapTop = 0,
        .width = 9,
        .height = 2,
        .paletteNum = BXPY_PALETTE_TEXT_ID,
    },
    [WIN_BXPY_ENEMY_LEVELS] =
    {
        .bg = BG1_BXPY_INFO,
        .tilemapLeft = 23,
        .tilemapTop = 2,
        .width = 4,
        .height = 16,
        .paletteNum = BXPY_PALETTE_TEXT_ID,
    },
    [WIN_BXPY_HELP_BAR] =
    {
        .bg = BG1_BXPY_INFO,
        .tilemapLeft = 0,
        .tilemapTop = 18,
        .width = 30,
        .height = 2,
        .paletteNum = BXPY_PALETTE_TEXT_ID,
    },
    [WIN_BXPY_MENU] =
    {
        .bg = BG0_BXPY_TEXT,
        .tilemapLeft = 21,
        .tilemapTop = 12,
        .width = 8,
        .height = 6,
        .paletteNum = BXPY_PALETTE_MENU_ID,
    },
    [WIN_BXPY_MENU_FULL]
    {
        .bg = BG0_BXPY_TEXT,
        .tilemapLeft = 21,
        .tilemapTop = 14,
        .width = 8,
        .height = 4,
        .paletteNum = BXPY_PALETTE_MENU_ID,
    },
    DUMMY_WIN_TEMPLATE
};

const u8 sBXPYWindowFontColors[BXPY_FONT_COLOR_COUNT][3] =
{
    [BXPY_FONT_COLOR_PLAYER] =
    {
        BXPY_TEXT_PALETTE_TRANSPERANT,
        BXPY_TEXT_PALETTE_WHITE,
        BXPY_TEXT_PALETTE_PURPLE,
    },
    [BXPY_FONT_COLOR_PLAYER_SELECTED] =
    {
        BXPY_TEXT_PALETTE_TRANSPERANT,
        BXPY_TEXT_PALETTE_BLACK,
        BXPY_TEXT_PALETTE_YELLOW,
    },
    [BXPY_FONT_COLOR_ENEMY_NAME] =
    {
        BXPY_TEXT_PALETTE_TRANSPERANT,
        BXPY_TEXT_PALETTE_WHITE,
        BXPY_TEXT_PALETTE_RED,
    },
    [BXPY_FONT_COLOR_ENEMY] =
    {
        BXPY_TEXT_PALETTE_TRANSPERANT,
        BXPY_TEXT_PALETTE_WHITE,
        BXPY_TEXT_PALETTE_RED,
    },
    [BXPY_FONT_COLOR_HELP_BAR] =
    {
        BXPY_TEXT_PALETTE_TRANSPERANT,
        BXPY_TEXT_PALETTE_WHITE,
        BXPY_TEXT_PALETTE_BLACK,
    },
    [BXPY_FONT_COLOR_SELECT_SPRITE] =
    {
        BXPY_TEXT_PALETTE_TRANSPERANT,
        BXPY_TEXT_SELECT_PALETTE_BLACK,
        BXPY_TEXT_SELECT_PALETTE_GRAY
    },
};

static void BXPY_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();

    if (BXPY_SKIN != GEN_CHAMPIONS)
        return;

    if (BXPY_SCROLLING_BACKGROUND == FALSE)
        return;

    ChangeBgX(BG3_BXPY_WALLPAPER, 64, BG_COORD_ADD);
    ChangeBgY(BG3_BXPY_WALLPAPER, 64, BG_COORD_ADD);
}

static void BXPY_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static bool8 BXPY_InitalizeBackgrounds(void)
{
    ResetAllBgsCoordinates();

    if (!AllocZeroedTilemapBuffers())
        return FALSE;

    HandleAndShowBgs();

    return TRUE;
}

static bool8 AllocZeroedTilemapBuffers(void)
{
    for (enum BXPYBackgrounds backgroundId = 0; backgroundId < BG_BXPY_COUNT; backgroundId++)
    {
        sBgTilemapBuffer[backgroundId] = AllocZeroed(BG_SCREEN_SIZE);

        if (sBgTilemapBuffer[backgroundId] == NULL)
            return FALSE;

        memset(sBgTilemapBuffer[backgroundId],0,BG_SCREEN_SIZE);
    }
    return TRUE;
}

static void HandleAndShowBgs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBXPYBgTemplates, NELEMS(sBXPYBgTemplates));

    for (enum BXPYBackgrounds backgroundId = 0; backgroundId < BG_BXPY_COUNT; backgroundId++)
    {
        SetScheduleBgs(backgroundId);
        ShowBg(backgroundId);
    }
}

static void SetScheduleBgs(enum BXPYBackgrounds backgroundId)
{
    SetBgTilemapBuffer(backgroundId, sBgTilemapBuffer[backgroundId]);
    ScheduleBgCopyTilemapToVram(backgroundId);
}

static bool8 AreTilesOrTilemapEmpty(enum BXPYBackgrounds backgroundId)
{
    return (sBXPY_BackgroundGraphics[backgroundId].tiles == NULL || sBXPY_BackgroundGraphics[backgroundId].tilemap == NULL);
}

static void LoadGraphics(void)
{
    ResetTempTileDataBuffers();

    for (enum BXPYBackgrounds backgroundId = BG0_BXPY_TEXT; backgroundId < BG_BXPY_COUNT; backgroundId++)
    {
        if (AreTilesOrTilemapEmpty(backgroundId))
            continue;

        DecompressAndLoadBgGfxUsingHeap(backgroundId, sBXPY_BackgroundGraphics[backgroundId].tiles,0,0,0);
        CopyToBgTilemapBuffer(backgroundId, sBXPY_BackgroundGraphics[backgroundId].tilemap,0,0);
    }

    LoadBXPYPalettes();

    for (u32 spriteId = 0; spriteId < BXPY_SPRITEID_COUNT; spriteId++)
    {
        if (sBXPYSpriteSheets[spriteId].spriteSheet.tag == 0)
            continue;

        LoadSpriteSheet(&sBXPYSpriteSheets[spriteId].spriteSheet);

        if (sBXPYSpriteSheets[spriteId].palette.tag == 0)
            continue;

        LoadSpritePalette(&sBXPYSpriteSheets[spriteId].palette);
    }
    CpuFill32(RGB_BLACK, gPlttBufferFaded, PLTT_SIZE);
}

static void LoadBXPYPalettes(void)
{
    LoadMonIconPalettes();
    LoadPalette(bxpyPartyBackgroundPalette, BXPY_PALETTE_PARTYBG_SLOT, PLTT_SIZE_4BPP*2);
    LoadPalette(bxpyWallpaperPalette, BXPY_PALETTE_WALLPAPER_SLOT, PLTT_SIZE_4BPP);
    LoadPalette(bxpyPalettesText, BXPY_PALETTE_TEXT_SLOT, PLTT_SIZE_4BPP);
    LoadPalette(bxpyTypesPalette, BXPY_PALETTE_TYPES_SLOT, PLTT_SIZE_4BPP*3);
}

static void PlaySoundStartFadeQuitApp(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_WaitFadeAndExitGracefully;
}

static void Task_WaitFadeAndExitGracefully(u8 taskId)
{
    if (gPaletteFade.active)
        return;

    u8 playerEnteredMons[PARTY_SIZE];

    for (u32 partyIndex = 0; partyIndex < PARTY_SIZE; partyIndex++)
        playerEnteredMons[partyIndex] = BXPY_EMPTY_MON;

    for (u32 partyIndex = 0; partyIndex < PARTY_SIZE; partyIndex++)
        playerEnteredMons[partyIndex] = BXPY_GetSelectedMons(partyIndex);

    u8 enemyEnteredMons[MAX_BATTLE_TRAINERS][PARTY_SIZE];

    u32 battleFlags = gBattleTypeFlags = BXPY_GetBattleFlags();
    BXPY_SetupAIData();

    // AI calcs using full parties
    BXPY_GetEnemyEnterMons(B_BATTLER_1, enemyEnteredMons[B_TRAINER_OPPONENT_A], BXPY_GetPickSize());
    if (TRAINER_BATTLE_PARAM.opponentB != TRAINER_NONE)
    {
        BXPY_GetEnemyEnterMons(B_BATTLER_3, enemyEnteredMons[B_TRAINER_OPPONENT_B], BXPY_GetPickSize());
    }
    if (gPartnerTrainerId != TRAINER_NONE)
    {
        BXPY_GetEnemyEnterMons(B_BATTLER_2, enemyEnteredMons[B_TRAINER_PARTNER], BXPY_GetPickSize());
    }

    // Selection of sub parties
    BXPY_SelectPartyMembers(gParties[B_TRAINER_PLAYER],playerEnteredMons,B_TRAINER_PLAYER);
    BXPY_SelectPartyMembers(gParties[B_TRAINER_OPPONENT_A],enemyEnteredMons[B_TRAINER_OPPONENT_A],B_TRAINER_OPPONENT_A);
    if (TRAINER_BATTLE_PARAM.opponentB != TRAINER_NONE)
    {
        BXPY_SelectPartyMembers(gParties[B_TRAINER_OPPONENT_B],enemyEnteredMons[B_TRAINER_OPPONENT_B],B_TRAINER_OPPONENT_B);
    }
    if (gPartnerTrainerId != TRAINER_NONE)
    {
        BXPY_SelectPartyMembers(gParties[B_TRAINER_PARTNER],enemyEnteredMons[B_TRAINER_PARTNER],B_TRAINER_PARTNER);
    }
    BXPY_ClearAIData();
    BXPY_FreeResources();
    DestroyTask(taskId);
    BattleSetup_StartBXPYBattle(battleFlags);
}

void BXPY_FadescreenAndExitGracefully(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_WaitFadeAndExitGracefully,0);
    SetVBlankCallback(BXPY_VBlankCB);
    SetMainCallback2(BXPY_MainCB);
}

static void FreeSpritePalettesResetSpriteData(void)
{
    ResetSpriteData();
    FreeSpriteTileRanges();
    FreeAllSpritePalettes();
    ClearDma3Requests();

}

static void BXPY_FreeResources(void)
{
    FreeSpritePalettesResetSpriteData();
    BXPY_FreeStructs();
    BXPY_FreeBackgrounds();
    FreeAllWindowBuffers();
    ResetSpriteData();
}

static void BXPY_FreeStructs(void)
{
    TRY_FREE_AND_SET_NULL(sBXPYState);
}

static void BXPY_FreeBackgrounds(void)
{
    for (enum BXPYBackgrounds backgroundId = 0; backgroundId < BG_BXPY_COUNT; backgroundId++)
        if (sBgTilemapBuffer[backgroundId] != NULL)
            TRY_FREE_AND_SET_NULL(sBgTilemapBuffer[backgroundId]);
}

static bool8 BXPY_AllocateStructs(void)
{
    sBXPYState = AllocZeroed(sizeof(struct BXPYState));

    return (sBXPYState == NULL);
}


void BXPY_SetupCallback(void)
{
    switch (gMain.state)
    {
        case 0:
            DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
            SetVBlankHBlankCallbacksToNull();
            ClearScheduledBgCopiesToVram();
            if (BXPY_GetMusicFlag())
                PlayBGM(MUS_BXPY_BACKGROUND);
            gMain.state++;
            break;
        case 1:
            ScanlineEffect_Stop();
            ResetPaletteFade();
            ResetTasks();
            FreeSpritePalettesResetSpriteData();
            BXPY_ResetAllSpriteIds();
            gMain.state++;
            break;
        case 2:
            BXPY_InitializeBackgroundsAndLoadBackgroundGraphics();
            gMain.state++;
            break;
        case 3:
            BXPY_CreateCursorSprite();
            BXPY_InitWindows();
            BXPY_DrawPage();
            BXPY_CreateHighlightSprite();
            gMain.state++;
            break;
        case 4:
            CreateTask(Task_BXPY_PartySelection,0);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            SetVBlankCallback(BXPY_VBlankCB);
            SetMainCallback2(BXPY_MainCB);
            break;
    }
}

static void SpriteCB_BXPYCursor(struct Sprite *sprite)
{
    u32 position = BXPY_GetPosition();

    if (BXPY_IsCursorOnEnemy())
    {
        u32 enemyPos = position - BXPY_GetBringSize();
        sprite->y = 16 + (enemyPos * 23);
        sprite->x2 = (gSineTable[(u8)sprite->data[0]] / 128) + 140;
        sprite->data[0] += 8;
    }
    else
    {
        sprite->y = 15 + (position * 23);
        sprite->x2 = gSineTable[(u8)sprite->data[0]] / 128;
        sprite->data[0] += 8;
    }
}

static void BXPY_CreateCursorSprite(void)
{
    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempSpriteTemplate.tileTag = BXPY_SPRITETAG_CURSOR;
    TempSpriteTemplate.callback = SpriteCB_BXPYCursor;
    TempSpriteTemplate.paletteTag = BXPY_PALTAG_SPRITE;

    u32 spriteId = CreateSprite(&TempSpriteTemplate, 6, 16, 0);
    gSprites[spriteId].oam.shape = SPRITE_SHAPE(16x16);
    gSprites[spriteId].oam.size = SPRITE_SIZE(16x16);
    gSprites[spriteId].invisible = FALSE;
    gSprites[spriteId].oam.priority = 0;
    gSprites[spriteId].subpriority = 0;

    BXPY_SetSpriteId(BXPY_SPRITEID_CURSOR,spriteId);
}

static void ClearWindowCopyToVram(u32 windowId)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void BXPY_InitWindows(void)
{
    const struct WindowTemplate *templates = sBXPYWindows;

    InitWindows(templates);

    u32 baseBlock = 1;
    for (enum BXPYWindows windowId = 0; windowId < WIN_BXPY_COUNT; windowId++)
    {
        SetWindowAttribute(windowId, WINDOW_BASE_BLOCK, baseBlock);
        ClearWindowCopyToVram(windowId);
        baseBlock += (templates[windowId].width * templates[windowId].height);
    }
    DeactivateAllTextPrinters();
}

static void BXPY_DisplayParty(enum BattleSide side, bool32 cursorMove)
{
    u32 bringSize = min(BXPY_GetBringSize(),NUM_BXPY_MAX_MONS_SHOWED);
    enum BXPYWindows windowId = (side == B_SIDE_PLAYER) ? WIN_BXPY_PLAYER_INFO : WIN_BXPY_ENEMY_LEVELS;

    enum BattleTrainer trainer = BXPY_DetermineTrainer(side, BXPY_GetPage());

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    for (u32 partyMonIndex = 0; partyMonIndex < bringSize; partyMonIndex++)
    {
        struct Pokemon *mon = &gParties[trainer][partyMonIndex];

        u32 species = GetMonData(mon,MON_DATA_SPECIES_OR_EGG);

        if (species == SPECIES_NONE)
            continue;

        if (species == SPECIES_EGG)
            continue;

        BXPY_DisplayPartyMonText(windowId, mon, side, partyMonIndex);

        if (cursorMove == TRUE)
            continue;

        BXPY_DisplayPartyMonIcons(windowId, mon, partyMonIndex, side, species);
    }

    CopyWindowToVram(windowId, COPYWIN_GFX);
}

static const union AnimCmd sAnim_Selected[] =
{
    ANIMCMD_FRAME(BXPY_SELECTED_FRAME_0,4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_SelectedHighlight[] =
{
    ANIMCMD_FRAME(BXPY_SELECTED_FRAME_1,4),
    ANIMCMD_END,
};

static const union AnimCmd * const sSpriteAnimTable_Selected[] =
{
    sAnim_Selected,
    sAnim_SelectedHighlight,
};

static void BXPY_CreateSelectionSprite(u32 partyMonIndex, enum BattleSide side)
{
    if (side == B_SIDE_OPPONENT)
        return;

    u32 spriteIndex = (BXPY_SPRITEID_PLAYER_SELECTED_0 + partyMonIndex);

    if (BXPY_GetSpriteId(spriteIndex) != SPRITE_NONE)
        return;

    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempSpriteTemplate.tileTag = BXPY_SPRITETAG_SELECTED_0 + partyMonIndex;
    TempSpriteTemplate.callback = SpriteCB_SelectionSprite;
    TempSpriteTemplate.paletteTag = BXPY_PALTAG_HIGHLIGHT;
    TempSpriteTemplate.anims = sSpriteAnimTable_Selected;

    u32 y = 10 + (24 * partyMonIndex);
    u32 spriteId = CreateSprite(&TempSpriteTemplate, 15, y, 0);
    gSprites[spriteId].data[1] = spriteId;
    gSprites[spriteId].data[2] = partyMonIndex;
    gSprites[spriteId].oam.shape = SPRITE_SHAPE(16x16);
    gSprites[spriteId].oam.size = SPRITE_SIZE(16x16);
    gSprites[spriteId].invisible = FALSE;
    gSprites[spriteId].oam.priority = 0;
    gSprites[spriteId].subpriority = 0;

    BXPY_SetSpriteId(spriteIndex,spriteId);
}

static void BXPY_CreateSelectionSpriteTail(u32 partyMonIndex, enum BattleSide side)
{
    if (side == B_SIDE_OPPONENT)
        return;

    u32 spriteIndex = (BXPY_SPRITEID_PLAYER_SELECTED_TAIL_0 + partyMonIndex);

    if (BXPY_GetSpriteId(spriteIndex) != SPRITE_NONE)
        return;

    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempSpriteTemplate.tileTag = BXPY_SPRITETAG_SELECTED_TAIL;
    TempSpriteTemplate.callback = SpriteCB_SelectionSprite;
    TempSpriteTemplate.paletteTag = BXPY_PALTAG_HIGHLIGHT;
    TempSpriteTemplate.anims = sSpriteAnimTable_Selected;

    u32 y = 11 + (24 * partyMonIndex);
    u32 spriteId = CreateSprite(&TempSpriteTemplate, 129, y, 0);
    gSprites[spriteId].data[1] = spriteId;
    gSprites[spriteId].data[2] = partyMonIndex;
    gSprites[spriteId].data[3] = TRUE;
    gSprites[spriteId].oam.shape = SPRITE_SHAPE(16x16);
    gSprites[spriteId].oam.size = SPRITE_SIZE(16x16);
    gSprites[spriteId].invisible = FALSE;
    gSprites[spriteId].oam.priority = 2;
    gSprites[spriteId].subpriority = 0;

    BXPY_SetSpriteId(spriteIndex,spriteId);
}

static void SpriteCB_SelectionSprite(struct Sprite *sprite)
{
    if (BXPY_IsOnPartnerPage())
    {
        sprite->invisible = TRUE;
        return;
    }

    u32 mon = sprite->data[2];
    bool32 isAlreadySelected = BXPY_IsMonAlreadySelected(mon);
    sprite->invisible = (isAlreadySelected == FALSE);

    u32 anim = (BXPY_GetPosition() != mon) ? BXPY_SELECTED : BXPY_SELECTED_HIGHLIGHT;
        StartSpriteAnimIfDifferent(sprite,anim);

    if (sprite->data[3])
        return;

    u32 spriteId = sprite->data[1];
    BXPY_DrawOrderOnSelectionSprite(spriteId,BXPY_GetOrderForMon(mon));
}

static void BXPY_DrawOrderOnSelectionSprite(u32 spriteId, u32 index)
{
    index++;

    u32 max = min(BXPY_GetBringSize(),NUM_BXPY_MAX_MONS_SHOWED);

    if (index > max)
        return;

    u8* orderString = Alloc(BXPY_ORDER_LENGTH_SIZE);
    ConvertIntToDecimalStringN(orderString,index,STR_CONV_MODE_LEFT_ALIGN,CountDigits(index));

    u32 fontId = FONT_BXPY_LEVEL;
    u32 x = 2;
    u32 y = 0;

    AddSpriteTextPrinterParameterized3(spriteId, fontId, x, y, sBXPYWindowFontColors[BXPY_FONT_COLOR_SELECT_SPRITE],TEXT_SKIP_DRAW,orderString);

    Free(orderString);
}

static u8 BXPY_GetOrderForMon(u32 monIndex)
{
    u32 bringSize = min(BXPY_GetBringSize(),NUM_BXPY_MAX_MONS_SHOWED);
    for (u32 selectedIndex = 0; selectedIndex < bringSize; selectedIndex++)
        if (BXPY_GetSelectedMons(selectedIndex) == monIndex)
            return selectedIndex;

    return bringSize;
}

static bool8 BXPY_IsMonAlreadySelected(u32 partyMonIndex)
{
    u32 bringSize = min(BXPY_GetBringSize(),NUM_BXPY_MAX_MONS_SHOWED);
    for (u32 selectedIndex = 0; selectedIndex < bringSize; selectedIndex++)
        if (BXPY_GetSelectedMons(selectedIndex) == partyMonIndex)
            return TRUE;

    return FALSE;
}

static void BXPY_DisplayPlayerParty(void)
{
    BXPY_DisplayParty(B_SIDE_PLAYER,FALSE);
}

static void BXPY_DisplayPlayerPartyCursorMove(void)
{
    BXPY_DisplayParty(B_SIDE_PLAYER,TRUE);
}

static void BXPY_DisplayPartyMonText(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex)
{
    BXPY_PrintNickname(windowId, mon, side, partyMonIndex);
    BXPY_PrintItemName(windowId, mon, side, partyMonIndex);
    BXPY_PrintLevel(windowId, mon, side, partyMonIndex);
}

static void BXPY_DisplayPartyMonIcons(enum BXPYWindows windowId, struct Pokemon *mon, u32 partyMonIndex, enum BattleSide side, u32 species)
{
    BXPY_PrintSex(windowId, mon, side, partyMonIndex);
    BXPY_PrintTypes(windowId, mon, side, partyMonIndex);
    BXPY_PrintMonIcon(windowId, mon, side, partyMonIndex,species);
    BXPY_PrintHP(windowId, mon, side, partyMonIndex);
    BXPY_CreateSelectionSprite(partyMonIndex, side);
    BXPY_CreateSelectionSpriteTail(partyMonIndex, side);
}

static void BXPY_PrintNickname(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex)
{
    if (side == B_SIDE_OPPONENT)
        return;

    u32 x = 8;
    u32 y = 2 + (partyMonIndex * 24);
    u32 fontId = FONT_BXPY_SPECIES_NAME;
    u32 letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    u32 lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);
    u32 windowWidth = BXPY_SPECIES_NICKNAME_WIDTH * TILE_SIZE_1BPP;
    u32 color = (BXPY_GetPosition() == partyMonIndex) ? BXPY_FONT_COLOR_PLAYER_SELECTED : BXPY_FONT_COLOR_PLAYER;

    GetMonData(mon,MON_DATA_NICKNAME,gStringVar1);
    fontId = GetFontIdToFit(gStringVar1,fontId,letterSpacing,windowWidth);

    AddTextPrinterParameterized4(windowId, fontId, x, y, letterSpacing, lineSpacing, sBXPYWindowFontColors[color], TEXT_SKIP_DRAW, gStringVar1);
}

static void BXPY_PrintItemName(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex)
{
    if (side == B_SIDE_OPPONENT)
        return;

    u32 heldItem = GetMonData(mon,MON_DATA_HELD_ITEM);
    if (heldItem == ITEM_NONE)
        return;

    u32 x = 8;
    u32 y = 12 + (partyMonIndex * 24);
    u32 fontId = FONT_BXPY_SPECIES_NAME;
    u32 letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    u32 lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);
    u32 windowWidth = BXPY_SPECIES_ITEM_WIDTH * TILE_SIZE_1BPP;
    u32 color = (BXPY_GetPosition() == partyMonIndex) ? BXPY_FONT_COLOR_PLAYER_SELECTED : BXPY_FONT_COLOR_PLAYER;

    StringCopy(gStringVar1,GetItemName(heldItem));
    fontId = GetFontIdToFit(gStringVar1,fontId,letterSpacing,windowWidth);

    AddTextPrinterParameterized4(windowId, fontId, x, y, letterSpacing, lineSpacing, sBXPYWindowFontColors[color], TEXT_SKIP_DRAW, gStringVar1);
}

static void BXPY_PrintLevel(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex)
{
    u32 x = (side == B_SIDE_PLAYER) ? 74 : 6;
    u32 y = (side == B_SIDE_PLAYER) ? 2 + (partyMonIndex * 24) : 6 + (partyMonIndex * 22);
    u32 fontId = FONT_BXPY_LEVEL;
    u32 letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    u32 lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);
    u32 color = 0;

    if (side == B_SIDE_OPPONENT)
        color = BXPY_FONT_COLOR_ENEMY;
    else if (BXPY_GetPosition() == partyMonIndex)
        color = BXPY_FONT_COLOR_PLAYER_SELECTED;
    else
        color = BXPY_FONT_COLOR_PLAYER;

    if (BXPY_TeamPreview_ShouldHideEnemyLevel(side))
        StringCopy(gStringVar2,COMPOUND_STRING("?"));
    else
        ConvertIntToDecimalStringN(gStringVar2,GetMonData(mon,MON_DATA_LEVEL),STR_CONV_MODE_LEFT_ALIGN,CountDigits(MAX_LEVEL));

    StringExpandPlaceholders(gStringVar1,COMPOUND_STRING("{LV}{STR_VAR_2}"));

    AddTextPrinterParameterized4(windowId, fontId, x, y, letterSpacing, lineSpacing, sBXPYWindowFontColors[color], TEXT_SKIP_DRAW, gStringVar1);
}

static const union AnimCmd sAnim_MonSexFemale[] =
{
    ANIMCMD_FRAME(BXPY_SEX_FRAME_FEMALE,4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MonSexMale[] =
{
    ANIMCMD_FRAME(BXPY_SEX_FRAME_MALE,4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MonSexHidden[] =
{
    ANIMCMD_FRAME(BXPY_SEX_FRAME_HIDDEN,4),
    ANIMCMD_END,
};

static const union AnimCmd * const sSpriteAnimTable_MonSexIcon[] =
{
    sAnim_MonSexFemale,
    sAnim_MonSexMale,
    sAnim_MonSexHidden,
};

static void BXPY_PrintSex(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex)
{
    u32 sex = GetMonGender(mon);

    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempSpriteTemplate.tileTag = BXPY_SPRITETAG_SEX;
    TempSpriteTemplate.callback = SpriteCallbackDummy;
    TempSpriteTemplate.paletteTag = BXPY_PALTAG_SPRITE;
    TempSpriteTemplate.anims = sSpriteAnimTable_MonSexIcon;

    u32 x = (side == B_SIDE_PLAYER) ? 103 : 220;
    u32 y = (side == B_SIDE_PLAYER) ?  19 + (partyMonIndex * 24) : 29 + (partyMonIndex * 22);
    u32 spriteId = CreateSprite(&TempSpriteTemplate, x, y, 0);
    gSprites[spriteId].oam.shape = SPRITE_SHAPE(16x16);
    gSprites[spriteId].oam.size = SPRITE_SIZE(16x16);
    gSprites[spriteId].oam.priority = 1;

    u32 animState = 0;

    if (BXPY_TeamPreview_ShouldHideEnemyGender(side))
    {
        animState = BXPY_SEX_HIDDEN;
    }
    else
    {
        animState = (sex == MON_FEMALE) ? BXPY_SEX_FEMALE : BXPY_SEX_MALE;
        gSprites[spriteId].invisible = (sex == MON_GENDERLESS);
    }

    StartSpriteAnimIfDifferent(&gSprites[spriteId],animState);
    u32 spriteIdStart = (side == B_SIDE_PLAYER) ? BXPY_SPRITEID_PLAYER_SEX_0 : BXPY_SPRITEID_ENEMY_SEX_0;
    BXPY_SetSpriteId(spriteIdStart + partyMonIndex,spriteId);
}

static void BXPY_PrintMonIcon(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex, u32 species)
{
    u32 x = (side == B_SIDE_PLAYER) ? 126: 170;
    u32 y = (side == B_SIDE_PLAYER) ? 10 + (partyMonIndex * 24) : 20 + (partyMonIndex * 22);
    species = BXPY_TeamPreview_TransformSpeciesId(species, side);

    u32 spriteId = CreateMonIcon(species,SpriteCB_MonIcon,x,y,0,0);
    u32 spriteIdStart = (side == B_SIDE_PLAYER) ? BXPY_SPRITEID_PLAYER_MON_0 : BXPY_SPRITEID_ENEMY_MON_0;
    gSprites[spriteId].subpriority = 1;
    BXPY_SetSpriteId(spriteIdStart + partyMonIndex,spriteId);
}

static const union AnimCmd sAnim_MonHP0[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_0,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP1[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_1,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP2[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_2,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP3[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_3,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP4[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_4,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP5[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_5,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP6[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_6,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP7[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_7,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP8[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_8,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP9[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_9,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP10[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_10,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP11[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_11,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP12[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_12,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP13[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_13,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP14[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_14,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP15[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_15,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP16[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_16,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP17[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_17,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP18[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_18,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP19[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_19,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP20[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_20,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP21[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_21,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP22[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_22,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP23[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_23,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP24[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_24,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP25[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_25,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP26[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_26,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP27[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_27,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP28[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_28,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP29[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_29,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP30[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_30,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonHP31[] =
{
    ANIMCMD_FRAME(BXPY_HP_FRAME_31,4),
    ANIMCMD_END,
};

static const union AnimCmd * const sSpriteAnimTable_MonHP[] =
{
    sAnim_MonHP0,
    sAnim_MonHP1,
    sAnim_MonHP2,
    sAnim_MonHP3,
    sAnim_MonHP4,
    sAnim_MonHP5,
    sAnim_MonHP6,
    sAnim_MonHP7,
    sAnim_MonHP8,
    sAnim_MonHP9,
    sAnim_MonHP10,
    sAnim_MonHP11,
    sAnim_MonHP12,
    sAnim_MonHP13,
    sAnim_MonHP14,
    sAnim_MonHP15,
    sAnim_MonHP16,
    sAnim_MonHP17,
    sAnim_MonHP18,
    sAnim_MonHP19,
    sAnim_MonHP20,
    sAnim_MonHP21,
    sAnim_MonHP22,
    sAnim_MonHP23,
    sAnim_MonHP24,
    sAnim_MonHP25,
    sAnim_MonHP26,
    sAnim_MonHP27,
    sAnim_MonHP28,
    sAnim_MonHP29,
    sAnim_MonHP30,
    sAnim_MonHP31,
};

static void BXPY_PrintHP(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex)
{
    if (side == B_SIDE_OPPONENT)
        return;

    u32 current = GetMonData(mon,MON_DATA_HP);
    u32 max = GetMonData(mon,MON_DATA_MAX_HP);
    u32 percent = (current * BXPY_HP_STEP_COUNT / max) - 1;

    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempSpriteTemplate.tileTag = BXPY_SPRITETAG_HP;
    TempSpriteTemplate.callback = SpriteCallbackDummy;
    TempSpriteTemplate.paletteTag = BXPY_PALTAG_SPRITE;
    TempSpriteTemplate.anims = sSpriteAnimTable_MonHP;

    u32 y = 23 + (partyMonIndex * 24);
    u32 spriteId = CreateSprite(&TempSpriteTemplate, 113, y, 0);
    gSprites[spriteId].oam.shape = SPRITE_SHAPE(32x8);
    gSprites[spriteId].oam.size = SPRITE_SIZE(32x8);
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].subpriority = 0;

    StartSpriteAnimIfDifferent(&gSprites[spriteId],percent);
    BXPY_SetSpriteId(BXPY_SPRITEID_PLAYER_HP_0 + partyMonIndex,spriteId);
}

static void BXPY_DisplayEnemyParty(void)
{
    BXPY_DisplayEnemyName();
    BXPY_DisplayParty(B_SIDE_OPPONENT,FALSE);
}

static void BXPY_DisplayEnemyName(void)
{
    enum BXPYWindows windowId = WIN_BXPY_ENEMY_NAME;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    BXPY_PrintEnemyName(windowId);
    CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void BXPY_PrintEnemyName(enum BXPYWindows windowId)
{
    u32 y = 0;
    u32 fontId = FONT_BXPY_LEVEL;
    u32 lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);
    u32 letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);
    u32 windowWidth = TILE_SIZE_1BPP * GetWindowAttribute(windowId, WINDOW_WIDTH);
    u32 trainerId = BXPY_IsOnPartnerPage() ? TRAINER_BATTLE_PARAM.opponentB : TRAINER_BATTLE_PARAM.opponentA;

    StringCopy(gStringVar4, GetTrainerNameFromId(trainerId));
    fontId = GetFontIdToFit(gStringVar4,fontId,letterSpacing,windowWidth);
    u32 x = GetStringRightAlignXOffset(fontId,gStringVar4,windowWidth);

    AddTextPrinterParameterized4(windowId, fontId, x, y, letterSpacing, lineSpacing, sBXPYWindowFontColors[BXPY_FONT_COLOR_ENEMY_NAME], TEXT_SKIP_DRAW, gStringVar4);
}

static void BXPY_DisplayHelpBar(enum BXPYWindows windowId)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    BXPY_PrintHelpBarText(windowId);
    CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void BXPY_PrintHelpBarText(enum BXPYWindows windowId)
{
    u32 x = 4;
    u32 y = 0;
    u32 fontId = FONT_BXPY_HELPBAR;
    u32 lineSpacing = GetFontAttribute(fontId, FONTATTR_LINE_SPACING);
    u32 letterSpacing = GetFontAttribute(fontId, FONTATTR_LETTER_SPACING);

    bool32 onEnemy = BXPY_IsCursorOnEnemy();
    bool32 isOTSOn = BXPY_IsOpenTeamSheetOn();
    bool32 isPartnerPage = BXPY_IsOnPartnerPage();
    bool32 isMultiBattle = BXPY_IsMultiBattle();
    bool32 hasSelectedEnough = BXPY_HasSelectedEnough();

    StringCopy(gStringVar4, COMPOUND_STRING(""));

    if (hasSelectedEnough)
    {
        StringAppend(gStringVar4, COMPOUND_STRING("{START_BUTTON} Start Battle"));
    }
    else
    {
        u32 pickSize = BXPY_GetPickSize();
        ConvertIntToDecimalStringN(gStringVar1,pickSize,STR_CONV_MODE_LEFT_ALIGN,CountDigits(pickSize));
        StringAppend(gStringVar4, COMPOUND_STRING("Select {STR_VAR_1} Pokemon."));
    }

    if ((onEnemy == FALSE) && (isPartnerPage == FALSE))
        StringAppend(gStringVar4,COMPOUND_STRING(" {A_BUTTON} Select"));
    else if (isOTSOn == TRUE)
        StringAppend(gStringVar4,COMPOUND_STRING(" {A_BUTTON} Summary"));

    if ((isMultiBattle == TRUE) && (isPartnerPage == FALSE))
        StringAppend(gStringVar4,COMPOUND_STRING(" {SELECT_BUTTON} See Partners"));
    else if ((isMultiBattle == TRUE) && (isPartnerPage == TRUE))
        StringAppend(gStringVar4,COMPOUND_STRING(" {SELECT_BUTTON} See {PLAYER}"));

    StringExpandPlaceholders(gStringVar2,gStringVar4);

    AddTextPrinterParameterized4(windowId, fontId, x, y, letterSpacing, lineSpacing, sBXPYWindowFontColors[BXPY_FONT_COLOR_HELP_BAR], TEXT_SKIP_DRAW, gStringVar2);
}

static bool8 BXPY_HasSelectedEnough(void)
{
    return (BXPY_CountNumberSelected() == BXPY_GetPickSize());
}

static u32 BXPY_CalculateCursorMonValue(enum BattleSide side)
{
    u32 position = BXPY_GetPosition();
    return (BXPY_IsCursorOnEnemy()) ? position - PARTY_SIZE : position;
}

static enum Species BXPY_GetSpeciesFromPosition(enum BattleTrainer trainer, u32 cursorMon)
{
    return (GetMonData(&gParties[trainer][cursorMon],MON_DATA_SPECIES_OR_EGG));
}

static bool8 BXPY_IsCursorOnEmpty(void)
{
    enum BattleSide side = BXPY_IsCursorOnEnemy() ? B_SIDE_OPPONENT : B_SIDE_PLAYER;
    enum BattleTrainer trainer = BXPY_DetermineTrainer(side, BXPY_GetPage());
    u32 cursorMon = BXPY_CalculateCursorMonValue(side);
    enum Species species = BXPY_GetSpeciesFromPosition(trainer,cursorMon);

    if (species == SPECIES_NONE)
        return TRUE;

    return (species == SPECIES_EGG);
}

static bool8 BXPY_IsCursorOnEnemy(void)
{
    return BXPY_GetPosition() >= PARTY_SIZE;
}

static bool8 BXPY_IsCursorOnPartner(void)
{
    if (BXPY_IsOnPartnerPage() == FALSE)
        return FALSE;

    return (BXPY_IsCursorOnEnemy() == FALSE);
}

bool8 BXPY_IsMultiBattle(void)
{
    if (TRAINER_BATTLE_PARAM.opponentB != TRAINER_NONE)
        return TRUE;

    return (gPartnerTrainerId != TRAINER_NONE);
}

static void BXPY_ResetAllSpriteIds(void)
{
    for (u32 spriteIndex = 0; spriteIndex < BXPY_SPRITEID_COUNT; spriteIndex++)
        BXPY_SetSpriteId(spriteIndex,SPRITE_NONE);
}

static void BXPY_InitializeBackgroundsAndLoadBackgroundGraphics(void)
{
    if (BXPY_InitalizeBackgrounds())
        LoadGraphics();
    else
        BXPY_FadescreenAndExitGracefully();
}

static u32 BXPY_CountNumberSelected(void)
{
    u32 count = 0;
    u32 bringSize = min(BXPY_GetBringSize(),NUM_BXPY_MAX_MONS_SHOWED);
    for (u32 selectedIndex = 0; selectedIndex < bringSize; selectedIndex++)
        if (BXPY_GetSelectedMons(selectedIndex) != BXPY_EMPTY_MON)
            count++;

    return count;
}

static void SpriteCB_HighlightSprite(struct Sprite *sprite)
{
    sprite->invisible = BXPY_IsCursorOnEnemy();
    sprite->y = 7 + (24 * BXPY_GetPosition());
}

static const union AnimCmd sAnim_HighlightLeft[] =
{
    ANIMCMD_FRAME(BXPY_HIGHLIGHT_FRAME_LEFT,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_HighlightCenter[] =
{
    ANIMCMD_FRAME(BXPY_HIGHLIGHT_FRAME_CENTER,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_HighlightRight[] =
{
    ANIMCMD_FRAME(BXPY_HIGHLIGHT_FRAME_RIGHT,4),
    ANIMCMD_END,
};

static const union AnimCmd * const sSpriteAnimTable_Highlight[] =
{
    sAnim_HighlightLeft,
    sAnim_HighlightCenter,
    sAnim_HighlightRight,
};

static void BXPY_CreateHighlightSprite(void)
{
    for (enum BXPYHighlight highlightIndex = BXPY_HIGHLIGHT_LEFT; highlightIndex < BXPY_HIGHLIGHT_COUNT; highlightIndex++)
    {
        struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

        TempSpriteTemplate.tileTag = BXPY_SPRITETAG_HIGHLIGHT;
        TempSpriteTemplate.callback = SpriteCB_HighlightSprite;
        TempSpriteTemplate.paletteTag = BXPY_PALTAG_HIGHLIGHT;
        TempSpriteTemplate.anims = sSpriteAnimTable_Highlight;

        u32 x = (64 * highlightIndex) + 12;
        u32 spriteId = CreateSprite(&TempSpriteTemplate, x, 12, 0);
        gSprites[spriteId].oam.shape = SPRITE_SHAPE(64x32);
        gSprites[spriteId].oam.size = SPRITE_SIZE(64x32);
        gSprites[spriteId].oam.priority = 2;
        gSprites[spriteId].subpriority = 1;

        BXPY_SetSpriteId(BXPY_SPRITEID_HIGHLIGHT_LEFT + highlightIndex,spriteId);
        StartSpriteAnim(&gSprites[spriteId],highlightIndex);
    }
}

static void BXPY_GoToPokemonSummary(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_LoadPokemonSummary,0);
    DestroyTask(taskId);
}

static void Task_LoadPokemonSummary(u8 taskId)
{
    if (gPaletteFade.active)
        return;

    DestroyTask(taskId);
    FreeAllWindowBuffers();

    enum BattleSide side = BXPY_IsCursorOnEnemy() ? B_SIDE_OPPONENT : B_SIDE_PLAYER;
    enum BattleTrainer trainer = BXPY_DetermineTrainer(side, BXPY_GetPage());
    u32 cursorMon = BXPY_CalculateCursorMonValue(side);
    u32 mode = (side == B_SIDE_PLAYER) ? SUMMARY_MODE_LOCK_MOVES : SUMMARY_MODE_BXPY;
    u32 partySize = CalculatePartyCount(trainer) - 1;
    ShowPokemonSummaryScreen(mode, &gParties[trainer], cursorMon, partySize, CB2_ReturnToBXPYInterface);
}

static void CB2_ReturnToBXPYInterface(void)
{
    u32 bringSize = BXPY_GetBringSize();
    u32 pickSize = BXPY_GetPickSize();
    u32 battleFlags = BXPY_GetBattleFlags();
    enum BXPYPages page = BXPY_GetPage();

    u32 old = BXPY_GetPosition();
    u32 new = VarGet(VAR_BXPY_MON_INDEX);
    u32 position = (old >= PARTY_SIZE) ? (new + PARTY_SIZE) : new;

    u8 playerEnteredMons[PARTY_SIZE];
    for (u32 partyIndex = 0; partyIndex < ARRAY_COUNT(playerEnteredMons); partyIndex++)
        playerEnteredMons[partyIndex] = BXPY_GetSelectedMons(partyIndex);

    BXPY_FreeResources();
    BXPY_PreparePartiesAndInit(bringSize,pickSize,battleFlags,playerEnteredMons,position,page,FALSE);
}

void BXPY_InitializeAndSaveCallback(u32 bringSize, u32 pickSize, u32 battleFlags, u8* playerEnteredMons, u32 position, enum BXPYPages page, bool32 isFirstTime)
{
    if (BXPY_AllocateStructs())
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        return;
    }

    BXPY_SetPickSize(pickSize);
    BXPY_SetBringSize(bringSize);
    BXPY_SetBattleFlags(battleFlags);
    BXPY_SetPosition(position);
    BXPY_SetPage(page);
    BXPY_SetMusicFlag(isFirstTime);

    for (u32 partyIndex = 0; partyIndex < PARTY_SIZE; partyIndex++)
         BXPY_SetSelectedMons(partyIndex,playerEnteredMons[partyIndex]);

    SetMainCallback2(BXPY_SetupCallback);
}

static const u8 sText_RemoveMenu[] = _("Remove\nSummary\nCancel");
static const u8 sText_AddMenu[] = _("Add\nSummary\nCancel");
static const u8 sText_FullMenu[] = _("Summary\nCancel");

static bool8 BXPY_IsCursorOnSelectedMon(void)
{
    u32 currentIndex = BXPY_GetPosition();
    return BXPY_IsMonAlreadySelected(currentIndex);
}

static void BXPY_SelectMonAndShowMenu(u8 taskId)
{
    PlaySE(SE_BXPY_GENERIC);
    BXPY_CreateMonMenu();
    gTasks[taskId].func = Task_HandleMonMenu;
}

static void BXPY_HandleMonClearMenu(u8 taskId)
{
    BXPY_AddRemoveSelectedMon();
    BXPY_ClearMenuReturnToMainTask(taskId);
}

static void BXPY_ClearMenuReturnToMainTask(u8 taskId)
{
    ClearStdWindowAndFrameToTransparent(WIN_BXPY_MENU_FULL,TRUE);
    ClearStdWindowAndFrameToTransparent(WIN_BXPY_MENU,TRUE);
    gTasks[taskId].func = Task_BXPY_PartySelection;
}

static void Task_HandleMonMenu(u8 taskId)
{
    //s8 input = Menu_ProcessInputNoWrapClearOnChoose();
    s8 input = Menu_ProcessInput();

    if (input == MENU_B_PRESSED || input == BXPY_MENU_CANCEL)
    {
        BXPY_ClearMenuReturnToMainTask(taskId);
    }
    else if (input == BXPY_MENU_SUMMARY_MON)
    {
        if (BXPY_ShouldHandleMonsWithFullMenu())
            BXPY_ClearMenuReturnToMainTask(taskId);
        else
            BXPY_GoToPokemonSummary(taskId);
    }
    else if (input == BXPY_MENU_ADD_MON)
    {
        if (BXPY_ShouldHandleMonsWithFullMenu())
            BXPY_GoToPokemonSummary(taskId);
        else
            BXPY_HandleMonClearMenu(taskId);
    }
}

static bool8 BXPY_ShouldHandleMonsWithFullMenu(void)
{
    return ((BXPY_IsCursorOnSelectedMon() == FALSE) && (BXPY_HasSelectedEnough()));
}

static void BXPY_CreateMonMenu(void)
{
    struct TextPrinterTemplate printer;
    u32 baseTileNum = 1;
    u32 windowId = BXPY_ShouldHandleMonsWithFullMenu() ? WIN_BXPY_MENU_FULL : WIN_BXPY_MENU;

    LoadUserWindowBorderGfx(windowId,baseTileNum,BXPY_PALETTE_BORDER_SLOT);
    DrawStdFrameWithCustomTileAndPalette(windowId, TRUE, baseTileNum, BXPY_PALETTE_BORDER_ID);

    if (BXPY_IsCursorOnSelectedMon())
        printer.currentChar = sText_RemoveMenu;
    else if (BXPY_HasSelectedEnough())
        printer.currentChar = sText_FullMenu;
    else
        printer.currentChar = sText_AddMenu;

    printer.type = WINDOW_TEXT_PRINTER;
    printer.windowId = windowId;
    printer.fontId = FONT_NORMAL;
    printer.x = 8;
    printer.y = 1;
    printer.currentX = printer.x;
    printer.currentY = printer.y;
    printer.color.foreground = GetFontAttribute(FONT_NORMAL, FONTATTR_COLOR_FOREGROUND);
    printer.color.background = GetFontAttribute(FONT_NORMAL, FONTATTR_COLOR_BACKGROUND);
    printer.color.shadow = GetFontAttribute(FONT_NORMAL, FONTATTR_COLOR_SHADOW);
    printer.color.accent = GetFontAttribute(FONT_NORMAL, FONTATTR_COLOR_ACCENT);
    printer.letterSpacing = 0;
    printer.lineSpacing = 0;

    u32 menuCount = (BXPY_HasSelectedEnough()) ? BXPY_MENU_COUNT - 1 : BXPY_MENU_COUNT;
    AddTextPrinter(&printer, TEXT_SKIP_DRAW, NULL);
    InitMenuInUpperLeftCornerNormal(windowId, menuCount, 0);
}

bool8 BXPY_IsOpenTeamSheetOn(void)
{
    return BXPY_OPEN_TEAM_SHEET;
}

static enum BattleTrainer BXPY_DetermineTrainer(enum BattleSide side, enum BXPYPages page)
{
    if (side == B_SIDE_PLAYER)
    {
        if (page == BXPY_PAGE_OPPONENT_A)
            return B_TRAINER_PLAYER;
        else
            return B_TRAINER_PARTNER;
    }
    else
    {
        if (page == BXPY_PAGE_OPPONENT_A)
            return B_TRAINER_OPPONENT_A;
        else
            return B_TRAINER_OPPONENT_B;
    }
}

static void BXPY_DrawPage(void)
{

    BXPY_RemoveAllSprites();
    BXPY_DisplayPlayerParty();
    BXPY_DisplayEnemyParty();
    BXPY_DisplayHelpBar(WIN_BXPY_HELP_BAR);
}

static void BXPY_RemoveSprite(enum BXPYSpriteIds first, enum BXPYSpriteIds last)
{
    for (u32 spriteIndex = first; spriteIndex < last + 1; spriteIndex++)
    {
        u32 spriteId = (BXPY_GetSpriteId(spriteIndex));
        if (spriteId == SPRITE_NONE)
            continue;

        if (BXPY_IsSpriteIndexMon(spriteIndex))
            FreeAndDestroyMonIconSprite(&gSprites[spriteId]);
        else
            DestroySpriteAndFreeResources(&gSprites[spriteId]);

        BXPY_SetSpriteId(spriteIndex,SPRITE_NONE);
    }
}

static void BXPY_RemovePlayerMonSprites(void)
{
    BXPY_RemoveSprite(BXPY_SPRITEID_PLAYER_MON_0,BXPY_SPRITEID_PLAYER_MON_5);
}
static void BXPY_RemovePlayerHPSprites(void)
{
    BXPY_RemoveSprite(BXPY_SPRITEID_PLAYER_HP_0,BXPY_SPRITEID_PLAYER_HP_5);
}
static void BXPY_RemovePlayerSexSprites(void)
{
    BXPY_RemoveSprite(BXPY_SPRITEID_PLAYER_SEX_0,BXPY_SPRITEID_PLAYER_SEX_5);
}
static void BXPY_RemoveEnemyMonSprites(void)
{
    BXPY_RemoveSprite(BXPY_SPRITEID_ENEMY_MON_0,BXPY_SPRITEID_ENEMY_MON_5);
}
static void BXPY_RemoveEnemySexSprites(void)
{
    BXPY_RemoveSprite(BXPY_SPRITEID_ENEMY_SEX_0,BXPY_SPRITEID_ENEMY_SEX_5);
}

static void BXPY_RemoveAllSprites(void)
{
    BXPY_RemovePlayerMonSprites();
    BXPY_RemovePlayerHPSprites();
    BXPY_RemovePlayerSexSprites();
    BXPY_RemoveEnemyMonSprites();
    BXPY_RemoveEnemySexSprites();
}

static bool8 BXPY_IsSpriteIndexMon(enum BXPYSpriteIds spriteIndex)
{
    u32 monSpriteIds[] =
    {
        BXPY_SPRITEID_PLAYER_MON_0,
        BXPY_SPRITEID_PLAYER_MON_1,
        BXPY_SPRITEID_PLAYER_MON_2,
        BXPY_SPRITEID_PLAYER_MON_3,
        BXPY_SPRITEID_PLAYER_MON_4,
        BXPY_SPRITEID_PLAYER_MON_5,
        BXPY_SPRITEID_ENEMY_MON_0,
        BXPY_SPRITEID_ENEMY_MON_1,
        BXPY_SPRITEID_ENEMY_MON_2,
        BXPY_SPRITEID_ENEMY_MON_3,
        BXPY_SPRITEID_ENEMY_MON_4,
        BXPY_SPRITEID_ENEMY_MON_5,
    };

    for (u32 index = 0; index < ARRAY_COUNT(monSpriteIds); index++)
        if (spriteIndex == monSpriteIds[index])
            return TRUE;

    return FALSE;
}

static const union AnimCmd sAnim_MonTypeNone[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_NONE,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeNormal[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_NORMAL,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeFighting[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_FIGHTING,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeFlying[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_FLYING,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypePoison[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_POISON,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeGround[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_GROUND,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeRock[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_ROCK,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeBug[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_BUG,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeGhost[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_GHOST,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeSteel[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_STEEL,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeMystery[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_MYSTERY,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeFire[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_FIRE,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeWater[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_WATER,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeGrass[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_GRASS,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeElectric[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_ELECTRIC,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypePsychic[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_PSYCHIC,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeIce[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_ICE,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeDragon[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_DRAGON,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeDark[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_DARK,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeFairy[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_FAIRY,4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_MonTypeStellar[] =
{
    ANIMCMD_FRAME(BXPY_TYPE_FRAME_STELLAR,4),
    ANIMCMD_END,
};

static const union AnimCmd * const sSpriteAnimTable_MonTypeIcon[] =
{
    sAnim_MonTypeNone,
    sAnim_MonTypeNormal,
    sAnim_MonTypeFighting,
    sAnim_MonTypeFlying,
    sAnim_MonTypePoison,
    sAnim_MonTypeGround,
    sAnim_MonTypeRock,
    sAnim_MonTypeBug,
    sAnim_MonTypeGhost,
    sAnim_MonTypeSteel,
    sAnim_MonTypeMystery,
    sAnim_MonTypeFire,
    sAnim_MonTypeWater,
    sAnim_MonTypeGrass,
    sAnim_MonTypeElectric,
    sAnim_MonTypePsychic,
    sAnim_MonTypeIce,
    sAnim_MonTypeDragon,
    sAnim_MonTypeDark,
    sAnim_MonTypeFairy,
    sAnim_MonTypeStellar,
};

static void SpriteCB_BXPYType(struct Sprite *sprite)
{
    u32 partyMonIndex = sprite->data[1];
    u32 typeIndex = sprite->data[0];

    enum BattleSide side = B_SIDE_OPPONENT;
    enum BattleTrainer trainer = BXPY_DetermineTrainer(side, BXPY_GetPage());
    enum Species species = BXPY_GetSpeciesFromPosition(trainer,partyMonIndex);
    species = BXPY_TeamPreview_TransformSpeciesId(species,side);


    enum Type type[] = {GetSpeciesType(species,0), GetSpeciesType(species,1)};

    sprite->invisible = ((species == SPECIES_EGG) || (species == SPECIES_NONE));

    if (typeIndex == 1)
        sprite->invisible = (type[0] == type[1]);

    sprite->oam.paletteNum = gTypesInfo[type[typeIndex]].palette;
    StartSpriteAnimIfDifferent(sprite,type[typeIndex]);
}

static void BXPY_PrintTypes(enum BXPYWindows windowId, struct Pokemon *mon, enum BattleSide side, u32 partyMonIndex)
{
    if (side == B_SIDE_PLAYER)
        return;

    for (u32 typeIndex = 0; typeIndex < 2; typeIndex++)
    {

    u32 spriteIndex = BXPY_SPRITEID_ENEMY_TYPE_0_MON_0 + typeIndex + (10 * partyMonIndex);
    if (BXPY_GetSpriteId(spriteIndex) != SPRITE_NONE)
        continue;

        struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;
        TempSpriteTemplate.tileTag = BXPY_SPRITETAG_TYPE;
        TempSpriteTemplate.callback = SpriteCB_BXPYType;
        TempSpriteTemplate.paletteTag = BXPY_PALTAG_TYPE;
        TempSpriteTemplate.anims = sSpriteAnimTable_MonTypeIcon;

        u32 x = 210 + (10 * typeIndex);
        u32 y = 16 + (partyMonIndex * 22);
        u32 spriteId = CreateSprite(&TempSpriteTemplate, x, y, 0);
        gSprites[spriteId].oam.shape = SPRITE_SHAPE(16x16);
        gSprites[spriteId].oam.size = SPRITE_SIZE(16x16);
        gSprites[spriteId].oam.priority = 1;
        gSprites[spriteId].data[1] = partyMonIndex;
        gSprites[spriteId].data[0] = typeIndex;

        BXPY_SetSpriteId(spriteIndex,spriteId);
    }
}

static void BXPY_RefreshSelectedSprites(void)
{
    BXPY_RemoveSprite(BXPY_SPRITEID_PLAYER_SELECTED_0,BXPY_SPRITEID_PLAYER_SELECTED_5);

    for (u32 partyMonIndex = 0; partyMonIndex < NUM_BXPY_MAX_MONS_SHOWED; partyMonIndex++)
    {
        FreeSpriteTilesByTag(BXPY_SPRITETAG_SELECTED_0 + partyMonIndex);
        LoadSpriteSheet(&sBXPYSpriteSheets[BXPY_SPRITEID_PLAYER_SELECTED_0 + partyMonIndex].spriteSheet);
        BXPY_CreateSelectionSprite(partyMonIndex,B_SIDE_PLAYER);
        u32 spriteId = BXPY_GetSpriteId(BXPY_SPRITEID_PLAYER_SELECTED_0+partyMonIndex);
        BXPY_DrawOrderOnSelectionSprite(spriteId, BXPY_GetOrderForMon(partyMonIndex));
    }
}
