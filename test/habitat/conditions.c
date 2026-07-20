#include "global.h"
#include "event_data.h"
#include "field_weather.h"
#include "habitat/conditions.h"
#include "habitat/save.h"
#include "habitat/spots.h"
#include "item.h"
#include "overworld.h"
#include "pokedex.h"
#include "rtc.h"
#include "constants/berry.h"
#include "constants/game_stat.h"
#include "constants/weather.h"
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

// ---- World conditions (Task 4) ----

TEST("Habitat conditions: TIME_OF_DAY hour windows with midnight wrap")
{
    static const struct HabitatCondition sNight[] = {  // 20:00–03:59, wraps
        HABITAT_COND(COND_TIME_OF_DAY, 20, 4, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sDay[] = {    // 08:00–16:59
        HABITAT_COND(COND_TIME_OF_DAY, 8, 17, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sEndsAt22[] = { // end-exclusive check
        HABITAT_COND(COND_TIME_OF_DAY, 20, 22, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    RtcInitLocalTimeOffset(22, 0);
    RtcCalcLocalTime();
    ASSUME(gLocalTime.hours == 22);

    Habitat_EvaluateConditions(sNight, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
    Habitat_EvaluateConditions(sDay, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);
    Habitat_EvaluateConditions(sEndsAt22, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);

    RtcInitLocalTimeOffset(2, 30);
    RtcCalcLocalTime();
    ASSUME(gLocalTime.hours == 2);
    Habitat_EvaluateConditions(sNight, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
}

TEST("Habitat conditions: WEATHER matches current weather")
{
    static const struct HabitatCondition sRain[] = {
        HABITAT_COND(COND_WEATHER, WEATHER_RAIN, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sNotSunny[] = {  // spite: must NOT be sunny
        HABITAT_COND(COND_WEATHER, WEATHER_SUNNY, 0, 0, HABITAT_COND_NEGATE),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    SetCurrentAndNextWeather(WEATHER_RAIN);  // same setter worker-generated weather uses
    ASSUME(GetCurrentWeather() == WEATHER_RAIN);
    Habitat_EvaluateConditions(sRain, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
    Habitat_EvaluateConditions(sNotSunny, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);

    SetCurrentAndNextWeather(WEATHER_SUNNY);
    ASSUME(GetCurrentWeather() == WEATHER_SUNNY);
    Habitat_EvaluateConditions(sRain, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);
    Habitat_EvaluateConditions(sNotSunny, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);
}

TEST("Habitat conditions: DEX_COUNT compares caught count")
{
    static const struct HabitatCondition sTwo[] = {
        HABITAT_COND(COND_DEX_COUNT, HABITAT_CMP_GE, 2, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sThree[] = {
        HABITAT_COND(COND_DEX_COUNT, HABITAT_CMP_GE, 3, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(givemon SPECIES_BULBASAUR, 10; givemon SPECIES_ZIGZAGOON, 10;);
    ASSUME(GetNationalPokedexCount(FLAG_GET_CAUGHT) == 2);

    Habitat_EvaluateConditions(sTwo, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
    Habitat_EvaluateConditions(sThree, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);
}

TEST("Habitat conditions: LIFETIME_STAT compares game stats")
{
    static const struct HabitatCondition sHundred[] = {
        HABITAT_COND(COND_LIFETIME_STAT, GAME_STAT_STEPS, HABITAT_CMP_GE, 100, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    SetGameStat(GAME_STAT_STEPS, 99);
    Habitat_EvaluateConditions(sHundred, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);

    SetGameStat(GAME_STAT_STEPS, 100);
    Habitat_EvaluateConditions(sHundred, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
}

TEST("Habitat conditions: BERRY_MATURE finds a mature tree anywhere")
{
    static const struct HabitatCondition sOran[] = {
        HABITAT_COND(COND_BERRY_MATURE, ITEM_ORAN_BERRY, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sPecha[] = {
        HABITAT_COND(COND_BERRY_MATURE, ITEM_PECHA_BERRY, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    memset(gSaveBlock1Ptr->berryTrees, 0, sizeof(gSaveBlock1Ptr->berryTrees));
    Habitat_EvaluateConditions(sOran, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);

    gSaveBlock1Ptr->berryTrees[2].berry = ItemIdToBerryType(ITEM_ORAN_BERRY);
    gSaveBlock1Ptr->berryTrees[2].stage = BERRY_STAGE_PLANTED;
    Habitat_EvaluateConditions(sOran, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);  // planted is not mature

    gSaveBlock1Ptr->berryTrees[2].stage = BERRY_STAGE_BERRIES;
    Habitat_EvaluateConditions(sOran, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
    Habitat_EvaluateConditions(sPecha, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);  // wrong berry
}

// ---- Offer context (Task 5) ----

TEST("Habitat conditions: ITEM_OFFERED matches the offer context")
{
    static const struct HabitatCondition sSpicy[] = {
        HABITAT_COND(COND_ITEM_OFFERED, ITEM_ORAN_BERRY, 1, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    static const struct HabitatCondition sThreeOran[] = {
        HABITAT_COND(COND_ITEM_OFFERED, ITEM_ORAN_BERRY, 3, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;
    struct HabitatOfferContext offer;

    Habitat_EvaluateConditions(sSpicy, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);  // no offer in progress

    offer.itemId = ITEM_PECHA_BERRY;
    offer.count = 1;
    Habitat_EvaluateConditions(sSpicy, HABITAT_SPOT_NONE, &offer, &r);
    EXPECT(!r.allMet);  // wrong item

    offer.itemId = ITEM_ORAN_BERRY;
    offer.count = 1;
    Habitat_EvaluateConditions(sSpicy, HABITAT_SPOT_NONE, &offer, &r);
    EXPECT(r.allMet);
    Habitat_EvaluateConditions(sThreeOran, HABITAT_SPOT_NONE, &offer, &r);
    EXPECT(!r.allMet);  // not enough

    offer.count = 3;
    Habitat_EvaluateConditions(sThreeOran, HABITAT_SPOT_NONE, &offer, &r);
    EXPECT(r.allMet);
}

// ---- Spot-local conditions (phase 2) ----

TEST("Habitat conditions: SPOT_STATE reads another spot's saved state")
{
    static const struct HabitatCondition sChain[] = {
        HABITAT_COND(COND_SPOT_STATE, 2, HABITAT_STATE_BEFRIENDED, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    Habitat_EvaluateConditions(sChain, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);

    Habitat_SetSpotState(2, HABITAT_STATE_BEFRIENDED);
    Habitat_EvaluateConditions(sChain, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
}

TEST("Habitat conditions: ITEM_PLACED reads the evaluated spot")
{
    static const struct HabitatCondition sDoll[] = {
        HABITAT_COND(COND_ITEM_PLACED, ITEM_POKE_DOLL, 1, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    Habitat_EvaluateConditions(sDoll, 1, NULL, &r);   // spot 1 = Skitty, has a slot
    EXPECT(!r.allMet);
    Habitat_AddPlacedCount(1, 0, 1);
    Habitat_EvaluateConditions(sDoll, 1, NULL, &r);
    EXPECT(r.allMet);
    Habitat_EvaluateConditions(sDoll, HABITAT_SPOT_NONE, NULL, &r);  // no spot context
    EXPECT(!r.allMet);
}

TEST("Habitat conditions: ZONE_COMPLETE requires every zone spot befriended")
{
    static const struct HabitatCondition sZone[] = {
        HABITAT_COND(COND_ZONE_COMPLETE, 1, 0, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;
    u32 i;

    Habitat_EvaluateConditions(sZone, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);

    for (i = 0; gHabitatSpots[i].spotId != 0xFFFF; i++)
        if (gHabitatSpots[i].zoneId == 1)
            Habitat_SetSpotState(gHabitatSpots[i].spotId, HABITAT_STATE_BEFRIENDED);
    Habitat_EvaluateConditions(sZone, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
}

TEST("Habitat conditions: BERRY_MATURE zone filter uses the zone's tree range")
{
    static const struct HabitatCondition sZone1Cheri[] = {
        HABITAT_COND(COND_BERRY_MATURE, ITEM_CHERI_BERRY, 1, 0, 0),
        HABITAT_CONDITIONS_END,
    };
    struct HabitatConditionResult r;

    memset(gSaveBlock1Ptr->berryTrees, 0, sizeof(gSaveBlock1Ptr->berryTrees));
    // Mature Cheri OUTSIDE zone 1's range (trees 5–7): tree 20.
    gSaveBlock1Ptr->berryTrees[20].berry = ItemIdToBerryType(ITEM_CHERI_BERRY);
    gSaveBlock1Ptr->berryTrees[20].stage = BERRY_STAGE_BERRIES;
    Habitat_EvaluateConditions(sZone1Cheri, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(!r.allMet);

    // Mature Cheri INSIDE the range: tree 5 (BERRY_TREE_ROUTE_103_CHERI_1).
    gSaveBlock1Ptr->berryTrees[5].berry = ItemIdToBerryType(ITEM_CHERI_BERRY);
    gSaveBlock1Ptr->berryTrees[5].stage = BERRY_STAGE_BERRIES;
    Habitat_EvaluateConditions(sZone1Cheri, HABITAT_SPOT_NONE, NULL, &r);
    EXPECT(r.allMet);
}
