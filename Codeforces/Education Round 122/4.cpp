#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
vector<int> precomp(1001, 2e9);

void PreCompute(vector<int> &dp)
{
    dp[1] = 0;
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j <= dp.size(); j++)
        {
            int ai = i + (i / j);
            if (ai <= 1001)
                if (dp[ai] > dp[i] + 1)
                {
                    dp[ai] = dp[i] + 1;
                }
        }
    }
}

int Max_Sum(int n, int k, int brr[], int crr[], vector<vector<int>> &dp)
{
    if (n < 0)
    {
        return 0;
    }

    if (dp[n][k] != -1)
        return dp[n][k];

    int req = precomp[brr[n]];
    if (k >= req)
    {
        return dp[n][k] = max(Max_Sum(n - 1, k, brr, crr, dp), Max_Sum(n - 1, k - req, brr, crr, dp) + crr[n]);
    }
    else
    {
        return dp[n][k] = Max_Sum(n - 1, k, brr, crr, dp);
    }
}

int main()
{
    PreCompute(precomp);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int brr[n], crr[n];
        int oper = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> brr[i];
            oper += precomp[brr[i]];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> crr[i];
        }

        if (oper <= k)
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += crr[i];
            }
            cout << sum << "\n";
            continue;
        }
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        int answer = Max_Sum(n - 1, k, brr, crr, dp);
        cout << answer << "\n";
    }
    return 0;
}