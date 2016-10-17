#ifndef EGG_H
#define EGG_H


class Egg
{
private:
    const char* id;
public:
    /**
    * Default Constructor
    */
    Egg();

    /**
    * Constructs Egg
    * Parameter id, the unique id of this egg
    */
    Egg(const char* id);

    /**
    * Return the id
    */
    const char* getId();

    /**
    * Prints information about this egg
    */
    void info();

    bool operator==(const Egg e);
    bool operator!=(const Egg e);
    bool operator< (const Egg e);
    bool operator> (const Egg e);
    bool operator<=(const Egg e);
    bool operator>=(const Egg e);



};

#endif // EGG_H
