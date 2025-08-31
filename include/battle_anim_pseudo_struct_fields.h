#ifndef GUARD_BATTLE_ANIM_PSEUDO_STRUCT_FIELDS_H
#define GUARD_BATTLE_ANIM_PSEUDO_STRUCT_FIELDS_H

// API for the following functions
// - InitSpriteLinearTranslation
// - TradeMenuBouncePartySprites (in pokeemerald: Trade_MoveSelectedMonToTarget)
// - TranslateSpriteLinear
// - TranslateSpriteLinearIconFrame
// - TranslateSpecifiedSpriteLinear

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
// - InitSpriteLinearTranslationIterator
// - UpdateSpriteLinearTranslationIterator
// - TranslateSpriteLinear_FromIterator
// - TranslateSpriteLinearWithSetCornerVecX_FromIterator
// - InitSpriteLinearTranslationIteratorWithSpeed
// - InitAndRunSpriteLinearTranslationIteratorWithSpritePosAsStart
// - InitAndRunSpriteLinearTranslationIteratorWithSpeedAndSpritePosAsStart
// - AnimTravelDiagonally

// The following functions inherit from this API:
// - InitAnimArcTranslation
// - TranslateAnimHorizontalArc
// - TranslateAnimVerticalArc

// - also TranslateSpriteToBattleTargetPos, TranslateSpriteToBattleAttackerPos, StartAnimLinearTranslation_SetCornerVecX, but all unused, so not bothering to document

// both input and output
#define sDuration_lti data[0]

// If using InitSpriteLinearTranslationIteratorWithSpeed and InitAndRunSpriteLinearTranslationIteratorWithSpeedAndSpritePosAsStart
#define sInputSpeed_lti data[0]

// input only
#define sInputStartX_lti data[1]
#define sInputEndX_lti data[2]
#define sInputStartY_lti data[3]
#define sInputEndY_lti data[4]

// output only
#define sXIncrement_lti data[1]
#define sYIncrement_lti data[2]
#define sCurXOffsetFixedPoint_lti data[3]
#define sCurYOffsetFixedPoint_lti data[4]

// For InitAnimArcTranslation, TranslateAnimHorizontalArc, and TranslateAnimVerticalArc only

// Think of amplitude as the max height of the arc
#define sArcAmplitude_ati data[5]

// output only
#define sArcIncrement_ati data[6]
#define sCurArcHeightFixedPoint_ati data[7]

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
// API for the following functions:
// - TranslateSpriteLinearInteger
// - TranslateSpecifiedSpriteLinearInteger

// ltz - Linear Translation Integer (Z = Integer)
#define sDuration_ltz data[0]
#define sXIncrement_ltz data[1]
#define sYIncrement_ltz data[2]

// For TranslateSpecifiedSpriteLinearInteger only
#define sSpriteId_ltz data[3]

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
