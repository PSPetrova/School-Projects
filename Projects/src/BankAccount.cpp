#include "BankAccount.h"
#include <iostream>

const int NAME_MAX=24;
const int NUM_MAX=16;

using namespace std;

BankAccount::BankAccount(char* nameClient, char* accountNum, double balanceIn)
{
    name=nameClient;
    num=accountNum;
    balance=balanceIn;
}
void BankAccount::print()
{
    cout<<"Name: "<<name<<endl;
    cout<<"";
}
//void BankAccount::draw()
//{
//}
//void BankAccount::put()
//{
//}
