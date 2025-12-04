#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Dynamax: Max Strike lowers single opponent's speed")
{
    GIVEN {
        // Fails?: ASSUME(GetMaxMove(B_POSITION_PLAYER_LEFT, MOVE_SCRATCH) == MOVE_MAX_STRIKE);
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_STRIKE, MOVE_EFFECT_LOWER_SPEED_SIDE));
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(80); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        // turn 1
        MESSAGE("The opposing Wobbuffet used Scratch!");
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Speed fell!");
        // turn 2
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("The opposing Wobbuffet's Speed fell!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

// This test should apply to all stat-lowering Max Moves, including G-Max Foam Burst and G-Max Tartness.
DOUBLE_BATTLE_TEST("Dynamax: Max Strike lowers both opponents' speed")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_STRIKE, MOVE_EFFECT_LOWER_SPEED_SIDE));
        PLAYER(SPECIES_WOBBUFFET) { Speed(80); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(79); }
        OPPONENT(SPECIES_WOBBUFFET) {Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(99); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); \
               MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); \
               MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft); }
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); \
               MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); \
               MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        // turn 1
        MESSAGE("The opposing Wobbuffet used Scratch!");
        MESSAGE("The opposing Wobbuffet used Scratch!");
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("The opposing Wobbuffet's Speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("The opposing Wobbuffet's Speed fell!");
        // turn 2
        MESSAGE("Wobbuffet used Max Strike!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        MESSAGE("The opposing Wobbuffet's Speed fell!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
        MESSAGE("The opposing Wobbuffet's Speed fell!");
        MESSAGE("The opposing Wobbuffet used Scratch!");
        MESSAGE("The opposing Wobbuffet used Scratch!");
    }
}

// This test should apply to all stat-boosting Max Moves, too.
DOUBLE_BATTLE_TEST("Dynamax: Max Knuckle raises both allies' attack")
{
    s16 damage[4];
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_KNUCKLE, MOVE_EFFECT_RAISE_TEAM_ATTACK));
        ASSUME(GetMoveCategory(MOVE_CLOSE_COMBAT) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CLOSE_COMBAT, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); \
               MOVE(playerRight, MOVE_SCRATCH, target: opponentRight); }
        TURN { MOVE(playerLeft, MOVE_CLOSE_COMBAT, target: opponentLeft); \
               MOVE(playerRight, MOVE_SCRATCH, target: opponentRight); }
    } SCENE {
        // turn 1
        MESSAGE("Wobbuffet used Max Knuckle!");
        HP_BAR(opponentLeft, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Wobbuffet's Attack rose!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Wynaut's Attack rose!");
        MESSAGE("Wynaut used Scratch!");
        HP_BAR(opponentRight, captureDamage: &damage[1]);
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wynaut used Celebrate!");
        // turn 2
        MESSAGE("Wobbuffet used Max Knuckle!");
        HP_BAR(opponentLeft, captureDamage: &damage[2]);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Wobbuffet's Attack rose!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
        MESSAGE("Wynaut's Attack rose!");
        MESSAGE("Wynaut used Scratch!");
        HP_BAR(opponentRight, captureDamage: &damage[3]);
    } THEN {
        EXPECT_GT(damage[2], damage[0]);
        EXPECT_GT(damage[3], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Max Flare sets up sunlight")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_FLARE, MOVE_EFFECT_SUN));
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Flare!");
        MESSAGE("The sunlight turned harsh!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SUN_CONTINUES);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Max Geyser sets up heavy rain")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_GEYSER, MOVE_EFFECT_RAIN));
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_GUN, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Geyser!");
        MESSAGE("It started to rain!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RAIN_CONTINUES);
    }
}

#if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW
SINGLE_BATTLE_TEST("Dynamax: Max Hailstorm sets up snow")
#else
SINGLE_BATTLE_TEST("Dynamax: Max Hailstorm sets up hail")
#endif
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_HAILSTORM, MOVE_EFFECT_HAIL));
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_POWDER_SNOW, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Hailstorm!");
#if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW
        MESSAGE("It started to snow!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SNOW_CONTINUES);
#else
        MESSAGE("It started to hail!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HAIL_CONTINUES);
#endif
    }
}

SINGLE_BATTLE_TEST("Dynamax: Max Rockfall sets up a sandstorm")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_ROCKFALL, MOVE_EFFECT_SANDSTORM));
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROCK_THROW, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Rockfall!");
        MESSAGE("A sandstorm kicked up!");
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SANDSTORM_CONTINUES);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Max Overgrowth sets up Grassy Terrain")
{
    s32 maxHP = 490; // Because of recalculated stats upon Dynamaxing
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_OVERGROWTH, MOVE_EFFECT_GRASSY_TERRAIN));
        ASSUME(GetSpeciesBaseHP(SPECIES_WOBBUFFET) == 190);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(maxHP); HP(maxHP / 2); };
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(maxHP); HP(maxHP / 2); };
    } WHEN {
        TURN { MOVE(player, MOVE_VINE_WHIP, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_VINE_WHIP); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Overgrowth!");
        MESSAGE("Grass grew to cover the battlefield!");
        MESSAGE("Wobbuffet is healed by the grassy terrain!");
        HP_BAR(player, damage: -maxHP/16);
        MESSAGE("The opposing Wobbuffet is healed by the grassy terrain!");
        HP_BAR(opponent, damage: -maxHP/16);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Max Mindstorm sets up Psychic Terrain")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_MINDSTORM, MOVE_EFFECT_PSYCHIC_TERRAIN));
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EXTREME_SPEED); MOVE(player, MOVE_PSYCHIC, gimmick: GIMMICK_DYNAMAX); }
        TURN { MOVE(opponent, MOVE_EXTREME_SPEED); MOVE(player, MOVE_PSYCHIC); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet used Extreme Speed!");
        MESSAGE("Wobbuffet used Max Mindstorm!");
        MESSAGE("The opposing Wobbuffet cannot use Extreme Speed!");
        MESSAGE("Wobbuffet used Max Mindstorm!");
    }
}

SINGLE_BATTLE_TEST("Dynamax: Max Lightning sets up Electric Terrain")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_LIGHTNING, MOVE_EFFECT_ELECTRIC_TERRAIN));
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDERBOLT, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_SPORE); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Lightning!");
        MESSAGE("The opposing Wobbuffet used Spore!");
        MESSAGE("Wobbuffet surrounds itself with electrified terrain!");
    }
}

SINGLE_BATTLE_TEST("Dynamax: Max Starfall sets up Misty Terrain")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_STARFALL, MOVE_EFFECT_MISTY_TERRAIN));
        OPPONENT(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MOONBLAST, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_TOXIC); }
    } SCENE {
        MESSAGE("Wobbuffet used Max Starfall!");
        MESSAGE("The opposing Wobbuffet used Toxic!");
        MESSAGE("Wobbuffet surrounds itself with a protective mist!");
    }
}

SINGLE_BATTLE_TEST("Dynamax: G-Max Stonesurge sets up Stealth Rocks")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_STONESURGE, MOVE_EFFECT_STEALTH_ROCK));
        PLAYER(SPECIES_DREDNAW) { GigantamaxFactor(TRUE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_LIQUIDATION, gimmick: GIMMICK_DYNAMAX); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        // turn 1
        MESSAGE("Drednaw used G-Max Stonesurge!");
        MESSAGE("Pointed stones float in the air around the opposing team!");
        // turn 2
        MESSAGE("Pointed stones dug into the opposing Wobbuffet!");
    }
}

// The test below also tests that sharp steel does type-based damage and can be Defogged away.
SINGLE_BATTLE_TEST("Dynamax: G-Max Steelsurge sets up sharp steel")
{
    GIVEN {
        WITH_CONFIG(CONFIG_DEFOG_EFFECT_CLEARING, GEN_6);
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_STEELSURGE, MOVE_EFFECT_STEELSURGE));
        PLAYER(SPECIES_COPPERAJAH) { GigantamaxFactor(TRUE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_HATTERENE);
    } WHEN {
        TURN { MOVE(player, MOVE_IRON_HEAD, gimmick: GIMMICK_DYNAMAX); }
        TURN { SWITCH(opponent, 1); }
        TURN { } // wait out Dynamax
        TURN { MOVE(opponent, MOVE_DEFOG); }
    } SCENE {
        // turn 1
        MESSAGE("Copperajah used G-Max Steelsurge!");
        MESSAGE("Sharp-pointed pieces of steel started floating around the opposing Pokémon!");
        // turn 2
        MESSAGE("2 sent out Hatterene!");
        MESSAGE("The sharp steel bit into the opposing Hatterene!");
        // turn 4
        MESSAGE("The opposing Hatterene used Defog!");
        MESSAGE("The pieces of steel surrounding the opposing Pokémon disappeared!");
    } THEN {
        EXPECT_MUL_EQ(opponent->maxHP, Q_4_12(0.75), opponent->hp);
    }
}

// The test below should apply to G-Max Fireball and G-Max Drum Solo, too.
SINGLE_BATTLE_TEST("Dynamax: G-Max Hydrosnipe has fixed power and ignores abilities", s16 damage)
{
    u16 move;
    PARAMETRIZE { move = MOVE_WATER_GUN; }
    PARAMETRIZE { move = MOVE_HYDRO_CANNON; }
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_HYDROSNIPE, MOVE_EFFECT_FIXED_POWER));
        PLAYER(SPECIES_INTELEON) { GigantamaxFactor(TRUE); }
        OPPONENT(SPECIES_ARCTOVISH) { Ability(ABILITY_WATER_ABSORB); }
    } WHEN {
        TURN { MOVE(player, move, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("Inteleon used G-Max Hydrosnipe!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Dynamax: G-Max Volt Crash paralyzes both opponents")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_VOLT_CRASH, MOVE_EFFECT_PARALYZE_SIDE));
        PLAYER(SPECIES_PIKACHU) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_PICHU);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_THUNDERBOLT, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("Pikachu used G-Max Volt Crash!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponentLeft);
        MESSAGE("The opposing Wobbuffet is paralyzed, so it may be unable to move!");
        STATUS_ICON(opponentLeft, paralysis: TRUE);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponentRight);
        MESSAGE("The opposing Wynaut is paralyzed, so it may be unable to move!");
        STATUS_ICON(opponentRight, paralysis: TRUE);
    }
}

// G-Max Stun Shock can apply different statuses to each opponent, but this isn't
// compatible with the test RNG set-up.
DOUBLE_BATTLE_TEST("Dynamax: G-Max Stun Shock paralyzes or poisons both opponents")
{
    u8 statusAnim;
    u32 rng;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = STATUS1_PARALYSIS; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; rng = STATUS1_POISON; }
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_STUN_SHOCK, MOVE_EFFECT_POISON_PARALYZE_SIDE));
        PLAYER(SPECIES_TOXTRICITY) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_TOXEL);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_THUNDERBOLT, target: opponentLeft, gimmick: GIMMICK_DYNAMAX, \
               WITH_RNG(RNG_G_MAX_STUN_SHOCK, rng)); }
    } SCENE {
        MESSAGE("Toxtricity used G-Max Stun Shock!");
        // opponent left
        ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponentLeft);
        if (statusAnim == B_ANIM_STATUS_PSN) {
            MESSAGE("The opposing Wobbuffet was poisoned!");
            STATUS_ICON(opponentLeft, poison: TRUE);
        }
        else {
            MESSAGE("The opposing Wobbuffet is paralyzed, so it may be unable to move!");
            STATUS_ICON(opponentLeft, paralysis: TRUE);
        }
        // opponent right
        ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponentRight);
        if (statusAnim == B_ANIM_STATUS_PSN) {
            MESSAGE("The opposing Wynaut was poisoned!");
            STATUS_ICON(opponentRight, poison: TRUE);
        }
        else {
            MESSAGE("The opposing Wynaut is paralyzed, so it may be unable to move!");
            STATUS_ICON(opponentRight, paralysis: TRUE);
        }
    }
}

// This test extends to G-Max Befuddle, too.
DOUBLE_BATTLE_TEST("Dynamax: G-Max Stun Shock chooses statuses before considering immunities")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_STUN_SHOCK, MOVE_EFFECT_POISON_PARALYZE_SIDE));
        PLAYER(SPECIES_TOXTRICITY) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_TOXEL);
        OPPONENT(SPECIES_GARBODOR);
        OPPONENT(SPECIES_TRUBBISH);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_NUZZLE, target: opponentLeft, gimmick: GIMMICK_DYNAMAX, \
               WITH_RNG(RNG_G_MAX_STUN_SHOCK, STATUS1_POISON)); }
    } SCENE {
        MESSAGE("Toxtricity used G-Max Stun Shock!");
        NONE_OF {
            // opponent left
            STATUS_ICON(opponentLeft, poison: TRUE);
            MESSAGE("The opposing Garbodor was poisoned!");
            STATUS_ICON(opponentLeft, paralysis: TRUE);
            MESSAGE("The opposing Garbodor is paralyzed, so it may be unable to move!");
            // opponent right
            STATUS_ICON(opponentRight, poison: TRUE);
            MESSAGE("The opposing Trubbish was poisoned!");
            STATUS_ICON(opponentRight, paralysis: TRUE);
            MESSAGE("The opposing Trubbish is paralyzed, so it may be unable to move!");
        }
    }
}

DOUBLE_BATTLE_TEST("Dynamax: G-Max Befuddle paralyzes, poisons, or sleeps both opponents")
{
    u8 statusAnim;
    u32 rng;
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PRZ; rng = STATUS1_PARALYSIS; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_PSN; rng = STATUS1_POISON; }
    PARAMETRIZE { statusAnim = B_ANIM_STATUS_SLP; rng = STATUS1_SLEEP; }
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_BEFUDDLE, MOVE_EFFECT_EFFECT_SPORE_SIDE));
        PLAYER(SPECIES_BUTTERFREE) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_CATERPIE);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BUG_BITE, target: opponentLeft, gimmick: GIMMICK_DYNAMAX,
               WITH_RNG(RNG_G_MAX_BEFUDDLE, rng)); }
    } SCENE {
        MESSAGE("Butterfree used G-Max Befuddle!");
        // opponent left
        ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponentLeft);
        if (statusAnim == B_ANIM_STATUS_PSN) {
            MESSAGE("The opposing Wobbuffet was poisoned!");
            STATUS_ICON(opponentLeft, poison: TRUE);
        }
        else if (statusAnim == B_ANIM_STATUS_PRZ) {
            MESSAGE("The opposing Wobbuffet is paralyzed, so it may be unable to move!");
            STATUS_ICON(opponentLeft, paralysis: TRUE);
        }
        else {
            MESSAGE("The opposing Wobbuffet fell asleep!");
            STATUS_ICON(opponentLeft, sleep: TRUE);
        }
        // opponent right
        ANIMATION(ANIM_TYPE_STATUS, statusAnim, opponentRight);
        if (statusAnim == B_ANIM_STATUS_PSN) {
            MESSAGE("The opposing Wobbuffet was poisoned!");
            STATUS_ICON(opponentRight, poison: TRUE);
        }
        else if (statusAnim == B_ANIM_STATUS_PRZ) {
            MESSAGE("The opposing Wobbuffet is paralyzed, so it may be unable to move!");
            STATUS_ICON(opponentRight, paralysis: TRUE);
        }
        else {
            MESSAGE("The opposing Wobbuffet fell asleep!");
            STATUS_ICON(opponentRight, sleep: TRUE);
        }
    }
}

DOUBLE_BATTLE_TEST("Dynamax: G-Max Gold Rush confuses both opponents and generates money")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_GOLD_RUSH, MOVE_EFFECT_CONFUSE_PAY_DAY_SIDE));
        PLAYER(SPECIES_MEOWTH) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_PERSIAN);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("Meowth used G-Max Gold Rush!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponentLeft);
        MESSAGE("The opposing Wobbuffet became confused!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponentRight);
        MESSAGE("The opposing Wobbuffet became confused!");
        MESSAGE("Coins were scattered everywhere!");
    }
}

DOUBLE_BATTLE_TEST("Dynamax: G-Max Smite confuses both opponents")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_SMITE, MOVE_EFFECT_CONFUSE_SIDE));
        PLAYER(SPECIES_HATTERENE) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_HATENNA);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MOONBLAST, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("Hatterene used G-Max Smite!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponentLeft);
        MESSAGE("The opposing Wobbuffet became confused!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_CONFUSION, opponentRight);
        MESSAGE("The opposing Wobbuffet became confused!");
    }
}

DOUBLE_BATTLE_TEST("Dynamax: G-Max Cuddle infatuates both opponents, if possible")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_CUDDLE, MOVE_EFFECT_INFATUATE_SIDE));
        PLAYER(SPECIES_EEVEE) { Gender(MON_MALE); GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_EEVEE);
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); }
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_MALE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("Eevee used G-Max Cuddle!");
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_INFATUATION, opponentLeft);
        MESSAGE("The opposing Wobbuffet fell in love!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_INFATUATION, opponentRight);
            MESSAGE("The opposing Wobbuffet fell in love!");
        }
    }
}

DOUBLE_BATTLE_TEST("Dynamax: G-Max Terror traps both opponents")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_TERROR, MOVE_EFFECT_PREVENT_ESCAPE_SIDE));
        PLAYER(SPECIES_GENGAR) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_GASTLY);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_LICK, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("Gengar used G-Max Terror!");
        MESSAGE("The opposing Wobbuffet can no longer escape!");
        MESSAGE("The opposing Wobbuffet can no longer escape!");
    } THEN { // Can't find good way to test trapping
        EXPECT(opponentLeft->volatiles.escapePrevention);
    }
}

SINGLE_BATTLE_TEST("Dynamax: Baton Pass passes G-Max Terror's escape prevention effect")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_TERROR, MOVE_EFFECT_PREVENT_ESCAPE_SIDE));
        PLAYER(SPECIES_GENGAR) { GigantamaxFactor(TRUE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_LICK, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_BATON_PASS); SEND_OUT(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_G_MAX_TERROR, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BATON_PASS, opponent);
    } THEN {
        EXPECT(opponent->volatiles.escapePrevention);
    }
}

DOUBLE_BATTLE_TEST("Dynamax: G-Max Meltdown torments both opponents for 3 turns")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_MELTDOWN, MOVE_EFFECT_TORMENT_SIDE));
        PLAYER(SPECIES_MELMETAL) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_MELTAN);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SPLASH, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WYNAUT) { Moves(MOVE_SPLASH, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_IRON_HEAD, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); \
               MOVE(opponentLeft, MOVE_SPLASH); MOVE(opponentRight, MOVE_SPLASH); }
        TURN { MOVE(playerLeft, MOVE_CELEBRATE, target: opponentLeft); \
               MOVE(opponentLeft, MOVE_SPLASH, allowed: FALSE); \
               MOVE(opponentLeft, MOVE_CELEBRATE); \
               MOVE(opponentRight, MOVE_SPLASH, allowed: FALSE); \
               MOVE(opponentRight, MOVE_CELEBRATE); }
        TURN { MOVE(playerLeft, MOVE_CELEBRATE, target: opponentLeft); \
               MOVE(opponentLeft, MOVE_SPLASH); \
               MOVE(opponentRight, MOVE_SPLASH); }
    } SCENE {
        // turn 1
        MESSAGE("Melmetal used G-Max Meltdown!");
        MESSAGE("The opposing Wobbuffet was subjected to torment!");
        MESSAGE("The opposing Wynaut was subjected to torment!");
        MESSAGE("The opposing Wobbuffet used Splash!");
        MESSAGE("The opposing Wynaut used Splash!");
        // turn 2
        MESSAGE("The opposing Wobbuffet used Celebrate!");
        MESSAGE("The opposing Wynaut used Celebrate!");
        // end of turn 3
        MESSAGE("The opposing Wobbuffet is no longer tormented!");
        MESSAGE("The opposing Wynaut is no longer tormented!");
    }
}

// This test applies to G-Max Cannonade, G-Max Vine Lash, and G-Max Volcalith, too.
DOUBLE_BATTLE_TEST("Dynamax: G-Max Wildfire sets a field effect that damages non-Fire types")
{
    s16 damage;
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_WILDFIRE, MOVE_EFFECT_WILDFIRE));
        PLAYER(SPECIES_CHARIZARD) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_CHARMANDER);
        OPPONENT(SPECIES_WOBBUFFET) { HP(600); MaxHP(600); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ARCANINE);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EMBER, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); }
        TURN { }
        TURN { SWITCH(opponentLeft, 2); }
        TURN { }
        TURN { }
    } SCENE {
        // turn 1
        MESSAGE("Charizard used G-Max Wildfire!");
        MESSAGE("The opposing Pokémon were surrounded by fire!");
        MESSAGE("The opposing Wobbuffet is burning up within G-Max Wildfire's flames!");
        HP_BAR(opponentLeft, captureDamage: &damage);
        MESSAGE("The opposing Wynaut is burning up within G-Max Wildfire's flames!");
        HP_BAR(opponentRight);
        // turn 2
        MESSAGE("The opposing Wobbuffet is burning up within G-Max Wildfire's flames!");
        HP_BAR(opponentLeft);
        MESSAGE("The opposing Wynaut is burning up within G-Max Wildfire's flames!");
        HP_BAR(opponentRight);
        // turn 3
        NONE_OF { MESSAGE("The opposing Arcanine is burning up within G-Max Wildfire's flames!"); }
        MESSAGE("The opposing Wynaut is burning up within G-Max Wildfire's flames!");
        HP_BAR(opponentRight);
        // turn 4
        MESSAGE("The opposing Wynaut is burning up within G-Max Wildfire's flames!");
        HP_BAR(opponentRight);
        // turn 5
        NONE_OF {
            HP_BAR(opponentRight);
            MESSAGE("The opposing Wynaut is burning up within G-Max Wildfire's flames!");
        }
    } THEN {
        EXPECT_EQ(damage, 100);
    }
}

DOUBLE_BATTLE_TEST("Dynamax: G-Max Replenish recycles allies' berries 50\% of the time")
{
    PASSES_RANDOMLY(1, 2, RNG_G_MAX_REPLENISH);
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_REPLENISH, MOVE_EFFECT_RECYCLE_BERRIES));
        PLAYER(SPECIES_SNORLAX) { Item(ITEM_APICOT_BERRY); GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_MUNCHLAX) { Item(ITEM_APICOT_BERRY); Ability(ABILITY_THICK_FAT); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_APICOT_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_APICOT_BERRY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_STUFF_CHEEKS); \
               MOVE(playerRight, MOVE_STUFF_CHEEKS); \
               MOVE(opponentLeft, MOVE_STUFF_CHEEKS); \
               MOVE(opponentRight, MOVE_STUFF_CHEEKS); }
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        // turn 1
        MESSAGE("Using Apicot Berry, the Sp. Def of Snorlax rose!");
        MESSAGE("Using Apicot Berry, the Sp. Def of Munchlax rose!");
        MESSAGE("Using Apicot Berry, the Sp. Def of the opposing Wobbuffet rose!");
        MESSAGE("Using Apicot Berry, the Sp. Def of the opposing Wobbuffet rose!");
        // turn 2
        MESSAGE("Snorlax used G-Max Replenish!");
        MESSAGE("Snorlax found one Apicot Berry!");
        MESSAGE("Munchlax found one Apicot Berry!");
    }
}

DOUBLE_BATTLE_TEST("Dynamax: G-Max Snooze makes only the target drowsy")
{
    PASSES_RANDOMLY(1, 2, RNG_G_MAX_SNOOZE);
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_SNOOZE, MOVE_EFFECT_YAWN_FOE));
        ASSUME(GetMoveCategory(MOVE_DARK_PULSE) == DAMAGE_CATEGORY_SPECIAL); // Otherwise, Blissey faints.
        PLAYER(SPECIES_GRIMMSNARL) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_IMPIDIMP);
        OPPONENT(SPECIES_BLISSEY);
        OPPONENT(SPECIES_CHANSEY);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DARK_PULSE, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); }
        TURN { }
    } SCENE {
        // turn 1
        MESSAGE("Grimmsnarl used G-Max Snooze!");
        MESSAGE("The opposing Blissey grew drowsy!");
        // turn 2
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponentLeft);
        MESSAGE("The opposing Blissey fell asleep!");
        STATUS_ICON(opponentLeft, sleep: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Dynamax: G-Max Finale heals allies by 1/6 of their health")
{
    s16 damage1, damage2;
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_FINALE, MOVE_EFFECT_HEAL_TEAM));
        PLAYER(SPECIES_ALCREMIE) { HP(1); GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_MILCERY) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MOONBLAST, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("Alcremie used G-Max Finale!");
        HP_BAR(playerLeft, captureDamage: &damage1);
        HP_BAR(playerRight, captureDamage: &damage2);
    } THEN {
        EXPECT_MUL_EQ(-damage1, Q_4_12(6), playerLeft->maxHP); // heals based on Dynamax HP
        EXPECT_MUL_EQ(-damage2, Q_4_12(6), playerRight->maxHP);
    }
}

DOUBLE_BATTLE_TEST("Dynamax: G-Max Sweetness cures allies' status conditions")
{
    u32 j;
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_SWEETNESS, MOVE_EFFECT_AROMATHERAPY));
        PLAYER(SPECIES_APPLETUN) { Status1(STATUS1_POISON); GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_APPLIN)  { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_APPLIN)  { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_APPLIN)  { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_APPLIN)  { Status1(STATUS1_POISON); }
        PLAYER(SPECIES_APPLIN)  { Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_VINE_WHIP, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("Appletun used G-Max Sweetness!");
        STATUS_ICON(playerLeft, none: TRUE);
        STATUS_ICON(playerRight, none: TRUE);
    } THEN {
        for (j = 0; j < PARTY_SIZE; j++)
            EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_STATUS), STATUS1_NONE);
    }
}

// This test applies to G-Max Sandblast, too.
DOUBLE_BATTLE_TEST("Dynamax: G-Max Centiferno traps both opponents in Fire Spin")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_CENTIFERNO, MOVE_EFFECT_FIRE_SPIN_SIDE));
        PLAYER(SPECIES_CENTISKORCH) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_SIZZLIPEDE);
        PLAYER(SPECIES_SIZZLIPEDE);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FLAME_CHARGE, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); }
        TURN { SWITCH(playerLeft, 2); }
    } SCENE {
        // turn 1
        MESSAGE("Centiskorch used G-Max Centiferno!");
        MESSAGE("The opposing Wobbuffet is hurt by Fire Spin!");
        HP_BAR(opponentLeft);
        MESSAGE("The opposing Wynaut is hurt by Fire Spin!");
        HP_BAR(opponentRight);
        // turn 2 - Fire Spin continues even after Centiskorch switches out
        MESSAGE("The opposing Wobbuffet is hurt by Fire Spin!");
        HP_BAR(opponentLeft);
        MESSAGE("The opposing Wynaut is hurt by Fire Spin!");
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Dynamax: G-Max Chi Strike boosts allies' crit chance by 1 stage")
{
    u32 j;
    GIVEN {
        WITH_CONFIG(CONFIG_CRIT_CHANCE, GEN_6);
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_CHI_STRIKE, MOVE_EFFECT_CRIT_PLUS_SIDE));
        PLAYER(SPECIES_MACHAMP) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_MACHOP);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_FORCE_PALM, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); }
        TURN { MOVE(playerLeft, MOVE_FORCE_PALM, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_FORCE_PALM, target: opponentLeft); \
               MOVE(playerRight, MOVE_FOCUS_ENERGY); }
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        // turn 1 - 3
        for (j = 0; j < 3; ++j) {
            MESSAGE("Machamp used G-Max Chi Strike!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Machamp is getting pumped!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
            MESSAGE("Machop is getting pumped!");
        }
        // turn 4
        MESSAGE("Machop used Scratch!"); // Machop is at +5 crit stages
        MESSAGE("A critical hit!");
    }
}

TO_DO_BATTLE_TEST("Dynamax: Baton Pass doesn't pass G-Max Chi Strike's effect");

DOUBLE_BATTLE_TEST("Dynamax: G-Max Depletion takes away 2 PP from the target's last move")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_DRAGON_CLAW) == DAMAGE_CATEGORY_PHYSICAL); // Otherwise Sableye faints.
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_DEPLETION, MOVE_EFFECT_SPITE));
        ASSUME(GetMovePP(MOVE_CELEBRATE) >= 3);
        PLAYER(SPECIES_DURALUDON) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_WYNAUT);
        // Dynamax behaves weird with test turn order because stats are recalculated.
        OPPONENT(SPECIES_SABLEYE) { Ability(ABILITY_PRANKSTER); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DRAGON_CLAW, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        MESSAGE("The opposing Sableye used Celebrate!");
        MESSAGE("Duraludon used G-Max Depletion!");
        MESSAGE("The opposing Sableye's PP was reduced!");
    } THEN {
        EXPECT_EQ(opponentLeft->pp[0], GetMovePP(MOVE_CELEBRATE) - 3); // 1 from regular use + 2 from G-Max Depletion
    }
}

// This test applies to G-Max Rapid Flow, too.
DOUBLE_BATTLE_TEST("Dynamax: G-Max One Blow bypasses Max Guard for full damage", s16 damage)
{
    bool32 protect;
    PARAMETRIZE { protect = TRUE; }
    PARAMETRIZE { protect = FALSE; }
    GIVEN {
        ASSUME(MoveIgnoresProtect(MOVE_G_MAX_RAPID_FLOW));
        PLAYER(SPECIES_URSHIFU) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_KUBFU);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        if (protect)
            TURN { MOVE(playerLeft, MOVE_WICKED_BLOW, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); \
                   MOVE(opponentLeft, MOVE_PROTECT, gimmick: GIMMICK_DYNAMAX); }
        else
            TURN { MOVE(playerLeft, MOVE_WICKED_BLOW, target: opponentLeft, gimmick: GIMMICK_DYNAMAX); \
                   MOVE(opponentLeft, MOVE_PSYCHIC, target: playerLeft, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        if (protect)
            MESSAGE("The opposing Wobbuffet used Max Guard!");
        MESSAGE("Urshifu used G-Max One Blow!");
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

// Bug Testing
//  This test will fail if it's the first test a thread runs
DOUBLE_BATTLE_TEST("Dynamax: Max Flare doesn't softlock the game when fainting player partner")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { HP(1); };
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PROTECT, gimmick: GIMMICK_DYNAMAX);
               MOVE(opponentLeft, MOVE_V_CREATE, target: playerRight, gimmick: GIMMICK_DYNAMAX);
               SEND_OUT(playerRight, 2); }
        TURN { }
    }
}

SINGLE_BATTLE_TEST("Dynamax: Max Moves don't execute effects on fainted battlers")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); };
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, player);
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("The opposing Wobbuffet fainted!");
        NOT MESSAGE("The opposing Wobbuffet's Speed fell!");
    }
}

SINGLE_BATTLE_TEST("Dynamax: Max Moves against semi-invulnerable target prints the correct message")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) {Speed(1);};
        OPPONENT(SPECIES_WOBBUFFET) {Speed(2);};
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); MOVE(opponent, MOVE_FLY); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_DYNAMAX_GROWTH, player);
        MESSAGE("Wobbuffet used Max Strike!");
        MESSAGE("The opposing Wobbuffet avoided the attack!");
    }
}

DOUBLE_BATTLE_TEST("Dynamax stat lowering moves don't make stat-changing abilities apply to partner")
{
    u32 move, stat, ability;
    move = 0; stat = 0; ability = 0;
    u32 abilityList[] = {ABILITY_COMPETITIVE, ABILITY_DEFIANT, ABILITY_CONTRARY, ABILITY_SIMPLE};
    for (u32 j = 0; j < 4; j++)
    {
        PARAMETRIZE { move = MOVE_SCRATCH; stat = STAT_SPEED; ability = abilityList[j]; }
        PARAMETRIZE { move = MOVE_FURY_CUTTER; stat = STAT_SPATK; ability = abilityList[j]; }
        PARAMETRIZE { move = MOVE_LICK; stat = STAT_DEF; ability = abilityList[j]; ;}
        PARAMETRIZE { move = MOVE_DRAGON_CLAW; stat = STAT_ATK; ability = abilityList[j]; }
        PARAMETRIZE { move = MOVE_CRUNCH; stat = STAT_SPDEF; ability = abilityList[j]; }
    }
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_STRIKE, MOVE_EFFECT_LOWER_SPEED_SIDE));
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_FLUTTERBY, MOVE_EFFECT_LOWER_SP_ATK_SIDE));
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_PHANTASM, MOVE_EFFECT_LOWER_DEFENSE_SIDE));
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_WYRMWIND, MOVE_EFFECT_LOWER_ATTACK_SIDE));
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_DARKNESS, MOVE_EFFECT_LOWER_SP_DEF_SIDE));
        PLAYER(SPECIES_WOBBUFFET) { }
        PLAYER(SPECIES_WOBBUFFET) { }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
    } WHEN {
        TURN { MOVE(playerLeft, move, target: opponentLeft, gimmick: GIMMICK_DYNAMAX);}
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
    } THEN {
        EXPECT_EQ(opponentRight->statStages[stat], DEFAULT_STAT_STAGE - 1);
    }
}

DOUBLE_BATTLE_TEST("Dynamax stat raising moves don't make stat-changing abilities apply to partner")
{
    u32 move, stat, ability;
    move = 0; stat = 0; ability = 0;
    u32 abilityList[] = {ABILITY_CONTRARY, ABILITY_SIMPLE};
    for (u32 j = 0; j < 2; j++)
    {
        PARAMETRIZE { move = MOVE_PECK; stat = STAT_SPEED; ability = abilityList[j]; }
        PARAMETRIZE { move = MOVE_POISON_JAB; stat = STAT_SPATK; ability = abilityList[j]; }
        PARAMETRIZE { move = MOVE_BULLET_PUNCH; stat = STAT_DEF; ability = abilityList[j]; ;}
        PARAMETRIZE { move = MOVE_DOUBLE_KICK; stat = STAT_ATK; ability = abilityList[j]; }
        PARAMETRIZE { move = MOVE_MUD_SLAP; stat = STAT_SPDEF; ability = abilityList[j]; }
    }
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_STRIKE, MOVE_EFFECT_LOWER_SPEED_SIDE));
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_FLUTTERBY, MOVE_EFFECT_LOWER_SP_ATK_SIDE));
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_PHANTASM, MOVE_EFFECT_LOWER_DEFENSE_SIDE));
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_WYRMWIND, MOVE_EFFECT_LOWER_ATTACK_SIDE));
        ASSUME(MoveHasAdditionalEffect(MOVE_MAX_DARKNESS, MOVE_EFFECT_LOWER_SP_DEF_SIDE));
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_SHADOW_TAG); }
        OPPONENT(SPECIES_WOBBUFFET) {}
        OPPONENT(SPECIES_WOBBUFFET) {}
    } WHEN {
        TURN { MOVE(playerLeft, move, target: opponentLeft, gimmick: GIMMICK_DYNAMAX);}
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerRight);
    } THEN {
        EXPECT_EQ(playerRight->statStages[stat], DEFAULT_STAT_STAGE + 1);
    }
}
