#include "global.h"
#include "string_util.h"
#include "pentara_ui.h"

// Moves are shown with a star rating and an accuracy word instead of numbers,
// so players read "how hard does it hit" at a glance.

static const u8 sText_Star[] = _("{STAR}");
static const u8 sText_Support[] = _("Support");
static const u8 sText_Varies[] = _("Varies");
static const u8 sText_SureHit[] = _("Sure-hit");
static const u8 sText_Reliable[] = _("Reliable");
static const u8 sText_Steady[] = _("Steady");
static const u8 sText_Risky[] = _("Risky");
static const u8 sText_Wild[] = _("Wild");

u8 *Pentara_BufferPowerRating(u8 *dst, u32 power)
{
    u32 stars, i;

    if (power == 0)
        return StringCopy(dst, sText_Support);
    if (power == 1)
        return StringCopy(dst, sText_Varies);

    if (power <= 40)
        stars = 1;
    else if (power <= 60)
        stars = 2;
    else if (power <= 80)
        stars = 3;
    else if (power <= 100)
        stars = 4;
    else
        stars = 5;

    for (i = 0; i < stars; i++)
        dst = StringCopy(dst, sText_Star);
    return dst;
}

const u8 *Pentara_AccuracyWord(u32 accuracy)
{
    if (accuracy == 0)
        return sText_SureHit;
    if (accuracy >= 100)
        return sText_Reliable;
    if (accuracy >= 90)
        return sText_Steady;
    if (accuracy >= 75)
        return sText_Risky;
    return sText_Wild;
}
