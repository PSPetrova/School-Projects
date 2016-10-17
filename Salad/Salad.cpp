#include <iostream>

using namespace std;

class Ingredient
{
public:
    Ingredient();
    Ingredient(const Ingredient&);
    Ingredient(bool isHomeMade,bool isCombinable);
    void operator=(const Ingredient&);
    virtual ~Ingredient();
    bool getIsHomeMade() const;
    bool getIsCombinable() const;
    virtual void print();
protected:
    bool isHomeMade;
    bool isCombinable;
};
Ingredient::Ingredient()
{
    isHomeMade=true;
    isCombinable=true;
}
Ingredient::Ingredient(const Ingredient& ingredient)
{
    this->isHomeMade=ingredient.getIsHomeMade();
    this->isCombinable=ingredient.getIsCombinable();
}
void Ingredient::operator=(const Ingredient& ingredient)
{
    this->isHomeMade=ingredient.getIsHomeMade();
    this->isCombinable=ingredient.getIsCombinable();
}
Ingredient::~Ingredient()
{
    cout<<"destructor Ingridient"<<endl;
}
bool Ingredient::getIsHomeMade() const
{
    return isHomeMade;
}
bool Ingredient::getIsCombinable() const
{
    return isCombinable;
}
void Ingredient::print()
{
    cout<<"is combinable: "<<isCombinable;
    cout<<"is homemade: "<<isHomeMade<<endl;
}
Ingredient::Ingredient(bool isHomeMade, bool isCombinable)
{
    this->isHomeMade=isHomeMade;
    this->isCombinable=isCombinable;
}
class Vegie:public Ingredient
{
public:
    Vegie();
    Vegie(const Vegie&);
    void operator=(const Vegie&);
    int getVitamin() const;
    void print();
    ~Vegie();
private:
    int vitamin;
};
Vegie::Vegie():Ingredient()
{
    this->vitamin=0;
}
Vegie::Vegie(const Vegie& vegie)
{
    this->isHomeMade=vegie.getIsHomeMade();
    this->isCombinable=vegie.getIsCombinable();
    this->vitamin=vegie.getVitamin();
}
int Vegie::getVitamin() const
{
    return vitamin;
}
void Vegie::print()
{
    cout<<"is combinable "<<isCombinable<<endl;
    cout<<"is homemade "<<isHomeMade<<endl;
    cout<<"vitamin "<<vitamin<<endl;
}
Vegie::~Vegie()
{
    cout<<"destructor Vegie "<<endl;
}
int main()
{
    // Polymorphism
    Ingredient* ing=new Vegie;
    ing->print();
    //Always delete data with new!
    delete ing;

    //polymorphic array
    Ingredient* ingrarr[2];
    ingrarr[0]=new Vegie;
    ingrarr[1]=new Ingredient;
    for(int i=0; i<2; i++)
    {
        ingrarr[i]->print();
    }

    return 0;
}
