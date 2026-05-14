#ifndef GUARD_CHALLENGE_MENU_H
#define GUARD_CHALLENGE_MENU_H

struct ScriptContext;

void CB2_InitChallengeMenu(void);
void Script_OpenChallengeMenu(struct ScriptContext *ctx);
bool32 HMsOverwriteOptionActive(void);
u8 GetMaxPartySize(void);
u8 GetCurrentTrainerIVs(void);
u8 GetCurrentTrainerEVs(void);
bool8 IsPokecenterChallengeActivated(void);
bool8 IsOneTypeChallengeActive(void);
u32 GetBaseStatEqualizerValue(void);

#endif // GUARD_CHALLENGE_MENU_H
