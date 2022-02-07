#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long int k;
        cin >> n;
        cin >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        map<int, int> ans, subans, prevans; //use to store ans and the prev ans
        map<int, queue<int>> submap;        // used to store the element in order with index
        vector<pair<int, int>> pcalc;       // store the precalculation
        vector<int>p;
        int tck = 0;
        for (int i = 0; i < n; i++)
        {
            subans[arr[i]]++;
            while (subans.find(tck) != subans.end())
            {
                tck++;
            }
            ans[tck]++;
            prevans[tck]++;
            pcalc.push_back({tck, arr[i]});
            p.push_back(tck);
            submap[arr[i]].push(i);
        }
        for (int j = 1; j < n; j++)
        {
            int pno = pcalc[j - 1].second;
            p[j-1]--;
            if (submap[pno].size() == 1)
            {
                submap.erase(pno);
                prevans[prevans.begin()->first]--;
                int cnt = 0;
                for (auto x : prevans)
                {
                    if (x.first > pno)
                    {
                        cnt += x.second;
                        prevans[x.first] = 0;
                    }
                }
                prevans[pno] = cnt;
            }
            else
            {
                prevans[prevans.begin()->first]--;
                submap[pno].pop();
                int newindx = submap[pno].front();
                int indx = j;
                int tck = prevans.begin()->first;
                while (indx < newindx && pcalc[indx].first != pcalc[newindx].first)
                {
                    auto it = upper_bound(p.begin(), p.end(), tck);
                    if (pcalc[indx].first > pno)
                    {
                        prevans[pcalc[indx].first] -= indx - (it - p.begin());
                        prevans[pno] += indx - (it - p.begin());
                    }
                    indx = it - p.begin();
                }
                if (pno < pcalc[indx].first)
                {
                    prevans[pcalc[indx].first] -= newindx - indx;
                    prevans[pno] += newindx - indx;
                }
            }
            for (auto x : prevans)
            {
                ans[x.first] += x.second;
            }
        }
        for (auto x : ans)
        {
            k -= x.second;
            if (k <= 0)
            {
                cout << x.first << endl;
                break;
            }
        }
    }
    return 0;
}
