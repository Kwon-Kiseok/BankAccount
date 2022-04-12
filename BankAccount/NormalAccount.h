#pragma once
#include "account.h"

class NormalAccount : public Account
{
protected:
	int mRatio;
public:
	NormalAccount();
	NormalAccount(int no, int money, const my::string name, int ratio);
	NormalAccount(const NormalAccount& copy);
	virtual ~NormalAccount();
	
	int GetRatio() const;
	virtual void Deposit(int money);
	int GetInterest() const;
};

