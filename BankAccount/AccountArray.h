#pragma once
#include "account.h"
#include <iostream>

typedef Account* Account_PTR;

class AccountArray
{
private:
	Account_PTR* arr;
	int arrlen;

	AccountArray(const AccountArray& arr) {}
	AccountArray& operator=(const AccountArray& arr) {}

public:
	AccountArray(int len = MAX_ACCOUNTS_SIZE);
	Account_PTR& operator[](int idx);
	Account_PTR operator[](int idx) const;
	int GetArrLen() const;
	~AccountArray();
};

