#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(long long arr[], long long mid, long long n, long long h)
{
    for (int i = 1; i < n; i++)
    {
        int time = arr[i] - arr[i - 1];
        if (time > mid)
        {
            h -= mid;
        }
        else
        {
            h -= time;
        }
    }
    h -= mid;
    if (h > 0)
        return false;
    else
        return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, h;
        cin >> n >> h;
        long long arr[n], pre[n - 1];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (n >= h)
        {
            cout << 1 << "\n";
        }
        else
        {
            long long low = 1, high = h, answer = 0;
            while (low <= high)
            {
                long long mid = low + (high - low) / 2;
                if (isValid(arr, mid, n, h))
                {
                    answer = mid;
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            cout << answer << "\n";
        }
    }
    return 0;
}