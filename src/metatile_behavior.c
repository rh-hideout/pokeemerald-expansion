#include "global.h"
#include "metatile_behaviour.h"
#include "constants/metatile_behaviours.h"

#define TILE_FLAG_HAS_ENCOUNTERS (1 << 0)
#define TILE_FLAG_SURFABLE       (1 << 1)
#define TILE_FLAG_UNUSED         (1 << 2) // Roughly all of the traversable metatiles. Set but never read

static const u8 sTileBitAttributes[NUM_METATILE_BEHAVIOURS] =
{
    [MB_NORMAL]                             = TILE_FLAG_UNUSED,
    [MB_TALL_GRASS]                         = TILE_FLAG_UNUSED | TILE_FLAG_HAS_ENCOUNTERS,
    [MB_LONG_GRASS]                         = TILE_FLAG_UNUSED | TILE_FLAG_HAS_ENCOUNTERS,
    [MB_UNUSED_05]                          = TILE_FLAG_HAS_ENCOUNTERS,
    [MB_DEEP_SAND]                          = TILE_FLAG_UNUSED | TILE_FLAG_HAS_ENCOUNTERS,
    [MB_SHORT_GRASS]                        = TILE_FLAG_UNUSED,
    [MB_CAVE]                               = TILE_FLAG_UNUSED | TILE_FLAG_HAS_ENCOUNTERS,
    [MB_LONG_GRASS_SOUTH_EDGE]              = TILE_FLAG_UNUSED,
    [MB_NO_RUNNING]                         = TILE_FLAG_UNUSED,
    [MB_INDOOR_ENCOUNTER]                   = TILE_FLAG_UNUSED | TILE_FLAG_HAS_ENCOUNTERS,
    [MB_MOUNTAIN_TOP]                       = TILE_FLAG_UNUSED,
    [MB_BATTLE_PYRAMID_WARP]                = TILE_FLAG_UNUSED,
    [MB_MOSSDEEP_GYM_WARP]                  = TILE_FLAG_UNUSED,
    [MB_MT_PYRE_HOLE]                       = TILE_FLAG_UNUSED,
    [MB_POND_WATER]                         = TILE_FLAG_UNUSED | TILE_FLAG_SURFABLE | TILE_FLAG_HAS_ENCOUNTERS,
    [MB_INTERIOR_DEEP_WATER]                = TILE_FLAG_UNUSED | TILE_FLAG_SURFABLE | TILE_FLAG_HAS_ENCOUNTERS,
    [MB_DEEP_WATER]                         = TILE_FLAG_UNUSED | TILE_FLAG_SURFABLE | TILE_FLAG_HAS_ENCOUNTERS,
    [MB_WATERFALL]                          = TILE_FLAG_UNUSED | TILE_FLAG_SURFABLE,
    [MB_SOOTOPOLIS_DEEP_WATER]              = TILE_FLAG_UNUSED | TILE_FLAG_SURFABLE,
    [MB_OCEAN_WATER]                        = TILE_FLAG_UNUSED | TILE_FLAG_SURFABLE | TILE_FLAG_HAS_ENCOUNTERS,
    [MB_PUDDLE]                             = TILE_FLAG_UNUSED,
    [MB_SHALLOW_WATER]                      = TILE_FLAG_UNUSED,
    [MB_NO_SURFACING]                       = TILE_FLAG_UNUSED | TILE_FLAG_SURFABLE,
    [MB_STAIRS_OUTSIDE_ABANDONED_SHIP]      = TILE_FLAG_UNUSED,
    [MB_SHOAL_CAVE_ENTRANCE]                = TILE_FLAG_UNUSED,
    [MB_ICE]                                = TILE_FLAG_UNUSED,
    [MB_SAND]                               = TILE_FLAG_UNUSED,
    [MB_SEAWEED]                            = TILE_FLAG_UNUSED | TILE_FLAG_SURFABLE | TILE_FLAG_HAS_ENCOUNTERS,
    [MB_UNUSED_23]                          = TILE_FLAG_UNUSED,
    [MB_ASHGRASS]                           = TILE_FLAG_UNUSED | TILE_FLAG_HAS_ENCOUNTERS,
    [MB_FOOTPRINTS]                         = TILE_FLAG_UNUSED | TILE_FLAG_HAS_ENCOUNTERS,
    [MB_THIN_ICE]                           = TILE_FLAG_UNUSED,
    [MB_CRACKED_ICE]                        = TILE_FLAG_UNUSED,
    [MB_HOT_SPRINGS]                        = TILE_FLAG_UNUSED,
    [MB_LAVARIDGE_GYM_B1F_WARP]             = TILE_FLAG_UNUSED,
    [MB_SEAWEED_NO_SURFACING]               = TILE_FLAG_UNUSED | TILE_FLAG_SURFABLE | TILE_FLAG_HAS_ENCOUNTERS,
    [MB_REFLECTION_UNDER_BRIDGE]            = TILE_FLAG_UNUSED,
    [MB_IMPASSABLE_EAST]                    = TILE_FLAG_UNUSED,
    [MB_IMPASSABLE_WEST]                    = TILE_FLAG_UNUSED,
    [MB_IMPASSABLE_NORTH]                   = TILE_FLAG_UNUSED,
    [MB_IMPASSABLE_SOUTH]                   = TILE_FLAG_UNUSED,
    [MB_IMPASSABLE_NORTHEAST]               = TILE_FLAG_UNUSED,
    [MB_IMPASSABLE_NORTHWEST]               = TILE_FLAG_UNUSED,
    [MB_IMPASSABLE_SOUTHEAST]               = TILE_FLAG_UNUSED,
    [MB_IMPASSABLE_SOUTHWEST]               = TILE_FLAG_UNUSED,
    [MB_JUMP_NORTHEAST]                     = TILE_FLAG_UNUSED,
    [MB_JUMP_NORTHWEST]                     = TILE_FLAG_UNUSED,
    [MB_JUMP_SOUTHEAST]                     = TILE_FLAG_UNUSED,
    [MB_JUMP_SOUTHWEST]                     = TILE_FLAG_UNUSED,
    [MB_WALK_EAST]                          = TILE_FLAG_UNUSED,
    [MB_WALK_WEST]                          = TILE_FLAG_UNUSED,
    [MB_WALK_NORTH]                         = TILE_FLAG_UNUSED,
    [MB_WALK_SOUTH]                         = TILE_FLAG_UNUSED,
    [MB_SLIDE_EAST]                         = TILE_FLAG_UNUSED,
    [MB_SLIDE_WEST]                         = TILE_FLAG_UNUSED,
    [MB_SLIDE_NORTH]                        = TILE_FLAG_UNUSED,
    [MB_SLIDE_SOUTH]                        = TILE_FLAG_UNUSED,
    [MB_TRICK_HOUSE_PUZZLE_8_FLOOR]         = TILE_FLAG_UNUSED,
    [MB_EASTWARD_CURRENT]                   = TILE_FLAG_UNUSED | TILE_FLAG_SURFABLE,
    [MB_WESTWARD_CURRENT]                   = TILE_FLAG_UNUSED | TILE_FLAG_SURFABLE,
    [MB_NORTHWARD_CURRENT]                  = TILE_FLAG_UNUSED | TILE_FLAG_SURFABLE,
    [MB_SOUTHWARD_CURRENT]                  = TILE_FLAG_UNUSED | TILE_FLAG_SURFABLE,
    [MB_NON_ANIMATED_DOOR]                  = TILE_FLAG_UNUSED,
    [MB_LADDER]                             = TILE_FLAG_UNUSED,
    [MB_EAST_ARROW_WARP]                    = TILE_FLAG_UNUSED,
    [MB_WEST_ARROW_WARP]                    = TILE_FLAG_UNUSED,
    [MB_NORTH_ARROW_WARP]                   = TILE_FLAG_UNUSED,
    [MB_SOUTH_ARROW_WARP]                   = TILE_FLAG_UNUSED,
    [MB_CRACKED_FLOOR_HOLE]                 = TILE_FLAG_UNUSED,
    [MB_AQUA_HIDEOUT_WARP]                  = TILE_FLAG_UNUSED,
    [MB_LAVARIDGE_GYM_1F_WARP]              = TILE_FLAG_UNUSED,
    [MB_ANIMATED_DOOR]                      = TILE_FLAG_UNUSED,
    [MB_UP_ESCALATOR]                       = TILE_FLAG_UNUSED,
    [MB_DOWN_ESCALATOR]                     = TILE_FLAG_UNUSED,
    [MB_WATER_DOOR]                         = TILE_FLAG_UNUSED | TILE_FLAG_SURFABLE,
    [MB_WATER_SOUTH_ARROW_WARP]             = TILE_FLAG_UNUSED | TILE_FLAG_SURFABLE,
    [MB_DEEP_SOUTH_WARP]                    = TILE_FLAG_UNUSED,
    [MB_UNUSED_6F]                          = TILE_FLAG_UNUSED | TILE_FLAG_SURFABLE,
    [MB_BRIDGE_OVER_POND_LOW]               = TILE_FLAG_UNUSED,
    [MB_BRIDGE_OVER_POND_MED]               = TILE_FLAG_UNUSED,
    [MB_BRIDGE_OVER_POND_HIGH]              = TILE_FLAG_UNUSED,
    [MB_PACIFIDLOG_VERTICAL_LOG_TOP]        = TILE_FLAG_UNUSED,
    [MB_PACIFIDLOG_VERTICAL_LOG_BOTTOM]     = TILE_FLAG_UNUSED,
    [MB_PACIFIDLOG_HORIZONTAL_LOG_LEFT]     = TILE_FLAG_UNUSED,
    [MB_PACIFIDLOG_HORIZONTAL_LOG_RIGHT]    = TILE_FLAG_UNUSED,
    [MB_FORTREE_BRIDGE]                     = TILE_FLAG_UNUSED,
    [MB_BRIDGE_OVER_POND_MED_EDGE_1]        = TILE_FLAG_UNUSED,
    [MB_BRIDGE_OVER_POND_MED_EDGE_2]        = TILE_FLAG_UNUSED,
    [MB_BRIDGE_OVER_POND_HIGH_EDGE_1]       = TILE_FLAG_UNUSED,
    [MB_BRIDGE_OVER_POND_HIGH_EDGE_2]       = TILE_FLAG_UNUSED,
    [MB_UNUSED_BRIDGE]                      = TILE_FLAG_UNUSED,
    [MB_BIKE_BRIDGE_OVER_BARRIER]           = TILE_FLAG_UNUSED,
    [MB_SECRET_BASE_SCENERY]                = TILE_FLAG_UNUSED,
    [MB_SECRET_BASE_TRAINER_SPOT]           = TILE_FLAG_UNUSED,
    [MB_HOLDS_SMALL_DECORATION]             = TILE_FLAG_UNUSED,
    [MB_SECRET_BASE_BALLOON]                = TILE_FLAG_UNUSED,
    [MB_SECRET_BASE_IMPASSABLE]             = TILE_FLAG_UNUSED,
    [MB_SECRET_BASE_GLITTER_MAT]            = TILE_FLAG_UNUSED,
    [MB_SECRET_BASE_JUMP_MAT]               = TILE_FLAG_UNUSED,
    [MB_SECRET_BASE_SPIN_MAT]               = TILE_FLAG_UNUSED,
    [MB_SECRET_BASE_SOUND_MAT]              = TILE_FLAG_UNUSED,
    [MB_SECRET_BASE_BREAKABLE_DOOR]         = TILE_FLAG_UNUSED,
    [MB_IMPASSABLE_SOUTH_AND_NORTH]         = TILE_FLAG_UNUSED,
    [MB_IMPASSABLE_WEST_AND_EAST]           = TILE_FLAG_UNUSED,
    [MB_SECRET_BASE_HOLE]                   = TILE_FLAG_UNUSED,
    [MB_HOLDS_LARGE_DECORATION]             = TILE_FLAG_UNUSED,
    [MB_SECRET_BASE_TV_SHIELD]              = TILE_FLAG_UNUSED,
    [MB_PLAYER_ROOM_PC_ON]                  = TILE_FLAG_UNUSED,
    [MB_MUDDY_SLOPE]                        = TILE_FLAG_UNUSED,
    [MB_BUMPY_SLOPE]                        = TILE_FLAG_UNUSED,
    [MB_CRACKED_FLOOR]                      = TILE_FLAG_UNUSED,
    [MB_ISOLATED_VERTICAL_RAIL]             = TILE_FLAG_UNUSED,
    [MB_ISOLATED_HORIZONTAL_RAIL]           = TILE_FLAG_UNUSED,
    [MB_VERTICAL_RAIL]                      = TILE_FLAG_UNUSED,
    [MB_HORIZONTAL_RAIL]                    = TILE_FLAG_UNUSED,
    [MB_SIGNPOST]                           = TILE_FLAG_UNUSED,
    [MB_POKEMON_CENTRE_SIGN]                = TILE_FLAG_UNUSED,
    [MB_POKEMART_SIGN]                      = TILE_FLAG_UNUSED,
    [MB_SIDEWAYS_STAIRS_RIGHT_SIDE]         = TILE_FLAG_UNUSED,
    [MB_SIDEWAYS_STAIRS_LEFT_SIDE]          = TILE_FLAG_UNUSED,
    [MB_SIDEWAYS_STAIRS_RIGHT_SIDE_TOP]     = TILE_FLAG_UNUSED,
    [MB_SIDEWAYS_STAIRS_LEFT_SIDE_TOP]      = TILE_FLAG_UNUSED,
    [MB_SIDEWAYS_STAIRS_RIGHT_SIDE_BOTTOM]  = TILE_FLAG_UNUSED,
    [MB_SIDEWAYS_STAIRS_LEFT_SIDE_BOTTOM]   = TILE_FLAG_UNUSED,
    [MB_ROCK_STAIRS]                        = TILE_FLAG_UNUSED,
};

bool8 MetatileBehaviour_IsATile(u8 metatileBehaviour)
{
    return TRUE;
}

bool8 MetatileBehaviour_IsEncounterTile(u8 metatileBehaviour)
{
    if ((sTileBitAttributes[metatileBehaviour] & TILE_FLAG_HAS_ENCOUNTERS))
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsJumpEast(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_JUMP_EAST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsJumpWest(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_JUMP_WEST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsJumpNorth(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_JUMP_NORTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsJumpSouth(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_JUMP_SOUTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsPokeGrass(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_TALL_GRASS || metatileBehaviour == MB_LONG_GRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSandOrDeepSand(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SAND || metatileBehaviour == MB_DEEP_SAND)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsDeepSand(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_DEEP_SAND)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsReflective(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_POND_WATER
     || metatileBehaviour == MB_PUDDLE
     || metatileBehaviour == MB_UNUSED_SOOTOPOLIS_DEEP_WATER_2
     || metatileBehaviour == MB_ICE
     || metatileBehaviour == MB_SOOTOPOLIS_DEEP_WATER
     || metatileBehaviour == MB_REFLECTION_UNDER_BRIDGE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsIce(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_ICE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsWarpDoor(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_ANIMATED_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsDoor(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_PETALBURG_GYM_DOOR
     || metatileBehaviour == MB_ANIMATED_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsEscalator(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_UP_ESCALATOR
     || metatileBehaviour == MB_DOWN_ESCALATOR)
        return TRUE;
    else
        return FALSE;
}

bool8 Unref_MetatileBehaviour_IsUnused04(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_UNUSED_04)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsLadder(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_LADDER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsNonAnimDoor(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_NON_ANIMATED_DOOR
     || metatileBehaviour == MB_WATER_DOOR
     || metatileBehaviour == MB_DEEP_SOUTH_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsDeepSouthWarp(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_DEEP_SOUTH_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSurfableWaterOrUnderwater(u8 metatileBehaviour)
{
    if ((sTileBitAttributes[metatileBehaviour] & TILE_FLAG_SURFABLE))
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsEastArrowWarp(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_EAST_ARROW_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsWestArrowWarp(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_WEST_ARROW_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsNorthArrowWarp(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_NORTH_ARROW_WARP
     || metatileBehaviour == MB_STAIRS_OUTSIDE_ABANDONED_SHIP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSouthArrowWarp(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SOUTH_ARROW_WARP
     || metatileBehaviour == MB_WATER_SOUTH_ARROW_WARP
     || metatileBehaviour == MB_SHOAL_CAVE_ENTRANCE)
        return TRUE;
    else
        return FALSE;
}

bool8 Unref_MetatileBehaviour_IsArrowWarp(u8 metatileBehaviour)
{
    u8 isArrowWarp = FALSE;

    if (MetatileBehaviour_IsEastArrowWarp(metatileBehaviour)
     || MetatileBehaviour_IsWestArrowWarp(metatileBehaviour)
     || MetatileBehaviour_IsNorthArrowWarp(metatileBehaviour)
     || MetatileBehaviour_IsSouthArrowWarp(metatileBehaviour))
    {
        isArrowWarp = TRUE;
    }

    return isArrowWarp;
}

bool8 MetatileBehaviour_IsForcedMovementTile(u8 metatileBehaviour)
{
    if ((metatileBehaviour >= MB_WALK_EAST && metatileBehaviour <= MB_TRICK_HOUSE_PUZZLE_8_FLOOR)
     || (metatileBehaviour >= MB_EASTWARD_CURRENT && metatileBehaviour <= MB_SOUTHWARD_CURRENT)
     || metatileBehaviour == MB_MUDDY_SLOPE
     || metatileBehaviour == MB_CRACKED_FLOOR
     || metatileBehaviour == MB_WATERFALL
     || metatileBehaviour == MB_ICE
     || metatileBehaviour == MB_SECRET_BASE_JUMP_MAT
     || metatileBehaviour == MB_SECRET_BASE_SPIN_MAT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsIce_2(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_ICE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsTrickHouseSlipperyFloor(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_TRICK_HOUSE_PUZZLE_8_FLOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 Unref_MetatileBehaviour_IsUnused05(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_UNUSED_05)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsWalkNorth(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_WALK_NORTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsWalkSouth(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_WALK_SOUTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsWalkWest(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_WALK_WEST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsWalkEast(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_WALK_EAST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsNorthwardCurrent(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_NORTHWARD_CURRENT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSouthwardCurrent(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SOUTHWARD_CURRENT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsWestwardCurrent(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_WESTWARD_CURRENT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsEastwardCurrent(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_EASTWARD_CURRENT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSlideNorth(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SLIDE_NORTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSlideSouth(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SLIDE_SOUTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSlideWest(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SLIDE_WEST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSlideEast(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SLIDE_EAST)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsCounter(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_COUNTER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsPlayerFacingTVScreen(u8 metatileBehaviour, u8 playerDir)
{
    if (playerDir != DIR_NORTH)
        return FALSE;
    else if (metatileBehaviour == MB_TELEVISION)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsPC(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_PC)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsCableBoxResults1(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_CABLE_BOX_RESULTS_1)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsOpenSecretBaseDoor(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_SPOT_RED_CAVE_OPEN
     || metatileBehaviour == MB_SECRET_BASE_SPOT_BROWN_CAVE_OPEN
     || metatileBehaviour == MB_SECRET_BASE_SPOT_YELLOW_CAVE_OPEN
     || metatileBehaviour == MB_SECRET_BASE_SPOT_TREE_LEFT_OPEN
     || metatileBehaviour == MB_SECRET_BASE_SPOT_SHRUB_OPEN
     || metatileBehaviour == MB_SECRET_BASE_SPOT_BLUE_CAVE_OPEN
     || metatileBehaviour == MB_SECRET_BASE_SPOT_TREE_RIGHT_OPEN)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBaseCave(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_SPOT_RED_CAVE
     || metatileBehaviour == MB_SECRET_BASE_SPOT_BROWN_CAVE
     || metatileBehaviour == MB_SECRET_BASE_SPOT_YELLOW_CAVE
     || metatileBehaviour == MB_SECRET_BASE_SPOT_BLUE_CAVE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBaseTree(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_SPOT_TREE_LEFT
     || metatileBehaviour == MB_SECRET_BASE_SPOT_TREE_RIGHT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBaseShrub(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_SPOT_SHRUB)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBasePC(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_PC)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsRecordMixingSecretBasePC(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_REGISTER_PC)
        return TRUE;
    else
        return FALSE;
}

// Used by the rock/grass floor spaces that the secret base trainer is not standing on
bool8 MetatileBehaviour_IsSecretBaseScenery1(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_SCENERY)
        return TRUE;
    else
        return FALSE;
}

// Used by the rock/grass floor space that the secret base trainer stands on
bool8 MetatileBehaviour_IsSecretBaseTrainerSpot(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_TRAINER_SPOT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBaseImpassable(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_IMPASSABLE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBaseDecorationBase(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_DECORATION_BASE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBasePoster(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_POSTER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsNormal(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_NORMAL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBaseNorthWall(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_NORTH_WALL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBaseScenery2(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_SCENERY)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_HoldsSmallDecoration(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_HOLDS_SMALL_DECORATION)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_HoldsLargeDecoration(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_HOLDS_LARGE_DECORATION)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBaseHole(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_HOLE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBaseBalloon(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_BALLOON)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBaseBreakableDoor(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_BREAKABLE_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBaseSoundMat(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_SOUND_MAT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBaseGlitterMat(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_GLITTER_MAT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBaseSandOrnament(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_SAND_ORNAMENT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBaseShieldOrToyTV(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_TV_SHIELD)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsPlayerRoomPCOn(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_PLAYER_ROOM_PC_ON)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_HasRipples(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_POND_WATER
     || metatileBehaviour == MB_PUDDLE
     || metatileBehaviour == MB_SOOTOPOLIS_DEEP_WATER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsPuddle(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_PUDDLE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsTallGrass(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_TALL_GRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsLongGrass(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_LONG_GRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsBerryTreeSoil(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_BERRY_TREE_SOIL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsAshGrass(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_ASHGRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsFootprints(u8 metatileBehaviour)
{
    // MB_FOOTPRINTS is not used by any metatiles.
    if (metatileBehaviour == MB_FOOTPRINTS)
        return TRUE;
    else
        return FALSE;
}

// For the sections of log bridges that span water / water's edge.
// Note that the rest of the metatiles for these bridges use MB_NORMAL.
// This is used to allow encounters on the water below the bridge.
bool8 MetatileBehaviour_IsBridgeOverWater(u8 metatileBehaviour)
{
    if ((metatileBehaviour == MB_BRIDGE_OVER_OCEAN
      || metatileBehaviour == MB_BRIDGE_OVER_POND_LOW
      || metatileBehaviour == MB_BRIDGE_OVER_POND_MED
      || metatileBehaviour == MB_BRIDGE_OVER_POND_HIGH)
      || (metatileBehaviour == MB_BRIDGE_OVER_POND_HIGH_EDGE_1
       || metatileBehaviour == MB_BRIDGE_OVER_POND_HIGH_EDGE_2
       || metatileBehaviour == MB_UNUSED_BRIDGE
       || metatileBehaviour == MB_BIKE_BRIDGE_OVER_BARRIER))
        return TRUE;
    else
        return FALSE;
}

u8 MetatileBehaviour_GetBridgeType(u8 metatileBehaviour)
{
    // MB_BRIDGE_OVER_OCEAN     --> BRIDGE_TYPE_OCEAN     (Routes 110/119)
    // MB_BRIDGE_OVER_POND_LOW  --> BRIDGE_TYPE_POND_LOW  (Unused)
    // MB_BRIDGE_OVER_POND_MED  --> BRIDGE_TYPE_POND_MED  (Route 120, south)
    // MB_BRIDGE_OVER_POND_HIGH --> BRIDGE_TYPE_POND_HIGH (Route 120, north)
    if (metatileBehaviour >= MB_BRIDGE_OVER_OCEAN
     && metatileBehaviour <= MB_BRIDGE_OVER_POND_HIGH)
        return metatileBehaviour - MB_BRIDGE_OVER_OCEAN;

    if (metatileBehaviour >= MB_BRIDGE_OVER_POND_MED_EDGE_1
     && metatileBehaviour <= MB_BRIDGE_OVER_POND_MED_EDGE_2)
        return BRIDGE_TYPE_POND_MED;

    if (metatileBehaviour >= MB_BRIDGE_OVER_POND_HIGH_EDGE_1
     && metatileBehaviour <= MB_BRIDGE_OVER_POND_HIGH_EDGE_2)
        return BRIDGE_TYPE_POND_HIGH;

    return BRIDGE_TYPE_OCEAN;
}

// Used to allow fishing below the bridge metatiles.
bool8 MetatileBehaviour_IsBridgeOverWaterNoEdge(u8 metatileBehaviour)
{
    if (metatileBehaviour >= MB_BRIDGE_OVER_OCEAN
     && metatileBehaviour <= MB_BRIDGE_OVER_POND_HIGH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsLandWildEncounter(u8 metatileBehaviour)
{
    if (MetatileBehaviour_IsSurfableWaterOrUnderwater(metatileBehaviour) == FALSE
     && MetatileBehaviour_IsEncounterTile(metatileBehaviour) == TRUE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsWaterWildEncounter(u8 metatileBehaviour)
{
    if (MetatileBehaviour_IsSurfableWaterOrUnderwater(metatileBehaviour) == TRUE
     && MetatileBehaviour_IsEncounterTile(metatileBehaviour) == TRUE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsIndoorEncounter(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_INDOOR_ENCOUNTER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsMountain(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_MOUNTAIN_TOP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsDiveable(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_INTERIOR_DEEP_WATER
     || metatileBehaviour == MB_DEEP_WATER
     || metatileBehaviour == MB_SOOTOPOLIS_DEEP_WATER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsUnableToEmerge(u8 metatileBehaviour)
{
    // BUG: The player is unintentionally able to emerge on water doors.
    // Also the narrower underwater door in the underwater tileset has the wrong metatile behaviour. This causes the dive glitch.
    // To fix change the metatile behaviour of the narrower water door with porymap's tileset editor.
    if (metatileBehaviour == MB_NO_SURFACING
     || metatileBehaviour == MB_SEAWEED_NO_SURFACING
     #ifdef BUGFIX
     || metatileBehaviour == MB_WATER_DOOR
     #endif
     )
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsShallowFlowingWater(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SHALLOW_WATER
     || metatileBehaviour == MB_STAIRS_OUTSIDE_ABANDONED_SHIP
     || metatileBehaviour == MB_SHOAL_CAVE_ENTRANCE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsThinIce(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_THIN_ICE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsCrackedIce(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_CRACKED_ICE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsDeepOrOceanWater(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_OCEAN_WATER
     || metatileBehaviour == MB_INTERIOR_DEEP_WATER
     || metatileBehaviour == MB_DEEP_WATER)
        return TRUE;
    else
        return FALSE;
}

bool8 Unref_MetatileBehaviour_IsUnusedSootopolisWater(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_UNUSED_SOOTOPOLIS_DEEP_WATER
     || metatileBehaviour == MB_UNUSED_SOOTOPOLIS_DEEP_WATER_2)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSurfableAndNotWaterfall(u8 metatileBehaviour)
{
    if (MetatileBehaviour_IsSurfableWaterOrUnderwater(metatileBehaviour)
     && MetatileBehaviour_IsWaterfall(metatileBehaviour) == FALSE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsEastBlocked(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_IMPASSABLE_EAST
     || metatileBehaviour == MB_IMPASSABLE_NORTHEAST
     || metatileBehaviour == MB_IMPASSABLE_SOUTHEAST
     || metatileBehaviour == MB_IMPASSABLE_WEST_AND_EAST
     || metatileBehaviour == MB_SECRET_BASE_BREAKABLE_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsWestBlocked(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_IMPASSABLE_WEST
     || metatileBehaviour == MB_IMPASSABLE_NORTHWEST
     || metatileBehaviour == MB_IMPASSABLE_SOUTHWEST
     || metatileBehaviour == MB_IMPASSABLE_WEST_AND_EAST
     || metatileBehaviour == MB_SECRET_BASE_BREAKABLE_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsNorthBlocked(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_IMPASSABLE_NORTH
     || metatileBehaviour == MB_IMPASSABLE_NORTHEAST
     || metatileBehaviour == MB_IMPASSABLE_NORTHWEST
     || metatileBehaviour == MB_IMPASSABLE_SOUTH_AND_NORTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSouthBlocked(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_IMPASSABLE_SOUTH
     || metatileBehaviour == MB_IMPASSABLE_SOUTHEAST
     || metatileBehaviour == MB_IMPASSABLE_SOUTHWEST
     || metatileBehaviour == MB_IMPASSABLE_SOUTH_AND_NORTH)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsShortGrass(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SHORT_GRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsHotSprings(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_HOT_SPRINGS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsWaterfall(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_WATERFALL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsFortreeBridge(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_FORTREE_BRIDGE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsPacifidlogVerticalLogTop(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_PACIFIDLOG_VERTICAL_LOG_TOP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsPacifidlogVerticalLogBottom(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_PACIFIDLOG_VERTICAL_LOG_BOTTOM)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsPacifidlogHorizontalLogLeft(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_PACIFIDLOG_HORIZONTAL_LOG_LEFT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsPacifidlogHorizontalLogRight(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_PACIFIDLOG_HORIZONTAL_LOG_RIGHT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsPacifidlogLog(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_PACIFIDLOG_VERTICAL_LOG_TOP
     || metatileBehaviour == MB_PACIFIDLOG_VERTICAL_LOG_BOTTOM
     || metatileBehaviour == MB_PACIFIDLOG_HORIZONTAL_LOG_LEFT
     || metatileBehaviour == MB_PACIFIDLOG_HORIZONTAL_LOG_RIGHT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsTrickHousePuzzleDoor(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_TRICK_HOUSE_PUZZLE_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsRegionMap(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_REGION_MAP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsClosedSootopolisDoor(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_CLOSED_SOOTOPOLIS_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSkyPillarClosedDoor(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SKY_PILLAR_CLOSED_DOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsRoulette(u8 metatileBehaviour) // unused
{
    if (metatileBehaviour == MB_ROULETTE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsPokeblockFeeder(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_POKEBLOCK_FEEDER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBaseJumpMat(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_JUMP_MAT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSecretBaseSpinMat(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SECRET_BASE_SPIN_MAT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsLavaridgeB1FWarp(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_LAVARIDGE_GYM_B1F_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsLavaridge1FWarp(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_LAVARIDGE_GYM_1F_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsAquaHideoutWarp(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_AQUA_HIDEOUT_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsUnionRoomWarp(u8 metatileBehaviour)
{
    // This metatile behaviour is re-used for some reason by
    // the Union Room exit metatile. This function is used to
    // initiate a teleport-style warp.
    if (metatileBehaviour == MB_BRIDGE_OVER_OCEAN)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsMossdeepGymWarp(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_MOSSDEEP_GYM_WARP)
        return TRUE;
    else
        return FALSE;
}


bool8 MetatileBehaviour_IsSurfableFishableWater(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_POND_WATER
     || metatileBehaviour == MB_OCEAN_WATER
     || metatileBehaviour == MB_INTERIOR_DEEP_WATER
     || metatileBehaviour == MB_DEEP_WATER
     || metatileBehaviour == MB_SOOTOPOLIS_DEEP_WATER
     || (metatileBehaviour == MB_EASTWARD_CURRENT
      || metatileBehaviour == MB_WESTWARD_CURRENT
      || metatileBehaviour == MB_NORTHWARD_CURRENT
      || metatileBehaviour == MB_SOUTHWARD_CURRENT))
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsMtPyreHole(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_MT_PYRE_HOLE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsCrackedFloorHole(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_CRACKED_FLOOR_HOLE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsCrackedFloor(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_CRACKED_FLOOR)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsMuddySlope(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_MUDDY_SLOPE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsBumpySlope(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_BUMPY_SLOPE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsIsolatedVerticalRail(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_ISOLATED_VERTICAL_RAIL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsIsolatedHorizontalRail(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_ISOLATED_HORIZONTAL_RAIL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsVerticalRail(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_VERTICAL_RAIL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsHorizontalRail(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_HORIZONTAL_RAIL)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSeaweed(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SEAWEED || metatileBehaviour == MB_SEAWEED_NO_SURFACING)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsRunningDisallowed(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_NO_RUNNING
     || metatileBehaviour == MB_LONG_GRASS
     || metatileBehaviour == MB_HOT_SPRINGS
     || MetatileBehaviour_IsPacifidlogLog(metatileBehaviour) != FALSE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsCuttableGrass(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_TALL_GRASS
     || metatileBehaviour == MB_LONG_GRASS
     || metatileBehaviour == MB_ASHGRASS
     || metatileBehaviour == MB_LONG_GRASS_SOUTH_EDGE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsRunningShoesManual(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_RUNNING_SHOES_INSTRUCTION)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsPictureBookShelf(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_PICTURE_BOOK_SHELF)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsBookShelf(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_BOOKSHELF)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsPokeCentreBookShelf(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_POKEMON_CENTRE_BOOKSHELF)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsVase(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_VASE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsTrashCan(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_TRASH_CAN)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsShopShelf(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SHOP_SHELF)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsBlueprint(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_BLUEPRINT)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsBattlePyramidWarp(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_BATTLE_PYRAMID_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsPlayerFacingWirelessBoxResults(u8 tile, u8 playerDir)
{
    if (playerDir != CONNECTION_NORTH) // if the player isn't facing north, forget about it.
        return FALSE;
    else if (tile == MB_WIRELESS_BOX_RESULTS) // is the player's north tile the monitor with results?
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsCableBoxResults2(u8 tile, u8 playerDir)
{
    if (playerDir != CONNECTION_NORTH) // if the player isn't facing north, forget about it.
        return FALSE;
    else if (tile == MB_CABLE_BOX_RESULTS_2) // is the player's north tile the monitor with results?
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsQuestionnaire(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_QUESTIONNAIRE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsLongGrass_Duplicate(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_LONG_GRASS)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsLongGrassSouthEdge(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_LONG_GRASS_SOUTH_EDGE)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsTrainerHillTimer(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_TRAINER_HILL_TIMER)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsDirectionalUpRightStairWarp(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_UP_RIGHT_STAIR_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsDirectionalUpLeftStairWarp(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_UP_LEFT_STAIR_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsDirectionalDownRightStairWarp(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_DOWN_RIGHT_STAIR_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsDirectionalDownLeftStairWarp(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_DOWN_LEFT_STAIR_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsDirectionalStairWarp(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_UP_RIGHT_STAIR_WARP
     || metatileBehaviour == MB_UP_LEFT_STAIR_WARP
     || metatileBehaviour == MB_DOWN_RIGHT_STAIR_WARP
     || metatileBehaviour == MB_DOWN_LEFT_STAIR_WARP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSignpost(u32 metatileBehaviour)
{
    return (metatileBehaviour == MB_SIGNPOST);
}

bool8 MetatileBehaviour_IsPokemonCentreSign(u32 metatileBehaviour)
{
    return (metatileBehaviour == MB_POKEMON_CENTRE_SIGN);
}

bool8 MetatileBehaviour_IsPokeMartSign(u32 metatileBehaviour)
{
    return (metatileBehaviour == MB_POKEMART_SIGN);
}

bool8 MetatileBehaviour_IsSidewaysStairsRightSide(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SIDEWAYS_STAIRS_RIGHT_SIDE || metatileBehaviour == MB_SIDEWAYS_STAIRS_RIGHT_SIDE_BOTTOM)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSidewaysStairsLeftSide(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SIDEWAYS_STAIRS_LEFT_SIDE || metatileBehaviour == MB_SIDEWAYS_STAIRS_LEFT_SIDE_BOTTOM)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSidewaysStairsRightSideTop(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SIDEWAYS_STAIRS_RIGHT_SIDE_TOP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSidewaysStairsLeftSideTop(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SIDEWAYS_STAIRS_LEFT_SIDE_TOP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSidewaysStairsRightSideBottom(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SIDEWAYS_STAIRS_RIGHT_SIDE_BOTTOM)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSidewaysStairsLeftSideBottom(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SIDEWAYS_STAIRS_LEFT_SIDE_BOTTOM)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSidewaysStairsRightSideAny(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SIDEWAYS_STAIRS_RIGHT_SIDE
     || metatileBehaviour == MB_SIDEWAYS_STAIRS_RIGHT_SIDE_BOTTOM
     || metatileBehaviour == MB_SIDEWAYS_STAIRS_RIGHT_SIDE_TOP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsSidewaysStairsLeftSideAny(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_SIDEWAYS_STAIRS_LEFT_SIDE
     || metatileBehaviour == MB_SIDEWAYS_STAIRS_LEFT_SIDE_BOTTOM
     || metatileBehaviour == MB_SIDEWAYS_STAIRS_LEFT_SIDE_TOP)
        return TRUE;
    else
        return FALSE;
}

bool8 MetatileBehaviour_IsRockStairs(u8 metatileBehaviour)
{
    if (metatileBehaviour == MB_ROCK_STAIRS)
        return TRUE;
    else
        return FALSE;
}
