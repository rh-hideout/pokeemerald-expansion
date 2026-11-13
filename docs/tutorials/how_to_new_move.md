*Full credits and thank you to CancerFairy for writing this guide!*

### Note: This guide was written for version 1.8.0. Most stuff still applies to 1.7.x versions and earlier, with the following exceptions:
- Battle and Contest move data are separated in `src/data/battle_moves.h` and `src/data/contest_moves.h`
- `additionalEffects` doesn't exist, instead being handled by a combination of `secondaryEffectChance` and unique `EFFECT_xxx`s.
- There's no `include/constants/battle_move_effects.h`, so data specific to certain effects is handled in other places.
- Move names are handled in `gMoveNames`.

# Adding/editing moves
This guide is here to give you a breakdown of how moves work, how to edit existing ones, and how to add your own.

## Contents:
1. [Key files and definitions](#key-files-and-definitions)
    - [Header files](#header-files)
    - [C files](#c-files)
    - [Script files](#script-files)
2. [Editing a move](#editing-a-move)
3. [Adding a new move](#adding-a-new-move)

## Key files and definitions
Before beginning the process, it's important to familiarise yourself with the important files that control moves. There are three categories of files - header(.h) files, which contain static information about a move, .c files which contains functions in C that determine how the move behaves, and script files (.s or .inc) that actually "run" the move - i.e. determine the sequence of events you see on screen when you execute the move.

## Header files
### src/data/moves_info.h
This is the place where the bulk of move information is stored, including name, base power, typing, PP, contest information etc.

Let's look at an example:
```c
[MOVE_THUNDER_SHOCK] =
{
    .name = COMPOUND_STRING("Thunder Shock"),
    .description = COMPOUND_STRING(
        "An electrical attack that\n"
        "may paralyze the foe."),
    .effect = EFFECT_HIT,
    .power = 40,
    .type = TYPE_ELECTRIC,
    .accuracy = 100,
    .pp = 30,
    .target = TARGET_SELECTED,
    .priority = 0,
    .category = DAMAGE_CATEGORY_SPECIAL,
    .additionalEffects = ADDITIONAL_EFFECTS({
        .moveEffect = MOVE_EFFECT_PARALYSIS,
        .chance = 10,
    }),
    .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
    .contestCategory = CONTEST_CATEGORY_COOL,
    .contestComboStarterId = 0,
    .contestComboMoves = {COMBO_STARTER_CHARGE},
},
```
Most of the fields here are obvious, but the two important ones for determining what a move actually *does* are `effect` and `additionalEffects`.

The `effect` represents how the move actually works when called in battle - it can be a two turn move, or a move that only works if the target is holding an item, for example. How each effect works is pretty much unique, but the way a move of a particular effect is executed is defined by a script [`data/battle_scripts_1.s`](#databattle_scripts_1s), and any *variable* characteristics such as typing or power are defined in either [`src/battle_script_commands.c`](#srcbattle_script_commandsc) or [`src/battle_util.c`](#srcbattle_utilc), depending on the effect. The vast majority of non-status moves are simply `EFFECT_HIT`, in that they deal damage and apply `additionalEffects` (if defined).

The `additionalEffects` field represents effects that are applied at the `setadditionaleffects` stage of the move script (for most moves, see `BattleScript_Hit_RetFromAtkAnimation`). These are effects that can be encapsulated by any of the `MOVE_EFFECT_X` defined in [`include/constants/battle.h`](#includeconstantsbattleh) and encoded under `SetMoveEffect` in [`src/battle_script_commands.c`](#srcbattle_script_commandsc). These can vary from applying a status, such as `MOVE_EFFECT_PARALYSIS`, or lowering/raising stats etc. The move effect could target the user by setting `self = TRUE`, such as Overheat lowering the user's own Sp. Atk. What's more, definining a `chance`, such as for Thunder Shock, not only limits the effect to applying only `chance`% of the time, but it also turns it into a *secondary effect.* This difference is important because secondary effects are nullified by Sheer Force (which in turn will boost the move's power) and they are blocked by Shield Dust. These two limitations do not apply to *primary effects* which do not a chance field defined and by definition will *always* happen when the move is executed.

### src/battle_move_resolution.c
As the name implies this is where the move resolution happens for a move. In the majority of cases this can be ignored but if a move needs to have very specific failure checks there are a couple functions that help with that. 
* `CancelerMoveFailure` Handles moves that would fail because of certain user conditions. For example Fake Out `EFFECT_FIRST_TURN_ONLY`. The move will fail independent of the target if it isn't the first turn
* `CancelerMoveEffectFailureTarget` Looks at target specific failure such as Poltergeist when target has no item. Note: the function is build in a way to handle spread moves meaning if one check is successfulthe move wont fail 
* `CancelerStatusEffects` This can be largely treated as a blackbox but noteworthy is that for status move the decision whether the move fails or not is handled here. When the move fails no animation is played and we handle the failure later. 
* A couple other things notable things are `CancelerCharging`, `CancelerExplosion`, `CancelerPledgeAttack`. For more information see the correspondings functions or that table `sMoveSuccessOrderCancelers`. 

You could call the file the heart of a move. It can be ignored but it can be useful to know how it works when a move needs to be more complicated like the pledges.

### src/data/battle_move_effects.h
Effects are listed here along with the `battleScript` that governs each one. Said scripts are defined in [`data/battle_scripts_1.s`](#databattle_scripts_1s). The indices/names of the effects (e.g. `EFFECT_FIRST_TURN_ONLY`) are enums defined in [`include/constants/battle_move_effects.h`](#includeconstantsbattle_move_effectsh).

### include/constants/battle_move_effects.h
Simply an enum list of possible effects for moves. Any new effects would be added here, with a definition for them (including defining a script) would then also be added to [`src/data/battle_move_effects.h`](#srcdatabattle_move_effectsh).

### include/constants/battle_string_ids.h
All strings that can be printed in battle have an id that is defined here. The actual message itself would then be defined and assigned to this id in [`src/data/battle_message.c`](#srcbattle_messagec).

### include/constants/battle.h
A whole range of constants defining battle variables, such as statuses, weather, and move effects.

### include/constants/moves.h
Where moves are defined (and nothing else).

**Note:** When adding custom moves, you should add them between the moves from the latest generation and the z moves, then adjust `MOVES_COUNT` accordingly.  Adding a move after `MOVES_COUNT` that is neither a Max Move or a Z Move will result in that move's name not being printed when it is used, instead a generic message will be printed.

As an example, the resulting changes should look like this:
```c
    MOVE_UPPER_HAND = 846,
    MOVE_MALIGNANT_CHAIN = 847,
    MOVES_COUNT_GEN9,

    // Add any custom moves here, not further down!
    MOVE_THROW_DOWN,

    MOVES_COUNT,

    // Z Moves
    FIRST_Z_MOVE = MOVES_COUNT,
    MOVE_BREAKNECK_BLITZ = FIRST_Z_MOVE,
    MOVE_ALL_OUT_PUMMELING,
```
## C files
### src/battle_set_effect.c
This is where the majority of effects are defined (e.g. Absorb). Exceptions are moves with damage modifiers (e.g. Round), with specific failure conditions (e.g. Poltergeist), two turn moves (e.g. Sky Drop). Let's examine a move effect function.
```C
// se->effectBattler -> the battler that will be seeded
static void HandleSetEffectLeechSeed(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].volatiles.leechSeed)
    {
        SetEffectFail(BattleScript_ButItFailedRet, cv->isStatusMove);
    }
    else if (IS_BATTLER_OF_TYPE(se->effectBattler, TYPE_GRASS))
    {
        SetEffectFail(BattleScript_ItDoesntAffectEffBattler, cv->isStatusMove);
    }
    else if (!cv->onlyChecking)
    {
        gBattleMons[se->effectBattler].volatiles.leechSeed = LEECHSEEDED_BY(cv->battlerAtk);
        PrepareStringBattleWithWait(STRINGID_PKMNSEEDED, se->effectBattler);
        BattleScriptPushAndSet(se->script, BattleScript_WaitMessage);
    }
}
```
The function has 2 parts. A "failure" part and a "set effect" part. The failure part checks if a move effect can be applied. For status moves this means that a failure message will be printed (Leech Seed). For damage moves the failure is silent (Sappy Seed).
For status moves specifically we want to check the failure first before we apply any effect. This is where `cv->onlyChecking` comes into play. It postpones the "set effect" part to after the animation. 
We also want to execute an effect. In this case a general `BattleScript_WaitMessage` is used. We already seeded the battler and we just want to print the message. A general script can be used in most cases but not always. A dedicated script is usually needed when the move is more sophisticated then usual (a move like Skill Swap that has a lot of moving parts). An other edge case is `BattleScript_PrintSavedMessage`. It has almost the same functionality as `BattleScript_WaitMessage` but it saves the string to delay the usage of `PrepareStringBattleWithWait`. This is required because we mark the battler for execution twice but need to delay it by one frame so the first execution isn't overwritten.

### src/battle_util.c
This contains a lot of the "utility" functions used to determine things like a move's dynamic typing or power. It's also where damage calculation takes place, and a lot of that will naturally take a move's effect into account. For example, a move with the effect `EFFECT_SOLAR_BEAM` would have its damage halved in sandstorm. If you wanted to add a move with an effect which gave it variable BP or typing, this is the file you would encode that effect.

### src/battle_message.c
Contains string defines and functions that print messages during the battle. If you wish to add or edit a move's string, then this is where you would do so.

### src/battle_main.c
Contains more fundamental functions that control the flow of the battle. Functions here determine move order, dynamic typing, animations, priority, speed calculations and more.

### data/battle_anim_scripts.s
This is the place where move animations are defined. The array at the top, `gBattleAnims_Moves`, is in move index order and determines which animation goes with which move.

## Editing a move
### Basic information
To edit a move's basic information, you need only edit the relevant fields in [`src/data/battle_moves.h`](#srcdatamoves_infoh). This will let you change a move's:
- name
- description
- power
- accuracy
- type
- category
- target
- pp
- recoil percentage
- flags
- Z-move effect (for status moves) or overwritting its calculated power (for damaging moves)

### Changing a move's main effect
To change the main effect of a move to an existing effect, you need only change its `effect` field to one of the options in [`src/data/battle_move_effects.h`](#srcdatabattle_move_effectsh). If you wish to keep the effect but simply modify how it works, you can modify how it plays out on screen by editing its entry in [`data/battle_scripts_1.s`](#databattle_scripts_1s) and any relevant functions in [`src/battle_script_commands.c`](#srcbattle_script_commandsc). To change how a move's dynamic power, accuracy and are calculated, then you need to modify the following functions:

- For power: `CalcMoveBasePowerAfterModifiers` in [`src/battle_util.c`](#srcbattle_utilc)
- For accuracy: `AccuracyCalcHelper` in [`src/battle_script_commands.c`](#srcbattle_script_commandsc)
- For type: `SetTypeBeforeUsingMove` in [`src/battle_main.c`](#srcbattle_mainc)

Note: A generic function for calculating category does not currently exist - Photon Geyser's script in [`data/battle_scripts_1.s`](#databattle_scripts_1s) uses a special `callnative` function `BS_SetPhotonGeyserCategory`.

### Changing a move's additional effects
If you look at the example [here](#src/data/moves_info.h), you can see that Thunder Shock has an additional effects array that contains a single move effect `MOVE_EFFECT_PARALYSIS` with a 10% chance of applying. Thanks to this field, you can add and remove primary and secondary effects (so long as they are defined by a `MOVE_EFFECT`) to a move without having to change its effect or script. You can also make an effect apply to the attacker rather than the target (for, say, a stat boost) with `.self = TRUE` and you can set the probability to whatever you want with the `chance` field.

All additional effects with a defined chance (even 100%) are treated as "secondary effects". This means that they are nullified by Sheer Force, blocked by Shield Dust or the Covert Cloak, and have their chance modified by Serene Grace. Additional effects without a chance field (effectively setting it to 0) are treated as "primary effects", which means that they cannot be blocked by the aforementioned items and abilities and their chance to occur cannot be modified; they will *always* happen.

Depending on the move effect, it is possible to also set a `multistring` value. For example:

```
.additionalEffects = ADDITIONAL_EFFECTS({
    .moveEffect = MOVE_EFFECT_WRAP,
    .multistring = B_MSG_WRAPPED_MAGMA_STORM,
}),
```

For Magma Storm, we not only want the wrapping move effect, we want to give it a unique string when it activates. The index is an enum defined in `battle_string_ids.h` and it corresponds to an entry (for this move effect) in the `gWrappedStringIds` list in battle_message.c. For custom strings, you need to add an enum and an entry respectively. For new custom move effects, you will have to add a new set of enums and a new table of strings.

Each move can have up to 3 additional effects, allowing you to construct monstrosities like this:
```
[MOVE_POUND] =
{
    .name = COMPOUND_STRING("Pound"),
    .description = COMPOUND_STRING(
        "Pounds the foe with\n"
        "forelegs or tail."),
    .effect = EFFECT_HIT,
    .power = 40,
    .type = TYPE_NORMAL,
    .accuracy = 100,
    .pp = 35,
    .target = TARGET_SELECTED,
    .priority = 0,
    .category = DAMAGE_CATEGORY_PHYSICAL,
    .additionalEffects = ADDITIONAL_EFFECTS({
        .moveEffect = MOVE_EFFECT_PARALYSIS,
        .chance = 10,
    },{
        .moveEffect = MOVE_EFFECT_CONFUSION,
        .chance = 100,
    },{
        .moveEffect = MOVE_EFFECT_FLINCH,
        .chance = 30,
    }),
    .makesContact = TRUE,
    .ignoresKingsRock = B_UPDATED_MOVE_FLAGS == GEN_4,
    .contestEffect = CONTEST_EFFECT_HIGHLY_APPEALING,
    .contestCategory = CONTEST_CATEGORY_TOUGH,
    .contestComboStarterId = COMBO_STARTER_POUND,
    .contestComboMoves = {0}
},
```

**Note: at the moment, additional effects can only be used by damaging moves, not by status moves.**

## Adding a new move
To add a new move, you need to create an entry in three locations:

- a define in [`include/constants/moves.h`](#includeconstantsmovesh)
- an info entry in [`src/data/battle_moves.h`](#srcdatamoves_infoh)
- an animation entry in [data/battle_anim_scripts.s](#databattle_anim_scriptss)

Now let's create a Stone Blade move 
```C
    [MOVE_STONE_BLADE] =
    {
        .name = COMPOUND_STRING("Stone Blade"),
        .description = COMPOUND_STRING("A strong slice with a high crit ratio"),
        .effect = EFFECT_HIT,
        .power = 70, // 70 Base Power
        .type = TYPE_ROCK, // Rock type
        .accuracy = 0, // 0: no accuracy check
        .pp = 10, // 10 Power Points
        .target = TARGET_SELECTED, // Target needs to be selected
        .priority = 0,
        .category = DAMAGE_CATEGORY_PHYSICAL,
        .criticalHitStage = 1,
        .makesContact = TRUE, // added the contact flag so can activate effects like static 
        .slicingMove = TRUE, // will be boosted by Sharpness
        .battleAnimScript = gBattleAnimMove_None, // replace with new anim
        .additionalEffects = ADDITIONAL_EFFECTS({
            .moveEffect = MOVE_EFFECT_STAT_MINUS,
            .speed = 1,
            .chance = 100,
        }, {
            .moveEffect = MOVE_EFFECT_STAT_PLUS,
            .speed = 1,
            .self = TRUE,
            .chance = 100,
        }),
    },
```
We created a basic rock type move with a high critical hit ratio. The move also has 2 additional effects. An effect that drops the speed of the target and an effect that increases speed


And that's it! You can use an existing animation or effect for your move - or you can add your own, but I'll leave figuring that out to you.

