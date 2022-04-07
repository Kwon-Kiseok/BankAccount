#include <iostream>
#include <cstdio>
#include <cassert>
#include "account.h"

bool IsFindAccount(Account* accounts[], int inputNo, int* idx)
{
	for (int i = 0; i < *idx; ++i)
	{
		if (accounts[i]->GetNo() == inputNo)
		{
			return true;
		}
	}
	return false;
}

void Account::Deposit(int money)
{
	mMoney += money;
}

int Account::Withdraw(int money)
{
	if (mMoney < money)
	{
		return 0;
	}
	mMoney -= money;
	return money;
}

void Account::ViewInfo()
{
	std::cout << "계좌번호: " << this->mNo << std::endl;
	std::cout << "이 름: " << this->mName << std::endl;
	std::cout << "잔 액: " << this->mMoney << std::endl;
	std::cout << std::endl;

}

void CreateAccount(Account* accounts[], int *idx)
{
	int no;
	char name[MAX_CUSTOMER_NAME];
	int money;

	std::cout << "[계좌개설]" << std::endl;
	std::cout << "계좌번호: ";
	std::cin >> no;
	
	if (IsFindAccount(accounts, no, idx))
	{
		std::cout << "중복된 계좌가 존재합니다." << std::endl;
		return;
	}
	
	std::cout << "이름: ";
	std::cin >> name;
	std::cout << "입금액: ";
	std::cin >> money;
	std::cout<<std::endl;

	accounts[(* idx)++] = new Account(no, money, name);
}

void DepositMoney(Account* accounts[], int *idx)
{
	int money;
	int no;
	std::cout << "[입 금]" << std::endl;
	std::cout << "계좌번호: ";
	std::cin >> no;

	for(int i = 0; i < *idx; ++i)
	{
		if (accounts[i]->GetNo() == no)
		{
			std::cout << "입금액: ";
			std::cin >> money;
			accounts[i]->Deposit(money);
			std::cout << "입금완료" << std::endl;
			return;
		}
	}
	std::cout << "입력된 계좌번호에 해당하는 정보가 없습니다." << std::endl;
}

void WithdrawMoney(Account* accounts[], int *idx)
{
	int no = 0, money = 0;

	std::cout << "[출 금]" << std::endl;
	std::cout << "계좌번호: ";
	std::cin >> no;

	for (int i = 0; i < *idx; ++i)
	{
		if (accounts[i]->GetNo() == no)
		{
			std::cout << "출금액: ";
			std::cin >> money;
			accounts[i]->Withdraw(money);
			std::cout << "출금완료" << std::endl;
			return;
		}
	}
	std::cout << "입력된 계좌번호에 해당하는 정보가 없습니다." << std::endl;
}

void ViewInfoAccounts(Account* accounts[], int *idx)
{
	if (*idx == 0)
	{
		std::cout << "저장된 계좌정보가 존재하지 않습니다." << std::endl;
		return;
	}

	for (int i = 0; i < *idx; ++i)
	{
		accounts[i]->ViewInfo();
	}
}

void SaveInfo(Account* accounts[], int *idx)
{
	int i = 0;
	FILE* fp;
	fopen_s(&fp, "save.dat", "wb");
	if (fp == NULL)
	{
		std::cout << "파일 읽기 실패" << std::endl;
		return;
	}

	fwrite(idx, sizeof(int), 1, fp);
	fwrite(accounts, sizeof(Account), *idx, fp);

	fclose(fp);
}

void LoadInfo(Account* accounts[], int* idx)
{
	int i = 0;
	FILE* fp;
	fopen_s(&fp, "save.dat", "rb");
	if (NULL == fp)
	{
		std::cout << "파일 읽기 실패" << std::endl;
		return;
	}

	fread(idx, sizeof(int), 1, fp);
	assert((*idx < sizeof(Account)));
	fread(accounts, sizeof(Account), *idx, fp);

	fclose(fp);
}
