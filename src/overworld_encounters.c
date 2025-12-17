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
static bool32 OWE_ShouldSpawnWaterMons(void);
static void SetOverworldEncounterSpeciesInfo(s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level);
static bool8 IsSafeToSpawnObjectEvents(void);
static const struct WildPokemonInfo *GetActiveEncounterTable(bool8 onWater);
static bool8 CheckForObjectEventAtLocation(s16 x, s16 y);
static u16 GetOverworldSpeciesBySpawnSlot(u32 spawnSlot);
static u32 GetLocalIdByOverworldSpawnSlot(u32 spawnSlot);
static u32 GetSpawnSlotByLocalId(u32 localId);
static void SortOWEMonAges(void);

void LoadOverworldEncounterData(void)
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
    s16 x, y;

    if (sOWESpawnCountdown != 0)
    {
        sOWESpawnCountdown--;
        return;
    }

    if (!IsSafeToSpawnObjectEvents() || !TrySelectTile(&x, &y))
        return;
    
    if (GetActiveEncounterTable(OWE_ShouldSpawnWaterMons()))
    {
        u16 spawnSlot = NextSpawnMonSlot();

        if (spawnSlot == INVALID_SPAWN_SLOT)
        {
            sOWESpawnCountdown = OWE_SPAWN_TIME_MINIMUM;
            return;
        }
        
        bool32 waterMons = OWE_ShouldSpawnWaterMons();
        u32 localId = GetLocalIdByOverworldSpawnSlot(spawnSlot);
        u32 numFreePalSlots = CountFreePaletteSlots();
        u32 level;
        
        struct ObjectEventTemplate objectEventTemplate = {
            .localId = localId,
            .graphicsId = GetOverworldEncounterObjectEventGraphicsId(x, y, &speciesId, &isShiny, &isFemale, &level),
            .x = x - MAP_OFFSET,
            .y = y - MAP_OFFSET,
            .elevation = MapGridGetElevationAt(x, y),
            .movementType = MOVEMENT_TYPE_WANDER_AROUND_OWE,
            .trainerType = TRAINER_TYPE_ENCOUNTER,
        };

        // We need at least 2 pal slots open. One for the object and one for the spawn field effect.
        // Add this and tiles to seperate graphics check function
        if (numFreePalSlots == 1)
        {
            u32 palTag = speciesId + OBJ_EVENT_MON + (isShiny ? OBJ_EVENT_MON_SHINY : 0);

            if (isFemale && gSpeciesInfo[speciesId].overworldShinyPaletteFemale != NULL)
                palTag += OBJ_EVENT_MON_FEMALE;
                
            // If the mon's palette isn't already loaded, don't spawn.
            if (IndexOfSpritePaletteTag(palTag) == 0xFF)
                return;

            // Add check if field effect pallete is already loaded
            // Bubbles field effect occurs on every movement
        }
        else if (numFreePalSlots == 0)
        {
            return;
        }

        u8 objectEventId = SpawnSpecialObjectEvent(&objectEventTemplate);

        if (objectEventId >= OBJECT_EVENTS_COUNT)
        {
            sOWESpawnCountdown = OWE_SPAWN_TIME_MINIMUM;
            return;
        }

        gObjectEvents[objectEventId].disableCoveringGroundEffects = TRUE;
        gObjectEvents[objectEventId].range.rangeX = OW_ENCOUNTER_MOVEMENT_RANGE_X;
        gObjectEvents[objectEventId].range.rangeY = OW_ENCOUNTER_MOVEMENT_RANGE_Y;
        gObjectEvents[objectEventId].sOverworldEncounterLevel = level;

        u8 directions[4] = {DIR_SOUTH, DIR_NORTH, DIR_WEST, DIR_EAST};
        ObjectEventTurn(&gObjectEvents[objectEventId], directions[Random() & 3]);

        // Hide reflections for spawns in water
        // (It just looks weird)
        if (waterMons)
            gObjectEvents[objectEventId].hideReflection = TRUE;

        // Slower replacement spawning
        sOWESpawnCountdown = OWE_TIME_BETWEEN_SPAWNS + (Random() % OWE_SPAWN_TIME_VARIABILITY);
        
        enum OverworldEncounterSpawnAnim spawnAnimType;

        // Play spawn animation.
        if (speciesId == SPECIES_NONE)
        {
            sOWESpawnCountdown = OWE_SPAWN_TIME_MINIMUM;
            return;
        }

        u32 pan = (Random() % 88) + 212;
        u32 volume = (Random() % 30) + 50;
        PlayCry_NormalNoDucking(speciesId, pan, volume, CRY_PRIORITY_AMBIENT);
        if (isShiny)
        {
            PlaySE(SE_SHINY);
            spawnAnimType = OWE_SPAWN_ANIM_SHINY;
        }
        else 
        {
            if (OWE_ShouldSpawnWaterMons())
                spawnAnimType = OWE_SPAWN_ANIM_WATER;
            else if (gMapHeader.cave || gMapHeader.mapType == MAP_TYPE_UNDERGROUND)
                spawnAnimType = OWE_SPAWN_ANIM_CAVE;
            else
                spawnAnimType = OWE_SPAWN_ANIM_GRASS;
        }
        // Instantly play a small animation to ground the spawning a bit
        MovementAction_OverworldEncounterSpawn(spawnAnimType, &gObjectEvents[objectEventId]);
    }
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
    if ((x + MAP_OFFSET) < 0 || (x + MAP_OFFSET) >= layout->width ||
        (y + MAP_OFFSET) < 0 || (y + MAP_OFFSET) >= layout->height)
        return FALSE;

    // 0 is change of elevation, 15 is multiple elevation e.g. bridges
    // Causes weird interaction issues so just don't let mons spawn here
    if (elevation == 0 || elevation == 15)
        return FALSE;

    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    if (OWE_ShouldSpawnWaterMons())
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
    u32 localId = gSpecialVar_LastTalked;
    u32 objEventId = GetObjectEventIdByLocalId(localId);
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

static void SetOverworldEncounterSpeciesInfo(s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();
    u32 encounterIndex;
    u32 personality = Random32();
    enum TimeOfDay timeOfDay;

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

bool32 IsSemiManualOverworldWildEncounter(u32 graphicsId)
{
    return graphicsId == OBJ_EVENT_GFX_OVERWORLD_ENCOUNTER;
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
    if (!IsSemiManualOverworldWildEncounter(template->graphicsId))
        return *template;

    struct ObjectEventTemplate templateOWE = *template;
    
    // Does this work?
    u32 graphicsId;
    u16 speciesId;
    bool32 isShiny = FALSE;
    bool32 isFemale = FALSE;
    u32 level;
    u32 headerId = GetCurrentMapWildMonHeaderId();
    u32 encounterIndex;
    u32 personality = Random32();
    enum TimeOfDay timeOfDay;

    SetOverworldEncounterSpeciesInfo_Helper(
        template->x - MAP_OFFSET,
        template->y - MAP_OFFSET,
        &encounterIndex,
        headerId,
        &timeOfDay,
        &speciesId,
        &isShiny,
        &isFemale,
        &level,
        personality
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

void OWE_TryTriggerEncounter(struct ObjectEvent *obstacle, struct ObjectEvent *collider)
{
    // The only automatically interacts with an OW Encounter when;
    // Not using a repel or the DexNav is inactive.
    if (/* VarGet(VAR_REPEL_STEP_COUNT) > 0 || */ FlagGet(DN_FLAG_SEARCHING))
        return;

    bool32 playerIsCollider = (collider->isPlayer && IsOverworldWildEncounter(obstacle));
    bool32 playerIsObstacle = (obstacle->isPlayer && IsOverworldWildEncounter(collider));

    if (playerIsCollider || playerIsObstacle)
    {
        struct ObjectEvent *wildMon = playerIsCollider ? obstacle : collider;

        gSpecialVar_LastTalked = wildMon->localId;
        gSpecialVar_0x8004 = OW_SPECIES(wildMon);
        ScriptContext_SetupScript(InteractWithDynamicWildOverworldEncounter);
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

bool32 OWE_CheckRestrictedMovement(s32 xCurrent, s32 yCurrent, s32 xNew, s32 yNew)
{
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

#undef sOverworldEncounterLevel
#undef sAge
