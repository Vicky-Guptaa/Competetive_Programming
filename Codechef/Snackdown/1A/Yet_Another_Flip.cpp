#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N, K;
        cin >> N >> K;
        long double ans1 = log2(K + 1), ans2;
        if (K > 2)
            ans2 = log2(K - 1);
        if (ans1 == (int)ans1)
        {
            cout << "YES" << endl;
            long long sum = K, pro = 1;
            cout << ans1 << endl;
            while (sum >= 1)
            {
                cout << sum << endl;
                pro *= 2;
                sum -= pro;
            }
        }
        else if (K > 2 && ans2 == int(ans2))
        {
            cout << "YES" << endl;
            cout << ans2 + 1 << endl;
            K -= pow(2, ans2);
            cout << K << endl;
            long long num = K;

            K += pow(2, ans2 - 1) - 1;
            long long sum = K, pro = 1;
            while (sum >= num)
            {
                cout << sum << endl;
                pro *= 2;
                sum -= pro;
            }
            K++;
            K -= pow(2, ans2 - 1);
            cout << K << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}