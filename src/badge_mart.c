#include "global.h"
#include "constants/items.h"
#include "constants/flags.h"
#include "script.h"
#include "event_data.h"

// Badge-based mart inventories
// Tier 0: No badges, before Prof. Birch has given the player Poke Balls
static const u16 sMartInventory_Tier0[] = {
    ITEM_POTION,
    ITEM_ANTIDOTE,
    ITEM_PARALYZE_HEAL,
    ITEM_AWAKENING,
    ITEM_EXP_CANDY_XS,
    ITEM_NONE
};

// Tier 1: No badges
static const u16 sMartInventory_Tier1[] = {
    ITEM_POKE_BALL,
    ITEM_POTION,
    ITEM_ANTIDOTE,
    ITEM_PARALYZE_HEAL,
    ITEM_AWAKENING,
    ITEM_EXP_CANDY_XS,
    ITEM_NONE
};

// Tier 2: 1-2 badges
static const u16 sMartInventory_Tier2[] = {
    ITEM_POKE_BALL,
    ITEM_POTION,
    ITEM_ANTIDOTE,
    ITEM_PARALYZE_HEAL,
    ITEM_AWAKENING,
    ITEM_REPEL,
    ITEM_X_SPEED,
    ITEM_X_ATTACK,
    ITEM_X_DEFENSE,
    ITEM_EXP_CANDY_S,
    ITEM_NONE
};

// Tier 3: 3-4 badges
static const u16 sMartInventory_Tier3[] = {
    ITEM_POKE_BALL,
    ITEM_GREAT_BALL,
    ITEM_POTION,
    ITEM_SUPER_POTION,
    ITEM_ANTIDOTE,
    ITEM_PARALYZE_HEAL,
    ITEM_AWAKENING,
    ITEM_BURN_HEAL,
    ITEM_SUPER_REPEL,
    ITEM_REPEL,
    ITEM_X_SPEED,
    ITEM_X_ATTACK,
    ITEM_X_DEFENSE,
    ITEM_GUARD_SPEC,
    ITEM_DIRE_HIT,
    ITEM_EXP_CANDY_M,
    ITEM_NONE
};

// Tier 4: 5-6 badges
static const u16 sMartInventory_Tier4[] = {
    ITEM_POKE_BALL,
    ITEM_GREAT_BALL,
    ITEM_TIMER_BALL,
    ITEM_REPEAT_BALL,
    ITEM_HYPER_POTION,
    ITEM_ANTIDOTE,
    ITEM_PARALYZE_HEAL,
    ITEM_AWAKENING,
    ITEM_BURN_HEAL,
    ITEM_ICE_HEAL,
    ITEM_REVIVE,
    ITEM_ESCAPE_ROPE,
    ITEM_MAX_REPEL,
    ITEM_REPEL,
    ITEM_X_SPEED,
    ITEM_X_ATTACK,
    ITEM_X_DEFENSE,
    ITEM_X_SP_ATK,
    ITEM_GUARD_SPEC,
    ITEM_DIRE_HIT,
    ITEM_X_ACCURACY,
    ITEM_EXP_CANDY_L,
    ITEM_NONE
};

// Tier 5: 7+ badges
static const u16 sMartInventory_Tier5[] = {
    ITEM_POKE_BALL,
    ITEM_GREAT_BALL,
    ITEM_ULTRA_BALL,
    ITEM_TIMER_BALL,
    ITEM_REPEAT_BALL,
    ITEM_NET_BALL,
    ITEM_DIVE_BALL,
    ITEM_POTION,
    ITEM_MAX_POTION,
    ITEM_FULL_RESTORE,
    ITEM_FULL_HEAL,
    ITEM_ANTIDOTE,
    ITEM_PARALYZE_HEAL,
    ITEM_AWAKENING,
    ITEM_BURN_HEAL,
    ITEM_ICE_HEAL,
    ITEM_REVIVE,
    ITEM_ESCAPE_ROPE,
    ITEM_MAX_REPEL,
    ITEM_REPEL,
    ITEM_X_SPEED,
    ITEM_X_ATTACK,
    ITEM_X_DEFENSE,
    ITEM_X_SP_ATK,
    ITEM_GUARD_SPEC,
    ITEM_DIRE_HIT,
    ITEM_X_ACCURACY,
    ITEM_PROTEIN,
    ITEM_CALCIUM,
    ITEM_IRON,
    ITEM_ZINC,
    ITEM_CARBOS,
    ITEM_HP_UP,
    ITEM_BUG_TERA_SHARD,
    ITEM_DARK_TERA_SHARD,
    ITEM_DRAGON_TERA_SHARD,
    ITEM_ELECTRIC_TERA_SHARD,
    ITEM_FAIRY_TERA_SHARD,
    ITEM_FIGHTING_TERA_SHARD,
    ITEM_FIRE_TERA_SHARD,
    ITEM_FLYING_TERA_SHARD,
    ITEM_GHOST_TERA_SHARD,
    ITEM_GRASS_TERA_SHARD,
    ITEM_GROUND_TERA_SHARD,
    ITEM_ICE_TERA_SHARD,
    ITEM_NORMAL_TERA_SHARD,
    ITEM_POISON_TERA_SHARD,
    ITEM_PSYCHIC_TERA_SHARD,
    ITEM_ROCK_TERA_SHARD,
    ITEM_STEEL_TERA_SHARD,
    ITEM_WATER_TERA_SHARD,
    ITEM_EXP_CANDY_XL,
    ITEM_NONE
};

// Count the number of badges the player has obtained
static u8 CountPlayerBadges(void)
{
    u8 badgeCount = 0;
    u16 badgeFlag;

    for (badgeFlag = FLAG_BADGE01_GET; badgeFlag < FLAG_BADGE01_GET + NUM_BADGES; badgeFlag++)
    {
        if (FlagGet(badgeFlag))
            badgeCount++;
    }

    return badgeCount;
}

// Get the appropriate mart inventory based on badge count.
// In New Game + mode, always use the final tier.
const u16 *GetBadgeBasedMartInventory(void)
{
    if (gSaveBlock2Ptr->newGamePlus > 0)
        return sMartInventory_Tier5;

    if (!FlagGet(FLAG_ADVENTURE_STARTED))
        return sMartInventory_Tier0;

    u8 badgeCount = CountPlayerBadges();

    if (badgeCount >= 7)
        return sMartInventory_Tier5;
    else if (badgeCount >= 5)
        return sMartInventory_Tier4;
    else if (badgeCount >= 3)
        return sMartInventory_Tier3;
    else if (badgeCount >= 1)
        return sMartInventory_Tier2;
    else
        return sMartInventory_Tier1;
}
