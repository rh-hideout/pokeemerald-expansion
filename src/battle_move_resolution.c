#include "global.h"
#include "battle.h"
#include "battle_environment.h"
#include "battle_hold_effects.h"
#include "battle_ai_record.h"
#include "battle_util.h"
#include "battle_move_resolution.h"
#include "battle_scripts.h"
#include "battle_z_move.h"
#include "item.h"
#include "battle_controllers.h"
#include "move.h"
#include "constants/battle_move_resolution.h"

static void ValidateBattlers(void);
static enum Move GetOriginallyUsedMove(enum Move chosenMove);
static void SetSameMoveTurnValues(enum BattleMoveEffects moveEffect);
static void TryClearChargeVolatile(enum Type moveType);
static inline bool32 IsBattlerUsingBeakBlast(enum BattlerId battler);
static void RequestNonVolatileChange(enum BattlerId battlerAtk);
static bool32 CanBattlerBounceBackMove(struct BattleCalcValues *cv);
static bool32 TryMagicBounce(struct BattleCalcValues *cv);
static bool32 TryMagicCoat(struct BattleCalcValues *cv);
static bool32 TryActivatePowderStatus(enum Move move);
static void CalculateMagnitudeDamage(void);
static void UpdateStallMons(void);

// Submoves
static enum Move GetMirrorMoveMove(void);
static enum Move GetMetronomeMove(void);
static enum Move GetAssistMove(void);
static enum Move GetSleepTalkMove(void);
static enum Move GetCopycatMove(void);
static enum Move GetMeFirstMove(void);

// ==============
// Attackcanceler
// ==============

static enum CancelerResult CancelerClearFlags(struct BattleCalcValues *cv)
{
    gBattleMons[cv->battlerAtk].volatiles.grudge = FALSE;
    gBattleMons[cv->battlerAtk].volatiles.glaiveRush = FALSE;
    gBattleStruct->eventState.atkCancelerBattler = 0;
    return CANCELER_RESULT_SUCCESS;
}

static bool32 TryFormChangeBeforeMove(void)
{
    enum Ability ability = GetBattlerAbility(gBattlerAttacker);

    if (TryBattleFormChange(gBattlerAttacker, FORM_CHANGE_BATTLE_BEFORE_MOVE, ability)
        || TryBattleFormChange(gBattlerAttacker, FORM_CHANGE_BATTLE_BEFORE_MOVE_CATEGORY, ability))
    {
        gBattleScripting.battler = gBattlerAttacker;
        BattleScriptCall(BattleScript_BattlerFormChange);
        return TRUE;
    }
    return FALSE;
}

static enum CancelerResult CancelerStanceChangeOne(struct BattleCalcValues *cv)
{
    if (B_STANCE_CHANGE_FAIL < GEN_7 && gChosenMove == cv->move && TryFormChangeBeforeMove())
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerSkyDrop(struct BattleCalcValues *cv)
{
    // If Pokemon is being held in Sky Drop
    if (gBattleMons[cv->battlerAtk].volatiles.semiInvulnerable == STATE_SKY_DROP_TARGET)
    {
        gBattlescriptCurrInstr = BattleScript_MoveEnd;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerRecharge(struct BattleCalcValues *cv)
{
    if (gBattleMons[cv->battlerAtk].volatiles.rechargeTimer > 0)
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_MoveUsedMustRecharge;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerChillyReception(struct BattleCalcValues *cv)
{
    if (GetMoveEffect(cv->move) == EFFECT_WEATHER_AND_SWITCH)
    {
        BattleScriptCall(BattleScript_ChillyReceptionMessage);
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    }
    return CANCELER_RESULT_SUCCESS;
}

static void DefrostBattler(enum BattlerId battler, u32 status)
{
    gBattleScripting.battler = battler;
    gBattleMons[battler].status1 &= ~status;
    RequestNonVolatileChange(battler);
}

static enum CancelerResult CancelerAsleepOrFrozen(struct BattleCalcValues *cv)
{
    enum CancelerResult result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;

    if (gBattleMons[cv->battlerAtk].status1 & STATUS1_SLEEP)
    {
        if (GetConfig(B_UPROAR) < GEN_5 && UproarWakeUpCheck(cv->battlerAtk))
        {
            TryDeactivateSleepClause(GetBattlerSide(cv->battlerAtk), gBattlerPartyIndexes[cv->battlerAtk]);
            gBattleMons[cv->battlerAtk].status1 &= ~STATUS1_SLEEP;
            gBattleMons[cv->battlerAtk].volatiles.nightmare = FALSE;
            gEffectBattler = cv->battlerAtk;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WOKE_UP_UPROAR;
            result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
            BattleScriptCall(BattleScript_MoveUsedWokeUp);
        }
        else
        {
            u32 toSub;
            if (IsAbilityAndRecord(cv->battlerAtk, cv->abilities[cv->battlerAtk], ABILITY_EARLY_BIRD))
                toSub = 2;
            else
                toSub = 1;

            if ((gBattleMons[cv->battlerAtk].status1 & STATUS1_SLEEP) < toSub)
                gBattleMons[cv->battlerAtk].status1 &= ~STATUS1_SLEEP;
            else
                gBattleMons[cv->battlerAtk].status1 -= toSub;

            if (gBattleMons[cv->battlerAtk].status1 & STATUS1_SLEEP)
            {
                enum BattleMoveEffects moveEffect = GetMoveEffect(cv->move);
                if (moveEffect == EFFECT_SNORE)
                {
                    BattleScriptCall(BattleScript_BeforeSnoreMessage);
                    result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
                }
                else if (moveEffect == EFFECT_SLEEP_TALK)
                {
                    result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
                }
                else
                {
                    gBattlescriptCurrInstr = BattleScript_MoveUsedIsAsleep;
                    result = CANCELER_RESULT_FAILURE;
                }
            }
            else
            {
                TryDeactivateSleepClause(GetBattlerSide(cv->battlerAtk), gBattlerPartyIndexes[cv->battlerAtk]);
                gBattleMons[cv->battlerAtk].volatiles.nightmare = FALSE;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WOKE_UP;
                result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
                BattleScriptCall(BattleScript_MoveUsedWokeUp);
            }
        }
        RequestNonVolatileChange(cv->battlerAtk);
    }
    else if (gBattleMons[cv->battlerAtk].status1 & STATUS1_FREEZE && !MoveThawsUser(cv->move))
    {
        if (!RandomPercentage(RNG_FROZEN, 20))
        {
            result = CANCELER_RESULT_FAILURE;
            gBattlescriptCurrInstr = BattleScript_MoveUsedIsFrozen;
        }
        else // unfreeze
        {
            DefrostBattler(cv->battlerAtk, STATUS1_FREEZE);
            result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
            BattleScriptCall(BattleScript_BattlerDefrosted);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DEFROSTED;
        }
    }

    return result;
}

static enum CancelerResult CancelerObedience(struct BattleCalcValues *cv)
{
    if (!gBattleMons[cv->battlerAtk].volatiles.multipleTurns)
    {
        enum Obedience obedienceResult = GetAttackerObedienceForAction();
        switch (obedienceResult)
        {
        case OBEYS:
            return CANCELER_RESULT_SUCCESS;
        case DISOBEYS_LOAFS:
            // Randomly select, then print a disobedient string
            // B_MSG_LOAFING, B_MSG_WONT_OBEY, B_MSG_TURNED_AWAY, or B_MSG_PRETEND_NOT_NOTICE
            gBattleCommunication[MULTISTRING_CHOOSER] = MOD(Random(), NUM_LOAF_STRINGS);
            gBattlescriptCurrInstr = BattleScript_MoveUsedLoafingAround;
            gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_MISSED;
            return CANCELER_RESULT_FAILURE;
        case DISOBEYS_HITS_SELF:
            gBattlerTarget = cv->battlerAtk;
            struct DamageContext dmgCtx = {0};
            dmgCtx.battlerAtk = dmgCtx.battlerDef = cv->battlerAtk;
            dmgCtx.move = dmgCtx.chosenMove = MOVE_NONE;
            dmgCtx.moveType = TYPE_MYSTERY;
            dmgCtx.isCrit = FALSE;
            dmgCtx.randomFactor = FALSE;
            dmgCtx.updateFlags = TRUE;
            dmgCtx.isSelfInflicted = TRUE;
            dmgCtx.fixedBasePower = 40;
            gBattleStruct->moveDamage[cv->battlerAtk] = CalculateMoveDamage(&dmgCtx);
            gBattlescriptCurrInstr = BattleScript_IgnoresAndHitsItself;
            return CANCELER_RESULT_FAILURE; // Move doesn't fail but mon hits itself
        case DISOBEYS_FALL_ASLEEP:
            if (IsSleepClauseEnabled())
                gBattleStruct->battlerState[cv->battlerAtk].sleepClauseEffectExempt = TRUE;
            gBattlescriptCurrInstr = BattleScript_IgnoresAndFallsAsleep;
            gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_MISSED;
            return CANCELER_RESULT_FAILURE;
            break;
        case DISOBEYS_WHILE_ASLEEP:
            gBattlescriptCurrInstr = BattleScript_IgnoresWhileAsleep;
            gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_MISSED;
            return CANCELER_RESULT_FAILURE;
        case DISOBEYS_RANDOM_MOVE:
            gCurrentMove = gCalledMove = gBattleMons[cv->battlerAtk].moves[gCurrMovePos];
            BattleScriptCall(BattleScript_IgnoresAndUsesRandomMove);
            gBattlerTarget = GetBattleMoveTarget(gCalledMove, TARGET_NONE);
            return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
        }
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerPowerPoints(struct BattleCalcValues *cv)
{
    if (gBattleMons[cv->battlerAtk].pp[gCurrMovePos] == 0
     && cv->move != MOVE_STRUGGLE
     && !gSpecialStatuses[cv->battlerAtk].dancerUsedMove
     && !gBattleMons[cv->battlerAtk].volatiles.multipleTurns)
    {
        gBattlescriptCurrInstr = BattleScript_NoPPForMove;
        gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_MISSED;
        return CANCELER_RESULT_FAILURE;
    }

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerTruant(struct BattleCalcValues *cv)
{
    if (GetBattlerAbility(cv->battlerAtk) == ABILITY_TRUANT && gBattleMons[cv->battlerAtk].volatiles.truantCounter)
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_LOAFING;
        gBattlerAbility = cv->battlerAtk;
        gBattlescriptCurrInstr = BattleScript_TruantLoafingAround;
        gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_MISSED;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerFocus(struct BattleCalcValues *cv)
{
    u32 focusPunchFailureConfig = GetConfig(B_FOCUS_PUNCH_FAILURE);

    // In Gens 3-4, only check if is using Focus Punch.
    // In Gens 5-6, only check if the chosen move is Focus Punch.
    // In Gens 7+, check if chose and is using Focus Punch.
    if ((gProtectStructs[cv->battlerAtk].physicalDmg || gProtectStructs[cv->battlerAtk].specialDmg)
     && (focusPunchFailureConfig < GEN_5 || GetMoveEffect(gChosenMoveByBattler[cv->battlerAtk]) == EFFECT_FOCUS_PUNCH)
     && (focusPunchFailureConfig == GEN_5 || focusPunchFailureConfig == GEN_6 || GetMoveEffect(cv->move) == EFFECT_FOCUS_PUNCH)
     && !gProtectStructs[cv->battlerAtk].survivedOHKO)
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_FocusPunchLostFocus;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerFocusGen5(struct BattleCalcValues *cv)
{
    if (GetConfig(B_FOCUS_PUNCH_FAILURE) >= GEN_5)
        return CancelerFocus(cv);
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerFlinch(struct BattleCalcValues *cv)
{
    if (gBattleMons[cv->battlerAtk].volatiles.flinched)
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_MoveUsedFlinched;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerDisabled(struct BattleCalcValues *cv)
{
    if (GetActiveGimmick(cv->battlerAtk) != GIMMICK_Z_MOVE
     && gBattleMons[cv->battlerAtk].volatiles.disabledMove == cv->move
     && gBattleMons[cv->battlerAtk].volatiles.disabledMove != MOVE_NONE)
    {
        gBattleScripting.battler = cv->battlerAtk;
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_MoveUsedIsDisabled;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerVolatileBlocked(struct BattleCalcValues *cv)
{
    enum CancelerResult result = CANCELER_RESULT_SUCCESS;

    if (GetActiveGimmick(cv->battlerAtk) != GIMMICK_Z_MOVE
     && gBattleMons[cv->battlerAtk].volatiles.healBlock
     && IsHealBlockPreventingMove(cv->battlerAtk, cv->move))
    {
        gBattleScripting.battler = cv->battlerAtk;
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_MoveUsedHealBlockPrevents;
        result = CANCELER_RESULT_FAILURE;
    }
    else if (gFieldStatuses & STATUS_FIELD_GRAVITY && IsGravityPreventingMove(cv->move))
    {
        gBattleScripting.battler = cv->battlerAtk;
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_MoveUsedGravityPrevents;
        result = CANCELER_RESULT_FAILURE;
    }
    else if (GetActiveGimmick(cv->battlerAtk) != GIMMICK_Z_MOVE && gBattleMons[cv->battlerAtk].volatiles.throatChopTimer > 0 && IsSoundMove(cv->move))
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_MoveUsedIsThroatChopPrevented;
        result = CANCELER_RESULT_FAILURE;
    }

    if (gBattleStruct->snatchedMoveIsUsed)
        gBattleStruct->eventState.atkCanceler = CANCELER_SNATCH - 1; // -1 for gen4- behavior since state is incremented on success

    return result;
}

static enum CancelerResult CancelerTaunted(struct BattleCalcValues *cv)
{
    if (GetActiveGimmick(cv->battlerAtk) != GIMMICK_Z_MOVE
     && gBattleMons[cv->battlerAtk].volatiles.tauntTimer
     && IsBattleMoveStatus(cv->move)
     && (GetConfig(B_TAUNT_ME_FIRST) < GEN_5 || GetMoveEffect(cv->move) != EFFECT_ME_FIRST))
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_MoveUsedIsTaunted;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerImprisoned(struct BattleCalcValues *cv)
{
    if (GetActiveGimmick(cv->battlerAtk) != GIMMICK_Z_MOVE && GetImprisonedMovesCount(cv->battlerAtk, cv->move))
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_MoveUsedIsImprisoned;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerConfused(struct BattleCalcValues *cv)
{
    if (gBattleMons[cv->battlerAtk].volatiles.confusionTurns)
    {
        if (!gBattleMons[cv->battlerAtk].volatiles.infiniteConfusion)
            gBattleMons[cv->battlerAtk].volatiles.confusionTurns--;
        if (gBattleMons[cv->battlerAtk].volatiles.confusionTurns)
        {
             // confusion dmg
            if (RandomPercentage(RNG_CONFUSION, (GetConfig(B_CONFUSION_SELF_DMG_CHANCE) >= GEN_7 ? 33 : 50)))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = TRUE;
                gBattlerTarget = gBattlerAttacker;
                struct DamageContext dmgCtx = {0};
                dmgCtx.battlerAtk = dmgCtx.battlerDef = cv->battlerAtk;
                dmgCtx.move = dmgCtx.chosenMove = MOVE_NONE;
                dmgCtx.moveType = TYPE_MYSTERY;
                dmgCtx.isCrit = FALSE;
                dmgCtx.randomFactor = FALSE;
                dmgCtx.updateFlags = TRUE;
                dmgCtx.isSelfInflicted = TRUE;
                dmgCtx.fixedBasePower = 40;
                dmgCtx.abilities[gBattlerAttacker] = cv->abilities[gBattlerAttacker];
                dmgCtx.holdEffects[gBattlerAttacker] = cv->holdEffects[gBattlerAttacker];
                gBattleStruct->passiveHpUpdate[cv->battlerAtk] = CalculateMoveDamage(&dmgCtx);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsConfused;
                return CANCELER_RESULT_FAILURE;
            }
            else
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = FALSE;
                BattleScriptCall(BattleScript_MoveUsedIsConfused);
                return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
            }
        }
        else // snapped out of confusion
        {
            BattleScriptCall(BattleScript_MoveUsedIsConfusedNoMore);
            return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
        }
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerGhost(struct BattleCalcValues *cv) // GHOST in Pokémon Tower
{
    if (IsGhostBattleWithoutScope())
    {
        if (GetBattlerSide(cv->battlerAtk) == B_SIDE_PLAYER)
            gBattlescriptCurrInstr = BattleScript_TooScaredToMove;
        else
            gBattlescriptCurrInstr = BattleScript_GhostGetOutGetOut;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerParalyzed(struct BattleCalcValues *cv)
{
    if (gBattleMons[cv->battlerAtk].status1 & STATUS1_PARALYSIS
        && !(B_MAGIC_GUARD == GEN_4 && IsAbilityAndRecord(cv->battlerAtk, cv->abilities[cv->battlerAtk], ABILITY_MAGIC_GUARD))
        && !RandomPercentage(RNG_PARALYSIS, 75))
    {
        CancelMultiTurnMoves(gBattlerAttacker);
        gBattlescriptCurrInstr = BattleScript_MoveUsedIsParalyzed;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerInfatuation(struct BattleCalcValues *cv)
{
    if (gBattleMons[cv->battlerAtk].volatiles.infatuation)
    {
        gBattleScripting.battler = gBattleMons[cv->battlerAtk].volatiles.infatuation - 1;
        if (!RandomPercentage(RNG_INFATUATION, 50))
        {
            BattleScriptCall(BattleScript_MoveUsedIsInLove);
            return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
        }
        else
        {
            BattleScriptPush(BattleScript_MoveUsedIsInLoveCantAttack);
            CancelMultiTurnMoves(cv->battlerAtk);
            gBattlescriptCurrInstr = BattleScript_MoveUsedIsInLove;
            return CANCELER_RESULT_FAILURE;
        }
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerZMoves(struct BattleCalcValues *cv)
{
    if (GetActiveGimmick(cv->battlerAtk) == GIMMICK_Z_MOVE)
    {
        // attacker has a queued z move
        RecordItemEffectBattle(cv->battlerAtk, HOLD_EFFECT_Z_CRYSTAL);
        SetGimmickAsActivated(cv->battlerAtk, GIMMICK_Z_MOVE);

        gBattleScripting.battler = cv->battlerAtk;
        if (GetMoveCategory(cv->move) == DAMAGE_CATEGORY_STATUS)
            BattleScriptCall(BattleScript_ZMoveActivateStatus);
        else
            BattleScriptCall(BattleScript_ZMoveActivateDamaging);

        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerChoiceLock(struct BattleCalcValues *cv)
{
    enum Move *choicedMoveAtk = &gBattleStruct->choicedMove[cv->battlerAtk];
    enum HoldEffect holdEffect = GetBattlerHoldEffect(cv->battlerAtk);

    if (gChosenMove != MOVE_STRUGGLE
     && (*choicedMoveAtk == MOVE_NONE || *choicedMoveAtk == MOVE_UNAVAILABLE)
     && (IsHoldEffectChoice(holdEffect) || cv->abilities[cv->battlerAtk] == ABILITY_GORILLA_TACTICS))
        *choicedMoveAtk = gChosenMove;

    u32 moveIndex;
    for (moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (gBattleMons[cv->battlerAtk].moves[moveIndex] == *choicedMoveAtk)
            break;
    }

    if (moveIndex == MAX_MON_MOVES)
        *choicedMoveAtk = MOVE_NONE;

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerCallSubmove(struct BattleCalcValues *cv)
{
    bool32 noEffect = FALSE;
    enum Move calledMove = MOVE_NONE;
    const u8 *battleScript = NULL;
    battleScript = BattleScript_SubmoveAttackstring;

    switch (GetMoveEffect(cv->move))
    {
    case EFFECT_MIRROR_MOVE:
        calledMove = GetMirrorMoveMove();
        break;
    case EFFECT_METRONOME:
        calledMove = GetMetronomeMove();
        battleScript = BattleScript_MetronomeAttackstring;
        break;
    case EFFECT_ASSIST:
        calledMove = GetAssistMove();
        break;
    case EFFECT_NATURE_POWER:
        calledMove = GetNaturePowerMove();
        battleScript = BattleScript_NaturePowerAttackstring;
        break;
    case EFFECT_SLEEP_TALK:
        calledMove = GetSleepTalkMove();
        battleScript = BattleScript_SleepTalkAttackstring;
        break;
    case EFFECT_COPYCAT:
        calledMove = GetCopycatMove();
        break;
    case EFFECT_ME_FIRST:
        calledMove = GetMeFirstMove();
        break;
    default:
        noEffect = TRUE;
        break;
    }

    if (noEffect)
    {
        gBattleStruct->submoveAnnouncement = SUBMOVE_NO_EFFECT;
        return CANCELER_RESULT_SUCCESS;
    }

    if (calledMove != MOVE_NONE)
    {
        if (GetActiveGimmick(cv->battlerAtk) == GIMMICK_Z_MOVE && !IsBattleMoveStatus(calledMove))
            calledMove = GetTypeBasedZMove(calledMove);
        if (GetMoveEffect(cv->move) == EFFECT_COPYCAT && IsMaxMove(calledMove))
            calledMove = gBattleStruct->dynamax.lastUsedBaseMove;

        gBattleStruct->submoveAnnouncement = SUBMOVE_SUCCESS;
        gCalledMove = calledMove;
        if (GetBattlerMoveTargetType(cv->battlerAtk, cv->move) == TARGET_DEPENDS) // originally using a move without a set target
            gBattlerTarget = GetBattleMoveTarget(calledMove, TARGET_NONE);
        BattleScriptCall(battleScript);
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    }

    gBattleStruct->submoveAnnouncement = SUBMOVE_FAILURE;
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerThaw(struct BattleCalcValues *cv)
{
    enum CancelerResult result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;

    if (MoveThawsUser(cv->move))
    {
        if (gBattleMons[cv->battlerAtk].status1 & STATUS1_FREEZE)
        {
            if (!IsMoveEffectRemoveSpeciesType(cv->move, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_FIRE) || IS_BATTLER_OF_TYPE(cv->battlerAtk, TYPE_FIRE))
            {
                DefrostBattler(cv->battlerAtk, STATUS1_FREEZE);
                result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
                BattleScriptCall(BattleScript_BattlerDefrosted);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DEFROSTED_BY_MOVE;
            }
            else
            {
                result = CANCELER_RESULT_FAILURE;
            }
        }
        else if (gBattleMons[cv->battlerAtk].status1 & STATUS1_FROSTBITE)
        {
            if (!IsMoveEffectRemoveSpeciesType(cv->move, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_FIRE) || IS_BATTLER_OF_TYPE(cv->battlerAtk, TYPE_FIRE))
            {
                DefrostBattler(cv->battlerAtk, STATUS1_FROSTBITE);
                result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
                BattleScriptCall(BattleScript_BattlerFrostbiteHealed);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FROSTBITE_HEALED_BY_MOVE;
            }
            else
            {
                result = CANCELER_RESULT_FAILURE;
            }
        }
    }
    return result;
}

static enum CancelerResult CancelerStanceChangeTwo(struct BattleCalcValues *cv)
{
    if (B_STANCE_CHANGE_FAIL >= GEN_7 && gChosenMove == cv->move && TryFormChangeBeforeMove())
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerAttackstring(struct BattleCalcValues *cv)
{
    if (gBattleMons[cv->battlerAtk].volatiles.bideTurns)
        return CANCELER_RESULT_SUCCESS;

    BattleScriptCall(BattleScript_Attackstring);
    if (!gSpecialStatuses[gBattlerAttacker].dancerUsedMove)
    {
        gBattleMons[gBattlerAttacker].volatiles.usedMoves |= 1u << gCurrMovePos;
        gBattleStruct->battlerState[gBattlerAttacker].lastMoveTarget = gBattlerTarget;
        gLastPrintedMoves[gBattlerAttacker] = gChosenMove;
        RecordKnownMove(gBattlerAttacker, gChosenMove);
    }
    return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
}

#define checkFailure TRUE
#define skipFailure FALSE
static bool32 IsSingleTarget(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (battlerDef != gBattlerTarget)
        return skipFailure;
    return checkFailure;
}

static bool32 IsSmartTarget(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (!IsBattlerAlly(gBattlerTarget, battlerDef) || battlerAtk == battlerDef)
        return skipFailure;
    return checkFailure;
}

static bool32 IsTargetingBothFoes(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (battlerDef == BATTLE_PARTNER(battlerAtk) || battlerAtk == battlerDef)
    {
        // Because of Magic Bounce and Magic Coat we don't want to set MOVE_RESULT_NO_EFFECT
        if (GetMoveCategory(gCurrentMove) != DAMAGE_CATEGORY_STATUS)
            gBattleStruct->moveResultFlags[battlerDef] = MOVE_RESULT_NO_EFFECT;
        return skipFailure;
    }
    return checkFailure;
}

static bool32 IsTargetingSelf(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    return skipFailure;
}

static bool32 IsTargetingAlly(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (battlerDef != BATTLE_PARTNER(battlerAtk))
    {
        gBattleStruct->moveResultFlags[battlerDef] = MOVE_RESULT_NO_EFFECT;
        return skipFailure;
    }
    return checkFailure;
}

static bool32 IsTargetingSelfAndAlly(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (battlerDef != BATTLE_PARTNER(battlerAtk))
    {
        if (battlerDef != battlerAtk) // Don't set result flags for user
            gBattleStruct->moveResultFlags[battlerDef] = MOVE_RESULT_NO_EFFECT;
        return skipFailure;
    }
    return checkFailure;
}

static bool32 IsTargetingSelfOrAlly(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (battlerDef == battlerAtk)
        return skipFailure;

    if (battlerDef != BATTLE_PARTNER(battlerAtk))
    {
        gBattleStruct->moveResultFlags[battlerDef] = MOVE_RESULT_NO_EFFECT;
        return skipFailure;
    }

    return checkFailure;
}

static bool32 IsTargetingFoesAndAlly(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (battlerAtk == battlerDef)
        return skipFailure;  // Don't set result flags for user
    return checkFailure;
}

static bool32 IsTargetingField(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    return skipFailure;
}

static bool32 IsTargetingOpponentsField(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (IsBattlerAlly(battlerDef, BATTLE_OPPOSITE(battlerAtk)))
        return checkFailure;
    return skipFailure;
}

static bool32 IsTargetingAllBattlers(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    return checkFailure;
}

// ShouldCheckFailureOnTarget
static bool32 (*const sShouldCheckTargetMoveFailure[])(enum BattlerId battlerAtk, enum BattlerId battlerDef) =
{
    [TARGET_NONE] = IsTargetingField,
    [TARGET_SELECTED] = IsSingleTarget,
    [TARGET_DEPENDS] = IsSingleTarget,
    [TARGET_OPPONENT] = IsSingleTarget,
    [TARGET_RANDOM] = IsSingleTarget,
    [TARGET_BOTH] = IsTargetingBothFoes,
    [TARGET_USER] = IsTargetingSelf,
    [TARGET_SMART] = IsSmartTarget,
    [TARGET_ALLY] = IsTargetingAlly,
    [TARGET_USER_AND_ALLY] = IsTargetingSelfAndAlly,
    [TARGET_USER_OR_ALLY] = IsTargetingSelfOrAlly,
    [TARGET_FOES_AND_ALLY] = IsTargetingFoesAndAlly,
    [TARGET_FIELD] = IsTargetingField,
    [TARGET_OPPONENTS_FIELD] = IsTargetingOpponentsField,
    [TARGET_ALL_BATTLERS] = IsTargetingAllBattlers,
};

static bool32 ShouldCheckTargetMoveFailure(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, enum MoveTarget moveTarget)
{
    // For Bounced moves
    if (IsBattlerUnaffectedByMove(battlerDef))
        return skipFailure;

    return sShouldCheckTargetMoveFailure[moveTarget](battlerAtk, battlerDef);
}
#undef checkFailure
#undef skipFailure

static inline bool32 IsSmartTargetMoveConsecutiveHit(enum BattlerId battlerAtk, enum Move move)
{
    if (GetBattlerMoveTargetType(battlerAtk, move) != TARGET_SMART)
        return FALSE;

    if (gMultiHitCounter < GetMoveStrikeCount(move))
        return TRUE;

    return FALSE;
}

bool32 IsAffectedByFollowMe(enum BattlerId battlerAtk, enum BattleSide defSide, enum Move move)
{
    enum Ability ability = GetBattlerAbility(battlerAtk);
    enum BattleMoveEffects effect = GetMoveEffect(move);

    if (gSideTimers[defSide].followmeTimer == 0
        || (!IsBattlerAlive(gSideTimers[defSide].followmeTarget) && !IsSmartTargetMoveConsecutiveHit(battlerAtk, move))
        || effect == EFFECT_SNIPE_SHOT
        || effect == EFFECT_SKY_DROP
        || IsAbilityAndRecord(battlerAtk, ability, ABILITY_PROPELLER_TAIL)
        || IsAbilityAndRecord(battlerAtk, ability, ABILITY_STALWART))
        return FALSE;

    if (effect == EFFECT_PURSUIT && IsPursuitTargetSet())
        return FALSE;

    if (gSideTimers[defSide].followmePowder && !IsAffectedByPowderMove(battlerAtk, ability, GetBattlerHoldEffect(battlerAtk)))
        return FALSE;

    return TRUE;
}

static bool32 HandleMoveTargetRedirection(struct BattleCalcValues *cv, enum MoveTarget moveTarget)
{
    u32 redirectorOrderNum = MAX_BATTLERS_COUNT;
    enum BattleMoveEffects moveEffect = GetMoveEffect(cv->move);
    enum BattleSide side = BATTLE_OPPOSITE(GetBattlerSide(cv->battlerAtk));

    if (moveEffect == EFFECT_REFLECT_DAMAGE)
    {
        enum DamageCategory reflectCategory = GetReflectDamageMoveDamageCategory(cv->battlerAtk, cv->move);

        if (reflectCategory == DAMAGE_CATEGORY_PHYSICAL)
            cv->battlerDef = gBattleStruct->moveTarget[cv->battlerAtk] = gProtectStructs[cv->battlerAtk].physicalBattlerId;
        else
            cv->battlerDef = gBattleStruct->moveTarget[cv->battlerAtk] = gProtectStructs[cv->battlerAtk].specialBattlerId;
    }

    if (IsAffectedByFollowMe(cv->battlerAtk, side, cv->move)
     && (moveTarget == TARGET_SELECTED || moveTarget == TARGET_SMART || moveEffect == EFFECT_REFLECT_DAMAGE)
     && !IsBattlerAlly(cv->battlerAtk, gSideTimers[side].followmeTarget))
    {
        gBattleStruct->moveTarget[cv->battlerAtk] = cv->battlerDef = gSideTimers[side].followmeTarget; // follow me moxie fix
        return TRUE;
    }

    enum Type moveType = GetBattleMoveType(cv->move);
    enum Ability ability = cv->abilities[cv->battlerDef];
    bool32 currTargetCantAbsorb = ((ability != ABILITY_LIGHTNING_ROD && moveType == TYPE_ELECTRIC)
                                || (ability != ABILITY_STORM_DRAIN && moveType == TYPE_WATER));

    if (currTargetCantAbsorb
     && IsDoubleBattle()
     && gSideTimers[side].followmeTimer == 0
     && moveTarget != TARGET_USER
     && moveTarget != TARGET_ALL_BATTLERS
     && moveTarget != TARGET_FIELD
     && moveEffect != EFFECT_TEATIME
     && moveEffect != EFFECT_SNIPE_SHOT
     && moveEffect != EFFECT_PLEDGE)
    {
        // Find first battler that redirects the move (in turn order)
        enum Ability abilityAtk = cv->abilities[cv->battlerAtk];
        enum BattlerId battler;
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            ability = cv->abilities[battler];
            if ((B_REDIRECT_ABILITY_ALLIES >= GEN_4 || !IsBattlerAlly(cv->battlerAtk, battler))
                && battler != cv->battlerAtk
                && battler != cv->battlerDef
                && ((ability == ABILITY_LIGHTNING_ROD && moveType == TYPE_ELECTRIC)
                 || (ability == ABILITY_STORM_DRAIN && moveType == TYPE_WATER))
                && GetBattlerTurnOrderNum(battler) < redirectorOrderNum
                && !IsAbilityAndRecord(cv->battlerAtk, abilityAtk, ABILITY_PROPELLER_TAIL)
                && !IsAbilityAndRecord(cv->battlerAtk, abilityAtk, ABILITY_STALWART))
            {
                redirectorOrderNum = GetBattlerTurnOrderNum(battler);
            }
        }
        if (redirectorOrderNum != MAX_BATTLERS_COUNT)
        {
            cv->battlerDef = gBattlerByTurnOrder[redirectorOrderNum];
            RecordAbilityBattle(cv->battlerDef, cv->abilities[cv->battlerDef]);
            gSpecialStatuses[cv->battlerDef].abilityRedirected = TRUE;
            return TRUE;
        }
    }

    return FALSE;
}

static bool32 WasOriginalTargetAlly(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum MoveTarget moveTarget)
{
    if (!gProtectStructs[BATTLE_PARTNER(battlerAtk)].usedAllySwitch)
        return FALSE;

    if ((moveTarget == TARGET_ALLY || moveTarget == TARGET_USER_OR_ALLY) && battlerAtk == battlerDef)
        return TRUE;

    return FALSE;
}

static enum CancelerResult CancelerSetTargets(struct BattleCalcValues *cv)
{
    enum MoveTarget moveTarget = GetBattlerMoveTargetType(cv->battlerAtk, cv->move);

    if (!HandleMoveTargetRedirection(cv, moveTarget))
    {
        if (IsDoubleBattle() && moveTarget == TARGET_RANDOM)
        {
            cv->battlerDef = SetRandomTarget(cv->battlerAtk);
            if (gAbsentBattlerFlags & (1u << cv->battlerAtk)
                && !IsBattlerAlly(cv->battlerAtk, cv->battlerDef))
            {
                cv->battlerDef = GetPartnerBattler(cv->battlerDef);
            }
        }
        else if (moveTarget == TARGET_ALLY && !IsBattlerAlly(cv->battlerDef, cv->battlerAtk))
        {
            cv->battlerDef = BATTLE_PARTNER(cv->battlerAtk);
        }
        else if (IsDoubleBattle() && moveTarget == TARGET_FOES_AND_ALLY)
        {
            for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
            {
                if (battlerDef == cv->battlerAtk)
                    continue;

                if (IsBattlerAlive(battlerDef))
                {
                    cv->battlerDef = battlerDef;
                    break;
                }
            }
        }
        else if (moveTarget == TARGET_USER || moveTarget == TARGET_USER_AND_ALLY)
        {
            cv->battlerDef = cv->battlerAtk;
        }
        else if (!IsBattlerAlive(cv->battlerDef)
              && moveTarget != TARGET_OPPONENTS_FIELD
              && IsDoubleBattle()
              && (!IsBattlerAlly(cv->battlerAtk, cv->battlerDef)))
        {
            cv->battlerDef = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(cv->battlerDef)));
        }
    }

    gBattlerTarget = cv->battlerDef; // ShouldCheckTargetMoveFailure relies on gBattlerTarget

    while (gBattleStruct->eventState.atkCancelerBattler < gBattlersCount)
    {
        enum BattlerId battlerDef = gBattleStruct->eventState.atkCancelerBattler++;

        if (!ShouldCheckTargetMoveFailure(cv->battlerAtk, battlerDef, cv->move, moveTarget))
            gBattleStruct->battlerState[cv->battlerAtk].targetsDone[battlerDef] = TRUE;
    }
    gBattleStruct->eventState.atkCancelerBattler = 0;

    if (IsBattlerAlly(cv->battlerAtk, cv->battlerDef) && !IsBattlerAlive(cv->battlerDef))
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
        return CANCELER_RESULT_FAILURE;
    }
    else if (WasOriginalTargetAlly(cv->battlerAtk, cv->battlerDef, moveTarget))
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
        return CANCELER_RESULT_FAILURE;
    }

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerPPDeduction(struct BattleCalcValues *cv)
{
    if (gBattleMons[cv->battlerAtk].volatiles.multipleTurns
     || gSpecialStatuses[cv->battlerAtk].dancerUsedMove
     || gBattleStruct->bouncedMoveIsUsed
     || gBattleMons[cv->battlerAtk].volatiles.bideTurns
     || cv->move == MOVE_STRUGGLE)
        return CANCELER_RESULT_SUCCESS;

    s32 ppToDeduct = 1;
    enum MoveTarget moveTarget = GetBattlerMoveTargetType(cv->battlerAtk, cv->move);
    u32 movePosition = gCurrMovePos;

    if (gBattleStruct->submoveAnnouncement == SUBMOVE_SUCCESS)
        movePosition = gChosenMovePos;

    if (IsSpreadMove(moveTarget)
     || moveTarget == TARGET_ALL_BATTLERS
     || moveTarget == TARGET_FIELD
     || MoveForcesPressure(cv->move))
    {
        for (u32 i = 0; i < gBattlersCount; i++)
        {
            if (!IsBattlerAlly(i, cv->battlerAtk))
                ppToDeduct += (GetBattlerAbility(i) == ABILITY_PRESSURE);
        }
    }
    else if (moveTarget != TARGET_OPPONENTS_FIELD)
    {
        if (cv->battlerAtk != cv->battlerDef && GetBattlerAbility(cv->battlerDef) == ABILITY_PRESSURE)
             ppToDeduct++;
    }

    // For item Metronome, echoed voice
    if (cv->move != gLastResultingMoves[cv->battlerAtk] || gBattleStruct->unableToUseMove)
        gBattleMons[cv->battlerAtk].volatiles.metronomeItemCounter = 0;

    if (gBattleMons[cv->battlerAtk].pp[movePosition] > ppToDeduct)
        gBattleMons[cv->battlerAtk].pp[movePosition] -= ppToDeduct;
    else
        gBattleMons[cv->battlerAtk].pp[movePosition] = 0;

    if (MOVE_IS_PERMANENT(cv->battlerAtk, movePosition))
    {
        BtlController_EmitSetMonData(
            cv->battlerAtk,
            B_COMM_TO_CONTROLLER,
            REQUEST_PPMOVE1_BATTLE + movePosition,
            0,
            sizeof(gBattleMons[cv->battlerAtk].pp[movePosition]),
            &gBattleMons[cv->battlerAtk].pp[movePosition]);
        MarkBattlerForControllerExec(cv->battlerAtk);
    }

    if (gBattleStruct->submoveAnnouncement != SUBMOVE_NO_EFFECT)
    {
        if (gBattleStruct->submoveAnnouncement == SUBMOVE_FAILURE)
        {
            gBattleStruct->submoveAnnouncement = SUBMOVE_NO_EFFECT;
            gBattlescriptCurrInstr = BattleScript_ButItFailed;
            return CANCELER_RESULT_FAILURE;
        }
        else if (CancelerVolatileBlocked(cv) == CANCELER_RESULT_FAILURE) // Check Gravity/Heal Block/Throat Chop for Submove
        {
            gBattleStruct->submoveAnnouncement = SUBMOVE_NO_EFFECT;
            return CANCELER_RESULT_FAILURE;
        }
        else
        {
            gBattleStruct->submoveAnnouncement = SUBMOVE_NO_EFFECT;
            gBattleScripting.animTurn = 0;
            gBattleScripting.animTargetsHit = 0;

            // Possibly better to just move type setting and redirection to attackcanceler as a new case at this point
            SetTypeBeforeUsingMove(cv->move, cv->battlerAtk);
            ClearDamageCalcResults();
            gBattlescriptCurrInstr = GetMoveBattleScript(cv->move);
            return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
        }
    }

    return CANCELER_RESULT_SUCCESS;
}

// We don't have clear data on where this belongs to but I assume it should at least be checked before Protean
static enum CancelerResult CancelerSkyBattle(struct BattleCalcValues *cv)
{
    if (gBattleStruct->isSkyBattle && IsMoveSkyBattleBanned(gCurrentMove))
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerWeatherPrimal(struct BattleCalcValues *cv)
{
    enum CancelerResult result = CANCELER_RESULT_SUCCESS;

    if (GetMovePower(cv->move) > 0 && HasWeatherEffect())
    {
        enum Type moveType = GetBattleMoveType(cv->move);
        if (moveType == TYPE_FIRE && gBattleWeather & B_WEATHER_RAIN_PRIMAL && (GetConfig(B_POWDER_STATUS_HEAVY_RAIN) >= GEN_7 || !TryActivatePowderStatus(cv->move)))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PRIMAL_WEATHER_FIZZLED_BY_RAIN;
            result = CANCELER_RESULT_FAILURE;
        }
        else if (moveType == TYPE_WATER && gBattleWeather & B_WEATHER_SUN_PRIMAL)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PRIMAL_WEATHER_EVAPORATED_IN_SUN;
            result = CANCELER_RESULT_FAILURE;
        }
        if (result == CANCELER_RESULT_FAILURE)
        {
            gProtectStructs[cv->battlerAtk].chargingTurn = FALSE;
            CancelMultiTurnMoves(cv->battlerAtk);
            gBattlescriptCurrInstr = BattleScript_PrimalWeatherBlocksMove;
        }
    }

    return result;
}

static enum CancelerResult CancelerFocusPreGen5(struct BattleCalcValues *cv)
{
    if (GetConfig(B_FOCUS_PUNCH_FAILURE) < GEN_5)
        return CancelerFocus(cv);
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerBide(struct BattleCalcValues *cv)
{
    if (GetMoveEffect(cv->move) != EFFECT_BIDE)
        return CANCELER_RESULT_SUCCESS;

    if (gBattleMons[cv->battlerAtk].volatiles.bideTurns)
    {
        if (--gBattleMons[cv->battlerAtk].volatiles.bideTurns)
        {
            gBattlescriptCurrInstr = BattleScript_BideStoringEnergy;
            return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT; // Jump to moveend
        }
        else if (gBideDmg[cv->battlerAtk])
        {
            gBattlerTarget = gBideTarget[cv->battlerAtk];
            gBattleMons[cv->battlerAtk].volatiles.multipleTurns = FALSE;
            if (!IsBattlerAlive(gBattlerTarget))
                gBattlerTarget = GetBattleMoveTarget(gCurrentMove, TARGET_SELECTED);
            gBattleStruct->battlerState[cv->battlerAtk].targetsDone[gBattlerTarget] = FALSE;
            BattleScriptCall(BattleScript_BideAttack);
            return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
        }
        else
        {
            gBattleMons[cv->battlerAtk].volatiles.multipleTurns = FALSE;
            gBattlescriptCurrInstr = BattleScript_BideNoEnergyToAttack;
            return CANCELER_RESULT_FAILURE;
        }
    }
    else
    {
        gBattleMons[gBattlerAttacker].volatiles.multipleTurns = TRUE;
        gLockedMoves[gBattlerAttacker] = gCurrentMove;
        gBideDmg[gBattlerAttacker] = 0;
        gBattleMons[gBattlerAttacker].volatiles.bideTurns = 2;
        gBattlescriptCurrInstr = BattleScript_SetUpBide;
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT; // Jump to moveend
    }

    return CANCELER_RESULT_SUCCESS;
}

static bool32 ShouldSkipFailureCheckOnBattler(enum BattlerId battlerAtk, enum BattlerId battlerDef, bool32 checkResultFlag)
{
    if (gBattleStruct->battlerState[battlerAtk].targetsDone[battlerDef])
        return TRUE;
    if (checkResultFlag && gBattleStruct->moveResultFlags[battlerDef] & MOVE_RESULT_NO_EFFECT)
        return TRUE;
    if (GetConfig(B_CHECK_USER_FAILURE) >= GEN_5 && battlerAtk == battlerDef)
        return TRUE;
    return FALSE;
}

static enum CancelerResult CancelerMoveFailure(struct BattleCalcValues *cv)
{
    const u8 *battleScript = NULL;

    switch (GetMoveEffect(cv->move))
    {
    case EFFECT_FLING:
        if (!CanFling(cv->battlerAtk, cv->abilities[cv->battlerAtk]))
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_FAIL_IF_NOT_ARG_TYPE:
        if (!IS_BATTLER_OF_TYPE(cv->battlerAtk, GetMoveArgType(cv->move)))
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_DARK_VOID:
        if (gBattleStruct->bouncedMoveIsUsed)
            break;
        if (B_DARK_VOID_FAIL >= GEN_7 && gBattleMons[cv->battlerAtk].species != SPECIES_DARKRAI)
            battleScript = BattleScript_PokemonCantUseTheMove;
        break;
    case EFFECT_AURA_WHEEL:
        if (gBattleMons[cv->battlerAtk].species != SPECIES_MORPEKO_FULL_BELLY
         && gBattleMons[cv->battlerAtk].species != SPECIES_MORPEKO_HANGRY)
            battleScript = BattleScript_PokemonCantUseTheMove;
        break;
    case EFFECT_AURORA_VEIL:
        if (!(gBattleWeather & B_WEATHER_ICY_ANY && HasWeatherEffect()))
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_CLANGOROUS_SOUL:
        if (gBattleMons[cv->battlerAtk].hp <= max(1, GetNonDynamaxMaxHP(cv->battlerAtk) / 3))
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_REFLECT_DAMAGE:
    {
        enum DamageCategory reflectCategory = GetReflectDamageMoveDamageCategory(cv->battlerAtk, cv->move);
        if (IsBattlerAlly(cv->battlerAtk, cv->battlerDef))
            battleScript = BattleScript_ButItFailed;
        // Counter / Metal Burst and took physical damage
        else if (reflectCategory == DAMAGE_CATEGORY_PHYSICAL
              && gProtectStructs[cv->battlerAtk].physicalDmg > 0
              && (GetConfig(B_COUNTER_TRY_HIT_PARTNER) >= GEN_5 || gBattleMons[gProtectStructs[cv->battlerAtk].physicalBattlerId].hp))
            break;
        // Mirror Coat / Metal Burst and took special damage
        else if (reflectCategory == DAMAGE_CATEGORY_SPECIAL
              && gProtectStructs[cv->battlerAtk].specialDmg > 0
              && (GetConfig(B_COUNTER_TRY_HIT_PARTNER) >= GEN_5 || gBattleMons[gProtectStructs[cv->battlerAtk].specialBattlerId].hp))
            break;
        else
            battleScript = BattleScript_ButItFailed;
        break;
    }
    case EFFECT_DESTINY_BOND:
        if (DoesDestinyBondFail(cv->battlerAtk))
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_FIRST_TURN_ONLY:
        if (!gBattleStruct->battlerState[cv->battlerAtk].isFirstTurn || gSpecialStatuses[cv->battlerAtk].backUpTarget)
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_MAT_BLOCK:
        if (!gBattleStruct->battlerState[cv->battlerAtk].isFirstTurn || gSpecialStatuses[cv->battlerAtk].backUpTarget)
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_FOLLOW_ME:
        if (B_UPDATED_MOVE_DATA >= GEN_8 && !(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_LAST_RESORT:
        if (!CanUseLastResort(cv->battlerAtk))
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_NO_RETREAT:
        if (gBattleMons[cv->battlerAtk].volatiles.noRetreat)
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_PROTECT:
    case EFFECT_ENDURE:
        TryResetConsecutiveUseCounter(cv->battlerAtk);
        if (IsLastMonToMove(cv->battlerAtk))
        {
            battleScript = BattleScript_ButItFailed;
        }
        else
        {
            enum ProtectMethod protectMethod = GetMoveProtectMethod(cv->move);
            bool32 canUseProtectSecondTime = CanUseMoveConsecutively(cv->battlerAtk);
            bool32 canUseWideGuard = (GetConfig(B_WIDE_GUARD) >= GEN_6 && protectMethod == PROTECT_WIDE_GUARD);
            bool32 canUseQuickGuard = (GetConfig(B_QUICK_GUARD) >= GEN_6 && protectMethod == PROTECT_QUICK_GUARD);

            if (!canUseProtectSecondTime
             && !canUseWideGuard
             && !canUseQuickGuard
             && protectMethod != PROTECT_CRAFTY_SHIELD)
                battleScript = BattleScript_ButItFailed;
        }
        if (battleScript != NULL)
        {
            gBattleMons[cv->battlerAtk].volatiles.consecutiveMoveUses = 0;
            gBattleStruct->battlerState[cv->battlerAtk].stompingTantrumTimer = 2;
        }
        break;
    case EFFECT_REST:
        if (gBattleMons[cv->battlerAtk].status1 & STATUS1_SLEEP
         || cv->abilities[cv->battlerAtk] == ABILITY_COMATOSE)
            battleScript = BattleScript_RestIsAlreadyAsleep;
        else if (gBattleMons[cv->battlerAtk].hp == gBattleMons[cv->battlerAtk].maxHP)
            battleScript = BattleScript_AlreadyAtFullHp;
        else if (cv->abilities[cv->battlerAtk] == ABILITY_INSOMNIA
              || cv->abilities[cv->battlerAtk] == ABILITY_VITAL_SPIRIT
              || cv->abilities[cv->battlerAtk] == ABILITY_PURIFYING_SALT)
            battleScript = BattleScript_InsomniaProtects;
        break;
    case EFFECT_SNORE:
        if (!(gBattleMons[cv->battlerAtk].status1 & STATUS1_SLEEP)
         && cv->abilities[cv->battlerAtk] != ABILITY_COMATOSE)
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_STEEL_ROLLER:
        if (!(gFieldStatuses & STATUS_FIELD_TERRAIN_ANY))
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_STOCKPILE:
        if (gBattleMons[cv->battlerAtk].volatiles.stockpileCounter >= 3)
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_STUFF_CHEEKS:
        if (GetItemPocket(gBattleMons[cv->battlerAtk].item) != POCKET_BERRIES)
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_SWALLOW:
    case EFFECT_SPIT_UP:
        if (gBattleMons[cv->battlerAtk].volatiles.stockpileCounter == 0 && !gBattleStruct->snatchedMoveIsUsed)
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_TELEPORT:
        // TODO: follow up: Can't make sense of teleport logic
        break;
    case EFFECT_NATURAL_GIFT:
        if (GetItemPocket(gBattleMons[cv->battlerAtk].item) != POCKET_BERRIES
         || gFieldStatuses & STATUS_FIELD_MAGIC_ROOM
         || cv->abilities[cv->battlerAtk] == ABILITY_KLUTZ
         || gBattleMons[cv->battlerAtk].volatiles.embargo)
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_PRESENT:
    {
        u32 rand = RandomUniform(RNG_PRESENT, 0, 0xFF);
        if (rand < 102)
            gBattleStruct->presentBasePower = 40;
        else if (rand < 178)
            gBattleStruct->presentBasePower = 80;
        else if (rand < 204)
            gBattleStruct->presentBasePower = 120;
        else
            gBattleStruct->presentBasePower = 0; // Healing
    }
        break;
    default:
        break;
    }

    if (battleScript != NULL)
    {
        gBattlescriptCurrInstr = battleScript;
        return CANCELER_RESULT_FAILURE;
    }

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerMoveEffectFailureTarget(struct BattleCalcValues *cv)
{
    const u8 *battleScript = NULL;
    u32 numAffectedTargets = 0;

    while (gBattleStruct->eventState.atkCancelerBattler < gBattlersCount)
    {
        enum BattlerId battlerDef = gBattleStruct->eventState.atkCancelerBattler++;

        if (ShouldSkipFailureCheckOnBattler(cv->battlerAtk, battlerDef, TRUE))
            continue;

        switch (GetMoveEffect(cv->move))
        {
        case EFFECT_FLING:
            if (!IsBattlerAlive(battlerDef)) // Edge case for removing a mon's item when there is no target available after using Fling.
            {
                battleScript = BattleScript_FlingFailConsumeItem;
            }
            else
            {
                numAffectedTargets++;
                continue;
            }
            break;
        case EFFECT_FUTURE_SIGHT:
            if (gBattleStruct->futureSight[battlerDef].counter > 0)
            {
                battleScript = BattleScript_ButItFailed;
            }
            else
            {
                numAffectedTargets++;
                continue;
            }
            break;
        case EFFECT_POLTERGEIST:
            if (gBattleMons[battlerDef].item == ITEM_NONE)
            {
                battleScript = BattleScript_ButItFailed;
            }
            else
            {
                numAffectedTargets++;
                continue;
            }
            break;
        case EFFECT_SUCKER_PUNCH:
        {
            u32 defMove = GetBattlerChosenMove(battlerDef);
            if (HasBattlerActedThisTurn(battlerDef)
             || (IsBattleMoveStatus(defMove) && !gProtectStructs[battlerDef].noValidMoves && GetMoveEffect(defMove) != EFFECT_ME_FIRST))
            {
                battleScript = BattleScript_ButItFailed;
            }
            else
            {
                numAffectedTargets++;
                continue;
            }

        }
            break;
        case EFFECT_UPPER_HAND:
        {
            s32 prio = GetChosenMovePriority(battlerDef, GetBattlerAbility(battlerDef));
            if (prio < 1 || prio > 3 // Fails if priority is less than 1 or greater than 3, if target already moved, or if using a status
             || HasBattlerActedThisTurn(battlerDef)
             || gChosenMoveByBattler[battlerDef] == MOVE_NONE
             || IsBattleMoveStatus(gChosenMoveByBattler[battlerDef]))
            {
                battleScript = BattleScript_ButItFailed;
            }
            else
            {
                numAffectedTargets++;
                continue;
            }
            break;
        }
        case EFFECT_LOW_KICK:
        case EFFECT_HEAT_CRASH:
            if (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
            {
                battleScript = BattleScript_MoveBlockedByDynamax;
            }
            else
            {
                numAffectedTargets++;
                continue;
            }
            break;
        default:
            continue;
        }

        gBattleStruct->moveResultFlags[battlerDef] = MOVE_RESULT_FAILED;
    }

    gBattleStruct->eventState.atkCancelerBattler = 0;

    if (battleScript != NULL && numAffectedTargets == 0)
    {
        gBattlescriptCurrInstr = battleScript;
        return CANCELER_RESULT_FAILURE;
    }

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerPowderStatus(struct BattleCalcValues *cv)
{
    if (TryActivatePowderStatus(cv->move))
    {
        if (!IsAbilityAndRecord(cv->battlerAtk, cv->abilities[cv->battlerAtk], ABILITY_MAGIC_GUARD))
            SetPassiveDamageAmount(cv->battlerAtk, GetNonDynamaxMaxHP(cv->battlerAtk) / 4);

        // This might be incorrect
        if (GetActiveGimmick(cv->battlerAtk) != GIMMICK_Z_MOVE
         || HasTrainerUsedGimmick(cv->battlerAtk, GIMMICK_Z_MOVE))
            gBattlescriptCurrInstr = BattleScript_MoveUsedPowder;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

bool32 IsDazzlingAbility(enum Ability ability)
{
    switch (ability)
    {
    case ABILITY_DAZZLING:        return TRUE;
    case ABILITY_QUEENLY_MAJESTY: return TRUE;
    case ABILITY_ARMOR_TAIL:      return TRUE;
    default: break;
    }
    return FALSE;
}

static enum CancelerResult CancelerPriorityBlock(struct BattleCalcValues *cv)
{
    bool32 effect = FALSE;
    s32 priority = GetChosenMovePriority(cv->battlerAtk, cv->abilities[cv->battlerAtk]);
    enum MoveTarget moveTarget = GetBattlerMoveTargetType(cv->battlerAtk, cv->move);

    if (priority <= 0 || moveTarget == TARGET_FIELD || moveTarget == TARGET_OPPONENTS_FIELD)
        return CANCELER_RESULT_SUCCESS;

    enum BattlerId battler;
    enum Ability ability = ABILITY_NONE; // ability of battler who is blocking
    for (battler = 0; battler < gBattlersCount; battler++)
    {
        if (!IsBattlerAlive(battler) || IsBattlerAlly(cv->battlerAtk, battler))
            continue;
        if (ShouldSkipFailureCheckOnBattler(cv->battlerAtk, battler, TRUE)
         && (!IsDoubleBattle() || ShouldSkipFailureCheckOnBattler(cv->battlerAtk, BATTLE_PARTNER(battler), TRUE))) // either battler or partner is affected
            continue;

        ability = cv->abilities[battler];
        if (IsDazzlingAbility(ability))
        {
            effect = TRUE;
            break;
        }
    }

    if (effect)
    {
        gLastUsedAbility = ability;
        RecordAbilityBattle(battler, ability);
        gBattlerAbility = battler;
        gBattlescriptCurrInstr = BattleScript_PokemonCannotUseMove;
        return CANCELER_RESULT_FAILURE;
    }

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerExplodingDamp(struct BattleCalcValues *cv)
{
    if (!IsMoveDampBanned(cv->move))
        return CANCELER_RESULT_SUCCESS;

    u32 dampBattler = IsAbilityOnField(ABILITY_DAMP);
    if (dampBattler)
    {
        gBattlerAbility = dampBattler - 1;
        gLastUsedAbility = ABILITY_DAMP;
        RecordAbilityBattle(gBattlerAbility, ABILITY_DAMP);
        gBattlescriptCurrInstr = BattleScript_PokemonCannotUseMove;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerProtean(struct BattleCalcValues *cv)
{
    enum Type moveType = GetBattleMoveType(cv->move);
    if (ProteanTryChangeType(cv->battlerAtk, cv->abilities[cv->battlerAtk], cv->move, moveType))
    {
        if (GetConfig(B_PROTEAN_LIBERO) >= GEN_9)
            gBattleMons[cv->battlerAtk].volatiles.usedProteanLibero = TRUE;
        PREPARE_TYPE_BUFFER(gBattleTextBuff1, moveType);
        gBattlerAbility = cv->battlerAtk;
        PrepareStringBattle(STRINGID_EMPTYSTRING3, cv->battlerAtk);
        gBattleCommunication[MSG_DISPLAY] = 1;
        BattleScriptCall(BattleScript_ProteanActivates);
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    }
    return CANCELER_RESULT_SUCCESS;
}

static bool32 CanTwoTurnMoveFireThisTurn(struct BattleCalcValues *cv)
{
    if (gBattleMoveEffects[GetMoveEffect(cv->move)].semiInvulnerableEffect
     || GetMoveEffect(cv->move) == EFFECT_GEOMANCY
     || !(GetAttackerWeather(cv->holdEffects[cv->battlerAtk], cv->abilities[cv->battlerAtk], GetWeather()) & GetMoveTwoTurnAttackWeather(cv->move))) 
        return FALSE;
    return TRUE;
}

static enum CancelerResult HandleSkyDropResult(struct BattleCalcValues *cv)
{
    if (gBattleMons[cv->battlerAtk].volatiles.multipleTurns) // Second turn
    {
        gBattleScripting.animTurn = 1;
        gBattleScripting.animTargetsHit = 0;
        gBattleMons[cv->battlerAtk].volatiles.multipleTurns = FALSE;
        gBattleMons[cv->battlerAtk].volatiles.semiInvulnerable = STATE_NONE;
        gBattleMons[cv->battlerAtk].volatiles.skyDropTarget = 0;

        // Sky Drop fails if target already left the field
        if (gBattleMons[cv->battlerDef].volatiles.semiInvulnerable == STATE_NONE)
        {
            gBattlescriptCurrInstr = BattleScript_SkyDropNoTarget;
            return CANCELER_RESULT_FAILURE;
        }

        gBattleMons[cv->battlerDef].volatiles.semiInvulnerable = STATE_NONE;
        return CANCELER_RESULT_SUCCESS;
    }

    if (IsBattlerAlly(cv->battlerAtk, cv->battlerDef))
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
        return CANCELER_RESULT_FAILURE;
    }
    else if (gBattleMons[cv->battlerDef].volatiles.semiInvulnerable != STATE_NONE)
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
        return CANCELER_RESULT_FAILURE;
    }
    else if (DoesSubstituteBlockMove(cv->battlerAtk, cv->battlerDef, cv->move))
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
        return CANCELER_RESULT_FAILURE;
    }
    else if (GetBattlerWeight(gBattlerTarget) >= 2000)
    {
        gBattlescriptCurrInstr = BattleScript_SkyDropTargetTooHeavy;
        return CANCELER_RESULT_FAILURE;
    }

    // First turn

    if (gBattleMons[cv->battlerDef].volatiles.rampageTurns > 0)
        gBattleMons[cv->battlerDef].volatiles.confuseAfterDrop = TRUE;

    CancelMultiTurnMoves(cv->battlerDef);
    gLockedMoves[cv->battlerAtk] = cv->move;
    gProtectStructs[cv->battlerAtk].chargingTurn = TRUE;
    gBattleMons[cv->battlerAtk].volatiles.multipleTurns = TRUE;
    gBattleMons[cv->battlerAtk].volatiles.skyDropTarget = cv->battlerDef + 1;
    gBattleMons[cv->battlerAtk].volatiles.semiInvulnerable = STATE_SKY_DROP_ATTACKER;
    gBattleMons[cv->battlerDef].volatiles.semiInvulnerable = STATE_SKY_DROP_TARGET;
    if (gSideTimers[GetBattlerSide(cv->battlerDef)].followmeTimer != 0 && gSideTimers[GetBattlerSide(cv->battlerDef)].followmeTarget == cv->battlerDef)
        gSideTimers[GetBattlerSide(cv->battlerDef)].followmeTimer = 0;

    gBattlescriptCurrInstr = BattleScript_SkyDropCharging;
    return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
}

static enum CancelerResult CancelerCharging(struct BattleCalcValues *cv)
{
    enum CancelerResult result = CANCELER_RESULT_SUCCESS;

    if (!gBattleMoveEffects[GetMoveEffect(cv->move)].twoTurnEffect)
    {
        result = CANCELER_RESULT_SUCCESS;
    }
    else if (GetMoveEffect(cv->move) == EFFECT_SKY_DROP)
    {
        result = HandleSkyDropResult(cv);
    }
    else if (gBattleMons[cv->battlerAtk].volatiles.multipleTurns) // Second turn
    {
        gBattleScripting.animTurn = 1;
        gBattleScripting.animTargetsHit = 0;
        gBattleMons[cv->battlerAtk].volatiles.multipleTurns = FALSE;
        if (gBattleMoveEffects[GetMoveEffect(cv->move)].semiInvulnerableEffect)
            gBattleMons[cv->battlerAtk].volatiles.semiInvulnerable = STATE_NONE;
        result = CANCELER_RESULT_SUCCESS;
    }
    else if (!gProtectStructs[cv->battlerAtk].chargingTurn) // First turn charge
    {
        gLockedMoves[cv->battlerAtk] = cv->move;
        gProtectStructs[cv->battlerAtk].chargingTurn = TRUE;
        if (gBattleMoveEffects[GetMoveEffect(cv->move)].semiInvulnerableEffect)
            gBattleMons[cv->battlerAtk].volatiles.semiInvulnerable = GetMoveTwoTurnAttackStatus(cv->move);
        BattleScriptCall(BattleScript_TwoTurnMoveCharging);
        result = CANCELER_RESULT_RUN_SCRIPT;
    }
    else // Try move this turn. Otherwise use next turn
    {
        if (CanTwoTurnMoveFireThisTurn(cv))
        {
            gBattleScripting.animTurn = 1;
            gBattleScripting.animTargetsHit = 0;
            gProtectStructs[cv->battlerAtk].chargingTurn = FALSE;
            if (gBattleMoveEffects[GetMoveEffect(cv->move)].semiInvulnerableEffect)
                gBattleMons[cv->battlerAtk].volatiles.semiInvulnerable = STATE_NONE;
            result = CANCELER_RESULT_SUCCESS;
        }
        else if (cv->holdEffects[cv->battlerAtk] == HOLD_EFFECT_POWER_HERB)
        {
            gBattleScripting.animTurn = 1;
            gBattleScripting.animTargetsHit = 0;
            gProtectStructs[cv->battlerAtk].chargingTurn = FALSE;
            if (gBattleMoveEffects[GetMoveEffect(cv->move)].semiInvulnerableEffect)
                gBattleMons[cv->battlerAtk].volatiles.semiInvulnerable = STATE_NONE;
            gLastUsedItem = gBattleMons[cv->battlerAtk].item;
            BattleScriptCall(BattleScript_PowerHerbActivation);
            result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
        }
        else // Use move next turn
        {
            gBattleMons[cv->battlerAtk].volatiles.multipleTurns = TRUE;
            gBattlescriptCurrInstr = BattleScript_MoveEnd;
            result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
        }

    }

    return result;
}

static enum CancelerResult CancelerSnatch(struct BattleCalcValues *cv)
{
    for (u32 i = 0; i < gCurrentTurnActionNumber; i++)
    {
        if (!gProtectStructs[gBattlerByTurnOrder[i]].stealMove
         || !MoveCanBeSnatched(cv->move))
            continue;

        if (B_SNATCH < GEN_5 || !gBattleStruct->snatchedMoveIsUsed)
        {
            u32 snatchBattler = gBattlerByTurnOrder[i];

            if (!gBattleStruct->snatchedMoveIsUsed) // store only once
            {
                SaveBattlerAttacker(gBattlerAttacker);
                SaveBattlerTarget(gBattlerTarget);
            }

            gProtectStructs[snatchBattler].stealMove = FALSE;
            gBattleStruct->snatchedMoveIsUsed = TRUE;

            if (cv->battlerAtk == cv->battlerDef)
            {
                gBattleScripting.battler = gBattlerTarget;
                gBattlerAttacker = gBattlerTarget = snatchBattler;
            }
            else
            {
                gBattlerTarget = gBattlerAttacker;
                gBattlerAttacker = snatchBattler;
            }

            gBattleStruct->eventState.atkCanceler = CANCELER_VOLATILE_BLOCKED;
            BattleScriptCall(BattleScript_SnatchedMove);
            return CANCELER_RESULT_RUN_SCRIPT;
        }
    }

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerExplosion(struct BattleCalcValues *cv)
{
    // KO user of Explosion; for Final Gambit doesn't happen if target is immune or if it missed
    if (IsExplosionMove(cv->move)
     && (GetMoveEffect(cv->move) != EFFECT_FINAL_GAMBIT || IsAnyTargetAffected()))
    {
        BattleScriptCall(BattleScript_Explosion);
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    }

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerMoveSpecificMessage(struct BattleCalcValues *cv)
{
    switch (GetMoveEffect(cv->move))
    {
    case EFFECT_MAGNITUDE:
        CalculateMagnitudeDamage();
        BattleScriptCall(BattleScript_MagnitudeMessage);
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    case EFFECT_FICKLE_BEAM:
        gBattleStruct->fickleBeamBoosted = RandomPercentage(RNG_FICKLE_BEAM, 30);
        if (gBattleStruct->fickleBeamBoosted)
        {
            BattleScriptCall(BattleScript_FickleBeamMessage);
            return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
        }
        break;
    default:
        break;
    }

    return CANCELER_RESULT_SUCCESS;
}

static bool32 NoTargetPresent(enum BattlerId battler, enum Move move, enum MoveTarget moveTarget)
{
    switch (moveTarget)
    {
    case TARGET_USER_AND_ALLY:
        return FALSE; // At least user is present
    case TARGET_ALLY:
        if (!IsBattlerAlive(gBattlerTarget))
            return TRUE;
        break;
    case TARGET_SELECTED:
    case TARGET_DEPENDS:
    case TARGET_RANDOM:
        if (!IsBattlerAlive(gBattlerTarget) && !IsBattlerAlive(GetBattleMoveTarget(move, TARGET_NONE)))
            return TRUE;
        break;
    case TARGET_BOTH:
    case TARGET_SMART:
        if (!IsBattlerAlive(gBattlerTarget) && !IsBattlerAlive(BATTLE_PARTNER(gBattlerTarget)))
            return TRUE;
        break;
    case TARGET_FOES_AND_ALLY:
        if (!IsBattlerAlive(gBattlerTarget) && !IsBattlerAlive(BATTLE_PARTNER(gBattlerTarget)) && !IsBattlerAlive(BATTLE_PARTNER(gBattlerAttacker)))
            return TRUE;
        break;
    default:
        break;
    }

    return FALSE;
}

static enum CancelerResult CancelerNoTarget(struct BattleCalcValues *cv)
{
    enum MoveTarget moveTarget = GetBattlerMoveTargetType(cv->battlerAtk, cv->move);

    if (NoTargetPresent(gBattlerAttacker, gCurrentMove, moveTarget))
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
        return CANCELER_RESULT_FAILURE;
    }

    if (cv->battlerAtk == cv->battlerDef
     && moveTarget == TARGET_ALLY
     && gProtectStructs[BATTLE_PARTNER(cv->battlerAtk)].usedAllySwitch)
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
        return CANCELER_RESULT_FAILURE;
    }

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerTookAttack(struct BattleCalcValues *cv)
{
    if (gSpecialStatuses[cv->battlerDef].abilityRedirected)
    {
        gSpecialStatuses[cv->battlerDef].abilityRedirected = FALSE;
        BattleScriptCall(BattleScript_TookAttack);
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    }
    return CANCELER_RESULT_SUCCESS;
}

static bool32 CanMoveBeBlockedByTargetHelper(struct BattleCalcValues *cv, s32 movePriority)
{
    struct DamageContext ctx = {0};

    ctx.battlerAtk = cv->battlerAtk;
    ctx.battlerDef = cv->battlerDef;
    ctx.move = cv->move;
    ctx.moveType = GetBattleMoveType(cv->move);
    ctx.updateFlags = TRUE;
    ctx.runScript = TRUE;
    ctx.abilities[ctx.battlerAtk] = cv->abilities[cv->battlerAtk];
    ctx.abilities[ctx.battlerDef] = cv->abilities[cv->battlerDef];
    ctx.holdEffects[ctx.battlerAtk] = cv->holdEffects[cv->battlerAtk];
    ctx.holdEffects[ctx.battlerDef] = cv->holdEffects[cv->battlerDef];

    return CanMoveBeBlockedByTarget(&ctx, movePriority);
}

static enum CancelerResult CancelerTargetFailure(struct BattleCalcValues *cv)
{
    bool32 targetAvoidedAttack = FALSE;
    bool32 moveBouncedBack = FALSE; // for moves that target the opposing field
    enum MoveTarget moveTarget = GetBattlerMoveTargetType(cv->battlerAtk, cv->move);
    s32 movePriority = GetChosenMovePriority(cv->battlerAtk, cv->abilities[cv->battlerAtk]);

    while (gBattleStruct->eventState.atkCancelerBattler < MAX_BATTLERS_COUNT)
    {
        if (IsDoubleBattle())
            cv->battlerDef = GetTargetBySlot(cv->battlerAtk, gBattleStruct->eventState.atkCancelerBattler);
        else
            cv->battlerDef = gBattleStruct->eventState.atkCancelerBattler;

        gBattleStruct->eventState.atkCancelerBattler++;

        if (ShouldSkipFailureCheckOnBattler(cv->battlerAtk, cv->battlerDef, FALSE))
            continue;

        if (moveTarget == TARGET_OPPONENTS_FIELD)
        {
            if (!IsSemiInvulnerable(cv->battlerDef, CHECK_ALL) && CanBattlerBounceBackMove(cv))
            {
                gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_FAILED;
                moveBouncedBack = TRUE;
            }
        }
        else if (IsBattlerUnaffectedByMove(cv->battlerDef)) // immune but targeted
        {
            BattleScriptCall(BattleScript_DoesntAffectScripting);
            targetAvoidedAttack = TRUE;
        }
        else if (!IsBattlerAlive(cv->battlerDef))
        {
            gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_FAILED;
            continue;
        }
        else if (!CanBreakThroughSemiInvulnerablity(cv->battlerAtk, cv->battlerDef, cv->abilities[cv->battlerAtk], cv->abilities[cv->battlerDef], cv->move))
        {
            gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_FAILED;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_AVOIDED_ATK;
            if (GetMoveEffect(cv->move) == EFFECT_FLING)
                BattleScriptCall(BattleScript_TargetAvoidsAttackConsumeFlingItem);
            else
                BattleScriptCall(BattleScript_TargetAvoidsAttack);
            targetAvoidedAttack = TRUE;
        }
        else if (IsBattlerProtected(cv))
        {
            SetOrClearRageVolatile();
            gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_MISSED;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PROTECTED;
            if (GetMoveEffect(cv->move) == EFFECT_FLING)
                BattleScriptCall(BattleScript_TargetAvoidsAttackConsumeFlingItem);
            else
                BattleScriptCall(BattleScript_TargetAvoidsAttack);
            targetAvoidedAttack = TRUE;
        }
        else if (CanBattlerBounceBackMove(cv))
        {
            gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_FAILED;
        }
        else if (CanMoveBeBlockedByTargetHelper(cv, movePriority))
        {
            gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_MISSED;
            gSpecialStatuses[cv->battlerDef].updateStallMons = TRUE;
            targetAvoidedAttack = TRUE;
        }
        else if (GetMoveEffect(cv->move) == EFFECT_SYNCHRONOISE && !DoBattlersShareType(cv->battlerAtk, cv->battlerDef))
        {
            gBattleStruct->moveResultFlags[cv->battlerDef] = MOVE_RESULT_NO_EFFECT;
            BattleScriptCall(BattleScript_ItDoesntAffectFoe);
            targetAvoidedAttack = TRUE;
        }
        else if (GetMoveEffect(cv->move) == EFFECT_SKY_DROP
              && !gProtectStructs[cv->battlerAtk].chargingTurn
              && IS_BATTLER_OF_TYPE(cv->battlerDef, TYPE_FLYING))
        {
            gBattleStruct->moveResultFlags[cv->battlerDef] = MOVE_RESULT_NO_EFFECT;
            BattleScriptCall(BattleScript_SkyDropFlyingType);
            targetAvoidedAttack = TRUE;
        }
        else
        {
            struct DamageContext ctx = {0};
            ctx.battlerAtk = cv->battlerAtk;
            ctx.battlerDef = cv->battlerDef;
            ctx.move = cv->move;
            ctx.moveType = GetBattleMoveType(cv->move);
            ctx.updateFlags = TRUE;
            ctx.runScript = TRUE;
            ctx.abilities[ctx.battlerAtk] = cv->abilities[cv->battlerAtk];
            ctx.abilities[ctx.battlerDef] = cv->abilities[cv->battlerDef];
            ctx.holdEffects[ctx.battlerAtk] = cv->holdEffects[cv->battlerAtk];
            ctx.holdEffects[ctx.battlerDef] = cv->holdEffects[cv->battlerDef];

            if (CalcTypeEffectivenessMultiplier(&ctx) == UQ_4_12(0.0))
                gSpecialStatuses[cv->battlerDef].updateStallMons = TRUE;

            if (ctx.abilityBlocked)
            {
                gBattleStruct->moveResultFlags[cv->battlerDef] = MOVE_RESULT_FAILED;
                gBattlerAbility = cv->battlerDef;
                RecordAbilityBattle(cv->battlerDef, cv->abilities[cv->battlerDef]);
                BattleScriptCall(BattleScript_NoEffectivenessAbility);
                targetAvoidedAttack = TRUE;
            }
            else if (ctx.airBalloonBlocked)
            {
                gBattleStruct->moveResultFlags[cv->battlerDef] = MOVE_RESULT_FAILED;
                BattleScriptCall(BattleScript_DoesntAffectScripting);
                targetAvoidedAttack = TRUE;
            }
        }

        if (targetAvoidedAttack)
        {
            gLastLandedMoves[cv->battlerDef] = 0; // Might need investigation on what exactly clears is
            gLastHitByType[cv->battlerDef] = 0;
            gBattleScripting.battler = cv->battlerDef;
            gBattleStruct->pledgeMove = FALSE;
            CancelMultiTurnMoves(cv->battlerAtk);
            return CANCELER_RESULT_RUN_SCRIPT;
        }
    }

    if (IsDoubleBattle())
    {
        if (moveTarget == TARGET_BOTH)
            gBattleStruct->numSpreadTargets = CountAliveMonsInBattle(BATTLE_ALIVE_EXCEPT_BATTLER_SIDE, gBattlerAttacker);
        else if (moveTarget == TARGET_FOES_AND_ALLY)
            gBattleStruct->numSpreadTargets = CountAliveMonsInBattle(BATTLE_ALIVE_EXCEPT_BATTLER, gBattlerAttacker);
    }

    cv->battlerDef = gBattlerTarget;
    gBattleStruct->eventState.atkCancelerBattler = 0;

    if (moveBouncedBack)
    {
        gBattlescriptCurrInstr = BattleScript_MoveEnd;
        return CANCELER_RESULT_FAILURE;
    }

    return CANCELER_RESULT_SUCCESS;
}

static bool32 CantFullyProtectFromMove(enum BattlerId battlerDef)
{
    if (MoveIgnoresProtect(gCurrentMove))
        return FALSE;
    if (!IsZMove(gCurrentMove) && !IsMaxMove(gCurrentMove))
        return FALSE;
    return GetProtectType(gProtectStructs[battlerDef].protected) == PROTECT_TYPE_SINGLE
        && gProtectStructs[battlerDef].protected != PROTECT_MAX_GUARD;
}

static enum CancelerResult CancelerNotFullyProtected(struct BattleCalcValues *cv)
{
    while (gBattleStruct->eventState.atkCancelerBattler < gBattlersCount)
    {
        enum BattlerId battlerDef = gBattleStruct->eventState.atkCancelerBattler++;

        if (ShouldSkipFailureCheckOnBattler(cv->battlerAtk, battlerDef, TRUE))
            continue;

        if (CantFullyProtectFromMove(battlerDef))
        {
            BattleScriptCall(BattleScript_CouldntFullyProtect);
            gBattleScripting.battler = battlerDef;
            return CANCELER_RESULT_RUN_SCRIPT;
        }
    }

    gBattleStruct->eventState.atkCancelerBattler = 0;
    return CANCELER_RESULT_SUCCESS;
}

static bool32 IsMoveParentalBondAffected(struct BattleCalcValues *cv)
{
    enum BattleMoveEffects effect = GetMoveEffect(cv->move);

    if (cv->abilities[cv->battlerAtk] != ABILITY_PARENTAL_BOND
     || gBattleStruct->numSpreadTargets > 1
     || IsMoveParentalBondBanned(cv->move)
     || GetMoveCategory(cv->move) == DAMAGE_CATEGORY_STATUS
     || gBattleMoveEffects[effect].twoTurnEffect
     || effect == EFFECT_OHKO
     || GetActiveGimmick(cv->battlerAtk) == GIMMICK_Z_MOVE
     || (effect == EFFECT_PRESENT && gBattleStruct->presentBasePower == 0)
     || cv->move == MOVE_STRUGGLE)
        return FALSE;
    return TRUE;
}

static void SetPossibleNewSmartTarget(u32 move)
{
    if (!IsBattlerUnaffectedByMove(gBattlerTarget)
     || !CanTargetPartner(gBattlerAttacker, gBattlerTarget)
     || IsAffectedByFollowMe(gBattlerAttacker, GetBattlerSide(gBattlerTarget), move)
     || GetBattlerMoveTargetType(gBattlerAttacker, move) != TARGET_SMART)
        return;

    enum BattlerId partner = BATTLE_PARTNER(gBattlerTarget);
    if (!IsBattlerUnaffectedByMove(partner))
        gBattlerTarget = partner;
}

static void SetRandomMultiHitCounter()
{
    if (GetBattlerHoldEffect(gBattlerAttacker) == HOLD_EFFECT_LOADED_DICE)
        gMultiHitCounter = RandomUniform(RNG_LOADED_DICE, 4, 5);
    else if (GetConfig(B_MULTI_HIT_CHANCE) >= GEN_5)
        gMultiHitCounter = RandomWeighted(RNG_HITS, 0, 0, 7, 7, 3, 3); // 35%: 2 hits, 35%: 3 hits, 15% 4 hits, 15% 5 hits.
    else
        gMultiHitCounter = RandomWeighted(RNG_HITS, 0, 0, 3, 3, 1, 1); // 37.5%: 2 hits, 37.5%: 3 hits, 12.5% 4 hits, 12.5% 5 hits.
}

static enum CancelerResult CancelerMultihitMoves(struct BattleCalcValues *cv)
{
    SetPossibleNewSmartTarget(cv->move);

    if (IsBattlerUnaffectedByMove(gBattlerTarget)) // Dragon Darts can still hit partner
    {
        gMultiHitCounter = 0;
    }
    else if (IsMultiHitMove(cv->move))
    {
        enum Ability ability = cv->abilities[cv->battlerAtk];

        if (ability == ABILITY_SKILL_LINK)
        {
            gMultiHitCounter = 5;
        }
        else if (GetMoveEffect(cv->move) == EFFECT_SPECIES_POWER_OVERRIDE
              && gBattleMons[cv->battlerAtk].species == GetMoveSpeciesPowerOverride_Species(cv->move))
        {
            gMultiHitCounter = GetMoveSpeciesPowerOverride_NumOfHits(cv->move);
        }
        else
        {
            SetRandomMultiHitCounter();
        }

        PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
    }
    else if (GetMoveStrikeCount(cv->move) > 1)
    {
        if (GetMoveEffect(cv->move) == EFFECT_POPULATION_BOMB && GetBattlerHoldEffect(cv->battlerAtk) == HOLD_EFFECT_LOADED_DICE)
        {
            gMultiHitCounter = RandomUniform(RNG_LOADED_DICE, 4, 10);
        }
        else
        {
            gMultiHitCounter = GetMoveStrikeCount(cv->move);
        }

        PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 3, 0)
    }
    else if (GetMoveEffect(cv->move) == EFFECT_BEAT_UP)
    {
        struct Pokemon* party = GetBattlerParty(cv->battlerAtk);
        int i;
        gBattleStruct->beatUpSlot = 0;
        gMultiHitCounter = 0;
        memset(gBattleStruct->beatUpSpecies, 0xFF, sizeof(gBattleStruct->beatUpSpecies));

        for (i = 0; i < PARTY_SIZE; i++)
        {
            enum Species species = GetMonData(&party[i], MON_DATA_SPECIES);
            if (species != SPECIES_NONE
             && GetMonData(&party[i], MON_DATA_HP)
             && !GetMonData(&party[i], MON_DATA_IS_EGG)
             && !GetMonData(&party[i], MON_DATA_STATUS))
            {
                if (GetConfig(B_BEAT_UP) >= GEN_5)
                    gBattleStruct->beatUpSpecies[gMultiHitCounter] = species;
                else
                    gBattleStruct->beatUpSpecies[gMultiHitCounter] = i;
                gMultiHitCounter++;
            }
        }

        PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
    }
    else if (IsMoveParentalBondAffected(cv))
    {
        gSpecialStatuses[gBattlerAttacker].parentalBondState = PARENTAL_BOND_1ST_HIT;
        gMultiHitCounter = 2;
        PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
    }
    else
    {
        gMultiHitCounter = 0;
    }

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult (*const sMoveSuccessOrderCancelers[])(struct BattleCalcValues *cv) =
{
    [CANCELER_CLEAR_FLAGS] = CancelerClearFlags,
    [CANCELER_STANCE_CHANGE_1] = CancelerStanceChangeOne,
    [CANCELER_SKY_DROP] = CancelerSkyDrop,
    [CANCELER_RECHARGE] = CancelerRecharge,
    [CANCELER_CHILLY_RECEPTION] = CancelerChillyReception,
    [CANCELER_ASLEEP_OR_FROZEN] = CancelerAsleepOrFrozen,
    [CANCELER_OBEDIENCE] = CancelerObedience,
    [CANCELER_POWER_POINTS] = CancelerPowerPoints,
    [CANCELER_TRUANT] = CancelerTruant,
    [CANCELER_FOCUS_GEN5] = CancelerFocusGen5,
    [CANCELER_FLINCH] = CancelerFlinch,
    [CANCELER_DISABLED] = CancelerDisabled,
    [CANCELER_VOLATILE_BLOCKED] = CancelerVolatileBlocked,
    [CANCELER_TAUNTED] = CancelerTaunted,
    [CANCELER_IMPRISONED] = CancelerImprisoned,
    [CANCELER_CONFUSED] = CancelerConfused,
    [CANCELER_GHOST] = CancelerGhost,
    [CANCELER_PARALYZED] = CancelerParalyzed,
    [CANCELER_INFATUATION] = CancelerInfatuation,
    [CANCELER_Z_MOVES] = CancelerZMoves,
    [CANCELER_CHOICE_LOCK] = CancelerChoiceLock,
    [CANCELER_CALLSUBMOVE] = CancelerCallSubmove,
    [CANCELER_THAW] = CancelerThaw,
    [CANCELER_STANCE_CHANGE_2] = CancelerStanceChangeTwo,
    [CANCELER_ATTACKSTRING] = CancelerAttackstring,
    [CANCELER_SET_TARGETS] = CancelerSetTargets,
    [CANCELER_PPDEDUCTION] = CancelerPPDeduction,
    [CANCELER_SKY_BATTLE] = CancelerSkyBattle,
    [CANCELER_WEATHER_PRIMAL] = CancelerWeatherPrimal,
    [CANCELER_FOCUS_PRE_GEN5] = CancelerFocusPreGen5,
    [CANCELER_BIDE] = CancelerBide,
    [CANCELER_MOVE_FAILURE] = CancelerMoveFailure,
    [CANCELER_MOVE_EFFECT_FAILURE_TARGET] = CancelerMoveEffectFailureTarget,
    [CANCELER_POWDER_STATUS] = CancelerPowderStatus,
    [CANCELER_PRIORITY_BLOCK] = CancelerPriorityBlock,
    [CANCELER_EXPLODING_DAMP] = CancelerExplodingDamp,
    [CANCELER_PROTEAN] = CancelerProtean,
    [CANCELER_CHARGING] = CancelerCharging,
    [CANCELER_SNATCH] = CancelerSnatch,
    [CANCELER_EXPLOSION] = CancelerExplosion,
    [CANCELER_MOVE_SPECIFIC_MESSAGE] = CancelerMoveSpecificMessage,
    [CANCELER_NO_TARGET] = CancelerNoTarget,
    [CANCELER_TOOK_ATTACK] = CancelerTookAttack,
    [CANCELER_TARGET_FAILURE] = CancelerTargetFailure,
    [CANCELER_NOT_FULLY_PROTECTED] = CancelerNotFullyProtected,
    [CANCELER_MULTIHIT_MOVES] = CancelerMultihitMoves,
};

enum CancelerResult DoAttackCanceler(void)
{
    enum CancelerResult result = CANCELER_RESULT_SUCCESS;

    struct BattleCalcValues cv = {
        .battlerAtk = gBattlerAttacker,
        .battlerDef = gBattlerTarget,
        .move = gCurrentMove,
    };

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        cv.abilities[battler] = GetBattlerAbility(battler);
        cv.holdEffects[battler] = GetBattlerHoldEffect(battler);
    }

    while (gBattleStruct->eventState.atkCanceler < CANCELER_END && result == CANCELER_RESULT_SUCCESS)
    {
        result = sMoveSuccessOrderCancelers[gBattleStruct->eventState.atkCanceler](&cv);
        if (result != CANCELER_RESULT_RUN_SCRIPT)
            gBattleStruct->eventState.atkCanceler++;
    }

    if (result == CANCELER_RESULT_FAILURE)
        gBattleStruct->unableToUseMove = TRUE;
    return result;
}

// ========
// Move End
// ========

static enum MoveEndResult MoveEndSetValues(void)
{
    gBattleScripting.savedDmg += gBattleStruct->moveDamage[gBattlerTarget];
    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleStruct->eventState.moveEndBlock = 0;
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndProtectLikeEffect(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    u32 temp = 0;
    enum Ability abilityAtk = GetBattlerAbility(gBattlerAttacker);
    enum HoldEffect holdEffectAtk = GetBattlerHoldEffect(gBattlerAttacker);
    enum ProtectMethod method = gProtectStructs[gBattlerTarget].protected;

    if (gProtectStructs[gBattlerAttacker].chargingTurn
     || !IsBattlerAlive(gBattlerAttacker)
     || CanBattlerAvoidContactEffects(gBattlerAttacker, gBattlerTarget, abilityAtk, holdEffectAtk, gCurrentMove))
    {
        gBattleScripting.moveendState++;
        return result;
    }

    if (method != PROTECT_MAX_GUARD
     && (abilityAtk == ABILITY_UNSEEN_FIST || abilityAtk == ABILITY_PIERCING_DRILL)
     && IsMoveMakingContact(gBattlerAttacker, gBattlerTarget, abilityAtk, holdEffectAtk, gCurrentMove))
    {
        gBattleScripting.moveendState++;
        return result;
    }

    switch (method)
    {
    case PROTECT_SPIKY_SHIELD:
        if (!IsAbilityAndRecord(gBattlerAttacker, GetBattlerAbility(gBattlerAttacker), ABILITY_MAGIC_GUARD))
        {
            SetPassiveDamageAmount(gBattlerAttacker, GetNonDynamaxMaxHP(gBattlerAttacker) / 8);
            PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_SPIKY_SHIELD);
            BattleScriptCall(BattleScript_SpikyShieldEffect);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case PROTECT_KINGS_SHIELD:
        SWAP(gBattlerAttacker, gBattlerTarget, temp); // gBattlerTarget and gBattlerAttacker are swapped in order to activate Defiant, if applicable
        if (B_KINGS_SHIELD_LOWER_ATK >= GEN_8)
            gBattleScripting.moveEffect = MOVE_EFFECT_ATK_MINUS_1;
        else
            gBattleScripting.moveEffect = MOVE_EFFECT_ATK_MINUS_2;
        BattleScriptCall(BattleScript_KingsShieldEffect);
        result = MOVEEND_RESULT_RUN_SCRIPT;
        break;
    case PROTECT_BANEFUL_BUNKER:
        if (CanBePoisoned(gBattlerTarget, gBattlerAttacker, GetBattlerAbility(gBattlerTarget), GetBattlerAbility(gBattlerAttacker)))
        {
            gBattleScripting.moveEffect = MOVE_EFFECT_POISON;
            BattleScriptCall(BattleScript_BanefulBunkerEffect);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case PROTECT_BURNING_BULWARK:
        if (CanBeBurned(gBattlerTarget, gBattlerAttacker, GetBattlerAbility(gBattlerAttacker)))
        {
            gBattleScripting.moveEffect = MOVE_EFFECT_BURN;
            BattleScriptCall(BattleScript_BanefulBunkerEffect);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case PROTECT_OBSTRUCT:
        SWAP(gBattlerAttacker, gBattlerTarget, temp); // gBattlerTarget and gBattlerAttacker are swapped in order to activate Defiant, if applicable
        gBattleScripting.moveEffect = MOVE_EFFECT_DEF_MINUS_2;
        BattleScriptCall(BattleScript_KingsShieldEffect);
        result = MOVEEND_RESULT_RUN_SCRIPT;
        break;
    case PROTECT_SILK_TRAP:
        SWAP(gBattlerAttacker, gBattlerTarget, temp); // gBattlerTarget and gBattlerAttacker are swapped in order to activate Defiant, if applicable
        gBattleScripting.moveEffect = MOVE_EFFECT_SPD_MINUS_1;
        BattleScriptCall(BattleScript_KingsShieldEffect);
        result = MOVEEND_RESULT_RUN_SCRIPT;
        break;
    default:
        break;
    }

    // Not strictly a protect effect, but works the same way
    if (IsBattlerUsingBeakBlast(gBattlerTarget)
     && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
     && CanBeBurned(gBattlerAttacker, gBattlerAttacker, GetBattlerAbility(gBattlerAttacker)))
    {
        gBattleMons[gBattlerAttacker].status1 = STATUS1_BURN;
        BtlController_EmitSetMonData(gBattlerAttacker, B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gBattlerAttacker].status1), &gBattleMons[gBattlerAttacker].status1);
        MarkBattlerForControllerExec(gBattlerAttacker);
        BattleScriptCall(BattleScript_BeakBlastBurn);
        result = MOVEEND_RESULT_RUN_SCRIPT;
    }

    gBattleScripting.moveendState++;
    return result;
}

static void SetHealScript(s32 healAmount)
{
    healAmount = GetDrainedBigRootHp(gBattlerAttacker, healAmount);
    if (GetBattlerAbility(gBattlerTarget) == ABILITY_LIQUID_OOZE
     && (GetMoveEffect(gCurrentMove) != EFFECT_DREAM_EATER || GetConfig(B_DREAM_EATER_LIQUID_OOZE) >= GEN_5))
    {
        SetPassiveDamageAmount(gBattlerAttacker, healAmount);
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABSORB_OOZE;
        BattleScriptCall(BattleScript_EffectAbsorbLiquidOoze);
    }
    else if (!IsBattlerAtMaxHp(gBattlerAttacker) || GetConfig(B_ABSORB_MESSAGE) < GEN_5)
    {
        SetHealAmount(gBattlerAttacker, healAmount);
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABSORB;
        BattleScriptCall(BattleScript_EffectAbsorb);
    }
}

static enum MoveEndResult MoveEndAbsorb(void)
{
    if (gBattleStruct->unableToUseMove)
    {
        gBattleScripting.moveendState++;
        return MOVEEND_RESULT_CONTINUE;
    }

    if (IsExplosionMove(gCurrentMove)
     && (gBattleStruct->doneDoublesSpreadHit || !IsDoubleSpreadMove())
     && !IsBattlerAlive(gBattlerAttacker)
     && !gBattleStruct->battlerState[gBattlerAttacker].notOnField)
    {
        gBattleStruct->passiveHpUpdate[gBattlerAttacker] = 0;
        BattleScriptCall(BattleScript_FaintAttackerForExplosion);
        gBattleScripting.moveendState++;
        return MOVEEND_RESULT_RUN_SCRIPT;
    }

    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    enum BattleMoveEffects moveEffect = GetMoveEffect(gCurrentMove);

    switch (moveEffect)
    {
    case EFFECT_STRENGTH_SAP:
        if (gBattleStruct->passiveHpUpdate[gBattlerAttacker] > 0)
        {
            s32 healAmount = gBattleStruct->passiveHpUpdate[gBattlerAttacker];
            SetHealScript(healAmount);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_ABSORB:
    case EFFECT_DREAM_EATER:
        if (gBattleStruct->moveDamage[gBattlerTarget] > 0
         && IsBattlerTurnDamaged(gBattlerTarget, INCLUDING_SUBSTITUTES)
         && IsBattlerAlive(gBattlerAttacker))
        {
            s32 healAmount = (gBattleStruct->moveDamage[gBattlerTarget] * GetMoveAbsorbPercentage(gCurrentMove) / 100);
            SetHealScript(healAmount);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_MAX_HP_50_RECOIL:
        if (IsBattlerAlive(gBattlerAttacker)
         && !gBattleStruct->unableToUseMove
         && (gBattleStruct->doneDoublesSpreadHit || !IsDoubleSpreadMove())
         && !gSpecialStatuses[gBattlerAttacker].mindBlownRecoil
         && !(gBattleStruct->moveResultFlags[gBattlerTarget] & MOVE_RESULT_FAILED)
         && !IsAbilityAndRecord(gBattlerAttacker, GetBattlerAbility(gBattlerAttacker), ABILITY_MAGIC_GUARD))
        {
            s32 recoil = (GetNonDynamaxMaxHP(gBattlerAttacker) + 1) / 2; // Half of Max HP Rounded UP
            SetPassiveDamageAmount(gBattlerAttacker, recoil);
            gSpecialStatuses[gBattlerAttacker].mindBlownRecoil = TRUE;
            TryUpdateEvolutionTracker(IF_RECOIL_DAMAGE_GE, gBattleStruct->passiveHpUpdate[gBattlerAttacker], MOVE_NONE);
            BattleScriptCall(BattleScript_MaxHp50Recoil);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    default:
        break;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndRage(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (gBattleMons[gBattlerTarget].volatiles.rage
        && IsBattlerAlive(gBattlerTarget)
        && gBattlerAttacker != gBattlerTarget
        && !IsBattlerAlly(gBattlerAttacker, gBattlerTarget)
        && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
        && !IsBattleMoveStatus(gCurrentMove)
        && CompareStat(gBattlerTarget, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, GetBattlerAbility(gBattlerTarget)))
    {
        SET_STATCHANGER(STAT_ATK, 1, FALSE);
        BattleScriptCall(BattleScript_RageIsBuilding);
        result = MOVEEND_RESULT_RUN_SCRIPT;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndAbilities(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    enum Ability targetAbility = GetBattlerAbility(gBattlerTarget);

    if (AbilityBattleEffects(ABILITYEFFECT_MOVE_END, gBattlerTarget, targetAbility, 0, TRUE))
        result = MOVEEND_RESULT_RUN_SCRIPT;
    else if (TryClearIllusion(gBattlerTarget, targetAbility))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndFormChangeOnHit(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (AbilityBattleEffects(ABILITYEFFECT_FORM_CHANGE_ON_HIT, gBattlerTarget, GetBattlerAbility(gBattlerTarget), 0, TRUE))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndAbilitiesAttacker(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (AbilityBattleEffects(ABILITYEFFECT_MOVE_END_ATTACKER, gBattlerAttacker, 0, 0, TRUE))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndQueueDancer(void)
{
    if (!IsDanceMove(gCurrentMove)
     || IsBattlerUnaffectedByMove(gBattlerTarget)
     || gBattleStruct->unableToUseMove
     || gSpecialStatuses[gBattlerAttacker].dancerUsedMove
     || gBattleStruct->snatchedMoveIsUsed
     || gBattleStruct->bouncedMoveIsUsed)
    {
        gBattleScripting.moveendState++;
        return MOVEEND_RESULT_CONTINUE;
    }

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (battler == gBattlerAttacker)
            continue;

        if (GetBattlerAbility(battler) == ABILITY_DANCER)
            gBattleMons[battler].volatiles.activateDancer = TRUE;
    }

    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndStatusImmunityAbilities(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (AbilityBattleEffects(ABILITYEFFECT_IMMUNITY, battler, 0, 0, TRUE))
            result = MOVEEND_RESULT_RUN_SCRIPT;
    }

    if (result == MOVEEND_RESULT_CONTINUE)
        gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndAttackerInvisible(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (IsSemiInvulnerable(gBattlerAttacker, CHECK_ALL)
     && gHitMarker & (HITMARKER_NO_ANIMATIONS | HITMARKER_DISABLE_ANIMATION))
    {
        BtlController_EmitSpriteInvisibility(gBattlerAttacker, B_COMM_TO_CONTROLLER, TRUE);
        MarkBattlerForControllerExec(gBattlerAttacker);
        result = MOVEEND_RESULT_BREAK;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndAttackerVisible(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (IsBattlerUnaffectedByMove(gBattlerTarget)
        || !IsSemiInvulnerable(gBattlerAttacker, CHECK_ALL)
        || (gBattleStruct->unableToUseMove && gBattleMons[gBattlerAttacker].volatiles.semiInvulnerable != STATE_SKY_DROP_TARGET))
    {
        BtlController_EmitSpriteInvisibility(gBattlerAttacker, B_COMM_TO_CONTROLLER, FALSE);
        MarkBattlerForControllerExec(gBattlerAttacker);
        gBattleMons[gBattlerAttacker].volatiles.semiInvulnerable = STATE_NONE;
        gSpecialStatuses[gBattlerAttacker].restoredBattlerSprite = TRUE;
        gBattleScripting.moveendState++;
        return MOVEEND_RESULT_BREAK;
    }
    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndTargetVisible(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (!gSpecialStatuses[gBattlerTarget].restoredBattlerSprite
     && gBattlerTarget < gBattlersCount
     && !IsSemiInvulnerable(gBattlerTarget, CHECK_ALL))
    {
        BtlController_EmitSpriteInvisibility(gBattlerTarget, B_COMM_TO_CONTROLLER, FALSE);
        MarkBattlerForControllerExec(gBattlerTarget);
        gSpecialStatuses[gBattlerTarget].restoredBattlerSprite = TRUE;
        gBattleMons[gBattlerTarget].volatiles.semiInvulnerable = STATE_NONE;
        result = MOVEEND_RESULT_BREAK;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndItemEffectsTarget(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    enum HoldEffect holdEffect = GetBattlerHoldEffect(gBattlerTarget);

    if (ItemBattleEffects(gBattlerTarget, gBattlerAttacker, holdEffect, IsOnTargetHitActivation)
     || ItemBattleEffects(gBattlerTarget, gBattlerAttacker, holdEffect, IsOnStatusChangeActivation))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndItemEffectsAttacker1(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    enum HoldEffect holdEffect = GetBattlerHoldEffect(gBattlerAttacker);

    if (ItemBattleEffects(gBattlerAttacker, gBattlerTarget, holdEffect, IsOnAttackerAfterHitActivation)
     || ItemBattleEffects(gBattlerAttacker, gBattlerTarget, holdEffect, IsOnStatusChangeActivation)
     || ItemBattleEffects(gBattlerAttacker, gBattlerTarget, holdEffect, IsOnHpThresholdActivation))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndSymbiosis(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if ((gSpecialStatuses[battler].berryReduced
              || (GetConfig(B_SYMBIOSIS_GEMS) >= GEN_7 && gSpecialStatuses[battler].gemBoost))
            && TryTriggerSymbiosis(battler, BATTLE_PARTNER(battler)))
        {
            BestowItem(BATTLE_PARTNER(battler), battler);
            gLastUsedAbility = gBattleMons[BATTLE_PARTNER(battler)].ability;
            gEffectBattler = battler;
            gBattleScripting.battler = gBattlerAbility = BATTLE_PARTNER(battler);
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_SymbiosisActivates;
            result = MOVEEND_RESULT_RUN_SCRIPT;
            break;
        }
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndSubstitute(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        if (gBattleMons[i].volatiles.substituteHP == 0)
            gBattleMons[i].volatiles.substitute = FALSE;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndFaintBlock(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    do
    {
        switch (gBattleStruct->eventState.moveEndBlock)
        {
        case FAINT_BLOCK_FINAL_GAMBIT:
            if (GetMoveEffect(gCurrentMove) == EFFECT_FINAL_GAMBIT
             && IsBattlerAlive(gBattlerAttacker)
             && !gBattleStruct->unableToUseMove
             && (gBattleStruct->doneDoublesSpreadHit || !IsDoubleSpreadMove())
             && !IsBattlerUnaffectedByMove(gBattlerTarget))
            {
                BattleScriptCall(BattleScript_FinalGambit);
                result = MOVEEND_RESULT_RUN_SCRIPT;
            }
            gBattleStruct->eventState.moveEndBlock++;
            break;
        case FAINT_BLOCK_CHECK_TARGET_FAINTED: // Stop if target already ran the block / is alive or absent
            if (IsBattlerAlive(gBattlerTarget)
             || gBattlerTarget >= gBattlersCount
             || (gAbsentBattlerFlags & 1u << gBattlerTarget)
             || gBattleStruct->battlerState[gBattlerTarget].notOnField)
            {
                gBattleScripting.moveendState++;
                return MOVEEND_RESULT_CONTINUE;
            }

            gBattleStruct->eventState.moveEndBlock++;
            break;
        case FAINT_BLOCK_END_NEUTRALIZING_GAS:
            if (gBattleMons[gBattlerTarget].volatiles.neutralizingGas)
            {
                gBattleMons[gBattlerTarget].volatiles.neutralizingGas = FALSE;
                if (!IsNeutralizingGasOnField())
                {
                    BattleScriptCall(BattleScript_NeutralizingGasExits);
                    result = MOVEEND_RESULT_RUN_SCRIPT;
                }
            }
            gBattleStruct->eventState.moveEndBlock++;
            break;
        case FAINT_BLOCK_TRY_DESTINY_BOND: // Checked before FAINT_BLOCK_FAINT_TARGET but occurs after since volatiles are cleared on faint
            if (gBattleMons[gBattlerTarget].volatiles.destinyBond
             && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(gBattlerAttacker)
             && GetActiveGimmick(gBattlerAttacker) != GIMMICK_DYNAMAX
             && !IsBattlerAlly(gBattlerAttacker, gBattlerTarget))
            {
                gBattleStruct->tryDestinyBond = TRUE;
            }
            gBattleStruct->eventState.moveEndBlock++;
            break;
        case FAINT_BLOCK_TRY_GRUDGE: // Checked before FAINT_BLOCK_FAINT_TARGET but occurs after since volatiles are cleared on faint
            if (gBattleMons[gBattlerTarget].volatiles.grudge
             && IsBattlerTurnDamaged(gBattlerTarget, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(gBattlerAttacker)
             && !IsBattlerAlly(gBattlerAttacker, gBattlerTarget)
             && !IsZMove(gCurrentMove)
             && gCurrentMove != MOVE_STRUGGLE
             && GetMoveEffect(gCurrentMove) != EFFECT_FUTURE_SIGHT)
            {
                gBattleStruct->tryGrudge = TRUE;
            }
            gBattleStruct->eventState.moveEndBlock++;
            break;
        case FAINT_BLOCK_FAINT_TARGET:
            gBattlerFainted = gBattlerTarget;
            TryUpdateEvolutionTracker(IF_DEFEAT_X_WITH_ITEMS, 1, MOVE_NONE);
            TryDeactivateSleepClause(GetBattlerSide(gBattlerTarget), gBattlerPartyIndexes[gBattlerTarget]);
            gHitMarker |= HITMARKER_FAINTED(gBattlerTarget);
            gBattleStruct->eventState.faintedAction = 0;
            if (IsOnPlayerSide(gBattlerTarget))
            {
                gHitMarker |= HITMARKER_PLAYER_FAINTED;
                if (gBattleResults.playerFaintCounter < 255)
                    gBattleResults.playerFaintCounter++;
                AdjustFriendshipOnBattleFaint(gBattlerTarget);
                gSideTimers[B_SIDE_PLAYER].retaliateTimer = 2;
            }
            else
            {
                if (gBattleResults.opponentFaintCounter < 255)
                    gBattleResults.opponentFaintCounter++;
                gBattleResults.lastOpponentSpecies = GetMonData(GetBattlerMon(gBattlerTarget), MON_DATA_SPECIES);
                gSideTimers[B_SIDE_OPPONENT].retaliateTimer = 2;
            }
            BattleScriptCall(BattleScript_FaintBattler);
            result = MOVEEND_RESULT_RUN_SCRIPT;
            gBattleStruct->eventState.moveEndBlock++;
            break;
        case FAINT_BLOCK_DO_DESTINY_BOND:
            if (gBattleStruct->tryDestinyBond)
            {
                gBattleStruct->passiveHpUpdate[gBattlerAttacker] = gBattleMons[gBattlerAttacker].hp;
                BattleScriptCall(BattleScript_DestinyBondTakesLife);
                result = MOVEEND_RESULT_RUN_SCRIPT;
            }
            gBattleStruct->eventState.moveEndBlock++;
            break;
        case FAINT_BLOCK_DO_GRUDGE:
            if (gBattleStruct->tryGrudge)
            {
                u32 moveIndex = gBattleStruct->chosenMovePositions[gBattlerAttacker];

                gBattleMons[gBattlerAttacker].pp[moveIndex] = 0;
                BtlController_EmitSetMonData(gBattlerAttacker, B_COMM_TO_CONTROLLER, moveIndex + REQUEST_PPMOVE1_BATTLE, 0, sizeof(gBattleMons[gBattlerAttacker].pp[moveIndex]), &gBattleMons[gBattlerAttacker].pp[moveIndex]);
                MarkBattlerForControllerExec(gBattlerAttacker);
                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleMons[gBattlerAttacker].moves[moveIndex])
                BattleScriptCall(BattleScript_GrudgeTakesPp);
                result = MOVEEND_RESULT_RUN_SCRIPT;
            }
            gBattleStruct->eventState.moveEndBlock++;
            break;
        case FAINT_BLOCK_COUNT: // Clear bits for other potential fainting targets
            gBattleStruct->tryDestinyBond = FALSE;
            gBattleStruct->tryGrudge = FALSE;
            gBattleStruct->eventState.moveEndBlock = 0;
            break;
        }

        if (result == MOVEEND_RESULT_RUN_SCRIPT)
            break;

    } while (gBattleStruct->eventState.moveEndBlock != 0);

    if (result == MOVEEND_RESULT_CONTINUE)
    {
        gBattleStruct->eventState.moveEndBlock = 0;
        gBattleScripting.moveendState++;
    }

    return result;
}

static enum MoveEndResult MoveEndUpdateLastMoves(void)
{
    if (!IsOnPlayerSide(gBattlerAttacker))
        UpdateStallMons();

    if (gBattleStruct->snatchedMoveIsUsed)
    {
        RestoreAttacker();
        RestoreTarget();
    }

    enum BattleMoveEffects originalEffect = GetMoveEffect(GetOriginallyUsedMove(gChosenMove));
    if (IsBattlerAlive(gBattlerAttacker) // Why do we need to check if user fainted? We just want to set with what move the target got hit
     && originalEffect != EFFECT_BATON_PASS
     && originalEffect != EFFECT_HEALING_WISH
     && originalEffect != EFFECT_LUNAR_DANCE)
    {
        if (!gBattleStruct->unableToUseMove)
        {
            if (!gSpecialStatuses[gBattlerAttacker].dancerUsedMove)
            {
                gLastMoves[gBattlerAttacker] = gChosenMove;
                gLastResultingMoves[gBattlerAttacker] = gCurrentMove;
                gLastUsedMoveType[gBattlerAttacker] = GetBattleMoveType(gCurrentMove);
            }
        }
        else
        {
            gLastMoves[gBattlerAttacker] = MOVE_UNAVAILABLE;
            gLastResultingMoves[gBattlerAttacker] = MOVE_UNAVAILABLE;
            gLastUsedMoveType[gBattlerAttacker] = 0;
        }

        if (IsBattlerAlive(gBattlerTarget))
            gLastHitBy[gBattlerTarget] = gBattlerAttacker; // Used by switch AI only

        if (!gBattleStruct->unableToUseMove
         && !IsBattlerUnaffectedByMove(gBattlerTarget)
         && IsBattlerAlive(gBattlerTarget))
        {
            if (gChosenMove == MOVE_UNAVAILABLE)
            {
                gLastLandedMoves[gBattlerTarget] = gChosenMove;
            }
            else
            {
                gLastLandedMoves[gBattlerTarget] = gCurrentMove;
                gLastHitByType[gBattlerTarget] = GetBattleMoveType(gCurrentMove);
                if (!gSpecialStatuses[gBattlerAttacker].dancerUsedMove)
                {
                    gLastUsedMove = gCurrentMove;
                    if (IsMaxMove(gCurrentMove))
                        gBattleStruct->dynamax.lastUsedBaseMove = gBattleStruct->dynamax.baseMoves[gBattlerAttacker];
                }
            }
        }
        else
        {
            gLastHitByType[gBattlerTarget] = TYPE_MYSTERY;
            gLastLandedMoves[gBattlerTarget] = MOVE_UNAVAILABLE;
        }
    }

    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndMirrorMove(void)
{
    if (!gBattleStruct->unableToUseMove
     && gBattlerAttacker != gBattlerTarget
     && IsBattlerAlive(gBattlerAttacker)
     && IsBattlerAlive(gBattlerTarget)
     && !IsMoveMirrorMoveBanned(GetOriginallyUsedMove(gChosenMove)))
    {
        gBattleStruct->lastTakenMove[gBattlerTarget] = gChosenMove;
        gBattleStruct->lastTakenMoveFrom[gBattlerTarget][gBattlerAttacker] = gChosenMove;
    }

    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndNextTarget(void)
{
    enum MoveTarget moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove);

    gBattleStruct->battlerState[gBattlerAttacker].targetsDone[gBattlerTarget] = TRUE;

    if (gBattleStruct->unableToUseMove || gProtectStructs[gBattlerAttacker].chargingTurn)
    {
        // unable to use move
    }
    else if (moveTarget == TARGET_USER_AND_ALLY)
    {
        enum BattlerId partner = BATTLE_PARTNER(gBattlerAttacker);
        if (partner != gBattlerTarget && IsBattlerAlive(partner))
        {
            gBattleStruct->moveTarget[gBattlerAttacker] = gBattlerTarget = partner;
            BattleScriptPush(GetMoveBattleScript(gCurrentMove));
            gBattlescriptCurrInstr = BattleScript_FlushMessageBox;
            gBattleScripting.moveendState = 0;
            return MOVEEND_RESULT_BREAK;
        }
    }
    else if (IsSpreadMove(moveTarget))
    {
        u32 nextTarget = GetNextTarget(moveTarget, FALSE);

        if (nextTarget != MAX_BATTLERS_COUNT)
        {
            gBattleStruct->moveTarget[gBattlerAttacker] = gBattlerTarget = nextTarget; // Fix for moxie spread moves
            gBattleScripting.moveendState = 0;
            BattleScriptPush(GetMoveBattleScript(gCurrentMove));
            gBattlescriptCurrInstr = BattleScript_FlushMessageBox;
            return MOVEEND_RESULT_BREAK;
        }
    }

    RecordLastUsedMoveBy(gBattlerAttacker, gCurrentMove);
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static void SortBattlersByRawSpeed(u8 battlers[])
{
    for (u32 i = 0; i < gBattlersCount; i++)
    {
        for (u32 j = 0; j < gBattlersCount; j++)
        {
            if (gBattleMons[battlers[i]].speed >= gBattleMons[battlers[j]].speed)
            {
                u32 temp = battlers[i];
                battlers[i] = battlers[j];
                battlers[j] = temp;
            }
        }
    }
}

static enum MoveEndResult MoveEndBouncedMove(void)
{
    if (gBattleStruct->bouncedMoveIsUsed)
    {
        RestoreAttacker();
        RestoreTarget();
        gBattleStruct->bouncedMoveIsUsed = FALSE;
    }

    if (gBattleStruct->magicBouncePending || gBattleStruct->magicCoatPending)
    {
        u8 battlers[MAX_BATTLERS_COUNT] = {0,1,2,3};
        enum MoveTarget moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove);

        if (moveTarget == TARGET_OPPONENTS_FIELD)
            SortBattlersByRawSpeed(battlers);

        for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
        {
            u32 bounceBattler = battlers[battler];

            if (gBattleStruct->magicBouncePending & 1u << bounceBattler)
            {
                gBattlerAbility = bounceBattler;
                gBattlescriptCurrInstr = GetMoveBattleScript(gCurrentMove);
                BattleScriptCall(BattleScript_MagicBounce);
            }
            else if (gBattleStruct->magicCoatPending & 1u << bounceBattler)
            {
                gBattlescriptCurrInstr = GetMoveBattleScript(gCurrentMove);
                BattleScriptCall(BattleScript_MagicCoat);
            }
            else
            {
                continue;
            }

            if (moveTarget == TARGET_OPPONENTS_FIELD)
            {
                gBattleStruct->magicBouncePending = 0;
                gBattleStruct->magicCoatPending = 0;
            }
            else
            {
                gBattleStruct->magicBouncePending &= ~(1u << bounceBattler);
                gBattleStruct->magicCoatPending &= ~(1u << bounceBattler);
            }

            SaveBattlerAttacker(gBattlerAttacker);
            SaveBattlerTarget(gBattlerTarget);
            gBattlerTarget = gBattlerAttacker;
            gBattlerAttacker = bounceBattler;
            gBattleStruct->bouncedMoveIsUsed = TRUE;

            ClearDamageCalcResults();
            gBattleStruct->eventState.atkCanceler = CANCELER_SET_TARGETS;
            gBattleStruct->eventState.atkCancelerBattler = 0;
            for (enum BattlerId i = B_BATTLER_0; i < gBattlersCount; i++)
                gBattleStruct->battlerState[gBattlerAttacker].targetsDone[i] = FALSE;
            gBattleStruct->moveTarget[gBattlerAttacker] = gBattlerTarget;
            gBattleScripting.moveendState = 0;
            gBattleScripting.animTurn = 0;
            gBattleScripting.animTargetsHit = 0;

            return MOVEEND_RESULT_RUN_SCRIPT;
        }
    }

    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndHpThresholdItemsTarget(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (gMultiHitCounter &&
        ItemBattleEffects(gBattlerTarget, gBattlerAttacker, GetBattlerHoldEffect(gBattlerTarget), IsOnHpThresholdActivation))
    {
        result = MOVEEND_RESULT_RUN_SCRIPT;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndMultihitMove(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (!IsBattlerUnaffectedByMove(gBattlerTarget)
     && !gBattleStruct->unableToUseMove
     && gMultiHitCounter)
    {
        enum MoveTarget target = GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove);
        gBattleStruct->preAttackEffectHappened = FALSE;
        gMultiHitCounter--;
        if (!IsBattlerAlive(gBattlerTarget) && target != TARGET_SMART)
            gMultiHitCounter = 0;

        gBattleScripting.multihitString[4]++;
        if (gMultiHitCounter == 0)
        {
            BattleScriptCall(BattleScript_MultiHitPrintStrings);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        else
        {
            if (target == TARGET_SMART
             && !IsAffectedByFollowMe(gBattlerAttacker, GetBattlerSide(gBattlerTarget), gCurrentMove)
             && !(gBattleStruct->moveResultFlags[BATTLE_PARTNER(gBattlerTarget)] & MOVE_RESULT_MISSED) // didn't miss the other target
             && CanTargetPartner(gBattlerAttacker, gBattlerTarget)
             && !IsBattlerUnaffectedByMove(BATTLE_PARTNER(gBattlerTarget)))
                gBattlerTarget = BATTLE_PARTNER(gBattlerTarget); // Target the partner in doubles for second hit.

            enum BattleMoveEffects chosenEffect = GetMoveEffect(gChosenMove);

            if (gBattleMons[gBattlerAttacker].hp
             && gBattleMons[gBattlerTarget].hp
             && (IsUsableWhileAsleepEffect(chosenEffect) || !(gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP))
             && !(gBattleMons[gBattlerAttacker].status1 & STATUS1_FREEZE))
            {
                if (gSpecialStatuses[gBattlerAttacker].parentalBondState)
                    gSpecialStatuses[gBattlerAttacker].parentalBondState--;

                gBattleScripting.animTargetsHit = 0;
                gBattleScripting.moveendState = 0;
                gSpecialStatuses[gBattlerAttacker].multiHitOn = TRUE;
                BattleScriptPush(GetMoveBattleScript(gCurrentMove));
                gBattlescriptCurrInstr = BattleScript_FlushMessageBox;
                return MOVEEND_RESULT_BREAK;
            }
            else
            {
                BattleScriptCall(BattleScript_MultiHitPrintStrings);
                result = MOVEEND_RESULT_RUN_SCRIPT;
            }
        }
    }

    gMultiHitCounter = 0;
    gSpecialStatuses[gBattlerAttacker].parentalBondState = PARENTAL_BOND_OFF;
    gSpecialStatuses[gBattlerAttacker].multiHitOn = 0;
    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndDefrost(void)
{
    enum Ability abilityAtk = GetBattlerAbility(gBattlerAttacker);
    const u8 *battleScript = NULL;

    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {
        enum BattlerId battler = gBattleStruct->eventState.moveEndBattler++;

        if (battler == gBattlerAttacker)
            continue;

        if (!(gBattleMons[battler].status1 & STATUS1_ICY_ANY)
         || !IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
         || !IsBattlerAlive(battler))
            continue;

        if (gBattleMons[battler].status1 & STATUS1_FREEZE)
            battleScript = BattleScript_BattlerDefrosted;
        else
            battleScript = BattleScript_BattlerFrostbiteHealed;

        if ((CanFireMoveThawTarget(gCurrentMove) || CanBurnHitThaw(gCurrentMove)) && gBattleMons[battler].status1 & STATUS1_FREEZE)
        {
            DefrostBattler(battler, gBattleMons[battler].status1);
            BattleScriptCall(battleScript);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DEFROSTED;
            return MOVEEND_RESULT_RUN_SCRIPT;
        }
        else if (IsBattlerAlive(gBattlerAttacker)
              && CanMoveThawTarget(abilityAtk, gCurrentMove))
        {
            DefrostBattler(battler, gBattleMons[battler].status1);
            BattleScriptCall(battleScript);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DEFROSTED;
            return MOVEEND_RESULT_RUN_SCRIPT;
        }
    }

    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndSheerForce(void)
{
    if (IsSheerForceAffected(gCurrentMove, GetBattlerAbility(gBattlerAttacker)))
        gBattleScripting.moveendState = MOVEEND_ITEMS_EFFECTS_ALL;
    else
        gBattleScripting.moveendState++;

    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndMoveBlock(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    enum BattleSide side = GetBattlerSide(gBattlerTarget);
    enum BattleMoveEffects moveEffect = GetMoveEffect(gCurrentMove);

    switch (moveEffect)
    {
    case EFFECT_SPIT_UP:
    case EFFECT_SWALLOW:
        if (!gBattleStruct->unableToUseMove)
        {
            gBattleMons[gBattlerAttacker].volatiles.stockpileCounter = 0;
            if (B_STOCKPILE_RAISES_DEFS >= GEN_4)
            {
                BattleScriptCall(BattleScript_MoveEffectStockpileWoreOff);
                result = MOVEEND_RESULT_RUN_SCRIPT;
            }
        }
        break;
    case EFFECT_KNOCK_OFF:
        if (gBattleMons[gBattlerTarget].item != ITEM_NONE
         && IsBattlerAlive(gBattlerAttacker)
         && !(B_KNOCK_OFF_REMOVAL >= GEN_5 && side == B_SIDE_PLAYER && !(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
         && IsAnyTargetTurnDamaged(gBattlerAttacker, EXCLUDING_SUBSTITUTES)
         && !DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove)
         && CanBattlerGetOrLoseItem(gBattlerTarget, gBattlerAttacker, gBattleMons[gBattlerTarget].item)
         && !NoAliveMonsForEitherParty())
        {
            enum BattleSide side = GetBattlerSide(gBattlerTarget);

            if (GetBattlerAbility(gBattlerTarget) == ABILITY_STICKY_HOLD)
            {
                gBattlerAbility = gBattlerTarget;
                BattleScriptCall(BattleScript_StickyHoldActivatesRet);
                result = MOVEEND_RESULT_RUN_SCRIPT;
                break;
            }

            gLastUsedItem = gBattleMons[gBattlerTarget].item;
            gBattleMons[gBattlerTarget].item = ITEM_NONE;
            if (gBattleMons[gBattlerTarget].ability != ABILITY_GORILLA_TACTICS)
                gBattleStruct->choicedMove[gBattlerTarget] = MOVE_NONE;
            CheckSetUnburden(gBattlerTarget);

            // In Gen 5+, Knock Off removes the target's item rather than rendering it unusable
            if (B_KNOCK_OFF_REMOVAL >= GEN_5)
            {
                BtlController_EmitSetMonData(gBattlerTarget, B_COMM_TO_CONTROLLER, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gBattlerTarget].item), &gBattleMons[gBattlerTarget].item);
                MarkBattlerForControllerExec(gBattlerTarget);
                // Mark item as stolen so it will be restored after battle
                gBattleStruct->itemLost[side][gBattlerPartyIndexes[gBattlerTarget]].stolen = TRUE;
            }
            else
            {
                GetBattlerPartyState(gBattlerTarget)->isKnockedOff = TRUE;
            }

            BattleScriptCall(BattleScript_KnockedOff);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_STEAL_ITEM:
        if (!IsAnyTargetTurnDamaged(gBattlerAttacker, EXCLUDING_SUBSTITUTES)
         || gBattleMons[gBattlerAttacker].item != ITEM_NONE
         || gBattleMons[gBattlerTarget].item == ITEM_NONE
         || !IsBattlerAlive(gBattlerAttacker)
         || !CanStealItem(gBattlerAttacker, gBattlerTarget, gBattleMons[gBattlerTarget].item))
        {
            result = MOVEEND_RESULT_CONTINUE;
        }
        else if (GetBattlerAbility(gBattlerTarget) == ABILITY_STICKY_HOLD)
        {
            BattleScriptCall(BattleScript_NoItemSteal);
            gLastUsedAbility = gBattleMons[gBattlerTarget].ability;
            RecordAbilityBattle(gBattlerTarget, gLastUsedAbility);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        else
        {
            StealTargetItem(gBattlerAttacker, gBattlerTarget);  // Attacker steals target item

            if (!(GetConfig(B_STEAL_WILD_ITEMS) >= GEN_9
             && !(gBattleTypeFlags & (BATTLE_TYPE_TRAINER | BATTLE_TYPE_PALACE))))
            {
                gBattleMons[gBattlerAttacker].item = gLastUsedItem;
            }
            gEffectBattler = gBattlerTarget;
            BattleScriptCall(BattleScript_ItemSteal);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_HIT_SWITCH_TARGET:
        if (IsAnyTargetTurnDamaged(gBattlerAttacker, EXCLUDING_SUBSTITUTES)
         && IsBattlerAlive(gBattlerTarget)
         && IsBattlerAlive(gBattlerAttacker)
         && gBattleStruct->battlerState[gBattlerTarget].commanderSpecies == SPECIES_NONE)
        {
            enum Ability targetAbility = GetBattlerAbility(gBattlerTarget);
            if (targetAbility == ABILITY_GUARD_DOG)
                break;

            if (targetAbility == ABILITY_SUCTION_CUPS)
            {
                BattleScriptCall(BattleScript_AbilityPreventsPhasingOutRet);
            }
            else if (gBattleMons[gBattlerTarget].volatiles.root)
            {
                BattleScriptCall(BattleScript_PrintMonIsRootedRet);
            }
            else if (GetActiveGimmick(gBattlerTarget) == GIMMICK_DYNAMAX)
            {
                BattleScriptCall(BattleScript_HitSwitchTargetDynamaxed);
            }
            else
            {
                gBattleScripting.switchCase = B_SWITCH_HIT;
                BattleScriptCall(BattleScript_TryHitSwitchTarget);
            }
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_SMACK_DOWN:
        if (!IsBattlerGrounded(gBattlerTarget, GetBattlerAbility(gBattlerTarget), GetBattlerHoldEffect(gBattlerTarget))
         && IsAnyTargetTurnDamaged(gBattlerAttacker, EXCLUDING_SUBSTITUTES)
         && IsBattlerAlive(gBattlerTarget)
         && !DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove))
        {
            gBattleMons[gBattlerTarget].volatiles.smackDown = TRUE;
            gBattleMons[gBattlerTarget].volatiles.telekinesis = FALSE;
            gBattleMons[gBattlerTarget].volatiles.magnetRise = FALSE;
            gBattleMons[gBattlerTarget].volatiles.semiInvulnerable = STATE_NONE;
            BattleScriptCall(BattleScript_MoveEffectSmackDown);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_RECOIL_IF_MISS:
        if (IsBattlerAlive(gBattlerAttacker)
         && IsBattlerUnaffectedByMove(gBattlerTarget)
         && !gBattleStruct->unableToUseMove)
        {
            s32 recoil = 0;
            if (B_CRASH_IF_TARGET_IMMUNE == GEN_4 && gBattleStruct->moveResultFlags[gBattlerTarget] & MOVE_RESULT_DOESNT_AFFECT_FOE)
            {
                recoil = GetNonDynamaxMaxHP(gBattlerTarget) / 2;
            }
            if (B_RECOIL_IF_MISS_DMG >= GEN_5)
            {
                recoil = GetNonDynamaxMaxHP(gBattlerAttacker) / 2;
            }
            else if (B_RECOIL_IF_MISS_DMG >= GEN_3)
            {
                if ((GetNonDynamaxMaxHP(gBattlerTarget) / 2) < gBattleStruct->moveDamage[gBattlerTarget])
                    recoil = gBattleStruct->moveDamage[gBattlerTarget];
                else
                    recoil = GetNonDynamaxMaxHP(gBattlerTarget) / 2;
            }
            else if (B_RECOIL_IF_MISS_DMG == GEN_2)
            {
                recoil = gBattleStruct->moveDamage[gBattlerTarget] / 8;
            }
            else
            {
                recoil = 1;
            }
            SetPassiveDamageAmount(gBattlerAttacker, recoil);
            BattleScriptCall(BattleScript_RecoilIfMiss);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_RECOIL:
        if (IsAnyTargetTurnDamaged(gBattlerAttacker, INCLUDING_SUBSTITUTES) && IsBattlerAlive(gBattlerAttacker) && gBattleStruct->moveDamage[gBattlerTarget] > 0)
        {
            enum Ability ability = GetBattlerAbility(gBattlerAttacker);
            if (IsAbilityAndRecord(gBattlerAttacker, ability, ABILITY_ROCK_HEAD)
             || IsAbilityAndRecord(gBattlerAttacker, ability, ABILITY_MAGIC_GUARD))
                break;

            SetPassiveDamageAmount(gBattlerAttacker, gBattleScripting.savedDmg * max(1, GetMoveRecoil(gCurrentMove)) / 100);
            TryUpdateEvolutionTracker(IF_RECOIL_DAMAGE_GE, gBattleStruct->passiveHpUpdate[gBattlerAttacker], MOVE_NONE);
            BattleScriptCall(BattleScript_MoveEffectRecoil);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_CHLOROBLAST:
        if (IsAnyTargetTurnDamaged(gBattlerAttacker, INCLUDING_SUBSTITUTES) && IsBattlerAlive(gBattlerAttacker))
        {
            enum Ability ability = GetBattlerAbility(gBattlerAttacker);
            if (IsAbilityAndRecord(gBattlerAttacker, ability, ABILITY_ROCK_HEAD)
             || IsAbilityAndRecord(gBattlerAttacker, ability, ABILITY_MAGIC_GUARD))
                break;

            s32 recoil = (GetNonDynamaxMaxHP(gBattlerAttacker) + 1) / 2; // Half of Max HP Rounded UP
            SetPassiveDamageAmount(gBattlerAttacker, recoil);
            TryUpdateEvolutionTracker(IF_RECOIL_DAMAGE_GE, gBattleStruct->passiveHpUpdate[gBattlerAttacker], MOVE_NONE);
            BattleScriptCall(BattleScript_MoveEffectRecoil);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_RAPID_SPIN:
        if (IsAnyTargetTurnDamaged(gBattlerAttacker, INCLUDING_SUBSTITUTES) && IsBattlerAlive(gBattlerAttacker))
        {
            BattleScriptCall(BattleScript_RapidSpinAway);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_FELL_STINGER:
        if (IsBattlerAlive(gBattlerAttacker)
         && !IsBattlerAlive(gBattlerTarget)
         && IsAnyTargetTurnDamaged(gBattlerAttacker, EXCLUDING_SUBSTITUTES)
         && !NoAliveMonsForEitherParty()
         && CompareStat(gBattlerAttacker, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, GetBattlerAbility(gBattlerAttacker)))
        {
            SET_STATCHANGER(STAT_ATK, GetConfig(B_FELL_STINGER_STAT_RAISE) >= GEN_7 ? 3 : 2, FALSE);
            PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_ATK);
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_FellStingerRaisesStat;
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_STONE_AXE:
        if (!IsHazardOnSide(side, HAZARDS_STEALTH_ROCK)
         && IsAnyTargetTurnDamaged(gBattlerAttacker, INCLUDING_SUBSTITUTES)
         && IsBattlerAlive(gBattlerAttacker))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_POINTEDSTONESFLOAT;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_MoveEffectStealthRock;
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_CEASELESS_EDGE:
        if (gSideTimers[side].spikesAmount < 3
         && IsAnyTargetTurnDamaged(gBattlerAttacker, INCLUDING_SUBSTITUTES)
         && IsBattlerAlive(gBattlerAttacker))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SPIKESSCATTERED;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            if (gBattleStruct->isSkyBattle)
            {
                result = MOVEEND_RESULT_CONTINUE;
            }
            else
            {
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_MoveEffectSpikes;
                result = MOVEEND_RESULT_RUN_SCRIPT;
            }
        }
        break;
    case EFFECT_SCALE_SHOT:
        if (IsBattlerAlive(gBattlerAttacker)
         && IsAnyTargetTurnDamaged(gBattlerAttacker, INCLUDING_SUBSTITUTES))
        {
            BattleScriptCall(BattleScript_DefDownSpeedUp);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    default:
        result = MOVEEND_RESULT_CONTINUE;
        break;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndItemEffectsAttacker2(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    enum HoldEffect holdEffect = GetBattlerHoldEffect(gBattlerAttacker);

    if (ItemBattleEffects(gBattlerAttacker, gBattlerTarget, holdEffect, IsOnStatusChangeActivation)
     || ItemBattleEffects(gBattlerAttacker, gBattlerTarget, holdEffect, IsOnHpThresholdActivation))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndAbilityEffectFoesFainted(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (AbilityBattleEffects(ABILITYEFFECT_MOVE_END_FOES_FAINTED, gBattlerAttacker, GetBattlerAbility(gBattlerAttacker), gCurrentMove, TRUE))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndShellTrap(void)
{
    for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
    {
        if (battlerDef == gBattlerAttacker || IsBattlerAlly(battlerDef, gBattlerAttacker))
            continue;

        // Set ShellTrap to activate after the attacker's turn if target was hit by a physical move.
        if (GetMoveEffect(gChosenMoveByBattler[battlerDef]) == EFFECT_SHELL_TRAP
         && IsBattleMovePhysical(gCurrentMove)
         && IsBattlerTurnDamaged(battlerDef, EXCLUDING_SUBSTITUTES)
         && gProtectStructs[battlerDef].physicalBattlerId == gBattlerAttacker)
        {
            gProtectStructs[battlerDef].shellTrap = TRUE;
            if (IsDoubleBattle()) // Change move order in double battles, so the hit mon with shell trap moves immediately after being hit.
                ChangeOrderTargetAfterAttacker(); // In what order should 2 targets move that will activate a trap?
        }
    }

    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndColorChange(void)
{
    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {
        enum BattlerId battler = gBattleStruct->eventState.moveEndBattler++;
        if (battler == gBattlerAttacker)
            continue;
        if (AbilityBattleEffects(ABILITYEFFECT_COLOR_CHANGE, battler, GetBattlerAbility(battler), 0, TRUE))
            return MOVEEND_RESULT_RUN_SCRIPT;
    }

    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndKeeMarangaHpThresholdItemTarget(void)
{
    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {
        enum BattlerId battlerDef = gBattleStruct->eventState.moveEndBattler++;
        if (battlerDef == gBattlerAttacker)
            continue;
        enum HoldEffect holdEffect = GetBattlerHoldEffect(battlerDef);
        if (ItemBattleEffects(battlerDef, gBattlerAttacker, holdEffect, IsKeeMarangaBerryActivation)
         || ItemBattleEffects(battlerDef, gBattlerAttacker, holdEffect, IsOnHpThresholdActivation))
            return MOVEEND_RESULT_RUN_SCRIPT;
    }

    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static bool32 HasAnyBattlerQueuedSwitch(void)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (gSpecialStatuses[battler].queuedSwitch != NO_QUEUED_SWITCH)
            return TRUE;
    }
    return FALSE;
}

static bool32 TryRedCard(enum BattlerId battlerAtk, enum BattlerId redCardBattler, enum Move move)
{
    if (!IsBattlerAlive(redCardBattler)
     || !IsBattlerTurnDamaged(redCardBattler, EXCLUDING_SUBSTITUTES)
     || DoesSubstituteBlockMove(battlerAtk, redCardBattler, move)
     || !CanBattlerSwitch(battlerAtk))
        return FALSE;

    gLastUsedItem = gBattleMons[redCardBattler].item;
    SaveBattlerTarget(redCardBattler); // save battler with red card
    SaveBattlerAttacker(battlerAtk);
    gBattleScripting.battler = gBattlerTarget = redCardBattler;
    gEffectBattler = battlerAtk;
    if (gBattleStruct->battlerState[battlerAtk].commanderSpecies != SPECIES_NONE
     || GetBattlerAbility(battlerAtk) == ABILITY_GUARD_DOG
     || GetActiveGimmick(battlerAtk) == GIMMICK_DYNAMAX)
        BattleScriptCall(BattleScript_RedCardActivationNoSwitch);
    else
        BattleScriptCall(BattleScript_RedCardActivates);

    return TRUE;
}

static bool32 TryEjectButton(enum BattlerId battlerAtk, u32 ejectButtonBattler)
{
    if (!IsBattlerTurnDamaged(ejectButtonBattler, EXCLUDING_SUBSTITUTES)
     || !IsBattlerAlive(ejectButtonBattler)
     || !CanBattlerSwitch(ejectButtonBattler))
        return FALSE;

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
        gBattleMons[battler].volatiles.tryEjectPack = FALSE;

    gBattleScripting.battler = ejectButtonBattler;
    gLastUsedItem = gBattleMons[ejectButtonBattler].item;
    gBattleStruct->battlerState[ejectButtonBattler].usedEjectItem = TRUE;
    gSpecialStatuses[ejectButtonBattler].queuedSwitch = QUEUED_SWITCH_OPEN_PARTY_SCREEN;
    BattleScriptCall(BattleScript_EjectItemActivates);
    gAiLogicData->ejectButtonSwitch = TRUE;
    return TRUE;
}

static enum MoveEndResult MoveEndCardButton(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    u32 redCardBattlers = 0;
    u32 ejectButtonBattlers = 0;

    // Because sorting the battlers by speed takes lots of cycles, it's better to just check if any of the battlers has the Eject items.
    for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
    {
        if (gBattlerAttacker == battlerDef)
            continue;

        if (GetBattlerHoldEffect(battlerDef) == HOLD_EFFECT_EJECT_BUTTON)
            ejectButtonBattlers |= 1u << battlerDef;

        if (GetBattlerHoldEffect(battlerDef) == HOLD_EFFECT_RED_CARD)
            redCardBattlers |= 1u << battlerDef;
    }

    if (!redCardBattlers && !ejectButtonBattlers)
    {
        gBattleScripting.moveendState++;
        return MOVEEND_RESULT_CONTINUE;
    }

    enum BattlerId battlers[MAX_BATTLERS_COUNT] = {0, 1, 2, 3};
    SortBattlersBySpeed(battlers, FALSE);

    for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
    {
        enum BattlerId battler = battlers[battlerDef];

        // Only fastest red card or eject button activates
        if (redCardBattlers & 1u << battler && TryRedCard(gBattlerAttacker, battler, gCurrentMove))
            result = MOVEEND_RESULT_RUN_SCRIPT;
        else if (ejectButtonBattlers & 1u << battler && TryEjectButton(gBattlerAttacker, battler))
            result = MOVEEND_RESULT_RUN_SCRIPT;
        else
            continue;

        break;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndFormChange(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (!gBattleStruct->battlerState[gBattlerAttacker].redCardSwitched
     && TryBattleFormChange(gBattlerAttacker, FORM_CHANGE_BATTLE_AFTER_MOVE, GetBattlerAbility(gBattlerAttacker)))
    {
        result = MOVEEND_RESULT_RUN_SCRIPT;
        BattleScriptCall(BattleScript_AttackerFormChangeMoveEffect);
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndLifeOrbShellBell(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (ItemBattleEffects(gBattlerAttacker, 0, GetBattlerHoldEffect(gBattlerAttacker), IsLifeOrbShellBellActivation))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndEmergencyExit(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    u32 numEmergencyExitBattlers = 0;
    u32 emergencyExitBattlers = 0;

    if (HasAnyBattlerQueuedSwitch())
    {
        gBattleScripting.moveendState++;
        return result;
    }

    // Because sorting the battlers by speed takes lots of cycles,
    // we check if EE can be activated and count how many.
    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        if (!IsBattleMoveStatus(gCurrentMove)
         && !gBattleStruct->unableToUseMove
         && EmergencyExitCanBeTriggered(i))
        {
            emergencyExitBattlers |= 1u << i;
            numEmergencyExitBattlers++;
        }
    }

    if (numEmergencyExitBattlers == 0)
    {
        gBattleScripting.moveendState++;
        return result;
    }

    for (enum BattlerId i = 0; i < gBattlersCount; i++)
        gBattleMons[i].volatiles.tryEjectPack = FALSE;

    enum BattlerId battlers[MAX_BATTLERS_COUNT] = {0, 1, 2, 3};
    if (numEmergencyExitBattlers > 1)
        SortBattlersBySpeed(battlers, FALSE);

    for (u32 i = 0; i < gBattlersCount; i++)
    {
        enum BattlerId battler = battlers[i];

        if (!(emergencyExitBattlers & 1u << battler))
            continue;

        gBattleScripting.battler = battler;
        gSpecialStatuses[battler].queuedSwitch = QUEUED_SWITCH_OPEN_PARTY_SCREEN;
        BattleScriptCall(BattleScript_EmergencyExit);
        result = MOVEEND_RESULT_RUN_SCRIPT;
        break; // Only the fastest Emergency Exit / Wimp Out activates
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndHitEscape(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (GetMoveEffect(gCurrentMove) == EFFECT_HIT_ESCAPE
     && !HasAnyBattlerQueuedSwitch()
     && !gBattleStruct->battlerState[gBattlerAttacker].redCardSwitched
     && !gBattleStruct->unableToUseMove
     && IsAnyTargetTurnDamaged(gBattlerAttacker, INCLUDING_SUBSTITUTES)
     && IsBattlerAlive(gBattlerAttacker)
     && !NoAliveMonsForBattlerSide(gBattlerTarget))
    {
        result = MOVEEND_RESULT_RUN_SCRIPT;
        gSpecialStatuses[gBattlerAttacker].queuedSwitch = QUEUED_SWITCH_OPEN_PARTY_SCREEN;
        BattleScriptCall(BattleScript_EffectHitEscape);
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndPickpocket(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (IsBattlerAlive(gBattlerAttacker)
     && gBattleMons[gBattlerAttacker].item != ITEM_NONE
     && !GetBattlerPartyState(gBattlerAttacker)->isKnockedOff) // Gen3 edge case where the knocked of item was not removed
    {
        enum BattlerId battlers[MAX_BATTLERS_COUNT] = {0, 1, 2, 3};
        SortBattlersBySpeed(battlers, FALSE); // Pickpocket activates for fastest mon without item
        for (u32 i = 0; i < gBattlersCount; i++)
        {
            enum BattlerId battlerDef = battlers[i];
            if (battlerDef != gBattlerAttacker
              && !gBattleStruct->battlerState[battlerDef].notOnField
              && !IsBattlerUnaffectedByMove(battlerDef)
              && GetBattlerAbility(battlerDef) == ABILITY_PICKPOCKET
              && IsMoveMakingContact(gBattlerAttacker, battlerDef, GetBattlerAbility(gBattlerAttacker), GetBattlerHoldEffect(gBattlerAttacker), gCurrentMove)
              && IsBattlerTurnDamaged(battlerDef, EXCLUDING_SUBSTITUTES)
              && !DoesSubstituteBlockMove(gBattlerAttacker, battlerDef, gCurrentMove)
              && IsBattlerAlive(battlerDef)
              && gBattleMons[battlerDef].item == ITEM_NONE
              && CanStealItem(battlerDef, gBattlerAttacker, gBattleMons[gBattlerAttacker].item))
            {
                gBattlerTarget = gBattlerAbility = battlerDef;
                // Battle scripting is super brittle so we shall do the item exchange now (if possible)
                if (GetBattlerAbility(gBattlerAttacker) != ABILITY_STICKY_HOLD)
                    StealTargetItem(battlerDef, gBattlerAttacker);  // Target takes attacker's item

                gEffectBattler = gBattlerAttacker;
                BattleScriptCall(BattleScript_Pickpocket);   // Includes sticky hold check to print separate string
                result = MOVEEND_RESULT_RUN_SCRIPT;
                break; // Pickpocket activates on fastest mon, so exit loop.
            }
        }
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndItemsEffectsAll(void)
{
    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {
        enum BattlerId battler = gBattleStruct->eventState.moveEndBattler++;
        enum HoldEffect holdEffect = GetBattlerHoldEffect(battler);
        if (ItemBattleEffects(battler, 0, holdEffect, IsOnStatusChangeActivation)
         || ItemBattleEffects(battler, 0, holdEffect, IsOnHpThresholdActivation))
            return MOVEEND_RESULT_RUN_SCRIPT;
    }

    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndWhiteHerb(void)
{
    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {
        enum BattlerId battler = gBattleStruct->eventState.moveEndBattler++;

        if (ItemBattleEffects(battler, 0, GetBattlerHoldEffect(battler), IsWhiteHerbActivation))
            return MOVEEND_RESULT_RUN_SCRIPT;
    }

    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndOpportunist(void)
{
    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {
        enum BattlerId battler = gBattleStruct->eventState.moveEndBattler++;

        if (AbilityBattleEffects(ABILITYEFFECT_OPPORTUNIST, battler, GetBattlerAbility(battler), 0, TRUE))
            return MOVEEND_RESULT_RUN_SCRIPT;
    }

    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndMirrorHerb(void)
{
    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {
        enum BattlerId battler = gBattleStruct->eventState.moveEndBattler++;

        if (ItemBattleEffects(battler, 0, GetBattlerHoldEffect(battler), IsMirrorHerbActivation))
            return MOVEEND_RESULT_RUN_SCRIPT;
    }

    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndThirdMoveBlock(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    enum BattleMoveEffects moveEffect = GetMoveEffect(gCurrentMove);

    switch (moveEffect)
    {
    case EFFECT_STEEL_ROLLER:
        if (gFieldStatuses & STATUS_FIELD_TERRAIN_ANY && IsAnyTargetTurnDamaged(gBattlerAttacker, INCLUDING_SUBSTITUTES))
        {
            BattleScriptCall(BattleScript_RemoveTerrain);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_ICE_SPINNER:
        if (gFieldStatuses & STATUS_FIELD_TERRAIN_ANY
         && gLastPrintedMoves[gBattlerAttacker] == gCurrentMove
         && IsBattlerAlive(gBattlerAttacker)
         && IsAnyTargetTurnDamaged(gBattlerAttacker, INCLUDING_SUBSTITUTES))
        {
            BattleScriptCall(BattleScript_RemoveTerrain);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_NATURAL_GIFT:
        if (!gBattleStruct->unableToUseMove && GetItemPocket(gBattleMons[gBattlerAttacker].item) == POCKET_BERRIES)
        {
            enum Item item = gBattleMons[gBattlerAttacker].item;
            gBattleMons[gBattlerAttacker].item = ITEM_NONE;
            gBattleStruct->battlerState[gBattlerAttacker].canPickupItem = TRUE;
            GetBattlerPartyState(gBattlerAttacker)->usedHeldItem = item;
            CheckSetUnburden(gBattlerAttacker);
            BtlController_EmitSetMonData(
                gBattlerAttacker,
                B_COMM_TO_CONTROLLER,
                REQUEST_HELDITEM_BATTLE,
                0,
                sizeof(gBattleMons[gBattlerAttacker].item),
                &gBattleMons[gBattlerAttacker].item);
            MarkBattlerForControllerExec(gBattlerAttacker);
            ClearBattlerItemEffectHistory(gBattlerAttacker);

            if (!TrySymbiosis(gBattlerAttacker, item, TRUE))
                result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    default:
        break;
    }

    gBattleScripting.moveendState++;
    return result;
}

static inline bool32 CanEjectPackTrigger(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum BattleMoveEffects moveEffect)
{
    if (gBattleMons[battlerDef].volatiles.tryEjectPack
     && GetBattlerHoldEffect(battlerDef) == HOLD_EFFECT_EJECT_PACK
     && IsBattlerAlive(battlerDef)
     && CanBattlerSwitch(battlerDef)
     && !gProtectStructs[battlerDef].disableEjectPack
     && !(moveEffect == EFFECT_PARTING_SHOT && CanBattlerSwitch(battlerAtk)))
        return TRUE;
    return FALSE;
}

static enum MoveEndResult MoveEndEjectPack(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    u32 ejectPackBattlers = 0;
    u32 numEjectPackBattlers = 0;

    if (HasAnyBattlerQueuedSwitch())
    {
        gBattleScripting.moveendState++;
        return result;
    }

    // Because sorting the battlers by speed takes lots of cycles, it's better to just check if any of the battlers has the Eject items.
    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        if (CanEjectPackTrigger(gBattlerAttacker, i, GetMoveEffect(gCurrentMove)))
        {
            ejectPackBattlers |= 1u << i;
            numEjectPackBattlers++;
        }
    }

    if (numEjectPackBattlers == 0)
    {
        gBattleScripting.moveendState++;
        return result;
    }

    enum BattlerId battlers[MAX_BATTLERS_COUNT] = {0, 1, 2, 3};
    if (numEjectPackBattlers > 1)
        SortBattlersBySpeed(battlers, FALSE);

    for (enum BattlerId i = 0; i < gBattlersCount; i++)
        gBattleMons[i].volatiles.tryEjectPack = FALSE;

    for (u32 i = 0; i < gBattlersCount; i++)
    {
        enum BattlerId battler = battlers[i];

        if (!(ejectPackBattlers & 1u << battler))
            continue;

        gBattleScripting.battler = battler;
        gLastUsedItem = gBattleMons[battler].item;
        gBattleStruct->battlerState[battler].usedEjectItem = TRUE;
        gSpecialStatuses[battler].queuedSwitch = QUEUED_SWITCH_OPEN_PARTY_SCREEN;
        BattleScriptCall(BattleScript_EjectItemActivates);
        gAiLogicData->ejectPackSwitch = TRUE;
        result = MOVEEND_RESULT_RUN_SCRIPT;
        break; // Only the fastest Eject item activates
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndSendOutReplacements(void)
{
    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {
        enum BattlerId battler = gBattlersBySpeed[gBattleStruct->eventState.moveEndBattler++];

        switch (gSpecialStatuses[battler].queuedSwitch)
        {
        case NO_QUEUED_SWITCH:
            continue;
        case QUEUED_SWITCH_SEND_REPLACEMENT:
            gBattleScripting.battler = battler;
            BattleScriptCall(BattleScript_QueuedSwitch);
            return MOVEEND_RESULT_RUN_SCRIPT;
        case QUEUED_SWITCH_OPEN_PARTY_SCREEN:
            gBattleScripting.battler = battler;
            BattleScriptCall(BattleScript_QueuedSwitchOpenPartyScreen);
            return MOVEEND_RESULT_RUN_SCRIPT;
        default:
            errorf("Invalid value - queuedSwitch");
            break;
        }
    }
    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndRampage(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (gBattleMons[gBattlerAttacker].volatiles.rampageTurns == 0
     || gSpecialStatuses[gBattlerAttacker].dancerUsedMove
     || B_RAMPAGE_CONFUSION < GEN_5)
    {
        result = MOVEEND_RESULT_CONTINUE;
    }
    else if (--gBattleMons[gBattlerAttacker].volatiles.rampageTurns == 0)
    {
        CancelMultiTurnMoves(gBattlerAttacker);
        if (CanBeConfused(gBattlerAttacker, gBattlerAttacker))
        {
            gBattleScripting.battler = gBattlerAttacker;
            gBattleMons[gBattlerAttacker].volatiles.confusionTurns = RandomUniform(RNG_CONFUSION_TURNS, 2, B_CONFUSION_TURNS); // 2-5 turns
            BattleScriptCall(BattleScript_ConfusionAfterRampage);
            result = MOVEEND_RESULT_BREAK;
        }
    }
    else if (IsBattlerUnaffectedByMove(gBattlerTarget))
    {
        CancelMultiTurnMoves(gBattlerAttacker);
        result = MOVEEND_RESULT_CONTINUE;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndConfusionAfterSkyDrop(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (gBattleMons[gBattlerTarget].volatiles.confuseAfterDrop
     && gBattleMons[gBattlerTarget].volatiles.semiInvulnerable != STATE_SKY_DROP_TARGET)
    {
        gBattleMons[gBattlerTarget].volatiles.confuseAfterDrop = FALSE;
        if (CanBeConfused(gBattlerTarget, gBattlerTarget))
        {
            gBattleScripting.battler = gBattlerTarget;
            gBattleMons[gBattlerTarget].volatiles.confusionTurns = RandomUniform(RNG_CONFUSION_TURNS, 2, B_CONFUSION_TURNS); // 2-5 turns
            BattleScriptCall(BattleScript_ConfusionAfterRampage);
            result = MOVEEND_RESULT_BREAK;
        }
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndSprayLeppaBlunder(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    enum HoldEffect holdEffect = GetBattlerHoldEffect(gBattlerAttacker);

    // Throat Spray, Leppa Berry, Blunder Policy
    if (ItemBattleEffects(gBattlerAttacker, 0, holdEffect, IsSprayLeppaBlunderActivation))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static bool32 ShouldSetStompingTantrumTimer(void)
{
    u32 numNotAffectedTargets = 0;

    if (gBattleStruct->battlerState[gBattlerAttacker].redCardSwitched) // no longer the same battler
        return FALSE;

    if (gBattleStruct->pledgeMove == TRUE // Is the battler that uses the first Pledge move in the combo
     || gBattleStruct->unableToUseMove)
        return TRUE;

    if (!IsDoubleSpreadMove())
        return gBattleStruct->moveResultFlags[gBattlerTarget] & (MOVE_RESULT_FAILED | MOVE_RESULT_DOESNT_AFFECT_FOE);

    for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
    {
        if (gBattlerAttacker == battlerDef)
            continue;
        if (gBattleStruct->moveResultFlags[battlerDef] & (MOVE_RESULT_FAILED | MOVE_RESULT_DOESNT_AFFECT_FOE))
            numNotAffectedTargets++;
    }

    return numNotAffectedTargets == gBattleStruct->numSpreadTargets;
}

static enum MoveEndResult MoveEndClearBits(void)
{
    ValidateBattlers();

    enum Move originallyUsedMove = GetOriginallyUsedMove(gChosenMove);
    enum Type moveType = GetBattleMoveType(gCurrentMove);
    enum BattleMoveEffects moveEffect = GetMoveEffect(gCurrentMove);

    if (ShouldSetStompingTantrumTimer())
        gBattleStruct->battlerState[gBattlerAttacker].stompingTantrumTimer = 2;

    if (gSpecialStatuses[gBattlerAttacker].backUpTarget)
        gBattleStruct->moveTarget[gBattlerAttacker] = gSpecialStatuses[gBattlerAttacker].backUpTarget - 1;

    // If the Pokémon needs to keep track of move usage for its evolutions, do it
    if (originallyUsedMove != MOVE_NONE)
        TryUpdateEvolutionTracker(IF_USED_MOVE_X_TIMES, 1, originallyUsedMove);

    SetSameMoveTurnValues(moveEffect);
    TryClearChargeVolatile(moveType);
    gProtectStructs[gBattlerAttacker].shellTrap = FALSE;
    gBattleStruct->battlerState[gBattlerAttacker].ateBoost = FALSE;
    gBattleScripting.moveEffect = MOVE_EFFECT_NONE;
    gBattleStruct->swapDamageCategory = FALSE;
    gBattleStruct->categoryOverride = FALSE;
    gBattleStruct->additionalEffectsCounter = 0;
    gBattleStruct->triAttackBurn = FALSE;
    gBattleStruct->poisonPuppeteerConfusion = FALSE;
    gBattleStruct->fickleBeamBoosted = FALSE;
    gBattleStruct->battlerState[gBattlerAttacker].usedMicleBerry = FALSE;
    gBattleStruct->toxicChainPriority = FALSE;
    gBattleStruct->flungItem = FLUNG_ITEM_NONE;
    gBattleStruct->blunderPolicy = FALSE;

    if (gBattleStruct->unableToUseMove)
        gBattleStruct->pledgeMove = FALSE;
    if (GetActiveGimmick(gBattlerAttacker) == GIMMICK_Z_MOVE)
        SetActiveGimmick(gBattlerAttacker, GIMMICK_NONE);
    if (gBattleMons[gBattlerAttacker].volatiles.destinyBond > 0)
        gBattleMons[gBattlerAttacker].volatiles.destinyBond--;

    // check if Stellar type boost should be used up
    if (GetActiveGimmick(gBattlerAttacker) == GIMMICK_TERA
     && GetBattlerTeraType(gBattlerAttacker) == TYPE_STELLAR
     && GetMoveCategory(gCurrentMove) != DAMAGE_CATEGORY_STATUS
     && IsTypeStellarBoosted(gBattlerAttacker, moveType))
        ExpendTypeStellarBoost(gBattlerAttacker, moveType);
    memset(gQueuedStatBoosts, 0, sizeof(gQueuedStatBoosts));

    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        gBattleStruct->battlerState[gBattlerAttacker].targetsDone[i] = FALSE;
        gBattleStruct->battlerState[i].redCardSwitched = FALSE;
        gBattleMons[i].volatiles.tryEjectPack = FALSE;

        if (gBattleStruct->battlerState[i].commanderSpecies != SPECIES_NONE && !IsBattlerAlive(i))
        {
            enum BattlerId partner = BATTLE_PARTNER(i);
            gBattleStruct->battlerState[i].commanderSpecies = SPECIES_NONE;
            if (gBattleMons[partner].volatiles.semiInvulnerable == STATE_COMMANDER)
                gBattleMons[partner].volatiles.semiInvulnerable = STATE_NONE;
        }
    }

    // Need to check a specific battler during the end turn
    gBattleMons[gBattlerAttacker].volatiles.unableToUseMove = gBattleStruct->unableToUseMove;
    ClearDamageCalcResults();

    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndDancer(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (AbilityBattleEffects(ABILITYEFFECT_DANCER, gBattlerAttacker, ABILITY_DANCER, gCurrentMove, TRUE))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndPursuitNextAction(void)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (gBattleStruct->battlerState[gBattlerTarget].pursuitTarget)
    {
        u32 storedTarget = gBattlerTarget;
        if (SetTargetToNextPursuiter(gBattlerTarget))
        {
            ChangeOrderTargetAfterAttacker();
            gBattleStruct->moveTarget[gBattlerTarget] = storedTarget;
            gBattlerTarget = storedTarget;
        }
        else if (IsBattlerAlive(gBattlerTarget))
        {
            gBattlerAttacker = gBattlerTarget;
            if (gBattleStruct->pursuitStoredSwitch == PARTY_SIZE)
                gBattlescriptCurrInstr = BattleScript_MoveSwitchOpenPartyScreen;
            else
                gBattlescriptCurrInstr = BattleScript_DoSwitchOut;
            gBattleStruct->monToSwitchIntoId[gBattlerTarget] = gBattleStruct->pursuitStoredSwitch;
            ClearPursuitValues();
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult (*const sMoveEndHandlers[])(void) =
{
    [MOVEEND_SET_VALUES] = MoveEndSetValues,
    [MOVEEND_PROTECT_LIKE_EFFECT] = MoveEndProtectLikeEffect,
    [MOVEEND_ABSORB] = MoveEndAbsorb,
    [MOVEEND_RAGE] = MoveEndRage,
    [MOVEEND_ABILITIES] = MoveEndAbilities,
    [MOVEEND_FORM_CHANGE_ON_HIT] = MoveEndFormChangeOnHit,
    [MOVEEND_ABILITIES_ATTACKER] = MoveEndAbilitiesAttacker,
    [MOVEEND_QUEUE_DANCER] = MoveEndQueueDancer,
    [MOVEEND_STATUS_IMMUNITY_ABILITIES] = MoveEndStatusImmunityAbilities,
    [MOVEEND_ATTACKER_INVISIBLE] = MoveEndAttackerInvisible,
    [MOVEEND_ATTACKER_VISIBLE] = MoveEndAttackerVisible,
    [MOVEEND_TARGET_VISIBLE] = MoveEndTargetVisible,
    [MOVEEND_ITEM_EFFECTS_TARGET] = MoveEndItemEffectsTarget,
    [MOVEEND_ITEM_EFFECTS_ATTACKER_1] = MoveEndItemEffectsAttacker1,
    [MOVEEND_SYMBIOSIS] = MoveEndSymbiosis,
    [MOVEEND_SUBSTITUTE] = MoveEndSubstitute,
    [MOVEEND_FAINT_BLOCK] = MoveEndFaintBlock,
    [MOVEEND_UPDATE_LAST_MOVES] = MoveEndUpdateLastMoves,
    [MOVEEND_MIRROR_MOVE] = MoveEndMirrorMove,
    [MOVEEND_NEXT_TARGET] = MoveEndNextTarget,
    [MOVEEND_BOUNCED_MOVE] = MoveEndBouncedMove,
    [MOVEEND_HP_THRESHOLD_ITEMS_TARGET] = MoveEndHpThresholdItemsTarget,
    [MOVEEND_MULTIHIT_MOVE] = MoveEndMultihitMove,
    [MOVEEND_DEFROST] = MoveEndDefrost,
    [MOVEEND_SHEER_FORCE] = MoveEndSheerForce,
    [MOVEEND_MOVE_BLOCK] = MoveEndMoveBlock,
    [MOVEEND_ITEM_EFFECTS_ATTACKER_2] = MoveEndItemEffectsAttacker2,
    [MOVEEND_ABILITY_EFFECT_FOES_FAINTED] = MoveEndAbilityEffectFoesFainted,
    [MOVEEND_SHELL_TRAP] = MoveEndShellTrap,
    [MOVEEND_COLOR_CHANGE] = MoveEndColorChange,
    [MOVEEND_KEE_MARANGA_HP_THRESHOLD_ITEM_TARGET] = MoveEndKeeMarangaHpThresholdItemTarget,
    [MOVEEND_CARD_BUTTON] = MoveEndCardButton,
    [MOVEEND_FORM_CHANGE] = MoveEndFormChange,
    [MOVEEND_LIFE_ORB_SHELL_BELL] = MoveEndLifeOrbShellBell,
    [MOVEEND_EMERGENCY_EXIT] = MoveEndEmergencyExit,
    [MOVEEND_HIT_ESCAPE] = MoveEndHitEscape,
    [MOVEEND_PICKPOCKET] = MoveEndPickpocket,
    [MOVEEND_ITEMS_EFFECTS_ALL] = MoveEndItemsEffectsAll,
    [MOVEEND_WHITE_HERB] = MoveEndWhiteHerb,
    [MOVEEND_OPPORTUNIST] = MoveEndOpportunist,
    [MOVEEND_MIRROR_HERB] = MoveEndMirrorHerb,
    [MOVEEND_THIRD_MOVE_BLOCK] = MoveEndThirdMoveBlock,
    [MOVEEND_RAMPAGE] = MoveEndRampage,
    [MOVEEND_CONFUSION_AFTER_SKY_DROP] = MoveEndConfusionAfterSkyDrop,
    [MOVEEND_SPRAY_LEPPA_BLUNDER] = MoveEndSprayLeppaBlunder,
    [MOVEEND_EJECT_PACK] = MoveEndEjectPack,
    [MOVEEND_SEND_OUT_REPLACEMENTS] = MoveEndSendOutReplacements,
    [MOVEEND_CLEAR_BITS] = MoveEndClearBits,
    [MOVEEND_DANCER] = MoveEndDancer,
    [MOVEEND_PURSUIT_NEXT_ACTION] = MoveEndPursuitNextAction,
};

enum MoveEndResult DoMoveEnd(enum MoveEndState endMode, enum MoveEndState endState)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    do
    {
        result = sMoveEndHandlers[gBattleScripting.moveendState]();

        if (endMode == 1 && result == MOVEEND_RESULT_CONTINUE)
            gBattleScripting.moveendState = MOVEEND_COUNT;
        if (endMode == 2 && endState == gBattleScripting.moveendState)
            gBattleScripting.moveendState = MOVEEND_COUNT;

    } while (gBattleScripting.moveendState != MOVEEND_COUNT && result == MOVEEND_RESULT_CONTINUE);

    return result;
}

// Utility functions

static void ValidateBattlers(void)
{
    assertf(gBattlerAttacker < MAX_BATTLERS_COUNT, "invalid gBattlerAttacker: %d\nmove: %S", gBattlerAttacker, GetMoveName(gCurrentMove));
    assertf(gBattlerTarget < MAX_BATTLERS_COUNT, "invalid gBattlerTarget: %d\nmove: %S", gBattlerTarget, GetMoveName(gCurrentMove));

    // More calls to SaveBattlerAttacker than RestoreBattlerAttacker.
    assertf(gBattleStruct->savedAttackerCount == 0, "savedAttackerCount is greater than 0");

    // More calls to SaveBattlerTarget than RestoreBattlerTarget.
    assertf(gBattleStruct->savedTargetCount == 0, "savedTargetCount is greater than 0");
}

static enum Move GetOriginallyUsedMove(enum Move chosenMove)
{
    return (gChosenMove == MOVE_UNAVAILABLE) ? MOVE_NONE : gChosenMove;
}

static void SetSameMoveTurnValues(enum BattleMoveEffects moveEffect)
{
    bool32 increment = IsAnyTargetAffected()
                    && !gBattleStruct->unableToUseMove
                    && gLastResultingMoves[gBattlerAttacker] == gCurrentMove;

    switch (moveEffect)
    {
    case EFFECT_FURY_CUTTER:
        if (increment && gBattleMons[gBattlerAttacker].volatiles.furyCutterCounter < 5)
            gBattleMons[gBattlerAttacker].volatiles.furyCutterCounter++;
        else
            gBattleMons[gBattlerAttacker].volatiles.furyCutterCounter = 0;
        break;
    case EFFECT_ROLLOUT:
        if (increment && ++gBattleMons[gBattlerAttacker].volatiles.rolloutTimer < 5)
        {
            gBattleMons[gBattlerAttacker].volatiles.multipleTurns = TRUE;
            gLockedMoves[gBattlerAttacker] = gCurrentMove;
        }
        else
        {
            gBattleMons[gBattlerAttacker].volatiles.multipleTurns = FALSE;
            gBattleMons[gBattlerAttacker].volatiles.rolloutTimer = 0;
        }
        break;
    case EFFECT_ECHOED_VOICE:
        if (!gBattleStruct->unableToUseMove) // Increment even if targets unaffected
            gBattleStruct->incrementEchoedVoice = TRUE;
        break;
    default: // not consecutive
        gBattleMons[gBattlerAttacker].volatiles.rolloutTimer = 0;
        gBattleMons[gBattlerAttacker].volatiles.furyCutterCounter = 0;
        break;
    }

    if (increment)
        gBattleMons[gBattlerAttacker].volatiles.metronomeItemCounter++;
    else
        gBattleMons[gBattlerAttacker].volatiles.metronomeItemCounter = 0;
}

static void TryClearChargeVolatile(enum Type moveType)
{
    if (B_CHARGE < GEN_9) // Prior to gen9, charge is cleared during the end turn
        return;

    if (moveType == TYPE_ELECTRIC && gBattleMons[gBattlerAttacker].volatiles.chargeTimer == 1)
        gBattleMons[gBattlerAttacker].volatiles.chargeTimer = 0;

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (gBattleMons[battler].volatiles.chargeTimer == 2) // Has been set this turn by move or ability
            gBattleMons[battler].volatiles.chargeTimer--;
    }
}

static inline bool32 IsBattlerUsingBeakBlast(enum BattlerId battler)
{
    if (gChosenActionByBattler[battler] != B_ACTION_USE_MOVE)
        return FALSE;
    if (GetMoveEffect(gChosenMoveByBattler[battler]) != EFFECT_BEAK_BLAST)
        return FALSE;
    return !HasBattlerActedThisTurn(battler);
}

static void RequestNonVolatileChange(enum BattlerId battlerAtk)
{
    BtlController_EmitSetMonData(
        battlerAtk,
        B_COMM_TO_CONTROLLER,
        REQUEST_STATUS_BATTLE,
        0,
        sizeof(gBattleMons[battlerAtk].status1),
        &gBattleMons[battlerAtk].status1);
    MarkBattlerForControllerExec(battlerAtk);
}

static enum Move GetMirrorMoveMove(void)
{
    s32 i, validMovesCount;
    enum Move move = MOVE_NONE;
    enum Move validMoves[MAX_BATTLERS_COUNT] = {MOVE_NONE};

    for (validMovesCount = 0, i = 0; i < gBattlersCount; i++)
    {
        if (i != gBattlerAttacker)
        {
            move = gBattleStruct->lastTakenMoveFrom[gBattlerAttacker][i];
            if (move != MOVE_NONE && move != MOVE_UNAVAILABLE)
            {
                validMoves[validMovesCount] = move;
                validMovesCount++;
            }
        }
    }

    move = gBattleStruct->lastTakenMove[gBattlerAttacker];
    if ((move == MOVE_NONE || move == MOVE_UNAVAILABLE) && validMovesCount != 0)
        move = validMoves[Random() % validMovesCount];

    if (GetActiveGimmick(gBattlerAttacker) == GIMMICK_Z_MOVE && !IsBattleMoveStatus(move))
        move = GetTypeBasedZMove(move);

    return move;
}

static bool32 InvalidMetronomeMove(u32 move)
{
    return GetMoveEffect(move) == EFFECT_PLACEHOLDER
        || IsMoveMetronomeBanned(move);
}

static enum Move GetMetronomeMove(void)
{
    enum Move move = MOVE_NONE;

#if B_METRONOME_MOVES >= GEN_9
    u32 moveCount = MOVES_COUNT_GEN9;
#elif B_METRONOME_MOVES >= GEN_8
    u32 moveCount = MOVES_COUNT_GEN8;
#elif B_METRONOME_MOVES >= GEN_7
    u32 moveCount = MOVES_COUNT_GEN7;
#elif B_METRONOME_MOVES >= GEN_6
    u32 moveCount = MOVES_COUNT_GEN6;
#elif B_METRONOME_MOVES >= GEN_5
    u32 moveCount = MOVES_COUNT_GEN5;
#elif B_METRONOME_MOVES >= GEN_4
    u32 moveCount = MOVES_COUNT_GEN4;
#elif B_METRONOME_MOVES >= GEN_3
    u32 moveCount = MOVES_COUNT_GEN3;
#elif B_METRONOME_MOVES >= GEN_2
    u32 moveCount = MOVES_COUNT_GEN2;
#else
    u32 moveCount = MOVES_COUNT_GEN1;
#endif

    move = RandomUniformExcept(RNG_METRONOME, 1, moveCount - 1, InvalidMetronomeMove);
    return move;
}

static enum Move GetAssistMove(void)
{
    enum Move move = MOVE_NONE;
    u32 chooseableMovesNo = 0;
    struct Pokemon *party;
    u8 battlerByPartyId[PARTY_SIZE];
    enum Move validMoves[PARTY_SIZE * MAX_MON_MOVES] = {MOVE_NONE};

    party = GetBattlerParty(gBattlerAttacker);

    for (u32 i = 0; i < PARTY_SIZE; i++)
        battlerByPartyId[i] = MAX_BATTLERS_COUNT;
    for (u32 battler = 0; battler < gBattlersCount; battler++)
    {
        if (!IsBattlerAlly(battler, gBattlerAttacker))
            continue;

        if (gBattlerPartyIndexes[battler] < PARTY_SIZE)
            battlerByPartyId[gBattlerPartyIndexes[battler]] = battler;
    }

    for (u32 monId = 0; monId < PARTY_SIZE; monId++)
    {
        if (monId == gBattlerPartyIndexes[gBattlerAttacker])
            continue;
        if (GetMonData(&party[monId], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[monId], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
            continue;

        for (u32 moveId = 0; moveId < MAX_MON_MOVES; moveId++)
        {
            enum Move move;

            if (battlerByPartyId[monId] != MAX_BATTLERS_COUNT)
                move = gBattleMons[battlerByPartyId[monId]].moves[moveId];
            else
                move = GetMonData(&party[monId], MON_DATA_MOVE1 + moveId);

            if (IsMoveAssistBanned(move))
                continue;

            validMoves[chooseableMovesNo++] = move;
        }
    }

    if (chooseableMovesNo)
        move = validMoves[Random() % chooseableMovesNo];

    return move;
}

enum Move GetNaturePowerMove(void)
{
    enum Move move = gBattleEnvironmentInfo[gBattleEnvironment].naturePower;
    if (gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN)
        move = MOVE_MOONBLAST;
    else if (gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN)
        move = MOVE_THUNDERBOLT;
    else if (gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN)
        move = MOVE_ENERGY_BALL;
    else if (gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN)
        move = MOVE_PSYCHIC;
    else if (gBattleEnvironmentInfo[gBattleEnvironment].naturePower == MOVE_NONE)
        move = B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_TRI_ATTACK : MOVE_SWIFT;

    return move;
}

static enum Move GetSleepTalkMove(void)
{
    enum Move move = MOVE_NONE;

    u32 i, unusableMovesBits = 0, movePosition;

    if (GetBattlerAbility(gBattlerAttacker) != ABILITY_COMATOSE
     && !(gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP))
        return move;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (IsMoveSleepTalkBanned(gBattleMons[gBattlerAttacker].moves[i])
            || gBattleMoveEffects[GetMoveEffect(gBattleMons[gBattlerAttacker].moves[i])].twoTurnEffect)
            unusableMovesBits |= (1 << (i));
    }

    unusableMovesBits = CheckMoveLimitations(gBattlerAttacker, unusableMovesBits, ~(MOVE_LIMITATION_PP | MOVE_LIMITATION_CHOICE_ITEM));
    if (unusableMovesBits == ALL_MOVES_MASK) // all 4 moves cannot be chosen
        return move;

    // Set Sleep Talk as used move, so it works with Last Resort.
    gBattleMons[gBattlerAttacker].volatiles.usedMoves |= 1u << gCurrMovePos;
    do
    {
        movePosition = MOD(Random(), MAX_MON_MOVES);
    } while ((1u << movePosition) & unusableMovesBits);

    move = gBattleMons[gBattlerAttacker].moves[movePosition];
    gCurrMovePos = movePosition;

    return move;
}

static enum Move GetCopycatMove(void)
{
    if (gLastUsedMove == MOVE_NONE
     || gLastUsedMove == MOVE_UNAVAILABLE
     || IsMoveCopycatBanned(gLastUsedMove)
     || IsZMove(gLastUsedMove))
        return MOVE_NONE;

    return gLastUsedMove;
}

static enum Move GetMeFirstMove(void)
{
    enum Move move = GetBattlerChosenMove(gBattlerTarget);

    if (IsBattleMoveStatus(move)
     || IsMoveMeFirstBanned(move)
     || HasBattlerActedThisTurn(gBattlerTarget))
        return MOVE_NONE;

    return move;
}

static bool32 CanBattlerBounceBackMove(struct BattleCalcValues *cv)
{
    return TryMagicBounce(cv) || TryMagicCoat(cv);
}

static bool32 TryMagicBounce(struct BattleCalcValues *cv)
{
    if (!MoveCanBeBouncedBack(cv->move))
        return FALSE;

    if (gBattleStruct->bouncedMoveIsUsed)
        return FALSE;

    if (cv->abilities[cv->battlerDef] != ABILITY_MAGIC_BOUNCE)
        return FALSE;

    gBattleStruct->magicBouncePending |= 1u << cv->battlerDef;
    return TRUE;
}

static bool32 TryMagicCoat(struct BattleCalcValues *cv)
{
    if (!MoveCanBeBouncedBack(cv->move))
        return FALSE;

    if (gBattleStruct->bouncedMoveIsUsed)
        return FALSE;

    if (!gProtectStructs[cv->battlerDef].bounceMove)
        return FALSE;

    gBattleStruct->magicCoatPending |= 1u << cv->battlerDef;
    return TRUE;
}

static bool32 TryActivatePowderStatus(enum Move move)
{
    enum Move partnerMove = GetBattlerChosenMove(BATTLE_PARTNER(gBattlerAttacker));
    if (!gBattleMons[gBattlerAttacker].volatiles.powder)
        return FALSE;
    if (GetBattleMoveType(move) == TYPE_FIRE && !gBattleStruct->pledgeMove)
        return TRUE;
    if (move == MOVE_FIRE_PLEDGE && partnerMove == MOVE_GRASS_PLEDGE)
        return TRUE;
    if (move == MOVE_GRASS_PLEDGE && partnerMove == MOVE_FIRE_PLEDGE && gBattleStruct->pledgeMove)
        return TRUE;
    return FALSE;
}

static void CalculateMagnitudeDamage(void)
{
    u32 magnitude = RandomUniform(RNG_MAGNITUDE, 0, 99);

    if (magnitude < 5)
    {
        gBattleStruct->magnitudeBasePower = 10;
        magnitude = 4;
    }
    else if (magnitude < 15)
    {
        gBattleStruct->magnitudeBasePower = 30;
        magnitude = 5;
    }
    else if (magnitude < 35)
    {
        gBattleStruct->magnitudeBasePower = 50;
        magnitude = 6;
    }
    else if (magnitude < 65)
    {
        gBattleStruct->magnitudeBasePower = 70;
        magnitude = 7;
    }
    else if (magnitude < 85)
    {
        gBattleStruct->magnitudeBasePower = 90;
        magnitude = 8;
    }
    else if (magnitude < 95)
    {
        gBattleStruct->magnitudeBasePower = 110;
        magnitude = 9;
    }
    else
    {
        gBattleStruct->magnitudeBasePower = 150;
        magnitude = 10;
    }

    PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff1, 2, magnitude)
}

static void UpdateStallMons(void)
{
    if (IsBattlerTurnDamaged(gBattlerTarget, INCLUDING_SUBSTITUTES) || GetMoveCategory(gCurrentMove) == DAMAGE_CATEGORY_STATUS)
        return;

    struct BattleCalcValues cv = {
        .battlerAtk = gBattlerAttacker,
        .battlerDef = gBattlerTarget,
        .move = gCurrentMove,
    };

    cv.abilities[cv.battlerAtk] = GetBattlerAbility(cv.battlerAtk);
    cv.abilities[cv.battlerDef] = GetBattlerAbility(cv.battlerDef);
    cv.holdEffects[cv.battlerAtk] = GetBattlerHoldEffect(cv.battlerAtk);
    cv.holdEffects[cv.battlerDef] = GetBattlerHoldEffect(cv.battlerDef);

    if (IsBattlerProtected(&cv))
        return;

    enum MoveTarget target = GetBattlerMoveTargetType(cv.battlerAtk, cv.move);
    if (!IsDoubleBattle() || target == TARGET_SELECTED)
    {
        if (gSpecialStatuses[cv.battlerDef].updateStallMons)
            gAiBattleData->playerStallMons[gBattlerPartyIndexes[gBattlerTarget]]++;
    }
    //  Handling for moves that target multiple opponents in doubles not handled currently
}
