#include "global.h"
#include "gba/isagbprint.h"
#include "habitat/migration.h"
#include "habitat/save.h"
#include "habitat/spots.h"

// These are the v0 placedCounters[8] meanings. They intentionally name the
// old slots only; their v2 destinations come from the authored paramC ids.
struct LegacyPlacedCounterMap
{
    u16 spotId;
    u8 conditionIndex;
};

struct LegacyResidentData
{
    u16 species;
    u8 personalitySeed;
    u8 assignment;
};

static const struct LegacyPlacedCounterMap sLegacyPlacedCounterMap[] = {
    { 1, 0 }, { 6, 0 }, { 7, 0 }, { 8, 0 },
    { 8, 1 }, { 9, 0 }, { 9, 1 }, { 9, 2 },
};

static const struct HabitatSpot *FindUniqueBefriendedSpot(u16 species, u32 residentSlot);
static bool32 LegacySpeciesIsRepeated(const struct LegacyResidentData *residents, u32 slot);
static bool32 OriginIsRegistered(u16 originSpotId, u32 throughSlot);
static void LogMigrationDiagnostic(const char *reason, u32 slot, u16 value);

void Habitat_MigrateSave(void)
{
    struct HabitatSave *save = &gSaveBlock3Ptr->habitat;
    struct LegacyResidentData legacyResidents[HABITAT_RESIDENT_COUNT];
    u32 i;

    if (save->saveVersion == HABITAT_SAVE_VERSION_CURRENT)
        return;
    if (save->saveVersion != HABITAT_SAVE_VERSION_LEGACY)
    {
        LogMigrationDiagnostic("save-version-unknown", save->saveVersion, 0);
        return;
    }

    // Read all v0 records before reusing their first two bytes as origins.
    for (i = 0; i < HABITAT_RESIDENT_COUNT; i++)
    {
        legacyResidents[i].species = save->residents[i].originSpotId;
        legacyResidents[i].personalitySeed = save->residents[i].personalitySeed;
        legacyResidents[i].assignment = save->residents[i].assignment;
    }
    for (i = 0; i < HABITAT_RESIDENT_COUNT; i++)
    {
        save->residents[i].originSpotId = HABITAT_SPOT_NONE;
        save->residents[i].personalitySeed = 0;
        save->residents[i].assignment = 0;
    }

    memset(save->placedConditionCounters, 0, sizeof(save->placedConditionCounters));
    for (i = 0; i < ARRAY_COUNT(sLegacyPlacedCounterMap); i++)
    {
        const struct HabitatSpot *spot = Habitat_GetSpot(sLegacyPlacedCounterMap[i].spotId);
        const struct HabitatCondition *condition;
        u16 counterId;

        if (save->placedCounters[i] > 15 || spot == NULL)
        {
            LogMigrationDiagnostic("placement", i, save->placedCounters[i]);
            continue;
        }
        condition = &spot->appearConditions[sLegacyPlacedCounterMap[i].conditionIndex];
        if (condition->type != COND_ITEM_PLACED)
        {
            LogMigrationDiagnostic("placement-map", i, spot->spotId);
            continue;
        }
        counterId = condition->paramC;
        if (counterId == 0 || counterId > HABITAT_PLACED_CONDITION_CAP)
        {
            LogMigrationDiagnostic("placement-id", i, counterId);
            continue;
        }
        Habitat_AddPlacedCount(counterId, save->placedCounters[i]);
    }

    for (i = 0; i < HABITAT_RESIDENT_COUNT; i++)
    {
        const struct HabitatSpot *spot;

        if (legacyResidents[i].species == SPECIES_NONE)
            continue;
        if (LegacySpeciesIsRepeated(legacyResidents, i))
        {
            LogMigrationDiagnostic("resident-duplicate", i, legacyResidents[i].species);
            continue;
        }
        spot = FindUniqueBefriendedSpot(legacyResidents[i].species, i);
        if (spot == NULL || OriginIsRegistered(spot->spotId, i))
        {
            if (spot != NULL)
                LogMigrationDiagnostic("resident-duplicate", i, legacyResidents[i].species);
            continue;
        }
        save->residents[i].originSpotId = spot->spotId;
        save->residents[i].personalitySeed = legacyResidents[i].personalitySeed;
        save->residents[i].assignment = legacyResidents[i].assignment;
    }

    // Version is written last so an interrupted migration always reruns.
    save->saveVersion = HABITAT_SAVE_VERSION_CURRENT;
}

static bool32 LegacySpeciesIsRepeated(const struct LegacyResidentData *residents, u32 slot)
{
    u32 i;

    for (i = 0; i < HABITAT_RESIDENT_COUNT; i++)
    {
        if (i != slot && residents[i].species == residents[slot].species)
            return TRUE;
    }
    return FALSE;
}

static const struct HabitatSpot *FindUniqueBefriendedSpot(u16 species, u32 residentSlot)
{
    const struct HabitatSpot *match = NULL;
    u32 i;

    for (i = 0; gHabitatSpots[i].spotId != 0xFFFF; i++)
    {
        if (gHabitatSpots[i].species != species
         || Habitat_GetSpotState(gHabitatSpots[i].spotId) != HABITAT_STATE_BEFRIENDED)
            continue;
        if (match != NULL)
        {
            LogMigrationDiagnostic("resident-ambiguous", residentSlot, species);
            return NULL;
        }
        match = &gHabitatSpots[i];
    }
    if (match == NULL)
        LogMigrationDiagnostic("resident-unmappable", residentSlot, species);
    return match;
}

static bool32 OriginIsRegistered(u16 originSpotId, u32 throughSlot)
{
    u32 i;

    for (i = 0; i < throughSlot; i++)
        if (gSaveBlock3Ptr->habitat.residents[i].originSpotId == originSpotId)
            return TRUE;
    return FALSE;
}

static void LogMigrationDiagnostic(const char *reason, u32 slot, u16 value)
{
    DebugPrintf("HABITAT_MIGRATION reason=%s slot=%u value=%u", reason, slot, value);
}
