#include "BankSystem.h"
#include "Exception.h"

static bool bQuit = false;

void BankSystem::Run()
{

	while (!bQuit)
	{
		PrintMenu();
		InputSelect();
		SelectMenu();
	}
}

void BankSystem::SelectMenu()
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

		std::cout << "[계좌종류선택]" << std::endl;
		std::cout << "1. 보통예금계좌" << std::endl;
		std::cout << "2. 신용신뢰계좌" << std::endl;
		std::cin >> type;

		switch ((ACCOUNT_TYPE)type)
		{
		case ACCOUNT_TYPE::NORMAL_ACCOUNT:
		{
			//보통예금계좌 개설
			std::cout << "[보통예금계좌 개설]" << std::endl;
			break;
		}
		case ACCOUNT_TYPE::HIGHCREDIT_ACCOUNT:
			//신용신뢰계좌 개설
			std::cout << "[신용신뢰계좌 개설]" << std::endl;
			break;
		default:
			std::cout << "잘못된 입력입니다." << std::endl;
			return;
		}

		std::cout << "[계좌개설]" << std::endl;
		std::cout << "계좌번호: ";
		std::cin >> no;

		if (handler.CheckOverlap(no))
		{
			std::cout << "중복된 계좌가 존재합니다." << std::endl;
			return;
		}

		std::cout << "이름: ";
		std::cin >> name;
		std::cout << "입금액: ";
		std::cin >> money;
		
		if ((ACCOUNT_TYPE)type == ACCOUNT_TYPE::NORMAL_ACCOUNT)
		{
			int ratio;
			std::cout << "이자율: ";
			std::cin >> ratio;
			newAccount = new NormalAccount(no, money, name, ratio);
		}
		else if ((ACCOUNT_TYPE)type == ACCOUNT_TYPE::HIGHCREDIT_ACCOUNT)
		{
			int credit;
			int ratio;
			std::cout << "이자율: ";
			std::cin >> ratio;
			std::cout << "신용등급(1toA, 2toB, 3toC): ";
			std::cin >> credit;
			newAccount = new HighCreditAccount(no, money, name, ratio, (CREDIT_RATING)credit);
		}
		std::cout << std::endl;

		handler.CreateAccount(newAccount);
	}
	break;
	case EInput::DEPOSIT:
	{
		int money;
		int no;
		std::cout << "[입 금]" << std::endl;
		std::cout << "계좌번호: ";
		std::cin >> no;

		for (int i = 0; i < handler.GetTotal(); ++i)
		{
			if (handler.GetAccount(i)->GetNo() == no)
			{
				while (1)
				{
					try
					{
						std::cout << "입금액: ";
						std::cin >> money;
						handler.DepositMoney(i, money);
						break;
					}
					catch (InputMoneyException& expn)
					{
						expn.ShowMessage();
					}
				}
				std::cout << "입금완료" << std::endl;
				return;
			}
		}
		std::cout << "입력된 계좌번호에 해당하는 정보가 없습니다." << std::endl;
	}
		break;
	case EInput::WITHDRAW:
	{
		int no = 0, money = 0;

		std::cout << "[출 금]" << std::endl;
		std::cout << "계좌번호: ";
		std::cin >> no;

		for (int i = 0; i < handler.GetTotal(); ++i)
		{
			if (handler.GetAccount(i)->GetNo() == no)
			{
				while (1)
				{
					try
					{
						std::cout << "출금액: ";
						std::cin >> money;
						handler.WithdrawMoney(i, money);

						std::cout << "출금완료" << std::endl;
						break;
					}
					catch (InputMoneyException& expn)
					{
						expn.ShowMessage();
					}
					catch (WithdrawException& expn)
					{
						expn.ShowMessage();
					}
				}
				return;
			}
		}
		std::cout << "입력된 계좌번호에 해당하는 정보가 없습니다." << std::endl;
	}
		break;
	case EInput::DELETE_ACCOUNT:
	{
		int no;

		std::cout << "[계좌삭제]" << std::endl;
		std::cout << "계좌번호: ";
		std::cin >> no;

		for (int i = 0; i < handler.GetTotal(); ++i)
		{
			if (handler.GetAccount(i)->GetNo() == no)
			{
				handler.DeleteAccount(i);
				std::cout << "해당 계좌가 삭제되었습니다." << std::endl;
				return;
			}
		}
		std::cout << "해당 계좌는 존재하지 않습니다." << std::endl;
	}
		break;
	case EInput::VIEWINFO:
	{
		if (handler.GetTotal() == 0)
		{
			std::cout << "저장된 계좌정보가 존재하지 않습니다." << std::endl;
			return;
		}

		for (int i = 0; i < handler.GetTotal(); ++i)
		{
			handler.ViewInfoAccounts(i); // 핸들러에서 처리하도록 수정
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
		bQuit = true;
		return;
		//exit(true); // -> 프로세스 자체를 종료, 소멸자들을 호출을 안함.
	}
	break;
	default:
		std::cout << "잘못된 입력입니다." << std::endl;
		break;
	}

	std::cout << std::endl;
}

void BankSystem::PrintMenu()
{
	std::cout << "=Menu=" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입 금" << std::endl;
	std::cout << "3. 출 금" << std::endl;
	std::cout << "4. 계좌삭제" << std::endl;
	std::cout << "5. 계좌정보 전체 출력" << std::endl;
	std::cout << "6. 저 장 (공사중)" << std::endl;
	std::cout << "7. 불러오기 (공사중)" << std::endl;
	std::cout << "8. 종 료" << std::endl;
}

EInput BankSystem::InputSelect()
{
	int input = 0;
	std::cout << "선택: ";
	std::cin >> input;
	std::cout << std::endl;

	return this->input = static_cast<EInput>(input);
}
