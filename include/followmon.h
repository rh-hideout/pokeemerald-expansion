#ifndef GUARD_FOLLOWMON_H
#define GUARD_FOLLOWMON_H

#define OW_FLAG_SPAWN_OVERWORLD_MON         FLAG_UNUSED_0x020

#define FOLLOWMON_SHINY_OFFSET              10000
#define FOLLOWMON_MAX_SPAWN_SLOTS           5
#define FOLLOWMON_IDEAL_OBJECT_EVENT_COUNT  8

#define INVALID_SPAWN_SLOT 0xFF

// Could be reduced to an u8 but I prefer to leave some potential for more advanced features
struct FollowMon
{
    u16 isShiny:1;
    u16 onWater:1;
    u16 timeOfDay:2;
    u16 unused:4;
    u16 encounterIndex:8;
    
};

#define EMPTY_FOLLOWMON 0xFF;

struct FollowMonData
{
    bool8 pendingInterction;
    u8 activeCount;
    //u8 encounterChainCount;
    u16 spawnCountdown;
    u16 spawnSlot;
    u16 pendingSpawnAnim;
    //u16 encounterChainSpecies;
    //u16 cachedPartnerMonGfx;
    struct FollowMon list[FOLLOWMON_MAX_SPAWN_SLOTS];
};

//data/scripts/followmon.inc
extern const u8 InteractWithDynamicWildFollowMon[];

void FollowMon_OverworldCB();
void CreateFollowMonEncounter(void);
bool8 FollowMon_ProcessMonInteraction(void);
bool8 FollowMon_IsCollisionExempt(struct ObjectEvent* obstacle, struct ObjectEvent* collider);
bool8 FollowMon_IsMonObject(struct ObjectEvent* object);
void FollowMon_OnObjectEventSpawned(struct ObjectEvent *objectEvent);
void FollowMon_OnObjectEventRemoved(struct ObjectEvent *objectEvent);
u16 GetFollowMonObjectEventGraphicsId(u16 graphicsId);
void FollowMon_OnWarp(void);
void RemoveAllFollowMonObjects(void);

#endif // GUARD_FOLLOWMON_H