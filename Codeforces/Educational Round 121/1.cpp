#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        unordered_map<char, int> umap;
        for (auto &x : str)
        {
            umap[x]++;
        }
        for (auto &x : umap)
        {
            for (int i = 0; i < x.second; i++)
            {
                cout << x.first;
            }
        }
        cout << "\n";
    }
    return 0;
}