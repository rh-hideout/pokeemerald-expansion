#ifndef GUARD_APRICORN_TREE_H
#define GUARD_APRICORN_TREE_H

#include "constants/apricorn_tree.h"
#include "constants/items.h"

bool8 IsApricornTreePicked(u32 id);
void SetApricornTreePicked(u32 id);

void DailyResetApricornTrees(void);
void ObjectEventInteractionGetApricornTreeData(void);
void ObjectEventInteractionPickApricornTree(void);
u8 GetApricornTypeByApricornTreeId(u32 id);
u8 GetApricornCountByApricornTreeId(u32 id);

#endif //GUARD_APRICORN_TREE_H
