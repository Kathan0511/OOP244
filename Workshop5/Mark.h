 

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
    class Mark {
        int marks;
    public:
        Mark();
        Mark(int mark);
        int getMarks();
        operator int() const;
        operator char() const;
        operator double() const;
        Mark& operator+=(int mark);
        Mark& operator=(int mark);
    };

    inline int operator+=(int& mark, Mark obj) {
        if (obj.getMarks() >= 0 && obj.getMarks() <= 100)
            mark += obj.getMarks();
        return mark;
    }

}
#endif // SDDS_MARK_H_