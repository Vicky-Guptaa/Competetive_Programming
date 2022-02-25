#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverse(arr, arr + n);
    ll max_sum = 0;
    int prev = 0;
    for (int i = 0; i <= 0; i++)
    {
        ll sum = arr[i];
        prev = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (min(prev - 1, arr[j]) == 0)
                break;
            sum += min(prev - 1, arr[j]);
            prev = min(prev - 1, arr[j]);
        }
        if (max_sum < sum)
        {
            max_sum = sum;
        }
    }
    cout << max_sum << "\n";
    return 0;
}