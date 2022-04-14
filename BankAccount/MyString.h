#pragma once
#include "ostream.h"
#include "istream.h"

#include <iostream>

namespace my
{
	class string
	{
	private:
		char* mStr;
		int len;
	public:
		string();
		string(const char* str);
		string(const string& copy);
		~string();


		int GetLen(const char* str);

		friend string operator+(const string& lhs, const string& rhs);
		string& operator=(const string& ref);
		const string& operator+=(const string& ref);
		bool operator==(const string& ref);

		friend ostream& operator<<(ostream& os, const string& str);
		friend istream& operator>>(istream& os, string& str);

		friend std::ostream& operator<<(std::ostream& os, const string& str);
		friend std::istream& operator>>(std::istream& os, string& str);
	};

	string operator+(const string& lhs, const string& rhs);
	ostream& operator<<(ostream& os, const string& str);
	istream& operator>>(istream& is, string& str);

	std::ostream& operator<<(std::ostream& os, const string& str);
	std::istream& operator>>(std::istream& os, string& str);
}

