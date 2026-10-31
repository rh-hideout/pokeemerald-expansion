#include "global.h"
#include "event_data.h"
#include "random.h"
#include "renewable_hidden_items.h"
#include "constants/maps.h"

#define MAX_HIDDEN_ITEMS_PER_GROUP 8
#define RENEWABLE_ITEM_MAX_STEP_COUNT 1500

struct RenewableHiddenItemData
{
    u8 rare[MAX_HIDDEN_ITEMS_PER_GROUP];     // 10%
    u8 uncommon[MAX_HIDDEN_ITEMS_PER_GROUP]; // 30%
    u8 common[MAX_HIDDEN_ITEMS_PER_GROUP];   // 60%
};

static void SampleRenewableItemFlags(void);

#define NO_ITEM 0xFF
#define HIDDEN_ID(flag)(flag ? flag - FLAG_HIDDEN_ITEMS_START : NO_ITEM)

static const u16 sMapsWithRenewableItems[] = {
    MAP_ROUTE20,
    MAP_ROUTE21_NORTH,
    MAP_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL,
    MAP_UNDERGROUND_PATH_EAST_WEST_TUNNEL,
    MAP_SEVEN_ISLAND_TANOBY_RUINS,
    MAP_MT_MOON_B1F,
    MAP_THREE_ISLAND_BERRY_FOREST,
    MAP_ONE_ISLAND_TREASURE_BEACH,
    MAP_THREE_ISLAND_BOND_BRIDGE,
    MAP_FOUR_ISLAND,
    MAP_FIVE_ISLAND_MEMORIAL_PILLAR,
    MAP_FIVE_ISLAND_RESORT_GORGEOUS,
    MAP_SIX_ISLAND_OUTCAST_ISLAND,
    MAP_SIX_ISLAND_GREEN_PATH,
    MAP_SEVEN_ISLAND_TRAINER_TOWER,
};

static const struct RenewableHiddenItemData sRenewableHiddenItemsFlags[] = {
    {
        .rare = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .uncommon = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_ROUTE20_STARDUST),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .common = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        }
    },
    {
        .rare = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .uncommon = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_ROUTE21_NORTH_PEARL),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .common = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        }
    },
    {
        .rare = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_ETHER),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .uncommon = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_POTION),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_ANTIDOTE),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_PARALYZE_HEAL),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_AWAKENING),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_BURN_HEAL),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL_ICE_HEAL),
            NO_ITEM,
            NO_ITEM
        },
        .common = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        }
    },
    {
        .rare = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_ETHER),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .uncommon = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_POTION),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_ANTIDOTE),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_PARALYZE_HEAL),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_AWAKENING),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_BURN_HEAL),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_UNDERGROUND_PATH_EAST_WEST_TUNNEL_ICE_HEAL),
            NO_ITEM,
            NO_ITEM
        },
        .common = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        }
    },
    {
        .rare = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_SEVEN_ISLAND_TANOBY_RUINS_HEART_SCALE_4),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_SEVEN_ISLAND_TANOBY_RUINS_HEART_SCALE),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_SEVEN_ISLAND_TANOBY_RUINS_HEART_SCALE_2),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_SEVEN_ISLAND_TANOBY_RUINS_HEART_SCALE_3),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .uncommon = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .common = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        }
    },
    {
        .rare = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_MT_MOON_B1F_TINY_MUSHROOM),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_MT_MOON_B1F_TINY_MUSHROOM_2),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_MT_MOON_B1F_TINY_MUSHROOM_3),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_MT_MOON_B1F_BIG_MUSHROOM),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_MT_MOON_B1F_BIG_MUSHROOM_2),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_MT_MOON_B1F_BIG_MUSHROOM_3),
            NO_ITEM,
            NO_ITEM
        },
        .uncommon = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_MT_MOON_B1F_TINY_MUSHROOM),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_MT_MOON_B1F_TINY_MUSHROOM_2),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_MT_MOON_B1F_TINY_MUSHROOM_3),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .common = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        }
    },
    {
        .rare = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_BLUK_BERRY),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_WEPEAR_BERRY),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_ORAN_BERRY),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_CHERI_BERRY),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_ASPEAR_BERRY),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_PERSIM_BERRY),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_PINAP_BERRY),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_LUM_BERRY),
        },
        .uncommon = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_BLUK_BERRY),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_WEPEAR_BERRY),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_ORAN_BERRY),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_CHERI_BERRY),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_ASPEAR_BERRY),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_PERSIM_BERRY),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_PINAP_BERRY),
            NO_ITEM
        },
        .common = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_RAZZ_BERRY),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_NANAB_BERRY),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_CHESTO_BERRY),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_PECHA_BERRY),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BERRY_FOREST_RAWST_BERRY),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        }
    },
    {
        .rare = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_ULTRA_BALL),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_ULTRA_BALL_2),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_STAR_PIECE),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_BIG_PEARL),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .uncommon = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_STARDUST),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_STARDUST_2),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_PEARL),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_PEARL_2),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_ULTRA_BALL),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_ULTRA_BALL_2),
            NO_ITEM,
            NO_ITEM
        },
        .common = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_ULTRA_BALL),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_ONE_ISLAND_TREASURE_BEACH_ULTRA_BALL_2),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        }
    },
    {
        .rare = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .uncommon = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BOND_BRIDGE_PEARL),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_THREE_ISLAND_BOND_BRIDGE_STARDUST),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .common = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        }
    },
    {
        .rare = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .uncommon = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_FOUR_ISLAND_PEARL),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .common = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_FOUR_ISLAND_ULTRA_BALL),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        }
    },
    {
        .rare = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_FIVE_ISLAND_MEMORIAL_PILLAR_BIG_PEARL),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .uncommon = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .common = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        }
    },
    {
        .rare = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_FIVE_ISLAND_RESORT_GORGEOUS_NEST_BALL),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_FIVE_ISLAND_RESORT_GORGEOUS_STAR_PIECE),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .uncommon = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_FIVE_ISLAND_RESORT_GORGEOUS_STARDUST),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_FIVE_ISLAND_RESORT_GORGEOUS_STARDUST_2),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .common = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        }
    },
    {
        .rare = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_SIX_ISLAND_OUTCAST_ISLAND_STAR_PIECE),
            HIDDEN_ID(FLAG_HIDDEN_ITEM_SIX_ISLAND_OUTCAST_ISLAND_NET_BALL),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .uncommon = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .common = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        }
    },
    {
        .rare = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .uncommon = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .common = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_SIX_ISLAND_GREEN_PATH_ULTRA_BALL),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        }
    },
    {
        .rare = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_SEVEN_ISLAND_TRAINER_TOWER_BIG_PEARL),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .uncommon = {
            HIDDEN_ID(FLAG_HIDDEN_ITEM_SEVEN_ISLAND_TRAINER_TOWER_PEARL),
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        },
        .common = {
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM,
            NO_ITEM
        }
    },
};

void SetAllRenewableItemFlags(void)
{
    for (u32 i = 0; i < ARRAY_COUNT(sRenewableHiddenItemsFlags); i++)
    {
        const u8 * rare = sRenewableHiddenItemsFlags[i].rare;
        const u8 * uncommon = sRenewableHiddenItemsFlags[i].uncommon;
        const u8 * common = sRenewableHiddenItemsFlags[i].common;
        for (u32 j = 0; j < MAX_HIDDEN_ITEMS_PER_GROUP; j++)
        {
            if (rare[j] != NO_ITEM)
                FlagSet(FLAG_HIDDEN_ITEMS_START + rare[j]);
            if (uncommon[j] != NO_ITEM)
                FlagSet(FLAG_HIDDEN_ITEMS_START + uncommon[j]);
            if (common[j] != NO_ITEM)
                FlagSet(FLAG_HIDDEN_ITEMS_START + common[j]);
        }
    }
}

void IncrementRenewableHiddenItemStepCounter(void)
{
    u16 stepCount = VarGet(VAR_RENEWABLE_ITEM_STEP_COUNTER);
    if (stepCount < RENEWABLE_ITEM_MAX_STEP_COUNT)
    {
        VarSet(VAR_RENEWABLE_ITEM_STEP_COUNTER, stepCount + 1);
    }
}

void TryRegenerateRenewableHiddenItems(void)
{
    u8 found_map = 0xFF;

    for (u32 i = 0; i < ARRAY_COUNT(sMapsWithRenewableItems); i++)
    {
        if (MAP_GROUP(sMapsWithRenewableItems[i]) == gSaveBlock1Ptr->location.mapGroup
         && MAP_NUM(sMapsWithRenewableItems[i]) == gSaveBlock1Ptr->location.mapNum)
            found_map = i;
    }

    if (found_map == 0xFF)
        return;
    if (VarGet(VAR_RENEWABLE_ITEM_STEP_COUNTER) >= RENEWABLE_ITEM_MAX_STEP_COUNT)
    {
        VarSet(VAR_RENEWABLE_ITEM_STEP_COUNTER, 0);
        SetAllRenewableItemFlags();
        SampleRenewableItemFlags();
    }
}

static void SampleRenewableItemFlags(void)
{
    const u8 * flags;
    u16 rval;

    for (u32 i = 0; i < ARRAY_COUNT(sRenewableHiddenItemsFlags); i++)
    {
        rval = RandomWeighted(RNG_HIDDEN_ITEM_REFRESH, 60, 30, 10);
        if (rval >= 90)
            flags = sRenewableHiddenItemsFlags[i].rare;
        else if (rval >= 60)
            flags = sRenewableHiddenItemsFlags[i].uncommon;
        else
            flags = sRenewableHiddenItemsFlags[i].common;
        for (u32 j = 0; j < MAX_HIDDEN_ITEMS_PER_GROUP; j++)
        {
            if (flags[j] != NO_ITEM)
                FlagClear(FLAG_HIDDEN_ITEMS_START + flags[j]);
        }
    }
}
