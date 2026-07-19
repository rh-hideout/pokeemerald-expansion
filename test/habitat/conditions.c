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

// ---- Party conditions (Task 3) ----

TEST("Habitat conditions: PARTY_SPECIES counts matching party members")
{
    static const struct HabitatCondition sOne[] = {
        HABITAT_COND(COND_PARTY_SPECIES, SPECIES_BULBASAUR, 1, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sTwo[] = {
        HABITAT_COND(COND_PARTY_SPECIES, SPECIES_BULBASAUR, 2, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    ZeroPlayerPartyMons();
    Habitat_EvaluateConditions(sOne, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);

    RUN_OVERWORLD_SCRIPT(givemon SPECIES_BULBASAUR, 10;);
    ASSUME(gPlayerPartyCount == 1);
    Habitat_EvaluateConditions(sOne, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
    Habitat_EvaluateConditions(sTwo, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);

    RUN_OVERWORLD_SCRIPT(givemon SPECIES_BULBASAUR, 10;);
    Habitat_EvaluateConditions(sTwo, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
}

TEST("Habitat conditions: PARTY_MOVE finds a known move")
{
    static const struct HabitatCondition sList[] = {
        HABITAT_COND(COND_PARTY_MOVE, MOVE_FLASH, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(givemon SPECIES_BULBASAUR, 10, move1=MOVE_TACKLE;);
    Habitat_EvaluateConditions(sList, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);

    RUN_OVERWORLD_SCRIPT(givemon SPECIES_ZIGZAGOON, 10, move1=MOVE_FLASH;);
    Habitat_EvaluateConditions(sList, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
}

TEST("Habitat conditions: PARTY_NATURE finds a matching nature")
{
    static const struct HabitatCondition sList[] = {
        HABITAT_COND(COND_PARTY_NATURE, NATURE_JOLLY, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(givemon SPECIES_BULBASAUR, 10, nature=NATURE_ADAMANT;);
    Habitat_EvaluateConditions(sList, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);

    RUN_OVERWORLD_SCRIPT(givemon SPECIES_BULBASAUR, 10, nature=NATURE_JOLLY;);
    Habitat_EvaluateConditions(sList, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
}

TEST("Habitat conditions: PARTY_FRIENDSHIP compares against any member")
{
    static const struct HabitatCondition sHigh[] = {
        HABITAT_COND(COND_PARTY_FRIENDSHIP, HABITAT_CMP_GE, 200, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sSpite[] = {  // Shuppet-style: LOW friendship
        HABITAT_COND(COND_PARTY_FRIENDSHIP, HABITAT_CMP_LE, 30, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;
    u32 fr;

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(givemon SPECIES_BULBASAUR, 10;);
    ASSUME(gPlayerPartyCount == 1);

    fr = 10;
    SetMonData(&gPlayerParty[0], MON_DATA_FRIENDSHIP, &fr);
    Habitat_EvaluateConditions(sHigh, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);
    Habitat_EvaluateConditions(sSpite, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);

    fr = 255;
    SetMonData(&gPlayerParty[0], MON_DATA_FRIENDSHIP, &fr);
    Habitat_EvaluateConditions(sHigh, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
    Habitat_EvaluateConditions(sSpite, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);
}
