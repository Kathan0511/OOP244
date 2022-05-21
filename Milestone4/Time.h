 

#ifndef SDDS_TIME_H
#define SDDS_TIME_H
#include <iostream>
namespace sdds
{
    class Time {
        unsigned int Time_min;
    public:
        Time& reset();
        Time(unsigned int min = 0);
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
        operator int()const;
        Time& operator *= (int val);
        Time& operator-=(const Time& D);
    };
   
    std::istream& operator>>(std::istream&, Time&);
    std::ostream& operator<<(std::ostream&, const Time&);
}

#endif // !SDDS_TIME_H