#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int No_Of_Subarray_Divisible_By(vector<int> arr, int n)
{
    vector<int> presum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        presum[i] = presum[i - 1] + arr[i - 1];
    }
    for (auto &x : presum)
    {
        x %= n;
    }
    vector<int> freq(n + 1, 0);
    for (auto &x : presum)
    {
        freq[x]++;
    }
    int result = 0;
    for (auto &x : freq)
    {
        result += (x * (x - 1)) / 2; // nC2;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    cout << No_Of_Subarray_Divisible_By(arr, n) << '\n';
    return 0;
}