#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

bool solve1(ll a, ll b, ll c)
{
    ll l = 1, h = 1e10;
    while (l <= h)
    {
        ll mid = (l + h) / 2;
        ll moda = a * mid;
        if (b - moda == c - b)
        {
            return true;
        }
        else if (b - moda < c - b)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return false;
}

bool solve2(ll a, ll b, ll c)
{
    ll l = 1, h = 1e10;
    while (l <= h)
    {
        ll mid = (l + h) / 2;
        ll modb = b * mid;
        if (modb - a == c - modb)
        {
            return true;
        }
        else if (modb - a > c - modb)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return false;
}

bool solve3(ll a, ll b, ll c)
{
    ll l = 1, h = 1e10;
    while (l <= h)
    {
        ll mid = (l + h) / 2;
        ll modc = c * mid;
        if (b - a == modc - b)
        {
            return true;
        }
        else if (b - a < modc - b)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if ((c - b) == (b - a))
            cout << "YES\n";
        else if (solve1(a, b, c) || solve2(a, b, c) || solve3(a, b, c))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}