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
#include "recorded_battle.h"
#include "reshow_battle_screen.h"
#include "sound.h"
#include "task.h"
#include "test_runner.h"
#include "text.h"
#include "util.h"
#include "window.h"
#include "line_break.h"
#include "constants/battle_anim.h"
#include "constants/party_menu.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/rgb.h"

static void RecordedSafariHandleDrawTrainerPic(enum BattlerId battler);
static void RecordedSafariHandleChooseAction(enum BattlerId battler);
static void RecordedSafariHandleChooseItem(enum BattlerId battler);
static void RecordedSafariHandleFaintingCry(enum BattlerId battler);
static void RecordedSafariHandleIntroTrainerBallThrow(enum BattlerId battler);
static void RecordedSafariHandleEndLinkBattle(enum BattlerId battler);

static void RecordedSafariBufferRunCommand(enum BattlerId battler);
static void CompleteWhenChosePokeblock(enum BattlerId battler);

static void (*const sRecordedSafariBufferCommands[CONTROLLER_CMDS_COUNT])(enum BattlerId battler) =
{
    [CONTROLLER_GETMONDATA]               = BtlController_Empty,
    [CONTROLLER_GETRAWMONDATA]            = BtlController_Empty,
    [CONTROLLER_SETMONDATA]               = BtlController_Empty,
    [CONTROLLER_SETRAWMONDATA]            = BtlController_Empty,
    [CONTROLLER_LOADMONSPRITE]            = BtlController_Empty,
    [CONTROLLER_SWITCHINANIM]             = BtlController_Empty,
    [CONTROLLER_RETURNMONTOBALL]          = BtlController_Empty,
    [CONTROLLER_DRAWTRAINERPIC]           = RecordedSafariHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = BtlController_Empty,
    [CONTROLLER_TRAINERSLIDEBACK]         = BtlController_Empty,
    [CONTROLLER_FAINTANIMATION]           = BtlController_Empty,
    [CONTROLLER_PALETTEFADE]              = BtlController_Empty,
    [CONTROLLER_BALLTHROWANIM]            = BtlController_HandleBallThrowAnim,
    [CONTROLLER_PAUSE]                    = BtlController_Empty,
    [CONTROLLER_MOVEANIMATION]            = BtlController_Empty,
    [CONTROLLER_PRINTSTRING]              = BtlController_HandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = BtlController_HandlePrintStringPlayerOnly,
    [CONTROLLER_CHOOSEACTION]             = RecordedSafariHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = BtlController_Empty,
    [CONTROLLER_CHOOSEMOVE]               = BtlController_Empty,
    [CONTROLLER_OPENBAG]                  = RecordedSafariHandleChooseItem,
    [CONTROLLER_CHOOSEPOKEMON]            = BtlController_Empty,
    [CONTROLLER_23]                       = BtlController_Empty,
    [CONTROLLER_HEALTHBARUPDATE]          = BtlController_Empty,
    [CONTROLLER_EXPUPDATE]                = BtlController_Empty,
    [CONTROLLER_STATUSICONUPDATE]         = BtlController_HandleStatusIconUpdate,
    [CONTROLLER_STATUSANIMATION]          = BtlController_Empty,
    [CONTROLLER_STATUSXOR]                = BtlController_Empty,
    [CONTROLLER_DATATRANSFER]             = BtlController_Empty,
    [CONTROLLER_DMA3TRANSFER]             = BtlController_Empty,
    [CONTROLLER_PLAYBGM]                  = BtlController_Empty,
    [CONTROLLER_32]                       = BtlController_Empty,
    [CONTROLLER_TWORETURNVALUES]          = BtlController_Empty,
    [CONTROLLER_CHOSENMONRETURNVALUE]     = BtlController_Empty,
    [CONTROLLER_ONERETURNVALUE]           = BtlController_Empty,
    [CONTROLLER_ONERETURNVALUE_DUPLICATE] = BtlController_Empty,
    [CONTROLLER_HITANIMATION]             = BtlController_Empty,
    [CONTROLLER_CANTSWITCH]               = BtlController_Empty,
    [CONTROLLER_PLAYSE]                   = BtlController_HandlePlaySE,
    [CONTROLLER_PLAYFANFAREORBGM]         = BtlController_HandlePlayFanfareOrBGM,
    [CONTROLLER_FAINTINGCRY]              = RecordedSafariHandleFaintingCry,
    [CONTROLLER_INTROSLIDE]               = BtlController_HandleIntroSlide,
    [CONTROLLER_INTROTRAINERBALLTHROW]    = RecordedSafariHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = BtlController_Empty,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = BtlController_Empty,
    [CONTROLLER_ENDBOUNCE]                = BtlController_Empty,
    [CONTROLLER_SPRITEINVISIBILITY]       = BtlController_Empty,
    [CONTROLLER_BATTLEANIMATION]          = BtlController_HandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = BtlController_Empty,
    [CONTROLLER_RESETACTIONMOVESELECTION] = BtlController_Empty,
    [CONTROLLER_ENDLINKBATTLE]            = RecordedSafariHandleEndLinkBattle,
    [CONTROLLER_DEBUGMENU]                = BtlController_Empty,
    [CONTROLLER_TERMINATOR_NOP]           = BtlController_TerminatorNop
};

void SetControllerToRecordedSafari(enum BattlerId battler)
{
    gBattlerBattleController[battler] = BATTLE_CONTROLLER_RECORDED_SAFARI;
    gBattlerControllerEndFuncs[battler] = RecordedSafariBufferExecCompleted;
    gBattlerControllerFuncs[battler] = RecordedSafariBufferRunCommand;
}

static void RecordedSafariBufferRunCommand(enum BattlerId battler)
{
    if (IsBattleControllerActiveOnLocal(battler))
    {
        if (gBattleResources->bufferA[battler][0] < ARRAY_COUNT(sRecordedSafariBufferCommands))
            sRecordedSafariBufferCommands[gBattleResources->bufferA[battler][0]](battler);
        else
            BtlController_Complete(battler);
    }
}

static void Controller_WaitForHealthbox(enum BattlerId battler)
{
    if (gSprites[gHealthboxSpriteIds[battler]].callback == SpriteCallbackDummy)
        BtlController_Complete(battler);
}

static void RecordedSafariSetBattleEndCallbacks(enum BattlerId battler)
{
    if (!gPaletteFade.active)
    {
        gMain.inBattle = FALSE;
        gMain.callback1 = gPreBattleCallback1;
        SetMainCallback2(gMain.savedCallback);
    }
}

static void RecordedSafariOpenPokeblockCase(enum BattlerId battler)
{
        TestRunner_Battle_SelectPokeblock();
        gBattlerControllerFuncs[battler] = CompleteWhenChosePokeblock;
}

static void CompleteWhenChosePokeblock(enum BattlerId battler)
{
        BtlController_EmitOneReturnValue(battler, B_COMM_TO_ENGINE, gSpecialVar_ItemId);
        BtlController_Complete(battler);
}

void RecordedSafariBufferExecCompleted(enum BattlerId battler)
{
    gBattlerControllerFuncs[battler] = RecordedSafariBufferRunCommand;
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

static void RecordedSafariHandleDrawTrainerPic(enum BattlerId battler)
{
    enum TrainerPicID trainerPicId = TRAINER_PIC_BRENDAN;

    BtlController_HandleDrawTrainerPic(battler, trainerPicId, FALSE,
                                       80, (8 - GetTrainerBackPicCoords(trainerPicId)->size) * 4 + 80,
                                       30);
}

static void RecordedSafariHandleChooseAction(enum BattlerId battler)
{
    BtlController_EmitTwoReturnValues(battler, B_COMM_TO_ENGINE, RecordedBattle_GetBattlerAction(RECORDED_ACTION_TYPE, battler), 0);
    BtlController_Complete(battler);
}

static void RecordedSafariHandleChooseItem(enum BattlerId battler)
{
    gBattlerControllerFuncs[battler] = RecordedSafariOpenPokeblockCase;
    gBattlerInMenuId = battler;
}

// All of the other controllers(except Wally's) use CRY_MODE_FAINT.
// Player is not a pokemon, so it can't really faint in the RecordedSafari anyway.
static void RecordedSafariHandleFaintingCry(enum BattlerId battler)
{
    enum Species species = GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES);

    PlayCry_Normal(species, 25);
    BtlController_Complete(battler);
    BtlController_Complete(battler);
}

static void RecordedSafariHandleIntroTrainerBallThrow(enum BattlerId battler)
{
    UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], GetBattlerMon(battler), HEALTHBOX_SAFARI_ALL_TEXT);
    StartHealthboxSlideIn(battler);
    SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);
    gBattlerControllerFuncs[battler] = Controller_WaitForHealthbox;
}

static void RecordedSafariHandleEndLinkBattle(enum BattlerId battler)
{
    gBattleOutcome = gBattleResources->bufferA[battler][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    BtlController_Complete(battler);
    if ((gBattleTypeFlags & BATTLE_TYPE_LINK) && !(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER))
        gBattlerControllerFuncs[battler] = RecordedSafariSetBattleEndCallbacks;
}
