#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,k;
    cin >> n>>k;
    vector<pair<ll, ll>> range(n);
    for (auto &x : range)
        cin >> x.first >> x.second;

    vector<pair<ll, ll>> segments;
    for (auto x : range)
    {
        segments.push_back({x.first, 1});
        segments.push_back({x.second, -1});
    }
    sort(segments.begin(), segments.end());

    int cnt = 0;
    vector<ll> lengthCovered(n + 1);
    for (int i = 0; i < segments.size(); i++)
    {
        int j = i;
        while (j < segments.size() && segments[j].first == segments[i].first)
        {
            cnt += segments[j].second;
            j++;
        }
        i = j - 1;
        if (i != (int)segments.size() - 1)
        {
            ll segLen = segments[i + 1].first - segments[i].first;
            lengthCovered[cnt] += segLen;
        }
    }

    for (int i = n - 1; i >= 1; i--)
    {
        lengthCovered[i] += lengthCovered[i + 1];
    }
    for (int i = 0; i < lengthCovered.size(); i++)
    {
        cout << i << " " << lengthCovered[i] << "\n";
    }
    return;
}

int main()
{
    solve();
    return 0;
}