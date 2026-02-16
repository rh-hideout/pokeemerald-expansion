#include "global.h"
#include "battle_tower.h"
#include "event_data.h"
#include "test/test.h"
#include "constants/factory_pools.h"
#include "constants/flags.h"
#include "constants/species.h"

static void SetFactoryMechanicFlags(bool8 enabled)
{
    if (enabled)
    {
        FlagSet(FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION);
        FlagSet(FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION);
        FlagSet(FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES);
    }
    else
    {
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION);
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION);
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES);
    }
}

static bool8 SourceContainsSpecies(const u16 *pool, u16 poolCount, u16 species)
{
    for (u32 i = 0; i < poolCount; i++)
    {
        if (gBattleFrontierMons[pool[i]].species == species)
            return TRUE;
    }

    return FALSE;
}

static u16 CountUnionSpecies(const u16 *poolA, u16 poolACount, const u16 *poolB, u16 poolBCount, const u16 *poolC, u16 poolCCount)
{
    bool8 seen[NUM_SPECIES] = {FALSE};
    u16 count = 0;
    const u16 *pools[] = {poolA, poolB, poolC};
    const u16 counts[] = {poolACount, poolBCount, poolCCount};

    for (u32 p = 0; p < ARRAY_COUNT(pools); p++)
    {
        for (u32 i = 0; i < counts[p]; i++)
        {
            u16 species = gBattleFrontierMons[pools[p][i]].species;
            if (!seen[species])
            {
                seen[species] = TRUE;
                count++;
            }
        }
    }

    return count;
}

static void ExpectPoolIsUnionOfThreeSources(const u16 *generatedPool, u16 generatedCount, const u16 *poolA, u16 poolACount, const u16 *poolB, u16 poolBCount, const u16 *poolC, u16 poolCCount)
{
    bool8 sourceSpecies[NUM_SPECIES] = {FALSE};
    bool8 generatedSpecies[NUM_SPECIES] = {FALSE};
    const u16 *pools[] = {poolA, poolB, poolC};
    const u16 counts[] = {poolACount, poolBCount, poolCCount};

    for (u32 p = 0; p < ARRAY_COUNT(pools); p++)
    {
        for (u32 i = 0; i < counts[p]; i++)
            sourceSpecies[gBattleFrontierMons[pools[p][i]].species] = TRUE;
    }

    for (u32 i = 0; i < generatedCount; i++)
    {
        u16 species = gBattleFrontierMons[generatedPool[i]].species;
        EXPECT(species != SPECIES_NONE);
        EXPECT(sourceSpecies[species]);
        EXPECT(!generatedSpecies[species]);
        generatedSpecies[species] = TRUE;
    }

    EXPECT_EQ(generatedCount, CountUnionSpecies(poolA, poolACount, poolB, poolBCount, poolC, poolCCount));
}

TEST("Factory pools: rank 1 combines PU + ZU + NU")
{
    bool8 oldTera = FlagGet(FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION);
    bool8 oldMega = FlagGet(FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION);
    bool8 oldZ = FlagGet(FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES);
    u16 speciesFromPuNotInNu = SPECIES_NONE;

    SetFactoryMechanicFlags(TRUE);
    InitFactoryRankPools();

    for (u32 i = 0; i < FRONTIER_FACTORY_POOL_GEN9PU_COUNT; i++)
    {
        u16 species = gBattleFrontierMons[gFrontierFactoryPool_GEN9PU[i]].species;
        if (!SourceContainsSpecies(gFrontierFactoryPool_GEN9NU, FRONTIER_FACTORY_POOL_GEN9NU_COUNT, species))
        {
            speciesFromPuNotInNu = species;
            break;
        }
    }

    ASSUME(speciesFromPuNotInNu != SPECIES_NONE);
    EXPECT(SourceContainsSpecies(sFactoryPoolRank1, gFactoryPoolRank1Count, speciesFromPuNotInNu));

    ExpectPoolIsUnionOfThreeSources(
        sFactoryPoolRank1,
        gFactoryPoolRank1Count,
        gFrontierFactoryPool_GEN9PU,
        FRONTIER_FACTORY_POOL_GEN9PU_COUNT,
        gFrontierFactoryPool_GEN9ZU,
        FRONTIER_FACTORY_POOL_GEN9ZU_COUNT,
        gFrontierFactoryPool_GEN9NU,
        FRONTIER_FACTORY_POOL_GEN9NU_COUNT
    );

    SetFactoryMechanicFlags(TRUE);
    if (!oldTera)
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION);
    if (!oldMega)
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION);
    if (!oldZ)
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES);
}

TEST("Factory pools: rank 2 combines NU + RU + National Dex RU")
{
    bool8 oldTera = FlagGet(FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION);
    bool8 oldMega = FlagGet(FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION);
    bool8 oldZ = FlagGet(FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES);

    SetFactoryMechanicFlags(TRUE);
    InitFactoryRankPools();

    ExpectPoolIsUnionOfThreeSources(
        sFactoryPoolRank2,
        gFactoryPoolRank2Count,
        gFrontierFactoryPool_GEN9NU,
        FRONTIER_FACTORY_POOL_GEN9NU_COUNT,
        gFrontierFactoryPool_GEN9RU,
        FRONTIER_FACTORY_POOL_GEN9RU_COUNT,
        gFrontierFactoryPool_GEN9NATIONALDEXRU,
        FRONTIER_FACTORY_POOL_GEN9NATIONALDEXRU_COUNT
    );

    SetFactoryMechanicFlags(TRUE);
    if (!oldTera)
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION);
    if (!oldMega)
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION);
    if (!oldZ)
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES);
}

TEST("Factory pools: rank 3 combines RU + UU + National Dex UU")
{
    bool8 oldTera = FlagGet(FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION);
    bool8 oldMega = FlagGet(FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION);
    bool8 oldZ = FlagGet(FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES);

    SetFactoryMechanicFlags(TRUE);
    InitFactoryRankPools();

    ExpectPoolIsUnionOfThreeSources(
        sFactoryPoolRank3,
        gFactoryPoolRank3Count,
        gFrontierFactoryPool_GEN9RU,
        FRONTIER_FACTORY_POOL_GEN9RU_COUNT,
        gFrontierFactoryPool_GEN9UU,
        FRONTIER_FACTORY_POOL_GEN9UU_COUNT,
        gFrontierFactoryPool_GEN9NATIONALDEXUU,
        FRONTIER_FACTORY_POOL_GEN9NATIONALDEXUU_COUNT
    );

    SetFactoryMechanicFlags(TRUE);
    if (!oldTera)
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION);
    if (!oldMega)
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION);
    if (!oldZ)
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES);
}

TEST("Factory pools: rank 4 combines UU + OU + National Dex")
{
    bool8 oldTera = FlagGet(FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION);
    bool8 oldMega = FlagGet(FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION);
    bool8 oldZ = FlagGet(FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES);

    SetFactoryMechanicFlags(TRUE);
    InitFactoryRankPools();

    ExpectPoolIsUnionOfThreeSources(
        sFactoryPoolRank4,
        gFactoryPoolRank4Count,
        gFrontierFactoryPool_GEN9UU,
        FRONTIER_FACTORY_POOL_GEN9UU_COUNT,
        gFrontierFactoryPool_GEN9OU,
        FRONTIER_FACTORY_POOL_GEN9OU_COUNT,
        gFrontierFactoryPool_GEN9NATIONALDEX,
        FRONTIER_FACTORY_POOL_GEN9NATIONALDEX_COUNT
    );

    SetFactoryMechanicFlags(TRUE);
    if (!oldTera)
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_TERASTALLISATION);
    if (!oldMega)
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_MEGA_EVOLUTION);
    if (!oldZ)
        FlagClear(FLAG_BATTLE_FACTORY_ALLOW_Z_MOVES);
}