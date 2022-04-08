#pragma once
#include "Data.h"
#include "account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountArray.h"

class AccountHandler
{
private:
	//Account* accounts[MAX_ACCOUNTS_SIZE];
	AccountArray accounts;
	int total = 0;
public:
	AccountHandler() : total(0) {}
	~AccountHandler();

	void PrintMenu();
	EInput SelectMenu();

	int GetTotal() const { return total; };
	Account* GetAccount(int i) const { return accounts[i]; };

	bool CheckOverlap(int inputNo);
	void CreateAccount(Account* account);
	void DepositMoney(int idx, int money);
	void WithdrawMoney(int idx, int money);
	void ViewInfoAccounts(int idx) const;
	//void SaveInfo();
	//void LoadInfo();
};

