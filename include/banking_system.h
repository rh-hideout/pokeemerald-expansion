#ifndef GUARD_SAVINGS_SYSTEM_H
#define GUARD_SAVINGS_SYSTEM_H

#include "script.h"

bool32 IsBankingEnabled(void);
u32 GetMoneyInBank(void);
void SetMoneyInBank(u32 amount);
u32 CalcAmountToDeposit(u32 money);
void Script_SetBankingMode(struct ScriptContext *ctx);
void Script_CompareBankBalance(struct ScriptContext *ctx);
bool32 IsSavingMoney(void);
u32 GetTransactionAmount(void);
void CreateBankingWindow(void);
void Script_StartTransactionTask(struct ScriptContext *ctx);

#endif // GUARD_SAVINGS_SYSTEM_H
