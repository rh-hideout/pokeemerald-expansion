#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "test/test.h"

TEST("Recorded in-game partners retain their AI ownership")
{
    u32 savedBattleTypeFlags = gBattleTypeFlags;
    u8 savedPosition = gBattlerPositions[B_BATTLER_2];
    u8 savedController = gBattlerBattleController[B_BATTLER_2];

    gBattlerPositions[B_BATTLER_2] = B_POSITION_PLAYER_RIGHT;
    gBattlerBattleController[B_BATTLER_2] = BATTLE_CONTROLLER_RECORDED_PLAYER;

    gBattleTypeFlags = BATTLE_TYPE_RECORDED;
    EXPECT(!BattlerHasAi(B_BATTLER_2));

    gBattleTypeFlags |= BATTLE_TYPE_INGAME_PARTNER;
    EXPECT(BattlerHasAi(B_BATTLER_2));

    gBattleTypeFlags |= BATTLE_TYPE_RECORDED_LINK;
    EXPECT(!BattlerHasAi(B_BATTLER_2));

    gBattleTypeFlags = savedBattleTypeFlags;
    gBattlerPositions[B_BATTLER_2] = savedPosition;
    gBattlerBattleController[B_BATTLER_2] = savedController;
}
