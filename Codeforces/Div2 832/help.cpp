#include <iostream>
#include <stack>
#include <vector>
using namespace std;

long long findMaxSum(vector<long long> arr, int n)
{
    long long CL[n] = {0}, CR[n] = {0};

    stack<int> q;

    for (int i = 0; i < n; i++)
    {
        while (q.size() != 0 && arr[q.top()] <= arr[i])
        {
            CL[i] += CL[q.top()] + 1;
            q.pop();
        }
        q.push(i);
    }

    while (q.size() != 0)
        q.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (q.size() != 0 && arr[q.top()] < arr[i])
        {
            CR[i] += CR[q.top()] + 1;
            q.pop();
        }
        q.push(i);
    }

    while (q.size() != 0)
        q.pop();

    long long ans = 0;

    for (int i = 0; i < n; i++)
        ans += (CL[i] + 1) * (CR[i] + 1) * arr[i];

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n, 0);
    for (auto &x : arr)
        cin >> x;

    long long ans = 0, mod = 1e9;
    for (int i = 0; i < n; i++)
    {
        ans += findMaxSum(arr, n - i);
        ans %= mod;
    }
    cout << ans << "\n";
}