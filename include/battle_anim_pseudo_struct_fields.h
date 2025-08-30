#ifndef GUARD_BATTLE_ANIM_PSEUDO_STRUCT_FIELDS_H
#define GUARD_BATTLE_ANIM_PSEUDO_STRUCT_FIELDS_H

// for InitSpriteLinearTranslation
// both input and output
#define sDuration_lt data[0]

// input only
#define sInputStartX_lt data[1]
#define sInputEndX_lt data[2]
#define sInputStartY_lt data[3]
#define sInputEndY_lt data[4]

// output only
#define sXIncrement_lt data[1]
#define sYIncrement_lt data[2]
#define sCurXOffsetFixedPoint_lt data[3]
#define sCurYOffsetFixedPoint_lt data[4]

// only when calling TranslateSpecifiedSpriteLinear
#define sSpriteId_lt data[5]

// ============================

// API for the following functions:
// - InitAndRunSpriteLinearTranslationIteratorWithSpritePosAsStart
// - InitSpriteLinearTranslationIterator
// - UpdateSpriteLinearTranslationIterator (TranslateSpriteLinear_FromIterator)
// - StartAnimLinearTranslation_SetCornerVecX
//   - AnimTranslateLinear_WithFollowup_SetCornerVecX
// - InitSpriteLinearTranslationIteratorWithSpeed
// - InitAndRunSpriteLinearTranslationIteratorWithSpeedAndSpritePosAsStart
// - AnimTravelDiagonally

// - also TranslateSpriteToBattleTargetPos, TranslateSpriteToBattleAttackerPos, StartAnimLinearTranslation_SetCornerVecX, but all unused, so not bothering to document

// TranslateAnimHorizontalArc, TranslateAnimVerticalArc are subclasses

// both input and output
#define sDuration_lt data[0]

// input only
#define sInputStartX_lt data[1]
#define sInputEndX_lt data[2]
#define sInputStartY_lt data[3]
#define sInputEndY_lt data[4]

// ============================
// API for the following functions
// - InitAnimFastLinearTranslation
// - InitAndRunAnimFastLinearTranslation
// - AnimFastTranslateLinear
// - AnimFastTranslateLinearWaitEnd
// - InitAnimFastLinearTranslationWithSpeed
// - InitAnimFastLinearTranslationWithSpeedAndPos

// ============================
// API for the following functions
// TranslateSpriteLinearAndFlicker
// AnimTranslateLinearAndFlicker_Flipped
// AnimTranslateLinearAndFlicker

// ============================
// for InitSpritePosToAnimTarget, InitSpritePosToAnimAttacker, InitSpritePosToAnimAttackerPartner, InitSpritePosToAnimBattler
// TODO: still need to document AnimSpriteOnMonPos

// expansion only: InitSpritePosToGivenTarget, InitSpritePosToAnimTargetsCentre, InitSpritePosToAnimAttackersCentre

// ISPM = InitSpritePos[To]Mon

// value that's added to the sprite's current x
#define ARG_SPRITE_X_OFFSET_ISPM 0
// value that's added to the sprite's current y
#define ARG_SPRITE_Y_OFFSET_ISPM 1

// ============================

#endif // GUARD_BATTLE_ANIM_PSEUDO_STRUCT_FIELDS_H
