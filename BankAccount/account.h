#pragma once
#include <iostream>

#define MAX_ACCOUNTS_SIZE 20
#define MAX_CUSTOMER_NAME 30

enum class ACCOUNT_TYPE
{
	NORMAL_ACCOUNT = 1,
	HIGHCREDIT_ACCOUNT = 2
};

class Account
{
private:
	int mNo;
	int mMoney;
	char* mName;
public:
	Account() : mNo(0), mMoney(0), mName(NULL) {}
	Account(int no, int money, const char* name) : mNo(no), mMoney(money)
	{
		mName = new char[strlen(name) + 1];
		strcpy_s(mName, (strlen(name) + 1), name);
	}
	Account(const Account& copy) : mNo(copy.mNo), mMoney(copy.mMoney)
	{
		mName = new char[strlen(copy.mName) + 1];
		strcpy_s(mName, (strlen(copy.mName) + 1), copy.mName);
	}
	~Account()
	{
		delete[] mName;
	}

	virtual void Deposit(int money);
	virtual int Withdraw(int money);
	virtual void ViewInfo() const;
	
	virtual int GetNo() const { return mNo; } 
	virtual int GetMoney() const { return mMoney; } 
	virtual char* GetName() const { return mName; }
};