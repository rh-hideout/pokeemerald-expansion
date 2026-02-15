#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_message.h"
#include "bg.h"
#include "data.h"
#include "item_menu.h"
#include "link.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "party_menu.h"
#include "pokeball.h"
#include "pokeblock.h"
#include "pokemon.h"
#include "reshow_battle_screen.h"
#include "sound.h"
#include "task.h"
#include "text.h"
#include "util.h"
#include "window.h"
#include "line_break.h"
#include "constants/battle_anim.h"
#include "constants/party_menu.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/rgb.h"

static void BodyguardHandleDrawTrainerPic(u32 battler);
static void BodyguardHandleSuccessBallThrowAnim(u32 battler);
static void BodyguardHandleBallThrowAnim(u32 battler);
static void BodyguardHandleChooseAction(u32 battler);
static void BodyguardHandleChooseItem(u32 battler);
static void BodyguardHandleChoosePokemon(u32 battler);

static void BodyguardHandleIntroTrainerBallThrow(u32 battler);
static void BodyguardHandleEndLinkBattle(u32 battler);
static void BodyguardHandleLoadMonSprite(u32 battler);
static void BodyguardHandleTrainerSlide(u32 battler);
static void BodyguardHandleTrainerSlideBack(u32 battler);
static void BodyguardHandlePaletteFade(u32 battler);
static void BodyguardHandleDrawPartyStatusSummary(u32 battler);
static void BodyguardHandleTwoReturnValues(u32 battler);
static void BodyguardHandleOneReturnValue(u32 battler);
static void BodyguardHandleOneReturnValue_Duplicate(u32 battler);
static void BodyguardHandleEndBounceEffect(u32 battler);
static void BodyguardHandleCmd23(u32 battler);
static void BodyguardHandleDMA3Transfer(u32 battler);
static void BodyguardHandlePlayBGM(u32 battler);
static void BodyguardHandleStatusXor(u32 battler);
static void BodyguardHandlePause(u32 battler);

static void Intro_TryShinyAnimShowHealthbox(u32 battler);
static void Intro_WaitForShinyAnimAndHealthbox(u32 battler);


static void BodyguardBufferRunCommand(u32 battler);
static void CompleteWhenChosePokeblock(u32 battler);
static void WaitForMonSelection(u32 battler);
static void CompleteOnBattlerSpritePosX_0(u32 battler);

static void (*const sBodyguardBufferCommands[CONTROLLER_CMDS_COUNT])(u32 battler) =
{
    [CONTROLLER_GETMONDATA]               = BtlController_HandleGetMonData,
    [CONTROLLER_GETRAWMONDATA]            = BtlController_HandleGetRawMonData,
    [CONTROLLER_SETMONDATA]               = BtlController_HandleSetMonData,
    [CONTROLLER_SETRAWMONDATA]            = BtlController_HandleSetRawMonData,
    [CONTROLLER_LOADMONSPRITE]            = BodyguardHandleLoadMonSprite,
    [CONTROLLER_SWITCHINANIM]             = BtlController_HandleSwitchInAnim,
    [CONTROLLER_RETURNMONTOBALL]          = BtlController_HandleReturnMonToBall,
    [CONTROLLER_DRAWTRAINERPIC]           = BodyguardHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = BodyguardHandleTrainerSlide,
    [CONTROLLER_TRAINERSLIDEBACK]         = BodyguardHandleTrainerSlideBack,
    [CONTROLLER_FAINTANIMATION]           = BtlController_HandleFaintAnimation,
    [CONTROLLER_PALETTEFADE]              = BodyguardHandlePaletteFade,
    [CONTROLLER_SUCCESSBALLTHROWANIM]     = BodyguardHandleSuccessBallThrowAnim,
    [CONTROLLER_BALLTHROWANIM]            = BodyguardHandleBallThrowAnim,
    [CONTROLLER_PAUSE]                    = BodyguardHandlePause,
    [CONTROLLER_MOVEANIMATION]            = BtlController_HandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = BtlController_HandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = BtlController_HandlePrintStringPlayerOnly,
    [CONTROLLER_CHOOSEACTION]             = BodyguardHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = BtlController_Empty,
    [CONTROLLER_CHOOSEMOVE]               = BtlController_Empty,
    [CONTROLLER_OPENBAG]                  = BodyguardHandleChooseItem,
    [CONTROLLER_CHOOSEPOKEMON]            = BodyguardHandleChoosePokemon,
    [CONTROLLER_23]                       = BodyguardHandleCmd23,
    [CONTROLLER_HEALTHBARUPDATE]          = BtlController_HandleHealthBarUpdate,
    [CONTROLLER_EXPUPDATE]                = BtlController_Empty,
    [CONTROLLER_STATUSICONUPDATE]         = BtlController_HandleStatusIconUpdate,
    [CONTROLLER_STATUSANIMATION]          = BtlController_HandleStatusAnimation,
    [CONTROLLER_STATUSXOR]                = BodyguardHandleStatusXor,
    [CONTROLLER_DATATRANSFER]             = BtlController_Empty,
    [CONTROLLER_DMA3TRANSFER]             = BodyguardHandleDMA3Transfer,
    [CONTROLLER_PLAYBGM]                  = BodyguardHandlePlayBGM,
    [CONTROLLER_32]                       = BtlController_Empty,
    [CONTROLLER_TWORETURNVALUES]          = BodyguardHandleTwoReturnValues,
    [CONTROLLER_CHOSENMONRETURNVALUE]     = BtlController_Empty,
    [CONTROLLER_ONERETURNVALUE]           = BodyguardHandleOneReturnValue,
    [CONTROLLER_ONERETURNVALUE_DUPLICATE] = BodyguardHandleOneReturnValue_Duplicate,
    [CONTROLLER_HITANIMATION]             = BtlController_HandleHitAnimation,
    [CONTROLLER_CANTSWITCH]               = BtlController_Empty,
    [CONTROLLER_PLAYSE]                   = BtlController_HandlePlaySE,
    [CONTROLLER_PLAYFANFAREORBGM]         = BtlController_HandlePlayFanfareOrBGM,
    [CONTROLLER_FAINTINGCRY]              = BtlController_HandleFaintingCry,
    [CONTROLLER_INTROSLIDE]               = BtlController_HandleIntroSlide,
    [CONTROLLER_INTROTRAINERBALLTHROW]    = BodyguardHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = BodyguardHandleDrawPartyStatusSummary,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = BtlController_HandleHidePartyStatusSummary,
    [CONTROLLER_ENDBOUNCE]                = BodyguardHandleEndBounceEffect,
    [CONTROLLER_SPRITEINVISIBILITY]       = BtlController_HandleSpriteInvisibility,
    [CONTROLLER_BATTLEANIMATION]          = BtlController_HandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = BtlController_Empty,
    [CONTROLLER_RESETACTIONMOVESELECTION] = BtlController_Empty,
    [CONTROLLER_ENDLINKBATTLE]            = BodyguardHandleEndLinkBattle,
    [CONTROLLER_DEBUGMENU]                = BtlController_Empty,

    [CONTROLLER_TERMINATOR_NOP]           = BtlController_TerminatorNop
};

void SetControllerToBodyguard(u32 battler)
{
    gBattlerControllerEndFuncs[battler] = BodyguardBufferExecCompleted;
    gBattlerControllerFuncs[battler] = BodyguardBufferRunCommand;
}

static void BodyguardBufferRunCommand(u32 battler)
{
    if (IsBattleControllerActiveOnLocal(battler))
    {
        if (gBattleResources->bufferA[battler][0] < ARRAY_COUNT(sBodyguardBufferCommands))
            sBodyguardBufferCommands[gBattleResources->bufferA[battler][0]](battler);
        else
            BtlController_Complete(battler);
    }
}

static void HandleInputChooseAction(u32 battler)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);

        switch (gActionSelectionCursor[battler])
        {
        case 0:
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_BODYGUARD_BALL, 0);
            break;
        case 1:
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_BODYGUARD_POKEBLOCK, 0);
            break;
        case 2:
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_BODYGUARD_GO_NEAR, 0);
            break;
        case 3:
            BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_BODYGUARD_RUN, 0);
            break;
        }
        BtlController_Complete(battler);
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (gActionSelectionCursor[battler] & 1)
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 1;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        if (!(gActionSelectionCursor[battler] & 1))
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 1;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gActionSelectionCursor[battler] & 2)
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 2;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (!(gActionSelectionCursor[battler] & 2))
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
            gActionSelectionCursor[battler] ^= 2;
            ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
        }
    }
    else if (B_QUICK_MOVE_CURSOR_TO_RUN && JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        ActionSelectionDestroyCursorAt(gActionSelectionCursor[battler]);
        gActionSelectionCursor[battler] = 3;
        ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
    }
}








static void CompleteWhenChosePokeblock(u32 battler)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        BtlController_EmitOneReturnValue(battler, B_COMM_TO_ENGINE, gSpecialVar_ItemId);
        BtlController_Complete(battler);
    }
}

static void BodyguardOpenPokeblockCase(u32 battler)
{
    if (!gPaletteFade.active)
    {
        gBattlerControllerFuncs[battler] = CompleteWhenChosePokeblock;
        FreeAllWindowBuffers();
        OpenPokeblockCaseInBattle();
    }
}

static void WaitForMonSelection(u32 battler)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        if (gPartyMenuUseExitCallback == TRUE)
            BtlController_EmitChosenMonReturnValue(battler, B_COMM_TO_ENGINE, gSelectedMonPartyId, gBattlePartyCurrentOrder);
        else
            BtlController_EmitChosenMonReturnValue(battler, B_COMM_TO_ENGINE, PARTY_SIZE, NULL);

        if ((gBattleResources->bufferA[battler][1] & 0xF) == 1)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_LINK)
            {
                gBattle_BG0_X = 0;
                gBattle_BG0_Y = 0;
                BattlePutTextOnWindow(gText_LinkStandby, B_WIN_MSG);
            }
        }

        BodyguardBufferExecCompleted(battler);
    }
}

static void OpenPartyMenuToChooseMon(u32 battler)
{
    if (!gPaletteFade.active)
    {
        gBattlerControllerFuncs[battler] = WaitForMonSelection;
        u8 caseId = gTasks[gBattleControllerData[battler]].data[0];
        DestroyTask(gBattleControllerData[battler]);
        FreeAllWindowBuffers();
        OpenPartyMenuInBattle(caseId);
    }
}

void BodyguardBufferExecCompleted(u32 battler)
{
    gBattlerControllerFuncs[battler] = BodyguardBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(battler, B_COMM_CONTROLLER_IS_DONE, 4, &playerId);
        gBattleResources->bufferA[battler][0] = CONTROLLER_TERMINATOR_NOP;
    }
    else
    {
        MarkBattleControllerIdleOnLocal(battler);
    }
}

static void CompleteOnBattlerSpritePosX_0(u32 battler)
{
    if (gSprites[gBattlerSpriteIds[battler]].x2 == 0)
        BtlController_Complete(battler);
}

static void BodyguardHandleCmd23(u32 battler)
{
    BtlController_Complete(battler);
}

static void BodyguardHandleLoadMonSprite(u32 battler)
{
    BattleLoadMonSpriteGfx(GetBattlerMon(battler), battler);
    gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
    gBattlerControllerFuncs[battler] = CompleteOnBattlerSpritePosX_0;
}

static u32 BodyguardGetTrainerBackPicId(void)
{
    u32 trainerPicId;

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        trainerPicId = LinkPlayerGetTrainerPicId(GetMultiplayerId());
    else
        trainerPicId = gSaveBlock2Ptr->playerGender + TRAINER_BACK_PIC_BRENDAN;

    return trainerPicId;
}

static void BodyguardHandleDrawTrainerPic(u32 battler)
{
    u32 trainerPicId = BodyguardGetTrainerBackPicId();
    BtlController_HandleDrawTrainerPic(battler, trainerPicId, FALSE,
                                       80, 80 + 4 * (8 - gTrainerBacksprites[trainerPicId].coordinates.size),
                                       30);
}

static void BodyguardHandleTrainerSlide(u32 battler)
{
    u32 trainerPicId = BodyguardGetTrainerBackPicId();
    BtlController_HandleTrainerSlide(battler, trainerPicId);
}

static void BodyguardHandleTrainerSlideBack(u32 battler)
{
    // In Bodyguard battles, we want the trainer to stay on screen
    // So we skip the slide back animation
    BtlController_Complete(battler);
}

static void BodyguardHandlePaletteFade(u32 battler)
{
    BeginNormalPaletteFade(PALETTES_ALL, 2, 0, 16, RGB_BLACK);
    BtlController_Complete(battler);
}

static void BodyguardHandleSuccessBallThrowAnim(u32 battler)
{
    BtlController_HandleSuccessBallThrowAnim(battler, gBattlerTarget, B_ANIM_BALL_THROW, TRUE);
}

static void BodyguardHandleBallThrowAnim(u32 battler)
{
    BtlController_HandleBallThrowAnim(battler, gBattlerTarget, B_ANIM_BALL_THROW, TRUE);
}

static void BodyguardHandlePause(u32 battler)
{
    u8 timer = gBattleResources->bufferA[battler][1];

    while (timer != 0)
        timer--;

    BtlController_Complete(battler);
}

static void HandleChooseActionAfterDma3(u32 battler)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = DISPLAY_HEIGHT;
        gBattlerControllerFuncs[battler] = HandleInputChooseAction;
    }
}

static void BodyguardHandleChooseAction(u32 battler)
{
    s32 i;

    gBattlerControllerFuncs[battler] = HandleChooseActionAfterDma3;
    // Use SafariZoneMenu (Ball, Rock, Bait, Run) in the Action Menu window (Right side)
    BattlePutTextOnWindow(gText_SafariZoneMenu, B_WIN_ACTION_MENU);

    for (i = 0; i < 4; i++)
        ActionSelectionDestroyCursorAt(i);

    ActionSelectionCreateCursorAt(gActionSelectionCursor[battler], 0);
    
    // Display standard prompt in the Prompt window (Left side)
    BattleStringExpandPlaceholdersToDisplayedString(gText_WhatWillPkmnDo2);
    BattlePutTextOnWindow(gDisplayedStringBattle, B_WIN_ACTION_PROMPT);
}

static void BodyguardHandleChooseItem(u32 battler)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gBattlerControllerFuncs[battler] = BodyguardOpenPokeblockCase;
    gBattlerInMenuId = battler;
}

static void BodyguardHandleChoosePokemon(u32 battler)
{
    for (s32 i = 0; i < ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        gBattlePartyCurrentOrder[i] = gBattleResources->bufferA[battler][4 + i];

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA && (gBattleResources->bufferA[battler][1] & 0xF) != PARTY_ACTION_CANT_SWITCH
        && (gBattleResources->bufferA[battler][1] & 0xF) != PARTY_ACTION_CHOOSE_FAINTED_MON
        && (gBattleResources->bufferA[battler][1] & 0xF) != PARTY_ACTION_SEND_MON_TO_BOX)
    {
        BtlController_EmitChosenMonReturnValue(battler, B_COMM_TO_ENGINE, gBattlerPartyIndexes[battler] + 1, gBattlePartyCurrentOrder);
        BodyguardBufferExecCompleted(battler);
    }
    else
    {
        gBattleControllerData[battler] = CreateTask(TaskDummy, 0xFF);
        gTasks[gBattleControllerData[battler]].data[0] = gBattleResources->bufferA[battler][1] & 0xF;
        *(&gBattleStruct->battlerPreventingSwitchout) = gBattleResources->bufferA[battler][1] >> 4;
        *(&gBattleStruct->prevSelectedPartySlot) = gBattleResources->bufferA[battler][2];
        *(&gBattleStruct->abilityPreventingSwitchout) = (gBattleResources->bufferA[battler][3] & 0xFF) | (gBattleResources->bufferA[battler][7] << 8);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        gBattlerControllerFuncs[battler] = OpenPartyMenuToChooseMon;
        gBattlerInMenuId = battler;
    }
}

static void BodyguardHandleTwoReturnValues(u32 battler)
{
    BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, B_ACTION_USE_MOVE, 0);
    BtlController_Complete(battler);
}

static void BodyguardHandleOneReturnValue(u32 battler)
{
    BtlController_EmitOneReturnValue(battler, B_COMM_TO_ENGINE, 0);
    BtlController_Complete(battler);
}

static void BodyguardHandleOneReturnValue_Duplicate(u32 battler)
{
    BtlController_EmitOneReturnValue_Duplicate(battler, B_COMM_TO_ENGINE, 0);
    BtlController_Complete(battler);
}

static void BodyguardHandleEndBounceEffect(u32 battler)
{
    EndBounceEffect(battler, BOUNCE_HEALTHBOX);
    EndBounceEffect(battler, BOUNCE_MON);
    BtlController_Complete(battler);
}

static void BodyguardHandleStatusXor(u32 battler)
{
    u32 val = GetMonData(GetBattlerMon(battler), MON_DATA_STATUS) ^ gBattleResources->bufferA[battler][1];

    SetMonData(GetBattlerMon(battler), MON_DATA_STATUS, &val);
    BtlController_Complete(battler);
}

static void BodyguardHandleDMA3Transfer(u32 battler)
{
    u32 dstArg = gBattleResources->bufferA[battler][1]
            | (gBattleResources->bufferA[battler][2] << 8)
            | (gBattleResources->bufferA[battler][3] << 16)
            | (gBattleResources->bufferA[battler][4] << 24);
    u16 sizeArg = gBattleResources->bufferA[battler][5] | (gBattleResources->bufferA[battler][6] << 8);

    const u8 *src = &gBattleResources->bufferA[battler][7];
    u8 *dst = (u8 *)(dstArg);
    u32 size = sizeArg;

    while (1)
    {
        if (size <= 0x1000)
        {
            DmaCopy16(3, src, dst, size);
            break;
        }
        DmaCopy16(3, src, dst, 0x1000);
        src += 0x1000;
        dst += 0x1000;
        size -= 0x1000;
    }
    BtlController_Complete(battler);
}

static void BodyguardHandlePlayBGM(u32 battler)
{
    PlayBGM(gBattleResources->bufferA[battler][1] | (gBattleResources->bufferA[battler][2] << 8));
    BtlController_Complete(battler);
}

static void BodyguardHandleEndLinkBattle(u32 battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK && !(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER))
    {
        gMain.inBattle = FALSE;
        gMain.callback1 = gPreBattleCallback1;
        SetMainCallback2(gMain.savedCallback);
    }
    BtlController_Complete(battler);
}

static void Intro_WaitForShinyAnimAndHealthbox(u32 battler)
{
    bool8 healthboxAnimDone = FALSE;

    // Check if healthbox has finished sliding in
    if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy)
        healthboxAnimDone = TRUE;

    // If healthbox and shiny anim are done
    if (healthboxAnimDone && gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim)
    {
        // Reset shiny anim (even if it didn't occur)
        gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;
        FreeShinyStars();

        HandleLowHpMusicChange(GetBattlerMon(battler), battler);

        gBattleSpritesDataPtr->healthBoxesData[battler].introEndDelay = 3;
        gBattlerControllerFuncs[battler] = BtlController_Intro_DelayAndEnd;

        // In Bodyguard battles, keep the trainer sprite
        if (gBattleTypeFlags & BATTLE_TYPE_BODYGUARD)
        {
            // Move trainer to the left (adjust X coordinate)
            // Default active battle X depends on `BodyguardHandleDrawTrainerPic`.
            // We want it to the left of the Pokemon.
            gSprites[gBattleControllerData[battler]].x -= 32; 
        }
        else
        {
            DestroySprite(&gSprites[gBattleControllerData[battler]]);
        }
    }
}

static void Intro_TryShinyAnimShowHealthbox(u32 battler)
{
    bool32 bgmRestored = FALSE;
    bool32 battlerAnimsDone = FALSE;

    // Start shiny animation if applicable for 1st Pokémon
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim
     && !gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
        TryShinyAnimation(battler, GetBattlerMon(battler));

    // Show healthbox after ball anim
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted)
        {
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], GetBattlerMon(battler), HEALTHBOX_ALL);
            StartHealthboxSlideIn(battler);
            SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);
        }
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted = TRUE;
    }

    // Restore bgm after cry has played and healthbox anim is started
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].waitForCry
        && gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted
        && !IsCryPlayingOrClearCrySongs())
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored)
        {
             m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
        }
        gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored = TRUE;
        bgmRestored = TRUE;
    }

    // Wait for battler anims
    if (gSprites[gBattleControllerData[battler]].callback == SpriteCallbackDummy
        && gSprites[gBattlerSpriteIds[battler]].callback == SpriteCallbackDummy)
    {
        battlerAnimsDone = TRUE;
    }

    // Clean up
    if (bgmRestored && battlerAnimsDone)
    {
        DestroySprite(&gSprites[gBattleControllerData[battler]]);

        gBattleSpritesDataPtr->animationData->introAnimActive = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].bgmRestored = FALSE;
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxSlideInStarted = FALSE;

        gBattlerControllerFuncs[battler] = Intro_WaitForShinyAnimAndHealthbox;
    }
}

static void BodyguardHandleIntroTrainerBallThrow(u32 battler)
{
    const u32 paletteIndex = BodyguardGetTrainerBackPicId();
    const u16 *trainerPal = gTrainerBacksprites[paletteIndex].palette.data;
    BtlController_HandleIntroTrainerBallThrow(battler, 0xD6F8, trainerPal, 31, Intro_TryShinyAnimShowHealthbox);
}

static void BodyguardHandleDrawPartyStatusSummary(u32 battler)
{
    BtlController_HandleDrawPartyStatusSummary(battler, B_SIDE_PLAYER, TRUE);
}


