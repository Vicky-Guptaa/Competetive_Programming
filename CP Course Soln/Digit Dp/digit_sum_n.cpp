#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll digit_sum(int strt, string &s, bool ristrict, ll sum, vector<vector<vector<ll>>> &dp)
{
    if (strt == s.size())
    {
        return sum;
    }
    if (dp[strt][sum][ristrict] != -1)
        return dp[strt][sum][ristrict];
    int end = (ristrict) ? s[strt] - '0' : 10;
    ll res = 0;
    for (int i = 0; i < end; i++)
    {
        res += digit_sum(strt + 1, s, false, sum + i, dp);
    }
    if (ristrict)
        res += digit_sum(strt + 1, s, true, sum + end, dp);
    return dp[strt][sum][ristrict] = res;
}

ll digitSum(string s)
{
    vector<vector<vector<ll>>> dp(s.size(), vector<vector<ll>>(s.size() * 10, vector<ll>(2, -1)));
    return digit_sum(0, s, true, 0, dp);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        if (x !=0)
            x--;
        ll left = digitSum(to_string(x));
        ll right = digitSum(to_string(y));
        ll ans = right - left;

        cout << ans << "\n";
    }
    return 0;
}