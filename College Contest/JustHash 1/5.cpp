#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int BFS_Reach(vector<pair<int, int>> list[], int n, int src, int dst)
{
    queue<pair<int, int>> que;
    que.push({0, src});
    vector<int> distance(n, 1e9);
    distance[src] = 0;
    int counter = 0;
    int shortest_distance = 1e9;
    while (!que.empty())
    {
        int curr = que.front().second;
        int wsf = que.front().first;
        que.pop();
        for (auto x : list[curr])
        {
            if (distance[x.first] >= wsf + x.second)
            {
                distance[x.first] = wsf + x.second;
                que.push({distance[x.first], x.first});
                if (x.first == dst)
                {
                    if (shortest_distance > distance[x.first])
                    {
                        counter = 1;
                        shortest_distance = distance[x.first];
                    }

                    else
                        counter++;
                }
            }
        }
    }
    return counter;
}

int main()
{
    int v, e, x;
    cin >> v >> e >> x;
    vector<pair<int, int>> list[v];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        list[u].push_back({v, 1});
        list[v].push_back({u, 1});
    }
    cout << BFS_Reach(list, v, 0, x) << " ";
    cout << BFS_Reach(list, v, v - 1, x) << "\n";
    return 0;
}
/*
5 8 2
0 1
0 4
0 3
1 4
4 3
1 2
4 2
3 4

5 5 1
0 2
0 3
3 4
2 4
4 1

*/