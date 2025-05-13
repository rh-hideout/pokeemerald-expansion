#include "global.h"
#include "battle.h"
#include "m4a.h"
#include "sound.h"
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

bool32 SwitchIn_HandleSoundAndEndUtil(u32 battler, bool32 isPlayer)
{
    if (gBattleSpritesDataPtr->healthBoxesData[battler].specialAnimActive || IsCryPlayingOrClearCrySongs())
        return FALSE;
    
    if (gSprites[gBattlerSpriteIds[battler]].callback != SpriteCallbackDummy
     && gSprites[gBattlerSpriteIds[battler]].callback != SpriteCallbackDummy_2
     && !isPlayer)
        return FALSE;

    m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
    return TRUE;
}
