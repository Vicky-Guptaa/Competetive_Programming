#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    vector<string> result;
    int len = s.length();

    if (len <= 10)
        return result;

    unordered_map<string, pair<int, int>> umap;

    int left = 0, right = 0;
    string pat;
    while (right < len)
    {
        while (10 > right - left)
        {
            pat += s[right];
            right++;
        }
        if (umap.find(pat) != umap.end())
        {
            int pright = umap[pat].second;
            if (pright <= left)
            {
                result.push_back(pat);
            }
        }
        else
        {
            umap[pat] = {left, right};
        }
        pat = pat.substr(1);
        left++;
    }
    return result;
}
int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res = findRepeatedDnaSequences(s);
    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}