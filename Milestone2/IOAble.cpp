 


#include "IOAble.h"

namespace sdds
{
	IOAble::~IOAble()
	{
	}

	std::ostream& IOAble::write(std::ostream& ostring) const
	{
		return ostring;
	}

	std::istream& IOAble::read(std::istream& istring)
	{
		return istring;
	}

	std::ostream& operator<<(std::ostream& os, const IOAble& rhtOperator)
	{
		return rhtOperator.write(os);
	}

	std::istream& operator>>(std::istream& is, IOAble& rhtOperator)
	{
		return rhtOperator.read(is);
	}
}