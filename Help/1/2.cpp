#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int maxi = 1e5 + 1;
int dp[maxi][6][6][6];
int go(int n, int k, int x, int last_color)
{
    if (n == 0)
    {
        return 1;
    }
    if (dp[n][k][x][last_color] != -1)
    {
        return dp[n][k][x][last_color];
    }
    ll ans = 0;
    for (int i = 1; i <= k; i++)
    {
        if (last_color != i || (last_color == x and x == i))
        {
            ans = (ans % mod + go(n - 1, k, x, i) % mod) % mod;
        }
    }
    return dp[n][k][x][last_color] = ans % mod;
}
int solution(int N, int K, int X)
{
    memset(dp, -1, sizeof dp);
    int x = go(N, K, X, 0);
    return x;
}