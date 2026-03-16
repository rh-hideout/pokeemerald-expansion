#ifndef GUARD_WILD_ENCOUNTER_H
#define GUARD_WILD_ENCOUNTER_H

#include "constants/wild_encounter.h"
#include "rtc.h"

#define HEADER_NONE 0xFFFF

enum WildPokemonArea {
    WILD_AREA_LAND,
    WILD_AREA_WATER,
    WILD_AREA_ROCKS,
    WILD_AREA_FISHING_START,
    WILD_AREA_FISHING_OLD_ROD = WILD_AREA_FISHING_START + OLD_ROD,
    WILD_AREA_FISHING_GOOD_ROD = WILD_AREA_FISHING_START + GOOD_ROD,
    WILD_AREA_FISHING_SUPER_ROD = WILD_AREA_FISHING_START + SUPER_ROD,
    WILD_AREA_HIDDEN
};

struct PACKED ALIGNED(2) WildPokemon
{
    u8 minLevel;
    u8 maxLevel;
    u16 species;
    u16 weight;
};

struct WildPokemonInfo
{
    u8 encounterRate;
    u8 numSlots;
    u16 totalWeight;
    const struct WildPokemon wildPokemon[];
};

struct WildEncounterTypes
{
    const struct WildPokemonInfo *landMonsInfo;
    const struct WildPokemonInfo *waterMonsInfo;
    const struct WildPokemonInfo *rockSmashMonsInfo;
    const struct WildPokemonInfo *fishingMonsOldRodInfo;
    const struct WildPokemonInfo *fishingMonsGoodRodInfo;
    const struct WildPokemonInfo *fishingMonsSuperRodInfo;
    const struct WildPokemonInfo *hiddenMonsInfo;
};

struct WildPokemonHeader
{
    u8 mapGroup;
    u8 mapNum;
    const struct WildEncounterTypes encounterTypes[TIMES_OF_DAY_COUNT];
};

extern const struct WildPokemonHeader gWildMonHeaders[];
extern bool8 gIsFishingEncounter;
extern bool8 gIsSurfingEncounter;
extern u8 gChainFishingDexNavStreak;

void DisableWildEncounters(bool8 disabled);
bool8 StandardWildEncounter(u16 curMetatileBehavior, u16 prevMetatileBehavior);
bool8 SweetScentWildEncounter(void);
bool8 DoesCurrentMapHaveFishingMons(enum FishingRod rod);
void FishingWildEncounter(enum FishingRod rod);
u16 GetLocalWildMon(bool8 *isWaterMon);
u16 GetLocalWaterMon(void);
bool8 UpdateRepelCounter(void);
bool8 TryDoDoubleWildBattle(void);
bool8 StandardWildEncounter_Debug(void);
u32 CalculateChainFishingShinyRolls(void);
void CreateWildMon(u16 species, u8 level);
u16 GetCurrentMapWildMonHeaderId(void);
u32 ChooseWildMonIndex(const struct WildPokemonInfo *encounterTable);
bool32 MapHasNoEncounterData(void);
enum TimeOfDay GetTimeOfDayForEncounters(u32 headerId, enum WildPokemonArea area);

#endif // GUARD_WILD_ENCOUNTER_H
