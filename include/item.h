#ifndef GUARD_ITEM_H
#define GUARD_ITEM_H

#include "constants/item.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/tms_hms.h"

/* Expands to:
 * enum
 * {
 *   ITEM_TM_FOCUS_PUNCH,
 *   ...
 *   ITEM_HM_CUT,
 *   ...
 * }; */
#define ENUM_TM(id) CAT(ITEM_TM_, id),
#define ENUM_HM(id) CAT(ITEM_HM_, id),
enum
{
    ENUM_TM_START_ = ITEM_TM01 - 1,
    FOREACH_TM(ENUM_TM)

    ENUM_HM_START_ = ITEM_HM01 - 1,
    FOREACH_HM(ENUM_HM)
};
#undef ENUM_TM
#undef ENUM_HM

/* Each of these TM_HM enums corresponds an index in the list of TMs + HMs item ids in
 * gTMHMItemMoveIds. TMs in src/data/items.h should have an index in their .tmHmIndex field
 * and this can be automatically generated with the DEFINE_TM/DEFINE_HM macros below.
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
    union PACKED {
        u8 index; // Used for sorting !! DO NOT USE IN data/items/h as it does not check type !!
        enum TMHMIndex tmHmIndex:8;
        // enum BerryIndex berryIndex:8; // Coming soon...
    };
    u8 type;
    u8 battleUsage;
    u8 flingPower;
    const u32 *iconPic;
    const u16 *iconPalette;
};

struct ALIGNED(2) BagPocket
{
    struct ItemSlot *itemSlots;
    u16 capacity;
};

struct TmHmIndexKey
{
    u16 itemId;
    u16 moveId;
};

extern const struct Item gItemsInfo[];
extern struct BagPocket gBagPockets[];
extern const struct TmHmIndexKey gTMHMItemMoveIds[];

static inline u16 GetTMHMItemId(enum TMHMIndex index)
{
    return gTMHMItemMoveIds[index].itemId;
}

static inline u16 GetTMHMMoveId(enum TMHMIndex index)
{
    return gTMHMItemMoveIds[index].moveId;
}

u16 GetBagItemId(enum Pocket pocketId, u32 pocketPos);
u16 GetBagItemQuantity(enum Pocket pocketId, u32 pocketPos);
void SetBagItemQuantity(enum Pocket pocketId, u32 pocketPos, u16 newValue);
void ApplyNewEncryptionKeyToBagItems(u32 newKey);
void SetBagItemsPointers(void);
u8 *CopyItemName(u16 itemId, u8 *dst);
u8 *CopyItemNameHandlePlural(u16 itemId, u8 *dst, u32 quantity);
bool8 IsBagPocketNonEmpty(enum Pocket pocketId);
bool8 CheckBagHasItem(u16 itemId, u16 count);
bool8 HasAtLeastOneBerry(void);
bool8 HasAtLeastOnePokeBall(void);
bool8 CheckBagHasSpace(u16 itemId, u16 count);
u32 GetFreeSpaceForItemInBag(u16 itemId);
bool8 AddBagItem(u16 itemId, u16 count);
bool8 RemoveBagItem(u16 itemId, u16 count);
u8 CountUsedPCItemSlots(void);
bool8 CheckPCHasItem(u16 itemId, u16 count);
bool8 AddPCItem(u16 itemId, u16 count);
void RemovePCItem(u8 index, u16 count);
void CompactPCItems(void);
void SwapRegisteredBike(void);
void CompactItemsInBagPocket(enum Pocket pocketId);
void SortBerriesOrTMHMs(enum Pocket pocketId);
void MoveItemSlotInPocket(enum Pocket pocketId, u32 from, u32 to);
void MoveItemSlotInPC(struct ItemSlot *itemSlots, u32 from, u32 to);
void ClearBag(void);
u16 CountTotalItemQuantityInBag(u16 itemId);
bool8 AddPyramidBagItem(u16 itemId, u16 count);
bool8 RemovePyramidBagItem(u16 itemId, u16 count);
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
