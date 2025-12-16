#include "global.h"
#include "test/test.h"

TEST("Tests resume after CRASH")
{
    KNOWN_CRASHING;
    void (*f)(void) = NULL;
    f();
}

TEST("EXPECT_FAIL allows expected failing tests to pass")
{
    EXPECT_FAIL;
    EXPECT_EQ(1, 2);
}
