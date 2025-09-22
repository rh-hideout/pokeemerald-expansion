#include "constants/apricorn_tree.h"
#include "constants/items.h"

#if (APRICORN_TREE_COUNT > 0)
bool8 IsApricornTreePicked(u8 id);
void SetApricornTreePicked(u8 id);

void DailyResetApricornTrees(void);
void ObjectEventInteractionGetApricornTreeData(void);
void ObjectEventInteractionPickApricornTree(void);
u8 GetApricornTypeByApricornTreeId(u8 id);
u8 GetApricornCountByApricornTreeId(u8 id);
static u16 ApricornTypeToItemId(u8 apricorn);
#endif
