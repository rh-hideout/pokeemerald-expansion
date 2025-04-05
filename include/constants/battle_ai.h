#ifndef GUARD_CONSTANTS_BATTLE_AI_H
#define GUARD_CONSTANTS_BATTLE_AI_H

// battlers
#define AI_TARGET 0
#define AI_USER 1
#define AI_TARGET_PARTNER 2
#define AI_USER_PARTNER 3

// get_type command
#define AI_TYPE1_TARGET 0
#define AI_TYPE1_USER 1
#define AI_TYPE2_TARGET 2
#define AI_TYPE2_USER 3
#define AI_TYPE_MOVE 4

// AI Flags. Most run specific functions to update score, new flags are used for internal logic in other scripts
// B_VAR_WILD_AI_FLAGS can only use the first 16, up through (1 << 15)
// Please make sure flags are ordered with that in mind.
// See docs/ai_flags.md for more details.
#define AI_FLAG_CHECK_BAD_MOVE              (1 << 0)  // AI will avoid using moves that are likely to fail or be ineffective in the current situation.
#define AI_FLAG_TRY_TO_FAINT                (1 << 1)  // AI will prioritize KOing the player's mon if able.
#define AI_FLAG_CHECK_VIABILITY             (1 << 2)  // AI damaging moves and move effects to determine the best available move in the current situation.
#define AI_FLAG_OMNISCIENT                  (1 << 3)  // AI has full knowledge of player moves, abilities, hold items.
#define AI_FLAG_RISKY                       (1 << 4)  // AI will generally behave more recklessly, prioritizing damage over accuracy, explosions, etc.
#define AI_FLAG_CONSERVATIVE                (1 << 5)  // AI assumes all moves will low roll damage.
#define AI_FLAG_TRY_TO_2HKO                 (1 << 6)  // AI adds score bonus to any move the AI has that either OHKOs or 2HKOs the player.
#define AI_FLAG_HP_AWARE                    (1 << 7)  // AI will favour certain move effects based on how much remaining HP it and the player's mon have.
#define AI_FLAG_WILL_SUICIDE                (1 << 8)  // AI will use explosion / self destruct / final gambit / etc.
#define AI_FLAG_PREFER_STATUS_MOVES         (1 << 9)  // AI gets a score bonus for status moves. Should be combined with AI_FLAG_CHECK_BAD_MOVE to prevent using only status moves.
#define AI_FLAG_STALL                       (1 << 10)  // AI stalls battle and prefers secondary damage/trapping/etc. TODO not finished.
#define AI_FLAG_WEIGH_ABILITY_PREDICTION    (1 << 11)  // AI will predict player's ability based on aiRating
#define AI_FLAG_PREFER_HIGHEST_DAMAGE_MOVE  (1 << 12)  // AI adds score to highest damage move regardless of accuracy or secondary effect
#define AI_FLAG_PREDICT_SWITCH              (1 << 13)  // AI will predict the player's switches and switchins based on how it would handle the situation. Recommend using AI_FLAG_OMNISCIENT
#define AI_FLAG_PREDICT_INCOMING_MON        (1 << 14)  // AI will score against the predicting incoming mon if it predicts the player to switch. Requires AI_FLAG_PREDICT_SWITCH
#define AI_FLAG_NEGATE_UNAWARE              (1 << 15)  // AI is NOT aware of negating effects like wonder room, mold breaker, etc.
// Flags below this point cannot be used in B_VAR_WILD_AI_FLAGS
#define AI_FLAG_POWERFUL_STATUS             (1 << 16)  // AI prefers moves that set up field effects or side statuses, even if the user can faint the target.
#define AI_FLAG_FORCE_SETUP_FIRST_TURN      (1 << 17)  // AI will prioritize using setup moves on the first turn at the expensve of all else. AI_FLAG_CHECK_VIABILITY will instead do this when the AI determines it makes sense.
#define AI_FLAG_PREFER_BATON_PASS           (1 << 18)  // AI prefers raising its own stats and setting for / using Baton Pass.
// Flags for intelligent switching.
#define AI_FLAG_SMART_MON_CHOICES           (1 << 19)  // AI will make smarter decisions when choosing which mon to send out mid-battle and after a KO, which are separate decisions. Automatically included by AI_FLAG_SMART_SWITCHING.
#define AI_FLAG_SMART_SWITCHING             (1 << 20)  // AI includes a lot more switching checks. Automatically includes AI_FLAG_SMART_MON_CHOICES.
// Flags for cinematic switching.
#define AI_FLAG_SEQUENCE_SWITCHING          (1 << 21)  // AI switches in mons in exactly party order, and never switches mid-battle.
#define AI_FLAG_ACE_POKEMON                 (1 << 22)  // AI has an Ace Pokemon. The last Pokemon in the party will not be used until it's the last one remaining.
#define AI_FLAG_DOUBLE_ACE_POKEMON          (1 << 23)  // AI has *two* Ace Pokémon. The last two Pokémons in the party won't be used unless they're the last ones remaining. Goes well in battles where the trainer ID equals to twins, couples, etc.
#define AI_FLAG_DOUBLE_BATTLE               (1 << 24)  // Automatically set for double battles, handles AI behaviour with partner.

#define AI_FLAG_COUNT                       25

// The following options are enough to have a basic/smart trainer. Any other addtion could make the trainer worse/better depending on the flag
#define AI_FLAG_BASIC_TRAINER         (AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY)
#define AI_FLAG_SMART_TRAINER         (AI_FLAG_BASIC_TRAINER | AI_FLAG_OMNISCIENT | AI_FLAG_SMART_SWITCHING | AI_FLAG_SMART_MON_CHOICES | AI_FLAG_WEIGH_ABILITY_PREDICTION)
#define AI_FLAG_PREDICTION            (AI_FLAG_PREDICT_SWITCH | AI_FLAG_PREDICT_INCOMING_MON)

// 'other' ai logic flags
#define AI_FLAG_DYNAMIC_FUNC          (1 << 28)  // Create custom AI functions for specific battles via "setdynamicaifunc" cmd
#define AI_FLAG_ROAMING               (1 << 29)
#define AI_FLAG_SAFARI                (1 << 30)
#define AI_FLAG_FIRST_BATTLE          (1 << 31)

#define AI_SCORE_DEFAULT 100 // Default score for all AI moves.

#endif // GUARD_CONSTANTS_BATTLE_AI_H
