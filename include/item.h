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

/* Expands TMs and HMs in their own enums in order to count them
 * but the enums themselves are not used anywhere but below
 */
#define UNPACK_TM_ENUM_1(_tm) CAT(ENUM_TM_, _tm),
#define UNPACK_HM_ENUM_1(_hm) CAT(ENUM_HM_, _hm),

enum {
    FOREACH_TM(UNPACK_TM_ENUM_1)
    NUM_TECHNICAL_MACHINES
};

enum {
    FOREACH_HM(UNPACK_HM_ENUM_1)
    NUM_HIDDEN_MACHINES
};

#define NUM_ALL_MACHINES NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES

#define UNPACK_TM_ENUM_2(_tm) CAT(ENUM_TM_HM_, _tm) = CAT(ENUM_TM_, _tm),
#define UNPACK_HM_ENUM_2(_hm) CAT(ENUM_TM_HM_, _hm) = CAT(ENUM_HM_, _hm) + NUM_TECHNICAL_MACHINES,

/* These are the actual enums - each one corresponds to an index in the list of TMs + HMs.
 * TMs in src/data/items.h should have an index in their .tmHmIndex field and this can be
 * automatically generated with the DEFINE_TM/DEFINE_HM macros below
 */
enum TMHM
{
    FOREACH_TM(UNPACK_TM_ENUM_2)
    FOREACH_HM(UNPACK_HM_ENUM_2)
};

/* This creates enums that let us associate an index with a real move ID */
#define UNPACK_MOVE_ID_FROM_INDEX(_tmHm) CAT(ENUM_TM_HM_MOVE_ID_,  _tmHm) = CAT(MOVE_, _tmHm),

enum TMIndexToMoveId
{
    FOREACH_TMHM(UNPACK_MOVE_ID_FROM_INDEX)
};

/* Functions to actually retrieve the move ID from an index input by returning one of the above enums as an answer */
#define TMHM_MOVE_ID_FROM_INDEX(_i) (RECURSIVELY(R_FOR_EACH_WITH(TMHM_MOVE_ID_FROM_INDEX_, (_i), FOREACH_TMHM(APPEND_COMMA))) MOVE_NONE)
#define TMHM_MOVE_ID_FROM_INDEX_(_i, _tmHm) (_i) == CAT(ENUM_TM_HM_, _tmHm) ? CAT(ENUM_TM_HM_MOVE_ID_,  _tmHm) :

/* Should be used in src/data/items.h to define TMs, HMs with the following syntax:
 * 
 *  [ITEM_TM_FOCUS_PUNCH] =
 *  {
 *      DEFINE_TM(01), // The leading zero is important here to generate the name "TM01" rather than "TM1"
 *      .price = 3000,
 *      .description = COMPOUND_STRING(
 *          "Powerful, but makes\n"
 *          "the user flinch if\n"
 *          "hit by the foe."),
 *      .importance = I_REUSABLE_TMS,
 *      .type = ITEM_USE_PARTY_MENU,
 *      .fieldUseFunc = ItemUseOutOfBattle_TMHM,
 *  },
 * 
 * Will generate the item's .name, .pocket, .tmHmIndex (see above), .secondaryId (by fetching a value from TMIndexToMoveId with TMHM_MOVE_ID_FROM_INDEX)
 */
#define DEFINE_TM(_tmNo) .name = _("TM" STR(_tmNo)), .pocket = POCKET_TM_HM, .tmHmIndex = REMOVE_LEADING_ZEROES(_tmNo) - 1, .secondaryId = TMHM_MOVE_ID_FROM_INDEX(REMOVE_LEADING_ZEROES(_tmNo) - 1)
#define DEFINE_HM(_hmNo) .name = _("HM" STR(_hmNo)), .pocket = POCKET_TM_HM, .tmHmIndex = REMOVE_LEADING_ZEROES(_hmNo) - 1 + NUM_TECHNICAL_MACHINES, .secondaryId = TMHM_MOVE_ID_FROM_INDEX(REMOVE_LEADING_ZEROES(_hmNo) - 1)

#undef UNPACK_TM_ENUM_1
#undef UNPACK_HM_ENUM_1
#undef UNPACK_TM_ENUM_2
#undef UNPACK_HM_ENUM_2
#undef UNPACK_MOVE_ID_FROM_INDEX

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
    union {
        u8 index; // Miscellaneous use?
        enum TMHM tmHmIndex:8;
    };
    u8 type;
    u8 battleUsage;
    u8 flingPower;
    const u32 *iconPic;
    const u16 *iconPalette;
};

struct __attribute__((packed, aligned(2))) BagPocket
{
    struct ItemSlot *itemSlots;
    u16 capacity;
};

extern const struct Item gItemsInfo[];
extern struct BagPocket gBagPockets[];
extern const u16 gTMHMItemIds[];

static inline u16 GetTMHMId(enum TMHM index)
{
    return gTMHMItemIds[index];
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

#endif // GUARD_ITEM_H
