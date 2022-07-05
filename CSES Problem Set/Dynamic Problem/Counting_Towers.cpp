#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

int helper(int s, bool isLinked, int &n, vector<vector<int>> &dp)
{
    if (s == n)
        return 1;

    if (dp[s][isLinked] != -1)
        return dp[s][isLinked];

    ll ways = 0;
    if (isLinked)
    {

        ways += 2ll * helper(s + 1, isLinked, n, dp) + helper(s + 1, !isLinked, n, dp);
    }
    else
    {
        ways += 4ll * helper(s + 1, isLinked, n, dp) + helper(s + 1, !isLinked, n, dp);
    }
    ways %= mod;

    return dp[s][isLinked] = ways;
}

void helper_iter(vector<vector<int>> &dp)
{
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= 1e6; i++)
    {
        dp[i][0] = (4ll * dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][1] = (2ll * dp[i - 1][1] + dp[i - 1][0]) % mod;
    }
}

int main()
{
    int t;
    cin >> t;
    vector<vector<int>> dp(1e6 + 1, vector<int>(2, 0));
    helper_iter(dp);
    while (t--)
    {
        int n;
        cin >> n;
        ll ans = dp[n][0] + dp[n][1];
        ans %= mod;
        cout << ans << "\n";
    }
    return 0;
}