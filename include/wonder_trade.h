#ifndef GUARD_WONDER_TRADE_H
#define GUARD_WONDER_TRADE_H

void CreateWonderTradePokemon(void);

struct WonderTradeTrainer
{
    const u8 *otName;
    u32 otId;
    u8 otGender;
};

#define WONDER_TRADE_TRAINERS 400

#endif //GUARD_WONDER_TRADE_H