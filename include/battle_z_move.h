#ifndef GUARD_BATTLE_Z_MOVE_H
#define GUARD_BATTLE_Z_MOVE_H

#include "constants/battle_z_move_effects.h"

#define MOVE_Z_STATUS   0xFFFF

struct SignatureZMove
{
    u16 species;
    enum Item item;
    enum Move move;
    enum Move zmove;
};

bool32 IsZMove(enum Move move);
bool32 CanUseZMove(u32 battler);
enum Move GetUsableZMove(u32 battler, enum Move move);
void ActivateZMove(u32 battler);
bool32 IsViableZMove(u32 battler, enum Move move);
bool32 TryChangeZTrigger(u32 battler, u32 moveIndex);
enum Move GetTypeBasedZMove(enum Move move);
enum Move GetSignatureZMove(enum Move move, u32 species, enum Item item);
bool32 MoveSelectionDisplayZMove(enum Move zmove, u32 battler);
void SetZEffect(void);
void AssignUsableZMoves(u32 battler, enum Move *moves);
u32 GetZMovePower(enum Move move);

#endif // GUARD_BATTLE_Z_MOVE_H
