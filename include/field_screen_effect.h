#ifndef GUARD_FIELD_SCREEN_EFFECT_H
#define GUARD_FIELD_SCREEN_EFFECT_H

extern const s32 gMaxFlashLevel;

void WarpFadeInScreen(void);
void WarpFadeOutScreen(void);
void FadeInFromBlack(void);
void FadeInFromWhite(void);
void FieldCB_ContinueScriptUnionRoom(void);
void FieldCB_ContinueScriptHandleMusic(void);
void FieldCB_ContinueScript(void);
void Task_ReturnToFieldRecordMixing(u8 taskId);
void FieldCB_ReturnToFieldCableLink(void);
void FieldCB_ReturnToFieldWirelessLink(void);
void FieldCB_DefaultWarpExit(void);
void FieldCB_WarpExitFadeFromBlack(void);
void FieldCB_WarpExitFadeFromWhite(void);
void FieldCB_RushInjuredPokemonToCentre(void);
bool8 FieldCB_ReturnToFieldOpenStartMenu(void);
void ReturnToFieldOpenStartMenu(void);
void FieldCB_ReturnToFieldNoScript(void);
void FieldCB_ReturnToFieldNoScriptCheckMusic(void);
void DoWarp(void);
void DoDiveWarp(void);
void DoWhiteFadeWarp(void);
void DoDoorWarp(void);
void DoFallWarp(void);
void DoEscalatorWarp(u8 metatileBehaviour);
void DoLavaridgeGymB1FWarp(void);
void DoLavaridgeGym1FWarp(void);
void DoTeleportTileWarp(void);
void DoMossdeepGymWarp(void);
void DoPortholeWarp(void);
void DoCableClubWarp(void);
void DoContestHallWarp(void);
void AnimateFlash(u8 newFlashLevel);
void WriteBattlePyramidViewScanlineEffectBuffer(void);
void DoSpinEnterWarp(void);
void DoSpinExitWarp(void);
void DoOrbEffect(void);
void FadeOutOrbEffect(void);
void WriteFlashScanlineEffectBuffer(u8 flashLevel);
bool8 IsPlayerStandingStill(void);
void DoStairWarp(u16 metatileBehaviour, u16 delay);
bool32 IsDirectionalStairWarpMetatileBehaviour(u16 metatileBehaviour, u8 playerDirection);

#endif // GUARD_FIELD_SCREEN_EFFECT_H
