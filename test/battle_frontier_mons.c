#include "global.h"
#include "data.h"
#include "test/test.h"
#include "constants/battle_frontier_mons.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/pokeball.h"
#include "constants/species.h"

extern const struct TrainerMon gBattleFrontierMons[NUM_FRONTIER_MONS];

TEST("Battle Frontier mon constants preserve order and high-tier boundary")
{
    EXPECT_EQ(FRONTIER_MON_SUNKERN, 0);
    EXPECT_EQ(FRONTIER_MON_LATIOS_8, FRONTIER_MONS_HIGH_TIER);
    EXPECT_EQ(NUM_FRONTIER_MONS, FRONTIER_MON_SUICUNE_6 + 1);
    EXPECT_EQ(NUM_FRONTIER_MONS, 882);
}

TEST("Battle Frontier mons are generated from party data")
{
    const struct TrainerMon *sunkern = &gBattleFrontierMons[FRONTIER_MON_SUNKERN];
    const struct TrainerMon *suicune = &gBattleFrontierMons[FRONTIER_MON_SUICUNE_6];

    EXPECT_EQ(sunkern->species, SPECIES_SUNKERN);
    EXPECT_EQ(sunkern->heldItem, ITEM_LAX_INCENSE);
    EXPECT_EQ(sunkern->moves[0], MOVE_MEGA_DRAIN);
    EXPECT_EQ(sunkern->moves[1], MOVE_HELPING_HAND);
    EXPECT_EQ(sunkern->moves[2], MOVE_SUNNY_DAY);
    EXPECT_EQ(sunkern->moves[3], MOVE_LIGHT_SCREEN);
    EXPECT_EQ((u32)sunkern->nature, NATURE_RELAXED);
    EXPECT_EQ((u32)sunkern->ball, BALL_POKE);
    EXPECT_EQ(sunkern->ev[0], 252);
    EXPECT_EQ(sunkern->ev[3], 252);

    EXPECT_EQ(suicune->species, SPECIES_SUICUNE);
    EXPECT_EQ(suicune->heldItem, ITEM_CHESTO_BERRY);
    EXPECT_EQ(suicune->moves[0], MOVE_SURF);
    EXPECT_EQ(suicune->moves[1], MOVE_ICE_BEAM);
    EXPECT_EQ(suicune->moves[2], MOVE_CALM_MIND);
    EXPECT_EQ(suicune->moves[3], MOVE_REST);
    EXPECT_EQ((u32)suicune->nature, NATURE_MODEST);
    EXPECT_EQ((u32)suicune->ball, BALL_POKE);
    EXPECT_EQ(suicune->ev[0], 170);
    EXPECT_EQ(suicune->ev[2], 170);
    EXPECT_EQ(suicune->ev[4], 170);
}
