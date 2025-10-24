#ifndef GUARD_CONFIG_SUMMARY_SCREEN_H
#define GUARD_CONFIG_SUMMARY_SCREEN_H

// Settings
#define P_SUMMARY_SCREEN_NATURE_COLORS   TRUE   // If TRUE, nature-based stat boosts and reductions will be red and blue in the summary screen.
#define P_SUMMARY_SCREEN_RENAME          TRUE   // If TRUE, an option to change Pokémon nicknames replaces the cancel prompt on the summary screen info page.

// IV/EV settings
#define P_SUMMARY_SCREEN_IV_EV_INFO      FALSE  // If TRUE, will allow player to cycle through the Stats, IVs, and EVs in the summary screen skills page.
#define P_SUMMARY_SCREEN_IV_EV_BOX_ONLY  FALSE  // If TRUE, will allow player to cycle through the Stats, IVs, and EVs in the summary screen skills page, but only in the PC storage box.
#define P_SUMMARY_SCREEN_IV_EV_TILESET   FALSE  // If TRUE, loads an alternate tileset to allow changing the "STATS" label in the summary screen skills page. Note: if it's still loading the alternate tileset after changing this and recompiling, you may need a `make clean` before compilation.
#define P_SUMMARY_SCREEN_IV_EV_VALUES    FALSE  // If TRUE, will show the actual IV value instead of the letter grade.
/*
LETTER GRADE GUIDE:

    F = 0
    D = 1 - 15
    C = 16 - 25
    B = 26 - 29
    A = 30
    S = 31

Info taken from https://bulbapedia.bulbagarden.net/wiki/Stats_judge.
*/
#define P_SUMMARY_SCREEN_IV_ONLY         FALSE  // If TRUE, will only show IV info in the summary screen.
#define P_SUMMARY_SCREEN_EV_ONLY         FALSE  // If TRUE, will only show EV info in the summary screen.

// IV/EV flags
#define P_FLAG_SUMMARY_SCREEN_IV_EV_INFO 0      // If this flag is set, will allow player to cycle through the Stats, IVs, and EVs in the summary screen skills page. Note: if P_SUMMARY_SCREEN_IV_EV_INFO is TRUE, this flag does nothing.

// Move Relearner var
// NOTE: unused vars are found in include/constants/vars.h and named something like VAR_UNUSED_0x####. To assign a var, rename one of them to something relevant, ie VAR_MOVE_RELEARNER_STATE, and then replace the 0 below with that name.
#define P_VAR_MOVE_RELEARNER_STATE       0       // IMPORTANT! Assign a var to make the move relearner swap between level up, egg, TM and tutor.

// Move Relearner settings
#define P_SUMMARY_SCREEN_MOVE_RELEARNER  TRUE    // If TRUE, shows an option for Pokémon to relearn moves on the summary screen moves page.
#define P_SUMMARY_MOVE_RELEARNER_FULL_PP FALSE   // If TRUE, the move relearner in the summary screen restores relearned moves' PP to full.
#define P_ENABLE_MOVE_RELEARNERS         FALSE   // If TRUE, it enables move relearners for level up, egg, TM and tutor.
#define P_PRE_EVO_MOVES                  TRUE    // If TRUE, it enables the Pokémon to learn moves from it's pre evolution.
#define P_ENABLE_ALL_LEVEL_UP_MOVES      TRUE    // If TRUE, it enables the Pokémon to learn all level up moves, regardless of its level.
#define P_ENABLE_ALL_TM_MOVES            TRUE    // If TRUE, it enables the Pokémon to learn all TMs its compatible with, regardless of it being in the bag.
#define P_SORT_MOVES                     TRUE    // If TRUE, sorts all moves alphabetically in the relearner's list.

// Move Relearner flags
#define P_FLAG_PARTY_MOVE_RELEARNER      0       // If this flag is set, it enables the move relearner in the party menu.
#define P_FLAG_SCRIPT_MOVE_RELEARNER     0       // Set this flag if you're planning on using the move relearner script from data/scripts/move_relearner.inc
// Redundant if P_ENABLE_MOVE_RELEARNERS is TRUE.
#define P_FLAG_LEVEL_UP_MOVES            0       // If this flag is set, enables level up move relearner.
#define P_FLAG_EGG_MOVES                 0       // If this flag is set, enables egg move relearner.
#define P_FLAG_TUTOR_MOVES               0       // If this flag is set, enables tutor move move relearner.
#define P_FLAG_TM_MOVES                  0       // If this flag is set, enables tutor move move relearner.

#endif // GUARD_CONFIG_SUMMARY_SCREEN_H
