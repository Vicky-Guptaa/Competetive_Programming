#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = n; i >= 1; i--)
        {
            arr[n - i] = i;
        }
        for (auto x : arr)
        {
            cout << x << " ";
        }
        cout << "\n";
        for (int i = 1; i < n; i++)
        {
            swap(arr[i], arr[i - 1]);
            for (auto x : arr)
            {
                cout << x << " ";
            }
            cout << "\n";
            swap(arr[i], arr[i - 1]);
        }
    }
    return 0;
}