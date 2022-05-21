 

#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Time& Time::setToNow()
	{
		m_min = getTime();
		return *this;
	}
	Time::Time(unsigned int min)
	{
		m_min = min;
	}
	std::ostream& Time::write(std::ostream& ostr) const
	{
		ostr.fill('0');
		ostr.width(2);
		ostr << retHrs() << ":";

		ostr.fill('0');
		ostr.width(2);
		ostr << retMin();
		return ostr;
	}
	std::istream& Time::read(std::istream& istr)
	{
		int hrs =0;
		int min =0;
		char ch ='\0';

		istr >> hrs;
		if (hrs < 0)
		{
			istr.setstate(ios::failbit);
		}
		else m_min = hrs * 60;

		istr.get(ch);
		if (ch != ':')
		{
			istr.setstate(ios::failbit);
		}

		istr >> min;
		if (min < 0)
		{
			istr.setstate(ios::failbit);
		}
		else m_min += min;

		return istr;
	}
	Time& Time::operator-=(const Time& D)
	{
		bool valid = true;

		if (m_min < D.m_min)
		{
			int i = 1;
			while (valid)
			{
				if ((m_min + (60 * 24 * i) < D.m_min))	i++;
				else valid = false;
			}

			m_min += (60 * 24 * i);
			m_min -= D.m_min;
		}
		else
		{
			m_min -= D.m_min;
		}
		return *this;
	}
	Time Time::operator-(const Time& D) const
	{
		bool valid = true;
		Time temp;
		if (m_min < D.m_min)
		{
			int i = 1;
			while (valid)
			{
				if ((m_min + (60 * 24 * i) < D.m_min))	i++;
				else valid = false;
			}

			temp.m_min = (m_min + (60 * 24 * i)) - D.m_min;

		}
		else
		{
			temp.m_min = m_min - D.m_min;
		}
		return temp;
	}
	Time& Time::operator+=(const Time& D)
	{
		m_min += D.m_min;
		return *this;
	}
	Time Time::operator+(const Time& D) const
	{
		Time temp(m_min + D.m_min);
		return temp;
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
		Time temp(this->m_min * val);
		return temp;
	}
	Time Time::operator/(unsigned int val) const
	{
		Time temp(this->m_min / val);
		return temp;
	}
	Time::operator unsigned int() const
	{
		return m_min;
	}
	Time::operator int() const
	{
		return (int)m_min;
	}
	unsigned Time::retHrs() const
	{
		return (m_min / 60);
	}
	unsigned Time::retMin() const
	{
		return (m_min - (60 * retHrs()));
	}
	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		return D.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, Time& D)
	{
		return D.read(istr);
	}
}