#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    ll k, n, w;
    cin >> k >> n >> w;
    ll sum = w * (w + 1) / 2;
    sum *= k;
    if (n >= sum)
        cout << 0 << "\n";
    else
        cout << sum - n << "\n";

    return 0;
}