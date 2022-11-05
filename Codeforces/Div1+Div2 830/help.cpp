#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int helper(int N, vector<int> &dp)
{
    if (N == 1)
        return 0;
    if (dp[N] != -1)
    {
        return dp[N];
    }
    int ans = helper(N - 1, dp);
    for (int i = 1; i < N; i++)
    {
        if (N % i == 0)
        {
            ans = min(ans, helper(N - i, dp));
        }
    }
    return dp[N] = ans + 1;
}

int reduceToOne(int N)
{
    vector<int> dp(N + 1, -1);
    return helper(N, dp);
}

int main()
{
    cout << reduceToOne(5) << "\n";
    return 0;
}