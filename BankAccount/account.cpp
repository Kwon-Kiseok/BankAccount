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
	mMoney += money;
}

int Account::Withdraw(int money) throw(InputMoneyException, WithdrawException)
{
	if (money < 0)
	{
		InputMoneyException expn(money);
		throw expn;
	}
	if (money > mMoney)
	{
		WithdrawException expn(mMoney);
		throw expn;
	}
	mMoney -= money;
	return money;
}

void Account::ViewInfo() const
{
	std::cout << "°èÁÂ¹øÈ£: " << this->mNo << std::endl;
	std::cout << "ÀÌ ¸§: " << this->mName << std::endl;
	std::cout << "ÀÜ ¾×: " << this->mMoney << std::endl;
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