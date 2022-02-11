#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(int x, int y, int xc, int yc)
{
    bool checkx = false, checky = false;
    for (int i = xc; i >= 0 && !checkx; i -= 2)
    {
        if (i == x)
            checkx = true;
    }
    for (int i = -xc; i <= 0 && !checkx; i += 2)
    {
        if (i == x)
            checkx = true;
    }
    for (int i = yc; i >= 0 && !checky; i -= 2)
    {
        if (i == y)
            checky = true;
    }
    for (int i = -yc; i <= 0 && !checky; i += 2)
    {
        if (i == y)
            checky = true;
    }
    return (checkx && checky);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int len, x, y;
        cin >> len >> x >> y;
        string str;
        cin >> str;
        int x1 = 0, y1 = 0;
        bool xoy = true;
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '0')
                xoy = !xoy;
            if (xoy)
                x1++;
            else
                y1++;
        }
        if (isPossible(x, y, x1, y1) || isPossible(x, y, y1, x1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}