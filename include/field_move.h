#ifndef GUARD_FIELD_MOVE_H
#define GUARD_FIELD_MOVE_H

#include "global.h"
#include "constants/field_move.h"

enum {
    FIELD_MOVE_SOURCE_POKEMON,
    FIELD_MOVE_SOURCE_ITEM,
};

void SetFieldMoveSource(u8 source);
u8 GetFieldMoveSource(void);
bool8 CanUseFly(void);
bool8 CanUseFlash(void);

struct FieldMoveInfo
{
    bool32 (*fieldMoveFunc)(void);
    bool32 (*isUnlockedFunc)(void);
    u16 moveID;
    u8 partyMsgID;
};

extern const struct FieldMoveInfo gFieldMoveInfo[];

static inline bool32 SetUpFieldMove(enum FieldMove fieldMove)
{
    return gFieldMoveInfo[fieldMove].fieldMoveFunc();
}

static inline bool32 IsFieldMoveUnlocked(enum FieldMove fieldMove)
{
    return gFieldMoveInfo[fieldMove].isUnlockedFunc();
}

static inline u32 FieldMove_GetMoveId(enum FieldMove fieldMove)
{
    return gFieldMoveInfo[fieldMove].moveID;
}

static inline u32 FieldMove_GetPartyMsgID(enum FieldMove fieldMove)
{
    return gFieldMoveInfo[fieldMove].partyMsgID;
}

#endif //GUARD_FIELD_MOVE_H
