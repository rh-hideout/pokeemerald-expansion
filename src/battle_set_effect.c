#include "global.h"
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
#include "battle_gimmick.h"
#include "battle_terastal.h"
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
#include "pokemon.h"
#include "util.h"
#include "move.h"
#include "random.h"
#include "string_util.h"
#include "config/battle.h"

#define SetEffectFail(failScript, ...) \
    do \
    { \
        se->effectFailed = TRUE; \
        if (!cv->onlyChecking __VA_OPT__(&& __VA_ARGS__))\
            BattleScriptPushAndSet(se->script, failScript); \
    } while (0)

#define SetEffectFailAndCheckReturn \
    do \
    { \
        se->effectFailed = TRUE; \
        if (cv->onlyChecking)\
            return; \
    } while (0)

static void BattleScriptPushAndSet(const u8 *currentScript, const u8 *effectScript);
static inline bool32 IgnoreTargetingForMoveEffect(enum MoveEffect moveEffect);
static bool32 DoesSubstituteBlockMoveEffectOnTarget(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum MoveEffect moveEffect);
static bool32 IsFinalStrikeEffect(enum MoveEffect moveEffect);

static void HandleSetEffectNone(struct BattleCalcValues *cv, struct SetEffect *se)
{
    gBattlescriptCurrInstr = se->script;

    assertf(se->moveEffect != MOVE_EFFECT_FLORAL_HEALING, "no effect assigned to MOVE_EFFECT_FLORAL_HEALING");
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

    if (cv->onlyChecking)
        return;

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
        gBattleStruct->battlerState[gBattlerAttacker].alreadyStatusedMoveAttempt = TRUE;
        PrepareStringBattleWithWait(STRINGID_PKMNALREADYCONFUSED, se->effectBattler);
        gBattlescriptCurrInstr = se->script;
    }
    else if (IsMistyTerrainAffected(se->effectBattler, effectAbility, effectHoldEffect, gFieldTimers.terrain))
    {
        SetEffectFailAndCheckReturn;
        PrepareStringBattleWithWait(STRINGID_MISTYTERRAINPREVENTS, se->effectBattler);
        gBattlescriptCurrInstr = se->script;
    }
    else if (IsSafeguardProtected(cv->battlerAtk, se->effectBattler, atkAbility))
    {
        SetEffectFailAndCheckReturn;
        PrepareStringBattleWithWait(STRINGID_MISTYTERRAINPREVENTS, se->effectBattler);
        gBattlescriptCurrInstr = se->script;
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
        enum MoveTarget moveTarget = GetBattlerMoveTargetType(cv->battlerAtk, cv->move);
        gPaydayMoney += (gBattleMons[cv->battlerAtk].level * 5);
        if (payday > gPaydayMoney)
            gPaydayMoney = 0xFFFF;

        // For a move that hits multiple targets (i.e. Make it Rain)
        // we only want to print the message on the final hit
        if (!(NumAffectedSpreadMoveTargets() > 1 && GetNextTarget(moveTarget, TRUE) != MAX_BATTLERS_COUNT))
        {
            BattleScriptPush(se->script);
            gBattlescriptCurrInstr = BattleScript_MoveEffectPayDay;
        }
        else
        {
            gBattlescriptCurrInstr = se->script;
        }
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
    gBattleMons[se->effectBattler].volatiles.nightmare = TRUE;
    gBattlescriptCurrInstr = se->script;
}

static void HandleSetEffectGlaiveRush(struct BattleCalcValues *cv, struct SetEffect *se)
{
    gBattleMons[cv->battlerAtk].volatiles.glaiveRush = TRUE;
    gBattlescriptCurrInstr = se->script;
}

static void HandleSetEffectRemoveStatus(struct BattleCalcValues *cv, struct SetEffect *se)
{
    u32 argStatus = GetMoveEffectArg_Status(gCurrentMove); // TODO: use the arg field in move effect
    if ((gBattleMons[se->effectBattler].status1 & argStatus)
     && (NumAffectedSpreadMoveTargets() > 1 || !IsMoveEffectBlockedByTarget(cv->abilities[se->effectBattler])))
    {
        gBattleScripting.battler = se->effectBattler;
        gBattleMons[se->effectBattler].status1 &= ~(argStatus);
        BtlController_EmitSetMonData(se->effectBattler, 0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[se->effectBattler].status1);
        MarkBattlerForControllerExec(se->effectBattler);
        BattleScriptPush(se->script);

        switch (argStatus)
        {
        case STATUS1_PARALYSIS:
            gBattlescriptCurrInstr = BattleScript_TargetPRLZHeal;
            break;
        case STATUS1_SLEEP:
            TryDeactivateSleepClause(se->effectBattler, gBattlerPartyIndexes[se->effectBattler]);
            gBattlescriptCurrInstr = BattleScript_TargetWokeUp;
            break;
        case STATUS1_BURN:
            gBattlescriptCurrInstr = BattleScript_TargetBurnHeal;
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
            gBattlescriptCurrInstr = BattleScript_TargetPoisonHealed;
            break;
        }
    }
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
     && GetBattlerAbility(partner) != ABILITY_MAGIC_GUARD)
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
    if (IsOnPlayerSide(cv->battlerAtk) && !gBattleStruct->moneyMultiplierMove)
    {
        gBattleStruct->moneyMultiplier *= 2;
        gBattleStruct->moneyMultiplierMove = 1;
    }
    gBattlescriptCurrInstr = se->script;
}

static void HandleSetEffectCoreEnforcer(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (HasBattlerActedThisTurn(se->effectBattler)
     && gBattleStruct->battlerState[se->effectBattler].isFirstTurn != 2
     && !NoAliveMonsForEitherParty())
    {
        if (gBattleMons[se->effectBattler].volatiles.gastroAcid
         || gAbilitiesInfo[gBattleMons[se->effectBattler].ability].cantBeSuppressed)
        {
            se->effectFailed = TRUE;
        }

        if (GetBattlerHoldEffectIgnoreAbility(se->effectBattler) == HOLD_EFFECT_ABILITY_SHIELD)
        {
            se->effectFailed = TRUE;
            if (cv->onlyChecking)
                RecordItemEffectBattle(se->effectBattler, HOLD_EFFECT_ABILITY_SHIELD);
        }

        if (cv->onlyChecking || se->effectFailed)
            return;

        if (gBattleMons[se->effectBattler].volatiles.neutralizingGas)
            gSpecialStatuses[se->effectBattler].neutralizingGasRemoved = TRUE;

        RemoveRuinAbilityFlags(se->effectBattler);
        gBattleMons[se->effectBattler].volatiles.gastroAcid = TRUE;

        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectGastroAcid;
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
    if (cv->abilities[se->effectBattler] == ABILITY_STICKY_HOLD)
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
    s32 recoil = (gBattleMons[se->effectBattler].maxHP) / 4;
    if (B_UPDATED_MOVE_DATA >= GEN_5 && (gBattleMons[se->effectBattler].maxHP % 4) >= 2) // Account for standard rounding (Gen5+)
        recoil++;
    if (recoil == 0)
        recoil = 1;

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
            if (gBattlerByTurnOrder[i] == gBattlerAttacker)
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

static void HandleSetEffectPsychicNoise(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattlerId battler = IsAbilityOnSide(se->effectBattler, ABILITY_AROMA_VEIL); // TODO: Create a new func that uses an array as input

    if (gBattleMons[se->effectBattler].volatiles.healBlockTimer)
    {
        se->effectFailed = TRUE;
        if (!cv->onlyChecking && cv->isStatusMove)
            BattleScriptPushAndSet(se->script, BattleScript_ButItFailedRet);
    }
    else if (battler)
    {
        se->effectFailed = TRUE;
        if (!cv->onlyChecking)
        {
            gBattlerAbility = battler - 1;
            BattleScriptPushAndSet(se->script, BattleScript_AromaVeilProtectsRet);
        }
    }

    if (cv->onlyChecking || se->effectFailed)
        return;

    gBattleMons[se->effectBattler].volatiles.healBlockTimer = 2;
    PrepareStringBattleWithWait(STRINGID_PKMNPREVENTEDFROMHEALING, se->effectBattler);
    BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
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
    if (!(gFieldStatuses & STATUS_FIELD_ION_DELUGE))
    {
        gFieldStatuses |= STATUS_FIELD_ION_DELUGE;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectIonDeluge;
    }
}

static void HandleSetEffectHaze(struct BattleCalcValues *cv, struct SetEffect *se)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
        TryResetBattlerStatChanges(battler);
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_MoveEffectHaze;
}

static void HandleSetEffectLeechSeed(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (IsBattlerUnaffectedByMove(se->effectBattler) || gBattleMons[se->effectBattler].volatiles.leechSeed)
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_LEECH_SEED_MISS;
        se->effectFailed = TRUE;
    }
    else if (IS_BATTLER_OF_TYPE(se->effectBattler, TYPE_GRASS))
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_LEECH_SEED_FAIL;
        se->effectFailed = TRUE;
    }

    if (cv->onlyChecking)
        return;

    if (se->effectFailed && !cv->isStatusMove)
        return;

    if (!se->effectFailed)
    {
        gBattleMons[se->effectBattler].volatiles.leechSeed = LEECHSEEDED_BY(cv->battlerAtk);
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_LEECH_SEED_SET;
    }

    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_MoveEffectLeechSeed;
}

static void HandleSetEffectReflect(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);

    if (gSideStatuses[side] & SIDE_STATUS_REFLECT)
    {
        se->effectFailed = TRUE;
        if (!cv->onlyChecking)
            PrepareStringBattleWithWait(STRINGID_BUTITFAILED, se->effectBattler);
    }

    if (cv->onlyChecking)
        return;

    if (se->effectFailed && !cv->isStatusMove)
        return;

    if (!se->effectFailed)
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
        se->effectFailed = TRUE;
        if (!cv->onlyChecking)
            PrepareStringBattleWithWait(STRINGID_BUTITFAILED, se->effectBattler);
    }

    if (cv->onlyChecking)
        return;

    if (se->effectFailed && !cv->isStatusMove)
        return;

    if (!se->effectFailed)
    {
        gSideStatuses[side] |= SIDE_STATUS_LIGHTSCREEN;

        if (cv->holdEffects[se->effectBattler] == HOLD_EFFECT_LIGHT_CLAY)
            gSideTimers[side].lightscreenTimer = 8;
        else
            gSideTimers[side].lightscreenTimer = 5;

        PrepareStringBattleWithWait(STRINGID_PKMNRAISEDSPDEF, se->effectBattler);
    }

    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_MoveEffectSetStatus;
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

        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectEerieSpell;
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
            gBattlescriptCurrInstr = BattleScript_EffectFlingConsumeBerry;
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

static void HandleSetEffectWeather(struct BattleCalcValues *cv, struct SetEffect *se)
{
    u32 weather = 0, msg = 0;
    switch (se->moveEffect)
    {
    case MOVE_EFFECT_SUN:
        weather = BATTLE_WEATHER_SUN;
        msg = B_MSG_STARTED_SUNLIGHT;
        break;
    case MOVE_EFFECT_RAIN:
        weather = BATTLE_WEATHER_RAIN;
        msg = B_MSG_STARTED_RAIN;
        break;
    case MOVE_EFFECT_SANDSTORM:
        weather = BATTLE_WEATHER_SANDSTORM;
        msg = B_MSG_STARTED_SANDSTORM;
        break;
    case MOVE_EFFECT_HAIL:
        if (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW)
        {
            weather = BATTLE_WEATHER_SNOW;
            msg = B_MSG_STARTED_SNOW;
        }
        else
        {
            weather = BATTLE_WEATHER_HAIL;
            msg = B_MSG_STARTED_HAIL;
        }
        break;
    default:
        break;
    }
    if (TryChangeBattleWeather(cv->battlerAtk, weather, ABILITY_NONE) == WEATHER_FAILURE_SUCCESS)
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = msg;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectSetWeather;
    }
}

static void HandleSetEffectTerrain(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleTerrain terrain = B_TERRAIN_NONE;
    switch (se->moveEffect)
    {
    case MOVE_EFFECT_MISTY_TERRAIN:
        terrain = B_TERRAIN_MISTY;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_MISTY;
        break;
    case MOVE_EFFECT_GRASSY_TERRAIN:
        terrain = B_TERRAIN_GRASSY;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_GRASSY;
        break;
    case MOVE_EFFECT_ELECTRIC_TERRAIN:
        terrain = B_TERRAIN_ELECTRIC;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_ELECTRIC;
        break;
    case MOVE_EFFECT_PSYCHIC_TERRAIN:
        terrain = B_TERRAIN_PSYCHIC;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_PSYCHIC;
        break;
    default:
        break;
    }
    if (TryChangeBattleTerrain(cv->battlerAtk, terrain))
    {
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectSetTerrain;
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
        se->effectFailed = TRUE;
        if (!cv->onlyChecking)
            PrepareStringBattleWithWait(STRINGID_BUTITFAILED, se->effectBattler);
    }

    if (cv->onlyChecking)
        return;

    if (se->effectFailed && !cv->isStatusMove)
        return;

    if (!se->effectFailed)
    {
        gSideStatuses[side] |= SIDE_STATUS_AURORA_VEIL;

        if (cv->holdEffects[se->effectBattler] == HOLD_EFFECT_LIGHT_CLAY)
            gSideTimers[side].reflectTimer = 8;
        else
            gSideTimers[side].reflectTimer = 5;

        PrepareStringBattleWithWait(STRINGID_PKMNAURORAVEIL, se->effectBattler);
    }

    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_MoveEffectSetStatus;
}

static void HandleSetEffectInfatuateSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectInfatuateSide;
}

static void HandleSetEffectRecycleBerries(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (RandomPercentage(RNG_G_MAX_REPLENISH, 50))
    {
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_EffectRecycleBerriesAllies;
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

static void HandleSetEffectSpite(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gLastMoves[se->effectBattler] != MOVE_NONE && gLastMoves[se->effectBattler] != MOVE_UNAVAILABLE)
    {
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectSpite;
    }
}

static void HandleSetEffectGravity(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!(gFieldStatuses & STATUS_FIELD_GRAVITY))
    {
        gFieldStatuses |= STATUS_FIELD_GRAVITY;
        gFieldTimers.gravityTimer = 5;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectGravity;
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
    if (!IsHazardOnSide(GetBattlerSide(se->effectBattler), HAZARDS_STEELSURGE))
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SHARPSTEELFLOATS;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectSteelsurge;
    }

    PrepareStringBattleWithWait(STRINGID_POINTEDSTONESFLOAT, se->effectBattler);
    BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
}

static void HandleSetEffectStealthRock(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);

    if (IsHazardOnSide(side, HAZARDS_STEALTH_ROCK))
        se->effectFailed = TRUE;

    if (cv->onlyChecking)
        return;

    if (se->effectFailed)
    {
        if (cv->isStatusMove)
            BattleScriptPushAndSet(se->script, BattleScript_ButItFailedRet);
    }
    else
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
    if (cv->onlyChecking)
        return;

    u32 temp;
    SWAP(gBattleMons[gBattlerAttacker].speed, gBattleMons[gBattlerTarget].speed, temp);
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
        se->effectFailed = TRUE;
        if (!cv->onlyChecking)
            PrepareStringBattleWithWait(STRINGID_BUTITFAILED, se->effectBattler);
    }

    if (cv->onlyChecking)
        return;

    if (se->effectFailed && !cv->isStatusMove)
        return;

    if (!se->effectFailed)
    {
        gSideStatuses[side] |= SIDE_STATUS_SAFEGUARD;
        gSideTimers[side].safeguardTimer = 5;
        PrepareStringBattleWithWait(STRINGID_PKMNCOVEREDBYVEIL, se->effectBattler);
    }

    BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
}

// For generic (simple) volatiles
static void TryEffectVolatile(struct BattleCalcValues *cv, struct SetEffect *se, u32 _volatile, u32 value, enum StringID string)
{
    if (GetBattlerVolatile(se->effectBattler, _volatile) != 0)
    {
        se->effectFailed = TRUE;
        if (!cv->onlyChecking)
            PrepareStringBattleWithWait(STRINGID_BUTITFAILED, se->effectBattler);
    }

    if (cv->onlyChecking)
        return;

    if (se->effectFailed && !cv->isStatusMove)
        return;

    if (!se->effectFailed)
    {
        SetMonVolatile(se->effectBattler, _volatile, value);
        PrepareStringBattleWithWait(string, se->effectBattler);
    }

    BattleScriptPushAndSet(se->script, BattleScript_MoveEffectSetStatus);
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
        se->effectFailed = TRUE;
        if (!cv->onlyChecking)
            PrepareStringBattleWithWait(STRINGID_BUTITFAILED, se->effectBattler);
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
        se->effectFailed = TRUE;
        if (!cv->onlyChecking)
            PrepareStringBattleWithWait(STRINGID_BUTITFAILED, se->effectBattler);
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
        se->effectFailed = TRUE;
        if (!cv->onlyChecking)
            PrepareStringBattleWithWait(STRINGID_BUTITFAILED, se->effectBattler);
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
        se->effectFailed = TRUE;

    if (cv->onlyChecking)
        return;

    if (se->effectFailed)
    {
        if (cv->isStatusMove)
            BattleScriptPushAndSet(se->script, BattleScript_ButItFailedRet);
    }
    else
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
        se->effectFailed = TRUE;

    if (cv->onlyChecking)
        return;

    if (se->effectFailed)
    {
        if (cv->isStatusMove)
            BattleScriptPushAndSet(se->script, BattleScript_ButItFailedRet);
    }
    else
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
    enum BattlerId aromaVeilBattler = IsAbilityOnSide(se->effectBattler, ABILITY_AROMA_VEIL);

    u32 moveIndex = 0;
    for (moveIndex = 0; moveIndex <= MAX_MON_MOVES; moveIndex++)
    {
        if (gBattleMons[se->effectBattler].moves[moveIndex] == gLastMoves[se->effectBattler])
            break;
    }

    if (gBattleMons[se->effectBattler].volatiles.disabledMove == MOVE_NONE
        && moveIndex != MAX_MON_MOVES
        && gBattleMons[se->effectBattler].pp[moveIndex] != 0)
    {
        if (cv->onlyChecking)
            return;

        gBattleMons[se->effectBattler].volatiles.disabledMove = gBattleMons[se->effectBattler].moves[moveIndex];

        if (B_DISABLE_TURNS >= GEN_5)
            gBattleMons[se->effectBattler].volatiles.disableTimer = B_DISABLE_TIMER;
        else if (B_DISABLE_TURNS >= GEN_4)
            gBattleMons[se->effectBattler].volatiles.disableTimer = (Random() & 3) + B_DISABLE_TIMER; // 4-7 turns
        else
            gBattleMons[se->effectBattler].volatiles.disableTimer = (Random() & 3) + 2; // 2-5 turns

        PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleMons[se->effectBattler].moves[moveIndex])
        PrepareStringBattleWithWait(STRINGID_PKMNMOVEWASDISABLED, se->effectBattler);
        gBattlescriptCurrInstr = se->script;
    }
    else if (aromaVeilBattler)
    {
        SetEffectFailAndCheckReturn;

        gBattlerAbility = aromaVeilBattler - 1;
        BattleScriptPushAndSet(se->script, BattleScript_AromaVeilProtectsRet);
    }
    else
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
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

static void HandleSetEffectSpiderWeb(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectPerishSong(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectLockOn(struct BattleCalcValues *cv, struct SetEffect *se)
{
    bool32 isLockedOn = gBattleMons[cv->battlerAtk].volatiles.battlerWithSureHit != 0;

    if (isLockedOn)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else {
        gBattleMons[cv->battlerAtk].volatiles.lockOn = 2;
        gBattleMons[cv->battlerAtk].volatiles.battlerWithSureHit = se->effectBattler + 1;
        PrepareStringBattleWithWait(STRINGID_PKMNTOOKAIM, se->effectBattler);
        gBattlescriptCurrInstr = se->script;
    }

}

static void HandleSetEffectMeanLook(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectAttract(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattlerId armovaVeilBattler = IsAbilityOnSide(se->effectBattler, ABILITY_AROMA_VEIL);

    if (gBattleMons[se->effectBattler].volatiles.infatuation || !AreBattlersOfOppositeGender(gBattlerAttacker, se->effectBattler))
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (armovaVeilBattler)
    {
        SetEffectFail(BattleScript_AromaVeilProtectsRet);
        gBattlerAbility = armovaVeilBattler - 1;
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

static void HandleSetEffectPainSplit(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectTorment(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattlerId aromaVeilBattler = IsAbilityOnSide(se->effectBattler, ABILITY_AROMA_VEIL);

    if (gBattleMons[se->effectBattler].volatiles.torment
     || GetActiveGimmick(se->effectBattler) == GIMMICK_DYNAMAX)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (aromaVeilBattler)
    {
        SetEffectFail(BattleScript_AromaVeilProtectsRet);
        gBattlerAbility = aromaVeilBattler - 1;
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

static void HandleSetEffectRecycle(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectYawn(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectImprison(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectRefresh(struct BattleCalcValues *cv, struct SetEffect *se)
{
    // curestatuswithmove BattleScript_ButItFailed
    // printfromtable gCureStatusStringIds
    // waitmessage B_WAIT_TIME_LONG
    // updatestatusicon BS_ATTACKER
    // goto BattleScript_MoveEnd

    enum StringID cureString = STRINGID_EMPTYSTRING3;

    u32 status = gBattleMons[se->effectBattler].status1;
    u32 shouldHeal = status & STATUS1_CAN_MOVE;

    if (!shouldHeal)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else
    {
        if (cv->onlyChecking)
            return;

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
        BtlController_EmitSetMonData(se->effectBattler, B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gBattlerAttacker].status1), &gBattleMons[gBattlerAttacker].status1);
        MarkBattlerForControllerExec(se->effectBattler);
        gBattleScripting.savedStringId = cureString;
        BattleScriptPushAndSet(se->script, BattleScript_MoveEffectRefresh);

    }

}

static void HandleSetEffectMudSport(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectOdorSleuth(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectBlock(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectWaterSport(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectTailwind(struct BattleCalcValues *cv, struct SetEffect *se)
{
    u32 side = GetBattlerSide(se->effectBattler);

    if (!(gSideStatuses[side] & SIDE_STATUS_TAILWIND))
    {
        if (cv->onlyChecking)
            return;

        gSideStatuses[side] |= SIDE_STATUS_TAILWIND;
        gSideTimers[side].tailwindTimer = (GetConfig(B_TAILWIND_TURNS) >= GEN_5 ? 4 : 3);
        gBattlescriptCurrInstr = se->script;
        PrepareStringBattleWithWait(STRINGID_TAILWINDBLEW, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_TryTailwindAbilitiesLoop);
    }
    else
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
}

static void HandleSetEffectPsychoShift(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectPowerTrick(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->onlyChecking)
        return;

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
        se->effectFailed = TRUE;
    }
    else if (GetBattlerHoldEffectIgnoreAbility(se->effectBattler) == HOLD_EFFECT_ABILITY_SHIELD)
    {
        se->effectFailed = TRUE;
        if (cv->onlyChecking)
            RecordItemEffectBattle(se->effectBattler, HOLD_EFFECT_ABILITY_SHIELD);
    }

    if (cv->onlyChecking)
        return;

    if (se->effectFailed)
    {
        if (cv->isStatusMove)
            BattleScriptPushAndSet(se->script, BattleScript_ButItFailedRet);
    }
    else
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
    else
    {
        if (cv->onlyChecking)
            return;

        gSideStatuses[side] |= SIDE_STATUS_LUCKY_CHANT;
        PrepareStringBattleWithWait(STRINGID_SHIELDEDFROMCRITICALHITS, se->effectBattler);
        gSideTimers[side].luckyChantTimer = 5;
        gBattlescriptCurrInstr = se->script;
    }
}

static void HandleSetEffectStatSwap(struct BattleCalcValues *cv, struct SetEffect *se)
{
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
    else
    {
        if (cv->onlyChecking)
            return;

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

static void HandleSetEffectSwitcheroo(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectTrickRoom(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectLunarDance(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectGuardSplit(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectPowerSplit(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectWonderRoom(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectTelekinesis(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectMagicRoom(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectOverwriteType(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->abilities[se->effectBattler] == ABILITY_MULTITYPE
     || cv->abilities[se->effectBattler] == ABILITY_RKS_SYSTEM)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else
    {
        enum Type types[3];
        GetBattlerTypes(se->effectBattler, FALSE, types);
        enum Type typeToSet = se->additionalEffect->argument.type;

        if ((types[0] == typeToSet && types[1] == typeToSet)
         || GetActiveGimmick(se->effectBattler) == GIMMICK_TERA)
        {
            se->effectFailed = TRUE;

            if (!cv->onlyChecking && cv->isStatusMove)
                BattleScriptPushAndSet(se->script, BattleScript_ButItFailedRet);
        }
        else
        {
            SET_BATTLER_TYPE(se->effectBattler, typeToSet);
            PREPARE_TYPE_BUFFER(gBattleTextBuff1, typeToSet);
            BattleScriptPushAndSet(se->script, BattleScript_MoveEffectOverwriteType);
        }
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
        se->effectFailed = TRUE;
        if (!cv->onlyChecking)
            BattleScriptPushAndSet(se->script, BattleScript_AbilityShieldProtects);
    }
    else
    {
        bool32 isDynamaxed = GetActiveGimmick(se->effectBattler) == GIMMICK_DYNAMAX;
        if (*destAbility == *srcAbility || isDynamaxed)
        {
            se->effectFailed = TRUE;
            if (!cv->onlyChecking && cv->isStatusMove)
                BattleScriptPushAndSet(se->script, BattleScript_ButItFailedRet);
        }
        else
        {
            RemoveAbilityFlags(se->effectBattler);
            *destAbility = gBattleMons[se->effectBattler].volatiles.overwrittenAbility = *srcAbility;
            PrepareStringBattleWithWait(STRINGID_PKMNACQUIREDABILITY, se->effectBattler);
            BattleScriptPushAndSet(se->script, BattleScript_MoveEffectOverwriteAbility);
        }
    }
}

static void HandleSetEffectHealPulse(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectQuash(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectReflectType(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectBestow(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectStickyWeb(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectTopsyTurvy(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectElectrify(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectFairyLock(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectPurify(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectTeatime(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectOctolock(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectCourtChange(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectLifeDew(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectCorrosiveGas(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectJungleHealing(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectPowerShift(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectLunarBlessing(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectRevivalBlessing(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectSnowscape(struct BattleCalcValues *cv, struct SetEffect *se)
{
}

static void HandleSetEffectDragonCheer(struct BattleCalcValues *cv, struct SetEffect *se)
{

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
    [MOVE_EFFECT_CORE_ENFORCER] = HandleSetEffectCoreEnforcer,
    [MOVE_EFFECT_THROAT_CHOP] = HandleSetEffectThroatChop,
    [MOVE_EFFECT_INCINERATE] = HandleSetEffectIncinerate,
    [MOVE_EFFECT_BUG_BITE] = HandleSetEffectBugBite,
    [MOVE_EFFECT_RECOIL_HP_25] = HandleSetEffectRecoilHp25,
    [MOVE_EFFECT_TRAP_BOTH] = HandleSetEffectTrapBoth,
    [MOVE_EFFECT_ROUND] = HandleSetEffectRound,
    [MOVE_EFFECT_SYRUP_BOMB] = HandleSetEffectSyrupBomb,
    [MOVE_EFFECT_FLORAL_HEALING] = HandleSetEffectNone,
    [MOVE_EFFECT_SECRET_POWER] = HandleSetEffectSecretPower,
    [MOVE_EFFECT_PSYCHIC_NOISE] = HandleSetEffectPsychicNoise,
    [MOVE_EFFECT_TERA_BLAST] = HandleSetEffectTeraBlast,
    [MOVE_EFFECT_ORDER_UP] = HandleSetEffectOrderUp,
    [MOVE_EFFECT_ION_DELUGE] = HandleSetEffectIonDeluge,
    [MOVE_EFFECT_HAZE] = HandleSetEffectHaze,
    [MOVE_EFFECT_LEECH_SEED] = HandleSetEffectLeechSeed,
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
    [MOVE_EFFECT_MIST] = HandleSetEffectMist,
    [MOVE_EFFECT_SPIDER_WEB] = HandleSetEffectSpiderWeb,
    [MOVE_EFFECT_PERISH_SONG] = HandleSetEffectPerishSong,
    [MOVE_EFFECT_LOCK_ON] = HandleSetEffectLockOn,
    [MOVE_EFFECT_MEAN_LOOK] = HandleSetEffectMeanLook,
    [MOVE_EFFECT_ATTRACT] = HandleSetEffectAttract,
    [MOVE_EFFECT_PAIN_SPLIT] = HandleSetEffectPainSplit,
    [MOVE_EFFECT_TORMENT] = HandleSetEffectTorment,
    [MOVE_EFFECT_INGRAIN] = HandleSetEffectIngrain,
    [MOVE_EFFECT_RECYCLE] = HandleSetEffectRecycle,
    [MOVE_EFFECT_YAWN] = HandleSetEffectYawn,
    [MOVE_EFFECT_IMPRISON] = HandleSetEffectImprison,
    [MOVE_EFFECT_REFRESH] = HandleSetEffectRefresh,
    [MOVE_EFFECT_MUD_SPORT] = HandleSetEffectMudSport,
    [MOVE_EFFECT_ODOR_SLEUTH] = HandleSetEffectOdorSleuth,
    [MOVE_EFFECT_BLOCK] = HandleSetEffectBlock,
    [MOVE_EFFECT_WATER_SPORT] = HandleSetEffectWaterSport,
    [MOVE_EFFECT_TAILWIND] = HandleSetEffectTailwind,
    [MOVE_EFFECT_PSYCHO_SHIFT] = HandleSetEffectPsychoShift,
    [MOVE_EFFECT_POWER_TRICK] = HandleSetEffectPowerTrick,

    [MOVE_EFFECT_GASTRO_ACID] = HandleSetEffectGastroAcid,

    [MOVE_EFFECT_LUCKY_CHANT] = HandleSetEffectLuckyChant,
    [MOVE_EFFECT_STAT_SWAP] = HandleSetEffectStatSwap,
    [MOVE_EFFECT_OVERWRITE_ABILITY] = HandleSetEffectOverwriteAbility,
    [MOVE_EFFECT_SWITCHEROO] = HandleSetEffectSwitcheroo,
    [MOVE_EFFECT_TRICK_ROOM] = HandleSetEffectTrickRoom,
    [MOVE_EFFECT_LUNAR_DANCE] = HandleSetEffectLunarDance,
    [MOVE_EFFECT_GUARD_SPLIT] = HandleSetEffectGuardSplit,
    [MOVE_EFFECT_POWER_SPLIT] = HandleSetEffectPowerSplit,
    [MOVE_EFFECT_WONDER_ROOM] = HandleSetEffectWonderRoom,
    [MOVE_EFFECT_TELEKINESIS] = HandleSetEffectTelekinesis,
    [MOVE_EFFECT_MAGIC_ROOM] = HandleSetEffectMagicRoom,
    [MOVE_EFFECT_OVERWRITE_TYPE] = HandleSetEffectOverwriteType,
    [MOVE_EFFECT_ENTRAINMENT] = HandleSetEffectEntrainment,
    [MOVE_EFFECT_HEAL_PULSE] = HandleSetEffectHealPulse,
    [MOVE_EFFECT_QUASH] = HandleSetEffectQuash,
    [MOVE_EFFECT_REFLECT_TYPE] = HandleSetEffectReflectType,
    [MOVE_EFFECT_BESTOW] = HandleSetEffectBestow,
    [MOVE_EFFECT_STICKY_WEB] = HandleSetEffectStickyWeb,
    [MOVE_EFFECT_TOPSY_TURVY] = HandleSetEffectTopsyTurvy,
    [MOVE_EFFECT_ELECTRIFY] = HandleSetEffectElectrify,
    [MOVE_EFFECT_FAIRY_LOCK] = HandleSetEffectFairyLock,
    [MOVE_EFFECT_PURIFY] = HandleSetEffectPurify,
    [MOVE_EFFECT_MAGIC_POWDER] = HandleSetEffectOverwriteType,
    [MOVE_EFFECT_TEATIME] = HandleSetEffectTeatime,
    [MOVE_EFFECT_OCTOLOCK] = HandleSetEffectOctolock,
    [MOVE_EFFECT_COURT_CHANGE] = HandleSetEffectCourtChange,
    [MOVE_EFFECT_LIFE_DEW] = HandleSetEffectLifeDew,
    [MOVE_EFFECT_CORROSIVE_GAS] = HandleSetEffectCorrosiveGas,
    [MOVE_EFFECT_JUNGLE_HEALING] = HandleSetEffectJungleHealing,
    [MOVE_EFFECT_POWER_SHIFT] = HandleSetEffectPowerShift,
    [MOVE_EFFECT_LUNAR_BLESSING] = HandleSetEffectLunarBlessing,
    [MOVE_EFFECT_REVIVAL_BLESSING] = HandleSetEffectRevivalBlessing,
    [MOVE_EFFECT_SNOWSCAPE] = HandleSetEffectSnowscape,
    [MOVE_EFFECT_DRAGON_CHEER] = HandleSetEffectDragonCheer,


    [MOVE_EFFECT_SUN] = HandleSetEffectWeather,
    [MOVE_EFFECT_RAIN] = HandleSetEffectWeather,
    [MOVE_EFFECT_SANDSTORM] = HandleSetEffectWeather,
    [MOVE_EFFECT_HAIL] = HandleSetEffectWeather,
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
    [MOVE_EFFECT_RECYCLE_BERRIES] = HandleSetEffectRecycleBerries,
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
    bool32 affectsUser = (cv->battlerAtk == se->effectBattler);

    if (gSpecialStatuses[cv->battlerAtk].parentalBondState == PARENTAL_BOND_1ST_HIT
     && IsBattlerAlive(se->effectBattler)
     && IsFinalStrikeEffect(se->moveEffect))
    {
        gBattlescriptCurrInstr = se->script;
        return;
    }

    gBattleScripting.battler = cv->battlerAtk;
    gEffectBattler = se->effectBattler;

    if (!se->primary && !affectsUser && IsMoveEffectBlockedByTarget(cv->abilities[se->effectBattler]))
        se->moveEffect = MOVE_EFFECT_NONE;
    else if (!se->primary
          && IsSheerForceAffected(cv->move, cv->abilities[cv->battlerAtk])
          && !(se->moveEffect == MOVE_EFFECT_ORDER_UP && gBattleStruct->battlerState[cv->battlerAtk].commanderSpecies != SPECIES_NONE))
        se->moveEffect = MOVE_EFFECT_NONE;
    else if (!IsBattlerAlive(se->effectBattler) && !IgnoreTargetingForMoveEffect(se->moveEffect))
        se->moveEffect = MOVE_EFFECT_NONE;
    else if (DoesSubstituteBlockMoveEffectOnTarget(cv->battlerAtk, se->effectBattler, se->moveEffect))
        se->moveEffect = MOVE_EFFECT_NONE;

    sSetEffectHandlers[se->moveEffect](cv, se);

    gBattleScripting.moveEffect = MOVE_EFFECT_NONE;
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
    case MOVE_EFFECT_WRAP:
        return TRUE;
    default:
        return FALSE;
    }
}

