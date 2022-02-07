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
        vector<pair<int, int>> ram(n, {0, 0});
        for (int i = 0; i < n; i++)
        {
            cin >> ram[i].first;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> ram[i].second;
        }
        sort(ram.begin(), ram.end());
        for (int i = 0; i < n; i++)
        {
            if (ram[i].first <= k)
            {
                k += ram[i].second;
            }
            else
            {
                break;
            }
        }
        cout << k << "\n";
    }
    return 0;
}