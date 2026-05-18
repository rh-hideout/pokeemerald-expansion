#ifndef GUARD_SAVINGS_SYSTEM_H
#define GUARD_SAVINGS_SYSTEM_H

#include "script.h"

 struct __attribute__((packed)) Banking
{
    u32 savings;
    u16 deposited;
    u8 lastBought:6;
    bool8 isPending:1;
    bool8 isRepeat:1;
};
bool32 IsBankingEnabled(void);
u32 GetMoneyInBank(void);
void SetMoneyInBank(u32 amount);
void DepositAndTrackMoney(u32 amount);
void NewGameInitBanking(void);
u32 CalcAmountToDeposit(u32 money);
void Script_SetBankingMode(struct ScriptContext *ctx);
void Script_CompareBankBalance(struct ScriptContext *ctx);
void Script_GetBankBalanceString(void);
bool32 IsSavingMoney(void);
u32 GetTransactionAmount(void);
void CreateBankingWindow(void);
void Script_StartTransactionTask(struct ScriptContext *ctx);
u32 PurchaseRepeatItem(void);
u32 TriggerBankingPurchase(u32 toDeposit);

#endif // GUARD_SAVINGS_SYSTEM_H
