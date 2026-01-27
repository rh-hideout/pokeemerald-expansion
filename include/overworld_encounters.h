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

#define OWE_SPAWN_TIME_MINIMUM      30  // The minimum value the spawn wait time can be reset to. Prevents spawn attempts every frame.
#define OWE_SPAWN_TIME_PER_ACTIVE   30  // The number of frames that will be added to the countdown per currently active spawn.
#define OWE_SPAWN_TIME_REPLACEMENT  240 // The number of frames before an existing spawn will be replaced with a new one (requires OW_WILD_ENCOUNTERS_SPAWN_REPLACEMENT).

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

#define OWE_SAVED_MOVEMENT_STATE        0x80
#define OWE_NO_REPLACE_FLAG         0x80

#define OWE_RESTORED_MOVEMENT_FUNC_ID   10

enum OverworldEncounterSpawnAnim
{
    OWE_SPAWN_ANIM_GRASS,
    OWE_SPAWN_ANIM_LONG_GRASS,
    OWE_SPAWN_ANIM_WATER,
    OWE_SPAWN_ANIM_UNDERWATER,
    OWE_SPAWN_ANIM_CAVE,
    OWE_SPAWN_ANIM_SHINY,
};

enum OverworldObjectEncounterType
{
    OWE_ANY,
    OWE_GENERATED,
    OWE_MANUAL
};

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

enum __attribute__((packed)) OverworldEncounterBehaviors
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
u32 GetOldestSlot(bool32 forceRemove);
void CreateOverworldWildEncounter(void);
void OverworldWildEncounter_OnObjectEventSpawned(struct ObjectEvent *objectEvent);
void OverworldWildEncounter_OnObjectEventRemoved(struct ObjectEvent *objectEvent);
u32 GetOverworldEncounterObjectEventGraphicsId(s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level, u32 *roamerIndex);
void OverworldWildEncounter_SetMinimumSpawnTimer(void);
void RemoveAllGeneratedOverworldEncounterObjects(void);
bool32 IsOverworldWildEncounter(struct ObjectEvent *objectEvent, enum OverworldObjectEncounterType oweType);
u32 GetNewestOWEncounterLocalId(void);
bool32 ShouldRunOverworldEncounterScript(u32 objectEventId);
bool32 CanRemoveOverworldEncounter(u32 localId);
u32 RemoveOldestGeneratedOverworldEncounter(void);
bool32 OWE_TryAndRemoveOldestGeneratedOverworldEncounter_Object(u32 localId, u8 *objectEventId);
void OWE_TryAndRemoveOldestGeneratedOverworldEncounter_Palette(void);
const struct ObjectEventTemplate TryGetObjectEventTemplateForOverworldEncounter(const struct ObjectEventTemplate *template);
void OWE_TryTriggerEncounter(struct ObjectEvent *obstacle, struct ObjectEvent *collider);
void OverworldWildEncounter_RemoveObjectOnBattle(void);
bool32 OWE_CheckRestrictedMovement(struct ObjectEvent *objectEvent, enum Direction direction);
bool32 OWE_CanAwareMonSeePlayer(struct ObjectEvent *mon);
bool32 OWE_IsPlayerInsideMonActiveDistance(struct ObjectEvent *mon);
u32 OWE_DirectionToPlayerFromCollision(struct ObjectEvent *mon);
bool32 OWE_IsMonNextToPlayer(struct ObjectEvent *mon);
u32 OWE_GetApproachingMonDistanceToPlayer(struct ObjectEvent *mon, bool32 *equalDistances);
void Task_OWE_WaitMovements(u8 taskId);
enum OverworldEncounterSpawnAnim OWE_GetSpawnDespawnAnimType(u32 metatileBehavior);
bool32 OverworldWildEncounter_ShouldDisableRandomEncounters(void);
bool32 OWE_DespawnMonDueToNPCCollision(struct ObjectEvent *curObject, struct ObjectEvent *objectEvent);
u32 OWE_DespawnMonDueToTrainerSight(u32 collision, s16 x, s16 y);
struct SpritePalette OWE_GetSpawnAnimFldEffPalette(enum OverworldEncounterSpawnAnim spawnAnim);
void OWE_RestoreBehaviorState(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void OWE_SetSavedMovementState(struct ObjectEvent *objectEvent);
void OWE_ClearSavedMovementState(struct ObjectEvent *objectEvent);
u32 OWE_GetWalkMovementActionInDirectionWithSpeed(enum Direction direction, u32 speed);

#endif // GUARD_OVERWORLD_ENCOUNTERS_H