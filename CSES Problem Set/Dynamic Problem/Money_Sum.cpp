#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

int main()
{
    int n, m = 0;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
    {
        cin >> x;
        m += x;
    } 
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int val = 0; val <= m; val++)
        {
            dp[i][val] = dp[i - 1][val];
            if (val - arr[i - 1] >= 0)
                dp[i][val] = (dp[i - 1][val - arr[i - 1]]|dp[i - 1][val]);
        }
    }
    vector<int> res;

    for (int i = 1; i <= m; i++)
    {
        if (dp[n][i])
            res.push_back(i);
    }

    cout << res.size() << "\n";
    for (auto x : res)
        cout << x << " ";
    cout << "\n";

    return 0;
}