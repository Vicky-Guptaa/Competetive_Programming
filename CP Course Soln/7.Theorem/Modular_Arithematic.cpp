#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int mod = 5;

int sum(int a, int b)
{
    return (a + b) % mod;
}

int diff(int a, int b)
{
    return ((a - b) % mod + mod) % mod;
}

int product(int a, int b)
{
    return (((ll)a % mod) * ((ll)b % mod)) % mod;
}

int power(int a, int b)
{
    int result = 1;
    while (b != 0)
    {
        if (b & 1)
            result = product(result, a);
        a = product(a, a);
        b /= 2;
    }
    return result;
}

int division(int a, int b)
{
    return (product(a, power(b, mod - 2)));
}

int main()
{
    cout << sum(3, 5) << "\n";
    cout << diff(3, 5) << "\n";
    cout << product(324, 234) << "\n";
    cout << division(56, 2) << "\n";
    return 0;
}