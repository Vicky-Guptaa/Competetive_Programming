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
        int n;
        cin >> n;
        vector<pair<int, int>> pairs;
        vector<int> range(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            pairs.push_back({a, b});
            range[a] += 1;
            if (b + 1 <= n)
                range[b + a] -= 1;
        }
        for (int i = 1; i < n + 1; i++)
        {
            range[i] += range[i - 1];
            cout << range[i] << " ";
        }
    }
    return 0;
}