#ifndef GUARD_WILD_ENCOUNTER_H
#define GUARD_WILD_ENCOUNTER_H

#include "rtc.h"
#include "constants/wild_encounter.h"
#include "constants/wild_encounter_types.h"

#define HEADER_NONE 0xFFFF

struct WildPokemon
{
    u8 minLevel;
    u8 maxLevel;
    enum Species species;
};

struct WildPokemonInfo
{
    u8 encounterRate;
    const struct WildPokemon *wildPokemon;
};

struct WildPokemonHeader
{
    u8 mapGroup;
    u8 mapNum;
    const struct WildPokemonInfo *encounterTypes[TIMES_OF_DAY_COUNT][WILD_ENCOUNTER_TYPES_COUNT];
};

extern const u8 gEncounterTableSizes[WILD_ENCOUNTER_TYPES_COUNT];
extern const struct WildPokemonHeader gWildMonHeaders[];
extern const struct WildPokemonHeader gBattlePikeWildMonHeaders[];
extern const struct WildPokemonHeader gBattlePyramidWildMonHeaders[];
extern const struct WildPokemon gWildFeebas;
extern bool8 gIsFishingEncounter;
extern bool8 gIsSurfingEncounter;
extern u8 gChainFishingDexNavStreak;

u8 ChooseWildMonLevel(const struct WildPokemon *wildPokemon, u8 wildMonIndex, enum WildEncounterType encounterType);
u32 ChooseWildMonIndex(enum WildEncounterType encounterType);
bool32 StandardWildEncounter(u32 metatileBehavior, bool32 isForced);
bool32 SweetScentWildEncounter(void);
bool8 DoesCurrentMapHaveFishingMons(void);
void FishingWildEncounter(u8 rod);
u16 GetLocalWildMon(bool8 *isWaterMon);
u16 GetLocalWaterMon(void);
bool8 UpdateRepelCounter(void);
enum WildEncounterType GetStandardWildEncounterType(u32 metatileBehavior);
u32 GetMinLevelEncounter(void);
bool32 CheckForDoubleWildBattle(void);
bool8 StandardWildEncounter_Debug(void);
u32 CalculateChainFishingShinyRolls(void);
void CreateWildMon(enum Species species, u8 level);
void GenerateWildMon(const struct WildPokemonInfo *wildMonInfo, enum WildEncounterType encounterType, u32 minLevel, u32 slot);
bool8 AreLegendariesInSootopolisPreventingEncounters(void);
u16 GetCurrentMapWildMonHeaderId(void);
bool8 CheckFeebasAtCoords(s16 x, s16 y);
u32 ChooseWildMonIndex_Land(void);
u32 ChooseWildMonIndex_Water(void);
u32 ChooseWildMonIndex_Rocks(void);
u32 ChooseHiddenMonIndex(void);
bool32 MapHasNoEncounterData(void);
enum TimeOfDay GetTimeOfDayForEncounters(u32 headerId, enum WildEncounterType encounterType);
const struct WildPokemonInfo *GetWildPokemonInfo(enum WildEncounterType encounterType);

#endif // GUARD_WILD_ENCOUNTER_H
