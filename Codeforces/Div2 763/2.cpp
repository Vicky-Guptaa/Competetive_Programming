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
                range[b + 1] -= 1;
        }
        for (int i = 1; i <= n; i++)
        {
            range[i] += range[i - 1];
        }
        for (int i = 0; i < n; i++)
        {
            int Min = 1e9, index = i;
            for (int j = pairs[i].first; j <= pairs[i].second; j++)
            {
                if (Min > range[j])
                {
                    index = j;
                    Min = range[j];
                }
            }
            cout << pairs[i].first << " " << pairs[i].second << " " << index << "\n";
        }
        cout << "\n";
    }
    return 0;
}