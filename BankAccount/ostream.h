#pragma once

namespace my
{
	class ostream
	{
	public:
		ostream& operator<<(char* str);
		ostream& operator<<(char str);
		ostream& operator<<(int num);
		ostream& operator<<(double e);
		ostream& operator<<(ostream& (*fp)(ostream& ostm));
	};
	ostream& endl(ostream& ostm);
	static ostream cout;
}

