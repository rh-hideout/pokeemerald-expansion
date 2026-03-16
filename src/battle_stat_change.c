#include "global.h"
#include "battle.h"
#include "battle_scripts.h"
#include "battle_util.h"
#include "battle_stat_change.h"
#include "battle_ai_record.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_ai_util.h"
#include "item.h"
#include "move.h"

static enum StatChangeResult CanDecreaseStat(struct BattleCalcValues *cv, struct StatChange *st);
static enum StatChangeResult DecreaseStat(struct BattleCalcValues *cv, struct StatChange *st);
static enum StatChangeResult IncreaseStat(struct BattleCalcValues  *cv, struct StatChange *st);

static void AdjustStatStage(struct BattleCalcValues *cv, struct StatChange *st);
static void TryPlayStatChangeAnimation(struct BattleCalcValues *cv, struct StatChange *st);

static bool32 CanAbilityPreventStatLoss(enum Ability ability);
static bool32 AbilityPreventsSpecificStatDrop(u32 ability, u32 stat);
static bool32 GetPositiveStatStage(u32 effect);
static bool32 GetNegativeStatStage(u32 effect);
static u32 GetNumPositiveStats(enum BattlerId battler);
static u32 GetNumNegativeStats(enum BattlerId battler);


bool32 CanAnyStatChange(struct BattleCalcValues *cv, struct StatChange *st)
{
    u32 numAdditionalEffects = GetMoveAdditionalEffectCount(cv->move);
    u32 additionalEffectsCounter = 0;
    u32 canAnyStatChange = FALSE;
    enum Stat currStatToChange = STAT_ATK;

    while (additionalEffectsCounter < numAdditionalEffects)
    {
        while (currStatToChange < NUM_STATS)
        {
            const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(cv->move, additionalEffectsCounter);
            st->stat = currStatToChange++;

            if (!IsStatSet(st->stat, additionalEffect))
                continue;

            if (IsStatDecreaseEffect(additionalEffect->moveEffect))
                st->stage = GetNegativeStatStage(additionalEffect->moveEffect);
            else
                st->stage = GetPositiveStatStage(additionalEffect->moveEffect);

            AdjustStatStage(cv, st);

            if (st->stage < 0)
            {
                if (CompareStat(cv->effectBattler, st->stat, MIN_STAT_STAGE, CMP_EQUAL, ABILITY_NONE))
                    continue;
            }
            else
            {
                if (CompareStat(cv->effectBattler, st->stat, MAX_STAT_STAGE, CMP_EQUAL, ABILITY_NONE))
                    continue;
            }

            if (st->stage < 0 && CanDecreaseStat(cv, st) == STAT_CHANGE_DIDNT_WORK)
                continue;

            gSpecialStatuses[cv->effectBattler].statStages[st->stat] = st->stage;
            canAnyStatChange = TRUE;
        }

        currStatToChange = STAT_ATK;
        additionalEffectsCounter++;
    }

    return canAnyStatChange;
}

void TryStatChange(struct BattleCalcValues *cv, struct StatChange *st)
{
    u32 numAdditionalEffects = GetMoveAdditionalEffectCount(cv->move);

    while (gBattleStruct->additionalEffectsCounter < numAdditionalEffects)
    {
        while (gBattleStruct->currStatToChange < NUM_STATS)
        {
            const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(gCurrentMove, gBattleStruct->additionalEffectsCounter);
            st->stat = gBattleStruct->currStatToChange++;

            if (!IsStatSet(st->stat, additionalEffect))
                continue;

            if (IsStatDecreaseEffect(additionalEffect->moveEffect))
                st->stage = GetNegativeStatStage(additionalEffect->moveEffect);
            else
                st->stage = GetPositiveStatStage(additionalEffect->moveEffect);

            AdjustStatStage(cv, st);

            if (st->stage < 0)
            {
                if (CanDecreaseStat(cv, st) == STAT_CHANGE_DIDNT_WORK)
                    return;

                if (DecreaseStat(cv, st) == STAT_CHANGE_WORKED)
                {
                    st->battleScript = BattleScript_DecreaseStatChangeMessage;
                    return;
                }
            }
            else if (IncreaseStat(cv, st) == STAT_CHANGE_WORKED)
            {
                st->battleScript = BattleScript_IncreaseStatChangeMessage;
                return;
            }
        }

        gBattleStruct->additionalEffectsCounter++;
        gBattleStruct->currStatToChange = STAT_ATK;
        gBattleScripting.statAnimPlayed = FALSE;
    }

    gBattleStruct->moveResultFlags[cv->effectBattler] |= MOVE_RESULT_DOESNT_AFFECT_FOE;
    gBattleStruct->additionalEffectsCounter = 0;
    st->nextBattler = TRUE;
}

enum StatChangeResult TryNonMoveStatChange(struct BattleCalcValues *cv, struct StatChange *st)
{
    // Contrary will not work correctly here
    switch (gBattleStruct->statChangeProcess)
    {
    case PROCESS_ADJUST_STATS:
        gBattleStruct->currStatToChange = PROCESS_NEGATIVE_STATS;
        // fallthrough
    case PROCESS_NEGATIVE_STATS:
        while (gBattleStruct->currStatToChange < NUM_STATS)
        {
            st->stat = gBattleStruct->currStatToChange++;
            st->stage = gSpecialStatuses[cv->effectBattler].statStages[st->stat];

            if (st->stage >= 0)
                continue;

            if (DecreaseStat(cv, st) == STAT_CHANGE_WORKED)
            {
                st->battleScript = BattleScript_DecreaseStatChangeMessage;
                return STAT_CHANGE_WORKED;
            }
        }
        gBattleStruct->statChangeProcess = PROCESS_POSITIVE_STATS;
        gBattleStruct->currStatToChange = STAT_ATK;
        gBattleScripting.statAnimPlayed = FALSE;
        break;
    case PROCESS_POSITIVE_STATS:
        while (gBattleStruct->currStatToChange < NUM_STATS)
        {
            st->stat = gBattleStruct->currStatToChange++;
            st->stage = gSpecialStatuses[cv->effectBattler].statStages[st->stat];

            if (st->stage <= 0)
                continue;

            AdjustStatStage(cv, st);

            if (IncreaseStat(cv, st) == STAT_CHANGE_WORKED)
            {
                st->battleScript = BattleScript_IncreaseStatChangeMessage;
                return STAT_CHANGE_WORKED;
            }
        }
        gBattleStruct->statChangeProcess = PROCESS_STATS_DONE;
        gBattleStruct->currStatToChange = STAT_ATK;
        gBattleScripting.statAnimPlayed = FALSE;
        break;
    case PROCESS_STATS_DONE:
        break;
    }

    return STAT_CHANGE_DIDNT_WORK;
}

static enum StatChangeResult CanDecreaseStat(struct BattleCalcValues *cv, struct StatChange *st)
{
    enum StatChangeResult result = STAT_CHANGE_WORKED;

    u32 flowerVeilBattler = 0;
    bool32 isCurse = GetMoveEffect(cv->move) == EFFECT_CURSE;
    bool32 isSelf = cv->battlerAtk == cv->effectBattler;
    bool32 canBePrevented = (st->passiveStatChange || !isSelf || st->mirrorArmored)
                          && !st->certain
                          && !isCurse;

    enum Ability abilityAtk = cv->abilities[cv->battlerAtk];
    enum Ability abilityEff = cv->abilities[cv->effectBattler];


    if (gSideTimers[GetBattlerSide(cv->effectBattler)].mistTimer
     && !st->certain
     && !isCurse
     && (isSelf || abilityAtk != ABILITY_INFILTRATOR))
    {
        if (!st->onlyChecking)
        {
            st->battleScript = BattleScript_MistProtected;
        }

        result = STAT_CHANGE_DIDNT_WORK;
    }
    else if (canBePrevented && CanAbilityPreventStatLoss(abilityEff))
    {
        if (!st->onlyChecking)
        {
            st->battleScript = BattleScript_AbilityNoStatLoss;
            gLastUsedAbility = abilityEff;
            RecordAbilityBattle(cv->effectBattler, abilityEff);
        }

        result = STAT_CHANGE_DIDNT_WORK;
    }
    else if (canBePrevented && cv->holdEffects[cv->effectBattler] == HOLD_EFFECT_CLEAR_AMULET)
    {
        if (!st->onlyChecking)
        {
            st->battleScript = BattleScript_ItemNoStatLoss;
            gLastUsedItem = gBattleMons[cv->effectBattler].item;
            RecordItemEffectBattle(cv->effectBattler, HOLD_EFFECT_CLEAR_AMULET);
        }

        result = STAT_CHANGE_DIDNT_WORK;
    }
    else if (!st->certain && (flowerVeilBattler = IsFlowerVeilProtected(cv->effectBattler)))
    {
        if (!st->onlyChecking)
        {
            st->battleScript = BattleScript_FlowerVeilProtectsRet;
            gBattleScripting.battler = gBattlerAbility = flowerVeilBattler - 1;
            gLastUsedAbility = ABILITY_FLOWER_VEIL;
            RecordAbilityBattle(gBattlerAbility, ABILITY_FLOWER_VEIL);
        }

        result = STAT_CHANGE_DIDNT_WORK;
    }
    else if (!st->certain && AbilityPreventsSpecificStatDrop(abilityEff, st->stat))
    {
        if (!st->onlyChecking)
        {
            st->battleScript = BattleScript_AbilityNoSpecificStatLoss;
            gBattleScripting.battler = gBattlerAbility = cv->effectBattler;
            gLastUsedAbility = abilityEff;
            RecordAbilityBattle(cv->effectBattler, gLastUsedAbility);
        }

        result = STAT_CHANGE_DIDNT_WORK;
    }
    else if (abilityEff == ABILITY_MIRROR_ARMOR && !st->mirrorArmored && !isSelf)
    {
        if (GetMoveEffect(cv->move) == EFFECT_PARTING_SHOT)
            gBattleScripting.animTargetsHit = 1;

        // TODO
        // SET_STATCHANGER(statId, GET_STAT_BUFF_VALUE(statValue) | STAT_BUFF_NEGATIVE, TRUE);

        // TODO
        if (!st->onlyChecking)
        {
            st->battleScript = BattleScript_MirrorArmorReflect;
            gBattlerAbility = cv->effectBattler;
            RecordAbilityBattle(cv->effectBattler, abilityEff);
        }

        result = STAT_CHANGE_DIDNT_WORK;
    }

    if (!st->onlyChecking && result == STAT_CHANGE_DIDNT_WORK)
    {
        gBattleStruct->moveResultFlags[cv->effectBattler] |= MOVE_RESULT_DOESNT_AFFECT_FOE;
        PREPARE_STAT_BUFFER(gBattleTextBuff1, st->stat);
        gEffectBattler = cv->effectBattler;
    }

    return result;
}

static enum StatChangeResult DecreaseStat(struct BattleCalcValues *cv, struct StatChange *st)
{
    u32 currStage = gBattleMons[cv->effectBattler].statStages[st->stat];

    PREPARE_STAT_BUFFER(gBattleTextBuff1, st->stat);

    if (currStage == (MIN_STAT_STAGE + 1))
        st->stage = -1;
    else if (currStage == 2 && st->stage < -2)
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

    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_BATTLER_STAT_CHANGED;

    if (currStage == MIN_STAT_STAGE)
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_WONT_CHANGE;
        gBattleScripting.statChanger |= STAT_BUFF_NEGATIVE;
        if (st->silentFailure)
            return STAT_CHANGE_WORKED;
        return STAT_CHANGE_DIDNT_WORK;
    }
    else if (!st->onlyChecking)
    {
        gBattleMons[cv->effectBattler].volatiles.tryEjectPack = TRUE;
        gProtectStructs[cv->effectBattler].lashOutAffected = TRUE;
        gBattleScripting.statChanger |= STAT_BUFF_NEGATIVE;
    }

    if (!st->onlyChecking)
    {
        gEffectBattler = cv->effectBattler;
        gBattleMons[cv->effectBattler].statStages[st->stat] += st->stage;
        if (gBattleMons[cv->effectBattler].statStages[st->stat] < MIN_STAT_STAGE)
            gBattleMons[cv->effectBattler].statStages[st->stat] = MIN_STAT_STAGE;
        TryPlayStatChangeAnimation(cv, st);
    }

    return STAT_CHANGE_WORKED;
}

static enum StatChangeResult IncreaseStat(struct BattleCalcValues *cv, struct StatChange *st)
{
    u32 currStage = gBattleMons[cv->effectBattler].statStages[st->stat];

    PREPARE_STAT_BUFFER(gBattleTextBuff1, st->stat);

    if (currStage == MAX_STAT_STAGE - 1)
        st->stage = 1;
    else if (currStage == MAX_STAT_STAGE - 2  && st->stage > 2)
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

    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_BATTLER_STAT_CHANGED;

    if (gBattleMons[cv->effectBattler].statStages[st->stat] == MAX_STAT_STAGE)
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_WONT_CHANGE;
        gBattleScripting.statChanger &= ~STAT_BUFF_NEGATIVE;
        if (st->silentFailure)
            return STAT_CHANGE_WORKED;
        return STAT_CHANGE_DIDNT_WORK;
    }
    else if (!st->onlyChecking)
    {
        u32 statIncrease = st->stat;

        if ((st->stage + gBattleMons[cv->effectBattler].statStages[st->stat]) > MAX_STAT_STAGE)
            statIncrease = MAX_STAT_STAGE - gBattleMons[cv->effectBattler].statStages[st->stat];

        gProtectStructs[cv->effectBattler].statRaised = TRUE;
        gBattleScripting.statChanger &= ~STAT_BUFF_NEGATIVE;

        if (statIncrease)
        {
            // Check Mirror Herb / Opportunist
            for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
            {
                if (IsBattlerAlly(battler, cv->effectBattler))
                    continue; // Only triggers on opposing side

                if (GetBattlerAbility(battler) == ABILITY_OPPORTUNIST
                 && gProtectStructs[cv->effectBattler].activateOpportunist == 0) // don't activate opportunist on other mon's opportunist raises
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

    if (!st->onlyChecking)
    {
        gEffectBattler = cv->effectBattler;
        gBattleMons[cv->effectBattler].statStages[st->stat] += st->stage;
        if (gBattleMons[cv->effectBattler].statStages[st->stat] > MAX_STAT_STAGE)
            gBattleMons[cv->effectBattler].statStages[st->stat] = MAX_STAT_STAGE;
        TryPlayStatChangeAnimation(cv, st);
    }

    return STAT_CHANGE_WORKED;
}

static void TryPlayStatChangeAnimation(struct BattleCalcValues *cv, struct StatChange *st)
{
    u32 statAnimId = st->stat;

    if (gBattleScripting.statAnimPlayed)
        return;

    if (st->stage <= -1) // goes down
    {
        u32 isStatChangeByTwo = abs(st->stage) > 1;
        u32 numNegativeStats = GetNumNegativeStats(cv->effectBattler);

        statAnimId += isStatChangeByTwo ? STAT_ANIM_MINUS2 : STAT_ANIM_MINUS1;

        if (ShouldDefiantCompetitiveActivate(cv->effectBattler, cv->abilities[cv->effectBattler]))
            numNegativeStats = 0;

        if (numNegativeStats > 1) // more than one stat, so the color is gray
            statAnimId = isStatChangeByTwo ? STAT_ANIM_MULTIPLE_MINUS2 : STAT_ANIM_MULTIPLE_MINUS1;
    }
    else // goes up
    {
        u32 isStatChangeByTwo = st->stage > 1;
        u32 numPositiveStats = GetNumPositiveStats(cv->effectBattler);

        statAnimId += isStatChangeByTwo ? STAT_ANIM_PLUS2 : STAT_ANIM_PLUS1;

        if (ShouldDefiantCompetitiveActivate(cv->effectBattler, cv->abilities[cv->effectBattler]))
            numPositiveStats = 0;

        if (numPositiveStats > 1)
            statAnimId = isStatChangeByTwo ? STAT_ANIM_MULTIPLE_PLUS2 : STAT_ANIM_MULTIPLE_PLUS1;
    }

    BtlController_EmitBattleAnimation(cv->effectBattler, B_COMM_TO_CONTROLLER, B_ANIM_STATS_CHANGE, statAnimId);
    MarkBattlerForControllerExec(cv->effectBattler);
    gBattleScripting.statAnimPlayed = TRUE;
}

static void AdjustStatStage(struct BattleCalcValues *cv, struct StatChange *st)
{
    if (GetMoveEffect(cv->move) == EFFECT_GROWTH && IsBattlerWeatherAffected(cv->holdEffects[cv->effectBattler], GetWeather(), B_WEATHER_SUN))
        st->stage = 2;

    switch (cv->abilities[cv->effectBattler])
    {
    case ABILITY_CONTRARY:
        st->stage = st->stage * -1;
        if (!st->onlyChecking)
            RecordAbilityBattle(cv->effectBattler, cv->abilities[cv->effectBattler]);
        break;
    case ABILITY_SIMPLE:
        st->stage = st->stage * 2;
        if (!st->onlyChecking)
            RecordAbilityBattle(cv->effectBattler, cv->abilities[cv->effectBattler]);
        break;
    default:
        break;
    }
}

static bool32 CanAbilityPreventStatLoss(enum Ability ability)
{
    switch (ability)
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

bool32 IsStatDecreaseEffect(u32 effect)
{
    return effect >= STAT_CHANGE_EFFECT_MINUS_1 && effect <= STAT_CHANGE_EFFECT_MINUS_6;
}

bool32 UNUSED IsStatIncreaseEffect(u32 effect)
{
    return effect >= STAT_CHANGE_EFFECT_PLUS_1 && effect <= STAT_CHANGE_EFFECT_PLUS_6;
}

static bool32 GetPositiveStatStage(u32 effect)
{
    return effect - STAT_CHANGE_EFFECT_PLUS_1 + 1;
}

static bool32 GetNegativeStatStage(u32 effect)
{
    return -1 * (effect - STAT_CHANGE_EFFECT_MINUS_1 + 1);
}

static u32 GetNumPositiveStats(enum BattlerId battler)
{
    u32 num = 0;
    for (enum Stat stat = STAT_ATK; stat < NUM_STATS; stat++)
    {
        if (gSpecialStatuses[battler].statStages[stat] > 0)
            num++;
    }
    return num;
}

static u32 GetNumNegativeStats(enum BattlerId battler)
{
    u32 num = 0;
    for (enum Stat stat = STAT_ATK; stat < NUM_STATS; stat++)
    {
        if (gSpecialStatuses[battler].statStages[stat] < 0)
            num++;
    }
    return num;
}

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

// OLD FUNCTIONS
u32 ChangeStatBuffs(enum BattlerId battler, s8 statValue, enum Stat statId, union StatChangeFlags flags, u32 stats, const u8 *BS_ptr) { return STAT_CHANGE_WORKED; }

