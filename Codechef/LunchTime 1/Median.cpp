#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

void Check(int i, map<int, int> &pre, bool &possible, vector<int> arr)
{
    if (pre.find(arr[i]) == pre.end())
    {
        possible = false;
    }
    else
    {
        pre[arr[i]]--;
        if (pre[arr[i]] == 0)
            pre.erase(arr[i]);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[2 * n];
        set<int> st;
        map<int, int> pre, suf;
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> arr[i];
            st.insert(arr[i]);
            if (i < n)
                pre[arr[i]]++;
            else
                suf[arr[i]]++;
        }
        vector<int> newarr, sorted;
        bool psble = true;
        for (auto x : st)
            sorted.push_back(x);
        int itr = 0;
        for (int i = 0; i < n; i++)
        {
            newarr.push_back(sorted[itr++]);
            int mid = (newarr.size() - 1) / 2;
            Check(mid, pre, psble, newarr);
            if (psble == false)
                break;
        }
        newarr.clear();
        itr = n - 1;
        for (int i = n; i < 2 * n; i++)
        {
            newarr.push_back(sorted[itr--]);
            int mid = (newarr.size()) / 2;
            Check(mid, suf, psble, newarr);
            if (psble == false)
                break;
        }
        if (psble == true)
        {
            for (auto x : sorted)
                cout << x << " ";
        }
        else
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}