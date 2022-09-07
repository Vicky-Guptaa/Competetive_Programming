#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    vector<int> bfsGraph(int s)
    {
        vector<int> bfs;
        int visited[V] = {0};
        queue<int> q;
        visited[0] = 1;
        q.push(0);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    vector<int> bfs = g.bfsGraph(2);
    for (auto x : bfs)
    {
        cout << x << " ";
    }

    return 0;
}