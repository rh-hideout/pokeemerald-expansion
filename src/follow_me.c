#include "global.h"
#include "follow_me.h"
#include "event_object_movement.h"
#include "field_door.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "field_control_avatar.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "fldeff_misc.h"
#include "item.h"
#include "task.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "script.h"
#include "event_data.h"
#include "sound.h"
#include "trig.h"
#include "metatile_behavior.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/songs.h"
#include "constants/map_types.h"
#include "constants/field_effects.h"
#include "constants/metatile_behaviors.h"

/*
Known Issues:
    -follower gets messed up if you go into a map with a maximum number of event objects
        -inherits incorrect palette, may get directionally confused

    -follower animation can get messed up when sideways hopping with Acro Bike
*/

#if OW_ENABLE_NPC_FOLLOWERS

struct FollowerSpriteGraphics
{
    u16 normalId;
    u16 machBikeId;
    u16 acroBikeId;
    u16 surfId;
    u16 underwaterId;
};

// Function Declarations
static u16 GetFollowerSprite(void);
static void TryUpdateFollowerSpriteUnderwater(void);
static void Task_ReallowPlayerMovement(u8 taskId);
static void PlayerLogCoordinates(struct ObjectEvent* player);
static bool8 IsStateMovement(u8 state);
static u8 ReturnFollowerDelayedState(u8 direction);
static void SetSurfJump(void);
static void Task_BindSurfBlobToFollower(u8 taskId);
static void SetUpSurfBlobFieldEffect(struct ObjectEvent* npc);
static void SetSurfDismount(void);
static void Task_FinishSurfDismount(u8 taskId);
void SetFollowerSurfSpriteAfterDive(void);
static void Task_FollowerOutOfDoor(u8 taskId);
//static void Task_FollowerHandleIndoorStairs(u8 taskId); // UNUSED
static void Task_FollowerHandleEscalator(u8 taskId);
static void Task_FollowerHandleEscalatorFinish(u8 taskId);
static void CalculateFollowerEscalatorTrajectoryUp(struct Task *task);
static void CalculateFollowerEscalatorTrajectoryDown(struct Task *task);
static void TurnNPCIntoFollower(u8 localId, u16 followerFlags, u8 setScript, const u8 *script);

// Const Data
static const struct FollowerSpriteGraphics gFollowerAlternateSprites[] =
{
    // FORMAT:
    // {WALKING/RUNNING SPRITE ID, MACH BIKE SPRITE ID, ACRO BIKE SPRITE ID, SURFING SPRITE ID, DIVE SPRITE ID},
    [0] = 
    {
        .normalId = OBJ_EVENT_GFX_RIVAL_MAY_NORMAL,
        .machBikeId = OBJ_EVENT_GFX_RIVAL_MAY_MACH_BIKE,
        .acroBikeId = OBJ_EVENT_GFX_RIVAL_MAY_ACRO_BIKE,
        .surfId = OBJ_EVENT_GFX_RIVAL_MAY_SURFING,
        .underwaterId = OBJ_EVENT_GFX_MAY_UNDERWATER,
    },
    [1] = 
    {
        .normalId = OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL,
        .machBikeId = OBJ_EVENT_GFX_RIVAL_BRENDAN_MACH_BIKE,
        .acroBikeId = OBJ_EVENT_GFX_RIVAL_BRENDAN_ACRO_BIKE,
        .surfId = OBJ_EVENT_GFX_RIVAL_BRENDAN_SURFING,
        .underwaterId = OBJ_EVENT_GFX_BRENDAN_UNDERWATER,
    },

};

// Functions
u8 GetFollowerObjectId(void)
{
    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return OBJECT_EVENTS_COUNT;

    return gSaveBlock3Ptr->NPCfollower.objId;
}

u8 GetFollowerLocalId(void)
{
    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return 0;

    return gObjectEvents[gSaveBlock3Ptr->NPCfollower.objId].localId;
}

const u8* GetFollowerScriptPointer(void)
{
    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return NULL;

    return gSaveBlock3Ptr->NPCfollower.script;
}
#endif

void HideFollower(void)
{
#if OW_ENABLE_NPC_FOLLOWERS
    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    if (gSaveBlock3Ptr->NPCfollower.createSurfBlob == 2 || gSaveBlock3Ptr->NPCfollower.createSurfBlob == 3)
    {
        SetSurfBlob_BobState(gObjectEvents[GetFollowerMapObjId()].fieldEffectSpriteId, 2);
        DestroySprite(&gSprites[gObjectEvents[GetFollowerMapObjId()].fieldEffectSpriteId]);
        gObjectEvents[GetFollowerMapObjId()].fieldEffectSpriteId = 0; // Unbind
    }

    gObjectEvents[GetFollowerMapObjId()].invisible = TRUE;
#endif
}

#if OW_ENABLE_NPC_FOLLOWERS
void FollowMe_SetIndicatorToComeOutDoor(void)
{
    if (gSaveBlock3Ptr->NPCfollower.inProgress)
        gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs = 1;
}

void FollowMe_SetIndicatorToRecreateSurfBlob(void)
{
    if (gSaveBlock3Ptr->NPCfollower.inProgress)
        gSaveBlock3Ptr->NPCfollower.createSurfBlob = 2;
}

void FollowMe_TryRemoveFollowerOnWhiteOut(void)
{
    if (gSaveBlock3Ptr->NPCfollower.inProgress)
    {
        if (gSaveBlock3Ptr->NPCfollower.flags & FOLLOW_ME_FLAG_CLEAR_ON_WHITE_OUT)
        {
            memset(&gSaveBlock3Ptr->NPCfollower, 0, sizeof(gSaveBlock3Ptr->NPCfollower));
        }
        else
            FollowMe_WarpSetEnd();
    }
}

u8 GetFollowerMapObjId(void)
{
    return gSaveBlock3Ptr->NPCfollower.objId;
}

static u16 GetFollowerSprite(void)
{
    u32 i;

    switch (gSaveBlock3Ptr->NPCfollower.currentSprite)
    {
    case FOLLOWER_SPRITE_INDEX_MACH_BIKE:
        for (i = 0; i < NELEMS(gFollowerAlternateSprites); i++)
        {
            if (gFollowerAlternateSprites[i].normalId == gSaveBlock3Ptr->NPCfollower.graphicsId)
                return gFollowerAlternateSprites[i].machBikeId;
        }
        break;
    case FOLLOWER_SPRITE_INDEX_ACRO_BIKE:
        for (i = 0; i < NELEMS(gFollowerAlternateSprites); i++)
        {
            if (gFollowerAlternateSprites[i].normalId == gSaveBlock3Ptr->NPCfollower.graphicsId)
                return gFollowerAlternateSprites[i].acroBikeId;
        }
        break;
    case FOLLOWER_SPRITE_INDEX_SURF:
        for (i = 0; i < NELEMS(gFollowerAlternateSprites); i++)
        {
            if (gFollowerAlternateSprites[i].normalId == gSaveBlock3Ptr->NPCfollower.graphicsId)
                return gFollowerAlternateSprites[i].surfId;
        }
        break;
    case FOLLOWER_SPRITE_INDEX_UNDERWATER:
        for (i = 0; i < NELEMS(gFollowerAlternateSprites); i++)
        {
            if (gFollowerAlternateSprites[i].normalId == gSaveBlock3Ptr->NPCfollower.graphicsId)
                return gFollowerAlternateSprites[i].underwaterId;
        }
        break;
    }

    return gSaveBlock3Ptr->NPCfollower.graphicsId;
}

static void TryUpdateFollowerSpriteUnderwater(void)
{
    if (gMapHeader.mapType == MAP_TYPE_UNDERWATER)
    {
        struct ObjectEvent* follower = &gObjectEvents[GetFollowerMapObjId()];
        SetFollowerSprite(FOLLOWER_SPRITE_INDEX_UNDERWATER);

        follower = &gObjectEvents[GetFollowerMapObjId()]; // Can change on reload sprite
        follower->fieldEffectSpriteId = StartUnderwaterSurfBlobBobbing(follower->spriteId);
    }
}

//Actual Follow Me
void FollowMe(struct ObjectEvent* npc, u8 state, bool8 ignoreScriptActive)
{
    struct ObjectEvent* player = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct ObjectEvent* follower = &gObjectEvents[GetFollowerMapObjId()];
    u8 dir;
    u8 newState;
    u8 taskId;

    if (player != npc) // Only when the player moves
        return;
    else if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;
    else if (ArePlayerFieldControlsLocked() && !ignoreScriptActive)
        return; // Don't follow during a script


    // fix post-surf jump
    if ((gSaveBlock3Ptr->NPCfollower.currentSprite == FOLLOWER_SPRITE_INDEX_SURF) && !(gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING) && follower->fieldEffectSpriteId == 0)
    {
        SetFollowerSprite(FOLLOWER_SPRITE_INDEX_NORMAL);
        gSaveBlock3Ptr->NPCfollower.createSurfBlob = 0;
    }

    // Check if state would cause hidden follower to reappear
    if (IsStateMovement(state) && gSaveBlock3Ptr->NPCfollower.warpEnd)
    {
        gSaveBlock3Ptr->NPCfollower.warpEnd = 0;

        if (gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs == 1)
        {
            gPlayerAvatar.preventStep = TRUE;
            taskId = CreateTask(Task_FollowerOutOfDoor, 1);
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].data[2] = follower->currentCoords.x;
            gTasks[taskId].data[3] = follower->currentCoords.y;
            TryUpdateFollowerSpriteUnderwater();
            ObjectEventClearHeldMovementIfFinished(follower);
            return;
        }
        else if (gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs == 2)
        {
            gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs = 0;
        }

        follower->invisible = FALSE;
        MoveObjectEventToMapCoords(follower, player->currentCoords.x, player->currentCoords.y);
        ObjectEventTurn(follower, player->facingDirection); // The follower should be facing the same direction as the player when it comes out of hiding

        if (gSaveBlock3Ptr->NPCfollower.createSurfBlob == 2) // Recreate surf blob
        {
            SetUpSurfBlobFieldEffect(follower);
            follower->fieldEffectSpriteId = FieldEffectStart(FLDEFF_SURF_BLOB);
            SetSurfBlob_BobState(follower->fieldEffectSpriteId, 1);
        }
        else
        {
            TryUpdateFollowerSpriteUnderwater();
        }
    }

    dir = DetermineFollowerDirection(player, follower);

    if (dir == DIR_NONE)
    {
        ObjectEventClearHeldMovementIfFinished(follower);
        return;
    }

    newState = DetermineFollowerState(follower, state, dir);
    if (newState == MOVEMENT_INVALID)
    {
        ObjectEventClearHeldMovementIfFinished(follower);
        return;
    }

    if (gSaveBlock3Ptr->NPCfollower.createSurfBlob == 1) // Get on Surf Blob
    {
        gSaveBlock3Ptr->NPCfollower.createSurfBlob = 2;
        gPlayerAvatar.preventStep = TRUE; // Wait for finish
        SetSurfJump();
        ObjectEventClearHeldMovementIfFinished(follower);
        return;
    }
    else if (gSaveBlock3Ptr->NPCfollower.createSurfBlob == 3) // Get off Surf Blob
    {
        gSaveBlock3Ptr->NPCfollower.createSurfBlob = 0;
        gPlayerAvatar.preventStep = TRUE; // Wait for finish
        SetSurfDismount();
        ObjectEventClearHeldMovementIfFinished(follower);
        return;
    }

    ObjectEventClearHeldMovementIfActive(follower);
    ObjectEventSetHeldMovement(follower, newState);
    PlayerLogCoordinates(player);

    switch (newState) 
    {
    case MOVEMENT_ACTION_JUMP_2_DOWN ... MOVEMENT_ACTION_JUMP_2_RIGHT:
        CreateTask(Task_ReallowPlayerMovement, 1); // Synchronize movements on stairs and ledges
        gPlayerAvatar.preventStep = TRUE;   // allow follower to catch up
    }

    ObjectEventClearHeldMovementIfFinished(follower);
}

static void Task_ReallowPlayerMovement(u8 taskId)
{
    bool8 animStatus = ObjectEventClearHeldMovementIfFinished(&gObjectEvents[GetFollowerMapObjId()]);
    if (animStatus == 0)
    {
        if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_DASH)
        && ObjectEventClearHeldMovementIfFinished(&gObjectEvents[gPlayerAvatar.objectEventId]))
            SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT); // Temporarily stop running
        return;
    }

    gPlayerAvatar.preventStep = FALSE;
    DestroyTask(taskId);
}

u8 DetermineFollowerDirection(struct ObjectEvent* player, struct ObjectEvent* follower)
{
    // Move the follower towards the player
    s8 delta_x = follower->currentCoords.x - player->currentCoords.x;
    s8 delta_y = follower->currentCoords.y - player->currentCoords.y;

    if (delta_x < 0)
        return DIR_EAST;
    else if (delta_x > 0)
        return DIR_WEST;

    if (delta_y < 0)
        return DIR_SOUTH;
    else if (delta_y > 0)
        return DIR_NORTH;

    return DIR_NONE;
}

static void PlayerLogCoordinates(struct ObjectEvent* player)
{
    gSaveBlock3Ptr->NPCfollower.log.x = player->currentCoords.x;
    gSaveBlock3Ptr->NPCfollower.log.y = player->currentCoords.y;
}

#define RETURN_STATE(state, dir) return newState == MOVEMENT_INVALID ? state + (dir - 1) : ReturnFollowerDelayedState(dir - 1);
u8 DetermineFollowerState(struct ObjectEvent* follower, u8 state, u8 direction)
{
    u8 newState = MOVEMENT_INVALID;
        u8 collision = COLLISION_NONE;
        s16 followerX = follower->currentCoords.x;
        s16 followerY = follower->currentCoords.y;
        u8 currentBehavior = MapGridGetMetatileBehaviorAt(followerX, followerY);
        u8 nextBehavior;

        MoveCoords(direction, &followerX, &followerY);
        nextBehavior = MapGridGetMetatileBehaviorAt(followerX, followerY);

    if (IsStateMovement(state) && gSaveBlock3Ptr->NPCfollower.delayedState)
        newState = gSaveBlock3Ptr->NPCfollower.delayedState + direction;

    // Clear ice tile stuff
    follower->disableAnim = FALSE; // follower->field1 &= 0xFB;

        // clear overwrite movement
        follower->directionOverwrite = DIR_NONE;

        // sideways stairs checks
        collision = GetSidewaysStairsCollision(follower, direction, currentBehavior, nextBehavior, collision);
        switch (collision)
        {
        case COLLISION_SIDEWAYS_STAIRS_TO_LEFT:
            follower->directionOverwrite = GetLeftSideStairsDirection(direction);
            break;
        case COLLISION_SIDEWAYS_STAIRS_TO_RIGHT:
            follower->directionOverwrite = GetRightSideStairsDirection(direction);
            break;
        }

    switch (state) 
    {
    case MOVEMENT_ACTION_WALK_SLOW_DOWN ... MOVEMENT_ACTION_WALK_SLOW_RIGHT:
        // Slow walk
        RETURN_STATE(MOVEMENT_ACTION_WALK_SLOW_DOWN, direction);

    case MOVEMENT_ACTION_WALK_NORMAL_DOWN ... MOVEMENT_ACTION_WALK_NORMAL_RIGHT:
        // normal walk
        RETURN_STATE(MOVEMENT_ACTION_WALK_NORMAL_DOWN, direction);

    case MOVEMENT_ACTION_JUMP_2_DOWN ... MOVEMENT_ACTION_JUMP_2_RIGHT:
        // Ledge jump
        if (((newState - direction) >= MOVEMENT_ACTION_JUMP_2_DOWN && (newState - direction) <= MOVEMENT_ACTION_JUMP_2_RIGHT)
        ||  ((newState - direction) >= 0x84 && (newState - direction) <= 0x87)) // Previously jumped
        {
            newState = MOVEMENT_INVALID;
            RETURN_STATE(MOVEMENT_ACTION_JUMP_2_DOWN, direction); // Jump right away
        }

        gSaveBlock3Ptr->NPCfollower.delayedState = MOVEMENT_ACTION_JUMP_2_DOWN;
        RETURN_STATE(MOVEMENT_ACTION_WALK_NORMAL_DOWN, direction);

    case MOVEMENT_ACTION_WALK_FAST_DOWN ... MOVEMENT_ACTION_WALK_FAST_RIGHT:
        // Handle player on waterfall
        if (PlayerIsUnderWaterfall(&gObjectEvents[gPlayerAvatar.objectEventId]) && (state == MOVEMENT_ACTION_WALK_FAST_UP))
            return MOVEMENT_INVALID;

        // Handle ice tile (some walking animation) -  Set a bit to freeze the follower's animation
        if (MetatileBehavior_IsIce(follower->currentMetatileBehavior) || MetatileBehavior_IsTrickHouseSlipperyFloor(follower->currentMetatileBehavior))
            follower->disableAnim = TRUE;

        RETURN_STATE(MOVEMENT_ACTION_WALK_FAST_DOWN, direction);

    case MOVEMENT_ACTION_WALK_FASTER_DOWN ... MOVEMENT_ACTION_WALK_FASTER_RIGHT:
        // mach bike
        if (MetatileBehavior_IsIce(follower->currentMetatileBehavior) || MetatileBehavior_IsTrickHouseSlipperyFloor(follower->currentMetatileBehavior))
            follower->disableAnim = TRUE;

        RETURN_STATE(MOVEMENT_ACTION_WALK_FASTER_DOWN, direction);

    // acro bike
    case MOVEMENT_ACTION_RIDE_WATER_CURRENT_DOWN ... MOVEMENT_ACTION_RIDE_WATER_CURRENT_RIGHT:
        // Handle player on waterfall
        if (PlayerIsUnderWaterfall(&gObjectEvents[gPlayerAvatar.objectEventId]) && IsPlayerSurfingNorth())
            return MOVEMENT_INVALID;

        RETURN_STATE(MOVEMENT_ACTION_RIDE_WATER_CURRENT_DOWN, direction);  //regular movement
    case MOVEMENT_ACTION_ACRO_WHEELIE_FACE_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_FACE_RIGHT:
        RETURN_STATE(MOVEMENT_ACTION_ACRO_WHEELIE_FACE_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_DOWN ... MOVEMENT_ACTION_ACRO_POP_WHEELIE_RIGHT:
        RETURN_STATE(MOVEMENT_ACTION_ACRO_POP_WHEELIE_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_DOWN ... MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_RIGHT:
        RETURN_STATE(MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_RIGHT:
        RETURN_STATE(MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_HOP_RIGHT:
        RETURN_STATE(MOVEMENT_ACTION_ACRO_WHEELIE_HOP_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_RIGHT:
        RETURN_STATE(MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_RIGHT:
        RETURN_STATE(MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_DOWN ... MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_RIGHT:
        RETURN_STATE(MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_RIGHT:
        RETURN_STATE(MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_DOWN ... MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_RIGHT:
        RETURN_STATE(MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_DOWN, direction);

    // Sliding
    case MOVEMENT_ACTION_SLIDE_DOWN ... MOVEMENT_ACTION_SLIDE_RIGHT:
        RETURN_STATE(MOVEMENT_ACTION_SLIDE_DOWN, direction);
    case MOVEMENT_ACTION_PLAYER_RUN_DOWN ... MOVEMENT_ACTION_PLAYER_RUN_RIGHT:
        // Running frames
        if (gSaveBlock3Ptr->NPCfollower.flags & FOLLOW_ME_FLAG_HAS_RUNNING_FRAMES)
            RETURN_STATE(MOVEMENT_ACTION_PLAYER_RUN_DOWN, direction);

        RETURN_STATE(MOVEMENT_ACTION_WALK_FAST_DOWN, direction);
    case MOVEMENT_ACTION_JUMP_SPECIAL_DOWN ... MOVEMENT_ACTION_JUMP_SPECIAL_RIGHT:
        gSaveBlock3Ptr->NPCfollower.delayedState = MOVEMENT_ACTION_JUMP_SPECIAL_DOWN;
        RETURN_STATE(MOVEMENT_ACTION_WALK_NORMAL_DOWN, direction);
    case MOVEMENT_ACTION_JUMP_DOWN ... MOVEMENT_ACTION_JUMP_RIGHT:
        gSaveBlock3Ptr->NPCfollower.delayedState = MOVEMENT_ACTION_JUMP_DOWN;
        RETURN_STATE(MOVEMENT_ACTION_WALK_NORMAL_DOWN, direction);

    // run slow
    #ifdef MOVEMENT_ACTION_RUN_DOWN_SLOW
    case MOVEMENT_ACTION_RUN_DOWN_SLOW ... MOVEMENT_ACTION_RUN_RIGHT_SLOW:
        if (gSaveBlock3Ptr->NPCfollower.flags & FOLLOW_ME_FLAG_HAS_RUNNING_FRAMES)
            RETURN_STATE(MOVEMENT_ACTION_RUN_DOWN_SLOW, direction);

        RETURN_STATE(MOVEMENT_ACTION_WALK_NORMAL_DOWN, direction);
    #endif

    default:
        return MOVEMENT_INVALID;
    }

    return newState;
}

static bool8 IsStateMovement(u8 state)
{
    switch (state) 
    {
    case MOVEMENT_ACTION_FACE_DOWN:
    case MOVEMENT_ACTION_FACE_UP:
    case MOVEMENT_ACTION_FACE_LEFT:
    case MOVEMENT_ACTION_FACE_RIGHT:
    case MOVEMENT_ACTION_DELAY_1:
    case MOVEMENT_ACTION_DELAY_2:
    case MOVEMENT_ACTION_DELAY_4:
    case MOVEMENT_ACTION_DELAY_8:
    case MOVEMENT_ACTION_DELAY_16:
    case MOVEMENT_ACTION_FACE_PLAYER:
    case MOVEMENT_ACTION_FACE_AWAY_PLAYER:
    case MOVEMENT_ACTION_LOCK_FACING_DIRECTION:
    case MOVEMENT_ACTION_UNLOCK_FACING_DIRECTION:
    case MOVEMENT_ACTION_SET_INVISIBLE:
    case MOVEMENT_ACTION_SET_VISIBLE:
    case MOVEMENT_ACTION_EMOTE_EXCLAMATION_MARK:
    case MOVEMENT_ACTION_EMOTE_QUESTION_MARK:
    case MOVEMENT_ACTION_EMOTE_HEART:
    case MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_DOWN:
    case MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_UP:
    case MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_LEFT:
    case MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_RIGHT:
    case MOVEMENT_ACTION_WALK_IN_PLACE_FAST_DOWN:
    case MOVEMENT_ACTION_WALK_IN_PLACE_FAST_UP:
    case MOVEMENT_ACTION_WALK_IN_PLACE_FAST_LEFT:
    case MOVEMENT_ACTION_WALK_IN_PLACE_FAST_RIGHT:
    case MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_DOWN:
    case MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_UP:
    case MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_LEFT:
    case MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_RIGHT:
    case MOVEMENT_ACTION_JUMP_IN_PLACE_DOWN:
    case MOVEMENT_ACTION_JUMP_IN_PLACE_UP:
    case MOVEMENT_ACTION_JUMP_IN_PLACE_LEFT:
    case MOVEMENT_ACTION_JUMP_IN_PLACE_RIGHT:
    case MOVEMENT_ACTION_JUMP_IN_PLACE_DOWN_UP:
    case MOVEMENT_ACTION_JUMP_IN_PLACE_UP_DOWN:
    case MOVEMENT_ACTION_JUMP_IN_PLACE_LEFT_RIGHT:
    case MOVEMENT_ACTION_JUMP_IN_PLACE_RIGHT_LEFT:
        return FALSE;
    }

    return TRUE;
}

static u8 ReturnFollowerDelayedState(u8 direction)
{
    u8 newState = gSaveBlock3Ptr->NPCfollower.delayedState;
    gSaveBlock3Ptr->NPCfollower.delayedState = 0;

    return newState + direction;
}

bool8 FollowMe_IsCollisionExempt(struct ObjectEvent* obstacle, struct ObjectEvent* collider)
{
    struct ObjectEvent* follower = &gObjectEvents[GetFollowerMapObjId()];
    struct ObjectEvent* player = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return FALSE;

    if (obstacle == follower && collider == player)
        return TRUE;

    return FALSE;
}

void FollowMe_FollowerToWater(void)
{
    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    // Prepare for making the follower do the jump and spawn the surf head
    // right in front of the follower's location.
    FollowMe(&gObjectEvents[gPlayerAvatar.objectEventId], MOVEMENT_ACTION_JUMP_DOWN, TRUE);
    gSaveBlock3Ptr->NPCfollower.createSurfBlob = 1;
}

void FollowMe_BindToSurfBlobOnReloadScreen(void)
{
    struct ObjectEvent* follower;

    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    follower = &gObjectEvents[GetFollowerMapObjId()];
    TryUpdateFollowerSpriteUnderwater();

    if (gSaveBlock3Ptr->NPCfollower.createSurfBlob != 2 && gSaveBlock3Ptr->NPCfollower.createSurfBlob != 3)
        return;

    // Spawn surfhead under follower
    SetUpSurfBlobFieldEffect(follower);
    follower->fieldEffectSpriteId = FieldEffectStart(FLDEFF_SURF_BLOB);
    SetSurfBlob_BobState(follower->fieldEffectSpriteId, 1);
}

static void SetSurfJump(void)
{
    struct ObjectEvent* follower = &gObjectEvents[GetFollowerMapObjId()];
    u8 direction;
    u8 jumpState;

    // Reset NPC movement bits
    ObjectEventClearHeldMovement(follower);

    // Jump animation according to direction
    direction = DetermineFollowerDirection(&gObjectEvents[gPlayerAvatar.objectEventId], follower);
    jumpState = GetJumpMovementAction(direction);
    SetUpSurfBlobFieldEffect(follower);

    // Adjust surf head spawn location infront of follower
    switch (direction) 
    {
    case DIR_SOUTH:
        gFieldEffectArguments[1]++; // effect_y
        break;
    case DIR_NORTH:
        gFieldEffectArguments[1]--;
        break;
    case DIR_WEST:
        gFieldEffectArguments[0]--; // effect_x
        break;
    default: // DIR_EAST
        gFieldEffectArguments[0]++;
    };

    // Execute, store sprite ID in fieldEffectSpriteId and bind surf blob
    follower->fieldEffectSpriteId = FieldEffectStart(FLDEFF_SURF_BLOB);
    CreateTask(Task_BindSurfBlobToFollower, 0x1);
    SetFollowerSprite(FOLLOWER_SPRITE_INDEX_SURF);

    follower = &gObjectEvents[GetFollowerMapObjId()];
    ObjectEventSetHeldMovement(follower, jumpState);
}

static void Task_BindSurfBlobToFollower(u8 taskId)
{
    struct ObjectEvent* npc = &gObjectEvents[GetFollowerMapObjId()];
    bool8 animStatus = ObjectEventClearHeldMovementIfFinished(npc); // Wait jump animation
    if (animStatus == 0)
        return;

    // Bind objs
    SetSurfBlob_BobState(npc->fieldEffectSpriteId, 0x1);
    UnfreezeObjectEvents();
    DestroyTask(taskId);
    gPlayerAvatar.preventStep = FALSE; // Player can move again
    return;
}

static void SetUpSurfBlobFieldEffect(struct ObjectEvent* npc)
{
    // Set up gFieldEffectArguments for execution
    gFieldEffectArguments[0] = npc->currentCoords.x;     // effect_x
    gFieldEffectArguments[1] = npc->currentCoords.y;    // effect_y
    gFieldEffectArguments[2] = gSaveBlock3Ptr->NPCfollower.objId;    // objId
}

void PrepareFollowerDismountSurf(void)
{
    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    FollowMe(&gObjectEvents[gPlayerAvatar.objectEventId], MOVEMENT_ACTION_WALK_NORMAL_DOWN, TRUE);
    gSaveBlock3Ptr->NPCfollower.createSurfBlob = 3;
}

static void SetSurfDismount(void)
{
    struct ObjectEvent* follower = &gObjectEvents[GetFollowerMapObjId()];
    u8 direction;
    u8 jumpState;
    u8 task;

    ObjectEventClearHeldMovement(follower);

    // Jump animation according to direction
    direction = DetermineFollowerDirection(&gObjectEvents[gPlayerAvatar.objectEventId], follower);
    jumpState = GetJumpMovementAction(direction);

    // Unbind and destroy Surf Blob
    task = CreateTask(Task_FinishSurfDismount, 1);
    gTasks[task].data[0] = follower->fieldEffectSpriteId;
    SetSurfBlob_BobState(follower->fieldEffectSpriteId, 2);
    follower->fieldEffectSpriteId = 0; // Unbind
    FollowMe_HandleSprite();

    follower = &gObjectEvents[GetFollowerMapObjId()]; // Can change after sprite reload
    ObjectEventSetHeldMovement(follower, jumpState);
}

static void Task_FinishSurfDismount(u8 taskId)
{
    struct ObjectEvent* npc = &gObjectEvents[GetFollowerMapObjId()];
    bool8 animStatus = ObjectEventClearHeldMovementIfFinished(npc); // Wait animation

    if (animStatus == 0)
    {
        if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_DASH) && ObjectEventClearHeldMovementIfFinished(&gObjectEvents[gPlayerAvatar.objectEventId]))
            SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT); // Temporarily stop running

        return;
    }

    DestroySprite(&gSprites[gTasks[taskId].data[0]]);
    UnfreezeObjectEvents();
    DestroyTask(taskId);
    gPlayerAvatar.preventStep = FALSE;
}
#endif

void SetFollowerSurfSpriteAfterDive(void)
{
#if OW_ENABLE_NPC_FOLLOWERS
    SetFollowerSprite(FOLLOWER_SPRITE_INDEX_SURF);
    gSaveBlock3Ptr->NPCfollower.createSurfBlob = 2;
#endif
}

#if OW_ENABLE_NPC_FOLLOWERS
static u8 GetPlayerFaceToDoorDirection(struct ObjectEvent* player, struct ObjectEvent* follower)
{
    s16 delta_x = player->currentCoords.x - follower->currentCoords.x;

    if (delta_x < 0)
        return DIR_EAST;
    else if (delta_x > 0)
        return DIR_WEST;

    return DIR_NORTH;
}

static void Task_FollowerOutOfDoor(u8 taskId)
{
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerMapObjId()];
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Task *task = &gTasks[taskId];
    s16 *x = &task->data[2];
    s16 *y = &task->data[3];

    if (OW_FACE_NPC_FOLLOWER_ON_DOOR_EXIT == TRUE && ObjectEventClearHeldMovementIfFinished(player)) {
        ObjectEventTurn(player, GetPlayerFaceToDoorDirection(player, follower)); // The player should face towards the follow as the exit the door
    }

    switch (task->data[0])
    {
    case 0:
        FreezeObjectEvents();
        task->data[1] = FieldAnimateDoorOpen(follower->currentCoords.x, follower->currentCoords.y);
        if (task->data[1] != -1)
            PlaySE(GetDoorSoundEffect(*x, *y)); // only play SE for animating doors

        task->data[0] = 1;
        break;
    case 1:
        if (task->data[1] < 0 || gTasks[task->data[1]].isActive != TRUE) // if Door isn't still opening
        {
            follower->invisible = FALSE;
            ObjectEventTurn(follower, DIR_SOUTH); // The follower should be facing down when it comes out the door
            follower->singleMovementActive = FALSE;
            follower->heldMovementActive = FALSE;
            ObjectEventSetHeldMovement(follower, MOVEMENT_ACTION_WALK_NORMAL_DOWN); // follower step down
            task->data[0] = 2;
        }
        break;
    case 2:
        if (ObjectEventClearHeldMovementIfFinished(follower))
        {
            task->data[1] = FieldAnimateDoorClose(*x, *y);
            task->data[0] = 3;
        }
        break;
    case 3:
        if (task->data[1] < 0 || gTasks[task->data[1]].isActive != TRUE) // Door is closed
        {
            UnfreezeObjectEvents();
            task->data[0] = 4;
        }
        break;
    case 4:
        FollowMe_HandleSprite();
        gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs = 0;
        gPlayerAvatar.preventStep = FALSE; // Player can move again
        DestroyTask(taskId);
        break;
    }
}

/* UNUSED
void StairsMoveFollower(void)
{
    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    if (!FuncIsActiveTask(Task_FollowerHandleIndoorStairs) && gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs != 2)
        CreateTask(Task_FollowerHandleIndoorStairs, 1);
}

static void Task_FollowerHandleIndoorStairs(u8 taskId)
{
    struct ObjectEvent* follower = &gObjectEvents[GetFollowerMapObjId()];
    struct ObjectEvent* player = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs = 2; // So the task doesn't get created more than once
        ObjectEventClearHeldMovementIfActive(follower);
        ObjectEventSetHeldMovement(follower, DetermineFollowerState(follower, MOVEMENT_ACTION_WALK_NORMAL_DOWN, DetermineFollowerDirection(player, follower)));
        task->data[0]++;
        break;
    case 1:
        if (ObjectEventClearHeldMovementIfFinished(follower))
        {
            ObjectEventSetHeldMovement(follower, DetermineFollowerState(follower, MOVEMENT_ACTION_WALK_NORMAL_DOWN, player->movementDirection));
            DestroyTask(taskId);
        }
        break;
    }
}
*/

void EscalatorMoveFollower(u8 movementType)
{
    u8 taskId;

    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    taskId = CreateTask(Task_FollowerHandleEscalator, 1);
    gTasks[taskId].data[1] = movementType;
}

static void Task_FollowerHandleEscalator(u8 taskId)
{
    struct ObjectEvent* follower = &gObjectEvents[GetFollowerMapObjId()];
    struct ObjectEvent* player = &gObjectEvents[gPlayerAvatar.objectEventId];

    ObjectEventClearHeldMovementIfActive(follower);
    ObjectEventSetHeldMovement(follower, DetermineFollowerState(follower, MOVEMENT_ACTION_WALK_NORMAL_DOWN, DetermineFollowerDirection(player, follower)));
    DestroyTask(taskId);
}

void EscalatorMoveFollowerFinish(void)
{
    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    CreateTask(Task_FollowerHandleEscalatorFinish, 1);
}

static void Task_FollowerHandleEscalatorFinish(u8 taskId)
{
    s16 x, y;
    struct ObjectEvent* follower = &gObjectEvents[GetFollowerMapObjId()];
    struct ObjectEvent* player = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite* sprite = &gSprites[follower->spriteId];
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        MoveObjectEventToMapCoords(follower, player->currentCoords.x, player->currentCoords.y);
        PlayerGetDestCoords(&x, &y);
        task->data[2] = MapGridGetMetatileBehaviorAt(x, y);
        task->data[7] = 0;
        task->data[0]++;
        break;
    case 1:
        if (task->data[7]++ < 0x20) // Wait half a second before revealing the follower
            break;

        task->data[0]++;
        task->data[1] = 16;
        CalculateFollowerEscalatorTrajectoryUp(task);
        gSaveBlock3Ptr->NPCfollower.warpEnd = 0;
        gPlayerAvatar.preventStep = TRUE;
        ObjectEventSetHeldMovement(follower, GetFaceDirectionMovementAction(DIR_EAST));
        if (task->data[2] == 0x6b)
            task->data[0] = 4;
        break;
    case 2:
        follower->invisible = FALSE;
        CalculateFollowerEscalatorTrajectoryDown(task);
        task->data[0]++;
        break;
    case 3:
        CalculateFollowerEscalatorTrajectoryDown(task);
        task->data[2]++;
        if (task->data[2] & 1)
        {
            task->data[1]--;
        }

        if (task->data[1] == 0)
        {
            sprite->x2 = 0;
            sprite->y2 = 0;
            task->data[0] = 6;
        }
        break;
    case 4:
        follower->invisible = FALSE;
        CalculateFollowerEscalatorTrajectoryUp(task);
        task->data[0]++;
        break;
    case 5:
        CalculateFollowerEscalatorTrajectoryUp(task);
        task->data[2]++;
        if (task->data[2] & 1)
        {
            task->data[1]--;
        }

        if (task->data[1] == 0)
        {
            sprite->x2 = 0;
            sprite->y2 = 0;
            task->data[0]++;
        }
        break;
    case 6:
        if (ObjectEventClearHeldMovementIfFinished(follower))
        {
            gPlayerAvatar.preventStep = FALSE;
            DestroyTask(taskId);
        }
    }
}

static void CalculateFollowerEscalatorTrajectoryDown(struct Task *task)
{
    struct Sprite* sprite = &gSprites[gObjectEvents[GetFollowerMapObjId()].spriteId];

    sprite->x2 = Cos(0x84, task->data[1]);
    sprite->y2 = Sin(0x94, task->data[1]);
}

static void CalculateFollowerEscalatorTrajectoryUp(struct Task *task)
{
    struct Sprite* sprite = &gSprites[gObjectEvents[GetFollowerMapObjId()].spriteId];

    sprite->x2 = Cos(0x7c, task->data[1]);
    sprite->y2 = Sin(0x76, task->data[1]);
}

bool8 FollowerCanBike(void)
{
    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return TRUE;
    else if (gSaveBlock3Ptr->NPCfollower.flags & FOLLOW_ME_FLAG_CAN_BIKE)
        return TRUE;
    else
        return FALSE;
}

void FollowMe_HandleBike(void)
{
    if (gSaveBlock3Ptr->NPCfollower.currentSprite == FOLLOWER_SPRITE_INDEX_SURF) // Follower is surfing
        return; // Sprite will automatically be adjusted when they finish surfing

    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_MACH_BIKE && FollowerCanBike() && gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs != 1) //Coming out door
        SetFollowerSprite(FOLLOWER_SPRITE_INDEX_MACH_BIKE); // Mach Bike on
    else if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ACRO_BIKE && FollowerCanBike() && gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs != 1) //Coming out door
        SetFollowerSprite(FOLLOWER_SPRITE_INDEX_ACRO_BIKE); // Acro Bike on
    else
        SetFollowerSprite(FOLLOWER_SPRITE_INDEX_NORMAL);
}

void FollowMe_HandleSprite(void)
{
    if (gSaveBlock3Ptr->NPCfollower.flags & FOLLOW_ME_FLAG_CAN_BIKE)
    {
        if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_MACH_BIKE)
            SetFollowerSprite(FOLLOWER_SPRITE_INDEX_MACH_BIKE);
        else if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ACRO_BIKE)
            SetFollowerSprite(FOLLOWER_SPRITE_INDEX_ACRO_BIKE);
    }
    else if (gMapHeader.mapType == MAP_TYPE_UNDERWATER)
    {
        TryUpdateFollowerSpriteUnderwater();
    }
    else
    {
        SetFollowerSprite(FOLLOWER_SPRITE_INDEX_NORMAL);
    }
}

void SetFollowerSprite(u8 spriteIndex)
{
    u8 oldSpriteId;
    u8 newSpriteId;
    u16 newGraphicsId;
    struct ObjectEventTemplate clone;
    struct ObjectEvent backupFollower;
    struct ObjectEvent *follower;

    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    if (gSaveBlock3Ptr->NPCfollower.currentSprite == spriteIndex)
        return;

    // Save sprite
    follower = &gObjectEvents[GetFollowerMapObjId()];
    gSaveBlock3Ptr->NPCfollower.currentSprite = spriteIndex;
    oldSpriteId = follower->spriteId;
    newGraphicsId = GetFollowerSprite();

    // Reload the entire event object.
    // It would usually be enough just to change the sprite Id, but if the original
    // sprite and the new sprite have different palettes, the palette would need to
    // be reloaded.
    backupFollower = *follower;
    backupFollower.graphicsId = newGraphicsId;
    // backupFollower.graphicsIdUpperByte = newGraphicsId >> 8;
    DestroySprite(&gSprites[oldSpriteId]);
    RemoveObjectEvent(&gObjectEvents[GetFollowerMapObjId()]);

    clone = *GetObjectEventTemplateByLocalIdAndMap(gSaveBlock3Ptr->NPCfollower.map.id, gSaveBlock3Ptr->NPCfollower.map.number, gSaveBlock3Ptr->NPCfollower.map.group);
    clone.graphicsId = newGraphicsId;
    clone.movementType = 0; // Make sure new follower sprite can't move on its own
    clone.localId = OBJ_EVENT_ID_NPC_FOLLOWER;
    gSaveBlock3Ptr->NPCfollower.objId = TrySpawnObjectEventTemplate(&clone, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, clone.x, clone.y);
    if (gSaveBlock3Ptr->NPCfollower.objId != OBJECT_EVENTS_COUNT)
    {
        follower = &gObjectEvents[GetFollowerMapObjId()];
        newSpriteId = follower->spriteId;
        *follower = backupFollower;
        follower->spriteId = newSpriteId;
        MoveObjectEventToMapCoords(follower, follower->currentCoords.x, follower->currentCoords.y);
        ObjectEventTurn(follower, follower->facingDirection);
    }
    else
    {
        memset(&gSaveBlock3Ptr->NPCfollower, 0, sizeof(gSaveBlock3Ptr->NPCfollower));
    }
}
#endif

void FollowMe_WarpSetEnd(void)
{
#if OW_ENABLE_NPC_FOLLOWERS
    struct ObjectEvent *player;
    struct ObjectEvent *follower;
    u8 toY;

    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    player = &gObjectEvents[gPlayerAvatar.objectEventId];
    follower = &gObjectEvents[GetFollowerMapObjId()];

    gSaveBlock3Ptr->NPCfollower.warpEnd = 1;
    PlayerLogCoordinates(player);

    toY = gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs == 1 ? (player->currentCoords.y - 1) : player->currentCoords.y;
    MoveObjectEventToMapCoords(follower, player->currentCoords.x, toY);

    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ON_FOOT)
        SetFollowerSprite(FOLLOWER_SPRITE_INDEX_NORMAL);

    follower->facingDirection = player->facingDirection;
    follower->movementDirection = player->movementDirection;
#endif
}

#if OW_ENABLE_NPC_FOLLOWERS
void CreateFollowerAvatar(void)
{
    struct ObjectEvent* player;
    struct ObjectEventTemplate clone;

    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    player = &gObjectEvents[gPlayerAvatar.objectEventId];
    clone = *GetObjectEventTemplateByLocalIdAndMap(gSaveBlock3Ptr->NPCfollower.map.id, gSaveBlock3Ptr->NPCfollower.map.number, gSaveBlock3Ptr->NPCfollower.map.group);

    clone.graphicsId = GetFollowerSprite();
    clone.x = player->currentCoords.x - 7;
    clone.y = player->currentCoords.y - 7;
    clone.movementType = 0; // Doesn't get to move on its own
    clone.localId = OBJ_EVENT_ID_NPC_FOLLOWER;

    switch (GetPlayerFacingDirection())
    {
    case DIR_NORTH:
        clone.movementType = MOVEMENT_TYPE_FACE_UP;
        break;
    case DIR_WEST:
        clone.movementType = MOVEMENT_TYPE_FACE_LEFT;
        break;
    case DIR_EAST:
        clone.movementType = MOVEMENT_TYPE_FACE_RIGHT;
        break;
    }

    // Create NPC and store ID
    gSaveBlock3Ptr->NPCfollower.objId = TrySpawnObjectEventTemplate(&clone, gSaveBlock3Ptr->NPCfollower.map.number, gSaveBlock3Ptr->NPCfollower.map.group, clone.x, clone.y);
    if (gSaveBlock3Ptr->NPCfollower.objId == OBJECT_EVENTS_COUNT)
    {
        memset(&gSaveBlock3Ptr->NPCfollower, 0, sizeof(gSaveBlock3Ptr->NPCfollower));
    }

    if (gMapHeader.mapType == MAP_TYPE_UNDERWATER)
        gSaveBlock3Ptr->NPCfollower.createSurfBlob = 0;

    gObjectEvents[gSaveBlock3Ptr->NPCfollower.objId].invisible = TRUE;
}

static void TurnNPCIntoFollower(u8 localId, u16 followerFlags, u8 setScript, const u8 *ptr)
{
    struct ObjectEvent* follower;
    u8 eventObjId;
    const u8 *script;
    u16 flag;

    if (gSaveBlock3Ptr->NPCfollower.inProgress)
        return; // Only 1 NPC following at a time

    for (eventObjId = 0; eventObjId < OBJECT_EVENTS_COUNT; eventObjId++) // For each NPC on the map
    {
        if (!gObjectEvents[eventObjId].active || gObjectEvents[eventObjId].isPlayer)
            continue;

        if (gObjectEvents[eventObjId].localId == localId)
        {
            follower = &gObjectEvents[eventObjId];
            flag = GetObjectEventFlagIdByLocalIdAndMap(follower->localId, follower->mapNum, follower->mapGroup);
            if (flag == 0) // If the NPC does not have an event flag, don't create follower
                return;
            follower->movementType = MOVEMENT_TYPE_NONE; // Doesn't get to move on its own anymore
            gSprites[follower->spriteId].callback = MovementType_None; // MovementType_None
            SetObjEventTemplateMovementType(localId, 0);
            if (setScript == TRUE)
                script = ptr;
            else
                script = GetObjectEventScriptPointerByObjectEventId(eventObjId);

            gSaveBlock3Ptr->NPCfollower.inProgress = TRUE;
            gSaveBlock3Ptr->NPCfollower.objId = eventObjId;
            gSaveBlock3Ptr->NPCfollower.graphicsId = follower->graphicsId;
            gSaveBlock3Ptr->NPCfollower.map.id = gObjectEvents[eventObjId].localId;
            gSaveBlock3Ptr->NPCfollower.map.number = gSaveBlock1Ptr->location.mapNum;
            gSaveBlock3Ptr->NPCfollower.map.group = gSaveBlock1Ptr->location.mapGroup;
            gSaveBlock3Ptr->NPCfollower.script = script;
            gSaveBlock3Ptr->NPCfollower.flag = flag;
            gSaveBlock3Ptr->NPCfollower.flags = followerFlags;
            gSaveBlock3Ptr->NPCfollower.createSurfBlob = 0;
            gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs = 0;
            follower->localId = OBJ_EVENT_ID_NPC_FOLLOWER;
            FlagSet(flag);

            if (!(gSaveBlock3Ptr->NPCfollower.flags & FOLLOW_ME_FLAG_CAN_BIKE) // Follower can't bike
            &&  TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_BIKE)) // Player on bike
                SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT); // Dismmount Bike

            if (!TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_ON_FOOT))
                FollowMe_HandleSprite(); // Set the follower sprite to match the player state
        }
    }
}

bool8 CheckFollowerFlag(u16 flag)
{
    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return TRUE;

    if (gSaveBlock3Ptr->NPCfollower.flags & flag)
        return TRUE;

    return FALSE;
}

static u8 GetPlayerMapObjId(void)
{
	return gPlayerAvatar.objectEventId;
}

enum
{
	GoDown,
	GoUp,
	GoLeft,
	GoRight
};

void FollowerPositionFix(u8 offset)
{
    u8 playerObjId = GetPlayerMapObjId();
    u8 followerObjid = gSaveBlock3Ptr->NPCfollower.objId;
    u16 playerX = gObjectEvents[playerObjId].currentCoords.x;
    u16 playerY = gObjectEvents[playerObjId].currentCoords.y;
    u16 npcX = gObjectEvents[followerObjid].currentCoords.x;
    u16 npcY = gObjectEvents[followerObjid].currentCoords.y;

    gSpecialVar_Result = 0xFFFF;

    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    if (playerX == npcX)
    {
        if (playerY > npcY)
        {
            if (playerY != npcY + offset) //Player and follower are not 1 tile apart
            {
                if (gSpecialVar_0x8000 == 0)
                    gSpecialVar_Result = GoDown;
                else
                    gObjectEvents[followerObjid].currentCoords.y = playerY - offset;
            }
        }
        else // Player Y <= npcY
        {
            if (playerY != npcY - offset) //Player and follower are not 1 tile apart
            {
                if (gSpecialVar_0x8000 == 0)
                    gSpecialVar_Result = GoUp;
                else
                    gObjectEvents[followerObjid].currentCoords.y = playerY + offset;
            }
        }
    }
    else //playerY == npcY
    {
        if (playerX > npcX)
        {
            if (playerX != npcX + offset) //Player and follower are not 1 tile apart
            {
                if (gSpecialVar_0x8000 == 0)
                    gSpecialVar_Result = GoRight;
                else
                    gObjectEvents[followerObjid].currentCoords.x = playerX - offset;
            }
        }
        else // Player X <= npcX
        {
            if (playerX != npcX - offset) //Player and follower are not 1 tile apart
            {
                if (gSpecialVar_0x8000 == 0)
                    gSpecialVar_Result = GoLeft;
                else
                    gObjectEvents[followerObjid].currentCoords.x = playerX + offset;
            }
        }
    }
}
#endif

void FollowerTrainerSightingPositionFix(void)
{
#if OW_ENABLE_NPC_FOLLOWERS
    FollowerPositionFix(1);
#endif
}

void FollowerIntoPlayer(void)
{
#if OW_ENABLE_NPC_FOLLOWERS
    FollowerPositionFix(0);
#endif
}

bool8 PlayerHasFollower(void)
{
#if OW_ENABLE_NPC_FOLLOWERS
    return gSaveBlock3Ptr->NPCfollower.inProgress;
#else
    return FALSE;
#endif
}

bool8 IsPlayerOnFoot(void)
{
    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ON_FOOT)
        return TRUE;
    else
        return FALSE;
}

bool8 FollowerComingThroughDoor(void)
{
#if OW_ENABLE_NPC_FOLLOWERS
    if (!PlayerHasFollower())
        return FALSE;

    if (gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs)
        return TRUE;
#endif

    return FALSE;
}

// Follow Me script commands

void ScriptSetFollower(struct ScriptContext *ctx)
{
#if OW_ENABLE_NPC_FOLLOWERS
    u8 localId = ScriptReadByte(ctx);
    u16 flags = ScriptReadHalfword(ctx);
    u8 setScript = ScriptReadByte(ctx);
    u16 battlePartner = ScriptReadHalfword(ctx);
    const u8 *script = (const u8 *)ScriptReadWord(ctx);

    gSaveBlock3Ptr->NPCfollower.battlePartner = battlePartner;
    TurnNPCIntoFollower(localId, flags, setScript, script);
#endif
}

void ScriptDestroyFollower(struct ScriptContext *ctx)
{
#if OW_ENABLE_NPC_FOLLOWERS
    if (gSaveBlock3Ptr->NPCfollower.inProgress)
    {
        gSaveBlock3Ptr->NPCfollower.warpEnd = 0; // In case a follower warp had not yet finished.
        RemoveObjectEvent(&gObjectEvents[gSaveBlock3Ptr->NPCfollower.objId]);
        FlagSet(gSaveBlock3Ptr->NPCfollower.flag);
        memset(&gSaveBlock3Ptr->NPCfollower, 0, sizeof(gSaveBlock3Ptr->NPCfollower));
    }
    if (OW_FOLLOWERS_ENABLED == TRUE) {
        UpdateFollowingPokemon();
    }
#endif
}

void ScriptFaceFollower(struct ScriptContext *ctx)
{
#if OW_ENABLE_NPC_FOLLOWERS
    if (gSaveBlock3Ptr->NPCfollower.inProgress)
    {
        u8 playerDirection, followerDirection;
        struct ObjectEvent* player, *follower;

        player = &gObjectEvents[gPlayerAvatar.objectEventId];
        follower = &gObjectEvents[gSaveBlock3Ptr->NPCfollower.objId];
        playerDirection = DetermineFollowerDirection(player, follower);
        followerDirection = playerDirection;

        //Flip direction
        switch (playerDirection) 
        {
        case DIR_NORTH:
            playerDirection = DIR_SOUTH;
            followerDirection = DIR_NORTH;
            break;
        case DIR_SOUTH:
            playerDirection = DIR_NORTH;
            followerDirection = DIR_SOUTH;
            break;
        case DIR_WEST:
            playerDirection = DIR_EAST;
            followerDirection = DIR_WEST;
            break;
        case DIR_EAST:
            playerDirection = DIR_WEST;
            followerDirection = DIR_EAST;
            break;
        }

        ObjectEventTurn(player, playerDirection);
        ObjectEventTurn(follower, followerDirection);
    }
#endif
}

void ScriptCheckFollower(struct ScriptContext *ctx)
{
#if OW_ENABLE_NPC_FOLLOWERS
    gSpecialVar_Result = gSaveBlock3Ptr->NPCfollower.inProgress;
#endif
}

void ScriptUpdateFollowingMon(struct ScriptContext *ctx)
{
#if OW_ENABLE_NPC_FOLLOWERS
    if (OW_FOLLOWERS_ENABLED == TRUE) {
        UpdateFollowingPokemon();
    }
#endif
}

void ScriptChangeFollowerBattlePartner(struct ScriptContext *ctx)
{
#if OW_ENABLE_NPC_FOLLOWERS
    u16 newBattlePartner = ScriptReadHalfword(ctx);

    if (gSaveBlock3Ptr->NPCfollower.inProgress)
        gSaveBlock3Ptr->NPCfollower.battlePartner = newBattlePartner;
#endif
}
