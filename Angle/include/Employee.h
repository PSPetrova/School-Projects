#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee
{
    public:
        Employee(char*,char*,double,double);
        void print();

    protected:
    private:
        char* firstName;
        char* lastName;
        double salary;
        double hours;

};

#endif // EMPLOYEE_H
