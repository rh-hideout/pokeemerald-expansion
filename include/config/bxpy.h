#ifndef GUARD_CONFIG_BXPY_H
#define GUARD_CONFIG_BXPY_H

#define BXPY_SCROLLING_BACKGROUND                       TRUE // When TRUE, the background on the BXPY menu will scroll.

#define BXPY_FORCE_MINIMUM_MONS                         TRUE // When TRUE, the PLayer must have at least bringSize unfainted Pokémon in the Party.
#define BXPY_CLAUSE_ITEMS                               TRUE // When TRUE, the Player cannot have duplicate held items in their Party.
#define BXPY_CLAUSE_SPECIES                             TRUE // When TRUE, the Player cannot have duplicate in their Party.
#define BXPY_CLAUSE_SPECIAL_POKEMON                     TRUE // When TRUE, the Player cannot have Special Pokemon in their Party.

#define BXPY_HEAL                                       BXPY_HEAL_ALWAYS // Controls when the Player's party is healed, if at all. Valid values are found in BXPYHealModes in include/constants/bxpy.h

#define BXPY_OPEN_TEAM_SHEET                            TRUE  // When TRUE, the Player can open the Pokemon Summary Screen for enemy Pokemon. If this is FALSE, all of the values for BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_* are ignored.

// For all BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_* configs, when TRUE, the Player will be able to see this specific piece of information on the enemy's Pokemon Summary Screen.

#define BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_ABILITY         TRUE  // When FALSE, the enemy Pokemon's Ability appears as `ABILITY_NONE`.

// If all three of BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_* configs are TRUE, the Pokemon stats will be visible. If any of them are FALSE, the stats will display as ???.

#define BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_NATURE     FALSE // When FALSE, the enemy Pokemon's Nature appears as ???. Stats are not colored.
#define BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_EV         FALSE // When FALSE, the enemy Pokemon's Effort Values appear as ?.
#define BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_IV         FALSE // When FALSE, the enemy Pokemon's Individual Values appear as ?. Respects P_SUMMARY_SCREEN_IV_EV_INFO and P_SUMMARY_SCREEN_IV_EV_VALUES
#define BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_GIMMICK_TERA    TRUE  // When FALSE, the enemy Pokemon's Tera Type appears as TYPE_MYSTERY. Respects P_SHOW_TERA_TYPE.
#define BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_MOVE            TRUE // When FALSE, the enemy Pokemon's Moves appear as `MOVE_NONE`.

// For all BXPY_OPEN_TEAM_PREVIEW_SHOW_ENEMY_* configs, when TRUE, the Player will be able to see this specific piece of information on the Team Preview AND Enemy Summary Screen. FALSE will disable it in both places.

#define BXPY_TEAM_PREVIEW_SHOW_ENEMY_SPECIES            BXPY_SPECIES_SHOW_TRUE
// When set to `BXPY_SPECIES_HIDE`, the enemy Pokemon will appear as ???.
// When set to `BXPY_SPECIES_SHOW_BASE`, the enemy will show Pokemon as their base form. For example, if the opponent has `SPECIES_ROTOM_HEAT`, it will be shown as `SPECIES_ROTOM`.
// When set to `BXPY_SPECIES_SHOW_TRUE`, the enemy will show Pokemon as their true species and form.

#define BXPY_TEAM_PREVIEW_SHOW_ENEMY_GENDER             TRUE // When FALSE, all of the enemy Pokemon will show ? for their gender.
#define BXPY_TEAM_PREVIEW_SHOW_ENEMY_ITEM               BXPY_ITEM_SHOW_ITEM
// When set to `BXPY_ITEM_NO_VISIBILITY`, the enemy Pokemon will appear with ? icons for Held Items on Team Preview. On the Summary Screen, all will appear as "Unknown". Having no item will appear as "Unknown".
// When set to `BXPY_ITEM_SHOW_POSSESSION`, the enemy Pokemon will appear on Team Preview with generic item icons if they are holding an item. On the Summary Screen, holding an item will be displayed as "???" and not holding an item will appear as "NONE".
// When set to `BXPY_ITEM_SHOW_ITEM`, the enemy Pokemon will appear with a sprite of their real item if they are holding an item. On the Summary screen, holding an item will be displayed with the true name, and not holding an item will appear as "NONE".

#define BXPY_TEAM_PREVIEW_SHOW_ENEMY_LEVEL              TRUE // When FALSE, all of the enemy Pokemon levels will show as ???.

// For all BXPY_OPEN_TEAM_SHEET_SHOW_PLAYER_* configs, when TRUE, the AI will be able to see this specific information when calculating which Pokemon to bring. If a trainer on the opposing side has the `AI_FLAG_OMNISCIENT` flag, these configs will be ignored and all AI will have access to full information. If a Trainer on the opposing side does NOT have `AI_FLAG_OMNISCIENT`, then the AI will not have this information for the battle itself.

#define BXPY_OPEN_TEAM_SHEET_SHOW_PLAYER_ABILITY        TRUE
#define BXPY_OPEN_TEAM_SHEET_SHOW_PLAYER_ITEM           TRUE
#define BXPY_OPEN_TEAM_SHEET_SHOW_PLAYER_LEVEL          TRUE
#define BXPY_OPEN_TEAM_SHEET_SHOW_PLAYER_MOVES          TRUE
#define BXPY_OPEN_TEAM_SHEET_SHOW_PLAYER_STATS          TRUE

#define BXPY_RETAIN_CHANGES                             FALSE // When TRUE, after battle, any changes that occured to the participating Pokemon is retained. This includes changes in HP, PP, Experience, Level, or even Evolution.

#define B_VAR_BXPY                                       B_VAR_SKY_BATTLE // This var is used to maintain BXPY_RETAIN_CHANGES.
#define B_FLAG_BXPY                                      FLAG_UNUSED_0x264                // This flag is used to manage BXPY mode's interaction with other features.

#endif // GUARD_CONFIG_BXPY_H
