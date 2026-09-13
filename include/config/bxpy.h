#ifndef GUARD_CONFIG_BXPY_H
#define GUARD_CONFIG_BXPY_H

#define BXPY_FORCE_MINIMUM_MONS                         TRUE              // When TRUE, the Player must have at least bringSize unfainted Pokémon in the Party.
#define BXPY_CLAUSE_ITEMS                               TRUE              // When TRUE, the Player cannot have duplicate held items in their Party.
#define BXPY_CLAUSE_SPECIES                             TRUE              // When TRUE, the Player cannot have duplicate in their Party.
#define BXPY_CLAUSE_SPECIAL_POKEMON                     TRUE              // When TRUE, the Player cannot have Special Pokemon in their Party. Special is defined as Pokemon with the `isMythical` or `isFrontierBanned`.

#define BXPY_HEAL                                       BXPY_HEAL_NEVER   // Controls when the Player's party is healed, if at all. Valid values are found in BXPYHealModes in include/constants/bxpy.h.

#define BXPY_OPEN_TEAM_SHEET                            TRUE              // When TRUE, the Player can open the Pokemon Summary Screen for enemy Pokemon. If this is FALSE, all of the values for BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_* are ignored.

// For all BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_* configs, when TRUE, the Player will be able to see this specific piece of information on the enemy's Pokemon Summary Screen.

#define BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_ABILITY         TRUE              // When FALSE, the enemy Pokemon's Ability appears as `ABILITY_NONE`.
#define BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_ITEM            BXPY_ITEM_SHOW_ITEM
// When set to `BXPY_ITEM_NO_VISIBILITY`, the enemy Pokemon will appear with ? icons for Held Items on Team Preview. On the Summary Screen, all will appear as "Unknown". Having no item will appear as "Unknown".
// When set to `BXPY_ITEM_SHOW_POSSESSION`, the enemy Pokemon will appear on Team Preview with generic item icons if they are holding an item. On the Summary Screen, holding an item will be displayed as "???" and not holding an item will appear as "NONE".
// When set to `BXPY_ITEM_SHOW_ITEM`, the enemy Pokemon will appear with a sprite of their real item if they are holding an item. On the Summary screen, holding an item will be displayed with the true name, and not holding an item will appear as "NONE".


// If all three of BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_* configs are TRUE, the Pokemon stats will be visible. If any of them are FALSE, the stats will display as ???.

#define BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_NATURE     TRUE              // When FALSE, the enemy Pokemon's Nature appears as ???. Stats are not colored.
#define BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_EV         FALSE             // When FALSE, the enemy Pokemon's Effort Values appear as ?.
#define BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_STAT_IV         FALSE             // When FALSE, the enemy Pokemon's Individual Values appear as ?. Respects P_SUMMARY_SCREEN_IV_EV_INFO and P_SUMMARY_SCREEN_IV_EV_VALUES.
#define BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_GIMMICK_TERA    TRUE              // When FALSE, the enemy Pokemon's Tera Type appears as TYPE_MYSTERY. Respects P_SHOW_TERA_TYPE.
#define BXPY_OPEN_TEAM_SHEET_SHOW_ENEMY_MOVE            TRUE              // When FALSE, the enemy Pokemon's Moves appear as `MOVE_NONE`.

// For all BXPY_OPEN_TEAM_PREVIEW_SHOW_ENEMY_* configs, when TRUE, the Player will be able to see this specific piece of information on the Team Preview AND Enemy Summary Screen. FALSE will disable it in both places.

#define BXPY_TEAM_PREVIEW_SHOW_ENEMY_SPECIES            BXPY_SPECIES_SHOW_TRUE
// When set to `BXPY_SPECIES_HIDE`, the enemy Pokemon will appear as ???.
// When set to `BXPY_SPECIES_SHOW_BASE`, the enemy will show Pokemon as their base form. For example, if the opponent has `SPECIES_ROTOM_HEAT`, it will be shown as `SPECIES_ROTOM`.
// When set to `BXPY_SPECIES_SHOW_TRUE`, the enemy will show Pokemon as their true species and form.

#define BXPY_TEAM_PREVIEW_SHOW_ENEMY_GENDER             TRUE              // When FALSE, all of the enemy Pokemon will show ? for their gender.
#define BXPY_TEAM_PREVIEW_SHOW_ENEMY_LEVEL              TRUE              // When FALSE, all of the enemy Pokemon levels will show as ???.

// Bring X Pick Y AI party scoring points
#define DEFENSIVE_MATCHUP_POINTS                        2                 // Score increase for having a positive defensive type matchup against an opposing party member
#define OFFENSIVE_MATCHUP_POINTS                        2                 // Score increase for having a positive offensive type matchup against an opposing party member
#define OUTSPEED_MATCHUP_POINTS                         1                 // Score increase for outspeeding against an opposing party member
#define CAN_1V1_MATCHUP_POINTS                          5                 // Score increase for winning a projected 1v1 against an opposing party member

#define BXPY_AI_DEBUG                                   FALSE             // Enables AI debug prints, useful for debugging in lieu of tests

#define BXPY_RETAIN_CHANGES                             FALSE             // When TRUE, after battle, any changes that occured to the participating Pokemon is retained. This includes changes in HP, PP, Experience, Level, or even Evolution.

#define B_VAR_BXPY                                      B_VAR_SKY_BATTLE  // This var is used to maintain BXPY_RETAIN_CHANGES.
#define B_FLAG_BXPY                                     0                 // This flag is used to manage BXPY mode's interaction with other features.


// Bring X Pick Y Comestic Configurations
#define BXPY_SKIN                                       GEN_3             // This changes the graphical skin that the BXPY menu uses. The currently only valid values are GEN_3 or GEN_CHAMPIONS. If an invalid value is used, the game will fall back to GEN_3.
#define BXPY_SCROLLING_BACKGROUND                       TRUE              // When TRUE, the background on the BXPY menu will scroll. This config only has an effect when BXPY_SKIN == GEN_CHAMPIONS.
#define MUS_BXPY_BACKGROUND                             MUS_B_DOME_LOBBY
#define SE_BXPY_GENERIC                                 SE_SELECT
#define SE_BXPY_ERROR                                   SE_BOO
#define SE_BXPY_SWITCH_PAGE                             SE_ROTATING_GATE
#define SE_BXPY_REMOVE                                  SE_BALL_OPEN

#endif // GUARD_CONFIG_BXPY_H
