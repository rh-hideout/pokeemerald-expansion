#ifndef GUARD_BATTLE_ABILITIES
#define GUARD_BATTLE_ABILITIES

enum AbilityEffect
{
    ABILITYEFFECT_ENDTURN,
    ABILITYEFFECT_MOVE_END_ATTACKER,
    ABILITYEFFECT_COLOR_CHANGE, // Color Change / Berserk / Anger Shell
    ABILITYEFFECT_MOVE_END_HIT_TARGET,
    ABILITYEFFECT_FORM_CHANGE_ON_HIT,
    ABILITYEFFECT_DANCER,
    ABILITYEFFECT_MOVE_END_FOES_FAINTED, // Moxie-like abilities / Battle Bond / Magician
    ABILITYEFFECT_RECEIVER, // Receiver / Power of Alchemy
    ABILITYEFFECT_ON_FAINT, // Soul Heart
    ABILITYEFFECT_ON_FORM_CHANGE,
    ABILITYEFFECT_ON_STATUS_CHANGE, // Synchronize / Poison Puppeteer

    // On Switch in
    ABILITYEFFECT_TERA_SHIFT,
    ABILITYEFFECT_NEUTRALIZINGGAS,
    ABILITYEFFECT_UNNERVE,
    ABILITYEFFECT_ON_SWITCHIN,
    ABILITYEFFECT_SWITCH_IN_FORM_CHANGE,
    ABILITYEFFECT_DEPENDS_ON_ALLY, // Commander / Hospitality / Costar
    ABILITYEFFECT_ON_WEATHER,
    ABILITYEFFECT_ON_TERRAIN,

    ABILITYEFFECT_IMMUNITY,
    ABILITYEFFECT_OPPORTUNIST,
};

bool32 AbilityBattleEffects(enum AbilityEffect caseID, struct BattleCalcValues *cv);
bool32 AbilityBattleEffectsHelper(enum AbilityEffect caseID, enum BattlerId battler, enum Ability ability, enum Move move, bool32 shouldAbilityTrigger);

#endif // GUARD_BATTLE_ABILITIES
