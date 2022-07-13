#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    vector<vector<int>> adjMat;
    int r = adjMat.size(), c = adjMat[0].size();
    vector<int> list[r + 1];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (adjMat[i][j])
                list[i].push_back(j);
        }
    }
}