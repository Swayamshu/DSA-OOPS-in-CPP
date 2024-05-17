#include <iostream>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "animal constructor" << endl;
    }

    int age;
    void walk()
    {
        cout << "animal walks" << endl;
    };
};

class Tiger : virtual public Animal
{
public:
    Tiger()
    {
        cout << "tiger constructor" << endl;
    }
    void walk()
    {
        cout << "tiger walks" << endl;
    }
};

class Lion : virtual public Animal
{
public:
    Lion()
    {
        cout << "lion constructor" << endl;
    }
    void walk()
    {
        cout << "lion walks" << endl;
    }
};

class Liger : public Lion, public Tiger
{
public:
    Liger()
    {
        cout << "liger constructor" << endl;
    }
    // void walk()
    // {
    //     cout << "liger walks" << endl;
    // }
};

int main()
{
    Liger obj;
    /**
     * Diamond Problem
     * two instances of Animal are are created when Liger object is created.
     * this cause ambiguity, which instance to use.
     *
     * Solution: Virtual Inheritance
     */
    // obj.walk();

    // use scope resolution operator to resolve which implementation to use from parent classes
    obj.Lion::walk();

    return 0;
}