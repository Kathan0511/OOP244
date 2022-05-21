 

#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
namespace sdds
{
	class IOAble {
	public:
		
		virtual std::ostream& csvWrite(std::ostream& ostr) const = 0;
		virtual std::istream& csvRead(std::istream& istr) = 0;
		virtual std::ostream& write(std::ostream& ostr) const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual ~IOAble() = 0;
	};
	
	std::istream& operator>>(std::istream&, IOAble&);
	std::ostream& operator<<(std::ostream&, const IOAble&);
}
#endif // !SDDS_IOABLE_H_