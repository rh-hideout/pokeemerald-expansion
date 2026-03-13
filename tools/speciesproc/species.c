#define TRUE  1
#define FALSE 0

#define SHADOW(a, b, c) .shadow = {a, b, c},
#define FOOTPRINT(a)    .footprint = a,
#define OVERWORLD(...)  .overworld =  {__VA_ARGS__},
#define OVERWORLD_FEMALE(...)  .overworldF =  {__VA_ARGS__},

#include "config/general.h"
#include "config/pokemon.h"


#include "pokemon/species_info/gen_1_families.h"
#include "pokemon/species_info/gen_2_families.h"
#include "pokemon/species_info/gen_3_families.h"
#include "pokemon/species_info/gen_4_families.h"
#include "pokemon/species_info/gen_5_families.h"
#include "pokemon/species_info/gen_6_families.h"
#include "pokemon/species_info/gen_7_families.h"
#include "pokemon/species_info/gen_8_families.h"
#include "pokemon/species_info/gen_9_families.h"