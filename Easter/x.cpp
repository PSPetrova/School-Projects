#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;
const float LOAD_TOLERANCE_TOP=0.75f;
const float LOAD_TOLERANCE_BOT=0.25f;
/**
* Represents Egg
*/
class Egg
{
private:
    string id;
public:
    /**
    * Default Constructor
    */
    Egg() {}

    /**
    * Constructs Egg
    * Parameter id, the unique id of this egg
    */
    Egg(string id)
    {
        this->id=id;
    }

    /**
    * Return the id
    */
    string getId()
    {
        return id;
    }

    /**
    * Prints information about this egg
    */
    void info()
    {
        cout<<id<<endl;
    }

};

class Basket
{
private:
    Egg* eggs;
    int maxSize=2;
    int currentSize=0;
    string name;
    /**
    *Reduce the size of the array in half
    */
    void shrinkEggs()
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
    /**
    *Increase the size of array by 50%
    */
    void expandEggs()
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
    float getLoadFactor()
    {
        return currentSize/(float)maxSize;
    }
    void ensureCapacity()
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
    bool checkEggPresent(Egg egg)
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
public:
    /**
    * Constructs Basket
    * Parameter name, the name of this basket
    */
    Basket(string name)
    {
        this->name=name;
        eggs=new Egg[maxSize];
    }

    /**
    * Returns the name of the basket
    */
    string getName()
    {
        return name;
    }
    /**
    * Adds egg to this basket
    * Parameter egg, the egg to add.
    */
    void addEgg(Egg egg)
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
    /**
    * Removes egg from the basket by given ID
    * Parameter id, the id of the egg
    */
    void removeEgg(const char* id)
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

    /**
    * Generates detailed report for this basket
    * Returns the report as string
    */
    string report()
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
    void saveReportToFile(string report){
         ofstream file;
         file.open ("report.txt");
         file <<report;
         file.close();
    }
    /**
    * Generates a string representing this basket.
    * Returns string that can be used to generate the same basket.
    */
    string serialize()
    {
        string data=name+":";
        for(int i=0; i<currentSize; i++)
        {
            data+=eggs[i].getId();
            data+=",";
        }
        return data;
    }
    ~Basket()
    {
        delete[] eggs;
    }
};

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
        string currentName = data.substr(0,indexOfDot).c_str();
        Egg e(currentName.c_str());
        basket.addEgg(e);
        data=data.substr(indexOfDot+1,data.length());
        indexOfDot=data.find(",");
    }
    return basket;

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
void saveBasketToFile(Basket b)
{
    ofstream myfile;
    myfile.open (b.getName().c_str());
    myfile << b.serialize();
    myfile.close();
}

int main()
{
  Basket basket("Stavri");
    Egg egg1("egg1");
    Egg egg2("egg2");
    Egg egg3("egg3");


    basket.addEgg(egg1);
    basket.addEgg(egg2);
    basket.addEgg(egg3);
    saveBasketToFile(basket);
   string data=readFile("Stavri");
   cout<<data;
   Basket novaKoshnica=deserializeBasket(data);
    cout<<novaKoshnica.serialize();
cout<<endl<<"Report: ";
     string report=basket.report();
cout<<report;
    basket.saveReportToFile(report);
    return 0;
}
