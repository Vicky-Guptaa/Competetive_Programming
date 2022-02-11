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
        map<int, int> map1;
        unordered_map<int, int> map2;
        map<int,queue<int>>map3;
        int tck = 0;
        vector<pair<int, int>> calc;
        vector<int>tcnt;
        for (int j = 0; j < n; j++)
        {
            map2[arr[j]]++;
            while (map2.find(tck) != map2.end())
                tck++;
            map1[tck]++;
            map3[arr[j]].push(j);
            calc.push_back({arr[j], tck});
            tcnt.push_back(tck);
        }

        for (int i = 1; i < calc.size(); i++)
        {
            int f = calc[i - 1].first;
            vector<int>:: iterator itr=upper_bound(tcnt.begin(),tcnt.end(),f);
            if(map3[f].size()>1)
            {
                map3[f].pop();
                int idx=map3[f].front();

            }
            else
            {
                map3.erase(f);
                map1[f]+=itr-tcnt.begin();
            }
            if (map2[f] > 1)
            {
                map2[f]--;
                for (int j = i; j < calc.size(); j++)
                {
                    if (calc[j].first == f)
                    {
                        for(int l=j;l<calc.size();l++)
                        {
                            map1[calc[l].second]++;
                        }
                        break;
                    }
                    else
                    {
                        if (calc[j].second > f)
                            calc[j].second = f;
                        map1[calc[j].second]++;
                    }
                }
            }
            else
            {
                for (int j = i; j < calc.size(); j++)
                {
                    if (calc[j].second > f)
                        calc[j].second = f;
                    map1[calc[j].second]++;
                }
                map2.erase(f);
            }
        }
        for (auto x : map1)
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
