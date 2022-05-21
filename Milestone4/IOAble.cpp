 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "IOAble.h"
using namespace std;
namespace sdds
{
	IOAble::~IOAble()
	{

	}

	std::istream& operator>>(std::istream& is, IOAble& ioa)
	{
		ioa.read(is);
		return is;
	}
	std::ostream& operator<<(std::ostream& os, const IOAble& ioa)
	{
		ioa.write(os);
		return os;
	}
}