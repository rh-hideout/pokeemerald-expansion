#ifndef COMFY_ANIM_H
#define COMFY_ANIM_H

enum
{
    COMFY_ANIM_TYPE_NONE,
    COMFY_ANIM_TYPE_EASING,
    COMFY_ANIM_TYPE_SPRING,
};

// t represents progress of the animation, where 0 is the start of the animation and 1 is the end.
// The return value is a Q_24_8 fixed-point value.
typedef s32 (*ComfyAnimEasingFunc)(s32 t /* Q_24_8 */);

struct ComfyAnimEasingConfig {
    // The total duration of the animation in frames (e.g. ~60 frames per second)
    u32 durationFrames;
    // The starting position of the animation. Q_24_8 fixed-point value
    s32 from;
    // The target position of the animation. Q_24_8 fixed-point value
    s32 to;
    // The easing function used for advancing the animation.
    ComfyAnimEasingFunc easingFunc;
    // The number of frames to delay before starting the animation.
    u32 delayFrames;
};

struct ComfyAnimSpringConfig {
    // The starting position of the animation. Q_24_8 fixed-point value
    s32 from;
    // The target position of the animation. Q_24_8 fixed-point value
    s32 to;
    // The spring's tension.
    s32 tension;
    // The spring's friction.
    s32 friction;
    // The mass of the value animated by the spring.
    s32 mass;
    // The maximum number of times the value can overshoot the destination before the spring animation
    // completes.
    //    A value of 0 (the default) indicates no clamping--the spring will run to its natural conclusion.
    //    A value of 1 indicates the spring stops when it overshoots the target value the first time. (no wobbling)
    //    A value of 2 indicates the spring stops when it overshoots the target value the second time, and so on.
    u32 clampAfter;
    // The number of frames to delay before starting the animation.
    u32 delayFrames;
};

struct ComfyAnimConfig {
    u8 type;
    union {
        struct ComfyAnimEasingConfig easing;
        struct ComfyAnimSpringConfig spring;
    } data;
};

struct ComfyAnimEasingState {
    u32 curFrame;
};

struct ComfyAnimSpringState {
    u32 overshootCount;
};

struct ComfyAnim {
    struct ComfyAnimConfig config;
    union {
        struct ComfyAnimEasingState easingState;
        struct ComfyAnimSpringState springState;
    } state;
    // The current position of the animation. Q_24_8 fixed-point value
    s32 position;
    // The current velocity of the animation. Q_24_8 fixed-point value
    s32 velocity;
    // The number of frames to delay before processing the animation.
    u32 delayFrames;
    // Indicates whether or not the animation has completed.
    bool32 completed;
    // Indicates whether or not the animation is currently in use.
    // It's up to the consumer to called ReleaseComfyAnim when finished with it.
    bool32 inUse;
};

#define NUM_COMFY_ANIMS     8
#define INVALID_COMFY_ANIM  NUM_COMFY_ANIMS
extern struct ComfyAnim gComfyAnims[NUM_COMFY_ANIMS];

#define COMFY_ANIM_SPRING_DEFAULT_MASS     Q_24_8(50)
#define COMFY_ANIM_SPRING_DEFAULT_TENSION  Q_24_8(175)
#define COMFY_ANIM_SPRING_DEFAULT_FRICTION Q_24_8(1000)

void TryAdvanceComfyAnim(struct ComfyAnim *anim);
void AdvanceComfyAnimations(void);
void InitComfyAnimConfig_Easing(struct ComfyAnimEasingConfig *config);
void InitComfyAnimConfig_Spring(struct ComfyAnimSpringConfig *config);
void InitComfyAnim_Easing(struct ComfyAnimEasingConfig *config, struct ComfyAnim *out);
void InitComfyAnim_Spring(struct ComfyAnimSpringConfig *config, struct ComfyAnim *out);
u32 CreateComfyAnim_Easing(struct ComfyAnimEasingConfig *config);
u32 CreateComfyAnim_Spring(struct ComfyAnimSpringConfig *config);
void ReleaseComfyAnim(u32 comfyAnimId);
void ReleaseComfyAnims(void);
int ReadComfyAnimValueSmooth(struct ComfyAnim *anim);

// Collection of standard easing functions
s32 ComfyAnimEasing_Linear(s32 t);
s32 ComfyAnimEasing_EaseInQuad(s32 t);
s32 ComfyAnimEasing_EaseOutQuad(s32 t);
s32 ComfyAnimEasing_EaseInOutQuad(s32 t);
s32 ComfyAnimEasing_EaseInCubic(s32 t);
s32 ComfyAnimEasing_EaseOutCubic(s32 t);
s32 ComfyAnimEasing_EaseInOutCubic(s32 t);
s32 ComfyAnimEasing_EaseInOutBack(s32 t);

#endif // SPRING_UTIL_H
