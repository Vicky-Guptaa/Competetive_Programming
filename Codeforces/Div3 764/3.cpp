#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
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
        sort(arr, arr + n);
        set<int> oset;
        for (int i = 0; i < n; i++)
        {
            do
            {
                if (arr[i] <= n && oset.find(arr[i]) == oset.end())
                {
                    oset.insert(arr[i]);
                    break;
                }
                arr[i] /= 2;

            } while (arr[i] > 0);
            if (arr[i] == 0)
            {
                cout << "NO\n";
                break;
            }
        }
        if (oset.size() == n)
        {
            cout << "YES\n";
        }
    }

    return 0;
}