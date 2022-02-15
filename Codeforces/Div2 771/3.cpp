#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

typedef long long ll;

class DisjSet
{
    int *parent;
    int *rank;
    int size;

public:
    DisjSet(int capacity)
    {
        size = capacity;
        parent = new int[size];
        rank = new int[size];
        initializer();
    }
    void initializer()
    {
        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int Find(int x)
    {
        if (parent[x] == x)
            return x;
        parent[x] = Find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y)
    {
        int x_rep = Find(x);
        int y_rep = Find(y);

        if (x_rep == y_rep)
            return;
        if (rank[x_rep] > rank[y_rep])
            parent[y_rep] = x_rep;
        else if (rank[y_rep] > rank[x_rep])
            parent[x_rep] = y_rep;
        else
        {
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
    }
};

void dfs(int src, vector<int> list[], vector<int> &isVisited)
{
    isVisited[src] = true;
    for (auto &curr : list[src])
    {
        if (isVisited[curr] == false)
        {
            dfs(curr, list, isVisited);
        }
    }
}

int solve(vector<int> list[], int n)
{
    vector<int> isVisited(n + 1, 0);
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isVisited[i] == false)
        {
            dfs(i, list, isVisited);
            count++;
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> list[n + 1];
        DisjSet graph = DisjSet(n + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                {
                    graph.Union(arr[i], arr[j]);
                    // list[arr[i]].push_back(arr[j]);
                    // list[arr[j]].push_back(arr[i]);
                }
            }
        }
        // int counter = 0;
        unordered_set<int> uset;
        for (int i = 0; i < n; i++)
        {
            uset.insert(graph.Find(arr[i]));
        }
        cout << uset.size() << "\n";
        // cout << solve(list, n) << "\n";
    }
    return 0;
}