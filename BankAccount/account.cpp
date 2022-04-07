#include <iostream>
#include <cstdio>
#include <cassert>
#include "account.h"

void Account::Deposit(int money)
{
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
	std::cout << "°èÁÂ¹øÈ£: " << this->mNo << std::endl;
	std::cout << "ÀÌ ¸§: " << this->mName << std::endl;
	std::cout << "ÀÜ ¾×: " << this->mMoney << std::endl;
	std::cout << std::endl;
}
