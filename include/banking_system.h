#ifndef GUARD_SAVINGS_SYSTEM_H
#define GUARD_SAVINGS_SYSTEM_H

#include "script.h"

u32 GetMoneyInBank(void);
void SetMoneyInBank(u32 amount);
u32 CalcAmountToDeposit(u32 money);
void Script_SetBankingMode(struct ScriptContext *ctx);
bool32 IsSavingMoney(void);
u32 GetWithdrawalAmount(void);
void CreateBankingWindow(void);
void StartWithdrawMoneyTask(void);
void UpdateBankAccountAfterWithdrawal(void);

#endif // GUARD_SAVINGS_SYSTEM_H
