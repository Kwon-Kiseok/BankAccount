#include <iostream>
#include <cstdio>
#include <cassert>
#include "account.h"

bool IsFindAccount(Account* accounts, int inputNo, int* idx)
{
	for (int i = 0; accounts[i].GetNo() != 0; ++i)
	{
		if (accounts[i].GetNo() == inputNo)
		{
			if (idx != nullptr)
				*idx = i;
			return true;
		}
	}

	return false;
}

void Account::CreateAccount(Account* accounts[], int* idx)
{
	int no = 0;

	std::cout << "[계좌개설]" << std::endl;
	std::cout << "계좌번호: ";
	std::cin >> no;

	if (IsFindAccount(*accounts, no, nullptr))
	{
		std::cout << "입력된 계좌번호는 사용할 수 없습니다." << std::endl;
		return;
	}
	else
	{
		char name[MAX_CUSTOMER_NAME];
		int money = 0;
		std::cout << "이름: ";
		std::cin >> name;
		std::cout << "입금액: ";
		std::cin >> money;

		accounts[*idx] = new Account(no, money, name);
		(*idx)++;
	}
}

void Account::Deposit(Account* accounts)
{
	int mNo = 0, mMoney = 0;
	int idx = 0;

	std::cout << "[입 금]" << std::endl;
	std::cout << "계좌번호: ";
	std::cin >> mNo;

	if (!IsFindAccount(accounts, mNo, &idx))
	{
		std::cout << "입력된 계좌번호에 해당하는 정보가 없습니다." << std::endl;
		return;
	}

	std::cout << "입금액: ";
	std::cin >> mMoney;
	accounts[idx].mMoney += mMoney;
	std::cout << "입금완료" << std::endl;
}

void Account::Withdraw(Account* accounts)
{
	int mNo = 0, mMoney = 0;
	int idx = 0;

	std::cout << "[출 금]" << std::endl;
	std::cout << "계좌번호: ";
	std::cin >> mNo;

	if (!IsFindAccount(accounts, mNo, &idx))
	{
		std::cout << "입력된 계좌번호에 해당하는 정보가 없습니다." << std::endl;
		return;
	}

	std::cout << "출금액: ";
	std::cin >> mMoney;
	accounts[idx].mMoney -= mMoney;
	std::cout << "출금완료" << std::endl;
}

void Account::ViewInfo(Account* accounts[])
{
	for (int i = 0; accounts[i]->GetNo() != 0; ++i)
	{
		std::cout << "계좌번호: " << accounts[i]->GetNo() << std::endl;
		std::cout << "이 름: " << accounts[i]->GetName() << std::endl;
		std::cout << "잔 액: " << accounts[i]->GetMoney() << std::endl;
	}
}

void Account::Save(Account* accounts, int* idx)
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

void Account::Load(Account* accounts, int* idx)
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
