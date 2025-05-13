#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_interface.h"
#include "m4a.h"
#include "sound.h"
#include "task.h"
#include "constants/battle_anim.h"

bool32 SwitchIn_ShowSubstituteUtil(u32 battler, bool32 isPlayerSide)
{
    if (gSprites[gHealthboxSpriteIds[battler]].callback != SpriteCallbackDummy)
        return FALSE;

    if (isPlayerSide)
        CopyBattleSpriteInvisibility(battler);

    if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
        InitAndLaunchSpecialAnimation(battler, battler, battler, B_ANIM_MON_TO_SUBSTITUTE);

    return TRUE;
}

bool32 SwitchIn_HandleSoundAndEndUtil(u32 battler, bool32 isPlayerSide)
{
    if (gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive || IsCryPlayingOrClearCrySongs())
        return FALSE;
    
    if (gSprites[gBattlerSpriteIds[battler]].callback != SpriteCallbackDummy
     && gSprites[gBattlerSpriteIds[battler]].callback != SpriteCallbackDummy_2
     && !isPlayerSide)
        return FALSE;

    m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
    return TRUE;
}

bool32 SwitchIn_ShowHealthboxUtil(u32 battler, bool32 isPlayerSide)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim
    || (!isPlayerSide && gSprites[gBattlerSpriteIds[battler]].callback != SpriteCallbackDummy))
        return FALSE;

    gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = FALSE;
    gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = FALSE;
    FreeSpriteTilesByTag(ANIM_TAG_GOLD_STARS);
    FreeSpritePaletteByTag(ANIM_TAG_GOLD_STARS);

    if (isPlayerSide)
    {
        CreateTask(Task_PlayerController_RestoreBgmAfterCry, 10);
        HandleLowHpMusicChange(GetBattlerMon(battler), battler);
    }

    StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], 0);
    UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], GetBattlerMon(battler), HEALTHBOX_ALL);
    StartHealthboxSlideIn(battler);
    SetHealthboxSpriteVisible(gHealthboxSpriteIds[battler]);

    if (!isPlayerSide)
        CopyBattleSpriteInvisibility(battler);

    return TRUE;
}

bool32 SwitchIn_TryShinyAnimUtil(u32 battler, bool32 isPlayerSide)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive
     && !gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim)
        TryShinyAnimation(battler, GetBattlerMon(battler));

    if (gSprites[gBattleControllerData[battler]].callback != SpriteCallbackDummy
     || gBattleSpritesDataPtr->healthBoxesData[battler].ballAnimActive)
        return FALSE;

    DestroySprite(&gSprites[gBattleControllerData[battler]]);

    if (!isPlayerSide)
        SetBattlerShadowSpriteCallback(battler, GetMonData(GetBattlerMon(battler), MON_DATA_SPECIES));

    return TRUE;
}
