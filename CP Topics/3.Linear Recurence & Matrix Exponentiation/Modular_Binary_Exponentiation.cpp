#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;

int power_recur(int x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    long long res = power_recur(x, n / 2) % mod;
    if (n & 1)
        return (res * res * x) % mod;
    else
        return (res * res) % mod;
}

int power_iterative(long long x, long long n)
{
    long long res = 1;
    while (n)
    {
        if (n & 1)
        {
            res *= x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        n /= 2;
    }
    return res;
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << power_recur(x, n) << "\n";
    cout << power_iterative(x, n) << "\n";
    return 0;
}