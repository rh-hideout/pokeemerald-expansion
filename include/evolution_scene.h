#ifndef GUARD_EVOLUTION_SCENE_H
#define GUARD_EVOLUTION_SCENE_H

#include "constants/species.h"

struct EvolutionData
{
    u8 evoIndex;
    bool8 cannotStopEvo:1;
    bool8 leveledUpInBattle:1;
    enum EvolutionMethods method;
    union
    {
        u32 param;
        struct Pokemon *tradePartner;
    };
};

bool32 TryEvolution(u32 partyIndex, struct EvolutionData *evo, u32 noFadeoutOrSpriteId);
enum Species GetEvolutionTargetSpecies(struct BoxPokemon *boxmon, struct EvolutionData *evo);
//void BeginEvolutionScene(struct Pokemon *mon, enum Species postEvoSpecies, bool32 canStopEvo, u8 partyId);
void EvolutionScene(void);
void TradeEvolutionScene(void);
struct EvolutionData InitTradeEvolutionData(struct Pokemon *mon);

extern void (*gCB2_AfterEvolution)(void);

#endif // GUARD_EVOLUTION_SCENE_H
