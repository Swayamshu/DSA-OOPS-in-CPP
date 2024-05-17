#include <iostream>

using namespace std;

class A
{
    int a;

    A() // this will throw error since private constructor is not allowed
    {
        cout << "default constructor" << endl;
    }

public:
    int b;

    A(int x)
    {
        this->b = x;
    }
};

class B
{
public:
    char ch;
    int a, b;

    B()
    {
        a = 0;
        b = 0;
        ch = 'a';
    }

    B(char c)
    {
        ch = c;
    }

    B(int x, int y)
    {
        a = x;
        b = y;
    }

    void get()
    {
        cout << a << " " << b << " " << ch << endl;
    }
};

class Test
{
    int a;

public:
    Test(int x)
    {
        a = x;
        cout << "constructor: " << a << endl;
    }

    ~Test()
    {
        cout << "destructor: " << a << endl;
    }
};

void fun(int x)
{
    Test obj(x);
    // scope of this function ends here
    // so destructors of Test objects are called once this function ends
    // i.e. function block(scope) ends
}

void staticFun(int x)
{
    static Test obj(x);
    // static member's scope ends at the end of program
}

class C
{
    int a;

public:
    C()
    {
        a = 10;
        cout << "default constructor: " << a << endl;
    }

    // Copy Constructors
    // argument is refernce to object of same class
    C(const C &obj)
    {
        a = obj.a;
        cout << "copy constructor: " << a << endl;
    }

    coid set(int x)
    {
        a = x;
    }
}

int
main()
{
    A obj(10);
    cout << obj.b << endl;

    B p, q('Z'), r(1, 2);
    p.get();
    q.get();
    r.get();

    Test a(1), b(2), c(3);
    fun(4);
    staticFun(5);

    C m;
    m.set(11); // default constructor called here
    C m1 = m;  // copy constructor called here
    C m2(m);   // copy constructor called here

    return 0; // main's scope ends here
} // static member's scope ends here where program ends