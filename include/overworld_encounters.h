#ifndef GUARD_FOLLOWMON_H
#define GUARD_FOLLOWMON_H

#if OW_POKEMON_OBJECT_EVENTS == FALSE && OW_WILD_ENCOUNTERS_OVERWORLD == TRUE
#error "OW_POKEMON_OBJECT_EVENTS needs to be TRUE in order for OW_WILD_ENCOUNTERS_OVERWORLD to work."
#endif

#define FOLLOWMON_MAX_SPAWN_SLOTS           5
#define FOLLOWMON_IDEAL_OBJECT_EVENT_COUNT  8

#define INVALID_SPAWN_SLOT 0xFF

// Could be reduced to an u8 but I prefer to leave some potential for more advanced features
struct FollowMon
{
    u16 isShiny:1;
    u16 onWater:1;
    u16 timeOfDay:2;
    u16 age:4;
    u16 encounterIndex:8;
    u16 padding;
};

#define EMPTY_FOLLOWMON 0xFF;

struct FollowMonData
{
    bool8 pendingInteraction;
    u8 oldestSlot:4;
    u8 usedSlots:4;
    u16 spawnCountdown;
    u16 pendingSpawnAnim;
    struct FollowMon list[FOLLOWMON_MAX_SPAWN_SLOTS];
};

//data/scripts/followmon.inc
extern const u8 InteractWithDynamicWildFollowMon[];

void LoadFollowMonData(struct ObjectEvent *objectEvent);
void UpdateOverworldEncounters(void);
void CreateFollowMonEncounter(void);
bool8 FollowMon_ProcessMonInteraction(void);
bool32 OverworldEncounter_IsCollisionExempt(struct ObjectEvent* obstacle, struct ObjectEvent* collider);
void FollowMon_OnObjectEventSpawned(struct ObjectEvent *objectEvent);
void FollowMon_OnObjectEventRemoved(struct ObjectEvent *objectEvent);
u16 GetFollowMonObjectEventGraphicsId(u16 graphicsId);
void ClearOverworldEncounterData(void);
void RemoveOverworldEncounterObjects(void);
bool32 IsOverworldEncounterObjectEventInSpawnedMap(struct ObjectEvent *objectEvent, s16 x, s16 y);
bool32 IsGeneratedOverworldEncounter(struct ObjectEvent *objectEvent);

#endif // GUARD_FOLLOWMON_H