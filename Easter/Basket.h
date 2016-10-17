#ifndef BASKET_H
#define BASKET_H
#include<Egg.h>
#include <string>

using namespace std;


class Basket
{
private:
    Egg* eggs;
    int maxSize;
    int currentSize;
    string name;


    void shrinkEggs();
    void expandEggs();
    float getLoadFactor();
    void ensureCapacity();
    bool checkEggPresent(Egg egg);
    bool compareEggArray(Basket other);
public:

    /**
    * Constructs Basket
    * Parameter name, the name of this basket
    */
    Basket(string name);

    /**
    * Returns the name of the basket
    */
    string getName();

    /**
    * Adds egg to this basket
    * Parameter egg, the egg to add.
    */
    void addEgg(Egg egg);

    /**
    * Removes egg from the basket by given ID
    * Parameter id, the id of the egg
    */
    void removeEgg(const char* id);

    /**
    * Generates detailed report for this basket
    * Returns the report as string
    */
    string report();

    /**
    * Generates a string representing this basket.
    * Returns string that can be used to generate the same basket.
    */
    string serialize();

    /**
    * Destructor
    */
    ~Basket();

    int size();

    //Operator Overloads

    Egg& operator[](int index);


    bool operator==(const Basket b);
    bool operator!=(const Basket b);
    bool operator< (const Basket b);
    bool operator> (const Basket b1);
    bool operator<=(const Basket b1);
    bool operator>=(const Basket b1);


    Basket& operator+=(const Basket b);
    Basket operator+(const Basket b);


};

#endif // BASKET_H
