#pragma once
#include "NormalAccount.h"

enum class CREDIT_RATING
{
	A = 1,
	B = 2,
	C = 3
};

class HighCreditAccount : public NormalAccount
{
private:
	CREDIT_RATING mCreditRating;
public:
	HighCreditAccount();
	HighCreditAccount(int no, int money, const my::string name, int ratio, CREDIT_RATING creditRating);
	HighCreditAccount(const HighCreditAccount& copy);
	virtual ~HighCreditAccount();

	CREDIT_RATING GetCreditRating() const;
	int GetInterest() const;
	virtual void Deposit(int money);
	int GetBonusInterest(int creditRating) const;
};

