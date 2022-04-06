#include <iostream>
#include "Data.h"
#include "account.h"

void update(Account* accounts[], int* idx);
void SelectMenu(Account* accounts[], int* idx, EInput input);
void Print();
EInput Input();

int main()
{
	Account* accounts = new Account[MAX_ACCOUNTS_SIZE]{};
	static int idx = 0;
	update(&accounts, &idx);
	return 0;
}

void update(Account* accounts[], int* idx)
{
	while (1)
	{
		Print();
		SelectMenu(accounts, idx, Input());
	}
}

void SelectMenu(Account* accounts[], int* idx, EInput input)
{
	switch (input)
	{
	case EInput::CREATE_ACCOUNT:
		accounts[*idx]->CreateAccount(accounts, idx);
		break;
	case EInput::DEPOSIT:
		//accounts[*idx]->Deposit(accounts);
		break;
	case EInput::WITHDRAW:
		//accounts->Withdraw(accounts);
		break;
	case EInput::VIEWINFO:
		accounts[*idx]->ViewInfo(accounts);
		break;
	case EInput::SAVE:
		//accounts->Save(accounts, idx);
		break;
	case EInput::LOAD:
		//accounts->Load(accounts, idx);
		break;
	case EInput::EXIT:
	{
		delete[] accounts;
		exit(true);
	}
	break;
	default:
		std::cout << "�߸��� �Է��Դϴ�." << std::endl;
		break;
	}

	std::cout << std::endl;
}

void Print()
{
	std::cout << "=Menu=" << std::endl;
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. �� ��" << std::endl;
	std::cout << "3. �� ��" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. �� ��" << std::endl;
	std::cout << "6. �ҷ�����" << std::endl;
	std::cout << "7. �� ��" << std::endl;
}

EInput Input()
{
	int input = 0;
	std::cout << "����: ";
	std::cin >> input;
	std::cout << std::endl;

	return (EInput)input;
}
