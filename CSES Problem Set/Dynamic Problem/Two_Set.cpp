#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int mod = 1e9 + 7;
int helper(int s, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    if (s >= arr.size())
    {
        return 0;
    }
    if (sum == 0)
        return 1;

    if (dp[s][sum] != -1)
        return dp[s][sum];

    if (sum >= arr[s])
        return dp[s][sum] = (helper(s + 1, sum, arr, dp) + helper(s + 1, sum - arr[s], arr, dp)) % mod;
    else
        return dp[s][sum] = helper(s + 1, sum, arr, dp) % mod;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 1; i <= n; i++)
    {
        arr[i - 1] = i + 1;
    }
    int sum = n * (n + 1) / 2;
    if (sum & 1)
    {
        cout << "0\n";
        return 0;
    }
    sum /= 2;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    ll ans = helper(0, sum, arr, dp);
    cout << ans << "\n";

    return 0;
}