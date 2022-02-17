#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long ll;

int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    unordered_map<char, int> umap;
    for (auto &x : s)
    {
        umap[x]++;
    }
    string result;
    for (auto &x : umap)
    {
        if (x.second % k != 0)
        {
            cout << -1 << "\n";
            return 0;
        }
        for (int i = 0; i < x.second / k; i++)
        {
            result += x.first;
        }
    }
    for (auto i = 0; i < k; i++)
    {
        cout << result;
    }
    cout << "\n";
    return 0;
}