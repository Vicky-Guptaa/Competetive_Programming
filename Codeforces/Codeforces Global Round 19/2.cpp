#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int mex(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < n)
        {
            arr[arr[i]] = -arr[arr[i]];
        }
    }
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

int result(vector<int> arr, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            res++;
        res++;
    }
    return res;
}

int solve(vector<int> &arr, int n)
{
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = i; j < n; j++)
        {
            temp.push_back(arr[j]);
            answer += result(temp, temp.size());
        }
    }
    return answer;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << solve(arr, n) << "\n";
    }
    return 0;
}