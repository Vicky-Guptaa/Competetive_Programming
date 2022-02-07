#include <iostream>
#include <algorithm>
using namespace std;

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
        {
            cin >> arr[i];
        }
        if (arr[0] != n && arr[n - 1] != n)
        {
            cout << -1 << "\n";
            continue;
        }
        else
        {
            if (arr[0] == n)
            {
                reverse(arr + 1, arr + n);
            }
            else
            {
                reverse(arr, arr + n - 1);
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
