#include "HighCreditAccount.h"

int HighCreditAccount::GetInterest() const
{
	return (Account::GetMoney()/100) * (NormalAccount::GetRatio() + GetBonusInterest(mCreditRating));
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
