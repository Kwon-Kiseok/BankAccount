#pragma once
#define MAX_STRING_LENGTH 1025

namespace my
{
	class istream
	{
	private:
		char* inputBuf;
	public:
		istream& operator>>(char*& str);
		istream& operator>>(const char str[MAX_STRING_LENGTH]);
		istream& operator>>(char& str);
		istream& operator>>(int& num);
		istream& operator>>(double& e);
	};

	static istream cin;
}

