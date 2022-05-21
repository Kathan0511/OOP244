 

#include <iostream>
#include "cstring.h"  
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;

    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                //if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                if (employees[j].m_studentNumber > employees[j + 1].m_studentNumber) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }


    bool load(Employee& emp) {
        bool ok = false;
        char name[128] = { '\0' };
        int num, length;
        double sal;



        ok = read(num);
        if (!ok)
            return ok;
        ok = read(sal);
        if (!ok)
            return ok;
        ok = read(name);
        if (!ok)
            return ok;
        length = strLen(name) + 1;
        emp.m_name = new char[length];
        strCpy(emp.m_name, name);
        emp.m_studentNumber = num;
        emp.m_gpa = sal;
        return ok;



    }

    bool load() {
        bool ok = false;
        int i = 0;

        if (openFile(DATAFILE)) {

            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            for (i = 0; i < noOfEmployees; i++)
            {
                ok = load(employees[i]);
                if (ok == false)
                {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted.";
                    return ok;
                }
            }

        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }


    void display(Employee& emp)
    {

        cout << emp.m_studentNumber << ": " << emp.m_name << ", " << emp.m_gpa << endl;
    }
    void display()
    {
        int i;
        cout << "Employee Salary report, sorted by employee number\n";
        cout << "no- Empno, Name, Salary\n";
        cout << "------------------------------------------------\n";
        sort();
        for (i = 0; i < noOfEmployees; i++)
        {
            cout << i + 1 << "- " << employees[i].m_studentNumber << ": " << employees[i].m_name << ", " << employees[i].m_gpa << endl;
        }
    }

    void deallocateMemory()
    {
        int i;
        for (i = 0; i < noOfEmployees; i++)
            delete[] employees[i].m_name;
        delete[] employees;
    }




}