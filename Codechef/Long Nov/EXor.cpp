#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long power2 = 1;
        long long ans = 0;
        bool notfound = false;
        for (int i = 0; i < 64; i++)
        {
            long long Xor = 0;
            for (int i = 0; i < n; i++)
                Xor ^= arr[i];
            if (i == 63 && (Xor & power2 == 1))
            {
                notfound = true;
                break;
            }
            if (Xor & power2 == 1)
            {
                ans += power2;
                for (int j = 0; j < n; j++)
                    arr[j] += power2;
            }
            power2 *= 2;
        }
        if (notfound)
        {
            cout << -1 << endl;
        }
        else
            cout << ans << endl;
    }
    return 0;
}
