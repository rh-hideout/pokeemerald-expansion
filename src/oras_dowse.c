#include "global.h"
#include "oras_dowse.h"
#include "bike.h"
#include "event_data.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "fldeff.h"
#include "item_use.h"
#include "palette.h"
#include "script.h"
#include "sound.h"
#include "task.h"
#include "constants/field_effects.h"
#include "constants/songs.h"
#include "constants/rgb.h"

static void StartORASDowseFieldEffect(void);
static void ChangeDowsingColor(u8 direction, struct Sprite *sprite);
static void ClearDowsingColor(struct Sprite *sprite);
static void PlayDowseSound(u32 dowseState);

void Task_UseORASDowsingMachine(u8 taskId)
{
    if (FlagGet(I_ORAS_DOWSING_FLAG))
    {
        EndORASDowsing();
    }
    else
    {
        if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_BIKE))
            GetOnOffBike(0);

        StartORASDowseFieldEffect();
    }
    ScriptUnfreezeObjectEvents();
    UnlockPlayerFieldControls();
    DestroyTask(taskId);
}

static void StartORASDowseFieldEffect(void)
{
    struct ObjectEvent *playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];

    gFieldEffectArguments[0] = playerObj->currentCoords.x;
    gFieldEffectArguments[1] = playerObj->currentCoords.y;
    FieldEffectStart(FLDEFF_ORAS_DOWSE);
}

void ResumeORASDowseFieldEffect(void)
{
    if (I_ORAS_DOWSING_FLAG != 0 && FlagGet(I_ORAS_DOWSING_FLAG))
        StartORASDowseFieldEffect();
}

static const struct SpritePalette gSpritePalette_ORASDowsing = {gFieldEffectPal_ORASDowsing, FLDEFF_PAL_TAG_ORAS_DOWSE};

// Sprite data for ORAS Dowsing Machine
#define tItemDistanceX  data[0]
#define tItemDistanceY  data[1]
#define sItemFound      data[2]
#define sCounter        data[3]
#define sSoundTimer     data[4]
#define sDowseState     data[5]
#define sPrevDowseState data[6]
#define sMoveActive     data[7]

#define fPlayerX        gFieldEffectArguments[0]
#define fPlayerY        gFieldEffectArguments[1]

// Create the ORAS Dowsing Machine sprite.
u32 FldEff_ORASDowsing(void)
{
    struct ObjectEvent *playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];
    u32 spriteId;
    u32 palNum;

    FlagSet(I_ORAS_DOWSING_FLAG);
    SetSpritePosToOffsetMapCoords((s16 *)&fPlayerX, (s16 *)&fPlayerY, 8, 0);
    if (gPlayerAvatar.gender == MALE)
        spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_ORAS_DOWSE_BRENDAN], fPlayerX, fPlayerY, 1);
    else
        spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_ORAS_DOWSE_MAY], fPlayerX, fPlayerY, 1);

    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        palNum = LoadSpritePalette(&gSpritePalette_ORASDowsing);
        if (palNum != 0xFF)
            sprite->oam.paletteNum = palNum;
        else
            sprite->oam.paletteNum = LoadPlayerObjectEventPalette(gSaveBlock2Ptr->playerGender);

        playerObj->fieldEffectSpriteId = spriteId;
        sprite->sDowseState = ORASD_WIGGLE_NONE;
        UpdateDowseState(sprite);
    }
    FieldEffectActiveListRemove(FLDEFF_ORAS_DOWSE);
    return spriteId;
}

static const u8 sClockwiseDirections[] = {DIR_NORTH, DIR_EAST, DIR_SOUTH, DIR_WEST};

void UpdateDowseState(struct Sprite *sprite)
{
    struct ObjectEvent *playerObj = &gObjectEvents[gPlayerAvatar.objectEventId];

    sprite->tItemDistanceX = 0;
    sprite->tItemDistanceY = 0;
    sprite->sPrevDowseState = sprite->sDowseState;
    if (ItemfinderCheckForHiddenItems(gMapHeader.events, TASK_NONE) == TRUE)
    {
        s8 distX = sprite->tItemDistanceX;
        s8 distY = sprite->tItemDistanceY;
        u8 directionToItem = CARDINAL_DIRECTION_COUNT;
        u8 playerDirToItem = GetDirectionToHiddenItem(distX, distY);
        if (playerDirToItem != DIR_NONE)
        {
            directionToItem = (sClockwiseDirections[GetDirectionToHiddenItem(distX, distY) - 1]);
        }

        if (distX < 0)
            distX *= -1;

        if (distY < 0)
            distY *= -1;

        // If the player is facing the item's direction.
        if (directionToItem == playerObj->movementDirection)
        {
            ChangeDowsingColor(directionToItem, sprite);
        }
        // If x and y distances are equal, make sure item can bee seen from both facing directions.
        else if (distX == distY && distX != 0)
        {
            if ((directionToItem == DIR_NORTH || directionToItem == DIR_SOUTH) && sprite->tItemDistanceX > 0 && playerObj->movementDirection == DIR_EAST)
            {
                ChangeDowsingColor(DIR_EAST, sprite);
            }
            else if ((directionToItem == DIR_NORTH || directionToItem == DIR_SOUTH) && sprite->tItemDistanceX < 0 && playerObj->movementDirection == DIR_WEST)
            {
                ChangeDowsingColor(DIR_WEST, sprite);
            }
            else
            {
                ClearDowsingColor(sprite);
            }
        }
        else
        {
            ClearDowsingColor(sprite);
        }
    }
    else
    {
        ClearDowsingColor(sprite);
    }
    UpdateDowsingAnimDirection(sprite, playerObj);
}

static void ChangeDowsingColor(u8 direction, struct Sprite *sprite)
{
    s16 distance;
    u16 color = I_ORAS_DOWSING_COLOR_NONE;

    if (direction == DIR_NORTH || direction == DIR_SOUTH)
        distance = sprite->tItemDistanceY;
    else
        distance = sprite->tItemDistanceX;

    // Absolute value.
    if (distance < 0)
        distance *= -1;

    switch (distance)
    {
    case 1:
        if (sprite->tItemDistanceX == 0 || sprite->tItemDistanceY == 0)
        {
            color = I_ORAS_DOWSING_COLOR_FASTER;
            sprite->sDowseState = ORASD_WIGGLE_FASTER;
            break;
        }
    case 2:
        color = I_ORAS_DOWSING_COLOR_FAST;
        sprite->sDowseState = ORASD_WIGGLE_FAST;
        break;
    case 3:
    case 4:
        color = I_ORAS_DOWSING_COLOR_NORMAL;
        sprite->sDowseState = ORASD_WIGGLE_NORMAL;
        break;
    case 5:
    case 6:
    case 7:
        color = I_ORAS_DOWSING_COLOR_SLOW;
        sprite->sDowseState = ORASD_WIGGLE_SLOW;
        break;
    }

    if (I_ORAS_DOWSING_SOUNDS && sprite->sDowseState != sprite->sPrevDowseState)
    {
        sprite->sSoundTimer = 0;
        PlayDowseSound(sprite->sDowseState);
    }

    FillPalette(color, (OBJ_PLTT_ID(IndexOfSpritePaletteTag(FLDEFF_PAL_TAG_ORAS_DOWSE)) + I_ORAS_DOWSING_COLOR_PAL), PLTT_SIZEOF(1));
    UpdateSpritePaletteWithTime(IndexOfSpritePaletteTag(FLDEFF_PAL_TAG_ORAS_DOWSE));
}

static void ClearDowsingColor(struct Sprite *sprite)
{
    sprite->sDowseState = ORASD_WIGGLE_NONE;
    FillPalette(I_ORAS_DOWSING_COLOR_NONE, (OBJ_PLTT_ID(IndexOfSpritePaletteTag(FLDEFF_PAL_TAG_ORAS_DOWSE)) + I_ORAS_DOWSING_COLOR_PAL), PLTT_SIZEOF(1));
    UpdateSpritePaletteWithTime(IndexOfSpritePaletteTag(FLDEFF_PAL_TAG_ORAS_DOWSE));
}

static void PlayDowseSound(u32 dowseState)
{
    switch (dowseState)
    {
    case ORASD_WIGGLE_SLOW:
        PlaySE(SE_CONTEST_ICON_CLEAR);
        return;
    case ORASD_WIGGLE_NORMAL:
        PlaySE(SE_PIN);
        return;
    case ORASD_WIGGLE_FAST:
        PlaySE(SE_SUCCESS);
        return;
    case ORASD_WIGGLE_FASTER:
        PlaySE(SE_ITEMFINDER);
        return;
    }
}

void UpdateDowsingAnimDirection(struct Sprite *sprite, struct ObjectEvent *playerObj)
{
    u32 anim = (playerObj->facingDirection - 1);

    switch (sprite->sDowseState)
    {
    case ORASD_WIGGLE_SLOW:
        anim += 4;
        break;
    case ORASD_WIGGLE_NORMAL:
        anim += 8;
        break;
    case ORASD_WIGGLE_FAST:
        anim += 12;
        break;
    case ORASD_WIGGLE_FASTER:
        anim += 16;
        break;
    }
    
    // Don't completely restart anim if wiggling didn't stop.
    if (sprite->sPrevDowseState != ORASD_WIGGLE_NONE && sprite->sDowseState != ORASD_WIGGLE_NONE)
        SetAndStartSpriteAnim(sprite, anim, sprite->animCmdIndex);
    else
        StartSpriteAnimIfDifferent(sprite, anim);
}

void EndORASDowsing(void)
{
    if (I_ORAS_DOWSING_FLAG != 0 && FlagGet(I_ORAS_DOWSING_FLAG))
        FlagClear(I_ORAS_DOWSING_FLAG);
}

void Script_ClearDowsingColor(void)
{
    if (I_ORAS_DOWSING_FLAG != 0 && FlagGet(I_ORAS_DOWSING_FLAG))
    {
        struct Sprite *sprite = &gSprites[gObjectEvents[gPlayerAvatar.objectEventId].fieldEffectSpriteId];
        ClearDowsingColor(sprite);
        UpdateDowsingAnimDirection(sprite, &gObjectEvents[gPlayerAvatar.objectEventId]);
    }
}

void Script_UpdateDowseState(void)
{
    if (I_ORAS_DOWSING_FLAG != 0 && FlagGet(I_ORAS_DOWSING_FLAG))
        UpdateDowseState(&gSprites[gObjectEvents[gPlayerAvatar.objectEventId].fieldEffectSpriteId]);
}
