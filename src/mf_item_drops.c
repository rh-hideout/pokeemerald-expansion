#include "global.h"
#include "battle.h"
#include "battle_scripts.h"
#include "item.h"
#include "mf_item_drops.h"
#include "mf_rules.h"
#include "pokemon.h"
#include "constants/battle.h"
#include "constants/battle_string_ids.h"
#include "constants/items.h"

// Same layout as battle_script_commands.c NATIVE_ARGS — callnative embeds the fn ptr.
#define MF_NATIVE_ARGS() \
    const struct __attribute__((packed)) { \
        u8 opcode; \
        void (*func)(void); \
        const u8 nextInstr[0]; \
    } *const cmd UNUSED = (const void *)gBattlescriptCurrInstr

const u16 gMfItemDroppedStringIds[] =
{
    [MF_ITEM_DROP_MSG_GRANTED]  = STRINGID_PKMNDROPPEDITEM,
    [MF_ITEM_DROP_MSG_BAG_FULL] = STRINGID_PKMNDROPPEDITEMBAGFULL,
};

bool32 MfWildBattleAllowsItemDrops(u32 battleTypeFlags)
{
    // ME: skip trainer / first-battle / Wally tutorial. FR has no Wally tutorial;
    // also skip Safari / ghost tower / link so we never gift outside normal wild wins.
    if (battleTypeFlags & (BATTLE_TYPE_TRAINER
                         | BATTLE_TYPE_FIRST_BATTLE
                         | BATTLE_TYPE_SAFARI
                         | BATTLE_TYPE_GHOST
                         | BATTLE_TYPE_LINK
                         | BATTLE_TYPE_RECORDED_LINK
                         | BATTLE_TYPE_FRONTIER
                         | BATTLE_TYPE_EREADER_TRAINER))
        return FALSE;

    return TRUE;
}

enum Item MfSelectWildItemDrop(enum Item heldItem, bool32 featureEnabled)
{
    if (!featureEnabled || heldItem == ITEM_NONE)
        return ITEM_NONE;
    return heldItem;
}

u32 MfTryGrantWildItemDrop(enum Item item)
{
    if (item == ITEM_NONE)
        return MF_ITEM_DROP_MSG_BAG_FULL;

    if (AddBagItem(item, 1))
        return MF_ITEM_DROP_MSG_GRANTED;

    return MF_ITEM_DROP_MSG_BAG_FULL;
}

static void ClearWildHeldItem(enum BattlerId battler)
{
    enum Item none = ITEM_NONE;
    u8 partyIndex = gBattlerPartyIndexes[battler];

    gBattleMons[battler].item = ITEM_NONE;
    SetMonData(&gParties[B_TRAINER_OPPONENT_A][partyIndex], MON_DATA_HELD_ITEM, &none);
}

void BS_TryGiveWildItemDrops(void)
{
    MF_NATIVE_ARGS();

    u32 i;
    u32 battlerCount;
    enum BattlerId battlers[2];

    if (!MfRules_HasWildItemDrops() || !MfWildBattleAllowsItemDrops(gBattleTypeFlags))
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }

    battlers[0] = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
    battlers[1] = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
    battlerCount = IsDoubleBattle() ? 2 : 1;

    for (i = 0; i < battlerCount; i++)
    {
        enum BattlerId battler = battlers[i];
        u8 partyIndex = gBattlerPartyIndexes[battler];
        enum Item heldItem = GetMonData(&gParties[B_TRAINER_OPPONENT_A][partyIndex], MON_DATA_HELD_ITEM);
        enum Item drop;

        // Prefer live battle state if party sync lagged (berry consume clears both).
        if (heldItem == ITEM_NONE)
            heldItem = gBattleMons[battler].item;

        drop = MfSelectWildItemDrop(heldItem, TRUE);
        if (drop == ITEM_NONE)
            continue;

        // Consume the drop candidate either way (ME clears history even on bag-full).
        ClearWildHeldItem(battler);
        gLastUsedItem = drop;
        gBattleCommunication[MULTISTRING_CHOOSER] = MfTryGrantWildItemDrop(drop);
        gBattlescriptCurrInstr = BattleScript_MfItemDropped;
        return;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}
