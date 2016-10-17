#include "Egg.h"
#include<iostream>

using namespace std;
Egg::Egg() {}


Egg::Egg(const char* id)
{
    this->id=id;
}

const char* Egg::getId()
{
    return id;
}

void Egg::info()
{
    cout<<id<<endl;
}

bool Egg::operator==( Egg e)
{
    return id == e.getId();
}
bool Egg::operator!=( Egg e)
{
    return id != e.getId();
}
bool Egg::operator< ( Egg e)
{
    return id > e.getId();
}
bool Egg::operator> ( Egg e)
{
    return id < e.getId();
}
bool Egg::operator<=( Egg e)
{
    return id <= e.getId();
}
bool Egg::operator>=( Egg e)
{
    return id >= e.getId();
}

Egg::~Egg()
{

}
