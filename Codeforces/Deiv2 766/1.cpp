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
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        int count = 0;
        vector<string> str;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            str.push_back(s);
        }
        vector<vector<char>> arr(n, vector<char>(m, '\0'));
        for (int i = 0; i < n; i++)
        {
            string s = str[i];
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = s[j];
                if (s[j] == 'W')
                    count++;
            }
        }
        if (count == n * m)
        {
            cout << -1 << "\n";
            continue;
        }
        else if (count == 0 || arr[r - 1][c - 1] == 'B')
        {
            cout << 0 << "\n";
            continue;
        }
        bool find = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i][c - 1] == 'B')
            {
                find = true;
                break;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (arr[r - 1][i] == 'B')
            {
                find = true;
                break;
            }
        }
        if (find == true)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 2 << "\n";
        }
    }
    return 0;
}