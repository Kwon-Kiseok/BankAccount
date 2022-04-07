#include <iostream>
#include "AccountHandler.h"

void update();
void SelectMenu(AccountHandler* handler, EInput input);

int main()
{
	update();
	return 0;
}

void update()
{
	AccountHandler handler;
	while (1)
	{
		handler.PrintMenu();
		SelectMenu(&handler, handler.SelectMenu());
	}
}

void SelectMenu(AccountHandler* handler, EInput input)
{
	switch (input)
	{
	case EInput::CREATE_ACCOUNT:
		handler->CreateAccount();
		break;
	case EInput::DEPOSIT:
		handler->DepositMoney();
		break;
	case EInput::WITHDRAW:
		handler->WithdrawMoney();
		break;
	case EInput::VIEWINFO:
		handler->ViewInfoAccounts();
		break;
	case EInput::SAVE:
		//SaveInfo(accounts, idx);
		break;
	case EInput::LOAD:
		//LoadInfo(accounts, idx);
		break;
	case EInput::EXIT:
	{
		exit(true);
	}
	break;
	default:
		std::cout << "잘못된 입력입니다." << std::endl;
		break;
	}

	std::cout << std::endl;
}
