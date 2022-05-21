 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {
    Mark::Mark()
    {
        marks = 0;
    }
    Mark::Mark(int mark)
    {
        marks = mark;
    }
    int Mark::getMarks()
    {
        return marks;
    }
    Mark::operator int() const
    {
        if (marks >= 0 && marks <= 100)
            return marks;
        return 0;
    }
    Mark::operator char() const
    {
        if (marks < 50)
            return 'F';
        else if (marks >= 50 && marks < 60)
            return 'D';
        else if (marks >= 60 && marks < 70)
            return 'C';
        else if (marks >= 70 && marks < 80)
            return 'B';
        else if (marks >= 80 && marks < 100)
            return 'A';
        else
            return 'X';
    }
    Mark::operator double() const
    {
        if (marks < 50)
            return 0.0;
        else if (marks >= 50 && marks < 60)
            return 1.0;
        else if (marks >= 60 && marks < 70)
            return 2.0;
        else if (marks >= 70 && marks < 80)
            return 3.0;
        else if (marks >= 80 && marks < 100)
            return 4.0;
        else
            return 0;
    }
    Mark& Mark::operator+=(int mark)
    {
        marks += mark;
        return *this;
    }
    Mark& Mark::operator=(int mark)
    {
        marks = mark;
        return *this;
    }

}