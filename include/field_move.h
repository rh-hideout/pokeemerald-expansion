#ifndef GUARD_FIELD_MOVE_H
#define GUARD_FIELD_MOVE_H

#include "global.h"
#include "constants/field_move.h"

// Tracks whether a field move is being used via a Pokémon or an item
enum {
    FIELD_MOVE_SOURCE_POKEMON,  // Field move is used via a Pokémon that knows/can learn the move
    FIELD_MOVE_SOURCE_ITEM,     // Field move is used via a key item (e.g., FLY_TOOL, CUT_TOOL)
};

// Set the source of the current field move operation
void SetFieldMoveSource(u8 source);

// Get the source of the current field move operation
u8 GetFieldMoveSource(void);

// Check if Fly can be used (either via Pokémon or FLY_TOOL item)
bool8 CanUseFly(void);

// Check if Flash can be used (either via Pokémon or FLASH_TOOL item)
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
