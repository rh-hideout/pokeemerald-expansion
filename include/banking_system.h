#ifndef GUARD_SAVINGS_SYSTEM_H
#define GUARD_SAVINGS_SYSTEM_H

u32 GetMoneyInBank(void);
void SetMoneyInBank(u32 amount);
u32 CalcAmountToDeposit(u32 money);
bool32 IsSavingMoney(void);
u32 GetWithdrawalAmount(void);
void CreateWithdrawalWindow(void);
void StartWithdrawMoneyTask(void);
void UpdateBankAccountAfterWithdrawal(void);

#endif // GUARD_SAVINGS_SYSTEM_H
