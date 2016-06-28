#include "Gcd.h"
#include <math.h>

using namespace std;

Gcd::Gcd(int a, int b)
{
    x=a;
    y=b;
}
int Gcd::value(int a,int b)
{
    if(y == 0) return x;
    else
    {
        Gcd t(y, x%y);
        return t.value(x,y);
    }
}
