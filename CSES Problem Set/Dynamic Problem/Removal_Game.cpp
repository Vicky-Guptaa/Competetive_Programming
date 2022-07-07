#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll helper(int l, int r, vector<int> &arr, vector<vector<ll>> &dp)
{
    if (l == r)
        return arr[l];
    if (l > r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];

    ll left = arr[l] + min(helper(l + 1, r - 1, arr, dp), helper(l + 2, r, arr, dp));
    ll right = arr[r] + min(helper(l + 1, r - 1, arr, dp), helper(l, r - 2, arr, dp));
    dp[l][r] = max(left, right);
    return dp[l][r];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
    ll ans = helper(0, n - 1, arr, dp);
    cout << ans << endl;
    return 0;
}