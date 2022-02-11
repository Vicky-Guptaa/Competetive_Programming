#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(int xi, int yi, int xd, int yd, int n, int m, int &time, int d[])
{
    if (xi > n || yi > m || xi <= 0 || yi <= 0)
    {
        if (xi > n || xd <= 0)
            d[0] = -d[0];
        if (yi > m || yd <= 0)
            d[1] = -d[1];
        return 0;
    }
    if (xi == xd || yi == yd)
        return 1;
    int ans = dfs(xi + d[0], yi + d[1], xd, yd, n, m, ++time, d);
    if (ans == 1)
        return 1;
    else
        return dfs(xi + d[0], yi + d[1], xd, yd, n, m, time, d);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xi, yi;
        cin >> xi >> yi;
        int xd, yd;
        cin >> xd >> yd;
        int time = 0;
        int d[2] = {1, 1};
        dfs(xi, yi, xd, yd, n, m, time, d);
        cout << time << "\n";
    }
    return 0;
}