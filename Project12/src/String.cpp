#include "String.h"

String::String()
{
    copyValues("");
}

String::String(const String& other)
{
    copyValues(other.getChars(),other.getCurrentSize());
}

String::String(const char* str)
{
    copyValues(str);
}

void String::operator=(String rhs)
{
    copyValues(rhs.getChars(),rhs.getCurrentSize());
}

void String::operator=(const char* s)
{
    copyValues(s);
}

int String::getCurrentSize() const
{
    return currentSize;
}

int String::countChars(const char &c) const
{
    int count=0;
    for(int i=0; i<currentSize; i++)
    {
        if(str[i]==c)
        {
            count++;
        }
    }
    return count;
}

String& String::substring(const int &start,const int &end) const
{
    String* result=new String;
    for(int i=start; i<=end; i++)
    {
        *result=*result+str[i];
    }
    return *result;
}

char* String::getChars() const
{
    char* chars = new char[currentSize];
    for(int i=0; i<currentSize; i++)
    {
        chars[i]=str[i];
    }
    return chars;
}


String& String::operator+(const char &c)
{
    //cout<<"This "<<currentSize<<endl;
    str[currentSize]=c;
    //cout<<str<<endl;
    currentSize++;
    handleSize();
    return *(this);
}



void String::handleSize()
{
    float loadFactor = (float)currentSize/maxSize;
    if(loadFactor>0.75)
    {
        cout<<"Expand "<<endl;
        expand();
    }
    else if(loadFactor<0.25)
    {
        shrink();
    }
}
String* String::split(const char &delimer) const
{
    int count = countChars(delimer)+1;
    String* split = new String[count];
    int lastIndex=0;
    int lastFoundIndex=0;
    for(int i=0; i<currentSize; i++)
    {
        if(str[i]==delimer)
        {
            split[lastIndex]=substring(lastFoundIndex,i-1);
            lastFoundIndex=i+1;
            lastIndex++;
        }
    }
    split[lastIndex]=substring(lastFoundIndex,currentSize-1);
    return split;

}
void String::expand()
{
    maxSize*=2;
    char* newStr = new char[maxSize];
    for(int i=0; i<currentSize; i++)
    {
        newStr[i]=str[i];
    }
    delete[] str;
    str=newStr;
}

void String::shrink()
{
    maxSize/=2;

    char* newStr = new char[maxSize];
    for(int i=0; i<currentSize; i++)
    {
        newStr[i]=str[i];
    }
    delete[] str;
    str=newStr;
}

char& String::operator[](int idx) const
{
    return str[idx];
}


void String::copyValues(const char* other)
{
    int size = 0;
    while(other[size] != '\0')
    {
        size++;
    }

    copyValues(other,size);
}

void String::copyValues(const char* other,const int &size)
{
    currentSize=size;
    maxSize=size*2+1;
    str = new char[maxSize];
    for(int i=0; i<size; i++)
    {
        str[i]=other[i];
    }
}
bool String::operator==(const char* rhs)
{
    int rhsSize=0;
    while(rhs[rhsSize]!='\0')
    {
        rhsSize++;
    }
    if(currentSize != rhsSize)
    {
        return false;
    }
    for(int i=0; i<currentSize; i++)
    {
        if(str[i]!=rhs[i])
        {
            return false;
        }
    }

    return true;
}

bool String::operator==(const String& rhs)
{
    if(currentSize!=rhs.getCurrentSize())
    {
        return false;
    }

    for(int i=0; i<rhs.getCurrentSize(); i++)
    {
        if(str[i]!=rhs[i])
        {
            return false;
        }
    }
    return true;

}
void String::reverse()
{
    for(int i =0; i<currentSize/2; i++)
    {
        char temp=str[i];
        str[i]=str[currentSize-i-1];
        str[currentSize-i-1]=temp;
    }
}
String::~String()
{
    delete[] str;
}
