#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll Bitwise_And_Of_Range_Brute(ll l, ll r)
{
    ll ans = l;
    for (ll i = l + 1; i <= r; i++)
        ans &= i;
    return ans;
}

ll Bitwise_And_Of_Range_Optimal(ll l, ll r)
{
    ll shift_count = 0;
    while (l != r && l > 0)
    {
        shift_count++;
        l >>= 1;
        r >>= 1;
    }
    return (l << shift_count);
}

int main()
{
    ll l, r;
    cin >> l >> r;
    cout << Bitwise_And_Of_Range_Brute(l, r) << "\n";
    cout << Bitwise_And_Of_Range_Optimal(l, r) << "\n";
    return 0;
}