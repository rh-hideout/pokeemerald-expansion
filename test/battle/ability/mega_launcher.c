#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Mega Launcher boosts pulse moves by 50%", s16 damage)
{
    bool32 suppress;
    enum Move move;
    PARAMETRIZE { move = MOVE_WATER_PULSE; suppress = TRUE; }
    PARAMETRIZE { move = MOVE_WATER_PULSE; suppress = FALSE; }
    PARAMETRIZE { move = MOVE_DARK_PULSE; suppress = TRUE; }
    PARAMETRIZE { move = MOVE_DARK_PULSE; suppress = FALSE; }
    PARAMETRIZE { move = MOVE_DRAGON_PULSE; suppress = TRUE; }
    PARAMETRIZE { move = MOVE_DRAGON_PULSE; suppress = FALSE; }
    PARAMETRIZE { move = MOVE_AURA_SPHERE; suppress = TRUE; }
    PARAMETRIZE { move = MOVE_AURA_SPHERE; suppress = FALSE; }
    PARAMETRIZE { move = MOVE_TERRAIN_PULSE; suppress = TRUE; }
    PARAMETRIZE { move = MOVE_TERRAIN_PULSE; suppress = FALSE; }
    GIVEN {
        ASSUME(IsPulseMove(move));
        PLAYER(SPECIES_CLAUNCHER) { Ability(ABILITY_MEGA_LAUNCHER); SpAttack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); SpDefense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, suppress ? MOVE_GASTRO_ACID : MOVE_CELEBRATE); }
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 10; j += 2)
            EXPECT_MUL_EQ(results[j].damage, UQ_4_12(1.5), results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Mega Launcher does not boost non-pulse moves", s16 damage)
{
    bool32 suppress;
    enum Move move;
    PARAMETRIZE { move = MOVE_WATER_GUN; suppress = TRUE; }
    PARAMETRIZE { move = MOVE_WATER_GUN; suppress = FALSE; }
    PARAMETRIZE { move = MOVE_SCRATCH; suppress = TRUE; }
    PARAMETRIZE { move = MOVE_SCRATCH; suppress = FALSE; }
    GIVEN {
        ASSUME(!IsPulseMove(move));
        PLAYER(SPECIES_CLAUNCHER) { Ability(ABILITY_MEGA_LAUNCHER); SpAttack(200); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); SpDefense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(opponent, suppress ? MOVE_GASTRO_ACID : MOVE_CELEBRATE); }
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 0; j < 4; j += 2)
            EXPECT_EQ(results[j].damage, results[j + 1].damage);
    }
}

SINGLE_BATTLE_TEST("Mega Launcher increases Heal Pulse recovery to three quarters")
{
    bool32 suppress;
    PARAMETRIZE { suppress = FALSE; }
    PARAMETRIZE { suppress = TRUE; }
    GIVEN {
        PLAYER(SPECIES_CLAUNCHER) { Ability(ABILITY_MEGA_LAUNCHER); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(1000); HP(1); }
    } WHEN {
        TURN { MOVE(opponent, suppress ? MOVE_GASTRO_ACID : MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_HEAL_PULSE); }
    } THEN {
        EXPECT_EQ(opponent->hp, suppress ? 501 : 751);
    }
}

DOUBLE_BATTLE_TEST("Mega Launcher increases Heal Pulse recovery for an ally")
{
    GIVEN {
        PLAYER(SPECIES_CLAUNCHER) { Ability(ABILITY_MEGA_LAUNCHER); }
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(1000); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HEAL_PULSE, target: playerRight); }
    } THEN {
        EXPECT_EQ(playerRight->hp, 751);
    }
}

SINGLE_BATTLE_TEST("Mega Launcher does not increase healing when only the recipient has it")
{
    GIVEN {
        PLAYER(SPECIES_CLAUNCHER) { Ability(ABILITY_MEGA_LAUNCHER); MaxHP(1000); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEAL_PULSE); }
    } THEN {
        EXPECT_EQ(player->hp, 501);
    }
}
