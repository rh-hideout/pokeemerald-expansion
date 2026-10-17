#ifndef GUARD_BATTLE_PIKE_H
#define GUARD_BATTLE_PIKE_H

void CallBattlePikeFunction(void);
u8 GetBattlePikeWildMonHeaderId(void);
u32 GetBattlePikeEncounterRate(void);
void GenerateBattlePikeWildMonFromId(u32 pikeMonId, u32 level);
u32 GenerateBattlePikeWildMon(u32 minLevel);
bool8 InBattlePike(void);

#endif // GUARD_BATTLE_PIKE_H
