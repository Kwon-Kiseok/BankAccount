#include <iostream>
#include <cstdio>
#include <cassert>
#include "account.h"

Account::Account() : mNo(0), mMoney(0), mName(nullptr)
{
}

Account::Account(int no, int money, const char* name) : mNo(no), mMoney(money)
{
	mName = new char[strlen(name) + 1];
	strcpy_s(mName, (strlen(name) + 1), name);
}

Account::Account(const Account& copy) : mNo(copy.mNo), mMoney(copy.mMoney)
{
	mName = new char[strlen(copy.mName) + 1];
	strcpy_s(mName, (strlen(copy.mName) + 1), copy.mName);
}

Account::~Account()
{
	delete[] mName;
}

void Account::Deposit(int money)
{
	// 예외처리 추가
	mMoney += money;
}

int Account::Withdraw(int money)
{
	if (mMoney < money)
	{
		return 0;
	}
	mMoney -= money;
	return money;
}

void Account::ViewInfo() const
{
	std::cout << "계좌번호: " << this->mNo << std::endl;
	std::cout << "이 름: " << this->mName << std::endl;
	std::cout << "잔 액: " << this->mMoney << std::endl;
	std::cout << std::endl;
}

int Account::GetNo() const
{
	return mNo;
}

int Account::GetMoney() const
{
	return mMoney;
}

char* Account::GetName() const
{
	return mName;
}