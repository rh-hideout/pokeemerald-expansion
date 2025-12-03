#ifndef GUARD_FOLLOWMON_H
#define GUARD_FOLLOWMON_H

#if OW_POKEMON_OBJECT_EVENTS == FALSE && OW_WILD_ENCOUNTERS_OVERWORLD == TRUE
#error "OW_POKEMON_OBJECT_EVENTS needs to be TRUE in order for OW_WILD_ENCOUNTERS_OVERWORLD to work."
#endif

#define FOLLOWMON_MAX_SPAWN_SLOTS   5

#define OWE_MAX_LAND_SPAWNS         3
#define OWE_MAX_WATER_SPAWNS        5
#define OWE_MAX_CAVE_SPAWNS         4

#define OWE_TIME_BETWEEN_SPAWNS     180 // Minimum wait time (in frames) between spawns.
#define OWE_SPAWN_TIME_VARIABILITY  60  // A random number of frames between 0 and this value will be added to OWE_TIME_BETWEEN_SPAWNS every reset for variability.
#define OWE_SPAWN_TIME_MINIMUM      60  // The minimum value the spawn wait time can be reset to. Prevents spawn attempts every frame.

#define INVALID_SPAWN_SLOT 0xFF

struct FollowMonData
{
    u16 spawnCountdown;
};

//data/scripts/followmon.inc
extern const u8 InteractWithDynamicWildFollowMon[];

void LoadFollowMonData(void);
void UpdateOverworldEncounters(void);
u32 GetOldestSlot(void);
void CreateOverworldWildEncounter(void);
bool32 OverworldEncounter_IsCollisionExempt(struct ObjectEvent* obstacle, struct ObjectEvent* collider);
void GeneratedOverworldWildEncounter_OnObjectEventSpawned(struct ObjectEvent *objectEvent);
void OverworldWildEncounter_OnObjectEventRemoved(struct ObjectEvent *objectEvent);
u32 GetFollowMonObjectEventGraphicsId(u32 spawnSlot, s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level);
void ClearOverworldEncounterData(void);
u8 CountActiveFollowMon();
void RemoveAllOverworldEncounterObjects(void);
bool32 IsOverworldWildEncounter(struct ObjectEvent *objectEvent);
bool32 IsGeneratedOverworldWildEncounter(struct ObjectEvent *objectEvent);
bool32 IsManualOverworldWildEncounter(struct ObjectEvent *objectEvent);
bool32 IsSemiManualOverworldWildEncounter(struct ObjectEvent *objectEvent);
u32 GetNewestOWEncounterLocalId(void);
bool32 ShouldRunOverworldEncounterScript(u32 objectEventId);
bool32 CanRemoveOverworldEncounter(u32 localId);
void RemoveOldestOverworldEncounter(u8 *objectEventId);
bool32 UNUSED TryAndRemoveOldestOverworldEncounter(u32 localId, u8 *objectEventId);
u16 GetGraphicsIdForOverworldEncounterGfx(struct ObjectEvent *objectEvent);

#endif // GUARD_FOLLOWMON_H