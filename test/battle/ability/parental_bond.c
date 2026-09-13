#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Parental Bond converts Scratch into a two-strike move")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveStrikeCount(MOVE_SCRATCH) < 2);
        ASSUME(GetMoveEffect(MOVE_SCRATCH) == EFFECT_HIT);
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Kangaskhan's Kangaskhanite is reacting to 1's Mega Ring!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Kangaskhan has Mega Evolved into Mega Kangaskhan!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_KANGASKHAN_MEGA);
    }
}

SINGLE_BATTLE_TEST("Parental Bond does not convert a move with three or more strikes to a two-strike move")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_TRIPLE_KICK) != DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveStrikeCount(MOVE_TRIPLE_KICK) == 3);
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TRIPLE_KICK, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Kangaskhan's Kangaskhanite is reacting to 1's Mega Ring!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Kangaskhan has Mega Evolved into Mega Kangaskhan!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TRIPLE_KICK, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_KANGASKHAN_MEGA);
    }
}

SINGLE_BATTLE_TEST("Parental Bond converts multi-target moves into a two-strike move in Single Battles")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_EARTHQUAKE; }
    PARAMETRIZE { move = MOVE_ICY_WIND; }

    GIVEN {
        ASSUME(GetMoveStrikeCount(MOVE_EARTHQUAKE) < 2);
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveStrikeCount(MOVE_ICY_WIND) < 2);
        ASSUME(GetMoveTarget(MOVE_ICY_WIND) == TARGET_BOTH);
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Kangaskhan's Kangaskhanite is reacting to 1's Mega Ring!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Kangaskhan has Mega Evolved into Mega Kangaskhan!");
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_KANGASKHAN_MEGA);
    }
}

DOUBLE_BATTLE_TEST("Parental Bond does not convert multi-target moves into a two-strike move in Double Battles, even if it only damages one")
{
    GIVEN {
        ASSUME(GetMoveStrikeCount(MOVE_EARTHQUAKE) < 2);
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetSpeciesType(SPECIES_PIDGEY, 1) == TYPE_FLYING);
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        PLAYER(SPECIES_PIDGEY);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE, gimmick: GIMMICK_MEGA); MOVE(playerRight, MOVE_CELEBRATE); MOVE(opponentLeft, MOVE_CELEBRATE); MOVE(opponentRight, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Kangaskhan's Kangaskhanite is reacting to 1's Mega Ring!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, playerLeft);
        MESSAGE("Kangaskhan has Mega Evolved into Mega Kangaskhan!");
        MESSAGE("It doesn't affect Pidgey…");
        MESSAGE("It doesn't affect the opposing Pidgey…");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
        HP_BAR(opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    } THEN {
        EXPECT_EQ(playerLeft->species, SPECIES_KANGASKHAN_MEGA);
    }
}

SINGLE_BATTLE_TEST("Parental Bond-converted moves only hit once on Lightning Rod/Storm Drain mons")
{
    enum Move move;
    enum Species species;
    enum Type type;
    enum Ability ability;
    PARAMETRIZE { move = MOVE_THUNDERBOLT; ability = ABILITY_LIGHTNING_ROD; species = SPECIES_RAICHU; type = TYPE_ELECTRIC; }
    PARAMETRIZE { move = MOVE_SURF;        ability = ABILITY_STORM_DRAIN;   species = SPECIES_LILEEP; type = TYPE_WATER; }
    GIVEN {
        WITH_CONFIG(B_REDIRECT_ABILITY_IMMUNITY, GEN_5);
        ASSUME(GetMoveStrikeCount(move) < 2);
        ASSUME(GetMoveType(move) == type);
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, move, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Kangaskhan's Kangaskhanite is reacting to 1's Mega Ring!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Kangaskhan has Mega Evolved into Mega Kangaskhan!");
        ABILITY_POPUP(opponent, ability);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, move, player);
            HP_BAR(opponent);
            ABILITY_POPUP(opponent, ability);
        };
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_KANGASKHAN_MEGA);
    }
}

SINGLE_BATTLE_TEST("Parental Bond has no effect on multi-hit moves and they still hit twice 37.5/35% of the time")
{
    u32 genConfig, passes, trials;
    PARAMETRIZE { genConfig = GEN_4; passes = 3; trials = 8; }  // 37.5%
    PARAMETRIZE { genConfig = GEN_5; passes = 7; trials = 20; } // 35%
    PASSES_RANDOMLY(passes, trials, RNG_HITS);

    GIVEN {
        WITH_CONFIG(B_MULTI_HIT_CHANCE, genConfig);
        ASSUME(GetMoveCategory(MOVE_COMET_PUNCH) != DAMAGE_CATEGORY_STATUS);
        ASSUME(IsMultiHitMove(MOVE_COMET_PUNCH));
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_COMET_PUNCH, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Kangaskhan's Kangaskhanite is reacting to 1's Mega Ring!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Kangaskhan has Mega Evolved into Mega Kangaskhan!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COMET_PUNCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COMET_PUNCH, player);
        MESSAGE("The Pokémon was hit 2 times!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
    THEN {
        EXPECT_EQ(player->species, SPECIES_KANGASKHAN_MEGA);
    }
}

SINGLE_BATTLE_TEST("Parental Bond has no effect on multi-hit moves and they still hit three times 37.5/35% of the time")
{
    u32 genConfig, passes, trials;
    PARAMETRIZE { genConfig = GEN_4; passes = 3; trials = 8; }  // 37.5%
    PARAMETRIZE { genConfig = GEN_5; passes = 7; trials = 20; } // 35%
    PASSES_RANDOMLY(passes, trials, RNG_HITS);

    GIVEN {
        WITH_CONFIG(B_MULTI_HIT_CHANCE, genConfig);
        ASSUME(GetMoveCategory(MOVE_COMET_PUNCH) != DAMAGE_CATEGORY_STATUS);
        ASSUME(IsMultiHitMove(MOVE_COMET_PUNCH));
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_COMET_PUNCH, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Kangaskhan's Kangaskhanite is reacting to 1's Mega Ring!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Kangaskhan has Mega Evolved into Mega Kangaskhan!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COMET_PUNCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COMET_PUNCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COMET_PUNCH, player);
        MESSAGE("The Pokémon was hit 3 times!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
    THEN {
        EXPECT_EQ(player->species, SPECIES_KANGASKHAN_MEGA);
    }
}

SINGLE_BATTLE_TEST("Parental Bond has no effect on multi-hit moves and they still hit four times 12.5/15% of the time")
{
    u32 genConfig, passes, trials;
    PARAMETRIZE { genConfig = GEN_4; passes = 1; trials = 8; }  // 12.5%
    PARAMETRIZE { genConfig = GEN_5; passes = 3; trials = 20; } // 15%
    PASSES_RANDOMLY(passes, trials, RNG_HITS);

    GIVEN {
        WITH_CONFIG(B_MULTI_HIT_CHANCE, genConfig);
        ASSUME(GetMoveCategory(MOVE_COMET_PUNCH) != DAMAGE_CATEGORY_STATUS);
        ASSUME(IsMultiHitMove(MOVE_COMET_PUNCH));
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_COMET_PUNCH, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Kangaskhan's Kangaskhanite is reacting to 1's Mega Ring!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Kangaskhan has Mega Evolved into Mega Kangaskhan!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COMET_PUNCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COMET_PUNCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COMET_PUNCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COMET_PUNCH, player);
        MESSAGE("The Pokémon was hit 4 times!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
    THEN {
        EXPECT_EQ(player->species, SPECIES_KANGASKHAN_MEGA);
    }
}

SINGLE_BATTLE_TEST("Parental Bond has no effect on multi-hit moves and they still hit five times 12.5/15% of the time")
{
    u32 genConfig, passes, trials;
    PARAMETRIZE { genConfig = GEN_4; passes = 1; trials = 8; }  // 12.5%
    PARAMETRIZE { genConfig = GEN_5; passes = 3; trials = 20; } // 15%
    PASSES_RANDOMLY(passes, trials, RNG_HITS);

    GIVEN {
        WITH_CONFIG(B_MULTI_HIT_CHANCE, genConfig);
        ASSUME(GetMoveCategory(MOVE_COMET_PUNCH) != DAMAGE_CATEGORY_STATUS);
        ASSUME(IsMultiHitMove(MOVE_COMET_PUNCH));
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_COMET_PUNCH, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COMET_PUNCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COMET_PUNCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COMET_PUNCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COMET_PUNCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COMET_PUNCH, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_COMET_PUNCH, player);
        MESSAGE("The Pokémon was hit 5 times!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
    }
    THEN {
        EXPECT_EQ(player->species, SPECIES_KANGASKHAN_MEGA);
    }
}

SINGLE_BATTLE_TEST("Parental Bond Smack Down effect triggers after 2nd hit")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SMACK_DOWN) == EFFECT_SMACK_DOWN);
        ASSUME(GetMoveCategory(MOVE_SMACK_DOWN) != DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveStrikeCount(MOVE_SMACK_DOWN) < 2);
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_SKARMORY);
    } WHEN {
        TURN { MOVE(player, MOVE_SMACK_DOWN, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Kangaskhan's Kangaskhanite is reacting to 1's Mega Ring!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Kangaskhan has Mega Evolved into Mega Kangaskhan!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SMACK_DOWN, player);
        HP_BAR(opponent);
        NOT MESSAGE("The opposing Skarmory fell straight down!");
        HP_BAR(opponent);
        MESSAGE("The opposing Skarmory fell straight down!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_KANGASKHAN_MEGA);
    }
}

SINGLE_BATTLE_TEST("Parental Bond Snore strikes twice while asleep")
{
    s16 damage[2];
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SNORE) == EFFECT_SNORE);
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); Status1(STATUS1_SLEEP); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SNORE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Kangaskhan is fast asleep.");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SNORE, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        HP_BAR(opponent, captureDamage: &damage[1]);
        MESSAGE("The Pokémon was hit 2 times!");
    } THEN {
        if (B_PARENTAL_BOND_DMG >= GEN_7)
            EXPECT_MUL_EQ(damage[0], Q_4_12(0.25), damage[1]);
        else
            EXPECT_MUL_EQ(damage[0], Q_4_12(0.5), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Parental Bond only triggers Dragon Tail's target switch out on the second hit")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DRAGON_TAIL) == EFFECT_HIT_SWITCH_TARGET);
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_DRAGON_TAIL, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
        MESSAGE("The opposing Wynaut was dragged out!");
    }
    THEN {
        EXPECT_EQ(player->species, SPECIES_KANGASKHAN_MEGA);
    }
}

SINGLE_BATTLE_TEST("Parental Bond does not trigger on semi-invulnerable moves")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_FLY) != DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveStrikeCount(MOVE_FLY) < 2);
        ASSUME(GetMoveEffect(MOVE_FLY) == EFFECT_SEMI_INVULNERABLE);
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FLY, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        HP_BAR(opponent);
        NOT HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Parental Bond does not trigger on two turn attacks")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_RAZOR_WIND) != DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveStrikeCount(MOVE_RAZOR_WIND) < 2);
        ASSUME(GetMoveEffect(MOVE_RAZOR_WIND) == EFFECT_TWO_TURNS_ATTACK);
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RAZOR_WIND, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        HP_BAR(opponent);
        NOT HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Parental Bond does not trigger on OHKO moves")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FISSURE) == EFFECT_OHKO);
        ASSUME(GetItemHoldEffect(ITEM_FOCUS_SASH) == HOLD_EFFECT_FOCUS_SASH);
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_MACHAMP) { Ability(ABILITY_NO_GUARD); Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(player, MOVE_FISSURE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FISSURE, player);
        HP_BAR(opponent, hp: 1);
        MESSAGE("The opposing Machamp hung on using its Focus Sash!");
        NOT HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(opponent->hp, 1);
    }
}

SINGLE_BATTLE_TEST("Parental Bond does not trigger on Uproar")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_UPROAR, MOVE_EFFECT_UPROAR));
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_UPROAR, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_UPROAR, player);
        HP_BAR(opponent);
        NOT HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Parental Bond does not trigger Scale Shot effect on Drain Punch")
{
    GIVEN {
        PLAYER(SPECIES_KANGASKHAN) { Item(ITEM_KANGASKHANITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAIN_PUNCH, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAIN_PUNCH, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

SINGLE_BATTLE_TEST("Parental Bond applies Power-Up Punch's Attack raise to both strikes")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffectSelf(MOVE_POWER_UP_PUNCH, MOVE_EFFECT_STAT_PLUS));
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_POWER_UP_PUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POWER_UP_PUNCH, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
    }
}

DOUBLE_BATTLE_TEST("Parental Bond still performs its second strike after Mummy replaces the Ability")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(GetMoveEffect(MOVE_SKILL_SWAP) == EFFECT_SKILL_SWAP);
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); Speed(20); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(10); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Speed(5); }
        OPPONENT(SPECIES_COFAGRIGUS) { Ability(ABILITY_MUMMY); Speed(30); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_SKILL_SWAP, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SKILL_SWAP, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentLeft);
    } THEN {
        EXPECT_EQ(playerLeft->ability, ABILITY_MUMMY);
    }
}

SINGLE_BATTLE_TEST("Rocky Helmet damages a Parental Bond user after each contact strike")
{
    s16 recoil[2];

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        ASSUME(GetItemHoldEffect(ITEM_ROCKY_HELMET) == HOLD_EFFECT_ROCKY_HELMET);
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); HP(600); MaxHP(600); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROCKY_HELMET); HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        HP_BAR(player, captureDamage: &recoil[0]);
        HP_BAR(opponent);
        HP_BAR(player, captureDamage: &recoil[1]);
    } THEN {
        EXPECT_EQ(recoil[0], 100);
        EXPECT_EQ(recoil[1], 100);
    }
}

SINGLE_BATTLE_TEST("Parental Bond performs only one accuracy check for both strikes")
{
    PASSES_RANDOMLY(50, 100, RNG_ACCURACY);

    GIVEN {
        ASSUME(GetMoveAccuracy(MOVE_ZAP_CANNON) == 50);
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_ZAP_CANNON); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ZAP_CANNON, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Parental Bond does not reduce the second strike of fixed-damage moves")
{
    enum Move move;
    u32 expectedHP;

    PARAMETRIZE { move = MOVE_SEISMIC_TOSS; expectedHP = 100; }
    PARAMETRIZE { move = MOVE_DRAGON_RAGE;   expectedHP = 120; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SEISMIC_TOSS) == EFFECT_LEVEL_DAMAGE);
        ASSUME(GetMoveEffect(MOVE_DRAGON_RAGE) == EFFECT_FIXED_HP_DAMAGE);
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); Level(50); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(200); MaxHP(200); }
    } WHEN {
        TURN { MOVE(player, move); }
    } THEN {
        EXPECT_EQ(opponent->hp, expectedHP);
    }
}

SINGLE_BATTLE_TEST("Each Parental Bond strike of Super Fang halves the target's remaining HP")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUPER_FANG) == EFFECT_FIXED_PERCENT_DAMAGE);
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(400); MaxHP(400); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUPER_FANG); }
    } THEN {
        EXPECT_EQ(opponent->hp, 100);
    }
}

SINGLE_BATTLE_TEST("Parental Bond applies Assurance's power increase to the second strike")
{
    s16 damage[2];

    GIVEN {
        WITH_CONFIG(B_PARENTAL_BOND_DMG, GEN_7);
        ASSUME(GetMoveEffect(MOVE_ASSURANCE) == EFFECT_ASSURANCE);
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_ASSURANCE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ASSURANCE, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(0.5), damage[1]);
    }
}

SINGLE_BATTLE_TEST("Natural Gift strikes twice with Parental Bond before consuming its Berry")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_NATURAL_GIFT) == EFFECT_NATURAL_GIFT);
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); Item(ITEM_ORAN_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_NATURAL_GIFT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NATURAL_GIFT, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Parental Bond only uses Endeavor once")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ENDEAVOR) == EFFECT_ENDEAVOR);
        ASSUME(IsMoveParentalBondBanned(MOVE_ENDEAVOR));
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); HP(100); MaxHP(500); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_ENDEAVOR); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENDEAVOR, player);
        HP_BAR(opponent);
        NOT HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(opponent->hp, 100);
    }
}

SINGLE_BATTLE_TEST("Parental Bond recoil is based on the damage from both strikes")
{
    s16 damage[2];
    s16 recoil;

    GIVEN {
        ASSUME(GetMoveRecoil(MOVE_TAKE_DOWN) == 25);
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); HP(1000); MaxHP(1000); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(5000); MaxHP(5000); }
    } WHEN {
        TURN { MOVE(player, MOVE_TAKE_DOWN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAKE_DOWN, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        HP_BAR(opponent, captureDamage: &damage[1]);
        HP_BAR(player, captureDamage: &recoil);
    } THEN {
        EXPECT_MUL_EQ(damage[0] + damage[1], UQ_4_12(0.25), recoil);
    }
}

SINGLE_BATTLE_TEST("Parental Bond applies Knock Off's power increase to both strikes before removing the item")
{
    s16 damage[2];

    GIVEN {
        WITH_CONFIG(B_PARENTAL_BOND_DMG, GEN_7);
        ASSUME(GetMoveEffect(MOVE_KNOCK_OFF) == EFFECT_KNOCK_OFF);
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_LEFTOVERS); HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_KNOCK_OFF); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_KNOCK_OFF, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(0.25), damage[1]);
        EXPECT_EQ(opponent->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Parental Bond applies Smelling Salts' power increase to both strikes before curing paralysis")
{
    s16 damage[2];

    GIVEN {
        WITH_CONFIG(B_PARENTAL_BOND_DMG, GEN_7);
        ASSUME(GetMoveEffect(MOVE_SMELLING_SALTS) == EFFECT_DOUBLE_POWER_ON_ARG_STATUS);
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_PARALYSIS); HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SMELLING_SALTS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SMELLING_SALTS, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(0.25), damage[1]);
        EXPECT_EQ(opponent->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Parental Bond makes U-turn strike twice before the user switches out")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_U_TURN) == EFFECT_HIT_ESCAPE);
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_U_TURN); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_U_TURN, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

SINGLE_BATTLE_TEST("Parental Bond does not add a second strike to a damaging Z-Move")
{
    GIVEN {
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); Item(ITEM_NORMALIUM_Z); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_Z_MOVE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_ZMOVE_ACTIVATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BREAKNECK_BLITZ, player);
        HP_BAR(opponent);
        NOT HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Parental Bond only uses Fling once")
{
    GIVEN {
        ASSUME(IsMoveParentalBondBanned(MOVE_FLING));
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); Item(ITEM_IRON_BALL); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_FLING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FLING, player);
        HP_BAR(opponent);
        NOT HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Parental Bond only uses Final Gambit once")
{
    GIVEN {
        ASSUME(IsMoveParentalBondBanned(MOVE_FINAL_GAMBIT));
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); HP(100); MaxHP(500); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(500); MaxHP(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_FINAL_GAMBIT); }
    } THEN {
        EXPECT_EQ(player->hp, 0);
        EXPECT_EQ(opponent->hp, 400);
    }
}

SINGLE_BATTLE_TEST("Parental Bond only strikes once with a Power Herb-charged move")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SOLAR_BEAM) == EFFECT_SOLAR_BEAM);
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); Item(ITEM_POWER_HERB); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SOLAR_BEAM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SOLAR_BEAM, player);
        HP_BAR(opponent);
        NOT HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Parental Bond does not affect Struggle")
{
    s16 recoil;

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_STRUGGLE) == EFFECT_STRUGGLE);
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); HP(200); MaxHP(200); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_STRUGGLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
        HP_BAR(opponent);
        NOT HP_BAR(opponent);
        HP_BAR(player, captureDamage: &recoil);
    } THEN {
        EXPECT_EQ(recoil, 50);
    }
}

SINGLE_BATTLE_TEST("Parental Bond only scatters coins once with Pay Day")
{
    KNOWN_FAILING;

    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_PAY_DAY, MOVE_EFFECT_PAYDAY));
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); Level(50); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_PAY_DAY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PAY_DAY, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
    } THEN {
        EXPECT_EQ(gPaydayMoney, 250);
    }
}

SINGLE_BATTLE_TEST("Parental Bond does not advance Echoed Voice's power counter between strikes")
{
    s16 damage[2];

    GIVEN {
        WITH_CONFIG(B_PARENTAL_BOND_DMG, GEN_7);
        ASSUME(GetMoveEffect(MOVE_ECHOED_VOICE) == EFFECT_ECHOED_VOICE);
        PLAYER(SPECIES_KANGASKHAN_MEGA) { Ability(ABILITY_PARENTAL_BOND); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_ECHOED_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ECHOED_VOICE, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[0], Q_4_12(0.25), damage[1]);
    }
}
