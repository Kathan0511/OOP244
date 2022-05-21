 

#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include <cstring>
#include <string>
using namespace std;
namespace sdds {
    char* LblShape::label() const
    {
        return m_label;
    }
    LblShape::LblShape()
    {
        if (m_label != nullptr)
            m_label = nullptr;
    }
    LblShape::LblShape(const char* label)
    {
        int len = strlen(label);
        m_label = new char[len + 1];
        strcpy(m_label, label);
        m_label[len] = '\0';
    }
    LblShape::~LblShape()
    {
        delete[] m_label;
    }
    void LblShape::getSpecs(std::istream& istr)
    {
        string s;
        getline(istr, s, ',');
        int len = s.length();
        if (m_label != nullptr)
            delete[] m_label;
        m_label = new char[len + 1];
        strcpy(m_label, s.c_str());
        m_label[len] = '\0';
    }
}