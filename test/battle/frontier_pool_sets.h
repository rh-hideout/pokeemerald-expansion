const struct TrainerPoolSet gBattleFrontierPoolSets[NUM_FRONTIER_POOL_SETS] =
{
    [FRONTIER_POOL_TEST_LEVEL_50] = {
        .monIds = (const u16[]){
            FRONTIER_MON_TEST_PIKACHU,
            FRONTIER_MON_TEST_MACHOP,
        },
        .poolSize = 2,
        .poolRuleIndex = POOL_RULESET_FRONTIER,
    },
    [FRONTIER_POOL_TEST_OPEN_LEVEL] = {
        .monIds = (const u16[]){
            FRONTIER_MON_TEST_ABRA,
            FRONTIER_MON_TEST_BULBASAUR,
        },
        .poolSize = 2,
        .poolRuleIndex = POOL_RULESET_FRONTIER,
        .poolPickIndex = POOL_PICK_LOWEST,
    },
};
