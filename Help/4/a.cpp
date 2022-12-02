#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

bool mycomp(vector<ll> &a, vector<ll> &b)
{
    if (a[0] != b[0])
        return a[0] < b[0];
    return a[1] < b[1];
}

int helper(int s, int n, vector<vector<ll>> &combine, vector<int> &strt, vector<int> &dp)
{
    if (s == n)
    {
        return 0;
    }
    if (dp[s] != -1)
        return dp[s];

    int skip = helper(s + 1, n, combine, strt, dp);
    int indx = lower_bound(strt.begin(), strt.end(), combine[s][1]) - strt.begin();
    int consider = helper(indx, n, combine, strt, dp) + combine[s][2];

    return dp[s] = max(skip, consider);
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<ll>> combine;
    vector<int> strt(n), end(n), people(n);
    for (auto &x : people)
        cin >> x;
    for (auto &x : strt)
        cin >> x;
    for (auto &x : end)
        cin >> x;

    for (int i = 0; i < n; i++)
    {
        combine.push_back({strt[i], end[i], people[i]});
    }

    sort(strt.begin(), strt.end());
    sort(combine.begin(), combine.end(), mycomp);
    vector<int> dp(n + 1, -1);
    ll totalPeople = accumulate(people.begin(), people.end(), 0ll);
    cout << totalPeople - helper(0, n, combine, strt, dp) << '\n';
}

int main()
{
    solve();
    return 0;
}