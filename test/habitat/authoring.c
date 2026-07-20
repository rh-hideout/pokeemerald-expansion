#include "global.h"
#include "habitat/authoring.h"
#include "habitat/finale.h"
#include "habitat/spots.h"
#include "constants/items.h"
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
    static const struct HabitatCondition sTooLong[HABITAT_MAX_CONDITIONS + 2] = {
        [0 ... HABITAT_MAX_CONDITIONS] = HABITAT_COND(COND_STORY_FLAG, 1, 0, 0, 0),
        [HABITAT_MAX_CONDITIONS + 1] = HABITAT_CONDITIONS_END,
    };

    EXPECT(!Habitat_ValidateConditionList(sBadGroup, HABITAT_CONDITION_SPOT_APPEAR));
    EXPECT(!Habitat_ValidateConditionList(sNoQuantity, HABITAT_CONDITION_SPOT_BEFRIEND));
    EXPECT(!Habitat_ValidateConditionList(sBadZone, HABITAT_CONDITION_SPOT_APPEAR));
    EXPECT(!Habitat_ValidateConditionList(sBadParameter, HABITAT_CONDITION_SPOT_APPEAR));
    EXPECT(!Habitat_ValidateConditionList(sTooLong, HABITAT_CONDITION_SPOT_APPEAR));
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
