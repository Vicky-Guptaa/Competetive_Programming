#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        string hash;
        cin >> str >> hash;
        unordered_map<char, int> umap;
        for (auto x : str)
        {
            umap[x]++;
        }
        int len = hash.size();
        bool isTrue = 0;
        for (int i = 0; i < len; i++)
        {
            unordered_map<char, int> tmap = umap;
            for (int j = i; j < len; j++)
            {
                if (tmap.find(hash[j]) != tmap.end())
                {
                    tmap[hash[j]]--;
                    if (tmap[hash[j]] == 0)
                    {
                        tmap.erase(hash[j]);
                    }
                }
                else
                {
                    break;
                }
            }
            if (tmap.empty())
            {
                isTrue = 1;
                break;
            }
        }
        if (isTrue)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}