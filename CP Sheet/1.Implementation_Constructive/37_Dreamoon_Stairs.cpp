#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    if (n < m)
    {
        cout << -1 << "\n";
    }
    else
    {
        int x = (n & 1 == 1) ? n - 3 : n - 2;
        for (x; x >= 0; x -= 2)
        {
            if ((n - x) % m == 0)
            {
                break;
            }
        }
        cout << x << "\n";
        int steps = (x / 2) + n - x;
        cout << steps << "\n";
    }
    return 0;
}