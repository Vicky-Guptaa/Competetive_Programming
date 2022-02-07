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
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)
        {
            umap[str[i]]++;
        }
        int ppairs = 0, single = 0;
        for (auto x : umap)
        {
            ppairs += x.second / 2;
            single += x.second - (x.second / 2) * 2;
        }
        int give = ppairs / k;
        int remain = ppairs % k;
        single += remain * 2;
        {
            if (single < k)
            {
                cout << 2 * give << "\n";
            }
            else
            {
                cout << 2 * give + 1 << "\n";
            }
        }
    }
    return 0;
}