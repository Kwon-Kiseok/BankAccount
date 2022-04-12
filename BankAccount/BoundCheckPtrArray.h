#pragma once
#include "account.h"
#include <iostream>


template<typename T>
class BoundCheckPtrArray
{
typedef T* array_PTR;
private:
	array_PTR* arr;
	int arrlen;

	BoundCheckPtrArray(const BoundCheckPtrArray& arr) {}
	BoundCheckPtrArray& operator=(const BoundCheckPtrArray& arr) {}

public:
	BoundCheckPtrArray(int len = MAX_ACCOUNTS_SIZE) : arrlen(len)
	{
		arr = new array_PTR[len];
	}
	array_PTR& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			std::cout << "Array index out of bound exception" << std::endl;
			exit(1);
		}

		return arr[idx];
	}
	array_PTR operator[](int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			std::cout << "Array index out of bound exception" << std::endl;
			exit(1);
		}

		return arr[idx];
	}
	int GetArrLen() const
	{
		return arrlen;
	}
	~BoundCheckPtrArray()
	{
		delete[] arr;
	}
};

