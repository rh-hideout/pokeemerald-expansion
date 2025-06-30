#include "global.h"
#include "constants/event_objects.h"
#include "constants/map_types.h"
#include "constants/songs.h"
#include "constants/vars.h"
#include "battle_setup.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "followmon.h"
#include "fieldmap.h"
#include "field_player_avatar.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "random.h"
#include "script.h"
#include "sprite.h"
#include "sound.h"
#include "wild_encounter.h"



static EWRAM_DATA struct FollowMonData sFollowMonData = { 0 };

static u8 CountActiveFollowMon();
static bool8 TrySelectTile(s16* outX, s16* outY);
static u8 NextSpawnMonSlot();
static bool8 IsSpawningWaterMons();
static u16 GetFollowMonSpecies(struct FollowMon *followMon);
static u8 CountActiveObjectEvents();
static bool8 IsSafeToSpawnObjectEvents(void);
static u8 FindObjectEventForGfx(u16 gfxId);
static const struct WildPokemonInfo *GetActiveEncounterTable(bool8 onWater);
static bool8 AreElevationsCompatible(u8 a, u8 b);
static bool8 CheckForObjectEventAtLocation(s16 x, s16 y);
static bool8 IsInsidePlayerMap(s16 x, s16 y);
static void GetMapSize(s32 *width, s32 *height);

#define sEncounterIndex trainerRange_berryTreeId

void LoadFollowMonData(struct ObjectEvent *objectEvent)
{
    u8 slot = objectEvent->graphicsId - OBJ_EVENT_GFX_FOLLOW_MON_FIRST;
    sFollowMonData.list[slot].isShiny = objectEvent->shiny;
    sFollowMonData.list[slot].timeOfDay = objectEvent->spawnTimeOfDay;
    sFollowMonData.list[slot].encounterIndex = objectEvent->sEncounterIndex;
    sFollowMonData.list[slot].onWater = MetatileBehavior_IsSurfableWaterOrUnderwater(objectEvent->currentMetatileBehavior);

    sFollowMonData.spawnCountdown += 60;
}


void FollowMon_OverworldCB(void)
{
    if (!FlagGet(OW_FLAG_SPAWN_OVERWORLD_MON)) {
        RemoveAllFollowMonObjects();
        // Zero sFollowMonData ;
        u8 *raw = (u8 *)&sFollowMonData;
        for (u32 i = 0; i < sizeof(struct FollowMonData); i++) {
            raw[i] = 0;
        }
        return;
    }

    if(sFollowMonData.spawnCountdown == 0)
    {
        s16 x, y;
        const struct WildPokemonInfo *wildMonInfo = NULL;
        wildMonInfo = GetActiveEncounterTable(IsSpawningWaterMons());

        if(wildMonInfo && IsSafeToSpawnObjectEvents() && TrySelectTile(&x, &y))
        {
            u16 spawnSlot = NextSpawnMonSlot();

            if(spawnSlot != INVALID_SPAWN_SLOT)
            {
                u8 localId = OBJ_EVENT_ID_FOLLOW_MON_FIRST + spawnSlot;
                u8 objectEventId = SpawnSpecialObjectEventParameterized(
                    OBJ_EVENT_GFX_FOLLOW_MON_FIRST + spawnSlot,
                    MOVEMENT_TYPE_WANDER_AROUND,
                    localId,
                    x,
                    y,
                    MapGridGetElevationAt(x, y)
                );

                gObjectEvents[objectEventId].disableCoveringGroundEffects = TRUE;
                gObjectEvents[objectEventId].range.rangeX = 8;
                gObjectEvents[objectEventId].range.rangeY = 8;

                // Only used for save/load as well as loading encounters, 
                // Most of the time, followmon data is tracked in sFollowMonData
                const struct FollowMon *followMon = &sFollowMonData.list[spawnSlot];
                gObjectEvents[objectEventId].shiny = followMon->isShiny;
                gObjectEvents[objectEventId].spawnTimeOfDay = followMon->timeOfDay;
                gObjectEvents[objectEventId].sEncounterIndex = followMon->encounterIndex;

                // Hide reflections for spawns in water
                // (It just looks weird)
                if(IsSpawningWaterMons())
                {
                    gObjectEvents[objectEventId].hideReflection = TRUE; 
                }

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
        u16 spawnSlot;
        u16 gfxId;
        u16 bitFlag;
        u8 objectEventId;
        enum FollowMonSpawnAnim spawnAnimType;

        for(gfxId = OBJ_EVENT_GFX_FOLLOW_MON_FIRST; gfxId < OBJ_EVENT_GFX_FOLLOW_MON_LAST; ++gfxId)
        {
            spawnSlot = gfxId - OBJ_EVENT_GFX_FOLLOW_MON_FIRST;
            bitFlag = (1 << spawnSlot);

            if((sFollowMonData.pendingSpawnAnim & bitFlag) != 0)
            {
                objectEventId = FindObjectEventForGfx(gfxId);

                if(objectEventId != OBJECT_EVENTS_COUNT)
                {
                    if(sFollowMonData.list[spawnSlot].isShiny)
                    {
                        PlaySE(SE_SHINY);
                        spawnAnimType = FOLLOWMON_SPAWN_ANIM_SHINY;
                        sFollowMonData.pendingSpawnAnim &= ~bitFlag;
                    }
                    else 
                    {
                        PlayCry_Normal(GetFollowMonSpecies(&sFollowMonData.list[spawnSlot]), 25); 
                        if (IsSpawningWaterMons())
                            spawnAnimType = FOLLOWMON_SPAWN_ANIM_WATER;
                        else if (gMapHeader.cave || gMapHeader.mapType == MAP_TYPE_UNDERGROUND)
                            spawnAnimType = FOLLOWMON_SPAWN_ANIM_CAVE;
                        else
                            spawnAnimType = FOLLOWMON_SPAWN_ANIM_GRASS;
                    }
                    // Instantly play a small animation to ground the spawning a bit (Disable for now)
                    MovementAction_FollowMonSpawn(spawnAnimType, &gObjectEvents[objectEventId]);
                    sFollowMonData.pendingSpawnAnim &= ~bitFlag;
                }
            }
        }
    }
}

static u8 NextSpawnMonSlot(void)
{
    u8 slot;

    slot = FOLLOWMON_MAX_SPAWN_SLOTS;

    for(slot = 0; slot < FOLLOWMON_MAX_SPAWN_SLOTS; ++slot)
    {
        if(sFollowMonData.list[slot].encounterIndex == 0)
            break;
    }

    // All mon slots are in use
    if(slot == FOLLOWMON_MAX_SPAWN_SLOTS)
    {
        // Cycle through so we remove the oldest mon first
        sFollowMonData.spawnSlot = (sFollowMonData.spawnSlot + 1) % FOLLOWMON_MAX_SPAWN_SLOTS;
        slot = sFollowMonData.spawnSlot;   
    }

    // Remove any existing id by this slot
    RemoveObjectEventByLocalIdAndMap(OBJ_EVENT_ID_FOLLOW_MON_FIRST + slot, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    
    // Check that we don't have too many sprites on screen before spawning
    // (lag reduction)
    if(CountActiveObjectEvents() >= FOLLOWMON_IDEAL_OBJECT_EVENT_COUNT)
    {
        return INVALID_SPAWN_SLOT;
    }

    GenerateFollowMon(&sFollowMonData.list[slot], IsSpawningWaterMons());

    return slot;
}

static bool8 TrySelectTile(s16* outX, s16* outY)
{
    u8 tryCount;
    u8 elevation;
    u16 tileBehavior;
    s16 playerX, playerY;
    s16 x, y;
    u8 closeDistance;

    for(tryCount = 0; tryCount < 3; ++tryCount)
    {
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

        if (!IsInsidePlayerMap(x, y)) {
            return FALSE;
        }
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
    }

    return FALSE;
}

void CreateFollowMonEncounter(void) {
    struct ObjectEvent *curObject;
    u8 lastTalkedId = VarGet(VAR_LAST_TALKED);
    u8 objEventId = GetObjectEventIdByLocalIdAndMap(lastTalkedId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);

    if(objEventId < OBJECT_EVENTS_COUNT)
    {
            curObject = &gObjectEvents[objEventId];
            if(!FollowMon_IsMonObject(curObject))
               return;
    } else 
        return;

    const struct WildPokemonInfo *wildMonInfo;
    u32 headerId = GetCurrentMapWildMonHeaderId();
    u8 index = curObject->sEncounterIndex - 1;
    u8 level = 0;
    if (MetatileBehavior_IsSurfableWaterOrUnderwater(curObject->currentMetatileBehavior)) {
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[curObject->spawnTimeOfDay].waterMonsInfo;
        level = ChooseWildMonLevel(wildMonInfo->wildPokemon, index, WILD_AREA_WATER);
    } else {
        wildMonInfo = gWildMonHeaders[headerId].encounterTypes[curObject->spawnTimeOfDay].landMonsInfo;
        level = ChooseWildMonLevel(wildMonInfo->wildPokemon,index, WILD_AREA_LAND);
    }

    u16 species = wildMonInfo->wildPokemon[index].species;
    bool8 shiny = curObject->shiny;

    ZeroEnemyPartyMons();
    CreateMon(
        &gEnemyParty[0],
        species,
        level,
        USE_RANDOM_IVS, 
        FALSE, 
        0, 
        OT_ID_PLAYER_ID,
        0
    );
    SetMonData(&gEnemyParty[0], MON_DATA_IS_SHINY, &shiny);
}



bool8 FollowMon_ProcessMonInteraction(void)
{
    if(VarGet(VAR_REPEL_STEP_COUNT) != 0)
    {
        // Never auto trigger battle whilst repel is active
        sFollowMonData.pendingInterction = FALSE;
        return FALSE;
    }

    if(sFollowMonData.pendingInterction)
    {
        u8 i;
        struct ObjectEvent *curObject;
        struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    
        sFollowMonData.pendingInterction = FALSE;
        
        for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
        {
            curObject = &gObjectEvents[i];
            if (curObject->active && curObject != player && FollowMon_IsMonObject(curObject))
            {
                if ((curObject->currentCoords.x == player->currentCoords.x && curObject->currentCoords.y == player->currentCoords.y) || (curObject->previousCoords.x == player->currentCoords.x && curObject->previousCoords.y == player->currentCoords.y))
                {
                    if (AreElevationsCompatible(curObject->currentElevation, player->currentElevation))
                    {
                        // There is a valid collision so exectute the attached script
                        const u8* script = InteractWithDynamicWildFollowMon;
                        gSpecialVar_LastTalked = curObject->localId;
                        //VarSet(VAR_LAST_TALKED, curObject->localId);
                        ScriptContext_SetupScript(script);
                        
                        //CreateFollowMonEncounter();
                        //BattleSetup_StartScriptedWildBattle();
                        return TRUE;
                    }
                }
            }
        }
    }

    return FALSE;
}

bool8 FollowMon_IsCollisionExempt(struct ObjectEvent* obstacle, struct ObjectEvent* collider)
{
    struct ObjectEvent* player = &gObjectEvents[gPlayerAvatar.objectEventId];
    if (collider == player)
    {
        // Player can walk on top of follow mon
        if(FollowMon_IsMonObject(obstacle))
        {
            sFollowMonData.pendingInterction = TRUE;
            return TRUE;
        }
    }
    else if(obstacle == player)
    {
        // Follow mon can walk onto player
        if(FollowMon_IsMonObject(collider))
        {
            sFollowMonData.pendingInterction = TRUE;
            return TRUE;
        }
    } else if(!FollowMon_IsMonObject(collider) && FollowMon_IsMonObject(obstacle))
    {
        // Other objects can walk through follow mons, whilst wandering mons is active
        return TRUE;
    }
    return FALSE;

}

bool8 FollowMon_IsMonObject(struct ObjectEvent* object)
{
    u16 localId = object->localId;
    u16 graphicsId = object->graphicsId;

    if (localId >= OBJ_EVENT_ID_FOLLOW_MON_FIRST && localId <= OBJ_EVENT_ID_FOLLOW_MON_LAST)
    {
        // Fast check
        return TRUE;
    }

    if (IS_FOLLOWMON_GFXID(graphicsId))
        return TRUE;

    return FALSE;
}


void FollowMon_OnObjectEventSpawned(struct ObjectEvent *objectEvent)
{
    u16 spawnSlot = objectEvent->graphicsId - OBJ_EVENT_GFX_FOLLOW_MON_FIRST;

    sFollowMonData.pendingSpawnAnim |= (1 << spawnSlot);
}

void FollowMon_OnObjectEventRemoved(struct ObjectEvent *objectEvent)
{
    u16 spawnSlot = objectEvent->graphicsId - OBJ_EVENT_GFX_FOLLOW_MON_FIRST;
    sFollowMonData.list[spawnSlot].encounterIndex = 0;
}

u16 GetFollowMonObjectEventGraphicsId(u16 graphicsId)
{
    u16 slot = graphicsId - OBJ_EVENT_GFX_FOLLOW_MON_FIRST;
    u16 species = GetFollowMonSpecies(&sFollowMonData.list[slot]);

    graphicsId = OBJ_EVENT_MON + species;
    if (sFollowMonData.list[slot].isShiny)
        graphicsId += OBJ_EVENT_MON_SHINY;
    return graphicsId;
}

void FollowMon_OnWarp(void)
{
    sFollowMonData.spawnCountdown = 0;
    for (u32 i = 0; i < FOLLOWMON_MAX_SPAWN_SLOTS; i++) {
        sFollowMonData.list[i].encounterIndex = 0;
    }
}

static u16 GetFollowMonSpecies(struct FollowMon *followMon)
{
    u16 species = 0;
    u32 headerId = GetCurrentMapWildMonHeaderId();
    if (followMon->onWater) {
       species = gWildMonHeaders[headerId].encounterTypes[followMon->timeOfDay].waterMonsInfo->wildPokemon[followMon->encounterIndex - 1].species;
    } else {
       species = gWildMonHeaders[headerId].encounterTypes[followMon->timeOfDay].landMonsInfo->wildPokemon[followMon->encounterIndex - 1].species;
    }
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
        if(sFollowMonData.list[slot].encounterIndex)
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

void RemoveAllFollowMonObjects(void) {
    for(u32 i = 0; i < OBJECT_EVENTS_COUNT; ++i) {
        if(IS_FOLLOWMON_GFXID(gObjectEvents[i].graphicsId))
            RemoveObjectEvent(&gObjectEvents[i]);
    }
}

static u8 FindObjectEventForGfx(u16 gfxId)
{
    u8 i;
    for(i = 0; i < OBJECT_EVENTS_COUNT; ++i)
    {
        if(gObjectEvents[i].active && gObjectEvents[i].graphicsId == gfxId)
        {
            return i;
        }
    }

    return OBJECT_EVENTS_COUNT;
}

static bool8 CheckForObjectEventAtLocation(s16 x, s16 y)
{
    u8 i;
    for(i = 0; i < OBJECT_EVENTS_COUNT; ++i)
    {
        if(gObjectEvents[i].active && gObjectEvents[i].currentCoords.x == x && gObjectEvents[i].currentCoords.y == y)
        {
            return TRUE;
        }
    }

    return FALSE;
}

static const struct WildPokemonInfo *GetActiveEncounterTable(bool8 onWater)
{
    u32 headerId = GetCurrentMapWildMonHeaderId();
    if (headerId == HEADER_NONE)
        return NULL;
    enum TimeOfDay timeOfDay;

    if (onWater) {
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

static bool8 IsInsidePlayerMap(s16 x, s16 y)
{
    s32 width, height;
    GetMapSize(&width, &height);
    if (x >= 0 && x <= width && y >= 0 && y <= height) {
        return TRUE;
    }
    return FALSE;
}

static void GetMapSize(s32 *width, s32 *height)
{
    const struct MapLayout *layout;
    layout = Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum)->mapLayout;
    *width = layout->width;
    *height = layout->height;
}