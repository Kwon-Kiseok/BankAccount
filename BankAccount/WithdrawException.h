#pragma once
#include "Exception.h"

class WithdrawException : public Exception
{
private:
	int balance;
public:
	WithdrawException(int money);
	virtual void ShowMessage();
};

