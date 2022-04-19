#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n, i, j, ans;

    cin >> t;

    for (; t--;)
    {
        cin >> n;

        ll child[n + 1];

        for (i = 0; i <= n; i++)
        {
            child[i] = 0;
        }

        ans = 0;

        for (i = 2; i <= n; i++)
        {
            cin >> j;
            child[j]++;
        }

        if (n == 2)
        {
            cout << "2\n";
            continue;
        }

        priority_queue<ll> q1, q2;

        for (i = 1; i <= n; i++)
        {
            if (child[i] > 0)
            {
                q1.push(child[i]);
            }
        }
        q1.push(1);

        j = q1.size();

        i = 0;

        while (q1.empty() == false)
        {
            ans++;
            if ((q1.top() - (j - i)) > 0)
            {
                q2.push(q1.top() - (j - i));
            }
            q1.pop();
            i++;
        }

        while (q2.empty() == false)
        {
            q1.push(q2.top());
            q2.pop();
        }

        while (q1.empty() == false)
        {
            ans++;

            if (q1.top() - 2 > 0)
            {
                q2.push(q1.top() - 2);
                q1.pop();
            }
            else
            {
                q1.pop();
            }

            while (q1.empty() == false)
            {
                if (q1.top() - 1 > 0)
                {
                    q2.push(q1.top() - 1);
                    q1.pop();
                }
                else
                {
                    q1.pop();
                }
            }

            while (q2.empty() == false)
            {
                q1.push(q2.top());
                q2.pop();
            }
        }

        cout << ans << "\n";
    }
}