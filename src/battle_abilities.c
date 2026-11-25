#include "global.h"
#include "battle.h"
#include "battle_abilities.h"
#include "battle_arena.h"
#include "battle_environment.h"
#include "battle_hold_effects.h"
#include "battle_ai_record.h"
#include "battle_util.h"
#include "battle_move_resolution.h"
#include "battle_script_commands.h"
#include "battle_stat_change.h"
#include "battle_scripts.h"
#include "battle_z_move.h"
#include "battle_anim_scripts.h"
#include "item.h"
#include "battle_controllers.h"
#include "move.h"
#include "test_runner.h"
#include "overworld.h"
#include "malloc.h"
#include "constants/weather.h"

static bool32 IsOpposingSideEmpty(enum BattlerId battler);
static bool32 IsRestrictedAbility(enum BattlerId battler, enum Ability ability);
static bool32 TryRemoveScreens(enum BattlerId battler);
static void ForewarnChooseMove(enum BattlerId battler);
static bool32 TryChangeWeatherWithAbility(enum BattlerId battler, u32 battleWeather, enum Ability ability);
u32 NumFaintedBattlersByAttacker(enum BattlerId battlerAtk);
static bool32 CantPickupItem(u32 _battler);
static bool32 PickupHasValidTarget(enum BattlerId battler);

static bool32 TryEndturnAbility(struct BattleCalcValues *cv)
{
    enum BattlerId battler = gBattlerAbility = cv->battlerAtk;
    enum Ability ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];

    switch (ability)
    {
    case ABILITY_PICKUP:
        if (gBattleMons[battler].item == ITEM_NONE && PickupHasValidTarget(battler))
        {
            gBattlerTarget = RandomUniformExcept(RNG_PICKUP, 0, gBattlersCount - 1, CantPickupItem);
            gLastUsedItem = GetBattlerPartyState(gBattlerTarget)->usedHeldItem;
            BattleScriptCall(BattleScript_PickupActivates);
            return TRUE;
        }
        break;
    case ABILITY_HARVEST:
        if ((IsBattlerWeatherAffected(cv->holdEffects[battler], GetWeather(), B_WEATHER_SUN) || RandomPercentage(RNG_HARVEST, 50))
         && gBattleMons[battler].item == ITEM_NONE
         && GetItemPocket(GetBattlerPartyState(battler)->usedHeldItem) == POCKET_BERRIES)
        {
            gLastUsedItem = GetBattlerPartyState(battler)->usedHeldItem;
            BattleScriptCall(BattleScript_HarvestActivates);
            return TRUE;
        }
        break;
    case ABILITY_ICE_BODY:
        if (IsBattlerWeatherAffected(cv->holdEffects[battler], GetWeather(), B_WEATHER_ICY_ANY)
         && !IsBattlerAtMaxHp(battler)
         && gBattleMons[battler].volatiles.semiInvulnerable != STATE_UNDERGROUND
         && gBattleMons[battler].volatiles.semiInvulnerable != STATE_UNDERWATER
         && !gBattleMons[battler].volatiles.healBlockTimer)
        {
            BattleScriptCall(BattleScript_IceBodyHeal);
            SetHealAmount(battler, GetNonDynamaxMaxHP(battler) / 16);
            return TRUE;
        }
        break;
    case ABILITY_DRY_SKIN:
        if (IsBattlerWeatherAffected(cv->holdEffects[battler], GetWeather(), B_WEATHER_SUN))
            goto SOLAR_POWER_HP_DROP;
    // Dry Skin works similarly to Rain Dish in Rain
        [[fallthrough]];
    case ABILITY_RAIN_DISH:
        if (IsBattlerWeatherAffected(cv->holdEffects[battler], GetWeather(), B_WEATHER_RAIN)
         && !IsBattlerAtMaxHp(battler)
         && !gBattleMons[battler].volatiles.healBlockTimer)
        {
            s32 healAmount = ability == ABILITY_RAIN_DISH ? 16 : 8;
            SetHealAmount(battler, GetNonDynamaxMaxHP(battler) / healAmount);
            BattleScriptCall(BattleScript_AbilityHpHeal);
            return TRUE;
        }
        break;
    case ABILITY_HYDRATION:
        if (IsBattlerWeatherAffected(cv->holdEffects[battler], GetWeather(), B_WEATHER_RAIN)
         && gBattleMons[battler].status1 & STATUS1_ANY)
        {
            goto ABILITY_HEAL_MON_STATUS;
        }
        break;
    case ABILITY_SHED_SKIN:
        if ((gBattleMons[battler].status1 & STATUS1_ANY)
         && (GetConfig(B_ABILITY_TRIGGER_CHANCE) == GEN_4 ? RandomPercentage(RNG_SHED_SKIN, 30) : RandomChance(RNG_SHED_SKIN, 1, 3)))
        {
        ABILITY_HEAL_MON_STATUS:
            if (gBattleMons[battler].status1 & (STATUS1_POISON | STATUS1_TOXIC_POISON))
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_POISON;
            if (gBattleMons[battler].status1 & STATUS1_SLEEP)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_SLEEP;
                TryDeactivateSleepClause(battler, gBattlerPartyIndexes[battler]);
            }
            if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_PARALYSIS;
            if (gBattleMons[battler].status1 & STATUS1_BURN)
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_BURN;
            if (gBattleMons[battler].status1 & STATUS1_FREEZE)
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_FREEZE;
            if (gBattleMons[battler].status1 & STATUS1_FROSTBITE)
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_FROSTBITE;

            gBattleMons[battler].status1 = 0;
            gBattleMons[battler].volatiles.nightmare = FALSE;
            gBattleScripting.battler = battler;
            BattleScriptCall(BattleScript_ShedSkinActivates);
            BtlController_EmitSetMonData(battler, B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battler].status1);
            MarkBattlerForControllerExec(battler);
            return TRUE;
        }
        break;
    case ABILITY_SPEED_BOOST:
        if (CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, ability) && !BattlerJustSwitchedIn(battler))
        {
            gEffectBattler = gBattlerAbility = battler;
            SetStatChange(battler, STAT_SPEED, 1);
            BattleScriptCall(BattleScript_AbilityStatChange);
            return TRUE;
        }
        break;
    case ABILITY_MOODY:
        {
            enum Stat stat = STAT_ATK;
            u32 validToRaise = 0, validToLower = 0;
            u32 statsNum = GetConfig(B_MOODY_ACC_EVASION) >= GEN_8 ? NUM_STATS : NUM_BATTLE_STATS;

            for (stat = STAT_ATK; stat < statsNum; stat++)
            {
                if (CompareStat(battler, stat, MIN_STAT_STAGE, CMP_GREATER_THAN, ability))
                    validToLower |= 1u << stat;
                if (CompareStat(battler, stat, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
                    validToRaise |= 1u << stat;
            }

            if (validToRaise) // Find stat to raise
            {
                stat = RandomUniformExcept(RNG_MOODY_INCREASE, STAT_ATK, statsNum - 1, MoodyCantRaiseStat);
                SetStatChange(battler, stat, 2);
                validToLower &= ~(1u << stat); // Can't lower the same stat as raising.
            }
            if (validToLower) // Find stat to lower
            {
                // MoodyCantLowerStat already checks that both stats are different
                stat = RandomUniformExcept(RNG_MOODY_DECREASE, STAT_ATK, statsNum - 1, MoodyCantLowerStat);
                SetStatChange(battler, stat, -1);
            }

            gEffectBattler = gBattlerAbility = battler;
            BattleScriptCall(BattleScript_AbilityStatChange);
            return TRUE;
        }
        break;
    case ABILITY_TRUANT:
        if (GetConfig(B_TRUANT) <= GEN_4)
            gBattleMons[battler].volatiles.truantToggle ^= 1;
        break;
    case ABILITY_SLOW_START:
        if (gBattleMons[battler].volatiles.slowStartTimer > 0 && --gBattleMons[battler].volatiles.slowStartTimer == 0)
        {
            BattleScriptCall(BattleScript_SlowStartEnds);
            return TRUE;
        }
        break;
    case ABILITY_BAD_DREAMS:
        BattleScriptCall(BattleScript_BadDreamsActivates);
        return TRUE;
    case ABILITY_SOLAR_POWER:
        if (IsBattlerWeatherAffected(cv->holdEffects[battler], GetWeather(), B_WEATHER_SUN))
        {
        SOLAR_POWER_HP_DROP:
            SetPassiveDamageAmount(battler, GetNonDynamaxMaxHP(battler) / 8);
            BattleScriptCall(BattleScript_SolarPowerActivates);
            return TRUE;
        }
        break;
    case ABILITY_HEALER:
        gBattleScripting.battler = GetPartnerBattler(battler);
        if (IsBattlerAlive(gBattleScripting.battler)
         && gBattleMons[gBattleScripting.battler].status1 & STATUS1_ANY
         && RandomPercentage(RNG_HEALER, 30))
        {
            BattleScriptCall(BattleScript_HealerActivates);
            return TRUE;
        }
        break;
    case ABILITY_BALL_FETCH:
        if (!HasAnyBattleFlags(BATTLE_TYPE_RAID)
         && gBattleMons[battler].item == ITEM_NONE
         && gBattleResults.catchAttempts[ItemIdToBallId(gLastUsedBall)] >= 1
         && !gHasFetchedBall)
        {
            gLastUsedItem = gLastUsedBall;
            gBattleScripting.battler = battler;
            gBattleMons[battler].item = gLastUsedItem;
            BtlController_EmitSetMonData(battler, B_COMM_TO_CONTROLLER, REQUEST_HELDITEM_BATTLE, 0, 2, &gLastUsedItem);
            MarkBattlerForControllerExec(battler);
            gHasFetchedBall = TRUE;
            BattleScriptCall(BattleScript_BallFetch);
            return TRUE;
        }
        break;
    case ABILITY_CUD_CHEW:
        if (gBattleMons[battler].volatiles.cudChewTimer > 0 && --gBattleMons[battler].volatiles.cudChewTimer == 0)
        {
            gBattleScripting.battler = battler;
            gLastUsedItem = GetBattlerPartyState(battler)->usedHeldItem;
            GetBattlerPartyState(battler)->usedHeldItem = ITEM_NONE;
            BattleScriptCall(BattleScript_CudChewActivates);
            return TRUE;
        }
        break;
    default:
        break;
    }

    return FALSE;
}

static bool32 TryMoveEndAttackerAbility(struct BattleCalcValues *cv)
{
    switch (cv->abilities[cv->battlerAtk])
    {
    case ABILITY_POISON_TOUCH:
        if (IsBattlerAlive(cv->battlerDef)
         && !IsMoveEffectBlockedByTarget(cv->abilities[cv->battlerDef])
         && CanBePoisoned(cv->battlerAtk, cv->battlerDef, cv->abilities[cv->battlerAtk], cv->abilities[cv->battlerDef])
         && IsMoveMakingContact(cv->battlerAtk, cv->battlerDef, cv->abilities[cv->battlerAtk], cv->holdEffects[cv->battlerAtk], cv->move)
         && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && RandomPercentage(RNG_POISON_TOUCH, 30))
        {
            gEffectBattler = cv->battlerDef;
            gBattleScripting.battler = gBattlerAbility = cv->battlerAtk;
            gBattleScripting.moveEffect = MOVE_EFFECT_POISON;
            gLastUsedAbility = cv->abilities[cv->battlerAtk];
            PREPARE_ABILITY_BUFFER(gBattleTextBuff1, cv->abilities[cv->battlerAtk]);
            BattleScriptCall(BattleScript_AbilityStatusEffect);
            return TRUE;
        }
        break;
    case ABILITY_TOXIC_CHAIN:
        if (gBattleStruct->battlerState[cv->battlerDef].toxicChainActivates)
        {
            gBattleStruct->battlerState[cv->battlerDef].toxicChainActivates = FALSE;
            if (!IsMoveEffectBlockedByTarget(cv->abilities[cv->battlerDef]))
            {
                gEffectBattler = cv->battlerDef;
                gBattleScripting.battler = gBattlerAbility = cv->battlerAtk;
                gBattleScripting.moveEffect = MOVE_EFFECT_TOXIC;
                gLastUsedAbility = cv->abilities[cv->battlerAtk];
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, cv->abilities[cv->battlerAtk]);
                BattleScriptCall(BattleScript_AbilityStatusEffect);
                return TRUE;
            }
        }
        break;
    case ABILITY_STENCH:
        if (IsBattlerAlive(cv->battlerDef)
         && !gBattleStruct->unableToUseMove
         && RandomChance(RNG_STENCH, 1, 10)
         && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && !MoveHasAdditionalEffect(cv->move, MOVE_EFFECT_FLINCH))
        {
            gBattlerAbility = cv->battlerAtk;
            gLastUsedAbility = cv->abilities[cv->battlerAtk];
            SetMoveEffectHelper(cv->battlerAtk, cv->battlerDef, MOVE_EFFECT_FLINCH, gBattlescriptCurrInstr, NO_FLAGS);
            return TRUE;
        }
        break;
    default:
        break;
    }

    return FALSE;
}

static bool32 TryColorChangeAbility(struct BattleCalcValues *cv)
{
    enum BattlerId battler = gBattlerAbility = cv->battlerDef;
    enum Ability ability = gLastUsedAbility = cv->abilities[cv->battlerDef];
    enum Type moveType = GetBattleMoveType(cv->move);

    switch (ability)
    {
    case ABILITY_COLOR_CHANGE:
        if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
         && !IS_BATTLER_OF_TYPE(battler, moveType)
         && cv->move != MOVE_STRUGGLE
         && moveType != TYPE_STELLAR
         && moveType != TYPE_MYSTERY)
        {
            gEffectBattler = battler;
            SET_BATTLER_TYPE(battler, moveType);
            PREPARE_TYPE_BUFFER(gBattleTextBuff1, moveType);
            BattleScriptCall(BattleScript_ColorChangeActivates);
            return TRUE;
        }
        break;
    case ABILITY_BERSERK:
        if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
         && HadMoreThanHalfHpNowDoesnt(battler)
         && CompareStat(battler, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
        {
            gEffectBattler = battler;
            SetStatChange(battler, STAT_SPATK, 1);
            BattleScriptCall(BattleScript_AbilityStatChange);
            return TRUE;
        }
        break;
    case ABILITY_ANGER_SHELL:
        if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
         && HadMoreThanHalfHpNowDoesnt(battler))
        {
            gEffectBattler = battler;
            if (CompareStat(battler, STAT_DEF, MIN_STAT_STAGE, CMP_GREATER_THAN, ABILITY_NONE))
                SetStatChange(battler, STAT_DEF, -1);

            if (CompareStat(battler, STAT_SPDEF, MIN_STAT_STAGE, CMP_GREATER_THAN, ABILITY_NONE))
                SetStatChange(battler, STAT_SPDEF, -1);

            if (CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, ABILITY_NONE))
                SetStatChange(battler, STAT_ATK, 1);

            if (CompareStat(battler, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN, ABILITY_NONE))
                SetStatChange(battler, STAT_SPATK, 1);

            if (CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, ABILITY_NONE))
                SetStatChange(battler, STAT_SPEED, 1);

            if (gSpecialStatuses[battler].statStageAmount > 0)
                BattleScriptCall(BattleScript_AbilityStatChange);
            else // Not sure if there is an actual ability popup in this case
                BattleScriptCall(BattleScript_AbilityPopUp);

            return TRUE;
        }
        break;
    default:
        break;
    }

    return FALSE;
}

static bool32 TryMoveEndAbility(struct BattleCalcValues *cv)
{
    bool32 effect = FALSE;
    enum Ability abilityDef = gLastUsedAbility = cv->abilities[cv->battlerDef];
    enum Type moveType = GetBattleMoveType(cv->move);

    switch (abilityDef)
    {
    case ABILITY_JUSTIFIED:
        if (IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && IsBattlerAlive(cv->battlerDef)
         && moveType == TYPE_DARK
         && CompareStat(cv->battlerDef, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, abilityDef))
        {
            gEffectBattler = cv->battlerDef;
            SetStatChange(cv->battlerDef, STAT_ATK, 1);
            BattleScriptCall(BattleScript_AbilityStatChange);
            effect = TRUE;
        }
        break;
    case ABILITY_RATTLED:
        if (IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && IsBattlerAlive(cv->battlerDef)
         && (moveType == TYPE_DARK || moveType == TYPE_BUG || moveType == TYPE_GHOST)
         && CompareStat(cv->battlerDef, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, abilityDef))
        {
            gEffectBattler = cv->battlerDef;
            SetStatChange(cv->battlerDef, STAT_SPEED, 1);
            BattleScriptCall(BattleScript_AbilityStatChange);
            effect = TRUE;
        }
        break;
    case ABILITY_WATER_COMPACTION:
        if (IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && IsBattlerAlive(cv->battlerDef)
         && moveType == TYPE_WATER
         && CompareStat(cv->battlerDef, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN, abilityDef))
        {
            gEffectBattler = cv->battlerDef;
            SetStatChange(cv->battlerDef, STAT_DEF, 2);
            BattleScriptCall(BattleScript_AbilityStatChange);
            effect = TRUE;
        }
        break;
    case ABILITY_STAMINA:
        if (gBattlerAttacker != cv->battlerDef
         && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && IsBattlerAlive(cv->battlerDef)
         && CompareStat(cv->battlerDef, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN, abilityDef))
        {
            gEffectBattler = cv->battlerDef;
            SetStatChange(cv->battlerDef, STAT_DEF, 1);
            BattleScriptCall(BattleScript_AbilityStatChange);
            effect = TRUE;
        }
        break;
    case ABILITY_WEAK_ARMOR:
        if (IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && IsBattlerAlive(cv->battlerDef)
         && IsBattleMovePhysical(gCurrentMove)
         && (CompareStat(cv->battlerDef, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, abilityDef) // Don't activate if both Speed and Defense cannot be raised.
           || CompareStat(cv->battlerDef, STAT_DEF, MIN_STAT_STAGE, CMP_GREATER_THAN, abilityDef)))
        {
            gEffectBattler = cv->battlerDef;
            SetStatChange(cv->battlerDef, STAT_DEF, -1);
            if (GetConfig(B_WEAK_ARMOR_SPEED) >= GEN_7)
                SetStatChange(cv->battlerDef, STAT_SPEED, 2);
            else
                SetStatChange(cv->battlerDef, STAT_SPEED, 1);
            BattleScriptCall(BattleScript_AbilityStatChange);
            effect = TRUE;
        }
        break;
    case ABILITY_CURSED_BODY:
        if (IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && GetMoveEffect(cv->move) != EFFECT_FUTURE_SIGHT
         && gBattleMons[gBattlerAttacker].volatiles.disabledMove == MOVE_NONE
         && IsBattlerAlive(gBattlerAttacker)
         && !gSpecialStatuses[gBattlerAttacker].attackerInParty
         && !IsAbilityOnSide(gBattlerAttacker, ABILITY_AROMA_VEIL)
         && gChosenMove != MOVE_STRUGGLE
         && GetActiveGimmick(gBattlerAttacker) != GIMMICK_DYNAMAX
         && RandomPercentage(RNG_CURSED_BODY, 30))
        {
            gBattleMons[gBattlerAttacker].volatiles.disabledMove = gChosenMove;
            gBattleMons[gBattlerAttacker].volatiles.disableTimer = B_DISABLE_TIMER;
            PREPARE_MOVE_BUFFER(gBattleTextBuff1, gChosenMove);
            BattleScriptCall(BattleScript_CursedBodyActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_LINGERING_AROMA:
    case ABILITY_MUMMY:
        if (IsBattlerAlive(gBattlerAttacker)
         && !gSpecialStatuses[gBattlerAttacker].attackerInParty
         && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && !CanBattlerAvoidContactEffects(gBattlerAttacker, cv->battlerDef, cv->abilities[cv->battlerAtk], cv->holdEffects[cv->battlerAtk], cv->move)
         && gBattleMons[gBattlerAttacker].ability != abilityDef
         && !gAbilitiesInfo[gBattleMons[gBattlerAttacker].ability].cantBeSuppressed)
        {
            if (GetBattlerHoldEffectIgnoreAbility(gBattlerAttacker) == HOLD_EFFECT_ABILITY_SHIELD)
            {
                RecordItemEffectBattle(gBattlerAttacker, HOLD_EFFECT_ABILITY_SHIELD);
                break;
            }

            RemoveAbilityFlags(gBattlerAttacker);
            gBattleScripting.battler = cv->battlerDef;
            gLastUsedAbility = gBattleMons[gBattlerAttacker].ability;
            OverwriteBattlerAbility(gBattlerAttacker, gBattleMons[cv->battlerDef].ability);
            BattleScriptCall(BattleScript_MummyActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_WANDERING_SPIRIT:
        if (IsBattlerAlive(gBattlerAttacker)
         && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && !CanBattlerAvoidContactEffects(gBattlerAttacker, cv->battlerDef, cv->abilities[gBattlerAttacker], cv->holdEffects[gBattlerAttacker], cv->move)
         && GetActiveGimmick(cv->battlerDef) != GIMMICK_DYNAMAX
         && !gAbilitiesInfo[gBattleMons[gBattlerAttacker].ability].cantBeSwapped)
        {
            if (GetBattlerHoldEffectIgnoreAbility(gBattlerAttacker) == HOLD_EFFECT_ABILITY_SHIELD)
            {
                RecordItemEffectBattle(gBattlerAttacker, HOLD_EFFECT_ABILITY_SHIELD);
                break;
            }
            if (GetBattlerHoldEffectIgnoreAbility(cv->battlerDef) == HOLD_EFFECT_ABILITY_SHIELD)
            {
                RecordItemEffectBattle(cv->battlerDef, HOLD_EFFECT_ABILITY_SHIELD);
                break;
            }

            RemoveAbilityFlags(gBattlerAttacker);
            gBattleScripting.battler = cv->battlerDef;
            gLastUsedAbility = gBattleMons[gBattlerAttacker].ability;
            OverwriteBattlerAbility(gBattlerAttacker, gBattleMons[cv->battlerDef].ability);
            OverwriteBattlerAbility(cv->battlerDef, gLastUsedAbility);
            BattleScriptCall(BattleScript_WanderingSpiritActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_ANGER_POINT:
        if (gSpecialStatuses[cv->battlerDef].criticalHit
         && IsBattlerTurnDamaged(cv->battlerDef, GetConfig(B_UPDATED_ABILITY_DATA) <= GEN_4 ? INCLUDING_SUBSTITUTES : EXCLUDING_SUBSTITUTES)
         && IsBattlerAlive(cv->battlerDef)
         && CompareStat(cv->battlerDef, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, abilityDef))
        {
            gEffectBattler = cv->battlerDef;
            SetStatChange(cv->battlerDef, STAT_ATK, MAX_STAT_STAGE);
            BattleScriptCall(BattleScript_AbilityStatChange);
            effect = TRUE;
        }
        break;
    case ABILITY_GOOEY:
    case ABILITY_TANGLING_HAIR:
        if (IsBattlerAlive(cv->battlerAtk)
         && !gSpecialStatuses[cv->battlerAtk].attackerInParty
         && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && !gBattleStruct->unableToUseMove)
        {
            struct BattleCalcValues gooey = {
                .battlerAtk = cv->battlerDef,
                .battlerDef = cv->battlerAtk,
                .move = MOVE_NONE,
            };

            for (enum BattlerId i = 0; i < gBattlersCount; i++)
            {
                gooey.abilities[i] = cv->abilities[i];
                gooey.holdEffects[i] = cv->holdEffects[i];
            }

            struct StatChange st = {
                .onlyChecking = TRUE,
            };

            struct StatStages change = {
                .stat = STAT_SPEED,
                .stage = -1,
            };

            st.statStageQueue = &change;
            st.statStageAmount = 1;

            if (CanBattlerAvoidContactEffects(cv->battlerAtk, cv->battlerDef, cv->abilities[cv->battlerAtk], cv->holdEffects[cv->battlerAtk], cv->move))
                break;

            if (TryStatChange(&gooey, &st) == STAT_CHANGE_WORKED || cv->abilities[cv->battlerAtk] == ABILITY_MIRROR_ARMOR)
            {
                gEffectBattler = cv->battlerDef;
                gLastUsedAbility = cv->abilities[cv->battlerDef];
                SetStatChange(cv->battlerAtk, STAT_SPEED, -1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect = TRUE;
            }
        }
        break;
    case ABILITY_ROUGH_SKIN:
    case ABILITY_IRON_BARBS:
        if (IsBattlerAlive(cv->battlerAtk)
         && !gSpecialStatuses[cv->battlerAtk].attackerInParty
         && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && !CanBattlerAvoidContactEffects(cv->battlerAtk, cv->battlerDef, cv->abilities[cv->battlerAtk], cv->holdEffects[cv->battlerAtk], cv->move))
        {
            if (!IsAbilityAndRecord(cv->battlerAtk, cv->abilities[cv->battlerAtk], ABILITY_MAGIC_GUARD))
            {
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, abilityDef);
                SetPassiveDamageAmount(cv->battlerAtk, GetNonDynamaxMaxHP(cv->battlerAtk) / (B_ROUGH_SKIN_DMG >= GEN_4 ? 8 : 16));
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_HURT;
                BattleScriptCall(BattleScript_RoughSkinActivates);
            }
            else
            {
                BattleScriptCall(BattleScript_AbilityPopUp);
            }

            effect = TRUE;
        }
        break;
    case ABILITY_AFTERMATH:
        if (!IsBattlerUnaffectedByMove(cv->battlerDef)
         && !gSpecialStatuses[cv->battlerAtk].attackerInParty
         && !IsBattlerAlive(cv->battlerDef)
         && IsBattlerAlive(cv->battlerAtk)
         && !CanBattlerAvoidContactEffects(cv->battlerAtk, cv->battlerDef, cv->abilities[cv->battlerAtk], cv->holdEffects[cv->battlerAtk], cv->move))
        {
            enum BattlerId dampBattler = IsAbilityOnField(ABILITY_DAMP);
            if (dampBattler)
            {
                gBattleScripting.battler = dampBattler - 1;
                BattleScriptCall(BattleScript_DampPreventsAftermath);
            }
            else
            {
                gBattleScripting.battler = cv->battlerDef;
                SetPassiveDamageAmount(cv->battlerAtk, GetNonDynamaxMaxHP(cv->battlerAtk) / 4);
                BattleScriptCall(BattleScript_AftermathDmg);
            }

            effect = TRUE;
        }
        break;
    case ABILITY_INNARDS_OUT:
        if (!IsBattlerUnaffectedByMove(cv->battlerDef)
         && !IsBattlerAlive(cv->battlerDef)
         && !gSpecialStatuses[cv->battlerAtk].attackerInParty
         && IsBattlerAlive(cv->battlerAtk))
        {
            s32 damage = gBattleStruct->moveDamage[cv->battlerDef];

            if (gBattleStruct->innardsOutHpLost[cv->battlerDef] != 0)
                damage = gBattleStruct->innardsOutHpLost[cv->battlerDef];

            gBattleScripting.battler = cv->battlerDef;
            SetPassiveDamageAmount(cv->battlerAtk, damage);
            BattleScriptCall(BattleScript_AftermathDmg);
            effect = TRUE;
        }
        break;
    case ABILITY_EFFECT_SPORE:
    {
        enum Ability abilityAtk = cv->abilities[cv->battlerAtk];
        enum HoldEffect holdEffectAtk = cv->holdEffects[cv->battlerAtk];
        if (IsBattlerAlive(cv->battlerAtk)
         && !gSpecialStatuses[cv->battlerAtk].attackerInParty
         && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && !CanBattlerAvoidContactEffects(cv->battlerAtk, cv->battlerDef, abilityAtk, holdEffectAtk, cv->move)
         && IsAffectedByPowderMove(cv->battlerAtk, abilityAtk, holdEffectAtk))
        {
            u32 poison, paralysis, sleep;

            if (GetConfig(B_ABILITY_TRIGGER_CHANCE) >= GEN_5)
            {
                poison = 9;
                paralysis = 19;
            }
            else
            {
                poison = 10;
                paralysis = 20;
            }
            sleep = 30;

            u32 chance = RandomUniform(RNG_EFFECT_SPORE, 0, GetConfig(B_ABILITY_TRIGGER_CHANCE) >= GEN_4 ? 99 : 299);
            if (chance < poison)
                goto POISON_POINT;
            if (chance < paralysis)
                goto STATIC;
            // Sleep
            if (chance < sleep && CanBeSlept(cv->battlerDef, cv->battlerAtk, abilityAtk, NOT_BLOCKED_BY_SLEEP_CLAUSE))
            {
                if (IsSleepClauseEnabled())
                    gBattleStruct->battlerState[cv->battlerAtk].sleepClauseEffectExempt = TRUE;
                gEffectBattler = cv->battlerAtk;
                gBattleScripting.battler = cv->battlerDef;
                gBattleScripting.moveEffect = MOVE_EFFECT_SLEEP;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, abilityDef);
                BattleScriptCall(BattleScript_AbilityStatusEffect);
                effect = TRUE;
            }
        }
    }
        break;
    case ABILITY_POISON_POINT:
        if (GetConfig(B_ABILITY_TRIGGER_CHANCE) >= GEN_4 ? RandomPercentage(RNG_POISON_POINT, 30) : RandomChance(RNG_POISON_POINT, 1, 3))
        {
        POISON_POINT:
        {
            enum Ability abilityAtk = cv->abilities[cv->battlerAtk];
            if (IsBattlerAlive(cv->battlerAtk)
             && !gSpecialStatuses[cv->battlerAtk].attackerInParty
             && !gBattleStruct->unableToUseMove
             && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
             && CanBePoisoned(cv->battlerDef, cv->battlerAtk, abilityDef, abilityAtk)
             && !CanBattlerAvoidContactEffects(cv->battlerAtk, cv->battlerDef, abilityAtk, cv->holdEffects[cv->battlerAtk], cv->move))
            {
                gEffectBattler = cv->battlerAtk;
                gBattleScripting.battler = cv->battlerDef;
                gBattleScripting.moveEffect = MOVE_EFFECT_POISON;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, abilityDef);
                BattleScriptCall(BattleScript_AbilityStatusEffect);
                effect = TRUE;
            }
        }
        }
        break;
    case ABILITY_STATIC:
        if (GetConfig(B_ABILITY_TRIGGER_CHANCE) >= GEN_4 ? RandomPercentage(RNG_STATIC, 30) : RandomChance(RNG_STATIC, 1, 3))
        {
        STATIC:
        {
            enum Ability abilityAtk = cv->abilities[cv->battlerAtk];
            if (IsBattlerAlive(cv->battlerAtk)
             && !gSpecialStatuses[cv->battlerAtk].attackerInParty
             && !gBattleStruct->unableToUseMove
             && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
             && CanBeParalyzed(cv->battlerDef, cv->battlerAtk, abilityAtk)
             && !CanBattlerAvoidContactEffects(cv->battlerAtk, cv->battlerDef, abilityAtk, cv->holdEffects[cv->battlerAtk], cv->move))
            {
                gEffectBattler = cv->battlerAtk;
                gBattleScripting.battler = cv->battlerDef;
                gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, abilityDef);
                BattleScriptCall(BattleScript_AbilityStatusEffect);
                effect = TRUE;
            }
        }
        }
        break;
    case ABILITY_FLAME_BODY:
        if (IsBattlerAlive(cv->battlerAtk)
         && !gSpecialStatuses[cv->battlerAtk].attackerInParty
         && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && !CanBattlerAvoidContactEffects(cv->battlerAtk, cv->battlerDef, cv->abilities[cv->battlerAtk], cv->holdEffects[cv->battlerAtk], cv->move)
         && CanBeBurned(cv->battlerDef, cv->battlerAtk, cv->abilities[cv->battlerAtk])
         && (GetConfig(B_ABILITY_TRIGGER_CHANCE) >= GEN_4 ? RandomPercentage(RNG_FLAME_BODY, 30) : RandomChance(RNG_FLAME_BODY, 1, 3)))
        {
            gEffectBattler = cv->battlerAtk;
            gBattleScripting.battler = cv->battlerDef;
            gBattleScripting.moveEffect = MOVE_EFFECT_BURN;
            gLastUsedAbility = cv->abilities[cv->battlerAtk];
            PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gLastUsedAbility);
            BattleScriptCall(BattleScript_AbilityStatusEffect);
            effect = TRUE;
        }
        break;
    case ABILITY_CUTE_CHARM:
        if (IsBattlerAlive(cv->battlerAtk)
         && !gSpecialStatuses[cv->battlerAtk].attackerInParty
         && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && IsBattlerAlive(cv->battlerDef)
         && (GetConfig(B_ABILITY_TRIGGER_CHANCE) >= GEN_4 ? RandomPercentage(RNG_CUTE_CHARM, 30) : RandomChance(RNG_CUTE_CHARM, 1, 3))
         && !(gBattleMons[cv->battlerAtk].volatiles.infatuation)
         && AreBattlersOfOppositeGender(cv->battlerAtk, cv->battlerDef)
         && !IsAbilityAndRecord(cv->battlerAtk, cv->abilities[cv->battlerAtk], ABILITY_OBLIVIOUS)
         && !CanBattlerAvoidContactEffects(cv->battlerAtk, cv->battlerDef, cv->abilities[cv->battlerAtk], cv->holdEffects[cv->battlerAtk], cv->move)
         && !IsAbilityOnSide(cv->battlerAtk, ABILITY_AROMA_VEIL))
        {
            gBattleMons[cv->battlerAtk].volatiles.infatuation = INFATUATED_WITH(cv->battlerDef);
            BattleScriptCall(BattleScript_CuteCharmActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_ILLUSION:
        if (gBattleStruct->illusion[cv->battlerDef].state == ILLUSION_ON && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES))
        {
            gBattleScripting.battler = cv->battlerDef;
            BattleScriptCall(BattleScript_IllusionOff);
            effect = TRUE;
        }
        break;
    case ABILITY_COTTON_DOWN:
        if (IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES))
        {
            gEffectBattler = cv->battlerDef;
            for (enum BattlerId i = 0; i < gBattlersCount; i++)
            {
                if (cv->battlerDef == i || !IsBattlerAlive(i))
                    continue;
                SetStatChange(i, STAT_SPEED, -1);
            }
            BattleScriptCall(BattleScript_AbilityStatChange);
            effect = TRUE;
        }
        break;
    case ABILITY_STEAM_ENGINE:
        if (IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && IsBattlerAlive(cv->battlerDef)
         && CompareStat(cv->battlerDef, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, abilityDef)
         && (moveType == TYPE_FIRE || moveType == TYPE_WATER))
        {
            gEffectBattler = cv->battlerDef;
            SetStatChange(cv->battlerDef, STAT_SPEED, 6);
            BattleScriptCall(BattleScript_AbilityStatChange);
            effect = TRUE;
        }
        break;
    case ABILITY_SAND_SPIT:
        if (IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES) && TryChangeWeatherWithAbility(cv->battlerDef, BATTLE_WEATHER_SANDSTORM, abilityDef))
            effect = TRUE;
        break;
    case ABILITY_PERISH_BODY:
        if (IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && IsBattlerAlive(cv->battlerDef)
         && !CanBattlerAvoidContactEffects(cv->battlerAtk, cv->battlerDef, cv->abilities[cv->battlerAtk], cv->holdEffects[cv->battlerAtk], cv->move)
         && !gBattleMons[cv->battlerAtk].volatiles.perishSong)
        {
            if (!gBattleMons[cv->battlerDef].volatiles.perishSong)
            {
                gBattleMons[cv->battlerDef].volatiles.perishSong = TRUE;
                gBattleMons[cv->battlerDef].volatiles.perishSongTimer = 3;
            }
            gBattleMons[cv->battlerAtk].volatiles.perishSong = TRUE;
            gBattleMons[cv->battlerAtk].volatiles.perishSongTimer = 3;
            BattleScriptCall(BattleScript_PerishBodyActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_SEED_SOWER:
        if (IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && TryChangeBattleTerrain(cv->battlerDef, B_TERRAIN_GRASSY))
        {
            BattleScriptCall(BattleScript_SeedSowerActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_THERMAL_EXCHANGE:
        if (IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && IsBattlerAlive(cv->battlerDef)
         && CompareStat(cv->battlerDef, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, abilityDef)
         && moveType == TYPE_FIRE)
        {
            gEffectBattler = cv->battlerDef;
            SetStatChange(cv->battlerDef, STAT_ATK, 1);
            BattleScriptCall(BattleScript_AbilityStatChange);
            effect = TRUE;
        }
        break;
    case ABILITY_WIND_POWER:
        if (!IsWindMove(gCurrentMove))
            break;
        [[fallthrough]];
    case ABILITY_ELECTROMORPHOSIS:
        if (!gBattleStruct->unableToUseMove && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES))
        {
            BattleScriptCall(BattleScript_WindPowerActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_TOXIC_DEBRIS:
    {
        enum BattlerId toxicSpikesTarget = GetOppositeBattler(cv->battlerDef);
        enum BattleSide side = GetBattlerSide(toxicSpikesTarget);
        if (!gBattleStruct->isSkyBattle
         && IsBattleMovePhysical(gCurrentMove)
         && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && (gSideTimers[side].toxicSpikesAmount != 2))
        {
            if (gSideTimers[side].toxicSpikesAmount == 0) // Add only once to the queue
                PushHazardTypeToQueue(side, HAZARDS_TOXIC_SPIKES);
            gSideTimers[side].toxicSpikesAmount++;
            // TODO: user ability and scripting battler
            SaveBattlerTarget(cv->battlerDef);
            SaveBattlerAttacker(cv->battlerAtk);
            gBattlerAttacker = cv->battlerDef;
            gBattlerTarget = GetOppositeBattler(gBattlerAttacker);
            BattleScriptCall(BattleScript_ToxicDebrisActivates);
            effect = TRUE;
        }
        break;
    }
    case ABILITY_SPICY_SPRAY:
        if (IsBattlerAlive(cv->battlerAtk)
         && !gSpecialStatuses[cv->battlerAtk].attackerInParty
         && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         && CanBeBurned(cv->battlerDef, cv->battlerAtk, cv->abilities[cv->battlerAtk]))
        {
            gEffectBattler = cv->battlerAtk;
            gBattleScripting.battler = cv->battlerDef;
            gBattleScripting.moveEffect = MOVE_EFFECT_BURN;
            PREPARE_ABILITY_BUFFER(gBattleTextBuff1, abilityDef);
            BattleScriptCall(BattleScript_AbilityStatusEffect);
            effect = TRUE;
        }
        break;
    default:
        break;
    }

    gBattlerAbility = cv->battlerDef;
    return effect;
}

static bool32 TryImmunityAbility(struct BattleCalcValues *cv)
{
    enum BattlerId battler = gBattlerAbility = gBattleScripting.battler = cv->battlerAtk;
    enum Ability ability = gLastUsedAbility = GetBattlerAbilityIgnoreMoldBreaker(battler);
    enum ImmunityHealStatusOutcome outcome = IMMUNITY_NO_EFFECT;

    switch (ability)
    {
    case ABILITY_IMMUNITY:
    case ABILITY_PASTEL_VEIL:
        if (gBattleMons[battler].status1 & (STATUS1_POISON | STATUS1_TOXIC_POISON | STATUS1_TOXIC_COUNTER))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_POISON;
            outcome = IMMUNITY_STATUS_CLEARED;
        }
        break;
    case ABILITY_OWN_TEMPO:
        if (gBattleMons[battler].volatiles.confusionTimer > 0)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_CONFUSION;
            outcome = IMMUNITY_CONFUSION_CLEARED;
        }
        break;
    case ABILITY_LIMBER:
        if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_PARALYSIS;
            outcome = IMMUNITY_STATUS_CLEARED;
        }
        break;
    case ABILITY_INSOMNIA:
    case ABILITY_VITAL_SPIRIT:
        if (gBattleMons[battler].status1 & STATUS1_SLEEP)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_SLEEP;
            TryDeactivateSleepClause(battler, gBattlerPartyIndexes[battler]);
            gBattleMons[battler].volatiles.nightmare = FALSE;
            outcome = IMMUNITY_STATUS_CLEARED;
        }
        break;
    case ABILITY_WATER_VEIL:
    case ABILITY_WATER_BUBBLE:
    case ABILITY_THERMAL_EXCHANGE:
        if (gBattleMons[battler].status1 & STATUS1_BURN)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_BURN;
            outcome = IMMUNITY_STATUS_CLEARED;
        }
        break;
    case ABILITY_MAGMA_ARMOR:
        if (gBattleMons[battler].status1 & STATUS1_FREEZE)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_FREEZE;
            outcome = IMMUNITY_STATUS_CLEARED;
        }
        else if (gBattleMons[battler].status1 & STATUS1_FROSTBITE)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_FROSTBITE;
            outcome = IMMUNITY_STATUS_CLEARED;
        }
        break;
    case ABILITY_OBLIVIOUS:
    {
        bool32 infatuationHeal = gBattleMons[battler].volatiles.infatuation;
        bool32 tauntHeal = GetConfig(B_OBLIVIOUS_TAUNT) >= GEN_6 && gBattleMons[battler].volatiles.tauntTimer != 0;

        if (infatuationHeal && tauntHeal)
        {
            outcome = IMMUNITY_INFATUATION_TAUNT_CLEARED;
        }
        else if (infatuationHeal)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_INFATUATION;
            outcome = IMMUNITY_INFATUATION_CLEARED;
        }
        else if (tauntHeal)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_TAUNT;
            outcome = IMMUNITY_TAUNT_CLEARED;
        }
        break;
    }
    default:
        break;
    }

    switch (outcome)
    {
    case IMMUNITY_STATUS_CLEARED:
        gBattleMons[battler].status1 = 0;
        BattleScriptCall(BattleScript_AbilityCuredStatus);
        break;
    case IMMUNITY_CONFUSION_CLEARED:
        gBattleMons[battler].volatiles.confusionTimer = 0;
        BattleScriptCall(BattleScript_AbilityCuredStatus);
        break;
    case IMMUNITY_INFATUATION_CLEARED:
        gBattleMons[battler].volatiles.infatuation = 0;
        BattleScriptCall(BattleScript_AbilityCuredStatus);
        break;
    case IMMUNITY_TAUNT_CLEARED:
        gBattleMons[battler].volatiles.tauntTimer = 0;
        BattleScriptCall(BattleScript_AbilityCuredStatus);
        break;
    case IMMUNITY_INFATUATION_TAUNT_CLEARED:
        gBattleMons[battler].volatiles.infatuation = 0;
        gBattleMons[battler].volatiles.tauntTimer = 0;
        BattleScriptCall(BattleScript_AbilityCuredInfatuationAndTaunt);
        break;
    case IMMUNITY_NO_EFFECT:
        return IMMUNITY_NO_EFFECT;
    }

    if (outcome == IMMUNITY_STATUS_CLEARED)
    {
        BtlController_EmitSetMonData(battler, B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battler].status1);
        MarkBattlerForControllerExec(battler);
    }

    return TRUE;
}

static bool32 TryFormChangeOnHitAbility(struct BattleCalcValues *cv)
{
    enum Species speciesForm = gBattleMons[cv->battlerDef].species;
    enum Ability abilityDef = gLastUsedAbility = cv->abilities[cv->battlerDef];

    if (gBattleStruct->unableToUseMove
     || !IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
     || !TryBattleFormChange(cv->battlerDef, FORM_CHANGE_BATTLE_HIT_BY_MOVE_CATEGORY, abilityDef))
        return FALSE;

    gBattleScripting.abilityPopupOverwrite = abilityDef;
    gBattleScripting.battler = gBattlerAbility = cv->battlerDef;

    switch (abilityDef)
    {
    case ABILITY_GULP_MISSILE:
        if (!IsBattlerAlive(cv->battlerAtk))
            break;

        if (!IsAbilityAndRecord(cv->battlerAtk, cv->abilities[cv->battlerAtk], ABILITY_MAGIC_GUARD))
            SetPassiveDamageAmount(cv->battlerAtk, GetNonDynamaxMaxHP(cv->battlerAtk) / 4);

        switch (speciesForm)
        {
        case SPECIES_CRAMORANT_GORGING:
            BattleScriptCall(BattleScript_GulpMissileGorging);
            break;
        case SPECIES_CRAMORANT_GULPING:
            SetStatChange(cv->battlerAtk, STAT_DEF, -1);
            BattleScriptCall(BattleScript_GulpMissileGulping);
            break;
        default:
            BattleScriptCall(BattleScript_BattlerFormChange); // Fallback
            break;
        }
        break;
    case ABILITY_DISGUISE:
        if (GetConfig(B_DISGUISE_HP_LOSS) >= GEN_8)
            SetPassiveDamageAmount(cv->battlerDef, GetNonDynamaxMaxHP(cv->battlerDef) / 8);
        BattleScriptCall(BattleScript_BattlerFormChangeDisguise);
        break;
    case ABILITY_ICE_FACE:
        BattleScriptCall(BattleScript_IceFaceNullsDamage);
        break;
    default:
        BattleScriptCall(BattleScript_BattlerFormChange);
        break;
    }

    return TRUE;
}

static bool32 TryDancerAbility(struct BattleCalcValues *cv)
{
    u32 order = 0;
    enum BattlerId dancerBattler = MAX_BATTLERS_COUNT;

    if (!IsDanceMove(cv->move))
        return FALSE;

    for (order = 0; order < gBattlersCount; order++)
    {
        if (GetConfig(B_DANCER_ORDER) < GEN_8)
            dancerBattler = gBattlersByRawSpeed[gBattlersCount - order - 1]; // pick from slowest to fastest Raw Speed
        else
            dancerBattler = gBattlersBySpeed[order]; // pick from fastest to slowest Speed including modifiers

        if (gBattleMons[dancerBattler].volatiles.activateDancer && !gSpecialStatuses[dancerBattler].dancerUsedMove)
            break;
    }

    if (order >= gBattlersCount) // no battler activates Dancer
        return FALSE;

    // Dance move succeeds
    // Set target for other Dancer mons; set bit so that mon cannot activate Dancer off of its own move
    if (!gSpecialStatuses[cv->battlerAtk].dancerUsedMove)
    {
        gBattleStruct->dancerSavedTarget = cv->battlerDef;
        gBattleStruct->dancerSavedAttacker = cv->battlerAtk;
        gSpecialStatuses[cv->battlerAtk].dancerUsedMove = TRUE;
    }

    if (IsBattlerAlive(dancerBattler))
    {
        gSpecialStatuses[dancerBattler].dancerUsedMove = TRUE;
        gSpecialStatuses[dancerBattler].backUpTarget = gBattleStruct->moveTarget[dancerBattler] + 1;
        gBattleMons[dancerBattler].volatiles.activateDancer = FALSE;
        gBattlerAttacker = gBattlerAbility = dancerBattler;
        gCalledMove = gCurrentMove;
        gLastUsedAbility = ABILITY_DANCER;
        RecordAbilityBattle(gBattlerAttacker, ABILITY_DANCER);

        // Set the target to the original target of the mon that first used a Dance move
        gBattlerTarget = gBattleStruct->dancerSavedTarget;

        // Make sure that the target isn't an ally - if it is, target the original user
        if (IsBattlerAlly(gBattlerTarget, gBattlerAttacker))
            gBattlerTarget = gBattleStruct->dancerSavedAttacker;

        BattleScriptExecute(BattleScript_DancerActivates);
        return TRUE;
    }

    return FALSE;
}

static bool32 TryMoveEndFoesFaintedAbility(struct BattleCalcValues *cv)
{
    gBattlerAbility = cv->battlerAtk;
    enum Ability abilityAtk = cv->abilities[cv->battlerAtk];

    switch (cv->abilities[cv->battlerAtk])
    {
    case ABILITY_MAGICIAN:
        if (GetMoveEffect(cv->move) != EFFECT_FLING
         && GetMoveEffect(cv->move) != EFFECT_NATURAL_GIFT
         && GetMoveEffect(cv->move) != EFFECT_FUTURE_SIGHT
         && gBattleMons[cv->battlerAtk].item == ITEM_NONE
         && !gSpecialStatuses[cv->battlerAtk].gemBoost) // In base game, gems are consumed after magician would activate.
        {
            u32 numFoeMagicianTargets = 0;
            u32 numAllyMagicianTargets = 0;
            u32 foeMagicianTargets = 0;
            u32 allyMagicianTargets = 0;

            for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
            {
                if (gBattleMons[battlerDef].item != ITEM_NONE
                 && battlerDef != cv->battlerAtk
                 && IsBattlerTurnDamaged(battlerDef, EXCLUDING_SUBSTITUTES)
                 && CanStealItem(cv->battlerAtk, battlerDef, gBattleMons[battlerDef].item)
                 && !GetBattlerPartyState(battlerDef)->isKnockedOff)
                {
                    if (IsBattlerAlly(cv->battlerAtk, battlerDef))
                    {
                        allyMagicianTargets |= 1u << battlerDef;
                        numAllyMagicianTargets++;
                    }
                    else
                    {
                        foeMagicianTargets |= 1u << battlerDef;
                        numFoeMagicianTargets++;
                    }
                }
            }

            if (numFoeMagicianTargets == 0 && numAllyMagicianTargets == 0)
                return FALSE;

            // For spread moves, Magician prioritizes opponents over allies.
            u32 magicianTargets = (numFoeMagicianTargets != 0) ? foeMagicianTargets : allyMagicianTargets;
            u32 numMagicianTargets = (numFoeMagicianTargets != 0) ? numFoeMagicianTargets : numAllyMagicianTargets;
            enum BattlerId battlers[MAX_BATTLERS_COUNT] = {0, 1, 2, 3};

            if (numMagicianTargets > 1)
                SortBattlersBySpeed(battlers, (gFieldStatuses & STATUS_FIELD_TRICK_ROOM) != 0);

            for (u32 i = 0; i < gBattlersCount; i++)
            {
                enum BattlerId targetBattler = battlers[i];

                if (!(magicianTargets & 1u << targetBattler))
                    continue;

                if (cv->abilities[targetBattler] == ABILITY_STICKY_HOLD)
                    return FALSE;

                StealTargetItem(cv->battlerAtk, targetBattler, ITEM_NONE, FALSE);
                gEffectBattler = targetBattler;
                gLastUsedAbility = abilityAtk;
                BattleScriptCall(BattleScript_MagicianActivates);
                return TRUE; // found target to steal from
            }
        }
        break;
    case ABILITY_MOXIE:
    case ABILITY_CHILLING_NEIGH:
    case ABILITY_AS_ONE_ICE_RIDER:
    case ABILITY_GRIM_NEIGH:
    case ABILITY_AS_ONE_SHADOW_RIDER:
    case ABILITY_BEAST_BOOST:
    case ABILITY_EELEVATE:
        {
            if (NoAliveMonsForEitherParty())
                break;

            enum Stat stat = STAT_ATK;

            u32 numMonsFainted = NumFaintedBattlersByAttacker(cv->battlerAtk);

            switch (abilityAtk)
            {
            case ABILITY_BEAST_BOOST:
            case ABILITY_EELEVATE:
                stat = GetHighestStatId(cv->battlerAtk);
                break;
            case ABILITY_GRIM_NEIGH:
            case ABILITY_AS_ONE_SHADOW_RIDER:
                stat = STAT_SPATK;
                break;
            default:
                break;
            }

            if (numMonsFainted && CompareStat(cv->battlerAtk, stat, MAX_STAT_STAGE, CMP_LESS_THAN, abilityAtk))
            {
                gLastUsedAbility = abilityAtk;
                if (abilityAtk == ABILITY_AS_ONE_ICE_RIDER)
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_CHILLING_NEIGH;
                else if (abilityAtk == ABILITY_AS_ONE_SHADOW_RIDER)
                    gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_GRIM_NEIGH;

                gEffectBattler = gBattlerAbility = cv->battlerAtk;
                SetStatChange(cv->battlerAtk, stat, numMonsFainted);
                BattleScriptCall(BattleScript_AbilityStatChange);
                return TRUE;
            }
        }
        break;
    case ABILITY_BATTLE_BOND:
        if (NoAliveMonsForEitherParty()
         || NumFaintedBattlersByAttacker(cv->battlerAtk) == 0)
            break;

        if (GetBattlerPartyState(cv->battlerAtk)->battleBondBoost || gBattleMons[cv->battlerAtk].species != SPECIES_GRENINJA_BATTLE_BOND)
            break;

        if (GetConfig(B_BATTLE_BOND) < GEN_9)
        {
            gLastUsedAbility = abilityAtk;
            GetBattlerPartyState(cv->battlerAtk)->battleBondBoost = TRUE;
            PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[cv->battlerAtk].species);
            TryBattleFormChange(cv->battlerAtk, FORM_CHANGE_BATTLE_BOND, abilityAtk);
            BattleScriptCall(BattleScript_BattleBondActivatesOnMoveEndAttacker);
            return TRUE;
        }

        if (CompareStat(cv->battlerAtk, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, abilityAtk))
            SetStatChange(cv->battlerAtk, STAT_ATK, 1);
        if (CompareStat(cv->battlerAtk, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN, abilityAtk))
            SetStatChange(cv->battlerAtk, STAT_SPATK, 1);
        if (CompareStat(cv->battlerAtk, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, abilityAtk))
            SetStatChange(cv->battlerAtk, STAT_SPEED, 1);

        if (gSpecialStatuses[cv->battlerAtk].statStageAmount > 0)
        {
            gLastUsedAbility = abilityAtk;
            gEffectBattler = gBattlerAbility = cv->battlerAtk;

            GetBattlerPartyState(cv->battlerAtk)->battleBondBoost = TRUE;
            BattleScriptCall(BattleScript_AbilityStatChange);
            return TRUE;
        }
        break;
    default:
        break;
    }

    return FALSE;
}

static bool32 TryReceiverAbility(struct BattleCalcValues *cv)
{
    switch (cv->abilities[cv->battlerDef])
    {
    case ABILITY_RECEIVER:
    case ABILITY_POWER_OF_ALCHEMY:
        if (GetBattlerHoldEffectIgnoreAbility(cv->battlerDef) != HOLD_EFFECT_ABILITY_SHIELD
         && !gAbilitiesInfo[gBattleMons[cv->battlerAtk].ability].cantBeCopied)
        {
            gBattlerAbility = cv->battlerDef;
            gBattleStruct->tracedAbility[cv->battlerDef] = gBattleMons[cv->battlerAtk].ability; // re-using the variable for trace
            gBattleScripting.battler = cv->battlerAtk;
            gLastUsedAbility = cv->abilities[cv->battlerDef];
            BattleScriptCall(BattleScript_ReceiverActivates);
            return TRUE;
        }
        break;
    default:
        break;
    }

    return FALSE;
}

static bool32 TryOnFaintAbility(struct BattleCalcValues *cv)
{
    enum Ability abilityAtk = gLastUsedAbility = cv->abilities[cv->battlerAtk];

    switch (abilityAtk)
    {
    case ABILITY_SOUL_HEART:
        if (!NoAliveMonsForEitherParty()
         && CompareStat(cv->battlerAtk, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN, abilityAtk))
        {
            gEffectBattler = gBattlerAbility = cv->battlerAtk;
            SetStatChange(cv->battlerAtk, STAT_SPATK, 1);
            BattleScriptCall(BattleScript_AbilityStatChange);
            return TRUE;
        }
        break;
    default:
        break;
    }

    return FALSE;
}

static bool32 TryOnFormChangeAbility(struct BattleCalcValues *cv)
{
    gBattlerAbility = cv->battlerAtk;
    gLastUsedAbility = cv->abilities[cv->battlerAtk];

    switch (gLastUsedAbility)
    {
    case ABILITY_TERAFORM_ZERO:
        if (gBattleStruct->overworldWeatherPresent)
        {
            if (gFieldTimers.terrain != B_TERRAIN_NONE)
                BattleScriptCall(BattleScript_ActivateTeraformZeroRemovesOnlyTerrain);
            else
                BattleScriptCall(BattleScript_BlockedByOverworldWeather);
            return TRUE;
        }
        else if (gBattleWeather != WEATHER_NONE || gFieldTimers.terrain != B_TERRAIN_NONE)
        {
            BattleScriptCall(BattleScript_ActivateTeraformZero);
            return TRUE;
        }
        break;
    default:
        break;
    }

    return FALSE;
}

static bool32 TryOnStatusChangeAbility(struct BattleCalcValues *cv)
{
    enum BattlerId battler = cv->battlerAtk;
    enum Ability ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];

    switch (ability)
    {
    case ABILITY_POISON_PUPPETEER:
        if (IsRestrictedAbility(battler, ABILITY_POISON_PUPPETEER)
         && gBattleStruct->statusInflicterBattler == battler // Is the battler that applied status
         && gSpecialStatuses[gBattleStruct->statusedBattler].poisonPuppeteer)
        {
            gSpecialStatuses[gBattleStruct->statusedBattler].poisonPuppeteer = FALSE;
            if (CanBeConfused(battler, gBattleStruct->statusedBattler))
            {
                gBattleScripting.battler = gBattlerAbility = battler;
                gEffectBattler = gBattleStruct->statusedBattler;
                gBattleScripting.moveEffect = MOVE_EFFECT_CONFUSION;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, ability);
                BattleScriptCall(BattleScript_AbilityStatusEffect);
                return TRUE;
            }
        }
        break;
    case ABILITY_SYNCHRONIZE:
        if (!gSpecialStatuses[battler].synchronize)
            break;
        switch (gBattleStruct->synchronizeStatus)
        {
        case MOVE_EFFECT_NONE:
            break;
        case MOVE_EFFECT_TOXIC:
            if (GetConfig(B_SYNCHRONIZE_TOXIC) < GEN_5)
                gBattleStruct->synchronizeStatus = MOVE_EFFECT_POISON;
            [[fallthrough]];
        default:
            gEffectBattler = gBattleStruct->statusInflicterBattler; // battler that originally inflicted status
            gBattleScripting.battler = gBattlerAbility = battler; // battler originally inflicted by status
            gBattleScripting.moveEffect = gBattleStruct->synchronizeStatus;
            PREPARE_ABILITY_BUFFER(gBattleTextBuff1, ABILITY_SYNCHRONIZE);

            if (CanSetNonVolatileStatus(
                    battler,
                    gEffectBattler,
                    ability,
                    cv->abilities[gEffectBattler],
                    gBattleScripting.moveEffect,
                    CHECK_TRIGGER))
            {
                gBattlerAbility = battler;
                BattleScriptCall(BattleScript_SynchronizeActivates);
                return TRUE;
            }

            BattleScriptPush(gBattlescriptCurrInstr);
            if (!CanSetNonVolatileStatus(
                    battler,
                    gEffectBattler,
                    ability,
                    cv->abilities[gEffectBattler],
                    gBattleScripting.moveEffect,
                    RUN_SCRIPT))
            {
                gBattlerAbility = battler;
                gSpecialStatuses[battler].synchronize = FALSE;
                return TRUE;
            }
            break;
        }
        break;
    default:
        break;
    }

    return FALSE;
}

static bool32 TryTeraShiftAbility(struct BattleCalcValues *cv)
{
    if (TryBattleFormChange(cv->battlerAtk, FORM_CHANGE_BATTLE_SWITCH_IN, cv->abilities[cv->battlerAtk]))
    {
        gBattleScripting.battler = gBattlerAbility = cv->battlerAtk;
        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = cv->abilities[cv->battlerAtk];
        BattleScriptCall(BattleScript_BattlerFormChangeWithString);
        return TRUE;
    }

    return FALSE;
}

static bool32 TryNeutralizinggasAbility(struct BattleCalcValues *cv)
{
    enum BattlerId battler = gBattlerAbility = cv->battlerAtk;
    enum Ability ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];

    if (ability == ABILITY_NEUTRALIZING_GAS && !gBattleMons[battler].volatiles.neutralizingGas)
    {
        for (enum BattlerId battlerDef = B_BATTLER_0; battlerDef < gBattlersCount; battlerDef++)
        {
            if (battler == battlerDef || GetBattlerHoldEffectIgnoreAbility(battlerDef) == HOLD_EFFECT_ABILITY_SHIELD)
                continue;
            ResetTruantToggleOnAbilitySuppression(battlerDef);
            RemoveRuinAbilityFlags(battlerDef);
        }

        gBattleMons[battler].volatiles.neutralizingGas = TRUE;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_NEUTRALIZING_GAS;
        BattleScriptCall(BattleScript_SwitchInNeutralizingGas);
        return TRUE;
    }

    return FALSE;
}

static bool32 TryUnnerveAbility(struct BattleCalcValues *cv)
{
    enum BattlerId battler = gBattlerAbility = cv->battlerAtk;
    enum Ability ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];

    switch (ability)
    {
    case ABILITY_UNNERVE:
        if (cv->shouldAbilityTrigger && !gBattleMons[battler].volatiles.unnerveActivated)
        {
            gBattleScripting.battler = battler;
            gEffectBattler = GetOppositeBattler(battler);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_UNNERVE;
            gBattleMons[battler].volatiles.unnerveActivated = TRUE;
            BattleScriptCall(BattleScript_SwitchInAbilityMsg);
            return TRUE;
        }
        break;
    case ABILITY_AS_ONE_ICE_RIDER:
    case ABILITY_AS_ONE_SHADOW_RIDER:
        if (cv->shouldAbilityTrigger && !gBattleMons[battler].volatiles.unnerveActivated)
        {
            gBattleScripting.battler = battler;
            gEffectBattler = GetOppositeBattler(battler);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_ASONE;
            gBattleMons[battler].volatiles.unnerveActivated = TRUE;
            BattleScriptCall(BattleScript_ActivateAsOne);
            return TRUE;
        }
        break;
    default:
        break;
    }

    return FALSE;
}

static bool32 TryOnSwitchInAbility(struct BattleCalcValues *cv)
{
    bool32 effect = FALSE;
    enum BattlerId battler = gBattlerAbility = gBattleScripting.battler = cv->battlerAtk;
    enum Ability ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];

    switch (ability)
    {
    case ABILITY_TRACE:
        if (!gBattleMons[battler].volatiles.traceActivated)
        {
            enum BattlerId chosenTarget;
            enum BattlerId target1;
            enum BattlerId target2;

            // TODO: use GetLeftBattler / GetRightBattler
            enum BattleSide side = (GetBattlerSide(battler) ^ BIT_SIDE);
            target1 = GetBattlerAtPosition((enum BattlerPosition)side);
            target2 = GetBattlerAtPosition((enum BattlerPosition)side + BIT_FLANK);
            if (IsDoubleBattle())
            {
                if (!gAbilitiesInfo[gBattleMons[target1].ability].cantBeTraced && gBattleMons[target1].hp != 0
                    && !gAbilitiesInfo[gBattleMons[target2].ability].cantBeTraced && gBattleMons[target2].hp != 0)
                {
                    chosenTarget = GetBattlerAtPosition((RandomPercentage(RNG_TRACE, 50) * 2) | side);
                    effect = TRUE;
                }
                else if (!gAbilitiesInfo[gBattleMons[target1].ability].cantBeTraced && gBattleMons[target1].hp != 0)
                {
                    chosenTarget = target1;
                    effect = TRUE;
                }
                else if (!gAbilitiesInfo[gBattleMons[target2].ability].cantBeTraced && gBattleMons[target2].hp != 0)
                {
                    chosenTarget = target2;
                    effect = TRUE;
                }
            }
            else if (!gAbilitiesInfo[gBattleMons[target1].ability].cantBeTraced && gBattleMons[target1].hp != 0)
            {
                chosenTarget = target1;
                effect = TRUE;
            }

            if (effect)
            {
                gBattleMons[battler].volatiles.traceActivated = TRUE;
                if (GetBattlerHoldEffectIgnoreAbility(battler) == HOLD_EFFECT_ABILITY_SHIELD)
                    break;
                BattleScriptCall(BattleScript_TraceActivates);
                gBattleStruct->tracedAbility[battler] = gLastUsedAbility = gBattleMons[chosenTarget].ability;
                RecordAbilityBattle(chosenTarget, gLastUsedAbility); // Record the opposing battler has this ability
                PREPARE_MON_NICK_WITH_PREFIX_LOWER_BUFFER(gBattleTextBuff1, chosenTarget, gBattlerPartyIndexes[chosenTarget])
                PREPARE_ABILITY_BUFFER(gBattleTextBuff2, gLastUsedAbility)
            }
        }
        break;
    case ABILITY_IMPOSTER:
        if (gBattleStruct->battlerState[battler].switchIn)
        {
            enum BattlerId diagonalBattler = GetOppositeBattler(battler);
            if (IsDoubleBattle())
                diagonalBattler = GetPartnerBattler(diagonalBattler);

            // Imposter only activates when the battler first switches in
            if (!gBattleMons[battler].volatiles.overwrittenAbility
                && IsBattlerAlive(diagonalBattler)
                && !gBattleMons[diagonalBattler].volatiles.substitute
                && !gBattleMons[diagonalBattler].volatiles.transformed
                && !gBattleMons[battler].volatiles.transformed
                && gBattleStruct->illusion[diagonalBattler].state != ILLUSION_ON
                && !IsSemiInvulnerable(diagonalBattler, EXCLUDE_COMMANDER))
            {
                gEffectBattler = battler;
                gBattleScripting.battler = diagonalBattler;
                BattleScriptCall(BattleScript_ImposterActivates);
                effect = TRUE;
            }
        }
        break;
    case ABILITY_MOLD_BREAKER:
        if (cv->shouldAbilityTrigger)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_MOLDBREAKER;
            BattleScriptCall(BattleScript_SwitchInAbilityMsg);
            effect = TRUE;
        }
        break;
    case ABILITY_TERAVOLT:
        if (cv->shouldAbilityTrigger)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_TERAVOLT;
            BattleScriptCall(BattleScript_SwitchInAbilityMsg);
            effect = TRUE;
        }
        break;
    case ABILITY_TURBOBLAZE:
        if (cv->shouldAbilityTrigger)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_TURBOBLAZE;
            BattleScriptCall(BattleScript_SwitchInAbilityMsg);
            effect = TRUE;
        }
        break;
    case ABILITY_SLOW_START:
        if (cv->shouldAbilityTrigger)
        {
            gBattleMons[battler].volatiles.slowStartTimer = B_SLOW_START_TIMER;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_SLOWSTART;
            BattleScriptCall(BattleScript_SwitchInAbilityMsg);
            effect = TRUE;
        }
        break;
    case ABILITY_CURIOUS_MEDICINE:
        if (cv->shouldAbilityTrigger
         && IsDoubleBattle()
         && IsBattlerAlive(GetPartnerBattler(battler))
         && TryResetBattlerStatChanges(GetPartnerBattler(battler)))
        {
            gEffectBattler = GetPartnerBattler(battler);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_CURIOUS_MEDICINE;
            BattleScriptCall(BattleScript_SwitchInAbilityMsg);
            effect = TRUE;
        }
        break;
    case ABILITY_PASTEL_VEIL:
        if (cv->shouldAbilityTrigger)
        {
            gEffectBattler = battler;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_PASTEL_VEIL;
            BattleScriptCall(BattleScript_PastelVeilActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_ANTICIPATION:
        if (cv->shouldAbilityTrigger)
        {
            struct DamageContext ctx = {0};
            uq4_12_t modifier = UQ_4_12(1.0);
            for (enum BattlerId i = 0; i < gBattlersCount; i++)
            {
                if (IsBattlerAlive(i) && !IsBattlerAlly(i, battler))
                {
                    for (u32 moveSlot = 0; moveSlot < MAX_MON_MOVES; moveSlot++)
                    {
                        enum Move move = gBattleMons[i].moves[moveSlot];
                        enum BattleMoveEffects moveEffect = GetMoveEffect(move);
                        enum Type moveType = GetBattleMoveType(move);

                        ctx.battlerAtk = i;
                        ctx.battlerDef = battler;
                        ctx.move = ctx.chosenMove = ctx.baseMove = move;
                        ctx.moveType = moveType;
                        ctx.isAnticipation = TRUE;
                        modifier = CalcTypeEffectivenessMultiplier(&ctx);

                        if (modifier >= UQ_4_12(2.0) || moveEffect == EFFECT_OHKO)
                        {
                            effect = TRUE;
                            break;
                        }
                    }
                }
            }

            if (effect)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_ANTICIPATION;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
            }
        }
        break;
    case ABILITY_FRISK:
        if (cv->shouldAbilityTrigger)
        {
            enum BattlerId battlerDef = B_BATTLER_0;

            for (battlerDef = B_BATTLER_0; battlerDef < gBattlersCount; battlerDef++)
            {
                if (IsBattlerAlly(battler, battlerDef) || !IsBattlerAlive(battlerDef))
                    continue;
                if (gBattleMons[battlerDef].item != ITEM_NONE)
                    break;
            }

            if (battlerDef == gBattlersCount)
                break; // no item found

            gBattlerAbility = gEffectBattler = battler;
            BattleScriptCall(BattleScript_FriskActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_FOREWARN:
        if (cv->shouldAbilityTrigger && !IsOpposingSideEmpty(battler))
        {
            ForewarnChooseMove(battler);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_FOREWARN;
            BattleScriptCall(BattleScript_SwitchInAbilityMsg);
            effect = TRUE;
        }
        break;
    case ABILITY_DOWNLOAD:
        if (cv->shouldAbilityTrigger)
        {
            enum Stat statId = GetDownloadStat(battler);

            if (CompareStat(battler, statId, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, statId, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect = TRUE;
            }
        }
        break;
    case ABILITY_PRESSURE:
        if (cv->shouldAbilityTrigger)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_PRESSURE;
            BattleScriptCall(BattleScript_SwitchInAbilityMsg);
            effect = TRUE;
        }
        break;
    case ABILITY_DARK_AURA:
        if (cv->shouldAbilityTrigger)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_DARKAURA;
            BattleScriptCall(BattleScript_SwitchInAbilityMsg);
            effect = TRUE;
        }
        break;
    case ABILITY_FAIRY_AURA:
        if (cv->shouldAbilityTrigger)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_FAIRYAURA;
            BattleScriptCall(BattleScript_SwitchInAbilityMsg);
            effect = TRUE;
        }
        break;
    case ABILITY_AURA_BREAK:
        if (cv->shouldAbilityTrigger)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_AURABREAK;
            BattleScriptCall(BattleScript_SwitchInAbilityMsg);
            effect = TRUE;
        }
        break;
    case ABILITY_COMATOSE:
        if (cv->shouldAbilityTrigger)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_COMATOSE;
            BattleScriptCall(BattleScript_SwitchInAbilityMsg);
            effect = TRUE;
        }
        break;
    case ABILITY_SCREEN_CLEANER:
        if (cv->shouldAbilityTrigger && TryRemoveScreens(battler))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_SCREENCLEANER;
            BattleScriptCall(BattleScript_SwitchInAbilityMsg);
            effect = TRUE;
        }
        break;
    case ABILITY_DRIZZLE:
        if (cv->shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_RAIN, ability))
            effect = TRUE;
        break;
    case ABILITY_SAND_STREAM:
        if (cv->shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_SANDSTORM, ability))
            effect = TRUE;
        break;
    case ABILITY_DROUGHT:
    case ABILITY_ORICHALCUM_PULSE:
        if (cv->shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_SUN, ability))
            effect = TRUE;
        break;
    case ABILITY_SNOW_WARNING:
        if (cv->shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, GetConfig(B_SNOW_WARNING) >= GEN_9 ? BATTLE_WEATHER_SNOW : BATTLE_WEATHER_HAIL, ability))
            effect = TRUE;
        break;
    case ABILITY_ELECTRIC_SURGE:
        if (!cv->shouldAbilityTrigger)
            break;
        if (TryChangeBattleTerrain(battler, B_TERRAIN_ELECTRIC))
        {
            BattleScriptCall(BattleScript_ElectricSurgeActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_HADRON_ENGINE:
        if (!cv->shouldAbilityTrigger)
            break;
        if (gFieldTimers.terrain == B_TERRAIN_ELECTRIC)
        {
            BattleScriptCall(BattleScript_HadronEngineActivatesInTerrain);
            effect = TRUE;
        }
        else if (TryChangeBattleTerrain(battler, B_TERRAIN_ELECTRIC))
        {
            BattleScriptCall(BattleScript_HadronEngineActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_GRASSY_SURGE:
        if (!cv->shouldAbilityTrigger)
            break;
        if (TryChangeBattleTerrain(battler, B_TERRAIN_GRASSY))
        {
            BattleScriptCall(BattleScript_GrassySurgeActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_MISTY_SURGE:
        if (!cv->shouldAbilityTrigger)
            break;
        if (TryChangeBattleTerrain(battler, B_TERRAIN_MISTY))
        {
            BattleScriptCall(BattleScript_MistySurgeActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_PSYCHIC_SURGE:
        if (!cv->shouldAbilityTrigger)
            break;
        if (TryChangeBattleTerrain(battler, B_TERRAIN_PSYCHIC))
        {
            BattleScriptCall(BattleScript_PsychicSurgeActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_INTIMIDATE:
        if (cv->shouldAbilityTrigger && !IsOpposingSideEmpty(battler))
        {
            gEffectBattler = battler;
            gBattleStruct->intimidateActivated = TRUE; // For rattled and Adrenaile Orb
            for (enum BattlerId i = 0; i < gBattlersCount; i++)
            {
                if (IsBattlerAlly(battler, i) || !IsBattlerAlive(i))
                    continue;
                SetStatChange(i, STAT_ATK, -1);
            }
            BattleScriptCall(BattleScript_IntimidateActivates); // Sets a flag to check for intim failure. Similar abilities should use BattleScript_AbilityStatChange.
            effect = TRUE;
        }
        break;
    case ABILITY_SUPERSWEET_SYRUP:
        if (cv->shouldAbilityTrigger
         && !GetBattlerPartyState(battler)->supersweetSyrup
         && !IsOpposingSideEmpty(battler))
        {
            gEffectBattler = battler;
            GetBattlerPartyState(battler)->supersweetSyrup = TRUE;
            for (enum BattlerId i = 0; i < gBattlersCount; i++)
            {
                if (IsBattlerAlly(battler, i) || !IsBattlerAlive(i))
                    continue;
                SetStatChange(i, STAT_EVASION, -1);
            }
            BattleScriptCall(BattleScript_SupersweetSyrupActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_CLOUD_NINE:
    case ABILITY_AIR_LOCK:
        if (cv->shouldAbilityTrigger)
        {
            BattleScriptCall(BattleScript_AnnounceAirLockCloudNine);
            effect = TRUE;
        }
        break;
    case ABILITY_INTREPID_SWORD:
        if (cv->shouldAbilityTrigger && !GetBattlerPartyState(battler)->intrepidSwordBoost)
        {
            if (GetConfig(B_INTREPID_SWORD) >= GEN_9)
                GetBattlerPartyState(battler)->intrepidSwordBoost = TRUE;

            if (CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_ATK, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect = TRUE;
            }
        }
        break;
    case ABILITY_DAUNTLESS_SHIELD:
        if (cv->shouldAbilityTrigger && !GetBattlerPartyState(battler)->dauntlessShieldBoost)
        {
            if (GetConfig(B_DAUNTLESS_SHIELD) >= GEN_9)
                GetBattlerPartyState(battler)->dauntlessShieldBoost = TRUE;

            if (CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_DEF, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect = TRUE;
            }
        }
        break;
    case ABILITY_WIND_RIDER:
        if (cv->shouldAbilityTrigger
         && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, ability)
         && gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_TAILWIND)
        {
            gEffectBattler = gBattlerAbility = battler;
            SetStatChange(battler, STAT_ATK, 1);
            BattleScriptCall(BattleScript_AbilityStatChange);
            effect = TRUE;
        }
        break;
    case ABILITY_DESOLATE_LAND:
        if (cv->shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_SUN_PRIMAL, ability))
            effect = TRUE;
        break;
    case ABILITY_PRIMORDIAL_SEA:
        if (cv->shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_RAIN_PRIMAL, ability))
            effect = TRUE;
        break;
    case ABILITY_DELTA_STREAM:
        if (cv->shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_STRONG_WINDS, ability))
            effect = TRUE;
        break;
    case ABILITY_VESSEL_OF_RUIN:
        if (cv->shouldAbilityTrigger)
        {
            gBattleMons[battler].volatiles.vesselOfRuin = TRUE;
            PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_SPATK);
            BattleScriptCall(BattleScript_RuinAbilityActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_SWORD_OF_RUIN:
        if (cv->shouldAbilityTrigger)
        {
            gBattleMons[battler].volatiles.swordOfRuin = TRUE;
            PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_DEF);
            BattleScriptCall(BattleScript_RuinAbilityActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_TABLETS_OF_RUIN:
        if (cv->shouldAbilityTrigger)
        {
            gBattleMons[battler].volatiles.tabletsOfRuin = TRUE;
            PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_ATK);
            BattleScriptCall(BattleScript_RuinAbilityActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_BEADS_OF_RUIN:
        if (cv->shouldAbilityTrigger)
        {
            gBattleMons[battler].volatiles.beadsOfRuin = TRUE;
            PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_SPDEF);
            BattleScriptCall(BattleScript_RuinAbilityActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_SUPREME_OVERLORD:
        if (cv->shouldAbilityTrigger)
        {
            gBattleMons[battler].volatiles.supremeOverlordCounter = min(5, gBattleStruct->faintCounter[GetBattlerTrainer(battler)]);
            if (gBattleMons[battler].volatiles.supremeOverlordCounter > 0)
            {
                BattleScriptCall(BattleScript_SupremeOverlordActivates);
                effect = TRUE;
            }
        }
        break;
    case ABILITY_ZERO_TO_HERO:
        if (GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES) == SPECIES_PALAFIN_HERO
         && !GetBattlerPartyState(battler)->transformZeroToHero)
        {
            GetBattlerPartyState(battler)->transformZeroToHero = TRUE;
            BattleScriptCall(BattleScript_ZeroToHeroActivates);
            effect = TRUE;
        }
        break;
    case ABILITY_EMBODY_ASPECT_TEAL_MASK:
    case ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK:
    case ABILITY_EMBODY_ASPECT_WELLSPRING_MASK:
    case ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK:
        if (cv->shouldAbilityTrigger && !gBattleMons[battler].volatiles.embodyAspectActivated)
        {
            enum Stat stat;
            gBattleMons[battler].volatiles.embodyAspectActivated = TRUE;

            if (ability == ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK)
                stat = STAT_ATK;
            else if (ability == ABILITY_EMBODY_ASPECT_WELLSPRING_MASK)
                stat = STAT_SPDEF;
            else if (ability == ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK)
                stat = STAT_DEF;
            else //ABILITY_EMBODY_ASPECT_TEAL_MASK
                stat = STAT_SPEED;

            if (CompareStat(battler, stat, MAX_STAT_STAGE, CMP_EQUAL, ability))
                break;

            gEffectBattler = gBattlerAbility = battler;
            SetStatChange(battler, stat, 1);
            BattleScriptCall(BattleScript_AbilityStatChange);
            effect = TRUE;
        }
        break;
    default:
        break;
    }

    return effect;
}

static bool32 TrySwitchInFormChangeAbility(struct BattleCalcValues *cv)
{
    if (cv->shouldAbilityTrigger && TryBattleFormChange(cv->battlerAtk, FORM_CHANGE_BATTLE_HP_PERCENT_SEND_OUT, cv->abilities[cv->battlerAtk]))
    {
        gBattleScripting.battler = gBattlerAbility = cv->battlerAtk;
        // To prevent the new form's ability from pop up
        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = cv->abilities[cv->battlerAtk];
        BattleScriptCall(BattleScript_BattlerFormChange);
        return TRUE;
    }
    return FALSE;
}

static bool32 TryDependsOnAllyAbility(struct BattleCalcValues *cv)
{
    enum BattlerId battler = gBattleScripting.battler = gBattlerAbility = cv->battlerAtk;
    enum BattlerId partner = GetPartnerBattler(battler);

    enum Ability ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];

    switch (ability)
    {
    case ABILITY_COMMANDER:
        if (IsBattlerAlive(partner)
         && !HasPartnerTrainer(battler)
         && gBattleStruct->battlerState[partner].commanderSpecies == SPECIES_NONE
         && gBattleMons[partner].species == SPECIES_DONDOZO
         && (gChosenActionByBattler[battler] != B_ACTION_SWITCH || HasBattlerActedThisTurn(battler))
         && (gChosenActionByBattler[partner] != B_ACTION_SWITCH || HasBattlerActedThisTurn(partner))
         && GetBaseSpecies(GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES)) == SPECIES_TATSUGIRI)
        {
            PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, partner, gBattlerPartyIndexes[partner]);
            gBattleStruct->battlerState[battler].commandingDondozo = TRUE;
            gBattleStruct->battlerState[partner].commanderSpecies = gBattleMons[battler].species;
            gBattleMons[battler].volatiles.semiInvulnerable = STATE_COMMANDER;
            if ((gBattleStruct->gimmick.toActivate & (1u << battler)) && gBattleStruct->gimmick.usableGimmick[battler] != GIMMICK_NONE)
                gBattleStruct->gimmick.toActivate &= ~(1u << battler);

            struct Volatiles *vol = &gBattleMons[battler].volatiles;
            if (vol->confusionTimer > 0 && vol->confusionTimer != PERMANENT_VOLATILE)
                vol->confusionTimer--;

            BtlController_EmitSpriteInvisibility(battler, B_COMM_TO_CONTROLLER, TRUE);
            MarkBattlerForControllerExec(battler);
            SetStatChange(partner, STAT_ATK, 2);
            SetStatChange(partner, STAT_DEF, 2);
            SetStatChange(partner, STAT_SPATK, 2);
            SetStatChange(partner, STAT_SPDEF, 2);
            SetStatChange(partner, STAT_SPEED, 2);

            gEffectBattler = partner;
            BattleScriptCall(BattleScript_CommanderActivates);
            return TRUE;
        }
        break;
    case ABILITY_HOSPITALITY:
        if (cv->shouldAbilityTrigger
         && IsDoubleBattle()
         && !gBattleMons[partner].volatiles.healBlockTimer
         && gBattleMons[partner].hp < gBattleMons[partner].maxHP
         && IsBattlerAlive(partner))
        {
            SetHealAmount(partner, GetNonDynamaxMaxHP(partner) / 4);
            gBattleScripting.battler = battler;
            gEffectBattler = partner;
            BattleScriptCall(BattleScript_HospitalityActivates);
            return TRUE;
        }
        break;
    case ABILITY_COSTAR:
        if (cv->shouldAbilityTrigger
         && IsDoubleBattle()
         && IsBattlerAlive(partner)
         && BattlerHasCopyableChanges(partner))
        {
            for (enum Stat stat = 0; stat < NUM_BATTLE_STATS; stat++)
                gBattleMons[battler].statStages[stat] = gBattleMons[partner].statStages[stat];
            // Copy crit boosts (Focus Energy, Dragon Cheer, G-Max Chi Strike)
            gBattleMons[battler].volatiles.criticalHitBoost = gBattleMons[partner].volatiles.criticalHitBoost;
            gBattleMons[battler].volatiles.bonusCritStages = gBattleMons[partner].volatiles.bonusCritStages;
            gEffectBattler = partner;
            BattleScriptCall(BattleScript_CostarActivates);
            return TRUE;
        }
        break;
    default:
        break;
    }

    return FALSE;
}

static bool32 TryOnWeatherAbility(struct BattleCalcValues *cv)
{
    enum BattlerId battler = gBattlerAbility = cv->battlerAtk;
    enum Ability ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];

    switch (ability)
    {
    case ABILITY_FORECAST:
    case ABILITY_FLOWER_GIFT:
    case ABILITY_ICE_FACE:
    {
        u32 weather = GetWeather();
        bool32 battlerWeatherAffected = IsBattlerWeatherAffected(cv->holdEffects[battler], weather, gBattleWeather);

        if (battlerWeatherAffected && !CanBattlerFormChange(battler, FORM_CHANGE_BATTLE_WEATHER))
        {
            // If Hail/Snow activates when in Eiscue is in base, prevent reversion when Eiscue Noice gets broken
            gBattleMons[battler].volatiles.weatherAbilityDone = TRUE;
        }

        if (((!gBattleMons[battler].volatiles.weatherAbilityDone && battlerWeatherAffected) || weather == B_WEATHER_NONE)
         && TryBattleFormChange(battler, FORM_CHANGE_BATTLE_WEATHER, ability))
        {
            gBattleScripting.battler = battler;
            gBattleMons[battler].volatiles.weatherAbilityDone = TRUE;
            BattleScriptCall(BattleScript_BattlerFormChangeWithString);
            return TRUE;
        }
        break;
    }
    case ABILITY_PROTOSYNTHESIS:
        if (!gBattleMons[battler].volatiles.weatherAbilityDone
         && (GetWeather() & B_WEATHER_SUN)
         && !gBattleMons[battler].volatiles.transformed
         && !gBattleMons[battler].volatiles.boosterEnergyActivated)
        {
            gBattleMons[battler].volatiles.weatherAbilityDone = TRUE;
            gBattleMons[battler].volatiles.paradoxBoostedStat = GetParadoxHighestStatId(battler);
            PREPARE_STAT_BUFFER(gBattleTextBuff1, gBattleMons[battler].volatiles.paradoxBoostedStat);
            gBattleScripting.battler = battler;
            BattleScriptCall(BattleScript_ProtosynthesisActivates);
            return TRUE;
        }
        break;
    default:
        break;
    }
    return FALSE;
}

static bool32 TryOnTerrainAbility(struct BattleCalcValues *cv)
{
    enum BattlerId battler = gBattlerAbility = cv->battlerAtk;
    enum Ability ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];

    switch (ability)
    {
    case ABILITY_MIMICRY:
        if (!gBattleMons[battler].volatiles.terrainAbilityDone && ChangeTypeBasedOnTerrain(battler))
        {
            gBattleMons[battler].volatiles.terrainAbilityDone = TRUE;
            ChangeTypeBasedOnTerrain(battler);
            gBattleScripting.battler = battler;
            BattleScriptCall(BattleScript_MimicryActivates);
            return TRUE;
        }
        break;
    case ABILITY_QUARK_DRIVE:
        if (!gBattleMons[battler].volatiles.terrainAbilityDone
         && gFieldTimers.terrain == B_TERRAIN_ELECTRIC
         && !gBattleMons[battler].volatiles.transformed
         && !gBattleMons[battler].volatiles.boosterEnergyActivated)
        {
            gBattleMons[battler].volatiles.terrainAbilityDone = TRUE;
            gBattleMons[battler].volatiles.paradoxBoostedStat = GetParadoxHighestStatId(battler);
            PREPARE_STAT_BUFFER(gBattleTextBuff1, gBattleMons[battler].volatiles.paradoxBoostedStat);
            gBattleScripting.battler = battler;
            BattleScriptCall(BattleScript_QuarkDriveActivates);
            return TRUE;
        }
        break;
    default:
        break;
    }
    return FALSE;
}

static bool32 TryOpportunistAbility(struct BattleCalcValues *cv)
{
    enum BattlerId battler = cv->battlerAtk;
    enum Ability ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];

    switch (ability)
    {
    case ABILITY_OPPORTUNIST:
        if (gProtectStructs[battler].activateOpportunist)
        {
            for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
            {
                u32 queuedStat = stat - 1;
                if (gQueuedStatBoosts[battler].stats & (1 << queuedStat))
                    SetStatChange(battler, stat, gQueuedStatBoosts[battler].statChanges[queuedStat]);

            }
            gBattleScripting.battler = gBattlerAbility = battler;
            gProtectStructs[battler].activateOpportunist = FALSE;
            BattleScriptCall(BattleScript_OpportunistCopyStatChange);
            return TRUE;
        }
        break;
    default:
        break;
    }
    return FALSE;
}

bool32 AbilityBattleEffects(enum AbilityEffect caseID, struct BattleCalcValues *cv)
{
    bool32 effect = FALSE;

    if (HasAnyBattleFlags(BATTLE_TYPE_SAFARI))
        return 0;

    switch (caseID)
    {
    case ABILITYEFFECT_ENDTURN:
        effect = TryEndturnAbility(cv);
        break;
    case ABILITYEFFECT_MOVE_END_ATTACKER:
        effect = TryMoveEndAttackerAbility(cv);
        break;
    case ABILITYEFFECT_COLOR_CHANGE:
        effect = TryColorChangeAbility(cv);
        break;
    case ABILITYEFFECT_MOVE_END_HIT_TARGET:
        effect = TryMoveEndAbility(cv);
        break;
    case ABILITYEFFECT_FORM_CHANGE_ON_HIT:
        effect = TryFormChangeOnHitAbility(cv);
        break;
    case ABILITYEFFECT_DANCER:
        effect = TryDancerAbility(cv);
        break;
    case ABILITYEFFECT_MOVE_END_FOES_FAINTED:
        effect = TryMoveEndFoesFaintedAbility(cv);
        break;
    case ABILITYEFFECT_RECEIVER:
        effect = TryReceiverAbility(cv);
        break;
    case ABILITYEFFECT_ON_FAINT:
        effect = TryOnFaintAbility(cv);
        break;
    case ABILITYEFFECT_ON_FORM_CHANGE:
        effect = TryOnFormChangeAbility(cv);
        break;
    case ABILITYEFFECT_ON_STATUS_CHANGE:
        effect = TryOnStatusChangeAbility(cv);
        break;
    case ABILITYEFFECT_TERA_SHIFT:
        effect = TryTeraShiftAbility(cv);
        break;
    case ABILITYEFFECT_NEUTRALIZINGGAS:
        effect = TryNeutralizinggasAbility(cv);
        break;
    case ABILITYEFFECT_UNNERVE:
        effect = TryUnnerveAbility(cv);
        break;
    case ABILITYEFFECT_ON_SWITCHIN:
        effect = TryOnSwitchInAbility(cv);
        break;
    case ABILITYEFFECT_SWITCH_IN_FORM_CHANGE:
        effect = TrySwitchInFormChangeAbility(cv);
        break;
    case ABILITYEFFECT_DEPENDS_ON_ALLY:
        effect = TryDependsOnAllyAbility(cv);
        break;
    case ABILITYEFFECT_ON_WEATHER: // For ability effects that activate when the battle weather changes.
        effect = TryOnWeatherAbility(cv);
        break;
    case ABILITYEFFECT_ON_TERRAIN:  // For ability effects that activate when the field terrain changes.
        effect = TryOnTerrainAbility(cv);
        break;
    case ABILITYEFFECT_IMMUNITY:
        effect = TryImmunityAbility(cv);
        break;
    case ABILITYEFFECT_OPPORTUNIST:
        effect = TryOpportunistAbility(cv);
        break;
    }

    if (effect)
    {
        RecordAbilityBattle(gBattlerAbility , gLastUsedAbility);
    }

    return effect;
}

bool32 AbilityBattleEffectsHelper(enum AbilityEffect caseID, enum BattlerId abilityBattler, enum Ability ability, enum Move move, bool32 shouldAbilityTrigger)
{
    struct BattleCalcValues cv = {
        .move = move,
        .battlerAtk = abilityBattler,
        .shouldAbilityTrigger = shouldAbilityTrigger,
    };
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (battler == abilityBattler)
            cv.abilities[battler] = ability;
        else
            cv.abilities[battler] = GetBattlerAbility(battler);
        cv.holdEffects[battler] = GetBattlerHoldEffectInternal(battler, cv.abilities[battler]);
    }
    return AbilityBattleEffects(caseID, &cv);
}

static bool32 IsRestrictedAbility(enum BattlerId battler, enum Ability ability)
{
    return GetSpeciesAbility(gBattleMons[battler].species, 0) == ability
        || GetSpeciesAbility(gBattleMons[battler].species, 1) == ability
        || GetSpeciesAbility(gBattleMons[battler].species, 2) == ability;
}

static bool32 TryRemoveScreens(enum BattlerId battler)
{
    bool32 removed = FALSE;
    u32 battlerSide = GetBattlerSide(battler);
    u8 enemySide = GetBattlerSide(GetOppositeBattler(battler));

    // try to remove from battler's side
    if (gSideStatuses[battlerSide] & SIDE_STATUS_SCREEN_ANY)
    {
        gSideStatuses[battlerSide] &= ~SIDE_STATUS_SCREEN_ANY;
        removed = TRUE;
    }

    // try to remove from battler opponent's side
    if (gSideStatuses[enemySide] & SIDE_STATUS_SCREEN_ANY)
    {
        gSideStatuses[enemySide] &= ~SIDE_STATUS_SCREEN_ANY;
        removed = TRUE;
    }

    return removed;
}

static void ForewarnChooseMove(enum BattlerId battler)
{
    struct Forewarn {
        enum BattlerId battler;
        u8 power;
        enum Move moveId;
    };
    u32 i, j, bestId, count;
    struct Forewarn *data = Alloc(sizeof(struct Forewarn) * MAX_BATTLERS_COUNT * MAX_MON_MOVES);

    // Put all moves
    for (count = 0, i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (IsBattlerAlive(i) && !IsBattlerAlly(i, battler))
        {
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (gBattleMons[i].moves[j] == MOVE_NONE)
                    continue;
                data[count].moveId = gBattleMons[i].moves[j];
                data[count].battler = i;
                switch (GetMoveEffect(data[count].moveId))
                {
                case EFFECT_OHKO:
                    data[count].power = 150;
                    break;
                case EFFECT_REFLECT_DAMAGE:
                    data[count].power = 120;
                    break;
                default:
                {
                    u32 movePower = GetMovePower(data[count].moveId);
                    if (movePower == 1)
                        data[count].power = 80;
                    else
                        data[count].power = movePower;
                    break;
                }
                }
                count++;
            }
        }
    }

    if (count == 0)
    {
        Free(data);
        return;
    }

    u32 tieCount = 1;
    u8 bestPower = data[0].power;

    bestId = 0;
    for (i = 1; i < count; i++)
    {
        if (data[i].power > bestPower)
        {
            bestPower = data[i].power;
            bestId = i;
            tieCount = 1;
        }
        else if (data[i].power == bestPower)
        {
            tieCount++;
        }
    }

    if (tieCount > 1)
    {
        u32 tieIndex = RandomUniform(RNG_FOREWARN, 0, tieCount - 1);
        for (i = 0, bestId = 0; i < count; i++)
        {
            if (data[i].power != bestPower)
                continue;
            if (tieIndex-- == 0)
            {
                bestId = i;
                break;
            }
        }
    }

    gEffectBattler = data[bestId].battler;
    PREPARE_MOVE_BUFFER(gBattleTextBuff1, data[bestId].moveId)
    RecordKnownMove(data[bestId].battler, data[bestId].moveId);

    Free(data);
}

static bool32 IsOpposingSideEmpty(enum BattlerId battler)
{
    enum BattlerId oppositeBattler = GetOppositeBattler(battler);

    if (IsBattlerAlive(oppositeBattler))
        return FALSE;

    if (!IsDoubleBattle())
        return TRUE;

    if (IsBattlerAlive(GetPartnerBattler(oppositeBattler)))
        return FALSE;

    return TRUE;
}

static bool32 TryChangeWeatherWithAbility(enum BattlerId battler, u32 battleWeather, enum Ability ability)
{
    switch (TryChangeBattleWeather(battler, battleWeather, ability))
    {
    case WEATHER_FAILURE_SAME_WEATHER:
        if (ability == ABILITY_ORICHALCUM_PULSE)
        {
            BattleScriptCall(BattleScript_OrichalcumPulseActivatesInSun);
            return TRUE;
        }
        return FALSE;
    case WEATHER_FAILURE_OVERWORLD:
        BattleScriptCall(BattleScript_BlockedByOverworldWeather);
        return TRUE;
    case WEATHER_FAILURE_PRIMAL:
        BattleScriptCall(BattleScript_BlockedByPrimalWeather);
        return TRUE;
    case WEATHER_FAILURE_SUCCESS:
        if (ability == ABILITY_ORICHALCUM_PULSE)
            BattleScriptCall(BattleScript_OrichalcumPulseActivates);
        else
            BattleScriptCall(BattleScript_WeatherAbilityActivates);
        return TRUE;
    }
    return FALSE;
}

u32 NumFaintedBattlersByAttacker(enum BattlerId battlerAtk)
{
    u32 numMonsFainted = 0;

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (battler == battlerAtk)
            continue;

        if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES) && !IsBattlerAlive(battler))
            numMonsFainted++;
    }

    return numMonsFainted;
}

// Not enum BattlerId to allow using it with RandomUniformExcept
static bool32 CantPickupItem(u32 _battler)
{
    enum BattlerId battler = _battler;
    // Used by RandomUniformExcept() for RNG_PICKUP
    if (battler == gBattlerAttacker && (GetConfig(B_PICKUP_WILD) < GEN_9 || HasAnyBattleFlags(BATTLE_TYPE_TRAINER | BATTLE_TYPE_LINK)))
        return TRUE;
    return !(IsBattlerAlive(battler) && GetBattlerPartyState(battler)->usedHeldItem && gBattleStruct->battlerState[battler].canPickupItem);
}

static bool32 PickupHasValidTarget(enum BattlerId battler)
{
    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        if (!CantPickupItem(i))
            return TRUE;
    }
    return FALSE;
}
