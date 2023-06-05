#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void Div_Sub(vector<int> &arr, int n)
{
    int sum = 0;
    unordered_map<int, vector<int>> umap;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        int presum = sum;
        presum %= n;
        if (umap.find(presum) == umap.end())
        {
            umap[presum].push_back(i);
        }
        else
        {

            int previndx = umap[presum][0];
            unordered_set<int> uset;
            vector<int> ans;
            bool isDup = false;
            for (int k = previndx + 1; k <= i; k++)
            {
                if (uset.find(arr[k - 1]) == uset.end())
                {
                    ans.push_back(k + 1);
                    uset.insert(arr[k - 1]);
                }
                else
                {
                    isDup = true;
                    break;
                }
            }
            if (isDup)
            {
                continue;
            }
            else
            {
                cout << "1\n";
                for (auto x : ans)
                    cout << x << " ";
                cout << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &x : arr)
        {
            cin >> x;
        }
        Div_Sub(arr, n);
    }
    return 0;
}