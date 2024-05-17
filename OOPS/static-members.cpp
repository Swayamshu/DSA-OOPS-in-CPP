#include <iostream>

using namespace std;

class A
{
public:
    static int a;

    void increment() { a++; }

    int get() { return a; }
};

int A::a = 10;

class B
{
public:
    static int b;

    static void increment() { b++; }

    static int get() { return b; }
};

int B::b = 10;

int main()
{
    A a, b, c;
    a.increment();
    b.increment();
    c.increment();
    cout << a.get() << b.get() << c.get() << endl;

    B p, q, r;
    p.increment();  // this increments to 11
    q.increment();  // this increments to 12
    B::increment(); // this increments to 13
    cout << c.get() << endl;

    return 0;
}