#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = n - i; j > 0; j--)
        {
            cout << "  ";
        }
        for (int k = 0; k <= i; k++)
        {
            if (i != 0)
                cout << k << " ";
            else
                cout << k;
        }
        for (int k = i - 1; k >= 0; k--)
        {
            if (k != 0)
                cout << k << " ";
            else
                cout << k;
        }
        cout << "\n";
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            cout << "  ";
        }
        for (int k = 0; k < n - i; k++)
        {
            if (i != n - 1)
                cout << k << " ";
            else
                cout << k;
        }
        for (int k = n - i - 2; k >= 0; k--)
        {
            if (k != 0)
                cout << k << " ";
            else
                cout << k;
        }
        cout << "\n";
    }
    return 0;
}