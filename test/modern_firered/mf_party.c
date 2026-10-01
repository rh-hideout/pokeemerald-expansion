#include "global.h"
#include "mf_party.h"
#include "test/test.h"

TEST("MF: party limit resolves ME menu indices to max party size")
{
    EXPECT_EQ(MfResolveMaxPartySize(0), 6); // Off
    EXPECT_EQ(MfResolveMaxPartySize(1), 5);
    EXPECT_EQ(MfResolveMaxPartySize(2), 4);
    EXPECT_EQ(MfResolveMaxPartySize(3), 3);
    EXPECT_EQ(MfResolveMaxPartySize(4), 2);
    EXPECT_EQ(MfResolveMaxPartySize(5), 1);
    // 3-bit field can hold 6/7 — clamp to solo rather than size 0.
    EXPECT_EQ(MfResolveMaxPartySize(6), 1);
    EXPECT_EQ(MfResolveMaxPartySize(7), 1);
}

TEST("MF: party count at limit")
{
    EXPECT(!MfIsPartyCountAtLimit(0, 3));
    EXPECT(!MfIsPartyCountAtLimit(2, 3));
    EXPECT(MfIsPartyCountAtLimit(3, 3));
    EXPECT(MfIsPartyCountAtLimit(4, 3));
    EXPECT(!MfIsPartyCountAtLimit(5, 6));
    EXPECT(MfIsPartyCountAtLimit(6, 6));
}
