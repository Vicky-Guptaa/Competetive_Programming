#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

ll sumRnge(ll l, ll r)
{
    return (((r) * (r + 1)) / 2) - ((l * (l - 1)) / 2);
}

void solve()
{
    ll n, s, l;
    cin >> n >> l >> s;
    ll low = 1, high = n - l + 1, ans = 0;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll sum = sumRnge(mid, mid + l - 1);
        if (sum >= s)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (sumRnge(ans, ans + l - 1) == s)
    {
        cout << "YES\n";
        return;
    }
    if (ans <= 1)
    {
        cout << "NO\n";
         return;
    }
    ll val = sumRnge(ans - 1, ans + l - 1) - s;
    if (val >= ans && ans + l >= val)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}