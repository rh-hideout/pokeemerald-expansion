#include "global.h"
#include "overworld_encounters.h"
#include "battle_setup.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "random.h"
#include "script.h"
#include "sprite.h"
#include "sound.h"
#include "wild_encounter.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/map_types.h"
#include "constants/trainer_types.h"
#include "constants/songs.h"
#include "constants/vars.h"

static EWRAM_DATA struct FollowMonData sFollowMonData = { 0 };

static bool8 TrySelectTile(s16* outX, s16* outY);
static u8 NextSpawnMonSlot();
static bool8 IsSpawningWaterMons();
static void SetOverworldEncounterSpeciesInfo(u32 spawnSlot, s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale);
static u8 CountActiveObjectEvents();
static bool8 IsSafeToSpawnObjectEvents(void);
static const struct WildPokemonInfo *GetActiveEncounterTable(bool8 onWater);
static bool8 CheckForObjectEventAtLocation(s16 x, s16 y);
static void GetMapSize(u8 mapGroup, u8 mapNum, s32 *width, s32 *height);
static bool32 IsInsideMap(u8 mapGroup, u8 mapNum, s16 x, s16 y);
static bool32 IsInsidePlayerMap(s16 x, s16 y);
static void OverworldEncounters_ProcessMonInteraction(void);
static u16 GetOverworldSpeciesBySpawnSlot(u32 spawnSlot);
static u32 GetLocalIdByOverworldSpawnSlot(u32 spawnSlot);
static u32 GetSpawnSlotByLocalId(u32 localId);
static bool32 CanRemoveOverworldEncounter(u32 localId);
static void RemoveOldestOverworldEncounter(u8 *objectEventId);
static void SortOWEMonAges(void);
static void RemoveOverworldEncounterObject(struct ObjectEvent *objectEvent);

void LoadFollowMonData(struct ObjectEvent *objectEvent)
{
    sFollowMonData.spawnCountdown += 60;
}

void UpdateOverworldEncounters(void)
{
    if (ArePlayerFieldControlsLocked())
        return;
    
    if (!OW_WILD_ENCOUNTERS_OVERWORLD || FlagGet(OW_FLAG_NO_ENCOUNTER)) // Need check for if header has encounters?
    {
        RemoveAllOverworldEncounterObjects();
        // Zero sFollowMonData ;
        u8 *raw = (u8 *)&sFollowMonData;
        for (u32 i = 0; i < sizeof(struct FollowMonData); i++)
        {
            raw[i] = 0;
        }

        return;
    }

    u16 speciesId = SPECIES_NONE;
    bool32 isShiny = FALSE;
    bool32 isFemale = FALSE;

    OverworldEncounters_ProcessMonInteraction();

    if(sFollowMonData.spawnCountdown == 0)
    {
        s16 x, y;
        const struct WildPokemonInfo *wildMonInfo = NULL;

        wildMonInfo = GetActiveEncounterTable(IsSpawningWaterMons());

        if(wildMonInfo && IsSafeToSpawnObjectEvents() && TrySelectTile(&x, &y))
        {
            u16 spawnSlot = NextSpawnMonSlot();

            if (spawnSlot != INVALID_SPAWN_SLOT)
            {
                bool32 waterMons = IsSpawningWaterMons();
                bool32 indoors = gMapHeader.mapType == MAP_TYPE_INDOOR;
                u32 localId = GetLocalIdByOverworldSpawnSlot(spawnSlot);
                u32 movementType;
                if (OW_WILD_ENCOUNTERS_RESTRICTED_MOVEMENT) // These checks need to be improved
                {
                    if (waterMons)
                        movementType = MOVEMENT_TYPE_WANDER_ON_WATER_ENCOUNTER;
                    else if (indoors)
                        movementType = MOVEMENT_TYPE_WANDER_ON_INDOOR_ENCOUNTER;
                    else
                        movementType = MOVEMENT_TYPE_WANDER_ON_LAND_ENCOUNTER;
                }
                else
                {
                    movementType = MOVEMENT_TYPE_WANDER_ON_MAP;
                }
                
                struct ObjectEventTemplate objectEventTemplate = {
                    .localId = localId,
                    .graphicsId = GetFollowMonObjectEventGraphicsId(spawnSlot, x, y, &speciesId, &isShiny, &isFemale),
                    .x = x - MAP_OFFSET,
                    .y = y - MAP_OFFSET,
                    .elevation = MapGridGetElevationAt(x, y),
                    .movementType = movementType,
                    .trainerType = TRAINER_TYPE_ENCOUNTER,
                };

                u8 objectEventId = SpawnSpecialObjectEvent(&objectEventTemplate);

                gObjectEvents[objectEventId].disableCoveringGroundEffects = TRUE;
                gObjectEvents[objectEventId].range.rangeX = 8;
                gObjectEvents[objectEventId].range.rangeY = 8;

                // Hide reflections for spawns in water
                // (It just looks weird)
                if (waterMons)
                    gObjectEvents[objectEventId].hideReflection = TRUE;

                // Slower replacement spawning
                sFollowMonData.spawnCountdown = 60 * (3 + Random() % 2);
            }
        }
    }
    else
    {
        --sFollowMonData.spawnCountdown;
    }

    // Play spawn animation when player is close enough
    if(sFollowMonData.pendingSpawnAnim != 0)
    {
        u32 spawnSlot = sFollowMonData.pendingSpawnAnim - 1;
        u32 objEventId = GetObjectEventIdByLocalId(GetLocalIdByOverworldSpawnSlot(spawnSlot));
        enum FollowMonSpawnAnim spawnAnimType;

        if (speciesId != SPECIES_NONE)
        {
            if (isShiny)
            {
                PlaySE(SE_SHINY);
                spawnAnimType = FOLLOWMON_SPAWN_ANIM_SHINY;
            }
            else 
            {
                PlayCry_Normal(speciesId, 25); 
                if (IsSpawningWaterMons())
                    spawnAnimType = FOLLOWMON_SPAWN_ANIM_WATER;
                else if (gMapHeader.cave || gMapHeader.mapType == MAP_TYPE_UNDERGROUND)
                    spawnAnimType = FOLLOWMON_SPAWN_ANIM_CAVE;
                else
                    spawnAnimType = FOLLOWMON_SPAWN_ANIM_GRASS;
            }
            // Instantly play a small animation to ground the spawning a bit
            MovementAction_FollowMonSpawn(spawnAnimType, &gObjectEvents[objEventId]);
            sFollowMonData.pendingSpawnAnim = 0;
        }
    }
}

static u8 GetMaxFollowMonSpawns(void)
{
    if (IsSpawningWaterMons())
        return OWE_MAX_WATER_SPAWNS;
    else if (gMapHeader.cave || gMapHeader.mapType == MAP_TYPE_UNDERGROUND)
        return OWE_MAX_CAVE_SPAWNS;
    else
        return OWE_MAX_LAND_SPAWNS;
}

u32 GetOldestSlot(void)
{
    u32 oldest = 0;

    for (u32 spawnSlot = 0; spawnSlot < FOLLOWMON_MAX_SPAWN_SLOTS; spawnSlot++)
    {
        if (GetOverworldSpeciesBySpawnSlot(spawnSlot) != SPECIES_NONE)
        {
            if (sFollowMonData.list[spawnSlot].age > sFollowMonData.list[oldest].age)
                oldest = spawnSlot;
        }
    }

    return oldest;
}

static u8 NextSpawnMonSlot(void)
{
    u32 spawnSlot;
    u32 maxSpawns = GetMaxFollowMonSpawns();

    // All mon slots are in use
    if (CountActiveFollowMon() >= maxSpawns)
    {
        // Cycle through so we remove the oldest mon first
        spawnSlot = GetOldestSlot();
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
        // Remove any existing id by this slot
        RemoveObjectEventByLocalIdAndMap(GetLocalIdByOverworldSpawnSlot(spawnSlot), gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
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

    // Spawn further away when surfing
    if(IsSpawningWaterMons())
        closeDistance = 3;
    else
        closeDistance = 1;

    // Select a random tile in [-7, -4] [7, 4] range
    // Make sure is not directly next to player
    do
    {
        x = (s16)(Random() % 15) - 7;
        y = (s16)(Random() % 9) - 4;
    }
    while (abs(x) <= closeDistance && abs(y) <= closeDistance);

    // We won't spawn mons in in the immediate facing direction
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

    if (!IsInsidePlayerMap(x, y))
        return FALSE;

    // 0 is change of elevation, 15 is multiple elevation e.g. bridges
    // Causes weird interaction issues so just don't let mons spawn here
    if (elevation == 0 || elevation == 15)
        return FALSE;

    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    if(IsSpawningWaterMons())
    {
        if(MetatileBehavior_IsWaterWildEncounter(tileBehavior) && !MapGridGetCollisionAt(x, y))
        {
            *outX = x;
            *outY = y;

            if(!CheckForObjectEventAtLocation(x, y))
                return TRUE;
        }
    }
    else
    {
        if(MetatileBehavior_IsLandWildEncounter(tileBehavior) && !MapGridGetCollisionAt(x, y))
        {
            *outX = x;
            *outY = y;

            if(!CheckForObjectEventAtLocation(x, y))
                return TRUE;
        }
    }

    return FALSE;
}

void CreateFollowMonEncounter(void)
{
    u32 localId = gSpecialVar_LastTalked;
    u32 objEventId = GetObjectEventIdByLocalIdAndMap(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    struct ObjectEvent *object = &gObjectEvents[objEventId];

    if (objEventId >= OBJECT_EVENTS_COUNT)
        return;

    if (!IsGeneratedOverworldEncounter(object))
        return;

    u32 slot = GetSpawnSlotByLocalId(localId);
    u16 speciesId = OW_SPECIES(object);
    bool32 shiny = OW_SHINY(object) ? TRUE : FALSE;
    bool32 isFemale = OW_FEMALE(object) ? TRUE : FALSE;

    ZeroEnemyPartyMons();
    CreateMonWithGender(
        &gEnemyParty[0],
        speciesId,
        sFollowMonData.list[slot].level,
        USE_RANDOM_IVS,
        OT_ID_PLAYER_ID,
        0,
        isFemale
    );
    SetMonData(&gEnemyParty[0], MON_DATA_IS_SHINY, &shiny);
}

static void OverworldEncounters_ProcessMonInteraction(void)
{
    u8 i;
    struct ObjectEvent *object;
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        object = &gObjectEvents[i];
        if (IsGeneratedOverworldEncounter(object) && object->active && object != player
            && ((object->currentCoords.x == player->currentCoords.x && object->currentCoords.y == player->currentCoords.y)
            || (object->previousCoords.x == player->currentCoords.x && object->previousCoords.y == player->currentCoords.y))
            && AreElevationsCompatible(object->currentElevation, player->currentElevation))
        {
            gSpecialVar_LastTalked = object->localId;
            ScriptContext_SetupScript(InteractWithDynamicWildFollowMon);
        }
    }
}

bool32 OverworldEncounter_IsCollisionExempt(struct ObjectEvent* obstacle, struct ObjectEvent* collider)
{
    // The player is only exempt from collisions with overworld encounters when not using a repel.
    // Non-player, non-overworld encounters are not collision exempt with overworld encounters.

    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (collider == player && IsGeneratedOverworldEncounter(obstacle) /* && VarGet(VAR_REPEL_STEP_COUNT) == 0 */)
        return TRUE;

    if (obstacle == player && IsGeneratedOverworldEncounter(collider) /* && VarGet(VAR_REPEL_STEP_COUNT) == 0 */)
        return TRUE;
    
    if (!IsGeneratedOverworldEncounter(collider) && IsGeneratedOverworldEncounter(obstacle))
        return TRUE;

    return FALSE;
}

struct AgeSort
{
    u8 slot:4;
    u8 age:4;
};

static void SortOWEMonAges(void)
{
    struct AgeSort array[FOLLOWMON_MAX_SPAWN_SLOTS];
    struct AgeSort current;
    u32 numActive = CountActiveFollowMon();
    u32 count = 0;
    s32 i, j;

    for (i = 0; i < FOLLOWMON_MAX_SPAWN_SLOTS; i++)
    {
        if (GetOverworldSpeciesBySpawnSlot(i) != SPECIES_NONE)
        {
            array[count].slot = i;
            array[count].age = sFollowMonData.list[i].age;
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
    sFollowMonData.list[array[0].slot].age = numActive;

    for (i = 1; i < numActive; i++)
    {
        array[i].age = array[i - 1].age - 1;
        sFollowMonData.list[array[i].slot].age = array[i].age;
    }
}

void FollowMon_OnObjectEventSpawned(struct ObjectEvent *objectEvent)
{
    u32 spawnSlot = GetSpawnSlotByLocalId(objectEvent->localId);

    sFollowMonData.pendingSpawnAnim = spawnSlot + 1;
    SortOWEMonAges();
}

void FollowMon_OnObjectEventRemoved(struct ObjectEvent *objectEvent)
{
    u32 spawnSlot = GetSpawnSlotByLocalId(objectEvent->localId);

    sFollowMonData.list[spawnSlot].age = 0;
}

u32 GetFollowMonObjectEventGraphicsId(u32 spawnSlot, s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale)
{
    SetOverworldEncounterSpeciesInfo(spawnSlot, x, y, speciesId, isShiny, isFemale);
    u16 graphicsId = *speciesId + OBJ_EVENT_MON;

    if (*isFemale)
        graphicsId += OBJ_EVENT_MON_FEMALE;

    if (*isShiny)
        graphicsId += OBJ_EVENT_MON_SHINY;

    return graphicsId;
}

void ClearOverworldEncounterData(void)
{
    sFollowMonData.spawnCountdown = 0;

    for (u32 i = 0; i < FOLLOWMON_MAX_SPAWN_SLOTS; i++)
    {
        sFollowMonData.list[i].age = 0;
    }
}

static void SetOverworldEncounterSpeciesInfo(u32 spawnSlot, s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale)
{
    const struct WildPokemonInfo *wildMonInfo;
    u32 headerId = GetCurrentMapWildMonHeaderId();
    u32 tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    u32 timeOfDay, encounterIndex, level;
    u32 personality = Random32();

    if (MetatileBehavior_IsWaterWildEncounter(tileBehavior))
    {
        encounterIndex = ChooseWildMonIndex_Water();
        timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_WATER);
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo;
        *speciesId = wildMonInfo->wildPokemon[encounterIndex].species;
        level = ChooseWildMonLevel(wildMonInfo->wildPokemon, encounterIndex, WILD_AREA_WATER);
    }
    else
    {
        encounterIndex = ChooseWildMonIndex_Land();
        timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo;
        *speciesId = wildMonInfo->wildPokemon[encounterIndex].species;
        level = ChooseWildMonLevel(wildMonInfo->wildPokemon, encounterIndex, WILD_AREA_LAND);
    }

    if (*speciesId == SPECIES_UNOWN)
        *speciesId = GetUnownSpeciesId(personality);

    sFollowMonData.list[spawnSlot].level = level;
    *isShiny = ComputePlayerShinyOdds(personality);
    if (GetGenderFromSpeciesAndPersonality(*speciesId, personality) == MON_FEMALE)
        *isFemale = TRUE;
    else
        *isFemale = FALSE;
}

static bool8 IsSafeToSpawnObjectEvents(void)
{
    struct ObjectEvent* player = &gObjectEvents[gPlayerAvatar.objectEventId];

    // Only spawn when player is at a valid tile position
    return (player->currentCoords.x == player->previousCoords.x && player->currentCoords.y == player->previousCoords.y);
}

u8 CountActiveFollowMon()
{
    u32 count = 0;
    for (u32 spawnSlot = 0; spawnSlot < FOLLOWMON_MAX_SPAWN_SLOTS; spawnSlot++)
    {
        if (GetOverworldSpeciesBySpawnSlot(spawnSlot) != SPECIES_NONE)
            count++;
    }

    return count;
}

static u8 CountActiveObjectEvents()
{
    u8 i;
    u8 count = 0;

    for(i = 0; i < OBJECT_EVENTS_COUNT; ++i)
    {
        if(gObjectEvents[i].active)
            ++count;
    }

    return count;
}

static bool8 IsSpawningWaterMons()
{
    return (gPlayerAvatar.flags & (PLAYER_AVATAR_FLAG_SURFING | PLAYER_AVATAR_FLAG_UNDERWATER));
}

static void RemoveOverworldEncounterObject(struct ObjectEvent *objectEvent)
{
    RemoveObjectEvent(objectEvent);
}

void RemoveAllOverworldEncounterObjects(void)
{
    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; ++i)
    {
        struct ObjectEvent *obj = &gObjectEvents[i];
        if (IsGeneratedOverworldEncounter(obj))
            RemoveOverworldEncounterObject(obj);
    }
}

static bool8 CheckForObjectEventAtLocation(s16 x, s16 y)
{
    u8 i;

    for(i = 0; i < OBJECT_EVENTS_COUNT; ++i)
    {
        if(gObjectEvents[i].active && gObjectEvents[i].currentCoords.x == x && gObjectEvents[i].currentCoords.y == y)
            return TRUE;
    }

    return FALSE;
}

static const struct WildPokemonInfo *GetActiveEncounterTable(bool8 onWater)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();

    if (headerId == HEADER_NONE)
        return NULL;

    enum TimeOfDay timeOfDay;

    if (onWater)
    {
        timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_WATER);
        return gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo;
    }
    timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
    return gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo;
}

static void GetMapSize(u8 mapGroup, u8 mapNum, s32 *width, s32 *height)
{
    const struct MapLayout *layout;

    layout = Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum)->mapLayout;
    *width = layout->width;
    *height = layout->height;
}

static bool32 IsInsideMap(u8 mapGroup, u8 mapNum, s16 x, s16 y)
{
    s32 width, height;
    GetMapSize(mapGroup, mapNum, &width, &height);
    x -= MAP_OFFSET;
    y -= MAP_OFFSET;

    if (x >= 0 && x < width && y >= 0 && y < height)
        return TRUE;

    return FALSE;
}

static bool32 IsInsidePlayerMap(s16 x, s16 y)
{
    return IsInsideMap(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, x, y);
}

bool32 IsOverworldEncounterObjectEventInSpawnedMap(struct ObjectEvent *objectEvent, s16 x, s16 y)
{
    u8 mapGroup = objectEvent->mapGroup;
    u8 mapNum = objectEvent->mapNum;

    if (mapGroup == gSaveBlock1Ptr->location.mapGroup && mapNum == gSaveBlock1Ptr->location.mapNum)
        return IsInsidePlayerMap(x, y);
    else
        return !IsInsidePlayerMap(x, y);
}

bool32 IsGeneratedOverworldEncounter(struct ObjectEvent *objectEvent)
{
    return (objectEvent->graphicsId & OBJ_EVENT_MON) && (objectEvent->trainerType == TRAINER_TYPE_ENCOUNTER);
}

static u16 GetOverworldSpeciesBySpawnSlot(u32 spawnSlot)
{
    u32 objEventId = GetObjectEventIdByLocalId(GetLocalIdByOverworldSpawnSlot(spawnSlot));
    struct ObjectEvent *objectEvent = &gObjectEvents[objEventId];
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
    u32 i;
    u32 newestSlot = 0;
    for (i = 0; i < FOLLOWMON_MAX_SPAWN_SLOTS; i++)
    {
        if (sFollowMonData.list[newestSlot].age > sFollowMonData.list[i].age)
            newestSlot = i;
    }

    return newestSlot;
}

static bool32 CanRemoveOverworldEncounter(u32 localId)
{
    // Can the last of these checks be replaced by IsGeneratedOverworldEncounter?
    // Include a check for the encounter not being shiny or a roamer.
    return (OW_WILD_ENCOUNTERS_OVERWORLD && CountActiveFollowMon() != 0
        && (localId <= (LOCALID_OW_ENCOUNTER_END - FOLLOWMON_MAX_SPAWN_SLOTS + 1)
        || localId > LOCALID_OW_ENCOUNTER_END));
}

static void RemoveOldestOverworldEncounter(u8 *objectEventId)
{
    *objectEventId = GetObjectEventIdByLocalId(GetLocalIdByOverworldSpawnSlot(GetOldestSlot()));
    s16 *fldEffSpriteId = &gSprites[gObjectEvents[*objectEventId].spriteId].data[6];

    // Stop the associated field effect if it is active.
    if (*fldEffSpriteId != 0)
        FieldEffectStop(&gSprites[*fldEffSpriteId - 1], FLDEFF_BUBBLES);

    RemoveOverworldEncounterObject(&gObjectEvents[*objectEventId]);
}

bool32 TryAndRemoveOldestOverworldEncounter(u32 localId, u8 *objectEventId)
{
    // How does this work for objects if they are on a different map?
    if (CanRemoveOverworldEncounter(localId))
    {
        RemoveOldestOverworldEncounter(objectEventId);
        return FALSE;
    }
    
    return TRUE;
}
