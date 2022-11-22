#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<int> nP = {1, 4, 6, 8, 9, 0};
vector<int> p = {2, 3, 5, 7};

int helper(int s, int n, int k, int mL, vector<int> &bP, vector<vector<int>> &dp, int len)
{
    if (s == n)
    {
        if (k == 0)
            return 1;
        return 0;
    }
    if (k == 0)
    {
        if (len - bP[s] >= mL)
            return 1;
        return 0;
    }

    if (dp[s][k] != -1)
        return dp[s][k];

    long long ways = 0, mod = 1e9 + 7;
    for (int i = s; i < n; i++)
    {
        if (mL <= bP[i] - bP[s] + 1)
        {
            ways += helper(i + 1, n, k - 1, mL, bP, dp, len);
            ways %= mod;
        }
    }
    return dp[s][k] = ways;
}

int beautifulPartitions(string s, int k, int minLength)
{
    int n = s.size();
    if (s[0] != '2' && s[0] != '3' && s[0] != '5' && s[0] != '7')
        return 0;
    vector<int> bP = {0};
    for (int i = 1; i < n; i++)
    {
        bool ptrue = false, nptrue = false;
        for (auto x : nP)
        {
            if (x == s[i] - '0')
            {
                nptrue = true;
                break;
            }
        }
        if (i < n - 1)
        {
            for (auto x : p)
            {
                if (x == s[i + 1] - '0')
                {
                    ptrue = true;
                    break;
                }
            }
        }
        if (nptrue && ptrue)
        {
            bP.push_back(i);
        }
        if (i == n - 1 && nptrue)
        {
            bP.push_back(i);
        }
    }

    if (bP.back() != n - 1)
        return 0;
    n = bP.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return helper(0, n, k, minLength, bP, dp, s.size());
}

int main()
{
    cout << beautifulPartitions("23542185131", 3, 2) << "\n";
    return 0;
}