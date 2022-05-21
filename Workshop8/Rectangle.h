 

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"
#include <iostream>
namespace sdds {
    class Rectangle : public LblShape {
        int m_width, m_height;
    public:
        Rectangle();
        Rectangle(const char*, int, int);
        ~Rectangle() {};
        void getSpecs(std::istream&);
        void draw(std::ostream&) const;
    };
}
#endif