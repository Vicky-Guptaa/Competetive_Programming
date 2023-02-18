#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

int minimumScore(string s, string t)
{
    map<char, vector<int>> charIndx;
    for (int i = 0; i < s.size(); i++)
    {
        charIndx[s[i]].push_back(i);
    }
    vector<int> leftRem;
    int prev = -1;
    for (int i = 0; i < t.size(); i++)
    {
        auto indx = lower_bound(charIndx[t[i]].begin(), charIndx[t[i]].end(), prev);
        if (indx == charIndx[t[i]].end())
        {
            leftRem.push_back(i);
        }
        else
        {
            prev = *indx;
        }
    }
    for (auto x : leftRem)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}

int main()
{
    cout << minimumScore("abacaba", "bzaa") << "\n";
    return 0;
}