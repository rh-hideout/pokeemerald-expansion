#include "global.h"
#include "overworld_encounters.h"
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

#define sOverworldEncounterLevel    trainerRange_berryTreeId
#define sAge                        playerCopyableMovement
#define sRoamerOutbreakStatus       directionSequenceIndex
#define sSavedMovementState         warpArrowSpriteId
#define OWE_NON_ROAMER_OUTBREAK     0
#define OWE_MASS_OUTBREAK_INDEX     ROAMER_COUNT + 1
#define OWE_INVALID_ROAMER_OUTBREAK OWE_MASS_OUTBREAK_INDEX + 1

static EWRAM_DATA u8 sOWESpawnCountdown = 0;

static bool8 TrySelectTile(s16* outX, s16* outY);
static u8 NextSpawnMonSlot();
static bool32 OWE_ShouldSpawnWaterMons(void);
static void SetOverworldEncounterSpeciesInfo(s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level, u32 *indexRoamerOutbreak);
static bool8 IsSafeToSpawnObjectEvents(void);
static bool32 OWE_CheckActiveEncounterTable(bool32 shouldSpawnWaterMons);
static bool8 CheckForObjectEventAtLocation(s16 x, s16 y);
static u16 GetOverworldSpeciesBySpawnSlot(u32 spawnSlot);
static u32 GetLocalIdByOverworldSpawnSlot(u32 spawnSlot);
static u32 GetSpawnSlotByLocalId(u32 localId);
static void SortOWEMonAges(void);
static void OWE_SetNewSpawnCountdown(void);
static bool32 OWE_CanEncounterBeLoaded(u32 speciesId, bool32 isFemale, bool32 isShiny, s16 x, s16 y);
static bool32 OWE_CanEncounterBeLoaded_Palette(u32 speciesId, bool32 isFemale, bool32 isShiny, s16 x, s16 y);
static bool32 OWE_CanEncounterBeLoaded_Tiles(u32 speciesId, bool32 isFemale, bool32 isShiny, s16 x, s16 y);
static void OWE_PlayMonObjectCry(struct ObjectEvent *objectEvent);
static struct ObjectEvent *OWE_GetRandomActiveEncounterObject(void);
static bool32 OWE_DoesRoamerObjectExist(void);
static bool32 OWE_CheckRestrictMovementMetatile(s32 xCurrent, s32 yCurrent, s32 xNew, s32 yNew);
static bool32 OWE_CheckRestrictMovementMap(struct ObjectEvent *objectEvent, s32 xNew, s32 yNew);
static bool32 OWE_CreateEnemyPartyMon(u16 *speciesId, u32 *level, u32 *indexRoamerOutbreak, s32 x, s32 y);
static bool32 CreateOverworldWildEncounter_CheckRoamer(u32 indexRoamerOutbreak);
static bool32 CreateOverworldWildEncounter_CheckBattleFrontier(u32 headerId);
static bool32 CreateOverworldWildEncounter_CheckMassOutbreak(u32 indexRoamerOutbreak, u32 speciesId);
static bool32 CreateOverworldWildEncounter_CheckDoubleBattle(struct ObjectEvent *objectEvent, u32 headerId);
static bool32 OWE_ShouldPlayMonFleeSound(struct ObjectEvent *objectEvent);
static u32 OWE_GetObjectRoamerStatusFromIndex(u32 index);
static u32 OWE_GetObjectRoamerOutbreakStatus(struct ObjectEvent *objectEvent);
static void OWE_DoSpawnDespawnAnim(struct ObjectEvent *objectEvent, bool32 animSpawn);
static bool32 OWE_ShouldDespawnGeneratedForNewOWE(struct ObjectEvent *object);
static void OWE_StartEncounter(struct ObjectEvent *mon);
static bool32 OWE_IsLineOfSightClear(struct ObjectEvent *player, enum Direction direction, u32 distance);
static bool32 OWE_CheckRestrictedMovementAtCoords(struct ObjectEvent *mon, s16 xNew, s16 yNew, enum Direction newDirection, enum Direction collisionDirection);
static u32 OWE_CheckPathToPlayerFromCollision(struct ObjectEvent *mon, enum Direction newDirection);
static void Task_OWE_ApproachForBattle(u8 taskId);
static bool32 OWE_CheckSpecies(u32 speciesId);

void UpdateOverworldEncounters(void)
{
    bool32 shouldSpawnWaterMons = OWE_ShouldSpawnWaterMons();
    if (ArePlayerFieldControlsLocked() || FlagGet(DN_FLAG_SEARCHING) || !OWE_CheckActiveEncounterTable(shouldSpawnWaterMons))
        return;
    
    if (!OWE_WILD_ENCOUNTERS_OVERWORLD
        || FlagGet(OW_FLAG_NO_ENCOUNTER)
        || (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS && !OWE_WILD_ENCOUNTERS_BATTLE_PIKE)
        || (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR && !OWE_WILD_ENCOUNTERS_BATTLE_PYRAMID)
        || InTrainerHillChallenge())
    {
        if (sOWESpawnCountdown != OWE_NO_ENCOUNTER_SET)
        {
            RemoveAllGeneratedOverworldEncounterObjects();
            sOWESpawnCountdown = OWE_NO_ENCOUNTER_SET;
        }
        return;
    }
    else if (sOWESpawnCountdown == OWE_NO_ENCOUNTER_SET)
    {
        OverworldWildEncounter_SetMinimumSpawnTimer();
    }

    u16 spawnSlot = NextSpawnMonSlot();
    if (LURE_STEP_COUNT && spawnSlot != INVALID_SPAWN_SLOT
        && (GetNumberActiveOverworldEncounters(OWE_GENERATED) < OWE_MAX_SPAWNS))
    {
        OverworldWildEncounter_SetMinimumSpawnTimer();
    }
    else if (sOWESpawnCountdown)
    {
        sOWESpawnCountdown--;
        return;
    }

    if (!IsSafeToSpawnObjectEvents())
        return;

    s16 x, y;
    if (spawnSlot == INVALID_SPAWN_SLOT
        || (shouldSpawnWaterMons && AreLegendariesInSootopolisPreventingEncounters())
        || !TrySelectTile(&x, &y))
    {
        OverworldWildEncounter_SetMinimumSpawnTimer();
        return;
    }

    u16 speciesId = SPECIES_NONE;
    bool32 isShiny = FALSE;
    bool32 isFemale = FALSE;
    u32 indexRoamerOutbreak = OWE_NON_ROAMER_OUTBREAK;
    u32 localId = GetLocalIdByOverworldSpawnSlot(spawnSlot);
    u32 level;
    u32 graphicsId = GetOverworldEncounterObjectEventGraphicsId(x, y, &speciesId, &isShiny, &isFemale, &level, &indexRoamerOutbreak);

    if (speciesId == SPECIES_NONE
        || !IsWildLevelAllowedByRepel(level)
        || !IsAbilityAllowingEncounter(level)
        || !OWE_CanEncounterBeLoaded(speciesId, isFemale, isShiny, x, y))
    {
        OverworldWildEncounter_SetMinimumSpawnTimer();
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
        .script = InteractWithDynamicWildOverworldEncounter,
    };
    u32 objectEventId = GetObjectEventIdByLocalId(localId);
    struct ObjectEvent *object = &gObjectEvents[objectEventId];
    if (OWE_ShouldDespawnGeneratedForNewOWE(object))
        RemoveObjectEvent(object);
    objectEventId = SpawnSpecialObjectEvent(&objectEventTemplate);

    assertf(objectEventId < OBJECT_EVENTS_COUNT, "could not spawn generated overworld encounter. too many object events exist")
    {
        OverworldWildEncounter_SetMinimumSpawnTimer();
        return;
    }

    object = &gObjectEvents[objectEventId];
    object->disableCoveringGroundEffects = TRUE;
    object->sOverworldEncounterLevel = level;
    object->sRoamerOutbreakStatus = indexRoamerOutbreak;

    enum Direction directions[4];
    memcpy(directions, gStandardDirections, sizeof directions);
    ObjectEventTurn(object, directions[Random() & 3]);
    OWE_SetNewSpawnCountdown();
}

static void OWE_SetNewSpawnCountdown(void)
{
    u32 numActive = GetNumberActiveOverworldEncounters(OWE_GENERATED);

    if (OWE_WILD_ENCOUNTERS_SPAWN_REPLACEMENT && numActive >= OWE_MAX_SPAWNS)
        sOWESpawnCountdown = OWE_SPAWN_TIME_REPLACEMENT;
    else
        sOWESpawnCountdown = OWE_SPAWN_TIME_MINIMUM + (OWE_SPAWN_TIME_PER_ACTIVE * numActive);
}

bool32 OWE_TryAndRemoveOldestGeneratedOverworldEncounter_Object(u32 localId, u8 *objectEventId)
{
    if (CanRemoveOverworldEncounter(localId))
    {
        *objectEventId = RemoveOldestGeneratedOverworldEncounter();

        if (*objectEventId == OBJECT_EVENTS_COUNT)
            return TRUE;
        else
            return FALSE;
    }
    
    return TRUE;
}

void OWE_TryAndRemoveOldestGeneratedOverworldEncounter_Palette(void)
{
    // Should have similar naming convention for these despawn functions based on Num Object Events, Pals & Tiles
    if (OWE_WILD_ENCOUNTERS_OVERWORLD && CountFreePaletteSlots() < 2)
    {
        u32 count = GetNumberActiveOverworldEncounters(OWE_GENERATED);

        if (count > 0)
        {
            for (; count > 0; count--)
            {
                RemoveOldestGeneratedOverworldEncounter();
                if (CountFreePaletteSlots() >= 2)
                    break;
            }
        }
    }
}

static bool32 OWE_CanEncounterBeLoaded(u32 speciesId, bool32 isFemale, bool32 isShiny, s16 x, s16 y)
{
    assertf(OWE_CanEncounterBeLoaded_Palette(speciesId, isFemale, isShiny, x, y), "could not load palette for overworld encounter\nspecies: %d\nfemale: %d\nshiny: %d\ncoords: %d %d", speciesId, isFemale, isShiny, x, y)
    {
        return FALSE;
    }

    assertf(OWE_CanEncounterBeLoaded_Tiles(speciesId, isFemale, isShiny, x, y), "could not load sprite tiles for overworld encounter\nspecies: %d\nfemale: %d\nshiny: %d\ncoords: %d %d", speciesId, isFemale, isShiny, x, y)
    {
        return FALSE;
    }

    return TRUE;
}

static bool32 OWE_CanEncounterBeLoaded_Palette(u32 speciesId, bool32 isFemale, bool32 isShiny, s16 x, s16 y)
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
        struct SpritePalette palette = OWE_GetSpawnAnimFldEffPalette(OWE_GetSpawnDespawnAnimType(metatileBehavior));
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
static bool32 OWE_CanEncounterBeLoaded_Tiles(u32 speciesId, bool32 isFemale, bool32 isShiny, s16 x, s16 y)
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
static void OWE_DoSpawnDespawnAnim(struct ObjectEvent *objectEvent, bool32 animSpawn)
{
    if (gMain.callback2 != CB2_Overworld)
        return;
    
    enum OverworldEncounterSpawnAnim spawnAnimType;
    bool32 isShiny = OW_SHINY(objectEvent) ? TRUE : FALSE;

    if (animSpawn)
        OWE_PlayMonObjectCry(objectEvent);
    
    if (!animSpawn && OWE_ShouldPlayMonFleeSound(objectEvent))
        PlaySE(SE_FLEE);

    if (OWE_WILD_ENCOUNTERS_SHINY_SPARKLE && isShiny && animSpawn)
    {
        PlaySE(SE_SHINY);
        spawnAnimType = OWE_SPAWN_ANIM_SHINY;
    }
    else 
    {
        u32 metatileBehavior = MapGridGetMetatileBehaviorAt(objectEvent->currentCoords.x, objectEvent->currentCoords.y);
        spawnAnimType = OWE_GetSpawnDespawnAnimType(metatileBehavior);
    }
    MovementAction_OverworldEncounterSpawn(spawnAnimType, objectEvent);
}

u32 GetOldestSlot(bool32 forceRemove)
{
    struct ObjectEvent *slotMon, *oldest = &gObjectEvents[GetObjectEventIdByLocalId(LOCALID_OW_ENCOUNTER_END)];
    u32 spawnSlot;

    for (spawnSlot = 0; spawnSlot < OWE_MAX_SPAWNS; spawnSlot++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(GetLocalIdByOverworldSpawnSlot(spawnSlot))];
        if (OW_SPECIES(slotMon) != SPECIES_NONE && (!(slotMon->sOverworldEncounterLevel & OWE_NO_REPLACE_FLAG) || forceRemove == TRUE))
        {
            oldest = slotMon;
            break;
        }
    }

    if (spawnSlot >= OWE_MAX_SPAWNS)
        return INVALID_SPAWN_SLOT;

    for (spawnSlot = 0; spawnSlot < OWE_MAX_SPAWNS; spawnSlot++)
    {
        slotMon = &gObjectEvents[GetObjectEventIdByLocalId(GetLocalIdByOverworldSpawnSlot(spawnSlot))];
        if (OW_SPECIES(slotMon) != SPECIES_NONE && (!(slotMon->sOverworldEncounterLevel & OWE_NO_REPLACE_FLAG) || forceRemove == TRUE))
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

    // All mon slots are in use
    if (GetNumberActiveOverworldEncounters(OWE_GENERATED) >= OWE_MAX_SPAWNS)
    {
        if (OWE_WILD_ENCOUNTERS_SPAWN_REPLACEMENT)
        {
            // Cycle through so we remove the oldest mon first
            spawnSlot = GetOldestSlot(FALSE);
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
        for (spawnSlot = 0; spawnSlot < OWE_MAX_SPAWNS; spawnSlot++)
        {
            if (GetOverworldSpeciesBySpawnSlot(spawnSlot) == SPECIES_NONE)
                break;
        }
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

    // Spawn further away when surfing
    if (OWE_ShouldSpawnWaterMons())
        closeDistance = OWE_SPAWN_DISTANCE_WATER;
    else
        closeDistance = OWE_SPAWN_DISTANCE_LAND;

    // Select a random tile in [-7, -4] [7, 4] range
    // Make sure is not directly next to player
    // Can we make get random tile its own function for use elsewhere in the codebase?
    // Have defines used and then replace MAP_METATILE_VIEW_X/Y with them
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
    if (OWE_ShouldSpawnWaterMons() && MetatileBehavior_IsWaterWildEncounter(tileBehavior))
        isEncounterTile = TRUE;

    if (!OWE_ShouldSpawnWaterMons() && (MetatileBehavior_IsLandWildEncounter(tileBehavior) || MetatileBehavior_IsIndoorEncounter(tileBehavior)))
        isEncounterTile = TRUE;

    if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS
        || gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
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
    u32 headerId = GetCurrentMapWildMonHeaderId();
    struct ObjectEvent *object = &gObjectEvents[objEventId];
    u32 indexRoamerOutbreak = object->sRoamerOutbreakStatus;

    assertf(objEventId < OBJECT_EVENTS_COUNT && IsOverworldWildEncounter(object, OWE_ANY), "cannot start overworld wild enocunter as the selected object is invalid.\nlocalId: %d", localId)
    {
        UnlockPlayerFieldControls();
        UnfreezeObjectEvents();
        return;
    }

    if (indexRoamerOutbreak && CreateOverworldWildEncounter_CheckRoamer(OWE_GetObjectRoamerOutbreakStatus(object)))
        return;

    u16 speciesId = OW_SPECIES(object);
    bool32 shiny = OW_SHINY(object) ? TRUE : FALSE;
    u32 gender = OW_FEMALE(object) ? MON_FEMALE : MON_MALE;
    u32 level = (object->sOverworldEncounterLevel &= ~OWE_NO_REPLACE_FLAG);
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
    
    if (CreateOverworldWildEncounter_CheckBattleFrontier(headerId))
        return;
    
    if (CreateOverworldWildEncounter_CheckMassOutbreak(indexRoamerOutbreak, speciesId))
        return;

    if (CreateOverworldWildEncounter_CheckDoubleBattle(object, headerId))
        return;

    BattleSetup_StartWildBattle();
}

static bool32 CreateOverworldWildEncounter_CheckRoamer(u32 indexRoamerOutbreak)
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

static bool32 CreateOverworldWildEncounter_CheckBattleFrontier(u32 headerId)
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

static bool32 CreateOverworldWildEncounter_CheckMassOutbreak(u32 indexRoamerOutbreak, u32 speciesId)
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

static bool32 CreateOverworldWildEncounter_CheckDoubleBattle(struct ObjectEvent *objectEvent, u32 headerId)
{
    enum WildPokemonArea wildArea;
    enum TimeOfDay timeOfDay;
    const struct WildPokemonInfo *wildMonInfo;
    u32 metatileBehavior = MapGridGetMetatileBehaviorAt(objectEvent->currentCoords.x, objectEvent->currentCoords.y);

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

struct AgeSort
{
    u8 slot:4;
    u8 age:4;
};

static void SortOWEMonAges(void)
{
    struct ObjectEvent *slotMon;
    struct AgeSort array[OWE_MAX_SPAWNS];
    struct AgeSort current;
    u32 numActive = GetNumberActiveOverworldEncounters(OWE_GENERATED);
    u32 count = 0;
    s32 i, j;

    for (i = 0; i < OWE_MAX_SPAWNS; i++)
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
    if (!IsOverworldWildEncounter(objectEvent, OWE_ANY))
        return;
    
    if (IsOverworldWildEncounter(objectEvent, OWE_GENERATED))
        SortOWEMonAges();

    OWE_DoSpawnDespawnAnim(objectEvent, TRUE);
}

void OverworldWildEncounter_OnObjectEventRemoved(struct ObjectEvent *objectEvent)
{
    if (!IsOverworldWildEncounter(objectEvent, OWE_ANY))
        return;

    if (IsOverworldWildEncounter(objectEvent, OWE_MANUAL))
        FlagSet(GetObjectEventFlagIdByLocalIdAndMap(objectEvent->localId, objectEvent->mapNum, objectEvent->mapGroup));

    objectEvent->sOverworldEncounterLevel = 0;
    objectEvent->sAge = 0;
    objectEvent->sRoamerOutbreakStatus = 0;
    
    OWE_DoSpawnDespawnAnim(objectEvent, FALSE);
}

u32 GetOverworldEncounterObjectEventGraphicsId(s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level, u32 *indexRoamerOutbreak)
{
    SetOverworldEncounterSpeciesInfo(x, y, speciesId, isShiny, isFemale, level, indexRoamerOutbreak);
    assertf(OWE_CheckSpecies(*speciesId), "invalid generated overworld encounter\nspecies: %d\ncheck if valid wild mon header exists", speciesId, x, y);
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

static void SetOverworldEncounterSpeciesInfo(s32 x, s32 y, u16 *speciesId, bool32 *isShiny, bool32 *isFemale, u32 *level, u32 *indexRoamerOutbreak)
{
    u32 personality;

    if (!OWE_CreateEnemyPartyMon(speciesId, level, indexRoamerOutbreak, x, y))
    {
        ZeroEnemyPartyMons();
        *speciesId = SPECIES_NONE;
        return;
    }
 
    *speciesId = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES);
    *level = GetMonData(&gEnemyParty[0], MON_DATA_LEVEL);
    personality = GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY);

    if (*speciesId == SPECIES_UNOWN)
        *speciesId = GetUnownSpeciesId(personality);

    *isShiny = ComputePlayerShinyOdds(personality, READ_OTID_FROM_SAVE);
    if (GetGenderFromSpeciesAndPersonality(*speciesId, personality) == MON_FEMALE)
        *isFemale = TRUE;
    else
        *isFemale = FALSE;

    if ((OWE_WILD_ENCOUNTERS_PREVENT_SHINY_REPLACEMENT && *isShiny))
        *level |= OWE_NO_REPLACE_FLAG;

    ZeroEnemyPartyMons();
}

static bool32 OWE_CreateEnemyPartyMon(u16 *speciesId, u32 *level, u32 *indexRoamerOutbreak, s32 x, s32 y)
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

    if (TryStartRoamerEncounter() && !OWE_DoesRoamerObjectExist() && *indexRoamerOutbreak != OWE_INVALID_ROAMER_OUTBREAK)
    {
        *indexRoamerOutbreak = OWE_GetObjectRoamerStatusFromIndex(gEncounteredRoamerIndex);
    }
    else if (OWE_WILD_ENCOUNTERS_FEEBAS_SPOTS && MetatileBehavior_IsWaterWildEncounter(metatileBehavior) && CheckFeebasAtCoords(x, y))
    {
        *level = ChooseWildMonLevel(&gWildFeebas, 0, WILD_AREA_FISHING);
        if (OWE_WILD_ENCOUNTERS_PREVENT_FEEBAS_REPLACEMENT)
            *level |= OWE_NO_REPLACE_FLAG;
        *speciesId = gWildFeebas.species;
        CreateWildMon(*speciesId, *level);
    }
    else if (DoMassOutbreakEncounterTest() && MetatileBehavior_IsLandWildEncounter(metatileBehavior) && *indexRoamerOutbreak != OWE_INVALID_ROAMER_OUTBREAK)
    {
        SetUpMassOutbreakEncounter(0);
        *indexRoamerOutbreak = OWE_MASS_OUTBREAK_INDEX;
    }
    else if (!TryGenerateWildMon(wildMonInfo, wildArea, 0))
    {
        return FALSE;
    }

    return TRUE;
}

static bool8 IsSafeToSpawnObjectEvents(void)
{
    struct ObjectEvent* player = &gObjectEvents[gPlayerAvatar.objectEventId];

    // Only spawn when player is at a valid tile position
    return (player->currentCoords.x == player->previousCoords.x && player->currentCoords.y == player->previousCoords.y);
}

u32 GetNumberActiveOverworldEncounters(enum OverworldObjectEncounterType oweType)
{
    u32 numActive = 0;
    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (IsOverworldWildEncounter(&gObjectEvents[i], oweType))
            numActive++;
    }
    return numActive;
}

static bool32 OWE_ShouldSpawnWaterMons(void)
{
    // Needs refactoring, and this replacing with a check for coords in many cases.
    return TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING | PLAYER_AVATAR_FLAG_UNDERWATER);
}

void RemoveAllGeneratedOverworldEncounterObjects(void)
{
    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; ++i)
    {
        struct ObjectEvent *obj = &gObjectEvents[i];
        if (IsOverworldWildEncounter(obj, OWE_GENERATED) && obj->active)
            RemoveObjectEvent(obj);
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

bool32 IsOverworldWildEncounter(struct ObjectEvent *objectEvent, enum OverworldObjectEncounterType oweType)
{
    bool32 isOWE = (objectEvent->graphicsId & OBJ_EVENT_MON) && (objectEvent->trainerType == TRAINER_TYPE_OW_WILD_ENCOUNTER);
    switch (oweType)
    {
    default:
    case OWE_ANY:
        return isOWE;
    
    case OWE_GENERATED:
        return isOWE && (objectEvent->localId <= LOCALID_OW_ENCOUNTER_END
            && objectEvent->localId > (LOCALID_OW_ENCOUNTER_END - OWE_MAX_SPAWNS));

    case OWE_MANUAL:
        return isOWE && (objectEvent->localId > LOCALID_OW_ENCOUNTER_END
            || objectEvent->localId <= (LOCALID_OW_ENCOUNTER_END - OWE_MAX_SPAWNS));
    }
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
    
    for (i = 0; i < OWE_MAX_SPAWNS; i++)
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
    return (OWE_WILD_ENCOUNTERS_OVERWORLD && GetNumberActiveOverworldEncounters(OWE_GENERATED) != 0
        && (localId <= (LOCALID_OW_ENCOUNTER_END - OWE_MAX_SPAWNS + 1)
        || localId > LOCALID_OW_ENCOUNTER_END));
}

u32 RemoveOldestGeneratedOverworldEncounter(void)
{
    u32 oldestSlot = GetOldestSlot(TRUE);

    if (oldestSlot == INVALID_SPAWN_SLOT)
        return OBJECT_EVENTS_COUNT;

    u32 objectEventId = GetObjectEventIdByLocalId(GetLocalIdByOverworldSpawnSlot(oldestSlot));
    RemoveObjectEvent(&gObjectEvents[objectEventId]);
    return objectEventId;
}

bool32 ShouldRunOverworldEncounterScript(u32 objectEventId)
{
    struct ObjectEvent *object = &gObjectEvents[objectEventId];
    if (!IsOverworldWildEncounter(object, OWE_ANY))
        return FALSE;

    if (IsOverworldWildEncounter(object, OWE_MANUAL)
        && GetObjectEventScriptPointerByObjectEventId(objectEventId) != InteractWithDynamicWildOverworldEncounter
        && GetObjectEventScriptPointerByObjectEventId(objectEventId) != NULL)
        return FALSE;

    gSpecialVar_0x8004 = OW_SPECIES(object);
    return TRUE;
}

const struct ObjectEventTemplate TryGetObjectEventTemplateForOverworldEncounter(const struct ObjectEventTemplate *template)
{
    if (template->trainerType != TRAINER_TYPE_OW_WILD_ENCOUNTER || (template->localId <= LOCALID_OW_ENCOUNTER_END
        && template->localId > (LOCALID_OW_ENCOUNTER_END - OWE_MAX_SPAWNS)))
        return *template;

    struct ObjectEventTemplate templateOWE = *template;
    
    // Does this work?
    u32 graphicsId;
    u16 speciesId, speciesTemplate = SanitizeSpeciesId(templateOWE.graphicsId & OBJ_EVENT_MON_SPECIES_MASK);
    bool32 isShiny = FALSE, isShinyTemplate = (templateOWE.graphicsId & OBJ_EVENT_MON_SHINY) ? TRUE : FALSE;
    bool32 isFemale = FALSE;
    u32 level, levelTemplate = templateOWE.sOverworldEncounterLevel;
    u32 indexRoamerOutbreak = OWE_INVALID_ROAMER_OUTBREAK;
    u32 x = template->x;
    u32 y = template->y;

    SetOverworldEncounterSpeciesInfo(
        x,
        y,
        &speciesId,
        &isShiny,
        &isFemale,
        &level,
        &indexRoamerOutbreak
    );

    if (speciesTemplate)
        speciesId = speciesTemplate;

    assertf(OWE_CheckSpecies(speciesId), "invalid manual overworld encounter\nspecies: %d\nx: %d y: %d\ncheck if valid wild mon header exists", speciesId, x, y)
    {
        // Currently causes assertf on each player step as function is called.
        templateOWE.graphicsId = OBJ_EVENT_GFX_BOY_1;
        templateOWE.trainerType = TRAINER_TYPE_NONE;
        templateOWE.sOverworldEncounterLevel = 0;
        templateOWE.movementType = MOVEMENT_TYPE_NONE;
        return templateOWE;
    }

    if (isShinyTemplate)
        isShiny = isShinyTemplate;

    if (templateOWE.graphicsId & OBJ_EVENT_MON && templateOWE.graphicsId & OBJ_EVENT_MON_FEMALE)
        isFemale = TRUE;
    else if (templateOWE.graphicsId & OBJ_EVENT_MON)
        isFemale = FALSE;
    else
        isFemale = GetGenderFromSpeciesAndPersonality(speciesId, Random32()) == MON_FEMALE;

    if (levelTemplate)
        level = levelTemplate;

    assertf(level >= MIN_LEVEL && level <= MAX_LEVEL, "invalid manual overworld encounter\nlevel: %d\nspecies: %d\nx: %d y: %d\ncheck if valid wild mon header exists", level, speciesId, x, y)
    {
        level = MIN_LEVEL;
    }

    if (templateOWE.movementType == MOVEMENT_TYPE_NONE)
        templateOWE.movementType = OWE_GetMovementTypeFromSpecies(speciesId);

    if (templateOWE.script == NULL)
        templateOWE.script = InteractWithDynamicWildOverworldEncounter;

    graphicsId = speciesId + OBJ_EVENT_MON;
    if (isFemale)
        graphicsId += OBJ_EVENT_MON_FEMALE;
    if (isShiny)
        graphicsId += OBJ_EVENT_MON_SHINY;

    templateOWE.graphicsId = graphicsId;
    templateOWE.sOverworldEncounterLevel = level;
    
    return templateOWE;
}

void OWE_TryTriggerEncounter(struct ObjectEvent *obstacle, struct ObjectEvent *collider)
{
    // The only automatically interacts with an OW Encounter when;
    // Not using a repel or the DexNav is inactive.
    if (REPEL_STEP_COUNT || FlagGet(DN_FLAG_SEARCHING))
        return;

    bool32 playerIsCollider = (collider->isPlayer && IsOverworldWildEncounter(obstacle, OWE_ANY));
    bool32 playerIsObstacle = (obstacle->isPlayer && IsOverworldWildEncounter(collider, OWE_ANY));

    if (!(playerIsCollider || playerIsObstacle))
        return;

    struct ObjectEvent *wildMon = playerIsCollider ? obstacle : collider;
    if (wildMon->sRoamerOutbreakStatus && !IsRoamerAt(OWE_GetObjectRoamerOutbreakStatus(wildMon),
        gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum))
    {
        RemoveObjectEvent(wildMon);
        return;
    }

    OWE_StartEncounter(wildMon);
}

void OverworldWildEncounter_RemoveObjectOnBattle(void)
{
    struct ObjectEvent *object = &gObjectEvents[GetObjectEventIdByLocalId(gSpecialVar_LastTalked)];
    if (IsOverworldWildEncounter(object, OWE_ANY))
    {
        RemoveObjectEvent(object);
        OWE_SetNewSpawnCountdown();
        gSpecialVar_LastTalked = LOCALID_NONE;
    }
}

// Returns TRUE if movement is restricted.
bool32 OWE_CheckRestrictedMovement(struct ObjectEvent *objectEvent, enum Direction direction)
{
    if (GetCollisionInDirection(objectEvent, direction))
        return TRUE;

    if (OWE_CanAwareMonSeePlayer(objectEvent) && OWE_WILD_ENCOUNTERS_UNRESTRICT_SIGHT)
        return FALSE;

    s32 xCurrent = objectEvent->currentCoords.x;
    s32 yCurrent = objectEvent->currentCoords.y;
    s32 xNew = xCurrent + gDirectionToVectors[direction].x;
    s32 yNew = yCurrent + gDirectionToVectors[direction].y;

    if (OWE_CheckRestrictMovementMetatile(xCurrent, yCurrent, xNew, yNew))
        return TRUE;
    
    if (OWE_CheckRestrictMovementMap(objectEvent, xNew, yNew))
        return TRUE;

    return FALSE;
}

bool32 OWE_CanAwareMonSeePlayer(struct ObjectEvent *mon)
{
    if (!IsOverworldWildEncounter(mon, OWE_ANY) || mon->movementType == MOVEMENT_TYPE_WANDER_AROUND_OWE)
        return FALSE;

    if (OWE_IsPlayerInsideMonActiveDistance(mon) && (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_DASH)
     || (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_BIKE) && gPlayerAvatar.runningState == MOVING)))
        return TRUE;

    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    u32 speciesId = OW_SPECIES(mon);
    u32 viewDistance = OWE_GetViewDistanceFromSpecies(speciesId);
    u32 viewWidth = OWE_GetViewWidthFromSpecies(speciesId);
    s32 halfWidth = (viewWidth - 1) / 2;
    enum Direction direction = mon->facingDirection;
    bool32 retVal = FALSE;

    switch (direction)
    {
    case DIR_NORTH:
        if (player->currentCoords.y < mon->currentCoords.y
         && mon->currentCoords.y - player->currentCoords.y <= viewDistance
         && player->currentCoords.x >= mon->currentCoords.x - halfWidth
         && player->currentCoords.x <= mon->currentCoords.x + halfWidth)
            retVal = TRUE;
        break;

    case DIR_SOUTH:
        if (player->currentCoords.y > mon->currentCoords.y
         && player->currentCoords.y - mon->currentCoords.y <= viewDistance
         && player->currentCoords.x >= mon->currentCoords.x - halfWidth
         && player->currentCoords.x <= mon->currentCoords.x + halfWidth)
            retVal = TRUE;
        break;

    case DIR_EAST:
        if (player->currentCoords.x > mon->currentCoords.x
         && player->currentCoords.x - mon->currentCoords.x <= viewDistance
         && player->currentCoords.y >= mon->currentCoords.y - halfWidth
         && player->currentCoords.y <= mon->currentCoords.y + halfWidth)
            retVal = TRUE;
        break;

    case DIR_WEST:
        if (player->currentCoords.x < mon->currentCoords.x
         && mon->currentCoords.x - player->currentCoords.x <= viewDistance
         && player->currentCoords.y >= mon->currentCoords.y - halfWidth
         && player->currentCoords.y <= mon->currentCoords.y + halfWidth)
            retVal = TRUE;
        break;

    default:
        retVal = FALSE;
        break;
    }

    if (retVal && OWE_IsLineOfSightClear(player, GetOppositeDirection(direction), viewDistance))
        return TRUE;
    
    return FALSE;
}

bool32 OWE_IsPlayerInsideMonActiveDistance(struct ObjectEvent *mon)
{
    if (!IsOverworldWildEncounter(mon, OWE_ANY))
        return FALSE;
    
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    u32 distance = OWE_CHASE_RANGE;
    u32 speciesId = OW_SPECIES(mon);

    if (speciesId != SPECIES_NONE)
        distance = OWE_GetViewActiveDistanceFromSpecies(speciesId);

    if (player->currentCoords.y <= mon->currentCoords.y + distance && player->currentCoords.y >= mon->currentCoords.y - distance
     && player->currentCoords.x <= mon->currentCoords.x + distance && player->currentCoords.x >= mon->currentCoords.x - distance)
        return TRUE;

    return FALSE;
}

static bool32 OWE_CheckRestrictedMovementAtCoords(struct ObjectEvent *mon, s16 xNew, s16 yNew, enum Direction newDirection, enum Direction collisionDirection)
{
    if (OWE_CheckRestrictMovementMetatile(mon->currentCoords.x, mon->currentCoords.y, xNew, yNew))
        return FALSE;

    if (OWE_CheckRestrictMovementMap(mon, xNew, yNew))
        return FALSE;

    if (GetCollisionAtCoords(mon, xNew, yNew, collisionDirection))
        return FALSE;

    return TRUE;
}

static u32 OWE_CheckPathToPlayerFromCollision(struct ObjectEvent *mon, enum Direction newDirection)
{
    s16 x = mon->currentCoords.x;
    s16 y = mon->currentCoords.y;

    MoveCoords(newDirection, &x, &y);
    if (OWE_CheckRestrictedMovementAtCoords(mon, x, y, newDirection, newDirection))
    {
        if (mon->movementType == MOVEMENT_TYPE_FLEE_PLAYER_OWE)
            return GetOppositeDirection(newDirection);

        MoveCoords(mon->movementDirection, &x, &y);
        if (OWE_CheckRestrictedMovementAtCoords(mon, x, y, newDirection, mon->movementDirection))
            return newDirection;
    }

    x = mon->currentCoords.x;
    y = mon->currentCoords.y;
    MoveCoords(GetOppositeDirection(newDirection), &x, &y);
    if (OWE_CheckRestrictedMovementAtCoords(mon, x, y, newDirection, newDirection))
    {
        if (mon->movementType == MOVEMENT_TYPE_FLEE_PLAYER_OWE)
            return newDirection;

        MoveCoords(mon->movementDirection, &x, &y);
        if (OWE_CheckRestrictedMovementAtCoords(mon, x, y, newDirection, mon->movementDirection))
            return GetOppositeDirection(newDirection);
    }

    return mon->movementDirection;
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
            return OWE_CheckPathToPlayerFromCollision(mon, (Random() % 2) == 0 ? DIR_EAST : DIR_WEST);
        else
            return DIR_EAST;
    case DIR_EAST:
    case DIR_WEST:
        if (player->currentCoords.y < mon->currentCoords.y)
            return DIR_NORTH;
        else if (player->currentCoords.y == mon->currentCoords.y)
            return OWE_CheckPathToPlayerFromCollision(mon, (Random() % 2) == 0 ? DIR_NORTH : DIR_SOUTH);
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

u32 OWE_GetApproachingMonDistanceToPlayer(struct ObjectEvent *mon, bool32 *equalDistances)
{
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    s16 absX, absY;
    s16 distanceX = player->currentCoords.x - mon->currentCoords.x;
    s16 distanceY = player->currentCoords.y - mon->currentCoords.y;

    // Get absolute X distance.
    if (distanceX < 0)
        absX = distanceX * -1;
    else
        absX = distanceX;

    // Get absolute Y distance.
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

enum OverworldEncounterSpawnAnim OWE_GetSpawnDespawnAnimType(u32 metatileBehavior)
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

static struct ObjectEvent *OWE_GetRandomActiveEncounterObject(void)
{
    u32 numActive = GetNumberActiveOverworldEncounters(OWE_ANY);
    u32 randomIndex;
    u32 counter = 0;
    struct ObjectEvent *object;

    if (numActive)
        randomIndex = Random() % numActive;
    else
        return NULL;
    
    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        object = &gObjectEvents[i];
        if (IsOverworldWildEncounter(object, OWE_ANY))
        {
            if (counter >= randomIndex)
                return object;
            else
                counter++;
        }
    }
    return NULL;
}

static void OWE_PlayMonObjectCry(struct ObjectEvent *objectEvent)
{
    if (!IsOverworldWildEncounter(objectEvent, OWE_ANY))
        return;

    // TESTING: Setting this species can be used as a test to play a consistent sound to check how often the
    //          code in UpdateOverworldEncounters runs, as OWE_GetRandomActiveEncounterObject cuurently returns
    //          NULL.
    if (objectEvent == NULL)
        return;
    
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    u32 speciesId = OW_SPECIES(objectEvent);
    s32 distanceX = objectEvent->currentCoords.x - player->currentCoords.x;
    s32 distanceY = objectEvent->currentCoords.y - player->currentCoords.y;
    u32 distanceMax = OWE_SPAWN_RADUIS_WIDTH + OWE_SPAWN_RADUIS_HEIGHT;
    u32 distance;
    u32 volume;
    s32 pan;

    if (distanceX > OWE_SPAWN_RADUIS_WIDTH)
        distanceX = OWE_SPAWN_RADUIS_WIDTH;
    else if (distanceX < -OWE_SPAWN_RADUIS_WIDTH)
        distanceX = -OWE_SPAWN_RADUIS_WIDTH;

    distanceY = abs(distanceY);
    if (distanceY > OWE_SPAWN_RADUIS_HEIGHT)
        distanceY = OWE_SPAWN_RADUIS_HEIGHT;

    distance = abs(distanceX) + distanceY;
    if (distance > distanceMax)
        distance = distanceMax;

    volume = 80 - (distance * (80 - 50)) / distanceMax;
    pan = 212 + ((distanceX + OWE_SPAWN_RADUIS_WIDTH) * (300 - 212)) / (2 * OWE_SPAWN_RADUIS_WIDTH);
    
    PlayCry_NormalNoDucking(speciesId, pan, volume, CRY_PRIORITY_AMBIENT);
}

static bool32 OWE_DoesRoamerObjectExist(void)
{
    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        struct ObjectEvent *object = &gObjectEvents[i];
        if (IsOverworldWildEncounter(object, OWE_ANY) && OWE_GetObjectRoamerOutbreakStatus(object) == gEncounteredRoamerIndex)
            return TRUE;
    }

    return FALSE;
}

static bool32 OWE_CheckRestrictMovementMetatile(s32 xCurrent, s32 yCurrent, s32 xNew, s32 yNew)
{
    if (!OWE_WILD_ENCOUNTERS_RESTRICT_METATILE)
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

static bool32 OWE_CheckRestrictMovementMap(struct ObjectEvent *objectEvent, s32 xNew, s32 yNew)
{
    if (!OWE_WILD_ENCOUNTERS_RESTRICT_MAP)
        return FALSE;
    
    if (objectEvent->mapGroup == gSaveBlock1Ptr->location.mapGroup
        && objectEvent->mapNum == gSaveBlock1Ptr->location.mapNum)
        return !AreCoordsInsidePlayerMap(xNew, yNew);
    else
        return AreCoordsInsidePlayerMap(xNew, yNew);
}

static bool32 OWE_ShouldPlayMonFleeSound(struct ObjectEvent *objectEvent)
{
    if (!IsOverworldWildEncounter(objectEvent, OWE_ANY) || OW_SPECIES(objectEvent) == SPECIES_NONE)
        return FALSE;

    if (!AreCoordsInsidePlayerMap(objectEvent->currentCoords.x, objectEvent->currentCoords.y))
        return FALSE;

    if (OWE_ShouldDespawnGeneratedForNewOWE(objectEvent))
        return FALSE;

    if (IsObjectEventOutsideView(objectEvent))
        return FALSE;

    return OWE_WILD_ENCOUNTERS_DESPAWN_SOUND;

}

static u32 OWE_GetObjectRoamerStatusFromIndex(u32 index)
{
    if (index < ROAMER_COUNT)
        return index + 1;
    
    return index;
}

static u32 OWE_GetObjectRoamerOutbreakStatus(struct ObjectEvent *objectEvent)
{
    if (!IsOverworldWildEncounter(objectEvent, OWE_ANY))
        return OWE_INVALID_ROAMER_OUTBREAK;

    u32 status = objectEvent->sRoamerOutbreakStatus;
    if (status == OWE_NON_ROAMER_OUTBREAK || status == OWE_MASS_OUTBREAK_INDEX)
    {
        return OWE_INVALID_ROAMER_OUTBREAK;
    }
    
    return status - 1;
}

bool32 OverworldWildEncounter_ShouldDisableRandomEncounters(void)
{
    if ((gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PIKE_ROOM_WILD_MONS && !OWE_WILD_ENCOUNTERS_BATTLE_PIKE)
        || (CurrentBattlePyramidLocation() && !OWE_WILD_ENCOUNTERS_BATTLE_PYRAMID))
        return FALSE;

    return !OWE_VANILLA_RANDOM_ENCOUNTERS;
}

static bool32 OWE_ShouldDespawnGeneratedForNewOWE(struct ObjectEvent *object)
{
    if (!IsOverworldWildEncounter(object, OWE_GENERATED))
        return FALSE;

    return OWE_WILD_ENCOUNTERS_SPAWN_REPLACEMENT && GetNumberActiveOverworldEncounters(OWE_GENERATED) >= OWE_MAX_SPAWNS;
}

void OWE_StartEncounter(struct ObjectEvent *mon)
{
    gSpecialVar_LastTalked = mon->localId;
    gSpecialVar_0x8004 = OW_SPECIES(mon);
    gSelectedObjectEvent = GetObjectEventIdByLocalId(mon->localId);

    // Stop the bobbing animation.
    if (mon->movementActionId >= MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_DOWN && mon->movementActionId <= MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_RIGHT)
        ClearObjectEventMovement(mon, &gSprites[mon->spriteId]);

    ScriptContext_SetupScript(InteractWithDynamicWildOverworldEncounter);
}

bool32 OWE_DespawnMonDueToNPCCollision(struct ObjectEvent *curObject, struct ObjectEvent *objectEvent)
{
    if (!IsOverworldWildEncounter(curObject, OWE_GENERATED) || IsOverworldWildEncounter(objectEvent, OWE_ANY) || objectEvent->isPlayer)
        return FALSE;

    RemoveObjectEvent(curObject);
    return TRUE;
}

u32 OWE_DespawnMonDueToTrainerSight(u32 collision, s16 x, s16 y)
{
    if (!(collision & (1 << (COLLISION_OBJECT_EVENT - 1))))
        return collision;

    struct ObjectEvent *objectEvent = &gObjectEvents[GetObjectEventIdByXY(x, y)];
    if (!IsOverworldWildEncounter(objectEvent, OWE_GENERATED))
        return collision;

    RemoveObjectEvent(objectEvent);
    return collision & (1 << (COLLISION_OBJECT_EVENT - 1));
}

struct SpritePalette OWE_GetSpawnAnimFldEffPalette(enum OverworldEncounterSpawnAnim spawnAnim)
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

#define sTypeFuncId data[1] // Same as in src/event_object_movement.c
void OWE_RestoreBehaviorState(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (IsOverworldWildEncounter(objectEvent, OWE_ANY) && objectEvent->sSavedMovementState & OWE_SAVED_MOVEMENT_STATE_FLAG)
        sprite->sTypeFuncId = OWE_RESTORED_MOVEMENT_FUNC_ID;
}
#undef sTypeFuncId

void OWE_SetSavedMovementState(struct ObjectEvent *objectEvent)
{
    objectEvent->sSavedMovementState |= OWE_SAVED_MOVEMENT_STATE_FLAG;
}

void OWE_ClearSavedMovementState(struct ObjectEvent *objectEvent)
{
    objectEvent->sSavedMovementState ^= OWE_SAVED_MOVEMENT_STATE_FLAG;
}

static bool32 OWE_IsLineOfSightClear(struct ObjectEvent *player, enum Direction direction, u32 distance)
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

#define tObjectId data[0]
void OWE_ApproachForBattle(void)
{
    u32 objectEventId = GetObjectEventIdByLocalId(gSpecialVar_LastTalked);
    struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
    if (!OWE_WILD_ENCOUNTERS_APPROACH_FOR_BATTLE || !IsOverworldWildEncounter(objectEvent, OWE_ANY))
    {
        FreezeObjectEvent(objectEvent);
        return;
    }
    
    if (!IsOverworldWildEncounter(objectEvent, OWE_ANY))
        return;
    
    u32 taskId = CreateTask(Task_OWE_ApproachForBattle, 2);
    if (FindTaskIdByFunc(Task_OWE_ApproachForBattle) == TASK_NONE)
    {
        FreezeObjectEvent(objectEvent);
        return;
    }
    
    ScriptContext_Stop();
    gTasks[taskId].tObjectId = objectEventId;
}

static void Task_OWE_ApproachForBattle(u8 taskId)
{
    struct ObjectEvent *OWE = &gObjectEvents[gTasks[taskId].tObjectId];

    // Let the mon continue to take steps until right next to the player.
    if (ObjectEventClearHeldMovementIfFinished(OWE))
    {
        struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
        if (OWE_IsMonNextToPlayer(OWE))
        {
            ObjectEventsTurnToEachOther(player, OWE);
            ScriptContext_Enable();
            DestroyTask(taskId);
            return;
        }

        u16 speciesId = OW_SPECIES(OWE);
        enum Direction direction = DetermineObjectEventDirectionFromObject(player, OWE);
        u8 movementActionId;
    
        SetObjectEventDirection(OWE, direction);
        movementActionId = OWE_GetWalkMovementActionInDirectionWithSpeed(OWE->movementDirection, OWE_GetActiveSpeedFromSpecies(speciesId));
        
        if (OWE_CheckRestrictedMovement(OWE, OWE->movementDirection))
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
                direction = OWE_DirectionToPlayerFromCollision(OWE);
                SetObjectEventDirection(OWE, direction);
                movementActionId = OWE_GetWalkMovementActionInDirectionWithSpeed(OWE->movementDirection, OWE_GetActiveSpeedFromSpecies(speciesId));
            }
        }
        ObjectEventSetHeldMovement(OWE, movementActionId);
    }
    
}
#undef tObjectId

u32 OWE_GetWalkMovementActionInDirectionWithSpeed(enum Direction direction, u32 speed)
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

static bool32 OWE_CheckSpecies(u32 speciesId)
{
    return speciesId != SPECIES_NONE
        && speciesId < NUM_SPECIES
        && IsSpeciesEnabled(speciesId);
}

void OWE_PlayAmbientCry(void)
{
    OWE_PlayMonObjectCry(OWE_GetRandomActiveEncounterObject());
}

#undef sOverworldEncounterLevel
#undef sAge
#undef sRoamerOutbreakStatus
#undef sSavedMovementState
