#ifndef GUARD_EVOLUTION_PARAMS_H
#define GUARD_EVOLUTION_PARAMS_H

struct EvolutionData;

bool32 CheckEvolutionCondition(struct BoxPokemon *boxmon, struct EvolutionData *evo, const struct EvolutionParam *param);
void AppendEvoParamString(u8 *dst, const struct EvolutionParam *param);
void AfterEvolutionParamCallback(struct BoxPokemon *boxmon, bool32 wasInterrupted, const struct EvolutionParam *param);

#endif // GUARD_EVOLUTION_PARAMS_H
