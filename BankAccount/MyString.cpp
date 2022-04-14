#include "MyString.h"
#include <cstring>

my::string::string()
	:mStr(NULL), len(0)
{
}

my::string::string(const char* str)
{
	GetLen(str);
	mStr = new char[len];
	strcpy_s(mStr, len, str);
}

my::string::string(const string& copy)
{
	GetLen(copy.mStr);
	mStr = new char[len];
	strcpy_s(mStr, len, copy.mStr);
}

my::string::~string()
{
	delete[] mStr;
}

int my::string::GetLen(const char* str)
{
	return len = strlen(str) + 1;
}

my::string& my::string::operator=(const string& ref)
{
	if (mStr != nullptr)
	{
		delete[] mStr;
		mStr = nullptr;
	}
	*this = ref;
	return *this;
}

const my::string& my::string::operator+=(const string& ref)
{
	return (*this = *this + ref);
}

bool my::string::operator==(const string& ref)
{
	return (strcmp(this->mStr, ref.mStr)) == 0;
}

my::string my::operator+(const string& lhs, const string& rhs)
{
	int len = lhs.len + rhs.len - 1;
	string temp;
	temp.mStr = new char[len];
	strcpy_s(temp.mStr, len, lhs.mStr);
	strcat_s(temp.mStr, len, rhs.mStr);
	return temp;
}

my::ostream& my::operator<<(ostream& os, const string& str)
{
	os << str.mStr;
	return os;
}

my::istream& my::operator>>(istream& is, string& str)
{
	is >> str.mStr;
	return is;
}

std::ostream& my::operator<<(std::ostream& os, const string& str)
{
	os << str.mStr;
	return os;
}

std::istream& my::operator>>(std::istream& is, string& str)
{
	char* temp = new char[MAX_STRING_LENGTH];
	is >> temp;
	str.mStr = temp;
	return is;
}