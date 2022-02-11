#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int t = 0, p;
    cin >> p;
    while (t++ < p)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int g = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - 1 - i])
                g++;
        }
        if (g == k)
        {
            cout << "Case #" << t << ": " << 0 << "\n";
        }
        else
        {
            cout << "Case #" << t << ": " << abs(k - g) << "\n";
        }
    }
    return 0;
}