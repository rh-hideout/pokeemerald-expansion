#ifndef GUARD_BATTLE_CONTROLLER_UTIL_H
#define GUARD_BATTLE_CONTROLLER_UTIL_H

void TrySetBattlerShadowSpriteCallback(u32 battler);

bool32 TryShinyAnimAfterMonAnimUtil(u32 battler);
bool32 SwitchIn_ShowSubstituteUtil(u32 battler, bool32 isPlayerSide);
bool32 SwitchIn_WaitAndEndUtil(u32 battler);
bool32 SwitchIn_HandleSoundAndEndUtil(u32 battler, bool32 isPlayerSide);
bool32 SwitchIn_ShowHealthboxUtil(u32 battler, bool32 isPlayerSide);
bool32 SwitchIn_TryShinyAnimUtil(u32 battler, bool32 isPlayerSide);

#endif // GUARD_BATTLE_CONTROLLER_UTIL_H
