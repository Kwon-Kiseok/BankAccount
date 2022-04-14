#pragma once
#include "AccountHandler.h"

class BankSystem
{
private:
	AccountHandler handler;
	EInput input;
public:
	BankSystem() : input(static_cast<EInput>(0)) {}
	~BankSystem() {}

	void Run();
	void SelectMenu();
	void PrintMenu();
	EInput InputSelect();
};

