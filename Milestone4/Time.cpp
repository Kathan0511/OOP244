 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds
{

	Time& Time::reset()
	{
		Time_min = getTime();
		return *this;
	}

	Time::Time(unsigned int min)
	{
		Time_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const
	{
		int hh = Time_min / 60;
		int mm = Time_min % 60;
		if (hh < 10)
		{
			ostr << setfill('0') << setw(2) << hh << ":";
		}
		else
		{
			ostr << hh << ":";
		}
		if (mm < 10)
		{
			ostr << setfill('0') << setw(2) << mm;
		}
		else
		{
			ostr << mm;
		}
		return ostr;
	}

	std::istream& Time::read(std::istream& istr)
	{
		int hh;
		int mm;
		char col;
		istr >> hh >> col >> mm;
		if (istr.fail() || col != ':')
		{
			istr.setstate(ios::failbit);
		}
		else
		{
			Time_min = 60 * hh + mm;
		}
		return istr;
	}

	Time::operator int() const
	{
		return Time_min;
	}

	Time& Time::operator*=(int val)
	{
		Time_min *= val;
		return *this;
	}

	Time& Time::operator-=(const Time& D)
	{
		if (Time_min < D.Time_min)
		{
			Time_min = Time_min + 24 * 60 - D.Time_min;
		}
		else
		{
			Time_min -= D.Time_min;
		}
		return *this;
	}

	// helper operator << and >> prototypes
	std::istream& operator>>(std::istream& is, Time& t)
	{
		t.read(is);
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const Time& t)
	{
		t.write(os);
		return os;
	}

}