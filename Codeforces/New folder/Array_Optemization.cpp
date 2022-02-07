#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int Count(deque<int> dq)
{
    vector<int> arr;
    while (!dq.empty())
    {
        arr.push_back(dq.front());
        dq.pop_front();
    }
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
                count++;
        }
    }
    return count;
}

void Min_Inversion(int arr[], int n, deque<int> dq, int *cnt)
{
    if (n == 0)
    {
        *cnt = min(Count(dq), *cnt);
        return;
    }
    for (int i = 1; i < n; i++)
    {
        if (dq.front() >= arr[i])
            dq.push_front(arr[i]);

        else if (dq.back() <= arr[i])
            dq.push_back(arr[i]);
        else
        {
            dq.push_front(arr[0]);
            Min_Inversion(arr + 1, n - 1, dq, cnt);
            dq.pop_front();
            dq.push_back(arr[0]);
            Min_Inversion(arr + 1, n - 1, dq, cnt);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int cnt = 2147483647;
        deque<int> dq;
        dq.push_back(arr[0]);
        int i;

        if (i == n)
            cout << Count(dq) << endl;
        else
            cout << cnt << endl;
    }
    return 0;
}