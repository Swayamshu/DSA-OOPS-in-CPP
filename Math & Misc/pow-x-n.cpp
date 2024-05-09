#include <iostream>

using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

double myPow(double x, int n)
{
    if (n < 0)
        x = 1 / x;

    long num = labs(n);
    double pow = 1;

    while (num)
    {
        if (num & 1) // num is odd
            pow *= x;

        x *= x;
        num >>= 1; // right shift bits by 1 -> division by 2
    }

    return pow;
}

ll binPow(ll a, ll b)
{
    a %= mod;
    ll res = 1;

    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;

        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

ll nCr(int n, int r)
{
    if (n < r)
        return 0;

    ll num = 1, den = 1;

    if (r == 0)
        return 1;

    while (r)
    {
        num *= n--;
        den *= r--;

        ll temp = gcd(num, den);

        num /= temp;
        den /= temp;
    }
    return num;
}

int main()
{
    ll a = 5, b = 4;
    cout << myPow(a, b) << "\n";
    cout << binPow(a, b);
    return 0;
}