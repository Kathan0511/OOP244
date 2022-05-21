 

#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace sdds
{
    struct Employee
    {
        char* m_name;
        int m_studentNumber;
        double m_gpa;
    };

    void sort();

    bool load(Employee&);

    bool load();
    void display(Employee&);
    void display();
    void deallocateMemory();

}
#endif // SDDS_EMPLOYEE_H_