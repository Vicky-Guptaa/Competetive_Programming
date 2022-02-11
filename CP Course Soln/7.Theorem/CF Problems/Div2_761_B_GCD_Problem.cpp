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
        int c = 1, a, b;
        n -= c;
        if ((n & 1) == 1)
        {
            a = n / 2;
            b = (n / 2) + 1;
        }
        else
        {
            a = n / 2;
            b = n / 2;
            if (a & 1)
            {
                a -= 2;
                b += 2;
            }
            else
            {
                a--;
                b++;
            }
        }
        cout << a << " " << b << " " << c << '\n';
    }
    return 0;
}