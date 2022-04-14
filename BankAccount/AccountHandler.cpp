#include "AccountHandler.h"
#include <iostream>

bool AccountHandler::CheckOverlap(int inputNo)
{
	for (int i = 0; i < total; ++i)
	{
		if (accounts[i]->GetNo() == inputNo)
		{
			return true;
		}
	}
	return false;
}

void AccountHandler::CreateAccount(Account* account)
{
	accounts[total++] = account;
}

void AccountHandler::DeleteAccount(int idx)
{
	delete accounts[idx];
	accounts[idx] = nullptr;

	for (int i = idx; i < total-1; ++i)
	{
		accounts[i] = accounts[i + 1];
	}
	total--;
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < total; ++i)
	{
		delete accounts[i];
	}
}

void AccountHandler::DepositMoney(int idx, int money) throw(InputMoneyException)
{
	if (money < 0)
	{
		InputMoneyException expn(money);
		throw expn;
	}

	accounts[idx]->Deposit(money);
}

void AccountHandler::WithdrawMoney(int idx, int money)
{
	accounts[idx]->Withdraw(money);
}

void AccountHandler::ViewInfoAccounts(int idx) const
{
	accounts[idx]->ViewInfo();
}

//void AccountHandler::SaveInfo()
//{
//	int i = 0;
//	FILE* fp;
//	fopen_s(&fp, "save.dat", "wb");
//	if (fp == NULL)
//	{
//		std::cout << "파일 읽기 실패" << std::endl;
//		return;
//	}
//
//	fwrite(&total, sizeof(int), 1, fp);
//	fwrite(accounts, sizeof(Account), total, fp);
//
//	fclose(fp);
//}

//void AccountHandler::LoadInfo()
//{
//	int i = 0;
//	FILE* fp;
//	fopen_s(&fp, "save.dat", "rb");
//	if (NULL == fp)
//	{
//		std::cout << "파일 읽기 실패" << std::endl;
//		return;
//	}
//
//	fread(&total, sizeof(int), 1, fp);
//	fread(accounts, sizeof(Account), total, fp);
//
//	fclose(fp);
//}