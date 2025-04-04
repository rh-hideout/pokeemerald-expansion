#ifndef GUARD_FOLLOWER_NPC_H
#define GUARD_FOLLOWER_NPC_H

#include "constants/follower_npc.h"

#define MOVEMENT_INVALID 0xFE

enum FollowerNPCSpriteTypes
{
    FOLLOWER_NPC_SPRITE_INDEX_NORMAL,
    FOLLOWER_NPC_SPRITE_INDEX_MACH_BIKE,
    FOLLOWER_NPC_SPRITE_INDEX_ACRO_BIKE,
    FOLLOWER_NPC_SPRITE_INDEX_SURF,
    FOLLOWER_NPC_SPRITE_INDEX_UNDERWATER,
};

enum FollowerNPCDoorStairsStates
{
    FNPC_DOOR_NONE,
    FNPC_DOOR_NEEDS_TO_EXIT
};

enum FollowerNPCWarpEndStates
{
    FNPC_WARP_NONE,
    FNPC_WARP_REAPPEAR
};

enum FollowerNPCSurfBlobStates
{
    FNPC_SURF_BLOB_NONE,
    FNPC_SURF_BLOB_NEW,
    FNPC_SURF_BLOB_RECREATE,
    FNPC_SURF_BLOB_DESTROY
};

bool8 FollowerNPCComingThroughDoor(void);
u8 GetFollowerNPCObjectId(void);
u8 GetFollowerNPCLocalId(void);
const u8 *GetFollowerNPCScriptPointer(void);
void HideNPCFollower(void);
void FollowerNPC_SetIndicatorToComeOutDoor(void);
void FollowerNPC_SetIndicatorToRecreateSurfBlob(void);
void FollowerNPC_TryRemoveFollowerOnWhiteOut(void);
void NPCFollow(struct ObjectEvent *npc, u8 state, bool8 ignoreScriptActive);
bool8 FollowerNPC_IsCollisionExempt(struct ObjectEvent *obstacle, struct ObjectEvent *collider);
void FollowerNPC_FollowerToWater(void);
void FollowerNPC_BindToSurfBlobOnReloadScreen(void);
void PrepareFollowerNPCDismountSurf(void);
void FollowerNPC_HandleBike(void);
void FollowerNPC_HandleSprite(void);
void FollowerNPC_WarpSetEnd(void);
void CreateFollowerNPCAvatar(void);
void EscalatorMoveFollowerNPC(u8 movementType);
void EscalatorMoveFollowerNPCFinish(void);
bool8 FollowerNPCCanBike(void);
bool8 CheckFollowerNPCFlag(u16 flag);
void FollowerNPCWalkIntoPlayerForLeaveRoute(struct ObjectEvent *follower);
void FollowerNPCHideForLeaveRoute(struct ObjectEvent *follower);
void FollowerNPCReappearAfterLeaveRoute(struct ObjectEvent *follower, struct ObjectEvent *player);
void FollowerNPCFaceAfterLeaveRoute(void);
void FollowerNPCPositionFix(u8 offset);
void SetFollowerNPCSprite(u8 spriteIndex);
bool8 PlayerHasFollowerNPC(void);
u8 DetermineFollowerNPCState(struct ObjectEvent *follower, u8 state, u8 direction);
u8 DetermineFollowerNPCDirection(struct ObjectEvent *player, struct ObjectEvent *follower);
u8 GetFollowerNPCMapObjId(void);
bool8 IsPlayerOnFoot(void);

#endif // GUARD_FOLLOWER_NPC_H