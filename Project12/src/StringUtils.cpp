#include "StringUtils.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

/**
Take path to file and returns string containing the file contents
*/
const char* readFileToString(const char* path)
{
    char ch;
    int fileSize=0;
    ifstream fin(path, ios::in);
    while (fin >> noskipws >> ch)
    {
        fileSize++;
    }
    fin.close();

    char* result=new char[fileSize];
    ifstream  fin2(path, ios::in);
    int i=0;
    while (fin2 >> noskipws >> ch)
    {
        result[i]=ch;
        i++;
    }
    fin2.close();
    return result;
}
/**
Appends content to file with $path
*/
void appendStringToFile(const char* content,const char* path)
{
    ofstream outfile;
    cout<<content<<endl;
    outfile.open(path, ios_base::app);
    outfile << content<< endl;
    outfile.close();
}
/**
Converts integer to string
*/
const char* convertIntToString(int num)
{
    int digitCount =0;
    int numTmp=num;

    do
    {
        numTmp=numTmp/10;
        digitCount++;
    }
    while(numTmp!=0);


    char* result=new char[digitCount];
    int i=digitCount-1;
    do
    {
        result[i]=convertDigitToChar(num%10);
        num=num/10;
        i--;
    }
    while(num!=0);
    result[digitCount]='\0';
    return result;
}
/**
Convert digit to char
*/
char convertDigitToChar(int num)
{
    switch(num)
    {
    case 0:
        return '0';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    default:
        return '0';
    }
}
/**
Compare two string, true if equal
*/
bool equal(const char* first,const char* second)
{
    int size1=getSize(first);
    int size2=getSize(second);
    if(size1!=size2)
    {
        return false;
    }

    for(int i=0; i<size1; i++)
    {
        if(first[i]!=second[i])
        {
            return false;
        }
    }
    return true;
}

/**
Splits the string by delimer
*/
char** split(const char* arr,char delimer)
{
    int count = countChars(arr,delimer)+1;
    char** split = new char*[count];
    int lastIndex=0;
    int lastFoundIndex=0;

    int arrSize= getSize(arr);
    for(int i=0; i<arrSize; i++)
    {
        if(arr[i]==delimer)
        {
            split[lastIndex]=substring(arr,lastFoundIndex,i-1);
            lastFoundIndex=i+1;
            lastIndex++;
        }
    }
    split[lastIndex]=substring(arr,lastFoundIndex,arrSize-1);
    return split;
}
/**
Return the size of string
*/
int getSize(const char* arr)
{
    int size=0;
    while(arr[size]!='\0')
    {
        size++;
    }
    return size;
}
/**
Count how many c's are in arr
*/
int countChars(const char* arr,char c)
{
    int size=getSize(arr);
    int count=0;
    for(int i=0; i<size; i++)
    {
        if(arr[i]==c)
        {
            count++;
        }
    }
    return count;
}
/**
Returns substring from begin(inclusive) to end(exclusive)
*/
char* substring(const char* str,int begin,int end)
{
    int subSize = end-begin;
    char* result = new char[subSize];
    int subIter=0;
    for(int i=begin; i<=end; i++)
    {
        result[subIter]=str[i];
        subIter++;
    }

    result[subSize+1]='\0';
    return result;
}
/**
Return index of c in string, first occurance, else -1
*/
int indexOf(const char* str,char c)
{
    int size=getSize(str);
    int index=-1;
    for(int i=0; i<size; i++)
    {
        if(str[i]==c)
        {
            index=i;
            break;
        }

    }
    return index;
}


