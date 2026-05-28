//
// DO NOT MODIFY THIS FILE! It is auto-generated from test/battle/frontier_mons.party
//
// If you want to modify this file see expansion PR #7154
//

#line 1 "test/battle/frontier_mons.party"

const struct TrainerMon gBattleFrontierMons[NUM_FRONTIER_MONS] =
{
#line 4
    [FRONTIER_MON_TEST_PIKACHU] = {
#line 6
        .nickname = COMPOUND_STRING("Sparky"),
#line 6
        .species = SPECIES_PIKACHU,
#line 6
        .gender = TRAINER_MON_MALE,
#line 6
        .heldItem = ITEM_LIGHT_BALL,
#line 7
        .ev = TRAINER_PARTY_EVS(252, 4, 12, 60, 36, 44),
#line 8
        .iv = TRAINER_PARTY_IVS(31, 30, 29, 26, 28, 27),
#line 9
        .ability = ABILITY_STATIC,
#line 10
        .lvl = 50,
#line 11
        .ball = BALL_LUXURY,
#line 12
        .friendship = 200,
#line 13
        .nature = NATURE_TIMID,
#line 14
        .isShiny = TRUE,
#line 15
        .dynamaxLevel = 7,
#line 1
        .gigantamaxFactor = TRUE,
        .shouldUseDynamax = TRUE,
#line 17
        .teraType = TYPE_FIRE,
#line 18
        .tags = MON_POOL_TAG_LEAD | MON_POOL_TAG_ACE,
        .moves = {
#line 19
            MOVE_THUNDERBOLT,
            MOVE_SURF,
            MOVE_PROTECT,
            MOVE_VOLT_SWITCH,
        },
    },
#line 24
    [FRONTIER_MON_TEST_ABRA] = {
#line 26
        .species = SPECIES_ABRA,
#line 26
        .heldItem = ITEM_TWISTED_SPOON,
#line 27
        .ev = TRAINER_PARTY_EVS(0, 0, 0, 252, 252, 4),
        .ball = POKEBALL_COUNT,
#line 28
        .nature = NATURE_MODEST,
        .moves = {
#line 29
            MOVE_PSYCHIC,
        },
    },
#line 31
    [FRONTIER_MON_TEST_MACHOP] = {
#line 33
        .species = SPECIES_MACHOP,
#line 33
        .heldItem = ITEM_BLACK_BELT,
        .ball = POKEBALL_COUNT,
#line 34
        .nature = NATURE_BRAVE,
#line 35
        .tags = MON_POOL_TAG_HIGH_TIER,
        .moves = {
#line 36
            MOVE_KARATE_CHOP,
        },
    },
#line 39
    [FRONTIER_MON_TEST_PIKACHU_2] = {
#line 41
        .species = SPECIES_PIKACHU,
#line 41
        .heldItem = ITEM_ORAN_BERRY,
        .ball = POKEBALL_COUNT,
#line 42
        .nature = NATURE_JOLLY,
        .moves = {
#line 43
            MOVE_QUICK_ATTACK,
        },
    },
#line 45
    [FRONTIER_MON_TEST_BULBASAUR] = {
#line 47
        .species = SPECIES_BULBASAUR,
#line 47
        .heldItem = ITEM_LIGHT_BALL,
        .ball = POKEBALL_COUNT,
#line 48
        .nature = NATURE_CALM,
        .moves = {
#line 49
            MOVE_VINE_WHIP,
        },
    },
};
