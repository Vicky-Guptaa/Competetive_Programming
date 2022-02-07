#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n == 1)
        {
            cout << "R\n";
        }
        else if ((n + 1) / 2 >= k)
        {
            int place = 0, yes = 1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (j == place && yes)
                    {
                        cout << "R";
                    }
                    else
                        cout << ".";
                }
                cout << "\n";
                if (yes)
                    place += 2;
                if (place / 2 >= k)
                    yes = 0;
                else
                    yes = !yes;
            }
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}