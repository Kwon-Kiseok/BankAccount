#pragma once
#include "account.h"

class NormalAccount : public Account
{
private:
	int mRatio;	// �⺻ ����
public:
	NormalAccount() : mRatio(0) {}
	NormalAccount(int no, int money, const char* name, int ratio)
		: Account(no, money, name), mRatio(ratio) {}
	NormalAccount(const NormalAccount& copy)
		: Account(Account::GetNo(), Account::GetMoney(), Account::GetName()), mRatio(copy.mRatio) {}
	~NormalAccount() {}
	
	virtual void Deposit(int money);
	virtual int GetInterest() const;
};

