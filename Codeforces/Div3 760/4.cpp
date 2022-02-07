#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int score = 0;
        for (int i = 0; i < k; i++)
        {
            score += arr[n - k - i - 1] / arr[n - 1 - i];
        }
        for (int i = 0; i < n - k * 2; i++)
        {
            score += arr[i];
        }
        cout << score << "\n";
    }
    return 0;
}