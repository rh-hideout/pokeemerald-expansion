#include "global.h"
#include "bike.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "rotating_gate.h"
#include "sound.h"
#include "sprite.h"
#include "constants/songs.h"
#include "constants/event_objects.h"

#define ROTATING_GATE_TILE_TAG 0x1300
#define ROTATING_GATE_REGULAR_SHEET_SIZE (32 * 32 / 2)
#define ROTATING_GATE_LARGE_SHEET_SIZE   (64 * 64 / 2)
#define GATE_ARM_MAX_LENGTH 2

// Runtime-only state stored in ObjectEventTemplate.trainerRange_berryTreeId.
// Gates never enter the normal object-event pipeline, so this otherwise ignored
// field can safely keep state in the save-block copy across temporary heap resets.
#define GATE_STATE_ORIENTATION_MASK  0x0003
#define GATE_STATE_SPRITE_ID_SHIFT   2
#define GATE_STATE_SPRITE_ID_MASK    (0x00FF << GATE_STATE_SPRITE_ID_SHIFT)
#define GATE_STATE_INITIALIZED       0x0400

#define GATE_ROT(rotationDirection, arm, longArm)                                             \
    ((rotationDirection & 15) << 4) | ((arm & 7) << 1) | (longArm & 1)
#define GATE_ROT_CW(arm, longArm) GATE_ROT(ROTATE_CLOCKWISE, arm, longArm)
#define GATE_ROT_ACW(arm, longArm) GATE_ROT(ROTATE_ANTICLOCKWISE, arm, longArm)
#define GATE_ROT_NONE 255

static void SpriteCallback_RotatingGate(struct Sprite *sprite);
static u8 RotatingGate_CreateGate(u8 objectEventIndex, s16 deltaX, s16 deltaY);
static void RotatingGate_HideGatesOutsideViewport(struct Sprite *sprite);

enum
{
    /*
     * |
     * +--
     */
    GATE_SHAPE_L1,

    /*
     * |
     * |
     * +--
     */
    GATE_SHAPE_L2,

    /*
     * |
     * +----
     */
    GATE_SHAPE_L3,

    /*
     * |
     * |
     * +----
     */
    GATE_SHAPE_L4,

    /*
     * |
     * +--
     * |
     */
    GATE_SHAPE_T1,

    /*
     * |
     * |
     * +--
     * |
     */
    GATE_SHAPE_T2,

    /*
     * |
     * +----
     * |
     */
    GATE_SHAPE_T3,

    /*
     * An unused T-shape gate
     * |
     * +--
     * |
     * |
     */
    GATE_SHAPE_T4,

    /*
     * An unused T-shape gate
     * |
     * |
     * +----
     * |
     */
    GATE_SHAPE_UNUSED_T1,

    /*
     * An unused T-shape gate
     * |
     * |
     * +--
     * |
     * |
     */
    GATE_SHAPE_UNUSED_T2,

    /*
     * An unused T-shape gate
     * |
     * +----
     * |
     * |
     */
    GATE_SHAPE_UNUSED_T3,

    /*
     * An unused T-shape gate
     * |
     * |
     * +----
     * |
     * |
     */
    GATE_SHAPE_UNUSED_T4,
};

enum
{
    /*
     * 0 degrees (clockwise)
     * |
     * +--
     * |
     */
    GATE_ORIENTATION_0,

    /*
     * 90 degress (clockwise)
     * --+--
     *   |
     */
    GATE_ORIENTATION_90,

    /*
     * 180 degrees (clockwise)
     *   |
     * --+
     *   |
     */
    GATE_ORIENTATION_180,

    /*
     * 270 degrees (clockwise)
     *   |
     * --+--
     */
    GATE_ORIENTATION_270,

    GATE_ORIENTATION_MAX,
};

// Describes the location of the gates "arms" when the gate has not
// been rotated (i.e. rotated 0 degrees)
enum
{
    GATE_ARM_NORTH,
    GATE_ARM_EAST,
    GATE_ARM_SOUTH,
    GATE_ARM_WEST,
};

enum
{
    ROTATE_NONE,
    ROTATE_ANTICLOCKWISE,
    ROTATE_CLOCKWISE,
};

extern const u32 gObjectEventPic_RotatingGateL1[];
extern const u32 gObjectEventPic_RotatingGateL2[];
extern const u32 gObjectEventPic_RotatingGateL3[];
extern const u32 gObjectEventPic_RotatingGateL4[];
extern const u32 gObjectEventPic_RotatingGateT1[];
extern const u32 gObjectEventPic_RotatingGateT2[];
extern const u32 gObjectEventPic_RotatingGateT3[];
extern const u32 gObjectEventPic_RotatingGateT4[];

static const struct OamData sOamData_RotatingGateLarge =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 2,
    .affineParam = 0,
};

static const struct OamData sOamData_RotatingGateRegular =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 2,
    .affineParam = 0,
};

static const struct SpriteSheet sRotatingGatesGraphicsTable[] =
{
    // Object graphics use the standard Down, Up, Left frame order. Facing is
    // only an editor convention; frame 0 remains the affine runtime sprite.
    {
        .data = gObjectEventPic_RotatingGateL1,
        .size = ROTATING_GATE_REGULAR_SHEET_SIZE,
        .tag = ROTATING_GATE_TILE_TAG + GATE_SHAPE_L1,
    },
    {
        .data = gObjectEventPic_RotatingGateL2,
        .size = ROTATING_GATE_LARGE_SHEET_SIZE,
        .tag = ROTATING_GATE_TILE_TAG + GATE_SHAPE_L2,
    },
    {
        .data = gObjectEventPic_RotatingGateL3,
        .size = ROTATING_GATE_LARGE_SHEET_SIZE,
        .tag = ROTATING_GATE_TILE_TAG + GATE_SHAPE_L3,
    },
    {
        .data = gObjectEventPic_RotatingGateL4,
        .size = ROTATING_GATE_LARGE_SHEET_SIZE,
        .tag = ROTATING_GATE_TILE_TAG + GATE_SHAPE_L4,
    },
    {
        .data = gObjectEventPic_RotatingGateT1,
        .size = ROTATING_GATE_REGULAR_SHEET_SIZE,
        .tag = ROTATING_GATE_TILE_TAG + GATE_SHAPE_T1,
    },
    {
        .data = gObjectEventPic_RotatingGateT2,
        .size = ROTATING_GATE_LARGE_SHEET_SIZE,
        .tag = ROTATING_GATE_TILE_TAG + GATE_SHAPE_T2,
    },
    {
        .data = gObjectEventPic_RotatingGateT3,
        .size = ROTATING_GATE_LARGE_SHEET_SIZE,
        .tag = ROTATING_GATE_TILE_TAG + GATE_SHAPE_T3,
    },
    {
        .data = gObjectEventPic_RotatingGateT4,
        .size = ROTATING_GATE_LARGE_SHEET_SIZE,
        .tag = ROTATING_GATE_TILE_TAG + GATE_SHAPE_T4,
    },
    {NULL},
};

static const union AnimCmd sSpriteAnim_RotatingGateLarge[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

static const union AnimCmd sSpriteAnim_RotatingGateRegular[] =
{
    ANIMCMD_FRAME(0, 0), ANIMCMD_END,
};

static const union AnimCmd *const sSpriteAnimTable_RotatingGateLarge[] =
{
    sSpriteAnim_RotatingGateLarge,
};

static const union AnimCmd *const sSpriteAnimTable_RotatingGateRegular[] =
{
    sSpriteAnim_RotatingGateRegular,
};

static const union AffineAnimCmd sSpriteAffineAnim_Rotated0[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sSpriteAffineAnim_Rotated90[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -64, 0),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sSpriteAffineAnim_Rotated180[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -128, 0),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sSpriteAffineAnim_Rotated270[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 64, 0),
    AFFINEANIMCMD_JUMP(0),
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingClockwise0to90[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -4, 16),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingClockwise90to180[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -64, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -4, 16),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingClockwise180to270[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -128, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -4, 16),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingClockwise270to360[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 64, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -4, 16),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingAnticlockwise360to270[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 4, 16),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingAnticlockwise270to180[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 64, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 4, 16),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingAnticlockwise180to90[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -128, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 4, 16),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingAnticlockwise90to0[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -64, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 4, 16),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingClockwise0to90Faster[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingClockwise90to180Faster[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -64, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingClockwise180to270Faster[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -128, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingClockwise270to360Faster[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 64, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -8, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingAnticlockwise360to270Faster[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingAnticlockwise270to180Faster[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 64, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingAnticlockwise180to90Faster[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -128, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingAnticlockwise90to0Faster[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, -64, 0),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 8, 8),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sSpriteAffineAnimTable_RotatingGate[] =
{
    sSpriteAffineAnim_Rotated0,
    sSpriteAffineAnim_Rotated90,
    sSpriteAffineAnim_Rotated180,
    sSpriteAffineAnim_Rotated270,
    sSpriteAffineAnim_RotatingAnticlockwise360to270,
    sSpriteAffineAnim_RotatingAnticlockwise90to0,
    sSpriteAffineAnim_RotatingAnticlockwise180to90,
    sSpriteAffineAnim_RotatingAnticlockwise270to180,
    sSpriteAffineAnim_RotatingClockwise0to90,
    sSpriteAffineAnim_RotatingClockwise90to180,
    sSpriteAffineAnim_RotatingClockwise180to270,
    sSpriteAffineAnim_RotatingClockwise270to360,
    sSpriteAffineAnim_RotatingAnticlockwise360to270Faster,
    sSpriteAffineAnim_RotatingAnticlockwise90to0Faster,
    sSpriteAffineAnim_RotatingAnticlockwise180to90Faster,
    sSpriteAffineAnim_RotatingAnticlockwise270to180Faster,
    sSpriteAffineAnim_RotatingClockwise0to90Faster,
    sSpriteAffineAnim_RotatingClockwise90to180Faster,
    sSpriteAffineAnim_RotatingClockwise180to270Faster,
    sSpriteAffineAnim_RotatingClockwise270to360Faster,
};

#define ROTATING_GATE_SPRITE_TEMPLATE(shape, oam_, anims_)       \
    [shape] =                                                   \
    {                                                           \
        .tileTag = ROTATING_GATE_TILE_TAG + shape,              \
        .paletteTag = OBJ_EVENT_PAL_TAG_NPC_1,                  \
        .oam = oam_,                                            \
        .anims = anims_,                                        \
        .affineAnims = sSpriteAffineAnimTable_RotatingGate,     \
        .callback = SpriteCallback_RotatingGate,                \
    }

static const struct SpriteTemplate sSpriteTemplates_RotatingGate[] =
{
    ROTATING_GATE_SPRITE_TEMPLATE(GATE_SHAPE_L1, &sOamData_RotatingGateRegular, sSpriteAnimTable_RotatingGateRegular),
    ROTATING_GATE_SPRITE_TEMPLATE(GATE_SHAPE_L2, &sOamData_RotatingGateLarge, sSpriteAnimTable_RotatingGateLarge),
    ROTATING_GATE_SPRITE_TEMPLATE(GATE_SHAPE_L3, &sOamData_RotatingGateLarge, sSpriteAnimTable_RotatingGateLarge),
    ROTATING_GATE_SPRITE_TEMPLATE(GATE_SHAPE_L4, &sOamData_RotatingGateLarge, sSpriteAnimTable_RotatingGateLarge),
    ROTATING_GATE_SPRITE_TEMPLATE(GATE_SHAPE_T1, &sOamData_RotatingGateRegular, sSpriteAnimTable_RotatingGateRegular),
    ROTATING_GATE_SPRITE_TEMPLATE(GATE_SHAPE_T2, &sOamData_RotatingGateLarge, sSpriteAnimTable_RotatingGateLarge),
    ROTATING_GATE_SPRITE_TEMPLATE(GATE_SHAPE_T3, &sOamData_RotatingGateLarge, sSpriteAnimTable_RotatingGateLarge),
    ROTATING_GATE_SPRITE_TEMPLATE(GATE_SHAPE_T4, &sOamData_RotatingGateLarge, sSpriteAnimTable_RotatingGateLarge),
};

#undef ROTATING_GATE_SPRITE_TEMPLATE

// These structures describe what happens to the gate if you hit it at
// a given coordinate in a 4x4 grid when walking in the specified
// direction. Either the gate does not rotate, or it rotates in the
// given direction. This information is compared against the gate
// "arm" layout to see if there is an arm at the position in order to
// produce the final rotation.
static const u8 sRotatingGate_RotationInfoNorth[4 * 4] =
{
    GATE_ROT_NONE,                 GATE_ROT_NONE,                 GATE_ROT_NONE,                  GATE_ROT_NONE,
    GATE_ROT_CW(GATE_ARM_WEST, 1), GATE_ROT_CW(GATE_ARM_WEST, 0), GATE_ROT_ACW(GATE_ARM_EAST, 0), GATE_ROT_ACW(GATE_ARM_EAST, 1),
    GATE_ROT_NONE,                 GATE_ROT_NONE,                 GATE_ROT_NONE,                  GATE_ROT_NONE,
    GATE_ROT_NONE,                 GATE_ROT_NONE,                 GATE_ROT_NONE,                  GATE_ROT_NONE,
};

static const u8 sRotatingGate_RotationInfoSouth[4 * 4] =
{
    GATE_ROT_NONE,                  GATE_ROT_NONE,                  GATE_ROT_NONE,                 GATE_ROT_NONE,
    GATE_ROT_NONE,                  GATE_ROT_NONE,                  GATE_ROT_NONE,                 GATE_ROT_NONE,
    GATE_ROT_ACW(GATE_ARM_WEST, 1), GATE_ROT_ACW(GATE_ARM_WEST, 0), GATE_ROT_CW(GATE_ARM_EAST, 0), GATE_ROT_CW(GATE_ARM_EAST, 1),
    GATE_ROT_NONE,                  GATE_ROT_NONE,                  GATE_ROT_NONE,                 GATE_ROT_NONE,
};

static const u8 sRotatingGate_RotationInfoWest[4 * 4] =
{
    GATE_ROT_NONE, GATE_ROT_ACW(GATE_ARM_NORTH, 1), GATE_ROT_NONE, GATE_ROT_NONE,
    GATE_ROT_NONE, GATE_ROT_ACW(GATE_ARM_NORTH, 0), GATE_ROT_NONE, GATE_ROT_NONE,
    GATE_ROT_NONE, GATE_ROT_CW(GATE_ARM_SOUTH, 0),  GATE_ROT_NONE, GATE_ROT_NONE,
    GATE_ROT_NONE, GATE_ROT_CW(GATE_ARM_SOUTH, 1),  GATE_ROT_NONE, GATE_ROT_NONE,
};

static const u8 sRotatingGate_RotationInfoEast[4 * 4] =
{
    GATE_ROT_NONE, GATE_ROT_NONE, GATE_ROT_CW(GATE_ARM_NORTH, 1),  GATE_ROT_NONE,
    GATE_ROT_NONE, GATE_ROT_NONE, GATE_ROT_CW(GATE_ARM_NORTH, 0),  GATE_ROT_NONE,
    GATE_ROT_NONE, GATE_ROT_NONE, GATE_ROT_ACW(GATE_ARM_SOUTH, 0), GATE_ROT_NONE,
    GATE_ROT_NONE, GATE_ROT_NONE, GATE_ROT_ACW(GATE_ARM_SOUTH, 1), GATE_ROT_NONE,
};

// These tables describe the relative coordinate positions the arms
// must move through in order to be rotated.
static const struct Coords8 sRotatingGate_ArmPositionsClockwiseRotation[] = {
    { 0, -1 }, { 1, -2 }, { 0, 0 }, { 1, 0 }, { -1, 0 }, { -1, 1 }, { -1, -1 }, { -2, -1 },
};

static const struct Coords8 sRotatingGate_ArmPositionsAntiClockwiseRotation[] = {
    { -1, -1 }, { -1, -2 }, { 0, -1 }, { 1, -1 }, { 0, 0 }, { 0, 1 }, { -1, 0 }, { -2, 0 },
};

// Describes where the gates "arms" are in the order north, east, south, west.
// These are adjusted using the current orientation to perform collision checking
static const u8 sRotatingGate_ArmLayout[][4 * 2] =
{
    // L-shape gates
    {
        1, 0,
        1, 0,
        0, 0,
        0, 0,
    },
    {
        1, 1,
        1, 0,
        0, 0,
        0, 0,
    },
    {
        1, 0,
        1, 1,
        0, 0,
        0, 0,
    },
    {
        1, 1,
        1, 1,
        0, 0,
        0, 0,
    },

    // T-shape gates
    {
        1, 0,
        1, 0,
        1, 0,
        0, 0,
    },
    {
        1, 1,
        1, 0,
        1, 0,
        0, 0,
    },
    {
        1, 0,
        1, 1,
        1, 0,
        0, 0,
    },
    {
        1, 0,
        1, 0,
        1, 1,
        0, 0,
    },

    // Unused T-shape gates
    // These have 2-3 long arms and cannot actually be used anywhere
    // since configuration for them is missing from the other tables.
    {
        1, 1,
        1, 1,
        1, 0,
        0, 0,
    },
    {
        1, 1,
        1, 0,
        1, 1,
        0, 0,
    },
    {
        1, 0,
        1, 1,
        1, 1,
        0, 0,
    },
    {
        1, 1,
        1, 1,
        1, 1,
        0, 0,
    },
};

bool32 IsRotatingGateObjectEventGraphicsId(u16 graphicsId)
{
    return graphicsId >= OBJ_EVENT_GFX_ROTATING_GATE_L1
        && graphicsId <= OBJ_EVENT_GFX_ROTATING_GATE_T4;
}

static u8 RotatingGate_GetObjectEventCount(void)
{
    if (gMapHeader.events == NULL)
        return 0;
    return min(gMapHeader.events->objectEventCount, OBJECT_EVENT_TEMPLATES_COUNT);
}

static bool32 RotatingGate_IsTemplate(const struct ObjectEventTemplate *objectEvent)
{
    // Gates are always-active map geometry. Apart from position and the
    // facing movement types, standard object fields (including elevation,
    // ranges, trainer data, script, and flag) are intentionally ignored.
    // Clone and dynamically spawned object templates are not supported.
    return objectEvent->kind == OBJ_KIND_NORMAL
        && IsRotatingGateObjectEventGraphicsId(objectEvent->graphicsId);
}

static bool32 RotatingGate_IsInitialized(const struct ObjectEventTemplate *objectEvent)
{
    return RotatingGate_IsTemplate(objectEvent)
        && (objectEvent->trainerRange_berryTreeId & GATE_STATE_INITIALIZED);
}

static bool32 RotatingGate_IsPuzzleActive(void)
{
    u32 i;

    for (i = 0; i < RotatingGate_GetObjectEventCount(); i++)
    {
        if (RotatingGate_IsInitialized(&gSaveBlock1Ptr->objectEventTemplates[i]))
            return TRUE;
    }
    return FALSE;
}

static u8 RotatingGate_GetInitialOrientation(const struct ObjectEventTemplate *objectEvent)
{
    switch (objectEvent->movementType)
    {
    case MOVEMENT_TYPE_NONE:
    case MOVEMENT_TYPE_FACE_DOWN:
        return GATE_ORIENTATION_0;
    case MOVEMENT_TYPE_FACE_RIGHT:
        return GATE_ORIENTATION_90;
    case MOVEMENT_TYPE_FACE_UP:
        return GATE_ORIENTATION_180;
    case MOVEMENT_TYPE_FACE_LEFT:
        return GATE_ORIENTATION_270;
    default:
        assertf(FALSE, "rotating gate %d has invalid movement type %d",
                objectEvent->localId, objectEvent->movementType)
        {
        }
        return GATE_ORIENTATION_0;
    }
}

static u8 RotatingGate_GetGateOrientation(u8 objectEventIndex)
{
    return gSaveBlock1Ptr->objectEventTemplates[objectEventIndex].trainerRange_berryTreeId & GATE_STATE_ORIENTATION_MASK;
}

static void RotatingGate_SetGateOrientation(u8 objectEventIndex, u8 orientation)
{
    struct ObjectEventTemplate *objectEvent = &gSaveBlock1Ptr->objectEventTemplates[objectEventIndex];

    objectEvent->trainerRange_berryTreeId &= ~GATE_STATE_ORIENTATION_MASK;
    objectEvent->trainerRange_berryTreeId |= orientation & GATE_STATE_ORIENTATION_MASK;
}

static u8 RotatingGate_GetGateSpriteId(u8 objectEventIndex)
{
    return (gSaveBlock1Ptr->objectEventTemplates[objectEventIndex].trainerRange_berryTreeId & GATE_STATE_SPRITE_ID_MASK)
         >> GATE_STATE_SPRITE_ID_SHIFT;
}

static void RotatingGate_SetGateSpriteId(u8 objectEventIndex, u8 spriteId)
{
    struct ObjectEventTemplate *objectEvent = &gSaveBlock1Ptr->objectEventTemplates[objectEventIndex];

    objectEvent->trainerRange_berryTreeId &= ~GATE_STATE_SPRITE_ID_MASK;
    objectEvent->trainerRange_berryTreeId |= spriteId << GATE_STATE_SPRITE_ID_SHIFT;
}

static bool32 RotatingGate_IsLiveSprite(u8 objectEventIndex, u8 spriteId)
{
    return spriteId < MAX_SPRITES
        && gSprites[spriteId].inUse
        && gSprites[spriteId].callback == SpriteCallback_RotatingGate
        && gSprites[spriteId].data[0] == objectEventIndex;
}

static u8 RotatingGate_GetShape(const struct ObjectEventTemplate *objectEvent)
{
    return objectEvent->graphicsId - OBJ_EVENT_GFX_ROTATING_GATE_L1;
}

static void RotatingGate_GetPivot(const struct ObjectEventTemplate *objectEvent, s16 *x, s16 *y)
{
    const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);

    *x = objectEvent->x;
    // Porymap places object events at the bottom-center of their graphics.
    // Affine objects rotate around their center, so move the pivot up by half
    // of the graphics height beyond the standard 16-pixel object anchor.
    *y = objectEvent->y + (16 - graphicsInfo->height / 2) / 16;
}

static void RotatingGate_RotateInDirection(u8 objectEventIndex, u32 rotationDirection)
{
    u8 orientation = RotatingGate_GetGateOrientation(objectEventIndex);

    if (rotationDirection == ROTATE_ANTICLOCKWISE)
    {
        if (orientation)
            orientation--;
        else
            orientation = GATE_ORIENTATION_270;
    }
    else
    {
        orientation++;
        orientation = orientation % GATE_ORIENTATION_MAX;
    }
    RotatingGate_SetGateOrientation(objectEventIndex, orientation);
}

void RotatingGate_InitMap(void)
{
    u32 i;

    for (i = 0; i < RotatingGate_GetObjectEventCount(); i++)
    {
        struct ObjectEventTemplate *objectEvent = &gSaveBlock1Ptr->objectEventTemplates[i];

        if (!RotatingGate_IsTemplate(objectEvent))
            continue;

        // This is the fresh-map hook: overwrite the ignored authored trainer
        // range even if it happens to contain one of the runtime state bits.
        objectEvent->trainerRange_berryTreeId = GATE_STATE_INITIALIZED
                                              | (MAX_SPRITES << GATE_STATE_SPRITE_ID_SHIFT)
                                              | RotatingGate_GetInitialOrientation(objectEvent);
    }
}

static void RotatingGate_CreateGatesWithinViewport(s16 deltaX, s16 deltaY)
{
    u32 i;

    // Calculate the bounding box of the camera
    // Same as RotatingGate_DestroyGatesOutsideViewport
    s16 x = gSaveBlock1Ptr->pos.x - 2;
    s16 x2 = gSaveBlock1Ptr->pos.x + MAP_OFFSET_W + 2;
    s16 y = gSaveBlock1Ptr->pos.y - 2;
    s16 y2 = gSaveBlock1Ptr->pos.y + MAP_OFFSET_H;

    for (i = 0; i < RotatingGate_GetObjectEventCount(); i++)
    {
        struct ObjectEventTemplate *objectEvent = &gSaveBlock1Ptr->objectEventTemplates[i];
        u8 spriteId;
        s16 x3, y3;

        if (!RotatingGate_IsInitialized(objectEvent))
            continue;

        spriteId = RotatingGate_GetGateSpriteId(i);
        if (spriteId != MAX_SPRITES && !RotatingGate_IsLiveSprite(i, spriteId))
        {
            RotatingGate_SetGateSpriteId(i, MAX_SPRITES);
            spriteId = MAX_SPRITES;
        }

        RotatingGate_GetPivot(objectEvent, &x3, &y3);
        x3 += MAP_OFFSET;
        y3 += MAP_OFFSET;

        if (y <= y3 && y2 >= y3 && x <= x3 && x2 >= x3 &&
            spriteId == MAX_SPRITES)
        {
            RotatingGate_SetGateSpriteId(i, RotatingGate_CreateGate(i, deltaX, deltaY));
        }
    }
}

static u8 RotatingGate_CreateGate(u8 objectEventIndex, s16 deltaX, s16 deltaY)
{
    const struct ObjectEventTemplate *objectEvent = &gSaveBlock1Ptr->objectEventTemplates[objectEventIndex];
    u8 shape = RotatingGate_GetShape(objectEvent);
    struct Sprite *sprite;
    struct SpriteTemplate template;
    struct OamData oam;
    u8 spriteId;
    s16 x, y;

    if (GetSpriteTileStartByTag(ROTATING_GATE_TILE_TAG + shape) == TAG_NONE)
        return MAX_SPRITES;

    // Create non-affine first so matrix exhaustion can be handled explicitly.
    template = sSpriteTemplates_RotatingGate[shape];
    oam = *template.oam;
    oam.affineMode = ST_OAM_AFFINE_OFF;
    template.oam = &oam;

    spriteId = CreateSpriteUnchecked(&template, 0, 0, OW_OBJECT_SUBPRIORITY - 1); // Above shadows
    if (spriteId == MAX_SPRITES)
        return MAX_SPRITES;

    RotatingGate_GetPivot(objectEvent, &x, &y);
    x += MAP_OFFSET;
    y += MAP_OFFSET;

    sprite = &gSprites[spriteId];
    sprite->template = &sSpriteTemplates_RotatingGate[shape];
    UpdateSpritePaletteByTemplate(&template, sprite);
    sprite->data[0] = objectEventIndex;
    sprite->coordOffsetEnabled = 1;
    sprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;

    if (!TryInitSpriteAffineAnim(sprite))
    {
        sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
        DestroySprite(sprite);
        return MAX_SPRITES;
    }

    GetMapCoordsFromSpritePos(x + deltaX, y + deltaY, &sprite->x, &sprite->y);
    RotatingGate_HideGatesOutsideViewport(sprite);
    StartSpriteAffineAnim(sprite, RotatingGate_GetGateOrientation(objectEventIndex));

    return spriteId;
}

static void SpriteCallback_RotatingGate(struct Sprite *sprite)
{
    u8 affineAnimation;
    u8 rotationDirection = sprite->data[1];
    u8 orientation = sprite->data[2];

    RotatingGate_HideGatesOutsideViewport(sprite);

    if (rotationDirection == ROTATE_ANTICLOCKWISE)
    {
        affineAnimation = orientation + 4;

        if (GetPlayerSpeed() != PLAYER_SPEED_NORMAL)
            affineAnimation += 8;

        PlaySE(SE_ROTATING_GATE);
        StartSpriteAffineAnim(sprite, affineAnimation);
    }
    else if (rotationDirection == ROTATE_CLOCKWISE)
    {
        affineAnimation = orientation + 8;

        if (GetPlayerSpeed() != PLAYER_SPEED_NORMAL)
            affineAnimation += 8;

        PlaySE(SE_ROTATING_GATE);
        StartSpriteAffineAnim(sprite, affineAnimation);
    }

    sprite->data[1] = ROTATE_NONE;
}

static void RotatingGate_HideGatesOutsideViewport(struct Sprite *sprite)
{
    u16 x, y;
    s16 x2, y2;

    sprite->invisible = FALSE;
    x = sprite->x + sprite->x2 + sprite->centerToCornerVecX + gSpriteCoordOffsetX;
    y = sprite->y + sprite->y2 + sprite->centerToCornerVecY + gSpriteCoordOffsetY;

    x2 = x + 64; // Dimensions of the rotating gate
    y2 = y + 64;

    if ((s16)x > DISPLAY_WIDTH + 16 - 1 || x2 < -16)
    {
        sprite->invisible = TRUE;
    }

    if ((s16)y > DISPLAY_HEIGHT + 16 - 1 || y2 < -16)
    {
        sprite->invisible = TRUE;
    }
}

static void LoadRotatingGatePics(void)
{
    u32 i;
    u32 usedShapes = 0;

    for (i = 0; i < RotatingGate_GetObjectEventCount(); i++)
    {
        const struct ObjectEventTemplate *objectEvent = &gSaveBlock1Ptr->objectEventTemplates[i];

        if (RotatingGate_IsInitialized(objectEvent))
            usedShapes |= 1 << RotatingGate_GetShape(objectEvent);
    }

    for (i = 0; i < ARRAY_COUNT(sRotatingGatesGraphicsTable) - 1; i++)
    {
        if ((usedShapes & (1 << i))
         && GetSpriteTileStartByTag(sRotatingGatesGraphicsTable[i].tag) == TAG_NONE)
            LoadSpriteSheet(&sRotatingGatesGraphicsTable[i]);
    }
}

static void RotatingGate_DestroyGatesOutsideViewport(void)
{
    s32 i;

    // Same as RotatingGate_CreateGatesWithinViewport
    s16 x = gSaveBlock1Ptr->pos.x - 2;
    s16 x2 = gSaveBlock1Ptr->pos.x + MAP_OFFSET_W + 2;
    s16 y = gSaveBlock1Ptr->pos.y - 2;
    s16 y2 = gSaveBlock1Ptr->pos.y + MAP_OFFSET_H;

    for (i = 0; i < RotatingGate_GetObjectEventCount(); i++)
    {
        struct ObjectEventTemplate *objectEvent = &gSaveBlock1Ptr->objectEventTemplates[i];
        u8 spriteId;
        s16 xGate, yGate;

        if (!RotatingGate_IsInitialized(objectEvent))
            continue;

        spriteId = RotatingGate_GetGateSpriteId(i);
        if (spriteId == MAX_SPRITES)
            continue;

        if (!RotatingGate_IsLiveSprite(i, spriteId))
        {
            RotatingGate_SetGateSpriteId(i, MAX_SPRITES);
            continue;
        }

        RotatingGate_GetPivot(objectEvent, &xGate, &yGate);
        xGate += MAP_OFFSET;
        yGate += MAP_OFFSET;

        if (xGate < x || xGate > x2 || yGate < y || yGate > y2)
        {
            struct Sprite *sprite = &gSprites[spriteId];
            FreeSpriteOamMatrix(sprite);
            DestroySprite(sprite);
            RotatingGate_SetGateSpriteId(i, MAX_SPRITES);
        }
    }
}

static s32 RotatingGate_CanRotate(u8 objectEventIndex, s32 rotationDirection)
{
    const struct ObjectEventTemplate *objectEvent = &gSaveBlock1Ptr->objectEventTemplates[objectEventIndex];
    const struct Coords8 *armPos;
    u8 orientation;
    s16 x, y;
    u8 shape;
    s32 i, j;

    if (rotationDirection == ROTATE_ANTICLOCKWISE)
        armPos = sRotatingGate_ArmPositionsAntiClockwiseRotation;
    else if (rotationDirection == ROTATE_CLOCKWISE)
        armPos = sRotatingGate_ArmPositionsClockwiseRotation;
    else
        return FALSE;

    orientation = RotatingGate_GetGateOrientation(objectEventIndex);

    shape = RotatingGate_GetShape(objectEvent);
    RotatingGate_GetPivot(objectEvent, &x, &y);
    x += MAP_OFFSET;
    y += MAP_OFFSET;

    // Loop through the gate's "arms" clockwise (north, south, east, west)
    for (i = GATE_ARM_NORTH; i <= GATE_ARM_WEST; i++)
    {
        // Ensure that no part of the arm collides with the map
        for (j = 0; j < GATE_ARM_MAX_LENGTH; j++)
        {
            u8 armIndex = 2 * ((orientation + i) % 4) + j;

            if (sRotatingGate_ArmLayout[shape][2 * i + j])
            {
            #ifdef BUGFIX
                // Collision has a range 0-3, any value != 0 is impassable
                if (MapGridGetCollisionAt(x + armPos[armIndex].x, y + armPos[armIndex].y))
            #else
                if (MapGridGetCollisionAt(x + armPos[armIndex].x, y + armPos[armIndex].y) == 1)
            #endif
                    return FALSE;
            }
        }
    }

    return TRUE;
}

static s32 RotatingGate_HasArm(u8 objectEventIndex, u8 armInfo)
{
    const struct ObjectEventTemplate *objectEvent = &gSaveBlock1Ptr->objectEventTemplates[objectEventIndex];
    s32 arm = armInfo / 2;
    s32 isLongArm = armInfo % 2;

    s8 armOrientation = (arm - RotatingGate_GetGateOrientation(objectEventIndex) + 4) % 4;
    s32 shape = RotatingGate_GetShape(objectEvent);
    return sRotatingGate_ArmLayout[shape][armOrientation * 2 + isLongArm];
}

static void RotatingGate_TriggerRotationAnimation(u8 objectEventIndex, s32 rotationDirection)
{
    u8 spriteId = RotatingGate_GetGateSpriteId(objectEventIndex);

    if (RotatingGate_IsLiveSprite(objectEventIndex, spriteId))
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->data[1] = rotationDirection;
        sprite->data[2] = RotatingGate_GetGateOrientation(objectEventIndex);
    }
}

static u8 RotatingGate_GetRotationInfo(enum Direction direction, s16 x, s16 y)
{
    const u8 *ptr;

    if (direction == DIR_NORTH)
        ptr = sRotatingGate_RotationInfoNorth;
    else if (direction == DIR_SOUTH)
        ptr = sRotatingGate_RotationInfoSouth;
    else if (direction == DIR_WEST)
        ptr = sRotatingGate_RotationInfoWest;
    else if (direction == DIR_EAST)
        ptr = sRotatingGate_RotationInfoEast;
    else
        return GATE_ROT_NONE;

    return ptr[y * 4 + x];
}

void RotatingGatePuzzleCameraUpdate(s16 deltaX, s16 deltaY)
{
    if (RotatingGate_IsPuzzleActive())
    {
        // A failed tile, sprite, or matrix allocation is retried as the
        // viewport moves. Collision does not depend on graphics resources.
        LoadRotatingGatePics();
        RotatingGate_CreateGatesWithinViewport(deltaX, deltaY);
        RotatingGate_DestroyGatesOutsideViewport();
    }
}

static void RotatingGate_DestroyAllSprites(void)
{
    u32 i;

    for (i = 0; i < RotatingGate_GetObjectEventCount(); i++)
    {
        struct ObjectEventTemplate *objectEvent = &gSaveBlock1Ptr->objectEventTemplates[i];
        u8 spriteId;

        if (!RotatingGate_IsInitialized(objectEvent))
            continue;

        spriteId = RotatingGate_GetGateSpriteId(i);
        if (RotatingGate_IsLiveSprite(i, spriteId))
        {
            FreeSpriteOamMatrix(&gSprites[spriteId]);
            DestroySprite(&gSprites[spriteId]);
        }
        RotatingGate_SetGateSpriteId(i, MAX_SPRITES);
    }
}

void RotatingGate_InitGraphics(s16 deltaX, s16 deltaY)
{
    if (!RotatingGate_IsPuzzleActive())
        return;

    // A compatibility special may have created destination-map gates while a
    // seamless transition was still updating the camera origin. Recreate them
    // once at the final origin rather than retaining those intermediate coords.
    if (deltaX != 0 || deltaY != 0)
        RotatingGate_DestroyAllSprites();

    LoadRotatingGatePics();
    RotatingGate_CreateGatesWithinViewport(deltaX, deltaY);
}

void RotatingGate_DestroyGraphics(void)
{
    u32 i;

    RotatingGate_DestroyAllSprites();

    for (i = 0; i < ARRAY_COUNT(sRotatingGatesGraphicsTable) - 1; i++)
        FreeSpriteTilesByTag(sRotatingGatesGraphicsTable[i].tag);
}

bool32 CheckForRotatingGatePuzzleCollision(enum Direction direction, s16 x, s16 y)
{
    u32 i;

    for (i = 0; i < RotatingGate_GetObjectEventCount(); i++)
    {
        const struct ObjectEventTemplate *objectEvent = &gSaveBlock1Ptr->objectEventTemplates[i];
        s16 gateX, gateY;

        if (!RotatingGate_IsInitialized(objectEvent))
            continue;

        RotatingGate_GetPivot(objectEvent, &gateX, &gateY);
        gateX += MAP_OFFSET;
        gateY += MAP_OFFSET;

        if (gateX - 2 <= x && x <= gateX + 1 && gateY - 2 <= y && y <= gateY + 1)
        {
            s16 centerX = x - gateX + 2;
            s16 centerY = y - gateY + 2;
            u8 rotationInfo = RotatingGate_GetRotationInfo(direction, centerX, centerY);

            if (rotationInfo != GATE_ROT_NONE)
            {
                u8 rotationDirection = ((rotationInfo & 0xF0) >> 4);
                u8 armInfo = rotationInfo & 0xF;

                if (RotatingGate_HasArm(i, armInfo))
                {
                    if (RotatingGate_CanRotate(i, rotationDirection))
                    {
                        RotatingGate_TriggerRotationAnimation(i, rotationDirection);
                        RotatingGate_RotateInDirection(i, rotationDirection);
                        return FALSE;
                    }
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

bool32 CheckForRotatingGatePuzzleCollisionWithoutAnimation(enum Direction direction, s16 x, s16 y)
{
    u32 i;

    for (i = 0; i < RotatingGate_GetObjectEventCount(); i++)
    {
        const struct ObjectEventTemplate *objectEvent = &gSaveBlock1Ptr->objectEventTemplates[i];
        s16 gateX, gateY;

        if (!RotatingGate_IsInitialized(objectEvent))
            continue;

        RotatingGate_GetPivot(objectEvent, &gateX, &gateY);
        gateX += MAP_OFFSET;
        gateY += MAP_OFFSET;

        if (gateX - 2 <= x && x <= gateX + 1 && gateY - 2 <= y && y <= gateY + 1)
        {
            s16 centerX = x - gateX + 2;
            s16 centerY = y - gateY + 2;
            u8 rotationInfo = RotatingGate_GetRotationInfo(direction, centerX, centerY);

            if (rotationInfo != GATE_ROT_NONE)
            {
                u8 rotationDirection = ((rotationInfo & 0xF0) >> 4);
                u8 armInfo = rotationInfo & 0xF;

                if (RotatingGate_HasArm(i, armInfo))
                {
                    if (!RotatingGate_CanRotate(i, rotationDirection))
                    {
                        return TRUE;
                    }
                }
            }
        }
    }
    return FALSE;
}
