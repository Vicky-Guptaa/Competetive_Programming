#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(int src, vector<int> list[], int subord[])
{
    bool isLeaf = true;
    for (auto curr : list[src])
    {
        subord[src] += dfs(curr, list, subord);
        isLeaf = false;
    }
    subord[src] += 1;
    return subord[src];
}

int main()
{
    int n;
    cin >> n;
    vector<int> list[n + 1];
    for (int i = 1; i < n; i++)
    {
        int node;
        cin >> node;
        list[node].push_back(i + 1);
    }
    int subord[n + 1] = {0};
    dfs(1, list, subord);
    for (int i = 1; i <= n; i++)
        cout << subord[i] - 1 << " ";
    cout << "\n";
    return 0;
}