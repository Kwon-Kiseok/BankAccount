#include <iostream>
#include <cstdio>
#include <cassert>
#include "account.h"

bool IsFindAccount(Account* accounts, int inputNo, int* idx)
{
	for (int i = 0; accounts[i].no != 0; ++i)
	{
		if (accounts[i].no == inputNo)
		{
			if (idx != nullptr)
				*idx = i;
			return true;
		}
	}

	return false;
}

void CreateAccount(Account* accounts, int* idx)
{
	int no = 0;

	std::cout << "[계좌개설]" << std::endl;
	std::cout << "계좌번호: ";
	std::cin >> no;

	if (IsFindAccount(accounts, no, nullptr))
	{
		std::cout << "입력된 계좌번호는 사용할 수 없습니다." << std::endl;
		return;
	}
	else
	{
		accounts[*idx].no = no;
		std::cout << "이름: ";
		std::cin >> accounts[*idx].name;
		std::cout << "입금액: ";
		std::cin >> accounts[*idx].money;

		(*idx)++;
	}
}

void Deposit(Account* accounts)
{
	int no = 0, money = 0;
	int idx = 0;

	std::cout << "[입 금]" << std::endl;
	std::cout << "계좌번호: ";
	std::cin >> no;

	if (!IsFindAccount(accounts, no, &idx))
	{
		std::cout << "입력된 계좌번호에 해당하는 정보가 없습니다." << std::endl;
		return;
	}

	std::cout << "입금액: ";
	std::cin >> money;
	accounts[idx].money += money;
	std::cout << "입금완료" << std::endl;
}

void Withdraw(Account* accounts)
{
	int no = 0, money = 0;
	int idx = 0;

	std::cout << "[출 금]" << std::endl;
	std::cout << "계좌번호: ";
	std::cin >> no;

	if (!IsFindAccount(accounts, no, &idx))
	{
		std::cout << "입력된 계좌번호에 해당하는 정보가 없습니다." << std::endl;
		return;
	}

	std::cout << "출금액: ";
	std::cin >> money;
	accounts[idx].money -= money;
	std::cout << "출금완료" << std::endl;
}

void ViewInfo(Account* accounts)
{
	for (int i = 0; accounts[i].no != NULL; ++i)
	{
		std::cout << "계좌번호: " << accounts[i].no << std::endl;
		std::cout << "이 름: " << accounts[i].name << std::endl;
		std::cout << "잔 액: " << accounts[i].money << std::endl;
	}
}

void Save(Account* accounts, int* idx)
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

void Load(Account* accounts, int* idx)
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
