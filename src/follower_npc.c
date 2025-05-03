#include "global.h"
#include "follower_npc.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_door.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "field_control_avatar.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "fldeff_misc.h"
#include "frontier_util.h"
#include "item.h"
#include "load_save.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "party_menu.h"
#include "script.h"
#include "script_movement.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "task.h"
#include "trig.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/frontier_util.h"
#include "constants/map_types.h"
#include "constants/metatile_behaviors.h"
#include "constants/songs.h"

/*
Known Issues:
    -follower gets messed up if you go into a map with a maximum number of event objects
        -inherits incorrect palette, may get directionally confused

    -follower animation can get messed up when sideways hopping with Acro Bike
*/

#if OW_ENABLE_NPC_FOLLOWERS

struct FollowerNPCSpriteGraphics
{
    u16 normalId;
    u16 machBikeId;
    u16 acroBikeId;
    u16 surfId;
    u16 underwaterId;
};

// Function Declarations
static u16 GetFollowerNPCSprite(void);
static void TryUpdateFollowerNPCSpriteUnderwater(void);
static void Task_ReallowPlayerMovement(u8 taskId);
static void PlayerLogCoordinates(struct ObjectEvent *player);
static bool8 IsStateMovement(u8 state);
static u8 ReturnFollowerNPCDelayedState(u8 direction);
static void SetSurfJump(void);
static void Task_BindSurfBlobToFollowerNPC(u8 taskId);
static void SetUpSurfBlobFieldEffect(struct ObjectEvent *npc);
static void SetSurfDismount(void);
static void Task_FinishSurfDismount(u8 taskId);
void SetFollowerNPCSurfSpriteAfterDive(void);
static void Task_FollowerNPCOutOfDoor(u8 taskId);
static void Task_FollowerNPCHandleEscalator(u8 taskId);
static void Task_FollowerNPCHandleEscalatorFinish(u8 taskId);
static void CalculateFollowerNPCEscalatorTrajectoryUp(struct Task *task);
static void CalculateFollowerNPCEscalatorTrajectoryDown(struct Task *task);
static void TurnNPCIntoFollower(u8 localId, u16 followerFlags, u8 setScript, const u8 *script);

static const struct FollowerNPCSpriteGraphics gFollowerNPCAlternateSprites[] =
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

u8 GetFollowerNPCObjectId(void)
{
    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return OBJECT_EVENTS_COUNT;

    return gSaveBlock3Ptr->NPCfollower.objId;
}

u8 GetFollowerNPCLocalId(void)
{
    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return 0;

    return gObjectEvents[gSaveBlock3Ptr->NPCfollower.objId].localId;
}

const u8 *GetFollowerNPCScriptPointer(void)
{
    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return NULL;

    return gSaveBlock3Ptr->NPCfollower.script;
}
#endif

void HideNPCFollower(void)
{
#if OW_ENABLE_NPC_FOLLOWERS
    if (!gSaveBlock3Ptr->NPCfollower.inProgress || gObjectEvents[GetFollowerNPCMapObjId()].invisible)
        return;

    if (gSaveBlock3Ptr->NPCfollower.createSurfBlob == FNPC_SURF_BLOB_RECREATE || gSaveBlock3Ptr->NPCfollower.createSurfBlob == FNPC_SURF_BLOB_DESTROY)
    {
        SetSurfBlob_BobState(gObjectEvents[GetFollowerNPCMapObjId()].fieldEffectSpriteId, 2);
        DestroySprite(&gSprites[gObjectEvents[GetFollowerNPCMapObjId()].fieldEffectSpriteId]);
        gObjectEvents[GetFollowerNPCMapObjId()].fieldEffectSpriteId = 0; // Unbind
    }

    gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs = FNPC_DOOR_NONE;

    gObjectEvents[GetFollowerNPCMapObjId()].invisible = TRUE;
#endif
}

#if OW_ENABLE_NPC_FOLLOWERS
void FollowerNPC_SetIndicatorToComeOutDoor(void)
{
    if (gSaveBlock3Ptr->NPCfollower.inProgress)
        gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs = FNPC_DOOR_NEEDS_TO_EXIT;
}

void FollowerNPC_SetIndicatorToRecreateSurfBlob(void)
{
    if (gSaveBlock3Ptr->NPCfollower.inProgress)
        gSaveBlock3Ptr->NPCfollower.createSurfBlob = FNPC_SURF_BLOB_RECREATE;
}

void FollowerNPC_TryRemoveFollowerOnWhiteOut(void)
{
    if (gSaveBlock3Ptr->NPCfollower.inProgress)
    {
        if (gSaveBlock3Ptr->NPCfollower.flags & FOLLOWER_NPC_FLAG_CLEAR_ON_WHITE_OUT)
        {
            memset(&gSaveBlock3Ptr->NPCfollower, 0, sizeof(gSaveBlock3Ptr->NPCfollower));
        }
        else
            FollowerNPC_WarpSetEnd();
    }
}

u8 GetFollowerNPCMapObjId(void)
{
    return gSaveBlock3Ptr->NPCfollower.objId;
}

static u16 GetFollowerNPCSprite(void)
{
    u32 i;

    switch (gSaveBlock3Ptr->NPCfollower.currentSprite)
    {
    case FOLLOWER_NPC_SPRITE_INDEX_MACH_BIKE:
        for (i = 0; i < NELEMS(gFollowerNPCAlternateSprites); i++)
        {
            if (gFollowerNPCAlternateSprites[i].normalId == gSaveBlock3Ptr->NPCfollower.graphicsId)
                return gFollowerNPCAlternateSprites[i].machBikeId;
        }
        break;
    case FOLLOWER_NPC_SPRITE_INDEX_ACRO_BIKE:
        for (i = 0; i < NELEMS(gFollowerNPCAlternateSprites); i++)
        {
            if (gFollowerNPCAlternateSprites[i].normalId == gSaveBlock3Ptr->NPCfollower.graphicsId)
                return gFollowerNPCAlternateSprites[i].acroBikeId;
        }
        break;
    case FOLLOWER_NPC_SPRITE_INDEX_SURF:
        for (i = 0; i < NELEMS(gFollowerNPCAlternateSprites); i++)
        {
            if (gFollowerNPCAlternateSprites[i].normalId == gSaveBlock3Ptr->NPCfollower.graphicsId)
                return gFollowerNPCAlternateSprites[i].surfId;
        }
        break;
    case FOLLOWER_NPC_SPRITE_INDEX_UNDERWATER:
        for (i = 0; i < NELEMS(gFollowerNPCAlternateSprites); i++)
        {
            if (gFollowerNPCAlternateSprites[i].normalId == gSaveBlock3Ptr->NPCfollower.graphicsId)
                return gFollowerNPCAlternateSprites[i].underwaterId;
        }
        break;
    }

    return gSaveBlock3Ptr->NPCfollower.graphicsId;
}

static void TryUpdateFollowerNPCSpriteUnderwater(void)
{
    if (gMapHeader.mapType == MAP_TYPE_UNDERWATER)
    {
        struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCMapObjId()];
        SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_UNDERWATER);

        follower = &gObjectEvents[GetFollowerNPCMapObjId()]; // Can change on reload sprite
        follower->fieldEffectSpriteId = StartUnderwaterSurfBlobBobbing(follower->spriteId);
    }
}

// Task data
#define tState          data[0]
#define tDoorX          data[2]
#define tDoorY          data[3]

void NPCFollow(struct ObjectEvent *npc, u8 state, bool8 ignoreScriptActive)
{
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCMapObjId()];
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
    if ((gSaveBlock3Ptr->NPCfollower.currentSprite == FOLLOWER_NPC_SPRITE_INDEX_SURF) && !(gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING) && follower->fieldEffectSpriteId == 0)
    {
        SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_NORMAL);
        gSaveBlock3Ptr->NPCfollower.createSurfBlob = FNPC_SURF_BLOB_NONE;
    }

    // Check if state would cause hidden follower to reappear
    if (IsStateMovement(state) && gSaveBlock3Ptr->NPCfollower.warpEnd)
    {
        gSaveBlock3Ptr->NPCfollower.warpEnd = FNPC_WARP_NONE;

        if (gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs == FNPC_DOOR_NEEDS_TO_EXIT)
        {
            gPlayerAvatar.preventStep = TRUE;
            taskId = CreateTask(Task_FollowerNPCOutOfDoor, 1);
            gTasks[taskId].tState = 0;
            gTasks[taskId].tDoorX = follower->currentCoords.x;
            gTasks[taskId].tDoorY = follower->currentCoords.y;
            TryUpdateFollowerNPCSpriteUnderwater();
            ObjectEventClearHeldMovementIfFinished(follower);
            return;
        }

        follower->invisible = FALSE;
        MoveObjectEventToMapCoords(follower, player->currentCoords.x, player->currentCoords.y);
        ObjectEventTurn(follower, player->facingDirection); // The follower should be facing the same direction as the player when it comes out of hiding

        if (gSaveBlock3Ptr->NPCfollower.createSurfBlob == FNPC_SURF_BLOB_RECREATE) // Recreate surf blob
        {
            SetUpSurfBlobFieldEffect(follower);
            follower->fieldEffectSpriteId = FieldEffectStart(FLDEFF_SURF_BLOB);
            SetSurfBlob_BobState(follower->fieldEffectSpriteId, 1);
        }
        else
        {
            TryUpdateFollowerNPCSpriteUnderwater();
        }
    }

    dir = DetermineFollowerNPCDirection(player, follower);

    if (dir == DIR_NONE)
    {
        ObjectEventClearHeldMovementIfFinished(follower);
        return;
    }

    newState = DetermineFollowerNPCState(follower, state, dir);
    if (newState == MOVEMENT_INVALID)
    {
        ObjectEventClearHeldMovementIfFinished(follower);
        return;
    }

    if (gSaveBlock3Ptr->NPCfollower.createSurfBlob == FNPC_SURF_BLOB_NEW && IsStateMovement(state)) // Get on Surf Blob
    {
        gSaveBlock3Ptr->NPCfollower.createSurfBlob = FNPC_SURF_BLOB_RECREATE;
        gPlayerAvatar.preventStep = TRUE; // Wait for finish
        SetSurfJump();
        ObjectEventClearHeldMovementIfFinished(follower);
        return;
    }
    else if (gSaveBlock3Ptr->NPCfollower.createSurfBlob == FNPC_SURF_BLOB_DESTROY) // Get off Surf Blob
    {
        gSaveBlock3Ptr->NPCfollower.createSurfBlob = FNPC_SURF_BLOB_NONE;
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
    case MOVEMENT_ACTION_JUMP_DOWN ... MOVEMENT_ACTION_JUMP_RIGHT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_RIGHT:
        CreateTask(Task_ReallowPlayerMovement, 1); // Synchronize movements on stairs and ledges
        gPlayerAvatar.preventStep = TRUE;   // allow follower to catch up
    }

    ObjectEventClearHeldMovementIfFinished(follower);
}

#undef tState
#undef tDoorX
#undef tDoorY

static void Task_ReallowPlayerMovement(u8 taskId)
{
    bool8 animStatus = ObjectEventClearHeldMovementIfFinished(&gObjectEvents[GetFollowerNPCMapObjId()]);
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

u8 DetermineFollowerNPCDirection(struct ObjectEvent *player, struct ObjectEvent *follower)
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

static void PlayerLogCoordinates(struct ObjectEvent *player)
{
    gSaveBlock3Ptr->NPCfollower.log.x = player->currentCoords.x;
    gSaveBlock3Ptr->NPCfollower.log.y = player->currentCoords.y;
}

#define RETURN_STATE(state, dir) return newState == MOVEMENT_INVALID ? state + (dir - 1) : ReturnFollowerNPCDelayedState(dir - 1);
u8 DetermineFollowerNPCState(struct ObjectEvent *follower, u8 state, u8 direction)
{
    u8 newState = MOVEMENT_INVALID;
    u8 noSpecialAnimFrames = (GetFollowerNPCSprite() == gSaveBlock3Ptr->NPCfollower.graphicsId);
#if SIDEWAYS_STAIRS_IMPLEMENTED
        u8 collision = COLLISION_NONE;
        s16 followerX = follower->currentCoords.x;
        s16 followerY = follower->currentCoords.y;
        u8 currentBehavior = MapGridGetMetatileBehaviorAt(followerX, followerY);
        u8 nextBehavior;

        MoveCoords(direction, &followerX, &followerY);
        nextBehavior = MapGridGetMetatileBehaviorAt(followerX, followerY);
#endif
    
    if (FindTaskIdByFunc(Task_MoveNPCFollowerAfterForcedMovement) == TASK_NONE)
        follower->facingDirectionLocked = FALSE;

    // Follower won't do delayed movement until player does a movement.
    if (!IsStateMovement(state) && gSaveBlock3Ptr->NPCfollower.delayedState)
        return MOVEMENT_ACTION_NONE;

    if (IsStateMovement(state) && gSaveBlock3Ptr->NPCfollower.delayedState)
    {
        // Lock face direction for Acro side jump.
        if (gSaveBlock3Ptr->NPCfollower.delayedState == MOVEMENT_ACTION_JUMP_DOWN && TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_ACRO_BIKE))
            follower->facingDirectionLocked = TRUE;
        newState = gSaveBlock3Ptr->NPCfollower.delayedState + (direction -1);
    }    

    // Clear ice tile stuff
    follower->disableAnim = FALSE;

#if SIDEWAYS_STAIRS_IMPLEMENTED
        // Clear overwrite movement
        follower->directionOverwrite = DIR_NONE;

        // Sideways stairs checks
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
#endif

    switch (state) 
    {
    case MOVEMENT_ACTION_WALK_SLOW_DOWN ... MOVEMENT_ACTION_WALK_SLOW_RIGHT:
        // Slow walk
        RETURN_STATE(MOVEMENT_ACTION_WALK_SLOW_DOWN, direction);

    case MOVEMENT_ACTION_WALK_NORMAL_DOWN ... MOVEMENT_ACTION_WALK_NORMAL_RIGHT:
        // Normal walk
        RETURN_STATE(MOVEMENT_ACTION_WALK_NORMAL_DOWN, direction);

    case MOVEMENT_ACTION_JUMP_2_DOWN ... MOVEMENT_ACTION_JUMP_2_RIGHT:
        // Ledge jump
        if (gSaveBlock3Ptr->NPCfollower.delayedState == MOVEMENT_ACTION_JUMP_2_DOWN) // Previously jumped
            return (MOVEMENT_ACTION_JUMP_2_DOWN + (direction - 1)); // Jump right away

        if (gSaveBlock3Ptr->NPCfollower.delayedState == MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN) // Jumped again.
            return (MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN + (direction - 1));

        gSaveBlock3Ptr->NPCfollower.delayedState = MOVEMENT_ACTION_JUMP_2_DOWN;
        RETURN_STATE(MOVEMENT_ACTION_WALK_NORMAL_DOWN, direction);

    case MOVEMENT_ACTION_WALK_FAST_DOWN ... MOVEMENT_ACTION_WALK_FAST_RIGHT:
        // Handle player on waterfall
        if (PlayerIsUnderWaterfall(&gObjectEvents[gPlayerAvatar.objectEventId]) && (state == MOVEMENT_ACTION_WALK_FAST_UP))
            return MOVEMENT_INVALID;

        // Handle ice tile (some walking animation) -  Set a bit to freeze the follower's animation
        if (MetatileBehavior_IsIce(follower->currentMetatileBehavior) || MetatileBehavior_IsTrickHouseSlipperyFloor(follower->currentMetatileBehavior))
            follower->disableAnim = TRUE;
            
        // Handle surfing
        if (gSaveBlock3Ptr->NPCfollower.currentSprite == FOLLOWER_NPC_SPRITE_INDEX_SURF && GetFollowerNPCSprite() == gSaveBlock3Ptr->NPCfollower.graphicsId)
            RETURN_STATE(MOVEMENT_ACTION_SURF_STILL_DOWN, direction);

        RETURN_STATE(MOVEMENT_ACTION_WALK_FAST_DOWN, direction);

    case MOVEMENT_ACTION_WALK_FASTER_DOWN ... MOVEMENT_ACTION_WALK_FASTER_RIGHT:
        if (MetatileBehavior_IsIce(follower->currentMetatileBehavior) || MetatileBehavior_IsTrickHouseSlipperyFloor(follower->currentMetatileBehavior))
            follower->disableAnim = TRUE;

        RETURN_STATE(MOVEMENT_ACTION_WALK_FASTER_DOWN, direction);

    case MOVEMENT_ACTION_RIDE_WATER_CURRENT_DOWN ... MOVEMENT_ACTION_RIDE_WATER_CURRENT_RIGHT:
        // Handle player on waterfall
        if (PlayerIsUnderWaterfall(&gObjectEvents[gPlayerAvatar.objectEventId]) && IsPlayerSurfingNorth())
            return MOVEMENT_INVALID;

        RETURN_STATE(MOVEMENT_ACTION_RIDE_WATER_CURRENT_DOWN, direction);  //Regular movement

    // Acro bike
    case MOVEMENT_ACTION_ACRO_WHEELIE_FACE_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_FACE_RIGHT:
        if (noSpecialAnimFrames)
            return MOVEMENT_ACTION_NONE;

        RETURN_STATE(MOVEMENT_ACTION_ACRO_WHEELIE_FACE_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_DOWN ... MOVEMENT_ACTION_ACRO_POP_WHEELIE_RIGHT:
        if (noSpecialAnimFrames)
            return MOVEMENT_ACTION_NONE;
            
        RETURN_STATE(MOVEMENT_ACTION_ACRO_POP_WHEELIE_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_DOWN ... MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_RIGHT:
        if (noSpecialAnimFrames)
            return MOVEMENT_ACTION_NONE;
            
        RETURN_STATE(MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_RIGHT:
        if (noSpecialAnimFrames)
            return MOVEMENT_ACTION_NONE;
            
        RETURN_STATE(MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_HOP_RIGHT:
        if (noSpecialAnimFrames)
            RETURN_STATE(MOVEMENT_ACTION_JUMP_DOWN, direction);
            
        RETURN_STATE(MOVEMENT_ACTION_ACRO_WHEELIE_HOP_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_RIGHT:
        // Ledge jump
        if (noSpecialAnimFrames)
        {
            if (gSaveBlock3Ptr->NPCfollower.delayedState == MOVEMENT_ACTION_JUMP_2_DOWN) // Jumped again.
                return (MOVEMENT_ACTION_JUMP_2_DOWN + (direction - 1));

            gSaveBlock3Ptr->NPCfollower.delayedState = MOVEMENT_ACTION_JUMP_2_DOWN;
        }
        else
        {
            if (gSaveBlock3Ptr->NPCfollower.delayedState == MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN) // Jumped again.
                return (MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN + (direction - 1));

            if (gSaveBlock3Ptr->NPCfollower.delayedState == MOVEMENT_ACTION_JUMP_2_DOWN)
                return (MOVEMENT_ACTION_JUMP_2_DOWN + (direction - 1));

            gSaveBlock3Ptr->NPCfollower.delayedState = MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN;
        }

        RETURN_STATE(MOVEMENT_ACTION_WALK_FAST_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_RIGHT:
        if (noSpecialAnimFrames)
            return MOVEMENT_ACTION_NONE;
            
        RETURN_STATE(MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_DOWN ... MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_RIGHT:
        if (noSpecialAnimFrames)
            RETURN_STATE(MOVEMENT_ACTION_WALK_FAST_DOWN, direction);
            
        RETURN_STATE(MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_DOWN ... MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_RIGHT:
        if (noSpecialAnimFrames)
            RETURN_STATE(MOVEMENT_ACTION_WALK_FAST_DOWN, direction);

        RETURN_STATE(MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_DOWN, direction);
    case MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_DOWN ... MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_RIGHT:
        if (noSpecialAnimFrames)
            RETURN_STATE(MOVEMENT_ACTION_WALK_FAST_DOWN, direction);
            
        RETURN_STATE(MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_DOWN, direction);

    // Sliding
    case MOVEMENT_ACTION_SLIDE_DOWN ... MOVEMENT_ACTION_SLIDE_RIGHT:
        RETURN_STATE(MOVEMENT_ACTION_SLIDE_DOWN, direction);
    case MOVEMENT_ACTION_PLAYER_RUN_DOWN ... MOVEMENT_ACTION_PLAYER_RUN_RIGHT:
        // Running frames
        if (gSaveBlock3Ptr->NPCfollower.flags & FOLLOWER_NPC_FLAG_HAS_RUNNING_FRAMES)
            RETURN_STATE(MOVEMENT_ACTION_PLAYER_RUN_DOWN, direction);

        RETURN_STATE(MOVEMENT_ACTION_WALK_FAST_DOWN, direction);

    case MOVEMENT_ACTION_JUMP_SPECIAL_DOWN ... MOVEMENT_ACTION_JUMP_SPECIAL_RIGHT:
        gSaveBlock3Ptr->NPCfollower.delayedState = MOVEMENT_ACTION_JUMP_SPECIAL_DOWN;
        RETURN_STATE(MOVEMENT_ACTION_WALK_NORMAL_DOWN, direction);
    case MOVEMENT_ACTION_JUMP_DOWN ... MOVEMENT_ACTION_JUMP_RIGHT:
        // Acro side hop
        if (gSaveBlock3Ptr->NPCfollower.delayedState == MOVEMENT_ACTION_JUMP_DOWN)
        {
            if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_ACRO_BIKE))
                follower->facingDirectionLocked = TRUE;
            return newState;
        }
        else
        {
            gSaveBlock3Ptr->NPCfollower.delayedState = MOVEMENT_ACTION_JUMP_DOWN;
            RETURN_STATE(MOVEMENT_ACTION_WALK_NORMAL_DOWN, direction);
        }

    // Run slow
    #ifdef MOVEMENT_ACTION_RUN_DOWN_SLOW
    case MOVEMENT_ACTION_RUN_DOWN_SLOW ... MOVEMENT_ACTION_RUN_RIGHT_SLOW:
        if (gSaveBlock3Ptr->NPCfollower.flags & FOLLOWER_NPC_FLAG_HAS_RUNNING_FRAMES)
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
    case MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_DOWN:
    case MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_UP:
    case MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_LEFT:
    case MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_RIGHT:
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
    case MOVEMENT_ACTION_ACRO_WHEELIE_FACE_DOWN:
    case MOVEMENT_ACTION_ACRO_WHEELIE_FACE_UP:
    case MOVEMENT_ACTION_ACRO_WHEELIE_FACE_RIGHT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_FACE_LEFT:
    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_DOWN:
    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_UP:
    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_RIGHT:
    case MOVEMENT_ACTION_ACRO_POP_WHEELIE_LEFT:
    case MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_DOWN:
    case MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_UP:
    case MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_RIGHT:
    case MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_LEFT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_DOWN:
    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_UP:
    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_RIGHT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_LEFT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_DOWN:
    case MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_UP:
    case MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_RIGHT:
    case MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_LEFT:
        return FALSE;
    }

    return TRUE;
}

static u8 ReturnFollowerNPCDelayedState(u8 direction)
{
    u8 newState = gSaveBlock3Ptr->NPCfollower.delayedState;
    gSaveBlock3Ptr->NPCfollower.delayedState = 0;

    return newState + direction;
}

bool8 FollowerNPC_IsCollisionExempt(struct ObjectEvent *obstacle, struct ObjectEvent *collider)
{
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCMapObjId()];
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return FALSE;

    if (obstacle == follower && collider == player)
        return TRUE;

    return FALSE;
}

// Task data
#define tState                  data[0]
#define PREVENT_PLAYER_STEP     0
#define DO_ALL_FORCED_MOVEMENTS 1
#define NPC_INTO_PLAYER         2
#define ENABLE_PLAYER_STEP      3

void Task_MoveNPCFollowerAfterForcedMovement(u8 taskId)
{
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCMapObjId()];
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];

    // Prevent player input until all forced mmovements are done and the follower is hidden.
    if (gTasks[taskId].tState == PREVENT_PLAYER_STEP)
    {
        gPlayerAvatar.preventStep = TRUE;
        gTasks[taskId].tState = DO_ALL_FORCED_MOVEMENTS;
    }
    // The player will keep doing forced movments until they land on a non-forced-move metatile or hit collision.
    else if (gTasks[taskId].tState == DO_ALL_FORCED_MOVEMENTS && ObjectEventClearHeldMovementIfFinished(player) != 0)
    {
        // Lock follower facing direction for muddy slope.
        if (follower->currentMetatileBehavior == MB_MUDDY_SLOPE)
            follower->facingDirectionLocked = TRUE;
            
        if (TryDoMetatileBehaviorForcedMovement() == 0)
            gTasks[taskId].tState = NPC_INTO_PLAYER;
        return;
    }
    // The NPC will take an extra step and be on the same tile as the player.
    else if (gTasks[taskId].tState == NPC_INTO_PLAYER && ObjectEventClearHeldMovementIfFinished(player) != 0 && ObjectEventClearHeldMovementIfFinished(follower) != 0)
    {
        ObjectEventSetHeldMovement(follower, GetWalkFastMovementAction(DetermineFollowerNPCDirection(player, follower)));
        gTasks[taskId].tState = ENABLE_PLAYER_STEP;
        return;
    }
    // Hide the NPC until the player takes a step. Reallow player input.
    else if (gTasks[taskId].tState == ENABLE_PLAYER_STEP && ObjectEventClearHeldMovementIfFinished(follower) != 0)
    {
        follower->facingDirectionLocked = FALSE;
        HideNPCFollower();
        gSaveBlock3Ptr->NPCfollower.warpEnd = FNPC_WARP_REAPPEAR;
        gPlayerAvatar.preventStep = FALSE;
        DestroyTask(taskId);
    }
}

#undef PREVENT_PLAYER_STEP
#undef DO_ALL_FORCED_MOVEMENTS
#undef NPC_INTO_PLAYER
#undef ENABLE_PLAYER_STEP

void FollowerNPC_FollowerToWater(void)
{
    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    // Prepare for making the follower do the jump and spawn the surf head
    // right in front of the follower's location.
    NPCFollow(&gObjectEvents[gPlayerAvatar.objectEventId], MOVEMENT_ACTION_JUMP_DOWN, TRUE);
    gSaveBlock3Ptr->NPCfollower.createSurfBlob = FNPC_SURF_BLOB_NEW;
}

void FollowerNPC_BindToSurfBlobOnReloadScreen(void)
{
    struct ObjectEvent *follower;

    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    follower = &gObjectEvents[GetFollowerNPCMapObjId()];
    TryUpdateFollowerNPCSpriteUnderwater();

    if (gSaveBlock3Ptr->NPCfollower.createSurfBlob != FNPC_SURF_BLOB_RECREATE && gSaveBlock3Ptr->NPCfollower.createSurfBlob != FNPC_SURF_BLOB_DESTROY)
        return;

    // Spawn surfhead under follower
    SetUpSurfBlobFieldEffect(follower);
    follower->fieldEffectSpriteId = FieldEffectStart(FLDEFF_SURF_BLOB);
    SetSurfBlob_BobState(follower->fieldEffectSpriteId, 1);
}

static void SetSurfJump(void)
{
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCMapObjId()];
    u8 direction;
    u8 jumpState;

    // Reset NPC movement bits
    ObjectEventClearHeldMovement(follower);

    // Jump animation according to direction
    direction = DetermineFollowerNPCDirection(&gObjectEvents[gPlayerAvatar.objectEventId], follower);
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
    CreateTask(Task_BindSurfBlobToFollowerNPC, 0x1);
    SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_SURF);

    follower = &gObjectEvents[GetFollowerNPCMapObjId()];
    ObjectEventSetHeldMovement(follower, jumpState);
}

static void Task_BindSurfBlobToFollowerNPC(u8 taskId)
{
    struct ObjectEvent *npc = &gObjectEvents[GetFollowerNPCMapObjId()];
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

static void SetUpSurfBlobFieldEffect(struct ObjectEvent *npc)
{
    // Set up gFieldEffectArguments for execution
    gFieldEffectArguments[0] = npc->currentCoords.x;                 // effect_x
    gFieldEffectArguments[1] = npc->currentCoords.y;                 // effect_y
    gFieldEffectArguments[2] = gSaveBlock3Ptr->NPCfollower.objId;    // objId
}

void PrepareFollowerNPCDismountSurf(void)
{
    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    NPCFollow(&gObjectEvents[gPlayerAvatar.objectEventId], MOVEMENT_ACTION_WALK_NORMAL_DOWN, TRUE);
    gSaveBlock3Ptr->NPCfollower.createSurfBlob = FNPC_SURF_BLOB_DESTROY;
}

#define tSpriteId       data[0]

static void SetSurfDismount(void)
{
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCMapObjId()];
    u8 direction;
    u8 jumpState;
    u8 task;

    ObjectEventClearHeldMovement(follower);

    // Jump animation according to direction
    direction = DetermineFollowerNPCDirection(&gObjectEvents[gPlayerAvatar.objectEventId], follower);
    jumpState = GetJumpMovementAction(direction);

    // Unbind and destroy Surf Blob
    task = CreateTask(Task_FinishSurfDismount, 1);
    gTasks[task].tSpriteId = follower->fieldEffectSpriteId;
    SetSurfBlob_BobState(follower->fieldEffectSpriteId, 2);
    follower->fieldEffectSpriteId = 0; // Unbind
    FollowerNPC_HandleSprite();

    follower = &gObjectEvents[GetFollowerNPCMapObjId()]; // Can change after sprite reload
    ObjectEventSetHeldMovement(follower, jumpState);
}

static void Task_FinishSurfDismount(u8 taskId)
{
    struct ObjectEvent *npc = &gObjectEvents[GetFollowerNPCMapObjId()];
    bool8 animStatus = ObjectEventClearHeldMovementIfFinished(npc); // Wait animation

    if (animStatus == 0)
    {
        if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_DASH) && ObjectEventClearHeldMovementIfFinished(&gObjectEvents[gPlayerAvatar.objectEventId]))
            SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT); // Temporarily stop running

        return;
    }

    SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_NORMAL);
    DestroySprite(&gSprites[gTasks[taskId].tSpriteId]);
    UnfreezeObjectEvents();
    DestroyTask(taskId);
    gPlayerAvatar.preventStep = FALSE;
}

#undef tSpriteId
#endif

void SetFollowerNPCSurfSpriteAfterDive(void)
{
#if OW_ENABLE_NPC_FOLLOWERS
    SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_SURF);
    gSaveBlock3Ptr->NPCfollower.createSurfBlob = FNPC_SURF_BLOB_RECREATE;
#endif
}

#if OW_ENABLE_NPC_FOLLOWERS
static u8 GetPlayerFaceToDoorDirection(struct ObjectEvent *player, struct ObjectEvent *follower)
{
    s16 delta_x = player->currentCoords.x - follower->currentCoords.x;

    if (delta_x < 0)
        return DIR_EAST;
    else if (delta_x > 0)
        return DIR_WEST;

    return DIR_NORTH;
}

// Task data
#define tDoorTask           data[1]
#define tDoorX              data[2]
#define tDoorY              data[3]

enum {
    OPEN_DOOR,
    NPC_WALK_OUT,
    CLOSE_DOOR,
    UNFREEZE_OBJECTS,
    REALLOW_MOVEMENT
};

static void Task_FollowerNPCOutOfDoor(u8 taskId)
{
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCMapObjId()];
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Task *task = &gTasks[taskId];
    s16 *x = &task->tDoorX;
    s16 *y = &task->tDoorY;

    if (OW_FACE_NPC_FOLLOWER_ON_DOOR_EXIT == TRUE && ObjectEventClearHeldMovementIfFinished(player)) {
        ObjectEventTurn(player, GetPlayerFaceToDoorDirection(player, follower)); // The player should face towards the follower as they exit the door.
    }

    switch (task->tState)
    {
    case OPEN_DOOR:
        FreezeObjectEvents();
        task->tDoorTask = FieldAnimateDoorOpen(follower->currentCoords.x, follower->currentCoords.y);
        if (task->tDoorTask != -1)
            PlaySE(GetDoorSoundEffect(*x, *y)); // only play SE for animating doors

        task->tState = NPC_WALK_OUT;
        break;
    case NPC_WALK_OUT:
        if (task->tDoorTask < 0 || gTasks[task->tDoorTask].isActive != TRUE) // if Door isn't still opening
        {
            follower->invisible = FALSE;
            if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING)) // In case came out door while surfing.
            {
                SetUpSurfBlobFieldEffect(follower);
                follower->fieldEffectSpriteId = FieldEffectStart(FLDEFF_SURF_BLOB);
                SetSurfBlob_BobState(follower->fieldEffectSpriteId, 1);
            }
            ObjectEventTurn(follower, DIR_SOUTH); // The follower should be facing down when it comes out the door.
            follower->singleMovementActive = FALSE;
            follower->heldMovementActive = FALSE;
            ObjectEventSetHeldMovement(follower, MOVEMENT_ACTION_WALK_NORMAL_DOWN); // follower step down
            task->tState = CLOSE_DOOR;
        }
        break;
    case CLOSE_DOOR:
        if (ObjectEventClearHeldMovementIfFinished(follower))
        {
            task->tDoorTask = FieldAnimateDoorClose(*x, *y);
            task->tState = UNFREEZE_OBJECTS;
        }
        break;
    case UNFREEZE_OBJECTS:
        if (task->tDoorTask < 0 || gTasks[task->tDoorTask].isActive != TRUE) // Door is closed
        {
            UnfreezeObjectEvents();
            task->tState = REALLOW_MOVEMENT;
        }
        break;
    case REALLOW_MOVEMENT:
        FollowerNPC_HandleSprite();
        gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs = FNPC_DOOR_NONE;
        gPlayerAvatar.preventStep = FALSE; // Player can move again
        DestroyTask(taskId);
        break;
    }
}
#undef tDoorTask
#undef tDoorX
#undef tDoorY

void EscalatorMoveFollowerNPC(u8 movementType)
{
    u8 taskId;

    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    taskId = CreateTask(Task_FollowerNPCHandleEscalator, 1);
    gTasks[taskId].data[1] = movementType;
}

static void Task_FollowerNPCHandleEscalator(u8 taskId)
{
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCMapObjId()];
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];

    ObjectEventClearHeldMovementIfActive(follower);
    ObjectEventSetHeldMovement(follower, DetermineFollowerNPCState(follower, MOVEMENT_ACTION_WALK_NORMAL_DOWN, DetermineFollowerNPCDirection(player, follower)));
    DestroyTask(taskId);
}

void EscalatorMoveFollowerNPCFinish(void)
{
    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    CreateTask(Task_FollowerNPCHandleEscalatorFinish, 1);
}

#define tCounter                data[1]
#define tMetatileBehavior       data[2]
#define tTimer                  data[7]

enum {
    MOVE_TO_PLAYER_POS,
    WAIT_FOR_PLAYER_MOVE,
    SHOW_FOLLOWER_DOWN,
    MOVE_FOLLOWER_DOWN,
    SHOW_FOLLOWER_UP,
    MOVE_FOLLOWER_UP,
    MOVEMENT_FINISH
};

static void Task_FollowerNPCHandleEscalatorFinish(u8 taskId)
{
    s16 x, y;
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCMapObjId()];
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *sprite = &gSprites[follower->spriteId];
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case MOVE_TO_PLAYER_POS:
        MoveObjectEventToMapCoords(follower, player->currentCoords.x, player->currentCoords.y);
        PlayerGetDestCoords(&x, &y);
        task->tMetatileBehavior = MapGridGetMetatileBehaviorAt(x, y);
        task->tTimer = 0;
        task->tState = WAIT_FOR_PLAYER_MOVE;
        break;
    case WAIT_FOR_PLAYER_MOVE:
        if (task->tTimer++ < 32) // Wait half a second before revealing the follower
            break;

        task->tState = SHOW_FOLLOWER_DOWN;
        task->tCounter = 16;
        gSaveBlock3Ptr->NPCfollower.warpEnd = FNPC_WARP_NONE;
        gPlayerAvatar.preventStep = TRUE;
        ObjectEventClearHeldMovementIfActive(follower);
        ObjectEventSetHeldMovement(follower, GetFaceDirectionMovementAction(DIR_EAST));
        if (task->tMetatileBehavior == 0x6b)
            task->tState = SHOW_FOLLOWER_UP;
        break;
    case SHOW_FOLLOWER_DOWN:
        follower->invisible = FALSE;
        CalculateFollowerNPCEscalatorTrajectoryDown(task);
        task->tState = MOVE_FOLLOWER_DOWN;
        break;
    case MOVE_FOLLOWER_DOWN:
        CalculateFollowerNPCEscalatorTrajectoryDown(task);
        task->tMetatileBehavior++;
        if (task->tMetatileBehavior & 1)
        {
            task->tCounter--;
        }

        if (task->tCounter == 0)
        {
            sprite->x2 = 0;
            sprite->y2 = 0;
            task->tState = MOVEMENT_FINISH;
        }
        break;
    case SHOW_FOLLOWER_UP:
        follower->invisible = FALSE;
        CalculateFollowerNPCEscalatorTrajectoryUp(task);
        task->tState = MOVE_FOLLOWER_UP;
        break;
    case MOVE_FOLLOWER_UP:
        CalculateFollowerNPCEscalatorTrajectoryUp(task);
        task->tMetatileBehavior++;
        if (task->tMetatileBehavior & 1)
        {
            task->tCounter--;
        }

        if (task->tCounter == 0)
        {
            sprite->x2 = 0;
            sprite->y2 = 0;
            task->tState = MOVEMENT_FINISH;
        }
        break;
    case MOVEMENT_FINISH:
        if (ObjectEventClearHeldMovementIfFinished(follower))
        {
            gPlayerAvatar.preventStep = FALSE;
            DestroyTask(taskId);
        }
    }
}

static void CalculateFollowerNPCEscalatorTrajectoryDown(struct Task *task)
{
    struct Sprite *sprite = &gSprites[gObjectEvents[GetFollowerNPCMapObjId()].spriteId];

    sprite->x2 = Cos(0x84, task->tCounter);
    sprite->y2 = Sin(0x94, task->tCounter);
}

static void CalculateFollowerNPCEscalatorTrajectoryUp(struct Task *task)
{
    struct Sprite *sprite = &gSprites[gObjectEvents[GetFollowerNPCMapObjId()].spriteId];

    sprite->x2 = Cos(0x7c, task->tCounter);
    sprite->y2 = Sin(0x76, task->tCounter);
}

#undef tState
#undef tCounter
#undef tMetatileBehavior
#undef tTimer

bool8 FollowerNPCCanBike(void)
{
    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return TRUE;
    else if (gSaveBlock3Ptr->NPCfollower.flags & FOLLOWER_NPC_FLAG_CAN_BIKE)
        return TRUE;
    else
        return FALSE;
}

void FollowerNPC_HandleBike(void)
{
    if (gSaveBlock3Ptr->NPCfollower.currentSprite == FOLLOWER_NPC_SPRITE_INDEX_SURF) // Follower is surfing
        return; // Sprite will automatically be adjusted when they finish surfing

    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_MACH_BIKE && FollowerNPCCanBike() && gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs != FNPC_DOOR_NEEDS_TO_EXIT) //Coming out door
        SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_MACH_BIKE); // Mach Bike on
    else if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ACRO_BIKE && FollowerNPCCanBike() && gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs != FNPC_DOOR_NEEDS_TO_EXIT) //Coming out door
        SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_ACRO_BIKE); // Acro Bike on
    else
    {
        SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_NORMAL);
        gSaveBlock3Ptr->NPCfollower.delayedState = 0; // Disable saved Acro side jump
    }
}

void FollowerNPC_HandleSprite(void)
{
    if (gSaveBlock3Ptr->NPCfollower.flags & FOLLOWER_NPC_FLAG_CAN_BIKE)
    {
        if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_MACH_BIKE)
            SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_MACH_BIKE);
        else if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ACRO_BIKE)
            SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_ACRO_BIKE);
    }
    else if (gMapHeader.mapType == MAP_TYPE_UNDERWATER)
    {
        TryUpdateFollowerNPCSpriteUnderwater();
    }
    else
    {
        SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_NORMAL);
    }
}

void SetFollowerNPCSprite(u8 spriteIndex)
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
    follower = &gObjectEvents[GetFollowerNPCMapObjId()];
    gSaveBlock3Ptr->NPCfollower.currentSprite = spriteIndex;
    oldSpriteId = follower->spriteId;
    newGraphicsId = GetFollowerNPCSprite();

    // Reload the entire event object.
    // It would usually be enough just to change the sprite Id, but if the original
    // sprite and the new sprite have different palettes, the palette would need to
    // be reloaded.
    backupFollower = *follower;
    backupFollower.graphicsId = newGraphicsId;
    DestroySprite(&gSprites[oldSpriteId]);
    RemoveObjectEvent(&gObjectEvents[GetFollowerNPCMapObjId()]);

    clone = *GetObjectEventTemplateByLocalIdAndMap(gSaveBlock3Ptr->NPCfollower.map.id, gSaveBlock3Ptr->NPCfollower.map.number, gSaveBlock3Ptr->NPCfollower.map.group);
    clone.graphicsId = newGraphicsId;
    clone.movementType = 0; // Make sure new follower sprite can't move on its own
    clone.localId = OBJ_EVENT_ID_NPC_FOLLOWER;
    gSaveBlock3Ptr->NPCfollower.objId = TrySpawnObjectEventTemplate(&clone, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, clone.x, clone.y);
    if (gSaveBlock3Ptr->NPCfollower.objId != OBJECT_EVENTS_COUNT)
    {
        follower = &gObjectEvents[GetFollowerNPCMapObjId()];
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

void FollowerNPC_WarpSetEnd(void)
{
#if OW_ENABLE_NPC_FOLLOWERS
    struct ObjectEvent *player;
    struct ObjectEvent *follower;
    u8 toY;

    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    player = &gObjectEvents[gPlayerAvatar.objectEventId];
    follower = &gObjectEvents[GetFollowerNPCMapObjId()];

    gSaveBlock3Ptr->NPCfollower.warpEnd = FNPC_WARP_REAPPEAR;
    PlayerLogCoordinates(player);

    toY = gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs == FNPC_DOOR_NEEDS_TO_EXIT ? (player->currentCoords.y - 1) : player->currentCoords.y;
    MoveObjectEventToMapCoords(follower, player->currentCoords.x, toY);

    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_ON_FOOT)
        SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_NORMAL);

    follower->facingDirection = player->facingDirection;
    follower->movementDirection = player->movementDirection;
#endif
}

#if OW_ENABLE_NPC_FOLLOWERS
void CreateFollowerNPCAvatar(void)
{
    struct ObjectEvent *player;
    struct ObjectEventTemplate clone;

    if (!gSaveBlock3Ptr->NPCfollower.inProgress)
        return;

    player = &gObjectEvents[gPlayerAvatar.objectEventId];
    clone = *GetObjectEventTemplateByLocalIdAndMap(gSaveBlock3Ptr->NPCfollower.map.id, gSaveBlock3Ptr->NPCfollower.map.number, gSaveBlock3Ptr->NPCfollower.map.group);

    clone.graphicsId = GetFollowerNPCSprite();
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
        gSaveBlock3Ptr->NPCfollower.createSurfBlob = FNPC_SURF_BLOB_NONE;

    gObjectEvents[gSaveBlock3Ptr->NPCfollower.objId].invisible = TRUE;
}

static void TurnNPCIntoFollower(u8 localId, u16 followerFlags, u8 setScript, const u8 *ptr)
{
    struct ObjectEvent *follower;
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
            gSaveBlock3Ptr->NPCfollower.createSurfBlob = FNPC_SURF_BLOB_NONE;
            gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs = FNPC_DOOR_NONE;
            follower->localId = OBJ_EVENT_ID_NPC_FOLLOWER;
            FlagSet(flag);

            if (!(gSaveBlock3Ptr->NPCfollower.flags & FOLLOWER_NPC_FLAG_CAN_BIKE) // Follower can't bike
            &&  TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_BIKE)) // Player on bike
                SetPlayerAvatarTransitionFlags(PLAYER_AVATAR_FLAG_ON_FOOT); // Dismmount Bike

            if (!TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_ON_FOOT))
                FollowerNPC_HandleSprite(); // Set the follower sprite to match the player state
        }
    }
}

bool8 CheckFollowerNPCFlag(u16 flag)
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

void FollowerNPCWalkIntoPlayerForLeaveMap(void)
{
    u8 followerObjId = GetFollowerNPCObjectId();
    struct ObjectEvent *follower = &gObjectEvents[GetFollowerNPCMapObjId()];

    if (followerObjId == OBJECT_EVENTS_COUNT)
        return;

    follower->singleMovementActive = FALSE;
    follower->heldMovementActive = FALSE;
    switch (DetermineFollowerNPCDirection(&gObjectEvents[gPlayerAvatar.objectEventId], &gObjectEvents[followerObjId]))
    {
        case DIR_NORTH:
            ObjectEventSetHeldMovement(follower, MOVEMENT_ACTION_WALK_NORMAL_UP);
            break;
        case DIR_SOUTH:
            ObjectEventSetHeldMovement(follower, MOVEMENT_ACTION_WALK_NORMAL_DOWN);
            break;
        case DIR_EAST:
            ObjectEventSetHeldMovement(follower, MOVEMENT_ACTION_WALK_NORMAL_RIGHT);
            break;
        case DIR_WEST:
            ObjectEventSetHeldMovement(follower, MOVEMENT_ACTION_WALK_NORMAL_LEFT);
            break;
            }
}

void FollowerNPCHideForLeaveMap(struct ObjectEvent *follower)
{
    SetFollowerNPCSprite(FOLLOWER_NPC_SPRITE_INDEX_NORMAL);
    follower->invisible = TRUE;
    gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs = FNPC_DOOR_NONE; // In case the follower was still coming out of a door.
    gSaveBlock3Ptr->NPCfollower.createSurfBlob = FNPC_SURF_BLOB_NONE; // No more surf blob.
    gSaveBlock3Ptr->NPCfollower.delayedState = 0;
}

void FollowerNPCReappearAfterLeaveMap(struct ObjectEvent *follower, struct ObjectEvent *player)
{
    if (gSaveBlock3Ptr->NPCfollower.inProgress) {
        follower->invisible = FALSE; // Show the follower after ESCAPE ROPE
        MoveObjectEventToMapCoords(follower, player->currentCoords.x, player->currentCoords.y);
        ObjectEventTurn(follower, DIR_SOUTH); // Turn the follower SOUTH
        follower->singleMovementActive = FALSE;
        follower->heldMovementActive = FALSE;

        if (GetCollisionAtCoords(player, player->currentCoords.x, player->currentCoords.y + 1, DIR_SOUTH) == COLLISION_NONE)
            ObjectEventSetHeldMovement(follower, MOVEMENT_ACTION_WALK_NORMAL_DOWN); // Follower takes a step SOUTH
        else if (GetCollisionAtCoords(player, player->currentCoords.x + 1, player->currentCoords.y, DIR_EAST) == COLLISION_NONE)
            ObjectEventSetHeldMovement(follower, MOVEMENT_ACTION_WALK_NORMAL_RIGHT); // Follower takes a step SOUTH
        else if (GetCollisionAtCoords(player, player->currentCoords.x - 1, player->currentCoords.y, DIR_WEST) == COLLISION_NONE)
            ObjectEventSetHeldMovement(follower, MOVEMENT_ACTION_WALK_NORMAL_LEFT); // Follower takes a step SOUTH
        else
        {
            FollowerNPCPositionFix(0);
            follower->invisible = TRUE;
            gSaveBlock3Ptr->NPCfollower.warpEnd = FNPC_WARP_REAPPEAR;
        }
    }
}

void FollowerNPCFaceAfterLeaveMap(void)
{
    u8 playerDirection, followerDirection;
    struct ObjectEvent *player, *follower;

    player = &gObjectEvents[gPlayerAvatar.objectEventId];
    follower = &gObjectEvents[gSaveBlock3Ptr->NPCfollower.objId];
    playerDirection = DetermineFollowerNPCDirection(player, follower);
    followerDirection = playerDirection;

    //Flip direction
    switch (playerDirection) 
    {
    case DIR_NORTH:
        followerDirection = DIR_NORTH;
        break;
    case DIR_SOUTH:
        followerDirection = DIR_SOUTH;
        break;
    case DIR_WEST:
        followerDirection = DIR_WEST;
        break;
    case DIR_EAST:
        followerDirection = DIR_EAST;
        break;
    }

    ObjectEventTurn(follower, followerDirection);
    gSaveBlock3Ptr->NPCfollower.warpEnd = FNPC_WARP_NONE;
}

void Task_HideNPCFollowerAfterMovementFinish(u8 taskId)
{
    struct ObjectEvent *npcFollower = &gObjectEvents[GetFollowerNPCMapObjId()];
    
    if (ObjectEventClearHeldMovementIfFinished(npcFollower) != 0)
    {
        HideNPCFollower();
        gSaveBlock3Ptr->NPCfollower.warpEnd = FNPC_WARP_REAPPEAR;
        gPlayerAvatar.preventStep = FALSE;
        DestroyTask(taskId);
    }
}

enum
{
	GoDown,
	GoUp,
	GoLeft,
	GoRight
};

void FollowerNPCPositionFix(u8 offset)
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
    
    if (gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs != FNPC_DOOR_NONE || gObjectEvents[followerObjid].invisible)
    {
        gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs = FNPC_DOOR_NONE;
        npcX = playerX;
        npcY = playerY;
        return;
    }

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

static void ChooseFirstThreeEligibleMons(void)
{
    u8 i;
    u8 count = 0;

    ClearSelectedPartyOrder();

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_HP) != 0
         && GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG) == FALSE
         && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE)
        {
            gSelectedOrderFromParty[count] = (i + 1);
            count++;
        }

        if (count == 3)
            break;
    }
}

void PrepareForFollowerNPCBattle(void)
{
    SavePlayerParty();
    ChooseFirstThreeEligibleMons();
    ReducePlayerPartyToSelectedMons();
	VarSet(VAR_0x8004, FRONTIER_UTIL_FUNC_SET_DATA);
	VarSet(VAR_0x8005, FRONTIER_DATA_SELECTED_MON_ORDER);
	CallFrontierUtilFunc();
    gPartnerTrainerId = TRAINER_PARTNER(gSaveBlock3Ptr->NPCfollower.battlePartner);
    FillPartnerParty(gPartnerTrainerId);
}

void RestorePartyAfterFollowerNPCBattle(void)
{
    VarSet(VAR_0x8004, FRONTIER_UTIL_FUNC_SAVE_PARTY);
	CallFrontierUtilFunc();
	LoadPlayerParty();
}
#endif

void FollowerNPCTrainerSightingPositionFix(void)
{
#if OW_ENABLE_NPC_FOLLOWERS
    FollowerNPCPositionFix(1);
#endif
}

bool8 PlayerHasFollowerNPC(void)
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

bool8 FollowerNPCComingThroughDoor(void)
{
#if OW_ENABLE_NPC_FOLLOWERS
    if (!PlayerHasFollowerNPC())
        return FALSE;

    if (gSaveBlock3Ptr->NPCfollower.comeOutDoorStairs)
        return TRUE;
#endif

    return FALSE;
}

// Script commands
void ScriptSetFollowerNPC(struct ScriptContext *ctx)
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

void ScriptDestroyFollowerNPC(struct ScriptContext *ctx)
{
#if OW_ENABLE_NPC_FOLLOWERS
    if (gSaveBlock3Ptr->NPCfollower.inProgress)
    {
        RemoveObjectEvent(&gObjectEvents[gSaveBlock3Ptr->NPCfollower.objId]);
        FlagSet(gSaveBlock3Ptr->NPCfollower.flag);
        memset(&gSaveBlock3Ptr->NPCfollower, 0, sizeof(gSaveBlock3Ptr->NPCfollower));
    }
#if OW_FOLLOWERS_ENABLED
        UpdateFollowingPokemon();
#endif
#endif
}

void ScriptFaceFollowerNPC(struct ScriptContext *ctx)
{
#if OW_ENABLE_NPC_FOLLOWERS
    if (gSaveBlock3Ptr->NPCfollower.inProgress)
    {
        u8 playerDirection, followerDirection;
        struct ObjectEvent *player, *follower;

        player = &gObjectEvents[gPlayerAvatar.objectEventId];
        follower = &gObjectEvents[gSaveBlock3Ptr->NPCfollower.objId];
        playerDirection = DetermineFollowerNPCDirection(player, follower);
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

#if OW_ENABLE_NPC_FOLLOWERS
static const u8 *const FollowerNPCHideMovementsSpeedTable[][4] =
{
    [DIR_SOUTH] = {Common_Movement_WalkDownSlow, Common_Movement_WalkDown, Common_Movement_WalkDownFast, Common_Movement_WalkDownFaster},
    [DIR_NORTH] = {Common_Movement_WalkUpSlow, Common_Movement_WalkUp, Common_Movement_WalkUpFast, Common_Movement_WalkUpFaster},
    [DIR_WEST] = {Common_Movement_WalkLeftSlow, Common_Movement_WalkLeft, Common_Movement_WalkLeftFast, Common_Movement_WalkLeftFaster},
    [DIR_EAST] = {Common_Movement_WalkRightSlow, Common_Movement_WalkRight, Common_Movement_WalkRightFast, Common_Movement_WalkRightFaster}
};
#endif

void ScriptHideNPCFollower(struct ScriptContext *ctx)
{
#if OW_ENABLE_NPC_FOLLOWERS
    u8 walkSpeed = ScriptReadByte(ctx);
    struct ObjectEvent *npc = &gObjectEvents[GetFollowerNPCObjectId()];

    if (gSaveBlock3Ptr->NPCfollower.inProgress && npc->invisible == FALSE)
    {
        u8 direction = DetermineFollowerNPCDirection(&gObjectEvents[gPlayerAvatar.objectEventId], npc);

        if (walkSpeed > 3)
            walkSpeed = 3;

        ScriptMovement_StartObjectMovementScript(OBJ_EVENT_ID_NPC_FOLLOWER, npc->mapGroup, npc->mapNum, FollowerNPCHideMovementsSpeedTable[direction][walkSpeed]);
        gSaveBlock3Ptr->NPCfollower.warpEnd = FNPC_WARP_REAPPEAR;
    }
#endif
}

void ScriptCheckFollowerNPC(struct ScriptContext *ctx)
{
#if OW_ENABLE_NPC_FOLLOWERS
    gSpecialVar_Result = gSaveBlock3Ptr->NPCfollower.inProgress;
#endif
}

void ScriptUpdateFollowingMon(struct ScriptContext *ctx)
{
#if OW_ENABLE_NPC_FOLLOWERS
#if OW_FOLLOWERS_ENABLED
        UpdateFollowingPokemon();
#endif
#endif
}

void ScriptBallFollowingMon(struct ScriptContext *ctx)
{
    u32 species;
    u32 form;
    bool32 shiny;
    bool32 female;

    if (OW_POKEMON_OBJECT_EVENTS == FALSE
     || OW_FOLLOWERS_ENABLED == FALSE
     || !GetFollowerInfo(&species, &form, &shiny, &female)
     || SpeciesToGraphicsInfo(species, shiny, female) == NULL
     || (gMapHeader.mapType == MAP_TYPE_INDOOR && SpeciesToGraphicsInfo(species, shiny, female)->oam->size > ST_OAM_SIZE_2)
     || FlagGet(FLAG_TEMP_HIDE_FOLLOWER)
#if OW_ENABLE_NPC_FOLLOWERS
     || gSaveBlock3Ptr->NPCfollower.inProgress
#endif
     )
    {
        return;
    }
    else
    {
        ReturnFollowingMonToBall();
    }
}

void ScriptChangeFollowerNPCBattlePartner(struct ScriptContext *ctx)
{
#if OW_ENABLE_NPC_FOLLOWERS
    u16 newBattlePartner = ScriptReadHalfword(ctx);

    if (gSaveBlock3Ptr->NPCfollower.inProgress)
        gSaveBlock3Ptr->NPCfollower.battlePartner = newBattlePartner;
#endif
}
