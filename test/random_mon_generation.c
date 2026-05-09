#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "pokemon.h"
#include "random_mon_generation.h"
#include "test/overworld_script.h"
#include "test/test.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokeball.h"
#include "constants/species.h"
#include "constants/vars.h"

#define TEST_SPECIES_GENERATOR_FILTERED_POOL (SPECIES_RANDOMLY_GENERATED_START + 0)
#define TEST_SPECIES_GENERATOR_MYTHICAL_FILTER (SPECIES_RANDOMLY_GENERATED_START + 1)
#define TEST_SPECIES_GENERATOR_BST_FILTER (SPECIES_RANDOMLY_GENERATED_START + 2)
#define TEST_SPECIES_GENERATOR_FORM_FILTER (SPECIES_RANDOMLY_GENERATED_START + 3)

#define TEST_ITEM_GENERATOR_SINGLE_ITEM (ITEM_RANDOMLY_GENERATED_START + 0)
#define TEST_ITEM_GENERATOR_FILTERED_POOL (ITEM_RANDOMLY_GENERATED_START + 1)
#define TEST_ITEM_GENERATOR_NONE_POOL (ITEM_RANDOMLY_GENERATED_START + 2)

static void ResolveRandomMonTestValues(enum Species species, enum PokeBall *ball, enum Move *moves)
{
    ResolveRandomMonGeneration(species, ball, moves);
}

TEST("Random mon generation filters species from a small pool")
{
    enum Species species = GetRandomSpecies(TEST_SPECIES_GENERATOR_FILTERED_POOL, 0xFFFF, 0xFFFF);

    EXPECT_EQ(species, SPECIES_CHARIZARD);
}

TEST("Random mon generation rejects disallowed mythical species")
{
    enum Species species = GetRandomSpecies(TEST_SPECIES_GENERATOR_MYTHICAL_FILTER, 0xFFFF, 0xFFFF);

    EXPECT_EQ(species, SPECIES_CHARIZARD);
}

TEST("Random mon generation allows species within BST vars")
{
    enum Species species = GetRandomSpecies(TEST_SPECIES_GENERATOR_BST_FILTER, 400, 10);

    EXPECT_EQ(species, SPECIES_WOBBUFFET);
}

TEST("Random mon generation rejects species outside BST vars")
{
    enum Species species = GetRandomSpecies(TEST_SPECIES_GENERATOR_BST_FILTER, 600, 10);

    EXPECT_EQ(species, SPECIES_MEW);
}

TEST("Random mon generation applies filters to possible forms")
{
    enum Species species = GetRandomSpecies(TEST_SPECIES_GENERATOR_FORM_FILTER, 0xFFFF, 0xFFFF);

    EXPECT_EQ(species, SPECIES_ROTOM_HEAT);
}

TEST("Random mon generation resolves held item from a pool")
{
    enum Item item = GetRandomItem(TEST_ITEM_GENERATOR_SINGLE_ITEM);

    EXPECT_EQ(item, ITEM_LEFTOVERS);
}

TEST("Random mon generation filters banned hold effects from a small pool")
{
    enum Item item = GetRandomItem(TEST_ITEM_GENERATOR_FILTERED_POOL);

    EXPECT_EQ(item, ITEM_LUM_BERRY);
}

TEST("Random mon generation allows ITEM_NONE in an explicit item pool")
{
    enum Item item = GetRandomItem(TEST_ITEM_GENERATOR_NONE_POOL);

    EXPECT_EQ(item, ITEM_NONE);
}

TEST("Random mon generation resolves random ball")
{
    enum Species species = SPECIES_CHARIZARD;
    enum PokeBall ball = BALL_RANDOM;
    enum Move moves[MAX_MON_MOVES] = {MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT};

    SET_RNG(RNG_RANDOM_MON_GEN, BALL_MASTER);
    ResolveRandomMonTestValues(species, &ball, moves);

    EXPECT_EQ(ball, BALL_MASTER);
}

TEST("Random mon generation resolves teachable moves")
{
    enum Species species = SPECIES_CHARIZARD;
    enum PokeBall ball = BALL_POKE;
    enum Move moves[MAX_MON_MOVES] = {MOVE_RANDOM_TEACHABLE, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT};

    ResolveRandomMonTestValues(species, &ball, moves);

    EXPECT_NE(moves[0], MOVE_RANDOM_TEACHABLE);
    EXPECT_NE(moves[0], MOVE_NONE);
}

TEST("Random mon generation commands set vars for createmon")
{
    ZeroPlayerPartyMons();

    RUN_OVERWORLD_SCRIPT(
        getrandomspecies VAR_0x8000, TEST_SPECIES_GENERATOR_FILTERED_POOL;
        getrandomitem VAR_0x8001, TEST_ITEM_GENERATOR_SINGLE_ITEM;
        createmon 1, 0, VAR_0x8000, 50, item=VAR_0x8001, ball=BALL_MASTER, move1=MOVE_RANDOM_TEACHABLE, move2=MOVE_DEFAULT;
    );

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_SPECIES), SPECIES_CHARIZARD);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_LEVEL), 50);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_HELD_ITEM), ITEM_LEFTOVERS);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_POKEBALL), BALL_MASTER);
    EXPECT_NE(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_MOVE1), MOVE_RANDOM_TEACHABLE);
    EXPECT_NE(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_MOVE1), MOVE_NONE);
}

TEST("Random mon generation command forwards filter args")
{
    RUN_OVERWORLD_SCRIPT(
        getrandomspecies VAR_0x8000, TEST_SPECIES_GENERATOR_BST_FILTER, arg1=400, arg2=10;
    );

    EXPECT_EQ(VarGet(VAR_0x8000), SPECIES_WOBBUFFET);
}
