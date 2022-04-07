#include "BankSystem.h"

void BankSystem::Run()
{
	AccountHandler handler;
	while (1)
	{
		handler.PrintMenu();
		SelectMenu(&handler, handler.SelectMenu());
	}
}

void BankSystem::SelectMenu(AccountHandler* handler, EInput input)
{
	switch (input)
	{
	case EInput::CREATE_ACCOUNT:
	{
		int no;
		char name[MAX_CUSTOMER_NAME];
		int money;
		int type;

		std::cout << "[계좌종류선택]" << std::endl;
		std::cout << "1. 보통예금계좌" << std::endl;
		std::cout << "2. 신용신뢰계좌" << std::endl;
		std::cin >> type;

		switch ((ACCOUNT_TYPE)type)
		{
		case ACCOUNT_TYPE::NORMAL_ACCOUNT:
			//보통예금계좌 개설
			std::cout << "[보통예금계좌 개설]" << std::endl;
			break;
		case ACCOUNT_TYPE::HIGHCREDIT_ACCOUNT:
			//신용신뢰계좌 개설
			std::cout << "[신용신뢰계좌 개설]" << std::endl;
			break;
		}

		std::cout << "[계좌개설]" << std::endl;
		std::cout << "계좌번호: ";
		std::cin >> no;

		if (handler->CheckOverlap(no))
		{
			std::cout << "중복된 계좌가 존재합니다." << std::endl;
			return;
		}

		std::cout << "이름: ";
		std::cin >> name;
		std::cout << "입금액: ";
		std::cin >> money;
		std::cout << std::endl;

		handler->CreateAccount(new Account(no, money, name));
	}
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
