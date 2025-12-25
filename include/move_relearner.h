#ifndef GUARD_MOVE_RELEARNER_H
#define GUARD_MOVE_RELEARNER_H

#include "constants/move_relearner.h"

void TeachMoveRelearnerMove(void);
void MoveRelearnerShowHideHearts(s32 move);
void MoveRelearnerShowHideCategoryIcon(s32);
void CB2_InitLearnMove(void);

extern enum MoveRelearnerStates gMoveRelearnerState;
extern enum RelearnMode gRelearnMode;

#endif //GUARD_MOVE_RELEARNER_H
