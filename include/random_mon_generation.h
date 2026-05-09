#ifndef GUARD_RANDOM_MON_GENERATION_H
#define GUARD_RANDOM_MON_GENERATION_H

#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokeball.h"
#include "constants/species.h"

enum Species GetRandomSpecies(u32 optionId, u16 arg1, u16 arg2);
enum Item GetRandomItem(u32 optionId);
void ResolveRandomMonGeneration(enum Species species, enum PokeBall *ball, enum Move *moves);

#endif // GUARD_RANDOM_MON_GENERATION_H
