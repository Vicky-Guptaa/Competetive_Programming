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
        int a, b, q;
        cin >> a >> b >> q;
        ll ab = a * b;
        vector<int> prefix_sum;
        for (int i = 0; i < ab; i++)
        {
            if (((i % a) % b) != ((i % b) % a))
                prefix_sum.push_back(1);
            else
                prefix_sum.push_back(0);
        }
        ll sum = 0;
        for (int i = 0; i < prefix_sum.size(); i++)
        {
            sum += prefix_sum[i];
            prefix_sum[i] = sum;
        }
        while (q--)
        {
            ll l, r;
            cin >> l >> r;
            ll l_ans = (l / ab) * prefix_sum[prefix_sum.size() - 1];
            ll rem = ((l % ab) + ab) % ab;
            if (rem != 0)
                l_ans += prefix_sum[rem - 1];

            ll r_ans = (r / ab) * prefix_sum[prefix_sum.size() - 1];
            rem = ((r % ab) + ab) % ab;
            r_ans += prefix_sum[rem];

            cout << r_ans - l_ans << " ";
        }
        cout << "\n";
    }
    return 0;
}