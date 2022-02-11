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
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n > 2)
        {
            cout << "NO\n";
        }
        else if (n == 1)
        {
            cout << "YES\n";
        }
        else
        {
            if (s[0] != s[1])
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