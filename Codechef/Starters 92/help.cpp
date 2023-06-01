#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    if (grid[0][0] == 1)
        return -1;
    int n = grid.size(), m = grid[0].size();
    vector<int> moveX = {0,
                         0,
                         1,
                         -1,
                         -1,
                         -1,
                         1,
                         1};
    vector<int> moveY = {1,
                         -1,
                         0,
                         0,
                         1,
                         -1,
                         1,
                         -1};
    int len = 1;
    queue<pair<int, int>> que;
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    visited[0][0] = true;
    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            if (x == n - 1 && y == m - 1)
            {
                return len;
            }
            for (int i = 0; i < 8; i++)
            {
                int _x = x + moveX[i], _y = y + moveY[i];
                if (_x >= n || _y >= m || _x < 0 || _y < 0 || visited[_x][_y] || grid[_x][_y])
                    continue;
                que.push({_x,
                          _y});
                visited[_x][_y] = true;
            }
        }
        len++;
    }
    return -1;
}
int main()
{
    vector<vector<int>> grid = {{0, 1}, {1, 0}};
    cout << shortestPathBinaryMatrix(grid) << "\n";
    return 0;
}