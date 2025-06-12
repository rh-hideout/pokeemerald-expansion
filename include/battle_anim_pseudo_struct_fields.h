#ifndef GUARD_BATTLE_ANIM_PSEUDO_STRUCT_FIELDS_H
#define GUARD_BATTLE_ANIM_PSEUDO_STRUCT_FIELDS_H

// for InitSpriteDataForLinearTranslation
// both input and output
#define sDuration_ltf data[0]

// input only
#define sInputStartX_ltf data[1]
#define sInputEndX_ltf data[2]
#define sInputStartY_ltf data[3]
#define sInputEndY_ltf data[4]

// output only
#define sXIncrement_ltf data[1]
#define sYIncrement_ltf data[2]
#define sCurXOffsetFixedPoint_ltf data[3]
#define sCurYOffsetFixedPoint_ltf data[4]

// only when calling TranslateSpriteLinearByIdFixedPoint
#define sSpriteId_ltf data[5]

#endif // GUARD_BATTLE_ANIM_PSEUDO_STRUCT_FIELDS_H
