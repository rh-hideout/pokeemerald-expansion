#ifndef GUARD_RANDOMIZER_H
#define GUARD_RANDOMIZER_H

#include "config/randomizer.h"
#if RANDOMIZER_AVAILABLE

#define RANDOMIZER_MAX_MON  (SPECIES_EGG-1)
#define RANDOMIZER_SPECIES_COUNT (RANDOMIZER_MAX_MON+1)

#include "global.h"
#include "random.h"
#include "script.h"
#include "wild_encounter.h"

#define RANDOMIZER_STREAM 17
#define STARTER_AND_GIFT_MON_COUNT 11
#define EGG_MON_COUNT 2

extern const u16 gStarterAndGiftMonTable[];
extern const u16 gEggMonTable[];

enum RandomizerFeature
{
    RANDOMIZE_WILD_MON,
    RANDOMIZE_TRAINER_MON,
    RANDOMIZE_FIELD_ITEMS,
    RANDOMIZE_BASE_STATS,
    RANDOMIZE_MON_TYPES,
    RANDOMIZE_LEARNSET,
    RANDOMIZE_FIXED_MON,
    RANDOMIZE_STARTER_AND_GIFT_MON,
    RANDOMIZE_EGG_MON,
    RANDOMIZE_ABILITIES,
};

enum RandomizerReason
{
    RANDOMIZER_REASON_WILD_ENCOUNTER,
    RANDOMIZER_REASON_FIXED_ENCOUNTER,
    RANDOMIZER_REASON_TRAINER_PARTY,
    RANDOMIZER_REASON_BASE_STATS,
    RANDOMIZER_REASON_SPECIES_TYPE,
    RANDOMIZER_REASON_LEARNSET,
    RANDOMIZER_REASON_FIELD_ITEM,
    RANDOMIZER_REASON_STARTER_AND_GIFT_MON,
    RANDOMIZER_REASON_EGG,
    RANDOMIZER_REASON_ABILITIES,
};

enum RandomizerOption {
    RANDOMIZER_OPTION_SPECIES_MODE,
};

enum RandomizerSpeciesMode {
    MON_RANDOM,
    MON_RANDOM_LEGEND_AWARE,
    MON_RANDOM_BST,
    MON_EVOLUTION,
    MAX_MON_MODE
};

struct RandomizerGroupSet {
    u16 species;
    u16 minGroup;
    u16 maxGroup;
};


u32 GetRandomizerSeed(void);
bool32 RandomizerFeatureEnabled(enum RandomizerFeature feature);
u16 GetRandomizerOption(enum RandomizerOption option);

struct Sfc32State RandomizerRandSeed(enum RandomizerReason reason, u32 data1, u32 data2);

static inline u16 RandomizerNext(struct Sfc32State* state)
{
    return _SFC32_Next_Stream(state, RANDOMIZER_STREAM) >> 16;
}
u32 RandomizerNextRange(struct Sfc32State* state, u32 range);

u16 RandomizerRand(enum RandomizerReason reason, u32 data1, u32 data2);
u16 RandomizerRandRange(enum RandomizerReason reason, u32 data1, u32 data2, u16 range);

static inline u8 RandomizeMonType(u16 species, u8 typeNum)
{
    u8 type;
    struct Sfc32State state = RandomizerRandSeed(RANDOMIZER_REASON_SPECIES_TYPE, species, typeNum);
    do {
        type = (u8)RandomizerNextRange(&state, NUMBER_OF_MON_TYPES);
    } while (type == TYPE_MYSTERY);
    return type;
}

u16 RandomizeFoundItem(u16 itemId, u8 mapNum, u8 mapGroup, u8 localId);
void FindItemRandomize_NativeCall(struct ScriptContext *ctx);
void FindHiddenItemRandomize_NativeCall(struct ScriptContext *ctx);

u16 RandomizeMon(enum RandomizerReason reason, enum RandomizerSpeciesMode mode, u32 seed, u16 species);
u16 RandomizeMonBaseForm(enum RandomizerReason reason, enum RandomizerSpeciesMode mode, u32 seed, u16 species);

u16 RandomizeWildEncounter(u16 species, u8 mapNum, u8 mapGroup, enum WildPokemonArea area, u8 slot);

bool32 IsRandomizationPossible(u16 tableSpecies, u16 matchSpecies);

u16 RandomizeTrainerMon(u16 trainerId, u8 slot, u8 totalMons, u16 species);

u16 RandomizeFixedEncounterMon(u16 species, u8 mapNum, u8 mapGroup, u8 localId);

u16 RandomizeStarterAndGiftMon(u16 originalSlot, const u16* originalStarterAndGiftMons);

u16 RandomizeEggMon(u16 originalSlot, const u16* originalEggMons);

u16 RandomizeAbility(u16 species, u8 abilityNum, u16 originalAbility);

static inline bool32 GroupSetsIntersect(struct RandomizerGroupSet* originalCache, struct RandomizerGroupSet* targetCache)
{
    return originalCache->maxGroup >= targetCache->minGroup
        && originalCache->minGroup <= targetCache->maxGroup;
}

#if RANDOMIZER_DYNAMIC_SPECIES
void PreloadRandomizationTables(void);
#endif

#endif // RANDOMIZER_AVAILABLE

#endif // GUARD_RANDOMIZER_H
