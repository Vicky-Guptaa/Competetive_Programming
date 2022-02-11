#include <bits/stdc++.h>
using namespace std;

int Missing_Number(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < n)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] > 0)
        {
            return i + 1;
        }
    }
    return n ;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n - 1; i++)
        cin >> arr[i];

    cout << Missing_Number(arr, n) << endl;
    return 0;
}