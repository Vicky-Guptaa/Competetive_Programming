#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

long long helper(int s, bool isEven, int N, int X, vector<long long> &A, vector<vector<long long>> &dp)
{
    if (s >= N)
        return -1e15;
    if (s == N - 1)
    {
        return A[s];
    }
    if (dp[s][isEven] != -1)
        return dp[s][isEven];

    return dp[s][isEven] = max(helper(s + 2, isEven, N, X, A, dp) + A[s], helper(s + 1, !isEven, N, X, A, dp) + A[s] - X);
}

long long solve(int N, vector<long long> A, int X)
{
    vector<vector<long long>> dp(N + 1, vector<long long>(2, -1));
    return max(helper(0, 1, N, X, A, dp), helper(1, 0, N, X, A, dp));
}

int main()
{
    vector<long long> A = {1, 2, 100, 10};
    cout << solve(4, A, 15) << "\n";
    return 0;
}