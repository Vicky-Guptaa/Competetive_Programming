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
        int oc = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i > 0 && i < n - 1 && arr[i] & 1)
            {
                oc++;
            }
        }
        int ec = n - oc - 2;
        if (oc == 1 && ec == 0)
        {
            cout << -1 << "\n";
            continue;
        }
        else
        {
            int onec = 0;
            for (int i = 1; i < n - 1; i++)
            {
                if (arr[i] == 1)
                {
                    onec++;
                }
            }
            if (onec == n - 2)
            {
                cout << -1 << "\n";
                continue;
            }
        }
        ll sum = 0;
        for (int i = 1; i < n - 1; i++)
        {
            sum += ceil(arr[i] + 1) / 2;
        }
        cout << sum << "\n";
    }
    return 0;
}