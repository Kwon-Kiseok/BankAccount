#include "AccountHandler.h"
#include <iostream>

bool AccountHandler::CheckOverlap(int inputNo)
{
	for (int i = 0; i < total; ++i)
	{
		if (accounts[i]->GetNo() == inputNo)
		{
			return true;
		}
	}
	return false;
}

void AccountHandler::CreateAccount(Account* account)
{
	accounts[total++] = account;
}

void AccountHandler::PrintMenu()
{
	std::cout << "=Menu=" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입 금" << std::endl;
	std::cout << "3. 출 금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 저 장 (공사중)" << std::endl;
	std::cout << "6. 불러오기 (공사중)" << std::endl;
	std::cout << "7. 종 료" << std::endl;
}

void AccountHandler::DepositMoney()
{
	int money;
	int no;
	std::cout << "[입 금]" << std::endl;
	std::cout << "계좌번호: ";
	std::cin >> no;

	for (int i = 0; i < total; ++i)
	{
		if (accounts[i]->GetNo() == no)
		{
			std::cout << "입금액: ";
			std::cin >> money;
			accounts[i]->Deposit(money);
			std::cout << "입금완료" << std::endl;
			return;
		}
	}
	std::cout << "입력된 계좌번호에 해당하는 정보가 없습니다." << std::endl;
}

EInput AccountHandler::SelectMenu()
{
	int input = 0;
	std::cout << "선택: ";
	std::cin >> input;
	std::cout << std::endl;

	return (EInput)input;
}

void AccountHandler::WithdrawMoney()
{
	int no = 0, money = 0;

	std::cout << "[출 금]" << std::endl;
	std::cout << "계좌번호: ";
	std::cin >> no;

	for (int i = 0; i < total; ++i)
	{
		if (accounts[i]->GetNo() == no)
		{
			std::cout << "출금액: ";
			std::cin >> money;
			accounts[i]->Withdraw(money);
			std::cout << "출금완료" << std::endl;
			return;
		}
	}
	std::cout << "입력된 계좌번호에 해당하는 정보가 없습니다." << std::endl;
}

void AccountHandler::ViewInfoAccounts() const
{
	if (total == 0)
	{
		std::cout << "저장된 계좌정보가 존재하지 않습니다." << std::endl;
		return;
	}

	for (int i = 0; i < total; ++i)
	{
		accounts[i]->ViewInfo();
	}
}

void AccountHandler::SaveInfo()
{
	int i = 0;
	FILE* fp;
	fopen_s(&fp, "save.dat", "wb");
	if (fp == NULL)
	{
		std::cout << "파일 읽기 실패" << std::endl;
		return;
	}

	fwrite(&total, sizeof(int), 1, fp);
	fwrite(accounts, sizeof(Account), total, fp);

	fclose(fp);
}

void AccountHandler::LoadInfo()
{
	int i = 0;
	FILE* fp;
	fopen_s(&fp, "save.dat", "rb");
	if (NULL == fp)
	{
		std::cout << "파일 읽기 실패" << std::endl;
		return;
	}

	fread(&total, sizeof(int), 1, fp);
	fread(accounts, sizeof(Account), total, fp);

	fclose(fp);
}