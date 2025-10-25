#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(GetMoveEffect(MOVE_ROLE_PLAY) == EFFECT_ROLE_PLAY);
}

SINGLE_BATTLE_TEST("Sword of Ruin reduces Defense if opposing mon's ability doesn't match")
{
    s16 damage[2];

    GIVEN {
        PLAYER(SPECIES_CHIEN_PAO) { Ability(ABILITY_SWORD_OF_RUIN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_ROLE_PLAY); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SWORD_OF_RUIN);
        MESSAGE("Chien-Pao's Sword of Ruin weakened the Defense of all surrounding Pokémon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &damage[0]);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROLE_PLAY, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &damage[1]);
    } THEN {
        EXPECT_MUL_EQ(damage[1], Q_4_12(1.33), damage[0]);
    }
}

SINGLE_BATTLE_TEST("Sword of Ruin's message displays correctly after all battlers fainted - Player")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_EXPLOSION) == EFFECT_EXPLOSION);
        PLAYER(SPECIES_WOBBUFFET) { HP(1);}
        PLAYER(SPECIES_CHIEN_PAO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EXPLOSION); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_RUINATION); }
    } SCENE {
        HP_BAR(opponent, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, opponent);
        // Everyone faints.
        MESSAGE("Go! Chien-Pao!");
        MESSAGE("2 sent out Wobbuffet!");
        ABILITY_POPUP(player, ABILITY_SWORD_OF_RUIN);
        MESSAGE("Chien-Pao's Sword of Ruin weakened the Defense of all surrounding Pokémon!");
    }
}

SINGLE_BATTLE_TEST("Sword of Ruin's message displays correctly after all battlers fainted - Opponent")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_EXPLOSION) == EFFECT_EXPLOSION);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1);}
        OPPONENT(SPECIES_CHIEN_PAO);
    } WHEN {
        TURN { MOVE(player, MOVE_EXPLOSION); SEND_OUT(player, 1); SEND_OUT(opponent, 1); }
        TURN { MOVE(player, MOVE_RUINATION); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(player, hp: 0);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, player);
        // Everyone faints.
        SEND_IN_MESSAGE("Wobbuffet");
        MESSAGE("2 sent out Chien-Pao!");
        ABILITY_POPUP(opponent, ABILITY_SWORD_OF_RUIN);
        MESSAGE("The opposing Chien-Pao's Sword of Ruin weakened the Defense of all surrounding Pokémon!");
    }
}

DOUBLE_BATTLE_TEST("Sword of Ruin increases damage taken by special moves in Wonder Room")
{
    bool32 useWonderRoom;
    s16 damage[4];
    u32 arrayVal;

    PARAMETRIZE { useWonderRoom = FALSE; arrayVal = 0; }
    PARAMETRIZE { useWonderRoom = TRUE; arrayVal = 2; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WONDER_ROOM) == EFFECT_WONDER_ROOM);
        ASSUME(GetMoveCategory(MOVE_ROUND) == DAMAGE_CATEGORY_SPECIAL);
        ASSUME(GetMoveEffect(MOVE_ROUND) != EFFECT_PSYSHOCK);
        PLAYER(SPECIES_CHIEN_PAO) { Ability(ABILITY_SWORD_OF_RUIN); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (useWonderRoom)
            TURN { MOVE(opponentLeft, MOVE_WONDER_ROOM);
                   MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft);
                   MOVE(playerLeft, MOVE_ROUND, target: opponentRight); }
        else
            TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft);
                   MOVE(playerLeft, MOVE_ROUND, target: opponentRight); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_SWORD_OF_RUIN);
        MESSAGE("Chien-Pao's Sword of Ruin weakened the Defense of all surrounding Pokémon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerRight);
        HP_BAR(opponentLeft, captureDamage: &damage[arrayVal]); // 0 when useWonderRoom = FALSE, 2 when useWonderRoom = TRUE
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, playerLeft);
        HP_BAR(opponentRight, captureDamage: &damage[arrayVal + 1]); // 1 when useWonderRoom = FALSE, 3 when useWonderRoom = TRUE
    } FINALLY {
        EXPECT_LT(damage[2], damage[0]); // In Wonder Room, physical move deals less damage
        EXPECT_GT(damage[3], damage[1]); // In Wonder Room, special move deals more damage
    }
}

SINGLE_BATTLE_TEST("Sword of Ruin doesn't activate when dragged out by Mold Breaker attacker", s16 damage)
{
    u32 ability;

    PARAMETRIZE { ability = ABILITY_MOLD_BREAKER; }
    PARAMETRIZE { ability = ABILITY_SAND_RUSH; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_DRAGON_TAIL) == EFFECT_HIT_SWITCH_TARGET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CHIEN_PAO) { Ability(ABILITY_SWORD_OF_RUIN); }
        OPPONENT(SPECIES_EXCADRILL) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_DRAGON_TAIL); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_TAIL, opponent);
        if (ability == ABILITY_MOLD_BREAKER)
        {
            NONE_OF {
                ABILITY_POPUP(player, ABILITY_SWORD_OF_RUIN);
                MESSAGE("Chien-Pao's Sword of Ruin weakened the Defense of all surrounding Pokémon!");
            }
        }
        else
        {
            ABILITY_POPUP(player, ABILITY_SWORD_OF_RUIN);
            MESSAGE("Chien-Pao's Sword of Ruin weakened the Defense of all surrounding Pokémon!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_LT(results[0].damage, results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Sword of Ruin's Defense reduction is not ignored by Mold Breaker", s16 damage)
{
    u32 ability;

    PARAMETRIZE { ability = ABILITY_MOLD_BREAKER; }
    PARAMETRIZE { ability = ABILITY_SAND_RUSH; }

    GIVEN {
        PLAYER(SPECIES_CHIEN_PAO) { Ability(ABILITY_SWORD_OF_RUIN); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_EXCADRILL) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_SWORD_OF_RUIN);
        MESSAGE("Chien-Pao's Sword of Ruin weakened the Defense of all surrounding Pokémon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerRight, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Sword of Ruin's Defense reduction is ignored by Gastro Acid", s16 damage)
{
    u32 move;

    PARAMETRIZE { move = MOVE_GASTRO_ACID; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GASTRO_ACID) == EFFECT_GASTRO_ACID);
        PLAYER(SPECIES_CHIEN_PAO) { Ability(ABILITY_SWORD_OF_RUIN); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentRight, move, target: playerLeft); MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight); }
    } SCENE {
        ABILITY_POPUP(playerLeft, ABILITY_SWORD_OF_RUIN);
        MESSAGE("Chien-Pao's Sword of Ruin weakened the Defense of all surrounding Pokémon!");
        ANIMATION(ANIM_TYPE_MOVE, move, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerRight, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_LT(results[0].damage, results[1].damage);
    }
}
