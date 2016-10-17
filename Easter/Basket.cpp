#include "Basket.h"
#include<iostream>
#include <algorithm>

using namespace std;

const float LOAD_TOLERANCE_TOP=0.75f;
const float LOAD_TOLERANCE_BOT=0.25f;

void Basket::shrinkEggs()
{
    Egg* newEggs = new Egg[maxSize/2];
    maxSize=maxSize/2;
    for(int i=0; i<currentSize; i++)
    {
        newEggs[i]=eggs[i];
    }
    delete[] eggs;
    eggs=newEggs;
}
void Basket::expandEggs()
{
    Egg* newEggs = new Egg[maxSize*2];
    maxSize=maxSize*2;
    for(int i=0; i<currentSize; i++)
    {
        newEggs[i]=eggs[i];
    }
    delete[] eggs;
    eggs=newEggs;
}
float Basket::getLoadFactor()
{
    return currentSize/(float)maxSize;
}
void Basket::ensureCapacity()
{
    if(getLoadFactor()>LOAD_TOLERANCE_TOP)
    {
        expandEggs();
    }
    else if(getLoadFactor()<LOAD_TOLERANCE_BOT)
    {
        shrinkEggs();
    }
}
bool Basket::checkEggPresent(Egg egg)
{
    for(int i = 0 ; i<currentSize; i++)
    {
        if(eggs[i].getId()==egg.getId())
        {
            return true;
        }
    }
    return false;
}

Basket::Basket(string name)
{
    this->currentSize=0;
    this->maxSize=5;
    this->name=name;
    eggs=new Egg[maxSize];
}


string Basket::getName()
{
    return name;
}

void Basket::addEgg(Egg egg)
{
    if(checkEggPresent(egg))
    {
        cout<<"egg: "<<egg.getId()<<" already exists"<<endl;
    }
    else
    {
        ensureCapacity();
        eggs[currentSize]=egg;
        currentSize++;
    }
}

void Basket::removeEgg(const char* id)
{
    int index=-1;
    for(int i=0; i<currentSize; i++)
    {
        if(eggs[i].getId()==id)
        {
            index=i;
            break;
        }
    }
    if(index>=0)
    {
        for(int i=index; i<=currentSize; i++)
        {
            eggs[i]=eggs[i+1];
        }
    }
}


string Basket::report()
{
    string reportTxt="Name: ";
    reportTxt+=name;
    reportTxt+="  EGS: ";
    for(int i=0; i<currentSize; i++)
    {
        reportTxt+=eggs[i].getId();
        reportTxt+=",";
    }
    return reportTxt;
}

string Basket::serialize()
{
    string data=name+":";
    for(int i=0; i<currentSize; i++)
    {
        data+=eggs[i].getId();
        data+=",";
    }
    return data;
}
int Basket::size()
{
    return currentSize;
}

Egg& Basket::operator[](int index)
{
    if(index<0 || index >currentSize)
    {
        cout<<"Index out of bounds! "<<index<<endl;
    }
    else
    {
        return eggs[index];
    }
}

bool Basket::operator<(Basket other)
{
    int loopMax = min(currentSize,other.size());
    Egg maxEgg=eggs[0];
    for(int i=0; i<loopMax; i++)
    {
        if(eggs[i]< other[i] && eggs[i]>maxEgg)
        {
            return true;//This basket is smaller
        }
        else if(eggs[i]>maxEgg)
        {
            maxEgg=eggs[i];
        }
    }
    return false;
}

bool Basket::operator>(Basket other)
{
    int loopMax = min(currentSize,other.size());
    Egg minEgg=eggs[0];
    for(int i=0; i<loopMax; i++)
    {
        if(eggs[i]> other[i] && eggs[i]<minEgg)
        {
            return true;//This basket is bigger
        }
        else if(eggs[i]<minEgg)
        {
            minEgg=eggs[i];
        }
    }
    return false;
}
bool Basket::operator==(Basket other)
{
    if(currentSize!= other.size())
    {
        return false;
    }

    for(int i=0; i<currentSize; i++)
    {
        if(eggs[i]!=other[i])
        {
            return false;
        }
    }
    return true;
}

bool Basket::operator!=(Basket other)
{
    return !(*this == other);
}
bool Basket::operator<=(Basket other)
{
    return *this == other || *this < other;
}

bool Basket::operator>=(Basket other)
{
    return *this == other || *this > other;
}

Basket& Basket::operator+=(Basket other)
{
    for(int i=0; i<other.size(); i++)
    {
        this->addEgg(other[i]);
    }
    return *this;
}

Basket Basket::operator+(Basket other)
{
    Basket newBasket(name+other.getName());
    for(int i=0; i<other.size(); i++)
    {
        newBasket.addEgg(other[i]);
    }
    for(int i=0; i<currentSize; i++)
    {
        newBasket.addEgg(eggs[i]);
    }
    return newBasket;
}


Basket::~Basket()
{
    delete[] eggs;
}

