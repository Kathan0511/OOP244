 

#include "Rectangle.h"
#include <cstring>
#include <iomanip>
using namespace std;
namespace sdds {
    Rectangle::Rectangle()
    {
        m_height = 0;
        m_width = 0;
    }
    Rectangle::Rectangle(const char* label, int width, int height) :LblShape(label)
    {
        m_width = width;
        m_height = height;
        if (m_height < 3 || m_width < ((int)strlen(LblShape::label()) + 2))
        {
            m_width = 0;
            m_height = 0;
        }
    }
    void Rectangle::getSpecs(std::istream& istr)
    {
        LblShape::getSpecs(istr);
        istr >> m_width;
        istr.ignore();
        istr >> m_height;
        istr.ignore(500, '\n');
    }
    void Rectangle::draw(std::ostream& ostr) const
    {
        if (m_height > 0 && m_width > 0)
        {
            ostr << '+';
            for (int i = 0; i < m_width - 2; i++)
                ostr << '-';
            ostr << '+' << endl;

            ostr << '|';
            ostr << left << setw(m_width - 2) << LblShape::label();
            ostr << '|' << endl;

            for (int i = 0; i < m_height - 3; i++)
            {
                ostr << '|';
                for (int j = 0; j < m_width - 2; j++)
                    ostr << ' ';
                ostr << '|' << endl;
            }

            ostr << '+';
            for (int i = 0; i < m_width - 2; i++)
                ostr << '-';
            ostr << '+';
        }
    }
}