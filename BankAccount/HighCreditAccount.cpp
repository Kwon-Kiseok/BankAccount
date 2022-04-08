#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount() : mCreditRating(CREDIT_RATING::A) 
{
}

HighCreditAccount::HighCreditAccount(int no, int money, const char* name, int ratio, CREDIT_RATING creditRating)
	: NormalAccount(no, money, name, ratio), mCreditRating(creditRating) 
{
}

HighCreditAccount::HighCreditAccount(const HighCreditAccount& copy)
	: NormalAccount(copy), mCreditRating(copy.mCreditRating) {}

HighCreditAccount::~HighCreditAccount() {}

CREDIT_RATING HighCreditAccount::GetCreditRating() const
{
	return mCreditRating;
}

int HighCreditAccount::GetInterest() const
{
	return (Account::GetMoney()/100) * (NormalAccount::GetRatio() + GetBonusInterest((int)mCreditRating));
}

void HighCreditAccount::Deposit(int money)
{
	money += GetInterest();
	Account::Deposit(money);
}

int HighCreditAccount::GetBonusInterest(int creditRating) const
{
	switch ((CREDIT_RATING)creditRating)
	{
	case CREDIT_RATING::A:
		return 7;
	case CREDIT_RATING::B:
		return 4;
	case CREDIT_RATING::C:
		return 2;
	default:
		return 0;
	}
}
