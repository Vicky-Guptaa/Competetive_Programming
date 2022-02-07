#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    ll tsum =(ll)n * (n + 1) / 2;
    if (tsum % 2 == 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    stack<int> st1, st2;
    ll s1 = 0, s2 = 0;
    st1.push(n);
    s1 += n;
    n--;
    while (n > 0)
    {
        if (s1 > s2)
        {
            st2.push(n);
            s2 += n;
        }
        else
        {
            st1.push(n);
            s1 += n;
        }
        n--;
    }
    if (s1 == s2)
    {
        cout << "YES\n";
        cout << st1.size() << "\n";
        while (st1.size())
        {
            cout << st1.top() << " ";
            st1.pop();
        }
        cout << "\n"
             << st2.size() << "\n";
        while (st2.size())
        {
            cout << st2.top() << " ";
            st2.pop();
        }
    }
    else
        cout << "NO" << endl;
    return 0;
}