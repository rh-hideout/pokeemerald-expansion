#include "global.h"
#include "habitat/authoring.h"
#include "habitat/finale.h"
#include "habitat/spots.h"
#include "constants/items.h"
#include "constants/pokemon.h"
#include "constants/species.h"
#include "test/test.h"

static u32 CountConditions(const struct HabitatCondition *list, u8 type)
{
    u32 i, count = 0;

    for (i = 0; list[i].type != COND_NONE; i++)
        if (list[i].type == type)
            count++;
    return count;
}

TEST("Habitat authoring: unsupported types and exact resident stages are rejected")
{
    static const struct HabitatCondition sIllusion[] = {
        HABITAT_COND(COND_ILLUSION, SPECIES_ZORUA, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sRecipe[] = {
        HABITAT_COND(COND_GROVE_RECIPE_DONE, 1, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sExactResident[] = {
        HABITAT_COND(COND_RESIDENT_SPECIES, SPECIES_TREECKO, 0, 0, HABITAT_COND_EXACT_STAGE),
        HABITAT_CONDITIONS_END,
    };

    EXPECT(!Habitat_ConditionTypeIsSupported(COND_ILLUSION));
    EXPECT(!Habitat_ConditionTypeIsSupported(COND_GROVE_RECIPE_DONE));
    EXPECT(!Habitat_ValidateConditionList(sIllusion, HABITAT_CONDITION_SPOT_APPEAR));
    EXPECT(!Habitat_ValidateConditionList(sRecipe, HABITAT_CONDITION_SPOT_BEFRIEND));
    EXPECT(!Habitat_ValidateConditionList(sExactResident, HABITAT_CONDITION_SPOT_APPEAR));
}

TEST("Habitat authoring: battle wins belong only to the Deoxys finale")
{
    static const struct HabitatCondition sBattleWin[] = {
        HABITAT_COND(COND_BATTLE_WIN, 0, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    u32 i, battleWins = 0;

    EXPECT(!Habitat_ValidateConditionList(sBattleWin, HABITAT_CONDITION_SPOT_APPEAR));
    EXPECT(!Habitat_ValidateConditionList(sBattleWin, HABITAT_CONDITION_SPOT_BEFRIEND));
    EXPECT(Habitat_ValidateConditionList(sBattleWin, HABITAT_CONDITION_DEOXYS_FINALE));

    for (i = 0; gHabitatSpots[i].spotId != 0xFFFF; i++)
    {
        battleWins += CountConditions(gHabitatSpots[i].appearConditions, COND_BATTLE_WIN);
        battleWins += CountConditions(gHabitatSpots[i].befriendConditions, COND_BATTLE_WIN);
    }
    EXPECT_EQ(gHabitatDeoxysFinale.species, SPECIES_DEOXYS);
    battleWins += CountConditions(gHabitatDeoxysFinale.conditions, COND_BATTLE_WIN);
    EXPECT_EQ(battleWins, 1);
}

TEST("Habitat authoring: invalid lists are rejected before runtime")
{
    static const struct HabitatCondition sBadGroup[] = {
        HABITAT_COND(COND_STORY_FLAG, 1, 0, 0, HABITAT_COND_OR_GROUP(1)),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sNoQuantity[] = {
        HABITAT_COND(COND_ITEM_OFFERED, ITEM_CHERI_BERRY, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sBadZone[] = {
        HABITAT_COND(COND_BERRY_MATURE, ITEM_CHERI_BERRY, 0xFF, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sBadParameter[] = {
        HABITAT_COND(COND_RESIDENT_SPECIES, NUM_SPECIES, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sResidentZone[] = {
        HABITAT_COND(COND_RESIDENT_SPECIES, SPECIES_TREECKO, 1, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sResidentBadZone[] = {
        HABITAT_COND(COND_RESIDENT_SPECIES, SPECIES_TREECKO, 0xFF, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sResidentType[] = {
        HABITAT_COND(COND_RESIDENT_COUNT, TYPE_GRASS, 1, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sResidentAnyType[] = {
        HABITAT_COND(COND_RESIDENT_COUNT, HABITAT_TYPE_ANY, 1, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sResidentBadType[] = {
        HABITAT_COND(COND_RESIDENT_COUNT, NUMBER_OF_MON_TYPES, 1, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sTooLong[HABITAT_MAX_CONDITIONS + 2] = {
        [0 ... HABITAT_MAX_CONDITIONS] = HABITAT_COND(COND_STORY_FLAG, 1, 0, 0, 0),
        [HABITAT_MAX_CONDITIONS + 1] = HABITAT_CONDITIONS_END,
    };

    EXPECT(!Habitat_ValidateConditionList(sBadGroup, HABITAT_CONDITION_SPOT_APPEAR));
    EXPECT(!Habitat_ValidateConditionList(sNoQuantity, HABITAT_CONDITION_SPOT_BEFRIEND));
    EXPECT(!Habitat_ValidateConditionList(sBadZone, HABITAT_CONDITION_SPOT_APPEAR));
    EXPECT(!Habitat_ValidateConditionList(sBadParameter, HABITAT_CONDITION_SPOT_APPEAR));
    EXPECT(Habitat_ValidateConditionList(sResidentZone, HABITAT_CONDITION_SPOT_APPEAR));
    EXPECT(!Habitat_ValidateConditionList(sResidentBadZone, HABITAT_CONDITION_SPOT_APPEAR));
    EXPECT(Habitat_ValidateConditionList(sResidentType, HABITAT_CONDITION_SPOT_APPEAR));
    EXPECT(Habitat_ValidateConditionList(sResidentAnyType, HABITAT_CONDITION_SPOT_APPEAR));
    EXPECT(!Habitat_ValidateConditionList(sResidentBadType, HABITAT_CONDITION_SPOT_APPEAR));
    EXPECT(!Habitat_ValidateConditionList(sTooLong, HABITAT_CONDITION_SPOT_APPEAR));
}

TEST("Habitat authoring: duplicate spot ids are rejected")
{
    static const u8 sHint[] = _("test$");
    static const struct HabitatCondition sConditions[] = {
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatSpot sDuplicateIds[] = {
        {
            .spotId = 1, .species = SPECIES_SKITTY, .tier = 1, .zoneId = 1,
            .appearConditions = sConditions, .befriendConditions = sConditions,
            .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        },
        {
            .spotId = 1, .species = SPECIES_LOTAD, .tier = 1, .zoneId = 1,
            .appearConditions = sConditions, .befriendConditions = sConditions,
            .hintDormant = sHint, .hintStirring = sHint, .hintActive = sHint,
        },
        { .spotId = 0xFFFF },
    };

    EXPECT(!Habitat_ValidateSpotTable(sDuplicateIds));
}

TEST("Habitat authoring: production condition lists are individually valid")
{
    u32 i;

    for (i = 0; gHabitatSpots[i].spotId != 0xFFFF; i++)
    {
        EXPECT(Habitat_ValidateConditionList(gHabitatSpots[i].appearConditions,
                                              HABITAT_CONDITION_SPOT_APPEAR));
        EXPECT(Habitat_ValidateConditionList(gHabitatSpots[i].befriendConditions,
                                              HABITAT_CONDITION_SPOT_BEFRIEND));
    }
}

TEST("Habitat authoring: production data is valid and Machop wants one Cheri")
{
    const struct HabitatSpot *machop = Habitat_GetSpot(3);

    EXPECT(Habitat_ValidateAuthoredData());
    ASSUME(machop != NULL);
    EXPECT_EQ(machop->befriendConditions[0].type, COND_ITEM_OFFERED);
    EXPECT_EQ(machop->befriendConditions[0].paramA, ITEM_CHERI_BERRY);
    EXPECT_EQ(machop->befriendConditions[0].paramB, 1);
    EXPECT_EQ(machop->befriendConditions[1].type, COND_NONE);
}

TEST("Habitat authoring: dependency masks and contiguous map spans are validated")
{
    struct HabitatSpot badMask[2];
    struct HabitatSpot splitMap[] = {
        { .spotId = 1, .mapGroup = 1, .mapNum = 1 },
        { .spotId = 2, .mapGroup = 2, .mapNum = 1 },
        { .spotId = 3, .mapGroup = 1, .mapNum = 1 },
        { .spotId = 0xFFFF },
    };
    struct HabitatMapSpan overlapping[] = {
        { .mapGroup = gHabitatSpots[0].mapGroup, .mapNum = gHabitatSpots[0].mapNum, .firstSpot = 0, .count = 1 },
        { .mapGroup = gHabitatSpots[0].mapGroup, .mapNum = gHabitatSpots[0].mapNum, .firstSpot = 0, .count = 1 },
        { 0 },
    };
    struct HabitatMapSpan splitSpans[] = {
        { .mapGroup = 1, .mapNum = 1, .firstSpot = 0, .count = 1 },
        { .mapGroup = 2, .mapNum = 1, .firstSpot = 1, .count = 1 },
        { .mapGroup = 1, .mapNum = 1, .firstSpot = 2, .count = 1 },
        { 0 },
    };
    struct HabitatMapSpan outOfBounds[] = {
        { .mapGroup = gHabitatSpots[0].mapGroup, .mapNum = gHabitatSpots[0].mapNum, .firstSpot = 0, .count = HABITAT_SPOT_COUNT },
        { 0 },
    };

    memcpy(badMask, gHabitatSpots, sizeof(badMask));
    badMask[1].spotId = 0xFFFF;
    badMask[0].dependencyMask ^= HABITAT_DEP_MASK(HABITAT_DEP_TIME);
    EXPECT(!Habitat_ValidateSpotTable(badMask));
    EXPECT(!Habitat_ValidateMapSpans(gHabitatSpots, overlapping));
    EXPECT(!Habitat_ValidateMapSpans(splitMap, splitSpans));
    EXPECT(!Habitat_ValidateMapSpans(gHabitatSpots, outOfBounds));
    EXPECT(Habitat_ValidateMapSpans(gHabitatSpots, gHabitatMapSpans));
}
