#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            cout << "10\n";
        }
        else if (n < 10)
        {
            cout << 10 + n << "\n";
        }
        string ans;
        while (n != 1)
        {
            for (int i = 9; i >= 2; i++)
            {
                if (n % i == 0)
                {
                    ans += (i + '0');
                    n /= i;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}