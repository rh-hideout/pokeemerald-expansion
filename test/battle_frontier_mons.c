#include "global.h"
#include "battle_frontier.h"
#include "battle_factory.h"
#include "data.h"
#include "frontier_util.h"
#include "string_util.h"
#include "test/test.h"
#include "trainer_pools.h"
#include "constants/battle_frontier.h"
#include "battle/frontier_mons_constants.h"
#include "battle/frontier_pool_sets_constants.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/pokeball.h"
#include "constants/species.h"
#include "constants/trainers.h"

extern const struct TrainerMon gTestBattleFrontierMons[NUM_FRONTIER_MONS];
extern const struct TrainerPoolSet gTestBattleFrontierPoolSets[NUM_FRONTIER_POOL_SETS];

TEST("trainerproc generates Battle Frontier mon constants from party data")
{
    EXPECT_EQ(FRONTIER_MON_TEST_PIKACHU, 0);
    EXPECT_EQ(FRONTIER_MONS_HIGH_TIER, FRONTIER_MON_TEST_ABRA);
    EXPECT_EQ(NUM_FRONTIER_MONS, FRONTIER_MON_TEST_BULBASAUR + 1);
}

TEST("trainerproc generates Battle Frontier mons from party data")
{
    const struct TrainerMon *pikachu = &gTestBattleFrontierMons[FRONTIER_MON_TEST_PIKACHU];
    const struct TrainerMon *abra = &gTestBattleFrontierMons[FRONTIER_MON_TEST_ABRA];
    const struct TrainerMon *machop = &gTestBattleFrontierMons[FRONTIER_MON_TEST_MACHOP];
    const struct TrainerMon *pikachu2 = &gTestBattleFrontierMons[FRONTIER_MON_TEST_PIKACHU_2];
    const struct TrainerMon *bulbasaur = &gTestBattleFrontierMons[FRONTIER_MON_TEST_BULBASAUR];

    EXPECT(StringCompare(pikachu->nickname, COMPOUND_STRING("Sparky")) == 0);
    EXPECT_EQ(pikachu->species, SPECIES_PIKACHU);
    EXPECT_EQ((u32)pikachu->gender, TRAINER_MON_MALE);
    EXPECT_EQ(pikachu->heldItem, ITEM_LIGHT_BALL);
    EXPECT_EQ(pikachu->iv, TRAINER_PARTY_IVS(31, 30, 29, 26, 28, 27));
    EXPECT_EQ(pikachu->ability, ABILITY_STATIC);
    EXPECT_EQ(pikachu->lvl, 50);
    EXPECT_EQ((u32)pikachu->ball, BALL_LUXURY);
    EXPECT_EQ(pikachu->friendship, 200);
    EXPECT_EQ((u32)pikachu->nature, NATURE_TIMID);
    EXPECT_EQ((u32)pikachu->isShiny, TRUE);
    EXPECT_EQ((u32)pikachu->dynamaxLevel, 7);
    EXPECT_EQ((u32)pikachu->gigantamaxFactor, TRUE);
    EXPECT_EQ((u32)pikachu->shouldUseDynamax, TRUE);
    EXPECT_EQ((u32)pikachu->teraType, TYPE_FIRE);
    EXPECT_EQ(pikachu->tags, MON_POOL_TAG_LEAD | MON_POOL_TAG_ACE);
    EXPECT_EQ(pikachu->moves[0], MOVE_THUNDERBOLT);
    EXPECT_EQ(pikachu->moves[1], MOVE_SURF);
    EXPECT_EQ(pikachu->moves[2], MOVE_PROTECT);
    EXPECT_EQ(pikachu->moves[3], MOVE_VOLT_SWITCH);
    EXPECT(pikachu->ev != NULL);
    EXPECT_EQ(pikachu->ev[0], 252);
    EXPECT_EQ(pikachu->ev[1], 4);
    EXPECT_EQ(pikachu->ev[2], 12);
    EXPECT_EQ(pikachu->ev[3], 36);
    EXPECT_EQ(pikachu->ev[4], 44);
    EXPECT_EQ(pikachu->ev[5], 60);

    EXPECT_EQ(abra->species, SPECIES_ABRA);
    EXPECT_EQ((u32)abra->gender, 0);
    EXPECT_EQ(abra->heldItem, ITEM_TWISTED_SPOON);
    EXPECT_EQ(abra->iv, 0);
    EXPECT_EQ(abra->ability, ABILITY_NONE);
    EXPECT_EQ(abra->lvl, 0);
    EXPECT_EQ((u32)abra->ball, POKEBALL_COUNT);
    EXPECT_EQ((u32)abra->nature, NATURE_MODEST);
    EXPECT_EQ((u32)abra->isShiny, FALSE);
    EXPECT_EQ((u32)abra->dynamaxLevel, 0);
    EXPECT_EQ((u32)abra->gigantamaxFactor, FALSE);
    EXPECT_EQ((u32)abra->shouldUseDynamax, FALSE);
    EXPECT_EQ((u32)abra->teraType, TYPE_NONE);
    EXPECT_EQ(abra->tags, 0);
    EXPECT_EQ(abra->moves[0], MOVE_PSYCHIC);
    EXPECT_EQ(abra->moves[1], MOVE_NONE);
    EXPECT(abra->ev != NULL);
    EXPECT_EQ(abra->ev[0], 0);
    EXPECT_EQ(abra->ev[1], 0);
    EXPECT_EQ(abra->ev[2], 0);
    EXPECT_EQ(abra->ev[3], 252);
    EXPECT_EQ(abra->ev[4], 4);
    EXPECT_EQ(abra->ev[5], 252);

    EXPECT_EQ(machop->species, SPECIES_MACHOP);
    EXPECT_EQ(machop->tags, MON_POOL_TAG_HIGH_TIER);

    EXPECT_EQ(pikachu2->species, SPECIES_PIKACHU);
    EXPECT_EQ(pikachu2->heldItem, ITEM_ORAN_BERRY);
    EXPECT_EQ(bulbasaur->species, SPECIES_BULBASAUR);
    EXPECT_EQ(bulbasaur->heldItem, ITEM_LIGHT_BALL);
}

TEST("frontier mon pools filter high tier mons by tag")
{
    const u16 lvl50MonSet[] = {FRONTIER_MON_TEST_PIKACHU, FRONTIER_MON_TEST_MACHOP, 0xFFFF};
    const u16 openLevelMonSet[] = {FRONTIER_MON_TEST_MACHOP, 0xFFFF};
    struct FrontierMonPool lvl50Pool = GetTrainerMonPoolFromSet(lvl50MonSet);
    u16 selectedMonId = 0xFFFF;

    gFacilityTrainerMons = gTestBattleFrontierMons;
    ASSUME(lvl50Pool.monIds == lvl50MonSet);
    ASSUME(lvl50Pool.size == 2);
    EXPECT_EQ(GetTrainerMonPoolAt(&lvl50Pool, 0), FRONTIER_MON_TEST_PIKACHU);
    EXPECT_EQ(GetTrainerMonPoolAt(&lvl50Pool, 1), FRONTIER_MON_TEST_MACHOP);
    ASSUME(!IsFrontierMonHighTier(FRONTIER_MON_TEST_PIKACHU));
    ASSUME(IsFrontierMonHighTier(FRONTIER_MON_TEST_MACHOP));

    SelectFrontierMonsFromSet(lvl50MonSet, FRONTIER_MAX_LEVEL_50, 1, &selectedMonId, 0);
    EXPECT_EQ(selectedMonId, FRONTIER_MON_TEST_PIKACHU);

    SelectFrontierMonsFromSet(openLevelMonSet, FRONTIER_MAX_LEVEL_OPEN, 1, &selectedMonId, 0);
    EXPECT_EQ(selectedMonId, FRONTIER_MON_TEST_MACHOP);
}

TEST("trainerproc generates Battle Frontier pool sets from pool set data")
{
    const struct TrainerPoolSet *lvl50Pool = &gTestBattleFrontierPoolSets[FRONTIER_POOL_TEST_LEVEL_50];
    const struct TrainerPoolSet *openLevelPool = &gTestBattleFrontierPoolSets[FRONTIER_POOL_TEST_OPEN_LEVEL];

    EXPECT_EQ((u32)FRONTIER_POOL_TEST_LEVEL_50, 0);
    EXPECT_EQ((u32)NUM_FRONTIER_POOL_SETS, 2);

    EXPECT_EQ(lvl50Pool->poolSize, 2);
    EXPECT_EQ((u32)lvl50Pool->poolRuleIndex, POOL_RULESET_FRONTIER);
    EXPECT_EQ(lvl50Pool->monIds[0], FRONTIER_MON_TEST_PIKACHU);
    EXPECT_EQ(lvl50Pool->monIds[1], FRONTIER_MON_TEST_MACHOP);

    EXPECT_EQ(openLevelPool->poolSize, 2);
    EXPECT_EQ((u32)openLevelPool->poolRuleIndex, POOL_RULESET_FRONTIER);
    EXPECT_EQ((u32)openLevelPool->poolPickIndex, POOL_PICK_LOWEST);
    EXPECT_EQ(openLevelPool->monIds[0], FRONTIER_MON_TEST_ABRA);
    EXPECT_EQ(openLevelPool->monIds[1], FRONTIER_MON_TEST_BULBASAUR);
}

TEST("frontier trainer selection can use generated pool sets")
{
    const struct BattleFrontierTrainer trainers[] =
    {
        {
            .poolSet = &gTestBattleFrontierPoolSets[FRONTIER_POOL_TEST_LEVEL_50],
        },
    };
    u16 selectedMonId = 0xFFFF;

    gFacilityTrainerMons = gTestBattleFrontierMons;
    gFacilityTrainers = trainers;
    ASSUME(IsFrontierMonHighTier(FRONTIER_MON_TEST_MACHOP));

    SelectFrontierTrainerMons(0, FRONTIER_MAX_LEVEL_50, 1, &selectedMonId, 0);
    EXPECT_EQ(selectedMonId, FRONTIER_MON_TEST_PIKACHU);
}

TEST("frontier mon pools preserve vanilla species and item clauses")
{
    const u16 monSet[] = {
        FRONTIER_MON_TEST_PIKACHU,
        FRONTIER_MON_TEST_PIKACHU_2,
        FRONTIER_MON_TEST_BULBASAUR,
        FRONTIER_MON_TEST_ABRA,
        0xFFFF,
    };
    u16 selectedMonIds[FRONTIER_PARTY_SIZE];

    gFacilityTrainerMons = gTestBattleFrontierMons;
    ASSUME(gTestBattleFrontierMons[FRONTIER_MON_TEST_PIKACHU].species == gTestBattleFrontierMons[FRONTIER_MON_TEST_PIKACHU_2].species);
    ASSUME(gTestBattleFrontierMons[FRONTIER_MON_TEST_PIKACHU].heldItem == gTestBattleFrontierMons[FRONTIER_MON_TEST_BULBASAUR].heldItem);

    SelectFrontierMonsFromSet(monSet, FRONTIER_MAX_LEVEL_OPEN, FRONTIER_PARTY_SIZE, selectedMonIds, 0);

    for (u32 i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        for (u32 j = i + 1; j < FRONTIER_PARTY_SIZE; j++)
        {
            const struct TrainerMon *left = &gTestBattleFrontierMons[selectedMonIds[i]];
            const struct TrainerMon *right = &gTestBattleFrontierMons[selectedMonIds[j]];

            EXPECT(left->species != right->species);
            EXPECT(left->heldItem == ITEM_NONE || left->heldItem != right->heldItem);
        }
    }
}

TEST("battle factory level gating uses high tier tags")
{
    const struct FrontierMonPool *lateOpenPool = GetFactoryMonPool(FRONTIER_LVL_OPEN, 7, FALSE);

    gFacilityTrainerMons = gTestBattleFrontierMons;
    ASSUME(!IsFrontierMonHighTier(FRONTIER_MON_TEST_PIKACHU));
    ASSUME(IsFrontierMonHighTier(FRONTIER_MON_TEST_MACHOP));

    EXPECT(IsFactoryMonAllowedByLevel(FRONTIER_LVL_50, FRONTIER_MON_TEST_PIKACHU));
    EXPECT(!IsFactoryMonAllowedByLevel(FRONTIER_LVL_50, FRONTIER_MON_TEST_MACHOP));
    EXPECT(IsFactoryMonAllowedByLevel(FRONTIER_LVL_OPEN, FRONTIER_MON_TEST_MACHOP));

    ASSUME(lateOpenPool->monIds == NULL);
    EXPECT(lateOpenPool->size > POOL_SLOT_DISABLED);
    EXPECT_EQ(GetTrainerMonPoolAt(lateOpenPool, lateOpenPool->size - 1),
              GetTrainerMonPoolAt(lateOpenPool, 0) + lateOpenPool->size - 1);
}

#define gBattleFrontierMons gTestBattleFrontierMons
#include "battle/frontier_mons.h"
#undef gBattleFrontierMons

#define gBattleFrontierPoolSets gTestBattleFrontierPoolSets
#include "battle/frontier_pool_sets.h"
#undef gBattleFrontierPoolSets
