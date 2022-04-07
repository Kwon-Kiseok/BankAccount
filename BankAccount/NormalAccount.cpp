#include "NormalAccount.h"

void NormalAccount::Deposit(int money)
{
	money += GetInterest();
	Account::Deposit(money);
}

int NormalAccount::GetInterest() const
{
	return (Account::GetMoney() / 100) * mRatio;
}