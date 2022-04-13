#include "NormalAccount.h"

NormalAccount::NormalAccount() : mRatio(0)
{
}

NormalAccount::NormalAccount(int no, int money, const my::string name, int ratio)
	: Account(no, money, name), mRatio(ratio) {}

NormalAccount::NormalAccount(const NormalAccount& copy)
	: Account(copy), mRatio(copy.mRatio) {}

NormalAccount::~NormalAccount() {}

int NormalAccount::GetRatio() const
{
	return mRatio;
}

void NormalAccount::Deposit(int money)
{
	money += GetInterest();
	Account::Deposit(money);
	// protected로 멤버변수 받아와서 그냥 더해와도 됨
}

int NormalAccount::GetInterest() const
{
	return (Account::GetMoney() * mRatio / 100);
}