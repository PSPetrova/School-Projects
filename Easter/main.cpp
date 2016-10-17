#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <Egg.h>
#include <Basket.h>
using namespace std;




/**
* Generates a basket from string data.
* Parameter data, the string data to deserialize from.
*/
Basket deserializeBasket(string data)
{
    int indexOfName = data.find(":");

    string name = data.substr(0,indexOfName);
    data=data.substr(indexOfName+1,data.length());
    Basket basket(name);
    int indexOfDot=data.find(",");
    while(indexOfDot>=0)
    {
        Egg e(data.substr(0,indexOfDot).c_str());
        basket.addEgg(e);
        data=data.substr(indexOfDot+1,data.length());
        indexOfDot=data.find(",");
    }
    Egg last(data.c_str());
    basket.addEgg(last);
    return basket;

}
/**
* Saves a basket into file.
*/
void saveBasketToFile(Basket basket)
{
    ofstream myfile;
    myfile.open (basket.getName().c_str());
    myfile << basket.serialize();
    myfile.close();
}
/**
* Reads the contents of a file into string
* Parameter path, the path to the file.
*/
string readFile(string path)
{
    string data="";
    string line;
    ifstream myfile (path.c_str());
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            data+=line;
        }
        myfile.close();
    }
    return data;
}
/**
* Creates file containing the detailed report for the given basket
*/
void saveBasketReportToFile(Basket basket)
{
    ofstream myfile;
    myfile.open (basket.getName().c_str());
    myfile << basket.serialize();
    myfile.close();
}

int main()
{

    Basket basket("Rabit");

    Egg egg1("egg1");
    Egg egg2("egg2");
    Egg egg3("egg3");
    Egg egg4("egg1");
    cout<<(egg2>egg1)<<endl;
    Basket b2("Other basket");

    Egg e("Random egg");
    b2.addEgg(e);

    Basket b3=basket+b2;// Name is RabitOther basket




    basket[6].info();//error



    return 0;
}
