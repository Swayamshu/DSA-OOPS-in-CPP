#include <iostream>

using namespace std;

class Data
{
public:
    int val;

    int f(float x)
    {
        return 1;
    }
};

int main(int argc, char const *argv[])
{
    Data d;
    Data *dp;
    dp = &d;

    int (Data::*fp1)(float) = &Data::f; // this is equivalent to -> *fp1 = f

    return 0;
}
