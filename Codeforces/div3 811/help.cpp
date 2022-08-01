#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int solve(vector<int> &arr, double k)
{
    int n = arr.size(), cnt = 0;
    for (int i = 0; i < n; i++)
    {
        double sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if ((sum / (j - i + 1)) == k)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n;
    double k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;

    cout << solve(arr, k) << "\n";

    return 0;
}