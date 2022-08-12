#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int helper(int src, vector<int> list[], int &cameraReq, vector<int> &visited)
{
    visited[src] = true;
    int isReq = -2;
    for (auto curr : list[src])
    {
        if (!visited[curr])
        {
            int val = helper(curr, list, cameraReq, visited);
            if (val == 1)
            {
                isReq = 1;
            }
            else if (isReq != 1)
            {
                isReq = val;
            }
        }
    }
    if (isReq == 1)
    {
        cameraReq++;
        return 0;
    }
    else
    {
        return 1;
    }
}

int minCamera(int N, vector<vector<int>> road)
{
    vector<int> list[N + 1];
    for (auto x : road)
    {
        list[x[0]].push_back(x[1]);
        list[x[1]].push_back(x[0]);
    }
    vector<int> visited(N + 1, false);
    int cameraReq = 0;
    helper(1, list, cameraReq, visited);
    return cameraReq;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> edges;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    cout << minCamera(n, edges) << "\n";
    return 0;
}