#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pp;

int max_sum(int arr[], int n)
{
    int sum = 0, max_sum = arr[0];
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        max_sum = max(max_sum, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return max_sum < 0 ? 0 : max_sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        int presum[n + 1] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; i++)
        {
            presum[i] = presum[i - 1] + arr[i - 1];
        }
        // for (auto x : presum)
        //     cout << x << " ";

        vector<int> result;
        for (int i = 0; i <= n; i++)
        {
            int max_sum = INT_MIN;
            for (int j = 0; j <= n - i; j++)
            {
                max_sum = max(max_sum, presum[j + i] - presum[j]);
            }
            result.push_back(max_sum);
        }
        // for (auto x : result)
        //     cout << x << " ";
        // cout << "\n";
        for (int i = 0; i <= n; i++)
        {
            int max_sum = INT_MIN;
            for (int j = 0; j < result.size(); j++)
            {
                max_sum = max(max_sum, result[j] + min(i, j) * k);
            }
            cout << max_sum << " ";
        }
        cout << "\n";
    }
    return 0;
}