#include "global.h"
#include "battle.h"
#include "battle_scripts.h"
#include "battle_util.h"
#include "battle_stat_change.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_ai_util.h"
#include "item.h"
#include "move.h"

static bool32 AbilityPreventsSpecificStatDrop(u32 ability, u32 stat);
static void AdjustStatStage(struct BattleContext *ctx, struct StatChange *st);
static u16 ReverseStatChangeMoveEffect(u16 moveEffect);
static bool32 CanAbilityPreventStatLoss(enum Ability abilityDef);
static void TryPlayStatChangeAnimation(enum BattlerId battler, enum Ability ability, u32 stats, s32 statValue, u32 statId, bool32 certain);

static enum StatChangeResult CanDecreaseStat(struct BattleContext *ctx, struct StatChange *st);
static enum StatChangeResult DecreaseStat(struct BattleContext *ctx, struct StatChange *st);
static enum StatChangeResult IncreaseStat(struct BattleContext *ctx, struct StatChange *st);
static void New_TryPlayStatChangeAnimation(struct BattleContext *ctx, struct StatChange *st);

u32 ChangeStatBuffs(enum BattlerId battler, s8 statValue, enum Stat statId, union StatChangeFlags flags, u32 stats, const u8 *BS_ptr)
{
    u32 index, battlerAbility;
    enum HoldEffect battlerHoldEffect;
    battlerAbility = GetBattlerAbility(battler);
    battlerHoldEffect = GetBattlerHoldEffect(battler);
    gSpecialStatuses[battler].changedStatsBattlerId = gBattlerAttacker;

    if (battlerAbility == ABILITY_CONTRARY)
    {
        statValue ^= STAT_BUFF_NEGATIVE;
        if (!flags.onlyChecking)
        {
            gBattleScripting.statChanger ^= STAT_BUFF_NEGATIVE;
            RecordAbilityBattle(battler, battlerAbility);
            if (flags.updateMoveEffect)
                gBattleScripting.moveEffect = ReverseStatChangeMoveEffect(gBattleScripting.moveEffect);
        }
    }
    else if (battlerAbility == ABILITY_SIMPLE && !flags.onlyChecking)
    {
        statValue = (SET_STAT_BUFF_VALUE(GET_STAT_BUFF_VALUE(statValue) * 2)) | ((statValue <= -1) ? STAT_BUFF_NEGATIVE : 0);
        RecordAbilityBattle(battler, battlerAbility);
    }

    PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);

    if (statValue <= -1) // Stat decrease.
    {
        enum BattleMoveEffects effect = GetMoveEffect(gCurrentMove);
        if (gSideTimers[GetBattlerSide(battler)].mistTimer
            && !flags.certain && effect != EFFECT_CURSE
            && !(battler == gBattlerTarget && GetBattlerAbility(gBattlerAttacker) == ABILITY_INFILTRATOR))
        {
            if (flags.allowPtr)
            {
                if (gSpecialStatuses[battler].statLowered)
                {
                    gBattlescriptCurrInstr = BS_ptr;
                }
                else
                {
                    BattleScriptPush(BS_ptr);
                    gBattleScripting.battler = battler;
                    gBattlescriptCurrInstr = BattleScript_MistProtected;
                    gSpecialStatuses[battler].statLowered = TRUE;
                }
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if ((battlerHoldEffect == HOLD_EFFECT_CLEAR_AMULET || CanAbilityPreventStatLoss(battlerAbility))
              && (flags.statDropPrevention || gBattlerAttacker != gBattlerTarget || flags.mirrorArmored) && !flags.certain && effect != EFFECT_CURSE)
        {
            if (flags.allowPtr)
            {
                if (gSpecialStatuses[battler].statLowered)
                {
                    gBattlescriptCurrInstr = BS_ptr;
                }
                else
                {
                    gBattleScripting.battler = battler;
                    if (battlerHoldEffect == HOLD_EFFECT_CLEAR_AMULET)
                    {
                        gLastUsedItem = gBattleMons[battler].item;
                        BattleScriptPush(BS_ptr);
                        gBattlescriptCurrInstr = BattleScript_ItemNoStatLoss;
                        RecordItemEffectBattle(battler, HOLD_EFFECT_CLEAR_AMULET);
                    }
                    else
                    {
                        gBattlerAbility = battler;
                        BattleScriptPush(BS_ptr);
                        gBattlescriptCurrInstr = BattleScript_AbilityNoStatLoss;
                        gLastUsedAbility = battlerAbility;
                        RecordAbilityBattle(battler, gLastUsedAbility);
                    }
                    gSpecialStatuses[battler].statLowered = TRUE;
                }
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if ((index = IsFlowerVeilProtected(battler)) && !flags.certain)
        {
            if (flags.allowPtr)
            {
                if (gSpecialStatuses[battler].statLowered)
                {
                    gBattlescriptCurrInstr = BS_ptr;
                }
                else
                {
                    BattleScriptPush(BS_ptr);
                    gBattleScripting.battler = battler;
                    gBattlerAbility = index - 1;
                    gBattlescriptCurrInstr = BattleScript_FlowerVeilProtectsRet;
                    gLastUsedAbility = ABILITY_FLOWER_VEIL;
                    gSpecialStatuses[battler].statLowered = TRUE;
                }
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (!flags.certain
                && (((battlerAbility == ABILITY_KEEN_EYE || battlerAbility == ABILITY_MINDS_EYE) && statId == STAT_ACC)
                || (GetConfig(CONFIG_ILLUMINATE_EFFECT) >= GEN_9 && battlerAbility == ABILITY_ILLUMINATE && statId == STAT_ACC)
                || (battlerAbility == ABILITY_HYPER_CUTTER && statId == STAT_ATK)
                || (battlerAbility == ABILITY_BIG_PECKS && statId == STAT_DEF)))
        {
            if (flags.allowPtr)
            {
                BattleScriptPush(BS_ptr);
                gBattleScripting.battler = battler;
                gBattlerAbility = battler;
                gBattlescriptCurrInstr = BattleScript_AbilityNoSpecificStatLoss;
                gLastUsedAbility = battlerAbility;
                RecordAbilityBattle(battler, gLastUsedAbility);
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (battlerAbility == ABILITY_MIRROR_ARMOR && !flags.mirrorArmored && gBattlerAttacker != gBattlerTarget && battler == gBattlerTarget)
        {
            if (GetMoveEffect(gCurrentMove) == EFFECT_PARTING_SHOT)
                gBattleScripting.animTargetsHit = 1;
            if (flags.allowPtr)
            {
                SET_STATCHANGER(statId, GET_STAT_BUFF_VALUE(statValue) | STAT_BUFF_NEGATIVE, TRUE);
                BattleScriptPush(BS_ptr);
                gBattleScripting.battler = battler;
                gBattlerAbility = battler;
                gBattlescriptCurrInstr = BattleScript_MirrorArmorReflect;
                RecordAbilityBattle(battler, gBattleMons[battler].ability);
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else // try to decrease
        {
            statValue = -GET_STAT_BUFF_VALUE(statValue);
            if (gBattleMons[battler].statStages[statId] == (MIN_STAT_STAGE + 1))
                statValue = -1;
            else if (gBattleMons[battler].statStages[statId] == 2 && statValue < -2)
                statValue = -2;

            if (statValue == -2)
            {
                PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_STATHARSHLY);
            }
            else if (statValue <= -3)
            {
                PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_SEVERELY);
            }
            else
            {
                PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_EMPTYSTRING3);
            }

            gBattleCommunication[MULTISTRING_CHOOSER] = (gBattlerTarget == battler); // B_MSG_ATTACKER_STAT_CHANGED or B_MSG_DEFENDER_STAT_CHANGED

            if (gBattleMons[battler].statStages[statId] == MIN_STAT_STAGE)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_WONT_CHANGE;
                gBattleScripting.statChanger |= STAT_BUFF_NEGATIVE;
            }
            else if (!flags.onlyChecking)
            {
                gBattleMons[battler].volatiles.tryEjectPack = TRUE;
                gProtectStructs[battler].lashOutAffected = TRUE;
                gBattleScripting.statChanger |= STAT_BUFF_NEGATIVE;
            }
        }
    }
    else // stat increase
    {
        statValue = GET_STAT_BUFF_VALUE(statValue);
        if (gBattleMons[battler].statStages[statId] == MAX_STAT_STAGE - 1)
            statValue = 1;
        else if (gBattleMons[battler].statStages[statId] == MAX_STAT_STAGE - 2  && statValue > 2)
            statValue = 2;

        if (statValue == 2)
        {
            PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_STATSHARPLY);
        }
        else if (statValue >= 3)
        {
            PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_DRASTICALLY);
        }
        else
        {
            PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_EMPTYSTRING3);
        }

        gBattleCommunication[MULTISTRING_CHOOSER] = (gBattlerTarget == battler); // B_MSG_ATTACKER_STAT_CHANGED or B_MSG_DEFENDER_STAT_CHANGED

        if (gBattleMons[battler].statStages[statId] == MAX_STAT_STAGE)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_WONT_CHANGE;
            gBattleScripting.statChanger &= ~STAT_BUFF_NEGATIVE;
        }
        else if (!flags.onlyChecking)
        {
            u32 statIncrease;
            if ((statValue + gBattleMons[battler].statStages[statId]) > MAX_STAT_STAGE)
                statIncrease = MAX_STAT_STAGE - gBattleMons[battler].statStages[statId];
            else
                statIncrease = statValue;

            gProtectStructs[battler].statRaised = TRUE;
            gBattleScripting.statChanger &= ~STAT_BUFF_NEGATIVE;

            if (statIncrease)
            {
                // Check Mirror Herb / Opportunist
                for (enum BattlerId index = 0; index < gBattlersCount; index++)
                {
                    if (IsBattlerAlly(index, battler))
                        continue; // Only triggers on opposing side

                    if (GetBattlerAbility(index) == ABILITY_OPPORTUNIST
                     && gProtectStructs[battler].activateOpportunist == 0) // don't activate opportunist on other mon's opportunist raises
                    {
                        gProtectStructs[index].activateOpportunist = 2;      // set stats to copy
                    }
                    if (GetBattlerHoldEffect(index) == HOLD_EFFECT_MIRROR_HERB)
                    {
                        gProtectStructs[index].eatMirrorHerb = 1;
                    }

                    if (gProtectStructs[index].activateOpportunist == 2 || gProtectStructs[index].eatMirrorHerb == 1)
                    {
                        gQueuedStatBoosts[index].stats |= (1 << (statId - 1));    // -1 to start at atk
                        gQueuedStatBoosts[index].statChanges[statId - 1] += statIncrease;
                    }

                }
            }
        }
    }

    if (gBattleCommunication[MULTISTRING_CHOOSER] == B_MSG_STAT_WONT_CHANGE) // at max or min
    {
        if (!flags.allowPtr)
            return STAT_CHANGE_DIDNT_WORK;
        return STAT_CHANGE_WORKED;
    }

    if (flags.onlyChecking)
        return STAT_CHANGE_WORKED;

    gBattleMons[battler].statStages[statId] += statValue;
    if (gBattleMons[battler].statStages[statId] < MIN_STAT_STAGE)
        gBattleMons[battler].statStages[statId] = MIN_STAT_STAGE;
    if (gBattleMons[battler].statStages[statId] > MAX_STAT_STAGE)
        gBattleMons[battler].statStages[statId] = MAX_STAT_STAGE;

    if (ShouldDefiantCompetitiveActivate(battler, battlerAbility))
        stats = 0; // use single stat animations when Defiant/Competitive activate
    else
        stats &= ~(1u << statId);

    TryPlayStatChangeAnimation(battler, battlerAbility, stats, statValue, statId, flags.certain);

    return STAT_CHANGE_WORKED;
}

#define STATS_TO_CHANGE 0
bool32 CanAnyStatChange(enum BattlerId battler, enum Ability ability, enum Move move)
{
    u32 numAdditionalEffects = GetMoveAdditionalEffectCount(move);

    while (gBattleStruct->additionalEffectsCounter < numAdditionalEffects)
    {
        while (gBattleStruct->currStatToChange < NUM_STATS)
        {
            const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(move, additionalEffectsCounter);
            u32 stat = gBattleStruct->currStatToChange++;

            if (!IsStatSet(stat, additionalEffect))
                continue;

            if (IsStatDecreaseEffect(additionalEffect->moveEffect))
            {
                if (CompareStat(battler, stat, MIN_STAT_STAGE, CMP_EQUAL, ability))
                    continue;

                if (!CanStatDecrease())
                    return FALSE;

                gBattleStruct->statsToChange[STATS_TO_CHANGE] |= stat;
                gBattleStruct->statsToChange[stat] = -1 * stat;
            }
            else if (IsStatIncreaseEffect(additionalEffect->moveEffect))
            {
                if (CompareStat(battler, stat, MAX_STAT_STAGE, CMP_EQUAL, ability))
                    continue;

                gBattleStruct->statsToChange[STATS_TO_CHANGE] |= stat;
                gBattleStruct->statsToChange[stat] = stat;
            }
        }

        gBattleStruct->additionalEffectsCounter++;
    }

    return gBattleStruct->positiveStats || gBattleStruct->negativeStas;
}

void ApplyStatChanges(struct BattleContext *ctx, struct StatChange *st)
{
    for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
    {
        while (gBattleStruct->statsToChange[STATS_TO_CHANGE] & (1u << stat))
        {
            gBattleStruct->statsToChange[STATS_TO_CHANGE] &= ~(1u << stat);
            if (DecreaseStat(ctx, st) == STAT_CHANGE_WORKED)
                return;
        }

    }

    for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
    {
        while (gBattleStruct->statsToChange[STATS_TO_CHANGE] & (1u << stat))
        {
            gBattleStruct->statsToChange[STATS_TO_CHANGE] &= ~(1u << stat);
            if (IncreaseStat(ctx, st) == STAT_CHANGE_WORKED)
                return;
        }

    }
}

static enum StatChangeResult CanDecreaseStat(struct BattleContext *ctx, struct StatChange *st)
{
    enum StatChangeResult result = STAT_CHANGE_WORKED;
    const u8 *battleScript = NULL;
    u32 flowerVeilBattler = 0;
    bool32 isCurse = GetMoveEffect(ctx->move) == EFFECT_CURSE;
    bool32 canBePrevented = (st->passiveStatChange || ctx->battlerAtk != ctx->battlerDef || st->mirrorArmored)
                          && !st->certain
                          && !isCurse;

    if (gSideTimers[GetBattlerSide(ctx->battlerDef)].mistTimer
     && (!st->certain && !isCurse)
     && !(ctx->battlerAtk != ctx->battlerDef && ctx->abilityAtk == ABILITY_INFILTRATOR))
    {
        battleScript = BattleScript_MistProtected;
        result = STAT_CHANGE_DIDNT_WORK;
    }
    else if (canBePrevented && CanAbilityPreventStatLoss(ctx->abilityDef))
    {
        battleScript = BattleScript_AbilityNoStatLoss;

        if (!st->onlyChecking)
        {
            gLastUsedAbility = ctx->abilityDef;
            RecordAbilityBattle(ctx->battlerDef, gLastUsedAbility);
        }

        result = STAT_CHANGE_DIDNT_WORK;
    }
    else if (canBePrevented && ctx->holdEffectDef == HOLD_EFFECT_CLEAR_AMULET)
    {
        battleScript = BattleScript_ItemNoStatLoss;

        if (!st->onlyChecking)
        {
            gLastUsedItem = gBattleMons[ctx->battlerDef].item;
            RecordItemEffectBattle(ctx->battlerDef, HOLD_EFFECT_CLEAR_AMULET);
        }

        result = STAT_CHANGE_DIDNT_WORK;
    }
    else if ((flowerVeilBattler = IsFlowerVeilProtected(ctx->battlerDef)) && !st->certain)
    {
        battleScript = BattleScript_FlowerVeilProtectsRet;

        if (!st->onlyChecking)
        {
            gBattlerAbility = flowerVeilBattler - 1;
            gLastUsedAbility = ABILITY_FLOWER_VEIL;
            RecordAbilityBattle(gBattlerAbility, ABILITY_FLOWER_VEIL);
        }

        result = STAT_CHANGE_DIDNT_WORK;
    }
    else if (st->certain && AbilityPreventsSpecificStatDrop(ctx->abilityDef, st->stat))
    {
        battleScript = BattleScript_AbilityNoSpecificStatLoss;

        if (!st->onlyChecking)
        {
            gBattlerAbility = ctx->battlerDef;
            gLastUsedAbility = ctx->abilityDef;
            RecordAbilityBattle(ctx->battlerDef, gLastUsedAbility);
        }

        result = STAT_CHANGE_DIDNT_WORK;
    }
    else if (ctx->abilityDef == ABILITY_MIRROR_ARMOR && !st->mirrorArmored && ctx->battlerAtk != ctx->battlerDef)
    {
        if (GetMoveEffect(ctx->move) == EFFECT_PARTING_SHOT)
            gBattleScripting.animTargetsHit = 1;

        // TODO
        // SET_STATCHANGER(statId, GET_STAT_BUFF_VALUE(statValue) | STAT_BUFF_NEGATIVE, TRUE);
        battleScript = BattleScript_MirrorArmorReflect;

        if (!st->onlyChecking)
        {
            gBattlerAbility = ctx->battlerDef;
            RecordAbilityBattle(ctx->battlerDef, gBattleMons[ctx->battlerDef].ability);
        }

        result = STAT_CHANGE_DIDNT_WORK;
    }

    if (!st->onlyChecking && !st->silentFailure)
    {
        BattleScriptPush(st->battleScript);
        gBattlescriptCurrInstr = battleScript;
        gBattleScripting.battler = ctx->battlerDef;
    }

    return result;
}

static enum StatChangeResult DecreaseStat(struct BattleContext *ctx, struct StatChange *st)
{
    if (gBattleMons[ctx->battlerDef].statStages[st->stage] == (MIN_STAT_STAGE + 1))
        st->stage = -1;
    else if (gBattleMons[ctx->battlerDef].statStages[st->stage] == 2 && st->stage < -2)
        st->stage = -2;

    if (st->stage == -2)
    {
        PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_STATHARSHLY);
    }
    else if (st->stage <= -3)
    {
        PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_SEVERELY);
    }
    else
    {
        PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_EMPTYSTRING3);
    }

    gBattleCommunication[MULTISTRING_CHOOSER] = (ctx->battlerDef == ctx->battlerAtk); // B_MSG_ATTACKER_STAT_CHANGED or B_MSG_DEFENDER_STAT_CHANGED

    if (gBattleMons[ctx->battlerDef].statStages[st->stat] == MIN_STAT_STAGE)
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_WONT_CHANGE;
        gBattleScripting.statChanger |= STAT_BUFF_NEGATIVE;
    }
    else if (!st->onlyChecking)
    {
        gBattleMons[ctx->battlerDef].volatiles.tryEjectPack = TRUE;
        gProtectStructs[ctx->battlerDef].lashOutAffected = TRUE;
        gBattleScripting.statChanger |= STAT_BUFF_NEGATIVE;
    }

    if (gBattleCommunication[MULTISTRING_CHOOSER] == B_MSG_STAT_WONT_CHANGE) // at max or min
    {
        if (st->printStatCantChangeMsg) // The message can be silent
            return STAT_CHANGE_WORKED;
        return STAT_CHANGE_DIDNT_WORK;
    }

    if (!st->onlyChecking)
    {
        gBattleMons[ctx->battlerDef].statStages[st->stat] += st->stage;
        if (gBattleMons[ctx->battlerDef].statStages[st->stat] < MIN_STAT_STAGE)
            gBattleMons[ctx->battlerDef].statStages[st->stat] = MIN_STAT_STAGE;
        New_TryPlayStatChangeAnimation(ctx, st);
    }

    return STAT_CHANGE_WORKED;
}

static enum StatChangeResult IncreaseStat(struct BattleContext *ctx, struct StatChange *st)
{
    if (gBattleMons[ctx->battlerDef].statStages[st->stat] == MAX_STAT_STAGE - 1)
        st->stage = 1;
    else if (gBattleMons[ctx->battlerDef].statStages[st->stat] == MAX_STAT_STAGE - 2  && st->stage > 2)
        st->stage = 2;

    if (st->stage == 2)
    {
        PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_STATSHARPLY);
    }
    else if (st->stage >= 3)
    {
        PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_DRASTICALLY);
    }
    else
    {
        PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_EMPTYSTRING3);
    }

    gBattleCommunication[MULTISTRING_CHOOSER] = (ctx->battlerAtk == ctx->battlerDef); // B_MSG_ATTACKER_STAT_CHANGED or B_MSG_DEFENDER_STAT_CHANGED

    if (gBattleMons[ctx->battlerDef].statStages[st->stat] == MAX_STAT_STAGE)
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_WONT_CHANGE;
        gBattleScripting.statChanger &= ~STAT_BUFF_NEGATIVE;
    }
    else if (!st->onlyChecking)
    {
        u32 statIncrease = st->stat;

        if ((st->stage + gBattleMons[ctx->battlerDef].statStages[st->stat]) > MAX_STAT_STAGE)
            statIncrease = MAX_STAT_STAGE - gBattleMons[ctx->battlerDef].statStages[st->stat];

        gProtectStructs[ctx->battlerDef].statRaised = TRUE;
        gBattleScripting.statChanger &= ~STAT_BUFF_NEGATIVE;

        if (statIncrease)
        {
            // Check Mirror Herb / Opportunist
            for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
            {
                if (IsBattlerAlly(battler, ctx->battlerDef))
                    continue; // Only triggers on opposing side

                if (GetBattlerAbility(battler) == ABILITY_OPPORTUNIST
                 && gProtectStructs[ctx->battlerDef].activateOpportunist == 0) // don't activate opportunist on other mon's opportunist raises
                {
                    gProtectStructs[battler].activateOpportunist = 2;      // set stats to copy
                }
                if (GetBattlerHoldEffect(battler) == HOLD_EFFECT_MIRROR_HERB)
                {
                    gProtectStructs[battler].eatMirrorHerb = 1;
                }

                if (gProtectStructs[battler].activateOpportunist == 2 || gProtectStructs[battler].eatMirrorHerb == 1)
                {
                    gQueuedStatBoosts[battler].stats |= (1 << (st->stat - 1));    // -1 to start at atk
                    gQueuedStatBoosts[battler].statChanges[st->stat - 1] += statIncrease;
                }
            }
        }
    }

    if (gBattleCommunication[MULTISTRING_CHOOSER] == B_MSG_STAT_WONT_CHANGE) // at max or min
    {
        if (st->printStatCantChangeMsg) // The message can be silent
            return STAT_CHANGE_WORKED;
        return STAT_CHANGE_DIDNT_WORK;
    }

    if (!st->onlyChecking)
    {
        gBattleMons[ctx->battlerDef].statStages[st->stat] += st->stage;
        if (gBattleMons[ctx->battlerDef].statStages[st->stat] > MAX_STAT_STAGE)
            gBattleMons[ctx->battlerDef].statStages[st->stat] = MAX_STAT_STAGE;
        New_TryPlayStatChangeAnimation(ctx, st);
    }

    return STAT_CHANGE_WORKED;
}

// use positive_stats and negative stats
// collect them while you check if anything can be increased
static void New_TryPlayStatChangeAnimation(struct BattleContext *ctx, struct StatChange *st)
{
    u8 stats = 0; // temp to compile
    enum Stat currStat = 0;
    u32 statAnimId = st->stat;
    bool32 statChangeByTwo = st->stage > 1 || st->stage < -1;
    u32 changeableStatsCount = 1; // current stat is counted automatically

    if (ShouldDefiantCompetitiveActivate(ctx->battlerDef, ctx->abilityDef))
        stats = 0; // use single stat animations when Defiant/Competitive activate
    else
        stats &= ~(1u << st->stat); // counted in changeableStatsCount

    if (st->stage <= -1) // goes down
    {
        if (statChangeByTwo)
            statAnimId += STAT_ANIM_MINUS2;
        else
            statAnimId += STAT_ANIM_MINUS1;

        while (stats != 0)
        {
            if (stats & 1)
            {
                if (st->certain)
                {
                    if (gBattleMons[ctx->battlerDef].statStages[currStat] > MIN_STAT_STAGE)
                    {
                        changeableStatsCount++;
                        break;
                    }
                }
                else if (!AbilityPreventsSpecificStatDrop(ctx->abilityDef, currStat))
                {
                    if (gBattleMons[ctx->abilityDef].statStages[currStat] > MIN_STAT_STAGE)
                    {
                        changeableStatsCount++;
                        break;
                    }
                }
            }
            stats >>= 1, currStat++;
        }

        if (changeableStatsCount > 1) // more than one stat, so the color is gray
        {
            if (statChangeByTwo)
                statAnimId = STAT_ANIM_MULTIPLE_MINUS2;
            else
                statAnimId = STAT_ANIM_MULTIPLE_MINUS1;
        }
    }
    else // goes up
    {
        if (statChangeByTwo)
            statAnimId += STAT_ANIM_PLUS2;
        else
            statAnimId += STAT_ANIM_PLUS1;

        while (stats != 0)
        {
            if (stats & 1 && gBattleMons[ctx->battlerDef].statStages[currStat] < MAX_STAT_STAGE)
            {
                changeableStatsCount++;
                break;
            }
            stats >>= 1, currStat++;
        }

        if (changeableStatsCount > 1) // more than one stat, so the color is gray
        {
            if (statChangeByTwo)
                statAnimId = STAT_ANIM_MULTIPLE_PLUS2;
            else
                statAnimId = STAT_ANIM_MULTIPLE_PLUS1;
        }
    }

    if (!gBattleScripting.statAnimPlayed)
    {
        BtlController_EmitBattleAnimation(ctx->battlerDef, B_COMM_TO_CONTROLLER, B_ANIM_STATS_CHANGE, statAnimId);
        MarkBattlerForControllerExec(ctx->battlerDef);
        if (changeableStatsCount > 1)
            gBattleScripting.statAnimPlayed = TRUE;
    }
    else if (changeableStatsCount == 1) // final stat that can be changed
    {
        gBattleScripting.statAnimPlayed = FALSE;
    }
}
bool32 IsStatDecreaseEffect(u32 effect)
{
    return effect >= STAT_CHANGE_EFFECT_MINUS_1 && effect <= STAT_CHANGE_EFFECT_MINUS_6;
}

bool32 IsStatIncreaseEffect(u32 effect)
{
    return effect >= STAT_CHANGE_EFFECT_PLUS_1 && effect <= STAT_CHANGE_EFFECT_PLUS_6;
}

bool32 IsStatSet(u32 stat, const struct AdditionalEffect *additionalEffect)
{
    switch (stat)
    {
    case STAT_ATK:     return additionalEffect->attack;
    case STAT_DEF:     return additionalEffect->defense;
    case STAT_SPEED:   return additionalEffect->speed;
    case STAT_SPATK:   return additionalEffect->spAtk;
    case STAT_SPDEF:   return additionalEffect->spDef;
    case STAT_ACC:     return additionalEffect->accuracy;
    case STAT_EVASION: return additionalEffect->evasion;
    }

    return FALSE;
}

// This function is the body of "jumpifstat", but can be used dynamically in a function
bool32 CompareStat(enum BattlerId battler, enum Stat statId, u32 cmpTo, u32 cmpKind, enum Ability ability)
{
    bool32 ret = FALSE;
    u32 statValue = gBattleMons[battler].statStages[statId];

    // Because this command is used as a way of checking if a stat can be lowered/raised,
    // we need to do some modification at run-time.
    if (ability == ABILITY_CONTRARY)
    {
        if (cmpKind == CMP_GREATER_THAN)
            cmpKind = CMP_LESS_THAN;
        else if (cmpKind == CMP_LESS_THAN)
            cmpKind = CMP_GREATER_THAN;

        if (cmpTo == MIN_STAT_STAGE)
            cmpTo = MAX_STAT_STAGE;
        else if (cmpTo == MAX_STAT_STAGE)
            cmpTo = MIN_STAT_STAGE;
    }

    switch (cmpKind)
    {
    case CMP_EQUAL:
        if (statValue == cmpTo)
            ret = TRUE;
        break;
    case CMP_NOT_EQUAL:
        if (statValue != cmpTo)
            ret = TRUE;
        break;
    case CMP_GREATER_THAN:
        if (statValue > cmpTo)
            ret = TRUE;
        break;
    case CMP_LESS_THAN:
        if (statValue < cmpTo)
            ret = TRUE;
        break;
    case CMP_COMMON_BITS:
        if (statValue & cmpTo)
            ret = TRUE;
        break;
    case CMP_NO_COMMON_BITS:
        if (!(statValue & cmpTo))
            ret = TRUE;
        break;
    }

    return ret;
}

static u16 ReverseStatChangeMoveEffect(u16 moveEffect)
{
    switch (moveEffect)
    {
    // +1
    case MOVE_EFFECT_ATK_PLUS_1:    return MOVE_EFFECT_ATK_MINUS_1;
    case MOVE_EFFECT_DEF_PLUS_1:    return MOVE_EFFECT_DEF_MINUS_1;
    case MOVE_EFFECT_SPD_PLUS_1:    return MOVE_EFFECT_SPD_MINUS_1;
    case MOVE_EFFECT_SP_ATK_PLUS_1: return MOVE_EFFECT_SP_ATK_MINUS_1;
    case MOVE_EFFECT_SP_DEF_PLUS_1: return MOVE_EFFECT_SP_DEF_MINUS_1;
    case MOVE_EFFECT_ACC_PLUS_1:    return MOVE_EFFECT_ACC_MINUS_1;
    case MOVE_EFFECT_EVS_PLUS_1:    return MOVE_EFFECT_EVS_MINUS_1;
    // -1
    case MOVE_EFFECT_ATK_MINUS_1:   return MOVE_EFFECT_ATK_PLUS_1;
    case MOVE_EFFECT_DEF_MINUS_1:   return MOVE_EFFECT_DEF_PLUS_1;
    case MOVE_EFFECT_SPD_MINUS_1:   return MOVE_EFFECT_SPD_PLUS_1;
    case MOVE_EFFECT_SP_ATK_MINUS_1:return MOVE_EFFECT_SP_ATK_PLUS_1;
    case MOVE_EFFECT_SP_DEF_MINUS_1:return MOVE_EFFECT_SP_DEF_PLUS_1;
    case MOVE_EFFECT_ACC_MINUS_1:
        return MOVE_EFFECT_ACC_PLUS_1;
    case MOVE_EFFECT_EVS_MINUS_1:
    // +2
    case MOVE_EFFECT_ATK_PLUS_2:
        return MOVE_EFFECT_ATK_MINUS_2;
    case MOVE_EFFECT_DEF_PLUS_2:
        return MOVE_EFFECT_DEF_MINUS_2;
    case MOVE_EFFECT_SPD_PLUS_2:
        return MOVE_EFFECT_SPD_MINUS_2;
    case MOVE_EFFECT_SP_ATK_PLUS_2:
        return MOVE_EFFECT_SP_ATK_MINUS_2;
    case MOVE_EFFECT_SP_DEF_PLUS_2:
        return MOVE_EFFECT_SP_DEF_MINUS_2;
    case MOVE_EFFECT_ACC_PLUS_2:
        return MOVE_EFFECT_ACC_MINUS_2;
    case MOVE_EFFECT_EVS_PLUS_2:
        return MOVE_EFFECT_EVS_MINUS_2;
    // -2
    case MOVE_EFFECT_ATK_MINUS_2:
        return MOVE_EFFECT_ATK_PLUS_2;
    case MOVE_EFFECT_DEF_MINUS_2:
        return MOVE_EFFECT_DEF_PLUS_2;
    case MOVE_EFFECT_SPD_MINUS_2:
        return MOVE_EFFECT_SPD_PLUS_2;
    case MOVE_EFFECT_SP_ATK_MINUS_2:
        return MOVE_EFFECT_SP_ATK_PLUS_2;
    case MOVE_EFFECT_SP_DEF_MINUS_2:
        return MOVE_EFFECT_SP_DEF_PLUS_2;
    case MOVE_EFFECT_ACC_MINUS_2:
        return MOVE_EFFECT_ACC_PLUS_2;
    case MOVE_EFFECT_EVS_MINUS_2:
        return MOVE_EFFECT_EVS_PLUS_2;
    default:
        return 0;
    }
}

static bool32 CanAbilityPreventStatLoss(enum Ability abilityDef)
{
    switch (abilityDef)
    {
    case ABILITY_CLEAR_BODY:
    case ABILITY_FULL_METAL_BODY:
    case ABILITY_WHITE_SMOKE:
        return TRUE;
    default:
        break;
    }
    return FALSE;
}

static void TryPlayStatChangeAnimation(enum BattlerId battler, enum Ability ability, u32 stats, s32 statValue, u32 statId, bool32 certain)
{
    enum Stat currStat = 0;
    u32 changeableStatsCount = 1; // current stat is counted automatically
    u32 statAnimId = statId;
    bool32 statChangeByTwo = statValue > 1 || statValue < -1;

    if (statValue <= -1) // goes down
    {
        if (statChangeByTwo)
            statAnimId += STAT_ANIM_MINUS2;
        else
            statAnimId += STAT_ANIM_MINUS1;

        while (stats != 0)
        {
            if (stats & 1)
            {
                if (certain)
                {
                    if (gBattleMons[battler].statStages[currStat] > MIN_STAT_STAGE)
                    {
                        changeableStatsCount++;
                        break;
                    }
                }
                else if (!((ability == ABILITY_KEEN_EYE || ability == ABILITY_MINDS_EYE) && currStat == STAT_ACC)
                        && !(GetConfig(CONFIG_ILLUMINATE_EFFECT) >= GEN_9 && ability == ABILITY_ILLUMINATE && currStat == STAT_ACC)
                        && !(ability == ABILITY_HYPER_CUTTER && currStat == STAT_ATK)
                        && !(ability == ABILITY_BIG_PECKS && currStat == STAT_DEF))
                {
                    if (gBattleMons[battler].statStages[currStat] > MIN_STAT_STAGE)
                    {
                        changeableStatsCount++;
                        break;
                    }
                }
            }
            stats >>= 1, currStat++;
        }

        if (changeableStatsCount > 1) // more than one stat, so the color is gray
        {
            if (statChangeByTwo)
                statAnimId = STAT_ANIM_MULTIPLE_MINUS2;
            else
                statAnimId = STAT_ANIM_MULTIPLE_MINUS1;
        }
    }
    else // goes up
    {
        if (statChangeByTwo)
            statAnimId += STAT_ANIM_PLUS2;
        else
            statAnimId += STAT_ANIM_PLUS1;

        while (stats != 0)
        {
            if (stats & 1 && gBattleMons[battler].statStages[currStat] < MAX_STAT_STAGE)
            {
                changeableStatsCount++;
                break;
            }
            stats >>= 1, currStat++;
        }

        if (changeableStatsCount > 1) // more than one stat, so the color is gray
        {
            if (statChangeByTwo)
                statAnimId = STAT_ANIM_MULTIPLE_PLUS2;
            else
                statAnimId = STAT_ANIM_MULTIPLE_PLUS1;
        }
    }

    if (!gBattleScripting.statAnimPlayed)
    {
        BtlController_EmitBattleAnimation(battler, B_COMM_TO_CONTROLLER, B_ANIM_STATS_CHANGE, statAnimId);
        MarkBattlerForControllerExec(battler);
        if (changeableStatsCount > 1)
            gBattleScripting.statAnimPlayed = TRUE;
    }
    else if (changeableStatsCount == 1) // final stat that can be changed
    {
        gBattleScripting.statAnimPlayed = FALSE;
    }
}

static bool32 AbilityPreventsSpecificStatDrop(u32 ability, u32 stat)
{
    switch (ability)
    {
        case ABILITY_ILLUMINATE:
            if (B_ILLUMINATE_EFFECT < GEN_9)
                return FALSE;
        case ABILITY_KEEN_EYE:
        case ABILITY_MINDS_EYE:
            return stat == STAT_ACC;
        case ABILITY_HYPER_CUTTER:
            return stat == STAT_ATK;
        case ABILITY_BIG_PECKS:
            return stat == STAT_DEF;
        default:
            return FALSE;
    }
}

static void AdjustStatStage(struct BattleContext *ctx, struct StatChange *st)
{
    if (GetMoveEffect(ctx->move) == EFFECT_GROWTH && IsBattlerWeatherAffected(ctx->battlerDef, B_WEATHER_SUN))
        st->stage = 2;

    if (ctx->abilityDef == ABILITY_CONTRARY)
    {
        st->stage = st->stage * -1;
        if (st->updateAdditionalEffectStats)
            st->additionalEffect = ReverseStatChangeMoveEffect(st->additionalEffect);
    }
    else if (ctx->abilityDef == ABILITY_SIMPLE)
    {
        st->stage = st->stage * 2;
    }

    if (!st->onlyChecking)
        RecordAbilityBattle(ctx->battlerDef, ctx->abilityDef);
}
