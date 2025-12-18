#ifndef GUARD_POKEMON_ANIMATION_H
#define GUARD_POKEMON_ANIMATION_H

#include "constants/pokemon_animation.h"

void LaunchAnimationTaskForFrontSprite(struct Sprite *sprite, enum AnimFunctionIDs frontAnimId);
void StartMonSummaryAnimation(struct Sprite *sprite, enum AnimFunctionIDs frontAnimId);
void LaunchAnimationTaskForBackSprite(struct Sprite *sprite, enum BackAnim backAnimSet);
void SetSpriteCB_MonAnimDummy(struct Sprite *sprite);

#endif // GUARD_POKEMON_ANIMATION_H
