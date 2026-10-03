#include "global.h"
#include "constants/trainers.h"

static enum TrainerPicID GetEmeraldTrainerPic(enum TrainerGender gender)
{
    return gender == TRAINER_GENDER_MALE ? TRAINER_PIC_BRENDAN : TRAINER_PIC_MAY;
}
static enum TrainerPicID GetRSTrainerPic(enum TrainerGender gender)
{
    return gender == TRAINER_GENDER_MALE ? TRAINER_PIC_RS_BRENDAN : TRAINER_PIC_RS_MAY;
}

static enum TrainerPicID GetKantoTrainerPic(enum TrainerGender gender)
{
    return gender == TRAINER_GENDER_MALE ? TRAINER_PIC_RED : TRAINER_PIC_LEAF;
}

enum TrainerPicID GetPlayerTrainerPic(enum TrainerGender gender, enum GameVersion version)
{
    switch (version)
    {
        case VERSION_SAPPHIRE:
        case VERSION_RUBY:
            return GetRSTrainerPic(gender);
        case VERSION_LEAF_GREEN:
        case VERSION_FIRE_RED:
            return GetKantoTrainerPic(gender);
        case VERSION_EMERALD:
        default:
            return GetEmeraldTrainerPic(gender);
    }
}
