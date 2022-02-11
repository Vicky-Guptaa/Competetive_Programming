#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    for (int i = 1; i <= n; i++)
        arr.push_back(i);
    set<pair<int, int>> pp;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        pp.insert({a, b});
    }
    int total = pow(2, n);
    int counter = 0;
    for (int i = 0; i < total; i++)
    {
        int temp = i;
        vector<int> uset;
        for (int j = 0; j < n; j++)
        {
            if (temp % 2 == 1)
            {
                uset.push_back(arr[j]);
            }
            temp /= 2;
        }
        bool check = true;
        for (int p = 0; p < uset.size(); p++)
        {
            for (int q = 0; q < uset.size(); q++)
            {
                if (p == q)
                    continue;
                if (pp.find({uset[p], uset[q]}) != pp.end())
                {
                    check = false;
                }
            }
        }
        if (check)
            counter++;
    }
    cout << counter << "\n";
    return 0;
}