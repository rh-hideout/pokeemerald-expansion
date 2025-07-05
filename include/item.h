#ifndef GUARD_ITEM_H
#define GUARD_ITEM_H

#include "constants/item.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/tms_hms.h"

/* Expands to:
 * enum
 * {
 *   ITEM_TM_FOCUS_PUNCH = ITEM_TM01,
 *   ...
 *   ITEM_HM_CUT = ITM_HM01,
 *   ...
 * }; */
#define ENUM_TM(n, id) CAT(ITEM_TM_, id) = CAT(ITEM_TM, n),
#define ENUM_HM(n, id) CAT(ITEM_HM_, id) = CAT(ITEM_HM, n),
#define TO_TMHM_NUMS(a, ...) (__VA_ARGS__)
enum TMHMItemId
{
    RECURSIVELY(R_ZIP(ENUM_TM, TO_TMHM_NUMS NUMBERS_256, (FOREACH_TM(APPEND_COMMA))))
    RECURSIVELY(R_ZIP(ENUM_HM, TO_TMHM_NUMS NUMBERS_256, (FOREACH_HM(APPEND_COMMA))))
};

#undef ENUM_TM
#undef ENUM_HM
#undef TO_TMHM_NUMS

/* Each of these TM_HM enums corresponds an index in the list of TMs + HMs item ids in
 * gTMHMItemMoveIds. The index for an item can be retrieved with GetItemTMHMIndex below.
 */
#define UNPACK_TM_HM_ENUM(_tmHm) CAT(ENUM_TM_HM_, _tmHm),
enum TMHMIndex
{
    FOREACH_TMHM(UNPACK_TM_HM_ENUM)
    NUM_ALL_MACHINES,
    NUM_TECHNICAL_MACHINES = (0 FOREACH_TM(PLUS_ONE)),
    NUM_HIDDEN_MACHINES = (0 FOREACH_HM(PLUS_ONE)),
};

#undef UNPACK_TM_HM_ENUM

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

struct TmHmIndexKey
{
    enum TMHMItemId itemId:16;
    u16 moveId;
};

extern const struct Item gItemsInfo[];
extern struct BagPocket gBagPockets[];
extern const struct TmHmIndexKey gTMHMItemMoveIds[];

#define UNPACK_ITEM_TO_TM_INDEX(_tm) case CAT(ITEM_TM_, _tm): return CAT(ENUM_TM_HM_, _tm) + 1;
#define UNPACK_ITEM_TO_HM_INDEX(_hm) case CAT(ITEM_HM_, _hm): return CAT(ENUM_TM_HM_, _hm) + 1;
#define UNPACK_ITEM_TO_TM_MOVE_ID(_tm) case CAT(ITEM_TM_, _tm): return CAT(MOVE_, _tm);
#define UNPACK_ITEM_TO_HM_MOVE_ID(_hm) case CAT(ITEM_HM_, _hm): return CAT(MOVE_, _hm);

static inline enum TMHMIndex GetItemTMHMIndex(u16 item)
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

static inline u16 GetItemTMHMMoveId(u16 item)
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

#undef UNPACK_ITEM_TO_TM_INDEX
#undef UNPACK_ITEM_TO_HM_INDEX
#undef UNPACK_ITEM_TO_TM_MOVE_ID
#undef UNPACK_ITEM_TO_HM_MOVE_ID

static inline enum TMHMItemId GetTMHMItemId(enum TMHMIndex index)
{
    return gTMHMItemMoveIds[index].itemId;
}

static inline u16 GetTMHMMoveId(enum TMHMIndex index)
{
    return gTMHMItemMoveIds[index].moveId;
}

enum SortPocket
{
    SORT_NONE,
    SORT_POCKET_BY_ITEM_ID,
    SORT_POCKET_TM_HM,
};

void GetBagItemIdAndQuantity(enum Pocket pocketId, u32 pocketPos, u16 *itemId, u16 *quantity);
u16 GetBagItemId(enum Pocket pocketId, u32 pocketPos);
u16 GetBagItemQuantity(enum Pocket pocketId, u32 pocketPos);
void ApplyNewEncryptionKeyToBagItems(u32 newKey);
void SetBagItemsPointers(void);
u8 *CopyItemName(u16 itemId, u8 *dst);
u8 *CopyItemNameHandlePlural(u16 itemId, u8 *dst, u32 quantity);
bool32 IsBagPocketNonEmpty(enum Pocket pocketId);
bool32 CheckBagHasItem(u16 itemId, u16 count);
bool32 HasAtLeastOneBerry(void);
bool32 HasAtLeastOnePokeBall(void);
bool32 CheckBagHasSpace(u16 itemId, u16 count);
u32 GetFreeSpaceForItemInBag(u16 itemId);
bool32 AddBagItem(u16 itemId, u16 count);
bool32 RemoveBagItem(u16 itemId, u16 count);
u8 CountUsedPCItemSlots(void);
bool32 CheckPCHasItem(u16 itemId, u16 count);
bool32 AddPCItem(u16 itemId, u16 count);
void RemovePCItem(u8 index, u16 count);
void CompactPCItems(void);
void SwapRegisteredBike(void);
void CompactItemsInBagPocket(enum Pocket pocketId);
void SortPocket(enum Pocket pocketId, enum SortPocket sortPocket);
void MoveItemSlotInPocket(enum Pocket pocketId, u32 from, u32 to);
void MoveItemSlotInPC(struct ItemSlot *itemSlots, u32 from, u32 to);
void ClearBag(void);
u16 CountTotalItemQuantityInBag(u16 itemId);
bool32 AddPyramidBagItem(u16 itemId, u16 count);
bool32 RemovePyramidBagItem(u16 itemId, u16 count);
const u8 *GetItemName(u16 itemId);
u32 GetItemPrice(u16 itemId);
const u8 *GetItemEffect(u32 itemId);
u32 GetItemHoldEffect(u32 itemId);
u32 GetItemHoldEffectParam(u32 itemId);
const u8 *GetItemDescription(u16 itemId);
u8 GetItemImportance(u16 itemId);
u8 GetItemConsumability(u16 itemId);
enum Pocket GetItemPocket(u16 itemId);
u8 GetItemType(u16 itemId);
ItemUseFunc GetItemFieldFunc(u16 itemId);
u8 GetItemBattleUsage(u16 itemId);
u32 GetItemSecondaryId(u32 itemId);
u32 GetItemFlingPower(u32 itemId);
u32 GetItemStatus1Mask(u16 itemId);
u32 GetItemStatus2Mask(u16 itemId);
u32 GetItemSellPrice(u32 itemId);

#endif // GUARD_ITEM_H
