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

	std::cout << "[���°���]" << std::endl;
	std::cout << "���¹�ȣ: ";
	std::cin >> no;

	if (IsFindAccount(*accounts, no, nullptr))
	{
		std::cout << "�Էµ� ���¹�ȣ�� ����� �� �����ϴ�." << std::endl;
		return;
	}
	else
	{
		char name[MAX_CUSTOMER_NAME];
		int money = 0;
		std::cout << "�̸�: ";
		std::cin >> name;
		std::cout << "�Աݾ�: ";
		std::cin >> money;

		accounts[*idx] = new Account(no, money, name);
		(*idx)++;
	}
}

void Account::Deposit(Account* accounts)
{
	int mNo = 0, mMoney = 0;
	int idx = 0;

	std::cout << "[�� ��]" << std::endl;
	std::cout << "���¹�ȣ: ";
	std::cin >> mNo;

	if (!IsFindAccount(accounts, mNo, &idx))
	{
		std::cout << "�Էµ� ���¹�ȣ�� �ش��ϴ� ������ �����ϴ�." << std::endl;
		return;
	}

	std::cout << "�Աݾ�: ";
	std::cin >> mMoney;
	accounts[idx].mMoney += mMoney;
	std::cout << "�ԱݿϷ�" << std::endl;
}

void Account::Withdraw(Account* accounts)
{
	int mNo = 0, mMoney = 0;
	int idx = 0;

	std::cout << "[�� ��]" << std::endl;
	std::cout << "���¹�ȣ: ";
	std::cin >> mNo;

	if (!IsFindAccount(accounts, mNo, &idx))
	{
		std::cout << "�Էµ� ���¹�ȣ�� �ش��ϴ� ������ �����ϴ�." << std::endl;
		return;
	}

	std::cout << "��ݾ�: ";
	std::cin >> mMoney;
	accounts[idx].mMoney -= mMoney;
	std::cout << "��ݿϷ�" << std::endl;
}

void Account::ViewInfo(Account* accounts[])
{
	for (int i = 0; accounts[i]->GetNo() != 0; ++i)
	{
		std::cout << "���¹�ȣ: " << accounts[i]->GetNo() << std::endl;
		std::cout << "�� ��: " << accounts[i]->GetName() << std::endl;
		std::cout << "�� ��: " << accounts[i]->GetMoney() << std::endl;
	}
}

void Account::Save(Account* accounts, int* idx)
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

void Account::Load(Account* accounts, int* idx)
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
