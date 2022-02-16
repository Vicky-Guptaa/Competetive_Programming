#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
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
        int arr[n];
        for (int i = 0; i < n; i++)
            arr[i] = i + 1;
        vector<pair<int, int>> rpair;
        int res = 0;
        priority_queue<int> pque(arr, arr + n);
        while (pque.size() != 1)
        {
            int first = pque.top();
            pque.pop();
            int second = pque.top();
            pque.pop();

            if (pque.size() > 0)
            {
                int theird = pque.top();
                pque.pop();
                int mid = 0;
                if (theird & 1 == first & 1)
                {
                    mid = (first + theird + 1) / 2;
                    rpair.push_back({first, theird});
                    rpair.push_back({mid, second});
                    mid = (mid + second + 1) / 2;
                }
                else
                {
                    mid = (first + second + 1) / 2;
                    rpair.push_back({first, second});
                    rpair.push_back({mid, theird});
                    mid = (mid + theird + 1) / 2;
                }
                pque.push(mid);
            }
            else
            {
                int mid = (first + second + 1) / 2;
                pque.push(mid);
                rpair.push_back({first, second});
            }
        }
        res = pque.top();
        cout << res << "\n";
        for (auto &x : rpair)
        {
            cout << x.first << " " << x.second << "\n";
        }
    }
    return 0;
}