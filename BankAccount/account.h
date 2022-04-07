#pragma once

#define MAX_ACCOUNTS_SIZE 20
#define MAX_CUSTOMER_NAME 30

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
	
	int GetNo() const { return mNo; } 
	int GetMoney() const { return mMoney; } 
	char* GetName() const { return mName; }

	void SetNo(int no) { mNo = no; }
	void SetMoney(int money) { mMoney = money; }
	void SetName(char* name)
	{
		mName = new char[strlen(name) + 1];
		strcpy_s(mName, (strlen(name) + 1), name);
	}

	void Deposit(int money);
	int Withdraw(int money);
	void ViewInfo();
};

void CreateAccount(Account* accounts[], int *idx);
void DepositMoney(Account* accounts[], int *idx);
void WithdrawMoney(Account* accounts[], int *idx);
void ViewInfoAccounts(Account* accounts[], int *idx);
void SaveInfo(Account* accounts[], int* idx);
void LoadInfo(Account* accounts[], int* idx);