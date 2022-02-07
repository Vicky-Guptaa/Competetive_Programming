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
        int n;
        cin >> n;
        int pow = 1;
        vector<int> ans;
        while (n)
        {
            int rem = (n % 10) * pow;
            if (rem != 0)
                ans.push_back(rem);
            n /= 10;
            pow *= 10;
        }
        cout << ans.size() << '\n';
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << '\n';
    }

    return 0;
}