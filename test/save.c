#include "global.h"
#include "pokemon_storage_system.h"
#include "test/test.h"

// If you would like to ensure save compatibility, update the values below with those for your hack. You can find these through the debug menu.
// Please note that this simple check is not 100% foolproof, but should be able to catch most unintended shifts.
#define T_SAVEBLOCK1_SIZE 15568
#define T_SAVEBLOCK2_SIZE 3884
#define T_SAVEBLOCK3_SIZE 4
#define T_POKEMONSTORAGE_SIZE 34144

TEST("SaveBlock1 is backwards compatible")
{
    EXPECT_EQ(sizeof(struct SaveBlock1), T_SAVEBLOCK1_SIZE);
}

TEST("SaveBlock2 is backwards compatible")
{
    EXPECT_EQ(sizeof(struct SaveBlock2), T_SAVEBLOCK2_SIZE);
}

TEST("SaveBlock3 is backwards compatible")
{
    EXPECT_EQ(sizeof(struct SaveBlock3), T_SAVEBLOCK3_SIZE);
}

TEST("PokemonStorage is backwards compatible")
{
    EXPECT_EQ(sizeof(struct PokemonStorage), T_POKEMONSTORAGE_SIZE);
}

// TODO: It would be nice to target 2 frames for this.
TEST("Encrypting and decrypting the save costs less than 3 frames")
{
    // Performance is affected by 'PID % 24' so assign them.
    u32 personality = 0;
    for (u32 i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (u32 j = 0; j < IN_BOX_COUNT; j++)
        {
            gPokemonStoragePtr->boxes[i][j].personality = personality++;
            gPokemonStoragePtr->boxes[i][j].hasSpecies = TRUE;
        }
    }

    struct Benchmark encDec;
    BENCHMARK(&encDec)
    {
        EncryptSave();
        DecryptSave();
    }
    EXPECT_LE(encDec.ticks, 3 * FRAME_TICKS);
}

#undef T_SAVEBLOCK1_SIZE
#undef T_SAVEBLOCK2_SIZE
#undef T_SAVEBLOCK3_SIZE
#undef T_POKEMONSTORAGE_SIZE
