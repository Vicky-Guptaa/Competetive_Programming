#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<ll> subsetSum(vector<ll> arr)
{
    int n = arr.size();
    vector<ll> res;
    ll size = 1 << n;
    for (int i = 0; i < size; i++)
    {
        ll sum = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
                sum += arr[j];
        }
        res.push_back(sum);
    }
    return res;
}

int main()
{
    ll a, b, n;
    cin >> n >> a >> b;

    vector<ll> arr(n);
    for (auto &x : arr)
        cin >> x;

    vector<ll> left, right;
    for (int i = 0; i < n / 2; i++)
        left.push_back(arr[i]);

    for (int i = n / 2; i < arr.size(); i++)
        right.push_back(arr[i]);

    vector<ll> left_sum = subsetSum(left);
    vector<ll> right_sum = subsetSum(right);

    sort(right_sum.begin(), right_sum.end());
    ll ans = 0;
    for (int i = 0; i < left_sum.size(); i++)
    {
        ans += upper_bound(right_sum.begin(), right_sum.end(), b - left_sum[i]) - lower_bound(right_sum.begin(), right_sum.end(), a - left_sum[i]);
    }
    cout << ans << "\n";
    return 0;
}