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
	std::cout << "���¹�ȣ: " << this->mNo << std::endl;
	std::cout << "�� ��: " << this->mName << std::endl;
	std::cout << "�� ��: " << this->mMoney << std::endl;
	std::cout << std::endl;

}

void CreateAccount(Account* accounts[], int *idx)
{
	int no;
	char name[MAX_CUSTOMER_NAME];
	int money;

	std::cout << "[���°���]" << std::endl;
	std::cout << "���¹�ȣ: ";
	std::cin >> no;
	
	if (IsFindAccount(accounts, no, idx))
	{
		std::cout << "�ߺ��� ���°� �����մϴ�." << std::endl;
		return;
	}
	
	std::cout << "�̸�: ";
	std::cin >> name;
	std::cout << "�Աݾ�: ";
	std::cin >> money;
	std::cout<<std::endl;

	accounts[(* idx)++] = new Account(no, money, name);
}

void DepositMoney(Account* accounts[], int *idx)
{
	int money;
	int no;
	std::cout << "[�� ��]" << std::endl;
	std::cout << "���¹�ȣ: ";
	std::cin >> no;

	for(int i = 0; i < *idx; ++i)
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

void WithdrawMoney(Account* accounts[], int *idx)
{
	int no = 0, money = 0;

	std::cout << "[�� ��]" << std::endl;
	std::cout << "���¹�ȣ: ";
	std::cin >> no;

	for (int i = 0; i < *idx; ++i)
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

void ViewInfoAccounts(Account* accounts[], int *idx)
{
	if (*idx == 0)
	{
		std::cout << "����� ���������� �������� �ʽ��ϴ�." << std::endl;
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
		std::cout << "���� �б� ����" << std::endl;
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
		std::cout << "���� �б� ����" << std::endl;
		return;
	}

	fread(idx, sizeof(int), 1, fp);
	assert((*idx < sizeof(Account)));
	fread(accounts, sizeof(Account), *idx, fp);

	fclose(fp);
}
