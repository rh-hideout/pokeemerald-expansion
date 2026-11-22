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
static bool32 TryDancer(void);
static bool32 TryRemoveScreens(enum BattlerId battler);
static void ForewarnChooseMove(enum BattlerId battler);
static bool32 TryChangeWeatherWithAbility(enum BattlerId battler, u32 battleWeather, enum Ability ability);
u32 NumFaintedBattlersByAttacker(enum BattlerId battlerAtk);
enum ImmunityHealStatusOutcome TryImmunityAbilityHealStatus(enum BattlerId battler, enum Ability ability);

u32 AbilityBattleEffects2(enum AbilityEffect caseID, enum BattlerId abilityBattler, enum Ability ability, enum Move move, bool32 shouldAbilityTrigger)
{
    struct BattleCalcValues cv = {
        .move = move,
        .battlerAtk = abilityBattler,
    };
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (battler == abilityBattler)
            cv.abilities[battler] = ability;
        else
            cv.abilities[battler] = GetBattlerAbility(battler);

        cv.holdEffects[battler] = GetBattlerHoldEffect(battler);
    }
    return AbilityBattleEffects(&cv, caseID, shouldAbilityTrigger);
}

u32 AbilityBattleEffects(struct BattleCalcValues *cv, enum AbilityEffect caseID, bool32 shouldAbilityTrigger)
{
    u32 effect = 0;
    enum Type moveType = 0;
    u32 side = 0;
    u32 i = 0, j = 0;
    u32 partner = 0;
    enum Species speciesForm = SPECIES_NONE;

    if (HasAnyBattleFlags(BATTLE_TYPE_SAFARI))
        return 0;

    enum BattlerId battler;
    enum Ability ability;
    enum Move move = cv->move;

    moveType = GetBattleMoveType(move);

    switch (caseID)
    {
    case ABILITYEFFECT_ON_FORM_CHANGE:
        battler = gBattlerAbility = cv->battlerAtk;
        ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];
        switch (ability)
        {
        case ABILITY_TERAFORM_ZERO:
            if (gBattleStruct->overworldWeatherPresent)
            {
                if (gFieldTimers.terrain != B_TERRAIN_NONE)
                    BattleScriptCall(BattleScript_ActivateTeraformZeroRemovesOnlyTerrain);
                else
                    BattleScriptCall(BattleScript_BlockedByOverworldWeather);
                effect++;
            }
            else if (gBattleWeather != WEATHER_NONE || gFieldTimers.terrain != B_TERRAIN_NONE)
            {
                BattleScriptCall(BattleScript_ActivateTeraformZero);
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_ON_SWITCHIN:
        battler = gBattlerAbility = gBattleScripting.battler = cv->battlerAtk;
        ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];
        switch (ability)
        {
        case ABILITY_TRACE:
            if (!gBattleMons[battler].volatiles.traceActivated)
            {
                enum BattlerId chosenTarget;
                enum BattlerId target1;
                enum BattlerId target2;

                side = (GetBattlerSide(battler) ^ BIT_SIDE);
                target1 = GetBattlerAtPosition(side);
                target2 = GetBattlerAtPosition(side + BIT_FLANK);
                if (IsDoubleBattle())
                {
                    if (!gAbilitiesInfo[gBattleMons[target1].ability].cantBeTraced && gBattleMons[target1].hp != 0
                        && !gAbilitiesInfo[gBattleMons[target2].ability].cantBeTraced && gBattleMons[target2].hp != 0)
                        chosenTarget = GetBattlerAtPosition((RandomPercentage(RNG_TRACE, 50) * 2) | side), effect++;
                    else if (!gAbilitiesInfo[gBattleMons[target1].ability].cantBeTraced && gBattleMons[target1].hp != 0)
                        chosenTarget = target1, effect++;
                    else if (!gAbilitiesInfo[gBattleMons[target2].ability].cantBeTraced && gBattleMons[target2].hp != 0)
                        chosenTarget = target2, effect++;
                }
                else
                {
                    if (!gAbilitiesInfo[gBattleMons[target1].ability].cantBeTraced && gBattleMons[target1].hp != 0)
                        chosenTarget = target1, effect++;
                }

                if (effect != 0)
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
                    effect++;
                }
            }
            break;
        case ABILITY_MOLD_BREAKER:
            if (shouldAbilityTrigger)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_MOLDBREAKER;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_TERAVOLT:
            if (shouldAbilityTrigger)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_TERAVOLT;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_TURBOBLAZE:
            if (shouldAbilityTrigger)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_TURBOBLAZE;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_SLOW_START:
            if (shouldAbilityTrigger)
            {
                gBattleMons[battler].volatiles.slowStartTimer = B_SLOW_START_TIMER;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_SLOWSTART;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_CURIOUS_MEDICINE:
            if (shouldAbilityTrigger
             && IsDoubleBattle()
             && IsBattlerAlive(GetPartnerBattler(battler))
             && TryResetBattlerStatChanges(GetPartnerBattler(battler)))
            {
                gEffectBattler = GetPartnerBattler(battler);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_CURIOUS_MEDICINE;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_PASTEL_VEIL:
            if (shouldAbilityTrigger)
            {
                gEffectBattler = battler;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_PASTEL_VEIL;
                BattleScriptCall(BattleScript_PastelVeilActivates);
                effect++;
            }
            break;
        case ABILITY_ANTICIPATION:
            if (shouldAbilityTrigger)
            {
                struct DamageContext ctx = {0};
                uq4_12_t modifier = UQ_4_12(1.0);
                for (i = 0; i < gBattlersCount; i++)
                {
                    if (IsBattlerAlive(i) && !IsBattlerAlly(i, battler))
                    {
                        for (j = 0; j < MAX_MON_MOVES; j++)
                        {
                            move = gBattleMons[i].moves[j];
                            enum BattleMoveEffects moveEffect = GetMoveEffect(move);
                            moveType = GetBattleMoveType(move);

                            ctx.battlerAtk = i;
                            ctx.battlerDef = battler;
                            ctx.move = ctx.chosenMove = ctx.baseMove = move;
                            ctx.moveType = moveType;
                            ctx.isAnticipation = TRUE;
                            modifier = CalcTypeEffectivenessMultiplier(&ctx);

                            if (modifier >= UQ_4_12(2.0) || moveEffect == EFFECT_OHKO)
                            {
                                effect++;
                                break;
                            }
                        }
                    }
                }

                if (effect != 0)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_ANTICIPATION;
                    BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                }
            }
            break;
        case ABILITY_FRISK:
            if (shouldAbilityTrigger)
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
                effect++;
            }
            return effect; // Note: It returns effect as to not record the ability if Frisk does not activate.
        case ABILITY_FOREWARN:
            if (shouldAbilityTrigger && !IsOpposingSideEmpty(battler))
            {
                ForewarnChooseMove(battler);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_FOREWARN;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_DOWNLOAD:
            if (shouldAbilityTrigger)
            {
                enum Stat statId = GetDownloadStat(battler);

                if (CompareStat(battler, statId, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
                {
                    gEffectBattler = gBattlerAbility = battler;
                    SetStatChange(battler, statId, 1);
                    BattleScriptCall(BattleScript_AbilityStatChange);
                    effect++;
                }
            }
            break;
        case ABILITY_PRESSURE:
            if (shouldAbilityTrigger)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_PRESSURE;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_DARK_AURA:
            if (shouldAbilityTrigger)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_DARKAURA;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_FAIRY_AURA:
            if (shouldAbilityTrigger)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_FAIRYAURA;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_AURA_BREAK:
            if (shouldAbilityTrigger)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_AURABREAK;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_COMATOSE:
            if (shouldAbilityTrigger)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_COMATOSE;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_SCREEN_CLEANER:
            if (shouldAbilityTrigger && TryRemoveScreens(battler))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_SCREENCLEANER;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_DRIZZLE:
            if (shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_RAIN, ability))
                effect++;
            break;
        case ABILITY_SAND_STREAM:
            if (shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_SANDSTORM, ability))
                effect++;
            break;
        case ABILITY_DROUGHT:
        case ABILITY_ORICHALCUM_PULSE:
            if (shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_SUN, ability))
                effect++;
            break;
        case ABILITY_SNOW_WARNING:
            if (shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, GetConfig(B_SNOW_WARNING) >= GEN_9 ? BATTLE_WEATHER_SNOW : BATTLE_WEATHER_HAIL, ability))
                effect++;
            break;
        case ABILITY_ELECTRIC_SURGE:
            if (!shouldAbilityTrigger)
                break;
            if (TryChangeBattleTerrain(battler, B_TERRAIN_ELECTRIC))
            {
                BattleScriptCall(BattleScript_ElectricSurgeActivates);
                effect++;
            }
            break;
        case ABILITY_HADRON_ENGINE:
            if (!shouldAbilityTrigger)
                break;
            if (gFieldTimers.terrain == B_TERRAIN_ELECTRIC)
            {
                BattleScriptCall(BattleScript_HadronEngineActivatesInTerrain);
                effect++;
            }
            else if (TryChangeBattleTerrain(battler, B_TERRAIN_ELECTRIC))
            {
                BattleScriptCall(BattleScript_HadronEngineActivates);
                effect++;
            }
            break;
        case ABILITY_GRASSY_SURGE:
            if (!shouldAbilityTrigger)
                break;
            if (TryChangeBattleTerrain(battler, B_TERRAIN_GRASSY))
            {
                BattleScriptCall(BattleScript_GrassySurgeActivates);
                effect++;
            }
            break;
        case ABILITY_MISTY_SURGE:
            if (!shouldAbilityTrigger)
                break;
            if (TryChangeBattleTerrain(battler, B_TERRAIN_MISTY))
            {
                BattleScriptCall(BattleScript_MistySurgeActivates);
                effect++;
            }
            break;
        case ABILITY_PSYCHIC_SURGE:
            if (!shouldAbilityTrigger)
                break;
            if (TryChangeBattleTerrain(battler, B_TERRAIN_PSYCHIC))
            {
                BattleScriptCall(BattleScript_PsychicSurgeActivates);
                effect++;
            }
            break;
        case ABILITY_INTIMIDATE:
            if (shouldAbilityTrigger && !IsOpposingSideEmpty(battler))
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
                effect++;
            }
            break;
        case ABILITY_SUPERSWEET_SYRUP:
            if (shouldAbilityTrigger
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
                effect++;
            }
            break;
        case ABILITY_CLOUD_NINE:
        case ABILITY_AIR_LOCK:
            if (shouldAbilityTrigger)
            {
                BattleScriptCall(BattleScript_AnnounceAirLockCloudNine);
                effect++;
            }
            break;
        case ABILITY_INTREPID_SWORD:
            if (shouldAbilityTrigger && !GetBattlerPartyState(battler)->intrepidSwordBoost)
            {
                if (GetConfig(B_INTREPID_SWORD) >= GEN_9)
                    GetBattlerPartyState(battler)->intrepidSwordBoost = TRUE;

                if (CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
                {
                    gEffectBattler = gBattlerAbility = battler;
                    SetStatChange(battler, STAT_ATK, 1);
                    BattleScriptCall(BattleScript_AbilityStatChange);
                    effect++;
                }
            }
            break;
        case ABILITY_DAUNTLESS_SHIELD:
            if (shouldAbilityTrigger && !GetBattlerPartyState(battler)->dauntlessShieldBoost)
            {
                if (GetConfig(B_DAUNTLESS_SHIELD) >= GEN_9)
                    GetBattlerPartyState(battler)->dauntlessShieldBoost = TRUE;

                if (CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
                {
                    gEffectBattler = gBattlerAbility = battler;
                    SetStatChange(battler, STAT_DEF, 1);
                    BattleScriptCall(BattleScript_AbilityStatChange);
                    effect++;
                }
            }
            break;
        case ABILITY_WIND_RIDER:
            if (shouldAbilityTrigger
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, ability)
             && gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_TAILWIND)
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_ATK, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_DESOLATE_LAND:
            if (shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_SUN_PRIMAL, ability))
                effect++;
            break;
        case ABILITY_PRIMORDIAL_SEA:
            if (shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_RAIN_PRIMAL, ability))
                effect++;
            break;
        case ABILITY_DELTA_STREAM:
            if (shouldAbilityTrigger && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_STRONG_WINDS, ability))
                effect++;
            break;
        case ABILITY_VESSEL_OF_RUIN:
            if (shouldAbilityTrigger)
            {
                gBattleMons[battler].volatiles.vesselOfRuin = TRUE;
                PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_SPATK);
                BattleScriptCall(BattleScript_RuinAbilityActivates);
                effect++;
            }
            break;
        case ABILITY_SWORD_OF_RUIN:
            if (shouldAbilityTrigger)
            {
                gBattleMons[battler].volatiles.swordOfRuin = TRUE;
                PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_DEF);
                BattleScriptCall(BattleScript_RuinAbilityActivates);
                effect++;
            }
            break;
        case ABILITY_TABLETS_OF_RUIN:
            if (shouldAbilityTrigger)
            {
                gBattleMons[battler].volatiles.tabletsOfRuin = TRUE;
                PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_ATK);
                BattleScriptCall(BattleScript_RuinAbilityActivates);
                effect++;
            }
            break;
        case ABILITY_BEADS_OF_RUIN:
            if (shouldAbilityTrigger)
            {
                gBattleMons[battler].volatiles.beadsOfRuin = TRUE;
                PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_SPDEF);
                BattleScriptCall(BattleScript_RuinAbilityActivates);
                effect++;
            }
            break;
        case ABILITY_SUPREME_OVERLORD:
            if (shouldAbilityTrigger)
            {
                gBattleMons[battler].volatiles.supremeOverlordCounter = min(5, gBattleStruct->faintCounter[GetBattlerTrainer(battler)]);
                if (gBattleMons[battler].volatiles.supremeOverlordCounter > 0)
                {
                    BattleScriptCall(BattleScript_SupremeOverlordActivates);
                    effect++;
                }
            }
            break;
        case ABILITY_ZERO_TO_HERO:
            if (GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES) == SPECIES_PALAFIN_HERO
             && !GetBattlerPartyState(battler)->transformZeroToHero)
            {
                GetBattlerPartyState(battler)->transformZeroToHero = TRUE;
                BattleScriptCall(BattleScript_ZeroToHeroActivates);
                effect++;
            }
            break;
        case ABILITY_EMBODY_ASPECT_TEAL_MASK:
        case ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK:
        case ABILITY_EMBODY_ASPECT_WELLSPRING_MASK:
        case ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK:
            if (shouldAbilityTrigger && !gBattleMons[battler].volatiles.embodyAspectActivated)
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
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_SWITCH_IN_FORM_CHANGE:
        if (shouldAbilityTrigger && TryBattleFormChange(cv->battlerAtk, FORM_CHANGE_BATTLE_HP_PERCENT_SEND_OUT, cv->abilities[cv->battlerAtk]))
        {
            gBattleScripting.battler = battler = cv->battlerAtk;
            // To prevent the new form's ability from pop up
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = cv->abilities[cv->battlerAtk];
            BattleScriptCall(BattleScript_BattlerFormChange);
            effect++;
        }
        break;
    case ABILITYEFFECT_ENDTURN:
        battler = cv->battlerAtk;
        ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];
        switch (ability)
        {
        case ABILITY_PICKUP:
            if (gBattleMons[battler].item == ITEM_NONE
             && PickupHasValidTarget(battler))
            {
                gBattlerTarget = RandomUniformExcept(RNG_PICKUP, 0, gBattlersCount - 1, CantPickupItem);
                gLastUsedItem = GetBattlerPartyState(gBattlerTarget)->usedHeldItem;
                BattleScriptCall(BattleScript_PickupActivates);
                effect++;
            }
            break;
        case ABILITY_HARVEST:
            if ((IsBattlerWeatherAffected(cv->holdEffects[battler], GetWeather(), B_WEATHER_SUN) || RandomPercentage(RNG_HARVEST, 50))
             && gBattleMons[battler].item == ITEM_NONE
             && GetItemPocket(GetBattlerPartyState(battler)->usedHeldItem) == POCKET_BERRIES)
            {
                gLastUsedItem = GetBattlerPartyState(battler)->usedHeldItem;
                BattleScriptCall(BattleScript_HarvestActivates);
                effect++;
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
                effect++;
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
                effect++;
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
                effect++;
            }
            break;
        case ABILITY_SPEED_BOOST:
            if (CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, ability) && !BattlerJustSwitchedIn(battler))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_SPEED, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
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
                effect++;
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
                effect++;
            }
            break;
        case ABILITY_BAD_DREAMS:
            BattleScriptCall(BattleScript_BadDreamsActivates);
            effect++;
            break;
        case ABILITY_SOLAR_POWER:
            if (IsBattlerWeatherAffected(cv->holdEffects[battler], GetWeather(), B_WEATHER_SUN))
            {
            SOLAR_POWER_HP_DROP:
                SetPassiveDamageAmount(battler, GetNonDynamaxMaxHP(battler) / 8);
                BattleScriptCall(BattleScript_SolarPowerActivates);
                effect++;
            }
            break;
        case ABILITY_HEALER:
            gBattleScripting.battler = GetPartnerBattler(battler);
            if (IsBattlerAlive(gBattleScripting.battler)
             && gBattleMons[gBattleScripting.battler].status1 & STATUS1_ANY
             && RandomPercentage(RNG_HEALER, 30))
            {
                BattleScriptCall(BattleScript_HealerActivates);
                effect++;
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
                effect++;
            }
            break;
        case ABILITY_CUD_CHEW:
            if (gBattleMons[battler].volatiles.cudChewTimer > 0 && --gBattleMons[battler].volatiles.cudChewTimer == 0)
            {
                gBattleScripting.battler = battler;
                gLastUsedItem = GetBattlerPartyState(battler)->usedHeldItem;
                GetBattlerPartyState(battler)->usedHeldItem = ITEM_NONE;
                BattleScriptCall(BattleScript_CudChewActivates);
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_COLOR_CHANGE:
        battler = cv->battlerDef;
        ability = gLastUsedAbility = cv->abilities[cv->battlerDef];
        switch (ability)
        {
        case ABILITY_COLOR_CHANGE:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && !IS_BATTLER_OF_TYPE(battler, moveType)
             && move != MOVE_STRUGGLE
             && moveType != TYPE_STELLAR
             && moveType != TYPE_MYSTERY)
            {
                gEffectBattler = gBattlerAbility = battler;
                SET_BATTLER_TYPE(battler, moveType);
                PREPARE_TYPE_BUFFER(gBattleTextBuff1, moveType);
                BattleScriptCall(BattleScript_ColorChangeActivates);
                effect++;
            }
            break;
        case ABILITY_BERSERK:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && HadMoreThanHalfHpNowDoesnt(battler)
             && CompareStat(battler, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_SPATK, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_ANGER_SHELL:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && HadMoreThanHalfHpNowDoesnt(battler))
            {
                gEffectBattler = gBattlerAbility = battler;
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

                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_MOVE_END: // Think contact abilities.
        battler = cv->battlerDef;
        ability = gLastUsedAbility = cv->abilities[cv->battlerDef];
        switch (ability)
        {
        case ABILITY_JUSTIFIED:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && moveType == TYPE_DARK
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_ATK, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_RATTLED:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && (moveType == TYPE_DARK || moveType == TYPE_BUG || moveType == TYPE_GHOST)
             && CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_SPEED, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_WATER_COMPACTION:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && moveType == TYPE_WATER
             && CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_DEF, 2);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_STAMINA:
            if (gBattlerAttacker != battler
             && IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_DEF, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_DEF, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_WEAK_ARMOR:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && IsBattleMovePhysical(gCurrentMove)
             && (CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, ability) // Don't activate if both Speed and Defense cannot be raised.
               || CompareStat(battler, STAT_DEF, MIN_STAT_STAGE, CMP_GREATER_THAN, ability)))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_DEF, -1);
                if (GetConfig(B_WEAK_ARMOR_SPEED) >= GEN_7)
                    SetStatChange(battler, STAT_SPEED, 2);
                else
                    SetStatChange(battler, STAT_SPEED, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_CURSED_BODY:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && GetMoveEffect(move) != EFFECT_FUTURE_SIGHT
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
                effect++;
            }
            break;
        case ABILITY_LINGERING_AROMA:
        case ABILITY_MUMMY:
            if (IsBattlerAlive(gBattlerAttacker)
             && !gSpecialStatuses[gBattlerAttacker].attackerInParty
             && IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && !CanBattlerAvoidContactEffects(gBattlerAttacker, battler, cv->abilities[gBattlerAttacker], cv->holdEffects[gBattlerAttacker], move)
             && gBattleMons[gBattlerAttacker].ability != ability
             && !gAbilitiesInfo[gBattleMons[gBattlerAttacker].ability].cantBeSuppressed)
            {
                if (GetBattlerHoldEffectIgnoreAbility(gBattlerAttacker) == HOLD_EFFECT_ABILITY_SHIELD)
                {
                    RecordItemEffectBattle(gBattlerAttacker, HOLD_EFFECT_ABILITY_SHIELD);
                    break;
                }

                RemoveAbilityFlags(gBattlerAttacker);
                gBattleScripting.battler = battler;
                gLastUsedAbility = gBattleMons[gBattlerAttacker].ability;
                OverwriteBattlerAbility(gBattlerAttacker, gBattleMons[battler].ability);
                BattleScriptCall(BattleScript_MummyActivates);
                effect++;
                break;
            }
            break;
        case ABILITY_WANDERING_SPIRIT:
            if (IsBattlerAlive(gBattlerAttacker)
             && IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && !CanBattlerAvoidContactEffects(gBattlerAttacker, battler, cv->abilities[gBattlerAttacker], cv->holdEffects[gBattlerAttacker], move)
             && GetActiveGimmick(battler) != GIMMICK_DYNAMAX
             && !gAbilitiesInfo[gBattleMons[gBattlerAttacker].ability].cantBeSwapped)
            {
                if (GetBattlerHoldEffectIgnoreAbility(gBattlerAttacker) == HOLD_EFFECT_ABILITY_SHIELD)
                {
                    RecordItemEffectBattle(gBattlerAttacker, HOLD_EFFECT_ABILITY_SHIELD);
                    break;
                }
                if (GetBattlerHoldEffectIgnoreAbility(battler) == HOLD_EFFECT_ABILITY_SHIELD)
                {
                    RecordItemEffectBattle(battler, HOLD_EFFECT_ABILITY_SHIELD);
                    break;
                }

                RemoveAbilityFlags(gBattlerAttacker);
                gBattleScripting.battler = battler;
                gLastUsedAbility = gBattleMons[gBattlerAttacker].ability;
                OverwriteBattlerAbility(gBattlerAttacker, gBattleMons[battler].ability);
                OverwriteBattlerAbility(battler, gLastUsedAbility);
                BattleScriptCall(BattleScript_WanderingSpiritActivates);
                effect++;
                break;
            }
            break;
        case ABILITY_ANGER_POINT:
            if (gSpecialStatuses[battler].criticalHit
             && IsBattlerTurnDamaged(battler, GetConfig(B_UPDATED_ABILITY_DATA) <= GEN_4 ? INCLUDING_SUBSTITUTES : EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_ATK, MAX_STAT_STAGE);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
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
                    gEffectBattler = gBattlerAbility = battler = cv->battlerDef;
                    gLastUsedAbility = cv->abilities[cv->battlerDef];
                    SetStatChange(cv->battlerAtk, STAT_SPEED, -1);
                    BattleScriptCall(BattleScript_AbilityStatChange);
                    effect++;
                }
            }
            break;
        case ABILITY_ROUGH_SKIN:
        case ABILITY_IRON_BARBS:
            if (IsBattlerAlive(cv->battlerAtk)
             && !gSpecialStatuses[cv->battlerAtk].attackerInParty
             && IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && !CanBattlerAvoidContactEffects(cv->battlerAtk, battler, cv->abilities[cv->battlerAtk], cv->holdEffects[cv->battlerAtk], move))
            {
                if (!IsAbilityAndRecord(cv->battlerAtk, cv->abilities[cv->battlerAtk], ABILITY_MAGIC_GUARD))
                {
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, ability);
                    SetPassiveDamageAmount(cv->battlerAtk, GetNonDynamaxMaxHP(cv->battlerAtk) / (B_ROUGH_SKIN_DMG >= GEN_4 ? 8 : 16));
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_HURT;
                    BattleScriptCall(BattleScript_RoughSkinActivates);
                }
                else
                {
                    BattleScriptCall(BattleScript_AbilityPopUp);
                }
                effect++;
            }
            break;
        case ABILITY_AFTERMATH:
            if (!IsBattlerUnaffectedByMove(battler)
             && !gSpecialStatuses[cv->battlerAtk].attackerInParty
             && !IsBattlerAlive(battler)
             && IsBattlerAlive(cv->battlerAtk)
             && !CanBattlerAvoidContactEffects(cv->battlerAtk, battler, cv->abilities[cv->battlerAtk], cv->holdEffects[cv->battlerAtk], move))
            {
                enum BattlerId dampBattler = IsAbilityOnField(ABILITY_DAMP);
                if (dampBattler)
                {
                    gBattleScripting.battler = dampBattler - 1;
                    BattleScriptCall(BattleScript_DampPreventsAftermath);
                }
                else
                {
                    gBattleScripting.battler = battler;
                    SetPassiveDamageAmount(cv->battlerAtk, GetNonDynamaxMaxHP(cv->battlerAtk) / 4);
                    BattleScriptCall(BattleScript_AftermathDmg);
                }
                effect++;
            }
            break;
        case ABILITY_INNARDS_OUT:
            if (!IsBattlerUnaffectedByMove(battler)
             && !IsBattlerAlive(battler)
             && !gSpecialStatuses[cv->battlerAtk].attackerInParty
             && IsBattlerAlive(cv->battlerAtk))
            {
                s32 damage = gBattleStruct->moveDamage[battler];

                if (gBattleStruct->innardsOutHpLost[battler] != 0)
                    damage = gBattleStruct->innardsOutHpLost[battler];

                gBattleScripting.battler = battler;
                SetPassiveDamageAmount(cv->battlerAtk, damage);
                BattleScriptCall(BattleScript_AftermathDmg);
                effect++;
            }
            break;
        case ABILITY_EFFECT_SPORE:
        {
            enum Ability abilityAtk = cv->abilities[cv->battlerAtk];
            enum HoldEffect holdEffectAtk = cv->holdEffects[cv->battlerAtk];
            if (IsBattlerAlive(cv->battlerAtk)
             && !gSpecialStatuses[cv->battlerAtk].attackerInParty
             && IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && !CanBattlerAvoidContactEffects(cv->battlerAtk, battler, abilityAtk, holdEffectAtk, move)
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

                i = RandomUniform(RNG_EFFECT_SPORE, 0, GetConfig(B_ABILITY_TRIGGER_CHANCE) >= GEN_4 ? 99 : 299);
                if (i < poison)
                    goto POISON_POINT;
                if (i < paralysis)
                    goto STATIC;
                // Sleep
                if (i < sleep && CanBeSlept(battler, cv->battlerAtk, abilityAtk, NOT_BLOCKED_BY_SLEEP_CLAUSE))
                {
                    if (IsSleepClauseEnabled())
                        gBattleStruct->battlerState[cv->battlerAtk].sleepClauseEffectExempt = TRUE;
                    gEffectBattler = cv->battlerAtk;
                    gBattleScripting.battler = battler;
                    gBattleScripting.moveEffect = MOVE_EFFECT_SLEEP;
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, ability);
                    BattleScriptCall(BattleScript_AbilityStatusEffect);
                    effect++;
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
                 && IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
                 && CanBePoisoned(battler, cv->battlerAtk, ability, abilityAtk)
                 && !CanBattlerAvoidContactEffects(cv->battlerAtk, battler, abilityAtk, cv->holdEffects[cv->battlerAtk], move))
                {
                    gEffectBattler = cv->battlerAtk;
                    gBattleScripting.battler = battler;
                    gBattleScripting.moveEffect = MOVE_EFFECT_POISON;
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, ability);
                    BattleScriptCall(BattleScript_AbilityStatusEffect);
                    effect++;
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
                 && IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
                 && CanBeParalyzed(battler, cv->battlerAtk, abilityAtk)
                 && !CanBattlerAvoidContactEffects(cv->battlerAtk, battler, abilityAtk, cv->holdEffects[cv->battlerAtk], move))
                {
                    gEffectBattler = cv->battlerAtk;
                    gBattleScripting.battler = battler;
                    gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, ability);
                    BattleScriptCall(BattleScript_AbilityStatusEffect);
                    effect++;
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
                effect++;
            }
            break;
        case ABILITY_CUTE_CHARM:
            if (IsBattlerAlive(cv->battlerAtk)
             && !gSpecialStatuses[cv->battlerAtk].attackerInParty
             && IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && (GetConfig(B_ABILITY_TRIGGER_CHANCE) >= GEN_4 ? RandomPercentage(RNG_CUTE_CHARM, 30) : RandomChance(RNG_CUTE_CHARM, 1, 3))
             && !(gBattleMons[cv->battlerAtk].volatiles.infatuation)
             && AreBattlersOfOppositeGender(cv->battlerAtk, battler)
             && !IsAbilityAndRecord(cv->battlerAtk, cv->abilities[cv->battlerAtk], ABILITY_OBLIVIOUS)
             && !CanBattlerAvoidContactEffects(cv->battlerAtk, battler, cv->abilities[cv->battlerAtk], cv->holdEffects[cv->battlerAtk], move)
             && !IsAbilityOnSide(cv->battlerAtk, ABILITY_AROMA_VEIL))
            {
                gBattleMons[cv->battlerAtk].volatiles.infatuation = INFATUATED_WITH(battler);
                BattleScriptCall(BattleScript_CuteCharmActivates);
                effect++;
            }
            break;
        case ABILITY_ILLUSION:
            if (gBattleStruct->illusion[battler].state == ILLUSION_ON && IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES))
            {
                gBattleScripting.battler = battler;
                BattleScriptCall(BattleScript_IllusionOff);
                effect++;
            }
            break;
        case ABILITY_COTTON_DOWN:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES))
            {
                gEffectBattler = gBattlerAbility = battler;
                for (enum BattlerId i = 0; i < gBattlersCount; i++)
                {
                    if (battler == i || !IsBattlerAlive(i))
                        continue;
                    SetStatChange(i, STAT_SPEED, -1);
                }
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_STEAM_ENGINE:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, ability)
             && (moveType == TYPE_FIRE || moveType == TYPE_WATER))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_SPEED, 6);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_SAND_SPIT:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES) && TryChangeWeatherWithAbility(battler, BATTLE_WEATHER_SANDSTORM, ability))
                effect++;
            break;
        case ABILITY_PERISH_BODY:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && !CanBattlerAvoidContactEffects(cv->battlerAtk, battler, cv->abilities[cv->battlerAtk], cv->holdEffects[cv->battlerAtk], move)
             && !gBattleMons[cv->battlerAtk].volatiles.perishSong)
            {
                if (!gBattleMons[battler].volatiles.perishSong)
                {
                    gBattleMons[battler].volatiles.perishSong = TRUE;
                    gBattleMons[battler].volatiles.perishSongTimer = 3;
                }
                gBattleMons[cv->battlerAtk].volatiles.perishSong = TRUE;
                gBattleMons[cv->battlerAtk].volatiles.perishSongTimer = 3;
                BattleScriptCall(BattleScript_PerishBodyActivates);
                effect++;
            }
            break;
        case ABILITY_SEED_SOWER:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && TryChangeBattleTerrain(battler, B_TERRAIN_GRASSY))
            {
                BattleScriptCall(BattleScript_SeedSowerActivates);
                effect++;
            }
            break;
        case ABILITY_THERMAL_EXCHANGE:
            if (IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battler)
             && CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, ability)
             && moveType == TYPE_FIRE)
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_ATK, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        case ABILITY_WIND_POWER:
            if (!IsWindMove(gCurrentMove))
                break;
            [[fallthrough]];
        case ABILITY_ELECTROMORPHOSIS:
            if (!gBattleStruct->unableToUseMove && IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES))
            {
                gBattlerAbility = battler;
                BattleScriptCall(BattleScript_WindPowerActivates);
                effect++;
            }
            break;
        case ABILITY_TOXIC_DEBRIS:
        {
            enum BattlerId toxicSpikesTarget = GetOppositeBattler(battler);
            enum BattleSide side = GetBattlerSide(toxicSpikesTarget);
            if (!gBattleStruct->isSkyBattle
             && IsBattleMovePhysical(gCurrentMove)
             && IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && (gSideTimers[side].toxicSpikesAmount != 2))
            {
                if (gSideTimers[side].toxicSpikesAmount == 0) // Add only once to the queue
                    PushHazardTypeToQueue(side, HAZARDS_TOXIC_SPIKES);
                gSideTimers[side].toxicSpikesAmount++;
                SaveBattlerTarget(battler);
                SaveBattlerAttacker(cv->battlerAtk);
                gBattlerAttacker = battler;
                gBattlerTarget = GetOppositeBattler(gBattlerAttacker);
                BattleScriptCall(BattleScript_ToxicDebrisActivates);
                effect++;
            }
            break;
        }
        case ABILITY_SPICY_SPRAY:
            if (IsBattlerAlive(cv->battlerAtk)
             && !gSpecialStatuses[cv->battlerAtk].attackerInParty
             && IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
             && CanBeBurned(battler, cv->battlerAtk, cv->abilities[cv->battlerAtk]))
            {
                gEffectBattler = cv->battlerAtk;
                gBattleScripting.battler = battler;
                gBattleScripting.moveEffect = MOVE_EFFECT_BURN;
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, ability);
                BattleScriptCall(BattleScript_AbilityStatusEffect);
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_MOVE_END_ATTACKER:
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
                gBattleScripting.battler = battler = cv->battlerAtk;
                gBattleScripting.moveEffect = MOVE_EFFECT_POISON;
                gLastUsedAbility = cv->abilities[cv->battlerAtk];
                PREPARE_ABILITY_BUFFER(gBattleTextBuff1, cv->abilities[cv->battlerAtk]);
                BattleScriptCall(BattleScript_AbilityStatusEffect);
                effect++;
            }
            break;
        case ABILITY_TOXIC_CHAIN:
            if (gBattleStruct->battlerState[cv->battlerDef].toxicChainActivates)
            {
                gBattleStruct->battlerState[cv->battlerDef].toxicChainActivates = FALSE;
                if (!IsMoveEffectBlockedByTarget(cv->abilities[cv->battlerDef]))
                {
                    gEffectBattler = cv->battlerDef;
                    gBattleScripting.battler = battler = cv->battlerAtk;
                    gBattleScripting.moveEffect = MOVE_EFFECT_TOXIC;
                    gLastUsedAbility = cv->abilities[cv->battlerAtk];
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, cv->abilities[cv->battlerAtk]);
                    BattleScriptCall(BattleScript_AbilityStatusEffect);
                    effect++;
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
                SetMoveEffectHelper(cv->battlerAtk, cv->battlerDef, MOVE_EFFECT_FLINCH, gBattlescriptCurrInstr, NO_FLAGS);
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_ON_STATUS_CHANGE:
        battler = cv->battlerAtk;
        ability = cv->abilities[cv->battlerAtk];
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
                    gBattleScripting.battler = battler;
                    gEffectBattler = gBattleStruct->statusedBattler;
                    gBattleScripting.moveEffect = MOVE_EFFECT_CONFUSION;
                    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, ability);
                    BattleScriptCall(BattleScript_AbilityStatusEffect);
                    effect++;
                }
            }
            break;
        case ABILITY_SYNCHRONIZE:
            if (gSpecialStatuses[battler].synchronize)
            {
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
                    enum Ability abilityEff = cv->abilities[gEffectBattler];

                    if (CanSetNonVolatileStatus(
                            battler,
                            gEffectBattler,
                            ability,
                            abilityEff,
                            gBattleScripting.moveEffect,
                            CHECK_TRIGGER))
                    {
                        BattleScriptCall(BattleScript_SynchronizeActivates);
                        effect++;
                        break;
                    }

                    BattleScriptPush(gBattlescriptCurrInstr);
                    if (!CanSetNonVolatileStatus(
                            battler,
                            gEffectBattler,
                            ability,
                            abilityEff,
                            gBattleScripting.moveEffect,
                            RUN_SCRIPT))
                    {
                        gSpecialStatuses[battler].synchronize = FALSE;
                        effect++;
                    }
                    break;
                }
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_FORM_CHANGE_ON_HIT:
        speciesForm = gBattleMons[cv->battlerDef].species;
        ability = gLastUsedAbility = cv->abilities[cv->battlerDef];

        if (gBattleStruct->unableToUseMove
         || !IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
         || !TryBattleFormChange(cv->battlerDef, FORM_CHANGE_BATTLE_HIT_BY_MOVE_CATEGORY, ability))
            break;

        gBattleScripting.abilityPopupOverwrite = ability;
        gBattleScripting.battler = gBattlerAbility = battler = cv->battlerDef;
        effect++;

        switch (ability)
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
        break;
    case ABILITYEFFECT_DANCER:
        return TryDancer();
    case ABILITYEFFECT_MOVE_END_FOES_FAINTED:
        gBattlerAbility = battler = cv->battlerAtk;
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
                {
                    effect = FALSE;
                    break;
                }

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
                    {
                        effect = FALSE;
                        break;
                    }

                    StealTargetItem(battler, targetBattler, ITEM_NONE, FALSE);
                    gEffectBattler = targetBattler;
                    gLastUsedAbility = cv->abilities[cv->battlerAtk];
                    BattleScriptCall(BattleScript_MagicianActivates);
                    effect = TRUE;
                    break; // found target to steal from
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
                battler = cv->battlerAtk;
                ability = cv->abilities[cv->battlerAtk];
                u32 numMonsFainted = NumFaintedBattlersByAttacker(battler);

                switch (ability)
                {
                case ABILITY_BEAST_BOOST:
                case ABILITY_EELEVATE:
                    stat = GetHighestStatId(battler);
                    break;
                case ABILITY_GRIM_NEIGH:
                case ABILITY_AS_ONE_SHADOW_RIDER:
                    stat = STAT_SPATK;
                    break;
                default:
                    break;
                }

                if (numMonsFainted && CompareStat(battler, stat, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
                {
                    gLastUsedAbility = ability;
                    if (ability == ABILITY_AS_ONE_ICE_RIDER)
                        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_CHILLING_NEIGH;
                    else if (ability == ABILITY_AS_ONE_SHADOW_RIDER)
                        gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_GRIM_NEIGH;

                    gEffectBattler = gBattlerAbility = battler;
                    SetStatChange(battler, stat, numMonsFainted);
                    BattleScriptCall(BattleScript_AbilityStatChange);
                    effect = TRUE;
                }
            }
            break;
        case ABILITY_BATTLE_BOND:
            {
                battler = cv->battlerAtk;
                ability = cv->abilities[cv->battlerAtk];

                if (NoAliveMonsForEitherParty()
                 || NumFaintedBattlersByAttacker(battler) == 0)
                    break;

                if (GetBattlerPartyState(battler)->battleBondBoost || gBattleMons[battler].species != SPECIES_GRENINJA_BATTLE_BOND)
                    break;

                if (GetConfig(B_BATTLE_BOND) < GEN_9)
                {
                    gLastUsedAbility = ability;
                    GetBattlerPartyState(battler)->battleBondBoost = TRUE;
                    PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[battler].species);
                    TryBattleFormChange(battler, FORM_CHANGE_BATTLE_BOND, ability);
                    BattleScriptCall(BattleScript_BattleBondActivatesOnMoveEndAttacker);
                    effect = TRUE;
                }
                else
                {
                    if (CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
                        SetStatChange(battler, STAT_ATK, 1);
                    if (CompareStat(battler, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
                        SetStatChange(battler, STAT_SPATK, 1);
                    if (CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
                        SetStatChange(battler, STAT_SPEED, 1);

                    if (gSpecialStatuses[battler].statStageAmount > 0)
                    {
                        gLastUsedAbility = ability;
                        gEffectBattler = gBattlerAbility = battler;

                        GetBattlerPartyState(battler)->battleBondBoost = TRUE;
                        BattleScriptCall(BattleScript_AbilityStatChange);
                        effect = TRUE;
                    }
                }
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_RECEIVER:
        switch (cv->abilities[cv->battlerDef])
        {
        case ABILITY_RECEIVER:
        case ABILITY_POWER_OF_ALCHEMY:
            if (GetBattlerHoldEffectIgnoreAbility(cv->battlerDef) != HOLD_EFFECT_ABILITY_SHIELD
             && !gAbilitiesInfo[gBattleMons[cv->battlerAtk].ability].cantBeCopied)
            {
                gBattlerAbility = battler = cv->battlerDef;
                gBattleStruct->tracedAbility[cv->battlerDef] = gBattleMons[cv->battlerAtk].ability; // re-using the variable for trace
                gBattleScripting.battler = cv->battlerAtk;
                gLastUsedAbility = cv->abilities[cv->battlerDef];
                BattleScriptCall(BattleScript_ReceiverActivates);
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_ON_FAINT:
        battler = cv->battlerAtk;
        ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];
        switch (ability)
        {
        case ABILITY_SOUL_HEART:
            if (!NoAliveMonsForEitherParty()
             && CompareStat(battler, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN, ability))
            {
                gEffectBattler = gBattlerAbility = battler;
                SetStatChange(battler, STAT_SPATK, 1);
                BattleScriptCall(BattleScript_AbilityStatChange);
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_OPPORTUNIST:
        battler = cv->battlerAtk;
        ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];
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
                effect = 1;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_IMMUNITY:
        battler = gBattlerAbility = gBattleScripting.battler = cv->battlerAtk;
        ability = gLastUsedAbility = GetBattlerAbilityIgnoreMoldBreaker(battler);
        effect = TryImmunityAbilityHealStatus(cv->battlerAtk, ability);
        break;
    case ABILITYEFFECT_TERA_SHIFT:
        if (TryBattleFormChange(cv->battlerAtk, FORM_CHANGE_BATTLE_SWITCH_IN, cv->abilities[cv->battlerAtk]))
        {
            gBattleScripting.battler = battler = cv->battlerAtk;
            gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = cv->abilities[cv->battlerAtk];
            BattleScriptCall(BattleScript_BattlerFormChangeWithString);
            effect++;
        }
        break;
    case ABILITYEFFECT_NEUTRALIZINGGAS:
        battler = cv->battlerAtk;
        ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];
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
            gBattlerAbility = battler;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_NEUTRALIZING_GAS;
            BattleScriptCall(BattleScript_SwitchInNeutralizingGas);
            effect++;
        }
        break;
    case ABILITYEFFECT_UNNERVE:
        battler = cv->battlerAtk;
        ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];
        switch (ability)
        {
        case ABILITY_UNNERVE:
            if (shouldAbilityTrigger && !gBattleMons[battler].volatiles.unnerveActivated)
            {
                gBattleScripting.battler = battler;
                gEffectBattler = GetOppositeBattler(battler);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_UNNERVE;
                gBattleMons[battler].volatiles.unnerveActivated = TRUE;
                BattleScriptCall(BattleScript_SwitchInAbilityMsg);
                effect++;
            }
            break;
        case ABILITY_AS_ONE_ICE_RIDER:
        case ABILITY_AS_ONE_SHADOW_RIDER:
            if (shouldAbilityTrigger && !gBattleMons[battler].volatiles.unnerveActivated)
            {
                gBattleScripting.battler = battler;
                gEffectBattler = GetOppositeBattler(battler);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_ASONE;
                gBattleMons[battler].volatiles.unnerveActivated = TRUE;
                BattleScriptCall(BattleScript_ActivateAsOne);
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_DEPENDS_ON_ALLY:
        battler = gBattleScripting.battler = cv->battlerAtk;
        ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];
        partner = GetPartnerBattler(battler);
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
                effect++;
            }
            break;
        case ABILITY_HOSPITALITY:
            if (shouldAbilityTrigger
             && IsDoubleBattle()
             && !gBattleMons[partner].volatiles.healBlockTimer
             && gBattleMons[partner].hp < gBattleMons[partner].maxHP
             && IsBattlerAlive(partner))
            {
                SetHealAmount(partner, GetNonDynamaxMaxHP(partner) / 4);
                gBattleScripting.battler = battler;
                gEffectBattler = partner;
                BattleScriptCall(BattleScript_HospitalityActivates);
                effect++;
            }
            break;
        case ABILITY_COSTAR:
            if (shouldAbilityTrigger
             && IsDoubleBattle()
             && IsBattlerAlive(partner)
             && BattlerHasCopyableChanges(partner))
            {
                for (i = 0; i < NUM_BATTLE_STATS; i++)
                    gBattleMons[battler].statStages[i] = gBattleMons[partner].statStages[i];
                // Copy crit boosts (Focus Energy, Dragon Cheer, G-Max Chi Strike)
                gBattleMons[battler].volatiles.criticalHitBoost = gBattleMons[partner].volatiles.criticalHitBoost;
                gBattleMons[battler].volatiles.bonusCritStages = gBattleMons[partner].volatiles.bonusCritStages;
                gEffectBattler = partner;
                BattleScriptCall(BattleScript_CostarActivates);
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_ON_WEATHER: // For ability effects that activate when the battle weather changes.
        battler = cv->battlerAtk;
        ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];
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
                effect++;
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
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    case ABILITYEFFECT_ON_TERRAIN:  // For ability effects that activate when the field terrain changes.
        battler = cv->battlerAtk;
        ability = gLastUsedAbility = cv->abilities[cv->battlerAtk];
        switch (ability)
        {
        case ABILITY_MIMICRY:
            if (!gBattleMons[battler].volatiles.terrainAbilityDone && ChangeTypeBasedOnTerrain(battler))
            {
                gBattleMons[battler].volatiles.terrainAbilityDone = TRUE;
                ChangeTypeBasedOnTerrain(battler);
                gBattlerAbility = gBattleScripting.battler = battler;
                BattleScriptCall(BattleScript_MimicryActivates);
                effect++;
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
                gBattlerAbility = gBattleScripting.battler = battler;
                BattleScriptCall(BattleScript_QuarkDriveActivates);
                effect++;
            }
            break;
        default:
            break;
        }
        break;
    }

    if (effect)
    {
        RecordAbilityBattle(battler, gLastUsedAbility);
        gBattlerAbility = battler;
    }

    return effect;
}

static bool32 IsRestrictedAbility(enum BattlerId battler, enum Ability ability)
{
    return GetSpeciesAbility(gBattleMons[battler].species, 0) == ability
        || GetSpeciesAbility(gBattleMons[battler].species, 1) == ability
        || GetSpeciesAbility(gBattleMons[battler].species, 2) == ability;
}

static bool32 TryDancer(void)
{
    u32 order = 0;
    enum BattlerId dancerBattler = MAX_BATTLERS_COUNT;

    if (!IsDanceMove(gCurrentMove))
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
    if (!gSpecialStatuses[gBattlerAttacker].dancerUsedMove)
    {
        gBattleStruct->dancerSavedTarget = gBattlerTarget;
        gBattleStruct->dancerSavedAttacker = gBattlerAttacker;
        gSpecialStatuses[gBattlerAttacker].dancerUsedMove = TRUE;
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

enum ImmunityHealStatusOutcome TryImmunityAbilityHealStatus(enum BattlerId battler, enum Ability ability)
{
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
    return outcome;
}

