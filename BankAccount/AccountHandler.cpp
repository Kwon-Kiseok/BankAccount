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

void AccountHandler::PrintMenu()
{
	std::cout << "=Menu=" << std::endl;
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. �� ��" << std::endl;
	std::cout << "3. �� ��" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. �� �� (������)" << std::endl;
	std::cout << "6. �ҷ����� (������)" << std::endl;
	std::cout << "7. �� ��" << std::endl;
}

void AccountHandler::DepositMoney()
{
	int money;
	int no;
	std::cout << "[�� ��]" << std::endl;
	std::cout << "���¹�ȣ: ";
	std::cin >> no;

	for (int i = 0; i < total; ++i)
	{
		if (accounts[i]->GetNo() == no)
		{
			std::cout << "�Աݾ�: ";
			std::cin >> money;
			accounts[i]->Deposit(money);
			std::cout << "�ԱݿϷ�" << std::endl;
			return;
		}
	}
	std::cout << "�Էµ� ���¹�ȣ�� �ش��ϴ� ������ �����ϴ�." << std::endl;
}

EInput AccountHandler::SelectMenu()
{
	int input = 0;
	std::cout << "����: ";
	std::cin >> input;
	std::cout << std::endl;

	return (EInput)input;
}

void AccountHandler::WithdrawMoney()
{
	int no = 0, money = 0;

	std::cout << "[�� ��]" << std::endl;
	std::cout << "���¹�ȣ: ";
	std::cin >> no;

	for (int i = 0; i < total; ++i)
	{
		if (accounts[i]->GetNo() == no)
		{
			std::cout << "��ݾ�: ";
			std::cin >> money;
			accounts[i]->Withdraw(money);
			std::cout << "��ݿϷ�" << std::endl;
			return;
		}
	}
	std::cout << "�Էµ� ���¹�ȣ�� �ش��ϴ� ������ �����ϴ�." << std::endl;
}

void AccountHandler::ViewInfoAccounts() const
{
	if (total == 0)
	{
		std::cout << "����� ���������� �������� �ʽ��ϴ�." << std::endl;
		return;
	}

	for (int i = 0; i < total; ++i)
	{
		accounts[i]->ViewInfo();
	}
}

void AccountHandler::SaveInfo()
{
	int i = 0;
	FILE* fp;
	fopen_s(&fp, "save.dat", "wb");
	if (fp == NULL)
	{
		std::cout << "���� �б� ����" << std::endl;
		return;
	}

	fwrite(&total, sizeof(int), 1, fp);
	fwrite(accounts, sizeof(Account), total, fp);

	fclose(fp);
}

void AccountHandler::LoadInfo()
{
	int i = 0;
	FILE* fp;
	fopen_s(&fp, "save.dat", "rb");
	if (NULL == fp)
	{
		std::cout << "���� �б� ����" << std::endl;
		return;
	}

	fread(&total, sizeof(int), 1, fp);
	fread(accounts, sizeof(Account), total, fp);

	fclose(fp);
}