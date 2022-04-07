#pragma once
#include "Data.h"
#include "account.h"

class AccountHandler
{
private:
	Account* accounts[MAX_ACCOUNTS_SIZE];
	int total = 0;
public:
	AccountHandler() : total(0) {}
	~AccountHandler()
	{
		for (int i = 0; i < total; ++i)
		{
			delete accounts[i];
		}
	}

	void PrintMenu();
	EInput SelectMenu();
	void CreateAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ViewInfoAccounts() const;
	void SaveInfo();
	void LoadInfo();
};

