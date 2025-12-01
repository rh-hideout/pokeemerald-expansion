#ifndef GUARD_FOLLOWMON_H
#define GUARD_FOLLOWMON_H

#if OW_POKEMON_OBJECT_EVENTS == FALSE && OW_WILD_ENCOUNTERS_OVERWORLD == TRUE
#error "OW_POKEMON_OBJECT_EVENTS needs to be TRUE in order for OW_WILD_ENCOUNTERS_OVERWORLD to work."
#endif

#define FOLLOWMON_MAX_SPAWN_SLOTS   5

#define OWE_MAX_LAND_SPAWNS         3
#define OWE_MAX_WATER_SPAWNS        5
#define OWE_MAX_CAVE_SPAWNS         4

#define INVALID_SPAWN_SLOT 0xFF

struct FollowMon
{
    u16 level:7;
    u16 form:3;
    u16 age:4;
    u16 padding:12;
    u16 padding2;
};

struct FollowMonData
{
    struct FollowMon list[FOLLOWMON_MAX_SPAWN_SLOTS];
    u16 spawnCountdown;
    u8 pendingSpawnAnim;
};

//data/scripts/followmon.inc
extern const u8 InteractWithDynamicWildFollowMon[];

void LoadFollowMonData(void);
void UpdateOverworldEncounters(void);
u32 GetOldestSlot(void);
void CreateFollowMonEncounter(void);
bool32 OverworldEncounter_IsCollisionExempt(struct ObjectEvent* obstacle, struct ObjectEvent* collider);
void GeneratedOverworldWildEncounter_OnObjectEventSpawned(struct ObjectEvent *objectEvent);
void GeneratedOverworldWildEncounter_OnObjectEventRemoved(struct ObjectEvent *objectEvent);
u32 GetFollowMonObjectEventGraphicsId(u32 spawnSlot, s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale);
void ClearOverworldEncounterData(void);
u8 CountActiveFollowMon();
void RemoveAllOverworldEncounterObjects(void);
bool32 IsOverworldEncounterObjectEventInSpawnedMap(struct ObjectEvent *objectEvent, s16 x, s16 y);
bool32 IsOverworldWildEncounter(struct ObjectEvent *objectEvent);
bool32 IsGeneratedOverworldWildEncounter(struct ObjectEvent *objectEvent);
u32 GetNewestOWEncounterLocalId(void);
bool32 TryAndRemoveOldestOverworldEncounter(u32 localId, u8 *objectEventId);

#endif // GUARD_FOLLOWMON_H