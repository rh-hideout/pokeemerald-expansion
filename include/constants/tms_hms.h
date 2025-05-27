#ifndef GUARD_CONSTANTS_TMS_HMS_H
#define GUARD_CONSTANTS_TMS_HMS_H

#define FOREACH_TM(F) \
    F(FOCUS_PUNCH) \
    F(DRAGON_CLAW) \
    F(SCALD) \
    F(CALM_MIND) \
    F(HOWL) \
    F(TOXIC) \
    F(FLIP_TURN) \
    F(BULK_UP) \
    F(BULLET_SEED) \
    F(U_TURN) \
    F(WAVE_CRASH) \
    F(TAUNT) \
    F(ICE_BEAM) \
    F(BLIZZARD) \
    F(HYPER_BEAM) \
    F(LIGHT_SCREEN) \
    F(PROTECT) \
    F(FREEZE_DRY) \
    F(GIGA_DRAIN) \
    F(SAFEGUARD) \
    F(FLASH_CANNON) \
    F(SOLAR_BEAM) \
    F(IRON_TAIL) \
    F(THUNDERBOLT) \
    F(THUNDER) \
    F(EARTHQUAKE) \
    F(RETURN) \
    F(DIG) \
    F(PSYCHIC) \
    F(SHADOW_BALL) \
    F(BRICK_BREAK) \
    F(SCALE_SHOT) \
    F(REFLECT) \
    F(FLING) \
    F(FLAMETHROWER) \
    F(SLUDGE_BOMB) \
    F(STEALTH_ROCK) \
    F(FIRE_BLAST) \
    F(ROCK_TOMB) \
    F(ACROBATICS) \
    F(TORMENT) \
    F(FACADE) \
    F(SECRET_POWER) \
    F(REST) \
    F(CHARGE_BEAM) \
    F(STONE_EDGE) \
    F(STEEL_WING) \
    F(DRAIN_PUNCH) \
    F(POLTERGEIST) \
    F(OVERHEAT) \
    F(POLLEN_PUFF)\
    F(LOW_KICK)\
    F(CLOSE_COMBAT)\
    F(CRUNCH)
    
#define FOREACH_HM(F) \
    F(CUT) \
    F(FLY) \
    F(SURF) \
    F(STRENGTH) \
    F(FLASH) \
    F(ROCK_SMASH) \
    F(WATERFALL) \
    F(DIVE)

#define FOREACH_TMHM(F) \
    FOREACH_TM(F) \
    FOREACH_HM(F)

#endif
