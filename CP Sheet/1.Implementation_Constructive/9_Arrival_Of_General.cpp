#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        int Max = -1e9, Maxi = 0, Min = 1e9, Mini = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (Max < arr[i])
            {
                Max = arr[i];
                Maxi = i;
            }
            if (Min >= arr[i])
            {
                Min = arr[i];
                Mini = i;
            }
        }
        if (Max == Min)
        {
            cout << 0 << "\n";
        }
        else if (Mini > Maxi)
        {
            cout << Maxi + n - Mini - 1 << "\n";
        }
        else
        {
            cout << Maxi + n - 1 - Mini - 1 << "\n";
        }
    }

    return 0;
}