#include "global.h"
#include "habitat/authoring.h"
#include "habitat/migration.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "constants/items.h"
#include "constants/species.h"
#include "test/test.h"

// Version 0 is the exact 820-byte HabitatSave written before versioning.
// Keep this fixture separate from the live struct so an append-only mistake
// cannot silently turn the compatibility test into a self-fulfilling copy.
struct LegacyHabitatResident
{
    u16 species;
    u8 personalitySeed;
    u8 assignment;
};

struct LegacyHabitatSave
{
    u8 spotStates[HABITAT_SPOT_COUNT];
    u8 talkCounters[HABITAT_TALK_COUNTER_COUNT];
    u8 placedCounters[HABITAT_PLACED_COUNTER_COUNT];
    struct LegacyHabitatResident residents[HABITAT_RESIDENT_COUNT];
    struct HabitatPlot plots[HABITAT_PLOT_COUNT];
    u32 lastGrowthMinutes;
};

STATIC_ASSERT(sizeof(struct LegacyHabitatSave) == 820, LegacyHabitatSaveMustStay820Bytes)

TEST("Habitat migration: version 0 preserves state and deterministically expands all legacy slots")
{
    struct LegacyHabitatSave legacy = {0};
    struct HabitatSave migrated;

    // The eight v0 placement slots map to authored condition ids 1..8.
    legacy.placedCounters[0] = 1;
    legacy.placedCounters[1] = 2;
    legacy.placedCounters[2] = 3;
    legacy.placedCounters[3] = 4;
    legacy.placedCounters[4] = 5;
    legacy.placedCounters[5] = 6;
    legacy.placedCounters[6] = 7;
    legacy.placedCounters[7] = 8;
    legacy.spotStates[1] = HABITAT_STATE_BEFRIENDED | 0xA0;
    legacy.spotStates[3] = HABITAT_STATE_BEFRIENDED | 0x50;
    legacy.spotStates[6] = HABITAT_STATE_ACTIVE | 0x20;
    legacy.talkCounters[0] = 9;
    legacy.lastGrowthMinutes = 12345;
    legacy.plots[2].berryItem = 99;
    legacy.plots[2].growthStage = 3;
    legacy.plots[2].worker1 = 0;
    legacy.plots[2].worker2 = 1;
    legacy.plots[2].hoursProgress = 47;
    legacy.residents[0] = (struct LegacyHabitatResident) {
        .species = SPECIES_MACHOP, .personalitySeed = 17, .assignment = 3,
    };
    legacy.residents[1] = (struct LegacyHabitatResident) {
        .species = SPECIES_SKITTY, .personalitySeed = 29, .assignment = 1,
    };
    // A befriended, but unmappable, legacy record must not be guessed.
    legacy.residents[2] = (struct LegacyHabitatResident) {
        .species = SPECIES_ZIGZAGOON, .personalitySeed = 91, .assignment = 2,
    };
    // A duplicate v0 record is corrupt: keep the befriended Machop spot but
    // do not guess which duplicate should own it.
    legacy.residents[3] = (struct LegacyHabitatResident) {
        .species = SPECIES_MACHOP, .personalitySeed = 44, .assignment = 2,
    };

    memset(&gSaveBlock3Ptr->habitat, 0xA5, sizeof(gSaveBlock3Ptr->habitat));
    memcpy(&gSaveBlock3Ptr->habitat, &legacy, sizeof(legacy));
    Habitat_MigrateSave();

    EXPECT_EQ(gSaveBlock3Ptr->habitat.saveVersion, HABITAT_SAVE_VERSION_CURRENT);
    EXPECT_EQ(Habitat_GetPlacedCount(1), 1);
    EXPECT_EQ(Habitat_GetPlacedCount(2), 2);
    EXPECT_EQ(Habitat_GetPlacedCount(3), 3);
    EXPECT_EQ(Habitat_GetPlacedCount(4), 4);
    EXPECT_EQ(Habitat_GetPlacedCount(5), 5);
    EXPECT_EQ(Habitat_GetPlacedCount(6), 6);
    EXPECT_EQ(Habitat_GetPlacedCount(7), 7);
    EXPECT_EQ(Habitat_GetPlacedCount(8), 8);
    EXPECT_EQ(gSaveBlock3Ptr->habitat.spotStates[1], legacy.spotStates[1]);
    EXPECT_EQ(gSaveBlock3Ptr->habitat.spotStates[3], legacy.spotStates[3]);
    EXPECT_EQ(gSaveBlock3Ptr->habitat.talkCounters[0], legacy.talkCounters[0]);
    EXPECT_EQ(gSaveBlock3Ptr->habitat.lastGrowthMinutes, legacy.lastGrowthMinutes);
    EXPECT_EQ(gSaveBlock3Ptr->habitat.plots[2].berryItem, legacy.plots[2].berryItem);
    EXPECT_EQ(gSaveBlock3Ptr->habitat.plots[2].hoursProgress, legacy.plots[2].hoursProgress);
    EXPECT_EQ(gSaveBlock3Ptr->habitat.residents[0].originSpotId, 3);
    EXPECT_EQ(gSaveBlock3Ptr->habitat.residents[0].personalitySeed, 17);
    EXPECT_EQ(gSaveBlock3Ptr->habitat.residents[0].assignment, 3);
    EXPECT_EQ(gSaveBlock3Ptr->habitat.residents[1].originSpotId, 1);
    EXPECT_EQ(gSaveBlock3Ptr->habitat.residents[1].personalitySeed, 29);
    EXPECT_EQ(gSaveBlock3Ptr->habitat.residents[1].assignment, 1);
    EXPECT_EQ(gSaveBlock3Ptr->habitat.residents[2].originSpotId, HABITAT_SPOT_NONE);
    EXPECT_EQ(gSaveBlock3Ptr->habitat.residents[3].originSpotId, HABITAT_SPOT_NONE);

    memcpy(&migrated, &gSaveBlock3Ptr->habitat, sizeof(migrated));
    Habitat_MigrateSave();
    EXPECT(memcmp(&migrated, &gSaveBlock3Ptr->habitat, sizeof(migrated)) == 0);
}

TEST("Habitat migration: authored placement ids reject duplicate, out-of-range, and oversized counts")
{
    static const u8 sHint[] = _("test$");
    static const struct HabitatCondition sDuplicateIds[] = {
        HABITAT_COND(COND_ITEM_PLACED, ITEM_POKE_DOLL, 1, 1, 0),
        HABITAT_COND(COND_ITEM_PLACED, ITEM_HONEY, 1, 1, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sOutOfRangeId[] = {
        HABITAT_COND(COND_ITEM_PLACED, ITEM_POKE_DOLL, 1, HABITAT_PLACED_CONDITION_CAP + 1, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sOversizedCount[] = {
        HABITAT_COND(COND_ITEM_PLACED, ITEM_POKE_DOLL, 16, 1, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatSpot sDuplicateIdSpotTable[] = {
        {
            .spotId = 1, .species = SPECIES_SKITTY, .tier = 1, .zoneId = 1,
            .appearConditions = sDuplicateIds, .befriendConditions = sOutOfRangeId,
            .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        },
        { .spotId = 0xFFFF },
    };

    EXPECT(!Habitat_ValidateSpotTable(sDuplicateIdSpotTable));
    EXPECT(!Habitat_ValidateConditionList(sOutOfRangeId, HABITAT_CONDITION_SPOT_APPEAR));
    EXPECT(!Habitat_ValidateConditionList(sOversizedCount, HABITAT_CONDITION_SPOT_APPEAR));
}
