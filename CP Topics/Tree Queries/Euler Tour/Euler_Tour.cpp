#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

void eulerTourDfs(int src, int par, vector<int> list[], int &timer, vector<int> &strt, vector<int> &end, vector<int> &tour)
{
    tour[timer] = src;
    strt[src] = timer;
    timer++;
    for (auto child : list[src])
    {
        if (par != child)
            eulerTourDfs(child, src, list, timer, strt, end, tour);
    }
    tour[timer] = src;
    end[src] = timer;
    timer++;
}

void eulerTour(int n, vector<int> list[])
{
    vector<int> strt(n, 0);
    vector<int> end(n, 0);
    vector<int> tour(2 * n, 0);
    // fixed the tree at some node
    int timer = 0;
    eulerTourDfs(0, -1, list, timer, strt, end, tour);

    for (auto x : strt)
        cout << x << " ";
    cout << "\n";

    for (auto x : end)
        cout << x << " ";
    cout << "\n";

    for (auto x : tour)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    int n = 6;
    vector<int> adjList[n];
    adjList[0].push_back(1);
    adjList[1].push_back(0);

    adjList[2].push_back(1);
    adjList[1].push_back(2);

    adjList[2].push_back(4);
    adjList[4].push_back(2);

    adjList[2].push_back(5);
    adjList[5].push_back(2);

    adjList[3].push_back(1);
    adjList[1].push_back(3);

    eulerTour(n, adjList);
    return 0;
}