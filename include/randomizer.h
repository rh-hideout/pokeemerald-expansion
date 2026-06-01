#ifndef GUARD_RANDOMIZER_H
#define GUARD_RANDOMIZER_H

#include "global.h"
#include "data.h"
#include "random.h"
#include "script.h"
#include "wild_encounter.h"
#include "config/randomizer.h"

#define RANDOMIZER_MAX_MON  (SPECIES_EGG-1)
#define RANDOMIZER_SPECIES_COUNT (RANDOMIZER_MAX_MON+1)

#define RANDOMIZER_STREAM 17

enum RandomizerReason
{
    RANDOMIZER_REASON_WILD_ENCOUNTER,
    RANDOMIZER_REASON_FIXED_ENCOUNTER,
    RANDOMIZER_REASON_TRAINER_PARTY,
    RANDOMIZER_REASON_BASE_STATS,
    RANDOMIZER_REASON_SPECIES_TYPE,
    RANDOMIZER_REASON_LEARNSET,
    RANDOMIZER_REASON_FIELD_ITEM,
    RANDOMIZER_REASON_STARTER,
    RANDOMIZER_REASON_ABILITY,
};

enum RandomizerSpeciesMode {
    // Any valid species can be randomized to any other valid species.
    MON_RANDOM,
    MON_RANDOM_LEGEND_AWARE,
    MON_RANDOM_BST,
    MON_EVOLUTION,
    // Other modes here.

    // A dummy mode to end the list.
    MAX_MON_MODE
};

// This object can be passed to IsRandomizationPossible to speed up queries.
struct RandomizerGroupSet {
    u16 species;
    u16 minGroup;
    u16 maxGroup;
};


u16 RandomizeFoundItem(u16 itemId, u8 mapNum, u8 mapGroup, u8 localId);
void FindItemRandomize_NativeCall(struct ScriptContext *ctx);
void FindHiddenItemRandomize_NativeCall(struct ScriptContext *ctx);

u16 RandomizeWildEncounter(u16 species, u8 mapNum, u8 mapGroup, enum WildPokemonArea area, u8 slot);

u16 RandomizeFixedEncounterMon(u16 species, u8 mapNum, u8 mapGroup, u8 localId);

// Given a starter slot and the list of original starters, returns the starter in that slot.
u16 RandomizeStarter(u16 starterSlot, const u16* originalStarters);

// Once the randomizer is set up, in RAM mode, you can call this to preload the tables.
// This avoids a short hitch the first time the randomizer is used.
// It's also a good idea to call this function if the randomizer mode changes.
void PreloadRandomizationTables(void);

// Checks if a trainer should be randomized or not
u16 RandomizeMon(enum RandomizerReason reason, enum RandomizerSpeciesMode mode, u32 seed, u16 species);
u16 RandomizeMove(u16 species, u16 move, u16 level);
struct TrainerMon RandomizeTrainerMon(const struct Trainer* trainer, u8 monsCount, u8 slot, u16 baseSeed);
u16 RandomizeAbility(u16 species, u16 ability);

#endif // GUARD_RANDOMIZER_H 