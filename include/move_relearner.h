#ifndef GUARD_MOVE_RELEARNER_H
#define GUARD_MOVE_RELEARNER_H

void TeachMoveRelearnerMove(void);
void MoveRelearnerShowHideHearts(s32);
void MoveRelearnerShowHideCategoryIcon(s32);
void CB2_InitLearnMove(void);

extern u8 gOriginSummaryScreenPage;

#define MAX_RELEARNER_MOVES 0xFF

#endif //GUARD_MOVE_RELEARNER_H
