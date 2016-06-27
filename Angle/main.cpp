#include <iostream>
#include <math.h>
#include <Employee.h>
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

char* str= "gg";

cout<<str['g']<<endl;
    return 0;

}
