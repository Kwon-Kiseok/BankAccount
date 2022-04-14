#pragma once
#include "Data.h"
#include "account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BoundCheckPtrArray.h"

class AccountHandler
{
private:
	//Account* accounts[MAX_ACCOUNTS_SIZE];
	BoundCheckPtrArray<Account> accounts;
	int total = 0;
public:
	AccountHandler() : total(0) {}
	~AccountHandler();

	int GetTotal() const { return total; };
	Account* GetAccount(int i) const { return accounts[i]; };

	bool CheckOverlap(int inputNo);
	void CreateAccount(Account* account);
	void DeleteAccount(int idx);
	void DepositMoney(int idx, int money) throw(InputMoneyException);
	void WithdrawMoney(int idx, int money);
	void ViewInfoAccounts(int idx) const;
	//void SaveInfo();
	//void LoadInfo();
};

