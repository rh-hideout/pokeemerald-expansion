#ifndef GUARD_CONSTANTS_TMS_HMS_H
#define GUARD_CONSTANTS_TMS_HMS_H

#define FOREACH_TM(F) \
    F(01, FOCUS_PUNCH) \
    F(02, DRAGON_CLAW) \
    F(03, WATER_PULSE) \
    F(04, CALM_MIND) \
    F(05, ROAR) \
    F(06, TOXIC) \
    F(07, HAIL) \
    F(08, BULK_UP) \
    F(09, BULLET_SEED) \
    F(10, HIDDEN_POWER) \
    F(11, SUNNY_DAY) \
    F(12, TAUNT) \
    F(13, ICE_BEAM) \
    F(14, BLIZZARD) \
    F(15, HYPER_BEAM) \
    F(16, LIGHT_SCREEN) \
    F(17, PROTECT) \
    F(18, RAIN_DANCE) \
    F(19, GIGA_DRAIN) \
    F(20, SAFEGUARD) \
    F(21, FRUSTRATION) \
    F(22, SOLAR_BEAM) \
    F(23, IRON_TAIL) \
    F(24, THUNDERBOLT) \
    F(25, THUNDER) \
    F(26, EARTHQUAKE) \
    F(27, RETURN) \
    F(28, DIG) \
    F(29, PSYCHIC) \
    F(30, SHADOW_BALL) \
    F(31, BRICK_BREAK) \
    F(32, DOUBLE_TEAM) \
    F(33, REFLECT) \
    F(34, SHOCK_WAVE) \
    F(35, FLAMETHROWER) \
    F(36, SLUDGE_BOMB) \
    F(37, SANDSTORM) \
    F(38, FIRE_BLAST) \
    F(39, ROCK_TOMB) \
    F(40, AERIAL_ACE) \
    F(41, TORMENT) \
    F(42, FACADE) \
    F(43, SECRET_POWER) \
    F(44, REST) \
    F(45, ATTRACT) \
    F(46, THIEF) \
    F(47, STEEL_WING) \
    F(48, SKILL_SWAP) \
    F(49, SNATCH) \
    F(50, OVERHEAT)

#define FOREACH_HM(F) \
    F(01, CUT) \
    F(02, FLY) \
    F(03, SURF) \
    F(04, STRENGTH) \
    F(05, FLASH) \
    F(06, ROCK_SMASH) \
    F(07, WATERFALL) \
    F(08, DIVE)

#define FOREACH_TMHM(F) \
    FOREACH_TM(F) \
    FOREACH_HM(F)

#endif
