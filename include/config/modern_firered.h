#ifndef GUARD_CONFIG_MODERN_FIRERED_H
#define GUARD_CONFIG_MODERN_FIRERED_H

// Modern FireRed compile-time knobs. All MF_* configs live here — do not add
// Modern FireRed toggles to upstream include/config/*.h headers.
//
// Naming:
//   MF_*     — compile-time configs in this file
//   mf_*     — runtime sources (src/mf_*.c) and headers (include/mf_*.h)
//
// Master switches below gate whole unfinished subsystems. Player-facing options
// still resolve at runtime through the rules accessors (see ADR 0003); these
// are compile-out kills, not substitutes for save-backed rules.
// Override any switch at build time without wiping Makefile CPPFLAGS, e.g.:
//   make firered MF_CPPFLAGS='-DMF_RULES_ENGINE=0'

// Bump when this header's contract changes in a way callers must notice.
#define MF_VERSION 1

#ifndef MF_RULES_ENGINE
#define MF_RULES_ENGINE              TRUE    // Save-backed rules engine + start-of-run menu
#endif

#ifndef MF_RANDOMIZER
#define MF_RANDOMIZER                TRUE    // Seeded randomizer subsystem
#endif

#ifndef MF_NUZLOCKE
#define MF_NUZLOCKE                  TRUE    // Nuzlocke encounter / faint handling
#endif

// ME TX_NUZLOCKE_CEMETERY_ICON_GRAY — greyscale fainted cemetery mons in the PC.
#ifndef MF_NUZLOCKE_CEMETERY_ICON_GRAY
#define MF_NUZLOCKE_CEMETERY_ICON_GRAY TRUE
#endif

#ifndef MF_OPTIONS_PLUS
#define MF_OPTIONS_PLUS              TRUE    // Options+ QoL menu and settings
#endif

// ---------------------------------------------------------------------------
// S14 — Dev-facing new-game defaults (mirrors ME's TX_* block).
// Override at build time to ship a pre-chosen rules vector for testing, e.g.:
//   make firered MF_CPPFLAGS='-DMF_DEFAULT_GAMEMODE_PRESET=0'
// Values for MF_DEFAULT_GAMEMODE_PRESET match enum MfGamemodePreset
// (0 Classic / 1 Modern / 2 Custom). See ADR 0014.
// ---------------------------------------------------------------------------

#ifndef MF_DEFAULT_GAMEMODE_PRESET
#define MF_DEFAULT_GAMEMODE_PRESET          1       // Modern (Phase 1 feel without menu)
#endif

// --- Randomizer (ME TX_RANDOM_*) ---
#ifndef MF_TX_RANDOM_STARTER
#define MF_TX_RANDOM_STARTER                FALSE
#endif
#ifndef MF_TX_RANDOM_WILD
#define MF_TX_RANDOM_WILD                   FALSE
#endif
#ifndef MF_TX_RANDOM_TRAINER
#define MF_TX_RANDOM_TRAINER                FALSE
#endif
#ifndef MF_TX_RANDOM_STATIC
#define MF_TX_RANDOM_STATIC                 FALSE
#endif
#ifndef MF_TX_RANDOM_SIMILAR
#define MF_TX_RANDOM_SIMILAR                TRUE
#endif
#ifndef MF_TX_RANDOM_MAP_BASED
#define MF_TX_RANDOM_MAP_BASED              TRUE
#endif
#ifndef MF_TX_RANDOM_INCLUDE_LEGENDARIES
#define MF_TX_RANDOM_INCLUDE_LEGENDARIES    FALSE
#endif
#ifndef MF_TX_RANDOM_TYPE
#define MF_TX_RANDOM_TYPE                   FALSE
#endif
#ifndef MF_TX_RANDOM_MOVES
#define MF_TX_RANDOM_MOVES                  FALSE
#endif
#ifndef MF_TX_RANDOM_ABILITIES
#define MF_TX_RANDOM_ABILITIES              FALSE
#endif
#ifndef MF_TX_RANDOM_EVOLUTION
#define MF_TX_RANDOM_EVOLUTION              FALSE
#endif
#ifndef MF_TX_RANDOM_EVOLUTION_METHODS
#define MF_TX_RANDOM_EVOLUTION_METHODS      FALSE
#endif
#ifndef MF_TX_RANDOM_TYPE_EFFECTIVENESS
#define MF_TX_RANDOM_TYPE_EFFECTIVENESS     FALSE
#endif
#ifndef MF_TX_RANDOM_ITEMS
#define MF_TX_RANDOM_ITEMS                  FALSE
#endif
#ifndef MF_TX_RANDOM_CHAOS
#define MF_TX_RANDOM_CHAOS                  FALSE
#endif

// --- Nuzlocke (ME TX_NUZLOCKE_*) ---
#ifndef MF_TX_NUZLOCKE
#define MF_TX_NUZLOCKE                      FALSE
#endif
#ifndef MF_TX_NUZLOCKE_HARDCORE
#define MF_TX_NUZLOCKE_HARDCORE             FALSE
#endif
#ifndef MF_TX_NUZLOCKE_EASY
#define MF_TX_NUZLOCKE_EASY                 FALSE
#endif
#ifndef MF_TX_NUZLOCKE_SPECIES_CLAUSE
#define MF_TX_NUZLOCKE_SPECIES_CLAUSE       TRUE
#endif
#ifndef MF_TX_NUZLOCKE_SHINY_CLAUSE
#define MF_TX_NUZLOCKE_SHINY_CLAUSE         TRUE
#endif
#ifndef MF_TX_NUZLOCKE_NICKNAMING
#define MF_TX_NUZLOCKE_NICKNAMING           TRUE
#endif
#ifndef MF_TX_NUZLOCKE_DELETION
#define MF_TX_NUZLOCKE_DELETION             FALSE
#endif

// --- Difficulty (ME TX_DIFFICULTY_*) ---
#ifndef MF_TX_DIFFICULTY_PARTY_LIMIT
#define MF_TX_DIFFICULTY_PARTY_LIMIT        0
#endif
#ifndef MF_TX_DIFFICULTY_LEVEL_CAP
#define MF_TX_DIFFICULTY_LEVEL_CAP          0
#endif
#ifndef MF_TX_DIFFICULTY_EXP_MULTIPLIER
#define MF_TX_DIFFICULTY_EXP_MULTIPLIER     0
#endif
#ifndef MF_TX_DIFFICULTY_NO_ITEM_PLAYER
#define MF_TX_DIFFICULTY_NO_ITEM_PLAYER     FALSE
#endif
#ifndef MF_TX_DIFFICULTY_NO_ITEM_TRAINER
#define MF_TX_DIFFICULTY_NO_ITEM_TRAINER    FALSE
#endif
#ifndef MF_TX_DIFFICULTY_NO_EVS
#define MF_TX_DIFFICULTY_NO_EVS             FALSE
#endif
#ifndef MF_TX_DIFFICULTY_SCALING_IVS
#define MF_TX_DIFFICULTY_SCALING_IVS        0
#endif
#ifndef MF_TX_DIFFICULTY_SCALING_EVS
#define MF_TX_DIFFICULTY_SCALING_EVS        0
#endif
#ifndef MF_TX_DIFFICULTY_MAX_PARTY_IVS
#define MF_TX_DIFFICULTY_MAX_PARTY_IVS      0
#endif
#ifndef MF_TX_DIFFICULTY_POKECENTER
#define MF_TX_DIFFICULTY_POKECENTER         0       // 0 unlimited, 1 none
#endif
#ifndef MF_TX_DIFFICULTY_LOCK_DIFFICULTY
#define MF_TX_DIFFICULTY_LOCK_DIFFICULTY    FALSE
#endif
#ifndef MF_TX_DIFFICULTY_ESCAPE_ROPE_DIG
#define MF_TX_DIFFICULTY_ESCAPE_ROPE_DIG    FALSE
#endif
#ifndef MF_TX_DIFFICULTY_HARD_EXP
#define MF_TX_DIFFICULTY_HARD_EXP           FALSE
#endif
#ifndef MF_TX_DIFFICULTY_SCALED_EXP
#define MF_TX_DIFFICULTY_SCALED_EXP         FALSE
#endif
#ifndef MF_TX_DIFFICULTY_CATCH_RATE
#define MF_TX_DIFFICULTY_CATCH_RATE         0
#endif

// --- Challenges (ME TX_CHALLENGE_*) ---
#ifndef MF_TX_CHALLENGE_EVO_LIMIT
#define MF_TX_CHALLENGE_EVO_LIMIT           0
#endif
#ifndef MF_TX_CHALLENGE_BASE_STAT_EQUALIZER
#define MF_TX_CHALLENGE_BASE_STAT_EQUALIZER 0
#endif
#ifndef MF_TX_CHALLENGE_TYPE_OFF
#define MF_TX_CHALLENGE_TYPE_OFF            31
#endif
#ifndef MF_TX_CHALLENGE_TYPE
#define MF_TX_CHALLENGE_TYPE                MF_TX_CHALLENGE_TYPE_OFF
#endif
#ifndef MF_TX_CHALLENGE_MIRROR
#define MF_TX_CHALLENGE_MIRROR              FALSE
#endif
#ifndef MF_TX_CHALLENGE_MIRROR_THIEF
#define MF_TX_CHALLENGE_MIRROR_THIEF        FALSE
#endif
#ifndef MF_TX_CHALLENGE_NO_PC_HEAL
#define MF_TX_CHALLENGE_NO_PC_HEAL          FALSE
#endif
#ifndef MF_TX_CHALLENGE_LESS_ESCAPES
#define MF_TX_CHALLENGE_LESS_ESCAPES        FALSE
#endif
#ifndef MF_TX_CHALLENGE_EXPENSIVE_SHOPS
#define MF_TX_CHALLENGE_EXPENSIVE_SHOPS     0
#endif

// --- Features (ME TX_FEATURES_*) ---
#ifndef MF_TX_FEATURES_SHINY_CHANCE
#define MF_TX_FEATURES_SHINY_CHANCE         0
#endif
#ifndef MF_TX_FEATURES_ITEM_DROP
#define MF_TX_FEATURES_ITEM_DROP            FALSE
#endif
#ifndef MF_TX_FEATURES_EASIER_FEEBAS
#define MF_TX_FEATURES_EASIER_FEEBAS        FALSE
#endif
#ifndef MF_TX_FEATURES_RTC_TYPE
#define MF_TX_FEATURES_RTC_TYPE             FALSE
#endif
#ifndef MF_TX_FEATURES_SHINY_COLORS
#define MF_TX_FEATURES_SHINY_COLORS         FALSE
#endif
#ifndef MF_TX_FEATURES_WONDER_TRADE
#define MF_TX_FEATURES_WONDER_TRADE         FALSE
#endif
#ifndef MF_TX_FEATURES_UNLIMITED_WT
#define MF_TX_FEATURES_UNLIMITED_WT         FALSE
#endif
#ifndef MF_TX_FEATURES_FRONTIER_BANS
#define MF_TX_FEATURES_FRONTIER_BANS        FALSE
#endif

// --- Gamemode (ME TX_MODE_*) — seed for Custom; Classic/Modern overwrite ---
#ifndef MF_TX_MODE_ALTERNATE_SPAWNS
#define MF_TX_MODE_ALTERNATE_SPAWNS         0
#endif
#ifndef MF_TX_MODE_INFINITE_TMS
#define MF_TX_MODE_INFINITE_TMS             FALSE
#endif
#ifndef MF_TX_MODE_SURVIVE_POISON
#define MF_TX_MODE_SURVIVE_POISON           FALSE
#endif
#ifndef MF_TX_MODE_SYNCHRONIZE
#define MF_TX_MODE_SYNCHRONIZE              FALSE
#endif
#ifndef MF_TX_MODE_MINTS
#define MF_TX_MODE_MINTS                    FALSE
#endif
#ifndef MF_TX_MODE_NEW_CITRUS
#define MF_TX_MODE_NEW_CITRUS               FALSE
#endif
#ifndef MF_TX_MODE_MODERN_TYPES
#define MF_TX_MODE_MODERN_TYPES             FALSE
#endif
#ifndef MF_TX_MODE_FAIRY_TYPES
#define MF_TX_MODE_FAIRY_TYPES              FALSE
#endif
#ifndef MF_TX_MODE_NEW_STATS
#define MF_TX_MODE_NEW_STATS                FALSE
#endif
#ifndef MF_TX_MODE_STURDY
#define MF_TX_MODE_STURDY                   FALSE
#endif
#ifndef MF_TX_MODE_MODERN_MOVES
#define MF_TX_MODE_MODERN_MOVES             FALSE
#endif
#ifndef MF_TX_MODE_LEGENDARY_ABILITIES
#define MF_TX_MODE_LEGENDARY_ABILITIES      FALSE
#endif
#ifndef MF_TX_MODE_NEW_LEGENDARIES
#define MF_TX_MODE_NEW_LEGENDARIES          FALSE
#endif
#ifndef MF_TX_MODE_TYPE_EFFECTIVENESS
#define MF_TX_MODE_TYPE_EFFECTIVENESS       FALSE
#endif

#endif // GUARD_CONFIG_MODERN_FIRERED_H
