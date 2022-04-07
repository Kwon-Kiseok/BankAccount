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
		Account* newAccount = nullptr;

		std::cout << "[������������]" << std::endl;
		std::cout << "1. ���뿹�ݰ���" << std::endl;
		std::cout << "2. �ſ�ŷڰ���" << std::endl;
		std::cin >> type;

		switch ((ACCOUNT_TYPE)type)
		{
		case ACCOUNT_TYPE::NORMAL_ACCOUNT:
		{
			//���뿹�ݰ��� ����
			std::cout << "[���뿹�ݰ��� ����]" << std::endl;
			break;
		}
		case ACCOUNT_TYPE::HIGHCREDIT_ACCOUNT:
			//�ſ�ŷڰ��� ����
			std::cout << "[�ſ�ŷڰ��� ����]" << std::endl;
			break;
		default:
			std::cout << "�߸��� �Է��Դϴ�." << std::endl;
			return;
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
		
		if ((ACCOUNT_TYPE)type == ACCOUNT_TYPE::NORMAL_ACCOUNT)
		{
			int ratio;
			std::cout << "������: ";
			std::cin >> ratio;
			newAccount = new NormalAccount(no, money, name, ratio);
		}
		else if ((ACCOUNT_TYPE)type == ACCOUNT_TYPE::HIGHCREDIT_ACCOUNT)
		{
			int credit;
			int ratio;
			std::cout << "������: ";
			std::cin >> ratio;
			std::cout << "�ſ���(1toA, 2toB, 3toC): ";
			std::cin >> credit;
			newAccount = new HighCreditAccount(no, money, name, ratio, credit);
		}
		std::cout << std::endl;

		handler->CreateAccount(newAccount);
	}
	break;
	case EInput::DEPOSIT:
	{
		int money;
		int no;
		std::cout << "[�� ��]" << std::endl;
		std::cout << "���¹�ȣ: ";
		std::cin >> no;

		for (int i = 0; i < handler->GetTotal(); ++i)
		{
			if (handler->GetAccount(i)->GetNo() == no)
			{
				std::cout << "�Աݾ�: ";
				std::cin >> money;
				handler->DepositMoney(i, money);
				std::cout << "�ԱݿϷ�" << std::endl;
				return;
			}
		}
		std::cout << "�Էµ� ���¹�ȣ�� �ش��ϴ� ������ �����ϴ�." << std::endl;
	}
		break;
	case EInput::WITHDRAW:
	{
		int no = 0, money = 0;

		std::cout << "[�� ��]" << std::endl;
		std::cout << "���¹�ȣ: ";
		std::cin >> no;

		for (int i = 0; i < handler->GetTotal(); ++i)
		{
			if (handler->GetAccount(i)->GetNo() == no)
			{
				std::cout << "��ݾ�: ";
				std::cin >> money;
				handler->WithdrawMoney(i, money);
				std::cout << "��ݿϷ�" << std::endl;
				return;
			}
		}
		std::cout << "�Էµ� ���¹�ȣ�� �ش��ϴ� ������ �����ϴ�." << std::endl;
	}
		break;
	case EInput::VIEWINFO:
	{
		if (handler->GetTotal() == 0)
		{
			std::cout << "����� ���������� �������� �ʽ��ϴ�." << std::endl;
			return;
		}

		for (int i = 0; i < handler->GetTotal(); ++i)
		{
			handler->ViewInfoAccounts(i);
		}
	}
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
