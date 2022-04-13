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

void AccountHandler::PrintMenu()
{
	std::cout << "=Menu=" << std::endl;
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. �� ��" << std::endl;
	std::cout << "3. �� ��" << std::endl;
	std::cout << "4. ���»���" << std::endl;
	std::cout << "5. �������� ��ü ���" << std::endl;
	std::cout << "6. �� �� (������)" << std::endl;
	std::cout << "7. �ҷ����� (������)" << std::endl;
	std::cout << "8. �� ��" << std::endl;
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

EInput AccountHandler::SelectMenu()
{
	int input = 0;
	std::cout << "����: ";
	std::cin >> input;
	std::cout << std::endl;

	return (EInput)input;
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
//		std::cout << "���� �б� ����" << std::endl;
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
//		std::cout << "���� �б� ����" << std::endl;
//		return;
//	}
//
//	fread(&total, sizeof(int), 1, fp);
//	fread(accounts, sizeof(Account), total, fp);
//
//	fclose(fp);
//}