#include "global.h"
#include "event_data.h"
#include "habitat/conditions.h"
#include "test/overworld_script.h"
#include "test/test.h"

// Scratch flags, safe to toggle in tests.
#define TEST_FLAG_A FLAG_UNUSED_0x020
#define TEST_FLAG_B FLAG_UNUSED_0x021

TEST("Habitat conditions: empty list is vacuously all-met and not any-met")
{
    static const struct HabitatCondition sList[] = { HABITAT_CONDITIONS_END };
    struct HabitatConditionResult r;
    Habitat_EvaluateConditions(sList, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT_EQ(r.count, 0);
    EXPECT(r.allMet);
    EXPECT(!r.anyMet);
}

TEST("Habitat conditions: standalone conditions AND together")
{
    static const struct HabitatCondition sList[] = {
        HABITAT_COND(COND_STORY_FLAG, TEST_FLAG_A, 0, 0, 0),
        HABITAT_COND(COND_STORY_FLAG, TEST_FLAG_B, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    FlagClear(TEST_FLAG_A);
    FlagClear(TEST_FLAG_B);
    Habitat_EvaluateConditions(sList, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT_EQ(r.count, 2);
    EXPECT(!r.allMet);
    EXPECT(!r.anyMet);

    FlagSet(TEST_FLAG_A);
    Habitat_EvaluateConditions(sList, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);
    EXPECT(r.anyMet);
    EXPECT_EQ(r.metMask, 1u << 0);

    FlagSet(TEST_FLAG_B);
    Habitat_EvaluateConditions(sList, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
    EXPECT_EQ(r.metMask, (1u << 0) | (1u << 1));
}

TEST("Habitat conditions: NEGATE inverts a condition")
{
    static const struct HabitatCondition sList[] = {
        HABITAT_COND(COND_STORY_FLAG, TEST_FLAG_A, 0, 0, HABITAT_COND_NEGATE),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    FlagClear(TEST_FLAG_A);
    Habitat_EvaluateConditions(sList, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);

    FlagSet(TEST_FLAG_A);
    Habitat_EvaluateConditions(sList, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);
}

TEST("Habitat conditions: OR-group passes when any member passes")
{
    static const struct HabitatCondition sList[] = {
        HABITAT_COND(COND_STORY_FLAG, TEST_FLAG_A, 0, 0, HABITAT_COND_OR_GROUP(1)),
        HABITAT_COND(COND_STORY_FLAG, TEST_FLAG_B, 0, 0, HABITAT_COND_OR_GROUP(1)),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    FlagClear(TEST_FLAG_A);
    FlagClear(TEST_FLAG_B);
    Habitat_EvaluateConditions(sList, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);

    FlagSet(TEST_FLAG_B);
    Habitat_EvaluateConditions(sList, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
    EXPECT(r.anyMet);
    EXPECT_EQ(r.metMask, 1u << 1);
}

TEST("Habitat conditions: standalone and OR-group combine correctly")
{
    static const struct HabitatCondition sList[] = {
        HABITAT_COND(COND_STORY_FLAG, TEST_FLAG_A, 0, 0, 0),
        HABITAT_COND(COND_STORY_FLAG, TEST_FLAG_B, 0, 0, HABITAT_COND_OR_GROUP(1)),
        HABITAT_COND(COND_STORY_FLAG, TEST_FLAG_B, 0, 0, HABITAT_COND_OR_GROUP(1) | HABITAT_COND_NEGATE),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    // Group 1 is (B OR !B) == always satisfiable; overall result tracks A.
    FlagClear(TEST_FLAG_A);
    FlagClear(TEST_FLAG_B);
    Habitat_EvaluateConditions(sList, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);
    EXPECT(r.anyMet);

    FlagSet(TEST_FLAG_A);
    Habitat_EvaluateConditions(sList, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
}
