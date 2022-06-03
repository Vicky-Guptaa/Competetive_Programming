#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;

#define ll long long int
int main()
{
    ll n, x;
    cin >> n >> x;
    ll xx = x;
    ll sum = 0;
    string s = to_string(xx);
    if (x == 1 and n > 1)
    {
        cout << -1 << endl;
        return 0;
    }
    if (s.size() == n)
    {
        cout << 0 << endl;
        return 0;
    }

    while (s.size() != n)
    {
        int m = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int a = s[i] - '0';
            m = max(m, a);
        }

        if (m == 1)
        {
            cout << -1 << endl;
            return 0;
        }

        string ss = s;
        ll xxx = (stoll(ss));
        ll newnum = m * xxx;
        s = to_string(newnum);
        cout << m << " " << ss << "\n";
        // cout<<s<<endl;
        sum++;
    }

    cout << sum << endl;

    return 0;
}