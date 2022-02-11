#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int power_recur(int x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    long long res = power_recur(x, n / 2);
    if (n & 1)
        return res * res * x;
    else
        return res * res;
}

int power_iterative(int x, int n)
{
    long long res = 1;
    while (n)
    {
        if (n & 1)
            res *= x;
        x *= x;
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