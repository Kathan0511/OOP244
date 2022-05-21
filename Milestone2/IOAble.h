//==============================================
// Name:           Kathan Patel
// Student Number: 148609191
// Email:          kjpatel30@myseneca.ca
// Section:        NKK
//==============================================:     
// Milestone:      MS2
//==============================================


#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>

namespace sdds
{
	class IOAble
	{
	public:

		virtual std::ostream& write(std::ostream& ostring = std::cout)const = 0;
		virtual std::istream& read(std::istream& istring = std::cin) = 0;

		virtual std::ostream& csvWrite(std::ostream& ostring = std::cout)const = 0;
		virtual std::istream& csvRead(std::istream& istring = std::cin) = 0;

		virtual ~IOAble();

	};

	std::ostream& operator<<(std::ostream& os, const IOAble& rhtOperator);

	std::istream& operator>>(std::istream& is, IOAble& rhtOperator);
}

#endif // !SDDS_IOABLE_H



