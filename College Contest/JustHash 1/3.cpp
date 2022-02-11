#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 1000000007
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x[n], y[n], z[n];
        for (int i = 0; i < n; i++)
            cin >> x[i];
        for (int i = 0; i < n; i++)
            cin >> y[i];
        for (int i = 0; i < n; i++)
            cin >> z[i];
        sort(x, x + n);
        sort(y, y + n);
        sort(z, z + n);
        long long answer = 0;
        for (int i = 0; i < n; i++)
        {
            bool chck = false;
            long long sindx = upper_bound(y, y + n, x[i]) - y;
            if (sindx == n)
            {
                sindx--;
                chck = true;
            }
            long long tindx = upper_bound(z, z + n, y[sindx]) - z;
            if (chck)
                sindx++;
            answer = (answer % mod + ((sindx) * (tindx)) % mod) % mod;
        }
        cout << answer << " \n";
    }
    return 0;
}