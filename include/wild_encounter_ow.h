#ifndef GUARD_WILD_ENCOUNTER_OW_H
#define GUARD_WILD_ENCOUNTER_OW_H

#define OWE_APPROACH_DISTANCE           2
#define OWE_APPROACH_JUMP_TIMER_MIN     16
#define OWE_APPROACH_JUMP_TIMER_MAX     64
#define OWE_FLEE_COLLISION_TIME         6   // If a fleeing mon is unable to take a step for this many tries it will despawn. (Multiply this value by 16 to get number of frames.)
#define OWE_DESPAWN_FRAMES              30  // Number of frames before a mon despawns after noticing the player (OWE_BEHAVIOR_DESPAWN)

enum OverworldEncounterSpawnAnim
{
    OWE_SPAWN_ANIM_GRASS,
    OWE_SPAWN_ANIM_LONG_GRASS,
    OWE_SPAWN_ANIM_WATER,
    OWE_SPAWN_ANIM_UNDERWATER,
    OWE_SPAWN_ANIM_CAVE,
    OWE_SPAWN_ANIM_SHINY
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

void OverworldWildEncounters_CB(void);
void GenerateOverworldWildEncounter(void);
void OverworldWildEncounter_SetInstantSpawnTimer(void);
void OverworldWildEncounter_SetMinimumSpawnTimer(void);
bool32 IsOverworldWildEncounter(struct ObjectEvent *objectEvent, enum OverworldObjectEncounterType oweType);
void OWE_TryTriggerEncounter(struct ObjectEvent *obstacle, struct ObjectEvent *collider);
bool32 ShouldRunOverworldEncounterScript(u32 objectEventId);
void OverworldWildEncounter_OnObjectEventSpawned(struct ObjectEvent *objectEvent);
void OverworldWildEncounter_OnObjectEventDespawned(struct ObjectEvent *objectEvent);
bool32 OWE_DespawnMonDueToNPCCollision(struct ObjectEvent *curObject, struct ObjectEvent *objectEvent);
u32 OWE_DespawnMonDueToTrainerSight(u32 collision, s16 x, s16 y);
bool32 OWE_IsDespawnExempt(struct ObjectEvent *objectEvent);
void DespwnAllOverworldWildEncounterObjects(enum OverworldObjectEncounterType oweType, u32 flags);
bool32 OWE_TryAndDespawnOldestGeneratedOverworldEncounter_Object(u32 localId, u8 *objectEventId);
void OWE_TryAndDespawnOldestGeneratedOverworldEncounter_Palette(void);
void OverworldWildEncounter_DespawnOnBattle(void);
void OWE_TryDespawnOverworldWildEncountersCrossingMapConnection(void);
void OWE_RestoreBehaviorState(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void OWE_SetSavedMovementState(struct ObjectEvent *objectEvent);
void OWE_ClearSavedMovementState(struct ObjectEvent *objectEvent);
bool32 OWE_CheckRestrictedMovement(struct ObjectEvent *objectEvent, enum Direction direction);
bool32 OWE_CanAwareMonSeePlayer(struct ObjectEvent *mon);
bool32 OWE_IsPlayerInsideMonActiveDistance(struct ObjectEvent *mon);
bool32 OWE_IsMonNextToPlayer(struct ObjectEvent *mon);
u32 OWE_DirectionToPlayerFromCollision(struct ObjectEvent *mon);
u32 OWE_GetApproachingMonDistanceToPlayer(struct ObjectEvent *mon, bool32 *equalDistances);
u32 OWE_GetWalkMovementActionInDirectionWithSpeed(enum Direction direction, u32 speed);
void OWE_PlayAmbientCry(void);
u32 GetNumberActiveOverworldEncounters(enum OverworldObjectEncounterType oweType);
const struct ObjectEventTemplate TryGetObjectEventTemplateForOverworldEncounter(const struct ObjectEventTemplate *template);
struct SpritePalette OWE_GetSpawnAnimFldEffPalette(enum OverworldEncounterSpawnAnim spawnAnim);

extern const u8 InteractWithOverworldWildEncounter[];

#endif // GUARD_WILD_ENCOUNTER_OW_H