#include "global.h"
#include "test/test.h"
#include "battle.h"
#include "battle_main.h"
#include "data.h"
#include "malloc.h"
#include "random.h"
#include "string_util.h"
#include "trainer_pools.h"
#include "constants/item.h"
#include "constants/abilities.h"
#include "constants/trainers.h"
#include "constants/battle.h"

#define NUM_TEST_TRAINERS 9

static const struct Trainer sTestTrainers[DIFFICULTY_COUNT][NUM_TEST_TRAINERS] =
{
#include "trainer_control.h"
};

enum DifficultyLevel GetTrainerDifficultyLevelTest(u16 trainerId)
{
    enum DifficultyLevel difficulty = GetCurrentDifficultyLevel();

    if (difficulty == DIFFICULTY_NORMAL)
        return DIFFICULTY_NORMAL;

    if (sTestTrainers[difficulty][trainerId].party == NULL)
        return DIFFICULTY_NORMAL;

    return difficulty;
}

TEST("CreateNPCTrainerPartyForTrainer generates customized Pokémon")
{
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    u32 currTrainer = 0;
    u8 nickBuffer[20];
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainers[GetTrainerDifficultyLevelTest(currTrainer)][currTrainer], TRUE, BATTLE_TYPE_TRAINER);
    EXPECT(IsMonShiny(&testParty[0]));
    EXPECT(!IsMonShiny(&testParty[1]));
    EXPECT(!IsMonShiny(&testParty[3]));

    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_POKEBALL), BALL_MASTER);
    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_POKEBALL), BALL_POKE);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_POKEBALL), BALL_DUSK);

    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_SPECIES), SPECIES_WOBBUFFET);
    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_SPECIES), SPECIES_WOBBUFFET);
    EXPECT_EQ(GetMonData(&testParty[2], MON_DATA_SPECIES), SPECIES_WYNAUT);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_SPECIES), SPECIES_WOBBUFFET);

    EXPECT_EQ(GetMonAbility(&testParty[0]), ABILITY_TELEPATHY);
    EXPECT_EQ(GetMonAbility(&testParty[1]), ABILITY_SHADOW_TAG);
    EXPECT_EQ(GetMonAbility(&testParty[2]), ABILITY_SHADOW_TAG);
    EXPECT_EQ(GetMonAbility(&testParty[3]), ABILITY_TELEPATHY);

    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_FRIENDSHIP), 42);
    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_FRIENDSHIP), 0);
    EXPECT_EQ(GetMonData(&testParty[2], MON_DATA_FRIENDSHIP), 0);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_FRIENDSHIP), 0);

    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_HELD_ITEM), ITEM_ASSAULT_VEST);
    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_HELD_ITEM), ITEM_NONE);
    EXPECT_EQ(GetMonData(&testParty[2], MON_DATA_HELD_ITEM), ITEM_NONE);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_HELD_ITEM), ITEM_STICKY_BARB);

    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_HP_IV), 25);
    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_ATK_IV), 26);
    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_DEF_IV), 27);
    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_SPEED_IV), 28);
    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_SPATK_IV), 29);
    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_SPDEF_IV), 30);

    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_HP_IV), 0);
    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_ATK_IV), 0);
    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_DEF_IV), 0);
    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_SPEED_IV), 0);
    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_SPATK_IV), 0);
    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_SPDEF_IV), 0);

    EXPECT_EQ(GetMonData(&testParty[2], MON_DATA_HP_IV), 0);
    EXPECT_EQ(GetMonData(&testParty[2], MON_DATA_ATK_IV), 0);
    EXPECT_EQ(GetMonData(&testParty[2], MON_DATA_DEF_IV), 0);
    EXPECT_EQ(GetMonData(&testParty[2], MON_DATA_SPEED_IV), 0);
    EXPECT_EQ(GetMonData(&testParty[2], MON_DATA_SPATK_IV), 0);
    EXPECT_EQ(GetMonData(&testParty[2], MON_DATA_SPDEF_IV), 0);

    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_HP_IV), 25);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_ATK_IV), 26);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_DEF_IV), 27);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_SPEED_IV), 28);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_SPATK_IV), 29);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_SPDEF_IV), 30);

    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_HP_EV), 252);
    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_ATK_EV), 0);
    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_DEF_EV), 0);
    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_SPEED_EV), 252);
    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_SPATK_EV), 4);
    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_SPDEF_EV), 0);

    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_HP_EV), 0);
    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_ATK_EV), 0);
    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_DEF_EV), 0);
    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_SPEED_EV), 0);
    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_SPATK_EV), 0);
    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_SPDEF_EV), 0);

    EXPECT_EQ(GetMonData(&testParty[2], MON_DATA_HP_EV), 0);
    EXPECT_EQ(GetMonData(&testParty[2], MON_DATA_ATK_EV), 0);
    EXPECT_EQ(GetMonData(&testParty[2], MON_DATA_DEF_EV), 0);
    EXPECT_EQ(GetMonData(&testParty[2], MON_DATA_SPEED_EV), 0);
    EXPECT_EQ(GetMonData(&testParty[2], MON_DATA_SPATK_EV), 0);
    EXPECT_EQ(GetMonData(&testParty[2], MON_DATA_SPDEF_EV), 0);

    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_HP_EV), 252);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_ATK_EV), 0);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_DEF_EV), 0);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_SPEED_EV), 252);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_SPATK_EV), 4);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_SPDEF_EV), 0);

    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_LEVEL), 67);
    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_LEVEL), 5);
    EXPECT_EQ(GetMonData(&testParty[2], MON_DATA_LEVEL), 5);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_LEVEL), 69);

    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_MOVE1), MOVE_AIR_SLASH);
    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_MOVE2), MOVE_BARRIER);
    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_MOVE3), MOVE_SOLAR_BEAM);
    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_MOVE4), MOVE_EXPLOSION);

    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_MOVE1), MOVE_AIR_SLASH);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_MOVE2), MOVE_BARRIER);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_MOVE3), MOVE_SOLAR_BEAM);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_MOVE4), MOVE_EXPLOSION);

    GetMonData(&testParty[0], MON_DATA_NICKNAME, nickBuffer);
    EXPECT_EQ(StringCompare(nickBuffer, COMPOUND_STRING("Bubbles")), 0);

    GetMonData(&testParty[1], MON_DATA_NICKNAME, nickBuffer);
    EXPECT_EQ(StringCompare(nickBuffer, COMPOUND_STRING("Wobbuffet")), 0);

    EXPECT_EQ(GetMonGender(&testParty[0]), MON_FEMALE);
    EXPECT_EQ(GetNature(&testParty[0]), NATURE_HASTY);
    EXPECT_EQ(GetNature(&testParty[3]), NATURE_HASTY);

    EXPECT_EQ(GetMonData(&testParty[0], MON_DATA_DYNAMAX_LEVEL), 5);
    EXPECT_EQ(GetMonData(&testParty[1], MON_DATA_DYNAMAX_LEVEL), 10);
    EXPECT_EQ(GetMonData(&testParty[2], MON_DATA_DYNAMAX_LEVEL), 10);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_DYNAMAX_LEVEL), 10);

    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_IS_SHADOW), TRUE);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_HEART_VALUE), 3000);
    EXPECT_EQ(GetMonData(&testParty[3], MON_DATA_HEART_MAX), 3000);

    Free(testParty);
}

TEST("CreateNPCTrainerPartyForTrainer generates different personalities for different mons")
{
    enum DifficultyLevel difficulty = GetTrainerDifficultyLevelTest(0);
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainers[difficulty][0], TRUE, BATTLE_TYPE_TRAINER);
    EXPECT(testParty[0].box.personality != testParty[1].box.personality);
    Free(testParty);
}

TEST("ModifyPersonalityForNature can set any nature")
{
    u32 personality = 0, nature = 0, j = 0, k = 0;
    for (j = 0; j < 64; j++)
    {
        for (k = 0; k < NUM_NATURES; k++)
        {
            PARAMETRIZE { personality = Random32(); nature = k; }
        }
    }
    ModifyPersonalityForNature(&personality, nature);
    EXPECT_EQ(GetNatureFromPersonality(personality), nature);
}

static const struct TrainerMon sTestParty2[] =
{
    {
        .species = SPECIES_WYNAUT,
        .lvl = 5,
    },
    {
        .species = SPECIES_WYNAUT,
        .lvl = 5,
    },
    {
        .species = SPECIES_WYNAUT,
        .lvl = 5,
    },
    {
        .species = SPECIES_WYNAUT,
        .lvl = 5,
    },
    {
        .species = SPECIES_WYNAUT,
        .lvl = 5,
    },
    {
        .species = SPECIES_WYNAUT,
        .lvl = 5,
    },
};

static const struct Trainer sTestTrainer2 =
{
    .trainerName = _("Test2"),
    .trainerClass = TRAINER_CLASS_BLACK_BELT,
    .party = TRAINER_PARTY(sTestParty2),
};

TEST("Trainer Class Balls apply to the entire party")
{
    u32 j;
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainer2, TRUE, BATTLE_TYPE_TRAINER);
    for(j = 0; j < 6; j++)
    {
        EXPECT(GetMonData(&testParty[j], MON_DATA_POKEBALL, 0) == gTrainerClasses[sTestTrainer2.trainerClass].ball);
    }
    Free(testParty);
}

TEST("Difficulty default to Normal is the trainer doesn't have a member for the current diffuculty")
{
    SetCurrentDifficultyLevel(DIFFICULTY_EASY);
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    u32 currTrainer = 1;
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainers[GetTrainerDifficultyLevelTest(currTrainer)][currTrainer], TRUE, BATTLE_TYPE_TRAINER);
    EXPECT(GetMonData(&testParty[0], MON_DATA_SPECIES) == SPECIES_MEWTWO);
    Free(testParty);
}

TEST("Difficulty changes which party if used for NPCs if defined for the difficulty (EASY)")
{
    SetCurrentDifficultyLevel(DIFFICULTY_EASY);
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    u32 currTrainer = 2;
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainers[GetTrainerDifficultyLevelTest(currTrainer)][currTrainer], TRUE, BATTLE_TYPE_TRAINER);
    EXPECT(GetMonData(&testParty[0], MON_DATA_SPECIES) == SPECIES_METAPOD);
    EXPECT(GetMonData(&testParty[0], MON_DATA_LEVEL) == 1);
    Free(testParty);
}

TEST("Difficulty changes which party if used for NPCs if defined for the difficulty (HARD)")
{
    SetCurrentDifficultyLevel(DIFFICULTY_HARD);
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    u32 currTrainer = 2;
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainers[GetTrainerDifficultyLevelTest(currTrainer)][currTrainer], TRUE, BATTLE_TYPE_TRAINER);
    EXPECT(GetMonData(&testParty[0], MON_DATA_SPECIES) == SPECIES_ARCEUS);
    EXPECT(GetMonData(&testParty[0], MON_DATA_LEVEL) == 99);
    Free(testParty);
}

TEST("Difficulty changes which party if used for NPCs if defined for the difficulty (NORMAL)")
{
    SetCurrentDifficultyLevel(DIFFICULTY_NORMAL);
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    u32 currTrainer = 2;
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainers[GetTrainerDifficultyLevelTest(currTrainer)][currTrainer], TRUE, BATTLE_TYPE_TRAINER);
    EXPECT(GetMonData(&testParty[0], MON_DATA_SPECIES) == SPECIES_MEWTWO);
    EXPECT(GetMonData(&testParty[0], MON_DATA_LEVEL) == 50);
    Free(testParty);
}

TEST("Trainer Party Pool generates a party from the trainer pool")
{
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    u32 currTrainer = 3;
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainers[GetTrainerDifficultyLevelTest(currTrainer)][currTrainer], TRUE, BATTLE_TYPE_TRAINER);
    EXPECT(GetMonData(&testParty[0], MON_DATA_SPECIES) == SPECIES_EEVEE);
    Free(testParty);
}

TEST("Trainer Party Pool picks a random lead and a random ace if tags exist in the pool")
{
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    u32 currTrainer = 4;
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainers[GetTrainerDifficultyLevelTest(currTrainer)][currTrainer], TRUE, BATTLE_TYPE_TRAINER);
    EXPECT(GetMonData(&testParty[0], MON_DATA_SPECIES) == SPECIES_ARON);    //  Lead
    EXPECT(GetMonData(&testParty[1], MON_DATA_SPECIES) == SPECIES_WYNAUT);  //  Not Lead or Ace
    EXPECT(GetMonData(&testParty[2], MON_DATA_SPECIES) == SPECIES_EEVEE);   //  Ace
    Free(testParty);
}

TEST("Trainer Party Pool picks according to custom rules")
{
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    u32 currTrainer = 5;
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainers[GetTrainerDifficultyLevelTest(currTrainer)][currTrainer], TRUE, BATTLE_TYPE_TRAINER | BATTLE_TYPE_DOUBLE);
    EXPECT(GetMonData(&testParty[0], MON_DATA_SPECIES) == SPECIES_TORKOAL);    //  Lead + Weather Setter
    EXPECT(GetMonData(&testParty[1], MON_DATA_SPECIES) == SPECIES_BULBASAUR);  //  Lead + Weather Abuser
    EXPECT(GetMonData(&testParty[2], MON_DATA_SPECIES) == SPECIES_EEVEE);      //  Anything else
    Free(testParty);
}

TEST("Trainer Party Pool uses standard party creation if pool is illegal")
{
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    u32 currTrainer = 6;
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainers[GetTrainerDifficultyLevelTest(currTrainer)][currTrainer], TRUE, BATTLE_TYPE_TRAINER);
    EXPECT(GetMonData(&testParty[0], MON_DATA_SPECIES) == SPECIES_WYNAUT);
    EXPECT(GetMonData(&testParty[1], MON_DATA_SPECIES) == SPECIES_WOBBUFFET);
    Free(testParty);
}

TEST("Trainer Party Pool can be pruned before picking")
{
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    u32 currTrainer = 7;
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainers[GetTrainerDifficultyLevelTest(currTrainer)][currTrainer], TRUE, BATTLE_TYPE_TRAINER);
    EXPECT(GetMonData(&testParty[0], MON_DATA_SPECIES) == SPECIES_EEVEE);
    EXPECT(GetMonData(&testParty[1], MON_DATA_SPECIES) == SPECIES_WYNAUT);
    Free(testParty);
}

TEST("Trainer Party Pool can choose which functions to use for picking mons")
{
    struct Pokemon *testParty = Alloc(6 * sizeof(struct Pokemon));
    u32 currTrainer = 8;
    CreateNPCTrainerPartyFromTrainer(testParty, &sTestTrainers[GetTrainerDifficultyLevelTest(currTrainer)][currTrainer], TRUE, BATTLE_TYPE_TRAINER);
    EXPECT(GetMonData(&testParty[0], MON_DATA_SPECIES) == SPECIES_WYNAUT);
    EXPECT(GetMonData(&testParty[1], MON_DATA_SPECIES) == SPECIES_WOBBUFFET);
    Free(testParty);
}
