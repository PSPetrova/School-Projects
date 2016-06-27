#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(char* first,char* last,double sal,double h)
{
    firstName=first;
    lastName=last;
    salary=sal;
    hours=h;
}
void Employee::print(){
 cout<<"First Name: "<<firstName<<endl;
 cout<<"Last Name: "<<lastName<<endl;
 cout<<"Salary: "<<salary<<endl;
 cout<<"Hours: "<<hours<<endl;
}

