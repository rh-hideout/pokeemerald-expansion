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

static void ResolveRandomMonTestValues(enum Species *species, enum Item *item, enum PokeBall *ball, enum Move *moves)
{
    ResolveRandomMonGeneration(species, item, ball, moves);
}

TEST("Random mon generation resolves species from a pool")
{
    enum Species species = SPECIES_RANDOM_MON_OPTION_0;
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
    enum Species species = SPECIES_RANDOM_MON_OPTION_1;
    enum Item item = ITEM_NONE;
    enum PokeBall ball = BALL_POKE;
    enum Move moves[MAX_MON_MOVES] = {MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT};

    ResolveRandomMonTestValues(&species, &item, &ball, moves);

    EXPECT_EQ(species, SPECIES_BULBASAUR);
}

TEST("Random mon generation allows species within BST vars")
{
    enum Species species = SPECIES_RANDOM_MON_OPTION_2;
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
    enum Species species = SPECIES_RANDOM_MON_OPTION_2;
    enum Item item = ITEM_NONE;
    enum PokeBall ball = BALL_POKE;
    enum Move moves[MAX_MON_MOVES] = {MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT};

    VarSet(VAR_0x8007, 600);
    VarSet(VAR_0x8008, 10);
    ResolveRandomMonTestValues(&species, &item, &ball, moves);
    VarSet(VAR_0x8007, 0);
    VarSet(VAR_0x8008, 0);

    EXPECT_EQ(species, SPECIES_BULBASAUR);
}

TEST("Random mon generation resolves held item from a pool")
{
    enum Species species = SPECIES_CHARIZARD;
    enum Item item = ITEM_RANDOM_OPTION_0;
    enum PokeBall ball = BALL_POKE;
    enum Move moves[MAX_MON_MOVES] = {MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT, MOVE_DEFAULT};

    ResolveRandomMonTestValues(&species, &item, &ball, moves);

    EXPECT_EQ(item, ITEM_LEFTOVERS);
}

TEST("Random mon generation rejects banned hold effects")
{
    enum Species species = SPECIES_CHARIZARD;
    enum Item item = ITEM_RANDOM_OPTION_1;
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

TEST("Random mon generation resolves teachable moves without duplicates")
{
    enum Species species = SPECIES_CHARIZARD;
    enum Item item = ITEM_NONE;
    enum PokeBall ball = BALL_POKE;
    enum Move moves[MAX_MON_MOVES] = {MOVE_FLAMETHROWER, MOVE_RANDOM_TEACHABLE, MOVE_RANDOM_TEACHABLE, MOVE_DEFAULT};

    ResolveRandomMonTestValues(&species, &item, &ball, moves);

    EXPECT_EQ(moves[0], MOVE_FLAMETHROWER);
    EXPECT_NE(moves[1], MOVE_RANDOM_TEACHABLE);
    EXPECT_NE(moves[1], MOVE_FLAMETHROWER);
    EXPECT_NE(moves[1], MOVE_NONE);
    EXPECT_NE(moves[2], MOVE_RANDOM_TEACHABLE);
    EXPECT_NE(moves[2], MOVE_FLAMETHROWER);
    EXPECT_NE(moves[2], moves[1]);
    EXPECT_NE(moves[2], MOVE_NONE);
}

TEST("createmon resolves random mon generation settings")
{
    ZeroPlayerPartyMons();

    RUN_OVERWORLD_SCRIPT(
        createmon 1, 0, SPECIES_RANDOM_MON_OPTION_0, 50, item=ITEM_RANDOM_OPTION_0, ball=BALL_MASTER, move1=MOVE_SCRATCH, move2=MOVE_RANDOM_TEACHABLE;
    );

    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_SPECIES), SPECIES_CHARIZARD);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_LEVEL), 50);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_HELD_ITEM), ITEM_LEFTOVERS);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_POKEBALL), BALL_MASTER);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_MOVE1), MOVE_SCRATCH);
    EXPECT_NE(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_MOVE2), MOVE_RANDOM_TEACHABLE);
    EXPECT_NE(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_MOVE2), MOVE_SCRATCH);
    EXPECT_NE(GetMonData(&gParties[B_TRAINER_1][0], MON_DATA_MOVE2), MOVE_NONE);
}
