#ifndef GUARD_OVERWORLD_ENCOUNTERS_H
#define GUARD_OVERWORLD_ENCOUNTERS_H

#if OW_POKEMON_OBJECT_EVENTS == FALSE && OW_WILD_ENCOUNTERS_OVERWORLD == TRUE
#error "OW_POKEMON_OBJECT_EVENTS needs to be TRUE in order for OW_WILD_ENCOUNTERS_OVERWORLD to work."
#endif

#define OWE_MAX_SPAWN_SLOTS   5

#define OWE_MAX_LAND_SPAWNS         3
#define OWE_MAX_WATER_SPAWNS        5
#define OWE_MAX_CAVE_SPAWNS         4

#define OWE_SPAWN_DISTANCE_LAND     1   // A spawn cannot happen within this many tiles of the player position.
#define OWE_SPAWN_DISTANCE_WATER    3   // A spawn cannot happen within this many tiles of the player position (while surfing).

#define OWE_TOTAL_SPAWN_WIDTH       15  // Width of the on-screen spawn area in tiles.
#define OWE_TOTAL_SPAWN_HEIGHT      9   // Height of the on-screen spawn area in tiles.
#define OWE_SPAWN_RADUIS_WIDTH      (OWE_TOTAL_SPAWN_WIDTH - 1) / 2     // Distance from center to left/right edge (not including center).
#define OWE_SPAWN_RADUIS_HEIGHT     (OWE_TOTAL_SPAWN_HEIGHT - 1) / 2    // Distance from center to top/bottom edge (not including center).

#define OWE_TIME_BETWEEN_SPAWNS     180 // Minimum wait time (in frames) between spawns.
#define OWE_SPAWN_TIME_VARIABILITY  60  // A random number of frames between 0 and this value will be added to OWE_TIME_BETWEEN_SPAWNS every reset for variability.
#define OWE_SPAWN_TIME_MINIMUM      60  // The minimum value the spawn wait time can be reset to. Prevents spawn attempts every frame.

#define OWE_MON_SIGHT_WIDTH         3
#define OWE_MON_SIGHT_LENGTH        4

#define OWE_CHASE_RANGE             5
#define OWE_APPROACH_DISTANCE       2

#define OWE_APPROACH_JUMP_TIMER_MIN 16
#define OWE_APPROACH_JUMP_TIMER_MAX 64

#define OWE_FLEE_COLLISION_TIME     6  // If a fleeing mon is unable to take a step for this many tries it will despawn. (Multiply this value by 16 to get number of frames.)

#define OWE_DESPAWN_FRAMES          30  // Number of frames before a mon despawns after noticing the player (OWE_BEHAVIOR_DESPAWN)

#define OWE_NO_ENCOUNTER_SET        255

#define INVALID_SPAWN_SLOT          0xFF

#define OWE_FLAG_START_ENCOUNTER    0x80

enum OverworldEncounterSpawnAnim
{
    OWE_SPAWN_ANIM_GRASS,
    OWE_SPAWN_ANIM_WATER,
    OWE_SPAWN_ANIM_CAVE,
    OWE_SPAWN_ANIM_SHINY,
};

/*
Combine OWE Type Checks into one function using these.
Need to figure a clean way to adjust SemiManual check as takes template.
enum OverworldObjectEncounterType
{
    OWE_NONE,
    OWE_GENERATED,
    OWE_SEMI_MANUAL,
    OWE_MANUAL,
};
*/

// OWE_SPEED_FASTER seems to visually bug out sometimes.
enum OWESpeeds
{
    OWE_SPEED_NORMAL,
    OWE_SPEED_SLOW,
    OWE_SPEED_FAST,
    OWE_SPEED_FASTER
};

struct OWESpeciesBehavior
{
    u32 movementType:8;
    u32 viewDistance:4;
    u32 viewWidth:4;
    u32 activeDistance:4;
    u32 padding:12;
    enum OWESpeeds idleSpeed;
    enum OWESpeeds activeSpeed;
};

enum OverworldEncounterBehaviors
{
    OWE_IGNORE_PLAYER,
    OWE_CHASE_PLAYER_SLOW,
    OWE_FLEE_PLAYER_NORMAL,
    OWE_WATCH_PLAYER_NORMAL,
    OWE_APPROACH_PLAYER_SLOW,
    OWE_DESPAWN_ON_NOTICE,
    OWE_SPECIES_BEHAVIOR_COUNT
};

extern const u8 InteractWithDynamicWildOverworldEncounter[];

void OWE_ResetSpawnCounterPlayAmbientCry(void);
void UpdateOverworldEncounters(void);
u32 GetOldestSlot(void);
void CreateOverworldWildEncounter(void);
void OverworldWildEncounter_OnObjectEventSpawned(struct ObjectEvent *objectEvent);
void OverworldWildEncounter_OnObjectEventRemoved(struct ObjectEvent *objectEvent);
u32 GetOverworldEncounterObjectEventGraphicsId(s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level, u32 *roamerIndex);
void OverworldWildEncounter_SetMinimumSpawnTimer(void);
void RemoveAllGeneratedOverworldEncounterObjects(void);
bool32 IsOverworldWildEncounter(struct ObjectEvent *objectEvent);
bool32 IsGeneratedOverworldWildEncounter(struct ObjectEvent *objectEvent);
bool32 IsManualOverworldWildEncounter(struct ObjectEvent *objectEvent);
bool32 IsSemiManualOverworldWildEncounter(u32 graphicsId, u32 trainerType);
u32 GetNewestOWEncounterLocalId(void);
bool32 ShouldRunOverworldEncounterScript(u32 objectEventId);
bool32 CanRemoveOverworldEncounter(u32 localId);
u32 RemoveOldestOverworldEncounter(void);
void OWE_DoSpawnDespawnAnim(struct ObjectEvent *objectEvent, bool32 spawn);
bool32 TryAndRemoveOldestOverworldEncounter(u32 localId, u8 *objectEventId);
struct ObjectEventTemplate TryGetObjectEventTemplateForOverworldEncounter(const struct ObjectEventTemplate *template);
void OWE_TryTriggerEncounter(struct ObjectEvent *obstacle, struct ObjectEvent *collider);
void TryRemoveOverworldWildEncounter(u32 localId);
bool32 OWE_CheckRestrictedMovement(struct ObjectEvent *objectEvent, u32 direction);
void DespawnOldestOWE_Pal(void);
bool32 OWE_CanMonSeePlayer(struct ObjectEvent *mon);
bool32 OWE_IsPlayerInsideMonActiveDistance(struct ObjectEvent *mon);
u32 OWE_DirectionToPlayerFromCollision(struct ObjectEvent *mon);
bool32 OWE_IsMonNextToPlayer(struct ObjectEvent *mon);
u32 OWE_GetApproachingMonDistanceToPlayer(struct ObjectEvent *mon, bool32 *equalDistances);
void Task_OWE_WaitMovements(u8 taskId);
enum OverworldEncounterSpawnAnim OWE_GetSpawnDespawnAnimType(u32 metatileBehavior);
void OverworldWildEncounter_InitRoamerOutbreakStatus(struct ObjectEvent *objectEvent, const struct ObjectEventTemplate *template);
void OverworldWildEncounter_FreezeAllObjects(void);

#endif // GUARD_OVERWORLD_ENCOUNTERS_H