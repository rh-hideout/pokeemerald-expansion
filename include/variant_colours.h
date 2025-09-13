#include "global.h"
#include "constants/species.h"

struct PaletteVariant
{
  u8 start : 4;        // Start index of palette customisation range
  u8 length : 4;       // Length of customisation range
  u8 hue_amount : 3;   // Index into hue table [0,10,20,30,45,60,90,180]
  u8 chr_amount : 2;   // Index into chroma table [0,5,10,25]
  u8 lum_amount : 2;   // Index into luma table [0,5,10,25]
  u8 sv_down_only : 1; // If set, switch from +/- to "down only" for both C & L (C: -2*chr, L: -2*lum)
};

struct SpeciesVariant
{
  struct PaletteVariant pv1;
  struct PaletteVariant pv2;
};

// Precomputed hue-amount table
// Code uses hue in [0..255] instead of [0..360]
// {0,10,20,30,45,60,90,180} -> {0,7,14,21,32,43,64,128}
static const u8 sHueTable[8] = {0, 7, 14, 21, 32, 43, 64, 128};
static const u8 sCLTable[4] = {0, 5, 10, 25};

// return variant data or return default if species has no variants.
const struct SpeciesVariant *GetSpeciesVariants(u32 species);

void ApplyPaletteVariantToPaletteBuffer(u16 pal16[16], const struct PaletteVariant *pv, u16 prn16);
void ApplyCustomRestrictionToPalletteBuffer(u8 hMin, u8 hMax, u8 cMin, u8 cMax, u8 lMin, u8 lMax, u16 pal16[16]);
void ApplyMonSpeciesVariantToPaletteBuffer(u32 species, bool8 shiny, u32 PID, u16 pal16[16]);

// Species data helpers

#define HUE_INDEX(h) (            \
    ((h) == 0 ? 0 : (h) <= 10 ? 1 \
                : (h) <= 20   ? 2 \
                : (h) <= 30   ? 3 \
                : (h) <= 45   ? 4 \
                : (h) <= 60   ? 5 \
                : (h) <= 90   ? 6 \
                : /*(h)==180*/ 7))

#define CHR_INDEX(s) (           \
    ((s) == 0 ? 0 : (s) <= 5 ? 1 \
                : (s) <= 10  ? 2 \
                : /*(s)==25*/ 3))

#define LUM_INDEX(v) ( \
    ((v) == 0 ? 0      \
    : (v) <= 5 ? 1     \
    : (v) <= 10  ? 2   \
    : /*(v)==25*/ 3))

#define PAL1(s, l)  \
  .pv1.start = (s), \
  .pv1.length = (l)

#define PAL2(s, l)  \
  .pv2.start = (s), \
  .pv2.length = (l)

#define HCL1(h, s, v, f)          \
  .pv1.hue_amount = HUE_INDEX(h), \
  .pv1.chr_amount = CHR_INDEX(s), \
  .pv1.lum_amount = LUM_INDEX(v), \
  .pv1.sv_down_only = (f)

#define HCL2(h, s, v, f)          \
  .pv2.hue_amount = HUE_INDEX(h), \
  .pv2.chr_amount = CHR_INDEX(s), \
  .pv2.lum_amount = LUM_INDEX(v), \
  .pv2.sv_down_only = (f)

#define DEFAULT_SPECIES_VARIANT \
  {                             \
      PAL1(1, 15),              \
      HCL1(10, 0, 0, FALSE),    \
  }

static const struct SpeciesVariant gSpeciesVariants[NUM_SPECIES] = {
    [SPECIES_POOCHYENA] = {
        PAL1(1, 5),
        HCL1(0, 25, 5, FALSE),
    },
    [SPECIES_MIGHTYENA] = {
        PAL1(1, 5),
        HCL1(0, 25, 5, FALSE),
    },
    [SPECIES_ZIGZAGOON] = {
        PAL1(5, 8),
        HCL1(10, 25, 5, FALSE),
    },
    [SPECIES_LINOONE] = {
        PAL1(1, 3),
        HCL1(10, 25, 5, FALSE),
    },
    [SPECIES_WURMPLE] = {
        PAL1(1, 4),
        HCL1(30, 5, 0, TRUE),
    },
    [SPECIES_SMEARGLE] = {
        PAL1(8, 6),
        HCL1(360, 0, 0, FALSE),
        PAL2(1, 6),
        HCL2(10, 5, 5, TRUE),
    },
        [SPECIES_TYRANITAR] = {
      PAL1(11, 3),
      HCL1(30, 25, 0, TRUE),
      PAL2(1, 5),
      HCL2(0, 0, 10, FALSE),
    },
};
