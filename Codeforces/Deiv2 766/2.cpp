#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> res;
        vector<int> c_x = {0, 0, n - 1, n - 1}, c_y = {0, m - 1, 0, m - 1};

        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                int max_dis = 0;
                for (int i = 0; i < 4; i++)
                {
                    int xdis = abs(c_x[i] - x);
                    int ydis = abs(c_y[i] - y);
                    max_dis = max(max_dis, xdis + ydis);
                }
                res.push_back(max_dis);
            }
        }
        sort(res.begin(), res.end());
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}