 

#define _CRT_SECURE_NO_WARMINGS
#include "Time.h"
#include "utils.h"
#include <stdio.h>
#include <iomanip>
#include <string>
#include <ios>


using namespace std;

namespace sdds
{
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
        int hour = 0;
        int min = 0;

        hour = m_min / 60;
        min = m_min % 60;

        return ostr << setfill('0') << setw(2) << hour << ":"
            << setfill('0') << setw(2) << min;
    }

    std::istream& Time::read(std::istream& istr)
    {
        string temp;
        istr >> temp;
        int count = 0, ihour = 0, imin = 0;

        int pos = temp.find(':');
        if (pos > 0) {
            string hour = temp.substr(0, pos);
            string min = temp.substr(pos + 1);

            for (unsigned int i = 0; i < hour.length(); i++)
            {
                if (!isdigit(hour[i]))
                {
                    istr.setstate(ios::failbit);
                    count++;
                }
            }
            for (unsigned int i = 0; i < min.length(); i++)
            {
                if (!isdigit(min[i]))
                {
                    istr.setstate(ios::failbit);
                    count++;
                }
            }

            if (count == 0)
            {
                ihour = std::stoi(hour);
                imin = std::stoi(min);
                m_min = (ihour * 60) + imin;
            }
            else if ((ihour < 0) || (imin < 0))
            {
                istr.setstate(ios::failbit);
            }
        }
        else {
            istr.setstate(ios::failbit);
        }
        return istr;
    }

    Time& Time::operator-=(const Time& D)
    {
        while (D.m_min > m_min) {
            m_min += 1440;
        }
        m_min = m_min - D.m_min;
        return *this;
    }
    Time Time::operator-(const Time& D)const
    {
        unsigned int newMins = m_min;
        do {
            if (newMins < D.m_min)
            {
                newMins += 1440;
            }
        } while (newMins < D.m_min);

        newMins = newMins - D.m_min;

        return newMins;
    }
    Time& Time::operator+=(const Time& D)
    {
        m_min += D.m_min;
        return *this;
    }
    Time Time::operator+(const Time& D)const
    {
        Time newTime;

        return newTime.m_min = m_min + D.m_min;
    }
    Time& Time::operator=(unsigned int val)
    {
        m_min = val;
        return *this;
    }
    Time& Time::operator *= (unsigned int val)
    {
        m_min = m_min * val;
        return *this;
    }
    Time Time::operator *(unsigned int val)const
    {
        Time newTime;

        newTime.m_min = m_min * val;
        return newTime;

    }
    Time& Time::operator /= (unsigned int val) {
        m_min = m_min / val;
        return *this;
    }
    Time Time::operator /(unsigned int val)const {
        Time newTime;

        newTime.m_min = m_min / val;
        return newTime;
    }
    Time::operator int()const
    {
        return m_min;
    }
    Time::operator unsigned int()const
    {
        return m_min;
    }
    std::ostream& operator<<(std::ostream& ostr, const Time& D)
    {
        D.write(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, Time& D)
    {
        D.read(istr);
        return istr;
    }
}