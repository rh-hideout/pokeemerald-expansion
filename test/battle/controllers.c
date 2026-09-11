#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "test/test.h"

TEST("Single battle controller setup ignores unused battler positions")
{
    u32 battleFlags = 0;

    PARAMETRIZE { battleFlags = 0; }
    PARAMETRIZE { battleFlags = BATTLE_TYPE_RECORDED; }
    PARAMETRIZE { battleFlags = BATTLE_TYPE_RECORDED | BATTLE_TYPE_RECORDED_LINK; }
    PARAMETRIZE { battleFlags = BATTLE_TYPE_RECORDED | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_RECORDED_IS_MASTER; }
    PARAMETRIZE { battleFlags = BATTLE_TYPE_LINK; }
    PARAMETRIZE { battleFlags = BATTLE_TYPE_LINK | BATTLE_TYPE_IS_MASTER; }
    PARAMETRIZE { battleFlags = BATTLE_TYPE_SAFARI; }

    gBattleTypeFlags = battleFlags;

    for (u32 i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        gBattlerPositions[i] = B_POSITION_ABSENT;
        gBattlerControllerFuncs[i] = BattleControllerDummy;
    }

    // Stale positions from doubles make unwanted writes observable inside the controller array.
    gBattlerPositions[B_BATTLER_2] = B_POSITION_PLAYER_RIGHT;
    gBattlerPositions[B_BATTLER_3] = B_POSITION_OPPONENT_RIGHT;

    Test_InitBtlControllersInternal();

    EXPECT(gBattlerControllerFuncs[B_BATTLER_2] == BattleControllerDummy);
    EXPECT(gBattlerControllerFuncs[B_BATTLER_3] == BattleControllerDummy);
}
