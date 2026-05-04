#ifndef GUARD_RANDOM_MON_GENERATION_H
#define GUARD_RANDOM_MON_GENERATION_H

#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokeball.h"
#include "constants/species.h"

void ResolveRandomMonGeneration(enum Species *species, enum Item *item, enum PokeBall *ball, enum Move *moves);

#endif // GUARD_RANDOM_MON_GENERATION_H
