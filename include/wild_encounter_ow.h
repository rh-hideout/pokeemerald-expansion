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
bool32 IsOverworldWildEncounter(struct ObjectEvent *objectEvent, enum OverworldObjectEncounterType oweType);
void StartWildBattleWithOWE(void);
void SetInstantOWESpawnTimer(void);
void SetMinimumOWESpawnTimer(void);
void TryTriggerOverworldWilEncounter(struct ObjectEvent *obstacle, struct ObjectEvent *collider);
bool32 ShouldRunDefaultOWEScript(u32 objectEventId);
void OnOverworldWildEncounterSpawn(struct ObjectEvent *objectEvent);
void OnOverworldWildEncounterDespawn(struct ObjectEvent *objectEvent);
bool32 IsOWEDespawnExempt(struct ObjectEvent *objectEvent);
bool32 DespawnOWEDueToNPCCollision(struct ObjectEvent *curObject, struct ObjectEvent *objectEvent);
u32 DespawnOWEDueToTrainerSight(u32 collision, s32 x, s32 y);
void DespwnAllOverworldWildEncounters(enum OverworldObjectEncounterType oweType, u32 flags);
bool32 TryAndDespawnOldestGeneratedOWE_Object(u32 localId, u8 *objectEventId);
void TryAndDespawnOldestGeneratedOWE_Palette(void);
void DespawnOWEOnBattleStart(void);
void TryDespawnOWEsCrossingMapConnection(void);
void RestoreSavedOWEBehaviorState(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void SetSavedOWEMovementState(struct ObjectEvent *objectEvent);
void ClearSavedOWEMovementState(struct ObjectEvent *objectEvent);
bool32 CheckRestrictedOWEMovement(struct ObjectEvent *objectEvent, enum Direction direction);
bool32 CanAwareOWESeePlayer(struct ObjectEvent *mon);
bool32 IsPlayerInsideOWEActiveDistance(struct ObjectEvent *mon);
bool32 IsOWENextToPlayer(struct ObjectEvent *mon);
enum Direction DirectionOfOWEToPlayerFromCollision(struct ObjectEvent *mon);
u32 GetApproachingOWEDistanceToPlayer(struct ObjectEvent *mon, bool32 *equalDistances);
u32 GetOWEWalkMovementActionInDirectionWithSpeed(enum Direction direction, u32 speed);
void OWEApproachForBattle(void);
void PlayAmbientOWECry(void);
u32 GetNumberOfActiveOWEs(enum OverworldObjectEncounterType oweType);
const struct ObjectEventTemplate TryGetObjectEventTemplateForOWE(const struct ObjectEventTemplate *template);
struct SpritePalette GetOWESpawnDespawnAnimFldEffPalette(enum OverworldEncounterSpawnAnim spawnAnim);

extern const u8 InteractWithOverworldWildEncounter[];

#endif // GUARD_WILD_ENCOUNTER_OW_H