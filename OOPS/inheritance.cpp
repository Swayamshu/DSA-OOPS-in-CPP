#include <iostream>

using namespace std;

class A
{
public:
  A()
  {
    cout << "A";
  }
  A(int y)
  {
    cout << "A" << y;
  }
};

class C
{
public:
  C()
  {
    cout << "C";
  }
  C(int x)
  {
    cout << "C" << x;
  }
};

class B : public C, A
{
public:
  B()
  {
    cout << "B";
  }
  B(int x, int y, int z) : A(x), C(y)
  { // order is decided by order of inheritance
    cout << "B" << z;
  }
};

int main()
{
  // B obj(4, 5);
  // B obj;
  B obj(2, 5, 9);
  return 0;
}