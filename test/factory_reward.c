#include "global.h"
#include "factory_reward.h"
#include "pokemon.h"
#include "test/test.h"
#include "constants/factory_boss.h"
#include "constants/battle_frontier.h"
#include "constants/battle_tent.h"
#include "constants/global.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/species.h"

TEST("Factory boss reward: Steven reward is a valid Mega Metagross set")
{
    struct Pokemon reward = {0};
    bool8 built = BuildFactoryBossRewardMon(FACTORY_BOSS_STEVEN, FRONTIER_LVL_50, &reward);

    EXPECT(built);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SANITY_IS_BAD_EGG), FALSE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SANITY_HAS_SPECIES), TRUE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SPECIES), SPECIES_METAGROSS);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_HELD_ITEM), ITEM_METAGROSSITE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_ABILITY_NUM), 0);
    EXPECT_EQ(GetNature(&reward), NATURE_JOLLY);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_MOVE1), MOVE_METEOR_MASH);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_MOVE2), MOVE_ICE_PUNCH);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_MOVE3), MOVE_ROCK_SLIDE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_MOVE4), MOVE_BULLET_PUNCH);
}

TEST("Factory boss reward: Wally reward is a valid Mega Gallade set")
{
    struct Pokemon reward = {0};
    bool8 built = BuildFactoryBossRewardMon(FACTORY_BOSS_WALLY, FRONTIER_LVL_50, &reward);

    EXPECT(built);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SANITY_IS_BAD_EGG), FALSE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SANITY_HAS_SPECIES), TRUE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SPECIES), SPECIES_GALLADE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_HELD_ITEM), ITEM_GALLADITE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_ABILITY_NUM), 2);
    EXPECT_EQ(GetNature(&reward), NATURE_JOLLY);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_MOVE1), MOVE_SWORDS_DANCE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_MOVE2), MOVE_CLOSE_COMBAT);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_MOVE3), MOVE_ZEN_HEADBUTT);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_MOVE4), MOVE_KNOCK_OFF);
}

TEST("Factory boss reward: Red reward is a valid Pikachu set with Electric Tera type")
{
    struct Pokemon reward = {0};
    bool8 built = BuildFactoryBossRewardMon(FACTORY_BOSS_RED, FRONTIER_LVL_50, &reward);

    EXPECT(built);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SANITY_IS_BAD_EGG), FALSE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SANITY_HAS_SPECIES), TRUE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SPECIES), SPECIES_PIKACHU);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_HELD_ITEM), ITEM_LIGHT_BALL);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_ABILITY_NUM), 0);
    EXPECT_EQ(GetNature(&reward), NATURE_HASTY);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_TERA_TYPE), TYPE_ELECTRIC);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_MOVE1), MOVE_FAKE_OUT);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_MOVE2), MOVE_EXTREME_SPEED);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_MOVE3), MOVE_VOLT_SWITCH);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_MOVE4), MOVE_SURF);
}

TEST("Factory boss reward: Norman reward is a valid Mega Kangaskhan set")
{
    struct Pokemon reward = {0};
    bool8 built = BuildFactoryBossRewardMon(FACTORY_BOSS_NORMAN, FRONTIER_LVL_50, &reward);

    EXPECT(built);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SANITY_IS_BAD_EGG), FALSE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SANITY_HAS_SPECIES), TRUE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SPECIES), SPECIES_KANGASKHAN);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_HELD_ITEM), ITEM_KANGASKHANITE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_ABILITY_NUM), 1);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_TERA_TYPE), TYPE_NORMAL);
    EXPECT_EQ(GetNature(&reward), NATURE_JOLLY);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_MOVE1), MOVE_FAKE_OUT);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_MOVE2), MOVE_RETURN);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_MOVE3), MOVE_SUCKER_PUNCH);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_MOVE4), MOVE_POWER_UP_PUNCH);
}

TEST("Factory boss reward: FACTORY_BOSS_NONE has no reward build")
{
    struct Pokemon reward = {0};
    EXPECT(!BuildFactoryBossRewardMon(FACTORY_BOSS_NONE, FRONTIER_LVL_50, &reward));
}

TEST("Factory boss reward: invalid boss id has no reward build")
{
    struct Pokemon reward = {0};
    EXPECT(!BuildFactoryBossRewardMon(FACTORY_BOSS_COUNT, FRONTIER_LVL_50, &reward));
}

TEST("Factory boss reward: level mode maps to expected reward level")
{
    struct Pokemon reward = {0};

    EXPECT(BuildFactoryBossRewardMon(FACTORY_BOSS_WALLY, FRONTIER_LVL_50, &reward));
    EXPECT_EQ(GetMonData(&reward, MON_DATA_LEVEL), FRONTIER_MAX_LEVEL_50);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SANITY_IS_BAD_EGG), FALSE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SANITY_HAS_SPECIES), TRUE);

    EXPECT(BuildFactoryBossRewardMon(FACTORY_BOSS_WALLY, FRONTIER_LVL_OPEN, &reward));
    EXPECT_EQ(GetMonData(&reward, MON_DATA_LEVEL), FRONTIER_MAX_LEVEL_OPEN);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SANITY_IS_BAD_EGG), FALSE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SANITY_HAS_SPECIES), TRUE);

    EXPECT(BuildFactoryBossRewardMon(FACTORY_BOSS_WALLY, FRONTIER_LVL_TENT, &reward));
    EXPECT_EQ(GetMonData(&reward, MON_DATA_LEVEL), TENT_MIN_LEVEL);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SANITY_IS_BAD_EGG), FALSE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SANITY_HAS_SPECIES), TRUE);
}

TEST("Factory reward helper: boss id resolution prefers active boss")
{
    EXPECT_EQ(GetFactoryRewardBossId(FACTORY_BOSS_RED, FACTORY_BOSS_WALLY), FACTORY_BOSS_RED);
}

TEST("Factory reward helper: boss id resolution falls back to last generated boss")
{
    EXPECT_EQ(GetFactoryRewardBossId(FACTORY_BOSS_NONE, FACTORY_BOSS_WALLY), FACTORY_BOSS_WALLY);
}

TEST("Factory reward helper: boss id resolution clamps invalid ids to none")
{
    EXPECT_EQ(GetFactoryRewardBossId(FACTORY_BOSS_COUNT, FACTORY_BOSS_COUNT), FACTORY_BOSS_NONE);
}

TEST("Factory reward helper: build-from-boss uses active boss first")
{
    struct Pokemon reward = {0};
    u8 bossId = FACTORY_BOSS_NONE;

    EXPECT(TryBuildFactoryRewardFromBoss(FACTORY_BOSS_RED, FACTORY_BOSS_WALLY, FRONTIER_LVL_50, &reward, &bossId));
    EXPECT_EQ(bossId, FACTORY_BOSS_RED);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SPECIES), SPECIES_PIKACHU);
}

TEST("Factory reward helper: build-from-boss falls back to last boss")
{
    struct Pokemon reward = {0};
    u8 bossId = FACTORY_BOSS_NONE;

    EXPECT(TryBuildFactoryRewardFromBoss(FACTORY_BOSS_NONE, FACTORY_BOSS_WALLY, FRONTIER_LVL_50, &reward, &bossId));
    EXPECT_EQ(bossId, FACTORY_BOSS_WALLY);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SPECIES), SPECIES_GALLADE);
}

TEST("Factory reward helper: grant rebuild can use pending boss fallback")
{
    struct Pokemon reward = {0};
    u8 outPendingBossId = FACTORY_BOSS_NONE;
    bool8 usedBossBuild = FALSE;

    EXPECT(TryRebuildFactoryRewardForGrant(FACTORY_BOSS_NONE,
                                           FACTORY_BOSS_NONE,
                                           FACTORY_BOSS_RED,
                                           FRONTIER_LVL_50,
                                           &reward,
                                           &outPendingBossId,
                                           &usedBossBuild));
    EXPECT_EQ(outPendingBossId, FACTORY_BOSS_RED);
    EXPECT_EQ(usedBossBuild, TRUE);
    EXPECT_EQ(GetMonData(&reward, MON_DATA_SPECIES), SPECIES_PIKACHU);
}
