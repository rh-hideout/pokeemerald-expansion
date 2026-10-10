#ifndef GUARD_ROTATING_GATE_H
#define GUARD_ROTATING_GATE_H

bool32 IsRotatingGateObjectEventGraphicsId(u16 graphicsId);
void RotatingGate_InitMap(void);
void RotatingGate_InitGraphics(s16 deltaX, s16 deltaY);
void RotatingGate_DestroyGraphics(void);
void RotatingGatePuzzleCameraUpdate(s16 deltaX, s16 deltaY);
bool32 CheckForRotatingGatePuzzleCollision(enum Direction direction, s16 x, s16 y);
bool32 CheckForRotatingGatePuzzleCollisionWithoutAnimation(enum Direction direction, s16 x, s16 y);

#endif // GUARD_ROTATING_GATE_H
