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
static u32 GetNumPositiveStats(struct StatChange *st);
static u32 GetNumNegativeStats(struct StatChange *st);
static void SetAdditionalEffectsOnStatChange(struct BattleCalcValues *cv, struct StatChange *st);
static void MarkStatsAsDone(struct StatChange *st, u32 stat);

u32 static const sAccurateStatOrder[NUM_BATTLE_STATS] =
{
    STAT_HP,
    STAT_ATK,
    STAT_DEF,
    STAT_SPATK,
    STAT_SPDEF,
    STAT_SPEED,
    STAT_ACC,
    STAT_EVASION,
};

bool32 CanStatChange(struct BattleCalcValues *cv, struct StatChange *st)
{
    AdjustStatStage(cv, st);

    if (st->stage < 0)
    {
        if (CompareStat(st->battler, st->stat, MIN_STAT_STAGE, CMP_EQUAL, ABILITY_NONE))
            return FALSE;

        if (st->stage < 0 && CanDecreaseStat(cv, st) == STAT_CHANGE_DIDNT_WORK)
            return FALSE;
    }
    else
    {
        if (CompareStat(st->battler, st->stat, MAX_STAT_STAGE, CMP_EQUAL, ABILITY_NONE))
            return FALSE;
    }

    return TRUE;
}

static void SetStrengthSapHealing(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Stat stat)
{
    u32 healAmount = 0;
    switch (stat)
    {
    case STAT_ATK:
        healAmount = gBattleMons[battlerDef].attack;
        break;
    case STAT_DEF:
        healAmount = gBattleMons[battlerDef].defense;
        break;
    case STAT_SPATK:
        healAmount = gBattleMons[battlerDef].spAttack;
        break;
    case STAT_SPDEF:
        healAmount = gBattleMons[battlerDef].spDefense;
        break;
    case STAT_SPEED:
        healAmount = gBattleMons[battlerDef].speed;
        break;
    default:
        errorf("Illegal stat requested");
        return;
    }

    healAmount *= gStatStageRatios[gBattleMons[battlerDef].statStages[stat]][0];
    healAmount /= gStatStageRatios[gBattleMons[battlerDef].statStages[stat]][1];
    gBattleStruct->passiveHpUpdate[battlerAtk] = healAmount;
}

// This is not very user friendly but it guarantees that everything works for spread moves as well
static bool32 CheckSpecificMoveCondition(struct BattleCalcValues *cv, struct StatChange *st)
{
    switch (GetMoveEffect(cv->move))
    {
    case EFFECT_CAPTIVATE:
        if (cv->abilities[st->battler] == ABILITY_OBLIVIOUS)
        {
            if (!st->onlyChecking)
            {
                st->script = BattleScript_AbilityPopUp;
                gBattlerAbility = st->battler;
                gLastUsedAbility = ABILITY_OBLIVIOUS;
                RecordAbilityBattle(st->battler, ABILITY_OBLIVIOUS);
            }
            return TRUE;
        }
        break;
    case EFFECT_STRENGTH_SAP:
        if (CompareStat(st->battler, STAT_ATK, MIN_STAT_STAGE, CMP_EQUAL, ABILITY_NONE))
        {
            if (!st->onlyChecking)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_WONT_CHANGE;
                st->script = BattleScript_DecreaseStatChangeMessage;
                gBattleScripting.battler = st->battler;
            }
            return TRUE;
        }
        else
        {
            SetStrengthSapHealing(cv->battlerAtk, st->battler, STAT_ATK);
            st->additionalEffectTriggers = TRUE;
        }
        break;
    case EFFECT_ROTOTILLER:
        if (!IsBattlerGrounded(st->battler, cv->abilities[st->battler], cv->holdEffects[st->battler])
         || !IS_BATTLER_OF_TYPE(st->battler, TYPE_GRASS))
        {
            if (!st->onlyChecking)
            {
                st->script = BattleScript_ItDoesntAffectScrTarget;
                gBattleScripting.battler = st->battler;
            }
            return TRUE;
        }
        break;
    case EFFECT_TOXIC_THREAD:
        if (CanBePoisoned(cv->battlerAtk, st->battler, cv->abilities[cv->battlerAtk], cv->abilities[cv->battlerDef]))
        {
            st->additionalEffectTriggers = TRUE;
            if (!st->onlyChecking)
                st->moveScript = BattleScript_ToxicThread;
        }
        break;
    case EFFECT_SWAGGER:
        if (cv->abilities[st->battler] == ABILITY_OWN_TEMPO)
        {
            if (!st->onlyChecking)
            {
                st->moveScript = BattleScript_OwnTempoPreventsRet;
                gBattlerAbility = st->battler;
                gLastUsedAbility = ABILITY_OWN_TEMPO;
                RecordAbilityBattle(st->battler, ABILITY_OWN_TEMPO);
            }
        }
        else if (CanBeConfused(cv->battlerAtk, st->battler))
        {
            st->additionalEffectTriggers = TRUE;
            if (!st->onlyChecking)
                st->moveScript = BattleScript_SwaggerConfusion;
        }
        break;
    case EFFECT_TAR_SHOT:
        if (!gBattleMons[st->battler].volatiles.tarShot && GetActiveGimmick(st->battler) != GIMMICK_TERA)
        {
            st->additionalEffectTriggers = TRUE;
            if (!st->onlyChecking)
            {
                gBattleMons[st->battler].volatiles.tarShot = TRUE;
                st->moveScript = BattleScript_TarShotMessage;
            }
        }
        break;
    default:
        break;
    }

    return FALSE;

}

static bool32 IsSubstituteBlocked(struct BattleCalcValues *cv, struct StatChange *st)
{
    if (st->ignoreCertainFailure && !st->silentFailure)
        return FALSE;

    if (st->certain || GetBattlerMoveTargetType(cv->battlerAtk, cv->move) == TARGET_ALLY)
        return FALSE;

    if (!DoesSubstituteBlockMoveInternal(cv->battlerAtk, st->battler, cv->abilities[cv->battlerAtk], cv->move))
        return FALSE;

    if (!st->onlyChecking)
    {
        gBattleScripting.battler = st->battler;
        st->script = BattleScript_ButItFailedRet;
    }

    return TRUE;
}

// Multi stat checks
bool32 CanAnyStatChange(struct BattleCalcValues *cv, struct StatChange *st)
{
    u32 numAdditionalEffects = GetMoveAdditionalEffectCount(cv->move);
    bool32 canAnyStatChange = FALSE;
    bool32 statChangeBlockedOnBattler = FALSE;

    if (CheckSpecificMoveCondition(cv, st) || IsSubstituteBlocked(cv, st))
        statChangeBlockedOnBattler = TRUE;

    for (u32 i = 0; i < numAdditionalEffects; i++)
    {
        const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(cv->move, i);

        for (enum Stat j = STAT_ATK; j < NUM_BATTLE_STATS; j++)
        {
            st->stat = sAccurateStatOrder[j];
            st->stage = GetStatStage(st->stat, additionalEffect);

            if (st->stage == 0)
                continue;

            if (additionalEffect->moveEffect == STAT_CHANGE_EFFECT_MINUS)
                st->stage = -1 * st->stage;

            SetStatChange(st->battler, st->stat, st->stage);

            if (statChangeBlockedOnBattler) // Still need to collect stats for proper failure
                continue;

            if (cv->move == MOVE_BELLY_DRUM && !CompareStat(st->battler, st->stat, MAX_STAT_STAGE, CMP_EQUAL, ABILITY_NONE))
            {
                canAnyStatChange = TRUE;
                continue;
            }

            AdjustStatStage(cv, st);

            if (st->stage < 0)
            {
                if (CompareStat(st->battler, st->stat, MIN_STAT_STAGE, CMP_EQUAL, ABILITY_NONE))
                    continue;
            }
            else
            {
                if (CompareStat(st->battler, st->stat, MAX_STAT_STAGE, CMP_EQUAL, ABILITY_NONE))
                    continue;
            }

            if (st->stage < 0 && CanDecreaseStat(cv, st) == STAT_CHANGE_DIDNT_WORK)
                continue;

            canAnyStatChange = TRUE;
        }
    }

    return canAnyStatChange;
}

enum StatChangeResult TryStatChange(struct BattleCalcValues *cv, struct StatChange *st)
{
    if (CheckSpecificMoveCondition(cv, st))
    {
        st->nextBattler = TRUE;
        return STAT_CHANGE_BLOCKED_BY_TARGET;
    }

    enum StatChangeResult result = STAT_CHANGE_DIDNT_WORK;
    for (u32 i = 0; i < st->statStageAmount; i++)
    {
        if (i + 1 == st->statStageAmount) // Avoids redundant looping
            st->nextBattler = TRUE;

        if (st->statStageQueue[i].done)
            continue;

        st->stat = st->statStageQueue[i].stat;
        st->stage = st->statStageQueue[i].stage;
        st->statStageQueue[i].done = TRUE;

        AdjustStatStage(cv, st);
        if (st->stage < 0)
        {
            if (CanDecreaseStat(cv, st) == STAT_CHANGE_DIDNT_WORK)
            {
                if (st->silentFailure)
                    continue;
                result = STAT_CHANGE_BLOCKED_BY_TARGET;
                break;
            }

            if (DecreaseStat(cv, st) == STAT_CHANGE_WORKED)
            {
                result = STAT_CHANGE_WORKED;
                break;
            }
        }
        else if (IncreaseStat(cv, st) == STAT_CHANGE_WORKED)
        {
            result = STAT_CHANGE_WORKED;
            break;
        }
    }

    if (st->nextBattler && !st->onlyChecking) // Set volatiles after all stats are done
        SetAdditionalEffectsOnStatChange(cv, st);

    return result;
}

enum StatChangeResult TrySingleStatChange(struct BattleCalcValues *cv, struct StatChange *st)
{
    AdjustStatStage(cv, st);

    if (st->stage < 0)
    {
        if (CanDecreaseStat(cv, st) == STAT_CHANGE_DIDNT_WORK)
            return STAT_CHANGE_DIDNT_WORK;

        if (DecreaseStat(cv, st) == STAT_CHANGE_WORKED)
            return STAT_CHANGE_WORKED;
    }
    else if (IncreaseStat(cv, st) == STAT_CHANGE_WORKED)
    {
        return STAT_CHANGE_WORKED;
    }

    return STAT_CHANGE_DIDNT_WORK;
}

static bool32 IsMistProtected(struct BattleCalcValues *cv, struct StatChange *st)
{
    if (gSideTimers[GetBattlerSide(st->battler)].mistTimer == 0)
        return FALSE;

    if (st->certain)
        return FALSE;

    if (st->battler == cv->battlerDef && cv->abilities[cv->battlerAtk] == ABILITY_INFILTRATOR)
        return FALSE;

    if (!st->onlyChecking)
    {
        MarkStatsAsDone(st, NUM_BATTLE_STATS);
        gBattleScripting.battler = st->battler;
        st->script = BattleScript_MistProtected;
    }

    return TRUE;
}

static bool32 IsFlowerVeilBlocked(struct BattleCalcValues *cv, struct StatChange *st)
{
    if (st->certain)
        return FALSE;

    u32 flowerVeilBattler = IsFlowerVeilProtected(st->battler);
    if (!flowerVeilBattler)
        return FALSE;

    if (!st->onlyChecking)
    {
        st->script = BattleScript_FlowerVeilProtectsRet;
        gBattleScripting.battler = st->battler;
        gBattlerAbility = flowerVeilBattler - 1;
        gLastUsedAbility = ABILITY_FLOWER_VEIL;
        MarkStatsAsDone(st, NUM_BATTLE_STATS);
        RecordAbilityBattle(gBattlerAbility, ABILITY_FLOWER_VEIL);
    }

    return TRUE;
}

static bool32 IsClearAmuletBlocked(struct BattleCalcValues *cv, struct StatChange *st)
{
    if (st->certain)
        return FALSE;

    if (cv->holdEffects[st->battler] != HOLD_EFFECT_CLEAR_AMULET)
        return FALSE;

    if (!st->onlyChecking)
    {
        st->script = BattleScript_ItemNoStatLoss;
        gBattleScripting.battler = st->battler;
        gLastUsedItem = gBattleMons[st->battler].item;
        MarkStatsAsDone(st, NUM_BATTLE_STATS);
        RecordItemEffectBattle(st->battler, HOLD_EFFECT_CLEAR_AMULET);
    }

    return TRUE;
}

static bool32 IsIntimidateBlocked(struct BattleCalcValues *cv, struct StatChange *st)
{
    if (!st->intimidate)
        return FALSE;

    switch (cv->abilities[st->battler])
    {
    case ABILITY_INNER_FOCUS:
    case ABILITY_SCRAPPY:
    case ABILITY_OWN_TEMPO:
    case ABILITY_OBLIVIOUS:
        if (GetConfig(B_UPDATED_INTIMIDATE) >= GEN_8)
            st->script = BattleScript_AbilityPopUp;
        break;
    case ABILITY_GUARD_DOG: // TODO
        st->stage = -1 * st->stage; // This does not work. I need to handle the stat correctly. Invert stat and mark it as not done
        st->script = BattleScript_AbilityPopUp;
        break;
    default:
        return FALSE;
    }

    gLastUsedAbility = cv->abilities[st->battler];
    gBattlerAbility = st->battler;
    gBattleScripting.battler = st->battler;
    MarkStatsAsDone(st, st->stat);
    RecordAbilityBattle(st->battler, cv->abilities[st->battler]);
    return TRUE;
}

static bool32 IsAbilityBlocked(struct BattleCalcValues *cv, struct StatChange *st)
{
    if (st->certain)
        return FALSE;

    if (!CanAbilityPreventStatLoss(cv->abilities[st->battler])
     && !AbilityPreventsSpecificStatDrop(cv->abilities[st->battler], st->stat))
        return FALSE;

    if (!st->onlyChecking)
    {
        if (CanAbilityPreventStatLoss(cv->abilities[st->battler]))
            MarkStatsAsDone(st, NUM_BATTLE_STATS);
        else
            MarkStatsAsDone(st, st->stat);
        st->script = BattleScript_AbilityPopUp;
        gBattleScripting.battler = st->battler;
        gBattlerAbility = st->battler;
        gLastUsedAbility = cv->abilities[st->battler];
        RecordAbilityBattle(st->battler, gLastUsedAbility);
    }

    return TRUE;
}

static bool32 IsMirrorArmorReflected(struct BattleCalcValues *cv, struct StatChange *st)
{
    if (cv->abilities[st->battler] != ABILITY_MIRROR_ARMOR || st->mirrorArmored)
        return FALSE;

    if (st->onlyChecking && !st->ignoreCertainFailure)
        return TRUE;

    if (gBattleStruct->moveResultFlags[st->battler] & MOVE_RESULT_MIRROR_ARMOR_PENDING || !st->ignoreCertainFailure)
    {
        st->script = BattleScript_MirrorArmorReflect;
        gBattlerAbility = st->battler;
        RecordAbilityBattle(st->battler, cv->abilities[st->battler]);

        if (st->stickyWeb)
        {
            if (gSideTimers[GetBattlerSide(st->battler)].stickyWebBattlerId != 0xFF)
            {
                gBattleScripting.battler = gSideTimers[GetBattlerSide(st->battler)].stickyWebBattlerId;
            }
            else
            {
                st->script = BattleScript_AbilityPopUp;
                return TRUE;
            }
        }
        else
        {
            gBattleScripting.battler = gBattleScripting.savedBattler;
            gBattleStruct->allowPartingShot = TRUE;
        }

        for (u32 i = 0; i < st->statStageAmount; i++)
        {
            enum Stat stat = st->statStageQueue[i].stat;
            s32 stage = st->statStageQueue[i].stage;
            if (stage < 0)
            {
                st->statStageQueue[i].done = TRUE;
                SetStatChange2(gBattleScripting.battler, stat, stage);
            }
        }

        return TRUE;
    }

    return FALSE;
}

static enum StatChangeResult CanDecreaseStat(struct BattleCalcValues *cv, struct StatChange *st)
{
    if (IsMistProtected(cv, st)
     || IsFlowerVeilBlocked(cv, st)
     || IsClearAmuletBlocked(cv, st)
     || IsIntimidateBlocked(cv, st)
     || IsAbilityBlocked(cv, st)
     || IsMirrorArmorReflected(cv, st))
        return STAT_CHANGE_DIDNT_WORK;
    return STAT_CHANGE_WORKED;
}

static enum StatChangeResult DecreaseStat(struct BattleCalcValues *cv, struct StatChange *st)
{
    u32 currStage = gBattleMons[st->battler].statStages[st->stat];

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

    if (currStage == MIN_STAT_STAGE)
    {
        if (st->onlyChecking)
            return STAT_CHANGE_DIDNT_WORK;

        if (cv->move == MOVE_BELLY_DRUM)
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_CHANGED_BELLY_DRUM;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_WONT_CHANGE;

        gBattleScripting.battler = st->battler;
        st->script = BattleScript_DecreaseStatChangeMessage;
        return STAT_CHANGE_WORKED; // Handle failure
    }
    else if (!st->onlyChecking)
    {
        gBattleMons[st->battler].volatiles.tryEjectPack = TRUE;
        gProtectStructs[st->battler].lashOutAffected = TRUE;
        gBattleScripting.statChanger |= STAT_BUFF_NEGATIVE;
    }

    if (!st->onlyChecking)
    {
        // Might not need the sticky web one
        if (!st->stickyWeb)
        {
            if (st->certain || IsBattlerAlly(cv->battlerAtk, st->battler))
                gBattleStruct->selfStatDrop = TRUE;
        }

        st->statChanged = TRUE;
        gBattleStruct->moveResultFlags[st->battler] |= MOVE_RESULT_STAT_CHANGED;
        gBattleScripting.battler = st->battler;
        gBattleMons[st->battler].statStages[st->stat] += st->stage;
        if (gBattleMons[st->battler].statStages[st->stat] < MIN_STAT_STAGE)
            gBattleMons[st->battler].statStages[st->stat] = MIN_STAT_STAGE;

        if (cv->move == MOVE_BELLY_DRUM)
        {
            gBattleMons[st->battler].statStages[st->stat] = MIN_STAT_STAGE;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_CHANGED_BELLY_DRUM;
        }
        else if (st->itemMessage)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_CHANGED_ITEM;
        }
        else
        {

            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_CHANGED;
        }

        st->script = BattleScript_DecreaseStatChangeMessage;
        TryPlayStatChangeAnimation(cv, st);
    }

    return STAT_CHANGE_WORKED;
}

static enum StatChangeResult IncreaseStat(struct BattleCalcValues *cv, struct StatChange *st)
{
    u32 currStage = gBattleMons[st->battler].statStages[st->stat];

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

    if (gBattleMons[st->battler].statStages[st->stat] == MAX_STAT_STAGE)
    {
        if (st->onlyChecking)
            return STAT_CHANGE_DIDNT_WORK;

        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_WONT_CHANGE;
        st->script = BattleScript_IncreaseStatChangeMessagePause;
        gBattleScripting.battler = st->battler;
        return STAT_CHANGE_WORKED; // Handle failure
    }
    else if (!st->onlyChecking)
    {
        u32 stageIncrease = st->stage;

        if ((st->stage + gBattleMons[st->battler].statStages[st->stat]) > MAX_STAT_STAGE)
            stageIncrease  = MAX_STAT_STAGE - gBattleMons[st->battler].statStages[st->stat];

        if (stageIncrease > 0)
        {
            // Check Mirror Herb / Opportunist
            for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
            {
                if (IsBattlerAlly(battler, st->battler))
                    continue; // Only triggers on opposing side

                if (GetBattlerAbility(battler) == ABILITY_OPPORTUNIST
                 && gProtectStructs[st->battler].activateOpportunist == 0) // don't activate opportunist on other mon's opportunist raises
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
                    gQueuedStatBoosts[battler].statChanges[st->stat - 1] += stageIncrease;
                }
            }
        }
    }

    if (!st->onlyChecking)
    {
        st->statChanged = TRUE;
        gBattleStruct->moveResultFlags[st->battler] |= MOVE_RESULT_STAT_CHANGED;
        gBattleScripting.battler = st->battler;
        gBattleMons[st->battler].statStages[st->stat] += st->stage;
        gProtectStructs[st->battler].statRaised = TRUE;
        if (gBattleMons[st->battler].statStages[st->stat] > MAX_STAT_STAGE)
            gBattleMons[st->battler].statStages[st->stat] = MAX_STAT_STAGE;

        // maxed attack message instead
        if (cv->move == MOVE_BELLY_DRUM)
        {
            gBattleMons[st->battler].statStages[st->stat] = MAX_STAT_STAGE;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_CHANGED_BELLY_DRUM;
        }
        else if (st->itemMessage)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_CHANGED_ITEM;
        }
        else
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_CHANGED;
        }

        st->script = BattleScript_IncreaseStatChangeMessage;
        TryPlayStatChangeAnimation(cv, st);
    }

    return STAT_CHANGE_WORKED;
}

static void TryPlayStatChangeAnimation(struct BattleCalcValues *cv, struct StatChange *st)
{
    u32 statAnimId = st->stat;

    if (st->stage <= -1) // goes down
    {
        if (gBattleStruct->negativeAnimPlayed && !st->forceAnim)
            return;

        u32 isStatChangeByTwo = abs(st->stage) > 1;
        u32 numNegativeStats = 0;

        if (!st->forceAnim)
        {
            gBattleStruct->negativeAnimPlayed = TRUE;
            numNegativeStats = GetNumNegativeStats(st);
        }

        statAnimId += isStatChangeByTwo ? STAT_ANIM_MINUS2 : STAT_ANIM_MINUS1;

        if (ShouldDefiantCompetitiveActivate(st->battler, cv->abilities[st->battler]))
            numNegativeStats = 0;

        if (numNegativeStats > 1) // more than one stat, so the color is gray
            statAnimId = isStatChangeByTwo ? STAT_ANIM_MULTIPLE_MINUS2 : STAT_ANIM_MULTIPLE_MINUS1;
    }
    else // goes up
    {
        if (gBattleStruct->positiveAnimPlayed && !st->forceAnim)
            return;

        u32 isStatChangeByTwo = st->stage > 1;
        u32 numPositiveStats = 0;

        if (!st->forceAnim)
        {
            numPositiveStats = GetNumPositiveStats(st);
            gBattleStruct->positiveAnimPlayed = TRUE;
        }

        statAnimId += isStatChangeByTwo ? STAT_ANIM_PLUS2 : STAT_ANIM_PLUS1;

        if (ShouldDefiantCompetitiveActivate(st->battler, cv->abilities[st->battler]))
            numPositiveStats = 0;

        if (numPositiveStats > 1)
            statAnimId = isStatChangeByTwo ? STAT_ANIM_MULTIPLE_PLUS2 : STAT_ANIM_MULTIPLE_PLUS1;
    }

    BtlController_EmitBattleAnimation(st->battler, B_COMM_TO_CONTROLLER, B_ANIM_STATS_CHANGE, statAnimId);
    MarkBattlerForControllerExec(st->battler);
}

static void AdjustStatStage(struct BattleCalcValues *cv, struct StatChange *st)
{
    u32 effect = GetMoveEffect(cv->move);
    if (effect == EFFECT_GROWTH && IsBattlerWeatherAffected(cv->holdEffects[st->battler], GetWeather(), B_WEATHER_SUN))
        st->stage = 2;

    if (st->stage == 7)
        st->stage = 12;

    switch (cv->abilities[st->battler])
    {
    case ABILITY_CONTRARY:
        st->stage = -1 * st->stage;
        if (!st->onlyChecking)
            RecordAbilityBattle(st->battler, cv->abilities[st->battler]);
        break;
    case ABILITY_SIMPLE:
        st->stage = 2 * st->stage;
        if (!st->onlyChecking)
            RecordAbilityBattle(st->battler, cv->abilities[st->battler]);
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
        return FALSE;
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

u32 GetStatStage(u32 stat, const struct AdditionalEffect *additionalEffect)
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

    return 0;
}

static u32 GetNumPositiveStats(struct StatChange *st)
{
    u32 num = 0;
    for (u32 i = STAT_ATK; i < st->statStageAmount; i++)
    {
        if (st->statStageQueue[i].stage > 0)
            num++;
    }
    return num;
}

static u32 GetNumNegativeStats(struct StatChange *st)
{
    u32 num = 0;
    for (u32 i = STAT_ATK; i < st->statStageAmount; i++)
    {
        if (st->statStageQueue[i].stage < 0)
            num++;
    }
    return num;
}

void SetStatChange(enum BattlerId battler, enum Stat stat, s32 stage)
{
    gSpecialStatuses[battler].statStageQueue[gSpecialStatuses[battler].statStageAmount].stat = stat;
    gSpecialStatuses[battler].statStageQueue[gSpecialStatuses[battler].statStageAmount].stage = stage;
    gSpecialStatuses[battler].statStageAmount++;
}

// Used for stat change responses like Defiant and Mirror Armor
void SetStatChange2(enum BattlerId battler, enum Stat stat, s32 stage)
{
    gSpecialStatuses[battler].statStageQueue2[gSpecialStatuses[battler].statStageAmount2].stat = stat;
    gSpecialStatuses[battler].statStageQueue2[gSpecialStatuses[battler].statStageAmount2].stage = stage;
    gSpecialStatuses[battler].statStageAmount2++;
}

void ClearStatChangeValues(void)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        memset(gSpecialStatuses[battler].statStageQueue, 0, sizeof(gSpecialStatuses[battler].statStageQueue));
        gSpecialStatuses[battler].statStageAmount = 0;
    }
    gBattleStruct->selfStatDrop = FALSE;
    gBattleStruct->negativeAnimPlayed = 0;
    gBattleStruct->positiveAnimPlayed = 0;
    gBattleStruct->statChangeBattler  = 0;
}

void ClearOtherStatChangeValues(enum BattlerId battler)
{
    memset(gSpecialStatuses[battler].statStageQueue2, 0, sizeof(gSpecialStatuses[battler].statStageQueue2));
    gSpecialStatuses[battler].statStageAmount2 = 0;
    gBattleStruct->selfStatDrop = FALSE;
    gBattleStruct->negativeAnimPlayed = 0;
    gBattleStruct->positiveAnimPlayed = 0;
}

// In case it turns out that we need to check this before anything else
#if 0
static bool32 IsStatAtMinStage(struct BattleCalcValues *cv, struct StatChange *st)
{
    if (CompareStat(st->battler, st->stat, MIN_STAT_STAGE, CMP_EQUAL, ABILITY_NONE))
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_WONT_CHANGE;
        st->script = BattleScript_DecreaseStatChangeMessage;
        return TRUE;
    }
    return FALSE;
}

static bool32 IsStatAtMaxStage(struct BattleCalcValues *cv, struct StatChange *st)
{
    if (CompareStat(st->battler, st->stat, MAX_STAT_STAGE, CMP_EQUAL, ABILITY_NONE))
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_WONT_CHANGE;
        st->script = BattleScript_IncreaseStatChangeMessage;
        return TRUE;
    }
    return FALSE;
}
#endif

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

static void SetAdditionalEffectsOnStatChange(struct BattleCalcValues *cv, struct StatChange *st)
{
    if (!(gBattleStruct->moveResultFlags[st->battler] & MOVE_RESULT_STAT_CHANGED))
        return;

    switch (GetMoveEffect(cv->move))
    {
    case EFFECT_DEFENSE_CURL:
        gBattleMons[st->battler].volatiles.defenseCurl = TRUE;
        break;
    case EFFECT_MINIMIZE:
        gBattleMons[st->battler].volatiles.minimize = TRUE;
        break;
    case EFFECT_STOCKPILE:
        gBattleMons[st->battler].volatiles.stockpileDef++;
        gBattleMons[st->battler].volatiles.stockpileSpDef++;
        break;
    case EFFECT_NO_RETREAT:
        if (!gBattleMons[st->battler].volatiles.noRetreat)
        {
            gBattleMons[st->battler].volatiles.noRetreat = TRUE;
            gBattleMons[st->battler].volatiles.escapePrevention = TRUE;
            st->moveScript = BattleScript_NoRetreatMessage;
        }
        break;
    case EFFECT_AUTOTOMIZE:
        if (GetBattlerWeight(st->battler) > 1)
        {
            gBattleMons[st->battler].volatiles.autotomizeCount++;
            st->moveScript = BattleScript_AutotomizeMessage;
        }
        break;
    default:
        break;
    }
}

/*
  There might be a better solution without this function
  The problems this fixes:
  1. Multiply failure pop ups
  2. Since we don't mark battlers as doesn't affect foe, they still get a stat drop
*/
static void MarkStatsAsDone(struct StatChange *st, u32 stat)
{
    for (u32 i = 0; i < st->statStageAmount; i++)
    {
        if (st->statStageQueue[i].stat != stat && stat != NUM_BATTLE_STATS)
            continue;

        if (st->statStageQueue[i].stage < 0)
            st->statStageQueue[i].done = TRUE;
    }
}
