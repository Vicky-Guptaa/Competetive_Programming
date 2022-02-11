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
        ll hc, dc, hm, dm, k, w, a;
        cin >> hc >> dc >> hm >> dm >> k >> w >> a;
        if (ceil((long double)hc / dm) < (long double)hm / dc)
        {
            if (k == 0)
            {
                cout << "NO\n";
                continue;
            }
            bool isFound = false;
            for (int i = 1; i <= k; i++)
            {
                if (ceil((hc + a * i) / (long double)dm) >= ceil((long double)hm / (dc + w * (k - i))))
                {
                    isFound = true;
                    break;
                }
                if (ceil((hc + a * (k - i)) / (long double)dm) >= ceil((long double)hm / (dc + w * i)))
                {
                    isFound = true;
                    break;
                }
            }
            if (isFound)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            cout << "Yes\n";
        }
    }
    return 0;
}