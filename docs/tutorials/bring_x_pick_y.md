# Introduction
![Demo of Bring X Pick Y Functionality](/docs/tutorials/img/bxpy/demo.png)

In this mode, the player must have X healthy, legal, Pokémon in the party. Using information about the opponent's team, they must then pick Y Pokémon to battle with. This mimicks the behavior from several official Pokémon titles.

# Usage
The functionality is run by using the macro `bringxpicky` in an overworld script. `bringxpicky` can be broken down into four seperate sections:

1. Optionally heal the player's party before battle (`BXPY_TryHealBeforeBattle`)
2. Check the player's party for legality (`BXPY_Script_CheckErrors`)
3. Start Team Preview (`BXPY_Init`)
4. Start and Post Battle (`BattleSetup_StartBXPYBattle`)

Users that want to execute outside of an overworld script can call the functions directly, but will need to handle error rejection and passing through Steps 1 and 2 manually.

The overworld macro takes five required arguments and three optional arguments.

## `battleType`
| `BXPY_BATTLE_SINGLE` | `BXPY_BATTLE_DOUBLE` |
| --- | --- |
| ![Demo of BXPY_BATTLE_SINGLE](/docs/tutorials/img/bxpy/single.png) | ![Demo of BXPY_BATTLE_DOUBLE](/docs/tutorials/img/bxpy/double.png) |

Required argument.

Dictates if the battle is a Single (`BXPY_BATTLE_SINGLE`) or Double Battle (`BXPY_BATTLE_DOUBLE`). 

### Restrictions
- Must be `BXPY_BATTLE_DOUBLE` if ``partnerId` or `trainer_b` are declared.

## `bringSize`
| `6` | `4` |
| --- | --- |
| ![](/docs/tutorials/img/bxpy/bring6pick4.png)| ![](/docs/tutorials/img/bxpy/bring4pick3.png)| 

Required argument.

Dictates how many Pokémon each side brings before Team Preview begins.

### Restrictions
- Must be greater than `0`.
- Cannot be greater than `PARTY_SIZE`.
- Cannot be less than `pickSize`.

## `pickSize`
| `4` | `3` |
| --- | --- |
| ![](/docs/tutorials/img/bxpy/bring6pick4.png)| ![](/docs/tutorials/img/bxpy/bring4pick3.png)| 

Required argument.

Dictates how many Pokémon each side pick for battle. 

### Restrictions
- Must be greater than `0`.
- Cannot be greater than `PARTY_SIZE`.
- Must be greater than or equal to `bringSize`.

## `trainer_a`
| `TRAINER_GABRIELLE_1` | `TRAINER_WALLACE` |
| --- | --- |
| ![](/docs/tutorials/img/bxpy/gabirelle.png)| ![](/docs/tutorials/img/bxpy/bring4pick3.png)| 

Required argument.

Dictates what trainer is battled against.

### Restrictions
- Must be a valid trainerId between `TRAINER_NONE` and `TRAINERS_COUNT`.

## `lose_text_a`
`bringxpicky BXPY_BATTLE_SINGLE, 4, 3, TRAINER_GABRIELLE_1, Route117_PokémonDayCare_Text_YouHaveJustOneMon`
![](/docs/tutorials/img/bxpy/losetext.png)

Required argument.

Dictates what `trainer_a` will say when they are defeated.

### Restrictions
- Must be a string.

## `trainer_b`
| `TRAINER_COLTON` | `TRAINER_RONALD` |
| --- | --- |
| ![](/docs/tutorials/img/bxpy/colton.png)| ![](/docs/tutorials/img/bxpy/ronald.png)| 

Optional argument. Defaults to `TRAINER_NONE` when not defined.

Dictates what second trainer is battled against.

### Restrictions
- Must be a valid trainerId between `TRAINER_NONE` and `TRAINERS_COUNT`.
- Must be defined if `lose_text_b` is defined.

## `lose_text_b`
![](/docs/tutorials/img/bxpy/losetextb.png)

Optional argument. Defaults to `NULL` when not defined.

### Restrictions
- Must be a string.
- Must be defined if `trainer_b` is defined.

Dictates what `trainer_b` will say when they are defeated.

## `partnerId`
![](/docs/tutorials/img/bxpy/partner.png)

Optional argument. Defaults to `PARTNER_NONE` when not defined.

Dictates what partner battles alongside the Player.

### Restrictions
- Must be a valid partnerId between `PARTNER_NONE` and `PARTNER_COUNT`.

# Party Legality
## Heal
The player's team will be healed before their party is checked for legality. All legality checks count alive Pokémon.

This can be turned off when `BXPY_HEAL` is not set to `BXPY_HEAL_BEFORE_BATTLE` OR `BXPY_HEAL_ALWAYS`.

## `BXPY_ERROR_BRING_SIZE_TOO_LARGE`
![](/docs/tutorials/img/bxpy/bringsizetoolarge.png)

If the Player's party has more alive Pokémon than `bringSize`, the Player is given a warning via the overworld. The script stops and does not proceed to Team Preview.

## `BXPY_ERROR_BRING_SIZE_NOT_ENOUGH`
![](/docs/tutorials/img/bxpy/bringsizenotenough.png)

If the Player's party has less alive Pokémon than `bringSize`, the Player is given a warning via the overworld. The script stops and does not proceed to Team Preview. 

This can be turned off via `BXPY_FORCE_MINIMUM_MONS`, and this config is `TRUE` by default.

## `BXPY_ERROR_CLAUSE_SPECIES`
![](/docs/tutorials/img/bxpy/species.png)

If the Player's party has multiple Pokémon that are the same species, the Player is given a warning via the overworld. The script stops and does not proceed to Team Preview. 

This can be turned off via `BXPY_CLAUSE_SPECIES`, and this config is `TRUE` by default.

## `BXPY_ERROR_CLAUSE_ITEM`
![](/docs/tutorials/img/bxpy/item.png)

If the Player's party has multiple Pokémon that are the holding the same item, the Player is given a warning via the overworld. The script stops and does not proceed to Team Preview. 

This can be turned off via `BXPY_CLAUSE_ITEMS`, and this config is `TRUE` by default.

## `BXPY_ERROR_CLAUSE_SPECIAL_POKEMON`
![](/docs/tutorials/img/bxpy/special.png)

If the Player's party has any Pokémon that are [Restricted](https://bulbapedia.bulbagarden.net/wiki/Special_Pok%C3%A9mon), the Player is given a warning via the overworld. The script stops and does not proceed to Team Preview.

This can be turned off via `BXPY_CLAUSE_SPECIAL_POKEMON`, and this config is `TRUE` by default.

If all the checks pass, the Player will not see any messages. The Player's party is saved to the saveblock, and any fainted or unhatched Pokémon are removed from the Party. The game then proceeds to Team Preview.

# Team Preview
For all `BXPY_OPEN_TEAM_PREVIEW_SHOW_ENEMY_*` configs, when `TRUE`, the Player will be able to see this specific piece of information on the Team Preview AND Enemy Summary Screen. `FALSE` will disable it in both places.
## `BXPY_TEAM_PREVIEW_SHOW_ENEMY_SPECIES`
| `BXPY_SPECIES_HIDE` | `BXPY_SPECIES_SHOW_BASE` | `BXPY_SPECIES_SHOW_TRUE` |
| --- | --- | --- |
| ![](/docs/tutorials/img/bxpy/speciesHide.png)| ![](/docs/tutorials/img/bxpy/speciesShowBase.png)| ![](/docs/tutorials/img/bxpy/speciesShowTrue.png)|


When set to `BXPY_SPECIES_HIDE`, the enemy Pokémon will appear as ???.

When set to `BXPY_SPECIES_SHOW_BASE`, the enemy will show Pokémon as their base form. For example, if the opponent has `SPECIES_ROTOM_HEAT`, it will be shown as `SPECIES_ROTOM`.

When set to `BXPY_SPECIES_SHOW_TRUE`, the enemy will show Pokémon as their true species and form.
## `BXPY_TEAM_PREVIEW_SHOW_ENEMY_GENDER`
| `TRUE` | `FALSE` |
| --- | --- |
| ![](/docs/tutorials/img/bxpy/speciesShowTrue.png)| ![](/docs/tutorials/img/bxpy/genderFalse.png)|


When `FALSE`, all of the enemy Pokémon will show "?" for their gender.
## `BXPY_TEAM_PREVIEW_SHOW_ENEMY_LEVEL`
| `TRUE` | `FALSE` |
| --- | --- |
| ![](/docs/tutorials/img/bxpy/speciesShowTrue.png)| ![](/docs/tutorials/img/bxpy/levelFalse.png)|


When FALSE, all of the enemy Pokémon levels will show as "???".
# Open Team Sheet
## `BXPY_OPEN_TEAM_SHEET`
When `TRUE`, the Player can open the Pokémon Summary Screen for enemy Pokémon. 

If this is `FALSE`, all of the values for `BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_*` are ignored.
### `BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_ABILITY`
| `TRUE` | `FALSE` |
| --- | --- |
| ![](/docs/tutorials/img/bxpy/speciesShowTrue.png)| ![](/docs/tutorials/img/bxpy/abilityFalse.png)|


When `FALSE`, the enemy Pokémon's Ability appears as `ABILITY_NONE`.
## `BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_ITEM`
| `BXPY_ITEM_NO_VISIBILITY` | `BXPY_ITEM_SHOW_POSSESSION` | `BXPY_ITEM_SHOW_ITEM` |
| --- | --- | --- |
| ![](/docs/tutorials/img/bxpy/itemNoVisibility.png)| ![](/docs/tutorials/img/bxpy/itemShowPossession.png)| ![](/docs/tutorials/img/bxpy/speciesShowTrue.png)|


When set to `BXPY_ITEM_NO_VISIBILITY`, the enemy Pokémon's held item will appear as "Unknown", regardless of the presence of an item.

When set to `BXPY_ITEM_SHOW_POSSESSION`, if the enemy Pokémon is holding an item, it will be displayed as "???". If they are not, "NONE" will be displayed.

When set to `BXPY_ITEM_SHOW_ITEM`, if the enemy Pokémon is holding an item, it will be displayed as the actual item. If they are not, "NONE" will be displayed.

## Stats
If all three of `BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_*` configs are `TRUE`, the Pokémon stats will be visible. If any of them are `FALSE`, the stats will display as "???".

### `BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_NATURE`
| `TRUE` | `FALSE` |
| --- | --- |
| ![](/docs/tutorials/img/bxpy/speciesShowTrue.png)| ![](/docs/tutorials/img/bxpy/natureFalse.png)|


When `FALSE`, the enemy Pokémon's Nature appears as "???". Stats are not colored. Respects `P_SUMMARY_SCREEN_NATURE_COLORS`.
### `BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_EV`
| `TRUE` | `FALSE` |
| --- | --- |
| ![](/docs/tutorials/img/bxpy/speciesShowTrue.png)| ![](/docs/tutorials/img/bxpy/evFalse.png)|


When `FALSE`, the enemy Pokémon's Effort Values appear as "?". Respects `P_SUMMARY_SCREEN_IV_EV_INFO` and `P_SUMMARY_SCREEN_IV_EV_VALUES`.
### `BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_IV`
| `TRUE` | `FALSE` |
| --- | --- |
| ![](/docs/tutorials/img/bxpy/speciesShowTrue.png)| ![](/docs/tutorials/img/bxpy/ivFalse.png)|


When `FALSE`, the enemy Pokémon's Individual Values appear as "?". Respects `P_SUMMARY_SCREEN_IV_EV_INFO` and `P_SUMMARY_SCREEN_IV_EV_VALUES`.
### `BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_GIMMICK_TERA`
| `TRUE` | `FALSE` |
| --- | --- |
| ![](/docs/tutorials/img/bxpy/speciesShowTrue.png)| ![](/docs/tutorials/img/bxpy/teraFalse.png)|


When `FALSE`, the enemy Pokémon's Tera Type appears as `TYPE_MYSTERY`. Respects `P_SHOW_TERA_TYPE`.
### `BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_MOVE`
| `TRUE` | `FALSE` |
| --- | --- |
| ![](/docs/tutorials/img/bxpy/speciesShowTrue.png)| ![](/docs/tutorials/img/bxpy/moveFalse.png)|


When `FALSE`, the enemy Pokémon's Moves appear as `MOVE_NONE`.

# Bring AI
Once the Player chooses Y Pokémon to battle with, Team Preview closes.

Bring X Pick Y's selection AI uses the same AI trainer flags as the battle AI. This means that the AI's knowledge of the player's moves, items, and abilities are all controlled by those flags, and that knowledge will affect the AI's decision making (ie. it will not evaluate 1v1 potential if it has no flags that provide information about the player's moves, items will not be considered when evaluating speed unless `AI_FLAG_OMNISCIENT` or `AI_FLAG_ITEM_OMNISCIENCE` is set, etc.). The following is run for each of the battler's Pokémon against all of the Pokémon on the opposing side.

1. If the AI's Pokémon A can defeat the enemy Pokémon Z, Pokémon A receieves `CAN_1V1_MATCHUP_POINTS` (`5`) points.
2. If the AI's Pokémon A has a strong defensive type matchup against enemy Pokémon Z, Pokémon A recieves `DEFENSIVE_MATCHUP_POINTS` (`2`) points.
3. If the AI's Pokémon A's moves have a strong offensive type matchup against enemy Pokémon Z's types, Pokémon A recieves `OFFENSIVE_MATCHUP_POINTS` (`2`) points.
4. If the AI's Pokémon A's speed is higher than enemy Pokémon Z, Pokémon A recieves `OUTSPEED_MATCHUP_POINTS` (`1`) points.
5. Each eligible Pokémon receives `1` point as a baseline.

Once every Pokémon and battler is evaluated, the AI will bring the top Y scoring Pokémon into battle, with the highest ranking Pokémon being sent out first. If multiple Pokémon are tied, a Pokémon is randomly chosen between the tied Pokémon until there are no ties. 

The Pokémon on each side that were not brought to the battle are removed from the party. All scoring occurs before the Pokémon are removed. The battle then begins.

# Post Battle

The following occurs regardless of the result of the battle.

## Load Party & Retain Changes
| `TRUE` | `FALSE` |
| --- | --- |
| ![](/docs/tutorials/img/bxpy/retainTrue.png)| ![](/docs/tutorials/img/bxpy/retainFalse.png)| 

The Player's original party prior to starting bringXpickY is restored.

Any changes that occured to the participating Pokémon is retained. This includes changes in HP, PP, Experience, Level, or even Evolution. This is disabled by default, and is enabled if `BXPY_RETAIN_CHANGES` is `TRUE`. This functionality requires `B_VAR_BXPY`(`B_VAR_SKY_BATTLE`) to be set.

## Heal Post Battle
| `TRUE` | `FALSE` |
| --- | --- |
| ![](/docs/tutorials/img/bxpy/retainTrue.png)| ![](/docs/tutorials/img/bxpy/healFalse.png)| 

The Player's party is healed after battle. This can be turned off when `BXPY_HEAL` is not set to `BXPY_HEAL_AFTER_BATTLE` OR `BXPY_HEAL_ALWAYS`.

## Continue Script
The script that was running before `bringxpicky` was run continues.

# Installation
These instructions assume that you can build [pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion), have a basic understanding of C, and are familiar with using the in-game scripting language. If you do not, please watch the tutorials series from [Team Aqua's Hideout](https://youtube.com/playlist?list=PLLNv9Lq6kDmTIYfN5NvgQRvfOHTOXl0uU).

## git merge (recommended)

From the root directory of your project, run the following commands in your terminal program of choice:

```bash
git remote add linathanzel-expansion https://github.com/LinathanZel/pokeemerald-expansion # This adds our `pokeemerald-expansion` branch as a remote repo.
git pull linathanzel-expansion bringXpickY # This pulls in the bringXpickY feature branch
```

## Manual merge
If your project is:
* Too far behind `pokeemerald-expansion`
* Using a different base (`pokeemerald` or `pokefirered`)
* Some other reason that I can't think of

You can manually implement the features using [the diff between this branch and pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion/compare/upcoming...LinathanZel:pokeemerald-expansion:bringXpickY) as a guide. You will need to manually edit or create each of these files in your project to properly recreate the feature.

# Warnings
## Saveblock space
Bring X Pick Y requires 1 flag, and optionally consumes 1 variable. 

* `B_FLAG_BXPY` is set directly before a battle from this feature starts. When this flag is not set, the game will:
    - not attempt to restore the experience / HP / PP changes that happened to pariticpating Pokémon.
    - not attempt to heal the party after the battle, even if `BXPY_HEAL` is configured to do so.
    - overwrite any changes made to the party by the bringXpickY feature before battle. Without this, the opponent will always battle with their full and original team.
* If `BXPY_RETAIN_CHANGES` is `TRUE`, the variable `B_VAR_SKY_BATTLE` is used to store the Pokémon that participated in battle. 
    * After battle, the experience / HP / PP changes that occured to the participating Pokémon are applied to the particpating Pokémon.
    * If `BXPY_RETAIN_CHANGES` is `TRUE`, the game will not compile if `B_VAR_BXPY` is not properly set.

# Frequently Asked Questions (FAQ)
> Are link battles supported?
No.

> Can `bringxpicky` be called from trainer scripts?
No, it requires its own script.
