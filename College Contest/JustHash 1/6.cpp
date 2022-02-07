#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(vector<int> list[], int src, vector<int> &walk, vector<bool> &visit)
{
    visit[src] = true;
    walk.push_back(src);
    for (auto curr : list[src])
    {
        if (visit[curr] == false)
        {
            DFS(list, curr, walk, visit);
            walk.push_back(src);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> list[n + 1];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(list[i].begin(), list[i].end(), greater<int>());
    }
    vector<int> walk;
    vector<bool> isVisited(n + 1, false);
    DFS(list, 1, walk, isVisited);
    int t;
    cin >> t;
    while (t--)
    {
        int s, e, b, cnt = 0;
        cin >> s >> e >> b;
        for (int i = s - 1; i < e; i++)
        {
            if (b == walk[i])
                cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}