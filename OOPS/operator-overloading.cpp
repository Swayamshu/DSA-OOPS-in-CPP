#include <iostream>

using namespace std;

/**
 * The operator symbol for both prefix(++i) and postfix(i++) are the same.
 * Hence, we need two different function definitions to distinguish between them.
 * This is achieved by passing a dummy (int) parameter in the postfix version.
 */

class Point
{
private:
    int value;

public:
    Point() : value(0) {}
    Point(int val) : value(val) {}

    // Normal Operator Overloading
    Point operator+(Point const &obj)
    {
        Point res; // created result object
        res.value = value + obj.value;
        return res;
    }

    // Prefix Operator Overloading
    Point &operator++()
    {
        ++value;      // increment the value first
        return *this; // return the updated current object reference
    }

    /** Postfix Operator Overloading
     *
     *  we use int in params to differentiate between prefix and postfix
     *  it doesn't have any use though
     */
    Point operator++(int)
    {
        Point newObj = *this; // make a copy of the current object
        ++value;              // increment the value
        return newObj;        // return the object copy
    }

    void print()
    {
        cout << value << endl;
    }
};

int main(int argc, char const *argv[])
{
    Point a(3);
    Point b(6);
    cout << "a = ";
    a.print();
    cout << "b = ";
    b.print();

    cout << "prefix:\n";
    Point d = ++a;
    cout << "d = ";
    d.print();
    cout << "a = ";
    a.print();

    cout << "postfix:\n";
    Point c = b++;
    cout << "c = ";
    c.print();
    cout << "b = ";
    b.print();

    return 0;
}
