#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

typedef long long ll;

int helper(int n, int m, vector<vector<int>> &dp)
{
    if (n == m)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    int minWays = 1e9;
    for (int i = 1; i < n; i++)
    {
        int temp = 1;
        temp += (dp[i][m] != -1) ? dp[i][m] : helper(i, m, dp);
        temp += (dp[n - i][m] != -1) ? dp[n - i][m] : helper(n - i, m, dp);
        minWays = min(minWays, temp);
    }
    for (int i = 1; i < m; i++)
    {
        int temp = 1;
        temp += (dp[n][i] != -1) ? dp[n][i] : helper(n, i, dp);
        temp += (dp[n][m - i] != -1) ? dp[n][m - i] : helper(n, m - i, dp);
        minWays = min(minWays, temp);
    }
    return dp[n][m] = minWays;
}

int main()
{
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int ans = helper(n, m, dp);
    cout << ans << "\n";
    return 0;
}