// src/ctf_flags.c
#include "global.h"
#include <string.h>

#include "ctf_flags.h"
#include "string_util.h"
#include "constants/characters.h"

#define CTF_STATIC_FLAG_COUNT CTF_FLAG_TUTORIAL

static const u8 sFlagWords[CTF_STATIC_FLAG_COUNT][PLAYER_NAME_LENGTH + 1] =
{
    // ACHTUNG: Die Flags müssen <=7 lang sein!
    _("ALGEBRA"),   // 1 Gym 1
    _("DOZE"),     // 2 Gym 2
    _("CIPHER"),   // 3 Gym 3
    _("PACKET"),   // 4 Gym 4
    _("STACK"),    // 5 Gym 5
    _("SLEEP"),    // 6 Gym 6
    _("SHELL"),    // 7 Gym 7
    _("ROOT"),     // 8 Gym 8
    _("BANG"),     // 9 Tutorial
};

#define ENROLLMENT_INPUT_BUFFER  (PLAYER_NAME_LENGTH + 16)
#define ENROLLMENT_CODE_STR_SIZE 9

static u8 CharmapToAscii(u8 c)
{
    if (c >= CHAR_A && c <= CHAR_Z)
        return 'A' + (c - CHAR_A);
    if (c >= CHAR_a && c <= CHAR_z)
        return 'a' + (c - CHAR_a);
    if (c >= CHAR_0 && c <= CHAR_9)
        return '0' + (c - CHAR_0);

    switch (c)
    {
    case CHAR_SPACE: return ' ';
    case CHAR_PERIOD: return '.';
    case CHAR_COMMA: return ',';
    case CHAR_EXCL_MARK: return '!';
    case CHAR_QUESTION_MARK: return '?';
    case CHAR_HYPHEN: return '-';
    case CHAR_SGL_QUOTE_RIGHT: return '\'';
    case CHAR_DBL_QUOTE_LEFT:
    case CHAR_DBL_QUOTE_RIGHT: return '\"';
    case CHAR_SLASH: return '/';
    case CHAR_LEFT_PAREN: return '(';
    case CHAR_RIGHT_PAREN: return ')';
    case CHAR_PLUS: return '+';
    case CHAR_COLON: return ':';
    case CHAR_SEMICOLON: return ';';
    case CHAR_UNDERSCORE: return '_';
    default: return '?';
    }
}

static void GameStringToAscii(const u8 *src, u8 *dst, u32 dstSize)
{
    u32 pos = 0;

    if (dstSize == 0)
        return;

    while (*src != EOS && pos + 1 < dstSize)
    {
        if (*src == EXT_CTRL_CODE_BEGIN)
        {
            src++;
            if (*src == EOS)
                break;
            src += GetExtCtrlCodeLength(*src);
            continue;
        }
        dst[pos++] = CharmapToAscii(*src++);
    }

    dst[pos] = '\0';
}

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

static u32 AppendDecimalString(u32 value, u8 *dst, u32 dstSize)
{
    u8 digits[10];
    u32 count = 0;

    if (dstSize == 0)
        return 0;

    if (value == 0)
        digits[count++] = '0';
    else
    {
        while (value > 0)
        {
            digits[count++] = '0' + (value % 10);
            value /= 10;
        }
    }

    for (u32 i = 0; i < count && i + 1 <= dstSize; i++)
        dst[i] = digits[count - 1 - i];

    if (count >= dstSize)
        return dstSize;

    return count;
}

// Builds the byte sequence used by the enrollment code hash.
// Equivalent to Python's `f"{trainer_id}{name}".encode("utf-8")`.
static u32 BuildEnrollmentInput(u8 *dst, u32 dstSize)
{
    u32 pos = 0;
    u32 trainerId = (gSaveBlock2Ptr->playerTrainerId[1] << 8)
                  | gSaveBlock2Ptr->playerTrainerId[0];

    if (dstSize == 0)
        return 0;

    if (pos < dstSize)
        pos += AppendDecimalString(trainerId, dst + pos, dstSize - pos);

    if (pos < dstSize)
    {
        u8 nameAscii[PLAYER_NAME_LENGTH + 1];
        GameStringToAscii(gSaveBlock2Ptr->playerName, nameAscii, sizeof(nameAscii));
        for (u32 i = 0; nameAscii[i] != '\0' && pos < dstSize; i++)
            dst[pos++] = nameAscii[i];
    }

    return pos;
}

static u32 GetEnrollmentCode(void)
{
    u8 buffer[ENROLLMENT_INPUT_BUFFER];
    u32 len = BuildEnrollmentInput(buffer, sizeof(buffer));
    u32 x = 0;

    for (u32 i = 0; i < len; i++)
    {
        u32 b = buffer[i];
        x ^= b;
        x ^= (x << 3) & 0xFFFFFFFF;
        x ^= (x >> 5);
    }

    x &= 0xFFFFFFFF;
    return 1000000 + (x % 9000000);
}

static void EnrollmentCodeToAscii(u32 code, u8 *dst, u32 dstSize)
{
    u8 digits[10];
    u32 count = 0;

    while (code > 0 && count < ARRAY_COUNT(digits))
    {
        digits[count++] = '0' + (code % 10);
        code /= 10;
    }

    if (count == 0)
        digits[count++] = '0';

    u32 pos = 0;
    while (count > 0 && pos + 1 < dstSize)
        dst[pos++] = digits[--count];

    dst[pos] = '\0';
}

static void InputToAscii(const u8 *src, u8 *dst, u32 dstSize)
{
    u32 pos = 0;

    if (dstSize == 0)
        return;

    while (*src != EOS && pos + 1 < dstSize)
    {
        if (*src == EXT_CTRL_CODE_BEGIN)
        {
            src++;
            if (*src == EOS)
                break;
            src += GetExtCtrlCodeLength(*src);
            continue;
        }

        dst[pos++] = CharmapToAscii(*src++);
    }

    dst[pos] = '\0';
}

static bool8 IsEnrollmentCodeCorrect(const u8 *input)
{
    u8 expected[ENROLLMENT_CODE_STR_SIZE];
    u8 attempt[ENROLLMENT_CODE_STR_SIZE];

    EnrollmentCodeToAscii(GetEnrollmentCode(), expected, sizeof(expected));
    InputToAscii(input, attempt, sizeof(attempt));

    if (attempt[0] == '\0')
        return FALSE;

    return (strcmp((char *)attempt, (char *)expected) == 0);
}

bool8 Ctf_IsFlagCorrect(u8 flagId, const u8 *input)
{
    if (flagId == 0 || flagId > CTF_FLAG_COUNT)
        return FALSE;

    if (flagId == CTF_FLAG_ENROLLMENT)
        return IsEnrollmentCodeCorrect(input);

    if (flagId > CTF_STATIC_FLAG_COUNT)
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

    if (flagId == CTF_FLAG_ENROLLMENT)
        return;

    if (flagId > CTF_STATIC_FLAG_COUNT)
        return;

    // Ziel ist PLAYER_NAME_LENGTH+1 groß, wir schreiben sicherheitshalber begrenzt
    // Normalisierung macht bereits EOS am Ende.
    Ctf_Normalize(dst, sFlagWords[flagId - 1]);

    // Falls dstSize kleiner ist, hart terminieren
    if (dstSize <= PLAYER_NAME_LENGTH)
        dst[dstSize - 1] = EOS;
}

void Ctf_GetFlagSolutionString(u8 flagId, u8 *dst, u32 dstSize)
{
    if (dstSize == 0)
        return;

    dst[0] = EOS;

    if (flagId == 0 || flagId > CTF_FLAG_COUNT)
        return;

    if (flagId == CTF_FLAG_ENROLLMENT)
    {
        ConvertIntToDecimalStringN(dst, GetEnrollmentCode(), STR_CONV_MODE_LEFT_ALIGN, ENROLLMENT_CODE_STR_SIZE - 1);
        return;
    }

    if (flagId > CTF_STATIC_FLAG_COUNT)
        return;

    Ctf_GetFlagWordUpper(flagId, dst, dstSize);
}
