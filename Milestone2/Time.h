 


#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <iostream>

namespace sdds
{
	class Time
	{
		unsigned int m_min;
	public:
		Time& setToNow();
		Time(unsigned int minimum = 0);
		std::ostream& write(std::ostream& ostring) const;
		std::istream& read(std::istream& istring);

		Time& operator-=(const Time& D);
		Time operator-(const Time& D)const;
		Time& operator+=(const Time& D);
		Time operator+(const Time& D)const;

		Time& operator=(unsigned int val);
		Time& operator *= (unsigned int val);
		Time& operator /= (unsigned int val);
		Time operator *(unsigned int val)const;
		Time operator /(unsigned int val)const;

		operator unsigned int()const;
		operator int()const;
	};
	std::ostream& operator<<(std::ostream& ostring, const Time& D);
	std::istream& operator>>(std::istream& istring, Time& D);
}

#endif // !SDDS_TIME_H