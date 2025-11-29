#include "global.h"
#include "overworld_encounters.h"
#include "battle_setup.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "field_player_avatar.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "random.h"
#include "script.h"
#include "sprite.h"
#include "sound.h"
#include "wild_encounter.h"
#include "constants/event_objects.h"
#include "constants/map_types.h"
#include "constants/trainer_types.h"
#include "constants/songs.h"
#include "constants/vars.h"

static EWRAM_DATA struct FollowMonData sFollowMonData = { 0 };

static u8 CountActiveFollowMon();
static bool8 TrySelectTile(s16* outX, s16* outY);
static u8 NextSpawnMonSlot();
static bool8 IsSpawningWaterMons();
static u32 GetFollowMonSpecies(u32 spawnSlot, s32 x, s32 y);
static u8 CountActiveObjectEvents();
static bool8 IsSafeToSpawnObjectEvents(void);
static const struct WildPokemonInfo *GetActiveEncounterTable(bool8 onWater);
static bool8 AreElevationsCompatible(u8 a, u8 b);
static bool8 CheckForObjectEventAtLocation(s16 x, s16 y);
static void GetMapSize(u8 mapGroup, u8 mapNum, s32 *width, s32 *height);
static bool32 IsInsideMap(u8 mapGroup, u8 mapNum, s16 x, s16 y);
static bool32 IsInsidePlayerMap(s16 x, s16 y);
static void OverworldEncounters_ProcessMonInteraction(void);

#define sEncounterIndex trainerRange_berryTreeId

void LoadFollowMonData(struct ObjectEvent *objectEvent)
{
    u32 slot = OBJ_EVENT_ID_LAST_OVERWORLD_ENCOUNTER - objectEvent->localId;
    sFollowMonData.list[slot].isShiny = objectEvent->shiny;

    sFollowMonData.spawnCountdown += 60;
}

void UpdateOverworldEncounters(void)
{
    if (ArePlayerFieldControlsLocked())
        return;
    
    if (!OW_WILD_ENCOUNTERS_OVERWORLD || FlagGet(OW_FLAG_NO_ENCOUNTER)) // Need check for if header has encounters?
    {
        RemoveOverworldEncounterObjects();
        // Zero sFollowMonData ;
        u8 *raw = (u8 *)&sFollowMonData;
        for (u32 i = 0; i < sizeof(struct FollowMonData); i++)
        {
            raw[i] = 0;
        }

        return;
    }

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
                const struct FollowMon *followMon = &sFollowMonData.list[spawnSlot];
                bool32 waterMons = IsSpawningWaterMons();
                bool32 indoors = gMapHeader.mapType == MAP_TYPE_INDOOR;
                u32 localId = OBJ_EVENT_ID_LAST_OVERWORLD_ENCOUNTER - spawnSlot;
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
                    .graphicsId = GetFollowMonObjectEventGraphicsId(spawnSlot, x, y),
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

                // Only used for save/load as well as loading encounters, 
                // Most of the time, followmon data is tracked in sFollowMonData
                gObjectEvents[objectEventId].shiny = followMon->isShiny;

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
        u32 objEventId = GetObjectEventIdByLocalId(OBJ_EVENT_ID_LAST_OVERWORLD_ENCOUNTER - spawnSlot);
        enum FollowMonSpawnAnim spawnAnimType;

        if (sFollowMonData.list[spawnSlot].species != SPECIES_NONE)
        {
            if(sFollowMonData.list[spawnSlot].isShiny)
            {
                PlaySE(SE_SHINY);
                spawnAnimType = FOLLOWMON_SPAWN_ANIM_SHINY;
            }
            else 
            {
                PlayCry_Normal(sFollowMonData.list[spawnSlot].species, 25); 
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
    if (IsSpawningWaterMons() || gMapHeader.cave || gMapHeader.mapType == MAP_TYPE_UNDERGROUND)
        return 5;
    else
        return 3;
}

static u32 GetNewOldestSlot(u32 oldSlot)
{
    u32 i;
    u32 nextOldest = FOLLOWMON_MAX_SPAWN_SLOTS;

    for (i = 0; i < FOLLOWMON_MAX_SPAWN_SLOTS; i++)
    {
        if (sFollowMonData.list[i].species != SPECIES_NONE)
        {
            if (i != oldSlot && (nextOldest == FOLLOWMON_MAX_SPAWN_SLOTS || sFollowMonData.list[i].age > sFollowMonData.list[nextOldest].age))
                nextOldest = i;
        }
    }

    return nextOldest;
}

static u8 NextSpawnMonSlot(void)
{
    u8 slot = 0;
    u8 maxSpawns = GetMaxFollowMonSpawns();

    // All mon slots are in use
    if(CountActiveFollowMon() >= maxSpawns)
    {
        // Cycle through so we remove the oldest mon first
        slot = sFollowMonData.oldestSlot;
        sFollowMonData.oldestSlot = GetNewOldestSlot(slot);
    }
    else
    {
        for (slot = 0; slot < maxSpawns; slot++)
        {
            if (sFollowMonData.list[slot].species == SPECIES_NONE)
                break;
        }
    }

    // Remove any existing id by this slot
    RemoveObjectEventByLocalIdAndMap(OBJ_EVENT_ID_LAST_OVERWORLD_ENCOUNTER - slot, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    
    // Check that we don't have too many sprites on screen before spawning
    // (lag reduction)
    if(CountActiveObjectEvents() >= FOLLOWMON_IDEAL_OBJECT_EVENT_COUNT)
    // TODO: Clear slot data.
        return INVALID_SPAWN_SLOT;

    return slot;
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

static void CreateMonWithGender(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 otIdType, u32 fixedOtId, bool32 isFemale)
{
    u32 personality;

    if (isFemale)
    {
        do
        {
            personality = Random32();
        }
        while (GetGenderFromSpeciesAndPersonality(species, personality) != MON_FEMALE);
    }
    else
    {
        do
        {
            personality = Random32();
        }
        while (GetGenderFromSpeciesAndPersonality(species, personality) == MON_FEMALE);
    }

    CreateMon(mon, species, level, fixedIV, TRUE, personality, otIdType, fixedOtId);
}

void CreateFollowMonEncounter(void) {
    struct ObjectEvent *curObject;
    u32 objEventId = GetObjectEventIdByLocalIdAndMap(gSpecialVar_LastTalked, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);

    if (objEventId < OBJECT_EVENTS_COUNT)
    {
        curObject = &gObjectEvents[objEventId];
        if (!IsGeneratedOverworldEncounter(curObject))
           return;
    }
    else
    {
        return;
    }

    u32 slot = OBJ_EVENT_ID_LAST_OVERWORLD_ENCOUNTER - gObjectEvents[objEventId].localId;
    bool32 shiny = curObject->shiny;

    ZeroEnemyPartyMons();
    CreateMonWithGender(
        &gEnemyParty[0],
        sFollowMonData.list[slot].species,
        sFollowMonData.list[slot].level,
        USE_RANDOM_IVS,
        OT_ID_PLAYER_ID,
        0,
        sFollowMonData.list[slot].isFemale
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
    // The player can only collide with overworld encounters when not using a repel.
    // Non-player, non-overworld encounters do not have collision with overworld encounters.

    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (collider == player && IsGeneratedOverworldEncounter(obstacle) /* && VarGet(VAR_REPEL_STEP_COUNT) == 0 */)
        return TRUE;

    if (obstacle == player && IsGeneratedOverworldEncounter(collider) /* && VarGet(VAR_REPEL_STEP_COUNT) == 0 */)
        return TRUE;
    
    if (!IsGeneratedOverworldEncounter(collider) && IsGeneratedOverworldEncounter(obstacle))
        return TRUE;

    return FALSE;
}

void FollowMon_OnObjectEventSpawned(struct ObjectEvent *objectEvent)
{
    u32 i;
    u32 spawnSlot = OBJ_EVENT_ID_LAST_OVERWORLD_ENCOUNTER - objectEvent->localId;

    sFollowMonData.pendingSpawnAnim = spawnSlot + 1;

    // Increase the age of all followmons
    for (i = 0; i < FOLLOWMON_MAX_SPAWN_SLOTS; i++)
    {
        if (sFollowMonData.list[i].species != SPECIES_NONE)
            sFollowMonData.list[i].age++;
    }
}

void FollowMon_OnObjectEventRemoved(struct ObjectEvent *objectEvent)
{
    u32 spawnSlot = OBJ_EVENT_ID_LAST_OVERWORLD_ENCOUNTER - objectEvent->localId;

    sFollowMonData.list[spawnSlot].species = SPECIES_NONE;
    sFollowMonData.list[spawnSlot].age = 0;
}

u32 GetFollowMonObjectEventGraphicsId(u32 spawnSlot, s32 x, s32 y)
{
    u16 species = GetFollowMonSpecies(spawnSlot, x, y);
    u16 graphicsId = species + OBJ_EVENT_MON;

    if (sFollowMonData.list[spawnSlot].isFemale)
        graphicsId += OBJ_EVENT_MON_FEMALE;

    if (sFollowMonData.list[spawnSlot].isShiny)
        graphicsId += OBJ_EVENT_MON_SHINY;

    return graphicsId;
}

void ClearOverworldEncounterData(void)
{
    sFollowMonData.spawnCountdown = 0;
    sFollowMonData.oldestSlot = 0;

    for (u32 i = 0; i < FOLLOWMON_MAX_SPAWN_SLOTS; i++)
    {
        sFollowMonData.list[i].species = SPECIES_NONE;
        sFollowMonData.list[i].age = 0;
    }
}

static u32 GetFollowMonSpecies(u32 spawnSlot, s32 x, s32 y)
{
    const struct WildPokemonInfo *wildMonInfo;
    u32 species = 0;
    u32 headerId = GetCurrentMapWildMonHeaderId();
    u32 tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    u32 timeOfDay, encounterIndex, level;

    if (MetatileBehavior_IsWaterWildEncounter(tileBehavior))
    {
        encounterIndex = ChooseWildMonIndex_Water();
        timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_WATER);
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].waterMonsInfo;
        species = wildMonInfo->wildPokemon[encounterIndex].species;
        level = ChooseWildMonLevel(wildMonInfo->wildPokemon, encounterIndex, WILD_AREA_WATER);
    }
    else
    {
        encounterIndex = ChooseWildMonIndex_Land();
        timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[timeOfDay].landMonsInfo;
        species = wildMonInfo->wildPokemon[encounterIndex].species;
        level = ChooseWildMonLevel(wildMonInfo->wildPokemon, encounterIndex, WILD_AREA_LAND);
    }

    if (species == SPECIES_UNOWN)
    {
        u32 rand = Random32() % NUM_UNOWN_FORMS;

        if (rand != 0)
            species = SPECIES_UNOWN_B + rand - 1;
    }

    sFollowMonData.list[spawnSlot].species = species;
    sFollowMonData.list[spawnSlot].level = level;
    sFollowMonData.list[spawnSlot].isShiny = ComputePlayerShinyOdds(Random32());
    if (GetGenderFromSpeciesAndPersonality(species, Random32()) == MON_FEMALE)
        sFollowMonData.list[spawnSlot].isFemale = TRUE;
    else
        sFollowMonData.list[spawnSlot].isFemale = FALSE;
    
    return species;
}

static bool8 IsSafeToSpawnObjectEvents(void)
{
    struct ObjectEvent* player = &gObjectEvents[gPlayerAvatar.objectEventId];

    // Only spawn when player is at a valid tile position
    return (player->currentCoords.x == player->previousCoords.x && player->currentCoords.y == player->previousCoords.y);
}

static u8 CountActiveFollowMon()
{
    u8 count = 0;
    for(u8 slot = 0; slot < FOLLOWMON_MAX_SPAWN_SLOTS; slot++)
    {
        if(sFollowMonData.list[slot].species != SPECIES_NONE)
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

void RemoveOverworldEncounterObjects(void)
{
    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; ++i)
    {
        struct ObjectEvent *obj = &gObjectEvents[i];
        if (IsGeneratedOverworldEncounter(obj))
            RemoveObjectEvent(obj);
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

static bool8 AreElevationsCompatible(u8 a, u8 b)
{
    if (a == 0 || b == 0)
        return TRUE;

    if (a != b)
        return FALSE;

    return TRUE;
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
