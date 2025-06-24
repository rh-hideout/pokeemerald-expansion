#include "global.h"
#include "constants/abilities.h"
#include "constants/item.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_move_effects.h"
#include "battle_scripts.h"
#include "battle_script_commands.h"
#include "battle_util.h"
#include "item.h"
#include "pokemon.h"
#include "string_util.h"



static void TryUpdateRoundTurnOrder(void)
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

        // Get battlers after us using round
        for (i = currRounder; i < gBattlersCount; i++)
        {
            if (gChosenMoveByBattler[gBattlerByTurnOrder[i]] == MOVE_ROUND)
                roundUsers[j++] = gBattlerByTurnOrder[i];
            else
                nonRoundUsers[k++] = gBattlerByTurnOrder[i];
        }

        // update turn order for round users
        for (i = 0; roundUsers[i] != 0xFF && i < 3; i++)
        {
            gBattlerByTurnOrder[currRounder] = roundUsers[i];
            gProtectStructs[roundUsers[i]].quash = TRUE; // Make it so their turn order can't be changed again
            currRounder++;
        }

        // Update turn order for non-round users
        for (i = 0; nonRoundUsers[i] != 0xFF && i < 3; i++)
        {
            gBattlerByTurnOrder[currRounder] = nonRoundUsers[i];
            currRounder++;
        }
    }
}

static struct SetMoveEffectResult *SetNonVolatileStatusConditionWithResult(struct SetMoveEffectResult *result, enum StatusTrigger trigger)
{
    if (result->moveEffect == MOVE_EFFECT_SLEEP
     || result->moveEffect == MOVE_EFFECT_FREEZE)
    {
        const u8 *cancelMultiTurnMovesResult = CancelMultiTurnMoves(result->effectBattler, SKY_DROP_STATUS_FREEZE_SLEEP);
        if (cancelMultiTurnMovesResult)
            result->nextInstr = cancelMultiTurnMovesResult;
    }

    switch (result->moveEffect)
    {
    case MOVE_EFFECT_SLEEP:
        if (B_SLEEP_TURNS >= GEN_5)
            gBattleMons[result->effectBattler].status1 = STATUS1_SLEEP_TURN(1 + RandomUniform(RNG_SLEEP_TURNS, 1, 3));
        else
            gBattleMons[result->effectBattler].status1 = STATUS1_SLEEP_TURN(1 + RandomUniform(RNG_SLEEP_TURNS, 2, 5));
        TryActivateSleepClause(result->effectBattler, gBattlerPartyIndexes[result->effectBattler]);
        break;
    default:
        gBattleMons[result->effectBattler].status1 = gMoveEffectsInfo[result->moveEffect].status;
    }

    PushNextInstrAndMoveEffectInstr(result);

    BtlController_EmitSetMonData(result->effectBattler, B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[result->effectBattler].status1), &gBattleMons[result->effectBattler].status1);
    MarkBattlerForControllerExec(result->effectBattler);

    if (trigger == TRIGGER_ON_ABILITY)
        result->multistring = B_MSG_STATUSED_BY_ABILITY;
    else
        result->multistring = B_MSG_STATUSED;

    // Activate Synchronize, Poison Puppeteer
    gBattleStruct->synchronizeMoveEffect = result->moveEffect * gMoveEffectsInfo[result->moveEffect].synchronizeMoveEffect;
    gBattleStruct->poisonPuppeteerConfusion = (result->moveEffect == MOVE_EFFECT_POISON || result->moveEffect == MOVE_EFFECT_TOXIC);

    return result;
}

void SetNonVolatileStatusCondition(u32 battler, u32 effectBattler, enum MoveEffect effect, enum StatusTrigger trigger)
{
    struct SetMoveEffectResult result = {
        .moveEffect = effect,
        .scriptingBattler = battler,
        .effectBattler = effectBattler,
        .statusTrigger = trigger,
    };
    const u8 *currInstr = gBattlescriptCurrInstr;

    // Assign next instruction
    SetMoveEffectHandleResult(SetNonVolatileStatusConditionWithResult(&result, trigger), currInstr, gBattlescriptCurrInstr + 1);
}

static void MoveEffect_SetVolatileTrue(struct SetMoveEffectResult *result)
{
    SetMonVolatile(result->effectBattler, gMoveEffectsInfo[result->moveEffect]._volatile, TRUE);
}

static void MoveEffect_SetNonVolatileStatusCondition(struct SetMoveEffectResult *result)
{
    SetNonVolatileStatusConditionWithResult(result, result->statusTrigger);
}

static void MoveEffect_ConfusionCallback(struct SetMoveEffectResult *result)
{
    gBattleMons[result->effectBattler].volatiles.confusionTurns = ((Random()) % 4) + 2; // 2-5 turns

    // If the confusion is activating due to being released from Sky Drop, go to "confused due to fatigue" script.
    // Otherwise, do normal confusion script.
    if (GetMoveEffect(result->currentMove) == EFFECT_SKY_DROP)
    {
        gBattleMons[result->effectBattler].volatiles.lockConfusionTurns = 0;
        gBattlerAttacker = result->effectBattler;
        result->nextInstr = BattleScript_ThrashConfuses;
    }
    else
        PushNextInstrAndMoveEffectInstr(result);
}

static void MoveEffect_UproarCallback(struct SetMoveEffectResult *result)
{
    gBattleMons[result->effectBattler].volatiles.multipleTurns = TRUE;
    gLockedMoves[result->effectBattler] = result->currentMove;
    gBattleMons[result->effectBattler].volatiles.uproarTurns  = B_UPROAR_TURNS >= GEN_5 ? 3 : (Random() & 3) + 2;

    PushNextInstrAndMoveEffectInstr(result);
}

static void MoveEffect_PaydayCallback(struct SetMoveEffectResult *result)
{
    u16 payday = gPaydayMoney;
    gPaydayMoney += (gBattleMons[result->battlerAtk].level * 5);
    if (payday > gPaydayMoney)
        gPaydayMoney = 0xFFFF;
}

static void MoveEffect_WrapCallback(struct SetMoveEffectResult *result)
{
    MoveEffect_SetVolatileTrue(result);
    if (GetBattlerHoldEffect(result->battlerAtk, TRUE) == HOLD_EFFECT_GRIP_CLAW)
        gDisableStructs[result->effectBattler].wrapTurns = B_BINDING_TURNS >= GEN_5 ? 7 : 5;
    else
        gDisableStructs[result->effectBattler].wrapTurns = B_BINDING_TURNS >= GEN_5 ? (Random() % 2) + 4 : (Random() % 4) + 2;

    gBattleStruct->wrappedMove[result->effectBattler] = result->currentMove;
    gBattleStruct->wrappedBy[result->effectBattler] = result->battlerAtk;

    PushNextInstrAndMoveEffectInstr(result);
}

static void MoveEffect_StealItemCallback(struct SetMoveEffectResult *result)
{
    StealTargetItem(result->battlerAtk, result->battlerDef);  // Attacker steals target item

    if (!(B_STEAL_WILD_ITEMS >= GEN_9
        && !(gBattleTypeFlags & (BATTLE_TYPE_TRAINER | BATTLE_TYPE_PALACE))))
    {
        gBattleMons[result->battlerAtk].item = ITEM_NONE; // Item assigned later on with thief (see MOVEEND_CHANGED_ITEMS)
        gBattleStruct->changedItems[result->battlerAtk] = result->lastUsedItem; // Stolen item to be assigned later
    }

    PushNextInstrAndMoveEffectInstr(result);
}

static void MoveEffect_PreventEscapeCallback(struct SetMoveEffectResult *result)
{
    gBattleMons[result->effectBattler].volatiles.escapePrevention = TRUE;
    gDisableStructs[result->effectBattler].battlerPreventingEscape = gBattlerAttacker;
}

static void MoveEffect_ThrashCallback(struct SetMoveEffectResult *result)
{
    gBattleMons[result->effectBattler].volatiles.multipleTurns = TRUE;
    gLockedMoves[result->effectBattler] = result->currentMove;
    gBattleMons[result->effectBattler].volatiles.lockConfusionTurns = RandomUniform(RNG_RAMPAGE_TURNS, 2, 3);
}

static void MoveEffect_ClearSmogCallback(struct SetMoveEffectResult *result)
{
    for (u32 i = 0; i < NUM_BATTLE_STATS; i++)
        gBattleMons[result->effectBattler].statStages[i] = DEFAULT_STAT_STAGE;

    PushNextInstrAndMoveEffectInstr(result);
}

const struct MoveEffectInfo gMoveEffectsInfo[] =
{
    [MOVE_EFFECT_NONE] =
    {

    },
    [MOVE_EFFECT_SLEEP] =
    {
        .status = STATUS1_SLEEP,
        .battlescript = BattleScript_MoveEffectSleep,
        .callback = MoveEffect_SetNonVolatileStatusCondition,
    },
    [MOVE_EFFECT_POISON] =
    {
        .status = STATUS1_POISON,
        .battlescript = BattleScript_MoveEffectPoison,
        .callback = MoveEffect_SetNonVolatileStatusCondition,
        .synchronizeMoveEffect = TRUE,
    },
    [MOVE_EFFECT_BURN] =
    {
        .status = STATUS1_BURN,
        .battlescript = BattleScript_MoveEffectBurn,
        .callback = MoveEffect_SetNonVolatileStatusCondition,
        .synchronizeMoveEffect = TRUE,
    },
    [MOVE_EFFECT_FREEZE] =
    {
        .status = STATUS1_FREEZE,
        .battlescript = BattleScript_MoveEffectFreeze,
        .callback = MoveEffect_SetNonVolatileStatusCondition,
    },
    [MOVE_EFFECT_PARALYSIS] =
    {
        .status = STATUS1_PARALYSIS,
        .battlescript = BattleScript_MoveEffectParalysis,
        .callback = MoveEffect_SetNonVolatileStatusCondition,
        .synchronizeMoveEffect = TRUE,
    },
    [MOVE_EFFECT_TOXIC] =
    {
        .status = STATUS1_TOXIC_POISON,
        .battlescript = BattleScript_MoveEffectToxic,
        .callback = MoveEffect_SetNonVolatileStatusCondition,
        .synchronizeMoveEffect = TRUE,
    },
    [MOVE_EFFECT_FROSTBITE] =
    {
        .status = STATUS1_FROSTBITE,
        .battlescript = BattleScript_MoveEffectFrostbite,
        .callback = MoveEffect_SetNonVolatileStatusCondition,
    },
    [MOVE_EFFECT_CONFUSION] =
    {
        ._volatile = VOLATILE_CONFUSION,
        .battlescript = BattleScript_MoveEffectConfusion,
        .callback = MoveEffect_ConfusionCallback,
        .blockers = (const struct MoveEffectBlocker[]){
            { MOVE_EFFECT_BLOCKER_ABILITY, .ability = ABILITY_OWN_TEMPO, BattleScript_OwnTempoPrevents },
            { MOVE_EFFECT_BLOCKER_SUBSTITUTE, BattleScript_ButItFailed },
            { MOVE_EFFECT_BLOCKER_VOLATILE, BattleScript_AlreadyConfused },
            { MOVE_EFFECT_BLOCKER_TERRAIN, .terrain = STATUS_FIELD_MISTY_TERRAIN, BattleScript_MistyTerrainPrevents},
            { MOVE_EFFECT_BLOCKER_ACCURACY_PLACEHOLDER },
            { MOVE_EFFECT_BLOCKER_SAFEGUARD, BattleScript_SafeguardProtected },
            { MOVE_EFFECT_BLOCKER_END },
        },
    },
    [MOVE_EFFECT_FLINCH] =
    {
        ._volatile = VOLATILE_FLINCHED,
        .callback = MoveEffect_SetVolatileTrue,
    },
    [MOVE_EFFECT_TRI_ATTACK] =
    {
        // Not really a move effect - it calls other move effects
    },
    [MOVE_EFFECT_UPROAR] =
    {
        ._volatile = VOLATILE_UPROAR,
        .battlescript = BattleScript_MoveEffectUproar,
        .callback = MoveEffect_UproarCallback,
    },
    [MOVE_EFFECT_PAYDAY] =
    {
        .callback = MoveEffect_PaydayCallback,
        .battlescript = BattleScript_MoveEffectPayDay,
        .activateAfterFaint = TRUE,
    },
    [MOVE_EFFECT_WRAP] =
    {
        ._volatile = VOLATILE_WRAPPED,
        .battlescript = BattleScript_MoveEffectWrap,
        .callback = MoveEffect_WrapCallback,
        .finalStrikeEffect = TRUE,
    },
    [MOVE_EFFECT_ATK_PLUS_1] =
    {

    },
    [MOVE_EFFECT_DEF_PLUS_1] =
    {

    },
    [MOVE_EFFECT_SPD_PLUS_1] =
    {

    },
    [MOVE_EFFECT_SP_ATK_PLUS_1] =
    {

    },
    [MOVE_EFFECT_SP_DEF_PLUS_1] =
    {

    },
    [MOVE_EFFECT_ACC_PLUS_1] =
    {

    },
    [MOVE_EFFECT_EVS_PLUS_1] =
    {

    },
    [MOVE_EFFECT_ATK_MINUS_1] =
    {

    },
    [MOVE_EFFECT_DEF_MINUS_1] =
    {

    },
    [MOVE_EFFECT_SPD_MINUS_1] =
    {

    },
    [MOVE_EFFECT_SP_ATK_MINUS_1] =
    {

    },
    [MOVE_EFFECT_SP_DEF_MINUS_1] =
    {

    },
    [MOVE_EFFECT_ACC_MINUS_1] =
    {

    },
    [MOVE_EFFECT_EVS_MINUS_1] =
    {

    },
    [MOVE_EFFECT_REMOVE_ARG_TYPE] =
    {
        .finalStrikeEffect = TRUE,
    },
    [MOVE_EFFECT_RECHARGE] =
    {

    },
    [MOVE_EFFECT_RAGE] =
    {
        ._volatile = VOLATILE_RAGE,
        .callback = MoveEffect_SetVolatileTrue,
    },
    [MOVE_EFFECT_STEAL_ITEM] =
    {
        .battlescript = BattleScript_ItemSteal,
        .callback = MoveEffect_StealItemCallback,
        .activateAfterFaint = TRUE,
        .finalStrikeEffect = TRUE,
    },
    [MOVE_EFFECT_PREVENT_ESCAPE] =
    {
        .callback = MoveEffect_PreventEscapeCallback,
        .finalStrikeEffect = TRUE,
    },
    [MOVE_EFFECT_NIGHTMARE] =
    {

    },
    [MOVE_EFFECT_ALL_STATS_UP] =
    {

    },
    [MOVE_EFFECT_REMOVE_STATUS] =
    {
        .finalStrikeEffect = TRUE,
    },
    [MOVE_EFFECT_ATK_DEF_DOWN] =
    {

    },
    [MOVE_EFFECT_ATK_PLUS_2] =
    {

    },
    [MOVE_EFFECT_DEF_PLUS_2] =
    {

    },
    [MOVE_EFFECT_SPD_PLUS_2] =
    {

    },
    [MOVE_EFFECT_SP_ATK_PLUS_2] =
    {

    },
    [MOVE_EFFECT_SP_DEF_PLUS_2] =
    {

    },
    [MOVE_EFFECT_ACC_PLUS_2] =
    {

    },
    [MOVE_EFFECT_EVS_PLUS_2] =
    {

    },
    [MOVE_EFFECT_ATK_MINUS_2] =
    {

    },
    [MOVE_EFFECT_DEF_MINUS_2] =
    {

    },
    [MOVE_EFFECT_SPD_MINUS_2] =
    {

    },
    [MOVE_EFFECT_SP_ATK_MINUS_2] =
    {

    },
    [MOVE_EFFECT_SP_DEF_MINUS_2] =
    {

    },
    [MOVE_EFFECT_ACC_MINUS_2] =
    {

    },
    [MOVE_EFFECT_EVS_MINUS_2] =
    {

    },
    [MOVE_EFFECT_SCALE_SHOT] =
    {

    },
    [MOVE_EFFECT_THRASH] =
    {
        .callback = MoveEffect_ThrashCallback,
    },
    [MOVE_EFFECT_DEF_SPDEF_DOWN] =
    {

    },
    [MOVE_EFFECT_CLEAR_SMOG] =
    {
        .battlescript = BattleScript_MoveEffectClearSmog,
        .callback = MoveEffect_ClearSmogCallback,
    },
    [MOVE_EFFECT_FLAME_BURST] =
    {

    },
    [MOVE_EFFECT_FEINT] =
    {

    },
    [MOVE_EFFECT_V_CREATE] =
    {

    },
    [MOVE_EFFECT_HAPPY_HOUR] =
    {

    },
    [MOVE_EFFECT_CORE_ENFORCER] =
    {

    },
    [MOVE_EFFECT_THROAT_CHOP] =
    {

    },
    [MOVE_EFFECT_INCINERATE] =
    {

    },
    [MOVE_EFFECT_BUG_BITE] =
    {
        .activateAfterFaint = TRUE,
        .finalStrikeEffect = TRUE,
    },
    [MOVE_EFFECT_RECOIL_HP_25] =
    {
        .finalStrikeEffect = TRUE,
    },
    [MOVE_EFFECT_TRAP_BOTH] =
    {

    },
    [MOVE_EFFECT_ROUND] =
    {

    },
    [MOVE_EFFECT_DIRE_CLAW] =
    {

    },
    [MOVE_EFFECT_STEALTH_ROCK] =
    {
        .activateAfterFaint = TRUE,
    },
    [MOVE_EFFECT_SPIKES] =
    {
        .activateAfterFaint = TRUE,
    },
    [MOVE_EFFECT_SYRUP_BOMB] =
    {

    },
    [MOVE_EFFECT_FLORAL_HEALING] =
    {

    },
    [MOVE_EFFECT_SECRET_POWER] =
    {

    },
    [MOVE_EFFECT_PSYCHIC_NOISE] =
    {

    },
    [MOVE_EFFECT_TERA_BLAST] =
    {

    },
    [MOVE_EFFECT_ORDER_UP] =
    {

    },
    [MOVE_EFFECT_ION_DELUGE] =
    {

    },
    [MOVE_EFFECT_HAZE] =
    {

    },
    [MOVE_EFFECT_LEECH_SEED] =
    {

    },
    [MOVE_EFFECT_REFLECT] =
    {

    },
    [MOVE_EFFECT_LIGHT_SCREEN] =
    {

    },
    [MOVE_EFFECT_SALT_CURE] =
    {

    },
    [MOVE_EFFECT_EERIE_SPELL] =
    {

    },
    [MOVE_EFFECT_RAISE_TEAM_ATTACK] =
    {

    },
    [MOVE_EFFECT_RAISE_TEAM_DEFENSE] =
    {

    },
    [MOVE_EFFECT_RAISE_TEAM_SPEED] =
    {

    },
    [MOVE_EFFECT_RAISE_TEAM_SP_ATK] =
    {

    },
    [MOVE_EFFECT_RAISE_TEAM_SP_DEF] =
    {

    },
    [MOVE_EFFECT_LOWER_ATTACK_SIDE] =
    {

    },
    [MOVE_EFFECT_LOWER_DEFENSE_SIDE] =
    {

    },
    [MOVE_EFFECT_LOWER_SPEED_SIDE] =
    {

    },
    [MOVE_EFFECT_LOWER_SP_ATK_SIDE] =
    {

    },
    [MOVE_EFFECT_LOWER_SP_DEF_SIDE] =
    {

    },
    [MOVE_EFFECT_SUN] =
    {

    },
    [MOVE_EFFECT_RAIN] =
    {

    },
    [MOVE_EFFECT_SANDSTORM] =
    {

    },
    [MOVE_EFFECT_HAIL] =
    {

    },
    [MOVE_EFFECT_MISTY_TERRAIN] =
    {

    },
    [MOVE_EFFECT_GRASSY_TERRAIN] =
    {

    },
    [MOVE_EFFECT_ELECTRIC_TERRAIN] =
    {

    },
    [MOVE_EFFECT_PSYCHIC_TERRAIN] =
    {

    },
    [MOVE_EFFECT_VINE_LASH] =
    {

    },
    [MOVE_EFFECT_WILDFIRE] =
    {

    },
    [MOVE_EFFECT_CANNONADE] =
    {

    },
    [MOVE_EFFECT_EFFECT_SPORE_SIDE] =
    {

    },
    [MOVE_EFFECT_PARALYZE_SIDE] =
    {

    },
    [MOVE_EFFECT_CONFUSE_PAY_DAY_SIDE] =
    {

    },
    [MOVE_EFFECT_CRIT_PLUS_SIDE] =
    {

    },
    [MOVE_EFFECT_PREVENT_ESCAPE_SIDE] =
    {

    },
    [MOVE_EFFECT_AURORA_VEIL] =
    {

    },
    [MOVE_EFFECT_INFATUATE_SIDE] =
    {

    },
    [MOVE_EFFECT_RECYCLE_BERRIES] =
    {

    },
    [MOVE_EFFECT_POISON_SIDE] =
    {

    },
    [MOVE_EFFECT_DEFOG] =
    {

    },
    [MOVE_EFFECT_POISON_PARALYZE_SIDE] =
    {

    },
    [MOVE_EFFECT_HEAL_TEAM] =
    {

    },
    [MOVE_EFFECT_SPITE] =
    {

    },
    [MOVE_EFFECT_GRAVITY] =
    {

    },
    [MOVE_EFFECT_VOLCALITH] =
    {

    },
    [MOVE_EFFECT_SANDBLAST_SIDE] =
    {

    },
    [MOVE_EFFECT_YAWN_FOE] =
    {

    },
    [MOVE_EFFECT_LOWER_EVASIVENESS_SIDE] =
    {

    },
    [MOVE_EFFECT_AROMATHERAPY] =
    {

    },
    [MOVE_EFFECT_CONFUSE_SIDE] =
    {

    },
    [MOVE_EFFECT_STEELSURGE] =
    {

    },
    [MOVE_EFFECT_TORMENT_SIDE] =
    {

    },
    [MOVE_EFFECT_LOWER_SPEED_2_SIDE] =
    {

    },
    [MOVE_EFFECT_FIRE_SPIN_SIDE] =
    {

    },
    [MOVE_EFFECT_FIXED_POWER] =
    {

    },
};

#define IF_FAIL(...) if ((result->failed = (__VA_ARGS__)))
#define IF_SUCCEED(...) if (!(result->failed = !(__VA_ARGS__)))

void SetMoveEffect(u32 battler, u32 effectBattler, bool32 primary, bool32 certain)
{
    struct SetMoveEffectResult result = { 0 };
    const u8 *currInstr = gBattlescriptCurrInstr;
    SetMoveEffectWithResult(&result, battler, effectBattler, gBattleScripting.moveEffect, primary, certain, gBattlescriptCurrInstr + 1);

    // Assign next instruction
    SetMoveEffectHandleResult(&result, currInstr, gBattlescriptCurrInstr + 1);
}

static bool32 CheckMoveEffectBlockers(struct SetMoveEffectResult *result)
{
    u32 i;

    if (gMoveEffectsInfo[result->moveEffect].blockers != NULL)
    {
        struct MoveEffectBlocker *blocker;
        for (i = 0; i < MOVE_EFFECT_BLOCKER_END && !result->failed; i++)
        {
            switch ((blocker = &gMoveEffectsInfo[result->moveEffect].blockers[i])->blockerType)
            {
                case MOVE_EFFECT_BLOCKER_ABILITY:
                    result->failed = (result->battlerAbility == blocker->ability);
                    break;
                case MOVE_EFFECT_BLOCKER_SUBSTITUTE:
                    result->failed = (DoesSubstituteBlockMove(result->battlerAtk, result->effectBattler, result->currentMove));
                    break;
                case MOVE_EFFECT_BLOCKER_SAFEGUARD:
                    result->failed = (GetBattlerAbility(result->battlerAtk) != ABILITY_INFILTRATOR && (gSideStatuses[GetBattlerSide(result->effectBattler)] & SIDE_STATUS_SAFEGUARD));
                    break;
                case MOVE_EFFECT_BLOCKER_TERRAIN:
                    result->failed = (IsBattlerTerrainAffected(result->effectBattler, blocker->terrain));
                    break;
                case MOVE_EFFECT_BLOCKER_VOLATILE:
                    result->failed = (blocker->_volatile && GetMonVolatile(result->effectBattler, blocker->_volatile));
                case MOVE_EFFECT_BLOCKER_ACCURACY_PLACEHOLDER:
                    // To do
                    break;
                case MOVE_EFFECT_BLOCKER_END:
                    return FALSE;
                default:
                    break;
            }
        }

        // Set next instruction if one is available (some effects fail silently)
        if (result->failed && blocker->battlescript)
            result->nextInstr = blocker->battlescript;

        return result->failed;
    }

    return FALSE;
}

// To avoid confusion the arguments are naned battler/effectBattler since they can be different from gBattlerAttacker/gBattlerTarget
struct SetMoveEffectResult *SetMoveEffectWithResult(struct SetMoveEffectResult *result, u32 battler, u32 effectBattler, u16 moveEffect, bool32 primary, bool32 certain, const u8 *nextInstr)
{
    s32 i;
    bool32 affectsUser = (battler == effectBattler);
    u32 battlerAbility = GetBattlerAbility(effectBattler);
    bool32 mirrorArmorReflected = (battlerAbility == ABILITY_MIRROR_ARMOR);
    union StatChangeFlags flags = {0};

    // Get battlers
    result->battlerAtk = gBattlerAttacker;
    result->battlerDef = gBattlerTarget;

    // Set move effect and check if it exists
    IF_FAIL((result->moveEffect = gBattleScripting.moveEffect = moveEffect) == MOVE_EFFECT_NONE)
        return result;

    IF_FAIL(gSpecialStatuses[battler].parentalBondState == PARENTAL_BOND_1ST_HIT
        && IsBattlerAlive(effectBattler)
        && gMoveEffectsInfo[gBattleScripting.moveEffect].finalStrikeEffect)
    {
        result->nextInstr = nextInstr;
        return result;
    }

    // Get current ability and move
    result->scriptingBattler = gBattleScripting.battler = battler;
    result->effectBattler = gEffectBattler = effectBattler;
    result->battlerAbility = battlerAbility;
    result->currentMove = gCurrentMove;

    // Check move effect blockers
    if (CheckMoveEffectBlockers(result))
        return result;

    IF_FAIL(!primary && !affectsUser
     && !(gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
     && IsMoveEffectBlockedByTarget(battlerAbility))
        gBattleScripting.moveEffect = MOVE_EFFECT_NONE;
    else IF_FAIL(!(gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
          && TestIfSheerForceAffected(gBattlerAttacker, gCurrentMove)
          && !(GetMoveEffect(gCurrentMove) == EFFECT_ORDER_UP && gBattleStruct->commanderActive[gBattlerAttacker])
          && !primary)
        gBattleScripting.moveEffect = MOVE_EFFECT_NONE;
    else IF_FAIL(!IsBattlerAlive(gEffectBattler) && !gMoveEffectsInfo[moveEffect].activateAfterFaint)
        gBattleScripting.moveEffect = MOVE_EFFECT_NONE;
    else IF_FAIL(DoesSubstituteBlockMove(gBattlerAttacker, gEffectBattler, gCurrentMove) && !affectsUser)
        gBattleScripting.moveEffect = MOVE_EFFECT_NONE;

    switch (gBattleScripting.moveEffect)
    {
    case MOVE_EFFECT_NONE:
        result->nextInstr = nextInstr;
        break;
    case MOVE_EFFECT_SLEEP:
    case MOVE_EFFECT_POISON:
    case MOVE_EFFECT_BURN:
    case MOVE_EFFECT_FREEZE:
    case MOVE_EFFECT_PARALYSIS:
    case MOVE_EFFECT_TOXIC:
    case MOVE_EFFECT_FROSTBITE:
        IF_FAIL((gSideStatuses[GetBattlerSide(result->effectBattler)] & SIDE_STATUS_SAFEGUARD && !(gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT) && !primary))
            result->nextInstr = nextInstr;
        else {
            result->failed = !CanSetNonVolatileStatus(
                result->battlerAtk,
                result->effectBattler,
                GetBattlerAbility(result->battlerAtk),
                result->battlerAbility,
                result->moveEffect,
                STATUS_CHECK_TRIGGER);
            }
            // SetNonVolatileStatusCondition(gEffectBattler, gBattleScripting.moveEffect, TRIGGER_ON_MOVE);
        break;
    case MOVE_EFFECT_CONFUSION:
        IF_FAIL(!CanBeConfused(result->effectBattler)
         || gBattleMons[result->effectBattler].volatiles.confusionTurns > 0
         || (gSideStatuses[GetBattlerSide(result->effectBattler)] & SIDE_STATUS_SAFEGUARD && !(gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT) && !primary))
            result->nextInstr = nextInstr;
        break;
    case MOVE_EFFECT_FLINCH:
        IF_FAIL(battlerAbility == ABILITY_INNER_FOCUS)
        {
            // Inner Focus ALWAYS prevents flinching but only activates
            // on a move that's supposed to flinch, like Fake Out
            if (primary || certain)
            {
                result->blockedByAbility = TRUE;
                result->nextInstr = BattleScript_FlinchPrevention;
            }
            else
                result->nextInstr = nextInstr;
        }
        else IF_FAIL(gBattleMons[result->effectBattler].volatiles.flinched)
            result->nextInstr = nextInstr;
        else IF_SUCCEED(GetBattlerTurnOrderNum(result->effectBattler) > gCurrentTurnActionNumber
                && !(GetActiveGimmick(result->effectBattler) == GIMMICK_DYNAMAX))
            result->nextInstr = nextInstr;
        break;
    case MOVE_EFFECT_TRI_ATTACK:
        IF_FAIL(gBattleMons[result->effectBattler].status1)
            result->nextInstr = nextInstr;
        else
        {
            static const u8 sTriAttackEffects[] =
            {
                MOVE_EFFECT_BURN,
                MOVE_EFFECT_FREEZE_OR_FROSTBITE,
                MOVE_EFFECT_PARALYSIS
            };
            return SetMoveEffectWithResult(result, battler, effectBattler, RandomElement(RNG_TRI_ATTACK, sTriAttackEffects), primary, certain, nextInstr);
        }
        break;
    case MOVE_EFFECT_UPROAR:
        IF_FAIL(gBattleMons[result->effectBattler].volatiles.uproarTurns > 0)
            result->nextInstr = nextInstr;
        break;
    case MOVE_EFFECT_PAYDAY:
        // Don't scatter coins on the second hit of Parental Bond
        IF_SUCCEED(IsOnPlayerSide(result->battlerAtk) && gSpecialStatuses[result->battlerAtk].parentalBondState != PARENTAL_BOND_2ND_HIT)
        {
            // For a move that hits multiple targets (i.e. Make it Rain)
            // we only want to print the message on the final hit
            if (!(NumAffectedSpreadMoveTargets() > 1 && GetNextTarget(GetBattlerMoveTargetType(result->battlerAtk, result->currentMove), TRUE) != MAX_BATTLERS_COUNT))
                PushNextInstrAndMoveEffectInstr(result);
            else
                result->nextInstr = nextInstr;
        }
        else
            result->nextInstr = nextInstr;
        break;
    case MOVE_EFFECT_HAPPY_HOUR:
        if (IsOnPlayerSide(gBattlerAttacker) && !gBattleStruct->moneyMultiplierMove)
        {
            gBattleStruct->moneyMultiplier *= 2;
            gBattleStruct->moneyMultiplierMove = 1;
        }
        gBattlescriptCurrInstr++;
        break;
    case MOVE_EFFECT_WRAP:
        IF_FAIL(gBattleMons[result->effectBattler].volatiles.wrapped)
            result->nextInstr = nextInstr;
        break;
    case MOVE_EFFECT_ATK_PLUS_1:
    case MOVE_EFFECT_DEF_PLUS_1:
    case MOVE_EFFECT_SPD_PLUS_1:
    case MOVE_EFFECT_SP_ATK_PLUS_1:
    case MOVE_EFFECT_SP_DEF_PLUS_1:
    case MOVE_EFFECT_ACC_PLUS_1:
    case MOVE_EFFECT_EVS_PLUS_1:
        if (NoAliveMonsForEitherParty()
          || ChangeStatBuffs(
                effectBattler,
                SET_STAT_BUFF_VALUE(1),
                gBattleScripting.moveEffect - MOVE_EFFECT_ATK_PLUS_1 + 1,
                STAT_CHANGE_UPDATE_MOVE_EFFECT,
                0, 0) == STAT_CHANGE_DIDNT_WORK)
        {
            gBattlescriptCurrInstr++;
        }
        else
        {
            gBattleScripting.animArg1 = gBattleScripting.moveEffect;
            gBattleScripting.animArg2 = 0;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_StatUp;
        }
        break;
    case MOVE_EFFECT_ATK_MINUS_1:
    case MOVE_EFFECT_DEF_MINUS_1:
    case MOVE_EFFECT_SPD_MINUS_1:
    case MOVE_EFFECT_SP_ATK_MINUS_1:
    case MOVE_EFFECT_SP_DEF_MINUS_1:
    case MOVE_EFFECT_ACC_MINUS_1:
    case MOVE_EFFECT_EVS_MINUS_1:
        flags.certain = affectsUser;
        if (mirrorArmorReflected && !affectsUser)
            flags.allowPtr = TRUE;
        else
            flags.updateMoveEffect = TRUE;

        if (ChangeStatBuffs(
                effectBattler,
                SET_STAT_BUFF_VALUE(1) | STAT_BUFF_NEGATIVE,
                gBattleScripting.moveEffect - MOVE_EFFECT_ATK_MINUS_1 + 1,
                flags,
                0, gBattlescriptCurrInstr + 1) == STAT_CHANGE_DIDNT_WORK)
        {
            if (!mirrorArmorReflected)
                gBattlescriptCurrInstr++;
        }
        else
        {
            gBattleScripting.animArg1 = gBattleScripting.moveEffect;
            gBattleScripting.animArg2 = 0;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_StatDown;
        }
        break;
    case MOVE_EFFECT_ATK_PLUS_2:
    case MOVE_EFFECT_DEF_PLUS_2:
    case MOVE_EFFECT_SPD_PLUS_2:
    case MOVE_EFFECT_SP_ATK_PLUS_2:
    case MOVE_EFFECT_SP_DEF_PLUS_2:
    case MOVE_EFFECT_ACC_PLUS_2:
    case MOVE_EFFECT_EVS_PLUS_2:
        if (NoAliveMonsForEitherParty()
          || ChangeStatBuffs(
                effectBattler,
                SET_STAT_BUFF_VALUE(2),
                gBattleScripting.moveEffect - MOVE_EFFECT_ATK_PLUS_2 + 1,
                STAT_CHANGE_UPDATE_MOVE_EFFECT,
                0, 0) == STAT_CHANGE_DIDNT_WORK)
        {
            gBattlescriptCurrInstr++;
        }
        else
        {
            gBattleScripting.animArg1 = gBattleScripting.moveEffect;
            gBattleScripting.animArg2 = 0;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_StatUp;
        }
        break;
    case MOVE_EFFECT_ATK_MINUS_2:
    case MOVE_EFFECT_DEF_MINUS_2:
    case MOVE_EFFECT_SPD_MINUS_2:
    case MOVE_EFFECT_SP_ATK_MINUS_2:
    case MOVE_EFFECT_SP_DEF_MINUS_2:
    case MOVE_EFFECT_ACC_MINUS_2:
    case MOVE_EFFECT_EVS_MINUS_2:
        flags.certain = affectsUser;
        if (mirrorArmorReflected && !affectsUser)
            flags.allowPtr = TRUE;
        else
            flags.updateMoveEffect = TRUE;

        if (ChangeStatBuffs(
                effectBattler,
                SET_STAT_BUFF_VALUE(2) | STAT_BUFF_NEGATIVE,
                gBattleScripting.moveEffect - MOVE_EFFECT_ATK_MINUS_2 + 1,
                flags,
                0, gBattlescriptCurrInstr + 1) == STAT_CHANGE_DIDNT_WORK)
        {
            if (!mirrorArmorReflected)
                gBattlescriptCurrInstr++;
        }
        else
        {
            gBattleScripting.animArg1 = gBattleScripting.moveEffect;
            gBattleScripting.animArg2 = 0;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_StatDown;
        }
        break;
    case MOVE_EFFECT_RECHARGE:
        if (B_SKIP_RECHARGE == GEN_1 && !IsBattlerAlive(gBattlerTarget))  // Skip recharge if gen 1 and foe is KO'd
            break;

        gBattleMons[gEffectBattler].status2 |= STATUS2_RECHARGE;
        gDisableStructs[gEffectBattler].rechargeTimer = 2;
        gLockedMoves[gEffectBattler] = gCurrentMove;
        gBattlescriptCurrInstr++;
        break;
    case MOVE_EFFECT_RAGE:
        gBattleMons[gBattlerAttacker].status2 |= STATUS2_RAGE;
        gBattlescriptCurrInstr++;
        break;
    case MOVE_EFFECT_STEAL_ITEM:
        if (!CanStealItem(gBattlerAttacker, gBattlerTarget, gBattleMons[gBattlerTarget].item)
            || gBattleMons[gBattlerAttacker].item != ITEM_NONE
            || gBattleMons[gBattlerTarget].item == ITEM_NONE)
        {
            gBattlescriptCurrInstr++;
        }
        else if (GetBattlerAbility(gBattlerTarget) == ABILITY_STICKY_HOLD)
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_NoItemSteal;

            gLastUsedAbility = gBattleMons[gBattlerTarget].ability;
            RecordAbilityBattle(gBattlerTarget, gLastUsedAbility);
        }
        else
        {
            StealTargetItem(gBattlerAttacker, gBattlerTarget);  // Attacker steals target item

            if (!(B_STEAL_WILD_ITEMS >= GEN_9
             && !(gBattleTypeFlags & (BATTLE_TYPE_TRAINER | BATTLE_TYPE_PALACE))))
            {
                gBattleMons[gBattlerAttacker].item = ITEM_NONE; // Item assigned later on with thief (see MOVEEND_CHANGED_ITEMS)
                gBattleStruct->changedItems[gBattlerAttacker] = gLastUsedItem; // Stolen item to be assigned later
            }
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_ItemSteal;
        }
        break;
    case MOVE_EFFECT_PREVENT_ESCAPE:
        if (!(gBattleMons[gBattlerTarget].status2 & STATUS2_ESCAPE_PREVENTION))
        {
            gBattleMons[gBattlerTarget].status2 |= STATUS2_ESCAPE_PREVENTION;
            gDisableStructs[gBattlerTarget].battlerPreventingEscape = gBattlerAttacker;
        }
        gBattlescriptCurrInstr++;
        break;
    case MOVE_EFFECT_NIGHTMARE:
        gBattleMons[gBattlerTarget].status2 |= STATUS2_NIGHTMARE;
        gBattlescriptCurrInstr++;
        break;
    case MOVE_EFFECT_ALL_STATS_UP:
        if (!NoAliveMonsForEitherParty())
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_AllStatsUp;
        }
        break;
    case MOVE_EFFECT_ATK_DEF_DOWN: // SuperPower
        if (!NoAliveMonsForEitherParty())
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_AtkDefDown;
        }
        break;
    case MOVE_EFFECT_DEF_SPDEF_DOWN: // Close Combat
        if (!NoAliveMonsForEitherParty())
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_DefSpDefDown;
        }
        break;
    case MOVE_EFFECT_RECOIL_HP_25: // Struggle
        gBattleStruct->moveDamage[gEffectBattler] = (gBattleMons[gEffectBattler].maxHP) / 4;
        if (gBattleStruct->moveDamage[gEffectBattler] == 0)
            gBattleStruct->moveDamage[gEffectBattler] = 1;
        if (GetBattlerAbility(gEffectBattler) == ABILITY_PARENTAL_BOND)
            gBattleStruct->moveDamage[gEffectBattler] *= 2;

        BattleScriptPush(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = BattleScript_MoveEffectRecoil;
        break;
    case MOVE_EFFECT_THRASH:
        // Petal Dance doesn't lock mons that copy the move with Dancer
        if (gSpecialStatuses[gEffectBattler].dancerUsedMove || gBattleMons[gEffectBattler].status2 & STATUS2_LOCK_CONFUSE)
        {
            gBattlescriptCurrInstr++;
        }
        else
        {
            gBattleMons[gEffectBattler].status2 |= STATUS2_MULTIPLETURNS;
            gLockedMoves[gEffectBattler] = gCurrentMove;
            gBattleMons[gEffectBattler].status2 |= STATUS2_LOCK_CONFUSE_TURN(RandomUniform(RNG_RAMPAGE_TURNS, 2, 3));
        }
        break;
    case MOVE_EFFECT_CLEAR_SMOG:
        for (i = 0; i < NUM_BATTLE_STATS; i++)
        {
            if (gBattleMons[gEffectBattler].statStages[i] != DEFAULT_STAT_STAGE)
                break;
        }
        if ((gSpecialStatuses[gEffectBattler].physicalDmg || gSpecialStatuses[gEffectBattler].specialDmg) && i != NUM_BATTLE_STATS)
        {
            for (i = 0; i < NUM_BATTLE_STATS; i++)
                gBattleMons[gEffectBattler].statStages[i] = DEFAULT_STAT_STAGE;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_MoveEffectClearSmog;
        }
        break;
    case MOVE_EFFECT_FLAME_BURST:
        if (IsBattlerAlive(BATTLE_PARTNER(gBattlerTarget))
         && !(gStatuses3[BATTLE_PARTNER(gBattlerTarget)] & STATUS3_SEMI_INVULNERABLE)
         && GetBattlerAbility(BATTLE_PARTNER(gBattlerTarget)) != ABILITY_MAGIC_GUARD)
        {
            i = BATTLE_PARTNER(gBattlerTarget);
            gBattleScripting.savedBattler = i;
            gBattleStruct->moveDamage[i] = gBattleMons[i].maxHP / 16;
            if (gBattleStruct->moveDamage[i] == 0)
                gBattleStruct->moveDamage[i] = 1;
            gBattlescriptCurrInstr = BattleScript_MoveEffectFlameBurst;
        }
        break;
    case MOVE_EFFECT_FEINT:
        i = FALSE; // Remove Protect if any
        if (gProtectStructs[gBattlerTarget].protected != PROTECT_NONE
         && gProtectStructs[gBattlerTarget].protected != PROTECT_MAX_GUARD)
        {
            gProtectStructs[gBattlerTarget].protected = PROTECT_NONE;
            i = TRUE;
        }
        if (GetProtectType(gProtectStructs[BATTLE_PARTNER(gBattlerTarget)].protected) == PROTECT_TYPE_SIDE)
        {
            gProtectStructs[BATTLE_PARTNER(gBattlerTarget)].protected = PROTECT_NONE;
            i = TRUE;
        }
        if (i)
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            if (gCurrentMove == MOVE_HYPERSPACE_FURY)
                gBattlescriptCurrInstr = BattleScript_HyperspaceFuryRemoveProtect;
            else
                gBattlescriptCurrInstr = BattleScript_MoveEffectFeint;
        }
        break;
    case MOVE_EFFECT_V_CREATE:
        if (!NoAliveMonsForEitherParty())
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_VCreateStatLoss;
        }
        break;
    case MOVE_EFFECT_CORE_ENFORCER:
        if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget)
         && !NoAliveMonsForEitherParty())
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_MoveEffectCoreEnforcer;
        }
        break;
    case MOVE_EFFECT_THROAT_CHOP:
        gDisableStructs[gEffectBattler].throatChopTimer = gBattleTurnCounter + 2;
        gBattlescriptCurrInstr++;
        break;
    case MOVE_EFFECT_INCINERATE:
        if ((gBattleMons[gEffectBattler].item >= FIRST_BERRY_INDEX && gBattleMons[gEffectBattler].item <= LAST_BERRY_INDEX)
         || (B_INCINERATE_GEMS >= GEN_6 && GetBattlerHoldEffect(gEffectBattler, FALSE) == HOLD_EFFECT_GEMS))
        {
            gLastUsedItem = gBattleMons[gEffectBattler].item;
            gBattleMons[gEffectBattler].item = 0;
            CheckSetUnburden(gEffectBattler);

            BtlController_EmitSetMonData(gEffectBattler, B_COMM_TO_CONTROLLER, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gEffectBattler].item), &gBattleMons[gEffectBattler].item);
            MarkBattlerForControllerExec(gEffectBattler);
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_MoveEffectIncinerate;
        }
        break;
    case MOVE_EFFECT_BUG_BITE:
        if (GetItemPocket(gBattleMons[gEffectBattler].item) == POCKET_BERRIES
            && battlerAbility != ABILITY_STICKY_HOLD)
        {
            // target loses their berry
            gLastUsedItem = gBattleMons[gEffectBattler].item;
            gBattleMons[gEffectBattler].item = 0;
            CheckSetUnburden(gEffectBattler);

            BtlController_EmitSetMonData(gEffectBattler, B_COMM_TO_CONTROLLER, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gEffectBattler].item), &gBattleMons[gEffectBattler].item);
            MarkBattlerForControllerExec(gEffectBattler);
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_MoveEffectBugBite;
        }
        break;
    case MOVE_EFFECT_TRAP_BOTH:
        if (!(gBattleMons[gBattlerTarget].status2 & STATUS2_ESCAPE_PREVENTION) && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_ESCAPE_PREVENTION))
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_BothCanNoLongerEscape;
        }
        if (!(gBattleMons[gBattlerTarget].status2 & STATUS2_ESCAPE_PREVENTION))
            gDisableStructs[gBattlerTarget].battlerPreventingEscape = gBattlerAttacker;

        if (!(gBattleMons[gBattlerAttacker].status2 & STATUS2_ESCAPE_PREVENTION))
            gDisableStructs[gBattlerAttacker].battlerPreventingEscape = gBattlerTarget;

        gBattleMons[gBattlerTarget].status2 |= STATUS2_ESCAPE_PREVENTION;
        gBattleMons[gBattlerAttacker].status2 |= STATUS2_ESCAPE_PREVENTION;
        break;
    case MOVE_EFFECT_REMOVE_ARG_TYPE:
    {
        u32 type = GetMoveArgType(gCurrentMove);
        // This seems unnecessary but is done to make it work properly with Parental Bond
        BattleScriptPush(gBattlescriptCurrInstr + 1);
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
        RemoveBattlerType(gEffectBattler, type);
        break;
    }
    case MOVE_EFFECT_ROUND:
        TryUpdateRoundTurnOrder(); // If another Pokémon uses Round before the user this turn, the user will use Round directly after it
        gBattlescriptCurrInstr++;
        break;
    case MOVE_EFFECT_DIRE_CLAW:
        if (!gBattleMons[gEffectBattler].status1)
        {
            static const u8 sDireClawEffects[] = { MOVE_EFFECT_POISON, MOVE_EFFECT_PARALYSIS, MOVE_EFFECT_SLEEP };
            gBattleScripting.moveEffect = RandomElement(RNG_DIRE_CLAW, sDireClawEffects);
            SetMoveEffect(battler, effectBattler, primary, certain);
        }
        break;
    case MOVE_EFFECT_STEALTH_ROCK:
        if (!(gSideStatuses[GetBattlerSide(gEffectBattler)] & SIDE_STATUS_STEALTH_ROCK))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_POINTEDSTONESFLOAT;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_StealthRockActivates;
        }
        break;
    case MOVE_EFFECT_SPIKES:
        if (gSideTimers[GetBattlerSide(gEffectBattler)].spikesAmount < 3)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SPIKESSCATTERED;
            BattleScriptPush(gBattlescriptCurrInstr + 1);

            if (gBattleStruct->isSkyBattle)
                gBattlescriptCurrInstr++;
            else
                gBattlescriptCurrInstr = BattleScript_SpikesActivates;
        }
        break;
    case MOVE_EFFECT_SYRUP_BOMB:
        if (!(gStatuses4[gEffectBattler] & STATUS4_SYRUP_BOMB))
        {
            struct Pokemon *mon = GetBattlerMon(gBattlerAttacker);

            gStatuses4[gEffectBattler] |= STATUS4_SYRUP_BOMB;
            gDisableStructs[gEffectBattler].syrupBombTimer = 3;
            gDisableStructs[gEffectBattler].syrupBombIsShiny = IsMonShiny(mon);
            gBattleStruct->stickySyrupdBy[gEffectBattler] = gBattlerAttacker;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_SyrupBombActivates;
        }
        break;
    case MOVE_EFFECT_SECRET_POWER:
        if (gFieldStatuses & STATUS_FIELD_TERRAIN_ANY)
        {
            switch (gFieldStatuses & STATUS_FIELD_TERRAIN_ANY)
            {
            case STATUS_FIELD_MISTY_TERRAIN:
                gBattleScripting.moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1;
                break;
            case STATUS_FIELD_GRASSY_TERRAIN:
                gBattleScripting.moveEffect = MOVE_EFFECT_SLEEP;
                break;
            case STATUS_FIELD_ELECTRIC_TERRAIN:
                gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
                break;
            case STATUS_FIELD_PSYCHIC_TERRAIN:
                gBattleScripting.moveEffect = MOVE_EFFECT_SPD_MINUS_1;
                break;
            default:
                gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
                break;
            }
        }
        else
        {
            switch (gBattleEnvironment)
            {
            case BATTLE_ENVIRONMENT_GRASS:
                gBattleScripting.moveEffect = (B_SECRET_POWER_EFFECT >= GEN_4 ? MOVE_EFFECT_SLEEP : MOVE_EFFECT_POISON);
                break;
            case BATTLE_ENVIRONMENT_UNDERWATER:
                gBattleScripting.moveEffect = (B_SECRET_POWER_EFFECT >= GEN_6 ? MOVE_EFFECT_ATK_MINUS_1 : MOVE_EFFECT_DEF_MINUS_1);
                break;
            case BATTLE_ENVIRONMENT_POND:
                gBattleScripting.moveEffect = (B_SECRET_POWER_EFFECT >= GEN_4 ? MOVE_EFFECT_ATK_MINUS_1 : MOVE_EFFECT_SPD_MINUS_1);
                break;
            case BATTLE_ENVIRONMENT_MOUNTAIN:
                if (B_SECRET_POWER_EFFECT >= GEN_5)
                    gBattleScripting.moveEffect = MOVE_EFFECT_ACC_MINUS_1;
                else if (B_SECRET_POWER_EFFECT >= GEN_4)
                    gBattleScripting.moveEffect = MOVE_EFFECT_FLINCH;
                else
                    gBattleScripting.moveEffect = MOVE_EFFECT_CONFUSION;
                break;
            case BATTLE_ENVIRONMENT_PUDDLE:
                gBattleScripting.moveEffect = (B_SECRET_POWER_EFFECT >= GEN_5 ? MOVE_EFFECT_SPD_MINUS_1 : MOVE_EFFECT_ACC_MINUS_1);
                break;
            case BATTLE_ENVIRONMENT_LONG_GRASS:
                gBattleScripting.moveEffect = MOVE_EFFECT_SLEEP;
                break;
            case BATTLE_ENVIRONMENT_SAND:
                gBattleScripting.moveEffect = MOVE_EFFECT_ACC_MINUS_1;
                break;
            case BATTLE_ENVIRONMENT_WATER:
                gBattleScripting.moveEffect = MOVE_EFFECT_ATK_MINUS_1;
                break;
            case BATTLE_ENVIRONMENT_CAVE:
            case BATTLE_ENVIRONMENT_BURIAL_GROUND:
            case BATTLE_ENVIRONMENT_SPACE:
                gBattleScripting.moveEffect = MOVE_EFFECT_FLINCH;
                break;
            case BATTLE_ENVIRONMENT_SOARING:
            case BATTLE_ENVIRONMENT_SKY_PILLAR:
            case BATTLE_ENVIRONMENT_MARSH:
            case BATTLE_ENVIRONMENT_SWAMP:
                gBattleScripting.moveEffect = MOVE_EFFECT_SPD_MINUS_1;
                break;
            case BATTLE_ENVIRONMENT_SNOW:
            case BATTLE_ENVIRONMENT_ICE:
                gBattleScripting.moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE;
                break;
            case BATTLE_ENVIRONMENT_VOLCANO:
                gBattleScripting.moveEffect = MOVE_EFFECT_BURN;
                break;
            case BATTLE_ENVIRONMENT_ULTRA_SPACE:
                gBattleScripting.moveEffect = MOVE_EFFECT_DEF_MINUS_1;
                break;
            default:
                gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
                break;
            }
        }
        SetMoveEffect(battler, effectBattler, primary, certain);
        break;
    case MOVE_EFFECT_PSYCHIC_NOISE:
        battlerAbility = IsAbilityOnSide(gEffectBattler, ABILITY_AROMA_VEIL);

        if (battlerAbility)
        {
            gBattlerAbility = battlerAbility - 1;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_AromaVeilProtectsRet;
        }
        else if (!(gStatuses3[gEffectBattler] & STATUS3_HEAL_BLOCK))
        {
            gStatuses3[gEffectBattler] |= STATUS3_HEAL_BLOCK;
            gDisableStructs[gEffectBattler].healBlockTimer = gBattleTurnCounter + 2;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectPsychicNoise;
        }
        break;
    case MOVE_EFFECT_TERA_BLAST:
        if (GetActiveGimmick(gEffectBattler) == GIMMICK_TERA
            && GetBattlerTeraType(gEffectBattler) == TYPE_STELLAR
            && !NoAliveMonsForEitherParty())
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_LowerAtkSpAtk;
        }
        break;
    case MOVE_EFFECT_ORDER_UP:
        {
            u32 stat = 0;
            bool32 commanderAffected = TRUE;
            switch (gBattleStruct->commanderActive[gEffectBattler])
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
            if (!commanderAffected
             || NoAliveMonsForEitherParty()
             || ChangeStatBuffs(
                    effectBattler,
                    SET_STAT_BUFF_VALUE(1),
                    stat,
                    STAT_CHANGE_UPDATE_MOVE_EFFECT,
                    0,
                    0) == STAT_CHANGE_DIDNT_WORK)
            {
                gBattlescriptCurrInstr++;
            }
            else
            {
                gBattleScripting.animArg1 = gBattleScripting.moveEffect;
                gBattleScripting.animArg2 = 0;
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_StatUp;
            }
        }
        break;
    case MOVE_EFFECT_ION_DELUGE:
        if (!(gFieldStatuses & STATUS_FIELD_ION_DELUGE))
        {
            gFieldStatuses |= STATUS_FIELD_ION_DELUGE;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_MoveEffectIonDeluge;
        }
        break;
    case MOVE_EFFECT_HAZE:
        for (i = 0; i < gBattlersCount; i++)
            TryResetBattlerStatChanges(i);
        BattleScriptPush(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = BattleScript_MoveEffectHaze;
        break;
    case MOVE_EFFECT_LEECH_SEED:
        if (!IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_GRASS) && !(gStatuses3[gBattlerTarget] & STATUS3_LEECHSEED))
        {
            gStatuses3[gBattlerTarget] |= gBattlerAttacker;
            gStatuses3[gBattlerTarget] |= STATUS3_LEECHSEED;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_MoveEffectLeechSeed;
        }
        break;
    case MOVE_EFFECT_REFLECT:
        if (TrySetReflect(gBattlerAttacker))
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_MoveEffectReflect;
        }
        break;
    case MOVE_EFFECT_LIGHT_SCREEN:
        if (TrySetLightScreen(gBattlerAttacker))
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_MoveEffectLightScreen;
        }
        break;
    case MOVE_EFFECT_SALT_CURE:
        if (!(gStatuses4[gBattlerTarget] & STATUS4_SALT_CURE))
        {
            gStatuses4[gBattlerTarget] |= STATUS4_SALT_CURE;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_MoveEffectSaltCure;
        }
        break;
    case MOVE_EFFECT_EERIE_SPELL:
        if (gLastMoves[gBattlerTarget] != MOVE_NONE && gLastMoves[gBattlerTarget] != 0xFFFF)
        {
            u32 i;

            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (gLastMoves[gBattlerTarget] == gBattleMons[gBattlerTarget].moves[i])
                    break;
            }

            if (i != MAX_MON_MOVES && gBattleMons[gBattlerTarget].pp[i] != 0)
            {
                u32 ppToDeduct = 3;

                if (gBattleMons[gBattlerTarget].pp[i] < ppToDeduct)
                    ppToDeduct = gBattleMons[gBattlerTarget].pp[i];

                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gLastMoves[gBattlerTarget])
                ConvertIntToDecimalStringN(gBattleTextBuff2, ppToDeduct, STR_CONV_MODE_LEFT_ALIGN, 1);
                PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff2, 1, ppToDeduct)
                gBattleMons[gBattlerTarget].pp[i] -= ppToDeduct;
                if (!(gDisableStructs[gBattlerTarget].mimickedMoves & (1u << i))
                    && !(gBattleMons[gBattlerTarget].status2 & STATUS2_TRANSFORMED))
                {
                    BtlController_EmitSetMonData(gBattlerTarget, B_COMM_TO_CONTROLLER, REQUEST_PPMOVE1_BATTLE + i, 0, sizeof(gBattleMons[gBattlerTarget].pp[i]), &gBattleMons[gBattlerTarget].pp[i]);
                    MarkBattlerForControllerExec(gBattlerTarget);
                }

                if (gBattleMons[gBattlerTarget].pp[i] == 0 && gBattleStruct->skyDropTargets[gBattlerTarget] == SKY_DROP_NO_TARGET)
                    CancelMultiTurnMoves(gBattlerTarget, SKY_DROP_IGNORE);

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_MoveEffectEerieSpell;
            }
        }
        break;
    case MOVE_EFFECT_RAISE_TEAM_ATTACK:
        if (!NoAliveMonsForEitherParty())
        {
            // Max Effects are ordered by stat ID.
            SET_STATCHANGER(STAT_ATK, 1, FALSE);
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectRaiseStatAllies;
        }
        break;
    case MOVE_EFFECT_RAISE_TEAM_DEFENSE:
        if (!NoAliveMonsForEitherParty())
        {
            // Max Effects are ordered by stat ID.
            SET_STATCHANGER(STAT_DEF, 1, FALSE);
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectRaiseStatAllies;
        }
        break;
    case MOVE_EFFECT_RAISE_TEAM_SPEED:
        if (!NoAliveMonsForEitherParty())
        {
            // Max Effects are ordered by stat ID.
            SET_STATCHANGER(STAT_SPEED, 1, FALSE);
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectRaiseStatAllies;
        }
        break;
    case MOVE_EFFECT_RAISE_TEAM_SP_ATK:
        if (!NoAliveMonsForEitherParty())
        {
            // Max Effects are ordered by stat ID.
            SET_STATCHANGER(STAT_SPATK, 1, FALSE);
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectRaiseStatAllies;
        }
        break;
    case MOVE_EFFECT_RAISE_TEAM_SP_DEF:
        if (!NoAliveMonsForEitherParty())
        {
            // Max Effects are ordered by stat ID.
            SET_STATCHANGER(STAT_SPDEF, 1, FALSE);
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectRaiseStatAllies;
        }
        break;
    case MOVE_EFFECT_LOWER_ATTACK_SIDE:
    case MOVE_EFFECT_LOWER_DEFENSE_SIDE:
    case MOVE_EFFECT_LOWER_SPEED_SIDE:
    case MOVE_EFFECT_LOWER_SP_ATK_SIDE:
    case MOVE_EFFECT_LOWER_SP_DEF_SIDE:
    case MOVE_EFFECT_LOWER_SPEED_2_SIDE:
    case MOVE_EFFECT_LOWER_EVASIVENESS_SIDE:
        if (!NoAliveMonsForEitherParty())
        {
            u32 statId = 0;
            u32 stage = 1;
            switch (gBattleScripting.moveEffect)
            {
                case MOVE_EFFECT_LOWER_SPEED_2_SIDE:
                    statId = STAT_SPEED;
                    stage = 2;
                    break;
                case MOVE_EFFECT_LOWER_EVASIVENESS_SIDE:
                    statId = STAT_EVASION;
                    break;
                default:
                    // Max Effects are ordered by stat ID.
                    statId = gBattleScripting.moveEffect - MOVE_EFFECT_LOWER_ATTACK_SIDE + 1;
                    break;
            }
            SET_STATCHANGER(statId, stage, TRUE);
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectLowerStatFoes;
        }
        break;
    case MOVE_EFFECT_SUN:
    case MOVE_EFFECT_RAIN:
    case MOVE_EFFECT_SANDSTORM:
    case MOVE_EFFECT_HAIL:
    {
        u8 weather = 0, msg = 0;
        switch (gBattleScripting.moveEffect)
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
        }
        if (TryChangeBattleWeather(gBattlerAttacker, weather, FALSE))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = msg;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectSetWeather;
        }
        break;
    }
    case MOVE_EFFECT_MISTY_TERRAIN:
    case MOVE_EFFECT_GRASSY_TERRAIN:
    case MOVE_EFFECT_ELECTRIC_TERRAIN:
    case MOVE_EFFECT_PSYCHIC_TERRAIN:
    {
        u32 statusFlag = 0;
        switch (gBattleScripting.moveEffect)
        {
            case MOVE_EFFECT_MISTY_TERRAIN:
                statusFlag = STATUS_FIELD_MISTY_TERRAIN;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_MISTY;
                break;
            case MOVE_EFFECT_GRASSY_TERRAIN:
                statusFlag = STATUS_FIELD_GRASSY_TERRAIN;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_GRASSY;
                break;
            case MOVE_EFFECT_ELECTRIC_TERRAIN:
                statusFlag = STATUS_FIELD_ELECTRIC_TERRAIN;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_ELECTRIC;
                break;
            case MOVE_EFFECT_PSYCHIC_TERRAIN:
                statusFlag = STATUS_FIELD_PSYCHIC_TERRAIN;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_PSYCHIC;
                break;
        }
        if (!(gFieldStatuses & statusFlag) && statusFlag != 0)
        {
            gFieldStatuses &= ~STATUS_FIELD_TERRAIN_ANY;
            gFieldStatuses |= statusFlag;
            if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_TERRAIN_EXTENDER)
                gFieldTimers.terrainTimer = gBattleTurnCounter + 8;
            else
                gFieldTimers.terrainTimer = gBattleTurnCounter + 5;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectSetTerrain;
        }
        break;
    }
    case MOVE_EFFECT_VINE_LASH:
    case MOVE_EFFECT_CANNONADE:
    case MOVE_EFFECT_WILDFIRE:
    case MOVE_EFFECT_VOLCALITH:
    {
        u8 side = GetBattlerSide(gBattlerTarget);
        if (!(gSideStatuses[side] & SIDE_STATUS_DAMAGE_NON_TYPES))
        {
            u32 moveType = GetMoveType(gCurrentMove);
            gSideStatuses[side] |= SIDE_STATUS_DAMAGE_NON_TYPES;
            gSideTimers[side].damageNonTypesTimer = gBattleTurnCounter + 5; // damage is dealt for 4 turns, ends on 5th
            gSideTimers[side].damageNonTypesType = moveType;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            ChooseDamageNonTypesString(moveType);
            gBattlescriptCurrInstr = BattleScript_DamageNonTypesStarts;
        }
        break;
    }
    case MOVE_EFFECT_STEELSURGE:
        if (!(gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_STEELSURGE))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SHARPSTEELFLOATS;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectSteelsurge;
        }
        break;
    case MOVE_EFFECT_DEFOG:
        if (gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_SCREEN_ANY
            || gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_HAZARDS_ANY
            || gSideStatuses[GetBattlerSide(gBattlerAttacker)] & SIDE_STATUS_HAZARDS_ANY
            || gFieldStatuses & STATUS_FIELD_TERRAIN_ANY)
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_DefogTryHazards;
        }
        break;
    case MOVE_EFFECT_AURORA_VEIL:
        if (!(gSideStatuses[GetBattlerSide(gBattlerAttacker)] & SIDE_STATUS_AURORA_VEIL))
        {
            gSideStatuses[GetBattlerSide(gBattlerAttacker)] |= SIDE_STATUS_AURORA_VEIL;
            if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_LIGHT_CLAY)
                gSideTimers[GetBattlerSide(gBattlerAttacker)].auroraVeilTimer = gBattleTurnCounter + 8;
            else
                gSideTimers[GetBattlerSide(gBattlerAttacker)].auroraVeilTimer = gBattleTurnCounter + 5;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SET_SAFEGUARD;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectAuroraVeilSuccess;
        }
        break;
    case MOVE_EFFECT_GRAVITY:
        if (!(gFieldStatuses & STATUS_FIELD_GRAVITY))
        {
            gFieldStatuses |= STATUS_FIELD_GRAVITY;
            gFieldTimers.gravityTimer = gBattleTurnCounter + 5;
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectGravitySuccess;
        }
        break;
    case MOVE_EFFECT_SANDBLAST_SIDE:
    case MOVE_EFFECT_FIRE_SPIN_SIDE:
    {
        // Affects both opponents, but doesn't print strings so we can handle it here.
        u8 battler;
        for (battler = 0; battler < MAX_BATTLERS_COUNT; ++battler)
        {
            if (!IsBattlerAlly(battler, gBattlerTarget))
                continue;
            if (!(gBattleMons[battler].status2 & STATUS2_WRAPPED))
            {
                gBattleMons[battler].status2 |= STATUS2_WRAPPED;
                if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_GRIP_CLAW)
                    gDisableStructs[battler].wrapTurns = (B_BINDING_TURNS >= GEN_5) ? 7 : 5;
                else
                    gDisableStructs[battler].wrapTurns = (Random() % 2) + 4;
                // The Wrap effect does not expire when the user switches, so here's some cheese.
                gBattleStruct->wrappedBy[battler] = gBattlerTarget;
                if (gBattleScripting.moveEffect == MOVE_EFFECT_SANDBLAST_SIDE)
                    gBattleStruct->wrappedMove[battler] = MOVE_SAND_TOMB;
                else
                    gBattleStruct->wrappedMove[battler] = MOVE_FIRE_SPIN;
            }
        }
        break;
    }
    case MOVE_EFFECT_YAWN_FOE:
    {
        if (!(gStatuses3[gBattlerTarget] & STATUS3_YAWN)
            && CanBeSlept(gBattlerTarget, gBattlerTarget, GetBattlerAbility(gBattlerTarget), BLOCKED_BY_SLEEP_CLAUSE)
            && RandomPercentage(RNG_G_MAX_SNOOZE, 50))
        {
            gStatuses3[gBattlerTarget] |= STATUS3_YAWN_TURN(2);
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectYawnSuccess;
        }
        break;
    }
    case MOVE_EFFECT_SPITE:
        if (gLastMoves[gBattlerTarget] != MOVE_NONE
            && gLastMoves[gBattlerTarget] != MOVE_UNAVAILABLE)
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectTryReducePP;
        }
        break;
    case MOVE_EFFECT_PARALYZE_SIDE:
        BattleScriptPush(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = BattleScript_EffectParalyzeSide;
        break;
    case MOVE_EFFECT_POISON_SIDE:
        BattleScriptPush(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = BattleScript_EffectPoisonSide;
        break;
    case MOVE_EFFECT_POISON_PARALYZE_SIDE:
        BattleScriptPush(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = BattleScript_EffectPoisonParalyzeSide;
        break;
    case MOVE_EFFECT_EFFECT_SPORE_SIDE:
        BattleScriptPush(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = BattleScript_EffectEffectSporeSide;
        break;
    case MOVE_EFFECT_CONFUSE_PAY_DAY_SIDE:
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            u32 payday = gPaydayMoney;
            gPaydayMoney += (gBattleMons[gBattlerAttacker].level * 100);
            if (payday > gPaydayMoney)
                gPaydayMoney = 0xFFFF;
            gBattleCommunication[CURSOR_POSITION] = 1; // add "Coins scattered." message
        }
        // fall through
    case MOVE_EFFECT_CONFUSE_SIDE:
        BattleScriptPush(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = BattleScript_EffectConfuseSide;
        break;
    case MOVE_EFFECT_INFATUATE_SIDE:
        BattleScriptPush(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = BattleScript_EffectInfatuateSide;
        break;
    case MOVE_EFFECT_TORMENT_SIDE:
        BattleScriptPush(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = BattleScript_EffectTormentSide;
        break;
    case MOVE_EFFECT_PREVENT_ESCAPE_SIDE:
        BattleScriptPush(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = BattleScript_EffectMeanLookSide;
        break;
    case MOVE_EFFECT_CRIT_PLUS_SIDE:
        gBattleStruct->bonusCritStages[gBattlerAttacker]++;
        gBattleStruct->bonusCritStages[BATTLE_PARTNER(gBattlerAttacker)]++;
        BattleScriptPush(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = BattleScript_EffectRaiseCritAlliesAnim;
        break;
    case MOVE_EFFECT_HEAL_TEAM:
        BattleScriptPush(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = BattleScript_EffectHealOneSixthAllies;
        break;
    case MOVE_EFFECT_AROMATHERAPY:
        BattleScriptPush(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = BattleScript_EffectHealBell_FromHeal;
        break;
    case MOVE_EFFECT_RECYCLE_BERRIES:
    {
        if (RandomPercentage(RNG_G_MAX_REPLENISH, 50))
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_EffectRecycleBerriesAllies;
        }
        break;
    }
    case MOVE_EFFECT_REMOVE_STATUS:
    {
        u32 argStatus = GetMoveEffectArg_Status(gCurrentMove);
        if ((gBattleMons[gEffectBattler].status1 & argStatus)
         && (NumAffectedSpreadMoveTargets() > 1 || !IsMoveEffectBlockedByTarget(GetBattlerAbility(gEffectBattler))))
        {
            gBattleMons[gEffectBattler].status1 &= ~(argStatus);
            BtlController_EmitSetMonData(gEffectBattler, 0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gEffectBattler].status1);
            MarkBattlerForControllerExec(gEffectBattler);
            BattleScriptPush(gBattlescriptCurrInstr + 1);

            switch (argStatus)
            {
            case STATUS1_PARALYSIS:
                gBattlescriptCurrInstr = BattleScript_TargetPRLZHeal;
                break;
            case STATUS1_SLEEP:
                TryDeactivateSleepClause(GetBattlerSide(gEffectBattler), gBattlerPartyIndexes[gBattlerTarget]);
                gBattlescriptCurrInstr = BattleScript_TargetWokeUp;
                break;
            case STATUS1_BURN:
                gBattlescriptCurrInstr = BattleScript_TargetBurnHeal;
                break;
            case STATUS1_FREEZE:
                gBattlescriptCurrInstr = BattleScript_DefrostedViaFireMove;
                break;
            case STATUS1_FROSTBITE:
                gBattlescriptCurrInstr = BattleScript_FrostbiteHealedViaFireMove;
                break;
            case STATUS1_POISON:
            case STATUS1_TOXIC_POISON:
            case STATUS1_PSN_ANY:
                gBattlescriptCurrInstr = BattleScript_TargetPoisonHealed;
                break;
            }
        }
        break;
    }
    }

    gBattleScripting.moveEffect = 0;
    return result;
}

#undef IF_FAIL
#undef IF_SUCCEED
