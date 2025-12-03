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
#include "constants/wild_encounter.h"

#define sOverworldEncounterLevel trainerRange_berryTreeId
#define sAge                     playerCopyableMovement

static EWRAM_DATA u8 sOWESpawnCountdown = 0;

static bool8 TrySelectTile(s16* outX, s16* outY);
static u8 NextSpawnMonSlot();
static bool8 IsSpawningWaterMons();
static void SetOverworldEncounterSpeciesInfo(u32 spawnSlot, s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level);
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
static void SortOWEMonAges(void);

void LoadFollowMonData(void)
{
    sOWESpawnCountdown = OWE_SPAWN_TIME_MINIMUM;
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
        sOWESpawnCountdown = OWE_SPAWN_TIME_MINIMUM;
    }

    u16 speciesId = SPECIES_NONE;
    bool32 isShiny = FALSE;
    bool32 isFemale = FALSE;

    OverworldEncounters_ProcessMonInteraction();

    if(sOWESpawnCountdown == 0)
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
                u32 movementType, level;
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
                    .graphicsId = GetFollowMonObjectEventGraphicsId(spawnSlot, x, y, &speciesId, &isShiny, &isFemale, &level),
                    .x = x - MAP_OFFSET,
                    .y = y - MAP_OFFSET,
                    .elevation = MapGridGetElevationAt(x, y),
                    .movementType = movementType,
                    .trainerType = TRAINER_TYPE_ENCOUNTER,
                };

                u8 objectEventId = SpawnSpecialObjectEvent(&objectEventTemplate);

                gObjectEvents[objectEventId].disableCoveringGroundEffects = TRUE;
                gObjectEvents[objectEventId].range.rangeX = OW_ENCOUNTER_MOVEMENT_RANGE_X;
                gObjectEvents[objectEventId].range.rangeY = OW_ENCOUNTER_MOVEMENT_RANGE_Y;
                gObjectEvents[objectEventId].sOverworldEncounterLevel = level;

                // Hide reflections for spawns in water
                // (It just looks weird)
                if (waterMons)
                    gObjectEvents[objectEventId].hideReflection = TRUE;

                // Slower replacement spawning
                sOWESpawnCountdown = OWE_TIME_BETWEEN_SPAWNS + (Random() % OWE_SPAWN_TIME_VARIABILITY);
                
                enum FollowMonSpawnAnim spawnAnimType;

                // Play spawn animation.
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
                    MovementAction_FollowMonSpawn(spawnAnimType, &gObjectEvents[objectEventId]);
                }
            }
            else
            {
                sOWESpawnCountdown = OWE_SPAWN_TIME_MINIMUM;
            }
        }
    }
    else
    {
        --sOWESpawnCountdown;
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
    struct ObjectEvent *slotMon;
    struct ObjectEvent *oldest = &gObjectEvents[GetObjectEventIdByLocalId(LOCALID_OW_ENCOUNTER_END)];
    u32 spawnSlot;

    for (spawnSlot = 0; spawnSlot < FOLLOWMON_MAX_SPAWN_SLOTS; spawnSlot++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(LOCALID_OW_ENCOUNTER_END - spawnSlot)];
        if (OW_SPECIES(slotMon) != SPECIES_NONE && !OW_SHINY(slotMon))
        {
            oldest = slotMon;
            break;
        }
    }

    if (spawnSlot >= FOLLOWMON_MAX_SPAWN_SLOTS)
        return INVALID_SPAWN_SLOT;

    for (spawnSlot = 0; spawnSlot < FOLLOWMON_MAX_SPAWN_SLOTS; spawnSlot++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(LOCALID_OW_ENCOUNTER_END - spawnSlot)];
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
    u32 maxSpawns = GetMaxFollowMonSpawns();

    // All mon slots are in use
    if (CountActiveFollowMon() >= maxSpawns)
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
        RemoveObjectEventByLocalIdAndMap(object->localId, object->mapNum, object->mapGroup);
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

void CreateOverworldWildEncounter(void)
{
    u32 objEventId = GetObjectEventIdByLocalId(gSpecialVar_LastTalked);
    struct ObjectEvent *object = &gObjectEvents[objEventId];

    if (objEventId >= OBJECT_EVENTS_COUNT)
        return;

    if (!IsOverworldWildEncounter(object))
        return;

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
    RemoveObjectEventByLocalIdAndMap(object->localId, object->mapNum, object->mapGroup);
    BattleSetup_StartWildBattle();
}

static void OverworldEncounters_ProcessMonInteraction(void)
{
    u8 i;
    struct ObjectEvent *object;
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        object = &gObjectEvents[i];
        if (IsOverworldWildEncounter(object) && object->active && object != player
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
    if (!OW_WILD_ENCOUNTERS_OVERWORLD)
        return FALSE;
    
    // The player only is exempt from collisions with OW Encounters when not using a repel or the DexNav is inactive.

    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    bool32 forcePlayerCollision = (/* VarGet(VAR_REPEL_STEP_COUNT) > 0 || */ FlagGet(DN_FLAG_SEARCHING));

    if (collider == player && IsOverworldWildEncounter(obstacle) && !forcePlayerCollision)
        return TRUE;

    if (obstacle == player && IsOverworldWildEncounter(collider) && !forcePlayerCollision)
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
    struct ObjectEvent *slotMon;
    struct AgeSort array[FOLLOWMON_MAX_SPAWN_SLOTS];
    struct AgeSort current;
    u32 numActive = CountActiveFollowMon();
    u32 count = 0;
    s32 i, j;

    for (i = 0; i < FOLLOWMON_MAX_SPAWN_SLOTS; i++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(LOCALID_OW_ENCOUNTER_END - i)];
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
    slotMon = &gObjectEvents[GetObjectEventIdByLocalId(LOCALID_OW_ENCOUNTER_END - array[0].slot)];
    slotMon->sAge = numActive;

    for (i = 1; i < numActive; i++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(LOCALID_OW_ENCOUNTER_END - array[i].slot)];
        array[i].age = array[i - 1].age - 1;
        slotMon->sAge = array[i].age;
    }
}

void GeneratedOverworldWildEncounter_OnObjectEventSpawned(struct ObjectEvent *objectEvent)
{
    if (!IsGeneratedOverworldWildEncounter(objectEvent))
        return;
    
    SortOWEMonAges();
}

void OverworldWildEncounter_OnObjectEventRemoved(struct ObjectEvent *objectEvent)
{
    if (!IsGeneratedOverworldWildEncounter(objectEvent))
        return;
}

u32 GetFollowMonObjectEventGraphicsId(u32 spawnSlot, s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level)
{
    SetOverworldEncounterSpeciesInfo(spawnSlot, x, y, speciesId, isShiny, isFemale, level);
    u16 graphicsId = *speciesId + OBJ_EVENT_MON;

    if (*isFemale)
        graphicsId += OBJ_EVENT_MON_FEMALE;

    if (*isShiny)
        graphicsId += OBJ_EVENT_MON_SHINY;

    return graphicsId;
}

void ClearOverworldEncounterData(void)
{
    sOWESpawnCountdown = OWE_SPAWN_TIME_MINIMUM;
}

static void SetOverworldEncounterSpeciesInfo_Helper(u32 x, u32 y, u32 *encounterIndex, u32 headerId, enum TimeOfDay *timeOfDay, u16 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level, u32 personality)
{
    const struct WildPokemonInfo *wildMonInfo;

    if (MetatileBehavior_IsWaterWildEncounter(MapGridGetMetatileBehaviorAt(x, y)))
    {
        *encounterIndex = ChooseWildMonIndex_Water();
        *timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_WATER);
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[*timeOfDay].waterMonsInfo;
        *speciesId = wildMonInfo->wildPokemon[*encounterIndex].species;
        *level = ChooseWildMonLevel(wildMonInfo->wildPokemon, *encounterIndex, WILD_AREA_WATER);
    }
    else
    {
        *encounterIndex = ChooseWildMonIndex_Land();
        *timeOfDay = GetTimeOfDayForEncounters(headerId, WILD_AREA_LAND);
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[*timeOfDay].landMonsInfo;
        *speciesId = wildMonInfo->wildPokemon[*encounterIndex].species;
        *level = ChooseWildMonLevel(wildMonInfo->wildPokemon, *encounterIndex, WILD_AREA_LAND);
    }

    if (*speciesId == SPECIES_UNOWN)
        *speciesId = GetUnownSpeciesId(personality);

    *isShiny = ComputePlayerShinyOdds(personality);
    if (GetGenderFromSpeciesAndPersonality(*speciesId, personality) == MON_FEMALE)
        *isFemale = TRUE;
    else
        *isFemale = FALSE;
}

static void SetOverworldEncounterSpeciesInfo(u32 spawnSlot, s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();
    enum TimeOfDay timeOfDay;
    u32 encounterIndex;
    u32 personality = Random32();

    SetOverworldEncounterSpeciesInfo_Helper(
        x,
        y,
        &encounterIndex,
        headerId,
        &timeOfDay,
        speciesId,
        isShiny,
        isFemale,
        level,
        personality
    );
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

static bool8 IsSpawningWaterMons()
{
    return (gPlayerAvatar.flags & (PLAYER_AVATAR_FLAG_SURFING | PLAYER_AVATAR_FLAG_UNDERWATER));
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

bool32 IsOverworldWildEncounter(struct ObjectEvent *objectEvent)
{
    return (objectEvent->graphicsId & OBJ_EVENT_MON) && (objectEvent->trainerType == TRAINER_TYPE_ENCOUNTER);
}

bool32 IsGeneratedOverworldWildEncounter(struct ObjectEvent *objectEvent)
{
    return IsOverworldWildEncounter(objectEvent)
        && (objectEvent->localId <= LOCALID_OW_ENCOUNTER_END
        && objectEvent->localId > (LOCALID_OW_ENCOUNTER_END - FOLLOWMON_MAX_SPAWN_SLOTS));
}

bool32 IsManualOverworldWildEncounter(struct ObjectEvent *objectEvent)
{
    return IsOverworldWildEncounter(objectEvent)
        && (objectEvent->localId > LOCALID_OW_ENCOUNTER_END
        || objectEvent->localId <= (LOCALID_OW_ENCOUNTER_END - FOLLOWMON_MAX_SPAWN_SLOTS));
}

bool32 IsSemiManualOverworldWildEncounter(struct ObjectEvent *objectEvent)
{
    return objectEvent->graphicsId == OBJ_EVENT_GFX_OVERWORLD_ENCOUNTER;
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
    struct ObjectEvent *slotMon;
    struct ObjectEvent *newest = &gObjectEvents[GetObjectEventIdByLocalId(LOCALID_OW_ENCOUNTER_END)];
    u32 i;
    
    for (i = 0; i < FOLLOWMON_MAX_SPAWN_SLOTS; i++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(LOCALID_OW_ENCOUNTER_END - i)];
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
    // Can the last of these checks be replaced by IsOverworldWildEncounter?
    // Include a check for the encounter not being shiny or a roamer.
    return (OW_WILD_ENCOUNTERS_OVERWORLD && CountActiveFollowMon() != 0
        && (localId <= (LOCALID_OW_ENCOUNTER_END - FOLLOWMON_MAX_SPAWN_SLOTS + 1)
        || localId > LOCALID_OW_ENCOUNTER_END));
}

void RemoveOldestOverworldEncounter(u8 *objectEventId)
{
    *objectEventId = GetObjectEventIdByLocalId(GetLocalIdByOverworldSpawnSlot(GetOldestSlot()));
    s16 *fldEffSpriteId = &gSprites[gObjectEvents[*objectEventId].spriteId].data[6];

    // Stop the associated field effect if it is active.
    if (*fldEffSpriteId != 0)
        FieldEffectStop(&gSprites[*fldEffSpriteId - 1], FLDEFF_BUBBLES);

    RemoveObjectEvent(&gObjectEvents[*objectEventId]);
}

bool32 UNUSED TryAndRemoveOldestOverworldEncounter(u32 localId, u8 *objectEventId)
{
    if (CanRemoveOverworldEncounter(localId))
    {
        RemoveOldestOverworldEncounter(objectEventId);
        return FALSE;
    }
    
    return TRUE;
}

bool32 ShouldRunOverworldEncounterScript(u32 objectEventId)
{
    return IsGeneratedOverworldWildEncounter(&gObjectEvents[objectEventId])
        || (IsManualOverworldWildEncounter(&gObjectEvents[objectEventId]) && GetObjectEventScriptPointerByObjectEventId(objectEventId) == NULL);
}

u16 GetGraphicsIdForOverworldEncounterGfx(struct ObjectEvent *objectEvent)
{
    struct ObjectEventTemplate template = *GetObjectEventTemplateByLocalIdAndMap(objectEvent->localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    u32 graphicsId;
    u32 headerId = GetCurrentMapWildMonHeaderId();
    u32 encounterIndex;
    u16 speciesId;
    bool32 isShiny = FALSE;
    bool32 isFemale = FALSE;
    u32 level;
    u32 personality = Random32();
    enum TimeOfDay timeOfDay;

    SetOverworldEncounterSpeciesInfo_Helper(
        template.x,
        template.y,
        &encounterIndex,
        headerId,
        &timeOfDay,
        &speciesId,
        &isShiny,
        &isFemale,
        &level,
        personality
    );

    graphicsId = speciesId + OBJ_EVENT_MON;
    if (isFemale)
        graphicsId += OBJ_EVENT_MON_FEMALE;
    if (isShiny)
        graphicsId += OBJ_EVENT_MON_SHINY;

    objectEvent->trainerType = TRAINER_TYPE_ENCOUNTER;
    objectEvent->sOverworldEncounterLevel = level;
    return graphicsId;
}

#undef sOverworldEncounterLevel
#undef sAge
