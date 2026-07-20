#include "global.h"
#include "config/habitat.h"
#include "field_player_avatar.h"
#include "overworld.h"
#include "constants/event_objects.h"
#include "constants/species.h"
#include "test/test.h"

TEST("Habitat player presentation: every avatar state uses the existing Zorua follower graphics")
{
    u8 state;
    u8 gender;
    static const u8 sAvatarFlags[] =
    {
        PLAYER_AVATAR_FLAG_ON_FOOT,
        PLAYER_AVATAR_FLAG_MACH_BIKE,
        PLAYER_AVATAR_FLAG_ACRO_BIKE,
        PLAYER_AVATAR_FLAG_SURFING,
        PLAYER_AVATAR_FLAG_UNDERWATER,
    };

    EXPECT(HABITAT_ZORUA_PRESENTATION);
    for (state = PLAYER_AVATAR_STATE_NORMAL; state <= PLAYER_AVATAR_STATE_VSSEEKER; state++)
    {
        EXPECT_EQ(GetPlayerAvatarGraphicsIdByStateIdAndGender(state, MALE), OBJ_EVENT_GFX_SPECIES(ZORUA));
        EXPECT_EQ(GetPlayerAvatarGraphicsIdByStateIdAndGender(state, FEMALE), OBJ_EVENT_GFX_SPECIES(ZORUA));
    }

    for (gender = MALE; gender <= FEMALE; gender++)
    {
        u8 flag;

        gPlayerAvatar.gender = gender;
        for (flag = 0; flag < ARRAY_COUNT(sAvatarFlags); flag++)
        {
            gPlayerAvatar.flags = sAvatarFlags[flag];
            EXPECT_EQ(GetPlayerAvatarGraphicsIdByCurrentState(), OBJ_EVENT_GFX_SPECIES(ZORUA));
        }
    }
}

TEST("Habitat player presentation: new games use the approved lab slice spawn")
{
    EXPECT(HABITAT_SLICE_SPAWN);
    EXPECT(HABITAT_ZORUA_ON_FOOT_ONLY);
}
