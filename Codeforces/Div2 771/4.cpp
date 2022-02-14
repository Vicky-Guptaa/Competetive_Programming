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
        int arr[n], brr[n], crr[n] = {0};
        int asum = 0, bsum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            asum += arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> brr[i];
            bsum += brr[i];
            crr[i] = arr[i] - brr[i];
        }
        if (n == 1)
        {
            cout << 0 << "\n";
            continue;
        }
        for (int i = 0; i < n; i++)
        {
        }
    }
    return 0;
}