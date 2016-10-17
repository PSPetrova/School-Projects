#include <iostream>

using namespace std;
class Element
{
public:
    Element();
    Element(const Element& other);
    void operator=(const Element& other);
    const char* getText() const;
    const char* getValue() const;
    virtual void draw();
    virtual ~Element();

private:
    const char* text;
    char* value[];
};
Element::Element()
{
    this->text="empty";
}
Element::Element(const Element& other)
{
    this->text=other.getText();
}
void Element:: operator=(const Element& other)
{
    this->text=other.getText();
}
const char* Element::getText() const
{
    return text;
}
const char* Element::getValue() const
{
    //TODO
}
void Element::draw()
{
    cout<<"text "<<text<<endl;
}
Element::~Element()
{
    delete text;
    delete[] value;
}
class PictureEl:public Element
{
public:
    PictureEl();
    PictureEl(const PictureEl& other);
    void operator=(const PictureEl& other);
    const char* getPicture() const;
    void draw();
    ~PictureEl();
private:
    const char* picture;
};
PictureEl::PictureEl()
{
    this->picture="";
}
PictureEl::PictureEl(const PictureEl& other)
{
    this->picture=other.getPicture();
}
void PictureEl:: operator=(const PictureEl& other)
{
    this->picture=other.getPicture();
}

const char* PictureEl::getPicture() const
{
    return picture;
}
void PictureEl::draw()
{
    cout<<"picture "<<picture<<endl;
}
PictureEl::~PictureEl()
{
    delete picture;
}
class TickEl:public Element
{
public:
    TickEl();
    TickEl(const TickEl& other);
    void operator=(const TickEl& other);
    bool isTicked() const;
    void draw();
    ~TickEl();
private:
    bool tick;
};
TickEl::TickEl()
{
    this->tick=false;
}
TickEl::TickEl(const TickEl& other)
{
    this->tick=other.isTicked();
}
void TickEl:: operator=(const TickEl& other)
{
    this->tick=other.isTicked();
}
void TickEl::draw()
{
    cout<<"tick "<<tick<<endl;
}
bool TickEl::isTicked() const
{
    return tick;
}
TickEl::~TickEl()
{
    //delete tick;
}
class ColorEl:public Element
{
public:
    ColorEl();
    ColorEl(const ColorEl& other);
    void operator=(const ColorEl& other);
    const char* getColor() const;
    void draw();
    ~ColorEl();
private:
    const char* color;
};
ColorEl::ColorEl()
{
    this->color="none";
}
ColorEl::ColorEl(const ColorEl& other)
{
    this->color=other.getColor();
}
const char* ColorEl::getColor() const
{
    return color;
}
void ColorEl:: operator=(const ColorEl& other)
{
    this->color=other.getColor();
}
void ColorEl::draw()
{
    cout<<"color "<<color<<endl;
}
ColorEl::~ColorEl()
{
    delete color;
}
class Control
{
public:
    Control();
    Control(const Control& other);
    void operator=(const Control& other);
    void addElement(Element element);
    ~Control();
private:
    Element* elementarr;
};
Control::Control(){
    this->elementarr= new Element[10];
}
Control::Control(const Control& other){

}
void Control:: operator=(const Control& other)
{

}
void Control::addElement(Element element){
 //   for(int i=0;i<10;i++){
  //         if(elementarr[i] ==NULL){
    //    elementarr[i]=element;}
}
Control::~Control(){
    delete[] elementarr;
}
int main()
{
    Element el1;
    el1.draw();
    PictureEl pel;
    pel.draw();


    return 0;
}
