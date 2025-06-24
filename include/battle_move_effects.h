#ifndef GUARD_BATTLE_MOVE_EFFECTS_H
#define GUARD_BATTLE_MOVE_EFFECTS_H

#include "battle.h"
#include "battle_ai_util.h"
#include "constants/battle_script_commands.h"
#include "battle_main.h"

enum MoveEffectBlockerType
{
    MOVE_EFFECT_BLOCKER_NONE,
    MOVE_EFFECT_BLOCKER_ABILITY,
    MOVE_EFFECT_BLOCKER_ABILITY_ON_SIDE,
    MOVE_EFFECT_BLOCKER_SUBSTITUTE,
    MOVE_EFFECT_BLOCKER_SAFEGUARD,
    MOVE_EFFECT_BLOCKER_TERRAIN,
    MOVE_EFFECT_BLOCKER_STATUS,
    MOVE_EFFECT_BLOCKER_VOLATILE,
    MOVE_EFFECT_BLOCKER_CALLBACK = 0x8, // Must be hard-coded!
    MOVE_EFFECT_BLOCKER_TYPES,
    MOVE_EFFECT_BLOCKER_ACCURACY_PLACEHOLDER,
    MOVE_EFFECT_BLOCKER_END,
};

struct MoveEffectBlocker
{
    union {
        struct {
            enum MoveEffectBlockerType blockerType:8;
            union PACKED {
                u16 ability;
                enum Volatile _volatile:8;
                u16 status;
                u16 terrain;
                struct PACKED {
                    u16 unlessAbility:10;
                    u8 type:6;
                    u8 type2;
                };
            };
        };
        const bool32 (*callback)(struct SetMoveEffectResult *);
    };
    const u8 *battlescript;
};

struct MoveEffectInfo
{
    void (*callback)(struct SetMoveEffectResult *);
    const u8 *battlescript;
    union {
        u16 status;
        enum Volatile _volatile:16;
    };
    u8 blockedByTypes[2];
    u32 notAbilityCompatible:1;
    u32 notItemCompatible:1;
    u32 activateAfterFaint:1;
    u32 finalStrikeEffect:1;
    u32 synchronizeMoveEffect:1;
    u32 onlyIfMonsAliveOnEitherSide:1;
    const struct MoveEffectBlocker *blockers;
};

extern const struct MoveEffectInfo gMoveEffectsInfo[];

static inline void PushMoveEffectInstr(struct SetMoveEffectResult *result)
{
    result->nextInstr = gMoveEffectsInfo[result->moveEffect].battlescript;
}

static inline void PushNextInstrAndMoveEffectInstr(struct SetMoveEffectResult *result)
{
    result->battlescriptPush = TRUE;
    PushMoveEffectInstr(result);
}

static inline void SetMoveEffectTriggerResult(struct SetMoveEffectResult *result, const u8 *currInstr, const u8 *backupInstr)
{
    if (result && result->moveEffect <= MOVE_EFFECT_PAYDAY)
    {
        if (result->blockedByAbility)
        {
            gLastUsedAbility = result->battlerAbility;
            gBattlerAbility = result->effectBattler;
            RecordAbilityBattle(result->effectBattler, result->battlerAbility);
        }
        else if (!result->failed && gMoveEffectsInfo[result->moveEffect].callback)
            gMoveEffectsInfo[result->moveEffect].callback(result);

        // Push and set next instruction
        if (result->nextInstr)
        {
            // Set result variables
            gBattleCommunication[MULTISTRING_CHOOSER] = result->multistring;
            gEffectBattler = result->effectBattler;
            gBattleScripting.battler = result->scriptingBattler;

            if (result->battlescriptPush && !result->saved)
                BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = result->nextInstr;
            return;
        }
    }

    // Fallback - jump to backupInstr if we haven't gone anywhere
    if (gBattlescriptCurrInstr == currInstr && backupInstr != NULL)
        gBattlescriptCurrInstr = backupInstr;
}

static inline void SetMoveEffectTriggerSavedResult(u32 index)
{
    SetMoveEffectTriggerResult(&gBattleStruct->savedMoveEffectResults[index], NULL, NULL);
}

void SetNonVolatileStatusCondition(u32 battler, u32 effectBattler, enum MoveEffect effect, enum StatusTrigger trigger);
void SetMoveEffect(u32 battler, u32 effectBattler, bool32 primary, bool32 certain);
struct SetMoveEffectResult *SetMoveEffectWithResult(struct SetMoveEffectResult *result, u32 battler, u32 effectBattler, u16 moveEffect, bool32 primary, bool32 certain, const u8 *failInstr);
bool32 CheckAndSaveAdditionalEffects(u32 battler, u32 effectBattler, enum MoveEffect effect, enum StatusTrigger trigger);

#endif // GUARD_BATTLE_MOVE_EFFECTS_H
