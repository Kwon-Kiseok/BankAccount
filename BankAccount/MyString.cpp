#include "MyString.h"
#include <cstring>

my::string::string()
	:mStr(NULL)
{
}

my::string::string(const char* str)
{
	int len = strlen(str) + 1;
	mStr = new char[len];
	strcpy_s(mStr, len, str);
}

my::string::string(const string& copy)
{
	int len = strlen(copy.mStr) + 1;
	mStr = new char[len];
	strcpy_s(mStr, len, copy.mStr);
}

my::string::~string()
{
	delete[] mStr;
}

my::string& my::string::operator=(const string& ref)
{
	delete[] mStr;
	int len = strlen(ref.mStr) + 1;
	mStr = new char[len];
	strcpy_s(this->mStr, len, ref.mStr);
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
	int len = strlen(lhs.mStr) + strlen(rhs.mStr) + 1;
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