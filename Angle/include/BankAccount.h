#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H


class BankAccount
{
private:
    char* name;
    char* num;
    double balance;
public:
    BankAccount(char*,char*,double);
    void print();
    void put(double);
    void draw(double);



};

#endif // EMPLOYEE_H
