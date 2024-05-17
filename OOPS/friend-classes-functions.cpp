#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    A(int x)
    {
        a = x;
    }

    friend class B;
};

class B
{
private:
    int b;

public:
    B(int x)
    {
        b = x;
    }

    void showA(A &obj)
    {
        cout << obj.a << endl;
    }

    // prototype of friend function
    friend void showB(B &obj);
};

void showB(B &obj)
{
    cout << obj.b << endl;
}

int main(int argc, char const *argv[])
{
    A a(3);
    B b(6);
    b.showA(a);
    showB(b);
    return 0;
}
