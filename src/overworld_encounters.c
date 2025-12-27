#include "global.h"
#include "overworld_encounters.h"
#include "battle_setup.h"
#include "battle_main.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "random.h"
#include "roamer.h"
#include "script.h"
#include "sprite.h"
#include "sound.h"
#include "task.h"
#include "wild_encounter.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/map_types.h"
#include "constants/trainer_types.h"
#include "constants/songs.h"
#include "constants/vars.h"
#include "constants/wild_encounter.h"

#define sOverworldEncounterLevel trainerRange_berryTreeId
#define sAge                     playerCopyableMovement
#define sRoamerStatus            directionSequenceIndex

static EWRAM_DATA u8 sOWESpawnCountdown = 0;

static bool8 TrySelectTile(s16* outX, s16* outY);
static u8 NextSpawnMonSlot();
static bool32 OWE_ShouldSpawnWaterMons(void);
static void SetOverworldEncounterSpeciesInfo(s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level);
static bool8 IsSafeToSpawnObjectEvents(void);
static bool32 OWE_CheckActiveEncounterTable(bool32 shouldSpawnWaterMons);
static bool8 CheckForObjectEventAtLocation(s16 x, s16 y);
static u16 GetOverworldSpeciesBySpawnSlot(u32 spawnSlot);
static u32 GetLocalIdByOverworldSpawnSlot(u32 spawnSlot);
static u32 GetSpawnSlotByLocalId(u32 localId);
static void SortOWEMonAges(void);
static bool32 OWE_CanEncounterBeLoaded(u32 speciesId, bool32 isFemale, bool32 isShiny);
static u32 OWE_GetMovementTypeFromSpecies(u32 speciesId);
static void OWE_PlayMonObjectCry(struct ObjectEvent *objectEvent);
static struct ObjectEvent *OWE_GetRandomActiveEncounterObject(void);

static const u32 sOWE_MovementBehaviorType[OWE_BEHAVIOR_COUNT] =
{
    [OWE_BEHAVIOR_WANDER_AROUND] =  MOVEMENT_TYPE_WANDER_AROUND_OWE,
    [OWE_BEHAVIOR_CHASE] =          MOVEMENT_TYPE_CHASE_PLAYER_OWE,
    [OWE_BEHAVIOR_FLEE] =           MOVEMENT_TYPE_FLEE_PLAYER_OWE,
};

void OWE_ResetSpawnCounterPlayAmbientCry(void)
{
    OverworldWildEncounter_SetMinimumSpawnTimer();
    if (OW_WILD_ENCOUNTERS_AMBIENT_CRIES)
        OWE_PlayMonObjectCry(OWE_GetRandomActiveEncounterObject());
}

void UpdateOverworldEncounters(void)
{
    if (!OW_WILD_ENCOUNTERS_OVERWORLD || ArePlayerFieldControlsLocked() || FlagGet(DN_FLAG_SEARCHING))
        return;
    
    if (FlagGet(OW_FLAG_NO_ENCOUNTER))
    {
        if (sOWESpawnCountdown != 255)
        {
            RemoveAllOverworldEncounterObjects();
            sOWESpawnCountdown = 255;
        }

        return;
    }
    else if (sOWESpawnCountdown == 255)
    {
        OverworldWildEncounter_SetMinimumSpawnTimer();
    }

    u16 speciesId = SPECIES_NONE;
    bool32 isShiny = FALSE;
    bool32 isFemale = FALSE;
    u32 roamerIndex = ROAMER_COUNT;
    s16 x, y;

    if (sOWESpawnCountdown != 0)
    {
        sOWESpawnCountdown--;
        return;
    }

    if (!IsSafeToSpawnObjectEvents() || !TrySelectTile(&x, &y))
    {
        OWE_ResetSpawnCounterPlayAmbientCry();
        return;
    }
    
    bool32 shouldSpawnWaterMons = OWE_ShouldSpawnWaterMons();
    if (OWE_CheckActiveEncounterTable(shouldSpawnWaterMons))
    {
        u16 spawnSlot = NextSpawnMonSlot();

        if (spawnSlot == INVALID_SPAWN_SLOT)
        {
            OWE_ResetSpawnCounterPlayAmbientCry();
            return;
        }
        
        u32 localId = GetLocalIdByOverworldSpawnSlot(spawnSlot);
        u32 level;
        u32 graphicsId = GetOverworldEncounterObjectEventGraphicsId(x, y, &speciesId, &isShiny, &isFemale, &level);

        if (TryStartRoamerEncounter())
        {
            roamerIndex = gEncounteredRoamerIndex;
            u32 personality = gSaveBlock1Ptr->roamer[roamerIndex].personality;
            speciesId = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES);
            level = GetMonData(&gEnemyParty[0], MON_DATA_LEVEL);

            // Consolidate next section into a function?
            isShiny = ComputePlayerShinyOdds(personality);
            if (GetGenderFromSpeciesAndPersonality(speciesId, personality) == MON_FEMALE)
                isFemale = TRUE;
            else
                isFemale = FALSE;

            // Consolidate ext section into a function?
            graphicsId = speciesId + OBJ_EVENT_MON;
            if (isFemale)
                graphicsId += OBJ_EVENT_MON_FEMALE;

            if (isShiny)
                graphicsId += OBJ_EVENT_MON_SHINY;

            ZeroEnemyPartyMons();
        }

        if (speciesId == SPECIES_NONE || !IsWildLevelAllowedByRepel(level))
        {
            OWE_ResetSpawnCounterPlayAmbientCry();
            return;
        }
        
        struct ObjectEventTemplate objectEventTemplate = {
            .localId = localId,
            .graphicsId = graphicsId,
            .x = x - MAP_OFFSET,
            .y = y - MAP_OFFSET,
            .elevation = MapGridGetElevationAt(x, y),
            .movementType = OWE_GetMovementTypeFromSpecies(speciesId),
            .trainerType = TRAINER_TYPE_ENCOUNTER,
        };

        if (!OWE_CanEncounterBeLoaded(speciesId, isFemale, isShiny))
        {
            OWE_ResetSpawnCounterPlayAmbientCry();
            return;
        }

        u8 objectEventId = SpawnSpecialObjectEvent(&objectEventTemplate);

        if (objectEventId >= OBJECT_EVENTS_COUNT)
        {
            OWE_ResetSpawnCounterPlayAmbientCry();
            return;
        }

        gObjectEvents[objectEventId].disableCoveringGroundEffects = TRUE;
        gObjectEvents[objectEventId].range.rangeX = OW_ENCOUNTER_MOVEMENT_RANGE_X;
        gObjectEvents[objectEventId].range.rangeY = OW_ENCOUNTER_MOVEMENT_RANGE_Y;
        gObjectEvents[objectEventId].sOverworldEncounterLevel = level;
        gObjectEvents[objectEventId].sRoamerStatus = roamerIndex;

        u8 directions[4] = {DIR_SOUTH, DIR_NORTH, DIR_WEST, DIR_EAST};
        ObjectEventTurn(&gObjectEvents[objectEventId], directions[Random() & 3]);

        // Hide reflections for spawns in water
        // (It just looks weird)
        if (shouldSpawnWaterMons)
            gObjectEvents[objectEventId].hideReflection = TRUE;

        // Slower replacement spawning
        sOWESpawnCountdown = OWE_TIME_BETWEEN_SPAWNS + (Random() % OWE_SPAWN_TIME_VARIABILITY);
    }
}

static bool32 OWE_CanEncounterBeLoaded(u32 speciesId, bool32 isFemale, bool32 isShiny)
{
    u32 numFreePalSlots = CountFreePaletteSlots();

    // We need at least 2 pal slots open. One for the object and one for the spawn field effect.
    // Add this and tiles to seperate graphics check function
    if (numFreePalSlots == 1)
    {
        u32 palTag = speciesId + OBJ_EVENT_MON + (isShiny ? OBJ_EVENT_MON_SHINY : 0);

        if (isFemale && gSpeciesInfo[speciesId].overworldShinyPaletteFemale != NULL)
            palTag += OBJ_EVENT_MON_FEMALE;
            
        // If the mon's palette isn't already loaded, don't spawn.
        if (IndexOfSpritePaletteTag(palTag) == 0xFF)
            return FALSE;

        // Add check if field effect pallete is already loaded
        // Bubbles field effect occurs on every movement
    }
    else if (numFreePalSlots == 0)
    {
        return FALSE;
    }

    return TRUE;
}

void OWE_DoSpawnDespawnAnim(struct ObjectEvent *objectEvent, bool32 spawn)
{
    enum OverworldEncounterSpawnAnim spawnAnimType;
    bool32 isShiny = OW_SHINY(objectEvent) ? TRUE : FALSE;

    if (spawn)
        OWE_PlayMonObjectCry(objectEvent);
    else
        PlaySE(SE_FLEE);

    if (isShiny && spawn)
    {
        PlaySE(SE_SHINY);
        spawnAnimType = OWE_SPAWN_ANIM_SHINY;
    }
    else 
    {
        u32 metatileBehavior = MapGridGetMetatileBehaviorAt(objectEvent->currentCoords.x, objectEvent->currentCoords.y);
        spawnAnimType = OWE_GetDespawnAnimType(metatileBehavior);
    }
    MovementAction_OverworldEncounterSpawn(spawnAnimType, objectEvent);
}

static u8 GetMaxOverworldEncounterSpawns(void)
{
    if (OWE_ShouldSpawnWaterMons())
        return OWE_MAX_WATER_SPAWNS;
    else if (gMapHeader.cave || gMapHeader.mapType == MAP_TYPE_UNDERGROUND)
        return OWE_MAX_CAVE_SPAWNS;
    else
        return OWE_MAX_LAND_SPAWNS;
}

u32 GetOldestSlot(void)
{
    struct ObjectEvent *slotMon, *oldest = &gObjectEvents[GetObjectEventIdByLocalId(LOCALID_OW_ENCOUNTER_END)];
    u32 spawnSlot;

    for (spawnSlot = 0; spawnSlot < OWE_MAX_SPAWN_SLOTS; spawnSlot++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(GetLocalIdByOverworldSpawnSlot(spawnSlot))];
        if (OW_SPECIES(slotMon) != SPECIES_NONE && !OW_SHINY(slotMon))
        {
            oldest = slotMon;
            break;
        }
    }

    if (spawnSlot >= OWE_MAX_SPAWN_SLOTS)
        return INVALID_SPAWN_SLOT;

    for (spawnSlot = 0; spawnSlot < OWE_MAX_SPAWN_SLOTS; spawnSlot++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(GetLocalIdByOverworldSpawnSlot(spawnSlot))];
        if (OW_SPECIES(slotMon) != SPECIES_NONE && !OW_SHINY(slotMon))
        {
            if (slotMon->sAge > oldest->sAge)
                oldest = slotMon;
        }
    }

    return GetSpawnSlotByLocalId(oldest->localId);
}

static u8 NextSpawnMonSlot(void)
{
    u32 spawnSlot;
    u32 maxSpawns = GetMaxOverworldEncounterSpawns();

    // All mon slots are in use
    if (CountActiveOverworldEncounters() >= maxSpawns)
    {
        if (OW_WILD_ENCOUNTERS_SPAWN_REPLACEMENT)
        {
            // Cycle through so we remove the oldest mon first
            spawnSlot = GetOldestSlot();
            if (spawnSlot == INVALID_SPAWN_SLOT)
                return INVALID_SPAWN_SLOT;
        }
        else
        {
            return INVALID_SPAWN_SLOT;
        }
    }
    else
    {
        for (spawnSlot = 0; spawnSlot < maxSpawns; spawnSlot++)
        {
            if (GetOverworldSpeciesBySpawnSlot(spawnSlot) == SPECIES_NONE)
                break;
        }
    }

    if (OW_WILD_ENCOUNTERS_SPAWN_REPLACEMENT)
    {
        u32 localId = GetLocalIdByOverworldSpawnSlot(spawnSlot);
        u32 objectEventId = GetObjectEventIdByLocalId(localId);
        struct ObjectEvent *object = &gObjectEvents[objectEventId];
        RemoveObjectEventByLocalIdAndMap(localId, object->mapNum, object->mapGroup);
    }

    return spawnSlot;
}

static bool8 TrySelectTile(s16* outX, s16* outY)
{
    u8 elevation;
    u16 tileBehavior;
    s16 playerX, playerY;
    s16 x, y;
    u8 closeDistance;
    bool32 isEncounterTile = FALSE;
    const struct MapLayout *layout;

    // Spawn further away when surfing
    if (OWE_ShouldSpawnWaterMons())
        closeDistance = OWE_SPAWN_DISTANCE_WATER;
    else
        closeDistance = OWE_SPAWN_DISTANCE_LAND;

    // Select a random tile in [-7, -4] [7, 4] range
    // Make sure is not directly next to player
    do
    {
        x = (s16)(Random() % OWE_TOTAL_SPAWN_WIDTH) - OWE_SPAWN_RADUIS_WIDTH;
        y = (s16)(Random() % OWE_TOTAL_SPAWN_HEIGHT) - OWE_SPAWN_RADUIS_HEIGHT;
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
    }
    
    PlayerGetDestCoords(&playerX, &playerY);
    x += playerX;
    y += playerY;

    elevation = MapGridGetElevationAt(x, y);

    layout = Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum)->mapLayout;
    if ((x - MAP_OFFSET) < 0 || (x - MAP_OFFSET) >= layout->width ||
        (y - MAP_OFFSET) < 0 || (y - MAP_OFFSET) >= layout->height)
        return FALSE;

    // 0 is change of elevation, 15 is multiple elevation e.g. bridges
    // Causes weird interaction issues so just don't let mons spawn here
    if (elevation == 0 || elevation == 15)
        return FALSE;

    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    if (OWE_ShouldSpawnWaterMons() && MetatileBehavior_IsWaterWildEncounter(tileBehavior))
        isEncounterTile = TRUE;

    if (!OWE_ShouldSpawnWaterMons() && (MetatileBehavior_IsLandWildEncounter(tileBehavior) || MetatileBehavior_IsIndoorEncounter(tileBehavior)))
        isEncounterTile = TRUE;

    if (isEncounterTile && !MapGridGetCollisionAt(x, y))
    {
        *outX = x;
        *outY = y;

        if (!CheckForObjectEventAtLocation(x, y))
            return TRUE;
    }

    return FALSE;
}

void CreateOverworldWildEncounter(void)
{
    u32 localId = gSpecialVar_LastTalked;
    u32 objEventId = GetObjectEventIdByLocalId(localId);
    struct ObjectEvent *object = &gObjectEvents[objEventId];

    if (objEventId >= OBJECT_EVENTS_COUNT)
        return;

    if (!IsOverworldWildEncounter(object))
        return;

    if (object->sRoamerStatus < ROAMER_COUNT)
    {
        CreateRoamerMonInstance(object->sRoamerStatus);
        gEncounteredRoamerIndex = object->sRoamerStatus;
        BattleSetup_StartRoamerBattle();
        return;
    }

    u16 speciesId = OW_SPECIES(object);
    bool32 shiny = OW_SHINY(object) ? TRUE : FALSE;
    bool32 isFemale = OW_FEMALE(object) ? TRUE : FALSE;
    u32 level = object->sOverworldEncounterLevel;

    if (level > MAX_LEVEL)
        level = MAX_LEVEL;
    else if ( level < MIN_LEVEL)
        level = MIN_LEVEL;

    ZeroEnemyPartyMons();
    CreateMonWithGender(
        &gEnemyParty[0],
        speciesId,
        level,
        USE_RANDOM_IVS,
        OT_ID_PLAYER_ID,
        0,
        isFemale
    );
    SetMonData(&gEnemyParty[0], MON_DATA_IS_SHINY, &shiny);
    BattleSetup_StartWildBattle();
}

struct AgeSort
{
    u8 slot:4;
    u8 age:4;
};

static void SortOWEMonAges(void)
{
    struct ObjectEvent *slotMon;
    struct AgeSort array[OWE_MAX_SPAWN_SLOTS];
    struct AgeSort current;
    u32 numActive = CountActiveOverworldEncounters();
    u32 count = 0;
    s32 i, j;

    for (i = 0; i < OWE_MAX_SPAWN_SLOTS; i++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(GetLocalIdByOverworldSpawnSlot(i))];
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
    slotMon = &gObjectEvents[GetObjectEventIdByLocalId(GetLocalIdByOverworldSpawnSlot(array[0].slot))];
    slotMon->sAge = numActive;

    for (i = 1; i < numActive; i++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(GetLocalIdByOverworldSpawnSlot(array[i].slot))];
        array[i].age = array[i - 1].age - 1;
        slotMon->sAge = array[i].age;
    }
}

void OverworldWildEncounter_OnObjectEventSpawned(struct ObjectEvent *objectEvent)
{
    if (!IsOverworldWildEncounter(objectEvent))
        return;
    
    if (IsGeneratedOverworldWildEncounter(objectEvent))
        SortOWEMonAges();

    OWE_DoSpawnDespawnAnim(objectEvent, TRUE);
}

void OverworldWildEncounter_OnObjectEventRemoved(struct ObjectEvent *objectEvent)
{
    if (!IsOverworldWildEncounter(objectEvent))
        return;
    
    if (gMain.callback2 != CB2_InitBattle)
        OWE_DoSpawnDespawnAnim(objectEvent, FALSE);
}

u32 GetOverworldEncounterObjectEventGraphicsId(s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level)
{
    SetOverworldEncounterSpeciesInfo(x, y, speciesId, isShiny, isFemale, level);
    u16 graphicsId = *speciesId + OBJ_EVENT_MON;

    if (*isFemale)
        graphicsId += OBJ_EVENT_MON_FEMALE;

    if (*isShiny)
        graphicsId += OBJ_EVENT_MON_SHINY;

    return graphicsId;
}

void OverworldWildEncounter_SetMinimumSpawnTimer(void)
{
    sOWESpawnCountdown = OWE_SPAWN_TIME_MINIMUM;
}

static void SetOverworldEncounterSpeciesInfo(s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level)
{
    const struct WildPokemonInfo *wildMonInfo;
    enum WildPokemonArea wildArea;
    enum TimeOfDay timeOfDay;
    u32 personality;
    u32 headerId = GetCurrentMapWildMonHeaderId();

    if (MetatileBehavior_IsWaterWildEncounter(MapGridGetMetatileBehaviorAt(x, y)))
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

    if (!TryGenerateWildMon(wildMonInfo, wildArea, WILD_CHECK_REPEL | WILD_CHECK_KEEN_EYE))
    {
        *speciesId = SPECIES_NONE;
        return;
    }

    *speciesId = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES);
    *level = GetMonData(&gEnemyParty[0], MON_DATA_LEVEL);
    personality = GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY);

    if (*speciesId == SPECIES_UNOWN)
        *speciesId = GetUnownSpeciesId(personality);

    *isShiny = ComputePlayerShinyOdds(personality);
    if (GetGenderFromSpeciesAndPersonality(*speciesId, personality) == MON_FEMALE)
        *isFemale = TRUE;
    else
        *isFemale = FALSE;

    ZeroEnemyPartyMons();
}

static bool8 IsSafeToSpawnObjectEvents(void)
{
    // Can this just be a check for player not moving?
    struct ObjectEvent* player = &gObjectEvents[gPlayerAvatar.objectEventId];

    // Only spawn when player is at a valid tile position
    return (player->currentCoords.x == player->previousCoords.x && player->currentCoords.y == player->previousCoords.y);
}

u8 CountActiveOverworldEncounters(void)
{
    u32 count = 0;
    for (u32 spawnSlot = 0; spawnSlot < OWE_MAX_SPAWN_SLOTS; spawnSlot++)
    {
        if (GetOverworldSpeciesBySpawnSlot(spawnSlot) != SPECIES_NONE)
            count++;
    }

    return count;
}

static bool32 OWE_ShouldSpawnWaterMons(void)
{
    // Needs refactoring, and this replacing with a check for coords in many cases.
    return TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING | PLAYER_AVATAR_FLAG_UNDERWATER);
}

void RemoveAllOverworldEncounterObjects(void)
{
    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; ++i)
    {
        struct ObjectEvent *obj = &gObjectEvents[i];
        if (IsGeneratedOverworldWildEncounter(obj))
            RemoveObjectEventByLocalIdAndMap(obj->localId, obj->mapNum, obj->mapGroup);
    }
}

static bool8 CheckForObjectEventAtLocation(s16 x, s16 y)
{
    for (u8 i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active && gObjectEvents[i].currentCoords.x == x
            && gObjectEvents[i].currentCoords.y == y)
            return TRUE;
    }

    return FALSE;
}

static bool32 OWE_CheckActiveEncounterTable(bool32 shouldSpawnWaterMons)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay;

    if (headerId == HEADER_NONE)
        return FALSE;

    if (shouldSpawnWaterMons)
    {
        timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_WATER);
        return gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo != NULL;
    }

    timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
    return gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo != NULL;
}

bool32 IsOverworldWildEncounter(struct ObjectEvent *objectEvent)
{
    return (objectEvent->graphicsId & OBJ_EVENT_MON) && (objectEvent->trainerType == TRAINER_TYPE_ENCOUNTER);
}

bool32 IsGeneratedOverworldWildEncounter(struct ObjectEvent *objectEvent)
{
    return IsOverworldWildEncounter(objectEvent)
        && (objectEvent->localId <= LOCALID_OW_ENCOUNTER_END
        && objectEvent->localId > (LOCALID_OW_ENCOUNTER_END - OWE_MAX_SPAWN_SLOTS));
}

bool32 IsManualOverworldWildEncounter(struct ObjectEvent *objectEvent)
{
    return IsOverworldWildEncounter(objectEvent)
        && (objectEvent->localId > LOCALID_OW_ENCOUNTER_END
        || objectEvent->localId <= (LOCALID_OW_ENCOUNTER_END - OWE_MAX_SPAWN_SLOTS));
}

bool32 IsSemiManualOverworldWildEncounter(u32 graphicsId, u32 trainerType)
{
    return graphicsId == OBJ_EVENT_GFX_OVERWORLD_ENCOUNTER && trainerType == TRAINER_TYPE_ENCOUNTER;
}

static u16 GetOverworldSpeciesBySpawnSlot(u32 spawnSlot)
{
    u32 objEventId = GetObjectEventIdByLocalId(GetLocalIdByOverworldSpawnSlot(spawnSlot));
    struct ObjectEvent *objectEvent = &gObjectEvents[objEventId];

    if (objEventId >= OBJECT_EVENTS_COUNT)
        return SPECIES_NONE;

    return OW_SPECIES(objectEvent);
}

static u32 GetLocalIdByOverworldSpawnSlot(u32 spawnSlot)
{
    return LOCALID_OW_ENCOUNTER_END - spawnSlot;
}

static u32 GetSpawnSlotByLocalId(u32 localId)
{
    return LOCALID_OW_ENCOUNTER_END - localId;
}

u32 GetNewestOWEncounterLocalId(void)
{
    struct ObjectEvent *slotMon;
    struct ObjectEvent *newest = &gObjectEvents[GetObjectEventIdByLocalId(LOCALID_OW_ENCOUNTER_END)];
    u32 i;
    
    for (i = 0; i < OWE_MAX_SPAWN_SLOTS; i++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(GetLocalIdByOverworldSpawnSlot(i))];
        if (OW_SPECIES(slotMon) != SPECIES_NONE)
        {
            if (newest->sAge > slotMon->sAge)
                newest = slotMon;
        }
    }

    return GetSpawnSlotByLocalId(newest->localId);
}

bool32 CanRemoveOverworldEncounter(u32 localId)
{
    // Include a check for the encounter not being shiny or a roamer.
    return (OW_WILD_ENCOUNTERS_OVERWORLD && CountActiveOverworldEncounters() != 0
        && (localId <= (LOCALID_OW_ENCOUNTER_END - OWE_MAX_SPAWN_SLOTS + 1)
        || localId > LOCALID_OW_ENCOUNTER_END));
}

u32 RemoveOldestOverworldEncounter(void)
{
    u32 oldestSlot = GetOldestSlot();

    if (oldestSlot == INVALID_SPAWN_SLOT)
        return OBJECT_EVENTS_COUNT;

    u32 localId = GetLocalIdByOverworldSpawnSlot(oldestSlot);
    u32 objectEventId = GetObjectEventIdByLocalId(localId);
    struct ObjectEvent *object = &gObjectEvents[objectEventId];
    u32 fldEffSpriteId = object->fieldEffectSpriteId;

    // Stop the associated field effect if it is active.
    if (fldEffSpriteId != 0)
    {
        FieldEffectStop(&gSprites[fldEffSpriteId], FLDEFF_OW_ENCOUNTER_SPAWN_ANIM);
        object->fieldEffectSpriteId = 0;
    }

    RemoveObjectEventByLocalIdAndMap(localId, object->mapNum, object->mapGroup);
    return objectEventId;
}

bool32 TryAndRemoveOldestOverworldEncounter(u32 localId, u8 *objectEventId)
{
    if (CanRemoveOverworldEncounter(localId))
    {
        *objectEventId = RemoveOldestOverworldEncounter();

        if (*objectEventId == OBJECT_EVENTS_COUNT)
            return TRUE;
        else
            return FALSE;
    }
    
    return TRUE;
}

bool32 ShouldRunOverworldEncounterScript(u32 objectEventId)
{
    struct ObjectEvent *object = &gObjectEvents[objectEventId];

    if (IsGeneratedOverworldWildEncounter(object)
        || (IsManualOverworldWildEncounter(object) && GetObjectEventScriptPointerByObjectEventId(objectEventId) == NULL))
    {
        gSpecialVar_0x8004 = OW_SPECIES(object);
        return TRUE;
    }

    return FALSE;
}

struct ObjectEventTemplate TryGetObjectEventTemplateForOverworldEncounter(const struct ObjectEventTemplate *template)
{
    if (!IsSemiManualOverworldWildEncounter(template->graphicsId, template->trainerType))
        return *template;

    struct ObjectEventTemplate templateOWE = *template;
    
    // Does this work?
    u32 graphicsId;
    u16 speciesId;
    bool32 isShiny = FALSE;
    bool32 isFemale = FALSE;
    u32 level;

    SetOverworldEncounterSpeciesInfo(
        template->x - MAP_OFFSET,
        template->y - MAP_OFFSET,
        &speciesId,
        &isShiny,
        &isFemale,
        &level
    );
    // Have a fallback incase of no header mons

    graphicsId = speciesId + OBJ_EVENT_MON;
    if (isFemale)
        graphicsId += OBJ_EVENT_MON_FEMALE;
    if (isShiny)
        graphicsId += OBJ_EVENT_MON_SHINY;

    templateOWE.graphicsId = graphicsId;
    templateOWE.sOverworldEncounterLevel = level;
    templateOWE.trainerType = TRAINER_TYPE_ENCOUNTER;
    return templateOWE;
}

#define tLocalId           gTasks[taskId].data[0]

void OWE_TryTriggerEncounter(struct ObjectEvent *obstacle, struct ObjectEvent *collider)
{
    // The only automatically interacts with an OW Encounter when;
    // Not using a repel or the DexNav is inactive.
    if (/* VarGet(VAR_REPEL_STEP_COUNT) > 0 || */ FlagGet(DN_FLAG_SEARCHING))
        return;

    bool32 playerIsCollider = (collider->isPlayer && IsOverworldWildEncounter(obstacle));
    bool32 playerIsObstacle = (obstacle->isPlayer && IsOverworldWildEncounter(collider));

    if ((playerIsCollider || playerIsObstacle) && FindTaskIdByFunc(Task_OWE_WaitMovements) == TASK_NONE)
    {
        struct ObjectEvent *wildMon = playerIsCollider ? obstacle : collider;

        LockPlayerFieldControls();
        // Wait for both the player and the mon to finish their current movements.
        u8 taskId = CreateTask(Task_OWE_WaitMovements, 0);
        tLocalId = wildMon->localId;
    }
}

void TryRemoveOverworldWildEncounter(u32 localId)
{
    struct ObjectEvent *object = &gObjectEvents[GetObjectEventIdByLocalId(gSpecialVar_LastTalked)];
    
    if (IsOverworldWildEncounter(object))
    {
        RemoveObjectEventByLocalIdAndMap(localId, object->mapNum, object->mapGroup);
        gSpecialVar_LastTalked = LOCALID_NONE;
    }
}

bool32 OWE_CheckRestrictedMovement(struct ObjectEvent *objectEvent, u32 direction)
{
    s16 xCurrent = objectEvent->currentCoords.x;
    s16 yCurrent = objectEvent->currentCoords.y;
    s16 xNew = xCurrent + gDirectionToVectors[direction].x;
    s16 yNew = yCurrent + gDirectionToVectors[direction].y;
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

    return TRUE;
}

void DespawnOldestOWE_Pal(void)
{
    // Should have similar naming convention for these despawn functions based on Num Object Events, Pals & Tiles
    if (OW_WILD_ENCOUNTERS_OVERWORLD && CountFreePaletteSlots() < 2)
    {
        u32 count = CountActiveOverworldEncounters();

        if (count > 0)
        {
            for (; count > 0; count--)
            {
                RemoveOldestOverworldEncounter();
                if (CountFreePaletteSlots() >= 2)
                    break;
            }
        }
    }
}

bool32 OWE_CanMonSeePlayer(struct ObjectEvent *mon)
{
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_DASH) || (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_BIKE) && gPlayerAvatar.runningState == MOVING))
    {
        if (OWE_IsPlayerInsideRangeFromMon(mon, OWE_MON_SIGHT_LENGTH))
            return TRUE;
    }
    else
    {
        switch (mon->facingDirection)
        {
        case DIR_NORTH:
            if (player->currentCoords.y < mon->currentCoords.y && (mon->currentCoords.y - player->currentCoords.y) <= OWE_MON_SIGHT_LENGTH
             && player->currentCoords.x >= (mon->currentCoords.x - ((OWE_MON_SIGHT_WIDTH - 1) / 2)) && player->currentCoords.x <= (mon->currentCoords.x + ((OWE_MON_SIGHT_WIDTH - 1) / 2)))
                return TRUE;
            break;
        case DIR_SOUTH:
            if (player->currentCoords.y > mon->currentCoords.y && (player->currentCoords.y - mon->currentCoords.y) <= OWE_MON_SIGHT_LENGTH
             && player->currentCoords.x >= (mon->currentCoords.x - ((OWE_MON_SIGHT_WIDTH - 1) / 2)) && player->currentCoords.x <= (mon->currentCoords.x + ((OWE_MON_SIGHT_WIDTH - 1) / 2)))
                return TRUE;
            break;
        case DIR_EAST:
            if (player->currentCoords.x > mon->currentCoords.x && (player->currentCoords.x - mon->currentCoords.x) <= OWE_MON_SIGHT_LENGTH
             && player->currentCoords.y >= (mon->currentCoords.y - ((OWE_MON_SIGHT_WIDTH - 1) / 2)) && player->currentCoords.y <= (mon->currentCoords.y + ((OWE_MON_SIGHT_WIDTH - 1) / 2)))
                return TRUE;
            break;
        case DIR_WEST:
            if (player->currentCoords.x < mon->currentCoords.x && (mon->currentCoords.x - player->currentCoords.x) <= OWE_MON_SIGHT_LENGTH
             && player->currentCoords.y >= (mon->currentCoords.y - ((OWE_MON_SIGHT_WIDTH - 1) / 2)) && player->currentCoords.y <= (mon->currentCoords.y + ((OWE_MON_SIGHT_WIDTH - 1) / 2)))
                return TRUE;
            break;
        }
    }

    return FALSE;
}

bool32 OWE_IsPlayerInsideRangeFromMon(struct ObjectEvent *mon, u32 distance)
{
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (player->currentCoords.y <= mon->currentCoords.y + distance && player->currentCoords.y >= mon->currentCoords.y - distance
     && player->currentCoords.x <= mon->currentCoords.x + distance && player->currentCoords.x >= mon->currentCoords.x - distance)
        return TRUE;

    return FALSE;
}

u32 OWE_DirectionToPlayerFromCollision(struct ObjectEvent *mon)
{
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];

    switch (mon->movementDirection)
    {
    case DIR_NORTH:
    case DIR_SOUTH:
        if (player->currentCoords.x < mon->currentCoords.x)
            return DIR_WEST;
        else if (player->currentCoords.x == mon->currentCoords.x)
            return (Random() % 2) == 0 ? DIR_EAST : DIR_WEST;
        else
            return DIR_EAST;
    case DIR_EAST:
    case DIR_WEST:
        if (player->currentCoords.y < mon->currentCoords.y)
            return DIR_NORTH;
        else if (player->currentCoords.y == mon->currentCoords.y)
            return (Random() % 2) == 0 ? DIR_NORTH : DIR_SOUTH;
        else
            return DIR_SOUTH;
    }

    return mon->movementDirection;
}

bool32 OWE_IsMonNextToPlayer(struct ObjectEvent *mon)
{
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];

    if ((mon->currentCoords.x != player->currentCoords.x && mon->currentCoords.y != player->currentCoords.y) || (mon->currentCoords.x < player->currentCoords.x - 1 || mon->currentCoords.x > player->currentCoords.x + 1 || mon->currentCoords.y < player->currentCoords.y - 1 || mon->currentCoords.y > player->currentCoords.y + 1))
        return FALSE;

    return TRUE;
}

#define tTaskStarted        gTasks[taskId].data[1]
#define sSpriteTaskState    gSprites[mon->spriteId].data[6]
#define NOT_STARTED         0
#define STARTED             1

void Task_OWE_WaitMovements(u8 taskId)
{
    struct ObjectEvent *mon = &gObjectEvents[GetObjectEventIdByLocalId(tLocalId)];
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    
    if (tTaskStarted == NOT_STARTED)
    {
        sSpriteTaskState = STARTED;
        tTaskStarted = STARTED;
    }

    if (mon->singleMovementActive == 0 && player->singleMovementActive == 0)
    {
        // Let the mon continue to take steps until right next to the player.
        if (OWE_IsMonNextToPlayer(mon))
        {
            gSpecialVar_LastTalked = tLocalId;
            gSpecialVar_0x8004 = OW_SPECIES(&gObjectEvents[GetObjectEventIdByLocalId(tLocalId)]);
            ScriptContext_SetupScript(InteractWithDynamicWildOverworldEncounter);
            FreezeObjectEvent(mon);
            DestroyTask(taskId);
        }
    }
}

u32 OWE_GetDespawnAnimType(u32 metatileBehavior)
{
    // Need to edit anims:
    // If object is on water then use water anim.
    // If object is indoor, need an indoor anim?
    // Long grass anim?

    if (MetatileBehavior_IsPokeGrass(metatileBehavior) || MetatileBehavior_IsAshGrass(metatileBehavior))
        return OWE_SPAWN_ANIM_GRASS;
    else if (MetatileBehavior_IsSurfableFishableWater(metatileBehavior))
        return OWE_SPAWN_ANIM_WATER;
    else
        return OWE_SPAWN_ANIM_CAVE;
}

static struct ObjectEvent *OWE_GetRandomActiveEncounterObject(void)
{
    return &gObjectEvents[gPlayerAvatar.objectEventId];
}


static u32 OWE_GetMovementTypeFromSpecies(u32 speciesId)
{
    return MOVEMENT_TYPE_WANDER_AROUND_OWE; // Replace for Testing
    return sOWE_MovementBehaviorType[gSpeciesInfo[speciesId].overworldEncounterBehavior];
}

// Are these needed? Not defined elsewhere? I don't think so.
#define MAP_METATILE_VIEW_X 7
#define MAP_METATILE_VIEW_Y 5
static void OWE_PlayMonObjectCry(struct ObjectEvent *objectEvent)
{
    if (!IS_OW_MON_OBJ(objectEvent))
        return;
    
    u32 speciesId = OW_SPECIES(objectEvent);
    u32 volume;
    s32 pan;
    s32 distanceX = objectEvent->currentCoords.x - gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x;
    s32 distanceY = objectEvent->currentCoords.y - gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y;

    // TESTING: Setting this species can be used as a test to play a consistent sound to check how often the
    //          code in UpdateOverworldEncounters runs, as OWE_GetRandomActiveEncounterObject cuurently returns
    //          the player object.
    if (objectEvent->isPlayer)
        speciesId = SPECIES_NONE;

    if (distanceX > MAP_METATILE_VIEW_X)
        distanceX = MAP_METATILE_VIEW_X;
    else if (distanceX < -MAP_METATILE_VIEW_X)
        distanceX = -MAP_METATILE_VIEW_X;

    if (distanceY > MAP_METATILE_VIEW_Y)
        distanceY = MAP_METATILE_VIEW_Y;
    else if (distanceY < -MAP_METATILE_VIEW_Y)
        distanceY = -MAP_METATILE_VIEW_Y;

    pan = (distanceX * 44) / MAP_METATILE_VIEW_X;
    volume = 50 + ((distanceY + MAP_METATILE_VIEW_Y) * 30) / (2 * MAP_METATILE_VIEW_Y);
    
    PlayCry_NormalNoDucking(speciesId, pan, volume, CRY_PRIORITY_AMBIENT);
}
#undef MAP_METATILE_VIEW_X
#undef MAP_METATILE_VIEW_Y

#undef tLocalId
#undef tTaskStarted
#undef sSpriteTaskState
#undef NOT_STARTED
#undef STARTED
#undef sOverworldEncounterLevel
#undef sAge
#undef sRoamerStatus
