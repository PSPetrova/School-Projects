#include <iostream>
#include <math.h>
#include <Employee.h>
#include <Absolute.h>
#include <Gcd.h>
#include <BankAccount.h>

const double DEG_TO_RAD= 3.14159265/180;

using namespace std;

class Angle
{
public:
    void setValue(double) ;
    double getSin() const;
    double getCos() const;
    double getTan() const;
private:
    double degrees;
};
void Angle::setValue(double a)
{
    degrees = a;
}
double  Angle::getSin() const
{
    return sin(DEG_TO_RAD*degrees);
}
double Angle::getCos() const
{
    return cos(DEG_TO_RAD*degrees);
}
double Angle::getTan() const
{
    return tan(DEG_TO_RAD*degrees);
}
int main()
{
    int a=4;
    int b=16;
    Gcd t(a,b);
    cout<<t.value(a,b);
    Absolute num;
    cout<<num.ab(-43.5);

  cout<<"Absolute value "<<num.ab(-45.7)<<endl;
   cout<<"Absolute value "<<num.ab(-232)<<endl;
    return 0;
}
