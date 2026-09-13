#ifndef GUARD_EVOLUTION_SCENE_H
#define GUARD_EVOLUTION_SCENE_H

#include "constants/species.h"

struct EvolutionData
{
    u8 partyIndex;
    u8 evoIndex;
    bool8 canStopEvo;
    enum EvolutionMode mode;
    enum Item item;
    struct Pokemon *tradePartner;
}

bool32 TryEvolution(u32 partyIndex, struct EvolutionData *evo, bool32 noFade);
enum Species GetEvolutionTargetSpecies(struct BoxPokemon *boxmon, struct EvolutionStruct *evo);
void BeginEvolutionScene(struct Pokemon *mon, enum Species postEvoSpecies, bool32 canStopEvo, u8 partyId);
void EvolutionScene(struct Pokemon *mon, enum Species postEvoSpecies, bool32 canStopEvo, u8 partyId);
void TradeEvolutionScene(struct Pokemon *mon, enum Species postEvoSpecies, u8 preEvoSpriteId, u8 partyId);

extern void (*gCB2_AfterEvolution)(void);

#endif // GUARD_EVOLUTION_SCENE_H
