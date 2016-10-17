#ifndef BASKET_H
#define BASKET_H
#include<Egg.h>


using namespace std;


class Basket
{
private:
    Egg* eggs;
    int maxSize;
    int currentSize;
    const char* name;


    void shrinkEggs();
    void expandEggs();
    float getLoadFactor();
    void ensureCapacity();
    bool checkEggPresent(Egg egg);
    bool compareEggArray(Basket other);
public:

    Basket();
    /**
    * Constructs Basket
    * Parameter name, the name of this basket
    */
    Basket( const char*  name);

    /**
    * Returns the name of the basket
    */
    const char* getName();

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
    * Prints detailed report for this basket
    */
    void report();

    /**
    * Saves a string representing this basket to file.
    */
    void serialize();

    /**
    * Destructor
    */
    ~Basket();

    /**
    Get the current size of the basket
    */
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
