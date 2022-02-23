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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i] += k;
        }
        vector<int> result;
        priority_queue<pp, vector<pp>, greater<pp>> pque;
        for (int i = 0; i < n; i++)
        {
            pque.push({arr[i], i});
        }
        int Max_sum = max_sum(arr, n);
        result.push_back(Max_sum);
        while (!pque.empty())
        {
            int ind = pque.top().second;
            arr[ind] -= k;
            pque.pop();
            Max_sum = max_sum(arr, n);
            result.push_back(Max_sum);
        }
        reverse(result.begin(), result.end());
        for (auto x : result)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}