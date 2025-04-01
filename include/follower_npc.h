#ifndef GUARD_FOLLOWER_NPC_H
#define GUARD_FOLLOWER_NPC_H

#include "constants/follower_npc.h"

#define MOVEMENT_INVALID 0xFE

enum FollowerSpriteTypes
{
    FOLLOWER_SPRITE_INDEX_NORMAL,
    FOLLOWER_SPRITE_INDEX_MACH_BIKE,
    FOLLOWER_SPRITE_INDEX_ACRO_BIKE,
    FOLLOWER_SPRITE_INDEX_SURF,
    FOLLOWER_SPRITE_INDEX_UNDERWATER,
};

bool8 FollowerComingThroughDoor(void);
u8 GetFollowerObjectId(void);
u8 GetFollowerLocalId(void);
const u8* GetFollowerScriptPointer(void);
void HideFollower(void);
void TryFreezeFollowerAnim(struct ObjectEvent* npc);
void IsFollowerStoppingRockClimb(void);
void FollowMe_SetIndicatorToComeOutDoor(void);
void FollowMe_SetIndicatorToRecreateSurfBlob(void);
void FollowMe_TryRemoveFollowerOnWhiteOut(void);
void FollowMe(struct ObjectEvent* npc, u8 state, bool8 ignoreScriptActive);
bool8 FollowMe_IsCollisionExempt(struct ObjectEvent* obstacle, struct ObjectEvent* collider);
void FollowMe_FollowerToWater(void);
void FollowMe_BindToSurfBlobOnReloadScreen(void);
void PrepareFollowerDismountSurf(void);
void StairsMoveFollower(void);
void FollowMe_HandleBike(void);
void FollowMe_HandleSprite(void);
void FollowMe_WarpSetEnd(void);
void CreateFollowerAvatar(void);
void EscalatorMoveFollower(u8 movementType);
void EscalatorMoveFollowerFinish(void);
bool8 FollowerCanBike(void);
bool8 CheckFollowerFlag(u16 flag);
void FollowerPositionFix(u8 offset);
void SetFollowerSprite(u8 spriteIndex);
bool8 PlayerHasFollower(void);
u8 DetermineFollowerState(struct ObjectEvent* follower, u8 state, u8 direction);
u8 DetermineFollowerDirection(struct ObjectEvent* player, struct ObjectEvent* follower);
u8 GetFollowerMapObjId(void);
bool8 IsPlayerOnFoot(void);

#endif // GUARD_FOLLOWER_NPC_H