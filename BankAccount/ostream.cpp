#include "ostream.h"
#include <cstdio>

my::ostream& my::ostream::operator<<(char* str)
{
	printf("%s", str);
	return *this;
}

my::ostream& my::ostream::operator<<(char str)
{
	printf("%c", str);
	return *this;
}

my::ostream& my::ostream::operator<<(int num)
{
	printf("%d", num);
	return *this;
}

my::ostream& my::ostream::operator<<(double e)
{
	printf("%g", e);
	return *this;
}

my::ostream& my::ostream::operator<<(ostream& (*fp)(ostream& ostm))
{
	return fp(*this);
}

my::ostream& my::endl(ostream& ostm)
{
	ostm << '\n';
	fflush(stdout);
	return ostm;
}