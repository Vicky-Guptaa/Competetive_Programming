#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        unsigned long long int n, m, answer = 0;
        cin >> n >> m;
        bool check = true; // n>m
        if (n < m)
            check = false;
        answer = max(m,n)*max(n,m);
        if (max(n, m) % 2 == 0)
        {
            if (check)
            {
                answer -= min(m, n) - 1;
            }
            else
            {
                answer -= 2 * max(m, n) - min(m, n) - 1;
            }
        }
        else
        {
            if (!check)
            {
                answer -= min(m, n) - 1;
            }
            else
            {
                answer -= 2 * max(m, n) - min(m, n) - 1;
            }
        }

        cout << answer << endl;
    }

    return 0;
}