---
name: ability-implementation
description: Implement new abilities or modify existing ability effects. Use when adding abilities, changing how abilities work in battle, or fixing ability bugs.
allowed-tools: Read, Grep, Glob, Write, Edit, Bash(make:*)
---

# Ability Implementation Guide

## Key Files

| File | Purpose |
|------|---------|
| `include/constants/abilities.h` | Ability enum constants |
| `src/data/abilities.h` | Ability data array (`gAbilitiesInfo`) |
| `include/pokemon.h` | `AbilityInfo` struct definition |
| `src/battle_util.c` | `AbilityBattleEffects()` - main implementation |
| `include/battle_util.h` | `AbilityEffect` enum & prototypes |
| `test/battle/ability/*.c` | Ability test cases |

## AbilityInfo Structure

```c
struct AbilityInfo {
    u8 name[ABILITY_NAME_LENGTH + 1];
    const u8 *description;
    s8 aiRating;                    // -10 to 10
    u8 cantBeCopied:1;              // Role Play, Doodle
    u8 cantBeSwapped:1;             // Skill Swap, Wandering Spirit
    u8 cantBeTraced:1;              // Trace
    u8 cantBeSuppressed:1;          // Gastro Acid, Neutralizing Gas
    u8 cantBeOverwritten:1;         // Entrainment, Worry Seed, Simple Beam
    u8 breakable:1;                 // Mold Breaker bypasses
    u8 failsOnImposter:1;           // Doesn't work with Imposter
};
```

## Adding a New Ability

### Step 1: Add Enum Constant

In `include/constants/abilities.h`, find the appropriate generation section:

```c
// Gen 9 abilities
ABILITY_MYABILITY = ABILITIES_COUNT_GEN8,
// ... update ABILITIES_COUNT_GEN9
```

### Step 2: Add Ability Data

In `src/data/abilities.h`:

```c
[ABILITY_MYABILITY] =
{
    .name = _("My Ability"),
    .description = COMPOUND_STRING("Description here."),
    .aiRating = 5,
    // flags default to FALSE if omitted
},
```

### Step 3: Implement Effect Logic

In `src/battle_util.c`, add to the appropriate `AbilityBattleEffects()` case:

```c
case ABILITYEFFECT_ON_SWITCHIN:
    switch (gLastUsedAbility)
    {
    case ABILITY_MYABILITY:
        // implementation
        effect++;
        break;
    }
```

## Effect Types (enum AbilityEffect)

| Effect | When Triggered |
|--------|----------------|
| `ABILITYEFFECT_ON_SWITCHIN` | Entering battle |
| `ABILITYEFFECT_ENDTURN` | End of turn |
| `ABILITYEFFECT_MOVE_END_ATTACKER` | After using a move |
| `ABILITYEFFECT_MOVE_END` | After being hit (contact abilities) |
| `ABILITYEFFECT_IMMUNITY` | Status immunity checks |
| `ABILITYEFFECT_ON_WEATHER` | Weather changes |
| `ABILITYEFFECT_ON_TERRAIN` | Terrain changes |

## Common Patterns

### On-Switch Weather (Drizzle pattern)

```c
case ABILITY_MYABILITY:
    if (TryChangeBattleWeather(battler, BATTLE_WEATHER_RAIN, gLastUsedAbility))
    {
        BattleScriptPushCursorAndCallback(BattleScript_DrizzleActivates);
        effect++;
    }
    break;
```

### End-of-Turn Stat Boost (Speed Boost pattern)

```c
case ABILITY_MYABILITY:
    if (CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN, gLastUsedAbility)
        && gDisableStructs[battler].isFirstTurn != 2)
    {
        SET_STATCHANGER(STAT_SPEED, 1, FALSE);
        BattleScriptExecute(BattleScript_AttackerAbilityStatRaiseEnd2);
        effect++;
    }
    break;
```

### Damage Modifier (Huge Power pattern)

In damage calculation section (~line 7722):

```c
case ABILITY_MYABILITY:
    if (IsBattleMovePhysical(move))
        modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(2.0));
    break;
```

### Contact Ability (Static pattern)

```c
case ABILITYEFFECT_MOVE_END:
    switch (gLastUsedAbility)
    {
    case ABILITY_MYABILITY:
        if (IsMoveMakingContact(gBattlerAttacker, battler, ABILITY_NONE, HOLD_EFFECT_NONE, move)
            && CanBeParalyzed(gBattlerAttacker, gLastUsedAbility))
        {
            gEffectBattler = gBattlerAttacker;
            gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
            BattleScriptCall(BattleScript_AbilityStatusEffect);
            effect++;
        }
        break;
    }
```

## Useful Helper Functions

| Function | Purpose |
|----------|---------|
| `CompareStat(battler, stat, value, cmp, ability)` | Check stat stage |
| `GetBattlerAbility(battler)` | Get current ability |
| `IsBattlerAlive(battler)` | Check if alive |
| `IsBattlerWeatherAffected(battler, weather)` | Weather check |
| `SET_STATCHANGER(stat, stages, lower)` | Queue stat change |
| `BattleScriptExecute(script)` | Run battle script |
| `RandomPercentage(rng, percent)` | Random chance |
| `RecordAbilityBattle(battler, ability)` | Log for Pokedex |

## Fixed-Point Math for Damage

```c
// 1.5x multiplier
modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(1.5));

// 2.0x multiplier
modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(2.0));
```

## Testing Abilities

Create test in `test/battle/ability/my_ability.c`:

```c
#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("My Ability does X when Y")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_MYABILITY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_MYABILITY);
        MESSAGE("Wobbuffet's My Ability!");
    }
}
```

Run with:
```bash
make check TESTS="my_ability"
```

## Key Data Structures

- `gBattleMons[battler]` - Pokemon battle data (HP, status, stats)
- `gDisableStructs[battler]` - Ability state (timers, flags)
- `gSpecialStatuses[battler]` - Switch-in flags, temporary state
- `gBattleStruct` - Global battle state
