#pragma once
#include <iostream>
#include "MyString.h"

#define MAX_ACCOUNTS_SIZE 20
#define MAX_CUSTOMER_NAME 30

enum class ACCOUNT_TYPE
{
	NORMAL_ACCOUNT = 1,
	HIGHCREDIT_ACCOUNT = 2
};

class Account
{
protected:
	int mNo;
	int mMoney;
	my::string mName;
public:
	Account();
	Account(int no, int money, const my::string name);
	Account(const Account& copy);
	virtual ~Account();
	
	Account& operator=(const Account& ref);

	virtual void Deposit(int money);
	int Withdraw(int money);
	void ViewInfo() const;
	// v-table 유무가 있기 때문에
	// 정확하게 하려면 재구현 할 것만 virtual 을 붙이기
	int GetNo() const;
	int GetMoney() const;
	my::string GetName() const;
};