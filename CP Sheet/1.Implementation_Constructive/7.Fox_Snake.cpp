#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        bool reverse = 0;
        string a, b, c;
        for (int i = 0; i < m; i++)
        {
            if (i == 0)
                c += "#";
            else
                c += ".";
            if (i == m - 1)
                b += "#";
            else
                b += ".";
            a += "#";
        }
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                cout << a << "\n";
            }
            else
            {
                if (reverse)
                {
                    cout << c << '\n';
                }
                else
                {
                    cout << b << "\n";
                }
                reverse = !reverse;
            }
        }
    }
    return 0;
}