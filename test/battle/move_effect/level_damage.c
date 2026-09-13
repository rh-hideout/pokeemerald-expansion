#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SEISMIC_TOSS) == EFFECT_LEVEL_DAMAGE);
    ASSUME(GetMoveEffect(MOVE_NIGHT_SHADE) == EFFECT_LEVEL_DAMAGE);
}

SINGLE_BATTLE_TEST("Level Damage: Seismic Toss deals damage based on user's level")
{
    s16 dmg;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(50); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SEISMIC_TOSS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SEISMIC_TOSS, player);
        HP_BAR(opponent, captureDamage: &dmg);
    } THEN {
        EXPECT(dmg == 50);
    }
}

SINGLE_BATTLE_TEST("Level Damage: Night Shade is unaffected by type immunities (Gen 1)")
{
    s16 damage;

    GIVEN {
        WITH_CONFIG(B_FIXED_DMG_IGNORES_TYPE, GEN_1);
        PLAYER(SPECIES_WOBBUFFET) { Level(50); }
        OPPONENT(SPECIES_RATTATA);
    } WHEN {
        TURN { MOVE(player, MOVE_NIGHT_SHADE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NIGHT_SHADE, player);
        HP_BAR(opponent, captureDamage: &damage);
    } THEN {
        EXPECT_EQ(damage, 50);
    }
}

SINGLE_BATTLE_TEST("Level Damage: Seismic Toss is unaffected by type immunities (Gen 1)")
{
    s16 damage;

    GIVEN {
        WITH_CONFIG(B_FIXED_DMG_IGNORES_TYPE, GEN_1);
        PLAYER(SPECIES_WOBBUFFET) { Level(50); }
        OPPONENT(SPECIES_GASTLY);
    } WHEN {
        TURN { MOVE(player, MOVE_SEISMIC_TOSS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SEISMIC_TOSS, player);
        HP_BAR(opponent, captureDamage: &damage);
    } THEN {
        EXPECT_EQ(damage, 50);
    }
}
