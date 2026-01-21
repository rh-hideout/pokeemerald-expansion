// src/ctf_flags.c
#include "global.h"
#include "ctf_flags.h"
#include "string_util.h"
#include "constants/characters.h"

// ============================================================================
// Central flag "library" (case-insensitive)
// ============================================================================
//
// Keep them <= PLAYER_NAME_LENGTH (usually 7) if you use the vanilla naming screen.
// You can write them in any case; comparison is case-insensitive.
//
// NOTE: This assumes your repo defines CHAR_A..CHAR_Z and CHAR_a..CHAR_z in
// include/constants/characters.h (standard in pokeemerald / expansion).

static const u8 sGymFlagWords[CTF_GYM_COUNT][PLAYER_NAME_LENGTH + 1] =
{
    _("SLEEP"),   // Gym 1
    _("DOZE"),    // Gym 2
    _("CIPHER"),  // Gym 3
    _("PACKET"),  // Gym 4
    _("STACK"),   // Gym 5
    _("HEAP"),    // Gym 6
    _("SHELL"),   // Gym 7
    _("ROOT"),    // Gym 8
};

static u8 Ctf_ToUpper(u8 c)
{
    // Convert a-z -> A-Z (Gen3 charmap bytes)
    if (c >= CHAR_a && c <= CHAR_z)
        return (u8)(c - (CHAR_a - CHAR_A));
    return c;
}

static void Ctf_Normalize(u8 *dst, const u8 *src)
{
    u32 i = 0;
    for (; i < PLAYER_NAME_LENGTH && src[i] != EOS; i++)
        dst[i] = Ctf_ToUpper(src[i]);

    dst[i] = EOS;
}

bool8 Ctf_IsGymFlagCorrect(u8 gymId, const u8 *input)
{
    // gymId is expected to be 1..CTF_GYM_COUNT
    if (gymId == 0 || gymId > CTF_GYM_COUNT)
        return FALSE;

    u8 normInput[PLAYER_NAME_LENGTH + 1];
    u8 normExpected[PLAYER_NAME_LENGTH + 1];

    Ctf_Normalize(normInput, input);
    Ctf_Normalize(normExpected, sGymFlagWords[gymId - 1]);

    return (StringCompare(normInput, normExpected) == 0);
}
