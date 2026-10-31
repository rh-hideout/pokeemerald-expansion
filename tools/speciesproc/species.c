#define TRUE  1
#define FALSE 0

#define SHADOW(a, b, c) .shadow = {.shadowXOffset = a, .shadowYOffset = b, .shadowSize = #c},
#define NO_SHADOW       .noshadow = TRUE,
#define FOOTPRINT(a)    .footprint = gMonFootprint_ ## a,

#define OVERWORLD(...)  .overworld = OVERWORLD_BASIC(__VA_ARGS__)
#define OVERWORLD_FEMALE(...)  .overworldF = OVERWORLD_BASIC(__VA_ARGS__)
#define OVERWORLD_PAL(...) .overworld = {OVER_PAL(__VA_ARGS__)},
#define OVERWORLD_PAL_FEMALE(...) .overworldF = {OVER_PAL(__VA_ARGS__)},

#define OVERWORLD_SHINYPAL(a, ...)  .shinyPal= #a
#define OVER_PAL(a, ...) .pal = #a __VA_OPT__(, OVERWORLD_SHINYPAL(__VA_ARGS__))
#define OVERWORLD_BASIC(a, b, c, d, e, ...) {.images = #a, .size = #b, .shadowSize = #c, .tracks = #d, .anims = #e __VA_OPT__(, OVER_PAL(__VA_ARGS__))},

#define _(x) x
#define MON_TYPES(a, ...) [#a __VA_OPT__(, #__VA_ARGS__)]
#define MON_EGG_GROUPS(group1, ...) [#group1 __VA_OPT__(, #__VA_ARGS__)]
#define EVOLUTION(...) [__VA_ARGS__]
#define CONDITIONS(...) {__VA_ARGS__}

#define ANIM_FRAMES(...) {__VA_ARGS__}
#define ANIMCMD_FRAME(a, b) "ANIMCMD_FRAME(" #a ", " #b ")"
#define ANIMCMD_LOOP(a)     "ANIMCMD_LOOP(" #a ")"
#define ANIMCMD_JUMP(a)     "ANIMCMD_JUMP(" #a ")"

#define COMPOUND_STRING(x) x

#define PERCENT_FEMALE(a) f(a)
#define MON_COORDS_SIZE(a, b) {.width = a, .height = b}


#include "config/general.h"
#include "config/pokemon.h"

#define __INTELLISENSE__ TRUE

#include "pokemon/species_info/gen_1_families.h"
#include "pokemon/species_info/gen_2_families.h"
#include "pokemon/species_info/gen_3_families.h"
#include "pokemon/species_info/gen_4_families.h"
#include "pokemon/species_info/gen_5_families.h"
#include "pokemon/species_info/gen_6_families.h"
#include "pokemon/species_info/gen_7_families.h"
#include "pokemon/species_info/gen_8_families.h"
#include "pokemon/species_info/gen_9_families.h"
