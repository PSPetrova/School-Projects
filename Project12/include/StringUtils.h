#ifndef STRINGUTILS_H
#define STRINGUTILS_H


const char* readFileToString(const char* path);
void appendStringToFile(const char* content,const char* path);
const char* convertIntToString(int num);
char convertDigitToChar(int num);
bool equal(const char* first,const char* second);
char** split(const char* arr,char delimer);
int getSize(const char* arr);
int countChars(const char* arr,char c);
char* substring(const char*,int begin,int end);
int indexOf(const char*, char);
#endif // STRINGUTILS_H
