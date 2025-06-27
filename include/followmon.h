#ifndef GUARD_FOLLOWMON_H
#define GUARD_FOLLOWMON_H

#define FOLLOWMON_SHINY_OFFSET              10000
#define FOLLOWMON_MAX_SPAWN_SLOTS           6 // 4 reserved palette slots, 1 for the 10th pal slot (if not in use) and 1 for the follower (todo change to 6)
#define FOLLOWMON_IDEAL_OBJECT_EVENT_COUNT  8

#define INVALID_SPAWN_SLOT 0xFF

struct FollowMon
{
    u32 personality;
    u16 species;
    u16 level;
};

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

enum FollowMonSpawnAnim
{
    FOLLOWMON_SPAWN_ANIM_SHINY,
    FOLLOWMON_SPAWN_ANIM_WATER,
    FOLLOWMON_SPAWN_ANIM_CAVE,
    FOLLOWMON_SPAWN_ANIM_GRASS,
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

#endif // GUARD_FOLLOWMON_H