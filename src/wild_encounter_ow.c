#include "global.h"
#include "wild_encounter_ow.h"
#include "battle_setup.h"
#include "battle_main.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "follower_npc.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "random.h"
#include "roamer.h"
#include "script.h"
#include "script_movement.h"
#include "sprite.h"
#include "sound.h"
#include "task.h"
#include "trainer_hill.h"
#include "wild_encounter.h"
#include "constants/battle_frontier.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/layouts.h"
#include "constants/item.h"
#include "constants/map_types.h"
#include "constants/trainer_types.h"
#include "constants/songs.h"
#include "constants/vars.h"
#include "constants/wild_encounter.h"


#define sOverworldEncounterLevel        trainerRange_berryTreeId
#define sAge                            playerCopyableMovement
#define sRoamerOutbreakStatus           warpArrowSpriteId
#define OWE_NON_ROAMER_OUTBREAK         0
#define OWE_MASS_OUTBREAK_INDEX         ROAMER_COUNT + 1
#define OWE_INVALID_ROAMER_OUTBREAK     OWE_MASS_OUTBREAK_INDEX + 1
#define OWE_MAX_ROAMERS                 UINT8_MAX - 2

#define OWE_FLAG_BIT                    (1 << 7)
#define OWE_SAVED_MOVEMENT_STATE_FLAG   OWE_FLAG_BIT
#define OWE_NO_DESPAWN_FLAG             OWE_FLAG_BIT

#define OWE_SPAWNS_MAX                  4
#define OWE_SPAWN_DISTANCE_LAND         1   // A spawn cannot happen within this many tiles of the player position.
#define OWE_SPAWN_DISTANCE_WATER        3   // A spawn cannot happen within this many tiles of the player position (while surfing).
#define OWE_SPAWN_WIDTH_TOTAL           15  // Width of the on-screen spawn area in tiles.
#define OWE_SPAWN_HEIGHT_TOTAL          9   // Height of the on-screen spawn area in tiles.
#define OWE_SPAWN_WIDTH_RADIUS          (OWE_SPAWN_WIDTH_TOTAL - 1) / 2     // Distance from center to left/right edge (not including center).
#define OWE_SPAWN_HEIGHT_RADIUS         (OWE_SPAWN_HEIGHT_TOTAL - 1) / 2    // Distance from center to top/bottom edge (not including center).

#define OWE_SPAWN_TIME_REPLACEMENT      240 // The number of frames before an existing spawn will be replaced with a new one (requires WE_OWE_SPAWN_REPLACEMENT).
#define OWE_SPAWN_TIME_LURE             0
#define OWE_SPAWN_TIME_MINIMUM          30  // The minimum value the spawn wait time can be reset to. Prevents spawn attempts every frame.
#define OWE_SPAWN_TIME_PER_ACTIVE       30  // The number of frames that will be added to the countdown per currently active spawn.

#define OWE_MON_SIGHT_WIDTH             3
#define OWE_MON_SIGHT_LENGTH            4
#define OWE_CHASE_RANGE                 5
#define OWE_RESTORED_MOVEMENT_FUNC_ID   10

#define OWE_NO_ENCOUNTER_SET            0xFF
#define OWE_INVALID_SPAWN_SLOT          0xFF


#if WE_OW_ENCOUNTERS == TRUE && ROAMER_COUNT > OWE_MAX_ROAMERS
#error "ROAMER_COUNT needs to be less than OWE_MAX_ROAMERS due to it being stored in the u8 field warpArrowSpriteId"
#endif

#if OW_POKEMON_OBJECT_EVENTS == FALSE && WE_OW_ENCOUNTERS == TRUE
#error "OW_POKEMON_OBJECT_EVENTS needs to be TRUE in order for WE_OW_ENCOUNTERS to work."
#endif


static inline u32 GetLocalIdByOWESpawnSlot(u32 spawnSlot)
{
    return LOCALID_OW_ENCOUNTER_END - spawnSlot;
}

static inline u32 GetSpawnSlotByOWELocalId(u32 localId)
{
    return LOCALID_OW_ENCOUNTER_END - localId;
}

static inline u32 GetOWERoamerIndex(const struct ObjectEvent *owe)
{
    return owe->sRoamerOutbreakStatus & ~OWE_SAVED_MOVEMENT_STATE_FLAG;
}

static inline bool32 HasSavedOWEMovementState(const struct ObjectEvent *owe)
{
    return owe->sRoamerOutbreakStatus & OWE_SAVED_MOVEMENT_STATE_FLAG;
}

void SetSavedOWEMovementState(struct ObjectEvent *owe)
{
    owe->sRoamerOutbreakStatus |= OWE_SAVED_MOVEMENT_STATE_FLAG;
}

void ClearSavedOWEMovementState(struct ObjectEvent *owe)
{
    owe->sRoamerOutbreakStatus &= ~OWE_SAVED_MOVEMENT_STATE_FLAG;
}

static inline u32 GetOWEEncounterLevel(u32 level)
{
    return level & ~OWE_NO_DESPAWN_FLAG;
}

static inline void SetOWEEncounterLevel(u32 *level, u32 newLevel)
{
    *level = (*level & OWE_NO_DESPAWN_FLAG) | (newLevel & ~OWE_NO_DESPAWN_FLAG);
}

static inline bool32 HasOWENoDespawnFlag(const struct ObjectEvent *owe)
{
    return owe->sOverworldEncounterLevel & OWE_NO_DESPAWN_FLAG;
}

static inline void SetOWENoDespawnFlag(u32 *level)
{
    *level |= OWE_NO_DESPAWN_FLAG;
}

static inline bool32 ShouldSpawnWaterOWE(void)
{
    return TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING | PLAYER_AVATAR_FLAG_UNDERWATER);
}

static bool32 CreateEnemyPartyOWE(u32 *speciesId, u32 *level, u32 *indexRoamerOutbreak, s32 x, s32 y);
static bool32 OWE_DoesOWERoamerExist(void);
static u32 GetOWERoamerStatusFromIndex(u32 indexRoamer);
static u32 GetOWERoamerOutbreakStatus(struct ObjectEvent *owe);
static bool32 StartWildBattleWithOWE_CheckRoamer(u32 indexRoamerOutbreak);
static bool32 StartWildBattleWithOWE_CheckBattleFrontier(u32 headerId);
static bool32 StartWildBattleWithOWE_CheckMassOutbreak(u32 indexRoamerOutbreak, u32 speciesId);
static bool32 StartWildBattleWithOWE_CheckDoubleBattle(struct ObjectEvent *owe, u32 headerId);
static bool32 CheckCuurentWildMonHeaderForOWE(bool32 shouldSpawnWaterMons);
static u32 GetOldestActiveOWESlot(bool32 forceRemove);
static u32 GetNextOWESpawnSlot(void);
static u32 GetSpeciesByOWESpawnSlot(u32 spawnSlot);
static bool32 TrySelectTileForOWE(s32* outX, s32* outY);
static void SetSpeciesInfoForOWE(u32 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level, u32 *indexRoamerOutbreak, s32 x, s32 y);
static u32 GetGraphicsIdForOWE(u32 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level, u32 *indexRoamerOutbreak, s32 x, s32 y);
static bool32 CheckCanRemoveOWE(u32 localId);
static bool32 CheckCanLoadOWE(u32 speciesId, bool32 isFemale, bool32 isShiny, s32 x, s32 y);
static bool32 CheckCanLoadOWE_Palette(u32 speciesId, bool32 isFemale, bool32 isShiny, s32 x, s32 y);
static bool32 CheckCanLoadOWE_Tiles(u32 speciesId, bool32 isFemale, bool32 isShiny, s32 x, s32 y);
static void SortOWEAges(void);
static u32 RemoveOldestGeneratedOWE(void);
static bool32 ShouldDespawnGeneratedForNewOWE(struct ObjectEvent *owe);
static void SetNewOWESpawnCountdown(void);
static void DoOWESpawnDespawnAnim(struct ObjectEvent *owe, bool32 animSpawn);
static enum SpawnDespawnTypeOWE GetOWESpawnDespawnAnimType(u32 metatileBehavior);
static void PlayOWECry(struct ObjectEvent *owe);
static struct ObjectEvent *GetOWEObjectEvent(void);
static bool32 OWE_ShouldPlayOWEFleeSound(struct ObjectEvent *owe);
static bool32 CheckRestrictedOWEMovementAtCoords(struct ObjectEvent *owe, s32 xNew, s32 yNew, enum Direction newDirection, enum Direction collisionDirection);
static bool32 CheckRestrictedOWEMovementMetatile(s32 xCurrent, s32 yCurrent, s32 xNew, s32 yNew);
static bool32 CheckRestrictedOWEMovementMap(struct ObjectEvent *owe, s32 xNew, s32 yNew);
static bool32 IsOWELineOfSightClear(struct ObjectEvent *player, enum Direction direction, u32 distance);
static enum Direction CheckOWEPathToPlayerFromCollision(struct ObjectEvent *owe, enum Direction newDirection);
static void Task_OWEApproachForBattle(u8 taskId);
static bool32 CheckValidOWESpecies(u32 speciesId);

static EWRAM_DATA u8 sOWESpawnCountdown = 0;

struct AgeSort
{
    u8 slot:4;
    u8 age:4;
};


void OverworldWildEncounters_CB(void)
{
    bool32 shouldSpawnWaterMons = ShouldSpawnWaterOWE();
    
    if (ArePlayerFieldControlsLocked() || FlagGet(DN_FLAG_SEARCHING) || !CheckCuurentWildMonHeaderForOWE(shouldSpawnWaterMons))
        return;

    if (!WE_OW_ENCOUNTERS
     || FlagGet(WE_OWE_FLAG_DISABLED)
     || FlagGet(OW_FLAG_NO_ENCOUNTER)
     || FlagGet(DN_FLAG_SEARCHING)
     || (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS && !WE_OWE_BATTLE_PIKE)
     || (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR && !WE_OWE_BATTLE_PYRAMID)
     || InTrainerHillChallenge())
    {
        if (sOWESpawnCountdown != OWE_NO_ENCOUNTER_SET)
        {
            DespwnAllOverworldWildEncounters(OWE_GENERATED, 0);
            sOWESpawnCountdown = OWE_NO_ENCOUNTER_SET;
        }
        return;
    }
    else if (sOWESpawnCountdown == OWE_NO_ENCOUNTER_SET)
    {
        SetMinimumOWESpawnTimer();
    }

    if (sOWESpawnCountdown)
    {
        sOWESpawnCountdown--;
        return;
    }
    
    DespwnAllOverworldWildEncounters(OWE_GENERATED, WILD_CHECK_REPEL);
    struct ObjectEvent* player = &gObjectEvents[gPlayerAvatar.objectEventId];
    if (player->currentCoords.x != player->previousCoords.x || player->currentCoords.y != player->previousCoords.y)
        return;

    u32 spawnSlot = GetNextOWESpawnSlot();
    s32 x, y;
    if (spawnSlot == OWE_INVALID_SPAWN_SLOT
     || (shouldSpawnWaterMons && AreLegendariesInSootopolisPreventingEncounters())
     || !TrySelectTileForOWE(&x, &y))
    {
        SetMinimumOWESpawnTimer();
        return;
    }

    u32 speciesId = SPECIES_NONE;
    bool32 isShiny = FALSE;
    bool32 isFemale = FALSE;
    u32 indexRoamerOutbreak = OWE_NON_ROAMER_OUTBREAK;
    u32 localId = GetLocalIdByOWESpawnSlot(spawnSlot);
    u32 level = MIN_LEVEL;
    u32 graphicsId = GetGraphicsIdForOWE(&speciesId, &isShiny, &isFemale, &level, &indexRoamerOutbreak, x, y);

    if (speciesId == SPECIES_NONE
     || !IsWildLevelAllowedByRepel(GetOWEEncounterLevel(level))
     || !IsAbilityAllowingEncounter(GetOWEEncounterLevel(level))
     || !CheckCanLoadOWE(speciesId, isFemale, isShiny, x, y))
    {
        SetMinimumOWESpawnTimer();
        return;
    }
    
    struct ObjectEventTemplate objectEventTemplate = {
        .localId = localId,
        .graphicsId = graphicsId,
        .x = x - MAP_OFFSET,
        .y = y - MAP_OFFSET,
        .elevation = MapGridGetElevationAt(x, y),
        .movementType = OWE_GetMovementTypeFromSpecies(speciesId),
        .trainerType = TRAINER_TYPE_OW_WILD_ENCOUNTER,
        .script = InteractWithOverworldWildEncounter,
    };
    u32 objectEventId = GetObjectEventIdByLocalId(localId);
    struct ObjectEvent *owe = &gObjectEvents[objectEventId];
    if (ShouldDespawnGeneratedForNewOWE(owe))
        RemoveObjectEvent(owe);
    objectEventId = SpawnSpecialObjectEvent(&objectEventTemplate);

    assertf(objectEventId < OBJECT_EVENTS_COUNT, "could not spawn generated overworld encounter. too many object events exist")
    {
        SetMinimumOWESpawnTimer();
        return;
    }

    owe = &gObjectEvents[objectEventId];
    owe->disableCoveringGroundEffects = TRUE;
    owe->sOverworldEncounterLevel = level;
    owe->sRoamerOutbreakStatus = indexRoamerOutbreak;

    enum Direction directions[4];
    memcpy(directions, gStandardDirections, sizeof directions);
    ObjectEventTurn(owe, directions[Random() & 3]);
    SetNewOWESpawnCountdown();
}

bool32 IsOverworldWildEncounter(struct ObjectEvent *owe, enum TypeOWE oweType)
{
    if (!IS_OW_MON_OBJ(owe))
        return FALSE;

    if (owe->trainerType != TRAINER_TYPE_OW_WILD_ENCOUNTER)
       return FALSE;

    switch (oweType)
    {
    default:
    case OWE_ANY:
        return TRUE;
    
    case OWE_GENERATED:
        return (owe->localId <= LOCALID_OW_ENCOUNTER_END && owe->localId > (LOCALID_OW_ENCOUNTER_END - OWE_SPAWNS_MAX));

    case OWE_MANUAL:
        return (owe->localId > LOCALID_OW_ENCOUNTER_END || owe->localId <= (LOCALID_OW_ENCOUNTER_END - OWE_SPAWNS_MAX));
    }
}

void StartWildBattleWithOWE(void)
{
    u32 localId = gSpecialVar_LastTalked;
    u32 objEventId = GetObjectEventIdByLocalId(localId);
    u32 headerId = GetCurrentMapWildMonHeaderId();
    struct ObjectEvent *owe = &gObjectEvents[objEventId];
    u32 indexRoamerOutbreak = GetOWERoamerIndex(owe);

    assertf(objEventId < OBJECT_EVENTS_COUNT && IsOverworldWildEncounter(owe, OWE_ANY), "cannot start overworld wild enocunter as the selected object is invalid.\nlocalId: %d", localId)
    {
        UnlockPlayerFieldControls();
        UnfreezeObjectEvents();
        return;
    }

    if (indexRoamerOutbreak && StartWildBattleWithOWE_CheckRoamer(GetOWERoamerOutbreakStatus(owe)))
        return;

    u32 speciesId = OW_SPECIES(owe);
    bool32 shiny = OW_SHINY(owe) ? TRUE : FALSE;
    u32 gender = OW_FEMALE(owe) ? MON_FEMALE : MON_MALE;
    u32 level = GetOWEEncounterLevel(owe->sOverworldEncounterLevel);
    u32 personality;

    switch (gSpeciesInfo[speciesId].genderRatio)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
        gender = gSpeciesInfo[speciesId].genderRatio;
    }

    if (level < MIN_LEVEL || level > MAX_LEVEL)
        level = MIN_LEVEL;

    ZeroEnemyPartyMons();
    personality = GetMonPersonality(speciesId, gender, NATURE_RANDOM, RANDOM_UNOWN_LETTER);
    CreateMonWithIVs(&gEnemyParty[0], speciesId, level, personality, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    GiveMonInitialMoveset(&gEnemyParty[0]);
    SetMonData(&gEnemyParty[0], MON_DATA_IS_SHINY, &shiny);
    
    if (StartWildBattleWithOWE_CheckBattleFrontier(headerId))
        return;
    
    if (StartWildBattleWithOWE_CheckMassOutbreak(indexRoamerOutbreak, speciesId))
        return;

    if (StartWildBattleWithOWE_CheckDoubleBattle(owe, headerId))
        return;

    BattleSetup_StartWildBattle();
}

static bool32 CreateEnemyPartyOWE(u32 *speciesId, u32 *level, u32 *indexRoamerOutbreak, s32 x, s32 y)
{
    const struct WildPokemonInfo *wildMonInfo;
    enum WildPokemonArea wildArea;
    enum TimeOfDay timeOfDay;
    u32 headerId = GetCurrentMapWildMonHeaderId();
    u32 metatileBehavior = MapGridGetMetatileBehaviorAt(x, y);

    if (headerId == HEADER_NONE)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS)
        {
            headerId = GetBattlePikeWildMonHeaderId();
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
            if (TryGenerateWildMon(gBattlePikeWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
                return FALSE;
            else if (!TryGenerateBattlePikeWildMon(TRUE))
                return FALSE;
            
            return TRUE;
        }
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        {
            headerId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
            if (TryGenerateWildMon(gBattlePyramidWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo, WILD_AREA_LAND, 0) != TRUE)
                return FALSE;

            u32 id = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES);
            GenerateBattlePyramidWildMon(SPECIES_NONE);
            SetMonData(&gEnemyParty[0], MON_DATA_LEVEL, &id);
            return TRUE;
        }

        return FALSE;
    }

    if (MetatileBehavior_IsWaterWildEncounter(metatileBehavior))
    {
        wildArea = WILD_AREA_WATER;
        timeOfDay = GetTimeOfDayForEncounters(headerId, wildArea);
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo;
    }
    else
    {
        wildArea = WILD_AREA_LAND;
        timeOfDay = GetTimeOfDayForEncounters(headerId, wildArea);
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo;
    }

    if (wildMonInfo == NULL)
        return FALSE;

    /*
    These functions perform checks of various encounter types in the following order:
        1. Attempt to generate a Roamer Encounter
        2. Attempt to generate a Feebas Encounter
        3. Attempt to generate a Mass Outbreak Encounter
        4. Attempt to generate a Standard Wild Encounter
    
    The structure of this statement ensures that only one of these encounter types can succeed per call,
    with the resultant wild mon being created in gEnemyParty[0].
    If none of these checks succeed, speciesId is set to SPECIES_NONE and FALSE is returned.
    */

    if (*indexRoamerOutbreak != OWE_INVALID_ROAMER_OUTBREAK)
    {
        if (TryStartRoamerEncounter() && !OWE_DoesOWERoamerExist())
        {
            *indexRoamerOutbreak = GetOWERoamerStatusFromIndex(gEncounteredRoamerIndex);
            return TRUE;
        }
        else if (WE_OWE_FEEBAS_SPOTS && MetatileBehavior_IsWaterWildEncounter(metatileBehavior) && CheckFeebasAtCoords(x, y))
        {
            CreateWildMon(gWildFeebas.species, ChooseWildMonLevel(&gWildFeebas, 0, WILD_AREA_FISHING));
            if (WE_OWE_PREVENT_FEEBAS_DESPAWN)
                SetOWENoDespawnFlag(level);

            return TRUE;
        }
        else if (DoMassOutbreakEncounterTest() && MetatileBehavior_IsLandWildEncounter(metatileBehavior))
        {
            SetUpMassOutbreakEncounter(0);
            *indexRoamerOutbreak = OWE_MASS_OUTBREAK_INDEX;
            return TRUE;
        }
        else
        {
            return TryGenerateWildMon(wildMonInfo, wildArea, 0);
        }
    }

    return TryGenerateWildMon(wildMonInfo, wildArea, 0);
}

static bool32 OWE_DoesOWERoamerExist(void)
{
    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        struct ObjectEvent *owe = &gObjectEvents[i];
        if (IsOverworldWildEncounter(owe, OWE_ANY) && GetOWERoamerOutbreakStatus(owe) == gEncounteredRoamerIndex)
            return TRUE;
    }

    return FALSE;
}

static u32 GetOWERoamerStatusFromIndex(u32 indexRoamer)
{
    if (indexRoamer < ROAMER_COUNT)
        return indexRoamer + 1;
    
    return indexRoamer;
}

static u32 GetOWERoamerOutbreakStatus(struct ObjectEvent *owe)
{
    if (!IsOverworldWildEncounter(owe, OWE_ANY))
        return OWE_INVALID_ROAMER_OUTBREAK;

    u32 status = GetOWERoamerIndex(owe);
    if (status == OWE_NON_ROAMER_OUTBREAK || status == OWE_MASS_OUTBREAK_INDEX)
    {
        return OWE_INVALID_ROAMER_OUTBREAK;
    }
    
    return status - 1;
}

static bool32 StartWildBattleWithOWE_CheckRoamer(u32 indexRoamerOutbreak)
{
    if (indexRoamerOutbreak < ROAMER_COUNT
     && IsRoamerAt(indexRoamerOutbreak, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum))
    {
        CreateRoamerMonInstance(indexRoamerOutbreak);
        gEncounteredRoamerIndex = indexRoamerOutbreak;
        BattleSetup_StartRoamerBattle();
        return TRUE;
    }

    return FALSE;
}

static bool32 StartWildBattleWithOWE_CheckBattleFrontier(u32 headerId)
{
    if (headerId == HEADER_NONE)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS)
        {
            TryGenerateBattlePikeWildMon(FALSE);
            BattleSetup_StartBattlePikeWildBattle();
            return TRUE;
        }
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        {
            u32 id = GetMonData(&gEnemyParty[0], MON_DATA_LEVEL);
            u32 species = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES);
            SetMonData(&gEnemyParty[0], MON_DATA_SPECIES, &id);
            if (!BATTLE_PYRAMID_RANDOM_ENCOUNTERS)
                species = SPECIES_NONE;
            GenerateBattlePyramidWildMon(species);
            BattleSetup_StartWildBattle();
            return TRUE;
        }
    }

    return FALSE;
}

static bool32 StartWildBattleWithOWE_CheckMassOutbreak(u32 indexRoamerOutbreak, u32 speciesId)
{
    if (indexRoamerOutbreak == OWE_MASS_OUTBREAK_INDEX
     && gSaveBlock1Ptr->outbreakPokemonSpecies == speciesId
     && gSaveBlock1Ptr->location.mapNum == gSaveBlock1Ptr->outbreakLocationMapNum
     && gSaveBlock1Ptr->location.mapGroup == gSaveBlock1Ptr->outbreakLocationMapGroup)
    {
        for (u32 i = 0; i < MAX_MON_MOVES; i++)
            SetMonMoveSlot(&gEnemyParty[0], gSaveBlock1Ptr->outbreakPokemonMoves[i], i);
        
        BattleSetup_StartWildBattle();
        return TRUE;
    }

    return FALSE;
}

static bool32 StartWildBattleWithOWE_CheckDoubleBattle(struct ObjectEvent *owe, u32 headerId)
{
    enum WildPokemonArea wildArea;
    enum TimeOfDay timeOfDay;
    const struct WildPokemonInfo *wildMonInfo;
    u32 metatileBehavior = MapGridGetMetatileBehaviorAt(owe->currentCoords.x, owe->currentCoords.y);

    if (TryDoDoubleWildBattle())
    {
        struct Pokemon mon1 = gEnemyParty[0];

        if (MetatileBehavior_IsWaterWildEncounter(metatileBehavior))
        {
            wildArea = WILD_AREA_WATER;
            timeOfDay = GetTimeOfDayForEncounters(headerId, wildArea);
            wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo;
        }
        else
        {
            wildArea = WILD_AREA_LAND;
            timeOfDay = GetTimeOfDayForEncounters(headerId, wildArea);
            wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo;
        }

        if (TryGenerateWildMon(wildMonInfo, wildArea, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE))
        {
            gEnemyParty[1] = mon1;
            BattleSetup_StartDoubleWildBattle();
            return TRUE;
        }
    }

    return FALSE;
}

void SetInstantOWESpawnTimer(void)
{
    if (!WE_OW_ENCOUNTERS)
        return;

    sOWESpawnCountdown = 0;
}

void SetMinimumOWESpawnTimer(void)
{
    if (!WE_OW_ENCOUNTERS)
        return;

    sOWESpawnCountdown = OWE_SPAWN_TIME_MINIMUM;
    if (LURE_STEP_COUNT && GetNumberOfActiveOWEs(OWE_GENERATED) < OWE_SPAWNS_MAX)
        sOWESpawnCountdown = OWE_SPAWN_TIME_LURE;
}

void TryTriggerOverworldWilEncounter(struct ObjectEvent *obstacle, struct ObjectEvent *collider)
{
    if (WE_OWE_REPEL_DEXNAV_COLLISION && (FlagGet(DN_FLAG_SEARCHING) || REPEL_STEP_COUNT))
        return;

    bool32 playerIsCollider = (collider->isPlayer && IsOverworldWildEncounter(obstacle, OWE_ANY));
    bool32 playerIsObstacle = (obstacle->isPlayer && IsOverworldWildEncounter(collider, OWE_ANY));

    if (!(playerIsCollider || playerIsObstacle))
        return;

    struct ObjectEvent *wildMon = playerIsCollider ? obstacle : collider;
    u32 indexRoamerOutbreak = GetOWERoamerIndex(wildMon);
    if (indexRoamerOutbreak
     && indexRoamerOutbreak < OWE_MASS_OUTBREAK_INDEX
     && !IsRoamerAt(GetOWERoamerOutbreakStatus(wildMon), gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum))
    {
        RemoveObjectEvent(wildMon);
        return;
    }

    gSpecialVar_LastTalked = wildMon->localId;
    gSpecialVar_0x8004 = OW_SPECIES(wildMon);
    gSelectedObjectEvent = GetObjectEventIdByLocalId(wildMon->localId);

    // Stop the bobbing animation.
    if (wildMon->movementActionId >= MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_DOWN && wildMon->movementActionId <= MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_RIGHT)
        ClearObjectEventMovement(wildMon, &gSprites[wildMon->spriteId]);

    ScriptContext_SetupScript(InteractWithOverworldWildEncounter);
}

bool32 ShouldRunDefaultOWEScript(u32 objectEventId)
{
    struct ObjectEvent *owe = &gObjectEvents[objectEventId];
    if (!IsOverworldWildEncounter(owe, OWE_ANY))
        return FALSE;

    if (IsOverworldWildEncounter(owe, OWE_MANUAL)
     && GetObjectEventScriptPointerByObjectEventId(objectEventId) != InteractWithOverworldWildEncounter
     && GetObjectEventScriptPointerByObjectEventId(objectEventId) != NULL)
        return FALSE;

    gSpecialVar_0x8004 = OW_SPECIES(owe);
    return TRUE;
}

static bool32 CheckCuurentWildMonHeaderForOWE(bool32 shouldSpawnWaterMons)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay;

    if (headerId == HEADER_NONE)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS)
        {
            headerId = GetBattlePikeWildMonHeaderId();
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
            return gBattlePikeWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo != NULL;
        }
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        {
            headerId = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
            timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
            return gBattlePyramidWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo != NULL;
        }
        return FALSE;
    }

    if (shouldSpawnWaterMons)
    {
        timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_WATER);
        return gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo != NULL;
    }

    timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
    return gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo != NULL;
}

static u32 GetOldestActiveOWESlot(bool32 forceRemove)
{
    struct ObjectEvent *slotMon, *oldest = &gObjectEvents[GetObjectEventIdByLocalId(LOCALID_OW_ENCOUNTER_END)];
    u32 spawnSlot;

    for (spawnSlot = 0; spawnSlot < OWE_SPAWNS_MAX; spawnSlot++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(GetLocalIdByOWESpawnSlot(spawnSlot))];
        if (OW_SPECIES(slotMon) != SPECIES_NONE && (!HasOWENoDespawnFlag(slotMon) || forceRemove == TRUE))
        {
            oldest = slotMon;
            break;
        }
    }

    if (spawnSlot >= OWE_SPAWNS_MAX)
        return OWE_INVALID_SPAWN_SLOT;

    for (spawnSlot = 0; spawnSlot < OWE_SPAWNS_MAX; spawnSlot++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(GetLocalIdByOWESpawnSlot(spawnSlot))];
        if (OW_SPECIES(slotMon) != SPECIES_NONE && (!HasOWENoDespawnFlag(slotMon) || forceRemove == TRUE))
        {
            if (slotMon->sAge > oldest->sAge)
                oldest = slotMon;
        }
    }

    return GetSpawnSlotByOWELocalId(oldest->localId);
}

static u32 GetNextOWESpawnSlot(void)
{
    u32 spawnSlot;

    // All mon slots are in use
    if (GetNumberOfActiveOWEs(OWE_GENERATED) >= OWE_SPAWNS_MAX)
    {
        if (WE_OWE_SPAWN_REPLACEMENT)
        {
            // Cycle through so we remove the oldest mon first
            spawnSlot = GetOldestActiveOWESlot(FALSE);
            if (spawnSlot == OWE_INVALID_SPAWN_SLOT)
                return OWE_INVALID_SPAWN_SLOT;
        }
        else
        {
            return OWE_INVALID_SPAWN_SLOT;
        }
    }
    else
    {
        for (spawnSlot = 0; spawnSlot < OWE_SPAWNS_MAX; spawnSlot++)
        {
            if (GetSpeciesByOWESpawnSlot(spawnSlot) == SPECIES_NONE)
                break;
        }
    }

    return spawnSlot;
}

static u32 GetSpeciesByOWESpawnSlot(u32 spawnSlot)
{
    u32 objEventId = GetObjectEventIdByLocalId(GetLocalIdByOWESpawnSlot(spawnSlot));
    struct ObjectEvent *owe = &gObjectEvents[objEventId];

    if (objEventId >= OBJECT_EVENTS_COUNT)
        return SPECIES_NONE;

    return OW_SPECIES(owe);
}

static bool32 TrySelectTileForOWE(s32* outX, s32* outY)
{
    u32 elevation;
    u32 tileBehavior;
    s16 playerX, playerY;
    s16 x, y;
    u32 closeDistance;
    bool32 isEncounterTile = FALSE;

    // Spawn further away when surfing
    if (ShouldSpawnWaterOWE())
        closeDistance = OWE_SPAWN_DISTANCE_WATER;
    else
        closeDistance = OWE_SPAWN_DISTANCE_LAND;

    // Select a random tile in [-7, -4] [7, 4] range
    // Make sure is not directly next to player
    // Can we make get random tile its own function for use elsewhere in the codebase?
    // Have defines used and then replace MAP_METATILE_VIEW_X/Y with them
    do
    {
        x = (s16)(Random() % OWE_SPAWN_WIDTH_TOTAL) - OWE_SPAWN_WIDTH_RADIUS;
        y = (s16)(Random() % OWE_SPAWN_HEIGHT_TOTAL) - OWE_SPAWN_HEIGHT_RADIUS;
    }
    while (abs(x) <= closeDistance && abs(y) <= closeDistance);

    // We won't spawn mons in the immediate facing direction
    // (stops mons spawning in as I'm running in a straight line)
    switch (GetPlayerFacingDirection())
    {
    case DIR_NORTH:
        if(x == 0 && y < 0)
            x = -1;
        break;
    case DIR_SOUTH:
        if(x == 0  && y > 0)
            x = 1;
        break;
    case DIR_EAST:
        if(y == 0 && x > 0)
            y = -1;
        break;
    case DIR_WEST:
        if(y == 0 && x < 0)
            y = 1;
        break;
    default:
        break;
    }
    
    PlayerGetDestCoords(&playerX, &playerY);
    x += playerX;
    y += playerY;

    elevation = MapGridGetElevationAt(x, y);

    if (gMapHeader.mapLayoutId != LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
    {
        if (!AreCoordsInsidePlayerMap(x, y))
            return FALSE;
    }
    else
    {
        if (x < 0 || x >= 32 || y < 0 || y >= 32)
            return FALSE;
    }


    // 0 is change of elevation, 15 is multiple elevation e.g. bridges
    // Causes weird interaction issues so just don't let mons spawn here
    if (elevation == 0 || elevation == 15)
        return FALSE;

    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    if (ShouldSpawnWaterOWE() && MetatileBehavior_IsWaterWildEncounter(tileBehavior))
        isEncounterTile = TRUE;

    if (!ShouldSpawnWaterOWE() && (MetatileBehavior_IsLandWildEncounter(tileBehavior) || MetatileBehavior_IsIndoorEncounter(tileBehavior)))
        isEncounterTile = TRUE;

    if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS
     || gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        isEncounterTile = TRUE;

    if (isEncounterTile && !MapGridGetCollisionAt(x, y))
    {
        *outX = x;
        *outY = y;

        if (GetObjectEventIdByPosition(x, y, 0) == OBJECT_EVENTS_COUNT)
            return TRUE;
    }

    return FALSE;
}

static void SetSpeciesInfoForOWE(u32 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level, u32 *indexRoamerOutbreak, s32 x, s32 y)
{
    u32 personality;

    if (!CreateEnemyPartyOWE(speciesId, level, indexRoamerOutbreak, x, y))
    {
        ZeroEnemyPartyMons();
        *speciesId = SPECIES_NONE;
        return;
    }
 
    *speciesId = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES);
    SetOWEEncounterLevel(level, GetMonData(&gEnemyParty[0], MON_DATA_LEVEL));
    personality = GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY);

    if (*speciesId == SPECIES_UNOWN)
        *speciesId = GetUnownSpeciesId(personality);

    *isShiny = ComputePlayerShinyOdds(personality, READ_OTID_FROM_SAVE);
    if (GetGenderFromSpeciesAndPersonality(*speciesId, personality) == MON_FEMALE)
        *isFemale = TRUE;
    else
        *isFemale = FALSE;

    if (WE_OWE_PREVENT_SHINY_DESPAWN && *isShiny)
        SetOWENoDespawnFlag(level);

    ZeroEnemyPartyMons();
}

static u32 GetGraphicsIdForOWE(u32 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level, u32 *indexRoamerOutbreak, s32 x, s32 y)
{
    SetSpeciesInfoForOWE(speciesId, isShiny, isFemale, level, indexRoamerOutbreak, x, y);
    assertf(CheckValidOWESpecies(*speciesId), "invalid generated overworld encounter\nspecies: %d\ncheck if valid wild mon header exists", speciesId, x, y);
    u32 graphicsId = *speciesId + OBJ_EVENT_MON;

    if (*isFemale)
        graphicsId += OBJ_EVENT_MON_FEMALE;

    if (*isShiny)
        graphicsId += OBJ_EVENT_MON_SHINY;

    return graphicsId;
}

static bool32 CheckCanRemoveOWE(u32 localId)
{
    if (!WE_OW_ENCOUNTERS)
        return FALSE;

    if (!GetNumberOfActiveOWEs(OWE_GENERATED))
        return FALSE;

    if (!(localId <= (LOCALID_OW_ENCOUNTER_END - OWE_SPAWNS_MAX + 1) || localId > LOCALID_OW_ENCOUNTER_END))
        return FALSE;

    return TRUE;
}

static bool32 CheckCanLoadOWE(u32 speciesId, bool32 isFemale, bool32 isShiny, s32 x, s32 y)
{
    assertf(CheckCanLoadOWE_Palette(speciesId, isFemale, isShiny, x, y), "could not load palette for overworld encounter\nspecies: %d\nfemale: %d\nshiny: %d\ncoords: %d %d", speciesId, isFemale, isShiny, x, y)
    {
        return FALSE;
    }

    assertf(CheckCanLoadOWE_Tiles(speciesId, isFemale, isShiny, x, y), "could not load sprite tiles for overworld encounter\nspecies: %d\nfemale: %d\nshiny: %d\ncoords: %d %d", speciesId, isFemale, isShiny, x, y)
    {
        return FALSE;
    }

    return TRUE;
}

static bool32 CheckCanLoadOWE_Palette(u32 speciesId, bool32 isFemale, bool32 isShiny, s32 x, s32 y)
{
    u32 numFreePalSlots = CountFreePaletteSlots();
    u32 tag = speciesId + OBJ_EVENT_MON + (isShiny ? OBJ_EVENT_MON_SHINY : 0);

#if P_GENDER_DIFFERENCES
    if (isFemale && gSpeciesInfo[speciesId].overworldShinyPaletteFemale != NULL)
        tag += OBJ_EVENT_MON_FEMALE;
#endif

    // We need at least 2 pal slots open. One for the object and one for the spawn field effect.
    // Add this and tiles to seperate graphics check function
    if (numFreePalSlots == 1)
    {
        u32 metatileBehavior = MapGridGetMetatileBehaviorAt(x, y);
        struct SpritePalette palette = GetOWESpawnDespawnAnimFldEffPalette(GetOWESpawnDespawnAnimType(metatileBehavior));
        // If the mon's palette or field effect palette isn't already loaded, don't spawn.
        // Include check if female or shiny mon is loaded and use that tag if possible
        if (IndexOfSpritePaletteTag(tag) == 0xFF && IndexOfSpritePaletteTag(palette.tag) == 0xFF)
            return FALSE;
    }
    else if (numFreePalSlots == 0)
    {
        return FALSE;
    }

    return TRUE;
}
#define OWE_FIELD_EFFECT_TILE_NUM 16 // Number of tiiles to add for field effect spawning
static bool32 CheckCanLoadOWE_Tiles(u32 speciesId, bool32 isFemale, bool32 isShiny, s32 x, s32 y)
{
    u32 tag = speciesId + OBJ_EVENT_MON + (isShiny ? OBJ_EVENT_MON_SHINY : 0);
    // const struct ObjectEventGraphicsInfo *graphicsInfo = SpeciesToGraphicsInfo(speciesId, isShiny, isFemale);
    const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(tag);
    tag = LoadSheetGraphicsInfo(graphicsInfo, tag, NULL);
    u32 tileCount = graphicsInfo->size / TILE_SIZE_4BPP;
    if (OW_GFX_COMPRESS)
    {
        // If tiles are already existing return early, spritesheet is loaded when compressed
        if (IndexOfSpriteTileTag(tag) != 0xFF)
        {
            DebugPrintf("\n\nALREADY LOADED\nSpecies: %S", GetSpeciesName(speciesId));
            return TRUE;
        }
        
        u32 frames = graphicsInfo->anims == sAnimTable_Following_Asym ? 8 : 6;
        tileCount *= frames;
    }
    
    tileCount += OWE_FIELD_EFFECT_TILE_NUM;
    if (!CanAllocSpriteTiles(tileCount))
    {
        DebugPrintf("\n\nNO SPAWN\nSpecies: %S\nSheet Tile Count: %d", GetSpeciesName(speciesId), tileCount);
        return FALSE;
    }

    DebugPrintf("\n\nSPAWN\nSpecies: %S\nSheet Tile Count: %d", GetSpeciesName(speciesId), tileCount);
    FreeSpriteTilesByTag(tag);
    return TRUE;
}
#undef OWE_FIELD_EFFECT_TILE_NUM

static void SortOWEAges(void)
{
    struct ObjectEvent *slotMon;
    struct AgeSort array[OWE_SPAWNS_MAX];
    struct AgeSort current;
    u32 numActive = GetNumberOfActiveOWEs(OWE_GENERATED);
    u32 count = 0;
    s32 i, j;

    if (OWE_SPAWNS_MAX <= 1)
        return;

    for (i = 0; i < OWE_SPAWNS_MAX; i++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(GetLocalIdByOWESpawnSlot(i))];
        if (OW_SPECIES(slotMon) != SPECIES_NONE)
        {
            array[count].slot = i;
            array[count].age = slotMon->sAge;
            count++;
        }
        if (count == numActive)
            break;
    }

    for (i = 1; i < numActive; i++)
    {
        current = array[i];
        j = i - 1;

        while (j >= 0 && array[j].age < current.age)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = current;
    }

    array[0].age = numActive;
    slotMon = &gObjectEvents[GetObjectEventIdByLocalId(GetLocalIdByOWESpawnSlot(array[0].slot))];
    slotMon->sAge = numActive;

    for (i = 1; i < numActive; i++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(GetLocalIdByOWESpawnSlot(array[i].slot))];
        array[i].age = array[i - 1].age - 1;
        slotMon->sAge = array[i].age;
    }
}

void OnOverworldWildEncounterSpawn(struct ObjectEvent *owe)
{
    if (!IsOverworldWildEncounter(owe, OWE_ANY))
        return;
    
    if (IsOverworldWildEncounter(owe, OWE_GENERATED))
        SortOWEAges();

    DoOWESpawnDespawnAnim(owe, TRUE);
}

void OnOverworldWildEncounterDespawn(struct ObjectEvent *owe)
{
    if (!IsOverworldWildEncounter(owe, OWE_ANY))
        return;

    owe->sOverworldEncounterLevel = 0;
    owe->sAge = 0;
    owe->sRoamerOutbreakStatus = 0;
    
    DoOWESpawnDespawnAnim(owe, FALSE);
}

bool32 IsOWEDespawnExempt(struct ObjectEvent *owe)
{
    if (!IsOverworldWildEncounter(owe, OWE_ANY))
        return FALSE;

    if (HasOWENoDespawnFlag(owe) && AreCoordsInsidePlayerMap(owe->currentCoords.x, owe->currentCoords.y))
        return TRUE;

    owe->offScreen = TRUE;
    return FALSE;
}

bool32 DespawnOWEDueToNPCCollision(struct ObjectEvent *curObject, struct ObjectEvent *owe)
{
    if (!IsOverworldWildEncounter(curObject, OWE_GENERATED) || IsOverworldWildEncounter(owe, OWE_ANY) || owe->isPlayer)
        return FALSE;

    RemoveObjectEvent(curObject);
    return TRUE;
}

u32 DespawnOWEDueToTrainerSight(u32 collision, s32 x, s32 y)
{
    if (!(collision & (1 << (COLLISION_OBJECT_EVENT - 1))))
        return collision;

    struct ObjectEvent *owe = &gObjectEvents[GetObjectEventIdByXY(x, y)];
    if (!IsOverworldWildEncounter(owe, OWE_GENERATED))
        return collision;

    RemoveObjectEvent(owe);
    return collision & (1 << (COLLISION_OBJECT_EVENT - 1));
}

void DespwnAllOverworldWildEncounters(enum TypeOWE oweType, u32 flags)
{
    s32 dx = 0, dy = 0;

    if (gCamera.active)
    {
        dx = gCamera.x;
        dy = gCamera.y;
    }

    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; ++i)
    {
        struct ObjectEvent *owe = &gObjectEvents[i];

        if (!owe->active)
            continue;

        if (!IsOverworldWildEncounter(owe, oweType))
            continue;

        if (flags & WILD_CHECK_REPEL)
        {
            if (!REPEL_STEP_COUNT)
                continue;

            if (HasOWENoDespawnFlag(owe))
                continue;

            if (IsWildLevelAllowedByRepel(GetOWEEncounterLevel(owe->sOverworldEncounterLevel)))
                continue;
        }

        UpdateObjectEventCoords(owe, dx, dy);
        RemoveObjectEvent(owe);
    }
}

bool32 TryAndDespawnOldestGeneratedOWE_Object(u32 localId, u8 *objectEventId)
{
    // does CheckCanRemoveOWE need to be used in TryAndDespawnOldestGeneratedOWE_Palette
    if (CheckCanRemoveOWE(localId))
    {
        *objectEventId = RemoveOldestGeneratedOWE();
        if (*objectEventId == OBJECT_EVENTS_COUNT)
            return TRUE;
        else
            return FALSE;
    }
    
    return TRUE;
}

void TryAndDespawnOldestGeneratedOWE_Palette(void)
{
    // Should have similar naming convention for these despawn functions based on Num Object Events, Pals & Tiles
    if (WE_OW_ENCOUNTERS && CountFreePaletteSlots() < 2)
    {
        u32 count = GetNumberOfActiveOWEs(OWE_GENERATED);

        if (count > 0)
        {
            for (; count > 0; count--)
            {
                RemoveOldestGeneratedOWE();
                if (CountFreePaletteSlots() >= 2)
                    break;
            }
        }
    }
}

void DespawnOWEOnBattleStart(void)
{
    struct ObjectEvent *owe = &gObjectEvents[GetObjectEventIdByLocalId(gSpecialVar_LastTalked)];
    if (!IsOverworldWildEncounter(owe, OWE_ANY))
        return;

    if (IsOverworldWildEncounter(owe, OWE_MANUAL))
        FlagSet(GetObjectEventFlagIdByLocalIdAndMap(owe->localId, owe->mapNum, owe->mapGroup));

    RemoveObjectEvent(owe);
    SetNewOWESpawnCountdown();
    gSpecialVar_LastTalked = LOCALID_NONE;
}

void TryDespawnOWEsCrossingMapConnection(void)
{
    if (gMain.callback2 != CB2_Overworld)
        return;

    if (!WE_OWE_DESPAWN_ON_ENTER_TOWN)
        return;

    if (gMapHeader.mapType != MAP_TYPE_CITY && gMapHeader.mapType != MAP_TYPE_TOWN)
        return;

    if (WE_OWE_DESPAWN_SOUND)
        PlaySE(SE_FLEE);
        
    DespwnAllOverworldWildEncounters(OWE_ANY, 0);
}

static u32 RemoveOldestGeneratedOWE(void)
{
    u32 oldestSlot = GetOldestActiveOWESlot(TRUE);

    if (oldestSlot == OWE_INVALID_SPAWN_SLOT)
        return OBJECT_EVENTS_COUNT;

    u32 objectEventId = GetObjectEventIdByLocalId(GetLocalIdByOWESpawnSlot(oldestSlot));
    RemoveObjectEvent(&gObjectEvents[objectEventId]);
    return objectEventId;
}

static bool32 ShouldDespawnGeneratedForNewOWE(struct ObjectEvent *owe)
{
    if (!IsOverworldWildEncounter(owe, OWE_GENERATED))
        return FALSE;

    return WE_OWE_SPAWN_REPLACEMENT && GetNumberOfActiveOWEs(OWE_GENERATED) >= OWE_SPAWNS_MAX;
}

static void SetNewOWESpawnCountdown(void)
{
    u32 numActive = GetNumberOfActiveOWEs(OWE_GENERATED);

    if (WE_OWE_SPAWN_REPLACEMENT && numActive >= OWE_SPAWNS_MAX)
        sOWESpawnCountdown = OWE_SPAWN_TIME_REPLACEMENT;
    else if (LURE_STEP_COUNT && numActive < OWE_SPAWNS_MAX)
        sOWESpawnCountdown = OWE_SPAWN_TIME_LURE;
    else
        sOWESpawnCountdown = OWE_SPAWN_TIME_MINIMUM + (OWE_SPAWN_TIME_PER_ACTIVE * numActive);
}

static void DoOWESpawnDespawnAnim(struct ObjectEvent *owe, bool32 animSpawn)
{
    if (gMain.callback2 != CB2_Overworld)
        return;
    
    enum SpawnDespawnTypeOWE spawnAnimType;
    bool32 isShiny = OW_SHINY(owe) ? TRUE : FALSE;

    if (animSpawn)
        PlayOWECry(owe);
    
    if (!animSpawn && OWE_ShouldPlayOWEFleeSound(owe))
        PlaySE(SE_FLEE);

    if (WE_OWE_SHINY_SPARKLE && isShiny && animSpawn)
    {
        PlaySE(SE_SHINY);
        spawnAnimType = OWE_SPAWN_ANIM_SHINY;
    }
    else 
    {
        u32 metatileBehavior = MapGridGetMetatileBehaviorAt(owe->currentCoords.x, owe->currentCoords.y);
        spawnAnimType = GetOWESpawnDespawnAnimType(metatileBehavior);
    }
    MovementAction_OverworldEncounterSpawn(spawnAnimType, owe);
}

static enum SpawnDespawnTypeOWE GetOWESpawnDespawnAnimType(u32 metatileBehavior)
{
    if (MetatileBehavior_IsPokeGrass(metatileBehavior) || MetatileBehavior_IsAshGrass(metatileBehavior))
        return OWE_SPAWN_ANIM_GRASS;
    else if (MetatileBehavior_IsLongGrass(metatileBehavior))
        return OWE_SPAWN_ANIM_LONG_GRASS;
    else if (MetatileBehavior_IsSurfableFishableWater(metatileBehavior) && gMapHeader.mapType != MAP_TYPE_UNDERWATER)
        return OWE_SPAWN_ANIM_WATER;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_UNDERWATER))
        return OWE_SPAWN_ANIM_UNDERWATER;
    else
        return OWE_SPAWN_ANIM_CAVE;
}

static void PlayOWECry(struct ObjectEvent *owe)
{
    if (!IsOverworldWildEncounter(owe, OWE_ANY))
        return;
    
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    u32 speciesId = OW_SPECIES(owe);
    s32 distanceX = owe->currentCoords.x - player->currentCoords.x;
    s32 distanceY = owe->currentCoords.y - player->currentCoords.y;
    u32 distanceMax = OWE_SPAWN_WIDTH_RADIUS + OWE_SPAWN_HEIGHT_RADIUS;
    u32 distance;
    u32 volume;
    s32 pan;

    if (distanceX > OWE_SPAWN_WIDTH_RADIUS)
        distanceX = OWE_SPAWN_WIDTH_RADIUS;
    else if (distanceX < -OWE_SPAWN_WIDTH_RADIUS)
        distanceX = -OWE_SPAWN_WIDTH_RADIUS;

    distanceY = abs(distanceY);
    if (distanceY > OWE_SPAWN_HEIGHT_RADIUS)
        distanceY = OWE_SPAWN_HEIGHT_RADIUS;

    distance = abs(distanceX) + distanceY;
    if (distance > distanceMax)
        distance = distanceMax;

    volume = 80 - (distance * (80 - 50)) / distanceMax;
    pan = 212 + ((distanceX + OWE_SPAWN_WIDTH_RADIUS) * (300 - 212)) / (2 * OWE_SPAWN_WIDTH_RADIUS);
    
    PlayCry_NormalNoDucking(speciesId, pan, volume, CRY_PRIORITY_AMBIENT);
}

static struct ObjectEvent *GetOWEObjectEvent(void)
{
    u32 numActive = GetNumberOfActiveOWEs(OWE_ANY);
    u32 randomIndex;
    u32 counter = 0;
    struct ObjectEvent *owe;

    if (numActive)
        randomIndex = Random() % numActive;
    else
        return NULL;
    
    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        owe = &gObjectEvents[i];
        if (IsOverworldWildEncounter(owe, OWE_ANY))
        {
            if (counter >= randomIndex)
                return owe;
            else
                counter++;
        }
    }
    return NULL;
}

static bool32 OWE_ShouldPlayOWEFleeSound(struct ObjectEvent *owe)
{
    if (!IsOverworldWildEncounter(owe, OWE_ANY) || OW_SPECIES(owe) == SPECIES_NONE)
        return FALSE;

    if (!AreCoordsInsidePlayerMap(owe->currentCoords.x, owe->currentCoords.y))
        return FALSE;

    if (ShouldDespawnGeneratedForNewOWE(owe))
        return FALSE;

    if (owe->offScreen)
        return FALSE;

    return WE_OWE_DESPAWN_SOUND;
}

#define sTypeFuncId data[1] // Same as in src/event_object_movement.c
#define sJumpTimer  sprite->data[7] // Same as in src/event_object_movement.c
void RestoreSavedOWEBehaviorState(struct ObjectEvent *owe, struct Sprite *sprite)
{
    if (IsOverworldWildEncounter(owe, OWE_ANY) && HasSavedOWEMovementState(owe))
    {
        sprite->sTypeFuncId = OWE_RESTORED_MOVEMENT_FUNC_ID;
        if (owe->movementType == MOVEMENT_TYPE_APPROACH_PLAYER_OWE)
            sJumpTimer = (Random() % (OWE_APPROACH_JUMP_TIMER_MAX - OWE_APPROACH_JUMP_TIMER_MIN)) + OWE_APPROACH_JUMP_TIMER_MIN;
    }
}
#undef sTypeFuncId
#undef sJumpTimer

// Returns TRUE if movement is restricted.
bool32 CheckRestrictedOWEMovement(struct ObjectEvent *owe, enum Direction direction)
{
    if (GetCollisionInDirection(owe, direction))
        return TRUE;

    if (CanAwareOWESeePlayer(owe) && WE_OWE_UNRESTRICT_SIGHT)
        return FALSE;

    s32 xCurrent = owe->currentCoords.x;
    s32 yCurrent = owe->currentCoords.y;
    s32 xNew = xCurrent + gDirectionToVectors[direction].x;
    s32 yNew = yCurrent + gDirectionToVectors[direction].y;

    if (CheckRestrictedOWEMovementMetatile(xCurrent, yCurrent, xNew, yNew))
        return TRUE;
    
    if (CheckRestrictedOWEMovementMap(owe, xNew, yNew))
        return TRUE;

    return FALSE;
}

static bool32 CheckRestrictedOWEMovementAtCoords(struct ObjectEvent *owe, s32 xNew, s32 yNew, enum Direction newDirection, enum Direction collisionDirection)
{
    if (CheckRestrictedOWEMovementMetatile(owe->currentCoords.x, owe->currentCoords.y, xNew, yNew))
        return FALSE;

    if (CheckRestrictedOWEMovementMap(owe, xNew, yNew))
        return FALSE;

    if (GetCollisionAtCoords(owe, xNew, yNew, collisionDirection))
        return FALSE;

    return TRUE;
}

static bool32 CheckRestrictedOWEMovementMetatile(s32 xCurrent, s32 yCurrent, s32 xNew, s32 yNew)
{
    if (!WE_OWE_RESTRICT_METATILE)
        return FALSE;
    u32 metatileBehaviourCurrent = MapGridGetMetatileBehaviorAt(xCurrent, yCurrent);
    u32 metatileBehaviourNew = MapGridGetMetatileBehaviorAt(xNew, yNew);

    if (MetatileBehavior_IsLandWildEncounter(metatileBehaviourCurrent)
     && MetatileBehavior_IsLandWildEncounter(metatileBehaviourNew))
        return FALSE;

    if (MetatileBehavior_IsWaterWildEncounter(metatileBehaviourCurrent)
     && MetatileBehavior_IsWaterWildEncounter(metatileBehaviourNew))
        return FALSE;

    if (MetatileBehavior_IsIndoorEncounter(metatileBehaviourCurrent)
     && MetatileBehavior_IsIndoorEncounter(metatileBehaviourNew))
        return FALSE;

    if (!MetatileBehavior_IsLandWildEncounter(metatileBehaviourCurrent)
     && !MetatileBehavior_IsWaterWildEncounter(metatileBehaviourCurrent)
     && !MetatileBehavior_IsIndoorEncounter(metatileBehaviourCurrent))
        return FALSE;

    return TRUE;
}

static bool32 CheckRestrictedOWEMovementMap(struct ObjectEvent *owe, s32 xNew, s32 yNew)
{
    if (!WE_OWE_RESTRICT_MAP)
        return FALSE;
    
    if (owe->mapGroup == gSaveBlock1Ptr->location.mapGroup
     && owe->mapNum == gSaveBlock1Ptr->location.mapNum)
        return !AreCoordsInsidePlayerMap(xNew, yNew);
    else
        return AreCoordsInsidePlayerMap(xNew, yNew);
}

bool32 CanAwareOWESeePlayer(struct ObjectEvent *owe)
{
    if (!IsOverworldWildEncounter(owe, OWE_ANY) || owe->movementType == MOVEMENT_TYPE_WANDER_AROUND_OWE)
        return FALSE;

    if (IsPlayerInsideOWEActiveDistance(owe) && (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_DASH)
     || (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_BIKE) && gPlayerAvatar.runningState == MOVING)))
        return TRUE;

    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    u32 speciesId = OW_SPECIES(owe);
    u32 viewDistance = OWE_GetViewDistanceFromSpecies(speciesId);
    u32 viewWidth = OWE_GetViewWidthFromSpecies(speciesId);
    s32 halfWidth = (viewWidth - 1) / 2;
    enum Direction direction = owe->facingDirection;
    bool32 retVal = FALSE;

    switch (direction)
    {
    case DIR_NORTH:
        if (player->currentCoords.y < owe->currentCoords.y
         && owe->currentCoords.y - player->currentCoords.y <= viewDistance
         && player->currentCoords.x >= owe->currentCoords.x - halfWidth
         && player->currentCoords.x <= owe->currentCoords.x + halfWidth)
            retVal = TRUE;
        break;

    case DIR_SOUTH:
        if (player->currentCoords.y > owe->currentCoords.y
         && player->currentCoords.y - owe->currentCoords.y <= viewDistance
         && player->currentCoords.x >= owe->currentCoords.x - halfWidth
         && player->currentCoords.x <= owe->currentCoords.x + halfWidth)
            retVal = TRUE;
        break;

    case DIR_EAST:
        if (player->currentCoords.x > owe->currentCoords.x
         && player->currentCoords.x - owe->currentCoords.x <= viewDistance
         && player->currentCoords.y >= owe->currentCoords.y - halfWidth
         && player->currentCoords.y <= owe->currentCoords.y + halfWidth)
            retVal = TRUE;
        break;

    case DIR_WEST:
        if (player->currentCoords.x < owe->currentCoords.x
         && owe->currentCoords.x - player->currentCoords.x <= viewDistance
         && player->currentCoords.y >= owe->currentCoords.y - halfWidth
         && player->currentCoords.y <= owe->currentCoords.y + halfWidth)
            retVal = TRUE;
        break;

    default:
        retVal = FALSE;
        break;
    }

    if (retVal && IsOWELineOfSightClear(player, GetOppositeDirection(direction), viewDistance))
        return TRUE;
    
    return FALSE;
}

static bool32 IsOWELineOfSightClear(struct ObjectEvent *player, enum Direction direction, u32 distance)
{
    s16 x = player->currentCoords.x;
    s16 y = player->currentCoords.y;
    u32 i;

    for (i = 0; i < distance; i++)
    {
        MoveCoords(direction, &x, &y);
        if (MapGridGetCollisionAt(x, y)
         || GetMapBorderIdAt(x, y) == CONNECTION_INVALID
         || IsMetatileDirectionallyImpassable(player, x, y, GetOppositeDirection(direction))
         || IsElevationMismatchAt(player->currentElevation, x, y))
            return FALSE;
    }

    return TRUE;
}

bool32 IsPlayerInsideOWEActiveDistance(struct ObjectEvent *owe)
{
    if (!IsOverworldWildEncounter(owe, OWE_ANY))
        return FALSE;
    
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    u32 distance = OWE_CHASE_RANGE;
    u32 speciesId = OW_SPECIES(owe);

    if (speciesId != SPECIES_NONE)
        distance = OWE_GetViewActiveDistanceFromSpecies(speciesId);

    if (player->currentCoords.y <= owe->currentCoords.y + distance && player->currentCoords.y >= owe->currentCoords.y - distance
     && player->currentCoords.x <= owe->currentCoords.x + distance && player->currentCoords.x >= owe->currentCoords.x - distance)
        return TRUE;

    return FALSE;
}

bool32 IsOWENextToPlayer(struct ObjectEvent *owe)
{
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];

    if ((owe->currentCoords.x != player->currentCoords.x && owe->currentCoords.y != player->currentCoords.y) || (owe->currentCoords.x < player->currentCoords.x - 1 || owe->currentCoords.x > player->currentCoords.x + 1 || owe->currentCoords.y < player->currentCoords.y - 1 || owe->currentCoords.y > player->currentCoords.y + 1))
        return FALSE;

    return TRUE;
}

enum Direction DirectionOfOWEToPlayerFromCollision(struct ObjectEvent *owe)
{
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];

    switch (owe->movementDirection)
    {
    case DIR_NORTH:
    case DIR_SOUTH:
        if (player->currentCoords.x < owe->currentCoords.x)
            return DIR_WEST;
        else if (player->currentCoords.x == owe->currentCoords.x)
            return CheckOWEPathToPlayerFromCollision(owe, (Random() % 2) == 0 ? DIR_EAST : DIR_WEST);
        else
            return DIR_EAST;
    case DIR_EAST:
    case DIR_WEST:
        if (player->currentCoords.y < owe->currentCoords.y)
            return DIR_NORTH;
        else if (player->currentCoords.y == owe->currentCoords.y)
            return CheckOWEPathToPlayerFromCollision(owe, (Random() % 2) == 0 ? DIR_NORTH : DIR_SOUTH);
        else
            return DIR_SOUTH;
    }

    return owe->movementDirection;
}

u32 GetApproachingOWEDistanceToPlayer(struct ObjectEvent *owe, bool32 *equalDistances)
{
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    s32 absX, absY;
    s32 distanceX = player->currentCoords.x - owe->currentCoords.x;
    s32 distanceY = player->currentCoords.y - owe->currentCoords.y;

    if (distanceX < 0)
        absX = distanceX * -1;
    else
        absX = distanceX;

    if (distanceY < 0)
        absY = distanceY * -1;
    else
        absY = distanceY;

    if (absY == absX)
        *equalDistances = TRUE;

    if (absY > absX)
        return absY;
    else
        return absX;
}

u32 GetOWEWalkMovementActionInDirectionWithSpeed(enum Direction direction, u32 speed)
{
    switch (speed)
    {
    case OWE_SPEED_SLOW:
        return GetWalkSlowMovementAction(direction);
    case OWE_SPEED_FAST:
        return GetWalkFastMovementAction(direction);
    case OWE_SPEED_FASTER:
        return GetWalkFasterMovementAction(direction);
    }

    return GetWalkNormalMovementAction(direction);
}

static enum Direction CheckOWEPathToPlayerFromCollision(struct ObjectEvent *owe, enum Direction newDirection)
{
    s16 x = owe->currentCoords.x;
    s16 y = owe->currentCoords.y;

    MoveCoords(newDirection, &x, &y);
    if (CheckRestrictedOWEMovementAtCoords(owe, x, y, newDirection, newDirection))
    {
        if (owe->movementType == MOVEMENT_TYPE_FLEE_PLAYER_OWE)
            return GetOppositeDirection(newDirection);

        MoveCoords(owe->movementDirection, &x, &y);
        if (CheckRestrictedOWEMovementAtCoords(owe, x, y, newDirection, owe->movementDirection))
            return newDirection;
    }

    x = owe->currentCoords.x;
    y = owe->currentCoords.y;
    MoveCoords(GetOppositeDirection(newDirection), &x, &y);
    if (CheckRestrictedOWEMovementAtCoords(owe, x, y, newDirection, newDirection))
    {
        if (owe->movementType == MOVEMENT_TYPE_FLEE_PLAYER_OWE)
            return newDirection;

        MoveCoords(owe->movementDirection, &x, &y);
        if (CheckRestrictedOWEMovementAtCoords(owe, x, y, newDirection, owe->movementDirection))
            return GetOppositeDirection(newDirection);
    }

    return owe->movementDirection;
}

#define tObjectId data[0]
void OWEApproachForBattle(void)
{
    u32 objectEventId = GetObjectEventIdByLocalId(gSpecialVar_LastTalked);
    struct ObjectEvent *owe = &gObjectEvents[objectEventId];
    if (!WE_OWE_APPROACH_FOR_BATTLE || !IsOverworldWildEncounter(owe, OWE_ANY))
    {
        FreezeObjectEvent(owe);
        return;
    }
    
    if (!IsOverworldWildEncounter(owe, OWE_ANY))
        return;
    
    u32 taskId = CreateTask(Task_OWEApproachForBattle, 2);
    if (FindTaskIdByFunc(Task_OWEApproachForBattle) == TASK_NONE)
    {
        FreezeObjectEvent(owe);
        return;
    }
    
    ScriptContext_Stop();
    gTasks[taskId].tObjectId = objectEventId;
}

static void Task_OWEApproachForBattle(u8 taskId)
{
    struct ObjectEvent *OWE = &gObjectEvents[gTasks[taskId].tObjectId];

    // Let the mon continue to take steps until right next to the player.
    if (ObjectEventClearHeldMovementIfFinished(OWE))
    {
        struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
        if (IsOWENextToPlayer(OWE))
        {
            ObjectEventsTurnToEachOther(player, OWE);
            ScriptContext_Enable();
            DestroyTask(taskId);
            return;
        }

        u32 speciesId = OW_SPECIES(OWE);
        enum Direction direction = DetermineObjectEventDirectionFromObject(player, OWE);
        u32 movementActionId;
    
        SetObjectEventDirection(OWE, direction);
        movementActionId = GetOWEWalkMovementActionInDirectionWithSpeed(OWE->movementDirection, OWE_GetActiveSpeedFromSpecies(speciesId));
        
        if (CheckRestrictedOWEMovement(OWE, OWE->movementDirection))
        {
            struct ObjectEvent *followerMon = GetFollowerObject();
            u32 idFollowerNPC = GetFollowerNPCObjectId();
            struct ObjectEvent *followerNPC = &gObjectEvents[idFollowerNPC];
            s16 x = OWE->currentCoords.x;
            s16 y = OWE->currentCoords.y;
            u32 collidingObject;

            MoveCoords(OWE->movementDirection, &x, &y);
            collidingObject = GetObjectObjectCollidesWith(OWE, x, y, FALSE);

            if (collidingObject == GetObjectEventIdByLocalId(followerMon->localId) && followerMon != NULL && !followerMon->invisible)
            {
                ClearObjectEventMovement(followerMon, &gSprites[followerMon->spriteId]);
                gSprites[followerMon->spriteId].animCmdIndex = 0;
                ObjectEventSetHeldMovement(followerMon, MOVEMENT_ACTION_ENTER_POKEBALL);
            }
            else if (collidingObject == idFollowerNPC && FNPC_ENABLE_NPC_FOLLOWERS && PlayerHasFollowerNPC() && !followerNPC->invisible)
            {
                enum Direction direction = DetermineFollowerNPCDirection(&gObjectEvents[gPlayerAvatar.objectEventId], followerNPC);
                ClearObjectEventMovement(followerNPC, &gSprites[followerNPC->spriteId]);
                gSprites[followerNPC->spriteId].animCmdIndex = 0;
                ObjectEventSetHeldMovement(followerNPC, GetWalkNormalMovementAction(direction));
                CreateTask(Task_HideNPCFollowerAfterMovementFinish, 2);
            }
            else if (collidingObject == gPlayerAvatar.objectEventId)
            {
                movementActionId = GetFaceDirectionMovementAction(OWE->facingDirection);
            }
            else
            {
                direction = DirectionOfOWEToPlayerFromCollision(OWE);
                SetObjectEventDirection(OWE, direction);
                movementActionId = GetOWEWalkMovementActionInDirectionWithSpeed(OWE->movementDirection, OWE_GetActiveSpeedFromSpecies(speciesId));
            }
        }
        ObjectEventSetHeldMovement(OWE, movementActionId);
    }
    
}
#undef tObjectId

void PlayAmbientOWECry(void)
{
    PlayOWECry(GetOWEObjectEvent());
}

u32 GetNumberOfActiveOWEs(enum TypeOWE oweType)
{
    u32 numActive = 0;
    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (IsOverworldWildEncounter(&gObjectEvents[i], oweType))
            numActive++;
    }
    return numActive;
}

const struct ObjectEventTemplate TryGetObjectEventTemplateForOWE(const struct ObjectEventTemplate *template)
{
    if (template->trainerType != TRAINER_TYPE_OW_WILD_ENCOUNTER || (template->localId <= LOCALID_OW_ENCOUNTER_END
     && template->localId > (LOCALID_OW_ENCOUNTER_END - OWE_SPAWNS_MAX)))
        return *template;

    struct ObjectEventTemplate templateOWE = *template;
    
    u32 graphicsId;
    u32 speciesId, speciesTemplate = SanitizeSpeciesId(templateOWE.graphicsId & OBJ_EVENT_MON_SPECIES_MASK);
    bool32 isShiny = FALSE, isShinyTemplate = (templateOWE.graphicsId & OBJ_EVENT_MON_SHINY) ? TRUE : FALSE;
    bool32 isFemale = FALSE;
    u32 level = MIN_LEVEL, levelTemplate = templateOWE.sOverworldEncounterLevel;
    u32 indexRoamerOutbreak = OWE_INVALID_ROAMER_OUTBREAK;
    u32 x = template->x;
    u32 y = template->y;

    SetSpeciesInfoForOWE(&speciesId, &isShiny, &isFemale, &level, &indexRoamerOutbreak, x, y);
    if (speciesTemplate)
        speciesId = speciesTemplate;

    if (levelTemplate)
        level = levelTemplate;

    bool32 validSpecies = CheckValidOWESpecies(speciesId);
    bool32 validLevel = GetOWEEncounterLevel(level) >= MIN_LEVEL && GetOWEEncounterLevel(level) <= MAX_LEVEL;
    assertf(validSpecies && validLevel, "invalid manual overworld encounter\nspecies: %d\nlevel: %d\nx: %d y: %d\ncheck if valid wild mon header exists", speciesId, level, x, y)
    {
        if (!validSpecies)
        {
            // Currently causes assertf on each player step as function is called.
            templateOWE.graphicsId = OBJ_EVENT_GFX_BOY_1;
            templateOWE.trainerType = TRAINER_TYPE_NONE;
            templateOWE.sOverworldEncounterLevel = 0;
            templateOWE.movementType = MOVEMENT_TYPE_NONE;
            return templateOWE;
        }
        else if (!validLevel)
        {
            level = MIN_LEVEL;
        }
    }

    if (isShinyTemplate)
        isShiny = isShinyTemplate;

    if (templateOWE.graphicsId & OBJ_EVENT_MON && templateOWE.graphicsId & OBJ_EVENT_MON_FEMALE)
        isFemale = TRUE;
    else if (templateOWE.graphicsId & OBJ_EVENT_MON)
        isFemale = FALSE;
    else
        isFemale = GetGenderFromSpeciesAndPersonality(speciesId, Random32()) == MON_FEMALE;

    if (templateOWE.movementType == MOVEMENT_TYPE_NONE)
        templateOWE.movementType = OWE_GetMovementTypeFromSpecies(speciesId);

    graphicsId = speciesId + OBJ_EVENT_MON;
    if (isFemale)
        graphicsId += OBJ_EVENT_MON_FEMALE;
    if (isShiny)
        graphicsId += OBJ_EVENT_MON_SHINY;

    templateOWE.graphicsId = graphicsId;
    templateOWE.sOverworldEncounterLevel = level;
    
    return templateOWE;
}

struct SpritePalette GetOWESpawnDespawnAnimFldEffPalette(enum SpawnDespawnTypeOWE spawnAnim)
{
    struct SpritePalette palette = gSpritePalette_GeneralFieldEffect0;
    switch (spawnAnim)
    {
    case OWE_SPAWN_ANIM_GRASS:
    case OWE_SPAWN_ANIM_LONG_GRASS:
        palette = gSpritePalette_GeneralFieldEffect1;
        break;

    case OWE_SPAWN_ANIM_WATER:
    case OWE_SPAWN_ANIM_UNDERWATER:
    case OWE_SPAWN_ANIM_CAVE:
    case OWE_SPAWN_ANIM_SHINY:
    default:
        break;
    }

    return palette;
}

static bool32 CheckValidOWESpecies(u32 speciesId)
{
    if (speciesId == SPECIES_NONE)
        return FALSE;

    if (speciesId >= NUM_SPECIES)
        return FALSE;

    if (!IsSpeciesEnabled(speciesId))
        return FALSE;

    return TRUE;
}

#undef sOverworldEncounterLevel
#undef sAge
#undef sRoamerOutbreakStatus
