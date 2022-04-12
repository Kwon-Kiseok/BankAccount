#include "istream.h"
#include "MyString.h"
#include <cstring>
#include <cstdio>

my::istream& my::istream::operator>>(char*& str)
{
    char* temp = new char[MAX_STRING_LENGTH];
    scanf_s("%s", temp, (unsigned int)sizeof(temp));
    str = temp;
    return *this;
}

my::istream& my::istream::operator>>(const char str[MAX_STRING_LENGTH])
{
    scanf_s("%s", str, (unsigned int)sizeof(str));
    return *this;
}

my::istream& my::istream::operator>>(char& str)
{
    scanf_s("%c", &str, 1);
    return *this;
}

my::istream& my::istream::operator>>(int& num)
{
    scanf_s("%d", &num);
    return *this;
}

my::istream& my::istream::operator>>(double& e)
{
    scanf_s("%lf", &e);
    return *this;
}
