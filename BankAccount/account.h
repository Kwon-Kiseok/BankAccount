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
	// v-table ������ �ֱ� ������
	// ��Ȯ�ϰ� �Ϸ��� �籸�� �� �͸� virtual �� ���̱�
	int GetNo() const;
	int GetMoney() const;
	my::string GetName() const;
};