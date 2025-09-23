#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Trap Master extends the duration of Gravity to 8 turns")
{
    GIVEN {
        PLAYER(SPECIES_ACCELGOR) { Ability(ABILITY_TRAP_MASTER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GRAVITY); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); }

    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRAVITY, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        MESSAGE("Gravity returned to normal!");

}

}

SINGLE_BATTLE_TEST("Trap Master extends the duration of Fairy Lock to 4 turns")
{
    GIVEN {
        PLAYER(SPECIES_ACCELGOR) { Ability(ABILITY_TRAP_MASTER); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_FAIRY_LOCK); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SWITCH(opponent, 1);}
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); }
        TURN { SWITCH(opponent, 1);}
        TURN { MOVE(player, MOVE_CELEBRATE); }

    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_FAIRY_LOCK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        NOT SEND_IN_MESSAGE("Wynaut");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        SEND_IN_MESSAGE("Wynaut");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);

}

}