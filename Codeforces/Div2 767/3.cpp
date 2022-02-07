#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        if (l == 1 && r == 1)
        {
            cout << "NO\n";
            continue;
        }
        else if (l == r)
        {
            cout << "YES\n";
            continue;
        }
        if (l % 2 == 0 && r % 2 == 0)
        {
            if ((r - l) / 2 <= k)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else if (l % 2 == 1 && r % 2 == 1)
        {
            if (l == 1 && (r - l + 2) / 2 <= k)
            {
                cout << "YES\n";
            }
            else if ((r - l + 2) / 2 <= k)
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
            if ((r - l + 1) / 2 <= k)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}