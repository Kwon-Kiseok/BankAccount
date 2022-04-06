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

	std::cout << "[���°���]" << std::endl;
	std::cout << "���¹�ȣ: ";
	std::cin >> no;

	if (IsFindAccount(accounts, no, nullptr))
	{
		std::cout << "�Էµ� ���¹�ȣ�� ����� �� �����ϴ�." << std::endl;
		return;
	}
	else
	{
		accounts[*idx].no = no;
		std::cout << "�̸�: ";
		std::cin >> accounts[*idx].name;
		std::cout << "�Աݾ�: ";
		std::cin >> accounts[*idx].money;

		(*idx)++;
	}
}

void Deposit(Account* accounts)
{
	int no = 0, money = 0;
	int idx = 0;

	std::cout << "[�� ��]" << std::endl;
	std::cout << "���¹�ȣ: ";
	std::cin >> no;

	if (!IsFindAccount(accounts, no, &idx))
	{
		std::cout << "�Էµ� ���¹�ȣ�� �ش��ϴ� ������ �����ϴ�." << std::endl;
		return;
	}

	std::cout << "�Աݾ�: ";
	std::cin >> money;
	accounts[idx].money += money;
	std::cout << "�ԱݿϷ�" << std::endl;
}

void Withdraw(Account* accounts)
{
	int no = 0, money = 0;
	int idx = 0;

	std::cout << "[�� ��]" << std::endl;
	std::cout << "���¹�ȣ: ";
	std::cin >> no;

	if (!IsFindAccount(accounts, no, &idx))
	{
		std::cout << "�Էµ� ���¹�ȣ�� �ش��ϴ� ������ �����ϴ�." << std::endl;
		return;
	}

	std::cout << "��ݾ�: ";
	std::cin >> money;
	accounts[idx].money -= money;
	std::cout << "��ݿϷ�" << std::endl;
}

void ViewInfo(Account* accounts)
{
	for (int i = 0; accounts[i].no != NULL; ++i)
	{
		std::cout << "���¹�ȣ: " << accounts[i].no << std::endl;
		std::cout << "�� ��: " << accounts[i].name << std::endl;
		std::cout << "�� ��: " << accounts[i].money << std::endl;
	}
}

void Save(Account* accounts, int* idx)
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

void Load(Account* accounts, int* idx)
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
