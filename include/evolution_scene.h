#ifndef GUARD_EVOLUTION_SCENE_H
#define GUARD_EVOLUTION_SCENE_H

void BeginEvolutionScene(struct Pokemon *mon, u16 postEvoSpecies, bool8 canStopEvo, u8 partyId);
void EvolutionScene(struct Pokemon *mon, u16 postEvoSpecies, bool8 canStopEvo, u8 partyId);
void TradeEvolutionScene(struct Pokemon *mon, u16 postEvoSpecies, u8 preEvoSpriteId, u8 partyId);
void DoInvisibleEvolution(struct Pokemon *mon, u16 postEvoSpecies);

extern void (*gCB2_AfterEvolution)(void);

#endif // GUARD_EVOLUTION_SCENE_H
