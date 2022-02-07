#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll Fast_Multiplication(ll a, ll b, ll c)
{
    ll res = 0;
    while (b)
    {
        if (b & 1)
            res += a, res %= c;
        a += a;
        a %= c;
        b >>= 1;
    }
    return res;
}

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    cout << Fast_Multiplication(a, b, c) << "\n";
    return 0;
}
// 99999999999999 99999999999999 1000000000000000