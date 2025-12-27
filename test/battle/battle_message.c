#include "global.h"
#include "test/battle.h"

// hpthresholds behavior in single battles with regular switch
SINGLE_BATTLE_TEST("Battle Message: Send-in message depends on foe HP (switch)")
{
    u32 hp;

    PARAMETRIZE { hp = 100; }
    PARAMETRIZE { hp = 69; }
    PARAMETRIZE { hp = 39; }
    PARAMETRIZE { hp = 9; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(hp); MaxHP(100); }
    } WHEN {
        TURN { SWITCH(player, 1);  }
    } SCENE {
        if (hp > 69)
            MESSAGE("Go! Wynaut!");
        else if (hp > 39)
            MESSAGE("You're in charge, Wynaut!");
        else if (hp > 9)
            MESSAGE("Go for it, Wynaut!");
        else
            MESSAGE("Your opponent's weak! Get 'em, Wynaut!");
    }
}

// hpthresholds behavior in double battles with regular switch
DOUBLE_BATTLE_TEST("Battle Message: Send-in message does not change depending on foe HP in a double battle (switch)")
{
    u32 hp;

    PARAMETRIZE { hp = 100; }
    PARAMETRIZE { hp = 69; }
    PARAMETRIZE { hp = 39; }
    PARAMETRIZE { hp = 9; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(hp); MaxHP(100); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(hp); MaxHP(100); }
    } WHEN {
        TURN { SWITCH(playerLeft, 2);  }
    } SCENE {
        MESSAGE("Go! Wynaut!");
    }
}

// hpthresholds behavior in single battles with Baton Pass send out
SINGLE_BATTLE_TEST("Battle Message: Send-in message depends on foe HP (Baton Pass)")
{
    u32 hp;
    PARAMETRIZE { hp = 100; }
    PARAMETRIZE { hp = 69; }
    PARAMETRIZE { hp = 39; }
    PARAMETRIZE { hp = 9; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(hp); }
    } WHEN {
        TURN { MOVE(player, MOVE_BATON_PASS, partyIndex:1); }
    } SCENE {
        if (hp > 69)
            MESSAGE("Go! Wynaut!");
        else if (hp > 39)
            MESSAGE("You're in charge, Wynaut!");
        else if (hp > 9)
            MESSAGE("Go for it, Wynaut!");
        else
            MESSAGE("Your opponent's weak! Get 'em, Wynaut!");
    }
}

// hpthresholds behavior in double battles with Baton Pass send out
DOUBLE_BATTLE_TEST("Battle Message: Send-in message does not change depending on foe HP in a double battle (Baton Pass)")
{
    u32 hp;
    PARAMETRIZE { hp = 100; }
    PARAMETRIZE { hp = 69; }
    PARAMETRIZE { hp = 39; }
    PARAMETRIZE { hp = 9; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(hp); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(hp); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_BATON_PASS, partyIndex:2); }
    } SCENE {
        MESSAGE("Go! Wynaut!");
    }
}

// hpthresholds behavior in single battles after KO
SINGLE_BATTLE_TEST("Battle Message: Send-in message depends on foe HP (post-KO)")
{
    u32 hp;
    PARAMETRIZE { hp = 100; }
    PARAMETRIZE { hp = 69; }
    PARAMETRIZE { hp = 39; }
    PARAMETRIZE { hp = 9; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET){ HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(hp); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SONIC_BOOM); SEND_OUT(player, 1); }
    } SCENE {
        if (hp > 69)
            MESSAGE("Go! Wynaut!");
        else if (hp > 39)
            MESSAGE("You're in charge, Wynaut!");
        else if (hp > 9)
            MESSAGE("Go for it, Wynaut!");
        else
            MESSAGE("Your opponent's weak! Get 'em, Wynaut!");
    }
}

// hpthresholds behavior in double battles after KO
DOUBLE_BATTLE_TEST("Battle Message: Send-in message does not change depending on foe HP in a double battle (post-KO)")
{
    u32 hp;
    PARAMETRIZE { hp = 100; }
    PARAMETRIZE { hp = 69; }
    PARAMETRIZE { hp = 39; }
    PARAMETRIZE { hp = 9; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET){ HP(1); }
        PLAYER(SPECIES_WOBBUFFET){ HP(1); }
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_RATTATA);
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(hp); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(hp); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SONIC_BOOM, target:playerLeft); 
            MOVE(opponentRight, MOVE_SONIC_BOOM, target:playerRight); 
            SEND_OUT(playerLeft, 2); SEND_OUT(playerRight, 3); }
    } SCENE {
        MESSAGE("Go! Wynaut!");
        MESSAGE("Go! Rattata!");
    }
}

// hpthresholds behavior in double battles with Revival Blessing send out
DOUBLE_BATTLE_TEST("Battle Message: Send-in message does not change depending on foe HP in a double battle (Revival Blessing send out)")
{
    u32 hp;
    PARAMETRIZE { hp = 100; }
    PARAMETRIZE { hp = 69; }
    PARAMETRIZE { hp = 39; }
    PARAMETRIZE { hp = 9; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET){ HP(1); Speed(3); }
        PLAYER(SPECIES_WYNAUT) { HP(1); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(hp); Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { MaxHP(100); HP(hp); Speed(1); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SONIC_BOOM, target:playerRight); 
            MOVE(playerLeft, MOVE_REVIVAL_BLESSING, partyIndex: 1); 
            SEND_OUT(playerRight, 1); }
    } SCENE {
        MESSAGE("Go! Wynaut!");
    }
}

/*

if (*(&gBattleStruct->hpScale) == 0 || IsDoubleBattle())
                stringPtr = sText_GoPkmn2;
            else if (*(&gBattleStruct->hpScale) == 1)
                stringPtr = sText_DoItPkmn;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_GoForItPkmn;
            else
                stringPtr = sText_YourFoesWeakGetEmPkmn;

        if (IsOnPlayerSide(battler))
        {
            if (*(&gBattleStruct->hpScale) == 0)
                stringPtr = sText_PkmnThatsEnough; // >69%
            else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                stringPtr = sText_PkmnComeBack; // 39-69%
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_PkmnOkComeBack; // 9-39%
            else
                stringPtr = sText_PkmnGoodComeBack;
        }

static void Cmd_hpthresholds(void)
{
    CMD_ARGS(u8 battler);

    if (!(IsDoubleBattle()))
    {
        u32 battler = GetBattlerForBattleScript(cmd->battler);
        u32 opposingBattler = BATTLE_OPPOSITE(battler);

        s32 result = gBattleMons[opposingBattler].hp * 100 / gBattleMons[opposingBattler].maxHP;
        if (result == 0)
            result = 1;

        if (result > 69 || !IsBattlerAlive(opposingBattler))
            gBattleStruct->hpScale = 0;
        else if (result > 39)
            gBattleStruct->hpScale = 1;
        else if (result > 9)
            gBattleStruct->hpScale = 2;
        else
            gBattleStruct->hpScale = 3;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}*/
