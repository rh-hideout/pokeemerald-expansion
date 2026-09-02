#include "global.h"
#include "assertf.h"
#include "battle.h"
#include "battle_set_effect.h"
#include "battle_util.h"
#include "battle_script_commands.h"
#include "battle_hold_effects.h"
#include "battle_message.h"
#include "battle_ai_record.h"
#include "battle_scripts.h"
#include "battle_environment.h"
#include "battle_stat_change.h"
#include "battle_controllers.h"
#include "battle_dynamax.h"
#include "battle_z_move.h"
#include "battle_gimmick.h"
#include "battle_terastal.h"
#include "config_changes.h"
#include "constants/abilities.h"
#include "constants/battle.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_set_effect.h"
#include "constants/battle_string_ids.h"
#include "constants/global.h"
#include "constants/pokemon.h"
#include "constants/script_menu.h"
#include "gba/defines.h"
#include "item.h"
#include "ow_abilities.h"
#include "pokemon.h"
#include "util.h"
#include "move.h"
#include "random.h"
#include "string_util.h"
#include "rtc.h"
#include "event_data.h"
#include "config/battle.h"
#include "constants/game_stat.h"

#define SetEffectFail(failScript, ...) \
    do \
    { \
        se->effectFailed = TRUE; \
        if (!se->silentFailure && !cv->onlyChecking __VA_OPT__(&& __VA_ARGS__))\
        { \
            BattleScriptPushAndSet(se->script, failScript); \
        } \
    } while (0)

#define SetEffectFailAndCheckReturn \
    do \
    { \
        se->effectFailed = TRUE; \
        if (cv->onlyChecking)\
            return; \
    } while (0)

#define SetBattlerTypes(battler, type1, ...) \
    do \
    { \
        gBattleMons[battler].types[0] = type1; \
        gBattleMons[battler].types[1] = DEFAULT(type1, __VA_ARGS__); \
        gBattleMons[battler].types[2] = DEFAULT_2(TYPE_NONE, __VA_ARGS__); \
    } while (0)


static void BattleScriptPushAndSet(const u8 *currentScript, const u8 *effectScript);
static bool32 ShouldTryToApplyEffect(struct BattleCalcValues *cv, struct SetEffect *se);
static inline bool32 IgnoreTargetingForMoveEffect(enum MoveEffect moveEffect);
static bool32 DoesSubstituteBlockMoveEffectOnTarget(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum MoveEffect moveEffect);
static bool32 IsFinalStrikeEffect(enum MoveEffect moveEffect);
static bool32 CanAbilityShieldActivateForBattler(enum BattlerId battler);
static void SwapStatStages(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Stat stat);
static struct TypeBasedHalverInfo GetTypeBasedHalverInfo(enum Type type);
static inline enum MoveEffect GetSynchronizeEffect(u32 status);
enum StringID GetStatus1String(u32 status1);
static s32 GetMaxHpWithRounding(enum BattlerId battler);

static void HandleSetEffectNone(struct BattleCalcValues *cv, struct SetEffect *se)
{
    gBattlescriptCurrInstr = se->script;
}

static bool32 CanSetNonVolatile(struct BattleCalcValues *cv, struct SetEffect *se, enum ResultOption option)
{
    return CanSetNonVolatileStatus(
                    cv->battlerAtk,
                    se->effectBattler,
                    cv->abilities[cv->battlerAtk],
                    cv->abilities[se->effectBattler],
                    se->moveEffect,
                    option
                );
}

static void HandleSetEffectNonVolatile(struct BattleCalcValues *cv, struct SetEffect *se)
{
    bool32 isSafeguardProtected = !se->primary && IsSafeguardProtected(cv->battlerAtk, se->effectBattler, cv->abilities[cv->battlerAtk]);

    se->effectFailed = isSafeguardProtected || !CanSetNonVolatile(cv, se, CHECK_TRIGGER);

    if (cv->onlyChecking) return;

    if (se->effectFailed && !cv->isStatusMove)
    {
        BattleScriptCall(se->script);
        CanSetNonVolatile(cv, se, RUN_SCRIPT);
    }
    else
    {
        SetNonVolatileStatus(cv->battlerAtk, se->effectBattler, se->moveEffect, se->script, TRIGGER_ON_MOVE);
    }
}

static void HandleSetEffectConfusion(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Ability effectAbility = cv->abilities[se->effectBattler];
    enum Ability atkAbility = cv->abilities[cv->battlerAtk];
    enum HoldEffect effectHoldEffect = cv->holdEffects[se->effectBattler];

    if (effectAbility == ABILITY_OWN_TEMPO)
    {
        SetEffectFailAndCheckReturn;
        gBattlerAbility = se->effectBattler;
        BattleScriptPushAndSet(se->script, BattleScript_OwnTempoPreventsRet);
        BattleScriptCall(BattleScript_AbilityPopUp);
    }
    else if (gBattleMons[se->effectBattler].volatiles.confusionTimer > 0)
    {
        SetEffectFailAndCheckReturn;
        gBattleStruct->battlerState[cv->battlerAtk].alreadyStatusedMoveAttempt = TRUE;
        PrepareStringBattleWithWait(STRINGID_PKMNALREADYCONFUSED, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
    else if (IsMistyTerrainAffected(se->effectBattler, effectAbility, effectHoldEffect, gFieldTimers.terrain))
    {
        SetEffectFailAndCheckReturn;
        PrepareStringBattleWithWait(STRINGID_MISTYTERRAINPREVENTS, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
    else if (IsSafeguardProtected(cv->battlerAtk, se->effectBattler, atkAbility))
    {
        SetEffectFailAndCheckReturn;
        PrepareStringBattleWithWait(STRINGID_MISTYTERRAINPREVENTS, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
    else
    {
        gBattleMons[se->effectBattler].volatiles.confusionTimer = RandomUniform(RNG_CONFUSION_TURNS, 2, B_CONFUSION_TURNS); // 2-5 turns
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectConfusion);
    }
}

static void HandleSetEffectFlinch(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->abilities[se->effectBattler] == ABILITY_INNER_FOCUS)
    {
        if (se->primary || se->certain)
        {
            gLastUsedAbility = ABILITY_INNER_FOCUS;
            gBattlerAbility = se->effectBattler;
            RecordAbilityBattle(se->effectBattler, ABILITY_INNER_FOCUS);
            gBattlescriptCurrInstr = se->script;
        }
        else
        {
            gBattlescriptCurrInstr = se->script;
        }
    }
    else if (gBattleMons[se->effectBattler].volatiles.flinched)
    {
        gBattlescriptCurrInstr = se->script;
    }
    else if (!HasBattlerActedThisTurn(se->effectBattler)
          && GetActiveGimmick(se->effectBattler) != GIMMICK_DYNAMAX)
    {
        gBattleMons[se->effectBattler].volatiles.flinched = TRUE;
        gBattlescriptCurrInstr = se->script;
    }
    else
    {
        gBattlescriptCurrInstr = se->script;
    }
}

static void HandleSetEffectAbsorb(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleStruct->moveDamage[cv->battlerDef] > 0
     && IsBattlerTurnDamaged(cv->battlerDef, INCLUDING_SUBSTITUTES)
     && IsBattlerAlive(cv->battlerAtk))
    {
        u32 absorbPercentage = se->additionalEffect->argument.absorbPercentage;

        assertf(absorbPercentage != 0, "Missing absorb percentage for %S", gMovesInfo[cv->move].name)
        {
            return;
        }

        s32 healAmount = (gBattleStruct->moveDamage[cv->battlerDef] * absorbPercentage / 100);
        healAmount = GetDrainedBigRootHp(cv->battlerAtk, healAmount);
        gEffectBattler = cv->battlerAtk;
        gBattlerAbility = gBattleScripting.battler = cv->battlerDef;

        if (cv->abilities[cv->battlerDef] == ABILITY_LIQUID_OOZE
         && (GetMoveEffect(cv->move)!= EFFECT_DREAM_EATER || GetConfig(B_DREAM_EATER_LIQUID_OOZE) >= GEN_5))
        {
            SetPassiveDamageAmount(cv->battlerAtk, healAmount);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABSORB_OOZE;
            BattleScriptPush(se->script);
            gBattlescriptCurrInstr = BattleScript_EffectAbsorbLiquidOoze;
        }
        else if (!IsBattlerAtMaxHp(cv->battlerAtk) || GetConfig(B_ABSORB_MESSAGE) < GEN_5)
        {
            SetHealAmount(cv->battlerAtk, healAmount);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABSORB;
            BattleScriptPush(se->script);
            gBattlescriptCurrInstr = BattleScript_EffectAbsorb;
        }
    }
}

static void HandleSetEffectRandomFromList(struct BattleCalcValues *cv, struct SetEffect *se)
{
    const enum MoveEffect *sRandomFromListEffects = se->additionalEffect->argument.randomMoveEffects;
    u32 validEffectCount = 0;

    while (validEffectCount < MAX_RANDOM_ADDITIONAL_EFFECTS && sRandomFromListEffects[validEffectCount] != MOVE_EFFECT_NONE)
    {
        validEffectCount++;
    }

    assertf(validEffectCount != 0, "Missing or empty randomMoveEffects array for move %S", gMovesInfo[gCurrentMove].name)
    {
        return;
    }

    u32 chosenMoveEffect = RandomUniform(RNG_RANDOM_FROM_LIST, 0, validEffectCount - 1);
    if (sRandomFromListEffects[chosenMoveEffect] == MOVE_EFFECT_BURN)
        gBattleStruct->triAttackBurn = TRUE;

    se->moveEffect = sRandomFromListEffects[chosenMoveEffect];
    SetMoveEffect(cv, se);
}

static void HandleSetEffectUproar(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!gBattleMons[se->effectBattler].volatiles.uproarTurns)
    {
        gBattleMons[se->effectBattler].volatiles.multipleTurns = TRUE;
        gLockedMoves[se->effectBattler] = cv->move;
        gBattleMons[se->effectBattler].volatiles.uproarTurns = B_UPROAR_TURNS >= GEN_5
                                                             ? B_UPROAR_TURN_COUNT - 2
                                                             : RandomUniform(RNG_CONFUSION_TURNS, 2, B_UPROAR_TURN_COUNT);

        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectUproar;
    }
    else
    {
        gBattlescriptCurrInstr = se->script;
    }
}

static void HandleSetEffectPayday(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (IsOnPlayerSide(cv->battlerAtk))
    {
        u16 payday = gPaydayMoney;
        gPaydayMoney += (gBattleMons[cv->battlerAtk].level * 5);
        if (payday > gPaydayMoney)
            gPaydayMoney = 0xFFFF;

        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectPayDay;
    }
    else
    {
        gBattlescriptCurrInstr = se->script;
    }
}

static void HandleSetEffectWrap(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].volatiles.wrapped)
    {
        gBattlescriptCurrInstr = se->script;
    }
    else
    {
        SetWrapTurns(se->effectBattler, GetBattlerHoldEffect(cv->battlerAtk));
        gBattleMons[se->effectBattler].volatiles.wrapped = TRUE;
        gBattleMons[se->effectBattler].volatiles.wrappedMove = cv->move;
        gBattleMons[se->effectBattler].volatiles.wrappedBy = cv->battlerAtk;
        gBattleCommunication[MULTISTRING_CHOOSER] = se->additionalEffect->argument.wrapped;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectWrap;
    }
}

static void HandleSetEffectStatChange(struct BattleCalcValues *cv, struct SetEffect *se)
{
    for (enum Stat i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
    {
        enum Stat stat = sAccurateStatOrder[i];
        s32 stage = GetStatStage(stat, se->additionalEffect);

        if (stage == 0)
            continue;

        if (se->additionalEffect->moveEffect == MOVE_EFFECT_STAT_MINUS)
            stage = -1 * stage;

        SetStatChange(se->effectBattler, stat, stage);
        if (se->additionalEffect->onSide)
            SetStatChange(GetPartnerBattler(se->effectBattler), stat, stage);
    }

    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_MoveEffectStatChange;
}

static void HandleSetEffectRemoveArgType(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Type type = GetMoveArgType(cv->move);

    BattleScriptPush(se->script);

    switch (type)
    {
    case TYPE_FIRE: // Burn Up
        gBattlescriptCurrInstr = BattleScript_RemoveFireType;
        break;
    case TYPE_ELECTRIC: // Double Shot
        gBattlescriptCurrInstr = BattleScript_RemoveElectricType;
        break;
    default:
        gBattlescriptCurrInstr = BattleScript_RemoveGenericType;
        break;
    }
    RemoveBattlerType(se->effectBattler, type);
}

static void HandleSetEffectRecharge(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (B_SKIP_RECHARGE == GEN_1 && !IsBattlerAlive(cv->battlerDef))  // Skip recharge if gen 1 and foe is KO'd
        return;

    gBattleMons[se->effectBattler].volatiles.rechargeTimer = 2;
    gLockedMoves[se->effectBattler] = cv->move;
    gBattlescriptCurrInstr = se->script;
}

static void HandleSetEffectRage(struct BattleCalcValues *cv, struct SetEffect *se)
{
    gBattleMons[se->effectBattler].volatiles.rage = TRUE;
    gBattlescriptCurrInstr = se->script;
}

static void HandleSetEffectPreventEscape(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!gBattleMons[se->effectBattler].volatiles.escapePrevention)
    {
        gBattleMons[se->effectBattler].volatiles.escapePrevention = TRUE;
        gBattleMons[se->effectBattler].volatiles.battlerPreventingEscape = cv->battlerAtk;
    }
    gBattlescriptCurrInstr = se->script;
}

static void HandleSetEffectNightmare(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].volatiles.nightmare
     || !IsAsleepOrComatose(se->effectBattler, cv->abilities[se->effectBattler]))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[se->effectBattler].volatiles.nightmare = TRUE;
        PrepareStringBattleWithWait(STRINGID_PKMNFELLINTONIGHTMARE, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectGlaiveRush(struct BattleCalcValues *cv, struct SetEffect *se)
{
    gBattleMons[se->effectBattler].volatiles.glaiveRush = TRUE;
    gBattlescriptCurrInstr = se->script;
}

static void CureNonVolatile(struct BattleCalcValues *cv, struct SetEffect *se, u32 status, bool32 canCureNonVolatile)
{
    if ((gBattleMons[se->effectBattler].status1 & status) && canCureNonVolatile)
    {
        gBattleScripting.battler = se->effectBattler;
        u32 currNonVolatile = gBattleMons[se->effectBattler].status1;
        gBattleMons[se->effectBattler].status1 = STATUS1_NONE;
        BtlController_EmitSetMonData(se->effectBattler, 0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[se->effectBattler].status1);
        MarkBattlerForControllerExec(se->effectBattler);
        BattleScriptPush(se->script);

        switch (currNonVolatile)
        {
        case STATUS1_PARALYSIS:
            gBattlescriptCurrInstr = BattleScript_BattlerParalyzeHeal;
            break;
        case STATUS1_SLEEP:
            TryDeactivateSleepClause(se->effectBattler, gBattlerPartyIndexes[se->effectBattler]);
            gBattlescriptCurrInstr = BattleScript_BattlerWokeUp;
            break;
        case STATUS1_BURN:
            gBattlescriptCurrInstr = BattleScript_BattlerBurnHeal;
            break;
        case STATUS1_FREEZE:
            gBattlescriptCurrInstr = BattleScript_BattlerDefrosted;
            break;
        case STATUS1_FROSTBITE:
            gBattlescriptCurrInstr = BattleScript_BattlerFrostbiteHealed;
            break;
        case STATUS1_POISON:
        case STATUS1_TOXIC_POISON:
        case STATUS1_PSN_ANY:
            gBattlescriptCurrInstr = BattleScript_BattlerPoisonHealed;
            break;
        }
    }
}
static void HandleSetEffectRemoveStatus(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->onlyChecking) return;

    bool32 canCureNonVolatile = (NumAffectedSpreadMoveTargets() > 1 || !IsMoveEffectBlockedByTarget(cv->abilities[se->effectBattler]));
    u32 argStatus = GetMoveEffectArg_Status(gCurrentMove);
    CureNonVolatile(cv, se, argStatus, canCureNonVolatile);
}

static void HandleSetEffectThrash(struct BattleCalcValues *cv, struct SetEffect *se)
{
    // Petal Dance (dance move) doesn't lock mons that copy the move with Dancer
    if (gSpecialStatuses[se->effectBattler].dancerUsedMove || gBattleMons[se->effectBattler].volatiles.rampageTurns)
    {
        gBattlescriptCurrInstr = se->script;
    }
    else
    {
        gBattleMons[se->effectBattler].volatiles.multipleTurns = TRUE;
        gLockedMoves[se->effectBattler] = cv->move;
        gBattleMons[se->effectBattler].volatiles.rampageTurns = RandomUniform(RNG_RAMPAGE_TURNS, 2, B_RAMPAGE_TURNS);
    }
}

static void HandleSetEffectClearSmog(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Stat stat;
    for (stat = 0; stat < NUM_BATTLE_STATS; stat++)
    {
        if (gBattleMons[se->effectBattler].statStages[stat] != DEFAULT_STAT_STAGE)
            break;
    }
    if (IsBattlerTurnDamaged(se->effectBattler, EXCLUDING_SUBSTITUTES) && stat != NUM_BATTLE_STATS)
    {
        for (u32 i = 0; i < NUM_BATTLE_STATS; i++)
            gBattleMons[se->effectBattler].statStages[i] = DEFAULT_STAT_STAGE;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectClearSmog;
    }
}

static void HandleSetEffectFlameBurst(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattlerId partner = GetPartnerBattler(se->effectBattler);

    if (IsBattlerAlive(partner)
     && !IsSemiInvulnerable(partner, CHECK_ALL)
     && cv->abilities[partner] != ABILITY_MAGIC_GUARD)
    {
        gEffectBattler = partner;
        SetPassiveDamageAmount(partner, gBattleMons[partner].maxHP / 16);
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectFlameBurst;
    }
}

static void HandleSetEffectFeint(struct BattleCalcValues *cv, struct SetEffect *se)
{
    bool32 removeProtect = FALSE;

    if (gProtectStructs[se->effectBattler].protected != PROTECT_NONE
     && gProtectStructs[se->effectBattler].protected != PROTECT_MAX_GUARD)
    {
        gProtectStructs[se->effectBattler].protected = PROTECT_NONE;
        gBattleMons[se->effectBattler].volatiles.consecutiveMoveUses = 0;
        removeProtect = TRUE;
    }
    enum BattlerId partner = GetPartnerBattler(se->effectBattler);
    if (GetProtectType(gProtectStructs[partner].protected) == PROTECT_TYPE_SIDE)
    {
        gProtectStructs[partner].protected = PROTECT_NONE;
        gBattleMons[partner].volatiles.consecutiveMoveUses = 0;
        removeProtect = TRUE;
    }
    if (removeProtect)
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = se->additionalEffect->argument.brokeProtect;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectFeint;
    }
}

static void HandleSetEffectHappyHour(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->onlyChecking) return;

    if (IsOnPlayerSide(se->effectBattler) && !gBattleStruct->moneyMultiplierMove)
    {
        gBattleStruct->moneyMultiplier *= 2;
        gBattleStruct->moneyMultiplierMove = 1;
    }
}

static void HandleSetEffectDoNothing(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->onlyChecking) return;

    PrepareStringBattleWithWait(STRINGID_BUTNOTHINGHAPPENED, se->effectBattler);
    BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
}

static void HandleSetEffectHoldHands(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->battlerAtk == se->effectBattler)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
}

static void HandleSetEffectCelebrate(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->onlyChecking) return;

    PrepareStringBattleWithWait(STRINGID_CELEBRATEMESSAGE, se->effectBattler);
    BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
}

static void HandleSetEffectCoreEnforcer(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (HasBattlerActedThisTurn(se->effectBattler)
     || BattlerJustSwitchedIn(se->effectBattler)
     || NoAliveMonsForEitherParty()
     || gBattleMons[se->effectBattler].volatiles.gastroAcid
     || gAbilitiesInfo[gBattleMons[se->effectBattler].ability].cantBeSuppressed)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (GetBattlerHoldEffectIgnoreAbility(se->effectBattler) == HOLD_EFFECT_ABILITY_SHIELD)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
        if (!cv->onlyChecking)
            RecordItemEffectBattle(se->effectBattler, HOLD_EFFECT_ABILITY_SHIELD);
    }
    else if (!cv->onlyChecking)
    {
        if (gBattleMons[se->effectBattler].volatiles.neutralizingGas)
            gSpecialStatuses[se->effectBattler].neutralizingGasRemoved = TRUE;

        RemoveRuinAbilityFlags(se->effectBattler);
        gBattleMons[se->effectBattler].volatiles.gastroAcid = TRUE;
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectGastroAcid);
    }
}

static void HandleSetEffectThroatChop(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].volatiles.throatChopTimer == 0)
    {
        gBattleMons[se->effectBattler].volatiles.throatChopTimer = B_THROAT_CHOP_TIMER;
        gBattlescriptCurrInstr = se->script;
    }
}

static void HandleSetEffectIncinerate(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->abilities[se->effectBattler] == ABILITY_STICKY_HOLD || gSpecialStatuses[se->effectBattler].berryReduced)
        return;

    if (gItemsInfo[gBattleMons[se->effectBattler].item].pocket == POCKET_BERRIES
     || (B_INCINERATE_GEMS >= GEN_6 && GetItemHoldEffect(gBattleMons[se->effectBattler].item) == HOLD_EFFECT_GEMS))
    {
        gLastUsedItem = gBattleMons[se->effectBattler].item;
        gBattleMons[se->effectBattler].item = ITEM_NONE;
        CheckSetUnburden(se->effectBattler);

        BtlController_EmitSetMonData(se->effectBattler, B_COMM_TO_CONTROLLER, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[se->effectBattler].item), &gBattleMons[se->effectBattler].item);
        MarkBattlerForControllerExec(se->effectBattler);
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectIncinerate;
    }
}

static void HandleSetEffectBugBite(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (GetBattlerHoldEffect(se->effectBattler) == HOLD_EFFECT_JABOCA_BERRY || gSpecialStatuses[se->effectBattler].berryReduced)
    {
        // jaboca berry / resist berries trigger instead of being stolen
        gBattlescriptCurrInstr = se->script;
    }
    else if (GetItemPocket(gBattleMons[se->effectBattler].item) == POCKET_BERRIES
        && cv->abilities[se->effectBattler] != ABILITY_STICKY_HOLD)
    {
        // target loses their berry
        gLastUsedItem = gBattleMons[se->effectBattler].item;
        gBattleMons[se->effectBattler].item = ITEM_NONE;
        CheckSetUnburden(se->effectBattler);

        BtlController_EmitSetMonData(se->effectBattler, B_COMM_TO_CONTROLLER, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[se->effectBattler].item), &gBattleMons[se->effectBattler].item);
        MarkBattlerForControllerExec(se->effectBattler);
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectBugBite;
    }
}

static void HandleSetEffectRecoilHp25(struct BattleCalcValues *cv, struct SetEffect *se)
{
    u32 maxHP = gBattleMons[se->effectBattler].maxHP;
    s32 recoil = maxHP / 4;
    if (B_UPDATED_MOVE_DATA >= GEN_5 && (maxHP % 4) >= 2) // Account for standard rounding (Gen5+)
        recoil++;
    recoil = max(1, recoil);

    SetPassiveDamageAmount(se->effectBattler, recoil);
    TryUpdateEvolutionTracker(IF_RECOIL_DAMAGE_GE, gBattleStruct->passiveHpUpdate[cv->battlerAtk], MOVE_NONE);
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_MoveEffectRecoilHP25;
}

static void HandleSetEffectTrapBoth(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!(gBattleMons[se->effectBattler].volatiles.escapePrevention || gBattleMons[cv->battlerAtk].volatiles.escapePrevention))
    {
        if (!gBattleMons[se->effectBattler].volatiles.escapePrevention)
            gBattleMons[se->effectBattler].volatiles.battlerPreventingEscape = cv->battlerAtk;

        if (!gBattleMons[cv->battlerAtk].volatiles.escapePrevention)
            gBattleMons[cv->battlerAtk].volatiles.battlerPreventingEscape = se->effectBattler;

        gBattleMons[se->effectBattler].volatiles.escapePrevention = TRUE;
        gBattleMons[cv->battlerAtk].volatiles.escapePrevention = TRUE;

        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_BothCanNoLongerEscape;
    }
}

static void HandleSetEffectRound(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (IsDoubleBattle())
    {
        u32 i;
        u32 j = 0;
        u32 k = 0;
        u32 currRounder = 0;
        u8 roundUsers[3] = {0xFF, 0xFF, 0xFF};
        u8 nonRoundUsers[3] = {0xFF, 0xFF, 0xFF};
        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattlerByTurnOrder[i] == cv->battlerAtk)
            {
                currRounder = i + 1; // Current battler going after attacker
                break;
            }
        }

        // Get battlers after attacker using round
        for (i = currRounder; i < gBattlersCount; i++)
        {
            if (gChosenMoveByBattler[gBattlerByTurnOrder[i]] == MOVE_ROUND)
                roundUsers[j++] = gBattlerByTurnOrder[i];
            else
                nonRoundUsers[k++] = gBattlerByTurnOrder[i];
        }

        // update turn order for round users
        for (i = 0; i < 3 && roundUsers[i] != 0xFF; i++)
        {
            gBattlerByTurnOrder[currRounder] = roundUsers[i];
            gProtectStructs[roundUsers[i]].quash = TRUE; // Make it so their turn order can't be changed again
            currRounder++;
        }

        // Update turn order for non-round users
        for (i = 0; i < 3 && nonRoundUsers[i] != 0xFF; i++)
        {
            gBattlerByTurnOrder[currRounder] = nonRoundUsers[i];
            currRounder++;
        }
    }

    gBattlescriptCurrInstr = se->script;
}

static void HandleSetEffectSyrupBomb(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!gBattleMons[se->effectBattler].volatiles.syrupBomb)
    {
        struct Pokemon *mon = GetBattlerMon(cv->battlerAtk);

        gBattleMons[se->effectBattler].volatiles.syrupBomb = TRUE;
        gBattleMons[se->effectBattler].volatiles.stickySyrupedBy = cv->battlerAtk;
        gBattleMons[se->effectBattler].volatiles.syrupBombTimer = B_SYRUP_BOMB_TIMER;
        gBattleMons[se->effectBattler].volatiles.syrupBombIsShiny = IsMonShiny(mon);
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_SyrupBombActivates;
    }
}

static void HandleSetEffectSecretPower(struct BattleCalcValues *cv, struct SetEffect *se)
{
    u32 moveEffect = MOVE_EFFECT_NONE;

    if (IsBattlerAlive(cv->battlerAtk))
    {
        // TODO: Refactor in a way so that the addtional effect constants don't exist anymore
        if (gFieldTimers.terrain != B_TERRAIN_NONE)
            moveEffect = gBattleTerrainInfo[gFieldTimers.terrain].secretPowerEffect;
        else
            moveEffect = gBattleEnvironmentInfo[gBattleEnvironment].secretPowerEffect;

        bool32 statDown = FALSE;
        switch (moveEffect)
        {
        case SECRET_POWER_ATK_MINUS_1:
            SetStatChange(se->effectBattler, STAT_ATK, -1);
            statDown = TRUE;
            break;
        case SECRET_POWER_DEF_MINUS_1:
            SetStatChange(se->effectBattler, STAT_DEF, -1);
            statDown = TRUE;
            break;
        case SECRET_POWER_SPD_MINUS_1:
            SetStatChange(se->effectBattler, STAT_SPEED, -1);
            statDown = TRUE;
            break;
        case SECRET_POWER_SP_ATK_MINUS_1:
            SetStatChange(se->effectBattler, STAT_SPATK, -1);
            statDown = TRUE;
            break;
        case SECRET_POWER_ACC_MINUS_1:
            SetStatChange(se->effectBattler, STAT_ACC, -1);
            statDown = TRUE;
            break;
        default:
            break;
        }

        if (statDown)
        {
            BattleScriptPush(se->script);
            gBattlescriptCurrInstr = BattleScript_MoveEffectStatChange;
        }
        else
        {
            se->moveEffect = moveEffect;
            SetMoveEffect(cv, se);
        }
    }
}

static void HandleSetEffectHealBlock(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattlerId aromaVeilBattler = B_BATTLER_0;

    if (IsAbilityOnSideWithArr(se->effectBattler, ABILITY_AROMA_VEIL, cv->abilities, &aromaVeilBattler))
    {
        se->effectFailed = TRUE;
        if (!cv->onlyChecking)
        {
            gBattlerAbility = aromaVeilBattler;
            BattleScriptPushAndSet(se->script, BattleScript_AromaVeilProtectsRet);
        }
    }
    else if (gBattleMons[se->effectBattler].volatiles.healBlockTimer)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[se->effectBattler].volatiles.healBlockTimer = 2;
        PrepareStringBattleWithWait(STRINGID_PKMNPREVENTEDFROMHEALING, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectTeraBlast(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (GetActiveGimmick(se->effectBattler) == GIMMICK_TERA
     && GetBattlerTeraType(se->effectBattler) == TYPE_STELLAR
     && !NoAliveMonsForEitherParty())
    {
        SetStatChange(se->effectBattler, STAT_ATK, -1);
        SetStatChange(se->effectBattler, STAT_SPATK, -1);
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectStatChange;
    }
}

static void HandleSetEffectOrderUp(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Stat stat = 0;
    bool32 commanderAffected = TRUE;
    switch (gBattleStruct->battlerState[se->effectBattler].commanderSpecies)
    {
    case SPECIES_TATSUGIRI_CURLY:
        stat = STAT_ATK;
        break;
    case SPECIES_TATSUGIRI_DROOPY:
        stat = STAT_DEF;
        break;
    case SPECIES_TATSUGIRI_STRETCHY:
        stat = STAT_SPEED;
        break;
    default:
        commanderAffected = FALSE;
        break;
    }

    if (commanderAffected)
    {
        SetStatChange(se->effectBattler, stat, 1);
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectStatChange;
    }
}

static void HandleSetEffectIonDeluge(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gFieldStatuses & STATUS_FIELD_ION_DELUGE)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gFieldStatuses |= STATUS_FIELD_ION_DELUGE;
        PrepareStringBattleWithWait(STRINGID_IONDELUGEON, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectHaze(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->onlyChecking) return;

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
        TryResetBattlerStatChanges(battler);
    PrepareStringBattleWithWait(STRINGID_STATCHANGESGONE, se->effectBattler);
    BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
}

static void HandleSetEffectLeechSeed(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].volatiles.leechSeed)
    {
        SetEffectFail(BattleScript_EffBattlerAvoidedAttack, cv->isStatusMove);
    }
    else if (IS_BATTLER_OF_TYPE(se->effectBattler, TYPE_GRASS))
    {
        SetEffectFail(BattleScript_ItDoesntAffectEffBattler, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[se->effectBattler].volatiles.leechSeed = LEECHSEEDED_BY(cv->battlerAtk);
        PrepareStringBattleWithWait(STRINGID_PKMNSEEDED, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectProtect(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->onlyChecking) return;

    u32 protectMethod = GetMoveProtectMethod(cv->move);

    if (GetMoveEffect(cv->move) == EFFECT_ENDURE)
    {
        gBattleMons[cv->battlerAtk].volatiles.endured = TRUE;
        PrepareStringBattleWithWait(STRINGID_PKMNBRACEDITSELF, se->effectBattler);
    }
    else if (GetProtectType(protectMethod) == PROTECT_TYPE_SIDE)
    {
        gProtectStructs[cv->battlerAtk].protected = protectMethod;
        PrepareStringBattleWithWait(STRINGID_PKMNSEEDED, se->effectBattler);
    }
    else
    {
        gProtectStructs[cv->battlerAtk].protected = protectMethod;
        PrepareStringBattleWithWait(STRINGID_PKMNPROTECTEDITSELF2, se->effectBattler);
    }

    gBattleMons[cv->battlerAtk].volatiles.consecutiveMoveUses++;
    BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
}

static void HandleSetEffectReflect(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);

    if (gSideStatuses[side] & SIDE_STATUS_REFLECT)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gSideStatuses[side] |= SIDE_STATUS_REFLECT;

        if (cv->holdEffects[se->effectBattler] == HOLD_EFFECT_LIGHT_CLAY)
            gSideTimers[side].reflectTimer = 8;
        else
            gSideTimers[side].reflectTimer = 5;

        PrepareStringBattleWithWait(STRINGID_PKMNRAISEDDEF, se->effectBattler);
    }

    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_MoveEffectSetStatus;
}

static void HandleSetEffectLightScreen(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);

    if (gSideStatuses[side] & SIDE_STATUS_LIGHTSCREEN)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gSideStatuses[side] |= SIDE_STATUS_LIGHTSCREEN;

        if (cv->holdEffects[se->effectBattler] == HOLD_EFFECT_LIGHT_CLAY)
            gSideTimers[side].lightscreenTimer = 8;
        else
            gSideTimers[side].lightscreenTimer = 5;

        PrepareStringBattleWithWait(STRINGID_PKMNRAISEDSPDEF, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectSaltCure(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!gBattleMons[se->effectBattler].volatiles.saltCure)
    {
        gBattleMons[se->effectBattler].volatiles.saltCure = TRUE;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectSaltCure;
    }
}

static void HandleSetEffectEerieSpell(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gLastMoves[se->effectBattler] == MOVE_NONE || gLastMoves[se->effectBattler] == MOVE_UNAVAILABLE)
        return;

    enum Move moveToReduce = gLastMoves[se->effectBattler];

    if (IsMaxMove(moveToReduce))
        moveToReduce = gBattleStruct->dynamax.baseMoves[se->effectBattler];

    u32 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moveToReduce == gBattleMons[se->effectBattler].moves[i])
            break;
    }

    if (i != MAX_MON_MOVES && gBattleMons[se->effectBattler].pp[i] != 0)
    {
        u32 ppToDeduct = 3;

        if (gBattleMons[se->effectBattler].pp[i] < ppToDeduct)
            ppToDeduct = gBattleMons[se->effectBattler].pp[i];

        PREPARE_MOVE_BUFFER(gBattleTextBuff1, moveToReduce)
        ConvertIntToDecimalStringN(gBattleTextBuff2, ppToDeduct, STR_CONV_MODE_LEFT_ALIGN, 1);
        PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff2, 1, ppToDeduct)
        gBattleMons[se->effectBattler].pp[i] -= ppToDeduct;
        if (!(gBattleMons[se->effectBattler].volatiles.mimickedMoves & (1u << i))
            && !(gBattleMons[se->effectBattler].volatiles.transformed))
        {
            BtlController_EmitSetMonData(se->effectBattler, B_COMM_TO_CONTROLLER, REQUEST_PPMOVE1_BATTLE + i, 0, sizeof(gBattleMons[se->effectBattler].pp[i]), &gBattleMons[se->effectBattler].pp[i]);
            MarkBattlerForControllerExec(se->effectBattler);
        }

        if (gBattleMons[se->effectBattler].pp[i] == 0)
            CancelMultiTurnMoves(se->effectBattler);

        PrepareStringBattleWithWait(STRINGID_PKMNREDUCEDPP, cv->battlerAtk);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectFling(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (CanFling(cv->battlerAtk, cv->abilities[cv->battlerAtk]) || gBattleStruct->flungItem == FLUNG_ITEM_REMOVED)
    {
        enum Item item = ITEM_NONE;

        switch (gBattleStruct->flungItem)
        {
        case FLUNG_ITEM_NONE:
            gBattleStruct->flungItem = FLUNG_ITEM_REMOVE;
            item = gLastUsedItem = gBattleStruct->flingItem = gBattleMons[cv->battlerAtk].item;
            break;
        case FLUNG_ITEM_REMOVE:
        case FLUNG_ITEM_REMOVED:
            gBattleStruct->flungItem = FLUNG_ITEM_REMOVED;
            item = gLastUsedItem = gBattleStruct->flingItem;
            break;
        }

        enum HoldEffect holdEffect = GetItemHoldEffect(item);

        if (IsMoveEffectBlockedByTarget(cv->abilities[se->effectBattler]))
        {
            BattleScriptPush(se->script);
            gBattlescriptCurrInstr = BattleScript_FlingBlockedByShieldDust;
            return;
        }

        if (GetItemPocket(item) == POCKET_BERRIES)
        {
            BattleScriptPush(se->script);
            gBattlescriptCurrInstr = BattleScript_FlingConsumeBerry;
            return;
        }

        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_RemoveItem;

        struct SetEffect flingEffect = {0};
        flingEffect.script = gBattlescriptCurrInstr;
        flingEffect.effectBattler = se->effectBattler;

        switch (holdEffect)
        {
        case HOLD_EFFECT_FLAME_ORB:
            flingEffect.moveEffect = MOVE_EFFECT_BURN;
            SetMoveEffect(cv, &flingEffect);
            break;
        case HOLD_EFFECT_TOXIC_ORB:
            flingEffect.moveEffect = MOVE_EFFECT_TOXIC;
            SetMoveEffect(cv, &flingEffect);
            break;
        case HOLD_EFFECT_LIGHT_BALL:
            flingEffect.moveEffect = MOVE_EFFECT_PARALYSIS;
            SetMoveEffect(cv, &flingEffect);
            break;
        case HOLD_EFFECT_TYPE_POWER:
            if (GetItemSecondaryId(item) == TYPE_POISON)
            {
                flingEffect.moveEffect = MOVE_EFFECT_POISON;
                SetMoveEffect(cv, &flingEffect);
            }
            break;
        case HOLD_EFFECT_FLINCH:
            flingEffect.moveEffect = MOVE_EFFECT_FLINCH;
            SetMoveEffect(cv, &flingEffect);
            break;
        case HOLD_EFFECT_MENTAL_HERB:
        case HOLD_EFFECT_WHITE_HERB:
            ItemBattleEffects(se->effectBattler, 0, holdEffect, IsOnFlingActivation);
            break;
        default:
            break;
        }
    }
}

static void HandleSetEffectRainbow(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);

    if (gSideStatuses[side] & SIDE_STATUS_RAINBOW)
        return;

    gSideStatuses[side] |= SIDE_STATUS_RAINBOW;
    gSideTimers[side].rainbowTimer = 4;
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_TheRainbowActivates;
}

static void HandleSetEffectSeaOfFire(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);

    if (gSideStatuses[side] & SIDE_STATUS_SEA_OF_FIRE)
        return;

    gSideStatuses[side] |= SIDE_STATUS_SEA_OF_FIRE;
    gSideTimers[side].seaOfFireTimer = 4;
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_SeaOfFireActivates;
}

static void HandleSetEffectSwamp(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);
    if (gSideStatuses[side] & SIDE_STATUS_SWAMP)
        return;

    gSideStatuses[side] |= SIDE_STATUS_SWAMP;
    gSideTimers[side].swampTimer = 4;
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_TheSwampActivates;
}

static void HandleSetEffectPresent(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!cv->isStatusMove) return;

    if (gBattleMons[se->effectBattler].hp == gBattleMons[se->effectBattler].maxHP)
    {
        SetEffectFail(BattleScript_EffBattlerAtFullHp, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        SetHealAmount(se->effectBattler, GetMaxHpWithRounding(se->effectBattler) / 4);
        BattleScriptPushAndSet(se->script, BattleScript_RestoreHpEffectBattler);
    }
}

static void HandleSetEffectSwallow(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].hp == gBattleMons[se->effectBattler].maxHP)
    {
        if (!cv->onlyChecking)
            gBattleMons[se->effectBattler].volatiles.stockpileCounter = 0;
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        if (gBattleMons[se->effectBattler].volatiles.stockpileCounter > 0)
        {
            SetHealAmount(se->effectBattler, GetMaxHpWithRounding(se->effectBattler) / (1 << (3 - gBattleMons[se->effectBattler].volatiles.stockpileCounter)));
            gBattleScripting.animTurn = gBattleMons[se->effectBattler].volatiles.stockpileCounter;
        }
        else // Snatched move
        {
            SetHealAmount(se->effectBattler, GetMaxHpWithRounding(se->effectBattler) / 4);
            gBattleScripting.animTurn = 1;
        }
        BattleScriptPushAndSet(se->script, BattleScript_RestoreHpEffectBattler);
    }
}

static void HandleSetEffectPurify(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!(gBattleMons[se->effectBattler].status1 & STATUS1_ANY))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        if (gBattleMons[cv->battlerAtk].hp < gBattleMons[cv->battlerAtk].maxHP)
        {
            s32 restoreHpModifier = se->additionalEffect->argument.restoreHpModifier;
            s32 healAmount = GetMaxHpWithRounding(cv->battlerAtk) / restoreHpModifier;
            SetHealAmount(cv->battlerAtk, healAmount);
            BattleScriptPushAndSet(se->script, BattleScript_Purify);
        }
    }
}

static void HandleSetEffectWish(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[cv->battlerAtk].volatiles.healBlockTimer
     || gBattleStruct->wish[cv->battlerAtk].counter > 0)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleStruct->wish[cv->battlerAtk].counter = 2;
        gBattleStruct->wish[cv->battlerAtk].partyId = gBattlerPartyIndexes[cv->battlerAtk];
    }
}

static void SetEffectRestoreHp(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].hp == gBattleMons[se->effectBattler].maxHP)
    {
        SetEffectFail(BattleScript_EffBattlerAtFullHp, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        s32 restoreHpModifier = se->additionalEffect->argument.restoreHpModifier;
        s32 healAmount = GetMaxHpWithRounding(se->effectBattler) / restoreHpModifier;
        SetHealAmount(se->effectBattler, healAmount);
        BattleScriptPushAndSet(se->script, BattleScript_RestoreHpEffectBattler);
    }
}

static void HandleSetEffectRoost(struct BattleCalcValues *cv, struct SetEffect *se)
{
    SetEffectRestoreHp(cv, se);
    gBattleMons[gBattlerAttacker].volatiles.roostActive = TRUE;
}

static void HandleSetEffectRestoreHp(struct BattleCalcValues *cv, struct SetEffect *se)
{
    SetEffectRestoreHp(cv, se);
}

static u32 GetWeatherHealingModifier(u32 moveEffect)
{
    u32 time = GetTimeOfDay();

    switch (moveEffect)
    {
    case EFFECT_MOONLIGHT:
        if (time == TIME_NIGHT || time == TIME_EVENING)
            return 2;
        break;
    case EFFECT_MORNING_SUN:
        if ((OW_TIMES_OF_DAY == GEN_3 && time == TIME_DAY) // Gen 3 doesn't have morning
          || (OW_TIMES_OF_DAY != GEN_3 && time == TIME_MORNING))
            return 2;
        break;
    case EFFECT_SYNTHESIS:
        if (time == TIME_DAY)
            return 2;
        break;
    default:
        return 1;
    }

    return 1;
}

static void HandleSetEffectRestoreHpOnWeather(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].hp == gBattleMons[se->effectBattler].maxHP)
    {
        SetEffectFail(BattleScript_EffBattlerAtFullHp, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        s32 moveResstoreHpModifier = se->additionalEffect->argument.restoreHpModifier;
        s32 maxHpWithRounding = GetMaxHpWithRounding(se->effectBattler);

        s32 recoverAmount = 0;
        u32 weather = GetWeather();
        u32 attackerWeather = GetAttackerWeather(cv->holdEffects[cv->battlerAtk], cv->abilities[cv->battlerAtk], weather);
        u32 healingWeather = attackerWeather & ~B_WEATHER_STRONG_WINDS;
        bool32 isAffectedByMegaSol = cv->abilities[cv->battlerAtk] == ABILITY_MEGA_SOL && !(weather & B_WEATHER_SUN);
        bool32 megaSolActivates = FALSE;
        bool32 isUnaffectedByWeather = !(healingWeather & B_WEATHER_ANY) || cv->holdEffects[se->effectBattler] == HOLD_EFFECT_UTILITY_UMBRELLA;

        if (cv->moveEffect == EFFECT_SHORE_UP)
        {
            if (attackerWeather & B_WEATHER_SANDSTORM)
                recoverAmount = 20 * maxHpWithRounding / 30;
            else
                recoverAmount = maxHpWithRounding / moveResstoreHpModifier;
        }
        else if (GetConfig(B_TIME_OF_DAY_HEALING_MOVES) != GEN_2)
        {
            if (attackerWeather & B_WEATHER_SUN)
            {
                recoverAmount = 20 * maxHpWithRounding / 30;
                megaSolActivates = isAffectedByMegaSol;
            }
            else if (isUnaffectedByWeather)
            {
                recoverAmount = maxHpWithRounding /  moveResstoreHpModifier;
            }
            else // not sunny weather
            {
                recoverAmount = maxHpWithRounding / 4;
            }
        }
        else // B_TIME_OF_DAY_HEALING_MOVES == GEN_2
        {
            u32 healingModifier = GetWeatherHealingModifier(cv->moveEffect);

            if (attackerWeather & B_WEATHER_SUN)
            {
                recoverAmount = healingModifier * maxHpWithRounding  / moveResstoreHpModifier;
                megaSolActivates = isAffectedByMegaSol;
            }
            else if (isUnaffectedByWeather)
            {
                recoverAmount = healingModifier * maxHpWithRounding / 4;
            }
            else // not sunny weather
            {
                recoverAmount = healingModifier * maxHpWithRounding / 8;
            }
        }

        SetHealAmount(se->effectBattler, recoverAmount);
        if (megaSolActivates)
        {
            gBattlerAbility = cv->battlerAtk;
            BattleScriptPushAndSet(se->script, BattleScript_MegaSolActivatesHealing);
        }
        else
        {
            BattleScriptPushAndSet(se->script, BattleScript_RestoreHpEffectBattler);
        }
    }
}

static void SetEffectHealPulse(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].hp == gBattleMons[se->effectBattler].maxHP)
    {
        SetEffectFail(BattleScript_EffBattlerAtFullHp, cv->isStatusMove);
    }
    else if (gBattleMons[cv->battlerAtk].volatiles.healBlockTimer
          || gBattleMons[se->effectBattler].volatiles.healBlockTimer)
    {
        SetEffectFail(BattleScript_MoveUsedHealBlockPreventsRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        u32 maxHpWithRounding = GetMaxHpWithRounding(se->effectBattler);
        s32 restoreHpModifier = se->additionalEffect->argument.restoreHpModifier;

        s32 healAmount;
        if (cv->abilities[cv->battlerAtk] == ABILITY_MEGA_LAUNCHER && IsPulseMove(cv->move))
            healAmount = maxHpWithRounding  * 75 / 100;
        else if (gFieldTimers.terrain == B_TERRAIN_GRASSY && se->moveEffect == MOVE_EFFECT_FLORAL_HEALING)
            healAmount = maxHpWithRounding * restoreHpModifier / 3;
        else
            healAmount = maxHpWithRounding / restoreHpModifier;

       SetHealAmount(se->effectBattler, healAmount);
       BattleScriptPushAndSet(se->script, BattleScript_RestoreHpEffectBattler);
    }
}

static void HandleSetEffectHealPulse(struct BattleCalcValues *cv, struct SetEffect *se)
{
    SetEffectHealPulse(cv, se);
}

static void HandleSetEffectPollenPuff(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!cv->isStatusMove) return;
    SetEffectHealPulse(cv, se);
}

static enum BattleWeather GetPreferredWeather(void)
{
    if (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW)
        return BATTLE_WEATHER_SNOW;
    return BATTLE_WEATHER_HAIL;
}

static void HandleSetEffectWeather(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleWeather weather = 0;
    switch (se->moveEffect)
    {
    case MOVE_EFFECT_SUN:
        weather = BATTLE_WEATHER_SUN;
        break;
    case MOVE_EFFECT_RAIN:
        weather = BATTLE_WEATHER_RAIN;
        break;
    case MOVE_EFFECT_SANDSTORM:
        weather = BATTLE_WEATHER_SANDSTORM;
        break;
    case MOVE_EFFECT_HAIL:
        weather = GetPreferredWeather();
        break;
    case MOVE_EFFECT_SNOW:
        weather = GetPreferredWeather();
        break;
    default:
        break;
    }

    if (gBattleWeather & B_WEATHER_PRIMAL_ANY)
    {
        SetEffectFail(BattleScript_FailOnPrimalWeather, cv->isStatusMove);
    }

    if (gBattleWeather & gBattleWeatherInfo[weather].flag)
        se->effectFailed = TRUE;

    if (gBattleStruct->overworldWeatherPresent)
        se->effectFailed = TRUE;

    if (cv->onlyChecking) return;

    if (TryChangeBattleWeather(cv->battlerAtk, weather, ABILITY_NONE) == WEATHER_FAILURE_SUCCESS)
    {
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetWeather);
    }
    else
    {
        if (cv->moveEffect == EFFECT_WEATHER_AND_SWITCH) return;
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
}

static void HandleSetEffectTerrain(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleTerrain terrain = B_TERRAIN_NONE;
    switch (se->moveEffect)
    {
    case MOVE_EFFECT_MISTY_TERRAIN:
        terrain = B_TERRAIN_MISTY;
        break;
    case MOVE_EFFECT_GRASSY_TERRAIN:
        terrain = B_TERRAIN_GRASSY;
        break;
    case MOVE_EFFECT_ELECTRIC_TERRAIN:
        terrain = B_TERRAIN_ELECTRIC;
        break;
    case MOVE_EFFECT_PSYCHIC_TERRAIN:
        terrain = B_TERRAIN_PSYCHIC;
        break;
    default:
        break;
    }

    if (gBattleStruct->isSkyBattle || terrain == gFieldTimers.terrain)
        se->effectFailed = TRUE;

    if (cv->onlyChecking) return;

    if (TryChangeBattleTerrain(cv->battlerAtk, terrain))
    {
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetTerrain);
    }
    else
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
}

static void HandleSetEffectGmaxNonTypeDamage(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);
    if (!(gSideStatuses[side] & SIDE_STATUS_DAMAGE_NON_TYPES))
    {
        u32 moveType = GetMoveType(gCurrentMove);
        gSideStatuses[side] |= SIDE_STATUS_DAMAGE_NON_TYPES;
        gSideTimers[side].damageNonTypesTimer = 5;
        gSideTimers[side].damageNonTypesType = moveType;
        BattleScriptPush(se->script);
        ChooseDamageNonTypesString(moveType);
        gBattlescriptCurrInstr = BattleScript_MoveEffectDamageNonTypes;
    }
}

static void HandleSetEffectEffectSporeSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectEffectSporeSide;
}

static void HandleSetEffectParalyzeSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectParalyzeSide;
}

static void HandleSetEffectConfusePayDaySide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && IsOnPlayerSide(cv->battlerAtk))
    {
        u32 payday = gPaydayMoney;
        gPaydayMoney += (gBattleMons[cv->battlerAtk].level * 100);
        if (payday > gPaydayMoney)
            gPaydayMoney = 0xFFFF;
        gBattleCommunication[CURSOR_POSITION] = 1; // add "Coins scattered." message
    }

    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectConfuseSide;
}

static void HandleSetEffectCritPlusSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].volatiles.bonusCritStages < 3)
        gBattleMons[se->effectBattler].volatiles.bonusCritStages++;

    enum BattlerId partner = GetPartnerBattler(se->effectBattler);
    if (gBattleMons[partner].volatiles.bonusCritStages < 3)
        gBattleMons[partner].volatiles.bonusCritStages++;

    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectRaiseCritAlliesAnim;
}

static void HandleSetEffectPreventEscapeSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectMeanLookSide;
}

static void HandleSetEffectAuroraVeil(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);

    if (gSideStatuses[side] & SIDE_STATUS_AURORA_VEIL)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gSideStatuses[side] |= SIDE_STATUS_AURORA_VEIL;

        if (cv->holdEffects[se->effectBattler] == HOLD_EFFECT_LIGHT_CLAY)
            gSideTimers[side].auroraVeilTimer = 8;
        else
            gSideTimers[side].auroraVeilTimer = 5;

        PrepareStringBattleWithWait(STRINGID_PKMNAURORAVEIL, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectInfatuateSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectInfatuateSide;
}

static void HandleSetEffectRecycleBerriesSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (RandomPercentage(RNG_G_MAX_REPLENISH, 50))
    {
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_EffectRecycleBerriesAllies;
    }
}

static void HandleSetEffectRecycle(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Item *usedHeldItem = &GetBattlerPartyState(se->effectBattler)->usedHeldItem;

    if (*usedHeldItem == ITEM_NONE || gBattleMons[se->effectBattler].item != ITEM_NONE)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gLastUsedItem = *usedHeldItem;
        *usedHeldItem = ITEM_NONE;
        gBattleMons[se->effectBattler].item = gLastUsedItem;
        gBattleMons[se->effectBattler].volatiles.unburdenActive = FALSE;

        BtlController_EmitSetMonData(
                se->effectBattler,
                B_COMM_TO_CONTROLLER,
                REQUEST_HELDITEM_BATTLE,
                0,
                sizeof(gBattleMons[se->effectBattler].item),
                &gBattleMons[se->effectBattler].item
            );
        MarkBattlerForControllerExec(se->effectBattler);

        PrepareStringBattleWithWait(STRINGID_XFOUNDONEY, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectPoisonSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectPoisonSide;
}

static void HandleSetEffectDefog(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gSideStatuses[GetBattlerSide(se->effectBattler)] & SIDE_STATUS_SCREEN_ANY
     || AreAnyHazardsOnSide(GetBattlerSide(se->effectBattler))
     || AreAnyHazardsOnSide(GetBattlerSide(cv->battlerAtk))
     || gFieldTimers.terrain != B_TERRAIN_NONE)
    {
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectDefog;
    }
}

static void HandleSetEffectPoisonParalyzeSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectPoisonParalyzeSide;
}

static void HandleSetEffectHealTeam(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectHealOneSixthAllies;
}

static bool32 HasValidMoveToReducePP(enum BattlerId battler, u32 *moveSlot)
{
    // Get move slot to reduce PP.
    if (IsMaxMove(gLastMoves[battler]))
    {
        for (u32 i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleStruct->dynamax.baseMoves[battler] == gBattleMons[battler].moves[i])
            {
                *moveSlot = i;
                break;
            }
        }
    }
    else
    {
        for (u32 i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gLastMoves[battler] == gBattleMons[battler].moves[i])
            {
                *moveSlot = i;
                break;
            }
        }
    }

    bool32 spiteThreshold = (B_CAN_SPITE_FAIL >= GEN_4 ? 0 : 1);
    if (*moveSlot == MAX_MON_MOVES || gBattleMons[battler].pp[*moveSlot] <= spiteThreshold)
        return FALSE;

    return TRUE;
}

static void HandleSetEffectSpite(struct BattleCalcValues *cv, struct SetEffect *se)
{
    u32 moveSlot = 0;
    enum Move lastMove = gLastMoves[se->effectBattler];

    if (lastMove == MOVE_NONE
     || lastMove == MOVE_UNAVAILABLE
     || !HasValidMoveToReducePP(se->effectBattler, &moveSlot))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        s32 ppToDeduct = B_PP_REDUCED_BY_SPITE >= GEN_4 ? 4 : (Random() & 3) + 2;

        if (IsMaxMove(cv->move)) // G-Max Depletion only deducts 2 PP.
            ppToDeduct = 2;

        if (gBattleMons[se->effectBattler].pp[moveSlot] < ppToDeduct)
            ppToDeduct = gBattleMons[se->effectBattler].pp[moveSlot];

        PREPARE_MOVE_BUFFER(gBattleTextBuff1, gLastMoves[se->effectBattler])

        ConvertIntToDecimalStringN(gBattleTextBuff2, ppToDeduct, STR_CONV_MODE_LEFT_ALIGN, 1);

        PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff2, 1, ppToDeduct)

        gBattleMons[se->effectBattler].pp[moveSlot] -= ppToDeduct;

        // if (MOVE_IS_PERMANENT(gBattlerTarget, i)), but backwards
        if (!(gBattleMons[se->effectBattler].volatiles.mimickedMoves & (1u << moveSlot))
            && !(gBattleMons[se->effectBattler].volatiles.transformed))
        {
            BtlController_EmitSetMonData(
                    se->effectBattler,
                    B_COMM_TO_CONTROLLER,
                    REQUEST_PPMOVE1_BATTLE + moveSlot,
                    0,
                    sizeof(gBattleMons[se->effectBattler].pp[moveSlot]),
                    &gBattleMons[se->effectBattler].pp[moveSlot]
                );
            MarkBattlerForControllerExec(se->effectBattler);
        }

        if (gBattleMons[se->effectBattler].pp[moveSlot] == 0)
            CancelMultiTurnMoves(se->effectBattler);

        PrepareStringBattleWithWait(STRINGID_PKMNREDUCEDPP, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectGravity(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gFieldStatuses & STATUS_FIELD_GRAVITY)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gFieldStatuses |= STATUS_FIELD_GRAVITY;
        gFieldTimers.gravityTimer = 5;
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectGravity);
    }
}

static void HandleSetEffectYawnFoe(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].volatiles.yawn == 0
     && CanBeSlept(cv->battlerAtk, se->effectBattler, cv->abilities[se->effectBattler], BLOCKED_BY_SLEEP_CLAUSE)
     && RandomPercentage(RNG_G_MAX_SNOOZE, 50))
    {
        gBattleMons[se->effectBattler].volatiles.yawn = 2;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectYawnFoe;
    }
}

static void HandleSetEffectAromatherapy(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_MoveEffectAromatherapy;
}

static void HandleSetEffectConfuseSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectConfuseSide;
}

static void HandleSetEffectSteelsurge(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);
    if (IsHazardOnSide(side, HAZARDS_STEELSURGE))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        PushHazardTypeToQueue(side, HAZARDS_STEELSURGE);
        PrepareStringBattleWithWait(STRINGID_POINTEDSTONESFLOAT, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectStealthRock(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);

    if (IsHazardOnSide(side, HAZARDS_STEALTH_ROCK))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        PushHazardTypeToQueue(side, HAZARDS_STEALTH_ROCK);
        PrepareStringBattleWithWait(STRINGID_POINTEDSTONESFLOAT, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectTormentSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectTormentSide;
}

static void HandleSetEffectFireSpinSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; ++battler)
    {
        if (!IsBattlerAlly(battler, se->effectBattler))
            continue;

        if (!gBattleMons[battler].volatiles.wrapped)
        {
            gBattleMons[battler].volatiles.wrapped = TRUE;
            SetWrapTurns(battler, GetBattlerHoldEffect(cv->battlerAtk));
            // The Wrap effect does not expire when the user switches, so here's some cheese.
            gBattleMons[battler].volatiles.wrappedBy = se->effectBattler;
            gBattleMons[battler].volatiles.wrappedMove = MOVE_FIRE_SPIN;
        }
    }
}

static void HandleSetEffectSandblastSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; ++battler)
    {
        if (!IsBattlerAlly(battler, se->effectBattler))
            continue;

        if (!gBattleMons[battler].volatiles.wrapped)
        {
            gBattleMons[battler].volatiles.wrapped = TRUE;
            SetWrapTurns(battler, GetBattlerHoldEffect(cv->battlerAtk));
            // The Wrap effect does not expire when the user switches, so here's some cheese.
            gBattleMons[battler].volatiles.wrappedBy = se->effectBattler;
            gBattleMons[battler].volatiles.wrappedMove = MOVE_SAND_TOMB;
        }
    }
}

static void HandleSetEffectBreakScreen(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side;

    if (B_BRICK_BREAK >= GEN_4)
        side = GetBattlerSide(cv->battlerDef); // From Gen 4 onwards, Brick Break can remove screens on the user's side if used on an ally
    else
        side = GetBattlerSide(cv->battlerAtk) ^ BIT_SIDE;

    if (gSideStatuses[side] & SIDE_STATUS_SCREEN_ANY)
    {
        bool32 failed;

        if (B_BRICK_BREAK >= GEN_5)
            failed = gBattleStruct->moveResultFlags[cv->battlerDef] & MOVE_RESULT_NO_EFFECT;
        else
            failed = FALSE;

        if (!failed)
        {
            if (gSideTimers[side].reflectTimer)
                gBattleCommunication[MULTISTRING_CHOOSER] |= 1 << 0;
            if (gSideTimers[side].lightscreenTimer)
                gBattleCommunication[MULTISTRING_CHOOSER] |= 1 << 1;
            if (gSideTimers[side].auroraVeilTimer)
                gBattleCommunication[MULTISTRING_CHOOSER] |= 1 << 2;

            gSideStatuses[side] &= ~SIDE_STATUS_SCREEN_ANY;
            gBattleScripting.animTurn = 1;
            gBattleScripting.animTargetsHit = 1;
            gBattleStruct->attackAnimPlayed = TRUE; // The whole brick break animation is covered by the move so don't play twice
            BattleScriptPush(se->script);
            gBattlescriptCurrInstr = BattleScript_BreakScreens;
        }
        else
        {
            gBattleScripting.animTurn = 0;
            gBattleScripting.animTargetsHit = 0;
        }
    }
}

static void HandleSetEffectStealStats(struct BattleCalcValues *cv, struct SetEffect *se)
{
    bool32 atLeastOneStatStolen = FALSE;

    for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
    {
        s32 stageToSteal = gBattleMons[se->effectBattler].statStages[stat];

        if (stageToSteal > DEFAULT_STAT_STAGE && gBattleMons[cv->battlerAtk].statStages[stat] != MAX_STAT_STAGE)
        {
            atLeastOneStatStolen = TRUE;
            gBattleMons[se->effectBattler].statStages[stat] = DEFAULT_STAT_STAGE;
            SetStatChange(cv->battlerAtk, stat, stageToSteal - DEFAULT_STAT_STAGE);
        }
    }

    if (atLeastOneStatStolen)
    {
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_StealStats;
    }
}

static void HandleSetEffectBeatUpMessage(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (GetConfig(B_BEAT_UP) >= GEN_5) // Gen5+ don't print any custom message on attack
        return;

    if (!IsBattlerAlive(cv->battlerDef))
    {
        gMultiHitCounter = 0;
        gBattlescriptCurrInstr = BattleScript_MoveEnd;
    }
    else if (gBattleStruct->beatUpSlot == 0 && gMultiHitCounter == 0)
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
    }
    else
    {
        PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, cv->battlerAtk, gBattleStruct->beatUpSpecies[gBattleStruct->beatUpSlot])
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_BeatUpAttackMessage;
    }
}

static void HandleSetEffectItemMessage(struct BattleCalcValues *cv, struct SetEffect *se)
{
    gLastUsedItem = gBattleMons[se->effectBattler].item;
    BattleScriptPush(se->script);

    if (se->effectBattler == cv->battlerAtk)
        gBattlescriptCurrInstr = BattleScript_FlingMessage;
    else
        gBattlescriptCurrInstr = BattleScript_PoltergeistMessage;
}

static void HandleSetEffectSpeedSwap(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->onlyChecking) return;

    u32 temp;
    SWAP(gBattleMons[cv->battlerAtk].speed, gBattleMons[gBattlerTarget].speed, temp);
    gBattleMons[cv->battlerAtk].volatiles.speedSwapped = TRUE;
    gBattleMons[se->effectBattler].volatiles.speedSwapped = TRUE;
    PrepareStringBattleWithWait(STRINGID_ATTACKERSWITCHEDSTATWITHTARGET, se->effectBattler);
    BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
}

static void HandleSetEffectSafeguard(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);

    if (gSideStatuses[side] & SIDE_STATUS_SAFEGUARD)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gSideStatuses[side] |= SIDE_STATUS_SAFEGUARD;
        gSideTimers[side].safeguardTimer = 5;
        PrepareStringBattleWithWait(STRINGID_PKMNCOVEREDBYVEIL, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

// For generic (simple) volatiles
static void TryEffectVolatile(struct BattleCalcValues *cv, struct SetEffect *se, u32 _volatile, u32 value, enum StringID string)
{
    if (GetBattlerVolatile(se->effectBattler, _volatile) != 0)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        SetMonVolatile(se->effectBattler, _volatile, value);
        PrepareStringBattleWithWait(string, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectLaserFocus(struct BattleCalcValues *cv, struct SetEffect *se)
{
    TryEffectVolatile(cv, se, VOLATILE_LASER_FOCUS_TIMER, B_LASER_FOCUS_TIMER, STRINGID_LASERFOCUS);
}

static void HandleSetEffectPowder(struct BattleCalcValues *cv, struct SetEffect *se)
{
    TryEffectVolatile(cv, se, VOLATILE_POWDER, TRUE, STRINGID_COVEREDINPOWDER);
}

static void HandleSetEffectAquaRing(struct BattleCalcValues *cv, struct SetEffect *se)
{
    TryEffectVolatile(cv, se, VOLATILE_AQUA_RING, TRUE, STRINGID_PKMNSURROUNDEDWITHVEILOFWATER);
}

static void HandleSetEffectEmbargo(struct BattleCalcValues *cv, struct SetEffect *se)
{
    TryEffectVolatile(cv, se, VOLATILE_EMBARGO_TIMER, B_EMBARGO_TIMER, STRINGID_PKMNCANTUSEITEMSANYMORE);
}

static void HandleSetEffectMiracleEye(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (GetConfig(B_MIRACLE_EYE_FAIL) >= GEN_5 && gBattleMons[se->effectBattler].volatiles.miracleEye)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else
    {
        TryEffectVolatile(cv, se, VOLATILE_MIRACLE_EYE, TRUE, STRINGID_PKMNIDENTIFIED);
    }
}

static void HandleSetEffectForesight(struct BattleCalcValues *cv, struct SetEffect *se)
{
    u32 config = GetConfig(B_FORESIGHT_FAIL);
    bool32 printsFailureMessage = (config < GEN_3 || config >= GEN_5);

    if (printsFailureMessage && gBattleMons[se->effectBattler].volatiles.foresight)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else
    {
        TryEffectVolatile(cv, se, VOLATILE_FORESIGHT, TRUE, STRINGID_PKMNIDENTIFIED);
    }
}

static void HandleSetEffectDestinyBond(struct BattleCalcValues *cv, struct SetEffect *se)
{
    TryEffectVolatile(cv, se, VOLATILE_DESTINY_BOND, 2, STRINGID_PKMNTRYINGTOTAKEFOE);
}

static void HandleSetEffectGrudge(struct BattleCalcValues *cv, struct SetEffect *se)
{
    TryEffectVolatile(cv, se, VOLATILE_GRUDGE, TRUE, STRINGID_PKMNWANTSGRUDGE);
}

static void HandleSetEffectMagnetRise(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].volatiles.root
     || gBattleMons[se->effectBattler].volatiles.smackDown
     || gBattleMons[se->effectBattler].volatiles.magnetRiseTimer)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else
    {
        TryEffectVolatile(cv, se, VOLATILE_MAGNET_RISE_TIMER, B_MAGNET_RISE_TIMER, STRINGID_PKMNLEVITATEDONELECTROMAGNETISM);
    }
}

static void HandleSetEffectToxicSpikes(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);

    if (gSideTimers[side].toxicSpikesAmount >= 2)
    {
        SetEffectFail(BattleScript_ButItFailedRet);
    }
    else if (!cv->onlyChecking)
    {
        if (gSideTimers[side].toxicSpikesAmount == 0) // Add only once to the queue
            PushHazardTypeToQueue(side, HAZARDS_TOXIC_SPIKES);
        gSideTimers[side].toxicSpikesAmount++;
        PrepareStringBattleWithWait(STRINGID_POISONSPIKESSCATTERED, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectSpikes(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);

    if (gSideTimers[side].spikesAmount == 3)
    {
        SetEffectFail(BattleScript_ButItFailedRet);
    }
    else if (!cv->onlyChecking)
    {
        if (gSideTimers[side].spikesAmount == 0) // Add only once to the queue
            PushHazardTypeToQueue(side, HAZARDS_SPIKES);
        gSideTimers[side].spikesAmount++;
        PrepareStringBattleWithWait(STRINGID_SPIKESSCATTERED, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectDisable(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattlerId aromaVeilBattler = B_BATTLER_0;

    u32 moveIndex = 0;
    for (moveIndex = 0; moveIndex <= MAX_MON_MOVES; moveIndex++)
    {
        if (gBattleMons[se->effectBattler].moves[moveIndex] == gLastMoves[se->effectBattler])
            break;
    }

    if (IsAbilityOnSideWithArr(se->effectBattler, ABILITY_AROMA_VEIL, cv->abilities, &aromaVeilBattler))
    {
        SetEffectFailAndCheckReturn;
        gBattlerAbility = aromaVeilBattler;
        BattleScriptPushAndSet(se->script, BattleScript_AromaVeilProtectsRet);
    }
    else if (gBattleMons[se->effectBattler].volatiles.disabledMove != MOVE_NONE
          || moveIndex == MAX_MON_MOVES
          || gBattleMons[se->effectBattler].pp[moveIndex] == 0)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[se->effectBattler].volatiles.disabledMove = gBattleMons[se->effectBattler].moves[moveIndex];

        if (B_DISABLE_TURNS >= GEN_5)
            gBattleMons[se->effectBattler].volatiles.disableTimer = B_DISABLE_TIMER;
        else if (B_DISABLE_TURNS >= GEN_4)
            gBattleMons[se->effectBattler].volatiles.disableTimer = (Random() & 3) + B_DISABLE_TIMER; // 4-7 turns
        else
            gBattleMons[se->effectBattler].volatiles.disableTimer = (Random() & 3) + 2; // 2-5 turns

        PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleMons[se->effectBattler].moves[moveIndex])
        PrepareStringBattleWithWait(STRINGID_PKMNMOVEWASDISABLED, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectEncore(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattlerId aromaVeilBattler = B_BATTLER_0;
    enum Move lastMove = gLastMoves[se->effectBattler];
    enum Ability abilities[MAX_BATTLERS_COUNT];
    s32 moveIndex;

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
        abilities[battler] = GetBattlerAbility(battler);

    if (IsMaxMove(lastMove) && GetActiveGimmick(se->effectBattler) != GIMMICK_DYNAMAX)
    {
        for (moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
        {
            if (gBattleMons[se->effectBattler].moves[moveIndex] == gBattleStruct->dynamax.baseMoves[se->effectBattler])
                break;
        }
    }
    else
    {
        for (moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
        {
            if (gBattleMons[se->effectBattler].moves[moveIndex] == lastMove)
                break;
        }
    }

    if (IsAbilityOnSideWithArr(se->effectBattler, ABILITY_AROMA_VEIL, abilities, &aromaVeilBattler))
    {
        SetEffectFailAndCheckReturn;
        gBattlerAbility = aromaVeilBattler;
        BattleScriptPushAndSet(se->script, BattleScript_AromaVeilProtectsRet);
    }
    else if (lastMove == MOVE_NONE
          || lastMove == MOVE_UNAVAILABLE
          || IsMoveEncoreBanned(lastMove)
          || moveIndex == MAX_MON_MOVES
          || gBattleMons[se->effectBattler].pp[moveIndex] == 0
          || gBattleMons[se->effectBattler].volatiles.encoredMove != MOVE_NONE
          || GetMoveEffect(gChosenMoveByBattler[se->effectBattler]) == EFFECT_SHELL_TRAP)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[se->effectBattler].volatiles.encoredMove = gBattleMons[se->effectBattler].moves[moveIndex];
        gBattleMons[se->effectBattler].volatiles.encoredMovePos = moveIndex;

        if (gBattleMons[se->effectBattler].volatiles.encoredMove != GetBattlerChosenMove(se->effectBattler))
            gBattleStruct->moveTarget[se->effectBattler] = SetRandomTarget(se->effectBattler);

        u32 turns;
        if (GetConfig(B_ENCORE_TURNS) >= GEN_5)
        {
            turns = B_ENCORE_TIMER;
            if (!HasBattlerActedThisTurn(se->effectBattler))
                turns--;
        }
        else if (GetConfig(B_ENCORE_TURNS) >= GEN_4)
        {
            turns = RandomUniform(RNG_ENCORE_TURNS, 3, 7);
        }
        else
        {
            turns = RandomUniform(RNG_ENCORE_TURNS, 2, 6);
        }

        gBattleMons[se->effectBattler].volatiles.encoreTimer = turns;
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectEncore);
    }
}

static void HandleSetEffectMist(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);

    if (gSideTimers[side].mistTimer)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gSideTimers[side].mistTimer = 5;
        gSideStatuses[side] |= SIDE_STATUS_MIST;
        PrepareStringBattleWithWait(STRINGID_PKMNSHROUDEDINMIST, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectPerishSong(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].volatiles.perishSong)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[se->effectBattler].volatiles.perishSong = TRUE;
        gBattleMons[se->effectBattler].volatiles.perishSongTimer = 3;
        PrepareStringBattleWithWait(STRINGID_FAINTINTHREE, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }

}

static void HandleSetEffectLockOn(struct BattleCalcValues *cv, struct SetEffect *se)
{
    bool32 isLockedOn = gBattleMons[cv->battlerAtk].volatiles.battlerWithSureHit != 0;

    if (isLockedOn)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[cv->battlerAtk].volatiles.lockOn = 2;
        gBattleMons[cv->battlerAtk].volatiles.battlerWithSureHit = se->effectBattler + 1;
        PrepareStringBattleWithWait(STRINGID_PKMNTOOKAIM, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }

}

static void HandleSetEffectMeanLook(struct BattleCalcValues *cv, struct SetEffect *se)
{

    bool32 alreadyTrapped = gBattleMons[se->effectBattler].volatiles.escapePrevention;
    bool32 canGhostsEscape = (GetConfig(B_GHOSTS_ESCAPE) < GEN_6
                           && IS_BATTLER_OF_TYPE(se->effectBattler, TYPE_GHOST));

    if (alreadyTrapped || canGhostsEscape)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[se->effectBattler].volatiles.escapePrevention = TRUE;
        gBattleMons[se->effectBattler].volatiles.battlerPreventingEscape = cv->battlerAtk;
        PrepareStringBattleWithWait( STRINGID_TARGETCANTESCAPENOW, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }

}

static void HandleSetEffectAttract(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattlerId aromaVeilBattler = B_BATTLER_0;

    if (IsAbilityOnSideWithArr(se->effectBattler, ABILITY_AROMA_VEIL, cv->abilities, &aromaVeilBattler))
    {
        SetEffectFail(BattleScript_AromaVeilProtectsRet);
        gBattlerAbility = aromaVeilBattler;
    }
    else if (gBattleMons[se->effectBattler].volatiles.infatuation || !AreBattlersOfOppositeGender(cv->battlerAtk, se->effectBattler))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (cv->abilities[se->effectBattler] == ABILITY_OBLIVIOUS)
    {
        SetEffectFailAndCheckReturn;
        gBattlerAbility = se->effectBattler;
        gLastUsedAbility = ABILITY_OBLIVIOUS;
        BattleScriptPushAndSet(se->script, BattleScript_NotAffectedAbilityPopUp);
        RecordAbilityBattle(se->effectBattler, ABILITY_OBLIVIOUS);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[se->effectBattler].volatiles.infatuation = INFATUATED_WITH(cv->battlerAtk);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectAttract);
    }
}

static void TrySubstitute(struct BattleCalcValues *cv, struct SetEffect *se, u32 hp, u32 factor, u8 const *script)
{
    if (gBattleMons[se->effectBattler].volatiles.substitute)
    {
        gBattleStruct->battlerState[se->effectBattler].alreadyStatusedMoveAttempt = TRUE;
        if (!cv->onlyChecking)
            PrepareStringBattleWithWait(STRINGID_PKMNHASSUBSTITUTE, se->effectBattler);
        SetEffectFail(BattleScript_MoveEffectSetStatus, cv->isStatusMove);
    }
    if (gBattleMons[se->effectBattler].hp <= hp)
    {
        if (!cv->onlyChecking)
            PrepareStringBattleWithWait(STRINGID_TOOWEAKFORSUBSTITUTE, se->effectBattler);
        SetEffectFail(BattleScript_MoveEffectSetStatus, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[se->effectBattler].volatiles.substitute = TRUE;
        gBattleMons[se->effectBattler].volatiles.wrapped = FALSE;

        if (factor == 2)
            gBattleMons[se->effectBattler].volatiles.substituteHP = hp / 2;
        else
            gBattleMons[se->effectBattler].volatiles.substituteHP = hp;

        gBattleStruct->passiveHpUpdate[se->effectBattler] = hp;
        BattleScriptPushAndSet(se->script, script);
    }
}

static void HandleSetEffectSubstitute(struct BattleCalcValues *cv, struct SetEffect *se)
{
    u32 factor = 4;
    u32 hp = GetNonDynamaxMaxHP(se->effectBattler) / factor; // one bit value will only work for Pokémon which max hp can go to 1020(which is more than possible in games)
    TrySubstitute(cv, se, max(hp, 1), factor, BattleScript_MoveEffectSubstitute);
}

static void HandleSetEffectShedTail(struct BattleCalcValues *cv, struct SetEffect *se)
{
    u32 factor = 2;
    u32 hp = (GetNonDynamaxMaxHP(se->effectBattler) + 1) / factor; // shed tail rounds up

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA
     || gBattleStruct->battlerState[se->effectBattler].commanderSpecies != SPECIES_NONE
     || gBattleMons[se->effectBattler].volatiles.semiInvulnerable == STATE_COMMANDER
     || !CanBattlerSwitch(se->effectBattler))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else
    {
        TrySubstitute(cv, se, max(hp, 1), factor, BattleScript_MoveEffectShedTail);
    }
}

static void HandleSetEffectPainSplit(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (DoesSubstituteBlockMoveEffectOnTarget(cv->battlerAtk, se->effectBattler, se->moveEffect))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        s32 hpDiff = (gBattleMons[cv->battlerAtk].hp + GetNonDynamaxHP(se->effectBattler)) / 2;
        gBattleStruct->passiveHpUpdate[se->effectBattler] = GetNonDynamaxHP(se->effectBattler) - hpDiff;
        gBattleStruct->passiveHpUpdate[cv->battlerAtk] = gBattleMons[cv->battlerAtk].hp - hpDiff;
    }
}

static void HandleSetEffectTorment(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattlerId aromaVeilBattler = B_BATTLER_0;

    if (IsAbilityOnSideWithArr(se->effectBattler, ABILITY_AROMA_VEIL, cv->abilities, &aromaVeilBattler))
    {
        SetEffectFail(BattleScript_AromaVeilProtectsRet);
        gBattlerAbility = aromaVeilBattler;
    }
    else if (gBattleMons[se->effectBattler].volatiles.torment || GetActiveGimmick(se->effectBattler) == GIMMICK_DYNAMAX)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[se->effectBattler].volatiles.torment = TRUE;
        PrepareStringBattleWithWait(STRINGID_PKMNSUBJECTEDTOTORMENT, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectIngrain(struct BattleCalcValues *cv, struct SetEffect *se)
{
    TryEffectVolatile(cv, se, VOLATILE_ROOT, TRUE, STRINGID_PKMNPLANTEDROOTS);
}

static enum Type GetConversionType(enum BattlerId battler, enum Move move)
{
    enum Type type = GetMoveType(move);

    if (type == TYPE_MYSTERY)
        type = IS_BATTLER_OF_TYPE(battler, TYPE_GHOST) ? TYPE_GHOST : TYPE_NORMAL;

    return type;
}

static bool32 IsValidConversionType(enum BattlerId battler, enum Type type)
{
    return !IS_BATTLER_OF_TYPE(battler, type);
}

static void HandleSetEffectConversion(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Type type = TYPE_NONE;
    u32 validMoves = 0;
    u32 firstMoveSlot = MAX_MON_MOVES;

    for (u32 i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[se->effectBattler].moves[i] != MOVE_NONE)
        {
            firstMoveSlot = i;
            break;
        }
    }

    while (validMoves < MAX_MON_MOVES && gBattleMons[se->effectBattler].moves[validMoves] != MOVE_NONE)
        validMoves++;

    if (GetActiveGimmick(se->effectBattler) == GIMMICK_TERA || firstMoveSlot == MAX_MON_MOVES)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
        return;
    }

    if (B_UPDATED_CONVERSION >= GEN_6)
    {
        type = GetMoveType(gBattleMons[se->effectBattler].moves[firstMoveSlot]);
        if (!IsValidConversionType(se->effectBattler, type))
        {
            SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
            return;
        }
    }
    else
    {
        bool32 hasValidType = FALSE;

        for (u32 i = 0; i < validMoves; i++)
        {
            type = GetConversionType(se->effectBattler, gBattleMons[se->effectBattler].moves[i]);
            if (IsValidConversionType(se->effectBattler, type))
            {
                hasValidType = TRUE;
                break;
            }
        }

        if (!hasValidType)
        {
            SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
            return;
        }

        if (!cv->onlyChecking)
        {
            do
            {
                u32 moveSlot;
                do
                {
                    moveSlot = MOD(Random(), MAX_MON_MOVES);
                } while (moveSlot >= validMoves);

                type = GetConversionType(se->effectBattler, gBattleMons[se->effectBattler].moves[moveSlot]);
            } while (!IsValidConversionType(se->effectBattler, type));
        }
    }

    if (!cv->onlyChecking)
    {
        SET_BATTLER_TYPE(se->effectBattler, type);
        PREPARE_TYPE_BUFFER(gBattleTextBuff1, type);
        PrepareStringBattleWithWait(STRINGID_PKMNCHANGEDTYPE, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static u32 GetResistTypes(enum Type typeToCheck)
{
    u32 resistTypes = 0;

    for (u32 i = 0; i < NUMBER_OF_MON_TYPES; i++) // Find all types that resist.
    {
        switch (GetTypeModifier(typeToCheck, i))
        {
        case UQ_4_12(0):
        case UQ_4_12(0.5):
            resistTypes |= 1u << i;
            break;
        }
    }

    return resistTypes;
}

static void HandleSetEffectConversion2(struct BattleCalcValues *cv, struct SetEffect *se)
{
    // Before Gen 5 Conversion 2 only worked on a move the attacker was actually hit by.
    // This changed later to the last move used by the selected target.
    enum Move moveToCheck;
    enum Type typeToCheck;

    if (GetConfig(B_UPDATED_CONVERSION_2) < GEN_5)
    {
        moveToCheck = gLastLandedMoves[cv->battlerAtk];
        if (GetMoveEffect(moveToCheck) == EFFECT_STRUGGLE)
            typeToCheck = TYPE_NORMAL;
        else
            typeToCheck = gLastHitByType[cv->battlerAtk];
    }
    else
    {
        moveToCheck = gLastResultingMoves[se->effectBattler];
        typeToCheck = gLastUsedMoveType[se->effectBattler];
    }

    u32 resistTypes = GetResistTypes(typeToCheck);

    if (moveToCheck == MOVE_NONE
     || moveToCheck == MOVE_UNAVAILABLE
     || GetActiveGimmick(cv->battlerAtk) == GIMMICK_TERA
     || typeToCheck == TYPE_NONE
     || typeToCheck == TYPE_STELLAR
     || typeToCheck == TYPE_MYSTERY
     || resistTypes == 0)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        enum Type type;

        while (resistTypes != 0)
        {
            type = Random() % NUMBER_OF_MON_TYPES;
            if (!(resistTypes & 1u << type))
                continue;

            if (IS_BATTLER_OF_TYPE(cv->battlerAtk, type))
            {
                resistTypes &= ~(1u << type); // Type resists, but the user is already of this type.
                continue;
            }

            SET_BATTLER_TYPE(cv->battlerAtk, type);
            PREPARE_TYPE_BUFFER(gBattleTextBuff1, type);
            PrepareStringBattleWithWait(STRINGID_PKMNCHANGEDTYPE, cv->battlerAtk);
            BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
            return;
        }
    }

}

static u32 GetMoveSlotToSketch(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    for (u32 moveSlot = 0; moveSlot < MAX_MON_MOVES; moveSlot++)
    {
        if (GetMoveEffect(gBattleMons[battlerAtk].moves[moveSlot]) == EFFECT_SKETCH)
            continue;
        if (gBattleMons[battlerAtk].moves[moveSlot] == gLastPrintedMoves[battlerDef])
            return moveSlot;
    }
    return MAX_MON_MOVES;
}

static void HandleSetEffectSketch(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[cv->battlerAtk].volatiles.transformed
     || gLastPrintedMoves[se->effectBattler] == MOVE_UNAVAILABLE
     || gLastPrintedMoves[se->effectBattler] == MOVE_NONE
     || GetMoveSlotToSketch(cv->battlerAtk, se->effectBattler) == MAX_MON_MOVES
     || IsMoveSketchBanned(gLastPrintedMoves[se->effectBattler]))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[cv->battlerAtk].moves[gCurrMovePos] = gLastPrintedMoves[se->effectBattler];
        gBattleMons[cv->battlerAtk].pp[gCurrMovePos] = GetMovePP(gLastPrintedMoves[se->effectBattler]);

        struct MovePPInfo movePPData;
        for (u32 i = 0; i < MAX_MON_MOVES; i++)
        {
            movePPData.moves[i] = gBattleMons[cv->battlerAtk].moves[i];
            movePPData.pp[i] = gBattleMons[cv->battlerAtk].pp[i];
        }
        movePPData.ppBonuses = gBattleMons[cv->battlerAtk].ppBonuses;

        BtlController_EmitSetMonData(cv->battlerAtk, B_COMM_TO_CONTROLLER, REQUEST_MOVES_PP_BATTLE, 0, sizeof(movePPData), &movePPData);
        MarkBattlerForControllerExec(cv->battlerAtk);

        PREPARE_MOVE_BUFFER(gBattleTextBuff1, gLastPrintedMoves[se->effectBattler])

        PrepareStringBattleWithWait(STRINGID_PKMNSKETCHEDMOVE, cv->battlerAtk);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void SetRestAbilityForMessage(enum BattlerId battler, enum Ability ability)
{
    gBattlerAbility = battler;
    gLastUsedAbility = ability;
    RecordAbilityBattle(battler, ability);
}

static void HandleSetEffectRest(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Ability ability = cv->abilities[se->effectBattler];
    enum HoldEffect holdEffect = GetBattlerHoldEffect(se->effectBattler);
    const u8 *failScript = GetRestFailureScript(se->effectBattler, ability);

    if (failScript != NULL)
    {
        if (!cv->onlyChecking && failScript == BattleScript_InsomniaProtects)
            SetRestAbilityForMessage(se->effectBattler, ability);
        SetEffectFail(failScript, cv->isStatusMove);
    }
    else if (UproarWakeUpCheck(se->effectBattler))
    {
        SetEffectFail(BattleScript_RestCantSleep, cv->isStatusMove);
    }
    else if ((GetConfig(B_LEAF_GUARD_PREVENTS_REST) >= GEN_5 && IsLeafGuardProtected(se->effectBattler, ability))
          || IsShieldsDownProtected(se->effectBattler, ability)
          || IsAbilityOnSide(se->effectBattler, ABILITY_SWEET_VEIL))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (IsElectricTerrainAffected(se->effectBattler, ability, holdEffect, gFieldTimers.terrain))
    {
        SetEffectFail(BattleScript_ElectricTerrainPrevents, cv->isStatusMove);
    }
    else if (IsMistyTerrainAffected(se->effectBattler, ability, holdEffect, gFieldTimers.terrain))
    {
        SetEffectFail(BattleScript_MistyTerrainPrevents, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        SetHealAmount(se->effectBattler, gBattleMons[se->effectBattler].maxHP);
        gBattleCommunication[MULTISTRING_CHOOSER] = gBattleMons[se->effectBattler].status1 & ((u8)(~STATUS1_SLEEP))
                                                   ? B_MSG_REST_STATUSED
                                                   : B_MSG_REST;
        gBattleMons[se->effectBattler].status1 = STATUS1_SLEEP_TURN(3);
        BtlController_EmitSetMonData(se->effectBattler, B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0,
                                     sizeof(gBattleMons[se->effectBattler].status1), &gBattleMons[se->effectBattler].status1);
        MarkBattlerForControllerExec(se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectRest);
    }
}

static bool32 CanTransformBattler(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    return !((GetConfig(B_TRANSFORM_SEMI_INV_FAIL) >= GEN_2 && IsSemiInvulnerable(battlerDef, EXCLUDE_COMMANDER))
          || (GetConfig(B_TRANSFORM_TARGET_FAIL) >= GEN_2 && gBattleMons[battlerDef].volatiles.transformed)
          || (GetConfig(B_TRANSFORM_USER_FAIL) >= GEN_5 && gBattleMons[battlerAtk].volatiles.transformed)
          || gBattleStruct->illusion[battlerDef].state == ILLUSION_ON);
}

bool32 TryTransformBattler(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (!CanTransformBattler(battlerAtk, battlerDef))
        return FALSE;

    u8 *battleMonAttacker;
    u8 *battleMonTarget;
    u8 timesGotHit;

    gChosenMove = MOVE_UNAVAILABLE;
    gBattleMons[battlerAtk].volatiles.transformed = TRUE;
    gBattleMons[battlerAtk].volatiles.disabledMove = MOVE_NONE;
    gBattleMons[battlerAtk].volatiles.disableTimer = 0;
    gBattleMons[battlerAtk].volatiles.transformedMonSpecies = gBattleMons[battlerAtk].species;
    gBattleMons[battlerAtk].volatiles.transformedMonPID = gBattleMons[battlerDef].personality;

    if (B_TRANSFORM_SHINY >= GEN_4)
        gBattleMons[battlerAtk].volatiles.isTransformedMonShiny = gBattleMons[battlerDef].isShiny;
    else
        gBattleMons[battlerAtk].volatiles.isTransformedMonShiny = gBattleMons[battlerAtk].isShiny;

    gBattleMons[battlerAtk].volatiles.mimickedMoves = 0;
    gBattleMons[battlerAtk].volatiles.usedMoves = 0;

    timesGotHit = GetBattlerPartyState(battlerDef)->timesGotHit;
    GetBattlerPartyState(battlerAtk)->timesGotHit = timesGotHit;
    PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[battlerDef].species);

    battleMonAttacker = (u8 *)&gBattleMons[battlerAtk];
    battleMonTarget = (u8 *)&gBattleMons[battlerDef];
    for (u32 i = 0; i < offsetof(struct BattlePokemon, pp); i++)
        battleMonAttacker[i] = battleMonTarget[i];

    gBattleMons[battlerAtk].volatiles.overwrittenAbility = GetBattlerAbility(battlerDef);
    for (u32 i = 0; i < MAX_MON_MOVES; i++)
        gBattleMons[battlerAtk].pp[i] = min(GetMovePP(gBattleMons[battlerAtk].moves[i]), 5);

    RecordAllMoves(battlerAtk);
    RecordAbilityBattle(battlerAtk, gBattleMons[battlerAtk].ability);
    SortBattlersByRawSpeed(gBattlersByRawSpeed);

    BtlController_EmitResetActionMoveSelection(battlerAtk, B_COMM_TO_CONTROLLER, RESET_MOVE_SELECTION);
    MarkBattlerForControllerExec(battlerAtk);
    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TRANSFORMED;

    return TRUE;
}

static void HandleSetEffectTransform(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!CanTransformBattler(cv->battlerAtk, se->effectBattler))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        TryTransformBattler(cv->battlerAtk, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectTransform);
    }
}

static void HandleSetEffectHealBell(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!cv->onlyChecking)
    {
        const u8 *effectScript = cv->move == MOVE_AROMATHERAPY
                               ? BattleScript_MoveEffectAromatherapy
                               : BattleScript_MoveEffectHealBell;

        BattleScriptPushAndSet(se->script, effectScript);
    }
}

static void HandleSetEffectPsychUp(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->onlyChecking)
        return;

    for (u32 i = 0; i < NUM_BATTLE_STATS; i++)
        gBattleMons[cv->battlerAtk].statStages[i] = gBattleMons[se->effectBattler].statStages[i];

    if (GetConfig(B_PSYCH_UP_CRIT_RATIO) >= GEN_6)
    {
        gBattleMons[cv->battlerAtk].volatiles.criticalHitBoost = gBattleMons[se->effectBattler].volatiles.criticalHitBoost;
        gBattleMons[cv->battlerAtk].volatiles.bonusCritStages = gBattleMons[se->effectBattler].volatiles.bonusCritStages;
    }

    gEffectBattler = se->effectBattler;
    gBattleScripting.battler = cv->battlerAtk;
    PrepareStringBattleWithWait(STRINGID_PKMNCOPIEDSTATCHANGES, cv->battlerAtk);
    BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
}

static void HandleSetEffectMagicCoat(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (IsLastMonToMove(se->effectBattler))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gProtectStructs[se->effectBattler].bounceMove = TRUE;
        PrepareStringBattleWithWait(STRINGID_PKMNSHROUDEDITSELF, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectYawn(struct BattleCalcValues *cv, struct SetEffect *se)
{
    bool32 canSleep = CanSetNonVolatileStatus(cv->battlerAtk,
                                              se->effectBattler,
                                              cv->abilities[cv->battlerAtk],
                                              cv->abilities[se->effectBattler],
                                              MOVE_EFFECT_SLEEP,
                                              CHECK_TRIGGER);

    if (!canSleep || gBattleMons[se->effectBattler].volatiles.yawn)
    {
        se->effectFailed = TRUE;
        if (!cv->onlyChecking && !se->silentFailure)
        {
            BattleScriptPush(se->script);
            if (!canSleep)
            {
                CanSetNonVolatileStatus(cv->battlerAtk,
                                        se->effectBattler,
                                        cv->abilities[cv->battlerAtk],
                                        cv->abilities[se->effectBattler],
                                        MOVE_EFFECT_SLEEP,
                                        RUN_SCRIPT);
            }
            else
            {
                gBattlescriptCurrInstr = BattleScript_ButItFailedRet;
            }
        }
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[se->effectBattler].volatiles.yawn = 2;
        PrepareStringBattleWithWait(STRINGID_PKMNWASMADEDROWSY, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectSnatch(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (IsLastMonToMove(se->effectBattler))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gProtectStructs[se->effectBattler].stealMove = TRUE;
        PrepareStringBattleWithWait(STRINGID_PKMNWAITSFORTARGET, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectCamouflage(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Type type = gFieldTimers.terrain != B_TERRAIN_NONE
                   ? gBattleTerrainInfo[gFieldTimers.terrain].type
                   : gBattleEnvironmentInfo[gBattleEnvironment].camouflageType;

    if (IS_BATTLER_OF_TYPE(se->effectBattler, type) || GetActiveGimmick(se->effectBattler) == GIMMICK_TERA)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        SET_BATTLER_TYPE(se->effectBattler, type);
        PREPARE_TYPE_BUFFER(gBattleTextBuff1, type);
        PrepareStringBattleWithWait(STRINGID_PKMNCHANGEDTYPE, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectImprison(struct BattleCalcValues *cv, struct SetEffect *se)
{
    bool32 sharesMoveWithFoe = GetConfig(B_IMPRISON) >= GEN_5;

    if (!sharesMoveWithFoe)
    {
        for (enum BattlerId battler = 0; battler < gBattlersCount && !sharesMoveWithFoe; battler++)
        {
            if (IsBattlerAlly(cv->battlerAtk, battler))
                continue;

            for (u32 attackerMove = 0; attackerMove < MAX_MON_MOVES && !sharesMoveWithFoe; attackerMove++)
            {
                if (gBattleMons[cv->battlerAtk].moves[attackerMove] == MOVE_NONE)
                    continue;

                for (u32 foeMove = 0; foeMove < MAX_MON_MOVES; foeMove++)
                {
                    if (gBattleMons[cv->battlerAtk].moves[attackerMove] == gBattleMons[battler].moves[foeMove])
                    {
                        sharesMoveWithFoe = TRUE;
                        break;
                    }
                }
            }
        }
    }

    if (gBattleMons[se->effectBattler].volatiles.imprison || !sharesMoveWithFoe)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[se->effectBattler].volatiles.imprison = TRUE;
        PrepareStringBattleWithWait(STRINGID_PKMNSEALEDOPPONENTMOVE, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectRefresh(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum StringID cureString = STRINGID_EMPTYSTRING3;

    u32 status = gBattleMons[se->effectBattler].status1;
    u32 shouldHeal = status & STATUS1_CAN_MOVE;

    if (!shouldHeal)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        if (status & STATUS1_SLEEP)
            TryDeactivateSleepClause(se->effectBattler, gBattlerPartyIndexes[se->effectBattler]);

        if (status & STATUS1_PARALYSIS)
            cureString = STRINGID_SCRCUREDPARALYSIS;
        else if (status & STATUS1_POISON || status & STATUS1_TOXIC_POISON)
            cureString = STRINGID_SCRCUREDPOISON;
        else if (status & STATUS1_BURN)
            cureString = STRINGID_SCRCUREDBURN;
        else if (status & STATUS1_SLEEP)
            cureString = STRINGID_SCRCUREDSLEEP;
        else if (status & STATUS1_FREEZE)
            cureString = STRINGID_PKMNWASDEFROSTED;
        else if (status & STATUS1_FROSTBITE)
            cureString = STRINGID_PKMNFROSTBITEHEALED;

        gBattleMons[se->effectBattler].status1 = 0;
        BtlController_EmitSetMonData(se->effectBattler, B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[cv->battlerAtk].status1), &gBattleMons[cv->battlerAtk].status1);
        MarkBattlerForControllerExec(se->effectBattler);
        gBattleScripting.savedStringId = cureString;
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectRefresh);

    }

}

static void HandleSetEffectTypeHalver(struct BattleCalcValues *cv, struct SetEffect *se)
{
    struct TypeBasedHalverInfo halver = GetTypeBasedHalverInfo(se->additionalEffect->argument.type);

    bool32 shouldSet = GetConfig(B_SPORT_TURNS) >= GEN_6
                         ? !(gFieldStatuses & halver.statusField)
                         : !GetBattlerVolatile(se->effectBattler, halver.voaltileStatus);

    if (gBattleStruct->isSkyBattle || !shouldSet)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        if (GetConfig(B_SPORT_TURNS) >= GEN_6)
        {
            gFieldStatuses |= halver.statusField;
            gFieldTimers.mudSportTimer = 5;
            PrepareStringBattleWithWait(halver.effectString, se->effectBattler);
            gBattlescriptCurrInstr = se->script;
        }
        else
        {
            TryEffectVolatile(cv, se, halver.voaltileStatus, TRUE, halver.effectString);
            gBattlescriptCurrInstr = se->script;
        }
    }
}

static void HandleSetEffectOdorSleuth(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectBlock(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectTailwind(struct BattleCalcValues *cv, struct SetEffect *se)
{
    u32 side = GetBattlerSide(se->effectBattler);

    if (gSideStatuses[side] & SIDE_STATUS_TAILWIND)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    if (!cv->onlyChecking)
    {
        gSideStatuses[side] |= SIDE_STATUS_TAILWIND;
        gSideTimers[side].tailwindTimer = (GetConfig(B_TAILWIND_TURNS) >= GEN_5 ? 4 : 3);
        gBattlescriptCurrInstr = se->script;
        PrepareStringBattleWithWait(STRINGID_TAILWINDBLEW, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_TryTailwindAbilitiesLoop);
    }
}

static void HandleSetEffectPsychoShift(struct BattleCalcValues *cv, struct SetEffect *se)
{
    u32 attackerStatus = gBattleMons[cv->battlerAtk].status1;
    u32 effectStatus = gBattleMons[se->effectBattler].status1;

    enum Ability attackerAbility = cv->abilities[cv->battlerAtk];
    enum Ability effectAbility = cv->abilities[se->effectBattler];
    enum MoveEffect synchronizeEffect = GetSynchronizeEffect(attackerStatus);

    bool32 canSetNonVolatile = CanSetNonVolatileStatus(cv->battlerAtk, se->effectBattler,
                                                       attackerAbility, effectAbility,
                                                       synchronizeEffect, CHECK_TRIGGER);

    bool32 shouldFail = effectStatus & STATUS1_ANY
                     || !(attackerStatus & STATUS1_ANY)
                     || IsSafeguardProtected(cv->battlerAtk, se->effectBattler, attackerAbility)
                     || !canSetNonVolatile;

    bool32 triggerSleepClause = IsSleepClauseActiveForSide(GetBattlerSide(se->effectBattler))
                             && (attackerStatus & STATUS1_SLEEP);

    // Actually activate the effect

    if (shouldFail)
    {
        if (triggerSleepClause)
            SetEffectFail(BattleScript_SleepClausePrevents, cv->isStatusMove);
        else
            SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[se->effectBattler].status1 = attackerStatus & STATUS1_ANY;

        BtlController_EmitSetMonData(
            se->effectBattler,
            B_COMM_TO_CONTROLLER,
            REQUEST_STATUS_BATTLE,
            0,
            sizeof(effectStatus),
            &gBattleMons[se->effectBattler].status1);

        MarkBattlerForControllerExec(se->effectBattler);

        gBattleScripting.savedStringId = GetStatus1String(attackerStatus);

        TryActivateSleepClause(se->effectBattler, gBattlerPartyIndexes[se->effectBattler]);
        TrySynchronizeActivation(cv->battlerAtk, se->effectBattler, synchronizeEffect);

        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectPsychoShift);
    }
}

static void HandleSetEffectPowerTrick(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->onlyChecking) return;

    u32 temp;
    gBattleMons[se->effectBattler].volatiles.powerTrick = !gBattleMons[se->effectBattler].volatiles.powerTrick;
    SWAP(gBattleMons[se->effectBattler].attack, gBattleMons[se->effectBattler].defense, temp);
    PrepareStringBattleWithWait(STRINGID_PKMNSWITCHEDATKANDDEF, se->effectBattler);
    BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
}

static void HandleSetEffectGastroAcid(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].volatiles.gastroAcid
     || gAbilitiesInfo[gBattleMons[se->effectBattler].ability].cantBeSuppressed)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (GetBattlerHoldEffectIgnoreAbility(se->effectBattler) == HOLD_EFFECT_ABILITY_SHIELD)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
        if (cv->onlyChecking)
            RecordItemEffectBattle(se->effectBattler, HOLD_EFFECT_ABILITY_SHIELD);
    }
    else if (!cv->onlyChecking)
    {
        if (gBattleMons[se->effectBattler].volatiles.neutralizingGas)
            gSpecialStatuses[se->effectBattler].neutralizingGasRemoved = TRUE;

        RemoveRuinAbilityFlags(se->effectBattler);
        gBattleMons[se->effectBattler].volatiles.gastroAcid = TRUE;
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectGastroAcid);
    }

}

static void HandleSetEffectLuckyChant(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);
    bool32 luckyChantActive = gSideStatuses[side] & SIDE_STATUS_LUCKY_CHANT;

    if(luckyChantActive)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gSideStatuses[side] |= SIDE_STATUS_LUCKY_CHANT;
        PrepareStringBattleWithWait(STRINGID_SHIELDEDFROMCRITICALHITS, se->effectBattler);
        gSideTimers[side].luckyChantTimer = 5;
        gBattlescriptCurrInstr = se->script;
    }
}

static void HandleSetEffectStatSwap(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->onlyChecking) return;

    struct StatField sf = se->additionalEffect->argument.statField;

    const struct
    {
        bool8 stat;
        u8 enumerator;
    } stats[] = {
        { sf.atk,     STAT_ATK     },
        { sf.def,     STAT_DEF     },
        { sf.spatk,   STAT_SPATK   },
        { sf.spdef,   STAT_SPDEF   },
        { sf.speed,   STAT_SPEED   },
        { sf.acc,     STAT_ACC     },
        { sf.evasion, STAT_EVASION },
    };

    for (u8 i = 0; i < ARRAY_COUNT(stats); i++)
    {
        if (stats[i].stat)
            SwapStatStages(cv->battlerAtk, se->effectBattler, stats[i].enumerator);
    }

    PrepareStringBattleWithWait(STRINGID_PKMNSWITCHEDSTATCHANGES, se->effectBattler);
    gBattlescriptCurrInstr = se->script;
}

static void HandleSetEffectOverwriteAbility(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Ability *abilityEb = &cv->abilities[se->effectBattler];
    enum Ability overwriteAbility = se->additionalEffect->argument.overwriteAbility;

    if (gAbilitiesInfo[*abilityEb].cantBeOverwritten || *abilityEb == overwriteAbility)
    {
        SetEffectFailAndCheckReturn;
        RecordAbilityBattle(se->effectBattler, *abilityEb);
        BattleScriptPushAndSet(se->script, BattleScript_ButItFailedRet);
    }
    else if (CanAbilityShieldActivateForBattler(se->effectBattler))
    {
        SetEffectFail(BattleScript_AbilityShieldProtects);
    }
    else if (!cv->onlyChecking)
    {
        if (gBattleMons[se->effectBattler].volatiles.neutralizingGas)
            gSpecialStatuses[se->effectBattler].neutralizingGasRemoved = TRUE;

        RemoveAbilityFlags(se->effectBattler);
        gBattleScripting.abilityPopupOverwrite = *abilityEb;
        gBattleMons[se->effectBattler].ability = gBattleMons[se->effectBattler].volatiles.overwrittenAbility = overwriteAbility;
        gBattlerAbility = se->effectBattler;

        RecordAbilityBattle(se->effectBattler, gBattleMons[se->effectBattler].ability);
        PrepareStringBattleWithWait(STRINGID_PKMNACQUIREDABILITY, se->effectBattler);
        BattleScriptPush(se->script);
        BattleScriptPush(BattleScript_MoveEffectOverwriteAbility);
        gBattlescriptCurrInstr = BattleScript_AbilityPopUpOverwriteThenNormal;
    }
}

static void HandleSetEffectSkillSwap(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Ability *abilityAtk = &gBattleMons[cv->battlerAtk].ability;
    enum Ability *abilityDef = &gBattleMons[se->effectBattler].ability;

    if (GetActiveGimmick(se->effectBattler) == GIMMICK_DYNAMAX
     || gAbilitiesInfo[*abilityAtk].cantBeSwapped
     || gAbilitiesInfo[*abilityDef].cantBeSwapped)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (CanAbilityShieldActivateForBattler(cv->battlerAtk) || CanAbilityShieldActivateForBattler(se->effectBattler))
    {
        SetEffectFail(BattleScript_AbilityShieldProtects);
    }
    else if (!cv->onlyChecking)
    {
        bool32 isAlly = IsBattlerAlly(cv->battlerAtk, se->effectBattler);

        if (!isAlly)
            gBattleScripting.abilityPopupOverwrite = gBattleMons[cv->battlerAtk].ability;

        gLastUsedAbility = *abilityDef;
        RemoveAbilityFlags(gBattlerTarget);
        RemoveAbilityFlags(cv->battlerAtk);
        *abilityDef = gBattleMons[se->effectBattler].volatiles.overwrittenAbility = *abilityAtk;
        *abilityAtk = gBattleMons[cv->battlerAtk].volatiles.overwrittenAbility = gLastUsedAbility ;
        RecordAbilityBattle(se->effectBattler, *abilityDef);
        RecordAbilityBattle(cv->battlerAtk, *abilityAtk);

        if (isAlly)
            BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSkillSwapAfterAbilityPopUp);
        else
            BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSkillSwap);
    }
}

static void HandleSetEffectRolePlay(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Ability sourceAbility = gBattleMons[cv->battlerDef].ability;
    enum Ability destAbility = gBattleMons[se->effectBattler].ability;

    if (destAbility == sourceAbility
     || sourceAbility == ABILITY_NONE
     || gAbilitiesInfo[destAbility].cantBeSuppressed
     || gAbilitiesInfo[sourceAbility].cantBeCopied)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (CanAbilityShieldActivateForBattler(se->effectBattler))
    {
        SetEffectFail(BattleScript_AbilityShieldProtects);
    }
    else if (!cv->onlyChecking)
    {
        gBattlerAbility = se->effectBattler;
        RemoveAbilityFlags(se->effectBattler);
        gBattleScripting.abilityPopupOverwrite = destAbility;
        gBattleMons[se->effectBattler].ability = gBattleMons[se->effectBattler].volatiles.overwrittenAbility = sourceAbility;
        gLastUsedAbility = sourceAbility;
        RecordAbilityBattle(se->effectBattler, gLastUsedAbility);
        RecordAbilityBattle(cv->battlerDef, gLastUsedAbility);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectRolePlay);
    }
}

#define BATTLE_TYPE_NOT_REGULAR (BATTLE_TYPE_LINK | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_FRONTIER | BATTLE_TYPE_SECRET_BASE | BATTLE_TYPE_RECORDED_LINK)
#define BATTLE_TYPE_TRAINER_CHECK_CONFIG (B_TRAINERS_KNOCK_OFF_ITEMS == TRUE ? BATTLE_TYPE_TRAINER : 0)
static void HandleSetEffectTrick(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Item oldItemAtk = gBattleMons[cv->battlerAtk].item;
    enum Item oldItemDef = gBattleMons[se->effectBattler].item;

    bool32 opponentCantSwapItems = (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                                || (!IsOnPlayerSide(cv->battlerAtk) && !(gBattleTypeFlags & (BATTLE_TYPE_NOT_REGULAR | BATTLE_TYPE_TRAINER_CHECK_CONFIG)));

    bool32 isKnockedOff = (GetBattlerPartyState(cv->battlerAtk)->isKnockedOff || GetBattlerPartyState(se->effectBattler)->isKnockedOff);
    bool32 cantSwapIfKnockedOff = !(gBattleTypeFlags & BATTLE_TYPE_NOT_REGULAR) && isKnockedOff;

    if (opponentCantSwapItems || cantSwapIfKnockedOff)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if ((oldItemAtk == ITEM_NONE && oldItemDef == ITEM_NONE)
          || !CanBattlerGetOrLoseItem(cv->battlerAtk, se->effectBattler, oldItemAtk)
          || !CanBattlerGetOrLoseItem(cv->battlerAtk, se->effectBattler, oldItemDef)
          || !CanBattlerGetOrLoseItem(se->effectBattler, cv->battlerAtk, oldItemDef)
          || !CanBattlerGetOrLoseItem(se->effectBattler, cv->battlerAtk, oldItemAtk))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (cv->abilities[se->effectBattler] == ABILITY_STICKY_HOLD)
    {
        SetEffectFailAndCheckReturn;
        gBattlerAbility = se->effectBattler;
        gLastUsedAbility = gBattleMons[se->effectBattler].ability;
        RecordAbilityBattle(se->effectBattler, gLastUsedAbility);
        BattleScriptPushAndSet(se->script, BattleScript_StickyHoldActivatesRet);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[cv->battlerAtk].item = oldItemDef;
        gBattleMons[se->effectBattler].item = oldItemAtk;

        RecordItemEffectBattle(cv->battlerAtk, cv->holdEffects[oldItemDef]);
        RecordItemEffectBattle(se->effectBattler, cv->holdEffects[oldItemAtk]);

        BtlController_EmitSetMonData(cv->battlerAtk, B_COMM_TO_CONTROLLER, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[cv->battlerAtk].item), &gBattleMons[cv->battlerAtk].item);
        MarkBattlerForControllerExec(se->effectBattler);

        BtlController_EmitSetMonData(se->effectBattler, B_COMM_TO_CONTROLLER, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[se->effectBattler].item), &gBattleMons[se->effectBattler].item);
        MarkBattlerForControllerExec(se->effectBattler);

        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectTrick);

        if (cv->abilities[se->effectBattler] != ABILITY_GORILLA_TACTICS)
            gBattleStruct->choicedMove[se->effectBattler] = MOVE_NONE;

        if (cv->abilities[cv->battlerAtk] != ABILITY_GORILLA_TACTICS
         && (!IsHoldEffectChoice(GetItemHoldEffect(oldItemDef))
         || (GetConfig(B_MODERN_TRICK_CHOICE_LOCK) >= GEN_5)))
        {
            gBattleStruct->choicedMove[cv->battlerAtk] = MOVE_NONE;
        }

        PREPARE_ITEM_BUFFER(gBattleTextBuff1, oldItemDef)
        PREPARE_ITEM_BUFFER(gBattleTextBuff2, oldItemAtk)

        if (!(IsBattlerAlly(cv->battlerAtk, se->effectBattler) && IsPartnerMonFromSameTrainer(cv->battlerAtk)))
        {
            // if targeting your own side and you aren't in a multi battle, don't save items as stolen
            if (IsOnPlayerSide(cv->battlerAtk))
                TrySaveExchangedItem(cv->battlerAtk, oldItemAtk);
            if (IsOnPlayerSide(se->effectBattler))
                TrySaveExchangedItem(se->effectBattler, oldItemDef);
        }

        if (oldItemAtk != ITEM_NONE && oldItemDef != ITEM_NONE)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ITEM_SWAP_BOTH;  // attacker's item -> <- target's item
        }
        else if (oldItemAtk == ITEM_NONE && oldItemDef != ITEM_NONE)
        {
            CheckSetUnburden(se->effectBattler);
            gBattleMons[cv->battlerAtk].volatiles.unburdenActive = FALSE;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ITEM_SWAP_TAKEN; // nothing -> <- target's item
        }
        else
        {
            CheckSetUnburden(cv->battlerAtk);
            gBattleMons[se->effectBattler].volatiles.unburdenActive = FALSE;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ITEM_SWAP_GIVEN; // attacker's item -> <- nothing
        }
    }
}

static void HandleSetEffectSetRoom(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum StringID roomString;
    enum StringID roomEndString;
    u32 roomStatus;
    u8 *timer;

    if(cv->onlyChecking) return;

    enum BattleRoom roomType = se->additionalEffect->argument.roomType;

    switch (roomType)
    {
    case B_ROOM_MAGIC:
        roomString = STRINGID_HELDITEMSLOSEEFFECTS;
        roomEndString = STRINGID_MAGICROOMENDS;
        roomStatus = STATUS_FIELD_MAGIC_ROOM;
        timer = &gFieldTimers.magicRoomTimer;
        break;
    case B_ROOM_TRICK:
        roomString = STRINGID_PKMNTWISTEDDIMENSIONS;
        roomEndString = STRINGID_TRICKROOMENDS;
        roomStatus = STATUS_FIELD_TRICK_ROOM;
        timer = &gFieldTimers.trickRoomTimer;
        break;
    case B_ROOM_WONDER:
        roomString = STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON;
        roomEndString = STRINGID_WONDERROOMENDS;
        roomStatus = STATUS_FIELD_WONDER_ROOM;
        timer = &gFieldTimers.wonderRoomTimer;
        break;
    default:
        errorf("Invalid argument for roomType: %d", roomType);
        roomString = STRINGID_EMPTYSTRING3;
        roomEndString = STRINGID_EMPTYSTRING3;
        timer = NULL;
        roomStatus = 0;
        break;
    }

    if (gFieldStatuses & roomStatus)
    {
        gFieldStatuses &= ~roomStatus;
        *timer = 0;
        PrepareStringBattleWithWait(roomEndString, se->effectBattler);
    }
    else
    {
        gFieldStatuses |= roomStatus;
        *timer = 5;
        PrepareStringBattleWithWait(roomString, se->effectBattler);
    }

    BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);

    if (roomType == B_ROOM_TRICK)
        BattleScriptCall(BattleScript_TryRoomServiceLoop);
}

static void HandleSetEffectLunarDance(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

u16 *GetBattlerStatPtr(struct BattlePokemon *battler, enum Stat stat)
{
    switch (stat)
    {
    case STAT_ATK:   return &battler->attack;
    case STAT_DEF:   return &battler->defense;
    case STAT_SPATK: return &battler->spAttack;
    case STAT_SPDEF: return &battler->spDefense;
    default:         return NULL;
    }
}

void AverageBattlerStats(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Stat stat)
{
    u16 *attackerStat = GetBattlerStatPtr(&gBattleMons[battlerAtk], stat);
    u16 *defenderStat = GetBattlerStatPtr(&gBattleMons[battlerDef], stat);
    u16 avg = (*attackerStat + *defenderStat) / 2;
    *attackerStat = *defenderStat = avg;
}

static void HandleSetEffectAverageStats(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->onlyChecking) return;

    struct StatField sf = se->additionalEffect->argument.statField;

    const struct
    {
        bool8 stat;
        u8 enumerator;
    } stats[] = {
        { sf.atk,     STAT_ATK     },
        { sf.def,     STAT_DEF     },
        { sf.spatk,   STAT_SPATK   },
        { sf.spdef,   STAT_SPDEF   },
        { sf.speed,   STAT_SPEED   },
        { sf.acc,     STAT_ACC     },
        { sf.evasion, STAT_EVASION },
    };

    for (u32 i = 0; i < ARRAY_COUNT(stats); i++)
    {
        if (stats[i].stat)
            AverageBattlerStats(cv->battlerAtk, se->effectBattler, stats[i].enumerator);
    }

    enum StringID effectString = STRINGID_EMPTYSTRING3;

    if (sf.def && sf.spdef)
        effectString = STRINGID_SHAREDITSGUARD;
    else if (sf.atk && sf.spatk)
        effectString = STRINGID_SHAREDITSPOWER;

    PrepareStringBattleWithWait(effectString, se->effectBattler);
    BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
}

static void HandleSetEffectTelekinesis(struct BattleCalcValues *cv, struct SetEffect *se)
{
    struct BattlePokemon *effectBattleMon = &gBattleMons[se->effectBattler];

    bool32 telekinesisFailed = effectBattleMon->volatiles.telekinesis
               || effectBattleMon->volatiles.root
               || effectBattleMon->volatiles.smackDown
               || gFieldStatuses & STATUS_FIELD_GRAVITY
               || IsTelekinesisBannedSpecies(gBattleMons[se->effectBattler].species);

    if (telekinesisFailed)
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);

    if (cv->onlyChecking) return;

    effectBattleMon->volatiles.telekinesis = TRUE;
    effectBattleMon->volatiles.telekinesisTimer = B_TELEKINESIS_TIMER;
    PrepareStringBattleWithWait(STRINGID_HURLEDINTOTHEAIR, se->effectBattler);
    BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
}

static void HandleSetEffectOverwriteType(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Type types[3];
    GetBattlerTypes(se->effectBattler, FALSE, types);
    enum Type typeToSet = se->additionalEffect->argument.type;

    if (cv->abilities[se->effectBattler] == ABILITY_MULTITYPE
     || cv->abilities[se->effectBattler] == ABILITY_RKS_SYSTEM
     || (types[0] == typeToSet && types[1] == typeToSet)
     || GetActiveGimmick(se->effectBattler) == GIMMICK_TERA)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        SET_BATTLER_TYPE(se->effectBattler, typeToSet);
        PREPARE_TYPE_BUFFER(gBattleTextBuff1, typeToSet);
        PrepareStringBattleWithWait(STRINGID_TARGETCHANGEDTYPE, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectEntrainment(struct BattleCalcValues *cv, struct SetEffect *se)
{
    const enum Ability *srcAbility = &gBattleMons[cv->battlerAtk].ability;
    enum Ability *destAbility = &gBattleMons[se->effectBattler].ability;

    if (gAbilitiesInfo[*srcAbility].cantBeCopied)
    {
        se->effectFailed = TRUE;
        if (!cv->onlyChecking)
        {
            RecordAbilityBattle(cv->battlerAtk, *srcAbility);
            if (cv->isStatusMove)
                BattleScriptPushAndSet(se->script, BattleScript_ButItFailedRet);
        }
    }
    else if (gAbilitiesInfo[*destAbility].cantBeOverwritten)
    {
        se->effectFailed = TRUE;
        if (!cv->onlyChecking)
        {
            RecordAbilityBattle(cv->battlerAtk, *destAbility);
            if (cv->isStatusMove)
                BattleScriptPushAndSet(se->script, BattleScript_ButItFailedRet);
        }
    }
    else if (CanAbilityShieldActivateForBattler(se->effectBattler))
    {
        SetEffectFail(BattleScript_AbilityShieldProtects);
    }
    else if (*destAbility == *srcAbility || GetActiveGimmick(se->effectBattler) == GIMMICK_DYNAMAX)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        RemoveAbilityFlags(se->effectBattler);
        *destAbility = gBattleMons[se->effectBattler].volatiles.overwrittenAbility = *srcAbility;
        PrepareStringBattleWithWait(STRINGID_PKMNACQUIREDABILITY, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectOverwriteAbility);
    }
}

static void HandleSetEffectQuash(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (HasBattlerActedThisTurn(se->effectBattler))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gProtectStructs[se->effectBattler].quash = TRUE;

        struct BattleCalcValues calcValues = {0};
        for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
        {
            calcValues.abilities[battler] = GetBattlerAbility(battler);
            calcValues.holdEffects[battler] = GetBattlerHoldEffect(battler);
        }

        u32 turnOrder = GetBattlerTurnOrderNum(se->effectBattler);
        for (u32 nextTurnOrder = turnOrder + 1; nextTurnOrder < gBattlersCount; nextTurnOrder++)
        {
            calcValues.battlerAtk = gBattlerByTurnOrder[turnOrder];
            calcValues.battlerDef = gBattlerByTurnOrder[nextTurnOrder];

            if (B_QUASH_TURN_ORDER < GEN_8 || GetWhichBattlerFaster(&calcValues, FALSE) == -1)
                SwapTurnOrder(turnOrder, nextTurnOrder);
            else
                break;
            turnOrder++;
        }

        PrepareStringBattleWithWait(STRINGID_QUASHSUCCESS, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectAfterYou(struct BattleCalcValues *cv, struct SetEffect *se)
{
    u32 attackerTurnOrder = GetBattlerTurnOrderNum(cv->battlerAtk);
    u32 targetTurnOrder = GetBattlerTurnOrderNum(se->effectBattler);
    bool32 canChangeOrder = cv->battlerAtk != se->effectBattler
                       && attackerTurnOrder <= targetTurnOrder
                       && (attackerTurnOrder + 1 != targetTurnOrder || GetConfig(B_AFTER_YOU_TURN_ORDER) >= GEN_8);

    if (!canChangeOrder)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        ChangeOrderTargetAfterAttacker(se->effectBattler);
        gSpecialStatuses[se->effectBattler].afterYou = TRUE;
        PrepareStringBattleWithWait(STRINGID_KINDOFFER, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectReflectType(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Species targetBaseSpecies = GET_BASE_SPECIES_ID(gBattleMons[se->effectBattler].species);
    enum Type targetTypes[3];
    GetBattlerTypes(se->effectBattler, FALSE, targetTypes);

    bool32 speciesTypeImmutable = targetBaseSpecies == SPECIES_ARCEUS
                               || targetBaseSpecies == SPECIES_SILVALLY;

    bool32 isTeraActive = GetActiveGimmick(cv->battlerAtk) == GIMMICK_TERA;

    if (speciesTypeImmutable || isTeraActive || IS_BATTLER_TYPELESS(se->effectBattler))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
        return;
    }

    if (cv->onlyChecking)
        return;

    if (targetTypes[0] == TYPE_MYSTERY && targetTypes[1] == TYPE_MYSTERY && targetTypes[2] != TYPE_MYSTERY)
    {
        SetBattlerTypes(cv->battlerAtk, TYPE_NORMAL, TYPE_NORMAL, targetTypes[2]);
    }
    else if (targetTypes[0] == TYPE_MYSTERY && targetTypes[1] != TYPE_MYSTERY)
    {
        SetBattlerTypes(cv->battlerAtk, targetTypes[1], targetTypes[1], targetTypes[2]);
    }
    else if (targetTypes[0] != TYPE_MYSTERY && targetTypes[1] == TYPE_MYSTERY)
    {
        SetBattlerTypes(cv->battlerAtk, targetTypes[0], targetTypes[0], targetTypes[2]);
    }
    else
    {
        SetBattlerTypes(cv->battlerAtk, targetTypes[0], targetTypes[1], targetTypes[2]);
    }

    PrepareStringBattleWithWait(STRINGID_REFLECTTARGETSTYPE, cv->battlerAtk);
    BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
}

static void HandleSetEffectBestow(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[cv->battlerAtk].item == ITEM_NONE
     || gBattleMons[se->effectBattler].item != ITEM_NONE
     || !CanBattlerGetOrLoseItem(cv->battlerAtk, se->effectBattler, gBattleMons[cv->battlerAtk].item)
     || !CanBattlerGetOrLoseItem(se->effectBattler, cv->battlerAtk, gBattleMons[cv->battlerAtk].item)
     || GetBattlerPartyState(se->effectBattler)->isKnockedOff)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        BestowItem(cv->battlerAtk, se->effectBattler);
        PrepareStringBattleWithWait(STRINGID_BESTOWITEMGIVING, cv->battlerAtk);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectStickyWeb(struct BattleCalcValues *cv, struct SetEffect *se)
{
    u8 effectSide = GetBattlerSide(se->effectBattler);

    if (IsHazardOnSide(effectSide, HAZARDS_STICKY_WEB))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        PushHazardTypeToQueue(effectSide, HAZARDS_STICKY_WEB);
        gSideTimers[effectSide].stickyWebBattlerId = cv->battlerAtk; // For Mirror Armor
        gSideTimers[effectSide].stickyWebBattlerSide = GetBattlerSide(cv->battlerAtk); // For Court Change/Defiant - set this to the user's side

        PrepareStringBattle(STRINGID_STICKYWEBUSED, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static bool32 DoesRoarFail(enum BattlerId battlerAtk, enum BattlerId effectBattler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        return TRUE;

    if (WILD_DOUBLE_BATTLE
     && IsOnPlayerSide(battlerAtk)
     && !IsOnPlayerSide(effectBattler)
     && IS_WHOLE_SIDE_ALIVE(effectBattler))
        return TRUE;

    if (WILD_DOUBLE_BATTLE
     && !IsOnPlayerSide(battlerAtk)
     && !IsOnPlayerSide(effectBattler))
        return TRUE;

    // TODO: This looks incorrect. it probably should be in doubles only for wild battle mon
    if (FlagGet(WE_FLAG_NO_RUNNING))
        return TRUE;

    if (gBattleStruct->battlerState[effectBattler].commanderSpecies != SPECIES_NONE
     || gBattleMons[effectBattler].volatiles.semiInvulnerable == STATE_COMMANDER)
        return TRUE;

    if (GetActiveGimmick(effectBattler) == GIMMICK_DYNAMAX)
        return TRUE;

    return FALSE;
}

static void HandleSetEffectRoar(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (DoesRoarFail(cv->battlerAtk, se->effectBattler) || cv->abilities[se->effectBattler] == ABILITY_GUARD_DOG) // TODO: There is no ability popup?
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (cv->abilities[se->effectBattler] == ABILITY_SUCTION_CUPS)
    {
        gBattlerAbility = se->effectBattler;
        SetEffectFail(BattleScript_AbilityPreventsPhasingOutRet, cv->isStatusMove);
    }
    else if (gBattleMons[se->effectBattler].volatiles.root)
    {
        SetEffectFail(BattleScript_PrintMonIsRooted, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        BattleScriptPushAndSet(se->script, BattleScript_EffectRoar);
    }
}

static bool32 IsAnyStatChanged(enum BattlerId battler, enum Ability ability)
{
    for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS ; stat++)
    {
        if (CompareStat(battler, stat, DEFAULT_STAT_STAGE, CMP_NOT_EQUAL, ability))
            return TRUE;
    }
    return FALSE;
}

static void HandleSetEffectTopsyTurvy(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (IsAnyStatChanged(se->effectBattler, cv->abilities[se->effectBattler]))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        for (enum Stat stat = 0; stat < NUM_BATTLE_STATS; stat++)
        {
            if (gBattleMons[se->effectBattler].statStages[stat] < DEFAULT_STAT_STAGE) // Negative becomes positive.
            {
                gBattleMons[se->effectBattler].statStages[stat] = DEFAULT_STAT_STAGE + (DEFAULT_STAT_STAGE - gBattleMons[se->effectBattler].statStages[stat]);
            }
            else if (gBattleMons[se->effectBattler].statStages[stat] > DEFAULT_STAT_STAGE) // Positive becomes negative.
            {
                gBattleMons[se->effectBattler].statStages[stat] = DEFAULT_STAT_STAGE - (gBattleMons[se->effectBattler].statStages[stat] - DEFAULT_STAT_STAGE);
            }
        }

        PrepareStringBattle(STRINGID_TOPSYTURVYSWITCHEDSTATS, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectElectrify(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (HasBattlerActedThisTurn(gBattlerTarget))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }

    if (cv->onlyChecking) return;

    gBattleMons[se->effectBattler].volatiles.electrified = TRUE;

    PrepareStringBattleWithWait(STRINGID_TARGETELECTRIFIED, se->effectBattler);
    BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
}

static void HandleSetEffectFairyLock(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gFieldStatuses & STATUS_FIELD_FAIRY_LOCK)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gFieldStatuses |= STATUS_FIELD_FAIRY_LOCK;
        gFieldTimers.fairyLockTimer = 2;
        PrepareStringBattleWithWait(STRINGID_NOONEWILLBEABLETORUNAWAY, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static bool32 IsTeatimeAffected(enum BattlerId battler)
{
    if (GetItemPocket(gBattleMons[battler].item) != POCKET_BERRIES)
        return FALSE;
    if (IsSemiInvulnerable(battler, CHECK_ALL))
        return FALSE;
    return TRUE;
}

static void HandleSetEffectTeatime(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!IsTeatimeAffected(se->effectBattler))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectTeatime);
    }
}

static void HandleSetEffectOctolock(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].volatiles.octolock)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[se->effectBattler].volatiles.octolock = TRUE;
        gBattleMons[se->effectBattler].volatiles.octolockedBy = cv->battlerAtk;
        gBattleMons[se->effectBattler].volatiles.escapePrevention = TRUE;
        gBattleMons[se->effectBattler].volatiles.battlerPreventingEscape = cv->battlerAtk;
        PrepareStringBattleWithWait(STRINGID_CANTESCAPEBECAUSEOFCURRENTMOVE, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

#define COURTCHANGE_SWAP(status, structField, temp)                     \
{                                                                       \
    temp = gSideStatuses[B_SIDE_PLAYER];                                \
    if (gSideStatuses[B_SIDE_OPPONENT] & status)                        \
        gSideStatuses[B_SIDE_PLAYER] |= status;                         \
    else                                                                \
        gSideStatuses[B_SIDE_PLAYER] &= ~(status);                      \
    if (temp & status)                                                  \
        gSideStatuses[B_SIDE_OPPONENT] |= status;                       \
    else                                                                \
        gSideStatuses[B_SIDE_OPPONENT] &= ~(status);                    \
    SWAP(sideTimerPlayer->structField, sideTimerOpp->structField, temp);\
}                                                                       \

#define UPDATE_COURTCHANGED_BATTLER(structField)\
{                                               \
    temp = sideTimerPlayer->structField;        \
    sideTimerPlayer->structField = ((sideTimerOpp->structField) ^ BIT_SIDE);        \
    sideTimerOpp->structField = (temp ^ BIT_SIDE);        \
}                                               \

static void HandleSetEffectCourtChange(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->onlyChecking) return;

    struct SideTimer *sideTimerPlayer = &gSideTimers[B_SIDE_PLAYER];
    struct SideTimer *sideTimerOpp = &gSideTimers[B_SIDE_OPPONENT];
    u32 temp;

    // Swap timers and statuses
    COURTCHANGE_SWAP(SIDE_STATUS_REFLECT, reflectTimer, temp)
    COURTCHANGE_SWAP(SIDE_STATUS_LIGHTSCREEN, lightscreenTimer, temp)
    COURTCHANGE_SWAP(SIDE_STATUS_MIST, mistTimer, temp);
    COURTCHANGE_SWAP(SIDE_STATUS_SAFEGUARD, safeguardTimer, temp);
    COURTCHANGE_SWAP(SIDE_STATUS_AURORA_VEIL, auroraVeilTimer, temp);
    COURTCHANGE_SWAP(SIDE_STATUS_TAILWIND, tailwindTimer, temp);
    // Lucky Chant doesn't exist in gen 8, but seems like it should be affected by Court Change
    COURTCHANGE_SWAP(SIDE_STATUS_LUCKY_CHANT, luckyChantTimer, temp);
    COURTCHANGE_SWAP(SIDE_STATUS_DAMAGE_NON_TYPES, damageNonTypesTimer, temp);
    // Track Pledge effect side
    COURTCHANGE_SWAP(SIDE_STATUS_RAINBOW, rainbowTimer, temp);
    COURTCHANGE_SWAP(SIDE_STATUS_SEA_OF_FIRE, seaOfFireTimer, temp);
    COURTCHANGE_SWAP(SIDE_STATUS_SWAMP, swampTimer, temp);

    // Hazards
    u32 tempQueue[HAZARDS_MAX_COUNT] = {HAZARDS_NONE};
    for (u32 i = 0; i < HAZARDS_MAX_COUNT; i++)
        tempQueue[i] = gBattleStruct->hazardsQueue[B_SIDE_PLAYER][i];
    for (u32 i = 0; i < HAZARDS_MAX_COUNT; i++)
        gBattleStruct->hazardsQueue[B_SIDE_PLAYER][i] = gBattleStruct->hazardsQueue[B_SIDE_OPPONENT][i];
    for (u32 i = 0; i < HAZARDS_MAX_COUNT; i++)
        gBattleStruct->hazardsQueue[B_SIDE_OPPONENT][i] = tempQueue[i];
    SWAP(gBattleStruct->numHazards[B_SIDE_PLAYER], gBattleStruct->numHazards[B_SIDE_OPPONENT], temp);
    SWAP(sideTimerPlayer->spikesAmount, sideTimerOpp->spikesAmount, temp);
    SWAP(sideTimerPlayer->toxicSpikesAmount, sideTimerOpp->toxicSpikesAmount, temp);

    // Change battler IDs of swapped effects. Needed for the correct string when they expire
    UPDATE_COURTCHANGED_BATTLER(stickyWebBattlerId);

    // Track which side originally set the Sticky Web
    SWAP(sideTimerPlayer->stickyWebBattlerSide, sideTimerOpp->stickyWebBattlerSide, temp);

    // Swap what type set the Gigantamax damage over time effect
    SWAP(sideTimerPlayer->damageNonTypesType, sideTimerOpp->damageNonTypesType, temp);

    PrepareStringBattleWithWait(STRINGID_COURTCHANGE, se->effectBattler);
    BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
}

static void HandleSetEffectCorrosiveGas(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Item item = gBattleMons[se->effectBattler].item;

    if (item == ITEM_NONE || !CanBattlerGetOrLoseItem(se->effectBattler, cv->battlerAtk, item))
    {
        SetEffectFailAndCheckReturn;
        PrepareStringBattleWithWait(STRINGID_NOEFFECTONTARGET, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
    else if (cv->abilities[se->effectBattler] == ABILITY_STICKY_HOLD)
    {
        if (cv->onlyChecking) return;

        gLastUsedAbility = ABILITY_STICKY_HOLD;
        gBattlerAbility = se->effectBattler;
        RecordAbilityBattle(se->effectBattler, gLastUsedAbility);
        BattleScriptPushAndSet(se->script, BattleScript_StickyHoldActivatesRet);
    }
    else if (!cv->onlyChecking)
    {
        gLastUsedItem = item;
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectCorrosiveGas);
    }
}

static void HandleSetEffectLifeDew(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].hp == gBattleMons[se->effectBattler].maxHP)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        s32 restoreHpModifier = se->additionalEffect->argument.restoreHpModifier;
        s32 healAmount = GetMaxHpWithRounding(se->effectBattler) / restoreHpModifier;
        SetHealAmount(se->effectBattler, healAmount);
        BattleScriptPushAndSet(se->script, BattleScript_RestoreHpEffectBattler);
    }
}

static void HandleSetEffectCureNonVolatile(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!(gBattleMons[se->effectBattler].status1 & STATUS1_ANY))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        CureNonVolatile(cv, se, STATUS1_ANY, TRUE);
    }
}

static void HandleSetEffectFollowMe(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (B_UPDATED_MOVE_DATA >= GEN_8 && !IsDoubleBattle())
    {
        se->effectFailed = TRUE; // failure message handled in move resolution
    }
    else if (!cv->onlyChecking)
    {
        enum BattleSide side = GetBattlerSide(cv->battlerAtk);
        gSideTimers[side].followmeTimer = 1;
        gSideTimers[side].followmeTarget = cv->battlerAtk;
        gSideTimers[side].followmePowder = IsPowderMove(cv->move);
        PrepareStringBattleWithWait(STRINGID_PKMNCENTERATTENTION, cv->battlerAtk);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectTaunt(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattlerId aromaVeilBattler = B_BATTLER_0;

    if (GetConfig(B_OBLIVIOUS_TAUNT) >= GEN_6 && cv->abilities[se->effectBattler] == ABILITY_OBLIVIOUS)
    {
        SetEffectFailAndCheckReturn;
        gBattlerAbility = se->effectBattler;
        gLastUsedAbility = ABILITY_OBLIVIOUS;
        BattleScriptPushAndSet(se->script, BattleScript_NotAffectedAbilityPopUp);
        RecordAbilityBattle(se->effectBattler, ABILITY_OBLIVIOUS);
    }
    else if (IsAbilityOnSideWithArr(se->effectBattler, ABILITY_AROMA_VEIL, cv->abilities, &aromaVeilBattler))
    {
        se->effectFailed = TRUE;
        if (!cv->onlyChecking)
        {
            gBattlerAbility = aromaVeilBattler;
            BattleScriptPushAndSet(se->script, BattleScript_AromaVeilProtectsRet);
        }
    }
    else if (gBattleMons[se->effectBattler].volatiles.tauntTimer)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        u32 turns = 2;
        if (GetConfig(B_TAUNT_TURNS) >= GEN_5)
        {
            turns = B_TAUNT_TIMER - 1; // 4 turns
            if (!HasBattlerActedThisTurn(se->effectBattler))
                turns--; // If the target hasn't yet moved this turn, Taunt lasts for only three turns (source: Bulbapedia)
        }
        else if (GetConfig(B_TAUNT_TURNS) >= GEN_4)
        {
            turns = RandomUniform(RNG_TAUNT_TURNS, 3, B_TAUNT_TIMER);
        }

        gBattleMons[se->effectBattler].volatiles.tauntTimer = turns;
        PrepareStringBattleWithWait(STRINGID_PKMNFELLFORTAUNT, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectHelpingHand(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!IsDoubleBattle()
     || !IsBattlerAlive(se->effectBattler)
     || HasBattlerActedThisTurn(se->effectBattler))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gProtectStructs[se->effectBattler].helpingHand++;
        PrepareStringBattleWithWait(STRINGID_PKMNREADYTOHELP, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectThirdType(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Type type = se->additionalEffect->argument.type;

    if (IS_BATTLER_OF_TYPE(se->effectBattler, type) || GetActiveGimmick(se->effectBattler) == GIMMICK_TERA)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[se->effectBattler].types[2] = type;
        PREPARE_TYPE_BUFFER(gBattleTextBuff1, type);
        PrepareStringBattleWithWait(STRINGID_THIRDTYPEADDED, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static bool32 CanMimicMoveSlot(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    for (u32 i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[battlerAtk].moves[i] == gLastMoves[battlerDef])
            return FALSE;
    }
    return TRUE;
}

static void HandleSetEffectMimic(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gLastMoves[se->effectBattler] == MOVE_UNAVAILABLE
     || gLastMoves[se->effectBattler] == MOVE_NONE
     || gBattleMons[cv->battlerAtk].volatiles.transformed
     || IsMoveMimicBanned(gLastMoves[se->effectBattler])
     || !CanMimicMoveSlot(cv->battlerAtk, se->effectBattler))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gChosenMove = 0xFFFF;
        gBattleMons[cv->battlerAtk].moves[gCurrMovePos] = gLastMoves[se->effectBattler];
        u32 pp = GetMovePP(gLastMoves[se->effectBattler]);
        gBattleMons[cv->battlerAtk].pp[gCurrMovePos] = min(pp, 5);

        PREPARE_MOVE_BUFFER(gBattleTextBuff1, gLastMoves[se->effectBattler])
        gBattleMons[cv->battlerAtk].volatiles.mimickedMoves |= 1u << gCurrMovePos;
        PrepareStringBattleWithWait(STRINGID_PKMNLEARNEDMOVE2, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

// TODO: Uses same effect as power trick but they seem to be different?
static void HandleSetEffectPowerShift(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectLunarBlessing(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static bool32 IsInstructBannedChargingMove(u32 battler)
{
    if (gChosenActionByBattler[battler] != B_ACTION_USE_MOVE || HasBattlerActedThisTurn(battler))
        return FALSE;

    enum BattleMoveEffects moveEffect = GetMoveEffect(gChosenMoveByBattler[battler]);
    return moveEffect == EFFECT_FOCUS_PUNCH
        || moveEffect == EFFECT_BEAK_BLAST
        || moveEffect == EFFECT_SHELL_TRAP;
}

static bool32 IsMoveViableForInstruct(enum BattlerId battler, u32 *moveIndex)
{
    for (u32 i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[battler].moves[i] == gCalledMove)
        {
            *moveIndex = i;
            break;
        }
    }

    if (*moveIndex == MAX_MON_MOVES)
        return FALSE;

    if (gBattleMons[battler].pp[*moveIndex] == 0)
        return FALSE;

    return TRUE;
}

static void HandleSetEffectInstruct(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattlerId battlerDef = se->effectBattler;
    enum Move move = gLastPrintedMoves[battlerDef];
    u32 moveIndex = MAX_MON_MOVES;
    gCalledMove = move;

    if (move == MOVE_NONE
     || move == MOVE_UNAVAILABLE
     || MoveHasAdditionalEffectSelf(move, MOVE_EFFECT_RECHARGE)
     || IsMoveInstructBanned(move)
     || IsInstructBannedChargingMove(battlerDef)
     || gBattleMons[battlerDef].volatiles.bideTurns != 0
     || gBattleMons[battlerDef].volatiles.semiInvulnerable == STATE_SKY_DROP_TARGET
     || gBattleMoveEffects[GetMoveEffect(move)].twoTurnEffect
     || (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
     || IsZMove(move)
     || IsMaxMove(move)
     || !IsMoveViableForInstruct(battlerDef, &moveIndex))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gCurrMovePos = moveIndex;
        gEffectBattler = gBattleStruct->battlerState[battlerDef].lastMoveTarget;
        PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, battlerDef, gBattlerPartyIndexes[battlerDef]);
        BattleScriptPushAndSet(se->script, BattleScript_Instruct);
    }
}

static void HandleSetEffectRevivalBlessing(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (GetFirstFaintedPartyIndex(cv->battlerAtk) == PARTY_SIZE)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        BattleScriptPushAndSet(se->script, BattleScript_RevivalBlessing);
    }
}

static void HandleSetEffectFocusEnergy(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].volatiles.criticalHitBoost)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        if (GetConfig(B_FOCUS_ENERGY_CRIT_RATIO) >= GEN_3 || GetConfig(B_CRIT_CHANCE) == GEN_1)
            gBattleMons[se->effectBattler].volatiles.criticalHitBoost = CRIT_BOOST_TWO_STAGES;
        else
            gBattleMons[se->effectBattler].volatiles.criticalHitBoost = CRIT_BOOST_ONE_STAGE;

        PrepareStringBattleWithWait(STRINGID_PKMNGETTINGPUMPED, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void HandleSetEffectDragonCheer(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!IsDoubleBattle()
     || !IsBattlerAlive(se->effectBattler)
     || gBattleMons[se->effectBattler].volatiles.criticalHitBoost)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[se->effectBattler].volatiles.criticalHitBoost = IS_BATTLER_OF_TYPE(se->effectBattler, TYPE_DRAGON)
                                                                  ? CRIT_BOOST_TWO_STAGES
                                                                  : CRIT_BOOST_ONE_STAGE;
        PrepareStringBattleWithWait(STRINGID_PKMNGETTINGPUMPED, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
    }
}

static void (*const sSetEffectHandlers[])(struct BattleCalcValues *cv, struct SetEffect *se) =
{
    [MOVE_EFFECT_NONE] = HandleSetEffectNone,
    [MOVE_EFFECT_SLEEP] = HandleSetEffectNonVolatile,
    [MOVE_EFFECT_POISON] = HandleSetEffectNonVolatile,
    [MOVE_EFFECT_BURN] = HandleSetEffectNonVolatile,
    [MOVE_EFFECT_FREEZE] = HandleSetEffectNonVolatile,
    [MOVE_EFFECT_PARALYSIS] = HandleSetEffectNonVolatile,
    [MOVE_EFFECT_TOXIC] = HandleSetEffectNonVolatile,
    [MOVE_EFFECT_FROSTBITE] = HandleSetEffectNonVolatile,
    [MOVE_EFFECT_CONFUSION] = HandleSetEffectConfusion,
    [MOVE_EFFECT_FLINCH] = HandleSetEffectFlinch,
    [MOVE_EFFECT_ABSORB] = HandleSetEffectAbsorb,
    [MOVE_EFFECT_RANDOM_FROM_LIST] = HandleSetEffectRandomFromList,
    [MOVE_EFFECT_UPROAR] = HandleSetEffectUproar,
    [MOVE_EFFECT_PAYDAY] = HandleSetEffectPayday,
    [MOVE_EFFECT_WRAP] = HandleSetEffectWrap,
    [MOVE_EFFECT_STAT_PLUS] = HandleSetEffectStatChange,
    [MOVE_EFFECT_STAT_MINUS] = HandleSetEffectStatChange,
    [MOVE_EFFECT_REMOVE_ARG_TYPE] = HandleSetEffectRemoveArgType,
    [MOVE_EFFECT_RECHARGE] = HandleSetEffectRecharge,
    [MOVE_EFFECT_RAGE] = HandleSetEffectRage,
    [MOVE_EFFECT_PREVENT_ESCAPE] = HandleSetEffectPreventEscape,
    [MOVE_EFFECT_NIGHTMARE] = HandleSetEffectNightmare,
    [MOVE_EFFECT_GLAIVE_RUSH] = HandleSetEffectGlaiveRush,
    [MOVE_EFFECT_REMOVE_STATUS] = HandleSetEffectRemoveStatus,
    [MOVE_EFFECT_THRASH] = HandleSetEffectThrash,
    [MOVE_EFFECT_CLEAR_SMOG] = HandleSetEffectClearSmog,
    [MOVE_EFFECT_FLAME_BURST] = HandleSetEffectFlameBurst,
    [MOVE_EFFECT_FEINT] = HandleSetEffectFeint,
    [MOVE_EFFECT_HAPPY_HOUR] = HandleSetEffectHappyHour,
    [MOVE_EFFECT_DO_NOTHING] = HandleSetEffectDoNothing,
    [MOVE_EFFECT_HOLD_HANDS] = HandleSetEffectHoldHands,
    [MOVE_EFFECT_CELEBRATE] = HandleSetEffectCelebrate,
    [MOVE_EFFECT_CORE_ENFORCER] = HandleSetEffectCoreEnforcer,
    [MOVE_EFFECT_THROAT_CHOP] = HandleSetEffectThroatChop,
    [MOVE_EFFECT_INCINERATE] = HandleSetEffectIncinerate,
    [MOVE_EFFECT_BUG_BITE] = HandleSetEffectBugBite,
    [MOVE_EFFECT_RECOIL_HP_25] = HandleSetEffectRecoilHp25,
    [MOVE_EFFECT_TRAP_BOTH] = HandleSetEffectTrapBoth,
    [MOVE_EFFECT_ROUND] = HandleSetEffectRound,
    [MOVE_EFFECT_SYRUP_BOMB] = HandleSetEffectSyrupBomb,
    [MOVE_EFFECT_SECRET_POWER] = HandleSetEffectSecretPower,
    [MOVE_EFFECT_HEAL_BLOCK] = HandleSetEffectHealBlock,
    [MOVE_EFFECT_TERA_BLAST] = HandleSetEffectTeraBlast,
    [MOVE_EFFECT_ORDER_UP] = HandleSetEffectOrderUp,
    [MOVE_EFFECT_ION_DELUGE] = HandleSetEffectIonDeluge,
    [MOVE_EFFECT_HAZE] = HandleSetEffectHaze,
    [MOVE_EFFECT_LEECH_SEED] = HandleSetEffectLeechSeed,
    [MOVE_EFFECT_PROTECT] = HandleSetEffectProtect,
    [MOVE_EFFECT_REFLECT] = HandleSetEffectReflect,
    [MOVE_EFFECT_LIGHT_SCREEN] = HandleSetEffectLightScreen,
    [MOVE_EFFECT_SALT_CURE] = HandleSetEffectSaltCure,
    [MOVE_EFFECT_EERIE_SPELL] = HandleSetEffectEerieSpell,
    [MOVE_EFFECT_FLING] = HandleSetEffectFling,
    [MOVE_EFFECT_RAINBOW] = HandleSetEffectRainbow,
    [MOVE_EFFECT_SEA_OF_FIRE] = HandleSetEffectSeaOfFire,
    [MOVE_EFFECT_SWAMP] = HandleSetEffectSwamp,
    [MOVE_EFFECT_SPEED_SWAP] = HandleSetEffectSpeedSwap,
    [MOVE_EFFECT_SAFEGUARD] = HandleSetEffectSafeguard,
    [MOVE_EFFECT_LASER_FOCUS] = HandleSetEffectLaserFocus,
    [MOVE_EFFECT_POWDER] = HandleSetEffectPowder,
    [MOVE_EFFECT_AQUA_RING] = HandleSetEffectAquaRing,
    [MOVE_EFFECT_EMBARGO] = HandleSetEffectEmbargo,
    [MOVE_EFFECT_MIRACLE_EYE] = HandleSetEffectMiracleEye,
    [MOVE_EFFECT_DESTINY_BOND] = HandleSetEffectDestinyBond,
    [MOVE_EFFECT_FORESIGHT] = HandleSetEffectForesight,
    [MOVE_EFFECT_GRUDGE] = HandleSetEffectGrudge,
    [MOVE_EFFECT_MAGNET_RISE] = HandleSetEffectMagnetRise,
    [MOVE_EFFECT_TOXIC_SPIKES] = HandleSetEffectToxicSpikes,
    [MOVE_EFFECT_SPIKES] = HandleSetEffectSpikes,
    [MOVE_EFFECT_DISABLE] = HandleSetEffectDisable,
    [MOVE_EFFECT_ENCORE] = HandleSetEffectEncore,
    [MOVE_EFFECT_MIST] = HandleSetEffectMist,
    [MOVE_EFFECT_PERISH_SONG] = HandleSetEffectPerishSong,
    [MOVE_EFFECT_LOCK_ON] = HandleSetEffectLockOn,
    [MOVE_EFFECT_MEAN_LOOK] = HandleSetEffectMeanLook,
    [MOVE_EFFECT_ATTRACT] = HandleSetEffectAttract,
    [MOVE_EFFECT_PAIN_SPLIT] = HandleSetEffectPainSplit,
    [MOVE_EFFECT_TORMENT] = HandleSetEffectTorment,
    [MOVE_EFFECT_INGRAIN] = HandleSetEffectIngrain,
    [MOVE_EFFECT_YAWN] = HandleSetEffectYawn,
    [MOVE_EFFECT_IMPRISON] = HandleSetEffectImprison,
    [MOVE_EFFECT_REFRESH] = HandleSetEffectRefresh,
    [MOVE_EFFECT_TYPE_HALVER] = HandleSetEffectTypeHalver,
    [MOVE_EFFECT_ODOR_SLEUTH] = HandleSetEffectOdorSleuth,
    [MOVE_EFFECT_BLOCK] = HandleSetEffectBlock,
    [MOVE_EFFECT_TAILWIND] = HandleSetEffectTailwind,
    [MOVE_EFFECT_PSYCHO_SHIFT] = HandleSetEffectPsychoShift,
    [MOVE_EFFECT_POWER_TRICK] = HandleSetEffectPowerTrick,
    [MOVE_EFFECT_GASTRO_ACID] = HandleSetEffectGastroAcid,
    [MOVE_EFFECT_LUCKY_CHANT] = HandleSetEffectLuckyChant,
    [MOVE_EFFECT_STAT_SWAP] = HandleSetEffectStatSwap,
    [MOVE_EFFECT_OVERWRITE_ABILITY] = HandleSetEffectOverwriteAbility,
    [MOVE_EFFECT_SKILL_SWAP] = HandleSetEffectSkillSwap,
    [MOVE_EFFECT_ROLE_PLAY] = HandleSetEffectRolePlay,
    [MOVE_EFFECT_TRICK] = HandleSetEffectTrick,
    [MOVE_EFFECT_SET_ROOM] = HandleSetEffectSetRoom,
    [MOVE_EFFECT_AVERAGE_STATS] = HandleSetEffectAverageStats,
    [MOVE_EFFECT_TELEKINESIS] = HandleSetEffectTelekinesis,
    [MOVE_EFFECT_OVERWRITE_TYPE] = HandleSetEffectOverwriteType,
    [MOVE_EFFECT_ENTRAINMENT] = HandleSetEffectEntrainment,
    [MOVE_EFFECT_AFTER_YOU] = HandleSetEffectAfterYou,
    [MOVE_EFFECT_REFLECT_TYPE] = HandleSetEffectReflectType,
    [MOVE_EFFECT_STICKY_WEB] = HandleSetEffectStickyWeb,
    [MOVE_EFFECT_ELECTRIFY] = HandleSetEffectElectrify,
    [MOVE_EFFECT_FAIRY_LOCK] = HandleSetEffectFairyLock,
    [MOVE_EFFECT_OCTOLOCK] = HandleSetEffectOctolock,
    [MOVE_EFFECT_COURT_CHANGE] = HandleSetEffectCourtChange,
    [MOVE_EFFECT_CORROSIVE_GAS] = HandleSetEffectCorrosiveGas,
    [MOVE_EFFECT_FOCUS_ENERGY] = HandleSetEffectFocusEnergy,
    [MOVE_EFFECT_DRAGON_CHEER] = HandleSetEffectDragonCheer,
    [MOVE_EFFECT_SHED_TAIL] = HandleSetEffectShedTail,
    [MOVE_EFFECT_SUBSTITUTE] = HandleSetEffectSubstitute,
    [MOVE_EFFECT_QUASH] = HandleSetEffectQuash,
    [MOVE_EFFECT_TEATIME] = HandleSetEffectTeatime,
    [MOVE_EFFECT_LIFE_DEW] = HandleSetEffectLifeDew,
    [MOVE_EFFECT_CURE_NON_VOLATILE] = HandleSetEffectCureNonVolatile,
    [MOVE_EFFECT_FOLLOW_ME] = HandleSetEffectFollowMe,
    [MOVE_EFFECT_TAUNT] = HandleSetEffectTaunt,
    [MOVE_EFFECT_HELPING_HAND] = HandleSetEffectHelpingHand,
    [MOVE_EFFECT_THIRD_TYPE] = HandleSetEffectThirdType,
    [MOVE_EFFECT_MIMIC] = HandleSetEffectMimic,
    [MOVE_EFFECT_SKETCH] = HandleSetEffectSketch,
    [MOVE_EFFECT_REST] = HandleSetEffectRest,
    [MOVE_EFFECT_TRANSFORM] = HandleSetEffectTransform,
    [MOVE_EFFECT_HEAL_BELL] = HandleSetEffectHealBell,
    [MOVE_EFFECT_MAGIC_COAT] = HandleSetEffectMagicCoat,
    [MOVE_EFFECT_SNATCH] = HandleSetEffectSnatch,
    [MOVE_EFFECT_ROAR] = HandleSetEffectRoar,
    [MOVE_EFFECT_TOPSY_TURVY] = HandleSetEffectTopsyTurvy,
    [MOVE_EFFECT_BESTOW] = HandleSetEffectBestow,
    [MOVE_EFFECT_LUNAR_DANCE] = HandleSetEffectLunarDance,
    [MOVE_EFFECT_POWER_SHIFT] = HandleSetEffectPowerShift,
    [MOVE_EFFECT_LUNAR_BLESSING] = HandleSetEffectLunarBlessing,
    [MOVE_EFFECT_INSTRUCT] = HandleSetEffectInstruct,
    [MOVE_EFFECT_REVIVAL_BLESSING] = HandleSetEffectRevivalBlessing,
    [MOVE_EFFECT_PRESENT] = HandleSetEffectPresent,
    [MOVE_EFFECT_SWALLOW] = HandleSetEffectSwallow,
    [MOVE_EFFECT_PURIFY] = HandleSetEffectPurify,
    [MOVE_EFFECT_PSYCH_UP] = HandleSetEffectPsychUp,
    [MOVE_EFFECT_CAMOUFLAGE] = HandleSetEffectCamouflage,
    [MOVE_EFFECT_CONVERSION] = HandleSetEffectConversion,
    [MOVE_EFFECT_CONVERSION2] = HandleSetEffectConversion2,
    [MOVE_EFFECT_WISH] = HandleSetEffectWish,
    [MOVE_EFFECT_ROOST] = HandleSetEffectRoost,
    [MOVE_EFFECT_RESTORE_HP] = HandleSetEffectRestoreHp,
    [MOVE_EFFECT_RESTORE_HP_ON_WEATHER] = HandleSetEffectRestoreHpOnWeather,
    [MOVE_EFFECT_HEAL_PULSE] = HandleSetEffectHealPulse,
    [MOVE_EFFECT_POLLEN_PUFF] = HandleSetEffectPollenPuff,
    [MOVE_EFFECT_FLORAL_HEALING] = HandleSetEffectHealPulse,
    [MOVE_EFFECT_SUN] = HandleSetEffectWeather,
    [MOVE_EFFECT_RAIN] = HandleSetEffectWeather,
    [MOVE_EFFECT_SANDSTORM] = HandleSetEffectWeather,
    [MOVE_EFFECT_HAIL] = HandleSetEffectWeather,
    [MOVE_EFFECT_SNOW] = HandleSetEffectWeather,
    [MOVE_EFFECT_MISTY_TERRAIN] = HandleSetEffectTerrain,
    [MOVE_EFFECT_GRASSY_TERRAIN] = HandleSetEffectTerrain,
    [MOVE_EFFECT_ELECTRIC_TERRAIN] = HandleSetEffectTerrain,
    [MOVE_EFFECT_PSYCHIC_TERRAIN] = HandleSetEffectTerrain,
    [MOVE_EFFECT_VINE_LASH] = HandleSetEffectGmaxNonTypeDamage,
    [MOVE_EFFECT_WILDFIRE] = HandleSetEffectGmaxNonTypeDamage,
    [MOVE_EFFECT_CANNONADE] = HandleSetEffectGmaxNonTypeDamage,
    [MOVE_EFFECT_EFFECT_SPORE_SIDE] = HandleSetEffectEffectSporeSide,
    [MOVE_EFFECT_PARALYZE_SIDE] = HandleSetEffectParalyzeSide,
    [MOVE_EFFECT_CONFUSE_PAY_DAY_SIDE] = HandleSetEffectConfusePayDaySide,
    [MOVE_EFFECT_CRIT_PLUS_SIDE] = HandleSetEffectCritPlusSide,
    [MOVE_EFFECT_PREVENT_ESCAPE_SIDE] = HandleSetEffectPreventEscapeSide,
    [MOVE_EFFECT_AURORA_VEIL] = HandleSetEffectAuroraVeil,
    [MOVE_EFFECT_INFATUATE_SIDE] = HandleSetEffectInfatuateSide,
    [MOVE_EFFECT_RECYCLE_BERRIES] = HandleSetEffectRecycleBerriesSide,
    [MOVE_EFFECT_RECYCLE] = HandleSetEffectRecycle,
    [MOVE_EFFECT_POISON_SIDE] = HandleSetEffectPoisonSide,
    [MOVE_EFFECT_DEFOG] = HandleSetEffectDefog,
    [MOVE_EFFECT_POISON_PARALYZE_SIDE] = HandleSetEffectPoisonParalyzeSide,
    [MOVE_EFFECT_HEAL_TEAM] = HandleSetEffectHealTeam,
    [MOVE_EFFECT_SPITE] = HandleSetEffectSpite,
    [MOVE_EFFECT_GRAVITY] = HandleSetEffectGravity,
    [MOVE_EFFECT_VOLCALITH] = HandleSetEffectGmaxNonTypeDamage,
    [MOVE_EFFECT_SANDBLAST_SIDE] = HandleSetEffectSandblastSide,
    [MOVE_EFFECT_YAWN_FOE] = HandleSetEffectYawnFoe,
    [MOVE_EFFECT_AROMATHERAPY] = HandleSetEffectAromatherapy,
    [MOVE_EFFECT_CONFUSE_SIDE] = HandleSetEffectConfuseSide,
    [MOVE_EFFECT_STEELSURGE] = HandleSetEffectSteelsurge,
    [MOVE_EFFECT_STEALTH_ROCK] = HandleSetEffectStealthRock,
    [MOVE_EFFECT_TORMENT_SIDE] = HandleSetEffectTormentSide,
    [MOVE_EFFECT_FIRE_SPIN_SIDE] = HandleSetEffectFireSpinSide,
    [MOVE_EFFECT_FIXED_POWER] = HandleSetEffectNone,
    [STAT_CHANGE_EFFECT_PLUS] = HandleSetEffectNone,
    [STAT_CHANGE_EFFECT_MINUS] = HandleSetEffectNone,
    [MOVE_EFFECT_BREAK_SCREEN] = HandleSetEffectBreakScreen,
    [MOVE_EFFECT_STEAL_STATS] = HandleSetEffectStealStats,
    [MOVE_EFFECT_BEAT_UP_MESSAGE] = HandleSetEffectBeatUpMessage,
    [MOVE_EFFECT_ITEM_MESSAGE] = HandleSetEffectItemMessage,
    [SECRET_POWER_ATK_MINUS_1] = HandleSetEffectNone,
    [SECRET_POWER_DEF_MINUS_1] = HandleSetEffectNone,
    [SECRET_POWER_SPD_MINUS_1] = HandleSetEffectNone,
    [SECRET_POWER_SP_ATK_MINUS_1] = HandleSetEffectNone,
    [SECRET_POWER_ACC_MINUS_1] = HandleSetEffectNone,
};

void SetMoveEffect(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (ShouldTryToApplyEffect(cv, se))
    {
        gBattleScripting.battler = cv->battlerAtk;
        gEffectBattler = se->effectBattler;
        sSetEffectHandlers[se->moveEffect](cv, se);
    }
    gBattleScripting.moveEffect = MOVE_EFFECT_NONE;
}

static bool32 ShouldTryToApplyEffect(struct BattleCalcValues *cv, struct SetEffect *se)
{
    bool32 affectsUser = (cv->battlerAtk == se->effectBattler);

    if (gSpecialStatuses[cv->battlerAtk].parentalBondState == PARENTAL_BOND_1ST_HIT
     && IsBattlerAlive(se->effectBattler)
     && IsFinalStrikeEffect(se->moveEffect))
        return FALSE;

    if (cv->isStatusMove)
        return TRUE;

    if (!se->primary && !affectsUser && IsMoveEffectBlockedByTarget(cv->abilities[se->effectBattler]))
        return FALSE;

    if (!se->primary
     && IsSheerForceAffected(cv->move, cv->abilities[cv->battlerAtk])
     && !(se->moveEffect == MOVE_EFFECT_ORDER_UP && gBattleStruct->battlerState[cv->battlerAtk].commanderSpecies != SPECIES_NONE))
        return FALSE;

    if (!IsBattlerAlive(se->effectBattler) && !IgnoreTargetingForMoveEffect(se->moveEffect))
        return FALSE;

    if (DoesSubstituteBlockMoveEffectOnTarget(cv->battlerAtk, se->effectBattler, se->moveEffect))
        return FALSE;

    return TRUE;
}

void SetMoveEffectHelper(enum BattlerId battlerAtk, enum BattlerId effectBattler, enum MoveEffect moveEffect, const u8 *battleScript, enum SetMoveEffectFlags effectFlags)
{
    struct BattleCalcValues cv = {0};
    cv.battlerAtk = battlerAtk;
    cv.battlerDef = gBattlerTarget;
    cv.move = gCurrentMove; // Should be set to None eventually. When Cmd_seteffectprimary is gone

    for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
    {
        cv.abilities[battler] = GetBattlerAbility(battler);
        cv.holdEffects[battler] = GetBattlerHoldEffect(battler);
    }

    struct SetEffect se = {0};
    se.moveEffect = moveEffect;
    se.script = battleScript;
    se.effectBattler = effectBattler;
    se.primary = effectFlags & EFFECT_PRIMARY;
    se.certain = effectFlags & EFFECT_CERTAIN;

    SetMoveEffect(&cv, &se);
}

static void BattleScriptPushAndSet(const u8 *currentScript, const u8 *effectScript)
{
    BattleScriptPush(currentScript);
    gBattlescriptCurrInstr = effectScript;
}

static inline bool32 IgnoreTargetingForMoveEffect(enum MoveEffect moveEffect) // Currently only used to determine move effects which happen even if the move's defined effectbattler is fainted
{
    switch (moveEffect)
    {
    case MOVE_EFFECT_PAYDAY:
    case MOVE_EFFECT_BUG_BITE:
    case MOVE_EFFECT_FLAME_BURST:
    case MOVE_EFFECT_STEALTH_ROCK:
    case MOVE_EFFECT_STEELSURGE:
    case MOVE_EFFECT_SUN:
    case MOVE_EFFECT_RAIN:
    case MOVE_EFFECT_SANDSTORM:
    case MOVE_EFFECT_HAIL:
    case MOVE_EFFECT_MISTY_TERRAIN:
    case MOVE_EFFECT_GRASSY_TERRAIN:
    case MOVE_EFFECT_ELECTRIC_TERRAIN:
    case MOVE_EFFECT_PSYCHIC_TERRAIN:
    case MOVE_EFFECT_DEFOG:
    case MOVE_EFFECT_ION_DELUGE:
    case MOVE_EFFECT_HAZE:
    case MOVE_EFFECT_VINE_LASH:
    case MOVE_EFFECT_WILDFIRE:
    case MOVE_EFFECT_CANNONADE:
    case MOVE_EFFECT_VOLCALITH:
    case MOVE_EFFECT_PREVENT_ESCAPE_SIDE:
    case MOVE_EFFECT_SANDBLAST_SIDE:
    case MOVE_EFFECT_FIRE_SPIN_SIDE:
    case MOVE_EFFECT_PARALYZE_SIDE:
    case MOVE_EFFECT_POISON_SIDE:
    case MOVE_EFFECT_CONFUSE_PAY_DAY_SIDE:
    case MOVE_EFFECT_POISON_PARALYZE_SIDE:
    case MOVE_EFFECT_EFFECT_SPORE_SIDE:
    case MOVE_EFFECT_INFATUATE_SIDE:
    case MOVE_EFFECT_CONFUSE_SIDE:
    case MOVE_EFFECT_TORMENT_SIDE:
    case MOVE_EFFECT_CORE_ENFORCER:
    case MOVE_EFFECT_RAINBOW:
    case MOVE_EFFECT_SEA_OF_FIRE:
    case MOVE_EFFECT_SWAMP:
    case MOVE_EFFECT_ABSORB:
    case MOVE_EFFECT_STICKY_WEB:
        return TRUE;
    default:
        return FALSE;
    }
}

static bool32 DoesSubstituteBlockMoveEffectOnTarget(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum MoveEffect moveEffect)
{
    if (battlerAtk == battlerDef)
        return FALSE;

    if (moveEffect != MOVE_EFFECT_BUG_BITE && IgnoreTargetingForMoveEffect(moveEffect))
        return FALSE;

    if (moveEffect == MOVE_EFFECT_BREAK_SCREEN)
        return FALSE;

    if (DoesSubstituteBlockMove(battlerAtk, battlerDef, gCurrentMove))
        return TRUE;

    return FALSE;
}

static bool32 IsFinalStrikeEffect(enum MoveEffect moveEffect)
{
    switch (moveEffect)
    {
    case MOVE_EFFECT_REMOVE_ARG_TYPE:
    case MOVE_EFFECT_REMOVE_STATUS:
    case MOVE_EFFECT_RECOIL_HP_25:
    case MOVE_EFFECT_PREVENT_ESCAPE:
    case MOVE_EFFECT_MEAN_LOOK:
    case MOVE_EFFECT_WRAP:
        return TRUE;
    default:
        return FALSE;
    }
}

static bool32 CanAbilityShieldActivateForBattler(enum BattlerId battler)
{
    if (GetBattlerHoldEffectIgnoreAbility(battler) != HOLD_EFFECT_ABILITY_SHIELD)
        return FALSE;

    RecordItemEffectBattle(battler, HOLD_EFFECT_ABILITY_SHIELD);
    gBattlerAbility = battler;
    gLastUsedItem = gBattleMons[battler].item;
    return TRUE;
}

static void SwapStatStages(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Stat stat)
{
    s8 *atkStatStage = &gBattleMons[battlerAtk].statStages[stat];
    s8 *defStatStage = &gBattleMons[battlerDef].statStages[stat];
    Swap(*atkStatStage, *defStatStage);
}

#define TYPE_HALVER(...) (struct TypeBasedHalverInfo){__VA_ARGS__}
static struct TypeBasedHalverInfo GetTypeBasedHalverInfo(enum Type type)
{
    switch(type)
    {
        case TYPE_FIRE:
            return TYPE_HALVER(STATUS_FIELD_WATERSPORT, VOLATILE_WATER_SPORT, STRINGID_FIREWEAKENED);
        case TYPE_ELECTRIC:
            return TYPE_HALVER(STATUS_FIELD_MUDSPORT, VOLATILE_MUD_SPORT, STRINGID_ELECTRICITYWEAKENED);
        default:
            errorf("Type (%s) does not have a halver", gTypesInfo[type].name);
            return TYPE_HALVER(STATUS_FIELD_MUDSPORT, VOLATILE_MUD_SPORT, STRINGID_ELECTRICITYWEAKENED);

    }
}

static inline enum MoveEffect GetSynchronizeEffect(u32 status)
{
    if (status & STATUS1_POISON)       return MOVE_EFFECT_POISON;
    if (status & STATUS1_TOXIC_POISON) return MOVE_EFFECT_TOXIC;
    if (status & STATUS1_BURN)         return MOVE_EFFECT_BURN;
    if (status & STATUS1_PARALYSIS)    return MOVE_EFFECT_PARALYSIS;
    if (status & STATUS1_SLEEP)        return MOVE_EFFECT_SLEEP;
    if (status & STATUS1_FROSTBITE)    return MOVE_EFFECT_FREEZE_OR_FROSTBITE;

    return MOVE_EFFECT_NONE;
}

enum StringID GetStatus1String(u32 status1)
{
    if (status1 & STATUS1_POISON)       return STRINGID_PKMNWASPOISONED;
    if (status1 & STATUS1_TOXIC_POISON) return STRINGID_PKMNBADLYPOISONED;
    if (status1 & STATUS1_BURN)         return STRINGID_PKMNWASBURNED;
    if (status1 & STATUS1_PARALYSIS)    return STRINGID_PKMNWASPARALYZED;
    if (status1 & STATUS1_SLEEP)        return STRINGID_PKMNFELLASLEEP;
    if (status1 & STATUS1_FROSTBITE)    return STRINGID_PKMNGOTFROSTBITE;

    return STRINGID_EMPTYSTRING3;
}

static s32 GetMaxHpWithRounding(enum BattlerId battler)
{
    if (B_UPDATED_MOVE_DATA >= GEN_5)
        return GetNonDynamaxMaxHP(battler) + 1;
    return GetNonDynamaxMaxHP(battler);
}
