#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_set>
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
        unordered_set<int> uset;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            uset.insert(arr[i]);
        }
        sort(arr, arr + n);
        int k = n / 2;
        for (int i = 0; k > 0 && i < n; i++)
        {
            for (int j = i + 1; k > 0 && j < n; j++)
            {
                if (uset.find(arr[j] % arr[i]) == uset.end())
                {
                    k--;
                    cout << arr[j] << " " << arr[i] << "\n";
                }
            }
        }
    }
    return 0;
}