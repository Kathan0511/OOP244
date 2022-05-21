 


#include <iostream>
#include "Time.h"
#include "utils.h"

using namespace std;

namespace sdds
{
	Time& Time::setToNow()
	{
		m_min = getTime();
		return *this;
	}

	Time::Time(unsigned int minimum)
	{
		m_min = minimum;
	}

	std::ostream& Time::write(std::ostream& ostring) const
	{
		int minimum = m_min % 60;
		int hours = (m_min - minimum) / 60;

		cout.fill('0');
		cout.width(2);
		cout << hours << ":";

		cout.fill('0');
		cout.width(2);
		cout << minimum;

		return ostring;
	}

	std::istream& Time::read(std::istream& istr)
	{
		int hours = 0;
		int minimum = 0;
		char ch = 0;

		istr >> hours;
		if (hours < 0)
		{
			istr.setstate(ios::failbit);
		}

		istr >> ch;
		if (ch != ':')
		{
			istr.setstate(ios::failbit);
		}

		istr >> minimum;
		if (minimum < 0)
		{
			istr.setstate(ios::failbit);
		}

		m_min = (hours * 60) + minimum;

		return istr;
	}

	Time& Time::operator-=(const Time& D)
	{
		if (D.m_min > m_min)
		{
			m_min = D.m_min - m_min;
			int hours = m_min / 60;
			int n = (hours / 24) + 1;
			m_min = 1440 * n - m_min;
		}
		else
		{
			m_min = m_min - D.m_min;
		}

		return *this;
	}

	Time Time::operator-(const Time& D) const
	{
		unsigned difference;

		if (D.m_min > m_min)
		{
			difference = D.m_min - m_min;
			int hours = difference / 60;
			int n = (hours / 24) + 1;
			difference = 1440 * n - difference;
		}
		else
		{
			difference = m_min - D.m_min;
		}

		return Time(difference);
	}

	Time& Time::operator+=(const Time& D)
	{
		m_min += D.m_min;
		return *this;
	}

	Time Time::operator+(const Time& D) const
	{
		return Time(m_min + D.m_min);
	}

	Time& Time::operator=(unsigned int val)
	{
		m_min = val;
		return *this;
	}

	Time& Time::operator*=(unsigned int val)
	{
		m_min *= val;
		return *this;
	}

	Time& Time::operator/=(unsigned int val)
	{
		m_min /= val;
		return *this;
	}

	Time Time::operator*(unsigned int val) const
	{
		return Time(m_min * val);
	}

	Time Time::operator/(unsigned int val) const
	{
		return Time(m_min / val);
	}

	Time::operator unsigned int() const
	{
		return m_min;
	}

	Time::operator int() const
	{
		return (int)m_min;
	}

	std::ostream& operator<<(std::ostream& ostring, const Time& D)
	{
		return D.write(ostring);
	}

	std::istream& operator>>(std::istream& istr, Time& D)
	{
		return D.read(istr);
	}
}