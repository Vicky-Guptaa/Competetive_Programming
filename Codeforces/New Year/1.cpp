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
        int n;
        cin >> n;
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            if (num < 0)
                num = -num;
            umap[num]++;
        }
        int answer = 0;
        for (auto x : umap)
        {
            if (x.first == 0 || x.second < 2)
                answer += 1;
            else
                answer += 2;
        }
        cout << answer << "\n";
    }
    return 0;
}