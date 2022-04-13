#pragma once
#include "Exception.h"

class InputMoneyException : public Exception
{
private:
	int mMoney;
public:
	InputMoneyException(int money);
	virtual void ShowMessage();
};

