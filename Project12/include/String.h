#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;

class String
{
public:
    String();
    String(const String& other);
    String(const char* str);

    void operator=(const String rhs);
    void operator=(const char* rhs);
    String& operator+(const String &rhs);
    String& operator+(const char &rhs);
    String& operator+(const char* rhs);
    bool operator==(const char* rhs);
    bool operator==(const String &srhs);
    char& operator[](int idx) const;
    void reverse();
    int getCurrentSize() const;
    String* split(const char &delimer) const;
    String& substring(const int &start,const int &end) const;
    int countChars(const char &c) const;
    char* getChars() const;

    virtual ~String();




private:
    void handleSize();
    void expand();
    void shrink();
    void copyValues(const char* other) ;
    void copyValues(const char* other,const int &size);

    int currentSize;
    int maxSize;
    char* str;
};




#endif // STRING_H
