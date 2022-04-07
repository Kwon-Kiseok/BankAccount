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
	int mCreditRating;
public:
	HighCreditAccount() : mCreditRating(0) {}
	HighCreditAccount(int no, int money, const char* name, int ratio, int creditRating)
		: NormalAccount(no, money, name, ratio), mCreditRating(creditRating) {}
	HighCreditAccount(const HighCreditAccount& copy)
		: NormalAccount(NormalAccount::GetNo(), NormalAccount::GetMoney(), NormalAccount::GetName(), NormalAccount::GetRatio()), mCreditRating(copy.mCreditRating) {}
	~HighCreditAccount() {}

	virtual int GetCreditRating() const { return mCreditRating; }
	virtual int GetInterest() const;
	virtual void Deposit(int money);
	virtual int GetBonusInterest(int creditRating) const;
};

