// src/ctf_flags.c
#include "global.h"
#include "ctf_flags.h"
#include "string_util.h"
#include "constants/characters.h"

static const u8 sFlagWords[CTF_FLAG_COUNT][PLAYER_NAME_LENGTH + 1] =
{

// ACHTUNG: Die Flags müssen <=7 lang sein!
    _("ALGEBRA"),   // 1 Gym 1
    _("DOZE"),    // 2 Gym 2
    _("5864"),  // 3 Gym 3
    _("PACKET"),  // 4 Gym 4
    _("STACK"),   // 5 Gym 5
    _("SLEEP"),    // 6 Gym 6
    _("SHELL"),   // 7 Gym 7
    _("ROOT"),    // 8 Gym 8
    _("BANG"),   // 9 Tutorial
    _("RKTSNC"), // 10 Finale Farmer
};

static u8 Ctf_ToUpper(u8 c)
{
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

bool8 Ctf_IsFlagCorrect(u8 flagId, const u8 *input)
{
    if (flagId == 0 || flagId > CTF_FLAG_COUNT)
        return FALSE;

    u8 normInput[PLAYER_NAME_LENGTH + 1];
    u8 normExpected[PLAYER_NAME_LENGTH + 1];

    Ctf_Normalize(normInput, input);
    Ctf_Normalize(normExpected, sFlagWords[flagId - 1]);

    return (StringCompare(normInput, normExpected) == 0);
}

bool8 Ctf_IsGymFlagCorrect(u8 gymId, const u8 *input)
{
    if (gymId == 0 || gymId > CTF_GYM_COUNT)
        return FALSE;
    return Ctf_IsFlagCorrect(gymId, input);
}

void Ctf_GetFlagWordUpper(u8 flagId, u8 *dst, u32 dstSize)
{
    if (dstSize == 0)
        return;

    dst[0] = EOS;

    if (flagId == 0 || flagId > CTF_FLAG_COUNT)
        return;

    // Ziel ist PLAYER_NAME_LENGTH+1 groß, wir schreiben sicherheitshalber begrenzt
    // Normalisierung macht bereits EOS am Ende.
    Ctf_Normalize(dst, sFlagWords[flagId - 1]);

    // Falls dstSize kleiner ist, hart terminieren
    if (dstSize <= PLAYER_NAME_LENGTH)
        dst[dstSize - 1] = EOS;
}


