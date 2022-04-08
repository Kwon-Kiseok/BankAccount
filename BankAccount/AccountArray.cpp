#include "AccountArray.h"

AccountArray::AccountArray(int len) : arrlen(len)
{
	arr = new Account_PTR[len];
}

Account_PTR& AccountArray::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		std::cout << "Array index out of bound exception" << std::endl;
		exit(1);
	}

	return arr[idx];
}

Account_PTR AccountArray::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		std::cout << "Array index out of bound exception" << std::endl;
		exit(1);
	}

	return arr[idx];
}

int AccountArray::GetArrLen() const
{
	return arrlen;
}

AccountArray::~AccountArray()
{
	delete[] arr;
}
