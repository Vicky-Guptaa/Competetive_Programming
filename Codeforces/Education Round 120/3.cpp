#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        int arr[n], sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        vector<int> presum = {0};
        for (int i = 1; i < n; i++)
        {
            sum += arr[i];
            presum.push_back(sum);
        }
        if (n == 1 && arr[0] <= k)
        {
            cout << 0 << "\n";
            continue;
        }
        else if (n == 1 && arr[0] > k)
        {
            cout << arr[0] - k << "\n";
            continue;
        }
        else if (presum[n - 1] <= k)
        {
            cout << 0 << "\n";
            continue;
        }
        int min_oper = 1e9;
        for (int i = 0; i < n - 1; i++)
        {
            int val = (k - presum[i]) / (n - 1 - i);
            for (int j = val - 2; j <= val + 1; j++)
            {
                if (k < presum[i] + (n - i) * j)
                    continue;
                int oper = 0;
                if (arr[0] <= k)
                    oper += arr[0] - k;
                oper += n - 1 - i;
                min_oper = min(oper, min_oper);
            }
        }
        cout << min_oper << "\n";
    }
    return 0;
}