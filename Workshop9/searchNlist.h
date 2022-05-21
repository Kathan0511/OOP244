 


#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Employee.h"
#include "Student.h"
#include "ReadWrite.h"

namespace sdds
{
    template<typename First, typename Second>
    bool search(Collection<First>& refers, First Element[], int size, Second key)
    {
        bool Testing = false;
        for (int i = 0; i < size; i++)
        {
            if (Element[i] == key)
            {
                Testing = true;
                refers.add(Element[i]);
            }
        }
        return Testing;
    }

    template<typename No_Three>
    void listArrayElements(const char* head, const No_Three Element[], int size)
    {
        std::cout << head << std::endl;
        for (int i = 0; i < size; i++)
        {
            std::cout << i + 1 << ": " << Element[i] << std::endl;
        }
    }
}
#endif