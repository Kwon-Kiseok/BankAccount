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
		std::cout << "잘못된 입력입니다." << std::endl;
		break;
	}

	std::cout << std::endl;
}

void Print()
{
	std::cout << "=Menu=" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입 금" << std::endl;
	std::cout << "3. 출 금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 저 장" << std::endl;
	std::cout << "6. 불러오기" << std::endl;
	std::cout << "7. 종 료" << std::endl;
}

EInput Input()
{
	int input = 0;
	std::cout << "선택: ";
	std::cin >> input;
	std::cout << std::endl;

	return (EInput)input;
}
