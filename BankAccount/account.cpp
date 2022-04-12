#include <iostream>
#include <cstdio>
#include <cassert>
#include "account.h"

Account::Account() : mNo(0), mMoney(0), mName(nullptr)
{
}

Account::Account(int no, int money, const my::string name) : mNo(no), mMoney(money), mName(my::string(name))
{
}

Account::Account(const Account& copy) : mNo(copy.mNo), mMoney(copy.mMoney), mName(my::string(copy.mName))
{
}

Account::~Account()
{
}

Account& Account::operator=(const Account& ref)
{
	mName.~string();
	mName = my::string(ref.mName);
	mNo = ref.mNo;
	mMoney = ref.mMoney;
	return *this;
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

my::string Account::GetName() const
{
	return mName;
}