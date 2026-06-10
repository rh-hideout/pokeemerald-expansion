#include "global.h"
#include "comfy_anim.h"
#include "math_util.h"

EWRAM_DATA struct ComfyAnim gComfyAnims[NUM_COMFY_ANIMS] = {0};

static void AdvanceComfyAnim_Easing(struct ComfyAnim *anim)
{
    s32 t, x, prevPosition;
    struct ComfyAnimEasingConfig *config = &anim->config.data.easing;

    anim->state.easingState.curFrame++;

    // Determine progress of animation, normalized to (0, 1]. The result is a Q_24_8 fixed-point representation.
    // This is simply calculated as: curFrame / durationFrames
    t = MathUtil_Div32(Q_24_8(anim->state.easingState.curFrame), Q_24_8(anim->config.data.easing.durationFrames));

    // Early exit if we know we're at the end of the animation--no need to invoke the easing function.
    if (t == Q_24_8(1))
    {
        anim->position = config->to;
        anim->completed = TRUE;
        return;
    }

    // Invoke the easing function to interpolate between the start and end states of the animation.
    x = anim->config.data.easing.easingFunc(t);
    prevPosition = anim->position;
    anim->position = config->from + MathUtil_Mul32(x, (config->to - config->from));
    anim->velocity = anim->position - prevPosition;

    if (anim->state.easingState.curFrame >= config->durationFrames)
        anim->completed = TRUE;
}

// These precisions and velocity thresholds are higher than one would typically use in modern-day applications. Since
// the GBA doesn't support sub-pixel rendering (i.e. things can only be drawn on the screen at whole-integer coordinates),
// when the spring is nearing its completion state, it will be prone to resulting in single-pixel oscillations, or extra
// frames of duration that result in no perceptible difference in the animated value. By choosing higher precision and
// stationary threshold, it will cause the spring to come to completion earlier. Because users will most often be using a
// spring animator to control the x/y coordinates of some visual element on-screen, this seems like a decent tradeoff.
// The precision used to compare the spring value's final resting position.
#define SPRING_POSITION_PRECISION     0x10 // 0.0625
// The threshold used to determine if the spring value has a stationary (zero) velocity.
#define STATIONARY_VELOCITY_THRESHOLD 0x10 // 0.0625

// Implementation of spring physics heavily borrowed from react-spring library.
// https://github.com/pmndrs/react-spring/blob/fd65b605b85c3a24143c4ce9dd322fdfca9c66be/packages/core/src/SpringValue.ts#L278
static void AdvanceComfyAnim_Spring(struct ComfyAnim *anim)
{
    s32 springForce, dampingForce, acceleration, prevPosition;
    s32 prevPositionSign, curPositionSign;
    struct ComfyAnimSpringConfig *config = &anim->config.data.spring;

    // When the spring value isn't moving AND it's at the target position, the animation is considered completed.
    if (abs(anim->velocity) < STATIONARY_VELOCITY_THRESHOLD && abs(config->to - anim->position) < SPRING_POSITION_PRECISION)
    {
        anim->position = config->to;
        anim->completed = TRUE;
        return;
    }

    // Wait for the specified delay before advancing the animation.
    if (anim->delayFrames > 0)
    {
        anim->delayFrames--;
        return;
    }

    // Apply spring physics to update velocity and position of the spring value.
    springForce = -1 * MathUtil_Mul32(MathUtil_Mul32(config->tension, 0x5 /* Q_24_8(0.02) */), anim->position - config->to);
    dampingForce = -1 * MathUtil_Mul32(MathUtil_Mul32(config->friction, 0x5 /* Q_24_8(0.02) */), anim->velocity);
    acceleration = MathUtil_Div32(springForce + dampingForce, config->mass);
    anim->velocity += acceleration;
    prevPosition = anim->position;
    anim->position += anim->velocity;

    if (config->clampAfter > 0)
    {
        prevPositionSign = prevPosition - config->to > 0;
        curPositionSign = anim->position - config->to > 0;
        if (prevPositionSign != curPositionSign)
        {
            // The spring value has overshot the target value. Check if the animation should complete early, as indicated by
            // the "clampAfter" config.
            anim->state.springState.overshootCount++;
            if (anim->state.springState.overshootCount >= config->clampAfter)
            {
                anim->position = config->to;
                anim->completed = TRUE;
                return;
            }
        }
    }
}

void TryAdvanceComfyAnim(struct ComfyAnim *anim)
{
    switch (anim->config.type)
    {
    case COMFY_ANIM_TYPE_EASING:
        if (!anim->completed)
            AdvanceComfyAnim_Easing(anim);
        break;
    case COMFY_ANIM_TYPE_SPRING:
        AdvanceComfyAnim_Spring(anim);
        break;
    }
}

void AdvanceComfyAnimations(void)
{
    int i;

    for (i = 0; i < NUM_COMFY_ANIMS; i++)
    {
        if (gComfyAnims[i].inUse)
            TryAdvanceComfyAnim(&gComfyAnims[i]);
    }
}

static u32 GetAvailableComfyAnim(void)
{
    int i;

    // Find the first free comfy anim.
    for (i = 0; i < NUM_COMFY_ANIMS; i++)
    {
        if (!gComfyAnims[i].inUse)
            return i;
    }

    return INVALID_COMFY_ANIM;
}

void InitComfyAnimConfig_Easing(struct ComfyAnimEasingConfig *config)
{
    memset(config, 0, sizeof(struct ComfyAnimEasingConfig));
    config->easingFunc = ComfyAnimEasing_Linear;
}

void InitComfyAnimConfig_Spring(struct ComfyAnimSpringConfig *config)
{
    memset(config, 0, sizeof(struct ComfyAnimSpringConfig));
    config->mass = COMFY_ANIM_SPRING_DEFAULT_MASS;
    config->tension = COMFY_ANIM_SPRING_DEFAULT_TENSION;
    config->friction = COMFY_ANIM_SPRING_DEFAULT_FRICTION;
}

void InitComfyAnim_Easing(struct ComfyAnimEasingConfig *config, struct ComfyAnim *out)
{
    out->inUse = TRUE;
    out->completed = FALSE;
    out->velocity = 0;
    out->delayFrames = config->delayFrames;
    out->position = config->from;
    out->config.type = COMFY_ANIM_TYPE_EASING;
    out->config.data.easing = *config;
    out->state.easingState.curFrame = 0;
}

u32 CreateComfyAnim_Easing(struct ComfyAnimEasingConfig *config)
{
    struct ComfyAnim *anim;
    int i = GetAvailableComfyAnim();

    if (i == INVALID_COMFY_ANIM)
        return i;

    anim = &gComfyAnims[i];
    InitComfyAnim_Easing(config, anim);
    return i;
}

void InitComfyAnim_Spring(struct ComfyAnimSpringConfig *config, struct ComfyAnim *out)
{
    out->inUse = TRUE;
    out->completed = FALSE;
    out->velocity = 0;
    out->delayFrames = config->delayFrames;
    out->position = config->from;
    out->config.type = COMFY_ANIM_TYPE_SPRING;
    out->config.data.spring = *config;
    out->state.springState.overshootCount = 0;
}

u32 CreateComfyAnim_Spring(struct ComfyAnimSpringConfig *config)
{
    struct ComfyAnim *anim;
    int i = GetAvailableComfyAnim();

    if (i == INVALID_COMFY_ANIM)
        return i;

    anim = &gComfyAnims[i];
    InitComfyAnim_Spring(config, anim);
    return i;
}

void ReleaseComfyAnim(u32 comfyAnimId)
{
    if (comfyAnimId < NUM_COMFY_ANIMS)
        gComfyAnims[comfyAnimId].inUse = FALSE;
}

void ReleaseComfyAnims(void)
{
    int i;

    for (i = 0; i < NUM_COMFY_ANIMS; i++)
        ReleaseComfyAnim(i);
}

int ReadComfyAnimValueSmooth(struct ComfyAnim *anim)
{
    return Q_24_8_TO_INT(anim->position + 0x80);
}

// Easing functions borrowed from easings.net library
// https://github.com/ai/easings.net/blob/master/src/easings/easingsFunctions.ts

s32 ComfyAnimEasing_Linear(s32 t /* Q_24_8 */)
{
    return t;
}

s32 ComfyAnimEasing_EaseInQuad(s32 t /* Q_24_8 */)
{
    return MathUtil_Mul32(t, t);
}

s32 ComfyAnimEasing_EaseOutQuad(s32 t /* Q_24_8 */)
{
    s32 v = Q_24_8(1) - t;
    return Q_24_8(1) - MathUtil_Mul32(v, v);
}

s32 ComfyAnimEasing_EaseInOutQuad(s32 t /* Q_24_8 */)
{
    if (t < (Q_24_8(1) >> 1))
        return 2 * MathUtil_Mul32(t, t);
    else
    {
        s32 v = -2 * t + Q_24_8(2);
        return Q_24_8(1) - (MathUtil_Mul32(v, v) >> 1);
    }
}

s32 ComfyAnimEasing_EaseInCubic(s32 t /* Q_24_8 */)
{
    return MathUtil_Mul32(t, MathUtil_Mul32(t, t));
}

s32 ComfyAnimEasing_EaseOutCubic(s32 t /* Q_24_8 */)
{
    s32 v = Q_24_8(1) - t;
    return Q_24_8(1) - MathUtil_Mul32(v, MathUtil_Mul32(v, v));
}

s32 ComfyAnimEasing_EaseInOutCubic(s32 t /* Q_24_8 */)
{
    if (t < (Q_24_8(1) >> 1))
        return 4 * MathUtil_Mul32(t, MathUtil_Mul32(t, t));
    else
    {
        s32 v = -2 * t + Q_24_8(2);
        return Q_24_8(1) - (MathUtil_Mul32(v, MathUtil_Mul32(v, v)) >> 1);
    }
}

s32 ComfyAnimEasing_EaseInOutBack(s32 t /* Q_24_8 */)
{
    s32 c1 = 0x1B3; // Q_24_8 representation of 1.70158
    s32 c2 = 0x298; // Q_24_8 representation of 1.70158 * 1.525

    if (t < (Q_24_8(1) >> 1))
    {
        s32 v1 = 2 * t;
        s32 a = MathUtil_Mul32(v1, v1);
        s32 b = MathUtil_Mul32(2 * (c2 + Q_24_8(1)), t) - c2;
        return (MathUtil_Mul32(a, b)) >> 1;
    }
    else
    {
        s32 v1 = 2 * t - Q_24_8(2);
        s32 a = MathUtil_Mul32(v1, v1);
        s32 b = MathUtil_Mul32(c2 + Q_24_8(1), v1) + c2;
        return (MathUtil_Mul32(a, b) + Q_24_8(2)) >> 1;
    }
}
