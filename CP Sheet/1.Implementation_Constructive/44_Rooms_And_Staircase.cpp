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
        string s;
        cin >> s;
        int stair = 1e9;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                stair = min(i, min(n - i - 1, stair));
        }
        if (stair == 1e9)
            cout << n << "\n";
        else
            cout << 2 * n - stair * 2 << "\n";
    }
    return 0;
}