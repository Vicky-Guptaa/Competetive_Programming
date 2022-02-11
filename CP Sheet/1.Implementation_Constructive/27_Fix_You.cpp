#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

typedef pair<int, int> pp;

int solve_bfs(int n, int m, vector<vector<char>> &mat)
{
    vector<vector<int>> Cost(n, vector<int>(m, 1e9));
    queue<pp> queue;
    queue.push({0, 0});
    Cost[0][0] = 0;
    while (!queue.empty())
    {
        int curr_x = queue.front().first;
        int curr_y = queue.front().second;
        queue.pop();

        if (curr_y < m - 1)
        {
            if (mat[curr_x][curr_y] == 'R' && Cost[curr_x][curr_y] < Cost[curr_x][curr_y + 1])
            {
                queue.push({curr_x, curr_y + 1});
                Cost[curr_x][curr_y + 1] = Cost[curr_x][curr_y];
            }
            else if (Cost[curr_x][curr_y] + 1 < Cost[curr_x][curr_y + 1])
            {
                queue.push({curr_x, curr_y + 1});
                Cost[curr_x][curr_y + 1] = Cost[curr_x][curr_y] + 1;
            }
        }
        if (curr_x < n - 1)
        {
            if (mat[curr_x][curr_y] == 'D' && Cost[curr_x][curr_y] < Cost[curr_x + 1][curr_y])
            {
                queue.push({curr_x + 1, curr_y});
                Cost[curr_x + 1][curr_y] = Cost[curr_x][curr_y];
            }
            else if (Cost[curr_x][curr_y] + 1 < Cost[curr_x + 1][curr_y])
            {
                queue.push({curr_x + 1, curr_y});
                Cost[curr_x + 1][curr_y] = Cost[curr_x][curr_y] + 1;
            }
        }
    }
    return Cost[n - 1][m - 1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> ss;
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            ss.push_back(s);
            if (s[m - 1] == 'R')
                counter++;
        }
        string s = ss[n - 1];
        for (int i = 0; i < m; i++)
        {
            if (s[i] == 'D')
                counter++;
        }
        cout << counter << "\n";
    }
    return 0;
}