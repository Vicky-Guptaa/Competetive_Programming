#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long ll;

void Three_Number(ll n)
{
    ll temp = n;
    unordered_map<int, int> umap;
    for (ll i = 2; i * i <= n; i++)
    {
        while (temp % i == 0)
        {
            umap[i]++;
            temp /= i;
        }
        if (temp == 1)
            break;
    }
    if (temp != 1)
    {
        umap[temp]++;
    }
    if (umap.size() >= 3)
    {
        cout << "YES\n";
        auto itr = umap.begin();
        int k = 2;
        while (k--)
        {
            cout << int(pow(itr->first, itr->second)) << " ";
            itr++;
        }
        ll last = 1;
        ;
        while (itr != umap.end())
        {
            last *= pow(itr->first, itr->second);
            itr++;
        }
        cout << int(last);
        cout
            << "\n";
    }
    else if (umap.size() >= 2)
    {
        auto itr = umap.begin();
        if (itr->second >= 3)
        {
            cout << "YES\n";
            cout << int(itr->first) << " " << int(pow(itr->first, itr->second - 1)) << " ";
            itr++;
            cout << int(pow(itr->first, itr->second)) << "\n";
        }
        else if ((++itr)->second >= 3)
        {
            cout << "YES\n";
            cout << int(pow(umap.begin()->first, umap.begin()->second)) << " " << int(itr->first) << " " << int(pow(itr->first, itr->second - 1)) << "\n";
        }
        else if (umap[umap.begin()->first] >= 2 && umap[itr->first] >= 2)
        {
            cout << "YES\n";
            cout << int(umap.begin()->first) << " " << int(itr->first) << " " << int(umap.begin()->first * itr->first) << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    else if (umap.size() >= 1 && umap[umap.begin()->first] >= 6)
    {
        cout << "YES\n";
        auto itr = umap.begin();
        cout << int(itr->first) << " " << int(pow(itr->first, 2)) << " " << int(pow(itr->first, itr->second - 3)) << "\n";
    }
    else
    {
        cout << "NO\n";
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        Three_Number(n);
    }
    return 0;
}