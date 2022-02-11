#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int BS2(int a, int b)
{

    int low = 1, high = b - a + 1;
    for (int i = a; i <= b; i++)
    {
        if ((i | b) == b)
        {
            if (i == b)
                return i - a;
            else
                return i - a + 1;
        }
    }
    return 0;
}

int BS1(int a, int b)
{
    for (int i = b; i <= 2 * b; i++)
    {
        if ((i | a) == i)
        {
            if (i == a)
                return i - b;
            else
                return i - b + 1;
        }
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
            cout << 0 << "\n";
        else if ((a | b) == b)
            cout << 1 << "\n";
        else
        {
            int min1 = BS2(a, b);
            int min2 = BS1(a, b);
            cout << min(min1, min2) << "\n";
        }
    }
    return 0;
}