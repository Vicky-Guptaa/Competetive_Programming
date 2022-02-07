#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int row[n], col[m];
    int presumcl[m] = {0};
    int presumrl[n] = {0};
    int presumcr[m] = {0};
    int presumrr[n] = {0};
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> row[i];
        sum += row[i];
        presumrl[i] = sum;
    }
    sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> col[i];
        sum += col[i];
        presumcl[i] = sum;
    }
    sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sum += row[i];
        presumrr[i] = sum;
    }
    sum = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        sum += col[i];
        presumcr[i] = sum;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int cost = 0;
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
        {
            cost += abs(presumrr[x2] - presumrr[x1]);
        }
        else if (x1 < x2)
        {
            cost += abs(presumrl[x2] - presumrl[x1]);
        }
        if (y1 > y2)
        {
            cost += abs(presumcr[y2] - presumcr[y1]);
        }
        else if (y1 < y2)
        {
            cost += abs(presumcl[y2] - presumcl[y1]);
        }
        cout << cost << "\n";
    }

    return 0;
}