#include "global.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/battle.h"
#include "config/habitat.h"
#include "event_data.h"
#include "habitat/bouts.h"
#include "habitat/finale.h"
#include "habitat/save.h"
#include "task.h"
#include "test/test.h"

static const struct HabitatBoutDefinition sTestBout = {
    .boutId = 1,
    .playerSpecies = SPECIES_TREECKO,
    .playerLevel = 12,
    .opponentSpecies = SPECIES_ZIGZAGOON,
    .opponentLevel = 9,
};

static void BuildDistinctParty(struct Pokemon *expected)
{
    static const u16 sSpecies[PARTY_SIZE] = {
        SPECIES_TREECKO, SPECIES_TORCHIC, SPECIES_MUDKIP,
        SPECIES_POOCHYENA, SPECIES_ZIGZAGOON, SPECIES_WURMPLE,
    };
    static const u16 sItems[PARTY_SIZE] = {
        ITEM_ORAN_BERRY, ITEM_CHERI_BERRY, ITEM_RAWST_BERRY,
        ITEM_ASPEAR_BERRY, ITEM_LEPPA_BERRY, ITEM_PECHA_BERRY,
    };
    static const u16 sMoves[PARTY_SIZE] = {
        MOVE_POUND, MOVE_SCRATCH, MOVE_TACKLE,
        MOVE_GROWL, MOVE_TAIL_WHIP, MOVE_STRING_SHOT,
    };
    static const u32 sStatuses[PARTY_SIZE] = {
        STATUS1_SLEEP, STATUS1_POISON, STATUS1_BURN,
        STATUS1_FREEZE, STATUS1_PARALYSIS, STATUS1_TOXIC_POISON,
    };
    static const u8 sNames[PARTY_SIZE][POKEMON_NAME_LENGTH + 1] = {
        "GROVE", "EMBER", "RIPPLE", "SHADE", "TRAIL", "SILK",
    };
    u32 i;

    ZeroPlayerPartyMons();
    for (i = 0; i < PARTY_SIZE; i++)
    {
        u8 friendship = 30 + i;
        u8 pp = 1 + i;
        u16 hp;
        u32 status = sStatuses[i];

        CreateMon(&gParties[B_TRAINER_PLAYER][i], sSpecies[i], 10 + i, i + 1, OTID_STRUCT_PLAYER_ID);
        SetMonMoveSlot(&gParties[B_TRAINER_PLAYER][i], sMoves[i], 0);
        SetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_HELD_ITEM, &sItems[i]);
        SetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_FRIENDSHIP, &friendship);
        SetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_STATUS, &status);
        SetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_NICKNAME, sNames[i]);
        hp = GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_MAX_HP) - i - 1;
        SetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_HP, &hp);
        SetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_PP1, &pp);
    }
    gPartiesCount[B_TRAINER_PLAYER] = PARTY_SIZE;
    memcpy(expected, gParties[B_TRAINER_PLAYER], sizeof(struct Pokemon) * PARTY_SIZE);
}

// Unit tests finish before the scheduler runs the battle-start task.
static void FinishTestBout(enum HabitatBoutOutcome outcome)
{
    Habitat_BoutFinish(outcome);
    ResetTasks();
}

TEST("Habitat bout: a win restores the exact six-member party")
{
    struct Pokemon expected[PARTY_SIZE];
    u16 item = ITEM_NONE;

    BuildDistinctParty(expected);
    EXPECT(Habitat_BoutBegin(&sTestBout));
    EXPECT(Habitat_BoutIsActive());

    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HELD_ITEM, &item);
    FinishTestBout(HABITAT_BOUT_WIN);

    EXPECT(!Habitat_BoutIsActive());
    EXPECT_EQ(Habitat_GetLastBoutOutcome(), HABITAT_BOUT_WIN);
    EXPECT_EQ(gPartiesCount[B_TRAINER_PLAYER], PARTY_SIZE);
    EXPECT(memcmp(expected, gParties[B_TRAINER_PLAYER], sizeof(expected)) == 0);
}

TEST("Habitat bout: a loss restores the exact six-member party")
{
    struct Pokemon expected[PARTY_SIZE];
    u16 item = ITEM_NONE;

    BuildDistinctParty(expected);
    ASSUME(Habitat_BoutBegin(&sTestBout));
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HELD_ITEM, &item);
    FinishTestBout(HABITAT_BOUT_LOSS);

    EXPECT_EQ(Habitat_GetLastBoutOutcome(), HABITAT_BOUT_LOSS);
    EXPECT(!Habitat_BoutIsActive());
    EXPECT(memcmp(expected, gParties[B_TRAINER_PLAYER], sizeof(expected)) == 0);
}

TEST("Habitat bout: a flee restores the exact six-member party")
{
    struct Pokemon expected[PARTY_SIZE];
    u16 item = ITEM_NONE;

    BuildDistinctParty(expected);
    ASSUME(Habitat_BoutBegin(&sTestBout));
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HELD_ITEM, &item);
    FinishTestBout(HABITAT_BOUT_FLED);

    EXPECT_EQ(Habitat_GetLastBoutOutcome(), HABITAT_BOUT_FLED);
    EXPECT(!Habitat_BoutIsActive());
    EXPECT(memcmp(expected, gParties[B_TRAINER_PLAYER], sizeof(expected)) == 0);
}

TEST("Habitat bout: setup failure restores the exact six-member party")
{
    struct Pokemon expected[PARTY_SIZE];
    struct HabitatBoutDefinition invalidBout = sTestBout;

    invalidBout.playerLevel = 0;
    BuildDistinctParty(expected);
    EXPECT(!Habitat_BoutBegin(&invalidBout));

    EXPECT_EQ(Habitat_GetLastBoutOutcome(), HABITAT_BOUT_ABORTED);
    EXPECT(!Habitat_BoutIsActive());
    EXPECT(memcmp(expected, gParties[B_TRAINER_PLAYER], sizeof(expected)) == 0);
}

TEST("Habitat bout: cancellation cleanup is idempotent and restores the party")
{
    struct Pokemon expected[PARTY_SIZE];
    u16 item = ITEM_NONE;

    BuildDistinctParty(expected);
    ASSUME(Habitat_BoutBegin(&sTestBout));
    SetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_HELD_ITEM, &item);
    FinishTestBout(HABITAT_BOUT_ABORTED);
    FinishTestBout(HABITAT_BOUT_LOSS);

    EXPECT_EQ(Habitat_GetLastBoutOutcome(), HABITAT_BOUT_ABORTED);
    EXPECT(!Habitat_BoutIsActive());
    EXPECT(memcmp(expected, gParties[B_TRAINER_PLAYER], sizeof(expected)) == 0);
}

TEST("Habitat bout: loss, flee, and abort leave finale state, spots, and residents unchanged")
{
    struct Pokemon expected[PARTY_SIZE];
    struct HabitatSave expectedHabitat;
    static const enum HabitatBoutOutcome sOutcomes[] = {
        HABITAT_BOUT_LOSS,
        HABITAT_BOUT_FLED,
        HABITAT_BOUT_ABORTED,
    };
    u32 i;

    memcpy(&expectedHabitat, &gSaveBlock3Ptr->habitat, sizeof(expectedHabitat));
    for (i = 0; i < ARRAY_COUNT(sOutcomes); i++)
    {
        FlagClear(FLAG_HABITAT_DEOXYS_FINALE_WON);
        BuildDistinctParty(expected);
        ASSUME(Habitat_BoutBegin(&sTestBout));
        FinishTestBout(sOutcomes[i]);

        EXPECT(!FlagGet(FLAG_HABITAT_DEOXYS_FINALE_WON));
        EXPECT(memcmp(&expectedHabitat, &gSaveBlock3Ptr->habitat, sizeof(expectedHabitat)) == 0);
        EXPECT(memcmp(expected, gParties[B_TRAINER_PLAYER], sizeof(expected)) == 0);
    }
    EXPECT_EQ(gHabitatDeoxysFinale.bout->winFlag, FLAG_HABITAT_DEOXYS_FINALE_WON);
}

TEST("Habitat bout: a forged Deoxys finale definition cannot award its completion flag")
{
    struct HabitatBoutDefinition forgedFinale = sTestBout;

    forgedFinale.boutId = HABITAT_BOUT_ID_DEOXYS_FINALE;
    forgedFinale.winFlag = FLAG_HABITAT_DEOXYS_FINALE_WON;
    FlagClear(FLAG_HABITAT_DEOXYS_FINALE_WON);

    ASSUME(Habitat_BoutBegin(&forgedFinale));
    FinishTestBout(HABITAT_BOUT_WIN);

    EXPECT(!FlagGet(FLAG_HABITAT_DEOXYS_FINALE_WON));
}

TEST("Habitat bout: finale authorization requires the canonical definition identity")
{
    struct HabitatBoutDefinition forgedFinale = *gHabitatDeoxysFinale.bout;

    EXPECT(Habitat_BoutIsApprovedFinaleDefinition(gHabitatDeoxysFinale.bout));
    EXPECT(!Habitat_BoutIsApprovedFinaleDefinition(&forgedFinale));
    EXPECT(!Habitat_BoutBegin(gHabitatDeoxysFinale.bout));
    EXPECT_EQ(Habitat_GetLastBoutOutcome(), HABITAT_BOUT_ABORTED);
}

TEST("Habitat bout: caller mutation after begin cannot alter finale authorization")
{
    struct HabitatBoutDefinition mutableBout = sTestBout;

    FlagClear(FLAG_HABITAT_DEOXYS_FINALE_WON);
    ASSUME(Habitat_BoutBegin(&mutableBout));
    mutableBout.boutId = HABITAT_BOUT_ID_DEOXYS_FINALE;
    mutableBout.winFlag = FLAG_HABITAT_DEOXYS_FINALE_WON;
    FinishTestBout(HABITAT_BOUT_WIN);

    EXPECT(!FlagGet(FLAG_HABITAT_DEOXYS_FINALE_WON));
}

TEST("Habitat bout: battle callback outcome mapping preserves field-return loss behavior")
{
    EXPECT_EQ(Habitat_BoutOutcomeFromBattleOutcome(B_OUTCOME_WON), HABITAT_BOUT_WIN);
    EXPECT_EQ(Habitat_BoutOutcomeFromBattleOutcome(B_OUTCOME_LOST), HABITAT_BOUT_LOSS);
    EXPECT(Habitat_BoutReturnsToField(HABITAT_BOUT_LOSS));
    EXPECT_EQ(Habitat_BoutOutcomeFromBattleOutcome(B_OUTCOME_DREW), HABITAT_BOUT_LOSS);
    EXPECT_EQ(Habitat_BoutOutcomeFromBattleOutcome(B_OUTCOME_FORFEITED), HABITAT_BOUT_LOSS);
    EXPECT_EQ(Habitat_BoutOutcomeFromBattleOutcome(B_OUTCOME_RAN), HABITAT_BOUT_FLED);
    EXPECT_EQ(Habitat_BoutOutcomeFromBattleOutcome(B_OUTCOME_PLAYER_TELEPORTED), HABITAT_BOUT_FLED);
    EXPECT_EQ(Habitat_BoutOutcomeFromBattleOutcome(B_OUTCOME_MON_FLED), HABITAT_BOUT_FLED);
    EXPECT_EQ(Habitat_BoutOutcomeFromBattleOutcome(B_OUTCOME_CAUGHT), HABITAT_BOUT_ABORTED);
}
