#include "Car.h"
#include <iostream>

using namespace std;

Car::Car()
{

    regNum="none";
    cout<<"default Constructor"<<endl;

}
Car::Car(const char* num)
{
    regNum=num;
    cout<<"regular Constructor"<<endl;
}
Car::Car(Car &car)
{
    regNum=car.getRegNum();
    cout<<"coppy constructor"<<endl;
}
Car::Car(int c)
{
    regNum="Copy int";
}
void Car::print()
{
    cout<<"reg num= "<<regNum<<endl;
}
const char* Car::getRegNum()
{
    return regNum;
}
void Car::operator=(const char* regNum)
{
    this->regNum=regNum;
}
void Car::operator=(int val)
{
    this->regNum="Thie was int";
}

void Car::operator=(Car v)
{
    this->regNum="Thie was car";
}
void Car::transport(){
cout<<"car transport"<<endl;
}
int Car::getAge(){
return 2;}
void Car::testAbstractMethod(){
cout<<"abstraktniq metod v CAR"<<endl;}
