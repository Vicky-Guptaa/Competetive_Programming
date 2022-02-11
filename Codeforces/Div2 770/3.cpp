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
        int n, m;
        cin >> n >> m;
        ll arr[n][m];
        ll counter = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[j][i] = counter++;
            }
        }
        bool isTrue = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ll sum = 0;
                for (int k = j; k < m; k++)
                {
                    sum += arr[i][k];
                    if (sum % (k - j + 1) != 0)
                    {
                        isTrue = false;
                    }
                }
                if (!isTrue)
                {
                    break;
                }
            }
            if (!isTrue)
            {
                break;
            }
        }
        if (isTrue)
        {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << "\n";
            }
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}