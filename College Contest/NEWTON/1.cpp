#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

void DFS_Max(int src, int par, int k, long long answer, long long &Max, vector<int> list[], vector<bool> isVisist)
{
    Max = max(answer, Max);
    if (k == 0)
        return;
    isVisist[src] = 1;
    for (auto x : list[src])
    {
        if (isVisist[x] == false)
        {
            DFS_Max(x, src, k - 1, answer + pow(2, x - 1) - 1, Max, list, isVisist);
        }
        else if (parent != x)
        {
            DFS_Max(x, src, k - 1, answer + pow(2, x - 1) - 1, Max, list, isVisist);
        }
    }
    isVisist[src] = 0;
}
int main()
{
    int v, e, k;
    cin >> v >> e >> k;
    vector<int> list[v + 1];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        list[x].push_back(y);
    }
    vector<bool> isVisited(v + 1, false);
    long long Max = 0;
    DFS_Max(1, -1, k, 0, Max, list, isVisited);
    cout << Max << "\n";
    return 0;
}