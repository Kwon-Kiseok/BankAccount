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

	NormalAccount& operator=(const NormalAccount& ref);
	
	int GetRatio() const;
	virtual void Deposit(int money);
	int GetInterest() const;
};

