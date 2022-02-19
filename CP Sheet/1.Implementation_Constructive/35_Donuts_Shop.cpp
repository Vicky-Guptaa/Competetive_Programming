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
        ll a, b, c;
        cin >> a >> b >> c;
        if (a < c)
        {
            cout << 1 << " ";
        }
        else
        {
            cout << -1 << " ";
        }
        if (c < a * b)
        {
            cout << b << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}