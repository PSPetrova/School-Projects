#ifndef CAR_H
#define CAR_H
#include <Vehicle.h>
#include <Transport.h>
#include <AbstractClas.h>

class Car : public Vehicle, public Transport, public AbstractClas
{
public:

    Car();
    Car(const char* regnum);
    Car( Car &c);
    Car( int c);
    void print();
    const char* getRegNum();
    void operator=(const char*);
    void operator=(int val);
    void operator=(Car c);
     void transport();
     int getAge();
     void testAbstractMethod();
private:
    const char* regNum;
};

#endif // CAR_H
