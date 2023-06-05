#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;

ll sum(ll a, ll b)
{
    return (a + b) % mod;
}

ll diff(ll a, ll b)
{
    return ((a - b) % mod + mod) % mod;
}

ll product(ll a, ll b)
{
    return (((ll)a % mod) * ((ll)b % mod)) % mod;
}

ll power(ll a, ll b)
{
    ll result = 1;
    while (b != 0)
    {
        if (b & 1)
            result = product(result, a);
        a = product(a, a);
        b /= 2;
    }
    return result;
}

ll division(ll a, ll b)
{
    return (product(a, power(b, mod - 2)));
}

ll factorial(ll n)
{
    ll fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
        fact %= mod;
    }
    return fact;
}

ll nCr(ll n, ll r)
{
    return product(factorial(n), power(product(factorial(n - r), factorial(r)), mod - 2));
}

int main()
{
    cout << sum(3, 5) << "\n";
    cout << diff(3, 5) << "\n";
    cout << product(324, 234) << "\n";
    cout << division(56, 2) << "\n";
    cout << nCr(5, 2) << "\n";
    return 0;
}