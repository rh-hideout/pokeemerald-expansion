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

static void ResolveRandomMonTestValues(enum Species *species, enum Item *item, enum PokeBall *ball, enum Move *moves)
{
    ResolveRandomMonGeneration(species, item, ball, moves);
}

TEST("Random mon generation filters species from a small pool")
{
    enum Species species = TEST_SPECIES_GENERATOR_FILTERED_POOL;
    enum Item item = ITEM_NONE;
    enum PokeBall ball = BALL_POKE;
    enum Move moves[MAX_MON_MOVES] = {MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT};

    ResolveRandomMonTestValues(&species, &item, &ball, moves);

    EXPECT_EQ(species, SPECIES_CHARIZARD);
    EXPECT_EQ(item, ITEM_NONE);
    EXPECT_EQ(ball, BALL_POKE);
}

TEST("Random mon generation rejects disallowed mythical species")
{
    enum Species species = TEST_SPECIES_GENERATOR_MYTHICAL_FILTER;
    enum Item item = ITEM_NONE;
    enum PokeBall ball = BALL_POKE;
    enum Move moves[MAX_MON_MOVES] = {MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT};

    ResolveRandomMonTestValues(&species, &item, &ball, moves);

    EXPECT_EQ(species, SPECIES_CHARIZARD);
}

TEST("Random mon generation allows species within BST vars")
{
    enum Species species = TEST_SPECIES_GENERATOR_BST_FILTER;
    enum Item item = ITEM_NONE;
    enum PokeBall ball = BALL_POKE;
    enum Move moves[MAX_MON_MOVES] = {MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT};

    VarSet(VAR_0x8007, 400);
    VarSet(VAR_0x8008, 10);
    ResolveRandomMonTestValues(&species, &item, &ball, moves);
    VarSet(VAR_0x8007, 0);
    VarSet(VAR_0x8008, 0);

    EXPECT_EQ(species, SPECIES_WOBBUFFET);
}

TEST("Random mon generation rejects species outside BST vars")
{
    enum Species species = TEST_SPECIES_GENERATOR_BST_FILTER;
    enum Item item = ITEM_NONE;
    enum PokeBall ball = BALL_POKE;
    enum Move moves[MAX_MON_MOVES] = {MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT};

    VarSet(VAR_0x8007, 600);
    VarSet(VAR_0x8008, 10);
    ResolveRandomMonTestValues(&species, &item, &ball, moves);
    VarSet(VAR_0x8007, 0);
    VarSet(VAR_0x8008, 0);

    EXPECT_EQ(species, SPECIES_MEW);
}

TEST("Random mon generation applies filters to possible forms")
{
    enum Species species = TEST_SPECIES_GENERATOR_FORM_FILTER;
    enum Item item = ITEM_NONE;
    enum PokeBall ball = BALL_POKE;
    enum Move moves[MAX_MON_MOVES] = {MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT};

    ResolveRandomMonTestValues(&species, &item, &ball, moves);

    EXPECT_EQ(species, SPECIES_ROTOM_HEAT);
}

TEST("Random mon generation resolves held item from a pool")
{
    enum Species species = SPECIES_CHARIZARD;
    enum Item item = TEST_ITEM_GENERATOR_SINGLE_ITEM;
    enum PokeBall ball = BALL_POKE;
    enum Move moves[MAX_MON_MOVES] = {MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT};

    ResolveRandomMonTestValues(&species, &item, &ball, moves);

    EXPECT_EQ(item, ITEM_LEFTOVERS);
}

TEST("Random mon generation filters banned hold effects from a small pool")
{
    enum Species species = SPECIES_CHARIZARD;
    enum Item item = TEST_ITEM_GENERATOR_FILTERED_POOL;
    enum PokeBall ball = BALL_POKE;
    enum Move moves[MAX_MON_MOVES] = {MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT};

    ResolveRandomMonTestValues(&species, &item, &ball, moves);

    EXPECT_EQ(item, ITEM_LUM_BERRY);
}

TEST("Random mon generation allows ITEM_NONE in an explicit item pool")
{
    enum Species species = SPECIES_CHARIZARD;
    enum Item item = TEST_ITEM_GENERATOR_NONE_POOL;
    enum PokeBall ball = BALL_POKE;
    enum Move moves[MAX_MON_MOVES] = {MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT};

    ResolveRandomMonTestValues(&species, &item, &ball, moves);

    EXPECT_EQ(item, ITEM_NONE);
}

TEST("Random mon generation resolves random ball")
{
    enum Species species = SPECIES_CHARIZARD;
    enum Item item = ITEM_NONE;
    enum PokeBall ball = BALL_RANDOM;
    enum Move moves[MAX_MON_MOVES] = {MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT};

    SET_RNG(RNG_RANDOM_MON_GEN, BALL_MASTER);
    ResolveRandomMonTestValues(&species, &item, &ball, moves);

    EXPECT_EQ(ball, BALL_MASTER);
}

TEST("Random mon generation resolves teachable moves")
{
    enum Species species = SPECIES_CHARIZARD;
    enum Item item = ITEM_NONE;
    enum PokeBall ball = BALL_POKE;
    enum Move moves[MAX_MON_MOVES] = {MOVE_RANDOM_TEACHABLE, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT};

    ResolveRandomMonTestValues(&species, &item, &ball, moves);

    EXPECT_NE(moves[0], MOVE_RANDOM_TEACHABLE);
    EXPECT_NE(moves[0], MOVE_NONE);
}

TEST("createmon resolves random mon generation settings")
{
    ZeroPlayerPartyMons();

    RUN_OVERWORLD_SCRIPT(
        createmon 1, 0, TEST_SPECIES_GENERATOR_FILTERED_POOL, 50, item=TEST_ITEM_GENERATOR_SINGLE_ITEM, ball=BALL_MASTER, move1=MOVE_RANDOM_TEACHABLE, move2=MOVE_DEFAULT;
    );

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_SPECIES), SPECIES_CHARIZARD);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_LEVEL), 50);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_HELD_ITEM), ITEM_LEFTOVERS);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_POKEBALL), BALL_MASTER);
    EXPECT_NE(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_MOVE1), MOVE_RANDOM_TEACHABLE);
    EXPECT_NE(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_MOVE1), MOVE_NONE);
}
