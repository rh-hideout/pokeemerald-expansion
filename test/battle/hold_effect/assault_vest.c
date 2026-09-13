#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetItemHoldEffect(ITEM_ASSAULT_VEST) == HOLD_EFFECT_ASSAULT_VEST);
}

SINGLE_BATTLE_TEST("Assault Vest boosts Sp. Def by 50%", s16 damage)
{
    enum Item item;

    PARAMETRIZE { item = ITEM_ASSAULT_VEST; }
    PARAMETRIZE { item = ITEM_NONE; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_WATER_GUN) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Item(item); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Moves(MOVE_WATER_GUN); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("A Pokémon that receives an Assault Vest through Trick or Switcheroo Struggles when Encored")
{
    enum Move transferMove;

    PARAMETRIZE { transferMove = MOVE_TRICK; }
    PARAMETRIZE { transferMove = MOVE_SWITCHEROO; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRICK) == EFFECT_TRICK);
        ASSUME(GetMoveEffect(MOVE_SWITCHEROO) == EFFECT_TRICK);
        ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Moves(transferMove, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Item(ITEM_ASSAULT_VEST); Moves(MOVE_ENCORE, MOVE_SCRATCH); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, transferMove); }
        TURN { MOVE(opponent, MOVE_ENCORE); FORCED_MOVE(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, transferMove, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
    } THEN {
        EXPECT_EQ(player->item, ITEM_ASSAULT_VEST);
    }
}

DOUBLE_BATTLE_TEST("A Pokémon that receives an Assault Vest through Trick or Switcheroo can repeat the move when Instructed")
{
    enum Move transferMove;

    PARAMETRIZE { transferMove = MOVE_TRICK; }
    PARAMETRIZE { transferMove = MOVE_SWITCHEROO; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TRICK) == EFFECT_TRICK);
        ASSUME(GetMoveEffect(MOVE_SWITCHEROO) == EFFECT_TRICK);
        ASSUME(GetMoveEffect(MOVE_INSTRUCT) == EFFECT_INSTRUCT);
        ASSUME(!IsMoveInstructBanned(transferMove));
        PLAYER(SPECIES_WOBBUFFET) { Speed(30); Moves(transferMove, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WYNAUT) { Speed(20); Moves(MOVE_INSTRUCT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); Item(ITEM_ASSAULT_VEST); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_WYNAUT) { Speed(5); }
    } WHEN {
        TURN { MOVE(playerLeft, transferMove, target: opponentLeft); MOVE(playerRight, MOVE_INSTRUCT, target: playerLeft); MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, transferMove, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_INSTRUCT, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, transferMove, playerLeft);
    } THEN {
        EXPECT_EQ(playerLeft->item, ITEM_NONE);
        EXPECT_EQ(opponentLeft->item, ITEM_ASSAULT_VEST);
    }
}

SINGLE_BATTLE_TEST("Assault Vest forces Struggle after the holder exhausts its only damaging move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) {
            Item(ITEM_ASSAULT_VEST);
            MovesWithPP({MOVE_SCRATCH, 1}, {MOVE_CELEBRATE, 10}, {MOVE_GROWL, 10}, {MOVE_SPLASH, 10});
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
        TURN { FORCED_MOVE(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
    }
}

SINGLE_BATTLE_TEST("Assault Vest forces Struggle when Torment blocks the holder's only damaging move")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TORMENT) == EFFECT_TORMENT);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); Item(ITEM_ASSAULT_VEST); Moves(MOVE_SCRATCH, MOVE_CELEBRATE, MOVE_GROWL, MOVE_SPLASH); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); MOVE(opponent, MOVE_TORMENT); }
        TURN { FORCED_MOVE(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TORMENT, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
    }
}
