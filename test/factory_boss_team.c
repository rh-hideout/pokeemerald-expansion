#include "global.h"
#include "factory_boss_team.h"
#include "test/test.h"
#include "constants/factory_boss.h"
#include "constants/items.h"
#include "constants/pokemon.h"

static void InitRentals(struct RentalMon *rentals)
{
    s32 i;
    for (i = 0; i < FRONTIER_PARTY_SIZE * 2; i++)
        rentals[i].monId = 0xFFFF;
}

TEST("Factory boss team: rejects ace candidates that are Unown")
{
    struct TrainerMon mons[2] = {0};
    struct RentalMon rentals[FRONTIER_PARTY_SIZE * 2] = {0};
    u16 species[FRONTIER_PARTY_SIZE] = {SPECIES_BULBASAUR, SPECIES_CHARMANDER, SPECIES_SQUIRTLE};
    u16 heldItems[FRONTIER_PARTY_SIZE] = {ITEM_LEFTOVERS, ITEM_LIFE_ORB, ITEM_NONE};

    mons[0].species = SPECIES_UNOWN;
    mons[0].heldItem = ITEM_FOCUS_SASH;
    InitRentals(rentals);

    EXPECT_EQ(FactoryBossCanUseAceMonIdForSlot(mons, rentals, 0, 2, species, heldItems), FALSE);
}

TEST("Factory boss team: rejects ace candidates already present in rentals")
{
    struct TrainerMon mons[2] = {0};
    struct RentalMon rentals[FRONTIER_PARTY_SIZE * 2] = {0};
    u16 species[FRONTIER_PARTY_SIZE] = {SPECIES_BULBASAUR, SPECIES_CHARMANDER, SPECIES_SQUIRTLE};
    u16 heldItems[FRONTIER_PARTY_SIZE] = {ITEM_LEFTOVERS, ITEM_LIFE_ORB, ITEM_NONE};

    mons[1].species = SPECIES_METAGROSS;
    mons[1].heldItem = ITEM_METAGROSSITE;
    InitRentals(rentals);
    rentals[0].monId = 1;

    EXPECT_EQ(FactoryBossCanUseAceMonIdForSlot(mons, rentals, 1, 2, species, heldItems), FALSE);
}

TEST("Factory boss team: rejects duplicate species and duplicate held item conflicts")
{
    struct TrainerMon mons[3] = {0};
    struct RentalMon rentals[FRONTIER_PARTY_SIZE * 2] = {0};
    u16 species[FRONTIER_PARTY_SIZE] = {SPECIES_METAGROSS, SPECIES_CHARMANDER, SPECIES_SQUIRTLE};
    u16 heldItems[FRONTIER_PARTY_SIZE] = {ITEM_LEFTOVERS, ITEM_LIFE_ORB, ITEM_NONE};

    InitRentals(rentals);
    mons[1].species = SPECIES_METAGROSS;
    mons[1].heldItem = ITEM_METAGROSSITE;
    EXPECT_EQ(FactoryBossCanUseAceMonIdForSlot(mons, rentals, 1, 2, species, heldItems), FALSE);

    species[0] = SPECIES_BULBASAUR;
    mons[2].species = SPECIES_METAGROSS;
    mons[2].heldItem = ITEM_LEFTOVERS;
    EXPECT_EQ(FactoryBossCanUseAceMonIdForSlot(mons, rentals, 2, 2, species, heldItems), FALSE);
}

TEST("Factory boss team: accepts a valid ace candidate")
{
    struct TrainerMon mons[2] = {0};
    struct RentalMon rentals[FRONTIER_PARTY_SIZE * 2] = {0};
    u16 species[FRONTIER_PARTY_SIZE] = {SPECIES_BULBASAUR, SPECIES_CHARMANDER, SPECIES_SQUIRTLE};
    u16 heldItems[FRONTIER_PARTY_SIZE] = {ITEM_LEFTOVERS, ITEM_LIFE_ORB, ITEM_NONE};

    InitRentals(rentals);
    mons[1].species = SPECIES_METAGROSS;
    mons[1].heldItem = ITEM_METAGROSSITE;
    EXPECT_EQ(FactoryBossCanUseAceMonIdForSlot(mons, rentals, 1, 2, species, heldItems), TRUE);
}

TEST("Factory boss team: chooser returns matching ace mon when exactly one valid candidate exists")
{
    struct TrainerMon mons[4] = {0};
    struct RentalMon rentals[FRONTIER_PARTY_SIZE * 2] = {0};
    struct FactoryBossProfile bossProfile = {0};
    u16 aceMonId;

    InitRentals(rentals);
    mons[0].species = SPECIES_BULBASAUR;
    mons[1].species = SPECIES_METAGROSS;
    mons[2].species = SPECIES_CHARMANDER;
    mons[3].species = SPECIES_SQUIRTLE;

    bossProfile.aceSpecies = SPECIES_METAGROSS;

    aceMonId = ChooseFactoryBossAceMonIdInRange(&bossProfile, mons, rentals, 0, 3);
    EXPECT_EQ(aceMonId, 1);
}

TEST("Factory boss team: chooser returns none when candidate is blocked by rentals")
{
    struct TrainerMon mons[3] = {0};
    struct RentalMon rentals[FRONTIER_PARTY_SIZE * 2] = {0};
    struct FactoryBossProfile bossProfile = {0};
    u16 aceMonId;

    InitRentals(rentals);
    mons[0].species = SPECIES_BULBASAUR;
    mons[1].species = SPECIES_METAGROSS;
    mons[2].species = SPECIES_CHARMANDER;
    rentals[0].monId = 1;

    bossProfile.aceSpecies = SPECIES_METAGROSS;

    aceMonId = ChooseFactoryBossAceMonIdInRange(&bossProfile, mons, rentals, 0, 2);
    EXPECT_EQ(aceMonId, 0xFFFF);
}
