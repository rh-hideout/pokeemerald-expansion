#ifndef BATTLE_PARTNER_H
#define BATTLE_PARTNER_H

#include "difficulty.h"
#include "constants/battle_partner.h"

void FillPartnerParty(u16 trainerId);
enum TrainerClassID GetPartnerClass(u16 trainerId);

#endif // BATTLE_PARTNER_H
