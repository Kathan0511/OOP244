 

#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
#include <iostream>
namespace sdds {
    class Line : public LblShape {
        int m_length;
    protected:
        char* label();
    public:
        Line();
        Line(const char*, int);
        ~Line() {};
        void getSpecs(std::istream&);
        void draw(std::ostream&) const;
    };
}
#endif