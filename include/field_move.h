#ifndef GUARD_FIELD_MOVE_H
#define GUARD_FIELD_MOVE_H

#include "global.h"
#include "constants/field_move.h"

struct FieldMoveUnlock
{
   bool32 (*isUnlockedFunc)(enum FieldMove);
   const u8 *lockedMessage;
};

enum FieldMoveUnlockType
{
    CANT_UNLOCK,
    ALWAYS_UNLOCKED,
    BADGE_UNLOCK,
    FIELD_MOVE_UNLOCK_COUNT
};

struct FieldMoveInfo
{
    bool32 (*fieldMoveFunc)(void);
    enum FieldMoveUnlockType unlockType:3;
    enum Move moveID:11;
    u32 partyMsgID:7;
    u32 arg:8;
    u32 hideIfLocked:1;
    u32 padding:3;
    // HM item taught by this field move. When OW_HM_USABLE_FROM_BAG is enabled
    // and the player owns this item, the move can be used without any party
    // Pokémon knowing it. ITEM_NONE keeps vanilla behaviour.
    u32 hmItem:16;
    // Offer this move in the party menu on any Pokémon once its HM and Badge are
    // owned. Meant for moves with no usable overworld trigger: Fly and Flash.
    u32 offerInPartyMenu:1;
};

extern const struct FieldMoveInfo gFieldMoveInfo[];
extern const struct FieldMoveUnlock gFieldMoveUnlocks[];

static inline bool32 SetUpFieldMove(enum FieldMove fieldMove)
{
    return gFieldMoveInfo[fieldMove].fieldMoveFunc();
}

static inline bool32 IsFieldMoveUnlocked(enum FieldMove fieldMove)
{
    return gFieldMoveUnlocks[gFieldMoveInfo[fieldMove].unlockType].isUnlockedFunc(fieldMove);
}

static inline const u8 *FieldMove_GetLockedMessage(enum FieldMove fieldMove)
{
    return gFieldMoveUnlocks[gFieldMoveInfo[fieldMove].unlockType].lockedMessage;
}

static inline enum Move FieldMove_GetMoveId(enum FieldMove fieldMove)
{
    return gFieldMoveInfo[fieldMove].moveID;
}

static inline u32 FieldMove_GetPartyMsgID(enum FieldMove fieldMove)
{
    return gFieldMoveInfo[fieldMove].partyMsgID;
}

static inline bool32 FieldMove_IsVisible(enum FieldMove fieldMove)
{
    return !gFieldMoveInfo[fieldMove].hideIfLocked || IsFieldMoveUnlocked(fieldMove);
}

// Can this field move be used straight from the bag, without any party Pokémon
// knowing it? Requires OW_HM_USABLE_FROM_BAG, the HM item, and the Badge.
bool32 FieldMove_CanUseFromBag(enum FieldMove fieldMove);

// Index of the Pokémon that will perform the field move, or PARTY_SIZE if none
// can. A Pokémon that actually knows the move always takes priority, so vanilla
// behaviour is preserved; otherwise the first non-egg party member stands in.
u32 FieldMove_GetUserIndex(enum FieldMove fieldMove);

#endif //GUARD_FIELD_MOVE_H
