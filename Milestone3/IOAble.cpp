 


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "IOAble.h"

using namespace std;

namespace sdds
{
	std::ostream& csvWrite(std::ostream& ostr)
	{
		return ostr;
	}
	std::istream& csvRead(std::istream& istr)
	{
		return istr;
	}
	std::ostream& write(std::ostream& ostr)
	{
		return ostr;
	}
	std::istream& read(std::istream& istr)
	{
		return istr;
	}
	IOAble::~IOAble()
	{

	}
	std::ostream& operator<<(std::ostream& ostr, const IOAble& I)
	{
		I.write(ostr);
		return ostr;

	}
	std::istream& operator>>(std::istream& istr, IOAble& I)
	{
		I.read(istr);
		return istr;
	}
}