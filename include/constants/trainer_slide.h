#ifndef GUARD_CONSTANTS_TRAINER_SLIDE_H
#define GUARD_CONSTANTS_TRAINER_SLIDE_H

enum TrainerSlideType
{
    TRAINER_SLIDE_NONE,
    TRAINER_SLIDE_BEFORE_FIRST_TURN,

    TRAINER_SLIDE_ATTACKER_LANDS_FIRST_CRITICAL_HIT, // Slide activates for the attacking battler when it lands its first crit
    TRAINER_SLIDE_ATTACKER_LANDS_FIRST_SUPER_EFFECTIVE_HIT, // Slide activates for the attacking battler when it lands its first supereffective hit
    TRAINER_SLIDE_ATTACKER_LANDS_FIRST_STAB_MOVE, // Slide activates for the attacking battler when it lands its first STAB hit
    TRAINER_SLIDE_ATTACKER_FAINTS_FIRST_MON, // Slide activates for the attacking battler when it faints its first opponent
    TRAINER_SLIDE_ATTACKER_LANDS_FIRST_INEFFECTIVE, // Slide activates for the attacking battler when it lands its first ineffective move

    TRAINER_SLIDE_DEFENDER_TAKES_FIRST_CRITICAL_HIT, // Slide activates for the defending battler when it takes its first crit
    TRAINER_SLIDE_DEFENDER_TAKES_FIRST_SUPER_EFFECTIVE_HIT, // Slide activates for the defending battler when it takes its first supereffective hit
    TRAINER_SLIDE_DEFENDER_TAKES_FIRST_STAB_MOVE, // Slide activates for the defending battler when it takes its first STAB hit
    TRAINER_SLIDE_DEFENDER_LOSES_FIRST_MON, // Slide activates for the defending battler when its first mon is lost
    TRAINER_SLIDE_DEFENDER_TAKES_FIRST_INEFFECTIVE, // Slide activates for the defending battler when it takes its first ineffective move

    TRAINER_SLIDE_SELF_LAST_SWITCHIN, // Slide activates for the battler when it sends out its last mon
    TRAINER_SLIDE_SELF_LAST_HALF_HP, // Slide activates for the battler when its last mon is between 25-50% HP
    TRAINER_SLIDE_SELF_LAST_LOW_HP, // Slide activates for the battler when its last mon is under 25% HP
    TRAINER_SLIDE_SELF_MEGA_EVOLUTION, // Slide activates for the battler when it is about to Mega
    TRAINER_SLIDE_SELF_Z_MOVE, // Slide activates for the battler when it is about to use a Z move
    TRAINER_SLIDE_SELF_DYNAMAX, // Slide activates for the battler when it is about to Dynamax
    TRAINER_SLIDE_SELF_TERA, // Slide activates for the battler when it is about to Tera

    TRAINER_SLIDE_OPPONENT_LAST_SWITCHIN, // Slide activates for the battler when its opponent(s) sends out their last mon
    TRAINER_SLIDE_OPPONENT_LAST_HALF_HP, // Slide activates for the battler when its opponent(s) last mon is between 25-50% HP
    TRAINER_SLIDE_OPPONENT_LAST_LOW_HP, // Slide activates for the battler when its opponent(s) last mon is under 25% HP
    TRAINER_SLIDE_OPPONENT_MEGA_EVOLUTION, // Slide activates for the battler when its opponent is about to Mega
    TRAINER_SLIDE_OPPONENT_Z_MOVE, // Slide activates for the battler when its opponent is about to use a Z move
    TRAINER_SLIDE_OPPONENT_DYNAMAX, // Slide activates for the battler when its opponent is about to Dynamax
    TRAINER_SLIDE_OPPONENT_TERA, // Slide activates for the battler when its opponent is about to Tera
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
