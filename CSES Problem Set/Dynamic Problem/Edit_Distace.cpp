#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int helper(int it1, int it2, string &s, string &p, vector<vector<int>> &dp)
{
    int ssize = s.size(), psize = p.size();

    if (it1 == ssize)
        return (psize - it2);

    if (it2 == psize)
        return (ssize - it1);

    if (dp[it1][it2] != -1)
        return dp[it1][it2];

    int oper = 0;
    if (s[it1] == p[it2])
    {
        oper += helper(it1 + 1, it2 + 1, s, p, dp);
    }
    else
    {
        oper = 1 + min(helper(it1 + 1, it2 + 1, s, p, dp), min(helper(it1 + 1, it2, s, p, dp), helper(it1, it2 + 1, s, p, dp)));
    }
    return dp[it1][it2] = oper;
}

int main()
{
    string s, p;
    cin >> s >> p;
    vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
    cout << helper(0, 0, s, p, dp);
    return 0;
}