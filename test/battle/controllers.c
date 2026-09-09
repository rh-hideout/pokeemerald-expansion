#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "test/test.h"

static void SetUpControllers(u32 battleFlags)
{
    gBattleTypeFlags = battleFlags;

    for (u32 i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        gBattlerPositions[i] = B_POSITION_ABSENT;
        gBattlerControllerFuncs[i] = BattleControllerDummy;
    }
}

TEST("Single battle controller setup ignores unused battler positions")
{
    u32 battleFlags = 0;
    bool32 stalePositions = FALSE;
    BattleControllerFunc playerController = SetControllerToPlayer;
    BattleControllerFunc opponentController = SetControllerToOpponent;

    for (u32 i = 0; i < 2; i++)
    {
        PARAMETRIZE { stalePositions = i; battleFlags = 0; playerController = SetControllerToPlayer; opponentController = SetControllerToOpponent; }
        PARAMETRIZE { stalePositions = i; battleFlags = BATTLE_TYPE_RECORDED; playerController = SetControllerToRecordedPlayer; opponentController = SetControllerToOpponent; }
        PARAMETRIZE { stalePositions = i; battleFlags = BATTLE_TYPE_RECORDED | BATTLE_TYPE_RECORDED_LINK; playerController = SetControllerToRecordedPlayer; opponentController = SetControllerToRecordedOpponent; }
        PARAMETRIZE { stalePositions = i; battleFlags = BATTLE_TYPE_RECORDED | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_RECORDED_IS_MASTER; playerController = SetControllerToRecordedPlayer; opponentController = SetControllerToRecordedOpponent; }
        PARAMETRIZE { stalePositions = i; battleFlags = BATTLE_TYPE_LINK; playerController = SetControllerToPlayer; opponentController = SetControllerToLinkOpponent; }
        PARAMETRIZE { stalePositions = i; battleFlags = BATTLE_TYPE_LINK | BATTLE_TYPE_IS_MASTER; playerController = SetControllerToPlayer; opponentController = SetControllerToLinkOpponent; }
        PARAMETRIZE { stalePositions = i; battleFlags = BATTLE_TYPE_SAFARI; playerController = SetControllerToSafari; opponentController = SetControllerToOpponent; }
    }

    SetUpControllers(battleFlags);
    if (stalePositions)
    {
        // Stale positions from doubles make unwanted writes observable inside the controller array.
        gBattlerPositions[B_BATTLER_2] = B_POSITION_PLAYER_RIGHT;
        gBattlerPositions[B_BATTLER_3] = B_POSITION_OPPONENT_RIGHT;
    }

    Test_InitBtlControllersInternal();

    EXPECT_EQ(gBattlersCount, 2);
    EXPECT(gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_0)] == playerController);
    EXPECT(gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_1)] == opponentController);
    EXPECT(gBattlerControllerFuncs[B_BATTLER_2] == BattleControllerDummy);
    EXPECT(gBattlerControllerFuncs[B_BATTLER_3] == BattleControllerDummy);
}

TEST("Double battle controller setup initializes all four battlers")
{
    u32 battleFlags = 0;
    BattleControllerFunc playerController = SetControllerToPlayer;
    BattleControllerFunc opponentController = SetControllerToOpponent;

    PARAMETRIZE { battleFlags = 0; playerController = SetControllerToPlayer; opponentController = SetControllerToOpponent; }
    PARAMETRIZE { battleFlags = BATTLE_TYPE_RECORDED | BATTLE_TYPE_IS_MASTER; playerController = SetControllerToRecordedPlayer; opponentController = SetControllerToOpponent; }
    PARAMETRIZE { battleFlags = BATTLE_TYPE_RECORDED | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_IS_MASTER; playerController = SetControllerToRecordedPlayer; opponentController = SetControllerToRecordedOpponent; }
    PARAMETRIZE { battleFlags = BATTLE_TYPE_RECORDED | BATTLE_TYPE_RECORDED_LINK; playerController = SetControllerToRecordedPlayer; opponentController = SetControllerToRecordedOpponent; }
    PARAMETRIZE { battleFlags = BATTLE_TYPE_LINK; playerController = SetControllerToPlayer; opponentController = SetControllerToLinkOpponent; }
    PARAMETRIZE { battleFlags = BATTLE_TYPE_LINK | BATTLE_TYPE_IS_MASTER; playerController = SetControllerToPlayer; opponentController = SetControllerToLinkOpponent; }

    SetUpControllers(BATTLE_TYPE_DOUBLE | battleFlags);
    Test_InitBtlControllersInternal();

    EXPECT_EQ(gBattlersCount, MAX_BATTLERS_COUNT);
    EXPECT(gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_0)] == playerController);
    EXPECT(gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_1)] == opponentController);
    EXPECT(gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_2)] == playerController);
    EXPECT(gBattlerControllerFuncs[GetBattlerPosition(B_BATTLER_3)] == opponentController);
}
