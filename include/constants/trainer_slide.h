#ifndef GUARD_CONSTANTS_TRAINER_SLIDE_H
#define GUARD_CONSTANTS_TRAINER_SLIDE_H

enum TrainerSlideType
{
    TRAINER_SLIDE_NONE,
    TRAINER_SLIDE_BEFORE_FIRST_TURN,

    // The following comments can be read as "This Trainer's messsage will be displayed when...":
    TRAINER_SLIDE_ATTACKER_LANDS_FIRST_CRITICAL_HIT, // their Pokemon lands a critical hit for the first time
    TRAINER_SLIDE_ATTACKER_LANDS_FIRST_SUPER_EFFECTIVE_HIT, // their Pokemon lands a super effective hit for the first time
    TRAINER_SLIDE_ATTACKER_LANDS_FIRST_STAB_MOVE, // their Pokemon lands a STAB move for the first time
    TRAINER_SLIDE_ATTACKER_FAINTS_FIRST_MON, // their Pokemon faints its first opponent
    TRAINER_SLIDE_ATTACKER_LANDS_FIRST_INEFFECTIVE, // their Pokemon lands an ineffective move for the first time

    TRAINER_SLIDE_DEFENDER_TAKES_FIRST_CRITICAL_HIT, // their Pokemon receives a critical hit for the first time
    TRAINER_SLIDE_DEFENDER_TAKES_FIRST_SUPER_EFFECTIVE_HIT, // their Pokemon receives a super effective hit for the first time
    TRAINER_SLIDE_DEFENDER_TAKES_FIRST_STAB_MOVE, // their Pokemon receives a STAB move hit for the first time
    TRAINER_SLIDE_DEFENDER_LOSES_FIRST_MON, // their first Pokemon faints
    TRAINER_SLIDE_DEFENDER_TAKES_FIRST_INEFFECTIVE, // their Pokemon receives an ineffective hit for the first time

    TRAINER_SLIDE_SELF_LAST_SWITCHIN, // they send out their last Pokemon
    TRAINER_SLIDE_SELF_LAST_HALF_HP, // their last Pokemon is between 25% and 50% HP
    TRAINER_SLIDE_SELF_LAST_LOW_HP, // their last Pokemon is under 25% HP
    TRAINER_SLIDE_SELF_MEGA_EVOLUTION, // their Pokemon is going to Mega Evolve
    TRAINER_SLIDE_SELF_Z_MOVE, // their Pokemon is going to use a Z-Move
    TRAINER_SLIDE_SELF_DYNAMAX, // their Pokemon is going to Dynamax
    TRAINER_SLIDE_SELF_TERA, // their Pokemon is going to Terastallize

    TRAINER_SLIDE_OPPONENT_LAST_SWITCHIN, // an opposing Trainer sends out their last Pokemon
    TRAINER_SLIDE_OPPONENT_LAST_HALF_HP, // their opponent's last Pokemon is between 25% and 50% HP
    TRAINER_SLIDE_OPPONENT_LAST_LOW_HP, // their opponent's last Pokemon is under 25% HP
    TRAINER_SLIDE_OPPONENT_MEGA_EVOLUTION, // an opposing Pokemon is going to Mega Evolve
    TRAINER_SLIDE_OPPONENT_Z_MOVE, // an opposing Pokemon is going to use a Z-Move
    TRAINER_SLIDE_OPPONENT_DYNAMAX, // an opposing Pokemon is going to Dynamax
    TRAINER_SLIDE_OPPONENT_TERA, // an opposing Pokemon is going to Terastallize
    TRAINER_SLIDE_COUNT,
};

#define TRAINER_SLIDES_PER_ARRAY 8
#define TRAINER_SLIDE_ARRAY_SIZE ((TRAINER_SLIDE_COUNT + TRAINER_SLIDES_PER_ARRAY - 1) / TRAINER_SLIDES_PER_ARRAY)

enum TrainerSlideTargets
{
    TRAINER_SLIDE_TARGET_NONE,
    TRAINER_SLIDE_TARGET_TRAINER_A,
    TRAINER_SLIDE_TARGET_TRAINER_B,
    TRAINER_SLIDE_TARGET_TRAINER_PARTNER,
};

#endif // GUARD_CONSTANTS_TRAINER_SLIDE_H
