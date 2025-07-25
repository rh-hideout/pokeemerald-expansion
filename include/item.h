#ifndef GUARD_ITEM_H
#define GUARD_ITEM_H

#include "constants/item.h"
#include "constants/item_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/tms_hms.h"
#include "constants/berries.h"
#include "constants/item_effects.h"
#include "constants/hold_effects.h"

/* Each of these TM_HM enums corresponds an index in the list of TMs + HMs.
 * The index for an item can be retrieved with GetItemTMHMIndex below.
 */
#define UNPACK_TM_HM_INDEX(_tmHm) CAT(TM_HM_INDEX_, _tmHm),
enum TMHMIndex
{
    FOREACH_TMHM(UNPACK_TM_HM_INDEX)
    NUM_ALL_MACHINES,
    NUM_TECHNICAL_MACHINES = (0 FOREACH_TM(PLUS_ONE)),
    NUM_HIDDEN_MACHINES = (0 FOREACH_HM(PLUS_ONE)),
};

#undef UNPACK_TM_HM_INDEX

typedef void (*ItemUseFunc)(u8);

struct Item
{
    u32 price;
    u16 secondaryId;
    ItemUseFunc fieldUseFunc;
    const u8 *description;
    const u8 *effect;
    u8 name[ITEM_NAME_LENGTH];
    u8 pluralName[ITEM_NAME_PLURAL_LENGTH];
    u8 holdEffect;
    u8 holdEffectParam;
    u8 importance:2;
    u8 notConsumed:1;
    enum Pocket pocket:5;
    u8 padding;
    u8 type;
    u8 battleUsage;
    u8 flingPower;
    const u32 *iconPic;
    const u16 *iconPalette;
};

struct ALIGNED(2) BagPocket
{
    struct ItemSlot *itemSlots;
    u16 capacity:10;
    enum Pocket id:6;
};

extern const struct Item gItemsInfo[];
extern struct BagPocket gBagPockets[];

#define UNPACK_ITEM_TO_TM_INDEX(_tm) case CAT(ITEM_TM_, _tm): return CAT(TM_HM_INDEX_, _tm) + 1;
#define UNPACK_ITEM_TO_HM_INDEX(_hm) case CAT(ITEM_HM_, _hm): return CAT(TM_HM_INDEX_, _hm) + 1;
#define UNPACK_ITEM_TO_TM_MOVE_ID(_tm) case CAT(ITEM_TM_, _tm): return CAT(MOVE_, _tm);
#define UNPACK_ITEM_TO_HM_MOVE_ID(_hm) case CAT(ITEM_HM_, _hm): return CAT(MOVE_, _hm);
#define UNPACK_TM_TO_ITEM_ID(_tm) case CAT(TM_HM_INDEX_, _tm): return CAT(ITEM_TM_, _tm);
#define UNPACK_HM_TO_ITEM_ID(_hm) case CAT(TM_HM_INDEX_, _hm): return CAT(ITEM_HM_, _hm);
#define UNPACK_TM_TO_MOVE_ID(_tm) case CAT(TM_HM_INDEX_, _tm): return CAT(MOVE_, _tm);
#define UNPACK_HM_TO_MOVE_ID(_hm) case CAT(TM_HM_INDEX_, _hm): return CAT(MOVE_, _hm);

static inline enum TMHMIndex GetItemTMHMIndex(enum ItemId item)
{
    switch (item)
    {
        /* Expands to:
         * case ITEM_TM_FOCUS_PUNCH:
         *     return 1;
         * case ITEM_TM_DRAGON_CLAW:
         *      return 2;
         * etc */
        FOREACH_TM(UNPACK_ITEM_TO_TM_INDEX)
        FOREACH_HM(UNPACK_ITEM_TO_HM_INDEX)
        default:
            return 0;
    }
}

static inline u16 GetItemTMHMMoveId(enum ItemId item)
{
    switch (item)
    {
        /* Expands to:
         * case ITEM_TM_FOCUS_PUNCH:
         *     return MOVE_FOCUS_PUNCH;
         * case ITEM_TM_DRAGON_CLAW:
         *      return MOVE_DRAGON_CLAW;
         * etc */
        FOREACH_TM(UNPACK_ITEM_TO_TM_MOVE_ID)
        FOREACH_HM(UNPACK_ITEM_TO_HM_MOVE_ID)
        default:
            return MOVE_NONE;
    }
}

static inline enum ItemId GetTMHMItemId(enum TMHMIndex index)
{
    switch (index)
    {
        /* Expands to:
         * case TM_HM_INDEX_FOCUS_PUNCH:
         *     return ITEM_TM_FOCUS_PUNCH;
         * case TM_HM_INDEX_DRAGON_CLAW:
         *      return ITEM_TM_DRAGON_CLAW;
         * etc */
        FOREACH_TM(UNPACK_TM_TO_ITEM_ID)
        FOREACH_HM(UNPACK_HM_TO_ITEM_ID)
        default:
            return ITEM_NONE;
    }
}

static inline u16 GetTMHMMoveId(enum TMHMIndex index)
{
    switch (index)
    {
        /* Expands to:
         * case TM_HM_INDEX_FOCUS_PUNCH:
         *     return MOVE_FOCUS_PUNCH;
         * case TM_HM_INDEX_DRAGON_CLAW:
         *      return MOVE_DRAGON_CLAW;
         * etc */
        FOREACH_TM(UNPACK_TM_TO_MOVE_ID)
        FOREACH_HM(UNPACK_HM_TO_MOVE_ID)
        default:
            return MOVE_NONE;
    }
}

#undef UNPACK_ITEM_TO_TM_INDEX
#undef UNPACK_ITEM_TO_HM_INDEX
#undef UNPACK_ITEM_TO_TM_MOVE_ID
#undef UNPACK_ITEM_TO_HM_MOVE_ID
#undef UNPACK_TM_TO_ITEM_ID
#undef UNPACK_HM_TO_ITEM_ID
#undef UNPACK_TM_TO_MOVE_ID
#undef UNPACK_HM_TO_MOVE_ID

#define GET_BERRY_INDEX(_berry) case ITEM_##_berry##_BERRY: return INDEX_##_berry##_BERRY;
#define GET_BERRY_ITEM_ID(_berry) case INDEX_##_berry##_BERRY: return ITEM_##_berry##_BERRY;

static inline enum BerryIndex GetBerryIndex(enum ItemId itemId)
{
    switch (itemId)
    {
    FOREACH_BERRY(GET_BERRY_INDEX)
    case ITEM_ENIGMA_BERRY_E_READER:
        return INDEX_ENIGMA_BERRY_E_READER;
    default:
        return INDEX_BERRY_NONE;
    }
};

static inline enum ItemId GetBerryItemId(enum BerryIndex berryIndex)
{
    switch (berryIndex)
    {
    FOREACH_BERRY(GET_BERRY_ITEM_ID)
    case INDEX_ENIGMA_BERRY_E_READER:
        return ITEM_ENIGMA_BERRY_E_READER;
    default:
        return ITEM_NONE;
    }
};

#undef GET_BERRY_INDEX
#undef GET_BERRY_ITEM_ID

enum SortPocket
{
    SORT_NONE,
    SORT_POCKET_BY_ITEM_ID,
    SORT_POCKET_TM_HM,
    SORT_POCKET_BERRIES,
};

void GetBagItemIdAndQuantity(enum Pocket pocketId, u32 pocketPos, u16 *itemId, u16 *quantity);
u16 GetBagItemId(enum Pocket pocketId, u32 pocketPos);
u16 GetBagItemQuantity(enum Pocket pocketId, u32 pocketPos);
void ApplyNewEncryptionKeyToBagItems(u32 newKey);
void SetBagItemsPointers(void);
u8 *CopyItemName(enum ItemId itemId, u8 *dst);
u8 *CopyItemNameHandlePlural(enum ItemId itemId, u8 *dst, u32 quantity);
bool32 IsBagPocketNonEmpty(enum Pocket pocketId);
bool32 CheckBagHasItem(enum ItemId itemId, u16 count);
bool32 HasAtLeastOneBerry(void);
bool32 HasAtLeastOnePokeBall(void);
bool32 CheckBagHasSpace(enum ItemId itemId, u16 count);
u32 GetFreeSpaceForItemInBag(enum ItemId itemId);
bool32 AddBagItem(enum ItemId itemId, u16 count);
bool32 RemoveBagItem(enum ItemId itemId, u16 count);
u8 CountUsedPCItemSlots(void);
bool32 CheckPCHasItem(enum ItemId itemId, u16 count);
bool32 AddPCItem(enum ItemId itemId, u16 count);
void RemovePCItem(u8 index, u16 count);
void CompactPCItems(void);
void SwapRegisteredBike(void);
void CompactItemsInBagPocket(enum Pocket pocketId);
void SortPocket(enum Pocket pocketId, enum SortPocket sortPocket);
void MoveItemSlotInPocket(enum Pocket pocketId, u32 from, u32 to);
void MoveItemSlotInPC(struct ItemSlot *itemSlots, u32 from, u32 to);
void ClearBag(void);
u16 CountTotalItemQuantityInBag(enum ItemId itemId);
bool32 AddPyramidBagItem(enum ItemId itemId, u16 count);
bool32 RemovePyramidBagItem(enum ItemId itemId, u16 count);
const u8 *GetItemName(enum ItemId itemId);
u32 GetItemPrice(enum ItemId itemId);
const u8 *GetItemEffect(u32 itemId);
u32 GetItemHoldEffect(u32 itemId);
u32 GetItemHoldEffectParam(u32 itemId);
const u8 *GetItemDescription(enum ItemId itemId);
u8 GetItemImportance(enum ItemId itemId);
u8 GetItemConsumability(enum ItemId itemId);
enum Pocket GetItemPocket(enum ItemId itemId);
u8 GetItemType(enum ItemId itemId);
ItemUseFunc GetItemFieldFunc(enum ItemId itemId);
u8 GetItemBattleUsage(enum ItemId itemId);
u32 GetItemSecondaryId(u32 itemId);
u32 GetItemFlingPower(u32 itemId);
u32 GetItemStatus1Mask(enum ItemId itemId);
bool32 ItemHasVolatileFlag(enum ItemId itemId, enum Volatile volatile);
u32 GetItemSellPrice(u32 itemId);
bool32 IsHoldEffectChoice(enum ItemHoldEffect holdEffect);

#endif // GUARD_ITEM_H
