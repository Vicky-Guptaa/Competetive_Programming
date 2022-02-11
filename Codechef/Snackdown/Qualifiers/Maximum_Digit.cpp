#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> ans(n);
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            ans[i] = {num, i};
        }
        sort(ans.begin(), ans.end());
        int rsum = 0, counter = 0;
        for (int i = 0; i < n; i++)
        {
            int num = rsum + ans[i].first;
            if ((num % ans[i].first) == counter)
            {
                counter++;
                rsum++;
            }
            ans[i].first = num;
        }
        sort(ans.begin(), ans.end(), [&](pair<int, int> a, pair<int, int> b)
             { return a.second < b.second; });
        for (int i = 0; i < n; i++)
            cout << ans[i].first << " ";
        cout<<endl;
    }
    return 0;
}