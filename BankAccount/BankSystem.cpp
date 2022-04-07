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

		std::cout << "[������������]" << std::endl;
		std::cout << "1. ���뿹�ݰ���" << std::endl;
		std::cout << "2. �ſ�ŷڰ���" << std::endl;
		std::cin >> type;

		switch ((ACCOUNT_TYPE)type)
		{
		case ACCOUNT_TYPE::NORMAL_ACCOUNT:
			//���뿹�ݰ��� ����
			std::cout << "[���뿹�ݰ��� ����]" << std::endl;
			break;
		case ACCOUNT_TYPE::HIGHCREDIT_ACCOUNT:
			//�ſ�ŷڰ��� ����
			std::cout << "[�ſ�ŷڰ��� ����]" << std::endl;
			break;
		}

		std::cout << "[���°���]" << std::endl;
		std::cout << "���¹�ȣ: ";
		std::cin >> no;

		if (handler->CheckOverlap(no))
		{
			std::cout << "�ߺ��� ���°� �����մϴ�." << std::endl;
			return;
		}

		std::cout << "�̸�: ";
		std::cin >> name;
		std::cout << "�Աݾ�: ";
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
		std::cout << "�߸��� �Է��Դϴ�." << std::endl;
		break;
	}

	std::cout << std::endl;
}
