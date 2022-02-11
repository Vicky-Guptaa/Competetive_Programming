#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define mod 1000000007
using namespace std;

void LIS(vector<pair<int, int>> arr, int n)
{
    vector<long long> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        dp[i] = arr[i].second;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i].first > arr[j].first)
            {
                dp[i] = dp[i] % mod + ((long long)arr[i].second * dp[j]) % mod;
            }
        }
    }
    long long answer = 0;
    for (int i = 0; i < n; i++)
    {
        answer = dp[i] % mod + answer % mod;
        answer %= mod;
    }
    cout << answer << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            umap[arr[i]]++;
        }
        vector<pair<int, int>> newarr;
        for (auto x : umap)
            newarr.push_back({x.first, x.second});
        if (n == umap.size())
        {
        }
        sort(newarr.begin(), newarr.end());
        LIS(newarr, newarr.size());
    }
    return 0;
}