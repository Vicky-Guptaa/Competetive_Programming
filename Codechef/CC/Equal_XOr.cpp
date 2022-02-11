#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        ll arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        unordered_map<ll, ll> umap, umap2;
        for (ll i = 0; i < n; i++)
        {
            umap[arr[i]]++;
            umap2[arr[i]]++;
        }

        ll Max=0;
        for (ll i = 0; i < n; i++)
        {
            if (umap.find((arr[i] ^ x)) != umap.end())
            {
                umap[arr[i] ^ x]++;
                if (umap[arr[i]] == 1)
                    umap.erase(arr[i]);
                else
                    umap[arr[i]]--;

                Max=max(Max,umap[arr[i]^x]);
            }
            
        }
        ll  Oper = INT_MAX;
        for (auto z : umap)
        {
            if (Max <= z.second)
            {
                int tempMax = max(umap2[z.first], umap2[z.first ^ x]);
                Max = z.second;
                if (Oper > Max - tempMax)
                {
                    Oper = Max - tempMax;
                }
            }
        }
        cout << Max << " " << Oper << endl;
    }
    return 0;
}

/*
Test Case -> 1. 6 1  -> 4 5 2 3 3 3 op 4 2
             2. 6 1  -> 4 5 2 3 3 4 op 3 3
             3. 10 1 -> 2 2 2 3 3 3 4 4 4 4 op 4 0
             4. 6 1  -> 2 2 2 2 3 3 op 6 4
*/