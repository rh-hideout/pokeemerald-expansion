#include "global.h"
#include "test/battle.h"
#include "palette.h"

// Palette offset computed from an IndexOfSpritePaletteTag miss (0xFF),
// out of bounds of gPlttBufferFaded.
#define OOB_PLTT_INDEX (0xFF * 16 + OBJ_PLTT_OFFSET)

static u16 sMemoryBeforeAnim[16];

SINGLE_BATTLE_TEST("Night Slash's palette blend does not write out of bounds (#10584)")
{
    u32 j;
    u32 corruptedEntries = 0;
    // Computed through uintptr_t so -Warray-bounds does not flag the
    // deliberately out-of-bounds address being watched.
    volatile u16 *oob = (u16 *)((uintptr_t)gPlttBufferFaded + OOB_PLTT_INDEX * sizeof(u16));

    FORCE_MOVE_ANIM(TRUE);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        for (j = 0; j < ARRAY_COUNT(sMemoryBeforeAnim); j++)
            sMemoryBeforeAnim[j] = oob[j];
        TURN { MOVE(player, MOVE_NIGHT_SLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_NIGHT_SLASH, player);
    } THEN {
        FORCE_MOVE_ANIM(FALSE);
        for (j = 0; j < ARRAY_COUNT(sMemoryBeforeAnim); j++)
        {
            if (oob[j] != sMemoryBeforeAnim[j])
                corruptedEntries++;
        }
        EXPECT_EQ(corruptedEntries, 0);
    }
}
