#pragma once
#include "AccountHandler.h"

class BankSystem
{
private:
	AccountHandler handler;
public:
	BankSystem() {}
	~BankSystem() {}

	void Run();
	void SelectMenu(AccountHandler* handler, EInput input);
};

