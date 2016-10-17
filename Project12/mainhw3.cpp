#include <iostream>
#include <fstream>
#include <Egg.h>
#include <Basket.h>
#include <StringUtils.h>
using namespace std;




/**
* Generates a basket from string data.
* Parameter data, the string data to deserialize from.
*/
Basket deserializeBasket(const char* data)
{
    int indexOfName = indexOf(data,':');


    const char*  name = substring( data,0,indexOfName);
    Basket basket(name);
    int dataSize= getSize(data);
    int lastFoundIndex=0;
    for(int i=indexOfName+1; i<dataSize; i++)
    {
        if(data[i]==',')
        {
            Egg e(substring(data,lastFoundIndex,i));
            const char* eggData=substring(data,lastFoundIndex,i);
            cout<<eggData<<endl;
            lastFoundIndex=i+1;
            basket.addEgg(e);
        }
    }
    return basket;
}

int mfain()
{
    Basket basket1("koshnica");
    Egg egg1("egg1");
    Egg egg2("egg2");
    Egg egg3("egg3");
    Egg egg4("egg4");
    basket1.addEgg(egg1);
    basket1.addEgg(egg2);
    basket1.addEgg(egg3);
    Basket basket2=basket1; //Copy constructor
    basket1.removeEgg("egg3");

    cout<<(egg1==egg1)<<endl;       // Return 1
    cout<<(egg1!=egg2)<<endl;       // Return 1
    cout<<(egg1<egg2)<<endl;
    cout<<(egg1>egg2)<<endl;
    cout<<(egg1>=egg2)<<endl;
    cout<<(egg1<=egg2)<<endl;
    //basket2=basket1+basket1;

    Egg someEgg = basket1[1]; // get Egg by index
    cout<<someEgg.getId()<<endl;

    basket1.serialize(); // save basket to file
    //const char* basketData=readFileToString(basket1.getName());
    //Basket basket3=deserializeBasket(basketData); // TODO not working
    basket2.report();
    return 0;
}
