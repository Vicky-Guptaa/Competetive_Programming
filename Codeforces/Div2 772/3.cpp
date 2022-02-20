#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (arr[n - 1] < arr[n - 2])
        {
            cout << -1 << "\n";
            continue;
        }
        int count = 0;
        vector<string> ans;
        bool isSort = true;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                arr[i] = arr[i + 1] - arr[n - 1];
                if (arr[i] > arr[i + 1])
                {
                    isSort = false;
                    break;
                }
                string res = to_string(i + 1);
                res += " ";
                res += to_string(i + 2);
                res += " ";
                res += to_string(n);
                ans.push_back(res);
                count++;
            }
        }
        if (!isSort)
        {
            cout << -1 << "\n";
            continue;
        }
        cout << count << "\n";
        for (auto x : ans)
        {
            cout << x << "\n";
        }
    }
    return 0;
}