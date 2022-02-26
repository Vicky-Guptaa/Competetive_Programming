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
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> ans(n, vector<int>(m, 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                for (int p = 0; p < m; p++)
                {
                    ans[i][p] = 0;
                }
                for (int p = 0; p < n; p++)
                {
                    ans[p][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                int sum = 0;
                for (int p = 0; p < m; p++)
                {
                    if (ans[i][p] == 1)
                        sum++;
                }
                for (int p = 0; p < n; p++)
                {
                    if (ans[p][j] == 1)
                        sum++;
                }
                if (sum == 0)
                {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        for (auto y : ans[i])
            cout << y << " ";
        cout << "\n";
    }
    return 0;
}