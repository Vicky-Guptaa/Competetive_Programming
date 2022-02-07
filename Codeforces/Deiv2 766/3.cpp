#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void dfs(int src, int parent, vector<pair<int, int>> list[], vector<bool> &isVisited)
{
    isVisited[src] = true;
    for (auto &x : list[src])
    {
        if (isVisited[x.first] == false)
        {
            if (parent != -1)
            {
                for (int i = 0; i < list[parent].size(); i++)
                {
                    if (list[parent][i].first == src)
                    {
                        if (list[parent][i].second == 2)
                        {
                            x.second = 5;
                        }
                        else
                        {
                            x.second = 2;
                        }
                        break;
                    }
                }
            }
            dfs(x.first, src, list, isVisited);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> links;
        vector<pair<int, int>> list[n + 1];
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            if (u > v)
                swap(u, v);
            list[u].push_back({v, -1});
            list[v].push_back({u, -1});
            links.push_back({u, v});
        }
        int odd_count = 0, odd_src = 0;
        bool isPosible = false;
        for (int i = 0; i <= n; i++)
        {
            if (list[i].size() > 2)
            {
                isPosible = true;
                break;
            }
            else if (list[i].size() & 1)
            {
                odd_count++;
                odd_src = i;
            }
        }
        if (isPosible || odd_count > 2)
        {
            cout << "-1\n";
            continue;
        }
        list[odd_src][0].second = 2;
        vector<bool> isVisited(n + 1, 0);
        dfs(odd_src, -1, list, isVisited);
        for (int i = 0; i < n - 1; i++)
        {
            bool gotIt = false;
            for (auto x : list[links[i].first])
            {
                if (x.first == links[i].second && x.second != -1)
                {
                    cout << x.second << " ";
                    gotIt = true;
                }
            }
            if (gotIt == false)
                for (auto x : list[links[i].second])
                {
                    if (x.first == links[i].first && x.second != -1)
                    {
                        cout << x.second << " ";
                    }
                }
        }
        cout << "\n";
    }
    return 0;
}